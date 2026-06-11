*** UID:0000D2 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000NO | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# ServerSelectPane

## Status

- Confidence: strong for main class role and IDA-confirmed boundaries.
- Likely source file: [UID:0000NO][ServerSelectPane](by-file/ServerSelectPane.md)
- Current recovered file: `source-3/simroot_v2/class_ServerSelectPane.cpp`
- Address range: [UID:0001HR][0x00573d20-0x005747df.ServerSelectPane](by-memory/0x00573d20-0x005747df.ServerSelectPane.md)

## Class Purpose

`ServerSelectPane` is the pre-login dialog for selecting a game server. It builds the `DLGSERV` background, OK/cancel image buttons, a scrollable `ServerSelectMenuItemList`, and selects the previously configured server when high-resolution layout is enabled.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| `ServerSelectPane` | `0x00573d20-0x00574300` | Builds the classic or EPF server-select dialog, creates the list pane, adds rows from server data, selects the configured server, and opens the dialog. |
| Non-deleting destructor-like helper | `0x00574310-0x00574338` | Resets vtables, clears [UID:0000S8][g_pServerSelectPane](by-global/g_pServerSelectPane.md), and jumps to base teardown; not currently modeled by Wave3. |
| `OnDialogAction` | `0x00574340-0x00574430` | Handles OK/cancel; OK calls the server-selection helper pair and creates a screen-dimmer transition before closing. |
| `UpdateScrollButtons` | `0x00574440-0x00574496` | Enables/disables scroll/action controls based on list enabled-entry count. |
| Adjustor thunks | `0x0057475b-0x00574770` | Compiler-generated thunks forwarding to the scalar deleting destructor. |
| Singleton clear helper | `0x00574750-0x0057475a` | Clears [UID:0000S8][g_pServerSelectPane](by-global/g_pServerSelectPane.md) without running the full destructor. |
| `ScalarDeletingDestructor` | `0x00574780-0x005747df` | Clears [UID:0000S8][g_pServerSelectPane](by-global/g_pServerSelectPane.md), destroys the base dialog pane, and conditionally frees memory. |

## Evidence Notes

- Wave3 effective grade is `95.8`, with auto grade note about control characters in the stored destructor method name.
- IDA MCP confirms the listed function starts and ends.
- Constructor has a direct caller at `0x004f70db`, in the pre-login/main-menu region.
- `OnDialogAction` calls the server-selection helper currently modeled by Wave3 as `ChattingColorListPane::ApplySelectedColor`; this is documented as data owner pollution.
- 2026-05-24 IDA MCP decompilation confirms `0x00574510` copies the selected server name into the config/current-server buffer and calls `0x005745b0`; `0x005745b0` sends the `0x57` select-server packet and stores selected endpoint/session state.
- `xrefs_to 0x0069b4ac` ties the active-pane singleton to main-menu cleanup/startup and the `ServerSelectPane` constructor/destructor family.
- 2026-06-01 live IDA MCP recheck confirms `0x00574750` as a tiny singleton-clear helper and the scalar deleting destructor as `0x00574780-0x005747df`, with `0x005747df-0x005747e0` as one-byte `0xcc` padding before the next socket lifecycle function.

## Cross-References

- [UID:0000NO][ServerSelectPane](by-file/ServerSelectPane.md)
- [UID:0001HR][0x00573d20-0x005747df.ServerSelectPane](by-memory/0x00573d20-0x005747df.ServerSelectPane.md)
- [UID:0000D1][ServerSelectMenuItemList](by-class/ServerSelectMenuItemList.md)
- [UID:0000VG][ServerSelectHelpers_574510_5745b0](by-item/ServerSelectHelpers_574510_5745b0.md)
- [UID:0000S8][g_pServerSelectPane](by-global/g_pServerSelectPane.md)
- [UID:0000L0][MainMenuPane](by-file/MainMenuPane.md)

## Changes

- 2026-06-05: Changed `RECONSTRUCTABLE` from blank to `TRUE` and assigned parent `0000NO`.
  - Before: The pre-login server-selection dialog remained unclassified in autogen coverage even though the class and parent file both met the 80/80 attach gate.
  - After: The class contributes to `ServerSelectPane.cpp` as a reconstructable child without emitting final C++ yet.
  - Evidence: Live IDA MCP lookup confirms constructor/action/update/destructor-family starts at `0x00573d20`, `0x00574310`, `0x00574340`, `0x00574440`, `0x00574750`, `0x0057475b`, `0x00574766`, and `0x00574780`; parent [UID:0000NO][ServerSelectPane](by-file/ServerSelectPane.md) owns the pre-login server-selection module.

- Before: completion/confidence were unevaluated at `0/0`.
- Changed to: completion `86`, confidence `88`.
- Evidence: the page documents the pre-login dialog role, file ownership, main range, constructor/destructor/action/update/destructor-thunk map, caller/xref evidence, singleton, and helper-pollution caveat; remaining completion gap is source-ready reconstruction detail.
