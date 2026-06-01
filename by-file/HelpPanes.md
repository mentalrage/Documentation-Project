*** UID:0000JU | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:80 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"NexusTK/ui/controls/" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***

# HelpPanes

## Status

- Confidence: strong for tooltip/help-pane source family; medium for exact original split.
- Proposed module folder: `ui/controls/`
- Candidate files: `ui/controls/HelpPanes.cpp`, possibly split with `ui/controls/ItemHelpPane.cpp` and `ui/controls/WillBeChangedPanes.cpp`.
- Current generated sources: `class_HelpPane.cpp`, `class_HelpPane__SimpleHelpTextPartPane.cpp`, `class_SimpleHelpPane.cpp`, `class_SimpleHelpPane2.cpp`, `class_WillBeChangedItemPane.cpp`, `class_WillBeChangedSpellPane.cpp`, and `class_ItemHelpPane.cpp`.
- Evidence basis: `simroot_v2` generated source and IDA MCP boundary/decompile/xref checks on 2026-05-24. Wave3 was not executed for this pass.

## Hypothesis

The help and tooltip panes were likely compiled as one UI support source neighborhood rather than as separate one-class files. The contiguous source-order cluster starts with reusable styled help text, then simple timed help popups, temporary item/spell change-preview panes, and the larger item tooltip pane.

[UID:0000JI][FontStyle](by-file/FontStyle.md) is a neighboring style descriptor used by `HelpPane` style-copy setup. Keep it as a separate support file for now because it is also used by static text callers outside the tooltip cluster.

Likely original grouping:

```text
ui/controls/HelpPanes.cpp
ui/controls/HelpPanes.h
```

Possible later split:

```text
ui/controls/HelpPanes.cpp
ui/controls/ItemHelpPane.cpp
ui/controls/WillBeChangedPanes.cpp
```

The split question should stay open because `ItemHelpPane` is much larger and depends on item metadata, player data, and inventory/equipment panes, while `HelpPane` and `SimpleHelpPane` are generic tooltip infrastructure.

## Proposed Contents

| Entity | Current range | Current file | Role |
| --- | --- | --- | --- |
| [UID:000064][HelpPane__SimpleHelpTextPartPane](by-class/HelpPane__SimpleHelpTextPartPane.md) | `0x004c65a0-0x004c6953`, destructor island `0x004ce3ae`, `0x004ce620` | `class_HelpPane__SimpleHelpTextPartPane.cpp` | Embedded text subpane for styled, outlined, or shadowed help text. |
| [UID:000063][HelpPane](by-class/HelpPane.md) | `0x004c6960-0x004c6ea9`, destructor island `0x004ce34b-0x004ce42b` | `class_HelpPane.cpp` | Styled tooltip base with placement, screen clamping, opacity/fade style, and embedded text part. |
| [UID:00022N][0x004c6eb0-0x004c6f89.HelpPaneFadeStateUpdate](by-memory/0x004c6eb0-0x004c6f89.HelpPaneFadeStateUpdate.md) | `0x004c6eb0-0x004c6f89` | no active function object | Raw help-pane fade/state updater under HelpPanes review; no direct xrefs currently found. |
| [UID:0000D6][SimpleHelpPane](by-class/SimpleHelpPane.md) | `0x004c6f90-0x004c74af`, singleton [UID:0001PC][0x0069ae00-0x0069ae04.g_pSimpleHelpPane](by-memory/0x0069ae00-0x0069ae04.g_pSimpleHelpPane.md), destructor island `0x004ce38d-0x004ce617` | `class_SimpleHelpPane.cpp` | Older/simple timed text tooltip singleton. |
| [UID:0000D7][SimpleHelpPane2](by-class/SimpleHelpPane2.md) | `0x004c74b0-0x004c7680`, factory [UID:00016T][0x004c7680-0x004c77e0.SimpleHelpPane2Factory](by-memory/0x004c7680-0x004c77e0.SimpleHelpPane2Factory.md), helpers [UID:00022O][0x004c77e0-0x004c78db.SimpleHelpPane2FactoryHelpers](by-memory/0x004c77e0-0x004c78db.SimpleHelpPane2FactoryHelpers.md), singleton [UID:0001OY][0x0067a7d4-0x0067a7d8.g_pSimpleHelpPane2](by-memory/0x0067a7d4-0x0067a7d8.g_pSimpleHelpPane2.md), destructor island `0x004ce377-0x004ce55f` | `class_SimpleHelpPane2.cpp`; factory/helpers currently absent from active `.cpp` output | `HelpPane` subclass with anchor rectangle, factory wrappers, anchor/cursor predicate, and auto-hide timer. |
| [UID:0000G5][WillBeChangedItemPane](by-class/WillBeChangedItemPane.md) | `0x004c78e0-0x004c7f8f`, singleton [UID:0001PK][0x0069b414-0x0069b418.g_pWillBeChangedItemPane](by-memory/0x0069b414-0x0069b418.g_pWillBeChangedItemPane.md), destructor island `0x004ce3c4`, `0x004ce670` | `class_WillBeChangedItemPane.cpp` | Temporary item drag/change preview pane. |
| [UID:0000G6][WillBeChangedSpellPane](by-class/WillBeChangedSpellPane.md) | `0x004c7f90-0x004c82cf`, destructor island `0x004ce3da`, `0x004ce6d0` | `class_WillBeChangedSpellPane.cpp` | Temporary spell drag/change preview pane. |
| [UID:00006U][ItemHelpPane](by-class/ItemHelpPane.md) | `0x004c82d0-0x004ce160`, singleton [UID:0001PD][0x0069ae04-0x0069ae08.g_pItemHelpPane](by-memory/0x0069ae04-0x0069ae08.g_pItemHelpPane.md), destructor island `0x004ce361-0x004ce4fb` | `class_ItemHelpPane.cpp` | Rich item tooltip with metadata lookup, stat formatting, price/requirements, and owner/protection lines. |
| help tooltip support helpers | [UID:00022P][0x004ce160-0x004ce34b.HelpTooltipSupportHelpers](by-memory/0x004ce160-0x004ce34b.HelpTooltipSupportHelpers.md) | mixed support, not cleanly emitted | UTF-16 string comparison, vector assign/range copy, and constructor/destructor unwind singleton clear helpers for the help-tooltip family. |
| help singleton close helpers | [UID:000228][0x004a0d40-0x004a0d71.HelpPaneSingletonCloseHelpers](by-memory/0x004a0d40-0x004a0d71.HelpPaneSingletonCloseHelpers.md) | likely file-local helpers; not currently emitted in active HelpPane class output | Close active `g_pItemHelpPane` or `g_pSimpleHelpPane` instances through deleting-destructor slot `0` before replacement/flow changes. |

## Evidence Notes

- IDA MCP confirms the reusable help text part at `0x004c65a0`, `0x004c6630`, and `0x004c6880`.
- IDA MCP confirms `HelpPane` construction at `0x004c6960`, including embedded `HelpPane::SimpleHelpTextPartPane`, style-copy setup, text measurement, screen clamp, and opacity handling.
- IDA MCP confirms `HelpPane::HelpPane` calls `FontStyle::FontStyle` and copies a compatible style record into its embedded style storage.
- `SimpleHelpPane` constructor xrefs are broad across item, inventory, self-look, user-look, status, and menu flows, supporting generic tooltip ownership.
- 2026-05-26 IDA MCP recheck confirms [UID:00016T][0x004c7680-0x004c77e0.SimpleHelpPane2Factory](by-memory/0x004c7680-0x004c77e0.SimpleHelpPane2Factory.md) at `0x004c7680`: it replaces [UID:0000SA][g_pSimpleHelpPane2](by-global/g_pSimpleHelpPane2.md), allocates and constructs a `HelpPane`-derived popup, installs `SimpleHelpPane2` vtables, stores the anchor rectangle, and schedules the auto-hide timer.
- 2026-05-28 IDA MCP raw disassembly confirms [UID:00022O][0x004c77e0-0x004c78db.SimpleHelpPane2FactoryHelpers](by-memory/0x004c77e0-0x004c78db.SimpleHelpPane2FactoryHelpers.md): two forwarding wrappers around the factory and one anchor/cursor predicate body, with no current IDA function objects or direct xrefs.
- 2026-05-28 IDA MCP confirms [UID:00022P][0x004ce160-0x004ce34b.HelpTooltipSupportHelpers](by-memory/0x004ce160-0x004ce34b.HelpTooltipSupportHelpers.md), including the corrected `ItemHelpPaneCore` exclusive end at `0x004ce160`, a string helper called from `ItemHelpPane::PopulateItemData`, a vector helper called from `HelpPane::HelpPane`, and singleton-clear unwind helpers for the help/tooltip classes.
- 2026-05-26 IDA MCP storage checks confirm tooltip singleton globals: [UID:0000S9][g_pSimpleHelpPane](by-global/g_pSimpleHelpPane.md), [UID:0000SA][g_pSimpleHelpPane2](by-global/g_pSimpleHelpPane2.md), [UID:0000R9][g_pItemHelpPane](by-global/g_pItemHelpPane.md), and [UID:0000SS][g_pWillBeChangedItemPane](by-global/g_pWillBeChangedItemPane.md).
- 2026-05-27 IDA MCP confirms [UID:000228][0x004a0d40-0x004a0d71.HelpPaneSingletonCloseHelpers](by-memory/0x004a0d40-0x004a0d71.HelpPaneSingletonCloseHelpers.md): tiny helpers that close [UID:0000R9][g_pItemHelpPane](by-global/g_pItemHelpPane.md) and [UID:0000S9][g_pSimpleHelpPane](by-global/g_pSimpleHelpPane.md) through the first virtual slot with flag `1`.
- `ItemHelpPane` constructor xrefs include inventory/item-menu style callers at `0x004ed957`, `0x0051b383`, `0x0051f7e3`, and `0x00568e84`.
- `WillBeChangedItemPane` is constructed from `0x004ed40f`; `WillBeChangedSpellPane` is constructed from `0x0057df03`.

## Ownership Notes

- `HelpPane__SimpleHelpTextPartPane` is separate from `StaticTextControlPane2__SimpleHelpTextPartPane`. Both draw styled text, but they live in different source neighborhoods and have different parent classes.
- `ItemHelpPane` uses [UID:0000LC][MetaMan](by-file/MetaMan.md) lookup and item/player data; final migration may justify a dedicated `ItemHelpPane.cpp`.
- `WillBeChangedItemPane` and `WillBeChangedSpellPane` are not generic help text panes, but physical locality and temporary overlay behavior make them plausible neighbors in the same tooltip/support source family.
- Do not move `ItemHelpPane::PopulateItemData` helpers into `MetaMan`; the metadata lookups are dependencies, while tooltip text population is item-help presentation code.

## Data Caveats

- Current generated source has base-owner pollution such as `TextButtonExControlPane::~Pane` and stray `BackGroundPane` typedefs in help-pane files.
- `SimpleHelpPane` event methods are rendered through `BulletinSession` owner-offset names. Treat those as decompiler/type pollution until event-handler subobject layout is cleaned.
- Several disabled thunk files omit small bodies even though IDA confirms the thunk starts.
- Active `simroot_v2` `.cpp` output still omits the [UID:00016T][0x004c7680-0x004c77e0.SimpleHelpPane2Factory](by-memory/0x004c7680-0x004c77e0.SimpleHelpPane2Factory.md) and [UID:00022O][0x004c77e0-0x004c78db.SimpleHelpPane2FactoryHelpers](by-memory/0x004c77e0-0x004c78db.SimpleHelpPane2FactoryHelpers.md); generated metadata references the factory from `MiniMapDialog`, but the helper family belongs with tooltip/help overlay code.
- [UID:00022P][0x004ce160-0x004ce34b.HelpTooltipSupportHelpers](by-memory/0x004ce160-0x004ce34b.HelpTooltipSupportHelpers.md) is mixed support: do not hand-port the STL-style helpers unless exact matching requires it, but preserve the singleton-clear behavior when reconstructing constructors/destructors.

## Cross-References

- [UID:000063][HelpPane](by-class/HelpPane.md)
- [UID:000064][HelpPane__SimpleHelpTextPartPane](by-class/HelpPane__SimpleHelpTextPartPane.md)
- [UID:0000D6][SimpleHelpPane](by-class/SimpleHelpPane.md)
- [UID:0000D7][SimpleHelpPane2](by-class/SimpleHelpPane2.md)
- [UID:00006U][ItemHelpPane](by-class/ItemHelpPane.md)
- [UID:0000G5][WillBeChangedItemPane](by-class/WillBeChangedItemPane.md)
- [UID:0000G6][WillBeChangedSpellPane](by-class/WillBeChangedSpellPane.md)
- [UID:00016R][0x004c65a0-0x004c6ea9.HelpPaneCore](by-memory/0x004c65a0-0x004c6ea9.HelpPaneCore.md)
- [UID:00022N][0x004c6eb0-0x004c6f89.HelpPaneFadeStateUpdate](by-memory/0x004c6eb0-0x004c6f89.HelpPaneFadeStateUpdate.md)
- [UID:00016S][0x004c6f90-0x004c7680.SimpleHelpPanes](by-memory/0x004c6f90-0x004c7680.SimpleHelpPanes.md)
- [UID:00016T][0x004c7680-0x004c77e0.SimpleHelpPane2Factory](by-memory/0x004c7680-0x004c77e0.SimpleHelpPane2Factory.md)
- [UID:00022O][0x004c77e0-0x004c78db.SimpleHelpPane2FactoryHelpers](by-memory/0x004c77e0-0x004c78db.SimpleHelpPane2FactoryHelpers.md)
- [UID:000228][0x004a0d40-0x004a0d71.HelpPaneSingletonCloseHelpers](by-memory/0x004a0d40-0x004a0d71.HelpPaneSingletonCloseHelpers.md)
- [UID:00016U][0x004c78e0-0x004c82cf.WillBeChangedPreviewPanes](by-memory/0x004c78e0-0x004c82cf.WillBeChangedPreviewPanes.md)
- [UID:00016V][0x004c82d0-0x004ce160.ItemHelpPaneCore](by-memory/0x004c82d0-0x004ce160.ItemHelpPaneCore.md)
- [UID:00022P][0x004ce160-0x004ce34b.HelpTooltipSupportHelpers](by-memory/0x004ce160-0x004ce34b.HelpTooltipSupportHelpers.md)
- [UID:00016W][0x004ce34b-0x004ce725.HelpTooltipDestructorThunks](by-memory/0x004ce34b-0x004ce725.HelpTooltipDestructorThunks.md)
- [UID:0000S9][g_pSimpleHelpPane](by-global/g_pSimpleHelpPane.md)
- [UID:0000SA][g_pSimpleHelpPane2](by-global/g_pSimpleHelpPane2.md)
- [UID:0000R9][g_pItemHelpPane](by-global/g_pItemHelpPane.md)
- [UID:0000SS][g_pWillBeChangedItemPane](by-global/g_pWillBeChangedItemPane.md)
- [UID:0000LC][MetaMan](by-file/MetaMan.md)
- [UID:0000JI][FontStyle](by-file/FontStyle.md)
- [UID:0000O8][StaticTextControlPane](by-file/StaticTextControlPane.md)

## Changes

- 2026-05-30 completion/confidence scoring:
  - What existed before: `COMPLETION:0` and `CONFIDENCE:0`.
  - Changed to: `COMPLETION:90` and `CONFIDENCE:80`.
  - Summary/evidence: tooltip/help-pane family, text parts, simple help variants, item/changed previews, singleton helpers, factories, support helpers, ownership notes, data caveats, and broad cross-references are documented; confidence is capped by exact original split and mixed support-helper ownership.
- 2026-05-31 projected reconstruction path:
  - What existed before: blank `PROPOSED_RECONSTRUCTION_PATH`.
  - Changed to: `NexusTK/ui/controls/`.
  - Summary/evidence: `by-project-structure/proposed-source-tree.md` lists `ui/controls/HelpPanes.cpp`, and the page's hypothesis groups the tooltip/help overlay classes with reusable UI controls while leaving possible future item/changed-pane splits open.
