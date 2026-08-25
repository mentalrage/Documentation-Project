** TARGET-REPORT-UID:0004CX **
** AUTHOR-AGENT-ID:B010 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | Medium **
** TARGET-REPORT-PATH:by-memory/0x00581730-0x005817a0.StartupNoticeSetButtonState.md **

# UID0004CX StartupNoticeSetButtonState Source-Quality Report

## Finalized Report / Current Recommendation

UID0004CX stays an emitting StartupWindow helper and has received the direct target-level source-quality refresh approved by supervisor callback, not a no-code reclassification. The formal helper C++ is source-shaped and matches the current IDA MCP behavior, so the implementation preserved the exact formal block while adding current evidence and raising the score.

Applied target metadata after callback:

- `COMPLETION:88`
- `CONFIDENCE:91`
- `CANONICAL_OWNER:0000O5`
- `RECONSTRUCTABLE:TRUE`
- `EMITTER_UIDS:0000O5`
- blank `EMITTER_POSITION_OPTIONAL`

The reason UID0004CX still appears in the not-covered research tracker is not a source blocker: the exact child page was created by the executed B008 `0000O5-StartupWindow-empty-emitter-family-source-quality.md` family report, so the tracker records `Reports:0` for the child itself. Current MCP evidence independently reconfirms the child as a real source-ready helper.

## Supporting Research

- Assignment source: `tools/leaser/Agents/Agent-B010/goal.md`, target UID0004CX, path `by-memory/0x00581730-0x005817a0.StartupNoticeSetButtonState.md`, report path `tools/leaser/Agents/Agent-B010/research/0004CX-StartupNoticeSetButtonState-source-quality.md`.
- Project workflow used: `ntk-b-agent-workflow` plus `references/b-agent-research-and-implementation-workflow.md` and `references/b-agent-report-template.md`.
- Active MCP evidence session: JSON-RPC `idb_list` returned active session `nexustk_supervisor_20260704`; `server_health` returned `status:"ok"`, IDB `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, input `NexusTK.exe`, imagebase `0x400000`, auto-analysis ready, Hex-Rays ready, and strings cache ready.
- Local docs checked: target UID0004CX, sibling UID0004CU/0004CW/0004CY docs, parent/split UID0001IO, `by-class/StartupWindow.md`, `by-file/StartupWindow.md`, and `by-item/StartupWindowUnmodeledNoticeHelpers_5815b0_581b7f.md`.
- Generated context checked read-only during research: `auto-generated/-ag-research-tracker.md` listed UID0004CX in `by-memory` not-covered reconstructable rows with `86/88`, `Reports:0`; pre-callback `auto-generated/NexusTK/app/StartupWindow.cpp` already emitted the helper body from UID0004CX under validator command `000000006343`, refreshed `2026-07-04T13:36:35-04:00`.
- Post-callback generated freshness checked after scoped validators: `auto-generated/NexusTK/app/StartupWindow.cpp` refreshed under validator command `000000006392` at `2026-07-04T17:59:35-04:00`; a later observed deferred refresh advanced the header to command `000000006394` at `2026-07-04T18:03:36-04:00`. The latest generated output emits UID0004CX at `Completion:88 | Confidence:91` with the formal helper body.
- Historical reports searched as leads and revalidated against current docs/MCP: executed B008 `0000O5-StartupWindow-empty-emitter-family-source-quality.md`, executed B010 `0001IO-StartupWindowUpdateCheck-source-quality.md`, and current B012 `0004CU-StartupNoticePostButtonResult-source-quality.md`.
- Implementation callback boundary: target/support by-* docs were edited only after supervisor Gate 1 approval, leases were acquired before edits and released after scoped validation, and scoped file validators were run only for changed by-* docs. No `execute_report`, dry-run/probe execute, registry lifecycle, lifecycle/archive, manual report move, coverage edit, generated manual edit, validator-state edit, or supervisor-ledger edit was run by B010.

## Target

- UID: `0004CX`
- Path: `by-memory/0x00581730-0x005817a0.StartupNoticeSetButtonState.md`
- Current target metadata after callback: `COMPLETION:88`, `CONFIDENCE:91`, `CANONICAL_OWNER:0000O5`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000O5`, blank optional emitter position.
- Current formal C++ exists and is an emitted `static void StartupNoticeSetButtonState(StartupWindow *startupWindow, int buttonIndex, int state)` helper.
- Current owner/emitter route: [UID:0000O5] `StartupWindow` / `NexusTK/app/StartupWindow.cpp`.
- Current assignment mode: post-implementation callback artifact returned for supervisor execution; B010 did not run any lifecycle or execution command.

## Current Target State

UID0004CX is not an empty-emitter problem anymore. It is an exact child created by B008, appears in generated `StartupWindow.cpp`, and has a formal body. The post-callback target page now contains direct B010 B-report coverage, current MCP-backed evidence, and the applied `88/91` score.

Current generated output from `auto-generated/NexusTK/app/StartupWindow.cpp`:

- Header: validator command `000000006394`, refreshed `2026-07-04T18:03:36-04:00`, source by-file UID `0000O5`.
- UID0004CX appears as `// UID:0004CX | by-memory/0x00581730-0x005817a0.StartupNoticeSetButtonState.md | Completion:88 | Confidence:91`.
- The generated helper body is the same source-shaped block recommended below.
- The helper is called from generated WndProc/post-result helper contexts at the expected source sites.

Remaining confidence caps after this pass:

- Original private helper spelling is not recovered.
- The binary calling convention is `__thiscall`-like, while the accepted source family uses file-local helper syntax with an explicit `StartupWindow *` argument; this is a source-shape convention cap, not a behavior blocker.
- The `StartupNoticeButton`, `m_buttons`, `m_noticeWindow`, and `state` names are support-doc-backed first-draft names rather than proven original symbols.

## Heuristic / Inference Reanalysis And Validation

The old heuristic issue was that UID0004CX was created by the broad StartupWindow family callback, so it inherited a useful but indirect report trail. Current evidence closes the direct child-level questions:

- Function boundary: MCP `lookup_funcs` reports `sub_581730`, start `0x00581730`, size `0x70`; the successor `sub_5817A0` begins at `0x005817a0`. `get_bytes 0x00581724 size 140` shows twelve `0xcc` bytes before the target, then target code, then `0x55 0x8b 0xec` for the successor.
- `ret 8` handling: MCP disassembly shows `retn 8` at `0x0058179d`; the `0x08 0x00` bytes at `0x0058179e-0x005817a0` are the immediate operand, not padding. This validates the half-open target range through `0x005817a0`.
- Signature shape: MCP `analyze_function` renders prototype `int __thiscall(_DWORD *this, int, int)` and disassembly confirms two stack args with `ecx` as receiver. Since all callers ignore the return, source-facing `void` remains better than propagating decompiler `int`.
- Field layout: the helper computes `index * 0x20`, compares/writes state at `this + 0x30 + index*0x20`, copies the rectangle from `this + 0x20 + index*0x20`, and invalidates HWND at `this + 0x0c`. These match `m_buttons[index].rect`, `m_buttons[index].state`, and `m_noticeWindow`.
- Caller set: MCP `xrefs_to` and `xref_query` report exactly five code refs: four from `sub_581100` at `0x005813ad`, `0x005813bd`, `0x005814e5`, `0x00581542`, and one raw helper ref at `0x00581632`.
- Related UID0001IO: the broad aggregate is now a non-emitting split index at `88/90`, and its current table already identifies UID0004CX as the exact source-bearing child. UID0001IO should not duplicate this body.
- Related UID0004CU: raw helper slice at `0x00581620` proves its call at `0x00581632` passes `buttonIndex=0`, `state=1` before posting `WM_USER + 11` result `1`. That supports, rather than blocks, UID0004CX.

No evidence supports removing the formal C++ or switching UID0004CX to a no-code marker. The current formal body should remain, with refreshed evidence and score.

## Evidence Standards Used

- IDA MCP evidence is treated as primary for live function boundaries, xrefs, callees, decompilation, disassembly, and byte ranges.
- Current by-* docs are support evidence for accepted source names, owner routes, family split context, and existing generated behavior.
- Generated C++ is treated as current output evidence, not as primary source authority.
- Executed/current B reports are lead material only; all important B008/B010/B012 claims used here were rechecked against current docs or live MCP.
- Inferences are labeled where they depend on source-shape convention rather than original symbol recovery.

## Evidence Checked

MCP calls used active session `nexustk_supervisor_20260704`:

- JSON-RPC id 4 `idb_list`: one active NexusTK session, not analyzing.
- JSON-RPC id 6 `server_health`: `status:"ok"`, auto-analysis ready, Hex-Rays ready, strings cache ready.
- JSON-RPC id 9 `lookup_funcs`: target `0x00581730` is `sub_581730`, size `0x70`; predecessor padding start `0x00581724` is not a function; sibling `0x00581670` and successor `0x005817a0` are modeled helpers; raw starts `0x005815b0`, `0x005817e0`, and `0x00581860` are not functions.
- JSON-RPC ids 10 and 11 `xrefs_to` / `xref_query`: five code refs to target, four inside `sub_581100` and one raw ref at `0x00581632`.
- JSON-RPC id 12 `callees`: target calls only `InvalidateRect` and `@__security_check_cookie@4`.
- JSON-RPC id 13 `decompile`: target compares the indexed state, writes the new state, copies one `RECT`, and calls `InvalidateRect(this[3], &Rect, 0)` only when changed.
- JSON-RPC id 14 `disasm`: 33 instructions total; `shl eax, 5`, state compare/write at `[eax+ecx+30h]`, rectangle load from `[eax+ecx+20h]`, HWND load from `[ecx+0Ch]`, `call ds:InvalidateRect`, security check, and `retn 8`.
- JSON-RPC id 15 `get_bytes`: twelve `0xcc` bytes at `0x00581724-0x00581730`, target body bytes, and successor prologue at `0x005817a0`.
- JSON-RPC id 16 `search_text`: five `call sub_581730` hits at `0x005813ad`, `0x005813bd`, `0x005814e5`, `0x00581542`, and `0x00581632`.
- JSON-RPC id 18 `decompile 0x00581100`: WndProc calls target for mouse move/hover, left button down, and left button up/update result paths.
- JSON-RPC id 21 `disasm 0x00581620`: raw helper call context pushes `1`, pushes `eax` where `eax==0`, sets `ecx=esi`, calls `sub_581730`, then posts `WM_USER + 11`.
- JSON-RPC id 23 `analyze_function`: target prototype, size `112`, three basic blocks, cyclomatic complexity `2`, callers listed as `sub_581100` plus xrefs including raw `0x581632`.
- JSON-RPC id 24 `callees` over related helpers: WndProc callee set includes UID0004CX, reset/hit-test/draw/resource helpers, User32/GDI/Shell APIs; target callee set remains only invalidation plus security cookie.

Local/documentation checks:

- Target page current metadata/formal C++.
- StartupWindow class/file docs for source route and child split list.
- UID0001IO split index for covered range and exact child relationship.
- UID0004CU/UID0004CW/UID0004CY sibling helper pages for button semantics and source-family naming.
- `by-item/StartupWindowUnmodeledNoticeHelpers_5815b0_581b7f.md` for raw helper tracker status.
- `auto-generated/-ag-research-tracker.md` for `Reports:0` direct-coverage gap.
- `auto-generated/NexusTK/app/StartupWindow.cpp` for current generated body and command header.

## IDA MCP Facts

| Fact | MCP evidence |
| --- | --- |
| Active IDB | `idb_list` session `nexustk_supervisor_20260704`, `NexusTK.exe.i64`, active worker session. |
| Server state | `server_health` status ok, auto-analysis ready, Hex-Rays ready. |
| Function record | `lookup_funcs 0x00581730`: `sub_581730`, size `0x70`. |
| Range boundary | `lookup_funcs 0x005817a0`: successor `sub_5817A0`; `get_bytes` shows `cc x12` before target and successor prologue after target. |
| Return convention | `disasm`: `retn 8` at `0x0058179d`, immediate bytes are inside the target range. |
| Receiver/arguments | `analyze_function`: `int __thiscall(_DWORD *this, int, int)`; source should express receiver as `StartupWindow *startupWindow` plus `buttonIndex` and `state`. |
| Callees | Target calls `InvalidateRect` and security-cookie check only. |
| Xrefs | Five code refs total: four WndProc refs and one raw UID0004CU helper ref. |
| Behavior | State changes are tested before writing; only changed state causes `InvalidateRect(m_noticeWindow, &button.rect, FALSE)`. |

## Function / Caller Inventory

| Address/range | Current function state | Source-facing role | UID relationship | Evidence |
| --- | --- | --- | --- | --- |
| `0x00581100-0x005815aa` | IDA function `sub_581100`, size `0x4aa` | `StartupWindowUpdateCheckWindowProc` | Caller of UID0004CX | Four direct call sites to target, plus hit-test/reset/draw/resource behavior. |
| `0x005815b0-0x0058165a` | no IDA function object | `StartupNoticePostButtonResult` raw helper | Caller of UID0004CX through UID0004CU | Raw slice has `call sub_581730` at `0x00581632` for button 0/result 1 behavior. |
| `0x00581670-0x00581724` | IDA function `sub_581670`, size `0xb4` | `StartupNoticeResetButtonStates` | sibling UID0004CW | Clears nonzero state slots and invalidates changed rects. |
| `0x00581724-0x00581730` | not a function | reset-to-set padding | ignored/alignment | Twelve `0xcc` bytes. |
| `0x00581730-0x005817a0` | IDA function `sub_581730`, size `0x70` | `StartupNoticeSetButtonState` | target UID0004CX | Sets one indexed state and invalidates one rect on change. |
| `0x005817a0-0x005817dd` | IDA function `sub_5817A0`, size `0x3d` | `StartupNoticeHitTestButton` | sibling UID0004CY | Hit-tests two button rectangles and returns index or `-1`. |

## Positive Evidence Summary

- Exact function boundary is current and simple: `0x00581730-0x005817a0`, size `0x70`, with real predecessor padding and real successor function start.
- `ret 8` is correctly part of the function body, proving two explicit stack arguments after the `ecx` receiver.
- The behavior is fully covered by direct disassembly/decompilation: compare current state, skip if unchanged, copy the indexed rectangle, write state, invalidate using `bErase=FALSE`.
- Caller set is narrow and startup-notice-local: WndProc mouse/button paths plus the raw post-result helper.
- The sibling helper family supports the first-draft names `StartupNoticeButton`, `m_buttons`, `m_noticeWindow`, and state semantics.
- Generated `StartupWindow.cpp` already emits the helper body, proving the current by-* route is operational.
- Owner/emitter route through [UID:0000O5] `StartupWindow` is supported by the WndProc, raw helper, resources, and parent split index.

## Negative Evidence Summary

- Do not treat `0x0058179e-0x005817a0` as padding. Those bytes are the `ret 8` immediate.
- Do not add a button-index guard to the target body. The binary body has no guard; callers enforce or naturally limit the two-button domain.
- Do not switch UID0004CX to a no-code marker. It is a modeled, source-authored, generated helper with a small exact body.
- Do not move ownership to Browser, ImageLoaders, Win32/User32, or a generic UI helper module. They are dependencies or unrelated consumers; the direct caller context is StartupWindow notice UI.
- Do not emit raw `sub_581730`, `unk_69BAC8`, `dword_`, XMM temporaries, or decompiler locals in source.
- Do not duplicate the body in UID0001IO. The aggregate is a non-emitting split/index and exact child pages own source-bearing bodies.
- Do not require a public `StartupWindow::SetButtonState` method before first-draft emission. Binary calling convention supports a receiver, but current family source shape consistently uses file-local helper names with an explicit `StartupWindow *`.

## Ranked Ownership Analysis

| Rank | Candidate | Decision | Evidence |
| ---: | --- | --- | --- |
| 1 | [UID:0000O5] `StartupWindow` / `NexusTK/app/StartupWindow.cpp` | Accepted owner/emitter | All callers are StartupWindow notice helpers; support docs route exact child pages through this file; generated output emits in `StartupWindow.cpp`. |
| 2 | [UID:0000DZ] `StartupWindow` class page | Support only | The receiver is a StartupWindow object, but the class page is a route/support page; exact helper body belongs on UID0004CX and emits through file UID0000O5. |
| 3 | [UID:0001IO] broad `StartupWindowUpdateCheck` aggregate | Non-emitting context only | Contains physical range inventory and split plan; current metadata is non-emitting. It should not duplicate UID0004CX C++. |
| 4 | Win32/User32 APIs | Dependency only | `InvalidateRect` is called, but API dependency does not own game helper source. |
| 5 | Browser/ImageLoaders/generic UI helpers | Rejected | No direct target refs, no source responsibility, and caller context stays inside StartupWindow notice UI. |

## Source Placement

Source placement should remain `NexusTK/app/StartupWindow.cpp` through [UID:0000O5] `StartupWindow`. The helper should remain file-local source under the startup notice helper family. The current first-draft helper syntax:

`static void StartupNoticeSetButtonState(StartupWindow *startupWindow, int buttonIndex, int state)`

is acceptable because it matches the generated StartupWindow helper family and keeps this small WndProc-only helper out of the public class API. The report records the binary `__thiscall` evidence as a confidence cap, not as a reason to reject the existing source-shaped helper.

## First-Draft C++ Recommendation

The callback preserved this exact formal block in the target page. This is the same source-shaped body currently present; the callback did not replace it with a no-code marker or raw decompiler form.

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
static void StartupNoticeSetButtonState(StartupWindow *startupWindow, int buttonIndex, int state)
{
    StartupNoticeButton &button = startupWindow->m_buttons[buttonIndex];
    if (button.state != state) {
        button.state = state;
        InvalidateRect(startupWindow->m_noticeWindow, &button.rect, FALSE);
    }
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

Source-quality notes:

- Keep `void`; callers ignore return and the meaningful side effect is the state/invalidation update.
- Keep no bounds guard; the target body does not implement one.
- Keep `FALSE` for `bErase=0`.
- Keep source-facing names and reject raw IDA labels in the final block.

## Recommended Target Doc Changes

For `by-memory/0x00581730-0x005817a0.StartupNoticeSetButtonState.md`, the callback applied these changes:

1. Set `COMPLETION:88`, `CONFIDENCE:91`.
2. Kept `CANONICAL_OWNER:0000O5`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000O5`, blank `EMITTER_POSITION_OPTIONAL`.
3. Preserved the exact formal `RECONSTRUCTION_CPP CODE` block from this report.
4. Expanded the evidence section with current MCP session `nexustk_supervisor_20260704`, including `lookup_funcs`, `xrefs_to`/`xref_query`, `decompile`, `disasm`, `get_bytes`, `search_text`, `analyze_function`, and related caller-context facts.
5. Documented the `ret 8` immediate handling explicitly: final bytes are part of the target function, not padding.
6. Documented caller split: four WndProc call sites plus raw UID0004CU call at `0x00581632`.
7. Documented behavior: indexed `0x20`-stride button slot, rectangle at `+0x20 + index*0x20`, state at `+0x30 + index*0x20`, notice HWND at `+0x0c`, invalidation only on state change.
8. Replaced broad "needs direct report" or "future work" wording with this direct-report disposition.

## Recommended Support Doc Changes

Support docs were inspected and updated only where stale during callback:

- `by-memory/0x005807d0-0x0058206e.StartupWindowUpdateCheck.md`: refreshed the UID0004CX child-row/context note to record B010 direct coverage, `88/91`, the active MCP session, range/size, five refs, `ret 8`, padding, field roles, and no-body duplication.
- `by-class/StartupWindow.md`: refreshed the helper-route note and live IDA evidence to state UID0004CX is directly rechecked at `88/91`, with `0x70` size, state/rect/HWND roles, no guard, and invalidation-on-change behavior.
- `by-file/StartupWindow.md`: refreshed the StartupWindow source route/caveat text to state exact helper child pages now own source-ready helper bodies and UID0004CX remains source-ready after B010 MCP recheck.
- No support doc absorbed the formal target body; exact source-bearing body stayed on UID0004CX.

## Claim And Incorporation Ledger

| Claim ID | Claim | Confidence | Evidence | Destination doc/section | Action | Verification state |
| --- | --- | --- | --- | --- | --- | --- |
| C01 | UID0004CX lacked direct B-report coverage because B008 created it through the StartupWindow family report; this direct report closes that tracker gap. | High | Research tracker row `Reports:0`; B008 executed report lines for child creation; target page `Changes` cites B008 family implementation. | Target `Evidence` / `Changes`; report `Supporting Research` | incorporate | applied: target evidence and `Changes` now cite B010 direct source-quality callback and tracker context; validator `000000006389` ok. |
| C02 | Target is a real IDA function `sub_581730`, range `0x00581730-0x005817a0`, size `0x70`. | High | MCP id 9 `lookup_funcs`; id 23 `analyze_function` size 112. | Target `Status` / `Evidence` | incorporate | applied: target evidence records modeled function/range/size under MCP session `nexustk_supervisor_20260704`; validator `000000006389` ok. |
| C03 | `ret 8` belongs to target body, not padding. | High | MCP id 14 `disasm` `retn 8` at `0x0058179d`; id 15 bytes; successor starts at `0x005817a0`. | Target `Evidence` / `Boundary` | incorporate | applied: target evidence explicitly says `ret 8` immediate is inside target; validator `000000006389` ok. |
| C04 | Pre-target `0x00581724-0x00581730` is twelve `0xcc` bytes. | High | MCP id 15 `get_bytes`; UID0001IO covered range table. | Target `Evidence`; UID0001IO covered-range note | incorporate | applied: target records padding; UID0001IO support refreshed with B010 boundary note; validators `000000006389` and `000000006390` ok. |
| C05 | Target uses `ecx` receiver plus two stack arguments, source-facing as `StartupWindow *`, `buttonIndex`, `state`. | High | MCP id 14 stack args and `ecx` field refs; id 23 prototype `int __thiscall(_DWORD *this, int, int)`. | Target `Evidence` / C++ notes | incorporate | applied: target formal C++ and evidence preserve receiver/two-argument source shape; validator `000000006389` ok. |
| C06 | The helper updates `m_buttons[buttonIndex].state` and invalidates `m_buttons[buttonIndex].rect` only when the state changes. | High | MCP ids 13, 14, 23 decompile/disasm; current formal C++ and generated output. | Target `Evidence`; formal C++ | incorporate | applied: target formal C++ preserved and evidence states invalidation only on change; latest observed generated refresh `000000006394` emits the body at `88/91`. |
| C07 | Notice HWND source field is `StartupWindow+0x0c` / `m_noticeWindow`. | High | MCP id 14 `push dword ptr [ecx+0Ch]`; StartupWindow support docs and generated C++. | Target `Evidence`; `by-class/StartupWindow.md`; `by-file/StartupWindow.md` | incorporate | applied: target and support docs record `m_noticeWindow`/HWND role; validators `000000006389`, `000000006391`, and `000000006392` ok. |
| C08 | Caller set is exactly five code refs: four WndProc refs and one raw UID0004CU helper ref. | High | MCP ids 10, 11, 16; id 23 xrefs. | Target `Evidence` / `Cross-References`; UID0001IO context note | incorporate | applied: target evidence and UID0001IO note record five refs/four WndProc/one raw helper; validators `000000006389` and `000000006390` ok. |
| C09 | Raw UID0004CU call at `0x00581632` passes `buttonIndex=0`, `state=1` and then posts update result. | High | MCP id 21 raw slice; current UID0004CU report/docs. | Target `Evidence`; support docs if stale | incorporate | applied: target evidence records UID0004CU raw call at `0x00581632` with arguments/result context; validator `000000006389` ok. |
| C10 | UID0001IO remains a non-emitting split/index and must not duplicate UID0004CX C++. | High | UID0001IO current metadata `RECONSTRUCTABLE:FALSE`, blank emitters/C++; covered range table. | UID0001IO support note | already-present | applied: UID0001IO remained non-emitting and received only context/no-duplication wording; validator `000000006390` ok. |
| C11 | Owner/emitter should remain [UID:0000O5] `StartupWindow`. | High | Caller context, StartupWindow support docs, generated `StartupWindow.cpp`. | Target metadata / Source Placement | incorporate | applied: owner/emitter/reconstructable state preserved in target and generated output remains under `StartupWindow.cpp`; validator `000000006389` ok. |
| C12 | Formal C++ should remain source-shaped and active; no no-code disposition is justified. | High | MCP body is exact, generated output contains body, callers ignore return. | Target formal C++ block | incorporate | applied: exact formal block preserved; latest observed generated refresh `000000006394` shows UID0004CX body, not a no-code/comment-only marker. |
| C13 | Target metadata should rise to `88/91`, with original symbol/helper-shape names still capping final confidence. | Medium-high | Direct MCP evidence resolves range/caller/body; names remain inferred support names. | Target metadata / Score rationale | incorporate | applied: target metadata set to `88/91`; validator `000000006389` reported `completion_update:1` and `confidence_update:1`. |
| C14 | Reject Browser, ImageLoaders, Win32/User32, generic helper, broad aggregate, and raw label ownership. | High | No target xrefs/ownership evidence outside StartupWindow; APIs are dependencies only. | Target `Negative Evidence`; support docs if stale | exclude-with-reason | applied: target negative evidence preserves rejected alternatives and raw-label rejection; validator `000000006389` ok. |
| C15 | Support docs do not need broad edits; exact body stays on UID0004CX. | High | Current class/file/UID0001IO docs route exact children through UID0000O5; callback read found stale direct-coverage wording only. | UID0001IO, `by-class/StartupWindow.md`, `by-file/StartupWindow.md`; target formal block | incorporate | applied: support docs refreshed narrowly; no support doc contains the exact UID0004CX body; validators `000000006390`, `000000006391`, and `000000006392` ok. |

## Final Recommendation

Implementation callback is complete and ready for supervisor execution:

- UID0004CX is raised to `88/91`.
- Owner/emitter/reconstructable state remains unchanged.
- The exact formal C++ block is preserved.
- Direct B010/current MCP evidence is incorporated into the target page.
- Support docs were touched only for stale direct-coverage/score/source-route wording.

This is not a no-code target and not a source-owner move. The formal helper body is already good first-draft C++.

## Score And Metadata Recommendation

| Field | Pre-callback | Applied/current | Reason |
| --- | --- | --- | --- |
| `COMPLETION` | `86` | `88` | Direct report closes the child-level evidence gap; function boundary, callers, behavior, generated output, and dependency context are now current. |
| `CONFIDENCE` | `88` | `91` | Current MCP proves exact range/body/caller set; confidence is capped only by original helper spelling and source-shape convention around `__thiscall` versus file-local helper syntax. |
| `CANONICAL_OWNER` | `0000O5` | `0000O5` | StartupWindow caller/source route remains strongest. |
| `RECONSTRUCTABLE` | `TRUE` | `TRUE` | Small source-authored helper with active generated body. |
| `EMITTER_UIDS` | `0000O5` | `0000O5` | Generated output already emits through `StartupWindow.cpp`. |
| Formal C++ | Active helper body | Preserve exact formal block | Behavior matches MCP and support docs. |

## Open Questions With Attempted Resolution

| Question | Investigation | Resolution |
| --- | --- | --- |
| Is `ret 8` padding or part of UID0004CX? | MCP disasm and bytes around `0x0058179d-0x005817a0`; successor lookup at `0x005817a0`. | Resolved: `ret 8` is the epilogue and its immediate bytes are part of the target. |
| Should the source be a private class method instead of a file-local static helper? | MCP shows `__thiscall`; support/generated family uses explicit `StartupWindow *` file-local helper form for notice helpers. | First-draft remains file-local helper; original method spelling/class declaration proof is not strong enough to force a method rewrite. |
| Should a bounds guard be added for `buttonIndex`? | Target disasm has no guard; callers supply two-button indices or reset/hit-test logic. | Resolved: no guard in target C++. |
| Does UID0004CX need no-code because it was inherited from a family report? | Current target has formal C++, generated output emits it, and MCP body is exact. | Resolved: keep active formal body. |
| Are support docs stale enough to require callback edits? | Callback read found narrow stale direct-coverage/current-score wording in UID0001IO, class, and file docs. | Resolved: those support docs were refreshed narrowly; the exact body stayed on UID0004CX. |

## Validator Results

Scoped validators were run from `E:\NTK\GhidraBridge\source-3\project-documentation` for every changed by-* file.

| File | Command | command_id | command_timestamp | Exit | ok | Warnings | Generated refresh |
| --- | --- | --- | --- | ---: | ---: | --- | --- |
| `by-memory/0x00581730-0x005817a0.StartupNoticeSetButtonState.md` | `python .\tools\validator.py --mode file --file by-memory/0x00581730-0x005817a0.StartupNoticeSetButtonState.md --apply --queue-timeout 240` | `000000006389` | `2026-07-04T17:59:09-04:00` | `0` | `1` | none reported | `deferred`; command id `000000006389`, timestamp `2026-07-04T17:59:09-04:00` |
| `by-memory/0x005807d0-0x0058206e.StartupWindowUpdateCheck.md` | `python .\tools\validator.py --mode file --file by-memory/0x005807d0-0x0058206e.StartupWindowUpdateCheck.md --apply --queue-timeout 240` | `000000006390` | `2026-07-04T17:59:14-04:00` | `0` | `1` | none reported | `deferred` |
| `by-class/StartupWindow.md` | `python .\tools\validator.py --mode file --file by-class/StartupWindow.md --apply --queue-timeout 240` | `000000006391` | `2026-07-04T17:59:25-04:00` | `0` | `1` | none reported | `deferred` |
| `by-file/StartupWindow.md` | `python .\tools\validator.py --mode file --file by-file/StartupWindow.md --apply --queue-timeout 240` | `000000006392` | `2026-07-04T17:59:35-04:00` | `0` | `1` | none reported | `deferred` |

Generated freshness check after validators:

- `auto-generated/NexusTK/app/StartupWindow.cpp` header: latest observed validator command `000000006394`, refreshed `2026-07-04T18:03:36-04:00`, refresh source `deferred-generated-refresh`; the direct by-file validator row above was command `000000006392`.
- UID0004CX now emits as `Completion:88 | Confidence:91` with the same formal `StartupNoticeSetButtonState` body.

## Changed Files

- Edited target doc: `by-memory/0x00581730-0x005817a0.StartupNoticeSetButtonState.md`.
- Edited support docs: `by-memory/0x005807d0-0x0058206e.StartupWindowUpdateCheck.md`, `by-class/StartupWindow.md`, `by-file/StartupWindow.md`.
- Checked but not edited during callback/context review: `by-memory/0x005815b0-0x0058165a.StartupNoticePostButtonResult.md`, `by-memory/0x00581670-0x00581724.StartupNoticeResetButtonStates.md`, `by-memory/0x005817a0-0x005817dd.StartupNoticeHitTestButton.md`, and `by-item/StartupWindowUnmodeledNoticeHelpers_5815b0_581b7f.md`.
- Updated report ledger/checklist: `tools/leaser/Agents/Agent-B010/research/0004CX-StartupNoticeSetButtonState-source-quality.md`.
- Validator-generated refresh side effect observed: `auto-generated/NexusTK/app/StartupWindow.cpp` refreshed after the validator batch and was later observed at command `000000006394`; B010 did not manually edit generated files.
- No coverage report, validator state, lifecycle/archive file, or supervisor-ledger file was edited by B010.
- Lease usage: B010 leased the four by-* docs before editing and released all four after validation; shared lease table reported no active leases after release.

## Implementation Tracking Checklist

- [x] Target metadata: set `by-memory/0x00581730-0x005817a0.StartupNoticeSetButtonState.md` to `COMPLETION:88`, `CONFIDENCE:91`; kept `CANONICAL_OWNER:0000O5`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000O5`, blank optional emitter position. Validator `000000006389` reported completion/confidence updates and exit `0`.
- [x] Target formal C++: preserved the exact formal `RECONSTRUCTION_CPP CODE` block from this report. Latest observed generated refresh `000000006394` emits the helper body at `88/91`.
- [x] Target evidence: added MCP session `nexustk_supervisor_20260704` details for `idb_list`, `server_health`, `lookup_funcs`, xrefs, decompile, disasm, bytes, caller context, callees, and generated output status.
- [x] Target boundary: stated that `0x00581724-0x00581730` is twelve bytes of padding and `ret 8` at `0x0058179d` is part of UID0004CX.
- [x] Target behavior: documented state-slot compare/write, rectangle copy, HWND field, `InvalidateRect(..., FALSE)`, and no bounds guard.
- [x] Target caller set: documented four WndProc refs plus raw UID0004CU ref at `0x00581632`.
- [x] Target negative evidence: rejected no-code disposition, broad aggregate duplication, raw labels, Browser/ImageLoaders/Win32 ownership, and guard insertion.
- [x] Support docs: inspected `by-memory/0x005807d0-0x0058206e.StartupWindowUpdateCheck.md`, `by-class/StartupWindow.md`, and `by-file/StartupWindow.md`; updated only stale direct-coverage/current-score/source-route wording.
- [x] Validation after callback: ran scoped validators for all four edited by-* files; command ids `000000006389`, `000000006390`, `000000006391`, and `000000006392`, all exit `0`, ok `1`, no warnings reported.
- [x] Lease cleanup: released all four by-* doc leases; shared lease table reports no active leases.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B010","command_id":"000000006396","destination_path":"executed-b-agent-research/B010/0004CX-StartupNoticeSetButtonState-source-quality.md","details":"report executed into central archive","event":"executed","source_path":"tools/leaser/Agents/Agent-B010/research/0004CX-StartupNoticeSetButtonState-source-quality.md","timestamp":"2026-07-04T18:08:04-04:00","uid":"0004CX"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
