*** UID:00008F | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:76 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:80 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# MiniMapRenderer

## Status

- Confidence: strong for embedded-runtime role and method starts; medium for exact helper ownership in the surrounding runtime-support gap.
- Likely source file: [UID:0000LE][MiniMap](by-file/MiniMap.md), probably `map/MiniMapRenderer.cpp` or a combined `map/MiniMap.cpp`.
- Current recovered file: `source-3/simroot_v2/class_MiniMapRenderer.cpp`
- Main memory doc: [UID:0000XO][0x00453df0-0x004563b5.MiniMapRendererAndControls](by-memory/0x00453df0-0x004563b5.MiniMapRendererAndControls.md)

## Class Purpose

`MiniMapRenderer` is the embedded runtime object used by [UID:00008C][MiniMapDialog](by-class/MiniMapDialog.md) at offset `+0x1cc`. It owns the active map code/path buffers, tile context, loaded minimap document path, normalized view coordinates, symbol-view vector, label-view vector, and cached title text used by the dialog render/timer path.

## Methods

| Address | Method | Role |
| --- | --- | --- |
| `0x00453f50-0x00454008` | constructor | Clears path/code buffers, initializes tile context state, and clears view/vector state. |
| `0x00454010-0x00454070` | destructor | Destroys tile context and frees renderer-owned symbol/label/view buffers. |
| `0x00454080-0x00454087` | `GetMapCodeBuffer` | Returns the short map-code buffer used for `.mnm` naming. |
| `0x00454090-0x00454094` | `GetMapPathBuffer` | Returns the full cached `.mnm` path buffer. |
| `0x00454150-0x004543ec` | `PrepareMapFileAndCheckVersion` | Formats map code/path under `NexusTK\MiniMapImages`, ensures the directory, and checks the cached file version. |
| `0x004543f0-0x00454bac` | `BuildSymbolViews` | Parses the loaded `.mnm` document, rebuilds symbol/label views, keyed lookup data, title text, and normalized view offsets. |
| `0x00454d80-0x00454e2f` | `HasCurrentVersion` | Opens the current `.mnm` file and compares its stored version header against [UID:00008H][MiniMapVersionManager](by-class/MiniMapVersionManager.md) state. |

## Boundary Caveats

- The support helpers called by `BuildSymbolViews`, such as vector insertion/growth helpers and `MiniMapFileLoader` helpers around `0x004550d0-0x00455b40` and `0x00457620-0x00457850`, should not automatically become `MiniMapRenderer` methods. They are renderer-local candidates, but some have generic collection/string behavior and need a focused ownership pass.
- `dword_67A7DC` in the generated renderer output is the minimap version-manager singleton candidate used for expected-version lookup. Keep it with [UID:00008H][MiniMapVersionManager](by-class/MiniMapVersionManager.md), not the renderer.
- `0x004570b0` is the manager-owned lookup helper used by `PrepareMapFileAndCheckVersion` and `HasCurrentVersion`; see [UID:0000XQ][0x004570b0-0x004570e0.MiniMapVersionLookupByMapId](by-memory/0x004570b0-0x004570e0.MiniMapVersionLookupByMapId.md).

## Cross-References

- [UID:0000LE][MiniMap](by-file/MiniMap.md)
- [UID:00008C][MiniMapDialog](by-class/MiniMapDialog.md)
- [UID:00008H][MiniMapVersionManager](by-class/MiniMapVersionManager.md)
- [UID:0000XQ][0x004570b0-0x004570e0.MiniMapVersionLookupByMapId](by-memory/0x004570b0-0x004570e0.MiniMapVersionLookupByMapId.md)
- [UID:0000XO][0x00453df0-0x004563b5.MiniMapRendererAndControls](by-memory/0x00453df0-0x004563b5.MiniMapRendererAndControls.md)
- [UID:0000IP][DATIndexVector](by-file/DATIndexVector.md)

## Changes

- 2026-05-30: Grading changed from `0/0` to `76/80`.
  - Before: page documented the embedded renderer role and methods but remained unevaluated by the completion/confidence header.
  - After: score reflects documented renderer purpose, method ranges, `.mnm` path/version workflow, symbol-view rebuild responsibility, version-manager dependency, and helper-ownership caveats.
  - Evidence: linked memory page [UID:0000XO][0x00453df0-0x004563b5.MiniMapRendererAndControls](by-memory/0x00453df0-0x004563b5.MiniMapRendererAndControls.md) records IDA-confirmed starts, construction from [UID:00008C][MiniMapDialog](by-class/MiniMapDialog.md), `.mnm` parsing callees, and manager-owned lookup calls.
