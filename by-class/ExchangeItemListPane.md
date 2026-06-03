*** UID:00004S | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:78 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000J9 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# ExchangeItemListPane

## Status

- Likely source file: [UID:0000J9][ExchangeDialog](by-file/ExchangeDialog.md)
- Address range: [UID:00014K][0x004ac8a0-0x004ae4b6.ExchangeDialog](by-memory/0x004ac8a0-0x004ae4b6.ExchangeDialog.md), plus shared list-pane destructor [UID:0000ZR][0x0047ea50-0x0047ea8b.SharedListPaneScalarDeletingDestructor](by-memory/0x0047ea50-0x0047ea8b.SharedListPaneScalarDeletingDestructor.md)
- Current recovered file: `source-3/simroot_v2/class_ExchangeItemListPane.cpp`
- Confidence: strong for role, row layout, vtable slots, and raw helper byte boundaries; medium for final original helper names.

## Class Purpose

`ExchangeItemListPane` is the private row list used by `ExchangeDialog` for local and remote offered items. Each row stores an item slot/key byte, item id, color byte, and wide item name. The draw path renders the item image and name in the exchange list.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| `ScalarDeletingDestructor` | [UID:0000ZR][0x0047ea50-0x0047ea8b.SharedListPaneScalarDeletingDestructor](by-memory/0x0047ea50-0x0047ea8b.SharedListPaneScalarDeletingDestructor.md) | Shared list-pane scalar deleting destructor target; also used by `MyItemListPane` and related list panes. |
| adjustor thunks | [UID:0000ZP][0x0047e855-0x0047e947.DialogAndAlertDestructorAdjustorThunks](by-memory/0x0047e855-0x0047e947.DialogAndAlertDestructorAdjustorThunks.md) | Compiler-generated secondary/tertiary deleting-destructor thunks; ignore for handwritten source. |
| `ExchangeItemListPane` | [UID:00014Q][0x004ae060-0x004ae0a4.ExchangeItemListPaneRawConstructor](by-memory/0x004ae060-0x004ae0a4.ExchangeItemListPaneRawConstructor.md) | Raw non-IDA constructor. Calls `ListPane(0x206, 8, 0x9c, 0x18, 0, 1, 1)` and installs three vtable views. |
| `UpsertOfferItemRaw` | [UID:00014R][0x004ae0b0-0x004ae167.ExchangeItemListPaneRawUpsertHelper](by-memory/0x004ae0b0-0x004ae167.ExchangeItemListPaneRawUpsertHelper.md) | Raw non-IDA helper. Finds/removes an existing row with the same key, then inserts a row containing key, item id, color, and name. |
| `FindOfferItemRaw` | [UID:00014S][0x004ae170-0x004ae1ac.ExchangeItemListPaneRawFindHelper](by-memory/0x004ae170-0x004ae1ac.ExchangeItemListPaneRawFindHelper.md) | Raw non-IDA helper. Returns the row index for a key byte or `-1`. |
| `Noop` | `0x004ae1b0-0x004ae1b3` | Null virtual helper referenced from the primary vtable at `0x00619e40`. |
| `DrawItemEntry` | `0x004ae1c0-0x004ae4b6` | Draws item glyphs with high-res/low-res branches and then draws the wide item name at x=50; primary vtable slot at `0x00619e48`. |

## Evidence Notes

- The main `ExchangeDialog` constructor creates two list instances through the same constructor bytes at `0x004ae060`.
- `DrawItemEntry` reads item id from row `+2`, item color from row `+4`, and the row name from `+6`.
- `0x004ae0b0` and `0x004ae170` are raw function bodies in IDA memory but not IDA function objects. They are listed here because their row layout matches `DrawItemEntry` and the exchange packet item update logic.
- The raw upsert helper extends through the duplicate-row branch block at `0x004ae156-0x004ae167`; older notes ending at `0x004ae153` were too short.
- 2026-05-26 IDA vtable checks show `0x0047ea50` is not exclusive to `ExchangeItemListPane`; [UID:00008W][MyItemListPane](by-class/MyItemListPane.md) also points its primary destructor slot at this target. Keep feature ownership based on constructors/draw methods, not this shared scalar destructor alone.
- 2026-06-03 IDA MCP `py_eval` confirms exact exclusive raw helper ends: constructor `0x004ae060-0x004ae0a4`, upsert helper `0x004ae0b0-0x004ae167`, find helper `0x004ae170-0x004ae1ac`, null virtual `0x004ae1b0-0x004ae1b3`, and draw virtual `0x004ae1c0-0x004ae4b6`.
- The same IDA pass confirms alignment padding after each raw/helper body: twelve `0xcc` bytes at `0x004ae0a4-0x004ae0b0`, nine at `0x004ae167-0x004ae170`, four at `0x004ae1ac-0x004ae1b0`, thirteen at `0x004ae1b3-0x004ae1c0`, and ten at `0x004ae4b6-0x004ae4c0`.
- IDA named vtable data in [UID:00025A][0x00619d2c-0x0061a3c8.ExchangeItemReadOnlyData](by-memory/0x00619d2c-0x0061a3c8.ExchangeItemReadOnlyData.md) shows `ExchangeItemListPane` vtable views at `0x00619dc8`, `0x00619e50`, and `0x00619e80`; `0x00619e40` points to `nullsub_29`, and `0x00619e48` points to the draw method at `0x004ae1c0`.
- IDA xrefs to the primary vtable pointer `0x00619dc8` come from `ExchangeDialog` constructor stores at `0x004acbef` and `0x004acd9c`, and from this raw constructor at `0x004ae083`, matching the two list instances plus class-local construction path.

## Cross-References

- [UID:0000J9][ExchangeDialog](by-file/ExchangeDialog.md)
- [UID:00004R][ExchangeDialog](by-class/ExchangeDialog.md)
- [UID:00014K][0x004ac8a0-0x004ae4b6.ExchangeDialog](by-memory/0x004ac8a0-0x004ae4b6.ExchangeDialog.md)
- [UID:0000ZR][0x0047ea50-0x0047ea8b.SharedListPaneScalarDeletingDestructor](by-memory/0x0047ea50-0x0047ea8b.SharedListPaneScalarDeletingDestructor.md)
- [UID:00014Q][0x004ae060-0x004ae0a4.ExchangeItemListPaneRawConstructor](by-memory/0x004ae060-0x004ae0a4.ExchangeItemListPaneRawConstructor.md)
- [UID:00014R][0x004ae0b0-0x004ae167.ExchangeItemListPaneRawUpsertHelper](by-memory/0x004ae0b0-0x004ae167.ExchangeItemListPaneRawUpsertHelper.md)
- [UID:00014S][0x004ae170-0x004ae1ac.ExchangeItemListPaneRawFindHelper](by-memory/0x004ae170-0x004ae1ac.ExchangeItemListPaneRawFindHelper.md)
- [UID:00025A][0x00619d2c-0x0061a3c8.ExchangeItemReadOnlyData](by-memory/0x00619d2c-0x0061a3c8.ExchangeItemReadOnlyData.md)
- [UID:0001RA][exchange-dialog-resources](by-resource/exchange-dialog-resources.md)

## Changes

- 2026-05-30:
  - Before: completion/confidence metadata was left at unevaluated `0/0`.
  - After: scored as `72/76`.
  - Summary/evidence: row-list role, raw constructor/upsert/find helpers, draw method, shared destructor caveat, row layout evidence, and exchange-dialog ownership are documented; confidence remains limited by raw non-IDA helper boundaries.
- 2026-06-03 IDA range/vtable pass:
  - Before: class page stayed at `72/76`, unparented, with raw helper ranges named by final-byte addresses and incomplete vtable slot evidence.
  - Changed to: `78/84`, `RECONSTRUCTABLE:TRUE`, and `AUTOGEN_PARENT_UID:0000J9`.
  - Summary/evidence: IDA MCP proved exact exclusive helper ranges, byte padding, real null/draw virtual function objects, all three `ExchangeItemListPane` vtable views, and vtable pointer stores from both `ExchangeDialog` constructor paths plus the raw constructor. C++ remains blank because helper names/source spelling are below the 95+ gate.
