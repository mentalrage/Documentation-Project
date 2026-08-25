*** UID:0003IR | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:93 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:00009M | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:00009M | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL:60 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
// [UID:0003IR] NumericStringControlPane's three vtable views are covered by the
// [UID:00009M][NumericStringControlPane](by-class/NumericStringControlPane.md) class declaration and virtual method definitions; the compiler
// generates their RTTI, slot layout, deleting wrapper, and adjustor entries.
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# NumericStringControlPane Vtables

## Status

- Current role: source-local by-vtable page for the `NumericStringControlPane` primary, secondary, and tertiary control views.
- Direct owner: [UID:00009M][NumericStringControlPane](by-class/NumericStringControlPane.md).
- Source context: [UID:0000M2][NumericStringControlPane](by-file/NumericStringControlPane.md).
- Exact backing data: [UID:0002OD][0x0061838c-0x00618430.NumericStringControlPaneVtableData](by-memory/0x0061838c-0x00618430.NumericStringControlPaneVtableData.md).
- Split source: [UID:0001YA][NumericRectangleControlPaneVtables](by-type/by-vtable/NumericRectangleControlPaneVtables.md) mixed aggregate.
- Rebuild handling: `source-declared/generated-binary`; reconstruct the `NumericStringControlPane` class declaration and virtual methods, not the vtable dwords as handwritten data.
- Callback disposition: the exact covered-by marker above participates in deterministic source order at position `60`, after the source-level methods and scalar-wrapper disposition but before the raw vtable-data marker. The compiler remains solely responsible for the RTTI, all three table views, deleting wrapper, and adjustor entries.
- Evidence-session note: MCP database session `59c7e90d` was healthy when B002 collected the UID00011M callback evidence on 2026-07-13; this is a time-scoped observation, not a claim about present session availability.

## Layout

The exact `NumericStringControlPane` vtable cluster at `0x0061838c-0x00618430` is `0xa4` bytes / decimal 164 bytes (Verified with int_convert.py). It contains the primary, secondary, and tertiary RTTI/vtable views for the same class.

| View | RTTI / locator | Vtable base | Key slots |
| --- | --- | --- | --- |
| Primary | `0x0061838c` | `0x00618390` | slot `+0x00 -> 0x0049b2f0` scalar deleting destructor; slot `+0x44 -> 0x00499a50` source-facing `OnPaint`; slots `+0x48` through `+0x5c` are shared local control-family helpers; slot `+0x60 -> 0x0041d690` terminal/control-family slot. |
| Secondary | `0x006183f4` | `0x006183f8` | slot `+0x00 -> 0x0049af7f`, an adjustor thunk subtracting `0xa0` / decimal 160 (Verified with int_convert.py); slot `+0x1c -> 0x004a89f0` shared secondary-view pane/control support. |
| Tertiary | `0x00618424` | `0x00618428` | slot `+0x00 -> 0x0049af8a`, an adjustor thunk subtracting `0xa4` / decimal 164 (Verified with int_convert.py); inherited/default slot `+0x04 -> 0x00544e90`. |

The primary view occupies `0x68` bytes / decimal 104 bytes from RTTI through the final primary slot, the secondary view occupies `0x30` bytes / decimal 48 bytes, and the tertiary view occupies `0x0c` bytes / decimal 12 bytes (Verified with int_convert.py). The cluster starts after the `TargetOptionEditControlPane` tertiary table at `0x00618384` and ends at `0x00618430`, where `RectangleControlPane` primary RTTI begins.

## 2026-06-12 A004 IDA Recheck

Live IDA MCP session `b001_nexustk` for `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe` reconfirmed this page's direct class ownership and split boundary:

- `entity_query` over `0x00618380-0x006184e0` reports `??_7NumericStringControlPane@@6B@` at `0x00618390`, `??_7NumericStringControlPane@@6B@_0` at `0x006183f8`, and `??_7NumericStringControlPane@@6B@_1` at `0x00618428`; predecessor `TargetOptionEditControlPane` is at `0x00618384`, and successor `RectangleControlPane` begins at `0x00618434`.
- `lookup_funcs` reports target sizes: constructor `0x00499910` size `0xb1`, non-deleting destructor `0x004999d0` size `0x7e`, render virtual `0x00499a50` size `0x197`, scalar deleting destructor `0x0049b2f0` size `0xbf`, and adjustor thunks `0x0049af7f`/`0x0049af8a` size `0x0b` each.
- `trace_data_flow backward` reports primary vptr stores at `0x00499951`, `0x004999fb`, and `0x0049b322`; secondary stores at `0x00499957`, `0x00499a01`, and `0x0049b328`; and tertiary stores at `0x00499961`, `0x00499a0b`, and `0x0049b332`.
- `make_signature_for_range 0x0061838c-0x00618430` produced a unique `0xa4` / decimal 164-byte signature (Verified with int_convert.py) beginning `68 5F 64 00 F0 B2 49 00 10 4B 4F 00 C0 B6 41 00` and ending `DC 5F 64 00 8A AF 49 00 90 4E 54 00`.

## Assignment Decision

`AUTOGEN_PARENT_UID` is [UID:00009M][NumericStringControlPane](by-class/NumericStringControlPane.md). This child is scored `90/93`, the direct class parent is `92/93`, and the source-file parent [UID:0000M2][NumericStringControlPane](by-file/NumericStringControlPane.md) is `92/92`, so the strict child/direct-parent gate clears.

This page should not attach directly to [UID:0000M2][NumericStringControlPane](by-file/NumericStringControlPane.md) or the mixed [UID:0001YA][NumericRectangleControlPaneVtables](by-type/by-vtable/NumericRectangleControlPaneVtables.md). The direct semantic owner is the `NumericStringControlPane` class.

## Reconstruction Notes

The rebuilt project should emit these vtables from the `NumericStringControlPane` class declaration, inherited pane/control interfaces, and normal destructor/`OnPaint` definitions. The formal marker records that source coverage without duplicating a raw table definition. Do not hand-port the dwords, RTTI locators, scalar deleting wrapper, or adjustor thunks as handwritten source; those are compiler ABI products of the class hierarchy and source-level virtual methods.

## Cross-References

- [UID:0001YA][NumericRectangleControlPaneVtables](by-type/by-vtable/NumericRectangleControlPaneVtables.md)
- [UID:00009M][NumericStringControlPane](by-class/NumericStringControlPane.md)
- [UID:0000M2][NumericStringControlPane](by-file/NumericStringControlPane.md)
- [UID:0002OD][0x0061838c-0x00618430.NumericStringControlPaneVtableData](by-memory/0x0061838c-0x00618430.NumericStringControlPaneVtableData.md)
- [UID:00011M][0x00499910-0x00499be7.NumericStringControlPaneCore](by-memory/0x00499910-0x00499be7.NumericStringControlPaneCore.md)
- [UID:000121][0x0049af7f-0x0049af95.NumericStringControlPaneAdjustorThunks](by-memory/0x0049af7f-0x0049af95.NumericStringControlPaneAdjustorThunks.md)

## Changes

- 2026-07-13 B002 UID00011M implementation callback:
  - Raised the page from `88/93` to `90/93`, assigned covered-marker position `60`, and inserted the accepted source-declared/generated-binary marker.
  - Preserved all three exact table views, RTTI addresses, slot/store evidence, boundaries, and compiler-ABI disposition; synchronized the source-facing virtual name to `OnPaint` and the accepted class/file scores.
- 2026-06-12 A004 Batch 331:
  - Created this exact source-local child from the former mixed [UID:0001YA][NumericRectangleControlPaneVtables](by-type/by-vtable/NumericRectangleControlPaneVtables.md) aggregate.
  - Summary/evidence: live IDA MCP reconfirmed the three decorated vtable bases, slot target sizes, constructor/destructor/scalar-destructor vptr stores, unique range signature, predecessor/successor boundaries, and direct class parent gate.
