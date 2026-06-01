*** UID:0001VZ | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:78 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# ScrollCollectionPane Layout

## Status

- Entity kind: class/object layout notes.
- Covered class: [UID:0000CG][ScrollCollectionPane](by-class/ScrollCollectionPane.md)
- Likely source file: [UID:0000NG][ScrollCollectionPane](by-file/ScrollCollectionPane.md), or final merge into [UID:0000NF][ScrollBar](by-file/ScrollBar.md)
- Confidence: strong for offsets used by IDA-confirmed methods; medium for final field names.

## Layout Hypothesis

`ScrollCollectionPane` follows the common pane multiple-inheritance shape:

| Offset | Type | Name hypothesis | Evidence |
| --- | --- | --- | --- |
| `+0x00` | vtable pointer | primary pane view | Constructor stores vtable `0x00623fa4`. |
| `+0x44` | `RECT` | bounds/display rect | Draw, hit-test, and rectangle helpers read the pane rect at `this + 68`. |
| `+0xa0` | vtable pointer | secondary pane-data view | Constructor stores vtable `0x00623ff0`. |
| `+0xa4` | vtable pointer / embedded update view | effect/update interface view | Constructor stores vtable `0x00624020`; interaction helpers call scheduler methods through `this + 0xa4`. |
| `+0xf8` | int16 | scrollbar size/table index | Constructor initializes the low word to `0`; draw, hit-test, and part-rect helpers read `*(__int16 *)(this + 0xf8)` as an index into the scrollbar size table. |
| `+0xfa` | byte/word tail | unresolved initialized state | Constructor initializes this byte through the `0x00010000` dword store at `+0xf8`; no final field name yet. |
| `+0xfb` | byte | drag-position override flag | Draw and rectangle helpers test `*(byte *)(this + 0xfb)` before using drag-offset coordinates instead of the stored scroll position. |
| `+0xfc` | byte | orientation | Constructor copies the orientation argument here; helpers branch on this byte. |
| `+0xfe` | int16 | scroll position | `SetScrollPosition` compares/stores `this[127]`; drag helpers read old position here. |
| `+0x100` | int16 | max scroll range | `SetMaxRange` compares/stores `this[128]`; part-rect helpers require it to be positive. |
| `+0x102` | byte | enabled flag | Constructor stores low byte `1`; `EnableScrollbar` sets this byte before invalidation. |
| `+0x103` | byte | highlighted part | Constructor stores `0xff`; raw highlight helpers update and invalidate this part. |
| `+0x104` | byte | active/pressed part | Constructor stores `0xff`; input/update helpers clear and test this field. |
| `+0x108` | `POINT` | drag point/offset | Constructor zeroes this point; raw interaction helper stores cursor offset from thumb origin. |

The object size is at least `0x110`; allocation sites construct it as a pane-derived scrollbar object, matching the sibling [UID:0000CL][ScrollNewGroupPane](by-class/ScrollNewGroupPane.md) layout pattern.

## IDA MCP Evidence

- Constructor decompilation at `0x00561db0` stores the orientation byte at `+0xfc`, zeroes `+0xfe/+0x100`, initializes `+0xf8` with `0x00010000`, sets `+0x102` to `1`, sets `+0x103` and `+0x104` to `0xff`, and zeroes the point at `+0x108`.
- IDA MCP `lookup_funcs` on 2026-05-31 confirms the function boundaries in the associated memory island, including the modeled functions at `0x00561db0`, `0x00561ec0`, `0x00561f20`, `0x00561f50`, `0x00562bf0`, `0x00562fb0`, and `0x00563070`, and the raw/not-modeled helper starts at `0x00562e80`, `0x00562ef0`, and `0x00563200`.
- `SetMaxRange` at `0x00561ec0` reads/writes `+0x100` and clamps `+0xfe` when the range shrinks.
- `SetScrollPosition` at `0x00561f20` reads/writes `+0xfe`.
- `GetScrollRegionRect` at `0x00562bf0`, `UpdateDragScroll` at `0x00562fb0`, and `UpdatePositionFromCursor` at `0x00563070` all use the `+0xfc` orientation, `+0xfe` position, `+0x100` range, `+0x102` enabled, and `+0x108` drag state.
- IDA MCP xrefs to vtable bases `0x00623fa4`, `0x00623ff0`, and `0x00624020` point to constructor stores at `0x00561e01`, `0x00561e07`, and `0x00561e11`.

## Reconstruction Notes

Use stable offset names in source comments until the broader scrollbar family is compared. The same field pattern appears in [UID:0000CL][ScrollNewGroupPane](by-class/ScrollNewGroupPane.md), so a shared base/helper struct is possible but not proven.

## Cross-References

- [UID:0000CG][ScrollCollectionPane](by-class/ScrollCollectionPane.md)
- [UID:0000NG][ScrollCollectionPane](by-file/ScrollCollectionPane.md)
- [UID:0001GT][0x00561db0-0x0056325b.ScrollCollectionPane](by-memory/0x00561db0-0x0056325b.ScrollCollectionPane.md)
- [UID:0001YP][ScrollCollectionPaneVtables](by-type/by-vtable/ScrollCollectionPaneVtables.md)
- [UID:0000CL][ScrollNewGroupPane](by-class/ScrollNewGroupPane.md)

## Changes

- 2026-05-31: Changed completion/confidence from `0/0` to `78/84`, marked reconstructable, and split the prior `+0xf8` dword description into better-supported subfields.
  - Before: The page was ungraded and described `+0xf8` as a vague dword size/index state.
  - After: The page records `+0xf8` as the 16-bit scrollbar size-table index, calls out adjacent initialized/drag-state bytes at `+0xfa/+0xfb`, and records 2026-05-31 IDA evidence for vtable stores and helper boundaries.
  - Evidence: IDA MCP `lookup_funcs`, `decompile`, raw disassembly of `0x00562e80/0x00562ef0`, and `xrefs_to` checks for `0x00623fa4`, `0x00623ff0`, and `0x00624020`.
