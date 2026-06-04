*** UID:0000T4 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000IN | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# LoadDatFileBuffer_4BB120

## Status

- Address range: [UID:00016G][0x004bb120-0x004bb1d2.LoadDatFileBuffer](by-memory/0x004bb120-0x004bb1d2.LoadDatFileBuffer.md)
- Symbol kind: global helper function
- Signature hypothesis: `char* __stdcall LoadDatFileBuffer_4BB120(const wchar_t* path, int prefixSize, std::uint32_t* outSize)`
- Likely owner file: [UID:0000IN][DATFile](by-file/DATFile.md)
- Autogen parent: [UID:0000IN][DATFile](by-file/DATFile.md)
- Confidence: strong

## Function Role

`LoadDatFileBuffer_4BB120` is a shared archive convenience loader. It opens one DAT-backed file by name, allocates a plain buffer large enough for an optional caller-requested prefix plus the file payload, zero-fills that prefix when requested, reads the DAT payload after the prefix, and returns the allocated buffer.

## Evidence Notes

- IDA MCP `lookup_funcs` on 2026-06-04 confirms `0x004bb120` as `sub_4BB120`, size `0xb2`, ending half-open at `0x004bb1d2`; `0x004bb1d2` is not a function and the next function starts at `0x004bb1e0`.
- IDA Python inspection confirms fourteen `0xcc` padding bytes after the range and before `sub_4BB1E0`.
- Live decompile confirms the helper calls the [UID:00003G][DATFile](by-class/DATFile.md) constructor, `Open`, `GetSize`, `Read`, `Close`, destructor, allocation helpers, and `_memset`.
- Direct call sites in the body are `0x004bb148`, `0x004bb152`, `0x004bb164`, `0x004bb16c`, `0x004bb17d`, `0x004bb195`, `0x004bb1a7`, `0x004bb1af`, and `0x004bb1b7`.
- `CodeRefsTo(0x004bb120)` confirms ten callers at `0x0048dc91`, `0x004999a1`, `0x005032a4`, `0x00565693`, `0x0056ca87`, `0x0056fee5`, `0x005b843f`, `0x005b8482`, `0x005babdd`, and `0x005bdac6`, with pane/resource constructor contexts rather than one feature owner.

## Source Layout Decision

Declare this near `DATFile` in `archive/DATFile.cpp`. The function is a compact lifecycle wrapper around `DATFile` and is now attached to [UID:0000IN][DATFile](by-file/DATFile.md).

Do not move it into render, map, status-pane, or dialog files just because those callers consume the returned buffers.

## Cross-References

- [UID:00016G][0x004bb120-0x004bb1d2.LoadDatFileBuffer](by-memory/0x004bb120-0x004bb1d2.LoadDatFileBuffer.md)
- [UID:0000UW][LoadDatFileBuffer_004BB120](by-item/LoadDatFileBuffer_004BB120.md)
- [UID:0000IN][DATFile](by-file/DATFile.md)
- [UID:0000IM][DATArchive](by-file/DATArchive.md)
- [UID:0001QC][client_dat_specifications](by-meta/client_dat_specifications.md)

## Changes

- 2026-06-04: Set `RECONSTRUCTABLE:TRUE` and attached `AUTOGEN_PARENT_UID:0000IN`; score remains `84/90`.
  - Before: the page already carried near-complete behavior coverage but still had blank reconstruction/parent metadata and stale provenance wording.
  - After: live IDA MCP evidence verifies the current boundary, padding, decompile flow, call sites, caller fan-in, and DATFile ownership; the global page is now aligned with the item and memory pages.
  - Evidence: `lookup_funcs`, live decompile, and IDA Python xref/disassembly inspection confirm the behavior. Reconstruction C++ remains blank because the helper's exact source-facing signature and allocator wrapper names are not yet proven to `95/95`.
- 2026-05-30: Grading changed from `0/0` to `84/90`.
  - Before: page documented the DAT-backed buffer loader, signature hypothesis, owner, callees, and broad caller set but remained unevaluated.
  - After: score reflects near-complete behavior and source-placement documentation for this archive helper.
  - Evidence: IDA notes confirm function size, calls to `DATFile` constructor/open/get-size/read/close/destructor, allocation/zero-fill helpers, and broad resource/UI callers.
