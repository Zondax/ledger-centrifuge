# Centrifuge  1.242.x

## System

| Name        | Light | XL | Nesting | Arguments | 
| :---------- |:------------:|:--------:|:--------:|:--------|
|fill_block |    | :white_check_mark: | :white_check_mark: | `Perbill` _ratio <br/> | 
|remark |    | :white_check_mark: |   | `Bytes` _remark <br/> | 
|set_heap_pages |    | :white_check_mark: |   | `u64` pages <br/> | 
|set_code |    | :white_check_mark: |   | `Bytes` code <br/> | 
|set_code_without_checks |    | :white_check_mark: |   | `Bytes` code <br/> | 
|set_changes_trie_config |    |   |   | `Option<ChangesTrieConfiguration>` changes_trie_config <br/> | 
|set_storage |    |   |   | `Vec<KeyValue>` items <br/> | 
|kill_storage |    |   |   | `Vec<Key>` keys <br/> | 
|kill_prefix |    |   |   | `Key` prefix <br/>`u32` _subkeys <br/> | 
|suicide |    | :white_check_mark: |   |  | 

## Utility

| Name        | Light | XL | Nesting | Arguments | 
| :---------- |:------------:|:--------:|:--------:|:--------|
|batch | :white_check_mark:  | :white_check_mark: |   | `Vec<Call>` calls <br/> | 
|as_derivative |    |   |   | `u16` index <br/>`Call` call <br/> | 

## Babe

| Name        | Light | XL | Nesting | Arguments | 
| :---------- |:------------:|:--------:|:--------:|:--------|
|report_equivocation |    |   |   | `BabeEquivocationProof` equivocation_proof <br/>`KeyOwnerProof` key_owner_proof <br/> | 
|report_equivocation_unsigned |    |   |   | `BabeEquivocationProof` equivocation_proof <br/>`KeyOwnerProof` key_owner_proof <br/> | 

## Timestamp

| Name        | Light | XL | Nesting | Arguments | 
| :---------- |:------------:|:--------:|:--------:|:--------|
|set |    | :white_check_mark: |   | `Compact<Moment>` now <br/> | 

## Authorship

| Name        | Light | XL | Nesting | Arguments | 
| :---------- |:------------:|:--------:|:--------:|:--------|
|set_uncles |    |   |   | `Vec<Header>` new_uncles <br/> | 

## Balances

| Name        | Light | XL | Nesting | Arguments | 
| :---------- |:------------:|:--------:|:--------:|:--------|
|transfer | :white_check_mark:  | :white_check_mark: | :white_check_mark: | `LookupSource` dest <br/>`Compact<Balance>` value <br/> | 
|set_balance |    | :white_check_mark: |   | `LookupSource` who <br/>`Compact<Balance>` new_free <br/>`Compact<Balance>` new_reserved <br/> | 
|force_transfer |    | :white_check_mark: |   | `LookupSource` source <br/>`LookupSource` dest <br/>`Compact<Balance>` value <br/> | 
|transfer_keep_alive | :white_check_mark:  | :white_check_mark: | :white_check_mark: | `LookupSource` dest <br/>`Compact<Balance>` value <br/> | 

## TransactionPayment

Empty

## Staking

| Name        | Light | XL | Nesting | Arguments | 
| :---------- |:------------:|:--------:|:--------:|:--------|
|bond | :white_check_mark:  | :white_check_mark: | :white_check_mark: | `LookupSource` controller <br/>`Compact<BalanceOf>` value <br/>`RewardDestination` payee <br/> | 
|bond_extra | :white_check_mark:  | :white_check_mark: | :white_check_mark: | `Compact<BalanceOf>` max_additional <br/> | 
|unbond | :white_check_mark:  | :white_check_mark: | :white_check_mark: | `Compact<BalanceOf>` value <br/> | 
|withdraw_unbonded |    | :white_check_mark: |   | `u32` num_slashing_spans <br/> | 
|validate | :white_check_mark:  | :white_check_mark: | :white_check_mark: | `ValidatorPrefs` prefs <br/> | 
|nominate | :white_check_mark:  | :white_check_mark: | :white_check_mark: | `Vec<LookupSource>` targets <br/> | 
|chill | :white_check_mark:  | :white_check_mark: | :white_check_mark: |  | 
|set_payee | :white_check_mark:  | :white_check_mark: | :white_check_mark: | `RewardDestination` payee <br/> | 
|set_controller | :white_check_mark:  | :white_check_mark: | :white_check_mark: | `LookupSource` controller <br/> | 
|set_validator_count |    | :white_check_mark: |   | `Compact<u32>` new <br/> | 
|increase_validator_count |    | :white_check_mark: |   | `Compact<u32>` additional <br/> | 
|scale_validator_count |    |   |   | `Percent` factor <br/> | 
|force_no_eras |    | :white_check_mark: |   |  | 
|force_new_era |    | :white_check_mark: |   |  | 
|set_invulnerables |    | :white_check_mark: |   | `Vec<AccountId>` validators <br/> | 
|force_unstake |    | :white_check_mark: |   | `AccountId` stash <br/>`u32` num_slashing_spans <br/> | 
|force_new_era_always |    | :white_check_mark: |   |  | 
|cancel_deferred_slash |    | :white_check_mark: |   | `EraIndex` era <br/>`Vec<u32>` slash_indices <br/> | 
|payout_stakers |    | :white_check_mark: |   | `AccountId` validator_stash <br/>`EraIndex` era <br/> | 
|rebond |    | :white_check_mark: | :white_check_mark: | `Compact<BalanceOf>` value <br/> | 
|set_history_depth |    | :white_check_mark: |   | `Compact<EraIndex>` new_history_depth <br/>`Compact<u32>` _era_items_deleted <br/> | 
|reap_stash |    | :white_check_mark: |   | `AccountId` stash <br/>`u32` num_slashing_spans <br/> | 
|submit_election_solution |    |   |   | `Vec<ValidatorIndex>` winners <br/>`CompactAssignments` compact <br/>`ElectionScore` score <br/>`EraIndex` era <br/>`ElectionSize` size <br/> | 
|submit_election_solution_unsigned |    |   |   | `Vec<ValidatorIndex>` winners <br/>`CompactAssignments` compact <br/>`ElectionScore` score <br/>`EraIndex` era <br/>`ElectionSize` size <br/> | 

## Session

| Name        | Light | XL | Nesting | Arguments | 
| :---------- |:------------:|:--------:|:--------:|:--------|
|set_keys | :white_check_mark:  | :white_check_mark: |   | `Keys` keys <br/>`Bytes` proof <br/> | 
|purge_keys | :white_check_mark:  | :white_check_mark: |   |  | 

## Democracy

| Name        | Light | XL | Nesting | Arguments | 
| :---------- |:------------:|:--------:|:--------:|:--------|
|propose | :white_check_mark:  | :white_check_mark: |   | `Hash` proposal_hash <br/>`Compact<BalanceOf>` value <br/> | 
|second | :white_check_mark:  | :white_check_mark: |   | `Compact<PropIndex>` proposal <br/>`Compact<u32>` seconds_upper_bound <br/> | 
|vote | :white_check_mark:  | :white_check_mark: |   | `Compact<ReferendumIndex>` ref_index <br/>`AccountVote` vote <br/> | 
|emergency_cancel |    | :white_check_mark: |   | `ReferendumIndex` ref_index <br/> | 
|external_propose | :white_check_mark:  | :white_check_mark: |   | `Hash` proposal_hash <br/> | 
|external_propose_majority | :white_check_mark:  | :white_check_mark: |   | `Hash` proposal_hash <br/> | 
|external_propose_default | :white_check_mark:  | :white_check_mark: |   | `Hash` proposal_hash <br/> | 
|fast_track | :white_check_mark:  | :white_check_mark: |   | `Hash` proposal_hash <br/>`BlockNumber` voting_period <br/>`BlockNumber` delay <br/> | 
|veto_external |    | :white_check_mark: |   | `Hash` proposal_hash <br/> | 
|cancel_referendum |    | :white_check_mark: |   | `Compact<ReferendumIndex>` ref_index <br/> | 
|cancel_queued |    | :white_check_mark: |   | `ReferendumIndex` which <br/> | 
|delegate |    | :white_check_mark: |   | `AccountId` to <br/>`Conviction` conviction <br/>`BalanceOf` balance <br/> | 
|undelegate |    | :white_check_mark: |   |  | 
|clear_public_proposals |    | :white_check_mark: |   |  | 
|note_preimage |    | :white_check_mark: |   | `Bytes` encoded_proposal <br/> | 
|note_preimage_operational |    | :white_check_mark: |   | `Bytes` encoded_proposal <br/> | 
|note_imminent_preimage |    | :white_check_mark: |   | `Bytes` encoded_proposal <br/> | 
|note_imminent_preimage_operational |    | :white_check_mark: |   | `Bytes` encoded_proposal <br/> | 
|reap_preimage |    | :white_check_mark: |   | `Hash` proposal_hash <br/>`Compact<u32>` proposal_len_upper_bound <br/> | 
|unlock | :white_check_mark:  | :white_check_mark: |   | `AccountId` target <br/> | 
|remove_vote |    | :white_check_mark: |   | `ReferendumIndex` index <br/> | 
|remove_other_vote |    | :white_check_mark: |   | `AccountId` target <br/>`ReferendumIndex` index <br/> | 
|enact_proposal |    | :white_check_mark: |   | `Hash` proposal_hash <br/>`ReferendumIndex` index <br/> | 

## Council

| Name        | Light | XL | Nesting | Arguments | 
| :---------- |:------------:|:--------:|:--------:|:--------|
|set_members |    | :white_check_mark: |   | `Vec<AccountId>` new_members <br/>`Option<AccountId>` prime <br/>`MemberCount` old_count <br/> | 
|execute | :white_check_mark:  | :white_check_mark: |   | `Proposal` proposal <br/>`Compact<u32>` length_bound <br/> | 
|propose | :white_check_mark:  | :white_check_mark: |   | `Compact<MemberCount>` threshold <br/>`Proposal` proposal <br/>`Compact<u32>` length_bound <br/> | 
|vote | :white_check_mark:  | :white_check_mark: |   | `Hash` proposal <br/>`Compact<ProposalIndex>` index <br/>`bool` approve <br/> | 
|close | :white_check_mark:  | :white_check_mark: |   | `Hash` proposal_hash <br/>`Compact<ProposalIndex>` index <br/>`Compact<Weight>` proposal_weight_bound <br/>`Compact<u32>` length_bound <br/> | 
|disapprove_proposal | :white_check_mark:  | :white_check_mark: |   | `Hash` proposal_hash <br/> | 

## Elections

| Name        | Light | XL | Nesting | Arguments | 
| :---------- |:------------:|:--------:|:--------:|:--------|
|vote | :white_check_mark:  | :white_check_mark: |   | `Vec<AccountId>` votes <br/>`Compact<BalanceOf>` value <br/> | 
|remove_voter |    | :white_check_mark: |   |  | 
|report_defunct_voter |    | :white_check_mark: |   | `DefunctVoter` defunct <br/> | 
|submit_candidacy | :white_check_mark:  | :white_check_mark: |   | `Compact<u32>` candidate_count <br/> | 
|renounce_candidacy | :white_check_mark:  | :white_check_mark: |   | `Renouncing` renouncing <br/> | 
|remove_member |    | :white_check_mark: |   | `LookupSource` who <br/>`bool` has_replacement <br/> | 

## FinalityTracker

| Name        | Light | XL | Nesting | Arguments | 
| :---------- |:------------:|:--------:|:--------:|:--------|
|final_hint |    | :white_check_mark: |   | `Compact<BlockNumber>` hint <br/> | 

## Grandpa

| Name        | Light | XL | Nesting | Arguments | 
| :---------- |:------------:|:--------:|:--------:|:--------|
|report_equivocation |    |   |   | `GrandpaEquivocationProof` equivocation_proof <br/>`KeyOwnerProof` key_owner_proof <br/> | 
|report_equivocation_unsigned |    |   |   | `GrandpaEquivocationProof` equivocation_proof <br/>`KeyOwnerProof` key_owner_proof <br/> | 
|note_stalled |    | :white_check_mark: |   | `BlockNumber` delay <br/>`BlockNumber` best_finalized_block_number <br/> | 

## ImOnline

| Name        | Light | XL | Nesting | Arguments | 
| :---------- |:------------:|:--------:|:--------:|:--------|
|heartbeat |    |   |   | `Heartbeat` heartbeat <br/>`Signature` _signature <br/> | 

## AuthorityDiscovery

| Name        | Light | XL | Nesting | Arguments | 
| :---------- |:------------:|:--------:|:--------:|:--------|

## Offences

| Name        | Light | XL | Nesting | Arguments | 
| :---------- |:------------:|:--------:|:--------:|:--------|

## RandomnessCollectiveFlip

| Name        | Light | XL | Nesting | Arguments | 
| :---------- |:------------:|:--------:|:--------:|:--------|

## Anchor

| Name        | Light | XL | Nesting | Arguments | 
| :---------- |:------------:|:--------:|:--------:|:--------|
|pre_commit |    | :white_check_mark: |   | `Hash` anchor_id <br/>`Hash` signing_root <br/> | 
|commit |    | :white_check_mark: |   | `Hash` anchor_id_preimage <br/>`Hash` doc_root <br/>`Hash` proof <br/>`Moment` stored_until_date <br/> | 
|evict_pre_commits |    | :white_check_mark: |   | `BlockNumber` evict_bucket <br/> | 
|evict_anchors |    | :white_check_mark: |   |  | 

## Fees

| Name        | Light | XL | Nesting | Arguments | 
| :---------- |:------------:|:--------:|:--------:|:--------|
|set_fee |    | :white_check_mark: |   | `Hash` key <br/>`Balance` new_price <br/> | 

## Nfts

| Name        | Light | XL | Nesting | Arguments | 
| :---------- |:------------:|:--------:|:--------:|:--------|
|validate_mint |    |   |   | `Hash` anchor_id <br/>`[u8;20]` deposit_address <br/>`Vec<Proof>` pfs <br/>`[H256;3]` static_proofs <br/>`ChainId` dest_id <br/> | 

## MultiAccount

| Name        | Light | XL | Nesting | Arguments | 
| :---------- |:------------:|:--------:|:--------:|:--------|
|create |    |   |   | `u16` threshold <br/>`Vec<AccountId>` other_signatories <br/> | 
|update |    |   |   | `u16` threshold <br/>`Vec<AccountId>` signatories <br/> | 
|remove |    |   |   |  | 
|call |    |   |   | `AccountId` multi_account_id <br/>`Option<Timepoint>` maybe_timepoint <br/>`Call` call <br/> | 
|approve |    |   |   | `AccountId` multi_account_id <br/>`Option<Timepoint>` maybe_timepoint <br/>`[u8;32]` call_hash <br/> | 
|cancel |    |   |   | `AccountId` multi_account_id <br/>`Timepoint` timepoint <br/>`[u8;32]` call_hash <br/> | 

## Identity

| Name        | Light | XL | Nesting | Arguments | 
| :---------- |:------------:|:--------:|:--------:|:--------|
|add_registrar |    | :white_check_mark: |   | `AccountId` account <br/> | 
|set_identity |    |   |   | `IdentityInfo` info <br/> | 
|set_subs |    |   |   | `Vec<(AccountId,Data)>` subs <br/> | 
|clear_identity |    | :white_check_mark: |   |  | 
|request_judgement |    | :white_check_mark: |   | `Compact<RegistrarIndex>` reg_index <br/>`Compact<BalanceOf>` max_fee <br/> | 
|cancel_request |    | :white_check_mark: |   | `RegistrarIndex` reg_index <br/> | 
|set_fee |    | :white_check_mark: |   | `Compact<RegistrarIndex>` index <br/>`Compact<BalanceOf>` fee <br/> | 
|set_account_id |    | :white_check_mark: |   | `Compact<RegistrarIndex>` index <br/>`AccountId` new <br/> | 
|set_fields |    |   |   | `Compact<RegistrarIndex>` index <br/>`IdentityFields` fields <br/> | 
|provide_judgement |    |   |   | `Compact<RegistrarIndex>` reg_index <br/>`LookupSource` target <br/>`IdentityJudgement` judgement <br/> | 
|kill_identity |    | :white_check_mark: |   | `LookupSource` target <br/> | 
|add_sub |    |   |   | `LookupSource` sub <br/>`Data` data <br/> | 
|rename_sub |    |   |   | `LookupSource` sub <br/>`Data` data <br/> | 
|remove_sub |    | :white_check_mark: |   | `LookupSource` sub <br/> | 
|quit_sub |    | :white_check_mark: |   |  | 

## PalletBridge

| Name        | Light | XL | Nesting | Arguments | 
| :---------- |:------------:|:--------:|:--------:|:--------|
|transfer_native |    |   |   | `BalanceOf` amount <br/>`Bytes` recipient <br/>`ChainId` dest_id <br/> | 
|transfer_asset |    |   |   | `Bytes` recipient <br/>`RegistryId` from_registry <br/>`TokenId` token_id <br/>`ChainId` dest_id <br/> | 
|transfer |    |   |   | `AccountId` to <br/>`BalanceOf` amount <br/>`ResourceId` r_id <br/> | 
|receive_nonfungible |    |   |   | `AccountId` to <br/>`TokenId` token_id <br/>`Bytes` _metadata <br/>`ResourceId` resource_id <br/> | 
|remark |    |   |   | `Hash` hash <br/>`ResourceId` r_id <br/> | 
|set_token_transfer_fee |    | :white_check_mark: |   | `Balance` fee <br/> | 

## ChainBridge

| Name        | Light | XL | Nesting | Arguments | 
| :---------- |:------------:|:--------:|:--------:|:--------|
|set_threshold |    |   |   | `u32` threshold <br/> | 
|set_resource |    |   |   | `ResourceId` id <br/>`Bytes` method <br/> | 
|remove_resource |    |   |   | `ResourceId` id <br/> | 
|whitelist_chain |    |   |   | `ChainId` id <br/> | 
|add_relayer |    |   |   | `AccountId` v <br/> | 
|remove_relayer |    |   |   | `AccountId` v <br/> | 
|acknowledge_proposal |    |   |   | `DepositNonce` nonce <br/>`ChainId` src_id <br/>`ResourceId` r_id <br/>`Proposal` call <br/> | 
|reject_proposal |    |   |   | `DepositNonce` nonce <br/>`ChainId` src_id <br/>`ResourceId` r_id <br/>`Proposal` call <br/> | 
|eval_vote_state |    |   |   | `DepositNonce` nonce <br/>`ChainId` src_id <br/>`Proposal` prop <br/> | 

## Indices

| Name        | Light | XL | Nesting | Arguments | 
| :---------- |:------------:|:--------:|:--------:|:--------|
|claim |    | :white_check_mark: |   | `AccountIndex` index <br/> | 
|transfer |    | :white_check_mark: |   | `AccountId` new <br/>`AccountIndex` index <br/> | 
|free |    | :white_check_mark: |   | `AccountIndex` index <br/> | 
|force_transfer |    | :white_check_mark: |   | `AccountId` new <br/>`AccountIndex` index <br/>`bool` freeze <br/> | 
|freeze |    | :white_check_mark: |   | `AccountIndex` index <br/> | 

## Historical

Empty

## Scheduler

| Name        | Light | XL | Nesting | Arguments | 
| :---------- |:------------:|:--------:|:--------:|:--------|
|schedule |    |   |   | `BlockNumber` when <br/>`Option<Period>` maybe_periodic <br/>`Priority` priority <br/>`Call` call <br/> | 
|cancel |    |   |   | `BlockNumber` when <br/>`u32` index <br/> | 
|schedule_named |    |   |   | `Bytes` id <br/>`BlockNumber` when <br/>`Option<Period>` maybe_periodic <br/>`Priority` priority <br/>`Call` call <br/> | 
|cancel_named |    |   |   | `Bytes` id <br/> | 
|schedule_after |    |   |   | `BlockNumber` after <br/>`Option<Period>` maybe_periodic <br/>`Priority` priority <br/>`Call` call <br/> | 
|schedule_named_after |    |   |   | `Bytes` id <br/>`BlockNumber` after <br/>`Option<Period>` maybe_periodic <br/>`Priority` priority <br/>`Call` call <br/> | 

## Proxy

| Name        | Light | XL | Nesting | Arguments | 
| :---------- |:------------:|:--------:|:--------:|:--------|
|proxy |    |   |   | `AccountId` real <br/>`Option<ProxyType>` force_proxy_type <br/>`Call` call <br/> | 
|add_proxy |    |   |   | `AccountId` proxy <br/>`ProxyType` proxy_type <br/> | 
|remove_proxy |    |   |   | `AccountId` proxy <br/>`ProxyType` proxy_type <br/> | 
|remove_proxies |    |   |   |  | 
|anonymous |    |   |   | `ProxyType` proxy_type <br/>`u16` index <br/> | 
|kill_anonymous |    |   |   | `AccountId` spawner <br/>`ProxyType` proxy_type <br/>`u16` index <br/>`Compact<BlockNumber>` height <br/>`Compact<u32>` ext_index <br/> | 

## Multisig

| Name        | Light | XL | Nesting | Arguments | 
| :---------- |:------------:|:--------:|:--------:|:--------|
|as_multi_threshold_1 |    |   |   | `Vec<AccountId>` other_signatories <br/>`Call` call <br/> | 
|as_multi |    |   |   | `u16` threshold <br/>`Vec<AccountId>` other_signatories <br/>`Option<Timepoint>` maybe_timepoint <br/>`OpaqueCall` call <br/>`bool` store_call <br/>`Weight` max_weight <br/> | 
|approve_as_multi |    |   |   | `u16` threshold <br/>`Vec<AccountId>` other_signatories <br/>`Option<Timepoint>` maybe_timepoint <br/>`[u8;32]` call_hash <br/>`Weight` max_weight <br/> | 
|cancel_as_multi |    |   |   | `u16` threshold <br/>`Vec<AccountId>` other_signatories <br/>`Timepoint` timepoint <br/>`[u8;32]` call_hash <br/> | 

## RadClaims

| Name        | Light | XL | Nesting | Arguments | 
| :---------- |:------------:|:--------:|:--------:|:--------|
|claim |    |   |   | `AccountId` account_id <br/>`Balance` amount <br/>`Vec<Hash>` sorted_hashes <br/> | 
|set_upload_account |    | :white_check_mark: |   | `AccountId` account_id <br/> | 
|store_root_hash |    | :white_check_mark: |   | `Hash` root_hash <br/> | 

## Vesting

| Name        | Light | XL | Nesting | Arguments | 
| :---------- |:------------:|:--------:|:--------:|:--------|
|vest |    | :white_check_mark: |   |  | 
|vest_other |    | :white_check_mark: |   | `LookupSource` target <br/> | 
|vested_transfer |    | :white_check_mark: |   | `LookupSource` target <br/>`VestingInfo` schedule <br/> | 
|force_vested_transfer |    | :white_check_mark: |   | `LookupSource` source <br/>`LookupSource` target <br/>`VestingInfo` schedule <br/> | 

## Registry

| Name        | Light | XL | Nesting | Arguments | 
| :---------- |:------------:|:--------:|:--------:|:--------|
|create_registry |    |   |   | `RegistryInfo` info <br/> | 
|mint |    |   |   | `AccountId` owner_account <br/>`RegistryId` registry_id <br/>`TokenId` token_id <br/>`AssetInfo` asset_info <br/>`MintInfo` mint_info <br/> | 

## Nft

| Name        | Light | XL | Nesting | Arguments | 
| :---------- |:------------:|:--------:|:--------:|:--------|
|transfer |    |   |   | `AccountId` dest_account <br/>`RegistryId` registry_id <br/>`TokenId` token_id <br/> | 

## BridgeMapping

| Name        | Light | XL | Nesting | Arguments | 
| :---------- |:------------:|:--------:|:--------:|:--------|
|set |    |   |   | `ResourceId` rid <br/>`Address` local_addr <br/> | 
|remove |    |   |   | `ResourceId` rid <br/> | 

