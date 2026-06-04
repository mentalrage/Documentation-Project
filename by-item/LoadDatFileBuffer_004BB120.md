*** UID:0000UW | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000IN | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# LoadDatFileBuffer 0x004BB120

## Status

- Confidence: strong
- Entity kind: global helper
- Canonical global page: [UID:0000T4][LoadDatFileBuffer_4BB120](by-global/LoadDatFileBuffer_4BB120.md)
- Likely source module: [UID:0000IN][DATFile](by-file/DATFile.md)
- Autogen parent: [UID:0000IN][DATFile](by-file/DATFile.md)
- Exact range: [UID:00016G][0x004bb120-0x004bb1d2.LoadDatFileBuffer](by-memory/0x004bb120-0x004bb1d2.LoadDatFileBuffer.md)

## Behavior

`LoadDatFileBuffer_4BB120` loads a DAT-backed path into a newly allocated memory buffer. It can reserve a zero-filled prefix before the file payload, which lets callers place small headers or alignment padding before the resource bytes.

Observed flow:

1. Constructs a local `DATFile`.
2. Opens the supplied DAT path.
3. Reads the payload size from `DATFile::GetSize`.
4. Allocates `payloadSize + prefixSize` bytes.
5. Stores total size through `outSize` when supplied.
6. Zero-fills the prefix area when `prefixSize > 0`.
7. Reads the DAT payload after the prefix.
8. Closes and destroys the local `DATFile`.

## Caller Families

IDA MCP recheck on 2026-06-04 reports ten direct call sites in UI and pane/resource setup code, including call sites at `0x0048dc91`, `0x004999a1`, `0x005032a4`, `0x00565693`, `0x0056ca87`, `0x0056fee5`, `0x005b843f`, `0x005b8482`, `0x005babdd`, and `0x005bdac6`.

IDA MCP decompile confirms the local `DATFile` lifecycle: construct, open path, get payload size, allocate `payloadSize + prefixSize`, optionally write `outSize`, zero-fill the prefix when positive, read the payload at `buffer + prefixSize`, close, destroy, and return the buffer.

## Live IDA Evidence

Checked on 2026-06-04:

- `lookup_funcs` confirms IDA `sub_4BB120` at `0x004bb120`, size `0xb2`; `0x004bb1d2` is not a function, and the next function is `sub_4BB1E0` at `0x004bb1e0`.
- IDA bytes between `0x004bb1d2` and `0x004bb1e0` are fourteen `0xcc` padding bytes, supporting the half-open range documented by the memory page.
- The live decompile is `char *__stdcall sub_4BB120(wchar_t *a1, int Size, _DWORD *a3)`, with calls to allocator setup `sub_516030`, `DATFile` constructor `sub_49C130`, `Open` `sub_49C180`, `GetSize` `sub_49C2F0`, allocator `sub_516050`, `_memset`, `Read` `sub_49C310`, `Close` `sub_49C240`, and destructor `sub_49C160`.
- The body stores `payloadSize + prefixSize` through `outSize` only when the third argument is non-null, zero-fills only when `prefixSize > 0`, and reads the DAT payload at `buffer + prefixSize`.
- Caller contexts show broad consumer use: `CollectionBarControlPane`, `NewGroupPane`, `SelfLookPane2`, `OldUserStatusPane`, and several resource/UI helpers call this loader rather than owning its archive behavior.
- The reconstruction C++ block remains blank because the original source-facing helper name, allocator wrapper semantics, and exact signature types are still below the `95/95` reconstruction threshold.

## Ownership Decision

This helper should migrate with [UID:0000IN][DATFile](by-file/DATFile.md) before broader UI/resource modules are reorganized. The callers consume loaded buffers, but the helper's behavior is archive access plus memory allocation.

## Cross-References

- [UID:0000IM][DATArchive](by-file/DATArchive.md)
- [UID:0000T4][LoadDatFileBuffer_4BB120](by-global/LoadDatFileBuffer_4BB120.md)
- [UID:00016G][0x004bb120-0x004bb1d2.LoadDatFileBuffer](by-memory/0x004bb120-0x004bb1d2.LoadDatFileBuffer.md)
- [UID:0001QC][client_dat_specifications](by-meta/client_dat_specifications.md)
- [UID:00003G][DATFile](by-class/DATFile.md)

## Changes

- 2026-06-04: Raised grading from `70/85` to `84/90` and attached `AUTOGEN_PARENT_UID:0000IN`.
  - Before: the page had the correct high-level lifecycle but lacked refreshed live evidence for function boundaries, padding, exact call sites, caller contexts, and parent attachment.
  - After: live IDA MCP evidence now verifies the half-open range, DATFile lifecycle, allocation and prefix zero-fill behavior, ten direct callers, and archive-module ownership.
  - Evidence: `lookup_funcs`, live decompile, and IDA Python xref/disassembly inspection confirm the documented body. Reconstruction C++ remains blank because allocator naming/signature details are not proven to `95/95`.
- 2026-05-31: Grading and reconstruction status changed from unevaluated/blank to `70/85` and `RECONSTRUCTABLE:TRUE`.
  - Before: the page body documented the DAT buffer loader, but the validator metadata still showed `0/0` and no reconstruction status.
  - After: the metadata now tracks the helper as rebuild-relevant code. Parent UID and C++ remain blank because canonical attachment should be coordinated with the `DATFile` file/global/memory pages.
  - Evidence: IDA MCP confirms the exact `0x004bb120-0x004bb1d2` range, ten callers, DATFile constructor/open/get-size/read/close/destructor callees, allocation helpers, `_memset`, and a decompiled lifecycle matching the documented behavior.
