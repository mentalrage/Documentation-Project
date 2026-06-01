*** UID:0000JQ | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:80 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***

# GeneralPurposePanel

## Status

- Confidence: strong for `GeneralPurposePanel` and `GeneralPurposePanel2` behavior; medium for final folder name.
- Proposed module: `ui/panels/GeneralPurposePanel.cpp`
- Current recovered sources: `class_GeneralPurposePanel.cpp` and `class_GeneralPurposePanel2.cpp`
- Main address doc: [UID:00015V][0x004b83d0-0x004b8bd3.GeneralPurposePanel](by-memory/0x004b83d0-0x004b8bd3.GeneralPurposePanel.md)

## Role

`GeneralPurposePanel.cpp` owns the in-game general-purpose panel shell that switches between major side-panel pages: self look, user look/profile, inventory, spell inventory, group, collection, and options. `GeneralPurposePanel2` is a smaller alternate shell with one child pane.

## Proposed Contents

| Structure | Address evidence | Role |
| --- | --- | --- |
| `GeneralPurposePanel` | `0x004b83d0-0x004b85e2`, destructor `0x004b8b40` | Constructs the seven-pane in-game panel and clears [UID:0000R0][g_pGeneralPurposePanel](by-global/g_pGeneralPurposePanel.md) on teardown. |
| `GeneralPurposePanel2` | `0x004b8830-0x004b8968`, destructor `0x004b8aa0` | Constructs a one-child alternate panel, exposes child lookup, and clears [UID:0000R1][g_pGeneralPurposePanel2](by-global/g_pGeneralPurposePanel2.md). |
| shared panel tab helpers under review | [UID:00015W][0x004b85f0-0x004b8643.GeneralPurposePanelChildAccessors](by-memory/0x004b85f0-0x004b8643.GeneralPurposePanelChildAccessors.md), [UID:00015Y][0x004b89a0-0x004b8a7e.GeneralPurposePanel2SwitchActiveChild](by-memory/0x004b89a0-0x004b8a7e.GeneralPurposePanel2SwitchActiveChild.md) | IDA-confirmed child lookup/active tab/switch helpers currently owned by `SpellOneArgInputPane` or omitted in Wave3. |
| singleton clear helpers | [UID:00015Z][0x004b8a80-0x004b8a9a.GeneralPurposePanelSingletonClearHelpers](by-memory/0x004b8a80-0x004b8a9a.GeneralPurposePanelSingletonClearHelpers.md) | Tiny global cleanup helpers for nearby panel singletons. |

## Boundaries

- Keep [UID:0000ME][PanelPane](by-file/PanelPane.md) in `ui/core`; it is a reusable base for many panel classes and is constructed by `NewOptionPane`, group panes, and other features.
- Keep `NewOptionPane` in [UID:0000M7][OptionPane](by-file/OptionPane.md); `GeneralPurposePanel` constructs it but does not own option-page internals.
- Keep `UserPane`, `UserLookPane`, inventory, spell inventory, group, and collection panes in their feature files. The general panel shell owns composition and page switching, not the full implementation of every child page.
- Keep [UID:0000PN][FrameChromeSlots](by-global/FrameChromeSlots.md) and [UID:0000YI][0x004615b0-0x00461657.AboveFrameRefreshHelpers](by-memory/0x004615b0-0x00461657.AboveFrameRefreshHelpers.md) with [UID:0000JL][FrameChrome](by-file/FrameChrome.md). `GeneralPurposePanel` calls the refresh pair after switching tabs, but that pair releases/rebuilds frame-chrome pane state.

## Evidence

- Wave3 reports `GeneralPurposePanel` grade `98.3` and `GeneralPurposePanel2` grade `98.0`.
- IDA confirms `GeneralPurposePanel::GeneralPurposePanel` at `0x004b83d0-0x004b857d`, with callers at `0x004f7ff7` and `0x004f8835`.
- IDA confirms `GeneralPurposePanel2::GeneralPurposePanel2` at `0x004b8830-0x004b88e0`, with caller at `0x004f8020`.
- Generated constructor code shows seven owned child pointers in `GeneralPurposePanel`, in index order: `0` self look, `1` user look/profile, `2` inventory, `3` spell inventory, `4` group, `5` collection, and `6` option.
- IDA decompilation of `0x004b85f0`, `0x004b8620`, `0x004b8630`, and `0x004b8650` shows child lookup, active child retrieval, active child refresh, and active tab switching over the same child array.
- IDA xrefs show `0x004b8650` calls [UID:00006O][InterfaceEfxMgr](by-class/InterfaceEfxMgr.md) trigger helper `0x004e9ee0` when switching or refreshing panel tabs in the old interface-effect path.
- IDA MCP confirms the new-layout tab switch path calls [UID:0000YI][0x004615b0-0x00461657.AboveFrameRefreshHelpers](by-memory/0x004615b0-0x00461657.AboveFrameRefreshHelpers.md): `0x004615b0` releases the dynamic `AboveFrame` slot and the adjacent creator rebuilds it into `0x0067a840`.
- 2026-05-25 IDA MCP recheck confirms `0x004b89a0` is a real `GeneralPurposePanel2` one-child switch helper and `0x004b8a80` / `0x004b8a90` are singleton clear helpers for `g_pGeneralPurposePanel2` / `g_pGeneralPurposePanel`.
- 2026-05-25 macro/profile follow-up uses this child index map to resolve [UID:0001V1][MacroHotkeyRecord](by-type/by-struct/MacroHotkeyRecord.md) state labels: index `3` / spell inventory writes state `2` / `.usr` `S`, and index `2` / inventory writes state `3` / `.usr` `I`.

## Caveats

Wave3 currently owns the shared child lookup/tab helpers at `0x004b85f0`, `0x004b8620`, `0x004b8630`, and `0x004b8650` as `SpellOneArgInputPane`, even though their IDA body and xref locality match the general-purpose panel shell. Do not migrate those helpers with spell input code without a focused owner review.

Current generated `class_GeneralPurposePanel2.cpp` also omits the active switch helper at `0x004b89a0`; reconstruct it as `GeneralPurposePanel2::SwitchActiveChild` or a similarly named one-child tab switch method.

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
- [UID:00015Y][0x004b89a0-0x004b8a7e.GeneralPurposePanel2SwitchActiveChild](by-memory/0x004b89a0-0x004b8a7e.GeneralPurposePanel2SwitchActiveChild.md)
- [UID:0000R0][g_pGeneralPurposePanel](by-global/g_pGeneralPurposePanel.md)
- [UID:0000R1][g_pGeneralPurposePanel2](by-global/g_pGeneralPurposePanel2.md)

## Changes

- 2026-05-30 completion/confidence scoring:
  - What existed before: `COMPLETION:0` and `CONFIDENCE:0`.
  - Changed to: `COMPLETION:84` and `CONFIDENCE:80`.
  - Summary/evidence: panel shell responsibility, child composition/index map, tab switching helpers, singleton clears, frame-chrome/interface effect boundaries, and Wave3 ownership caveats are documented; confidence remains below 100 because final folder and helper ownership still need focused review.
