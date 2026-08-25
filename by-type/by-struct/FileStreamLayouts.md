*** UID:0001UG | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
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

# File Stream Layouts

## Status

- Confidence: very strong for object sizes, stable offsets, split ownership, and mixed-index policy; medium-high for final source-facing field names.
- Current Wave3 entity kind: struct/class layout support; this page is now a non-emitting split index.
- Likely owner header: `util/File.h` for the abstract stream contract; concrete fields in `util/StdioFile.h` and `archive/DATFile.h`.
- Evidence basis: existing by-memory docs plus IDA MCP function, xref, vtable, and decompilation checks. `simroot_v2` remains only lead/provenance data, not scoring authority.

## Split Children

This page is no longer the source-emitting layout owner. It is a reviewed index over three source-owned declarations:

| Child | Direct owner | Role |
| --- | --- | --- |
| [UID:0003H1][FileBaseLayout](by-type/by-struct/FileBaseLayout.md) | [UID:00004V][File](by-class/File.md) | Abstract 4-byte data-member-free `File` base layout. |
| [UID:0003H2][StdioFileLayout](by-type/by-struct/StdioFileLayout.md) | [UID:0000E6][StdioFile](by-class/StdioFile.md) | Concrete 12-byte CRT-backed `File` implementation. |
| [UID:0003H3][DATFileLayout](by-type/by-struct/DATFileLayout.md) | [UID:00003G][DATFile](by-class/DATFile.md) | Concrete 20-byte DAT-entry-backed `File` implementation. |

## Layout Summary

| Type | Size | Offset | Field hypothesis | Evidence |
| --- | --- | --- | --- | --- |
| `File` | `0x04` | `+0x00` | vtable / inherited `LObject` head; no File data member | File scalar wrapper supplies complete object size `4`; LObject runtime metadata also records size `4`. |
| `StdioFile` | `0x0c` | `+0x00` | `File` base/vtable | Constructor installs vtable `0x0062d5ac`. |
| `StdioFile` | `0x0c` | `+0x04` | `FILE* m_fileHandle` | Constructor clears it, destructor closes it, virtual methods call CRT file APIs through it. |
| `StdioFile` | `0x0c` | `+0x08` | cached file size | `Open` copies the stat size field here; `GetSize` at `0x004f5ad0` returns it. |
| `DATFile` | `0x14` | `+0x00` | `File` base/vtable | Constructor installs vtable `0x00618924`. |
| `DATFile` | `0x14` | `+0x04` | archive/container handle | `Open`, `Close`, `Tell`, `GetSize`, and `Read` test this handle before using entry data. |
| `DATFile` | `0x14` | `+0x08` | entry-record pointer/handle | Set by `Open`/`OpenByIndex`; cleared by `Close`. |
| `DATFile` | `0x14` | `+0x0c` | current absolute payload offset | `Tell` subtracts the entry start offset from this value. |
| `DATFile` | `0x14` | `+0x10` | payload size | `GetSize` returns this value when an entry is open. |

## Interpretation Notes

The `File` base is abstract and data-member-free beyond its inherited four-byte LObject/vptr head. Offset `+0x04` begins concrete derived state:

- `StdioFile` owns `+0x04` as the CRT `FILE*` stream and `+0x08` as cached size.
- `DATFile` owns `+0x04` as an archive/container field and stores entry/cursor/size fields through `+0x10`.

This layout also explains why `DATFile` is 20 bytes while `StdioFile` is 12 bytes even though both implement the same vtable contract.

The sizes are `0x04` / decimal 4, `0x0c` / decimal 12, and `0x14` / decimal 20 (Verified with int_convert.py). The historical eight-byte shared-handle interpretation is rejected because it conflicts with all three scalar-wrapper size immediates and would place the accepted concrete fields at the wrong C++ offsets.

## IDA Evidence

- 2026-05-31 IDA MCP `lookup_funcs` confirms the concrete stream method starts and sizes, including `DATFile` constructor `0x0049c130` size `0x2a`, `DATFile::Open` `0x0049c180` size `0xbb`, `DATFile::Close` `0x0049c240` size `0x20`, `DATFile::Seek` `0x0049c260` size `0x6c`, `DATFile::Tell` `0x0049c2d0` size `0x17`, `DATFile::GetSize` `0x0049c2f0` size `0x14`, and `DATFile::Read` `0x0049c310` size `0x52`.
- 2026-05-31 IDA MCP `lookup_funcs` confirms `StdioFile` constructor `0x00582070` size `0x2a`, `StdioFile::Open` `0x005820d0` size `0xf9`, `StdioFile::Close` `0x005821d0` size `0x27`, `StdioFile::Tell` `0x00582200` size `0x0c`, `StdioFile::Seek` `0x00582210` size `0x1d`, `StdioFile::GetSize` `0x004f5ad0` size `0x04`, `StdioFile::Read` `0x00582230` size `0x1a`, and the deleting destructor `0x005824a0` size `0x56`.
- 2026-05-31 IDA MCP xrefs confirm `DATFile` installs vtable `0x00618924` at `0x0049c13f`, `StdioFile` installs/restores vtable `0x0062d5ac` at `0x0058207f`, `0x005820a6`, and `0x005824a9`, and `File` vtable `0x006188e4` is restored by base/destructor paths including `0x0049d396`, `0x005820b9`, and `0x005824be`.
- 2026-05-31 IDA MCP decompilation confirms `StdioFile` constructor clears `this[1]` and `this[2]`; `Open` stores the CRT `FILE*` in `this[1]` and the `_wstat` size in `this[2]`; `Close`, `Tell`, `Seek`, and `Read` use `this + 4` as the `FILE*`; `GetSize` returns `this[2]`.
- 2026-05-31 IDA MCP decompilation confirms `DATFile` constructor installs the DAT vtable and clears `this[1]`/`this[2]`; `Open` fills archive/container, entry pointer, cursor, and payload size fields; `Close` clears `this[1]`/`this[2]`; `Tell` returns `this[3] - *entryRecord`; `GetSize` returns `this[4]`; `Read` advances `this[3]` after copying from the mapped DAT payload.
- 2026-06-11 A005 normal-task IDA MCP refresh reconfirmed the same layout split. `lookup_funcs` reports `File` base destructor `0x0049d390` size `0x3e`, the `DATFile` method set from constructor `0x0049c130` size `0x2a` through scalar deleting destructor `0x0049d280` size `0x4c`, and the `StdioFile` method set from constructor `0x00582070` size `0x2a` through scalar deleting destructor `0x005824a0` size `0x56`, with non-contiguous `StdioFile::GetSize` at `0x004f5ad0` size `0x04`.
- 2026-06-12 A004 Batch297 live IDA MCP refresh used active session `b001_nexustk` and reconfirmed all shared stream slot targets: `File` destructor `0x0049d390` size `0x3e`; DATFile constructor/open/close/seek/tell/size/read/raw-line/string-line sizes `0x2a`, `0xbb`, `0x20`, `0x6c`, `0x17`, `0x14`, `0x52`, `0x6f`, and `0xb9`; StdioFile constructor/open/close/tell/seek/size/read/raw-line/string-line/deleting-destructor sizes `0x2a`, `0xf9`, `0x27`, `0x0c`, `0x1d`, `0x04`, `0x1a`, `0x71`, `0xa9`, and `0x56`.
- 2026-06-11 IDA MCP `xrefs_to` reconfirmed `File` vtable `0x006188e4` restore/store refs from `DATFile` destructor/deleting destructor, `File` destructor, and `StdioFile` destructor/deleting destructor; `DATFile` vtable `0x00618924` is installed by `0x0049c13f`; `StdioFile` vtable `0x0062d5ac` is installed/restored at `0x0058207f`, `0x005820a6`, and `0x005824a9`.
- 2026-06-11 IDA MCP vtable dword read confirmed the shared slot map: `File` has the base destructor/runtime/no-op slots followed by `__purecall` operation slots; `DATFile` fills those operation slots with `0x0049c180`, `0x0049c240`, `0x0049c2d0`, `0x0049c260`, `0x0049c2f0`, `0x0049c310`, `0x0049c3e0`, and `0x0049c370`; `StdioFile` fills the same slots with `0x005820d0`, `0x005821d0`, `0x00582200`, `0x00582210`, `0x004f5ad0`, `0x00582230`, `0x005822d0`, and `0x00582250`.
- 2026-06-12 A004 Batch297 `xrefs_to` reconfirmed vtable ownership: `File` vtable `0x006188e4` has restore/store refs at `0x0049c16e`, `0x0049d294`, `0x0049d396`, `0x005820b9`, and `0x005824be`; `DATFile` vtable `0x00618924` is installed at `0x0049c13f`; `StdioFile` vtable `0x0062d5ac` is installed/restored at `0x0058207f`, `0x005820a6`, and `0x005824a9`.
- 2026-06-12 representative `analyze_function` results reconfirmed concrete field writes: `StdioFile::Open` stores `_wfopen` output at `this[1]` / `+0x04` and `_wstat` size at `this[2]` / `+0x08`; `DATFile::Open` stores archive/container at `this[1]`, entry record at `this[2]`, current absolute payload offset at `this[3]`, and payload size at `this[4]`.
- 2026-06-11 representative decompilation reconfirmed the offset semantics: `DATFile::Open` stores archive/container at `+0x04`, entry record at `+0x08`, absolute payload cursor at `+0x0c`, and payload size at `+0x10`; `DATFile::Tell` returns `+0x0c - *(entryRecord)`, `GetSize` returns `+0x10`, and `Read` copies from mapped archive data then advances `+0x0c`. `StdioFile::Open` stores `_wfopen` result at `+0x04` and `_wstat` size at `+0x08`; `Close`, `Tell`, `Seek`, `GetSize`, and `Read` use those two fields exactly as documented.

## Assignment Decision

`AUTOGEN_PARENT_UID` remains blank intentionally, and `RECONSTRUCTABLE` is now `FALSE` for this page itself. This page is a cross-owner layout-family index, not a single source declaration:

- The abstract four-byte data-member-free `File` base belongs with [UID:00004V][File](by-class/File.md) and source root [UID:0000JB][File](by-file/File.md).
- The concrete 12-byte `StdioFile` fields belong with [UID:0000E6][StdioFile](by-class/StdioFile.md) and source root [UID:0000O9][StdioFile](by-file/StdioFile.md).
- The concrete 20-byte `DATFile` fields belong with [UID:00003G][DATFile](by-class/DATFile.md) and source root [UID:0000IN][DATFile](by-file/DATFile.md).

The broader [UID:0000JD][FileIO](by-file/FileIO.md) umbrella clears `85/85`, but it is not the direct semantic owner for the archive-backed `DATFile` fields. Attaching this mixed layout page to `File`, `FileIO`, `StdioFile`, or `DATFile` would hide one or more concrete owners, so the strict child/direct-parent gate is intentionally satisfied through split children instead: [UID:0003H1][FileBaseLayout](by-type/by-struct/FileBaseLayout.md) routes to [UID:00004V][File](by-class/File.md), [UID:0003H2][StdioFileLayout](by-type/by-struct/StdioFileLayout.md) routes to [UID:0000E6][StdioFile](by-class/StdioFile.md), and [UID:0003H3][DATFileLayout](by-type/by-struct/DATFileLayout.md) routes to [UID:00003G][DATFile](by-class/DATFile.md).

## Score Rationale

| Field | Value | Rationale |
| --- | ---: | --- |
| Completion | 90 | The page records the corrected base/concrete sizes, exact offsets, wrapper-size proof, vtable ownership, concrete virtual slot maps, signed Read contract, source-layout implications, exact split children, and explicit non-emitting mixed-index decision. |
| Confidence | 93 | The layout facts and split ownership are backed by independent scalar-wrapper sizes, RTTI/runtime metadata, current IDA function/xref/vtable/decompilation evidence, and matching class/file/memory pages. Confidence remains below final because derived field spellings and historical header split are inferred. |
| Parent | blank | No single direct semantic parent owns all three layouts; separate class/file pages own the individual concrete declarations. |

## Source-Layout Implication

The common source declaration uses `size_t Read(void *buffer, int count)`. DATFile's signed-negative sentinel is behaviorally observable and fixes the common parameter type; StdioFile's CRT call does not make the virtual parameter unsigned.

## UID0002UV Source-Quality Callback

- Preserved this page as ownerless, emitterless, `RECONSTRUCTABLE:FALSE`, with a blank formal.
- Corrected the shared layout union to File `4`, StdioFile `0x0c`, and DATFile `0x14`.
- Removed the current shared-handle model and retained it only as superseded history.
- Added the exact File/DAT/Stdio scalar-wrapper size triad, LObject size corroboration, and source-compatible derived-field ownership.
- Synchronized the common source-facing operation vocabulary to `GetPosition` and signed-count `Read`.
- Raised only this page from `88/91` to `90/93`; all three source-local child routes remain independent.

Keep declarations close to their implementations:

- `File` base declaration in `util/File.h`.
- `StdioFile` declaration in `util/StdioFile.h`, or together with `File` if the original source used a compact `FileIO` pair.
- `DATFile` declaration in `archive/DATFile.h`, because the extra fields are archive-entry state rather than generic file I/O state.

## Cross-References

- [UID:0001XK][FileStreamVtables](by-type/by-vtable/FileStreamVtables.md)
- [UID:0003H1][FileBaseLayout](by-type/by-struct/FileBaseLayout.md)
- [UID:0003H2][StdioFileLayout](by-type/by-struct/StdioFileLayout.md)
- [UID:0003H3][DATFileLayout](by-type/by-struct/DATFileLayout.md)
- [UID:0000JB][File](by-file/File.md)
- [UID:0000JD][FileIO](by-file/FileIO.md)
- [UID:0000O9][StdioFile](by-file/StdioFile.md)
- [UID:0000IN][DATFile](by-file/DATFile.md)
- [UID:00004V][File](by-class/File.md)
- [UID:0000E6][StdioFile](by-class/StdioFile.md)
- [UID:00003G][DATFile](by-class/DATFile.md)
- [UID:0001IT][0x005820d0-0x005821c9.StdioFileOpen](by-memory/0x005820d0-0x005821c9.StdioFileOpen.md)
- [UID:00019F][0x004f5ad0-0x004f5ad4.StdioFileGetSize](by-memory/0x004f5ad0-0x004f5ad4.StdioFileGetSize.md)
- [UID:00012D][0x0049c130-0x0049d2cc.DATFile](by-memory/0x0049c130-0x0049d2cc.DATFile.md)

## Changes

- 2026-06-12 A004 Batch 297:
  - What existed before: this page was `85/88`, `RECONSTRUCTABLE:TRUE`, and parent-blank as a mixed File/DATFile/StdioFile layout family.
  - Changed to: `88/91`, `RECONSTRUCTABLE:FALSE`, and a non-emitting split index with exact reconstructable children [UID:0003H1][FileBaseLayout](by-type/by-struct/FileBaseLayout.md), [UID:0003H2][StdioFileLayout](by-type/by-struct/StdioFileLayout.md), and [UID:0003H3][DATFileLayout](by-type/by-struct/DATFileLayout.md).
  - Summary/evidence: live IDA MCP reconfirmed method sizes, vtable install/restore refs, concrete `Open` field writes, and the no-single-direct-parent issue; the child pages now carry the source-owned declarations and parent routes.
- 2026-05-31:
  - What existed before: metadata was `0/0` with `RECONSTRUCTABLE` blank, and the evidence basis still mentioned generated metadata as part of the scoring basis.
  - Changed to: scored `78/86`, marked reconstructable, and updated with current IDA MCP function, vtable xref, and decompilation evidence.
  - Summary/evidence: IDA MCP confirms the File/DATFile/StdioFile vtable installs, method boundaries, object sizes, and field offsets. Final source-facing member names and exact header/source split remain below the 95+ reconstruction-code threshold.
- 2026-06-11:
  - Changed to: `85/88`, still reconstructable, and still parent-blank.
  - Summary/evidence: A005 normal-task live IDA MCP refreshed the File/DATFile/StdioFile function boundaries, vtable install/restore refs, vtable slot dwords, and representative decompilation for the fields at `+0x04`, `+0x08`, `+0x0c`, and `+0x10`. The child now clears its score gate, but no single direct parent clears the ownership gate for the whole mixed layout family: `File` owns the abstract base, `StdioFile` owns the loose-file fields, and `DATFile` owns the archive-backed fields. C++ remains blank under the 95/95 source-emission gate.
