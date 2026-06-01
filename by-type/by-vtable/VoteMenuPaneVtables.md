*** UID:0001Z1 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:78 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# VoteMenuPane Vtables

## Status

- Entity kind: vtable cluster.
- Covered class: [UID:0000FX][VoteMenuPane](by-class/VoteMenuPane.md).
- Likely source file: [UID:0000P6][VoteMenuPane](by-file/VoteMenuPane.md).
- Confidence: strong for vtable bases, constructor/destructor stores, and class-specific virtual slots.

## Vtable Bases

| Class view | Base | Constructor store | Object offset | Notes |
| --- | --- | --- | --- | --- |
| primary | `0x00622ff8` | `0x00555913` | `+0x00` | Primary `Pane` view. |
| secondary | `0x0062304c` | `0x00555919` | `+0xa0` | Mouse/input and dismiss view. |
| tertiary | `0x0062307c` | `0x00555923` | `+0xa4` | Event/update-handler view. |

The same vtables are reinstalled by the non-deleting destructor at `0x00555950-0x005559bc` and the scalar deleting destructor at `0x00556320-0x005563cd`.

## Notable Slots

| Vtable | Slot | Target | Notes |
| --- | --- | --- | --- |
| primary `0x00622ff8` | `+0x00` | `0x00556320` | `VoteMenuPane::ScalarDeletingDestructor`. |
| primary `0x00622ff8` | `+0x44` | `0x00555af0` | `OnPaint`, draws Promote/Demote labels and highlight state. |
| primary `0x00622ff8` | `+0x48` | `0x00555c70` | Background fill helper. |
| primary `0x00622ff8` | `+0x4c` | `0x00555cf0` | SUBWIN border drawing helper. |
| secondary `0x0062304c` | `+0x00` | `0x00556228` | Adjustor thunk into `0x00556320` with `this - 0xa0`. |
| secondary `0x0062304c` | `+0x04` | `0x005559c0` | `OnMouseEvent`, hit-tests rows and dispatches vote submission. |
| secondary `0x0062304c` | `+0x08` | `0x00555ae0` | Dismiss handler. |
| tertiary `0x0062307c` | `+0x00` | `0x00556233` | Adjustor thunk into `0x00556320` with `this - 0xa4`. |
| tertiary `0x0062307c` | `+0x04` | `0x00544e90` | Base/default event-update slot. |

Do not read primary `+0x50` as a `VoteMenuPane` virtual: it is RTTI metadata for the secondary table. Secondary `+0x2c` is RTTI metadata for the tertiary table, and tertiary `+0x08` falls into adjacent wide string menu text such as `Look`, `Trade`, `Info`, `Promote`, and `Demote`.

## IDA MCP Evidence

- `list_globals *VoteMenuPane*` reports vtables at `0x00622ff8`, `0x0062304c`, and `0x0062307c`, plus RTTI records at `0x0064ece0`, `0x0064ed90`, and `0x0064eda4`.
- Raw constructor disassembly at `0x005558d0-0x00555945` stores the three bases at `0x00555913`, `0x00555919`, and `0x00555923`.
- IDA xrefs to the vtable bases also report non-deleting destructor stores at `0x00555975`, `0x0055597b`, and `0x00555985`, and scalar deleting destructor stores at `0x0055634c`, `0x00556352`, and `0x0055635c`.
- `lookup_funcs` confirms modeled functions at `0x00555950`, `0x005559c0`, `0x00555ae0`, `0x00555af0`, `0x00555c70`, `0x00555cf0`, `0x00556020`, `0x00556070`, `0x00556100`, `0x00556228`, `0x00556233`, and `0x00556320`; it still reports constructor start `0x005558d0` as `Not a function`.
- `xrefs_to`/IDA `py_eval` show `0x00556070` and `0x00556100` are direct callees from `OnMouseEvent`, not vtable slots.
- Current `class_VoteMenuPane.meta_wave3` reports `vtable_count: 0`, so the generated vtable inventory is incomplete despite active source placeholders for `VoteMenuPane_vtable`, `VoteMenuPane_vtable2`, and `VoteMenuPane_vtable3`.

## Reconstruction Notes

Model `VoteMenuPane` as a `Pane`-derived menu popup with three vtable views at `+0x00`, `+0xa0`, and `+0xa4`. The hit-test and packet-submit helpers remain ordinary private helpers in the same source module, not virtual functions and not `BulletinSession` behavior.

## Cross-References

- [UID:0000FX][VoteMenuPane](by-class/VoteMenuPane.md)
- [UID:0000P6][VoteMenuPane](by-file/VoteMenuPane.md)
- [UID:0001WH][VoteMenuPaneLayout](by-type/by-struct/VoteMenuPaneLayout.md)
- [UID:0001FY][0x005558d0-0x0055606d.VoteMenuPaneCore](by-memory/0x005558d0-0x0055606d.VoteMenuPaneCore.md)
- [UID:0002LQ][0x005558d0-0x00555945.VoteMenuPaneRawConstructor](by-memory/0x005558d0-0x00555945.VoteMenuPaneRawConstructor.md)
- [UID:0002LR][0x00555950-0x005559bc.VoteMenuPaneDestructor](by-memory/0x00555950-0x005559bc.VoteMenuPaneDestructor.md)
- [UID:0001FZ][0x00556070-0x00556211.VoteMenuPaneHitTestAndSubmit](by-memory/0x00556070-0x00556211.VoteMenuPaneHitTestAndSubmit.md)
- [UID:0001G1][0x00556228-0x0055623e.VoteMenuPaneDestructorThunks](by-memory/0x00556228-0x0055623e.VoteMenuPaneDestructorThunks.md)
- [UID:0001G3][0x00556320-0x005563cd.VoteMenuPaneScalarDeletingDestructor](by-memory/0x00556320-0x005563cd.VoteMenuPaneScalarDeletingDestructor.md)
- [UID:0000N7][RightButtonMenuPane](by-file/RightButtonMenuPane.md)

## Changes

- 2026-05-31 scoring and reconstructable flag:
  - What existed before: `COMPLETION:0`, `CONFIDENCE:0`, and blank `RECONSTRUCTABLE`.
  - Changed to: `COMPLETION:78`, `CONFIDENCE:88`, and `RECONSTRUCTABLE:TRUE`.
  - Summary/evidence: IDA MCP xrefs confirm the vtable bases are installed by the raw constructor and restored by both destructor forms; lookup/decompile evidence ties the slots to the exact VoteMenuPane methods and compiler-generated adjustor thunks.
