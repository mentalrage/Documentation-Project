*** UID:0000PA | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:95 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"NexusTK/app/" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:FILE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***

# WinMain

## Status

- Confidence: strong for top-level product startup role, exact `_WinMain@16` range, the first-draft WinMain C++ route, the B001-014 early-exit KeySpeedMgr cleanup helper, and the B009 Error-pointer catch correction; medium-high for original filename and final source spelling of local constants/virtuals.
- Proposed module: `app/WinMain.cpp`
- Current recovered global: `WinMain_wrapper` / `_WinMain@16` at `0x004f5c80`.
- Current generated container: `source-3/simroot_v2/recovered/WinMain_wrapper_004F5C80.cpp`
- Related docs: [UID:0000HG][Application](by-file/Application.md), [UID:0000O5][StartupWindow](by-file/StartupWindow.md), [UID:0000J5][Error](by-file/Error.md), [UID:0000ML][PlatformApi](by-file/PlatformApi.md), [UID:00019G][0x004f5c80-0x004f5f17.WinMain](by-memory/0x004f5c80-0x004f5f17.WinMain.md), [UID:00032A][0x004673c0-0x004673d1.DestroyKeySpeedMgr](by-memory/0x004673c0-0x004673d1.DestroyKeySpeedMgr.md)

## File Role

`WinMain.cpp` should own the real game startup entry after CRT startup has handed off to `_WinMain@16`. The body stack-constructs the application object, creates and warms startup helpers such as `MiniMapVersionManager`, runs the [UID:0000O5][StartupWindow](by-file/StartupWindow.md) update-check flow, optionally launches the updater, and otherwise executes the normal initialize, message loop, shutdown, and exit-request lifecycle.

B001-014 adds the exact [UID:00032A][0x004673c0-0x004673d1.DestroyKeySpeedMgr](by-memory/0x004673c0-0x004673d1.DestroyKeySpeedMgr.md) helper to this file's source model. IDA shows `_WinMain@16` is the helper's sole direct caller at `0x004f5eeb`; the surrounding WinMain tail restores keyboard state through [UID:0000RB][g_pKeySpeedMgr](by-global/g_pKeySpeedMgr.md), calls the helper, then continues the exit/message-box sequence.

B003's 2026-07-15 complete UID00019H split adds [UID:0004R1][0x004f66b0-0x004f66b5.WinMainBaramAppCleanupThunk](by-memory/0x004f66b0-0x004f66b5.WinMainBaramAppCleanupThunk.md) as non-emitting compiler/EH support caused by WinMain's stack `BaramApp app(...)`. Evidence-time MCP database `46dda60b` proves exact bytes `e9 bb d2 f6 ff`, SHA256 `0505B9DEE2A5853919270FF7492420AF7218237D70A193234D113A4FD822A222`, and the sole inbound route `lea ecx,[ebp+var_1A88]` at `0x00600fc0` followed by the jump at `0x00600fc6`. The child tail-jumps to [UID:0002GZ][0x00463970-0x004639c4.ApplicationDestructor](by-memory/0x00463970-0x004639c4.ApplicationDestructor.md); WinMain owns the source cause, while the Application destructor remains the callee/source relationship.

The CRT wrapper before this handoff is runtime code and should not become project source.

IDA MCP confirms `_WinMain@16` is exactly `0x004f5c80-0x004f5f17` and has only the CRT startup caller. The generated `simroot_v2` recovery is useful here because it gives a source-shaped body, but treat its helper splits as recovered conveniences rather than proven original local functions.

B009's 2026-06-26 MCP-backed rework resolves the prior blank-C++ blocker on [UID:00019G][0x004f5c80-0x004f5f17.WinMain](by-memory/0x004f5c80-0x004f5f17.WinMain.md). The in-range `0x004f5e95-0x004f5f16` tail is source-level `catch (Error *error)` behavior, not StartupWindow virtual accessors and not padding: EH metadata points through handler record `0x0065efd4` to type descriptor `0x00674544` / `??_R0PAVError@@@8`, and the virtual calls match the [UID:0001XI][ErrorHierarchyVtables](by-type/by-vtable/ErrorHierarchyVtables.md) slot `+0x0c` message-output and `+0x10` error-name roles. The same pass resolves WinMain's `0x0069be70` read as the [UID:0000TQ][WideApiDispatchTable](by-global/WideApiDispatchTable.md) `g_pfnGetCurrentDirectoryW` slot, while preserving the observed `ShellExecuteExA` updater launch. The first-draft C++ therefore belongs on the exact by-memory WinMain page and should keep the W-dispatch/A-shell-call caveat visible.

## Proposed Contents

| Entity | Address evidence | Role |
| --- | --- | --- |
| `WinMain_wrapper` / `_WinMain@16` | `0x004f5c80-0x004f5f17` | Product startup/lifecycle entry. |
| updater-launch local block | inside `0x004f5c80-0x004f5f17` | Message box, [UID:0000TQ][WideApiDispatchTable](by-global/WideApiDispatchTable.md) `g_pfnGetCurrentDirectoryW` read, and `ShellExecuteExA("NexusUpdater.exe")`; emitted in [UID:00019G][0x004f5c80-0x004f5f17.WinMain](by-memory/0x004f5c80-0x004f5f17.WinMain.md), not split as a proven helper. |
| startup-window destroy local helper | inside `0x004f5c80-0x004f5f17` | Vtable delete call after `StartupWindow::RunUpdateCheck`; source-style split only. |
| early-exit local helper | inside `0x004f5c80-0x004f5f17` | Notifies [UID:0000QQ][g_pDATFileMgr](by-global/g_pDATFileMgr.md) before application cleanup on update-abort result; source-style split only. |
| Error catch body | `0x004f5e95-0x004f5f16` | In-range `catch (Error *error)` handler that copies wide text through Error slot `+0x0c`, hides the main window, restores screen/keyboard state, shows `MessageBoxW`, and deletes the caught object. |
| [UID:0004R1][0x004f66b0-0x004f66b5.WinMainBaramAppCleanupThunk](by-memory/0x004f66b0-0x004f66b5.WinMainBaramAppCleanupThunk.md) | external exact compiler child; sole WinMain EH edge at `0x00600fc6` | Non-emitting cleanup tail for the stack `BaramApp` local; ordinary stack lifetime and destructor declarations regenerate it. |
| [UID:00032A][0x004673c0-0x004673d1.DestroyKeySpeedMgr](by-memory/0x004673c0-0x004673d1.DestroyKeySpeedMgr.md) | `0x004673c0-0x004673d1`, called at `0x004f5eeb` | WinMain early-exit cleanup wrapper that deletes the current KeySpeedMgr object after keyboard restore; KeySpeedMgr remains the object/global owner. |

## Boundary Notes

- Keep `Application` methods in [UID:0000HG][Application](by-file/Application.md).
- Keep update notice and libcurl/browser update flow in [UID:0000O5][StartupWindow](by-file/StartupWindow.md).
- Keep `MiniMapVersionManager` implementation in [UID:0000LE][MiniMap](by-file/MiniMap.md); `WinMain` only constructs and warms it from local hash data.
- Keep `BaramApp` behavior in [UID:0000HG][Application](by-file/Application.md). This entry point writes `BaramApp` vtables onto a stack-constructed application object, but that does not prove a separate constructor function in this range.
- Keep UID0004R1 attached to this file only as semantic compiler-lifetime evidence. It is `RECONSTRUCTABLE:FALSE`, has blank emitter/position/formal C++, and must not become a `WinMainBaramAppCleanupThunk()` source helper, explicit base-destructor call, EH label, tail-jump assembly, or raw vptr/deleting-flag code.
- Keep exact topology separate: eleven-byte `0xcc` pad `0x004f66a5-0x004f66b0`, UID0004R1 `0x004f66b0-0x004f66b5`, then the unrelated BaramApp secondary deleting-destructor adjustor [UID:0002Q1][0x004f66b5-0x004f66bd.BaramAppDeletingDestructorThunk](by-memory/0x004f66b5-0x004f66bd.BaramAppDeletingDestructorThunk.md). UID0004R1 has no normal caller/callee/data/vtable/pointer route.
- Keep [UID:0000KJ][KeySpeedMgr](by-file/KeySpeedMgr.md) as the object and normal lifecycle owner for `g_pKeySpeedMgr`; [UID:00032A][0x004673c0-0x004673d1.DestroyKeySpeedMgr](by-memory/0x004673c0-0x004673d1.DestroyKeySpeedMgr.md) is WinMain early-exit cleanup glue because its only direct caller is `_WinMain@16`.
- Keep [UID:0000J5][Error](by-file/Error.md) as the owner of the Error hierarchy declarations and virtual implementations. WinMain owns only the catch policy: slot `+0x0c` is locally named `CopyErrorMessage` in the first-draft block, slot `+0x10` is `GetErrorName`, and the caught pointer is deleted after the message box.
- Keep [UID:0000ML][PlatformApi](by-file/PlatformApi.md) as the owner of `g_pfnGetCurrentDirectoryW` / `0x0069be70`. WinMain is a concrete consumer that passes the resulting buffer through an ANSI `SHELLEXECUTEINFOA` structure before `ShellExecuteExA`; do not hide that mismatch by renaming the slot to `GetCurrentDirectoryA`.
- Keep CRT `__scrt_common_main_seh` and related startup glue excluded as library/runtime code.

## Cross-References

- [UID:0000HG][Application](by-file/Application.md)
- [UID:0000O5][StartupWindow](by-file/StartupWindow.md)
- [UID:0000LE][MiniMap](by-file/MiniMap.md)
- [UID:0000J5][Error](by-file/Error.md)
- [UID:0000ML][PlatformApi](by-file/PlatformApi.md)
- [UID:00019G][0x004f5c80-0x004f5f17.WinMain](by-memory/0x004f5c80-0x004f5f17.WinMain.md)
- [UID:00032A][0x004673c0-0x004673d1.DestroyKeySpeedMgr](by-memory/0x004673c0-0x004673d1.DestroyKeySpeedMgr.md)
- [UID:0000RB][g_pKeySpeedMgr](by-global/g_pKeySpeedMgr.md)
- [UID:0000TQ][WideApiDispatchTable](by-global/WideApiDispatchTable.md)
- [UID:0001XI][ErrorHierarchyVtables](by-type/by-vtable/ErrorHierarchyVtables.md)
- [UID:0003P3][0x0061d140-0x0061d234.WinMainStartupUpdateStrings](by-memory/0x0061d140-0x0061d234.WinMainStartupUpdateStrings.md)
- [UID:0001P7][0x0067ab48-0x0067ab4c.g_pKeySpeedMgr](by-memory/0x0067ab48-0x0067ab4c.g_pKeySpeedMgr.md)
- [UID:0001IO][0x005807d0-0x0058206e.StartupWindowUpdateCheck](by-memory/0x005807d0-0x0058206e.StartupWindowUpdateCheck.md)
- [UID:00019H][0x004f5f20-0x004f66fb.BaramAppAndApplicationStartup](by-memory/0x004f5f20-0x004f66fb.BaramAppAndApplicationStartup.md)
- [UID:0004R1][0x004f66b0-0x004f66b5.WinMainBaramAppCleanupThunk](by-memory/0x004f66b0-0x004f66b5.WinMainBaramAppCleanupThunk.md)
- [UID:0002GZ][0x00463970-0x004639c4.ApplicationDestructor](by-memory/0x00463970-0x004639c4.ApplicationDestructor.md)
- [UID:0002Q1][0x004f66b5-0x004f66bd.BaramAppDeletingDestructorThunk](by-memory/0x004f66b5-0x004f66bd.BaramAppDeletingDestructorThunk.md)

## Changes

- 2026-08-17 B007 UID0000PA whole-file implementation callback:
  - Raised the whole-file score from `89/88` to `94/95` after reconciling the complete source inventory: handwritten [UID:00032A][0x004673c0-0x004673d1.DestroyKeySpeedMgr](by-memory/0x004673c0-0x004673d1.DestroyKeySpeedMgr.md), handwritten [UID:00019G][0x004f5c80-0x004f5f17.WinMain](by-memory/0x004f5c80-0x004f5f17.WinMain.md), the use-site-only [UID:0003P3][0x0061d140-0x0061d234.WinMainStartupUpdateStrings](by-memory/0x0061d140-0x0061d234.WinMainStartupUpdateStrings.md) pool, and compiler-only [UID:0004R1][0x004f66b0-0x004f66b5.WinMainBaramAppCleanupThunk](by-memory/0x004f66b0-0x004f66b5.WinMainBaramAppCleanupThunk.md).
  - Fixed source order to helper position `10`, WinMain position `20`, and the pooled-literal no-standalone-data marker at position `30`. The source has no reusable declaration, so `WinMain.h` remains intentionally absent and no third-party import applies.
  - Provider closure is explicit: `Application.h`, `StartupWindow.h`, `DATFileMgr.h`, `KeySpeedMgr.h`, `MiniMapVersionManager.h`, `PlatformApi.h`, `ScreenPane.h`, and `Error.h` supply every class, singleton, API dispatch, and error/screen dependency used by the two handwritten bodies.
  - The reconstructed entry point preserves the wide `GetCurrentDirectoryW` result passed through the observed ANSI `SHELLEXECUTEINFOA`/`ShellExecuteExA` route, direct publisher/title/updater literals, startup/update branching, DAT cleanup, `Application::RequestExit`, `Error::FormatErrorMessage`, screen restoration, keyboard restoration, helper deletion, and message/error destruction order.
  - Rejected source shapes remain historical rather than emitted: raw pooled `k*` declarations, raw vptr/RTTI/EH products, an explicit BaramApp base-destructor call, an Application-owned entry point, a StartupWindow-owned entry point, and a standalone constants table would duplicate compiler products or contradict direct xrefs.

- 2026-07-15 B003 UID00019H split support sync:
  - Score/path remain `89/88` and `NexusTK/app/`; existing WinMain source and unrelated contents are unchanged.
  - Added non-emitting UID0004R1 to Proposed Contents and boundary/compiler-lifetime evidence with exact range, bytes/hash, sole WinMain EH route, stack-local source cause, Application destructor tail target, negative routes, no-code proof, and rejected handwritten compiler mechanics.
  - UID00019H is now a non-emitting ownerless mixed index rather than Application-emitted source; that parent reclassification does not change WinMain's formal source route.
- 2026-06-26 B009 WinMain source-quality implementation:
  - Before: `COMPLETION:86`, `CONFIDENCE:86`; the file page described top-level startup and early-exit cleanup but did not carry the accepted first-draft C++ readiness, Error catch correction, or PlatformApi current-directory dispatch caveat.
  - Changed to: `COMPLETION:89`, `CONFIDENCE:88`; proposed path remains `NexusTK/app/`.
  - Summary/evidence: [UID:00019G][0x004f5c80-0x004f5f17.WinMain](by-memory/0x004f5c80-0x004f5f17.WinMain.md) now emits first-draft WinMain C++; MCP session `80de0a67` proves `0x004f5e95` is a `catch (Error *error)` handler via EH record `0x0065efd4` and type descriptor `0x00674544` / `??_R0PAVError@@@8`, rejects the stale StartupWindow-tail reading, and preserves `0x0069be70 -> GetCurrentDirectoryW` with the observed `ShellExecuteExA` updater call.
- Completion/confidence scoring: existed before as ungraded `0/0`; changed to `84/80`. Summary/evidence: the page documents the product entry-point role, startup/update flow boundaries, CRT exclusion, IDA range evidence, and related file/memory refs; exact original filename and local helper splits remain medium-confidence.
- 2026-06-10 B001-014 early-exit cleanup split:
  - Before: `84/80`; the adjacent `0x004673c0` KeySpeedMgr cleanup wrapper was unsplit and the file-level confidence was capped by unresolved local helper ownership.
  - Changed to: `86/86`, with [UID:00032A][0x004673c0-0x004673d1.DestroyKeySpeedMgr](by-memory/0x004673c0-0x004673d1.DestroyKeySpeedMgr.md) added as a WinMain-owned early-exit helper while KeySpeedMgr remains the object/global owner.
  - Summary/evidence: live IDA MCP confirms `sub_4673C0` has one direct caller, `_WinMain@16` at `0x004f5eeb`; the caller loads [UID:0000RB][g_pKeySpeedMgr](by-global/g_pKeySpeedMgr.md), calls keyboard restore at `0x004eff30`, then calls this cleanup wrapper before the WinMain shutdown/message-box tail.
