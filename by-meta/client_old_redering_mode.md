*** UID:0001QJ | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:-1 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:-1 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***

# Client Old Rendering Mode

## Status

- Confidence: medium for retained compatibility/legacy render paths; open for the exact product-level mode switch.
- Scope: retained/deprecated lower-color drawing callbacks, legacy EPD UI asset branches, old-status/human-pane layout branches, and compatibility helpers that must not be mistaken for the current RGB565/EPF default path.
- Filename note: this document keeps the existing `redering` spelling so existing links do not break.

## Current Findings

The strongest current evidence for an old or compatibility rendering path is the retained RGB555 helper family. [UID:0000TZ][BlendRgb555_004C0710](by-item/BlendRgb555_004C0710.md) blends 15-bit RGB555 colors and has thirteen callers inside the compatibility render callback neighborhood. The [UID:0000YD][0x0045fa00-0x004604f4.Rgb555565BlitHelpers](by-memory/0x0045fa00-0x004604f4.Rgb555565BlitHelpers.md) adds transparent-shadow, alpha-map, weighted span, and transparent weighted-span RGB555 helpers, with direct callers from the compatibility callback family at `0x004bc090` and `0x004bdf40`. This proves the binary still contains 555-mode drawing code or compatibility helpers even though the currently documented primary surface path is RGB565.

`GrafPort::UpdateRenderRegion` creates RGB565 DirectDraw surfaces, so the active/current path should not be described as RGB555 unless a runtime display-mode switch is proven.

The process-wide [UID:0000TN][SurfaceRenderCallbackTable](by-global/SurfaceRenderCallbackTable.md) now makes the old/current software-render split concrete: the callback slots have a compatibility/RGB555-family side at [UID:00016J][0x004bb8d0-0x004c069e.SoftwareRenderCompatCallbacks](by-memory/0x004bb8d0-0x004c069e.SoftwareRenderCompatCallbacks.md) and an RGB565-family side at [UID:00016L][0x004c0770-0x004c5fde.SoftwareRenderRgb565Callbacks](by-memory/0x004c0770-0x004c5fde.SoftwareRenderRgb565Callbacks.md). IDA xrefs tie representative targets to the surface initializer at `0x00558840`, not to Ranking UI ownership.

[UID:0000JX][HourPane](by-file/HourPane.md) gives a concrete UI-resource old-mode branch: when [UID:0000SW][g_useEpfAssets](by-global/g_useEpfAssets.md) / `byte_66DA97 != 1`, its paint handler at `0x004cf010` loads `TIME.EPD` instead of `TIME.EPF`/`TIME.PAL`. This suggests "old rendering" also includes legacy EPD pane art, not only RGB555 helper code.

[UID:0000K9][InterfaceEfx](by-file/InterfaceEfx.md) adds another old-layout UI-art example: [UID:0000UV][InitializeMainUiGraph_004F7D10](by-item/InitializeMainUiGraph_004F7D10.md) creates `InterfaceEfxMgr` only when `byte_66DA97 != 1`, and that manager spawns `CHREFX.EPD`, `MAGEFX.EPD`, `ITEMEFX.EPD`, `FRMLEFX.EPD`, and `FRMREFX.EPD` effects using `INTEFX.PAD`.

Legacy mode is therefore documented as a set of retained paths, not one fully named option yet:

- RGB555/compatibility software-render callbacks and blend helpers.
- `byte_66DA97 != 1` EPD asset branches for UI panes and interface effects.
- Legacy status and old-human rendering/layout classes such as [UID:0001NR][0x005bda40-0x005bfbc1.OldUserStatusPane](by-memory/0x005bda40-0x005bfbc1.OldUserStatusPane.md) and [UID:0000JY][HumanImageLib](by-file/HumanImageLib.md).

Do not merge this topic into [UID:0001QI][client_new_rendering_mode](by-meta/client_new_rendering_mode.md). The current path owns RGB565 DirectDraw/software surfaces and EPF/current-layout asset use, while this page tracks retained compatibility and legacy branches that still need final activation/reachability proof.

## Evidence Links

- [UID:0000NT][SoftwareBlend16](by-file/SoftwareBlend16.md)
- [UID:0000TZ][BlendRgb555_004C0710](by-item/BlendRgb555_004C0710.md)
- [UID:00016K][0x004c0710-0x004c076d.BlendRgb555](by-memory/0x004c0710-0x004c076d.BlendRgb555.md)
- [UID:0000YD][0x0045fa00-0x004604f4.Rgb555565BlitHelpers](by-memory/0x0045fa00-0x004604f4.Rgb555565BlitHelpers.md)
- [UID:00016J][0x004bb8d0-0x004c069e.SoftwareRenderCompatCallbacks](by-memory/0x004bb8d0-0x004c069e.SoftwareRenderCompatCallbacks.md)
- [UID:00016L][0x004c0770-0x004c5fde.SoftwareRenderRgb565Callbacks](by-memory/0x004c0770-0x004c5fde.SoftwareRenderRgb565Callbacks.md)
- [UID:0000TN][SurfaceRenderCallbackTable](by-global/SurfaceRenderCallbackTable.md)
- [UID:0000SW][g_useEpfAssets](by-global/g_useEpfAssets.md)
- [UID:0000JR][GrafPort](by-file/GrafPort.md)
- [UID:0001RC][hourpane-time-resources](by-resource/hourpane-time-resources.md)
- [UID:0001RE][interface-efx-resources](by-resource/interface-efx-resources.md)
- [UID:0001NR][0x005bda40-0x005bfbc1.OldUserStatusPane](by-memory/0x005bda40-0x005bfbc1.OldUserStatusPane.md)
- [UID:0000JY][HumanImageLib](by-file/HumanImageLib.md)

## Open Questions

- Find the mode-selection setting or startup branch that decides between 555 and 565 drawing, if it still exists.
- Determine whether "old rendering" means lower resolution assets, 15-bit color mode, old human sprite composition, or a combination of these.
- Find whether runtime mode selection can still activate the RGB555 compatibility callback family, or whether it is retained but unused fallback code.
- Decide whether the existing misspelled filename should be replaced by a correctly spelled wrapper/redirect file after all inbound links are updated.
