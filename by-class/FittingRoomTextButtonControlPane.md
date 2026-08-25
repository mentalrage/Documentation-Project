*** UID:000055 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000JE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000JE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
// FittingRoomTextButtonControlPane emits exact child bodies through this source route.
// Current source-ready children: [UID:0004GE][0x00424020-0x0042405f.FittingRoomTextButtonControlPaneConstructor](by-memory/0x00424020-0x0042405f.FittingRoomTextButtonControlPaneConstructor.md), [UID:0004GG][0x00424080-0x0042425d.FittingRoomTextButtonControlPaneOnPaint](by-memory/0x00424080-0x0042425d.FittingRoomTextButtonControlPaneOnPaint.md), and [UID:0004GH][0x00424260-0x00424270.FittingRoomTextButtonControlPaneSetSelected](by-memory/0x00424260-0x00424270.FittingRoomTextButtonControlPaneSetSelected.md).
[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# FittingRoomTextButtonControlPane

## Status

- Confidence: strong for live method/vtable behavior, medium-high for final source placement because one ranking dialog path also instantiates the same class.
- Proposed source module: [UID:0000JE][FittingRoom](by-file/FittingRoom.md)
- Local memory core: reviewed non-emitting split/index [UID:0002SC][0x00424020-0x004242e4.FittingRoomTextButtonControlPane](by-memory/0x00424020-0x004242e4.FittingRoomTextButtonControlPane.md), with exact child pages [UID:0004GE][0x00424020-0x0042405f.FittingRoomTextButtonControlPaneConstructor](by-memory/0x00424020-0x0042405f.FittingRoomTextButtonControlPaneConstructor.md)-[UID:0004GK][0x00424290-0x004242e5.FittingRoomTextButtonControlPaneScalarDeletingDestructor](by-memory/0x00424290-0x004242e5.FittingRoomTextButtonControlPaneScalarDeletingDestructor.md).
- Base class: [UID:0000EJ][TextButtonControlPane](by-class/TextButtonControlPane.md) constructor/destructor calls at `0x00495040` and `0x00495130`.
- Evidence basis: live IDA MCP function, xref, vtable, byte-boundary, type-search, and decompilation checks through 2026-06-16.

## Generated Output Status

- Reconstructable: true. This is a source-owned fitting-room action/category button class.
- Emitter route: [UID:0000JE][FittingRoom](by-file/FittingRoom.md). The file route is high-confidence and has a valid proposed reconstruction path under `NexusTK/cashshop/`.
- Reconstruction status: class page emits a formal `[[CHILDREN]]` route marker only. Source-ready children now include [UID:0004GE][0x00424020-0x0042405f.FittingRoomTextButtonControlPaneConstructor](by-memory/0x00424020-0x0042405f.FittingRoomTextButtonControlPaneConstructor.md), which supplies `FittingRoomTextButtonControlPane::FittingRoomTextButtonControlPane(const wchar_t *label, const RectBounds *bounds)`, [UID:0004GG][0x00424080-0x0042425d.FittingRoomTextButtonControlPaneOnPaint](by-memory/0x00424080-0x0042425d.FittingRoomTextButtonControlPaneOnPaint.md), which supplies first-draft `void FittingRoomTextButtonControlPane::OnPaint()`, and [UID:0004GH][0x00424260-0x00424270.FittingRoomTextButtonControlPaneSetSelected](by-memory/0x00424260-0x00424270.FittingRoomTextButtonControlPaneSetSelected.md), which supplies `void FittingRoomTextButtonControlPane::SetSelected(bool selected)`. The broad class declaration remains deferred because final header shape, exact original color constant spellings, and the RankingDialog reuse caveat still cap source-placement confidence.

## Score Rationale

| Field | Value | Rationale |
| --- | ---: | --- |
| Completion | 88 | B005 split-first implementation creates exact child pages for constructor, non-deleting destructor body, OnPaint, `SetSelected(bool)`, two destructor adjustor thunks, and scalar deleting destructor wrapper; the class page has a formal `[[CHILDREN]]` route marker and source-ready constructor, OnPaint, and setter children while preserving no-code proofs for destructor/thunk children. |
| Confidence | 90 | MCP sessions `c9b60f19` and `supervisor_nexustk_20260709` confirm function sizes, xrefs, vtable refs, pointer facts, callees, decompilation behavior, constructor `retn 8`, paint behavior, and boundaries. Confidence remains below final because RankingDialog still constructs this class twice and no local UDT proves final field/header names or exact original paint constant spellings. |

## Role

Fitting-room action/category text-button control. Local methods initialize a resource-backed text button, draw the frame, and toggle selected visual state.

## Confirmed Methods

| Address | Method | Notes |
| --- | --- | --- |
| [UID:0004GE][0x00424020-0x0042405f.FittingRoomTextButtonControlPaneConstructor](by-memory/0x00424020-0x0042405f.FittingRoomTextButtonControlPaneConstructor.md) | constructor | Source-ready child. Fresh MCP proves two explicit parameters after `this` (`label`, `bounds`) with `retn 8`; source calls `TextButtonControlPane(label, bounds)` and initializes `m_selected(false)`. Raw derived vtable stores at `+0`, `+0xa0`, and `+0xa4` are compiler output. |
| [UID:0004GF][0x00424060-0x0042407f.FittingRoomTextButtonControlPaneNonDeletingDestructor](by-memory/0x00424060-0x0042407f.FittingRoomTextButtonControlPaneNonDeletingDestructor.md) | non-deleting destructor body | Restores the class vtables and tail-calls `TextButtonControlPane` teardown at `0x00495130`; non-emitting compiler/implicit destructor body. |
| [UID:0004GG][0x00424080-0x0042425d.FittingRoomTextButtonControlPaneOnPaint](by-memory/0x00424080-0x0042425d.FittingRoomTextButtonControlPaneOnPaint.md) | `OnPaint()` | Source-ready vtable-only paint method. Current MCP confirms range `0x00424080-0x0042425d`, vtable/data ref `0x0060e018`, no ordinary code callers, selected/pressed color swap `208/216` versus `216/208`, fill color `212`, disabled text color `134`, centered text rectangle from `m_bounds`, pushed text offset `(1,1)`, `m_textDrawMode = 1`, `m_textAlign = 1`, and `DrawTextInRect` over the `+0x10c` label pointer. |
| [UID:0004GH][0x00424260-0x00424270.FittingRoomTextButtonControlPaneSetSelected](by-memory/0x00424260-0x00424270.FittingRoomTextButtonControlPaneSetSelected.md) | `SetSelected(bool selected)` | Source-ready child. Stores the selected visual flag at `this + 0x110`; called by category rebuild and selected-button paths; emits `m_selected = selected`. |
| [UID:0004GI][0x00424270-0x0042427b.FittingRoomTextButtonControlPaneSecondaryDtorAdjustorThunk](by-memory/0x00424270-0x0042427b.FittingRoomTextButtonControlPaneSecondaryDtorAdjustorThunk.md) | adjustor thunk | Secondary-vtable `this - 0xa0` thunk to the deleting destructor wrapper; nonreconstructable compiler-generated glue. |
| [UID:0004GJ][0x0042427b-0x00424286.FittingRoomTextButtonControlPaneTertiaryDtorAdjustorThunk](by-memory/0x0042427b-0x00424286.FittingRoomTextButtonControlPaneTertiaryDtorAdjustorThunk.md) | adjustor thunk | Tertiary-vtable `this - 0xa4` thunk to the deleting destructor wrapper; nonreconstructable compiler-generated glue. |
| [UID:0004GK][0x00424290-0x004242e5.FittingRoomTextButtonControlPaneScalarDeletingDestructor](by-memory/0x00424290-0x004242e5.FittingRoomTextButtonControlPaneScalarDeletingDestructor.md) | scalar deleting destructor wrapper | Restores class vtables, calls `0x00495130`, conditionally frees with `0x004f4ac0`, and has a sized-delete path for `0x114` bytes; non-emitting deleting-wrapper glue. |

## Evidence Notes

- B005 MCP session `c9b60f19` `server_health` was OK and `lookup_funcs` resolved the split inventory: constructor `0x00424020` size `0x3f`, non-deleting destructor `0x00424060` size `0x1f`, OnPaint `0x00424080` size `0x1dd`, setter `0x00424260` size `0x10`, adjustors `0x00424270`/`0x0042427b` size `0xb` each, scalar deleting destructor `0x00424290` size `0x55`, and excluded type-code helper `0x004242f0` size `0x5`.
- B002 MCP session `supervisor_nexustk_20260709` rechecked the constructor source-quality blocker: disassembly for `0x00424020` pushes only label and bounds, calls `0x00495040`, clears `+0x110`, and returns with `retn 8`; caller checks show command/control ids feed `GetFittingRoomControlBounds`/control-manager context rather than UID0004GE constructor parameters.
- B004 UID0004GG callback uses the same current MCP session `supervisor_nexustk_20260709` for paint source readiness: `lookup_funcs(0x00424080)` size `0x1dd`, no function at `0x0042425d`, setter start at `0x00424260`, vtable-only pointer at `0x0060e018`, raw padding bytes `cc cc cc`, helper callees `SetDrawColor`/fill/`MoveTo`/`LineTo`/`InsetRect`/`OffsetRect`/`SetTextColor`/`DrawTextInRect`, and no direct code xrefs to the paint handler.
- Current B005 xrefs confirm fourteen constructor callers, including fitting-room construction/rebuild call sites and RankingDialog reuse at `0x00458828` and `0x0045886d`; setter callers are `0x0041ce6b`, `0x0041d30a`, and `0x0041d320`.
- Current B005 vtable/pointer evidence confirms paint at `0x0060e018`, secondary and tertiary destructor adjustors at `0x0060e040` and `0x0060e070`, scalar deleting destructor at `0x0060dfd4`, no pointer hits for constructor/non-deleting destructor/setter, and ten refs to the excluded shared `0x004242f0` type-code helper.
- Current B005 decompilation confirms constructor base helper `0x00495040`, selected byte `+0x110`, OnPaint state bytes `+0x101`, `+0x103`, and `+0x110`, color constants `208`, `216`, `212`, `128`, and `134`, label pointer `+0x10c`, setter byte write to `+0x110`, adjustor deltas `0xa0`/`0xa4`, and scalar deleting destructor calls to `0x00495130`, `0x004f4ac0`, and `0x0041b6a0`.
- Live IDA on 2026-06-04 confirms the local function starts and half-open ranges: `sub_424020` `0x00424020-0x0042405f`, `sub_424060` `0x00424060-0x0042407f`, `sub_424080` `0x00424080-0x0042425d`, `sub_424260` `0x00424260-0x00424270`, `sub_424270` `0x00424270-0x0042427b`, `sub_42427B` `0x0042427b-0x00424286`, and `sub_424290` `0x00424290-0x004242e5`.
- The constructor writes primary vtable `0x0060dfd4`, secondary vtable `0x0060e040` at `this + 0xa0`, tertiary vtable `0x0060e070` at `this + 0xa4`, and selected byte `this + 0x110 = 0`.
- Vtable data xrefs place `0x00424290` at `0x0060dfd4`, paint `0x00424080` at `0x0060e018`, adjustor thunk `0x00424270` at `0x0060e040`, and adjustor thunk `0x0042427b` at `0x0060e070`.
- [UID:0002CV][0x0041cdc0-0x0041d14b.FittingRoomDialogRebuildCategoryButtons](by-memory/0x0041cdc0-0x0041d14b.FittingRoomDialogRebuildCategoryButtons.md) constructs category buttons for `UsableItems`, `Weapons`, `Mounts`, `Face`, `Head`, `Mantle`, `Necklaces`, `Coats`, `Shoes`, and `SpecialtySets`; it calls the selected-state setter once for the default category.
- [UID:0002CP][0x0041bdd0-0x0041c250.FittingRoomDialogConstructor](by-memory/0x0041bdd0-0x0041c250.FittingRoomDialogConstructor.md) constructs fixed fitting-room buttons for `Basic` and `Current`.
- [UID:0002CX][0x0041d2c0-0x0041d335.FittingRoomDialogSelectButton](by-memory/0x0041d2c0-0x0041d335.FittingRoomDialogSelectButton.md) calls `0x00424260` at `0x0041d30a` and `0x0041d320` to clear the old selected button and set the new selected button.
- [UID:0000XZ][0x00458610-0x0045f9f5.RankingDialog](by-memory/0x00458610-0x0045f9f5.RankingDialog.md) also constructs this class at `0x00458828` with `RewardInfo` and at `0x0045886d` with `GetReward`.
- [UID:00024M][0x0060d794-0x0060e174.CashShopFittingRoomReadOnlyData](by-memory/0x0060d794-0x0060e174.CashShopFittingRoomReadOnlyData.md) places the class RTTI/vtable names in the fitting-room UI vtable block.

## Boundary Cautions

- The `RankingDialog` constructor reuse means this class may be a small shared text-button subclass or a fitting-room class reused by ranking code. Keep the FittingRoom parent for current autogen grouping, but do not treat source-file placement as final.
- Vtable entry `0x0060e034 -> 0x004242f0` is a separate shared type-code virtual that returns `11` and is cross-referenced by several other vtables; keep it outside this class page.
- Padding around the local core is now byte-checked: `0x0042425d-0x00424260` and `0x00424286-0x00424290` are `0xcc` alignment, and `0x004242e5-0x004242f0` / `0x004242f5-0x00424300` bracket the separate `0x004242f0` type-code helper before [UID:000056][FittingRoomUserImageControlPane](by-class/FittingRoomUserImageControlPane.md).
- Do not write a broad class declaration yet. The current formal block is only a `[[CHILDREN]]` route marker, and the exact child pages decide which method bodies emit. The constructor, `OnPaint()`, and `SetSelected(bool selected)` are source-ready; destructor and thunk bodies are not emitted for the reasons recorded on their child pages.

## 2026-06-16 A001 Evidence Refresh

Live IDA MCP on database `b001_mappane_0001AW_20260616` reconfirmed the local cluster: constructor `0x00424020` size `0x3f`, non-deleting destructor `0x00424060` size `0x1f`, paint `0x00424080` size `0x1dd`, selected-state setter `0x00424260` size `0x10`, adjustor thunks `0x00424270` and `0x0042427b` size `0xb` each, scalar deleting destructor `0x00424290` size `0x55`, and shared type-code helper `0x004242f0` size `0x5`.

`xrefs_to 0x00424020` shows fourteen constructor call sites: two fixed fitting-room buttons, ten fitting-room category buttons, and two `RankingDialog` buttons at `0x00458828` / `0x0045886d`. `xrefs_to 0x00424260` shows the selected-state setter called from category rebuild and selected-button updates. Vtable refs still bind paint at `0x0060e018`, adjustors at `0x0060e040` / `0x0060e070`, and scalar deletion at `0x0060dfd4`; `0x004242f0` has ten vtable refs across this and unrelated control families, so it remains excluded from this class body.

Decompilation confirms constructor stores primary/secondary/tertiary vtables and clears byte `+0x110`. The paint method uses state bytes `+0x101`, `+0x103`, and `+0x110`, color constants `208`, `216`, `212`, `128`, and `134`, label pointer `+0x10c`, and the shared text renderer `0x004bad70`. That 2026-06-16 pass left paint names unresolved; B004's 2026-07-09 callback resolves the method-level helper/field route for first-draft `OnPaint()` while keeping exact original palette constant names, broad header shape, and RankingDialog-vs-FittingRoom source split as confidence caps.

## Cross-References

- [UID:0000JE][FittingRoom](by-file/FittingRoom.md)
- [UID:0002SC][0x00424020-0x004242e4.FittingRoomTextButtonControlPane](by-memory/0x00424020-0x004242e4.FittingRoomTextButtonControlPane.md)
- [UID:0004GE][0x00424020-0x0042405f.FittingRoomTextButtonControlPaneConstructor](by-memory/0x00424020-0x0042405f.FittingRoomTextButtonControlPaneConstructor.md)
- [UID:0004GF][0x00424060-0x0042407f.FittingRoomTextButtonControlPaneNonDeletingDestructor](by-memory/0x00424060-0x0042407f.FittingRoomTextButtonControlPaneNonDeletingDestructor.md)
- [UID:0004GG][0x00424080-0x0042425d.FittingRoomTextButtonControlPaneOnPaint](by-memory/0x00424080-0x0042425d.FittingRoomTextButtonControlPaneOnPaint.md)
- [UID:0004GH][0x00424260-0x00424270.FittingRoomTextButtonControlPaneSetSelected](by-memory/0x00424260-0x00424270.FittingRoomTextButtonControlPaneSetSelected.md)
- [UID:0004GI][0x00424270-0x0042427b.FittingRoomTextButtonControlPaneSecondaryDtorAdjustorThunk](by-memory/0x00424270-0x0042427b.FittingRoomTextButtonControlPaneSecondaryDtorAdjustorThunk.md)
- [UID:0004GJ][0x0042427b-0x00424286.FittingRoomTextButtonControlPaneTertiaryDtorAdjustorThunk](by-memory/0x0042427b-0x00424286.FittingRoomTextButtonControlPaneTertiaryDtorAdjustorThunk.md)
- [UID:0004GK][0x00424290-0x004242e5.FittingRoomTextButtonControlPaneScalarDeletingDestructor](by-memory/0x00424290-0x004242e5.FittingRoomTextButtonControlPaneScalarDeletingDestructor.md)
- [UID:0000WR][0x0041ba40-0x004245f5.FittingRoomUiCore](by-memory/0x0041ba40-0x004245f5.FittingRoomUiCore.md)
- [UID:0002CV][0x0041cdc0-0x0041d14b.FittingRoomDialogRebuildCategoryButtons](by-memory/0x0041cdc0-0x0041d14b.FittingRoomDialogRebuildCategoryButtons.md)
- [UID:0002CX][0x0041d2c0-0x0041d335.FittingRoomDialogSelectButton](by-memory/0x0041d2c0-0x0041d335.FittingRoomDialogSelectButton.md)
- [UID:00024M][0x0060d794-0x0060e174.CashShopFittingRoomReadOnlyData](by-memory/0x0060d794-0x0060e174.CashShopFittingRoomReadOnlyData.md)
- [UID:0000XZ][0x00458610-0x0045f9f5.RankingDialog](by-memory/0x00458610-0x0045f9f5.RankingDialog.md)
- [UID:0000EJ][TextButtonControlPane](by-class/TextButtonControlPane.md)
- [UID:00001E][ButtonControlPane](by-class/ButtonControlPane.md)

## Changes

- Completion/confidence score update: existed before as `0/0`; changed to `58/64`. Summary: local fitting-room button methods and ownership cautions are documented, but class contents are intentionally incomplete because generic event/motion helpers are not strong ownership evidence. Evidence: confirmed local cluster `0x00424020-0x004242e4` and documented boundary cautions against trusting stale generated ownership alone.

- 2026-06-02 exact local-core and autogen update:
  - What existed before: score was `58/64`, reconstructable and parent metadata were blank, and the class did not have an exact memory page.
  - Changed to: score is `72/80`, reconstructable is `TRUE`, parent is [UID:0000JE][FittingRoom](by-file/FittingRoom.md), and the class now links the exact local-core page.
  - Summary/evidence: existing IDA MCP evidence in the category-button rebuild and selected-button helper pages ties the constructor and selected-state helper to fitting-room behavior, while the read-only data page confirms the class vtable block. Fresh IDA MCP calls timed out, so final C++ remains blank.

- 2026-06-04 live IDA refresh:
  - What existed before: score was `72/80` and the page still relied on earlier linked evidence because the previous direct IDA refresh had timed out; it also omitted the non-deleting destructor body and second adjustor thunk.
  - Changed to: score is `84/86`, the method inventory now includes `0x00424060-0x0042407f` and `0x0042427b-0x00424286`, the stale timeout basis is replaced with current IDA binary identity/function/xref/vtable evidence, and the RankingDialog constructor reuse is recorded as a source-placement caveat.
  - Summary/evidence: live IDA confirms the exact local starts/ranges, TextButtonControlPane constructor/destructor calls, vtable pointers at `0x0060dfd4`, `0x0060e018`, `0x0060e040`, and `0x0060e070`, FittingRoom constructor/category/select call sites, RankingDialog `RewardInfo`/`GetReward` call sites, and boundary separation from the shared `0x004242f0` type-code virtual. Final C++ remains blank because final naming/source placement and paint constants are not at the 95/95 bar.

- 2026-06-16 A001 target refresh:
  - Before: `COMPLETION:84`, `CONFIDENCE:86`.
  - After: `COMPLETION:86`, `CONFIDENCE:88`.
  - Evidence: live IDA MCP reconfirmed all local function sizes, fourteen constructor refs, selected-state setter refs, vtable refs, shared type-code fan-out, byte boundaries, and decompiled paint constants/state offsets. Source placement remains blocked after checking current xrefs and local type metadata because RankingDialog still constructs this class twice and no IDA UDT proves final field or header names.

- 2026-07-03 B005 split-first implementation callback:
  - Before: the class page had no formal route marker and treated [UID:0002SC][0x00424020-0x004242e4.FittingRoomTextButtonControlPane](by-memory/0x00424020-0x004242e4.FittingRoomTextButtonControlPane.md) as a single unresolved empty-emitter cluster.
  - Changed to: `COMPLETION:88`, `CONFIDENCE:90`, formal `[[CHILDREN]]` route marker, exact child links [UID:0004GE][0x00424020-0x0042405f.FittingRoomTextButtonControlPaneConstructor](by-memory/0x00424020-0x0042405f.FittingRoomTextButtonControlPaneConstructor.md)-[UID:0004GK][0x00424290-0x004242e5.FittingRoomTextButtonControlPaneScalarDeletingDestructor](by-memory/0x00424290-0x004242e5.FittingRoomTextButtonControlPaneScalarDeletingDestructor.md), and source-ready `SetSelected(bool selected)` routing through [UID:0004GH][0x00424260-0x00424270.FittingRoomTextButtonControlPaneSetSelected](by-memory/0x00424260-0x00424270.FittingRoomTextButtonControlPaneSetSelected.md). Broad class declaration C++ remains deferred.
  - Summary/evidence: accepted B005 report `tools/leaser/Agents/Agent-B005/research/0002SC-FittingRoomTextButtonControlPane-empty-emitter-source-quality.md`, MCP session `c9b60f19`, current function sizes/xrefs/vtable refs/pointer facts/decompilation/boundaries, RankingDialog consumer caveat, and `0x004242f0` exclusion.

- 2026-07-09 B002 UID0004GE implementation callback:
  - Before: the class route emitted only the setter child and described the constructor as blank/no-code pending source-quality base signature and parameter names.
  - Changed to: the formal `[[CHILDREN]]` route now lists source-ready constructor [UID:0004GE][0x00424020-0x0042405f.FittingRoomTextButtonControlPaneConstructor](by-memory/0x00424020-0x0042405f.FittingRoomTextButtonControlPaneConstructor.md) plus setter [UID:0004GH][0x00424260-0x00424270.FittingRoomTextButtonControlPaneSetSelected](by-memory/0x00424260-0x00424270.FittingRoomTextButtonControlPaneSetSelected.md).
  - Summary/evidence: B002 MCP session `supervisor_nexustk_20260709` confirms UID0004GE has two explicit parameters (`label`, `bounds`), calls `TextButtonControlPane` construction at `0x00495040`, clears selected byte `+0x110`, and uses compiler-generated vtable stores. RankingDialog `RewardInfo`/`GetReward` calls remain consumer reuse caveats, and no broad class declaration is promoted.

- 2026-07-09 B004 UID0004GG implementation callback:
  - Before: the class route still described OnPaint as blank/no-code pending source-quality helper, field, and color-constant names.
  - Changed to: the formal `[[CHILDREN]]` route now lists source-ready paint child [UID:0004GG][0x00424080-0x0042425d.FittingRoomTextButtonControlPaneOnPaint](by-memory/0x00424080-0x0042425d.FittingRoomTextButtonControlPaneOnPaint.md) alongside constructor and setter children.
  - Summary/evidence: B004 MCP session `supervisor_nexustk_20260709` confirms exact paint range and padding, vtable-only route at `0x0060e018`, helper callees, selected/pressed/disabled color behavior, label-centering and pushed-offset logic, text draw/alignment state writes, and generated-output stale omission. Exact original palette constant spellings and broad class/header source shape remain score caps only.
