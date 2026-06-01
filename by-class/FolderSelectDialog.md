*** UID:000059 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:68 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:78 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# FolderSelectDialog

## Status

- Confidence: strong for class responsibility; medium for field names.
- Likely source file: [UID:0000JF][FolderSelectDialog](by-file/FolderSelectDialog.md)
- Address range: [UID:000154][0x004b1590-0x004b1b87.FolderSelectDialog](by-memory/0x004b1590-0x004b1b87.FolderSelectDialog.md)
- Current recovered file: `source-3/simroot_v2/class_FolderSelectDialog.cpp`
- Current size: `0x274` (`628`) bytes in Wave3/Ghidra struct data.

## Class Purpose

`FolderSelectDialog` is a `DialogPane`-derived modal folder picker. It creates a drive-list control, a [UID:00005A][FolderTreePane](by-class/FolderTreePane.md), OK/cancel image buttons, and a callback result path used by the music settings dialog.

## Method Notes

| Method or helper | Address | Role |
| --- | --- | --- |
| constructor | `0x004b1590-0x004b18d6` | Builds controls, creates the `FolderTreePane`, populates drives, selects current drive, and optionally navigates to the initial path. |
| `OnCommand` | `0x004b1920-0x004b1a00` | Handles drive-list notifications and confirm/cancel callback dispatch. |
| drive-list helper | `0x004b1a00-0x004b1b05` | Real IDA function for drive enumeration; not active in current Wave3 method list. |
| secondary thunk | `0x004b1b05-0x004b1b10` | Disabled/missing Wave3 code; IDA recognizes a tiny function. |
| scalar-deleting destructor thunk | `0x004b1b10-0x004b1b1b` | Adjustor thunk into the deleting destructor. |
| scalar-deleting destructor | `0x004b1b20-0x004b1b87` | Destroys callback, tears down base dialog, conditionally deletes. |

## Data Notes

- `DialogPane` is embedded at offset `0x000`.
- The tree pane pointer is at offset `0x26c` in generated source evidence.
- The callback/function object pointer is at offset `0x270`.
- The generated destructor labels the base teardown as `TransferReplyAlert::~DialogPane`; treat that as base-owner pollution until the shared dialog destructor is named cleanly.

## Cross-References

- [UID:0000JF][FolderSelectDialog](by-file/FolderSelectDialog.md)
- [UID:000154][0x004b1590-0x004b1b87.FolderSelectDialog](by-memory/0x004b1590-0x004b1b87.FolderSelectDialog.md)
- [UID:00005A][FolderTreePane](by-class/FolderTreePane.md)
- [UID:00008U][MusicControlDialog](by-class/MusicControlDialog.md)

## Changes

- Completion/confidence score update: existed before as `0/0`; changed to `68/78`. Summary: dialog responsibility, control composition, method/helper ranges, and key field offsets are documented; exact field names and some base-destructor naming remain medium-confidence. Evidence: range `0x004b1590-0x004b1b87`, `FolderTreePane` relationship, and data notes for tree/callback offsets.
