*** UID:0001XK | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:78 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# File Stream Vtables

## Status

- Confidence: strong for slot order and implementation mapping.
- Current Wave3 entity kind: vtable/type-layout support, not a standalone source file.
- Likely owner header: `util/File.h` for the abstract contract; concrete implementations in `util/StdioFile.cpp` and `archive/DATFile.cpp`.
- Evidence basis: IDA MCP function lookup, vtable xrefs, and method decompilation checks. Generated source/metadata is useful lead data only.

## Shared Interface Contract

`File`, `DATFile`, and `StdioFile` share the same primary vtable shape. Slots `+0x0` through `+0x8` are destructor/base runtime slots, and slots `+0x0c` through `+0x28` are the stream interface.

| Slot | Abstract `File` at `0x006188e4` | `DATFile` at `0x00618924` | `StdioFile` at `0x0062d5ac` | Interface role |
| --- | --- | --- | --- | --- |
| `+0x00` | `0x0049d390` | `0x0049d280` | `0x005824a0` | scalar deleting destructor |
| `+0x04` | `0x004f4b10` | `0x004f4b10` | `0x004f4b10` | inherited `LObject`/runtime virtual |
| `+0x08` | `nullsub_18` | `nullsub_18` | `nullsub_18` | inherited no-op virtual |
| `+0x0c` | `__purecall` | `0x0049c180` | `0x005820d0` | `Open` |
| `+0x10` | `__purecall` | `0x0049c240` | `0x005821d0` | `Close` |
| `+0x14` | `__purecall` | `0x0049c2d0` | `0x00582200` | `Tell` / `GetPosition` |
| `+0x18` | `__purecall` | `0x0049c260` | `0x00582210` | `Seek` |
| `+0x1c` | `__purecall` | `0x0049c2f0` | `0x004f5ad0` | `GetSize` |
| `+0x20` | `__purecall` | `0x0049c310` | `0x00582230` | `Read` |
| `+0x24` | `__purecall` | `0x0049c3e0` | `0x005822d0` | `ReadLine` into `LString` |
| `+0x28` | `__purecall` | `0x0049c370` | `0x00582250` | raw line read into caller buffer |

RTTI pointers sit immediately before the first slot:

- `File`: RTTI at `0x006188e0`, vtable entries `0x006188e4-0x00618910`.
- `DATFile`: RTTI at `0x00618920`, vtable entries `0x00618924-0x00618950`.
- `StdioFile`: RTTI at `0x0062d5a8`, vtable entries `0x0062d5ac-0x0062d5d8`.

## Xref Evidence

IDA MCP `xrefs_to` on 2026-05-25 confirms:

- `File` vtable is restored by `DATFile` and `StdioFile` destructor paths and by `File::ScalarDeletingDestructor`.
- `DATFile` vtable is installed by `DATFile::DATFile` at `0x0049c13f`.
- `StdioFile` vtable is installed/restored by constructor/destructor/deleting-destructor paths at `0x0058207f`, `0x005820a6`, and `0x005824a9`.

2026-05-31 IDA MCP recheck confirms the same vtable ownership:

- `File` vtable `0x006188e4` has data xrefs from `DATFile`/`StdioFile` and `File` destructor paths, including `0x0049d396`, `0x005820b9`, and `0x005824be`.
- `DATFile` vtable `0x00618924` has the constructor install xref at `0x0049c13f`.
- `StdioFile` vtable `0x0062d5ac` has install/restore xrefs at `0x0058207f`, `0x005820a6`, and `0x005824a9`.
- `lookup_funcs` confirms concrete virtual method starts match the table: DATFile stream interface `0x0049c180`, `0x0049c240`, `0x0049c2d0`, `0x0049c260`, `0x0049c2f0`, `0x0049c310`, `0x0049c3e0`, `0x0049c370`; StdioFile stream interface `0x005820d0`, `0x005821d0`, `0x00582200`, `0x00582210`, `0x004f5ad0`, `0x00582230`, `0x005822d0`, `0x00582250`.

This supports a common `File` base declaration with concrete loose-file and DAT-backed stream implementations. It also explains why callers can switch between `DATFile` and `StdioFile` in file-loader and Miles callback code without owning the stream interface themselves.

## Source-Layout Implication

- Put the abstract class declaration in `util/File.h`.
- Keep the small `File` destructor body in `util/File.cpp` or a compact `util/FileIO.cpp`.
- Keep `StdioFile` in `util/StdioFile.cpp` because it owns CRT `_wstat`, `_wfopen`, `FILE*`, `ftell`, `fseek`, and `fread` behavior.
- Keep `DATFile` in `archive/DATFile.cpp` because it owns archive-entry cursor state and depends on `DATFileMgr` lookup/index state.

## Cross-References

- [UID:0000JB][File](by-file/File.md)
- [UID:0000JD][FileIO](by-file/FileIO.md)
- [UID:0000O9][StdioFile](by-file/StdioFile.md)
- [UID:0000IN][DATFile](by-file/DATFile.md)
- [UID:00004V][File](by-class/File.md)
- [UID:0000E6][StdioFile](by-class/StdioFile.md)
- [UID:00003G][DATFile](by-class/DATFile.md)
- [UID:0001UG][FileStreamLayouts](by-type/by-struct/FileStreamLayouts.md)
- [UID:00012I][0x0049d390-0x0049d3cd.FileBaseDestructor](by-memory/0x0049d390-0x0049d3cd.FileBaseDestructor.md)
- [UID:0001IR][0x00582070-0x005824f6.StdioFile](by-memory/0x00582070-0x005824f6.StdioFile.md)
- [UID:00012D][0x0049c130-0x0049d2cb.DATFile](by-memory/0x0049c130-0x0049d2cb.DATFile.md)

## Changes

- 2026-05-31:
  - What existed before: metadata was `0/0` with `RECONSTRUCTABLE` blank, despite the vtable mapping already being documented.
  - Changed to: scored `78/88`, marked reconstructable, and added current IDA MCP vtable xref/method-boundary evidence.
  - Summary/evidence: IDA MCP verifies the vtable install/restore sites and the concrete virtual method starts for File, DATFile, and StdioFile. No C++ reconstruction code was added because final declarations and source split are not yet at the 95+ gate.
