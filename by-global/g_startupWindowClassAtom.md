*** UID:0002ZQ | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:87 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000O5 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# g_startupWindowClassAtom

## Status

- Address: `0x0069bac4`
- Storage page: [UID:0002ZR][0x0069bac4-0x0069bac6.g_startupWindowClassAtom](by-memory/0x0069bac4-0x0069bac6.g_startupWindowClassAtom.md)
- Type hypothesis: Win32 `ATOM` / registered notice-window class atom.
- Owner: [UID:0000O5][StartupWindow](by-file/StartupWindow.md)

## Evidence

The exact memory storage is the first word in [UID:0002AM][0x0069bac4-0x0069bacc.StartupWindowUpdateStateGlobals](by-memory/0x0069bac4-0x0069bacc.StartupWindowUpdateStateGlobals.md). Existing IDA evidence on the startup executable range records four refs to `word_69BAC4`: two from `StartupWindow::RunUpdateCheck` at `0x00580a57` and `0x00580a6e`, and two from the raw alternate setup path at `0x00581af4` and `0x00581b08`.

[UID:0001IO][0x005807d0-0x0058206e.StartupWindowUpdateCheck](by-memory/0x005807d0-0x0058206e.StartupWindowUpdateCheck.md) ties those refs to the notice-window class registration/check path. [UID:0000DZ][StartupWindow](by-class/StartupWindow.md) records the same static-data owner and keeps this atom with the startup/update notice class.

## Assignment Gate

Assigned to [UID:0000O5][StartupWindow](by-file/StartupWindow.md) after the file page reached `87/85`. The relationship is direct because this atom is file-local StartupWindow notice-window registration state; it is not a neighboring packet-transform or string-buffer pool global.

## Cross-References

- [UID:0000O5][StartupWindow](by-file/StartupWindow.md)
- [UID:0000DZ][StartupWindow](by-class/StartupWindow.md)
- [UID:0001IO][0x005807d0-0x0058206e.StartupWindowUpdateCheck](by-memory/0x005807d0-0x0058206e.StartupWindowUpdateCheck.md)
- [UID:0002AM][0x0069bac4-0x0069bacc.StartupWindowUpdateStateGlobals](by-memory/0x0069bac4-0x0069bacc.StartupWindowUpdateStateGlobals.md)
- [UID:0002ZR][0x0069bac4-0x0069bac6.g_startupWindowClassAtom](by-memory/0x0069bac4-0x0069bac6.g_startupWindowClassAtom.md)

## Changes

- 2026-06-07 A003 Batch 055: created as the canonical global page for the `0x0069bac4` StartupWindow notice-class atom split from [UID:0002AM][0x0069bac4-0x0069bacc.StartupWindowUpdateStateGlobals](by-memory/0x0069bac4-0x0069bacc.StartupWindowUpdateStateGlobals.md).
