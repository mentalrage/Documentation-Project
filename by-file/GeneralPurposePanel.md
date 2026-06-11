*** UID:0000JQ | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:85 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"NexusTK/ui/panels/" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***

# GeneralPurposePanel

## Status

- Confidence: strong for `GeneralPurposePanel` and `GeneralPurposePanel2` behavior; medium for final folder name.
- Proposed module: `ui/panels/GeneralPurposePanel.cpp`
- Primary classes: `GeneralPurposePanel` and `GeneralPurposePanel2`
- Main address doc: [UID:00015V][0x004b83d0-0x004b8bd3.GeneralPurposePanel](by-memory/0x004b83d0-0x004b8bd3.GeneralPurposePanel.md)

## Role

`GeneralPurposePanel.cpp` owns the in-game general-purpose panel shell that switches between major side-panel pages: self look, user look/profile, inventory, spell inventory, group, collection, and options. `GeneralPurposePanel2` is a smaller alternate shell with one child pane.

## Proposed Contents

| Structure | Address evidence | Role |
| --- | --- | --- |
| `GeneralPurposePanel` | `0x004b83d0-0x004b85e2`, destructor `0x004b8b40` | Constructs the seven-pane in-game panel and clears [UID:0000R0][g_pGeneralPurposePanel](by-global/g_pGeneralPurposePanel.md) on teardown. |
| `GeneralPurposePanel2` | `0x004b8830-0x004b8a7f`, scalar deleting destructor `0x004b8aa0` | Constructs a one-child alternate panel, exposes child lookup, owns [UID:00015Y][0x004b89a0-0x004b8a7f.GeneralPurposePanel2SwitchActiveChild](by-memory/0x004b89a0-0x004b8a7f.GeneralPurposePanel2SwitchActiveChild.md), and clears [UID:0000R1][g_pGeneralPurposePanel2](by-global/g_pGeneralPurposePanel2.md). |
| shared panel tab helpers under review | [UID:00015W][0x004b85f0-0x004b8643.GeneralPurposePanelChildAccessors](by-memory/0x004b85f0-0x004b8643.GeneralPurposePanelChildAccessors.md) | IDA-confirmed child lookup and active tab helpers whose xref locality matches the general-purpose panel shell. The one-child `GeneralPurposePanel2` switch is now attached to the class row above. |
| singleton clear helpers | [UID:00015Z][0x004b8a80-0x004b8a9a.GeneralPurposePanelSingletonClearHelpers](by-memory/0x004b8a80-0x004b8a9a.GeneralPurposePanelSingletonClearHelpers.md) | Tiny global cleanup helpers for nearby panel singletons. |

## Boundaries

- Keep [UID:0000ME][PanelPane](by-file/PanelPane.md) in `ui/core`; it is a reusable base for many panel classes and is constructed by `NewOptionPane`, group panes, and other features.
- Keep `NewOptionPane` in [UID:0000M7][OptionPane](by-file/OptionPane.md); `GeneralPurposePanel` constructs it but does not own option-page internals.
- Keep `UserPane`, `UserLookPane`, inventory, spell inventory, group, and collection panes in their feature files. The general panel shell owns composition and page switching, not the full implementation of every child page.
- Keep [UID:0000PN][FrameChromeSlots](by-global/FrameChromeSlots.md) and [UID:0000YI][0x004615b0-0x00461657.AboveFrameRefreshHelpers](by-memory/0x004615b0-0x00461657.AboveFrameRefreshHelpers.md) with [UID:0000JL][FrameChrome](by-file/FrameChrome.md). `GeneralPurposePanel` calls the refresh pair after switching tabs, but that pair releases/rebuilds frame-chrome pane state.

## Evidence

- IDA confirms `GeneralPurposePanel::GeneralPurposePanel` at `0x004b83d0-0x004b857d`, with callers at `0x004f7ff7` and `0x004f8835`.
- IDA confirms `GeneralPurposePanel2::GeneralPurposePanel2` at `0x004b8830-0x004b88e0`, with caller at `0x004f8020`.
- IDA decompilation of the constructor shows seven owned child pointers in `GeneralPurposePanel`, in index order: `0` self look, `1` user look/profile, `2` inventory, `3` spell inventory, `4` group, `5` collection, and `6` option.
- IDA decompilation of `0x004b85f0`, `0x004b8620`, `0x004b8630`, and `0x004b8650` shows child lookup, active child retrieval, active child refresh, and active tab switching over the same child array.
- IDA xrefs show `0x004b8650` calls [UID:00006O][InterfaceEfxMgr](by-class/InterfaceEfxMgr.md) trigger helper `0x004e9ee0` when switching or refreshing panel tabs in the old interface-effect path.
- IDA MCP confirms the new-layout tab switch path calls [UID:0000YI][0x004615b0-0x00461657.AboveFrameRefreshHelpers](by-memory/0x004615b0-0x00461657.AboveFrameRefreshHelpers.md): `0x004615b0` releases the dynamic `AboveFrame` slot and the adjacent creator rebuilds it into `0x0067a840`.
- 2026-05-25 IDA MCP recheck confirms `0x004b89a0` is a real `GeneralPurposePanel2` one-child switch helper and `0x004b8a80` / `0x004b8a90` are singleton clear helpers for `g_pGeneralPurposePanel2` / `g_pGeneralPurposePanel`.
- 2026-05-25 macro/profile follow-up uses this child index map to resolve [UID:0001V1][MacroHotkeyRecord](by-type/by-struct/MacroHotkeyRecord.md) state labels: index `3` / spell inventory writes state `2` / `.usr` `S`, and index `2` / inventory writes state `3` / `.usr` `I`.
- Batch 118 live IDA `py_eval` rechecked `GeneralPurposePanel2` constructor `0x004b8830-0x004b88e1` and switch helper `0x004b89a0-0x004b8a7f`, including the final `retn 8` byte. The switch helper has one caller at `0x005a771b`, uses the one-child slot initialized by the constructor, and depends on FrameChrome only through the post-switch refresh pair.

## Caveats

The shared child lookup/tab helpers at `0x004b85f0`, `0x004b8620`, `0x004b8630`, and `0x004b8650` need a focused owner review before source migration, but their IDA body and xref locality match the general-purpose panel shell.

The active switch helper at `0x004b89a0-0x004b8a7f` stays with `GeneralPurposePanel2`; reconstruct it as `GeneralPurposePanel2::SwitchActiveChild` or a similarly named one-child tab switch method.

## Cross References

- [UID:00005Q][GeneralPurposePanel](by-class/GeneralPurposePanel.md)
- [UID:00005R][GeneralPurposePanel2](by-class/GeneralPurposePanel2.md)
- [UID:0000ME][PanelPane](by-file/PanelPane.md)
- [UID:0000M7][OptionPane](by-file/OptionPane.md)
- [UID:0000K9][InterfaceEfx](by-file/InterfaceEfx.md)
- [UID:0000JL][FrameChrome](by-file/FrameChrome.md)
- [UID:0000PN][FrameChromeSlots](by-global/FrameChromeSlots.md)
- [UID:0000YI][0x004615b0-0x00461657.AboveFrameRefreshHelpers](by-memory/0x004615b0-0x00461657.AboveFrameRefreshHelpers.md)
- [UID:00015V][0x004b83d0-0x004b8bd3.GeneralPurposePanel](by-memory/0x004b83d0-0x004b8bd3.GeneralPurposePanel.md)
- [UID:00015W][0x004b85f0-0x004b8643.GeneralPurposePanelChildAccessors](by-memory/0x004b85f0-0x004b8643.GeneralPurposePanelChildAccessors.md)
- [UID:00015X][0x004b8650-0x004b8822.GeneralPurposePanelSwitchActiveTab](by-memory/0x004b8650-0x004b8822.GeneralPurposePanelSwitchActiveTab.md)
- [UID:00015Y][0x004b89a0-0x004b8a7f.GeneralPurposePanel2SwitchActiveChild](by-memory/0x004b89a0-0x004b8a7f.GeneralPurposePanel2SwitchActiveChild.md)
- [UID:0000R0][g_pGeneralPurposePanel](by-global/g_pGeneralPurposePanel.md)
- [UID:0000R1][g_pGeneralPurposePanel2](by-global/g_pGeneralPurposePanel2.md)

## Changes

- 2026-06-08 A006 Batch 118 parent-gate repair:
  - Before: `COMPLETION:84`, `CONFIDENCE:80`.
  - Changed to: `COMPLETION:85`, `CONFIDENCE:86`.
  - Summary/evidence: corrected the `GeneralPurposePanel2` switch-helper range to [UID:00015Y][0x004b89a0-0x004b8a7f.GeneralPurposePanel2SwitchActiveChild](by-memory/0x004b89a0-0x004b8a7f.GeneralPurposePanel2SwitchActiveChild.md), moved it from under-review helper status into the `GeneralPurposePanel2` class row, and recorded the fresh IDA boundary/caller/field evidence. Remaining uncertainty is final public method naming and higher-level user-message semantics, not source-file ownership.
- 2026-05-30 completion/confidence scoring:
  - What existed before: `COMPLETION:0` and `CONFIDENCE:0`.
  - Changed to: `COMPLETION:84` and `CONFIDENCE:80`.
  - Summary/evidence: panel shell responsibility, child composition/index map, tab switching helpers, singleton clears, frame-chrome/interface effect boundaries, and ownership caveats are documented; confidence remains below 100 because final folder and helper ownership still need focused review.
- 2026-06-05 reconstruction path classification:
  - What existed before: `PROPOSED_RECONSTRUCTION_PATH` was blank, leaving the file row in error.
  - Changed to: `NexusTK/ui/panels/`.
  - Summary/evidence: `by-project-structure/proposed-source-tree.md` places `GeneralPurposePanel.cpp` under `NexusTK/ui/panels/`, and live IDA MCP xrefs/decompilation confirm `0x004b83d0`, `0x004b8580`, `0x004b8830`, `0x004b88f0`, `0x004b8a80`, `0x004b8a90`, and `0x004b8b40` write/clear the two panel singleton globals in this file's lifecycle island.
