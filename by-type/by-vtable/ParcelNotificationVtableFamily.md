*** UID:0001YE | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# Parcel Notification Vtable Family

## Status

- Disposition: vtable inventory for reconstructable parcel notification UI code.
- Covered source owner: [UID:0000MF][ParcelPane](by-file/ParcelPane.md)
- Covered classes: [UID:0000A5][ParcelIconPane](by-class/ParcelIconPane.md), [UID:0000A6][ParcelPane](by-class/ParcelPane.md), and [UID:000058][FlyingParcelPane](by-class/FlyingParcelPane.md)
- Layout docs: [UID:0001VI][ParcelNotificationPaneLayouts](by-type/by-struct/ParcelNotificationPaneLayouts.md)
- Exact vtable-data range: [UID:0002OH][0x00621bb0-0x00621d50.ParcelNotificationVtableData](by-memory/0x00621bb0-0x00621d50.ParcelNotificationVtableData.md)
- Confidence: strong for table bases, slot extents, destructor slots, and secondary/tertiary adjustor thunks.
- Verification: IDA MCP `list_globals`, `lookup_funcs`, `xrefs_to`, `disasm`, and `py_eval` checks on 2026-05-26; IDA MCP `py_eval` recheck of exact vtable-data dwords, string boundaries, data xrefs, and function extents on 2026-06-01. Generated `simroot_v2` was used only as provisional comparison.

## Table Bases

| Class | Object offset | Vtable symbol | Address | First slot | Extent |
| --- | --- | --- | --- | --- | --- |
| `ParcelIconPane` | `+0x00` | `??_7ParcelIconPane@@6B@` | `0x00621bb4` | `0x00546f40` | slots `+0x00..+0x44` |
| `ParcelIconPane` | `+0xa0` | `??_7ParcelIconPane@@6B@_0` | `0x00621c00` | `0x00546ea1` | slots `+0x00..+0x28` |
| `ParcelIconPane` | `+0xa4` | `??_7ParcelIconPane@@6B@_1` | `0x00621c30` | `0x00546eac` | slots `+0x00..+0x04` |
| `ParcelPane` | `+0x00` | `??_7ParcelPane@@6B@` | `0x00621c3c` | `0x00547000` | slots `+0x00..+0x4c` |
| `ParcelPane` | `+0xa0` | `??_7ParcelPane@@6B@_0` | `0x00621c90` | `0x00546eb7` | slots `+0x00..+0x28` |
| `ParcelPane` | `+0xa4` | `??_7ParcelPane@@6B@_1` | `0x00621cc0` | `0x00546ec2` | slots `+0x00..+0x04` |
| `FlyingParcelPane` | `+0x00` | `??_7FlyingParcelPane@@6B@` | `0x00621ccc` | `0x00546ed0` | slots `+0x00..+0x44` |
| `FlyingParcelPane` | `+0xa0` | `??_7FlyingParcelPane@@6B@_0` | `0x00621d18` | `0x00546e8b` | slots `+0x00..+0x28` |
| `FlyingParcelPane` | `+0xa4` | `??_7FlyingParcelPane@@6B@_1` | `0x00621d48` | `0x00546e96` | slots `+0x00..+0x04` |

## Slot Evidence

| Class/table | Slot | Target | Interpretation |
| --- | --- | --- | --- |
| `ParcelIconPane` primary | `+0x00` | `0x00546f40` | Scalar deleting destructor. |
| `ParcelIconPane` primary | `+0x04..+0x44` | `0x004f4b10`, `0x0041b6c0`, `0x004b8e20`, `0x0041d680`, `0x00544730`, `0x00544750`, `0x005447a0`, `0x00544800`, `0x00544a20`, `0x00544b80`, `0x00544bd0`, `0x00544c70`, `0x00544cb0`, `0x00544ce0`, `0x00544d30`, `0x00544d70`, `0x0041b6a0` | Inherited pane/base interface slots. |
| `ParcelIconPane` secondary | `+0x00` | `0x00546ea1` | Adjustor thunk subtracting `0xa0`, then jumping to `0x00546f40`. |
| `ParcelIconPane` secondary | `+0x10` | `0x005461c0` | Parcel packet/update callback; decodes parcel counts and forwards to the child `ParcelPane`. |
| `ParcelIconPane` tertiary | `+0x00` | `0x00546eac` | Adjustor thunk subtracting `0xa4`, then jumping to `0x00546f40`. |
| `ParcelIconPane` tertiary | `+0x04` | `0x00544e90` | Inherited handler-interface slot. |
| `ParcelPane` primary | `+0x00` | `0x00547000` | Scalar deleting destructor. |
| `ParcelPane` primary | `+0x44` | `0x00546890` | `ParcelPane` paint/draw virtual. |
| `ParcelPane` primary | `+0x48` | `0x00546970` | Parcel animation counter helper. |
| `ParcelPane` primary | `+0x4c` | `0x005469e0` | Parcel frame-index helper. |
| `ParcelPane` secondary | `+0x00` | `0x00546eb7` | Adjustor thunk subtracting `0xa0`, then jumping to `0x00547000`. |
| `ParcelPane` secondary | `+0x04` | `0x00546610` | Mouse-event virtual. |
| `ParcelPane` secondary | `+0x08` | `0x005465e0` | Key-event virtual. |
| `ParcelPane` tertiary | `+0x00` | `0x00546ec2` | Adjustor thunk subtracting `0xa4`, then jumping to `0x00547000`. |
| `ParcelPane` tertiary | `+0x04` | `0x00546810` | Timer/animation virtual. |
| `FlyingParcelPane` primary | `+0x00` | `0x00546ed0` | Scalar deleting destructor. |
| `FlyingParcelPane` primary | `+0x44` | `0x00546df0` | Draws parcel/letter sprites. |
| `FlyingParcelPane` secondary | `+0x00` | `0x00546e8b` | Adjustor thunk subtracting `0xa0`, then jumping to `0x00546ed0`. |
| `FlyingParcelPane` tertiary | `+0x00` | `0x00546e96` | Adjustor thunk subtracting `0xa4`, then jumping to `0x00546ed0`. |
| `FlyingParcelPane` tertiary | `+0x04` | `0x00546d70` | Animation-step virtual. |

## Extent Notes

Do not read these short tertiary tables past slot `+0x04`.

- `ParcelIconPane` tertiary table at `0x00621c30` ends before `0x00621c38`, where `ParcelPane` RTTI begins.
- `ParcelPane` tertiary table at `0x00621cc0` ends before `0x00621cc8`, where `FlyingParcelPane` RTTI begins.
- `FlyingParcelPane` tertiary table at `0x00621d48` ends before `0x00621d50`, where adjacent wide string data begins. The dwords after `0x00621d50` decode from strings such as `ALERTBTN.EPF`, not virtual slots.

This adjacency explains generated false rows such as a `FlyingParcelPane` method at `0x00420054`: that value is read from string/data bytes after the real `FlyingParcelPane` tertiary vtable, not from a valid vtable slot.

## Constructor and Destructor Store Evidence

IDA `xrefs_to` reports the vtable stores below:

- `ParcelIconPane` constructor `0x00545e40`, non-deleting destructor `0x00546070`, and scalar deleting destructor `0x00546f40` write `0x00621bb4`, `0x00621c00`, and `0x00621c30`.
- `ParcelIconPane` constructor also writes the child `ParcelPane` vtables at `0x00545f27`, `0x00545f2d`, and `0x00545f37` while constructing the embedded/owned notification child.
- `ParcelPane` constructor `0x00546290`, non-deleting destructor `0x00546440`, and scalar deleting destructor `0x00547000` write `0x00621c3c`, `0x00621c90`, and `0x00621cc0`.
- `FlyingParcelPane` constructor `0x00546ac0`, raw cleanup body `0x00546b80`, and scalar deleting destructor `0x00546ed0` write `0x00621ccc`, `0x00621d18`, and `0x00621d48`. Current IDA does not wrap `0x00546b80` as a function, but raw disassembly confirms the same vtable-write cleanup pattern.

## Wave3 Data Issue

Active `simroot_v2` omits several real parcel-family bodies or misreads adjacent data:

- `class_ParcelIconPane.cpp` omits the constructor `0x00545e40` and parcel callback `0x005461c0`.
- `class_ParcelPane.cpp` omits the non-deleting destructor `0x00546440`.
- `class_FlyingParcelPane.cpp` omits the raw cleanup body `0x00546b80` and animation-start/configure body `0x00546bc0`.
- Disabled `class_FlyingParcelPane.cpp` emits a false `0x00420054` method from post-vtable string/data and marks `0x00546e8b` missing even though IDA disassembly confirms a normal adjustor thunk.

These are tracked in [wave3 data issues](../../wave3_data_issues.md).

## Cross References

- [UID:0002OH][0x00621bb0-0x00621d50.ParcelNotificationVtableData](by-memory/0x00621bb0-0x00621d50.ParcelNotificationVtableData.md)
- [UID:0001EH][0x00545e40-0x005470ac.ParcelNotificationPanes](by-memory/0x00545e40-0x005470ac.ParcelNotificationPanes.md)
- [UID:0001VI][ParcelNotificationPaneLayouts](by-type/by-struct/ParcelNotificationPaneLayouts.md)
- [UID:0001EM][0x00546e8b-0x00546ecd.ParcelNotificationAdjustorThunks](by-memory/0x00546e8b-0x00546ecd.ParcelNotificationAdjustorThunks.md)
- [UID:0001EL][0x00546b80-0x00546d64.FlyingParcelPaneRawLifecycleAndStart](by-memory/0x00546b80-0x00546d64.FlyingParcelPaneRawLifecycleAndStart.md)
- [UID:0001EN][0x00546ed0-0x00546f36.FlyingParcelPaneScalarDeletingDestructor](by-memory/0x00546ed0-0x00546f36.FlyingParcelPaneScalarDeletingDestructor.md)
- [UID:0001YC][PaneCoreVtableFamily](by-type/by-vtable/PaneCoreVtableFamily.md)

## Changes

- 2026-06-01:
  - What existed before: this vtable-family page had strong table/slot evidence, but the validator-tracked completion/confidence header remained `0/0` and there was no exact `by-memory` child for the `0x00621bb0-0x00621d50` parcel notification vtable island.
  - Changed to: scored the page as a strong but non-final vtable inventory, marked it reconstructable, and linked [UID:0002OH][0x00621bb0-0x00621d50.ParcelNotificationVtableData](by-memory/0x00621bb0-0x00621d50.ParcelNotificationVtableData.md) as the exact address-range evidence page.
  - Summary/evidence: IDA MCP `py_eval` on 2026-06-01 read the RTTI/vtable dwords from `0x00621bb0` through `0x00621d50`, confirmed constructor/destructor data xrefs to each vtable base, confirmed the adjustor thunk/function extents, and verified that `0x00621b98-0x00621bb0` is `LINE001.EPD` string data while `0x00621d50` starts `ALERTBTN.EPF` string data.
