/*******************************************************************************
*  (c) 2019 Zondax GmbH
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
********************************************************************************/
#include "substrate_dispatch_V1.h"

#include "zxmacros.h"
#include <stdint.h>

__Z_INLINE parser_error_t _readMethod_system_fill_block_V1(
    parser_context_t* c, pd_system_fill_block_V1_t* m)
{
    CHECK_ERROR(_readPerbill_V1(c, &m->_ratio))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_system_remark_V1(
    parser_context_t* c, pd_system_remark_V1_t* m)
{
    CHECK_ERROR(_readBytes(c, &m->_remark))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_system_set_heap_pages_V1(
    parser_context_t* c, pd_system_set_heap_pages_V1_t* m)
{
    CHECK_ERROR(_readu64(c, &m->pages))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_system_set_code_V1(
    parser_context_t* c, pd_system_set_code_V1_t* m)
{
    CHECK_ERROR(_readBytes(c, &m->code))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_system_set_code_without_checks_V1(
    parser_context_t* c, pd_system_set_code_without_checks_V1_t* m)
{
    CHECK_ERROR(_readBytes(c, &m->code))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_system_set_changes_trie_config_V1(
    parser_context_t* c, pd_system_set_changes_trie_config_V1_t* m)
{
    CHECK_ERROR(_readOptionChangesTrieConfiguration_V1(c, &m->changes_trie_config))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_system_set_storage_V1(
    parser_context_t* c, pd_system_set_storage_V1_t* m)
{
    CHECK_ERROR(_readVecKeyValue_V1(c, &m->items))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_system_kill_storage_V1(
    parser_context_t* c, pd_system_kill_storage_V1_t* m)
{
    CHECK_ERROR(_readVecKey_V1(c, &m->keys))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_system_kill_prefix_V1(
    parser_context_t* c, pd_system_kill_prefix_V1_t* m)
{
    CHECK_ERROR(_readKey_V1(c, &m->prefix))
    CHECK_ERROR(_readu32(c, &m->_subkeys))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_system_suicide_V1(
    parser_context_t* c, pd_system_suicide_V1_t* m)
{
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_utility_batch_V1(
    parser_context_t* c, pd_utility_batch_V1_t* m)
{
    CHECK_ERROR(_readVecCall(c, &m->calls))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_utility_as_derivative_V1(
    parser_context_t* c, pd_utility_as_derivative_V1_t* m)
{
    CHECK_ERROR(_readu16(c, &m->index))
    CHECK_ERROR(_readCall(c, &m->call))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_babe_report_equivocation_V1(
    parser_context_t* c, pd_babe_report_equivocation_V1_t* m)
{
    CHECK_ERROR(_readEquivocationProof_V1(c, &m->equivocation_proof))
    CHECK_ERROR(_readKeyOwnerProof_V1(c, &m->key_owner_proof))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_babe_report_equivocation_unsigned_V1(
    parser_context_t* c, pd_babe_report_equivocation_unsigned_V1_t* m)
{
    CHECK_ERROR(_readEquivocationProof_V1(c, &m->equivocation_proof))
    CHECK_ERROR(_readKeyOwnerProof_V1(c, &m->key_owner_proof))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_timestamp_set_V1(
    parser_context_t* c, pd_timestamp_set_V1_t* m)
{
    CHECK_ERROR(_readCompactMoment_V1(c, &m->now))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_authorship_set_uncles_V1(
    parser_context_t* c, pd_authorship_set_uncles_V1_t* m)
{
    CHECK_ERROR(_readVecHeader(c, &m->new_uncles))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_balances_transfer_V1(
    parser_context_t* c, pd_balances_transfer_V1_t* m)
{
    CHECK_ERROR(_readLookupSource_V1(c, &m->dest))
    CHECK_ERROR(_readCompactBalance(c, &m->value))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_balances_set_balance_V1(
    parser_context_t* c, pd_balances_set_balance_V1_t* m)
{
    CHECK_ERROR(_readLookupSource_V1(c, &m->who))
    CHECK_ERROR(_readCompactBalance(c, &m->new_free))
    CHECK_ERROR(_readCompactBalance(c, &m->new_reserved))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_balances_force_transfer_V1(
    parser_context_t* c, pd_balances_force_transfer_V1_t* m)
{
    CHECK_ERROR(_readLookupSource_V1(c, &m->source))
    CHECK_ERROR(_readLookupSource_V1(c, &m->dest))
    CHECK_ERROR(_readCompactBalance(c, &m->value))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_balances_transfer_keep_alive_V1(
    parser_context_t* c, pd_balances_transfer_keep_alive_V1_t* m)
{
    CHECK_ERROR(_readLookupSource_V1(c, &m->dest))
    CHECK_ERROR(_readCompactBalance(c, &m->value))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_bond_V1(
    parser_context_t* c, pd_staking_bond_V1_t* m)
{
    CHECK_ERROR(_readLookupSource_V1(c, &m->controller))
    CHECK_ERROR(_readCompactBalanceOf(c, &m->value))
    CHECK_ERROR(_readRewardDestination_V1(c, &m->payee))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_bond_extra_V1(
    parser_context_t* c, pd_staking_bond_extra_V1_t* m)
{
    CHECK_ERROR(_readCompactBalanceOf(c, &m->max_additional))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_unbond_V1(
    parser_context_t* c, pd_staking_unbond_V1_t* m)
{
    CHECK_ERROR(_readCompactBalanceOf(c, &m->value))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_withdraw_unbonded_V1(
    parser_context_t* c, pd_staking_withdraw_unbonded_V1_t* m)
{
    CHECK_ERROR(_readu32(c, &m->num_slashing_spans))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_validate_V1(
    parser_context_t* c, pd_staking_validate_V1_t* m)
{
    CHECK_ERROR(_readValidatorPrefs_V1(c, &m->prefs))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_nominate_V1(
    parser_context_t* c, pd_staking_nominate_V1_t* m)
{
    CHECK_ERROR(_readVecLookupSource_V1(c, &m->targets))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_chill_V1(
    parser_context_t* c, pd_staking_chill_V1_t* m)
{
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_set_payee_V1(
    parser_context_t* c, pd_staking_set_payee_V1_t* m)
{
    CHECK_ERROR(_readRewardDestination_V1(c, &m->payee))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_set_controller_V1(
    parser_context_t* c, pd_staking_set_controller_V1_t* m)
{
    CHECK_ERROR(_readLookupSource_V1(c, &m->controller))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_set_validator_count_V1(
    parser_context_t* c, pd_staking_set_validator_count_V1_t* m)
{
    CHECK_ERROR(_readCompactu32(c, &m->new_))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_increase_validator_count_V1(
    parser_context_t* c, pd_staking_increase_validator_count_V1_t* m)
{
    CHECK_ERROR(_readCompactu32(c, &m->additional))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_scale_validator_count_V1(
    parser_context_t* c, pd_staking_scale_validator_count_V1_t* m)
{
    CHECK_ERROR(_readPercent_V1(c, &m->factor))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_force_no_eras_V1(
    parser_context_t* c, pd_staking_force_no_eras_V1_t* m)
{
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_force_new_era_V1(
    parser_context_t* c, pd_staking_force_new_era_V1_t* m)
{
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_set_invulnerables_V1(
    parser_context_t* c, pd_staking_set_invulnerables_V1_t* m)
{
    CHECK_ERROR(_readVecAccountId_V1(c, &m->validators))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_force_unstake_V1(
    parser_context_t* c, pd_staking_force_unstake_V1_t* m)
{
    CHECK_ERROR(_readAccountId_V1(c, &m->stash))
    CHECK_ERROR(_readu32(c, &m->num_slashing_spans))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_force_new_era_always_V1(
    parser_context_t* c, pd_staking_force_new_era_always_V1_t* m)
{
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_cancel_deferred_slash_V1(
    parser_context_t* c, pd_staking_cancel_deferred_slash_V1_t* m)
{
    CHECK_ERROR(_readEraIndex_V1(c, &m->era))
    CHECK_ERROR(_readVecu32(c, &m->slash_indices))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_payout_stakers_V1(
    parser_context_t* c, pd_staking_payout_stakers_V1_t* m)
{
    CHECK_ERROR(_readAccountId_V1(c, &m->validator_stash))
    CHECK_ERROR(_readEraIndex_V1(c, &m->era))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_rebond_V1(
    parser_context_t* c, pd_staking_rebond_V1_t* m)
{
    CHECK_ERROR(_readCompactBalanceOf(c, &m->value))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_set_history_depth_V1(
    parser_context_t* c, pd_staking_set_history_depth_V1_t* m)
{
    CHECK_ERROR(_readCompactEraIndex_V1(c, &m->new_history_depth))
    CHECK_ERROR(_readCompactu32(c, &m->_era_items_deleted))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_reap_stash_V1(
    parser_context_t* c, pd_staking_reap_stash_V1_t* m)
{
    CHECK_ERROR(_readAccountId_V1(c, &m->stash))
    CHECK_ERROR(_readu32(c, &m->num_slashing_spans))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_submit_election_solution_V1(
    parser_context_t* c, pd_staking_submit_election_solution_V1_t* m)
{
    CHECK_ERROR(_readVecValidatorIndex_V1(c, &m->winners))
    CHECK_ERROR(_readCompactAssignments_V1(c, &m->compact))
    CHECK_ERROR(_readElectionScore_V1(c, &m->score))
    CHECK_ERROR(_readEraIndex_V1(c, &m->era))
    CHECK_ERROR(_readElectionSize_V1(c, &m->size))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_submit_election_solution_unsigned_V1(
    parser_context_t* c, pd_staking_submit_election_solution_unsigned_V1_t* m)
{
    CHECK_ERROR(_readVecValidatorIndex_V1(c, &m->winners))
    CHECK_ERROR(_readCompactAssignments_V1(c, &m->compact))
    CHECK_ERROR(_readElectionScore_V1(c, &m->score))
    CHECK_ERROR(_readEraIndex_V1(c, &m->era))
    CHECK_ERROR(_readElectionSize_V1(c, &m->size))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_session_set_keys_V1(
    parser_context_t* c, pd_session_set_keys_V1_t* m)
{
    CHECK_ERROR(_readKeys_V1(c, &m->keys))
    CHECK_ERROR(_readBytes(c, &m->proof))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_session_purge_keys_V1(
    parser_context_t* c, pd_session_purge_keys_V1_t* m)
{
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_democracy_propose_V1(
    parser_context_t* c, pd_democracy_propose_V1_t* m)
{
    CHECK_ERROR(_readHash(c, &m->proposal_hash))
    CHECK_ERROR(_readCompactBalanceOf(c, &m->value))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_democracy_second_V1(
    parser_context_t* c, pd_democracy_second_V1_t* m)
{
    CHECK_ERROR(_readCompactPropIndex_V1(c, &m->proposal))
    CHECK_ERROR(_readCompactu32(c, &m->seconds_upper_bound))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_democracy_vote_V1(
    parser_context_t* c, pd_democracy_vote_V1_t* m)
{
    CHECK_ERROR(_readCompactReferendumIndex_V1(c, &m->ref_index))
    CHECK_ERROR(_readAccountVote_V1(c, &m->vote))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_democracy_emergency_cancel_V1(
    parser_context_t* c, pd_democracy_emergency_cancel_V1_t* m)
{
    CHECK_ERROR(_readReferendumIndex_V1(c, &m->ref_index))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_democracy_external_propose_V1(
    parser_context_t* c, pd_democracy_external_propose_V1_t* m)
{
    CHECK_ERROR(_readHash(c, &m->proposal_hash))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_democracy_external_propose_majority_V1(
    parser_context_t* c, pd_democracy_external_propose_majority_V1_t* m)
{
    CHECK_ERROR(_readHash(c, &m->proposal_hash))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_democracy_external_propose_default_V1(
    parser_context_t* c, pd_democracy_external_propose_default_V1_t* m)
{
    CHECK_ERROR(_readHash(c, &m->proposal_hash))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_democracy_fast_track_V1(
    parser_context_t* c, pd_democracy_fast_track_V1_t* m)
{
    CHECK_ERROR(_readHash(c, &m->proposal_hash))
    CHECK_ERROR(_readBlockNumber(c, &m->voting_period))
    CHECK_ERROR(_readBlockNumber(c, &m->delay))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_democracy_veto_external_V1(
    parser_context_t* c, pd_democracy_veto_external_V1_t* m)
{
    CHECK_ERROR(_readHash(c, &m->proposal_hash))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_democracy_cancel_referendum_V1(
    parser_context_t* c, pd_democracy_cancel_referendum_V1_t* m)
{
    CHECK_ERROR(_readCompactReferendumIndex_V1(c, &m->ref_index))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_democracy_cancel_queued_V1(
    parser_context_t* c, pd_democracy_cancel_queued_V1_t* m)
{
    CHECK_ERROR(_readReferendumIndex_V1(c, &m->which))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_democracy_delegate_V1(
    parser_context_t* c, pd_democracy_delegate_V1_t* m)
{
    CHECK_ERROR(_readAccountId_V1(c, &m->to))
    CHECK_ERROR(_readConviction_V1(c, &m->conviction))
    CHECK_ERROR(_readBalanceOf(c, &m->balance))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_democracy_undelegate_V1(
    parser_context_t* c, pd_democracy_undelegate_V1_t* m)
{
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_democracy_clear_public_proposals_V1(
    parser_context_t* c, pd_democracy_clear_public_proposals_V1_t* m)
{
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_democracy_note_preimage_V1(
    parser_context_t* c, pd_democracy_note_preimage_V1_t* m)
{
    CHECK_ERROR(_readBytes(c, &m->encoded_proposal))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_democracy_note_preimage_operational_V1(
    parser_context_t* c, pd_democracy_note_preimage_operational_V1_t* m)
{
    CHECK_ERROR(_readBytes(c, &m->encoded_proposal))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_democracy_note_imminent_preimage_V1(
    parser_context_t* c, pd_democracy_note_imminent_preimage_V1_t* m)
{
    CHECK_ERROR(_readBytes(c, &m->encoded_proposal))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_democracy_note_imminent_preimage_operational_V1(
    parser_context_t* c, pd_democracy_note_imminent_preimage_operational_V1_t* m)
{
    CHECK_ERROR(_readBytes(c, &m->encoded_proposal))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_democracy_reap_preimage_V1(
    parser_context_t* c, pd_democracy_reap_preimage_V1_t* m)
{
    CHECK_ERROR(_readHash(c, &m->proposal_hash))
    CHECK_ERROR(_readCompactu32(c, &m->proposal_len_upper_bound))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_democracy_unlock_V1(
    parser_context_t* c, pd_democracy_unlock_V1_t* m)
{
    CHECK_ERROR(_readAccountId_V1(c, &m->target))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_democracy_remove_vote_V1(
    parser_context_t* c, pd_democracy_remove_vote_V1_t* m)
{
    CHECK_ERROR(_readReferendumIndex_V1(c, &m->index))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_democracy_remove_other_vote_V1(
    parser_context_t* c, pd_democracy_remove_other_vote_V1_t* m)
{
    CHECK_ERROR(_readAccountId_V1(c, &m->target))
    CHECK_ERROR(_readReferendumIndex_V1(c, &m->index))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_democracy_enact_proposal_V1(
    parser_context_t* c, pd_democracy_enact_proposal_V1_t* m)
{
    CHECK_ERROR(_readHash(c, &m->proposal_hash))
    CHECK_ERROR(_readReferendumIndex_V1(c, &m->index))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_council_set_members_V1(
    parser_context_t* c, pd_council_set_members_V1_t* m)
{
    CHECK_ERROR(_readVecAccountId_V1(c, &m->new_members))
    CHECK_ERROR(_readOptionAccountId_V1(c, &m->prime))
    CHECK_ERROR(_readMemberCount_V1(c, &m->old_count))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_council_execute_V1(
    parser_context_t* c, pd_council_execute_V1_t* m)
{
    CHECK_ERROR(_readProposal(c, &m->proposal))
    CHECK_ERROR(_readCompactu32(c, &m->length_bound))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_council_propose_V1(
    parser_context_t* c, pd_council_propose_V1_t* m)
{
    CHECK_ERROR(_readCompactMemberCount_V1(c, &m->threshold))
    CHECK_ERROR(_readProposal(c, &m->proposal))
    CHECK_ERROR(_readCompactu32(c, &m->length_bound))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_council_vote_V1(
    parser_context_t* c, pd_council_vote_V1_t* m)
{
    CHECK_ERROR(_readHash(c, &m->proposal))
    CHECK_ERROR(_readCompactProposalIndex_V1(c, &m->index))
    CHECK_ERROR(_readbool(c, &m->approve))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_council_close_V1(
    parser_context_t* c, pd_council_close_V1_t* m)
{
    CHECK_ERROR(_readHash(c, &m->proposal_hash))
    CHECK_ERROR(_readCompactProposalIndex_V1(c, &m->index))
    CHECK_ERROR(_readCompactWeight_V1(c, &m->proposal_weight_bound))
    CHECK_ERROR(_readCompactu32(c, &m->length_bound))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_council_disapprove_proposal_V1(
    parser_context_t* c, pd_council_disapprove_proposal_V1_t* m)
{
    CHECK_ERROR(_readHash(c, &m->proposal_hash))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_elections_vote_V1(
    parser_context_t* c, pd_elections_vote_V1_t* m)
{
    CHECK_ERROR(_readVecAccountId_V1(c, &m->votes))
    CHECK_ERROR(_readCompactBalanceOf(c, &m->value))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_elections_remove_voter_V1(
    parser_context_t* c, pd_elections_remove_voter_V1_t* m)
{
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_elections_report_defunct_voter_V1(
    parser_context_t* c, pd_elections_report_defunct_voter_V1_t* m)
{
    CHECK_ERROR(_readDefunctVoter_V1(c, &m->defunct))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_elections_submit_candidacy_V1(
    parser_context_t* c, pd_elections_submit_candidacy_V1_t* m)
{
    CHECK_ERROR(_readCompactu32(c, &m->candidate_count))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_elections_renounce_candidacy_V1(
    parser_context_t* c, pd_elections_renounce_candidacy_V1_t* m)
{
    CHECK_ERROR(_readRenouncing_V1(c, &m->renouncing))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_elections_remove_member_V1(
    parser_context_t* c, pd_elections_remove_member_V1_t* m)
{
    CHECK_ERROR(_readLookupSource_V1(c, &m->who))
    CHECK_ERROR(_readbool(c, &m->has_replacement))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_finalitytracker_final_hint_V1(
    parser_context_t* c, pd_finalitytracker_final_hint_V1_t* m)
{
    CHECK_ERROR(_readCompactBlockNumber(c, &m->hint))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_grandpa_report_equivocation_V1(
    parser_context_t* c, pd_grandpa_report_equivocation_V1_t* m)
{
    CHECK_ERROR(_readEquivocationProof_V1(c, &m->equivocation_proof))
    CHECK_ERROR(_readKeyOwnerProof_V1(c, &m->key_owner_proof))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_grandpa_report_equivocation_unsigned_V1(
    parser_context_t* c, pd_grandpa_report_equivocation_unsigned_V1_t* m)
{
    CHECK_ERROR(_readEquivocationProof_V1(c, &m->equivocation_proof))
    CHECK_ERROR(_readKeyOwnerProof_V1(c, &m->key_owner_proof))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_grandpa_note_stalled_V1(
    parser_context_t* c, pd_grandpa_note_stalled_V1_t* m)
{
    CHECK_ERROR(_readBlockNumber(c, &m->delay))
    CHECK_ERROR(_readBlockNumber(c, &m->best_finalized_block_number))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_imonline_heartbeat_V1(
    parser_context_t* c, pd_imonline_heartbeat_V1_t* m)
{
    CHECK_ERROR(_readHeartbeat(c, &m->heartbeat))
    CHECK_ERROR(_readSignature_V1(c, &m->_signature))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_anchor_pre_commit_V1(
    parser_context_t* c, pd_anchor_pre_commit_V1_t* m)
{
    CHECK_ERROR(_readHash(c, &m->anchor_id))
    CHECK_ERROR(_readHash(c, &m->signing_root))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_anchor_commit_V1(
    parser_context_t* c, pd_anchor_commit_V1_t* m)
{
    CHECK_ERROR(_readHash(c, &m->anchor_id_preimage))
    CHECK_ERROR(_readHash(c, &m->doc_root))
    CHECK_ERROR(_readHash(c, &m->proof))
    CHECK_ERROR(_readMoment_V1(c, &m->stored_until_date))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_anchor_evict_pre_commits_V1(
    parser_context_t* c, pd_anchor_evict_pre_commits_V1_t* m)
{
    CHECK_ERROR(_readBlockNumber(c, &m->evict_bucket))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_anchor_evict_anchors_V1(
    parser_context_t* c, pd_anchor_evict_anchors_V1_t* m)
{
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_fees_set_fee_V1(
    parser_context_t* c, pd_fees_set_fee_V1_t* m)
{
    CHECK_ERROR(_readHash(c, &m->key))
    CHECK_ERROR(_readBalance(c, &m->new_price))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_nfts_validate_mint_V1(
    parser_context_t* c, pd_nfts_validate_mint_V1_t* m)
{
    CHECK_ERROR(_readHash(c, &m->anchor_id))
    CHECK_ERROR(_readu8_array_20(c, &m->deposit_address))
    CHECK_ERROR(_readVecProof_V1(c, &m->pfs))
    CHECK_ERROR(_readH256_array_3_V1(c, &m->static_proofs))
    CHECK_ERROR(_readChainId_V1(c, &m->dest_id))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_multiaccount_create_V1(
    parser_context_t* c, pd_multiaccount_create_V1_t* m)
{
    CHECK_ERROR(_readu16(c, &m->threshold))
    CHECK_ERROR(_readVecAccountId_V1(c, &m->other_signatories))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_multiaccount_update_V1(
    parser_context_t* c, pd_multiaccount_update_V1_t* m)
{
    CHECK_ERROR(_readu16(c, &m->threshold))
    CHECK_ERROR(_readVecAccountId_V1(c, &m->signatories))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_multiaccount_remove_V1(
    parser_context_t* c, pd_multiaccount_remove_V1_t* m)
{
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_multiaccount_call_V1(
    parser_context_t* c, pd_multiaccount_call_V1_t* m)
{
    CHECK_ERROR(_readAccountId_V1(c, &m->multi_account_id))
    CHECK_ERROR(_readOptionTimepoint_V1(c, &m->maybe_timepoint))
    CHECK_ERROR(_readCall(c, &m->call))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_multiaccount_approve_V1(
    parser_context_t* c, pd_multiaccount_approve_V1_t* m)
{
    CHECK_ERROR(_readAccountId_V1(c, &m->multi_account_id))
    CHECK_ERROR(_readOptionTimepoint_V1(c, &m->maybe_timepoint))
    CHECK_ERROR(_readu8_array_32_V1(c, &m->call_hash))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_multiaccount_cancel_V1(
    parser_context_t* c, pd_multiaccount_cancel_V1_t* m)
{
    CHECK_ERROR(_readAccountId_V1(c, &m->multi_account_id))
    CHECK_ERROR(_readTimepoint_V1(c, &m->timepoint))
    CHECK_ERROR(_readu8_array_32_V1(c, &m->call_hash))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_identity_add_registrar_V1(
    parser_context_t* c, pd_identity_add_registrar_V1_t* m)
{
    CHECK_ERROR(_readAccountId_V1(c, &m->account))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_identity_set_identity_V1(
    parser_context_t* c, pd_identity_set_identity_V1_t* m)
{
    CHECK_ERROR(_readIdentityInfo_V1(c, &m->info))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_identity_set_subs_V1(
    parser_context_t* c, pd_identity_set_subs_V1_t* m)
{
    CHECK_ERROR(_readVecTupleAccountIdData_V1(c, &m->subs))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_identity_clear_identity_V1(
    parser_context_t* c, pd_identity_clear_identity_V1_t* m)
{
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_identity_request_judgement_V1(
    parser_context_t* c, pd_identity_request_judgement_V1_t* m)
{
    CHECK_ERROR(_readCompactRegistrarIndex_V1(c, &m->reg_index))
    CHECK_ERROR(_readCompactBalanceOf(c, &m->max_fee))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_identity_cancel_request_V1(
    parser_context_t* c, pd_identity_cancel_request_V1_t* m)
{
    CHECK_ERROR(_readRegistrarIndex_V1(c, &m->reg_index))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_identity_set_fee_V1(
    parser_context_t* c, pd_identity_set_fee_V1_t* m)
{
    CHECK_ERROR(_readCompactRegistrarIndex_V1(c, &m->index))
    CHECK_ERROR(_readCompactBalanceOf(c, &m->fee))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_identity_set_account_id_V1(
    parser_context_t* c, pd_identity_set_account_id_V1_t* m)
{
    CHECK_ERROR(_readCompactRegistrarIndex_V1(c, &m->index))
    CHECK_ERROR(_readAccountId_V1(c, &m->new_))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_identity_set_fields_V1(
    parser_context_t* c, pd_identity_set_fields_V1_t* m)
{
    CHECK_ERROR(_readCompactRegistrarIndex_V1(c, &m->index))
    CHECK_ERROR(_readIdentityFields_V1(c, &m->fields))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_identity_provide_judgement_V1(
    parser_context_t* c, pd_identity_provide_judgement_V1_t* m)
{
    CHECK_ERROR(_readCompactRegistrarIndex_V1(c, &m->reg_index))
    CHECK_ERROR(_readLookupSource_V1(c, &m->target))
    CHECK_ERROR(_readJudgement_V1(c, &m->judgement))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_identity_kill_identity_V1(
    parser_context_t* c, pd_identity_kill_identity_V1_t* m)
{
    CHECK_ERROR(_readLookupSource_V1(c, &m->target))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_identity_add_sub_V1(
    parser_context_t* c, pd_identity_add_sub_V1_t* m)
{
    CHECK_ERROR(_readLookupSource_V1(c, &m->sub))
    CHECK_ERROR(_readData(c, &m->data))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_identity_rename_sub_V1(
    parser_context_t* c, pd_identity_rename_sub_V1_t* m)
{
    CHECK_ERROR(_readLookupSource_V1(c, &m->sub))
    CHECK_ERROR(_readData(c, &m->data))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_identity_remove_sub_V1(
    parser_context_t* c, pd_identity_remove_sub_V1_t* m)
{
    CHECK_ERROR(_readLookupSource_V1(c, &m->sub))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_identity_quit_sub_V1(
    parser_context_t* c, pd_identity_quit_sub_V1_t* m)
{
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_palletbridge_transfer_native_V1(
    parser_context_t* c, pd_palletbridge_transfer_native_V1_t* m)
{
    CHECK_ERROR(_readBalanceOf(c, &m->amount))
    CHECK_ERROR(_readBytes(c, &m->recipient))
    CHECK_ERROR(_readChainId_V1(c, &m->dest_id))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_palletbridge_transfer_asset_V1(
    parser_context_t* c, pd_palletbridge_transfer_asset_V1_t* m)
{
    CHECK_ERROR(_readBytes(c, &m->recipient))
    CHECK_ERROR(_readRegistryId_V1(c, &m->from_registry))
    CHECK_ERROR(_readTokenId_V1(c, &m->token_id))
    CHECK_ERROR(_readChainId_V1(c, &m->dest_id))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_palletbridge_transfer_V1(
    parser_context_t* c, pd_palletbridge_transfer_V1_t* m)
{
    CHECK_ERROR(_readAccountId_V1(c, &m->to))
    CHECK_ERROR(_readBalanceOf(c, &m->amount))
    CHECK_ERROR(_readResourceId_V1(c, &m->r_id))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_palletbridge_receive_nonfungible_V1(
    parser_context_t* c, pd_palletbridge_receive_nonfungible_V1_t* m)
{
    CHECK_ERROR(_readAccountId_V1(c, &m->to))
    CHECK_ERROR(_readTokenId_V1(c, &m->token_id))
    CHECK_ERROR(_readBytes(c, &m->_metadata))
    CHECK_ERROR(_readResourceId_V1(c, &m->resource_id))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_palletbridge_remark_V1(
    parser_context_t* c, pd_palletbridge_remark_V1_t* m)
{
    CHECK_ERROR(_readHash(c, &m->hash))
    CHECK_ERROR(_readResourceId_V1(c, &m->r_id))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_chainbridge_set_threshold_V1(
    parser_context_t* c, pd_chainbridge_set_threshold_V1_t* m)
{
    CHECK_ERROR(_readu32(c, &m->threshold))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_chainbridge_set_resource_V1(
    parser_context_t* c, pd_chainbridge_set_resource_V1_t* m)
{
    CHECK_ERROR(_readResourceId_V1(c, &m->id))
    CHECK_ERROR(_readBytes(c, &m->method))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_chainbridge_remove_resource_V1(
    parser_context_t* c, pd_chainbridge_remove_resource_V1_t* m)
{
    CHECK_ERROR(_readResourceId_V1(c, &m->id))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_chainbridge_whitelist_chain_V1(
    parser_context_t* c, pd_chainbridge_whitelist_chain_V1_t* m)
{
    CHECK_ERROR(_readChainId_V1(c, &m->id))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_chainbridge_add_relayer_V1(
    parser_context_t* c, pd_chainbridge_add_relayer_V1_t* m)
{
    CHECK_ERROR(_readAccountId_V1(c, &m->v))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_chainbridge_remove_relayer_V1(
    parser_context_t* c, pd_chainbridge_remove_relayer_V1_t* m)
{
    CHECK_ERROR(_readAccountId_V1(c, &m->v))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_chainbridge_acknowledge_proposal_V1(
    parser_context_t* c, pd_chainbridge_acknowledge_proposal_V1_t* m)
{
    CHECK_ERROR(_readDepositNonce_V1(c, &m->nonce))
    CHECK_ERROR(_readChainId_V1(c, &m->src_id))
    CHECK_ERROR(_readResourceId_V1(c, &m->r_id))
    CHECK_ERROR(_readProposal(c, &m->call))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_chainbridge_reject_proposal_V1(
    parser_context_t* c, pd_chainbridge_reject_proposal_V1_t* m)
{
    CHECK_ERROR(_readDepositNonce_V1(c, &m->nonce))
    CHECK_ERROR(_readChainId_V1(c, &m->src_id))
    CHECK_ERROR(_readResourceId_V1(c, &m->r_id))
    CHECK_ERROR(_readProposal(c, &m->call))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_chainbridge_eval_vote_state_V1(
    parser_context_t* c, pd_chainbridge_eval_vote_state_V1_t* m)
{
    CHECK_ERROR(_readDepositNonce_V1(c, &m->nonce))
    CHECK_ERROR(_readChainId_V1(c, &m->src_id))
    CHECK_ERROR(_readProposal(c, &m->prop))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_indices_claim_V1(
    parser_context_t* c, pd_indices_claim_V1_t* m)
{
    CHECK_ERROR(_readAccountIndex_V1(c, &m->index))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_indices_transfer_V1(
    parser_context_t* c, pd_indices_transfer_V1_t* m)
{
    CHECK_ERROR(_readAccountId_V1(c, &m->new_))
    CHECK_ERROR(_readAccountIndex_V1(c, &m->index))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_indices_free_V1(
    parser_context_t* c, pd_indices_free_V1_t* m)
{
    CHECK_ERROR(_readAccountIndex_V1(c, &m->index))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_indices_force_transfer_V1(
    parser_context_t* c, pd_indices_force_transfer_V1_t* m)
{
    CHECK_ERROR(_readAccountId_V1(c, &m->new_))
    CHECK_ERROR(_readAccountIndex_V1(c, &m->index))
    CHECK_ERROR(_readbool(c, &m->freeze))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_indices_freeze_V1(
    parser_context_t* c, pd_indices_freeze_V1_t* m)
{
    CHECK_ERROR(_readAccountIndex_V1(c, &m->index))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_scheduler_schedule_V1(
    parser_context_t* c, pd_scheduler_schedule_V1_t* m)
{
    CHECK_ERROR(_readBlockNumber(c, &m->when))
    CHECK_ERROR(_readOptionPeriod_V1(c, &m->maybe_periodic))
    CHECK_ERROR(_readPriority_V1(c, &m->priority))
    CHECK_ERROR(_readCall(c, &m->call))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_scheduler_cancel_V1(
    parser_context_t* c, pd_scheduler_cancel_V1_t* m)
{
    CHECK_ERROR(_readBlockNumber(c, &m->when))
    CHECK_ERROR(_readu32(c, &m->index))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_scheduler_schedule_named_V1(
    parser_context_t* c, pd_scheduler_schedule_named_V1_t* m)
{
    CHECK_ERROR(_readBytes(c, &m->id))
    CHECK_ERROR(_readBlockNumber(c, &m->when))
    CHECK_ERROR(_readOptionPeriod_V1(c, &m->maybe_periodic))
    CHECK_ERROR(_readPriority_V1(c, &m->priority))
    CHECK_ERROR(_readCall(c, &m->call))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_scheduler_cancel_named_V1(
    parser_context_t* c, pd_scheduler_cancel_named_V1_t* m)
{
    CHECK_ERROR(_readBytes(c, &m->id))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_scheduler_schedule_after_V1(
    parser_context_t* c, pd_scheduler_schedule_after_V1_t* m)
{
    CHECK_ERROR(_readBlockNumber(c, &m->after))
    CHECK_ERROR(_readOptionPeriod_V1(c, &m->maybe_periodic))
    CHECK_ERROR(_readPriority_V1(c, &m->priority))
    CHECK_ERROR(_readCall(c, &m->call))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_scheduler_schedule_named_after_V1(
    parser_context_t* c, pd_scheduler_schedule_named_after_V1_t* m)
{
    CHECK_ERROR(_readBytes(c, &m->id))
    CHECK_ERROR(_readBlockNumber(c, &m->after))
    CHECK_ERROR(_readOptionPeriod_V1(c, &m->maybe_periodic))
    CHECK_ERROR(_readPriority_V1(c, &m->priority))
    CHECK_ERROR(_readCall(c, &m->call))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_proxy_proxy_V1(
    parser_context_t* c, pd_proxy_proxy_V1_t* m)
{
    CHECK_ERROR(_readAccountId_V1(c, &m->real))
    CHECK_ERROR(_readOptionProxyType_V1(c, &m->force_proxy_type))
    CHECK_ERROR(_readCall(c, &m->call))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_proxy_add_proxy_V1(
    parser_context_t* c, pd_proxy_add_proxy_V1_t* m)
{
    CHECK_ERROR(_readAccountId_V1(c, &m->proxy))
    CHECK_ERROR(_readProxyType_V1(c, &m->proxy_type))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_proxy_remove_proxy_V1(
    parser_context_t* c, pd_proxy_remove_proxy_V1_t* m)
{
    CHECK_ERROR(_readAccountId_V1(c, &m->proxy))
    CHECK_ERROR(_readProxyType_V1(c, &m->proxy_type))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_proxy_remove_proxies_V1(
    parser_context_t* c, pd_proxy_remove_proxies_V1_t* m)
{
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_proxy_anonymous_V1(
    parser_context_t* c, pd_proxy_anonymous_V1_t* m)
{
    CHECK_ERROR(_readProxyType_V1(c, &m->proxy_type))
    CHECK_ERROR(_readu16(c, &m->index))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_proxy_kill_anonymous_V1(
    parser_context_t* c, pd_proxy_kill_anonymous_V1_t* m)
{
    CHECK_ERROR(_readAccountId_V1(c, &m->spawner))
    CHECK_ERROR(_readProxyType_V1(c, &m->proxy_type))
    CHECK_ERROR(_readu16(c, &m->index))
    CHECK_ERROR(_readCompactBlockNumber(c, &m->height))
    CHECK_ERROR(_readCompactu32(c, &m->ext_index))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_multisig_as_multi_threshold_1_V1(
    parser_context_t* c, pd_multisig_as_multi_threshold_1_V1_t* m)
{
    CHECK_ERROR(_readVecAccountId_V1(c, &m->other_signatories))
    CHECK_ERROR(_readCall(c, &m->call))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_multisig_as_multi_V1(
    parser_context_t* c, pd_multisig_as_multi_V1_t* m)
{
    CHECK_ERROR(_readu16(c, &m->threshold))
    CHECK_ERROR(_readVecAccountId_V1(c, &m->other_signatories))
    CHECK_ERROR(_readOptionTimepoint_V1(c, &m->maybe_timepoint))
    CHECK_ERROR(_readOpaqueCall_V1(c, &m->call))
    CHECK_ERROR(_readbool(c, &m->store_call))
    CHECK_ERROR(_readWeight_V1(c, &m->max_weight))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_multisig_approve_as_multi_V1(
    parser_context_t* c, pd_multisig_approve_as_multi_V1_t* m)
{
    CHECK_ERROR(_readu16(c, &m->threshold))
    CHECK_ERROR(_readVecAccountId_V1(c, &m->other_signatories))
    CHECK_ERROR(_readOptionTimepoint_V1(c, &m->maybe_timepoint))
    CHECK_ERROR(_readu8_array_32_V1(c, &m->call_hash))
    CHECK_ERROR(_readWeight_V1(c, &m->max_weight))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_multisig_cancel_as_multi_V1(
    parser_context_t* c, pd_multisig_cancel_as_multi_V1_t* m)
{
    CHECK_ERROR(_readu16(c, &m->threshold))
    CHECK_ERROR(_readVecAccountId_V1(c, &m->other_signatories))
    CHECK_ERROR(_readTimepoint_V1(c, &m->timepoint))
    CHECK_ERROR(_readu8_array_32_V1(c, &m->call_hash))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_radclaims_claim_V1(
    parser_context_t* c, pd_radclaims_claim_V1_t* m)
{
    CHECK_ERROR(_readAccountId_V1(c, &m->account_id))
    CHECK_ERROR(_readBalance(c, &m->amount))
    CHECK_ERROR(_readVecHash(c, &m->sorted_hashes))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_radclaims_set_upload_account_V1(
    parser_context_t* c, pd_radclaims_set_upload_account_V1_t* m)
{
    CHECK_ERROR(_readAccountId_V1(c, &m->account_id))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_radclaims_store_root_hash_V1(
    parser_context_t* c, pd_radclaims_store_root_hash_V1_t* m)
{
    CHECK_ERROR(_readHash(c, &m->root_hash))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_vesting_vest_V1(
    parser_context_t* c, pd_vesting_vest_V1_t* m)
{
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_vesting_vest_other_V1(
    parser_context_t* c, pd_vesting_vest_other_V1_t* m)
{
    CHECK_ERROR(_readLookupSource_V1(c, &m->target))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_vesting_vested_transfer_V1(
    parser_context_t* c, pd_vesting_vested_transfer_V1_t* m)
{
    CHECK_ERROR(_readLookupSource_V1(c, &m->target))
    CHECK_ERROR(_readVestingInfo_V1(c, &m->schedule))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_vesting_force_vested_transfer_V1(
    parser_context_t* c, pd_vesting_force_vested_transfer_V1_t* m)
{
    CHECK_ERROR(_readLookupSource_V1(c, &m->source))
    CHECK_ERROR(_readLookupSource_V1(c, &m->target))
    CHECK_ERROR(_readVestingInfo_V1(c, &m->schedule))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_registry_create_registry_V1(
    parser_context_t* c, pd_registry_create_registry_V1_t* m)
{
    CHECK_ERROR(_readRegistryInfo_V1(c, &m->info))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_registry_mint_V1(
    parser_context_t* c, pd_registry_mint_V1_t* m)
{
    CHECK_ERROR(_readAccountId_V1(c, &m->owner_account))
    CHECK_ERROR(_readRegistryId_V1(c, &m->registry_id))
    CHECK_ERROR(_readTokenId_V1(c, &m->token_id))
    CHECK_ERROR(_readAssetInfo_V1(c, &m->asset_info))
    CHECK_ERROR(_readMintInfo_V1(c, &m->mint_info))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_nft_transfer_V1(
    parser_context_t* c, pd_nft_transfer_V1_t* m)
{
    CHECK_ERROR(_readAccountId_V1(c, &m->dest_account))
    CHECK_ERROR(_readRegistryId_V1(c, &m->registry_id))
    CHECK_ERROR(_readTokenId_V1(c, &m->token_id))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_bridgemapping_set_V1(
    parser_context_t* c, pd_bridgemapping_set_V1_t* m)
{
    CHECK_ERROR(_readResourceId_V1(c, &m->rid))
    CHECK_ERROR(_readAddress_V1(c, &m->local_addr))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_bridgemapping_remove_V1(
    parser_context_t* c, pd_bridgemapping_remove_V1_t* m)
{
    CHECK_ERROR(_readResourceId_V1(c, &m->rid))
    return parser_ok;
}

parser_error_t _readMethod_V1(
    parser_context_t* c,
    uint8_t moduleIdx,
    uint8_t callIdx,
    pd_Method_V1_t* method)
{
    uint16_t callPrivIdx = ((uint16_t)moduleIdx << 8u) + callIdx;

    switch (callPrivIdx) {
    case 0: /* module 0 call 0 */
        CHECK_ERROR(_readMethod_system_fill_block_V1(c, &method->basic.system_fill_block_V1))
        break;
    case 1: /* module 0 call 1 */
        CHECK_ERROR(_readMethod_system_remark_V1(c, &method->basic.system_remark_V1))
        break;
    case 2: /* module 0 call 2 */
        CHECK_ERROR(_readMethod_system_set_heap_pages_V1(c, &method->basic.system_set_heap_pages_V1))
        break;
    case 3: /* module 0 call 3 */
        CHECK_ERROR(_readMethod_system_set_code_V1(c, &method->basic.system_set_code_V1))
        break;
    case 4: /* module 0 call 4 */
        CHECK_ERROR(_readMethod_system_set_code_without_checks_V1(c, &method->basic.system_set_code_without_checks_V1))
        break;
    case 5: /* module 0 call 5 */
        CHECK_ERROR(_readMethod_system_set_changes_trie_config_V1(c, &method->basic.system_set_changes_trie_config_V1))
        break;
    case 6: /* module 0 call 6 */
        CHECK_ERROR(_readMethod_system_set_storage_V1(c, &method->basic.system_set_storage_V1))
        break;
    case 7: /* module 0 call 7 */
        CHECK_ERROR(_readMethod_system_kill_storage_V1(c, &method->basic.system_kill_storage_V1))
        break;
    case 8: /* module 0 call 8 */
        CHECK_ERROR(_readMethod_system_kill_prefix_V1(c, &method->basic.system_kill_prefix_V1))
        break;
    case 9: /* module 0 call 9 */
        CHECK_ERROR(_readMethod_system_suicide_V1(c, &method->basic.system_suicide_V1))
        break;
    case 256: /* module 1 call 0 */
        CHECK_ERROR(_readMethod_utility_batch_V1(c, &method->basic.utility_batch_V1))
        break;
    case 257: /* module 1 call 1 */
        CHECK_ERROR(_readMethod_utility_as_derivative_V1(c, &method->basic.utility_as_derivative_V1))
        break;
    case 512: /* module 2 call 0 */
        CHECK_ERROR(_readMethod_babe_report_equivocation_V1(c, &method->basic.babe_report_equivocation_V1))
        break;
    case 513: /* module 2 call 1 */
        CHECK_ERROR(_readMethod_babe_report_equivocation_unsigned_V1(c, &method->basic.babe_report_equivocation_unsigned_V1))
        break;
    case 768: /* module 3 call 0 */
        CHECK_ERROR(_readMethod_timestamp_set_V1(c, &method->basic.timestamp_set_V1))
        break;
    case 1024: /* module 4 call 0 */
        CHECK_ERROR(_readMethod_authorship_set_uncles_V1(c, &method->basic.authorship_set_uncles_V1))
        break;
    case 1280: /* module 5 call 0 */
        CHECK_ERROR(_readMethod_balances_transfer_V1(c, &method->basic.balances_transfer_V1))
        break;
    case 1281: /* module 5 call 1 */
        CHECK_ERROR(_readMethod_balances_set_balance_V1(c, &method->basic.balances_set_balance_V1))
        break;
    case 1282: /* module 5 call 2 */
        CHECK_ERROR(_readMethod_balances_force_transfer_V1(c, &method->basic.balances_force_transfer_V1))
        break;
    case 1283: /* module 5 call 3 */
        CHECK_ERROR(_readMethod_balances_transfer_keep_alive_V1(c, &method->basic.balances_transfer_keep_alive_V1))
        break;
    case 1536: /* module 6 call 0 */
        CHECK_ERROR(_readMethod_staking_bond_V1(c, &method->basic.staking_bond_V1))
        break;
    case 1537: /* module 6 call 1 */
        CHECK_ERROR(_readMethod_staking_bond_extra_V1(c, &method->basic.staking_bond_extra_V1))
        break;
    case 1538: /* module 6 call 2 */
        CHECK_ERROR(_readMethod_staking_unbond_V1(c, &method->basic.staking_unbond_V1))
        break;
    case 1539: /* module 6 call 3 */
        CHECK_ERROR(_readMethod_staking_withdraw_unbonded_V1(c, &method->basic.staking_withdraw_unbonded_V1))
        break;
    case 1540: /* module 6 call 4 */
        CHECK_ERROR(_readMethod_staking_validate_V1(c, &method->basic.staking_validate_V1))
        break;
    case 1541: /* module 6 call 5 */
        CHECK_ERROR(_readMethod_staking_nominate_V1(c, &method->basic.staking_nominate_V1))
        break;
    case 1542: /* module 6 call 6 */
        CHECK_ERROR(_readMethod_staking_chill_V1(c, &method->basic.staking_chill_V1))
        break;
    case 1543: /* module 6 call 7 */
        CHECK_ERROR(_readMethod_staking_set_payee_V1(c, &method->basic.staking_set_payee_V1))
        break;
    case 1544: /* module 6 call 8 */
        CHECK_ERROR(_readMethod_staking_set_controller_V1(c, &method->basic.staking_set_controller_V1))
        break;
    case 1545: /* module 6 call 9 */
        CHECK_ERROR(_readMethod_staking_set_validator_count_V1(c, &method->basic.staking_set_validator_count_V1))
        break;
    case 1546: /* module 6 call 10 */
        CHECK_ERROR(_readMethod_staking_increase_validator_count_V1(c, &method->basic.staking_increase_validator_count_V1))
        break;
    case 1547: /* module 6 call 11 */
        CHECK_ERROR(_readMethod_staking_scale_validator_count_V1(c, &method->basic.staking_scale_validator_count_V1))
        break;
    case 1548: /* module 6 call 12 */
        CHECK_ERROR(_readMethod_staking_force_no_eras_V1(c, &method->basic.staking_force_no_eras_V1))
        break;
    case 1549: /* module 6 call 13 */
        CHECK_ERROR(_readMethod_staking_force_new_era_V1(c, &method->basic.staking_force_new_era_V1))
        break;
    case 1550: /* module 6 call 14 */
        CHECK_ERROR(_readMethod_staking_set_invulnerables_V1(c, &method->basic.staking_set_invulnerables_V1))
        break;
    case 1551: /* module 6 call 15 */
        CHECK_ERROR(_readMethod_staking_force_unstake_V1(c, &method->basic.staking_force_unstake_V1))
        break;
    case 1552: /* module 6 call 16 */
        CHECK_ERROR(_readMethod_staking_force_new_era_always_V1(c, &method->basic.staking_force_new_era_always_V1))
        break;
    case 1553: /* module 6 call 17 */
        CHECK_ERROR(_readMethod_staking_cancel_deferred_slash_V1(c, &method->basic.staking_cancel_deferred_slash_V1))
        break;
    case 1554: /* module 6 call 18 */
        CHECK_ERROR(_readMethod_staking_payout_stakers_V1(c, &method->basic.staking_payout_stakers_V1))
        break;
    case 1555: /* module 6 call 19 */
        CHECK_ERROR(_readMethod_staking_rebond_V1(c, &method->basic.staking_rebond_V1))
        break;
    case 1556: /* module 6 call 20 */
        CHECK_ERROR(_readMethod_staking_set_history_depth_V1(c, &method->basic.staking_set_history_depth_V1))
        break;
    case 1557: /* module 6 call 21 */
        CHECK_ERROR(_readMethod_staking_reap_stash_V1(c, &method->basic.staking_reap_stash_V1))
        break;
    case 1558: /* module 6 call 22 */
        CHECK_ERROR(_readMethod_staking_submit_election_solution_V1(c, &method->basic.staking_submit_election_solution_V1))
        break;
    case 1559: /* module 6 call 23 */
        CHECK_ERROR(_readMethod_staking_submit_election_solution_unsigned_V1(c, &method->basic.staking_submit_election_solution_unsigned_V1))
        break;
    case 1792: /* module 7 call 0 */
        CHECK_ERROR(_readMethod_session_set_keys_V1(c, &method->basic.session_set_keys_V1))
        break;
    case 1793: /* module 7 call 1 */
        CHECK_ERROR(_readMethod_session_purge_keys_V1(c, &method->basic.session_purge_keys_V1))
        break;
    case 2048: /* module 8 call 0 */
        CHECK_ERROR(_readMethod_democracy_propose_V1(c, &method->basic.democracy_propose_V1))
        break;
    case 2049: /* module 8 call 1 */
        CHECK_ERROR(_readMethod_democracy_second_V1(c, &method->basic.democracy_second_V1))
        break;
    case 2050: /* module 8 call 2 */
        CHECK_ERROR(_readMethod_democracy_vote_V1(c, &method->basic.democracy_vote_V1))
        break;
    case 2051: /* module 8 call 3 */
        CHECK_ERROR(_readMethod_democracy_emergency_cancel_V1(c, &method->basic.democracy_emergency_cancel_V1))
        break;
    case 2052: /* module 8 call 4 */
        CHECK_ERROR(_readMethod_democracy_external_propose_V1(c, &method->basic.democracy_external_propose_V1))
        break;
    case 2053: /* module 8 call 5 */
        CHECK_ERROR(_readMethod_democracy_external_propose_majority_V1(c, &method->basic.democracy_external_propose_majority_V1))
        break;
    case 2054: /* module 8 call 6 */
        CHECK_ERROR(_readMethod_democracy_external_propose_default_V1(c, &method->basic.democracy_external_propose_default_V1))
        break;
    case 2055: /* module 8 call 7 */
        CHECK_ERROR(_readMethod_democracy_fast_track_V1(c, &method->basic.democracy_fast_track_V1))
        break;
    case 2056: /* module 8 call 8 */
        CHECK_ERROR(_readMethod_democracy_veto_external_V1(c, &method->basic.democracy_veto_external_V1))
        break;
    case 2057: /* module 8 call 9 */
        CHECK_ERROR(_readMethod_democracy_cancel_referendum_V1(c, &method->basic.democracy_cancel_referendum_V1))
        break;
    case 2058: /* module 8 call 10 */
        CHECK_ERROR(_readMethod_democracy_cancel_queued_V1(c, &method->basic.democracy_cancel_queued_V1))
        break;
    case 2059: /* module 8 call 11 */
        CHECK_ERROR(_readMethod_democracy_delegate_V1(c, &method->basic.democracy_delegate_V1))
        break;
    case 2060: /* module 8 call 12 */
        CHECK_ERROR(_readMethod_democracy_undelegate_V1(c, &method->basic.democracy_undelegate_V1))
        break;
    case 2061: /* module 8 call 13 */
        CHECK_ERROR(_readMethod_democracy_clear_public_proposals_V1(c, &method->basic.democracy_clear_public_proposals_V1))
        break;
    case 2062: /* module 8 call 14 */
        CHECK_ERROR(_readMethod_democracy_note_preimage_V1(c, &method->basic.democracy_note_preimage_V1))
        break;
    case 2063: /* module 8 call 15 */
        CHECK_ERROR(_readMethod_democracy_note_preimage_operational_V1(c, &method->basic.democracy_note_preimage_operational_V1))
        break;
    case 2064: /* module 8 call 16 */
        CHECK_ERROR(_readMethod_democracy_note_imminent_preimage_V1(c, &method->basic.democracy_note_imminent_preimage_V1))
        break;
    case 2065: /* module 8 call 17 */
        CHECK_ERROR(_readMethod_democracy_note_imminent_preimage_operational_V1(c, &method->basic.democracy_note_imminent_preimage_operational_V1))
        break;
    case 2066: /* module 8 call 18 */
        CHECK_ERROR(_readMethod_democracy_reap_preimage_V1(c, &method->basic.democracy_reap_preimage_V1))
        break;
    case 2067: /* module 8 call 19 */
        CHECK_ERROR(_readMethod_democracy_unlock_V1(c, &method->basic.democracy_unlock_V1))
        break;
    case 2068: /* module 8 call 20 */
        CHECK_ERROR(_readMethod_democracy_remove_vote_V1(c, &method->basic.democracy_remove_vote_V1))
        break;
    case 2069: /* module 8 call 21 */
        CHECK_ERROR(_readMethod_democracy_remove_other_vote_V1(c, &method->basic.democracy_remove_other_vote_V1))
        break;
    case 2070: /* module 8 call 22 */
        CHECK_ERROR(_readMethod_democracy_enact_proposal_V1(c, &method->basic.democracy_enact_proposal_V1))
        break;
    case 2304: /* module 9 call 0 */
        CHECK_ERROR(_readMethod_council_set_members_V1(c, &method->basic.council_set_members_V1))
        break;
    case 2305: /* module 9 call 1 */
        CHECK_ERROR(_readMethod_council_execute_V1(c, &method->basic.council_execute_V1))
        break;
    case 2306: /* module 9 call 2 */
        CHECK_ERROR(_readMethod_council_propose_V1(c, &method->basic.council_propose_V1))
        break;
    case 2307: /* module 9 call 3 */
        CHECK_ERROR(_readMethod_council_vote_V1(c, &method->basic.council_vote_V1))
        break;
    case 2308: /* module 9 call 4 */
        CHECK_ERROR(_readMethod_council_close_V1(c, &method->basic.council_close_V1))
        break;
    case 2309: /* module 9 call 5 */
        CHECK_ERROR(_readMethod_council_disapprove_proposal_V1(c, &method->basic.council_disapprove_proposal_V1))
        break;
    case 2560: /* module 10 call 0 */
        CHECK_ERROR(_readMethod_elections_vote_V1(c, &method->basic.elections_vote_V1))
        break;
    case 2561: /* module 10 call 1 */
        CHECK_ERROR(_readMethod_elections_remove_voter_V1(c, &method->basic.elections_remove_voter_V1))
        break;
    case 2562: /* module 10 call 2 */
        CHECK_ERROR(_readMethod_elections_report_defunct_voter_V1(c, &method->basic.elections_report_defunct_voter_V1))
        break;
    case 2563: /* module 10 call 3 */
        CHECK_ERROR(_readMethod_elections_submit_candidacy_V1(c, &method->basic.elections_submit_candidacy_V1))
        break;
    case 2564: /* module 10 call 4 */
        CHECK_ERROR(_readMethod_elections_renounce_candidacy_V1(c, &method->basic.elections_renounce_candidacy_V1))
        break;
    case 2565: /* module 10 call 5 */
        CHECK_ERROR(_readMethod_elections_remove_member_V1(c, &method->basic.elections_remove_member_V1))
        break;
    case 2816: /* module 11 call 0 */
        CHECK_ERROR(_readMethod_finalitytracker_final_hint_V1(c, &method->basic.finalitytracker_final_hint_V1))
        break;
    case 3072: /* module 12 call 0 */
        CHECK_ERROR(_readMethod_grandpa_report_equivocation_V1(c, &method->basic.grandpa_report_equivocation_V1))
        break;
    case 3073: /* module 12 call 1 */
        CHECK_ERROR(_readMethod_grandpa_report_equivocation_unsigned_V1(c, &method->basic.grandpa_report_equivocation_unsigned_V1))
        break;
    case 3074: /* module 12 call 2 */
        CHECK_ERROR(_readMethod_grandpa_note_stalled_V1(c, &method->basic.grandpa_note_stalled_V1))
        break;
    case 3328: /* module 13 call 0 */
        CHECK_ERROR(_readMethod_imonline_heartbeat_V1(c, &method->basic.imonline_heartbeat_V1))
        break;
    case 4352: /* module 17 call 0 */
        CHECK_ERROR(_readMethod_anchor_pre_commit_V1(c, &method->basic.anchor_pre_commit_V1))
        break;
    case 4353: /* module 17 call 1 */
        CHECK_ERROR(_readMethod_anchor_commit_V1(c, &method->basic.anchor_commit_V1))
        break;
    case 4354: /* module 17 call 2 */
        CHECK_ERROR(_readMethod_anchor_evict_pre_commits_V1(c, &method->basic.anchor_evict_pre_commits_V1))
        break;
    case 4355: /* module 17 call 3 */
        CHECK_ERROR(_readMethod_anchor_evict_anchors_V1(c, &method->basic.anchor_evict_anchors_V1))
        break;
    case 4608: /* module 18 call 0 */
        CHECK_ERROR(_readMethod_fees_set_fee_V1(c, &method->basic.fees_set_fee_V1))
        break;
    case 4864: /* module 19 call 0 */
        CHECK_ERROR(_readMethod_nfts_validate_mint_V1(c, &method->basic.nfts_validate_mint_V1))
        break;
    case 5120: /* module 20 call 0 */
        CHECK_ERROR(_readMethod_multiaccount_create_V1(c, &method->basic.multiaccount_create_V1))
        break;
    case 5121: /* module 20 call 1 */
        CHECK_ERROR(_readMethod_multiaccount_update_V1(c, &method->basic.multiaccount_update_V1))
        break;
    case 5122: /* module 20 call 2 */
        CHECK_ERROR(_readMethod_multiaccount_remove_V1(c, &method->basic.multiaccount_remove_V1))
        break;
    case 5123: /* module 20 call 3 */
        CHECK_ERROR(_readMethod_multiaccount_call_V1(c, &method->basic.multiaccount_call_V1))
        break;
    case 5124: /* module 20 call 4 */
        CHECK_ERROR(_readMethod_multiaccount_approve_V1(c, &method->basic.multiaccount_approve_V1))
        break;
    case 5125: /* module 20 call 5 */
        CHECK_ERROR(_readMethod_multiaccount_cancel_V1(c, &method->basic.multiaccount_cancel_V1))
        break;
    case 5376: /* module 21 call 0 */
        CHECK_ERROR(_readMethod_identity_add_registrar_V1(c, &method->basic.identity_add_registrar_V1))
        break;
    case 5377: /* module 21 call 1 */
        CHECK_ERROR(_readMethod_identity_set_identity_V1(c, &method->basic.identity_set_identity_V1))
        break;
    case 5378: /* module 21 call 2 */
        CHECK_ERROR(_readMethod_identity_set_subs_V1(c, &method->basic.identity_set_subs_V1))
        break;
    case 5379: /* module 21 call 3 */
        CHECK_ERROR(_readMethod_identity_clear_identity_V1(c, &method->basic.identity_clear_identity_V1))
        break;
    case 5380: /* module 21 call 4 */
        CHECK_ERROR(_readMethod_identity_request_judgement_V1(c, &method->basic.identity_request_judgement_V1))
        break;
    case 5381: /* module 21 call 5 */
        CHECK_ERROR(_readMethod_identity_cancel_request_V1(c, &method->basic.identity_cancel_request_V1))
        break;
    case 5382: /* module 21 call 6 */
        CHECK_ERROR(_readMethod_identity_set_fee_V1(c, &method->basic.identity_set_fee_V1))
        break;
    case 5383: /* module 21 call 7 */
        CHECK_ERROR(_readMethod_identity_set_account_id_V1(c, &method->basic.identity_set_account_id_V1))
        break;
    case 5384: /* module 21 call 8 */
        CHECK_ERROR(_readMethod_identity_set_fields_V1(c, &method->basic.identity_set_fields_V1))
        break;
    case 5385: /* module 21 call 9 */
        CHECK_ERROR(_readMethod_identity_provide_judgement_V1(c, &method->basic.identity_provide_judgement_V1))
        break;
    case 5386: /* module 21 call 10 */
        CHECK_ERROR(_readMethod_identity_kill_identity_V1(c, &method->basic.identity_kill_identity_V1))
        break;
    case 5387: /* module 21 call 11 */
        CHECK_ERROR(_readMethod_identity_add_sub_V1(c, &method->basic.identity_add_sub_V1))
        break;
    case 5388: /* module 21 call 12 */
        CHECK_ERROR(_readMethod_identity_rename_sub_V1(c, &method->basic.identity_rename_sub_V1))
        break;
    case 5389: /* module 21 call 13 */
        CHECK_ERROR(_readMethod_identity_remove_sub_V1(c, &method->basic.identity_remove_sub_V1))
        break;
    case 5390: /* module 21 call 14 */
        CHECK_ERROR(_readMethod_identity_quit_sub_V1(c, &method->basic.identity_quit_sub_V1))
        break;
    case 5632: /* module 22 call 0 */
        CHECK_ERROR(_readMethod_palletbridge_transfer_native_V1(c, &method->basic.palletbridge_transfer_native_V1))
        break;
    case 5633: /* module 22 call 1 */
        CHECK_ERROR(_readMethod_palletbridge_transfer_asset_V1(c, &method->basic.palletbridge_transfer_asset_V1))
        break;
    case 5634: /* module 22 call 2 */
        CHECK_ERROR(_readMethod_palletbridge_transfer_V1(c, &method->basic.palletbridge_transfer_V1))
        break;
    case 5635: /* module 22 call 3 */
        CHECK_ERROR(_readMethod_palletbridge_receive_nonfungible_V1(c, &method->basic.palletbridge_receive_nonfungible_V1))
        break;
    case 5636: /* module 22 call 4 */
        CHECK_ERROR(_readMethod_palletbridge_remark_V1(c, &method->basic.palletbridge_remark_V1))
        break;
    case 5888: /* module 23 call 0 */
        CHECK_ERROR(_readMethod_chainbridge_set_threshold_V1(c, &method->basic.chainbridge_set_threshold_V1))
        break;
    case 5889: /* module 23 call 1 */
        CHECK_ERROR(_readMethod_chainbridge_set_resource_V1(c, &method->basic.chainbridge_set_resource_V1))
        break;
    case 5890: /* module 23 call 2 */
        CHECK_ERROR(_readMethod_chainbridge_remove_resource_V1(c, &method->basic.chainbridge_remove_resource_V1))
        break;
    case 5891: /* module 23 call 3 */
        CHECK_ERROR(_readMethod_chainbridge_whitelist_chain_V1(c, &method->basic.chainbridge_whitelist_chain_V1))
        break;
    case 5892: /* module 23 call 4 */
        CHECK_ERROR(_readMethod_chainbridge_add_relayer_V1(c, &method->basic.chainbridge_add_relayer_V1))
        break;
    case 5893: /* module 23 call 5 */
        CHECK_ERROR(_readMethod_chainbridge_remove_relayer_V1(c, &method->basic.chainbridge_remove_relayer_V1))
        break;
    case 5894: /* module 23 call 6 */
        CHECK_ERROR(_readMethod_chainbridge_acknowledge_proposal_V1(c, &method->basic.chainbridge_acknowledge_proposal_V1))
        break;
    case 5895: /* module 23 call 7 */
        CHECK_ERROR(_readMethod_chainbridge_reject_proposal_V1(c, &method->basic.chainbridge_reject_proposal_V1))
        break;
    case 5896: /* module 23 call 8 */
        CHECK_ERROR(_readMethod_chainbridge_eval_vote_state_V1(c, &method->basic.chainbridge_eval_vote_state_V1))
        break;
    case 6144: /* module 24 call 0 */
        CHECK_ERROR(_readMethod_indices_claim_V1(c, &method->basic.indices_claim_V1))
        break;
    case 6145: /* module 24 call 1 */
        CHECK_ERROR(_readMethod_indices_transfer_V1(c, &method->basic.indices_transfer_V1))
        break;
    case 6146: /* module 24 call 2 */
        CHECK_ERROR(_readMethod_indices_free_V1(c, &method->basic.indices_free_V1))
        break;
    case 6147: /* module 24 call 3 */
        CHECK_ERROR(_readMethod_indices_force_transfer_V1(c, &method->basic.indices_force_transfer_V1))
        break;
    case 6148: /* module 24 call 4 */
        CHECK_ERROR(_readMethod_indices_freeze_V1(c, &method->basic.indices_freeze_V1))
        break;
    case 6400: /* module 25 call 0 */
        CHECK_ERROR(_readMethod_scheduler_schedule_V1(c, &method->basic.scheduler_schedule_V1))
        break;
    case 6401: /* module 25 call 1 */
        CHECK_ERROR(_readMethod_scheduler_cancel_V1(c, &method->basic.scheduler_cancel_V1))
        break;
    case 6402: /* module 25 call 2 */
        CHECK_ERROR(_readMethod_scheduler_schedule_named_V1(c, &method->basic.scheduler_schedule_named_V1))
        break;
    case 6403: /* module 25 call 3 */
        CHECK_ERROR(_readMethod_scheduler_cancel_named_V1(c, &method->basic.scheduler_cancel_named_V1))
        break;
    case 6404: /* module 25 call 4 */
        CHECK_ERROR(_readMethod_scheduler_schedule_after_V1(c, &method->basic.scheduler_schedule_after_V1))
        break;
    case 6405: /* module 25 call 5 */
        CHECK_ERROR(_readMethod_scheduler_schedule_named_after_V1(c, &method->basic.scheduler_schedule_named_after_V1))
        break;
    case 6656: /* module 26 call 0 */
        CHECK_ERROR(_readMethod_proxy_proxy_V1(c, &method->basic.proxy_proxy_V1))
        break;
    case 6657: /* module 26 call 1 */
        CHECK_ERROR(_readMethod_proxy_add_proxy_V1(c, &method->basic.proxy_add_proxy_V1))
        break;
    case 6658: /* module 26 call 2 */
        CHECK_ERROR(_readMethod_proxy_remove_proxy_V1(c, &method->basic.proxy_remove_proxy_V1))
        break;
    case 6659: /* module 26 call 3 */
        CHECK_ERROR(_readMethod_proxy_remove_proxies_V1(c, &method->basic.proxy_remove_proxies_V1))
        break;
    case 6660: /* module 26 call 4 */
        CHECK_ERROR(_readMethod_proxy_anonymous_V1(c, &method->basic.proxy_anonymous_V1))
        break;
    case 6661: /* module 26 call 5 */
        CHECK_ERROR(_readMethod_proxy_kill_anonymous_V1(c, &method->basic.proxy_kill_anonymous_V1))
        break;
    case 6912: /* module 27 call 0 */
        CHECK_ERROR(_readMethod_multisig_as_multi_threshold_1_V1(c, &method->basic.multisig_as_multi_threshold_1_V1))
        break;
    case 6913: /* module 27 call 1 */
        CHECK_ERROR(_readMethod_multisig_as_multi_V1(c, &method->basic.multisig_as_multi_V1))
        break;
    case 6914: /* module 27 call 2 */
        CHECK_ERROR(_readMethod_multisig_approve_as_multi_V1(c, &method->basic.multisig_approve_as_multi_V1))
        break;
    case 6915: /* module 27 call 3 */
        CHECK_ERROR(_readMethod_multisig_cancel_as_multi_V1(c, &method->basic.multisig_cancel_as_multi_V1))
        break;
    case 7168: /* module 28 call 0 */
        CHECK_ERROR(_readMethod_radclaims_claim_V1(c, &method->basic.radclaims_claim_V1))
        break;
    case 7169: /* module 28 call 1 */
        CHECK_ERROR(_readMethod_radclaims_set_upload_account_V1(c, &method->basic.radclaims_set_upload_account_V1))
        break;
    case 7170: /* module 28 call 2 */
        CHECK_ERROR(_readMethod_radclaims_store_root_hash_V1(c, &method->basic.radclaims_store_root_hash_V1))
        break;
    case 7424: /* module 29 call 0 */
        CHECK_ERROR(_readMethod_vesting_vest_V1(c, &method->basic.vesting_vest_V1))
        break;
    case 7425: /* module 29 call 1 */
        CHECK_ERROR(_readMethod_vesting_vest_other_V1(c, &method->basic.vesting_vest_other_V1))
        break;
    case 7426: /* module 29 call 2 */
        CHECK_ERROR(_readMethod_vesting_vested_transfer_V1(c, &method->basic.vesting_vested_transfer_V1))
        break;
    case 7427: /* module 29 call 3 */
        CHECK_ERROR(_readMethod_vesting_force_vested_transfer_V1(c, &method->basic.vesting_force_vested_transfer_V1))
        break;
    case 7680: /* module 30 call 0 */
        CHECK_ERROR(_readMethod_registry_create_registry_V1(c, &method->basic.registry_create_registry_V1))
        break;
    case 7681: /* module 30 call 1 */
        CHECK_ERROR(_readMethod_registry_mint_V1(c, &method->basic.registry_mint_V1))
        break;
    case 7936: /* module 31 call 0 */
        CHECK_ERROR(_readMethod_nft_transfer_V1(c, &method->basic.nft_transfer_V1))
        break;
    case 8192: /* module 32 call 0 */
        CHECK_ERROR(_readMethod_bridgemapping_set_V1(c, &method->basic.bridgemapping_set_V1))
        break;
    case 8193: /* module 32 call 1 */
        CHECK_ERROR(_readMethod_bridgemapping_remove_V1(c, &method->basic.bridgemapping_remove_V1))
        break;
    default:
        return parser_unexpected_callIndex;
    }

    return parser_ok;
}

/////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////

const char* _getMethod_ModuleName_V1(uint8_t moduleIdx)
{
    switch (moduleIdx) {
    case 0:
        return "System";
    case 1:
        return "Utility";
    case 2:
        return "Babe";
    case 3:
        return "Timestamp";
    case 4:
        return "Authorship";
    case 5:
        return "Balances";
    case 6:
        return "Staking";
    case 7:
        return "Session";
    case 8:
        return "Democracy";
    case 9:
        return "Council";
    case 10:
        return "Elections";
    case 11:
        return "Finalitytracker";
    case 12:
        return "Grandpa";
    case 13:
        return "Imonline";
    case 14:
        return "Authoritydiscovery";
    case 15:
        return "Offences";
    case 16:
        return "Randomnesscollectiveflip";
    case 17:
        return "Anchor";
    case 18:
        return "Fees";
    case 19:
        return "Nfts";
    case 20:
        return "Multiaccount";
    case 21:
        return "Identity";
    case 22:
        return "Palletbridge";
    case 23:
        return "Chainbridge";
    case 24:
        return "Indices";
    case 25:
        return "Scheduler";
    case 26:
        return "Proxy";
    case 27:
        return "Multisig";
    case 28:
        return "Radclaims";
    case 29:
        return "Vesting";
    case 30:
        return "Registry";
    case 31:
        return "Nft";
    case 32:
        return "Bridgemapping";
    default:
        return NULL;
    }

    return NULL;
}

const char* _getMethod_Name_V1(uint8_t moduleIdx, uint8_t callIdx)
{
    uint16_t callPrivIdx = ((uint16_t)moduleIdx << 8u) + callIdx;

    switch (callPrivIdx) {
    case 0: /* module 0 call 0 */
        return "Fill block";
    case 1: /* module 0 call 1 */
        return "Remark";
    case 2: /* module 0 call 2 */
        return "Set heap pages";
    case 3: /* module 0 call 3 */
        return "Set code";
    case 4: /* module 0 call 4 */
        return "Set code without checks";
    case 5: /* module 0 call 5 */
        return "Set changes trie config";
    case 6: /* module 0 call 6 */
        return "Set storage";
    case 7: /* module 0 call 7 */
        return "Kill storage";
    case 8: /* module 0 call 8 */
        return "Kill prefix";
    case 9: /* module 0 call 9 */
        return "Suicide";
    case 256: /* module 1 call 0 */
        return "Batch";
    case 257: /* module 1 call 1 */
        return "As derivative";
    case 512: /* module 2 call 0 */
        return "Report equivocation";
    case 513: /* module 2 call 1 */
        return "Report equivocation unsigned";
    case 768: /* module 3 call 0 */
        return "Set";
    case 1024: /* module 4 call 0 */
        return "Set uncles";
    case 1280: /* module 5 call 0 */
        return "Transfer";
    case 1281: /* module 5 call 1 */
        return "Set balance";
    case 1282: /* module 5 call 2 */
        return "Force transfer";
    case 1283: /* module 5 call 3 */
        return "Transfer keep alive";
    case 1536: /* module 6 call 0 */
        return "Bond";
    case 1537: /* module 6 call 1 */
        return "Bond extra";
    case 1538: /* module 6 call 2 */
        return "Unbond";
    case 1539: /* module 6 call 3 */
        return "Withdraw Unbonded";
    case 1540: /* module 6 call 4 */
        return "Validate";
    case 1541: /* module 6 call 5 */
        return "Nominate";
    case 1542: /* module 6 call 6 */
        return "Chill";
    case 1543: /* module 6 call 7 */
        return "Set payee";
    case 1544: /* module 6 call 8 */
        return "Set controller";
    case 1545: /* module 6 call 9 */
        return "Set validator count";
    case 1546: /* module 6 call 10 */
        return "Increase validator count";
    case 1547: /* module 6 call 11 */
        return "Scale validator count";
    case 1548: /* module 6 call 12 */
        return "Force no eras";
    case 1549: /* module 6 call 13 */
        return "Force new era";
    case 1550: /* module 6 call 14 */
        return "Set invulnerables";
    case 1551: /* module 6 call 15 */
        return "Force unstake";
    case 1552: /* module 6 call 16 */
        return "Force new era always";
    case 1553: /* module 6 call 17 */
        return "Cancel deferred slash";
    case 1554: /* module 6 call 18 */
        return "Payout stakers";
    case 1555: /* module 6 call 19 */
        return "Rebond";
    case 1556: /* module 6 call 20 */
        return "Set history depth";
    case 1557: /* module 6 call 21 */
        return "Reap stash";
    case 1558: /* module 6 call 22 */
        return "Submit election solution";
    case 1559: /* module 6 call 23 */
        return "Submit election solution unsigned";
    case 1792: /* module 7 call 0 */
        return "Set keys";
    case 1793: /* module 7 call 1 */
        return "Purge keys";
    case 2048: /* module 8 call 0 */
        return "Propose";
    case 2049: /* module 8 call 1 */
        return "Second";
    case 2050: /* module 8 call 2 */
        return "Vote";
    case 2051: /* module 8 call 3 */
        return "Emergency cancel";
    case 2052: /* module 8 call 4 */
        return "External propose";
    case 2053: /* module 8 call 5 */
        return "External propose majority";
    case 2054: /* module 8 call 6 */
        return "External propose default";
    case 2055: /* module 8 call 7 */
        return "Fast track";
    case 2056: /* module 8 call 8 */
        return "Veto external";
    case 2057: /* module 8 call 9 */
        return "Cancel referendum";
    case 2058: /* module 8 call 10 */
        return "Cancel queued";
    case 2059: /* module 8 call 11 */
        return "Delegate";
    case 2060: /* module 8 call 12 */
        return "Undelegate";
    case 2061: /* module 8 call 13 */
        return "Clear public proposals";
    case 2062: /* module 8 call 14 */
        return "Note preimage";
    case 2063: /* module 8 call 15 */
        return "Note preimage operational";
    case 2064: /* module 8 call 16 */
        return "Note imminent preimage";
    case 2065: /* module 8 call 17 */
        return "Note imminent preimage operational";
    case 2066: /* module 8 call 18 */
        return "Reap preimage";
    case 2067: /* module 8 call 19 */
        return "Unlock";
    case 2068: /* module 8 call 20 */
        return "Remove vote";
    case 2069: /* module 8 call 21 */
        return "Remove other vote";
    case 2070: /* module 8 call 22 */
        return "Enact proposal";
    case 2304: /* module 9 call 0 */
        return "Set members";
    case 2305: /* module 9 call 1 */
        return "Execute";
    case 2306: /* module 9 call 2 */
        return "Propose";
    case 2307: /* module 9 call 3 */
        return "Vote";
    case 2308: /* module 9 call 4 */
        return "Close";
    case 2309: /* module 9 call 5 */
        return "Disapprove proposal";
    case 2560: /* module 10 call 0 */
        return "Vote";
    case 2561: /* module 10 call 1 */
        return "Remove voter";
    case 2562: /* module 10 call 2 */
        return "Report defunct voter";
    case 2563: /* module 10 call 3 */
        return "Submit candidacy";
    case 2564: /* module 10 call 4 */
        return "Renounce candidacy";
    case 2565: /* module 10 call 5 */
        return "Remove member";
    case 2816: /* module 11 call 0 */
        return "Final hint";
    case 3072: /* module 12 call 0 */
        return "Report equivocation";
    case 3073: /* module 12 call 1 */
        return "Report equivocation unsigned";
    case 3074: /* module 12 call 2 */
        return "Note stalled";
    case 3328: /* module 13 call 0 */
        return "Heartbeat";
    case 4352: /* module 17 call 0 */
        return "Pre commit";
    case 4353: /* module 17 call 1 */
        return "Commit";
    case 4354: /* module 17 call 2 */
        return "Evict pre commits";
    case 4355: /* module 17 call 3 */
        return "Evict anchors";
    case 4608: /* module 18 call 0 */
        return "Set fee";
    case 4864: /* module 19 call 0 */
        return "Validate mint";
    case 5120: /* module 20 call 0 */
        return "Create";
    case 5121: /* module 20 call 1 */
        return "Update";
    case 5122: /* module 20 call 2 */
        return "Remove";
    case 5123: /* module 20 call 3 */
        return "Call";
    case 5124: /* module 20 call 4 */
        return "Approve";
    case 5125: /* module 20 call 5 */
        return "Cancel";
    case 5376: /* module 21 call 0 */
        return "Add registrar";
    case 5377: /* module 21 call 1 */
        return "Set identity";
    case 5378: /* module 21 call 2 */
        return "Set subs";
    case 5379: /* module 21 call 3 */
        return "Clear identity";
    case 5380: /* module 21 call 4 */
        return "Request judgement";
    case 5381: /* module 21 call 5 */
        return "Cancel request";
    case 5382: /* module 21 call 6 */
        return "Set fee";
    case 5383: /* module 21 call 7 */
        return "Set account id";
    case 5384: /* module 21 call 8 */
        return "Set fields";
    case 5385: /* module 21 call 9 */
        return "Provide judgement";
    case 5386: /* module 21 call 10 */
        return "Kill identity";
    case 5387: /* module 21 call 11 */
        return "Add sub";
    case 5388: /* module 21 call 12 */
        return "Rename sub";
    case 5389: /* module 21 call 13 */
        return "Remove sub";
    case 5390: /* module 21 call 14 */
        return "Quit sub";
    case 5632: /* module 22 call 0 */
        return "Transfer native";
    case 5633: /* module 22 call 1 */
        return "Transfer asset";
    case 5634: /* module 22 call 2 */
        return "Transfer";
    case 5635: /* module 22 call 3 */
        return "Receive nonfungible";
    case 5636: /* module 22 call 4 */
        return "Remark";
    case 5888: /* module 23 call 0 */
        return "Set threshold";
    case 5889: /* module 23 call 1 */
        return "Set resource";
    case 5890: /* module 23 call 2 */
        return "Remove resource";
    case 5891: /* module 23 call 3 */
        return "Whitelist chain";
    case 5892: /* module 23 call 4 */
        return "Add relayer";
    case 5893: /* module 23 call 5 */
        return "Remove relayer";
    case 5894: /* module 23 call 6 */
        return "Acknowledge proposal";
    case 5895: /* module 23 call 7 */
        return "Reject proposal";
    case 5896: /* module 23 call 8 */
        return "Eval vote state";
    case 6144: /* module 24 call 0 */
        return "Claim";
    case 6145: /* module 24 call 1 */
        return "Transfer";
    case 6146: /* module 24 call 2 */
        return "Free";
    case 6147: /* module 24 call 3 */
        return "Force transfer";
    case 6148: /* module 24 call 4 */
        return "Freeze";
    case 6400: /* module 25 call 0 */
        return "Schedule";
    case 6401: /* module 25 call 1 */
        return "Cancel";
    case 6402: /* module 25 call 2 */
        return "Schedule named";
    case 6403: /* module 25 call 3 */
        return "Cancel named";
    case 6404: /* module 25 call 4 */
        return "Schedule after";
    case 6405: /* module 25 call 5 */
        return "Schedule named after";
    case 6656: /* module 26 call 0 */
        return "Proxy";
    case 6657: /* module 26 call 1 */
        return "Add proxy";
    case 6658: /* module 26 call 2 */
        return "Remove proxy";
    case 6659: /* module 26 call 3 */
        return "Remove proxies";
    case 6660: /* module 26 call 4 */
        return "Anonymous";
    case 6661: /* module 26 call 5 */
        return "Kill anonymous";
    case 6912: /* module 27 call 0 */
        return "As multi threshold 1";
    case 6913: /* module 27 call 1 */
        return "As multi";
    case 6914: /* module 27 call 2 */
        return "Approve as multi";
    case 6915: /* module 27 call 3 */
        return "Cancel as multi";
    case 7168: /* module 28 call 0 */
        return "Claim";
    case 7169: /* module 28 call 1 */
        return "Set upload account";
    case 7170: /* module 28 call 2 */
        return "Store root hash";
    case 7424: /* module 29 call 0 */
        return "Vest";
    case 7425: /* module 29 call 1 */
        return "Vest other";
    case 7426: /* module 29 call 2 */
        return "Vested transfer";
    case 7427: /* module 29 call 3 */
        return "Force vested transfer";
    case 7680: /* module 30 call 0 */
        return "Create registry";
    case 7681: /* module 30 call 1 */
        return "Mint";
    case 7936: /* module 31 call 0 */
        return "Transfer";
    case 8192: /* module 32 call 0 */
        return "Set";
    case 8193: /* module 32 call 1 */
        return "Remove";
    default:
        return NULL;
    }

    return NULL;
}

uint8_t _getMethod_NumItems_V1(uint8_t moduleIdx, uint8_t callIdx, pd_Method_V1_t* method)
{
    uint16_t callPrivIdx = ((uint16_t)moduleIdx << 8u) + callIdx;

    switch (callPrivIdx) {
    case 0: /* module 0 call 0 */
        return 1;
    case 1: /* module 0 call 1 */
        return 1;
    case 2: /* module 0 call 2 */
        return 1;
    case 3: /* module 0 call 3 */
        return 1;
    case 4: /* module 0 call 4 */
        return 1;
    case 5: /* module 0 call 5 */
        return 1;
    case 6: /* module 0 call 6 */
        return 1;
    case 7: /* module 0 call 7 */
        return 1;
    case 8: /* module 0 call 8 */
        return 2;
    case 9: /* module 0 call 9 */
        return 0;
    case 256: /* module 1 call 0 */
        return 1;
    case 257: /* module 1 call 1 */
        return 2;
    case 512: /* module 2 call 0 */
        return 2;
    case 513: /* module 2 call 1 */
        return 2;
    case 768: /* module 3 call 0 */
        return 1;
    case 1024: /* module 4 call 0 */
        return 1;
    case 1280: /* module 5 call 0 */
        return 2;
    case 1281: /* module 5 call 1 */
        return 3;
    case 1282: /* module 5 call 2 */
        return 3;
    case 1283: /* module 5 call 3 */
        return 2;
    case 1536: /* module 6 call 0 */
        return 3;
    case 1537: /* module 6 call 1 */
        return 1;
    case 1538: /* module 6 call 2 */
        return 1;
    case 1539: /* module 6 call 3 */
        return 1;
    case 1540: /* module 6 call 4 */
        return 1;
    case 1541: /* module 6 call 5 */
        return 1;
    case 1542: /* module 6 call 6 */
        return 0;
    case 1543: /* module 6 call 7 */
        return 1;
    case 1544: /* module 6 call 8 */
        return 1;
    case 1545: /* module 6 call 9 */
        return 1;
    case 1546: /* module 6 call 10 */
        return 1;
    case 1547: /* module 6 call 11 */
        return 1;
    case 1548: /* module 6 call 12 */
        return 0;
    case 1549: /* module 6 call 13 */
        return 0;
    case 1550: /* module 6 call 14 */
        return 1;
    case 1551: /* module 6 call 15 */
        return 2;
    case 1552: /* module 6 call 16 */
        return 0;
    case 1553: /* module 6 call 17 */
        return 2;
    case 1554: /* module 6 call 18 */
        return 2;
    case 1555: /* module 6 call 19 */
        return 1;
    case 1556: /* module 6 call 20 */
        return 2;
    case 1557: /* module 6 call 21 */
        return 2;
    case 1558: /* module 6 call 22 */
        return 5;
    case 1559: /* module 6 call 23 */
        return 5;
    case 1792: /* module 7 call 0 */
        return 2;
    case 1793: /* module 7 call 1 */
        return 0;
    case 2048: /* module 8 call 0 */
        return 2;
    case 2049: /* module 8 call 1 */
        return 2;
    case 2050: /* module 8 call 2 */
        return 2;
    case 2051: /* module 8 call 3 */
        return 1;
    case 2052: /* module 8 call 4 */
        return 1;
    case 2053: /* module 8 call 5 */
        return 1;
    case 2054: /* module 8 call 6 */
        return 1;
    case 2055: /* module 8 call 7 */
        return 3;
    case 2056: /* module 8 call 8 */
        return 1;
    case 2057: /* module 8 call 9 */
        return 1;
    case 2058: /* module 8 call 10 */
        return 1;
    case 2059: /* module 8 call 11 */
        return 3;
    case 2060: /* module 8 call 12 */
        return 0;
    case 2061: /* module 8 call 13 */
        return 0;
    case 2062: /* module 8 call 14 */
        return 1;
    case 2063: /* module 8 call 15 */
        return 1;
    case 2064: /* module 8 call 16 */
        return 1;
    case 2065: /* module 8 call 17 */
        return 1;
    case 2066: /* module 8 call 18 */
        return 2;
    case 2067: /* module 8 call 19 */
        return 1;
    case 2068: /* module 8 call 20 */
        return 1;
    case 2069: /* module 8 call 21 */
        return 2;
    case 2070: /* module 8 call 22 */
        return 2;
    case 2304: /* module 9 call 0 */
        return 3;
    case 2305: /* module 9 call 1 */
        return 2;
    case 2306: /* module 9 call 2 */
        return 3;
    case 2307: /* module 9 call 3 */
        return 3;
    case 2308: /* module 9 call 4 */
        return 4;
    case 2309: /* module 9 call 5 */
        return 1;
    case 2560: /* module 10 call 0 */
        return 2;
    case 2561: /* module 10 call 1 */
        return 0;
    case 2562: /* module 10 call 2 */
        return 1;
    case 2563: /* module 10 call 3 */
        return 1;
    case 2564: /* module 10 call 4 */
        return 1;
    case 2565: /* module 10 call 5 */
        return 2;
    case 2816: /* module 11 call 0 */
        return 1;
    case 3072: /* module 12 call 0 */
        return 2;
    case 3073: /* module 12 call 1 */
        return 2;
    case 3074: /* module 12 call 2 */
        return 2;
    case 3328: /* module 13 call 0 */
        return 2;
    case 4352: /* module 17 call 0 */
        return 2;
    case 4353: /* module 17 call 1 */
        return 4;
    case 4354: /* module 17 call 2 */
        return 1;
    case 4355: /* module 17 call 3 */
        return 0;
    case 4608: /* module 18 call 0 */
        return 2;
    case 4864: /* module 19 call 0 */
        return 5;
    case 5120: /* module 20 call 0 */
        return 2;
    case 5121: /* module 20 call 1 */
        return 2;
    case 5122: /* module 20 call 2 */
        return 0;
    case 5123: /* module 20 call 3 */
        return 3;
    case 5124: /* module 20 call 4 */
        return 3;
    case 5125: /* module 20 call 5 */
        return 3;
    case 5376: /* module 21 call 0 */
        return 1;
    case 5377: /* module 21 call 1 */
        return 1;
    case 5378: /* module 21 call 2 */
        return 1;
    case 5379: /* module 21 call 3 */
        return 0;
    case 5380: /* module 21 call 4 */
        return 2;
    case 5381: /* module 21 call 5 */
        return 1;
    case 5382: /* module 21 call 6 */
        return 2;
    case 5383: /* module 21 call 7 */
        return 2;
    case 5384: /* module 21 call 8 */
        return 2;
    case 5385: /* module 21 call 9 */
        return 3;
    case 5386: /* module 21 call 10 */
        return 1;
    case 5387: /* module 21 call 11 */
        return 2;
    case 5388: /* module 21 call 12 */
        return 2;
    case 5389: /* module 21 call 13 */
        return 1;
    case 5390: /* module 21 call 14 */
        return 0;
    case 5632: /* module 22 call 0 */
        return 3;
    case 5633: /* module 22 call 1 */
        return 4;
    case 5634: /* module 22 call 2 */
        return 3;
    case 5635: /* module 22 call 3 */
        return 4;
    case 5636: /* module 22 call 4 */
        return 2;
    case 5888: /* module 23 call 0 */
        return 1;
    case 5889: /* module 23 call 1 */
        return 2;
    case 5890: /* module 23 call 2 */
        return 1;
    case 5891: /* module 23 call 3 */
        return 1;
    case 5892: /* module 23 call 4 */
        return 1;
    case 5893: /* module 23 call 5 */
        return 1;
    case 5894: /* module 23 call 6 */
        return 4;
    case 5895: /* module 23 call 7 */
        return 4;
    case 5896: /* module 23 call 8 */
        return 3;
    case 6144: /* module 24 call 0 */
        return 1;
    case 6145: /* module 24 call 1 */
        return 2;
    case 6146: /* module 24 call 2 */
        return 1;
    case 6147: /* module 24 call 3 */
        return 3;
    case 6148: /* module 24 call 4 */
        return 1;
    case 6400: /* module 25 call 0 */
        return 4;
    case 6401: /* module 25 call 1 */
        return 2;
    case 6402: /* module 25 call 2 */
        return 5;
    case 6403: /* module 25 call 3 */
        return 1;
    case 6404: /* module 25 call 4 */
        return 4;
    case 6405: /* module 25 call 5 */
        return 5;
    case 6656: /* module 26 call 0 */
        return 3;
    case 6657: /* module 26 call 1 */
        return 2;
    case 6658: /* module 26 call 2 */
        return 2;
    case 6659: /* module 26 call 3 */
        return 0;
    case 6660: /* module 26 call 4 */
        return 2;
    case 6661: /* module 26 call 5 */
        return 5;
    case 6912: /* module 27 call 0 */
        return 2;
    case 6913: /* module 27 call 1 */
        return 6;
    case 6914: /* module 27 call 2 */
        return 5;
    case 6915: /* module 27 call 3 */
        return 4;
    case 7168: /* module 28 call 0 */
        return 3;
    case 7169: /* module 28 call 1 */
        return 1;
    case 7170: /* module 28 call 2 */
        return 1;
    case 7424: /* module 29 call 0 */
        return 0;
    case 7425: /* module 29 call 1 */
        return 1;
    case 7426: /* module 29 call 2 */
        return 2;
    case 7427: /* module 29 call 3 */
        return 3;
    case 7680: /* module 30 call 0 */
        return 1;
    case 7681: /* module 30 call 1 */
        return 5;
    case 7936: /* module 31 call 0 */
        return 3;
    case 8192: /* module 32 call 0 */
        return 2;
    case 8193: /* module 32 call 1 */
        return 1;
    default:
        return 0;
    }

    return 0;
}

const char* _getMethod_ItemName_V1(uint8_t moduleIdx, uint8_t callIdx, uint8_t itemIdx)
{
    uint16_t callPrivIdx = ((uint16_t)moduleIdx << 8u) + callIdx;

    switch (callPrivIdx) {
    case 0: /* module 0 call 0 */
        switch (itemIdx) {
        case 0:
            return "Ratio";
        default:
            return NULL;
        }
    case 1: /* module 0 call 1 */
        switch (itemIdx) {
        case 0:
            return "Remark";
        default:
            return NULL;
        }
    case 2: /* module 0 call 2 */
        switch (itemIdx) {
        case 0:
            return "Pages";
        default:
            return NULL;
        }
    case 3: /* module 0 call 3 */
        switch (itemIdx) {
        case 0:
            return "Code";
        default:
            return NULL;
        }
    case 4: /* module 0 call 4 */
        switch (itemIdx) {
        case 0:
            return "Code";
        default:
            return NULL;
        }
    case 5: /* module 0 call 5 */
        switch (itemIdx) {
        case 0:
            return "Changes trie config";
        default:
            return NULL;
        }
    case 6: /* module 0 call 6 */
        switch (itemIdx) {
        case 0:
            return "Items";
        default:
            return NULL;
        }
    case 7: /* module 0 call 7 */
        switch (itemIdx) {
        case 0:
            return "Keys";
        default:
            return NULL;
        }
    case 8: /* module 0 call 8 */
        switch (itemIdx) {
        case 0:
            return "Prefix";
        case 1:
            return "Subkeys";
        default:
            return NULL;
        }
    case 9: /* module 0 call 9 */
        switch (itemIdx) {
        default:
            return NULL;
        }
    case 256: /* module 1 call 0 */
        switch (itemIdx) {
        case 0:
            return "Calls";
        default:
            return NULL;
        }
    case 257: /* module 1 call 1 */
        switch (itemIdx) {
        case 0:
            return "Index";
        case 1:
            return "Call";
        default:
            return NULL;
        }
    case 512: /* module 2 call 0 */
        switch (itemIdx) {
        case 0:
            return "Equivocation proof";
        case 1:
            return "Key owner proof";
        default:
            return NULL;
        }
    case 513: /* module 2 call 1 */
        switch (itemIdx) {
        case 0:
            return "Equivocation proof";
        case 1:
            return "Key owner proof";
        default:
            return NULL;
        }
    case 768: /* module 3 call 0 */
        switch (itemIdx) {
        case 0:
            return "Now";
        default:
            return NULL;
        }
    case 1024: /* module 4 call 0 */
        switch (itemIdx) {
        case 0:
            return "New uncles";
        default:
            return NULL;
        }
    case 1280: /* module 5 call 0 */
        switch (itemIdx) {
        case 0:
            return "Dest";
        case 1:
            return "Amount";
        default:
            return NULL;
        }
    case 1281: /* module 5 call 1 */
        switch (itemIdx) {
        case 0:
            return "Who";
        case 1:
            return "New free";
        case 2:
            return "New reserved";
        default:
            return NULL;
        }
    case 1282: /* module 5 call 2 */
        switch (itemIdx) {
        case 0:
            return "Source";
        case 1:
            return "Dest";
        case 2:
            return "Amount";
        default:
            return NULL;
        }
    case 1283: /* module 5 call 3 */
        switch (itemIdx) {
        case 0:
            return "Dest";
        case 1:
            return "Amount";
        default:
            return NULL;
        }
    case 1536: /* module 6 call 0 */
        switch (itemIdx) {
        case 0:
            return "Controller";
        case 1:
            return "Amount";
        case 2:
            return "Payee";
        default:
            return NULL;
        }
    case 1537: /* module 6 call 1 */
        switch (itemIdx) {
        case 0:
            return "Amount";
        default:
            return NULL;
        }
    case 1538: /* module 6 call 2 */
        switch (itemIdx) {
        case 0:
            return "Amount";
        default:
            return NULL;
        }
    case 1539: /* module 6 call 3 */
        switch (itemIdx) {
        case 0:
            return "Num slashing spans";
        default:
            return NULL;
        }
    case 1540: /* module 6 call 4 */
        switch (itemIdx) {
        case 0:
            return "Prefs";
        default:
            return NULL;
        }
    case 1541: /* module 6 call 5 */
        switch (itemIdx) {
        case 0:
            return "Targets";
        default:
            return NULL;
        }
    case 1542: /* module 6 call 6 */
        switch (itemIdx) {
        default:
            return NULL;
        }
    case 1543: /* module 6 call 7 */
        switch (itemIdx) {
        case 0:
            return "Payee";
        default:
            return NULL;
        }
    case 1544: /* module 6 call 8 */
        switch (itemIdx) {
        case 0:
            return "Controller";
        default:
            return NULL;
        }
    case 1545: /* module 6 call 9 */
        switch (itemIdx) {
        case 0:
            return "New";
        default:
            return NULL;
        }
    case 1546: /* module 6 call 10 */
        switch (itemIdx) {
        case 0:
            return "Additional";
        default:
            return NULL;
        }
    case 1547: /* module 6 call 11 */
        switch (itemIdx) {
        case 0:
            return "Factor";
        default:
            return NULL;
        }
    case 1548: /* module 6 call 12 */
        switch (itemIdx) {
        default:
            return NULL;
        }
    case 1549: /* module 6 call 13 */
        switch (itemIdx) {
        default:
            return NULL;
        }
    case 1550: /* module 6 call 14 */
        switch (itemIdx) {
        case 0:
            return "Validators";
        default:
            return NULL;
        }
    case 1551: /* module 6 call 15 */
        switch (itemIdx) {
        case 0:
            return "Stash";
        case 1:
            return "Num slashing spans";
        default:
            return NULL;
        }
    case 1552: /* module 6 call 16 */
        switch (itemIdx) {
        default:
            return NULL;
        }
    case 1553: /* module 6 call 17 */
        switch (itemIdx) {
        case 0:
            return "Era";
        case 1:
            return "Slash indices";
        default:
            return NULL;
        }
    case 1554: /* module 6 call 18 */
        switch (itemIdx) {
        case 0:
            return "Validator stash";
        case 1:
            return "Era";
        default:
            return NULL;
        }
    case 1555: /* module 6 call 19 */
        switch (itemIdx) {
        case 0:
            return "Amount";
        default:
            return NULL;
        }
    case 1556: /* module 6 call 20 */
        switch (itemIdx) {
        case 0:
            return "New history depth";
        case 1:
            return "Era items deleted";
        default:
            return NULL;
        }
    case 1557: /* module 6 call 21 */
        switch (itemIdx) {
        case 0:
            return "Stash";
        case 1:
            return "Num slashing spans";
        default:
            return NULL;
        }
    case 1558: /* module 6 call 22 */
        switch (itemIdx) {
        case 0:
            return "Winners";
        case 1:
            return "Compact";
        case 2:
            return "Score";
        case 3:
            return "Era";
        case 4:
            return "Size";
        default:
            return NULL;
        }
    case 1559: /* module 6 call 23 */
        switch (itemIdx) {
        case 0:
            return "Winners";
        case 1:
            return "Compact";
        case 2:
            return "Score";
        case 3:
            return "Era";
        case 4:
            return "Size";
        default:
            return NULL;
        }
    case 1792: /* module 7 call 0 */
        switch (itemIdx) {
        case 0:
            return "Keys";
        case 1:
            return "Proof";
        default:
            return NULL;
        }
    case 1793: /* module 7 call 1 */
        switch (itemIdx) {
        default:
            return NULL;
        }
    case 2048: /* module 8 call 0 */
        switch (itemIdx) {
        case 0:
            return "Proposal hash";
        case 1:
            return "Amount";
        default:
            return NULL;
        }
    case 2049: /* module 8 call 1 */
        switch (itemIdx) {
        case 0:
            return "Proposal";
        case 1:
            return "Seconds upper bound";
        default:
            return NULL;
        }
    case 2050: /* module 8 call 2 */
        switch (itemIdx) {
        case 0:
            return "Ref index";
        case 1:
            return "Vote";
        default:
            return NULL;
        }
    case 2051: /* module 8 call 3 */
        switch (itemIdx) {
        case 0:
            return "Ref index";
        default:
            return NULL;
        }
    case 2052: /* module 8 call 4 */
        switch (itemIdx) {
        case 0:
            return "Proposal hash";
        default:
            return NULL;
        }
    case 2053: /* module 8 call 5 */
        switch (itemIdx) {
        case 0:
            return "Proposal hash";
        default:
            return NULL;
        }
    case 2054: /* module 8 call 6 */
        switch (itemIdx) {
        case 0:
            return "Proposal hash";
        default:
            return NULL;
        }
    case 2055: /* module 8 call 7 */
        switch (itemIdx) {
        case 0:
            return "Proposal hash";
        case 1:
            return "Voting period";
        case 2:
            return "Delay";
        default:
            return NULL;
        }
    case 2056: /* module 8 call 8 */
        switch (itemIdx) {
        case 0:
            return "Proposal hash";
        default:
            return NULL;
        }
    case 2057: /* module 8 call 9 */
        switch (itemIdx) {
        case 0:
            return "Ref index";
        default:
            return NULL;
        }
    case 2058: /* module 8 call 10 */
        switch (itemIdx) {
        case 0:
            return "Which";
        default:
            return NULL;
        }
    case 2059: /* module 8 call 11 */
        switch (itemIdx) {
        case 0:
            return "To";
        case 1:
            return "Conviction";
        case 2:
            return "Balance";
        default:
            return NULL;
        }
    case 2060: /* module 8 call 12 */
        switch (itemIdx) {
        default:
            return NULL;
        }
    case 2061: /* module 8 call 13 */
        switch (itemIdx) {
        default:
            return NULL;
        }
    case 2062: /* module 8 call 14 */
        switch (itemIdx) {
        case 0:
            return "Encoded proposal";
        default:
            return NULL;
        }
    case 2063: /* module 8 call 15 */
        switch (itemIdx) {
        case 0:
            return "Encoded proposal";
        default:
            return NULL;
        }
    case 2064: /* module 8 call 16 */
        switch (itemIdx) {
        case 0:
            return "Encoded proposal";
        default:
            return NULL;
        }
    case 2065: /* module 8 call 17 */
        switch (itemIdx) {
        case 0:
            return "Encoded proposal";
        default:
            return NULL;
        }
    case 2066: /* module 8 call 18 */
        switch (itemIdx) {
        case 0:
            return "Proposal hash";
        case 1:
            return "Proposal len upper bound";
        default:
            return NULL;
        }
    case 2067: /* module 8 call 19 */
        switch (itemIdx) {
        case 0:
            return "Target";
        default:
            return NULL;
        }
    case 2068: /* module 8 call 20 */
        switch (itemIdx) {
        case 0:
            return "Index";
        default:
            return NULL;
        }
    case 2069: /* module 8 call 21 */
        switch (itemIdx) {
        case 0:
            return "Target";
        case 1:
            return "Index";
        default:
            return NULL;
        }
    case 2070: /* module 8 call 22 */
        switch (itemIdx) {
        case 0:
            return "Proposal hash";
        case 1:
            return "Index";
        default:
            return NULL;
        }
    case 2304: /* module 9 call 0 */
        switch (itemIdx) {
        case 0:
            return "New members";
        case 1:
            return "Prime";
        case 2:
            return "Old count";
        default:
            return NULL;
        }
    case 2305: /* module 9 call 1 */
        switch (itemIdx) {
        case 0:
            return "Proposal";
        case 1:
            return "Length bound";
        default:
            return NULL;
        }
    case 2306: /* module 9 call 2 */
        switch (itemIdx) {
        case 0:
            return "Threshold";
        case 1:
            return "Proposal";
        case 2:
            return "Length bound";
        default:
            return NULL;
        }
    case 2307: /* module 9 call 3 */
        switch (itemIdx) {
        case 0:
            return "Proposal";
        case 1:
            return "Index";
        case 2:
            return "Approve";
        default:
            return NULL;
        }
    case 2308: /* module 9 call 4 */
        switch (itemIdx) {
        case 0:
            return "Proposal hash";
        case 1:
            return "Index";
        case 2:
            return "Proposal weight bound";
        case 3:
            return "Length bound";
        default:
            return NULL;
        }
    case 2309: /* module 9 call 5 */
        switch (itemIdx) {
        case 0:
            return "Proposal hash";
        default:
            return NULL;
        }
    case 2560: /* module 10 call 0 */
        switch (itemIdx) {
        case 0:
            return "Votes";
        case 1:
            return "Amount";
        default:
            return NULL;
        }
    case 2561: /* module 10 call 1 */
        switch (itemIdx) {
        default:
            return NULL;
        }
    case 2562: /* module 10 call 2 */
        switch (itemIdx) {
        case 0:
            return "Defunct";
        default:
            return NULL;
        }
    case 2563: /* module 10 call 3 */
        switch (itemIdx) {
        case 0:
            return "Candidate count";
        default:
            return NULL;
        }
    case 2564: /* module 10 call 4 */
        switch (itemIdx) {
        case 0:
            return "Renouncing";
        default:
            return NULL;
        }
    case 2565: /* module 10 call 5 */
        switch (itemIdx) {
        case 0:
            return "Who";
        case 1:
            return "Has replacement";
        default:
            return NULL;
        }
    case 2816: /* module 11 call 0 */
        switch (itemIdx) {
        case 0:
            return "Hint";
        default:
            return NULL;
        }
    case 3072: /* module 12 call 0 */
        switch (itemIdx) {
        case 0:
            return "Equivocation proof";
        case 1:
            return "Key owner proof";
        default:
            return NULL;
        }
    case 3073: /* module 12 call 1 */
        switch (itemIdx) {
        case 0:
            return "Equivocation proof";
        case 1:
            return "Key owner proof";
        default:
            return NULL;
        }
    case 3074: /* module 12 call 2 */
        switch (itemIdx) {
        case 0:
            return "Delay";
        case 1:
            return "Best finalized block number";
        default:
            return NULL;
        }
    case 3328: /* module 13 call 0 */
        switch (itemIdx) {
        case 0:
            return "Heartbeat";
        case 1:
            return "Signature";
        default:
            return NULL;
        }
    case 4352: /* module 17 call 0 */
        switch (itemIdx) {
        case 0:
            return "Anchor id";
        case 1:
            return "Signing root";
        default:
            return NULL;
        }
    case 4353: /* module 17 call 1 */
        switch (itemIdx) {
        case 0:
            return "Anchor id preimage";
        case 1:
            return "Doc root";
        case 2:
            return "Proof";
        case 3:
            return "Stored until date";
        default:
            return NULL;
        }
    case 4354: /* module 17 call 2 */
        switch (itemIdx) {
        case 0:
            return "Evict bucket";
        default:
            return NULL;
        }
    case 4355: /* module 17 call 3 */
        switch (itemIdx) {
        default:
            return NULL;
        }
    case 4608: /* module 18 call 0 */
        switch (itemIdx) {
        case 0:
            return "Key";
        case 1:
            return "New price";
        default:
            return NULL;
        }
    case 4864: /* module 19 call 0 */
        switch (itemIdx) {
        case 0:
            return "Anchor id";
        case 1:
            return "Deposit address";
        case 2:
            return "Pfs";
        case 3:
            return "Static proofs";
        case 4:
            return "Dest id";
        default:
            return NULL;
        }
    case 5120: /* module 20 call 0 */
        switch (itemIdx) {
        case 0:
            return "Threshold";
        case 1:
            return "Other signatories";
        default:
            return NULL;
        }
    case 5121: /* module 20 call 1 */
        switch (itemIdx) {
        case 0:
            return "Threshold";
        case 1:
            return "Signatories";
        default:
            return NULL;
        }
    case 5122: /* module 20 call 2 */
        switch (itemIdx) {
        default:
            return NULL;
        }
    case 5123: /* module 20 call 3 */
        switch (itemIdx) {
        case 0:
            return "Multi account id";
        case 1:
            return "Maybe timepoint";
        case 2:
            return "Call";
        default:
            return NULL;
        }
    case 5124: /* module 20 call 4 */
        switch (itemIdx) {
        case 0:
            return "Multi account id";
        case 1:
            return "Maybe timepoint";
        case 2:
            return "Call hash";
        default:
            return NULL;
        }
    case 5125: /* module 20 call 5 */
        switch (itemIdx) {
        case 0:
            return "Multi account id";
        case 1:
            return "Timepoint";
        case 2:
            return "Call hash";
        default:
            return NULL;
        }
    case 5376: /* module 21 call 0 */
        switch (itemIdx) {
        case 0:
            return "Account";
        default:
            return NULL;
        }
    case 5377: /* module 21 call 1 */
        switch (itemIdx) {
        case 0:
            return "Info";
        default:
            return NULL;
        }
    case 5378: /* module 21 call 2 */
        switch (itemIdx) {
        case 0:
            return "Subs";
        default:
            return NULL;
        }
    case 5379: /* module 21 call 3 */
        switch (itemIdx) {
        default:
            return NULL;
        }
    case 5380: /* module 21 call 4 */
        switch (itemIdx) {
        case 0:
            return "Reg index";
        case 1:
            return "Max fee";
        default:
            return NULL;
        }
    case 5381: /* module 21 call 5 */
        switch (itemIdx) {
        case 0:
            return "Reg index";
        default:
            return NULL;
        }
    case 5382: /* module 21 call 6 */
        switch (itemIdx) {
        case 0:
            return "Index";
        case 1:
            return "Fee";
        default:
            return NULL;
        }
    case 5383: /* module 21 call 7 */
        switch (itemIdx) {
        case 0:
            return "Index";
        case 1:
            return "New";
        default:
            return NULL;
        }
    case 5384: /* module 21 call 8 */
        switch (itemIdx) {
        case 0:
            return "Index";
        case 1:
            return "Fields";
        default:
            return NULL;
        }
    case 5385: /* module 21 call 9 */
        switch (itemIdx) {
        case 0:
            return "Reg index";
        case 1:
            return "Target";
        case 2:
            return "Judgement";
        default:
            return NULL;
        }
    case 5386: /* module 21 call 10 */
        switch (itemIdx) {
        case 0:
            return "Target";
        default:
            return NULL;
        }
    case 5387: /* module 21 call 11 */
        switch (itemIdx) {
        case 0:
            return "Sub";
        case 1:
            return "Data";
        default:
            return NULL;
        }
    case 5388: /* module 21 call 12 */
        switch (itemIdx) {
        case 0:
            return "Sub";
        case 1:
            return "Data";
        default:
            return NULL;
        }
    case 5389: /* module 21 call 13 */
        switch (itemIdx) {
        case 0:
            return "Sub";
        default:
            return NULL;
        }
    case 5390: /* module 21 call 14 */
        switch (itemIdx) {
        default:
            return NULL;
        }
    case 5632: /* module 22 call 0 */
        switch (itemIdx) {
        case 0:
            return "Amount";
        case 1:
            return "Recipient";
        case 2:
            return "Dest id";
        default:
            return NULL;
        }
    case 5633: /* module 22 call 1 */
        switch (itemIdx) {
        case 0:
            return "Recipient";
        case 1:
            return "From registry";
        case 2:
            return "Token id";
        case 3:
            return "Dest id";
        default:
            return NULL;
        }
    case 5634: /* module 22 call 2 */
        switch (itemIdx) {
        case 0:
            return "To";
        case 1:
            return "Amount";
        case 2:
            return "R id";
        default:
            return NULL;
        }
    case 5635: /* module 22 call 3 */
        switch (itemIdx) {
        case 0:
            return "To";
        case 1:
            return "Token id";
        case 2:
            return "Metadata";
        case 3:
            return "Resource id";
        default:
            return NULL;
        }
    case 5636: /* module 22 call 4 */
        switch (itemIdx) {
        case 0:
            return "Hash";
        case 1:
            return "R id";
        default:
            return NULL;
        }
    case 5888: /* module 23 call 0 */
        switch (itemIdx) {
        case 0:
            return "Threshold";
        default:
            return NULL;
        }
    case 5889: /* module 23 call 1 */
        switch (itemIdx) {
        case 0:
            return "Id";
        case 1:
            return "Method";
        default:
            return NULL;
        }
    case 5890: /* module 23 call 2 */
        switch (itemIdx) {
        case 0:
            return "Id";
        default:
            return NULL;
        }
    case 5891: /* module 23 call 3 */
        switch (itemIdx) {
        case 0:
            return "Id";
        default:
            return NULL;
        }
    case 5892: /* module 23 call 4 */
        switch (itemIdx) {
        case 0:
            return "V";
        default:
            return NULL;
        }
    case 5893: /* module 23 call 5 */
        switch (itemIdx) {
        case 0:
            return "V";
        default:
            return NULL;
        }
    case 5894: /* module 23 call 6 */
        switch (itemIdx) {
        case 0:
            return "Nonce";
        case 1:
            return "Src id";
        case 2:
            return "R id";
        case 3:
            return "Call";
        default:
            return NULL;
        }
    case 5895: /* module 23 call 7 */
        switch (itemIdx) {
        case 0:
            return "Nonce";
        case 1:
            return "Src id";
        case 2:
            return "R id";
        case 3:
            return "Call";
        default:
            return NULL;
        }
    case 5896: /* module 23 call 8 */
        switch (itemIdx) {
        case 0:
            return "Nonce";
        case 1:
            return "Src id";
        case 2:
            return "Prop";
        default:
            return NULL;
        }
    case 6144: /* module 24 call 0 */
        switch (itemIdx) {
        case 0:
            return "Index";
        default:
            return NULL;
        }
    case 6145: /* module 24 call 1 */
        switch (itemIdx) {
        case 0:
            return "New";
        case 1:
            return "Index";
        default:
            return NULL;
        }
    case 6146: /* module 24 call 2 */
        switch (itemIdx) {
        case 0:
            return "Index";
        default:
            return NULL;
        }
    case 6147: /* module 24 call 3 */
        switch (itemIdx) {
        case 0:
            return "New";
        case 1:
            return "Index";
        case 2:
            return "Freeze";
        default:
            return NULL;
        }
    case 6148: /* module 24 call 4 */
        switch (itemIdx) {
        case 0:
            return "Index";
        default:
            return NULL;
        }
    case 6400: /* module 25 call 0 */
        switch (itemIdx) {
        case 0:
            return "When";
        case 1:
            return "Maybe periodic";
        case 2:
            return "Priority";
        case 3:
            return "Call";
        default:
            return NULL;
        }
    case 6401: /* module 25 call 1 */
        switch (itemIdx) {
        case 0:
            return "When";
        case 1:
            return "Index";
        default:
            return NULL;
        }
    case 6402: /* module 25 call 2 */
        switch (itemIdx) {
        case 0:
            return "Id";
        case 1:
            return "When";
        case 2:
            return "Maybe periodic";
        case 3:
            return "Priority";
        case 4:
            return "Call";
        default:
            return NULL;
        }
    case 6403: /* module 25 call 3 */
        switch (itemIdx) {
        case 0:
            return "Id";
        default:
            return NULL;
        }
    case 6404: /* module 25 call 4 */
        switch (itemIdx) {
        case 0:
            return "After";
        case 1:
            return "Maybe periodic";
        case 2:
            return "Priority";
        case 3:
            return "Call";
        default:
            return NULL;
        }
    case 6405: /* module 25 call 5 */
        switch (itemIdx) {
        case 0:
            return "Id";
        case 1:
            return "After";
        case 2:
            return "Maybe periodic";
        case 3:
            return "Priority";
        case 4:
            return "Call";
        default:
            return NULL;
        }
    case 6656: /* module 26 call 0 */
        switch (itemIdx) {
        case 0:
            return "Real";
        case 1:
            return "Force proxy type";
        case 2:
            return "Call";
        default:
            return NULL;
        }
    case 6657: /* module 26 call 1 */
        switch (itemIdx) {
        case 0:
            return "Proxy";
        case 1:
            return "Proxy type";
        default:
            return NULL;
        }
    case 6658: /* module 26 call 2 */
        switch (itemIdx) {
        case 0:
            return "Proxy";
        case 1:
            return "Proxy type";
        default:
            return NULL;
        }
    case 6659: /* module 26 call 3 */
        switch (itemIdx) {
        default:
            return NULL;
        }
    case 6660: /* module 26 call 4 */
        switch (itemIdx) {
        case 0:
            return "Proxy type";
        case 1:
            return "Index";
        default:
            return NULL;
        }
    case 6661: /* module 26 call 5 */
        switch (itemIdx) {
        case 0:
            return "Spawner";
        case 1:
            return "Proxy type";
        case 2:
            return "Index";
        case 3:
            return "Height";
        case 4:
            return "Ext index";
        default:
            return NULL;
        }
    case 6912: /* module 27 call 0 */
        switch (itemIdx) {
        case 0:
            return "Other signatories";
        case 1:
            return "Call";
        default:
            return NULL;
        }
    case 6913: /* module 27 call 1 */
        switch (itemIdx) {
        case 0:
            return "Threshold";
        case 1:
            return "Other signatories";
        case 2:
            return "Maybe timepoint";
        case 3:
            return "Call";
        case 4:
            return "Store call";
        case 5:
            return "Max weight";
        default:
            return NULL;
        }
    case 6914: /* module 27 call 2 */
        switch (itemIdx) {
        case 0:
            return "Threshold";
        case 1:
            return "Other signatories";
        case 2:
            return "Maybe timepoint";
        case 3:
            return "Call hash";
        case 4:
            return "Max weight";
        default:
            return NULL;
        }
    case 6915: /* module 27 call 3 */
        switch (itemIdx) {
        case 0:
            return "Threshold";
        case 1:
            return "Other signatories";
        case 2:
            return "Timepoint";
        case 3:
            return "Call hash";
        default:
            return NULL;
        }
    case 7168: /* module 28 call 0 */
        switch (itemIdx) {
        case 0:
            return "Account id";
        case 1:
            return "Amount";
        case 2:
            return "Sorted hashes";
        default:
            return NULL;
        }
    case 7169: /* module 28 call 1 */
        switch (itemIdx) {
        case 0:
            return "Account id";
        default:
            return NULL;
        }
    case 7170: /* module 28 call 2 */
        switch (itemIdx) {
        case 0:
            return "Root hash";
        default:
            return NULL;
        }
    case 7424: /* module 29 call 0 */
        switch (itemIdx) {
        default:
            return NULL;
        }
    case 7425: /* module 29 call 1 */
        switch (itemIdx) {
        case 0:
            return "Target";
        default:
            return NULL;
        }
    case 7426: /* module 29 call 2 */
        switch (itemIdx) {
        case 0:
            return "Target";
        case 1:
            return "Schedule";
        default:
            return NULL;
        }
    case 7427: /* module 29 call 3 */
        switch (itemIdx) {
        case 0:
            return "Source";
        case 1:
            return "Target";
        case 2:
            return "Schedule";
        default:
            return NULL;
        }
    case 7680: /* module 30 call 0 */
        switch (itemIdx) {
        case 0:
            return "Info";
        default:
            return NULL;
        }
    case 7681: /* module 30 call 1 */
        switch (itemIdx) {
        case 0:
            return "Owner account";
        case 1:
            return "Registry id";
        case 2:
            return "Token id";
        case 3:
            return "Asset info";
        case 4:
            return "Mint info";
        default:
            return NULL;
        }
    case 7936: /* module 31 call 0 */
        switch (itemIdx) {
        case 0:
            return "Dest account";
        case 1:
            return "Registry id";
        case 2:
            return "Token id";
        default:
            return NULL;
        }
    case 8192: /* module 32 call 0 */
        switch (itemIdx) {
        case 0:
            return "Rid";
        case 1:
            return "Local addr";
        default:
            return NULL;
        }
    case 8193: /* module 32 call 1 */
        switch (itemIdx) {
        case 0:
            return "Rid";
        default:
            return NULL;
        }
    default:
        return NULL;
    }

    return NULL;
}

parser_error_t _getMethod_ItemValue_V1(
    pd_Method_V1_t* m,
    uint8_t moduleIdx, uint8_t callIdx, uint8_t itemIdx,
    char* outValue, uint16_t outValueLen,
    uint8_t pageIdx, uint8_t* pageCount)
{
    uint16_t callPrivIdx = ((uint16_t)moduleIdx << 8u) + callIdx;

    switch (callPrivIdx) {
    case 0: /* module 0 call 0 */
        switch (itemIdx) {
        case 0: /* system_fill_block_V1 - _ratio */;
            return _toStringPerbill_V1(
                &m->basic.system_fill_block_V1._ratio,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1: /* module 0 call 1 */
        switch (itemIdx) {
        case 0: /* system_remark_V1 - _remark */;
            return _toStringBytes(
                &m->basic.system_remark_V1._remark,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 2: /* module 0 call 2 */
        switch (itemIdx) {
        case 0: /* system_set_heap_pages_V1 - pages */;
            return _toStringu64(
                &m->basic.system_set_heap_pages_V1.pages,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 3: /* module 0 call 3 */
        switch (itemIdx) {
        case 0: /* system_set_code_V1 - code */;
            return _toStringBytes(
                &m->basic.system_set_code_V1.code,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 4: /* module 0 call 4 */
        switch (itemIdx) {
        case 0: /* system_set_code_without_checks_V1 - code */;
            return _toStringBytes(
                &m->basic.system_set_code_without_checks_V1.code,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 5: /* module 0 call 5 */
        switch (itemIdx) {
        case 0: /* system_set_changes_trie_config_V1 - changes_trie_config */;
            return _toStringOptionChangesTrieConfiguration_V1(
                &m->basic.system_set_changes_trie_config_V1.changes_trie_config,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 6: /* module 0 call 6 */
        switch (itemIdx) {
        case 0: /* system_set_storage_V1 - items */;
            return _toStringVecKeyValue_V1(
                &m->basic.system_set_storage_V1.items,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 7: /* module 0 call 7 */
        switch (itemIdx) {
        case 0: /* system_kill_storage_V1 - keys */;
            return _toStringVecKey_V1(
                &m->basic.system_kill_storage_V1.keys,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 8: /* module 0 call 8 */
        switch (itemIdx) {
        case 0: /* system_kill_prefix_V1 - prefix */;
            return _toStringKey_V1(
                &m->basic.system_kill_prefix_V1.prefix,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* system_kill_prefix_V1 - _subkeys */;
            return _toStringu32(
                &m->basic.system_kill_prefix_V1._subkeys,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 9: /* module 0 call 9 */
        switch (itemIdx) {
        default:
            return parser_no_data;
        }
    case 256: /* module 1 call 0 */
        switch (itemIdx) {
        case 0: /* utility_batch_V1 - calls */;
            return _toStringVecCall(
                &m->basic.utility_batch_V1.calls,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 257: /* module 1 call 1 */
        switch (itemIdx) {
        case 0: /* utility_as_derivative_V1 - index */;
            return _toStringu16(
                &m->basic.utility_as_derivative_V1.index,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* utility_as_derivative_V1 - call */;
            return _toStringCall(
                &m->basic.utility_as_derivative_V1.call,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 512: /* module 2 call 0 */
        switch (itemIdx) {
        case 0: /* babe_report_equivocation_V1 - equivocation_proof */;
            return _toStringEquivocationProof_V1(
                &m->basic.babe_report_equivocation_V1.equivocation_proof,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* babe_report_equivocation_V1 - key_owner_proof */;
            return _toStringKeyOwnerProof_V1(
                &m->basic.babe_report_equivocation_V1.key_owner_proof,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 513: /* module 2 call 1 */
        switch (itemIdx) {
        case 0: /* babe_report_equivocation_unsigned_V1 - equivocation_proof */;
            return _toStringEquivocationProof_V1(
                &m->basic.babe_report_equivocation_unsigned_V1.equivocation_proof,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* babe_report_equivocation_unsigned_V1 - key_owner_proof */;
            return _toStringKeyOwnerProof_V1(
                &m->basic.babe_report_equivocation_unsigned_V1.key_owner_proof,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 768: /* module 3 call 0 */
        switch (itemIdx) {
        case 0: /* timestamp_set_V1 - now */;
            return _toStringCompactMoment_V1(
                &m->basic.timestamp_set_V1.now,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1024: /* module 4 call 0 */
        switch (itemIdx) {
        case 0: /* authorship_set_uncles_V1 - new_uncles */;
            return _toStringVecHeader(
                &m->basic.authorship_set_uncles_V1.new_uncles,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1280: /* module 5 call 0 */
        switch (itemIdx) {
        case 0: /* balances_transfer_V1 - dest */;
            return _toStringLookupSource_V1(
                &m->basic.balances_transfer_V1.dest,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* balances_transfer_V1 - value */;
            return _toStringCompactBalance(
                &m->basic.balances_transfer_V1.value,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1281: /* module 5 call 1 */
        switch (itemIdx) {
        case 0: /* balances_set_balance_V1 - who */;
            return _toStringLookupSource_V1(
                &m->basic.balances_set_balance_V1.who,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* balances_set_balance_V1 - new_free */;
            return _toStringCompactBalance(
                &m->basic.balances_set_balance_V1.new_free,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* balances_set_balance_V1 - new_reserved */;
            return _toStringCompactBalance(
                &m->basic.balances_set_balance_V1.new_reserved,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1282: /* module 5 call 2 */
        switch (itemIdx) {
        case 0: /* balances_force_transfer_V1 - source */;
            return _toStringLookupSource_V1(
                &m->basic.balances_force_transfer_V1.source,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* balances_force_transfer_V1 - dest */;
            return _toStringLookupSource_V1(
                &m->basic.balances_force_transfer_V1.dest,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* balances_force_transfer_V1 - value */;
            return _toStringCompactBalance(
                &m->basic.balances_force_transfer_V1.value,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1283: /* module 5 call 3 */
        switch (itemIdx) {
        case 0: /* balances_transfer_keep_alive_V1 - dest */;
            return _toStringLookupSource_V1(
                &m->basic.balances_transfer_keep_alive_V1.dest,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* balances_transfer_keep_alive_V1 - value */;
            return _toStringCompactBalance(
                &m->basic.balances_transfer_keep_alive_V1.value,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1536: /* module 6 call 0 */
        switch (itemIdx) {
        case 0: /* staking_bond_V1 - controller */;
            return _toStringLookupSource_V1(
                &m->basic.staking_bond_V1.controller,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* staking_bond_V1 - value */;
            return _toStringCompactBalanceOf(
                &m->basic.staking_bond_V1.value,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* staking_bond_V1 - payee */;
            return _toStringRewardDestination_V1(
                &m->basic.staking_bond_V1.payee,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1537: /* module 6 call 1 */
        switch (itemIdx) {
        case 0: /* staking_bond_extra_V1 - max_additional */;
            return _toStringCompactBalanceOf(
                &m->basic.staking_bond_extra_V1.max_additional,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1538: /* module 6 call 2 */
        switch (itemIdx) {
        case 0: /* staking_unbond_V1 - value */;
            return _toStringCompactBalanceOf(
                &m->basic.staking_unbond_V1.value,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1539: /* module 6 call 3 */
        switch (itemIdx) {
        case 0: /* staking_withdraw_unbonded_V1 - num_slashing_spans */;
            return _toStringu32(
                &m->basic.staking_withdraw_unbonded_V1.num_slashing_spans,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1540: /* module 6 call 4 */
        switch (itemIdx) {
        case 0: /* staking_validate_V1 - prefs */;
            return _toStringValidatorPrefs_V1(
                &m->basic.staking_validate_V1.prefs,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1541: /* module 6 call 5 */
        switch (itemIdx) {
        case 0: /* staking_nominate_V1 - targets */;
            return _toStringVecLookupSource_V1(
                &m->basic.staking_nominate_V1.targets,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1542: /* module 6 call 6 */
        switch (itemIdx) {
        default:
            return parser_no_data;
        }
    case 1543: /* module 6 call 7 */
        switch (itemIdx) {
        case 0: /* staking_set_payee_V1 - payee */;
            return _toStringRewardDestination_V1(
                &m->basic.staking_set_payee_V1.payee,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1544: /* module 6 call 8 */
        switch (itemIdx) {
        case 0: /* staking_set_controller_V1 - controller */;
            return _toStringLookupSource_V1(
                &m->basic.staking_set_controller_V1.controller,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1545: /* module 6 call 9 */
        switch (itemIdx) {
        case 0: /* staking_set_validator_count_V1 - new_ */;
            return _toStringCompactu32(
                &m->basic.staking_set_validator_count_V1.new_,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1546: /* module 6 call 10 */
        switch (itemIdx) {
        case 0: /* staking_increase_validator_count_V1 - additional */;
            return _toStringCompactu32(
                &m->basic.staking_increase_validator_count_V1.additional,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1547: /* module 6 call 11 */
        switch (itemIdx) {
        case 0: /* staking_scale_validator_count_V1 - factor */;
            return _toStringPercent_V1(
                &m->basic.staking_scale_validator_count_V1.factor,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1548: /* module 6 call 12 */
        switch (itemIdx) {
        default:
            return parser_no_data;
        }
    case 1549: /* module 6 call 13 */
        switch (itemIdx) {
        default:
            return parser_no_data;
        }
    case 1550: /* module 6 call 14 */
        switch (itemIdx) {
        case 0: /* staking_set_invulnerables_V1 - validators */;
            return _toStringVecAccountId_V1(
                &m->basic.staking_set_invulnerables_V1.validators,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1551: /* module 6 call 15 */
        switch (itemIdx) {
        case 0: /* staking_force_unstake_V1 - stash */;
            return _toStringAccountId_V1(
                &m->basic.staking_force_unstake_V1.stash,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* staking_force_unstake_V1 - num_slashing_spans */;
            return _toStringu32(
                &m->basic.staking_force_unstake_V1.num_slashing_spans,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1552: /* module 6 call 16 */
        switch (itemIdx) {
        default:
            return parser_no_data;
        }
    case 1553: /* module 6 call 17 */
        switch (itemIdx) {
        case 0: /* staking_cancel_deferred_slash_V1 - era */;
            return _toStringEraIndex_V1(
                &m->basic.staking_cancel_deferred_slash_V1.era,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* staking_cancel_deferred_slash_V1 - slash_indices */;
            return _toStringVecu32(
                &m->basic.staking_cancel_deferred_slash_V1.slash_indices,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1554: /* module 6 call 18 */
        switch (itemIdx) {
        case 0: /* staking_payout_stakers_V1 - validator_stash */;
            return _toStringAccountId_V1(
                &m->basic.staking_payout_stakers_V1.validator_stash,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* staking_payout_stakers_V1 - era */;
            return _toStringEraIndex_V1(
                &m->basic.staking_payout_stakers_V1.era,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1555: /* module 6 call 19 */
        switch (itemIdx) {
        case 0: /* staking_rebond_V1 - value */;
            return _toStringCompactBalanceOf(
                &m->basic.staking_rebond_V1.value,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1556: /* module 6 call 20 */
        switch (itemIdx) {
        case 0: /* staking_set_history_depth_V1 - new_history_depth */;
            return _toStringCompactEraIndex_V1(
                &m->basic.staking_set_history_depth_V1.new_history_depth,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* staking_set_history_depth_V1 - _era_items_deleted */;
            return _toStringCompactu32(
                &m->basic.staking_set_history_depth_V1._era_items_deleted,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1557: /* module 6 call 21 */
        switch (itemIdx) {
        case 0: /* staking_reap_stash_V1 - stash */;
            return _toStringAccountId_V1(
                &m->basic.staking_reap_stash_V1.stash,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* staking_reap_stash_V1 - num_slashing_spans */;
            return _toStringu32(
                &m->basic.staking_reap_stash_V1.num_slashing_spans,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1558: /* module 6 call 22 */
        switch (itemIdx) {
        case 0: /* staking_submit_election_solution_V1 - winners */;
            return _toStringVecValidatorIndex_V1(
                &m->basic.staking_submit_election_solution_V1.winners,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* staking_submit_election_solution_V1 - compact */;
            return _toStringCompactAssignments_V1(
                &m->basic.staking_submit_election_solution_V1.compact,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* staking_submit_election_solution_V1 - score */;
            return _toStringElectionScore_V1(
                &m->basic.staking_submit_election_solution_V1.score,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 3: /* staking_submit_election_solution_V1 - era */;
            return _toStringEraIndex_V1(
                &m->basic.staking_submit_election_solution_V1.era,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 4: /* staking_submit_election_solution_V1 - size */;
            return _toStringElectionSize_V1(
                &m->basic.staking_submit_election_solution_V1.size,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1559: /* module 6 call 23 */
        switch (itemIdx) {
        case 0: /* staking_submit_election_solution_unsigned_V1 - winners */;
            return _toStringVecValidatorIndex_V1(
                &m->basic.staking_submit_election_solution_unsigned_V1.winners,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* staking_submit_election_solution_unsigned_V1 - compact */;
            return _toStringCompactAssignments_V1(
                &m->basic.staking_submit_election_solution_unsigned_V1.compact,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* staking_submit_election_solution_unsigned_V1 - score */;
            return _toStringElectionScore_V1(
                &m->basic.staking_submit_election_solution_unsigned_V1.score,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 3: /* staking_submit_election_solution_unsigned_V1 - era */;
            return _toStringEraIndex_V1(
                &m->basic.staking_submit_election_solution_unsigned_V1.era,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 4: /* staking_submit_election_solution_unsigned_V1 - size */;
            return _toStringElectionSize_V1(
                &m->basic.staking_submit_election_solution_unsigned_V1.size,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1792: /* module 7 call 0 */
        switch (itemIdx) {
        case 0: /* session_set_keys_V1 - keys */;
            return _toStringKeys_V1(
                &m->basic.session_set_keys_V1.keys,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* session_set_keys_V1 - proof */;
            return _toStringBytes(
                &m->basic.session_set_keys_V1.proof,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1793: /* module 7 call 1 */
        switch (itemIdx) {
        default:
            return parser_no_data;
        }
    case 2048: /* module 8 call 0 */
        switch (itemIdx) {
        case 0: /* democracy_propose_V1 - proposal_hash */;
            return _toStringHash(
                &m->basic.democracy_propose_V1.proposal_hash,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* democracy_propose_V1 - value */;
            return _toStringCompactBalanceOf(
                &m->basic.democracy_propose_V1.value,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 2049: /* module 8 call 1 */
        switch (itemIdx) {
        case 0: /* democracy_second_V1 - proposal */;
            return _toStringCompactPropIndex_V1(
                &m->basic.democracy_second_V1.proposal,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* democracy_second_V1 - seconds_upper_bound */;
            return _toStringCompactu32(
                &m->basic.democracy_second_V1.seconds_upper_bound,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 2050: /* module 8 call 2 */
        switch (itemIdx) {
        case 0: /* democracy_vote_V1 - ref_index */;
            return _toStringCompactReferendumIndex_V1(
                &m->basic.democracy_vote_V1.ref_index,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* democracy_vote_V1 - vote */;
            return _toStringAccountVote_V1(
                &m->basic.democracy_vote_V1.vote,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 2051: /* module 8 call 3 */
        switch (itemIdx) {
        case 0: /* democracy_emergency_cancel_V1 - ref_index */;
            return _toStringReferendumIndex_V1(
                &m->basic.democracy_emergency_cancel_V1.ref_index,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 2052: /* module 8 call 4 */
        switch (itemIdx) {
        case 0: /* democracy_external_propose_V1 - proposal_hash */;
            return _toStringHash(
                &m->basic.democracy_external_propose_V1.proposal_hash,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 2053: /* module 8 call 5 */
        switch (itemIdx) {
        case 0: /* democracy_external_propose_majority_V1 - proposal_hash */;
            return _toStringHash(
                &m->basic.democracy_external_propose_majority_V1.proposal_hash,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 2054: /* module 8 call 6 */
        switch (itemIdx) {
        case 0: /* democracy_external_propose_default_V1 - proposal_hash */;
            return _toStringHash(
                &m->basic.democracy_external_propose_default_V1.proposal_hash,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 2055: /* module 8 call 7 */
        switch (itemIdx) {
        case 0: /* democracy_fast_track_V1 - proposal_hash */;
            return _toStringHash(
                &m->basic.democracy_fast_track_V1.proposal_hash,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* democracy_fast_track_V1 - voting_period */;
            return _toStringBlockNumber(
                &m->basic.democracy_fast_track_V1.voting_period,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* democracy_fast_track_V1 - delay */;
            return _toStringBlockNumber(
                &m->basic.democracy_fast_track_V1.delay,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 2056: /* module 8 call 8 */
        switch (itemIdx) {
        case 0: /* democracy_veto_external_V1 - proposal_hash */;
            return _toStringHash(
                &m->basic.democracy_veto_external_V1.proposal_hash,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 2057: /* module 8 call 9 */
        switch (itemIdx) {
        case 0: /* democracy_cancel_referendum_V1 - ref_index */;
            return _toStringCompactReferendumIndex_V1(
                &m->basic.democracy_cancel_referendum_V1.ref_index,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 2058: /* module 8 call 10 */
        switch (itemIdx) {
        case 0: /* democracy_cancel_queued_V1 - which */;
            return _toStringReferendumIndex_V1(
                &m->basic.democracy_cancel_queued_V1.which,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 2059: /* module 8 call 11 */
        switch (itemIdx) {
        case 0: /* democracy_delegate_V1 - to */;
            return _toStringAccountId_V1(
                &m->basic.democracy_delegate_V1.to,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* democracy_delegate_V1 - conviction */;
            return _toStringConviction_V1(
                &m->basic.democracy_delegate_V1.conviction,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* democracy_delegate_V1 - balance */;
            return _toStringBalanceOf(
                &m->basic.democracy_delegate_V1.balance,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 2060: /* module 8 call 12 */
        switch (itemIdx) {
        default:
            return parser_no_data;
        }
    case 2061: /* module 8 call 13 */
        switch (itemIdx) {
        default:
            return parser_no_data;
        }
    case 2062: /* module 8 call 14 */
        switch (itemIdx) {
        case 0: /* democracy_note_preimage_V1 - encoded_proposal */;
            return _toStringBytes(
                &m->basic.democracy_note_preimage_V1.encoded_proposal,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 2063: /* module 8 call 15 */
        switch (itemIdx) {
        case 0: /* democracy_note_preimage_operational_V1 - encoded_proposal */;
            return _toStringBytes(
                &m->basic.democracy_note_preimage_operational_V1.encoded_proposal,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 2064: /* module 8 call 16 */
        switch (itemIdx) {
        case 0: /* democracy_note_imminent_preimage_V1 - encoded_proposal */;
            return _toStringBytes(
                &m->basic.democracy_note_imminent_preimage_V1.encoded_proposal,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 2065: /* module 8 call 17 */
        switch (itemIdx) {
        case 0: /* democracy_note_imminent_preimage_operational_V1 - encoded_proposal */;
            return _toStringBytes(
                &m->basic.democracy_note_imminent_preimage_operational_V1.encoded_proposal,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 2066: /* module 8 call 18 */
        switch (itemIdx) {
        case 0: /* democracy_reap_preimage_V1 - proposal_hash */;
            return _toStringHash(
                &m->basic.democracy_reap_preimage_V1.proposal_hash,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* democracy_reap_preimage_V1 - proposal_len_upper_bound */;
            return _toStringCompactu32(
                &m->basic.democracy_reap_preimage_V1.proposal_len_upper_bound,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 2067: /* module 8 call 19 */
        switch (itemIdx) {
        case 0: /* democracy_unlock_V1 - target */;
            return _toStringAccountId_V1(
                &m->basic.democracy_unlock_V1.target,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 2068: /* module 8 call 20 */
        switch (itemIdx) {
        case 0: /* democracy_remove_vote_V1 - index */;
            return _toStringReferendumIndex_V1(
                &m->basic.democracy_remove_vote_V1.index,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 2069: /* module 8 call 21 */
        switch (itemIdx) {
        case 0: /* democracy_remove_other_vote_V1 - target */;
            return _toStringAccountId_V1(
                &m->basic.democracy_remove_other_vote_V1.target,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* democracy_remove_other_vote_V1 - index */;
            return _toStringReferendumIndex_V1(
                &m->basic.democracy_remove_other_vote_V1.index,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 2070: /* module 8 call 22 */
        switch (itemIdx) {
        case 0: /* democracy_enact_proposal_V1 - proposal_hash */;
            return _toStringHash(
                &m->basic.democracy_enact_proposal_V1.proposal_hash,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* democracy_enact_proposal_V1 - index */;
            return _toStringReferendumIndex_V1(
                &m->basic.democracy_enact_proposal_V1.index,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 2304: /* module 9 call 0 */
        switch (itemIdx) {
        case 0: /* council_set_members_V1 - new_members */;
            return _toStringVecAccountId_V1(
                &m->basic.council_set_members_V1.new_members,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* council_set_members_V1 - prime */;
            return _toStringOptionAccountId_V1(
                &m->basic.council_set_members_V1.prime,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* council_set_members_V1 - old_count */;
            return _toStringMemberCount_V1(
                &m->basic.council_set_members_V1.old_count,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 2305: /* module 9 call 1 */
        switch (itemIdx) {
        case 0: /* council_execute_V1 - proposal */;
            return _toStringProposal(
                &m->basic.council_execute_V1.proposal,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* council_execute_V1 - length_bound */;
            return _toStringCompactu32(
                &m->basic.council_execute_V1.length_bound,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 2306: /* module 9 call 2 */
        switch (itemIdx) {
        case 0: /* council_propose_V1 - threshold */;
            return _toStringCompactMemberCount_V1(
                &m->basic.council_propose_V1.threshold,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* council_propose_V1 - proposal */;
            return _toStringProposal(
                &m->basic.council_propose_V1.proposal,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* council_propose_V1 - length_bound */;
            return _toStringCompactu32(
                &m->basic.council_propose_V1.length_bound,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 2307: /* module 9 call 3 */
        switch (itemIdx) {
        case 0: /* council_vote_V1 - proposal */;
            return _toStringHash(
                &m->basic.council_vote_V1.proposal,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* council_vote_V1 - index */;
            return _toStringCompactProposalIndex_V1(
                &m->basic.council_vote_V1.index,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* council_vote_V1 - approve */;
            return _toStringbool(
                &m->basic.council_vote_V1.approve,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 2308: /* module 9 call 4 */
        switch (itemIdx) {
        case 0: /* council_close_V1 - proposal_hash */;
            return _toStringHash(
                &m->basic.council_close_V1.proposal_hash,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* council_close_V1 - index */;
            return _toStringCompactProposalIndex_V1(
                &m->basic.council_close_V1.index,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* council_close_V1 - proposal_weight_bound */;
            return _toStringCompactWeight_V1(
                &m->basic.council_close_V1.proposal_weight_bound,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 3: /* council_close_V1 - length_bound */;
            return _toStringCompactu32(
                &m->basic.council_close_V1.length_bound,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 2309: /* module 9 call 5 */
        switch (itemIdx) {
        case 0: /* council_disapprove_proposal_V1 - proposal_hash */;
            return _toStringHash(
                &m->basic.council_disapprove_proposal_V1.proposal_hash,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 2560: /* module 10 call 0 */
        switch (itemIdx) {
        case 0: /* elections_vote_V1 - votes */;
            return _toStringVecAccountId_V1(
                &m->basic.elections_vote_V1.votes,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* elections_vote_V1 - value */;
            return _toStringCompactBalanceOf(
                &m->basic.elections_vote_V1.value,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 2561: /* module 10 call 1 */
        switch (itemIdx) {
        default:
            return parser_no_data;
        }
    case 2562: /* module 10 call 2 */
        switch (itemIdx) {
        case 0: /* elections_report_defunct_voter_V1 - defunct */;
            return _toStringDefunctVoter_V1(
                &m->basic.elections_report_defunct_voter_V1.defunct,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 2563: /* module 10 call 3 */
        switch (itemIdx) {
        case 0: /* elections_submit_candidacy_V1 - candidate_count */;
            return _toStringCompactu32(
                &m->basic.elections_submit_candidacy_V1.candidate_count,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 2564: /* module 10 call 4 */
        switch (itemIdx) {
        case 0: /* elections_renounce_candidacy_V1 - renouncing */;
            return _toStringRenouncing_V1(
                &m->basic.elections_renounce_candidacy_V1.renouncing,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 2565: /* module 10 call 5 */
        switch (itemIdx) {
        case 0: /* elections_remove_member_V1 - who */;
            return _toStringLookupSource_V1(
                &m->basic.elections_remove_member_V1.who,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* elections_remove_member_V1 - has_replacement */;
            return _toStringbool(
                &m->basic.elections_remove_member_V1.has_replacement,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 2816: /* module 11 call 0 */
        switch (itemIdx) {
        case 0: /* finalitytracker_final_hint_V1 - hint */;
            return _toStringCompactBlockNumber(
                &m->basic.finalitytracker_final_hint_V1.hint,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 3072: /* module 12 call 0 */
        switch (itemIdx) {
        case 0: /* grandpa_report_equivocation_V1 - equivocation_proof */;
            return _toStringEquivocationProof_V1(
                &m->basic.grandpa_report_equivocation_V1.equivocation_proof,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* grandpa_report_equivocation_V1 - key_owner_proof */;
            return _toStringKeyOwnerProof_V1(
                &m->basic.grandpa_report_equivocation_V1.key_owner_proof,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 3073: /* module 12 call 1 */
        switch (itemIdx) {
        case 0: /* grandpa_report_equivocation_unsigned_V1 - equivocation_proof */;
            return _toStringEquivocationProof_V1(
                &m->basic.grandpa_report_equivocation_unsigned_V1.equivocation_proof,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* grandpa_report_equivocation_unsigned_V1 - key_owner_proof */;
            return _toStringKeyOwnerProof_V1(
                &m->basic.grandpa_report_equivocation_unsigned_V1.key_owner_proof,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 3074: /* module 12 call 2 */
        switch (itemIdx) {
        case 0: /* grandpa_note_stalled_V1 - delay */;
            return _toStringBlockNumber(
                &m->basic.grandpa_note_stalled_V1.delay,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* grandpa_note_stalled_V1 - best_finalized_block_number */;
            return _toStringBlockNumber(
                &m->basic.grandpa_note_stalled_V1.best_finalized_block_number,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 3328: /* module 13 call 0 */
        switch (itemIdx) {
        case 0: /* imonline_heartbeat_V1 - heartbeat */;
            return _toStringHeartbeat(
                &m->basic.imonline_heartbeat_V1.heartbeat,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* imonline_heartbeat_V1 - _signature */;
            return _toStringSignature_V1(
                &m->basic.imonline_heartbeat_V1._signature,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 4352: /* module 17 call 0 */
        switch (itemIdx) {
        case 0: /* anchor_pre_commit_V1 - anchor_id */;
            return _toStringHash(
                &m->basic.anchor_pre_commit_V1.anchor_id,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* anchor_pre_commit_V1 - signing_root */;
            return _toStringHash(
                &m->basic.anchor_pre_commit_V1.signing_root,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 4353: /* module 17 call 1 */
        switch (itemIdx) {
        case 0: /* anchor_commit_V1 - anchor_id_preimage */;
            return _toStringHash(
                &m->basic.anchor_commit_V1.anchor_id_preimage,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* anchor_commit_V1 - doc_root */;
            return _toStringHash(
                &m->basic.anchor_commit_V1.doc_root,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* anchor_commit_V1 - proof */;
            return _toStringHash(
                &m->basic.anchor_commit_V1.proof,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 3: /* anchor_commit_V1 - stored_until_date */;
            return _toStringMoment_V1(
                &m->basic.anchor_commit_V1.stored_until_date,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 4354: /* module 17 call 2 */
        switch (itemIdx) {
        case 0: /* anchor_evict_pre_commits_V1 - evict_bucket */;
            return _toStringBlockNumber(
                &m->basic.anchor_evict_pre_commits_V1.evict_bucket,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 4355: /* module 17 call 3 */
        switch (itemIdx) {
        default:
            return parser_no_data;
        }
    case 4608: /* module 18 call 0 */
        switch (itemIdx) {
        case 0: /* fees_set_fee_V1 - key */;
            return _toStringHash(
                &m->basic.fees_set_fee_V1.key,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* fees_set_fee_V1 - new_price */;
            return _toStringBalance(
                &m->basic.fees_set_fee_V1.new_price,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 4864: /* module 19 call 0 */
        switch (itemIdx) {
        case 0: /* nfts_validate_mint_V1 - anchor_id */;
            return _toStringHash(
                &m->basic.nfts_validate_mint_V1.anchor_id,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* nfts_validate_mint_V1 - deposit_address */;
            return _toStringu8_array_20(
                &m->basic.nfts_validate_mint_V1.deposit_address,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* nfts_validate_mint_V1 - pfs */;
            return _toStringVecProof_V1(
                &m->basic.nfts_validate_mint_V1.pfs,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 3: /* nfts_validate_mint_V1 - static_proofs */;
            return _toStringH256_array_3_V1(
                &m->basic.nfts_validate_mint_V1.static_proofs,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 4: /* nfts_validate_mint_V1 - dest_id */;
            return _toStringChainId_V1(
                &m->basic.nfts_validate_mint_V1.dest_id,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 5120: /* module 20 call 0 */
        switch (itemIdx) {
        case 0: /* multiaccount_create_V1 - threshold */;
            return _toStringu16(
                &m->basic.multiaccount_create_V1.threshold,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* multiaccount_create_V1 - other_signatories */;
            return _toStringVecAccountId_V1(
                &m->basic.multiaccount_create_V1.other_signatories,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 5121: /* module 20 call 1 */
        switch (itemIdx) {
        case 0: /* multiaccount_update_V1 - threshold */;
            return _toStringu16(
                &m->basic.multiaccount_update_V1.threshold,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* multiaccount_update_V1 - signatories */;
            return _toStringVecAccountId_V1(
                &m->basic.multiaccount_update_V1.signatories,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 5122: /* module 20 call 2 */
        switch (itemIdx) {
        default:
            return parser_no_data;
        }
    case 5123: /* module 20 call 3 */
        switch (itemIdx) {
        case 0: /* multiaccount_call_V1 - multi_account_id */;
            return _toStringAccountId_V1(
                &m->basic.multiaccount_call_V1.multi_account_id,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* multiaccount_call_V1 - maybe_timepoint */;
            return _toStringOptionTimepoint_V1(
                &m->basic.multiaccount_call_V1.maybe_timepoint,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* multiaccount_call_V1 - call */;
            return _toStringCall(
                &m->basic.multiaccount_call_V1.call,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 5124: /* module 20 call 4 */
        switch (itemIdx) {
        case 0: /* multiaccount_approve_V1 - multi_account_id */;
            return _toStringAccountId_V1(
                &m->basic.multiaccount_approve_V1.multi_account_id,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* multiaccount_approve_V1 - maybe_timepoint */;
            return _toStringOptionTimepoint_V1(
                &m->basic.multiaccount_approve_V1.maybe_timepoint,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* multiaccount_approve_V1 - call_hash */;
            return _toStringu8_array_32_V1(
                &m->basic.multiaccount_approve_V1.call_hash,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 5125: /* module 20 call 5 */
        switch (itemIdx) {
        case 0: /* multiaccount_cancel_V1 - multi_account_id */;
            return _toStringAccountId_V1(
                &m->basic.multiaccount_cancel_V1.multi_account_id,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* multiaccount_cancel_V1 - timepoint */;
            return _toStringTimepoint_V1(
                &m->basic.multiaccount_cancel_V1.timepoint,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* multiaccount_cancel_V1 - call_hash */;
            return _toStringu8_array_32_V1(
                &m->basic.multiaccount_cancel_V1.call_hash,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 5376: /* module 21 call 0 */
        switch (itemIdx) {
        case 0: /* identity_add_registrar_V1 - account */;
            return _toStringAccountId_V1(
                &m->basic.identity_add_registrar_V1.account,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 5377: /* module 21 call 1 */
        switch (itemIdx) {
        case 0: /* identity_set_identity_V1 - info */;
            return _toStringIdentityInfo_V1(
                &m->basic.identity_set_identity_V1.info,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 5378: /* module 21 call 2 */
        switch (itemIdx) {
        case 0: /* identity_set_subs_V1 - subs */;
            return _toStringVecTupleAccountIdData_V1(
                &m->basic.identity_set_subs_V1.subs,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 5379: /* module 21 call 3 */
        switch (itemIdx) {
        default:
            return parser_no_data;
        }
    case 5380: /* module 21 call 4 */
        switch (itemIdx) {
        case 0: /* identity_request_judgement_V1 - reg_index */;
            return _toStringCompactRegistrarIndex_V1(
                &m->basic.identity_request_judgement_V1.reg_index,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* identity_request_judgement_V1 - max_fee */;
            return _toStringCompactBalanceOf(
                &m->basic.identity_request_judgement_V1.max_fee,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 5381: /* module 21 call 5 */
        switch (itemIdx) {
        case 0: /* identity_cancel_request_V1 - reg_index */;
            return _toStringRegistrarIndex_V1(
                &m->basic.identity_cancel_request_V1.reg_index,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 5382: /* module 21 call 6 */
        switch (itemIdx) {
        case 0: /* identity_set_fee_V1 - index */;
            return _toStringCompactRegistrarIndex_V1(
                &m->basic.identity_set_fee_V1.index,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* identity_set_fee_V1 - fee */;
            return _toStringCompactBalanceOf(
                &m->basic.identity_set_fee_V1.fee,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 5383: /* module 21 call 7 */
        switch (itemIdx) {
        case 0: /* identity_set_account_id_V1 - index */;
            return _toStringCompactRegistrarIndex_V1(
                &m->basic.identity_set_account_id_V1.index,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* identity_set_account_id_V1 - new_ */;
            return _toStringAccountId_V1(
                &m->basic.identity_set_account_id_V1.new_,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 5384: /* module 21 call 8 */
        switch (itemIdx) {
        case 0: /* identity_set_fields_V1 - index */;
            return _toStringCompactRegistrarIndex_V1(
                &m->basic.identity_set_fields_V1.index,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* identity_set_fields_V1 - fields */;
            return _toStringIdentityFields_V1(
                &m->basic.identity_set_fields_V1.fields,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 5385: /* module 21 call 9 */
        switch (itemIdx) {
        case 0: /* identity_provide_judgement_V1 - reg_index */;
            return _toStringCompactRegistrarIndex_V1(
                &m->basic.identity_provide_judgement_V1.reg_index,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* identity_provide_judgement_V1 - target */;
            return _toStringLookupSource_V1(
                &m->basic.identity_provide_judgement_V1.target,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* identity_provide_judgement_V1 - judgement */;
            return _toStringJudgement_V1(
                &m->basic.identity_provide_judgement_V1.judgement,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 5386: /* module 21 call 10 */
        switch (itemIdx) {
        case 0: /* identity_kill_identity_V1 - target */;
            return _toStringLookupSource_V1(
                &m->basic.identity_kill_identity_V1.target,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 5387: /* module 21 call 11 */
        switch (itemIdx) {
        case 0: /* identity_add_sub_V1 - sub */;
            return _toStringLookupSource_V1(
                &m->basic.identity_add_sub_V1.sub,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* identity_add_sub_V1 - data */;
            return _toStringData(
                &m->basic.identity_add_sub_V1.data,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 5388: /* module 21 call 12 */
        switch (itemIdx) {
        case 0: /* identity_rename_sub_V1 - sub */;
            return _toStringLookupSource_V1(
                &m->basic.identity_rename_sub_V1.sub,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* identity_rename_sub_V1 - data */;
            return _toStringData(
                &m->basic.identity_rename_sub_V1.data,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 5389: /* module 21 call 13 */
        switch (itemIdx) {
        case 0: /* identity_remove_sub_V1 - sub */;
            return _toStringLookupSource_V1(
                &m->basic.identity_remove_sub_V1.sub,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 5390: /* module 21 call 14 */
        switch (itemIdx) {
        default:
            return parser_no_data;
        }
    case 5632: /* module 22 call 0 */
        switch (itemIdx) {
        case 0: /* palletbridge_transfer_native_V1 - amount */;
            return _toStringBalanceOf(
                &m->basic.palletbridge_transfer_native_V1.amount,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* palletbridge_transfer_native_V1 - recipient */;
            return _toStringBytes(
                &m->basic.palletbridge_transfer_native_V1.recipient,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* palletbridge_transfer_native_V1 - dest_id */;
            return _toStringChainId_V1(
                &m->basic.palletbridge_transfer_native_V1.dest_id,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 5633: /* module 22 call 1 */
        switch (itemIdx) {
        case 0: /* palletbridge_transfer_asset_V1 - recipient */;
            return _toStringBytes(
                &m->basic.palletbridge_transfer_asset_V1.recipient,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* palletbridge_transfer_asset_V1 - from_registry */;
            return _toStringRegistryId_V1(
                &m->basic.palletbridge_transfer_asset_V1.from_registry,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* palletbridge_transfer_asset_V1 - token_id */;
            return _toStringTokenId_V1(
                &m->basic.palletbridge_transfer_asset_V1.token_id,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 3: /* palletbridge_transfer_asset_V1 - dest_id */;
            return _toStringChainId_V1(
                &m->basic.palletbridge_transfer_asset_V1.dest_id,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 5634: /* module 22 call 2 */
        switch (itemIdx) {
        case 0: /* palletbridge_transfer_V1 - to */;
            return _toStringAccountId_V1(
                &m->basic.palletbridge_transfer_V1.to,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* palletbridge_transfer_V1 - amount */;
            return _toStringBalanceOf(
                &m->basic.palletbridge_transfer_V1.amount,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* palletbridge_transfer_V1 - r_id */;
            return _toStringResourceId_V1(
                &m->basic.palletbridge_transfer_V1.r_id,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 5635: /* module 22 call 3 */
        switch (itemIdx) {
        case 0: /* palletbridge_receive_nonfungible_V1 - to */;
            return _toStringAccountId_V1(
                &m->basic.palletbridge_receive_nonfungible_V1.to,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* palletbridge_receive_nonfungible_V1 - token_id */;
            return _toStringTokenId_V1(
                &m->basic.palletbridge_receive_nonfungible_V1.token_id,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* palletbridge_receive_nonfungible_V1 - _metadata */;
            return _toStringBytes(
                &m->basic.palletbridge_receive_nonfungible_V1._metadata,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 3: /* palletbridge_receive_nonfungible_V1 - resource_id */;
            return _toStringResourceId_V1(
                &m->basic.palletbridge_receive_nonfungible_V1.resource_id,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 5636: /* module 22 call 4 */
        switch (itemIdx) {
        case 0: /* palletbridge_remark_V1 - hash */;
            return _toStringHash(
                &m->basic.palletbridge_remark_V1.hash,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* palletbridge_remark_V1 - r_id */;
            return _toStringResourceId_V1(
                &m->basic.palletbridge_remark_V1.r_id,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 5888: /* module 23 call 0 */
        switch (itemIdx) {
        case 0: /* chainbridge_set_threshold_V1 - threshold */;
            return _toStringu32(
                &m->basic.chainbridge_set_threshold_V1.threshold,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 5889: /* module 23 call 1 */
        switch (itemIdx) {
        case 0: /* chainbridge_set_resource_V1 - id */;
            return _toStringResourceId_V1(
                &m->basic.chainbridge_set_resource_V1.id,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* chainbridge_set_resource_V1 - method */;
            return _toStringBytes(
                &m->basic.chainbridge_set_resource_V1.method,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 5890: /* module 23 call 2 */
        switch (itemIdx) {
        case 0: /* chainbridge_remove_resource_V1 - id */;
            return _toStringResourceId_V1(
                &m->basic.chainbridge_remove_resource_V1.id,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 5891: /* module 23 call 3 */
        switch (itemIdx) {
        case 0: /* chainbridge_whitelist_chain_V1 - id */;
            return _toStringChainId_V1(
                &m->basic.chainbridge_whitelist_chain_V1.id,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 5892: /* module 23 call 4 */
        switch (itemIdx) {
        case 0: /* chainbridge_add_relayer_V1 - v */;
            return _toStringAccountId_V1(
                &m->basic.chainbridge_add_relayer_V1.v,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 5893: /* module 23 call 5 */
        switch (itemIdx) {
        case 0: /* chainbridge_remove_relayer_V1 - v */;
            return _toStringAccountId_V1(
                &m->basic.chainbridge_remove_relayer_V1.v,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 5894: /* module 23 call 6 */
        switch (itemIdx) {
        case 0: /* chainbridge_acknowledge_proposal_V1 - nonce */;
            return _toStringDepositNonce_V1(
                &m->basic.chainbridge_acknowledge_proposal_V1.nonce,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* chainbridge_acknowledge_proposal_V1 - src_id */;
            return _toStringChainId_V1(
                &m->basic.chainbridge_acknowledge_proposal_V1.src_id,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* chainbridge_acknowledge_proposal_V1 - r_id */;
            return _toStringResourceId_V1(
                &m->basic.chainbridge_acknowledge_proposal_V1.r_id,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 3: /* chainbridge_acknowledge_proposal_V1 - call */;
            return _toStringProposal(
                &m->basic.chainbridge_acknowledge_proposal_V1.call,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 5895: /* module 23 call 7 */
        switch (itemIdx) {
        case 0: /* chainbridge_reject_proposal_V1 - nonce */;
            return _toStringDepositNonce_V1(
                &m->basic.chainbridge_reject_proposal_V1.nonce,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* chainbridge_reject_proposal_V1 - src_id */;
            return _toStringChainId_V1(
                &m->basic.chainbridge_reject_proposal_V1.src_id,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* chainbridge_reject_proposal_V1 - r_id */;
            return _toStringResourceId_V1(
                &m->basic.chainbridge_reject_proposal_V1.r_id,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 3: /* chainbridge_reject_proposal_V1 - call */;
            return _toStringProposal(
                &m->basic.chainbridge_reject_proposal_V1.call,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 5896: /* module 23 call 8 */
        switch (itemIdx) {
        case 0: /* chainbridge_eval_vote_state_V1 - nonce */;
            return _toStringDepositNonce_V1(
                &m->basic.chainbridge_eval_vote_state_V1.nonce,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* chainbridge_eval_vote_state_V1 - src_id */;
            return _toStringChainId_V1(
                &m->basic.chainbridge_eval_vote_state_V1.src_id,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* chainbridge_eval_vote_state_V1 - prop */;
            return _toStringProposal(
                &m->basic.chainbridge_eval_vote_state_V1.prop,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 6144: /* module 24 call 0 */
        switch (itemIdx) {
        case 0: /* indices_claim_V1 - index */;
            return _toStringAccountIndex_V1(
                &m->basic.indices_claim_V1.index,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 6145: /* module 24 call 1 */
        switch (itemIdx) {
        case 0: /* indices_transfer_V1 - new_ */;
            return _toStringAccountId_V1(
                &m->basic.indices_transfer_V1.new_,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* indices_transfer_V1 - index */;
            return _toStringAccountIndex_V1(
                &m->basic.indices_transfer_V1.index,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 6146: /* module 24 call 2 */
        switch (itemIdx) {
        case 0: /* indices_free_V1 - index */;
            return _toStringAccountIndex_V1(
                &m->basic.indices_free_V1.index,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 6147: /* module 24 call 3 */
        switch (itemIdx) {
        case 0: /* indices_force_transfer_V1 - new_ */;
            return _toStringAccountId_V1(
                &m->basic.indices_force_transfer_V1.new_,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* indices_force_transfer_V1 - index */;
            return _toStringAccountIndex_V1(
                &m->basic.indices_force_transfer_V1.index,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* indices_force_transfer_V1 - freeze */;
            return _toStringbool(
                &m->basic.indices_force_transfer_V1.freeze,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 6148: /* module 24 call 4 */
        switch (itemIdx) {
        case 0: /* indices_freeze_V1 - index */;
            return _toStringAccountIndex_V1(
                &m->basic.indices_freeze_V1.index,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 6400: /* module 25 call 0 */
        switch (itemIdx) {
        case 0: /* scheduler_schedule_V1 - when */;
            return _toStringBlockNumber(
                &m->basic.scheduler_schedule_V1.when,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* scheduler_schedule_V1 - maybe_periodic */;
            return _toStringOptionPeriod_V1(
                &m->basic.scheduler_schedule_V1.maybe_periodic,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* scheduler_schedule_V1 - priority */;
            return _toStringPriority_V1(
                &m->basic.scheduler_schedule_V1.priority,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 3: /* scheduler_schedule_V1 - call */;
            return _toStringCall(
                &m->basic.scheduler_schedule_V1.call,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 6401: /* module 25 call 1 */
        switch (itemIdx) {
        case 0: /* scheduler_cancel_V1 - when */;
            return _toStringBlockNumber(
                &m->basic.scheduler_cancel_V1.when,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* scheduler_cancel_V1 - index */;
            return _toStringu32(
                &m->basic.scheduler_cancel_V1.index,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 6402: /* module 25 call 2 */
        switch (itemIdx) {
        case 0: /* scheduler_schedule_named_V1 - id */;
            return _toStringBytes(
                &m->basic.scheduler_schedule_named_V1.id,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* scheduler_schedule_named_V1 - when */;
            return _toStringBlockNumber(
                &m->basic.scheduler_schedule_named_V1.when,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* scheduler_schedule_named_V1 - maybe_periodic */;
            return _toStringOptionPeriod_V1(
                &m->basic.scheduler_schedule_named_V1.maybe_periodic,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 3: /* scheduler_schedule_named_V1 - priority */;
            return _toStringPriority_V1(
                &m->basic.scheduler_schedule_named_V1.priority,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 4: /* scheduler_schedule_named_V1 - call */;
            return _toStringCall(
                &m->basic.scheduler_schedule_named_V1.call,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 6403: /* module 25 call 3 */
        switch (itemIdx) {
        case 0: /* scheduler_cancel_named_V1 - id */;
            return _toStringBytes(
                &m->basic.scheduler_cancel_named_V1.id,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 6404: /* module 25 call 4 */
        switch (itemIdx) {
        case 0: /* scheduler_schedule_after_V1 - after */;
            return _toStringBlockNumber(
                &m->basic.scheduler_schedule_after_V1.after,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* scheduler_schedule_after_V1 - maybe_periodic */;
            return _toStringOptionPeriod_V1(
                &m->basic.scheduler_schedule_after_V1.maybe_periodic,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* scheduler_schedule_after_V1 - priority */;
            return _toStringPriority_V1(
                &m->basic.scheduler_schedule_after_V1.priority,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 3: /* scheduler_schedule_after_V1 - call */;
            return _toStringCall(
                &m->basic.scheduler_schedule_after_V1.call,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 6405: /* module 25 call 5 */
        switch (itemIdx) {
        case 0: /* scheduler_schedule_named_after_V1 - id */;
            return _toStringBytes(
                &m->basic.scheduler_schedule_named_after_V1.id,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* scheduler_schedule_named_after_V1 - after */;
            return _toStringBlockNumber(
                &m->basic.scheduler_schedule_named_after_V1.after,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* scheduler_schedule_named_after_V1 - maybe_periodic */;
            return _toStringOptionPeriod_V1(
                &m->basic.scheduler_schedule_named_after_V1.maybe_periodic,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 3: /* scheduler_schedule_named_after_V1 - priority */;
            return _toStringPriority_V1(
                &m->basic.scheduler_schedule_named_after_V1.priority,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 4: /* scheduler_schedule_named_after_V1 - call */;
            return _toStringCall(
                &m->basic.scheduler_schedule_named_after_V1.call,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 6656: /* module 26 call 0 */
        switch (itemIdx) {
        case 0: /* proxy_proxy_V1 - real */;
            return _toStringAccountId_V1(
                &m->basic.proxy_proxy_V1.real,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* proxy_proxy_V1 - force_proxy_type */;
            return _toStringOptionProxyType_V1(
                &m->basic.proxy_proxy_V1.force_proxy_type,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* proxy_proxy_V1 - call */;
            return _toStringCall(
                &m->basic.proxy_proxy_V1.call,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 6657: /* module 26 call 1 */
        switch (itemIdx) {
        case 0: /* proxy_add_proxy_V1 - proxy */;
            return _toStringAccountId_V1(
                &m->basic.proxy_add_proxy_V1.proxy,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* proxy_add_proxy_V1 - proxy_type */;
            return _toStringProxyType_V1(
                &m->basic.proxy_add_proxy_V1.proxy_type,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 6658: /* module 26 call 2 */
        switch (itemIdx) {
        case 0: /* proxy_remove_proxy_V1 - proxy */;
            return _toStringAccountId_V1(
                &m->basic.proxy_remove_proxy_V1.proxy,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* proxy_remove_proxy_V1 - proxy_type */;
            return _toStringProxyType_V1(
                &m->basic.proxy_remove_proxy_V1.proxy_type,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 6659: /* module 26 call 3 */
        switch (itemIdx) {
        default:
            return parser_no_data;
        }
    case 6660: /* module 26 call 4 */
        switch (itemIdx) {
        case 0: /* proxy_anonymous_V1 - proxy_type */;
            return _toStringProxyType_V1(
                &m->basic.proxy_anonymous_V1.proxy_type,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* proxy_anonymous_V1 - index */;
            return _toStringu16(
                &m->basic.proxy_anonymous_V1.index,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 6661: /* module 26 call 5 */
        switch (itemIdx) {
        case 0: /* proxy_kill_anonymous_V1 - spawner */;
            return _toStringAccountId_V1(
                &m->basic.proxy_kill_anonymous_V1.spawner,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* proxy_kill_anonymous_V1 - proxy_type */;
            return _toStringProxyType_V1(
                &m->basic.proxy_kill_anonymous_V1.proxy_type,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* proxy_kill_anonymous_V1 - index */;
            return _toStringu16(
                &m->basic.proxy_kill_anonymous_V1.index,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 3: /* proxy_kill_anonymous_V1 - height */;
            return _toStringCompactBlockNumber(
                &m->basic.proxy_kill_anonymous_V1.height,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 4: /* proxy_kill_anonymous_V1 - ext_index */;
            return _toStringCompactu32(
                &m->basic.proxy_kill_anonymous_V1.ext_index,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 6912: /* module 27 call 0 */
        switch (itemIdx) {
        case 0: /* multisig_as_multi_threshold_1_V1 - other_signatories */;
            return _toStringVecAccountId_V1(
                &m->basic.multisig_as_multi_threshold_1_V1.other_signatories,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* multisig_as_multi_threshold_1_V1 - call */;
            return _toStringCall(
                &m->basic.multisig_as_multi_threshold_1_V1.call,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 6913: /* module 27 call 1 */
        switch (itemIdx) {
        case 0: /* multisig_as_multi_V1 - threshold */;
            return _toStringu16(
                &m->basic.multisig_as_multi_V1.threshold,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* multisig_as_multi_V1 - other_signatories */;
            return _toStringVecAccountId_V1(
                &m->basic.multisig_as_multi_V1.other_signatories,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* multisig_as_multi_V1 - maybe_timepoint */;
            return _toStringOptionTimepoint_V1(
                &m->basic.multisig_as_multi_V1.maybe_timepoint,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 3: /* multisig_as_multi_V1 - call */;
            return _toStringOpaqueCall_V1(
                &m->basic.multisig_as_multi_V1.call,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 4: /* multisig_as_multi_V1 - store_call */;
            return _toStringbool(
                &m->basic.multisig_as_multi_V1.store_call,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 5: /* multisig_as_multi_V1 - max_weight */;
            return _toStringWeight_V1(
                &m->basic.multisig_as_multi_V1.max_weight,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 6914: /* module 27 call 2 */
        switch (itemIdx) {
        case 0: /* multisig_approve_as_multi_V1 - threshold */;
            return _toStringu16(
                &m->basic.multisig_approve_as_multi_V1.threshold,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* multisig_approve_as_multi_V1 - other_signatories */;
            return _toStringVecAccountId_V1(
                &m->basic.multisig_approve_as_multi_V1.other_signatories,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* multisig_approve_as_multi_V1 - maybe_timepoint */;
            return _toStringOptionTimepoint_V1(
                &m->basic.multisig_approve_as_multi_V1.maybe_timepoint,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 3: /* multisig_approve_as_multi_V1 - call_hash */;
            return _toStringu8_array_32_V1(
                &m->basic.multisig_approve_as_multi_V1.call_hash,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 4: /* multisig_approve_as_multi_V1 - max_weight */;
            return _toStringWeight_V1(
                &m->basic.multisig_approve_as_multi_V1.max_weight,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 6915: /* module 27 call 3 */
        switch (itemIdx) {
        case 0: /* multisig_cancel_as_multi_V1 - threshold */;
            return _toStringu16(
                &m->basic.multisig_cancel_as_multi_V1.threshold,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* multisig_cancel_as_multi_V1 - other_signatories */;
            return _toStringVecAccountId_V1(
                &m->basic.multisig_cancel_as_multi_V1.other_signatories,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* multisig_cancel_as_multi_V1 - timepoint */;
            return _toStringTimepoint_V1(
                &m->basic.multisig_cancel_as_multi_V1.timepoint,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 3: /* multisig_cancel_as_multi_V1 - call_hash */;
            return _toStringu8_array_32_V1(
                &m->basic.multisig_cancel_as_multi_V1.call_hash,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 7168: /* module 28 call 0 */
        switch (itemIdx) {
        case 0: /* radclaims_claim_V1 - account_id */;
            return _toStringAccountId_V1(
                &m->basic.radclaims_claim_V1.account_id,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* radclaims_claim_V1 - amount */;
            return _toStringBalance(
                &m->basic.radclaims_claim_V1.amount,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* radclaims_claim_V1 - sorted_hashes */;
            return _toStringVecHash(
                &m->basic.radclaims_claim_V1.sorted_hashes,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 7169: /* module 28 call 1 */
        switch (itemIdx) {
        case 0: /* radclaims_set_upload_account_V1 - account_id */;
            return _toStringAccountId_V1(
                &m->basic.radclaims_set_upload_account_V1.account_id,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 7170: /* module 28 call 2 */
        switch (itemIdx) {
        case 0: /* radclaims_store_root_hash_V1 - root_hash */;
            return _toStringHash(
                &m->basic.radclaims_store_root_hash_V1.root_hash,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 7424: /* module 29 call 0 */
        switch (itemIdx) {
        default:
            return parser_no_data;
        }
    case 7425: /* module 29 call 1 */
        switch (itemIdx) {
        case 0: /* vesting_vest_other_V1 - target */;
            return _toStringLookupSource_V1(
                &m->basic.vesting_vest_other_V1.target,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 7426: /* module 29 call 2 */
        switch (itemIdx) {
        case 0: /* vesting_vested_transfer_V1 - target */;
            return _toStringLookupSource_V1(
                &m->basic.vesting_vested_transfer_V1.target,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* vesting_vested_transfer_V1 - schedule */;
            return _toStringVestingInfo_V1(
                &m->basic.vesting_vested_transfer_V1.schedule,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 7427: /* module 29 call 3 */
        switch (itemIdx) {
        case 0: /* vesting_force_vested_transfer_V1 - source */;
            return _toStringLookupSource_V1(
                &m->basic.vesting_force_vested_transfer_V1.source,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* vesting_force_vested_transfer_V1 - target */;
            return _toStringLookupSource_V1(
                &m->basic.vesting_force_vested_transfer_V1.target,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* vesting_force_vested_transfer_V1 - schedule */;
            return _toStringVestingInfo_V1(
                &m->basic.vesting_force_vested_transfer_V1.schedule,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 7680: /* module 30 call 0 */
        switch (itemIdx) {
        case 0: /* registry_create_registry_V1 - info */;
            return _toStringRegistryInfo_V1(
                &m->basic.registry_create_registry_V1.info,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 7681: /* module 30 call 1 */
        switch (itemIdx) {
        case 0: /* registry_mint_V1 - owner_account */;
            return _toStringAccountId_V1(
                &m->basic.registry_mint_V1.owner_account,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* registry_mint_V1 - registry_id */;
            return _toStringRegistryId_V1(
                &m->basic.registry_mint_V1.registry_id,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* registry_mint_V1 - token_id */;
            return _toStringTokenId_V1(
                &m->basic.registry_mint_V1.token_id,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 3: /* registry_mint_V1 - asset_info */;
            return _toStringAssetInfo_V1(
                &m->basic.registry_mint_V1.asset_info,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 4: /* registry_mint_V1 - mint_info */;
            return _toStringMintInfo_V1(
                &m->basic.registry_mint_V1.mint_info,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 7936: /* module 31 call 0 */
        switch (itemIdx) {
        case 0: /* nft_transfer_V1 - dest_account */;
            return _toStringAccountId_V1(
                &m->basic.nft_transfer_V1.dest_account,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* nft_transfer_V1 - registry_id */;
            return _toStringRegistryId_V1(
                &m->basic.nft_transfer_V1.registry_id,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* nft_transfer_V1 - token_id */;
            return _toStringTokenId_V1(
                &m->basic.nft_transfer_V1.token_id,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 8192: /* module 32 call 0 */
        switch (itemIdx) {
        case 0: /* bridgemapping_set_V1 - rid */;
            return _toStringResourceId_V1(
                &m->basic.bridgemapping_set_V1.rid,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* bridgemapping_set_V1 - local_addr */;
            return _toStringAddress_V1(
                &m->basic.bridgemapping_set_V1.local_addr,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 8193: /* module 32 call 1 */
        switch (itemIdx) {
        case 0: /* bridgemapping_remove_V1 - rid */;
            return _toStringResourceId_V1(
                &m->basic.bridgemapping_remove_V1.rid,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    default:
        return parser_ok;
    }

    return parser_ok;
}

bool _getMethod_ItemIsExpert_V1(uint8_t moduleIdx, uint8_t callIdx, uint8_t itemIdx)
{
    uint16_t callPrivIdx = ((uint16_t)moduleIdx << 8u) + callIdx;

    switch (callPrivIdx) {
    case 1539: // Staking:Withdraw Unbonded
        switch (itemIdx) {
        case 0: // Num slashing spans
            return true;
        default:
            return false;
        }
    case 1551: // Staking:Force unstake
        switch (itemIdx) {
        case 1: // Num slashing spans
            return true;
        default:
            return false;
        }
    case 1557: // Staking:Reap stash
        switch (itemIdx) {
        case 1: // Num slashing spans
            return true;
        default:
            return false;
        }
    case 5894: // ChainBridge:Acknowledge proposal
        switch (itemIdx) {
        case 0: // Nonce
            return true;
        default:
            return false;
        }
    case 5895: // ChainBridge:Reject proposal
        switch (itemIdx) {
        case 0: // Nonce
            return true;
        default:
            return false;
        }
    case 5896: // ChainBridge:Eval vote state
        switch (itemIdx) {
        case 0: // Nonce
            return true;
        default:
            return false;
        }

    default:
        return false;
    }
}

bool _getMethod_IsNestingSupported_V1(uint8_t moduleIdx, uint8_t callIdx)
{
    uint16_t callPrivIdx = ((uint16_t)moduleIdx << 8u) + callIdx;

    switch (callPrivIdx) {
    case 0: // System:Fill block
    case 1: // System:Remark
    case 2: // System:Set heap pages
    case 3: // System:Set code
    case 4: // System:Set code without checks
    case 5: // System:Set changes trie config
    case 6: // System:Set storage
    case 7: // System:Kill storage
    case 8: // System:Kill prefix
    case 9: // System:Suicide
    case 256: // Utility:Batch
    case 257: // Utility:As derivative
    case 512: // Babe:Report equivocation
    case 513: // Babe:Report equivocation unsigned
    case 768: // Timestamp:Set
    case 1024: // Authorship:Set uncles
    case 1280: // Balances:Transfer
    case 1281: // Balances:Set balance
    case 1282: // Balances:Force transfer
    case 1283: // Balances:Transfer keep alive
    case 1536: // Staking:Bond
    case 1537: // Staking:Bond extra
    case 1538: // Staking:Unbond
    case 1539: // Staking:Withdraw Unbonded
    case 1540: // Staking:Validate
    case 1541: // Staking:Nominate
    case 1542: // Staking:Chill
    case 1543: // Staking:Set payee
    case 1544: // Staking:Set controller
    case 1545: // Staking:Set validator count
    case 1546: // Staking:Increase validator count
    case 1547: // Staking:Scale validator count
    case 1548: // Staking:Force no eras
    case 1549: // Staking:Force new era
    case 1550: // Staking:Set invulnerables
    case 1551: // Staking:Force unstake
    case 1552: // Staking:Force new era always
    case 1553: // Staking:Cancel deferred slash
    case 1554: // Staking:Payout stakers
    case 1555: // Staking:Rebond
    case 1556: // Staking:Set history depth
    case 1557: // Staking:Reap stash
    case 1558: // Staking:Submit election solution
    case 1559: // Staking:Submit election solution unsigned
    case 1792: // Session:Set keys
    case 1793: // Session:Purge keys
    case 2048: // Democracy:Propose
    case 2049: // Democracy:Second
    case 2050: // Democracy:Vote
    case 2051: // Democracy:Emergency cancel
    case 2052: // Democracy:External propose
    case 2053: // Democracy:External propose majority
    case 2054: // Democracy:External propose default
    case 2055: // Democracy:Fast track
    case 2056: // Democracy:Veto external
    case 2057: // Democracy:Cancel referendum
    case 2058: // Democracy:Cancel queued
    case 2059: // Democracy:Delegate
    case 2060: // Democracy:Undelegate
    case 2061: // Democracy:Clear public proposals
    case 2062: // Democracy:Note preimage
    case 2063: // Democracy:Note preimage operational
    case 2064: // Democracy:Note imminent preimage
    case 2065: // Democracy:Note imminent preimage operational
    case 2066: // Democracy:Reap preimage
    case 2067: // Democracy:Unlock
    case 2068: // Democracy:Remove vote
    case 2069: // Democracy:Remove other vote
    case 2070: // Democracy:Enact proposal
    case 2304: // Council:Set members
    case 2305: // Council:Execute
    case 2306: // Council:Propose
    case 2307: // Council:Vote
    case 2308: // Council:Close
    case 2309: // Council:Disapprove proposal
    case 2560: // Elections:Vote
    case 2561: // Elections:Remove voter
    case 2562: // Elections:Report defunct voter
    case 2563: // Elections:Submit candidacy
    case 2564: // Elections:Renounce candidacy
    case 2565: // Elections:Remove member
    case 2816: // FinalityTracker:Final hint
    case 3072: // Grandpa:Report equivocation
    case 3073: // Grandpa:Report equivocation unsigned
    case 3074: // Grandpa:Note stalled
    case 3328: // ImOnline:Heartbeat
    case 4352: // Anchor:Pre commit
    case 4353: // Anchor:Commit
    case 4354: // Anchor:Evict pre commits
    case 4355: // Anchor:Evict anchors
    case 4608: // Fees:Set fee
    case 4864: // Nfts:Validate mint
    case 5120: // MultiAccount:Create
    case 5121: // MultiAccount:Update
    case 5122: // MultiAccount:Remove
    case 5123: // MultiAccount:Call
    case 5124: // MultiAccount:Approve
    case 5125: // MultiAccount:Cancel
    case 5376: // Identity:Add registrar
    case 5377: // Identity:Set identity
    case 5378: // Identity:Set subs
    case 5379: // Identity:Clear identity
    case 5380: // Identity:Request judgement
    case 5381: // Identity:Cancel request
    case 5382: // Identity:Set fee
    case 5383: // Identity:Set account id
    case 5384: // Identity:Set fields
    case 5385: // Identity:Provide judgement
    case 5386: // Identity:Kill identity
    case 5387: // Identity:Add sub
    case 5388: // Identity:Rename sub
    case 5389: // Identity:Remove sub
    case 5390: // Identity:Quit sub
    case 5632: // PalletBridge:Transfer native
    case 5633: // PalletBridge:Transfer asset
    case 5634: // PalletBridge:Transfer
    case 5635: // PalletBridge:Receive nonfungible
    case 5636: // PalletBridge:Remark
    case 5888: // ChainBridge:Set threshold
    case 5889: // ChainBridge:Set resource
    case 5890: // ChainBridge:Remove resource
    case 5891: // ChainBridge:Whitelist chain
    case 5892: // ChainBridge:Add relayer
    case 5893: // ChainBridge:Remove relayer
    case 5894: // ChainBridge:Acknowledge proposal
    case 5895: // ChainBridge:Reject proposal
    case 5896: // ChainBridge:Eval vote state
    case 6144: // Indices:Claim
    case 6145: // Indices:Transfer
    case 6146: // Indices:Free
    case 6147: // Indices:Force transfer
    case 6148: // Indices:Freeze
    case 6400: // Scheduler:Schedule
    case 6401: // Scheduler:Cancel
    case 6402: // Scheduler:Schedule named
    case 6403: // Scheduler:Cancel named
    case 6404: // Scheduler:Schedule after
    case 6405: // Scheduler:Schedule named after
    case 6656: // Proxy:Proxy
    case 6657: // Proxy:Add proxy
    case 6658: // Proxy:Remove proxy
    case 6659: // Proxy:Remove proxies
    case 6660: // Proxy:Anonymous
    case 6661: // Proxy:Kill anonymous
    case 6912: // Multisig:As multi threshold 1
    case 6913: // Multisig:As multi
    case 6914: // Multisig:Approve as multi
    case 6915: // Multisig:Cancel as multi
    case 7168: // RadClaims:Claim
    case 7169: // RadClaims:Set upload account
    case 7170: // RadClaims:Store root hash
    case 7424: // Vesting:Vest
    case 7425: // Vesting:Vest other
    case 7426: // Vesting:Vested transfer
    case 7427: // Vesting:Force vested transfer
    case 7680: // Registry:Create registry
    case 7681: // Registry:Mint
    case 7936: // Nft:Transfer
    case 8192: // BridgeMapping:Set
    case 8193: // BridgeMapping:Remove
        return false;
    default:
        return true;
    }
}
