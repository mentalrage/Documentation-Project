*** UID:000022 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:72 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:82 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000NY | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL:30 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# CheckBoxTextControlPane

## Status

- Confidence: medium-high for control behavior and reusable-control ownership; medium for exact constructor boundary.
- Likely source family: [UID:0000NY][SpecializedButtonPanes](by-file/SpecializedButtonPanes.md), a provisional `NexusTK/ui/controls/` root. A later final-source pass may still split this into `ui/controls/CheckBoxTextControlPane.cpp`.
- Current recovered file: `source-3/simroot_v2/class_CheckBoxTextControlPane.cpp`
- IDA MCP rechecked: 2026-05-24.
- Type docs: [UID:0001W7][SpecializedButtonPaneLayouts](by-type/by-struct/SpecializedButtonPaneLayouts.md), [UID:0001YW][SpecializedButtonPaneVtables](by-type/by-vtable/SpecializedButtonPaneVtables.md)
- Rebuild handling: source-authored reusable UI-control class. Marked reconstructable and attached to [UID:0000NY][SpecializedButtonPanes](by-file/SpecializedButtonPanes.md) at autogen position `30` now that the file page is a `76/82` provisional `NexusTK/ui/controls/` root. C++ remains blank because the raw constructor/source declaration is not final-audit quality.

## Class Purpose

`CheckBoxTextControlPane` is a reusable checkbox plus text label control. It stores the checked flag at offset `+0x108`, stores a 256-wide-character label buffer at `+0x10a`, paints on/off EPF tile state, draws the shadowed label text, and tears down through the base control path.

The checked state is not currently exposed through the method at `0x004214c0`; IDA decompiles that tiny vtable helper as a constant control-type return of `0x16`. The known user of the checked flag is [UID:0000A7][PartySearchEditPane](by-class/PartySearchEditPane.md), which reads and toggles offset `+0x108` directly.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| `GetControlType` | [UID:0002DZ][0x004214c0-0x004214c5.CheckBoxTextControlPaneGetControlType](by-memory/0x004214c0-0x004214c5.CheckBoxTextControlPaneGetControlType.md) | Returns constant control type `0x16`; current Wave3 summary incorrectly describes this as checked-state access. |
| `CheckBoxTextControlPane` | `0x0059ded0-0x0059df24` | Constructor-shaped bytes: calls the base control constructor with argument `8`, installs three vtable pointers, stores the initial checked flag, and copies the label. IDA does not currently model this as a function. |
| vtable/base teardown helper | `0x0059df30-0x0059df4e` | IDA-modeled helper that reinstalls `CheckBoxTextControlPane` vtables and tail-calls the base teardown path at `0x00544580`; not in the active Wave3 partition. |
| `OnPaint` | `0x0059df50-0x0059e0ab` | Draws checkbox tile and label text with shadow effect. |
| Adjustor thunks | `0x0059efeb-0x0059f000` | Secondary-base this-adjustors that forward to the scalar deleting destructor. |
| Scalar deleting destructor | `0x0059f050-0x0059f0a4` | Reinstalls class vtables, calls base teardown, and conditionally deletes the object. |

## Layout And Vtable Evidence

| Evidence | Source |
| --- | --- |
| Checked byte at `+0x108` | [UID:0001W7][SpecializedButtonPaneLayouts](by-type/by-struct/SpecializedButtonPaneLayouts.md) and [UID:0001KJ][0x0059ded0-0x0059f0a4.CheckBoxTextControlPane](by-memory/0x0059ded0-0x0059f0a4.CheckBoxTextControlPane.md) record constructor storage, paint use, and direct `PartySearchEditPane` toggling. |
| Label buffer at `+0x10a` | The constructor-shaped bytes copy a `0x100` wide-character label, and `OnPaint` scans/draws the buffer twice for shadow and foreground text. |
| Three-view vtable layout | [UID:0001YW][SpecializedButtonPaneVtables](by-type/by-vtable/SpecializedButtonPaneVtables.md) records primary `0x0062e99c`, secondary `0x0062ea04`, and tertiary `0x0062ea34`; [UID:0002OX][0x0062e998-0x0062ea3c.CheckBoxTextControlPaneVtableData](by-memory/0x0062e998-0x0062ea3c.CheckBoxTextControlPaneVtableData.md) tracks the exact `.rdata` child. |
| Control type | [UID:0002DZ][0x004214c0-0x004214c5.CheckBoxTextControlPaneGetControlType](by-memory/0x004214c0-0x004214c5.CheckBoxTextControlPaneGetControlType.md) returns constant `0x16`; it is not a checked-state getter. |

## Evidence Notes

- `source-3/simroot_v2/class_CheckBoxTextControlPane.cpp` has low active emitted-file quality (`62.7`) and active class ownership quality (`40.5`), so use it as generated evidence only.
- IDA MCP `lookup_funcs` reports no function at `0x0059ded0`, but direct disassembly there shows the constructor-shaped sequence through `retn 0Ch` at `0x0059df24`.
- IDA MCP decompilation of [UID:0002DZ][0x004214c0-0x004214c5.CheckBoxTextControlPaneGetControlType](by-memory/0x004214c0-0x004214c5.CheckBoxTextControlPaneGetControlType.md) returns constant `22`/`0x16`; it is only address-adjacent to fitting-room/string helpers and belongs to this reusable control.
- IDA MCP recognizes `0x0059df30` (`size 0x1f`), `0x0059df50` (`size 0x15c`), thunks at `0x0059efeb` and `0x0059eff6`, and scalar deleting destructor `0x0059f050` (`size 0x55`).
- `PartySearchEditPane::PartySearchEditPane` inlines equivalent checkbox/text initialization at `0x0059e22f-0x0059e265` after allocating `0x30c` bytes, which explains why `0x0059ded0` has no direct code xrefs in the current IDB.
- `PartySearchEditPane::OnAction` reads the checked flag from `+0x108` when applying hunters-list settings and toggles that byte directly for command `2`.
- 2026-05-26 IDA MCP confirmed primary vtable `0x0062e99c`, secondary vtable `0x0062ea04`, and tertiary vtable `0x0062ea34`. The paint method reads checked byte `+0x108` and label buffer `+0x10a`, and the adjustor thunks are vtable-only compiler glue into scalar deleting destructor `0x0059f050`.
- [UID:0001KJ][0x0059ded0-0x0059f0a4.CheckBoxTextControlPane](by-memory/0x0059ded0-0x0059f0a4.CheckBoxTextControlPane.md) is now the canonical executable-range page for the constructor-shaped body, paint, teardown helper, and scalar deleting destructor.
- [UID:0000NY][SpecializedButtonPanes](by-file/SpecializedButtonPanes.md) keeps this class in the reusable-control source family and now supplies the provisional `NexusTK/ui/controls/` parent path. The final direction/gender/checkbox source split is still open.
- 2026-06-03 IDA MCP recheck again reports `0x0059ded0` as `NOFUNC` with no xrefs or raw pointer hits. It reconfirmed `0x0059df30`, `0x0059df50`, `0x0059efeb`, `0x0059eff6`, and `0x0059f050` as real functions, primary vtable slots `0x0062e99c+0x44 -> 0x0059df50`, `+0x60 -> 0x004214c0`, and `+0x00 -> 0x0059f050`, plus constructor/teardown/inline/destructor vtable store refs at `0x0059defc`, `0x0059df30`, `0x0059e23f`, and `0x0059f056`.

## Score Rationale

| Field | Value | Rationale |
| --- | ---: | --- |
| Completion | 72 | The class purpose, method inventory, fields, vtables, out-of-range type helper, PartySearch use, and generated-data caveats are now documented with stable UID links. |
| Confidence | 82 | Confidence is strong for behavior, field offsets, vtable identity, and ownership as a reusable control. It is capped because the constructor start is still raw/non-IDA-modeled and the final source-file split is unresolved. |
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

## Changes

- 2026-05-30: Existing class doc mentioned `0x004214c0` as an address-only helper. Changed it to the exact by-memory UID page and clarified that the helper is reusable checkbox-control code, not fitting-room or SimpleUString ownership. Evidence: IDA MCP decompilation/data refs for `0x004214c0` and the split of the historical `0x00421310-0x004216cb` aggregate.
- 2026-06-02 reconstructable evidence update:
  - What existed before: the class page was scored `60/78`, reconstructable metadata was blank, and newer memory/type evidence was only partially reflected.
  - Changed to: scored `72/82`, marked reconstructable, added layout/vtable and score-rationale sections, and linked the exact vtable-data child.
  - Summary/evidence: [UID:0001KJ][0x0059ded0-0x0059f0a4.CheckBoxTextControlPane](by-memory/0x0059ded0-0x0059f0a4.CheckBoxTextControlPane.md), [UID:0001W7][SpecializedButtonPaneLayouts](by-type/by-struct/SpecializedButtonPaneLayouts.md), [UID:0001YW][SpecializedButtonPaneVtables](by-type/by-vtable/SpecializedButtonPaneVtables.md), and [UID:0000NY][SpecializedButtonPanes](by-file/SpecializedButtonPanes.md) now provide stronger documented evidence while preserving the unresolved raw-constructor and final source-split caveats.
- 2026-06-03 parent attachment update:
  - Before: `AUTOGEN_PARENT_UID` was blank because the likely file parent was below the 80+ confidence threshold and had no projected path.
  - Changed to: `AUTOGEN_PARENT_UID:0000NY` and position `30`; reconstruction C++ remains blank.
  - Summary/evidence: [UID:0000NY][SpecializedButtonPanes](by-file/SpecializedButtonPanes.md) is now a `76/82` provisional `NexusTK/ui/controls/` parent after a fresh IDA MCP recheck reconfirmed checkbox/text vtable/function evidence while preserving the raw constructor caveat.
