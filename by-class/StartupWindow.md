*** UID:0000DZ | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:76 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# StartupWindow

## Status

- Confidence: strong for high-level behavior; medium for helper function boundaries.
- Likely source file: [UID:0000O5][StartupWindow](by-file/StartupWindow.md)
- Address range: [UID:0001IO][0x005807d0-0x0058206e.StartupWindowUpdateCheck](by-memory/0x005807d0-0x0058206e.StartupWindowUpdateCheck.md)
- Current recovered file: `source-3/simroot_v2/class_StartupWindow.cpp`

## Class Purpose

`StartupWindow` is the pre-game update/news notice object. It runs before the main `Application::Startup` path, displays a browser-backed notice window, checks the remote update version with libcurl, refreshes minimap hash data, and reports whether the updater should run or the game can continue.

## Method Notes

| Method or helper | Address | Role |
| --- | --- | --- |
| constructor | `0x005807d0-0x0058080c` | Stores singleton pointer, installs vtable, sets EPF/asset mode, stores `HINSTANCE`, clears state flags. |
| `RunUpdateCheck` | `0x00580870-0x005810fd` | Creates notice HWND/browser, queries registry, performs libcurl update/minimap fetches, runs modal message loop, cleans up, returns update decision. |
| `UpdateCheckWindowProc` | `0x00581100-0x005815aa` | Handles keyboard, paint, mouse, cursor, link, and update/close button behavior for the notice window. |
| notice click helper | `0x005815b0-0x00581657` | Raw helper that posts update/close messages and updates close-button visual state; not an IDA function object yet. |
| state access/helper | `0x00581660-0x005817dd` | IDA-confirmed tiny accessor plus reset/set/hit-test helpers for the two notice buttons. |
| notice asset helper | `0x005818d0-0x005819c9` | Raw helper that lazily loads `brm_main.pcx`, `brm_st_*.pcx`, and `brm_ex_*.pcx`, then initializes button rectangles. |
| scalar deleting destructor | `0x00581d30-0x00581db2` | Releases owned child/browser-like objects when initialized, clears singleton, and optionally deletes. |
| curl/string helpers | `0x00581b80-0x0058206e` | Curl response append callback and string helpers used by `RunUpdateCheck`. |

## Data Notes

- `g_pStartupWindow` stores the live singleton pointer.
- `g_startupWindowClassAtom` caches the registered notice window class.
- `g_startupUpdateNoticeState` points to the notice-state structure used by `UpdateCheckWindowProc`.
- `g_szBaramNoticeWndClass` and `g_szNoticeTitle` are ANSI window-class/title strings.
- [UID:0000SW][g_useEpfAssets](by-global/g_useEpfAssets.md) / `byte_66DA97` is forced to `1` by the constructor.

## Evidence Notes

- IDA reports direct constructor and `RunUpdateCheck` calls from `_WinMain@16`.
- IDA MCP decompilation of the constructor at `0x005807d0` shows `byte_66DA97 = 1`; this is the broad EPF/current-layout selector documented as [UID:0000SW][g_useEpfAssets](by-global/g_useEpfAssets.md).
- `UpdateCheckWindowProc` has a data xref from the `WNDCLASSEXA` setup inside `RunUpdateCheck` and another raw data xref at `0x005819fc`.
- IDA does not currently model several obvious code starts in `0x005815b0-0x00581b7f`; these should be treated as boundary/data debt before source migration.
- 2026-05-26 IDA MCP recheck still ties the curl write callback `0x00581b80` and parse/string helpers `0x00581cf0`, `0x00581e40`, and `0x00581f50` to `StartupWindow::RunUpdateCheck` only. Keep them with this startup/update module unless future caller evidence expands their ownership.

## Cross-References

- [UID:0000O5][StartupWindow](by-file/StartupWindow.md)
- [UID:0001IO][0x005807d0-0x0058206e.StartupWindowUpdateCheck](by-memory/0x005807d0-0x0058206e.StartupWindowUpdateCheck.md)
- [UID:0000SW][g_useEpfAssets](by-global/g_useEpfAssets.md)
- [UID:0001RO][startup-update-notice-resources](by-resource/startup-update-notice-resources.md)
- [UID:0000HV][Browser](by-file/Browser.md)
- [UID:00008H][MiniMapVersionManager](by-class/MiniMapVersionManager.md)

## Changes

- Before: completion/confidence were unevaluated at `0/0`.
- Changed to: completion `84`, confidence `76`.
- Evidence: the page documents startup/update responsibility, constructor/update/window-proc/helper/destructor/curl ranges, key globals, resource links, WinMain callers, and raw helper boundary debt; confidence remains capped by unmodeled helper starts in `0x005815b0-0x00581b7f`.
