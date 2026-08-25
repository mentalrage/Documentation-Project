*** UID:0003I2 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:93 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:000005 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# AboveFrame Vtables

## Status

- Current role: source-local by-vtable page for the `AboveFrame` primary, secondary, and tertiary pane views.
- Direct owner: [UID:000005][AboveFrame](by-class/AboveFrame.md).
- Source context: [UID:0000JL][FrameChrome](by-file/FrameChrome.md).
- Exact backing data: [UID:0002NG][0x00610ed8-0x00610f60.AboveFrameVtableData](by-memory/0x00610ed8-0x00610f60.AboveFrameVtableData.md).
- Split source: [UID:0001XO][FrameChromeVtableFamily](by-type/by-vtable/FrameChromeVtableFamily.md) mixed aggregate.

## Layout

The exact `AboveFrame` vtable cluster at `0x00610ed8-0x00610f60` is `0x88` bytes / decimal 136 bytes (Verified with int_convert.py). It contains the primary, secondary, and tertiary RTTI/vtable views for the same class.

| View | RTTI / locator | Vtable base | Key slots |
| --- | --- | --- | --- |
| Primary | `0x00610ed8` | `0x00610edc` | slot `+0x00 -> 0x004616e0` scalar deleting destructor; slot `+0x08 -> 0x004616b0` `AboveFrame::OnNotify` `goog` notification handler; slot `+0x44 -> 0x00461660` `AboveFrame::OnPaint` frame draw method. |
| Secondary | `0x00610f24` | `0x00610f28` | slot `+0x00 -> 0x004616c8`, an adjustor thunk subtracting `0xa0` / decimal 160 (Verified with int_convert.py) before dispatching to the destructor path. |
| Tertiary | `0x00610f54` | `0x00610f58` | slot `+0x00 -> 0x004616d3`, an adjustor thunk subtracting `0xa4` / decimal 164 (Verified with int_convert.py); inherited/default slot `+0x04 -> 0x00544e90`. |

The cluster is `0x88` bytes, composed from the primary view through the short tertiary table; it ends before UTF-16 `FRMPART.EPF` bytes at `0x00610f60`.

## 2026-06-12 A004 IDA Recheck

Live IDA MCP session `b001_nexustk` for `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe` reconfirmed this page's direct class ownership and split boundary:

- `entity_query` over `0x00610ed8-0x00610f70` reports `??_7AboveFrame@@6B@` at `0x00610edc`, `??_7AboveFrame@@6B@_0` at `0x00610f28`, `??_7AboveFrame@@6B@_1` at `0x00610f58`, and the successor string name at `0x00610f64`.
- `lookup_funcs` reports target sizes: scalar deleting destructor `0x004616e0` size `0xaa`, notification handler `0x004616b0` size `0x18`, `OnPaint` frame draw method `0x00461660` size `0x4f`, adjustor thunk `0x004616c8` size `0x0b`, adjustor thunk `0x004616d3` size `0x0b`, and inherited/default slot `0x00544e90` size `0x05`.
- `trace_data_flow backward` reports primary vptr stores at `0x00461139`, `0x004612cc`, and `0x0046170c`; secondary stores at `0x0046113f`, `0x004612d2`, and `0x00461712`; and tertiary stores at `0x00461149`, `0x004612dc`, and `0x0046171c`.
- `trace_data_flow backward 0x00610f60` reports the `FRMPART.EPF` string-data pointer uses from `0x00461178` and `0x004b7446`, proving the vtable cluster ends before that successor.
- `make_signature_for_range 0x00610ed8-0x00610f60` produced a unique `0x88` / decimal 136-byte signature (Verified with int_convert.py):
  `18 1E 64 00 E0 16 46 00 10 4B 4F 00 B0 16 46 00 20 8E 4B 00 80 D6 41 00 30 47 54 00 50 47 54 00 A0 47 54 00 00 48 54 00 20 4A 54 00 80 4B 54 00 D0 4B 54 00 70 4C 54 00 B0 4C 54 00 E0 4C 54 00 30 4D 54 00 70 4D 54 00 60 16 46 00 74 1E 64 00 C8 16 46 00 B0 4D 54 00 C0 4D 54 00 D0 4D 54 00 E0 4D 54 00 F0 4D 54 00 00 4E 54 00 F0 89 4A 00 10 4E 54 00 30 4E 54 00 70 4E 54 00 88 1E 64 00 D3 16 46 00 90 4E 54 00`.

## Assignment Decision

`AUTOGEN_PARENT_UID` is [UID:000005][AboveFrame](by-class/AboveFrame.md). This child is `88/93`, the direct class parent is `85/90`, and the source-file parent [UID:0000JL][FrameChrome](by-file/FrameChrome.md) is `86/85`, so the strict child/direct-parent gate clears.

This page should not attach directly to [UID:0000JL][FrameChrome](by-file/FrameChrome.md) or the mixed [UID:0001XO][FrameChromeVtableFamily](by-type/by-vtable/FrameChromeVtableFamily.md). The direct owner is the `AboveFrame` class.

## Reconstruction Notes

The rebuilt project should emit these vtables from the `AboveFrame` class declaration, inherited pane interfaces, and normal destructor/`OnNotify`/`OnPaint` definitions. Do not hand-port the dwords, adjustor thunks, or scalar deleting destructor wrapper as handwritten source. The class declaration belongs on [UID:000005][AboveFrame](by-class/AboveFrame.md); source-authored method/helper bodies belong on exact child pages.

B006's Rule 26 recheck keeps this direct class route unchanged. The primary paint slot should use source-facing `AboveFrame::OnPaint()` with `DrawFrame` only as a descriptive alias, and the secondary/tertiary destructor entries remain compiler adjustor thunks regenerated from the class layout.

B007's Rule 26 report was reviewed on 2026-06-21 and is already represented by this page's direct class route, primary `OnNotify` and `OnPaint` slot names, secondary/tertiary adjustor-thunk classification, and no literal vtable/thunk emission policy. The report's `DrawFrame` wording remains a descriptive alias only.

## Cross-References

- [UID:000005][AboveFrame](by-class/AboveFrame.md)
- [UID:0000JL][FrameChrome](by-file/FrameChrome.md)
- [UID:0001XO][FrameChromeVtableFamily](by-type/by-vtable/FrameChromeVtableFamily.md)
- [UID:0002NG][0x00610ed8-0x00610f60.AboveFrameVtableData](by-memory/0x00610ed8-0x00610f60.AboveFrameVtableData.md)
- [UID:0000YH][0x004610f0-0x0046178a.AboveFrame](by-memory/0x004610f0-0x0046178a.AboveFrame.md)
- [UID:0000YJ][0x004616c8-0x004616de.AboveFrameAdjustorThunks](by-memory/0x004616c8-0x004616de.AboveFrameAdjustorThunks.md)

## UID0000JL Accepted Split Incorporation - 2026-08-25

- This page is the exact source-local type child for AboveFrame's primary/secondary/tertiary family over [UID:0002NG][0x00610ed8-0x00610f60.AboveFrameVtableData](by-memory/0x00610ed8-0x00610f60.AboveFrameVtableData.md). It is not the mixed FrameChrome family index.
- Exact vtable bases, lifecycle stores, virtual slot targets, and adjustor relationships are owned semantically by [UID:000005][AboveFrame](by-class/AboveFrame.md) and source-routed through [UID:000577][AboveFrame](by-file/AboveFrame.md).
- The formal CPP/H blocks and emitter remain blank because the complete class declaration and virtual methods generate these compiler tables. No raw vtable array, RTTI bytes, or empty-emitter marker is valid human source.

## Changes

- 2026-08-25 UID0000JL callback: removed the invalid emitter, retained canonical class ownership, and documented the new UID000577 source route plus exact compiler-generated no-code disposition.

- 2026-06-20 B003 AboveFrame source-quality implementation: synchronized slot names with the accepted source-facing method split. Primary slot `0x00461660` is now `AboveFrame::OnPaint`, primary slot `0x004616b0` is `AboveFrame::OnNotify`, and adjustor/scalar destructor glue remains compiler-generated/no-code.
- 2026-06-20 B006 Rule 26 reconciliation: score unchanged; independently reaffirmed direct [UID:000005][AboveFrame](by-class/AboveFrame.md) ownership, `OnPaint` preferred naming, `DrawFrame` as alias only, and no handwritten source for the destructor thunks/scalar wrapper.
- 2026-06-21 B007 Rule 26 report review: score unchanged; verified B007's vtable facts against the current direct class-owned slot table and no-code compiler support policy.
- 2026-06-12 A004 Batch 323:
  - Created this exact source-local child from the former mixed [UID:0001XO][FrameChromeVtableFamily](by-type/by-vtable/FrameChromeVtableFamily.md) aggregate.
  - Summary/evidence: live IDA MCP reconfirmed the three decorated vtable bases, slot target sizes, constructor/destructor/scalar-destructor vptr stores, `FRMPART.EPF` successor boundary, unique range signature, and direct class parent gate.
