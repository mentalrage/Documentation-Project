# Agent-B013 Current Assignment

- Use the project-level `ntk-b-agent-workflow` skill for all general B-agent instructions.
- Agent identity: `B013`.
- Required runtime/provenance for this assignment: `** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **`.
- Current supervisor cap/spec override: maintain 5 active B-agent workstreams using GPT 5.5 xHigh as the standing requirement.
- You are not alone in the codebase. Do not revert edits made by others.

Project context: this is a local old-game preservation effort for an unsupported NexusTK client, intended to keep the game runnable through archival compatibility research and faithful source reconstruction.

## Current Assignment

- Mode: implementation callback after supervisor Gate 1 pass.
- Target: [UID:0004G9] `by-memory/0x0041a550-0x0041a564.FittingRoomDownloadProgressStateResetPrimary.md`.
- Accepted report: `tools/leaser/Agents/Agent-B013/research/0004G9-FittingRoomDownloadProgressStateResetPrimary-source-quality.md`.
- Accepted report SHA256: `FFE736E3CDA55D860838711E82383B71C2890442684352ED76CB4C5E9E347D78`.
- Gate 1 audit: `tools/leaser/Agents/b-report-validation-audit.md`, entry `2026-07-08T18:26:00-04:00 - B013 UID0004G9 Current Artifact Gate 1 Audit`, state `GATE1_PASSED`.
- Required return: implement the accepted report details, update the report ledger/checklist, run scoped validators for edited by-* files, then stop with `READY_FOR_SUPERVISOR_EXECUTE`.

## Accepted Implementation Scope

Use the report's `Claim And Incorporation Ledger`, `Recommended Target Doc Changes`, `Recommended Support Doc Changes`, and `Implementation Tracking Checklist`.

Target page:

- Edit `by-memory/0x0041a550-0x0041a564.FittingRoomDownloadProgressStateResetPrimary.md`.
- Change metadata to `COMPLETION:87`, `CONFIDENCE:91`.
- Preserve `CANONICAL_OWNER:0000JE`, `RECONSTRUCTABLE:TRUE`, blank `EMITTER_UIDS`, and blank formal C++.
- Incorporate the report facts at report-level detail:
  - current MCP IDB session `b001-0002wl-readonly`;
  - current `lookup_funcs` result for `0x0041a550` size `0x14`, `0x0041a564` not a function, and successor `0x0041a570` `nullsub_15`;
  - current `analyze_function` result: byte `+0x00` zero, dword `+0x04` zero, dword `+0x08` zero, return receiver, no callers, no callees;
  - zero incoming xrefs for `0x0041a550`;
  - no absolute VA pointer-pattern hits;
  - the sole `50 A5 01 00` RVA-style hit at `0x006545e0` is a non-route, section-name-style byte coincidence with no xrefs;
  - sibling contrast: percent child `0x0041a580` has the one live code xref from `0x0041cbbc`, while this reset primary does not.
- Preserve the exact no-code proof. Do not add any first-draft/example/sample C++.
- Preserve historical B006 no-route proof as historical/supporting evidence, but do not leave stale wording that implies old session `c9b60f19` is the only current evidence.

Support docs:

- `by-memory/0x0041a550-0x0041a5c1.FittingRoomDownloadProgressStateHelpers.md`: edit only if it lacks same-or-greater detail for the B013 current MCP recheck and the RVA false-positive note. If already present, mark `already-present` in the report ledger/checklist.
- `by-type/by-struct/FittingRoomDownloadProgressState.md`, `by-class/FittingRoomDialog.md`, `by-class/FittingRoomDownloadControlPane.md`, and `by-memory/0x0041cb70-0x0041cd38.FittingRoomDialogHandleFittingAction.md`: no required edit if current docs already carry same-or-greater layout/live-percent-helper/non-emitting sibling detail; record `already-present` or exact exclusion reason in the report.

Report update:

- Update `tools/leaser/Agents/Agent-B013/research/0004G9-FittingRoomDownloadProgressStateResetPrimary-source-quality.md` after edits.
- For every accepted ledger row, update verification state to `applied`, `already-present`, `historicalized`, `not-applicable`, or `excluded-with-reason`.
- Check off the implementation callback checklist items that are actually complete.
- Record changed files, leases used/released, validator commands/results, command IDs/timestamps, exit code, `ok` count, warnings, and generated-refresh state.

## Validation

Run scoped file validation from `source-3/project-documentation` for every edited by-* file. At minimum, run:

```powershell
python .\tools\validator.py --mode file --file by-memory\0x0041a550-0x0041a564.FittingRoomDownloadProgressStateResetPrimary.md --apply --queue-timeout 240
```

## Boundaries

- Lease only files you need to edit and release leases immediately after edits.
- Do not edit generated files, coverage reports, supervisor ledgers, validator state, queue files, lock files, archives, lifecycle files, IDA DB files, or unrelated docs.
- Do not run `execute_report`, dry-run/probing execute variants, registry lifecycle/archive commands, manual report moves, archive moves, or equivalent lifecycle commands.
- Do not start, stop, restart, or kill IDA/MCP.
- If validators or MCP fail transiently, retry briefly. If they remain blocked, stop and return the exact blocker.

## Return Condition

Return only when the callback is complete with:

- `READY_FOR_SUPERVISOR_EXECUTE`
- report path and new SHA256
- changed files
- leases used and released
- validator commands/results including command IDs/timestamps, exit codes, `ok` counts, warnings, and generated-refresh observations
- confirmation that no generated files, coverage reports, supervisor ledgers, validator state, lifecycle/archive files, manual report moves, or `execute_report` variants were touched
