*** UID:0002XC | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000L2 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# g_pMapNamePane

## Status

- Address: `0x0069b4b4` (`dword_69B4B4` in IDA).
- Type: `MapNamePane *`.
- Owner file: [UID:0000L2][MapNamePane](by-file/MapNamePane.md), or final private helper placement under [UID:0000L3][MapPane](by-file/MapPane.md) if the map UI split is folded later.
- Disposition: reconstructable NexusTK singleton global.
- Rebuild handling: `source-declared/generated-binary`.

## Role

`g_pMapNamePane` stores the active map-name overlay pane. It is written by `MapNamePane` construction, cleared by destructor/helper paths, and read by a map-side helper that needs the live pane/global while updating map UI state.

## Evidence

- IDA MCP `py_eval` on 2026-06-07 reports `0x0069b4b4-0x0069b4b8` as a four-byte item named `dword_69B4B4`, bytes `ff ff ff ff`, initialized dword `0xffffffff`, with six xrefs.
- Xrefs are constructor publish/fallback writes `0x0050323b` and `0x00503242`, destructor clear `0x0050332e`, singleton helper clear `0x005037f0`, scalar deleting destructor clear `0x005038a5`, and external map-side reader `0x00504a43`.
- [UID:0000L2][MapNamePane](by-file/MapNamePane.md) and [UID:00007P][MapNamePane](by-class/MapNamePane.md) document the map-name pane construction, resource setup, vtables, update handler, and source placement.
- The exact storage split is [UID:0002XD][0x0069b4b4-0x0069b4b8.g_pMapNamePane](by-memory/0x0069b4b4-0x0069b4b8.g_pMapNamePane.md).

## Ownership Decision

Use `g_pMapNamePane` as the canonical documentation name for the `dword_69B4B4` slot. Keep the declaration with the map-name/map UI source owner, not with the adjacent MiniMapButtonPane or game-server object table globals.

## Cross-References

- [UID:0000L2][MapNamePane](by-file/MapNamePane.md)
- [UID:00007P][MapNamePane](by-class/MapNamePane.md)
- [UID:0001AL][0x005031f0-0x0050395f.MapNameAndMiniMapButtonPanes](by-memory/0x005031f0-0x0050395f.MapNameAndMiniMapButtonPanes.md)
- [UID:0001AK][0x005031f0-0x005038fd.MapNamePane](by-memory/0x005031f0-0x005038fd.MapNamePane.md)
- [UID:00029X][0x0069b4b4-0x0069b4c8.MapNameMiniMapAndGameServerGlobals](by-memory/0x0069b4b4-0x0069b4c8.MapNameMiniMapAndGameServerGlobals.md)

## Changes

- 2026-06-07 Batch 043: Created canonical global page for the exact `0x0069b4b4` singleton slot. Evidence: live IDA MCP confirmed the item bounds, initial value, six xrefs, and direct ownership by `MapNamePane` constructor/destructor/helper paths.
