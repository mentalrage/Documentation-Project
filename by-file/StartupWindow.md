*** UID:0000O5 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:87 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:85 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"NexusTK/app/" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***

# StartupWindow

## Status

- Confidence: strong for class responsibility, startup global ownership, and update-notice entry points; medium-high for helper boundary cleanup.
- Proposed module: `app/StartupWindow.cpp`
- Current recovered source: `class_StartupWindow.cpp`
- Main class: [UID:0000DZ][StartupWindow](by-class/StartupWindow.md)
- Main address doc: [UID:0001IO][0x005807d0-0x0058206e.StartupWindowUpdateCheck](by-memory/0x005807d0-0x0058206e.StartupWindowUpdateCheck.md)
- Related resources: [UID:0001RO][startup-update-notice-resources](by-resource/startup-update-notice-resources.md)
- Evidence basis: generated `simroot_v2` source and IDA MCP boundary/xref/disassembly checks on 2026-05-24, 2026-05-25, and 2026-05-26. `wave3.py` was not executed for this pass.

## File Role

`StartupWindow.cpp` owns the pre-game update notice window shown from `_WinMain@16` before the normal application startup path continues. It creates the small notice HWND, embeds the browser/news panel, fetches update metadata with libcurl, checks the stored update version in the registry, refreshes minimap hash data when needed, and returns whether the external updater path should be launched.

This file is app/startup code. It depends on [UID:0000HV][Browser](by-file/Browser.md), [UID:00008H][MiniMapVersionManager](by-class/MiniMapVersionManager.md), [UID:0000K3][ImageLoaders](by-file/ImageLoaders.md), and Win32 APIs, but should not own those implementations.

## Proposed Contents

| Entity | Address evidence | Role |
| --- | --- | --- |
| `StartupWindow` | `0x005807d0-0x0058080c`, `0x00580870-0x005810fd`, `0x00581100-0x005815aa`, `0x00581d30-0x00581db2` | Constructor, update-check driver, notice WndProc, scalar deleting destructor. |
| notice button helpers | `0x005815b0-0x005817dd` | Raw/IDA-partial helpers for button state, hit testing, reset/invalidations, and update/close post-message behavior. |
| notice asset loader helper | `0x005818d0-0x005819c9` | Raw helper that loads `brm_*.pcx` resources and initializes button bounds. IDA has code bytes but no function object. |
| alternate notice registration helper | `0x005819d0` onward | Raw helper that registers a class using `StartupWindow::UpdateCheckWindowProc`; exact end still needs boundary review. |
| curl/string helpers | `0x00581b80-0x0058206e` | [UID:0001IP][0x00581b80-0x00581ce6.CurlWriteCallback](by-memory/0x00581b80-0x00581ce6.CurlWriteCallback.md) and narrow/wide string parse helpers used by update JSON and minimap hash-list parsing. |
| globals | [UID:0002ZS][g_pStartupWindow](by-global/g_pStartupWindow.md), [UID:0002ZQ][g_startupWindowClassAtom](by-global/g_startupWindowClassAtom.md), `g_startupUpdateNoticeState`, `g_szBaramNoticeWndClass`, `g_szNoticeTitle`, [UID:0000SW][g_useEpfAssets](by-global/g_useEpfAssets.md) | Startup-window singleton, window-class atom, notice state, notice strings, and asset-mode state. |

## Evidence Notes

- IDA xrefs show `StartupWindow::StartupWindow` and `StartupWindow::RunUpdateCheck` are both called only from `_WinMain@16`.
- `RunUpdateCheck` registers class `BaramNoticeWndClass`, creates a 500 by 430 notice window, constructs a `BrowserWindow` for `http://www.nexustk.com/news/news.asp`, then fetches `https://s3.amazonaws.com/kru-downloads/tk/update/nexustk.ver`.
- The registry path is `Software\KRU\NexusTK`, value `updvr`, under `HKEY_CURRENT_USER`.
- If the remote minimap version differs from [UID:00008H][MiniMapVersionManager](by-class/MiniMapVersionManager.md), `RunUpdateCheck` fetches `https://s3.amazonaws.com/kru-downloads/tk/minimaps/HashList.txt`, decodes it through [UID:0000L6][MD5](by-file/MD5.md) at `0x00515290`, and calls `MiniMapVersionManager::UpdateHashList`.
- `UpdateCheckWindowProc` handles keyboard accept/cancel, first-paint asset loading, PCX drawing, button hit testing, cursor changes, the top web-link rectangle, and update/close `WM_USER + 11` posts.
- IDA `xrefs_to 0x00581b80` reports callback-pointer data refs at `0x00580c6f` and `0x00580efb` inside `RunUpdateCheck`, while normal caller lookup reports no direct callers. This matches libcurl write callback use.
- IDA caller checks for helpers `0x00581cf0`, `0x00581e40`, and `0x00581f50` currently tie the ANSI parse helpers only to `RunUpdateCheck`.
- IDA decompilation of the constructor at `0x005807d0` writes [UID:0000SW][g_useEpfAssets](by-global/g_useEpfAssets.md) / historical IDA alias `byte_66DA97 = 1`, forcing the current startup path into EPF/current-layout mode.
- 2026-05-25 IDA MCP recheck reconfirmed the callback setup sites as `curl_easy_setopt` calls that push `offset sub_581B80` with option `0x4e2b`.
- 2026-05-26 IDA MCP recheck reconfirmed `0x00581b80` as a real `0x166`-byte function, still with only the two `RunUpdateCheck` callback-pointer refs and no formal callers. The adjacent parse/string helpers still call only from `RunUpdateCheck`.
- 2026-06-07 A003 Batch 055 documentation split records the writable startup global cluster [UID:0002AM][0x0069bac4-0x0069bacc.StartupWindowUpdateStateGlobals](by-memory/0x0069bac4-0x0069bacc.StartupWindowUpdateStateGlobals.md) as three exact child ranges: [UID:0002ZR][0x0069bac4-0x0069bac6.g_startupWindowClassAtom](by-memory/0x0069bac4-0x0069bac6.g_startupWindowClassAtom.md), [UID:0002ZU][0x0069bac6-0x0069bac8.StartupWindowUpdateStateReservedWord](by-memory/0x0069bac6-0x0069bac8.StartupWindowUpdateStateReservedWord.md), and [UID:0002ZT][0x0069bac8-0x0069bacc.g_pStartupWindow](by-memory/0x0069bac8-0x0069bacc.g_pStartupWindow.md). The live word/dword children match the `RunUpdateCheck`, raw setup, constructor, WndProc, and destructor refs already documented by [UID:0001IO][0x005807d0-0x0058206e.StartupWindowUpdateCheck](by-memory/0x005807d0-0x0058206e.StartupWindowUpdateCheck.md) and [UID:0000DZ][StartupWindow](by-class/StartupWindow.md).

## Ownership Notes

Keep browser hosting in [UID:0000HV][Browser](by-file/Browser.md): `StartupWindow` constructs and destroys `BrowserWindow`, but browser COM/OLE lifetime helpers are browser-owned.

Keep minimap hash ownership in [UID:00008H][MiniMapVersionManager](by-class/MiniMapVersionManager.md): `StartupWindow` fetches remote version/hash-list data, but the persisted hash map belongs to the minimap manager.

Keep PCX decoding in [UID:0000K3][ImageLoaders](by-file/ImageLoaders.md): the startup notice is a confirmed caller of `LoadPcxImage`, but the loader is a render/resource helper.

Keep MD5 helpers in [UID:0000L6][MD5](by-file/MD5.md): startup consumes the string hash wrapper but does not own the shared hash implementation.

Keep [UID:0000UA][CurlWriteCallback_00581B80](by-item/CurlWriteCallback_00581B80.md) in this module as private startup/libcurl glue. Do not migrate it into a third-party libcurl source folder; it appends text response data into the startup updater's ANSI small-string buffer.

## Cross-References

- [UID:0000DZ][StartupWindow](by-class/StartupWindow.md)
- [UID:0001IO][0x005807d0-0x0058206e.StartupWindowUpdateCheck](by-memory/0x005807d0-0x0058206e.StartupWindowUpdateCheck.md)
- [UID:0000SW][g_useEpfAssets](by-global/g_useEpfAssets.md)
- [UID:0001RO][startup-update-notice-resources](by-resource/startup-update-notice-resources.md)
- [UID:0000L6][MD5](by-file/MD5.md)
- [UID:0001QM][client_s1-startup](by-meta/client_s1-startup.md)
- [UID:0001QE][client_libraries](by-meta/client_libraries.md)
- [UID:0000VI][StartupWindowUnmodeledNoticeHelpers_5815b0_581b7f](by-item/StartupWindowUnmodeledNoticeHelpers_5815b0_581b7f.md)
- [UID:0000UA][CurlWriteCallback_00581B80](by-item/CurlWriteCallback_00581B80.md)
- [UID:0001IP][0x00581b80-0x00581ce6.CurlWriteCallback](by-memory/0x00581b80-0x00581ce6.CurlWriteCallback.md)
- [UID:0002AM][0x0069bac4-0x0069bacc.StartupWindowUpdateStateGlobals](by-memory/0x0069bac4-0x0069bacc.StartupWindowUpdateStateGlobals.md)
- [UID:0002ZS][g_pStartupWindow](by-global/g_pStartupWindow.md)
- [UID:0002ZQ][g_startupWindowClassAtom](by-global/g_startupWindowClassAtom.md)

## Changes

- 2026-06-07 A003 Batch 055 parent-gate refresh:
  - Before: file score was `86/80`, below the corrected `85/85` direct-parent gate for startup global-data assignment.
  - Changed to: `COMPLETION:87`, `CONFIDENCE:85`.
  - Evidence: added the exact writable startup global split and linked the atom/singleton storage back to already documented `RunUpdateCheck`, raw setup, constructor, WndProc, and destructor refs. Confidence remains capped below 90 because the raw notice-helper island still needs exact child function promotion, but file-level ownership of the startup globals is now directly documented well enough for the corrected gate.
- 2026-06-07 A008 alias cleanup:
  - Before: the constructor evidence line used a bare `byte_66DA97 = 1` alias for the startup asset-mode write.
  - Changed to: canonical [UID:0000SW][g_useEpfAssets](by-global/g_useEpfAssets.md) wording with `byte_66DA97` retained as the historical IDA alias.
  - Evidence: constructor decompilation still forces the current startup path into EPF/current-layout mode.
- 2026-05-30: Scored documentation completeness/confidence.
  - Before: completion/confidence metadata was ungraded at `0/0`.
  - After: set completion to `86` and confidence to `80`.
  - Evidence: document covers update-window role, proposed contents, Win32/browser/curl/minimap behavior, global dependencies, IDA xrefs and callback evidence, ownership boundaries, and cross-references; confidence is capped by helper boundary cleanup around the notice helper range.
