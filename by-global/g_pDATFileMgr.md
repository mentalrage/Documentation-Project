*** UID:0000QQ | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:82 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# g_pDATFileMgr

## Status

- Address range: [UID:0001P6][0x0067ab40-0x0067ab44.g_pDATFileMgr](by-memory/0x0067ab40-0x0067ab44.g_pDATFileMgr.md)
- Symbol kind: global singleton pointer
- Likely type: `DATFileMgr*`
- Likely owner file: [UID:0000IO][DATFileMgr](by-file/DATFileMgr.md)
- Current generated aliases: `dword_67AB40`, `g_pDATFileMgr`
- Confidence: strong for address, type role, and primary owner; medium-high for complete xref coverage.

## Purpose

`g_pDATFileMgr` stores the active DAT archive manager wrapper. The public wrapper points at an internal `_DATFileMgr` object, and archive API helpers use the wrapper to resolve resource names into mapped DAT archive entries.

## Evidence Notes

- Wave3 and existing docs identify `0x0067ab40` as the DAT manager singleton.
- Current `simroot_v2/recovered/HasDATEntry_0049C700.cpp` emits this storage as raw `dword_67AB40`; manager docs use the clearer `g_pDATFileMgr` name.
- IDA MCP `xrefs_to 0x0067ab40` reports constructor writes, destructor clear, `DATFile::Open`, `HasDATEntry_49C700`, application startup, [UID:0000UF][DestroyDATFileMgr_467380](by-item/DestroyDATFileMgr_467380.md), and shutdown users. The 2026-05-30 helper recheck confirms [UID:0000YV][0x00467380-0x00467391.DestroyDATFileMgr](by-memory/0x00467380-0x00467391.DestroyDATFileMgr.md) reads this pointer and deletes the active manager through vtable slot 0 with delete flag `1`.
- `HasDATEntry_49C700` reads `*(g_pDATFileMgr + 4)` and forwards to `_DATFileMgr::FindEntryByName`, confirming that the global points at the public wrapper, not directly at the internal manager object.

## Ownership Decision

Declare this in `archive/DATFileMgr.cpp`/`.h` with the public manager wrapper. Generated standalone helper files should reference it rather than redeclare a separate raw `dword_67AB40`.

## Cross-References

- [UID:0001P6][0x0067ab40-0x0067ab44.g_pDATFileMgr](by-memory/0x0067ab40-0x0067ab44.g_pDATFileMgr.md)
- [UID:0000IO][DATFileMgr](by-file/DATFileMgr.md)
- [UID:00003I][DATFileMgr](by-class/DATFileMgr.md)
- [UID:000004][_DATFileMgr](by-class/_DATFileMgr.md)
- [UID:0000T0][HasDATEntry_49C700](by-global/HasDATEntry_49C700.md)
- [UID:0000UF][DestroyDATFileMgr_467380](by-item/DestroyDATFileMgr_467380.md)
- [UID:0000IM][DATArchive](by-file/DATArchive.md)
- [UID:0001QC][client_dat_specifications](by-meta/client_dat_specifications.md)

## Changes

- 2026-05-30: Raised completion/confidence from `0/0` to `82/88`. Previously the page described the global but had no score; it now records the 2026-05-30 destroy-helper recheck and preserves the source-owner/xref-completeness caveat.
