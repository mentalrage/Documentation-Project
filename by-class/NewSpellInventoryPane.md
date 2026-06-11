*** UID:00009A | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:80 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000LU | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# NewSpellInventoryPane

## Status

- Confidence: strong for behavior, inventory-module placement, child-scrollbar relationship, and current file parent; medium-high for final field names and spell input helper naming.
- Likely source file: [UID:0000LU][NewSpellInventoryPane](by-file/NewSpellInventoryPane.md), under the [UID:0000O1][SpellInventoryPane](by-file/SpellInventoryPane.md) umbrella
- Address range: [UID:0001IH][0x0057c2d0-0x0057f742.SpellInventoryPanes](by-memory/0x0057c2d0-0x0057f742.SpellInventoryPanes.md)
- Current recovered file: `source-3/simroot_v2/class_NewSpellInventoryPane.cpp`

## Class Purpose

`NewSpellInventoryPane` is the newer spell inventory pane. It owns an embedded [UID:0000CN][ScrollSpellInventoryPane](by-class/ScrollSpellInventoryPane.md), rebuilds the visible learned-spell list, supports collapsed and expanded row counts, handles hover/drag/quick-cast/swap interactions, and dispatches spells to direct-cast or input-pane flows.

## Autogen Status

- Reconstructable: true; this is NexusTK-owned UI source.
- Autogen parent: [UID:0000LU][NewSpellInventoryPane](by-file/NewSpellInventoryPane.md). The file page has a reviewed `NexusTK/ui/inventory/` path, method-family map, child scrollbar caller evidence, and spell-cast/input dispatch caveats.
- C++ emission: none. The exact fields, spell-type dispatch names, input-pane helper names, and final child method splits remain below the 95+ source-emission gate.

## Source Ownership

Attach this class to [UID:0000LU][NewSpellInventoryPane](by-file/NewSpellInventoryPane.md) for current reconstruction. Keep [UID:0000NJ][ScrollSpellInventoryPane](by-file/ScrollSpellInventoryPane.md) as a reviewed companion root for now; it may fold into `NewSpellInventoryPane.cpp` later, but current docs preserve it as a private spell-inventory scrollbar file.

The broader [UID:0001IH][0x0057c2d0-0x0057f742.SpellInventoryPanes](by-memory/0x0057c2d0-0x0057f742.SpellInventoryPanes.md) aggregate is attached to the older [UID:0000O1][SpellInventoryPane](by-file/SpellInventoryPane.md) family root and covers legacy, new, alternate, and destructor-tail children. Use its child pages for exact boundaries; do not treat the aggregate parent as evidence that this class should be folded into the legacy spell inventory source by default.

## Method Families

| Family | Representative methods | Role |
| --- | --- | --- |
| Lifecycle/layout | `NewSpellInventoryPane`, `OnRefresh`, `OnResize`, `SetBoundsForMode`, `OnLayout`, `OnHide`, `ScalarDeletingDestructor` | Creates child scrollbar and keeps collapsed/expanded layout synchronized. |
| Spell list model | `RebuildSpellList`, `ResolveVisibleSpellSlot`, `HitTestSpellRow` | Scans player spell data and maps visible rows to real spell slots. |
| Rendering | `OnPaint`, `GetButtonRect` | Draws the spell list, selection highlight, key labels, names, and expand toggle. |
| Input/timers | `OnKeyEvent`, `OnMouseEvent`, `OnTimerEvent`, `OnScrollPositionChanged` | Handles page keys, mouse interactions, scroll repeat, and scrollbar sync. |
| Spell activation | `CastSpell`, `StopSound`, `ToggleExpandedMode` | Dispatches spell use, stops spell sound, and toggles expanded display. |

## Evidence Notes

- IDA MCP confirms `0x0057cf70-0x0057d03f`, `0x0057d430-0x0057d8c4`, `0x0057d9c0-0x0057e18f`, and `0x0057e2d0-0x0057e56d`.
- Wave3 notes describe player spell data at `g_pPlayerData + 0x13a834`, stride `0x148`, with normal 13-row and expanded 26-row modes.
- `CastSpell` calls several spell input/cast helpers, so exact spell-type names should wait for a spell packet/input-pane pass.
- [UID:0000LU][NewSpellInventoryPane](by-file/NewSpellInventoryPane.md) records the current source root, companion scrollbar candidate, constructor caller/callee evidence, vtable slot ownership, internal helper chain, and cast/input dispatch evidence at `82/82`.
- [UID:0001IH][0x0057c2d0-0x0057f742.SpellInventoryPanes](by-memory/0x0057c2d0-0x0057f742.SpellInventoryPanes.md) splits the new-pane core as [UID:0002RJ][0x0057cf70-0x0057ea57.NewSpellInventoryPaneCoreAndHelpers](by-memory/0x0057cf70-0x0057ea57.NewSpellInventoryPaneCoreAndHelpers.md) and scalar deleting destructor tail as [UID:0002RL][0x0057f58b-0x0057f742.SpellInventoryScalarDeletingDestructors](by-memory/0x0057f58b-0x0057f742.SpellInventoryScalarDeletingDestructors.md).
- [UID:0001GM][0x0055f450-0x005608fc.ScrollSpellInventoryPane](by-memory/0x0055f450-0x005608fc.ScrollSpellInventoryPane.md) records the one observed scrollbar constructor caller at `0x0057d013` inside this class constructor, while [UID:0000NJ][ScrollSpellInventoryPane](by-file/ScrollSpellInventoryPane.md) keeps the standalone-versus-folded source caveat explicit.

## Score Rationale

| Field | Value | Rationale |
| --- | --- | --- |
| Completion | `80` | Purpose, method families, player-spell model leads, source parent, companion scrollbar relationship, aggregate child split, and spell input/cast caveats are documented. Completion is capped by missing exact field layout, unsplit per-method class pages, and source-quality spell helper names. |
| Confidence | `84` | Existing IDA-backed docs agree on constructor/paint/input/cast boundaries, `ui/inventory/` placement, the sole observed child scrollbar constructor caller, and the file parent. Confidence remains below final audit because this pass added no fresh IDA/MCP evidence and spell-type/input helper naming is still unresolved. |

## Cross-References

- [UID:0000LU][NewSpellInventoryPane](by-file/NewSpellInventoryPane.md)
- [UID:0000O1][SpellInventoryPane](by-file/SpellInventoryPane.md)
- [UID:0001IH][0x0057c2d0-0x0057f742.SpellInventoryPanes](by-memory/0x0057c2d0-0x0057f742.SpellInventoryPanes.md)
- [UID:0002RJ][0x0057cf70-0x0057ea57.NewSpellInventoryPaneCoreAndHelpers](by-memory/0x0057cf70-0x0057ea57.NewSpellInventoryPaneCoreAndHelpers.md)
- [UID:0002RL][0x0057f58b-0x0057f742.SpellInventoryScalarDeletingDestructors](by-memory/0x0057f58b-0x0057f742.SpellInventoryScalarDeletingDestructors.md)
- [UID:0000CN][ScrollSpellInventoryPane](by-class/ScrollSpellInventoryPane.md)
- [UID:0000NJ][ScrollSpellInventoryPane](by-file/ScrollSpellInventoryPane.md)
- [UID:0001GM][0x0055f450-0x005608fc.ScrollSpellInventoryPane](by-memory/0x0055f450-0x005608fc.ScrollSpellInventoryPane.md)
- [UID:0000O0][SpellInputPanes](by-file/SpellInputPanes.md)
- [UID:0000DX][SpellWhoInputPane](by-class/SpellWhoInputPane.md)

## Changes

- 2026-06-05: Marked `RECONSTRUCTABLE:TRUE` after live IDA MCP on `NexusTK.exe` confirmed representative newer spell-inventory lifecycle/list/render/input/activation method starts at `0x0057cf70`, `0x0057d430`, `0x0057d9c0`, and `0x0057e2d0`. Left `AUTOGEN_PARENT_UID` blank because this class is below the 80 completion attachment gate even though [UID:0000LU][NewSpellInventoryPane](by-file/NewSpellInventoryPane.md) and [UID:0000O1][SpellInventoryPane](by-file/SpellInventoryPane.md) are likely source-family parents.
- Before: completion/confidence metadata were `0/0` despite class purpose, method-family, evidence, and inventory/source-placement notes.
- Changed to: `COMPLETION:74` and `CONFIDENCE:84`.
- Evidence: the page documents lifecycle/layout, spell-list model, rendering, input/timer behavior, activation flow, row counts, and player-spell data leads; remaining gaps are detailed field layout and exact spell-type/input helper naming.
- 2026-06-07 A006 parent attachment and source-ownership pass:
  - Before: the page was reconstructable but parentless because completion was below the attachment gate.
  - Changed to: `COMPLETION:80`, `AUTOGEN_PARENT_UID:0000LU`, added autogen/source ownership sections, added score rationale, and left C++ blank.
  - Evidence: [UID:0000LU][NewSpellInventoryPane](by-file/NewSpellInventoryPane.md) is a reviewed `82/82` source root with `NexusTK/ui/inventory/` placement; [UID:0001IH][0x0057c2d0-0x0057f742.SpellInventoryPanes](by-memory/0x0057c2d0-0x0057f742.SpellInventoryPanes.md) has exact child pages for the new-pane core and destructor tail; [UID:0001GM][0x0055f450-0x005608fc.ScrollSpellInventoryPane](by-memory/0x0055f450-0x005608fc.ScrollSpellInventoryPane.md) and [UID:0000NJ][ScrollSpellInventoryPane](by-file/ScrollSpellInventoryPane.md) document the owned scrollbar relationship and remaining source-split caveat.
