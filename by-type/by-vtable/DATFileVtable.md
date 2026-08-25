*** UID:0003I0 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:95 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:97 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:NONE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:FALSE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# DATFile Vtable

## Status

- Current role: non-emitting compiler-vtable evidence for the concrete archive-backed `DATFile` stream.
- Owner/emitter: none; [UID:00003G][DATFile](by-class/DATFile.md) virtual declarations/definitions are the sole human source and cause compiler emission.
- Source context: [UID:0000IN][DATFile](by-file/DATFile.md).
- Exact backing data: [UID:0003B7][0x00618920-0x00618950.DATFileVtableData](by-memory/0x00618920-0x00618950.DATFileVtableData.md).
- Split source: [UID:0001XK][FileStreamVtables](by-type/by-vtable/FileStreamVtables.md) mixed aggregate.

## Layout

The record at `0x00618920-0x00618950` is `0x30` bytes / decimal 48 bytes, with an RTTI locator dword followed by `0x2c` bytes / decimal 44 bytes of vtable slots (Verified with int_convert.py).

| Slot | Address | Value | Role |
| --- | --- | --- | --- |
| locator | `0x00618920` | `0x006464f8` | `DATFile` RTTI complete-object-locator pointer. |
| `+0x00` | `0x00618924` | `0x0049d280` | scalar deleting destructor. |
| `+0x04` | `0x00618928` | `0x004f4b10` | inherited `LObject`-style runtime slot. |
| `+0x08` | `0x0061892c` | `0x0041b6c0` | inherited no-op virtual / `nullsub_18`. |
| `+0x0c` | `0x00618930` | `0x0049c180` | `Open` / attach entry by name. |
| `+0x10` | `0x00618934` | `0x0049c240` | `Close`. |
| `+0x14` | `0x00618938` | `0x0049c2d0` | `GetPosition`; `Tell` is historical vocabulary. |
| `+0x18` | `0x0061893c` | `0x0049c260` | seek. |
| `+0x1c` | `0x00618940` | `0x0049c2f0` | size query. |
| `+0x20` | `0x00618944` | `0x0049c310` | `size_t Read(void *buffer, int count)` with negative-count full-payload sentinel. |
| `+0x24` | `0x00618948` | `0x0049c3e0` | string/line read. |
| `+0x28` | `0x0061894c` | `0x0049c370` | raw line read. |

## 2026-06-12 A004 IDA Recheck

Live IDA MCP session `b001_nexustk` for `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe` reconfirmed this page's direct class ownership and split boundary:

- `entity_query` over `0x006188dc-0x00618954` reports `??_7DATFile@@6B@` at `0x00618924`, after the separate `DATFileContainer` one-slot record at `0x0061891c`.
- `lookup_funcs` reports concrete slot target sizes: destructor `0x0049d280` size `0x4c`, open `0x0049c180` size `0xbb`, close `0x0049c240` size `0x20`, tell `0x0049c2d0` size `0x17`, seek `0x0049c260` size `0x6c`, size `0x0049c2f0` size `0x14`, read `0x0049c310` size `0x52`, string-line read `0x0049c3e0` size `0xb9`, and raw-line read `0x0049c370` size `0x6f`.
- `trace_data_flow backward 0x00618924` reports the vftable dword and the constructor install xref at `0x0049c13f`.
- `make_signature_for_range 0x00618920-0x00618950` produced a unique 48-byte signature:
  `F8 64 64 00 80 D2 49 00 10 4B 4F 00 C0 B6 41 00 80 C1 49 00 40 C2 49 00 D0 C2 49 00 60 C2 49 00 F0 C2 49 00 10 C3 49 00 E0 C3 49 00 70 C3 49 00`.

## Assignment Decision

`AUTOGEN_PARENT_UID` is [UID:00003G][DATFile](by-class/DATFile.md). This child score remains unchanged, the direct class parent is now `89/92`, and the existing archive source root remains the emitter.

## UID0002UV Source-Quality Callback

- Scores, owner/emitter, blank formal, exact table bytes/order/signature, constructor install xref, source-local ownership, and all unrelated DAT evidence remain unchanged.
- Slot `+0x14` is source-facing `GetPosition`; `Tell` remains historical vocabulary.
- Slot `+0x20` returns `size_t` and takes signed `int count`. The concrete negative-count branch substitutes the full payload and proves the common File/Stdio parameter type.
- DATFile remains a 20-byte object over a four-byte data-member-free File base with derived fields at `+0x04/+0x08/+0x0c/+0x10`.
- No vtable array, vptr store, RTTI, deleting-wrapper mechanics, or complete DAT class body was introduced.

This page should not attach to [UID:0000JB][File](by-file/File.md) or [UID:0000JD][FileIO](by-file/FileIO.md). It implements the `File` interface, but the concrete vtable owner is the archive-backed `DATFile` class.

## Reconstruction Notes

The rebuilt project should emit this vtable from the concrete `DATFile` class declaration and virtual method implementations. Do not hand-port the dwords as a static source table.

## Cross-References

- [UID:0001XK][FileStreamVtables](by-type/by-vtable/FileStreamVtables.md)
- [UID:00003G][DATFile](by-class/DATFile.md)
- [UID:0000IN][DATFile](by-file/DATFile.md)
- [UID:0003B7][0x00618920-0x00618950.DATFileVtableData](by-memory/0x00618920-0x00618950.DATFileVtableData.md)
- [UID:00012D][0x0049c130-0x0049d2cc.DATFile](by-memory/0x0049c130-0x0049d2cc.DATFile.md)
- [UID:0003H3][DATFileLayout](by-type/by-struct/DATFileLayout.md)

## Changes

- 2026-06-12 A004 Batch 319:
  - Created this exact source-local child from the former mixed [UID:0001XK][FileStreamVtables](by-type/by-vtable/FileStreamVtables.md) aggregate.
  - Summary/evidence: live IDA MCP reconfirmed the decorated vtable name, concrete slot targets and sizes, constructor install xref, unique range signature, and direct class parent gate.
