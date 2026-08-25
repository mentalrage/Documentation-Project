** TARGET-REPORT-UID:0002GM **
** AUTHOR-AGENT-ID:B004 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# 0002GM ApplicationGetInstanceHandle Source-Quality Research

## Finalized Report / Current Recommendation

- Current recommendation: raise [UID:0002GM] `ApplicationGetInstanceHandle` from `84/92` to `88/93`, keep owner/emitter routing through [UID:00000D] `Application`, and add first-draft source-shaped C++ as `HINSTANCE Application::GetInstanceHandle() const`.
- Final disposition: implementation-ready if accepted. The target is an exact four-byte `Application` getter with current MCP-backed boundary, bytes, no-callee state, five direct caller sites, constructor initialization evidence for the returned field, and browser/window caller contexts that consume the return as an `HINSTANCE`.
- Required action if accepted: update the target page and synchronize Application class/file/lifecycle/constructor support docs. Do not edit coverage reports directly; the exact supervisor-owned replacement row is supplied below.
- Confidence: high for range, behavior, direct routes, owner/emitter, return type, field role, and C++ readiness; medium-high for exact original method spelling, exact original `m_hInstance` member spelling, and header/public/private placement.

## Supporting Research

## Target

- Target UID: `0002GM`
- Target path: `E:\NTK\GhidraBridge\source-3\project-documentation\by-memory\0x004651c0-0x004651c4.ApplicationGetInstanceHandle.md`
- Required report path: `E:\NTK\GhidraBridge\source-3\project-documentation\tools\leaser\Agents\Agent-B004\research\0002GM-ApplicationGetInstanceHandle-source-quality.md`
- Assignment ID: `B004-report-application-get-instance-handle-source-quality-0002GM-mcp-20260623`
- Source queue/report row: `project-level/-auto-completion-stats.md` lists `0002GM | 84 | 92 | 88.0`; `auto-generated/-ag-memory-coverage.md` routes it as `emits` through `auto-generated/NexusTK/app/Application.cpp` with an empty emitter marker; `by-memory/-coverage-report.md` has the current `84% : strong` row.
- Current scores and parent state: target is `COMPLETION:84`, `CONFIDENCE:92`, `CANONICAL_OWNER:00000D`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:00000D`, blank emitter position, blank C++.

## Current Target State

- Existing metadata: [UID:0002GM] is attached to [UID:00000D] `Application`, reconstructable, and emitted by the same class route into [UID:0000HG] `by-file/Application.md`.
- Existing behavior: documented as returning the process/module instance handle stored at `Application+0x20`.
- Existing evidence: older 2026-06-05/2026-06-06 IDA passes recorded exact size `0x4`, bytes `8b 41 20 c3`, no callees, five direct browser/window/UI callers, eight `0xcc` bytes before the function, and twelve `0xcc` bytes before sibling [UID:0002GN] `ApplicationGetMainWindowHandle`.
- Existing blocker/stale claim: the page leaves formal C++ blank because it cites the older `95/95` final-code gate and unresolved Application layout naming. That gate is stale under the current code-entry policy. Current by-structure rules allow first-draft C++ when the item is reconstructable, has a nonblank emitter route that surfaces to generated output, and `(COMPLETION + CONFIDENCE) / 2 > 85`, provided the source shape is strong enough.
- Related docs checked:
  - `by-class/Application.md`
  - `by-file/Application.md`
  - `by-memory/0x00463310-0x004674ed.ApplicationLifecycle.md`
  - `by-memory/0x00463310-0x0046396e.ApplicationConstructor.md`
  - `by-memory/0x004651d0-0x004651d7.ApplicationGetMainWindowHandle.md`
  - `by-memory/0x004651e0-0x004651e7.ApplicationIsRunning.md`
  - `auto-generated/-ag-memory-coverage.md`
  - `project-level/-auto-completion-stats.md`
  - `by-memory/-coverage-report.md`
  - `auto-generated/NexusTK/app/Application.cpp`

## Executive Recommendation

[UID:0002GM] should stay an exact `Application` class method under `app/Application.cpp`. The current evidence supports first-draft C++:

```cpp
HINSTANCE Application::GetInstanceHandle() const
{
    return m_hInstance;
}
```

`GetInstanceHandle`, `m_hInstance`, and `const` are source-facing inferred names/qualifiers, not original-symbol proof. They are nevertheless the best current final-output shape: the constructor stores WinMain's `hInstance` argument into `this[8]` / `Application+0x20`, the getter returns that dword unchanged, and every direct caller uses the result as a Win32 `HINSTANCE` for `WNDCLASSA.hInstance` or a window-creation call.

Do not emit the IDA/decompiler shape `int __thiscall sub_4651C0(_DWORD *this) { return this[8]; }`. Do not keep the target blank merely because broad Application class layout is not final-audit complete. This tiny getter has enough target-local, field, and caller evidence to cross the current source-quality gate while still documenting original spelling/header-placement caveats.

## Supervisor Active Recheck

- Supervisor instruction required report-only MCP-backed source-quality research using the current IDA MCP session, after stale session `b880584f` became unavailable.
- First MCP attempt with stale `b880584f` returned `idb_list` count `0` and `server_health(database=b880584f)` error `Session not found`; B004 paused and did not continue fallback-only research.
- Supervisor then resumed the assignment with verified session `261fb29b`. This report uses session `261fb29b` for the accepted evidence pass.
- MCP responded successfully for all bounded calls used below. No by-* docs, coverage reports, generated/project-level files, IDA DB, or tool state were edited.

## Inference Research Guidance Check

- Direct IDA facts, documentation evidence, and inference are separated below.
- Existing documentation assumptions treated as uncertain: exact original getter spelling, exact `m_hInstance` member spelling, and header/public/private declaration placement.
- Existing stale policy text treated as superseded: older `95/95` C++ blocker wording on the target and support docs.
- Wave2/Wave3 material encountered: generated coverage and generated C++ were used only as current route/output-state evidence. No Wave2/Wave3 name or source-shape claim was accepted as proof.
- Code-entry rule: the current target average is already `88.0`, owner/emitter route is nonblank and surfaces to `auto-generated/NexusTK/app/Application.cpp`, and the C++ body is a single exact field getter with strong source type evidence. The target is eligible for first-draft C++.

## Evidence Standards Used

- MCP evidence types: `initialize`, `tools/list`, `idb_list`, `server_health`, `lookup_funcs`, `entity_query`, `get_bytes`, `disasm`, `decompile`, `callees`, `xrefs_to`, `analyze_function`, `find_bytes`, and bounded `insn_query`.
- Local supplement: raw PE SHA-256/MD5, section map, target raw offset, body hash, unique body-byte search, rel32 control-transfer scan, and absolute VA/RVA/raw-offset pointer scans.
- Documentation evidence: current target page, Application class/file/lifecycle/constructor/sibling pages, generated memory coverage, generated `Application.cpp`, current auto-completion stats, and current memory coverage row.
- Evidence ladder application: MCP function/byte/xref/disassembly/decompile facts are primary; PE route scan independently corroborates route/pointer claims; support docs supply ownership/source-family context; source-facing names remain inference and cap the score.
- IDA MCP limitations: MCP cannot prove original source names, member spelling, or header declaration placement without debug/source metadata. The report therefore recommends source-shaped inferred names and records the remaining uncertainty.

## Evidence Checked

MCP session/provenance:

- `initialize` returned server `ida-pro-mcp`, protocol `2025-06-18`; `tools/list` returned `65` tools.
- `idb_list` returned one active session `261fb29b`, input path `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, filename `NexusTK.exe.i64`, `is_active:true`, `is_analyzing:false`, backend `worker`, worker PID `12132`, created `2026-06-23T07:51:09.317417`.
- `server_health(database=261fb29b)` returned `status:"ok"`, IDB path `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, module `NexusTK.exe`, input executable `C:\Users\admin\Desktop\Clone\NexusTK\NexusTK.exe`, imagebase `0x400000`, `auto_analysis_ready:true`, `hexrays_ready:true`, `strings_cache_ready:true`, and strings cache size `2067`.

by-* docs, generated reports, and target state checked:

- Target page [UID:0002GM] current metadata, evidence, blank C++ block, and stale `95/95` gate wording.
- `by-class/Application.md` method and field sections: target is already listed as `GetInstanceHandle`; field section already has `m_hInstance around 0x20`, but it does not include current target-specific MCP/PE proof.
- `by-file/Application.md` Application responsibilities/source-placement audit and generated-output status.
- `by-memory/0x00463310-0x004674ed.ApplicationLifecycle.md` child list and lifecycle child refresh notes.
- `by-memory/0x00463310-0x0046396e.ApplicationConstructor.md` constructor parameter and touched-state notes.
- Sibling accessors [UID:0002GN] `ApplicationGetMainWindowHandle` and [UID:0002GO] `ApplicationIsRunning`.
- `auto-generated/-ag-memory-coverage.md`, `auto-generated/NexusTK/app/Application.cpp`, `project-level/-auto-completion-stats.md`, and `by-memory/-coverage-report.md`.

Negative checks performed:

- MCP `xrefs_to(0x004651c0)` found exactly five incoming code xrefs and no data xrefs.
- MCP `callees(0x004651c0)` returned an empty callee list.
- MCP `xrefs_to(0x004651b8)` and `xrefs_to(0x004651c4)` returned zero refs to the adjacent padding boundaries.
- MCP `find_bytes` found zero dword matches for target VA `c0 51 46 00`, target RVA `c0 51 06 00`, and target raw offset `c0 45 06 00`.
- Local PE scan found the same zero file-wide dword matches and exactly five direct `E8` control-transfer hits to the target. No pointer table, vtable slot, raw data route, or alternate indirect route was found.
- No evidence found for `Browser`, `BrowserWindow`, `BrowserControlPane`, `BrowserThread`, `WinMain`, or a no-owner/global helper disposition as the canonical owner.

Failed, unavailable, or intentionally skipped checks:

- Initial MCP session `b880584f` was stale and rejected before this report was finalized. The report was resumed only after supervisor verified session `261fb29b`.
- No broad `insn_query` or whole-image heavy scan was needed beyond the bounded target route checks and local PE scan. The target is tiny, has direct xrefs, and the PE scan independently checked direct calls and dword pointer forms.

## IDA MCP Facts

Function/range inventory:

| Address | MCP result |
| --- | --- |
| `0x004651b8` | not a function |
| `0x004651c0` | `sub_4651C0`, size `0x4` |
| `0x004651c4` | not a function |
| `0x004651d0` | `sub_4651D0`, size `0x7` |
| `0x004651e0` | `sub_4651E0`, size `0x7` |
| `0x004651f0` | `sub_4651F0`, size `0xec` |

MCP `entity_query(functions, 0x004651b0-0x004651f0)` returned exactly the local modeled functions at `0x004651c0`, `0x004651d0`, `0x004651e0`, and `0x004651f0`. This confirms the getter is an exact standalone function and that `0x004651c4-0x004651d0` is inter-function padding before the main-window-handle getter.

Bytes and padding:

| Range | MCP bytes |
| --- | --- |
| `0x004651b8-0x004651c0` | `cc cc cc cc cc cc cc cc` |
| `0x004651c0-0x004651c4` | `8b 41 20 c3` |
| `0x004651c4-0x004651d0` | `cc cc cc cc cc cc cc cc cc cc cc cc` |
| `0x004651d0-0x004651d7` | `8b 81 28 08 00 00 c3` |
| `0x004651e0-0x004651e7` | `8a 81 38 08 00 00 c3` |

Target disassembly:

```asm
0x4651c0 mov eax, [ecx+20h]
0x4651c3 retn
```

Target decompile:

```c
int __thiscall sub_4651C0(_DWORD *this)
{
  return this[8]; /*0x4651c3*/
}
```

MCP `disasm` reports segment `.text`, two instructions, one basic block, and current IDA prototype `int __thiscall(_DWORD *this)`. MCP `analyze_function` reports size `4`, no strings, no constants, no callees, one basic block, cyclomatic complexity `1`, and the five xrefs listed below.

Incoming xrefs:

| Xref | Containing MCP function | Source-family role |
| --- | --- | --- |
| `0x00469776` | `sub_469640`, size `0x3d7` | [UID:0000Z4] `BrowserWindowCore` |
| `0x0046b6c2` | `sub_46B520`, size `0x46e` | [UID:0000Z6] `BrowserControlPaneCore` |
| `0x0046b762` | `sub_46B520`, size `0x46e` | [UID:0000Z6] `BrowserControlPaneCore` |
| `0x00470ad3` | `sub_470A00`, size `0x3c9` | [UID:00032W] `BrowserThreadInitializeBrowserHost` |
| `0x00470b7b` | `sub_470A00`, size `0x3c9` | [UID:00032W] `BrowserThreadInitializeBrowserHost` |

Caller snippets and return-type evidence:

```asm
0x469776 call sub_4651C0
0x469782 mov [ebp+WndClass.hInstance], eax
```

`sub_469640` decompile states `WndClass.hInstance = (HINSTANCE)sub_4651C0((_DWORD *)unk_67AB1C);` and later calls `CreateWindowExA(..., hInstance, 0)` in the browser-window host setup.

```asm
0x46b6c2 call sub_4651C0
0x46b6ce mov [ebp+WndClass.hInstance], eax
```

`sub_46B520` decompile states `WndClass.hInstance = (HINSTANCE)sub_4651C0(v24);`, then `RegisterClassA(&WndClass)`.

```asm
0x46b762 call sub_4651C0
0x46b76d push eax; hInstance
0x46b770 call sub_4651D0
0x46b775 push eax; hWndParent
```

`sub_46B520` decompile states `v17 = (HINSTANCE)sub_4651C0(v24);`, `v7 = (HWND)sub_4651D0(v24);`, then `CreateWindowExA(..., v7, 0, v17, 0)`.

```asm
0x470ad3 call sub_4651C0
0x470adf mov [ebp+var_3DC], eax
```

`sub_470A00` decompile shows the returned value stored into the local window-class structure slot for `hInstance`.

```asm
0x470b7b call sub_4651C0
0x470b86 push eax
0x470b89 call sub_4651D0
0x470b8e push eax
```

`sub_470A00` decompile states `v17 = sub_4651C0(v23);`, `v6 = sub_4651D0(v23);`, then calls the window-creation dispatch `unk_69BE44(..., v6, 0, v17, 0)`.

Field initialization evidence:

- MCP decompile of `Application__Constructor` reports `HKEY __thiscall Application__Constructor(HKEY this, int a2, wchar_t *Source, wchar_t *a4)` and the direct assignment `*((_DWORD *)this + 8) = a2; /*0x4634f6*/`.
- `this[8]` is byte offset `0x20`; `int_convert.py --text 0x20` returned decimal `32` (Verified with `int_convert.py`).
- MCP disassembly of `_WinMain@16` shows `mov esi, [ebp+hInstance]`, then `push esi` before `call Application__Constructor` at `0x004f5cca`.
- MCP decompile of WinMain reports `WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd)` and `Application__Constructor((int)hInstance, ...) /*0x4f5cca*/`.
- MCP disassembly of the raw BaramApp forwarding body at `0x004f5f20-0x004f5f40` shows it forwards its first stack argument through `push dword ptr [ebp+8]` before `call Application__Constructor` at `0x004f5f33`.

The field returned by [UID:0002GM] is therefore the constructor-captured Win32 application instance handle, not the main window handle, module singleton pointer, global application pointer, or a generic integer status.

## PE Route Scan Supplement

B004 supplemented MCP with a local PE scan of `E:\NTK\Resources\NexusTK\NexusTK.exe`, length `2679296`, MD5 `4247e04e20b65d6414c7238aa8ff5515`, SHA-256 `9aec210bbc5ce592176a21dd8e9d9fd8f250b8d9ea78237915a99ba8cfa9a632`, imagebase `0x400000`.

Section map:

| Section | VA / virtual size | Raw range |
| --- | --- | --- |
| `.text` | `0x00401000`, virtual size `0x20b4ac` | raw `0x00000400+0x20b600` |
| `.rdata` | `0x0060d000`, virtual size `0x5f0be` | raw `0x0020ba00+0x5f200` |
| `.data` | `0x0066d000`, virtual size `0x2fe24` | raw `0x0026ac00+0xd800` |

Target accounting: VA `0x004651c0`, RVA `0x000651c0`, raw offset `0x000645c0`, section `.text`. Target-body SHA-256 over the four bytes is `07ad3a50b1c271e07fb57fb47d2f0e77f3342d41bfa410990cb1320a45035fb2`.

Local PE byte checks:

- `0x004651b8-0x004651c0`: `cc cc cc cc cc cc cc cc`
- `0x004651c0-0x004651c4`: `8b 41 20 c3`
- `0x004651c4-0x004651d0`: `cc cc cc cc cc cc cc cc cc cc cc cc`

Local PE route checks:

- File-wide `8b 41 20 c3` body pattern: one hit at raw `0x645c0`.
- File-wide target VA dword `c0 51 46 00`: zero hits.
- File-wide target RVA dword `c0 51 06 00`: zero hits.
- File-wide target raw-offset dword `c0 45 06 00`: zero hits.
- `.text` direct control transfers to `0x004651c0`: five `E8` calls at `0x00469776`, `0x0046b6c2`, `0x0046b762`, `0x00470ad3`, and `0x00470b7b`.

The PE scan agrees with MCP and rejects hidden pointer-table/vtable/data ownership routes.

## Heuristic / Inference Reanalysis And Validation

- Return type: use `HINSTANCE`, not `int`, `DWORD`, `HMODULE`, `void *`, or `HANDLE`. The binary only returns a dword, but WinMain passes `hInstance` into the constructor, the constructor stores that value at `Application+0x20`, and every direct caller consumes the getter return as `WNDCLASSA.hInstance` or the `hInstance` argument to `CreateWindowExA` / the PlatformApi CreateWindowEx dispatch. `HINSTANCE` is therefore source-correct even if the IDA decompiler shows `int`.
- Field name: use `m_hInstance`. Current `by-class/Application.md` already uses `m_hInstance around 0x20`; this pass ties the name to constructor and caller evidence. Exact original member spelling remains inferred; possible alternatives include `m_hInst`, `m_hInstanceHandle`, `m_hModule`, or `m_instanceHandle`, but `m_hInstance` is the clearest project-local Win32 style and matches the WinMain parameter.
- Method name: keep `GetInstanceHandle()`. It is already used by the target filename and support docs, and it accurately describes the getter's role. Alternatives such as `GetInstance`, `GetModuleHandle`, `GetHInstance`, or `InstanceHandle` are plausible original spellings but less aligned with current docs and the function's Windows field role. `sub_4651C0` and `ApplicationGetInstanceHandle` are evidence/search names, not final C++ API text.
- `const` qualifier: use `const` in first-draft C++ because the target reads `this+0x20`, performs no writes, calls no helpers, and has no side effects. Exact original header qualifier is not symbol-proven, so this remains a source-quality inference and caps the score below final.
- Source placement: keep under `Application.cpp` through the `Application` class. Browser callers are consumers that need the app instance for Win32 class/window setup; they do not own the field or getter.
- Blank-C++ status: reject the current blank C++ rationale. The old `95/95` gate is stale, and this target has enough exact evidence to emit a final-shaped getter while documenting original-name/header caveats.

## Inference Claim Ledger

| Claim | Confidence | Evidence | Counter-evidence checked | Remaining uncertainty |
| --- | --- | --- | --- | --- |
| Exact range is `0x004651c0-0x004651c4` | High | MCP `lookup_funcs` size `0x4`; bytes `8b 41 20 c3`; padding before/after; next function `0x004651d0` | MCP `entity_query`, `xrefs_to` on padding, PE bytes | None for range |
| Function returns `Application+0x20` | High | Disassembly `mov eax,[ecx+20h]; retn`; decompile `return this[8]`; no callees | Raw bytes and PE unique body pattern | None for behavior |
| Field is the captured WinMain `HINSTANCE` | High | Constructor assigns `a2` to `this[8]`; WinMain passes `hInstance`; all callers consume return as `HINSTANCE` | Checked sibling HWND getter at `+0x828`; checked browser callers are consumers | Exact member spelling unresolved |
| Owner is `Application` | High | `this` field read; constructor initializes same field; class/file docs own Application state; generated route emits through Application | Browser/WinMain/global/no-owner alternatives checked and rejected | Header/public/private placement unresolved |
| First-draft C++ is ready | High for body, medium-high for exact names | Exact body, route, return type, field role, current code-entry gate, support-doc field name | Original symbol/header not available; broad class C++ still blank | Original method/member spelling and `const` qualifier could change with future symbols |

## Positive Evidence Summary

- `sub_4651C0` is a real IDA-modeled function with exact size `0x4`.
- The body is the simplest possible Application field getter: `mov eax, [ecx+20h]; retn`.
- MCP and PE agree on bytes, padding, no callees, and five direct call sites.
- Constructor evidence proves the returned field stores the WinMain `hInstance` argument.
- Caller evidence proves the return is used as a Win32 `HINSTANCE` in browser/window host setup.
- Existing owner/emitter route is valid: [UID:0002GM] -> [UID:00000D] `Application` -> [UID:0000HG] `Application` file -> `auto-generated/NexusTK/app/Application.cpp`.
- Existing class docs already name the field direction as `m_hInstance`; this pass supplies current target-local proof.

## Negative And Rejected Evidence Summary

- No callees, no strings, no internal branches, no hidden helper dependencies.
- No xrefs to padding boundary `0x004651b8` or end boundary `0x004651c4`.
- No absolute target VA/RVA/raw-offset dword hits in MCP `find_bytes` or local PE scan.
- No non-call pointer, vtable, jump-table, callback-table, or raw data route to the getter.
- Browser callers do not own the getter: they only consume the Application instance handle for `WNDCLASSA`/window creation.
- `WinMain` does not own the getter: it supplies the constructor argument but does not own the Application object field or accessor method.
- No-owner/non-emitting is rejected because the target is reconstructable, class-owned, route-valid, and C++-ready.

## Ranked Ownership And Source-Placement Alternatives

| Rank | Candidate | Decision |
| ---: | --- | --- |
| 1 | [UID:00000D] `Application` class under [UID:0000HG] `Application.cpp` | Accepted. The getter reads an Application field initialized by the Application constructor and consumed through the existing Application class route. |
| 2 | [UID:0000HG] `Application` file as direct owner | Rejected as too broad for canonical owner. The source file is the emitter root, but the narrow semantic owner is the `Application` class. |
| 3 | [UID:0000Z4] `BrowserWindowCore`, [UID:0000Z6] `BrowserControlPaneCore`, [UID:00032W] `BrowserThreadInitializeBrowserHost` | Rejected. These contain all five call sites, but each call consumes the returned handle for browser host window setup. They do not initialize or own `Application+0x20`. |
| 4 | [UID:0000PA] `WinMain` / startup entry | Rejected. WinMain passes `hInstance` to the constructor, but the long-lived field and accessor are Application-owned. |
| 5 | Global or standalone platform helper | Rejected. The value is read through `ecx+0x20`, not a global or imported API; no pointer/global route exists. |
| 6 | No-owner/non-emitting | Rejected. The target has exact class ownership, valid emitter route, and first-draft C++ readiness. |

## First-Draft C++ Recommendation

Recommended target C++:

```cpp
HINSTANCE Application::GetInstanceHandle() const
{
    return m_hInstance;
}
```

Reasons:

- The target covers the entire function body.
- `HINSTANCE` matches constructor and caller evidence better than IDA's generic `int`.
- `m_hInstance` matches current Application class field naming direction and the exact stored value.
- The body preserves exact behavior: read one dword field and return it unchanged.
- No null checks, casts, wrapper calls, globals, or decompiler temporaries should be added.

C++ caveats to document:

- Exact original method spelling is not symbol-proven.
- Exact original member spelling is not symbol-proven.
- `const` is inferred from the side-effect-free body.
- Broad `Application` class declaration can remain blank until the larger class layout/header audit is complete; this exact child can still emit the getter body.

## Target And Support Doc Changes Needed If Accepted

Target path: `by-memory/0x004651c0-0x004651c4.ApplicationGetInstanceHandle.md`

- Change metadata to `COMPLETION:88`, `CONFIDENCE:93`.
- Keep `CANONICAL_OWNER:00000D`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:00000D`, and blank emitter position unchanged.
- Insert the first-draft C++ block shown above.
- Replace stale `95/95`/blank-C++ wording with current code-entry gate rationale.
- Incorporate the 2026-06-23 MCP session `261fb29b` facts: session/health provenance, function inventory, exact bytes, disassembly, decompile, no callees, one basic block/cyclomatic `1`, five code xrefs, zero padding xrefs, zero target pointer hits, and bounded caller snippets.
- Preserve PE route-scan facts: local PE path/hash, section map, target raw offset, body hash, unique body pattern, five `E8` calls, and zero VA/RVA/raw dword hits.
- Preserve field/source-shape rationale: constructor stores `hInstance` into `Application+0x20`, callers consume as `HINSTANCE`, sibling `GetMainWindowHandle` at `+0x828` proves this is not HWND, and source names remain inferred.
- Preserve rejected alternatives: Browser callers, WinMain, Application file as direct owner, global helper, pointer table/vtable route, and no-owner/non-emitting.

Support path: `by-class/Application.md`

- Update the method entry for [UID:0002GM] to say it now has first-draft `HINSTANCE Application::GetInstanceHandle() const` C++.
- Strengthen the `m_hInstance` field note at `+0x20` with B004 evidence: constructor store at `0x004634f6`, WinMain `hInstance` pass at `0x004f5cca`, five getter callers, and HINSTANCE caller use.
- Add or update a change entry noting that the older small-getter blank-C++ status is superseded for [UID:0002GM], just as [UID:0002H4] was superseded by a later source-quality pass.

Support path: `by-file/Application.md`

- Add [UID:0002GM] to the current source-ready getter exceptions in the Application source page, alongside [UID:0002H4] where appropriate.
- Preserve route/source-placement detail: target emits through `Application.cpp`, browser modules are caller/consumers, and broad lifecycle methods may still remain blank because their helper/API declarations are unresolved.
- Add the field/return-type summary and no-pointer-route caveat at support level.

Support path: `by-memory/0x00463310-0x004674ed.ApplicationLifecycle.md`

- Update the lifecycle child refresh table/list to record [UID:0002GM] as `88/93` and source-ready with first-draft getter C++.
- Update the older "small accessors final-code omissions" wording so [UID:0002GM] is no longer described as blank/omitted after this accepted pass.
- Preserve that the aggregate itself remains a no-code context parent and does not emit a monolithic lifecycle body.

Support path: `by-memory/0x00463310-0x0046396e.ApplicationConstructor.md`

- Update the `this + 0x20` touched-state row from "likely process/module startup state, final name unresolved" to the stronger result: constructor argument `a2` is the WinMain `hInstance` value and this field is the `m_hInstance`/instance-handle field read by [UID:0002GM].
- Preserve caveat that exact original member spelling remains inferred.
- No constructor C++ should be added as part of this target; only the field-role support note should be synchronized.

Optional sibling path: `by-memory/0x004651d0-0x004651d7.ApplicationGetMainWindowHandle.md`

- No edit required unless implementation finds stale cross-sibling wording. It already records the twelve-byte pre-padding after [UID:0002GM] and the main-window-handle distinction.

## Score And Metadata Recommendation

- Current score/metadata: `COMPLETION:84`, `CONFIDENCE:92`, owner/emitter `00000D`, reconstructable true, blank C++.
- Recommended score/metadata: `COMPLETION:88`, `CONFIDENCE:93`, owner/emitter unchanged, reconstructable unchanged, C++ populated.
- Score rationale:
  - Raise completion because the current MCP/PE evidence validates the exact function, range, bytes, padding, no-callee state, five callers, field initialization, caller return type, no pointer/table routes, source placement, rejected alternatives, and first-draft C++.
  - Raise confidence slightly because session `261fb29b` refreshed the evidence and added constructor/caller route proof beyond the older target page. Keep below `95` because exact original method spelling, exact member spelling, `const` qualifier, and header/public-private placement remain inferred.
  - Do not leave completion at `84` because the remaining uncertainties are source-name/header caveats, not behavior, route, range, or C++ blockers.
- Metadata fields:
  - `CANONICAL_OWNER:00000D` unchanged.
  - `RECONSTRUCTABLE:TRUE` unchanged.
  - `EMITTER_UIDS:00000D` unchanged.
  - `EMITTER_POSITION_OPTIONAL:` unchanged/blank.

## Open Questions With Attempted Resolution

- Exact original method spelling:
  - Evidence checked: current target/support docs, MCP function name/decompile, caller contexts, generated output.
  - Best supported resolution: use `Application::GetInstanceHandle() const`.
  - Remaining uncertainty: original source might have used `GetHInstance`, `GetInstance`, or similar. Cap score.
- Exact field name:
  - Evidence checked: constructor store, WinMain `hInstance` pass, five callers, current Application class field note.
  - Best supported resolution: use inferred `m_hInstance`.
  - Remaining uncertainty: original header might have used `m_hInst`, `m_hModule`, or another local convention. Cap score.
- Public/private/header placement:
  - Evidence checked: five callers outside Application, generated route through class/file, class docs.
  - Best supported resolution: a callable Application member getter exists and can be emitted on the exact child page.
  - Remaining uncertainty: no symbol/header metadata proves whether the declaration was public, protected, inline in header, or out-of-line in `Application.cpp`. Cap score but do not block child C++.
- Browser caller relationship:
  - Evidence checked: BrowserWindow/BrowserControlPane/BrowserThread call sites.
  - Resolution: browser source owns the callers; Application owns the getter and field.

## Exact Supervisor-Owned Coverage Text

File/placement: `by-memory/-coverage-report.md`, replace the current [UID:0002GM] row.

Exact replacement text:

```markdown
    - [UID:0002GM][0x004651c0-0x004651c4.ApplicationGetInstanceHandle](by-memory/0x004651c0-0x004651c4.ApplicationGetInstanceHandle.md) 0x004651c0-0x004651c4 | class method | ApplicationGetInstanceHandle : reconstructable : 88% : very strong : B004 2026-06-23 MCP session `261fb29b` and PE scan confirm exact `0x4` Application getter bytes `8b 41 20 c3` / `mov eax,[ecx+0x20]; retn`, no callees, eight-byte and twelve-byte `0xcc` padding boundaries, five direct browser/window setup callers at `0x00469776`, `0x0046b6c2`, `0x0046b762`, `0x00470ad3`, and `0x00470b7b`, zero target VA/RVA/raw-offset pointer hits, constructor store of WinMain `hInstance` into `Application+0x20`, and caller use as `WNDCLASSA.hInstance` / `CreateWindowExA` `HINSTANCE`. First-draft `HINSTANCE Application::GetInstanceHandle() const` C++ is ready; cap remains for inferred original method/member spelling, `const` qualifier, and header placement.
```

Reason B004 must not apply it directly: report-only assignment forbids editing any `-coverage-report.md` file; coverage application is supervisor-owned.

## Follow-Up Actions

- Supervisor actions:
  - Review/accept or reject the `88/93` and first-draft C++ recommendation.
  - Apply the coverage row only after accepted implementation is verified.
- B004 implementation actions if callback accepted:
  - Update target and support docs at report-level detail.
  - Run scoped validators for every changed by-* doc from `source-3/project-documentation`.
- A-agent actions: none required by this report.

## Confidence

- Recommendation confidence: high.
- Score confidence: high for `88/93` as a capped source-quality score.
- Remaining uncertainty: original names, `const`, and header placement only. No behavior, range, owner, emitter, or first-draft C++ blocker remains.

## Validator Results

- Implementation validators run from `E:\NTK\GhidraBridge\source-3\project-documentation`.
- Target validator:
  - `python .\tools\validator.py --mode file --file by-memory\0x004651c0-0x004651c4.ApplicationGetInstanceHandle.md --apply --queue-timeout 240`
  - First pass exit code `0`, `ok: 1`; validator applied `completion_update 0002GM 88`, `confidence_update 0002GM 93`, inserted UID links, updated validator-owned `auto-generated/NexusTK/app/Application.cpp`, updated validator-owned `auto-generated/-ag-memory-coverage.md`, updated `project-level/-auto-completion-stats.md`, rebuilt `tools/validator.ini`, and created `tools/validator_autogen_backup/20260623-081243`.
  - B004 noticed the report's `Application__Constructor` UID reference expanded to the wrong [UID:0002EW] target, corrected it to [UID:0002GY], and reran the same command. Second pass exit code `0`, `ok: 1`; validator inserted the corrected [UID:0002GY] constructor link, removed the stale [UID:0002EW] reference index entry, and reported generated outputs unchanged.
- Support validators:
  - `python .\tools\validator.py --mode file --file by-class\Application.md --apply --queue-timeout 240`: exit code `0`, `ok: 1`; validator inserted [UID:0002GM] link, updated two existing getter target annotations, updated projected stats, and rebuilt the autogen registry.
  - `python .\tools\validator.py --mode file --file by-file\Application.md --apply --queue-timeout 240`: exit code `0`, `ok: 1`; validator inserted [UID:0002GM] link, updated projected stats, and rebuilt the autogen registry.
  - `python .\tools\validator.py --mode file --file by-memory\0x00463310-0x004674ed.ApplicationLifecycle.md --apply --queue-timeout 240`: exit code `0`, `ok: 1`; validator updated the existing stats row and rebuilt the autogen registry.
  - `python .\tools\validator.py --mode file --file by-memory\0x00463310-0x0046396e.ApplicationConstructor.md --apply --queue-timeout 240`: exit code `0`, `ok: 1`; validator added reference-index entries for [UID:0002GM] and [UID:0002GO], updated projected stats, and rebuilt the autogen registry.
- Repeated validator side effects/notes: each support scan reported pre-existing `autogen_registry_stale` entries for missing registered files [UID:0003E6] and [UID:00026U]. These were not introduced by this implementation. No `-coverage-report.md` validator edit was performed.

## Changed Files

- Edited by B004:
  - `by-memory/0x004651c0-0x004651c4.ApplicationGetInstanceHandle.md`
  - `by-class/Application.md`
  - `by-file/Application.md`
  - `by-memory/0x00463310-0x004674ed.ApplicationLifecycle.md`
  - `by-memory/0x00463310-0x0046396e.ApplicationConstructor.md`
  - `tools/leaser/Agents/Agent-B004/research/0002GM-ApplicationGetInstanceHandle-source-quality.md`
- Validator-owned side effects observed:
  - `auto-generated/NexusTK/app/Application.cpp`
  - `auto-generated/-ag-memory-coverage.md`
  - `project-level/-auto-completion-stats.md`
  - `tools/validator.ini`
- Not edited by B004:
  - `by-memory/-coverage-report.md`; exact replacement row remains supervisor-owned.
  - Optional sibling `by-memory/0x004651d0-0x004651d7.ApplicationGetMainWindowHandle.md`; it already records the `0x828` HWND distinction and the twelve-byte padding after [UID:0002GM], so no material B004 support edit was needed.
- Renamed: none.
- Moved to executed: none.
- Leases: B004 leased the target for the target edit/validator batch and released it successfully. B004 later leased `by-class/Application.md`, `by-file/Application.md`, `by-memory/0x00463310-0x004674ed.ApplicationLifecycle.md`, and `by-memory/0x00463310-0x0046396e.ApplicationConstructor.md` after B005's overlap leases cleared; validators completed with `ok: 1`, then the explicit unlease command reported `Rejected[No active lease]` because the B004 leases had already expired. Shared `current_leases.md` reported `No active leases` at that cleanup check; a later final check showed B005 had reacquired the overlapping support-doc leases after B004's edit/validator batch, so B004 did not make further support-doc edits.

## Implementation Tracking Checklist

Initial report-only pass:

- [x] Supervisor validation required before implementation. Proof: supervisor accepted the report and issued implementation callback `B004-implement-application-get-instance-handle-source-quality-0002GM-mcp-20260623`.
- [x] Target/support docs to update: target `by-memory/0x004651c0-0x004651c4.ApplicationGetInstanceHandle.md`; required support `by-class/Application.md`, `by-file/Application.md`, `by-memory/0x00463310-0x004674ed.ApplicationLifecycle.md`, and `by-memory/0x00463310-0x0046396e.ApplicationConstructor.md`; optional sibling `by-memory/0x004651d0-0x004651d7.ApplicationGetMainWindowHandle.md` only if stale wording is found during implementation. Proof: all required docs edited; optional sibling reread and left unchanged because it already records the `0x828` HWND role and padding distinction at same-or-greater relevant detail.
- [x] Current target state and actual evidence checked recorded: target metadata, blank C++/stale gate text, MCP session `261fb29b`, PE route scan, constructor/WinMain field initialization, caller snippets, support docs, generated coverage, and current coverage row are recorded in this report. Proof: target page now has `2026-06-23 B004 MCP And PE Source-Quality Pass` preserving those facts; support docs cross-synchronize the constructor/field/source-route facts.
- [x] Metadata/score changes to apply: change target `COMPLETION:84` to `COMPLETION:88`; change `CONFIDENCE:92` to `CONFIDENCE:93`. Proof: target metadata changed; target validator first pass reported `completion_update 0002GM 88` and `confidence_update 0002GM 93`, exit code `0`, `ok: 1`.
- [x] Owner/emitter/reconstructable changes to apply: keep `CANONICAL_OWNER:00000D`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:00000D`, and blank emitter position unchanged. Proof: target header retains those exact fields.
- [x] Split/rename/new-child changes to apply: no split, rename, merge, new child, ignored-range change, or reclassification. Proof: no file rename/new child was performed.
- [x] Source-placement, range/split/padding/reclassification, or IDA rename/type/comment changes to apply or confirm not applicable: keep source placement in `NexusTK/app/Application.cpp`; preserve exact range `0x004651c0-0x004651c4`; preserve adjacent ignored padding; no IDA DB edits. Proof: target scope and support route still point through Application/Application.cpp; padding facts are preserved; no MCP/IDA edit call was made.
- [x] First-draft C++ or no-code proof to apply: insert source-shaped `HINSTANCE Application::GetInstanceHandle() const` returning `m_hInstance`. Proof: target formal reconstruction block now contains the accepted four-line getter.
- [x] Exact target/support doc facts to incorporate at report-level detail: MCP health/session, lookup/entity query, xrefs, caller/callee, bytes, disassembly/decompile, caller snippets, constructor/WinMain field initialization, PE SHA/section/route scan, no target pointer hits, source-shaped return-type/field rationale, and score cap. Proof: target page contains the full B004 MCP/PE section; support docs record the same facts at appropriate class/file/lifecycle/constructor granularity.
- [x] Historical/stale assumptions, rejected alternatives, and negative evidence to preserve: stale `95/95` gate correction, Browser caller/consumer rejection, WinMain caller rejection, Application-file-as-direct-owner rejection, no pointer/table/vtable route, no padding xrefs, no-callee state, and original method/member/header spelling caveats. Proof: target page records all rejected alternatives and the stale gate correction; support docs preserve Browser-as-consumer and larger-lifecycle blank-C++ distinctions.
- [x] Wave2/Wave3 mentions or artifacts encountered and ignored/rejected as stale, if applicable: generated coverage/source routes used only as current route/output-state evidence; no Wave2/Wave3 naming accepted as proof. Proof: docs use generated output only as route/status context; final C++ uses source-facing inferred names from MCP/PE evidence.
- [x] Open questions to close or document as evidence-backed unresolved: original method spelling, original `m_hInstance` spelling, `const` qualifier, and header/public-private placement remain unresolved and cap score; no behavior/route/range/C++ blocker remains. Proof: target and support docs state these caveats and cap rationale.
- [x] Validators to run: run scoped validators for every changed by-* file from `E:\NTK\GhidraBridge\source-3\project-documentation` using the commands listed in `Validator Results`. Proof: all five changed by-* docs validated with exit code `0`, `ok: 1`; commands/results are recorded above.
- [x] Supervisor-owned coverage-report/tracker text to apply: replace [UID:0002GM] row in `by-memory/-coverage-report.md` with the exact row supplied above if accepted. Proof: exact replacement row remains in `Exact Supervisor-Owned Coverage Text`; B004 did not edit `by-memory/-coverage-report.md`.

Implementation callback pass:

- [x] Report accepted by supervisor for implementation: accepted by supervisor callback for `0002GM`.
- [x] All accepted target/support doc details incorporated at report-level detail: target and required support docs updated; optional sibling left unchanged with same-or-greater relevant detail.
- [x] Metadata/score/owner/emitter/split/rename/C++ changes applied or explicitly not applied with reason: target `88/93`, owner/emitter/reconstructable unchanged, no split/rename/new child, first-draft C++ applied.
- [x] Historical/stale assumptions, rejected alternatives, and negative evidence preserved: stale `95/95` gate, Browser/WinMain/file/global/no-owner rejections, no pointer/table route, no padding xrefs, and original-spelling/header caveats preserved.
- [x] Open questions resolved or documented with evidence-backed unresolved rationale: original method/member spelling, `const`, and header placement remain documented score caps.
- [x] Validators run and results recorded: five changed by-* validators all exit code `0`, `ok: 1`; target validator was rerun after correcting the constructor UID reference.
- [x] Supervisor-owned coverage-report/tracker text supplied or confirmed unchanged: exact coverage row supplied above; B004 did not edit any `-coverage-report.md`.
- [x] Remaining unapplied accepted items listed with exact blocker: none.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B004","command_id":"000000004165","destination_path":"executed-b-agent-research/B004/0002GM-ApplicationGetInstanceHandle-source-quality.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:17","uid":"0002GM"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
