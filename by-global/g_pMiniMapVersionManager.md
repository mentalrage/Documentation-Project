*** UID:0000RP | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:82 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# g_pMiniMapVersionManager

## Status

- Entity kind: global singleton pointer
- Confidence: strong for address and owner
- Address: [UID:0001OZ][0x0067a7dc-0x0067a7e0.g_pMiniMapVersionManager](by-memory/0x0067a7dc-0x0067a7e0.g_pMiniMapVersionManager.md)
- Proposed owner: [UID:0000LF][MiniMapVersionManager](by-file/MiniMapVersionManager.md)
- Current generated aliases: `g_pMiniMapVersionManager`, `g_pMiniMapVersionMgr`, IDA `dword_67A7DC`

## Role

This pointer stores the active [UID:00008H][MiniMapVersionManager](by-class/MiniMapVersionManager.md) singleton. Startup constructs and warms it from disk, `StartupWindow` uses it for minimap update checks, and `MiniMapRenderer` uses it to validate map file version/hash data.

## Evidence

- IDA decompilation of `0x004563c0` writes `this` into `dword_67A7DC` during construction.
- IDA decompilation of `0x00456480` clears `dword_67A7DC` during destruction.
- IDA MCP `xrefs_to 0x0067a7dc` reports references from `MiniMapRenderer` version-check paths, `MiniMapVersionManager` constructor/destructor/scalar-destructor helpers, `_WinMain@16`, and `StartupWindow__RunUpdateCheck`.
- [UID:0001OZ][0x0067a7dc-0x0067a7e0.g_pMiniMapVersionManager](by-memory/0x0067a7dc-0x0067a7e0.g_pMiniMapVersionManager.md) records the exact storage slot and owner decision.
- [UID:0000LF][MiniMapVersionManager](by-file/MiniMapVersionManager.md) documents disk cache load/update behavior, persisted `mnmhs.hs` handling, version-string exposure, map-id lookup, and dependency boundaries.
- `source-3/simroot_v2/class_MiniMapVersionManager.cpp` writes `g_pMiniMapVersionManager = this` in the constructor and clears it in the destructor, but current `simroot_v2` has no `class_MiniMapVersionManager.cpp.source_map.json`.
- `source-3/simroot_v2/class_Application.cpp` and `class_StartupWindow.cpp` still show alias pollution through `dword_67A7DC` and `g_pMiniMapVersionMgr`; these should be treated as consumer-side generated aliases until their methods are reviewed.
- Current generated files spell the same concept as both `g_pMiniMapVersionManager` and `g_pMiniMapVersionMgr`; keep the full `g_pMiniMapVersionManager` spelling in documentation unless original-source evidence proves the abbreviated name.
- Live IDA MCP was unavailable during the 2026-05-30 review, so the page relies on recorded IDA MCP notes, exact memory docs, and current simroot leads.

## Cross-References

- [UID:0000LF][MiniMapVersionManager](by-file/MiniMapVersionManager.md)
- [UID:00008H][MiniMapVersionManager](by-class/MiniMapVersionManager.md)
- [UID:0000XP][0x004563c0-0x00457547.MiniMapVersionManager](by-memory/0x004563c0-0x00457547.MiniMapVersionManager.md)
- [UID:0000XQ][0x004570b0-0x004570e0.MiniMapVersionLookupByMapId](by-memory/0x004570b0-0x004570e0.MiniMapVersionLookupByMapId.md)
- [UID:0000LE][MiniMap](by-file/MiniMap.md)

## Changes

- 2026-05-30: Previously this page had stale `0/0` completion/confidence metadata despite exact storage and class/file research. It now records the exact storage page, lifecycle writes/clears, map-id/version-cache role evidence, generated alias caveats, missing owner source-map caveat, and live IDA MCP availability limit. Score changed to `82/84`; confidence is strong for identity/storage but capped by alias pollution and the unresolved original file split.
