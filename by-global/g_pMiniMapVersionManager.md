*** UID:0000RP | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000LF | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# g_pMiniMapVersionManager

## Status

- Entity kind: global singleton pointer
- Confidence: strong for address, owner, lifecycle writes, and consumers
- Address: [UID:0001OZ][0x0067a7dc-0x0067a7e0.g_pMiniMapVersionManager](by-memory/0x0067a7dc-0x0067a7e0.g_pMiniMapVersionManager.md)
- Proposed owner: [UID:0000LF][MiniMapVersionManager](by-file/MiniMapVersionManager.md)
- Canonical documentation name: `g_pMiniMapVersionManager`

## Role

This pointer stores the active [UID:00008H][MiniMapVersionManager](by-class/MiniMapVersionManager.md) singleton. Startup constructs and warms it from disk, `StartupWindow` uses it for minimap update checks, and `MiniMapRenderer` uses it to validate map file version/hash data.

## Evidence

- IDA decompilation of `0x004563c0` publishes the constructed manager pointer to `0x0067a7dc`.
- IDA decompilation of `0x00456480` clears the singleton slot during destruction.
- IDA MCP `xrefs_to 0x0067a7dc` reports references from `MiniMapRenderer` version-check paths, `MiniMapVersionManager` constructor/destructor/scalar-destructor helpers, `_WinMain@16`, and `StartupWindow__RunUpdateCheck`.
- [UID:0001OZ][0x0067a7dc-0x0067a7e0.g_pMiniMapVersionManager](by-memory/0x0067a7dc-0x0067a7e0.g_pMiniMapVersionManager.md) records the exact storage slot and owner decision.
- [UID:0000LF][MiniMapVersionManager](by-file/MiniMapVersionManager.md) documents disk cache load/update behavior, persisted `mnmhs.hs` handling, version-string exposure, map-id lookup, and dependency boundaries.
- Live IDA MCP on 2026-06-05 reports 12 xrefs to `0x0067a7dc`, including constructor writes at `0x004563f7` / `0x004563fe`, teardown clears at `0x00456516`, `0x004573c0`, and `0x0045751a`, `_WinMain@16`, and `StartupWindow__RunUpdateCheck`.
- Live IDA MCP on 2026-06-06 reconfirms the same 12 xrefs and shows the adjacent 16 bytes beginning at `0x0067a7dc` are zero-initialized in the loaded image.
- Decompilation shows `0x004563c0` installing the `MiniMapVersionManager` vtable and publishing the manager pointer, while `0x00456480`, `0x004573c0`, and `0x00457480` clear the slot during teardown.
- Keep the full `g_pMiniMapVersionManager` spelling in documentation unless original-source evidence proves an abbreviated source declaration.

## Cross-References

- [UID:0000LF][MiniMapVersionManager](by-file/MiniMapVersionManager.md)
- [UID:00008H][MiniMapVersionManager](by-class/MiniMapVersionManager.md)
- [UID:0000XP][0x004563c0-0x00457547.MiniMapVersionManager](by-memory/0x004563c0-0x00457547.MiniMapVersionManager.md)
- [UID:0000XQ][0x004570b0-0x004570e0.MiniMapVersionLookupByMapId](by-memory/0x004570b0-0x004570e0.MiniMapVersionLookupByMapId.md)
- [UID:0000LE][MiniMap](by-file/MiniMap.md)

## Changes

- 2026-05-30: Previously this page had stale `0/0` completion/confidence metadata despite exact storage and class/file research. It now records the exact storage page, lifecycle writes/clears, map-id/version-cache role evidence, naming caveat, and unresolved original-file split. Score changed to `82/84`; confidence is strong for identity/storage but capped by naming uncertainty and the unresolved original file split.

- 2026-06-05 autogen classification:
  - What existed before: autogen metadata was blank, so the singleton was reported as unclassified.
  - Changed to: `RECONSTRUCTABLE:TRUE` with `AUTOGEN_PARENT_UID:0000LF`; `RECONSTRUCTION_CPP CODE` remains empty.
  - Summary/evidence: live IDA MCP `xrefs_to 0x0067a7dc` and decompilation of `0x004563c0`, `0x00456480`, `0x004573c0`, and `0x00457480` prove NexusTK-owned `MiniMapVersionManager` singleton storage owned by [UID:0000LF][MiniMapVersionManager](by-file/MiniMapVersionManager.md). No final C++ body was added because the page is below the 95/95 reconstruction gate.

- 2026-06-06 source-facing cleanup:
  - What existed before: the page still described the singleton with a raw IDA storage label and stale generated-alias caveats in the coverage row.
  - Changed to: score `84/88`, source-facing singleton-slot wording, refreshed live xref/byte evidence, and synced the manual by-global coverage row.
  - Summary/evidence: live IDA MCP again reports the constructor publish, teardown clears, startup/update-check readers, renderer readers, and zero-initialized storage; final declaration spelling remains provisional, so C++ stays blank.
