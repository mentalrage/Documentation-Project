** TARGET-REPORT-UID:00018E **
** AUTHOR-AGENT-ID:B001 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# B001-goal2-inputman-source-quality-00018E-20260618

Primary target: [UID:00018E] `by-memory/0x004e8af0-0x004e970d.InputMan.md`

Required report path: `tools/leaser/Agents/Agent-B001/research/00018E-InputMan-source-quality.md`

Report-only scope observed: no by-* docs, generated reports, generated source, IDA DB, or `by-memory/-coverage-report.md` were edited.

## Finalized Report / Current Recommendation

Keep [UID:00018E] as the canonical emitting aggregate for the `InputMan` executable island and populate its formal C++ with a first draft. The current blockers are resolved or reduced to non-blocking exact-spelling caveats:

- Source placement remains [UID:00006J] `InputMan` under [UID:0000K6] `NexusTK/input/InputMan.cpp`.
- Event factory bodies remain owned by [UID:0000J6] `Event`, not `InputMan`. `InputMan::HandleWindowMessage` should call the source-facing Event helpers.
- Platform function-pointer globals are not `InputMan` globals. They are [UID:0000ML] PlatformApi wide-dispatch entries:
  - `0x0069be50` = `g_pfnDefWindowProcW`, `LRESULT (WINAPI *)(HWND, UINT, WPARAM, LPARAM)`.
  - `0x0069be90` = `g_pfnPostMessageW`, `BOOL (WINAPI *)(HWND, UINT, WPARAM, LPARAM)`.
  - `0x0069bebc` = `g_pfnImmGetCompositionStringW`, `LONG (WINAPI *)(HIMC, DWORD, LPVOID, DWORD)`.
  - `0x0069bec0` = `g_pfnImmGetCandidateListW`, `DWORD (WINAPI *)(HIMC, DWORD, LPCANDIDATELIST, DWORD)`.
  - `0x0069bec8` = `g_pfnGetLocaleInfoW`, `int (WINAPI *)(LCID, LCTYPE, LPWSTR, int)`.
- `0x004e8cc0-0x004e8cdf` is best modeled as a no-route local/static keyboard-layout locale helper, not a public `InputMan` method and not PlatformApi ownership.
- `0x004e8dd0-0x004e8dd5` should be added to the target inventory as a no-route `InputMan` state-byte accessor returning `*(BYTE *)(this + 0x15)`.
- The generated `auto-generated/NexusTK/input/InputMan.cpp` no-code/noop state is caused by blank formal C++ blocks despite [00018E]/[00006J]/[0000K6] clearing owner/emitter gates. It is not evidence that `InputMan` is non-emitting.

Recommended metadata:

| UID | Current | Recommended | Reason |
| --- | --- | --- | --- |
| [00018E] `InputMan` memory aggregate | `84/88`, `RECONSTRUCTABLE:TRUE`, owner/emitter [00006J] | `88/90`, same owner/emitter | Event helper names, platform dispatch globals, raw `0x004e8cc0`, missing `0x004e8dd0`, field names, and C++ readiness are now resolved or bounded. |
| [00006J] `InputMan` class | `86/89`, owner/emitter [0000K6] | `88/90`, same owner/emitter | Class open questions are resolved by this report; exact original spellings and candidate deque deletion semantics still cap confidence below final-audit levels. |
| [0000K6] `InputMan` file | `86/89` | `88/90` | File-level API dispatch and Event factory boundaries are now typed and no longer block formal C++. |
| [000299] `g_pInputMan` | `88/90` | no change | Existing singleton evidence is already sufficient. |
| [0003BR] `InputManVtableData` | `85/91` | no change | Vtable data remains generated from the class declaration; no source-body change needed. |

## Evidence Checked

Supervisor and agent rules:

- Read `tools/leaser/Agents/Supervisor.md`, `tools/leaser/Agents/Agent-B001/goal.md`, and `tools/leaser/Agents/Agent-B001/notes.md` before working.
- Read source-tree and inference guidance pages used by the supervisor workflow, including `by-project-structure/proposed-source-tree.md`.

Target and direct support docs:

- [UID:00018E] `by-memory/0x004e8af0-0x004e970d.InputMan.md`.
- [UID:00006J] `by-class/InputMan.md`.
- [UID:0000K6] `by-file/InputMan.md`.
- [UID:000299] `by-memory/0x0067ab44-0x0067ab48.g_pInputMan.md`.
- [UID:0003BR] `by-memory/0x0061c5a0-0x0061c5b0.InputManVtableData.md`.
- [UID:0000J6] `by-file/Event.md`.
- [UID:00004O] `by-class/EventMan.md`.
- [UID:00014C] `by-memory/0x004a8ac0-0x004ab3eb.EventManAndEventFactoryHelpers.md`.
- [UID:0000K5] `by-file/IMEPanes.md`.
- [UID:00018A] `by-memory/0x004e7470-0x004e763c.IMECompositionSetCompositionString.md`.
- [UID:00018B] `by-memory/0x004e7930-0x004e7b6c.IMECandidateShowCandidateList.md`.
- [UID:0001WO] `by-type/by-template/CandidateStringDequeTemplate.md`.
- [UID:00001G] `by-class/CandidateStringQueue.md`.
- [UID:0000ML] `by-file/PlatformApi.md`.
- [UID:0000WD] `by-memory/0x0041a280-0x0041a4a8.WideApiDispatchInit.md`.
- [UID:0000TQ] `by-global/WideApiDispatchTable.md`.
- [UID:0002AS] `by-memory/0x0069be14-0x0069bec4.WideApiDispatchPointerTable.md`.
- [UID:0001Q1] `by-memory/0x0069bec4-0x0069bec8.g_browserControlKeyCallback.md`.
- [UID:0002A6] `by-memory/0x0069bec8-0x0069bed0.WideApiDispatchTailPointers.md`.

Local exported-function JSON and binary checks:

- `core/data/readonly/prewave/exported-functions/0x0041a280.json`: confirms `0x0069be50 = DefWindowProcW`, `0x0069be90 = PostMessageW`, `0x0069bebc = ImmGetCompositionStringW`, `0x0069bec0 = ImmGetCandidateListW`, `0x0069bec4 = SendMessageW`, `0x0069bec8 = GetLocaleInfoW`, `0x0069becc = SetFileAttributesW`.
- `0x004e8af0.json`: constructor body and exact field writes.
- `0x004e8c20.json`: ordinary destructor body.
- `0x004e8cb0.json`: five-byte `__stdcall` message callback stub; direct caller `0x004666fa`.
- `0x004e8cc0.json`: Ghidra-only/raw helper, no callers, calls `GetKeyboardLayout(0)` and then `DAT_0069bec8(LOWORD(hkl), 2, param_1, param_2)`.
- `0x004e8cf0.json`: `TrackInputTarget` body and callers.
- `0x004e8dd0.json`: five-byte `this[21]` accessor, no callers/xrefs.
- `0x004e8de0.json`: `HandleWindowMessage` branch logic, direct caller `0x00465fad`.
- `0x004e9430.json`: `GetInputMode`, direct callers `0x00464d9a`, `0x004661cd`.
- `0x004e9440.json`: `SetInputMode`, direct callers `0x004f67a2`, `0x005a25ec`.
- `0x004e9490.json`: standalone composition-finalize helper, direct caller `0x00590f6b`.
- `0x004e94d0.json`: `GCS_CURSORPOS` helper, direct caller `0x004e7606`.
- `0x004e9510.json`: composition-string copy helper, callers from `HandleWindowMessage`.
- `0x004e9590.json`: current-context release helper, callers from `HandleWindowMessage`.
- `0x004e9650.json`: singleton clear helper, reached by constructor-unwind/EH jump at `0x0060063e`.
- `0x004e9660.json`: scalar deleting destructor, vtable data reference at `0x0061c5a4`.
- Event factory JSON for `0x004a97e0`, `0x004a9a40`, `0x004a9ae0`, `0x004a9c10`, `0x004a9cb0`, `0x004a9db0`, `0x004a9e50`, and `0x004a9f00`.
- Local PE byte checks against `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`: manual decoding of positive control call sites confirms `0x004666fa -> 0x004e8cb0`, `0x00465fad -> 0x004e8de0`, `0x00464d9a -> 0x004e9430`, and `0x0060063e -> 0x004e9650`; targeted VA/RVA pattern checks found no pointer-byte hits for `0x004e8cc0` or `0x004e8dd0`.

Generated-state checks:

- `project-documentation/auto-generated/NexusTK/input/InputMan.cpp` is empty. This is consistent with blank formal C++ in [00018E] and support pages, not with a non-emitting source decision.
- `simroot_v2/class_InputMan.cpp` was inspected only as a generated lead. It contains useful coarse method shapes but still uses placeholder dispatch globals and unresolved Event declarations, so it should not be treated as proof.

## Heuristic / Inference Reanalysis And Validation

### Source placement and ownership

Best inference: keep [00018E] owned by [00006J] `InputMan`, emitted through [00006J] and file parent [0000K6] `NexusTK/input/InputMan.cpp`.

Evidence:

- Constructor at `0x004e8af0` publishes `g_pInputMan` and installs the `InputMan` vtable.
- Destructor bodies and scalar deleting destructor clear `g_pInputMan`.
- [0003BR] vtable data points back to constructor/destructor/scalar-delete stores.
- Application constructs the object at `0x00464572` and calls `InputMan::HandleWindowMessage` from the main message path at `0x00465fad`.
- Neighboring [0000K5] `IMEPanes.cpp` owns pane display state; Event owns Event factories; PlatformApi owns API dispatch slots.

Rejected alternatives:

- `Application.cpp`: rejected because Application is caller/owner of lifetime, not owner of the IME/message translator implementation.
- `IMEPanes.cpp`: rejected because IMEPanes consumes Event type 15 and UI popup state; `InputMan` produces Win32/IMM events.
- `Event.cpp`: rejected for `InputMan` body because Event only owns factory helpers and Event payload layout.
- `PlatformApi.cpp`: rejected for `InputMan` body because it only owns dispatch-table slots.

Impact:

- Owner/emitter should remain [00006J]; no split or non-emitting index is needed.
- Formal C++ should be populated on [00018E].

### Source-facing method and helper signatures

Recommended source-facing names/signatures:

| Range | Recommended source-facing name/signature | Evidence and caveat |
| --- | --- | --- |
| `0x004e8af0-0x004e8c11` | `InputMan::InputMan()` | Constructor publishes singleton, installs vtable, creates/associates owned HIMC, reads IME property flags, creates input-target list. |
| `0x004e8c20-0x004e8ca1` | `InputMan::~InputMan()` | Restores `m_restoreImeContext` if nonzero, destroys owned context, releases list, clears singleton, calls base cleanup. |
| `0x004e8cb0-0x004e8cb5` | `static LRESULT __stdcall InputManMessageCallbackStub(HWND, UINT, WPARAM, LPARAM)` | Five-byte stdcall stub returns zero and is called at `0x004666fa`; no instance state is used. |
| `0x004e8cc0-0x004e8cdf` | `static int __stdcall GetKeyboardLayoutLanguageName(LPWSTR buffer, int cchBuffer)` | No callers/xrefs; calls `GetKeyboardLayout(0)`, `g_pfnGetLocaleInfoW(LOWORD(hkl), 2, buffer, cchBuffer)`. `2` is `LOCALE_SLANGUAGE`. |
| `0x004e8cf0-0x004e8dcb` | `bool InputMan::TrackInputTarget(int targetId, bool active)` | Adds/removes `int` ids in the `+0x1c` list; posts custom `0x401` when the tracked set crosses empty/non-empty. |
| `0x004e8dd0-0x004e8dd5` | `BYTE InputMan::GetImeStateByte() const` or `BYTE InputMan::GetImeStateFlags() const` | Returns `this[0x15]`; no callers/xrefs. The exact original spelling is unknown, but it is a real source-shaped accessor over the high byte of the `+0x14` state word. |
| `0x004e8de0-0x004e9319` | `bool InputMan::HandleWindowMessage(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam, LRESULT *result)` | Return value is handled/not-handled; stores `*result = 0` on handled paths. |
| `0x004e9430-0x004e9434` | `int InputMan::GetInputMode() const` | Returns `m_inputMode` at `+0x18`; Wave2 traces already integrated this name. |
| `0x004e9440-0x004e9485` | `BOOL InputMan::SetInputMode(int mode)` | Stores mode; if mode is `2`, sends `ImmNotifyIME(context, 0x15, 1, 0)` and releases context. |
| `0x004e9490-0x004e94c4` | `BOOL __stdcall CompleteImeComposition()` | Standalone helper with the same `ImmNotifyIME(..., 0x15, 1, 0)` sequence; direct caller is `TextEditPane::OnMouseEvent` at `0x00590f6b`. |
| `0x004e94d0-0x004e950e` | `int __stdcall InputMan::GetCompositionCursorPosition()` or file-local `GetCompositionCursorPosition()` | Calls `g_pfnImmGetCompositionStringW(context, GCS_CURSORPOS, NULL, 0)` and returns low word; [00018A] validates this as cursor position, not composition length. |
| `0x004e9510-0x004e9561` | `int __stdcall CopyCompositionString(DWORD gcsFlag, wchar_t *buffer, int byteCapacity)` | Copies result/composition string with `g_pfnImmGetCompositionStringW`, leaves a UTF-16 NUL at byte offset `byteCount`, returns byte count. |
| `0x004e9590-0x004e95ab` | `BOOL __stdcall ReleaseCurrentImeContext(HIMC context)` | Releases context against current app HWND; used by candidate-list and composition-string paths. |
| `0x004e9650-0x004e965b` | `static void __stdcall ClearInputManSingletonForCtorUnwind()` | Writes `g_pInputMan = 0`; reached from constructor unwind/EH at `0x0060063e`, not a normal public helper. |
| `0x004e9660-0x004e970d` | MSVC scalar deleting destructor for `InputMan` | Compiler-generated wrapper around ordinary cleanup plus optional delete. Do not expose as human-written source API. |

### Field names and layout

Recommended field names:

| Offset | Name | Type | Evidence |
| --- | --- | --- | --- |
| `+0x04` | `m_defaultImeWindow` | `HWND` | Constructor stores `ImmGetDefaultIMEWnd(appWindow)`; used as IME/default-window context state. |
| `+0x08` | `m_ownedImeContext` | `HIMC` | Constructor stores `ImmCreateContext`; destructor destroys it; custom `0x401` associates/disassociates it. |
| `+0x0c` | `m_restoreImeContext` or `m_previousImeContext` | `HIMC` | Destructor re-associates this field if nonzero. No positive constructor write is visible in the exported decompile, so name is inferred from destructor behavior and confidence is lower than `+0x08`. |
| `+0x10` | `m_imePropertyFlags` | `DWORD` | Constructor stores `ImmGetProperty(GetKeyboardLayout(0), 4)`; `WM_IME_SETCONTEXT` fallback checks bit `0x20000`. |
| `+0x14` | `m_imeStateWord` | `WORD` | Constructor clears a word; `0x004e8dd0` reads high byte at `+0x15`. No stronger source name is defensible. |
| `+0x18` | `m_inputMode` | `int` | Constructor initializes `2`; `GetInputMode` returns it; `SetInputMode` writes it. |
| `+0x1c` | `m_inputTargetList` | `List<int> *` | Constructor calls `List(..., 4, 100)`; `TrackInputTarget` uses list virtual slots for data/count/add/remove/clear. |

Rejected field alternatives:

- `+0x0c` as a live always-saved app context: rejected as overstated because no constructor writer is currently proven. Keep `m_restoreImeContext` with caveat.
- `+0x14` as a composition length or cursor: rejected because cursor comes from `0x004e94d0`/`GCS_CURSORPOS`, and the state word is only cleared/read as bytes in this island.
- `+0x1c` as a custom queue: rejected because constructor element size is `4` and `TrackInputTarget` stores integer target ids; candidate strings use separate STL deque support.

### Input-target list role

`TrackInputTarget(int targetId, bool active)` manages an integer list of active input target ids. If `targetId == 0`, it posts custom `0x401` with the requested active state and clears the list. Otherwise it scans the list contents, appends/removes the integer id, and posts `0x401` only on empty/non-empty transitions. The message is posted with `g_pfnPostMessageW(appHwnd, 0x401, activeState, 0)`, not sent synchronously through `SendMessageW`.

Rejected alternatives:

- List of pane pointers: rejected because the stored element copied into the list is the caller's integer target id and the constructor element size is 4.
- Candidate-string deque: rejected because candidate strings use `std::deque<std::wstring>` support around `0x004e9710`, not this list.

### Event factories and payloads

Resolved Event helper names/signatures:

| Address | Owner | Source-facing signature | Producer path |
| --- | --- | --- | --- |
| `0x004a97e0` | EventMan/Event | `void EventMan::DispatchCharEvent(wchar_t ch, int tickCount)` | `WM_CHAR`, unless `lParam & 0x20000000`. |
| `0x004a9a40` | Event | `void __stdcall DispatchImeOpenStatusEvent(BOOL isOpen, int tickCount)` | `WM_IME_NOTIFY/IMN_SETOPENSTATUS`. |
| `0x004a9ae0` | EventMan/Event | `void EventMan::DispatchCompositionTextEvent(const wchar_t *text, int tickCount)` | `WM_IME_COMPOSITION` with `GCS_COMPSTR`. |
| `0x004a9c10` | Event | `void __stdcall DispatchCompositionStartEvent(int tickCount)` | `WM_IME_STARTCOMPOSITION`. |
| `0x004a9cb0` | Event | `void __stdcall DispatchCompositionResultEvent(const wchar_t *resultText, int tickCount)` | `WM_IME_COMPOSITION` with `GCS_RESULTSTR`. |
| `0x004a9db0` | Event | `void __stdcall DispatchCompositionEndEvent(int tickCount)` | `WM_IME_ENDCOMPOSITION`. |
| `0x004a9e50` | Event | `void __stdcall DispatchCandidateListEvent(int selectedRow, std::deque<std::wstring> *visibleCandidates, int tickCount)` | `WM_IME_NOTIFY/IMN_OPENCANDIDATE` or `IMN_CHANGECANDIDATE`. |
| `0x004a9f00` | Event | `void __stdcall DispatchCandidateCloseEvent(int tickCount)` | `WM_IME_NOTIFY/IMN_CLOSECANDIDATE`. |

Payload structure:

- Event type `10`, subcode `0x100`: character input from `DispatchCharEvent`.
- Event type `10`, subcode `0`: composition text from `DispatchCompositionTextEvent`, inline UTF-16 text, length capped by the helper.
- Event type `11`: IME open status, carrying open flag and tick count.
- Event type `12`: composition start.
- Event type `13`: composition result text.
- Event type `14`: composition end.
- Event type `15`: candidate list; Event payload field consumed as `+0x08` is a visible-candidate deque pointer, and field consumed as `+0x0c` is selected row normalized as `dwSelection - pageStart`.
- Event type `16`: candidate close.

Ownership/lifetime:

- The Event factory bodies are already documented under [0000J6]/[00014C].
- `InputMan` allocates the visible candidate deque and passes it to `DispatchCandidateListEvent`. There is no explicit free in `InputMan` after dispatch. [00018B] proves the pane-side consumer copies/uses that pointer. This is best represented in first-draft C++ as ownership transfer to the Event dispatch path. The exact deleter location is not proven in the checked docs/JSON and should cap confidence below final audit, but it does not block modeling `InputMan` as the producer.

### IME message constants and branch meanings

`HandleWindowMessage` should be reconstructed around these constants:

| Message/value | Meaning in target |
| --- | --- |
| `0x51` / `WM_INPUTLANGCHANGE` | Recreates owned HIMC, associates it with the app window, disables current open status. |
| `0x102` / `WM_CHAR` | Dispatches `DispatchCharEvent` unless bit `0x20000000` is set in `lParam`; handled with result zero. |
| `0x10d` / `WM_IME_STARTCOMPOSITION` | Dispatches composition-start Event; handled with result zero. |
| `0x10e` / `WM_IME_ENDCOMPOSITION` | Dispatches composition-end Event; returns not handled per decompile. |
| `0x10f` / `WM_IME_COMPOSITION` | For `GCS_RESULTSTR` (`0x8`) copies result text and dispatches type 13; for `GCS_COMPSTR` (`0x800`) copies current text and dispatches composition-text Event. |
| `0x281` / `WM_IME_SETCONTEXT` | If `m_imePropertyFlags & 0x20000` is clear, forwards to `g_pfnDefWindowProcW(hwnd, WM_IME_SETCONTEXT, wParam, 0)` and returns handled. |
| `0x282` / `WM_IME_NOTIFY` | Handles `IMN_OPENSTATUSWINDOW` (`2`), `IMN_CHANGECANDIDATE` (`3`), `IMN_CLOSECANDIDATE` (`4`), `IMN_OPENCANDIDATE` (`5`), and `IMN_SETOPENSTATUS` (`8`). |
| `0x286` / `WM_IME_CHAR` | Swallowed with result zero. |
| `0x290` / `WM_IME_KEYDOWN` | Sets result zero but returns not handled. |
| `0x401` / `WM_USER + 1` | Custom app message; associates owned context when low byte of `wParam` is `1`, otherwise disassociates IME context. |

Candidate-list branch:

- Finds the first set bit in `lParam` to choose candidate-list index.
- Calls `g_pfnImmGetCandidateListW(context, listIndex, NULL, 0)` to get byte count.
- Allocates a CANDIDATELIST-sized buffer, fills it with `g_pfnImmGetCandidateListW`, and releases the HIMC through `ReleaseCurrentImeContext`.
- Uses `dwPageSize`; defaults zero page size to `9`.
- Uses `dwPageStart`; if zero, recomputes page start as `pageSize * (dwSelection / pageSize)`.
- Appends only visible-page candidate strings through STL deque/wstring helper support at `0x004e9710`.
- Calls `DispatchCandidateListEvent(dwSelection - pageStart, visibleDeque, GetMessageTime())`.

### Platform dispatch globals

Validation:

- `WideApiDispatchInit` and its JSON decompilation directly assign `DefWindowProcW` to `0x0069be50` and `PostMessageW` to `0x0069be90`.
- This resolves `dword_69BE50` and `dword_69BE90` in the target.
- The same initializer resolves `dword_69BEBC`, `dword_69BEC0`, and `dword_69BEC8` used by composition/candidate/key-layout helpers.

Rejected alternatives:

- `dword_69BE90` as `SendMessageW`: rejected because `SendMessageW` is the neighboring `0x0069bec4` slot and is documented by [0001Q1].
- `dword_69BE50` as an InputMan callback: rejected because initializer installs `DefWindowProcW`, and Browser/window fallback paths also consume it as a default window proc.
- Moving these globals into `InputMan`: rejected because the dispatch table is owned and initialized by PlatformApi.

### Raw helper starts and reachability

`0x004e8cc0`:

- Exported JSON/Ghidra models the exact code even though older IDA docs called it "Not a function".
- It has no direct callers and no IDA/Ghidra xrefs in the checked exports.
- Local targeted VA/RVA pointer-byte checks found no pointer hits.
- Best source-shape inference: file-local helper for current keyboard layout language name, likely originally available to code that no longer references it in this binary.
- Do not split it into a public child page unless the supervisor wants a no-route helper child; it can be documented inside [00018E].

`0x004e8dd0`:

- Exported JSON models a real five-byte function: `return this[21];`.
- No callers/xrefs were found in the checked exports.
- It is an omitted state-byte accessor over `m_imeStateWord` high byte at `+0x15`.
- Add it to the function inventory and C++ review draft as a private/no-route accessor.

`0x004e9650`:

- Current docs should not say it has no callers without caveat. The raw control-flow check decodes an EH/unwind jump from `0x0060063e` to `0x004e9650`.
- Model as constructor-unwind singleton clear, not as a normal public helper.

### Generated-output and final-C++ readiness

The target clears the active code-entry gate:

- `RECONSTRUCTABLE:TRUE`.
- Valid owner/emitter route [00018E] -> [00006J] -> [0000K6].
- Average score already above 85 in the assignment state and recommended higher after this reanalysis.
- Formal C++ is blank only because source-quality blockers were unresolved. Those blockers are now resolved or bounded.

Therefore this report recommends populating formal C++ for [00018E]. It should not wait for a generic "final C++ blocker." Remaining exact original spellings and the candidate deque deleter location should be recorded as confidence caps, not as no-code proof.

## Open Questions Resolved Or Remaining

Resolved:

- Event helper names around `0x004a97e0-0x004a9f00`: resolved to `DispatchCharEvent`, `DispatchImeOpenStatusEvent`, `DispatchCompositionTextEvent`, `DispatchCompositionStartEvent`, `DispatchCompositionResultEvent`, `DispatchCompositionEndEvent`, `DispatchCandidateListEvent`, and `DispatchCandidateCloseEvent`.
- Platform `dword_69BE*` globals: resolved to PlatformApi dispatch entries with source-facing `g_pfn...` names and signatures.
- `0x004e8cc0`: resolved as a no-route source-local keyboard-layout locale helper, not a live public method.
- `0x004e8dd0`: newly identified as a no-route state-byte accessor that should be documented.
- Field names for `+0x04/+0x08/+0x10/+0x18/+0x1c`: resolved with high confidence.
- Field names for `+0x0c/+0x14`: high-probability names supplied with explicit evidence caveats.
- Input-target list/container role: resolved as `List<int>` of active target ids.
- `InputMan.cpp` no-code/noop reason: resolved as blank formal C++, not non-emitting status.
- Source placement: resolved as `NexusTK/input/InputMan.cpp` with Event, PlatformApi, and IMEPanes boundaries preserved.

Remaining, non-blocking:

- Exact original spellings of `m_restoreImeContext`, `m_imeStateWord`, `GetImeStateByte`, and `GetKeyboardLayoutLanguageName` are not proven. The proposed names are descriptive and source-facing enough for by-* incorporation.
- The exact candidate-deque deleter/ownership endpoint is not proven in the checked docs/JSON. The producer-side transfer is proven; confidence should remain below final-audit levels until Event dispatch cleanup is traced or a deliberate leak is accepted as original behavior.
- Constructor decompilation does not show a positive write to `+0x0c`; destructor behavior still supports `m_restoreImeContext` as the best field role, but docs should preserve the "no proven constructor writer" caveat.

## First-Draft C++ Recommendation

Populate [00018E] formal C++ with this draft shape. It is source-facing and mid-2000s C++ oriented, but it intentionally keeps external helpers/containers as declarations because Event, PlatformApi, Application, and List support are owned elsewhere.

```cpp
#include <windows.h>
#include <imm.h>
#include <deque>
#include <string>

class List;
class EventMan;
class InputMan;

extern InputMan *g_pInputMan;
extern EventMan *g_pEventMan;

extern HWND GetApplicationWindow();

extern LRESULT (WINAPI *g_pfnDefWindowProcW)(HWND, UINT, WPARAM, LPARAM);
extern BOOL (WINAPI *g_pfnPostMessageW)(HWND, UINT, WPARAM, LPARAM);
extern LONG (WINAPI *g_pfnImmGetCompositionStringW)(HIMC, DWORD, LPVOID, DWORD);
extern DWORD (WINAPI *g_pfnImmGetCandidateListW)(HIMC, DWORD, LPCANDIDATELIST, DWORD);
extern int (WINAPI *g_pfnGetLocaleInfoW)(LCID, LCTYPE, LPWSTR, int);

void __stdcall DispatchImeOpenStatusEvent(BOOL isOpen, int tickCount);
void __stdcall DispatchCompositionStartEvent(int tickCount);
void __stdcall DispatchCompositionResultEvent(const wchar_t *text, int tickCount);
void __stdcall DispatchCompositionEndEvent(int tickCount);
void __stdcall DispatchCandidateListEvent(int selectedRow,
                                          std::deque<std::wstring> *visibleCandidates,
                                          int tickCount);
void __stdcall DispatchCandidateCloseEvent(int tickCount);

static const UINT kInputManContextMessage = WM_USER + 1;
static const int kDefaultCandidatePageSize = 9;

static LRESULT __stdcall InputManMessageCallbackStub(HWND, UINT, WPARAM, LPARAM)
{
    return 0;
}

static int __stdcall GetKeyboardLayoutLanguageName(LPWSTR buffer, int cchBuffer)
{
    HKL layout = GetKeyboardLayout(0);
    return g_pfnGetLocaleInfoW(LOWORD(layout), LOCALE_SLANGUAGE, buffer, cchBuffer);
}

InputMan::InputMan()
    : m_defaultImeWindow(0),
      m_ownedImeContext(0),
      m_restoreImeContext(0),
      m_imePropertyFlags(0),
      m_imeStateWord(0),
      m_inputMode(2),
      m_inputTargetList(0)
{
    g_pInputMan = this;

    HWND appWindow = GetApplicationWindow();
    m_defaultImeWindow = ImmGetDefaultIMEWnd(appWindow);
    m_ownedImeContext = ImmCreateContext();
    ImmAssociateContext(appWindow, m_ownedImeContext);

    HIMC context = ImmGetContext(appWindow);
    ImmSetOpenStatus(context, FALSE);
    ImmReleaseContext(appWindow, context);

    m_imePropertyFlags = ImmGetProperty(GetKeyboardLayout(0), IGP_PROPERTY);
    m_inputTargetList = new List(sizeof(int), 100);
}

InputMan::~InputMan()
{
    if (m_restoreImeContext != 0) {
        ImmAssociateContext(GetApplicationWindow(), m_restoreImeContext);
    }

    if (m_ownedImeContext != 0) {
        ImmDestroyContext(m_ownedImeContext);
        m_ownedImeContext = 0;
    }

    if (m_inputTargetList != 0) {
        m_inputTargetList->Release(1);
        m_inputTargetList = 0;
    }

    g_pInputMan = 0;
}

bool InputMan::TrackInputTarget(int targetId, bool active)
{
    HWND appWindow = GetApplicationWindow();

    if (targetId == 0) {
        g_pfnPostMessageW(appWindow, kInputManContextMessage, active ? 1 : 0, 0);
        m_inputTargetList->Clear();
        return true;
    }

    const int oldCount = m_inputTargetList->GetCount();
    int index = -1;
    int *targets = static_cast<int *>(m_inputTargetList->GetData());
    for (int i = 0; i < oldCount; ++i) {
        if (targets[i] == targetId) {
            index = i;
            break;
        }
    }

    if (active) {
        if (index < 0) {
            m_inputTargetList->Append(&targetId, 1);
        }
    } else if (index >= 0) {
        m_inputTargetList->Remove(index, 1);
    }

    const int newCount = m_inputTargetList->GetCount();
    if (oldCount == 0 && newCount != 0) {
        g_pfnPostMessageW(appWindow, kInputManContextMessage, 1, 0);
    } else if (oldCount != 0 && newCount == 0) {
        g_pfnPostMessageW(appWindow, kInputManContextMessage, 0, 0);
    }

    return true;
}

BYTE InputMan::GetImeStateByte() const
{
    return reinterpret_cast<const BYTE *>(&m_imeStateWord)[1];
}

static BOOL __stdcall ReleaseCurrentImeContext(HIMC context)
{
    return ImmReleaseContext(GetApplicationWindow(), context);
}

static int __stdcall CopyCompositionString(DWORD gcsFlag, wchar_t *buffer, int byteCapacity)
{
    HWND appWindow = GetApplicationWindow();
    HIMC context = ImmGetContext(appWindow);
    int byteCount = g_pfnImmGetCompositionStringW(context, gcsFlag, buffer,
                                                  byteCapacity - sizeof(wchar_t));
    ReleaseCurrentImeContext(context);
    *reinterpret_cast<wchar_t *>(reinterpret_cast<BYTE *>(buffer) + byteCount) = 0;
    return byteCount;
}

BOOL __stdcall CompleteImeComposition()
{
    HWND appWindow = GetApplicationWindow();
    HIMC context = ImmGetContext(appWindow);
    ImmNotifyIME(context, NI_COMPOSITIONSTR, CPS_COMPLETE, 0);
    return ImmReleaseContext(appWindow, context);
}

int __stdcall InputMan::GetCompositionCursorPosition()
{
    HWND appWindow = GetApplicationWindow();
    HIMC context = ImmGetContext(appWindow);
    int cursorPosition = g_pfnImmGetCompositionStringW(context, GCS_CURSORPOS, 0, 0) & 0xffff;
    ImmReleaseContext(appWindow, context);
    return cursorPosition;
}

int InputMan::GetInputMode() const
{
    return m_inputMode;
}

BOOL InputMan::SetInputMode(int mode)
{
    m_inputMode = mode;
    if (mode == 2) {
        return CompleteImeComposition();
    }
    return mode != 0;
}

static void AppendCandidateText(std::deque<std::wstring> *visibleCandidates,
                                const CANDIDATELIST *candidateList,
                                DWORD candidateIndex)
{
    const char *candidateText =
        reinterpret_cast<const char *>(candidateList) + candidateList->dwOffset[candidateIndex];
    wchar_t wideText[256];
    MultiByteToWideChar(CP_ACP, 0, candidateText, -1, wideText, 256);
    visibleCandidates->push_back(std::wstring(wideText));
}

bool InputMan::HandleWindowMessage(HWND hwnd, UINT message, WPARAM wParam,
                                   LPARAM lParam, LRESULT *result)
{
    switch (message) {
    case WM_INPUTLANGCHANGE: {
        if (m_ownedImeContext != 0) {
            ImmDestroyContext(m_ownedImeContext);
        }

        m_ownedImeContext = ImmCreateContext();
        ImmAssociateContext(hwnd, m_ownedImeContext);

        HIMC context = ImmGetContext(hwnd);
        ImmSetOpenStatus(context, FALSE);
        ImmReleaseContext(hwnd, context);
        *result = 0;
        return true;
    }

    case WM_CHAR:
        if ((lParam & 0x20000000) == 0) {
            g_pEventMan->DispatchCharEvent(static_cast<wchar_t>(wParam), GetMessageTime());
            *result = 0;
            return true;
        }
        return false;

    case WM_IME_STARTCOMPOSITION:
        DispatchCompositionStartEvent(GetMessageTime());
        *result = 0;
        return true;

    case WM_IME_ENDCOMPOSITION:
        DispatchCompositionEndEvent(GetMessageTime());
        return false;

    case WM_IME_COMPOSITION: {
        if ((lParam & GCS_RESULTSTR) != 0) {
            wchar_t resultText[128];
            CopyCompositionString(GCS_RESULTSTR, resultText, sizeof(resultText));
            DispatchCompositionResultEvent(resultText, GetMessageTime());
        }

        if ((lParam & GCS_COMPSTR) != 0) {
            wchar_t compositionText[64];
            CopyCompositionString(GCS_COMPSTR, compositionText, sizeof(compositionText));
            g_pEventMan->DispatchCompositionTextEvent(compositionText, GetMessageTime());
        }

        *result = 0;
        return true;
    }

    case WM_IME_SETCONTEXT:
        if ((m_imePropertyFlags & 0x20000) == 0) {
            *result = g_pfnDefWindowProcW(hwnd, message, wParam, 0);
            return true;
        }
        return false;

    case WM_IME_NOTIFY:
        if (wParam == IMN_OPENSTATUSWINDOW) {
            *result = 0;
            return true;
        }

        if (wParam == IMN_CHANGECANDIDATE || wParam == IMN_OPENCANDIDATE) {
            DWORD listIndex = 0;
            DWORD listMask = static_cast<DWORD>(lParam);
            while (((listMask >> listIndex) & 1) == 0 && listIndex < 32) {
                ++listIndex;
            }

            HIMC context = ImmGetContext(hwnd);
            DWORD byteCount = g_pfnImmGetCandidateListW(context, listIndex, 0, 0);
            CANDIDATELIST *candidateList =
                reinterpret_cast<CANDIDATELIST *>(operator new(byteCount));
            g_pfnImmGetCandidateListW(context, listIndex, candidateList, byteCount);
            ReleaseCurrentImeContext(context);

            DWORD pageSize = candidateList->dwPageSize;
            if (pageSize == 0) {
                pageSize = kDefaultCandidatePageSize;
            }

            DWORD pageStart = candidateList->dwPageStart;
            if (pageStart == 0 && pageSize != 0) {
                pageStart = pageSize * (candidateList->dwSelection / pageSize);
            }

            DWORD pageEnd = pageStart + pageSize;
            if (pageEnd > candidateList->dwCount) {
                pageEnd = candidateList->dwCount;
            }

            std::deque<std::wstring> *visibleCandidates = new std::deque<std::wstring>;
            for (DWORD i = pageStart; i < pageEnd; ++i) {
                AppendCandidateText(visibleCandidates, candidateList, i);
            }

            DispatchCandidateListEvent(static_cast<int>(candidateList->dwSelection - pageStart),
                                       visibleCandidates, GetMessageTime());

            operator delete(candidateList);
            *result = 0;
            return true;
        }

        if (wParam == IMN_CLOSECANDIDATE) {
            DispatchCandidateCloseEvent(GetMessageTime());
            return false;
        }

        if (wParam == IMN_SETOPENSTATUS) {
            HIMC context = ImmGetContext(hwnd);
            BOOL isOpen = ImmGetOpenStatus(context);
            ImmReleaseContext(hwnd, context);
            DispatchImeOpenStatusEvent(isOpen, GetMessageTime());
            *result = 0;
            return true;
        }
        return false;

    case WM_IME_CHAR:
        *result = 0;
        return true;

    case WM_IME_KEYDOWN:
        *result = 0;
        return false;

    case kInputManContextMessage:
        ImmAssociateContext(hwnd, (LOBYTE(wParam) == 1) ? m_ownedImeContext : 0);
        *result = 0;
        return true;
    }

    return false;
}

static void __stdcall ClearInputManSingletonForCtorUnwind()
{
    g_pInputMan = 0;
}
```

Notes for supervisor applying this draft:

- The `List` method names in this draft (`GetData`, `GetCount`, `Append`, `Remove`, `Clear`, `Release`) are source-facing stand-ins for observed virtual slots. If the support docs already standardize these names differently, use the standardized names while preserving behavior.
- The constructor initializes `m_restoreImeContext` to zero for source hygiene, but the checked decompilation does not prove a constructor write to `+0x0c`. If the supervisor prioritizes exact decompile parity over source hygiene, leave that initializer out and retain the field caveat in prose.
- `AppendCandidateText` represents the source-level candidate string conversion. The binary has inline conversion and STL helper calls; do not create a separate product-owned helper page unless the supervisor wants a review-only helper for readability.
- Do not expose the scalar deleting destructor as human-written C++.

## Exact Supervisor Changes Required

### Target [UID:00018E] metadata

Placement: header of `by-memory/0x004e8af0-0x004e970d.InputMan.md`.

Exact replacements:

```text
*** COMPLETION:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:00006J | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:00006J | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
```

### Target [UID:00018E] function inventory

Placement: replace the current rows covering `0x004e8cb0`, `0x004e8cc0`, and the gap before `0x004e8de0`; keep surrounding rows unchanged.

Exact replacement rows:

```markdown
| `0x004e8cb0-0x004e8cb5` | `InputManMessageCallbackStub` | `0x05` | Five-byte `__stdcall` window-message callback stub; returns `0`, direct caller at `0x004666fa`, no instance state. |
| `0x004e8cc0-0x004e8cdf` | `GetKeyboardLayoutLanguageName` local helper | `0x20` | No-route helper: calls `GetKeyboardLayout(0)`, takes `LOWORD(HKL)`, and calls `g_pfnGetLocaleInfoW(..., LOCALE_SLANGUAGE, buffer, cchBuffer)`. Exported JSON and local VA/RVA pattern checks found no direct callers or hidden pointer route. |
| `0x004e8dd0-0x004e8dd5` | `InputMan::GetImeStateByte` / `GetImeStateFlags` | `0x05` | No-route state-byte accessor returning `*(BYTE *)(this + 0x15)`, the high byte of the `+0x14` state word. Exact original spelling remains unproven. |
```

### Target [UID:00018E] field/layout text

Placement: replace the existing field-name block/table in [00018E].

Exact replacement:

```markdown
## Field Layout

| Offset | Recommended source-facing name | Type | Evidence |
| --- | --- | --- | --- |
| `+0x04` | `m_defaultImeWindow` | `HWND` | Constructor stores `ImmGetDefaultIMEWnd(appWindow)`. |
| `+0x08` | `m_ownedImeContext` | `HIMC` | Constructor stores `ImmCreateContext`; destructor destroys it; custom `0x401` associates/disassociates it. |
| `+0x0c` | `m_restoreImeContext` / `m_previousImeContext` | `HIMC` | Destructor re-associates this field if nonzero. No positive constructor write is currently proven, so keep this as a destructor-supported inference. |
| `+0x10` | `m_imePropertyFlags` | `DWORD` | Constructor stores `ImmGetProperty(GetKeyboardLayout(0), IGP_PROPERTY)`; `WM_IME_SETCONTEXT` checks bit `0x20000`. |
| `+0x14` | `m_imeStateWord` | `WORD` | Constructor clears the word; `0x004e8dd0` reads the high byte at `+0x15`. No stronger semantic name is proven. |
| `+0x18` | `m_inputMode` | `int` | Constructor initializes `2`; `GetInputMode` returns it; `SetInputMode` writes it. |
| `+0x1c` | `m_inputTargetList` | `List<int> *` | Constructor allocates a list with element size `4`; `TrackInputTarget` stores integer target ids and posts `0x401` on empty/non-empty transitions. |
```

### Target [UID:00018E] platform/Event helper notes

Placement: replace the paragraph beginning "The event factories at `0x004a97e0-0x004a9f00` remain owned..." and the open-question language about `dword_69BE*`.

Exact replacement:

```markdown
The Event factories at `0x004a97e0-0x004a9f00` remain owned by [UID:0000J6][Event](by-file/Event.md): `EventMan::DispatchCharEvent`, `DispatchImeOpenStatusEvent`, `EventMan::DispatchCompositionTextEvent`, `DispatchCompositionStartEvent`, `DispatchCompositionResultEvent`, `DispatchCompositionEndEvent`, `DispatchCandidateListEvent`, and `DispatchCandidateCloseEvent`. `InputMan::HandleWindowMessage` should call these helpers but should not absorb their source bodies.

The `dword_69BE*` calls in this island are PlatformApi wide-dispatch entries initialized by [UID:0000WD][WideApiDispatchInit](by-memory/0x0041a280-0x0041a4a8.WideApiDispatchInit.md): `dword_69BE50` is `g_pfnDefWindowProcW`, `dword_69BE90` is `g_pfnPostMessageW`, `dword_69BEBC` is `g_pfnImmGetCompositionStringW`, `dword_69BEC0` is `g_pfnImmGetCandidateListW`, and `dword_69BEC8` is `g_pfnGetLocaleInfoW`.
```

### Target [UID:00018E] changes section

Placement: append to `## Changes`.

Exact addition:

```markdown
- 2026-06-18 B001 source-quality reanalysis:
  - Changed to: `COMPLETION:88`, `CONFIDENCE:90`, owner/emitter unchanged at [UID:00006J][InputMan](by-class/InputMan.md), and formal C++ should be populated.
  - Summary/evidence: rechecked target, class/file/global/vtable support docs, Event/IMEPanes support pages, PlatformApi dispatch docs, exported function JSON, and local PE call/pointer evidence. Event helper names around `0x004a97e0-0x004a9f00` are resolved; `dword_69BE50/90/BC/C0/C8` are typed as PlatformApi wide-dispatch entries; `0x004e8cc0` is a no-route `GetLocaleInfoW` keyboard-layout language helper; `0x004e8dd0` is a no-route `+0x15` state-byte accessor; `0x004e9650` is an EH/unwind singleton clear reached at `0x0060063e`; field names and IME message/event payload roles are now documented. Remaining exact-spelling and candidate-deque deleter caveats cap confidence but do not block first-draft C++.
```

### [UID:00006J] `by-class/InputMan.md`

Placement: metadata header.

Exact replacements:

```text
*** COMPLETION:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
```

Placement: replace `## Observed State` code block with the field names listed above for [00018E].

Placement: insert into `## Methods` after the `TrackInputTarget` row or before `HandleWindowMessage`.

Exact row:

```markdown
| `0x004e8dd0-0x004e8dd5` | No-route accessor returning byte `this+0x15`; document as `GetImeStateByte` / `GetImeStateFlags` over the high byte of `m_imeStateWord`. |
```

Placement: replace `## Open Questions`.

Exact replacement:

```markdown
## Open Questions

- Exact original spellings for `m_restoreImeContext`, `m_imeStateWord`, `GetImeStateByte`, and `GetKeyboardLayoutLanguageName` remain unproven; the current names are source-facing descriptive names backed by behavior.
- The candidate-list producer path transfers a heap `std::deque<std::wstring>` pointer through Event type `15`; `InputMan` does not free it after dispatch. The exact deleter/ownership endpoint is not proven in the checked docs, so preserve this as a confidence cap.
- These remaining caveats do not block formal C++ for [UID:00018E].
```

### [UID:0000K6] `by-file/InputMan.md`

Placement: metadata header.

Exact replacements:

```text
*** COMPLETION:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
```

Placement: replace the "IME dispatch function pointers currently named..." bullet in `## Likely File Contents`.

Exact replacement:

```markdown
- PlatformApi wide-dispatch imports used by this file: `g_pfnDefWindowProcW` at `0x0069be50`, `g_pfnPostMessageW` at `0x0069be90`, `g_pfnImmGetCompositionStringW` at `0x0069bebc`, `g_pfnImmGetCandidateListW` at `0x0069bec0`, and `g_pfnGetLocaleInfoW` at `0x0069bec8`. These slots are initialized by [UID:0000WD][WideApiDispatchInit](by-memory/0x0041a280-0x0041a4a8.WideApiDispatchInit.md) and should not be moved into `InputMan.cpp`.
```

Placement: replace `State And Dispatch Inventory` row "Executable island" decision text.

Exact replacement decision:

```markdown
Treat this as the canonical `InputMan.cpp` body. After the 2026-06-18 B001 reanalysis, [UID:00018E] should receive formal first-draft C++; the previously blank generated file was caused by missing C++ blocks, not by a non-emitting decision.
```

Placement: append to `## Changes`.

Exact addition:

```markdown
- 2026-06-18 B001 InputMan source-quality reanalysis:
  - Changed to: `COMPLETION:88`, `CONFIDENCE:90`.
  - Summary/evidence: [UID:00018E] reanalysis resolves Event helper names, PlatformApi dispatch slot names/signatures, raw no-route helper roles for `0x004e8cc0` and `0x004e8dd0`, source-facing field names, `TrackInputTarget` list semantics, IME message/event payload structures, and formal C++ readiness. `InputMan.cpp` should remain under `NexusTK/input/`; Event factories stay in [UID:0000J6][Event](by-file/Event.md), pane-side IME UI stays in [UID:0000K5][IMEPanes](by-file/IMEPanes.md), and API dispatch storage stays in [UID:0000ML][PlatformApi](by-file/PlatformApi.md).
```

### PlatformApi support docs

Placement: [UID:0000TQ] `WideApiDispatchTable.md`, in the table around `0x0069be50` and `0x0069be90`. If the rows already exist at same-or-greater detail, do not duplicate them.

Exact additions/replacements:

```markdown
| `0x0069be50` | `g_pfnDefWindowProcW` | `DefWindowProcW` | Consumed by main window/default fallback and `InputMan::HandleWindowMessage` on `WM_IME_SETCONTEXT` when IME property bit `0x20000` is not set. |
| `0x0069be90` | `g_pfnPostMessageW` | `PostMessageW` | Consumed by `InputMan::TrackInputTarget` to post custom `WM_USER + 1` / `0x401` context-toggle notifications when active input-target state changes. |
```

Placement: [UID:0002AS] `WideApiDispatchPointerTable.md` or [UID:0000WD] initializer notes, if they still omit the two slots.

Exact addition:

```markdown
- 2026-06-18 B001 InputMan support check: `0x0069be50` is `DefWindowProcW` and `0x0069be90` is `PostMessageW` per `0x0041a280` initializer JSON/decompilation; InputMan consumes them as `g_pfnDefWindowProcW` and `g_pfnPostMessageW`.
```

### Event/IMEPanes support docs

No required score changes. Existing [0000J6], [00014C], [0000K5], [00018A], and [00018B] docs already contain same-or-greater detail for Event type `15`, `GCS_CURSORPOS`, producer/consumer split, candidate deque pointer, and selected-row payload. If the supervisor wants a small sync note, append:

```markdown
- 2026-06-18 B001 InputMan source-quality sync: [UID:00018E][InputMan](by-memory/0x004e8af0-0x004e970d.InputMan.md) now uses the Event helper names and payload roles documented here; ownership remains unchanged.
```

## Coverage Report Replacement Text

Placement context: replace the current [UID:00018E] row under the IME/InputMan neighborhood in `by-memory/-coverage-report.md`, between [UID:00018D] and [UID:00018F]. Do not edit directly from this B report.

Current row:

```markdown
    - [UID:00018E][0x004e8af0-0x004e970d.InputMan](by-memory/0x004e8af0-0x004e970d.InputMan.md) 0x004e8af0-0x004e970d | class-method-cluster | InputMan : reconstructable : 84% : strong : Live IDA confirms corrected `[start,end)` coverage, constructor, ordinary destructor, message/callback stubs, target tracking, `HandleWindowMessage`, input-mode accessors, IME helper group, singleton clear helper, scalar deleting destructor, `g_pInputMan`/vtable xrefs, class/file parent attachment, and blank final C++ below the source gate; event helper names, IME function-pointer globals, and the unmodeled `0x004e8cc0` stub remain open.
```

Replacement row:

```markdown
    - [UID:00018E][0x004e8af0-0x004e970d.InputMan](by-memory/0x004e8af0-0x004e970d.InputMan.md) 0x004e8af0-0x004e970d | class-method-cluster | InputMan : reconstructable : 88% : very-strong : B001 2026-06-18 source-quality reanalysis keeps owner/emitter [UID:00006J][InputMan](by-class/InputMan.md), validates `NexusTK/input/InputMan.cpp` placement, resolves Event helper names around `0x004a97e0-0x004a9f00`, types `dword_69BE50/90/BC/C0/C8` as PlatformApi wide-dispatch entries, documents constructor/destructor/`TrackInputTarget`/`HandleWindowMessage`/mode/composition/context helper signatures, identifies `0x004e8cc0` as a no-route `GetLocaleInfoW` keyboard-layout language helper, adds omitted no-route `0x004e8dd0` `+0x15` state-byte accessor, corrects `0x004e9650` as constructor-unwind singleton clear reached at `0x0060063e`, names fields `+0x04` `m_defaultImeWindow`, `+0x08` `m_ownedImeContext`, `+0x0c` `m_restoreImeContext`, `+0x10` `m_imePropertyFlags`, `+0x14` `m_imeStateWord`, `+0x18` `m_inputMode`, and `+0x1c` `m_inputTargetList`, resolves input-target list and IME event payload structures, and supplies first-draft C++ for formal population. Remaining exact-spelling and candidate-deque deleter caveats cap confidence but no longer block emission.
```

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B001","command_id":"000000004165","destination_path":"executed-b-agent-research/B001/00018E-InputMan-source-quality.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:19","uid":"00018E"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
