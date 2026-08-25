*** UID:0000UW | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000IN | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000IN | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
// Emitted implementation for this LoadDatFileBuffer alias is covered by [UID:00016G][0x004bb120-0x004bb1d2.LoadDatFileBuffer](by-memory/0x004bb120-0x004bb1d2.LoadDatFileBuffer.md) LoadDatFileBuffer.
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# LoadDatFileBuffer 0x004BB120

## Status

- Confidence: very strong for behavior, direct-call reachability, DATFile ownership, MemoryMan allocation route, and covered-by alias disposition; exact original header/typedef spelling remains below final-audit proof.
- Entity kind: global helper
- Canonical global page: [UID:0000T4][LoadDatFileBuffer_4BB120](by-global/LoadDatFileBuffer_4BB120.md)
- Likely source module: [UID:0000IN][DATFile](by-file/DATFile.md)
- Direct owner/emitter: [UID:0000IN][DATFile](by-file/DATFile.md)
- Exact range: [UID:00016G][0x004bb120-0x004bb1d2.LoadDatFileBuffer](by-memory/0x004bb120-0x004bb1d2.LoadDatFileBuffer.md)

## Behavior

`LoadDatFileBuffer_4BB120` is the documentation/search alias for source-facing helper `LoadDatFileBuffer`, whose full implementation is emitted by [UID:00016G][0x004bb120-0x004bb1d2.LoadDatFileBuffer](by-memory/0x004bb120-0x004bb1d2.LoadDatFileBuffer.md). It loads a DAT-backed path into a newly allocated memory buffer. It can reserve a zero-filled prefix before the file payload, which lets callers place small headers or alignment padding before the resource bytes.

Observed flow:

1. Constructs a local `DATFile`.
2. Opens the supplied DAT path.
3. Reads the payload size from `DATFile::GetSize`.
4. Allocates `payloadSize + prefixSize` bytes through `GetMemoryMan()->AllocateBufferMemory`.
5. Stores total size through `outSize` when supplied.
6. Zero-fills the prefix area when `prefixSize > 0`.
7. Reads the DAT payload after the prefix.
8. Closes and destroys the local `DATFile`.

## Caller Families

IDA MCP and PE recheck on 2026-06-16 reports ten direct call sites in UI and pane/resource setup code, including call sites at `0x0048dc91`, `0x004999a1`, `0x005032a4`, `0x00565693`, `0x0056ca87`, `0x0056fee5`, `0x005b843f`, `0x005b8482`, `0x005babdd`, and `0x005bdac6`.

IDA MCP decompile confirms the local `DATFile` lifecycle: construct, open path, get payload size, allocate `payloadSize + prefixSize`, optionally write `outSize`, zero-fill the prefix when positive, read the payload at `buffer + prefixSize`, close, destroy, and return the buffer.

## Live IDA Evidence

Checked on 2026-06-16 against IDA database `b001_maildialogs_0000ZO_20260616` for read-only `NexusTK.exe`:

- `lookup_funcs` confirms IDA `sub_4BB120` at `0x004bb120`, size `0xb2`; `0x004bb1d2` is not a function, and the next function is `sub_4BB1E0` at `0x004bb1e0`.
- IDA bytes between `0x004bb1d2` and `0x004bb1e0` are fourteen `0xcc` padding bytes, supporting the half-open range documented by the memory page.
- The live decompile is `char *__stdcall sub_4BB120(wchar_t *a1, int Size, _DWORD *a3)`, with calls to allocator setup `sub_516030`, `DATFile` constructor `sub_49C130`, `Open` `sub_49C180`, `GetSize` `sub_49C2F0`, allocator `sub_516050`, `_memset`, `Read` `sub_49C310`, `Close` `sub_49C240`, and destructor `sub_49C160`. Source-facing C++ resolves those raw allocator calls as `GetMemoryMan()->AllocateBufferMemory(totalSize)` through accepted MemoryMan docs.
- The body stores `payloadSize + prefixSize` through `outSize` only when the third argument is non-null, zero-fills only when `prefixSize > 0`, and reads the DAT payload at `buffer + prefixSize`.
- Caller contexts show broad consumer use: `CollectionBarControlPane`, `NewGroupPane`, `SelfLookPane2`, `OldUserStatusPane`, and several resource/UI helpers call this loader rather than owning its archive behavior.
- A section-mapped PE scan finds exactly the same ten `E8` rel32 call sites, zero direct jumps, zero absolute-VA pointer hits, and zero RVA-form pointer hits to `0x004bb120`.
- 2026-06-28 B015 MCP recheck used active session `supervisor_20260628_resume`; `server_health` returned `status: ok`, Hex-Rays and strings cache ready, and `lookup_funcs 0x004bb120` again returned `sub_4BB120`, size `0xb2`.
- The caller path literal is UTF-16 `L"9X11FONT.BIN"` starting at `0x0061682c`; IDA's interior `a11fontBin` label at `0x00616830` is a string-typing artifact and evidence only.
- `xrefs_to 0x004bb1d2` reports no xrefs and successor `0x004bb1e0` is a distinct function, so the helper is not a split/container repair case.

## Source-Quality Resolution

- Ownership/source placement is resolved to `DATFile`: the body is a compact stack `DATFile` constructor/open/get-size/read/close/destructor lifecycle wrapper, while UI/resource callers only consume the returned buffer.
- Reachability is resolved as ordinary direct-call reachability; IDA and PE scans agree on ten calls and find no callback/pointer route to the helper start.
- Final C++ is now source-ready on [UID:00016G][0x004bb120-0x004bb1d2.LoadDatFileBuffer](by-memory/0x004bb120-0x004bb1d2.LoadDatFileBuffer.md). The behavior-proven source-facing signature is `char *__stdcall LoadDatFileBuffer(const wchar_t *path, int prefixSize, int *outSize)`.
- This by-item page intentionally emits only a formal covered-by marker. Duplicating the full function body here would produce duplicate source for the same helper.
- [UID:0001BC][0x00516030-0x00516036.GetMemoryMan](by-memory/0x00516030-0x00516036.GetMemoryMan.md) and [UID:0001BD][0x00516050-0x005160ce.AllocateBufferMemory](by-memory/0x00516050-0x005160ce.AllocateBufferMemory.md) resolve the old allocator-name blocker.
- Do not emit a standalone `9X11FONT.BIN` constant here; the path literal is shared UI numeric-font resource evidence already covered by read-only data/resource docs.

## Ownership Decision

This helper should migrate with [UID:0000IN][DATFile](by-file/DATFile.md) before broader UI/resource modules are reorganized. The callers consume loaded buffers, but the helper's behavior is archive access plus memory allocation.

Rejected alternatives: leaving this page as a blank emitter, duplicating [UID:00016G][0x004bb120-0x004bb1d2.LoadDatFileBuffer](by-memory/0x004bb120-0x004bb1d2.LoadDatFileBuffer.md)'s full implementation, clearing the owner/emitter route, moving ownership to UI/resource callers, merging the successor function, hard-coding the `9X11FONT.BIN` path in this generic loader, or using raw IDA labels such as `sub_4BB120`, `sub_516030`, `sub_516050`, or `a11fontBin` in source.

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
  - Evidence: `lookup_funcs`, live decompile, and IDA Python xref/disassembly inspection confirm the documented body. Reconstruction C++ remains blank because allocator naming/signature details are not source-grade.
- 2026-05-31: Grading and reconstruction status changed from unevaluated/blank to `70/85` and `RECONSTRUCTABLE:TRUE`.
  - Before: the page body documented the DAT buffer loader, but the validator metadata still showed `0/0` and no reconstruction status.
  - After: the metadata now tracks the helper as rebuild-relevant code. Parent UID and C++ remain blank because canonical attachment should be coordinated with the `DATFile` file/global/memory pages.
  - Evidence: IDA MCP confirms the exact `0x004bb120-0x004bb1d2` range, ten callers, DATFile constructor/open/get-size/read/close/destructor callees, allocation helpers, `_memset`, and a decompiled lifecycle matching the documented behavior.
- 2026-06-16: Raised completion/confidence from `84/90` to `86/91`.
  - Before: the helper had strong lifecycle evidence but no current PE reachability scan or explicit final signature/name blocker investigation.
  - After: the page records direct-call-only reachability, refreshed current IDA evidence, owner/emitter rationale, and the precise remaining allocator/signature source-quality blocker.
  - Evidence: IDA MCP `server_health`, `lookup_funcs`, `analyze_function`, `decompile`, `xrefs_to`, and a read-only section-mapped PE scan.
- 2026-06-28 B015 implementation callback: raised from `86/91` to `88/92`; owner/emitter metadata remains [UID:0000IN][DATFile](by-file/DATFile.md), `RECONSTRUCTABLE:TRUE`, and `EMITTER_UIDS:0000IN`; formal C++ now emits the covered-by marker for [UID:00016G][0x004bb120-0x004bb1d2.LoadDatFileBuffer](by-memory/0x004bb120-0x004bb1d2.LoadDatFileBuffer.md).
  - Before: the item page remained a blank emitter alias and generated an `Empty Emitter Marker`.
  - After: the page records that source-facing `LoadDatFileBuffer` is implemented by [UID:00016G][0x004bb120-0x004bb1d2.LoadDatFileBuffer](by-memory/0x004bb120-0x004bb1d2.LoadDatFileBuffer.md), with this item page retained as an alias/index page. The allocator route is resolved through `GetMemoryMan()->AllocateBufferMemory`, and rejected alternatives/negative evidence are preserved.
  - Evidence: accepted B015 report `tools/leaser/Agents/Agent-B015/research/00016G-LoadDatFileBuffer-empty-emitter-source-quality.md` and live MCP session `supervisor_20260628_resume`.
