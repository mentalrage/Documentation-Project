*** UID:0001QN | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:-1 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:-1 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***

# Client S2 Main Menu

## Status

- Scope: main menu through login/account dialog entry, excluding full character-creator internals.
- Confidence: medium; several menu-side dialogs are documented, but live reachability for older story/history paths still needs review.

## Covered Source Family

- [UID:0000L0][MainMenuPane](by-file/MainMenuPane.md) owns the top-level pre-login menu, input, paint, pre-login server-message handling, and menu-item dispatch.
- [UID:0000KX][LoginDialogPane](by-file/LoginDialogPane.md) owns credential entry, validation, login packet submission, and successful-login handoff into the main UI bootstrap.
- [UID:0000HP][BackStoryDialogPane](by-file/BackStoryDialogPane.md) owns the older story text dialog using `STORY.EPF`/`STORY.EPD`, `PAL01.PAL`/`NPAL8.PAL`, and `BACKTALE`.
- [UID:0000JW][HistoryViewingPane](by-file/HistoryViewingPane.md) owns the full-screen story/history frame viewer opened from `MainMenuPane` with `STORY.EPF`/`STORY.EPD` or `HISTORY.EPF`/`HISTORY.EPD`.
- [UID:0000LQ][NewHistoryDialogPane](by-file/NewHistoryDialogPane.md) owns the newer full-screen `HISTORYN.EPF` / `MADEBY` history-credits dialog; direct live construction is still unresolved.
- [UID:0000O3][StaffsDialogPane](by-file/StaffsDialogPane.md) owns the main-menu staff/credits dialog using `STAFF.EPF`, `NPAL8.PAL`, and `STAFFS`/`STAFFS2`.
- [UID:0000JJ][ForcedInformMessageDialog](by-file/ForcedInformMessageDialog.md) owns the mandatory accept/decline notice dialog using `DLGSTAFF.EPF`/`DLGSTAFF.EPD` and reactivates the login dialog after accepted teardown.
- [UID:0000NO][ServerSelectPane](by-file/ServerSelectPane.md), [UID:0000OI][TerminalPane](by-file/TerminalPane.md), [UID:0000MJ][PhoneBookDialog](by-file/PhoneBookDialog.md), and [UID:0000IK][CreateUserDialogs](by-file/CreateUserDialogs.md) are part of the same pre-login/login support family.

## Current Findings

- `MainMenuPane::ActivateMenuItem` opens login/account/password/story/history/terminal/exit flows from the menu selection state.
- `MainMenuPane::ActivateMenuItem` directly constructs `HistoryViewingPane` for both story and history frame-sequence actions. IDA reports four direct constructor call sites in that function plus two helper-wrapper call sites.
- [UID:0000PH][CloseMainMenuDialogSingletons_4F69A0](by-global/CloseMainMenuDialogSingletons_4F69A0.md) closes or marks for deletion the pre-login singleton dialogs, including `g_pBackStoryDialogPane` and `g_pHistoryViewingPane`.
- [UID:0000PI][ComputeMenuItemRect_4F8B90](by-global/ComputeMenuItemRect_4F8B90.md) owns the main-menu item rectangles used by mouse/key hit testing and paint.
- [UID:0000T1][HitTestMenuItem_4F8C10](by-global/HitTestMenuItem_4F8C10.md) owns main-menu mouse-coordinate hit testing and is called only from `MainMenuPane::OnMouseEvent`.
- [UID:0000SZ][HandleLegacyMainMenuPacket_4F8D00](by-global/HandleLegacyMainMenuPacket_4F8D00.md) is the only helper currently proven for pre-login server-message opcode `3`.
- [UID:0000TB][OpenCreateUserDialog_4F8FA0](by-global/OpenCreateUserDialog_4F8FA0.md), [UID:0000TE][OpenStoryViewingPane_4F90C0](by-global/OpenStoryViewingPane_4F90C0.md), [UID:0000TC][OpenHistoryViewingPane_4F9140](by-global/OpenHistoryViewingPane_4F9140.md), and [UID:0000TF][OpenTerminalPane_4F91C0](by-global/OpenTerminalPane_4F91C0.md) are retained launch helpers with no direct xrefs in the current IDA database.
- `BackStoryDialogPane` is still present as a concrete dialog class at `0x00500090-0x0050040d`, but IDA did not show a direct constructor xref during the 2026-05-24 pass. Treat it as an older or indirectly reached menu dialog until the caller path is resolved.
- `NewHistoryDialogPane` is present as a concrete dialog class at `0x00500410-0x00500632`; IDA did not show a direct constructor xref during the 2026-05-24 pass. Its embedded `ScrolledTextControlPaneForMadeBy` closes `g_pNewHistoryDialog` when `MADEBY` finishes scrolling.
- `StaffsDialogPane` is present as a concrete dialog class at `0x004ffaa0-0x004ffd3d`; IDA likewise shows no direct constructor caller, so treat the exact menu action path as open while keeping source placement in the main-menu family.
- `ForcedInformMessageDialog` is present as a concrete dialog class at `0x00587bb0-0x005881ed`; IDA shows no direct constructor caller, but its singleton is read by main-menu cleanup and its destructor calls `EnsureLoginDialogPane_4F8B30`.

## Cross-References

- [UID:0001R1][proposed-source-tree](by-project-structure/proposed-source-tree.md)
- [UID:00007O][MainMenuPane](by-class/MainMenuPane.md)
- [UID:0000PH][CloseMainMenuDialogSingletons_4F69A0](by-global/CloseMainMenuDialogSingletons_4F69A0.md)
- [UID:0000PI][ComputeMenuItemRect_4F8B90](by-global/ComputeMenuItemRect_4F8B90.md)
- [UID:0000T1][HitTestMenuItem_4F8C10](by-global/HitTestMenuItem_4F8C10.md)
- [UID:0000SZ][HandleLegacyMainMenuPacket_4F8D00](by-global/HandleLegacyMainMenuPacket_4F8D00.md)
- [UID:0000TB][OpenCreateUserDialog_4F8FA0](by-global/OpenCreateUserDialog_4F8FA0.md)
- [UID:0000TF][OpenTerminalPane_4F91C0](by-global/OpenTerminalPane_4F91C0.md)
- [UID:00000T][BackStoryDialogPane](by-class/BackStoryDialogPane.md)
- [UID:000066][HistoryViewingPane](by-class/HistoryViewingPane.md)
- [UID:000091][NewHistoryDialogPane](by-class/NewHistoryDialogPane.md)
- [UID:0000DY][StaffsDialogPane](by-class/StaffsDialogPane.md)
- [UID:00005E][ForcedInformMessageDialog](by-class/ForcedInformMessageDialog.md)
- [UID:0001RG][main-menu-story-resources](by-resource/main-menu-story-resources.md)
- [UID:0001RF][main-menu-history-resources](by-resource/main-menu-history-resources.md)
- [UID:0001RM][staff-dialog-resources](by-resource/staff-dialog-resources.md)
- [UID:0001RB][forced-inform-message-resources](by-resource/forced-inform-message-resources.md)
