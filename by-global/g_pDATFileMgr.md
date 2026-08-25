*** UID:0000QQ | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000IO | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000IO | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
DATFileMgr *g_pDATFileMgr = 0;
[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# g_pDATFileMgr

## Status

- Address range: [UID:0001P6][0x0067ab40-0x0067ab44.g_pDATFileMgr](by-memory/0x0067ab40-0x0067ab44.g_pDATFileMgr.md)
- Symbol kind: global singleton pointer
- Likely type: `DATFileMgr*`
- Likely owner file: [UID:0000IO][DATFileMgr](by-file/DATFileMgr.md)
- Observed aliases: `dword_67AB40`, `g_pDATFileMgr`
- Confidence: very strong for address, type role, 24-xref lifecycle, RTTI-proven `Singleton<DATFileMgr>` source ownership, public-wrapper value, and direct DATFileMgr parent routing.

## Purpose

`g_pDATFileMgr` stores the active DAT archive manager wrapper. `DATFileMgr : public Singleton<DATFileMgr>` owns source publication and clear; the public wrapper points at an internal `_DATFileMgr` object at wrapper offset `+0x04`, and archive API helpers use the wrapper to resolve resource names into mapped DAT archive entries.

## Evidence Notes

- Existing docs identify `0x0067ab40` as the DAT manager singleton.
- Helper docs use both raw `dword_67AB40` and the clearer `g_pDATFileMgr` name for this storage.
- Evidence-time database `bf5519ae` `xrefs_to 0x0067ab40` reports exactly 24 xrefs: constructor publish/null fallback, ordinary/EH/scalar clear paths, `DATFile::Open`, `HasDATEntry_49C700`, application startup, [UID:0000UF][DestroyDATFileMgr_467380](by-item/DestroyDATFileMgr_467380.md), and shutdown users. The 2026-05-30 helper recheck confirms [UID:0000YV][0x00467380-0x00467391.DestroyDATFileMgr](by-memory/0x00467380-0x00467391.DestroyDATFileMgr.md) reads this pointer and deletes the active manager through vtable slot 0 with delete flag `1`.
- `HasDATEntry_49C700` reads `*(g_pDATFileMgr + 4)` and forwards to `_DATFileMgr::FindEntryByName`, confirming that the global points at the public wrapper, not directly at the internal manager object.
- Historical session `80de0a67` read bytes `00 00 00 00`, `u32le=0`, and `get_global_value=0x0` at `0x0067ab40`; source storage remains `DATFileMgr *g_pDATFileMgr = 0`. Older `ff ff ff ff` wording is stale/historical unless a separate original-image audit proves it.
- Exact storage page [UID:0001P6][0x0067ab40-0x0067ab44.g_pDATFileMgr](by-memory/0x0067ab40-0x0067ab44.g_pDATFileMgr.md) is `88/91` and preserves current-zero evidence, 24 xrefs, five writes, and all reader/cleanup clusters.
- [UID:00003I][DATFileMgr](by-class/DATFileMgr.md) is `91/94`, [UID:000004][_DATFileMgr](by-class/_DATFileMgr.md) is `90/92`, and [UID:0000IO][DATFileMgr](by-file/DATFileMgr.md) is `92/92` after UID000439 implementation.
- DATFileMgr RTTI hierarchy `0x00646470` contains exactly `DATFileMgr` and `Singleton<DATFileMgr>`; base descriptor `0x006464a8` has PMD `+0x04`. Constructor `this+4` adjustment, EH state-zero clear, and destructor clear order attribute source writes/clears to this base rather than manual public method statements.

## Ownership Decision

Declare this in `archive/DATFileMgr.cpp`/`.h` with the public manager wrapper. Standalone helper bodies should reference it rather than redeclare a separate raw `dword_67AB40`. Source publication/clear belongs to `Singleton<DATFileMgr>` lifetime; historical constructor/destructor manual-assignment descriptions are superseded.

The formal reconstruction block now emits the singleton definition from this global page. The exact storage child [UID:0001P6][0x0067ab40-0x0067ab44.g_pDATFileMgr](by-memory/0x0067ab40-0x0067ab44.g_pDATFileMgr.md) preserves address/xref proof only and must not duplicate the pointer definition.

## Score Rationale

| Field | Value | Rationale |
| --- | ---: | --- |
| Completion | 90 | Exact storage, 24-xref lifecycle, read clusters, public-wrapper value, helper consumers, shutdown cleanup, Singleton source ownership, support scores, and unchanged emitted definition are documented. |
| Confidence | 94 | Address, zero initializer, RTTI base, constructor/EH/destructor lifetime, exact storage page, class/file pages, and HasDATEntry body agree. Exact original global/template member header spelling remains inferred. |
| Parent | [UID:0000IO][DATFileMgr](by-file/DATFileMgr.md) | Child `90/94` and direct parent `92/92` clear the strict gate. |

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

- 2026-08-17 B007 UID0000PA provider-declaration sync:
  - Preserved the single source definition `DATFileMgr *g_pDATFileMgr = 0;` and its exact child/lifecycle route under [UID:0000IO][DATFileMgr](by-file/DATFileMgr.md).
  - The matching extern now lives in the complete guarded `DATFileMgr.h` declaration. WinMain's conditional early-exit deletion includes that provider and remains a consumer rather than a competing global definition or owner.

- 2026-07-12 B001 UID000439 accepted implementation callback:
  - Raised score from `88/91` to `90/94`; preserved owner/emitter UID0000IO and exact `DATFileMgr *g_pDATFileMgr = 0;` block.
  - Added exact Singleton RTTI/base PMD and constructor/EH/destructor lifetime ownership, evidence-time 24-xref proof, current support scores, and historicalized manual-global/manual-clear and session-byte wording.
- 2026-07-01 B008 DATFileMgr empty-emitter family implementation:
  - Raised score from `86/88` to `88/91`.
  - Added formal singleton definition C++ `DATFileMgr *g_pDATFileMgr = 0;` plus `[[CHILDREN]]`.
  - Preserved current zero-byte MCP proof and assigned duplicate exact storage proof to [UID:0001P6][0x0067ab40-0x0067ab44.g_pDATFileMgr](by-memory/0x0067ab40-0x0067ab44.g_pDATFileMgr.md).
- 2026-05-30: Raised completion/confidence from `0/0` to `82/88`. Previously the page described the global but had no score; it now records the 2026-05-30 destroy-helper recheck and preserves the source-owner/xref-completeness caveat.
- 2026-06-05: Marked reconstructable under [UID:0000IO][DATFileMgr](by-file/DATFileMgr.md). Evidence: live IDA MCP reports 24 xrefs to `0x0067ab40`; decompilation confirms `0x0049bd30` writes the singleton, `0x0049c700` reads the public wrapper before forwarding to `_DATFileMgr::FindEntryByName`, and `0x00467380` deletes the active manager through its vtable.
- 2026-06-10 A001 gate repair/evidence consolidation:
  - Changed completion from `82` to `86` while retaining confidence `88`, `RECONSTRUCTABLE:TRUE`, and parent [UID:0000IO][DATFileMgr](by-file/DATFileMgr.md).
  - Summary/evidence: consolidated the exact storage page's `86/90` lifecycle/xref evidence, the public wrapper class `86/86`, the internal manager class `87/85`, and the direct source file parent `89/85`. The child and direct parent now clear the strict `85/85` gate; final C++ remains blank because declaration spelling and source-shape details are still below the final-code threshold.
- 2026-06-26 B002 singleton-byte correction:
  - Replaced stale current-byte wording with live IDA MCP session `80de0a67` evidence: `00 00 00 00`, `u32le=0`, and `get_global_value=0x0`.
  - Source declaration direction is `DATFileMgr *g_pDATFileMgr = 0`; older `ff ff ff ff` evidence is retained only as stale/historical unless a separate original-file byte audit proves that source.
