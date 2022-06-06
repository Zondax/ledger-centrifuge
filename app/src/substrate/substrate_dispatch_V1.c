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
#include "substrate_strings.h"
#include "zxmacros.h"
#include <stdint.h>

__Z_INLINE parser_error_t _readMethod_utility_batch_V1(
    parser_context_t* c, pd_utility_batch_V1_t* m)
{
    CHECK_ERROR(_readVecCall(c, &m->calls))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_balances_transfer_V1(
    parser_context_t* c, pd_balances_transfer_V1_t* m)
{
    CHECK_ERROR(_readLookupSource_V1(c, &m->dest))
    CHECK_ERROR(_readCompactBalance(c, &m->value))
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

__Z_INLINE parser_error_t _readMethod_democracy_unlock_V1(
    parser_context_t* c, pd_democracy_unlock_V1_t* m)
{
    CHECK_ERROR(_readAccountId_V1(c, &m->target))
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

#ifdef SUBSTRATE_PARSER_FULL
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

__Z_INLINE parser_error_t _readMethod_system_suicide_V1(
    parser_context_t* c, pd_system_suicide_V1_t* m)
{
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_timestamp_set_V1(
    parser_context_t* c, pd_timestamp_set_V1_t* m)
{
    CHECK_ERROR(_readCompactMoment_V1(c, &m->now))
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

__Z_INLINE parser_error_t _readMethod_democracy_emergency_cancel_V1(
    parser_context_t* c, pd_democracy_emergency_cancel_V1_t* m)
{
    CHECK_ERROR(_readReferendumIndex_V1(c, &m->ref_index))
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

__Z_INLINE parser_error_t _readMethod_grandpa_note_stalled_V1(
    parser_context_t* c, pd_grandpa_note_stalled_V1_t* m)
{
    CHECK_ERROR(_readBlockNumber(c, &m->delay))
    CHECK_ERROR(_readBlockNumber(c, &m->best_finalized_block_number))
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

__Z_INLINE parser_error_t _readMethod_identity_add_registrar_V1(
    parser_context_t* c, pd_identity_add_registrar_V1_t* m)
{
    CHECK_ERROR(_readAccountId_V1(c, &m->account))
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

__Z_INLINE parser_error_t _readMethod_identity_kill_identity_V1(
    parser_context_t* c, pd_identity_kill_identity_V1_t* m)
{
    CHECK_ERROR(_readLookupSource_V1(c, &m->target))
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

__Z_INLINE parser_error_t _readMethod_palletbridge_set_token_transfer_fee_V1(
    parser_context_t* c, pd_palletbridge_set_token_transfer_fee_V1_t* m)
{
    CHECK_ERROR(_readBalance(c, &m->fee))
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
    CHECK_ERROR(_readH256(c, &m->call_hash))
    CHECK_ERROR(_readWeight_V1(c, &m->max_weight))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_multisig_cancel_as_multi_V1(
    parser_context_t* c, pd_multisig_cancel_as_multi_V1_t* m)
{
    CHECK_ERROR(_readu16(c, &m->threshold))
    CHECK_ERROR(_readVecAccountId_V1(c, &m->other_signatories))
    CHECK_ERROR(_readTimepoint_V1(c, &m->timepoint))
    CHECK_ERROR(_readH256(c, &m->call_hash))
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

#endif

parser_error_t _readMethod_V1(
    parser_context_t* c,
    uint8_t moduleIdx,
    uint8_t callIdx,
    pd_Method_V1_t* method)
{
    uint16_t callPrivIdx = ((uint16_t)moduleIdx << 8u) + callIdx;

    switch (callPrivIdx) {

    case 256: /* module 1 call 0 */
        CHECK_ERROR(_readMethod_utility_batch_V1(c, &method->basic.utility_batch_V1))
        break;
    case 1280: /* module 5 call 0 */
        CHECK_ERROR(_readMethod_balances_transfer_V1(c, &method->nested.balances_transfer_V1))
        break;
    case 1282: /* module 5 call 2 */
        CHECK_ERROR(_readMethod_balances_force_transfer_V1(c, &method->nested.balances_force_transfer_V1))
        break;
    case 1283: /* module 5 call 3 */
        CHECK_ERROR(_readMethod_balances_transfer_keep_alive_V1(c, &method->nested.balances_transfer_keep_alive_V1))
        break;
    case 1536: /* module 6 call 0 */
        CHECK_ERROR(_readMethod_staking_bond_V1(c, &method->nested.staking_bond_V1))
        break;
    case 1537: /* module 6 call 1 */
        CHECK_ERROR(_readMethod_staking_bond_extra_V1(c, &method->nested.staking_bond_extra_V1))
        break;
    case 1538: /* module 6 call 2 */
        CHECK_ERROR(_readMethod_staking_unbond_V1(c, &method->nested.staking_unbond_V1))
        break;
    case 1539: /* module 6 call 3 */
        CHECK_ERROR(_readMethod_staking_withdraw_unbonded_V1(c, &method->basic.staking_withdraw_unbonded_V1))
        break;
    case 1540: /* module 6 call 4 */
        CHECK_ERROR(_readMethod_staking_validate_V1(c, &method->nested.staking_validate_V1))
        break;
    case 1541: /* module 6 call 5 */
        CHECK_ERROR(_readMethod_staking_nominate_V1(c, &method->nested.staking_nominate_V1))
        break;
    case 1542: /* module 6 call 6 */
        CHECK_ERROR(_readMethod_staking_chill_V1(c, &method->nested.staking_chill_V1))
        break;
    case 1543: /* module 6 call 7 */
        CHECK_ERROR(_readMethod_staking_set_payee_V1(c, &method->nested.staking_set_payee_V1))
        break;
    case 1544: /* module 6 call 8 */
        CHECK_ERROR(_readMethod_staking_set_controller_V1(c, &method->nested.staking_set_controller_V1))
        break;
    case 1554: /* module 6 call 18 */
        CHECK_ERROR(_readMethod_staking_payout_stakers_V1(c, &method->basic.staking_payout_stakers_V1))
        break;
    case 1555: /* module 6 call 19 */
        CHECK_ERROR(_readMethod_staking_rebond_V1(c, &method->nested.staking_rebond_V1))
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
    case 2067: /* module 8 call 19 */
        CHECK_ERROR(_readMethod_democracy_unlock_V1(c, &method->basic.democracy_unlock_V1))
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
    case 2563: /* module 10 call 3 */
        CHECK_ERROR(_readMethod_elections_submit_candidacy_V1(c, &method->basic.elections_submit_candidacy_V1))
        break;
    case 2564: /* module 10 call 4 */
        CHECK_ERROR(_readMethod_elections_renounce_candidacy_V1(c, &method->basic.elections_renounce_candidacy_V1))
        break;

#ifdef SUBSTRATE_PARSER_FULL
    case 0: /* module 0 call 0 */
        CHECK_ERROR(_readMethod_system_fill_block_V1(c, &method->nested.system_fill_block_V1))
        break;
    case 1: /* module 0 call 1 */
        CHECK_ERROR(_readMethod_system_remark_V1(c, &method->nested.system_remark_V1))
        break;
    case 2: /* module 0 call 2 */
        CHECK_ERROR(_readMethod_system_set_heap_pages_V1(c, &method->nested.system_set_heap_pages_V1))
        break;
    case 3: /* module 0 call 3 */
        CHECK_ERROR(_readMethod_system_set_code_V1(c, &method->nested.system_set_code_V1))
        break;
    case 4: /* module 0 call 4 */
        CHECK_ERROR(_readMethod_system_set_code_without_checks_V1(c, &method->nested.system_set_code_without_checks_V1))
        break;
    case 9: /* module 0 call 9 */
        CHECK_ERROR(_readMethod_system_suicide_V1(c, &method->nested.system_suicide_V1))
        break;
    case 768: /* module 3 call 0 */
        CHECK_ERROR(_readMethod_timestamp_set_V1(c, &method->basic.timestamp_set_V1))
        break;
    case 1281: /* module 5 call 1 */
        CHECK_ERROR(_readMethod_balances_set_balance_V1(c, &method->nested.balances_set_balance_V1))
        break;
    case 1545: /* module 6 call 9 */
        CHECK_ERROR(_readMethod_staking_set_validator_count_V1(c, &method->basic.staking_set_validator_count_V1))
        break;
    case 1546: /* module 6 call 10 */
        CHECK_ERROR(_readMethod_staking_increase_validator_count_V1(c, &method->basic.staking_increase_validator_count_V1))
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
    case 1556: /* module 6 call 20 */
        CHECK_ERROR(_readMethod_staking_set_history_depth_V1(c, &method->basic.staking_set_history_depth_V1))
        break;
    case 1557: /* module 6 call 21 */
        CHECK_ERROR(_readMethod_staking_reap_stash_V1(c, &method->basic.staking_reap_stash_V1))
        break;
    case 2051: /* module 8 call 3 */
        CHECK_ERROR(_readMethod_democracy_emergency_cancel_V1(c, &method->basic.democracy_emergency_cancel_V1))
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
    case 2561: /* module 10 call 1 */
        CHECK_ERROR(_readMethod_elections_remove_voter_V1(c, &method->basic.elections_remove_voter_V1))
        break;
    case 2562: /* module 10 call 2 */
        CHECK_ERROR(_readMethod_elections_report_defunct_voter_V1(c, &method->basic.elections_report_defunct_voter_V1))
        break;
    case 2565: /* module 10 call 5 */
        CHECK_ERROR(_readMethod_elections_remove_member_V1(c, &method->basic.elections_remove_member_V1))
        break;
    case 2816: /* module 11 call 0 */
        CHECK_ERROR(_readMethod_finalitytracker_final_hint_V1(c, &method->basic.finalitytracker_final_hint_V1))
        break;
    case 3074: /* module 12 call 2 */
        CHECK_ERROR(_readMethod_grandpa_note_stalled_V1(c, &method->basic.grandpa_note_stalled_V1))
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
    case 5376: /* module 21 call 0 */
        CHECK_ERROR(_readMethod_identity_add_registrar_V1(c, &method->basic.identity_add_registrar_V1))
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
    case 5386: /* module 21 call 10 */
        CHECK_ERROR(_readMethod_identity_kill_identity_V1(c, &method->basic.identity_kill_identity_V1))
        break;
    case 5389: /* module 21 call 13 */
        CHECK_ERROR(_readMethod_identity_remove_sub_V1(c, &method->basic.identity_remove_sub_V1))
        break;
    case 5390: /* module 21 call 14 */
        CHECK_ERROR(_readMethod_identity_quit_sub_V1(c, &method->basic.identity_quit_sub_V1))
        break;
    case 5637: /* module 22 call 5 */
        CHECK_ERROR(_readMethod_palletbridge_set_token_transfer_fee_V1(c, &method->basic.palletbridge_set_token_transfer_fee_V1))
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
    case 6656: /* module 26 call 0 */
        CHECK_ERROR(_readMethod_proxy_proxy_V1(c, &method->nested.proxy_proxy_V1))
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
        CHECK_ERROR(_readMethod_multisig_as_multi_threshold_1_V1(c, &method->nested.multisig_as_multi_threshold_1_V1))
        break;
    case 6913: /* module 27 call 1 */
        CHECK_ERROR(_readMethod_multisig_as_multi_V1(c, &method->nested.multisig_as_multi_V1))
        break;
    case 6914: /* module 27 call 2 */
        CHECK_ERROR(_readMethod_multisig_approve_as_multi_V1(c, &method->nested.multisig_approve_as_multi_V1))
        break;
    case 6915: /* module 27 call 3 */
        CHECK_ERROR(_readMethod_multisig_cancel_as_multi_V1(c, &method->nested.multisig_cancel_as_multi_V1))
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
    case 8192: /* module 32 call 0 */
        CHECK_ERROR(_readMethod_bridgemapping_set_V1(c, &method->basic.bridgemapping_set_V1))
        break;
    case 8193: /* module 32 call 1 */
        CHECK_ERROR(_readMethod_bridgemapping_remove_V1(c, &method->basic.bridgemapping_remove_V1))
        break;
#endif
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
    case 1:
        return STR_MO_UTILITY;
    case 5:
        return STR_MO_BALANCES;
    case 6:
        return STR_MO_STAKING;
    case 7:
        return STR_MO_SESSION;
    case 8:
        return STR_MO_DEMOCRACY;
    case 9:
        return STR_MO_COUNCIL;
    case 10:
        return STR_MO_ELECTIONS;
#ifdef SUBSTRATE_PARSER_FULL
    case 0:
        return STR_MO_SYSTEM;
    case 3:
        return STR_MO_TIMESTAMP;
    case 11:
        return STR_MO_FINALITYTRACKER;
    case 12:
        return STR_MO_GRANDPA;
    case 17:
        return STR_MO_ANCHOR;
    case 18:
        return STR_MO_FEES;
    case 21:
        return STR_MO_IDENTITY;
    case 22:
        return STR_MO_PALLETBRIDGE;
    case 24:
        return STR_MO_INDICES;
    case 26:
        return STR_MO_PROXY;
    case 27:
        return STR_MO_MULTISIG;
    case 28:
        return STR_MO_RADCLAIMS;
    case 29:
        return STR_MO_VESTING;
    case 32:
        return STR_MO_BRIDGEMAPPING;
#endif
    default:
        return NULL;
    }

    return NULL;
}

const char* _getMethod_Name_V1(uint8_t moduleIdx, uint8_t callIdx)
{
    uint16_t callPrivIdx = ((uint16_t)moduleIdx << 8u) + callIdx;

    switch (callPrivIdx) {
    case 256: /* module 1 call 0 */
        return STR_ME_BATCH;
    case 1280: /* module 5 call 0 */
        return STR_ME_TRANSFER;
    case 1282: /* module 5 call 2 */
        return STR_ME_FORCE_TRANSFER;
    case 1283: /* module 5 call 3 */
        return STR_ME_TRANSFER_KEEP_ALIVE;
    case 1536: /* module 6 call 0 */
        return STR_ME_BOND;
    case 1537: /* module 6 call 1 */
        return STR_ME_BOND_EXTRA;
    case 1538: /* module 6 call 2 */
        return STR_ME_UNBOND;
    case 1539: /* module 6 call 3 */
        return STR_ME_WITHDRAW_UNBONDED;
    case 1540: /* module 6 call 4 */
        return STR_ME_VALIDATE;
    case 1541: /* module 6 call 5 */
        return STR_ME_NOMINATE;
    case 1542: /* module 6 call 6 */
        return STR_ME_CHILL;
    case 1543: /* module 6 call 7 */
        return STR_ME_SET_PAYEE;
    case 1544: /* module 6 call 8 */
        return STR_ME_SET_CONTROLLER;
    case 1554: /* module 6 call 18 */
        return STR_ME_PAYOUT_STAKERS;
    case 1555: /* module 6 call 19 */
        return STR_ME_REBOND;
    case 1792: /* module 7 call 0 */
        return STR_ME_SET_KEYS;
    case 1793: /* module 7 call 1 */
        return STR_ME_PURGE_KEYS;
    case 2048: /* module 8 call 0 */
        return STR_ME_PROPOSE;
    case 2049: /* module 8 call 1 */
        return STR_ME_SECOND;
    case 2050: /* module 8 call 2 */
        return STR_ME_VOTE;
    case 2052: /* module 8 call 4 */
        return STR_ME_EXTERNAL_PROPOSE;
    case 2053: /* module 8 call 5 */
        return STR_ME_EXTERNAL_PROPOSE_MAJORITY;
    case 2054: /* module 8 call 6 */
        return STR_ME_EXTERNAL_PROPOSE_DEFAULT;
    case 2055: /* module 8 call 7 */
        return STR_ME_FAST_TRACK;
    case 2067: /* module 8 call 19 */
        return STR_ME_UNLOCK;
    case 2305: /* module 9 call 1 */
        return STR_ME_EXECUTE;
    case 2306: /* module 9 call 2 */
        return STR_ME_PROPOSE;
    case 2307: /* module 9 call 3 */
        return STR_ME_VOTE;
    case 2308: /* module 9 call 4 */
        return STR_ME_CLOSE;
    case 2309: /* module 9 call 5 */
        return STR_ME_DISAPPROVE_PROPOSAL;
    case 2560: /* module 10 call 0 */
        return STR_ME_VOTE;
    case 2563: /* module 10 call 3 */
        return STR_ME_SUBMIT_CANDIDACY;
    case 2564: /* module 10 call 4 */
        return STR_ME_RENOUNCE_CANDIDACY;
#ifdef SUBSTRATE_PARSER_FULL
    case 0: /* module 0 call 0 */
        return STR_ME_FILL_BLOCK;
    case 1: /* module 0 call 1 */
        return STR_ME_REMARK;
    case 2: /* module 0 call 2 */
        return STR_ME_SET_HEAP_PAGES;
    case 3: /* module 0 call 3 */
        return STR_ME_SET_CODE;
    case 4: /* module 0 call 4 */
        return STR_ME_SET_CODE_WITHOUT_CHECKS;
    case 5: /* module 0 call 5 */
        return STR_ME_SET_CHANGES_TRIE_CONFIG;
    case 6: /* module 0 call 6 */
        return STR_ME_SET_STORAGE;
    case 7: /* module 0 call 7 */
        return STR_ME_KILL_STORAGE;
    case 8: /* module 0 call 8 */
        return STR_ME_KILL_PREFIX;
    case 9: /* module 0 call 9 */
        return STR_ME_SUICIDE;
    case 257: /* module 1 call 1 */
        return STR_ME_AS_DERIVATIVE;
    case 512: /* module 2 call 0 */
        return STR_ME_REPORT_EQUIVOCATION;
    case 513: /* module 2 call 1 */
        return STR_ME_REPORT_EQUIVOCATION_UNSIGNED;
    case 768: /* module 3 call 0 */
        return STR_ME_SET;
    case 1024: /* module 4 call 0 */
        return STR_ME_SET_UNCLES;
    case 1281: /* module 5 call 1 */
        return STR_ME_SET_BALANCE;
    case 1545: /* module 6 call 9 */
        return STR_ME_SET_VALIDATOR_COUNT;
    case 1546: /* module 6 call 10 */
        return STR_ME_INCREASE_VALIDATOR_COUNT;
    case 1547: /* module 6 call 11 */
        return STR_ME_SCALE_VALIDATOR_COUNT;
    case 1548: /* module 6 call 12 */
        return STR_ME_FORCE_NO_ERAS;
    case 1549: /* module 6 call 13 */
        return STR_ME_FORCE_NEW_ERA;
    case 1550: /* module 6 call 14 */
        return STR_ME_SET_INVULNERABLES;
    case 1551: /* module 6 call 15 */
        return STR_ME_FORCE_UNSTAKE;
    case 1552: /* module 6 call 16 */
        return STR_ME_FORCE_NEW_ERA_ALWAYS;
    case 1553: /* module 6 call 17 */
        return STR_ME_CANCEL_DEFERRED_SLASH;
    case 1556: /* module 6 call 20 */
        return STR_ME_SET_HISTORY_DEPTH;
    case 1557: /* module 6 call 21 */
        return STR_ME_REAP_STASH;
    case 1558: /* module 6 call 22 */
        return STR_ME_SUBMIT_ELECTION_SOLUTION;
    case 1559: /* module 6 call 23 */
        return STR_ME_SUBMIT_ELECTION_SOLUTION_UNSIGNED;
    case 2051: /* module 8 call 3 */
        return STR_ME_EMERGENCY_CANCEL;
    case 2056: /* module 8 call 8 */
        return STR_ME_VETO_EXTERNAL;
    case 2057: /* module 8 call 9 */
        return STR_ME_CANCEL_REFERENDUM;
    case 2058: /* module 8 call 10 */
        return STR_ME_CANCEL_QUEUED;
    case 2059: /* module 8 call 11 */
        return STR_ME_DELEGATE;
    case 2060: /* module 8 call 12 */
        return STR_ME_UNDELEGATE;
    case 2061: /* module 8 call 13 */
        return STR_ME_CLEAR_PUBLIC_PROPOSALS;
    case 2062: /* module 8 call 14 */
        return STR_ME_NOTE_PREIMAGE;
    case 2063: /* module 8 call 15 */
        return STR_ME_NOTE_PREIMAGE_OPERATIONAL;
    case 2064: /* module 8 call 16 */
        return STR_ME_NOTE_IMMINENT_PREIMAGE;
    case 2065: /* module 8 call 17 */
        return STR_ME_NOTE_IMMINENT_PREIMAGE_OPERATIONAL;
    case 2066: /* module 8 call 18 */
        return STR_ME_REAP_PREIMAGE;
    case 2068: /* module 8 call 20 */
        return STR_ME_REMOVE_VOTE;
    case 2069: /* module 8 call 21 */
        return STR_ME_REMOVE_OTHER_VOTE;
    case 2070: /* module 8 call 22 */
        return STR_ME_ENACT_PROPOSAL;
    case 2304: /* module 9 call 0 */
        return STR_ME_SET_MEMBERS;
    case 2561: /* module 10 call 1 */
        return STR_ME_REMOVE_VOTER;
    case 2562: /* module 10 call 2 */
        return STR_ME_REPORT_DEFUNCT_VOTER;
    case 2565: /* module 10 call 5 */
        return STR_ME_REMOVE_MEMBER;
    case 2816: /* module 11 call 0 */
        return STR_ME_FINAL_HINT;
    case 3072: /* module 12 call 0 */
        return STR_ME_REPORT_EQUIVOCATION;
    case 3073: /* module 12 call 1 */
        return STR_ME_REPORT_EQUIVOCATION_UNSIGNED;
    case 3074: /* module 12 call 2 */
        return STR_ME_NOTE_STALLED;
    case 3328: /* module 13 call 0 */
        return STR_ME_HEARTBEAT;
    case 4352: /* module 17 call 0 */
        return STR_ME_PRE_COMMIT;
    case 4353: /* module 17 call 1 */
        return STR_ME_COMMIT;
    case 4354: /* module 17 call 2 */
        return STR_ME_EVICT_PRE_COMMITS;
    case 4355: /* module 17 call 3 */
        return STR_ME_EVICT_ANCHORS;
    case 4608: /* module 18 call 0 */
        return STR_ME_SET_FEE;
    case 4864: /* module 19 call 0 */
        return STR_ME_VALIDATE_MINT;
    case 5120: /* module 20 call 0 */
        return STR_ME_CREATE;
    case 5121: /* module 20 call 1 */
        return STR_ME_UPDATE;
    case 5122: /* module 20 call 2 */
        return STR_ME_REMOVE;
    case 5123: /* module 20 call 3 */
        return STR_ME_CALL;
    case 5124: /* module 20 call 4 */
        return STR_ME_APPROVE;
    case 5125: /* module 20 call 5 */
        return STR_ME_CANCEL;
    case 5376: /* module 21 call 0 */
        return STR_ME_ADD_REGISTRAR;
    case 5377: /* module 21 call 1 */
        return STR_ME_SET_IDENTITY;
    case 5378: /* module 21 call 2 */
        return STR_ME_SET_SUBS;
    case 5379: /* module 21 call 3 */
        return STR_ME_CLEAR_IDENTITY;
    case 5380: /* module 21 call 4 */
        return STR_ME_REQUEST_JUDGEMENT;
    case 5381: /* module 21 call 5 */
        return STR_ME_CANCEL_REQUEST;
    case 5382: /* module 21 call 6 */
        return STR_ME_SET_FEE;
    case 5383: /* module 21 call 7 */
        return STR_ME_SET_ACCOUNT_ID;
    case 5384: /* module 21 call 8 */
        return STR_ME_SET_FIELDS;
    case 5385: /* module 21 call 9 */
        return STR_ME_PROVIDE_JUDGEMENT;
    case 5386: /* module 21 call 10 */
        return STR_ME_KILL_IDENTITY;
    case 5387: /* module 21 call 11 */
        return STR_ME_ADD_SUB;
    case 5388: /* module 21 call 12 */
        return STR_ME_RENAME_SUB;
    case 5389: /* module 21 call 13 */
        return STR_ME_REMOVE_SUB;
    case 5390: /* module 21 call 14 */
        return STR_ME_QUIT_SUB;
    case 5632: /* module 22 call 0 */
        return STR_ME_TRANSFER_NATIVE;
    case 5633: /* module 22 call 1 */
        return STR_ME_TRANSFER_ASSET;
    case 5634: /* module 22 call 2 */
        return STR_ME_TRANSFER;
    case 5635: /* module 22 call 3 */
        return STR_ME_RECEIVE_NONFUNGIBLE;
    case 5636: /* module 22 call 4 */
        return STR_ME_REMARK;
    case 5637: /* module 22 call 5 */
        return STR_ME_SET_TOKEN_TRANSFER_FEE;
    case 5888: /* module 23 call 0 */
        return STR_ME_SET_THRESHOLD;
    case 5889: /* module 23 call 1 */
        return STR_ME_SET_RESOURCE;
    case 5890: /* module 23 call 2 */
        return STR_ME_REMOVE_RESOURCE;
    case 5891: /* module 23 call 3 */
        return STR_ME_WHITELIST_CHAIN;
    case 5892: /* module 23 call 4 */
        return STR_ME_ADD_RELAYER;
    case 5893: /* module 23 call 5 */
        return STR_ME_REMOVE_RELAYER;
    case 5894: /* module 23 call 6 */
        return STR_ME_ACKNOWLEDGE_PROPOSAL;
    case 5895: /* module 23 call 7 */
        return STR_ME_REJECT_PROPOSAL;
    case 5896: /* module 23 call 8 */
        return STR_ME_EVAL_VOTE_STATE;
    case 6144: /* module 24 call 0 */
        return STR_ME_CLAIM;
    case 6145: /* module 24 call 1 */
        return STR_ME_TRANSFER;
    case 6146: /* module 24 call 2 */
        return STR_ME_FREE;
    case 6147: /* module 24 call 3 */
        return STR_ME_FORCE_TRANSFER;
    case 6148: /* module 24 call 4 */
        return STR_ME_FREEZE;
    case 6400: /* module 25 call 0 */
        return STR_ME_SCHEDULE;
    case 6401: /* module 25 call 1 */
        return STR_ME_CANCEL;
    case 6402: /* module 25 call 2 */
        return STR_ME_SCHEDULE_NAMED;
    case 6403: /* module 25 call 3 */
        return STR_ME_CANCEL_NAMED;
    case 6404: /* module 25 call 4 */
        return STR_ME_SCHEDULE_AFTER;
    case 6405: /* module 25 call 5 */
        return STR_ME_SCHEDULE_NAMED_AFTER;
    case 6656: /* module 26 call 0 */
        return STR_ME_PROXY;
    case 6657: /* module 26 call 1 */
        return STR_ME_ADD_PROXY;
    case 6658: /* module 26 call 2 */
        return STR_ME_REMOVE_PROXY;
    case 6659: /* module 26 call 3 */
        return STR_ME_REMOVE_PROXIES;
    case 6660: /* module 26 call 4 */
        return STR_ME_ANONYMOUS;
    case 6661: /* module 26 call 5 */
        return STR_ME_KILL_ANONYMOUS;
    case 6912: /* module 27 call 0 */
        return STR_ME_AS_MULTI_THRESHOLD_1;
    case 6913: /* module 27 call 1 */
        return STR_ME_AS_MULTI;
    case 6914: /* module 27 call 2 */
        return STR_ME_APPROVE_AS_MULTI;
    case 6915: /* module 27 call 3 */
        return STR_ME_CANCEL_AS_MULTI;
    case 7168: /* module 28 call 0 */
        return STR_ME_CLAIM;
    case 7169: /* module 28 call 1 */
        return STR_ME_SET_UPLOAD_ACCOUNT;
    case 7170: /* module 28 call 2 */
        return STR_ME_STORE_ROOT_HASH;
    case 7424: /* module 29 call 0 */
        return STR_ME_VEST;
    case 7425: /* module 29 call 1 */
        return STR_ME_VEST_OTHER;
    case 7426: /* module 29 call 2 */
        return STR_ME_VESTED_TRANSFER;
    case 7427: /* module 29 call 3 */
        return STR_ME_FORCE_VESTED_TRANSFER;
    case 7680: /* module 30 call 0 */
        return STR_ME_CREATE_REGISTRY;
    case 7681: /* module 30 call 1 */
        return STR_ME_MINT;
    case 7936: /* module 31 call 0 */
        return STR_ME_TRANSFER;
    case 8192: /* module 32 call 0 */
        return STR_ME_SET;
    case 8193: /* module 32 call 1 */
        return STR_ME_REMOVE;
#endif
    default:
        return NULL;
    }

    return NULL;
}

uint8_t _getMethod_NumItems_V1(uint8_t moduleIdx, uint8_t callIdx)
{
    uint16_t callPrivIdx = ((uint16_t)moduleIdx << 8u) + callIdx;

    switch (callPrivIdx) {
    case 256: /* module 1 call 0 */
        return 1;
    case 1280: /* module 5 call 0 */
        return 2;
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
    case 1554: /* module 6 call 18 */
        return 2;
    case 1555: /* module 6 call 19 */
        return 1;
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
    case 2052: /* module 8 call 4 */
        return 1;
    case 2053: /* module 8 call 5 */
        return 1;
    case 2054: /* module 8 call 6 */
        return 1;
    case 2055: /* module 8 call 7 */
        return 3;
    case 2067: /* module 8 call 19 */
        return 1;
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
    case 2563: /* module 10 call 3 */
        return 1;
    case 2564: /* module 10 call 4 */
        return 1;
#ifdef SUBSTRATE_PARSER_FULL
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
    case 9: /* module 0 call 9 */
        return 0;
    case 768: /* module 3 call 0 */
        return 1;
    case 1281: /* module 5 call 1 */
        return 3;
    case 1545: /* module 6 call 9 */
        return 1;
    case 1546: /* module 6 call 10 */
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
    case 1556: /* module 6 call 20 */
        return 2;
    case 1557: /* module 6 call 21 */
        return 2;
    case 2051: /* module 8 call 3 */
        return 1;
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
    case 2068: /* module 8 call 20 */
        return 1;
    case 2069: /* module 8 call 21 */
        return 2;
    case 2070: /* module 8 call 22 */
        return 2;
    case 2304: /* module 9 call 0 */
        return 3;
    case 2561: /* module 10 call 1 */
        return 0;
    case 2562: /* module 10 call 2 */
        return 1;
    case 2565: /* module 10 call 5 */
        return 2;
    case 2816: /* module 11 call 0 */
        return 1;
    case 3074: /* module 12 call 2 */
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
    case 5376: /* module 21 call 0 */
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
    case 5386: /* module 21 call 10 */
        return 1;
    case 5389: /* module 21 call 13 */
        return 1;
    case 5390: /* module 21 call 14 */
        return 0;
    case 5637: /* module 22 call 5 */
        return 1;
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
    case 8192: /* module 32 call 0 */
        return 2;
    case 8193: /* module 32 call 1 */
        return 1;
#endif
    default:
        return 0;
    }

    return 0;
}

const char* _getMethod_ItemName_V1(uint8_t moduleIdx, uint8_t callIdx, uint8_t itemIdx)
{
    uint16_t callPrivIdx = ((uint16_t)moduleIdx << 8u) + callIdx;

    switch (callPrivIdx) {
    case 256: /* module 1 call 0 */
        switch (itemIdx) {
        case 0:
            return STR_IT_calls;
        default:
            return NULL;
        }
    case 1280: /* module 5 call 0 */
        switch (itemIdx) {
        case 0:
            return STR_IT_dest;
        case 1:
            return STR_IT_value;
        default:
            return NULL;
        }
    case 1282: /* module 5 call 2 */
        switch (itemIdx) {
        case 0:
            return STR_IT_source;
        case 1:
            return STR_IT_dest;
        case 2:
            return STR_IT_value;
        default:
            return NULL;
        }
    case 1283: /* module 5 call 3 */
        switch (itemIdx) {
        case 0:
            return STR_IT_dest;
        case 1:
            return STR_IT_value;
        default:
            return NULL;
        }
    case 1536: /* module 6 call 0 */
        switch (itemIdx) {
        case 0:
            return STR_IT_controller;
        case 1:
            return STR_IT_value;
        case 2:
            return STR_IT_payee;
        default:
            return NULL;
        }
    case 1537: /* module 6 call 1 */
        switch (itemIdx) {
        case 0:
            return STR_IT_max_additional;
        default:
            return NULL;
        }
    case 1538: /* module 6 call 2 */
        switch (itemIdx) {
        case 0:
            return STR_IT_value;
        default:
            return NULL;
        }
    case 1539: /* module 6 call 3 */
        switch (itemIdx) {
        case 0:
            return STR_IT_num_slashing_spans;
        default:
            return NULL;
        }
    case 1540: /* module 6 call 4 */
        switch (itemIdx) {
        case 0:
            return STR_IT_prefs;
        default:
            return NULL;
        }
    case 1541: /* module 6 call 5 */
        switch (itemIdx) {
        case 0:
            return STR_IT_targets;
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
            return STR_IT_payee;
        default:
            return NULL;
        }
    case 1544: /* module 6 call 8 */
        switch (itemIdx) {
        case 0:
            return STR_IT_controller;
        default:
            return NULL;
        }
    case 1554: /* module 6 call 18 */
        switch (itemIdx) {
        case 0:
            return STR_IT_validator_stash;
        case 1:
            return STR_IT_era;
        default:
            return NULL;
        }
    case 1555: /* module 6 call 19 */
        switch (itemIdx) {
        case 0:
            return STR_IT_value;
        default:
            return NULL;
        }
    case 1792: /* module 7 call 0 */
        switch (itemIdx) {
        case 0:
            return STR_IT_keys;
        case 1:
            return STR_IT_proof;
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
            return STR_IT_proposal_hash;
        case 1:
            return STR_IT_value;
        default:
            return NULL;
        }
    case 2049: /* module 8 call 1 */
        switch (itemIdx) {
        case 0:
            return STR_IT_proposal;
        case 1:
            return STR_IT_seconds_upper_bound;
        default:
            return NULL;
        }
    case 2050: /* module 8 call 2 */
        switch (itemIdx) {
        case 0:
            return STR_IT_ref_index;
        case 1:
            return STR_IT_vote;
        default:
            return NULL;
        }
    case 2052: /* module 8 call 4 */
        switch (itemIdx) {
        case 0:
            return STR_IT_proposal_hash;
        default:
            return NULL;
        }
    case 2053: /* module 8 call 5 */
        switch (itemIdx) {
        case 0:
            return STR_IT_proposal_hash;
        default:
            return NULL;
        }
    case 2054: /* module 8 call 6 */
        switch (itemIdx) {
        case 0:
            return STR_IT_proposal_hash;
        default:
            return NULL;
        }
    case 2055: /* module 8 call 7 */
        switch (itemIdx) {
        case 0:
            return STR_IT_proposal_hash;
        case 1:
            return STR_IT_voting_period;
        case 2:
            return STR_IT_delay;
        default:
            return NULL;
        }
    case 2067: /* module 8 call 19 */
        switch (itemIdx) {
        case 0:
            return STR_IT_target;
        default:
            return NULL;
        }
    case 2305: /* module 9 call 1 */
        switch (itemIdx) {
        case 0:
            return STR_IT_proposal;
        case 1:
            return STR_IT_length_bound;
        default:
            return NULL;
        }
    case 2306: /* module 9 call 2 */
        switch (itemIdx) {
        case 0:
            return STR_IT_threshold;
        case 1:
            return STR_IT_proposal;
        case 2:
            return STR_IT_length_bound;
        default:
            return NULL;
        }
    case 2307: /* module 9 call 3 */
        switch (itemIdx) {
        case 0:
            return STR_IT_proposal;
        case 1:
            return STR_IT_index;
        case 2:
            return STR_IT_approve;
        default:
            return NULL;
        }
    case 2308: /* module 9 call 4 */
        switch (itemIdx) {
        case 0:
            return STR_IT_proposal_hash;
        case 1:
            return STR_IT_index;
        case 2:
            return STR_IT_proposal_weight_bound;
        case 3:
            return STR_IT_length_bound;
        default:
            return NULL;
        }
    case 2309: /* module 9 call 5 */
        switch (itemIdx) {
        case 0:
            return STR_IT_proposal_hash;
        default:
            return NULL;
        }
    case 2560: /* module 10 call 0 */
        switch (itemIdx) {
        case 0:
            return STR_IT_votes;
        case 1:
            return STR_IT_value;
        default:
            return NULL;
        }
    case 2563: /* module 10 call 3 */
        switch (itemIdx) {
        case 0:
            return STR_IT_candidate_count;
        default:
            return NULL;
        }
    case 2564: /* module 10 call 4 */
        switch (itemIdx) {
        case 0:
            return STR_IT_renouncing;
        default:
            return NULL;
        }
#ifdef SUBSTRATE_PARSER_FULL
    case 0: /* module 0 call 0 */
        switch (itemIdx) {
        case 0:
            return STR_IT__ratio;
        default:
            return NULL;
        }
    case 1: /* module 0 call 1 */
        switch (itemIdx) {
        case 0:
            return STR_IT__remark;
        default:
            return NULL;
        }
    case 2: /* module 0 call 2 */
        switch (itemIdx) {
        case 0:
            return STR_IT_pages;
        default:
            return NULL;
        }
    case 3: /* module 0 call 3 */
        switch (itemIdx) {
        case 0:
            return STR_IT_code;
        default:
            return NULL;
        }
    case 4: /* module 0 call 4 */
        switch (itemIdx) {
        case 0:
            return STR_IT_code;
        default:
            return NULL;
        }
    case 9: /* module 0 call 9 */
        switch (itemIdx) {
        default:
            return NULL;
        }
    case 768: /* module 3 call 0 */
        switch (itemIdx) {
        case 0:
            return STR_IT_now;
        default:
            return NULL;
        }
    case 1281: /* module 5 call 1 */
        switch (itemIdx) {
        case 0:
            return STR_IT_who;
        case 1:
            return STR_IT_new_free;
        case 2:
            return STR_IT_new_reserved;
        default:
            return NULL;
        }
    case 1545: /* module 6 call 9 */
        switch (itemIdx) {
        case 0:
            return STR_IT_new_;
        default:
            return NULL;
        }
    case 1546: /* module 6 call 10 */
        switch (itemIdx) {
        case 0:
            return STR_IT_additional;
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
            return STR_IT_validators;
        default:
            return NULL;
        }
    case 1551: /* module 6 call 15 */
        switch (itemIdx) {
        case 0:
            return STR_IT_stash;
        case 1:
            return STR_IT_num_slashing_spans;
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
            return STR_IT_era;
        case 1:
            return STR_IT_slash_indices;
        default:
            return NULL;
        }
    case 1556: /* module 6 call 20 */
        switch (itemIdx) {
        case 0:
            return STR_IT_new_history_depth;
        case 1:
            return STR_IT__era_items_deleted;
        default:
            return NULL;
        }
    case 1557: /* module 6 call 21 */
        switch (itemIdx) {
        case 0:
            return STR_IT_stash;
        case 1:
            return STR_IT_num_slashing_spans;
        default:
            return NULL;
        }
    case 2051: /* module 8 call 3 */
        switch (itemIdx) {
        case 0:
            return STR_IT_ref_index;
        default:
            return NULL;
        }
    case 2056: /* module 8 call 8 */
        switch (itemIdx) {
        case 0:
            return STR_IT_proposal_hash;
        default:
            return NULL;
        }
    case 2057: /* module 8 call 9 */
        switch (itemIdx) {
        case 0:
            return STR_IT_ref_index;
        default:
            return NULL;
        }
    case 2058: /* module 8 call 10 */
        switch (itemIdx) {
        case 0:
            return STR_IT_which;
        default:
            return NULL;
        }
    case 2059: /* module 8 call 11 */
        switch (itemIdx) {
        case 0:
            return STR_IT_to;
        case 1:
            return STR_IT_conviction;
        case 2:
            return STR_IT_balance;
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
            return STR_IT_encoded_proposal;
        default:
            return NULL;
        }
    case 2063: /* module 8 call 15 */
        switch (itemIdx) {
        case 0:
            return STR_IT_encoded_proposal;
        default:
            return NULL;
        }
    case 2064: /* module 8 call 16 */
        switch (itemIdx) {
        case 0:
            return STR_IT_encoded_proposal;
        default:
            return NULL;
        }
    case 2065: /* module 8 call 17 */
        switch (itemIdx) {
        case 0:
            return STR_IT_encoded_proposal;
        default:
            return NULL;
        }
    case 2066: /* module 8 call 18 */
        switch (itemIdx) {
        case 0:
            return STR_IT_proposal_hash;
        case 1:
            return STR_IT_proposal_len_upper_bound;
        default:
            return NULL;
        }
    case 2068: /* module 8 call 20 */
        switch (itemIdx) {
        case 0:
            return STR_IT_index;
        default:
            return NULL;
        }
    case 2069: /* module 8 call 21 */
        switch (itemIdx) {
        case 0:
            return STR_IT_target;
        case 1:
            return STR_IT_index;
        default:
            return NULL;
        }
    case 2070: /* module 8 call 22 */
        switch (itemIdx) {
        case 0:
            return STR_IT_proposal_hash;
        case 1:
            return STR_IT_index;
        default:
            return NULL;
        }
    case 2304: /* module 9 call 0 */
        switch (itemIdx) {
        case 0:
            return STR_IT_new_members;
        case 1:
            return STR_IT_prime;
        case 2:
            return STR_IT_old_count;
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
            return STR_IT_defunct;
        default:
            return NULL;
        }
    case 2565: /* module 10 call 5 */
        switch (itemIdx) {
        case 0:
            return STR_IT_who;
        case 1:
            return STR_IT_has_replacement;
        default:
            return NULL;
        }
    case 2816: /* module 11 call 0 */
        switch (itemIdx) {
        case 0:
            return STR_IT_hint;
        default:
            return NULL;
        }
    case 3074: /* module 12 call 2 */
        switch (itemIdx) {
        case 0:
            return STR_IT_delay;
        case 1:
            return STR_IT_best_finalized_block_number;
        default:
            return NULL;
        }
    case 4352: /* module 17 call 0 */
        switch (itemIdx) {
        case 0:
            return STR_IT_anchor_id;
        case 1:
            return STR_IT_signing_root;
        default:
            return NULL;
        }
    case 4353: /* module 17 call 1 */
        switch (itemIdx) {
        case 0:
            return STR_IT_anchor_id_preimage;
        case 1:
            return STR_IT_doc_root;
        case 2:
            return STR_IT_proof;
        case 3:
            return STR_IT_stored_until_date;
        default:
            return NULL;
        }
    case 4354: /* module 17 call 2 */
        switch (itemIdx) {
        case 0:
            return STR_IT_evict_bucket;
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
            return STR_IT_key;
        case 1:
            return STR_IT_new_price;
        default:
            return NULL;
        }
    case 5376: /* module 21 call 0 */
        switch (itemIdx) {
        case 0:
            return STR_IT_account;
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
            return STR_IT_reg_index;
        case 1:
            return STR_IT_max_fee;
        default:
            return NULL;
        }
    case 5381: /* module 21 call 5 */
        switch (itemIdx) {
        case 0:
            return STR_IT_reg_index;
        default:
            return NULL;
        }
    case 5382: /* module 21 call 6 */
        switch (itemIdx) {
        case 0:
            return STR_IT_index;
        case 1:
            return STR_IT_fee;
        default:
            return NULL;
        }
    case 5383: /* module 21 call 7 */
        switch (itemIdx) {
        case 0:
            return STR_IT_index;
        case 1:
            return STR_IT_new_;
        default:
            return NULL;
        }
    case 5386: /* module 21 call 10 */
        switch (itemIdx) {
        case 0:
            return STR_IT_target;
        default:
            return NULL;
        }
    case 5389: /* module 21 call 13 */
        switch (itemIdx) {
        case 0:
            return STR_IT_sub;
        default:
            return NULL;
        }
    case 5390: /* module 21 call 14 */
        switch (itemIdx) {
        default:
            return NULL;
        }
    case 5637: /* module 22 call 5 */
        switch (itemIdx) {
        case 0:
            return STR_IT_fee;
        default:
            return NULL;
        }
    case 6144: /* module 24 call 0 */
        switch (itemIdx) {
        case 0:
            return STR_IT_index;
        default:
            return NULL;
        }
    case 6145: /* module 24 call 1 */
        switch (itemIdx) {
        case 0:
            return STR_IT_new_;
        case 1:
            return STR_IT_index;
        default:
            return NULL;
        }
    case 6146: /* module 24 call 2 */
        switch (itemIdx) {
        case 0:
            return STR_IT_index;
        default:
            return NULL;
        }
    case 6147: /* module 24 call 3 */
        switch (itemIdx) {
        case 0:
            return STR_IT_new_;
        case 1:
            return STR_IT_index;
        case 2:
            return STR_IT_freeze;
        default:
            return NULL;
        }
    case 6148: /* module 24 call 4 */
        switch (itemIdx) {
        case 0:
            return STR_IT_index;
        default:
            return NULL;
        }
    case 6656: /* module 26 call 0 */
        switch (itemIdx) {
        case 0:
            return STR_IT_real;
        case 1:
            return STR_IT_force_proxy_type;
        case 2:
            return STR_IT_call;
        default:
            return NULL;
        }
    case 6657: /* module 26 call 1 */
        switch (itemIdx) {
        case 0:
            return STR_IT_proxy;
        case 1:
            return STR_IT_proxy_type;
        default:
            return NULL;
        }
    case 6658: /* module 26 call 2 */
        switch (itemIdx) {
        case 0:
            return STR_IT_proxy;
        case 1:
            return STR_IT_proxy_type;
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
            return STR_IT_proxy_type;
        case 1:
            return STR_IT_index;
        default:
            return NULL;
        }
    case 6661: /* module 26 call 5 */
        switch (itemIdx) {
        case 0:
            return STR_IT_spawner;
        case 1:
            return STR_IT_proxy_type;
        case 2:
            return STR_IT_index;
        case 3:
            return STR_IT_height;
        case 4:
            return STR_IT_ext_index;
        default:
            return NULL;
        }
    case 6912: /* module 27 call 0 */
        switch (itemIdx) {
        case 0:
            return STR_IT_other_signatories;
        case 1:
            return STR_IT_call;
        default:
            return NULL;
        }
    case 6913: /* module 27 call 1 */
        switch (itemIdx) {
        case 0:
            return STR_IT_threshold;
        case 1:
            return STR_IT_other_signatories;
        case 2:
            return STR_IT_maybe_timepoint;
        case 3:
            return STR_IT_call;
        case 4:
            return STR_IT_store_call;
        case 5:
            return STR_IT_max_weight;
        default:
            return NULL;
        }
    case 6914: /* module 27 call 2 */
        switch (itemIdx) {
        case 0:
            return STR_IT_threshold;
        case 1:
            return STR_IT_other_signatories;
        case 2:
            return STR_IT_maybe_timepoint;
        case 3:
            return STR_IT_call_hash;
        case 4:
            return STR_IT_max_weight;
        default:
            return NULL;
        }
    case 6915: /* module 27 call 3 */
        switch (itemIdx) {
        case 0:
            return STR_IT_threshold;
        case 1:
            return STR_IT_other_signatories;
        case 2:
            return STR_IT_timepoint;
        case 3:
            return STR_IT_call_hash;
        default:
            return NULL;
        }
    case 7169: /* module 28 call 1 */
        switch (itemIdx) {
        case 0:
            return STR_IT_account_id;
        default:
            return NULL;
        }
    case 7170: /* module 28 call 2 */
        switch (itemIdx) {
        case 0:
            return STR_IT_root_hash;
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
            return STR_IT_target;
        default:
            return NULL;
        }
    case 7426: /* module 29 call 2 */
        switch (itemIdx) {
        case 0:
            return STR_IT_target;
        case 1:
            return STR_IT_schedule;
        default:
            return NULL;
        }
    case 7427: /* module 29 call 3 */
        switch (itemIdx) {
        case 0:
            return STR_IT_source;
        case 1:
            return STR_IT_target;
        case 2:
            return STR_IT_schedule;
        default:
            return NULL;
        }
    case 8192: /* module 32 call 0 */
        switch (itemIdx) {
        case 0:
            return STR_IT_rid;
        case 1:
            return STR_IT_local_addr;
        default:
            return NULL;
        }
    case 8193: /* module 32 call 1 */
        switch (itemIdx) {
        case 0:
            return STR_IT_rid;
        default:
            return NULL;
        }
#endif
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
    case 1280: /* module 5 call 0 */
        switch (itemIdx) {
        case 0: /* balances_transfer_V1 - dest */;
            return _toStringLookupSource_V1(
                &m->nested.balances_transfer_V1.dest,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* balances_transfer_V1 - value */;
            return _toStringCompactBalance(
                &m->nested.balances_transfer_V1.value,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1282: /* module 5 call 2 */
        switch (itemIdx) {
        case 0: /* balances_force_transfer_V1 - source */;
            return _toStringLookupSource_V1(
                &m->nested.balances_force_transfer_V1.source,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* balances_force_transfer_V1 - dest */;
            return _toStringLookupSource_V1(
                &m->nested.balances_force_transfer_V1.dest,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* balances_force_transfer_V1 - value */;
            return _toStringCompactBalance(
                &m->nested.balances_force_transfer_V1.value,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1283: /* module 5 call 3 */
        switch (itemIdx) {
        case 0: /* balances_transfer_keep_alive_V1 - dest */;
            return _toStringLookupSource_V1(
                &m->nested.balances_transfer_keep_alive_V1.dest,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* balances_transfer_keep_alive_V1 - value */;
            return _toStringCompactBalance(
                &m->nested.balances_transfer_keep_alive_V1.value,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1536: /* module 6 call 0 */
        switch (itemIdx) {
        case 0: /* staking_bond_V1 - controller */;
            return _toStringLookupSource_V1(
                &m->nested.staking_bond_V1.controller,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* staking_bond_V1 - value */;
            return _toStringCompactBalanceOf(
                &m->nested.staking_bond_V1.value,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* staking_bond_V1 - payee */;
            return _toStringRewardDestination_V1(
                &m->nested.staking_bond_V1.payee,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1537: /* module 6 call 1 */
        switch (itemIdx) {
        case 0: /* staking_bond_extra_V1 - max_additional */;
            return _toStringCompactBalanceOf(
                &m->nested.staking_bond_extra_V1.max_additional,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1538: /* module 6 call 2 */
        switch (itemIdx) {
        case 0: /* staking_unbond_V1 - value */;
            return _toStringCompactBalanceOf(
                &m->nested.staking_unbond_V1.value,
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
                &m->nested.staking_validate_V1.prefs,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1541: /* module 6 call 5 */
        switch (itemIdx) {
        case 0: /* staking_nominate_V1 - targets */;
            return _toStringVecLookupSource_V1(
                &m->nested.staking_nominate_V1.targets,
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
                &m->nested.staking_set_payee_V1.payee,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1544: /* module 6 call 8 */
        switch (itemIdx) {
        case 0: /* staking_set_controller_V1 - controller */;
            return _toStringLookupSource_V1(
                &m->nested.staking_set_controller_V1.controller,
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
                &m->nested.staking_rebond_V1.value,
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
#ifdef SUBSTRATE_PARSER_FULL
    case 0: /* module 0 call 0 */
        switch (itemIdx) {
        case 0: /* system_fill_block_V1 - _ratio */;
            return _toStringPerbill_V1(
                &m->nested.system_fill_block_V1._ratio,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1: /* module 0 call 1 */
        switch (itemIdx) {
        case 0: /* system_remark_V1 - _remark */;
            return _toStringBytes(
                &m->nested.system_remark_V1._remark,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 2: /* module 0 call 2 */
        switch (itemIdx) {
        case 0: /* system_set_heap_pages_V1 - pages */;
            return _toStringu64(
                &m->nested.system_set_heap_pages_V1.pages,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 3: /* module 0 call 3 */
        switch (itemIdx) {
        case 0: /* system_set_code_V1 - code */;
            return _toStringBytes(
                &m->nested.system_set_code_V1.code,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 4: /* module 0 call 4 */
        switch (itemIdx) {
        case 0: /* system_set_code_without_checks_V1 - code */;
            return _toStringBytes(
                &m->nested.system_set_code_without_checks_V1.code,
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
    case 1281: /* module 5 call 1 */
        switch (itemIdx) {
        case 0: /* balances_set_balance_V1 - who */;
            return _toStringLookupSource_V1(
                &m->nested.balances_set_balance_V1.who,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* balances_set_balance_V1 - new_free */;
            return _toStringCompactBalance(
                &m->nested.balances_set_balance_V1.new_free,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* balances_set_balance_V1 - new_reserved */;
            return _toStringCompactBalance(
                &m->nested.balances_set_balance_V1.new_reserved,
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
    case 5637: /* module 22 call 5 */
        switch (itemIdx) {
        case 0: /* palletbridge_set_token_transfer_fee_V1 - fee */;
            return _toStringBalance(
                &m->basic.palletbridge_set_token_transfer_fee_V1.fee,
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
    case 6656: /* module 26 call 0 */
        switch (itemIdx) {
        case 0: /* proxy_proxy_V1 - real */;
            return _toStringAccountId_V1(
                &m->nested.proxy_proxy_V1.real,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* proxy_proxy_V1 - force_proxy_type */;
            return _toStringOptionProxyType_V1(
                &m->nested.proxy_proxy_V1.force_proxy_type,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* proxy_proxy_V1 - call */;
            return _toStringCall(
                &m->nested.proxy_proxy_V1.call,
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
                &m->nested.multisig_as_multi_threshold_1_V1.other_signatories,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* multisig_as_multi_threshold_1_V1 - call */;
            return _toStringCall(
                &m->nested.multisig_as_multi_threshold_1_V1.call,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 6913: /* module 27 call 1 */
        switch (itemIdx) {
        case 0: /* multisig_as_multi_V1 - threshold */;
            return _toStringu16(
                &m->nested.multisig_as_multi_V1.threshold,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* multisig_as_multi_V1 - other_signatories */;
            return _toStringVecAccountId_V1(
                &m->nested.multisig_as_multi_V1.other_signatories,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* multisig_as_multi_V1 - maybe_timepoint */;
            return _toStringOptionTimepoint_V1(
                &m->nested.multisig_as_multi_V1.maybe_timepoint,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 3: /* multisig_as_multi_V1 - call */;
            return _toStringOpaqueCall_V1(
                &m->nested.multisig_as_multi_V1.call,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 4: /* multisig_as_multi_V1 - store_call */;
            return _toStringbool(
                &m->nested.multisig_as_multi_V1.store_call,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 5: /* multisig_as_multi_V1 - max_weight */;
            return _toStringWeight_V1(
                &m->nested.multisig_as_multi_V1.max_weight,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 6914: /* module 27 call 2 */
        switch (itemIdx) {
        case 0: /* multisig_approve_as_multi_V1 - threshold */;
            return _toStringu16(
                &m->nested.multisig_approve_as_multi_V1.threshold,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* multisig_approve_as_multi_V1 - other_signatories */;
            return _toStringVecAccountId_V1(
                &m->nested.multisig_approve_as_multi_V1.other_signatories,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* multisig_approve_as_multi_V1 - maybe_timepoint */;
            return _toStringOptionTimepoint_V1(
                &m->nested.multisig_approve_as_multi_V1.maybe_timepoint,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 3: /* multisig_approve_as_multi_V1 - call_hash */;
            return _toStringH256(
                &m->nested.multisig_approve_as_multi_V1.call_hash,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 4: /* multisig_approve_as_multi_V1 - max_weight */;
            return _toStringWeight_V1(
                &m->nested.multisig_approve_as_multi_V1.max_weight,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 6915: /* module 27 call 3 */
        switch (itemIdx) {
        case 0: /* multisig_cancel_as_multi_V1 - threshold */;
            return _toStringu16(
                &m->nested.multisig_cancel_as_multi_V1.threshold,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* multisig_cancel_as_multi_V1 - other_signatories */;
            return _toStringVecAccountId_V1(
                &m->nested.multisig_cancel_as_multi_V1.other_signatories,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* multisig_cancel_as_multi_V1 - timepoint */;
            return _toStringTimepoint_V1(
                &m->nested.multisig_cancel_as_multi_V1.timepoint,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 3: /* multisig_cancel_as_multi_V1 - call_hash */;
            return _toStringH256(
                &m->nested.multisig_cancel_as_multi_V1.call_hash,
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
#endif
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

    default:
        return false;
    }
}

bool _getMethod_IsNestingSupported_V1(uint8_t moduleIdx, uint8_t callIdx)
{
    uint16_t callPrivIdx = ((uint16_t)moduleIdx << 8u) + callIdx;

    switch (callPrivIdx) {
    case 256: // Utility:Batch
    case 768: // Timestamp:Set
    case 1539: // Staking:Withdraw Unbonded
    case 1545: // Staking:Set validator count
    case 1546: // Staking:Increase validator count
    case 1548: // Staking:Force no eras
    case 1549: // Staking:Force new era
    case 1550: // Staking:Set invulnerables
    case 1551: // Staking:Force unstake
    case 1552: // Staking:Force new era always
    case 1553: // Staking:Cancel deferred slash
    case 1554: // Staking:Payout stakers
    case 1556: // Staking:Set history depth
    case 1557: // Staking:Reap stash
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
    case 3074: // Grandpa:Note stalled
    case 4352: // Anchor:Pre commit
    case 4353: // Anchor:Commit
    case 4354: // Anchor:Evict pre commits
    case 4355: // Anchor:Evict anchors
    case 4608: // Fees:Set fee
    case 5376: // Identity:Add registrar
    case 5379: // Identity:Clear identity
    case 5380: // Identity:Request judgement
    case 5381: // Identity:Cancel request
    case 5382: // Identity:Set fee
    case 5383: // Identity:Set account id
    case 5386: // Identity:Kill identity
    case 5389: // Identity:Remove sub
    case 5390: // Identity:Quit sub
    case 5637: // PalletBridge:Set token transfer fee
    case 6144: // Indices:Claim
    case 6145: // Indices:Transfer
    case 6146: // Indices:Free
    case 6147: // Indices:Force transfer
    case 6148: // Indices:Freeze
    case 6657: // Proxy:Add proxy
    case 6658: // Proxy:Remove proxy
    case 6659: // Proxy:Remove proxies
    case 6660: // Proxy:Anonymous
    case 6661: // Proxy:Kill anonymous
    case 7169: // RadClaims:Set upload account
    case 7170: // RadClaims:Store root hash
    case 7424: // Vesting:Vest
    case 7425: // Vesting:Vest other
    case 7426: // Vesting:Vested transfer
    case 7427: // Vesting:Force vested transfer
    case 8192: // BridgeMapping:Set
    case 8193: // BridgeMapping:Remove
        return false;
    default:
        return true;
    }
}
