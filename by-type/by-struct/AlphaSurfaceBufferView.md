*** UID:0001TQ | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# AlphaSurfaceBufferView

## Status

- Confidence: strong for offsets and role, medium for final original type name.
- Likely owner header: `render/AlphaMaskSurface.h` or a shared render surface header.
- Entity kind: POD buffer-view record.
- Primary memory docs: [UID:0000YL][0x00462170-0x00462e03.AlphaMaskSurface](by-memory/0x00462170-0x00462e03.AlphaMaskSurface.md)

## Layout

`AlphaSurfaceBufferView` is the 0x14-byte payload copied from an alpha surface object or built as a clipped non-owning view.

| Offset | Field | Evidence |
| --- | --- | --- |
| `0x00` | `uint8_t* pixels` | `GetBufferInfo` copies source `+0x14`; clipped builder writes adjusted pointer. |
| `0x04` | `int width` | Width copied from source or clipped rectangle. |
| `0x08` | `int height` | Height copied from source or clipped rectangle. |
| `0x0c` | `int stride` | Source stride copied so clipped views keep row pitch. |
| `0x10` | `uint32_t ownsBufferOrFlags` | Source ownership byte/padding copied by `GetBufferInfo`; clipped builder clears byte `+0x10` to mark non-owning. |

## Evidence

- 2026-05-26 IDA MCP decompilation of `0x00462300` copies an OWORD from alpha-surface object offset `+0x14` to output offset `+0x00`, then copies the dword at object offset `+0x24` to output offset `+0x10`.
- 2026-05-26 IDA MCP decompilation of [UID:0000U3][BuildClippedAlphaSurfaceView_00462320](by-item/BuildClippedAlphaSurfaceView_00462320.md) writes adjusted pixel pointer, clipped width/height, preserved stride, and clears byte `+0x10`.
- `0x00462320` has a live IDA code xref from `StaticObjImageLib` at `0x004dd66a`, so this record is reconstructable render infrastructure rather than dead local scratch.
- 2026-05-30 IDA MCP recheck of [UID:0000U3][BuildClippedAlphaSurfaceView_00462320](by-item/BuildClippedAlphaSurfaceView_00462320.md) confirms the output writes: pixel pointer at `+0x00`, clipped width at `+0x04`, clipped height at `+0x08`, stride at `+0x0c`, and non-owning byte clear at `+0x10`.

## Cross-References

- [UID:0001TP][AlphaMaskSurfaceLayout](by-type/by-struct/AlphaMaskSurfaceLayout.md)
- [UID:0000HF][AlphaMaskSurface](by-file/AlphaMaskSurface.md)
- [UID:00000C][AlphaMaskSurface](by-class/AlphaMaskSurface.md)
- [UID:0000YL][0x00462170-0x00462e03.AlphaMaskSurface](by-memory/0x00462170-0x00462e03.AlphaMaskSurface.md)
- [UID:0000U3][BuildClippedAlphaSurfaceView_00462320](by-item/BuildClippedAlphaSurfaceView_00462320.md)
- [UID:0000UU][InitAlphaSurfaceView_004623C0](by-item/InitAlphaSurfaceView_004623C0.md)

## Changes

- 2026-05-30: Raised completion/confidence from `0/0` to `86/90`. Previously this page documented the layout but had no score; it now records the current IDA MCP clipped-view recheck and concrete output offsets.
