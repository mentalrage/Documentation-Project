** TARGET-REPORT-UID:00015X **
** AUTHOR-AGENT-ID:B005 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **

# B-Agent Source-Quality Report: [UID:00015X] GeneralPurposePanelSwitchActiveTab

## Finalized Report / Current Recommendation

Keep [UID:00015X] `by-memory/0x004b8650-0x004b8822.GeneralPurposePanelSwitchActiveTab.md` owned by [UID:00005Q] `GeneralPurposePanel`, emitted through [UID:0000JQ] `NexusTK/ui/panels/GeneralPurposePanel.cpp`.

Recommended metadata:

```text
COMPLETION:88
CONFIDENCE:93
CANONICAL_OWNER:00005Q
RECONSTRUCTABLE:TRUE
EMITTER_UIDS:00005Q
```

Do not populate the formal `RECONSTRUCTION_CPP` block in this target yet. This is a narrow target-specific no-code recommendation, not a fallback-only deferral: current MCP resolves the owner, boundary, core control flow, fields, callers, rectangles, and dependency ownership. The remaining source-blocking gap is exact source spelling/declaration shape for inherited pane virtual slot `+0x48` and the inherited slot `+0x0c` inside helper `0x00544ee0`; emitting a first draft now would require inventing method names or helper wrappers that the current Pane/PanelPane docs do not yet support.

## Supporting Research

Lifecycle/status context for this artifact: this is the active B005 research report at `tools/leaser/Agents/Agent-B005/research/00015X-GeneralPurposePanelSwitchActiveTab-source-quality.md`, repaired in place at the same path and then used for the supervisor-authorized implementation callback. Historical repair context only: SHA256 `17374E39773407AE917144C33C29DDD1B50460C13FA58DD035ED124F11EF34AA` failed Gate 1 for missing exact target/current-state headings, an invalid ledger, non-insertion C++ text, checklist looseness, and unresolved score-blocker phrasing; SHA256 `50504A96DC59187FDFED4898D983B31E77A4A675D4113E997845E1457AF31F7C` then failed narrowly because this `Supporting Research` heading had no standalone body. Gate 1 passed for SHA256 `2F5CD02DB981FDB8C06F350004D6BBAA742032636183A732E56FFC663E8F3A22`; this current report revision records the post-Gate 1 callback outcome. The artifact is not executed, archived, lifecycle-cleared, or manually moved.

Instruction and workflow sources for the report and callback: current B005 goal at `tools/leaser/Agents/Agent-B005/goal.md`; project skill `ntk-b-agent-workflow`; `references/b-agent-research-and-implementation-workflow.md`; `references/b-agent-report-template.md`; `references/score-blocker-audit-standard.md`; and the current supervisor Gate 1 pass plus implementation callback instructions. These sources require literal report headings with content under each heading, report-only boundaries before supervisor callback, exact ledger/checklist traceability, lease discipline for by-* edits, scoped validators for changed by-* files, and formal C++ insertion text only when exact source-quality code is supportable.

Research context used by the report: the target [UID:00015X] `by-memory/0x004b8650-0x004b8822.GeneralPurposePanelSwitchActiveTab.md`; queue row `auto-generated/-ag-research-tracker.md` -> `## by-memory` -> `### Not-Covered Files - Reconstructable`; GeneralPurposePanel file/class/aggregate/accessor docs; PaneCore, PaneVtables, PanelPaneVtables, RectBounds, BlackHole, TotemFrame, FrameChrome, AboveFrame refresh, InterfaceEfx, g_pBackPane, MainUiLayerSlots, MapPane, LivingObjectPane, SpellInputPanes, and SpellOneArgInputPane support docs; generated `auto-generated/NexusTK/ui/panels/GeneralPurposePanel.cpp` and `auto-generated/NexusTK/ui/dialogs/SpellInputPanes.cpp`; and old-report/search context by UID, address, target name, and source family. Generated output and old reports are treated as leads, while current by-* docs and IDA evidence drive the recommendation.

Active MCP evidence context captured by the report: JSON-RPC endpoint `http://127.0.0.1:13337/mcp`, selected database/session `b007_uid0002oc_20260708`, module `NexusTK.exe`, imagebase `0x400000`, `server_health: ok`, auto-analysis ready, and Hex-Rays ready. The report's IDA evidence comes from read-only `idb_list`, `server_health`, `lookup_funcs`, `get_bytes`, `callees`, `xref_query`, `decompile`, and `analyze_function` calls already recorded in the body. The implementation callback did not run MCP/IDA/Python management commands, did not call `idb_open`, and did not add or mutate MCP evidence.

Boundary for this artifact: during Gate 1 repair, B005 edited only this report in its own `research/` folder. During the supervisor-authorized implementation callback, B005 edited only the accepted leased by-* docs needed for the immediate batch plus this report: UID00015X target, PaneCore support, GeneralPurposePanel file support, and GeneralPurposePanel class support. PaneVtables, SpellInputPanes, and SpellOneArgInputPane were inspected read-only and were not edited because their relevant facts were already present. B005 did not manually edit generated files, coverage reports, supervisor ledgers, validator state, queues, locks, archives, lifecycle headers/footers, or IDA DB state. No `execute_report`, dry-run/probing execute variants, lifecycle/archive commands, manual report moves, `idb_open`, or MCP/IDA/Python management commands were run.

## Target

- Target UID: [UID:00015X].
- Target path: `by-memory/0x004b8650-0x004b8822.GeneralPurposePanelSwitchActiveTab.md`.
- Expected report path: `tools/leaser/Agents/Agent-B005/research/00015X-GeneralPurposePanelSwitchActiveTab-source-quality.md`.
- Queue/source row context: `auto-generated/-ag-research-tracker.md` -> `## by-memory` -> `### Not-Covered Files - Reconstructable`; the Gate 1 source row was `[UID:00015X] 0x004b8650-0x004b8822.GeneralPurposePanelSwitchActiveTab | 85/91 | owner 00005Q | reconstructable TRUE | emitter 00005Q`. The callback updates target metadata to `88/93`; generated tracker/coverage files are not manually edited.
- Current classification: source-authored `GeneralPurposePanel` class method / side-panel active-tab switcher, source-quality research report with accepted implementation callback applied.
- Current scores/metadata after callback: `COMPLETION:88`, `CONFIDENCE:93`, `CANONICAL_OWNER:00005Q`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:00005Q`, formal `RECONSTRUCTION_CPP` blank.
- Source route: [UID:00005Q] `GeneralPurposePanel` -> [UID:0000JQ] `GeneralPurposePanel` file -> `auto-generated/NexusTK/ui/panels/GeneralPurposePanel.cpp`.
- Parent/emitter state: parent class [UID:00005Q] is the accepted canonical owner and emitter owner; the generated class shell is present in `GeneralPurposePanel.cpp`, refreshed by validator command `000000007832` at `2026-07-07T03:37:36-04:00`; UID00015X remains an empty emitter marker because no formal C++ body is currently source-quality.

## Current Target State

The target currently records:

```text
COMPLETION:88
CONFIDENCE:93
CANONICAL_OWNER:00005Q
RECONSTRUCTABLE:TRUE
EMITTER_UIDS:00005Q
RECONSTRUCTION_CPP: blank
```

Owner/emitter/reconstructable state is consistent across the target, class, file, and generated artifact: [UID:00005Q] owns the method, [UID:0000JQ] emits through `NexusTK/ui/panels/GeneralPurposePanel.cpp`, and the row remains reconstructable/source-authored. The current page already contains correct direction for the broad side-panel helper, stale `SpellOneArgInputPane` generated ownership rejection, EPF/new-layout versus legacy tab limits, `m_childPanes[7]`, `m_activeChildIndex`, FrameChrome/InterfaceEfx dependency boundaries, and LivingObjectPane packet caller evidence.

Current C++/empty-emitter state: generated `GeneralPurposePanel.cpp` is fresh and still leaves UID00015X as an empty emitter marker. The report recommends keeping the formal target `RECONSTRUCTION_CPP` block blank because the remaining unresolved names are inherited/source-facing API names, not missing control-flow understanding.

Open blockers for formal C++ are narrow and target-specific: exact source spelling/declaration for helper `0x00544ee0`, the helper's inherited slot `+0x0c`, and UID00015X's new-child inherited slot `+0x48`. These blockers remain after checking the current IDA MCP decompile/analyze/xref data and the current PaneCore, PaneVtables, PanelPaneVtables, GeneralPurposePanel, RectBounds, FrameChrome, InterfaceEfx, MainUiLayerSlots, SpellInputPanes, generated output, and old report evidence. They block only exact insertion text, not the owner, boundary, behavior, dependency ownership, or score movement.

Current related docs checked: target [UID:00015X]; [UID:0000JQ] `GeneralPurposePanel` file; [UID:00005Q] `GeneralPurposePanel` class; [UID:00015W] child accessors; [UID:00015V] aggregate; [UID:0001EA] `PaneCore`; [UID:0003JA] `PaneVtables`; [UID:0000R5] `PanelPaneVtables`; [UID:0000SK] `RectBoundsMethods`; [UID:00029M] `BlackHoleQueuePaneForDeferredDeletion`; [UID:0000YI] above-frame refresh helpers; [UID:0000JL] `FrameChrome`; [UID:00018H] `InterfaceEfxMgrTriggerInterfaceEffect`; [UID:0000O0]/[UID:0000DR] spell input panes; `g_pTotemFrame`, `g_pBackPane`, `MainUiLayerSlots`, MapPane and LivingObjectPane caller support; generated `GeneralPurposePanel.cpp` and `SpellInputPanes.cpp`.

Current artifact/lifecycle state: this is the same active report path repaired in place after Gate 1 failures and then updated for the accepted implementation callback. Target/support by-* edits were limited to the four leased accepted docs, and scoped validators were run only for those changed by-* files. Generated/stat side effects were validator-owned only; no generated files, coverage files, validator state, supervisor ledgers, queues, locks, archives, lifecycle headers/footers, or IDA DB state were manually edited. No `execute_report`, lifecycle/archive commands, manual report moves, or MCP/IDA/Python management commands were run.

## Heuristic / Inference Reanalysis And Validation

| Issue | Evidence checked | Rejected alternatives | Current conclusion |
| --- | --- | --- | --- |
| Exact boundary and padding | Current IDA MCP session `b007_uid0002oc_20260708`: `lookup_funcs 0x004b8650` gives `sub_4B8650`, size `0x1d3`; `0x004b8820` and `0x004b8822` resolve inside the same function; `0x004b8823` is not a function; `0x004b8830` starts `sub_4B8830`, size `0xb1`; bytes at `0x004b8820` are `c2 08 00` followed by `0xcc` padding through the next prologue. | Extending into padding; starting `GeneralPurposePanel2` early; treating `0x004b8823-0x004b8830` as a hidden helper. | Boundary remains exact: source body is `0x004b8650-0x004b8823` half-open, with final byte at filename/inclusive `0x004b8822` and padding `0x004b8823-0x004b8830`. |
| Owner and stale generated source | Target page, GeneralPurposePanel file/class docs, SpellInputPanes file/class docs, generated `SpellInputPanes.cpp`, generated `GeneralPurposePanel.cpp`, current MCP xrefs. | `SpellOneArgInputPane::SwitchActiveTab`; standalone helper; packet/input-pane ownership. | [UID:00015X] is `GeneralPurposePanel::SwitchActiveTab(int tabIndex, bool showChild)` or equivalent. Spell input panes call it as a dependency and generated spell ownership is stale pollution. |
| Child array and active index | GeneralPurposePanel class/file docs, UID00015W accessor context, current decompile: `this[a2 + 1]` child pointer access and `this[8]` active index storage/read. | Unnamed `this[8]`, FrameChrome-owned active field, spell-pane field. | Use accepted names `Pane *m_childPanes[7]` and `int m_activeChildIndex`. |
| EPF/new-layout versus legacy behavior | Current decompile and target docs. EPF path tests `g_useEpfAssets == 1` and accepts `tabIndex < 7`; legacy accepts `tabIndex < 4`. Rectangles are `(832,79,1021,367)` and `(434,12,626,300)`. | One common four-tab limit; spell-only tab switch; packet-specific behavior. | The method is a shared side-panel layout switcher with seven current/EPF tabs and four legacy tabs. |
| Redundant tab condition | Current decompile at `0x004b8684-0x004b8698` and legacy equivalent. | Blanket no-op on same tab. | Same-tab requests for tabs `2+` are skipped, while tab `0` and `1` same-index requests continue through the switch path. |
| Totem-frame cleanup | Current decompile calls `0x00544690` on `unk_69B35C`; `g_pTotemFrame` docs; PaneCore and BlackHole docs. | TotemFrame-owned switch logic; BlackHole ownership for the panel method. | UID00015X is a consumer: when `g_pTotemFrame` is non-null it calls `Pane::MarkForDeletion` on that pane. `Pane::MarkForDeletion` sets `Pane +0xf4` and queues through BlackHole. |
| Old-child hide/collapse | Current MCP `analyze_function 0x00544ee0`: only callers are `sub_4B8650` and `sub_4B89A0`; it calls primary slot `+0x38`, zeroes a 16-byte local rectangle, and calls primary slot `+0x0c` with that zero rectangle. UID00015X then calls old child slot `+0x40`. | Treating `0x00544ee0` as SpellOneArgInputPane-owned; naming it final without support; folding it into GeneralPurposePanel. | Behavior is exact enough for prose: a Pane switch-out collapse helper that detaches/removes and clears bounds/state before `Pane::UnregisterEventHandler`. Source spelling remains unresolved and belongs in PaneCore support. |
| New-child layout and attachment | Current decompile calls `RectBounds::SetLTRB`, slot `+0x2c`, slot `+0x30`, slot `+0x3c`, then slot `+0x48`. PaneVtables maps `+0x2c` as `Pane::SetBounds`, `+0x30` as `Pane::AddToLayer`, `+0x3c` as `Pane::SetPaneOrder` / dispatcher order helper; `+0x48` is not source-final in Pane/PanelPane. | Inventing final names for every inherited virtual; treating layer globals as GeneralPurposePanel fields. | Formal C++ should remain blank until `+0x48` and the `+0x0c` helper slot have accepted source-facing names. Prose may safely describe layout/attach/order/show behavior. |
| Frame refresh helpers | AboveFrameRefreshHelpers and FrameChrome docs; current `callees` returns `0x004615b0` and `0x004615d0`. | Moving FrameChrome helpers into GeneralPurposePanel; preserving false `__std_parallel_algorithms_hw_threads` label. | Use FrameChrome-owned `ReleaseDynamicAboveFrame()` and `RecreateDynamicAboveFrame()` dependency names. UID00015X only calls them after setting `m_activeChildIndex`. |
| Legacy InterfaceEfx call | UID00018H docs and current decompile `sub_4E9EE0(unk_69B360, this[8])` at `0x004b880b`. | Arbitrary resource/effect id; packet opcode id. | Legacy branch passes `m_activeChildIndex` directly to `InterfaceEfxMgr::TriggerInterfaceEffect(int effectId)`. |
| Broad caller fan-in | Current MCP `xref_query` returns 35 code refs, including MapPane dispatcher, LivingObjectPane handler, spell/item input shortcuts, user-pane paths, and macro/dialog callers. | Spell/input-pane direct ownership; single packet handler ownership. | Caller mix proves broad side-panel shell method. |

## Evidence Standards Used

- Current IDA MCP, required by assignment: initialized JSON-RPC endpoint `http://127.0.0.1:13337/mcp`; selected database session `b007_uid0002oc_20260708`; `server_health` reported `ok`, auto-analysis ready, Hex-Rays ready, module `NexusTK.exe`, imagebase `0x400000`.
- IDA MCP tools used: `idb_list`, `server_health`, `lookup_funcs`, `get_bytes`, `callees`, `xref_query`, `decompile`, `analyze_function`.
- Documentation evidence: target page; GeneralPurposePanel file/class/aggregate/accessor pages; FrameChrome, AboveFrameRefreshHelpers, FrameChromeSlots; InterfaceEfxMgrTriggerInterfaceEffect and g_pInterfaceEfxMgr; PaneCore, Pane/PanelPane vtables, RectBoundsMethods, BlackHole QueuePaneForDeferredDeletion, g_pTotemFrame, g_pBackPane, MainUiLayerSlots, MapPanePacketDispatcher, LivingObjectPaneHandleUIPanelSwitchPacket, SpellInputPanes, SpellOneArgInputPane.
- Generated-output evidence: `auto-generated/NexusTK/ui/panels/GeneralPurposePanel.cpp` and `auto-generated/NexusTK/ui/dialogs/SpellInputPanes.cpp`.
- Negative evidence: no current source symbol or support page provides exact source spelling for `0x00544ee0` or inherited slot `+0x48`; no direct evidence makes `SpellOneArgInputPane` an owner.

## Evidence Checked

Instruction and workflow files checked:

- Project-level skill `ntk-b-agent-workflow` and required B-agent workflow references.
- Agent goal: `tools/leaser/Agents/Agent-B005/goal.md`.

Target/support docs checked:

- [UID:00015X] `by-memory/0x004b8650-0x004b8822.GeneralPurposePanelSwitchActiveTab.md`.
- [UID:0000JQ] `by-file/GeneralPurposePanel.md`.
- [UID:00005Q] `by-class/GeneralPurposePanel.md`.
- [UID:00015W] `by-memory/0x004b85f0-0x004b8643.GeneralPurposePanelChildAccessors.md`.
- [UID:00015V] `by-memory/0x004b83d0-0x004b8bd3.GeneralPurposePanel.md`.
- [UID:0000YI] `by-memory/0x004615b0-0x00461658.AboveFrameRefreshHelpers.md`.
- [UID:0000JL] `by-file/FrameChrome.md`.
- [UID:0000PN] `by-global/FrameChromeSlots.md`.
- [UID:00018H] `by-memory/0x004e9ee0-0x004e9f2d.InterfaceEfxMgrTriggerInterfaceEffect.md`.
- [UID:0000R8] `by-global/g_pInterfaceEfxMgr.md`.
- [UID:0000R0] `by-global/g_pGeneralPurposePanel.md`.
- [UID:0000SK] `by-global/g_pTotemFrame.md`.
- [UID:00015Q] `by-memory/0x004b78d0-0x004b7ae8.RectBoundsMethods.md`.
- [UID:0001EA] `by-memory/0x00544460-0x00545086.PaneCore.md`.
- [UID:0003JA] `by-type/by-vtable/PaneVtables.md`.
- [UID:0001YD] `by-type/by-vtable/PanelPaneVtables.md`.
- [UID:0000Z1] `by-memory/0x00469180-0x004691fa.BlackHoleQueuePaneForDeferredDeletion.md`.
- [UID:00028J] `by-memory/0x0067a740-0x0067a744.g_pBackPane.md`.
- [UID:00029M] `by-memory/0x0069b364-0x0069b370.MainUiLayerSlotsHead.md`.
- [UID:0003UT] `by-memory/0x005abda0-0x005abee8.LivingObjectPaneHandleUIPanelSwitchPacket.md`.
- [UID:00037T] `by-memory/0x00507c90-0x00508f60.MapPanePacketDispatcher.md`.
- [UID:0000O0] `by-file/SpellInputPanes.md`.
- [UID:0000DR] `by-class/SpellOneArgInputPane.md`.

Old report search:

- Search terms included `00015X`, `0x004b8650`, `GeneralPurposePanelSwitchActiveTab`, `SwitchActiveTab`, and `SpellOneArgInputPane`.
- Directly relevant executed reports checked: B003 `00015V-GeneralPurposePanel-source-quality.md`, B004 `0003UT-LivingObjectPaneHandleUIPanelSwitchPacket-source-quality.md`, and B003 `00018H-interface-efxmgr-trigger-interface-effect-source-quality.md`.
- Additional report hits for spell/item/key handlers were used as caller-context leads only, not owner authority.

Generated output checked:

- `auto-generated/NexusTK/ui/panels/GeneralPurposePanel.cpp`: current command `000000007832`, refreshed `2026-07-07T03:37:36-04:00`; class shell includes `SwitchActiveTab(int tabIndex, bool showChild)` and `m_childPanes[7]`/`m_activeChildIndex`; UID00015X remains an empty emitter marker.
- `auto-generated/NexusTK/ui/dialogs/SpellInputPanes.cpp`: current generated spell pane code calls `g_pGeneralPurposePanel->SwitchActiveTab(3, false)` as a dependency. It no longer emits UID00015X as a spell-owned function body, but support docs preserve the stale `class_SpellOneArgInputPane.cpp` generator pollution warning.

## IDA MCP Facts

- Database: `b007_uid0002oc_20260708`.
- `server_health`: `status=ok`, `idb_path=E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, `module=NexusTK.exe`, `input_path=C:\Users\admin\Desktop\Clone\NexusTK\NexusTK.exe`, `imagebase=0x400000`, `auto_analysis_ready=true`, `hexrays_ready=true`, `strings_cache_ready=true`.
- `lookup_funcs`:
  - `0x004b8650` -> `sub_4B8650`, size `0x1d3`.
  - `0x004b8820` -> same function.
  - `0x004b8822` -> same function.
  - `0x004b8823` -> not a function.
  - `0x004b8830` -> `sub_4B8830`, size `0xb1`.
  - `0x00544690` -> `sub_544690`, size `0x1d`.
  - `0x00544ee0` -> `sub_544EE0`, size `0x4e`.
  - `0x004b78d0` -> `sub_4B78D0`, size `0x1e`.
  - `0x004615b0` -> `sub_4615B0`, size `0x11`.
  - `0x004615d0` -> IDA label `___std_parallel_algorithms_hw_threads@0`, size `0x88`; FrameChrome docs resolve this false label as the dynamic AboveFrame recreate helper.
  - `0x004e9ee0` -> `sub_4E9EE0`, size `0x4d`.
- `get_bytes 0x004b8810 size 48`: function epilogue includes `8b e5 5d c2 08 00`, followed by `0xcc` padding and the `0x004b8830` prologue `55 8b ec 6a ff ...`.
- `get_bytes 0x004b8820 size 24`: `c2 08 00 cc cc cc cc cc cc cc cc cc cc cc cc cc 55 8b ec 6a ff 68 a4 f2`.
- `callees 0x004b8650`: `0x00544690`, `0x00544ee0`, `0x004b78d0`, `0x004615b0`, `0x004615d0`, `@__security_check_cookie@4`, `0x004e9ee0`.
- `decompile 0x004b8650`: confirms the exact source shape summarized in this report.
- `xref_query to 0x004b8650`: 35 code refs, including `0x00508040`, `0x00508679`, `0x00508cb2`, `0x00541b9c`, `0x005abde3`, `0x005abe3d`, `0x005abe55`, `0x005b13df`, `0x005b304f`, `0x005b329f`, and `0x005b622f`.
- `analyze_function 0x00544690`: sets `Pane +0xf4` when not already marked and calls `0x00469180` through cleanup queue storage `dword_67A74C`.
- `analyze_function 0x00544ee0`: calls the old child primary slot `+0x38`, clears a local zero rectangle, then calls primary slot `+0x0c`; callers are only `sub_4B8650` and `sub_4B89A0`.
- `analyze_function 0x004b78d0`: writes four `RectBounds` edge integers; no callees; broad caller fan-in.

## Function / Child Inventory

| Range / item | Status | Recommendation |
| --- | --- | --- |
| `0x004b8650-0x004b8823` half-open | Exact source-authored `GeneralPurposePanel::SwitchActiveTab(int tabIndex, bool showChild)` body. | Keep as [UID:00015X], owner/emitter [UID:00005Q], no split needed. |
| `0x004b8823-0x004b8830` | `0xcc` alignment padding after `retn 8`. | Keep out of target source; document as padding before `GeneralPurposePanel2` constructor. |
| `0x004b8830` successor | `GeneralPurposePanel2` constructor start. | Boundary positive control only. |
| `0x00544690` | `Pane::MarkForDeletion`. | Dependency owned by Pane; support docs already strong. |
| `0x00544ee0` | Switch-out Pane helper used only by GeneralPurposePanel and GeneralPurposePanel2 switch helpers. | Add PaneCore support row/note in implementation callback; do not make it GeneralPurposePanel-owned. |
| `0x004b78d0` | `RectBounds::SetLTRB`. | Dependency owned by RectBounds; no target blocker. |
| `0x004615b0` / `0x004615d0` | FrameChrome dynamic AboveFrame release/recreate helpers. | Dependency owned by FrameChrome. |
| `0x004e9ee0` | `InterfaceEfxMgr::TriggerInterfaceEffect(int effectId)`. | Dependency owned by InterfaceEfxMgr. |

## Direct Xref / Caller Inventory

Current MCP returns 35 code refs to `0x004b8650`. Important representative callers:

| Callsite | Containing function | Meaning |
| ---: | --- | --- |
| `0x00508040`, `0x00508679`, `0x00508cb2` | `sub_507C90` / [UID:00037T] `MapPanePacketDispatcher` | MapPane packet cases call side-panel tab switches. |
| `0x00541b9c` | `sub_541B30` / IntegrateMacroDialog context | Macro/dialog construction path opens a panel tab. |
| `0x005abde3`, `0x005abe3d`, `0x005abe55` | `sub_5ABDA0` / [UID:0003UT] LivingObjectPane UI panel switch packet | Server opcode `0x3e` actions open inventory tab `2` and spell inventory tab `3`. |
| `0x005b13df` | `sub_5B13A0` / SpellSlotInputPane key shortcut | Spell prompt `?` shortcut opens spell tab `3`. |
| `0x005b304f` | `sub_5B3010` / ChangeItemSlotInputPane key shortcut | Item prompt `?` shortcut opens inventory tab `2`. |
| `0x005b329f`, `0x005b622f` | ChangeSpellSlotInputPane / SpellSpellInputPane key shortcuts | Spell prompt `?` shortcuts open spell tab `3`. |
| `0x005a5f9d`, `0x005a6067` | UserPane-family broad handler | Side-panel user/profile paths. |

This caller spread proves a shared side-panel shell method. It rejects any source placement under SpellInputPanes, LivingObjectPane, MapPane, UserPane, or dialog constructors.

## Documentation Evidence And IDA Status

- [UID:0000JQ] `GeneralPurposePanel` already declares the correct source route, class composition, child helper rows, stale generated owner rejection, and external FrameChrome/InterfaceEfx dependencies.
- [UID:00005Q] `GeneralPurposePanel` already emits the class shell with `Pane* m_childPanes[7]`, `int m_activeChildIndex`, and `void SwitchActiveTab(int tabIndex, bool showChild)`.
- [UID:00015W] child accessors support the same field names and child-index map.
- [UID:00015V] aggregate report and current page both support no monolithic aggregate C++ and exact child pages.
- [UID:0000YI]/FrameChrome docs already own the AboveFrame refresh helpers and reject the false `__std_parallel_algorithms_hw_threads` label for `0x004615d0`.
- [UID:00018H] now emits `InterfaceEfxMgr::TriggerInterfaceEffect(int effectId)` and documents that UID00015X passes the active child index.
- [UID:0001EA]/PaneCore and [UID:0003JA]/PaneVtables resolve most inherited pane slot names, but need a fresh support note for the modeled `0x00544ee0-0x00544f2e` helper and still do not source-finalize `+0x0c`/`+0x48`.
- [UID:0003UT] and [UID:00037T] confirm server-driven caller contexts without moving ownership.
- [UID:0000O0] and [UID:0000DR] explicitly reject migrating GeneralPurposePanel helper pages with `SpellOneArgInputPane`.

## Range / Split / Padding / Reclassification Analysis

No target split is recommended. UID00015X is one modeled function with one source-level purpose. Current MCP confirms:

- Function start: `0x004b8650`.
- Function size: `0x1d3`.
- Return: `0x004b8820` begins `retn 8`.
- Last function byte: `0x004b8822`.
- Padding: `0x004b8823-0x004b8830`.
- Successor: `0x004b8830` `GeneralPurposePanel2` constructor.

The target should continue to use filename/inclusive title `0x004b8650-0x004b8822` while prose can state the half-open function interval as `0x004b8650-0x004b8823`.

No compiler-generated wrapper or jump-table bytes are inside UID00015X. The only compiler support is the stack-cookie check inside the body.

## Ranked Ownership Analysis

### 1. [UID:00005Q] GeneralPurposePanel

Evidence for:

- Receiver is the seven-child GeneralPurposePanel layout: `this[index + 1]` for child pointers and `this[8]` / offset `+0x20` for active index.
- Class/file docs already declare the method and fields.
- Constructor/aggregate docs place the child array and side-panel shell in GeneralPurposePanel.
- Broad callers are side-panel page switchers, not a single feature.

Evidence against:

- Exact original public method spelling is not symbol-proven.
- It calls external FrameChrome, Pane, RectBounds, InterfaceEfx, TotemFrame, and layer/global helpers.

Decision: accepted direct owner/emitter. External calls are dependencies, not ownership conflicts.

### 2. [UID:0000JQ] GeneralPurposePanel source file

Evidence for:

- Parent file owns GeneralPurposePanel and GeneralPurposePanel2 side-panel shells.
- Generated `GeneralPurposePanel.cpp` already includes the class declaration and empty UID00015X marker.

Evidence against:

- Formal method body is still blocked by inherited virtual/helper spelling.

Decision: accepted file route; body remains blank for this exact pass.

### 3. [UID:0000O0] SpellInputPanes / [UID:0000DR] SpellOneArgInputPane

Evidence for:

- Historical generated `class_SpellOneArgInputPane.cpp` pollution included this address.
- Spell input key handlers call `SwitchActiveTab(3,false)`.

Evidence against:

- UID00015X receiver layout is GeneralPurposePanel, not spell input pane.
- Callers include MapPane, LivingObjectPane, UserPane, macro dialogs, item/spell shortcuts, and many small UI wrappers.
- SpellInputPanes docs explicitly reject migrating `0x004b85f0`, `0x004b8620`, `0x004b8630`, and `0x004b8650` with spell argument panes.

Decision: rejected as stale generated owner.

### 4. MapPane / LivingObjectPane / UserPane / Dialog Callers

Evidence for:

- These families call the helper.

Evidence against:

- They do not own the receiver or child array.
- Their packet/input/dialog logic remains separate and calls this broad panel switcher as a dependency.

Decision: caller evidence only; rejected as direct owners.

### 5. PaneCore / RectBounds / FrameChrome / InterfaceEfx / TotemFrame / MainUiLayerSlots

Evidence for:

- UID00015X depends on all of these.

Evidence against:

- They own helper bodies or global storage, not the side-panel switch method.

Decision: support owners only.

## Source Placement

Place the method body, when it becomes source-ready, under:

```text
NexusTK/ui/panels/GeneralPurposePanel.cpp
GeneralPurposePanel::SwitchActiveTab(int tabIndex, bool showChild)
```

Do not place it in:

- `NexusTK/ui/dialogs/SpellInputPanes.cpp`.
- `NexusTK/map/LivingObjectPane.cpp`.
- `NexusTK/map/MapPane.cpp`.
- `NexusTK/ui/core/Pane.cpp`.
- `NexusTK/ui/core/FrameChrome.cpp`.
- `NexusTK/ui/InterfaceEfx.cpp`.

Those files own callers or helper dependencies only.

## Claim And Incorporation Ledger

| Claim ID | Claim | Confidence | Evidence | Destination doc/section | Action | Verification state |
| --- | --- | --- | --- | --- | --- | --- |
| C001 | UID00015X boundary is `0x004b8650-0x004b8823` half-open, final byte `0x004b8822`, padding to `0x004b8830`. | High | Current MCP `lookup_funcs`, `get_bytes`; `0x004b8820` bytes `c2 08 00 cc`, `0x004b8823` not a function. | UID00015X `Function Boundary`; tracker row note. | incorporate | applied: target `Function Boundary` records the half-open interval, final included byte, padding, and successor; validator `000000007979` ok. |
| C002 | `0x004b8830` starts successor `sub_4B8830` / `GeneralPurposePanel2` constructor, so no split extension belongs to UID00015X. | High | Current MCP `lookup_funcs 0x004b8830`; target successor docs. | UID00015X `Function Boundary`. | incorporate | applied: target `Function Boundary` names the `0x004b8830` successor; validator `000000007979` ok. |
| C003 | Method owner is [UID:00005Q] `GeneralPurposePanel` and source file route is [UID:0000JQ] `GeneralPurposePanel.cpp`. | High | Target, class, file, generated `GeneralPurposePanel.cpp`, broad caller fan-in. | UID00015X metadata/status; [UID:00005Q]/[UID:0000JQ] cross-links. | already-present | already-present: owner/emitter/reconstructable values stayed unchanged; GeneralPurposePanel file/class notes were synced where stale; validators `000000007979`, `000000007981`, `000000007982` ok. |
| C004 | Generated `SpellOneArgInputPane` ownership is stale pollution, not a valid owner for UID00015X. | High | SpellInputPanes/SpellOneArgInputPane docs, generated `SpellInputPanes.cpp`, current xrefs. | UID00015X `Ownership Notes`; [UID:0000O0]/[UID:0000DR] stale-owner notes. | already-present | already-present: UID00015X preserves stale-owner rejection; SpellInputPanes and SpellOneArgInputPane were inspected read-only and already reject at same-or-greater detail. |
| C005 | EPF/current mode accepts tabs `< 7`; legacy mode accepts tabs `< 4`. | High | Current decompile branch on `g_useEpfAssets == 1`; target behavior docs. | UID00015X `Behavior`. | already-present | already-present: target `Behavior` retains both limits; validator `000000007979` ok. |
| C006 | Same-index requests for tabs `2+` skip; same-index tab `0`/`1` requests continue through refresh/switch path. | High | Current decompile at `0x004b8684-0x004b8698` and legacy equivalent. | UID00015X `Behavior`. | incorporate | applied: target `Behavior` states the same-index exception; validator `000000007979` ok. |
| C007 | `this[index + 1]` is `m_childPanes[7]`; `this[8]` / `+0x20` is `m_activeChildIndex`. | High | UID00015W, GeneralPurposePanel docs, generated class shell, current decompile. | UID00015X `Callee And State Evidence`; class/file field notes. | already-present | already-present: target, GeneralPurposePanel file, and GeneralPurposePanel class preserve these names; validator `000000007979` ok. |
| C008 | New-layout rectangle is `(832,79,1021,367)` and legacy rectangle is `(434,12,626,300)`. | High | Current decompile and `RectBounds::SetLTRB` call. | UID00015X `Behavior`. | already-present | already-present: target `Behavior`/state evidence retains both RectBounds rectangles; validator `000000007979` ok. |
| C009 | `0x004b78d0` is `RectBounds::SetLTRB`. | High | RectBoundsMethods support and current MCP callees. | UID00015X `Callee And State Evidence`. | incorporate | applied: target and GeneralPurposePanel support notes use `RectBounds::SetLTRB`; validators `000000007979`, `000000007981` ok. |
| C010 | `0x00544690` is `Pane::MarkForDeletion`; UID00015X uses it on `g_pTotemFrame`. | High | `analyze_function 0x00544690`; PaneCore, BlackHole, g_pTotemFrame docs. | UID00015X `Callee And State Evidence`; PaneCore support reference. | incorporate | applied: target records `g_pTotemFrame` cleanup through `Pane::MarkForDeletion`; validators `000000007979`, `000000007980` ok. |
| C011 | `0x00544ee0` is a Pane switch-out collapse helper with only UID00015X/UID00015Y callers, not spell-owned. | Medium-high | `analyze_function 0x00544ee0`; callers `sub_4B8650` and `sub_4B89A0`; slot `+0x38`, zero-rect slot `+0x0c`. | UID00015X `Callee And State Evidence`; [UID:0001EA] `PaneCore` support row. | incorporate | applied: target and PaneCore now document helper behavior, only-callers proof, and unresolved `+0x0c`; validators `000000007979`, `000000007980` ok. |
| C012 | Old child then calls vslot `+0x40`, supported as `Pane::UnregisterEventHandler`. | High | Current decompile, PaneVtables support. | UID00015X `Callee And State Evidence`. | incorporate | applied: target records old-child `Pane::UnregisterEventHandler` slot `+0x40`; validator `000000007979` ok. |
| C013 | New child uses `Pane::SetBounds` (`+0x2c`), `Pane::AddToLayer` (`+0x30`), `Pane::SetPaneOrder`/ordering (`+0x3c`), and unresolved inherited display/activation slot `+0x48`. | Medium-high | Current decompile, PaneVtables/PanelPaneVtables support; lack of final `+0x48` source-facing name. | UID00015X `Source-Quality / No-Code Proof`; PaneVtables caveat. | incorporate | applied: target records the new-child slot sequence and keeps `+0x48` as a formal-C++ blocker; PaneVtables was inspected read-only and already had the unresolved `+0x48` caveat. |
| C014 | `0x004615b0`/`0x004615d0` are FrameChrome dynamic AboveFrame release/recreate helpers. | High | AboveFrameRefreshHelpers, FrameChrome docs, current MCP callees. | UID00015X `Behavior`. | already-present | already-present: target preserves FrameChrome release/recreate calls; validator `000000007979` ok. |
| C015 | Legacy branch calls `InterfaceEfxMgr::TriggerInterfaceEffect(m_activeChildIndex)`. | High | UID00018H, g_pInterfaceEfxMgr docs, current decompile call `sub_4E9EE0(unk_69B360, this[8])`. | UID00015X `Behavior`. | already-present | already-present: target preserves legacy InterfaceEfx call with `m_activeChildIndex`; validator `000000007979` ok. |
| C016 | `g_pBackPane` and `rootPaneLayerContext`/MainUiLayerSlots are external layer/context arguments, not GeneralPurposePanel fields. | Medium-high | g_pBackPane, MainUiLayerSlots docs, current decompile argument flow. | UID00015X dependency notes. | incorporate | applied: target behavior/callee evidence keeps these as external dependencies; validator `000000007979` ok. |
| C017 | Current xrefs show 35 code callers, proving broad side-panel shell usage. | High | Current MCP `xref_query to 0x004b8650`. | UID00015X `Caller Evidence`; tracker row note. | incorporate | applied: target `Caller Evidence` records 35 callers; validator `000000007979` ok. |
| C018 | MapPane dispatcher callsites include `0x00508040`, `0x00508679`, `0x00508cb2`. | High | Current MCP xrefs and MapPane docs. | UID00015X `Caller Evidence`. | incorporate | applied: target caller evidence records the MapPane callsites; validator `000000007979` ok. |
| C019 | LivingObjectPane handler callsites include `0x005abde3`, `0x005abe3d`, `0x005abe55`. | High | Current MCP xrefs and LivingObjectPane packet support. | UID00015X `Packet Dispatch Notes` / `Caller Evidence`. | incorporate | applied: target caller and packet-dispatch notes record LivingObjectPane opcode caller context; validator `000000007979` ok. |
| C020 | Formal C++ should remain blank until helper `0x00544ee0`, helper slot `+0x0c`, and child slot `+0x48` have support-quality source spellings. | High | Current MCP proof plus negative check across PaneCore, PaneVtables, PanelPaneVtables, generated output, target/support docs. | UID00015X `RECONSTRUCTION_CPP`; `Source-Quality / No-Code Proof`. | incorporate | applied: target formal `RECONSTRUCTION_CPP` block remains blank and target has a no-code proof; validator `000000007979` ok. |
| C021 | Recommended score moves from `85/91` to `88/93` without changing owner, reconstructable state, or emitter. | High | Current owner/boundary/dependency/caller proof; unresolved names limited to formal C++ only. | UID00015X metadata; tracker row. | incorporate | applied: target metadata is `88/93`, owner/reconstructable/emitter unchanged; validator `000000007979` ok with completion/confidence updates. |
| C022 | Generated `GeneralPurposePanel.cpp` remains empty for UID00015X, consistent with no-code recommendation. | High | Generated file refreshed by command `000000007832` at `2026-07-07T03:37:36-04:00`; UID00015X empty marker; callback validators reported `generated_refresh: deferred`. | UID00015X `Generated output` note; report `Current Target State`. | not-applicable | excluded-with-reason: generated output was not manually edited; scoped validators deferred generated refresh, so the no-code state remains report evidence rather than a generated-code edit. |
| C023 | During callback, B005 manually edited only accepted leased by-* docs and this report; no generated files, coverage reports, validator state, queues, locks, archives, lifecycle files, supervisor ledgers, IDA DB state, or unrelated docs were manually edited. | High | Current assignment hard boundaries; lease command succeeded for four by-* docs; release/current lease checks show no active leases. | Report `Changed Files`; final response provenance. | incorporate | applied: report changed-files/lease section lists edited docs, scoped validators, and lease release state. |
| C024 | Pre-existing dirty by-* worktree changes are not B005 edits and must not be reverted. | High | Read-only `git status --short` observed existing dirty by-* files before report creation/repair; final status remains dirty because this workspace is shared and validators can update generated/stat files. | Report `Changed Files`. | not-applicable | applied: no unrelated dirty files were reverted; final response scopes B005 edits to the accepted files and validator-owned side effects. |

## Positive Evidence Summary

- Current IDA MCP is available and healthy.
- Exact function boundary and successor padding are reconfirmed.
- Decompile exactly matches the documented side-panel switch behavior.
- All direct callees are known support dependencies or narrowly identified helper blockers.
- GeneralPurposePanel field names `m_childPanes[7]` and `m_activeChildIndex` are already accepted in class/file/generated output.
- Caller fan-in is broad and spans MapPane, LivingObjectPane, spell/item input shortcuts, macro/dialog paths, and user-pane paths.
- FrameChrome and InterfaceEfx helper ownership is already resolved and does not block this target.
- SpellInputPanes and SpellOneArgInputPane support pages explicitly reject the stale generated ownership.

## Negative Evidence Summary

- No original source symbol proves the public method spelling beyond the accepted descriptive `SwitchActiveTab`.
- No current support page gives a final source-facing name for `0x00544ee0`; current MCP only proves behavior and callers.
- The Pane/PanelPane vtable docs still leave inherited primary slot `+0x48` and the `+0x0c` slot used inside `0x00544ee0` below final-source spelling quality.
- Any formal C++ body today would need invented names for those slots or wrappers, which would reduce source quality.
- Generated output still leaves UID00015X as an empty emitter marker; it does not yet validate a method body.

## First-Draft C++ Recommendation

No C++ insertion text is provided in this report. Because the current evidence cannot support exact formal `RECONSTRUCTION_CPP CODE` insertion text, this section intentionally contains no C++ block, no illustrative body, and no non-insertion sample.

UID00015X clears the active source gate for owner, range, behavior, fields, callers, and dependency ownership, but its formal body must remain blank under a rare target-specific no-code proof:

1. The body is not a simple wrapper. It directly calls helper `0x00544ee0`; current MCP proves behavior and callers, but current support does not prove the helper's source-level name, declaration, or the source name for its inherited slot `+0x0c`.
2. UID00015X also calls child primary slot `+0x48` to finish display/activation. Pane and PanelPane vtable docs do not yet provide a stable source-facing base name for this inherited slot, and derived panes use family-specific overrides that cannot be generalized safely here.
3. Insertion text using invented wrapper names, raw vslot dispatch, or placeholder calls would lower source quality and would not be verifiable against current support docs.
4. All other body components are source-ready for prose and documentation edits: `RectBounds::SetLTRB`, `Pane::SetBounds`, `Pane::AddToLayer`, `Pane::SetPaneOrder`, `Pane::UnregisterEventHandler`, `Pane::MarkForDeletion`, `ReleaseDynamicAboveFrame`, `RecreateDynamicAboveFrame`, `InterfaceEfxMgr::TriggerInterfaceEffect`, `m_childPanes`, and `m_activeChildIndex`.

Reasonable current routes exhausted:

| Route checked | Evidence checked | Result / score-blocker disposition |
| --- | --- | --- |
| Current target decompile and boundary proof | MCP `lookup_funcs`, `get_bytes`, `callees`, `xref_query`, and decompile for `0x004b8650-0x004b8822`; successor proof at `0x004b8830`. | Closed owner/range/control-flow blockers. Does not name helper `0x00544ee0`, slot `+0x0c`, or slot `+0x48` at source quality. |
| Helper `0x00544ee0` analysis | MCP `analyze_function 0x00544ee0`; only callers `sub_4B8650` and `sub_4B89A0`; calls primary slot `+0x38`, clears a local zero rectangle, then calls primary slot `+0x0c`. | Behavior and ownership are report-ready and map to ledger C011. Exact helper source name/declaration and `+0x0c` source name remain unresolved after current available routes, so no formal C++ call can be written. |
| Pane/PanelPane vtable support | `PaneVtables`, `PanelPaneVtables`, PaneCore, and related support docs checked against slots `+0x2c`, `+0x30`, `+0x3c`, `+0x40`, `+0x48`, and helper slot `+0x0c`. | Slots `+0x2c/+0x30/+0x3c/+0x40` are supportable in prose. Slots `+0x48` and `+0x0c` are not final-source names in current support, so they stay as explicit no-code blockers under ledger C013/C020. |
| Target/support docs and generated output | UID00015X, GeneralPurposePanel class/file/aggregate/accessor docs, RectBounds, BlackHole, FrameChrome, InterfaceEfx, g_pTotemFrame, g_pBackPane, MainUiLayerSlots, SpellInputPanes, old reports, generated `GeneralPurposePanel.cpp` and `SpellInputPanes.cpp`. | No related doc supplies the missing source names. Generated `GeneralPurposePanel.cpp` remains fresh and empty for UID00015X, which supports retaining blank C++ rather than inventing a body. |
| Source-shape alternatives | Considered raw virtual-slot calls, invented helper/wrapper names, inlining `0x00544ee0`, using family-specific derived-pane names, or splitting `0x00544ee0` as a new child before support acceptance. | Rejected with evidence. Each route either invents API names, embeds raw dispatch in project source, obscures helper ownership, or requires support by-* acceptance beyond this UID00015X callback scope. |

Score-blocker reconciliation:

- Inherited child slot `+0x48`: exhausted current decompile, vtable, and derived-pane documentation routes. It remains a formal-C++ blocker only; target behavior can still be documented as inherited display/activation virtual dispatch.
- Helper `0x00544ee0`: ownership and behavior are resolved enough for PaneCore support update and target prose. Its exact source name/declaration remains unsupported, so it blocks insertion text but not the recommended score increase.
- Helper slot `+0x0c`: exhausted current helper decompile and vtable support routes. It remains unresolved as a source-facing name and is the second reason no exact formal helper call can be written.

This is not an open-ended deferral. The current routes that can be used without editing support docs, changing IDA state, or inventing source have been exhausted, and the remaining gap is limited to exact source spelling for three inherited/helper surfaces. That makes blank formal C++ the only source-quality recommendation for this report.

## IDA Rename / Type / Comment Recommendations

No IDA DB edits are authorized or recommended during this B005 assignment.

If a future IDA annotation pass is authorized, suggested non-destructive comment/name directions are:

- `0x004b8650`: `GeneralPurposePanel::SwitchActiveTab(int tabIndex, bool showChild)` / `GeneralPurposePanel_SwitchActiveTab`.
- `0x00544ee0`: descriptive comment only until PaneCore owner accepts a name: "Pane switch-out collapse helper; calls RemoveFromLayer-style slot +0x38, clears a zero rect through inherited slot +0x0c; only GeneralPurposePanel switch helpers call it."
- `0x004615d0`: retain FrameChrome recreate helper comment; reject false IDA name `___std_parallel_algorithms_hw_threads@0` in docs.

Do not rename or type IDA in this B005 assignment.

## Final Recommendation

Gate 1 passed for this report, and the target/support documentation implementation callback has been applied:

- Raised UID00015X to `88/93`.
- Kept owner/emitter [UID:00005Q].
- Kept formal C++ blank with the exact no-code proof above.
- Replaced or annotated raw helper labels in target prose with supported dependency names.
- Added current MCP session `b007_uid0002oc_20260708` facts for range, bytes, callees, and caller fan-in.
- Added/refreshed PaneCore support for `0x00544ee0-0x00544f2e`.
- Did not manually edit generated output; scoped validators reported `generated_refresh: deferred`.

## Recommended Target Doc Changes

1. Update metadata:

```text
*** COMPLETION:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:93 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
```

2. Update item summary to mention current MCP session, exact half-open boundary, helper names, and the narrow C++ blocker.

3. In `Function Boundary`, add:

```markdown
2026-07-08 B005 current IDA MCP session `b007_uid0002oc_20260708` reconfirms `sub_4B8650` size `0x1d3`: `0x004b8822` remains inside the function, `0x004b8823` is not a function, bytes at `0x004b8820` are `c2 08 00` followed by `0xcc` padding, and `0x004b8830` starts `sub_4B8830`. Treat the source interval as `0x004b8650-0x004b8823` half-open, with the filename's `0x004b8822` as the final included byte.
```

4. In `Callee And State Evidence`, replace raw helper wording:

- `0x004b78d0` -> `RectBounds::SetLTRB`.
- `0x00544690` -> `Pane::MarkForDeletion`.
- `0x00544ee0` -> "Pane switch-out collapse helper; exact source name unresolved; calls slot `+0x38`, zero-rect slot `+0x0c`, and only has GeneralPurposePanel/GeneralPurposePanel2 switch callers."
- Slot `+0x40` -> `Pane::UnregisterEventHandler`.
- Slot `+0x2c` -> `Pane::SetBounds`.
- Slot `+0x30` -> `Pane::AddToLayer`.
- Slot `+0x3c` -> `Pane::SetPaneOrder` / dispatcher ordering helper.
- Slot `+0x48` -> keep as unresolved inherited display/activation virtual.

5. Add a `Source-Quality / No-Code Proof` section explaining why formal C++ remains blank despite the active gate.

6. Refresh `Caller Evidence` with current xref callsites, especially LivingObjectPane `0x005abde3/0x005abe3d/0x005abe55` and existing MapPane `0x00508040/0x00508679/0x00508cb2`.

7. Optional coverage row replacement after target/support edits:

```markdown
    - [UID:00015X][0x004b8650-0x004b8822.GeneralPurposePanelSwitchActiveTab](by-memory/0x004b8650-0x004b8822.GeneralPurposePanelSwitchActiveTab.md) 0x004b8650-0x004b8822 | class-method | GeneralPurposePanel::SwitchActiveTab : reconstructable : 88% : very-strong : B005 2026-07-08 current IDA MCP session `b007_uid0002oc_20260708` reconfirms exact `sub_4B8650` size `0x1d3`, final byte `0x004b8822`, padding `0x004b8823-0x004b8830`, EPF/new tab limit 7, legacy tab limit 4, same-tab refresh exception for indexes 0/1, `m_childPanes[7]`, `m_activeChildIndex`, `RectBounds::SetLTRB` rectangles `(832,79,1021,367)` and `(434,12,626,300)`, `g_pTotemFrame` cleanup through `Pane::MarkForDeletion`, old-child switch-out helper `0x00544ee0` plus `Pane::UnregisterEventHandler`, new-child `Pane::SetBounds`/`AddToLayer`/ordering/display virtual sequence, FrameChrome dynamic AboveFrame release/recreate calls, legacy `InterfaceEfxMgr::TriggerInterfaceEffect(m_activeChildIndex)`, 35 broad side-panel callers including MapPane, LivingObjectPane opcode `0x3e`, spell/item input shortcuts, and stale SpellOneArgInputPane generated ownership rejection. Formal C++ remains blank with a target-specific no-code proof pending source-quality names for `0x00544ee0` slot `+0x0c` and inherited display/activation slot `+0x48`.
```

## Recommended Support Doc Changes

- [UID:0001EA] `PaneCore`: add row for `0x00544ee0-0x00544f2e`, stating it is a Pane switch-out collapse helper with only UID00015X and UID00015Y callers; current MCP shows it calls primary slot `+0x38`, zeroes a local rectangle, and forwards through primary slot `+0x0c`. Keep exact final source name unresolved unless a later Pane pass proves it.
- [UID:0003JA] `PaneVtables`: no score change required, but cross-link the unresolved `+0x48` caveat if UID00015X text starts citing it.
- [UID:00015W] `GeneralPurposePanelChildAccessors`: no required change; already supports `m_childPanes[7]` and `m_activeChildIndex`.
- [UID:0000JQ] `GeneralPurposePanel`: optionally add a short B005 note that UID00015X now has current MCP proof for helper naming, but method C++ remains blank for the narrow inherited-slot blocker.
- [UID:00005Q] `GeneralPurposePanel`: no declaration change required; class shell already has `SwitchActiveTab(int tabIndex, bool showChild)`.
- [UID:0000O0] `SpellInputPanes` and [UID:0000DR] `SpellOneArgInputPane`: no change required; they already reject stale panel-helper ownership at equal or greater detail.
- [UID:0000YI], [UID:00018H], [UID:0000SK], [UID:00028J], [UID:00029M]: no score or content change required for this target; current docs are adequate dependency support.

## Score And Metadata Recommendation

| Field | Current | Recommended | Rationale |
| --- | ---: | ---: | --- |
| `COMPLETION` | 85 | 88 | Current MCP refresh resolves boundary/padding, helper names, exact dependency ownership, caller fan-in, stale generated ownership proof, and a target-specific formal-C++ no-code proof. |
| `CONFIDENCE` | 91 | 93 | Live IDA, current support docs, and generated output agree on owner, fields, behavior, and caller spread. Confidence remains below final audit only because original source spelling for inherited slot `+0x48`, helper `0x00544ee0`, and helper slot `+0x0c` is not recovered. |
| `CANONICAL_OWNER` | 00005Q | 00005Q | Direct semantic owner remains GeneralPurposePanel. |
| `RECONSTRUCTABLE` | TRUE | TRUE | Source-authored method, not compiler-only data. |
| `EMITTER_UIDS` | 00005Q | 00005Q | Body should eventually emit through GeneralPurposePanel class into GeneralPurposePanel.cpp. |
| `RECONSTRUCTION_CPP` | blank | blank | Keep blank with exact no-code proof until inherited virtual/helper names are support-quality. |

## Open Questions With Attempted Resolution

| Question | Attempted resolution | Result |
| --- | --- | --- |
| Is the boundary current? | Current MCP `lookup_funcs` and `get_bytes` rechecked start, size, final bytes, padding, and successor. | Closed. |
| Is `SpellOneArgInputPane` a possible owner? | Checked target docs, GeneralPurposePanel docs, SpellInputPanes docs, generated SpellInputPanes output, and current caller fan-in. | Closed: stale generated pollution only. |
| Are `m_childPanes[7]` and `m_activeChildIndex` safe names? | Checked GeneralPurposePanel class/file, UID00015W, target decompile, FrameChrome dependency. | Closed for first-draft source quality. |
| Is `0x004b78d0` still a blocker? | Checked RectBoundsMethods and current MCP. | Closed: `RectBounds::SetLTRB`. |
| Is `0x00544690` still a blocker? | Checked PaneCore, BlackHole queue, g_pTotemFrame, current MCP. | Closed: `Pane::MarkForDeletion`. |
| Is `0x00544ee0` resolved enough for formal C++? | Current MCP decompiled it; checked PaneCore/vtable docs. | Partially resolved: behavior and ownership closed, exact source name and slot `+0x0c` still open. |
| Are inherited pane slots resolved? | Checked PaneVtables and PanelPaneVtables. | `+0x2c/+0x30/+0x3c/+0x40` resolved enough; `+0x48` and `+0x0c` remain formal-C++ blockers. |
| Is first-draft formal C++ justified now? | Compared source gate against unresolved helper/virtual names and the formal-code-only rule for any C++ shown in reports. | No. Provide a narrow prose no-code proof and omit all C++ sample/planning blocks. |
| Does generated freshness matter? | Checked current generated `GeneralPurposePanel.cpp`. | Relevant: generated file is fresh and still marks UID00015X empty, consistent with no-code recommendation. |

## Validator Results

Scoped validators were run only for the changed by-* files from `E:\NTK\GhidraBridge\source-3\project-documentation`, as authorized by the implementation callback. `execute_report`, dry-run/probing execute variants, lifecycle/archive commands, report moves, MCP/IDA/Python management commands, and non-scoped validators were not run.

Validator command metadata:

```text
command_id: 000000007979
timestamp: 2026-07-08T16:32:06-04:00
cwd: E:\NTK\GhidraBridge\source-3\project-documentation
command: python .\tools\validator.py --mode file --file by-memory/0x004b8650-0x004b8822.GeneralPurposePanelSwitchActiveTab.md --apply --queue-timeout 240
exit: 0
ok: 1
generated_refresh: deferred
notes: completion_update UID00015X -> 88; confidence_update UID00015X -> 93; uid_link_insert for 0001EA/00015Q/00028J/00029M; missing_ref_uid warnings for 0003UT and 0003JA.
```

```text
command_id: 000000007980
timestamp: 2026-07-08T16:32:16-04:00
cwd: E:\NTK\GhidraBridge\source-3\project-documentation
command: python .\tools\validator.py --mode file --file by-memory/0x00544460-0x00545086.PaneCore.md --apply --queue-timeout 240
exit: 0
ok: 1
generated_refresh: deferred
notes: uid_link_insert for 00015X/00015Y; missing_ref_uid warning for 0003JA.
```

```text
command_id: 000000007981
timestamp: 2026-07-08T16:32:27-04:00
cwd: E:\NTK\GhidraBridge\source-3\project-documentation
command: python .\tools\validator.py --mode file --file by-file/GeneralPurposePanel.md --apply --queue-timeout 240
exit: 0
ok: 1
generated_refresh: deferred
notes: uid_link_insert for 00015Q/0001EA/00015X; missing_ref_uid warning for 0003A2.
```

```text
command_id: 000000007982
timestamp: 2026-07-08T16:32:37-04:00
cwd: E:\NTK\GhidraBridge\source-3\project-documentation
command: python .\tools\validator.py --mode file --file by-class/GeneralPurposePanel.md --apply --queue-timeout 240
exit: 0
ok: 1
generated_refresh: deferred
notes: stats_row_update for 00005Q; uid_link_insert for 00015X; missing_ref_uid warnings for 0003BC.
```

Non-validator MCP command metadata:

```text
endpoint: http://127.0.0.1:13337/mcp
database/session: b007_uid0002oc_20260708
health: ok
read-only tools used: idb_list, server_health, lookup_funcs, get_bytes, callees, xref_query, decompile, analyze_function
```

## Changed Files

Manually edited by B005 during the accepted implementation callback:

```text
by-memory/0x004b8650-0x004b8822.GeneralPurposePanelSwitchActiveTab.md
by-memory/0x00544460-0x00545086.PaneCore.md
by-file/GeneralPurposePanel.md
by-class/GeneralPurposePanel.md
tools/leaser/Agents/Agent-B005/research/00015X-GeneralPurposePanelSwitchActiveTab-source-quality.md
```

Validator-owned generated/stat side effects observed after scoped validators:

```text
auto-generated/-ag-class-coverage.md
auto-generated/-ag-file-coverage.md
auto-generated/-ag-memory-coverage.md
project-level/-auto-completion-stats.md
```

Those generated/stat files were not manually edited by B005. The scoped validators reported `generated_refresh: deferred`; the listed side effects are validator-owned score/link/stat maintenance.

Optional docs inspected read-only and not edited because they were already same-or-greater detail for this callback:

```text
by-type/by-vtable/PaneVtables.md
by-file/SpellInputPanes.md
by-class/SpellOneArgInputPane.md
```

Worktree note: `git status --short` showed pre-existing dirty changes in shared by-* files before the callback. I did not revert unrelated work and did not use destructive git commands.

Leases used/released:

```text
lease command: python leaser.py B005 lease <four callback by-* paths>
leased paths:
  by-memory/0x004b8650-0x004b8822.GeneralPurposePanelSwitchActiveTab.md
  by-memory/0x00544460-0x00545086.PaneCore.md
  by-file/GeneralPurposePanel.md
  by-class/GeneralPurposePanel.md
lease result: Success for all four paths

release command: python leaser.py B005 unlease
release result: B005: No active leases
current_leases.md: No active leases
```

## Implementation Tracking Checklist

- [x] Gate 1 review of this repaired report passed. Ledger rows: C001-C024. Callback outcome: supervisor accepted SHA256 `2F5CD02DB981FDB8C06F350004D6BBAA742032636183A732E56FFC663E8F3A22` and authorized by-* implementation.
- [x] Update UID00015X metadata to `COMPLETION:88`, `CONFIDENCE:93`, keeping `CANONICAL_OWNER:00005Q`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:00005Q`, and blank `RECONSTRUCTION_CPP`. Ledger rows: C003, C020, C021. Callback outcome: target metadata updated; validator `000000007979` ok and reported completion/confidence updates.
- [x] Add current boundary/split evidence to UID00015X `Function Boundary`. Ledger rows: C001, C002. Callback outcome: target text records `sub_4B8650` size `0x1d3`, final byte `0x004b8822`, `0x004b8823` non-function/padding, and successor `0x004b8830`; validator `000000007979` ok.
- [x] Refresh UID00015X behavior with tab limits, same-tab exception, rectangles, FrameChrome calls, legacy InterfaceEfx call, and external layer/context arguments. Ledger rows: C005, C006, C008, C014, C015, C016. Callback outcome: target behavior prose contains those facts at report-level detail; validator `000000007979` ok.
- [x] Refresh UID00015X callee/state evidence with accepted helper names and explicit unresolved caveats. Ledger rows: C007, C009, C010, C011, C012, C013, C020. Callback outcome: target records `RectBounds::SetLTRB`, `Pane::MarkForDeletion`, `Pane::UnregisterEventHandler`, `Pane::SetBounds`, `Pane::AddToLayer`, `Pane::SetPaneOrder`, helper `0x00544ee0` behavior, and unresolved `+0x0c`/`+0x48` no-code blockers; validator `000000007979` ok.
- [x] Refresh UID00015X caller evidence. Ledger rows: C017, C018, C019. Callback outcome: target records 35 current callers, including MapPane `0x00508040/0x00508679/0x00508cb2` and LivingObjectPane `0x005abde3/0x005abe3d/0x005abe55`; validator `000000007979` ok.
- [x] Preserve owner/source-placement and stale SpellInputPanes rejection. Ledger rows: C003, C004. Callback outcome: UID00015X remains GeneralPurposePanel-owned; stale SpellOneArgInputPane generated ownership stays rejected; SpellInputPanes and SpellOneArgInputPane required no edit.
- [x] Add/refresh [UID:0001EA] `PaneCore` support row/note for `0x00544ee0-0x00544f2e`. Ledger row: C011. Callback outcome: PaneCore states the helper's callers and behavior while keeping exact final source name and `+0x0c` unresolved; validator `000000007980` ok.
- [x] Optionally cross-link the unresolved slot caveat in [UID:0003JA] `PaneVtables` if UID00015X starts citing it. Ledger row: C013. Callback outcome: PaneVtables already had same-or-greater unresolved `+0x48` caveat; no edit.
- [x] Optionally add a short B005 support note to [UID:0000JQ]/[UID:00005Q] without changing the class declaration. Ledger rows: C003, C007, C021. Callback outcome: GeneralPurposePanel file/class notes synced with target no-code proof; class declaration unchanged; validators `000000007981` and `000000007982` ok.
- [x] Confirm [UID:0000O0]/[UID:0000DR] already reject stale Spell ownership at same-or-greater detail. Ledger row: C004. Callback outcome: already-present; no edit.
- [x] Do not manually edit generated files. Ledger row: C022. Callback outcome: no generated files were manually edited; scoped validators reported `generated_refresh: deferred`; generated freshness remains report evidence.
- [x] Run only scoped validators authorized by the implementation callback, after any by-* edit batch. Ledger rows: C001-C024. Callback outcome: validators `000000007979` through `000000007982` all exited `0` with `ok: 1`; warning-only `missing_ref_uid` notes are recorded above.
- [x] Lease only by-* files needed for the immediate implementation batch and release promptly. Ledger row: C023. Callback outcome: leased exactly four by-* callback files; release/current lease checks show no active leases.
- [x] Update the ledger verification state after callback. Ledger rows: C001-C024. Callback outcome: every row is marked `applied`, `already-present`, or `excluded-with-reason`; no accepted claim remains `proposed`.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B005","command_id":"000000007984","destination_path":"executed-b-agent-research/B005/00015X-GeneralPurposePanelSwitchActiveTab-source-quality.md","details":"report executed into central archive","event":"executed","source_path":"tools/leaser/Agents/Agent-B005/research/00015X-GeneralPurposePanelSwitchActiveTab-source-quality.md","timestamp":"2026-07-08T16:46:24-04:00","uid":"00015X"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
