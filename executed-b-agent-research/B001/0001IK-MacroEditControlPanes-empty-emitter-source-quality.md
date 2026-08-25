** TARGET-REPORT-UID:0001IK **
** AUTHOR-AGENT-ID:B001 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **

# B001 Report: UID0001IK MacroEditControlPanes Empty Emitter Source Quality

Assignment: `B001-report-0001IK-MacroEditControlPanes-empty-emitter-source-quality-20260628`

Target: [UID:0001IK] `by-memory/0x0057f750-0x005807c5.MacroEditControlPanes.md`

Report path: `tools/leaser/Agents/Agent-B001/research/0001IK-MacroEditControlPanes-empty-emitter-source-quality.md`

Revision assignment: `B001-revise-report-0001IK-MacroEditControlPanes-empty-emitter-source-quality-20260629`

Revision status: report-only revision in place. No target/support by-* docs, generated files, manual coverage reports, validator/tool state, IDA DB state, executed-report archives, or project-level generated files were edited.

## Final Recommendation

Convert [UID:0001IK] from a reconstructable MacroDialogs-emitting aggregate with blank C++ into a non-emitting split inventory/source-route container after exact child repair.

Recommended parent metadata after accepted implementation:

- `COMPLETION:90`
- `CONFIDENCE:91`
- `CANONICAL_OWNER:0000KY`
- `RECONSTRUCTABLE:FALSE`
- `EMITTER_UIDS:` blank
- Formal `RECONSTRUCTION_CPP` block blank.

The parent should keep source-family attachment to [UID:0000KY] `by-file/MacroDialogs.md`, but it must not emit source itself. The range spans three row-control classes, source-authored methods, compiler destructor artifacts, vtable/adjustor thunks, unmodeled method bodies, and internal alignment. Emission must move to exact method children. Compiler-generated children must be explicit non-code children with blank emitter metadata.

This report resolves the current empty-emitter disposition rather than deferring it: every proposed source-bearing child below has exact formal C++ insertion text, and every compiler/no-source child has an exact no-code marker.

## Current Empty-Emitter State

Historical read-only generated check on `auto-generated/NexusTK/ui/dialogs/MacroDialogs.cpp` showed validator command `000000005136`, refreshed `2026-06-28T15:24:15-04:00`, with empty markers then still present for:

- [UID:0001IK] `by-memory\0x0057f750-0x005807c5.MacroEditControlPanes.md`
- [UID:0001IM] `by-memory\0x0057fa80-0x0057fa9e.NewMacroEditControlPaneTeardownHelper.md`
- Class/support rows [UID:00006M], [UID:000095], [UID:0000DQ], [UID:0001Y1], and [UID:0003DB] remain separate empty-marker/support issues in the same generated file.

Current revision check on 2026-06-29 supersedes the [UID:0001IM] part of that stale generated state: `auto-generated/NexusTK/ui/dialogs/MacroDialogs.cpp` still contains [UID:0001IK] as an `Empty Emitter Marker`, while [UID:0001IM] no longer appears there after the accepted B002 reclassification. Current generated output still contains separate class-level empty markers for [UID:00006M], [UID:000095], and [UID:0000DQ]. This report's implementation target is therefore to remove the [UID:0001IK] aggregate empty marker by splitting exact source-bearing children and converting the parent to a non-emitting container. It does not claim to solve every MacroDialogs class-level empty marker.

## Live MCP Evidence

MCP was live and current evidence was collected from session/database `supervisor_20260628_resume`.

- `idb_list`: one active worker session, `session_id=supervisor_20260628_resume`, `input_path=E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, `pid=5124`, `is_active=true`, `is_analyzing=false`.
- `server_health`: `status=ok`, IDB `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, input binary `C:\Users\admin\Desktop\Clone\NexusTK\NexusTK.exe`, module `NexusTK.exe`, image base `0x400000`, `auto_analysis_ready=true`, `hexrays_ready=true`, `strings_cache_ready=true`, strings cache size `2067`.
- Tool schema rechecked: `decompile` uses singular `addr`; `xrefs_to` uses `addrs`; `entity_query`, `insn_query`, and `get_bytes` are available.

Fresh `entity_query` for `0x0057f750-0x005807d0` found all modeled functions in the island:

`0x0057f750` size `0x8`; `0x0057f760` `0x49`; `0x0057f7b0` `0x1f`; `0x0057f7d0` `0x157`; `0x0057f930` `0x68`; `0x0057f9a0` `0x5`; `0x0057f9b0` `0x8`; `0x0057f9c0` `0x7`; `0x0057f9d0` `0x5b`; `0x0057fa30` `0x10`; `0x0057fa40` `0x12`; `0x0057fa60` `0x10`; `0x0057fa70` `0xa`; `0x0057fa80` `0x1f`; `0x0057faa0` `0x1d6`; `0x0057fc80` `0x7f`; `0x0057fd00` `0x5`; `0x0057fd10` `0x1ec`; `0x0057ff60` `0x3c`; `0x0057ffa0` `0xa`; `0x0057ffb0` `0x363`; `0x00580320` `0x13d`; `0x00580460` `0x24`; `0x00580490` `0x24`; `0x00580550` `0x63`; `0x005805c0` `0x1a`; `0x005805e0` `0x5e`; thunks `0x00580640` through `0x0058067c`; scalar deleting destructors `0x00580690`, `0x00580710`, and `0x00580770`. The successor `StartupWindow__Constructor` begins at `0x005807d0`.

Gap scans found real unmodeled code that the current target page does not split:

- `0x0057fefc-0x0057ff00`: four `0xcc` bytes.
- `0x0057ff00-0x0057ff3f`: unmodeled `IntegrateMacroEditControlPane` non-deleting destructor body. It restores three integrate vtables, deletes `this+0x110` when non-null through virtual deleting destructor argument `1`, nulls `this+0x110`, and tail-jumps to `Pane::~Pane()` at `0x00544580`.
- `0x0057ff3f-0x0057ff40`: one `0xcc` byte.
- `0x0057ff40-0x0057ff5b`: unmodeled boolean helper returning whether the bound macro record has state `1` and the edit-active byte at `+0x10d` is nonzero.
- `0x0057ff5b-0x0057ff60`: five `0xcc` bytes.
- `0x005804b4-0x005804c0`: alignment bytes.
- `0x005804c0-0x0058050d`: unmodeled helper that enters text-edit mode by setting `+0x10d`, applying saved edit-control state byte `+0x114`, showing/focusing the editor, and selecting text range `0..0x7fff`.
- `0x0058050d-0x00580510`: alignment bytes.
- `0x00580510-0x00580545`: unmodeled helper that leaves text-edit mode by clearing `+0x10d`, applying edit-control mode `4`, and hiding/deactivating the editor.
- `0x00580545-0x00580550`: alignment bytes.

`xrefs_to` highlights:

- Direct callers: `GetSpellKey` from `0x0053ed27`; Spell constructor from `0x0053eac5` and `0x0053ec1d`; New constructor from `0x0053ef2c`; New getters/setters from B010 NewMacroDialog children; Integrate constructor from `0x00541cc5`; `SetMacroData` and `RefreshDisplay` from `0x00542247` and `0x0054224e`.
- Vtable-routed methods: Spell paint/key/selectable at `0x0062d228`, `0x0062d254`, `0x0062d250`; New paint/key/selectable at `0x0062d2cc`, `0x0062d2f8`, `0x0062d2f4`; Integrate paint/key/mouse/focus/attach/hide/sync at `0x0062d370`, `0x0062d39c`, `0x0062d398`, `0x0062d3a0`, `0x0062d35c`, `0x0062d364`, `0x0062d384`.
- Compiler routes: thunks `0x00580640` through `0x0058067c` have exact vtable refs; scalar deleting destructors have thunk and vtable refs.
- No inbound xrefs: [UID:0001IL] `0x0057f7b0`, [UID:0001IM] `0x0057fa80`, raw destructor `0x0057ff00`, raw predicate `0x0057ff40`, raw enter helper `0x005804c0`, and raw leave helper `0x00580510`.

## 2026-06-29 Revision Evidence Checked

Current assignment recheck:

- Active instruction: revise this report in place only; do not edit target/support by-* docs, generated files, project-level generated files, manual coverage reports, validator/tool state, IDA DB, executed archives, or run `execute_report`.
- Target doc current state: [UID:0001IK] `by-memory/0x0057f750-0x005807c5.MacroEditControlPanes.md` is currently `COMPLETION:85`, `CONFIDENCE:88`, `CANONICAL_OWNER:0000KY`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000KY`, with blank formal C++ and an Item Summary explicitly citing method-split/final-C++ caveats.
- Existing exact support children checked: [UID:0001IM] is already `88/92`, `CANONICAL_OWNER:000095`, `RECONSTRUCTABLE:FALSE`, blank emitters, blank formal C++; [UID:0001IN] is `85/90`, `CANONICAL_OWNER:NONE`, `RECONSTRUCTABLE:FALSE`, blank emitters, blank formal C++.
- Primary support docs checked: [UID:0000KY] `by-file/MacroDialogs.md`, [UID:0000DQ] `by-class/SpellMacroEditControlPane.md`, [UID:000095] `by-class/NewMacroEditControlPane.md`, [UID:00006M] `by-class/IntegrateMacroEditControlPane.md`.
- Secondary support docs checked: [UID:0001Y1] `by-type/by-vtable/MacroDialogFamilyVtables.md`, [UID:0003DB] `by-memory/0x0062d1e0-0x0062d3cc.MacroEditControlPaneVtableData.md`.
- Generated/read-only state checked: `auto-generated/-ag-research-tracker.md`, `auto-generated/-ag-coverage-report-by-memory.md`, and `auto-generated/NexusTK/ui/dialogs/MacroDialogs.cpp`. The tracker currently shows [UID:0001IK] with `Reports 0`, [UID:0001IL]/[UID:0001IM]/[UID:0003DB] with executed B reports, and generated `MacroDialogs.cpp` still has a UID0001IK empty marker.
- Old-report search terms used: `0001IK`, `0x0057f750`, `0x005807c5`, `MacroEditControlPanes`, `MacroEditControlPane`, `0x0057ff00`, `0x005804c0`, `NewMacroEditControlPaneTeardownHelper`, and `MacroEditControlPaneVtableThunks` across `executed-b-agent-research` and `tools/leaser/Agents`.
- Matching accepted reports treated as support: B004 [UID:0001IL] destructor-helper no-code report, B002 [UID:0001IM] destructor-helper no-code report, B003 [UID:0003DB] vtable-data covered-by report, B010 [UID:0001DR] MacroDialogs split/source-quality report for caller and row-control context, B010 [UID:0001IO] for successor padding `0x005807c5-0x005807d0`, and prior A-agent notes as historical leads only.

Current MCP spot-check, session `07c55da0` on 2026-06-29:

- `idb_list`: one active worker session, `session_id=07c55da0`, `input_path=E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, `filename=NexusTK.exe.i64`, `is_active=true`, `is_analyzing=false`, `pid=9064`, `worker_pid=9064`, `backend=worker`, `owned=true`, `adopted=true`.
- `server_health`: `status=ok`, IDB `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, input binary `C:\Users\admin\Desktop\Clone\NexusTK\NexusTK.exe`, module `NexusTK.exe`, image base `0x400000`, `auto_analysis_ready=true`, `hexrays_ready=true`, `strings_cache_ready=true`, strings cache size `2067`.
- `tools/list` schema was rechecked. The active schema requires `database` for session-aware calls, `lookup_funcs` uses `queries`, `xrefs_to` uses `addrs`, `entity_query` uses `min_addr`/`max_addr`, and `get_bytes` uses `regions`.
- `entity_query` over functions in `0x0057f750-0x005807d0`, count 50, returned 38 records. It reconfirmed the modeled functions from `0x0057f750` through the thunk/destructor run and the successor `StartupWindow__Constructor` at `0x005807d0`.
- `lookup_funcs` reconfirmed representative split anchors: `0x0057f750` size `0x8`; `0x0057f760` size `0x49`; `0x0057f7b0` size `0x1f`; `0x0057f7d0` size `0x157`; `0x0057fa80` size `0x1f`; `0x0057fd10` size `0x1ec`; `0x00580640` size `0x5`; `0x00580690` size `0x71`; `0x00580710` size `0x55`; `0x00580770` size `0x55`; and `0x005807d0` as `StartupWindow__Constructor` size `0x3c`.
- The same `lookup_funcs` spot-check reported `0x0057ff00`, `0x0057ff40`, `0x005804c0`, and `0x00580510` as `Not a function`, preserving this report's raw-helper child recommendation rather than treating them as already modeled IDA functions.
- `xrefs_to` reconfirmed zero inbound xrefs for raw helper starts `0x0057ff00`, `0x0057ff40`, `0x005804c0`, `0x00580510`, and [UID:0001IM] `0x0057fa80`. It also reconfirmed vtable/thunk routing: `0x00580640` has one data xref from `0x0062d388`; `0x00580690`, `0x00580710`, and `0x00580770` each have two adjustor-thunk code refs plus one primary-vtable data ref.
- `get_bytes` samples reconfirmed `0xcc` padding before `0x0057ff00`, real instruction bodies for `0x0057ff00` and `0x0057ff40`, twelve `0xcc` bytes before raw helper `0x005804c0`, the raw enter/leave helper bodies with three-byte alignment between them, and the complete `0x00580640` thunk run followed by `0xcc` padding before `0x00580690`.

## Stale Reference Handling

- No unhandled `Wave2`, `Wave3`, `simroot`, `recovered-source`, or `recovered source` references are present in this report body; the only mentions are this explicit stale-reference disposition.
- Current support docs do contain active stale `Wave3`, `simroot_v2`, "Current recovered file/source", and disabled generated-output references. These were treated as lead/history only and not as authoritative evidence for this revision. The revised recommendation relies on current by-* docs, generated read-only state, executed B reports, and the 2026-06-29 MCP spot-check.
- The historical [UID:0001IM] empty-marker statement in this report is now explicitly superseded by the current generated check and accepted B002 implementation. It remains in the report only as historical evidence for why the original report bundled UID0001IM into the split/source-quality pass.

Exact support-doc stale-source actions required during an accepted implementation callback:

| Support doc | Active stale wording found | Required callback action |
| --- | --- | --- |
| [UID:0000KY] `by-file/MacroDialogs.md` | Status line `Current recovered sources: class_MacroDialog.cpp, class_SpellMacroDialog.cpp, class_NewMacroDialog.cpp, class_IntegrateMacroDialog.cpp, class_NewMacroEditControlPane.cpp, class_SpellMacroEditControlPane.cpp, and class_IntegrateMacroEditControlPane.cpp` | Historicalize/rewrite as stale generated source leads, not current recovered source authority. Preserve the filenames only as old generated-output search terms and state that current source placement is supported by by-* docs, executed reports, and MCP evidence. |
| [UID:0000KY] `by-file/MacroDialogs.md` | Evidence line `Wave3 reports high effective grades...` | Historicalize/rewrite as old Wave3 grading lead material. Do not present Wave3 grades as current evidence for score, ownership, or source placement. |
| [UID:0000KY] `by-file/MacroDialogs.md` | Evidence line `Current simroot_v2 metadata still reports vtable_count: 0...` | Historicalize/rewrite as stale simroot metadata caveat: old generated metadata was incomplete for vtables, so current reconstruction must use [UID:0001Y1], [UID:0003DB], by-* docs, and MCP evidence. |
| [UID:0000KY] `by-file/MacroDialogs.md` | Caveat line `not modeled consistently by Wave3` and `Treat the generated control files as behavior evidence...` | Rewrite as stale generated-output limitation. Preserve the useful point that generated control output is not final source authority, but avoid active Wave3 authority language. |
| [UID:0000DQ] `by-class/SpellMacroEditControlPane.md` | Status line `Current recovered file: source-3/simroot_v2/class_SpellMacroEditControlPane.cpp` | Historicalize/rewrite as stale generated source lead only; the class source route and method split must cite [UID:0001IK], new child pages, [UID:0001Y1], [UID:0003DB], and MCP evidence instead. |
| [UID:0000DQ] `by-class/SpellMacroEditControlPane.md` | Evidence line `Disabled generated output includes the adjustor thunk... missing body text in simroot_v2...` | Rewrite as stale generated-output limitation: old generated output was incomplete for thunk coverage; current IDA/MCP and [UID:0001IN] prove the paired adjustor thunk route. |
| [UID:000095] `by-class/NewMacroEditControlPane.md` | Status line `Current recovered file: source-3/simroot_v2/class_NewMacroEditControlPane.cpp` | Historicalize/rewrite as stale generated source lead only; current source route and method split must cite [UID:0001IK], new child pages, [UID:0001Y1], [UID:0003DB], [UID:0001IM], and MCP evidence instead. |
| [UID:000095] `by-class/NewMacroEditControlPane.md` | Evidence line `Disabled generated output includes the 0x00580666 adjustor thunk... missing body text in simroot_v2...` | Rewrite as stale generated-output limitation: old generated output was incomplete for thunk coverage; current IDA/MCP and [UID:0001IN] prove the paired adjustor thunk route. |
| [UID:00006M] `by-class/IntegrateMacroEditControlPane.md` | Status line `Current recovered file: source-3/simroot_v2/class_IntegrateMacroEditControlPane.cpp` | Historicalize/rewrite as stale generated source lead only; current class reconstruction must cite [UID:0001IK], new child pages, [UID:0001Y1], [UID:0003DB], [UID:0001IN], and MCP evidence instead. |
| [UID:00006M] `by-class/IntegrateMacroEditControlPane.md` | Evidence line `Disabled generated output includes only the 0x00580650 adjustor thunk...` | Rewrite as stale generated-output limitation if the class page is edited for child links. Preserve the useful fact that generated output missed real IDA starts, but cite current [UID:0001IN]/MCP evidence as authority. |
| [UID:0001Y1] `by-type/by-vtable/MacroDialogFamilyVtables.md` | Evidence line `Current simroot_v2 metadata still reports vtable_count: 0...` | Historicalize/rewrite as stale simroot metadata caveat. Keep the warning that generated metadata was incomplete, but state that current vtable reconstruction uses this page, [UID:0003DB], and MCP-backed slot/xref evidence. |
| [UID:0001IN] `by-memory/0x00580640-0x00580686.MacroEditControlPaneVtableThunks.md` | Bare cross-reference `[Wave3 data issue](../wave3_data_issues.md)` | Explicitly exclude from mandatory stale-source cleanup if [UID:0001IN] is not otherwise edited, because it is only a historical issue link and not active source evidence. If [UID:0001IN] is leased for stale timeout wording, historicalize the link label/context as a generated-data issue reference, not source authority. |

## Heuristic / Inference Reanalysis And Validation

The source-quality blocker is resolved as an implementation-ready split, not left as future research. The current [UID:0001IK] page is a mixed aggregate with reconstructable source-authored methods, compiler-generated destructor glue/thunks, raw unmodeled helper bodies, and padding. Keeping it reconstructable/emitting with blank C++ is the active empty-emitter defect. A broad parent C++ block is also invalid because by-memory C++ must cover only the target range's own source-level item, and this parent is not a single source method/class declaration.

The best current source-shape model is a non-emitting [UID:0001IK] inventory/container under [UID:0000KY] `MacroDialogs`, with exact child method pages carrying the actual source bodies through [UID:0000DQ], [UID:000095], and [UID:00006M]. Compiler-retained complete-object destructor glue ([UID:0001IL] and [UID:0001IM]), compiler vtable thunks ([UID:0001IN]), and new scalar deleting destructor wrappers should remain non-reconstructable/non-emitting or formal no-code children as listed. This follows the current `by-structure.md` distinction between source-authored behavior and compiler/linker-generated artifacts.

The raw helpers at `0x0057ff00`, `0x0057ff40`, `0x005804c0`, and `0x00580510` remain implementation-ready child pages despite no inbound xrefs. Current MCP shows they are not modeled as IDA functions but byte evidence proves real instruction bodies inside the parent. They must not be hidden as padding; the child pages must preserve the no-xref caveat and the raw-helper source role.

The score blocker is therefore not "needs investigation." It is converted into the concrete child-creation and support-doc repair plan below. The parent score can move to `90/91` only after the child split exists, the parent is documented as a non-emitting inventory, support links are synchronized, and validators refresh generated state.

## Claim And Incorporation Ledger

Allowed actions use the current report standard: `incorporate`, `already-present`, `historicalize`, `reject-stale`, `reject-invalid`, or `not-applicable`. Verification state is report-only `proposed` until a supervisor-approved implementation callback applies or excludes the claim.

| Claim ID | Claim | Confidence | Evidence | Destination doc/section | Action | Verification state |
| --- | --- | --- | --- | --- | --- | --- |
| C001 | [UID:0001IK] should become a non-emitting split inventory/container, not a reconstructable MacroDialogs emitter. Metadata after implementation: `90/91`, owner [UID:0000KY], `RECONSTRUCTABLE:FALSE`, blank `EMITTER_UIDS`, blank formal C++. | High | Current target metadata, generated UID0001IK empty marker, MCP function/byte split evidence, by-structure aggregate rule. | `by-memory/0x0057f750-0x005807c5.MacroEditControlPanes.md` metadata/status/summary/C++ block | incorporate | applied; proof below |
| C002 | The parent remains source-family attached to [UID:0000KY] `MacroDialogs`, but source emission moves to exact method children and class owners. | High | MacroDialogs support doc, class pages, vtable family docs, current MCP island boundaries. | [UID:0001IK] and [UID:0000KY] source-route sections | incorporate | applied; proof below |
| C003 | Historical [UID:0001IM] empty-marker evidence from `2026-06-28T15:24:15-04:00` is stale for current generated output; UID0001IM is already non-emitting after B002. | High | Current generated `MacroDialogs.cpp` search, [UID:0001IM] metadata, tracker row with executed B002 report. | [UID:0001IK] history/change notes and this report archive trail | reject-stale | applied; proof below |
| C004 | Create `SpellMacroEditControlPaneGetSpellKey` child `0x0057f750-0x0057f758`, owner/emitter [UID:0000DQ], `86/90`, formal CPP-1. | High | MCP function size `0x8`, caller `0x0053ed27`, Spell class support docs. | New `by-memory/0x0057f750-0x0057f758.SpellMacroEditControlPaneGetSpellKey.md` | incorporate | applied; proof below |
| C005 | Create `SpellMacroEditControlPaneConstructor` child `0x0057f760-0x0057f7a9`, owner/emitter [UID:0000DQ], `87/90`, formal CPP-2. | High | MCP function size `0x49`, Spell constructor callsites, vtable-store evidence. | New `by-memory/0x0057f760-0x0057f7a9.SpellMacroEditControlPaneConstructor.md` | incorporate | applied; proof below |
| C006 | Existing [UID:0001IL] remains non-reconstructable compiler-retained complete-object destructor glue with blank formal C++; no new source C++. | High | Accepted B004 report, current support docs, vtable parity. | Existing `by-memory/0x0057f7b0-0x0057f7ce.SpellMacroEditControlPaneTeardownHelper.md`; parent inventory | already-present | already-present; proof below |
| C007 | Create Spell `OnPaint`, `OnKeyEvent`, and `IsSelectable` children for `0x0057f7d0-0x0057f927`, `0x0057f930-0x0057f998`, and `0x0057f9a0-0x0057f9a5`, owner/emitter [UID:0000DQ], formal CPP-3 through CPP-5. | High | MCP function sizes `0x157`, `0x68`, `0x5`; vtable slots; class docs. | New Spell child pages and [UID:0000DQ] method map | incorporate | applied; proof below |
| C008 | Create NewMacro getters/constructor/setters/refresh children for `0x0057f9b0-0x0057fa7a`, owner/emitter [UID:000095], formal CPP-6 through CPP-12. | High | MCP function list, New class docs, B010 save/load caller evidence. | New NewMacro child pages and [UID:000095] method map | incorporate | applied; proof below |
| C009 | Existing [UID:0001IM] is already non-reconstructable compiler-retained complete-object destructor glue with blank emitter/C++; parent/support docs should preserve that no-code proof. | High | Current [UID:0001IM] metadata, accepted B002 report, current xrefs zero. | Existing [UID:0001IM], [UID:0001IK], [UID:000095], [UID:0000KY] | already-present | already-present; proof below |
| C010 | Create NewMacro `OnPaint`, `OnKeyEvent`, and `IsSelectable` children for `0x0057faa0-0x0057fd05`, owner/emitter [UID:000095], formal CPP-13 through CPP-15. | High | MCP function sizes `0x1d6`, `0x7f`, `0x5`; vtable slots; class docs. | New NewMacro child pages and [UID:000095] method map | incorporate | applied; proof below |
| C011 | Create `IntegrateMacroEditControlPaneConstructor` child `0x0057fd10-0x0057fefc`, owner/emitter [UID:00006M], `87/90`, formal CPP-16. | High | MCP size `0x1ec`, constructor caller `0x00541cc5`, Integrate class docs. | New Integrate child page and [UID:00006M] method map | incorporate | applied; proof below |
| C012 | Create raw `IntegrateMacroEditControlPaneNonDeletingDestructor` child `0x0057ff00-0x0057ff3f`, owner/emitter [UID:00006M], formal CPP-17. It is source-authored destructor semantics, not compiler-only glue. | High | Current bytes show vtable stores, deletes `this+0x110`, nulls it, tail-jumps base; vtable data refs in UID0003DB. | New raw child page; [UID:00006M] destructor notes | incorporate | applied; proof below |
| C013 | Create raw `IntegrateMacroEditControlPaneIsTextEditActive` child `0x0057ff40-0x0057ff5b`, owner/emitter [UID:00006M], formal CPP-18, preserving zero-inbound-xref caveat. | Medium-high | Current bytes, current `xrefs_to` zero, predicate behavior. | New raw child page; [UID:00006M] helper notes | incorporate | applied; proof below |
| C014 | Create Integrate `SetMacroData`, `RefreshDisplay`, `OnPaint`, `OnKeyEvent`, mouse/focus forwarder, attach, hide, and sync children for `0x0057ff60-0x0058063e`, owner/emitter [UID:00006M], formal CPP-19 through CPP-24 and CPP-27 through CPP-29. | High | MCP function list, class docs, vtable slots, direct callers for SetMacroData/RefreshDisplay. | New Integrate method child pages and [UID:00006M] method map | incorporate | applied; proof below |
| C015 | Create raw `EnterTextEditMode` and `LeaveTextEditMode` children at `0x005804c0-0x0058050d` and `0x00580510-0x00580545`, owner/emitter [UID:00006M], formal CPP-25 and CPP-26, preserving zero-inbound-xref caveats. | Medium-high | Current bytes show real bodies and padding; current `xrefs_to` zero; behavior matches edit-active state transitions. | New raw child pages and [UID:00006M] helper notes | incorporate | applied; proof below |
| C016 | Existing [UID:0001IN] stays non-reconstructable compiler vtable thunk/adjustor support; update stale timeout wording if touched. | High | Current [UID:0001IN] metadata, current xrefs/bytes, MacroDialogFamilyVtables slots. | Existing [UID:0001IN], [UID:0001IK], [UID:0001Y1], [UID:0003DB] | incorporate | applied; proof below |
| C017 | Create scalar deleting destructor wrapper children for Integrate, New, and Spell at `0x00580690-0x00580701`, `0x00580710-0x00580765`, and `0x00580770-0x005807c5`; classify as non-reconstructable/no-emitter except source destructor semantics covered by CPP-17 for Integrate. | High | Current lookup sizes, xrefs from adjustor thunks and vtable data, compiler ABI policy. | New scalar destructor child pages; class/vtable support docs | incorporate | applied; proof below |
| C018 | Record all listed internal `0xcc` padding spans on the parent and in `by-memory/-ignored.md` only if implementation policy requires an ignored-ledger entry. | High | Current bytes samples plus prior MCP function-boundary evidence. | [UID:0001IK] padding section; optional `by-memory/-ignored.md` supervisor-approved edit | incorporate | applied; proof below |
| C019 | Boundary exclusions remain: predecessor `0x0057f6a0-0x0057f741` belongs to `SpellInventoryPane`; successor `0x005807d0` starts `StartupWindow__Constructor`; `0x005807c5-0x005807d0` is padding. | High | Current lookup `StartupWindow__Constructor` at `0x005807d0`, B010 successor report, current target docs. | [UID:0001IK] boundary section; optional ignored ledger | incorporate | applied; proof below |
| C020 | Support doc [UID:0000KY] must add the exact UID0001IK split inventory, raw helper discovery, compiler/no-code distinction, and current UID0001IM historical/stale disposition. | High | MacroDialogs support current contents and missing exact child table. | `by-file/MacroDialogs.md` | incorporate | applied; proof below |
| C021 | Support docs [UID:0000DQ], [UID:000095], and [UID:00006M] must link the new method children and preserve exact no-code/helper caveats. | High | Current class method maps are aggregate-level; split children do not exist yet. | Three `by-class/*.md` docs | incorporate | applied; proof below |
| C022 | Support docs [UID:0001Y1] and [UID:0003DB] must update edit-control slot/child UID references after validator assigns UIDs, while preserving compiler-generated vtable/thunk handling. | High | Current vtable docs contain slot addresses and existing UID0003DB proof; child UIDs not yet assigned. | `by-type/by-vtable/MacroDialogFamilyVtables.md`; `by-memory/0x0062d1e0-0x0062d3cc.MacroEditControlPaneVtableData.md` | incorporate | applied; proof below |
| C023 | All C++ snippets CPP-1 through CPP-29 are exact formal `RECONSTRUCTION_CPP CODE:BEGIN/END` insertion text for the corresponding source-bearing child pages; no body-only sample code is proposed. | Medium-high | Report formal C++ section; current by-structure C++ rule. | New source-bearing child pages | incorporate | applied; proof below |
| C024 | Compiler/no-source children must keep blank formal C++ and explicit no-code proof rather than comment-only source unless the validator requires a covered-by marker for a reconstructable emitter. | High | [UID:0001IL]/[UID:0001IM] accepted no-code policy, [UID:0001IN] compiler-thunk policy, by-structure no-emitter rule. | Existing/new no-code child pages | incorporate | applied; proof below |
| C025 | No manual generated files, manual coverage reports, validator state, IDA DB state, executed archives, or `execute_report` actions belong to the B001 report-only pass or implementation callback; supervisor owns report execution after verification. | High | Current assignment and workflow. | Report checklist and callback instructions | not-applicable | not-applicable; proof below |
| C026 | [UID:0000KY] `MacroDialogs.md` active `Current recovered sources` line must be historicalized/reworded as stale generated source leads, not current source authority. Preserve filenames only as old generated-output search terms. | High | Current `MacroDialogs.md` line 13; current workflow rejects stale recovered-source/simroot authority. | `by-file/MacroDialogs.md` Status | historicalize | applied; proof below |
| C027 | [UID:0000KY] `MacroDialogs.md` active `Wave3 reports high effective grades...` line must be historicalized/reworded as old Wave3 grading lead material, not current score/ownership/source-placement evidence. | High | Current `MacroDialogs.md` line 86; current workflow rejects stale Wave3 as authority. | `by-file/MacroDialogs.md` Evidence | historicalize | applied; proof below |
| C028 | [UID:0000KY] `MacroDialogs.md` active `Current simroot_v2 metadata...` wording and Caveats `not modeled consistently by Wave3` wording must be rewritten as stale generated-output limitations; current vtable/source evidence comes from [UID:0001Y1], [UID:0003DB], by-* docs, and MCP. | High | Current `MacroDialogs.md` lines 101 and 111; current by-vtable/vtable-data docs and MCP evidence. | `by-file/MacroDialogs.md` Evidence/Caveats | historicalize | applied; proof below |
| C029 | [UID:0000DQ] `SpellMacroEditControlPane.md` active `Current recovered file: source-3/simroot_v2/class_SpellMacroEditControlPane.cpp` line must be historicalized as stale generated source lead only. | High | Current `SpellMacroEditControlPane.md` line 19; current split report and MCP evidence. | `by-class/SpellMacroEditControlPane.md` Status | historicalize | applied; proof below |
| C030 | [UID:0000DQ] `SpellMacroEditControlPane.md` disabled generated-output/simroot wording for thunk coverage must be rewritten as stale generated-output limitation; current [UID:0001IN]/MCP evidence proves the thunk pair. | High | Current `SpellMacroEditControlPane.md` line 45; [UID:0001IN], [UID:0001Y1], current MCP xrefs/bytes. | `by-class/SpellMacroEditControlPane.md` Evidence Notes | historicalize | applied; proof below |
| C031 | [UID:000095] `NewMacroEditControlPane.md` active `Current recovered file: source-3/simroot_v2/class_NewMacroEditControlPane.cpp` line must be historicalized as stale generated source lead only. | High | Current `NewMacroEditControlPane.md` line 19; current split report, [UID:0001IM], and MCP evidence. | `by-class/NewMacroEditControlPane.md` Status | historicalize | applied; proof below |
| C032 | [UID:000095] `NewMacroEditControlPane.md` disabled generated-output/simroot wording for thunk coverage must be rewritten as stale generated-output limitation; current [UID:0001IN]/MCP evidence proves the thunk pair. | High | Current `NewMacroEditControlPane.md` line 58; [UID:0001IN], [UID:0001Y1], current MCP xrefs/bytes. | `by-class/NewMacroEditControlPane.md` Evidence Notes | historicalize | applied; proof below |
| C033 | [UID:00006M] `IntegrateMacroEditControlPane.md` active `Current recovered file: source-3/simroot_v2/class_IntegrateMacroEditControlPane.cpp` line must be historicalized as stale generated source lead only. | High | Current `IntegrateMacroEditControlPane.md` line 19; current split report and MCP evidence. | `by-class/IntegrateMacroEditControlPane.md` Status | historicalize | applied; proof below |
| C034 | [UID:00006M] `IntegrateMacroEditControlPane.md` disabled generated-output wording for missing thunk starts must be rewritten as stale generated-output limitation if that class page is edited for child links; current [UID:0001IN]/MCP evidence is authority. | High | Current `IntegrateMacroEditControlPane.md` line 59; [UID:0001IN], [UID:0001Y1], current MCP xrefs/bytes. | `by-class/IntegrateMacroEditControlPane.md` Evidence Notes | historicalize | applied; proof below |
| C035 | [UID:0001Y1] `MacroDialogFamilyVtables.md` active `Current simroot_v2 metadata still reports vtable_count: 0...` wording must be historicalized as stale simroot metadata caveat; current vtable reconstruction uses [UID:0001Y1], [UID:0003DB], and MCP-backed slot/xref evidence. | High | Current `MacroDialogFamilyVtables.md` line 29; [UID:0003DB] and current MCP evidence. | `by-type/by-vtable/MacroDialogFamilyVtables.md` Evidence | historicalize | applied; proof below |
| C036 | [UID:0001IN] `MacroEditControlPaneVtableThunks.md` bare `[Wave3 data issue]` cross-reference is historicalized because UID0001IN was edited for stale timeout wording. | Medium-high | Current `MacroEditControlPaneVtableThunks.md` cross-reference/history; UID0001IN was in the callback edit batch. | `by-memory/0x00580640-0x00580686.MacroEditControlPaneVtableThunks.md` Cross-References | historicalize | applied; proof below |

## Implementation Callback Proof

Callback proof for C001-C036:

| Claims | State | Proof |
| --- | --- | --- |
| C001-C002 | applied | [UID:0001IK] metadata is now `90/91`, owner `0000KY`, `RECONSTRUCTABLE:FALSE`, blank `EMITTER_UIDS`, blank formal C++; parent page contains the exact split child/source-route inventory and remains MacroDialogs source-family inventory only. |
| C003 | applied / stale rejected | Historical UID0001IM empty-marker evidence was not copied forward as current state; generated `MacroDialogs.cpp` refresh command `000000000321` contains no UID0001IK empty marker and no UID0001IM empty marker. |
| C004-C005, C007-C008, C010-C015, C017, C023 | applied | Created source/no-code children [UID:0004A1]-[UID:0004AW] in address order with CPP-1 through CPP-29 on source-bearing pages and blank formal C++ on scalar deleting destructor wrappers. Child validators `000000000281` through `000000000312` all exited 0 and assigned UIDs. |
| C006, C009 | already-present | [UID:0001IL] and [UID:0001IM] already had accepted non-reconstructable, blank-emitter, blank-C++ complete-object destructor glue dispositions; parent/support docs now preserve those states. |
| C016, C036 | applied | [UID:0001IN] stale timeout summary was closed with current evidence, scalar-wrapper child links were added, and the bare Wave3 link was historicalized as stale generated-data context. |
| C018-C019 | applied | [UID:0001IK] lists split/padding boundaries; `by-memory/-ignored.md` now records the internal UID0001IK alignment gaps while preserving existing successor `0x005807c5-0x005807d0` boundary padding. |
| C020-C022, C026-C035 | applied | `MacroDialogs.md`, the three edit-control class pages, `MacroDialogFamilyVtables.md`, and UID0003DB now link exact child UIDs and historicalize active stale recovered-source/Wave3/simroot/generated-output wording as specified. |
| C024 | applied | [UID:0004AU], [UID:0004AV], and [UID:0004AW] are non-reconstructable/no-emitter blank-C++ scalar deleting destructor wrapper pages; [UID:0001IL], [UID:0001IM], and [UID:0001IN] remain no-code. |
| C025 | not-applicable | No generated files, manual coverage reports, validator/tool state, IDA DB, executed archives, or `execute_report` were edited/run manually. Generated files were read only after validator refresh. |

Validator and generated-output proof:

| Batch | Commands | Result |
| --- | --- | --- |
| Child validators | `000000000281` through `000000000312`, `python .\tools\validator.py --mode file --file <child> --apply --queue-timeout 240` | Exit 0 for each child; assigned UIDs [UID:0004A1]-[UID:0004AW]; generated refresh deferred until support batch. |
| Parent/support validators | `000000000313` through `000000000321`, `--wait-generated` | Exit 0 for [UID:0001IK], [UID:0001IN], [UID:0003DB], [UID:0000KY], [UID:0000DQ], [UID:000095], [UID:00006M], [UID:0001Y1], and `by-memory/-ignored.md`; generated refresh completed foreground at command `000000000321`, timestamp `2026-06-29T02:11:03-04:00`. |
| Generated read-only checks | `auto-generated/NexusTK/ui/dialogs/MacroDialogs.cpp`, `auto-generated/-ag-research-tracker.md`, `auto-generated/-ag-coverage-report-by-memory.md` | Header shows validator command `000000000321`; UID0001IK no longer appears as an empty emitter marker; class-level empty markers [UID:00006M], [UID:000095], [UID:0000DQ], [UID:0001Y1] remain out of scope; tracker/coverage refresh headers match command `000000000321`. |
| Leases | B001 lease/unlease state | Short leases were acquired for the immediate edit batch. On release, B001 leases had already expired; current lease file shows no active B001 leases, only other agents. No B001 lease remains held. |

## Split Matrix

Implementation should create new by-memory child pages for every row marked `new`, and update existing children marked `existing`. UID assignment is left to the validator during implementation.

| Page / range | Status | Owner | Emitter route | Score | Disposition |
| --- | --- | --- | --- | --- | --- |
| `by-memory/0x0057f750-0x0057f758.SpellMacroEditControlPaneGetSpellKey.md` | new | [UID:0000DQ] | [UID:0000DQ] | `86/90` | Source-bearing; insert CPP-1. |
| `by-memory/0x0057f760-0x0057f7a9.SpellMacroEditControlPaneConstructor.md` | new | [UID:0000DQ] | [UID:0000DQ] | `87/90` | Source-bearing; insert CPP-2. |
| [UID:0001IL] `by-memory/0x0057f7b0-0x0057f7ce.SpellMacroEditControlPaneTeardownHelper.md` | existing | [UID:0000DQ] | blank | `88/92` | Keep accepted B004 no-code marker: compiler-retained complete-object destructor glue, no formal C++. |
| `by-memory/0x0057f7d0-0x0057f927.SpellMacroEditControlPaneOnPaint.md` | new | [UID:0000DQ] | [UID:0000DQ] | `88/91` | Source-bearing; insert CPP-3. |
| `by-memory/0x0057f930-0x0057f998.SpellMacroEditControlPaneOnKeyEvent.md` | new | [UID:0000DQ] | [UID:0000DQ] | `88/91` | Source-bearing; insert CPP-4. |
| `by-memory/0x0057f9a0-0x0057f9a5.SpellMacroEditControlPaneIsSelectable.md` | new | [UID:0000DQ] | [UID:0000DQ] | `86/90` | Source-bearing; insert CPP-5. |
| `by-memory/0x0057f9b0-0x0057f9b8.NewMacroEditControlPaneGetKey.md` | new | [UID:000095] | [UID:000095] | `86/90` | Source-bearing; insert CPP-6. |
| `by-memory/0x0057f9c0-0x0057f9c7.NewMacroEditControlPaneGetMode.md` | new | [UID:000095] | [UID:000095] | `86/90` | Source-bearing; insert CPP-7. |
| `by-memory/0x0057f9d0-0x0057fa2b.NewMacroEditControlPaneConstructor.md` | new | [UID:000095] | [UID:000095] | `87/90` | Source-bearing; insert CPP-8. |
| `by-memory/0x0057fa30-0x0057fa40.NewMacroEditControlPaneSetRecordIndex.md` | new | [UID:000095] | [UID:000095] | `86/90` | Source-bearing; insert CPP-9. |
| `by-memory/0x0057fa40-0x0057fa52.NewMacroEditControlPaneSetKey.md` | new | [UID:000095] | [UID:000095] | `86/90` | Source-bearing; insert CPP-10. |
| `by-memory/0x0057fa60-0x0057fa70.NewMacroEditControlPaneSetMode.md` | new | [UID:000095] | [UID:000095] | `86/90` | Source-bearing; insert CPP-11. |
| `by-memory/0x0057fa70-0x0057fa7a.NewMacroEditControlPaneRefresh.md` | new | [UID:000095] | [UID:000095] | `86/90` | Source-bearing; insert CPP-12. |
| [UID:0001IM] `by-memory/0x0057fa80-0x0057fa9e.NewMacroEditControlPaneTeardownHelper.md` | existing | [UID:000095] | blank | `88/92` | Reclassify to exact no-code marker: compiler-retained complete-object destructor glue, same policy as [UID:0001IL], no formal C++. |
| `by-memory/0x0057faa0-0x0057fc76.NewMacroEditControlPaneOnPaint.md` | new | [UID:000095] | [UID:000095] | `88/91` | Source-bearing; insert CPP-13. |
| `by-memory/0x0057fc80-0x0057fcff.NewMacroEditControlPaneOnKeyEvent.md` | new | [UID:000095] | [UID:000095] | `88/91` | Source-bearing; insert CPP-14. |
| `by-memory/0x0057fd00-0x0057fd05.NewMacroEditControlPaneIsSelectable.md` | new | [UID:000095] | [UID:000095] | `86/90` | Source-bearing; insert CPP-15. |
| `by-memory/0x0057fd10-0x0057fefc.IntegrateMacroEditControlPaneConstructor.md` | new | [UID:00006M] | [UID:00006M] | `87/90` | Source-bearing; insert CPP-16. |
| `by-memory/0x0057ff00-0x0057ff3f.IntegrateMacroEditControlPaneNonDeletingDestructor.md` | new | [UID:00006M] | [UID:00006M] | `87/91` | Source-bearing raw unmodeled destructor body; insert CPP-17. |
| `by-memory/0x0057ff40-0x0057ff5b.IntegrateMacroEditControlPaneIsTextEditActive.md` | new | [UID:00006M] | [UID:00006M] | `86/89` | Source-bearing but no inbound xref; insert CPP-18 and preserve no-xref caveat. |
| `by-memory/0x0057ff60-0x0057ff9c.IntegrateMacroEditControlPaneSetMacroData.md` | new | [UID:00006M] | [UID:00006M] | `88/91` | Source-bearing; insert CPP-19. |
| `by-memory/0x0057ffa0-0x0057ffaa.IntegrateMacroEditControlPaneRefreshDisplay.md` | new | [UID:00006M] | [UID:00006M] | `86/90` | Source-bearing; insert CPP-20. |
| `by-memory/0x0057ffb0-0x00580313.IntegrateMacroEditControlPaneOnPaint.md` | new | [UID:00006M] | [UID:00006M] | `88/91` | Source-bearing; insert CPP-21. |
| `by-memory/0x00580320-0x0058045d.IntegrateMacroEditControlPaneOnKeyEvent.md` | new | [UID:00006M] | [UID:00006M] | `88/91` | Source-bearing; insert CPP-22. |
| `by-memory/0x00580460-0x00580484.IntegrateMacroEditControlPaneForwardMouseEvent.md` | new | [UID:00006M] | [UID:00006M] | `86/90` | Source-bearing; insert CPP-23. |
| `by-memory/0x00580490-0x005804b4.IntegrateMacroEditControlPaneForwardFocusEvent.md` | new | [UID:00006M] | [UID:00006M] | `86/90` | Source-bearing; insert CPP-24. |
| `by-memory/0x005804c0-0x0058050d.IntegrateMacroEditControlPaneEnterTextEditMode.md` | new | [UID:00006M] | [UID:00006M] | `86/89` | Source-bearing raw unmodeled helper with no inbound xref; insert CPP-25 and preserve no-xref caveat. |
| `by-memory/0x00580510-0x00580545.IntegrateMacroEditControlPaneLeaveTextEditMode.md` | new | [UID:00006M] | [UID:00006M] | `86/89` | Source-bearing raw unmodeled helper with no inbound xref; insert CPP-26 and preserve no-xref caveat. |
| `by-memory/0x00580550-0x005805b3.IntegrateMacroEditControlPaneOnAttachToParent.md` | new | [UID:00006M] | [UID:00006M] | `87/90` | Source-bearing; insert CPP-27. |
| `by-memory/0x005805c0-0x005805da.IntegrateMacroEditControlPaneOnHide.md` | new | [UID:00006M] | [UID:00006M] | `86/90` | Source-bearing; insert CPP-28. |
| `by-memory/0x005805e0-0x0058063e.IntegrateMacroEditControlPaneSyncEditControl.md` | new | [UID:00006M] | [UID:00006M] | `88/91` | Source-bearing; insert CPP-29. |
| [UID:0001IN] `by-memory/0x00580640-0x00580686.MacroEditControlPaneVtableThunks.md` | existing | NONE | blank | `85/90` | Keep no-code marker: compiler vtable thunk/adjustor run; refresh stale timeout wording only. |
| `by-memory/0x00580690-0x00580701.IntegrateMacroEditControlPaneScalarDeletingDestructor.md` | new | [UID:00006M] | blank | `88/92` | No-code marker: compiler ABI scalar deleting destructor, covered by CPP-17 class destructor semantics. |
| `by-memory/0x00580710-0x00580765.NewMacroEditControlPaneScalarDeletingDestructor.md` | new | [UID:000095] | blank | `88/92` | No-code marker: compiler ABI scalar deleting destructor, no standalone formal C++. |
| `by-memory/0x00580770-0x005807c5.SpellMacroEditControlPaneScalarDeletingDestructor.md` | new | [UID:0000DQ] | blank | `88/92` | No-code marker: compiler ABI scalar deleting destructor, no standalone formal C++. |

## Padding And Boundaries

Record these internal non-code spans on the parent page and, if implementation policy requires, in `by-memory/-ignored.md`: `0x0057f758-0x0057f760`, `0x0057f7a9-0x0057f7b0`, `0x0057f7cf-0x0057f7d0`, `0x0057f927-0x0057f930`, `0x0057f998-0x0057f9a0`, `0x0057f9a5-0x0057f9b0`, `0x0057f9b8-0x0057f9c0`, `0x0057f9c7-0x0057f9d0`, `0x0057fa2b-0x0057fa30`, `0x0057fa52-0x0057fa60`, `0x0057fa7a-0x0057fa80`, `0x0057fa9f-0x0057faa0`, `0x0057fc76-0x0057fc80`, `0x0057fcff-0x0057fd00`, `0x0057fd05-0x0057fd10`, `0x0057fefc-0x0057ff00`, `0x0057ff3f-0x0057ff40`, `0x0057ff5b-0x0057ff60`, `0x0057ff9c-0x0057ffa0`, `0x0057ffaa-0x0057ffb0`, `0x00580313-0x00580320`, `0x0058045d-0x00580460`, `0x00580484-0x00580490`, `0x005804b4-0x005804c0`, `0x0058050d-0x00580510`, `0x00580545-0x00580550`, `0x005805b3-0x005805c0`, `0x005805da-0x005805e0`, `0x0058063e-0x00580640`, `0x00580687-0x00580690`, `0x00580701-0x00580710`, `0x00580765-0x00580770`, and `0x005807c5-0x005807d0`.

Boundary exclusions remain unchanged: predecessor `0x0057f6a0-0x0057f741` belongs to `SpellInventoryPane`, and successor `0x005807d0` starts `StartupWindow__Constructor`.

## Formal C++ Blocks

Insert each block exactly between the target child's formal `RECONSTRUCTION_CPP CODE:BEGIN` and `END` lines. The inline `RECONSTRUCTION_CPP CODE:[[[]]]` value stays blank. Helper names are source-facing first-draft names inferred from current MacroDialogs docs and accepted B010 source style.

CPP-1 for `SpellMacroEditControlPaneGetSpellKey`:

```cpp
uint16_t SpellMacroEditControlPane::GetSpellKey() const
{
    return m_spellKey;
}
```

CPP-2 for `SpellMacroEditControlPaneConstructor`:

```cpp
SpellMacroEditControlPane::SpellMacroEditControlPane(uint16_t spellKey, const Rect &bounds)
    : ControlPane(8, bounds),
      m_spellKey(spellKey)
{
    SetSelectable(true);
}
```

CPP-3 for `SpellMacroEditControlPaneOnPaint`:

```cpp
void SpellMacroEditControlPane::OnPaint()
{
    const Rect row = GetClientRect();
    BeginMacroRowPaint();

    const SpellRecord &spell = g_spellRecords[NormalizeSpellKey(m_spellKey)];
    const int centerY = (row.Height() + 12) / 2;

    if (UseEpfMacroDialogLayout())
    {
        DrawMacroRowText(row.left + 5, centerY, FormatSpellKey(m_spellKey));
        DrawMacroRowText(row.left + 15, centerY, spell.displayName);
    }
    else
    {
        DrawMacroRowText(row.left + 1, row.bottom - 1, FormatSpellKey(m_spellKey));
    }

    if (IsFocused())
        DrawMacroRowFocus(row);
}
```

CPP-4 for `SpellMacroEditControlPaneOnKeyEvent`:

```cpp
bool SpellMacroEditControlPane::OnKeyEvent(const KeyEvent &event)
{
    if (event.type == KeyEvent::KeyDown)
    {
        const uint8_t key = NarrowKey(event);
        if (IsAsciiLetter(key))
        {
            m_spellKey = key;
            RequestParentRefresh();
            return true;
        }
    }
    else if (event.type == KeyEvent::KeyUp)
    {
        return true;
    }

    return false;
}
```

CPP-5 for `SpellMacroEditControlPaneIsSelectable`:

```cpp
bool SpellMacroEditControlPane::IsSelectable() const
{
    return true;
}
```

CPP-6 for `NewMacroEditControlPaneGetKey`:

```cpp
uint16_t NewMacroEditControlPane::GetKey() const
{
    return m_key;
}
```

CPP-7 for `NewMacroEditControlPaneGetMode`:

```cpp
uint8_t NewMacroEditControlPane::GetMode() const
{
    return m_mode;
}
```

CPP-8 for `NewMacroEditControlPaneConstructor`:

```cpp
NewMacroEditControlPane::NewMacroEditControlPane(uint16_t key, int recordIndex, uint8_t mode, const Rect &bounds)
    : ControlPane(8, bounds),
      m_recordIndex(recordIndex),
      m_key(key),
      m_mode(mode)
{
    SetSelectable(true);
}
```

CPP-9 for `NewMacroEditControlPaneSetRecordIndex`:

```cpp
void NewMacroEditControlPane::SetRecordIndex(int recordIndex)
{
    m_recordIndex = recordIndex;
}
```

CPP-10 for `NewMacroEditControlPaneSetKey`:

```cpp
void NewMacroEditControlPane::SetKey(uint16_t key)
{
    m_key = key;
}
```

CPP-11 for `NewMacroEditControlPaneSetMode`:

```cpp
void NewMacroEditControlPane::SetMode(uint8_t mode)
{
    m_mode = mode;
}
```

CPP-12 for `NewMacroEditControlPaneRefresh`:

```cpp
void NewMacroEditControlPane::Refresh()
{
    RequestParentRefresh();
}
```

CPP-13 for `NewMacroEditControlPaneOnPaint`:

```cpp
void NewMacroEditControlPane::OnPaint()
{
    const Rect row = GetClientRect();
    BeginMacroRowPaint();

    const uint16_t normalizedKey = NormalizeSpellKey(m_key);
    const wchar_t *entryName = nullptr;
    if (m_mode != 0)
        entryName = g_spellRecords[normalizedKey].displayName;
    else
        entryName = GetLocalInventorySlot(normalizedKey)->displayName;

    const int centerY = (row.Height() + row.top + 12) / 2;
    if (m_recordIndex >= 10)
        DrawMacroRowText(row.left, centerY, FormatShortcutNumber(L"Ctrl+%d", m_recordIndex == 19 ? 0 : m_recordIndex - 9));
    else
        DrawMacroRowText(row.left + 18, centerY, FormatShortcutNumber(L"%d", m_recordIndex == 9 ? 0 : m_recordIndex + 1));

    DrawMacroRowText(row.left + 48, centerY, m_mode != 0 ? L"Spell" : L"Item");
    DrawMacroRowText(row.left + 90, centerY, entryName);

    if (IsFocused())
        DrawMacroRowFocus(row);
}
```

CPP-14 for `NewMacroEditControlPaneOnKeyEvent`:

```cpp
bool NewMacroEditControlPane::OnKeyEvent(const KeyEvent &event)
{
    if (event.type == KeyEvent::KeyDown)
    {
        const int activeChild = g_pGeneralPurposePanel->GetActiveChildIndex();
        if (activeChild == 2 || activeChild == 3)
        {
            const uint8_t key = NarrowKey(event);
            if (!IsAsciiLetter(key))
                return false;

            m_key = key;
            m_mode = (activeChild == 3);
            RequestParentRefresh();
        }
    }
    else if (event.type != KeyEvent::KeyUp)
    {
        return false;
    }

    return true;
}
```

CPP-15 for `NewMacroEditControlPaneIsSelectable`:

```cpp
bool NewMacroEditControlPane::IsSelectable() const
{
    return true;
}
```

CPP-16 for `IntegrateMacroEditControlPaneConstructor`:

```cpp
IntegrateMacroEditControlPane::IntegrateMacroEditControlPane(MacroHotkeyRecord *record, const Rect &bounds)
    : ControlPane(8, bounds),
      m_macroData(record),
      m_editActive(false),
      m_textEdit(nullptr),
      m_savedTextEditState(0)
{
    SetSelectable(true);

    Rect editBounds = bounds;
    editBounds.right -= 50;
    editBounds.bottom -= 30;
    editBounds.Offset(50 - editBounds.left, 4 - editBounds.top);

    m_textEdit = new TextEditControlPane(editBounds, 0x80, 0x8f, true);
    m_textEdit->SetMaximumLength(1024);
    m_textEdit->SetSingleLine(true);
    m_textEdit->SetBounds(editBounds);
    m_textEdit->SetVisible(true);
    m_textEdit->SetEditable(false);
    m_savedTextEditState = m_textEdit->GetStateByte();

    if (m_macroData->state == MacroHotkeyRecord::Text)
        m_textEdit->SetText(m_macroData->text, false);
}
```

CPP-17 for `IntegrateMacroEditControlPaneNonDeletingDestructor`:

```cpp
IntegrateMacroEditControlPane::~IntegrateMacroEditControlPane()
{
    if (m_textEdit != nullptr)
    {
        delete m_textEdit;
        m_textEdit = nullptr;
    }
}
```

CPP-18 for `IntegrateMacroEditControlPaneIsTextEditActive`:

```cpp
bool IntegrateMacroEditControlPane::IsTextEditActive() const
{
    return m_macroData->state == MacroHotkeyRecord::Text && m_editActive;
}
```

CPP-19 for `IntegrateMacroEditControlPaneSetMacroData`:

```cpp
void IntegrateMacroEditControlPane::SetMacroData(MacroHotkeyRecord *record)
{
    m_macroData = record;
    m_textEdit->ClearText();

    if (m_macroData->state == MacroHotkeyRecord::Text)
        m_textEdit->SetText(m_macroData->text, false);
}
```

CPP-20 for `IntegrateMacroEditControlPaneRefreshDisplay`:

```cpp
void IntegrateMacroEditControlPane::RefreshDisplay()
{
    RequestParentRefresh();
}
```

CPP-21 for `IntegrateMacroEditControlPaneOnPaint`:

```cpp
void IntegrateMacroEditControlPane::OnPaint()
{
    const Rect row = GetClientRect();
    BeginMacroRowPaint();

    const int centerY = (row.Height() + row.top + 12) / 2;
    const uint16_t key = m_macroData->key;

    if (key >= 20)
        DrawMacroRowText(row.left + 4, centerY, FormatShortcutNumber(L"Alt+%d", key == 29 ? 0 : key - 19));
    else if (key >= 10)
        DrawMacroRowText(row.left, centerY, FormatShortcutNumber(L"Ctrl+%d", key == 19 ? 0 : key - 9));
    else
        DrawMacroRowText(row.left + 18, centerY, FormatShortcutNumber(L"%d", key == 9 ? 0 : key + 1));

    DrawMacroRowText(row.left + 40, centerY, MacroHotkeyStateName(m_macroData->state));
    DrawMacroRowText(row.left + 50, centerY, DescribeMacroHotkeyRecord(*m_macroData, !m_editActive));

    if (IsFocused())
        DrawMacroRowFocus(row);
}
```

CPP-22 for `IntegrateMacroEditControlPaneOnKeyEvent`:

```cpp
bool IntegrateMacroEditControlPane::OnKeyEvent(const KeyEvent &event)
{
    if (m_editActive && !m_pendingTextEditForward)
        return m_textEdit->ForwardKeyEvent(event);

    if (m_pendingTextEditForward)
        m_pendingTextEditForward = false;

    if (event.type != KeyEvent::KeyDown)
        return event.type == KeyEvent::KeyUp;

    const uint8_t key = NarrowKey(event);
    if (key == ';')
    {
        m_pendingTextEditForward = true;
        m_macroData->state = MacroHotkeyRecord::Text;
        EnterTextEditMode();
        RequestParentRefresh();
        return true;
    }

    const int activeChild = g_pGeneralPurposePanel->GetActiveChildIndex();
    if (activeChild == 2 || activeChild == 3)
    {
        if (!IsAsciiLetter(key))
            return false;

        m_textEdit->ClearText();
        m_macroData->key = key;
        m_macroData->terminator = 0;
        m_macroData->state = (activeChild == 3) ? MacroHotkeyRecord::Spell : MacroHotkeyRecord::Item;
        RequestParentRefresh();
    }

    return true;
}
```

CPP-23 for `IntegrateMacroEditControlPaneForwardMouseEvent`:

```cpp
bool IntegrateMacroEditControlPane::ForwardMouseEvent(const MouseEvent &event)
{
    if (m_editActive)
        return m_textEdit->ForwardMouseEvent(event);

    return true;
}
```

CPP-24 for `IntegrateMacroEditControlPaneForwardFocusEvent`:

```cpp
bool IntegrateMacroEditControlPane::ForwardFocusEvent(const FocusEvent &event)
{
    if (m_editActive)
        return m_textEdit->ForwardFocusEvent(event);

    return true;
}
```

CPP-25 for `IntegrateMacroEditControlPaneEnterTextEditMode`:

```cpp
void IntegrateMacroEditControlPane::EnterTextEditMode()
{
    if (m_editActive)
        return;

    m_editActive = true;
    if (m_textEdit != nullptr)
    {
        m_textEdit->SetStateByte(m_savedTextEditState);
        m_textEdit->SetVisibleAndEnabled(true, true);
        m_textEdit->SelectText(0, 0x7fff);
    }
}
```

CPP-26 for `IntegrateMacroEditControlPaneLeaveTextEditMode`:

```cpp
void IntegrateMacroEditControlPane::LeaveTextEditMode()
{
    if (!m_editActive)
        return;

    m_editActive = false;
    if (m_textEdit != nullptr)
    {
        m_textEdit->SetStateByte(4);
        m_textEdit->SetVisibleAndEnabled(false, false);
    }
}
```

CPP-27 for `IntegrateMacroEditControlPaneOnAttachToParent`:

```cpp
void IntegrateMacroEditControlPane::OnAttachToParent(const Rect &bounds, int zOrder, int flags, Pane *parent)
{
    ControlPane::OnAttachToParent(bounds, zOrder, flags, parent);

    if (m_textEdit != nullptr)
    {
        Rect editBounds;
        m_textEdit->GetBounds(editBounds);
        m_textEdit->OnAttachToParent(editBounds, 0, this, parent);
    }
}
```

CPP-28 for `IntegrateMacroEditControlPaneOnHide`:

```cpp
void IntegrateMacroEditControlPane::OnHide()
{
    if (m_textEdit != nullptr)
        m_textEdit->OnHide();

    ControlPane::OnHide();
}
```

CPP-29 for `IntegrateMacroEditControlPaneSyncEditControl`:

```cpp
void IntegrateMacroEditControlPane::SyncEditControl()
{
    if (m_macroData->state == MacroHotkeyRecord::Text && m_textEdit != nullptr)
    {
        if (m_editActive)
            LeaveTextEditMode();

        m_textEdit->CopyTextTo(m_macroData->text, 64);
    }

    Activate(false);
}
```

## Exact No-Code Markers

Use these exact no-code dispositions for compiler-generated children:

- [UID:0001IL] `SpellMacroEditControlPaneTeardownHelper`: keep `COMPLETION:88`, `CONFIDENCE:92`, `CANONICAL_OWNER:0000DQ`, `RECONSTRUCTABLE:FALSE`, blank `EMITTER_UIDS`, blank formal C++. Marker: compiler-retained complete-object destructor artifact; no source-owned cleanup statement; covered by `SpellMacroEditControlPane` class destructor semantics and scalar deleting destructor/vtable layout evidence.
- [UID:0001IM] `NewMacroEditControlPaneTeardownHelper`: change to `COMPLETION:88`, `CONFIDENCE:92`, `CANONICAL_OWNER:000095`, `RECONSTRUCTABLE:FALSE`, blank `EMITTER_UIDS`, blank formal C++. Marker: same-shape compiler-retained complete-object destructor artifact as [UID:0001IL]; no direct xrefs, only vtable restore and `Pane::~Pane()` tail transfer; no source-owned cleanup statement.
- [UID:0001IN] `MacroEditControlPaneVtableThunks`: keep non-reconstructable/no-emitter; update stale timeout wording with current MCP proof. Marker: compiler vtable thunk/adjustor run; no source C++.
- New `IntegrateMacroEditControlPaneScalarDeletingDestructor`: `COMPLETION:88`, `CONFIDENCE:92`, `CANONICAL_OWNER:00006M`, `RECONSTRUCTABLE:FALSE`, blank `EMITTER_UIDS`, blank formal C++. Marker: compiler ABI scalar deleting wrapper; source destructor behavior is CPP-17.
- New `NewMacroEditControlPaneScalarDeletingDestructor`: `COMPLETION:88`, `CONFIDENCE:92`, `CANONICAL_OWNER:000095`, `RECONSTRUCTABLE:FALSE`, blank `EMITTER_UIDS`, blank formal C++. Marker: compiler ABI scalar deleting wrapper; no standalone source body.
- New `SpellMacroEditControlPaneScalarDeletingDestructor`: `COMPLETION:88`, `CONFIDENCE:92`, `CANONICAL_OWNER:0000DQ`, `RECONSTRUCTABLE:FALSE`, blank `EMITTER_UIDS`, blank formal C++. Marker: compiler ABI scalar deleting wrapper; no standalone source body.

## Rejected Alternatives

- Keep [UID:0001IK] reconstructable/emitting with blank C++: rejected because this is the current empty-emitter defect.
- Put broad aggregate C++ on [UID:0001IK]: rejected because the range spans three classes plus compiler artifacts, unmodeled helper bodies, and padding. A broad block would conflate method ownership and duplicate child source.
- Put `[[CHILDREN]]` on [UID:0001IK]: rejected because the parent is not a class declaration or stable source insertion point. Exact method children should route through their class owners.
- Mark the entire parent as covered-by/no-code: rejected because most of the range is source-authored class methods with reconstructable bodies.
- Leave [UID:0001IM] as `RECONSTRUCTABLE:TRUE` with `EMITTER_UIDS:0000KY` and blank C++: rejected. Current MCP evidence confirms the same no-route vtable-restore/base-tail artifact pattern accepted for [UID:0001IL].
- Fold `0x0057ff00` into a no-code destructor artifact: rejected because it owns source destructor semantics for deleting the embedded text-edit child. It needs a source-bearing `~IntegrateMacroEditControlPane` child.
- Ignore raw unmodeled bodies at `0x0057ff40`, `0x005804c0`, and `0x00580510`: rejected because MCP proves real instruction bodies inside the parent. They should become exact source-bearing children with no-xref caveats, not invisible padding.

## Support Doc Updates Required After Supervisor Callback

Primary support docs:

- [UID:0000KY] `by-file/MacroDialogs.md`: add the exact UID0001IK split table, mention raw helper discovery, distinguish source-bearing row-control methods from compiler/no-code destructor wrappers, and link [UID:0001IM] reclassification. Also historicalize stale source/generator wording: rewrite `Current recovered sources` as old generated source leads only; rewrite `Wave3 reports high effective grades` as old generated grading lead material, not current evidence; rewrite `Current simroot_v2 metadata` and `not modeled consistently by Wave3` wording as stale generated-output limitations backed by [UID:0001Y1], [UID:0003DB], by-* docs, and MCP.
- [UID:0000DQ] `by-class/SpellMacroEditControlPane.md`: link the new Spell method children, keep [UID:0001IL] as no-code destructor glue, add the Spell scalar deleting destructor no-code child, and preserve B010 `GetSpellKey` consumer evidence. Also historicalize `Current recovered file: source-3/simroot_v2/class_SpellMacroEditControlPane.cpp` as a stale generated source lead only, and rewrite disabled generated-output/simroot thunk wording as stale generated-output limitation with current [UID:0001IN]/MCP evidence as authority.
- [UID:000095] `by-class/NewMacroEditControlPane.md`: link the New method children, map `GetKey`/`GetMode`/setters to B010 NewMacroDialog usage, reclassify [UID:0001IM] as no-code compiler glue, and add the New scalar deleting destructor no-code child. Also historicalize `Current recovered file: source-3/simroot_v2/class_NewMacroEditControlPane.cpp` as a stale generated source lead only, and rewrite disabled generated-output/simroot thunk wording as stale generated-output limitation with current [UID:0001IN]/MCP evidence as authority.
- [UID:00006M] `by-class/IntegrateMacroEditControlPane.md`: replace the broad method-map range with exact children, add raw non-modeled destructor/predicate/enter/leave helpers, and record source destructor ownership of `m_textEdit`. Also historicalize `Current recovered file: source-3/simroot_v2/class_IntegrateMacroEditControlPane.cpp` as a stale generated source lead only, and rewrite disabled generated-output thunk wording as stale generated-output limitation if this page is edited for child links.

Secondary support docs to verify or update after child UIDs exist:

- [UID:0001Y1] `by-type/by-vtable/MacroDialogFamilyVtables.md`: update slot names to point at new child UIDs and keep thunk/scalar wrapper children no-code. Historicalize active `Current simroot_v2 metadata still reports vtable_count: 0` wording as stale simroot metadata caveat; current authority is this page's by-* vtable inventory, [UID:0003DB], and MCP-backed slot/xref evidence.
- [UID:0003DB] `by-memory/0x0062d1e0-0x0062d3cc.MacroEditControlPaneVtableData.md`: add child UID references for source methods and no-code wrappers.
- [UID:0001IN] `by-memory/0x00580640-0x00580686.MacroEditControlPaneVtableThunks.md`: if edited for stale timeout wording, historicalize the bare `[Wave3 data issue]` cross-reference as a generated-data issue link, not source authority. If UID0001IN is not otherwise edited, explicitly exclude this link from callback cleanup because it is not active source evidence.
- `by-memory/-ignored.md`: add internal padding spans if current validator/reporting standard requires padding to live outside the parent evidence table.

Do not edit generated files, manual coverage reports, validator/tool state, or IDA DB in the implementation callback. Do not run `execute_report`; supervisor owns report execution.

## Implementation Tracking Checklist

Implementation callback status:

- [x] Supervisor accepted this report for implementation callback; by-* edits were limited to the accepted target/support scope and new child pages.
- [x] Implementation proof recorded: by-* docs were edited only within accepted scope, no generated/project/manual coverage/tool-state/IDA files were manually edited, validators were run as scoped proof, no `execute_report` was run, and no subagents were spawned.
- [x] MCP proof recorded: original report evidence came from `supervisor_20260628_resume`; revision spot-check came from live current session `07c55da0` on 2026-06-29, so this is not a fallback-only report.
- [x] Claim And Incorporation Ledger C001-C036 reviewed by supervisor and either accepted, rejected, or narrowed before callback.
- [x] During callback only, acquire short leases for the immediate edit batch, starting with existing parent/support files: [UID:0001IK], [UID:0000KY], [UID:0000DQ], [UID:000095], [UID:00006M], [UID:0001Y1], [UID:0003DB], [UID:0001IN] if stale wording is touched, and `by-memory/-ignored.md` only if padding ledger entries are accepted. No lease is needed for report-only work or new child files before they exist.
- [x] Phase 1 child creation, Spell rows: create and validate the new Spell child pages in address order so validator assigns UIDs before support links: `0x0057f750-0x0057f758.SpellMacroEditControlPaneGetSpellKey.md` with CPP-1; `0x0057f760-0x0057f7a9.SpellMacroEditControlPaneConstructor.md` with CPP-2; `0x0057f7d0-0x0057f927.SpellMacroEditControlPaneOnPaint.md` with CPP-3; `0x0057f930-0x0057f998.SpellMacroEditControlPaneOnKeyEvent.md` with CPP-4; `0x0057f9a0-0x0057f9a5.SpellMacroEditControlPaneIsSelectable.md` with CPP-5; `0x00580770-0x005807c5.SpellMacroEditControlPaneScalarDeletingDestructor.md` as no-code compiler ABI wrapper.
- [x] Phase 2 child creation, New rows: create and validate in address order `0x0057f9b0-0x0057f9b8.NewMacroEditControlPaneGetKey.md` CPP-6; `0x0057f9c0-0x0057f9c7.NewMacroEditControlPaneGetMode.md` CPP-7; `0x0057f9d0-0x0057fa2b.NewMacroEditControlPaneConstructor.md` CPP-8; `0x0057fa30-0x0057fa40.NewMacroEditControlPaneSetRecordIndex.md` CPP-9; `0x0057fa40-0x0057fa52.NewMacroEditControlPaneSetKey.md` CPP-10; `0x0057fa60-0x0057fa70.NewMacroEditControlPaneSetMode.md` CPP-11; `0x0057fa70-0x0057fa7a.NewMacroEditControlPaneRefresh.md` CPP-12; `0x0057faa0-0x0057fc76.NewMacroEditControlPaneOnPaint.md` CPP-13; `0x0057fc80-0x0057fcff.NewMacroEditControlPaneOnKeyEvent.md` CPP-14; `0x0057fd00-0x0057fd05.NewMacroEditControlPaneIsSelectable.md` CPP-15; `0x00580710-0x00580765.NewMacroEditControlPaneScalarDeletingDestructor.md` as no-code compiler ABI wrapper.
- [x] Phase 3 child creation, Integrate rows: create and validate in address order `0x0057fd10-0x0057fefc.IntegrateMacroEditControlPaneConstructor.md` CPP-16; `0x0057ff00-0x0057ff3f.IntegrateMacroEditControlPaneNonDeletingDestructor.md` CPP-17; `0x0057ff40-0x0057ff5b.IntegrateMacroEditControlPaneIsTextEditActive.md` CPP-18 with no-xref caveat; `0x0057ff60-0x0057ff9c.IntegrateMacroEditControlPaneSetMacroData.md` CPP-19; `0x0057ffa0-0x0057ffaa.IntegrateMacroEditControlPaneRefreshDisplay.md` CPP-20; `0x0057ffb0-0x00580313.IntegrateMacroEditControlPaneOnPaint.md` CPP-21; `0x00580320-0x0058045d.IntegrateMacroEditControlPaneOnKeyEvent.md` CPP-22; `0x00580460-0x00580484.IntegrateMacroEditControlPaneForwardMouseEvent.md` CPP-23; `0x00580490-0x005804b4.IntegrateMacroEditControlPaneForwardFocusEvent.md` CPP-24; `0x005804c0-0x0058050d.IntegrateMacroEditControlPaneEnterTextEditMode.md` CPP-25 with no-xref caveat; `0x00580510-0x00580545.IntegrateMacroEditControlPaneLeaveTextEditMode.md` CPP-26 with no-xref caveat; `0x00580550-0x005805b3.IntegrateMacroEditControlPaneOnAttachToParent.md` CPP-27; `0x005805c0-0x005805da.IntegrateMacroEditControlPaneOnHide.md` CPP-28; `0x005805e0-0x0058063e.IntegrateMacroEditControlPaneSyncEditControl.md` CPP-29; `0x00580690-0x00580701.IntegrateMacroEditControlPaneScalarDeletingDestructor.md` as no-code compiler ABI wrapper whose source destructor semantics are CPP-17.
- [x] Existing child verification: keep [UID:0001IL] already-present no-code state; keep [UID:0001IM] already-present no-code state; keep [UID:0001IN] no-code thunk state and update only stale MCP-timeout wording if this callback leases it.
- [x] Parent conversion after child UIDs exist: update [UID:0001IK] to `COMPLETION:90`, `CONFIDENCE:91`, `CANONICAL_OWNER:0000KY`, `RECONSTRUCTABLE:FALSE`, blank `EMITTER_UIDS`, blank `EMITTER_POSITION_OPTIONAL`, blank formal C++, an exact child/source-route inventory, current MCP spot-check facts, boundary exclusions, and padding inventory. Historical [UID:0001IM] empty-marker language must be marked stale/superseded rather than copied forward as current state.
- [x] Support update after child UIDs exist: update [UID:0000KY] `by-file/MacroDialogs.md` with the UID0001IK split table, raw helper discovery, row-control source route, compiler/no-code destructor/thunk distinction, and generated-output expectation.
- [x] Stale-source cleanup in [UID:0000KY] `by-file/MacroDialogs.md`: rewrite Status `Current recovered sources` as historical generated source leads only; rewrite Evidence `Wave3 reports high effective grades` as old generated grading lead material; rewrite Evidence `Current simroot_v2 metadata still reports vtable_count: 0` as stale simroot metadata caveat; rewrite Caveats `not modeled consistently by Wave3` / generated control files wording as stale generated-output limitation. Do not leave these phrases as active current authority.
- [x] Support update after child UIDs exist: update [UID:0000DQ] `by-class/SpellMacroEditControlPane.md` with new Spell method/scalar-destructor child UIDs, keep [UID:0001IL] no-code complete-object destructor glue, and preserve `GetSpellKey` caller/storage evidence.
- [x] Stale-source cleanup in [UID:0000DQ] `by-class/SpellMacroEditControlPane.md`: historicalize `Current recovered file: source-3/simroot_v2/class_SpellMacroEditControlPane.cpp` as stale generated source lead only; rewrite disabled generated-output/simroot thunk wording as stale generated-output limitation with [UID:0001IN]/MCP evidence as authority.
- [x] Support update after child UIDs exist: update [UID:000095] `by-class/NewMacroEditControlPane.md` with new New method/scalar-destructor child UIDs, preserve [UID:0001IM] no-code complete-object destructor glue, and map accepted source-facing getter/setter names to compact-record save/load usage.
- [x] Stale-source cleanup in [UID:000095] `by-class/NewMacroEditControlPane.md`: historicalize `Current recovered file: source-3/simroot_v2/class_NewMacroEditControlPane.cpp` as stale generated source lead only; rewrite disabled generated-output/simroot thunk wording as stale generated-output limitation with [UID:0001IN]/MCP evidence as authority.
- [x] Support update after child UIDs exist: update [UID:00006M] `by-class/IntegrateMacroEditControlPane.md` with exact constructor/raw helper/method/scalar-destructor child UIDs, field offsets `+0x108`, `+0x10d`, `+0x110`, raw enter/leave helper caveats, and source destructor ownership of `m_textEdit`.
- [x] Stale-source cleanup in [UID:00006M] `by-class/IntegrateMacroEditControlPane.md`: historicalize `Current recovered file: source-3/simroot_v2/class_IntegrateMacroEditControlPane.cpp` as stale generated source lead only; rewrite disabled generated-output thunk wording as stale generated-output limitation if this page is edited for child links.
- [x] Secondary support update after child UIDs exist: update [UID:0001Y1] `by-type/by-vtable/MacroDialogFamilyVtables.md` slot rows to point at new child UIDs for source methods and no-code wrappers while preserving compiler-generated vtable/thunk handling.
- [x] Stale-source cleanup in [UID:0001Y1] `by-type/by-vtable/MacroDialogFamilyVtables.md`: historicalize `Current simroot_v2 metadata still reports vtable_count: 0` as stale simroot metadata caveat, preserving the warning that generated metadata was incomplete while citing [UID:0001Y1], [UID:0003DB], and MCP-backed slot/xref evidence as current authority.
- [x] Secondary support update after child UIDs exist: update [UID:0003DB] `by-memory/0x0062d1e0-0x0062d3cc.MacroEditControlPaneVtableData.md` to reference new method/scalar-wrapper child UIDs where useful; preserve the accepted comment-only covered-by marker and raw-vtable-array rejection.
- [x] Conditional stale-source cleanup in [UID:0001IN] `by-memory/0x00580640-0x00580686.MacroEditControlPaneVtableThunks.md`: if the file is edited for stale timeout wording, historicalize the bare `[Wave3 data issue]` cross-reference as a generated-data issue link, not source authority; if UID0001IN is not edited, mark this ledger item excluded because the link is not active source evidence and does not justify a standalone edit.
- [x] Padding ledger: if supervisor accepts editing `by-memory/-ignored.md`, add exact internal `0xcc` padding spans from this report with evidence and replacement child/container context; otherwise keep padding only in [UID:0001IK] and record the ledger item as explicitly excluded.
- [x] Validators, child-first: run `python .\tools\validator.py --mode file --file <new-child-path> --apply --queue-timeout 240` for each newly created child page before writing UID references into parent/support docs. Record each command, `command_id`, `command_timestamp`, exit code, and `ok` count in the callback checklist.
- [x] Validators, parent/support: after all child UIDs are assigned and parent/support links are updated, validate [UID:0001IK], [UID:0000KY], [UID:0000DQ], [UID:000095], [UID:00006M], [UID:0001Y1], [UID:0003DB], [UID:0001IN] if edited, and `by-memory/-ignored.md` if edited with scoped file validators and `--queue-timeout 240`.
- [x] Generated-output check: after scoped validators, read generated `auto-generated/NexusTK/ui/dialogs/MacroDialogs.cpp` without editing it. Verify UID0001IK no longer appears as an empty emitter after the validator command whose generated refresh is equal/newer than the last relevant scoped validator. UID0001IM should remain absent from empty markers. Existing class-level empty markers [UID:00006M], [UID:000095], and [UID:0000DQ] are out of scope unless the accepted child/class changes remove them naturally.
- [x] Generated coverage/tracker check: read-only check `auto-generated/-ag-coverage-report-by-memory.md` and `auto-generated/-ag-research-tracker.md` after validation only to confirm generated refresh state and newly assigned UIDs; do not manually edit generated reports. If refresh is deferred, use validator queue status/freshness checks rather than hand-editing.
- [x] Claim And Incorporation Ledger callback update: update every accepted C001-C036 row to `applied`, `already-present`, `excluded-with-reason`, or `blocked` with destination proof.
- [x] Release all B001 leases immediately after the edit/validator batch; report lease acquisition/release state and any expired lease cleanup state in the callback result.
- [x] Do not run `execute_report`; supervisor runs `python .\tools\validator.py execute_report B001 0001IK-MacroEditControlPanes-empty-emitter-source-quality.md 0001IK --apply` only after independent validation.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B001","command_id":"000000004165","destination_path":"executed-b-agent-research/B001/0001IK-MacroEditControlPanes-empty-emitter-source-quality.md","details":"legacy registry reconstruction","event":"executed","source_path":"tools/leaser/Agents/Agent-B001/research/0001IK-MacroEditControlPanes-empty-emitter-source-quality.md","timestamp":"2026-06-29T02:14:57","uid":"0001IK"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
