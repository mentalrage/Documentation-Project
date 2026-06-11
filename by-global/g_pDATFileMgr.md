*** UID:0000QQ | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000IO | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
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
- Observed aliases: `dword_67AB40`, `g_pDATFileMgr`
- Confidence: strong for address, type role, singleton lifecycle, public-wrapper owner, and direct DATFileMgr parent routing.

## Purpose

`g_pDATFileMgr` stores the active DAT archive manager wrapper. The public wrapper points at an internal `_DATFileMgr` object at wrapper offset `+0x04`, and archive API helpers use the wrapper to resolve resource names into mapped DAT archive entries.

## Evidence Notes

- Existing docs identify `0x0067ab40` as the DAT manager singleton.
- Helper docs use both raw `dword_67AB40` and the clearer `g_pDATFileMgr` name for this storage.
- IDA MCP `xrefs_to 0x0067ab40` reports constructor writes, destructor clear, `DATFile::Open`, `HasDATEntry_49C700`, application startup, [UID:0000UF][DestroyDATFileMgr_467380](by-item/DestroyDATFileMgr_467380.md), and shutdown users. The 2026-05-30 helper recheck confirms [UID:0000YV][0x00467380-0x00467391.DestroyDATFileMgr](by-memory/0x00467380-0x00467391.DestroyDATFileMgr.md) reads this pointer and deletes the active manager through vtable slot 0 with delete flag `1`.
- `HasDATEntry_49C700` reads `*(g_pDATFileMgr + 4)` and forwards to `_DATFileMgr::FindEntryByName`, confirming that the global points at the public wrapper, not directly at the internal manager object.
- The exact storage page [UID:0001P6][0x0067ab40-0x0067ab44.g_pDATFileMgr](by-memory/0x0067ab40-0x0067ab44.g_pDATFileMgr.md) is scored `86/90` and records the initialized `0xffffffff` dword, `24` total xrefs, five writes, constructor publish/null fallback, constructor-adjacent cleanup clear, clear helper, scalar-deleting destructor clear, application startup/shutdown readers, `DATFile::Open`, `HasDATEntry`, `DestroyDATFileMgr`, and `WinMain`.
- [UID:00003I][DATFileMgr](by-class/DATFileMgr.md) is scored `86/86`, [UID:000004][_DATFileMgr](by-class/_DATFileMgr.md) is scored `87/85`, and [UID:0000IO][DATFileMgr](by-file/DATFileMgr.md) is scored `89/85`. Those pages document the public wrapper, private implementation, container/resolver helpers, vtable data, and `archive/DATFileMgr.cpp` ownership, so this global and direct file parent both clear the strict `85/85` assignment gate.

## Ownership Decision

Declare this in `archive/DATFileMgr.cpp`/`.h` with the public manager wrapper. Standalone helper bodies should reference it rather than redeclare a separate raw `dword_67AB40`.

## Score Rationale

| Field | Value | Rationale |
| --- | ---: | --- |
| Completion | 86 | The page now summarizes exact storage, lifecycle writes/clears, read clusters, public-wrapper versus internal-manager distinction, helper consumers, shutdown cleanup, and score-qualified parent evidence. |
| Confidence | 88 | The address, lifecycle, and owner are backed by the exact memory storage page, DATFileMgr class/file pages, and the HasDATEntry body. Confidence remains below final levels because the final declaration spelling and surrounding source shape are still not at the reconstruction-code gate. |
| Parent | [UID:0000IO][DATFileMgr](by-file/DATFileMgr.md) | Child `86/88` and direct parent `89/85` clear the strict `85/85` child/parent gate. |

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
- 2026-06-05: Marked reconstructable under [UID:0000IO][DATFileMgr](by-file/DATFileMgr.md). Evidence: live IDA MCP reports 24 xrefs to `0x0067ab40`; decompilation confirms `0x0049bd30` writes the singleton, `0x0049c700` reads the public wrapper before forwarding to `_DATFileMgr::FindEntryByName`, and `0x00467380` deletes the active manager through its vtable.
- 2026-06-10 A001 gate repair/evidence consolidation:
  - Changed completion from `82` to `86` while retaining confidence `88`, `RECONSTRUCTABLE:TRUE`, and parent [UID:0000IO][DATFileMgr](by-file/DATFileMgr.md).
  - Summary/evidence: consolidated the exact storage page's `86/90` lifecycle/xref evidence, the public wrapper class `86/86`, the internal manager class `87/85`, and the direct source file parent `89/85`. The child and direct parent now clear the strict `85/85` gate; final C++ remains blank because declaration spelling and source-shape details are still below the final-code threshold.
