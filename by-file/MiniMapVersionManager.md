*** UID:0000LF | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"NexusTK/map/" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***

# MiniMapVersionManager

## Status

- Confidence: strong for class ownership, singleton lifecycle, and `map/` placement; medium-high for whether this was a separate original `.cpp` or compiled into a larger `MiniMap.cpp`.
- Proposed module: `map/MiniMapVersionManager.cpp`
- Proposed header: `map/MiniMapVersionManager.h` or declarations inside a broader `map/MiniMap.h`
- Umbrella subsystem: [UID:0000LE][MiniMap](by-file/MiniMap.md)
- Singleton storage: [UID:0000RP][g_pMiniMapVersionManager](by-global/g_pMiniMapVersionManager.md) at [UID:0001OZ][0x0067a7dc-0x0067a7e0.g_pMiniMapVersionManager](by-memory/0x0067a7dc-0x0067a7e0.g_pMiniMapVersionManager.md)

## File Role

`MiniMapVersionManager.cpp` should own the minimap hash/version cache manager. The class is constructed during startup, loads `%APPDATA%\NexusTK\MiniMap\mnmhs.hs`, exposes the current hash-list version string to the startup updater, merges downloaded slash/comma-delimited hash entries, and gives `MiniMapRenderer` the expected version token for a map id before `.mnm` data is accepted.

This is minimap-owned state, not generic startup or DAT archive code. Startup creates and refreshes the manager, while renderer code consumes it for local minimap validation.

## Proposed Contents

| Entity | Address | Role |
| --- | --- | --- |
| [UID:00008H][MiniMapVersionManager](by-class/MiniMapVersionManager.md) | [UID:0000XP][0x004563c0-0x00457547.MiniMapVersionManager](by-memory/0x004563c0-0x00457547.MiniMapVersionManager.md) | Singleton class for minimap hash-cache lifetime, disk load, update merge, and lookup. |
| `MiniMapVersionManager::LoadHashFile` | `0x00456540-0x004566fe` | Loads the local `mnmhs.hs` cache and forwards parsed text to `UpdateHashList`. |
| `MiniMapVersionManager::UpdateHashList` | [UID:0002JL][0x00456a90-0x0045709e.MiniMapVersionManagerUpdateHashList](by-memory/0x00456a90-0x0045709e.MiniMapVersionManagerUpdateHashList.md) | Updates the current version string, optionally persists cache text, and creates/updates [UID:0001V8][MiniMapVersionNode](by-type/by-struct/MiniMapVersionNode.md) records. |
| `MiniMapVersionManager::GetVersionString` | [UID:0002JM][0x004570a0-0x004570a4.MiniMapVersionManagerGetVersionString](by-memory/0x004570a0-0x004570a4.MiniMapVersionManagerGetVersionString.md) | Returns the current version string buffer at object offset `+0x04`. |
| `MiniMapVersionManager::GetExpectedVersionForMapId` | [UID:0000XQ][0x004570b0-0x004570e0.MiniMapVersionLookupByMapId](by-memory/0x004570b0-0x004570e0.MiniMapVersionLookupByMapId.md) | Looks up a map id through the embedded [UID:0000IP][DATIndexVector](by-file/DATIndexVector.md) at object offset `+0x48`. |
| [UID:0001V8][MiniMapVersionNode](by-type/by-struct/MiniMapVersionNode.md) | type-only | Intrusive node payload overlay for map id and version/hash string. |
| [UID:0000RP][g_pMiniMapVersionManager](by-global/g_pMiniMapVersionManager.md) | [UID:0001OZ][0x0067a7dc-0x0067a7e0.g_pMiniMapVersionManager](by-memory/0x0067a7dc-0x0067a7e0.g_pMiniMapVersionManager.md) | Process singleton pointer written by constructor/destructor and read by startup and renderer paths. |

## Dependencies

- [UID:0000IP][DATIndexVector](by-file/DATIndexVector.md): embedded hash/index helper used for map-id lookup and update insertion. Keep the shared container implementation in `DATIndexVector.cpp`.
- [UID:0000KR][LinkedList](by-file/LinkedList.md): shared sentinel-list allocation and cleanup helpers reached from construction and teardown. Do not fold those helpers into minimap source.
- [UID:0000O5][StartupWindow](by-file/StartupWindow.md): updater caller of `GetVersionString` and `UpdateHashList`.
- [UID:00008F][MiniMapRenderer](by-class/MiniMapRenderer.md): runtime consumer of `GetExpectedVersionForMapId` while checking `.mnm` files.

## Evidence

- IDA MCP `lookup_funcs` on 2026-05-26 confirms modeled functions at `0x004563c0`, `0x00456480`, `0x00456540`, `0x00456a90`, `0x004570a0`, `0x004570b0`, and `0x00457480`.
- IDA MCP callers show construction and `LoadHashFile` reached from `_WinMain@16`, `UpdateHashList` reached from both `LoadHashFile` and `StartupWindow__RunUpdateCheck`, `GetVersionString` reached from `StartupWindow__RunUpdateCheck`, and `GetExpectedVersionForMapId` reached from the two `MiniMapRenderer` version-check paths.
- IDA decompilation shows the constructor/destructor publishing and clearing singleton storage at `0x0067a7dc`, and `xrefs_to 0x0067a7dc` confirms renderer, startup, construction, teardown, and scalar-destructor references.
- Live IDA MCP on 2026-06-05 again confirmed 12 xrefs to `0x0067a7dc`, including `0x004563f7` / `0x004563fe` constructor writes, `0x00456516`, `0x004573c0`, and `0x0045751a` teardown clears, `_WinMain@16`, and `StartupWindow__RunUpdateCheck`.
- Live IDA MCP on 2026-06-06 reconfirmed the same 12 xrefs and zero-initialized bytes for the singleton-adjacent storage beginning at `0x0067a7dc`.
- Keep the exact memory page for `0x004570b0` as the reconstruction anchor until the surrounding method ownership is fully audited.

## Source Placement

Prefer a separate `map/MiniMapVersionManager.cpp` in the reconstructed tree. A compact legacy `map/MiniMap.cpp` is still plausible, but this manager has enough independent lifetime, disk-cache, and hash-index behavior to justify a focused migration unit.

Do not move this class into [UID:0000IM][DATArchive](by-file/DATArchive.md) or [UID:0000IP][DATIndexVector](by-file/DATIndexVector.md): those are dependencies. Do not move it into [UID:0000O5][StartupWindow](by-file/StartupWindow.md): startup is only a lifecycle/update caller.

## Cross-References

- [UID:0000LE][MiniMap](by-file/MiniMap.md)
- [UID:00008H][MiniMapVersionManager](by-class/MiniMapVersionManager.md)
- [UID:0000XP][0x004563c0-0x00457547.MiniMapVersionManager](by-memory/0x004563c0-0x00457547.MiniMapVersionManager.md)
- [UID:0002JL][0x00456a90-0x0045709e.MiniMapVersionManagerUpdateHashList](by-memory/0x00456a90-0x0045709e.MiniMapVersionManagerUpdateHashList.md)
- [UID:0002JM][0x004570a0-0x004570a4.MiniMapVersionManagerGetVersionString](by-memory/0x004570a0-0x004570a4.MiniMapVersionManagerGetVersionString.md)
- [UID:0000XQ][0x004570b0-0x004570e0.MiniMapVersionLookupByMapId](by-memory/0x004570b0-0x004570e0.MiniMapVersionLookupByMapId.md)
- [UID:0001V8][MiniMapVersionNode](by-type/by-struct/MiniMapVersionNode.md)
- [UID:0000RP][g_pMiniMapVersionManager](by-global/g_pMiniMapVersionManager.md)
- [UID:0001OZ][0x0067a7dc-0x0067a7e0.g_pMiniMapVersionManager](by-memory/0x0067a7dc-0x0067a7e0.g_pMiniMapVersionManager.md)

## Changes

- Before: completion/confidence were ungraded at `0/0`.
- Changed to: completion `86`, confidence `86`.
- Summary/evidence: the page documents the singleton role, disk-cache/hash-list behavior, method map, dependencies, IDA caller evidence, source placement, and method-ownership caveats; confidence remains capped by the unresolved separate-file versus broader `MiniMap.cpp` question.

- Before: the method inventory listed `UpdateHashList` and `GetVersionString` as raw ranges only, and the lookup helper was still being reconciled after its end-exclusive range correction.
- Changed to: `UpdateHashList` and `GetVersionString` now link to exact by-memory child pages, and the lookup helper references the corrected `0x004570b0-0x004570e0` page.
- Summary/evidence: IDA MCP `lookup_funcs`, decompilation, and disassembly on 2026-05-31 verified the `0x00456a90`, `0x004570a0`, and `0x004570b0` function boundaries and the padding between them.

- 2026-06-05 projected path assignment:
  - What existed before: `PROPOSED_RECONSTRUCTION_PATH` was blank, so the by-file root remained an autogen file-path error.
  - Changed to: `PROPOSED_RECONSTRUCTION_PATH:"NexusTK/map/"`.
  - Summary/evidence: `by-project-structure/proposed-source-tree.md` places `MiniMapVersionManager.cpp` under `NexusTK/map/`; live IDA MCP xrefs/decompilation confirm the singleton lifecycle at `0x0067a7dc` and minimap/startup consumers documented on this page.
- 2026-06-06 source-facing cleanup:
  - What existed before: the file page still cited a raw singleton label in evidence and an older confidence score.
  - Changed to: confidence `86`, refreshed singleton xref/byte evidence, and source-facing singleton wording.
  - Summary/evidence: live IDA MCP reconfirms constructor publish, teardown clears, startup/update-check readers, renderer readers, and zero-initialized storage; original source split is still the remaining confidence cap.
