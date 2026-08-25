*** UID:0003H2 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:93 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000E6 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000E6 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
// StdioFile storage layout is declared by the StdioFile class; no standalone emitted code for this layout page.
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# StdioFile Layout

## Status

- Entity kind: class layout.
- Disposition: reconstructable source declaration for the CRT-backed concrete `File` stream.
- Direct parent: [UID:0000E6][StdioFile](by-class/StdioFile.md).
- Source owner: [UID:0000O9][StdioFile](by-file/StdioFile.md), under the utility [UID:0000JD][FileIO](by-file/FileIO.md) layer.
- Evidence basis: live IDA MCP checks on 2026-06-12 plus [UID:0001UG][FileStreamLayouts](by-type/by-struct/FileStreamLayouts.md), [UID:0001XK][FileStreamVtables](by-type/by-vtable/FileStreamVtables.md), [UID:0001IR][0x00582070-0x005824f6.StdioFile](by-memory/0x00582070-0x005824f6.StdioFile.md), [UID:0001IT][0x005820d0-0x005821c9.StdioFileOpen](by-memory/0x005820d0-0x005821c9.StdioFileOpen.md), [UID:0001IV][0x00582200-0x0058224a.StdioFileVirtualPositionReadMethods](by-memory/0x00582200-0x0058224a.StdioFileVirtualPositionReadMethods.md), and [UID:00019F][0x004f5ad0-0x004f5ad4.StdioFileGetSize](by-memory/0x004f5ad0-0x004f5ad4.StdioFileGetSize.md).

This page splits the concrete `StdioFile` layout out of the mixed [UID:0001UG][FileStreamLayouts](by-type/by-struct/FileStreamLayouts.md) family so it can route to the true direct class owner.

2026-07-01 B010 UID0000O9 implementation adds only a formal no-standalone-code marker here. The actual source storage declaration is emitted by [UID:0000E6][StdioFile](by-class/StdioFile.md) with `FILE *m_fileHandle` at `+0x04` and `int m_fileSize` at `+0x08`; this layout page remains support evidence for offsets and object size.

## Layout

`StdioFile` is a 12-byte (`0x0c`; decimal 12, Verified with int_convert.py) concrete subclass of the 4-byte (`0x04`; decimal 4, Verified with int_convert.py) data-member-free [UID:00004V][File](by-class/File.md) base.

| Offset | Size | Field hypothesis | Evidence |
| --- | ---: | --- | --- |
| `+0x00` | `0x04` | `File`/`LObject` vtable head | Constructor `0x00582070` installs vtable `0x0062d5ac`; destructor paths restore the abstract `File` vtable. |
| `+0x04` | `0x04` | inferred `FILE* m_fileHandle` | UID0001IQ constructor clears this slot; `Open` stores the `_wfopen` result in `this[1]`; `Close`, `Tell`, `Seek`, `Read`, and destructor paths consume the same slot. The source-facing field name is inferred, not symbol-proven. |
| `+0x08` | `0x04` | inferred `m_fileSize` / cached file size | UID0001IQ constructor clears this slot; `Open` copies the `_wstat` size result into `this[2]`; `GetSize` at `0x004f5ad0` returns `this[2]`. The source-facing field name is inferred, not symbol-proven. |

## IDA Evidence

2026-06-12 A004 live IDA MCP `lookup_funcs` confirms the concrete slot targets and sizes: constructor `0x00582070` size `0x2a`, `Open` `0x005820d0` size `0xf9`, `Close` `0x005821d0` size `0x27`, `GetPosition` (historically `Tell`) `0x00582200` size `0x0c`, `Seek` `0x00582210` size `0x1d`, `GetSize` `0x004f5ad0` size `0x04`, `Read` `0x00582230` size `0x1a`, raw-line read `0x00582250` size `0x71`, string line read `0x005822d0` size `0xa9`, and scalar deleting destructor `0x005824a0` size `0x56`.

`xrefs_to 0x0062d5ac` reports the vtable install/restore refs at `0x0058207f`, `0x005820a6`, and `0x005824a9`.

`analyze_function 0x005820d0` confirms `Open` calls the imported `_wstat` wrapper, throws `FileError` on stat failure, calls the imported `_wfopen` wrapper with binary-read mode, stores the returned handle at `this[1]`, stores the stat size at `this[2]`, and throws `FileError` when open fails. Its callers include startup video/logo, main-menu art, and map `.cmp` loading paths (`0x004f53b0`, `0x004f5710`, `0x004f6700`, and `0x00504b90`).

2026-06-29 B006 UID0001IQ implementation refresh uses current MCP session `3fa0535f` to reconfirm constructor `0x00582070-0x0058209a` as a 42-byte / `0x2a` one-block body that calls the inherited base constructor, installs the `StdioFile` vtable, and zeroes offsets `+0x04` and `+0x08`. Formal constructor C++ now uses inferred source-facing names `m_fileHandle` and `m_fileSize`; decompiler names `this[1]`, `this[2]`, and the stale `statBuffer_size` placeholder are evidence only, not source names.

## Assignment Decision

`AUTOGEN_PARENT_UID` is [UID:0000E6][StdioFile](by-class/StdioFile.md). The child layout is `90/93`, and the direct class parent is `91/92`. This page attaches to the class rather than the file root because it is class storage.

## Score Rationale

Completion is `90` because the complete object/base sizes, both concrete fields, scalar-wrapper size proof, virtual method evidence, signed Read contract, vtable refs, source owner, split rationale, and unchanged no-standalone-code formal are documented. Confidence is `93` because constructor/open/read/destructor evidence and compiler size `0x0c` agree; exact historical field spelling remains inferred.

## UID0002UV Source-Quality Callback

- Preserved the existing formal marker byte-for-byte.
- Corrected the inherited File base from eight bytes to four bytes.
- Confirmed `FILE *m_fileHandle` at `+0x04` and `int m_fileSize` at `+0x08` are StdioFile-owned fields, not reuse of a File handle.
- StdioFile scalar deleting wrapper's `0x0c` size immediate, constructor zeroing, Open stores, method reads, and destructor behavior all agree with this complete layout.
- The common source contract is `size_t Read(void *buffer, int count)`; the signed parameter is proven by DATFile's negative-count sentinel and does not change the CRT byte-count return.
- Historical `Tell` and compact FileIO wording remain only as superseded naming/source-layout context.
- Raised only this page from `87/89` to `90/93`; owner/emitter/source route remain unchanged.

## Cross-References

- [UID:0001UG][FileStreamLayouts](by-type/by-struct/FileStreamLayouts.md)
- [UID:0001XK][FileStreamVtables](by-type/by-vtable/FileStreamVtables.md)
- [UID:0000E6][StdioFile](by-class/StdioFile.md)
- [UID:0000O9][StdioFile](by-file/StdioFile.md)
- [UID:00004V][File](by-class/File.md)
- [UID:0001IR][0x00582070-0x005824f6.StdioFile](by-memory/0x00582070-0x005824f6.StdioFile.md)
- [UID:0001IT][0x005820d0-0x005821c9.StdioFileOpen](by-memory/0x005820d0-0x005821c9.StdioFileOpen.md)
- [UID:0001IV][0x00582200-0x0058224a.StdioFileVirtualPositionReadMethods](by-memory/0x00582200-0x0058224a.StdioFileVirtualPositionReadMethods.md)
- [UID:00019F][0x004f5ad0-0x004f5ad4.StdioFileGetSize](by-memory/0x004f5ad0-0x004f5ad4.StdioFileGetSize.md)

## Changes

- 2026-07-01 B010 UID0000O9 empty-emitter family implementation:
  - Before: `86/88`, formal C++ blank.
  - After: `87/89`; inserted formal no-standalone-code marker.
  - Summary/evidence: layout evidence remains class-storage support only. Source fields are emitted by [UID:0000E6][StdioFile](by-class/StdioFile.md) as `m_fileHandle` and `m_fileSize`; this page preserves the complete-object offsets, object size, and inferred-field-name caveat.
- 2026-06-29 B006 UID0001IQ constructor implementation:
  - Score unchanged.
  - Summary/evidence: refreshed layout rows with constructor-specific source names for `+0x04` inferred `m_fileHandle` and `+0x08` inferred `m_fileSize` / cached file size. Current MCP session `3fa0535f` reconfirmed UID0001IQ exact range, 42-byte size, one-block body, vtable install, field zeroing, `Open` writer provenance, and rejected decompiler field names; exact original field spellings remain inferred.
- 2026-06-12 A004 Batch 297 split: created this exact source-owned child from the former mixed `FileStreamLayouts` page. Live IDA MCP reconfirmed the method sizes, vtable refs, `_wstat`/`_wfopen` field stores, caller set, and 12-byte layout; the old note left formal C++ blank below the then-used `95/95` source-emission gate. UID0001IQ's constructor-specific C++ gate was superseded by the 2026-06-29 B006 implementation, and the 2026-07-01 B010 callback adds this layout page's formal no-standalone-code marker while it remains a declaration/support page.
