*** UID:000022 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:85 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:87 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000NY | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL:30 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# CheckBoxTextControlPane

## Status

- Confidence: strong for control behavior, vtables, field use, paint, destructor, and reusable-control ownership; medium for the raw constructor start and final source split.
- Likely source family: [UID:0000NY][SpecializedButtonPanes](by-file/SpecializedButtonPanes.md), a provisional `NexusTK/ui/controls/` root. A later final-source pass may still split this into `ui/controls/CheckBoxTextControlPane.cpp`.
- IDA MCP rechecked: 2026-06-05.
- Type docs: [UID:0001W7][SpecializedButtonPaneLayouts](by-type/by-struct/SpecializedButtonPaneLayouts.md), [UID:0001YW][SpecializedButtonPaneVtables](by-type/by-vtable/SpecializedButtonPaneVtables.md)
- Rebuild handling: source-authored reusable UI-control class. Marked reconstructable and attached to [UID:0000NY][SpecializedButtonPanes](by-file/SpecializedButtonPanes.md) at autogen position `30` as a provisional `NexusTK/ui/controls/` root. C++ remains blank because the raw constructor/source declaration is not final-audit quality.

## Class Purpose

`CheckBoxTextControlPane` is a reusable checkbox plus text label control. It stores the checked flag at offset `+0x108`, stores a 256-wide-character label buffer at `+0x10a`, paints on/off EPF tile state, draws the shadowed label text, and tears down through the base control path.

The checked state is not currently exposed through the method at `0x004214c0`; IDA decompiles that tiny vtable helper as a constant control-type return of `0x16`. The known user of the checked flag is [UID:0000A7][PartySearchEditPane](by-class/PartySearchEditPane.md), which reads and toggles offset `+0x108` directly.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| `GetControlType` | [UID:0002DZ][0x004214c0-0x004214c5.CheckBoxTextControlPaneGetControlType](by-memory/0x004214c0-0x004214c5.CheckBoxTextControlPaneGetControlType.md) | Returns constant control type `0x16`; vtable slot evidence shows this is not a checked-state accessor. |
| `CheckBoxTextControlPane` | `0x0059ded0-0x0059df25` | Raw constructor-shaped bytes ending in `retn 0Ch`: calls the base control constructor with argument `8`, installs three vtables, stores the initial checked flag, and copies the label. IDA does not currently model this as a function. |
| vtable/base teardown helper | `0x0059df30-0x0059df4f` | IDA-modeled helper that reinstalls `CheckBoxTextControlPane` vtables and tail-calls the base teardown path at `0x00544580`. |
| `OnPaint` | `0x0059df50-0x0059e0ac` | Draws checkbox tile and label text with shadow effect, selecting tile state from the checked byte. |
| Adjustor thunks | `0x0059efeb-0x0059f001` | Secondary-base this-adjustors subtract `0xa0` and `0xa4`, then forward to the scalar deleting destructor. |
| Scalar deleting destructor | `0x0059f050-0x0059f0a5` | Reinstalls class vtables, calls base teardown, and conditionally deletes the `0x30c`-byte object. |

## Layout And Vtable Evidence

| Evidence | Source |
| --- | --- |
| Checked byte at `+0x108` | [UID:0001W7][SpecializedButtonPaneLayouts](by-type/by-struct/SpecializedButtonPaneLayouts.md) and [UID:0001KJ][0x0059ded0-0x0059f0a4.CheckBoxTextControlPane](by-memory/0x0059ded0-0x0059f0a4.CheckBoxTextControlPane.md) record constructor storage, paint use, and direct `PartySearchEditPane` toggling. |
| Label buffer at `+0x10a` | The constructor-shaped bytes copy a `0x100` wide-character label, and `OnPaint` scans/draws the buffer twice for shadow and foreground text. |
| Three-view vtable layout | [UID:0001YW][SpecializedButtonPaneVtables](by-type/by-vtable/SpecializedButtonPaneVtables.md) records primary `0x0062e99c`, secondary `0x0062ea04`, and tertiary `0x0062ea34`; [UID:0002OX][0x0062e998-0x0062ea3c.CheckBoxTextControlPaneVtableData](by-memory/0x0062e998-0x0062ea3c.CheckBoxTextControlPaneVtableData.md) tracks the exact `.rdata` child. |
| Control type | [UID:0002DZ][0x004214c0-0x004214c5.CheckBoxTextControlPaneGetControlType](by-memory/0x004214c0-0x004214c5.CheckBoxTextControlPaneGetControlType.md) returns constant `0x16`; it is not a checked-state getter. |

## Evidence Notes

- 2026-06-05 live IDA MCP reports `0x0059ded0` still has no function object or xrefs, but direct disassembly shows a complete constructor-shaped sequence through `retn 0Ch` at `0x0059df24`.
- The raw constructor calls `sub_4949E0` with argument `8`, stores the checked byte from `[ebp+8]` at `+0x108`, copies the input wide string into `+0x10a` with `_wcscpy_s` and a `0x100` wide-character count, and writes the three class vtables at `0x0059defc`, `0x0059df02`, and `0x0059df0c`.
- IDA MCP decompilation of [UID:0002DZ][0x004214c0-0x004214c5.CheckBoxTextControlPaneGetControlType](by-memory/0x004214c0-0x004214c5.CheckBoxTextControlPaneGetControlType.md) returns constant `22`/`0x16`; it is only address-adjacent to fitting-room/string helpers and belongs to this reusable control.
- IDA recognizes `0x0059df30-0x0059df4f`, `0x0059df50-0x0059e0ac`, `0x0059efeb-0x0059eff6`, `0x0059eff6-0x0059f001`, and `0x0059f050-0x0059f0a5` as functions.
- `0x0059df30` reinstalls the three class vtables and jumps to `sub_544580`. `0x0059f050` reinstalls the same vtables, calls `sub_544580`, and applies deleting flags through `sub_4F4AC0` or the guarded `0x30c`-byte delete path.
- `OnPaint` resolves `ON` resources through [UID:0000QU][g_pEPFLib](by-global/g_pEPFLib.md) / `dword_67A744`, scans the `+0x10a` label twice for shadow/foreground text drawing, checks byte `+0x108`, and selects the checkbox tile before rendering through `sub_4B9980`.
- `PartySearchEditPane::PartySearchEditPane` inlines equivalent checkbox/text setup at `0x0059e22f-0x0059e265`, writing the same three vtables, storing byte `+0x108`, and copying the label `Put me on the hunters list`.
- `PartySearchEditPane::OnAction` reads the checked flag from `+0x108` when applying hunters-list settings and toggles that byte directly for command `2`.
- 2026-06-05 IDA MCP confirmed the vtable block: RTTI at `0x0062e998`, primary destructor slot `0x0062e99c -> sub_59F050`, paint slot `0x0062e9e0 -> sub_59DF50`, control-type slot `0x0062e9fc -> sub_4214C0`, secondary adjustor `0x0062ea04 -> sub_59EFEB`, and tertiary adjustor `0x0062ea34 -> sub_59EFF6`.
- Vtable-base xrefs tie the class to the raw constructor, the teardown helper, the PartySearch inline setup in `sub_59E0D0`, the scalar deleting destructor, and two surrounding inlined setup sites in `sub_59BC90`.
- [UID:0001KJ][0x0059ded0-0x0059f0a4.CheckBoxTextControlPane](by-memory/0x0059ded0-0x0059f0a4.CheckBoxTextControlPane.md) is now the canonical executable-range page for the constructor-shaped body, paint, teardown helper, and scalar deleting destructor.
- [UID:0000NY][SpecializedButtonPanes](by-file/SpecializedButtonPanes.md) keeps this class in the reusable-control source family and now supplies the provisional `NexusTK/ui/controls/` parent path. The final direction/gender/checkbox source split is still open.

## B001-006 Parent-Gate Audit

This class now clears the active `85/85` direct-parent gate for [UID:0002DZ][0x004214c0-0x004214c5.CheckBoxTextControlPaneGetControlType](by-memory/0x004214c0-0x004214c5.CheckBoxTextControlPaneGetControlType.md). Existing documentation was treated as a hypothesis and rechecked against IDA MCP where relevant:

- IDA MCP `decompile 0x004214c0` returns constant `22`/`0x16` and has no callees, matching a control-type virtual slot rather than a checked-state accessor.
- The 2026-06-10 B001 xref audit reports `0x004214c0` has 12 vtable data refs and no ordinary direct code callers; the refs include the `CheckBoxTextControlPane` primary vtable slot at `0x0062e9fc -> 0x004214c0`.
- [UID:0001YW][SpecializedButtonPaneVtables](by-type/by-vtable/SpecializedButtonPaneVtables.md) documents the `CheckBoxTextControlPane` primary vtable at `0x0062e99c`, with destructor `0x0059f050`, paint `0x0059df50`, control-type slot `0x004214c0`, and secondary/tertiary adjustor slots.
- The class page already records live IDA evidence for constructor-shaped bytes at `0x0059ded0-0x0059df24`, modeled teardown helper `0x0059df30`, paint `0x0059df50`, adjustor thunks `0x0059efeb`/`0x0059eff6`, and scalar deleting destructor `0x0059f050`.
- Checked-state ownership is separated from the type helper: byte `+0x108` is read/toggled by `PartySearchEditPane` and read by `OnPaint`; `0x004214c0` only returns the static control-type value.

## Score Rationale

| Field | Value | Rationale |
| --- | ---: | --- |
| Completion | 85 | The class purpose, method inventory, fields, vtables, out-of-range type helper, PartySearch use, raw constructor caveat, paint/destructor behavior, parent attachment, and direct parent-gate evidence for the `0x004214c0` control-type helper are now documented with live IDA evidence. |
| Confidence | 87 | Confidence is strong for behavior, field offsets, vtable identity, destructor/adjustor slots, and ownership as a reusable control. It is capped below final-source confidence because the constructor start is still raw/non-IDA-modeled and the final source-file split is unresolved. |
| Reconstructable | true | The class represents source-authored control behavior. C++ remains blank until constructor boundaries, inherited layout names, and final source placement are audited together. |

## Cross-References

- [UID:0000NY][SpecializedButtonPanes](by-file/SpecializedButtonPanes.md)
- [UID:000021][CheckBoxControlPane](by-class/CheckBoxControlPane.md)
- [UID:0000A7][PartySearchEditPane](by-class/PartySearchEditPane.md)
- [UID:0002DZ][0x004214c0-0x004214c5.CheckBoxTextControlPaneGetControlType](by-memory/0x004214c0-0x004214c5.CheckBoxTextControlPaneGetControlType.md)
- [UID:0001KJ][0x0059ded0-0x0059f0a4.CheckBoxTextControlPane](by-memory/0x0059ded0-0x0059f0a4.CheckBoxTextControlPane.md)
- [UID:0001KI][0x0059bc90-0x0059f25b.UserListDialogPaneAndUserListPane](by-memory/0x0059bc90-0x0059f25b.UserListDialogPaneAndUserListPane.md)
- [UID:0001W7][SpecializedButtonPaneLayouts](by-type/by-struct/SpecializedButtonPaneLayouts.md)
- [UID:0001YW][SpecializedButtonPaneVtables](by-type/by-vtable/SpecializedButtonPaneVtables.md)
- [UID:0002OX][0x0062e998-0x0062ea3c.CheckBoxTextControlPaneVtableData](by-memory/0x0062e998-0x0062ea3c.CheckBoxTextControlPaneVtableData.md)
- [UID:0000QU][g_pEPFLib](by-global/g_pEPFLib.md)

## Changes

- 2026-06-07 A005 resolved-name cleanup:
  - Before: the paint-resource evidence used only the historical `dword_67A744` label.
  - After: the page records resolved name `g_pEPFLib` beside the historical label and cross-links the global page.
  - Evidence: generated resolved-name report maps `dword_67A744` to `g_pEPFLib`; existing page evidence already ties the reference to EPF checkbox resource lookup.
- 2026-05-30: Existing class doc mentioned `0x004214c0` as an address-only helper. Changed it to the exact by-memory UID page and clarified that the helper is reusable checkbox-control code, not fitting-room or SimpleUString ownership. Evidence: IDA MCP decompilation/data refs for `0x004214c0` and the split of the historical `0x00421310-0x004216cb` aggregate.
- 2026-06-02 reconstructable evidence update:
  - What existed before: the class page was scored `60/78`, reconstructable metadata was blank, and newer memory/type evidence was only partially reflected.
  - Changed to: scored `72/82`, marked reconstructable, added layout/vtable and score-rationale sections, and linked the exact vtable-data child.
  - Summary/evidence: [UID:0001KJ][0x0059ded0-0x0059f0a4.CheckBoxTextControlPane](by-memory/0x0059ded0-0x0059f0a4.CheckBoxTextControlPane.md), [UID:0001W7][SpecializedButtonPaneLayouts](by-type/by-struct/SpecializedButtonPaneLayouts.md), [UID:0001YW][SpecializedButtonPaneVtables](by-type/by-vtable/SpecializedButtonPaneVtables.md), and [UID:0000NY][SpecializedButtonPanes](by-file/SpecializedButtonPanes.md) now provide stronger documented evidence while preserving the unresolved raw-constructor and final source-split caveats.
- 2026-06-03 parent attachment update:
  - Before: `AUTOGEN_PARENT_UID` was blank because the likely file parent was below the 80+ confidence threshold and had no projected path.
  - Changed to: `AUTOGEN_PARENT_UID:0000NY` and position `30`; reconstruction C++ remains blank.
  - Summary/evidence: [UID:0000NY][SpecializedButtonPanes](by-file/SpecializedButtonPanes.md) is now a `76/82` provisional `NexusTK/ui/controls/` parent after a fresh IDA MCP recheck reconfirmed checkbox/text vtable/function evidence while preserving the raw constructor caveat.
- 2026-06-05 live IDA refinement:
  - What existed before: the class page had `72/82` scores and documented the broad behavior, but still carried stale evidence wording and did not spell out the live constructor rows, vtable slots, paint behavior, destructor flags, or inline setup proof.
  - Changed to: scores `82/86`, updated method extents, removed stale source-quality caveats, and added direct live IDA evidence for the raw constructor body, modeled functions, vtable slots, PartySearch inline setup, and destructor/adjustor behavior.
  - Summary/evidence: completion increased because the documented surface now covers the constructor-shaped body, paint, teardown helper, scalar deleting destructor, adjustors, control-type slot, field offsets, and vtable store sites. Confidence increased because live IDA MCP disassembly/xrefs confirm the class identity while still preserving the raw-constructor and final source-split caps. C++ remains blank because the constructor is not an IDA function and the class declaration is not yet 95/95 quality.
- 2026-06-10 B001-006 split-gate repair: Raised scores from `82/86` to `85/87` so [UID:0002DZ][0x004214c0-0x004214c5.CheckBoxTextControlPaneGetControlType](by-memory/0x004214c0-0x004214c5.CheckBoxTextControlPaneGetControlType.md) has a direct parent that clears the active `85/85` gate. Evidence: IDA MCP rechecked `0x004214c0` as a no-callee `return 22` helper, vtable xrefs include `0x0062e9fc -> 0x004214c0`, and existing class evidence covers the constructor-shaped body, paint, teardown, destructor, adjustor slots, checked-byte field, and label buffer while retaining final-source caveats.
