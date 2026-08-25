** TARGET-REPORT-UID:00013M **
** AUTHOR-AGENT-ID:B009 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# B009 Source-Quality Research Report - 00013M DecoderAndCodecVtableGlue

Agent: B009  
Assignment: `B009-report-00013M-DecoderAndCodecVtableGlue-source-quality-20260627`  
Mode: report-only research first  
Target: [UID:00013M] `by-memory/0x004a5630-0x004a5e54.DecoderAndCodecVtableGlue.md`  
Required report path: `tools/leaser/Agents/Agent-B009/research/00013M-DecoderAndCodecVtableGlue-source-quality.md`

## Executive Recommendation

Keep [UID:00013M] as a reviewed non-emitting BinaryCodec grouping index:

- `COMPLETION:85`
- `CONFIDENCE:89`
- `CANONICAL_OWNER:0000HQ`
- `RECONSTRUCTABLE:FALSE`
- `EMITTER_UIDS:` blank
- `RECONSTRUCTION_CPP CODE` blank

The live 2026-06-27 IDA MCP pass confirms the current source-page disposition. The page is not a source-emitting method or type. It overlaps exact Encoder and Decoder child method/vtable-support pages plus the non-emitting raw Decoder reader family index. The safe implementation callback is to add a new 2026-06-27 MCP refresh note to the target page and a matching change-log entry, while preserving all current metadata and blank C++.

No support by-* documentation needs content changes for this target. `by-file/BinaryCodec.md`, `by-file/Encoder.md`, `by-file/Decoder.md`, `by-class/Encoder.md`, `by-class/Decoder.md`, `by-type/by-vtable/BinaryCodecVtables.md`, and `by-type/by-struct/BinaryCodecCursorLayout.md` already express the current owner/source route and the non-emitting aggregate policy.

## Current State And Tracker Mismatch

Target source page current state:

- [UID:00013M] is already `85/89`, `CANONICAL_OWNER:0000HQ`, `RECONSTRUCTABLE:FALSE`, with blank emitters and blank C++.
- The page states that it is a non-emitting grouping index over exact child pages, not a direct source-output page.

Generated reports are stale and must not be manually edited:

- `auto-generated/-ag-research-tracker.md` still lists [UID:00013M] as `78/88`, combined `83.0`, reconstructable `true`, reports `0`.
- `auto-generated/-ag-coverage-report-by-memory.md` still describes [UID:00013M] as `reconstructable : 78%` while also showing `emits_code:false`.

Implementation should use validator-generated refresh after the accepted target edit. Do not hand-edit generated tracker or coverage rows.

## Evidence Sources Checked

Local documentation checked:

- `tools/leaser/Agents/Agent-B009/goal.md`
- `by-memory/0x004a5630-0x004a5e54.DecoderAndCodecVtableGlue.md`
- `by-file/BinaryCodec.md`
- `by-file/Encoder.md`
- `by-file/Decoder.md`
- `by-class/Encoder.md`
- `by-class/Decoder.md`
- `by-type/by-vtable/BinaryCodecVtables.md`
- `by-type/by-struct/BinaryCodecCursorLayout.md`
- `by-memory/0x004a5680-0x004a5dce.DecoderRawReaderFamily.md`
- `by-memory/0x004a5630-0x004a5631.EncoderNoopVirtual.md`
- `by-memory/0x004a5df0-0x004a5df1.DecoderNoopVirtual.md`
- `by-memory/0x004a5e00-0x004a5e24.DecoderScalarDeletingDestructor.md`
- `by-memory/0x004a5e30-0x004a5e54.EncoderScalarDeletingDestructor.md`
- `auto-generated/-ag-research-tracker.md`
- `auto-generated/-ag-coverage-report-by-memory.md`

Live IDA MCP evidence checked in current active session:

- `idb_list`
- `server_health(database=b001_000241_20260627)`
- `lookup_funcs`
- `entity_query`
- `analyze_component`
- `analyze_function`
- `xrefs_to`
- `xref_query`
- `find_bytes`
- `get_int`
- `get_bytes`

MCP session details:

- Active session: `b001_000241_20260627`
- IDB path: `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`
- Module: `NexusTK.exe`
- Imagebase: `0x400000`
- Health: OK
- Auto-analysis ready: true
- Hex-Rays ready: true
- Strings cache ready: true

## Positive MCP Evidence

Function inventory for `0x004a5600-0x004a5e80`:

- `0x004a5630` is `nullsub_27`, size `0x1`.
- `0x004a5640` is `sub_4A5640`, size `0x24`.
- `0x004a5670` is `sub_4A5670`, size `0x7`.
- `0x004a5dd0` is `sub_4A5DD0`, size `0x1d`.
- `0x004a5df0` is `nullsub_28`, size `0x1`.
- `0x004a5e00` is `sub_4A5E00`, size `0x24`.
- `0x004a5e30` is `sub_4A5E30`, size `0x24`.
- `0x004a5e60` is `sub_4A5E60`, size `0x23f`.

Modeled body behavior:

- `0x004a5630` decompiles/disassembles as a single `retn`; it has no callers/callees and is reached only through data at `0x006192d0`.
- `0x004a5640` stores the Decoder vtable, clears `+0x04/+0x08/+0x0c`, writes `0x0101` at `+0x10`, and returns `this`.
- `0x004a5670` only restores the Decoder vtable and returns.
- `0x004a5dd0` returns the old byte at `+0x11`, clears `+0x04/+0x08/+0x0c`, restores `+0x11` to `1`, and returns the prior validity state.
- `0x004a5df0` decompiles/disassembles as a single `retn`; it has no callers/callees and is reached only through data at `0x006192dc`.
- `0x004a5e00` is Decoder scalar deleting destructor glue: it restores the Decoder vtable, tests the hidden delete flag, conditionally calls `sub_5C7526`, returns `this`, and ends with `retn 4`.
- `0x004a5e30` is Encoder scalar deleting destructor glue with the same generated-wrapper shape for the Encoder vtable.

Vtable and boundary data:

- `get_bytes(0x006192c8, 24)` returned the compact Encoder/Decoder vtable sequence:
  - `0x006192c8 -> 0x00646b2c`
  - `0x006192cc -> 0x004a5e30`
  - `0x006192d0 -> 0x004a5630`
  - `0x006192d4 -> 0x00646b74`
  - `0x006192d8 -> 0x004a5e00`
  - `0x006192dc -> 0x004a5df0`
- `get_int(0x006192e0)` returned `0x1a`, not a function pointer.
- `xrefs_to(0x006192cc)` shows Encoder vtable-base refs from `0x004a4e70`, `0x004a4ea0`, and `0x004a5e3a`.
- `xrefs_to(0x006192d8)` shows Decoder vtable-base refs from `0x004a5640`, `0x004a5670`, and `0x004a5e0a`.
- `xrefs_to(0x006192e0)` shows the only data ref is from `0x004a5e9e` inside adjacent `sub_4A5E60`.
- `xrefs_to(0x004a5e60)` shows code refs from `0x0049c4d4` and `0x0049c524`, confirming the adjacent DAT helper has its own caller route outside BinaryCodec glue.

Padding and range checks:

- `get_bytes(0x004a5621, 15)` returned only `0xcc`.
- `get_bytes(0x004a5dce, 2)` returned `0xcc 0xcc`.
- `get_bytes(0x004a5e54, 12)` returned only `0xcc`.
- `get_bytes(0x004a5630, 1)` and `get_bytes(0x004a5df0, 1)` returned `0xc3`, matching one-byte no-op virtual bodies.

## Negative MCP Evidence

Raw Decoder starts remain non-functions:

- `lookup_funcs` reports `Not a function` for raw starts `0x004a5680`, `0x004a5690`, `0x004a56c0`, `0x004a5710`, `0x004a5770`, `0x004a57e0`, `0x004a5870`, `0x004a5930`, `0x004a5a40`, `0x004a5bb0`, `0x004a5c80`, `0x004a5cd0`, `0x004a5d80`, and `0x004a5db0`.
- `xrefs_to` reports zero incoming refs to every raw Decoder start.
- `xref_query` shows only local outgoing fall-through records from each raw start, not external callers or table entries.
- `find_bytes` found no VA or RVA pointer patterns for any raw Decoder start.
- Control patterns are reliable: the same `find_bytes` method finds real vtable pointers for `0x004a5630` at `0x006192d0` and `0x004a5e00` at `0x006192d8`.

This negative evidence is current-scope research, not future work. It caps final-audit confidence for raw reader reachability and original method names, but it does not justify making [UID:00013M] reconstructable. The exact raw child pages already own source-bearing method content where appropriate.

## Ownership And Source Placement

The correct canonical owner for [UID:00013M] is [UID:0000HQ] BinaryCodec.

Reasoning:

- The target range spans both Encoder and Decoder vtable/lifecycle support. A single class owner would be inaccurate.
- `by-file/BinaryCodec.md` is the family coordinator for shared codec layout/vtable evidence and records the adjacent DAT boundary.
- `by-file/Encoder.md` owns concrete Encoder source output under `NexusTK/util/Encoder.cpp`.
- `by-file/Decoder.md` owns concrete Decoder source output under `NexusTK/util/Decoder.cpp`.
- Exact Encoder child pages route through [UID:00004F] Encoder and [UID:0000J1] Encoder.
- Exact Decoder child pages route through [UID:00003M] Decoder and [UID:0000IQ] Decoder.
- The adjacent `0x004a5e60` helper is DATFile territory, not BinaryCodec, proven by the `0x006192e0` data ref and external callers.

No owner change is recommended. No support page reroute is recommended.

## Split And Range Analysis

No new split is needed.

The target is already an intentional broad index over exact child pages:

- [UID:00013L] `0x004a5630-0x004a5631.EncoderNoopVirtual`
- [UID:00013N] `0x004a5640-0x004a5664.DecoderConstructor`
- [UID:00013O] `0x004a5670-0x004a5677.DecoderDestructor`
- [UID:00013Q] `0x004a5680-0x004a5dce.DecoderRawReaderFamily`
- [UID:00013S] `0x004a5dd0-0x004a5ded.DecoderFinalize`
- [UID:00013T] `0x004a5df0-0x004a5df1.DecoderNoopVirtual`
- [UID:00013U] `0x004a5e00-0x004a5e24.DecoderScalarDeletingDestructor`
- [UID:00013V] `0x004a5e30-0x004a5e54.EncoderScalarDeletingDestructor`

Boundary proof:

- Preceding padding: `0x004a5621-0x004a5630`.
- Internal raw-family/finalize separator: `0x004a5dce-0x004a5dd0`.
- Following padding: `0x004a5e54-0x004a5e60`.
- Adjacent next function: `0x004a5e60`, a DAT parser helper with independent callers.

The broad `0x004a5630-0x004a5e54` page should remain a non-emitting audit/index to avoid duplicate output over the exact children.

## First-Draft C++ And Exact No-Code Proof

Do not add C++ to [UID:00013M].

Exact no-code proof:

- The page is an overlap/container across multiple exact child pages.
- It contains both source-authored methods and compiler-generated vtable/deleting-destructor glue.
- The raw reader family inside it is itself a non-emitting index over exact child pages that already carry first-draft method C++ where accepted.
- Handwritten C++ here would duplicate exact child output or author compiler-generated scalar deleting destructor and vtable mechanics directly.
- The active C++ gate requires `RECONSTRUCTABLE:TRUE`, nonblank emitter route, and a valid source output path. This page intentionally has `RECONSTRUCTABLE:FALSE` and blank emitters.

Correct source representation:

- Source declarations belong in Encoder/Decoder class/file docs.
- Concrete child method bodies belong on exact child pages.
- Scalar deleting destructors remain compiler-generated wrapper evidence, not handwritten source.
- No-op virtual source names remain descriptive placeholders, not proven original symbol names.

## Score Assessment

Keep `85/89`.

Completion rationale:

- The page documents the current index disposition, child inventory, owner route, vtable dwords, function boundaries, padding, DAT boundary, and C++ no-code policy.
- Current MCP reconfirms all high-value boundary and ownership facts.
- Raising much above 85 would overstate a container page whose purpose is not source emission.

Confidence rationale:

- Vtable identity, modeled function behavior, padding, and adjacent DAT boundary are strong.
- Confidence remains below final-audit range because raw Decoder starts still lack IDA function objects, direct callers, VA/RVA pointer routes, and original method names/signatures.
- The no-op virtual names are descriptive, not proven original names.
- Exact original header/source split between separate Encoder/Decoder files and a compact BinaryCodec header remains a final-audit caveat, not a current blocker.

Do not lower the score. The stale generated reports are out of sync with the source page, not evidence that the source page should revert.

## Naming And IDA DB Recommendations

No IDA DB edits are recommended during this report-only pass.

Documentation naming:

- Keep `EncoderNoopVirtual` and `DecoderNoopVirtual` as source-quality descriptive documentation names.
- Do not use `nullsub_27` or `nullsub_28` as source-facing names.
- Do not model the no-op slots as pure virtual; both bodies are concrete `ret` functions.
- Keep scalar deleting destructor pages as compiler-generated wrapper evidence.
- Do not hand-author `Encoder::ScalarDeletingDestructor` or `Decoder::ScalarDeletingDestructor` in final source.

## Rule 26 Blocker Investigation

| Blocker | Current-scope investigation | Result | Implementation impact |
| --- | --- | --- | --- |
| Score mismatch with assignment tracker | Compared target source header to generated tracker and coverage rows. | Source page is current `85/89` and non-reconstructable; generated rows are stale. | Preserve target score; refresh generated rows via validator after implementation. |
| Ownership/emitter route | Checked BinaryCodec, Encoder, Decoder, class pages, vtable type page, and MCP vtable/function evidence. | BinaryCodec aggregate owner is correct; exact children carry class/file routes. | No owner/emitter change. |
| Source placement | Checked `NexusTK/util/Encoder.cpp`, `NexusTK/util/Decoder.cpp`, and BinaryCodec coordinator evidence. | Exact children belong in Encoder/Decoder routes; aggregate belongs to BinaryCodec coordinator. | No support source-root change. |
| Raw Decoder reachability | Rechecked `lookup_funcs`, `xrefs_to`, `xref_query`, and VA/RVA `find_bytes` for all raw starts. | No function objects, no incoming refs, no pointer routes. | Record as confidence cap, not future work. |
| Split/range | Checked function inventory, padding bytes, raw-family boundaries, and adjacent `0x004a5e60`. | Existing exact child split is correct; DAT boundary is outside target. | No new split. |
| Vtable boundary | Rechecked vtable bytes, dwords, vtable-base refs, and `0x006192e0`. | Encoder/Decoder compact vtables are confirmed; `0x006192e0` is DAT constant data. | Add 2026-06-27 evidence refresh only. |
| First-draft C++ | Checked active code gate and exact child dispositions. | Aggregate must not emit C++; exact child pages carry source output where appropriate. | Keep C++ blank. |
| Source-quality naming | Checked no-op and scalar deleting destructor support pages. | No-op names are descriptive placeholders; scalar deleting destructors are compiler glue. | No rename or final-source promotion. |

## Implementation Plan For Supervisor Callback

When the supervisor approves implementation, lease only:

- `by-memory/0x004a5630-0x004a5e54.DecoderAndCodecVtableGlue.md`

Do not lease or edit support docs unless the supervisor explicitly expands scope.

Implementation edits:

1. Keep all [UID:00013M] header metadata unchanged: `85/89`, `0000HQ`, `RECONSTRUCTABLE:FALSE`, blank emitters, blank C++.
2. Add a `2026-06-27 B009 live IDA MCP refresh` subsection under `## Live IDA Evidence` or append it after the existing 2026-06-16 entry.
3. Add a matching `2026-06-27 B009 source-quality report` entry under `## Changes`.
4. Record the active MCP session `b001_000241_20260627`, health OK, `NexusTK.exe`, imagebase `0x400000`, auto-analysis ready, Hex-Rays ready.
5. Summarize the function inventory, raw-start negative evidence, vtable dwords/refs, padding bytes, and adjacent DAT boundary.
6. Do not add C++.
7. Do not edit generated tracker/coverage rows manually.
8. Run scoped validation with generated refresh after the target edit.

No manual coverage report text is required. No project-level generated file, manual `-coverage-report.md`, validator/tool state, or IDA DB edit is part of the implementation plan beyond the validator command's normal generated refresh during the implementation callback.

## Implementation Tracking Checklist

- [x] Target header remains `COMPLETION:85` and `CONFIDENCE:89`. Proof: `by-memory/0x004a5630-0x004a5e54.DecoderAndCodecVtableGlue.md` header checked after validator `000000004603`.
- [x] Target header remains `CANONICAL_OWNER:0000HQ`. Proof: target header checked after validator `000000004603`.
- [x] Target remains `RECONSTRUCTABLE:FALSE`. Proof: target header checked after validator `000000004603`; generated coverage row now renders `not_reconstructable`.
- [x] `EMITTER_UIDS` and `EMITTER_POSITION_OPTIONAL` remain blank. Proof: target header checked after validator `000000004603`.
- [x] `RECONSTRUCTION_CPP CODE` remains blank. Proof: target inline C++ header remains `[[[]]]` and BEGIN/END block is empty after validator `000000004603`.
- [x] New evidence note records MCP session `b001_000241_20260627` and `server_health` OK. Proof: target `2026-06-27 B009 live IDA MCP refresh` note added under `## Live IDA Evidence`.
- [x] New evidence note records the exact modeled function list: `0x004a5630`, `0x004a5640`, `0x004a5670`, `0x004a5dd0`, `0x004a5df0`, `0x004a5e00`, `0x004a5e30`, plus adjacent `0x004a5e60`. Proof: target B009 evidence note lists names and sizes.
- [x] New evidence note records raw Decoder starts as non-functions with zero incoming refs and no VA/RVA pointer routes. Proof: target B009 evidence note records the full raw-start list, `xrefs_to` zero incoming refs, `find_bytes` no VA/RVA pointer routes, and `xref_query` local fall-through only.
- [x] New evidence note records Encoder/Decoder vtable dwords and vtable-base refs. Proof: target B009 evidence note records `0x006192c8-0x006192dc` dwords and refs from Encoder/Decoder vtable-base stores.
- [x] New evidence note records `0x006192e0 -> 0x1a` as adjacent DAT constant data with ref from `0x004a5e9e`. Proof: target B009 evidence note records the value, ref, and adjacent DAT helper boundary.
- [x] New evidence note records padding at `0x004a5621-0x004a5630`, `0x004a5dce-0x004a5dd0`, and `0x004a5e54-0x004a5e60`. Proof: target B009 evidence note records all three padding envelopes.
- [x] Change-log entry states that no score, owner, route, split, emitter, or C++ change is needed. Proof: target `## Changes` now has `2026-06-27 B009 source-quality report` with unchanged metadata/no-code disposition.
- [x] Support by-* scope updated per accepted callback. Proof: `by-file/BinaryCodec.md` now has a concise B009 2026-06-27 status/evidence/change note stating [UID:00013M] was rechecked with current MCP, remains a non-emitting BinaryCodec family/index page, and exact children remain source-owned emitters where applicable.
- [x] No generated reports were edited manually. Proof: generated tracker/coverage were refreshed only by validator commands `000000004603` and `000000004604`.
- [x] No IDA DB changes were made. Proof: implementation used documentation edits and validators only.
- [x] Scoped validators were run after implementation. Proof: target validator `python .\tools\validator.py --mode file --file by-memory\0x004a5630-0x004a5e54.DecoderAndCodecVtableGlue.md --apply --wait-generated` returned exit code `0`, `command_id: 000000004603`, `command_timestamp: 2026-06-27T21:49:06-04:00`, `ok: 1`, `generated_refresh: completed`; support validator `python .\tools\validator.py --mode file --file by-file\BinaryCodec.md --apply --wait-generated` returned exit code `0`, `command_id: 000000004604`, `command_timestamp: 2026-06-27T21:49:24-04:00`, `ok: 1`, `generated_refresh: completed`.
- [x] Generated output is current. Proof: `auto-generated/-ag-coverage-report-by-memory.md` and `auto-generated/-ag-research-tracker.md` headers show `validator-command-id: 000000004604`, `validator-refreshed-at: 2026-06-27T21:49:24-04:00`, matching the final foreground generated refresh; [UID:00013M] rows now show `85/89`, combined `87.0`, `false` reconstructable in the tracker and `not_reconstructable : 85%` in by-memory coverage.
- [x] Leases were released. Proof: leased `by-memory/0x004a5630-0x004a5e54.DecoderAndCodecVtableGlue.md` and `by-file/BinaryCodec.md` as `B009`, then released both with `leaser.py B009 unlease`; current lease report shows no active B009 rows.
- [x] Validator warnings recorded. Proof: both validators reported existing stale registry/missing-file diagnostics; BinaryCodec validator also reported `missing_ref_uid` for `0003IA`, `0003IB`, and `0003IC`. Those referenced files exist with matching UID headers, but repairing validator registry state for those extra files was outside the accepted callback's listed edit and validator scope, so no extra file validators were run.

## Exact Validation Commands

Run from `E:\NTK\GhidraBridge\source-3\project-documentation` after the implementation edit:

> Executable block R001 was removed from this report and preserved verbatim in [00013M-DecoderAndCodecVtableGlue-source-quality-removed.md](00013M-DecoderAndCodecVtableGlue-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

Actual implementation run results:

> Executable block R002 was removed from this report and preserved verbatim in [00013M-DecoderAndCodecVtableGlue-source-quality-removed.md](00013M-DecoderAndCodecVtableGlue-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

`execute_report` was not run; supervisor verification remains required before executed-report lifecycle handling.

## Implementation Callback Compliance

- Leases taken: `by-memory/0x004a5630-0x004a5e54.DecoderAndCodecVtableGlue.md`, `by-file/BinaryCodec.md`.
- Leases released: yes; current lease report shows no active B009 rows.
- Target/support by-* docs edited: target [UID:00013M] and support [UID:0000HQ].
- Generated docs or reports manually edited: no; validator refreshed generated outputs.
- Manual coverage reports edited: no.
- IDA DB edited: no.
- Subagents spawned: none.
- Validators run: both required scoped validators with generated refresh complete.
- Report checklist updated: yes.
- Report file retained at `tools/leaser/Agents/Agent-B009/research/00013M-DecoderAndCodecVtableGlue-source-quality.md`.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B009","command_id":"000000004165","destination_path":"executed-b-agent-research/B009/00013M-DecoderAndCodecVtableGlue-source-quality.md","details":"legacy registry reconstruction","event":"executed","source_path":"tools/leaser/Agents/Agent-B009/research/00013M-DecoderAndCodecVtableGlue-source-quality.md","timestamp":"2026-06-27T21:59:04","uid":"00013M"} -->
<!-- {"agent":"B009","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 00013M-DecoderAndCodecVtableGlue-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B009/00013M-DecoderAndCodecVtableGlue-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"00013M"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
