** TARGET-REPORT-UID:0002GN **
** AUTHOR-AGENT-ID:B006 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# UID0002GN ApplicationGetMainWindowHandle Empty Emitter Source-Quality Report

## Finalized Report / Current Recommendation

- Current recommendation: convert [UID:0002GN][by-memory/0x004651d0-0x004651d7.ApplicationGetMainWindowHandle.md] from an empty emitter to a source-ready Application getter with formal first-draft C++.
- Final disposition: no split, rename, owner change, emitter change, or no-code marker is needed. The empty emitter is caused by stale `95/95`/final-layout gate wording, not by missing ownership or unsafe behavior.
- Required action after supervisor acceptance: update the target page and Application support pages at report-level detail, raise the target from `86/92` to `88/93`, keep `CANONICAL_OWNER:00000D`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:00000D`, and insert the exact formal C++ block below.
- Confidence: high for behavior, bounds, owner, emitter route, source placement, and C++ readiness; below final-audit `95+` because the full 78-caller semantic taxonomy and whole Application layout audit are not exhaustively written on the target page.

## Target

- Target UID: `0002GN`
- Target path: `by-memory/0x004651d0-0x004651d7.ApplicationGetMainWindowHandle.md`
- Source queue row: `auto-generated/-ag-research-tracker.md` / Files With Empty Emitters for [UID:0000HG] `by-file/Application.md` / `auto-generated/NexusTK/app/Application.cpp`.
- Current metadata: `COMPLETION:86`, `CONFIDENCE:92`, `CANONICAL_OWNER:00000D`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:00000D`, blank `RECONSTRUCTION_CPP CODE`.
- Current generated state: `auto-generated/NexusTK/app/Application.cpp` header `validator-command-id: 000000001094`, `validator-refreshed-at: 2026-06-29T19:21:38-04:00`, still contains `// UID:0002GN ... Completion:86 | Confidence:92 | Empty Emitter Marker`.

## Current Target State

The target page already documents the exact range, bytes, `mov eax,[ecx+0x828]; retn`, no callees, broad code-ref use, Application owner, Application emitter, and source-level `HWND` return type. The only material blocker left on the page is historical: its reconstruction notes say the C++ block is intentionally blank until final Application layout naming and a `95/95` audit.

That blocker conflicts with current `by-structure.md` guidance. The active code-entry rule allows C++ when a page is `RECONSTRUCTABLE:TRUE`, has a confirmed nonblank emitter route to a generated source file, and `(COMPLETION + CONFIDENCE) / 2 > 85`; `95+` is now a rare final-audit score, not a C++ eligibility gate. UID0002GN already has average `89`, owner [UID:00000D] Application, and emitter [UID:00000D] routing through [UID:0000HG] `Application.cpp`.

## Evidence Checked

- IDA MCP session: active IDB session `3fa0535f`, `idb_list` count `1`, active worker for `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, `pid` / `worker_pid` `16844`.
- MCP health: `server_health(database=3fa0535f)` returned `status:"ok"`, IDB path `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, module `NexusTK.exe`, imagebase `0x400000`, `auto_analysis_ready:true`, `hexrays_ready:true`, `strings_cache_ready:true`, strings cache size `2067`.
- MCP target facts: `lookup_funcs`, `get_bytes`, `decompile`, `analyze_function(include_asm=true)`, `xrefs_to(limit=1000)`, and `int_convert` against `3fa0535f`.
- MCP field writer/consumer facts: decompiled `0x004639d0` Application initialization, `0x004f5fb0` Application startup, and `0x00464a60` Application cleanup.
- Current docs checked: target page, `by-structure.md`, `by-class/Application.md`, `by-file/Application.md`, `by-memory/0x00463310-0x004674ed.ApplicationLifecycle.md`, `by-memory/0x004f5fb0-0x004f6490.ApplicationStartup.md`, `by-memory/0x00464a60-0x00464cc1.ApplicationCleanupResources.md`, `by-memory/0x004f5c80-0x004f5f17.WinMain.md`, `by-memory/0x005576a0-0x00557810.SurfaceDirectDrawRestoreMaintenance.md`, and `by-memory/0x0067ab1c-0x0067ab20.g_pApplication.md`.
- Generated inputs checked read-only: `auto-generated/-ag-memory-coverage.md`, `auto-generated/-ag-research-tracker.md`, and `auto-generated/NexusTK/app/Application.cpp`.
- Existing report search terms used: `0002GN`, `0x004651d0`, `ApplicationGetMainWindowHandle`, `GetMainWindowHandle`, `m_hMainWnd`, `Application+0x828`, and `0x828`.
- Relevant executed reports opened as leads: B004 `0002GM-ApplicationGetInstanceHandle-source-quality.md`, B005 `0002GO-ApplicationIsRunning-source-quality.md`, B007 `0002H7-ApplicationStartup-source-quality.md`, B010 `0002H1-ApplicationCleanupResources-empty-emitter-source-quality.md`, B009 `00019G-WinMain-source-quality.md`, B002 `00039R-SurfaceDirectDrawRestoreMaintenance-source-quality.md`, B001 `000294-g_pApplication-source-quality.md`, B001 `0002GJ-BaramAppOnActivate-empty-emitter-source-quality.md`, B008 `0002GK-BaramAppOnDeactivate-empty-emitter-source-quality.md`, and B002 `0002H0-0002JV-application-lifecycle-source-quality.md`.

## IDA MCP Facts

- `lookup_funcs(0x004651d0)` returns `sub_4651D0`, address `0x4651d0`, size `0x7`; `0x004651d7` is not a function; `0x004651e0` is the next function, `sub_4651E0`, size `0x7`.
- `get_bytes(0x004651c4, 28)` returns twelve `0xcc` bytes, target bytes `8b 81 28 08 00 00 c3`, then nine `0xcc` bytes. This confirms exact function bytes and padding on both sides.
- `decompile(0x004651d0)` returns `int __thiscall sub_4651D0(_DWORD *this) { return this[522]; /*0x4651d6*/ }`.
- `analyze_function(0x004651d0, include_asm=true)` returns assembly `4651d0 mov eax, [ecx+828h]` and `4651d6 retn`, no strings, no constants, no callees, one basic block, cyclomatic complexity `1`.
- `xrefs_to(0x004651d0, limit=1000)` returns `xref_count:78`, `more:false`, all code refs. Representative caller functions include `sub_465CB0`, `sub_46B520`, `sub_46BA90`, `sub_46F010`, `sub_470A00`, `_WinMain@16`, `sub_557470`, `sub_5576A0`, `sub_558840`, `sub_57B490`, `sub_5917D0`, and others.
- `int_convert` verifies `0x828` as decimal `2088`, byte form `28 08`; `522` as `0x20a`; and size `0x7` as decimal `7`. The decompiler's `this[522]` is dword indexing, so `522 * 4 == 2088 == 0x828`.
- `decompile(0x004639d0)` shows Application initialization creating/storing the main window: `v24 = (HWND)unk_69BE44(...)` at `0x464387`, `*(_DWORD *)(v15 + 2088) = v24` at `0x464393`, then `GetClientRect(v24, &rc)` and `ClientToScreen(*(HWND *)(v15 + 2088), &Point)`. Alternate window-mode branch stores the same offset at `0x46444c`.
- `decompile(0x004f5fb0)` shows startup using the field as a window handle: `ShowWindow(this[522], 5)`, `UpdateWindow(this[522])`, and `SetForegroundWindow(this[522])` at `0x4f61d6-0x4f61ee`.
- `decompile(0x00464a60)` shows cleanup using the same offset as `HWND`: `ShowWindow(*(HWND *)(this + 2088), 0)` at `0x464b5c`.

## Positive Evidence Summary

UID0002GN is a standalone one-block accessor. It has an exact 7-byte body, exact padding before and after, no callees, no internal side effects, and the return value is the dword at `Application+0x828`. Current MCP confirms `Application+0x828` is written by Application initialization from the main window creation result and consumed by Win32 `ShowWindow`, `UpdateWindow`, `SetForegroundWindow`, `GetClientRect`, and `ClientToScreen` paths. The source-facing return type `HWND` and member name `m_hMainWnd` are therefore not speculative decompiler polish; they are the best-supported source names already used by accepted Application startup/cleanup/BaramApp/ScreenPane reconstruction.

The generated output route is also already valid. The target is reconstructable, owner/emitter are [UID:00000D] Application, and [UID:00000D] routes to [UID:0000HG] `by-file/Application.md` / `app/Application.cpp`. Generated `Application.cpp` already contains sibling Application code that uses `m_hMainWnd` directly and uses `g_pApplication->GetMainWindowHandle()` from accepted BaramApp activation/deactivation C++; UID0002GN remaining as an empty marker is inconsistent with that source shape.

## Negative Evidence Summary

- No split is needed: MCP reports one function at `0x004651d0` with size `0x7`; `0x004651d7` is not a function; the surrounding bytes are `0xcc` padding.
- No no-code proof is appropriate: the body is not compiler-only support, not a thunk to another owner, not data, not third-party code, and not a mixed range.
- No owner change is supported: all hard field evidence is `this + 0x828` inside Application, with Application initialization writing the field and Application lifecycle/startup/cleanup consuming it. Consumers in WinMain, BaramApp, ScreenPane, browser/input/UI, and fatal-error paths use the accessor but do not own the Application field.
- No emitter change is supported: the current emitter route already reaches `auto-generated/NexusTK/app/Application.cpp`; the generated coverage row shows UID0002GN `emits` through `00000D` to that file, only with no generated C++ body.
- Global-window-handle ownership is rejected: the field is accessed through the Application object (`ecx+0x828` / `this+2088`), not a standalone global.
- Keeping the C++ blank for `95/95` is rejected as stale. Current `by-structure.md` explicitly supersedes old `90/90+` and `95/95` C++ gate language with the combined-score/emitter rule.

## Heuristic / Inference Reanalysis And Validation

- Field name: `m_hMainWnd` is inferred, not original-symbol proof, but it is validated by the main-window creation store at `Application+0x828`, Win32 window API consumers, current `by-class/Application.md` field table, accepted ApplicationStartup/CleanupResources formal C++, and accepted BaramApp activation/deactivation source shape. `m_mainWindowHandle` remains an acceptable descriptive alias in prose, but formal code should use the established `m_hMainWnd` spelling for local consistency.
- Method name: `Application::GetMainWindowHandle` is inferred source-facing name already used across current docs and generated Application C++; it is preferable to decompiler `sub_4651D0`, generic `GetWindowHandle`, or a free `ApplicationGetMainWindowHandle` because the body is a `thiscall` Application method and sibling methods use Application member style.
- Return type: `HWND` is directly validated by the writer and consumers. The decompiler `int` return type is a type-recovery artifact.
- Constness: `const` is recommended because the accessor only reads `m_hMainWnd`, has no callees, writes no memory, and matches the source shape of neighboring read-only Application getters such as `GetInstanceHandle`.
- Source placement: `app/Application.cpp` remains correct because this is an Application member and its emitter chain already reaches [UID:0000HG] Application. BaramApp and ScreenPane are consumers only.
- Wave2/Wave3 artifacts: none were used as evidence. Stale historical code-gate wording was identified and rejected under current `by-structure.md`.

## Ranked Ownership Analysis

### 1. Application / [UID:00000D]

- Evidence for: `thiscall` body reads `ecx+0x828`; Application initialization writes `this+2088` from the created main `HWND`; Application startup/cleanup use the same member; current class/file/lifecycle docs already list the method and field under Application.
- Evidence against: none material. The exact original member spelling is inferred, but the owner and type are strongly proven.
- Decision: keep `CANONICAL_OWNER:00000D`.

### 2. Application file / [UID:0000HG] as direct emitter route

- Evidence for: [UID:00000D] routes to [UID:0000HG] `by-file/Application.md`, generated memory coverage lists UID0002GN as emitted to `auto-generated/NexusTK/app/Application.cpp`, and Application.cpp already contains related Application getter/field consumers.
- Evidence against: none material. File-level broad Application page may remain an empty marker separately, but that does not block exact child emission.
- Decision: keep `EMITTER_UIDS:00000D`; no direct file-emitter override needed.

### 3. BaramApp, ScreenPane, WinMain, browser/input/UI/fatal-error consumers

- Evidence for: many xrefs and accepted reports consume the returned window handle.
- Evidence against: these are read/call consumers. They do not store `Application+0x828`, do not own the Application object layout, and do not define the accessor body.
- Decision: reject as owners or emitters for UID0002GN.

### 4. Standalone global/free helper

- Evidence for: some documentation and older reports use helper-like prose names such as `ApplicationGetMainWindowHandle`.
- Evidence against: the body is `__thiscall`, reads `ecx+0x828`, and the current source model has an Application class method.
- Decision: reject as source owner/shape. A free helper would be less faithful to the binary and current Application source.

## Source Placement

Recommended placement is `HWND Application::GetMainWindowHandle() const` in `app/Application.cpp`, near neighboring exact Application accessors such as `GetInstanceHandle`, `IsRunning`, `GetVersionMajor`, and `GetVersionMinor`. The declaration belongs with the Application class interface if/when class headers are materialized; the by-memory page should only carry the method definition represented by bytes `0x004651d0-0x004651d7`.

Rejected placements are BaramApp, ScreenPane, WinMain, DirectX/Surface, browser/input/UI modules, a standalone `WindowHandle.cpp`, or a global helper. Those modules depend on the Application window handle but do not own the field or method.

## Range / Split / Padding / Reclassification Analysis

No split, merge, or reclassification is required. UID0002GN covers exactly `0x004651d0-0x004651d7`. The preceding `0x004651c4-0x004651d0` bytes are twelve `0xcc` bytes after [UID:0002GM] `ApplicationGetInstanceHandle`, and the following `0x004651d7-0x004651e0` bytes are nine `0xcc` bytes before [UID:0002GO] `ApplicationIsRunning`. The target is reconstructable source code, not padding, data, a container, or compiler-only support.

## Function / Child Inventory

| Range / Item | UID / Path | Role | Reconstructable | Direct Parent | Score | Status |
| --- | --- | --- | --- | --- | --- | --- |
| `0x004651d0-0x004651d7` | `0002GN` / target page | Application main-window handle getter | TRUE | [UID:0000YR] ApplicationLifecycle / [UID:00000D] Application | current `86/92`, recommended `88/93` | Source-ready; add formal C++ |
| `0x004651c4-0x004651d0` | ignored padding | Alignment padding after UID0002GM | FALSE | ignored | n/a | Leave ignored |
| `0x004651d7-0x004651e0` | ignored padding | Alignment padding before UID0002GO | FALSE | ignored | n/a | Leave ignored |

## First-Draft C++ Recommendation

Eligible for draft C++: yes.

Exact formal `RECONSTRUCTION_CPP CODE` insertion text:

```cpp
HWND Application::GetMainWindowHandle() const
{
    return m_hMainWnd;
}
```

Reason it preserves behavior: the binary body loads `eax` from `[ecx+0x828]` and returns. `m_hMainWnd` is the current source-facing name for the Application field at `+0x828`, and returning it directly produces the same value with no side effects.

Reason it matches plausible original source: a small const accessor returning the cached main `HWND` is ordinary Visual C++ era Application-class code. It avoids decompiler names, avoids pointer-index syntax, and aligns with neighboring source-ready getters.

No-code proof: not applicable. The target is a normal source-level member function with a valid emitter route and sufficient evidence.

## Score And Metadata Recommendation

- Current: `COMPLETION:86`, `CONFIDENCE:92`, `CANONICAL_OWNER:00000D`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:00000D`, blank C++.
- Recommended: `COMPLETION:88`, `CONFIDENCE:93`, owner/reconstructable/emitter unchanged, formal C++ inserted.
- Completion rationale: raise to `88` because this pass resolves the stale C++ blocker, records current MCP session evidence, ties the getter to a proven field writer and Win32 consumers, and supplies implementation-ready C++ and support-doc destinations. Do not raise higher because the target page still should not pretend to exhaustively classify all 78 caller refs or the entire Application layout.
- Confidence rationale: raise to `93` because behavior, type, field, owner, emitter route, source placement, and formal C++ are all strongly corroborated. Do not raise to `95+`; current `by-structure.md` reserves that for near-final exhaustive audit.
- Metadata fields: keep `CANONICAL_OWNER:00000D`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:00000D`, and blank `EMITTER_POSITION_OPTIONAL`.

## Recommended Target Doc Changes

Target path: `by-memory/0x004651d0-0x004651d7.ApplicationGetMainWindowHandle.md`

Incorporate:

- Update score to `88/93`.
- Replace blank `RECONSTRUCTION_CPP CODE` with the formal `HWND Application::GetMainWindowHandle() const` block above.
- Update summary/score/reconstruction notes to state the old `95/95` blank-code gate is stale under current `by-structure.md`, and that current evidence supports source-ready first-draft C++.
- Add current MCP session `3fa0535f` evidence: health ok, exact `0x7` range, bytes/padding, decompile, one-block/no-callee state, `xrefs_to` count `78` with `more:false`, and `int_convert` results for `0x828`, `522`, and `0x7`.
- Add field provenance: `Application::Initialize` stores created main `HWND` into `Application+0x828`; startup shows/updates/foregrounds it; cleanup hides it.
- Preserve rejected alternatives: no split, no no-code marker, no owner/emitter change, no global/free helper ownership, and consumer modules rejected as direct owners.

## Recommended Support Doc Changes

Support path: `by-class/Application.md`

- Update the method list entry for UID0002GN to mark it source-ready first-draft C++ at `88/93`, returning `HWND Application::GetMainWindowHandle() const`.
- In field/source notes for `Application+0x828`, keep `m_hMainWnd` as the formal code spelling, mention `m_mainWindowHandle` only as a descriptive alias if retained, and add that Initialize writes the created main window while Startup, CleanupResources, WinMain, BaramApp activation/deactivation, and ScreenPane/Surface consumers use the handle.
- Preserve dependency boundaries: WinMain, BaramApp, ScreenPane/Surface, browser/input/UI/fatal-error paths are consumers, not owners of the Application field or getter.

Support path: `by-file/Application.md`

- Add UID0002GN to the source-ready Application accessor/helper list for `app/Application.cpp`, aligned with neighboring getter entries.
- Record that the old empty-emitter state was a stale code-gate issue, not an owner/emitter route defect.
- Confirm `Application.cpp` should emit the getter through the existing [UID:00000D] Application route.

Support path: `by-memory/0x00463310-0x004674ed.ApplicationLifecycle.md`

- Update the lifecycle child/accessor section so UID0002GN is source-ready at `88/93` with formal `HWND Application::GetMainWindowHandle() const`.
- Keep it as an exact child under ApplicationLifecycle; do not paste the child C++ into the aggregate except via normal child emission.
- Add or refresh the stale-code-gate note: old `95/95` C++ gate language should not block this exact accessor under the current combined-score/emitter rule.

Support pages already sufficient unless contradicted during callback:

- `by-memory/0x004f5fb0-0x004f6490.ApplicationStartup.md` already uses `m_hMainWnd` and proves startup consumers.
- `by-memory/0x00464a60-0x00464cc1.ApplicationCleanupResources.md` already uses `m_hMainWnd` and proves cleanup consumers.
- `by-memory/0x004f5c80-0x004f5f17.WinMain.md`, BaramApp activation/deactivation pages, `SurfaceDirectDrawRestoreMaintenance`, and `g_pApplication` already document consumer relationships; no edit is required unless the implementation pass finds stale contradictory wording.

## Claim And Incorporation Ledger

| Claim ID | Claim | Confidence | Evidence | Destination doc/section | Action | Verification state |
| --- | --- | --- | --- | --- | --- | --- |
| C01 | UID0002GN is exact `0x004651d0-0x004651d7`, size `0x7`, bytes `8b 81 28 08 00 00 c3`, surrounded by `0xcc` padding. | High | MCP `lookup_funcs`, `get_bytes`, `analyze_function` session `3fa0535f`. | Target IDA Evidence / Boundary section; ApplicationLifecycle child row. | incorporate | applied: target `2026-06-29 B006 Current MCP Source-Ready Evidence` records exact bytes/range/padding; lifecycle child row records same. |
| C02 | The body is a one-block no-callee getter: `mov eax,[ecx+828h]; retn`, decompiled as `return this[522]`. | High | MCP decompile/analyze_function. | Target behavior/evidence; by-file accessor note. | incorporate | applied: target evidence and by-file observed-behavior route note record one-block/no-callee getter. |
| C03 | `0x828` is `2088`, and decompiler `this[522]` is dword indexing for the same offset. | High | MCP `int_convert`; decompile math. | Target IDA Facts / score rationale. | incorporate | applied: target current MCP evidence and score rationale record `int_convert` proof; class/file/lifecycle support notes repeat `Application+0x828`. |
| C04 | `Application+0x828` is the main `HWND`, not an integer or arbitrary pointer. | High | Initialize store from window creation; Startup and Cleanup Win32 HWND consumers. | Target evidence; by-class field table; support notes. | incorporate | applied: target field provenance, by-class field table, by-file observed behavior, and lifecycle notes record Initialize writer plus Startup/Cleanup consumers. |
| C05 | Formal source name should be `HWND Application::GetMainWindowHandle() const` returning `m_hMainWnd`. | High | Current Application docs, accepted sibling getter style, field writer/consumers, no side effects. | Target C++ block; by-class method list; by-file source-ready list. | incorporate | applied: target formal `RECONSTRUCTION_CPP CODE` contains exact block; by-class/by-file/lifecycle mark source-ready getter. |
| C06 | Current owner/emitter metadata is correct: owner [UID:00000D], reconstructable TRUE, emitter [UID:00000D] routing to [UID:0000HG] Application.cpp. | High | Target metadata; generated coverage row; by-file/class docs. | Target metadata retained; by-file route note. | incorporate | applied: target metadata retained; by-file and class support notes document Application/Application.cpp route. |
| C07 | Empty emitter cause is stale `95/95`/layout-gate wording, not lack of eligibility. | High | Target reconstruction notes; current `by-structure.md` combined-score/emitter rule; generated empty marker. | Target score/reconstruction notes; by-file/ApplicationLifecycle notes. | incorporate | applied: target rejected alternatives/reconstruction notes and support change entries supersede stale `95/95` gate. |
| C08 | No split/range repair is needed. | High | Exact function size, non-function end, padding before/after. | Target range/split notes; lifecycle child table. | incorporate | applied: target rejected alternatives and lifecycle child row record exact range and padding. |
| C09 | No no-code marker is appropriate. | High | Normal source method, valid emitter route, current score average `89`, exact behavior. | Target reconstruction notes and checklist. | incorporate | applied: target formal C++ inserted and no-code alternative rejected in target and support change entries. |
| C10 | BaramApp, ScreenPane, WinMain, browser/input/UI, and fatal-error paths are consumers only. | High | 78 code refs; accepted reports; field ownership through Application object. | Target rejected alternatives; by-class dependency boundary. | incorporate | applied: target Owner/Emitter and Rejected Alternatives, by-class field table, and by-file route table preserve consumer-only status. |
| C11 | Recommended score is `88/93`, not `95+`. | Medium-high | Current evidence resolves C++ blocker but not complete 78-caller taxonomy or final whole-layout audit. | Target metadata and score rationale. | incorporate | applied: target metadata is `88/93`; score rationale explains below-`95+` caps. Validator command `000000001116` reported completion/confidence updates. |
| C12 | Generated `Application.cpp` currently remains stale for UID0002GN until validators run after accepted doc edits. | High | Generated header `000000001094` / `2026-06-29T19:21:38-04:00`; empty marker present. | Report checklist; implementation validator/generation expectations. | incorporate | applied: UID0002GN validators first refreshed generated `Application.cpp` to command `000000001121` / `2026-06-29T19:47:37-04:00`; final read-only freshness check shows current generated header `000000001127` / `2026-06-29T19:49:02-04:00`, with UID0002GN still emitting real getter code and no UID0002GN empty marker. |

## Open Questions With Attempted Resolution

- Exact original symbol spelling for `m_hMainWnd`: not proven by symbols, but current project source convention and repeated Application docs support `m_hMainWnd`. This does not block C++ because the name is the established source-facing reconstruction and validated by field use.
- Complete semantic classification of all 78 callers: not exhaustively written, but unnecessary for this exact getter's formal C++ because the body has no branches or dependency-specific behavior. It remains the reason not to score `95+`.
- Header declaration placement: final header shape is a broader generated-source concern. The method definition is still safe in the target C++ block because the by-file Application route owns source assembly.

## Validator And Generated-Output Expectations / Callback Results

Report-only pass: no validators were run and no leases were taken.

After supervisor acceptance and implementation callback, run scoped validators from `source-3/project-documentation` for each changed by-* file, likely:

- `python .\tools\validator.py --mode file --file by-memory/0x004651d0-0x004651d7.ApplicationGetMainWindowHandle.md --apply --queue-timeout 240 --wait-generated`
- `python .\tools\validator.py --mode file --file by-class/Application.md --apply --queue-timeout 240`
- `python .\tools\validator.py --mode file --file by-file/Application.md --apply --queue-timeout 240 --wait-generated`
- `python .\tools\validator.py --mode file --file by-memory/0x00463310-0x004674ed.ApplicationLifecycle.md --apply --queue-timeout 240`

Generated expectation: `auto-generated/NexusTK/app/Application.cpp` should refresh at or after the validator command metadata and should no longer contain the UID0002GN empty emitter marker. It should contain the formal getter definition or equivalent generated source for UID0002GN.

Callback validator results:

| Command | command_id | command_timestamp | Exit | ok | Notes |
| --- | --- | --- | ---: | ---: | --- |
| `python .\tools\validator.py --mode file --file by-memory/0x004651d0-0x004651d7.ApplicationGetMainWindowHandle.md --apply --queue-timeout 240 --wait-generated` | `000000001116` | `2026-06-29T19:46:53-04:00` | 0 | 1 | Updated UID0002GN completion/confidence, registry, generated coverage/tracker, and generated Application.cpp. Reported pre-existing missing UID reference warnings for `00039R` on the target page. |
| `python .\tools\validator.py --mode file --file by-class/Application.md --apply --queue-timeout 240` | `000000001119` | `2026-06-29T19:47:13-04:00` | 0 | 1 | Generated refresh deferred; projected stats updated. |
| `python .\tools\validator.py --mode file --file by-file/Application.md --apply --queue-timeout 240 --wait-generated` | `000000001120` | `2026-06-29T19:47:20-04:00` | 0 | 1 | Generated refresh completed. Reported pre-existing missing UID reference warnings for `0003OY` in `by-file/Application.md`. |
| `python .\tools\validator.py --mode file --file by-memory/0x00463310-0x004674ed.ApplicationLifecycle.md --apply --queue-timeout 240` | `000000001121` | `2026-06-29T19:47:37-04:00` | 0 | 1 | Generated refresh deferred but `auto-generated/NexusTK/app/Application.cpp` header refreshed to this command. |

Generated callback proof: UID0002GN validators first refreshed `auto-generated/NexusTK/app/Application.cpp` to `validator-command-id: 000000001121`, `validator-refreshed-at: 2026-06-29T19:47:37-04:00`; a later validator-owned foreground refresh advanced the current header to `validator-command-id: 000000001127`, `validator-refreshed-at: 2026-06-29T19:49:02-04:00`. Read-only `rg` shows UID0002GN at lines 314-318 with real `HWND Application::GetMainWindowHandle() const` code and no UID0002GN empty marker.

## Changed Files

- Created during report-only pass: `tools/leaser/Agents/Agent-B006/research/0002GN-ApplicationGetMainWindowHandle-empty-emitter-source-quality.md`
- Modified during callback: `by-memory/0x004651d0-0x004651d7.ApplicationGetMainWindowHandle.md`, `by-class/Application.md`, `by-file/Application.md`, `by-memory/0x00463310-0x004674ed.ApplicationLifecycle.md`, and this report checklist/ledger.
- Report execution: not run. Supervisor must run `tools/validator.py execute_report ... --apply` only after acceptance, callback implementation, and verification.

## Implementation Tracking Checklist

Initial report-only pass:

- [x] Supervisor validation required before implementation. Proof: supervisor callback accepted this report for implementation on 2026-06-29.
- [x] Target doc `by-memory/0x004651d0-0x004651d7.ApplicationGetMainWindowHandle.md`: raise score to `88/93`, keep owner/emitter/reconstructable metadata, add formal C++ getter, current MCP evidence, field writer/consumer proof, stale-gate correction, and rejected alternatives. Proof: target metadata/C++/evidence/score/reconstruction/change sections updated; validator `000000001116` ok:1.
- [x] Support doc `by-class/Application.md`: mark UID0002GN source-ready; record `HWND Application::GetMainWindowHandle() const`; keep `m_hMainWnd` as formal field spelling; preserve consumer-vs-owner boundaries. Proof: method list, field notes, inference map, and change entry updated; validator `000000001119` ok:1.
- [x] Support doc `by-file/Application.md`: add UID0002GN to source-ready Application accessor/helper list and note existing route to `app/Application.cpp`. Proof: observed behavior, route table, source-ready exception notes, migration/accessor list, and change entry updated; validator `000000001120` ok:1.
- [x] Support doc `by-memory/0x00463310-0x004674ed.ApplicationLifecycle.md`: add/refresh UID0002GN child/accessor row as source-ready at `88/93` and reject stale `95/95` code-gate blocking. Proof: lifecycle child table, covered-method entry, evidence note, reconstruction note, and change entry updated; validator `000000001121` ok:1.
- [x] Confirm no edits are required to Startup, CleanupResources, WinMain, BaramApp activation/deactivation, SurfaceDirectDrawRestoreMaintenance, or g_pApplication support pages unless callback reread finds contradictory stale wording. Proof: accepted report and implementation reread found those pages already sufficient or consumer-only; no contradictory stale wording requiring edits was found, so they were excluded-with-reason as already sufficient.
- [x] Claim And Incorporation Ledger updated with destination and report-only `proposed` verification state for every accepted claim. Proof: ledger now uses callback `applied` states with destination proof for C01-C12.
- [x] Metadata/score changes to apply: `86/92` to `88/93`; owner [UID:00000D], reconstructable TRUE, emitter [UID:00000D], and blank emitter position unchanged. Proof: target metadata updated; validator `000000001116` reported `completion_update 0002GN ... 88` and `confidence_update 0002GN ... 93`.
- [x] Score-limiting blocker researched to resolution: stale `95/95` blank-code gate rejected under current `by-structure.md`; remaining nonblocking caps documented. Proof: target rejected alternatives, score rationale, and reconstruction notes updated.
- [x] Owner/emitter/reconstructable changes to apply: none beyond retaining current values with stronger evidence. Proof: target metadata unchanged for owner/reconstructable/emitter; support docs document route.
- [x] Split/rename/new-child changes to apply: none; exact range and padding proof recorded. Proof: target and lifecycle docs record exact range and padding; no new files created.
- [x] Source-placement/name/type changes to apply: use `HWND`, `Application::GetMainWindowHandle`, `m_hMainWnd`, and `const`; reject global/free helper and consumer ownership routes. Proof: target formal C++, class/file/lifecycle support docs updated.
- [x] First-draft C++ to apply in formal block:

```cpp
HWND Application::GetMainWindowHandle() const
{
    return m_hMainWnd;
}
```

- [x] Third-party import directive: not applicable. Proof: target is ordinary source-level Application member code, not third-party static embed.
- [x] Historical/stale assumptions to preserve: target's old `95/95`/final-layout C++ blocker is historical and superseded; do not use it to keep UID0002GN blank. Proof: target/support docs record stale-gate rejection.
- [x] Open questions to document as nonblocking: exact original member spelling and exhaustive 78-caller taxonomy remain below-`95+` reasons only. Proof: target score/reconstruction notes and support docs carry these as caps, not blockers.
- [x] Validators to run after callback edits: scoped file validators listed above, with command_id, command_timestamp, exit code, ok count, and generated freshness reported. Proof: validator results table added above.
- [x] Generated output to verify after callback validators: `auto-generated/NexusTK/app/Application.cpp` header is equal/newer than validator metadata and UID0002GN empty marker is gone/replaced by real getter source. Proof: generated header is now `000000001127` / `2026-06-29T19:49:02-04:00` after a later validator-owned foreground refresh; UID0002GN emits real getter at lines 314-318.

Implementation callback pass:

- [x] Report accepted by supervisor for implementation. Proof: supervisor callback received 2026-06-29.
- [x] All accepted target/support doc details incorporated at report-level detail. Proof: target, Application class, Application file, and ApplicationLifecycle support docs updated.
- [x] Claim And Incorporation Ledger updated with callback verification state for every accepted claim. Proof: C01-C12 now `applied` with proof.
- [x] Metadata/score/owner/emitter/split/rename/C++ changes applied or explicitly excluded with reason. Proof: score/C++ applied; owner/emitter/reconstructable retained; split/rename excluded as not applicable by exact range proof.
- [x] Historical/stale assumptions, rejected alternatives, and negative evidence preserved. Proof: stale `95/95` gate, no-code, owner/emitter move, free-helper, consumer-owner, and split alternatives recorded in target/support docs.
- [x] Scoped validators run and results recorded. Proof: command IDs `000000001116`, `000000001119`, `000000001120`, and `000000001121` recorded above, all exit 0 / ok:1.
- [x] Generated `Application.cpp` freshness and UID0002GN empty-marker status recorded. Proof: generated header `000000001127` / `2026-06-29T19:49:02-04:00`; UID0002GN has real getter code and no UID0002GN empty marker.
- [x] Remaining unapplied accepted items listed with exact blocker, if any. Proof: no unapplied accepted items remain; non-target support pages were already sufficient and intentionally unchanged.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B006","command_id":"000000004165","destination_path":"executed-b-agent-research/B006/0002GN-ApplicationGetMainWindowHandle-empty-emitter-source-quality.md","details":"legacy registry reconstruction","event":"executed","source_path":"tools/leaser/Agents/Agent-B006/research/0002GN-ApplicationGetMainWindowHandle-empty-emitter-source-quality.md","timestamp":"2026-06-29T19:53:33","uid":"0002GN"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
