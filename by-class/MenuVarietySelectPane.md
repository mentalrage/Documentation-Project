*** UID:000082 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# MenuVarietySelectPane

## Status

- Confidence: strong for class role and boundaries.
- Likely source file: [UID:0000L8][MenuVarietyPanes](by-file/MenuVarietyPanes.md)
- Main address range: [UID:0001NP][0x005bc610-0x005bfd98.MenuVarietyPanes](by-memory/0x005bc610-0x005bfd98.MenuVarietyPanes.md)
- Current recovered file: `source-3/simroot_v2/class_MenuVarietySelectPane.cpp`
- Shared destructor/thunk tail: [UID:0001NS][0x005bfbd0-0x005c0034.UiPaneDestructorThunksAndVectorHelper](by-memory/0x005bfbd0-0x005c0034.UiPaneDestructorThunksAndVectorHelper.md)

## Class Purpose

`MenuVarietySelectPane` is the selector opened by `MenuVarietyPane`. It stores menu labels, handles mouse selection, dispatches userlook/board/mail/friends/target/hotkey/profile/ranking/quit actions, and draws SUBWIN frame/border plus menu entries.

## Method Map

| Address | Method | Role |
| --- | --- | --- |
| `0x005bc970-0x005bcf7a` | `MenuVarietySelectPane::MenuVarietySelectPane()` | Constructs pane state and appends menu/action labels. |
| `0x005bcf80-0x005bcff7` | `~MenuVarietySelectPane()` | Removes/unregisters pane, destroys label vector, and clears global pointer. |
| `0x005bd000-0x005bd372` | `HandleMenuMouseEvent(...)` | Hover/click handler and action dispatcher. |
| `0x005bd3a0-0x005bd3bf` | `NotifyAndMarkSessionForDeletion()` | Pulses parent and marks session for deletion. |
| `0x005bd3c0-0x005bd5ac` | `DrawMenuEntries()` | Draws labels and selected-row marker. |
| `0x005bd5b0-0x005bd952` | Frame/border drawing | Draws SUBWIN fill and border tiles. |
| `0x005bd9b0-0x005bda3b` | [UID:0001NQ][0x005bd9b0-0x005bda3b.MenuVarietySelectPaneHitTest](by-memory/0x005bd9b0-0x005bda3b.MenuVarietySelectPaneHitTest.md) | Ten-row selector hit-test helper called only by `HandleMenuMouseEvent`; currently generated as `BulletinSession::GetMenuIndexFromPoint`. |
| `0x005bfbd0-0x005bfbdb` | `ClearMenuVarietySelectPaneSingleton` | Clears [UID:0000RJ][g_pMenuVarietySelectPane](by-global/g_pMenuVarietySelectPane.md). |
| `0x005bfc21-0x005bfc37` | Adjustor/thunk helpers | Destructor adjustor helpers. |
| `0x005bfce0-0x005bfd98` | `ScalarDeletingDestructor(...)` | Destructor wrapper with scalar-delete flag handling. |

## Evidence Notes

- Wave3 grades the class at effective `96.3`.
- IDA MCP confirms all listed starts as exact functions.
- IDA MCP on 2026-05-26 confirms `0x005bd9b0` is a ten-row hit-test helper with callers only at `0x005bd089` and `0x005bd338` inside `MenuVarietySelectPane::HandleMenuMouseEvent`.
- IDA xrefs and active simroot names resolve global `0x0069bf78` as [UID:0000RJ][g_pMenuVarietySelectPane](by-global/g_pMenuVarietySelectPane.md); the `0x005bfbd0` helper clears this selector singleton.
- The quit action constructs [UID:0000BG][QuitDialog](by-class/QuitDialog.md) at `0x005bd202`; the confirmation dialog implementation belongs to [UID:0000MX][QuitDialogs](by-file/QuitDialogs.md).
- Older notes classify adjacent vector helpers as generic small-wide-string vector support, not class-owned menu-variety logic.

## Cross-References

- [UID:0000L8][MenuVarietyPanes](by-file/MenuVarietyPanes.md)
- [UID:000081][MenuVarietyPane](by-class/MenuVarietyPane.md)
- [UID:0000RI][g_pMenuVarietyPane](by-global/g_pMenuVarietyPane.md)
- [UID:0000RJ][g_pMenuVarietySelectPane](by-global/g_pMenuVarietySelectPane.md)
- [UID:0001NQ][0x005bd9b0-0x005bda3b.MenuVarietySelectPaneHitTest](by-memory/0x005bd9b0-0x005bda3b.MenuVarietySelectPaneHitTest.md)
- [UID:0000BG][QuitDialog](by-class/QuitDialog.md)
- [UID:0001NS][0x005bfbd0-0x005c0034.UiPaneDestructorThunksAndVectorHelper](by-memory/0x005bfbd0-0x005c0034.UiPaneDestructorThunksAndVectorHelper.md)

## Changes

- Completion/confidence score update: existed before as `0/0`; changed to `84/86`. Summary: the menu selector pane is documented in high detail across construction, labels/actions, mouse dispatch, draw/frame helpers, singleton cleanup, hit-test helper, quit-dialog dependency, and generic vector-helper exclusion. Evidence: linked `MenuVarietyPanes` range, IDA-confirmed method starts, singleton global references, 2026-05-26 hit-test caller recheck, and adjacent vector-helper classification.
