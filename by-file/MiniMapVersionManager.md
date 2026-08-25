*** UID:0000LF | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:91 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"NexusTK/map/" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:FILE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***

# MiniMapVersionManager

## Status

- Confidence: very strong for class/global/node ownership, singleton lifetime, exact emitter topology, and focused `map/` placement; high for the literal historical filenames.
- Current reconstruction module: `NexusTK/map/MiniMapVersionManager.cpp`
- Current reconstruction header: `NexusTK/map/MiniMapVersionManager.h`
- Umbrella subsystem: [UID:0000LE][MiniMap](by-file/MiniMap.md)
- Singleton storage: [UID:0000RP][g_pMiniMapVersionManager](by-global/g_pMiniMapVersionManager.md) at [UID:0001OZ][0x0067a7dc-0x0067a7e0.g_pMiniMapVersionManager](by-memory/0x0067a7dc-0x0067a7e0.g_pMiniMapVersionManager.md)

## File Role

`MiniMapVersionManager.cpp` should own the minimap hash/version cache manager. The class is constructed during startup, loads `%APPDATA%\NexusTK\MiniMap\mnmhs.hs`, exposes the current hash-list version string to the startup updater, merges downloaded slash/comma-delimited hash entries, and gives `MiniMapRenderer` the expected version token for a map id before `.mnm` data is accepted.

This is minimap-owned state, not generic startup or DAT archive code. Startup creates and refreshes the manager, while renderer code consumes it for local minimap validation.

## 2026-08-17 Standard-Container Dependency Correction

The manager's map-id/version index is source-facing `stdext::hash_map<int, wchar_t *>` from `<hash_map>`. [UID:0000IP][DATIndexVector](by-file/DATIndexVector.md) is now a non-emitting index for the folded old-MSVC/Dinkumware compiler implementation, not a source file or include dependency. Constructor, insertion, lookup, unwind, and destruction ranges keep their exact binary evidence while source uses the ordinary standard-container API.

## Header / Source Contract And Emission Order

- Header content begins with file-scope [UID:0001V8][MiniMapVersionNode](by-type/by-struct/MiniMapVersionNode.md) at position `5`, followed by [UID:00008H][MiniMapVersionManager](by-class/MiniMapVersionManager.md) and its `extern MiniMapVersionManager *g_pMiniMapVersionManager;` at position `10`.
- Source content emits semantic [UID:0000RP][g_pMiniMapVersionManager](by-global/g_pMiniMapVersionManager.md) at position `20` as the sole `MiniMapVersionManager *g_pMiniMapVersionManager = 0;` definition, followed by physical [UID:0001OZ][0x0067a7dc-0x0067a7e0.g_pMiniMapVersionManager](by-memory/0x0067a7dc-0x0067a7e0.g_pMiniMapVersionManager.md) at position `40` as a no-duplicate marker.
- Class-owned method children expand under UID00008H. Exact method pages remain the behavior/code anchors; the file page establishes source grouping and does not duplicate method bodies.
- Shared standard-container/LinkedList lowering, compiler EH/scalar helpers, vtable, and RTTI remain outside handwritten file content. StartupWindow, MiniMapRenderer, Application, and WinMain are API/lifetime consumers rather than source owners.
- This order gives the class a complete node declaration, the `.cpp` one global definition, and the physical storage child exact binary traceability without nesting or duplicate symbols.

## Proposed Contents

| Entity | Address | Role |
| --- | --- | --- |
| [UID:00008H][MiniMapVersionManager](by-class/MiniMapVersionManager.md) | [UID:0000XP][0x004563c0-0x00457547.MiniMapVersionManager](by-memory/0x004563c0-0x00457547.MiniMapVersionManager.md) | Singleton class for minimap hash-cache lifetime, disk load, update merge, and lookup. |
| [UID:0003FQ][0x006108d4-0x00610980.MiniMapVersionManagerReadOnlyData](by-memory/0x006108d4-0x00610980.MiniMapVersionManagerReadOnlyData.md) | `.rdata` child | Class vtable, cache path formats, slash delimiter data, and version/hash marker strings owned by `MiniMapVersionManager`. |
| `MiniMapVersionManager::MiniMapVersionManager` | [0x004563c0-0x0045647d.MiniMapVersionManagerConstructor](by-memory/0x004563c0-0x0045647d.MiniMapVersionManagerConstructor.md) | Publishes/guard-clears `g_pMiniMapVersionManager`, installs the vtable, and default-constructs the typed `VersionIndex`; sentinel/max-load/eight-bucket operations are private old-MSVC/Dinkumware lowering. |
| `MiniMapVersionManager::~MiniMapVersionManager` | [0x00456480-0x00456532.MiniMapVersionManagerDestructor](by-memory/0x00456480-0x00456532.MiniMapVersionManagerDestructor.md) | Releases manager-owned wide strings, destroys the typed `VersionIndex` through ordinary member lifetime, and clears the singleton; private node/bucket cleanup is compiler lowering. |
| `MiniMapVersionManager::LoadHashFile` | [0x00456540-0x004566fe.MiniMapVersionManagerLoadHashFile](by-memory/0x00456540-0x004566fe.MiniMapVersionManagerLoadHashFile.md) | Loads the local `mnmhs.hs` cache and forwards parsed version/list text to `UpdateHashList(..., false)`. |
| `MiniMapVersionManager::ClearHashList` | [0x00456700-0x00456791.MiniMapVersionManagerClearHashList](by-memory/0x00456700-0x00456791.MiniMapVersionManagerClearHashList.md) | Clears payload strings, nodes, sentinel/count, and embedded index buckets before reinitializing the hash list; current target page now carries formal first-draft C++ and should replace the prior generated empty marker after validation. |
| retained-raw cache-load replay body | [0x004567a0-0x0045695e.MiniMapVersionManagerRawCacheLoadReplay](by-memory/0x004567a0-0x0045695e.MiniMapVersionManagerRawCacheLoadReplay.md) | Source-shaped `mnmhs.hs` replay body with stack cookie and raw `0x00456939` `UpdateHashList(..., false)` call, but not an IDA function and zero start xrefs; documentation-only/no-code. |
| retained-raw cache-save body | [0x00456960-0x00456a8e.MiniMapVersionManagerRawCacheSaveBody](by-memory/0x00456960-0x00456a8e.MiniMapVersionManagerRawCacheSaveBody.md) | Source-shaped cache writer with file-open/write/close and `retn 8`, but not an IDA function and zero start xrefs; documentation-only/no-code. |
| `MiniMapVersionManager::UpdateHashList(const wchar_t* versionString, wchar_t* hashListText, bool saveCache)` | [UID:0002JL][0x00456a90-0x0045709e.MiniMapVersionManagerUpdateHashList](by-memory/0x00456a90-0x0045709e.MiniMapVersionManagerUpdateHashList.md) | Updates `m_currentVersion`, optionally persists cache text, and creates/updates [UID:0001V8][MiniMapVersionNode](by-type/by-struct/MiniMapVersionNode.md) records. |
| `MiniMapVersionManager::GetVersionString() const` | [UID:0002JM][0x004570a0-0x004570a4.MiniMapVersionManagerGetVersionString](by-memory/0x004570a0-0x004570a4.MiniMapVersionManagerGetVersionString.md) | Returns `m_currentVersion` at object offset `+0x04`. |
| `MiniMapVersionManager::GetExpectedVersionForMapId(int mapId) const` | [UID:0000XQ][0x004570b0-0x004570e0.MiniMapVersionLookupByMapId](by-memory/0x004570b0-0x004570e0.MiniMapVersionLookupByMapId.md) | Looks up a map id through `m_versionIndex` at object offset `+0x48` and returns the expected `.mnm` header/version string. |
| `MiniMapVersionManager_ClearSingletonHelper` | [0x004573c0-0x004573cb.MiniMapVersionManagerClearSingletonHelper](by-memory/0x004573c0-0x004573cb.MiniMapVersionManagerClearSingletonHelper.md) | Exact helper that only clears `g_pMiniMapVersionManager` to null. |
| compiler-generated scalar deleting destructor | [0x00457480-0x00457547.MiniMapVersionManagerScalarDeletingDestructor](by-memory/0x00457480-0x00457547.MiniMapVersionManagerScalarDeletingDestructor.md) | Non-reconstructable compiler wrapper around destructor/optional delete; no file-authored C++ body should be emitted. |
| [UID:0001V8][MiniMapVersionNode](by-type/by-struct/MiniMapVersionNode.md) | type-only | Exact 16-byte file-scope node declaration, semantically class-owned but emitted directly through this file at position `5` before the class. |
| [UID:0000RP][g_pMiniMapVersionManager](by-global/g_pMiniMapVersionManager.md) | [UID:0001OZ][0x0067a7dc-0x0067a7e0.g_pMiniMapVersionManager](by-memory/0x0067a7dc-0x0067a7e0.g_pMiniMapVersionManager.md) | Sole zero-initialized source definition at position `20`; the exact physical storage child at position `40` emits no duplicate definition. |

## Dependencies

- `<hash_map>`: complete source dependency for private `VersionIndex`, defined as `stdext::hash_map<int, wchar_t *>`. [UID:0000IP][DATIndexVector](by-file/DATIndexVector.md) documents binary lowering only and generates no CPP/H.
- [UID:0000KR][LinkedList](by-file/LinkedList.md): shared sentinel-list allocation and cleanup helpers reached from construction and teardown. Do not fold those helpers into minimap source.
- Constructor-specific split: [UID:0000XW][0x00457550-0x0045757d.StdListBuyNode8](by-memory/0x00457550-0x0045757d.StdListBuyNode8.md) and [UID:0000WW][0x00423b00-0x00423c3d.DATIndexVectorResizeAndFill](by-memory/0x00423b00-0x00423c3d.DATIndexVectorResizeAndFill.md) are non-emitting standard-container construction lowering; neither moves into `MiniMapVersionManager.cpp` or another custom source file.
- Destructor-specific split: [UID:0000WW][0x00423b00-0x00423c3d.DATIndexVectorResizeAndFill](by-memory/0x00423b00-0x00423c3d.DATIndexVectorResizeAndFill.md), [UID:0000XU][0x004573d0-0x00457429.DATIndexVectorDestructor](by-memory/0x004573d0-0x00457429.DATIndexVectorDestructor.md), and [UID:0000XV][0x00457430-0x00457473.StdListTidy8ByteList](by-memory/0x00457430-0x00457473.StdListTidy8ByteList.md) explain teardown support, but those implementations remain in their helper/source-owner pages rather than `MiniMapVersionManager.cpp`; the scalar deleting destructor peer stays compiler-generated no-code.
- [UID:0000XS][0x00457100-0x0045730f.DATIndexVectorInsertNode](by-memory/0x00457100-0x0045730f.DATIndexVectorInsertNode.md), [UID:0000XT][0x00457310-0x004573b3.DATIndexVectorRemoveNodeHelper](by-memory/0x00457310-0x004573b3.DATIndexVectorRemoveNodeHelper.md), and [UID:0000XU][0x004573d0-0x00457429.DATIndexVectorDestructor](by-memory/0x004573d0-0x00457429.DATIndexVectorDestructor.md): shared helpers inside the physical aggregate remain outside MiniMapVersionManager ownership.
- [UID:0000O5][StartupWindow](by-file/StartupWindow.md): updater caller of `GetVersionString` and `UpdateHashList`.
- [UID:00008F][MiniMapRenderer](by-class/MiniMapRenderer.md): runtime consumer of `GetExpectedVersionForMapId` while checking `.mnm` files.

## Evidence

- IDA MCP `lookup_funcs` on 2026-05-26 confirms modeled functions at `0x004563c0`, `0x00456480`, `0x00456540`, `0x00456a90`, `0x004570a0`, `0x004570b0`, and `0x00457480`.
- IDA MCP callers show construction and `LoadHashFile` reached from `_WinMain@16`, `UpdateHashList` reached from both `LoadHashFile` and `StartupWindow__RunUpdateCheck`, `GetVersionString` reached from `StartupWindow__RunUpdateCheck`, and `GetExpectedVersionForMapId` reached from the two `MiniMapRenderer` version-check paths.
- IDA decompilation shows the constructor/destructor publishing and clearing singleton storage at `0x0067a7dc`, and `xrefs_to 0x0067a7dc` confirms renderer, startup, construction, teardown, and scalar-destructor references.
- Live IDA MCP on 2026-06-05 again confirmed 12 xrefs to `0x0067a7dc`, including `0x004563f7` / `0x004563fe` constructor writes, `0x00456516`, `0x004573c0`, and `0x0045751a` teardown clears, `_WinMain@16`, and `StartupWindow__RunUpdateCheck`.
- Live IDA MCP on 2026-06-06 reconfirmed the same 12 xrefs and zero-initialized bytes for the singleton-adjacent storage beginning at `0x0067a7dc`.
- B001 current MCP session `supervisor_nexustk_20260709` rechecked constructor [UID:0004D8][0x004563c0-0x0045647d.MiniMapVersionManagerConstructor](by-memory/0x004563c0-0x0045647d.MiniMapVersionManagerConstructor.md): active healthy IDB, `sub_4563C0` size `0xbd`, sole `_WinMain@16 + 0x284` caller, singleton publish/guard-clear at `0x004563f7/0x004563fe`, vtable write at `0x0045640b`, `StdListBuyNode8` sentinel creation, and `DATIndexVector::ResizeAndFill(8)` bucket initialization.
- B003 current MCP session `supervisor_nexustk_20260709` rechecked destructor [0x00456480-0x00456532.MiniMapVersionManagerDestructor](by-memory/0x00456480-0x00456532.MiniMapVersionManagerDestructor.md): active healthy IDB, `sub_456480` size `0xb2`, zero direct code xrefs to the non-scalar destructor, `0x00456532-0x00456540` padding before `LoadHashFile`, vtable restore, expected-version string frees, sentinel/count reset, node frees, `DATIndexVector::ResizeAndFill(8)`, `DATIndexVector::~DATIndexVector`, singleton clear, and generated empty-marker/no-code disposition.
- B003 current MCP session `supervisor_nexustk_20260709` rechecked [UID:0004DB][0x00456700-0x00456791.MiniMapVersionManagerClearHashList](by-memory/0x00456700-0x00456791.MiniMapVersionManagerClearHashList.md): active healthy IDB, `sub_456700` size `0x91`, no direct entry callers/xrefs, payload frees at `0x456730-0x456733`, sentinel/count reset at `0x456741-0x456755`, old-node frees at `0x45675c-0x456773`, `DATIndexVector::ResizeAndFill(8)` at `0x456775-0x45677a`, return at `0x00456790`, `0xcc` padding through `0x0045679f`, and `0x004567a0` outside the function. The target now emits first-draft `void MiniMapVersionManager::ClearHashList()` C++ with `delete []`/`delete` documented as inferred source operations over observed CRT/list-helper lowering.
- Keep the exact memory page for `0x004570b0` as the reconstruction anchor until the surrounding method ownership is fully audited.
- B004 retained-raw evidence closes the source-quality blocker for `0x004567a0` and `0x00456960`: both bodies are source-shaped minimap cache code but current IDA reports no function object at either start and `xrefs_to` reports zero start xrefs. They remain documentation-only no-code children rather than file-emitted source.
- B004 preserves the dedicated `NexusTK/map/` route as nonblocking despite the historical possibility of a broader `MiniMap.cpp`; stale Wave2/Wave3 export-name leads do not override the current IDA-backed file/class/aggregate route.
- 2026-07-23 live evidence closes the first-draft file contract: exact target bytes are four zero bytes with SHA256 `DF3F619804A92FDB4057192DC43DD748EA778ADC52BC498CE80524C014B81119`; `xrefs_to` returns exactly 12 references (`more:false`), split into seven reads and five publication/clear stores; RTTI identifies `MiniMapVersionManager` plus `Singleton<MiniMapVersionManager>` with base PMD `+0x04`; and WinMain allocates the exact `0x68`-byte complete object.
- The exact class layout is vptr at `+0x00`, empty Singleton base/member start at `+0x04`, 33-wide-character current-version buffer at `+0x04`, natural padding to `+0x48`, and `0x20`-byte `VersionIndex` through `+0x68`. The exact private node remains compiler-layout evidence with map-id and expected-version pointer payload.
- Renderer reads at `0x00454336/0x00454da0`, Application teardown reads at `0x00464c89/0x00464e8c`, WinMain cache-load read at `0x004f5d09`, StartupWindow update reads at `0x00580e99/0x00580fc5`, and constructor/destructor/EH/scalar stores at `0x004563f7/0x004563fe/0x00456516/0x004573c0/0x0045751a` establish the full file-level lifetime and consumer map.

## Source Placement

Use focused `NexusTK/map/MiniMapVersionManager.h` and `NexusTK/map/MiniMapVersionManager.cpp` in the current reconstructed tree. The manager's distinct class RTTI, singleton lifetime, disk-cache literals and bodies, update merge, map-id/version index, exact generated route, and existing file page make this the strongest source-quality grouping.

A compact historical `MiniMap.cpp` remains possible because original source/PDB filenames do not survive, but that bounded historical uncertainty is no longer an active emitter choice. [UID:0000LE][MiniMap](by-file/MiniMap.md) remains the umbrella subsystem and must not define a second class/global copy.

Do not move this class into [UID:0000IM][DATArchive](by-file/DATArchive.md) or [UID:0000IP][DATIndexVector](by-file/DATIndexVector.md): the former is unrelated archive source and the latter is a non-emitting compiler-family index. Do not move it into [UID:0000O5][StartupWindow](by-file/StartupWindow.md): startup is only a lifecycle/update caller.

## Score Rationale

Completion `91` covers the focused header/source contract, source order, node/class/global/physical roles, exact one-definition topology, complete method/helper inventory, retained-raw and compiler-generated boundaries, exact target storage/hash, full 12-reference lifetime/consumer map, RTTI inheritance, `0x68` class layout, dependency rejection, and generated ownership route. Confidence `92` reflects strong independent binary and documentation agreement. Original literal filenames, include spellings, private lexical names, and some final method source shapes remain inferred, keeping the file below 95 without leaving IDA-style source.

## Historical Assumptions Superseded

- Earlier revisions treated separate `MiniMapVersionManager.cpp` versus broader `MiniMap.cpp` as a confidence-capping active choice. Current reconstruction now uses the focused page/path as the direct route; the broader possibility remains historical context only.
- Earlier constructor/destructor rows said class-level/member construction uncertainty forced blank declarations. The exact RTTI inheritance, allocation size, major-member layout, accepted first-draft class shell, and compiler-boundary treatment now supersede that global blank-code blocker while preserving method-specific caveats on their exact pages.
- Earlier generated empty-marker observations remain useful historical evidence. The accepted emitter positions `5/10/20/40` are now the current intended generated topology; validator output is authoritative after refresh.

## Cross-References

- [UID:0000LE][MiniMap](by-file/MiniMap.md)
- [UID:00008H][MiniMapVersionManager](by-class/MiniMapVersionManager.md)
- [UID:0000XP][0x004563c0-0x00457547.MiniMapVersionManager](by-memory/0x004563c0-0x00457547.MiniMapVersionManager.md)
- [UID:0003FQ][0x006108d4-0x00610980.MiniMapVersionManagerReadOnlyData](by-memory/0x006108d4-0x00610980.MiniMapVersionManagerReadOnlyData.md)
- [0x004563c0-0x0045647d.MiniMapVersionManagerConstructor](by-memory/0x004563c0-0x0045647d.MiniMapVersionManagerConstructor.md)
- [0x00456480-0x00456532.MiniMapVersionManagerDestructor](by-memory/0x00456480-0x00456532.MiniMapVersionManagerDestructor.md)
- [0x00456540-0x004566fe.MiniMapVersionManagerLoadHashFile](by-memory/0x00456540-0x004566fe.MiniMapVersionManagerLoadHashFile.md)
- [0x00456700-0x00456791.MiniMapVersionManagerClearHashList](by-memory/0x00456700-0x00456791.MiniMapVersionManagerClearHashList.md)
- [0x004567a0-0x0045695e.MiniMapVersionManagerRawCacheLoadReplay](by-memory/0x004567a0-0x0045695e.MiniMapVersionManagerRawCacheLoadReplay.md)
- [0x00456960-0x00456a8e.MiniMapVersionManagerRawCacheSaveBody](by-memory/0x00456960-0x00456a8e.MiniMapVersionManagerRawCacheSaveBody.md)
- [UID:0002JL][0x00456a90-0x0045709e.MiniMapVersionManagerUpdateHashList](by-memory/0x00456a90-0x0045709e.MiniMapVersionManagerUpdateHashList.md)
- [UID:0002JM][0x004570a0-0x004570a4.MiniMapVersionManagerGetVersionString](by-memory/0x004570a0-0x004570a4.MiniMapVersionManagerGetVersionString.md)
- [UID:0000XQ][0x004570b0-0x004570e0.MiniMapVersionLookupByMapId](by-memory/0x004570b0-0x004570e0.MiniMapVersionLookupByMapId.md)
- [0x004573c0-0x004573cb.MiniMapVersionManagerClearSingletonHelper](by-memory/0x004573c0-0x004573cb.MiniMapVersionManagerClearSingletonHelper.md)
- [0x00457480-0x00457547.MiniMapVersionManagerScalarDeletingDestructor](by-memory/0x00457480-0x00457547.MiniMapVersionManagerScalarDeletingDestructor.md)
- [UID:0001V8][MiniMapVersionNode](by-type/by-struct/MiniMapVersionNode.md)
- [UID:0000RP][g_pMiniMapVersionManager](by-global/g_pMiniMapVersionManager.md)
- [UID:0001OZ][0x0067a7dc-0x0067a7e0.g_pMiniMapVersionManager](by-memory/0x0067a7dc-0x0067a7e0.g_pMiniMapVersionManager.md)

## Changes

- 2026-08-17 B007 UID0000PA provider-header and source-order closure:
  - `MiniMapVersionManager.h` now owns the complete guarded `0x68` Singleton-derived declaration and includes the complete `DATIndexVector.h` dependency required by its embedded by-value member.
  - `MiniMapVersionManager.cpp` begins at position `5` with the manager-header include followed by the exact source-local `MiniMapVersionNode`; position `10` emits manager children without duplicating the class declaration.
  - WinMain's startup construction and `LoadHashFile()` call now compile through the provider header. The node stays translation-unit-local, while version-index lifecycle, lookup, update, cache, and singleton ownership remain in this file.

- 2026-07-23 B002 UID0001OZ accepted implementation callback:
  - Raised the file from `86/86` to `91/92` and established focused `NexusTK/map/MiniMapVersionManager.h/.cpp` as the current direct source route.
  - Added exact header/source roles and emitter order `5/10/20/40`, sole global definition, no-duplicate physical marker, class/node declarations, full lifetime/consumer map, RTTI/PMD and `0x68` layout evidence, dependency/compiler boundaries, score rationale, and rejected alternative owners.
  - Preserved the historical broader-`MiniMap.cpp` and empty-emitter assumptions as explicitly superseded context rather than deleting them.

- Before: completion/confidence were ungraded at `0/0`.
- Changed to: completion `86`, confidence `86`.
- Summary/evidence: the page documents the singleton role, disk-cache/hash-list behavior, method map, dependencies, IDA caller evidence, source placement, and method-ownership caveats; confidence remains capped by the unresolved separate-file versus broader `MiniMap.cpp` question.

- 2026-06-12 A004 Batch 254 read-only-data split note:
  - Score unchanged at `86/86`.
  - Added [UID:0003FQ][0x006108d4-0x00610980.MiniMapVersionManagerReadOnlyData](by-memory/0x006108d4-0x00610980.MiniMapVersionManagerReadOnlyData.md) to the proposed contents after live IDA confirmed the exact `0x006108d4-0x00610980` class-owned vtable/cache-string child.

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
- 2026-06-17 B002 source-quality execution:
  - Score unchanged at `86/86`.
  - Updated proposed contents to use the resolved source-facing method signatures and field names from the accepted MiniMapVersionManager method report. The file route remains `NexusTK/map/MiniMapVersionManager.cpp`; StartupWindow, MiniMapRenderer, DATIndexVector, and LinkedList remain consumers/dependencies rather than source owners.
- 2026-07-02 B004 implementation callback:
  - Added exact child pages for constructor, destructor, `LoadHashFile`, `ClearHashList`, retained-raw cache-load replay, retained-raw cache-save body, singleton-clear helper, and scalar deleting destructor to proposed contents and cross-references.
  - Preserved `PROPOSED_RECONSTRUCTION_PATH:"NexusTK/map/"`. The dedicated file versus broader `MiniMap.cpp` question remains nonblocking; shared DATIndexVector/List helpers in the physical aggregate remain dependencies, not MiniMapVersionManager-owned source.
- 2026-07-09 B001 UID0004D8 implementation callback:
  - Score/path unchanged at `86/86` and `NexusTK/map/`.
  - Updated the constructor proposed-content row, dependency split, and evidence with current MCP-backed details: publish/guard-clear singleton writes, vtable write, sole startup caller, embedded DATIndexVector/list-state setup, non-emitting `StdListBuyNode8`, source-owned `DATIndexVector::ResizeAndFill(8)`, and blank constructor C++ pending accepted member-construction declarations.
- 2026-07-09 B003 UID0004D9 implementation callback:
  - Score/path unchanged at `86/86` and `NexusTK/map/`.
  - Updated the destructor proposed-content row, dependency split, and evidence with current MCP-backed details: exact range/padding, vtable restore, payload and node cleanup, sentinel/count reset, `DATIndexVector::ResizeAndFill(8)`, `DATIndexVector::~DATIndexVector`, singleton clear, scalar deleting destructor relationship, and no-code/generated empty-marker disposition.
- 2026-07-09 B003 UID0004DB implementation callback:
  - Score/path unchanged at `86/86` and `NexusTK/map/`.
  - Updated the `ClearHashList` proposed-content row and evidence with current MCP-backed details: exact `0x00456700-0x00456791` range, `sub_456700` size `0x91`, no direct entry callers/xrefs, payload free anchors, sentinel/count reset, old-node free loop, `DATIndexVector::ResizeAndFill(8)`, return at `0x00456790`, `0xcc` padding through `0x0045679f`, and `0x004567a0` not a current IDA function.
  - The child [UID:0004DB][0x00456700-0x00456791.MiniMapVersionManagerClearHashList](by-memory/0x00456700-0x00456791.MiniMapVersionManagerClearHashList.md) now carries score `89/91` and formal first-draft C++; generated `MiniMapVersionManager.cpp` should no longer retain UID0004DB as an empty marker once the scoped validator refreshes output.
