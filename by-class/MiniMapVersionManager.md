*** UID:00008H | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:82 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# MiniMapVersionManager

## Status

- Confidence: strong for class responsibility and map-module placement
- Likely source module: [UID:0000LF][MiniMapVersionManager](by-file/MiniMapVersionManager.md), under the broader [UID:0000LE][MiniMap](by-file/MiniMap.md) subsystem
- Current file: `class_MiniMapVersionManager.cpp`
- Current range: `0x004563c0-0x00457547`
- Evidence basis: Wave2 readonly JSON, `simroot_v2\class_MiniMapVersionManager.meta_wave3`, prior report notes, and IDA MCP caller/lookup checks on 2026-05-22.
- Singleton storage: [UID:0000RP][g_pMiniMapVersionManager](by-global/g_pMiniMapVersionManager.md) at [UID:0001OZ][0x0067a7dc-0x0067a7e0.g_pMiniMapVersionManager](by-memory/0x0067a7dc-0x0067a7e0.g_pMiniMapVersionManager.md)

## Responsibility

`MiniMapVersionManager` owns the minimap hash/version list used by startup update checks and local minimap cache validation. It initializes during process startup, stores the current minimap hash version string, loads persisted hash data, merges downloaded hash-list text, and rewrites the local hash cache when requested.

## Methods

| Address | Current name | Summary |
| --- | --- | --- |
| `0x004563c0` | constructor | Initializes the singleton and internal version-list storage. |
| `0x00456480` | destructor | Releases minimap version-list data and clears the global manager pointer. |
| `0x00456540` | `LoadHashFile` inferred | Loads persisted minimap hash cache from app data and forwards decoded version/list text into `UpdateHashList`. |
| [UID:0002JL][0x00456a90-0x0045709e.MiniMapVersionManagerUpdateHashList](by-memory/0x00456a90-0x0045709e.MiniMapVersionManagerUpdateHashList.md) | `UpdateHashList` inferred | Updates the current hash version, optionally rewrites `mnmhs.hs`, and merges slash-delimited hash entries into the owned cache. |
| [UID:0002JM][0x004570a0-0x004570a4.MiniMapVersionManagerGetVersionString](by-memory/0x004570a0-0x004570a4.MiniMapVersionManagerGetVersionString.md) | `GetVersionString` inferred | Returns the manager-owned wide string buffer storing the current minimap hash version. |
| `0x004570b0` | `GetExpectedVersionForMapId` inferred | Looks up a map id in the `DATIndexVector` hash index and returns the stored expected `.mnm` header/version string. |
| `0x00457480` | scalar deleting destructor | Invokes destructor and conditionally frees the object. |

## IDA MCP Evidence

- `lookup_funcs` confirms:
  - `0x004563c0` size `0xbd`
  - `0x00456480` size `0xb2`
  - `0x00456540` size `0x1be`
  - `0x00456a90` size `0x60e`
  - `0x004570a0` size `0x4`
  - `0x00457480` size `0xc7`
- `callers` confirms:
  - `0x004563c0` is called from `_WinMain@16` at `0x004f5d04`.
  - `0x004570a0` is called from `StartupWindow__RunUpdateCheck` at `0x00580ea3`.
- 2026-05-25 `callers` confirms `0x004570b0` is used by `MiniMapRenderer::PrepareMapFileAndCheckVersion` and `MiniMapRenderer::HasCurrentVersion`.
- 2026-05-26 IDA MCP reconfirms these boundaries and callers. IDA decompilation identifies singleton storage as `dword_67A7DC`; `xrefs_to 0x0067a7dc` ties it to the manager lifetime helpers, startup, update-check code, and renderer version checks.
- `callees` for `0x004563c0` include internal helpers at `0x00457550` and `0x00423b00`, consistent with storage/list initialization.
- 2026-05-24 IDA MCP caller checks show `0x00456a90` calls [UID:0000XS][0x00457100-0x0045730e.DATIndexVectorInsertNode](by-memory/0x00457100-0x0045730e.DATIndexVectorInsertNode.md), and construction/teardown paths call `DATIndexVector` storage helpers.
- 2026-05-25 IDA MCP checks place `0x00457550`, `0x004570e0`, and `0x00457430` in the shared [UID:0000KR][LinkedList](by-file/LinkedList.md) helper family rather than minimap-owned source.

## Ownership Notes

- This class belongs with minimap code rather than generic startup code. Startup constructs/uses it, but the owned data is minimap hash/version state.
- `StartupWindow::RunUpdateCheck` depends on the current version string, so `StartupWindow` should include/use the minimap version manager rather than owning the manager implementation.
- The persisted hash path and format should be documented separately when the `.hs` file parser/writer is fully reviewed.
- `DATIndexVector` is a dependency of the minimap hash-list storage, not owned by `MiniMapVersionManager`.
- `LinkedList` is a lower-level utility dependency for sentinel nodes and two-word payload nodes, not minimap-specific code.
- Active `simroot_v2` output currently omits `0x004570b0`; use [UID:0000XQ][0x004570b0-0x004570e0.MiniMapVersionLookupByMapId](by-memory/0x004570b0-0x004570e0.MiniMapVersionLookupByMapId.md) for that method until generated ownership is fixed.

## Open Questions

- Confirm final method names in Wave3 metadata for `0x00456540`, `0x00456a90`, `0x004570a0`, and `0x004570b0`.
- Confirm whether the original file was `MiniMapVersionManager.cpp` or part of a larger `MiniMap.cpp`.
- Build a by-memory page for `0x00456a90-0x0045709e` if the hash-list merge algorithm is researched in detail.

## Cross-References

- [UID:0000LF][MiniMapVersionManager](by-file/MiniMapVersionManager.md)
- [UID:0000LE][MiniMap](by-file/MiniMap.md)
- [UID:0000XQ][0x004570b0-0x004570e0.MiniMapVersionLookupByMapId](by-memory/0x004570b0-0x004570e0.MiniMapVersionLookupByMapId.md)
- [UID:0001V8][MiniMapVersionNode](by-type/by-struct/MiniMapVersionNode.md)
- [UID:0000RP][g_pMiniMapVersionManager](by-global/g_pMiniMapVersionManager.md)
- [UID:0001OZ][0x0067a7dc-0x0067a7e0.g_pMiniMapVersionManager](by-memory/0x0067a7dc-0x0067a7e0.g_pMiniMapVersionManager.md)
- [UID:00003K][DATIndexVector](by-class/DATIndexVector.md)
- [UID:0000KR][LinkedList](by-file/LinkedList.md)
- [UID:0001R1][proposed-source-tree](by-project-structure/proposed-source-tree.md)

## Changes

- 2026-05-27: Updated current class range from `0x004563c0-0x00457546` to `0x004563c0-0x00457547`. Evidence: IDA MCP reports the scalar deleting destructor `sub_457480` ending at `0x00457547`; the previous range omitted the final `retn 4` immediate byte.
- Completion/confidence score update: existed before as `0/0`; changed to `84/82`. Summary: the minimap hash/version manager has detailed singleton, startup, persisted hash cache, version lookup, dependency, method-boundary, caller, and ownership documentation, but final method names and exact original source split still remain open. Evidence: IDA lookup/caller confirmations, `g_pMiniMapVersionManager`, version lookup by map id, `DATIndexVector` and `LinkedList` dependency notes, and active simroot omission of `0x004570b0`.
- 2026-05-31: Marked `RECONSTRUCTABLE:TRUE` and replaced raw `UpdateHashList`/`GetVersionString` address rows with exact by-memory child references. Evidence: IDA MCP rechecked both methods and the exact child pages now carry the current behavior evidence.
