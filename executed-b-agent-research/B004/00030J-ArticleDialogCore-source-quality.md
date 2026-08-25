** TARGET-REPORT-UID:00030J **
** AUTHOR-AGENT-ID:B004 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | Medium **

# 00030J ArticleDialogCore Source-Quality Report

## Finalized Report / Current Recommendation

- Current recommendation: keep [UID:00030J][0x004753e0-0x00476c0a.ArticleDialogCore](../../../by-memory/0x004753e0-0x00476c0a.ArticleDialogCore.md) owned by [UID:00000J][ArticleDialog](../../../by-class/ArticleDialog.md) and emitted through [UID:00000J] / [UID:0000HT][BoardDialogs](../../../by-file/BoardDialogs.md); update the target documentation with the current MCP-backed action IDs, packet layouts, raw helper roles, duplicate helper route, and exact no-aggregate-C++ proof.
- Final disposition: source-quality improvement, not ownership repair. The current owner/emitter route is correct. The stale blocker is that the page still says action IDs, packet fields, and raw helper reachability are unresolved even though current bounded MCP evidence resolves their practical roles.
- Required action: supervisor validation before callback. If accepted, update target/support docs only; do not execute this report until supervisor verification after implementation.
- Confidence: high for owner/emitter, action dispatch, packet subcommands, raw helper roles, delete/reply alert route, and no-partial-aggregate C++ disposition; medium-high for exact original method/member spellings because the current IDB still lacks function objects and direct callers for several retained helpers.

## Supporting Research

## Target

- Target UID: `00030J`
- Target path: `by-memory/0x004753e0-0x00476c0a.ArticleDialogCore.md`
- Source queue/report row: `auto-generated/-ag-research-tracker.md` -> Not-Covered Files - Reconstructable, row `85/88`, average `86.5`, reconstructable `true`, reports `0`.
- Current supervisor classification: report-only source-quality pass for ArticleDialog constructor/action/server-response cluster, raw helper islands, packet/action fields, delete/reply alert route, owner/emitter path, score readiness, and first-draft C++ or no-code disposition.
- Current scores and parent state: target `85/88`, `CANONICAL_OWNER:00000J`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:00000J`; class parent [UID:00000J] is `85/87`; file parent [UID:0000HT] is now `87/88`.

## Current Target State

- Existing metadata: `COMPLETION:85`, `CONFIDENCE:88`, owner/emitter through `ArticleDialog`, formal C++ block contains a marker-only comment.
- Existing owner/emitter/reconstructable state: correct. Current MCP reconfirms `ArticleDialog` vtable stores at `0x0047544a`, `0x00475450`, and `0x0047545a`, and the constructor caller at `0x00471b7a` from `BulletinSession`.
- Existing C++/emitter state: generated `auto-generated/NexusTK/ui/dialogs/BoardDialogs.cpp` contains UID00030J as a non-empty marker at lines 9-10, not an empty-emitter marker. This marker came from executed B009 `0000HT-BoardDialogs-empty-emitter-family-source-quality.md`.
- Existing blockers: target text still caps completion because raw helper reachability, action IDs, packet fields, and final C++ readiness are not documented at source-quality detail.
- Related docs checked: target page, [UID:00000J] `ArticleDialog`, [UID:0000HT] `BoardDialogs`, [UID:0000ZK] `BoardArticleDialogs`, [UID:00030H] `ArticleNavigationHelpers`, [UID:00030K] `NewArticleDialogCore`, [UID:00003O] `DeleteReplyAlert`, [UID:0001X4] `BoardArticleDialogVtableFamily`, [UID:00001D] `BulletinSession`, generated tracker/coverage rows, executed B001/B009/B005 reports.

## Executive Recommendation

Keep UID00030J as one `ArticleDialogCore` aggregate for now, but upgrade the page body from "unresolved action/packet/raw helper blockers" to an evidence-backed no-partial-aggregate disposition. Current MCP resolves the command IDs and packet fields well enough to raise the target to `88/90`, but not enough to insert a full formal aggregate body.

Recommended source-facing names:

- `ArticleDialog::OnDialogAction` for `0x00476410`.
- `ArticleDialog::SendReplyOrReportAction` or conservative `SubmitAction` for `0x00476740`; it reads control index `7`, closes/pops the dialog, then either sends opcode `0x3b` subcommand `8` when `this+0x276` is set or delegates text to `BulletinSession` helper `0x004712f0`.
- `ArticleDialog::CreateDeleteConfirmAlert` for `0x00476820`, an unreferenced duplicate of action case `4`'s `ConfirmDeleteAlert` construction.
- `ArticleDialog::HandleDeleteReplyPacket` for `0x004768c0`, checking packet subcommand `7`.
- `ArticleDialog::HandleDeleteReplyPayload` for `0x004769f0`, the shifted payload variant with no subcommand check.
- Raw helper `0x00476320` / `0x00476ba0`: retained send-current-article subcommand `5` helpers.
- Raw helper `0x00476620`: retained send-relative-article subcommand `3` helper; it mirrors action cases `1` and `5` but takes the direction as an argument.
- Raw helper `0x00476b10`: retained explicit send-relative-article helper taking board id, article id, and direction byte.

Do not create child pages during this callback unless the supervisor explicitly expands scope to exact helper splits. The raw helper bodies are source-shaped but have no direct xrefs, some have clone patterns elsewhere, and their final source spellings should be synchronized with `ArticleNavigationHelpers`, `NewArticleDialogCore`, and mail-side packet helper conventions. The implementation-ready repair for this report is target/support doc detail plus score movement, not emitted C++.

## Supervisor Active Recheck

- The active instruction is report-only research for UID00030J; no by-* edits are allowed in this phase.
- The item does not require a parent repair. Target, direct class parent, and file parent already clear the current gate.
- Every in-scope source-bearing subrange now has either a role and packet layout or an evidence-backed no-code/split rationale. No named blocker is left as "future investigation."

## Inference Research Guidance Check

- `by-structure.md` requires direct semantic ownership and separates `CANONICAL_OWNER` from `EMITTER_UIDS`. The current target correctly uses class ownership (`00000J`) and class/file output routing.
- Current docs and generated output were treated as leads. The B009 marker-only implementation is valid for generated health, but it did not resolve this target's action/packet helper semantics.
- Direct IDA/MCP facts are separated below from documentation evidence and inference.
- No Wave2/Wave3 source was used as authority. Recovered/generator material was used only as current generated-output state.

## Heuristic / Inference Reanalysis And Validation

- Action IDs: direct decompile of `0x00476410` resolves the switch. Case `1` increments `this+0x274` up to `0x7fff`; case `5` decrements it down to `1`; both send opcode `0x3b`, subcommand `3`, session board/context id from `this+0x270 + 0x102`, article id, and direction byte `+1` or `-1`, length `7`. Case `2` calls `0x00476740`. Case `3` pops/closes through `0x004a10e0`. Case `4` constructs `ConfirmDeleteAlert` and stores mode byte `0` at `+0x270`. Case `6` calls `0x004a0f40` on the session/dialog stack.
- Packet fields: `0x3b` is the board/article opcode in this family. UID00030J uses subcommands `3`, `5`, `7`, and `8`; UID00030H already covers shared subcommands `2`, `3`, `5`, and `7`, and UID00030K covers post subcommand `4` and transfer reply `6`.
- Raw helper reachability: current `xrefs_to` / `xref_query` reports zero direct xrefs to `0x00476320`, `0x00476620`, and `0x00476b10`. This does not make them padding: bounded disassembly shows normal prologues, security-cookie epilogues, packet writes, and send calls.
- Raw helper liveness: treat these as retained source helpers or address-taken/indirect-call bodies with missing direct IDA routes. Their bodies are too structured and duplicated across board/mail dialog families to classify as compiler glue.
- Delete/reply alert route: `0x004768c0` checks packet byte `+1 == 7`, decodes mode byte at `+2`, message length at `+3`, text bytes at `+4`, releases active modal/dimmer state, allocates `DeleteReplyAlert` through constructor `0x0047e2f0`, and returns handled. `0x004769f0` is the shifted payload twin starting at mode, length, text. Current `DeleteReplyAlert` docs confirm constructor callers from `0x004769c7` and `0x00476add`.
- Source split: exact child splits would be possible for individual helpers, but not required for the current repair. A split would require new UID pages for at least `0x00476320-0x004763bc`, `0x00476620-0x00476733`, `0x00476b10-0x00476b9d`, and `0x00476ba0-0x00476c07`, plus aggregate nesting. Since the helper roles are now understood but direct xrefs/original names remain absent, the safer callback is to document the roles and leave formal C++ marker-only.
- First-draft C++ readiness: not ready for a full aggregate body. The constructor is large, control/resource declaration shape is not synchronized, raw helper visibility is unresolved, `this+0x270/+0x274/+0x276`, control index `7`, session field `+0x102`, and singleton/modal globals still need final source-facing declarations before copy/paste-ready C++ is honest.

Rejected alternatives:

- Move owner to `BoardDialogs`: rejected. BoardDialogs is the file emitter bucket, but the constructor vtable stores and method cluster are class-owned by ArticleDialog.
- Move delete/reply helpers to `DeleteReplyAlert`: rejected. The helpers allocate/use `DeleteReplyAlert`, but their receiver is ArticleDialog and their vtable/server-response route belongs to ArticleDialog.
- Emit a partial aggregate C++ body now: rejected. It would either omit raw helpers and constructor details represented by the range, or invent synchronized declarations not yet documented.
- Split raw helpers now as the default callback: rejected for this report. Split is implementation-ready if requested, but the target can improve meaningfully without new UID files, and creating child pages would expand the callback beyond the assigned report-only surface.

## Evidence Standards Used

- Direct MCP evidence: current `server_health`, `lookup_funcs`, `xrefs_to`, `xref_query`, `callees`, `decompile`, `analyze_function`, `disasm`, `get_bytes`, and `find_bytes`.
- Documentation evidence: current by-* pages and executed B reports listed in Evidence Checked.
- Negative evidence: zero direct xrefs to raw starts, no function objects at raw starts, duplicate raw helper byte patterns, and current generated marker proving no full body exists.

## Evidence Checked

- MCP session: `supervisor_resume_20260629`, `server_health` status `ok`, `auto_analysis_ready:true`, `hexrays_ready:true`, `strings_cache_ready:true`, IDB `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, module `NexusTK.exe`.
- `lookup_funcs` on `0x004753e0`, `0x00476320`, `0x004763c0`, `0x00476410`, `0x00476620`, `0x00476740`, `0x00476820`, `0x004768c0`, `0x004769f0`, `0x00476b10`, `0x00476c0a`, `0x00476c10`.
- `xrefs_to` on target starts and vtables `0x00613f10`, `0x00613f74`, `0x00613fa4`.
- `callees` on modeled functions in UID00030J.
- `decompile` on `0x004763c0`, `0x00476410`, `0x00476740`, `0x00476820`, `0x004768c0`, `0x004769f0`; `analyze_function` on constructor `0x004753e0`.
- `disasm` and `get_bytes` on raw chunks `0x00476320`, `0x00476620`, `0x00476b10`, jump table `0x00476600`, and padding `0x00476c0a`.
- Existing report searches: `00030J`, `0x004753e0`, `004753e0`, `00476c0a`, `ArticleDialogCore`, `ArticleDialog`, `BoardDialogs`, `DeleteReplyAlert`, `BoardArticleDialogs`, `empty-emitter`. Relevant opened reports: executed B001 `0000ZK-BoardArticleDialogs.md`, executed B009 `0000HT-BoardDialogs-empty-emitter-family-source-quality.md`, executed B005 `00030K-NewArticleDialogCore-source-quality.md` as sibling precedent. No executed UID00030J-specific report exists; tracker row reports `0`.
- Generated/tracker state: `auto-generated/-ag-research-tracker.md` row for UID00030J reports `85/88`, average `86.5`, reconstructable true, reports `0`; `auto-generated/-ag-memory-coverage.md` routes UID00030J to `auto-generated/NexusTK/ui/dialogs/BoardDialogs.cpp`; generated file currently contains marker text for UID00030J and no empty marker for this UID.

Failed/skipped checks:

- No validator was run because this is report-only and no by-* docs were edited.
- No MCP process management was performed. MCP was available.

## Claim And Incorporation Ledger

| Claim ID | Claim | Confidence | Evidence | Destination doc/section | Action | Verification state |
| --- | --- | --- | --- | --- | --- | --- |
| C01 | UID00030J owner/emitter route remains `00000J` / `00000J`, surfacing through BoardDialogs. | High | Current target/class/file docs; MCP constructor caller/vtable stores. | Target Status/Assignment Decision; ArticleDialog Evidence Notes; BoardDialogs proposed contents. | applied | Applied in target status/evidence and support docs; metadata still `CANONICAL_OWNER:00000J`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:00000J`; validators `4544`, `4546`, `4548`, `4550` passed. |
| C02 | Modeled/raw boundary inventory remains accurate: modeled starts at `0x4753e0`, `0x4763c0`, `0x476410`, `0x476740`, `0x476820`, `0x4768c0`, `0x4769f0`; raw starts at `0x476320`, `0x476620`, `0x476b10`; padding `0x476c0a-0x476c10`. | High | Current `lookup_funcs`, `get_bytes`, `disasm`. | Target Covered Range/Boundary Notes. | applied | Applied in target Covered Range and function/packet sections; aggregate support row updated; no child pages created. |
| C03 | Action IDs resolve to next/read-relative, submit/reply action, close, delete-confirm, previous/read-relative, and stack/session action for cases `1` through `6`. | High | `decompile 0x00476410`; action jump table bytes at `0x00476600`. | Target Function-Level Behavior. | applied | Applied in target action table and ArticleDialog method notes. |
| C04 | Packet fields for action navigation are opcode `0x3b`, subcommand `3`, board/context id from session `+0x102`, article id, direction byte, length `7`. | High | `decompile 0x00476410`; `disasm 0x00476620`; packet helper callees. | Target packet table. | applied | Applied in target packet table and ArticleDialog/BoardDialogs support summaries. |
| C05 | Raw helper `0x00476320` sends opcode `0x3b`, subcommand `5`, session board/context id and `this+0x274`, length `6`, then records active dialog and starts dimmer/session wait. | High | `disasm 0x00476320`; `get_bytes`; zero xrefs. | Target raw helper notes. | applied | Applied in target Covered Range and packet table; zero-direct-xref caveat preserved. |
| C06 | Raw helper `0x00476620` sends opcode `0x3b`, subcommand `3`, computed previous/next article id, direction byte, length `7`, then active dialog/dimmer logic. | High | `disasm 0x00476620`; `get_bytes`; zero xrefs. | Target raw helper notes. | applied | Applied in target Covered Range and packet table; zero-direct-xref caveat preserved. |
| C07 | Tail raw region contains two helpers: `0x00476b10-0x00476b9d` explicit subcommand `3` sender and `0x00476ba0-0x00476c07` explicit subcommand `5` sender; `0x00476c0a-0x00476c10` is padding. | High | `disasm/get_bytes 0x00476b10`; `get_bytes 0x00476c0a`. | Target raw helper notes/boundary notes. | applied | Applied in target tail-helper rows and aggregate function/helper map. |
| C08 | Delete/reply response uses packet subcommand `7`; shifted payload helper starts at mode/length/text; both construct `DeleteReplyAlert`. | High | `decompile 0x004768c0`, `0x004769f0`; DeleteReplyAlert docs. | Target server-response behavior; DeleteReplyAlert evidence map. | applied | Applied in target server-response rows, packet table, and class method notes; support docs reference the delete/reply route. |
| C09 | `0x00476820` is an unreferenced duplicate helper for `ConfirmDeleteAlert` construction, matching action case `4`; it is not DeleteReplyAlert-owned. | Medium-high | `decompile 0x00476820`; action case `4`; xrefs zero. | Target covered range/source-quality notes. | applied | Applied in target Covered Range, ArticleDialog notes, BoardDialogs row, and aggregate evidence. |
| C10 | Current formal C++ should remain marker-only; first-draft aggregate code is unsafe until constructor/control declarations, raw helper visibility, and member names are synchronized or exact helper splits are approved. | High | by-structure C++ gate; current MCP; B009 marker precedent; target range contents. | Target Reconstruction Guidance/First-Draft C++ Recommendation. | applied | Applied by refining the target marker-only formal C++ comment and adding no-code rationale; no aggregate body inserted. Generated `BoardDialogs.cpp` refreshed at command `4548` with the marker and no empty marker for UID00030J. |
| C11 | Recommended score moves from `85/88` to `88/90`; not higher because no full formal body, exact original member names, and raw helper direct routes remain unresolved. | Medium-high | Score blocker audit; current evidence resolves named blockers except final C++ source shape. | Target metadata/Score Rationale; support docs summary. | applied | Applied in target metadata and score rationale; validator `4544` recorded `completion_update 00030J ... 88` and `confidence_update ... 90`. |

## Positive Evidence Summary

- Direct constructor ownership: `xrefs_to 0x004753e0` returns caller `0x00471b7a` in `sub_471A30`; vtable bases `0x00613f10`, `0x00613f74`, `0x00613fa4` are stored inside the constructor at `0x0047544a`, `0x00475450`, `0x0047545a`.
- Direct action/packet evidence: decompiled `0x00476410` shows command switch cases and calls packet write helpers `0x00575380`, `0x005753a0`, send path `0x00574bb0`, action helper `0x00476740`, confirm-delete constructor path, and stack helper `0x004a0f40`.
- Raw helper evidence: all raw starts have structured function prologues, security-cookie epilogues, packet helper calls, and exact lengths/padding; none are padding.
- Delete/reply alert evidence: `0x004768c0` and `0x004769f0` both allocate and call `0x0047e2f0`; `DeleteReplyAlert` docs list ArticleDialog callers `0x004769c7` and `0x00476add`.
- Generated-output evidence: UID00030J already emits a marker comment, proving the current no-body disposition is represented in generated output but not yet justified with target-specific current evidence.

## IDA MCP Facts

- Function/range facts: `lookup_funcs` says raw starts `0x00476320`, `0x00476620`, and `0x00476b10` are not functions; modeled functions and sizes are `sub_4753E0` `0xf35`, `sub_4763C0` `0x50`, `sub_476410` `0x1ee`, `sub_476740` `0xd4`, `sub_476820` `0x96`, `sub_4768C0` `0x12c`, `sub_4769F0` `0x112`, successor `sub_476C10` `0x541`.
- Data/table/padding facts: jump table at `0x00476600` contains six dword targets for action cases; `0x00476c0a-0x00476c10` is `0xcc` padding.
- Xref facts: raw starts have zero direct xrefs; modeled action and response entries are vtable/call routed; `0x00476740` is called from `0x0047656b`.
- Vtable facts: `ArticleDialog` vtable bases `0x00613f10`, `0x00613f74`, `0x00613fa4` each have constructor data refs in `sub_4753E0`.
- Negative IDA facts: no current direct xref proves live direct calls to retained helpers `0x00476320`, `0x00476620`, `0x00476820`, `0x004769f0`, or `0x00476b10`; their source status is inferred from body shape and range context.

## Function / Child Inventory

| Range / Item | UID / Path | Role | Reconstructable | Direct Parent | Score | Status |
| --- | --- | --- | --- | --- | --- | --- |
| `0x004753e0-0x00476315` | UID00030J | `ArticleDialog` constructor/setup | true | [UID:00000J] | `85/88` -> recommend `88/90` | Class-owned; large body still no full C++. |
| `0x00476320-0x004763bc` | UID00030J subrange | retained current-article send helper, subcmd `5` length `6` | true | [UID:00000J] | included | Raw no-function, no xrefs, source-shaped. |
| `0x004763c0-0x00476410` | UID00030J subrange | select current article row/control and refresh previous dialog | true | [UID:00000J] | included | Modeled function, no direct xrefs. |
| `0x00476410-0x004765fe` | UID00030J subrange | `OnDialogAction` switch | true | [UID:00000J] | included | Vtable-routed at `0x00613f58`; action IDs resolved. |
| `0x004765fe-0x00476618` | UID00030J subrange | action jump table | true | [UID:00000J] | included | Data owned by switch. |
| `0x00476620-0x00476733` | UID00030J subrange | retained relative article send helper, subcmd `3` length `7` | true | [UID:00000J] | included | Raw no-function, no xrefs, source-shaped. |
| `0x00476740-0x00476814` | UID00030J subrange | submit/reply/report action helper | true | [UID:00000J] | included | Called by action case `2`. |
| `0x00476820-0x004768b6` | UID00030J subrange | duplicate retained `ConfirmDeleteAlert` construction helper | true | [UID:00000J] | included | Modeled, no direct xrefs. |
| `0x004768c0-0x004769ec` | UID00030J subrange | `HandleDeleteReplyPacket`, subcmd `7` | true | [UID:00000J] | included | Vtable-routed at `0x00613f6c`. |
| `0x004769f0-0x00476b02` | UID00030J subrange | shifted `HandleDeleteReplyPayload` | true | [UID:00000J] | included | Modeled, no direct xrefs. |
| `0x00476b10-0x00476b9d` | UID00030J subrange | explicit relative send helper, subcmd `3` length `7` | true | [UID:00000J] | included | Raw no-function body inside tail chunk. |
| `0x00476ba0-0x00476c07` | UID00030J subrange | explicit current-article send helper, subcmd `5` length `6` | true | [UID:00000J] | included | Raw no-function body inside tail chunk. |
| `0x00476c0a-0x00476c10` | none | padding | false | none | n/a | `0xcc` padding before UID00030K. |

## Direct Xref / Caller Inventory

| Address / Item | Xref / Caller / Callee | Meaning |
| --- | --- | --- |
| `0x004753e0` | caller `0x00471b7a` in `sub_471A30` | BulletinSession creates ArticleDialog. |
| `0x00613f10` | data ref `0x0047544a` | ArticleDialog primary vtable store. |
| `0x00613f74` | data ref `0x00475450` | ArticleDialog secondary vtable store. |
| `0x00613fa4` | data ref `0x0047545a` | ArticleDialog tertiary vtable store. |
| `0x00476410` | data ref `0x00613f58` | vtable action handler slot. |
| `0x00476740` | code ref `0x0047656b` | action case `2` calls submit/action helper. |
| `0x004768c0` | data ref `0x00613f6c` | vtable server response slot. |
| `0x00476320`, `0x00476620`, `0x00476b10` | zero direct xrefs | retained raw helper bodies; no direct route. |

## Documentation Evidence And IDA Status

- Existing docs supporting conclusion: target page already has correct split inventory and owner; ArticleDialog class records exact child and vtable-family evidence; BoardDialogs records UID00030J as marker-only support; BoardArticleDialogs treats UID00030J as exact class-owned child; BoardArticleDialogVtableFamily records ArticleDialog vtables and constructor stores.
- Existing docs incomplete/stale: UID00030J says raw helper reachability/action IDs/packet fields are unresolved but does not include the current source-facing packet tables above. ArticleDialog class repeats the same blocker at class level.
- Generated/coverage state: generated `BoardDialogs.cpp` has non-empty UID00030J marker comment; generated memory coverage lists UID00030J as `coded`/`emits_code:true` because the marker comment exists, not because a full ArticleDialog body exists.

## Ranked Ownership Analysis

### 1. ArticleDialog class owner, emitted through BoardDialogs

- Evidence for: constructor caller from BulletinSession article-view path, ArticleDialog vtable stores, method cluster receiver fields, vtable action/server slots, target/class/file docs, vtable-family page.
- Evidence against: final `BoardDialogs.cpp` versus `ArticleDialogs.cpp` source-file split remains inferred; raw helpers have no direct xrefs.
- Decision: accepted. Keep `CANONICAL_OWNER:00000J`, `EMITTER_UIDS:00000J`.

### 2. BoardDialogs file owner directly

- Evidence for: all code is in board/article dialog source bucket and emitted into `BoardDialogs.cpp`.
- Evidence against: by-structure requires the narrow direct semantic owner; the receiver and vtable evidence are class-specific.
- Decision: rejected as canonical owner; BoardDialogs remains file-level output route only.

### 3. DeleteReplyAlert / BulletinReplyAlerts owner for response helpers

- Evidence for: `0x004768c0` and `0x004769f0` construct `DeleteReplyAlert`.
- Evidence against: they are ArticleDialog response handlers using ArticleDialog receiver/session state; DeleteReplyAlert is the allocated alert object, not the handler owner.
- Decision: rejected.

### 4. Exact raw-helper child split

- Evidence for: exact function-shaped raw bodies and clear packet roles.
- Evidence against: no direct xrefs, duplicate helper patterns elsewhere, and current aggregate can document roles without inventing new UID pages during report-only pass.
- Decision: optional future implementation if supervisor expands scope; not required for this report's accepted callback.

## Source Placement

- Recommended source placement: ArticleDialog methods/helpers in the board/article dialog source bucket, likely an eventual `ArticleDialogs.cpp` or `BoardDialogs.cpp` split under `NexusTK/ui/dialogs/`.
- Why it fits: ArticleDialog is one of the board/article dialog classes in the contiguous family, constructed by BulletinSession and routed through BoardDialogs; it shares packet helpers and alert classes with ArticleList/NewArticle flows.
- Rejected placements: `BulletinSession.cpp` owns the coordinator call site, not the dialog body; `BulletinReplyAlerts.cpp` owns alert classes, not ArticleDialog server response methods; one broad `BoardArticleDialogs` aggregate is already rejected as non-emitting split inventory.

## Range / Split / Padding / Reclassification Analysis

- Exact range remains valid: `0x004753e0-0x00476c0a`; successor padding `0x00476c0a-0x00476c10`; UID00030K starts at `0x00476c10`.
- No immediate new child files are required. If the supervisor wants exact helper splits later, create children for `0x00476320-0x004763bc`, `0x00476620-0x00476733`, `0x00476b10-0x00476b9d`, and `0x00476ba0-0x00476c07`, then update UID00030J as an aggregate with nested children.
- Reclassification: none. UID00030J remains reconstructable true.

## Negative Evidence Summary

- No direct xrefs to raw starts: current `xrefs_to` and `xref_query` are empty for `0x00476320`, `0x00476620`, and `0x00476b10`.
- Byte-pattern duplicates: raw prologue/packet-helper patterns also appear at addresses such as `0x0047c410` and `0x0047c780`, so raw-byte similarity alone is not unique ownership proof.
- No safe full aggregate C++: constructor/control/resource setup is large and not fully source-shaped; helper visibility is unresolved; some helper bodies are duplicated/retained with no direct route.
- Consumer relationship is not ownership: DeleteReplyAlert and ConfirmDeleteAlert are constructed/used, but ArticleDialog remains the method owner.

## IDA Rename / Type / Comment Recommendations

- Proposed source-facing names for documentation only:
  - `ArticleDialog::OnDialogAction`
  - `ArticleDialog::SendReplyOrReportAction` / conservative `SubmitAction`
  - `ArticleDialog::CreateDeleteConfirmAlert`
  - `ArticleDialog::HandleDeleteReplyPacket`
  - `ArticleDialog::HandleDeleteReplyPayload`
  - `SendCurrentArticleRequest`, `SendRelativeArticleRequest`, and `SendArticleRequest` style names for raw helper bodies, marked inferred/descriptive.
- Proposed field meanings for documentation only:
  - `this+0x270`: session/dialog-session pointer used for board/context id and stack operations.
  - `this+0x274`: current/selected article id used by navigation helpers.
  - `this+0x276`: submit/action mode byte controlling `0x00476740` packet-vs-session branch.
  - control index `7`: text/control used by `0x00476740`.
- IDA DB edits: not requested. These are documentation/source-facing names only.

## First-Draft C++ Recommendation

- Eligible for draft C++: yes by metadata minimum (`RECONSTRUCTABLE:TRUE`, nonblank emitter route, average `86.5`), but not ready for honest final-source body.
- Recommended code: keep the existing formal marker-only block, but update surrounding prose to explain the current no-code proof:

```text
// UID00030J ArticleDialogCore is covered through UID00000J ArticleDialog and UID0000HT BoardDialogs. No partial aggregate body is emitted here because the range mixes the ArticleDialog constructor, action switch, server-response handlers, retained raw packet helpers, jump-table bytes, and unresolved final class/member/control declarations. Current MCP resolves the packet/action roles, but final source should wait for either a synchronized full ArticleDialog draft or exact helper child splits.
```

- Reason it preserves behavior: it avoids emitting a partial body that would omit in-range helpers or invent unverified declarations.
- Reason it matches plausible source shape: a real source file would likely contain the constructor, action methods, retained helpers, and server-response methods together under ArticleDialog, but the current project does not yet have the supporting class/header declarations to express that cleanly.
- Exact no-code proof: the range contains multiple modeled functions, raw no-function retained helpers, jump-table bytes, and duplicated helper bodies; direct xrefs for several retained helpers are absent; current generated marker is the correct formal output until a full aggregate draft or split callback is approved.

## Final Recommendation

- Exact changes recommended: update UID00030J body with current MCP evidence, function-level behavior, packet field table, raw helper roles, no-code proof, score rationale, and generated marker status.
- Exact parent assignments recommended: unchanged `CANONICAL_OWNER:00000J`, `EMITTER_UIDS:00000J`.
- Score recommended: `COMPLETION 85 -> 88`, `CONFIDENCE 88 -> 90`.
- Exact support changes recommended: synchronize ArticleDialog and BoardDialogs notes to say UID00030J's action/packet roles are now documented, while full C++ remains marker-only.
- Future work outside this assignment: full ArticleDialog C++ body pass or exact helper split pass if the supervisor wants to convert the aggregate marker into source bodies.

## Recommended Target Doc Changes

- Target path: `by-memory/0x004753e0-0x00476c0a.ArticleDialogCore.md`
- Incorporate the function inventory, action switch mapping, packet tables, raw helper roles, duplicate `ConfirmDeleteAlert` helper, delete/reply packet/payload distinction, zero-direct-xref negative evidence, and no-code proof from this report.
- Metadata changes: `COMPLETION:88`, `CONFIDENCE:90`; owner/emitter/reconstructable unchanged.
- C++ block: keep marker-only, optionally replace marker with the refined text above.
- Preserve historical assumptions: B009 marker-only implementation remains valid but was an empty-emitter fix, not a full source-quality pass; old "unresolved action IDs/packet fields" wording should be historicalized as now resolved at documentation level.

## Recommended Support Doc Changes

- `by-class/ArticleDialog.md`: update Autogen Status/Method Notes/Evidence Notes/Score Rationale to record that UID00030J's packet/action fields are now documented; preserve marker-only class-level C++ because class/header split and raw helper policy still block standalone declaration output. Recommended class score after callback: `86/89` or keep `85/87` if supervisor wants only target score movement; do not lower.
- `by-file/BoardDialogs.md`: update the ArticleDialog proposed-content row and empty-emitter family/source disposition note with UID00030J `88/90`, current MCP session `supervisor_resume_20260629`, resolved action IDs/packet fields, and retained no-partial-body proof. File score can remain `87/88` because broad file partitioning remains the cap.
- `by-memory/0x00472070-0x00477790.BoardArticleDialogs.md`: update the UID00030J child inventory row to `88/90` and note current source-quality packet/action repair; aggregate disposition unchanged.
- No generated reports, coverage reports, validator state, or supervisor ledgers should be manually edited.

## Score And Metadata Recommendation

- Current score/metadata: `85/88`, owner/emitter `00000J`, reconstructable true, marker-only formal C++.
- Recommended score/metadata: `88/90`, owner/emitter unchanged, reconstructable unchanged, marker-only formal C++ retained with stronger no-code proof.
- Score rationale: completion rises because all named blockers from the assignment now have current evidence-backed dispositions: action IDs, packet fields, raw helper roles, delete/reply route, owner/emitter, source placement, split/no-split, and C++ disposition. Confidence rises because MCP evidence directly confirms boundaries, xrefs, vtable stores, and decompiled behavior.
- Reason not higher: no full final C++ body, constructor still lacks source-quality declarations, raw retained helpers still have no direct route, exact original helper/member names remain inferred, and final `BoardDialogs.cpp` versus `ArticleDialogs.cpp` partition remains unresolved.

Score-limiting blocker audit:

- Action IDs: resolved by `decompile 0x00476410`; no longer a blocker.
- Packet fields: resolved enough for docs by decompile/disasm; exact source names remain inferred but not a blocker for score `88/90`.
- Raw helper reachability: zero direct xrefs proven; role documented; this remains a final-C++ blocker but not an ownership/score blocker.
- Source split: optional exact helper splits documented; no split required for current repair.
- Final C++ readiness: resolved as exact no-code proof, not left as future work.

## Open Questions With Attempted Resolution

- Exact original names for helper methods and fields remain unknown. Current evidence supports descriptive source-facing names but not original spelling. This limits final C++, not documentation improvement.
- Whether raw helpers are indirectly called, template/inline clones, or retained dead helpers remains unresolved. Current direct xref checks are empty; byte-pattern checks show clones elsewhere. Treat as retained source helpers with no direct route.
- Final source file partition (`BoardDialogs.cpp` vs `ArticleDialogs.cpp`) remains unresolved at file-family level and is outside this target's owner/emitter repair.

## Follow-Up Actions

- Supervisor actions: validate this report, then send an implementation callback if accepted. After B004 callback implementation and supervisor verification, supervisor runs the executed-report lifecycle command; B004 must not run it.
- A-agent actions: none.
- B004 callback actions: update target/support docs at report-level detail, run scoped validators for changed by-* docs, inspect generated `BoardDialogs.cpp` only after validator refresh if C++ marker text changes.

## Confidence

- Recommendation confidence: high.
- Score confidence: medium-high.
- Remaining uncertainty: exact original source names, indirect retained-helper routes, final header/source split, and complete constructor source body.

## Validator Results

- Commands run from `source-3/project-documentation` with `--apply --queue-timeout 240`:
  - `python .\tools\validator.py --mode file --file by-memory/0x004753e0-0x00476c0a.ArticleDialogCore.md --apply --queue-timeout 240`
    - `command_id: 000000004544`, `command_timestamp: 2026-07-02T14:16:17-04:00`, exit code `0`, `ok: 1`.
    - Applied `completion_update 00030J ... 88`, `confidence_update 00030J ... 90`, registry hash update, reference index add, stats row remove/projected stats update; generated refresh deferred.
  - `python .\tools\validator.py --mode file --file by-class/ArticleDialog.md --apply --queue-timeout 240`
    - `command_id: 000000004546`, `command_timestamp: 2026-07-02T14:16:25-04:00`, exit code `0`, `ok: 1`.
    - Applied two UID link-label normalizations for UID00030J and stats/projected stats updates; generated refresh deferred.
  - `python .\tools\validator.py --mode file --file by-file/BoardDialogs.md --apply --queue-timeout 240`
    - `command_id: 000000004548`, `command_timestamp: 2026-07-02T14:16:39-04:00`, exit code `0`, `ok: 1`.
    - File was not present in generated stats lists; projected stats updated; generated refresh deferred.
  - `python .\tools\validator.py --mode file --file by-memory/0x00472070-0x00477790.BoardArticleDialogs.md --apply --queue-timeout 240`
    - `command_id: 000000004550`, `command_timestamp: 2026-07-02T14:16:56-04:00`, exit code `0`, `ok: 1`.
    - File was not present in generated stats lists; projected stats updated; generated refresh deferred.
- Generated refresh state:
  - `python .\tools\validator.py --queue-status` at `command_id: 000000004552`, `2026-07-02T14:17:19-04:00`, reported `queued generated refresh jobs: 0`, `processing generated refresh jobs: 0`.
  - Read-only inspection of `auto-generated/NexusTK/ui/dialogs/BoardDialogs.cpp` shows `validator-command-id: 000000004548`, `validator-refreshed-at: 2026-07-02T14:16:39-04:00`, `validator-refresh-source: deferred-generated-refresh`, and UID00030J at `Completion:88 | Confidence:90` with the refined marker-only text.
- Any unresolved validator warnings/errors: none observed.

## Changed Files

- Created:
  - `tools/leaser/Agents/Agent-B004/research/00030J-ArticleDialogCore-source-quality.md`
- Modified:
  - `by-memory/0x004753e0-0x00476c0a.ArticleDialogCore.md`
  - `by-class/ArticleDialog.md`
  - `by-file/BoardDialogs.md`
  - `by-memory/0x00472070-0x00477790.BoardArticleDialogs.md`
  - `tools/leaser/Agents/Agent-B004/research/00030J-ArticleDialogCore-source-quality.md`
- Renamed:
  - none.
- Report execution: not run. B agents must not run `tools/validator.py execute_report`, any `execute_report` variant, registry lifecycle command, manual report move, or equivalent archive command.
- Leases: B004 leased the four by-* files, the first lease window expired before validation, a fresh scoped lease was taken for the validator batch, and all four by-* leases were released successfully after validators and generated-refresh queue check.

## Implementation Tracking Checklist

Initial report-only pass:

- [x] Supervisor validation required before implementation. Applied: supervisor accepted the report for implementation callback before by-* edits.
- [x] Target/support docs to update: `by-memory/0x004753e0-0x00476c0a.ArticleDialogCore.md`, `by-class/ArticleDialog.md`, `by-file/BoardDialogs.md`, and `by-memory/0x00472070-0x00477790.BoardArticleDialogs.md`. Applied: all four files updated and validated.
- [x] Current target state and actual evidence checked recorded: current metadata `85/88`, owner/emitter `00000J`, generated marker state, MCP session `supervisor_resume_20260629`, exact MCP calls, related docs, and old reports listed in Evidence Checked. Already present in report before callback.
- [x] Claim And Incorporation Ledger updated with destination and verification state for every accepted claim. Applied: ledger C01-C11 now says `applied` with proof.
- [x] Metadata/score changes to apply: update UID00030J to `88/90`; support-page scores remain unchanged per accepted scope. Applied: validator `4544` confirmed `completion_update ... 88` and `confidence_update ... 90`.
- [x] Score-limiting blockers researched to resolution, implementation-ready repair/split recommendation, or rare exact evidence-backed no-improvement proof. Already present and incorporated in target/support docs.
- [x] Owner/emitter/reconstructable changes to apply: none; preserve `CANONICAL_OWNER:00000J`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:00000J`. Applied/confirmed unchanged.
- [x] Split/rename/new-child changes to apply: none. Excluded with reason: accepted callback said no child pages unless docs could not be made consistent; docs were made consistent without children.
- [x] Source-placement, range/split/padding/reclassification, or IDA rename/type/comment changes to apply or confirm not applicable. Applied/confirmed: ArticleDialog/BoardDialogs placement and padding documented; no IDA DB edits requested.
- [x] First-draft C++ or no-code proof to apply: keep/refine marker-only formal C++ text; do not insert full aggregate body. Applied: marker refined; no aggregate body inserted.
- [x] Third-party import directive to apply or confirm not applicable. Excluded with reason: not applicable to UID00030J.
- [x] Exact target/support doc facts to incorporate at report-level detail. Applied: action switch mapping, packet layouts, raw helper roles, delete/reply packet and payload distinction, duplicate ConfirmDeleteAlert helper, vtable/caller evidence, zero-xref negative evidence, generated marker state, rejected alternatives, and score rationale are now in target/support docs.
- [x] Historical/stale assumptions, rejected alternatives, and negative evidence to preserve. Applied: B009 marker-only history and rejected owner/split/full-C++ alternatives remain documented.
- [x] Wave2/Wave3 mentions or artifacts encountered and ignored/rejected as stale, if applicable. Already present: no Wave2/Wave3 source authority used.
- [x] Open questions to close or document as evidence-backed unresolved. Applied: helper/member names, indirect retained-helper routes, and final file partition remain documented as C++ caps, not ownership blockers.
- [x] Validators to run after accepted callback edits. Applied: scoped validators `4544`, `4546`, `4548`, and `4550` passed.
- [x] Generated report refresh expected or explicit manual supervisor-owned coverage/tracker text to apply. Applied: no manual coverage/tracker text; generated queue clear at `4552`, and `BoardDialogs.cpp` refreshed by validator `4548`.

Implementation callback pass:

- [x] Report accepted by supervisor for implementation. Applied: callback received for UID00030J.
- [x] All accepted target/support doc details incorporated at report-level detail. Applied across the four accepted by-* files.
- [x] Claim And Incorporation Ledger updated with destination and verification state for every accepted claim. Applied: C01-C11 updated with proof.
- [x] Metadata/score/owner/emitter/split/rename/C++ changes applied or explicitly not applied with reason. Applied: UID00030J `85/88 -> 88/90`; owner/emitter/reconstructable unchanged; no splits/renames/children; marker-only C++ retained/refined.
- [x] Historical/stale assumptions, rejected alternatives, and negative evidence preserved. Applied in target/support docs and this report.
- [x] Open questions resolved or documented with evidence-backed unresolved rationale. Applied: unresolved original names, indirect routes, and final file partition are documented as confidence/final-C++ caps.
- [x] Validators run and results recorded. Applied: see Validator Results for commands `4544`, `4546`, `4548`, `4550`.
- [x] Generated report refresh completed by validator or explicit manual supervisor-owned coverage/tracker text supplied/confirmed unchanged. Applied: generated queue clear at `4552`; `BoardDialogs.cpp` read-only inspection shows validator `4548` refresh and UID00030J `88/90`.
- [x] Remaining unapplied accepted items listed with exact blocker. Applied: no accepted items remain unapplied; excluded items are no child pages, no aggregate C++ body, no IDA edits, no third-party import, and no manual generated/coverage edits.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B004","command_id":"000000004554","destination_path":"executed-b-agent-research/B004/00030J-ArticleDialogCore-source-quality.md","details":"report executed into central archive","event":"executed","source_path":"tools/leaser/Agents/Agent-B004/research/00030J-ArticleDialogCore-source-quality.md","timestamp":"2026-07-02T14:23:56-04:00","uid":"00030J"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
