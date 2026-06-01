*** UID:0001XE | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:91 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# DIBitmap And DirectX Vtables

## Status

- Confidence: strong for slot values and owning class association.
- Evidence basis: IDA MCP `py_eval` vtable reads and xref checks on 2026-05-26.
- Current data caveat: `class_DIBitmap.meta_wave3` and `class_DirectX.meta_wave3` both report `vtable_count: 0`; do not use that generated count as authority.

## DIBitmap Vtable

- RTTI pointer: `0x00618e50`
- Primary vtable: `0x00618e54`
- Exact data range: [UID:0002MC][0x00618e50-0x00618e60.DIBitmapVtableData](by-memory/0x00618e50-0x00618e60.DIBitmapVtableData.md)
- Owner class: [UID:00003V][DIBitmap](by-class/DIBitmap.md)
- Likely source file: [UID:0000IV][DIBitmap](by-file/DIBitmap.md)
- Confirmed layout: [UID:0001U6][DIBitmapLayout](by-type/by-struct/DIBitmapLayout.md)

| Slot | Target | Interpretation |
| --- | --- | --- |
| `+0x00` | `0x004a1b10` | `DIBitmap::ScalarDeletingDestructor` |
| `+0x04` | `0x004f4b10` | inherited `LObject`/runtime virtual |
| `+0x08` | `0x0041b6c0` | inherited no-op virtual / `nullsub_18` |

IDA xrefs to `0x00618e54` land at:

- `0x004a1638` in `DIBitmap::DIBitmap`
- `0x004a1746` in the raw non-deleting destructor body
- `0x004a195c` inside `CreateDIBitmapFromPcxBuffer`
- `0x004a1b19` in `DIBitmap::ScalarDeletingDestructor`

The table ends before the DirectX RTTI pointer at `0x00618e60`.

## DirectX Vtable

- RTTI pointer: `0x00618e60`
- Primary vtable: `0x00618e64`
- Exact data range: [UID:0002MD][0x00618e60-0x00618e70.DirectXVtableData](by-memory/0x00618e60-0x00618e70.DirectXVtableData.md)
- Owner class: [UID:00003Y][DirectX](by-class/DirectX.md)
- Likely source file: [UID:0000IW][DirectX](by-file/DirectX.md)

| Slot | Target | Interpretation |
| --- | --- | --- |
| `+0x00` | `0x004a1cd0` | `DirectX::ScalarDeletingDestructor` |
| `+0x04` | `0x004f4b10` | inherited `LObject`/runtime virtual |
| `+0x08` | `0x0041b6c0` | inherited no-op virtual / `nullsub_18` |

IDA xrefs to `0x00618e64` land at:

- `0x004a1bbf` in `DirectX::DirectX`
- `0x004a1c88` in `DirectX::~DirectX`
- `0x004a1cf8` in `DirectX::ScalarDeletingDestructor`

The table ends before adjacent DirectX diagnostic string/data at `0x00618e70`.

## Exact By-Memory Children

- [UID:0002MC][0x00618e50-0x00618e60.DIBitmapVtableData](by-memory/0x00618e50-0x00618e60.DIBitmapVtableData.md) documents the exact `DIBitmap` RTTI pointer and three-slot primary vtable record.
- [UID:0002MD][0x00618e60-0x00618e70.DirectXVtableData](by-memory/0x00618e60-0x00618e70.DirectXVtableData.md) documents the exact `DirectX` RTTI pointer and three-slot primary vtable record.

## 2026-05-31 IDA Recheck

- `list_globals *DIBitmap*` reports `??_7DIBitmap@@6B@` at `0x00618e54` and `??_R4DIBitmap@@6B@` at `0x006467d0`.
- `list_globals *DirectX*` reports `??_7DirectX@@6B@` at `0x00618e64` and `??_R4DirectX@@6B@` at `0x0064681c`.
- `lookup_funcs` confirms scalar deleting destructor starts `0x004a1b10` (`0x4e` bytes) and `0x004a1cd0` (`0x9a` bytes).
- `xrefs_to 0x00618e54` reports `DIBitmap` vtable stores at `0x004a1638`, raw destructor offset `0x004a1746`, PCX factory offset `0x004a195c`, and scalar destructor offset `0x004a1b19`.
- `xrefs_to 0x00618e64` reports `DirectX` vtable stores at `0x004a1bbf`, `0x004a1c88`, and `0x004a1cf8`.
- Dword scan verifies `0x00618e50-0x00618e60` as `DIBitmap`, `0x00618e60-0x00618e70` as `DirectX`, `0x00618e70` as DirectX string data, and `0x00618efc` as `EmployeeDialogPane` RTTI.

## Source-Layout Implication

Both classes are tiny render-support wrappers with one primary `LObject`-style vtable. `DIBitmap` belongs with the GDI/PCX DIB wrapper code, while `DirectX` belongs with DirectDraw bootstrap/lifetime code and [UID:0000QS][g_pDirectX](by-global/g_pDirectX.md). The adjacent vtable placement is linker layout evidence only; it is not a reason to merge the original source files.

## Cross-References

- [UID:0000IV][DIBitmap](by-file/DIBitmap.md)
- [UID:00003V][DIBitmap](by-class/DIBitmap.md)
- [UID:0001U6][DIBitmapLayout](by-type/by-struct/DIBitmapLayout.md)
- [UID:000136][0x004a1740-0x004a17ac.DIBitmapDestructorAndAccessors](by-memory/0x004a1740-0x004a17ac.DIBitmapDestructorAndAccessors.md)
- [UID:000135][0x004a1600-0x004a1b5e.DIBitmapAndPcxLoaders](by-memory/0x004a1600-0x004a1b5e.DIBitmapAndPcxLoaders.md)
- [UID:0000IW][DirectX](by-file/DirectX.md)
- [UID:00003Y][DirectX](by-class/DirectX.md)
- [UID:000137][0x004a1b60-0x004a1d6a.DirectX](by-memory/0x004a1b60-0x004a1d6a.DirectX.md)
- [UID:0000QS][g_pDirectX](by-global/g_pDirectX.md)
- [UID:0002MC][0x00618e50-0x00618e60.DIBitmapVtableData](by-memory/0x00618e50-0x00618e60.DIBitmapVtableData.md)
- [UID:0002MD][0x00618e60-0x00618e70.DirectXVtableData](by-memory/0x00618e60-0x00618e70.DirectXVtableData.md)

## Changes

- 2026-05-31 exact child split:
  - What existed before: metadata was `0/0` with `RECONSTRUCTABLE` blank, and the page described the two vtables without exact by-memory child pages.
  - Changed to: scored `84/91`, marked reconstructable, and linked exact `DIBitmap` and `DirectX` vtable-data pages.
  - Summary/evidence: IDA MCP `list_globals`, `lookup_funcs`, `xrefs_to`, and dword scan confirm the RTTI words, slot values, vtable stores, and adjacent string/next-class boundaries.
