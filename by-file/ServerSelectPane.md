*** UID:0000NO | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:80 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***

# ServerSelectPane

## Status

- Confidence: strong for feature ownership, medium for two helper/data-boundary caveats.
- Proposed module: `login/ServerSelectPane.cpp`
- Current recovered sources: `class_ServerSelectPane.cpp`, `class_ServerSelectMenuItemList.cpp`, and nearby recovered main-menu cleanup helper.

## File Role

`ServerSelectPane.cpp` owns the pre-login server-selection dialog. It displays the server list using `DLGSERV.EPD` or `DLGSERV.EPF`, remembers the configured server name, lets the user confirm or cancel, and writes the selected server name into the application/session buffer before the login flow continues.

This belongs under `login/` rather than generic dialogs because it is part of the main-menu/login sequence and is closed by `CloseMainMenuDialogSingletons_4F69A0` together with other pre-login panes.

## Proposed Contents

| Entity | Address evidence | Role |
| --- | --- | --- |
| `ServerSelectPane` | `0x00573d20-0x00574496`, thunks `0x0057475b`/`0x00574766`, destructor `0x00574780-0x005747de` | Modal server-selection dialog, layout construction, OK/cancel handling, scroll-button state, and cleanup. |
| `ServerSelectMenuItemList` | projected constructor `0x005744a0`, active methods `0x00574660-0x00574747` | List-pane row widget for selecting server rows and drawing `Name : Description` text. |
| Selection helpers | `0x00574510-0x0057465d` | [UID:0000VG][ServerSelectHelpers_574510_5745b0](by-item/ServerSelectHelpers_574510_5745b0.md) currently mis-owned/unowned in Wave3; applies the chosen server, sends the select-server packet, and stores endpoint/session state. |
| Global singleton | [UID:0000S8][g_pServerSelectPane](by-global/g_pServerSelectPane.md) / `g_serverSelectPane` | Tracks the active server-select pane for pre-login cleanup. Naming needs final reconciliation. |

## Evidence Notes

- IDA MCP confirms `ServerSelectPane::ServerSelectPane` at `0x00573d20-0x00574300`, action handler at `0x00574340-0x00574430`, scroll-button updater at `0x00574440-0x00574496`, adjustor thunks at `0x0057475b` and `0x00574766`, and scalar deleting destructor at `0x00574780-0x005747de`.
- IDA MCP confirms `ServerSelectMenuItemList` active methods at `0x00574660-0x0057466a` and `0x00574670-0x00574747`.
- IDA MCP does not define a function at Wave3's projected `ServerSelectMenuItemList` constructor `0x005744a0`; the generated `ServerSelectPane` constructor currently builds the list inline.
- IDA MCP confirms real helper functions at `0x00574510-0x0057454d` and `0x005745b0-0x0057465d`; Wave3 currently owns the first as `ChattingColorListPane::ApplySelectedColor`, which is not consistent with server-select caller and data-flow context.
- 2026-05-24 MCP recheck: `xrefs_to 0x00574510` reports only the two `ServerSelectPane::OnDialogAction` branch calls at `0x00574399` and `0x005743db`. Decompilation shows the helper copying the selected server name into the config/current-server buffer before calling `0x005745b0`, which sends the `0x57` select-server packet and records selected endpoint state.
- `xrefs_to 0x0069b4ac` supports [UID:0000S8][g_pServerSelectPane](by-global/g_pServerSelectPane.md): main-menu cleanup/startup, constructor, non-deleting destructor helper, thunk, and scalar deleting destructor all touch the same pointer.

## Ownership Notes

- Keep the server-select pane near `MainMenuPane` and login/account dialogs. It is not part of in-game popup/menu infrastructure.
- The list pane should migrate with `ServerSelectPane`, not as a generic list control.
- Treat `0x005744a0`, `0x00574510`, `0x005745b0`, and the `g_serverSelectPane`/`g_pServerSelectPane` alias split as cleanup targets before any source move or rename operation.

## Cross-References

- [UID:0000D2][ServerSelectPane](by-class/ServerSelectPane.md)
- [UID:0000D1][ServerSelectMenuItemList](by-class/ServerSelectMenuItemList.md)
- [UID:0001HR][0x00573d20-0x005747df.ServerSelectPane](by-memory/0x00573d20-0x005747df.ServerSelectPane.md)
- [UID:0000VG][ServerSelectHelpers_574510_5745b0](by-item/ServerSelectHelpers_574510_5745b0.md)
- [UID:0000S8][g_pServerSelectPane](by-global/g_pServerSelectPane.md)
- [UID:0000L0][MainMenuPane](by-file/MainMenuPane.md)
- [UID:0000KX][LoginDialogPane](by-file/LoginDialogPane.md)

## Changes

- 2026-05-30: Scored documentation completeness/confidence.
  - Before: completion/confidence metadata was ungraded at `0/0`.
  - After: set completion to `84` and confidence to `80`.
  - Evidence: document covers login feature role, proposed contents, IDA method boundaries, helper/data-boundary caveats, singleton alias evidence, ownership notes, and cross-references; confidence remains limited by projected list constructor and helper ownership cleanup.
