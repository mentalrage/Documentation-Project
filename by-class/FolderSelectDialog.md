*** UID:000059 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:74 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:82 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000JF | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
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
- Autogen parent: [UID:0000JF][FolderSelectDialog](by-file/FolderSelectDialog.md). C++ remains blank because callback type names, field names, and final control helper names are not final-source quality.

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

## Evidence Notes

- 2026-06-03 IDA MCP `lookup_funcs` reconfirmed the exact class island starts and sizes: constructor `0x004b1590` size `0x346`, command handler `0x004b1920` size `0xe0`, drive-list helper `0x004b1a00` size `0x105`, adjustor thunks `0x004b1b05` and `0x004b1b10` size `0xb`, and scalar deleting destructor `0x004b1b20` size `0x67`.
- 2026-06-03 IDA MCP caller checks show the constructor is reached from `0x0052986d` inside the music-control command handler and that selected-path helper `0x004b3090` is called from `0x004b197f` inside `OnCommand`; `0x004b1a00` and the scalar deleting destructor still have no direct code callers.
- 2026-06-03 IDA MCP callee checks show the constructor creates/uses `FolderTreePane` at `0x004b1b90`, calls Win32 `GetLogicalDrives`, and can navigate an initial path through `0x004b2730`. The command handler calls `0x004b3090` for selected-path construction, `0x004b25e0` for drive-root reset, callback/result helpers, and dialog close helpers.
- 2026-06-03 IDA MCP xrefs tie `FolderSelectDialog` vtables `0x0061a45c`, `0x0061a4bc`, and `0x0061a4ec` to constructor stores, unwind/cleanup stores, and destructor stores. The drive-root buffer `0x0066da88` is referenced by the constructor at `0x004b183f`/`0x004b185b` and by the drive helper at `0x004b1a8b`/`0x004b1aaa`.
- 2026-06-03 IDA MCP decompilation of `0x004b1920` confirms confirm/cancel callback dispatch through the function object at offset `0x270`, selected-path construction from `tree + 0x170`, and drive-list notification handling that copies the selected drive text before calling the folder-tree root reset helper.
- 2026-06-03 IDA MCP decompilation of `0x004b1a00` confirms drive enumeration with `GetLogicalDrives`, current-drive selection through `GetCurrentDirectoryA` and `_toupper`, rewriting `asc_66DA88[0]`, creating drive-list entries, and selecting the current drive.
- 2026-06-03 IDA MCP disassembly confirms the `0x004b1b05`/`0x004b1b10` thunks subtract `0xa0`/`0xa4` from `ecx` before jumping to `0x004b1b20`; the destructor restores three `FolderSelectDialog` vtables, destroys the callback at offset `0x270`, calls base teardown, and conditionally frees `this`.

## Cross-References

- [UID:0000JF][FolderSelectDialog](by-file/FolderSelectDialog.md)
- [UID:000154][0x004b1590-0x004b1b87.FolderSelectDialog](by-memory/0x004b1590-0x004b1b87.FolderSelectDialog.md)
- [UID:00005A][FolderTreePane](by-class/FolderTreePane.md)
- [UID:00008U][MusicControlDialog](by-class/MusicControlDialog.md)
- [UID:00027D][0x0066da88-0x0066da90.FolderSelectDriveRootBuffer](by-memory/0x0066da88-0x0066da90.FolderSelectDriveRootBuffer.md)

## Changes

- Completion/confidence score update: existed before as `0/0`; changed to `68/78`. Summary: dialog responsibility, control composition, method/helper ranges, and key field offsets are documented; exact field names and some base-destructor naming remain medium-confidence. Evidence: range `0x004b1590-0x004b1b87`, `FolderTreePane` relationship, and data notes for tree/callback offsets.
- 2026-06-03 MCP verification and parent attachment:
  - What existed before: the class remained unassigned at `68/78`; it documented the dialog role and key offsets but did not carry the later vtable, drive-buffer, callback, and thunk verification directly on the class page.
  - Changed to: `COMPLETION:74`, `CONFIDENCE:82`, `RECONSTRUCTABLE:TRUE`, and parent [UID:0000JF][FolderSelectDialog](by-file/FolderSelectDialog.md).
  - Summary/evidence: live IDA MCP lookup/caller/callee/xref/decompile/disassembly checks reconfirmed function boundaries, the MusicControlDialog constructor caller, selected-path callback flow, drive-list helper behavior, vtable xrefs, drive-root buffer xrefs, and destructor/adjustor thunk shape. C++ remains blank because final callback type names, fields, and helper names are below the 95+ reconstruction gate.
