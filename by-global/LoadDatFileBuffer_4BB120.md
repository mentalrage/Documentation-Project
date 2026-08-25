*** UID:0000T4 | DO NOT MODIFY OR REMOVE!!! ***
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

# LoadDatFileBuffer_4BB120

## Status

- Address range: [UID:00016G][0x004bb120-0x004bb1d2.LoadDatFileBuffer](by-memory/0x004bb120-0x004bb1d2.LoadDatFileBuffer.md)
- Symbol kind: global helper function
- Source-facing signature: `char *__stdcall LoadDatFileBuffer(const wchar_t *path, int prefixSize, int *outSize)`
- Likely owner file: [UID:0000IN][DATFile](by-file/DATFile.md)
- Direct owner/emitter: [UID:0000IN][DATFile](by-file/DATFile.md)
- Confidence: very strong for executable behavior, owner routing, MemoryMan allocation route, and alias disposition; exact original header/typedef spelling remains below final-audit proof.

## Function Role

`LoadDatFileBuffer_4BB120` is the documentation/search alias for source-facing helper `LoadDatFileBuffer`. It is a shared archive convenience loader. It opens one DAT-backed file by name, allocates a plain buffer large enough for an optional caller-requested prefix plus the file payload, zero-fills that prefix when requested, reads the DAT payload after the prefix, and returns the allocated buffer.

## Evidence Notes

- IDA MCP `lookup_funcs` on 2026-06-16 confirms `0x004bb120` as `sub_4BB120`, size `0xb2`, ending half-open at `0x004bb1d2`; `0x004bb1d2` is not a function and the next function starts at `0x004bb1e0`.
- IDA Python inspection confirms fourteen `0xcc` padding bytes after the range and before `sub_4BB1E0`.
- Live decompile confirms the helper calls the [UID:00003G][DATFile](by-class/DATFile.md) constructor, `Open`, `GetSize`, `Read`, `Close`, destructor, MemoryMan allocation helpers, and `_memset`.
- Direct call sites in the body are `0x004bb148`, `0x004bb152`, `0x004bb164`, `0x004bb16c`, `0x004bb17d`, `0x004bb195`, `0x004bb1a7`, `0x004bb1af`, and `0x004bb1b7`.
- `CodeRefsTo(0x004bb120)` confirms ten callers at `0x0048dc91`, `0x004999a1`, `0x005032a4`, `0x00565693`, `0x0056ca87`, `0x0056fee5`, `0x005b843f`, `0x005b8482`, `0x005babdd`, and `0x005bdac6`, with pane/resource constructor contexts rather than one feature owner.
- A read-only PE scan confirms those ten rel32 `call` sites and finds zero direct jumps, zero absolute-VA pointer hits, and zero RVA-form pointer hits to `0x004bb120`.
- 2026-06-28 B015 MCP recheck used active session `supervisor_20260628_resume`; `server_health` was `ok`, Hex-Rays and strings cache were ready, and `lookup_funcs 0x004bb120` again returned `sub_4BB120`, size `0xb2`.
- The path literal used by all observed callers is the UTF-16 string `L"9X11FONT.BIN"` starting at `0x0061682c`; IDA's interior `a11fontBin` label at `0x00616830` is evidence only and must not become source-facing code.
- [UID:0001BC][0x00516030-0x00516036.GetMemoryMan](by-memory/0x00516030-0x00516036.GetMemoryMan.md) and [UID:0001BD][0x00516050-0x005160ce.AllocateBufferMemory](by-memory/0x00516050-0x005160ce.AllocateBufferMemory.md) now resolve the old allocator-name blocker: source C++ should use `GetMemoryMan()->AllocateBufferMemory(totalSize)`.

## Source Layout Decision

Declare the source-facing helper near `DATFile` in `archive/DATFile.cpp`. The function is a compact lifecycle wrapper around `DATFile` and is attached to [UID:0000IN][DATFile](by-file/DATFile.md).

Do not move it into render, map, status-pane, or dialog files just because those callers consume the returned buffers.

This by-global page is not the canonical implementation page. It keeps the owner/emitter route and emits only a formal covered-by marker because [UID:00016G][0x004bb120-0x004bb1d2.LoadDatFileBuffer](by-memory/0x004bb120-0x004bb1d2.LoadDatFileBuffer.md) now emits the full accepted implementation. Duplicating the full body here would create duplicate generated source for the same helper.

## 2026-06-28 Alias Disposition

Accepted B015 implementation keeps [UID:0000T4] as an alias/index page:

- Metadata is raised to `88/92` because the allocator/source-name blocker is closed and source-ready implementation exists on [UID:00016G][0x004bb120-0x004bb1d2.LoadDatFileBuffer](by-memory/0x004bb120-0x004bb1d2.LoadDatFileBuffer.md).
- `CANONICAL_OWNER:0000IN`, `RECONSTRUCTABLE:TRUE`, and `EMITTER_UIDS:0000IN` remain unchanged so the alias disposition stays visible in `archive/DATFile.cpp`.
- Formal C++ intentionally contains only `// Emitted implementation for this LoadDatFileBuffer alias is covered by [UID:00016G][0x004bb120-0x004bb1d2.LoadDatFileBuffer](by-memory/0x004bb120-0x004bb1d2.LoadDatFileBuffer.md) LoadDatFileBuffer.`
- The source-facing function name is `LoadDatFileBuffer`; `_4BB120` remains only a disambiguating documentation suffix.
- Rejected alternatives are duplicate full C++ here, clearing `EMITTER_UIDS`, moving the helper to UI/resource callers, hard-coding `9X11FONT.BIN` in the loader, or using raw IDA names in source.

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
  - Evidence: `lookup_funcs`, live decompile, and IDA Python xref/disassembly inspection confirm the behavior. Reconstruction C++ remained blank at that time because the helper's exact source-facing signature and allocator wrapper names were not source-grade yet.
- 2026-05-30: Grading changed from `0/0` to `84/90`.
  - Before: page documented the DAT-backed buffer loader, signature hypothesis, owner, callees, and broad caller set but remained unevaluated.
  - After: score reflects near-complete behavior and source-placement documentation for this archive helper.
  - Evidence: IDA notes confirm function size, calls to `DATFile` constructor/open/get-size/read/close/destructor, allocation/zero-fill helpers, and broad resource/UI callers.
- 2026-06-16: Raised from `84/90` to `86/91`.
  - Before: the global page lacked current direct-call/pointer scan evidence and did not spell out the allocator/signature blocker.
  - After: the page recorded current IDA/PE reachability, DATFile owner routing, and why final C++ remained blank before the later B015 callback.
  - Evidence: IDA MCP `server_health`, `lookup_funcs`, `analyze_function`, `decompile`, `xrefs_to`, plus a read-only section-mapped PE scan.
- 2026-06-28 B015 implementation callback: raised from `86/91` to `88/92`; owner/emitter metadata remains [UID:0000IN][DATFile](by-file/DATFile.md), `RECONSTRUCTABLE:TRUE`, and `EMITTER_UIDS:0000IN`; formal C++ now emits the covered-by marker for [UID:00016G][0x004bb120-0x004bb1d2.LoadDatFileBuffer](by-memory/0x004bb120-0x004bb1d2.LoadDatFileBuffer.md).
  - Before: the page was a blank emitter alias and produced an `Empty Emitter Marker` in generated `archive/DATFile.cpp`.
  - After: the page records that `_4BB120` is a documentation alias for source-facing `LoadDatFileBuffer`, with the full implementation emitted by [UID:00016G][0x004bb120-0x004bb1d2.LoadDatFileBuffer](by-memory/0x004bb120-0x004bb1d2.LoadDatFileBuffer.md). The allocator route is resolved through `GetMemoryMan()->AllocateBufferMemory`, while UI/resource ownership, duplicate full-body emission, and raw IDA names remain rejected.
  - Evidence: accepted B015 report `tools/leaser/Agents/Agent-B015/research/00016G-LoadDatFileBuffer-empty-emitter-source-quality.md` and live MCP session `supervisor_20260628_resume`.
