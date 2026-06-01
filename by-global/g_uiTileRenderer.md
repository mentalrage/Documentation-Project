*** UID:0000SV | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:82 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:FALSE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# g_uiTileRenderer

## Status

- Symbol kind: generated Wave3 `global-data` alias; no confirmed backing global.
- Current generated source: `source-3/simroot_v2/class_BlueAlertPane.cpp`
- Disposition: do not migrate as a real source-level singleton yet.
- Ignored alias ledger: [UID:0000PF][-ignored](by-global/-ignored.md)
- Evidence basis: generated `simroot_v2` source and IDA MCP decompile/disassembly of `0x00500d70` and `0x00500e20` on 2026-05-24, with current-state recheck on 2026-05-26.
- Confidence: strong that the current generated name is an alias artifact; medium for final render-callback names.

## Finding

`class_BlueAlertPane.cpp` currently renders `BlueAlertPane::DrawBorderFrame` through a synthesized object-style interface:

```cpp
g_uiTileRenderer->BeginFrame(context);
g_uiTileRenderer->SelectTile(L"BDFRAME.EPF", frame, context);
g_uiTileRenderer->Blit(context, sourceRect, drawPos, 1, 0, 0);
```

IDA does not show a `g_uiTileRenderer` storage load in the corresponding functions. The real `DrawBorderFrame` path loads [UID:0000QU][g_pEPFLib](by-global/g_pEPFLib.md) / `dword_67A744`, initializes a temporary [UID:00004I][EPFTileContext](by-class/EPFTileContext.md), looks up `BDFRAME.EPF` frames through [UID:0000N5][ResourceLayoutTable](by-file/ResourceLayoutTable.md) method `0x004d02f0`, then dispatches drawing through the broad render callback global `dword_69B3E8`.

`BlueAlertPane::DrawContent` follows the same split for frame `8`: it initializes a tile context, resolves the frame through `g_pEPFLib`, and either fills the content area or uses alternate content/draw callbacks.

Current `class_BlueAlertPane.meta_wave3` lists `g_uiTileRenderer` as `global-data` but gives it no memory ranges and marks the record incomplete. Treat it as a callsite-biased generated alias over the surface callback table, not a durable source symbol.

2026-05-31 IDA MCP `py_eval` recheck of `0x00500d70-0x0050114d` confirms the BlueAlertPane draw paths reference `dword_67A744` / EPF library state, literal `BDFRAME.EPF`, and surface callback slots `dword_69B3FC`, `dword_69B3EC`, and `dword_69B3E8`; no backing `g_uiTileRenderer` storage was found.

## Ownership Decision

Do not create a real `UiTileRenderer` singleton or place `g_uiTileRenderer` in `AlertPanes.cpp` from current evidence. The behavior should be modeled as:

- resource selection owned by [UID:0000K2][ImageLib](by-file/ImageLib.md) / [UID:0000N5][ResourceLayoutTable](by-file/ResourceLayoutTable.md) through [UID:0000QU][g_pEPFLib](by-global/g_pEPFLib.md);
- low-level surface/tile blitting owned by [UID:0000OC][Surface](by-file/Surface.md) or the [UID:0000TN][SurfaceRenderCallbackTable](by-global/SurfaceRenderCallbackTable.md);
- [UID:00000Y][BlueAlertPane](by-class/BlueAlertPane.md) as a consumer that selects `BDFRAME.EPF` frame ids and computes border tile positions.

## Open Questions

- Final semantic names and types for `dword_69B3E8`, `dword_69B3EC`, and related render callback globals.
- Whether the original source wrapped resource lookup plus blit callbacks in an inline helper class or whether Wave3 synthesized the object-style renderer entirely from adjacent calls.

## Cross-References

- [UID:00000Y][BlueAlertPane](by-class/BlueAlertPane.md)
- [UID:0001A5][0x005008c0-0x0050114d.BlueAlertPaneCore](by-memory/0x005008c0-0x0050114d.BlueAlertPaneCore.md)
- [UID:0000HE][AlertPanes](by-file/AlertPanes.md)
- [UID:0000QU][g_pEPFLib](by-global/g_pEPFLib.md)
- [UID:0000N5][ResourceLayoutTable](by-file/ResourceLayoutTable.md)
- [UID:00004I][EPFTileContext](by-class/EPFTileContext.md)
- [UID:0000OC][Surface](by-file/Surface.md)
- [UID:0000TN][SurfaceRenderCallbackTable](by-global/SurfaceRenderCallbackTable.md)
- [UID:0001R5][alert-dialog-resources](by-resource/alert-dialog-resources.md)
- [Wave3 data issues](../wave3_data_issues.md)

## Changes

- 2026-05-31 reconstruction classification:
  - What existed before: `COMPLETION:0`, `CONFIDENCE:0`, blank `RECONSTRUCTABLE`, while coverage already treated the item as ignored.
  - Changed to: `COMPLETION:82`, `CONFIDENCE:88`, and `RECONSTRUCTABLE:FALSE`.
  - Summary/evidence: IDA MCP recheck confirms the BlueAlertPane drawing code uses EPF/resource lookup and surface callback slots, not a real `g_uiTileRenderer` global. Keep this page as an alias warning and do not emit reconstructed C++ from it.
