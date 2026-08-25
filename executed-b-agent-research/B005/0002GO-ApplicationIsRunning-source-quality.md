** TARGET-REPORT-UID:0002GO **
** AUTHOR-AGENT-ID:B005 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# 0002GO ApplicationIsRunning Source-Quality Research

## Final Recommendation

- Target: [UID:0002GO] `by-memory/0x004651e0-0x004651e7.ApplicationIsRunning.md`.
- Assignment: `B005-report-application-is-running-source-quality-0002GO-mcp-20260623`.
- Report-only status: no leases taken, no by-* docs edited, no generated/project-level files edited, no IDA DB/tool-state edits, and no `-coverage-report.md` edits.
- Recommendation: raise [UID:0002GO] from `84/92` to `88/93`, keep `CANONICAL_OWNER:00000D`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:00000D`, and keep `EMITTER_POSITION_OPTIONAL:` blank.
- C++ recommendation: add first-draft source-facing getter C++ under the active combined-score/emitter gate:

```cpp
bool Application::IsRunning() const
{
    return m_isRunning;
}
```

The behavior is exact. The field name `m_isRunning`, return type `bool`, and `const` qualifier remain inferred source-facing spelling, not recovered original header proof, so confidence should stay below `95`.

## Current Target State

The current target page already records strong local behavior, but it still carries stale no-code rationale from the old final-source gate:

- `COMPLETION:84`
- `CONFIDENCE:92`
- `CANONICAL_OWNER:00000D`
- `RECONSTRUCTABLE:TRUE`
- `EMITTER_UIDS:00000D`
- `EMITTER_POSITION_OPTIONAL:` blank
- Formal C++ block: blank.

Current useful target facts that should be retained:

- `Application::IsRunning` reads the one-byte running/active flag at `Application+0x838`.
- The exact range is `0x004651e0-0x004651e7`.
- The body is isolated by padding before and after.
- The only current direct callers are two routes inside `ScreenPane::HandleMessage`.
- The target is Application-owned and source-emitted through [UID:00000D] `Application` to [UID:0000HG] `Application` / `NexusTK/app/Application.cpp`.

Current stale/superseded target facts:

- The page says the reconstruction C++ block is intentionally blank because a prior one-line snippet used provisional `m_isRunning` while the page was below the old `95/95` final-source gate. Under current project policy, the eligible-code gate is nonblank emitter plus combined score greater than `85`, and this tiny accessor is now evidence-backed enough for first-draft C++.
- The page does not yet cite the current MCP session `261fb29b`, current PE hash, current exact writer addresses for `Application+0x838`, or the source-facing `m_isRunning` recommendation.

## MCP And Binary Evidence Checked

Current IDA MCP session evidence:

- MCP endpoint: `http://127.0.0.1:13337/mcp`.
- Active database/session used for this report: `261fb29b`.
- `server_health(database=261fb29b)` returned `status=ok`, IDB path `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, module `NexusTK.exe`, input path `C:\Users\admin\Desktop\Clone\NexusTK\NexusTK.exe`, imagebase `0x400000`, `auto_analysis_ready=true`, `hexrays_ready=true`, and `strings_cache_ready=true`.
- `idb_list` returned one active worker session `261fb29b`, input path `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, `is_analyzing=false`.
- SHA-256 for both `C:\Users\admin\Desktop\Clone\NexusTK\NexusTK.exe` and `E:\NTK\Resources\NexusTK\NexusTK.exe` is `9AEC210BBC5CE592176A21DD8E9D9FD8F250B8D9EA78237915A99BA8CFA9A632`.

Target function evidence:

- `lookup_funcs(0x004651e0)` reports `sub_4651E0`, start `0x4651e0`, size `0x7`.
- `lookup_funcs(0x004651e7)` reports not a function.
- `lookup_funcs(0x004651d7)` reports not a function.
- `lookup_funcs(0x004651f0)` reports next modeled function `sub_4651F0`, size `0xec`.
- `get_bytes(0x004651e0, 7)` returns `8a 81 38 08 00 00 c3`.
- `disasm(0x004651e0)` returns two instructions: `mov al, [ecx+838h]` and `retn`; IDA return type is `char`, argument is `_BYTE *this`.
- `decompile(0x004651e0)` returns `char __thiscall sub_4651E0(_BYTE *this) { return this[2104]; }`. `2104` is `0x838` and `2105`/`2106` are `0x839`/`0x83a`, verified with `python .\tools\int_convert.py` JSON batch.
- `callees(0x004651e0)` returns an empty callee set.
- `xrefs_to(0x004651e0)` returns exactly two code xrefs: `0x00556dab` and `0x00556e36`, both inside `sub_556D50` / `ScreenPane::HandleMessage`.
- `xref_query` reports two code xrefs to `0x004651e0`, zero data xrefs to `0x004651e0`, and zero xrefs of any type to exclusive end `0x004651e7`.
- `get_bytes(0x004651d7, 25)` shows nine `0xcc` bytes before the getter, the seven-byte getter body, and nine `0xcc` bytes after it.

Targeted byte-pattern checks:

- `find_bytes("8A 81 38 08 00 00 C3")` finds only `0x004651e0`.
- `find_bytes("8A ?? 38 08 00 00")` finds only `0x004651e0` for getter-shaped byte reads of `+0x838`.
- `find_bytes("C6 ?? 38 08 00 00 01")` finds `0x00463511` and `0x004669f5`.
- `find_bytes("C6 ?? 38 08 00 00 00")` finds `0x00466a9d`.
- `find_bytes("80 ?? 38 08 00 00 00")` and `find_bytes("80 ?? 38 08 00 00 01")` find no compare-pattern matches. This is a targeted negative check, not a claim that every possible register-transfer variant over the field has been globally excluded.

## Writer And Caller Evidence

The field lifecycle is now strong enough to name `Application+0x838` as source-facing `m_isRunning` with a spelling caveat:

- Constructor initialization:
  - `search_text("838h", 0x00463310-0x0046396e)` finds `0x00463511 mov byte ptr [edi+838h], 1` inside `Application__Constructor`.
  - Surrounding bytes at `0x00463500` show nearby Application layout stores, including the active message-handler field at `+0x844` before the `+0x838` byte initialization.
  - This corrects the support docs from a generic constructor field note to the exact current MCP-backed write address.
- `BaramApp::OnActivate` writer:
  - `decompile(0x004669c0)` shows the activation path guarded by `!this[2106]` (`Application/BaramApp +0x83a`) and, when `!unk_67A93C && dword_67A7CC`, writes `*(_BYTE *)(unk_67AB1C + 2104) = 1` at `0x004669f5`, calls `sub_557470(dword_67A7CC)`, and calls `ShowWindow(*(HWND *)(unk_67AB1C + 2088), 9)`.
  - `search_text("838h", 0x004669c0-0x00466b23)` confirms `0x004669f5 mov byte ptr [eax+838h], 1`.
- `BaramApp::OnDeactivate` writer:
  - `decompile(0x00466a70)` shows the deactivate path guarded by `!this[2106]`, clears `this[2105]` (`+0x839`), and, when `!unk_67A93C && dword_67A7CC`, writes `*(_BYTE *)(unk_67AB1C + 2104) = 0` at `0x00466a9d`, calls `ShowWindow(*(HWND *)(unk_67AB1C + 2088), 6)`, and calls `sub_5576A0(dword_67A7CC)`.
  - `search_text("838h", 0x004669c0-0x00466b23)` confirms `0x00466a9d mov byte ptr [eax+838h], 0`.
- ScreenPane caller route 1:
  - `decompile(0x00556d50)` shows message `1` calls `sub_4651E0((_BYTE *)unk_67AB1C)` at xref site `0x00556dab`; only when it returns true does the palette/visible-tile refresh branch enter its nested active-pane refresh work before scheduling another timer event.
- ScreenPane caller route 2:
  - The same decompile shows message `0` tests `*(_DWORD *)(this + 1280) == 1 && sub_4651E0((_BYTE *)unk_67AB1C) == 1 && !sub_464F40(v5)` before calling `sub_557140(this - 164)`, then schedules a timer. The xref to `Application::IsRunning` is `0x00556e36`; the combined running-plus-not-exit branch is represented around `0x00556e41`.
- `callees(0x00556d50)` includes both `sub_4651E0` and `sub_464F40`, proving the paired `Application::IsRunning()` / `Application::IsExitRequested()` caller relationship inside `ScreenPane::HandleMessage`.

## Heuristic And Inference Reanalysis

Claim: `Application+0x838` should be treated as source-facing `m_isRunning`.

- Confidence: strong, with original spelling unresolved.
- Direct evidence: the exact getter returns only the byte at `+0x838`; the constructor initializes that byte to `1`; activation writes it to `1`; deactivation writes it to `0`; and both ScreenPane caller routes consume it as a predicate before repaint/presentation work.
- Supporting documentation evidence: current target, class, file, lifecycle, constructor, BaramApp, and ScreenPane pages already describe this field as an Application running/active flag, but they do not yet carry the current session `261fb29b` writer/caller proof or a source-facing member name.
- Source-shape inference: `m_isRunning` is the most realistic member name in the current Application naming style. The class page already uses `m_isWow64` and `m_exitRequested`; a boolean getter named `Application::IsRunning()` naturally returns `m_isRunning`.
- Counter-evidence checked: IDA has no recovered original symbol for the field or getter; the write sites are tied to activation/deactivation and screen-path state, so `m_isActive` remains a plausible alternate. However, `m_isActive` is weaker because `BaramApp::OnDeactivate` also clears a separate `this+0x839` byte, and the documented method/caller name is `IsRunning`, not `IsActive`.
- Next verification if required: a full Application layout/header-source pass could decide exact original member spelling, `bool` versus project typedef spelling, and whether the getter was declared `const`.

Claim: first-draft C++ is ready.

- Confidence: strong.
- Evidence: the body is a seven-byte leaf, has no callees, has exact isolated padding, has no data xrefs to start, has no xrefs to end, has a confirmed owner/emitter route, and now has a defensible field name. The active code-entry rule is satisfied by nonblank emitter [UID:00000D] and recommended score `88/93`.
- Rejected no-code proof: the old no-code reason was tied to the superseded `95/95` final-source gate and provisional field-name concern. The remaining field spelling uncertainty is a confidence cap, not a blocker for this tiny getter.
- Exact behavior preserved: return the member byte directly. Do not add null checks, side effects, calls, or conversion logic. Do not model this as a free helper or ScreenPane method.

## Positive And Negative Evidence

Positive evidence:

- Exact IDA function at `0x004651e0`, size `0x7`.
- Exact body bytes `8a 81 38 08 00 00 c3`.
- Exact disassembly `mov al,[ecx+838h]; retn`.
- Hex-Rays returns `this[2104]`, matching `0x838` with `int_convert.py` verification.
- No callees.
- Exactly two code xrefs to the function start, both in one ScreenPane method.
- Zero data xrefs to the function start.
- Zero xrefs to the exclusive end.
- Nine `0xcc` bytes before and nine `0xcc` bytes after the target.
- Constructor, activation, and deactivation write the same byte using current MCP-backed addresses.
- Caller semantics match running-state gating: message `1` palette refresh requires running; message `0` refresh/presentation requires running and not exit-requested.

Negative evidence and rejected alternatives:

- ScreenPane ownership rejected. ScreenPane has the only direct callers, but they load `g_pApplication` / `unk_67AB1C` and call an Application accessor. ScreenPane consumes the state; it does not own the field or getter.
- BaramApp ownership rejected. BaramApp activation/deactivation writes the byte as lifecycle policy, but the storage is `g_pApplication + 0x838` and the getter is an Application method.
- ApplicationLifecycle aggregate ownership rejected as direct emitter. It is a range/context aggregate; exact child [UID:0002GO] and class/file docs own the source body.
- EventDispatcher, PlatformApi, MSGHandler, DirectX/Surface, and WindowProc ownership rejected. They either do not reference this getter or only depend on Application lifecycle state indirectly.
- Generic `m_statusFlag`, `byte_838`, or `m_appFlag838` rejected as final source names because current data flow gives a specific running/active predicate role.
- `m_isActive` remains a plausible alternate but is rejected as the recommended emitted field name because the documented getter is `IsRunning`, callers treat the return as `Application::IsRunning()`, and `+0x839` already carries a nearby BaramApp active-state byte.
- `BOOL` return rejected for the first draft because the binary returns one byte in `AL` from a one-byte field. `char` is accepted as decompiler ABI wording but rejected as the preferred source-facing getter type.
- Adding first-draft C++ to neighboring `ApplicationGetInstanceHandle` or `ApplicationGetMainWindowHandle` is out of scope for this target even though those pages also carry old no-code-gate language. They should receive separate review if the supervisor wants analogous getter C++ passes.

## Ranked Ownership And Source Placement

1. [UID:00000D] `Application` / [UID:0000HG] `Application` / `NexusTK/app/Application.cpp`: accepted. This class owns the singleton object layout, constructor initialization, lifecycle state, and getter. The recommended emitter remains [UID:00000D] with blank optional position.
2. [UID:0000YR] `ApplicationLifecycle`: context parent only. Keep child link and aggregate notes, but do not emit a separate aggregate body.
3. [UID:00000V] `BaramApp`: writer/context only. It toggles the Application field during activation/deactivation but should not own the getter.
4. [UID:0000CB]/[UID:0000NB] `ScreenPane`: consumer/caller only. It has the two direct caller routes and should document them as dependency evidence.
5. DirectX/Surface/PlatformApi/MSGHandler/EventDispatcher/WinMain: rejected as direct owners. No direct ownership of the Application field or getter body.

## Score And Metadata Recommendation

Recommended target metadata:

```text
*** COMPLETION:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:93 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:00000D | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:00000D | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
```

Completion rationale:

- Raise to `88` because current MCP-backed report detail covers exact range, raw bytes, disassembly, decompilation, no-callee state, exact code/data/end xref status, adjacent padding, constructor/Baram writer lifecycle, two ScreenPane caller routes, owner/source placement, rejected alternatives, and first-draft C++.
- Do not raise into `95+` because original member spelling, header declaration, return type spelling, and `const` qualifier are inferred rather than recovered.

Confidence rationale:

- Raise to `93` because current MCP session `261fb29b` directly proves the local behavior, boundaries, padding, xrefs, and field writes, and the Application owner route is coherent with current docs.
- Keep below `94/95` because `m_isRunning` versus a possible original `m_isActive`/`m_bRunning` spelling remains an inferred source-name decision and no original header/PDB evidence exists.

## Recommended Target And Support Doc Changes

| Path | Recommended change |
| --- | --- |
| `by-memory/0x004651e0-0x004651e7.ApplicationIsRunning.md` | Change score to `88/93`, keep owner/emitter metadata unchanged, add the first-draft C++ getter, replace old no-code-gate rationale, add current MCP session `261fb29b` evidence, PE SHA-256, exact bytes/disassembly/decompile, xref/no-xref state, padding, constructor/activation/deactivation writer addresses, two ScreenPane caller-route details, `m_isRunning` field recommendation, rejected alternatives, and unresolved spelling/return/const caveats. |
| `by-class/Application.md` | Add `Application+0x838` as source-facing `m_isRunning` in the field list/inference map, update the [UID:0002GO] method entry to source-ready `bool Application::IsRunning() const`, cite constructor write `0x00463511`, activation write `0x004669f5`, deactivation write `0x00466a9d`, and the two ScreenPane caller routes. Preserve `m_exitRequested` at `+0x83a` as distinct. |
| `by-file/Application.md` | Add [UID:0002GO] as the second source-ready tiny Application getter alongside [UID:0002H4], update lifecycle/source-placement text so `Application::IsRunning()` no longer shares the old blank-C++ status, and preserve larger lifecycle no-code blockers as target-specific. |
| `by-memory/0x00463310-0x004674ed.ApplicationLifecycle.md` | Add/refresh a row or note for [UID:0002GO] at `88/93`, first-draft C++ ready as `bool Application::IsRunning() const { return m_isRunning; }`, with current MCP proof of `+0x838` constructor/Baram writer lifecycle, two ScreenPane callers, and adjacent padding. Keep aggregate non-emitting/no-code. |
| `by-memory/0x00463310-0x0046396e.ApplicationConstructor.md` | Add exact MCP-backed constructor write `0x00463511 mov byte ptr [edi+838h], 1` for `m_isRunning` / `Application+0x838`, distinct from exit flag `+0x83a`, and cross-link [UID:0002GO]. Score can remain unchanged unless the supervisor wants local scoring review. |
| `by-memory/0x004669c0-0x00466a69.BaramAppOnActivate.md` | Refresh current MCP session evidence that activation writes `g_pApplication+0x838 = 1` at `0x004669f5` before ScreenPane restore/show work; state this is Application field writer evidence, not BaramApp ownership of the getter. |
| `by-memory/0x00466a70-0x00466b23.BaramAppOnDeactivate.md` | Refresh current MCP session evidence that deactivation writes `g_pApplication+0x838 = 0` at `0x00466a9d`, after clearing separate `this+0x839`, before `ShowWindow(...,6)` and ScreenPane restore; state this is Application field writer evidence, not BaramApp ownership of the getter. |
| `by-memory/0x00556910-0x00557132.ScreenPane.md` | Add the two consumer routes: message `1` palette branch calls [UID:0002GO] at `0x00556dab`, and message `0` refresh/presentation branch calls [UID:0002GO] at `0x00556e36` and [UID:0002H4] around `0x00556e41` before `0x00557140`. Preserve ScreenPane as caller/consumer only. |
| `by-file/ScreenPane.md` | If implementing at full support-doc detail, add a concise evidence note under ScreenPane message handling that the only direct [UID:0002GO] callers are the two `ScreenPane::HandleMessage` branches and that this is an Application dependency, not ScreenPane ownership. |
| `by-class/ScreenPane.md` | If implementing at full support-doc detail, expand the `HandleMessage` method row to mention the two Application running-state gates and the paired exit-request gate in the message `0` path. No ScreenPane score/owner change recommended. |

No support change is recommended for `by-memory/0x004651c0-0x004651c4.ApplicationGetInstanceHandle.md` or `by-memory/0x004651d0-0x004651d7.ApplicationGetMainWindowHandle.md` during this callback unless the supervisor explicitly broadens scope; they are neighboring old-gate getter pages, not evidence owners for `+0x838`.

## Supervisor-Owned Coverage Text

Do not edit `by-memory/-coverage-report.md` as B005. If accepted, replace the current [UID:0002GO] row with:

```text
    - [UID:0002GO][0x004651e0-0x004651e7.ApplicationIsRunning](by-memory/0x004651e0-0x004651e7.ApplicationIsRunning.md) 0x004651e0-0x004651e7 | class method | ApplicationIsRunning : reconstructable : 88% : very-strong : IDA MCP session `261fb29b` confirms exact 0x7 Application running-state getter bytes `8a 81 38 08 00 00 c3`, `mov al,[ecx+0x838]; retn`, Hex-Rays `this[2104]` / `Application+0x838` (verified with `int_convert.py`), no callees, exactly two ScreenPane `HandleMessage` code refs at `0x00556dab` and `0x00556e36`, zero data xrefs to the start, zero xrefs to the end, constructor write `0x00463511`, BaramApp activation/deactivation writes `0x004669f5`/`0x00466a9d`, adjacent `0xcc` padding, `m_isRunning` field role, and first-draft C++ readiness.
```

## Expected Validators After Accepted Implementation

Run scoped validators only for changed by-* docs from `E:\NTK\GhidraBridge\source-3\project-documentation`:

> Executable block R001 was removed from this report and preserved verbatim in [0002GO-ApplicationIsRunning-source-quality-removed.md](0002GO-ApplicationIsRunning-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

If the supervisor narrows support synchronization and a listed file is not touched because it already contains the accepted facts at same-or-greater detail, record that in the implementation checklist and skip that file's validator.

## Implementation Tracking Checklist

Report-only pass:

- [x] Read current `Agent-B005/goal.md`: assignment `B005-report-application-is-running-source-quality-0002GO-mcp-20260623`, target [UID:0002GO], report-only, MCP mandatory.
- [x] Used project-level `ntk-b-agent-workflow` skill and read `SKILL.md` plus the B-agent research workflow reference.
- [x] No by-* docs, generated/project-level files, IDA DB/tool state, unrelated docs, or `-coverage-report.md` files edited during report-only research.
- [x] Current target state recorded, including existing `84/92`, Application owner/emitter route, blank C++ block, and stale old-gate no-code rationale.
- [x] Current MCP evidence recorded from session `261fb29b`: health, IDB path, function/range, bytes, disassembly, decompilation, callers/xrefs, no-callee state, no data/end xrefs, padding, writer addresses, and caller semantics.
- [x] `int_convert.py` used for decimal/hex field-offset conversion (`2104`/`0x838`, `2105`/`0x839`, `2106`/`0x83a`).
- [x] Heuristic/source-facing field analysis completed: recommend `m_isRunning`, reject generic names and `m_isActive` as the primary emitted name, preserve original-spelling caveat.
- [x] Ownership/source-placement ranking completed: Application accepted; ApplicationLifecycle context-only; BaramApp and ScreenPane rejected as direct owners; DirectX/Surface/PlatformApi/MSGHandler/EventDispatcher/WinMain rejected.
- [x] Score/metadata recommendation recorded: `88/93`, owner/emitter unchanged, reconstructable true.
- [x] First-draft C++ recommendation recorded.
- [x] Supervisor-owned coverage replacement row supplied; B005 did not edit coverage.

Accepted implementation callback items:

- [x] `by-memory/0x004651e0-0x004651e7.ApplicationIsRunning.md`: updated metadata to `88/93`, kept `CANONICAL_OWNER:00000D`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:00000D`, and blank emitter position, added first-draft C++ `bool Application::IsRunning() const { return m_isRunning; }`, replaced stale no-code wording, and incorporated current MCP session `261fb29b` evidence at report-level detail: PE hash, exact bytes/disassembly/decompile, zero-callee state, start/end/data xref state, padding, constructor/activation/deactivation writer addresses, two ScreenPane caller routes, `m_isRunning` field recommendation, rejected alternatives, and spelling/return/const caveats. Validator: `python .\tools\validator.py --mode file --file by-memory\0x004651e0-0x004651e7.ApplicationIsRunning.md --apply --queue-timeout 240` exited `0`, `ok: 1`; validator applied the target metadata/C++ derived updates and later compact validation passed.
- [x] `by-class/Application.md`: added/retained `m_isRunning` / `Application+0x838` field note and source-ready [UID:0002GO] method entry with constructor writer `0x00463511`, activation writer `0x004669f5`, deactivation writer `0x00466a9d`, two ScreenPane caller routes, and `m_exitRequested` at `+0x83a` preserved as distinct. After B004 edited overlapping Application content for [UID:0002GM], this file was reread and merged without dropping B004's `m_hInstance`/`GetInstanceHandle` additions. Validator: `python .\tools\validator.py --mode file --file by-class\Application.md --apply --queue-timeout 240` exited `0`, `ok: 1`.
- [x] `by-file/Application.md`: added/retained [UID:0002GO] as a source-ready tiny Application getter exception/source route alongside [UID:0002H4], preserving larger lifecycle no-code blockers and B004's [UID:0002GM] source-ready getter detail. Validator: `python .\tools\validator.py --mode file --file by-file\Application.md --apply --queue-timeout 240` exited `0`, `ok: 1`.
- [x] `by-memory/0x00463310-0x004674ed.ApplicationLifecycle.md`: added/retained [UID:0002GO] `88/93` score/source-ready note while keeping the aggregate non-emitting, with `+0x838` constructor/Baram writer lifecycle, two ScreenPane callers, and current MCP proof. B004's overlapping [UID:0002GM] lifecycle support detail was preserved after reread/merge. Validator: `python .\tools\validator.py --mode file --file by-memory\0x00463310-0x004674ed.ApplicationLifecycle.md --apply --queue-timeout 240` exited `0`, `ok: 1`.
- [x] `by-memory/0x00463310-0x0046396e.ApplicationConstructor.md`: added/retained exact constructor write `0x00463511 mov byte ptr [edi+838h], 1` for `m_isRunning` / `Application+0x838`, distinct from exit flag `+0x83a`, and cross-linked [UID:0002GO]. B004's overlapping [UID:0002GM] `m_hInstance` constructor evidence was preserved after reread/merge. Validator: `python .\tools\validator.py --mode file --file by-memory\0x00463310-0x0046396e.ApplicationConstructor.md --apply --queue-timeout 240` exited `0`, `ok: 1`.
- [x] `by-memory/0x004669c0-0x00466a69.BaramAppOnActivate.md`: refreshed activation writer evidence `0x004669f5` as `g_pApplication+0x838 = 1` before ScreenPane restore/show work, explicitly as Application field writer evidence and not BaramApp ownership of the getter. Validator: `python .\tools\validator.py --mode file --file by-memory\0x004669c0-0x00466a69.BaramAppOnActivate.md --apply --queue-timeout 240` exited `0`, `ok: 1`.
- [x] `by-memory/0x00466a70-0x00466b23.BaramAppOnDeactivate.md`: refreshed deactivation writer evidence `0x00466a9d` as `g_pApplication+0x838 = 0`, preserved the distinct `this+0x839` clear caveat, and kept this as Application field writer evidence rather than BaramApp ownership. Validator: `python .\tools\validator.py --mode file --file by-memory\0x00466a70-0x00466b23.BaramAppOnDeactivate.md --apply --queue-timeout 240` exited `0`, `ok: 1`.
- [x] `by-memory/0x00556910-0x00557132.ScreenPane.md`: added the two [UID:0002GO] consumer routes and preserved ScreenPane consumer-only status: message `1` palette branch call at `0x00556dab`; message `0` refresh/presentation branch call at `0x00556e36`, paired with [UID:0002H4] around `0x00556e41` before `0x00557140`. Validator: `python .\tools\validator.py --mode file --file by-memory\0x00556910-0x00557132.ScreenPane.md --apply --queue-timeout 240` exited `0`, `ok: 1`.
- [x] `by-file/ScreenPane.md`: not touched. Proof: accepted implementation scope made ScreenPane class/file optional; required route-level evidence is now present in `by-memory/0x00556910-0x00557132.ScreenPane.md`, and no stale [UID:0002GO] ownership or `Application+0x838` field-name claim required correction in the broad file page.
- [x] `by-class/ScreenPane.md`: not touched. Proof: accepted implementation scope made ScreenPane class/file optional; the class page did not contain a conflicting direct-owner claim for [UID:0002GO], and the required caller-route specifics are carried by the ScreenPane by-memory page that owns the relevant message-handler evidence.
- [x] Preserved rejected alternatives and caveats in the target/support implementation: original member spelling, return-type spelling, `const` qualifier, `m_isActive` alternate, neighboring getter C++ out-of-scope, ScreenPane/BaramApp/ApplicationLifecycle direct-owner rejections, and source-facing `m_isRunning` as a confidence-capped recommendation.
- [x] Did not edit any `-coverage-report.md`; supervisor-owned replacement row remains supplied above for supervisor application.
- [x] Ran scoped validators for every changed by-* doc and recorded command, exit code, and `ok` count above. Validator side effects were the expected derived outputs (`project-level/-auto-completion-stats.md`, `validator.ini`, and unchanged auto-generated coverage reports); no generated/project-level file was manually edited.
- [x] Lease/overlap control handled: after the supervisor overlap override, B004 held active leases on `by-class/Application.md`, `by-file/Application.md`, `by-memory/0x00463310-0x004674ed.ApplicationLifecycle.md`, and `by-memory/0x00463310-0x0046396e.ApplicationConstructor.md` until `2026-06-23T12:18:38Z`; B005 waited, rechecked that no active leases remained at `2026-06-23T08:18:59-04:00`, reread the latest contents immediately before validating/merging, preserved B004's [UID:0002GM] edits, and released B005 leases successfully after validation. No `PAUSED_LEASE_CONFLICT` blocker remained.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B005","command_id":"000000004165","destination_path":"executed-b-agent-research/B005/0002GO-ApplicationIsRunning-source-quality.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:17","uid":"0002GO"} -->
<!-- {"agent":"B005","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 0002GO-ApplicationIsRunning-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B005/0002GO-ApplicationIsRunning-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"0002GO"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
