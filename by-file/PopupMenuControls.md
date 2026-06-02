*** UID:0000MN | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:80 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"NexusTK/ui/menu/" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***

# PopupMenuControls

## Status

- Confidence: strong for reusable popup-menu control ownership; medium for exact split between controls and menu item sources.
- Proposed module folder: `ui/menu/`
- Candidate file: `ui/menu/PopupMenuControls.cpp`
- Current generated sources: `class_PopupMenuControlPane.cpp`, `class_MenuPane.cpp`, `class_MenuItem.cpp`, `class_StringMenuItem.cpp`, `class_SeparatorMenuItem.cpp`, and `class_PlainMemberFunctionObject_void____thiscall_PopupMenuControlPane_____long____class_PopupMenuControlPane_.cpp`.
- Evidence basis: Wave3 class inspection, `simroot_v2` generated source, older Wave2 notes for `MenuPane::GetItemByIndex`, and targeted IDA MCP boundary checks on 2026-05-23.

## Hypothesis

The reusable popup-menu control code likely lived together as a small UI/menu framework source file. `PopupMenuControlPane` constructs a `MenuPane` and a member-function callback object, while `MenuPane` owns the list of `MenuItem` entries and dispatches pointer/keyboard selection to its callback target. `StringMenuItem` and `SeparatorMenuItem` are concrete entries used by popup and context-menu flows.

Likely structure:

```text
ui/menu/PopupMenuControls.cpp
```

Possible split:

```text
ui/menu/MenuPane.cpp
ui/menu/MenuItem.cpp
ui/controls/PopupMenuControlPane.cpp
```

## Proposed Contents

| Entity | Current range | Current file | Role |
| --- | --- | --- | --- |
| `PopupMenuControlPane` | `0x00498040-0x0049b8e5` | `class_PopupMenuControlPane.cpp` | Dialog/control wrapper that owns a `MenuPane`, draws `POPUP_MENU` EPF art, and forwards mouse/key selection. |
| [UID:0000V8][PopupMenuSelectionCallback_0049AF00](by-item/PopupMenuSelectionCallback_0049AF00.md) | `0x0049af00-0x0049af11` | long generated template filename | Small callback object invoked by `MenuPane` selection. |
| `MenuPane` | `0x00516290-0x005173fe` | `class_MenuPane.cpp` | Popup menu pane with entry list, layout building, hit-testing, pointer/keyboard navigation, and selection dispatch. |
| `MenuItem` | `0x00516f00-0x0051731e` | `class_MenuItem.cpp` | Base menu item with bounds/enabled state and deleting destructor. |
| `StringMenuItem` | `0x00516ff0-0x00517441` | `class_StringMenuItem.cpp` | Text menu item that measures, returns, and draws a fixed wide-character label. |
| `SeparatorMenuItem` | `0x005171b0-0x005172be` | `class_SeparatorMenuItem.cpp` | Non-interactive separator item with fixed dimensions/style flags and separator-line drawing. |

## IDA MCP Evidence

Targeted checks on 2026-05-23 confirmed:

- `PopupMenuControlPane`: `0x00498040-0x0049812b`, `0x00498270-0x004984bc`, `0x004984c0-0x0049851a`, `0x00498520-0x00498599`, `0x0049af95-0x0049afa0`, `0x0049afa0-0x0049afab`, `0x0049b3b0-0x0049b417`, and `0x0049b8e0-0x0049b8e5`.
- Callback helper: [UID:0000V8][PopupMenuSelectionCallback_0049AF00](by-item/PopupMenuSelectionCallback_0049AF00.md) at `0x0049af00-0x0049af11`.
- `MenuPane`: `0x00516290-0x00516345`, `0x00516350-0x005163fa`, `0x005164e0-0x005164f7`, `0x00516790-0x0051693e`, `0x00516940-0x00516a62`, `0x00516a70-0x00516ba8`, `0x005172be-0x005172c9`, `0x005172c9-0x005172d4`, and `0x00517320-0x005173fe`.
- `MenuItem`/`StringMenuItem`/`SeparatorMenuItem`: `0x00516f00-0x00517441` as listed in the memory page.

IDA caller evidence ties `PopupMenuControlPane::OnDraw` to `MenuPane::GetItemByIndex`, and older Wave2 notes record that `0x005164e0` was restored under `MenuPane` after reviewing `PopupMenuControlPane` and `RadioGroupControlPane` callers.

## Ownership Notes

- Keep this separate from item-specific menu dialogs such as `ServerItemMenuDialog` and from packet-driven message/menu-question dialogs.
- [UID:000238][0x00517450-0x00517d23.MenuDialogFactoryHelpers](by-memory/0x00517450-0x00517d23.MenuDialogFactoryHelpers.md) begins immediately after the menu item destructor padding, but it is a merchant/dialog factory island rather than reusable popup-menu item code.
- `RightButtonMenuPane`, `VoteMenuPane`, and `MenuVarietyPane` use similar drawing idioms and SUBWIN/MENUVAR resources, but they are gameplay/menu entry points and should be documented as neighboring feature panes, not as proof that every menu-named class belongs in this core file.
- The complex template callback class name caused a Wave3 lookup timeout; use [UID:0000V8][PopupMenuSelectionCallback_0049AF00](by-item/PopupMenuSelectionCallback_0049AF00.md) as the short alias and use the generated source file plus IDA boundary for evidence. The reusable callback type itself belongs with [UID:0000JO][FunctionObjects](by-file/FunctionObjects.md), while this file owns the popup-menu construction/consumer side.
- Current emitted source omits some tiny virtual/helper thunk bodies for `PopupMenuControlPane` and `MenuPane`; migration should include IDA-confirmed omitted starts.
- 2026-05-26 IDA MCP resolved the concrete menu-item vtables at `0x0061eb98`, `0x0061ebb4`, and `0x0061ebd0`; see [UID:0001Y4][MenuItemVtables](by-type/by-vtable/MenuItemVtables.md). Current generated metadata reports `vtable_count: 0` for the three menu item classes.
- [UID:0001V5][MenuItemLayouts](by-type/by-struct/MenuItemLayouts.md) records the shared bounds/state layout and the `StringMenuItem` inline `wchar_t[0x80]` label buffer at offset `+0x18`.

## Cross-References

- [UID:0000AN][PopupMenuControlPane](by-class/PopupMenuControlPane.md)
- [UID:00007W][MenuPane](by-class/MenuPane.md)
- [UID:0000V8][PopupMenuSelectionCallback_0049AF00](by-item/PopupMenuSelectionCallback_0049AF00.md)
- [UID:0000AK][PlainMemberFunctionObject_void____thiscall_PopupMenuControlPane_____long____class_PopupMenuControlPane_](by-class/PlainMemberFunctionObject_void____thiscall_PopupMenuControlPane_____long____class_PopupMenuControlPane_.md)
- [UID:0000JO][FunctionObjects](by-file/FunctionObjects.md)
- [UID:00007V][MenuItem](by-class/MenuItem.md)
- [UID:0000E8][StringMenuItem](by-class/StringMenuItem.md)
- [UID:0000CY][SeparatorMenuItem](by-class/SeparatorMenuItem.md)
- [UID:0001Y4][MenuItemVtables](by-type/by-vtable/MenuItemVtables.md)
- [UID:0001V5][MenuItemLayouts](by-type/by-struct/MenuItemLayouts.md)
- [UID:00011F][0x00498040-0x0049b8e5.PopupMenuControlPane](by-memory/0x00498040-0x0049b8e5.PopupMenuControlPane.md)
- [UID:0001BK][0x00516290-0x00517441.MenuPaneAndItems](by-memory/0x00516290-0x00517441.MenuPaneAndItems.md)
- [UID:000238][0x00517450-0x00517d23.MenuDialogFactoryHelpers](by-memory/0x00517450-0x00517d23.MenuDialogFactoryHelpers.md)
- [UID:0000L8][MenuVarietyPanes](by-file/MenuVarietyPanes.md)
- [UID:0000N7][RightButtonMenuPane](by-file/RightButtonMenuPane.md)
- [UID:0000P6][VoteMenuPane](by-file/VoteMenuPane.md)

## Changes

- Before: completion/confidence were ungraded at `0/0`.
- Changed to: completion `84`, confidence `78`.
- Summary/evidence: the page documents the popup menu framework hypothesis, proposed contents, IDA boundary evidence, ownership notes, vtable/layout refs, generated callback caveat, and cross-references; confidence remains capped by exact split between control, menu pane, and menu item sources.
- 2026-06-02 projected path and confidence update:
  - What existed before: `PROPOSED_RECONSTRUCTION_PATH` was blank and confidence stayed at `78`.
  - Changed to: `PROPOSED_RECONSTRUCTION_PATH:"NexusTK/ui/menu/"` and `CONFIDENCE:80`.
  - Summary/evidence: `by-project-structure/proposed-source-tree.md` names `PopupMenuControls.cpp` under `ui/menu/`, and this file already records IDA-backed popup-control, menu-pane, menu-item, vtable, layout, and callback evidence. Confidence remains capped at 80 because a later source-layout pass may split `MenuPane.cpp`, `MenuItem.cpp`, or `PopupMenuControlPane.cpp` from the consolidated file.
