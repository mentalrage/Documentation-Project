*** UID:0001XE | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:89 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:93 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:NONE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:FALSE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# DIBitmap And DirectX Vtables

## Status

- Confidence: very strong for slot values, owning class association, split routing, and aggregate non-ownership.
- Evidence basis: IDA MCP `py_eval`/dword reads, `entity_query`, `trace_data_flow`, unique range signature, and xref checks through 2026-06-12.
- Current data caveat: `class_DIBitmap.meta_wave3` and `class_DirectX.meta_wave3` both report `vtable_count: 0`; do not use that generated count as authority.
- Current classification: non-emitting `reviewed-85-ownership-split` aggregate.
- Assignment: this mixed type inventory is intentionally unassigned upward even at `89/93` because it spans two direct class owners. Source-local by-vtable children now carry reconstructable class routes, and exact by-memory children carry the backing data ranges.

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

- [UID:0002MC][0x00618e50-0x00618e60.DIBitmapVtableData](by-memory/0x00618e50-0x00618e60.DIBitmapVtableData.md) documents the exact `DIBitmap` RTTI pointer and three-slot primary vtable record; Batch 130 assigns that exact child to [UID:00003V][DIBitmap](by-class/DIBitmap.md).
- [UID:0002MD][0x00618e60-0x00618e70.DirectXVtableData](by-memory/0x00618e60-0x00618e70.DirectXVtableData.md) documents the exact `DirectX` RTTI pointer and three-slot primary vtable record; Batch 130 assigns that exact child to [UID:00003Y][DirectX](by-class/DirectX.md).

## Source-Local Split Pages

| Split page | Direct parent | Parent gate | Backing data |
| --- | --- | ---: | --- |
| [UID:0003HO][DIBitmapVtable](by-type/by-vtable/DIBitmapVtable.md) | [UID:00003V][DIBitmap](by-class/DIBitmap.md) | `86/87` | [UID:0002MC][0x00618e50-0x00618e60.DIBitmapVtableData](by-memory/0x00618e50-0x00618e60.DIBitmapVtableData.md) |
| [UID:0003HP][DirectXVtable](by-type/by-vtable/DirectXVtable.md) | [UID:00003Y][DirectX](by-class/DirectX.md) | `85/88` | [UID:0002MD][0x00618e60-0x00618e70.DirectXVtableData](by-memory/0x00618e60-0x00618e70.DirectXVtableData.md) |

## 2026-05-31 IDA Recheck

- `list_globals *DIBitmap*` reports `??_7DIBitmap@@6B@` at `0x00618e54` and `??_R4DIBitmap@@6B@` at `0x006467d0`.
- `list_globals *DirectX*` reports `??_7DirectX@@6B@` at `0x00618e64` and `??_R4DirectX@@6B@` at `0x0064681c`.
- `lookup_funcs` confirms scalar deleting destructor starts `0x004a1b10` (`0x4e` bytes) and `0x004a1cd0` (`0x9a` bytes).
- `xrefs_to 0x00618e54` reports `DIBitmap` vtable stores at `0x004a1638`, raw destructor offset `0x004a1746`, PCX factory offset `0x004a195c`, and scalar destructor offset `0x004a1b19`.
- `xrefs_to 0x00618e64` reports `DirectX` vtable stores at `0x004a1bbf`, `0x004a1c88`, and `0x004a1cf8`.
- Dword scan verifies `0x00618e50-0x00618e60` as `DIBitmap`, `0x00618e60-0x00618e70` as `DirectX`, `0x00618e70` as DirectX string data, and `0x00618efc` as `EmployeeDialogPane` RTTI.

## 2026-06-08 IDA Recheck

- IDB: `NexusTK.exe`, MD5 `4247e04e20b65d6414c7238aa8ff5515`.
- `py_eval` reads `0x00618e50 -> 0x006467d0`, `0x00618e54 -> 0x004a1b10`, `0x00618e58 -> 0x004f4b10`, and `0x00618e5c -> 0x0041b6c0` for the `DIBitmap` record.
- `py_eval` reads `0x00618e60 -> 0x0064681c`, `0x00618e64 -> 0x004a1cd0`, `0x00618e68 -> 0x004f4b10`, and `0x00618e6c -> 0x0041b6c0` for the `DirectX` record.
- `xrefs_to 0x00618e54` reconfirms DIBitmap vtable stores at `0x004a1638`, `0x004a1746`, `0x004a195c`, and `0x004a1b19`.
- `xrefs_to 0x00618e64` reconfirms DirectX vtable stores at `0x004a1bbf`, `0x004a1c88`, and `0x004a1cf8`.

## 2026-06-10 B001-010 Audit

- IDB: `NexusTK.exe`, MD5 `4247e04e20b65d6414c7238aa8ff5515`, SHA-256 `9aec210bbc5ce592176a21dd8e9d9fd8f250b8d9ea78237915a99ba8cfa9a632`.
- `list_globals *DIBitmap*` reports `??_7DIBitmap@@6B@` at `0x00618e54` and `??_R4DIBitmap@@6B@` at `0x006467d0`.
- `list_globals *DirectX*` reports `??_7DirectX@@6B@` at `0x00618e64` and `??_R4DirectX@@6B@` at `0x0064681c`.
- `lookup_funcs` reconfirms slot targets `0x004a1b10` (`sub_4A1B10`, size `0x4e`), `0x004a1cd0` (`sub_4A1CD0`, size `0x9a`), shared inherited slot `0x004f4b10` (`sub_4F4B10`, size `0x6`), and `0x0041b6c0` (`nullsub_18`, size `0x3`).
- `py_eval` dword scan reconfirms `0x00618e50-0x00618e60` as the `DIBitmap` RTTI/vtable record and `0x00618e60-0x00618e70` as the `DirectX` RTTI/vtable record.
- `xrefs_to 0x00618e54` returns DIBitmap-context refs at `0x004a1638`, raw `0x004a1746`, `0x004a195c`, and `0x004a1b19`.
- `xrefs_to 0x00618e64` returns DirectX-context refs at `0x004a1bbf`, `0x004a1c88`, and `0x004a1cf8`.
- `xrefs_to 0x00618e70` returns DirectX constructor string refs at `0x004a1bfb` and `0x004a1c31`; byte decoding confirms the UTF-16 text `DirectX not installed, or is corrupted. Please install DirectX again.` before the `EmployeeDialogPane` RTTI pointer at `0x00618efc`.

The audit confirmed the by-memory split and the two class owners. Batch 317 adds source-local by-vtable split pages on top of those exact by-memory children so the mixed aggregate no longer has to masquerade as a reconstructable owner.

## 2026-06-12 A004 IDA Recheck

- IDB session: `b001_nexustk`, `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe.i64`.
- `entity_query` over `0x00618e50-0x00618efc` reports `??_7DIBitmap@@6B@` at `0x00618e54`, `??_7DirectX@@6B@` at `0x00618e64`, and the adjacent DirectX string label `aCtxNotInstalle` at `0x00618e78`.
- `lookup_funcs` reconfirms slot targets `0x004a1b10` (`sub_4A1B10`, `0x4e` / 78 bytes, verified with `int_convert.py`), `0x004a1cd0` (`sub_4A1CD0`, `0x9a` / 154 bytes, verified with `int_convert.py`), inherited `0x004f4b10` (`sub_4F4B10`, `0x6`), and `0x0041b6c0` (`nullsub_18`, `0x3`).
- `trace_data_flow backward 0x00618e54` reconfirms DIBitmap vptr stores at `0x004a1638`, raw destructor bytes `0x004a1746`, PCX factory construction path `0x004a195c`, and scalar deleting destructor `0x004a1b19`.
- `trace_data_flow backward 0x00618e64` reconfirms DirectX vptr stores at `0x004a1bbf`, destructor restore `0x004a1c88`, and scalar deleting destructor `0x004a1cf8`.
- `trace_data_flow backward 0x00618e70` reconfirms DirectX diagnostic string refs at `0x004a1bfb` and `0x004a1c31`, so `0x00618e70` is the DirectX string successor and not a vtable continuation.
- `make_signature_for_range 0x00618e50-0x00618e70` returns a unique 32-byte signature: `D0 67 64 00 10 1B 4A 00 10 4B 4F 00 C0 B6 41 00 1C 68 64 00 D0 1C 4A 00 10 4B 4F 00 C0 B6 41 00`.

## Source-Layout Implication

Both classes are tiny render-support wrappers with one primary `LObject`-style vtable. `DIBitmap` belongs with the GDI/PCX DIB wrapper code, while `DirectX` belongs with DirectDraw bootstrap/lifetime code and [UID:0000QS][g_pDirectX](by-global/g_pDirectX.md). The adjacent vtable placement is linker layout evidence only; it is not a reason to merge the original source files.

## Assignment Decision

This page is a reviewed, non-emitting `reviewed-85-ownership-split` aggregate: it clears the score gate, but there is no single actual direct parent that owns both records. Direct ownership is split between [UID:00003V][DIBitmap](by-class/DIBitmap.md) and [UID:00003Y][DirectX](by-class/DirectX.md). [UID:0003HO][DIBitmapVtable](by-type/by-vtable/DIBitmapVtable.md) and [UID:0003HP][DirectXVtable](by-type/by-vtable/DirectXVtable.md) now carry source-local reconstructable type routes, while the exact by-memory children carry the backing `.rdata` ranges. The mixed aggregate remains useful as a vtable-family inventory and cross-reference page, not as a source-owner node.

## Score Rationale

- Completion is raised to `89` because the page now documents the current live IDA refresh, source-local split pages, exact by-memory backing ranges, class-parent gates, and the mixed-ownership no-parent decision.
- Confidence is raised to `93` because repeated IDA evidence now confirms every slot value, function size, vtable-store xref, successor string boundary, unique range signature, and the two direct owner classes.
- Remaining work before higher scores: final original C++ declaration spelling and the generated `vtable_count: 0` metadata issue remain outside this mixed inventory page.

## Cross-References

- [UID:0000IV][DIBitmap](by-file/DIBitmap.md)
- [UID:00003V][DIBitmap](by-class/DIBitmap.md)
- [UID:0003HO][DIBitmapVtable](by-type/by-vtable/DIBitmapVtable.md)
- [UID:0001U6][DIBitmapLayout](by-type/by-struct/DIBitmapLayout.md)
- [UID:000136][0x004a1740-0x004a17ad.DIBitmapDestructorAndAccessors](by-memory/0x004a1740-0x004a17ad.DIBitmapDestructorAndAccessors.md)
- [UID:000135][0x004a1600-0x004a1b5e.DIBitmapAndPcxLoaders](by-memory/0x004a1600-0x004a1b5e.DIBitmapAndPcxLoaders.md)
- [UID:0000IW][DirectX](by-file/DirectX.md)
- [UID:00003Y][DirectX](by-class/DirectX.md)
- [UID:0003HP][DirectXVtable](by-type/by-vtable/DirectXVtable.md)
- [UID:000137][0x004a1b60-0x004a1d6a.DirectX](by-memory/0x004a1b60-0x004a1d6a.DirectX.md)
- [UID:0000QS][g_pDirectX](by-global/g_pDirectX.md)
- [UID:0002MC][0x00618e50-0x00618e60.DIBitmapVtableData](by-memory/0x00618e50-0x00618e60.DIBitmapVtableData.md)
- [UID:0002MD][0x00618e60-0x00618e70.DirectXVtableData](by-memory/0x00618e60-0x00618e70.DirectXVtableData.md)

## Changes

- 2026-06-10 B001-010 audit:
  - Score remains `87/92`; no new child pages are needed.
  - Current IDA MCP reconfirmed both RTTI/vtable four-dword records, all slot targets, vtable-store xrefs, the DirectX string refs at `0x00618e70`, and the `0x00618efc` `EmployeeDialogPane` boundary.
  - Reclassified the active recommendation wording to `reviewed-85-ownership-split`: exact by-memory children carry direct class ownership and this page remains parent-blank by design.
- 2026-05-31 exact child split:
  - What existed before: metadata was `0/0` with `RECONSTRUCTABLE` blank, and the page described the two vtables without exact by-memory child pages.
  - Changed to: scored `84/91`, marked reconstructable, and linked exact `DIBitmap` and `DirectX` vtable-data pages.
  - Summary/evidence: IDA MCP `list_globals`, `lookup_funcs`, `xrefs_to`, and dword scan confirm the RTTI words, slot values, vtable stores, and adjacent string/next-class boundaries.
- 2026-06-08 A007 Batch 130 mixed-inventory refresh:
  - Changed to: `COMPLETION:87`, `CONFIDENCE:92`, with `AUTOGEN_PARENT_UID` still blank.
  - Summary/evidence: current IDA MCP reconfirmed both four-dword records and their vtable-store xrefs. Exact child [UID:0002MC][0x00618e50-0x00618e60.DIBitmapVtableData](by-memory/0x00618e50-0x00618e60.DIBitmapVtableData.md) is assigned to `DIBitmap`, exact child [UID:0002MD][0x00618e60-0x00618e70.DirectXVtableData](by-memory/0x00618e60-0x00618e70.DirectXVtableData.md) is assigned to `DirectX`, and this mixed inventory remains unassigned because no single direct owner covers both records.
- 2026-06-12 A004 Batch 317 source-local split repair:
  - What existed before: the page was parent-blank and documented the ownership split, but it was still `RECONSTRUCTABLE:TRUE`, which made the mixed aggregate appear as an unassigned source-emitting type row.
  - Changed to: `COMPLETION:89`, `CONFIDENCE:93`, `RECONSTRUCTABLE:FALSE`, still parent blank, with source-local reconstructable split children [UID:0003HO][DIBitmapVtable](by-type/by-vtable/DIBitmapVtable.md) and [UID:0003HP][DirectXVtable](by-type/by-vtable/DirectXVtable.md).
  - Summary/evidence: live IDA MCP reconfirmed both vtable names, all slot targets and sizes, class-specific vptr-store refs, the DirectX string successor boundary, and a unique signature over the adjacent records. The strict route belongs on the split pages because each one has a single direct class parent clearing `85/85`.
