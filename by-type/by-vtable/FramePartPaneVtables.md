*** UID:0003I3 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:89 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:93 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:00005I | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# FramePartPane Vtables

## Status

- Current role: source-local by-vtable page for the `FramePartPane` primary, secondary, and tertiary pane views.
- Direct owner: [UID:00005I][FramePartPane](by-class/FramePartPane.md).
- Source context: [UID:0000JL][FrameChrome](by-file/FrameChrome.md).
- Exact backing data: [UID:0002NH][0x0061a7f8-0x0061a880.FramePartPaneVtableData](by-memory/0x0061a7f8-0x0061a880.FramePartPaneVtableData.md).
- Split source: [UID:0001XO][FrameChromeVtableFamily](by-type/by-vtable/FrameChromeVtableFamily.md) mixed aggregate.

## Layout

The exact `FramePartPane` vtable cluster at `0x0061a7f8-0x0061a880` is `0x88` bytes / decimal 136 bytes (Verified with int_convert.py). It contains the primary, secondary, and tertiary RTTI/vtable views for the same class.

| View | RTTI / locator | Vtable base | Key slots |
| --- | --- | --- | --- |
| Primary | `0x0061a7f8` | `0x0061a7fc` | slot `+0x00 -> 0x004b75b0` scalar deleting destructor; slot `+0x08 -> 0x004b73b0` `goog` notification handler; slot `+0x44 -> 0x004b7410` frame-part paint method. |
| Secondary | `0x0061a844` | `0x0061a848` | slot `+0x00 -> 0x004b7590`, an adjustor thunk subtracting `0xa0` / decimal 160 (Verified with int_convert.py) before dispatching to the destructor path. |
| Tertiary | `0x0061a874` | `0x0061a878` | slot `+0x00 -> 0x004b759b`, an adjustor thunk subtracting `0xa4` / decimal 164 (Verified with int_convert.py); inherited/default slot `+0x04 -> 0x00544e90`. |

The cluster is `0x88` bytes and stops before exact RectBounds constant child [UID:00040U][0x0061a880-0x0061a884.RectBoundsQuarterScaleConstant](by-memory/0x0061a880-0x0061a884.RectBoundsQuarterScaleConstant.md) and the `GeneralPurposePanel` vtable neighborhood.

## 2026-06-12 A004 IDA Recheck

Live IDA MCP session `b001_nexustk` for `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe` reconfirmed this page's direct class ownership and split boundary:

- `entity_query` over `0x0061a7f8-0x0061a890` reports `??_7FramePartPane@@6B@` at `0x0061a7fc`, `??_7FramePartPane@@6B@_0` at `0x0061a848`, `??_7FramePartPane@@6B@_1` at `0x0061a878`, and the next `GeneralPurposePanel` vtable name at `0x0061a888`.
- `lookup_funcs` reports target sizes: scalar deleting destructor `0x004b75b0` size `0xb1`, notification handler `0x004b73b0` size `0x51`, paint method `0x004b7410` size `0x70`, adjustor thunk `0x004b7590` size `0x0b`, adjustor thunk `0x004b759b` size `0x0b`, and inherited/default slot `0x00544e90` size `0x05`.
- `trace_data_flow backward` reports primary vptr stores at `0x004b74b5`, `0x004b754c`, and `0x004b75dc`; secondary stores at `0x004b74bb`, `0x004b7552`, and `0x004b75e2`; and tertiary stores at `0x004b74c5`, `0x004b755c`, and `0x004b75ec`.
- `trace_data_flow backward 0x0061a880` reports `dword_61A880 == 0x3e800000` and data refs at `0x004b7b15` and `0x004b7b43`, proving the vtable cluster ends before the RectBounds quarter-scale constant child [UID:00040U][0x0061a880-0x0061a884.RectBoundsQuarterScaleConstant](by-memory/0x0061a880-0x0061a884.RectBoundsQuarterScaleConstant.md) and the following `GeneralPurposePanel` RTTI/vtable data.
- `make_signature_for_range 0x0061a7f8-0x0061a880` produced a unique `0x88` / decimal 136-byte signature (Verified with int_convert.py):
  `10 7C 64 00 B0 75 4B 00 10 4B 4F 00 B0 73 4B 00 20 8E 4B 00 80 D6 41 00 30 47 54 00 50 47 54 00 A0 47 54 00 00 48 54 00 20 4A 54 00 80 4B 54 00 D0 4B 54 00 70 4C 54 00 B0 4C 54 00 E0 4C 54 00 30 4D 54 00 70 4D 54 00 10 74 4B 00 6C 7C 64 00 90 75 4B 00 B0 4D 54 00 C0 4D 54 00 D0 4D 54 00 E0 4D 54 00 F0 4D 54 00 00 4E 54 00 F0 89 4A 00 10 4E 54 00 30 4E 54 00 70 4E 54 00 80 7C 64 00 9B 75 4B 00 90 4E 54 00`.

## Assignment Decision

`AUTOGEN_PARENT_UID` is [UID:00005I][FramePartPane](by-class/FramePartPane.md). This child is `89/93`, the direct class parent is `85/89`, and the source-file parent [UID:0000JL][FrameChrome](by-file/FrameChrome.md) is `86/85`, so the strict child/direct-parent gate clears.

This page should not attach directly to [UID:0000JL][FrameChrome](by-file/FrameChrome.md) or the mixed [UID:0001XO][FrameChromeVtableFamily](by-type/by-vtable/FrameChromeVtableFamily.md). The direct owner is the `FramePartPane` class.

## Reconstruction Notes

The rebuilt project should emit these vtables from the `FramePartPane` class declaration, inherited pane interfaces, and normal destructor/notification/paint definitions. Do not hand-port the dwords or adjustor thunks as handwritten source.

## Cross-References

- [UID:00005I][FramePartPane](by-class/FramePartPane.md)
- [UID:0000JL][FrameChrome](by-file/FrameChrome.md)
- [UID:0001XO][FrameChromeVtableFamily](by-type/by-vtable/FrameChromeVtableFamily.md)
- [UID:0002NH][0x0061a7f8-0x0061a880.FramePartPaneVtableData](by-memory/0x0061a7f8-0x0061a880.FramePartPaneVtableData.md)
- [UID:00040U][0x0061a880-0x0061a884.RectBoundsQuarterScaleConstant](by-memory/0x0061a880-0x0061a884.RectBoundsQuarterScaleConstant.md)
- [UID:00015O][0x004b73b0-0x004b7661.FramePartPane](by-memory/0x004b73b0-0x004b7661.FramePartPane.md)
- [UID:00015P][0x004b7590-0x004b75a6.FramePartPaneAdjustorThunks](by-memory/0x004b7590-0x004b75a6.FramePartPaneAdjustorThunks.md)

## UID0000JL Accepted Split Incorporation - 2026-08-25

- This page is the exact source-local type child for FramePartPane's primary/secondary/tertiary family over [UID:0002NH][0x0061a7f8-0x0061a880.FramePartPaneVtableData](by-memory/0x0061a7f8-0x0061a880.FramePartPaneVtableData.md), not a duplicate of the mixed FrameChrome index.
- Exact bases, lifecycle stores, virtual callback/paint slots, scalar wrapper, and adjustor relationships are owned semantically by [UID:00005I][FramePartPane](by-class/FramePartPane.md) and routed through [UID:000578][FramePartPane](by-file/FramePartPane.md).
- Formal CPP/H and emitter stay blank because the complete class declaration generates the compiler tables. No raw vtable/RTTI source or empty-emitter marker is valid.

## Changes

- 2026-08-25 UID0000JL callback: removed the invalid emitter, retained class ownership, and documented the UID000578 source route and exact generated no-code disposition.

- 2026-06-12 A004 Batch 323:
  - Created this exact source-local child from the former mixed [UID:0001XO][FrameChromeVtableFamily](by-type/by-vtable/FrameChromeVtableFamily.md) aggregate.
  - Summary/evidence: live IDA MCP reconfirmed the three decorated vtable bases, slot target sizes, constructor/destructor/scalar-destructor vptr stores, `0x0061a880` non-vtable successor boundary, unique range signature, and direct class parent gate.
