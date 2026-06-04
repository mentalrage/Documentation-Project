*** UID:0000T0 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000IO | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# HasDATEntry_49C700

## Status

- Address range: [UID:00012E][0x0049c700-0x0049c71d.HasDATEntry](by-memory/0x0049c700-0x0049c71d.HasDATEntry.md)
- Symbol kind: global helper function
- Signature hypothesis: `bool __cdecl HasDATEntry_49C700(const wchar_t* entryName)`
- Likely owner file: [UID:0000IO][DATFileMgr](by-file/DATFileMgr.md)
- Autogen parent: [UID:0000IO][DATFileMgr](by-file/DATFileMgr.md)
- Confidence: strong

## Function Role

`HasDATEntry_49C700` is the public DAT-entry existence probe used by render, image, palette, audio, and file-callback code. It checks whether [UID:0000QQ][g_pDATFileMgr](by-global/g_pDATFileMgr.md) can resolve a named entry through the internal `_DATFileMgr` lookup API.

## Evidence Notes

- IDA MCP `lookup_funcs` on 2026-06-04 confirms `0x0049c700` as `sub_49C700`, size `0x1d`, ending half-open at `0x0049c71d`.
- `0x0049c71d` is not a function, the next function begins at `0x0049c720`, and the gap is three `0xcc` alignment bytes.
- IDA MCP `disasm` shows the helper reads `dword_67AB40`, loads the inner manager pointer from `+0x04`, calls `sub_49CAD0` with a null output-location pointer, and returns `setnz al`.
- IDA MCP `decompile` renders the body as `sub_49CAD0(*(_DWORD **)(dword_67AB40 + 4), String, 0) != 0`.
- IDA MCP `xrefs_to` confirms 17 direct callers spread across resource/image/audio consumers, supporting manager-module ownership rather than caller ownership.

## Source Layout Decision

Declare this helper beside the DAT manager API in `archive/DATFileMgr.cpp`. It is not private to a resource-loader caller even though many loaders depend on it.

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

- 2026-05-30: Grading changed from `0/0` to `84/90`.
  - Before: page documented the public DAT-entry probe, exact range, signature hypothesis, owner, callee, and broad caller set but remained unevaluated.
  - After: score reflects near-complete behavior and source-placement documentation for this small manager helper.
  - Evidence: IDA notes confirm function size, sole `_DATFileMgr::FindEntryByName` callee, and 17 callers across resource/image/audio consumers.
- 2026-06-04: Set `RECONSTRUCTABLE:TRUE` and attached [UID:0000IO][DATFileMgr](by-file/DATFileMgr.md) as the autogen parent without changing the `84/90` score.
  - Before: the page had strong behavior and owner evidence but blank reconstructable/parent metadata and older evidence notes.
  - After: the page records current live IDA boundary, padding, disassembly, decompile, singleton access, sole lookup callee, 17 direct callers, and DAT manager parent attachment. C++ remains blank because source-facing signature and original name proof are still below the `95/95` final-code gate.
  - Evidence: live IDA MCP `lookup_funcs`, `disasm`, `decompile`, `xrefs_to`, and `py_eval` on 2026-06-04.
