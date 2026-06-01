*** UID:0000T4 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
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
- Current generated file: `source-3/simroot_v2/recovered/LoadDatFileBuffer_004BB120.cpp`
- Confidence: strong

## Function Role

`LoadDatFileBuffer_4BB120` is a shared archive convenience loader. It opens one DAT-backed file by name, allocates a plain buffer large enough for an optional caller-requested prefix plus the file payload, zero-fills that prefix when requested, reads the DAT payload after the prefix, and returns the allocated buffer.

## Evidence Notes

- Current `simroot_v2` emits this as a standalone recovered global helper because it was restored from Wave2 missing-reference work.
- IDA MCP `lookup_funcs` on 2026-05-25 confirms `0x004bb120` as a real function of size `0xb2`, ending half-open at `0x004bb1d2`.
- IDA MCP `callees` confirms the helper calls the [UID:00003G][DATFile](by-class/DATFile.md) constructor, `Open`, `GetSize`, `Read`, `Close`, destructor, allocation helpers, and `_memset`.
- IDA MCP `callers` confirms broad resource/UI consumers rather than one feature owner.

## Source Layout Decision

Declare this near `DATFile` in `archive/DATFile.cpp`. The standalone generated file is useful recovery provenance, but the original source likely kept this small helper beside the `DATFile` reader API.

Do not move it into render, map, status-pane, or dialog files just because those callers consume the returned buffers.

## Cross-References

- [UID:00016G][0x004bb120-0x004bb1d2.LoadDatFileBuffer](by-memory/0x004bb120-0x004bb1d2.LoadDatFileBuffer.md)
- [UID:0000UW][LoadDatFileBuffer_004BB120](by-item/LoadDatFileBuffer_004BB120.md)
- [UID:0000IN][DATFile](by-file/DATFile.md)
- [UID:0000IM][DATArchive](by-file/DATArchive.md)
- [UID:0001QC][client_dat_specifications](by-meta/client_dat_specifications.md)

## Changes

- 2026-05-30: Grading changed from `0/0` to `84/90`.
  - Before: page documented the DAT-backed buffer loader, signature hypothesis, owner, callees, and broad caller set but remained unevaluated.
  - After: score reflects near-complete behavior and source-placement documentation for this archive helper.
  - Evidence: IDA notes confirm function size, calls to `DATFile` constructor/open/get-size/read/close/destructor, allocation/zero-fill helpers, and broad resource/UI callers.
