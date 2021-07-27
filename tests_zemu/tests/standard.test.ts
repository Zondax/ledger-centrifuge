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

import Zemu, {DEFAULT_START_OPTIONS} from '@zondax/zemu'
import {APP_SEED, models} from './common'
import {newCentrifugeApp} from '@zondax/ledger-polkadot'

// @ts-ignore
import ed25519 from 'ed25519-supercop'
// @ts-ignore
import {blake2bFinal, blake2bInit, blake2bUpdate} from 'blakejs'

const defaultOptions = {
  ...DEFAULT_START_OPTIONS,
  logging: true,
  custom: `-s "${APP_SEED}"`,
  X11: false,
}

jest.setTimeout(60000)

describe('Standard', function () {
  test.each(models)('can start and stop container', async function (m) {
    const sim = new Zemu(m.path)
    try {
      await sim.start({...defaultOptions, model: m.name})
    } finally {
      await sim.close()
    }
  })

  test.each(models)('main menu', async function (m) {
    const sim = new Zemu(m.path)
    try {
      await sim.start({...defaultOptions, model: m.name})
      await sim.navigateAndCompareSnapshots('.', `${m.prefix.toLowerCase()}-mainmenu`, [1, 0, 0, 5, -5])
    } finally {
      await sim.close()
    }
  })

  test.each(models)('get app version', async function (m) {
    const sim = new Zemu(m.path)
    try {
      await sim.start({...defaultOptions, model: m.name})
      const app = newCentrifugeApp(sim.getTransport())
      const resp = await app.getVersion()

      console.log(resp)

      expect(resp.return_code).toEqual(0x9000)
      expect(resp.error_message).toEqual('No errors')
      expect(resp).toHaveProperty('test_mode')
      expect(resp).toHaveProperty('major')
      expect(resp).toHaveProperty('minor')
      expect(resp).toHaveProperty('patch')
    } finally {
      await sim.close()
    }
  })

  test.each(models)('get address', async function (m) {
    const sim = new Zemu(m.path)
    try {
      await sim.start({...defaultOptions, model: m.name})
      const app = newCentrifugeApp(sim.getTransport())

      const resp = await app.getAddress(0x80000000, 0x80000000, 0x80000000)

      console.log(resp)

      expect(resp.return_code).toEqual(0x9000)
      expect(resp.error_message).toEqual('No errors')

      const expected_address = '4dTWk5RN3BB5M1yoY8SuZsvNPRamdHgshe4TVNBpmWaMjvgr'
      const expected_pk = '5da18749c8443cddf9dcd5b6ba4330c1ab8f218b44fcdb9ef91b884e35e0be1f'

      expect(resp.address).toEqual(expected_address)
      expect(resp.pubKey).toEqual(expected_pk)
    } finally {
      await sim.close()
    }
  })

  test.each(models)('show address', async function (m) {
    const sim = new Zemu(m.path)
    try {
      await sim.start({...defaultOptions, model: m.name})
      const app = newCentrifugeApp(sim.getTransport())

      const respRequest = app.getAddress(0x80000000, 0x80000000, 0x80000000, true)
      // Wait until we are not in the main menu
      await sim.waitUntilScreenIsNot(sim.getMainMenuSnapshot())

      await sim.compareSnapshotsAndAccept('.', `${m.prefix.toLowerCase()}-show_address`, 2)

      const resp = await respRequest

      console.log(resp)

      expect(resp.return_code).toEqual(0x9000)
      expect(resp.error_message).toEqual('No errors')

      const expected_address = '4dTWk5RN3BB5M1yoY8SuZsvNPRamdHgshe4TVNBpmWaMjvgr'
      const expected_pk = '5da18749c8443cddf9dcd5b6ba4330c1ab8f218b44fcdb9ef91b884e35e0be1f'

      expect(resp.address).toEqual(expected_address)
      expect(resp.pubKey).toEqual(expected_pk)
    } finally {
      await sim.close()
    }
  })

  test.each(models)('show address - reject', async function (m) {
    const sim = new Zemu(m.path)
    try {
      await sim.start({...defaultOptions, model: m.name})
      const app = newCentrifugeApp(sim.getTransport())

      const respRequest = app.getAddress(0x80000000, 0x80000000, 0x80000000, true)
      // Wait until we are not in the main menu
      await sim.waitUntilScreenIsNot(sim.getMainMenuSnapshot())

      await sim.compareSnapshotsAndAccept('.', `${m.prefix.toLowerCase()}-show_address_reject`, 3, 2)

      const resp = await respRequest
      console.log(resp)

      expect(resp.return_code).toEqual(0x6986)
      expect(resp.error_message).toEqual('Transaction rejected')
    } finally {
      await sim.close()
    }
  })

  test.each(models)('sign basic normal', async function (m) {
    const sim = new Zemu(m.path)
    try {
      await sim.start({...defaultOptions, model: m.name})
      const app = newCentrifugeApp(sim.getTransport())
      const pathAccount = 0x80000000
      const pathChange = 0x80000000
      const pathIndex = 0x80000000

      const txBlobStr =
        '05002503d2029649d5038d2433158139ae28a3dfaac5fe1560a5e9e05cf00000000100000067dddf2673b69e5f875f6f25277495834398eafd67f492e09f3f3345e003d1b567dddf2673b69e5f875f6f25277495834398eafd67f492e09f3f3345e003d1b5'

      const txBlob = Buffer.from(txBlobStr, 'hex')

      const responseAddr = await app.getAddress(pathAccount, pathChange, pathIndex)
      const pubKey = Buffer.from(responseAddr.pubKey, 'hex')

      // do not wait here.. we need to navigate
      const signatureRequest = app.sign(pathAccount, pathChange, pathIndex, txBlob)
      // Wait until we are not in the main menu
      await sim.waitUntilScreenIsNot(sim.getMainMenuSnapshot())

      await sim.compareSnapshotsAndAccept('.', `${m.prefix.toLowerCase()}-sign_basic_normal`, m.name == "nanos" ? 5 : 6)

      const signatureResponse = await signatureRequest
      console.log(signatureResponse)

      expect(signatureResponse.return_code).toEqual(0x9000)
      expect(signatureResponse.error_message).toEqual('No errors')

      // Now verify the signature
      let prehash = txBlob
      if (txBlob.length > 256) {
        const context = blake2bInit(32, null)
        blake2bUpdate(context, txBlob)
        prehash = Buffer.from(blake2bFinal(context))
      }
      const valid = ed25519.verify(signatureResponse.signature.slice(1), prehash, pubKey)
      expect(valid).toEqual(true)
    } finally {
      await sim.close()
    }
  })

  test.each(models)('sign basic expert', async function (m) {
    const sim = new Zemu(m.path)
    try {
      await sim.start({...defaultOptions, model: m.name})
      const app = newCentrifugeApp(sim.getTransport())
      const pathAccount = 0x80000000
      const pathChange = 0x80000000
      const pathIndex = 0x80000000

      // Change to expert mode so we can skip fields
      await sim.clickRight()
      await sim.clickBoth()
      await sim.clickLeft()

      const txBlobStr =
        '05002503d2029649d5038d2433158139ae28a3dfaac5fe1560a5e9e05cf00000000100000067dddf2673b69e5f875f6f25277495834398eafd67f492e09f3f3345e003d1b567dddf2673b69e5f875f6f25277495834398eafd67f492e09f3f3345e003d1b5'

      const txBlob = Buffer.from(txBlobStr, 'hex')

      const responseAddr = await app.getAddress(pathAccount, pathChange, pathIndex)
      const pubKey = Buffer.from(responseAddr.pubKey, 'hex')

      // do not wait here.. we need to navigate
      const signatureRequest = app.sign(pathAccount, pathChange, pathIndex, txBlob)

      // Wait until we are not in the main menu
      await sim.waitUntilScreenIsNot(sim.getMainMenuSnapshot())

      await sim.compareSnapshotsAndAccept('.', `${m.prefix.toLowerCase()}-sign_basic_expert`, m.name == "nanos" ? 11 : 12)

      const signatureResponse = await signatureRequest
      console.log(signatureResponse)

      expect(signatureResponse.return_code).toEqual(0x9000)
      expect(signatureResponse.error_message).toEqual('No errors')

      // Now verify the signature
      let prehash = txBlob
      if (txBlob.length > 256) {
        const context = blake2bInit(32, null)
        blake2bUpdate(context, txBlob)
        prehash = Buffer.from(blake2bFinal(context))
      }
      const valid = ed25519.verify(signatureResponse.signature.slice(1), prehash, pubKey)
      expect(valid).toEqual(true)
    } finally {
      await sim.close()
    }
  })

  test.each(models)('sign large nomination', async function (m) {
    const sim = new Zemu(m.path)
    try {
      await sim.start({...defaultOptions, model: m.name})
      const app = newCentrifugeApp(sim.getTransport())
      const pathAccount = 0x80000000
      const pathChange = 0x80000000
      const pathIndex = 0x80000000

      const txBlobStr =
        '060520ffe6d4144d715edfc14ba834e9d90a0be59d52810a86f47707b05e2e1eda31d277ff74927ebcee5f78d527e4572c1539de8db6d31802e4bb78e914a0e6ff8d2b1d11ffbae9b6ddea32c084125a7fc98a7d85c74d618c5aa4457e20c1f6d60435fcd47eff64e5a1599df7db957da76a913a516ac32462736eddc9c3da34d84bd74f3d1f1dfff2fa38176e0577b92287efcfdfa1ef1077feed884674b4a15b42c82acd07bb1bff8841cbfedcb1c5ea6fdd947093cbfd9f6ab4e313f6c321abd700ac6e9c612106ff18807b7cab1be33cbbc037b4d6589ca414b0c3e7819b814e19a2718d2335e47fff320aee1b7bc72df1bc734dfd9250b9157ae8b1782c5ee07db5d01f1b605fb62ed5038d246d0ff00000000100000067dddf2673b69e5f875f6f25277495834398eafd67f492e09f3f3345e003d1b567dddf2673b69e5f875f6f25277495834398eafd67f492e09f3f3345e003d1b5'

      const txBlob = Buffer.from(txBlobStr, 'hex')

      const responseAddr = await app.getAddress(pathAccount, pathChange, pathIndex)
      const pubKey = Buffer.from(responseAddr.pubKey, 'hex')

      // do not wait here.. we need to navigate
      const signatureRequest = app.sign(pathAccount, pathChange, pathIndex, txBlob)
      // Wait until we are not in the main menu
      await sim.waitUntilScreenIsNot(sim.getMainMenuSnapshot())

      await sim.compareSnapshotsAndAccept('.', `${m.prefix.toLowerCase()}-sign_large_nomination`, m.name === 'nanos' ? 18 : 13)

      const signatureResponse = await signatureRequest
      console.log(signatureResponse)

      expect(signatureResponse.return_code).toEqual(0x9000)
      expect(signatureResponse.error_message).toEqual('No errors')

      // Now verify the signature
      let prehash = txBlob
      if (txBlob.length > 256) {
        const context = blake2bInit(32, null)
        blake2bUpdate(context, txBlob)
        prehash = Buffer.from(blake2bFinal(context))
      }
      const valid = ed25519.verify(signatureResponse.signature.slice(1), prehash, pubKey)
      expect(valid).toEqual(true)
    } finally {
      await sim.close()
    }
  })
})