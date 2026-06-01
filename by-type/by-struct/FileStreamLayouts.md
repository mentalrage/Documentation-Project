*** UID:0001UG | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:78 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# File Stream Layouts

## Status

- Confidence: strong for object sizes and stable offsets; medium for final source-facing field names.
- Current Wave3 entity kind: struct/class layout support.
- Likely owner header: `util/File.h` for the abstract stream contract; concrete fields in `util/StdioFile.h` and `archive/DATFile.h`.
- Evidence basis: existing by-memory docs plus IDA MCP function, xref, vtable, and decompilation checks. `simroot_v2` remains only lead/provenance data, not scoring authority.

## Layout Summary

| Type | Size | Offset | Field hypothesis | Evidence |
| --- | --- | --- | --- | --- |
| `File` | `0x08` | `+0x00` | vtable / `LObject` head | `File::ScalarDeletingDestructor` restores vtable `0x006188e4`. |
| `File` | `0x08` | `+0x04` | implementation handle slot | Concrete implementations use this word as `FILE*` (`StdioFile`) or archive/container handle (`DATFile`). Keep the final base-field name open. |
| `StdioFile` | `0x0c` | `+0x00` | `File` base/vtable | Constructor installs vtable `0x0062d5ac`. |
| `StdioFile` | `0x0c` | `+0x04` | `FILE* m_fileHandle` | Constructor clears it, destructor closes it, virtual methods call CRT file APIs through it. |
| `StdioFile` | `0x0c` | `+0x08` | cached file size | `Open` copies the stat size field here; `GetSize` at `0x004f5ad0` returns it. |
| `DATFile` | `0x14` | `+0x00` | `File` base/vtable | Constructor installs vtable `0x00618924`. |
| `DATFile` | `0x14` | `+0x04` | archive/container handle | `Open`, `Close`, `Tell`, `GetSize`, and `Read` test this handle before using entry data. |
| `DATFile` | `0x14` | `+0x08` | entry-record pointer/handle | Set by `Open`/`OpenByIndex`; cleared by `Close`. |
| `DATFile` | `0x14` | `+0x0c` | current absolute payload offset | `Tell` subtracts the entry start offset from this value. |
| `DATFile` | `0x14` | `+0x10` | payload size | `GetSize` returns this value when an entry is open. |

## Interpretation Notes

The `File` base is abstract but not zero-state: it has an 8-byte footprint. The second word at `+0x04` is best treated as a protected implementation handle until a final source name is proven. This avoids forcing `StdioFile` and `DATFile` into incompatible layouts:

- `StdioFile` uses `+0x04` directly as the CRT `FILE*` stream.
- `DATFile` uses `+0x04` as an archive/container handle and stores entry/cursor fields after the base footprint.

This layout also explains why `DATFile` is 20 bytes while `StdioFile` is 12 bytes even though both implement the same vtable contract.

## IDA Evidence

- 2026-05-31 IDA MCP `lookup_funcs` confirms the concrete stream method starts and sizes, including `DATFile` constructor `0x0049c130` size `0x2a`, `DATFile::Open` `0x0049c180` size `0xbb`, `DATFile::Close` `0x0049c240` size `0x20`, `DATFile::Seek` `0x0049c260` size `0x6c`, `DATFile::Tell` `0x0049c2d0` size `0x17`, `DATFile::GetSize` `0x0049c2f0` size `0x14`, and `DATFile::Read` `0x0049c310` size `0x52`.
- 2026-05-31 IDA MCP `lookup_funcs` confirms `StdioFile` constructor `0x00582070` size `0x2a`, `StdioFile::Open` `0x005820d0` size `0xf9`, `StdioFile::Close` `0x005821d0` size `0x27`, `StdioFile::Tell` `0x00582200` size `0x0c`, `StdioFile::Seek` `0x00582210` size `0x1d`, `StdioFile::GetSize` `0x004f5ad0` size `0x04`, `StdioFile::Read` `0x00582230` size `0x1a`, and the deleting destructor `0x005824a0` size `0x56`.
- 2026-05-31 IDA MCP xrefs confirm `DATFile` installs vtable `0x00618924` at `0x0049c13f`, `StdioFile` installs/restores vtable `0x0062d5ac` at `0x0058207f`, `0x005820a6`, and `0x005824a9`, and `File` vtable `0x006188e4` is restored by base/destructor paths including `0x0049d396`, `0x005820b9`, and `0x005824be`.
- 2026-05-31 IDA MCP decompilation confirms `StdioFile` constructor clears `this[1]` and `this[2]`; `Open` stores the CRT `FILE*` in `this[1]` and the `_wstat` size in `this[2]`; `Close`, `Tell`, `Seek`, and `Read` use `this + 4` as the `FILE*`; `GetSize` returns `this[2]`.
- 2026-05-31 IDA MCP decompilation confirms `DATFile` constructor installs the DAT vtable and clears `this[1]`/`this[2]`; `Open` fills archive/container, entry pointer, cursor, and payload size fields; `Close` clears `this[1]`/`this[2]`; `Tell` returns `this[3] - *entryRecord`; `GetSize` returns `this[4]`; `Read` advances `this[3]` after copying from the mapped DAT payload.

## Source-Layout Implication

Keep declarations close to their implementations:

- `File` base declaration in `util/File.h`.
- `StdioFile` declaration in `util/StdioFile.h`, or together with `File` if the original source used a compact `FileIO` pair.
- `DATFile` declaration in `archive/DATFile.h`, because the extra fields are archive-entry state rather than generic file I/O state.

## Cross-References

- [UID:0001XK][FileStreamVtables](by-type/by-vtable/FileStreamVtables.md)
- [UID:0000JB][File](by-file/File.md)
- [UID:0000JD][FileIO](by-file/FileIO.md)
- [UID:0000O9][StdioFile](by-file/StdioFile.md)
- [UID:0000IN][DATFile](by-file/DATFile.md)
- [UID:00004V][File](by-class/File.md)
- [UID:0000E6][StdioFile](by-class/StdioFile.md)
- [UID:00003G][DATFile](by-class/DATFile.md)
- [UID:0001IT][0x005820d0-0x005821c9.StdioFileOpen](by-memory/0x005820d0-0x005821c9.StdioFileOpen.md)
- [UID:00019F][0x004f5ad0-0x004f5ad4.StdioFileGetSize](by-memory/0x004f5ad0-0x004f5ad4.StdioFileGetSize.md)
- [UID:00012D][0x0049c130-0x0049d2cb.DATFile](by-memory/0x0049c130-0x0049d2cb.DATFile.md)

## Changes

- 2026-05-31:
  - What existed before: metadata was `0/0` with `RECONSTRUCTABLE` blank, and the evidence basis still mentioned generated metadata as part of the scoring basis.
  - Changed to: scored `78/86`, marked reconstructable, and updated with current IDA MCP function, vtable xref, and decompilation evidence.
  - Summary/evidence: IDA MCP confirms the File/DATFile/StdioFile vtable installs, method boundaries, object sizes, and field offsets. Final source-facing member names and exact header/source split remain below the 95+ reconstruction-code threshold.
