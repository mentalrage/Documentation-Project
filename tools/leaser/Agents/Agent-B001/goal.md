# Agent-B001 Current Assignment

Project context: this is a local old-game preservation effort for an unsupported NexusTK client, intended to keep the game runnable through archival compatibility research and faithful source reconstruction.

## UID0000JM Same-Report Gate 2A Incorporation Repair

- Agent: `B001`; preserve `CHATGPT | 5.6 | xHigh`, use the project-level `ntk-b-agent-workflow` skill, and do not spawn subagents.
- Repair additively in place: `tools/leaser/Agents/Agent-B001/research/0000JM-FrameMgr-file-source-quality.md`.
- Failed artifact: SHA256 `A1EF5ADF535AB9EC4313D7FB8B8CA295BCCCEEF52EFC8DF7776BA55697D811FB`; 344385 bytes; 1605 LF; zero CR; terminal LF; 33 headings; 170/170 twins; 164 checked / 6 unchecked.
- Controlling audit: `2026-08-25T21:08:00Z - B001 UID0000JM Gate 2A FAIL - Ten Ordinary Incorporation Defects`.

## Exact Required Repair

1. Preserve all valid research, the prior Gate 1 repair, 154 passing checked claims, formal CPP/H, generated semantics, all IDA handoff rows/protections, claim IDs/order/twins/allocation, manual coverage payloads, and one terminal marker. Do not rewrite the report from scratch.
2. Repair C048-C051 by incorporating into `by-memory/0x004b6cb0-0x004b7112.FrameScheduler.md` the report's exact incoming xref addresses and complete per-function callee inventories for the FrameHandler destructor, next-frame wrapper, remove wrapper, and delayed wrapper. Counts or abbreviated callee summaries are insufficient.
3. Repair C075 by adding the exact currently claimed IDA type `void *()` for `sub_4B7120` to `by-memory/0x004b7120-0x004b731f.BuildFramePartPanes.md`, preserving its exact range/size/no-caller/UID000578 source route and no FrameMgr merge.
4. Repair C101, C102, and C104 by adding to `FrameScheduler.md` the exact half-open ranges and claim-specific relationships for `0x005ff100`, `0x005f6800`, and `0x005ff133`: FrameHandler destructor EH, scalar-wrapper metadata, and FrameMgr-constructor EH. A grouped dependency list is insufficient.
5. Repair C113 by reconciling `by-file/FrameMgr.md:14`; no active prose may say the current file score remains `88/91`. Preserve the dated historical transition while making current authority unambiguously `94/94`.
6. Repair C119 by reconciling `by-memory/0x0061a7dc-0x0061a7f8.FrameHandlerFrameMgrVtableData.md:28`; no active prose may call the direct parent `88/91`. Current direct parent authority is `94/94`; preserve dated history separately.
7. Lease each affected file only while editing and release immediately. Run scoped file validators from `source-3/project-documentation` for every changed by-* destination with exact syntax `python .\tools\validator.py --mode file --file <relative-by-star-path> --apply --queue-timeout 240`; use `--wait-generated` on the final relevant validation.
8. Update the report's affected target/support/change/validator/generated receipts and checked claim rows additively. Preserve all report-level detail. Reread every changed destination and generated artifact before claiming completion.
9. Return exact final SHA256/bytes/LF/CR/terminal LF, 33 headings, 170/170 twins, 164/6 allocation, one marker, zero executable fences/conflicts/status locks, all changed destination hashes, validator command IDs/results, current generated freshness, and zero leases.

## Restrictions And Status

- Do not edit coverage reports, tracker, audit ledger, validator registry/lifecycle files, goal after this assignment, IDA, MCP state, generated files directly, or unrelated reports.
- Do not run `execute_report` or any lifecycle/report-status command. The supervisor owns Gate 1, Gate 2, coverage, IDA, and execution.
- FIRST ACTION: run `python .\tools\leaser\status\status.py -report working B001 "UID0000JM Gate2A incorporation repair in progress"`. Refresh `working` within 15 minutes while active. On completion run the same tool with `complete`, exact artifact/mechanical proof and zero leases, then stop for wholly fresh supervisor Gate 1 and Gate 2A.
