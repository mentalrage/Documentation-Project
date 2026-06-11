*** UID:00007O | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000L0 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# MainMenuPane

## Status

- Confidence: strong
- Likely source file: [UID:0000L0][MainMenuPane](by-file/MainMenuPane.md)
- Address range: [UID:00019I][0x004f6700-0x004fb62a.MainMenuLoginAndAccountDialogs](by-memory/0x004f6700-0x004fb62a.MainMenuLoginAndAccountDialogs.md)
- Current recovered file: `source-3/simroot_v2/class_MainMenuPane.cpp`

## Class Purpose

`MainMenuPane` is the pre-login menu controller. It renders and navigates the main menu, handles pre-login server messages, and opens the login/account/password/story/exit flows selected by the user.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| `MainMenuPane` | `0x004f6700` | Constructs the menu pane and loads menu art/resources. |
| `~MainMenuPane` | `0x004f6910` | Tears down menu state and calls dialog-singleton cleanup. |
| `OnMouseEvent` | `0x004f6af0` | Updates selection and triggers menu activation from mouse input. |
| `OnKeyEvent` | `0x004f6bf0` | Keyboard navigation and activation. |
| `OnServerMessage` | `0x004f6d80` | Pre-login server-message handling. |
| `OnTimerEvent` | `0x004f7660` | Menu timer handling. |
| `OnPaint` | `0x004f76d0` | Paints menu assets and selected item. |
| `ActivateMenuItem` | `0x004f7a10` | Dispatches selected menu item to create-user, login, password, story/history frame viewer, terminal, or exit. |
| `HitTestMenuItem_4F8C10` | `0x004f8c10` | File-local helper used by `OnMouseEvent` to map mouse coordinates to a menu item index. |
| `HandleLegacyMainMenuPacket_4F8D00` | `0x004f8d00` | File-local helper for pre-login server-message opcode `3`; packet semantic name still open. |
| `OpenCreateUserDialog_4F8FA0` | `0x004f8fa0` | Retained create-user launcher; currently no direct caller/xref. |
| `OpenTerminalPane_4F91C0` | `0x004f91c0` | Retained terminal launcher; currently no direct caller/xref. |
| Destructor thunks | `0x005024e2`, `0x005024ed`, `0x00502850` | Multiple-inheritance deleting destructor family. |

## Evidence Notes

- IDA MCP confirms all listed method starts as functions.
- `ActivateMenuItem` calls `LoginDialogPane::LoginDialogPane`, `ChangePasswordDialogPane::ChangePasswordDialogPane`, `CreateUserDialogPane::CreateUserDialogPane`, and `NewUserDialogPane2::NewUserDialogPane2`.
- `ActivateMenuItem` calls [UID:000066][HistoryViewingPane](by-class/HistoryViewingPane.md) for the story/history menu branches, passing `STORY.EPF`/`STORY.EPD` or `HISTORY.EPF`/`HISTORY.EPD` based on the high-resolution layout flag.
- [UID:0000PI][ComputeMenuItemRect_4F8B90](by-global/ComputeMenuItemRect_4F8B90.md) is a local menu geometry helper used by mouse, key, and paint handlers.
- [UID:0000T1][HitTestMenuItem_4F8C10](by-global/HitTestMenuItem_4F8C10.md) is called only from `OnMouseEvent` in the current IDA database.
- [UID:0000SZ][HandleLegacyMainMenuPacket_4F8D00](by-global/HandleLegacyMainMenuPacket_4F8D00.md) is called only from `OnServerMessage` and triggers a `Meta.dat` sync after its packet work.
- [UID:0000TB][OpenCreateUserDialog_4F8FA0](by-global/OpenCreateUserDialog_4F8FA0.md) and [UID:0000TF][OpenTerminalPane_4F91C0](by-global/OpenTerminalPane_4F91C0.md) are real retained launch helpers with no direct xrefs found in the current IDA database.
- [UID:0000PH][CloseMainMenuDialogSingletons_4F69A0](by-global/CloseMainMenuDialogSingletons_4F69A0.md) is called from main-menu teardown paths and closes the pre-login singleton dialog cluster.
- Generated source uses `g_useHighResLayout`/config bytes to select old/new menu branches.

## Cross-References

- [UID:0000L0][MainMenuPane](by-file/MainMenuPane.md)
- [UID:0000KX][LoginDialogPane](by-file/LoginDialogPane.md)
- [UID:0000IK][CreateUserDialogs](by-file/CreateUserDialogs.md)
- [UID:000066][HistoryViewingPane](by-class/HistoryViewingPane.md)
- [UID:0000PH][CloseMainMenuDialogSingletons_4F69A0](by-global/CloseMainMenuDialogSingletons_4F69A0.md)
- [UID:0000PI][ComputeMenuItemRect_4F8B90](by-global/ComputeMenuItemRect_4F8B90.md)
- [UID:0000T1][HitTestMenuItem_4F8C10](by-global/HitTestMenuItem_4F8C10.md)
- [UID:0000SZ][HandleLegacyMainMenuPacket_4F8D00](by-global/HandleLegacyMainMenuPacket_4F8D00.md)
- [UID:0000TB][OpenCreateUserDialog_4F8FA0](by-global/OpenCreateUserDialog_4F8FA0.md)
- [UID:0000TF][OpenTerminalPane_4F91C0](by-global/OpenTerminalPane_4F91C0.md)
- [UID:0001RF][main-menu-history-resources](by-resource/main-menu-history-resources.md)

## Changes

- 2026-06-05: Marked reconstructable and attached to [UID:0000L0][MainMenuPane](by-file/MainMenuPane.md) because the class is `84/88` and the parent is `88/82`, satisfying the 80/80 parent gate. Live IDA MCP evidence: `lookup_funcs` confirms exact starts for the constructor/destructor, mouse/key/server/timer/paint handlers, activation helper, retained launch helpers, and scalar deleting destructor at `0x004f6700`, `0x004f6910`, `0x004f6af0`, `0x004f6bf0`, `0x004f6d80`, `0x004f7660`, `0x004f76d0`, `0x004f7a10`, `0x004f8c10`, `0x004f8d00`, `0x004f8fa0`, `0x004f91c0`, and `0x00502850`; `callers` confirms constructor calls from `0x00504b35` and `0x0058b3de`.
- Completion/confidence score update: existed before as `0/0`; changed to `84/88`. Summary: the pre-login menu controller has detailed purpose, method inventory, dialog-launch dependencies, local helper ownership, retained launcher caveats, singleton cleanup, resource branches, and high-resolution behavior documented, with final source-level rewrite detail still incomplete. Evidence: IDA-confirmed method starts, `ActivateMenuItem` callees, menu geometry/helper globals, story/history resource references, and retained no-xref launcher notes.
