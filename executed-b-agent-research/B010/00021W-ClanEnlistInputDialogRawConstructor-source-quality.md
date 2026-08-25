** TARGET-REPORT-UID:00021W **
** AUTHOR-AGENT-ID:B010 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# 00021W ClanEnlistInputDialogRawConstructor Source-Quality Report

## Finalized Report / Current Recommendation

Post-callback current recommendation: [UID:00021W] `by-memory/0x00489f80-0x00489fb5.ClanEnlistInputDialogRawConstructor.md` is now documented as a reconstructable, class-owned retained raw constructor-shaped child for [UID:00002B] `ClanEnlistInputDialog`, with marker-only/no standalone constructor body.

Target metadata is now applied as `COMPLETION:88`, `CONFIDENCE:92`, `CANONICAL_OWNER:00002B`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:00002B`, and blank `EMITTER_POSITION_OPTIONAL`. This was a score/evidence refresh only; owner/emitter/reconstructable routing remained unchanged.

The body remains source-authored constructor evidence, not padding, not compiler adjustor glue, and not the source-visible submit behavior body. Current MCP proves no IDA function object, no raw-start/end xrefs, no exact VA/RVA byte pointer route, and no direct PE branch/call route to `0x00489f80`. Current MCP also proves the source-facing class identity through the `ClanAttrInputDialog` base constructor call, three `ClanEnlistInputDialog` vtable stores, and live inline construction in `ClanStatusPane::HandleClanEnlistPacket` action `1`.

Formal C++ now remains the accepted marker-only/no-standalone-body comment inside the target's formal `RECONSTRUCTION_CPP CODE` block. No callable constructor body or side/example C++ was added.

## Supporting Research

Assignment provenance: Agent-B010 goal dated 2026-07-05 09:20 assigns report-first research for [UID:00021W] from `auto-generated/-ag-research-tracker.md` -> `by-memory` -> `Not-Covered Files - Reconstructable`.

Queue row checked read-only: line `1570` of `auto-generated/-ag-research-tracker.md` lists [UID:00021W] `0x00489f80-0x00489fb5.ClanEnlistInputDialogRawConstructor`, score `85/90`, combined `87.5`, reconstructable `true`, reports `0`, target path `by-memory/0x00489f80-0x00489fb5.ClanEnlistInputDialogRawConstructor.md`.

Current MCP evidence is available and mandatory evidence was collected from active database session `supervisor_recovery_20260705`. `idb_list` returned one active adopted worker session for `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, not analyzing, PID/worker PID `19604`. `server_health` returned `status:"ok"`, module `NexusTK.exe`, input path `C:\Users\admin\Desktop\Clone\NexusTK\NexusTK.exe`, imagebase `0x400000`, `auto_analysis_ready:true`, `hexrays_ready:true`, `strings_cache_ready:true`, strings cache size `2067`.

MCP calls followed `by-structure.md` IDA MCP Output Discipline: schema-current `tools/list`, exact-address `lookup_funcs`, capped `xrefs_to`/`xref_query`, exact byte-pattern `find_bytes`, small-region `get_bytes`, scoped `insn_query`, one bounded decompile of the already-modeled live handler `0x00487ea0`, and no broad unbounded list/search/disassembly/callgraph/type/batch-analysis calls.

Prior/current docs used as support evidence only: target page, [UID:00002B] `ClanEnlistInputDialog`, [UID:0000I8] `Clan`, [UID:00021S] `ClanStatusPacketDialogHandlers`, [UID:00010L] `ClanAttrInputDialogCore`, [UID:0002O3] `ClanEnlistInputDialogSubmitEnlistment`, [UID:0001X9] `ClanDialogVtableFamily`, [UID:0002MN] `ClanModalDialogVtableData`, and [UID:0001TY] `ClanInputDialogLayouts`.

## Target

- Target UID: [UID:00021W].
- Target path: `by-memory/0x00489f80-0x00489fb5.ClanEnlistInputDialogRawConstructor.md`.
- Required report path: `tools/leaser/Agents/Agent-B010/research/00021W-ClanEnlistInputDialogRawConstructor-source-quality.md`.
- Queue source: `auto-generated/-ag-research-tracker.md` line `1570`.
- Current target metadata: `COMPLETION:88`, `CONFIDENCE:92`, `CANONICAL_OWNER:00002B`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:00002B`, blank `EMITTER_POSITION_OPTIONAL`.
- Current formal C++ state: accepted marker-only/no standalone constructor body inside the formal block and no callable constructor body.
- Direct semantic owner: [UID:00002B] `ClanEnlistInputDialog`.
- Source route: [UID:00002B] -> [UID:0000I8] `Clan` -> `NexusTK/social/Clan.cpp`.

## Current Target State

The target page now records the durable 2026-05/2026-06 facts and the 2026-07-05 B010 implementation refresh: exact raw constructor-shaped range `0x00489f80-0x00489fb5`, no IDA function object or decompile at the raw start, base call to [UID:00010L] `0x00489600`, stores of `ClanEnlistInputDialog` primary/secondary/tertiary vtables, return with `retn 4`, `0x00489fb5-0x00489fc0` alignment before the vtable-backed submitter [UID:0002O3], zero raw-start/end xrefs and pointer routes, no direct PE branch/call route, and live inline construction in `sub_487EA0` action `1`.

The implementation callback applied the target score update to `88/92`, refreshed the formal no-code marker with the exact current MCP/no-route proof, and historicalized legacy `AUTOGEN_PARENT_UID` wording under current `CANONICAL_OWNER` / `EMITTER_UIDS` terminology.

Support docs were updated only where weaker: `by-class/ClanEnlistInputDialog.md` gained current B010 MCP/no-route wording, and `by-file/Clan.md` refreshed the `ClanEnlistInputDialog` row and change note. Handler/base/submitter/vtable/layout support docs were verified as already carrying same-or-greater detail and were left untouched.

## Heuristic / Inference Reanalysis And Validation

| Issue | Decision | Evidence | Rejected alternatives / impact |
| --- | --- | --- | --- |
| Raw range classification | Retained source-authored constructor-shaped body with no live raw-entry route. | MCP `insn_query` shows prologue, saved `this`, base call, vtable stores, `retn 4`; `lookup_funcs` says raw start/end are not functions. | Reject padding/dead discard and reject normal callable constructor entry. |
| Direct owner | Keep [UID:00002B] `ClanEnlistInputDialog`. | Vtable stores use `??_7ClanEnlistInputDialog@@6B@`, `...@_0`, `...@_1`; class page owns submitter child. | Reject direct [UID:0000I8] file ownership; `Clan` remains file route only. |
| Source file | Keep `social/Clan.cpp` through [UID:0000I8]. | Clan file owns clan status, dialog, packet-handler, and modal-dialog routes. | Reject one-off migration to [UID:0000IA] `ClanDialogs`; that remains a coordinated split candidate only. |
| Constructor argument | Source-facing constructor argument remains `const unsigned char *packet` / packet pointer. | Raw body pushes `[ebp+8]` to base `sub_489600`; `ClanAttrInputDialogCore` uses packet data for DLGCLAN2 submitted fields. | Reject row index, dialog id, or free helper context parameter. |
| Active construction | Live handler `sub_487EA0` action `1` inlines construction, not a call to raw start. | MCP decompile/insn query: allocate `2160` / `0x870` bytes, call `sub_489600`, then store the same three vtables at `0x00487f34/3a/44`. | Do not use inline construction to claim an xref/call to `0x00489f80`. |
| Submit behavior | Source-visible submit behavior belongs to [UID:0002O3] `OnSubmitEnlistment`. | Submitter is function `sub_489FC0` size `0x29`, vtable data xref from `0x00615e54`, formal body already forwards `+0x26c/+0x46c/+0x66c/+0x86c` to `g_pClanStatusPane->SendClanAttributePacket`. | Do not duplicate submit behavior in raw constructor page. |
| C++ disposition | Marker-only formal comment; no callable constructor body. | No function, no decompile, zero xrefs, zero pointer routes, zero branch route; live inline opener exists elsewhere. | Reject body-only/sample/illustrative constructor C++ and reject blank/ambiguous wording that hides the marker-only status. |
| Score movement | Raise target to `88/92`. | Current MCP closes stale evidence and matches sibling raw-constructor scoring after current refresh; residual caps remain real. | Do not promote to 95+ or final body because raw-entry liveness and final original declaration policy remain unresolved. |

## Evidence Standards Used

Evidence types used:

- Current IDA MCP session/health checks.
- Exact function/no-function lookup.
- Capped xrefs and vtable data refs.
- Exact bytes and instruction reads for the raw target range and padding.
- Bounded decompile/disassembly of the live opener `0x00487ea0`.
- Exact byte-pattern pointer searches for raw-start/end and positive-control submitter pointer.
- Read-only local PE section-mapped scan for direct branch/call routes to the raw start.
- Current by-* target/support docs for class, file, vtable, layout, handler, and submitter context.
- `tools/int_convert.py` for size/offset conversions.

The evidence is strong enough for `88/92`: constructor identity and class/source route are directly proven, and no-route status is independently supported by IDA xrefs, IDA byte search, and a local PE branch scan. It is not strong enough for a callable constructor body or near-final 95+ confidence because no live raw-entry route or original source declaration policy was recovered.

## Evidence Checked

Current MCP checks:

- `idb_list`: one active worker session `supervisor_recovery_20260705`, `NexusTK.exe.i64`, `is_analyzing:false`, `owned:true`, `adopted:true`.
- `server_health`: `status:ok`, imagebase `0x400000`, auto-analysis ready, Hex-Rays ready, strings cache ready.
- `lookup_funcs`: `0x00489f80` and `0x00489fb5` are not functions; `0x00489fc0` is `sub_489FC0`, size `0x29`; `0x00489600` is `sub_489600`, size `0x7e1`; `0x00487ea0` is `sub_487EA0`, size `0x2c7`; `0x00487f2f` is inside `sub_487EA0`.
- `decompile 0x00489f80`: `code:null`, error `Decompilation failed at 0x489f80`.
- `xrefs_to`: zero xrefs to `0x00489f80`; zero xrefs to `0x00489fb5`; one data xref to `0x00489fc0` from `0x00615e54`.
- `xref_query` for vtable bases: `0x00615df8` refs at `0x00487f34` and `0x00489f92`; `0x00615e5c` refs at `0x00487f3a` and `0x00489f9a`; `0x00615e8c` refs at `0x00487f44` and `0x00489fa4`.
- `find_bytes`: no matches for raw-start VA bytes `80 9f 48 00`; no matches for raw-start RVA bytes `80 9f 08 00`; no matches for raw-end VA bytes `b5 9f 48 00`; positive control submitter VA bytes `c0 9f 48 00` match `0x00615e54`.
- `get_bytes`: `0x00489f80` region is the exact 53-byte constructor-shaped body followed by eleven `0xcc` bytes; `0x00489fb5-0x00489fc0` is all `0xcc`; `0x00489fc0` starts with the submitter field-load bytes.
- `insn_query 0x00489f80-0x00489fb5`: 16 instructions, all `fn:null`; includes `call sub_489600` at `0x00489f8d`, vtable stores at `0x00489f92`, `0x00489f9a`, `0x00489fa4`, and `retn 4` at `0x00489fb2`.
- `insn_query 0x00489fb5-0x00489fc0`: one `align 10h`, `fn:null`.
- `insn_query 0x00487f20-0x00487f50`: live handler path at `0x00487f2f` calls `sub_489600` and stores the same three vtables at `0x00487f34`, `0x00487f3a`, and `0x00487f44`.
- `decompile 0x00487ea0`: action `1` allocates `2160` / `0x870` bytes, calls `sub_489600(v3, a2)`, and installs the `ClanEnlistInputDialog` vtable family. Action `0` fills the enlist list, and action `2` succeeds without opening a dialog.

Local read-only checks:

- `tools/int_convert.py`: verified `0x35 = 53`, `0xb = 11`, `0x2c7 = 711`, `0x7e1 = 2017`, `0x29 = 41`, `0x26c = 620`, `0x46c = 1132`, `0x66c = 1644`, `0x86c = 2156`, `2160 = 0x870`, and `4759488 = 0x489fc0`.
- PE scan of `C:\Users\admin\Desktop\Clone\NexusTK\NexusTK.exe`, imagebase `0x400000`: zero raw-start VA hits, zero raw-start RVA hits, zero raw-end VA hits, one positive-control submitter VA hit at file offset `0x214854`, and zero direct `E8`/`E9`/near-jcc/short-branch targets to `0x00489f80`.

Skipped/forbidden checks:

- Report-only phase: no validators were run because no by-* docs were edited before Gate 1.
- Implementation callback phase: scoped file validators were run for the three edited by-* files; see `Validator Results`.
- No `execute_report`, dry-run/probing execute variants, lifecycle/archive commands, registry commands, generated edits, coverage-report edits, validator-state edits, queue/lock edits, IDB mutating calls, or manual report moves were run.

## Claim And Incorporation Ledger

| Claim ID | Claim text | Confidence | Evidence | Exact destination doc/section | Action | Verification state |
| --- | --- | --- | --- | --- | --- | --- |
| W21-001 | Current MCP session `supervisor_recovery_20260705` is healthy and was used for UID00021W evidence. | High | `idb_list`, `server_health`. | Target `IDA MCP Evidence`; class `Evidence Notes`; Clan file row/change note. | Incorporated current refresh into target/class/file docs. | applied |
| W21-002 | `0x00489f80` and `0x00489fb5` are not IDA functions; successor `0x00489fc0` is `sub_489FC0` size `0x29`. | High | MCP `lookup_funcs`. | Target `IDA MCP Evidence`, `Covered Range`, `Score Rationale`; class evidence note; Clan row. | Incorporated current lookup facts. | applied |
| W21-003 | Raw body is 53 bytes (`0x35`) ending at `0x00489fb5`; `0x00489fb5-0x00489fc0` is eleven-byte `0xcc` alignment. | High | MCP `get_bytes`, `insn_query`; `int_convert.py`. | Target `Covered Range`, `IDA MCP Evidence`, `Changes`; class evidence note; Clan row. | Incorporated exact current bytes/size/padding. | applied |
| W21-004 | Raw body calls `ClanAttrInputDialog` base constructor `sub_489600` at `0x00489f8d` and returns with `retn 4`. | High | MCP `insn_query`, `lookup_funcs 0x00489600`; `ClanAttrInputDialogCore` support doc. | Target `IDA MCP Evidence`; class method/evidence notes. | Incorporated in target/class; base-core support already had same-or-greater detail and was left untouched. | applied / already-present in `by-memory/0x00489600-0x00489f80.ClanAttrInputDialogCore.md` |
| W21-005 | Raw body stores `ClanEnlistInputDialog` vtables at offsets `+0`, `+0xa0`, and `+0xa4` using vtable bases `0x00615df8`, `0x00615e5c`, and `0x00615e8c`. | High | MCP `insn_query`; `xref_query`; vtable docs. | Target `IDA MCP Evidence`; class evidence note; `by-type/by-vtable/ClanDialogVtableFamily.md`; `by-memory/0x006158f4-0x00615fd8.ClanModalDialogVtableData.md`. | Incorporated in target/class; vtable support docs already listed bases/store refs and were left untouched. | applied / already-present in vtable docs |
| W21-006 | There are zero IDA xrefs to raw start/end and zero exact VA/RVA byte-pointer hits to the raw start. | High | MCP `xrefs_to`, `find_bytes`. | Target `IDA MCP Evidence`; class evidence caveat; Clan row. | Incorporated current no-route proof. | applied |
| W21-007 | Local PE `.text` scan found zero direct branch/call routes to `0x00489f80`. | High | Read-only PE scan. | Target `IDA MCP Evidence`; class evidence note; Clan row; this report. | Incorporated as support evidence with MCP remaining primary. | applied |
| W21-008 | Live handler `sub_487EA0` action `1` inlines construction with allocation `0x870`, base call `sub_489600`, and vtable stores at `0x00487f34/3a/44`; this proves class identity but not raw-start liveness. | High | MCP `decompile 0x00487ea0`, `insn_query`, `xref_query`; [UID:00021S] support doc. | Target `IDA MCP Evidence` and `Parent Attachment`; class evidence note; Clan row. | Incorporated distinction in edited docs; [UID:00021S] already had action `1`/allocation/base-call/vtable facts and was left untouched. | applied / already-present in [UID:00021S] |
| W21-009 | Source-visible submit behavior belongs to [UID:0002O3] `ClanEnlistInputDialog::OnSubmitEnlistment`, not UID00021W. | High | Submitter doc, MCP `xrefs_to 0x00489fc0`, `get_int 0x00615e54 -> 0x00489fc0`. | Target no-code proof; class/file rows; submitter support doc. | Preserved in target/class/file; submitter page already carried emitted body and current helper sync. | already-present / applied wording refresh |
| W21-010 | Direct owner/emitter should remain [UID:00002B] `ClanEnlistInputDialog`; source route remains [UID:0000I8] `Clan` / `NexusTK/social/Clan.cpp`. | High | Target/class/file docs; vtable identity. | Target metadata; class/file support. | Preserved unchanged. | already-present |
| W21-011 | Target formal C++ should be marker-only/no standalone constructor body, with exact updated marker text supplied in this report. | High | Combined no-function/decompile-failed/no-route proof and active inline construction route. | Target formal `RECONSTRUCTION_CPP CODE`; class/file wording. | Replaced target marker with exact accepted marker; class/file wording synchronized. | applied |
| W21-012 | Raise target score from pre-callback `85/90` to `88/92`. | Medium-high | Current MCP refresh closes stale evidence; residual caps remain. | Target metadata and `Score Rationale`; report current-state sections. | Applied metadata and rationale; validator command `000000006931` recorded completion/confidence updates. | applied |
| W21-013 | Historical `AUTOGEN_PARENT_UID` wording in target changes should be historicalized under current `CANONICAL_OWNER`/`EMITTER_UIDS` terminology. | High | Target change log uses old terminology; by-structure current metadata rules. | Target `Changes`. | Historicalized old `AUTOGEN_PARENT_UID` entries without changing facts. | applied |
| W21-014 | Reject padding, dead discard, compiler glue, PacketBuffer/Socket/helper-strip ownership, one-off `ClanDialogs.cpp`, and callable raw constructor body alternatives. | High | Body shape, class vtables, source/file docs, no-route proof. | Target `Ownership Decision`, formal no-code proof, `Changes`; Clan file row/change note. | Preserved and refreshed in target/file docs; no callable body or side/example C++ added. | applied |
| W21-015 | Manual generated/coverage/tracker/validator-state edits are not applicable. | High | Assignment boundaries and command history. | This report `Validator Results`, `Changed Files`, `Implementation Tracking Checklist`. | Excluded manual edits; only required scoped validators ran and produced recorded validator side effects. | excluded-with-reason: forbidden/manual generated, coverage, lifecycle, registry, and validator-state edits |

## Positive Evidence Summary

- Exact constructor-shaped body: prologue, saved `this`, `[ebp+8]` packet argument forwarded to `sub_489600`, `mov eax, esi`, three derived vtable stores, and `retn 4`.
- Direct class identity: raw body and live inline opener both store `ClanEnlistInputDialog` vtable bases `0x00615df8`, `0x00615e5c`, and `0x00615e8c`.
- Live source context: `sub_487EA0` action `1` allocates `0x870` bytes and inlines base construction plus derived vtable stores for `ClanEnlistInputDialog`.
- Adjacent behavior split: successor [UID:0002O3] is a real vtable-backed function and already emits `OnSubmitEnlistment()`.
- Source route: [UID:00002B] class page and [UID:0000I8] file page already route the dialog through `NexusTK/social/Clan.cpp`.

## Negative Evidence Summary

- No IDA function object at `0x00489f80` or `0x00489fb5`.
- No IDA xrefs to `0x00489f80` or `0x00489fb5`.
- No exact VA byte-pattern hit for raw start `80 9f 48 00`.
- No exact RVA byte-pattern hit for raw start `80 9f 08 00`.
- No exact VA byte-pattern hit for raw end `b5 9f 48 00`.
- No direct PE branch/call target to `0x00489f80`.
- No evidence that PacketBuffer, Socket, `g_packetSender`, or a clan helper strip owns this constructor-shaped range.
- No evidence that this one target should migrate alone to `ClanDialogs.cpp`.

## Ranked Ownership Analysis

### 1. [UID:00002B] ClanEnlistInputDialog

Evidence for: raw body stores only `ClanEnlistInputDialog` vtables; active handler action `1` constructs `ClanEnlistInputDialog` with the same base-call/vtable-store sequence; class page owns the submitter child; source-visible behavior is the class declaration plus [UID:0002O3] submit override.

Evidence against: raw start has no function/xref route, so it cannot be treated as a normal live callable constructor body.

Decision: keep [UID:00002B] as direct owner/emitter.

### 2. [UID:0000I8] Clan / social Clan.cpp

Evidence for: file page owns the clan status/dialog/packet cluster and current generated source route.

Evidence against: file is a source route, not the narrow semantic owner of this exact class constructor evidence.

Decision: keep as emitter route through the class; do not make it direct owner.

### 3. [UID:0000IA] ClanDialogs Split Candidate

Evidence for: a future coordinated source split for modal clan dialogs remains plausible.

Evidence against: current docs keep `ClanDialogs` as a candidate only; a one-off migration for UID00021W would split one raw constructor away from its class, submitter, and handler context.

Decision: reject for this callback; mention only as a coordinated future split candidate.

### 4. PacketBuffer, Socket, `g_packetSender`, Clan Helper Strip, Or Compiler Glue

Evidence for: nearby clan packet handlers and submitters use packet helpers.

Evidence against: UID00021W does not send packets, read packet-buffer helpers directly, or perform ABI adjustor logic. Its body is constructor-shaped class setup.

Decision: reject.

## Source Placement

Recommended source placement remains [UID:00002B] `ClanEnlistInputDialog`, emitted through [UID:0000I8] `Clan` / `NexusTK/social/Clan.cpp`.

This placement fits the surrounding source map because `ClanStatusPane::HandleClanEnlistPacket` action `1` opens this modal dialog, `ClanAttrInputDialogCore` supplies the base DLGCLAN2 submitted-field layout, and [UID:0002O3] carries the class-owned submit behavior.

No new file, class, or child split is recommended. The exact range split is already correct: raw constructor `0x00489f80-0x00489fb5`, alignment `0x00489fb5-0x00489fc0`, and successor submitter `0x00489fc0-0x00489fe9`.

## Range / Split / Padding / Reclassification Analysis

- Exact target range: `0x00489f80-0x00489fb5`.
- Size: `0x35` / 53 bytes (verified with `int_convert.py`).
- Padding successor: `0x00489fb5-0x00489fc0`, eleven `0xcc` bytes (verified with `int_convert.py`).
- Next modeled function: `0x00489fc0` / `sub_489FC0`, size `0x29` / 41 bytes (verified with `int_convert.py`).
- No merge into [UID:00010L]: `sub_489F50` ends exactly at `0x00489f80`; UID00021W begins a fresh prologue.
- No merge into [UID:0002O3]: padding separates the raw constructor and submitter, and `0x00489fc0` is a modeled function/vtable slot.
- No new child page needed: current split already isolates the constructor, padding, and submitter.
- No reclassification to non-reconstructable compiler glue: the body is source-authored constructor evidence, but not a standalone callable body.

## First-Draft C++ Recommendation

Eligible for callable draft C++ body: no.

The only C++ text recommended for UID00021W is the exact formal marker block below. It is a marker-only/no-standalone-body comment inside the formal target block, not a constructor implementation and not a side/example snippet.

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
// Retained no-route ClanEnlistInputDialog constructor-shaped range: MCP session supervisor_recovery_20260705 finds no function object, decompile, xref, exact VA/RVA pointer route, or direct branch/call route to 0x00489f80; the class declaration/base layout and OnSubmitEnlistment child carry the source-visible behavior.
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

Why no callable body:

- Current MCP has no function object at `0x00489f80`.
- Current MCP has zero xrefs to `0x00489f80`.
- Current MCP exact VA/RVA pointer-byte searches are negative.
- Local PE direct branch/call scan is negative.
- The live source construction path in `sub_487EA0` action `1` inlines the base constructor call and vtable stores; it does not call this raw start.
- The source-visible submit behavior is already carried by [UID:0002O3].

## Final Recommendation

Implementation callback has been applied as a documentation-only target/support refresh:

- Target metadata is now `COMPLETION:88`, `CONFIDENCE:92`; `CANONICAL_OWNER:00002B`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:00002B`, and blank `EMITTER_POSITION_OPTIONAL` were preserved.
- Target formal C++ is the exact marker-only/no-standalone-body block above; no callable constructor body or side/example C++ was added.
- Current 2026-07-05 B010 MCP evidence from `supervisor_recovery_20260705` was added to the target and synchronized into the class/file support wording.
- Source-authored constructor evidence and the no-route caveat were preserved.
- [UID:0002O3] remains the emitted source-visible submit body.
- Stale `AUTOGEN_PARENT_UID` wording was historicalized under current owner/emitter terminology.

B010 did not run `execute_report`; supervisor owns Gate 2 verification and lifecycle execution.

## Recommended Target Doc Changes

Target path: `by-memory/0x00489f80-0x00489fb5.ClanEnlistInputDialogRawConstructor.md`.

Applied target metadata:

```text
COMPLETION:88
CONFIDENCE:92
CANONICAL_OWNER:00002B
RECONSTRUCTABLE:TRUE
EMITTER_UIDS:00002B
EMITTER_POSITION_OPTIONAL:
```

Applied target formal C++: exact marker block supplied in `First-Draft C++ Recommendation`.

Exact facts incorporated:

- 2026-07-05 B010 MCP session `supervisor_recovery_20260705` health OK.
- `lookup_funcs`: no function at `0x00489f80` or `0x00489fb5`; `0x00489fc0` is `sub_489FC0` size `0x29`; `0x00489600` is `sub_489600` size `0x7e1`; `0x00487ea0` is `sub_487EA0` size `0x2c7`.
- Exact body instructions: base call at `0x00489f8d`; vtable stores at `0x00489f92`, `0x00489f9a`, `0x00489fa4`; `retn 4` at `0x00489fb2`.
- Exact bytes/range: 53-byte body and eleven `0xcc` padding bytes before submitter.
- Negative route proof: zero xrefs to start/end; zero exact VA/RVA pointer-byte hits to start; zero PE direct branch/call route to start.
- Positive-control/support route: submitter start has data pointer at `0x00615e54`; handler `sub_487EA0` action `1` inlines construction with allocation `0x870`.
- Historicalize old `AUTOGEN_PARENT_UID` wording in Changes without removing historical score/progression facts.

## Recommended Support Doc Changes

Support path: `by-class/ClanEnlistInputDialog.md`.

- Applied: added/refreshed the 2026-07-05 B010 note that UID00021W remains marker-only/no standalone constructor body with current MCP no-function/no-route proof.
- Preserved: declaration `explicit ClanEnlistInputDialog(const unsigned char *packet);` and `OnSubmitEnlistment()` child relationship.
- No class score/owner/emitter change was made.

Support path: `by-file/Clan.md`.

- Applied: refreshed the `ClanEnlistInputDialog` row to mention UID00021W current MCP no-route marker-only constructor evidence, [UID:0002O3] as the source-visible `OnSubmitEnlistment()` body, and `sub_487EA0` action `1` as the live inline opener context.
- Preserved: `NexusTK/social/Clan.cpp` route; no one-off migration to `ClanDialogs.cpp`.
- No file metadata/source-path change was made.

Support path: `by-memory/0x004877d0-0x00488594.ClanStatusPacketDialogHandlers.md`.

- Already-present / not edited: it already records subtype `6` action `1` opening `ClanEnlistInputDialog`, allocation `0x870`, call to `0x00489600` / `sub_489600`, and vtable-family stores. The whole handler island remains ClanStatusPane/Clan helper context, not `ClanEnlistInputDialog`.

Support path: `by-type/by-vtable/ClanDialogVtableFamily.md` and `by-memory/0x006158f4-0x00615fd8.ClanModalDialogVtableData.md`.

- Already-present / not edited: existing rows already list `ClanEnlistInputDialog` vtable bases and store refs, including the raw constructor and live inline store contexts. No score/reconstructability change was needed.

Support path: `by-type/by-struct/ClanInputDialogLayouts.md`.

- Already-present / not edited: it already carries the inherited DLGCLAN2 field offsets used by [UID:0002O3].

Support path: `by-memory/0x00489fc0-0x00489fe9.ClanEnlistInputDialogSubmitEnlistment.md`.

- Already-present / not edited: it already carries the emitted submitter body and B009 helper sync, and the edited target/class/file docs preserve UID00021W as marker-only/no standalone constructor body.

Generated files, coverage reports, validator state, tracker files, lifecycle/archive files, and supervisor ledgers must not be edited manually.

## Score And Metadata Recommendation

Current target score/metadata after implementation:

- `COMPLETION:88`
- `CONFIDENCE:92`
- `CANONICAL_OWNER:00002B`
- `RECONSTRUCTABLE:TRUE`
- `EMITTER_UIDS:00002B`
- `EMITTER_POSITION_OPTIONAL:` blank

Pre-callback target score was `85/90`; that historical value is superseded by the applied target metadata above. Owner/emitter/reconstructable fields are unchanged.

Rationale for `88`: current evidence now covers exact range, current MCP function/no-function status, exact instructions/bytes, padding, live inline construction context, vtable xrefs, submitter positive control, pointer negatives, branch negatives, source placement, rejected alternatives, and exact marker-only formal C++ text.

Rationale for `92`: class identity and no-route evidence are strongly corroborated by current IDA MCP and local PE scan. Confidence remains below final because no live raw-entry route, original constructor declaration policy, final modal-dialog source split, and original source symbol spellings are recovered.

Do not raise above `92` until either raw-entry liveness is proven or project-level policy explicitly accepts retained raw constructors as ordinary callable constructor bodies. Do not lower score: current source-shaped bytes, class/vtable identity, owner route, and current no-route proof are stronger than the stale `85/90` state.

## Open Questions With Attempted Resolution

| Question | Attempted resolution | Current disposition |
| --- | --- | --- |
| Is `0x00489f80` a function now? | Current MCP `lookup_funcs` on start/end. | No; both start and end are not functions. |
| Is there any static raw-entry route? | MCP xrefs, MCP VA/RVA `find_bytes`, and local PE branch scan. | No current route found. |
| Is the body padding or compiler glue? | MCP `insn_query` and bytes show full constructor-shaped body with vtable stores. | No; retain as source-authored constructor evidence. |
| Should the target emit a constructor body? | Compared no-route evidence against live inline construction and submitter child. | No; marker-only formal block is the correct current source-quality disposition. |
| Does `ClanDialogs.cpp` own this target? | Checked Clan file and modal-dialog support docs. | No one-off migration; `ClanDialogs` remains only a coordinated split candidate. |
| Are field names and constructor argument solved enough? | `ClanAttrInputDialogCore` and `ClanInputDialogLayouts` support `const unsigned char *packet` and inherited submitted fields. | Good enough for marker/class declaration context; exact original names remain score caps. |

## Validator Results

Scoped validators were run from `source-3/project-documentation` for each edited by-* file after the implementation callback.

| Command ID | Timestamp | Command | Exit | Result | Notes / side effects |
| --- | --- | --- | ---: | --- | --- |
| `000000006931` | `2026-07-05T09:37:54-04:00` | `python .\tools\validator.py --mode file --file by-memory\0x00489f80-0x00489fb5.ClanEnlistInputDialogRawConstructor.md --apply --queue-timeout 240` | `0` | `ok: 1` | Applied `completion_update 88`, `confidence_update 92`, `autogen_registry_update`, `reference_index_add`, projected stats update; generated refresh deferred. |
| `000000006932` | `2026-07-05T09:38:00-04:00` | `python .\tools\validator.py --mode file --file by-class\ClanEnlistInputDialog.md --apply --queue-timeout 240` | `0` | `ok: 1` | Applied stats row/projected stats updates; generated refresh deferred. |
| `000000006933` | `2026-07-05T09:38:12-04:00` | `python .\tools\validator.py --mode file --file by-file\Clan.md --apply --queue-timeout 240` | `0` | `ok: 1` | Reported `missing_ref_uid: 20` for pre-existing Clan.md UID references (`0003HE`, `000411`, `000412`, `000413`, `0003B8`, `0003B9`, suppressed remainder); applied stats row/projected stats updates; generated refresh deferred. |

Forbidden commands/files not used manually: `execute_report`, dry-run/probing execute variants, lifecycle/archive commands, registry commands, generated edits, coverage-report edits, validator-state edits, queue/lock edits, and manual report moves.

Generated freshness: all scoped validators reported `generated_refresh: deferred`; no generated files were manually edited by B010.

## Changed Files

Changed by B010 manual edits during this implementation callback:

- `tools/leaser/Agents/Agent-B010/research/00021W-ClanEnlistInputDialogRawConstructor-source-quality.md`
- `by-memory/0x00489f80-0x00489fb5.ClanEnlistInputDialogRawConstructor.md`
- `by-class/ClanEnlistInputDialog.md`
- `by-file/Clan.md`

Validator-applied side effects recorded from scoped validators:

- Target UID00021W completion/confidence registry updates from command `000000006931`.
- Reference index/stats/projection updates from commands `000000006931` through `000000006933`.
- Generated refresh deferred for all three validators.

Verified but not changed because same-or-greater detail was already present:

- `by-memory/0x004877d0-0x00488594.ClanStatusPacketDialogHandlers.md`
- `by-memory/0x00489600-0x00489f80.ClanAttrInputDialogCore.md`
- `by-memory/0x00489fc0-0x00489fe9.ClanEnlistInputDialogSubmitEnlistment.md`
- `by-type/by-vtable/ClanDialogVtableFamily.md`
- `by-memory/0x006158f4-0x00615fd8.ClanModalDialogVtableData.md`
- `by-type/by-struct/ClanInputDialogLayouts.md`

Not manually changed:

- Generated files.
- Coverage reports.
- Validator state.
- Queue/lock files.
- Lifecycle/archive files.
- Supervisor ledgers.

Leases used/released:

- Leased `by-memory/0x00489f80-0x00489fb5.ClanEnlistInputDialogRawConstructor.md`, `by-class/ClanEnlistInputDialog.md`, and `by-file/Clan.md` with `python leaser.py Agent-B010 lease ...`: all `Success`.
- Released the same three files with `python leaser.py Agent-B010 unlease ...`: all `Success`.
- Current lease report after release: `tools/leaser/Agents/current_leases.md` says `No active leases.`

## Implementation Tracking Checklist

Report-only research pass:

- [x] Loaded Agent-B010 goal and project-level B-agent workflow.
- [x] Preserved required provenance `CHATGPT | 5.5 | xHigh`.
- [x] Checked queue row read-only: [UID:00021W], `85/90`, reconstructable true, reports `0`.
- [x] Read target and support docs needed for source-quality analysis.
- [x] Used current MCP evidence from `supervisor_recovery_20260705`.
- [x] Researched function/no-function status, xrefs, bytes, padding, vtable refs, active inline construction, source route, C++ disposition, score blockers, and rejected alternatives.
- [x] Did not edit target/support by-* docs.
- [x] Did not run validators, `execute_report`, lifecycle/archive/registry commands, generated edits, coverage edits, validator-state edits, queue/lock edits, or manual report moves.

Supervisor callback implementation:

- [x] Leased only files being edited immediately before callback edits: target, `ClanEnlistInputDialog.md`, and `Clan.md`; all lease requests returned `Success`.
- [x] Target: updated metadata to `COMPLETION:88`, `CONFIDENCE:92`; preserved `CANONICAL_OWNER:00002B`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:00002B`, and blank `EMITTER_POSITION_OPTIONAL`.
- [x] Target: replaced formal C++ with the exact marker-only/no-standalone-body block from this report; no callable body or side/example C++ was added.
- [x] Target: added current MCP refresh facts from `supervisor_recovery_20260705`, including health OK, no function/decompile/xrefs, successor submitter size `0x29`, exact body/padding, pointer negatives, vtable refs, live inline construction, and PE branch/call negative.
- [x] Target: preserved no-route proof, source-authored constructor evidence, exact bytes/instructions, padding, active inline construction context, and rejected alternatives.
- [x] Target: historicalized stale `AUTOGEN_PARENT_UID` wording under current `CANONICAL_OWNER`/`EMITTER_UIDS` terminology.
- [x] Support `ClanEnlistInputDialog.md`: synced marker-only/no standalone constructor wording and current MCP no-route proof; preserved class declaration, `OnSubmitEnlistment`, scores, owner, and emitter.
- [x] Support `Clan.md`: synced row-level current MCP route/no-route facts, live inline construction context, source-visible [UID:0002O3] submit body, and no one-off `ClanDialogs.cpp` migration.
- [x] Support `ClanStatusPacketDialogHandlers.md`: already-present; subtype `6` action `1`, allocation `0x870`, base call, and vtable stores were already recorded, so no edit.
- [x] Support `ClanAttrInputDialogCore.md`: already-present; base constructor, field offsets, raw derived-constructor calls, and DLGCLAN2 layout facts were already recorded, so no edit.
- [x] Support `ClanEnlistInputDialogSubmitEnlistment.md`: already-present; emitted `OnSubmitEnlistment()` body, vtable-only slot, field offsets, and current helper sync were already recorded, so no edit.
- [x] Support vtable/layout docs: already-present; `ClanEnlistInputDialog` vtable bases/store refs and DLGCLAN2 offsets were already recorded, so no edit.
- [x] Ran scoped validators from `source-3/project-documentation` for every changed by-* file: commands `000000006931`, `000000006932`, and `000000006933`, all exit `0`, all `ok: 1`.
- [x] Released all leases immediately after edits/validation; all release requests returned `Success`.
- [x] Updated this report ledger/checklist with `applied`, `already-present`, or `excluded-with-reason` states and validator command metadata.
- [x] Did not run `execute_report`, dry-run/probing execute variants, lifecycle/archive commands, registry commands, generated edits, coverage edits, validator-state edits, queue/lock edits, or manual report moves.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B010","command_id":"000000006938","destination_path":"executed-b-agent-research/B010/00021W-ClanEnlistInputDialogRawConstructor-source-quality.md","details":"report executed into central archive","event":"executed","source_path":"tools/leaser/Agents/Agent-B010/research/00021W-ClanEnlistInputDialogRawConstructor-source-quality.md","timestamp":"2026-07-05T09:45:20-04:00","uid":"00021W"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
