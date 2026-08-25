*** UID:0000RP | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000LF | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000LF | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL:20 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
MiniMapVersionManager *g_pMiniMapVersionManager = 0;

[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# g_pMiniMapVersionManager

## Status

- Entity kind: global singleton pointer
- Confidence: very strong for exact storage, complete-object pointer type, owner, sole-definition route, initializer, all lifecycle writes/clears, and all consumers
- Address: [UID:0001OZ][0x0067a7dc-0x0067a7e0.g_pMiniMapVersionManager](by-memory/0x0067a7dc-0x0067a7e0.g_pMiniMapVersionManager.md)
- Proposed owner: [UID:0000LF][MiniMapVersionManager](by-file/MiniMapVersionManager.md)
- Canonical documentation name: `g_pMiniMapVersionManager`

## Role

This pointer is the sole source-level definition of the active [UID:00008H][MiniMapVersionManager](by-class/MiniMapVersionManager.md) singleton. It is zero-initialized at exact physical [UID:0001OZ][0x0067a7dc-0x0067a7e0.g_pMiniMapVersionManager](by-memory/0x0067a7dc-0x0067a7e0.g_pMiniMapVersionManager.md), declared `extern` by the class/header page, and defined once through focused [UID:0000LF][MiniMapVersionManager](by-file/MiniMapVersionManager.md). Startup constructs and warms it from disk, `StartupWindow` uses it for minimap update checks, `MiniMapRenderer` validates map file version/hash data through it, and Application teardown deletes it.

## Declaration, Definition, And Linkage

- Header declaration: `extern MiniMapVersionManager *g_pMiniMapVersionManager;`, emitted with [UID:00008H][MiniMapVersionManager](by-class/MiniMapVersionManager.md).
- Source definition: `MiniMapVersionManager *g_pMiniMapVersionManager = 0;`, emitted here at position `20` through `NexusTK/map/MiniMapVersionManager.cpp`.
- Physical [UID:0001OZ][0x0067a7dc-0x0067a7e0.g_pMiniMapVersionManager](by-memory/0x0067a7dc-0x0067a7e0.g_pMiniMapVersionManager.md) emits only a no-duplicate marker at position `40`. It does not emit a second variable definition.
- The explicit `0` initializer matches the four zero loaded-image bytes and mid-2000s project style while preserving ordinary static-storage behavior.
- No source assignment is added merely to reproduce inlined Singleton publication or compiler-generated teardown clears. Those effects remain in the constructor/destructor lowering documented by exact method pages.

## Evidence

- IDA decompilation of `0x004563c0` publishes the constructed manager pointer to `0x0067a7dc`.
- IDA decompilation of `0x00456480` clears the singleton slot during destruction.
- IDA MCP `xrefs_to 0x0067a7dc` reports references from `MiniMapRenderer` version-check paths, `MiniMapVersionManager` constructor/destructor/scalar-destructor helpers, `_WinMain@16`, and `StartupWindow__RunUpdateCheck`.
- [UID:0001OZ][0x0067a7dc-0x0067a7e0.g_pMiniMapVersionManager](by-memory/0x0067a7dc-0x0067a7e0.g_pMiniMapVersionManager.md) records the exact storage slot and owner decision.
- [UID:0000LF][MiniMapVersionManager](by-file/MiniMapVersionManager.md) documents disk cache load/update behavior, persisted `mnmhs.hs` handling, version-string exposure, map-id lookup, and dependency boundaries.
- Live IDA MCP on 2026-06-05 reports 12 xrefs to `0x0067a7dc`, including constructor writes at `0x004563f7` / `0x004563fe`, teardown clears at `0x00456516`, `0x004573c0`, and `0x0045751a`, `_WinMain@16`, and `StartupWindow__RunUpdateCheck`.
- Live IDA MCP on 2026-06-06 reconfirms the same 12 xrefs and shows the adjacent 16 bytes beginning at `0x0067a7dc` are zero-initialized in the loaded image.
- Decompilation shows `0x004563c0` installing the `MiniMapVersionManager` vtable and publishing the manager pointer, while `0x00456480`, `0x004573c0`, and `0x00457480` clear the slot during teardown.
- [0x004573c0-0x004573cb.MiniMapVersionManagerClearSingletonHelper](by-memory/0x004573c0-0x004573cb.MiniMapVersionManagerClearSingletonHelper.md) is the exact child page for the standalone singleton-clear write `g_pMiniMapVersionManager = nullptr`.
- Keep the full `g_pMiniMapVersionManager` spelling in documentation unless original-source evidence proves an abbreviated source declaration.
- 2026-06-16 C001 live IDA refresh reconfirmed 12 direct xrefs to `0x0067a7dc`: renderer readers at `0x00454336`/`0x00454da0`, constructor publish/guard clear at `0x004563f7`/`0x004563fe`, teardown/helper/scalar-deleting clears at `0x00456516`, `0x004573c0`, and `0x0045751a`, application transition readers at `0x00464c89`/`0x00464e8c`, `_WinMain@16` at `0x004f5d09`, and update-check readers at `0x00580e99`/`0x00580fc5`. `get_bytes 0x0067a7d0` confirmed the singleton-adjacent window is zeroed.
- Historical 2026-06-16 C001 evidence reported saved names for the global and lifecycle helpers. Current 2026-07-23 live IDA readback supersedes that current-state claim: no defined/typed entity is present at `0x0067a7dc`, decompilation still uses `dword_67A7DC`, and all nine manager functions retain raw `sub_*` names. The accepted supervisor-owned Gate 2B handoff, not B002's ordinary-doc callback, will repair and verify that analysis state.

## Exact Storage, Type, And Lifetime

- Exact range `[0x0067a7dc,0x0067a7e0)` contains `00 00 00 00`; four-byte SHA256 is `DF3F619804A92FDB4057192DC43DD748EA778ADC52BC498CE80524C014B81119`.
- Live IDA MCP returned exactly 12 direct references with `more:false`: seven reads at `0x00454336`, `0x00454da0`, `0x00464c89`, `0x00464e8c`, `0x004f5d09`, `0x00580e99`, and `0x00580fc5`; five publication/clear stores at `0x004563f7`, `0x004563fe`, `0x00456516`, `0x004573c0`, and `0x0045751a`.
- RTTI identifies `MiniMapVersionManager` and `Singleton<MiniMapVersionManager>`. The Singleton base descriptor PMD is `mdisp=4,pdisp=-1,vdisp=0`; constructor lowering subtracts that displacement before publication, so this global stores a complete `MiniMapVersionManager *` rather than a base pointer.
- WinMain allocates exactly `0x68` bytes. The source layout is vptr at `+0x00`, empty Singleton base/member start at `+0x04`, `wchar_t m_currentVersion[33]`, natural padding through `+0x48`, and a `0x20`-byte `DATIndexVector m_versionIndex` through `+0x68`.
- Lifetime is complete: construction publishes, constructor-unwind/ordinary/destructing paths clear, renderer/startup/update paths read, and two Application shutdown paths delete through the virtual interface.

## Ownership And Rejected Alternatives

- Focused [UID:0000LF][MiniMapVersionManager](by-file/MiniMapVersionManager.md) owns the declaration/definition because class methods, RTTI, cache literals, singleton lifetime, and generated route converge there.
- Application, WinMain, StartupWindow, and MiniMapRenderer are consumers. DATIndexVector and LinkedList are lower-level dependencies. Broad [UID:0000LE][MiniMap](by-file/MiniMap.md) is an umbrella, not a second definition owner.
- Reject emitting from both semantic and physical pages, moving the definition to a consumer, typing it as `void *`/integer/Singleton-base/DATIndexVector, or preserving `dword_67A7DC` in source.
- Reject the former blocker that internal list/vector lexical names, retained-raw cache bodies, or exact historical file split must be finalized before this simple pointer definition can exist.

## Score Rationale

Completion `92` covers exact storage/initializer, complete xrefs and lifetime, RTTI-proven type/inheritance, exact object size/layout, header/source linkage, sole-definition topology, focused source placement, and rejected duplicate/consumer routes. Confidence `94` reflects direct byte, instruction, xref, RTTI, allocation, receiver, and documentation agreement. Original PDB spellings, exact access qualifiers, and the literal historical header filename remain inferred and keep the page below 95 without requiring raw reverse-engineering labels.

## Cross-References

- [UID:0000LF][MiniMapVersionManager](by-file/MiniMapVersionManager.md)
- [UID:00008H][MiniMapVersionManager](by-class/MiniMapVersionManager.md)
- [UID:0000XP][0x004563c0-0x00457547.MiniMapVersionManager](by-memory/0x004563c0-0x00457547.MiniMapVersionManager.md)
- [0x004573c0-0x004573cb.MiniMapVersionManagerClearSingletonHelper](by-memory/0x004573c0-0x004573cb.MiniMapVersionManagerClearSingletonHelper.md)
- [UID:0000XQ][0x004570b0-0x004570e0.MiniMapVersionLookupByMapId](by-memory/0x004570b0-0x004570e0.MiniMapVersionLookupByMapId.md)
- [UID:0000LE][MiniMap](by-file/MiniMap.md)

## Changes

- 2026-07-23 B002 UID0001OZ accepted implementation callback:
  - Changed score from `85/90` to `92/94`, set emitter position `20`, and added the sole zero-initialized `MiniMapVersionManager *g_pMiniMapVersionManager = 0;` definition plus child expansion.
  - Added exact storage/hash, seven-read/five-write lifetime inventory, complete-object type and Singleton PMD proof, exact `0x68` layout, extern/definition/physical-marker topology, focused source placement, current IDA readback, and rejected duplicate/consumer alternatives.
  - Historicalized the stale saved-IDA-name claim and the disproved internal-field/cache-body/source-split blocker instead of deleting them.

- 2026-05-30: Previously this page had stale `0/0` completion/confidence metadata despite exact storage and class/file research. It now records the exact storage page, lifecycle writes/clears, map-id/version-cache role evidence, naming caveat, and unresolved original-file split. Score changed to `82/84`; confidence is strong for identity/storage but capped by naming uncertainty and the unresolved original file split.

- 2026-06-05 autogen classification:
  - What existed before: autogen metadata was blank, so the singleton was reported as unclassified.
  - Changed to: `RECONSTRUCTABLE:TRUE` with `AUTOGEN_PARENT_UID:0000LF`; `RECONSTRUCTION_CPP CODE` remains empty.
  - Summary/evidence: live IDA MCP `xrefs_to 0x0067a7dc` and decompilation of `0x004563c0`, `0x00456480`, `0x004573c0`, and `0x00457480` prove NexusTK-owned `MiniMapVersionManager` singleton storage owned by [UID:0000LF][MiniMapVersionManager](by-file/MiniMapVersionManager.md). No final C++ body was added because the page is below the 95/95 reconstruction gate.

- 2026-06-06 source-facing cleanup:
  - What existed before: the page still described the singleton with a raw IDA storage label and stale generated-alias caveats in the coverage row.
  - Changed to: score `84/88`, source-facing singleton-slot wording, refreshed live xref/byte evidence, and synced the manual by-global coverage row.
  - Summary/evidence: live IDA MCP again reports the constructor publish, teardown clears, startup/update-check readers, renderer readers, and zero-initialized storage; final declaration spelling remains provisional, so C++ stays blank.
- 2026-06-16 C001 global/source-quality refresh:
  - What existed before: score `84/88`, exact singleton lifecycle was documented, but IDA still used generated names for the storage and lifecycle helpers.
  - Changed to: score `85/90`; IDA names were saved for the global and four lifecycle helpers.
  - Summary/evidence: live IDA reconfirmed the exact 12-xref lifecycle/consumer set, zeroed singleton-cluster bytes, startup/update/renderer consumers, and focused owner/emitter route through [UID:0000LF][MiniMapVersionManager](by-file/MiniMapVersionManager.md). Final C++ remains blank because internal list/vector field names, cache-load/cache-save body promotion, and the dedicated `MiniMapVersionManager.cpp` versus broader `MiniMap.cpp` source split still require source-quality resolution.
- 2026-07-02 B004 implementation callback: added the exact clear-singleton helper child page cross-reference [0x004573c0-0x004573cb.MiniMapVersionManagerClearSingletonHelper](by-memory/0x004573c0-0x004573cb.MiniMapVersionManagerClearSingletonHelper.md). Metadata unchanged.
