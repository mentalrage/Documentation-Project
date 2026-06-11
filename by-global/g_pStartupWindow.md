*** UID:0002ZS | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000O5 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# g_pStartupWindow

## Status

- Address: `0x0069bac8`
- Storage page: [UID:0002ZT][0x0069bac8-0x0069bacc.g_pStartupWindow](by-memory/0x0069bac8-0x0069bacc.g_pStartupWindow.md)
- Type hypothesis: `StartupWindow *`.
- Owner: [UID:0000O5][StartupWindow](by-file/StartupWindow.md)

## Evidence

The exact memory storage is the final dword in [UID:0002AM][0x0069bac4-0x0069bacc.StartupWindowUpdateStateGlobals](by-memory/0x0069bac4-0x0069bacc.StartupWindowUpdateStateGlobals.md). [UID:0001IO][0x005807d0-0x0058206e.StartupWindowUpdateCheck](by-memory/0x005807d0-0x0058206e.StartupWindowUpdateCheck.md) records constructor decompilation at `0x005807d0` writing `dword_69BAC8 = this` after installing the `StartupWindow` vtable and startup state. The same page records WndProc/destructor use: the notice WndProc reads the singleton around `0x00581114`, and the scalar deleting destructor clears it around `0x00581d94`.

[UID:0000DZ][StartupWindow](by-class/StartupWindow.md) independently records this as narrow class-owned static data, with constructor, WndProc, and destructor refs in the StartupWindow range.

## Assignment Gate

Assigned to [UID:0000O5][StartupWindow](by-file/StartupWindow.md) after the file page reached `87/85`. The relationship is direct because this is the StartupWindow singleton pointer storage for the notice/update object, and the adjacent string-buffer pools start only at `0x0069bacc`.

## Cross-References

- [UID:0000O5][StartupWindow](by-file/StartupWindow.md)
- [UID:0000DZ][StartupWindow](by-class/StartupWindow.md)
- [UID:0001IO][0x005807d0-0x0058206e.StartupWindowUpdateCheck](by-memory/0x005807d0-0x0058206e.StartupWindowUpdateCheck.md)
- [UID:0002AM][0x0069bac4-0x0069bacc.StartupWindowUpdateStateGlobals](by-memory/0x0069bac4-0x0069bacc.StartupWindowUpdateStateGlobals.md)
- [UID:0002ZT][0x0069bac8-0x0069bacc.g_pStartupWindow](by-memory/0x0069bac8-0x0069bacc.g_pStartupWindow.md)

## Changes

- 2026-06-07 A003 Batch 055: created as the canonical global page for the `0x0069bac8` StartupWindow singleton-pointer split from [UID:0002AM][0x0069bac4-0x0069bacc.StartupWindowUpdateStateGlobals](by-memory/0x0069bac4-0x0069bacc.StartupWindowUpdateStateGlobals.md).
