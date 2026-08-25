** TARGET-REPORT-UID:00039R **
** AUTHOR-AGENT-ID:B005 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
** REPORT-VALIDATION-STATUS: needs-revalidation **
** REPORT-REVALIDATION-REASON: target_uid_unknown: 00039R **
# B005 MCP-Backed Source-Quality Reanalysis: 00039R SurfaceDirectDrawRestoreMaintenance

Assignment: `B005-redo-surface-directdraw-restore-maintenance-source-quality-00039R-mcp-20260623`
Agent: `Agent-B005`
Target: [UID:00039R] `by-memory/0x005576a0-0x00557810.SurfaceDirectDrawRestoreMaintenance.md`
Required output path: `tools/leaser/Agents/Agent-B005/research/00039R-SurfaceDirectDrawRestoreMaintenance-source-quality.md`
Current pass: accepted implementation callback after the MCP-backed redo superseded the earlier raw-PE-only acceptance/execution review.

## Scope And Revocation Note

This report supersedes the earlier B005 report body and the earlier checked implementation-callback checklist. That prior implementation was revoked for acceptance/execution review because the report stated IDA MCP was unavailable. During the MCP redo I edited only this research report. During the accepted implementation callback I reconciled the target and required support by-* docs against this MCP-backed evidence, updated this checklist, and did not edit IDA DB state, unrelated docs, or any `-coverage-report.md` file.

Important implementation caveat: the target and some support by-* docs on disk already contained earlier, now-revoked implementation edits. The accepted callback treated those edits as unverified until reconciled against this MCP-backed report, retained only same-or-greater-detail facts that matched the MCP evidence, and replaced stale local-only / MCP-unavailable wording.

## Final Recommendation

Raise [UID:00039R] above the original `85/87` cap and reroute direct semantic ownership from Surface to ScreenPane:

```text
COMPLETION: 88
CONFIDENCE: 91
CANONICAL_OWNER: 0000CB
RECONSTRUCTABLE: TRUE
EMITTER_UIDS: 0000CB
EMITTER_POSITION_OPTIONAL: blank
Source route: [UID:0000NB] ScreenPane.cpp / NexusTK/ui/core/ScreenPane.cpp
C++: first-draft source body recommended
```

Recommended source-facing method name:

```cpp
void ScreenPane::RestoreDirectDrawState()
```

`RestoreDirectDrawState` is descriptive, not a recovered original symbol. It is better than the stale `SurfaceDirectDrawRestoreMaintenance` role because IDA MCP confirms this is a `__thiscall` body whose two direct callers pass `dword_67A7CC` / `g_pScreenPane` in `ecx`, and whose body tests and clears ScreenPane bytes `+0x111` and `+0x110`.

## Current Target State

Assignment baseline from `goal.md`:

```text
UID: 00039R
COMPLETION: 85
CONFIDENCE: 87
CANONICAL_OWNER: 0000OC
RECONSTRUCTABLE: TRUE
EMITTER_UIDS: 0000OC
RECONSTRUCTION_CPP: blank
```

Observed on-disk target after the revoked implementation attempt:

```text
UID: 00039R
COMPLETION: 88
CONFIDENCE: 91
CANONICAL_OWNER: 0000CB
RECONSTRUCTABLE: TRUE
EMITTER_UIDS: 0000CB
RECONSTRUCTION_CPP: ScreenPane::RestoreDirectDrawState()
```

The target page has been reconciled so its evidence basis is MCP-backed proof from active session `b880584f`, not the revoked local-only pass. The implemented metadata remains `88/91`, `0000CB`, `TRUE`, `0000CB`; the rationale is now MCP-backed instead of raw-PE-only.

## Actual Evidence Checked

Direct IDA MCP evidence from endpoint `http://127.0.0.1:13337/mcp`, active IDB session `b880584f`:

- `initialize` and `tools/list`: server `ida-pro-mcp`, protocol `2025-06-18`; available tools included `lookup_funcs`, `decompile`, `disasm`, `xrefs_to`, `xref_query`, `callees`, `get_bytes`, `get_int`, `type_query`, `type_inspect`, and `int_convert`.
- `idb_list`: active session `b880584f`, input path `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, filename `NexusTK.exe.i64`, `is_analyzing:false`.
- `server_health`: status `ok`; module `NexusTK.exe`; IDB path `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`; input executable `C:\Users\admin\Desktop\Clone\NexusTK\NexusTK.exe`; imagebase `0x400000`; auto-analysis and Hex-Rays ready. Final health check after evidence gathering was also `ok`.
- `lookup_funcs`: `0x005576a0` is IDA function `sub_5576A0`, size `0x170`; neighbors include `sub_557470` at `0x00557470` size `0x22d`, `sub_557820` at `0x00557820` size `0x8`, `sub_559170` at `0x00559170` size `0x8c`, `sub_556910` at `0x00556910` size `0x14a`, and `sub_556A60` at `0x00556a60` size `0x274`.
- `decompile 0x005576a0`: Hex-Rays models `void __thiscall sub_5576A0(_BYTE *this)`. It uses `unk_67AB20`, loads `*(unk_67AB20 + 4)`, tests `this[273]` and `this[272]`, calls vtable offsets `+76` and `+80`, calls `sub_4651D0((_DWORD *)unk_67AB1C)`, allocates with `sub_4F4AA0(8)`, constructs with `sub_4A6260`, calls a temporary object's vtable slot `+12`, and throws through `_CxxThrowException`.
- `disasm 0x005576a0`: IDA segment `.text`, 137 instructions. Important lines: `0x005576ce mov edi, ecx`; `0x005576d0 mov ebx, dword ptr unk_67AB20`; `0x005576d8 jz`; `0x005576da cmp byte ptr [edi+111h], 1`; `0x005576e6 cmp dword ptr unk_67A93C, 0`; `0x005576f2 call dword ptr [eax+4Ch]`; `0x005576fb mov byte ptr [edi+111h], 0`; `0x00557702 cmp byte ptr [edi+110h], 1`; `0x00557713 push 8`; `0x00557715 call sub_4651D0`; `0x0055771c call dword ptr [esi+50h]`; `0x00557725 mov byte ptr [edi+110h], 0`; `0x005577c8 call dword ptr [eax+0Ch]`; `0x00557788` and `0x0055780b call __CxxThrowException@8`.
- `xrefs_to 0x005576a0` and `xref_query`: exactly two code xrefs, from `0x00466abb` in `sub_466A70` and `0x004f5ed7` in `_WinMain@16`. `xref_query` found zero data xrefs to `0x005576a0`; `xrefs_to 0x00557810` found zero xrefs to the function end.
- `callees 0x005576a0`: direct/static callees are `sub_4651D0`, `@__security_check_cookie@4`, `sub_4F4AA0`, `sub_4A6260`, and `__CxxThrowException@8`. Indirect DirectDraw and DDError formatter calls are visible in disassembly rather than this static callee list.
- `get_bytes`: `0x0055769d` has `cc cc cc`; `0x00557810` has sixteen `cc` bytes; `0x005576a0` begins `55 8b ec 6a ff 68 22 73 60 00 64 a1 00 00 00 00`.
- `get_bytes 0x0061938c` and `get_int`: DDError vtable bytes include `90 62 4a 00` at vtable `+0x0c`; `int_convert` confirms decimal `4874896` is `0x4a6290`.
- `type_query *DirectDraw*` and `type_inspect IDirectDrawVtbl`: IDA's type catalog contains `IDirectDraw`, `LPDIRECTDRAW`, and `IDirectDrawVtbl`. `IDirectDrawVtbl` member offsets are `Compact` at `+0x0c`, `RestoreDisplayMode` at `+0x4c`, `SetCooperativeLevel` at `+0x50`, and `SetDisplayMode` at `+0x54`.
- `type_query *DDError*`: no named DDError type was present in IDA's type catalog; DDError identity comes from current docs, constructor/typeinfo references, and vtable/body behavior.
- `decompile 0x004a6290`: `sub_4A6290(_DWORD *this, wchar_t *Buffer, size_t BufferCount)` formats into the caller-provided wide buffer using `this[1]`, supporting `DDError::FormatErrorMessage(wchar_t *, size_t)`.
- `decompile 0x004651d0`: `sub_4651D0(_DWORD *this)` returns `this[522]`, matching `Application::GetMainWindowHandle()` / window handle field `+0x828`.
- `decompile 0x00466a70` and `disasm 0x00466a70`: the deactivate path checks `dword_67A7CC`, clears `*(unk_67AB1C + 0x838)`, calls `ShowWindow([unk_67AB1C + 0x828], 6)`, then loads `ecx = dword_67A7CC` at `0x00466ab5` before `call sub_5576A0` at `0x00466abb`.
- `disasm 0x004f5ec0`: the WinMain-tail path calls `ShowWindow`, loads `ecx = dword_67A7CC` at `0x004f5ec6`, sets a local flag, tests `ecx`, and calls `sub_5576A0` at `0x004f5ed7` only when `g_pScreenPane` is non-null.
- `disasm 0x005574d0`: paired setup helper writes `mov byte ptr [edi+110h], 1` at `0x005574e5`, later writes `mov byte ptr [edi+111h], 1` at `0x00557537`, and uses the same `ApplicationActiveGate` / `g_pDirectX` / DirectDraw region.
- `disasm 0x005569e8`: constructor range writes `mov word ptr [esi+110h], 0` at `0x00556a06`, zeroing bytes `+0x110` and `+0x111`.
- `disasm 0x00556b77`: destructor range checks `g_pDirectX`, tests byte `+0x111`, calls DirectDraw vtable `+0x4c`, clears `+0x111`, tests byte `+0x110`, calls `sub_4651D0`, calls DirectDraw vtable `+0x50`, and follows the same DDError formatter/throw pattern.
- `int_convert`: `0x111` is decimal 273, `0x110` is decimal 272, `0x50` is decimal 80, and `0x08` is decimal 8. These conversions were verified with MCP `int_convert`.

Supplemental non-IDA evidence:

- `Get-FileHash -Algorithm SHA256` on `C:\Users\admin\Desktop\Clone\NexusTK\NexusTK.exe` and `E:\NTK\Resources\NexusTK\NexusTK.exe` both returned `9AEC210BBC5CE592176A21DD8E9D9FD8F250B8D9EA78237915A99BA8CFA9A632`.
- Current by-* docs were read as leads only, including the target page, [UID:00039Q], [UID:00039Z], [UID:0001G6], [UID:0000OC] Surface, [UID:0000NB]/[UID:0000CB] ScreenPane, DirectX/global/dependency pages, and the two caller pages.

No IDA DB names, types, comments, patches, bookmarks, or other tool state were changed.

## Exact Body Evidence

IDA MCP confirms one modeled source body from `0x005576a0` to `0x00557810`. It is a `__thiscall` method shape, not a free helper: the first source-useful instruction copies incoming `ecx` to `edi`, and every object flag access is through `edi`.

Confirmed control flow:

```text
if (g_pDirectX != NULL) {
    LPDIRECTDRAW directDraw = g_pDirectX->m_pDirectDraw;  // [unk_67AB20 + 4]

    if (this[0x111] == 1 && ApplicationActiveGate == 0) {
        hr = directDraw->RestoreDisplayMode();            // IDirectDrawVtbl +0x4c
        if (hr < 0)
            throw new DDError(hr);
        this[0x111] = 0;
    }

    if (this[0x110] == 1) {
        hr = directDraw->SetCooperativeLevel(
            g_pApplication->GetMainWindowHandle(),
            DDSCL_NORMAL);                                // IDirectDrawVtbl +0x50, literal 0x08
        if (hr < 0) {
            DDError *formatted = new DDError(hr);
            formatted->FormatErrorMessage(localWideBuffer, 0x50);
            throw new DDError(hr);
        }
        this[0x110] = 0;
    }
}
```

The local wide buffer is `0xa0` bytes, used with a capacity argument `0x50` (80 decimal, verified with MCP `int_convert`) to the DDError formatter. The formatter side call on the `SetCooperativeLevel` failure path is real and must be retained in first-draft C++; the first allocated temporary object is not explicitly deleted in the straight-line body before the second allocation/throw.

Compiler support to exclude from source logic:

- SEH/EH frame setup and scope table `SEH_5576A0`.
- Security cookie reads/checks using `___security_cookie` and `@__security_check_cookie@4`.
- `_CxxThrowException` plumbing and EH cleanup thunks in the `0x006072f8+` handler area.
- Padding bytes before and after the function.

## Vtable And SDK Method Reanalysis

The prior grouped wording that treated `+0x4c`, `+0x50`, and `+0x0c` as unresolved DirectDraw-style slots is superseded by MCP evidence.

| Slot | Receiver proven by MCP | Correct source-facing identity | MCP evidence |
| --- | --- | --- | --- |
| `+0x4c` | `g_pDirectX->m_pDirectDraw` / `IDirectDraw *` | `IDirectDraw::RestoreDisplayMode()` | Target disasm loads `ebx = [unk_67AB20 + 4]`, loads `[ebx]`, and calls `[eax+4Ch]` at `0x005576f2`. `type_inspect IDirectDrawVtbl` maps offset `+0x4c` to `RestoreDisplayMode`. |
| `+0x50` | `g_pDirectX->m_pDirectDraw` / `IDirectDraw *` | `IDirectDraw::SetCooperativeLevel(HWND, DWORD)` | Target disasm pushes literal `8`, calls `sub_4651D0`, pushes returned `HWND`, pushes `ebx`, and calls `[esi+50h]` at `0x0055771c`. `type_inspect IDirectDrawVtbl` maps offset `+0x50` to `SetCooperativeLevel`. |
| `+0x0c` | temporary DDError object, not DirectDraw | `DDError::FormatErrorMessage(wchar_t *, size_t)` | Target disasm constructs a DDError-like object with `sub_4A6260`, loads its vtable through `mov eax, [ecx]`, passes a local wide buffer and `0x50`, and calls `[eax+0Ch]` at `0x005577c8`. Vtable bytes at `0x0061938c + 0x0c` resolve to `0x004a6290`; decompile of `0x004a6290` formats into a `wchar_t *Buffer` and `BufferCount`. |

IDA's `IDirectDrawVtbl` also confirms that `+0x0c` would be `IDirectDraw::Compact` if the receiver were DirectDraw. That mapping is explicitly rejected here because the receiver at `0x005577c8` is the temporary error object, not `g_pDirectX->m_pDirectDraw`.

## Caller And Reachability Reanalysis

MCP proves this is a live function with two direct code xrefs and no data-table owner route.

| Call site | MCP caller function | Receiver setup | Meaning |
| --- | --- | --- | --- |
| `0x00466abb` | `sub_466A70`, current doc [UID:0002GK] `BaramApp::OnDeactivate` | `0x00466ab5 mov ecx, dword_67A7CC`; `0x00466abb call sub_5576A0` | Deactivate/minimize path clears application window state, calls `ShowWindow(..., 6)`, then restores ScreenPane DirectDraw state. |
| `0x004f5ed7` | `_WinMain@16`, current doc [UID:00019G] | `0x004f5ec6 mov ecx, dword_67A7CC`; `0x004f5ed3 test ecx, ecx`; `0x004f5ed7 call sub_5576A0` | Startup/updater-tail path hides/shows startup UI, checks `g_pScreenPane`, and restores DirectDraw state before final message/window teardown work. |

Negative xref evidence:

- `xref_query` found zero data xrefs to `0x005576a0`.
- `xrefs_to 0x00557810` found zero xrefs to the function end.
- The only code xrefs are the two call instructions above; no MCP evidence supports a vtable dispatch, callback table, jump-table entry, or absolute function pointer owner for this body.

## Context Pointer And Field Names

The incoming object is ScreenPane-shaped:

- IDA target decompilation uses `this[273]` and `this[272]`; MCP `int_convert` verifies those are offsets `0x111` and `0x110`.
- Both direct callers load `dword_67A7CC` into `ecx` before calling `sub_5576A0`. Current docs identify `dword_67A7CC` as `g_pScreenPane`.
- The ScreenPane constructor range writes `word ptr [esi+110h], 0` at `0x00556a06`, zeroing the two adjacent bytes later used by this target.
- The paired setup helper [UID:00039Q] writes byte `+0x110 = 1` at `0x005574e5` and byte `+0x111 = 1` at `0x00557537`.
- The ScreenPane destructor range repeats the same restore/clear behavior over `+0x111` and `+0x110`, including DirectDraw vtable slots `+0x4c` and `+0x50`.

Recommended provisional field names:

| Offset | Preferred provisional name | Alternate acceptable name | Evidence and caveat |
| --- | --- | --- | --- |
| `+0x110` | `m_restoreCooperativeLevelPending` | `m_directDrawCooperativeLevelActive` | Set by [UID:00039Q] before/after non-normal cooperative-level work, tested by [UID:00039R] before `SetCooperativeLevel(hwnd, DDSCL_NORMAL)`, cleared on success, initialized with `+0x111` by constructor. |
| `+0x111` | `m_restoreDisplayModePending` | `m_displayModeChanged` | Set by [UID:00039Q] after display-mode setup, tested by [UID:00039R] before `RestoreDisplayMode()` only when `ApplicationActiveGate == 0`, cleared on success, initialized with `+0x110` by constructor. |

The field names are inferred and source-facing. They are strong enough for first-draft C++ because the offsets, initialization, setup writes, restore reads/clears, destructor duplication, and caller receiver all agree.

## Exception Flow

MCP decompilation and disassembly confirm pointer-to-`DDError` throw behavior through `__CxxThrowException@8` with throw info `__TI4PAVDDError@@` at `0x0065d704`.

Failure paths:

- `RestoreDisplayMode()` failure:
  - `0x005576f7 test esi, esi`; `0x005576f9 js loc_557748`.
  - Allocate `8` bytes with `sub_4F4AA0`.
  - Construct via `sub_4A6260(v7, hr)`.
  - Throw pointer-to-DDError through `_CxxThrowException`.
- `SetCooperativeLevel()` failure:
  - `0x00557721 test esi, esi`; `0x00557723 js loc_55778D`.
  - Allocate/construct a temporary DDError with `sub_4F4AA0` and `sub_4A6260`.
  - Load temporary object's vtable and call slot `+0x0c` with local wide buffer and capacity `0x50`.
  - Allocate/construct a second DDError with the same HRESULT.
  - Throw pointer-to-DDError through `_CxxThrowException`.

The odd formatter side call remains an unresolved source-shape caveat, but it is not a blocker to first-draft C++ because the observed behavior is clear and must be preserved.

## Heuristic And Inference Reanalysis

### Positive Evidence

- IDA MCP confirms the exact function boundary, `.text` placement, function size, decompilation, disassembly, direct callers, direct/static callees, and padding bytes.
- Both direct callers pass `dword_67A7CC` / `g_pScreenPane` as `this`.
- The target mutates ScreenPane fields `+0x111` and `+0x110`; there is no anonymous Surface object receiver.
- The ScreenPane constructor initializes those bytes; the paired setup helper sets them; the ScreenPane destructor duplicates the cleanup path.
- IDA type info directly maps `IDirectDrawVtbl +0x4c` to `RestoreDisplayMode` and `+0x50` to `SetCooperativeLevel`.
- The `+0x0c` call is resolved away from DirectDraw: MCP proves it is on a temporary error object, and vtable bytes/decompilation point to `0x004a6290`.
- Reachability is live and concrete: two call sites, no no-xref/no-function cap.

### Negative Evidence

- `xref_query` found no data xrefs to the target start and `xrefs_to` found no xrefs to the end address.
- No vtable dispatch, callback registration, jump table, or absolute function pointer ownership evidence was recovered for `0x005576a0`.
- DirectX owns the singleton and `LPDIRECTDRAW` dependency, not the ScreenPane state policy.
- Application, BaramApp, and WinMain explain reachability and window-handle access, not direct ownership.
- Surface owns or groups neighboring presentation helpers, but locality is weaker than receiver/field/lifecycle evidence for this exact child.
- IDA does not contain recovered original names for the method or fields, and `type_query *DDError*` found no IDA type catalog hit for the class. DDError naming remains documentation/typeinfo/vtable-based.

## Ranked Ownership Analysis

### 1. [UID:0000CB] ScreenPane class, emitted through [UID:0000NB] ScreenPane.cpp

- Evidence for: `__thiscall` shape; both callers pass `g_pScreenPane`; ScreenPane constructor zeroes `+0x110/+0x111`; [UID:00039Q] sets those flags; this target clears them; destructor repeats the cleanup.
- Evidence against: the body is address-neighboring SurfacePresentation/DirectDraw helpers, and original source symbol names are unavailable.
- Decision: recommended direct owner/emitter route. The receiver and state lifecycle beat address-neighborhood evidence.

### 2. [UID:0000OC] Surface / Surface.cpp

- Evidence for: the target is in the `SurfacePresentation` address neighborhood and works on DirectDraw presentation state.
- Evidence against: no Surface object or Surface-specific global is the receiver; ScreenPane flags and caller route dominate; DirectDraw calls are service dependencies.
- Decision: demote to surrounding presentation-neighborhood context. Do not keep as direct owner for [UID:00039R].

### 3. [UID:0000IW] DirectX file / [UID:00003Y] DirectX class

- Evidence for: target reads `g_pDirectX` and calls `IDirectDraw`.
- Evidence against: no DirectX object is `this`; DirectX state is used as a device service dependency; flags live on ScreenPane.
- Decision: reject as direct owner. Keep as dependency.

### 4. Application / BaramApp / WinMain

- Evidence for: [UID:0002GK] and [UID:00019G] are the only direct callers, and the body calls `Application::GetMainWindowHandle`.
- Evidence against: they do not own the DirectDraw flags; they call into the ScreenPane singleton and orchestrate lifecycle only.
- Decision: reject as direct owner. Keep as reachability/caller context.

### 5. Error/DDError/allocator support

- Evidence for: DDError constructor, formatter, allocation, and C++ throw flow are material.
- Evidence against: they are failure-path dependencies only.
- Decision: reject as owner.

## Source Placement

Recommended source placement: `ScreenPane::RestoreDirectDrawState()` in [UID:0000NB] `ScreenPane.cpp`, under the [UID:0000CB] `ScreenPane` class.

Why it fits:

- The function is class-shaped `__thiscall`.
- The only known direct callers pass the global ScreenPane singleton as receiver.
- The field lifecycle is ScreenPane constructor/setup/destructor scoped.
- [UID:00039Z] already establishes that DirectDraw maintenance helpers in this address neighborhood can be ScreenPane methods when receiver/field evidence supports it.

Rejected placements:

- `Surface.cpp`: only an address-neighborhood grouping for this exact child.
- `DirectX.cpp`: device/service dependency only.
- `Application.cpp`, `BaramApp`, or WinMain: caller/orchestration context only.
- New standalone helper file: unnecessary because the body is method-shaped and tied to ScreenPane fields.

Remaining uncertainty: original spelling of the method and field names is unresolved. The descriptive names should be documented as inferred.

## Range / Split / Padding / Reclassification Analysis

Exact boundary facts:

- IDA function: `sub_5576A0`, start `0x005576a0`, size `0x170`, end `0x00557810`.
- Predecessor [UID:00039Q] ends at `0x0055769d`; `get_bytes 0x0055769d size 3` returns `cc cc cc`.
- Successor begins at `0x00557820`; `get_bytes 0x00557810 size 16` returns sixteen `cc` bytes.
- No MCP xrefs target `0x00557810`.

Recommendation:

- Keep [UID:00039R] as one exact function range `0x005576a0-0x00557810`.
- Keep both adjacent padding spans ignored.
- Do not merge with [UID:00039Q], [UID:00039S], or [UID:00039Z].
- Reclassify only direct owner/emitter/source-facing role for this child.

## Relationship To Required Neighbors

[UID:00039Q] `SurfaceFlipSurfaces`:

- MCP disassembly shows it writes `+0x110 = 1` at `0x005574e5` and `+0x111 = 1` at `0x00557537`.
- This is the setup side of the flags that [UID:00039R] consumes and clears.
- This report does not change [UID:00039Q] ownership. It should remain a required support note and later family-review candidate because the same ScreenPane receiver/field standard may affect it.

[UID:00039Z] `SurfaceRestoreLostSurfaces`:

- Different ScreenPane DirectDraw maintenance method: lost-surface recovery over DirectDraw surface fields such as `+0x18`, `+0x100`, and `+0x108`.
- It supports the general ScreenPane DirectDraw ownership pattern but does not duplicate this display-mode/cooperative-level behavior.

[UID:0001G6] `SurfacePresentation`:

- Should remain a mixed non-emitting aggregate/container.
- Its child row/note for [UID:00039R] now routes this exact child to ScreenPane class ownership at `88/91`.

## IDA Rename / Type / Comment Recommendations

No IDA DB edits were requested or made in this report/implementation pass.

Source-facing names/types recommended for docs and eventual C++:

- `ScreenPane::RestoreDirectDrawState()` for `sub_5576A0`.
- `g_pDirectX` for `unk_67AB20`.
- `g_pDirectX->m_pDirectDraw` for `[unk_67AB20 + 4]`.
- `g_pApplication` for `unk_67AB1C`.
- `Application::GetMainWindowHandle()` for `sub_4651D0`.
- `ApplicationActiveGate` or the existing project name for `unk_67A93C`.
- `m_restoreDisplayModePending` for byte `+0x111`.
- `m_restoreCooperativeLevelPending` for byte `+0x110`.
- `DDError::FormatErrorMessage(wchar_t *, size_t)` for `sub_4A6290`.

Items intentionally left unresolved:

- Exact original method spelling.
- Exact original member field spellings.
- Whether the odd formatter side call reflects original source text, macro/debug side effect, or compiler-shaped exception cleanup interaction. The call itself is not optional.

## First-Draft C++ Recommendation

Eligible for draft C++: yes. The target is reconstructable, has a confirmed ScreenPane emitter route, the combined score recommendation is above the C++ gate, and MCP resolves the body, dependencies, range, callers, and field roles well enough for a source-shaped first draft.

Recommended code:

```cpp
void ScreenPane::RestoreDirectDrawState()
{
    if (g_pDirectX == NULL)
        return;

    LPDIRECTDRAW directDraw = g_pDirectX->m_pDirectDraw;

    if (m_restoreDisplayModePending && ApplicationActiveGate == 0) {
        HRESULT hr = directDraw->RestoreDisplayMode();
        if (FAILED(hr))
            throw new DDError(hr);

        m_restoreDisplayModePending = false;
    }

    if (m_restoreCooperativeLevelPending) {
        HRESULT hr = directDraw->SetCooperativeLevel(
            g_pApplication->GetMainWindowHandle(),
            DDSCL_NORMAL);

        if (FAILED(hr)) {
            wchar_t formattedError[0x50];
            DDError *errorText = new DDError(hr);
            errorText->FormatErrorMessage(formattedError, 0x50);
            throw new DDError(hr);
        }

        m_restoreCooperativeLevelPending = false;
    }
}
```

Behavioral preservation notes:

- Do not add a null check for `g_pApplication` or `g_pDirectX->m_pDirectDraw`; MCP disassembly shows no such checks after `g_pDirectX != NULL`.
- Keep `ApplicationActiveGate == 0` only on the display-mode branch.
- Keep the cooperative-level branch gated only by byte `+0x110`.
- Keep literal `0x08` as `DDSCL_NORMAL` because IDA's `IDirectDrawVtbl` maps the receiver slot and project/SDK DirectDraw types agree on the method signature.
- Keep the formatter side call before the second DDError throw.
- Do not emit SEH/security-cookie/throw-helper mechanics as source.

## Accepted Target Doc Implementation

Target path: `by-memory/0x005576a0-0x00557810.SurfaceDirectDrawRestoreMaintenance.md`

The accepted implementation applied or retained:

- Metadata `88/91`, owner/emitter [UID:0000CB], `RECONSTRUCTABLE:TRUE`, blank emitter position.
- First-draft `ScreenPane::RestoreDirectDrawState()` C++ above.
- MCP-backed evidence replacing stale "MCP unavailable" language.
- Function/range proof: `sub_5576A0`, size `0x170`, `.text`, 137 instructions, exact padding before and after.
- Xref proof: exactly two code xrefs, zero data xrefs to start, zero xrefs to end.
- Caller proof: `0x00466abb` and `0x004f5ed7` load/test `dword_67A7CC` as receiver.
- DirectDraw method table proof from IDA `IDirectDrawVtbl`.
- DDError formatter proof from vtable bytes and `sub_4A6290` decompilation.
- Field map for `+0x110/+0x111`, including constructor zero, setup writes, restore clears, and destructor duplicate sequence.
- Owner ranking/rejections and unresolved spelling/source-shape caveats.

## Accepted Support Doc Synchronization

Required support docs checked/updated during the accepted implementation callback:

- `by-memory/0x00557140-0x00559aef.SurfacePresentation.md`: child row/note routes [UID:00039R] to ScreenPane class owner at `88/91` while preserving aggregate non-emitting status.
- `by-file/Surface.md`: [UID:00039R] is demoted from Surface-owned proposed content to SurfacePresentation neighborhood/dependency context.
- `by-file/ScreenPane.md`: `ScreenPane::RestoreDirectDrawState()` is recorded as a ScreenPane-owned DirectDraw display-state restore method emitted through `NexusTK/ui/core/ScreenPane.cpp`.
- `by-class/ScreenPane.md`: method entry, field notes for `+0x110/+0x111`, constructor zero, setup writes, and destructor duplicate relationship are recorded.
- `by-memory/0x00556910-0x00557132.ScreenPane.md`: constructor zero at `0x00556a06`, destructor duplicate sequence, and field lifecycle notes are recorded.
- `by-memory/0x00557470-0x0055769d.SurfaceFlipSurfaces.md`: paired setup writes at `0x005574e5` and `0x00557537` are recorded; [UID:00039Q] ownership remains unchanged pending a dedicated family pass.
- `by-memory/0x00559170-0x005591fc.SurfaceRestoreLostSurfaces.md`: optional cross-reference edit was not needed because stale wording conflating lost-surface recovery with display-mode/cooperative-level restoration was not present.
- Dependency pages were not touched because the optional scan found current dependency/caller text or unrelated historical entries, not stale current Surface-owned wording for [UID:00039R].

No by-meta page was required for this callback.

## Score And Metadata Recommendation

Current assignment baseline:

```text
COMPLETION: 85
CONFIDENCE: 87
CANONICAL_OWNER: 0000OC
RECONSTRUCTABLE: TRUE
EMITTER_UIDS: 0000OC
```

Recommended:

```text
COMPLETION: 88
CONFIDENCE: 91
CANONICAL_OWNER: 0000CB
RECONSTRUCTABLE: TRUE
EMITTER_UIDS: 0000CB
EMITTER_POSITION_OPTIONAL: blank
```

Rationale for `88` completion:

- MCP resolves function range, body flow, branch conditions, HRESULT paths, DirectDraw slot names, DDError formatter identity, callers, xrefs, padding, field offsets, direct owner ranking, and first-draft C++.
- It stays below `90+` because original method spelling, exact field names, and the odd formatter side-call source rationale remain unresolved, and the sibling [UID:00039Q] ownership family still needs a dedicated pass.

Rationale for `91` confidence:

- Confidence is higher than the old `87` because IDA MCP now confirms the function, xrefs, disassembly, decompilation, IDA DirectDraw type slots, padding, constructor/setup/destructor field lifecycle, and support dependencies.
- It stays below final-source confidence because no original PDB/source names are recovered, IDA lacks a named DDError type catalog entry, and some source-level naming remains inferred.

## Open Questions With Attempted Resolution

- Original method spelling: unresolved. MCP proves method shape and behavior but not source symbol names. Use descriptive `RestoreDirectDrawState`.
- Original field names: unresolved. MCP proves offsets and lifecycle. Use provisional names with offset caveats.
- Calling convention/source declaration: MCP decompiles `__thiscall`; source should be a normal C++ instance method, not an explicit low-level calling convention.
- Formatter side-call rationale: unresolved. MCP proves the call, buffer, capacity, and second throw. Preserve behavior and document that the source rationale is unknown.
- [UID:00039Q] owner family: out of scope for this exact target. MCP shows strong ScreenPane field evidence, but this report only recommends a support note and later family pass for [UID:00039Q].

## Exact Supervisor-Owned Coverage Text

B005 must not edit `by-memory/-coverage-report.md`. If the supervisor accepts this MCP-backed report, replace the [UID:00039R] row with:

```text
        - [UID:00039R][0x005576a0-0x00557810.SurfaceDirectDrawRestoreMaintenance](by-memory/0x005576a0-0x00557810.SurfaceDirectDrawRestoreMaintenance.md) 0x005576a0-0x00557810 | function | ScreenPaneDirectDrawStateRestore : reconstructable : 88% : very-strong : B005 2026-06-23 MCP-backed source-quality reanalysis reroutes direct owner/emitter to [UID:0000CB][ScreenPane](by-class/ScreenPane.md), with source path through [UID:0000NB][ScreenPane](by-file/ScreenPane.md); IDA MCP session `b880584f` confirms `sub_5576A0` size `0x170`, `.text` body, Hex-Rays `__thiscall` shape, receiver `dword_67A7CC` / `g_pScreenPane`, two direct code xrefs at `BaramApp::OnDeactivate` `0x00466abb` and `_WinMain@16` `0x004f5ed7`, zero data xrefs to the start, zero xrefs to `0x00557810`, predecessor padding `0x0055769d-0x005576a0` as `cc cc cc`, successor padding `0x00557810-0x00557820` as sixteen `cc` bytes, ScreenPane flags `+0x111` and `+0x110`, constructor zero at `0x00556a06`, paired setup writes at `0x005574e5` and `0x00557537`, destructor duplicate restore sequence, `g_pDirectX->m_pDirectDraw` calls through IDA `IDirectDrawVtbl` slots `+0x4c` `RestoreDisplayMode` and `+0x50` `SetCooperativeLevel(hwnd, DDSCL_NORMAL)`, and DDError pointer-throw paths; the previously grouped `+0x0c` slot is not DirectDraw here, but a temporary DDError object's formatter at `0x004a6290` before the SetCooperativeLevel failure throw. First-draft C++ is recommended with provisional method/field names and the formatter side-effect caveat.
```

Adjacent padding rows remain valid:

```text
        - [UID:0000VN][-ignored](by-memory/-ignored.md) 0x0055769d-0x005576a0 | padding | SurfaceFlipSurfaces to SurfaceDirectDrawRestoreMaintenance alignment : ignored : 100% : strong : IDA MCP confirms `0xcc` alignment.
        - [UID:0000VN][-ignored](by-memory/-ignored.md) 0x00557810-0x00557820 | padding | SurfaceDirectDrawRestoreMaintenance to ScreenPanePresentationModeFlagSetters alignment : ignored : 100% : strong : IDA MCP confirms `0xcc` alignment.
```

## Validator Results

Implementation callback validators were run from `E:\NTK\GhidraBridge\source-3\project-documentation` for every changed by-* doc, using the supervisor-specified scoped file mode and `--apply`. After the supervisor MCP restart, the same seven validators were rerun after updating evidence references to session `b880584f`; the results below are from that resumed run.

| File | Command | Result |
| --- | --- | --- |
| `by-memory/0x005576a0-0x00557810.SurfaceDirectDrawRestoreMaintenance.md` | `python .\tools\validator.py --mode file --file by-memory\0x005576a0-0x00557810.SurfaceDirectDrawRestoreMaintenance.md --apply --queue-timeout 240` | exit `0`; `scanned markdown files: 1`; `ok: 1` |
| `by-memory/0x00557140-0x00559aef.SurfacePresentation.md` | `python .\tools\validator.py --mode file --file by-memory\0x00557140-0x00559aef.SurfacePresentation.md --apply --queue-timeout 240` | exit `0`; `scanned markdown files: 1`; `ok: 1` |
| `by-file/Surface.md` | `python .\tools\validator.py --mode file --file by-file\Surface.md --apply --queue-timeout 240` | exit `0`; `scanned markdown files: 1`; `ok: 1` |
| `by-file/ScreenPane.md` | `python .\tools\validator.py --mode file --file by-file\ScreenPane.md --apply --queue-timeout 240` | exit `0`; `scanned markdown files: 1`; `ok: 1` |
| `by-class/ScreenPane.md` | `python .\tools\validator.py --mode file --file by-class\ScreenPane.md --apply --queue-timeout 240` | exit `0`; `scanned markdown files: 1`; `ok: 1` |
| `by-memory/0x00556910-0x00557132.ScreenPane.md` | `python .\tools\validator.py --mode file --file by-memory\0x00556910-0x00557132.ScreenPane.md --apply --queue-timeout 240` | exit `0`; `scanned markdown files: 1`; `ok: 1` |
| `by-memory/0x00557470-0x0055769d.SurfaceFlipSurfaces.md` | `python .\tools\validator.py --mode file --file by-memory\0x00557470-0x0055769d.SurfaceFlipSurfaces.md --apply --queue-timeout 240` | exit `0`; `scanned markdown files: 1`; `ok: 1` |

The filtered validator capture also reported `autogen_registry_rebuild: 1`, `autogen_report_noop: 7`, and `projected_stats_update: 1` on each run. These are validator-managed `--apply` side effects, not manual edits. No manual `-coverage-report.md` edit was made, and the validator reported coverage/report outputs as no-op; the exact supervisor-owned coverage replacement text remains supplied above.

## Changed Files

Modified in the accepted implementation callback:

```text
by-memory/0x005576a0-0x00557810.SurfaceDirectDrawRestoreMaintenance.md
by-memory/0x00557140-0x00559aef.SurfacePresentation.md
by-file/Surface.md
by-file/ScreenPane.md
by-class/ScreenPane.md
by-memory/0x00556910-0x00557132.ScreenPane.md
by-memory/0x00557470-0x0055769d.SurfaceFlipSurfaces.md
tools/leaser/Agents/Agent-B005/research/00039R-SurfaceDirectDrawRestoreMaintenance-source-quality.md
```

Not edited:

```text
any -coverage-report.md file manually
IDA DB
```

## Implementation Tracking Checklist

Report-only MCP redo proof:

- [x] Read Agent-B005 `goal.md`, `ntk-b-agent-workflow` skill, B-agent research workflow reference, and relevant `by-structure.md` MCP notes.
- [x] Rechecked current report and target/support docs as leads only.
- [x] Confirmed MCP session `b880584f` with `idb_list` and `server_health`; no IDA/process control was attempted.
- [x] Resumed after supervisor MCP restart with the formal stop-on-MCP-failure override active; discarded the prior session reference and revalidated the implementation evidence through session `b880584f`.
- [x] Revalidated [UID:00039R] function/range through `lookup_funcs`, `decompile`, and `disasm`.
- [x] Revalidated xrefs/callers/callees through `xrefs_to`, `xref_query`, `callees`, and caller disassembly.
- [x] Revalidated DirectDraw receiver/slot identities through target disassembly and IDA `type_inspect IDirectDrawVtbl`.
- [x] Revalidated DDError formatter path through vtable bytes, `get_int`/`int_convert`, and `decompile 0x004a6290`.
- [x] Revalidated padding and boundary bytes through `get_bytes`.
- [x] Revalidated ScreenPane field lifecycle through [UID:00039Q] setup disassembly and ScreenPane constructor/destructor disassembly.
- [x] Revalidated PE SHA-256 for the backing executable and project resource executable.
- [x] Replaced the stale "MCP unavailable" report basis with MCP-backed evidence.
- [x] Superseded the old checked implementation-callback checklist; current checklist below records the accepted implementation callback.

Initial report-only pass - proposed implementation items, now completed after supervisor validation:

- [x] Supervisor validation required before any new implementation callback or execution review. Proof: supervisor accepted this MCP-backed report for implementation on 2026-06-23.
- [x] Target doc to update or confirm already present at same-or-greater detail: `by-memory/0x005576a0-0x00557810.SurfaceDirectDrawRestoreMaintenance.md`. Proof: reconciled stale local-only language in `Exact Boundary And Padding`, `Evidence Basis`, `Vtable And SDK Method Resolution`, `Caller And Reachability Evidence`, `Context Pointer And Field Map`, `Score Rationale`, and `Changes`.
- [x] Target metadata to apply/retain after acceptance: `COMPLETION:88`, `CONFIDENCE:91`, `CANONICAL_OWNER:0000CB`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000CB`, blank emitter position. Proof: target header retains those exact metadata values.
- [x] Target C++ to apply/retain after acceptance: first-draft `ScreenPane::RestoreDirectDrawState()` preserving exact MCP-observed behavior. Proof: target C++ retains the `g_pDirectX` null return, no extra null checks, `IDirectDraw::RestoreDisplayMode`, `IDirectDraw::SetCooperativeLevel(g_pApplication->GetMainWindowHandle(), DDSCL_NORMAL)`, success-only clears for `+0x111/+0x110`, HRESULT throws, and the `DDError::FormatErrorMessage(formattedError, 0x50)` side call before the second throw.
- [x] Target evidence to apply/retain after acceptance: MCP session/path/hash, function range, decompile/disasm body, xrefs, caller receiver setup, padding, DirectDraw type-slot table, DDError formatter proof, field map, exception flow, owner ranking/rejections, and unresolved caveats. Proof: target now names MCP session `b880584f`, IDB path, PE SHA-256, `sub_5576A0` size `0x170`, two callers `0x00466abb`/`0x004f5ed7`, zero data xrefs, zero xrefs to `0x00557810`, padding bytes, IDA `IDirectDrawVtbl` slots, DDError formatter target `0x004a6290`, constructor/setup/destructor flag lifecycle, owner rejections, and original spelling/field-name/formatter/[UID:00039Q] caveats.
- [x] Required support docs to update or confirm already present at same-or-greater detail: `by-memory/0x00557140-0x00559aef.SurfacePresentation.md`, `by-file/Surface.md`, `by-file/ScreenPane.md`, `by-class/ScreenPane.md`, `by-memory/0x00556910-0x00557132.ScreenPane.md`, and `by-memory/0x00557470-0x0055769d.SurfaceFlipSurfaces.md`. Proof: all six required support docs were updated with MCP-backed 00039R routing, field lifecycle, DirectDraw/DDError slot proof, setup writes, and ScreenPane/Surface boundary rationale.
- [x] Optional support docs to touch only if stale wording remains: `by-memory/0x00559170-0x005591fc.SurfaceRestoreLostSurfaces.md` and direct dependency/caller pages listed in this report. Proof: `rg` check over the optional dependency/caller list found current ScreenPane-route dependency text or unrelated historical entries, not stale current 00039R Surface-owned/raw-PE wording requiring edits; no optional docs were touched.
- [x] Preserve historical/stale assumptions as superseded: Surface-owned direct route, unresolved DirectDraw `+0x4c/+0x50/+0x0c` grouping, raw-PE-only evidence basis, and old completed implementation checklist. Proof: target/support changes explicitly supersede Surface direct ownership and the unresolved slot grouping, while retaining rejected owner alternatives and caveats.
- [x] No split/new child/rename required; keep exact range and padding rows. Proof: target keeps `0x005576a0-0x00557810`, predecessor padding `0x0055769d-0x005576a0`, and successor padding `0x00557810-0x00557820`; no child or file rename was introduced.
- [x] No IDA rename/type/comment changes requested. Proof: implementation edited Markdown docs only and did not perform IDA DB changes.
- [x] Validators to run only after an accepted implementation callback for every changed by-* doc: `python .\tools\validator.py --mode file --file <relative-by-star-path> --apply --queue-timeout 240`. Proof: all seven changed by-* docs were validated with exit `0` and `ok: 1`; commands/results are listed in `Validator Results`.
- [x] Supervisor-owned coverage row to apply, if accepted: exact replacement text supplied above; B005 must not edit any `-coverage-report.md` file manually. Proof: exact coverage row remains in `Exact Supervisor-Owned Coverage Text`; validators reported `autogen_report_noop: 7`, and no manual coverage-report edit was made.

Implementation callback pass:

- [x] Report accepted by supervisor for implementation after MCP-backed review. Proof: acceptance callback named this report and target and required implementation.
- [x] Leases checked and taken before by-* edits. Proof: `tools/leaser\leaser.py B005 lease` succeeded for the seven required by-* docs before the resumed edits; `tools/leaser/Agents/current_leases.md` currently reports no active leases and no B005 entries.
- [x] All accepted target/support doc details incorporated or confirmed already present at same-or-greater detail. Proof: target plus six required support docs updated; optional docs checked and left untouched for already-current/not-material state.
- [x] Metadata/score/owner/emitter/C++ changes applied or retained with proof. Proof: target retains `88/91`, owner/emitter [UID:0000CB], reconstructable true, blank emitter position, and first-draft `ScreenPane::RestoreDirectDrawState()`.
- [x] Historical/stale assumptions, rejected alternatives, and negative evidence preserved. Proof: target keeps ranked owner rejection table, Surface/DirectX/Application/DDError rejection rationale, zero data xrefs, zero end xrefs, and [UID:00039Q] family follow-up caveat.
- [x] Open questions documented with evidence-backed unresolved rationale. Proof: target keeps unresolved original method spelling, inferred field names, source declaration/calling-convention caveat, DDError formatter rationale caveat, and [UID:00039Q] ownership-family follow-up.
- [x] Scoped validators run for every changed by-* doc and results recorded. Proof: see `Validator Results`, all exit `0`, `ok: 1`.
- [x] Supervisor-owned coverage-report/tracker text supplied or confirmed unchanged. Proof: coverage text remains in this report; validators reported `autogen_report_noop: 7`, and no manual coverage-report edit was made.
- [x] Remaining unapplied accepted items listed with exact blocker. Proof: no accepted implementation blockers remain.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"command_id":"000000004167","details":"report marked for revalidation","event":"needs-revalidation","issue":"target_uid_unknown: 00039R","source_path":"executed-b-agent-research/B005/00039R-SurfaceDirectDrawRestoreMaintenance-source-quality.md","timestamp":"2026-07-01T19:52:03-04:00"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
