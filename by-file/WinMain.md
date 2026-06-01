*** UID:0000PA | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:80 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"NexusTK/app/" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***

# WinMain

## Status

- Confidence: strong for top-level product startup role; medium for original filename.
- Proposed module: `app/WinMain.cpp`
- Current recovered global: `WinMain_wrapper` / `_WinMain@16` at `0x004f5c80`.
- Current generated container: `source-3/simroot_v2/recovered/WinMain_wrapper_004F5C80.cpp`
- Related docs: [UID:0000HG][Application](by-file/Application.md), [UID:0000O5][StartupWindow](by-file/StartupWindow.md), [UID:00019G][0x004f5c80-0x004f5f17.WinMain](by-memory/0x004f5c80-0x004f5f17.WinMain.md)

## File Role

`WinMain.cpp` should own the real game startup entry after CRT startup has handed off to `_WinMain@16`. The body stack-constructs the application object, creates and warms startup helpers such as `MiniMapVersionManager`, runs the [UID:0000O5][StartupWindow](by-file/StartupWindow.md) update-check flow, optionally launches the updater, and otherwise executes the normal initialize, message loop, shutdown, and exit-request lifecycle.

The CRT wrapper before this handoff is runtime code and should not become project source.

IDA MCP confirms `_WinMain@16` is exactly `0x004f5c80-0x004f5f17` and has only the CRT startup caller. The generated `simroot_v2` recovery is useful here because it gives a source-shaped body, but treat its helper splits as recovered conveniences rather than proven original local functions.

## Proposed Contents

| Entity | Address evidence | Role |
| --- | --- | --- |
| `WinMain_wrapper` / `_WinMain@16` | `0x004f5c80-0x004f5f17` | Product startup/lifecycle entry. |
| updater-launch local helper | inside `0x004f5c80-0x004f5f17` | Message box, current-directory setup, and `ShellExecuteExA("NexusUpdater.exe")`; source-style split only. |
| startup-window destroy local helper | inside `0x004f5c80-0x004f5f17` | Vtable delete call after `StartupWindow::RunUpdateCheck`; source-style split only. |
| early-exit local helper | inside `0x004f5c80-0x004f5f17` | Notifies [UID:0000QQ][g_pDATFileMgr](by-global/g_pDATFileMgr.md) before application cleanup on update-abort result; source-style split only. |

## Boundary Notes

- Keep `Application` methods in [UID:0000HG][Application](by-file/Application.md).
- Keep update notice and libcurl/browser update flow in [UID:0000O5][StartupWindow](by-file/StartupWindow.md).
- Keep `MiniMapVersionManager` implementation in [UID:0000LE][MiniMap](by-file/MiniMap.md); `WinMain` only constructs and warms it from local hash data.
- Keep `BaramApp` behavior in [UID:0000HG][Application](by-file/Application.md). This entry point writes `BaramApp` vtables onto a stack-constructed application object, but that does not prove a separate constructor function in this range.
- Keep CRT `__scrt_common_main_seh` and related startup glue excluded as library/runtime code.

## Cross-References

- [UID:0000HG][Application](by-file/Application.md)
- [UID:0000O5][StartupWindow](by-file/StartupWindow.md)
- [UID:0000LE][MiniMap](by-file/MiniMap.md)
- [UID:00019G][0x004f5c80-0x004f5f17.WinMain](by-memory/0x004f5c80-0x004f5f17.WinMain.md)
- [UID:0001IO][0x005807d0-0x0058206e.StartupWindowUpdateCheck](by-memory/0x005807d0-0x0058206e.StartupWindowUpdateCheck.md)
- [UID:00019H][0x004f5f20-0x004f66fb.BaramAppAndApplicationStartup](by-memory/0x004f5f20-0x004f66fb.BaramAppAndApplicationStartup.md)

## Changes

- Completion/confidence scoring: existed before as ungraded `0/0`; changed to `84/80`. Summary/evidence: the page documents the product entry-point role, startup/update flow boundaries, CRT exclusion, IDA range evidence, and related file/memory refs; exact original filename and local helper splits remain medium-confidence.
