*** UID:0003H1 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:00004V | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:00004V | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
// File storage is declared by [UID:00004V][File](by-class/File.md); this layout page emits no standalone code.
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# File Base Layout

## Status

- Entity kind: class/base layout.
- Disposition: reconstructable source declaration for the abstract `File` stream base.
- Direct parent: [UID:00004V][File](by-class/File.md).
- Source owner: [UID:0000JB][File](by-file/File.md), with the declaration in `NexusTK/util/File.h`; [UID:0000JD][FileIO](by-file/FileIO.md) is a non-emitting umbrella.
- Evidence basis: live IDA MCP checks on 2026-06-12 plus [UID:0001UG][FileStreamLayouts](by-type/by-struct/FileStreamLayouts.md), [UID:0001XK][FileStreamVtables](by-type/by-vtable/FileStreamVtables.md), [UID:00012I][0x0049d390-0x0049d3cd.FileBaseDestructor](by-memory/0x0049d390-0x0049d3cd.FileBaseDestructor.md), and [UID:0002UV][0x006188e0-0x00618910.FileVtableData](by-memory/0x006188e0-0x00618910.FileVtableData.md).

This page splits the abstract base layout out of the mixed [UID:0001UG][FileStreamLayouts](by-type/by-struct/FileStreamLayouts.md) family so it can route to the true direct class owner.

## Layout

`File` is a 4-byte (`0x04`; decimal 4, Verified with int_convert.py) data-member-free abstract stream base.

| Offset | Size | Field hypothesis | Evidence |
| --- | ---: | --- | --- |
| `+0x00` | `0x04` | vtable pointer / inherited `LObject` head | `File` destructor `0x0049d390` restores vtable `0x006188e4`; [UID:0001XK][FileStreamVtables](by-type/by-vtable/FileStreamVtables.md) records destructor/base/purecall slot layout. |

There is no File field at `+0x04`. That offset begins derived-class state: StdioFile owns `FILE *m_fileHandle`, while DATFile owns its archive/container field. The former protected shared-handle row is retained only as a rejected historical model.

## IDA Evidence

2026-06-12 A004 live IDA MCP `lookup_funcs` confirms `File` base destructor `0x0049d390` size `0x3e`.

The decisive object-size evidence is compiler-generated:

| Class | Scalar-wrapper allocation size | Source-compatible layout |
| --- | ---: | --- |
| File | `4` | inherited LObject/vptr head only |
| StdioFile | `0x0c` | File plus `FILE*` at `+0x04` and cached size at `+0x08` |
| DATFile | `0x14` | File plus four DAT fields at `+0x04/+0x08/+0x0c/+0x10` |

LObject runtime-class metadata independently records object size `4`. File RTTI contains exactly File and LObject descriptors with zero PMD displacement, so no hidden virtual-base or multiple-inheritance storage exists.

The same pass `xrefs_to 0x006188e4` reports five vptr-store/restore refs:

| Ref | Context |
| --- | --- |
| `0x0049c16e` | `DATFile` destructor path restores the abstract base vtable. |
| `0x0049d294` | `DATFile` scalar deleting destructor path. |
| `0x0049d396` | `File` base destructor body. |
| `0x005820b9` | `StdioFile` destructor path restores the abstract base vtable. |
| `0x005824be` | `StdioFile` scalar deleting destructor path. |

## Assignment Decision

`AUTOGEN_PARENT_UID` is [UID:00004V][File](by-class/File.md). The child layout is `92/94`, and the direct class parent is `92/93`. This page attaches to the class, not to the broader FileIO umbrella, because it is the base-class storage declaration.

## Score Rationale

Completion is `92` because the exact four-byte size, absence of fields, RTTI hierarchy, vtable evidence, scalar-wrapper size triad, concrete derived offsets, source owner, formal disposition, and rejected shared-handle history are documented. Confidence is `94` because independent compiler metadata and concrete layouts agree; only historical source spelling remains unrecovered.

## UID0002UV Source-Quality Callback

- Applied the exact class-covered no-standalone-code marker.
- Corrected File size from eight bytes to four and removed the nonexistent shared implementation handle.
- Preserved all five destructor/restoration vptr refs and classified them precisely; none is a constructor write.
- Recorded the File/DAT/Stdio wrapper-size triad and LObject object-size corroboration.
- Preserved source-local ownership under File and the non-emitting mixed-layout index.
- Raised only this page from `86/90` to `92/94`.

## Cross-References

- [UID:0001UG][FileStreamLayouts](by-type/by-struct/FileStreamLayouts.md)
- [UID:0001XK][FileStreamVtables](by-type/by-vtable/FileStreamVtables.md)
- [UID:00004V][File](by-class/File.md)
- [UID:0000JB][File](by-file/File.md)
- [UID:0000E6][StdioFile](by-class/StdioFile.md)
- [UID:00003G][DATFile](by-class/DATFile.md)
- [UID:00012I][0x0049d390-0x0049d3cd.FileBaseDestructor](by-memory/0x0049d390-0x0049d3cd.FileBaseDestructor.md)
- [UID:0002UV][0x006188e0-0x00618910.FileVtableData](by-memory/0x006188e0-0x00618910.FileVtableData.md)

## Changes

- 2026-06-12 A004 Batch 297 split: created this exact source-owned child from the former mixed `FileStreamLayouts` page. Live IDA MCP reconfirmed the destructor size, vtable restore refs, and shared subclass handle-slot reuse; final C++ remains blank below the 95/95 source-emission gate.
