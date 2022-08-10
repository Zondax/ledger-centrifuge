# Centrifuge  1.1007.x

## System

| Name        | Light | XL | Nesting | Arguments |
| :---------- |:------------:|:--------:|:--------:|:--------|
|Fill block |    |   |   | `Perbill` ratio <br/> |
|Remark |    |   |   | `Vecu8` remark <br/> |
|Set heap pages |    |   |   | `u64` pages <br/> |
|Set code |    |   |   | `Vecu8` code <br/> |
|Set code without checks |    |   |   | `Vecu8` code <br/> |
|Set storage |    |   |   | `VecKeyValue` items <br/> |
|Kill storage |    |   |   | `VecKey` keys <br/> |
|Kill prefix |    |   |   | `Key` prefix <br/>`u32` subkeys <br/> |
|Remark with event |    |   |   | `Vecu8` remark <br/> |

## ParachainSystem

| Name        | Light | XL | Nesting | Arguments |
| :---------- |:------------:|:--------:|:--------:|:--------|
|Set validation data |    |   |   | `ParachainInherentData` data <br/> |
|Sudo send upward message |    |   |   | `UpwardMessage` message <br/> |
|Authorize upgrade |    |   |   | `Hash` code_hash <br/> |
|Enact authorized upgrade |    |   |   | `Vecu8` code <br/> |

## Timestamp

| Name        | Light | XL | Nesting | Arguments |
| :---------- |:------------:|:--------:|:--------:|:--------|
|Set |    |   |   | `Compactu64` now <br/> |

## Balances

| Name        | Light | XL | Nesting | Arguments |
| :---------- |:------------:|:--------:|:--------:|:--------|
|Transfer | :heavy_check_mark:  | :heavy_check_mark: | :heavy_check_mark: | `LookupasStaticLookupSource` dest <br/>`CompactBalance` amount <br/> |
|Set balance |    | :heavy_check_mark: | :heavy_check_mark: | `LookupasStaticLookupSource` who <br/>`CompactBalance` new_free <br/>`CompactBalance` new_reserved <br/> |
|Force transfer | :heavy_check_mark:  | :heavy_check_mark: | :heavy_check_mark: | `LookupasStaticLookupSource` source <br/>`LookupasStaticLookupSource` dest <br/>`CompactBalance` amount <br/> |
|Transfer keep alive | :heavy_check_mark:  | :heavy_check_mark: | :heavy_check_mark: | `LookupasStaticLookupSource` dest <br/>`CompactBalance` amount <br/> |
|Transfer all | :heavy_check_mark:  | :heavy_check_mark: |   | `LookupasStaticLookupSource` dest <br/>`bool` keep_alive <br/> |
|Force unreserve |    | :heavy_check_mark: |   | `LookupasStaticLookupSource` who <br/>`Balance` amount <br/> |

## Authorship

| Name        | Light | XL | Nesting | Arguments |
| :---------- |:------------:|:--------:|:--------:|:--------|
|Set uncles |    |   |   | `VecHeader` new_uncles <br/> |

## Session

| Name        | Light | XL | Nesting | Arguments |
| :---------- |:------------:|:--------:|:--------:|:--------|
|Set keys |    |   |   | `Keys` keys <br/>`Bytes` proof <br/> |
|Purge keys |    |   |   |  |

## Multisig

| Name        | Light | XL | Nesting | Arguments |
| :---------- |:------------:|:--------:|:--------:|:--------|
|As multi threshold 1 |    |   |   | `VecAccountId` other_signatories <br/>`Call` call <br/> |
|As multi |    |   |   | `u16` threshold <br/>`VecAccountId` other_signatories <br/>`OptionTimepoint` maybe_timepoint <br/>`OpaqueCall` call <br/>`bool` store_call <br/>`Weight` max_weight <br/> |
|Approve as multi |    |   |   | `u16` threshold <br/>`VecAccountId` other_signatories <br/>`OptionTimepoint` maybe_timepoint <br/>`H256` call_hash <br/>`Weight` max_weight <br/> |
|Cancel as multi |    |   |   | `u16` threshold <br/>`VecAccountId` other_signatories <br/>`Timepoint` timepoint <br/>`H256` call_hash <br/> |

## Proxy

| Name        | Light | XL | Nesting | Arguments |
| :---------- |:------------:|:--------:|:--------:|:--------|
|Proxy |    |   |   | `AccountId` real <br/>`OptionProxyType` force_proxy_type <br/>`Call` call <br/> |
|Add proxy |    |   |   | `AccountId` delegate <br/>`ProxyType` proxy_type <br/>`BlockNumber` delay <br/> |
|Remove proxy |    |   |   | `AccountId` delegate <br/>`ProxyType` proxy_type <br/>`BlockNumber` delay <br/> |
|Remove proxies |    |   |   |  |
|Anonymous |    |   |   | `ProxyType` proxy_type <br/>`BlockNumber` delay <br/>`u16` index <br/> |
|Kill anonymous |    |   |   | `AccountId` spawner <br/>`ProxyType` proxy_type <br/>`u16` index <br/>`Compactu32` height <br/>`Compactu32` ext_index <br/> |
|Announce |    |   |   | `AccountId` real <br/>`CallHashOf` call_hash <br/> |
|Remove announcement |    |   |   | `AccountId` real <br/>`CallHashOf` call_hash <br/> |
|Reject announcement |    |   |   | `AccountId` delegate <br/>`CallHashOf` call_hash <br/> |
|Proxy announced |    |   |   | `AccountId` delegate <br/>`AccountId` real <br/>`OptionProxyType` force_proxy_type <br/>`Call` call <br/> |

## Utility

| Name        | Light | XL | Nesting | Arguments |
| :---------- |:------------:|:--------:|:--------:|:--------|
|Batch |    |   |   | `VecCall` calls <br/> |
|As derivative |    |   |   | `u16` index <br/>`Call` call <br/> |
|Batch all |    |   |   | `VecCall` calls <br/> |
|Dispatch as |    |   |   | `BoxPalletsOrigin` as_origin <br/>`Call` call <br/> |
|Force batch |    |   |   | `VecCall` calls <br/> |

## Scheduler

| Name        | Light | XL | Nesting | Arguments |
| :---------- |:------------:|:--------:|:--------:|:--------|
|Schedule |    |   |   | `BlockNumber` when <br/>`OptionschedulePeriodBlockNumber` maybe_periodic <br/>`schedulePriority` priority <br/>`BoxCallOrHashOfT` call <br/> |
|Cancel |    |   |   | `BlockNumber` when <br/>`u32` index <br/> |
|Schedule named |    |   |   | `Vecu8` id <br/>`BlockNumber` when <br/>`OptionschedulePeriodBlockNumber` maybe_periodic <br/>`schedulePriority` priority <br/>`BoxCallOrHashOfT` call <br/> |
|Cancel named |    |   |   | `Vecu8` id <br/> |
|Schedule after |    |   |   | `BlockNumber` after <br/>`OptionschedulePeriodBlockNumber` maybe_periodic <br/>`schedulePriority` priority <br/>`BoxCallOrHashOfT` call <br/> |
|Schedule named after |    |   |   | `Vecu8` id <br/>`BlockNumber` after <br/>`OptionschedulePeriodBlockNumber` maybe_periodic <br/>`schedulePriority` priority <br/>`BoxCallOrHashOfT` call <br/> |

## Council

| Name        | Light | XL | Nesting | Arguments |
| :---------- |:------------:|:--------:|:--------:|:--------|
|Set members |    |   |   | `VecAccountId` new_members <br/>`OptionAccountId` prime <br/>`MemberCount` old_count <br/> |
|Execute |    |   |   | `Proposal` proposal <br/>`Compactu32` length_bound <br/> |
|Propose |    |   |   | `Compactu32` threshold <br/>`Proposal` proposal <br/>`Compactu32` length_bound <br/> |
|Vote |    |   |   | `Hash` proposal <br/>`Compactu32` index <br/>`bool` approve <br/> |
|Close |    |   |   | `Hash` proposal_hash <br/>`Compactu32` index <br/>`Compactu64` proposal_weight_bound <br/>`Compactu32` length_bound <br/> |
|Disapprove proposal |    |   |   | `Hash` proposal_hash <br/> |

## Elections

| Name        | Light | XL | Nesting | Arguments |
| :---------- |:------------:|:--------:|:--------:|:--------|
|Vote |    |   |   | `VecAccountId` votes <br/>`Compactu128` amount <br/> |
|Remove voter |    |   |   |  |
|Submit candidacy |    |   |   | `Compactu32` candidate_count <br/> |
|Renounce candidacy |    |   |   | `Renouncing` renouncing <br/> |
|Remove member |    |   |   | `LookupasStaticLookupSource` who <br/>`bool` has_replacement <br/> |
|Clean defunct voters |    |   |   | `u32` num_voters <br/>`u32` num_defunct <br/> |

## Democracy

| Name        | Light | XL | Nesting | Arguments |
| :---------- |:------------:|:--------:|:--------:|:--------|
|Propose |    |   |   | `Hash` proposal_hash <br/>`CompactBalance` amount <br/> |
|Second |    |   |   | `Compactu32` proposal <br/>`Compactu32` seconds_upper_bound <br/> |
|Vote |    |   |   | `Compactu32` ref_index <br/>`AccountVote` vote <br/> |
|Emergency cancel |    |   |   | `ReferendumIndex` ref_index <br/> |
|External propose |    |   |   | `Hash` proposal_hash <br/> |
|External propose majority |    |   |   | `Hash` proposal_hash <br/> |
|External propose default |    |   |   | `Hash` proposal_hash <br/> |
|Fast track |    |   |   | `Hash` proposal_hash <br/>`BlockNumber` voting_period <br/>`BlockNumber` delay <br/> |
|Veto external |    |   |   | `Hash` proposal_hash <br/> |
|Cancel referendum |    |   |   | `Compactu32` ref_index <br/> |
|Cancel queued |    |   |   | `ReferendumIndex` which <br/> |
|Delegate |    |   |   | `AccountId` to <br/>`Conviction` conviction <br/>`Balance` balance <br/> |
|Undelegate |    |   |   |  |
|Clear public proposals |    |   |   |  |
|Note preimage |    |   |   | `Bytes` encoded_proposal <br/> |
|Note preimage operational |    |   |   | `Bytes` encoded_proposal <br/> |
|Note imminent preimage |    |   |   | `Bytes` encoded_proposal <br/> |
|Note imminent preimage operational |    |   |   | `Bytes` encoded_proposal <br/> |
|Reap preimage |    |   |   | `Hash` proposal_hash <br/>`Compactu32` proposal_len_upper_bound <br/> |
|Unlock |    |   |   | `AccountId` target <br/> |
|Remove vote |    |   |   | `ReferendumIndex` index <br/> |
|Remove other vote |    |   |   | `AccountId` target <br/>`ReferendumIndex` index <br/> |
|Enact proposal |    |   |   | `Hash` proposal_hash <br/>`ReferendumIndex` index <br/> |
|Blacklist |    |   |   | `Hash` proposal_hash <br/>`OptionReferendumIndex` maybe_ref_index <br/> |
|Cancel proposal |    |   |   | `Compactu32` prop_index <br/> |

## Identity

| Name        | Light | XL | Nesting | Arguments |
| :---------- |:------------:|:--------:|:--------:|:--------|
|Add registrar |    |   |   | `AccountId` account <br/> |
|Set identity |    |   |   | `BoxIdentityInfoMaxAdditionalFields` info <br/> |
|Set subs |    |   |   | `VecTupleAccountIdData` subs <br/> |
|Clear identity |    |   |   |  |
|Request judgement |    |   |   | `Compactu32` reg_index <br/>`Compactu128` max_fee <br/> |
|Cancel request |    |   |   | `RegistrarIndex` reg_index <br/> |
|Set fee |    |   |   | `Compactu32` index <br/>`Compactu128` fee <br/> |
|Set account id |    |   |   | `Compactu32` index <br/>`AccountId` new_ <br/> |
|Set fields |    |   |   | `Compactu32` index <br/>`IdentityFields` fields <br/> |
|Provide judgement |    |   |   | `Compactu32` reg_index <br/>`LookupasStaticLookupSource` target <br/>`JudgementBalanceOfT` judgement <br/> |
|Kill identity |    |   |   | `LookupasStaticLookupSource` target <br/> |
|Add sub |    |   |   | `LookupasStaticLookupSource` sub <br/>`Data` data <br/> |
|Rename sub |    |   |   | `LookupasStaticLookupSource` sub <br/>`Data` data <br/> |
|Remove sub |    |   |   | `LookupasStaticLookupSource` sub <br/> |
|Quit sub |    |   |   |  |

## Vesting

| Name        | Light | XL | Nesting | Arguments |
| :---------- |:------------:|:--------:|:--------:|:--------|
|Vest |    |   |   |  |
|Vest other |    |   |   | `LookupasStaticLookupSource` target <br/> |
|Vested transfer |    |   |   | `LookupasStaticLookupSource` target <br/>`VestingInfo` schedule <br/> |
|Force vested transfer |    |   |   | `LookupasStaticLookupSource` source <br/>`LookupasStaticLookupSource` target <br/>`VestingInfo` schedule <br/> |
|Merge schedules |    |   |   | `u32` schedule1_index <br/>`u32` schedule2_index <br/> |

## Preimage

| Name        | Light | XL | Nesting | Arguments |
| :---------- |:------------:|:--------:|:--------:|:--------|
|Note preimage |    |   |   | `Vecu8` bytes <br/> |
|Unnote preimage |    |   |   | `Hash` hash <br/> |
|Request preimage |    |   |   | `Hash` hash <br/> |
|Unrequest preimage |    |   |   | `Hash` hash <br/> |

## Treasury

| Name        | Light | XL | Nesting | Arguments |
| :---------- |:------------:|:--------:|:--------:|:--------|
|Propose spend |    |   |   | `CompactBalance` amount <br/>`LookupasStaticLookupSource` beneficiary <br/> |
|Reject proposal |    |   |   | `Compactu32` proposal_id <br/> |
|Approve proposal |    |   |   | `Compactu32` proposal_id <br/> |
|Remove approval |    |   |   | `Compactu32` proposal_id <br/> |

## Fees

| Name        | Light | XL | Nesting | Arguments |
| :---------- |:------------:|:--------:|:--------:|:--------|
|Set fee |    |   |   | `Hash` key <br/>`Balance` new_price <br/> |

## Anchor

| Name        | Light | XL | Nesting | Arguments |
| :---------- |:------------:|:--------:|:--------:|:--------|
|Pre commit |    |   |   | `Hash` anchor_id <br/>`Hash` signing_root <br/> |
|Commit |    |   |   | `Hash` anchor_id_preimage <br/>`Hash` doc_root <br/>`Hash` proof <br/>`Moment` stored_until_date <br/> |
|Evict pre commits |    |   |   | `BlockNumber` evict_bucket <br/> |
|Evict anchors |    |   |   |  |

## Claims

| Name        | Light | XL | Nesting | Arguments |
| :---------- |:------------:|:--------:|:--------:|:--------|
|Claim |    |   |   | `AccountId` account_id <br/>`Balance` amount <br/>`VecHash` sorted_hashes <br/> |
|Set upload account |    |   |   | `AccountId` account_id <br/> |
|Store root hash |    |   |   | `Hash` root_hash <br/> |

## Nfts

| Name        | Light | XL | Nesting | Arguments |
| :---------- |:------------:|:--------:|:--------:|:--------|
|Validate mint |    |   |   | `SystemHashOfT` anchor_id <br/>`DepositAddress` deposit_address <br/>`VecProofHasherHashOfBundleHasher` proofs <br/>`FixedArrayHasherHashOfBundleHasher3` static_proofs <br/>`TasConfigChainId` dest_id <br/> |

## Bridge

| Name        | Light | XL | Nesting | Arguments |
| :---------- |:------------:|:--------:|:--------:|:--------|
|Transfer native |    |   |   | `Balance` amount <br/>`Vecu8` recipient <br/>`ChainId` dest_id <br/> |
|Transfer |    |   |   | `AccountId` to <br/>`Balance` amount <br/>`H256` r_id <br/> |
|Remark |    |   |   | `Hash` hash <br/>`H256` r_id <br/> |
|Set native token transfer fee |    |   |   | `Balance` new_fee <br/> |
|Set nft token transfer fee |    |   |   | `Balance` new_fee <br/> |

## Migration

| Name        | Light | XL | Nesting | Arguments |
| :---------- |:------------:|:--------:|:--------:|:--------|
|Migrate system account |    |   |   | `VecTupleVecu8Vecu8` accounts <br/> |
|Migrate balances issuance |    |   |   | `Balance` additional_issuance <br/> |
|Migrate vesting vesting |    |   |   | `VecTupleAccountIdVestingInfoBalanceOfTBlockNumber` vestings <br/> |
|Migrate proxy proxies |    |   |   | `VecAccountIdTaspallet_proxyConfigCurrencyasframe_supporttraitsCurrencyTasframe_systemConfigAccountIdBalanceBoundedVecProxyDefinitionAccountIdProxyTypeBlockNumberTaspallet_proxyConfigMaxProxiesTaspallet_proxyConfigCurrencyasframe_supporttraitsCurrencyTasframe_systemConfigAccountIdBalance` proxies <br/> |
|Finalize |    |   |   |  |

## CrowdloanClaim

| Name        | Light | XL | Nesting | Arguments |
| :---------- |:------------:|:--------:|:--------:|:--------|
|Claim reward |    |   |   | `RelayChainAccountId` relaychain_account_id <br/>`ParachainAccountIdOfT` parachain_account_id <br/>`MultiSignature` identity_proof <br/>`ProofHash` contribution_proof <br/>`Balance` contribution <br/> |
|Initialize |    |   |   | `RootHashOfT` contributions <br/>`BlockNumber` locked_at <br/>`TrieIndex` index <br/>`BlockNumber` lease_start <br/>`BlockNumber` lease_period <br/> |
|Set lease start |    |   |   | `BlockNumber` start <br/> |
|Set lease period |    |   |   | `BlockNumber` period <br/> |
|Set contributions root |    |   |   | `RootHashOfT` root <br/> |
|Set locked at |    |   |   | `BlockNumber` locked_at <br/> |
|Set crowdloan trie index |    |   |   | `TrieIndex` trie_index <br/> |

## CrowdloanReward

| Name        | Light | XL | Nesting | Arguments |
| :---------- |:------------:|:--------:|:--------:|:--------|
|Initialize |    |   |   | `Perbill` direct_payout_ratio <br/>`BlockNumber` vesting_period <br/>`BlockNumber` vesting_start <br/> |
|Set vesting start |    |   |   | `BlockNumber` start <br/> |
|Set vesting period |    |   |   | `BlockNumber` period <br/> |
|Set direct payout ratio |    |   |   | `Perbill` ratio <br/> |

## ChainBridge

| Name        | Light | XL | Nesting | Arguments |
| :---------- |:------------:|:--------:|:--------:|:--------|
|Set threshold |    |   |   | `u32` threshold <br/> |
|Set resource |    |   |   | `H256` id <br/>`Vecu8` method <br/> |
|Remove resource |    |   |   | `H256` id <br/> |
|Whitelist chain |    |   |   | `ChainId` id <br/> |
|Add relayer |    |   |   | `AccountId` v <br/> |
|Remove relayer |    |   |   | `AccountId` account_id <br/> |
|Acknowledge proposal |    |   |   | `DepositNonce` nonce <br/>`ChainId` src_id <br/>`H256` r_id <br/>`BoxTasConfigProposal` call <br/> |
|Reject proposal |    |   |   | `DepositNonce` nonce <br/>`ChainId` src_id <br/>`H256` r_id <br/>`BoxTasConfigProposal` call <br/> |
|Eval vote state |    |   |   | `DepositNonce` nonce <br/>`ChainId` src_id <br/>`BoxTasConfigProposal` proposal <br/> |

