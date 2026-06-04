*** UID:0000DZ | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000O5 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# StartupWindow

## Status

- Confidence: strong for class identity, WinMain entry points, vtable/singleton state, callback ownership, and static data references; medium-high for raw notice-helper boundaries.
- Likely source file: [UID:0000O5][StartupWindow](by-file/StartupWindow.md) / `NexusTK/app/StartupWindow.cpp`
- Address range: [UID:0001IO][0x005807d0-0x0058206e.StartupWindowUpdateCheck](by-memory/0x005807d0-0x0058206e.StartupWindowUpdateCheck.md)
- Rebuild handling: reconstructable class documentation attached to the file parent; final C++ remains blank because raw notice-helper boundaries and member names are not final-source quality.

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

## Live IDA Evidence

- IDA MCP on 2026-06-04 used IDB `C:\Users\admin\Desktop\Clone\NexusTK\NexusTK.exe`, MD5 `4247e04e20b65d6414c7238aa8ff5515`.
- Exact IDA function records: constructor `0x005807d0-0x0058080c`, `RunUpdateCheck` `0x00580870-0x005810fd`, WndProc `0x00581100-0x005815aa`, modeled notice helpers `0x00581660-0x005817dd`, curl/string/draw/destructor helpers `0x00581b80-0x0058206e`, and next StdioFile function at `0x00582070`.
- `_WinMain@16` is the only code caller for both constructor and `RunUpdateCheck`, at `0x004f5d3a` and `0x004f5d52`.
- Constructor disassembly/decompilation writes `dword_69BAC8 = this`, `*this = StartupWindow::vftable`, `byte_66DA97 = 1`, stores the startup `HINSTANCE` at `this + 8`, and clears bytes at `this + 4` and `this + 0x54`.
- The StartupWindow vtable slot at `0x0062d470` contains `0x00581d30`; xrefs to the slot come from constructor/destructor writes at `0x005807ed` and `0x00581d3a`, plus an adjacent constructor-gap write at `0x00580817`.
- WndProc pointer refs remain narrow: `xrefs_to 0x00581100` reports `0x005808e4` inside `RunUpdateCheck` and raw `0x005819fc` inside the alternate notice setup helper.
- Raw helper starts `0x005815b0`, `0x005817e0`, `0x00581860`, `0x005818d0`, and `0x005819d0` still have no IDA function objects but begin with function-shaped prologues (`55 8b ec ...`). The modeled WndProc-to-raw gap `0x005815aa-0x005815b0` and final aggregate gap `0x0058206e-0x00582070` are `0xcc` alignment.
- Button/draw helpers are tied to WndProc: `0x00581670` has two code refs from `0x00581100`, `0x00581730` has four WndProc refs plus one raw helper ref, `0x005817a0` has three WndProc refs, and `0x00581dc0` has two WndProc refs.
- Curl/string helpers remain startup-local: `0x00581b80` has only two callback-pointer refs inside `RunUpdateCheck` (`0x00580c6f`, `0x00580efb`), `0x00581cf0` has two `RunUpdateCheck` callers, `0x00581e40` has eight, and `0x00581f50` has two.
- Startup static data refs are narrow and class-owned: `word_69BAC4` has four refs from the update-check/raw setup paths, `dword_69BAC8` has constructor/WndProc/destructor refs, and notice string pointers `0x00670260`/`0x00670264` are referenced from `RunUpdateCheck` plus the raw setup helper.
- Read-only strings at `0x0062d418`, `0x0062d430`, `0x0062d474`, `0x0062d4f0`, and `0x0062d590` confirm the notice class/title, news URL, minimap hash-list URL, and base web URL used by this class.

## Cross-References

- [UID:0000O5][StartupWindow](by-file/StartupWindow.md)
- [UID:0001IO][0x005807d0-0x0058206e.StartupWindowUpdateCheck](by-memory/0x005807d0-0x0058206e.StartupWindowUpdateCheck.md)
- [UID:0000SW][g_useEpfAssets](by-global/g_useEpfAssets.md)
- [UID:0001RO][startup-update-notice-resources](by-resource/startup-update-notice-resources.md)
- [UID:0000HV][Browser](by-file/Browser.md)
- [UID:00008H][MiniMapVersionManager](by-class/MiniMapVersionManager.md)

## Changes

- 2026-06-04:
  - Before: scored `84/76`, reconstructability and parent attachment were blank, and the page still carried stale source-reference phrasing.
  - After: scored `86/84`, marked reconstructable, attached to [UID:0000O5][StartupWindow](by-file/StartupWindow.md), and replaced the evidence section with live IDA function/xref/raw-helper/vtable/string checks.
  - Why: current IDA evidence proves the class entry points, vtable, singleton/global state, WndProc/callback ownership, raw helper gap, and startup-local string helpers well enough for class-level reconstruction planning. Confidence remains below 90 because the raw helper starts in `0x005815b0-0x00581b7f` still need exact child-function promotion before final C++.

- Before: completion/confidence were unevaluated at `0/0`.
- Changed to: completion `84`, confidence `76`.
- Evidence: the page documents startup/update responsibility, constructor/update/window-proc/helper/destructor/curl ranges, key globals, resource links, WinMain callers, and raw helper boundary debt; confidence remains capped by unmodeled helper starts in `0x005815b0-0x00581b7f`.
