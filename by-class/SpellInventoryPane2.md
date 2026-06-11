*** UID:0000DO | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:80 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:82 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# SpellInventoryPane2

## Status

- Confidence: strong for alternate spell-pane behavior, source-family ownership, and verified method boundaries; medium for constructor/setup boundary.
- Likely source file: [UID:0000O1][SpellInventoryPane](by-file/SpellInventoryPane.md) or `ui/inventory/SpellInventoryPane.cpp`
- Autogen handling: parent intentionally blank under the corrected direct child/parent `85/85` gate. [UID:0000O1][SpellInventoryPane](by-file/SpellInventoryPane.md) is the likely source root, but this class is still `80/82` and the file root is also below gate.
- Address range: [UID:0001IH][0x0057c2d0-0x0057f742.SpellInventoryPanes](by-memory/0x0057c2d0-0x0057f742.SpellInventoryPanes.md)
- Current recovered file: `source-3/simroot_v2/class_SpellInventoryPane2.cpp`

## Class Purpose

`SpellInventoryPane2` is an alternate grid/page spell inventory pane. It displays spell icons and names, supports page buttons and Page Up/Page Down keys, and handles spell selection/info clicks.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| `SpellInventoryPane2` | `0x0057ea60-0x0057ea9f` | Wave3-projected constructor; IDA does not currently define a function at this start. |
| `ResetPage` | `0x0057eac0-0x0057ead4` | Resets to first page. |
| `OnPaint` | `0x0057eb00-0x0057eda3` | Renders up to 13 spell entries with icons and names. |
| `OnKeyDown` | `0x0057edb0-0x0057ee2b` | Handles Page Up/Page Down. |
| `OnMouseClick` | `0x0057ee30-0x0057eff6` | Handles page buttons and spell selection/info. |
| `~SpellInventoryPane2` | `0x0057f640-0x0057f694` | Destroys `PanelPane` base and conditionally frees storage. |

## Evidence Notes

- IDA MCP confirms paint, click, and destructor boundaries.
- [UID:0002RK][0x0057eaa0-0x0057f58b.SpellInventoryPane2CoreAndHelpers](by-memory/0x0057eaa0-0x0057f58b.SpellInventoryPane2CoreAndHelpers.md) documents the alternate-pane method/helper island at `78/82` and remains unassigned under the corrected strict gate.
- [UID:0001IH][0x0057c2d0-0x0057f742.SpellInventoryPanes](by-memory/0x0057c2d0-0x0057f742.SpellInventoryPanes.md) records the enclosing spell inventory aggregate at `82/84`, including the vtable dword review that maps `SpellInventoryPane2` slots into this executable island.
- [UID:00026J][0x0062d02c-0x0062d418.SpellInventoryMacroReadOnlyData](by-memory/0x0062d02c-0x0062d418.SpellInventoryMacroReadOnlyData.md) records the mixed read-only-data island containing the `SpellInventoryPane2` vtable group.
- IDA reports no function at `0x0057ea60`; previous function is `0x0057e9d0-0x0057ea57`, next function is `0x0057eaa0-0x0057eabf`. This is tracked in [wave3_data_issues](../wave3_data_issues.md).

## Parent Gate Analysis

`SpellInventoryPane2` is reconstructable and likely belongs under [UID:0000O1][SpellInventoryPane](by-file/SpellInventoryPane.md), but it remains unassigned for autogen until both sides clear the strict `85/85` gate. The class page is now `80/82`, while the likely file root is still `82/82`; neither side is high enough for a direct parent assertion.

Child method pages should attach to this class only after their own exact pages and this class page clear `85/85`. The current low child [UID:0002RK][0x0057eaa0-0x0057f58b.SpellInventoryPane2CoreAndHelpers](by-memory/0x0057eaa0-0x0057f58b.SpellInventoryPane2CoreAndHelpers.md) therefore stays unassigned rather than bypassing this class and attaching directly to the file root.

## Cross-References

- [UID:0000O1][SpellInventoryPane](by-file/SpellInventoryPane.md)
- [UID:0001IH][0x0057c2d0-0x0057f742.SpellInventoryPanes](by-memory/0x0057c2d0-0x0057f742.SpellInventoryPanes.md)
- [UID:0002RK][0x0057eaa0-0x0057f58b.SpellInventoryPane2CoreAndHelpers](by-memory/0x0057eaa0-0x0057f58b.SpellInventoryPane2CoreAndHelpers.md)
- [UID:00026J][0x0062d02c-0x0062d418.SpellInventoryMacroReadOnlyData](by-memory/0x0062d02c-0x0062d418.SpellInventoryMacroReadOnlyData.md)

## Changes

- Before: completion/confidence were unevaluated at `0/0`.
- Changed to: completion `76`, confidence `74`.
- Evidence: the page documents alternate spell-pane behavior, file/range ownership, paint/key/click/destructor methods, and the projected-constructor caveat; confidence remains capped because IDA does not define the generated constructor start.
- 2026-06-03 autogen attachment pass:
  - Before: the page remained unparented at `76/74` even though the parent file and exact memory island had reached the 80+ confidence gate.
  - Changed to: completion/confidence `78/82`, `RECONSTRUCTABLE:TRUE`, and `AUTOGEN_PARENT_UID:0000O1`.
  - Evidence: [UID:0000O1][SpellInventoryPane](by-file/SpellInventoryPane.md) is `82/82`; [UID:0001IH][0x0057c2d0-0x0057f742.SpellInventoryPanes](by-memory/0x0057c2d0-0x0057f742.SpellInventoryPanes.md) documents the enclosing executable island at `82/84`; [UID:0002RK][0x0057eaa0-0x0057f58b.SpellInventoryPane2CoreAndHelpers](by-memory/0x0057eaa0-0x0057f58b.SpellInventoryPane2CoreAndHelpers.md) documents the class-specific alternate-pane helper island at `74/82`. C++ remains blank because IDA still does not define the generated constructor start and the page is below the final-source `95+` threshold.
- 2026-06-10 A002 strict-gate repair:
  - Before: the class still attached to [UID:0000O1][SpellInventoryPane](by-file/SpellInventoryPane.md) under the older 80% parent rule.
  - Changed to: completion/confidence `80/82` and blank `AUTOGEN_PARENT_UID`.
  - Evidence: the likely file root remains only `82/82`, the class is still below the corrected `85/85` gate, and [UID:0002RK][0x0057eaa0-0x0057f58b.SpellInventoryPane2CoreAndHelpers](by-memory/0x0057eaa0-0x0057f58b.SpellInventoryPane2CoreAndHelpers.md) remains capped by the unresolved constructor/setup boundary.
