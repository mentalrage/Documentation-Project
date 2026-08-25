*** UID:0000SV | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:NONE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:FALSE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

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

2026-06-14 A003 live IDA MCP refresh reconfirmed the concrete draw bodies: `sub_500D70` is `0xa9` / `169` bytes and `sub_500E20` is `0x32d` / `813` bytes (Verified with int_convert.py). `sub_500D70` either calls callback slots `unk_69B3FC`/`unk_69B3EC` for the alternate content path or looks up `L"BDFRAME.EPF"` frame `8` through `sub_4D02F0(dword_67A744, ...)`. `sub_500E20` reads `dword_67A744` once, looks up `BDFRAME.EPF` frames `1,6,3,4,0,2,5,7`, and dispatches each tile through `unk_69B3E8`.

2026-06-14 listing search across `0x005008c0-0x0050114d` found nine `BDFRAME.EPF` push sites: one in `sub_500D70` and eight in `sub_500E20`. `xrefs_to` also confirms `dword_69B3EC` is referenced at `0x00500dcb` from `sub_500D70`; `dword_69B3E8` and `dword_69B3FC` are high-fanout callback slots with broad render users. None of these checks expose a separate `g_uiTileRenderer` storage object.

## Ownership Decision

Do not create a real `UiTileRenderer` singleton or place `g_uiTileRenderer` in `AlertPanes.cpp` from current evidence. The behavior should be modeled as:

- resource selection owned by [UID:0000K2][ImageLib](by-file/ImageLib.md) / [UID:0000N5][ResourceLayoutTable](by-file/ResourceLayoutTable.md) through [UID:0000QU][g_pEPFLib](by-global/g_pEPFLib.md);
- low-level surface/tile blitting owned by [UID:0000OC][Surface](by-file/Surface.md) or the [UID:0000TN][SurfaceRenderCallbackTable](by-global/SurfaceRenderCallbackTable.md);
- [UID:00000Y][BlueAlertPane](by-class/BlueAlertPane.md) as a consumer that selects `BDFRAME.EPF` frame ids and computes border tile positions.

## Score Rationale

- Completion is raised to `86` because the page now records the generated-alias source, ignored-ledger support, exact draw-function boundaries, `BDFRAME.EPF` frame-selection pattern, EPF library dependency, callback-slot dependencies, replacement owners, and the absence of a backing global.
- Confidence is raised to `90` because current IDA decompilation and listing search confirm the renderer behavior is real but the `g_uiTileRenderer` name is not. It remains below final audit because final callback-slot names/types and the exact original helper abstraction, if any, are still unresolved.
- `RECONSTRUCTABLE:FALSE`, `CANONICAL_OWNER:NONE`, and blank emitters remain correct. This page documents an ignored generated alias, not source-level storage to emit.

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
- 2026-06-14 A003 goal2 score pass: raised `82/88` to `86/90`.
  - Evidence: live IDA MCP reconfirmed `sub_500D70` and `sub_500E20` boundaries/decompilation, nine `BDFRAME.EPF` listing hits across the BlueAlertPane core, EPF lookup through `dword_67A744`, and render callback use through `dword_69B3E8`, `dword_69B3EC`, and `dword_69B3FC`.
  - Routing decision: kept non-reconstructable/no-emitter ignored status; no C++ was added because there is no proven source-level `g_uiTileRenderer` global.
