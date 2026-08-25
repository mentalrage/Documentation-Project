** TARGET-REPORT-UID:0004G7 **
** AUTHOR-AGENT-ID:B012 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | Medium **
# 0004G7 BulletinSessionOpenMailListDialog Source-Quality Research


## Finalized Report / Current Recommendation

- Current recommendation: [UID:0004G7] `by-memory/0x00471dd0-0x00471e96.BulletinSessionOpenMailListDialog.md` has been updated as a detailed source-bearing `BulletinSession` method child owned by [UID:00001D] `BulletinSession`.
- Final disposition after implementation callback: `RECONSTRUCTABLE:TRUE`, `CANONICAL_OWNER:00001D`, blank `EMITTER_UIDS`, blank formal C++, no split or rename. Score movement `84/90` to `88/92` is applied on the target.
- Current action state: accepted target/support documentation has been incorporated and scoped validators have run. The artifact is awaiting supervisor Gate 2 verification/execution; no B012 implementation work remains unless supervisor finds a defect.
- Confidence: strong for range, behavior, owner, source placement, helper role names, and no-code disposition; medium-high for final method name and source-facing field aliases because exact original spellings remain unavailable.

## Supporting Research

- Lifecycle/status notes: historical report-only research was accepted for implementation. The implementation callback has now edited only accepted target/support by-* docs, run scoped validators, and updated this report ledger. No coverage files, generated files by hand, lifecycle/archive commands, or `execute_report` commands were run.
- MCP status: fresh IDB-backed session `supervisor_20260703_reopen` was used for this repair. Read-only health returned status `ok`, IDB `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, module `NexusTK.exe`, input path `C:\Users\admin\Desktop\Clone\NexusTK\NexusTK.exe`, imagebase `0x400000`, auto-analysis ready, Hex-Rays ready, and strings cache size `2067`.
- Stale MCP note: earlier session ids `b010_00032w_20260703` and `d3e83820` are historical only and were not used for the repaired conclusion.

## Target

- Target UID: `0004G7`.
- Target path: `by-memory/0x00471dd0-0x00471e96.BulletinSessionOpenMailListDialog.md`.
- Source queue/report row: `auto-generated/-ag-research-tracker.md` -> `## by-memory` -> `### Not-Covered Files - Reconstructable`, assignment-time row `84/90`, combined `87.0`, reconstructable `true`, reports `0`.
- Current supervisor classification: post-Gate-1 implementation callback awaiting supervisor Gate 2 verification.
- Current scores and parent state: target is now `COMPLETION:88`, `CONFIDENCE:92`, owner [UID:00001D], reconstructable `TRUE`, blank `EMITTER_UIDS`, blank C++; parent [UID:0000ZH] remains a non-emitting split/index parent at `88/91`.

## Current Target State

- Current metadata: `COMPLETION:88`, `CONFIDENCE:92`, `CANONICAL_OWNER:00001D`, `RECONSTRUCTABLE:TRUE`, blank `EMITTER_UIDS`, blank `RECONSTRUCTION_CPP CODE`.
- Current owner/emitter/reconstructable state: source-bearing child method under [UID:00001D] `BulletinSession`, still non-emitting because no direct call-to-start route is recovered and dispatcher case `4` carries the live routed path.
- Current C++/emitter state: intentionally blank. The target page has target-specific no-code proof and no emitter route.
- Current open questions/blockers: exact original private method symbol and whether a private-helper route exists outside current xrefs remain unresolved. The target/support docs now carry fresh session `supervisor_20260703_reopen` facts, exact callee/caller inventories, rectangle/allocation constants, `+0x102`/`MailListDialog + 0x274` data flow, no-xref-to-start caveat, resolved helper/API role names, and target-specific code-entry decision.
- Related target/support docs checked: [UID:0000ZH] `BulletinSessionCore`, [UID:0004G1] dispatcher, [UID:0004G8] mail-read result handler, [UID:00001D] `BulletinSession`, [UID:0000HX] `BulletinSession`, [UID:0000KZ] `MailDialogs`, [UID:00007L] `MailListDialog`, [UID:0003PU] `MailListDialogCore`, [UID:00007M] `MailListPane`, [UID:0003PV] `MailListPaneCore`, [UID:000132] `DialogSession` stack-helper index, generated tracker/coverage rows, and relevant executed B-agent reports for MailDialogs/MailListDialog/MailListPane/MailDialog support.
- Current artifact/lifecycle status: active report file in `tools/leaser/Agents/Agent-B012/research/`; implementation callback complete; not executed or archived.

## Executive Recommendation

- Best direct owner: [UID:00001D] `BulletinSession`. The target is a `BulletinSession` private/helper method that creates a `MailListDialog`, pushes it through the `DialogSession` stack, stores returned mail-list dialog id/state into `BulletinSession + 0x102`, and returns that id.
- Source placement: eventual method implementation belongs in [UID:0000HX] `BulletinSession.cpp` through [UID:00001D], while the concrete `MailListDialog` constructor/body stays in [UID:0000KZ] `MailDialogs.cpp` / [UID:00007L].
- Assignment/code disposition: keep blank `EMITTER_UIDS` and blank C++. The combined score clears the code-entry numeric threshold, and this repair resolves the previously vague helper/declaration blockers into source-facing documentation directions: `DialogSession::PushDialog(DialogInSession *)` is already formal on [UID:00003U], `0x004b7c50` is a four-int `Rect` initializer best named `MakeRect`/`InitRectBounds`, `0x004f4aa0` is the MemoryMan-backed allocation wrapper best represented as normal `new`, `MailListDialog` constructor direction is `MailListDialog(BulletinSession *, const Rect &, const unsigned char *mailListPayload)`, `BulletinSession +0x102` is an inferred `m_activeListId`/active list-dialog id slot, and `MailListDialog +0x274` is the returned dialog/list id field. These are implementation-ready support-doc directions, not future research deferrals.
- Exact no-code decision after repair: do not emit C++ from UID0004G7 now because fresh MCP still reports zero xrefs to `0x00471dd0`, while dispatcher case `4` at `0x00471550` contains the live routed inline mail-list open path with the same constructor/push/id-store sequence plus the `+0x100` gate/clear. Emitting UID0004G7 as a standalone method would require inventing an unobserved private call route or duplicating dispatcher case `4` source. That source-shape problem remains after helper declarations are resolved.

## Supervisor Active Recheck

- Current supervisor instruction: implement the Gate-1-accepted UID0004G7 report using `ntk-b-agent-workflow`, edit only accepted target/support docs, run scoped validators, update this report ledger/checklist, and do not run execute/lifecycle commands or spawn subagents.
- Split repair status: no new split is required. UID0004G7 is already one exact child created by the accepted UID0000ZH split.
- Source-bearing child status: UID0004G7 already exists and now has the accepted owner/reconstructable/blank-emitter disposition, score improvement, documentation details, and no-code proof applied.

## Inference Research Guidance Check

- `by-structure.md` affected the recommendation by separating ownership (`CANONICAL_OWNER`) from output routing (`EMITTER_UIDS`). The class owner is strong, but emission must remain blank until formal code is ready and routed to a valid file root.
- Existing docs treated as uncertain or incomplete: the short target page, old session id evidence, generic "active list/dialog id" wording, and "future source route" prose. These are directionally correct but underdocumented for Gate 1/source-quality purposes.
- IDA facts: function boundary/size, disassembly, decompilation, callees, no direct xrefs to function start, xrefs to interior constructor/push/store call sites, bytes/padding, helper roles, and dispatcher case relationship from `supervisor_20260703_reopen`.
- Documentation evidence: current by-* docs already support `BulletinSession` ownership, `MailDialogs` as concrete dialog owner, `DialogSession::PushDialog`, and `MailListDialog + 0x274`/row dependencies.
- Inference: source-facing name should be `BulletinSession::OpenMailListDialog` or `BulletinSession::OpenMailList`. `OpenMailListDialog` is preferred for this page because it mirrors the operation and current filename while remaining descriptive rather than pretending exact original symbol proof.
- Wave2/Wave3 artifacts: generated names such as `sub_471DD0`, `_WORD *this`, `byte_66DA97`, and `sub_4F4AA0` are treated as leads only. No stale Wave2/Wave3 source was used as authority.

## Heuristic / Inference Reanalysis And Validation

- Method name: `BulletinSession::OpenMailListDialog` is the best source-facing name. Evidence: dispatcher submode `4` and this body allocate `0x278` bytes, call `MailListDialog` constructor `0x00479110`, push the dialog, then store the returned id. Rejected names: `HandleMailListPacket` is too broad and belongs to dispatcher-level semantics; `CreateMailListDialog` misses the stack-push and state-store behavior; `MailListDialog::MailListDialog` belongs to [UID:00007L]/[UID:0003PU], not this method.
- Parameter: the single explicit argument is the packet/list payload pointer passed through to `MailListDialog` as the fourth constructor argument. Source-facing direction is `const unsigned char *mailListPayload` or equivalent packet view; use that prose in target/support docs, but do not freeze a formal type in C++ until the whole BulletinSession dispatcher packet API is emitted.
- Return value: function returns the 16-bit value read from the constructed `MailListDialog + 0x274`. This value is stored at `BulletinSession + 0x102`, so it is best described as active mail-list dialog id/state, not a generic success boolean.
- `BulletinSession + 0x102`: current docs call it an active list/dialog id slot. This report now resolves the documentation direction as inferred `m_activeListId` / active list-dialog id: UID0004G7 writes `this + 0x102` from `MailListDialog + 0x274` immediately after pushing the dialog, and dispatcher cases for article-list and mail-list use the same slot. Do not claim the exact original member spelling, but support docs should stop treating the role as unresolved.
- `BulletinSession + 0x100`: dispatcher case `4` gates mail-list creation on `*(this + 0x100) == 1` and clears it after storing `+0x102`; the standalone UID0004G7 child does not clear `+0x100`. This distinction should be preserved so target docs do not overclaim the child body.
- Rectangle/layout constants: both dispatcher case `4` and UID0004G7 choose rectangle `(10,10,461,430)` when `byte_66DA97 == 1`, otherwise `(10,10,456,376)`. Decimal/hex conversions verified with `tools/int_convert.py`: `0x1cd` = `461`, `0x1ae` = `430`, `0x1c8` = `456`, `0x178` = `376`. `byte_66DA97` remains best documented as `g_useEpfAssets`/layout mode, not as a proven exact source symbol.
- Allocation: UID0004G7 calls allocator `0x004f4aa0` with `0x278` bytes (`632`, verified with `tools/int_convert.py`) before invoking `MailListDialog` constructor. Fresh MCP decompiles `0x004f4aa0` as a 0x14-byte wrapper that calls `sub_516030()` and `sub_516050(size)`, matching existing MemoryMan allocation-helper documentation; source-facing docs should describe this as normal `new MailListDialog(...)`, not as a hand-written allocator call.
- Callees: target calls rectangle helper `0x004b7c50`, allocator `0x004f4aa0`, `MailListDialog` constructor `0x00479110`, `DialogSession::PushDialog` at `0x004a0fc0`, and security-cookie support. Fresh MCP decompiles `0x004b7c50` as a four-int rectangle initializer writing left/top/right/bottom into a 16-byte record; use `MakeRect`/`InitRectBounds` and `Rect` as source-facing names. [UID:00003U] already formally declares `DialogSession::PushDialog(DialogInSession *dialog)`, so that is no longer an unresolved blocker.
- Caller/reachability: MCP reports no xrefs to function start `0x00471dd0`; the child is an exact helper body without a recovered direct call-to-start route. It is still source-bearing because it is a modeled function in the `BulletinSession` method island and duplicates the dispatcher case `4` open-mail-list sequence as a clean helper-shaped body.
- Duplicate/relationship caveat: dispatcher case `4` contains an inline mail-list creation path at `0x004716e0-0x004716bd`, while UID0004G7 contains the same open/push/store body without the active-flag gate/clear. Both should be documented as related; do not merge them or emit both blindly until class source shape decides whether one was an inline helper, a private method, or compiler/codegen duplication.
- Range boundary: `lookup_funcs` reports UID0004G7 size `0xc6` (`198`, verified with `tools/int_convert.py); bytes before start include `0xcc` padding at `0x00471dcd-0x00471dcf`, and bytes after `0x00471e96` are `0xcc` until the next function at `0x00471ea0`. Boundary is clean.
- C++ readiness: not ready, but the reason is narrowed. `Rect`/`MakeRect`, MemoryMan-backed `new`, `MailListDialog(BulletinSession *, const Rect &, const unsigned char *)`, `PushDialog(DialogInSession *)`, inferred `m_activeListId`, and returned dialog id are all safe documentation directions now. Formal C++ remains blank because fresh MCP still proves no entry xref to UID0004G7 and the dispatcher already contains the live case-4 path; writing a standalone method body would invent a private call route or duplicate the dispatcher source path.

## Evidence Standards Used

- IDA MCP exact-address facts were preferred over generated docs: `server_health`, `lookup_funcs`, `xrefs_to`, `callees`, `analyze_function`, `decompile`, `disasm`, `basic_blocks`, and `get_bytes` where available, with repaired evidence against database `supervisor_20260703_reopen`.
- Documentation evidence was used as support, not authority: by-* pages for `BulletinSession`, `BulletinSessionCore`, dispatcher, `MailDialogs`, `MailListDialog`, `MailListDialogCore`, `MailListPane`, `MailListPaneCore`, and `DialogSession` stack helpers.
- Negative evidence counted: no xrefs to the function start, no function at the exclusive end, dispatcher case-4 duplicate/live route, and the absence of a proven private call route prevent a formal source body. Field/helper roles are now documentation-ready directions rather than unresearched blockers.
- Evidence is strong enough for score/metadata improvement because the exact function behavior, boundaries, owner, helper roles, and support relationships are now directly checked. It is not strong enough for emitter/C++ because the function still lacks an entry route and duplicates the dispatcher case-4 source path.

## Evidence Checked

- IDA MCP checks performed:
  - `server_health` on `supervisor_20260703_reopen` returned `ok` for `NexusTK.exe.i64` with Hex-Rays ready.
  - `lookup_funcs` on `0x00471dd0`, `0x00471550`, `0x00479110`, `0x0047a8a0`, `0x00471ea0`, `0x00471dc0`, and `0x00471e96`.
  - `xrefs_to` on `0x00471dd0`, `0x00479110`, `0x004a0fc0`, `0x00471ea0`, and target interior addresses `0x00471e51`, `0x00471e66`, `0x00471e72`.
  - `callees`, `analyze_function`, `decompile`, `disasm`, `basic_blocks`, and prior byte/padding evidence for `0x00471dd0`; repaired MCP reconfirmed decompile/callee/xref facts.
  - Bounded support calls: `analyze_function 0x00479110`, `decompile 0x00471550`, `decompile 0x004b7c50`, `decompile 0x004f4aa0`, and `decompile 0x004a0fc0`.
- Local/project checks performed: target page, parent/sibling memory pages, class/file support docs, generated tracker/coverage rows, executed B reports for `MailDialogs`, `MailListDialog`, `MailListPane`, and `MailDialog`.
- Numeric conversion checks: `tools/int_convert.py` for `0x278`, `0x274`, `0x102`, `0x100`, `0x1cd`, `0x1ae`, `0x1c8`, `0x178`, and `0xc6`.
- Negative checks performed: no existing active report for UID0004G7 found; fresh MCP `xrefs_to` reports zero xrefs to `0x00471dd0`; `lookup_funcs` reports `0x00471e96` is not a function in the previous target-boundary pass.
- Callback checks performed: accepted target/support docs were edited and scoped validators `000000005717` through `000000005722` ran successfully. No `idb_open`, lifecycle, archive, manual generated, coverage, or `execute_report` commands were run.

## Claim And Incorporation Ledger

| Claim ID | Claim | Confidence | Evidence | Destination doc/section | Action | Verification state |
| --- | --- | --- | --- | --- | --- | --- |
| C1 | UID0004G7 is an exact modeled function at `0x00471dd0-0x00471e96`, size `0xc6`/198. | Strong | MCP `lookup_funcs`, `disasm`, `get_bytes`; `0xc6` verified with `tools/int_convert.py`. | Target `Status` / `MCP Evidence` | incorporated | Applied in target; validator `000000005717` ok. |
| C2 | The function creates a `MailListDialog`, pushes it into the `DialogSession` stack, stores the returned id/state at `BulletinSession + 0x102`, and returns it. | Strong | MCP `decompile`/`analyze_function` lines call `0x00479110`, `0x004a0fc0`, load `[esi+0x274]`, store `[edi+0x102]`. | Target `Behavior` / `Touched State` | incorporated | Applied in target and BulletinSession support; validators `000000005717`, `000000005721`, `000000005722` ok. |
| C3 | The source-facing method name should be `BulletinSession::OpenMailListDialog` or equivalent. | Strong inference | Behavior, dispatcher submode `4`, current filename, MailDialogs docs. | Target `Signature` / `Heuristic` | incorporated | Applied in target and BulletinSession support; validators `000000005717`, `000000005721`, `000000005722` ok. |
| C4 | Direct owner remains [UID:00001D] `BulletinSession`; concrete `MailListDialog` remains [UID:00007L]/[UID:0000KZ]. | Strong | Constructor call-in from BulletinSession, class/file docs, support pages, rejected owner analysis. | Target `Owner` / class/file support docs | incorporated | Applied in target, BulletinSession, MailDialogs, and MailListDialog support; validators `000000005717`-`000000005722` ok. |
| C5 | `EMITTER_UIDS` and formal C++ should remain blank despite score improvement. | Strong | Missing formal `BulletinSession` field names, `MailListDialog` constructor signature, `DialogSession::PushDialog` declaration, and code-entry quality rules. | Target metadata/C++ / `No-Code Proof` | incorporated | Applied in target with blank emitter/C++; validator `000000005717` ok. |
| C6 | Recommended score moves to `88/92`. | Medium-high | Exact fresh MCP evidence removes sparse-page and helper-name blockers; zero entry xrefs and dispatcher/source-shape duplication cap completion below 90 and confidence below 95. | Target metadata / score rationale | incorporated | Applied in target; validator `000000005717` ok and updated scores. |
| C7 | Rectangle selection uses `(10,10,461,430)` for `byte_66DA97 == 1`, else `(10,10,456,376)`. | Strong | MCP disasm/decompile; constants verified with `tools/int_convert.py`. | Target `Raw Code Evidence` / support docs | incorporated | Applied in target and BulletinSession support; validators `000000005717`, `000000005721`, `000000005722` ok. |
| C8 | Allocation size is `0x278`/632 bytes for `MailListDialog`; returned id is at `MailListDialog + 0x274`/628. | Strong | MCP decompile/disasm; constants verified with `tools/int_convert.py`; MailListDialog support docs. | Target `Touched State` / MailDialogs support | incorporated | Applied in target, BulletinSession, MailDialogs, and MailListDialog support; validators `000000005717`, `000000005719`, `000000005720`, `000000005721`, `000000005722` ok. |
| C9 | No direct xrefs to function start were found; do not overclaim direct caller route. | Strong | MCP `xrefs_to 0x00471dd0` returned zero xrefs. | Target `Callers/Callees` / no-code proof | incorporated | Applied in target, dispatcher, and BulletinSession support; validators `000000005717`, `000000005718`, `000000005721`, `000000005722` ok. |
| C10 | Dispatcher case `4` has a related inline open-mail-list path that also calls `0x00479110` and stores `+0x102`, but it additionally gates and clears `+0x100`. | Strong | MCP `decompile 0x00471550`; current [UID:0004G1]. | Target `Relationship To Dispatcher` / support docs | incorporated | Applied in target and dispatcher; validator `000000005718` ok. |
| C11 | `DialogSession::PushDialog(DialogInSession *dialog)` is not an unresolved blocker for documentation; [UID:00003U] already carries declaration-level C++ for it. | Strong | [UID:00003U] class C++; fresh MCP `decompile 0x004a0fc0` confirms the push/list behavior and `+0xf8/+0xfc` use. | Target no-code proof; `by-class/BulletinSession.md`; `by-file/BulletinSession.md` | incorporated | Applied in target and BulletinSession support; validators `000000005717`, `000000005721`, `000000005722` ok. |
| C12 | `0x004b7c50` is a 16-byte rectangle initializer best documented as `MakeRect`/`InitRectBounds` over a `Rect`/bounds record. | Strong | Fresh MCP `decompile 0x004b7c50` writes `a1[0..3]` as left/top/right/bottom; sibling B reports use `MakeRect`/`InitRectBounds`. | Target helper evidence; support docs | incorporated | Applied in target and BulletinSession support; validators `000000005717`, `000000005721`, `000000005722` ok. |
| C13 | `0x004f4aa0` is a MemoryMan-backed allocation wrapper and should be represented as ordinary `new` in source-facing prose, not as a retained helper call. | Strong | Fresh MCP `decompile 0x004f4aa0` calls `sub_516030` and `sub_516050(size)`; MemoryMan docs identify those as allocator helpers. | Target helper evidence; support docs | incorporated | Applied in target and BulletinSession support; validators `000000005717`, `000000005721`, `000000005722` ok. |
| C14 | `MailListDialog` constructor direction is `MailListDialog(BulletinSession *, const Rect &, const unsigned char *mailListPayload)`; exact formal type spelling remains a code-integration cap, not an unresolved documentation blocker. | Medium-high | Fresh MCP `analyze_function 0x00479110` prototype `int __thiscall(int this, int, int *, int)`, callers `sub_471550` and `sub_471DD0`; [UID:00007L]/[UID:0003PU] constructor docs. | Target signature notes; `MailDialogs`/`MailListDialog` support | incorporated | Applied in target, MailDialogs, MailListDialog, and BulletinSession support; validators `000000005717`, `000000005719`, `000000005720`, `000000005721`, `000000005722` ok. |
| C15 | `BulletinSession +0x102` should be documented as inferred `m_activeListId`/active list-dialog id, and `MailListDialog +0x274` as the returned dialog/list id. | Medium-high | UID0004G7 and dispatcher case `4` copy `dialog+628` to `session+258`; constructor report for UID0004FS used `m_activeListId`; MailListDialog size/allocation supports `+0x274` tail id field. | Target touched state; BulletinSession support | incorporated | Applied in target and BulletinSession support; validators `000000005717`, `000000005721`, `000000005722` ok. |
| C16 | Formal C++ remains blank after blocker repair because UID0004G7 has no entry xref and duplicates the live dispatcher case-4 source path; emitting it would invent a call route or duplicate source. | Strong | Fresh MCP `xrefs_to 0x00471dd0` zero; `decompile 0x00471550` case `4` and `decompile 0x00471dd0` show same constructor/push/id-store body with dispatcher-only gate/clear. | Target `No-Code Proof`; `First-Draft C++ Recommendation` | incorporated | Applied in target, dispatcher, and BulletinSession support; validators `000000005717`, `000000005718`, `000000005721`, `000000005722` ok. |

## Positive Evidence Summary

- Direct facts supporting the chosen recommendation: fresh MCP proves the exact target function, clean boundary, concrete callee list, dialog allocation/constructor call, `DialogSession::PushDialog` call, and `+0x102` store/return.
- Corroborating docs: [UID:00001D] and [UID:0000HX] already place `BulletinSession` session coordination in `BulletinSession.cpp`; [UID:0000KZ], [UID:00007L], and [UID:0003PU] already place the concrete `MailListDialog` implementation in `MailDialogs.cpp`.
- Strongest inference chain: dispatcher submode `4` plus UID0004G7 both construct `MailListDialog`; UID0004G7 uses the `BulletinSession` receiver and writes `BulletinSession + 0x102`; therefore ownership stays with `BulletinSession`, while callee implementation stays in `MailDialogs`.

## IDA MCP Facts

- Function/range facts: `lookup_funcs` reports `0x00471dd0` as `sub_471DD0`, size `0xc6`; `0x00471e96` is not a function; next modeled function is `0x00471ea0` size `0x151`; preceding address `0x00471dc0` belongs to `0x00471c00` size `0x1cd`.
- Data/table/padding facts: bytes at `0x00471dcd-0x00471dcf` and `0x00471e96-0x00471e9f` are `0xcc` padding; jump-table bytes at `0x00471872` point into dispatcher case labels and are not part of this child.
- Xref facts: `xrefs_to 0x00471dd0` returns zero xrefs. `xrefs_to 0x00479110` returns constructor call sites `0x0047173f` from dispatcher and `0x00471e51` from UID0004G7. `xrefs_to 0x004a0fc0` includes `0x00471e66` from UID0004G7 among 15 stack-push callers.
- Callee facts: UID0004G7 calls `0x004b7c50`, `0x004f4aa0`, `0x00479110`, `0x004a0fc0`, and security-cookie support.
- Decompilation facts: UID0004G7 chooses a rectangle through `byte_66DA97`, allocates `0x278`, constructs `MailListDialog`, pushes it, reads `*(dialog + 0x274)`, stores it at `*(this + 0x102)`, and returns the 16-bit value.
- Negative IDA facts: no xrefs to start; Hex-Rays prototype is decompiler-shaped `__int16 __thiscall(_WORD *this, int)`, so source-level types remain unresolved.

## Function / Child Inventory

| Range / Item | UID / Path | Role | Reconstructable | Direct Parent | Score | Status |
| --- | --- | --- | --- | --- | --- | --- |
| `0x00471dd0-0x00471e96` | [UID:0004G7] `by-memory/0x00471dd0-0x00471e96.BulletinSessionOpenMailListDialog.md` | `BulletinSession::OpenMailListDialog` helper | TRUE | [UID:00001D] | applied `88/92` | target docs updated; blank emitter/C++ kept |
| `0x00471550-0x00471872` | [UID:0004G1] dispatcher | caller/related inline case for submode `4` | TRUE | [UID:00001D] | unchanged | case-4 support relationship applied |
| `0x00479110-0x0047a894` | [UID:0003PU] `MailListDialogCore` | concrete dialog constructor/list packet island | TRUE | [UID:00007L] | unchanged | constructor caller/direction support applied through MailDialogs/MailListDialog docs |
| `0x004a0fc0` | [UID:000132] indexed stack helper | `DialogSession::PushDialog` route | source-bearing child candidate under DialogSession | [UID:00003U] when split | unchanged | push-helper caveat incorporated in target/support docs |

## Direct Xref / Caller Inventory

| Address / Item | Xref / Caller / Callee | Meaning |
| --- | --- | --- |
| `0x00471dd0` | no xrefs to function start | Retain no-direct-start caveat; do not claim a recovered direct caller. |
| `0x00471e51` | call to `0x00479110` from UID0004G7 | Constructs `MailListDialog`. |
| `0x00471e66` | call to `0x004a0fc0` from UID0004G7 | Pushes constructed dialog into `DialogSession`. |
| `0x00471e72` | store to `[edi+0x102]` | Saves returned 16-bit active mail-list dialog id/state into `BulletinSession`. |
| `0x0047173f` | dispatcher call to `0x00479110` | Related inline submode `4` path in dispatcher. |
| `0x00479110` | callers `0x0047173f`, `0x00471e51` | Concrete `MailListDialog` constructor called from dispatcher and UID0004G7. |
| `0x004a0fc0` | 15 xrefs including `0x00471e66` | Shared `DialogSession::PushDialog` helper used by board/article/mail flows. |

## Documentation Evidence And IDA Status

- Existing docs that support conclusion: target page already states `BulletinSession` ownership and mail-list dialog creation; [UID:0004G1] records dispatcher submode `4`; [UID:00001D]/[UID:0000HX] route `BulletinSession`; [UID:0000KZ]/[UID:00007L]/[UID:0003PU] route concrete `MailListDialog`; [UID:000132] records `DialogSession::PushDialog`.
- Historical docs that were stale/incomplete before callback: target page cited stale MCP session `b010_00032w_20260703` and lacked fresh `supervisor_20260703_reopen` evidence, direct xref/callee inventory, rectangle/allocation constants, helper/API role resolution, no-direct-start caveat, and detailed C++ blocker proof. The callback has applied those facts to the target/support docs.
- Generated/coverage report state: generated by-memory coverage shows UID0004G7 as reconstructable but `emits_code:false`. That remains correct under this report; the target is now better documented but still non-emitting.

## Ranked Ownership Analysis

### 1. [UID:00001D] BulletinSession

- Evidence for: target receives `this` as `BulletinSession`, writes `this + 0x102`, is inside the exact `BulletinSession` method island, matches dispatcher mail-list submode behavior, and uses `DialogSession` stack helpers through the session object.
- Evidence against: concrete dialog constructor body and row/list behavior belong to `MailDialogs`, not `BulletinSession`.
- Decision: keep as direct owner. This page documents the session coordinator method, not the concrete dialog class.

### 2. [UID:0000HX] BulletinSession file root

- Evidence for: source route for `BulletinSession` class; owns coordinator source module and singleton/session method family.
- Evidence against: direct semantic owner should be the class [UID:00001D], not the by-file root, until emitted through the class route.
- Decision: possible output route only after a UID0004G7 source-route proof exists and formal C++ is ready; do not set `EMITTER_UIDS` yet.

### 3. [UID:00007L]/[UID:0000KZ] MailListDialog / MailDialogs

- Evidence for: target allocates `0x278` bytes and calls the `MailListDialog` constructor `0x00479110`; [UID:00007L]/[UID:0003PU] own that concrete dialog implementation.
- Evidence against: UID0004G7 itself operates on `BulletinSession` state and pushes through session stack; it is a caller/coordinator method, not a `MailListDialog` member.
- Decision: support/callee owner only. Do not reassign UID0004G7 to `MailDialogs`.

### 4. [UID:00003U]/[UID:0000IU] DialogSession

- Evidence for: target calls `DialogSession::PushDialog` at `0x004a0fc0`.
- Evidence against: push is shared infrastructure; target-specific behavior is mail-list session routing and `BulletinSession + 0x102` state.
- Decision: support dependency only.

### 5. No-owner/non-emitting

- Evidence for: no direct xrefs to the function start and final C++ is blocked.
- Evidence against: modeled function body is NexusTK-owned session source behavior with strong class owner evidence; no-owner would lose clear semantic ownership.
- Decision: reject no-owner. Keep reconstructable true and owner [UID:00001D], but blank emitter/C++.

## Source Placement

- Recommended placement: target method belongs to `BulletinSession` in `NexusTK/ui/dialogs/BulletinSession.cpp` once formal C++ exists.
- Why it fits: the method coordinates session stack state and constructs a mail dialog as a callee; it parallels other `BulletinSession` open-dialog helpers for board/article/mail flows.
- Rejected placements: `MailDialogs.cpp` owns the callee implementation, not this session method; `DialogSession.cpp` owns the push helper only; `BulletinReplyAlerts.cpp` is not involved.
- Remaining uncertainty: exact original split between dispatcher inline case `4` and the no-direct-start UID0004G7 helper. This blocks C++ body emission because emitting both as final source could duplicate source semantics unless the private helper/inline relationship is resolved.

## Range / Split / Padding / Reclassification Analysis

- Exact range/boundary facts: `0x00471dd0-0x00471e96`, size `0xc6`/198. Bytes immediately before and after include `0xcc` padding, and the next function begins at `0x00471ea0`.
- Children/subranges to create, repair, merge, leave ignored, or leave no-owner: none. The existing split is exact.
- Padding/table/data/code distinctions: target body is code; `0x00471e96-0x00471e9f` is padding; dispatcher jump table at `0x00471872` is separate [UID:0004G2] data.
- Parent/container impact: no parent reclassification needed. [UID:0000ZH] remains the non-emitting split/index parent.

## Negative Evidence Summary

- No direct xrefs to `0x00471dd0`: this prevents overclaiming a recovered call route and contributes to the C++ deferral.
- Decompiler prototype uses `_WORD *this` and `int` parameter rather than source types: exact original type spellings are not recovered, although documentation directions are now established.
- `+0x102` and `MailListDialog + 0x274` exact original spellings are not final, but documentation direction is no longer open-ended: use inferred `m_activeListId` / active list-dialog id for `BulletinSession +0x102` and returned dialog/list id for `MailListDialog +0x274`.
- Dispatcher case `4` duplicates much of the body with extra `+0x100` gating/clear: final source shape must resolve whether UID0004G7 is private helper, duplicate inlined body, or a callback-reachable method before emitting source.
- Concrete dialog ownership is not target ownership: a callee constructor at `0x00479110` does not move UID0004G7 to `MailDialogs`.

## IDA Rename / Type / Comment Recommendations

- IDA DB edits were not requested or performed during implementation callback.
- Source-facing name applied in docs: `BulletinSession::OpenMailListDialog`.
- Source-facing parameter prose: `mailListPayload` or `packetData`, not formal until packet type exists.
- Source-facing field prose: inferred `m_activeListId` / active list-dialog id for `BulletinSession + 0x102`; identify exact member spelling as not recovered rather than unresearched.
- Callee role names: `MakeRect`/`InitRectBounds` for `0x004b7c50`, ordinary `new` through MemoryMan-backed allocation for `0x004f4aa0`, `MailListDialog::MailListDialog(BulletinSession *, const Rect &, const unsigned char *mailListPayload)` for `0x00479110`, and formal `DialogSession::PushDialog(DialogInSession *dialog)` for `0x004a0fc0`.

## First-Draft C++ Recommendation

- Eligible for draft C++: no, despite reconstructable status and a combined score above the numeric threshold, because `EMITTER_UIDS` is blank and the target has no proven source route distinct from the dispatcher case-4 inline path.
- Recommended code: none.
- Reason it preserves exact original behavior: leaving C++ blank avoids inventing an unobserved private call route to `0x00471dd0` or duplicating dispatcher case `4`, which is the live routed path that performs the same mail-list construction plus `+0x100` gate/clear.
- Reason it matches the most plausible original precompiled source shape: the method almost certainly resembled a small private `BulletinSession` helper, but the project does not yet know whether the dispatcher case or this no-direct-start function is the actual source spelling/body to emit.
- Inferred names/types/fields: `BulletinSession::OpenMailListDialog`, `MailListDialog(BulletinSession *, const Rect &, const unsigned char *mailListPayload)`, `DialogSession::PushDialog(DialogInSession *)`, `MakeRect`/`InitRectBounds`, MemoryMan-backed `new`, `m_activeListId`/active list-dialog id at `BulletinSession +0x102`, returned dialog/list id at `MailListDialog +0x274`, and `g_useEpfAssets` layout mode.
- Naming/coding style: CamelCase class/method names match existing `BulletinSession`, `MailListDialog`, and `MailListPane` docs.
- Reason code should remain blank: target has no emitter route and, after resolving helper/API roles, still has no recovered entry route separate from the dispatcher case-4 inline body.
- Exact no-code proof: MCP session `supervisor_20260703_reopen` proves UID0004G7 is a modeled source-shaped function at `0x00471dd0-0x00471e96`, but `xrefs_to 0x00471dd0` returns zero xrefs. The same fresh session decompiles dispatcher `0x00471550` case `4` as the live path that checks `*(this+0x100)==1`, builds the same bounds, allocates `0x278`, calls `MailListDialog` constructor `0x00479110`, pushes through `DialogSession::PushDialog`, copies `dialog+0x274` to `this+0x102`, and clears `this+0x100`. UID0004G7 contains the constructor/push/store subset but lacks the gate/clear and has no caller. Current docs can now name `PushDialog`, `MakeRect`/`InitRectBounds`, MemoryMan-backed `new`, `m_activeListId`, and the constructor direction, so the remaining block is not unresearched declarations. The block is exact source-shape safety: emitting UID0004G7 would invent a private helper route or duplicate dispatcher case `4` source. Keep `EMITTER_UIDS` and formal C++ blank.

## Final Recommendation

- Exact changes applied: UID0004G7 page now carries fresh MCP evidence, detailed behavior, callers/callees, touched state, source-facing name, no-direct-start caveat, rectangle/allocation constants, dispatcher relationship, no-code proof, and score rationale.
- Exact parent assignments after callback: kept `CANONICAL_OWNER:00001D`, `RECONSTRUCTABLE:TRUE`, blank `EMITTER_UIDS`, blank C++.
- Exact items left no-owner/non-emitting and why: none newly. UID0004G7 remains owned/reconstructable but non-emitting because code-entry quality is not met.
- Exact future work outside this assignment: only a later source-route proof for UID0004G7, such as a recovered private call/vector route or authoritative source evidence that this no-direct-start body was an intentional retained private helper, should allow C++ emission. Declaration/help-name synchronization alone is no longer listed as the blocker.

## Recommended Target Doc Changes

- Target path: `by-memory/0x00471dd0-0x00471e96.BulletinSessionOpenMailListDialog.md`.
- Callback status: applied and validated by command `000000005717`.
- Exact report facts incorporated:
  - Fresh MCP session `supervisor_20260703_reopen` evidence: function size `0xc6`, no xrefs to start, callees, decompile/disasm facts, helper decompilations, and historical clean padding evidence.
  - Behavior: creates rectangle, allocates `0x278` bytes for `MailListDialog`, calls constructor `0x00479110`, pushes through `0x004a0fc0`, stores/returns `*(dialog + 0x274)` into `BulletinSession + 0x102`.
  - Dispatcher relationship: submode `4` in [UID:0004G1] has related inline path with `+0x100` gate/clear; UID0004G7 itself only performs open/push/store/return.
  - Source-facing name: `BulletinSession::OpenMailListDialog` as inferred/descriptive.
  - Source-facing resolved helper/API names: `MakeRect`/`InitRectBounds`, `Rect`, MemoryMan-backed `new`, `MailListDialog(BulletinSession *, const Rect &, const unsigned char *mailListPayload)`, `DialogSession::PushDialog(DialogInSession *)`, `m_activeListId`/active list-dialog id at `BulletinSession +0x102`, and returned dialog/list id at `MailListDialog +0x274`.
  - No-code proof exactly as stated in `First-Draft C++ Recommendation`.
- Metadata/score/owner/emitter/reconstructable/C++ changes applied: score changed to `COMPLETION:88`, `CONFIDENCE:92`; owner `00001D`, reconstructable `TRUE`, blank `EMITTER_UIDS`, and blank C++ preserved.
- Historical/stale assumptions, rejected alternatives, and negative evidence preserved: prior split-callback origin and old `b010_00032w_20260703`/`d3e83820` evidence are historical; fresh `supervisor_20260703_reopen` proof is current; rejection of `MailDialogs`, `DialogSession`, and no-owner as direct owner is preserved; no-direct-start caveat is preserved.

## Recommended Support Doc Changes

- Support path: `by-class/BulletinSession.md`.
  - Callback status: applied and validated by command `000000005721`.
  - Exact facts incorporated: UID0004G7 method note mentions allocation size `0x278`, rectangle constants, `MailListDialog + 0x274 -> BulletinSession + 0x102` store, inferred `m_activeListId` / active list-dialog id direction for `+0x102`, `MakeRect`/`InitRectBounds`, MemoryMan-backed `new`, formal `DialogSession::PushDialog(DialogInSession *)`, no direct xrefs to the helper start, dispatcher case-4 duplicate/live route, and blank-emitter/no-code proof based on route/source-shape rather than vague missing declarations.
  - Metadata/link/score changes: none beyond validator-owned stats updates.
- Support path: `by-file/BulletinSession.md`.
  - Callback status: applied and validated by command `000000005722`.
  - Exact facts incorporated: proposed contents row for UID0004G7 carries the same fresh behavior/no-code evidence and clarifies it is a future emitter only if a call/vector/private-helper source route is proven; declaration-only synchronization is not enough because dispatcher case `4` already carries the live routed path.
  - Metadata/link/score changes: none beyond validator-owned stats updates.
- Support path: `by-memory/0x00471550-0x00471872.BulletinSessionPacketDispatcher.md`.
  - Callback status: applied and validated by command `000000005718`.
  - Exact facts incorporated: case `4` relationship to UID0004G7 now states dispatcher case `4` gates on `+0x100`, creates `MailListDialog`, stores `+0x102`, clears `+0x100`; UID0004G7 is a related helper-shaped open-mail-list body without the gate/clear.
  - Metadata/link/score changes: none beyond validator-owned UID link/reference index updates.
- Support path: `by-file/MailDialogs.md` and [UID:00007L] `by-class/MailListDialog.md`.
  - Callback status: applied and validated by commands `000000005720` and `000000005719`.
  - Exact facts incorporated: UID0004G7 calls `MailListDialog` constructor at `0x00471e51`, so `BulletinSession` is a constructor caller/coordinator; constructor direction is `MailListDialog(BulletinSession *, const Rect &, const unsigned char *mailListPayload)`; concrete dialog ownership remains `MailDialogs`; `MailListDialog +0x274` is consumed by BulletinSession as returned dialog/list id.
  - Metadata/link/score changes: none beyond validator-owned UID link/reference index and stats updates.

## Score And Metadata Recommendation

- Historical pre-callback score/metadata: `84/90`, owner [UID:00001D], reconstructable `TRUE`, blank emitter/C++.
- Current applied score/metadata: `88/92`, owner [UID:00001D], reconstructable `TRUE`, blank emitter/C++.
- Score rationale and reason not higher/lower:
  - Completion improves to `88` because the report resolves sparse-page blockers: exact MCP evidence, callee/caller inventory, boundary bytes, constants, dispatcher relationship, source-facing name, and no-code proof are now implementation-ready.
  - Completion should not exceed `88` because final C++ remains absent and the dispatcher/helper route duplication is unresolved even though helper/API role names are now documentation-ready.
  - Confidence improves to `92` because fresh MCP directly confirms the target body and support docs corroborate ownership/source placement.
  - Confidence should not exceed `92` because the function has no direct xrefs to its start, exact original field/member spellings are inferred, and source code shape remains unresolved.
- Score-improvement attempt:
  - Blocker: old target page had sparse evidence. Resolved by fresh MCP `supervisor_20260703_reopen` checks.
  - Blocker: owner/source placement could be confused with `MailDialogs`. Resolved by separating session method owner from concrete dialog callee owner.
  - Blocker: code-entry readiness. Researched through fresh decompile/support docs; helper names and API directions are resolved, but code remains intentionally blank because zero entry xrefs and dispatcher case-4 duplication make standalone emission unsafe.
  - Blocker: range/split. Resolved; no split needed.
- Metadata fields changed or left unchanged: changed only `COMPLETION` and `CONFIDENCE`; left owner/reconstructable/emitter/C++ unchanged.

## Open Questions With Attempted Resolution

- Open question: is UID0004G7 directly callable?
  - Evidence checked: MCP `xrefs_to 0x00471dd0`, local docs, dispatcher relationship.
  - Best supported resolution: no direct xrefs to the start in current IDA. Keep no-direct-start caveat; do not mark as dead because it is modeled, source-shaped, and part of the accepted exact split.
- Open question: what exact source field is `BulletinSession + 0x102`?
  - Evidence checked: UID0004G7 store, dispatcher case `4`, class docs, constructor report UID0004FS, MailListDialog/MailListPane docs.
  - Best supported resolution: use inferred `m_activeListId` / active list-dialog id in docs. Exact original member spelling is not recovered, but the role is sufficiently resolved for target/support documentation.
- Open question: what exact source field is `MailListDialog + 0x274`?
  - Evidence checked: UID0004G7 reads it; dispatcher case `4` reads it; allocation size `0x278`; [UID:00007L]/[UID:0003PU] support docs.
  - Best supported resolution: returned dialog/list id consumed by `BulletinSession +0x102`. Formal accessor spelling is not recovered, but docs should not leave the role generic.
- Open question: are rectangle, allocator, and push helper declarations blockers?
  - Evidence checked: fresh MCP `decompile 0x004b7c50`, `decompile 0x004f4aa0`, `decompile 0x004a0fc0`, [UID:00003U], [UID:0000IU], MemoryMan support notes, sibling BulletinSession reports.
  - Best supported resolution: no for documentation. Use `MakeRect`/`InitRectBounds`, MemoryMan-backed `new`, and `DialogSession::PushDialog(DialogInSession *)`.
- Open question: what is the MailListDialog constructor signature direction?
  - Evidence checked: fresh MCP `analyze_function 0x00479110`, constructor callers `0x0047173f` and `0x00471e51`, [UID:00007L]/[UID:0003PU].
  - Best supported resolution: `MailListDialog(BulletinSession *, const Rect &, const unsigned char *mailListPayload)` as source-facing direction, with exact packet-view type spelling deferred only for formal code.
- Open question: should this method emit C++ now?
  - Evidence checked: code-entry rule, owner/emitter route, fresh `xrefs_to 0x00471dd0`, fresh dispatcher case-4 decompile, target decompile, support declarations.
  - Best supported resolution: no. C++ remains blank because a standalone UID0004G7 method has no recovered entry route and duplicates the dispatcher case-4 live path. This is the exact no-improvement proof for formal C++; all reasonable current declaration/helper routes were checked and converted into documentation recommendations.
- Questions remaining unresolved after repair: exact original private method symbol and whether an original private-helper call route exists outside current xrefs. These cap score and block C++; they do not block target/support documentation improvement.

## Exact Manual Supervisor-Owned Coverage Or Tracker Text

- Not applicable. No manual `-coverage-report.md` or supervisor-owned tracker edit was requested or performed.
- Validator-owned generated refresh remained deferred in each scoped validator run; B012 did not edit generated reports manually.

## Follow-Up Actions

- Supervisor actions: Gate 2 verification and supervisor-owned execution if accepted.
- A-agent actions: none.
- B012 follow-up actions: none unless supervisor finds a Gate 2 defect.

## Confidence

- Recommendation confidence: strong.
- Score confidence: medium-high; `88/92` is appropriate for detailed no-code documentation, not final-source readiness.
- Remaining uncertainty: exact original names/types and the dispatcher/helper source-shape decision.

## Validator Results

- Validator run directory: `E:\NTK\GhidraBridge\source-3\project-documentation`.
- Command `python .\tools\validator.py --mode file --file by-memory/0x00471dd0-0x00471e96.BulletinSessionOpenMailListDialog.md --apply --queue-timeout 240`: command id `000000005717`, timestamp `2026-07-03T18:12:32-04:00`, exit `0`, ok `1`, completion/confidence updated to `88/92`, UID link/reference index additions applied, generated refresh deferred.
- Command `python .\tools\validator.py --mode file --file by-memory/0x00471550-0x00471872.BulletinSessionPacketDispatcher.md --apply --queue-timeout 240`: command id `000000005718`, timestamp `2026-07-03T18:12:34-04:00`, exit `0`, ok `1`, UID link/reference index additions applied, generated refresh deferred.
- Command `python .\tools\validator.py --mode file --file by-class/MailListDialog.md --apply --queue-timeout 240`: command id `000000005719`, timestamp `2026-07-03T18:12:36-04:00`, exit `0`, ok `1`, UID0004G7 link label/reference index updated, generated refresh deferred; warnings: pre-existing `missing_ref_uid` for `0003PU` twice and `0003PV`.
- Command `python .\tools\validator.py --mode file --file by-file/MailDialogs.md --apply --queue-timeout 240`: command id `000000005720`, timestamp `2026-07-03T18:12:38-04:00`, exit `0`, ok `1`, reference index/stats updates applied, generated refresh deferred; warnings: pre-existing `missing_ref_uid` entries for older MailDialogs UIDs including `0003PU`, `0003PV`, `0003PW`, `0003PX`, `0003PY`, `0003O8`, `0003PZ`, `0003MZ` with additional warnings suppressed.
- Command `python .\tools\validator.py --mode file --file by-class/BulletinSession.md --apply --queue-timeout 240`: command id `000000005721`, timestamp `2026-07-03T18:12:40-04:00`, exit `0`, ok `1`, stats updates applied, generated refresh deferred, no warnings.
- Command `python .\tools\validator.py --mode file --file by-file/BulletinSession.md --apply --queue-timeout 240`: command id `000000005722`, timestamp `2026-07-03T18:12:42-04:00`, exit `0`, ok `1`, stats updates applied, generated refresh deferred, no warnings.
- Validator summary: all changed by-* files passed scoped validation with exit `0` and ok `1`. Warnings are limited to pre-existing missing reference UID issues in MailDialogs/MailListDialog support docs.

## Changed Files

- Modified by B012 callback: `by-memory/0x00471dd0-0x00471e96.BulletinSessionOpenMailListDialog.md`.
- Modified by B012 callback: `by-memory/0x00471550-0x00471872.BulletinSessionPacketDispatcher.md`.
- Modified by B012 callback: `by-class/BulletinSession.md`.
- Modified by B012 callback: `by-file/BulletinSession.md`.
- Modified by B012 callback: `by-class/MailListDialog.md`.
- Modified by B012 callback: `by-file/MailDialogs.md`.
- Modified report: `tools/leaser/Agents/Agent-B012/research/0004G7-BulletinSessionOpenMailListDialog-source-quality.md`.
- Validator-applied side effect: project stats/reference-index style updates occurred through scoped validators only; no generated reports or coverage reports were manually edited.
- Renamed: none.
- Leases: target, dispatcher, MailListDialog class, and MailDialogs file were leased for editing; BulletinSession class/file were leased after a conflicting lease cleared. First batch leases expired before release; BulletinSession class/file leases were released explicitly. A final lease check showed no active B012 leases.
- Report execution: not run. No `execute_report`, lifecycle/archive command, dry-run/probe lifecycle command, validator state edit, manual generated edit, coverage edit, or manual report move was performed.

## Implementation Tracking Checklist

Initial report-only pass:
- [x] Supervisor validation required before implementation.
- [x] Target/support docs to update: target UID0004G7; support [UID:00001D], [UID:0000HX], [UID:0004G1], and if needed [UID:0000KZ]/[UID:00007L]/[UID:0003PU].
- [x] Current target state and actual evidence checked recorded.
- [x] Claim And Incorporation Ledger updated with destination and verification state for every accepted claim.
- [x] Metadata/score changes to apply: UID0004G7 `84/90 -> 88/92`; owner/reconstructable/emitter/C++ unchanged.
- [x] Score-limiting blockers researched to resolution or no-code proof: sparse evidence resolved; C++ remains blocked by exact declaration/source-shape proof.
- [x] Owner/emitter/reconstructable changes to apply: none except confirming existing owner `00001D`, reconstructable `TRUE`, blank emitter.
- [x] Split/rename/new-child changes to apply: none.
- [x] Source-placement, range/split/padding/reclassification, or IDA rename/type/comment changes to apply or confirm not applicable: document source-facing name and no IDA DB edits.
- [x] First-draft C++ or no-code proof to apply: apply target-specific no-code proof; do not insert C++.
- [x] Third-party import directive to apply or confirm not applicable: not applicable.
- [x] Exact target/support doc facts incorporated at report-level detail: MCP `supervisor_20260703_reopen` facts, behavior, xrefs/callees, constants, helper/API role names, field caveats, owner/source placement, no-code proof.
- [x] Historical/stale assumptions, rejected alternatives, and negative evidence to preserve: old MCP session evidence as historical, no-direct-start caveat, rejected MailDialogs/DialogSession/no-owner direct ownership, dispatcher/helper duplication caveat.
- [x] Wave2/Wave3 mentions or artifacts encountered and ignored/rejected as stale: generated names treated as leads only; no generated source used as authority.
- [x] Open questions to close or document as evidence-backed unresolved: exact original method symbol and whether a private-helper route exists outside current xrefs. Parameter, field, helper, and constructor directions are documentation-ready but not formal-code spellings.
- [x] Validators to run: scoped validators for each changed by-* doc during implementation callback only.
- [x] Generated report refresh expected or explicit manual supervisor-owned coverage/tracker text to apply: validator refresh was deferred; no manual tracker/coverage text.

Implementation callback pass:
- [x] Report accepted by supervisor for implementation.
- [x] All accepted target/support doc details incorporated at report-level detail.
- [x] Claim And Incorporation Ledger updated with destination and verification state for every accepted claim.
- [x] Metadata/score/owner/emitter/split/rename/C++ changes applied or explicitly not applied with reason.
- [x] Historical/stale assumptions, rejected alternatives, and negative evidence preserved.
- [x] Open questions resolved or documented with evidence-backed unresolved rationale.
- [x] Validators run and results recorded.
- [x] Generated report refresh completed by validator or explicit manual supervisor-owned coverage/tracker text supplied/confirmed unchanged: generated refresh was deferred by validators; no manual generated/coverage edit was performed.
- [x] Remaining unapplied accepted items listed with exact blocker: none.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B012","command_id":"000000005738","destination_path":"executed-b-agent-research/B012/0004G7-BulletinSessionOpenMailListDialog-source-quality.md","details":"report executed into central archive","event":"executed","source_path":"tools/leaser/Agents/Agent-B012/research/0004G7-BulletinSessionOpenMailListDialog-source-quality.md","timestamp":"2026-07-03T18:27:41-04:00","uid":"0004G7"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
