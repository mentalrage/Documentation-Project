*** UID:0000T0 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
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
- Current generated file: `source-3/simroot_v2/recovered/HasDATEntry_0049C700.cpp`
- Confidence: strong

## Function Role

`HasDATEntry_49C700` is the public DAT-entry existence probe used by render, image, palette, audio, and file-callback code. It checks whether [UID:0000QQ][g_pDATFileMgr](by-global/g_pDATFileMgr.md) can resolve a named entry through the internal `_DATFileMgr` lookup API.

## Evidence Notes

- Current `simroot_v2` emits this as a standalone recovered global helper from Wave2/Wave3 recovery data.
- IDA MCP `lookup_funcs` on 2026-05-25 confirms `0x0049c700` as a real function of size `0x1d`, ending half-open at `0x0049c71d`.
- IDA MCP `callees` confirms the only callee is `_DATFileMgr::FindEntryByName` at `0x0049cad0`.
- IDA MCP `callers` confirms 17 direct callers spread across resource/image/audio consumers, supporting manager-module ownership rather than caller ownership.

## Source Layout Decision

Declare this helper beside the DAT manager API in `archive/DATFileMgr.cpp`. It is not private to a resource-loader caller even though many loaders depend on it.

The generated standalone file should be folded into the manager module during source-layout migration.

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
