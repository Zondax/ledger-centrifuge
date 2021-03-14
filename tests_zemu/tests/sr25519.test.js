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

const {newCentrifugeApp} = require("@zondax/ledger-polkadot");
import {blake2bFinal, blake2bInit, blake2bUpdate} from "blakejs";
var addon = require('../../tests_tools/neon/native');

const Resolve = require("path").resolve;

const APP_PATH = Resolve("../app/output/app_sr25519.elf");
const APP_SEED = "equip will roof matter pink blind book anxiety banner elbow sun young"

const simOptions = {
    logging: true,
    start_delay: 3000,
    custom: `-s "${APP_SEED}"`,
    X11: true
};

jest.setTimeout(60000)

describe('SR25519', function () {
    test('get address sr25519', async function () {
        const sim = new Zemu(APP_PATH);
        try {
            await sim.start(simOptions);
            const app = newCentrifugeApp(sim.getTransport());

            const resp = await app.getAddress(0x80000000, 0x80000000, 0x80000000, false, 1);

            console.log(resp)

            expect(resp.return_code).toEqual(0x9000);
            expect(resp.error_message).toEqual("No errors");

            const expected_address = "4gBxasX42h16QPSVXWrSNoecNNTWMFXkX6GCrYJNz4bG3uVN";
            const expected_pk = "d6794ab98c389e49de27f5b60a5cc43ac7fbc91e14a154c2b51ab9edd7f83c52";

            expect(resp.address).toEqual(expected_address);
            expect(resp.pubKey).toEqual(expected_pk);

        } finally {
            await sim.close();
        }
    });

    test('show address sr25519', async function () {
        const sim = new Zemu(APP_PATH);
        try {
            await sim.start(simOptions);
            const app = newCentrifugeApp(sim.getTransport());

            const respRequest = app.getAddress(0x80000000, 0x80000000, 0x80000000, true, 1);
            // Wait until we are not in the main menu
            await sim.waitUntilScreenIsNot(sim.getMainMenuSnapshot());

            await sim.compareSnapshotsAndAccept(".", "s-show_address_sr25519", 2);

            const resp = await respRequest;
            console.log(resp);

            expect(resp.return_code).toEqual(0x9000);
            expect(resp.error_message).toEqual("No errors");

            const expected_address = "4gBxasX42h16QPSVXWrSNoecNNTWMFXkX6GCrYJNz4bG3uVN";
            const expected_pk = "d6794ab98c389e49de27f5b60a5cc43ac7fbc91e14a154c2b51ab9edd7f83c52";

            expect(resp.address).toEqual(expected_address);
            expect(resp.pubKey).toEqual(expected_pk);
        } finally {
            await sim.close();
        }
    });

    test('show address - reject sr25519', async function () {
        const sim = new Zemu(APP_PATH);
        try {
            await sim.start(simOptions);
            const app = newCentrifugeApp(sim.getTransport());

            const respRequest = app.getAddress(0x80000000, 0x80000000, 0x80000000, true, 1);
            // Wait until we are not in the main menu
            await sim.waitUntilScreenIsNot(sim.getMainMenuSnapshot());
            await sim.compareSnapshotsAndAccept(".", "s-show_address_reject_sr25519", 3, 2);

            const resp = await respRequest;
            console.log(resp);

            expect(resp.return_code).toEqual(0x6986);
            expect(resp.error_message).toEqual("Transaction rejected");
        } finally {
            await sim.close();
        }
    });

    test('sign basic normal', async function () {
        const sim = new Zemu(APP_PATH);
        try {
            await sim.start(simOptions);
            const app = newCentrifugeApp(sim.getTransport());
            const pathAccount = 0x80000000;
            const pathChange = 0x80000000;
            const pathIndex = 0x80000000;

            let txBlobStr = "0500268ed73e0dd5030033158139ae28a3dfaac5fe1560a5e9e05cf000000001000000d77ea01f23717cbdf86a4ba6df00f8cec726cee71f5365a9e195e9806aaa5716d77ea01f23717cbdf86a4ba6df00f8cec726cee71f5365a9e195e9806aaa5716";

            const txBlob = Buffer.from(txBlobStr, "hex");

            const responseAddr = await app.getAddress(pathAccount, pathChange, pathIndex, false, 1);
            const pubKey = Buffer.from(responseAddr.pubKey, "hex");

            // do not wait here.. we need to navigate
            const signatureRequest = app.sign(pathAccount, pathChange, pathIndex, txBlob, 1);
            // Wait until we are not in the main menu
            await sim.waitUntilScreenIsNot(sim.getMainMenuSnapshot());

            await sim.compareSnapshotsAndAccept(".", "s-sign_basic_normal_sr25519", 5);

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
            let signingcontext = Buffer.from([]);
            const valid = addon.schnorrkel_verify(pubKey,signingcontext,prehash, signatureResponse.signature.slice(1));
            expect(valid).toEqual(true);
        } finally {
            await sim.close();
        }
    });

    test('sign basic expert', async function () {
        const sim = new Zemu(APP_PATH);
        try {
            await sim.start(simOptions);
            const app = newCentrifugeApp(sim.getTransport());
            const pathAccount = 0x80000000;
            const pathChange = 0x80000000;
            const pathIndex = 0x80000000;

            // Change to expert mode so we can skip fields
            await sim.clickRight();
            await sim.clickBoth();
            await sim.clickLeft();

            let txBlobStr = "0500268ed73e0dd5030033158139ae28a3dfaac5fe1560a5e9e05cf000000001000000d77ea01f23717cbdf86a4ba6df00f8cec726cee71f5365a9e195e9806aaa5716d77ea01f23717cbdf86a4ba6df00f8cec726cee71f5365a9e195e9806aaa5716";

            const txBlob = Buffer.from(txBlobStr, "hex");

            const responseAddr = await app.getAddress(pathAccount, pathChange, pathIndex, false , 1);
            const pubKey = Buffer.from(responseAddr.pubKey, "hex");

            // do not wait here.. we need to navigate
            const signatureRequest = app.sign(pathAccount, pathChange, pathIndex, txBlob, 1);

            // Wait until we are not in the main menu
            await sim.waitUntilScreenIsNot(sim.getMainMenuSnapshot());

            await sim.compareSnapshotsAndAccept(".", "s-sign_basic_expert_sr25519", 11);

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
            let signingcontext = Buffer.from([]);
            const valid = addon.schnorrkel_verify(pubKey,signingcontext,prehash, signatureResponse.signature.slice(1));
            expect(valid).toEqual(true);
        } finally {
            await sim.close();
        }
    });

    test('sign large nomination', async function () {
        const sim = new Zemu(APP_PATH);
        try {
            await sim.start(simOptions);
            const app = newCentrifugeApp(sim.getTransport());
            const pathAccount = 0x80000000;
            const pathChange = 0x80000000;
            const pathIndex = 0x80000000;

            let txBlobStr = "060540ff44b5d2eea05aee033e61ae3dc4b5fa5bc84c6e81a2320037f52bd1695998fe39ff4e9681fe22184b1989420ee5ef8f9ea5bf488b33e7e33c5cfba5b0ba7774a766ff1671d88131ecd52bfa3bcde246a9063a2de895878ea4dfccb5f9c91d1c14f435ffac1156362d74c9964a877ba0d2eced7f81fc1d9e72b4a28de461df92b0fa3140ff7c71020c7a19319f748a272ea8f6e1b2fbd87ebde83225a754bf2edc021c140cffecd729f00f09ff4e301de0b5aeaf717d955630dd1a5ece233755e3b0be7ebe11ff3aefdb1db2603d7ba4f259b81cd832f6f900b290a514e6f09d7b9071811e9e69ffa47bafe7cd25b6fc30523cc08f0a396895b99677ae03b54905fb5979d3538b6cffaa6f1fae766e30138c75c7cd102d45729a48ec29f0f49235f90db05d8bb0c648ff2c7d26191b827d57523585614a95b1ecd30f307a03ab5694ad7c6cf1f3845c1bffcaa3181634d3952efb925c5aaf0a8699b972864b620757347d1414d50678ec2bff82ec006b0cb4442b4ed23b0e74191e1b72e84813c32b32f1f6eb68385c215e03ffda9098e62c9d1a0bccbd74754108a6de9dcc667b8a37d836db347ea851c9642effda87dde348c26d14afade327d442a1837f902a85dbbb5276d543233c8d77346fff5ad7cc8977c23e06b3b795c6f1d652113cadaf2929484df1ec68d5cec291ef68ff223adf1784a64a4a650446dbbe9fe6553302aa19c07a7d731da0e152b0e3a07ad50391018ed73e0df000000001000000d77ea01f23717cbdf86a4ba6df00f8cec726cee71f5365a9e195e9806aaa5716d77ea01f23717cbdf86a4ba6df00f8cec726cee71f5365a9e195e9806aaa5716";

            const txBlob = Buffer.from(txBlobStr, "hex");

            const responseAddr = await app.getAddress(pathAccount, pathChange, pathIndex, false, 1);
            const pubKey = Buffer.from(responseAddr.pubKey, "hex");

            // do not wait here.. we need to navigate
            const signatureRequest = app.sign(pathAccount, pathChange, pathIndex, txBlob, 1);
            // Wait until we are not in the main menu
            await sim.waitUntilScreenIsNot(sim.getMainMenuSnapshot());

            await sim.compareSnapshotsAndAccept(".", "s-sign_large_nomination_sr25519", 34);

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
            let signingcontext = Buffer.from([]);
            const valid = addon.schnorrkel_verify(pubKey,signingcontext,prehash, signatureResponse.signature.slice(1));
            expect(valid).toEqual(true);
        } finally {
            await sim.close();
        }
    });

});
