*** UID:0001XK | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:NONE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:FALSE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# File Stream Vtables

## Status

- Confidence: very strong for slot order, vtable bytes, implementation mapping, and split ownership; this aggregate is non-emitting because it intentionally spans three direct class/source owners.
- Current Wave3 entity kind: vtable/type-layout support, not a standalone source file.
- Likely owner header: `util/File.h` for the abstract contract; concrete implementations in `util/StdioFile.cpp` and `archive/DATFile.cpp`.
- Source-local split pages: [UID:0003HZ][FileVtable](by-type/by-vtable/FileVtable.md), [UID:0003I0][DATFileVtable](by-type/by-vtable/DATFileVtable.md), and [UID:0003I1][StdioFileVtable](by-type/by-vtable/StdioFileVtable.md).
- Exact backing data pages: [UID:0002UV][0x006188e0-0x00618910.FileVtableData](by-memory/0x006188e0-0x00618910.FileVtableData.md), [UID:0003B7][0x00618920-0x00618950.DATFileVtableData](by-memory/0x00618920-0x00618950.DATFileVtableData.md), and [UID:00026L][0x0062d5a8-0x0062d5f8.StdioFileStringIterReadOnlyData](by-memory/0x0062d5a8-0x0062d5f8.StdioFileStringIterReadOnlyData.md).
- Evidence basis: IDA MCP function lookup, vtable xrefs, dword/value-name scans, and method decompilation checks. Generated source/metadata is useful lead data only.

## Source-Local Split Pages

This page is now the non-emitting shared ABI index. The reconstructable ownership routes live in exact source-local children:

| Child | Direct owner | Backing evidence | Gate |
| --- | --- | --- | --- |
| [UID:0003HZ][FileVtable](by-type/by-vtable/FileVtable.md) | [UID:00004V][File](by-class/File.md) | [UID:0002UV][0x006188e0-0x00618910.FileVtableData](by-memory/0x006188e0-0x00618910.FileVtableData.md) | child `92/94`, parent `92/93` |
| [UID:0003I0][DATFileVtable](by-type/by-vtable/DATFileVtable.md) | [UID:00003G][DATFile](by-class/DATFile.md) | [UID:0003B7][0x00618920-0x00618950.DATFileVtableData](by-memory/0x00618920-0x00618950.DATFileVtableData.md) | child `88/93`, parent `86/88` |
| [UID:0003I1][StdioFileVtable](by-type/by-vtable/StdioFileVtable.md) | [UID:0000E6][StdioFile](by-class/StdioFile.md) | [UID:00026L][0x0062d5a8-0x0062d5f8.StdioFileStringIterReadOnlyData](by-memory/0x0062d5a8-0x0062d5f8.StdioFileStringIterReadOnlyData.md) | child score unchanged, parent `91/92` |

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
| `+0x20` | `__purecall` | `0x0049c310` | `0x00582230` | `size_t Read(void *buffer, int count)`; DAT treats negative count as the full payload |
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

2026-06-11 IDA MCP refresh reconfirms the dword-level table data and target extents:

- `File` range `0x006188e0-0x00618910`: `0x006188e0 -> const File::RTTI Complete Object Locator`, slot `0x006188e4 -> 0x0049d390`, inherited/base slots `0x004f4b10` and `nullsub_18`, and eight `__purecall` operation slots from `0x006188f0` through `0x0061890c`. Data xrefs to `0x006188e4` are still `0x0049c16e`, `0x0049d294`, `0x0049d396`, `0x005820b9`, and `0x005824be`.
- `DATFile` table at `0x00618920-0x00618950`: `0x00618920 -> const DATFile::RTTI Complete Object Locator`, slot `0x00618924 -> 0x0049d280`, inherited/base slots, and concrete stream slots `0x0049c180`, `0x0049c240`, `0x0049c2d0`, `0x0049c260`, `0x0049c2f0`, `0x0049c310`, `0x0049c3e0`, and `0x0049c370`; constructor install xref remains `0x0049c13f`.
- `StdioFile` table at `0x0062d5a8-0x0062d5d8`: `0x0062d5a8 -> const StdioFile::RTTI Complete Object Locator`, slot `0x0062d5ac -> 0x005824a0`, inherited/base slots, and concrete stream slots `0x005820d0`, `0x005821d0`, `0x00582200`, `0x00582210`, `0x004f5ad0`, `0x00582230`, `0x005822d0`, and `0x00582250`; vtable store/reset xrefs remain `0x0058207f`, `0x005820a6`, and `0x005824a9`.
- Boundary dwords still reject a wider contiguous single owner: `0x006188dc -> 0x0049bb60` is the preceding `Crasher` vtable tail, `0x00618910 -> const DATFileMgr::RTTI Complete Object Locator` starts the manager vtable neighborhood, `0x00618950` starts the UTF-16 DAT path/error string island, and `0x0062d5d8` starts the adjacent whitespace/string-utility data after `StdioFile`.
- `lookup_funcs` confirms target sizes for the concrete stream slots: DATFile open/close/tell/seek/size/read/string-line/raw-line targets are `0xbb`, `0x20`, `0x17`, `0x6c`, `0x14`, `0x52`, `0xb9`, and `0x6f` bytes; StdioFile open/close/tell/seek/size/read/string-line/raw-line targets are `0xf9`, `0x27`, `0x0c`, `0x1d`, `0x04`, `0x1a`, `0xa9`, and `0x71` bytes.

2026-06-12 A004 Batch 319 IDA MCP refresh used active session `b001_nexustk` for `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe` and reconfirmed the split:

- `entity_query` reports `??_7File@@6B@` at `0x006188e4`, `??_7DATFile@@6B@` at `0x00618924`, and `??_7StdioFile@@6B@` at `0x0062d5ac`, with `StringIter` beginning at `0x0062d5ec`.
- `trace_data_flow backward` confirms `File` vtable refs at `0x0049c16e`, `0x0049d294`, `0x0049d396`, `0x005820b9`, and `0x005824be`; `DATFile` constructor install at `0x0049c13f`; and `StdioFile` constructor/destructor/deleting-destructor refs at `0x0058207f`, `0x005820a6`, and `0x005824a9`.
- `trace_data_flow backward 0x0062d5d8` confirms the successor whitespace literal and pointer `0x0067027c`, proving the `StdioFile` vtable ends before the adjacent string-utility data.
- `make_signature_for_range` produced unique 48-byte signatures for `0x006188e0-0x00618910`, `0x00618920-0x00618950`, and `0x0062d5a8-0x0062d5d8`.

## Assignment Gate

`AUTOGEN_PARENT_UID` remains blank and `RECONSTRUCTABLE` is now `FALSE`. This page clears `85/85`, but it is a reviewed non-emitting mixed-owner aggregate, not a direct source owner. The abstract `File` vtable belongs to [UID:0003HZ][FileVtable](by-type/by-vtable/FileVtable.md) under [UID:00004V][File](by-class/File.md); the concrete `DATFile` stream vtable belongs to [UID:0003I0][DATFileVtable](by-type/by-vtable/DATFileVtable.md) under [UID:00003G][DATFile](by-class/DATFile.md); and the concrete `StdioFile` vtable belongs to [UID:0003I1][StdioFileVtable](by-type/by-vtable/StdioFileVtable.md) under [UID:0000E6][StdioFile](by-class/StdioFile.md). No single direct parent owns all three records. Keep this page as the shared slot-layout authority rather than routing it through `FileIO`, `File`, `DATFile`, or `StdioFile`.

## UID0002UV Source-Quality Callback

- The mixed index remains `RECONSTRUCTABLE:FALSE`, ownerless, emitterless, and formally blank. Its role is ABI comparison, not source emission.
- The exact common operation order is destructor, inherited LObject runtime/no-op slots, then `Open`, `Close`, `GetPosition`, `Seek`, `GetSize`, `Read`, ANSI `ReadLine`, and `ReadLineChars`.
- The common `Read` contract returns `size_t` and takes signed `int count`. DATFile's explicit negative-count branch is direct evidence; StdioFile must use the same parameter type even though `fread` converts it to `size_t`.
- File's source-local table is compiler-generated from a four-byte data-member-free abstract class. DATFile and StdioFile provide concrete tables for 20-byte and 12-byte objects respectively.
- All three 48-byte signatures remain unique, table order remains exact, and no common handwritten vtable array is introduced.
- The former `Tell` and unsigned-count vocabulary remains historical; current source-facing naming is `GetPosition` with signed-count `Read`.
- Score is `90/94`; source-local child ownership and all unrelated vtable evidence remain intact.

## Split Review

Batch 319 supersedes the earlier Batch149 no-split decision. This page remains useful as the shared interface-contract page for one virtual ABI shape implemented by three classes, but it is not a reconstructable source owner. Source-local by-vtable children now carry exact ownership:

- [UID:0003HZ][FileVtable](by-type/by-vtable/FileVtable.md) covers the abstract `File` record and routes to [UID:00004V][File](by-class/File.md).
- [UID:0003I0][DATFileVtable](by-type/by-vtable/DATFileVtable.md) covers the exact `DATFile` stream-interface vtable and routes to [UID:00003G][DATFile](by-class/DATFile.md).
- [UID:0003I1][StdioFileVtable](by-type/by-vtable/StdioFileVtable.md) covers the exact `StdioFile` vtable and routes to [UID:0000E6][StdioFile](by-class/StdioFile.md), while [UID:00026L][0x0062d5a8-0x0062d5f8.StdioFileStringIterReadOnlyData](by-memory/0x0062d5a8-0x0062d5f8.StdioFileStringIterReadOnlyData.md) remains a non-emitting mixed memory index for the adjacent whitespace/sentinel/StringIter data.

Final supervisor status for this page is `reviewed-85-non-emitting-split-index-parent-blank`.

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
- [UID:0003HZ][FileVtable](by-type/by-vtable/FileVtable.md)
- [UID:0003I0][DATFileVtable](by-type/by-vtable/DATFileVtable.md)
- [UID:0003I1][StdioFileVtable](by-type/by-vtable/StdioFileVtable.md)
- [UID:0001UG][FileStreamLayouts](by-type/by-struct/FileStreamLayouts.md)
- [UID:0002UV][0x006188e0-0x00618910.FileVtableData](by-memory/0x006188e0-0x00618910.FileVtableData.md)
- [UID:0003B7][0x00618920-0x00618950.DATFileVtableData](by-memory/0x00618920-0x00618950.DATFileVtableData.md)
- [UID:0002UT][0x00618918-0x00618950.DATFileContainerAndDATFileVtableData](by-memory/0x00618918-0x00618950.DATFileContainerAndDATFileVtableData.md)
- [UID:00026L][0x0062d5a8-0x0062d5f8.StdioFileStringIterReadOnlyData](by-memory/0x0062d5a8-0x0062d5f8.StdioFileStringIterReadOnlyData.md)
- [UID:00012I][0x0049d390-0x0049d3cd.FileBaseDestructor](by-memory/0x0049d390-0x0049d3cd.FileBaseDestructor.md)
- [UID:0001IR][0x00582070-0x005824f6.StdioFile](by-memory/0x00582070-0x005824f6.StdioFile.md)
- [UID:00012D][0x0049c130-0x0049d2cc.DATFile](by-memory/0x0049c130-0x0049d2cc.DATFile.md)

## Changes

- 2026-06-12 A004 Batch 319:
  - Before: the page was `86/91`, `RECONSTRUCTABLE:TRUE`, and parent-blank as a mixed File/DATFile/StdioFile stream-vtable aggregate.
  - Changed to: `89/93`, `RECONSTRUCTABLE:FALSE`, and a non-emitting split index with source-local children [UID:0003HZ][FileVtable](by-type/by-vtable/FileVtable.md), [UID:0003I0][DATFileVtable](by-type/by-vtable/DATFileVtable.md), and [UID:0003I1][StdioFileVtable](by-type/by-vtable/StdioFileVtable.md).
  - Summary/evidence: live IDA MCP reconfirmed decorated table names, slot target sizes, vptr store/restore refs, unique table signatures, and the `0x0062d5d8` StdioFile successor boundary; each child now routes to its direct class parent after the strict child/direct-parent gate clears.
- 2026-06-11:
  - Before: the page was `78/88`, had the shared slot table and older vtable xrefs, but did not explicitly document the strict mixed-owner no-assignment decision or the current dword/function-size evidence.
  - Changed to: raised to `86/91`, added exact backing memory children, current IDA MCP dword/value-name/xref/function-size evidence, assignment-gate rationale, and Batch149 split review leaving `AUTOGEN_PARENT_UID` blank.
  - Summary/evidence: live IDA MCP reconfirms the abstract `File` purecall block, concrete `DATFile` and `StdioFile` slot targets, vtable-store xrefs, neighboring boundary dwords, and target function sizes. The page remains unassigned because it intentionally spans `File`, `DATFile`, and `StdioFile` direct owners, while exact address-level split pages already exist in by-memory.
- 2026-06-11 A001 Batch 208 exact DATFile split sync:
  - Scores remain `86/91`.
  - Replaced the exact backing-data pointer for the `DATFile` stream table with [UID:0003B7][0x00618920-0x00618950.DATFileVtableData](by-memory/0x00618920-0x00618950.DATFileVtableData.md), leaving [UID:0002UT][0x00618918-0x00618950.DATFileContainerAndDATFileVtableData](by-memory/0x00618918-0x00618950.DATFileContainerAndDATFileVtableData.md) as a non-emitting mixed inventory.
  - Summary/evidence: Batch 208 split separated the adjacent `DATFileContainer` one-slot record from the `DATFile` stream-interface vtable at `0x00618920`.
- 2026-05-31:
  - What existed before: metadata was `0/0` with `RECONSTRUCTABLE` blank, despite the vtable mapping already being documented.
  - Changed to: scored `78/88`, marked reconstructable, and added current IDA MCP vtable xref/method-boundary evidence.
  - Summary/evidence: IDA MCP verifies the vtable install/restore sites and the concrete virtual method starts for File, DATFile, and StdioFile. No C++ reconstruction code was added because final declarations and source split are not yet at the 95+ gate.
