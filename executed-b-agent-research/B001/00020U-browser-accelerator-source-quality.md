** TARGET-REPORT-UID:00020U **
** AUTHOR-AGENT-ID:B001 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# 00020U BrowserWindow Accelerator Source-Quality Research

Assignment: `B001-goal2-browser-accelerator-source-quality-00020U-20260616`  
Target: `[UID:00020U] by-memory/0x0046a510-0x0046a617.BrowserWindowAcceleratorTranslateMessage.md`  
Agent: B001  
Date: 2026-06-16

## Final Recommendation

Raise the target page from `82/88` to `85/90`, keep `CANONICAL_OWNER:0000HV`, keep `EMITTER_UIDS:0000HV`, keep `RECONSTRUCTABLE:TRUE`, and do not split the range.

Recommended source-facing classification:

```text
static int __cdecl BrowserWindowTranslateAcceleratorMessage(MSG *message)
```

This is a distinct BrowserWindow-specific accelerator helper, not a thunk and not the active Application message-loop route. It is duplicate-like in behavior compared with `0x0046c550`, but it reads a different owner/global path:

- `0x0046a510`: `g_pActiveBrowserWindow + 0x18`
- `0x0046c550`: `g_activeBrowserControlPane + 0x120`

The active routed helper is `0x0046c550` (`BrowserControlPaneTranslateAcceleratorMessage`), called from the Application message loop at `0x00464d88` in `sub_464CD0`. The target `0x0046a510` has no direct caller, no loaded-segment absolute pointer hit, no WndProc registration hit, and no vtable/table route found. That no-xref state has now been investigated rather than merely restated.

Final C++ should remain blank unless the supervisor accepts retained no-xref helper emission as a file-static helper, or additional evidence identifies the original caller/table route. The no-caller issue is now classified and non-blocking for `85/90` metadata quality, but it remains material for final C++ source emission policy.

## Evidence Checked

Primary docs reviewed:

- `tools/leaser/Agents/Supervisor.md`
- `tools/leaser/Agents/Agent-B001/goal.md`
- `tools/leaser/Agents/Supervisor_notes.md`
- `by-structure.md`
- `tools/leaser/Agents/Agent-B001/inference_research.md`
- `by-memory/0x0046a510-0x0046a617.BrowserWindowAcceleratorTranslateMessage.md`
- `by-memory/0x0046b520-0x0046cfe0.BrowserControlPaneCore.md`
- `by-memory/0x0046a630-0x0046a6ea.BrowserWindowHostWndProc.md`
- `by-memory/0x0046a760-0x0046a855.BrowserRawWindowProcClone.md`
- `by-memory/0x00469640-0x0046a39c.BrowserWindowCore.md`
- `by-memory/0x006131b4-0x006139df.BrowserVtablesAndStrings.md`
- `by-class/BrowserWindow.md`
- `by-class/BrowserControlPane.md`
- `by-class/BrowserPane.md`
- `by-file/Browser.md`
- `by-global/g_pActiveBrowserWindow.md`
- `by-global/g_activeBrowserControlPane.md`
- `by-global/g_activeBrowserPane.md`
- GUID support pages around `0x00631580-0x00631660`

Generated/source comparison reviewed:

- `source-3/simroot_v2/recovered/HandleAcceleratorMessage_0046C550.cpp`
- `source-3/simroot_v2/recovered/HandleAcceleratorMessage_0046C550.cpp.meta_wave3`
- `source-3/simroot_v2/recovered/HandleAcceleratorMessage_0046C550.cpp.meta_old`
- `source-3/simroot_v2/class_Application.cpp`
- `auto-generated/-ag-memory-coverage.md`
- `project-level/-auto-completion-stats.md`

IDA/MCP read-only evidence was gathered from a fresh session on `NexusTK.exe.i64`:

- `lookup_funcs`
- `analyze_function`
- `func_profile`
- `xref_query`
- `xrefs_to`
- `find_bytes`
- `decompile_function`
- `analyze_component`

No IDA write actions were used. No source files, by-memory pages, generated reports, or coverage reports were edited.

## Function Behavior

Fresh IDA analysis confirms the target is a real function:

```text
0x0046a510 sub_46A510
size: 0x107
prototype observed by func_profile: int __cdecl(int)
basic blocks: 23
cyclomatic complexity: 9
external caller count: 0
```

The decompiled behavior is stable across the current target page and the fresh MCP session:

1. If `g_pActiveBrowserWindow` is null, return `1`.
2. Read an active object source from `[g_pActiveBrowserWindow + 0x18]`.
3. Query that object for `IID_IOleInPlaceActiveObject` at `0x006315c0`.
4. If `QueryInterface` fails or returns no interface, return `1`.
5. For key messages `WM_KEYDOWN`, `WM_KEYUP`, `WM_SYSKEYDOWN`, and `WM_SYSKEYUP`:
   - `Ctrl+N` without Alt returns `1` after releasing the interface.
   - `Escape` calls the BrowserPane activation/close helper through `g_activeBrowserPane`, returns `0`, and releases the interface.
   - Otherwise calls `IOleInPlaceActiveObject::TranslateAccelerator(message)` through vtable offset `+0x14`, releases the interface, and returns that result.
6. Non-key messages fall through to the default return path.

The inferred source signature should use `MSG *`, not a raw `int`, because the helper reads `message->message` at `+4`, `message->wParam` at `+8`, and passes the original pointer to `TranslateAccelerator`.

Return convention:

- `0` means consumed/handled.
- Nonzero means caller should continue normal dispatch.
- The helper forwards the COM `TranslateAccelerator` result directly, so source can preserve the `int`/HRESULT-like convention rather than forcing `bool`.

## Relationship To 0x0046c550

`0x0046c550` is the related active helper, currently named `BrowserControlPaneTranslateAcceleratorMessage` in IDA. It is not the same function and not merely a renamed duplicate:

```text
0x0046a510 source path:
  g_pActiveBrowserWindow -> +0x18 -> QueryInterface(IID_IOleInPlaceActiveObject)

0x0046c550 source path:
  g_activeBrowserControlPane -> +0x120 -> QueryInterface(IID_IOleInPlaceActiveObject)
```

The two helpers share the same accelerator policy:

- Handle `Ctrl+N` specially.
- Handle `Escape` through `g_activeBrowserPane`.
- Otherwise call `IOleInPlaceActiveObject::TranslateAccelerator`.
- Release the queried interface.

The important routing difference is that `0x0046c550` has the live Application message-loop caller:

```text
0x00464d88 in sub_464CD0 -> BrowserControlPaneTranslateAcceleratorMessage(&Msg)
```

`sub_464CD0` checks `g_activeBrowserControlPane` before calling the helper. If the helper returns nonzero, the message continues through translation/dispatch. That makes `0x0046c550` the active route for the Application pump.

Therefore `00020U` should be classified as:

```text
distinct BrowserWindow-specific retained/static accelerator helper
```

It should not be merged into the `0x0046c550` documentation, and it should not be treated as a thunk.

## Caller, Reachability, And No-Xref Investigation

The no-xref state was checked beyond direct callers.

Evidence checked:

- `xrefs_to 0x0046a510`: no direct code or data xrefs.
- `func_profile 0x0046a510`: caller count `0`.
- Loaded-segment absolute pointer search for little-endian `0x0046a510`: no hits.
- Application message loop `sub_464CD0`: calls `0x0046c550`, not `0x0046a510`.
- BrowserWindow constructor `0x00469640`: registers `sub_46A630` as `WNDCLASSA.lpfnWndProc`, publishes `g_pActiveBrowserWindow`, but does not reference `0x0046a510`.
- Proven BrowserWindow WndProc `0x0046a630`: data xref from constructor at `0x00469758` / `0x0046975e`; does not call `0x0046a510`.
- Adjacent raw WndProc-like clone `0x0046a760`: no direct xrefs or pointer hits; no route to `0x0046a510`.
- BrowserWindow vtable slices around `0x00613200` and related Browser vtable/string page: constructor/destructor-style refs were observed, but no function pointer/table route to `0x0046a510`.
- Local switch targets at `0x0046a5ab` and `0x0046a5e3` have local code/data xrefs from the function and switch table around `0x0046a618`; these do not represent external reachability.

The direct broad instruction query timed out in the MCP session, but the practical reachability question was covered through IDA's xref engine, function profiles, decompilation of the known neighboring dispatch functions, and loaded-segment absolute pointer scans.

Best current conclusion: `0x0046a510` is retained code or an unobserved/static BrowserWindow-era route that is not referenced by the recovered active pump path. No source-quality score should continue to list "no direct xrefs" as an uninvestigated blocker.

## Ownership, Emitter, And Source Placement

Keep:

```text
CANONICAL_OWNER:0000HV
EMITTER_UIDS:0000HV
```

Reasoning:

- The function is `__cdecl`, has no `this`, and is not a proven BrowserWindow class method.
- It is semantically BrowserWindow-specific because it reads `g_pActiveBrowserWindow + 0x18`.
- The current Browser source root `0000HV` already owns the browser globals, BrowserWindow/BrowserControlPane grouping, and static helper routing.
- The narrow class page `BrowserWindow.md` should document the helper as BrowserWindow-specific, but direct canonical ownership should stay with the Browser file/root unless the supervisor later creates a specific static-helper owner for BrowserWindow file scope.

Source placement:

```text
auto-generated/NexusTK/browser/Browser.cpp
```

This matches the existing Browser docs and auto-generated route. If a later source split creates `BrowserWindow.cpp`, this helper should travel with the BrowserWindow implementation, but the current evidence does not require a split.

## Split / No-Split Boundary

Keep the target range as one function:

```text
0x0046a510-0x0046a617
```

The bytes immediately after the function include local switch data/padding before the next documented function boundary. The target helper itself is a complete body, not a stub:

- Entry logic
- QueryInterface path
- key-message switch
- Ctrl/Alt state checks
- Escape BrowserPane path
- TranslateAccelerator call
- Release cleanup
- return paths

No child helper or internal split is recommended.

## Generated / Compiler Name Reanalysis

Generated/compiler-facing names observed:

- `sub_46A510`: current unresolved IDA name for target.
- `BrowserControlPaneTranslateAcceleratorMessage`: current IDA name for `0x0046c550`.
- `HandleAcceleratorMessage_0046C550.cpp`: generated Wave3 source artifact for the BrowserControlPane route.

Recommended source-facing name for `00020U`:

```text
BrowserWindowTranslateAcceleratorMessage
```

Rationale:

- Mirrors the active sibling `BrowserControlPaneTranslateAcceleratorMessage`.
- Puts the source object first: `BrowserWindow`.
- Uses the COM verb/name `TranslateAccelerator`, matching `IOleInPlaceActiveObject::TranslateAccelerator`.
- Avoids implying this helper translates all BrowserWindow accelerators in isolation; it is specifically message-based.

The current page title `BrowserWindowAcceleratorTranslateMessage` is defensible but less source-like. A future rename is recommended if the supervisor is already changing target metadata/text. If page renaming is too much churn, keep the filename/title and document the inferred source-facing helper name inside the page.

## Type, Global, Protocol, And Helper Naming

Recommended source-facing names:

```text
unk_67AB94 / dword_67AB94 -> g_pActiveBrowserWindow
MEMORY[0x67AB84] / dword_67AB84 -> g_activeBrowserPane
unk_6315C0 / 0x006315c0 -> IID_IOleInPlaceActiveObject
sub_49DF20 -> BrowserPane::ActivateItem / BrowserPane active-item helper
```

Recommended BrowserWindow field wording:

```text
[g_pActiveBrowserWindow + 0x18] -> active browser OLE/web object source
```

The exact field name is still not binary-proven. If a source-style name is needed in explanatory text, use one of:

```text
m_oleObject
m_webBrowserOleObject
m_activeObjectSource
```

`m_activeObjectSource` is the safest descriptive documentation term because the helper immediately queries the field for `IID_IOleInPlaceActiveObject`.

## Heuristic / Inference Reanalysis And Validation

The prior unresolved source-quality issues were rechecked as follows:

| Issue | Reanalysis | Current Direction |
|---|---|---|
| Generated/compiler name | IDA still has `sub_46A510`; no original symbol found. Sibling route has stable generated/IDA name around BrowserControlPane accelerator translation. | Use inferred source-facing name `BrowserWindowTranslateAcceleratorMessage` with confidence noted as inferred, not original-symbol proof. |
| Source-facing helper name | Behavior is exactly a BrowserWindow-specific `IOleInPlaceActiveObject::TranslateAccelerator` message helper. | Prefer `BrowserWindowTranslateAcceleratorMessage`. Existing title can remain if avoiding page rename. |
| Declaration / return convention | `func_profile` reports `int __cdecl(int)`; field offsets and COM call prove `MSG *message`. Return values match handled/continue dispatch convention and COM forwarding. | Document as `static int __cdecl BrowserWindowTranslateAcceleratorMessage(MSG *message)`. |
| Caller / reachability | Direct xrefs, function profile, pointer search, app loop, BrowserWindow WndProc, raw WndProc clone, constructor registration, and vtable neighborhood were checked. No route found. | No-xref is now a researched retained-helper classification, not an unresolved blocker for metadata score. |
| Source placement | Browser docs route BrowserWindow helpers/globals to Browser source root; no stronger split proof. | Keep `0000HV` owner/emitter and `Browser.cpp` route. |
| Ownership / emitter routing | Function has no `this`, no vtable slot, and no proven class method route, but semantically reads BrowserWindow active global. | Keep `CANONICAL_OWNER:0000HV`; document BrowserWindow-specific static helper on class page. |
| Split / no-split | Full function body present; local switch table/padding begins after target end. No child helper found. | No split. Keep `0x0046a510-0x0046a617`. |
| Type / global / protocol naming | Globals and GUID are already supported by global/GUID pages. | Use `g_pActiveBrowserWindow`, `g_activeBrowserPane`, `IID_IOleInPlaceActiveObject`, `BrowserPane::ActivateItem`/active item helper. |
| Duplicate / alternate owner vs `0x0046c550` | The helpers share policy but read different global/field paths. `0x0046c550` is called from the Application pump; target is not. | Distinct helper; `0x0046c550` is active BrowserControlPane route; target is retained BrowserWindow analogue. |
| Final C++ blocker | Behavior and source shape are reconstructable. Missing caller remains unresolved for source emission policy. | Keep C++ blank unless retained no-xref helper emission is accepted or a caller/table route is found. |

Why `85/90` is defensible:

- Behavior, boundaries, global names, GUID, signature, return convention, and sibling-helper relationship are now supported by direct docs plus fresh IDA evidence.
- The major previous ambiguity, "is this the same as or replaced by `0x0046c550`?", is resolved: it is related but distinct, and `0x0046c550` is the active route.
- The no-caller issue has been investigated through neighboring dispatch and registration evidence. It remains material only for final C++ emission, not for current metadata/source-quality classification.
- Remaining source-facing names are best-supported descriptive names, not original-symbol claims. That is acceptable at `85` completion but not enough for a higher routine tier.

Additional evidence required for final C++:

- A direct or indirect caller/table route to `0x0046a510`; or
- historical source/debug/map evidence proving the helper existed as a static BrowserWindow helper; or
- supervisor policy accepting final source emission of retained no-xref static helpers in Browser source.

## Exact Recommended Target Metadata

Replace the target metadata header with:

```text
*** PROJECT: GHIDRA_BRIDGE_RECON
*** UID: 00020U
*** ADDRESS: 0x0046a510-0x0046a617
*** NAME: BrowserWindowAcceleratorTranslateMessage
*** CATEGORY: by-memory
*** PARENT: 0000HV
*** COMPOSITION: leaf
*** ROLE: browser-accelerator-helper
*** COMPLETION: 85
*** CONFIDENCE: 90
*** CANONICAL_OWNER: 0000HV
*** RECONSTRUCTABLE: TRUE
*** EMITTER_UIDS: 0000HV
*** C++:
```

If the supervisor accepts a page rename, use:

```text
*** NAME: BrowserWindowTranslateAcceleratorMessage
```

Otherwise keep the current page name and add the source-facing inferred name in the notes.

## Exact Target Text To Apply If Accepted

Add this section to the target page, preferably after the existing behavior/evidence section:

```markdown
## B001 2026-06-16 Source-Quality Recheck

Fresh IDA MCP session `b001_00020U_browser_accel_20260616` reopened `NexusTK.exe.i64` read-only and confirmed `sub_46A510` as `0x0046a510-0x0046a617` (`0x107` bytes), prototype `int __cdecl(int)`, 23 basic blocks, and no direct external callers/xrefs. A loaded-segment absolute pointer search found no pointer hit for `0x0046a510`, while the proven BrowserWindow WndProc `0x0046a630` still has its constructor pointer at `0x00469758/0x0046975e`. `xrefs_to 0x0046c550` shows the active Application-message route at `0x00464d88` in `sub_464CD0`; decompilation of `sub_464CD0` calls `BrowserControlPaneTranslateAcceleratorMessage(&Msg)` only after checking `g_activeBrowserControlPane`, so the active pump route is the distinct BrowserControlPane helper, not this BrowserWindow helper.

Best source-facing name is inferred/descriptive: `BrowserWindowTranslateAcceleratorMessage(MSG *message)`. The helper is not a thunk: it has a full switch/body and local switch data/padding after the function end. It is a BrowserWindow-specific analogue of `BrowserControlPaneTranslateAcceleratorMessage`: it reads `g_pActiveBrowserWindow`, queries `[g_pActiveBrowserWindow + 0x18]` for `IID_IOleInPlaceActiveObject`, shares the `Ctrl+N`/Escape/TranslateAccelerator behavior, and releases the queried interface. The `0x0046c550` helper reads `g_activeBrowserControlPane + 0x120` and is called from the Application loop, so it is a related active BrowserControlPane route, not proof of duplicate ownership for `0x0046a510`.
```

Add or replace reconstruction/source notes with:

```markdown
## Reconstruction Notes

The declaration can be documented as `static int __cdecl BrowserWindowTranslateAcceleratorMessage(MSG *message)` with HRESULT-like dispatch semantics: `0` means consumed/handled and nonzero means the caller should continue normal dispatch. The helper forwards the result of `IOleInPlaceActiveObject::TranslateAccelerator(message)` after querying `[g_pActiveBrowserWindow + 0x18]` for `IID_IOleInPlaceActiveObject`.

Final C++ remains intentionally blank pending either a recovered caller/table route or a supervisor decision that retained no-xref Browser static helpers may be emitted as unused file-static helpers. The no-caller state has been checked through direct xrefs, loaded-segment pointer search, the Application message loop, BrowserWindow constructor/WndProc registration, the adjacent raw WndProc clone, BrowserWindow vtable neighborhood evidence, and the related BrowserControlPane dispatch route.
```

Replace or extend the score rationale with:

```markdown
## Score Rationale

Completion is raised to `85` because the function body, boundary, global/GUID names, helper signature, return convention, source route, and relationship to the active `0x0046c550` BrowserControlPane helper are now resolved or best-inferred with direct evidence. Confidence is raised to `90` because fresh IDA/MCP evidence confirms the behavior and the no-xref investigation across caller, pointer, WndProc, constructor, vtable-neighborhood, and message-loop routes. Remaining uncertainty is limited to original source symbol/caller proof and final emission policy for retained no-xref helpers.
```

Add this change-log entry:

```markdown
- 2026-06-16 B001 source-quality reanalysis: recommended score change `82/88 -> 85/90`; classified `0x0046a510` as a distinct retained BrowserWindow-specific accelerator helper, not a thunk and not the active Application route; confirmed `0x0046c550` as the active BrowserControlPane message-loop route; final C++ remains blank pending retained-helper/caller policy.
```

## Exact Support-Doc Text If Accepted

Optional `by-class/BrowserWindow.md` support text:

```markdown
- `0x0046a510-0x0046a617` is best treated as a file-static BrowserWindow-specific accelerator helper, source-facing name inferred as `BrowserWindowTranslateAcceleratorMessage(MSG *message)`. It reads `g_pActiveBrowserWindow + 0x18`, queries `IID_IOleInPlaceActiveObject`, handles `Ctrl+N` and `Escape`, then forwards to `IOleInPlaceActiveObject::TranslateAccelerator`. Fresh B001 recheck found no direct caller/table route; the active Application pump route is the distinct BrowserControlPane helper at `0x0046c550`.
```

Optional `by-class/BrowserControlPane.md` support text:

```markdown
- The accelerator helper at `0x0046c550` is the active Application message-loop route from `sub_464CD0` and should remain BrowserControlPane-owned/routed. It is related to but distinct from the retained BrowserWindow-specific helper at `0x0046a510`, which reads `g_pActiveBrowserWindow + 0x18` rather than `g_activeBrowserControlPane + 0x120`.
```

Optional `by-file/Browser.md` support text:

```markdown
- B001 source-quality recheck classifies `0x0046a510` as a retained BrowserWindow-specific accelerator helper under Browser source routing, while `0x0046c550` remains the active BrowserControlPane/Application message-loop helper. Keep both helpers distinct; do not merge `0x0046a510` into the BrowserControlPane route.
```

## Exact Coverage Replacement Row

The by-memory coverage report is banned for agent edits. If the supervisor applies this recommendation, replace the existing `00020U` row with the following row in the Browser code neighborhood:

```markdown
| [UID:00020U][0x0046a510-0x0046a617.BrowserWindowAcceleratorTranslateMessage](by-memory/0x0046a510-0x0046a617.BrowserWindowAcceleratorTranslateMessage.md) | emits | `0000HV` | `0000HV` |  | no | `auto-generated/NexusTK/browser/Browser.cpp` | BrowserWindow-specific accelerator helper; fresh B001 recheck confirms `g_pActiveBrowserWindow + 0x18` -> `IID_IOleInPlaceActiveObject`, `Ctrl+N`/Escape/`TranslateAccelerator` behavior, distinct from active BrowserControlPane route `0x0046c550`; no direct caller/table route found after xref, pointer, WndProc, constructor, vtable-neighborhood, and Application-loop checks; recommended score `85/90`, final C++ blank pending retained-helper emission policy. |
```

If the local coverage report format uses the compact scored row style, use this replacement instead:

```markdown
- [UID:00020U][0x0046a510-0x0046a617.BrowserWindowAcceleratorTranslateMessage](by-memory/0x0046a510-0x0046a617.BrowserWindowAcceleratorTranslateMessage.md) 0x0046a510-0x0046a617 | browser message helper | BrowserWindowAcceleratorTranslateMessage : reconstructable : 85% : very strong : Fresh B001 source-quality recheck confirms exact `0x107`-byte BrowserWindow-specific `IOleInPlaceActiveObject` accelerator helper, `g_pActiveBrowserWindow + 0x18` query through `IID_IOleInPlaceActiveObject`, `Ctrl+N`/Escape/`TranslateAccelerator` behavior, no direct xrefs or absolute pointer hits, active message-loop route belongs to distinct BrowserControlPane helper at `0x0046c550`, Browser owner/emitter route remains valid, and final C++ remains blank pending retained-helper/caller policy.
```

## Validator Results

No project validator was run because this assignment is report-only and no target by-memory pages, generated reports, coverage reports, source files, or IDA database state were edited.

## Files Changed

Created this research report only:

```text
source-3/project-documentation/tools/leaser/Agents/Agent-B001/research/00020U-browser-accelerator-source-quality.md
```

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B001","command_id":"000000004165","destination_path":"executed-b-agent-research/B001/00020U-browser-accelerator-source-quality.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:20","uid":"00020U"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
