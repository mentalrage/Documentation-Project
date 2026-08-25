*** UID:0003HZ | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:00004V | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:00004V | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
// Emitted code for this vtable is covered by [UID:00004V][File](by-class/File.md).
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# File Vtable

## Status

- Current role: source-local by-vtable page for the abstract `File` stream interface.
- Direct owner: [UID:00004V][File](by-class/File.md).
- Source context: File declaration in [UID:0000JB][File](by-file/File.md) / `NexusTK/util/File.h`; [UID:0000JD][FileIO](by-file/FileIO.md) is a non-emitting umbrella.
- Exact backing data: [UID:0002UV][0x006188e0-0x00618910.FileVtableData](by-memory/0x006188e0-0x00618910.FileVtableData.md).
- Split source: [UID:0001XK][FileStreamVtables](by-type/by-vtable/FileStreamVtables.md) mixed aggregate.

## Layout

The record at `0x006188e0-0x00618910` is `0x30` bytes / decimal 48 bytes, with an RTTI locator dword followed by `0x2c` bytes / decimal 44 bytes of vtable slots (Verified with int_convert.py).

| Slot | Address | Value | Role |
| --- | --- | --- | --- |
| locator | `0x006188e0` | `0x00646380` | `File` RTTI complete-object-locator pointer. |
| `+0x00` | `0x006188e4` | `0x0049d390` | scalar deleting destructor / base destructor path. |
| `+0x04` | `0x006188e8` | `0x004f4b10` | inherited `LObject`-style runtime slot. |
| `+0x08` | `0x006188ec` | `0x0041b6c0` | inherited no-op virtual / `nullsub_18`. |
| `+0x0c` | `0x006188f0` | `0x005ca28c` | pure virtual `Open`. |
| `+0x10` | `0x006188f4` | `0x005ca28c` | pure virtual `Close`. |
| `+0x14` | `0x006188f8` | `0x005ca28c` | pure virtual tell/current-position query. |
| `+0x18` | `0x006188fc` | `0x005ca28c` | pure virtual seek. |
| `+0x1c` | `0x00618900` | `0x005ca28c` | pure virtual size query. |
| `+0x20` | `0x00618904` | `0x005ca28c` | pure virtual read. |
| `+0x24` | `0x00618908` | `0x005ca28c` | pure virtual string/line read. |
| `+0x28` | `0x0061890c` | `0x005ca28c` | pure virtual raw line read. |

## 2026-06-12 A004 IDA Recheck

Live IDA MCP session `b001_nexustk` for `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe` reconfirmed this page's direct class ownership and split boundary:

- `entity_query` over `0x006188dc-0x00618954` reports `??_7File@@6B@` at `0x006188e4`, followed by `DATFileMgr`, `DATFileContainer`, and `DATFile` vtable names. This proves the abstract `File` record is a separate source-local owner within the former mixed stream-vtable aggregate.
- `lookup_funcs` reports slot targets: `0x0049d390` size `0x3e`, inherited `0x004f4b10` size `0x6`, `nullsub_18` size `0x3`, and `__purecall` at `0x005ca28c` size `0x1b`.
- `trace_data_flow backward 0x006188e4` reports the vftable dword and refs at `0x0049c16e`, `0x0049d294`, `0x0049d396`, `0x005820b9`, and `0x005824be`. The later all-dword audit classifies all five as destructor/restoration refs; no constructor writes the abstract File vptr.

## UID0002UV Source-Quality Callback

- Exact backing bytes for `[0x006188e0,0x00618910)` hash to `50E64382EF488DAED7C36979C4F6D21B81C12860ABA8B314F301A7FDC70ADF35` and form a unique 48-byte image signature.
- The record lies in read-only initialized `.rdata` at raw file offset `0x2172e0`; relocations are stripped, the relocation directory is absent, and no target relocation exists.
- File RTTI resolves to a two-entry File/LObject hierarchy with both PMD displacements zero, proving direct non-virtual inheritance at offset zero.
- The inherited slots are LObject runtime-class and no-op change-message methods. The eight File operation slots are `Open`, `Close`, `GetPosition`, `Seek`, `GetSize`, signed-count `Read`, ANSI `ReadLine`, and `ReadLineChars`.
- File/DAT/Stdio scalar-wrapper size immediates `4`, `0x14`, and `0x0c` prove File is data-member-free and four bytes. The shared-handle model is rejected.
- Source emits through the complete [UID:00004V][File](by-class/File.md) declaration. This page carries only the exact covered-by marker; no vtable array, RTTI struct, vptr store, purecall entry, or deleting-wrapper mechanics are handwritten.
- Score is `92/94`; owner/emitter and source-local split routing remain unchanged.
- `make_signature_for_range 0x006188e0-0x00618910` produced a unique 48-byte signature:
  `80 63 64 00 90 D3 49 00 10 4B 4F 00 C0 B6 41 00 8C A2 5C 00 8C A2 5C 00 8C A2 5C 00 8C A2 5C 00 8C A2 5C 00 8C A2 5C 00 8C A2 5C 00 8C A2 5C 00`.

## Assignment Decision

`AUTOGEN_PARENT_UID` is [UID:00004V][File](by-class/File.md). This child is `88/93`, the direct class parent is `86/89`, and the source-file parent [UID:0000JB][File](by-file/File.md) is `86/88`, so the strict child/direct-parent gate clears.

This page should not attach to [UID:0000JD][FileIO](by-file/FileIO.md) directly. `FileIO` is useful umbrella context, but the true direct semantic owner of this vtable declaration is the abstract `File` class.

## Reconstruction Notes

The rebuilt project should emit this vtable from the abstract `File` class declaration: virtual destructor/base slots plus pure virtual stream methods. Do not hand-port the dwords as a static source table.

## Cross-References

- [UID:0001XK][FileStreamVtables](by-type/by-vtable/FileStreamVtables.md)
- [UID:00004V][File](by-class/File.md)
- [UID:0000JB][File](by-file/File.md)
- [UID:0000JD][FileIO](by-file/FileIO.md)
- [UID:0002UV][0x006188e0-0x00618910.FileVtableData](by-memory/0x006188e0-0x00618910.FileVtableData.md)
- [UID:00012I][0x0049d390-0x0049d3cd.FileBaseDestructor](by-memory/0x0049d390-0x0049d3cd.FileBaseDestructor.md)
- [UID:0003H1][FileBaseLayout](by-type/by-struct/FileBaseLayout.md)

## Changes

- 2026-06-12 A004 Batch 319:
  - Created this exact source-local child from the former mixed [UID:0001XK][FileStreamVtables](by-type/by-vtable/FileStreamVtables.md) aggregate.
  - Summary/evidence: live IDA MCP reconfirmed the decorated vtable name, purecall slot block, slot target sizes, vptr restore/store xrefs, unique range signature, and direct class parent gate.
