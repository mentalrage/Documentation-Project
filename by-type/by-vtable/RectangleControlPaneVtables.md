*** UID:0003IT | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:96 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000BT | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:FALSE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# RectangleControlPane Vtables

## Status

- Current role: source-local by-vtable page for the `RectangleControlPane` primary, secondary, and tertiary control views.
- Direct owner: [UID:0000BT][RectangleControlPane](by-class/RectangleControlPane.md).
- Source context: [UID:0000N1][RectangleControlPane](by-file/RectangleControlPane.md).
- Exact backing data: [UID:0002OE][0x00618430-0x006184d4.RectangleControlPaneVtableData](by-memory/0x00618430-0x006184d4.RectangleControlPaneVtableData.md).
- Split source: [UID:0001YA][NumericRectangleControlPaneVtables](by-type/by-vtable/NumericRectangleControlPaneVtables.md) mixed aggregate.
- Rebuild handling: non-reconstructable compiler-generated binary; reconstruct the `RectangleControlPane` class declaration and authored virtual methods, never the vtable dwords as handwritten data.

## Layout

The exact `RectangleControlPane` vtable cluster at `0x00618430-0x006184d4` is `0xa4` bytes / decimal 164 bytes (Verified with int_convert.py). It contains the primary, secondary, and tertiary RTTI/vtable views for the same class.

| View | RTTI / locator | Vtable base | Key slots |
| --- | --- | --- | --- |
| Primary | `0x00618430` | `0x00618434` | 25 slots; `+0x00 -> 0x0049b490` scalar deleting destructor; `+0x44 -> 0x00499d00` `OnPaint`; `+0x48` through `+0x5c` shared control-family helpers; `+0x60 -> 0x0049b8f0` `HitTestPart(int,int)` returning `21`. |
| Secondary | `0x00618498` | `0x0061849c` | 11 slots; `+0x00 -> 0x0049afc1`, an adjustor thunk subtracting `0xA0`; `+0x1c -> 0x004a89f0` shared secondary-view support. |
| Tertiary | `0x006184c8` | `0x006184cc` | 2 slots; `+0x00 -> 0x0049afcc`, an adjustor thunk subtracting `0xA4`; inherited/default `+0x04 -> 0x00544e90`. |

The primary view occupies `0x68` bytes / decimal 104 bytes from RTTI through the final primary slot, the secondary view occupies `0x30` bytes / decimal 48 bytes, and the tertiary view occupies `0x0c` bytes / decimal 12 bytes (Verified with int_convert.py). The cluster starts immediately after the `NumericStringControlPane` tertiary table and ends at `0x006184d4`, where `CheckBoxControlPane` primary RTTI begins.

## 2026-06-12 A004 IDA Recheck

Live IDA MCP session `b001_nexustk` for `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe` reconfirmed this page's direct class ownership and split boundary:

- `entity_query` over `0x00618380-0x006184e0` reports `??_7RectangleControlPane@@6B@` at `0x00618434`, `??_7RectangleControlPane@@6B@_0` at `0x0061849c`, and `??_7RectangleControlPane@@6B@_1` at `0x006184cc`; predecessor `NumericStringControlPane` ends before `0x00618430`, and successor `CheckBoxControlPane` begins at `0x006184d8`.
- `lookup_funcs` reports target sizes: constructor `0x00499c60` size `0x72`, non-deleting destructor helper `0x00499ce0` size `0x1f`, `OnPaint` `0x00499d00` size `0x37`, scalar deleting destructor `0x0049b490` size `0x55`, `HitTestPart` `0x0049b8f0` size `0x05`, and adjustor thunks `0x0049afc1`/`0x0049afcc` size `0x0b` each.
- `trace_data_flow backward` reports primary vptr stores at `0x00499c9f`, `0x00499ce0`, and `0x0049b496`; secondary stores at `0x00499ca5`, `0x00499ce6`, and `0x0049b49c`; and tertiary stores at `0x00499caf`, `0x00499cf0`, and `0x0049b4a6`.
- `make_signature_for_range 0x00618430-0x006184d4` produced a unique `0xa4` / decimal 164-byte signature (Verified with int_convert.py) beginning `F0 5F 64 00 90 B4 49 00 10 4B 4F 00 C0 B6 41 00` and ending `64 60 64 00 CC AF 49 00 90 4E 54 00`.

## Assignment Decision

Current metadata is `94/96`, `CANONICAL_OWNER:0000BT`, `RECONSTRUCTABLE:FALSE`, and blank `EMITTER_UIDS`. [UID:0000BT][RectangleControlPane](by-class/RectangleControlPane.md) is the exact class-attribution owner, while the compiler emits the vtables from that class declaration; this by-vtable page does not emit handwritten source. The current direct class owner and source-file route [UID:0000N1][RectangleControlPane](by-file/RectangleControlPane.md) are each `94/95`.

This page should not use [UID:0000N1][RectangleControlPane](by-file/RectangleControlPane.md) or mixed [UID:0001YA][NumericRectangleControlPaneVtables](by-type/by-vtable/NumericRectangleControlPaneVtables.md) as its direct semantic owner. The class is the exact attribution owner and compiler source cause; the file remains the next source context, and this compiler-generated child has no emitter.

## Reconstruction Notes

The rebuilt project should emit these vtables from the `RectangleControlPane` class declaration, inherited pane/control interfaces, and normal destructor/`OnPaint`/`HitTestPart` definitions. UID0004HL supplies the authored out-of-line empty ordinary destructor source. UID000125 and UID000122 remain compiler-generated deleting-wrapper/adjustor evidence, not handwritten methods. Do not hand-port vtable dwords, vptr stores, inherited Pane teardown, deleting flags, or adjustor thunks as source.

## 2026-07-14 Destructor Route Recheck

- The three complete-object locators at `0x00645ff0`, `0x00646050`, and `0x00646064` encode view offsets `0`, `0xa0`, and `0xa4`. The class hierarchy descriptor at `0x00646004` has seven bases: RectangleControlPane, ControlPane, Pane, GrafPort, LObject, EventHandler, and TimerHandler.
- Constructor, UID0004HL ordinary destructor, and UID000125 scalar wrapper form exact store triads to each of the three vtable bases. This is construction/destruction view maintenance, not three separate human destructor bodies.
- The primary slot selects UID000125; secondary and tertiary slots select UID000122 adjustors subtracting `0xa0` and `0xa4`. These are compiler routes generated from class destructor semantics.
- UID0004HL itself is not a vtable slot and has no direct start xref, raw pointer, or constructor-EH route. Its standalone source-island placement between constructor and OnPaint, plus a same-layout CheckBoxControlPane comparator with no standalone ordinary destructor, supports an authored out-of-line empty source definition.
- Current state is `94/96`, owner `0000BT`, `RECONSTRUCTABLE:FALSE`, blank emitter/position/formal C++, with all slot and boundary detail preserved. The dated 2026-07-14 state was `88/93`, UID0000BT owner/emitter, reconstructable true, and is retained only as superseded history. Historical helper/default uncertainty is superseded for UID0004HL's source cause; generated-binary vtable handling remains compiler-owned and non-emitting.

## Cross-References

- [UID:0001YA][NumericRectangleControlPaneVtables](by-type/by-vtable/NumericRectangleControlPaneVtables.md)
- [UID:0000BT][RectangleControlPane](by-class/RectangleControlPane.md)
- [UID:0000N1][RectangleControlPane](by-file/RectangleControlPane.md)
- [UID:0002OE][0x00618430-0x006184d4.RectangleControlPaneVtableData](by-memory/0x00618430-0x006184d4.RectangleControlPaneVtableData.md)
- [UID:00011Q][0x00499c60-0x00499d37.RectangleControlPaneCore](by-memory/0x00499c60-0x00499d37.RectangleControlPaneCore.md)
- [UID:000122][0x0049afc1-0x0049afd7.RectangleControlPaneAdjustorThunks](by-memory/0x0049afc1-0x0049afd7.RectangleControlPaneAdjustorThunks.md)

## 2026-08-16 B006 Source-Cause And Layout Reconciliation

- Backing range [UID:0002OE][0x00618430-0x006184d4.RectangleControlPaneVtableData](by-memory/0x00618430-0x006184d4.RectangleControlPaneVtableData.md) is exactly `[0x00618430,0x006184d4)`, 164 bytes, SHA256 `BE245C307949282DC57E5EB938C0FA85DDB5A50AC43F8EA58FF8BA47A4A6E277`.
- Primary/secondary/tertiary views contain 25, 11, and 2 function slots. Their complete-object-locator offsets are `0`, `0xA0`, and `0xA4`, matching the complete, EventHandler, and TimerHandler object views and the class's `0x108` complete size.
- RTTI hierarchy is RectangleControlPane, ControlPane, Pane, GrafPort, LObject, EventHandler, TimerHandler. The primary table routes scalar destruction, `OnPaint`, and `HitTestPart`; secondary tables route the two compiler adjustors.
- Historical type-id wording for the primary `+0x60` slot is superseded by the exact `HitTestPart(int,int)` interpretation. The fixed result `21` is a hit-part code, and sibling same-slot overrides return `20` and `18`.
- This page and [UID:0002OE][0x00618430-0x006184d4.RectangleControlPaneVtableData](by-memory/0x00618430-0x006184d4.RectangleControlPaneVtableData.md) retain class ownership only to document compiler cause. Both are non-reconstructable/non-emitting with blank formal code because [UID:0000BT][RectangleControlPane](by-class/RectangleControlPane.md)'s inheritance and virtual declarations are the only human source required.

## Changes

- 2026-07-14 B001 UID0004HL support update:
  - Replaced stale `AUTOGEN_PARENT_UID` prose with current canonical-owner/emitter terminology while preserving all metadata and scores.
  - Added exact COL offsets, hierarchy, constructor/ordinary/scalar store triads, deleting-wrapper/adjustor routes, ordinary-source evidence, and explicit no-handwritten-vtable/compiler-helper policy.

- 2026-06-12 A004 Batch 331:
  - Created this exact source-local child from the former mixed [UID:0001YA][NumericRectangleControlPaneVtables](by-type/by-vtable/NumericRectangleControlPaneVtables.md) aggregate.
  - Summary/evidence: live IDA MCP reconfirmed the three decorated vtable bases, slot target sizes, constructor/helper/destructor vptr stores, paint/type-id slot targets, unique range signature, predecessor/successor boundaries, and direct class parent gate.
