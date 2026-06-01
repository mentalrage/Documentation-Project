*** UID:0000ME | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:78 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***

# PanelPane

## Status

- Confidence: strong for base behavior; medium for whether original source was a standalone file or part of `Pane.cpp`.
- Proposed module: `ui/core/PanelPane.cpp`
- Current recovered source: `class_PanelPane.cpp`
- Main address doc: [UID:0001EC][0x00545090-0x00545165.PanelPane](by-memory/0x00545090-0x00545165.PanelPane.md)
- Type docs: [UID:0001YD][PanelPaneVtables](by-type/by-vtable/PanelPaneVtables.md)
- Evidence basis: `simroot_v2` generated source plus IDA MCP lookup/caller/xref checks through 2026-05-24.

## Role

`PanelPane` is a reusable `Pane`-derived base for panel-style UI containers. It installs a three-vtable layout used by derived panels such as `NewOptionPane`, group panes, and other in-game panel surfaces.

## Proposed Contents

| Structure | Address evidence | Role |
| --- | --- | --- |
| `PanelPane` | `0x00545090-0x00545165` | Base constructor, destructor, and scalar deleting destructor. |
| vtable family | `0x00621a70`, `0x00621ac0`, `0x00621af0` | Three `PanelPane` vtable views installed at object offsets `+0x00`, `+0xa0`, and `+0xa4`. |
| adjustor thunk helpers | `0x005450ef`, `0x005450fa` | Tiny IDA-confirmed functions that forward into the deleting destructor island; compiler-generated and not handwritten source. |

## Observed Derived Constructor Callers

IDA MCP caller checks show `PanelPane::PanelPane` at `0x00545090` has direct constructor calls from these panel families:

| Caller address | Current owner | Source-module implication |
| --- | --- | --- |
| `0x004ea15b` | `InventoryPane` | Item inventory panel family; keep in [UID:0000KA][InventoryPane](by-file/InventoryPane.md). |
| `0x004eb44b` | `NewInventoryPane` | New item inventory panel; keep in [UID:0000LS][NewInventoryPane](by-file/NewInventoryPane.md). |
| `0x0053ffbd` | `NewOptionPane` | Options UI panel; keep in [UID:0000M7][OptionPane](by-file/OptionPane.md). |
| `0x0056563b` | `SelfLookPane` | Self-look/status panel; keep in [UID:0000NL][SelfLookPane](by-file/SelfLookPane.md). |
| `0x0056c4ec`, `0x0056c79c`, `0x0056ca4b` | `GroupPane`, `GroupPane2`, `NewGroupPane` | Group/social panel family; keep in [UID:0000JS][Group](by-file/Group.md). |
| `0x0056e96b` | `CollectionPane` | Collection UI; keep in [UID:0000IC][CollectionPane](by-file/CollectionPane.md). |
| `0x0056feab` | `SelfLookPane2` | Compact self-look panel; keep in [UID:0000NL][SelfLookPane](by-file/SelfLookPane.md). |
| `0x0057c2fb` | `SpellInventoryPane` | Spell inventory panel; keep in [UID:0000O1][SpellInventoryPane](by-file/SpellInventoryPane.md). |
| `0x0057cf9b` | `NewSpellInventoryPane` | New spell inventory panel; keep in [UID:0000LU][NewSpellInventoryPane](by-file/NewSpellInventoryPane.md). |
| `0x0058859c` | `NewSystemMessagePane` | New system-message panel wrapper; keep in [UID:0000OE][SystemMessagePanes](by-file/SystemMessagePanes.md). |
| `0x0059f28c` | `UserLookPane` | Remote user-look/profile panel; keep in [UID:0000P0][UserLookPane](by-file/UserLookPane.md). |

This fan-in supports `PanelPane` as a core UI base class, not a feature-owned helper.

## Boundaries

- Keep `PanelPane` near `Pane`, `DialogPane`, and `ControlPane` under `ui/core`.
- Keep feature panels such as [UID:0000JQ][GeneralPurposePanel](by-file/GeneralPurposePanel.md), [UID:0000M7][OptionPane](by-file/OptionPane.md), group panes, and status panes in their feature modules.

## Caveats

The generated `PanelPane::~PanelPane` body currently calls `TextButtonExControlPane::~TextButtonExControlPane`, even though constructor evidence flows through `Pane::Pane(this, 1)`. Treat that destructor owner name as inherited base-owner pollution until teardown ownership is cleaned.

Disabled generated output lists `0x005450ef` as missing code, but IDA recognizes it as an 0xb-byte adjustor thunk with vtable data xref at `0x00621ac0`. See [UID:0001ED][0x005450ef-0x00545104.PanelPaneAdjustorThunks](by-memory/0x005450ef-0x00545104.PanelPaneAdjustorThunks.md).

## Cross References

- [UID:0000A4][PanelPane](by-class/PanelPane.md)
- [UID:0001YD][PanelPaneVtables](by-type/by-vtable/PanelPaneVtables.md)
- [UID:0001ED][0x005450ef-0x00545104.PanelPaneAdjustorThunks](by-memory/0x005450ef-0x00545104.PanelPaneAdjustorThunks.md)
- [UID:0000MC][Pane](by-file/Pane.md)
- [UID:0000JQ][GeneralPurposePanel](by-file/GeneralPurposePanel.md)
- [UID:0000KA][InventoryPane](by-file/InventoryPane.md)
- [UID:0000M7][OptionPane](by-file/OptionPane.md)
- [UID:0000JS][Group](by-file/Group.md)
- [UID:0000IC][CollectionPane](by-file/CollectionPane.md)
- [UID:0000NL][SelfLookPane](by-file/SelfLookPane.md)
- [UID:0000O1][SpellInventoryPane](by-file/SpellInventoryPane.md)
- [UID:0000OE][SystemMessagePanes](by-file/SystemMessagePanes.md)
- [UID:0000P0][UserLookPane](by-file/UserLookPane.md)
- [UID:0001EC][0x00545090-0x00545165.PanelPane](by-memory/0x00545090-0x00545165.PanelPane.md)

## Changes

- Before: the `PanelPane` memory page ended at `0x00545164`.
- Changed to: the page ends at `0x00545165`.
- Summary/evidence: 2026-05-28 IDA MCP byte/function review shows `0x00545164` is the final operand byte of the `retn 4` in the scalar deleting destructor; `0x00545165-0x00545170` is alignment padding.

- Before: completion/confidence were ungraded at `0/0`.
- Changed to: completion `84`, confidence `78`.
- Summary/evidence: the page documents base behavior, vtable family, derived constructor callers, boundaries, generated destructor caveat, range correction, and cross-references; confidence remains capped by uncertainty over standalone file versus `Pane.cpp` grouping.
