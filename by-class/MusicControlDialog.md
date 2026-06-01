*** UID:00008U | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:80 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# MusicControlDialog

## Status

- Confidence: strong for class responsibility, medium for helper ownership cleanup.
- Likely source file: [UID:0000LN][MusicControlDialog](by-file/MusicControlDialog.md)
- Address range: [UID:0001CP][0x00528e60-0x0052a535.MusicControlDialog](by-memory/0x00528e60-0x0052a535.MusicControlDialog.md)
- Current recovered file: `source-3/simroot_v2/class_MusicControlDialog.cpp`

## Class Purpose

`MusicControlDialog` is the client music/sound settings dialog. It exposes sound-effect enablement, sample volume, playback enable/mode, stream volume, local music folder selection, CD drive selection, music behavior flags, previous/pause/next buttons, and close/accept behavior.

The object is a `DialogPane`-style UI class of size `0x270` (`624`) in current Wave3 struct data. The only clearly named local field so far is the pause-state byte at offset `0x26c`, used by `TogglePauseState` and the playback-state helper.

## Method Notes

| Method or helper | Address | Role |
| --- | --- | --- |
| constructor | `0x00528e60-0x0052976c` | Builds `DLGSCNTL.EPF` controls, enumerates CD drives, initializes values from config and `SoundManager`, and queues packet `0x11b`. |
| non-deleting destructor helper | `0x00529770-0x0052978f` | Resets vtables and tears down the base dialog; IDA-confirmed, not modeled by Wave3 method lookup. |
| `HandleControlCommand` | `0x00529790-0x00529b2e` | Handles control ids `1..14` for SFX, volumes, playback modes, folder dialog, drive menu, previous/pause/next, and close. |
| music settings packet handler | `0x00529be0-0x00529c5a` | Vtable-backed handler that reads a packet-like buffer and applies sound-effect enablement. IDA-confirmed, not modeled by Wave3. |
| secondary packet/helper handler | `0x00529c60-0x00529cf8` | Vtable-backed handler that recognizes tag `0x42446972`, converts a narrow string when present, and clears a global pending flag. IDA-confirmed, not modeled by Wave3. |
| `RefreshControlStates` | `0x00529d00-0x00529ed1` | Enables/disables controls based on sound-effect, playback, and music-mode selections. |
| folder path selected/input helper | `0x00529ee0-0x0052a00c` | Stores the selected music path, updates control id `6`, rescans music directory, and reapplies playback state. Currently Wave3-owned by `ChattingColorPane`. |
| drive menu population helper | `0x0052a010-0x0052a120` | Enumerates CD drives `A:` through `Z:` and populates control id `8`; IDA-confirmed, not modeled by Wave3. |
| `ApplyMusicPlaybackState` | `0x0052a120-0x0052a17f` | Applies config playback mode to stream/Redbook/zone playback. Currently Wave3-owned by `ChattingColorPane`. |
| `TogglePauseState` | `0x0052a180-0x0052a1e9` | Toggles offset `0x26c`, pauses stream or Redbook playback, retrieves control id `12`, and updates pause/play icon ids `37`/`48` through [UID:00011D][0x00495cb0-0x00495cc9.SelectionControlPaneSetSelectionAndRefresh](by-memory/0x00495cb0-0x00495cc9.SelectionControlPaneSetSelectionAndRefresh.md). |
| `ApplyMusicEnabledSelection` | `0x0052a2d0-0x0052a304` | Applies sound-effect enabled/disabled state to config and `SoundManager`; IDA-confirmed, not modeled by Wave3. |
| playback-output selection helper | `0x0052a310-0x0052a3e0` | Applies playback output selection and raises localized alert `244` when needed; IDA-confirmed, not modeled by Wave3. |
| [UID:0000AL][PlainMemberFunctionObjectT_void____thiscall_MusicControlDialog_____class_m__h73bc206d7ae6](by-class/PlainMemberFunctionObjectT_void____thiscall_MusicControlDialog_____class_m__h73bc206d7ae6.md) | `0x0052a3e0-0x0052a4de` | Template function-object invoke/destructor support for the [UID:0000JF][FolderSelectDialog](by-file/FolderSelectDialog.md) callback. |
| scalar deleting destructor | `0x0052a4e0-0x0052a535` | Resets vtables, destroys base dialog state, and conditionally deletes. |

## Data Notes

- `g_pConfig + 0x291908` stores music playback mode.
- `g_pConfig + 0x29190c` stores the selected local music path/device name string.
- `g_pConfig + 0x291910` stores selected Redbook drive id.
- `g_pConfig + 0x291912` and `+0x291913` are option flags used by controls `9` and `10`.
- `g_pConfig + 0x291914` stores the playback output/toggle mode used by control `3`.
- `g_pConfig + 0x28de48` is touched by SFX enablement helpers, but the config field name remains provisional.
- Control id `12` is the pause/play selection control. `TogglePauseState` passes icon/frame ids `37` and `48` into [UID:0000CR][SelectionControlPane](by-class/SelectionControlPane.md), whose selected-value field lives at offset `+0x10c` in the control object.

## Evidence Notes

- Wave3 reports only five `MusicControlDialog` methods, while IDA confirms additional starts in the same vtable/function island.
- `ApplyMusicPlaybackState` has only two IDA callers: `0x00529790` and `0x00529ee0`; both are music-dialog paths.
- The folder callback object stores a `MusicControlDialog` owner pointer and a member-function pointer target. The reusable template declarations belong with [UID:0000JO][FunctionObjects](by-file/FunctionObjects.md), while this class owns the selected-path handler and callback setup.

## Cross-References

- [UID:0000LN][MusicControlDialog](by-file/MusicControlDialog.md)
- [UID:0001CP][0x00528e60-0x0052a535.MusicControlDialog](by-memory/0x00528e60-0x0052a535.MusicControlDialog.md)
- [UID:0000DG][SoundManager](by-class/SoundManager.md)
- [UID:0000JF][FolderSelectDialog](by-file/FolderSelectDialog.md)
- [UID:0000JO][FunctionObjects](by-file/FunctionObjects.md)
- [UID:0000CR][SelectionControlPane](by-class/SelectionControlPane.md)
- [UID:00011D][0x00495cb0-0x00495cc9.SelectionControlPaneSetSelectionAndRefresh](by-memory/0x00495cb0-0x00495cc9.SelectionControlPaneSetSelectionAndRefresh.md)

## Changes

- Completion/confidence score update: existed before as `0/0`; changed to `86/80`. Summary: the music/sound settings dialog is documented in high detail across constructor, controls, config offsets, SoundManager/CD/folder behavior, callback template, helper ownership, and generated ownership caveats, but confidence stays medium-high because some helper ownership cleanup and field names remain provisional. Evidence: linked `MusicControlDialog` memory range, IDA-confirmed additional starts, control-id method table, config offset notes, callback wrapper class, and `SelectionControlPaneSetSelectionAndRefresh` reference.
