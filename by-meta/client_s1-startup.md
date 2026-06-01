*** UID:0001QM | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:-1 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:-1 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***

# Client S1 Startup

## Status

- Confidence: medium; this is a working startup-flow index, not full coverage yet.
- Scope: process launch through the point where the normal application startup/login flow begins.

## Startup Sequence

1. [UID:00019G][0x004f5c80-0x004f5f17.WinMain](by-memory/0x004f5c80-0x004f5f17.WinMain.md) constructs the application shell and startup support objects.
2. `_WinMain@16` constructs [UID:00008H][MiniMapVersionManager](by-class/MiniMapVersionManager.md) and loads the local minimap hash/version state.
3. `_WinMain@16` constructs [UID:0000O5][StartupWindow](by-file/StartupWindow.md) and calls `StartupWindow::RunUpdateCheck`.
4. `StartupWindow::RunUpdateCheck` shows a pre-game notice window with embedded browser/news content and queries remote update metadata.
5. If the remote game version differs from the registry `updvr` value, startup returns the update-required state so the external updater path can run.
6. If the game can continue, the normal [UID:0000HG][Application](by-file/Application.md) startup path preloads [UID:0001R6][application-startup-dat-archives](by-resource/application-startup-dat-archives.md), constructs the client subsystems including [UID:0000KK][LanguageMan](by-file/LanguageMan.md), and proceeds toward the login/main-menu UI.

## StartupWindow Update Phase

[UID:0000O5][StartupWindow](by-file/StartupWindow.md) is the pre-game update and news notice. It:

- creates a 500 by 430 notice HWND using class `BaramNoticeWndClass`;
- embeds a `BrowserWindow` that navigates to `http://www.nexustk.com/news/news.asp`;
- reads `HKEY_CURRENT_USER\Software\KRU\NexusTK\updvr`;
- fetches `https://s3.amazonaws.com/kru-downloads/tk/update/nexustk.ver` with libcurl;
- parses at least the `version` and `minimap` keys;
- fetches `https://s3.amazonaws.com/kru-downloads/tk/minimaps/HashList.txt` when minimap data is stale;
- forwards minimap updates to `MiniMapVersionManager::UpdateHashList`.

The notice window uses PCX resources documented in [UID:0001RO][startup-update-notice-resources](by-resource/startup-update-notice-resources.md).

## Application DAT Archive Phase

[UID:0000HG][Application](by-file/Application.md) loads required and optional DAT archives before most higher-level managers are constructed. The inventory is documented in [UID:0001R6][application-startup-dat-archives](by-resource/application-startup-dat-archives.md):

- `Application::Application` loads `DATA/BARAMST.DAT`.
- `Application::Initialize` loads fixed required DAT files such as `DATA/MISC.DAT`, `DATA/CHAR.DAT`, `DATA/TILE.DAT`, `DATA/MON.DAT`, `DATA/EFX.DAT`, `DATA/MNM.DAT`, `DATA/BARAM.DAT`, BINT `0..2`, and `DATA/WM.DAT`.
- `Application::Initialize` scans numbered visual/resource families through [UID:0000T5][LoadIndexedDATSeries](by-global/LoadIndexedDATSeries.md).
- The music archive loop tries `DATA/MUH###.DAT` and falls back to `DATA/MUS###.DAT`.

This phase is startup resource policy in `Application.cpp`; archive parsing and indexing remain [UID:0000IO][DATFileMgr](by-file/DATFileMgr.md) behavior.

## Startup Logo Phase

[UID:0000O4][StartupLogoPanes](by-file/StartupLogoPanes.md) owns the later static-logo and startup-movie panes:

- [UID:00007G][LogoPane](by-class/LogoPane.md) loads and renders the static `.LGO` logo and advances through timer/click callbacks.
- [UID:00007H][LogoPlayerPane](by-class/LogoPlayerPane.md) reads segmented Bink data and uses [UID:0000P4][VideoPlayerPane](by-file/VideoPlayerPane.md) for playback.

## Cross-References

- [UID:0000PA][WinMain](by-file/WinMain.md)
- [UID:00019G][0x004f5c80-0x004f5f17.WinMain](by-memory/0x004f5c80-0x004f5f17.WinMain.md)
- [UID:0000HG][Application](by-file/Application.md)
- [UID:0001R6][application-startup-dat-archives](by-resource/application-startup-dat-archives.md)
- [UID:0000KK][LanguageMan](by-file/LanguageMan.md)
- [UID:0000O5][StartupWindow](by-file/StartupWindow.md)
- [UID:0001RO][startup-update-notice-resources](by-resource/startup-update-notice-resources.md)
- [UID:0000O4][StartupLogoPanes](by-file/StartupLogoPanes.md)
- [UID:0001QE][client_libraries](by-meta/client_libraries.md)
