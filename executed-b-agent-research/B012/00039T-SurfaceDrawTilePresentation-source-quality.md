** TARGET-REPORT-UID:00039T **
** AUTHOR-AGENT-ID:B012 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# [UID:00039T] SurfaceDrawTilePresentation Source-Quality Reanalysis

## Finalized Report / Current Recommendation

- Current recommendation: keep [UID:00039T][0x005583a0-0x0055867a.SurfaceDrawTilePresentation](../../../../by-memory/0x005583a0-0x0055867a.SurfaceDrawTilePresentation.md) as a reconstructable source-authored presentation helper in the current Surface presentation bucket, with ScreenPane receiver caveat and blank formal C++.
- Final disposition: no split, no merge, target-only callback applied; no support by-* edit required.
- Required action: supervisor Gate 2 review and execute-report lifecycle only. The narrow target evidence refresh was applied, replacing/historicalizing the old "IDA MCP unavailable" sentence with current MCP proof; other accepted details were already present at same-or-greater detail.
- Metadata recommendation: keep current `COMPLETION:86`, `CONFIDENCE:88`, `RECONSTRUCTABLE:TRUE`, `CANONICAL_OWNER:0000OC`, and `EMITTER_UIDS:0000OC`. The current route is the existing `Surface.cpp` presentation source bucket, while the actual C++ receiver remains the root ScreenPane object.
- Confidence: high for range, bytes, branch behavior, helper dependencies, globals, no external entry route, and blank formal C++; medium-high for exact original source-file boundary because current project docs intentionally keep this family in `render/Surface.cpp` even though the receiver is ScreenPane-shaped.

## Supporting Research

- Historical lifecycle: this active de-executed repair copy previously carried top-level `REPORT-VALIDATION-STATUS: needs-revalidation` and `REPORT-REVALIDATION-REASON: target_uid_unknown: 00039T` headers from validator command `000000004167`. Under the current supervisor override, those two top-level status lines were removed from the active report body and preserved here as historical context only. The validator-owned `VALIDATOR-REPORT-HISTORY` footer remains unchanged.
- Historical de-execution: validator command `000000006857` returned the report from `executed-b-agent-research/B012/00039T-SurfaceDrawTilePresentation-source-quality.md` to `tools/leaser/Agents/Agent-B012/research/00039T-SurfaceDrawTilePresentation-source-quality.md` for same-report repair on `2026-07-05T07:00:44-04:00`.
- Current supervisor validator repair: command `000000006859`, timestamp `2026-07-05T07:01:25-04:00`, ran `python .\tools\validator.py --mode file --file by-memory/0x005583a0-0x0055867a.SurfaceDrawTilePresentation.md --apply --queue-timeout 240`, exited `0`, and reported `ok: 1`.
- Validator `000000006859` effects: `path_update`, `completion_update 86`, `confidence_update 88`, `canonical_owner_update 0000OC`, autogen registry updates, projected stats update, and `generated_refresh: deferred`.
- Current remaining validator warnings are sibling `missing_ref_uid` warnings for referenced UIDs `00039P`, `0003A3`, `0003A4`, and `00039U`. They are registry/reference warnings around adjacent siblings, not evidence that `00039T` is missing after the mapping repair.
- Current generated state was checked after the validator repair: `auto-generated/-ag-research-tracker.md` lists UID00039T at `86/88`, average `87.0`; `auto-generated/-ag-memory-coverage.md` routes UID00039T through owner/emitter `0000OC` to `auto-generated/NexusTK/render/Surface.cpp`; generated `Surface.cpp` carries validator-command-id `000000006859`, refreshed-at `2026-07-05T07:01:25-04:00`, and line-level UID00039T empty emitter marker at `86/88`.

## Target

- Target UID: `00039T`
- Target path: `E:\NTK\GhidraBridge\source-3\project-documentation\by-memory\0x005583a0-0x0055867a.SurfaceDrawTilePresentation.md`
- Current scores and state: `COMPLETION:86`, `CONFIDENCE:88`, `CANONICAL_OWNER:0000OC`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000OC`, blank formal C++.
- Current generated tracker state: `auto-generated/-ag-research-tracker.md` lists `00039T` at `86/88`, average `87.0`, reconstructable `true`, nested `0`.
- Current generated route: `auto-generated/-ag-memory-coverage.md` routes `00039T` through [UID:0000OC][Surface](../../../../by-file/Surface.md) to `auto-generated/NexusTK/render/Surface.cpp`; generated `Surface.cpp` currently contains only an empty emitter marker for this UID and is refreshed at validator command `000000006859`.
- Current manual coverage state: `by-memory/-coverage-report.md` remains out of scope for B012 report repair. B012 did not edit manual coverage; the exact supervisor-owned text below remains available only if the supervisor decides a manual tracker/coverage update is still needed.

## Current Target State

The target exists at `by-memory/0x005583a0-0x0055867a.SurfaceDrawTilePresentation.md` with UID00039T, current metadata `86/88`, owner/emitter `0000OC`, `RECONSTRUCTABLE:TRUE`, and an empty formal `RECONSTRUCTION_CPP CODE` block. The page already contains the main B012 source-quality incorporation from the earlier executed report: source-authored retained presentation helper, `DrawTileSurface`/`ScreenPane::DrawTileSurface(short frameCount)` naming direction, Surface bucket with ScreenPane receiver caveat, exact range/padding, behavior, field/global roles, no-entry proof, rejected alternatives, and blank-C++ rationale.

The target now historicalizes the old `Reachability And No-Entry Evidence` sentence saying IDA MCP was unavailable for the prior pass and records current MCP session `supervisor_recovery_20260705`. Metadata remains `86/88`, owner/emitter `0000OC`, `RECONSTRUCTABLE:TRUE`, and blank formal C++.

## Executive Recommendation

Treat `0x005583a0-0x0055867a` as a retained no-entry presentation helper best named descriptively as `DrawTileSurface` or, with the receiver made explicit, `ScreenPane::DrawTileSurface(short frameCount)`. Keep the file label `SurfaceDrawTilePresentation` as a searchable documentation title because it is already used by coverage/autogen, but source-facing prose should prefer:

- `DrawTileSurface`: strongest short helper name from the Surface file page and callback-table docs.
- `ScreenPane::DrawTileSurface(short frameCount)`: strongest method-shaped name if current `CANONICAL_OWNER` semantics are interpreted strictly. The function is `thiscall`-shaped, uses `ecx` as the root presentation object, and returns with `ret 4` after consuming one 16-bit loop/count argument from `[ebp+8]`.
- `SurfaceDrawTilePresentation`: acceptable documentation/file name, but less source-like than `DrawTileSurface`.

Do not populate formal C++ now. The target clears the numeric emitter gate, but it fails the source-quality gate for final output because current MCP and prior local PE evidence still show no direct call, no direct jump, no absolute pointer/pointer-byte hit, and no external branch route into the body or its range. A function with no proven entry route and unresolved family-level Surface-vs-ScreenPane method placement would force guessed dead-source code into `Surface.cpp`.

## Supervisor Active Recheck

- The active user instruction assigns Agent-B012 to UID `00039T`, report-only, with no by-* doc or `by-memory/-coverage-report.md` edits.
- The assigned item does not require split repair before reporting. The exact body is already a single modeled function from `0x005583a0` through `0x0055867a`, with `0xcc` padding before and after.
- No source-bearing child inside this exact target needs a new child page. Internal branch targets are all inside the body and are control flow, not subfunctions.
- The current target page already carries the earlier B012 source-quality detail. The only by-* stale-current issue found in this repair is the historical sentence saying MCP was unavailable; current MCP proof is now in this report for supervisor decision.

## Inference Research Guidance Check

The by-structure rules separate direct semantic ownership from generated output routing. They also allow blank formal C++ after the numeric gate when the route, names, source shape, or liveness are not good enough for final output. That distinction matters here:

- Direct receiver evidence: the code is a `thiscall`-shaped method over the root ScreenPane presentation object. Sibling direct callers to `0x00557140` load [UID:0000S7][g_pScreenPane](../../../../by-global/g_pScreenPane.md) into `ecx`, and this target uses the same root presentation fields.
- Source bucket evidence: [UID:0000OC][Surface](../../../../by-file/Surface.md), [UID:0001G6][SurfacePresentation](../../../../by-memory/0x00557140-0x00559aef.SurfacePresentation.md), and [UID:0000TN][SurfaceRenderCallbackTable](../../../../by-global/SurfaceRenderCallbackTable.md) intentionally keep the DirectDraw/callback/display-presentation helpers in `render/Surface.cpp`.
- Safe implementation direction: keep current Surface owner/emitter in this one-target pass to avoid a one-off metadata change that would conflict with sibling `0x00557140`, but document the ScreenPane receiver and recommend a family-wide owner audit if the supervisor wants strict class ownership.

Existing documentation was treated as a lead, not proof. The local PE checks confirm the key B001 claims about body bounds, no direct entry route, shared state with `0x00557140`, display blit calls, callback slot use, and ScreenPane field interaction.

## Heuristic / Inference Reanalysis And Validation

### Helper name and role

- Issue: current title `SurfaceDrawTilePresentation` is useful but not the strongest source-facing name.
- Evidence checked: target disassembly, [UID:0000OC][Surface](../../../../by-file/Surface.md), [UID:0000TN][SurfaceRenderCallbackTable](../../../../by-global/SurfaceRenderCallbackTable.md), generated empty marker, and sibling [UID:00039P][SurfaceRenderPresentation](../../../../by-memory/0x00557140-0x00557377.SurfaceRenderPresentation.md).
- Best inference: `DrawTileSurface`, with `ScreenPane::DrawTileSurface(short frameCount)` as the method-shaped spelling when receiver ownership is discussed.
- Rejected alternatives:
  - `SurfaceDrawTilePresentation`: keep as documentation filename, but it reads like a report title rather than source.
  - `UpdateFadeState`: wrong family; this helper is presentation/blit/traversal, not the help-pane fade state target from the previous assignment.
  - `MapPane::DrawTileSurface`: tile output can include map content, but no MapPane field, constructor, or direct caller signal appears.
  - `Surface::DrawTileSurface`: possible only if "Surface" is treated as the source module, not as a proven class receiver.

### Source owner and emitter placement

- Issue: current metadata uses [UID:0000OC][Surface](../../../../by-file/Surface.md), while the code is method-shaped on ScreenPane state.
- Evidence for Surface: the body calls `UpdateSurfaceInfo` at `0x004b9820`, Surface render callback slot `dword_69B40C`, `EndPaint` at `0x004b98c0`, [UID:0003A4][BlitSurfaceToDisplay](../../../../by-memory/0x005595d0-0x00559a0f.BlitSurfaceToDisplay.md), browser-sync presentation glue, and final `0x00557140` render-presentation helper. [UID:0000OC][Surface](../../../../by-file/Surface.md) lists `DrawTileSurface` as a proposed Surface.cpp content item and routes the generated marker to `NexusTK/render/Surface.cpp`.
- Evidence for ScreenPane: the receiver fields are ScreenPane/root presentation fields. The sibling `0x00557140` direct callers load `dword_67A7CC` / [UID:0000S7][g_pScreenPane](../../../../by-global/g_pScreenPane.md) into `ecx`; this target reads and writes the same `+0x59c`, `+0x59e`, `+0x5a0`, `+0x5a4`, `+0x5ac`, and `+0x5b0` fields.
- Decision: keep current Surface owner/emitter for this one-target implementation because current project structure explicitly treats `0x00557140-0x00559aef` generic presentation helpers as the `Surface.cpp` source-boundary bucket. Add a strong caveat that the C++ receiver is ScreenPane-shaped and that a future family-wide pass should not evaluate `00039T` alone.

### Field names and state roles

Best-supported field interpretations:

| Offset | Best descriptive name | Evidence |
| --- | --- | --- |
| `this+0x18` | `m_activeSurface` or active render surface pointer | Passed to `UpdateSurfaceInfo`, browser sync `0x0046bfd0`, and display blit; same role in `0x00557140`. |
| `this+0x20` | active pixel/source buffer pointer | Passed to `dword_69B40C` with area and mode. |
| `this+0x2c/+0x30/+0x34/+0x38` | active surface bounds or source rectangle edges | Width/height are computed as `(+0x38 - +0x30) * (+0x34 - +0x2c)` before block transfer. |
| `this+0x108` | display/front surface handle or presentation surface slot | Passed to virtual surface calls and `BlitSurfaceToDisplay` in both direct and traversal paths. |
| `this+0x59c` | presentation dirty/changed flag | Set before presentation, cleared before traversal, tested after `0x00559410`, and ORed inside traversal helper. |
| `this+0x59e` | random/shake X offset | Set to `rand() % 10` per loop iteration; later zeroed together with `+0x5a0`. |
| `this+0x5a0` | random/shake Y offset | Set to `rand() % 40` per loop iteration; paired with `+0x59e`. |
| `this+0x5a4` | presentation mode/state | Values decide direct block transfer versus traversal/clipped blit path. Transition helpers set related states. |
| `this+0x5ac` | block transfer/effect mode | Passed as the third argument to callback slot `dword_69B40C`; transition helpers set `0x18` or `0`. |
| `this+0x5b0` | force full redraw flag | Constructor initializes it, both presentation helpers test it before optional full-screen `SetRect`, and both clear it after redraw/browser handling. Tiny setter `0x00558680` sets it. |

Rejected field names:

- `MapPane` tile fields: no evidence this receiver is a MapPane.
- generic `unknown flags`: too weak; exact local behavior supports presentation dirty/mode/force-redraw roles.
- final public field names: not proven. Use descriptive names in documentation until a ScreenPane layout pass finalizes member names.

### Global and placeholder names

| Placeholder | Best-supported name | Status |
| --- | --- | --- |
| `sub_5583A0` | `DrawTileSurface` / `ScreenPane::DrawTileSurface(short frameCount)` | Inferred descriptive source name. No original symbol proof. |
| `dword_67AB20` | [UID:0000QS][g_pDirectX](../../../../by-global/g_pDirectX.md) / `DirectX *g_pDirectX` | Resolved. Body reads it at `0x005583d0` and obtains a DirectDraw-style interface pointer at `+0x04`. |
| `word_66DA94` | [UID:0000SU][g_screenWidth](../../../../by-global/g_screenWidth.md) | Resolved. Used for full-screen/clipped rectangle bounds. |
| `word_66DA98` | [UID:0000ST][g_screenHeight](../../../../by-global/g_screenHeight.md) | Resolved. Used with `g_screenWidth`. |
| `dword_69B40C` | [UID:0000TN][SurfaceRenderCallbackTable](../../../../by-global/SurfaceRenderCallbackTable.md) slot 11, descriptive `g_pfnBlockTransferSurface` / `SurfaceBlockTransferProc` | Resolved at role level, final typedef spelling open. |
| `dword_67AB28` | [UID:0000PO][g_activeBrowserControlPane](../../../../by-global/g_activeBrowserControlPane.md) | Resolved. Presentation consumer only, not owner. |
| `0x004b9820` | Surface paint/update helper, currently `UpdateSurfaceInfo` | Dependency. |
| `0x004b98c0` | `EndPaint` | Dependency. |
| `0x00559410` | [UID:0003A3][ScreenPanePresentationTraversal](../../../../by-memory/0x00559410-0x005595ca.ScreenPanePresentationTraversal.md) | ScreenPane traversal dependency. |
| `0x005595d0` | [UID:0003A4][BlitSurfaceToDisplay](../../../../by-memory/0x005595d0-0x00559a0f.BlitSurfaceToDisplay.md) | Surface display blit dependency. |
| `0x0046bfd0` | browser active-surface sync helper | Browser dependency, final source name still open outside this target. |
| `_rand` at `0x005de5a5` | CRT `rand` | Used for shake offsets. |
| `0x60d43c`, `0x60d47c`, `0x60d3cc` | `SetRect`, `GetClientRect`, `RedrawWindow` imports | Confirmed by call shape and sibling docs. |

### Caller/reachability hypothesis

- Local PE scan found no direct external rel32 call/jump into `0x005583a0-0x0055867a`, no absolute pointer into the range anywhere in the file, and no direct branch into the range from outside. All detected branch targets into the range are internal control flow.
- Existing docs also report no IDA direct caller xrefs to the function start.
- Best inference: this is source-authored retained code with no recovered live route, likely a private/prototype presentation helper retained by the linker because it was in the same object or referenced in a way not visible in ordinary direct xrefs. It may have been a no-longer-used tile shake/presentation path.
- Rejected alternatives:
  - Padding or data: false; the body is a complete SEH-framed function with calls, state updates, and `ret 4`.
  - Compiler-generated thunk: false; the body contains substantive presentation logic.
  - Callback-table target: false; callback table slot 11 points to `0x004bee40` / `0x004c4790`, not to `0x005583a0`.

### Split/range decision

- Keep exact function range `0x005583a0-0x0055867a`.
- Predecessor `0x00558391-0x005583a0` remains padding after [UID:0001G9][ScreenshotCaptureAndProof](../../../../by-memory/0x00557aa0-0x00558391.ScreenshotCaptureAndProof.md).
- Successor `0x0055867a-0x00558680` remains padding before [UID:00039U][UnresolvedPresentationFlagSetter](../../../../by-memory/0x00558680-0x00558688.UnresolvedPresentationFlagSetter.md).
- No merge into [UID:0001G6][SurfacePresentation](../../../../by-memory/0x00557140-0x00559aef.SurfacePresentation.md); the aggregate is a mixed container and exact children carry ownership.
- No split inside `00039T`; branch subregions are the same function's direct-mode, traversal-mode, redraw, cleanup, and EH-cleanup blocks.

### Final C++ blocker

- The target satisfies numeric minimum eligibility: `RECONSTRUCTABLE:TRUE`, nonblank `EMITTER_UIDS:0000OC`, generated route to `NexusTK/render/Surface.cpp`, and average score above 85.
- It still fails source-quality readiness. The no-entry route, no pointer route, no direct caller route, current empty generated marker, and unresolved family-level Surface-vs-ScreenPane method boundary make final-output C++ unsafe. Do not populate formal C++ in the target until a route is proven or a family-wide presentation-source decision is accepted.

## Evidence Standards Used

Evidence used in this pass:

- Existing by-* docs: target page, Surface file, ScreenPane file/class, SurfacePresentation aggregate, `SurfaceRenderCallbackTable`, `BlitSurfaceToDisplay`, `ScreenPanePresentationTraversal`, transition/flag setter pages, `g_pDirectX`, `g_pScreenPane`, and `g_activeBrowserControlPane`.
- Generated reports: `auto-generated/-ag-research-tracker.md`, `auto-generated/-ag-memory-coverage.md`, generated `NexusTK/render/Surface.cpp`, and read-only manual `by-memory/-coverage-report.md`.
- Prior B reports and trackers searched as leads with `rg "00039T|SurfaceDrawTilePresentation|0x005583a0|DrawTileSurface"` under `tools/leaser/Agents` and `executed-b-agent-research`: the active de-executed B012 report, B001 `0001G6-SurfacePresentation.md`, B012 `0003A3-ScreenPanePresentationTraversal-source-quality.md`, and later Surface/ScreenPane support reports cite UID00039T as dependency/family context.
- Local binary evidence from the prior accepted report remains valid as historical support: `NexusTK.exe` image base `0x00400000`, MD5 `4247e04e20b65d6414c7238aa8ff5515`, Capstone 5.0.7 disassembly and raw reference scans.
- Current IDA MCP evidence is mandatory and was refreshed for this repair through `http://127.0.0.1:13337/mcp` using `initialize`, `tools/list`, `idb_list`, `server_health`, `lookup_funcs`, `xrefs_to`, `get_bytes`, `decompile`, `callees`, `find`, and `find_bytes`. The active session is `supervisor_recovery_20260705`, `idb_list` count is `1`, and `server_health` status is `ok`.

## Evidence Checked

- MCP safe flow: `initialize` returned server `ida-pro-mcp` version `1.0.0`, protocol `2025-06-18`; `tools/list` returned 65 tools and confirmed the narrow tools used in this repair.
- MCP session: `idb_list` returned one active session `supervisor_recovery_20260705`, IDB `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, filename `NexusTK.exe.i64`, worker PID `19604`, `is_analyzing:false`.
- MCP health: `server_health(database=supervisor_recovery_20260705)` returned `status: ok`, module `NexusTK.exe`, input path `C:\Users\admin\Desktop\Clone\NexusTK\NexusTK.exe`, imagebase `0x400000`, `auto_analysis_ready:true`, `hexrays_ready:true`, `strings_cache_ready:true`, string cache size `2067`.
- MCP lookup: `lookup_funcs` for `0x005583a0`, `0x0055867a`, `0x00558680`, `0x00557140`, `0x00559410`, `0x005595d0`, `0x004b9820`, `0x004b98c0`, and `0x0046bfd0`.
- MCP references: `xrefs_to 0x005583a0 limit=25`, `find` code/data/immediate references to `0x005583a0`, and `find_bytes` pointer patterns `a0 83 55 00` and `a0 83 15 00`.
- MCP bytes/decompile/callees: `get_bytes` for `0x00558390`, `0x005583a0`, and `0x00558660`; `decompile 0x005583a0 include_addresses=false`; `callees 0x005583a0 limit=80`.
- Current docs checked: target `by-memory/0x005583a0-0x0055867a.SurfaceDrawTilePresentation.md`, `by-file/Surface.md`, `by-file/ScreenPane.md`, `by-class/ScreenPane.md`, `by-global/SurfaceRenderCallbackTable.md`, `by-memory/0x00557140-0x00559aef.SurfacePresentation.md`, `by-memory/0x005595d0-0x00559a0f.BlitSurfaceToDisplay.md`, and `by-memory/0x00559410-0x005595ca.ScreenPanePresentationTraversal.md`.
- Current generated/read-only state checked: `auto-generated/-ag-research-tracker.md`, `auto-generated/-ag-memory-coverage.md`, generated `auto-generated/NexusTK/render/Surface.cpp`, and manual `by-memory/-coverage-report.md`.

## IDA MCP / Local PE Facts

Current MCP pass (`supervisor_recovery_20260705`) supersedes the old report-only note that MCP was unavailable. Local PE evidence from the earlier accepted report remains consistent with MCP and is retained as supporting detail.

- `lookup_funcs` reports `0x005583a0` as `sub_5583A0`, size `0x2da`; `0x0055867a` is not a function; `0x00558680` is `sub_558680`, size `0x8`.
- Related lookups: `0x00557140` is `sub_557140`, size `0x237`; `0x00559410` is `sub_559410`, size `0x1ba`; `0x005595d0` is `sub_5595D0`, size `0x43f`; `0x004b9820` is `sub_4B9820`, size `0x98`; `0x004b98c0` is `sub_4B98C0`, size `0x2e`; `0x0046bfd0` is `sub_46BFD0`, size `0x10f`.
- `xrefs_to 0x005583a0` returned `xref_count:0`, `more:false`, message `No cross-references to this address`.
- `find` returned zero `code_ref`, zero `data_ref`, and zero `immediate` matches for `0x005583a0`.
- `find_bytes` returned zero matches for both direct VA pointer bytes `a0 83 55 00` and RVA-style bytes `a0 83 15 00`.
- `decompile 0x005583a0` succeeded with 130 code lines and contains `_rand`, calls/references to `0x00559410`, `0x005595d0`, `0x00557140`, and the expected `int __thiscall sub_5583A0(int this, unsigned __int16 a2)` shape.
- `callees 0x005583a0` returned `_rand`, `0x004b9820`, external `unk_69B40C`, `0x004b98c0`, `0x0046bfd0`, `0x005595d0`, `0x00554680`, `0x00559410`, `0x00554ae0`, `SetRect`, `0x004f4a90`, `GetClientRect`, `RedrawWindow`, `0x00557140`, and `@__security_check_cookie@4`.

### Function and bytes

- MCP `get_bytes` and prior local PE disassembly confirm `0x005583a0` starts with a normal prologue and SEH setup: `55 8b ec 6a ff 68 52 73 60 00 ...`, corresponding to `push ebp`, `mov ebp, esp`, exception registration, local stack allocation, saved `ebx/esi/edi`.
- Body size: `0x2da` / 730 bytes, matching `0x005583a0-0x0055867a`.
- Return: `ret 4` at `0x00558663`, with an EH cleanup/alternate path ending in `jmp 0x00558619` at `0x00558678`.
- Preceding bytes: MCP byte window at `0x00558390` shows `0x00558391-0x0055839f` are `0xcc` padding before the `0x005583a0` prologue.
- Following bytes: MCP byte window at `0x00558660` shows `0x0055867a-0x0055867f` are `0xcc` padding before the tiny `0x00558680` setter (`c6 81 b0 05 00 00 01 c3`).

### Control flow and behavior

- `ecx` is saved into `esi` and used as the receiver throughout.
- The single stack argument is read as a word from `[ebp+8]`. The function returns with `ret 4`. The value is converted to a loop count in `ebx`.
- If the count is non-positive, the helper skips directly to final state reset and calls sibling `0x00557140`.
- Per iteration, it sets `this+0x59e = rand() % 10` and `this+0x5a0 = rand() % 40`, sets `this+0x59c = 1`, and calls a DirectDraw-style virtual at `[g_pDirectX->+4]->vtable+0x58`.
- Mode path:
  - If `this+0x5a4 == 1`, it initializes a region object, clears `this+0x59c`, calls [UID:0003A3][ScreenPanePresentationTraversal](../../../../by-memory/0x00559410-0x005595ca.ScreenPanePresentationTraversal.md), checks whether traversal marked `this+0x59c`, clips the dirty rectangle to `g_screenWidth/g_screenHeight`, optionally expands to full screen when `this+0x5b0 != 0`, calls [UID:0003A4][BlitSurfaceToDisplay](../../../../by-memory/0x005595d0-0x00559a0f.BlitSurfaceToDisplay.md), then destroys the temporary region.
  - If `this+0x5a4` is `2` or `3`, it builds a full-screen rectangle from `g_screenWidth/g_screenHeight`, invokes a surface virtual on `this+0x18`, calls `UpdateSurfaceInfo`, dispatches slot `dword_69B40C` with the active pixel buffer, area, and `this+0x5ac`, calls `EndPaint`, syncs the active browser pane if present, and blits to display.
  - Other mode values skip the core present path and proceed to browser redraw / flag clear / loop decrement.
- After each iteration it redraws the hosted browser window when [UID:0000PO][g_activeBrowserControlPane](../../../../by-global/g_activeBrowserControlPane.md) is non-null, then clears `this+0x5b0`, decrements the loop counter, and repeats.
- Final state reset sets `this+0x59c = 1`, zeroes the random offsets at `this+0x59e/+0x5a0`, calls the same DirectDraw-style virtual, then calls `0x00557140`.

### Local PE no-entry-route checks

- Current MCP no-entry checks agree with the prior local PE scan: no direct IDA xrefs, no `find` code/data/immediate refs, and no VA/RVA pointer-byte hits to the function entry.
- Exact start reference scan:
  - Direct calls to `0x005583a0`: none.
  - Direct jumps to `0x005583a0`: none.
  - Absolute dword pointer to `0x005583a0`: none.
  - rel32 immediates targeting `0x005583a0`: none.
- Range reference scan:
  - Absolute dword values into `0x005583a0-0x0055867a`: zero.
  - Branch targets into `0x005583a0-0x0055867a`: 25 detected, all internal; zero external branch targets into the body.
- Positive controls from the same scan:
  - `0x00557140` has direct call refs such as `0x0046ae22`, `0x0046d445`, `0x0046e9c5`, `0x00494ff5`, `0x0049deb1`, and many more.
  - `0x00559410` has calls from `0x00556e9c`, `0x00556f0c`, `0x00557237`, `0x005584f5`, `0x00559258`, and `0x00559308`.
  - `0x005595d0` has calls from `0x00557211`, `0x00557301`, `0x005584cf`, and `0x005585bf`.

### Data/global facts

Local absolute reference scan confirms these project-level counts:

| Address | Role | Direct absolute refs in `.text` |
| --- | --- | ---: |
| `0x0066da94` | `g_screenWidth` | 98 |
| `0x0066da98` | `g_screenHeight` | 96 |
| `0x0067ab20` | `g_pDirectX` | 19 |
| `0x0067ab28` | `g_activeBrowserControlPane` | 24 |
| `0x0069b40c` | Surface callback slot 11 | 5 |
| `0x0060d43c` | `SetRect` import slot | 10 |
| `0x0060d47c` | `GetClientRect` import slot | 20 |
| `0x0060d3cc` | `RedrawWindow` import slot | 6 |

## Claim And Incorporation Ledger

| Claim ID | Claim | Confidence | Evidence | Destination doc/section | Action | Verification state |
| --- | --- | --- | --- | --- | --- | --- |
| C-00039T-01 | The active report is no longer status-locked at top level; prior `needs-revalidation` / `target_uid_unknown: 00039T` headers are historical only for this de-executed repair copy. | High | Supervisor override plus preserved validator footer events `000000004167` and `000000006857`. | This report header and `Supporting Research`; validator history footer unchanged. | historicalize | already-present |
| C-00039T-02 | UID00039T currently exists at `by-memory/0x005583a0-0x0055867a.SurfaceDrawTilePresentation.md` with metadata `COMPLETION:86`, `CONFIDENCE:88`, `CANONICAL_OWNER:0000OC`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000OC`, and blank formal C++. | High | Target header verified after callback and scoped validator `000000006867`; generated `Surface.cpp` still has UID00039T empty marker at `86/88`. | Target metadata/header and target formal C++ marker. | already-present | already-present |
| C-00039T-03 | Supervisor validator command `000000006859` repaired the UID/path mapping and current callback validator `000000006867` validated the target, with remaining sibling `missing_ref_uid` warnings for `00039P`, `0003A3`, `0003A4`, and `00039U`. | High | Goal.md command metadata; callback validator `000000006867`, timestamp `2026-07-05T07:21:02-04:00`, exit `0`, `ok:1`; generated `Surface.cpp` header command-id `000000006867`. | Target evidence/current-state history; this report `Supporting Research`, `Validator Results`, and checklist. | incorporate | applied |
| C-00039T-04 | Current MCP session `supervisor_recovery_20260705` proves `0x005583a0` is modeled `sub_5583A0`, size `0x2da`; `0x0055867a` is not a function and `0x00558680` is the adjacent `sub_558680` setter. | High | MCP `idb_list`, `server_health`, and `lookup_funcs` results; target `Reachability And No-Entry Evidence` now records these facts. | Target IDA/MCP evidence section; stale "MCP unavailable" prose historicalized. | incorporate | applied |
| C-00039T-05 | Current MCP and prior local PE evidence find no ordinary entry route to `0x005583a0`: zero xrefs, zero code/data/immediate refs, zero VA/RVA pointer-byte hits, no direct call/jump/pointer route, and no external branch into the body. | High | MCP `xrefs_to`, `find`, `find_bytes`; prior local PE branch/pointer scan; target reachability section and final C++ proof now include current MCP proof. | Target reachability/no-entry evidence and formal no-C++ proof. | incorporate | applied |
| C-00039T-06 | The body is source-authored presentation logic, not padding or compiler glue: 730-byte `ret 4` `thiscall`-shaped function, frame/count loop, shake offsets `+0x59e/+0x5a0`, mode field `+0x5a4`, force-redraw clear `+0x5b0`, traversal `0x00559410`, blit `0x005595d0`, final `0x00557140`, browser redraw, and callback slot `dword_69B40C`. | High | MCP decompile/callee list; current target behavior section; prior local PE details. | Target behavior, field/global roles, direct xref/callee inventory. | already-present | already-present |
| C-00039T-07 | Surface remains the current owner/emitter bucket, while ScreenPane is the semantic receiver/state owner; strict ownership cleanup must evaluate UID00039T with UID00039P/0003A3/0003A4 and transition helpers, not move this one child alone. | High | Target current prose; `by-file/Surface.md` UID00039T row; `by-file/ScreenPane.md` and `by-class/ScreenPane.md` receiver caveats. | Target ownership section; support docs `by-file/Surface.md`, `by-file/ScreenPane.md`, `by-class/ScreenPane.md`. | already-present | already-present |
| C-00039T-08 | Formal C++ should remain blank because source liveness and family-level Surface-vs-ScreenPane method placement remain unresolved despite reconstructable source-authored logic. | High | Blank target `RECONSTRUCTION_CPP` block verified after callback; generated `Surface.cpp` empty marker; no-entry evidence. | Target formal C++ marker and `First-Draft C++ Recommendation`. | already-present | already-present |
| C-00039T-09 | `BlitSurfaceToDisplay`, `ScreenPanePresentationTraversal`, and `SurfaceRenderCallbackTable` support pages already carry same-or-greater UID00039T caller/slot evidence; no support edit is needed for this report repair. | Medium-high | Support doc searches for UID00039T / `0x005583a0`; current support rows and changes. | Support docs: `by-memory/0x005595d0-0x00559a0f...`, `by-memory/0x00559410-0x005595ca...`, `by-global/SurfaceRenderCallbackTable.md`. | already-present | already-present |
| C-00039T-10 | Manual coverage/tracker edits are supervisor-owned and out of scope for B012 report repair; generated tracker/memory coverage already list UID00039T and callback validator regenerated `Surface.cpp`. | High | Assignment boundary; generated tracker/memory coverage rows; no `by-memory/-coverage-report.md` edit by B012; generated `Surface.cpp` command-id `000000006867`. | Exact manual coverage/tracker text section; no generated/manual coverage file edits. | not-applicable | excluded-with-reason |

## Positive Evidence Summary

- Current MCP confirms an exact modeled function at `0x005583a0`, size `0x2da`, and a clean successor boundary before the `0x00558680` setter.
- Current MCP decompilation confirms the `thiscall` receiver, one unsigned 16-bit argument, `_rand`-based shake offsets, mode branching, traversal/blit/callback dependencies, browser redraw side effects, and final sibling presentation call.
- Current target and support docs already contain the key source-quality conclusion: Surface is the current presentation-bucket owner/emitter, but the receiver/state are ScreenPane-shaped and must be treated as a family-level caveat.
- Generated outputs are current to supervisor validator command `000000006859`: research tracker lists UID00039T at `86/88`, memory coverage routes it to `auto-generated/NexusTK/render/Surface.cpp`, and generated `Surface.cpp` contains only the intended empty emitter marker.
- Existing support pages agree on dependencies: `ScreenPanePresentationTraversal` records `0x005584f5` as a caller, `BlitSurfaceToDisplay` records callers from `0x00557140` and `0x005583a0`, and `SurfaceRenderCallbackTable` records slot 11 as a dependency called by the retained helper rather than a route to it.

## Function / Child Inventory

| Range / Item | UID / Path | Role | Reconstructable | Direct Parent | Score | Status |
| --- | --- | --- | --- | --- | --- | --- |
| `0x00558391-0x005583a0` | `-ignored` coverage row needed | Padding between screenshot cluster and target | false/ignored | none | `100/strong` | keep padding |
| `0x005583a0-0x0055867a` | [UID:00039T][SurfaceDrawTilePresentation](../../../../by-memory/0x005583a0-0x0055867a.SurfaceDrawTilePresentation.md) | Retained no-entry ScreenPane-shaped presentation helper, current Surface.cpp source bucket | true | current `0000OC`; semantic receiver caveat `0000CB` | recommend `86/88` | keep exact page |
| `0x0055867a-0x00558680` | `-ignored` coverage row needed | Padding before tiny ScreenPane flag setter | false/ignored | none | `100/strong` | keep padding |
| `0x00558680-0x00558688` | [UID:00039U][UnresolvedPresentationFlagSetter](../../../../by-memory/0x00558680-0x00558688.UnresolvedPresentationFlagSetter.md) | Tiny `this+0x5b0 = 1` ScreenPane flag setter | true | [UID:0000CB][ScreenPane](../../../../by-class/ScreenPane.md) | `86/88` | sibling dependency |

## Direct Xref / Caller Inventory

| Address / Item | Xref / Caller / Callee | Meaning |
| --- | --- | --- |
| external to `0x005583a0` | none found | No direct live route to target start. |
| pointer into `0x005583a0-0x0055867a` | none found | No vtable/function-pointer/literal-pointer route in local PE. |
| `0x00558486` | call `0x004b9820` | Surface metadata/update helper. |
| `0x005584a4` | call `[0x0069b40c]` | Surface block-transfer callback slot 11. |
| `0x005584af` | call `0x004b98c0` | Surface `EndPaint` helper. |
| `0x005584c1`, `0x00558581` | call `0x0046bfd0` | Browser active-surface sync when active browser control exists. |
| `0x005584cf`, `0x005585bf` | call `0x005595d0` | Surface display blit helper. |
| `0x005584f5` | call `0x00559410` | ScreenPane traversal helper for dirty/clip path. |
| `0x00558643` | call `0x00557140` | Final call to sibling render presentation helper after resetting offsets. |
| `0x005585ad` | call `[0x0060d43c]` | `SetRect` import for full-screen forced redraw. |
| `0x005585f0` | call `[0x0060d47c]` | `GetClientRect` for browser HWND. |
| `0x0055860c` | call `[0x0060d3cc]` | `RedrawWindow` for browser HWND. |

## Documentation Evidence And IDA Status

Existing docs that support the conclusion:

- [UID:0001G6][SurfacePresentation](../../../../by-memory/0x00557140-0x00559aef.SurfacePresentation.md) lists `00039T` as a Surface draw/tile presentation child and records the mixed child inventory.
- [UID:0000OC][Surface](../../../../by-file/Surface.md) lists `DrawTileSurface` at `0x005583a0-0x0055867a` and groups presentation/minimap/display blit helpers in `render/Surface.cpp`.
- [UID:0000TN][SurfaceRenderCallbackTable](../../../../by-global/SurfaceRenderCallbackTable.md) names slot `0x0069b40c` / `dword_69B40C` as the block/surface transfer callback used by DrawTileSurface-style paths.
- [UID:0003A4][BlitSurfaceToDisplay](../../../../by-memory/0x005595d0-0x00559a0f.BlitSurfaceToDisplay.md) confirms its four callers are from `0x00557140` and `0x005583a0`.
- [UID:0003A3][ScreenPanePresentationTraversal](../../../../by-memory/0x00559410-0x005595ca.ScreenPanePresentationTraversal.md) confirms one caller is `0x005583a0`.
- [UID:00039U][UnresolvedPresentationFlagSetter](../../../../by-memory/0x00558680-0x00558688.UnresolvedPresentationFlagSetter.md) confirms all visible `+0x5b0` uses: constructor init, reads/clears in both presentation helpers, and setter at `0x00558680`.
- [UID:0003A0][ScreenPanePresentationTransitionHelpers](../../../../by-memory/0x00559200-0x00559359.ScreenPanePresentationTransitionHelpers.md) confirms `+0x5a4/+0x5ac` are ScreenPane transition fields feeding the presentation path.

Existing docs that are stale, incomplete, or supervisor-owned:

- Target page already contains the earlier behavior, no-entry, field/global, ScreenPane receiver caveat, and blank-C++ detail, but it still carries historical wording that MCP was unavailable during the prior pass. Current MCP evidence in this report supersedes that availability statement.
- Current `by-memory/-coverage-report.md` remains supervisor-owned and was not edited by B012. Generated tracker and memory coverage already list UID00039T after `000000006859`.
- Generated `auto-generated/NexusTK/render/Surface.cpp` has an empty marker for `00039T`; this is intentional until formal C++ is safe and is current to command `000000006859`.

## Ranked Ownership Analysis

### 1. Current [UID:0000OC] Surface source bucket

- Evidence for: Surface file already owns this presentation helper family; body calls Surface paint/update, callback slot 11, display blit, browser sync, and DirectDraw-related presentation helpers; generated route already lands in `NexusTK/render/Surface.cpp`.
- Evidence against: the function is `thiscall` on a ScreenPane/root presentation object, not a proven `Surface` class object.
- Decision: keep as current owner/emitter for this one-target pass, but document that it is a source-bucket decision rather than pure receiver ownership.

### 2. [UID:0000CB] ScreenPane class

- Evidence for: receiver fields are ScreenPane-root presentation fields; sibling `0x00557140` callers load `g_pScreenPane` into `ecx`; transition and force-redraw fields are initialized/used by ScreenPane docs; this function is method-shaped with `ret 4`.
- Evidence against: current project structure and Surface/ScreenPane docs intentionally keep generic Surface/presentation helpers outside `ScreenPane.cpp`; a one-off move of only `00039T` would leave sibling `00039P` and Surface docs inconsistent.
- Decision: strongest semantic receiver candidate and should be recorded. Do not change only this target unless the supervisor accepts a family-wide ScreenPane presentation-method reclassification.

### 3. [UID:0000NB] ScreenPane file

- Evidence for: file root owns root ScreenPane state and helper islands; it clears `86/85`.
- Evidence against: class [UID:0000CB] is narrower if moving by strict semantic owner; current source-boundary docs keep presentation helpers under Surface.
- Decision: secondary route behind ScreenPane class, not the current one-target recommendation.

### 4. [UID:0000L3] MapPane / [UID:00007Q] MapPane class

- Evidence for: tile wording and presentation output can include map content.
- Evidence against: no receiver, field, constructor, caller, or global evidence ties the body to MapPane. Surface and ScreenPane dependencies explain all observed behavior.
- Decision: reject.

### 5. [UID:0000IW] DirectX

- Evidence for: body reads `g_pDirectX` and uses DirectDraw-style virtual calls.
- Evidence against: DirectX is a service/singleton dependency, not owner of presentation policy.
- Decision: reject.

## Source Placement

Keep UID00039T in the current [UID:0000OC][Surface](../../../../by-file/Surface.md) source bucket and generated route `NexusTK/render/Surface.cpp` for this report. This is a project source-boundary placement, not proof that the receiver is a `Surface` class instance. The body is `thiscall` over the root ScreenPane presentation object and manipulates ScreenPane-shaped presentation fields; therefore any strict source move should be family-wide across the `0x00557140-0x00559aef` presentation cluster, not a one-off UID00039T change.

The callback scope was narrow and is now applied: target metadata and blank C++ marker were preserved, stale MCP-unavailable wording was historicalized with current `supervisor_recovery_20260705` MCP facts, and support docs were left unchanged because they already record the Surface bucket plus ScreenPane receiver caveat.

## Negative Evidence Summary

- No ordinary direct caller to `0x005583a0`.
- No direct jump to `0x005583a0`.
- No absolute pointer to `0x005583a0`.
- No absolute pointer into `0x005583a0-0x0055867a`.
- No external branch target into `0x005583a0-0x0055867a`; local branch targets are all internal.
- No evidence that callback table slot 11 targets this helper; slot 11 targets the compat/RGB565 block-transfer callbacks and this helper calls the slot.
- No MapPane-specific receiver evidence.
- No evidence that `g_activeBrowserControlPane` owns the target; browser state is a synchronization/redraw consumer.

## Open Questions With Attempted Resolution

| Open question | Resolution |
| --- | --- |
| What is `sub_5583A0`? | Source-authored, retained no-entry presentation helper best named `DrawTileSurface`; method-shaped spelling `ScreenPane::DrawTileSurface(short frameCount)` is the clearest receiver-aware name. |
| Is it live/reachable? | No direct route recovered. Treat as retained/no-entry source code, not padding. |
| Should C++ be emitted? | No. Empty emitter marker should remain intentional until a route or family-wide source decision is proven. |
| Is Surface ownership still valid? | Valid as the current project source-bucket/emitter convention. Not pure semantic receiver ownership. |
| Is ScreenPane the semantic owner? | Yes as receiver/state owner, but moving only this child would be inconsistent. Recommend documenting caveat and doing a family-level audit before changing metadata. |
| Does it need a split? | No. Exact modeled body with only internal control-flow blocks. |
| Are unresolved placeholders nameable? | Yes for `g_pDirectX`, `g_screenWidth`, `g_screenHeight`, `g_activeBrowserControlPane`, callback slot 11 role, imports, ScreenPane presentation fields, and helper roles. |

## First-Draft C++ Recommendation

Do not populate `RECONSTRUCTION_CPP CODE` for `00039T` yet.

Exact proof:

- The target is a complete source-authored body, but no external entry route is currently proven.
- Local PE exact-start scan found no direct `call`, no direct `jmp`, no rel32 branch/call, and no absolute pointer to `0x005583a0`.
- Local PE range scan found no absolute dword pointer into `0x005583a0-0x0055867a` and no external branch into the body range.
- Current MCP reports zero xrefs, zero code/data/immediate refs, and zero VA/RVA pointer-byte hits to the function start.
- The only current generated output is an empty marker in `auto-generated/NexusTK/render/Surface.cpp`, refreshed under validator command `000000006859`.
- The source shape is still family-sensitive: `Surface.cpp` is the current emitter bucket, while the receiver object and fields are ScreenPane-shaped. Emitting a `Surface::DrawTileSurface` free/member function would bake in an unproven class/source shape; emitting a `ScreenPane::DrawTileSurface` body would conflict with current target metadata and sibling Surface helper routing.

The formal C++ block is already blank in the target and should remain blank. A later callback should only update stale evidence wording if accepted; it should not add a standalone body.

## Final Recommendation

Gate 1 disposition: keep UID00039T source-ready as a reconstructable source-authored retained helper with no emitted C++ body. The report repair should be accepted with the current target metadata unchanged at `COMPLETION:86`, `CONFIDENCE:88`, `CANONICAL_OWNER:0000OC`, `RECONSTRUCTABLE:TRUE`, and `EMITTER_UIDS:0000OC`.

Implementation recommendation if the supervisor callback chooses to touch by-* docs: make a narrow target-only evidence refresh that historicalizes the old "IDA MCP unavailable" sentence and inserts the current MCP session/results. No score, owner, emitter, split, generated, manual coverage, or support-doc edit is required for this repair because the target and support docs already carry the accepted source-quality details at same-or-greater factual detail except for that stale MCP availability sentence.

## Recommended Target Doc Changes

Target: `by-memory/0x005583a0-0x0055867a.SurfaceDrawTilePresentation.md`.

- Metadata/header: already current at `COMPLETION:86`, `CONFIDENCE:88`, `CANONICAL_OWNER:0000OC`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000OC`; no score/header change recommended.
- Formal C++: already blank; keep the existing formal no-body block unchanged.
- Evidence/body: applied in callback. The target historicalizes the old IDA-MCP-unavailable sentence and adds current MCP proof: session `supervisor_recovery_20260705`, server health OK, `lookup_funcs` `sub_5583A0` size `0x2da`, no function at `0x0055867a`, adjacent `sub_558680` size `0x8`, zero xrefs/find refs/pointer hits, decompile success, callees to `_rand`, `0x004b9820`, `unk_69B40C`, `0x004b98c0`, `0x0046bfd0`, `0x005595d0`, `0x00559410`, Win32 imports, and `0x00557140`.
- Keep existing behavior, field/global roles, no-entry proof, Surface-bucket/ScreenPane-receiver caveat, rejected alternatives, split/range decision, and blank-C++ proof.
- Optional changes history note: record supervisor validator command `000000006859` only if the target page maintains revalidation/change-history prose; do not add validator-owned registry details to unrelated sections.

## Recommended Support Doc Changes

- [UID:0000OC][Surface](../../../../by-file/Surface.md): no edit required. Current row for UID00039T already says retained no-entry `DrawTileSurface`, ScreenPane receiver caveat, callback slot 11, traversal/display-blit dependencies, browser sync/redraw, and blank formal C++ until an entry route or family placement is proven.
- [UID:0000NB][ScreenPane](../../../../by-file/ScreenPane.md): no edit required. Current file-level prose already records UID00039T as Surface-routed under current convention while `ecx` and `+0x59c/+0x59e/+0x5a0/+0x5a4/+0x5ac/+0x5b0` are ScreenPane-shaped, and calls for family-wide audit before strict owner cleanup.
- [UID:0000CB][ScreenPane](../../../../by-class/ScreenPane.md): no edit required. Current class-level prose already records the same receiver/state caveat and keeps UID00039T out of the ScreenPane method table until a family-wide owner decision is proven.
- [UID:0000TN][SurfaceRenderCallbackTable](../../../../by-global/SurfaceRenderCallbackTable.md): no edit required. Current slot-11 note already names UID00039T as a caller/dependency and rejects a callback-table-target route to `0x005583a0`.
- [UID:0003A3][ScreenPanePresentationTraversal](../../../../by-memory/0x00559410-0x005595ca.ScreenPanePresentationTraversal.md) and [UID:0003A4][BlitSurfaceToDisplay](../../../../by-memory/0x005595d0-0x00559a0f.BlitSurfaceToDisplay.md): no edit required; both already record caller evidence from `0x005583a0`.
- Aggregate/support pages and manual coverage are no-edit in this report repair. Remaining `missing_ref_uid` warnings for `00039P`, `0003A3`, `0003A4`, and `00039U` are validator/reference-state follow-up, not a B012 by-* edit authorization.

## Score And Metadata Recommendation

- Target score: keep current `COMPLETION:86`, `CONFIDENCE:88`.
- Owner/emitter: keep current `CANONICAL_OWNER:0000OC`, `EMITTER_UIDS:0000OC`.
- Reconstructable: keep `RECONSTRUCTABLE:TRUE`.
- Formal C++: keep blank.
- Rationale: completion remains under 90 because the original source qualifier, external entry route, and family-level Surface-vs-ScreenPane placement are unresolved. Confidence remains 88 because MCP and local evidence agree on bounds, behavior, no-entry state, and support dependencies, but the no-entry/source-placement caveat is still real.

## Exact Manual Supervisor-Owned Coverage Or Tracker Text

Placement context: under the corrected [UID:0001G6][SurfacePresentation](../../../../by-memory/0x00557140-0x00559aef.SurfacePresentation.md) nested block, after the padding row for `0x00558391-0x005583a0` and before the padding row for `0x0055867a-0x00558680`.

Current generated tracker and memory coverage already list UID00039T after supervisor validator command `000000006859`. B012 did not edit manual coverage. If the supervisor still needs manual `by-memory/-coverage-report.md` text, use this updated wording:

```markdown
        - [UID:00039T][0x005583a0-0x0055867a.SurfaceDrawTilePresentation](by-memory/0x005583a0-0x0055867a.SurfaceDrawTilePresentation.md) 0x005583a0-0x0055867a | function | SurfaceDrawTilePresentation : reconstructable : 86% : strong : B012 source-quality revalidation keeps the current Surface owner/emitter [UID:0000OC](by-file/Surface.md) as the existing `render/Surface.cpp` presentation-bucket route, but documents the method-shaped ScreenPane receiver caveat; current MCP session `supervisor_recovery_20260705` and prior local PE evidence confirm a 730-byte `ret 4` `DrawTileSurface`-style helper that loops over a frame/count argument, randomizes presentation shake offsets `+0x59e/+0x5a0`, branches on ScreenPane presentation mode `+0x5a4`, dispatches Surface callback slot `dword_69B40C`, calls traversal `0x00559410`, display blit `0x005595d0`, browser sync/redraw helpers, and clears force-redraw flag `+0x5b0`; placeholders are resolved to `g_pDirectX`, `g_screenWidth`, `g_screenHeight`, `g_activeBrowserControlPane`, and Surface callback slot 11, while formal C++ remains intentionally blank because MCP/local evidence finds no direct caller, no pointer into the body, and no external branch route to the retained helper.
```

## Follow-Up Actions

- Supervisor: perform Gate 2 verification against the target/report and then run the supervisor-owned execute-report lifecycle if satisfied.
- Implementation state: target score/owner/emitter/C++ state was preserved, the accepted target evidence refresh was applied, and scoped validation completed. The exact coverage row remains supervisor-owned only if manual coverage remains desired.
- Future B research: if strict current `CANONICAL_OWNER` semantics are enforced, audit whether `0x00557140` and `0x005583a0` should both move to [UID:0000CB][ScreenPane](../../../../by-class/ScreenPane.md) while still depending on Surface/GrafPort helpers, or whether the project will retain a documented exception for `Surface.cpp` presentation methods with a ScreenPane receiver.

## Confidence

- Recommendation confidence: `high` for no split/no merge, no formal C++, field/global/helper role names, and current Surface emitter route.
- Score confidence: current `86/88` is still appropriate. Completion remains below 90 because final C++, final class qualifier, and original source-file boundary are unresolved. Confidence can remain 88 because current MCP, local PE evidence, and existing docs agree on bounds, behavior, and negative reachability.
- Remaining uncertainty: exact original source qualifier and why the retained helper has no recovered caller/pointer route.

## Validator Results

- Historical supervisor validator command incorporated: `000000006859`, timestamp `2026-07-05T07:01:25-04:00`, command `python .\tools\validator.py --mode file --file by-memory/0x005583a0-0x0055867a.SurfaceDrawTilePresentation.md --apply --queue-timeout 240`, exit `0`, `ok: 1`. Effects included `path_update`, `completion_update 86`, `confidence_update 88`, `canonical_owner_update 0000OC`, autogen registry updates, projected stats update, and `generated_refresh: deferred`.
- B012 callback validator command: `python .\tools\validator.py --mode file --file by-memory\0x005583a0-0x0055867a.SurfaceDrawTilePresentation.md --apply --queue-timeout 240`, run from `E:\NTK\GhidraBridge\source-3\project-documentation`.
- B012 callback validator result: command_id `000000006867`, command_timestamp `2026-07-05T07:21:02-04:00`, process exit `0`, `ok: 1`.
- B012 callback validator warnings: `missing_ref_uid: 15`, with visible repeated sibling warnings for `00039P`, `0003A3`, `0003A4`, and `00039U`, plus five suppressed rows. These are the same sibling reference-state class already accepted by Gate 1; no warning says UID00039T itself is missing.
- B012 callback validator side effects: `projected_stats_update: 1`, `stats_incremental_noop: 1`, `stats_incremental_noop 00039T project-level/-auto-completion-stats.md file is not present in generated stats lists`, and `generated_refresh: deferred` with generated_refresh_command_id `000000006867`, generated_refresh_timestamp `2026-07-05T07:21:02-04:00`.
- Generated refresh verification: `auto-generated/NexusTK/render/Surface.cpp` now has validator-command-id `000000006867`, `validator-refreshed-at: 2026-07-05T07:21:02-04:00`, `validator-refresh-source: deferred-generated-refresh`, and still carries UID00039T as an empty emitter marker at `86/88`.
- No `execute_report`, dry-run/probing execute variant, lifecycle/archive command, registry lifecycle command, manual generated edit, manual coverage-report edit, validator-state edit, supervisor-ledger edit, or manual report move was run by B012.

## Changed Files

- Manual B012 changes in this callback:
  - `by-memory/0x005583a0-0x0055867a.SurfaceDrawTilePresentation.md`
  - `tools/leaser/Agents/Agent-B012/research/00039T-SurfaceDrawTilePresentation-source-quality.md`
- Support by-* docs edited by B012: none.
- Validator-generated side effects recorded, not manually edited by B012:
  - `auto-generated/NexusTK/render/Surface.cpp` refreshed to validator-command-id `000000006867`.
  - `project-level/-auto-completion-stats.md` reported `projected_stats_update: 1`.
- Manual coverage files, generated reports, validator state, lifecycle/archive files, and supervisor ledgers manually edited by B012: none.
- Callback lease used/released: B012 leased `by-memory/0x005583a0-0x0055867a.SurfaceDrawTilePresentation.md` for the immediate edit/validator batch and released it after validation; `current_leases.md` reported no active leases after release.
- Report moved/executed: no.

## Implementation Tracking Checklist

- [x] Removed the two top-level active-report status/reason lines allowed by supervisor override: `REPORT-VALIDATION-STATUS: needs-revalidation` and `REPORT-REVALIDATION-REASON: target_uid_unknown: 00039T`.
- [x] Preserved the validator-owned `VALIDATOR-REPORT-HISTORY` footer unchanged.
- [x] Historicalized the prior validator status/reason under `Supporting Research`.
- [x] Incorporated supervisor validator command `000000006859`, its timestamp, exit/ok result, side effects, generated refresh state, and remaining sibling warnings.
- [x] Rechecked current MCP evidence using narrow schema-current calls against active session `supervisor_recovery_20260705`.
- [x] Verified the current target header/route/generated marker state: target `86/88`, owner/emitter `0000OC`, blank formal C++, generated tracker row `86/88`, generated `Surface.cpp` empty marker refreshed under `000000006859`.
- [x] Verified support-doc disposition: Surface, ScreenPane file/class, SurfaceRenderCallbackTable, ScreenPanePresentationTraversal, and BlitSurfaceToDisplay already carry same-or-greater UID00039T support detail.
- [x] Callback applied: target stale "IDA MCP unavailable" sentence was historicalized and current MCP proof was inserted in `Reachability And No-Entry Evidence`.
- [x] Callback preserved target metadata exactly: `COMPLETION:86`, `CONFIDENCE:88`, `CANONICAL_OWNER:0000OC`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000OC`.
- [x] Callback preserved blank formal C++: no standalone body added.
- [x] Callback preserved existing behavior, field/global roles, no-entry proof, Surface-bucket/ScreenPane-receiver caveat, rejected alternatives, split/range decision, and blank-C++ proof.
- [x] Callback lease discipline: leased only `by-memory/0x005583a0-0x0055867a.SurfaceDrawTilePresentation.md`, edited it, ran scoped validator, released the lease, and verified no active leases.
- [x] Callback validator run: command_id `000000006867`, command_timestamp `2026-07-05T07:21:02-04:00`, exit `0`, `ok:1`, with sibling `missing_ref_uid` warnings and generated refresh side effects recorded above.
- [x] Support docs were verification-only; no concrete accepted-report mismatch was found and no support by-* docs were edited.
- [x] No manual generated/project-level generated files, manual coverage reports, validator state, queue/lock files, lifecycle/archive files, or supervisor ledgers were edited.
- [x] No `execute_report`, dry-run/probing execute variant, registry/lifecycle/archive command, or manual report move was run.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"command_id":"000000004167","details":"report marked for revalidation","event":"needs-revalidation","issue":"target_uid_unknown: 00039T","source_path":"executed-b-agent-research/B012/00039T-SurfaceDrawTilePresentation-source-quality.md","timestamp":"2026-07-01T19:52:03-04:00"} -->
<!-- {"agent":"B012","command_id":"000000006857","destination_path":"tools/leaser/Agents/Agent-B012/research/00039T-SurfaceDrawTilePresentation-source-quality.md","details":"report returned to active agent research for rework","event":"de-executed-for-rework","source_path":"executed-b-agent-research/B012/00039T-SurfaceDrawTilePresentation-source-quality.md","timestamp":"2026-07-05T07:00:44-04:00"} -->
<!-- {"agent":"B012","command_id":"000000006870","destination_path":"executed-b-agent-research/B012/00039T-SurfaceDrawTilePresentation-source-quality.md","details":"report executed into central archive","event":"executed","source_path":"tools/leaser/Agents/Agent-B012/research/00039T-SurfaceDrawTilePresentation-source-quality.md","timestamp":"2026-07-05T07:26:41-04:00","uid":"00039T"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
