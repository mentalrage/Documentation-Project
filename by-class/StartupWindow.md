*** UID:0000DZ | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000O5 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000O5 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
#include "StartupWindow.h"
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
#ifndef NEXUSTK_APP_STARTUPWINDOW_H
#define NEXUSTK_APP_STARTUPWINDOW_H

#include "../util/Singleton.h"
#include <windows.h>

class DIBitmap;

struct StartupNoticeButton
{
    DIBitmap *images[3];
    RECT rect;
    int state;
};

class StartupWindow : public Singleton<StartupWindow>
{
public:
    enum Result
    {
        kRunUpdater = 1,
        kAbortStartup = 2
    };

    StartupWindow(HINSTANCE instance);
    virtual ~StartupWindow();

    int RunUpdateCheck(bool *runUpdater);
    HINSTANCE GetInstanceHandle() const;

    bool m_assetsLoaded;
    HINSTANCE m_instance;
    HWND m_noticeWindow;
    DIBitmap *m_backgroundImage;
    StartupNoticeButton m_buttons[2];
    bool m_resultReady;
};

typedef char StartupNoticeButtonSizeMustBe0x20[
    sizeof(StartupNoticeButton) == 0x20 ? 1 : -1];
typedef char StartupWindowSizeMustBe0x58[
    sizeof(StartupWindow) == 0x58 ? 1 : -1];
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# StartupWindow

## Status

- Confidence: very strong for class identity, WinMain entry points, vtable/singleton state, callback ownership, static data references, corrected helper ranges, and accepted child-page split; medium for exact original source spelling of private fields/helpers.
- Likely source file: [UID:0000O5][StartupWindow](by-file/StartupWindow.md) / `NexusTK/app/StartupWindow.cpp`
- Address range: [UID:0001IO][0x005807d0-0x0058206e.StartupWindowUpdateCheck](by-memory/0x005807d0-0x0058206e.StartupWindowUpdateCheck.md)
- Rebuild handling: reconstructable class route attached to the file parent; this page emits only the class-route marker plus `[[CHILDREN]]`. Exact method/helper bodies are owned by by-memory child pages and must not be duplicated here.

## Class Purpose

`StartupWindow` is the pre-game update/news notice object. It runs before the main `Application::Startup` path, displays a browser-backed notice window, checks the remote update version with libcurl, refreshes minimap hash data, and reports whether the updater should run or the game can continue.

The current source-facing result constants inferred from [UID:00019G][0x004f5c80-0x004f5f17.WinMain](by-memory/0x004f5c80-0x004f5f17.WinMain.md) are `StartupWindow::kRunUpdater` for the out-byte value `1` and `StartupWindow::kAbortStartup` for the `RunUpdateCheck` return value `2`. These names are accepted first-draft caller/control-flow names rather than proven original symbols.

Do not use WinMain's `0x004f5e95-0x004f5f16` message tail as evidence for StartupWindow failure-message/failure-caption virtuals. B009's 2026-06-26 MCP-backed rework proves that tail is a source-level `catch (Error *error)` handler: the EH handler record at `0x0065efd4` points to type descriptor `0x00674544` / `??_R0PAVError@@@8`, and the virtual calls match the Error hierarchy `+0x0c` message-output and `+0x10` name/descriptor slots. The StartupWindow vtable evidence remains destructor-only.

## Method Notes

| Method or helper | Address | Role |
| --- | --- | --- |
| constructor | `0x005807d0-0x0058080c` | Stores singleton pointer, installs vtable, sets EPF/asset mode, stores `HINSTANCE`, clears state flags. |
| `StartupWindow::~StartupWindow` ordinary/non-deleting destructor body | `0x00580810-0x00580870` | Source-ready exact child after four bytes of constructor-to-destructor padding; current B011 MCP evidence shows inline cleanup of `m_backgroundImage` and the two notice-button image groups, then unconditional `g_pStartupWindow = NULL`. No direct start refs are known, so that remains a confidence cap rather than a C++ blocker. |
| `RunUpdateCheck` | `0x00580870-0x005810fd` | Creates notice HWND/browser, queries registry, performs libcurl update/minimap fetches, runs modal message loop, cleans up, returns update decision. |
| `UpdateCheckWindowProc` | `0x00581100-0x005815aa` | Handles keyboard, paint, mouse, cursor, link, and update/close button behavior for the notice window. |
| notice click helper | `0x005815b0-0x0058165a` | [UID:0004CU][0x005815b0-0x0058165a.StartupNoticePostButtonResult](by-memory/0x005815b0-0x0058165a.StartupNoticePostButtonResult.md) is a direct source-bearing raw helper at `88/91`: it resets the cursor, maps button `1` to direct state/rectangle invalidation and `WM_USER + 11` result `2`, maps button `0` to [UID:0004CX][0x00581730-0x005817a0.StartupNoticeSetButtonState](by-memory/0x00581730-0x005817a0.StartupNoticeSetButtonState.md) and result `1`, and leaves other indices as cursor-reset/no-result fallbacks. Current MCP still finds no IDA function or direct start refs, and the corrected range includes final `ret 4`. |
| state access/helper | `0x00581660-0x005817dd` | IDA-confirmed tiny accessor plus reset/set/hit-test helpers for the two notice buttons; [UID:0004CW][0x00581670-0x00581724.StartupNoticeResetButtonStates](by-memory/0x00581670-0x00581724.StartupNoticeResetButtonStates.md) now has direct B003 coverage at `89/92`, [UID:0004CX][0x00581730-0x005817a0.StartupNoticeSetButtonState](by-memory/0x00581730-0x005817a0.StartupNoticeSetButtonState.md) now has direct B010 coverage at `88/91`, and [UID:0004CY][0x005817a0-0x005817dd.StartupNoticeHitTestButton](by-memory/0x005817a0-0x005817dd.StartupNoticeHitTestButton.md) now has direct B007 coverage at `88/92`. |
| notice invalidation helpers | `0x005817e0-0x00581854`, `0x00581860-0x005818c3` | Raw helpers that invalidate all or one notice button rectangle; corrected ranges include their final returns. [UID:0004D0][0x00581860-0x005818c3.StartupNoticeInvalidateButton](by-memory/0x00581860-0x005818c3.StartupNoticeInvalidateButton.md) now has direct B003 coverage at `88/91`: MCP session `ddf5b602` confirms a `0x63` / 99-byte, 30-instruction raw body with no IDA function/decompile/direct start route; it reads `m_noticeWindow` at `this+0x0c`, copies the indexed `m_buttons[buttonIndex].rect` at `this+0x20 + buttonIndex*0x20`, calls `InvalidateRect(..., FALSE)`, and stays separated from the all-buttons sibling and asset loader by explicit padding. |
| notice asset helper | `0x005818d0-0x005819cc` | [UID:0004D1][0x005818d0-0x005819cc.StartupNoticeLoadAssets](by-memory/0x005818d0-0x005819cc.StartupNoticeLoadAssets.md) now has direct B004 coverage at `88/91`: the source-bearing file-local helper lazily loads `brm_main.pcx`, `brm_st_*.pcx`, and `brm_ex_*.pcx`, initializes button rectangles/states, preserves the exact formal helper body, and keeps no-function/no-decompile/no-direct-route plus inferred field/layout names as confidence caps. |
| alternate notice setup helper | `0x005819d0-0x00581b75` | [UID:0004D2][0x005819d0-0x00581b75.StartupNoticeCreateWindowRaw](by-memory/0x005819d0-0x00581b75.StartupNoticeCreateWindowRaw.md) is the direct source-bearing raw helper at `88/90`: current MCP session `13191102` confirms no IDA function/decompile, exact `0x1a5` / 421-byte range, 135 instructions, four-byte predecessor padding, eleven-byte successor padding, class/title/WndProc/atom refs, `CreateWindowExA`/`this+0x0c` store, and no direct start route. Formal C++ uses source-facing `StartupNoticeCreateWindow`, `CS_CLASSDC`, `WS_POPUP | WS_CLIPCHILDREN`, and `CW_USEDEFAULT` fallback x/y until desktop rect lookup succeeds. |
| scalar deleting destructor | `0x00581d30-0x00581db2` | Releases owned child/browser-like objects when initialized, clears singleton, and optionally deletes. |
| notice image draw helper | `0x00581dc0-0x00581e35` | [UID:0004D5][0x00581dc0-0x00581e35.StartupNoticeDrawPcxImage](by-memory/0x00581dc0-0x00581e35.StartupNoticeDrawPcxImage.md) is the direct source-bearing draw helper at `89/91`: current MCP session `ddf5b602` confirms a modeled `0x75` / 117-byte body, 46 instructions, two WndProc calls at `0x00581306` and `0x00581337`, fourteen-byte predecessor padding, eleven-byte successor padding, DIBitmap HBITMAP/width/height accessors, `CreateCompatibleDC`/`SelectObject`/`BitBlt(..., SRCCOPY)`/`DeleteDC`, no clipping/alpha/stretch/source-offset behavior, and source-facing `DIBitmap *`/`void` as inference caps over absent IDB UDTs and IDA's cleanup-return `BOOL`. |
| curl/string helpers | `0x00581b80-0x0058206e` | Curl response append callback and StartupWindow-local ANSI parse helpers used by `RunUpdateCheck`; [UID:0004D6][0x00581e40-0x00581f46.AnsiSmallStringFindFrom](by-memory/0x00581e40-0x00581f46.AnsiSmallStringFindFrom.md) is now direct source-covered at `88/91` as a file-local `std::string`/SSO find-from-offset helper, not a `StartupWindow` member method or shared StringUtil/runtime function. [UID:0004D7][0x00581f50-0x0058206e.AnsiSmallStringSubstring](by-memory/0x00581f50-0x0058206e.AnsiSmallStringSubstring.md) is no longer a class/file helper emitter; it is non-emitting MSVC/Dinkumware `std::string::substr` support generated by the `RunUpdateCheck` source expression. |

The accepted B008 split routes source-bearing bodies to exact by-memory children: [UID:0004CQ][0x005807d0-0x0058080c.StartupWindowConstructor](by-memory/0x005807d0-0x0058080c.StartupWindowConstructor.md), [UID:0004CR][0x00580810-0x00580870.StartupWindowOrdinaryDestructor](by-memory/0x00580810-0x00580870.StartupWindowOrdinaryDestructor.md), [UID:0004CS][0x00580870-0x005810fd.StartupWindowRunUpdateCheck](by-memory/0x00580870-0x005810fd.StartupWindowRunUpdateCheck.md), [UID:0004CT][0x00581100-0x005815aa.StartupWindowUpdateCheckWindowProc](by-memory/0x00581100-0x005815aa.StartupWindowUpdateCheckWindowProc.md), [UID:0004CV][0x00581660-0x00581664.StartupWindowGetInstanceHandle](by-memory/0x00581660-0x00581664.StartupWindowGetInstanceHandle.md), and the StartupWindow-local helper children created under the broad [UID:0001IO][0x005807d0-0x0058206e.StartupWindowUpdateCheck](by-memory/0x005807d0-0x0058206e.StartupWindowUpdateCheck.md) split index. [UID:0004D4][0x00581d30-0x00581db2.StartupWindowScalarDeletingDestructor](by-memory/0x00581d30-0x00581db2.StartupWindowScalarDeletingDestructor.md) is compiler-wrapper proof only and has no emitted body.

B011 2026-07-04 source-quality callback updates [UID:0004CR][0x00580810-0x00580870.StartupWindowOrdinaryDestructor](by-memory/0x00580810-0x00580870.StartupWindowOrdinaryDestructor.md) from the inherited descriptive `ReleaseNoticeAssets()` helper/conditional-singleton draft to direct destructor source: if startup notice assets were loaded, the body deletes `m_backgroundImage` and the three image slots for each of two `m_buttons` entries, then clears `g_pStartupWindow` unconditionally. The helper name is retained only as historical/descriptive shorthand unless a future exact helper route is proven.

B012 2026-07-04 source-quality callback updates [UID:0004CU][0x005815b0-0x0058165a.StartupNoticePostButtonResult](by-memory/0x005815b0-0x0058165a.StartupNoticePostButtonResult.md) from the inherited broad guard/set-state draft to direct raw helper source: the body calls `SetCursor(LoadCursorA(NULL, IDC_ARROW))` before result handling, handles `buttonIndex == 1` with direct second-button state write plus `InvalidateRect`, handles `buttonIndex == 0` through `StartupNoticeSetButtonState(startupWindow, 0, 1)`, and posts `WM_USER + 11` values `2` and `1` respectively. Current MCP session `nexustk_supervisor_20260704` confirms the exact `0xaa` / 170-byte range, six-byte predecessor/successor padding, final `retn 4`, security-cookie frame, relevant Win32/helper callees, and no IDA function/direct-start route. The no-function/no-xref status remains a confidence cap rather than a reason to keep stale generated C++.

B010 2026-07-04 source-quality callback updates [UID:0004D6][0x00581e40-0x00581f46.AnsiSmallStringFindFrom](by-memory/0x00581e40-0x00581f46.AnsiSmallStringFindFrom.md) as a direct `StartupWindow.cpp` helper emitter at `88/91`: current MCP session `ddf5b602` confirms exact `0x106` / 262-byte modeled function, eleven-byte predecessor and ten-byte successor padding, eight `RunUpdateCheck` code refs, zero data refs, sole `_memchr` callee, string length/capacity reads at receiver `+0x10/+0x14`, heap pointer switch for non-small storage, empty-needle return of the supplied offset, impossible-range rejection, zero-based match index on success, and `-1` sentinel on failure. This class doc treats it as StartupWindow-local parsing support routed through the file root, not an instance method or shared StringUtil/runtime declaration.

B011 2026-07-04 source-quality callback updates [UID:0004D7][0x00581f50-0x0058206e.AnsiSmallStringSubstring](by-memory/0x00581f50-0x0058206e.AnsiSmallStringSubstring.md) in the opposite direction: live MCP session `ddf5b602` proves the body is MSVC/Dinkumware `std::string::substr` runtime support with SSO-15 destination/source layout, offset bounds handling, count clamping, allocation/copy/terminator/free behavior, and runtime callees. The two `RunUpdateCheck` refs remain parser source-use context, but this class doc no longer treats UID0004D7 as a StartupWindow-owned helper or member. The source-level version parse remains in UID0004CS as `responseText.substr(...)`; UID0004D7 stays owner `NONE`, `RECONSTRUCTABLE:FALSE`, blank emitter, and blank C++.

## Data Notes

- `g_pStartupWindow` stores the live singleton pointer.
- `g_startupWindowClassAtom` caches the registered notice window class.
- `g_startupUpdateNoticeState` points to the notice-state structure used by `UpdateCheckWindowProc`.
- [UID:000288][0x00670260-0x00670268.StartupWindowNoticePointerData](by-memory/0x00670260-0x00670268.StartupWindowNoticePointerData.md) are file-static mutable pointer objects to const ANSI window-class/title literals. They are StartupWindow source-file data, not class members, and emit at position `0` before the modeled and raw consumers.
- [UID:0000SW][g_useEpfAssets](by-global/g_useEpfAssets.md) / historical IDA alias `byte_66DA97` is forced to `1` by the constructor.
- [UID:00026K][0x0062d418-0x0062d5a8.StartupWindowReadOnlyData](by-memory/0x0062d418-0x0062d5a8.StartupWindowReadOnlyData.md) carries the source constants and compiler-emitted class data for this class: the `StartupWindow` COL pointer at `0x0062d46c`, the single-slot vtable at `0x0062d470`, the wide registry value `L"updvr"` at `0x0062d49c`, startup/update URLs, and notice PCX names.

## Live IDA Evidence

- IDA MCP on 2026-06-04 used IDB `C:\Users\admin\Desktop\Clone\NexusTK\NexusTK.exe`, MD5 `4247e04e20b65d6414c7238aa8ff5515`.
- Exact IDA function records: constructor `0x005807d0-0x0058080c`, `RunUpdateCheck` `0x00580870-0x005810fd`, WndProc `0x00581100-0x005815aa`, modeled notice helpers `0x00581660-0x005817dd`, curl/string/draw/destructor helpers `0x00581b80-0x0058206e`, and next StdioFile function at `0x00582070`.
- `_WinMain@16` is the only code caller for both constructor and `RunUpdateCheck`, at `0x004f5d3a` and `0x004f5d52`.
- Constructor disassembly/decompilation writes `dword_69BAC8 = this`, `*this = StartupWindow::vftable`, [UID:0000SW][g_useEpfAssets](by-global/g_useEpfAssets.md) / historical IDA alias `byte_66DA97 = 1`, stores the startup `HINSTANCE` at `this + 8`, and clears bytes at `this + 4` and `this + 0x54`.
- The StartupWindow vtable slot at `0x0062d470` contains `0x00581d30`; xrefs to the slot come from constructor/destructor writes at `0x005807ed` and `0x00581d3a`, plus an adjacent constructor-gap write at `0x00580817`.
- WndProc pointer refs remain narrow: `xrefs_to 0x00581100` reports `0x005808e4` inside `RunUpdateCheck` and raw `0x005819fc` inside the alternate notice setup helper.
- Raw helper starts `0x005815b0`, `0x005817e0`, `0x00581860`, `0x005818d0`, and `0x005819d0` still have no IDA function objects but begin with function-shaped prologues (`55 8b ec ...`). The modeled WndProc-to-raw gap `0x005815aa-0x005815b0` and final aggregate gap `0x0058206e-0x00582070` are `0xcc` alignment.
- Button/draw helpers are tied to WndProc: `0x00581670` has two code refs from `0x00581100`, `0x00581730` has four WndProc refs plus one raw helper ref, `0x005817a0` has three WndProc refs, and `0x00581dc0` has two WndProc refs. B003's 2026-07-04 UID0004CW direct MCP recheck confirms `0x00581670-0x00581724` as size `0xb4` / 180 bytes, with exact WndProc calls at `0x005813c6` and `0x005814fd`, twelve-byte padding before and after, state fields at `+0x30` and `+0x50`, button rectangles at `+0x20` and `+0x40`, notice `HWND` at `+0x0c`, and source-ready reset-helper C++ preserved. B010's 2026-07-04 UID0004CX direct MCP recheck confirms `0x00581730-0x005817a0` as size `0x70`, with `ret 8` inside the function, `0x00581724-0x00581730` padding, state slot at `+0x30 + index*0x20`, rectangle at `+0x20 + index*0x20`, HWND at `+0x0c`, and no target-local bounds guard.
- B008's 2026-07-04 UID0004D5 direct MCP recheck uses session `ddf5b602` and confirms `0x00581dc0-0x00581e35` as modeled `sub_581DC0`, size `0x75` / 117 bytes, with exact WndProc draw calls `0x00581306` and `0x00581337`, fourteen-byte predecessor padding, eleven-byte successor padding, DIBitmap bitmap/width/height accessor calls, `SRCCOPY` BitBlt from source origin `(0, 0)`, and no clipping/transparent/alpha/stretch/source-offset logic. The helper emits through [UID:0000O5][StartupWindow](by-file/StartupWindow.md); ImageLoaders owns PCX decode and DIBitmap owns image storage/accessors only.
- B007's 2026-07-04 UID0004CY direct MCP recheck uses active session `13191102` and confirms `0x005817a0-0x005817dd` as `sub_5817A0`, size `0x3d` / 61 bytes, with WndProc callers `0x0058138c`, `0x00581465`, and `0x00581533`, sole `sub_4B7E80` point-in-rect callee, two `0x20`-stride button rectangles at `+0x20` and `+0x40`, `LOWORD(lParam)`/`HIWORD(lParam)` mouse-coordinate order, generated source presence, and source-ready helper C++ preserved. Exact original private helper/field spelling remains a class-level confidence cap only.
- Curl/string support context remains narrow to `RunUpdateCheck`: `0x00581b80` has only two callback-pointer refs inside `RunUpdateCheck` (`0x00580c6f`, `0x00580efb`), `0x00581cf0` has two `RunUpdateCheck` callers, `0x00581e40` has eight, and `0x00581f50` has two. B007's 2026-07-04 UID0004D3 direct recheck on MCP session `ddf5b602` confirms `0x00581cf0-0x00581d30` as exact size `0x40`, with ten-byte predecessor padding, successor scalar-wrapper boundary, reserve helper `0x00423eb0`, shared byte-widening append helper `0x00423060`, hidden wide-SSO destination initialization, no `MultiByteToWideChar`/`mbstowcs_s`, no third source parameter, no pointer/table route, and exact child emission through [UID:0000O5][StartupWindow](by-file/StartupWindow.md). B010's 2026-07-04 UID0004D6 direct recheck on the same MCP session confirms `0x00581e40-0x00581f46` as exact size `0x106`, with eleven-byte predecessor padding, ten-byte successor padding, eight `RunUpdateCheck` code refs, zero data refs, sole `_memchr` callee, string length/capacity reads and heap-pointer switch, empty-needle/offset handling, and `-1` no-match sentinel; exact child emission remains through [UID:0000O5][StartupWindow](by-file/StartupWindow.md). B011's UID0004D7 recheck confirms the two `0x00581f50` refs are source-use only; the body is non-emitting `std::string::substr` runtime support with no data/immediate refs and no class state.
- Startup static data refs are narrow and file-owned class-use evidence: `word_69BAC4` has four refs from the update-check/raw setup paths, `dword_69BAC8` has constructor/WndProc/destructor refs, and notice pointer objects `0x00670260`/`0x00670264` each have exactly two reads from `RunUpdateCheck` plus exact raw child UID0004D2. Their `.rdata` literal targets each have only the corresponding slot xref.
- Read-only strings at `0x0062d418`, `0x0062d430`, `0x0062d474`, `0x0062d4f0`, and `0x0062d590` confirm the notice class/title, news URL, minimap hash-list URL, and base web URL used by this class.
- 2026-06-16 live IDA MCP session `c001_midiplayer_rdata_20260615` reconfirmed constructor `0x005807d0`, `RunUpdateCheck` `0x00580870`, WndProc `0x00581100`, modeled notice helpers `0x00581660/0x00581670/0x00581730/0x005817a0`, callback/string/destructor helpers through `0x00581f50`, and successor `StdioFile` at `0x00582070`.
- Current `xrefs_to` reconfirmed `_WinMain@16` as the only code caller for the constructor and `RunUpdateCheck`, WndProc data refs from `RunUpdateCheck` and raw `0x005819d0`, two callback-pointer refs to `0x00581b80`, the destructor vtable slot, and the four `g_pStartupWindow` lifecycle refs.
- Current raw-helper review reconfirmed no IDA function objects and no direct xrefs for raw starts `0x005815b0`, `0x005817e0`, `0x00581860`, `0x005818d0`, and `0x005819d0`. `get_bytes` confirmed `0xcc` padding before each raw helper/callback boundary and before `StdioFile`.
- A PE-section-mapped scan found no absolute-VA pointer hits, no RVA hits, and no direct `E8`/`E9` hits to those five raw starts. It found only the expected `_WinMain@16` direct calls to constructor/`RunUpdateCheck` and WndProc pointer stores, so the raw-helper source-shape blocker is real and should remain documented rather than hidden by a score bump.
- Constructor and scalar deleting destructor decompilation reconfirm singleton publication/clear, vtable writes, [UID:0000SW][g_useEpfAssets](by-global/g_useEpfAssets.md) startup write, `HINSTANCE` storage, initialized/result flags, release of owned notice/browser/image objects, and compiler-only conditional object free. Historical pre-catalog0373 UID0004CR analysis lacked an IDA function object and therefore reconstructed the ordinary destructor from bounded bytes/instructions; catalog0373 subsequently created the exact function without changing that evidence or the authored source body.
- 2026-06-17 B001 read-only-data reanalysis confirmed the `StartupWindow` `.rdata` boundary at `0x0062d5a8`: `0x0062d46c` points to `??_R4StartupWindow@@6B@`, `0x0062d470` is the `StartupWindow` vtable, `0x0062d49c` is `L"updvr"`, and `0x0062d5a8` is the successor `StdioFile` complete-object-locator pointer rather than StartupWindow data.
- Historical B011 MCP session `nexustk_supervisor_20260704` rechecked UID0004CR before catalog0373: `0x00580810` was not an IDA function and did not decompile, but bounded `insn_query`/bytes showed a 39-instruction, `0x60`/96-byte destructor body ending at `0x0058086f`; `xrefs_to` and `find` code/data/immediate searches for `0x00580810` were empty. Catalog0373 now models exact function `StartupWindow__Destructor` over the same byte-identical range with zero start refs. The body still writes the StartupWindow vtable at `0x00580817`, releases notice image pointers through four indirect deleting calls, and clears `g_pStartupWindow` at `0x00580864`. The scalar deleting destructor at `0x00581d30` remains the vtable-referenced ABI wrapper with conditional object free.
- 2026-06-21 B010 source-quality reanalysis corrected the class executable split: `0x0058080c-0x00580810` is four `0xcc` bytes, `0x00580810-0x00580870` is a no-direct-route destructor-like body rather than padding, raw helper ranges now include return bytes through `0x00581b75`, and `0x005819d0-0x00581b75` is best treated as a raw alternate notice setup helper. Class C++ remains a route marker; exact child pages now carry the constructor/destructor/run/WndProc/helper source bodies.

UID000288's direct source-quality pass resolves the class/title data boundary without changing this class declaration or score. The exact `.data` slots contain `0x0062d418/0x0062d430`, point to `.rdata` `"BaramNoticeWnd_Class"`/`"Notice"`, and are consumed at modeled `0x005808ac/0x00580ab1` and raw `0x005819e1/0x00581b47`. Pointer indirection, immutable literal pointees, writable pointer-object storage, and complete StartupWindow-only refs support file-local `static const char *` declarations. Array-only, top-level-const pointer, class-member, public/header, and compiler-only alternatives are rejected. UID000288 owns the declarations; this class page preserves only the route marker plus `[[CHILDREN]]` and does not duplicate source.

## 2026-07-29 B009 Startup Global One-Definition Reconciliation

The accepted UID0002AM source-quality pass leaves this class page at `88/89` and does not move file-static globals into the class. Historical pre-catalog0373 evidence from session `1da2b2ae` against saved IDB SHA256 `412DA7E81557538D283BBFBC18875CACC6C1DBBC662E88BEC71307E0AE0519CD`, `143191140` bytes, saved `2026-07-29T15:00:32.0998001-04:00`, is preserved below rather than presented as current state. The immediately prior `905D1AB131C953911CD1DF5E536AF36EAECFA67486E2F800907B36C0673604C1`, then `296ED21C6665B7C0D8EFBC515B137101F8506FD945C6C7E14C3E6F655063CF8B`, `3C8F31781C94DF74AADDB65B3D944CD2CA4387C448918BBBFFD60B41C3625B69`, `0E0AF9383DE743CB91E076959498A0D9DAF906C5CA6E620F99425931A09AB481`, `03F10207763C01455EA5F767F330A371FEDD9885FBFD98705F5A486985DBE5DA`, `08D31FD1C7B80721D6CD7774B42C5A5157B3A4683670A3E27EA5660290554F5A`, and older IDB identities are dated historical checkpoints.

Historical pre-catalog0373 state represented `[0x0069bac4,0x0069bacc)` as eight independent undefined one-byte items with no persisted target names, types, or comments; `unk_69BAC4` and `unk_69BAC8` were presentation aliases rather than saved source symbols. Catalog0373 materialized the accepted analysis topology, and a later bounded no-drift readback at dated saved IDB SHA256 `DBF6280848C1301A796458235703DB91091BB160FD6D3022D6D8FDF483A1F5FD`, `143192467` bytes, saved `2026-07-31T01:36:48.7011378-04:00`, reconfirmed an opaque `StartupWindow` declaration with unknown size and zero members, one exact two-byte `ATOM g_startupWindowClassAtom` item with accepted regular/repeatable comments, two protected undefined zero bytes, and one exact four-byte `StartupWindow *g_pStartupWindow` item with accepted regular/repeatable comments. All eight bytes remain zero. The atom word has exactly four refs at `0x00580a57`, `0x00580a6e`, `0x00581af4`, and `0x00581b08`; the reserved word has zero refs; the pointer has exactly four lifecycle refs at constructor publication `0x005807e5`, ordinary-destructor clear `0x00580864`, WndProc read `0x00581114`, and scalar-wrapper clear `0x00581d94`. The left fence at `0x0069bac3` and separate successor at `0x0069bacc` remain intact. This evidence resolves three different physical objects rather than one packed class field, aggregate, or array.

Source ownership is therefore deliberately split from physical documentation. [UID:0002ZQ][g_startupWindowClassAtom](by-global/g_startupWindowClassAtom.md) is the sole source definition `static ATOM g_startupWindowClassAtom;`. [UID:0002ZS][g_pStartupWindow](by-global/g_pStartupWindow.md) is the sole source definition, with a source-local `class StartupWindow;` forward declaration immediately followed by `static StartupWindow *g_pStartupWindow;`. Their physical pages [UID:0002ZR][0x0069bac4-0x0069bac6.g_startupWindowClassAtom](by-memory/0x0069bac4-0x0069bac6.g_startupWindowClassAtom.md) and [UID:0002ZT][0x0069bac8-0x0069bacc.g_pStartupWindow](by-memory/0x0069bac8-0x0069bacc.g_pStartupWindow.md), plus aggregate index [UID:0002AM][0x0069bac4-0x0069bacc.StartupWindowUpdateStateGlobals](by-memory/0x0069bac4-0x0069bacc.StartupWindowUpdateStateGlobals.md), are non-emitting physical evidence. [UID:0002ZU][0x0069bac6-0x0069bac8.StartupWindowUpdateStateReservedWord](by-memory/0x0069bac6-0x0069bac8.StartupWindowUpdateStateReservedWord.md) is exact alignment/reserved storage with no source declaration.

The `StartupWindow` class owns behavior that reads or writes those file-static objects, but it does not own them as class members or class-static declarations. The pointer definition requires only the source-local forward declaration above; it does not justify placing a second declaration in this class route or a public header. Rejected alternatives include a class-static singleton, generic process-wide globals, a packed eight-byte state structure, one array, duplicate definitions on physical pages, raw `unk_`/`word_`/`dword_` labels, and neighbor-range merging.

Historical pre-catalog0373 executable evidence left the ordinary destructor and private create-window helper as raw code without function objects. Catalog0373 preserved every byte, range, xref, and fence while applying these six analysis poststates:

- Constructor `[0x005807d0,0x0058080c)` remains `StartupWindow__Constructor`, now typed `StartupWindow *__thiscall StartupWindow__Constructor(StartupWindow *this, HINSTANCE instance)`, with regular function comment `Constructs the StartupWindow update-notice object and publishes the active instance.` and repeatable function comment `Source reconstruction: StartupWindow::StartupWindow(HINSTANCE instance).` Its frame is exactly `var_4 +0x00/0x04 _DWORD`, `__saved_registers +0x04/0x04 _DWORD`, `__return_address +0x08/0x04 _UNKNOWN *`, and `instance +0x0c/0x04 HINSTANCE`; `this` is in `ECX`, and the sole caller remains `0x004f5d3a`.
- Ordinary destructor `[0x00580810,0x00580870)` now exists as `StartupWindow__Destructor`, typed `void __thiscall StartupWindow__Destructor(StartupWindow *this)`, with regular function comment `StartupWindow non-deleting destructor; releases loaded notice images and clears the active instance.` and repeatable function comment `Source reconstruction: StartupWindow::~StartupWindow().` Its only physical frame member is `__return_address +0x04/0x04 _UNKNOWN *`; `this` is in `ECX`, no stack argument or fabricated local exists, the range remains 96 bytes/39 instructions with zero start refs, and the unconditional singleton clear remains unchanged.
- RunUpdateCheck `[0x00580870,0x005810fd)` remains `StartupWindow__RunUpdateCheck`, now typed `int __thiscall StartupWindow__RunUpdateCheck(StartupWindow *this, bool *runUpdater)`, with regular function comment `Runs the startup notice, update-version, and minimap-hash check flow.` and repeatable function comment `Source reconstruction: int StartupWindow::RunUpdateCheck(bool *runUpdater).` Its exact frame is `Msg +0x010/0x01c tagMSG`, `var_124 +0x02c/0x04 char[4]`, `var_120 +0x030/0x030 WNDCLASSEXA`, `var_F0 +0x060`, `var_EC +0x064`, `var_E8 +0x068`, `var_E4 +0x06c`, `PtNumOfCharConverted +0x070 size_t`, `Block +0x074 void *`, `var_D8 +0x078`, `var_D4 +0x07c`, `var_D0 +0x080`, `hWnd +0x084 HWND`, `var_C8 +0x088`, `Y +0x08c int`, `X +0x090 int`, `EndPtr +0x097/0x05 _BYTE[5]`, `var_B1 +0x09f/0x01 _BYTE`, `bounds +0x0a0/0x10 RectBounds`, `Source +0x0b0 wchar_t *`, `Rect +0x0b8/0x10 tagRECT`, `String +0x0c8 char *`, `var_80 +0x0d0/0x10 tagRECT`, `var_70 +0x0e0 char *`, `var_60 +0x0f0`, `var_5C +0x0f4`, `Destination +0x0f8/0x02 wchar_t`, `var_14 +0x13c`, `var_10 +0x140`, `var_C +0x144`, `var_4 +0x14c`, `__saved_registers +0x150`, `__return_address +0x154`, `runUpdater +0x158 bool *`, and retained nonformal analysis residue `arg_4 +0x15c`; unlabeled four-byte entries are `_DWORD`. `this` is in `ECX`, and the sole caller remains `0x004f5d52`.
- WndProc `[0x00581100,0x005815aa)` now exists as `StartupWindowUpdateCheckWindowProc`, typed `LRESULT __stdcall StartupWindowUpdateCheckWindowProc(HWND window, UINT message, WPARAM wParam, LPARAM lParam)`, with regular function comment `Window procedure for the StartupWindow update notice.` and repeatable function comment `Referenced by both StartupWindow notice-window setup paths.` Its exact frame is `var_64 +0x08 _DWORD`, `row +0x0c int`, `var_5C +0x10 WPARAM`, `var_58 +0x14 HWND`, `Paint +0x18/0x40 tagPAINTSTRUCT`, `Rect +0x58/0x10 tagRECT`, `var_4 +0x68 _DWORD`, `__saved_registers +0x6c`, `__return_address +0x70`, `hWnd +0x74 HWND`, `Msg +0x78 UINT`, `wParam +0x7c WPARAM`, and `lParam +0x80 LPARAM`. The formal source names `window/message` map to physical `hWnd/Msg`; no register argument exists under `__stdcall`, and the two callback-pointer refs remain `0x005808e4` and `0x005819fc`.
- Private helper `[0x005819d0,0x00581b75)` now exists as `StartupNoticeCreateWindow`, typed `bool __fastcall StartupNoticeCreateWindow(StartupWindow *startupWindow)`, with regular address comment `Retained private StartupWindow notice-window creation helper; exact source body is documented by UID0004D2 and no direct start route is known.` and repeatable address comment `Source reconstruction: static bool StartupNoticeCreateWindow(StartupWindow *startupWindow).` Its exact frame is `var_5C +0x0c/0x30 WNDCLASSEXA`, `var_2C +0x3c _DWORD`, `Y +0x40 int`, `Rect +0x44/0x10 tagRECT`, `var_14 +0x54/0x10 tagRECT`, `var_4 +0x64 _DWORD`, `__saved_registers +0x68`, and `__return_address +0x6c`; `startupWindow` is solely in `ECX`, with no EDX or stack formal. The range remains 421 bytes/135 instructions with four predecessor and eleven successor padding bytes and zero start refs.
- Scalar wrapper `[0x00581d30,0x00581db2)` now exists as `StartupWindow__ScalarDeletingDestructor`, typed `StartupWindow *__thiscall StartupWindow__ScalarDeletingDestructor(StartupWindow *this, unsigned int deleteFlags)`, with regular function comment `Compiler-generated scalar deleting destructor for StartupWindow; do not hand-author as source.` and repeatable function comment `Regenerated from StartupWindow::~StartupWindow() and operator delete semantics.` Its exact physical frame remains `__saved_registers +0x04/0x04 _DWORD`, `__return_address +0x08/0x04 _UNKNOWN *`, and low-byte `arg_0 +0x0c/0x01 char`; `this` is in `ECX`, logical `deleteFlags` remains unsigned int, the sole vtable ref remains `0x0062d470`, and the wrapper remains compiler-generated/non-emitting.

The private helper's machine code uses ECX as its receiver-shaped argument, but that calling-convention fact does not prove source-level membership. The accepted human source remains a private file-local static helper owned by UID0004D2; the IDA `__fastcall` prototype is analysis-only and does not create a class method.

Dated validator command `19259` showed the defect this split corrects: generated source still carried an aggregate marker and physical-storage comments even though source requires only the two semantic definitions. Expected generated closure is one atom definition and one forward-declared pointer definition, with zero aggregate or physical-storage contributions. Older MCP-timeout, persisted-name, broad unresolved-helper, reconstructable marker/emitter, and duplicate-definition assumptions remain preserved in their historical entries below, but this accepted pass supersedes them as current source-placement guidance.

## Cross-References

- [UID:0000O5][StartupWindow](by-file/StartupWindow.md)
- [UID:0001IO][0x005807d0-0x0058206e.StartupWindowUpdateCheck](by-memory/0x005807d0-0x0058206e.StartupWindowUpdateCheck.md)
- [UID:0000SW][g_useEpfAssets](by-global/g_useEpfAssets.md)
- [UID:0001RO][startup-update-notice-resources](by-resource/startup-update-notice-resources.md)
- [UID:0000HV][Browser](by-file/Browser.md)
- [UID:00008H][MiniMapVersionManager](by-class/MiniMapVersionManager.md)
- [UID:00026K][0x0062d418-0x0062d5a8.StartupWindowReadOnlyData](by-memory/0x0062d418-0x0062d5a8.StartupWindowReadOnlyData.md)
- [UID:000288][0x00670260-0x00670268.StartupWindowNoticePointerData](by-memory/0x00670260-0x00670268.StartupWindowNoticePointerData.md)

## Changes

- 2026-08-17 B007 UID0000PA provider closure:
  - Raised `88/89 -> 92/94` after resolving the direct `Singleton<StartupWindow>` base, complete `0x58` layout, two `0x20` notice-button records, result constants, source-local pointer publication, and exact constructor/destructor/loader source causes.
  - The CPP channel now includes `StartupWindow.h`; method bodies continue to emit from exact by-memory children. The H channel opens the one shared guard, includes Singleton/Windows dependencies, forward-declares DIBitmap, and declares the complete class and size checks.
  - Public fields are deliberate source-shape inference because translation-unit WndProc/static helpers directly access them. Invented accessors or friend declarations would not match those uses.
  - The H fragment intentionally does not close its guard. Later-positioned [UID:0000SW][g_useEpfAssets](by-global/g_useEpfAssets.md) appends the extern/helper child and closes it, producing one coherent `StartupWindow.h`.

- 2026-07-29 B009 accepted UID0002AM callback: preserved class scores/formals while adding current authoritative-IDB evidence, exact atom/reserved/pointer physical split, sole semantic-global definitions, source-local forward-declaration placement, raw destructor/helper source-shape distinctions, rejected alternatives, generated-topology diagnosis, and explicit historicalization of stale timeout/persisted-name/marker assumptions.
- 2026-07-20 B004 UID000288 support synchronization:
  - Scores remain `88/89`; the complete class marker/formal and unrelated StartupWindow union are unchanged.
  - Corrected broad string wording to exact non-member file-static mutable-pointer-to-const-literal semantics, added all four modeled/raw refs and literal-only slot xrefs, recorded position-0 ordering and source/generated separation, and rejected duplicate/class/compiler-only alternatives.
- 2026-07-04 B008 UID0004D5 callback:
  - Scores unchanged at `88/89` for the class route.
  - Synchronized the notice image draw helper method note with direct UID0004D5 evidence: exact range `0x00581dc0-0x00581e35`, size `0x75` / 117 bytes, 46 instructions, predecessor/successor padding, two WndProc calls, DIBitmap accessor roles, compatible DC/select/BitBlt/DeleteDC flow, `SRCCOPY`, no clipping/alpha/stretch/source-offset behavior, source-facing `DIBitmap *` and `void` rationale, and exact child source emission through [UID:0000O5][StartupWindow](by-file/StartupWindow.md).
- 2026-07-04 B011 UID0004D7 callback:
  - Scores unchanged at `88/89` for the class route.
  - Historicalized UID0004D7 as a StartupWindow class/file helper. The class now records UID0004D7 as non-emitting MSVC/Dinkumware `std::string::substr` support generated by `RunUpdateCheck` source syntax, while UID0004CS carries the direct `responseText.substr(...)` expression and UID0004D7 itself keeps owner `NONE`, `RECONSTRUCTABLE:FALSE`, blank emitter, blank C++, and report-level MCP evidence.
- 2026-07-04 B010 UID0004D6 source-quality callback:
  - Scores unchanged at `88/89` for the class route.
  - Synchronized the curl/string helper method note and live evidence with direct UID0004D6 coverage: exact `0x00581e40-0x00581f46` range, `0x106` / 262-byte size, padding before/after, eight `RunUpdateCheck` code refs, zero data refs, sole `_memchr` callee, string length/capacity and heap-pointer behavior, empty-needle/offset semantics, `-1` sentinel, StartupWindow-local file helper route, and rejected member-method/StringUtil/runtime/broad-parent alternatives.
- 2026-07-04 B003 UID0004D0 callback:
  - Scores unchanged at `88/89` for the class route.
  - Updated the notice invalidation helper row with direct source-ready UID0004D0 evidence: exact `0x00581860-0x005818c3` range, `0x63` / 99-byte size, 30-instruction body, field roles, sibling comparison, no direct start route, and StartupWindow ownership/emission through [UID:0000O5][StartupWindow](by-file/StartupWindow.md).
- 2026-07-04 B012 UID0004CU callback:
  - Scores unchanged at `88/89` for the class route.
  - Synchronized the notice click helper method note with direct UID0004CU evidence: exact range `0x005815b0-0x0058165a`, size `0xaa` / 170 bytes, final `retn 4`, six-byte predecessor and successor padding, no IDA function/decompile or direct start refs, security-cookie frame, cursor reset through `LoadCursorA`/`SetCursor`, direct `buttonIndex == 1` state/rectangle invalidation, `buttonIndex == 0` set-state helper call, `WM_USER + 11` result values `2` and `1`, no-op fallback for other indices, and exact child source emission through [UID:0000O5][StartupWindow](by-file/StartupWindow.md).
- 2026-07-04 B004 UID0004D1 callback:
  - Scores unchanged at `88/89` for the class route.
  - Synchronized the notice asset helper method note with direct UID0004D1 evidence: exact range `0x005818d0-0x005819cc`, size `0xfc` / 252 bytes, final `ret 4`, thirteen-byte predecessor padding, four-byte successor padding, six PCX strings/calls, WndProc duplicate loader-call context, current `sub_4A17B0` IDA dependency versus source-facing `LoadPcxImage`, no start/end xrefs, no pointer-pattern route, and exact child source emission through [UID:0000O5][StartupWindow](by-file/StartupWindow.md).
- 2026-07-04 B006 UID0004D2 callback:
  - Scores unchanged at `88/89` for the class route.
  - Synchronized the alternate notice setup helper method note with direct UID0004D2 evidence: exact range `0x005819d0-0x00581b75`, size `0x1a5` / 421 bytes, 135 instructions, four-byte predecessor padding, eleven-byte successor padding, no IDA function/decompile, no direct start route, class/title/WndProc/atom refs, `CreateWindowExA`/HWND store, corrected `CS_CLASSDC` and `WS_POPUP | WS_CLIPCHILDREN` constants, `CW_USEDEFAULT` fallback coordinate handling, and exact child source emission through [UID:0000O5][StartupWindow](by-file/StartupWindow.md).
- 2026-07-01 B008 accepted split implementation:
  - Formal C++ changed from blank to a class-route marker plus `[[CHILDREN]]`.
  - Exact constructor/destructor/RunUpdateCheck/WndProc/helper bodies are emitted only by the new by-memory child pages, while this class page preserves class ownership, WinMain constants, Error EH rejection, vtable/singleton evidence, and the no-duplicate-method-body policy.

- 2026-06-07 A008 alias cleanup: normalized the constructor's `byte_66DA97 = 1` write to canonical [UID:0000SW][g_useEpfAssets](by-global/g_useEpfAssets.md), preserving `byte_66DA97` as the historical IDA lookup alias.
- 2026-06-04:
  - Before: scored `84/76`, reconstructability and parent attachment were blank, and the page still carried stale source-reference phrasing.
  - After: scored `86/84`, marked reconstructable, attached to [UID:0000O5][StartupWindow](by-file/StartupWindow.md), and replaced the evidence section with live IDA function/xref/raw-helper/vtable/string checks.
  - Why: current IDA evidence proves the class entry points, vtable, singleton/global state, WndProc/callback ownership, raw helper gap, and startup-local string helpers well enough for class-level reconstruction planning. Confidence remains below 90 because the raw helper starts in `0x005815b0-0x00581b7f` still need exact child-function promotion before final C++.

- Before: completion/confidence were unevaluated at `0/0`.
- Changed to: completion `84`, confidence `76`.
- Evidence: the page documents startup/update responsibility, constructor/update/window-proc/helper/destructor/curl ranges, key globals, resource links, WinMain callers, and raw helper boundary debt; confidence remains capped by unmodeled helper starts in `0x005815b0-0x00581b7f`.
- 2026-06-16 A001 low-confidence refresh:
  - Before: `COMPLETION:86`, `CONFIDENCE:84`.
  - Changed to: `COMPLETION:87`, `CONFIDENCE:88`; owner/emitter remain [UID:0000O5][StartupWindow](by-file/StartupWindow.md), and final C++ remains blank.
  - Evidence: live IDA reconfirmed WinMain-only entry points, WndProc/callback/vtable/singleton refs, constructor/destructor decompilation, raw-helper no-function/no-xref status, boundary padding, and PE-section-mapped no pointer/direct-branch hits to the raw helper starts. At that historical point the remaining blockers were exact child promotion and final source names for the raw notice helpers and member fields; exact child pages now carry source bodies, while original private helper/member spelling remains the current confidence cap.
- 2026-06-17 B001 read-only-data sync:
  - Scores unchanged at `87/88`.
  - Added corrected [UID:00026K][0x0062d418-0x0062d5a8.StartupWindowReadOnlyData](by-memory/0x0062d418-0x0062d5a8.StartupWindowReadOnlyData.md) evidence for the class COL/vtable prefix, `updvr` registry literal, and `0x0062d5a8` StdioFile successor boundary.
- 2026-06-21 B010 source-quality incorporation:
  - Before: `COMPLETION:87`, `CONFIDENCE:88`; method notes omitted the `0x00580810` destructor-like body and carried stale raw helper endpoints.
  - Changed to: `COMPLETION:88`, `CONFIDENCE:89`; owner/emitter remain [UID:0000O5][StartupWindow](by-file/StartupWindow.md), and class C++ remains blank.
  - Evidence: local PE/Capstone range proof identified the ordinary-destructor candidate, corrected raw helper ranges, and preserved no-direct-start-ref caveats for helper promotion.
- 2026-06-26 B009 WinMain result-flow support sync:
  - Score unchanged at `88/89`.
  - Added caller-inferred `StartupWindow::kRunUpdater` and `StartupWindow::kAbortStartup` result names for WinMain's update/abort branch logic.
  - Summary/evidence: [UID:00019G][0x004f5c80-0x004f5f17.WinMain](by-memory/0x004f5c80-0x004f5f17.WinMain.md) now documents that the in-range message tail is Error-pointer EH handling, not StartupWindow virtual accessors; StartupWindow ownership remains limited to the update-window object and its documented methods/helpers.
- 2026-07-04 B011 UID0004CR callback:
  - Scores unchanged at `88/89` for the class route.
  - Synchronized the ordinary destructor method note with current MCP-backed UID0004CR evidence: exact raw range `0x00580810-0x00580870`, four-byte predecessor padding, no direct start refs as a confidence cap, inline notice image/button cleanup, unconditional singleton clear, and scalar deleting destructor wrapper as compiler support only.
- 2026-07-04 B010 UID0004CX callback:
  - Scores unchanged at `88/89` for the class route.
  - Synchronized the modeled notice set-state helper note with direct UID0004CX evidence: exact range `0x00581730-0x005817a0`, size `0x70`, predecessor padding `0x00581724-0x00581730`, `ret 8` immediate inside the target, four WndProc refs plus raw UID0004CU ref at `0x00581632`, field roles for `m_noticeWindow` and `m_buttons[index]`, no guard in the target body, and exact child source emission through [UID:0000O5][StartupWindow](by-file/StartupWindow.md).
- 2026-07-04 B007 UID0004CY callback:
  - Scores unchanged at `88/89` for the class route.
  - Synchronized the modeled notice hit-test helper note with direct UID0004CY evidence: exact range `0x005817a0-0x005817dd`, size `0x3d` / 61 bytes, three WndProc refs, sole `sub_4B7E80` point-in-rect callee, two `0x20`-stride button rectangles, WndProc mouse-coordinate order, generated output presence, source-name/field-name confidence caps, and exact child source emission through [UID:0000O5][StartupWindow](by-file/StartupWindow.md).
- 2026-07-04 B007 UID0004D3 callback:
  - Scores unchanged at `88/89` for the class route.
  - Synchronized the startup string conversion helper note with direct UID0004D3 evidence: exact range `0x00581cf0-0x00581d30`, size `0x40` / 64 bytes, two RunUpdateCheck callers, reserve/append dependency roles, hidden wide-SSO destination shape, replacement of stale `mbstowcs_s` source with direct range widening, no `MultiByteToWideChar`, no source-facing third parameter, no pointer/table route, and exact child source emission through [UID:0000O5][StartupWindow](by-file/StartupWindow.md).
- 2026-07-04 B003 UID0004CW callback:
  - Scores unchanged at `88/89` for the class route.
  - Synchronized the modeled notice reset helper note with direct UID0004CW evidence: exact range `0x00581670-0x00581724`, size `0xb4` / 180 bytes, two WndProc call sites `0x005813c6` and `0x005814fd`, twelve-byte padding before and after, field roles for the two notice-button rectangles/states and `m_noticeWindow`, source-ready formal C++ preserved on the child, and exact child source emission through [UID:0000O5][StartupWindow](by-file/StartupWindow.md).
