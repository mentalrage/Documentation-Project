*** UID:0000T0 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:91 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:00012E | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:FALSE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# HasDATEntry_49C700

## Status

- Address range: [UID:00012E][0x0049c700-0x0049c71d.HasDATEntry](by-memory/0x0049c700-0x0049c71d.HasDATEntry.md)
- Symbol kind: global helper function
- Signature hypothesis: `bool __cdecl HasDATEntry_49C700(const wchar_t* entryName)`
- Likely owner file: [UID:0000IO][DATFileMgr](by-file/DATFileMgr.md)
- Direct source-bearing page: [UID:00012E][0x0049c700-0x0049c71d.HasDATEntry](by-memory/0x0049c700-0x0049c71d.HasDATEntry.md)
- Emission disposition: non-emitting duplicate/global symbol index for [UID:00012E][0x0049c700-0x0049c71d.HasDATEntry](by-memory/0x0049c700-0x0049c71d.HasDATEntry.md).
- Confidence: very strong for executable behavior and owner routing; final source spelling/signature remains provisional.

## Function Role

`HasDATEntry_49C700` is the public DAT-entry existence probe used by render, image, palette, audio, and file-callback code. It checks whether [UID:0000QQ][g_pDATFileMgr](by-global/g_pDATFileMgr.md) can resolve a named entry through the internal `_DATFileMgr` lookup API.

## Evidence Notes

- IDA MCP `lookup_funcs` on 2026-06-16 confirms `0x0049c700` as `sub_49C700`, size `0x1d`, ending half-open at `0x0049c71d`.
- `0x0049c71d` is not a function, the next function begins at `0x0049c720`, and the gap is three `0xcc` alignment bytes.
- IDA MCP `disasm` shows the helper reads `dword_67AB40`, loads the inner manager pointer from `+0x04`, calls `sub_49CAD0` with a null output-location pointer, and returns `setnz al`.
- IDA MCP `decompile` renders the body as `sub_49CAD0(*(_DWORD **)(dword_67AB40 + 4), String, 0) != 0`.
- IDA MCP `xrefs_to` confirms 17 direct callers spread across resource/image/audio consumers, supporting manager-module ownership rather than caller ownership.
- A read-only PE scan confirms the 17 rel32 `call` sites, zero direct jumps, and zero absolute-VA/RVA pointer encodings to `0x0049c700`.

## Source Layout Decision

Declare this helper beside the DAT manager API in `archive/DATFileMgr.cpp`. It is not private to a resource-loader caller even though many loaders depend on it.

The final emitted C++ remains blank on this duplicate global symbol page. [UID:00012E][0x0049c700-0x0049c71d.HasDATEntry](by-memory/0x0049c700-0x0049c71d.HasDATEntry.md) is the only source-bearing `HasDATEntry` emitter and already contains the exact formal body. This page preserves the global symbol/caller evidence and must not duplicate that body.

## 2026-07-01 B008 Duplicate Emitter Disposition

This page is reclassified to `RECONSTRUCTABLE:FALSE` with [UID:00012E][0x0049c700-0x0049c71d.HasDATEntry](by-memory/0x0049c700-0x0049c71d.HasDATEntry.md) as canonical owner and a blank emitter list. The 17-caller evidence remains valuable as a global symbol index, but separate emission from this page would create a duplicate `HasDATEntry` body in `DATFileMgr.cpp`.

## Cross-References

- [UID:00012E][0x0049c700-0x0049c71d.HasDATEntry](by-memory/0x0049c700-0x0049c71d.HasDATEntry.md)
- [UID:0000UT][HasDATEntry_0049C700](by-item/HasDATEntry_0049C700.md)
- [UID:0000IO][DATFileMgr](by-file/DATFileMgr.md)
- [UID:00003I][DATFileMgr](by-class/DATFileMgr.md)
- [UID:000004][_DATFileMgr](by-class/_DATFileMgr.md)
- [UID:0000QQ][g_pDATFileMgr](by-global/g_pDATFileMgr.md)
- [UID:0000IM][DATArchive](by-file/DATArchive.md)
- [UID:0001QC][client_dat_specifications](by-meta/client_dat_specifications.md)

## Changes

- 2026-07-01 B008 DATFileMgr empty-emitter family implementation:
  - Changed canonical owner from [UID:0000IO][DATFileMgr](by-file/DATFileMgr.md) to [UID:00012E][0x0049c700-0x0049c71d.HasDATEntry](by-memory/0x0049c700-0x0049c71d.HasDATEntry.md), set `RECONSTRUCTABLE:FALSE`, and blanked `EMITTER_UIDS`.
  - Preserved the blank formal C++ block by design because [UID:00012E][0x0049c700-0x0049c71d.HasDATEntry](by-memory/0x0049c700-0x0049c71d.HasDATEntry.md) is the single source-bearing `HasDATEntry` emitter.
  - Added duplicate-symbol/no-duplicate-body proof while retaining the 17-caller global evidence.
- 2026-05-30: Grading changed from `0/0` to `84/90`.
  - Before: page documented the public DAT-entry probe, exact range, signature hypothesis, owner, callee, and broad caller set but remained unevaluated.
  - After: score reflects near-complete behavior and source-placement documentation for this small manager helper.
  - Evidence: IDA notes confirm function size, sole `_DATFileMgr::FindEntryByName` callee, and 17 callers across resource/image/audio consumers.
- 2026-06-04: Set `RECONSTRUCTABLE:TRUE` and attached [UID:0000IO][DATFileMgr](by-file/DATFileMgr.md) as the autogen parent without changing the `84/90` score.
  - Before: the page had strong behavior and owner evidence but blank reconstructable/parent metadata and older evidence notes.
  - After: the page records current live IDA boundary, padding, disassembly, decompile, singleton access, sole lookup callee, 17 direct callers, and DAT manager parent attachment. C++ remains blank because source-facing signature and original name proof are still below the final-source quality bar.
  - Evidence: live IDA MCP `lookup_funcs`, `disasm`, `decompile`, `xrefs_to`, and `py_eval` on 2026-06-04.
- 2026-06-16: Raised from `84/90` to `86/91`.
  - Before: the global page lacked current PE reachability evidence and did not spell out the final signature/name blocker.
  - After: current IDA/PE evidence confirms the direct-call-only helper route, reinforces DATFileMgr ownership, and records why the C++ block remains blank.
  - Evidence: IDA MCP `server_health`, `lookup_funcs`, `analyze_function`, `decompile`, `xrefs_to`, plus section-mapped PE call/pointer scans.
