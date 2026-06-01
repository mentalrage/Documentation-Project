*** UID:00007P | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:76 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:78 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# MapNamePane

## Status

- Confidence: strong for behavior, medium for final file split.
- Likely source file: [UID:0000L2][MapNamePane](by-file/MapNamePane.md), or private code in [UID:0000L3][MapPane](by-file/MapPane.md)
- Address range: [UID:0001AL][0x005031f0-0x0050395f.MapNameAndMiniMapButtonPanes](by-memory/0x005031f0-0x0050395f.MapNameAndMiniMapButtonPanes.md)
- Current recovered file: `source-3/simroot_v2/class_MapNamePane.cpp`

## Class Purpose

`MapNamePane` is a small UI pane that displays the current map name. It initializes map-name archive/font resources, draws centered map-name text, and releases those resources during pane teardown.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| `MapNamePane` | `0x005031f0-0x005032c2` | Initializes pane state, map-name archive storage, and optional font resources. |
| `~MapNamePane` | `0x005032d0-0x0050334c` | Releases resources and clears global pane state. |
| `RenderMapName` | `0x00503350-0x0050349e` | Builds and draws centered map-name text using resource-backed or fallback rendering. |
| adjustor thunks | `0x0050380b`, `0x00503816` | Compiler/vtable thunks; not source-level logic. |
| `ScalarDeletingDestructor` | `0x00503840-0x005038fd` | Runs destructor logic and conditionally frees storage. |

## Evidence Notes

- IDA MCP confirms all listed starts as real functions.
- The constructor is called from the broader UI/game setup path around `0x004f7d10`.
- The local address island is interleaved with [UID:00008B][MiniMapButtonPane](by-class/MiniMapButtonPane.md) beginning at `0x00503580`; do not migrate the older MapName-only aggregate span as a contiguous class range.
- Do not treat the adjustor thunks as separate original methods.

## Cross-References

- [UID:0000L3][MapPane](by-file/MapPane.md)
- [UID:0000L2][MapNamePane](by-file/MapNamePane.md)
- [UID:0001AL][0x005031f0-0x0050395f.MapNameAndMiniMapButtonPanes](by-memory/0x005031f0-0x0050395f.MapNameAndMiniMapButtonPanes.md)
- [UID:0001AK][0x005031f0-0x005038fd.MapNamePane](by-memory/0x005031f0-0x005038fd.MapNamePane.md)

## Changes

- 2026-05-28: Updated the shared memory-island reference from `0x005031f0-0x0050395e` to `0x005031f0-0x0050395f`. Evidence: IDA MCP reports the interleaved `MiniMapButtonPane` destructor ending at `0x0050395f`; the previous boundary omitted the final `retn 4` immediate byte.
- Completion/confidence score update: existed before as `0/0`; changed to `76/78`. Summary: the small map-name UI pane has clear behavior, constructor/destructor/render method coverage, shared island caveat, and thunk exclusion notes, but final file split and exhaustive field/resource details remain incomplete. Evidence: linked `MapNameAndMiniMapButtonPanes` and `MapNamePane` memory pages, IDA-confirmed starts, UI setup caller, and documented interleaving with `MiniMapButtonPane`.
