*** UID:0000LN | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:80 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***

# MusicControlDialog

## Status

- Confidence: strong for class/file ownership, medium for helper ownership cleanup.
- Proposed module: `ui/dialogs/MusicControlDialog.cpp`
- Current recovered source: `class_MusicControlDialog.cpp`
- Main class: [UID:00008U][MusicControlDialog](by-class/MusicControlDialog.md)
- Main address doc: [UID:0001CP][0x00528e60-0x0052a535.MusicControlDialog](by-memory/0x00528e60-0x0052a535.MusicControlDialog.md)
- Evidence basis: Wave3 class/method summaries, generated `simroot_v2` source, and IDA MCP boundary/decompilation checks on 2026-05-23.

## File Role

`MusicControlDialog.cpp` owns the in-client music and sound settings dialog. It builds the `DLGSCNTL.EPF` dialog, manages sound-effect and music playback controls, edits the loose music-directory path, enumerates CD drives for Redbook playback, and dispatches previous/pause/next/accept commands into `SoundManager`.

This is best treated as a UI dialog source that depends on [UID:0000NV][SoundManager](by-file/SoundManager.md) and [UID:0000JF][FolderSelectDialog](by-file/FolderSelectDialog.md), not as part of the audio engine itself. `SoundManager.cpp` owns playback implementation; this file owns the settings dialog and the user-facing control policy.

## Proposed Contents

| Entity | Address evidence | Role |
| --- | --- | --- |
| `MusicControlDialog` | `0x00528e60-0x0052a535` | Dialog construction, command handling, control enablement, pause toggle, destructor/thunks. |
| folder path selected/input helper | `0x00529ee0-0x0052a00c` | Updates config path, updates control id `6`, rescans local music files, reapplies playback state. Currently mis-owned by `ChattingColorPane` in Wave3. |
| `ApplyMusicPlaybackState` | `0x0052a120-0x0052a17f` | Applies config playback mode to stream, Redbook, or zone music; currently mis-owned by `ChattingColorPane` in Wave3. |
| [UID:0000AL][PlainMemberFunctionObjectT_void____thiscall_MusicControlDialog_____class_m__h73bc206d7ae6](by-class/PlainMemberFunctionObjectT_void____thiscall_MusicControlDialog_____class_m__h73bc206d7ae6.md) | `0x0052a3e0-0x0052a4de` | Template callback wrapper used by [UID:0000JF][FolderSelectDialog](by-file/FolderSelectDialog.md) to call the selected-path handler. |
| `g_pSoundManager` and config offsets | global dependencies | Consumed by the dialog, but owned by audio/config modules. |

## Evidence Notes

- Wave3 reports `MusicControlDialog` as a class with grade `97.7`, emitted in `class_MusicControlDialog.cpp`, with five attached methods.
- IDA MCP confirms a compact function island from constructor `0x00528e60` through scalar deleting destructor `0x0052a4e0-0x0052a535`, with `NewUserDialogPane2` beginning at `0x0052a540`.
- The constructor builds controls from `DLGSCNTL.EPF`, initializes sliders/radio groups from `SoundManager` and config offsets around `g_pConfig + 0x291908`, and sends packet `0x11b`.
- `HandleControlCommand` drives control ids `1..14`, including SFX toggle, sample/stream volume sliders, playback mode selection, folder browsing, drive selection, previous/pause/next, and close.
- `TogglePauseState` retrieves control id `12` and calls [UID:00011D][0x00495cb0-0x00495cc9.SelectionControlPaneSetSelectionAndRefresh](by-memory/0x00495cb0-0x00495cc9.SelectionControlPaneSetSelectionAndRefresh.md) with frame ids `37` or `48`; the setter remains generic [UID:0000HY][ButtonControlPane](by-file/ButtonControlPane.md) code rather than music-dialog-owned implementation.
- IDA xrefs show `ApplyMusicPlaybackState` is only reached from `MusicControlDialog::HandleControlCommand` and the folder-path input helper, which supports moving it out of chat-color ownership.
- The folder callback wrapper is a [UID:0000JO][FunctionObjects](by-file/FunctionObjects.md) template instantiation; `MusicControlDialog.cpp` owns the selected-path handler and callback setup, not the generic callback type declarations.

## Ownership Notes

Keep this file separate from [UID:0000NV][SoundManager](by-file/SoundManager.md). The dialog has substantial UI construction and control dispatch code, while `SoundManager` owns Miles/Redbook/stream implementation.

Also keep this file separate from [UID:0000NX][SoundStatusPane](by-file/SoundStatusPane.md). Both are UI clients of the audio subsystem, but `MusicControlDialog` owns the full settings dialog and `SoundStatusPane` owns the always-visible HUD shortcut/caption pane.

The generated source still calls `ChattingColorPane::ApplyMusicPlaybackState`, `ChattingColorPane::OnFolderPathSelected`, and `ChattingColorPane::CloseDialog` from the music dialog. Those names should be treated as Wave3 owner pollution, not original source-layout evidence.

## Cross-References

- [UID:00008U][MusicControlDialog](by-class/MusicControlDialog.md)
- [UID:0001CP][0x00528e60-0x0052a535.MusicControlDialog](by-memory/0x00528e60-0x0052a535.MusicControlDialog.md)
- [UID:0000NV][SoundManager](by-file/SoundManager.md)
- [UID:0000NX][SoundStatusPane](by-file/SoundStatusPane.md)
- [UID:0000JF][FolderSelectDialog](by-file/FolderSelectDialog.md)
- [UID:0000JO][FunctionObjects](by-file/FunctionObjects.md)
- [UID:00011D][0x00495cb0-0x00495cc9.SelectionControlPaneSetSelectionAndRefresh](by-memory/0x00495cb0-0x00495cc9.SelectionControlPaneSetSelectionAndRefresh.md)
- [UID:0000AL][PlainMemberFunctionObjectT_void____thiscall_MusicControlDialog_____class_m__h73bc206d7ae6](by-class/PlainMemberFunctionObjectT_void____thiscall_MusicControlDialog_____class_m__h73bc206d7ae6.md)
- [UID:0000MN][PopupMenuControls](by-file/PopupMenuControls.md)
- [UID:0001R1][proposed-source-tree](by-project-structure/proposed-source-tree.md)

## Changes

- Before: completion/confidence were ungraded at `0/0`.
- Changed to: completion `86`, confidence `80`.
- Summary/evidence: the page documents dialog role, class and helper ownership, UI/audio dependencies, IDA evidence, generated owner pollution, and cross-references; confidence remains capped by helper ownership cleanup and generated `ChattingColorPane` pollution.
