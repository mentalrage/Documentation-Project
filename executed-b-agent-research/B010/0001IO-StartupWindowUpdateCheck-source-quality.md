** TARGET-REPORT-UID:0001IO **
** AUTHOR-AGENT-ID:B010 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# Agent-B010 Source-Quality Report: UID 0001IO StartupWindowUpdateCheck

Assignment: `B010 new report-only assignment`, target [UID:0001IO].

Target: `E:\NTK\GhidraBridge\source-3\project-documentation\by-memory\0x005807d0-0x0058206e.StartupWindowUpdateCheck.md`

Report path: `E:\NTK\GhidraBridge\source-3\project-documentation\tools\leaser\Agents\Agent-B010\research\0001IO-StartupWindowUpdateCheck-source-quality.md`

Mode: report-only. This pass did not edit by-* documentation and did not edit `by-memory/-coverage-report.md`.

## Executive Conclusion

[UID:0001IO] is source-owned StartupWindow update-notice code, but it is not one source-level function or one source-emitting by-memory item. It is an address-neighborhood aggregate spanning the `StartupWindow` constructor, a newly reidentified non-deleting destructor body at `0x00580810`, `StartupWindow::RunUpdateCheck`, the notice WndProc, button-state helpers, raw no-IDA-function helper bodies, the existing curl callback child, string/range helpers, the scalar deleting destructor, image blitting helper, and internal padding.

The aggregate should not receive formal `RECONSTRUCTION_CPP` as a single block. C++ should be deferred until exact child by-memory pages exist for the source-bearing functions. After that split, [UID:0001IO] should become a non-emitting split/index page, with exact child pages carrying reconstructable source and routing directly to [UID:0000O5] `StartupWindow` or the narrower [UID:0000DZ] `StartupWindow` class where appropriate.

The most important correction is the constructor-to-run gap. The target currently says `0x0058080c-0x00580870` is padding/neighboring bytes. Local PE byte/disassembly validation shows:

- `0x0058080c-0x00580810`: four `0xcc` bytes.
- `0x00580810-0x00580870`: standalone destructor/resource-release body, no direct rel32/VA/RVA refs found.

This is not padding. It is source-shaped class teardown code, most likely the complete-object/non-deleting `StartupWindow::~StartupWindow` body or a compiler-emitted ordinary destructor body sharing logic with the scalar deleting destructor at `0x00581d30`.

Recommended target disposition after implementation:

- `COMPLETION:88`
- `CONFIDENCE:90`
- `CANONICAL_OWNER:0000O5`
- `RECONSTRUCTABLE:FALSE`
- `EMITTER_UIDS:` blank
- `RECONSTRUCTION_CPP` blank
- Coverage row classification: non-emitting split inventory / ignored row, with exact reconstructable child rows nested beneath it.

If the supervisor elects not to split immediately, keep [UID:0001IO] at `85/87` or at most `86/88`; do not add C++ and do not leave the stale `0x0058080c-0x00580870` padding claim in place.

## Inputs Reviewed

Control/instructions:

- `tools/leaser/Agents/Supervisor.md`
- `.codex/AGENTS.md`
- `tools/leaser/Agents/Agent-B010/goal.md`
- `tools/leaser/Agents/Agent-B010/notes.md`

Target/support docs:

- `by-memory/0x005807d0-0x0058206e.StartupWindowUpdateCheck.md`
- `by-memory/0x00581b80-0x00581ce6.CurlWriteCallback.md`
- `by-item/StartupWindowUnmodeledNoticeHelpers_5815b0_581b7f.md`
- `by-file/StartupWindow.md`
- `by-class/StartupWindow.md`
- `by-memory/0x0062d418-0x0062d5a8.StartupWindowReadOnlyData.md`
- `by-resource/startup-update-notice-resources.md`
- `by-memory/0x00670260-0x00670268.StartupWindowNoticePointerData.md`
- `by-memory/0x0069bac4-0x0069bacc.StartupWindowUpdateStateGlobals.md`
- `by-memory/0x0069bac4-0x0069bac6.g_startupWindowClassAtom.md`
- `by-memory/0x0069bac8-0x0069bacc.g_pStartupWindow.md`
- `by-global/g_useEpfAssets.md`
- `by-project-structure/proposed-source-tree.md`
- `auto-generated/NexusTK/app/StartupWindow.cpp`
- `by-memory/-coverage-report.md`

Additional evidence:

- Local PE: `C:\Users\admin\Desktop\Clone\NexusTK\NexusTK.exe`
- Known matching MD5 from prior documentation: `4247e04e20b65d6414c7238aa8ff5515`
- Capstone 5.0.7 read-only disassembly with manual PE mapping.
- Existing IDA-backed documentation. Live IDA MCP was unavailable in this session.

Live IDA MCP status:

```text
POST tools/list to http://127.0.0.1:13337/mcp
ERROR: Unable to connect to the remote server
```

No IDA database changes were made.

## Current Target State

Current target metadata:

- `UID:0001IO`
- `COMPLETION:85`
- `CONFIDENCE:87`
- `CANONICAL_OWNER:0000O5`
- `RECONSTRUCTABLE:TRUE`
- `EMITTER_UIDS:0000O5`
- formal C++ block blank

Current generated state:

- `auto-generated/NexusTK/app/StartupWindow.cpp` contains an `Empty Emitter Marker` for [UID:0001IO], plus empty markers for [UID:0001IP] and associated StartupWindow globals/data.
- Validator dry run reports [UID:0001IO] as `emitting children only`; there is no generated C++ implementation for the target.

Current coverage-row state is stale against the target header:

- [UID:0001IO] target header is `85/87`.
- `by-memory/-coverage-report.md` row still says `84% : strong`.
- Existing child [UID:0001IP] header is `86/90`.
- `by-memory/-coverage-report.md` row still says `74% : strong`.

The worktree already had dirty `by-memory` files before this report was written. This report did not modify them.

## Validator Baseline

Scoped read-only validator baseline command:

> Executable block R001 was removed from this report and preserved verbatim in [0001IO-StartupWindowUpdateCheck-source-quality-removed.md](0001IO-StartupWindowUpdateCheck-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

Working directory:

```text
E:\NTK\GhidraBridge\source-3\project-documentation
```

Result:

```text
mode: file
scope: direct by-* folders under root
apply: False
scanned markdown files: 1
ok: 1
ok           0001IO by-memory/0x005807d0-0x0058206e.StartupWindowUpdateCheck.md UID header exists
dry run only; pass --apply to write changes
```

The validator also rebuilt registry/autogen state in dry-run mode and printed normal project-wide `autogen_*` diagnostics. No `--apply` was used.

## Heuristic / Inference Reanalysis And Validation

### Overall Classification

| Issue | Evidence checked | Best-supported decision | Rejected alternatives / negative evidence |
| --- | --- | --- | --- |
| Single aggregate versus child split | Target page inventory, `by-structure.md` reconstruction rules, coverage report, generated `StartupWindow.cpp`, local PE range/padding scan. | Split before source C++. [UID:0001IO] should become a non-emitting split/index page after child pages exist. | Reject one formal C++ block on [UID:0001IO]. The range contains multiple functions, raw helper starts, padding, compiler destructor variants, an existing callback child, and helper/string functions. |
| `0x0058080c-0x00580870` gap | Local PE bytes and disassembly. `0x0058080c-0x00580810` is `cc cc cc cc`; `0x00580810-0x00580870` is valid code ending in `ret`. | Add a child candidate `0x00580810-0x00580870` for the ordinary/non-deleting destructor body or `StartupWindowReleaseOwnedNoticeObjects`. | Reject target's current "bytes immediately after are padding before RunUpdateCheck" wording. Only the first four bytes are padding. |
| `0x00580810` reachability | Local PE scan for rel32 targets, immediate dword VA, and immediate dword RVA. | No direct rel32/VA/RVA references were found. Treat as emitted class destructor body with no proven live call route in current static evidence. | Reject treating it as padding or as a known direct helper. Do not emit child C++ until the destructor-source route is accepted. |
| Raw helper starts in `0x005815b0-0x00581b75` | Stored IDA docs plus local PE disassembly and reference scan. | They are real source-shaped helper bodies under StartupWindow, but the exact child pages should preserve no-IDA-function/no-direct-start-ref caveats. | Reject leaving names as `raw helper`/`sub_` in final source-quality docs. Reject pretending IDA has modeled functions there. |
| Raw helper end ranges | Local PE disassembly through returns and padding bytes. | Several current ranges omit final `ret` bytes. Correct child half-open ranges should include the return instruction and then separate `0xcc` padding. | Reject current raw endpoints `0x00581657`, `0x00581853`, `0x005818c0`, and `0x005819c9` as exact function ends. They stop at or before return bytes. |
| `0x005819d0-0x00581b7f` raw alternate setup | Local PE disassembly and existing pointer refs to class/title/WndProc. | Source-shaped `StartupNoticeCreateWindowRaw` / alternate create-window helper. It builds `WNDCLASSEXA`, registers class, creates a centered 500x430 notice window, and stores `HWND` at `this+0x0c`. | No direct caller/ref to the start was found. Keep no-route caveat and do not use it as proof that the source had a second public setup API. |
| WndProc ownership | Existing xrefs: WndProc pointer stored by `RunUpdateCheck` and raw setup helper; local disassembly agrees. | `StartupWindowNoticeWndProc` or `StartupWindowUpdateCheckWindowProc`, likely file-local/static callback in `StartupWindow.cpp` and semantically tied to class state through `g_pStartupWindow`. | Reject generic `sub_581100`. Reject moving it to Browser or ImageLoaders; Browser only hosts the news panel and ImageLoaders only loads PCX assets. |
| Curl callback ownership | Existing [UID:0001IP] docs and target xrefs: data refs at `0x00580c70` and `0x00580efc`, both `curl_easy_setopt(..., CURLOPT_WRITEFUNCTION, callback)`. | StartupWindow file-local libcurl glue. Direct owner/emitter should be [UID:0000O5] after [UID:0001IO] becomes non-emitting. | Reject libcurl third-party ownership. Reject leaving [UID:0001IP] emitted through a non-emitting aggregate after split. |
| String helper ownership | Existing caller locality: `0x00581cf0`, `0x00581e40`, `0x00581f50` only called from `RunUpdateCheck` in written docs/local refs. | Keep as StartupWindow-local parse helpers unless a wider caller scan later proves shared string-runtime ownership. | Reject final generic `StringUtil` ownership today. The current evidence only proves StartupWindow callers. |
| Browser path | Target/read-only-data/resource docs: `RunUpdateCheck` embeds `http://www.nexustk.com/news/news.asp`. | StartupWindow owns orchestration and URL; [UID:0000HV] Browser owns browser implementation. | Reject moving browser host implementation into StartupWindow. StartupWindow consumes Browser APIs. |
| Minimap path | B002 support docs: StartupWindow compares remote `minimap` key against `MiniMapVersionManager::GetVersionString() const`, then calls `MiniMapVersionManager::UpdateHashList(..., saveCache=true)` after selecting downloaded `HashList.txt`. | StartupWindow owns HTTP fetch/selection; [UID:00008H]/[UID:0000LF] own minimap version/hash-list persistence. | Reject assigning hash-list parser/cache mutation to StartupWindow. |
| Registry/version fields | Read-only-data/resource docs: `HKCU\Software\KRU\NexusTK`, value `L"updvr"` at `0x0062d49c`, remote `version` key, remote update URL at `0x0062d4a8`. | Use source-facing names `kStartupRegistryUpdateVersionValue`, `kStartupUpdateVersionUrl`, and `kStartupUpdateVersionKey`/shared `"version"` key. | Reject leaving `dword`/raw string labels. Exact broader remote payload schema remains unknown, but fields used here are proven. |
| PCX/button state | Resource docs and raw asset loader disassembly. | Object layout includes two button rect/state slots and six loaded PCX objects. Source names should be notice/start/exit button assets and states. | Adjacent `brm_n_*`/`brm_o_*` DAT entries are not proven used here; do not promote them into StartupWindow unless a later helper-state audit finds refs. |
| Compiler/generated names | Vtable/COL docs, scalar deleting destructor, exception literals, security cookie frames. | Treat `0x0062d46c` COL/vtable prefix and `0x00581d30` scalar deleting destructor as compiler-generated class artifacts; source emits class destructor, not a manually named scalar-deleting wrapper. | Reject source names like `sub_581D30` or direct hand-authored `ScalarDeletingDestructor` in final C++. Use those only as binary artifact labels. |

### Fresh Local PE Findings

Read-only local PE validation found these materially relevant facts:

```text
0x0058080c-0x00580810: cc cc cc cc
0x00580810-0x00580870: valid destructor-like code, no rel32/VA/RVA refs found
0x005810fd-0x00581100: cc cc cc
0x005815aa-0x005815b0: cc x6
0x0058165a-0x00581660: cc x6
0x00581664-0x00581670: cc x12
0x00581724-0x00581730: cc x12
0x005817dd-0x005817e0: cc x3
0x00581854-0x00581860: cc x12
0x005818c3-0x005818d0: cc x13
0x005819cc-0x005819d0: cc x4
0x00581b75-0x00581b80: cc x11
0x00581ce6-0x00581cf0: cc x10
0x00581db2-0x00581dc0: cc x14
0x00581e35-0x00581e40: cc x11
0x00581f46-0x00581f50: cc x10
0x0058206e-0x00582070: cc cc
```

Reference scan summary:

| Target | rel32 refs | VA/RVA data refs | Decision |
| --- | --- | --- | --- |
| `0x005807d0` | `0x004f5d3a` | none found in local scan | Constructor called from `_WinMain@16`. |
| `0x00580810` | none | none | Emitted destructor-like body, no live route proven. |
| `0x00580870` | `0x004f5d52` | none found in local scan | `RunUpdateCheck` called from `_WinMain@16`. |
| `0x00581100` | none | VA refs at `0x005808ea`, `0x005819ff` | WndProc pointer used by `RunUpdateCheck` and raw create-window helper. |
| `0x005815b0` | none | none | Raw helper, no start route proven. |
| `0x00581670` | `0x005813c6`, `0x005814fd` | none | Button-state reset helper called from WndProc. |
| `0x00581730` | `0x005813ae`, `0x005813be`, `0x005814e6`, `0x00581543`, `0x00581633` | none | Button-state setter called from WndProc and raw accept helper. |
| `0x005817a0` | `0x0058138d`, `0x00581466`, `0x00581534` | none | Button hit-test helper called from WndProc. |
| `0x005817e0` | none | none | Raw invalidate-all helper, no start route proven. |
| `0x00581860` | none | none | Raw invalidate-one helper, no start route proven. |
| `0x005818d0` | none | none | Raw asset loader, no start route proven. |
| `0x005819d0` | none | none | Raw create-window helper, no start route proven. |
| `0x00581b80` | none | VA refs at `0x00580c70`, `0x00580efc` | Curl write callback installed by `RunUpdateCheck`. |
| `0x00581cf0` | `0x00580e3f`, `0x00580fb6` | none | ANSI range to wide string helper called from `RunUpdateCheck`. |
| `0x00581d30` | none | VA ref at `0x0062d470` | Scalar deleting destructor in vtable. |
| `0x00581dc0` | `0x00581306`, `0x00581337` | none | Notice image draw helper called from WndProc. |
| `0x00581e40` | `0x00580cb3`, `0x00580cc2`, `0x00580cd1`, `0x00580ce4`, `0x00580db3`, `0x00580dca`, `0x00580dd9`, `0x00580dec` | none | ANSI find helper called from `RunUpdateCheck`. |
| `0x00581f50` | `0x00580cf8`, `0x00580e00` | none | ANSI substring helper called from `RunUpdateCheck`. |

The local scan confirms the existing no-direct-start-route caveat for the raw helper island and adds the same caveat for the newly identified `0x00580810` destructor-like body.

## Covered Range Recheck And Split Plan

Recommended exact physical map:

| Range | Proposed child/source-facing name | Kind | Direct owner / emitter after split | Reconstructable decision | Notes |
| --- | --- | --- | --- | --- | --- |
| `0x005807d0-0x0058080c` | `StartupWindow::StartupWindow` | constructor | [UID:0000DZ] class, emitter to [UID:0000O5] | `TRUE` | Stores singleton, vtable, `HINSTANCE`, clears flags, sets `g_useEpfAssets`. Called from `_WinMain@16`. |
| `0x0058080c-0x00580810` | constructor-to-destructor alignment | padding | ignored | `FALSE`/ignored | Four `0xcc` bytes. |
| `0x00580810-0x00580870` | `StartupWindow::~StartupWindow` / `StartupWindowReleaseOwnedNoticeObjects` | ordinary/non-deleting destructor body | [UID:0000DZ] class, emitter to [UID:0000O5] only if route accepted | `TRUE`, but no-code until route reviewed | Releases owned image/browser-like objects, clears `g_pStartupWindow`, no delete call. No direct start refs found. |
| `0x00580870-0x005810fd` | `StartupWindow::RunUpdateCheck` | method | [UID:0000DZ] class, emitter [UID:0000O5] | `TRUE` | Register/create notice window, embed Browser, registry/update/minimap/curl flow, modal loop/cleanup. Called from `_WinMain@16`. |
| `0x005810fd-0x00581100` | run-to-WndProc alignment | padding | ignored | `FALSE`/ignored | Three `0xcc` bytes. |
| `0x00581100-0x005815aa` | `StartupWindowUpdateCheckWindowProc` / `StartupNoticeWndProc` | static WndProc | [UID:0000O5] file or [UID:0000DZ] static class helper | `TRUE` | WndProc pointer installed by `RunUpdateCheck` and raw setup helper. |
| `0x005815aa-0x005815b0` | WndProc-to-raw alignment | padding | ignored | `FALSE`/ignored | Six `0xcc` bytes. |
| `0x005815b0-0x0058165a` | `StartupNoticePostButtonResult` / `StartupNoticeActivateButton` | raw helper | [UID:0000O5] or [UID:0000DZ] | `TRUE`, no-code until raw child accepted | Current target range omits final `ret 4`; corrected half-open end is `0x0058165a`. Posts `WM_USER+11` result `1` or `2`. |
| `0x0058165a-0x00581660` | accept-to-accessor alignment | padding | ignored | `FALSE`/ignored | Six `0xcc` bytes. |
| `0x00581660-0x00581664` | `StartupWindow::GetInstanceHandle` | tiny accessor | [UID:0000DZ] | `TRUE`, likely low priority | Returns `this+0x08` (`HINSTANCE`). No current callers. |
| `0x00581664-0x00581670` | accessor-to-reset alignment | padding | ignored | `FALSE`/ignored | Twelve `0xcc` bytes. |
| `0x00581670-0x00581724` | `StartupNoticeResetButtonStates` | helper | [UID:0000O5]/[UID:0000DZ] | `TRUE` | Clears nonzero button visual states and invalidates rects. |
| `0x00581724-0x00581730` | reset-to-set alignment | padding | ignored | `FALSE`/ignored | Twelve `0xcc` bytes. |
| `0x00581730-0x005817a0` | `StartupNoticeSetButtonState` | helper | [UID:0000O5]/[UID:0000DZ] | `TRUE` | IDA function record size `0x70`. Ends with `ret 8` at `0x0058179d`; bytes `0x0058179e-0x005817a0` are the immediate operand of `ret 8`, not padding. |
| `0x005817a0-0x005817dd` | `StartupNoticeHitTestButton` | helper | [UID:0000O5]/[UID:0000DZ] | `TRUE` | Scans two button rects, returns index or `-1`. |
| `0x005817dd-0x005817e0` | hit-test-to-invalidate alignment | padding | ignored | `FALSE`/ignored | Three `0xcc` bytes. |
| `0x005817e0-0x00581854` | `StartupNoticeInvalidateButtons` | raw helper | [UID:0000O5]/[UID:0000DZ] | `TRUE`, no-code until raw child accepted | Current target range omits final `ret`; corrected half-open end is `0x00581854`. |
| `0x00581854-0x00581860` | invalidate-all-to-one alignment | padding | ignored | `FALSE`/ignored | Twelve `0xcc` bytes. |
| `0x00581860-0x005818c3` | `StartupNoticeInvalidateButton` | raw helper | [UID:0000O5]/[UID:0000DZ] | `TRUE`, no-code until raw child accepted | Current target range omits final `ret 4`; corrected half-open end is `0x005818c3`. |
| `0x005818c3-0x005818d0` | invalidate-one-to-assets alignment | padding | ignored | `FALSE`/ignored | Thirteen `0xcc` bytes. |
| `0x005818d0-0x005819cc` | `StartupNoticeLoadButtonAssets` / `StartupNoticeLoadAssets` | raw helper | [UID:0000O5]/[UID:0000DZ] | `TRUE`, no-code until raw child accepted | Current target range omits final `ret 4`; corrected half-open end is `0x005819cc`. Loads PCX assets and initializes rects/states. |
| `0x005819cc-0x005819d0` | assets-to-setup alignment | padding | ignored | `FALSE`/ignored | Four `0xcc` bytes. |
| `0x005819d0-0x00581b75` | `StartupNoticeCreateWindowRaw` / `StartupWindowCreateNoticeWindow` | raw helper | [UID:0000O5]/[UID:0000DZ] | `TRUE`, no-code until raw child accepted | Builds `WNDCLASSEXA`, registers class, creates centered 500x430 notice window, stores `HWND`. |
| `0x00581b75-0x00581b80` | setup-to-callback alignment | padding | ignored | `FALSE`/ignored | Eleven `0xcc` bytes. |
| `0x00581b80-0x00581ce6` | `StartupCurlWriteCallback` / `CurlWriteCallback` | callback helper | [UID:0000O5] file | `TRUE` | Existing [UID:0001IP]. Should route directly to [UID:0000O5] after parent split. |
| `0x00581ce6-0x00581cf0` | callback-to-convert alignment | padding | ignored | `FALSE`/ignored | Ten `0xcc` bytes. |
| `0x00581cf0-0x00581d30` | `StartupAnsiRangeToWideString` | helper | [UID:0000O5] file | `TRUE` | ANSI range into UTF-16 small string. Only observed callers are in `RunUpdateCheck`. |
| `0x00581d30-0x00581db2` | `StartupWindowScalarDeletingDestructor` | compiler-generated destructor wrapper | [UID:0000DZ] class | `TRUE`, but source should be destructor, not wrapper | Vtable slot at `0x0062d470`; clears singleton and optionally deletes `this`. |
| `0x00581db2-0x00581dc0` | destructor-to-draw alignment | padding | ignored | `FALSE`/ignored | Fourteen `0xcc` bytes. |
| `0x00581dc0-0x00581e35` | `StartupNoticeDrawPcxImage` | helper | [UID:0000O5] file | `TRUE` | Compatible DC, select HBITMAP, BitBlt, cleanup. |
| `0x00581e35-0x00581e40` | draw-to-find alignment | padding | ignored | `FALSE`/ignored | Eleven `0xcc` bytes. |
| `0x00581e40-0x00581f46` | `AnsiSmallStringFindFrom` | local string helper | [UID:0000O5] unless shared owner later proven | `TRUE` | Finds needle in ANSI SSO-like buffer from offset. |
| `0x00581f46-0x00581f50` | find-to-substring alignment | padding | ignored | `FALSE`/ignored | Ten `0xcc` bytes. |
| `0x00581f50-0x0058206e` | `AnsiSmallStringSubstring` | local string helper | [UID:0000O5] unless shared owner later proven | `TRUE` | Extracts bounded ANSI substring into destination SSO buffer. |
| `0x0058206e-0x00582070` | StartupWindow-to-StdioFile alignment | padding | ignored | `FALSE`/ignored | Two `0xcc` bytes; successor `StdioFile` starts at `0x00582070`. |

The target should retain the broad physical range only as an index. Exact source-bearing C++ belongs in child pages.

## Function And Helper Reanalysis

### Constructor: `0x005807d0-0x0058080c`

Best source name: `StartupWindow::StartupWindow(HINSTANCE instance)`.

Confirmed behavior:

- Stores `this` in `g_pStartupWindow` (`0x0069bac8`).
- Writes the `StartupWindow` vtable pointer `0x0062d470`.
- Writes `g_useEpfAssets` / `byte_66DA97 = 1`.
- Stores `HINSTANCE` at `this+0x08`.
- Clears initialization/result state at `this+0x04` and `this+0x54`.
- Returns with `ret 4`.

Reachability: direct call from `_WinMain@16` at `0x004f5d3a`.

### Ordinary Destructor / Release Body: `0x00580810-0x00580870`

Best source-name options:

- `StartupWindow::~StartupWindow`
- `StartupWindowReleaseOwnedNoticeObjects`
- `StartupWindow::DestroyNoticeResources`

Best inference: compiler-emitted ordinary/non-deleting destructor body or source destructor body clone, not a standalone public helper.

Confirmed behavior:

- Restores/writes the `StartupWindow` vtable.
- Checks `this+0x04` initialized/assets-loaded flag.
- If initialized, releases object pointers by calling their vtable slot with argument `1`.
- Releases the pointer at `this+0x10`.
- Iterates two 0x20-byte button/image groups and releases pointers at group offsets consistent with `+0x14/+0x18/+0x1c` and `+0x34/+0x38/+0x3c`.
- Clears `g_pStartupWindow` (`0x0069bac8`).
- Returns without deleting `this`.

Negative evidence:

- No rel32, VA-immediate, or RVA-immediate reference to `0x00580810` was found in the local PE scan.
- It is not covered by the IDA function record at `0x005807d0`; that record ends at `0x0058080c`.
- Only `0x0058080c-0x00580810` is padding.

Implementation decision: create a child page, but do not emit final C++ from it until the project accepts no-direct-route destructor bodies as class-owned children or live IDA/vtable/exception evidence identifies a route.

### `StartupWindow::RunUpdateCheck`: `0x00580870-0x005810fd`

Best source name: `StartupWindow::RunUpdateCheck`.

Confirmed high-level behavior:

- Checks/registers `BaramNoticeWnd_Class`.
- Uses `StartupWindowUpdateCheckWindowProc` / `StartupNoticeWndProc` as the notice window procedure.
- Creates a centered 500x430 notice/update window with title `Notice`.
- Embeds Browser content from `http://www.nexustk.com/news/news.asp`.
- Reads `HKEY_CURRENT_USER\Software\KRU\NexusTK`, value `updvr`, as local update-version state.
- Fetches remote update metadata from `https://s3.amazonaws.com/kru-downloads/tk/update/nexustk.ver`.
- Installs [UID:0001IP] callback as `curl_easy_setopt(..., 20011, sub_581B80)` at two sites.
- Searches/parses `version` and `minimap` keys.
- Converts parsed ANSI ranges to UTF-16 strings for version/minimap comparisons.
- Reads [UID:00008H] `MiniMapVersionManager::GetVersionString() const`.
- Conditionally fetches `https://s3.amazonaws.com/kru-downloads/tk/minimaps/HashList.txt`.
- Calls `MiniMapVersionManager::UpdateHashList(..., saveCache=true)` when the remote minimap hash list should be applied.
- Runs the notice modal/message loop and cleans up browser/curl/string state.

Reachability: direct call from `_WinMain@16` at `0x004f5d52`.

Source placement: [UID:0000O5] `NexusTK/app/StartupWindow.cpp`, as a `StartupWindow` class method under [UID:0000DZ].

### Notice WndProc: `0x00581100-0x005815aa`

Best source name:

- `StartupWindowUpdateCheckWindowProc`
- `StartupNoticeWndProc`
- `StartupWindow::UpdateCheckWindowProc` if the project accepts a static class method spelling.

Confirmed behavior groups:

- Retrieves `g_pStartupWindow`.
- Handles keyboard accept/cancel behavior.
- Handles first-paint lazy PCX load and background/button drawing.
- Loads/draws `brm_main.pcx`, `brm_st_a.pcx`, `brm_st_b.pcx`, `brm_st_c.pcx`, `brm_ex_a.pcx`, `brm_ex_b.pcx`.
- Maintains two button rect/state slots.
- Handles mouse hit testing, hover/pressed state transitions, capture/release, and cursor behavior.
- Uses `ShellExecuteA` for the clickable top banner/home URL `http://www.nexustk.com`.
- Posts `WM_USER + 11` style result messages for update/start or close/cancel.

Pointer refs:

- `RunUpdateCheck` stores pointer to `0x00581100` into `WNDCLASSEXA.lpfnWndProc`.
- Raw setup helper at `0x005819d0` also stores pointer to `0x00581100`.

Source placement: file-local/static helper in `StartupWindow.cpp` or static `StartupWindow` method. Do not model it as a normal `thiscall` method because the entry signature is Win32 `WNDPROC`.

### Button And Asset Helpers

Best source-facing names:

| Range | Current raw/model name | Recommended source-facing name | Main behavior |
| --- | --- | --- | --- |
| `0x005815b0-0x0058165a` | raw notice accept/close helper | `StartupNoticePostButtonResult` | Branches on button index, sets cursor/state, posts result message `1` or `2` to notice `HWND`. |
| `0x00581660-0x00581664` | `sub_581660` | `StartupWindow::GetInstanceHandle` | Returns `HINSTANCE` at `this+0x08`; no callers found. |
| `0x00581670-0x00581724` | `sub_581670` | `StartupNoticeResetButtonStates` | Clears nonzero visual states and invalidates both button rects. |
| `0x00581730-0x005817a0` | `sub_581730` | `StartupNoticeSetButtonState` | Updates indexed state at `this+0x30 + index*0x20`; invalidates changed button. |
| `0x005817a0-0x005817dd` | `sub_5817A0` | `StartupNoticeHitTestButton` | Tests two rects at `this+0x20` and `this+0x40`; returns button index or `-1`. |
| `0x005817e0-0x00581854` | raw reset-all helper | `StartupNoticeInvalidateButtons` | Invalidates both button rects. |
| `0x00581860-0x005818c3` | raw one-button invalidate helper | `StartupNoticeInvalidateButton` | Invalidates one button rect by index. |
| `0x005818d0-0x005819cc` | raw notice asset loader | `StartupNoticeLoadAssets` / `StartupNoticeLoadButtonAssets` | Lazy loads PCX assets and initializes button bounds/states. |
| `0x005819d0-0x00581b75` | raw alternate setup helper | `StartupNoticeCreateWindowRaw` | Builds/registers notice WNDCLASS and creates centered notice HWND. |

Rejected names:

- `sub_581xxx`: raw placeholder names, not source quality.
- `raw reset-all helper`: useful for old evidence only, not a final source-facing label.
- Generic `ButtonHelper`: too vague; the helper family is specific to startup notice/update UI.

### Curl Callback: `0x00581b80-0x00581ce6`

Existing child: [UID:0001IP] `CurlWriteCallback`.

Best source name: `StartupCurlWriteCallback` or file-local `CurlWriteCallback`.

Confirmed behavior:

- Installed twice from `RunUpdateCheck` via `curl_easy_setopt(..., 20011, callback)`.
- Appends incoming text response data to an ANSI SSO-like buffer.
- Returns `elementSize * elementCount`.
- Uses `strlen`-style incoming data length behavior, so document as text-response callback for update/minimap metadata, not binary-safe generic sink.

Ownership correction after parent split:

- Current child metadata routes through [UID:0001IO].
- If [UID:0001IO] becomes non-emitting, [UID:0001IP] should have `CANONICAL_OWNER:0000O5`, `EMITTER_UIDS:0000O5`.

### String And Conversion Helpers

| Range | Recommended source-facing name | Evidence | Ownership decision |
| --- | --- | --- | --- |
| `0x00581cf0-0x00581d30` | `StartupAnsiRangeToWideString` | Called at `0x00580e3f` and `0x00580fb6` from `RunUpdateCheck`; initializes UTF-16 small string and copies/converts an ANSI range. | StartupWindow-local helper for now. |
| `0x00581e40-0x00581f46` | `AnsiSmallStringFindFrom` | Eight callers, all in `RunUpdateCheck`; finds needle in SSO-like ANSI buffer from offset. | StartupWindow-local parse helper unless future broad caller evidence appears. |
| `0x00581f50-0x0058206e` | `AnsiSmallStringSubstring` | Two callers in `RunUpdateCheck`; initializes/copies destination SSO substring. | StartupWindow-local parse helper unless future broad caller evidence appears. |

These are source-shaped helpers but still carry type-name uncertainty. Avoid final project-global `StringUtil` names unless a separate broad caller pass proves sharing.

### Destructor Wrapper: `0x00581d30-0x00581db2`

Best binary-artifact name: `StartupWindowScalarDeletingDestructor`.

Source-facing reconstruction should be the class destructor, not a hand-authored scalar-deleting function. The compiler wrapper:

- Restores the `StartupWindow` vtable.
- Releases initialized image/browser pointers using vtable slot calls with argument `1`.
- Clears `g_pStartupWindow`.
- Checks delete flag `[ebp+8] & 1`.
- Calls delete helper `0x005c7526(this, 0x58)` when delete flag is set.
- Returns `this`.

Vtable evidence: [UID:00026K] reports `0x0062d470 -> 0x00581d30`.

### Draw Helper: `0x00581dc0-0x00581e35`

Best source name: `StartupNoticeDrawPcxImage`.

Behavior:

- Creates compatible DC.
- If image pointer and HBITMAP are nonnull, selects bitmap.
- Gets image width/height through image helper calls.
- Calls `BitBlt`.
- Restores selection and deletes compatible DC.

Ownership: StartupWindow file-local drawing helper; image object implementation remains ImageLoaders/rendering support.

## Field, Type, And Global Reanalysis

### StartupWindow Object Layout

Best current field map for `sizeof(StartupWindow) == 0x58`:

| Offset | Best type/name | Evidence |
| --- | --- | --- |
| `+0x00` | vtable pointer | Constructor and destructor write `0x0062d470`; vtable slot points to scalar deleting destructor. |
| `+0x04` | `m_noticeAssetsLoaded` / init flag | Constructor clears; asset loader checks/sets; destructor release paths gated by this byte/dword. |
| `+0x08` | `HINSTANCE m_instance` | Constructor stores argument; tiny accessor returns this dword; WndProc/setup uses instance for Win32 APIs. |
| `+0x0c` | `HWND m_noticeWindow` | Raw setup stores create-window result; button helpers post/invalidate against this HWND. |
| `+0x10` | background/news/browser-like owned pointer | Destructor releases pointer; asset path loads `brm_main.pcx` into this slot in raw loader. Current docs also mention browser cleanup in RunUpdateCheck, so final field split must be checked in child C++. |
| `+0x14` | start button normal image | Asset loader loads `brm_st_a.pcx`; destructor releases. |
| `+0x18` | start button hover image | Asset loader loads `brm_st_b.pcx`; destructor releases. |
| `+0x1c` | start button pressed image | Asset loader loads `brm_st_c.pcx`; destructor releases. |
| `+0x20` | `RECT m_startButtonRect` | Asset loader initializes; state helpers/hit-test use first rect. |
| `+0x30` | `int m_startButtonState` | Button state slot for index 0. |
| `+0x34` | exit button normal image | Asset loader loads `brm_ex_a.pcx`. |
| `+0x38` | exit button middle/hover image placeholder | Asset loader clears to zero; destructor release loop checks pointer. |
| `+0x3c` | exit button pressed image | Asset loader loads `brm_ex_b.pcx`. |
| `+0x40` | `RECT m_exitButtonRect` | Asset loader initializes; state helpers/hit-test use second rect. |
| `+0x50` | `int m_exitButtonState` | Button state slot for index 1. |
| `+0x54` | result/decision byte or flag | Constructor clears; `RunUpdateCheck`/message loop likely uses it for result. Final child C++ should verify exact semantics before naming. |

Open detail closed as best inference:

- `+0x38` is an owned pointer slot in the destructor loop but the raw asset loader sets it to zero. The safest name is a placeholder such as `m_exitButtonHoverImage` or `m_exitButtonUnusedImage`, with a note that the current binary does not load a `brm_ex_*` hover asset into it.
- `+0x10` needs child-level verification because target docs describe both browser/notice image ownership. The raw asset loader clearly writes `brm_main.pcx` there; Browser object lifetime in `RunUpdateCheck` may use locals or another slot. Do not over-name `+0x10` as Browser without checking exact child body.

### Globals And Data

| Address / UID | Source-facing name | Decision |
| --- | --- | --- |
| `0x0069bac4` / [UID:0002AM], [UID:0002ZQ] | `g_startupWindowClassAtom` | StartupWindow-owned global atom/registration state. |
| `0x0069bac8` / [UID:0002AM], [UID:0002ZS] | `g_pStartupWindow` | StartupWindow singleton/current notice object pointer. Constructor writes; WndProc/destructors read/clear. |
| `0x0066da97` / [UID:0000SW] | `g_useEpfAssets` | Startup constructor forces current EPF/current-layout mode. Existing global owner remains correct. |
| `0x0062d470` / [UID:00026K] | `StartupWindow` vtable | Compiler-generated from class declaration; destructor slot points to `0x00581d30`. |
| `0x00670260` / [UID:000288] | pointer to `kStartupNoticeWindowClassName` | Writable pointer slot to `"BaramNoticeWnd_Class"` at `0x0062d418`. |
| `0x00670264` / [UID:000288] | pointer to `kStartupNoticeWindowTitle` | Writable pointer slot to `"Notice"` at `0x0062d430`. |
| `0x0062d474` / [UID:00026K] | `kStartupNewsUrl` | Browser news panel URL. |
| `0x0062d49c` / [UID:00026K] | `kStartupRegistryUpdateVersionValue` | Wide `L"updvr"` registry value. |
| `0x0062d4a8` / [UID:00026K] | `kStartupUpdateVersionUrl` | Remote `nexustk.ver` URL. |
| `0x0060d94c` / [UID:0003G1] | shared `"version"` key | Shared JSON/metadata key; StartupWindow is a source-use route, not sole owner. |
| `0x0062d4e8` / [UID:00026K] | `kStartupUpdateMinimapKey` | `"minimap"` update metadata key. |
| `0x0062d4f0` / [UID:00026K] | `kStartupMinimapHashListUrl` | Remote `HashList.txt` URL. |
| `0x0062d530-0x0062d580` / [UID:00026K] | `kStartupNotice*Pcx` literals | Startup notice PCX asset names. |
| `0x0062d590` / [UID:00026K] | `kStartupNoticeHomeUrl` | Top banner/home URL for WndProc `ShellExecuteA`. |

## Caller, Reachability, And Ownership

Primary reachability:

- Constructor `0x005807d0`: called from `_WinMain@16` at `0x004f5d3a`.
- `RunUpdateCheck` `0x00580870`: called from `_WinMain@16` at `0x004f5d52`.
- WndProc `0x00581100`: no direct call, but used as `WNDCLASSEXA.lpfnWndProc` by `RunUpdateCheck` and by raw setup helper.
- Existing curl callback `0x00581b80`: no direct call, but two callback-pointer data refs in `RunUpdateCheck`.
- Scalar deleting destructor `0x00581d30`: vtable data ref at `0x0062d470`.
- Modeled button/draw/string helpers: direct call refs from WndProc or `RunUpdateCheck` as listed above.
- Raw helper starts and `0x00580810`: no local PE start refs found. They are source-shaped bodies but need no-route caveats.

Ownership decisions:

- [UID:0000O5] `StartupWindow` is the correct source-file root for this whole family.
- [UID:0000DZ] `StartupWindow` is the narrow direct class owner for constructor/destructor/RunUpdateCheck and possibly class-static WndProc/button helpers.
- [UID:0001IP] curl callback should be file-local StartupWindow glue, not libcurl source.
- [UID:00008H]/[UID:0000LF] `MiniMapVersionManager` owns minimap hash-list state and persistence; StartupWindow owns fetch trigger and downloaded response selection.
- [UID:0000HV] Browser owns the embedded browser implementation; StartupWindow owns use/configuration of the news URL.
- [UID:0000K3] ImageLoaders owns PCX decoding; StartupWindow owns the resource names and loaded-object lifetime.
- Shared `"version"` key ownership remains with the shared key/data page; StartupWindow is one consumer.

## Source Placement And C++ Readiness

### Aggregate Eligibility Decision

[UID:0001IO] is not eligible for first-draft C++ as one aggregate.

Target-specific no-code proof:

- The range covers many independent functions and helper bodies, not one source routine.
- The range contains padding spans that cannot appear in source.
- It already contains a child page [UID:0001IP], and parent C++ must not duplicate child/sibling source.
- Several raw helper starts have no IDA function objects and no direct start refs. They can be documented as child pages with caveats, but the aggregate should not hide those caveats inside a large source block.
- The current target still has a false boundary claim for `0x0058080c-0x00580870`.
- [UID:0001IO]'s current `RECONSTRUCTABLE:TRUE` and `EMITTER_UIDS:0000O5` are useful as historical route state, but after exact child split they should be replaced by child-level route metadata.
- `by-structure.md` requires `RECONSTRUCTION_CPP` content to be limited to the page's own source item and says broad mixed/index ranges should not paste child source into parent pages.

### Child-Level C++ Readiness

The following child pages would be C++-eligible after split, metadata routing, and written evidence update:

| Child | Eligibility after split | Emitter metadata |
| --- | --- | --- |
| `StartupWindow::StartupWindow` | Eligible for first-draft C++ once exact child page exists. | `CANONICAL_OWNER:0000DZ`, `EMITTER_UIDS:0000O5` or class route if class emits through file. |
| `StartupWindow::RunUpdateCheck` | Eligible for source-like C++ after helper pages and local type names are documented. Large, but behavior is sufficiently understood. | `CANONICAL_OWNER:0000DZ`, `EMITTER_UIDS:0000O5`. |
| `StartupWindowUpdateCheckWindowProc` | Eligible after button-state helper names/types are recorded. | `CANONICAL_OWNER:0000O5` or `0000DZ`, `EMITTER_UIDS:0000O5`. |
| Modeled button helpers `0x00581670`, `0x00581730`, `0x005817a0` | Eligible with descriptive names and object layout. | [UID:0000O5] or [UID:0000DZ]. |
| Draw helper `0x00581dc0` | Eligible with descriptive file-local name. | [UID:0000O5]. |
| Curl callback [UID:0001IP] | Eligible after small-string type spelling is accepted. | `CANONICAL_OWNER:0000O5`, `EMITTER_UIDS:0000O5`. |

The following should remain blank/no-code until no-route or source-type blockers are closed:

- `0x00580810-0x00580870` ordinary destructor/release body: no direct route found.
- Raw helpers `0x005815b0`, `0x005817e0`, `0x00581860`, `0x005818d0`, `0x005819d0`: no IDA function objects and no start refs found.
- String helpers `0x00581cf0`, `0x00581e40`, `0x00581f50`: behavior clear, but exact SSO/string type policy and shared/local ownership need final source-policy confirmation.
- Scalar deleting destructor wrapper `0x00581d30`: generated wrapper; source should be destructor implementation, not wrapper code.

Source-like placement:

```text
NexusTK/app/StartupWindow.cpp
  class StartupWindow methods:
    StartupWindow::StartupWindow(HINSTANCE)
    StartupWindow::~StartupWindow()
    StartupWindow::RunUpdateCheck()

  file-local/static helpers:
    StartupWindowUpdateCheckWindowProc(HWND, UINT, WPARAM, LPARAM)
    StartupCurlWriteCallback(char*, size_t, size_t, void*)
    StartupNotice* button/asset/draw helpers
    StartupAnsiRangeToWideString / local parse helpers
```

## Open Questions Closed Or Carried Forward

| Question | Closure |
| --- | --- |
| Should this remain one aggregate for C++? | Closed: no. It should split before C++; the aggregate becomes a non-emitting split/index. |
| Is `0x0058080c-0x00580870` padding? | Closed: no. Only `0x0058080c-0x00580810` is padding; `0x00580810-0x00580870` is valid destructor-like code. |
| Are raw helper starts real code? | Closed: yes. They are valid source-shaped functions/helpers, but remain no-IDA-function/no-start-ref children. |
| Are raw helper exact ends known enough for child pages? | Best-inferred: yes for half-open byte ranges listed above, based on return instructions and `0xcc` padding. Live IDA function creation is still not present. |
| Is the alternate setup helper `0x005819d0` reachable? | Best-inferred no direct start route found. It is still source-shaped and references class/title/WndProc; child should retain no-route caveat. |
| Who owns Browser/curl/minimap/ImageLoaders behavior? | Closed: StartupWindow owns orchestration/glue/constants; Browser/libcurl/ImageLoaders/MiniMapVersionManager own their implementations/state. |
| Are string helpers StartupWindow or shared utility? | Best-supported current decision: StartupWindow-local because all recorded callers are in `RunUpdateCheck`. Carry forward a low-risk review question if broader scans later find callers. |
| Are compiler-generated names source names? | Closed: no. Vtable/COL/scalar deleting destructor/security-cookie artifacts should be documented as compiler-generated. |
| Can the child source names be final original names? | Best-supported names are descriptive, not PDB-proven. They are still source-quality enough to replace raw `sub_` labels in docs. |

## Proposed Score And Metadata Changes

Target [UID:0001IO] after implementation:

| Field | Current | Proposed after split/update | Rationale |
| --- | --- | --- | --- |
| `COMPLETION` | `85` | `88` | Adds corrected `0x00580810` child, exact split map, raw end corrections, closed ownership/source-placement questions, and no-code proof. |
| `CONFIDENCE` | `87` | `90` | Strong local PE and existing IDA-backed evidence support ranges/ownership. Confidence stays below 95 because raw starts lack IDA function objects/direct refs and final original source names are inferred. |
| `CANONICAL_OWNER` | `0000O5` | `0000O5` | The aggregate remains semantically contained by StartupWindow source. |
| `RECONSTRUCTABLE` | `TRUE` | `FALSE` after child split | The parent is an address-neighborhood index once exact children carry source ownership. |
| `EMITTER_UIDS` | `0000O5` | blank | The parent should not emit; children should emit directly to `StartupWindow.cpp`. |
| `RECONSTRUCTION_CPP` | blank | blank | Aggregate C++ is not source-valid. |

Support page changes recommended:

- [UID:0001IP] `CurlWriteCallback`: keep `86/90`; change direct owner/emitter from [UID:0001IO] to [UID:0000O5] after parent becomes non-emitting.
- [UID:0000VI] raw helper tracker: update to mention `0x00580810` separately if scope is expanded, or explicitly keep its title limited to `0x005815b0-0x00581b7f` and cross-link the new child.
- [UID:0000O5] StartupWindow file: keep as file source root; add note that [UID:0001IO] is non-emitting split inventory after child split.
- [UID:0000DZ] StartupWindow class: add child refs for constructor/destructor/RunUpdateCheck and class layout offsets once child pages exist.
- [UID:00026K] read-only data and [UID:0001RO] resources: no required score change; add cross-links only if child pages are created.

## Exact Supervisor-Owned Coverage Row Text

Current exact row block in `by-memory/-coverage-report.md`:

```markdown
    - [UID:0000VN][-ignored](by-memory/-ignored.md) 0x005807c5-0x005807d0 | padding | MacroEditControlPanes to StartupWindowUpdateCheck alignment : ignored : 100% : strong : IDA MCP/raw-byte check shows eleven `0xcc` alignment bytes.
    - [UID:0001IO][0x005807d0-0x0058206e.StartupWindowUpdateCheck](by-memory/0x005807d0-0x0058206e.StartupWindowUpdateCheck.md) 0x005807d0-0x0058206e | aggregate | StartupWindowUpdateCheck : reconstructable : 84% : strong : Startup/update notice executable island with IDA-backed function inventory, raw helper starts, caller/xref evidence, touched globals/resources, padding boundaries, and unresolved raw-helper child split debt.
        - [UID:0001IP][0x00581b80-0x00581ce6.CurlWriteCallback](by-memory/0x00581b80-0x00581ce6.CurlWriteCallback.md) 0x00581b80-0x00581ce6 | callback helper | CurlWriteCallback : reconstructable : 74% : strong : Exact libcurl write callback child used only by StartupWindow::RunUpdateCheck callback-pointer setup sites; appends text response data into the startup update buffer.
    - [UID:0000VN][-ignored](by-memory/-ignored.md) 0x0058206e-0x00582070 | padding | StartupWindowUpdateCheck to StdioFile alignment : ignored : 100% : strong : IDA MCP/raw-byte check shows two `0xcc` alignment bytes.
```

Immediate exact replacement row block that can be applied before creating new child UIDs:

```markdown
    - [UID:0000VN][-ignored](by-memory/-ignored.md) 0x005807c5-0x005807d0 | padding | MacroEditControlPanes to StartupWindowUpdateCheck alignment : ignored : 100% : strong : IDA MCP/raw-byte check shows eleven `0xcc` alignment bytes.
    - [UID:0001IO][0x005807d0-0x0058206e.StartupWindowUpdateCheck](by-memory/0x005807d0-0x0058206e.StartupWindowUpdateCheck.md) 0x005807d0-0x0058206e | split-needed aggregate | StartupWindowUpdateCheck : reconstructable : 85% : strong : Startup/update notice executable island with constructor, newly confirmed `0x00580810` destructor-like raw body after four-byte padding, RunUpdateCheck, WndProc, raw notice helpers, callback/string helpers, globals/resources, caller/xref evidence, and unresolved exact-child split/C++ debt; aggregate C++ must remain blank until child pages carry source ownership.
        - [UID:0001IP][0x00581b80-0x00581ce6.CurlWriteCallback](by-memory/0x00581b80-0x00581ce6.CurlWriteCallback.md) 0x00581b80-0x00581ce6 | callback helper | CurlWriteCallback : reconstructable : 86% : strong : Exact StartupWindow/libcurl write callback child used only by `RunUpdateCheck` callback-pointer setup sites; appends text update/minimap responses into the startup update buffer and should route directly to StartupWindow if the parent aggregate becomes non-emitting.
    - [UID:0000VN][-ignored](by-memory/-ignored.md) 0x0058206e-0x00582070 | padding | StartupWindowUpdateCheck to StdioFile alignment : ignored : 100% : strong : IDA MCP/raw-byte check shows two `0xcc` alignment bytes.
```

Recommended post-split replacement block. `NEW_UID_*` placeholders must be replaced with validator-assigned UIDs after creating the child pages; do not guess real UIDs in advance:

```markdown
    - [UID:0000VN][-ignored](by-memory/-ignored.md) 0x005807c5-0x005807d0 | padding | MacroEditControlPanes to StartupWindowUpdateCheck alignment : ignored : 100% : strong : IDA MCP/raw-byte check shows eleven `0xcc` alignment bytes.
    - [UID:0001IO][0x005807d0-0x0058206e.StartupWindowUpdateCheck](by-memory/0x005807d0-0x0058206e.StartupWindowUpdateCheck.md) 0x005807d0-0x0058206e | split index | StartupWindowUpdateCheck : ignored : 88% : strong : Non-emitting split inventory for the StartupWindow update-notice executable neighborhood; B010 2026-06-19 reanalysis confirms exact constructor/destructor/run/WndProc/callback/string-helper/padding map, newly separates `0x00580810-0x00580870` as destructor-like code, corrects raw helper return-inclusive ranges, assigns source ownership to StartupWindow child pages, and leaves aggregate C++ blank by parent/child source-boundary policy.
        - [UID:NEW_UID_CTOR][0x005807d0-0x0058080c.StartupWindowConstructor](by-memory/0x005807d0-0x0058080c.StartupWindowConstructor.md) 0x005807d0-0x0058080c | constructor | StartupWindowConstructor : reconstructable : 88% : strong : `StartupWindow::StartupWindow(HINSTANCE)` called from `_WinMain@16`; stores singleton, vtable, instance handle, startup flags, and `g_useEpfAssets`.
        - [UID:0000VN][-ignored](by-memory/-ignored.md) 0x0058080c-0x00580810 | padding | StartupWindow constructor to ordinary destructor alignment : ignored : 100% : strong : Local PE byte check shows four `0xcc` bytes before the newly identified destructor-like body.
        - [UID:NEW_UID_ORD_DTOR][0x00580810-0x00580870.StartupWindowOrdinaryDestructor](by-memory/0x00580810-0x00580870.StartupWindowOrdinaryDestructor.md) 0x00580810-0x00580870 | destructor body | StartupWindowOrdinaryDestructor : reconstructable : 85% : strong : Source-shaped non-deleting StartupWindow release body; releases loaded notice/browser image pointers and clears `g_pStartupWindow`, with no direct rel32/VA/RVA start refs found.
        - [UID:NEW_UID_RUN][0x00580870-0x005810fd.StartupWindowRunUpdateCheck](by-memory/0x00580870-0x005810fd.StartupWindowRunUpdateCheck.md) 0x00580870-0x005810fd | method | StartupWindowRunUpdateCheck : reconstructable : 88% : strong : `_WinMain@16`-called update orchestration method; registers/creates notice window, embeds Browser news URL, reads `HKCU\Software\KRU\NexusTK\updvr`, fetches/parses `nexustk.ver`, and conditionally fetches minimap `HashList.txt`.
        - [UID:0000VN][-ignored](by-memory/-ignored.md) 0x005810fd-0x00581100 | padding | StartupWindow RunUpdateCheck to notice WndProc alignment : ignored : 100% : strong : Local PE byte check shows three `0xcc` bytes.
        - [UID:NEW_UID_WNDPROC][0x00581100-0x005815aa.StartupWindowUpdateCheckWindowProc](by-memory/0x00581100-0x005815aa.StartupWindowUpdateCheckWindowProc.md) 0x00581100-0x005815aa | WndProc | StartupWindowUpdateCheckWindowProc : reconstructable : 88% : strong : Static StartupWindow notice WndProc registered by RunUpdateCheck and raw setup helper; handles paint, keyboard, mouse/button states, cursor, top-link `ShellExecuteA`, PCX drawing, and result posting.
        - [UID:0000VN][-ignored](by-memory/-ignored.md) 0x005815aa-0x005815b0 | padding | StartupWindow notice WndProc to post-button-result raw helper alignment : ignored : 100% : strong : Six `0xcc` bytes before raw helper-shaped code.
        - [UID:NEW_UID_POST_RESULT][0x005815b0-0x0058165a.StartupNoticePostButtonResult](by-memory/0x005815b0-0x0058165a.StartupNoticePostButtonResult.md) 0x005815b0-0x0058165a | raw helper | StartupNoticePostButtonResult : reconstructable : 85% : strong : Raw no-IDA-function helper that handles update/close button activation, updates visual state, and posts `WM_USER+11` result messages; no direct start refs found.
        - [UID:0000VN][-ignored](by-memory/-ignored.md) 0x0058165a-0x00581660 | padding | StartupNoticePostButtonResult to StartupWindowGetInstanceHandle alignment : ignored : 100% : strong : Six `0xcc` bytes after the raw helper return.
        - [UID:NEW_UID_HINSTANCE][0x00581660-0x00581664.StartupWindowGetInstanceHandle](by-memory/0x00581660-0x00581664.StartupWindowGetInstanceHandle.md) 0x00581660-0x00581664 | accessor | StartupWindowGetInstanceHandle : reconstructable : 84% : strong : Tiny accessor returning `StartupWindow +0x08` `HINSTANCE`; no current callers found.
        - [UID:0000VN][-ignored](by-memory/-ignored.md) 0x00581664-0x00581670 | padding | StartupWindowGetInstanceHandle to StartupNoticeResetButtonStates alignment : ignored : 100% : strong : Twelve `0xcc` bytes.
        - [UID:NEW_UID_RESET][0x00581670-0x00581724.StartupNoticeResetButtonStates](by-memory/0x00581670-0x00581724.StartupNoticeResetButtonStates.md) 0x00581670-0x00581724 | helper | StartupNoticeResetButtonStates : reconstructable : 86% : strong : WndProc-called helper that clears start/exit button visual state slots and invalidates changed button rectangles.
        - [UID:0000VN][-ignored](by-memory/-ignored.md) 0x00581724-0x00581730 | padding | StartupNoticeResetButtonStates to StartupNoticeSetButtonState alignment : ignored : 100% : strong : Twelve `0xcc` bytes.
        - [UID:NEW_UID_SET][0x00581730-0x005817a0.StartupNoticeSetButtonState](by-memory/0x00581730-0x005817a0.StartupNoticeSetButtonState.md) 0x00581730-0x005817a0 | helper | StartupNoticeSetButtonState : reconstructable : 86% : strong : WndProc/raw-helper-called button state setter for two `0x20`-stride notice button slots; invalidates the target rectangle when state changes.
        - [UID:NEW_UID_HIT][0x005817a0-0x005817dd.StartupNoticeHitTestButton](by-memory/0x005817a0-0x005817dd.StartupNoticeHitTestButton.md) 0x005817a0-0x005817dd | helper | StartupNoticeHitTestButton : reconstructable : 86% : strong : WndProc-called hit-test helper scanning two StartupWindow button rectangles and returning a button index or `-1`.
        - [UID:0000VN][-ignored](by-memory/-ignored.md) 0x005817dd-0x005817e0 | padding | StartupNoticeHitTestButton to StartupNoticeInvalidateButtons alignment : ignored : 100% : strong : Three `0xcc` bytes.
        - [UID:NEW_UID_INV_ALL][0x005817e0-0x00581854.StartupNoticeInvalidateButtons](by-memory/0x005817e0-0x00581854.StartupNoticeInvalidateButtons.md) 0x005817e0-0x00581854 | raw helper | StartupNoticeInvalidateButtons : reconstructable : 85% : strong : Raw no-IDA-function helper that invalidates both notice button rectangles; corrected range includes final `ret`.
        - [UID:0000VN][-ignored](by-memory/-ignored.md) 0x00581854-0x00581860 | padding | StartupNoticeInvalidateButtons to StartupNoticeInvalidateButton alignment : ignored : 100% : strong : Twelve `0xcc` bytes.
        - [UID:NEW_UID_INV_ONE][0x00581860-0x005818c3.StartupNoticeInvalidateButton](by-memory/0x00581860-0x005818c3.StartupNoticeInvalidateButton.md) 0x00581860-0x005818c3 | raw helper | StartupNoticeInvalidateButton : reconstructable : 85% : strong : Raw no-IDA-function helper that copies and invalidates one indexed notice button rectangle; corrected range includes final `ret 4`.
        - [UID:0000VN][-ignored](by-memory/-ignored.md) 0x005818c3-0x005818d0 | padding | StartupNoticeInvalidateButton to StartupNoticeLoadAssets alignment : ignored : 100% : strong : Thirteen `0xcc` bytes.
        - [UID:NEW_UID_ASSETS][0x005818d0-0x005819cc.StartupNoticeLoadAssets](by-memory/0x005818d0-0x005819cc.StartupNoticeLoadAssets.md) 0x005818d0-0x005819cc | raw helper | StartupNoticeLoadAssets : reconstructable : 86% : strong : Raw no-IDA-function lazy PCX asset loader for `brm_main`, `brm_st_a/b/c`, and `brm_ex_a/b`, including notice button bounds/state initialization; corrected range includes final `ret 4`.
        - [UID:0000VN][-ignored](by-memory/-ignored.md) 0x005819cc-0x005819d0 | padding | StartupNoticeLoadAssets to StartupNoticeCreateWindowRaw alignment : ignored : 100% : strong : Four `0xcc` bytes.
        - [UID:NEW_UID_CREATE_RAW][0x005819d0-0x00581b75.StartupNoticeCreateWindowRaw](by-memory/0x005819d0-0x00581b75.StartupNoticeCreateWindowRaw.md) 0x005819d0-0x00581b75 | raw helper | StartupNoticeCreateWindowRaw : reconstructable : 85% : strong : Raw no-IDA-function alternate notice setup helper; builds `WNDCLASSEXA`, uses the StartupWindow WndProc pointer and notice class/title strings, centers a 500x430 window, and stores the `HWND`, with no direct start refs found.
        - [UID:0000VN][-ignored](by-memory/-ignored.md) 0x00581b75-0x00581b80 | padding | StartupNoticeCreateWindowRaw to CurlWriteCallback alignment : ignored : 100% : strong : Eleven `0xcc` bytes before callback child.
        - [UID:0001IP][0x00581b80-0x00581ce6.CurlWriteCallback](by-memory/0x00581b80-0x00581ce6.CurlWriteCallback.md) 0x00581b80-0x00581ce6 | callback helper | CurlWriteCallback : reconstructable : 86% : strong : StartupWindow/libcurl write callback used only by `RunUpdateCheck` callback-pointer setup sites; appends text update/minimap responses into the startup update buffer and should route directly to [UID:0000O5] after parent split.
        - [UID:0000VN][-ignored](by-memory/-ignored.md) 0x00581ce6-0x00581cf0 | padding | CurlWriteCallback to StartupAnsiRangeToWideString alignment : ignored : 100% : strong : Ten `0xcc` bytes.
        - [UID:NEW_UID_ANSI_WIDE][0x00581cf0-0x00581d30.StartupAnsiRangeToWideString](by-memory/0x00581cf0-0x00581d30.StartupAnsiRangeToWideString.md) 0x00581cf0-0x00581d30 | helper | StartupAnsiRangeToWideString : reconstructable : 85% : strong : StartupWindow-local helper converting selected ANSI response ranges into UTF-16 small strings for update/minimap comparison.
        - [UID:NEW_UID_SCALAR_DTOR][0x00581d30-0x00581db2.StartupWindowScalarDeletingDestructor](by-memory/0x00581d30-0x00581db2.StartupWindowScalarDeletingDestructor.md) 0x00581d30-0x00581db2 | compiler destructor wrapper | StartupWindowScalarDeletingDestructor : reconstructable : 86% : strong : Vtable-referenced scalar deleting destructor wrapper for StartupWindow; releases owned notice/browser image pointers, clears `g_pStartupWindow`, and conditionally deletes `this`.
        - [UID:0000VN][-ignored](by-memory/-ignored.md) 0x00581db2-0x00581dc0 | padding | StartupWindowScalarDeletingDestructor to StartupNoticeDrawPcxImage alignment : ignored : 100% : strong : Fourteen `0xcc` bytes.
        - [UID:NEW_UID_DRAW][0x00581dc0-0x00581e35.StartupNoticeDrawPcxImage](by-memory/0x00581dc0-0x00581e35.StartupNoticeDrawPcxImage.md) 0x00581dc0-0x00581e35 | helper | StartupNoticeDrawPcxImage : reconstructable : 86% : strong : StartupWindow-local draw helper that creates a compatible DC, selects a PCX-backed bitmap, blits it, and deletes the DC.
        - [UID:0000VN][-ignored](by-memory/-ignored.md) 0x00581e35-0x00581e40 | padding | StartupNoticeDrawPcxImage to AnsiSmallStringFindFrom alignment : ignored : 100% : strong : Eleven `0xcc` bytes.
        - [UID:NEW_UID_FIND][0x00581e40-0x00581f46.AnsiSmallStringFindFrom](by-memory/0x00581e40-0x00581f46.AnsiSmallStringFindFrom.md) 0x00581e40-0x00581f46 | helper | AnsiSmallStringFindFrom : reconstructable : 85% : strong : StartupWindow update-response parse helper that searches an ANSI SSO-like buffer from an offset; all observed callers are in `RunUpdateCheck`.
        - [UID:0000VN][-ignored](by-memory/-ignored.md) 0x00581f46-0x00581f50 | padding | AnsiSmallStringFindFrom to AnsiSmallStringSubstring alignment : ignored : 100% : strong : Ten `0xcc` bytes.
        - [UID:NEW_UID_SUBSTR][0x00581f50-0x0058206e.AnsiSmallStringSubstring](by-memory/0x00581f50-0x0058206e.AnsiSmallStringSubstring.md) 0x00581f50-0x0058206e | helper | AnsiSmallStringSubstring : reconstructable : 85% : strong : StartupWindow update-response parse helper that extracts a bounded ANSI SSO-like substring; all observed callers are in `RunUpdateCheck`.
    - [UID:0000VN][-ignored](by-memory/-ignored.md) 0x0058206e-0x00582070 | padding | StartupWindowUpdateCheck to StdioFile alignment : ignored : 100% : strong : IDA MCP/raw-byte check shows two `0xcc` alignment bytes.
```

## Target Implementation Checklist

For the target page [UID:0001IO]:

- Replace the stale statement that bytes after the constructor are padding before `RunUpdateCheck`.
- Add the `0x0058080c-0x00580810` padding and `0x00580810-0x00580870` destructor-like body evidence.
- Update the covered-ranges table to the exact split map above.
- Correct raw helper end ranges so they include return bytes:
  - `0x005815b0-0x0058165a`
  - `0x005817e0-0x00581854`
  - `0x00581860-0x005818c3`
  - `0x005818d0-0x005819cc`
  - `0x005819d0-0x00581b75`
- Replace remaining `sub_`/raw-only helper labels with best source-facing names while preserving raw/no-route caveats.
- Add a source-quality section documenting fields, globals, callback/string helper ownership, browser/curl/minimap boundaries, and compiler-generated artifacts.
- Change [UID:0001IO] to a non-emitting split/index after child pages exist:
  - `RECONSTRUCTABLE:FALSE`
  - blank `EMITTER_UIDS`
  - blank `RECONSTRUCTION_CPP`
  - `COMPLETION:88`
  - `CONFIDENCE:90`
- If child pages are not created in the same implementation callback, do not flip [UID:0001IO] to non-emitting yet unless [UID:0001IP] is also rerouted; use the immediate replacement row and keep aggregate C++ blank.

## Support Implementation Checklist

Child/support changes:

- Create exact child pages for the source-bearing ranges listed in the post-split coverage block.
- Create or reuse ignored padding rows for the exact `0xcc` spans.
- Update [UID:0001IP] `CurlWriteCallback` owner/emitter from [UID:0001IO] to [UID:0000O5] if [UID:0001IO] becomes non-emitting.
- Update [UID:0000VI] `StartupWindowUnmodeledNoticeHelpers_5815b0_581b7f` with corrected raw helper ranges and the no-direct-start-ref PE scan results. Keep its scope limited to `0x005815b0-0x00581b7f`; do not silently absorb `0x00580810` unless the title/range is changed.
- Update [UID:0000O5] `StartupWindow` file page with the child split and note that the old broad [UID:0001IO] page is now an index.
- Update [UID:0000DZ] `StartupWindow` class page with constructor/destructor/RunUpdateCheck children and the best current `0x58` field layout.
- Keep Browser, ImageLoaders, MiniMapVersionManager, libcurl, and shared `"version"` ownership boundaries as dependencies, not StartupWindow-owned implementations.
- Run validator in file mode for each new child and then a relevant folder/report dry run before editing coverage.
- Replace the supervisor-owned `by-memory/-coverage-report.md` row only after child pages have real UIDs; use placeholders above only as a template, not literal final UIDs.

## Rejected Alternatives

- Emit one large C++ function or pseudo-source block on [UID:0001IO]. Rejected because it would mix many functions, padding, and an existing child callback.
- Keep [UID:0001IO] as the emitter parent for [UID:0001IP] after reclassifying it as non-emitting. Rejected because it would create an output routing mismatch.
- Treat `0x00580810-0x00580870` as padding or neighboring unknown bytes. Rejected by local PE disassembly.
- Treat raw helper starts as false positives. Rejected by prologues, body structure, return/padding boundaries, and internal semantic matches.
- Move PCX loader implementation into StartupWindow. Rejected; StartupWindow consumes `LoadPcxImage`, while ImageLoaders owns decoding.
- Move Browser implementation into StartupWindow. Rejected; StartupWindow hosts/configures Browser.
- Move minimap hash-list state mutation into StartupWindow. Rejected; MiniMapVersionManager owns hash-list/cache behavior.
- Give final original names to descriptive labels. Rejected; names in this report are best source-facing analysis names, not PDB-proven original spellings.

## Final Recommendation

Proceed with a split implementation callback before source C++ emission. The source-quality target is strong enough to improve the target page and coverage row, but not as one aggregate code page. The exact source-bearing work should move to child pages, with [UID:0001IO] retained only as the audited physical-range index for StartupWindow update-notice executable code.

No by-* docs and no coverage files were edited by this report-only pass.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B010","command_id":"000000004165","destination_path":"executed-b-agent-research/B010/0001IO-StartupWindowUpdateCheck-source-quality.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:34","uid":"0001IO"} -->
<!-- {"agent":"B010","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 0001IO-StartupWindowUpdateCheck-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B010/0001IO-StartupWindowUpdateCheck-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"0001IO"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
