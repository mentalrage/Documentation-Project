*** UID:0003HP | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:00003Y | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:00003Y | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# DirectX Vtable

## Status

- Entity kind: source-local vtable layout.
- Direct owner: [UID:00003Y][DirectX](by-class/DirectX.md).
- Source context: [UID:0000IW][DirectX](by-file/DirectX.md).
- Exact data page: [UID:0002MD][0x00618e60-0x00618e70.DirectXVtableData](by-memory/0x00618e60-0x00618e70.DirectXVtableData.md).
- Split from: [UID:0001XE][DIBitmapDirectXVtables](by-type/by-vtable/DIBitmapDirectXVtables.md), which remains a broad non-emitting mixed-owner index.
- Rebuild handling: `source-declared/generated-binary`; reconstruct the `DirectX` class declaration and virtual destructor shape, not the vtable bytes as hand-authored data.

## Slot Layout

| Address | Slot | Target | Interpretation |
| --- | --- | --- | --- |
| `0x00618e60` | RTTI | `0x0064681c` | `??_R4DirectX@@6B@` complete-object locator pointer. |
| `0x00618e64` | `+0x00` | `0x004a1cd0` | `DirectX` scalar deleting destructor, IDA `sub_4A1CD0`, size `0x9a` / 154 bytes (verified with `int_convert.py`). |
| `0x00618e68` | `+0x04` | `0x004f4b10` | inherited `LObject::GetRuntimeClass`, IDA `sub_4F4B10`, size `0x6`. |
| `0x00618e6c` | `+0x08` | `0x0041b6c0` | inherited `LObject::OnChangeMessage`, no-op IDA `nullsub_18`, size `0x3`. |

The exact record is `0x10` / 16 bytes (verified with `int_convert.py`) and ends before [UID:0003AY][0x00618e70-0x00618efc.DirectXDiagnosticString](by-memory/0x00618e70-0x00618efc.DirectXDiagnosticString.md), whose `0x8c` / 140-byte span is also verified with `int_convert.py`.

The semantic source cause is the complete [UID:00003Y][DirectX](by-class/DirectX.md) declaration: direct `LObject` plus empty `Singleton<DirectX>` bases, virtual ordinary destructor, public `LPDIRECTDRAW m_pDirectDraw`, and x86 size `0x08`. The ten individually bounded DirectX/Singleton RTTI objects are inventoried on that class page under C0000IW-035 through C0000IW-044. They and this table are compiler-generated; both formal blocks remain intentionally blank on this semantic type page.

## Evidence

- 2026-06-12 A004 live IDA MCP `entity_query` over `0x00618e50-0x00618efc` reports `??_7DirectX@@6B@` at `0x00618e64` and the adjacent string label `aCtxNotInstalle` at `0x00618e78`.
- 2026-06-12 `lookup_funcs` confirms slot targets `0x004a1cd0` (`sub_4A1CD0`, size `0x9a`), `0x004f4b10` (`sub_4F4B10`, size `0x6`), and `0x0041b6c0` (`nullsub_18`, size `0x3`).
- 2026-06-12 `trace_data_flow backward 0x00618e64` reconfirms DirectX-context vptr stores at `0x004a1bbf`, destructor restore `0x004a1c88`, and scalar deleting destructor `0x004a1cf8`.
- 2026-06-12 `trace_data_flow backward 0x00618e70` reconfirms the successor string refs at `0x004a1bfb` and `0x004a1c31`, proving the vtable's exclusive end.
- 2026-06-12 `make_signature_for_range 0x00618e50-0x00618e70` returns a unique 32-byte signature covering the adjacent `DIBitmap` and `DirectX` four-dword records; the DirectX half is `1C 68 64 00 D0 1C 4A 00 10 4B 4F 00 C0 B6 41 00`.
- [UID:0002MD][0x00618e60-0x00618e70.DirectXVtableData](by-memory/0x00618e60-0x00618e70.DirectXVtableData.md) records repeated dword-level checks and the direct assignment to [UID:00003Y][DirectX](by-class/DirectX.md).

## Parent Gate

This source-local vtable page is assigned to [UID:00003Y][DirectX](by-class/DirectX.md). The child and direct class parent are both `92/94`. The file parent [UID:0000IW][DirectX](by-file/DirectX.md) remains the source context; mixed aggregate [UID:0001XE][DIBitmapDirectXVtables](by-type/by-vtable/DIBitmapDirectXVtables.md) stays non-emitting and has no source-owner action.

## Score Rationale

- Completion is `92` because the exact COL-inclusive record, all three slot targets, three vptr stores, successor boundary, complete two-base declaration source cause, ten-object RTTI route, and compiler-only deletion/vtable policy are closed.
- Confidence is `94` because repeated slot/data/xref evidence and the complete class declaration agree. It remains below 95 only because original inherited virtual tokens are not PDB-proven.

## Cross-References

- [UID:00003Y][DirectX](by-class/DirectX.md)
- [UID:0000IW][DirectX](by-file/DirectX.md)
- [UID:0002MD][0x00618e60-0x00618e70.DirectXVtableData](by-memory/0x00618e60-0x00618e70.DirectXVtableData.md)
- [UID:0003AY][0x00618e70-0x00618efc.DirectXDiagnosticString](by-memory/0x00618e70-0x00618efc.DirectXDiagnosticString.md)
- [UID:0000QS][g_pDirectX](by-global/g_pDirectX.md)
- [UID:0001XE][DIBitmapDirectXVtables](by-type/by-vtable/DIBitmapDirectXVtables.md)

## Changes

- 2026-08-14 B004 accepted UID0000IW whole-file implementation:
  - Raised `88/93` to `92/94` while keeping both formal source channels blank as required for a semantic compiler-generated vtable type.
  - Corrected the inherited slots to `LObject::GetRuntimeClass` and `LObject::OnChangeMessage`, and tied the exact record to the complete LObject/Singleton DirectX declaration and ten-object RTTI graph.

- 2026-06-12 A004 Batch 317:
  - Created this source-local split page from the mixed [UID:0001XE][DIBitmapDirectXVtables](by-type/by-vtable/DIBitmapDirectXVtables.md) aggregate.
  - Evidence: live IDA MCP reconfirmed the vtable symbol, three slot targets, function sizes, DirectX-context vptr stores, successor diagnostic-string refs, and the unique adjacent-record byte signature.
  - Gate: assigned to [UID:00003Y][DirectX](by-class/DirectX.md) because this vtable is a compiler-emitted artifact of the `DirectX` class declaration and both child and direct parent clear `85/85`.
