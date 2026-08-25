# Agent-B004 Current Assignment

Project context: this is a local old-game preservation effort for an unsupported NexusTK client, intended to keep the game runnable through archival compatibility research and faithful source reconstruction.

## UID0000N2 Same-Report Gate 1 Endpoint-Contract Repair

- Agent: `B004`; preserve `CHATGPT | 5.6 | xHigh`, use the project-level `ntk-b-agent-workflow` skill, and do not spawn subagents.
- Repair in place: `tools/leaser/Agents/Agent-B004/research/0000N2-RectBounds-file-source-quality.md`.
- Failed exact artifact SHA256: `DB0F6B747F7BA56B5F5D6624ECB2769A6FA51F87C87A1724D991FDD13D58F54F`.
- The prior I67 order repair is coherent and must be preserved. This is an additive exact-contract repair, not a rewrite.

## Exact Gate 1 Failures

1. Present desired-name registry rows still use `{addr:ADDR,name:NAME}`. Current successful `entity_query(kind:"names")` rows require exactly `{kind:"name",addr:ADDR,name:NAME}`. Repair all active surfaces, including shared Section 21 text, N11-N31, C065-C085, and exact checklist twins.
2. Distinguish request payloads from response rows. Preserve request `{addr,name}` objects. Dry pure-function rename responses must allow only `addr/old/name/dry_run:true`; persistent responses only `addr/old/name`. Forbid `dir`, `func_addr`, `new`, and persistent `dry_run`. Optional `error`/`dir_error` must be absent or exactly `""`.
3. Add literal immediate one-row result-envelope contracts for all ten `define_func` actions I01-I10.
4. Add literal immediate one-row result-envelope contracts for all 22 `set_type` actions I11T-I20T, I32-I42, and I66: exact submitted `edit` when emitted, correct `kind`, `ok:true`, and optional `error` absent or exactly `""`; reject extra rows, fields, or values.
5. Add the current one-row response contract for all 21 `set_repeatable_comments` actions I43-I63: mandatory exact target `addr`, optional `error` absent or `""`, and no extra row or top-level members.
6. Repair the affected Claim And Incorporation Ledger rows and exact checklist twins together. Reconcile Documentation Evidence And IDA Status, Final Recommendation, and terminal self-audit so they no longer claim complete schemas until the repaired text proves them.
7. Preserve action counts, protection counts, I24 -> I67 -> I35 -> I56 order, ordinary claims, formal CPP/H, current `84/91` allocation, one terminal marker, and all unrelated evidence.

## Restrictions And Return Boundary

- Edit only this report. No by-*, generated, coverage, tracker, audit, registry, lifecycle, archive, goal, IDB, or other-report edits.
- IDA/MCP use is read-only. Do not run validators, `execute_report`, or any mutation/save/start/stop/process-management operation.
- Lease the report only while editing and release immediately. End with zero B004 leases.
- Immediately use the status tool: `python .\tools\leaser\status\status.py -report working B004 "UID0000N2 endpoint-contract repair in progress"`; refresh at least every 15 minutes while active.
- On completion use `-report complete` with exact report SHA/shape, all repaired contract-surface counts, 175/175 twin proof, allocation proof, one-marker/zero-script proof, prohibited-action proof, and zero leases. Stop for a wholly fresh Supervisor Gate 1.
