*** UID:0003HO | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:93 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:00003V | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:00003V | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# DIBitmap Vtable

## Status

- Entity kind: source-local vtable layout.
- Direct owner: [UID:00003V][DIBitmap](by-class/DIBitmap.md).
- Source context: [UID:0000IV][DIBitmap](by-file/DIBitmap.md).
- Exact data page: [UID:0002MC][0x00618e50-0x00618e60.DIBitmapVtableData](by-memory/0x00618e50-0x00618e60.DIBitmapVtableData.md).
- Split from: [UID:0001XE][DIBitmapDirectXVtables](by-type/by-vtable/DIBitmapDirectXVtables.md), which remains a broad non-emitting mixed-owner index.
- Rebuild handling: `source-declared/generated-binary`; reconstruct the `DIBitmap` class declaration and virtual destructor shape, not the vtable bytes as hand-authored data.

## Slot Layout

| Address | Slot | Target | Interpretation |
| --- | --- | --- | --- |
| `0x00618e50` | RTTI | `0x006467d0` | `??_R4DIBitmap@@6B@` complete-object locator pointer. |
| `0x00618e54` | `+0x00` | `0x004a1b10` | `DIBitmap` scalar deleting destructor, IDA `sub_4A1B10`, size `0x4e` / 78 bytes (verified with `int_convert.py`). |
| `0x00618e58` | `+0x04` | `0x004f4b10` | inherited `LObject`/runtime virtual, IDA `sub_4F4B10`, size `0x6`. |
| `0x00618e5c` | `+0x08` | `0x0041b6c0` | inherited no-op virtual, IDA `nullsub_18`, size `0x3`. |

The exact record is `0x10` / 16 bytes (verified with `int_convert.py`) and ends before the adjacent [UID:0002MD][0x00618e60-0x00618e70.DirectXVtableData](by-memory/0x00618e60-0x00618e70.DirectXVtableData.md) child.

## Evidence

- 2026-06-12 A004 live IDA MCP `entity_query` over `0x00618e50-0x00618efc` reports `??_7DIBitmap@@6B@` at `0x00618e54`.
- 2026-06-12 `lookup_funcs` confirms slot targets `0x004a1b10` (`sub_4A1B10`, size `0x4e`), `0x004f4b10` (`sub_4F4B10`, size `0x6`), and `0x0041b6c0` (`nullsub_18`, size `0x3`).
- 2026-06-12 `trace_data_flow backward 0x00618e54` reconfirms DIBitmap-context vptr stores at `0x004a1638`, raw destructor bytes `0x004a1746`, PCX factory construction path `0x004a195c`, and scalar deleting destructor `0x004a1b19`.
- 2026-06-12 `make_signature_for_range 0x00618e50-0x00618e70` returns a unique 32-byte signature covering the adjacent `DIBitmap` and `DirectX` four-dword records; the first half is `D0 67 64 00 10 1B 4A 00 10 4B 4F 00 C0 B6 41 00`.
- [UID:0002MC][0x00618e50-0x00618e60.DIBitmapVtableData](by-memory/0x00618e50-0x00618e60.DIBitmapVtableData.md) records repeated dword-level checks and the direct assignment to [UID:00003V][DIBitmap](by-class/DIBitmap.md).

## Parent Gate

This source-local vtable page is assigned to [UID:00003V][DIBitmap](by-class/DIBitmap.md). The child is `88/93`, and the direct class parent is `86/87`, so both sides clear the strict `85/85` gate. The file parent [UID:0000IV][DIBitmap](by-file/DIBitmap.md) is `86/86` and remains the source context; the mixed aggregate [UID:0001XE][DIBitmapDirectXVtables](by-type/by-vtable/DIBitmapDirectXVtables.md) is not a direct owner.

## Cross-References

- [UID:00003V][DIBitmap](by-class/DIBitmap.md)
- [UID:0000IV][DIBitmap](by-file/DIBitmap.md)
- [UID:0001U6][DIBitmapLayout](by-type/by-struct/DIBitmapLayout.md)
- [UID:0002MC][0x00618e50-0x00618e60.DIBitmapVtableData](by-memory/0x00618e50-0x00618e60.DIBitmapVtableData.md)
- [UID:0001XE][DIBitmapDirectXVtables](by-type/by-vtable/DIBitmapDirectXVtables.md)

## Changes

- 2026-06-12 A004 Batch 317:
  - Created this source-local split page from the mixed [UID:0001XE][DIBitmapDirectXVtables](by-type/by-vtable/DIBitmapDirectXVtables.md) aggregate.
  - Evidence: live IDA MCP reconfirmed the vtable symbol, three slot targets, function sizes, DIBitmap-context vptr stores, and the unique adjacent-record byte signature.
  - Gate: assigned to [UID:00003V][DIBitmap](by-class/DIBitmap.md) because this vtable is a compiler-emitted artifact of the `DIBitmap` class declaration and both child and direct parent clear `85/85`.
