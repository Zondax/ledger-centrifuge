/** ******************************************************************************
 *  (c) 2020 Zondax GmbH
 *
 *  Licensed under the Apache License, Version 2.0 (the "License");
 *  you may not use this file except in compliance with the License.
 *  You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 *  Unless required by applicable law or agreed to in writing, software
 *  distributed under the License is distributed on an "AS IS" BASIS,
 *  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *  See the License for the specific language governing permissions and
 *  limitations under the License.
 ******************************************************************************* */

import jest, {expect} from "jest";
import Zemu from "@zondax/zemu";
import {blake2bFinal, blake2bInit, blake2bUpdate} from "blakejs";

const {newCentrifugeApp} = require("@zondax/ledger-polkadot");
const ed25519 = require("ed25519-supercop");
const Resolve = require("path").resolve;
const APP_PATH_S = Resolve("../app/output/app_s.elf");
const APP_PATH_X = Resolve("../app/output/app_x.elf");

const APP_SEED = "equip will roof matter pink blind book anxiety banner elbow sun young"

var simOptions = {
    logging: true,
    start_delay: 3000,
    custom: `-s "${APP_SEED}"`,
    X11: false
};

let models = [
    ['S', {model: 'nanos', prefix: 'S', path: APP_PATH_S}],
    ['X', {model: 'nanox', prefix: 'X', path: APP_PATH_X}]
]

jest.setTimeout(60000)

describe('Standard', function () {
    test.each(models)('can start and stop container (%s)', async function (_, {model, prefix, path}) {
        const sim = new Zemu(path);
        try {
            await sim.start({model, ...simOptions});
        } finally {
            await sim.close();
        }
    });

    test.each(models)('main menu (%s)', async function (_, {model, prefix, path}) {
        const sim = new Zemu(path);
        try {
            await sim.start({model, ...simOptions});
            await sim.compareSnapshotsAndAccept(".", `${prefix.toLowerCase()}-mainmenu`, 3);
        } finally {
            await sim.close();
        }
    });

    test.each(models)('get app version (%s)', async function (_, {model, prefix, path}) {
        const sim = new Zemu(path);
        try {
            await sim.start({model, ...simOptions});
            const app = newCentrifugeApp(sim.getTransport());
            const resp = await app.getVersion();

            console.log(resp);

            expect(resp.return_code).toEqual(0x9000);
            expect(resp.error_message).toEqual("No errors");
            expect(resp).toHaveProperty("test_mode");
            expect(resp).toHaveProperty("major");
            expect(resp).toHaveProperty("minor");
            expect(resp).toHaveProperty("patch");
        } finally {
            await sim.close();
        }
    });

    test.each(models)('get address (%s)', async function (_, {model, prefix, path}) {
        const sim = new Zemu(path);
        try {
            await sim.start({model, ...simOptions});
            const app = newCentrifugeApp(sim.getTransport());

            const resp = await app.getAddress(0x80000000, 0x80000000, 0x80000000);

            console.log(resp)

            expect(resp.return_code).toEqual(0x9000);
            expect(resp.error_message).toEqual("No errors");

            const expected_address = "4dTWk5RN3BB5M1yoY8SuZsvNPRamdHgshe4TVNBpmWaMjvgr";
            const expected_pk = "5da18749c8443cddf9dcd5b6ba4330c1ab8f218b44fcdb9ef91b884e35e0be1f";

            expect(resp.address).toEqual(expected_address);
            expect(resp.pubKey).toEqual(expected_pk);
        } finally {
            await sim.close();
        }
    });

    test.each(models)('show address (%s)', async function (_, {model, prefix, path}) {
        const sim = new Zemu(path);
        try {
            await sim.start({model, ...simOptions});
            const app = newCentrifugeApp(sim.getTransport());

            const respRequest = app.getAddress(0x80000000, 0x80000000, 0x80000000, true);
            // Wait until we are not in the main menu
            await sim.waitUntilScreenIsNot(sim.getMainMenuSnapshot());

            await sim.compareSnapshotsAndAccept(".", `${prefix.toLowerCase()}-show_address`, 2);

            const resp = await respRequest;
            console.log(resp);

            expect(resp.return_code).toEqual(0x9000);
            expect(resp.error_message).toEqual("No errors");

            const expected_address = "4dTWk5RN3BB5M1yoY8SuZsvNPRamdHgshe4TVNBpmWaMjvgr";
            const expected_pk = "5da18749c8443cddf9dcd5b6ba4330c1ab8f218b44fcdb9ef91b884e35e0be1f";

            expect(resp.address).toEqual(expected_address);
            expect(resp.pubKey).toEqual(expected_pk);
        } finally {
            await sim.close();
        }
    });

    test.each(models)('show address - reject (%s)', async function (_, {model, prefix, path}) {
        const sim = new Zemu(path);
        try {
            await sim.start({model, ...simOptions});
            const app = newCentrifugeApp(sim.getTransport());

            const respRequest = app.getAddress(0x80000000, 0x80000000, 0x80000000, true);
            // Wait until we are not in the main menu
            await sim.waitUntilScreenIsNot(sim.getMainMenuSnapshot());

            await sim.compareSnapshotsAndAccept(".", `${prefix.toLowerCase()}-show_address_reject`, 3, 2);

            const resp = await respRequest;
            console.log(resp);

            expect(resp.return_code).toEqual(0x6986);
            expect(resp.error_message).toEqual("Transaction rejected");
        } finally {
            await sim.close();
        }
    });

    test.each(models)('sign basic normal (%s)', async function (_, {model, prefix, path}) {
        const sim = new Zemu(path);
        try {
            await sim.start({model, ...simOptions});
            const app = newCentrifugeApp(sim.getTransport());
            const pathAccount = 0x80000000;
            const pathChange = 0x80000000;
            const pathIndex = 0x80000000;

            let txBlobStr = "0000419dfc0dd5038d2403d2029649f000000001000000d77ea01f23717cbdf86a4ba6df00f8cec726cee71f5365a9e195e9806aaa5716d77ea01f23717cbdf86a4ba6df00f8cec726cee71f5365a9e195e9806aaa5716";

            const txBlob = Buffer.from(txBlobStr, "hex");

            const responseAddr = await app.getAddress(pathAccount, pathChange, pathIndex);
            const pubKey = Buffer.from(responseAddr.pubKey, "hex");

            // do not wait here.. we need to navigate
            const signatureRequest = app.sign(pathAccount, pathChange, pathIndex, txBlob);
            // Wait until we are not in the main menu
            await sim.waitUntilScreenIsNot(sim.getMainMenuSnapshot());

            await sim.compareSnapshotsAndAccept(".", `${prefix.toLowerCase()}-sign_basic_normal`, model === "nanos" ? 3 : 4);

            let signatureResponse = await signatureRequest;
            console.log(signatureResponse);

            expect(signatureResponse.return_code).toEqual(0x9000);
            expect(signatureResponse.error_message).toEqual("No errors");

            // Now verify the signature
            let prehash = txBlob;
            if (txBlob.length > 256) {
                const context = blake2bInit(32, null);
                blake2bUpdate(context, txBlob);
                prehash = Buffer.from(blake2bFinal(context));
            }
            const valid = ed25519.verify(signatureResponse.signature.slice(1), prehash, pubKey);
            expect(valid).toEqual(true);
        } finally {
            await sim.close();
        }
    });

    test.each(models)('sign basic expert (%s)', async function (_, {model, prefix, path}) {
        const sim = new Zemu(path);
        try {
            await sim.start({model, ...simOptions});
            const app = newCentrifugeApp(sim.getTransport());
            const pathAccount = 0x80000000;
            const pathChange = 0x80000000;
            const pathIndex = 0x80000000;

            // Change to expert mode so we can skip fields
            await sim.clickRight();
            await sim.clickBoth();
            await sim.clickLeft();

            let txBlobStr = "0000419dfc0dd5038d2403d2029649f000000001000000d77ea01f23717cbdf86a4ba6df00f8cec726cee71f5365a9e195e9806aaa5716d77ea01f23717cbdf86a4ba6df00f8cec726cee71f5365a9e195e9806aaa5716";

            const txBlob = Buffer.from(txBlobStr, "hex");

            const responseAddr = await app.getAddress(pathAccount, pathChange, pathIndex);
            const pubKey = Buffer.from(responseAddr.pubKey, "hex");

            // do not wait here.. we need to navigate
            const signatureRequest = app.sign(pathAccount, pathChange, pathIndex, txBlob);

            // Wait until we are not in the main menu
            await sim.waitUntilScreenIsNot(sim.getMainMenuSnapshot());

            await sim.compareSnapshotsAndAccept(".", `${prefix.toLowerCase()}-sign_basic_expert`, model === "nanos" ? 9 : 10);

            let signatureResponse = await signatureRequest;
            console.log(signatureResponse);

            expect(signatureResponse.return_code).toEqual(0x9000);
            expect(signatureResponse.error_message).toEqual("No errors");

            // Now verify the signature
            let prehash = txBlob;
            if (txBlob.length > 256) {
                const context = blake2bInit(32, null);
                blake2bUpdate(context, txBlob);
                prehash = Buffer.from(blake2bFinal(context));
            }
            const valid = ed25519.verify(signatureResponse.signature.slice(1), prehash, pubKey);
            expect(valid).toEqual(true);
        } finally {
            await sim.close();
        }
    });

    test.each(models)('sign basic - forward/backward (%s)', async function (_, {model, prefix, path}) {
        const sim = new Zemu(path);
        try {
            await sim.start({model, ...simOptions});
            const app = newCentrifugeApp(sim.getTransport());
            const pathAccount = 0x80000000;
            const pathChange = 0x80000000;
            const pathIndex = 0x80000000;

            let txBlobStr = "0000419dfc0dd5038d2403d2029649f000000001000000d77ea01f23717cbdf86a4ba6df00f8cec726cee71f5365a9e195e9806aaa5716d77ea01f23717cbdf86a4ba6df00f8cec726cee71f5365a9e195e9806aaa5716";

            const txBlob = Buffer.from(txBlobStr, "hex");

            const responseAddr = await app.getAddress(pathAccount, pathChange, pathIndex);
            const pubKey = Buffer.from(responseAddr.pubKey, "hex");

            // do not wait here.. we need to navigate
            const signatureRequest = app.sign(pathAccount, pathChange, pathIndex, txBlob);
            // Wait until we are not in the main menu
            await sim.waitUntilScreenIsNot(sim.getMainMenuSnapshot());

            await sim.compareSnapshotsAndAccept(".", `${prefix.toLowerCase()}-sign_basic_FB`, model === "nanos" ? 3 : 4, 1);

            let signatureResponse = await signatureRequest;
            console.log(signatureResponse);

            expect(signatureResponse.return_code).toEqual(0x9000);
            expect(signatureResponse.error_message).toEqual("No errors");

            // Now verify the signature
            let prehash = txBlob;
            if (txBlob.length > 256) {
                const context = blake2bInit(32, null);
                blake2bUpdate(context, txBlob);
                prehash = Buffer.from(blake2bFinal(context));
            }
            const valid = ed25519.verify(signatureResponse.signature.slice(1), prehash, pubKey);
            expect(valid).toEqual(true);
        } finally {
            await sim.close();
        }
    });

    test.each(models)('sign basic - forward/backward-reject (%s)', async function (_, {model, prefix, path}) {
        const sim = new Zemu(path);
        try {
            await sim.start({model, ...simOptions});
            const app = newCentrifugeApp(sim.getTransport());
            const pathAccount = 0x80000000;
            const pathChange = 0x80000000;
            const pathIndex = 0x80000000;

            let txBlobStr = "0000419dfc0dd5038d2403d2029649f000000001000000d77ea01f23717cbdf86a4ba6df00f8cec726cee71f5365a9e195e9806aaa5716d77ea01f23717cbdf86a4ba6df00f8cec726cee71f5365a9e195e9806aaa5716";

            const txBlob = Buffer.from(txBlobStr, "hex");

            const responseAddr = await app.getAddress(pathAccount, pathChange, pathIndex);
            const pubKey = Buffer.from(responseAddr.pubKey, "hex");

            // do not wait here.. we need to navigate
            const signatureRequest = app.sign(pathAccount, pathChange, pathIndex, txBlob);
            // Wait until we are not in the main menu
            await sim.waitUntilScreenIsNot(sim.getMainMenuSnapshot());

            await sim.compareSnapshotsAndAccept(".", `${prefix.toLowerCase()}-sign_basic_FB_reject`, model === "nanos" ? 4 : 5, 1);

            let signatureResponse = await signatureRequest;
            console.log(signatureResponse);

            expect(signatureResponse.return_code).toEqual(0x6986);
            expect(signatureResponse.error_message).toEqual("Transaction rejected");
        } finally {
            await sim.close();
        }
    });

    test.each(models)('sign large nomination (%s)', async function (_, {model, prefix, path}) {
        const sim = new Zemu(path);
        try {
            await sim.start({model, ...simOptions});
            const app = newCentrifugeApp(sim.getTransport());
            const pathAccount = 0x80000000;
            const pathChange = 0x80000000;
            const pathIndex = 0x80000000;

            let txBlobStr = "060540ff44b5d2eea05aee033e61ae3dc4b5fa5bc84c6e81a2320037f52bd1695998fe39ff4e9681fe22184b1989420ee5ef8f9ea5bf488b33e7e33c5cfba5b0ba7774a766ff1671d88131ecd52bfa3bcde246a9063a2de895878ea4dfccb5f9c91d1c14f435ffac1156362d74c9964a877ba0d2eced7f81fc1d9e72b4a28de461df92b0fa3140ff7c71020c7a19319f748a272ea8f6e1b2fbd87ebde83225a754bf2edc021c140cffecd729f00f09ff4e301de0b5aeaf717d955630dd1a5ece233755e3b0be7ebe11ff3aefdb1db2603d7ba4f259b81cd832f6f900b290a514e6f09d7b9071811e9e69ffa47bafe7cd25b6fc30523cc08f0a396895b99677ae03b54905fb5979d3538b6cffaa6f1fae766e30138c75c7cd102d45729a48ec29f0f49235f90db05d8bb0c648ff2c7d26191b827d57523585614a95b1ecd30f307a03ab5694ad7c6cf1f3845c1bffcaa3181634d3952efb925c5aaf0a8699b972864b620757347d1414d50678ec2bff82ec006b0cb4442b4ed23b0e74191e1b72e84813c32b32f1f6eb68385c215e03ffda9098e62c9d1a0bccbd74754108a6de9dcc667b8a37d836db347ea851c9642effda87dde348c26d14afade327d442a1837f902a85dbbb5276d543233c8d77346fff5ad7cc8977c23e06b3b795c6f1d652113cadaf2929484df1ec68d5cec291ef68ff223adf1784a64a4a650446dbbe9fe6553302aa19c07a7d731da0e152b0e3a07ad50391018ed73e0df000000001000000d77ea01f23717cbdf86a4ba6df00f8cec726cee71f5365a9e195e9806aaa5716d77ea01f23717cbdf86a4ba6df00f8cec726cee71f5365a9e195e9806aaa5716";
            const txBlob = Buffer.from(txBlobStr, "hex");

            const responseAddr = await app.getAddress(pathAccount, pathChange, pathIndex);
            const pubKey = Buffer.from(responseAddr.pubKey, "hex");

            // do not wait here.. we need to navigate
            const signatureRequest = app.sign(pathAccount, pathChange, pathIndex, txBlob);
            // Wait until we are not in the main menu
            await sim.waitUntilScreenIsNot(sim.getMainMenuSnapshot());

            await sim.compareSnapshotsAndAccept(".", `${prefix.toLowerCase()}-sign_large_nomination`, model === "nanos" ? 34 : 19);

            let signatureResponse = await signatureRequest;
            console.log(signatureResponse);

            expect(signatureResponse.return_code).toEqual(0x9000);
            expect(signatureResponse.error_message).toEqual("No errors");

            // Now verify the signature
            let prehash = txBlob;
            if (txBlob.length > 256) {
                const context = blake2bInit(32, null);
                blake2bUpdate(context, txBlob);
                prehash = Buffer.from(blake2bFinal(context));
            }
            const valid = ed25519.verify(signatureResponse.signature.slice(1), prehash, pubKey);
            expect(valid).toEqual(true);
        } finally {
            await sim.close();
        }
    });

});
