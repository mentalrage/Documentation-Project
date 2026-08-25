*** UID:0000V6 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:91 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0001IZ | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:FALSE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# PathExistsViaStat_00582460

## Status

- Disposition: non-emitting evidence/index mirror for canonical source-bearing [UID:0001IZ][0x00582460-0x00582495.PathExistsViaStat](by-memory/0x00582460-0x00582495.PathExistsViaStat.md).
- Confidence: very strong for exact range, bytes/hash, ABI, stack UDT, predicate, caller set, dispatch dependency, owner, source route, and duplicate disposition; strong inferred for original lexical/header spelling.
- Address range: [UID:0001IZ][0x00582460-0x00582495.PathExistsViaStat](by-memory/0x00582460-0x00582495.PathExistsViaStat.md)
- Canonical body owner: [UID:0001IZ][0x00582460-0x00582495.PathExistsViaStat](by-memory/0x00582460-0x00582495.PathExistsViaStat.md), emitted through [UID:0000MI][PathUtil](by-file/PathUtil.md) into `NexusTK/util/PathUtil.cpp`.
- Formal C++ is blank by design: this mirror must not duplicate the exact by-memory body.
- Whole-file synchronization: canonical UID0001IZ emits the position-10 include preamble, `PathExistsViaStat` definition, and complete two-helper `PathUtil.h`; sibling UID00022K emits only the position-20 `FileExists` definition. This mirror contributes no CPP/H fragment to either output.
- Historical generated source candidate: `PathExistsViaStat_00582460.cpp`; use only as search context, not as authority.

## Function Role

`PathExistsViaStat` is a shared wide-path existence probe. The exact binary function is 53 bytes at `[0x00582460,0x00582495)`, has one basic block and cdecl ABI, passes a stack-local 48-byte `struct _stat64i32` to the PlatformApi-owned `g_pfnWideStat`, and returns the exact binary predicate `result != -1`.

`g_pfnWideStat` is the `0x0069be18` `_wstat64i32` entry in the process-wide [UID:0000TQ][WideApiDispatchTable](by-global/WideApiDispatchTable.md), initialized by [UID:0000WD][0x0041a280-0x0041a4a8.WideApiDispatchInit](by-memory/0x0041a280-0x0041a4a8.WideApiDispatchInit.md) and source-emitted by [UID:0002AS][0x0069be14-0x0069bec4.WideApiDispatchPointerTable](by-memory/0x0069be14-0x0069bec4.WideApiDispatchPointerTable.md). Older generated output declared raw `dword_69BE18` locally; that is retained only as a rejected historical source shape.

## Exact Mirror Evidence

- Exact bytes: `55 8B EC 83 EC 34 A1 24 2F 67 00 33 C5 89 45 FC 8B 45 08 8D 4D CC 51 50 FF 15 18 BE 69 00 8B 4D FC 83 C4 08 83 F8 FF 0F 95 C0 33 CD E8 9E 52 04 00 8B E5 5D C3`.
- SHA256: `9283C746FB482BB7DED5096C9BA3E63F003646AACC801D31BA549C69D260CAA0`.
- ABI and stack: `bool __cdecl PathExistsViaStat(const wchar_t *path)`; 48-byte `_stat64i32` at `[ebp-34h]`, separate /GS cookie at `[ebp-4]`, plain caller cleanup, normalized bool in `al`.
- Exact predicate: `cmp eax,-1; setnz al`; source must use `g_pfnWideStat(path, &statBuffer) != -1`, not `== 0`.
- UDT layout: `_stat64i32` is size `0x30`, with `st_size` at `+0x14` and 64-bit time fields at `+0x18/+0x20/+0x28`; the live UDT exactly accounts for the local storage.
- Uniqueness: the 22-byte entry signature occurs once at `0x00582460`; raw little-endian VA bytes `60 24 58 00` have no matches.
- Boundaries: seven leading `0xcc` bytes after predecessor `sub_582410`; eleven trailing `0xcc` bytes before successor `sub_5824A0`; no function or xref at `0x00582495`.
- Dependency xrefs: `0x0069be18` has initializer/consumer refs at `0x0041a438`, `0x00582104`, `0x00582478`, `0x0059976d`, and `0x005999a8`; `_wstat64i32` at `0x005e25aa` already has the exact CRT prototype.
- Source route: definition in `NexusTK/util/PathUtil.cpp`, inferred cross-module declaration in `PathUtil.h`, PlatformApi declaration dependency for `g_pfnWideStat`, and no local dispatch storage.
- This page preserves the evidence for search/navigation but delegates all source emission to UID0001IZ.

## Caller Evidence

IDA caller checks on 2026-05-24 show this helper used from:

- startup-logo movie selection (`LOGO.PAK` / `LOGO.PAD`)
- `Application::Startup` when probing `NEXON.LGO`
- `MainMenuPane` resource loading for `LEVEL.BMP`
- `MapPane::LoadMapFromFile` for local `.cmp` map files
- the Miles AIL file-open callback before constructing a [UID:0000E6][StdioFile](by-class/StdioFile.md)

B001-022 rechecked the exact memory page on 2026-06-10 with live IDA MCP: the function is `0x00582460-0x00582495`, decompilation is a single `dword_69BE18(path, stackStatBuffer) != -1` boolean return, callers are `0x004f5765`, `0x004f5781`, `0x004f640d`, `0x004f6853`, `0x00504c7d`, and `0x0057b6be`, and callees are only the wide stat dispatch slot and the stack-cookie check.

2026-06-16 A001 rechecked the current IDA database and PE bytes. `lookup_funcs` still reports `sub_582460` at `0x00582460`, size `0x35`, with no function at `0x00582495`; `disasm` shows the 48-byte stack stat buffer, indirect call through `unk_69BE18`, `cmp eax, 0xffffffff`, and `setnz al`; `xrefs_to` still reports the same six direct call sites. A read-only PE scan found the same six direct `E8` references and no absolute VA/RVA pointer references to `0x00582460`.

2026-07-24 B001 revalidated the same facts through healthy live MCP session `supervisor_gate2b_0002OT_20260723` and resolved the source-facing dependency/type/route blockers. The exact call-site meanings are:

| Call site | Caller role | Meaning |
| --- | --- | --- |
| `0x004f5765` | startup-logo Bink selection | first `LOGO.PAK` / `LOGO.PAD` probe |
| `0x004f5781` | same startup-logo function | alternate logo asset probe |
| `0x004f640d` | `Application::Startup` | `NEXON.LGO` LogoPane/TerminalPane selection |
| `0x004f6853` | `MainMenuPane::MainMenuPane` | optional `LEVEL.BMP` load |
| `0x00504c7d` | `MapPane::LoadCompressedMapFile` | local `TK%06d.cmp` cache probe |
| `0x0057b6be` | `AILFileOpenCallback` | loose-file fallback after DAT lookup |

## Ownership Notes

Treat this as utility file/path support. It is adjacent to `StdioFile` in memory and API role, but its caller spread is broader than one class. It is distinct from [UID:0000T0][HasDATEntry_49C700](by-global/HasDATEntry_49C700.md), which probes the DAT archive manager.

B001-022 also assigns [UID:00022K][0x004b81f0-0x004b821e.FileExists](by-memory/0x004b81f0-0x004b821e.FileExists.md) to the same [UID:0000MI][PathUtil](by-file/PathUtil.md) root. That open-based helper is not object-stateful and matches this stat-based helper's source role.

The canonical emission owner is the exact by-memory page, not this by-item page. Keeping both reconstructable under the same by-file owner created two generated empty markers for one function. `CANONICAL_OWNER:0001IZ`, `RECONSTRUCTABLE:FALSE`, blank `EMITTER_UIDS`, and blank formal C++ preserve this item's evidence while enforcing one body.

Rejected owners remain explicit: StdioFile adjacency is insufficient because the helper reads no `this`/field/vtable/stream state; PlatformApi owns the slot but not the consumer; FileIO is a non-emitting umbrella; startup/application/menu/map/audio modules are consumers rather than owners.

## Autogen Status

- Reconstructable: false for this duplicate item page; the underlying source function is reconstructable and emitted by UID0001IZ.
- Canonical owner: UID0001IZ. Emitter list and formal C++ remain blank.
- Expected generated state: no UID0000V6 empty marker, exactly one UID0001IZ position-10 body and one UID00022K position-20 body in `auto-generated/NexusTK/util/PathUtil.cpp`, and a complete `PathUtil.h` emitted by UID0001IZ. The mirror remains absent from generated source.

## Score Rationale

- Completion `91`: the mirror records the exact range/bytes/hash, ABI, stack/UDT layout, predicate, six callers, dispatch owner/type/xrefs, signature uniqueness, padding, source/header/dependency route, sibling distinction, rejected owners, and one-body policy while intentionally containing no source body.
- Confidence `94`: direct binary and current source-routing evidence are very strong. The score stays below `95` because original lexical/header spelling and rebuilt compiler equivalence remain unproved, not because any emission blocker remains.

## Cross-References

- [UID:0001IZ][0x00582460-0x00582495.PathExistsViaStat](by-memory/0x00582460-0x00582495.PathExistsViaStat.md)
- [UID:0000MI][PathUtil](by-file/PathUtil.md)
- [UID:0000JD][FileIO](by-file/FileIO.md)
- [UID:0000TQ][WideApiDispatchTable](by-global/WideApiDispatchTable.md)
- [UID:0000E6][StdioFile](by-class/StdioFile.md)
- [UID:0000IO][DATFileMgr](by-file/DATFileMgr.md)

## Changes

- 2026-08-16 B006 UID0000MI whole-file synchronization:
  - Preserved `91/94`, owner UID0001IZ, `RECONSTRUCTABLE:FALSE`, blank emitter, and blank formal CPP/H.
  - Updated only the final source contract to reflect canonical UID0001IZ position-10 CPP/H ownership and independent UID00022K position-20 CPP ownership, without granting this mirror emission or duplicate source credit.

- 2026-07-24 B001 UID0001IZ duplicate-emitter callback:
  - Changed `87/89` to `91/94`, `CANONICAL_OWNER:0000MI` to `0001IZ`, `RECONSTRUCTABLE:TRUE` to `FALSE`, and `EMITTER_UIDS:0000MI` to blank while preserving a blank formal block.
  - Added exact bytes/hash, ABI, `_stat64i32` layout, predicate, call-site meanings, dispatch dependency/xrefs, uniqueness, padding, source/header route, rejected ownership, and generated expectations as a detailed evidence mirror.
  - Historicalized the earlier compact FileIO/raw dispatch blockers and resolved duplicate emission by making UID0001IZ the sole source-bearing body owner. UID00022K remains a separate PathUtil sibling outside this report's coverage.

- 2026-06-16 A001 packet/path item refresh:
  - Raised completion/confidence from `85/88` to `87/89`.
  - Evidence: live IDA MCP reconfirmed `0x00582460-0x00582495`, the single-stack-buffer `_wstat64i32` dispatch body, exact six caller sites, `unk_69BE18` dependency, and no function at the end byte. A read-only PE scan found the same six direct `E8` references and no absolute VA/RVA pointers to this helper.
  - Routing: owner/emitter remains [UID:0000MI][PathUtil](by-file/PathUtil.md). Final C++ remains blank because `PathUtil.cpp` versus compact `FileIO.cpp` placement and the final platform dispatch typedef/name are still source-quality blockers.

- 2026-06-10 B001-022 parent-gate refresh:
  - Before: `COMPLETION:80`, `CONFIDENCE:86`, attached to PathUtil but below the current strict child-completion gate.
  - Changed to: `COMPLETION:85`, `CONFIDENCE:88`.
  - Summary/evidence: live IDA MCP reconfirmed the exact function range, stat-buffer boolean body, six-call-site spread, dispatch-table dependency, and relationship to the newly assigned [UID:00022K][0x004b81f0-0x004b821e.FileExists](by-memory/0x004b81f0-0x004b821e.FileExists.md) sibling helper.
- 2026-06-03 parent attachment:
  - Before: the item was reconstructable but unassigned, and the proposed source owner only named the FileIO umbrella plus `PathUtil.cpp`/`StdioFile.cpp` alternatives.
  - Changed to: `COMPLETION:74`, `AUTOGEN_PARENT_UID:0000MI`, and staged owner [UID:0000MI][PathUtil](by-file/PathUtil.md), while leaving C++ blank.
  - Summary/evidence: [UID:0001IZ][0x00582460-0x00582495.PathExistsViaStat](by-memory/0x00582460-0x00582495.PathExistsViaStat.md), [UID:0000JD][FileIO](by-file/FileIO.md), and [UID:0001R1][proposed-source-tree](by-project-structure/proposed-source-tree.md) support the util placement; the exact final source split and platform dispatch declaration remain unresolved.
- 2026-06-06 evidence wording and score refresh:
  - Before: the item still cited a recovered source path and stayed at `74/85` even though exact range, dispatch dependency, caller spread, and parent attachment were already documented.
  - Changed to: completion `80`, confidence `86`, with generated-source naming demoted to search context only.
  - Summary/evidence: [UID:0001IZ][0x00582460-0x00582495.PathExistsViaStat](by-memory/0x00582460-0x00582495.PathExistsViaStat.md) records the exact function range, stack stat-buffer behavior, dispatch-table xrefs, and caller list; [UID:0000MI][PathUtil](by-file/PathUtil.md) and [UID:0000JD][FileIO](by-file/FileIO.md) provide the staged utility owner. C++ remains blank because the final dispatch-pointer declaration and `PathUtil.cpp` versus `StdioFile.cpp` split are unresolved.
