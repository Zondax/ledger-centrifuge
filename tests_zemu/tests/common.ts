import { DeviceModel } from '@zondax/zemu'

const Resolve = require('path').resolve

export const APP_SEED = 'equip will roof matter pink blind book anxiety banner elbow sun young'

const APP_PATH_S = Resolve('../app/output/app_s.elf')
const APP_PATH_X = Resolve('../app/output/app_x.elf')
const APP_PATH_SP = Resolve('../app/output/app_s2.elf')

export const models: DeviceModel[] = [
  { name: 'nanos', prefix: 'S', path: APP_PATH_S },
  { name: 'nanox', prefix: 'X', path: APP_PATH_X },
  { name: 'nanosp', prefix: 'SP', path: APP_PATH_SP },
]

export const txBasic =
  '05002503d2029649d5038d2433158139ae28a3dfaac5fe1560a5e9e05cf00000000100000067dddf2673b69e5f875f6f25277495834398eafd67f492e09f3f3345e003d1b567dddf2673b69e5f875f6f25277495834398eafd67f492e09f3f3345e003d1b5'

export const txNomination =
  '060520ffe6d4144d715edfc14ba834e9d90a0be59d52810a86f47707b05e2e1eda31d277ff74927ebcee5f78d527e4572c1539de8db6d31802e4bb78e914a0e6ff8d2b1d11ffbae9b6ddea32c084125a7fc98a7d85c74d618c5aa4457e20c1f6d60435fcd47eff64e5a1599df7db957da76a913a516ac32462736eddc9c3da34d84bd74f3d1f1dfff2fa38176e0577b92287efcfdfa1ef1077feed884674b4a15b42c82acd07bb1bff8841cbfedcb1c5ea6fdd947093cbfd9f6ab4e313f6c321abd700ac6e9c612106ff18807b7cab1be33cbbc037b4d6589ca414b0c3e7819b814e19a2718d2335e47fff320aee1b7bc72df1bc734dfd9250b9157ae8b1782c5ee07db5d01f1b605fb62ed5038d246d0ff00000000100000067dddf2673b69e5f875f6f25277495834398eafd67f492e09f3f3345e003d1b567dddf2673b69e5f875f6f25277495834398eafd67f492e09f3f3345e003d1b5'
