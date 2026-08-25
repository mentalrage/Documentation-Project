** TARGET-REPORT-UID:0000XK **
** AUTHOR-AGENT-ID:B004 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# 0000XK MiniMapDialog Source-Quality Report

## Finalized Report / Current Recommendation

- Current recommendation: raise [UID:0000XK] `by-memory/0x00450ca0-0x0045381b.MiniMapDialog.md` from `85/88` to `88/89`, keep `CANONICAL_OWNER:0000LE`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000LE`, and keep `EMITTER_POSITION_OPTIONAL` blank.
- Final disposition: keep this target as the MiniMap feature-root `MiniMapDialog` method/helper island, not as a single source C++ body. The target should document the current MCP session `80de0a67` evidence, the three raw source-shaped/no-route starts, exact padding/table spans, vtable/singleton route, and the shared-helper exclusions.
- Required action: update the target and MiniMap support docs at report-level detail. Do not add aggregate C++. Do not create raw child pages for `0x004517a0`, `0x00452ce0`, or `0x00452ea0` in this callback unless the supervisor explicitly authorizes raw no-route child inventory pages; the implementation-ready recommendation below proves why those children would be documentation-only and non-emitting under current evidence.
- Confidence: strong for the MiniMap ownership route, function inventory, raw-range semantics, and no-code decision. Capped below final-source confidence by the no-route raw code islands, shared helper ownership inside the broad physical range, and lack of a single plausible original source unit for the full aggregate.

## Supporting Research

## Target

- Target UID: `0000XK`.
- Target path: `E:\NTK\GhidraBridge\source-3\project-documentation\by-memory\0x00450ca0-0x0045381b.MiniMapDialog.md`.
- Source queue/report row: `project-level/-auto-completion-stats.md` lists `0000XK` at `85/88`; `by-memory/-coverage-report.md` row currently reports `85% : strong`.
- Current supervisor classification: report-only MCP-backed B-agent source-quality research for the broad MiniMapDialog method/helper island.
- Current scores and parent state: target `85/88`, parent/emitter [UID:0000LE] `by-file/MiniMap.md` at `86/88`, class context [UID:00008C] `by-class/MiniMapDialog.md` at `85/88`.

## Current Target State

- Existing metadata: `COMPLETION:85`, `CONFIDENCE:88`, `CANONICAL_OWNER:0000LE`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000LE`, blank emitter position.
- Existing owner/emitter/reconstructable state: MiniMap feature-root owner/emitter, source path `auto-generated/NexusTK/map/MiniMap.cpp`.
- Existing C++/emitter state: aggregate `RECONSTRUCTION_CPP` is blank; generated `auto-generated/NexusTK/map/MiniMap.cpp` contains only the empty emitter marker for [UID:0000XK].
- Existing open questions/blockers: older target text records raw generated labels `0x004517a0` and `0x00452ce0` as not IDA functions, but does not include current-session raw disassembly semantics, zero pointer/direct-route proof, or the raw `0x00452ea0` no-function/no-route status. Older coverage text says 22 modeled functions; current MCP inventory has 23 modeled in-range functions.
- Related target/support docs checked: target page, `by-file/MiniMap.md`, `by-class/MiniMapDialog.md`, `by-class/MiniMapRenderer.md`, `by-memory/0x00452260-0x0045239a.GetControlLayout_452260.md`, `by-global/GetControlLayout_452260.md`, `by-memory/0x004536e0-0x00453732.FontStyleClearRules.md`, `by-memory/0x0067a7c4-0x0067a7c8.g_pMiniMapDialog.md`, `by-memory/0x00453df0-0x004563b5.MiniMapRendererAndControls.md`, `auto-generated/NexusTK/map/MiniMap.cpp`, `auto-generated/-ag-memory-coverage.md`, `by-memory/-coverage-report.md`, and executed B005/B007/B012 support reports touching MiniMapRenderer, MiniMapSymbolControlPane, FontStyle, RectangleControlPane, and SimpleHelpPane2.

## Executive Recommendation

Keep direct routing through [UID:0000LE] `MiniMap`. The full physical range is not class-only: it includes `MiniMapDialog` methods, minimap-specific free layout helper [UID:0000XL], FontStyle child [UID:0000XM], local string/tree helpers, shared small-wide-string helpers, compiler thunks, and three source-shaped raw no-route bodies. A class-only owner would overclaim those support bytes. A no-owner/non-emitting reclassification would underclaim the clearly live constructor, vtable methods, singleton lifecycle, timer/input/rendering methods, and MiniMap file-family caller/callee route.

The score should rise to `88/89` because current MCP plus PE evidence resolves the previous active-session gap, gives exact role names for the raw projected labels, proves which raw ranges cannot yet be split into source-emitting children, confirms the successor boundary at `0x00453820`, and preserves shared-helper exclusions. It should not rise higher and should not receive aggregate C++ because there is no single defensible source block for all bytes in `0x00450ca0-0x0045381b`.

## Supervisor Active Recheck

- Trigger: supervisor assigned `B004-report-minimap-dialog-source-quality-0000XK-mcp-20260623` and required MCP session/database `80de0a67`.
- Split repair: this was report-only; no by-* split was permitted during this pass. The report therefore gives exact implementation-ready documentation updates and split decisions, but does not edit by-* pages.
- Source-bearing children: clean existing split children [UID:0000XL] and [UID:0000XM] remain valid. Raw starts `0x004517a0`, `0x00452ce0`, and `0x00452ea0` are source-shaped but have zero incoming route proof; under current by-structure rules they should be documented inside the target as raw no-route bodies rather than promoted to emitting child pages.

## Inference Research Guidance Check

- IDA fact: current MCP session `80de0a67` reports exact function starts/sizes, no-function results, xrefs, decompile failure for raw labels, bytes, vtable data refs, singleton bytes/refs, and successor function start.
- Documentation evidence: current MiniMap, MiniMapDialog, MiniMapRenderer, MiniMapRendererAndControls, FontStyle, GetControlLayout, and g_pMiniMapDialog pages already route the family through [UID:0000LE] but predate the current session and do not fully resolve all raw labels.
- Inference: source-facing raw labels are behavior labels backed by disassembly, with no original-symbol claim: `RefreshMiniMap` remains a good role name for `0x004517a0`, `0x00452ce0` should be corrected from generated `EnqueueRequest` to a raw symbol-pane append/add-control helper, and `0x00452ea0` should be described as a player marker/center-position update helper path.
- Wave2/Wave3 artifacts: generated `class_MiniMapDialog.cpp` and `auto-generated/NexusTK/map/MiniMap.cpp` were treated as leads only. No stale Wave2/Wave3 claim was used as authority.

## Heuristic / Inference Reanalysis And Validation

- `0x004517a0`: current MCP reports no function object and `xrefs_to` zero. Raw disassembly is source-shaped: it compares the dialog current map id at `this+0x26c` with the incoming argument, calls `MiniMapRenderer::BuildSymbolViews` (`0x004543f0`) at `0x004517c9`, clears panes at `0x004517df`, renders symbols at `0x004517e6`, toggles groups through `0x00452f70`, invalidates the 768x768 map area, and writes success/failure byte `this+0x614`. Existing generated `RefreshMiniMap` is acceptable as a descriptive role; a safer implementation wording is `raw RefreshMiniMap(int mapId) body`. It is not source-emitting because MCP xrefs and PE route scans find no branch, pointer, VA, RVA, or raw-offset route to the start.
- `0x00452ce0`: current MCP reports no function object and `xrefs_to` zero. Raw disassembly shows `this`, `pane` argument, a call to `0x0049dc10`/dialog add-control helper, then append of the same pane pointer into the vector triplet around `this+0x5c4`/`this+0x5c8`, with capacity growth through `0x00437710`. Generated `EnqueueRequest` is rejected as network/request wording; the body is a raw symbol-pane append/add-control helper. It is not source-emitting because the start has no route and no caller-owned signature.
- `0x00452ea0`: current MCP reports no function object and no direct route. Raw disassembly shows a map-id guard against the active map id, calls `MiniMapRenderer::UpdateViewOriginFromPlayer` at `0x00452ee9`, computes display-space center coordinates, calls image-control positioning at `0x00452f3d`, calls `MiniMapSymbolControlPane::SetCenterPosition` at `0x00452f4e`, then invalidates/draws through the dialog vtable. Best role is `raw player-marker center update path`, not a raw map-coordinate setter. This resolves the B005/B007 support-doc chain for the target but still blocks a child C++ page because the entry has no function object or route.
- `0x00453540`: source-shaped small-wide-string assignment/copy helper. It has MiniMap callers and external `0x004e8de0` callers. It should remain a shared-support caveat in the target, not be documented as a MiniMapDialog method. If the supervisor wants exact child cleanup, create a no-emitter shared helper child `0x00453540-0x0045365e.SmallWideStringAssignHelper.md`, `RECONSTRUCTABLE:TRUE`, `CANONICAL_OWNER:NONE`, blank emitter/C++, starting near `84/86`; do not attach it to MiniMap without a generic string-support owner.
- `0x00453660`: tiny singleton clear helper writes `g_pMiniMapDialog = 0`; current xrefs are EH/unwind funclet-style direct jumps from the constructor, not normal source calls. Keep it inside the target as lifecycle cleanup evidence and do not emit a manual helper while the constructor/destructor already document singleton publish/clear behavior.
- `0x00453670`: cleanup/free helper reached from constructor funclet-style xref. It clears or frees list/vector state and is not a MiniMapDialog source method. Keep as compiler/container cleanup support in the target.
- `0x00453740`: small-wide-string comparator/search helper with 25 code xrefs, including many external `0x00523xxx-0x00525xxx` metadata/table helpers. It is shared support. Do not assign it to MiniMapDialog. If split, use a no-owner shared helper child `0x00453740-0x004537bc.SmallWideStringCompareHelper.md`, blank emitter/C++; this is a coverage cleanup, not a MiniMap source body.
- `0x004537bc` and `0x004537c7`: destructor adjustor thunks with vtable dwords at `0x00610554` and `0x00610584`; compiler-generated glue, no source C++.
- `0x004537e0-0x0045381b`: scalar deleting destructor with vtable dword at `0x006104f4`; compiler wrapper around the non-deleting destructor and optional delete; source responsibility remains the ordinary destructor, not this wrapper.

Rejected alternatives:

- Leave generated names untouched: rejected because `EnqueueRequest` is misleading and `0x00452ea0` now has a resolved marker-centering role.
- Split raw starts as source-emitting children: rejected by zero route evidence and decompile/function-object failure.
- Move the aggregate owner from MiniMap to MiniMapDialog class: rejected because of free helper, FontStyle child, shared helper, and compiler/support bytes in the same physical range.
- Reclassify the entire range as no-owner/non-emitting: rejected because the live constructor, vtable methods, singleton lifecycle, timer/input/rendering methods, and MiniMap file route are all directly documented.

## Evidence Standards Used

Evidence ladder used for this pass:

- Current IDA MCP first: `initialize`, `tools/list`, `server_health`, `entity_query`, `lookup_funcs`, `get_bytes`, `xrefs_to`, `analyze_function`, `decompile`, and `insn_query` evidence from session `80de0a67`.
- Supplemental PE route scan second: section-mapped scan of `E:\NTK\Resources\NexusTK\NexusTK.exe` for direct call/jump and VA/RVA/raw-offset dword encodings.
- Documentation/generated checks third: by-* docs, generated MiniMap output, memory coverage, generated memory coverage, and executed B-agent reports.
- Inference last: source-facing names are used only where behavior and local subsystem context support them; original spelling is not claimed.

Tool limitations affecting confidence: IDA MCP cannot prove original source file split or original private helper spelling. Decompiler failures at raw starts are evidence of current function-model absence, not proof that the bytes are not source-authored. PE route scans can prove direct/pointer encodings are absent in the scanned image, but cannot prove a runtime-only computed call never occurs.

## Evidence Checked

IDA MCP and raw checks performed:

- MCP `server_health(database='80de0a67')`: status `ok`, IDB path `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, module `NexusTK.exe`, input path `C:\Users\admin\Desktop\Clone\NexusTK\NexusTK.exe`, imagebase `0x400000`, auto-analysis ready, Hex-Rays ready, strings cache ready, strings count 2067.
- MCP `entity_query(functions, 0x00450ca0-0x00453820)`: 23 modeled in-range functions plus successor `0x00453820`.
- MCP `lookup_funcs`: confirms raw/non-function status for `0x004517a0`, `0x00452ce0`, `0x00452ea0`, and `0x0045381b`; confirms `0x00453820` successor `sub_453820`.
- MCP `get_bytes`: checked raw/padding/table spans at `0x0045179a`, `0x00452183`, `0x0045239a`, `0x00452cda`, `0x00452e91`, `0x0045353b`, `0x0045365e`, `0x004536d9`, `0x00453732`, and `0x0045381b`; checked MiniMapDialog vtable bytes at `0x006104f4`; checked `g_pMiniMapDialog` bytes at `0x0067a7c4`.
- MCP `xrefs_to`: checked starts and raw labels including `0x004517a0`, `0x00452ce0`, `0x00452ea0`, modeled starts, vtable methods, shared helpers, successor `0x00453820`, and `0x0067a7c4`.
- MCP `analyze_function`: checked constructor, destructor, action/key/mouse/timer handlers, clamp, layout helper, render/clear/toggle helpers, tail string/tree helpers, shared helpers, FontStyle cleanup, adjustor/deleting destructors, and successor `0x00453820`.
- MCP `decompile`: raw starts `0x004517a0`, `0x00452ce0`, and `0x00452ea0` fail because no function object exists.
- MCP `insn_query`: raw disassembly for `0x004517a0`, `0x00452ce0`, and `0x00452ea0`.
- Local PE scan: `E:\NTK\Resources\NexusTK\NexusTK.exe` SHA-256 `9AEC210BBC5CE592176A21DD8E9D9FD8F250B8D9EA78237915A99BA8CFA9A632`; section map `.text` VA `0x00401000-0x0060d000`, `.rdata` VA `0x0060d000-0x0066c200`, `.data` VA `0x0066d000-0x0069cd64`; direct route and pointer-pattern scan for key starts.
- `tools/int_convert.py`: verified target size `0x2b7b` as decimal 11131, constructor allocation `0x63c` as decimal 1596, and selected function-size decimal conversions.

Docs, generated files, and old reports checked:

- Target and support by-* docs listed in Current Target State.
- `auto-generated/NexusTK/map/MiniMap.cpp`: only empty emitter markers for [UID:0000XK], [UID:00008C], [UID:00028P], [UID:0000XL], [UID:0000XO], and related MiniMap pages; no aggregate C++.
- `auto-generated/-ag-memory-coverage.md`: [UID:0000XK] emits through `auto-generated/NexusTK/map/MiniMap.cpp`.
- `by-memory/-coverage-report.md`: current [UID:0000XK] row still says `85%` and references the older 22-function inventory.
- Executed reports: B007 `0000XO-MiniMapRendererAndControls`, B005 `00008G-MiniMapSymbolControlPane`, B009 `00016T-SimpleHelpPane2Factory`, B012/B006 FontStyle reports, B004/B005 RectangleControlPane reports.

Negative checks performed:

- Zero MCP xrefs to `0x004517a0`, `0x00452ce0`, and `0x00452ea0`.
- Zero PE direct branch hits and zero VA/RVA/raw-offset pointer-pattern hits for `0x004517a0`, `0x00452ce0`, and `0x00452ea0`.
- No modeled function at the raw starts; Hex-Rays cannot decompile them as standalone functions.
- No function at the five-byte end padding `0x0045381b`; successor function begins at `0x00453820`.
- Shared-helper starts `0x00453540` and `0x00453740` have external callers, rejecting pure MiniMapDialog ownership.

Failed, unavailable, or skipped checks:

- `get_global_value` could read `0x0067a7c4` as `0x0`, but returned type-information errors for untyped vtable addresses. This was not an MCP availability failure; `get_bytes` over `0x006104f4` supplied the vtable dwords instead.
- No IDA DB changes were attempted; this assignment is report-only.

## Inference Claim Ledger

| Claim | Confidence | Evidence | Counter-evidence checked | Next verification / remaining uncertainty |
| --- | --- | --- | --- | --- |
| [UID:0000XK] remains MiniMap feature-root owned. | Strong | Constructor callers, vtable refs, singleton lifecycle, MiniMapRenderer/GetControlLayout/SymbolControl call chains, parent MiniMap docs. | Class-only owner, renderer owner, FontStyle owner, no-owner, shared-helper owners. | No further ownership blocker for target metadata. |
| `0x004517a0` is raw `RefreshMiniMap(int mapId)`-style code. | Strong for role, medium for exact name/signature | Raw disassembly compares map id, builds symbol views, clears/renders/toggles panes, invalidates map region, writes success byte. | Zero xrefs/pointer/routes; no function object; decompile failure. | Document as raw no-route body, no C++. |
| `0x00452ce0` is a symbol-pane append/add-control helper, not request enqueue. | Strong for behavior, medium for exact name | Raw disassembly calls add-control and appends pane pointer to vector around `this+0x5c4`. | Zero xrefs/pointer/routes; generated name only. | Replace generated name wording in docs; no C++. |
| `0x00452ea0` updates player marker/display centers. | Strong for role, medium for exact name/signature | Raw disassembly calls renderer `0x004540a0`, image-control position setter, and symbol-control `SetCenterPosition`. B005/B007 support docs corroborate. | Zero xrefs/pointer/routes; no function object. | Document in target and class support; no child C++. |
| `0x00453540` and `0x00453740` are shared support, not MiniMapDialog methods. | Strong | External callers at `0x004e8de0` and many `0x00523xxx-0x00525xxx` helpers; generic small-wide-string behavior. | MiniMap local callers checked and do not outweigh external reuse. | Optional no-owner shared-helper child pages if supervisor wants coverage splits. |
| Aggregate C++ should remain blank. | Strong | Mixed classes/helpers/raw no-route bodies/thunks/child overlaps; generated output already only has empty marker. | Individual child methods reviewed; several would be source-ready only as exact child pages, not aggregate body. | No aggregate C++; exact child C++ requires separate child pages or accepted split scope. |

## Positive Evidence Summary

- Direct constructor reachability: `xrefs_to 0x00450ca0` gives calls at `0x005a815f` in `sub_5A76C0` and `0x005ac049` in `sub_5AC000`.
- Vtable reachability: rdata bytes at `0x006104f4` include `0x004537e0`, `0x004518b0`, `0x004537bc`, `0x00451a10`, `0x004519b0`, `0x004537c7`, and `0x00451c90`; `xrefs_to` also reports vtable data refs for action/key/mouse/timer handlers and destructor thunks.
- Singleton lifecycle: `g_pMiniMapDialog` at `0x0067a7c4` is four zero bytes; xrefs include constructor publish/guard clear, destructor clear, tiny clear helper, and four packet/UI reads.
- Renderer/control route: constructor calls renderer constructor; timer/raw refresh paths call renderer prepare/build/version functions; raw `0x00452ea0` calls renderer view-origin update then image/symbol center setters.
- Existing children: [UID:0000XL] maps minimap control ids to rectangles and has seven constructor calls; [UID:0000XM] correctly owns FontStyle vector cleanup through FontStyle, not MiniMap.
- Generated output: target currently emits only an empty marker, proving no existing C++ would be overwritten or duplicated by leaving the aggregate blank.

## IDA MCP Facts

Function/range facts:

- Target half-open range is `0x00450ca0-0x0045381b`, size `0x2b7b` / 11131 bytes (Verified with `int_convert.py`).
- Current MCP function inventory in `0x00450ca0-0x00453820`:

| Start | Size | Current IDA name | Role |
| --- | ---: | --- | --- |
| `0x00450ca0` | `0x682` | `sub_450CA0` | Constructor. |
| `0x00451330` | `0x46a` | `sub_451330` | Non-deleting destructor. |
| `0x004518b0` | `0xf6` | `sub_4518B0` | `OnDialogAction`. |
| `0x004519b0` | `0x55` | `sub_4519B0` | `OnKeyEvent`. |
| `0x00451a10` | `0x27a` | `sub_451A10` | `OnMouseEvent`. |
| `0x00451c90` | `0x4f3` | `sub_451C90` | `OnTimerEvent`. |
| `0x004521a0` | `0xbc` | `sub_4521A0` | Clamp helper. |
| `0x00452260` | `0x13a` | `sub_452260` | GetControlLayout. |
| `0x004523d0` | `0x90a` | `sub_4523D0` | RenderSymbols. |
| `0x00452d20` | `0x171` | `sub_452D20` | ClearSymbolPanes. |
| `0x00452f70` | `0x112` | `sub_452F70` | ToggleSymbolVisibility. |
| `0x00453090` | `0xf9` | `sub_453090` | Small-wide-string tree node helper. |
| `0x00453190` | `0x154` | `sub_453190` | RB-tree insert/rebalance helper. |
| `0x004532f0` | `0x24b` | `sub_4532F0` | Set lookup/insert helper called by RenderSymbols. |
| `0x00453540` | `0x11e` | `sub_453540` | Shared small-wide-string assignment/copy helper. |
| `0x00453660` | `0xb` | `sub_453660` | Singleton clear helper. |
| `0x00453670` | `0x69` | `sub_453670` | Cleanup/free helper. |
| `0x004536e0` | `0x52` | `sub_4536E0` | FontStyle vector cleanup child [UID:0000XM]. |
| `0x00453740` | `0x7c` | `sub_453740` | Shared small-wide-string comparator/search helper. |
| `0x004537bc` | `0xb` | `sub_4537BC` | Destructor adjustor thunk. |
| `0x004537c7` | `0xb` | `sub_4537C7` | Destructor adjustor thunk. |
| `0x004537e0` | `0x3b` | `sub_4537E0` | Scalar deleting destructor. |
| `0x00453820` | `0x19` | `sub_453820` | Successor outside target; list/sentinel allocator used by constructor and external `sub_5227D0`. |

Data/table/padding facts:

- `0x0045179a-0x004517a0`: six `0xcc` bytes, then raw code at `0x004517a0`.
- `0x00452183-0x004521a0`: jump-table data before `0x004521a0`.
- `0x0045239a-0x004523d0`: post-body switch-table data and padding before `RenderSymbols`.
- `0x00452cda-0x00452ce0`: six `0xcc`, then raw code at `0x00452ce0`.
- `0x00452e91-0x00452ea0`: fifteen `0xcc`, then raw code at `0x00452ea0`; return at `0x00452f62`, alignment to `0x00452f70`.
- `0x0045353b-0x00453540`: five `0xcc`.
- `0x0045365e-0x00453660`: two `0xcc`.
- `0x004536d9-0x004536e0`: seven `0xcc`.
- `0x00453732-0x00453740`: fourteen `0xcc`.
- `0x0045381b-0x00453820`: five `0xcc` before successor `sub_453820`.

Xref facts:

- Zero xrefs to raw starts `0x004517a0`, `0x00452ce0`, and `0x00452ea0`.
- `0x004523d0` has code refs from raw `0x004517a0` at `0x004517e6` and timer handler at `0x00451d5e`.
- `0x00452d20` has code refs from raw `0x004517a0` at `0x004517df` and timer handler at `0x00451d57`.
- `0x00452f70` has nine code refs: four in raw `0x004517a0`, one in `OnDialogAction`, and four in `OnTimerEvent`.
- `0x00453540` has local MiniMap refs plus external `0x004e918b`/`0x004e921f`.
- `0x00453740` has 25 refs, including local MiniMap refs and many external metadata/table helper refs.

Vtable/global/type facts:

- MiniMapDialog vtable slice at `0x006104f4` contains scalar deleting destructor `0x004537e0`, `OnDialogAction` at offset `+0x48`, adjustor thunk `0x004537bc` at `+0x60`, `OnMouseEvent` at `+0x64`, `OnKeyEvent` at `+0x68`, adjustor thunk `0x004537c7` at `+0x90`, and `OnTimerEvent` at `+0x94`.
- `g_pMiniMapDialog` bytes at `0x0067a7c4` are zero-initialized. MCP `xrefs_to` reports writes/clears at `0x00450cf6`, `0x00450cfd`, `0x00451774`, `0x00453660`, plus reads at `0x005a59a0`, `0x005a607c`, `0x005a812e`, and `0x005ac023`.

Negative IDA facts:

- No function at `0x004517a0`, `0x00452ce0`, `0x00452ea0`, or `0x0045381b`.
- Decompilation fails at raw starts because they are not function objects.
- No vtable or data pointer route lands on the three raw starts.

## Function / Child Inventory

| Range / Item | UID / Path | Role | Reconstructable | Direct Parent | Score | Status |
| --- | --- | --- | --- | --- | --- | --- |
| `0x00450ca0-0x0045381b` | [UID:0000XK] target | MiniMapDialog method/helper island | TRUE | [UID:0000LE] MiniMap | recommend `88/89` | Keep owner/emitter, blank aggregate C++. |
| `0x00452260-0x0045239a` | [UID:0000XL] `GetControlLayout_452260` | Minimap-specific layout helper | TRUE | [UID:0000LE] MiniMap | `86/90` | Existing child sufficient; no C++ change. |
| `0x004536e0-0x00453732` | [UID:0000XM] `FontStyleClearRules` | FontStyle destructor-like vector cleanup | TRUE | [UID:00005C] FontStyle | `87/92` | Existing child correctly rejects MiniMap ownership. |
| `0x004517a0-0x0045188b` physical body | no child recommended | Raw `RefreshMiniMap(int mapId)`-style body | Source-shaped but no route | MiniMap context only | documentation only | Do not create emitting child; document no-route proof. |
| `0x00452ce0-0x00452d09` physical body | no child recommended | Raw symbol-pane append/add-control helper | Source-shaped but no route | MiniMap context only | documentation only | Reject `EnqueueRequest`; document no-route proof. |
| `0x00452ea0-0x00452f63` physical body | no child recommended | Raw player marker center update path | Source-shaped but no route | MiniMap context only | documentation only | Document relation to renderer/control chain; no child C++. |
| `0x00453540-0x0045365e` | optional future child | Shared small-wide-string assignment helper | TRUE if split | NONE until shared owner exists | suggested `84/86` | Optional coverage cleanup, not required for [UID:0000XK] score. |
| `0x00453740-0x004537bc` | optional future child | Shared small-wide-string comparator/search helper | TRUE if split | NONE until shared owner exists | suggested `84/86` | Optional coverage cleanup, not required for [UID:0000XK] score. |

## Direct Xref / Caller Inventory

| Address / Item | Xref / Caller / Callee | Meaning |
| --- | --- | --- |
| `0x00450ca0` | Calls at `0x005a815f`, `0x005ac049` | Live MiniMapDialog construction routes. |
| `0x004518b0` | Vtable dword `0x0061053c` | Action handler virtual dispatch route. |
| `0x004519b0` | Vtable dword `0x0061055c` | Key handler virtual dispatch route. |
| `0x00451a10` | Vtable dword `0x00610558` | Mouse handler virtual dispatch route. |
| `0x00451c90` | Vtable dword `0x00610588` | Timer handler virtual dispatch route. |
| `0x00452260` | Seven constructor calls in `0x00450ca0` | Minimap control layout helper. |
| `0x004523d0` | `0x004517e6`, `0x00451d5e` | Raw refresh and timer path render symbols. |
| `0x00452d20` | `0x004517df`, `0x00451d57` | Raw refresh and timer path clear symbols. |
| `0x00452f70` | Nine calls from raw/action/timer paths | Toggle category visibility. |
| `0x00452ee9` | Call to `0x004540a0` inside raw `0x00452ea0` | Renderer view-origin update before marker placement. |
| `0x00452f4e` | Call to `0x004560f0` inside raw `0x00452ea0` | Symbol-control center setter route. |
| `0x0067a7c4` | 8 xrefs | MiniMapDialog singleton storage. |

## Documentation Evidence And IDA Status

- Target page supports MiniMap assignment but should replace old session wording and 22-function summary with current session `80de0a67`, 23 modeled in-range functions, and raw-role proof.
- `by-file/MiniMap.md` already supports the MiniMap source family and compact-vs-split source path. It should add the current B004 [UID:0000XK] refresh, including the raw label resolution and score/no-code rationale.
- `by-class/MiniMapDialog.md` already records the class purpose, singleton, and B005/B007 symbol-center route. It should add current raw-label role/no-route details and note the target score recommendation.
- `by-class/MiniMapRenderer.md` and `by-memory/0x00453df0-0x004563b5.MiniMapRendererAndControls.md` already contain same-or-greater detail for `0x00452ea0` -> `0x004540a0` -> image/symbol center setter. A callback should edit them only if the supervisor wants explicit current-session `80de0a67` cross-reference; otherwise mark as already sufficient.
- `by-memory/0x00452260-0x0045239a.GetControlLayout_452260.md` and `by-global/GetControlLayout_452260.md` already contain same-or-greater behavior/detail for the layout helper. No required support edit.
- `by-memory/0x004536e0-0x00453732.FontStyleClearRules.md` already rejects MiniMap ownership at same-or-greater detail. No required support edit.
- `by-memory/0x0067a7c4-0x0067a7c8.g_pMiniMapDialog.md` already documents the singleton route; optional refresh only if the supervisor wants the current session named.

## Ranked Ownership Analysis

### 1. [UID:0000LE] MiniMap file root

- Evidence for: current MiniMap page owns the feature family; constructor callers create the dialog through map/living/user packet/UI paths; renderer/control/downloader/version-manager pages all route through MiniMap; `g_pMiniMapDialog` and MiniMap resource/config evidence support this root; generated output routes [UID:0000XK] to `auto-generated/NexusTK/map/MiniMap.cpp`.
- Evidence against: exact original file could have been compact `MiniMap.cpp` or split `MiniMapDialog.cpp`; aggregate also contains shared helpers and a FontStyle child.
- Decision: keep as canonical owner/emitter. The file root is the correct durable parent for a mixed MiniMap feature island with explicit child/shared-helper caveats.

### 2. [UID:00008C] MiniMapDialog class

- Evidence for: most major methods in the target are class methods; vtable and singleton evidence are class-specific; raw refresh/update paths operate on `this`.
- Evidence against: exact range also includes minimap free helper [UID:0000XL], FontStyle cleanup child [UID:0000XM], shared string helpers, RB-tree helpers, and compiler thunks. The class route would overstate ownership for non-class support bytes.
- Decision: primary context only, not canonical owner for the aggregate.

### 3. [UID:00008F] MiniMapRenderer / renderer-control island

- Evidence for: dialog calls renderer constructor, build/version/update methods, and the raw `0x00452ea0` path bridges into renderer/control center updates.
- Evidence against: renderer is an embedded dependency and downstream callee; it does not own dialog construction/input/timer/action methods or the singleton.
- Decision: rejected as target owner. Keep renderer pages as support docs.

### 4. [UID:0000XL] GetControlLayout / [UID:0000XM] FontStyle / shared control-helper owners

- Evidence for: exact subranges exist and have separate behavior/ownership evidence.
- Evidence against: each owns only a subrange or support behavior, not the full target.
- Decision: retain child/subrange ownership and explicitly exclude them from MiniMapDialog class-method claims.

### 5. No-owner/non-emitting aggregate

- Evidence for: mixed range and no aggregate C++.
- Evidence against: live constructor/vtable/singleton/event/rendering method route and valid MiniMap file-root emitter make no-owner too weak.
- Decision: rejected for the target. Use blank aggregate C++ with source-family owner instead.

## Source Placement

- Recommended placement: `NexusTK/map/`, current [UID:0000LE] MiniMap file root. Original source could have been compact `MiniMap.cpp` or split into `MiniMapDialog.cpp` plus `MiniMapRenderer.cpp` and private control files; current docs should not force either spelling as original-proof.
- Why it fits: all direct feature evidence is MiniMap UI state, renderer state, `g_pMiniMapDialog`, minimap controls, minimap `.mnm` rendering, MiniMapSymbolControlPane center placement, and map/dialog timers.
- Rejected placements: `MapPane` is a consumer/open route only; `FileDownloader` owns a different minimap HTTP worker shape; `FontStyle` and generic UI controls own reusable dependencies only; no-owner underclaims the live MiniMap route.
- Remaining placement uncertainty: exact compact-versus-split original source file is unresolved by direct metadata. This does not block the `88/89` target recommendation because the durable current emitter route is the MiniMap feature root and aggregate C++ remains blank.

## Range / Split / Padding / Reclassification Analysis

- Exact target range: `0x00450ca0-0x0045381b`, size `0x2b7b` / decimal 11131 (Verified with `int_convert.py`).
- Start boundary: immediately after [UID:0000VN] one-byte ignored padding at `0x00450c9f-0x00450ca0` and LodePNG island boundary; current constructor starts at `0x00450ca0`.
- End boundary: scalar deleting destructor ends at `0x0045381b`; five `0xcc` bytes `0x0045381b-0x00453820`; successor `sub_453820` begins at `0x00453820` and is outside [UID:0000XK].
- Existing child splits: keep [UID:0000XL] and [UID:0000XM]. They already prevent the clean layout and FontStyle cleanup subranges from being hidden inside the aggregate.
- Raw ranges:
  - `0x004517a0-0x0045188b`: source-shaped refresh body, no route.
  - `0x00452ce0-0x00452d09`: source-shaped append/add-control body, no route.
  - `0x00452ea0-0x00452f63`: source-shaped marker-center update body, no route.
- Split decision: do not create emitting child pages for the raw starts under current evidence. If the supervisor wants exact documentation-only raw child pages, create them with blank emitter/C++, parent [UID:0000LE], and explicit no-route proof; recommended starting score would be no higher than `84/86` because the behavior is clear but liveness/signature route is absent.
- Shared helper split decision: `0x00453540-0x0045365e` and `0x00453740-0x004537bc` can be split into no-owner shared-helper children if coverage cleanup is prioritized, but this is not required to score [UID:0000XK] at `88/89` because the target can document them as shared support caveats and keep aggregate C++ blank.

## Negative Evidence Summary

- No direct route to the raw labels from MCP xrefs or PE direct-branch scan.
- No VA/RVA/raw-offset pointer encodings for raw starts in the scanned executable.
- Raw starts cannot be decompiled as functions because the active IDB has no function objects there.
- `0x00453540` and `0x00453740` have external callers, so MiniMap-only ownership is rejected.
- `FontStyleClearRules` local MiniMap callers do not prove MiniMap ownership because the operation is generic FontStyle vector teardown and existing FontStyle docs model the source destructor.
- Generated names from `class_MiniMapDialog.cpp` are not authoritative. `EnqueueRequest` is specifically contradicted by raw disassembly.

## IDA Rename / Type / Comment Recommendations

- Do not edit the IDA database in this report-only assignment.
- Documentation/source-facing labels to use:
  - `0x004517a0`: `raw RefreshMiniMap(int mapId) body` or `raw MiniMapDialog refresh body`; keep generated `RefreshMiniMap` only as a search alias.
  - `0x00452ce0`: `raw symbol-pane append/add-control helper`; reject `EnqueueRequest`.
  - `0x00452ea0`: `raw player-marker center update path` or `raw UpdatePlayerMarkerPosition` role; note it calls renderer view-origin update, image-control positioning, and `MiniMapSymbolControlPane::SetCenterPosition`.
  - `0x00453540`: shared small-wide-string assignment/copy helper.
  - `0x00453740`: shared small-wide-string comparator/search helper.
- Comments that would be safe if a later IDA-comment pass is authorized: mark the three raw starts as source-shaped/no-route raw bodies, mark the shared helpers as non-MiniMap-exclusive, and mark `0x0045381b-0x00453820` as alignment before successor `sub_453820`.

## First-Draft C++ Recommendation

- Eligible for draft C++: no, not for [UID:0000XK] as an aggregate.
- Recommended code: keep the target `RECONSTRUCTION_CPP` block blank.
- Reason code should remain blank: the physical range mixes multiple source responsibilities and compiler artifacts: constructor/destructor/event methods, raw no-route helper bodies, child helper [UID:0000XL], FontStyle child [UID:0000XM], RB-tree/string helpers, shared support with external callers, destructor adjustor thunks, and scalar deleting destructor. A single C++ block would either duplicate child pages or emit an artificial decompiler-shaped amalgam.
- Exact no-code proof:
  - Current generated `auto-generated/NexusTK/map/MiniMap.cpp` already contains only an empty [UID:0000XK] marker.
  - The target has clean child overlap for `GetControlLayout_452260` and `FontStyle::~FontStyle` handling.
  - The three source-shaped raw starts have no incoming route, no function object, no decompilation, and zero pointer/direct-route scan hits.
  - Shared helpers have non-MiniMap callers and cannot be emitted as MiniMapDialog methods.
  - Existing child pages or future exact child pages are the correct C++ scope for individual methods, not the aggregate page.

## Final Recommendation

- Update [UID:0000XK] metadata to `COMPLETION:88`, `CONFIDENCE:89`; leave owner/emitter/reconstructable as-is.
- Keep aggregate C++ blank.
- Add current `2026-06-23 B004 MCP-backed source-quality recheck` evidence to the target.
- Replace/supersede older 22-function/current-session text with 23 modeled in-range functions, explicit raw no-function/no-route proof, raw role names, vtable/singleton evidence, PE route-scan proof, end padding/successor boundary, and score/no-code rationale.
- Preserve rejected alternatives: class-only owner, renderer owner, FontStyle/generic-control owner, FileDownloader/MapPane consumer owners, no-owner/non-emitting aggregate, raw child C++ emission, `EnqueueRequest` generated name, and MiniMap-only ownership for shared string helpers.

## Recommended Target Doc Changes

- Target path: `by-memory/0x00450ca0-0x0045381b.MiniMapDialog.md`.
- Exact report facts to incorporate:
  - Metadata `88/89`, owner/emitter retained.
  - MCP endpoint/session `80de0a67`, IDB path, health facts, PE SHA-256 and section map.
  - Target size `0x2b7b` / 11131 bytes and exact start/end boundaries.
  - Current 23-function inventory and successor `0x00453820`.
  - Raw `0x004517a0`, `0x00452ce0`, `0x00452ea0` no-function/no-route/decompile-failure facts and raw disassembly roles.
  - PE zero route/pointer-pattern scan for raw starts; positive controls for constructor calls, vtable dwords, and singleton xrefs.
  - `g_pMiniMapDialog` lifecycle route and vtable slots.
  - Shared helper exclusions for `0x00453540` and `0x00453740`.
  - Existing [UID:0000XL]/[UID:0000XM] child split status.
  - Score cap and exact no-code proof.
- Metadata/score/owner/emitter/reconstructable/C++ changes: raise scores only; keep all owner/emitter fields and blank C++.
- Historical/stale assumptions to preserve as superseded: older 22-function inventory and generated `EnqueueRequest` wording, explicitly corrected by current evidence.

## Recommended Support Doc Changes

- `by-file/MiniMap.md`: add a B004 current-session source-quality note for [UID:0000XK], including session `80de0a67`, 23 modeled functions, three raw no-route labels, raw role/name decisions, MiniMap owner retained, no aggregate C++, and score `88/89`. Preserve compact `MiniMap.cpp` versus split `MiniMapDialog.cpp` wording.
- `by-class/MiniMapDialog.md`: add current raw-label details for `RefreshMiniMap`, symbol-pane append/add-control helper, and player-marker center update path. Clarify that class context is primary but file root remains [UID:0000LE] because the exact range contains free/shared/helper bytes.
- `by-class/MiniMapRenderer.md`: no required edit if current B005/B007 symbol-positioning context remains present. If touched, only add that current B004 revalidated `0x00452ea0` as a raw no-function/no-route caller body and did not change renderer ownership.
- `by-memory/0x00453df0-0x004563b5.MiniMapRendererAndControls.md`: already contains same-or-greater detail for `0x00452ea0` relation to `UpdateViewOriginFromPlayer` and `SetCenterPosition`; no required edit unless the supervisor wants a current-session cross-reference.
- `by-memory/0x00452260-0x0045239a.GetControlLayout_452260.md` and `by-global/GetControlLayout_452260.md`: already sufficient; no edit required.
- `by-memory/0x004536e0-0x00453732.FontStyleClearRules.md`: already sufficient and correctly rejects MiniMap ownership; no edit required.
- `by-memory/0x0067a7c4-0x0067a7c8.g_pMiniMapDialog.md`: already sufficient for singleton lifecycle; optional current-session note only.

## Score And Metadata Recommendation

- Current score/metadata: `85/88`, `CANONICAL_OWNER:0000LE`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000LE`, blank emitter position, blank C++.
- Recommended score/metadata: `88/89`, same owner/emitter/reconstructable fields, blank C++.
- Score rationale and reason not lower: current evidence resolves active-session freshness, exact raw code roles, function inventory, padding/table spans, vtable/singleton proof, PE route controls, generated-name rejection, and no-code proof. Keeping `85/88` would understate the amount of currently verified source-quality evidence.
- Reason not higher: the aggregate includes no-route raw bodies, shared helpers with external callers, and compiler glue; source-file split is inferred at the MiniMap feature-root level; no single aggregate C++ body is defensible.
- Metadata fields to leave unchanged: owner/emitter/reconstructable should stay as current because the live target is a reconstructable MiniMap source-family island.

## Open Questions With Attempted Resolution

- Should `0x004517a0` become a child or C++ method? Resolved no for current implementation. Evidence checked: MCP function lookup/decompile/xrefs, raw disassembly, PE direct/pointer scan. Behavior is clear enough to document, but no route/signature is available for emitting code.
- Should `0x00452ce0` keep `EnqueueRequest`? Resolved no. Raw disassembly proves add-control plus vector append of a pane pointer. Use symbol-pane append/add-control wording.
- Should `0x00452ea0` be a renderer or symbol-control method? Resolved as MiniMapDialog-side raw marker update path that calls renderer/control methods. It is a caller bridge, not owned by renderer or symbol control.
- Should shared helpers be assigned to MiniMap? Resolved no. External caller evidence outweighs local MiniMap use.
- Should target be non-emitting/no-owner? Resolved no. MiniMap owner/emitter route is directly supported, but aggregate C++ remains blank.

## Exact Supervisor-Owned Coverage Text

File/placement: replace the existing [UID:0000XK] row in `by-memory/-coverage-report.md`. B agents must not apply this directly.

Exact replacement row:

```markdown
    - [UID:0000XK][0x00450ca0-0x0045381b.MiniMapDialog](by-memory/0x00450ca0-0x0045381b.MiniMapDialog.md) 0x00450ca0-0x0045381b | class/source-family island | MiniMapDialog : reconstructable : 88% : strong : B004 2026-06-23 MCP session 80de0a67 refresh confirmed a 0x2b7b / 11131-byte MiniMapDialog island with 23 modeled in-range functions, raw no-function/no-route labels at 0x004517a0, 0x00452ce0, and 0x00452ea0, exact padding/table gaps, constructor calls from 0x005a815f/0x005ac049, MiniMapDialog vtable refs, g_pMiniMapDialog singleton refs, GetControlLayout/FontStyle child splits, renderer/control symbol-center chain, shared-tail helper caveats, and aggregate no-code proof; keep owner/emitter [UID:0000LE] and blank C++ because raw route/function proof, shared helper ownership, and single-source aggregate shape do not support an aggregate C++ body.
```

Reason B agent must not apply it directly: current assignment forbids editing any `-coverage-report.md` file.

## Follow-Up Actions

- Supervisor actions: review and, if accepted, send implementation callback for target/support docs and apply the coverage row after verification.
- B004 implementation actions if accepted: edit target, MiniMap file doc, MiniMapDialog class doc, and only optional same-or-greater-detail support docs as needed; run scoped validators for changed by-* files.
- Optional supervisor-authorized split actions: if supervisor prioritizes coverage cleanup, create no-emitter documentation children for `0x00453540-0x0045365e` and `0x00453740-0x004537bc`; raw no-route children for `0x004517a0`, `0x00452ce0`, and `0x00452ea0` should remain documentation-only unless a route appears.

## Confidence

- Recommendation confidence: strong.
- Score confidence: strong for `88/89`; not higher because aggregate code remains intentionally blank and raw/shared-helper caveats are real.
- Remaining uncertainty: original private helper spellings and compact-versus-split source file shape are not directly recoverable from current IDB metadata. The report resolves their current documentation/C++ impact rather than leaving them as score blockers.

## Validator Results

- Report-only pass: no validators were run before supervisor acceptance.
- Implementation validator, target:
  - Command: `python .\tools\validator.py --mode file --file by-memory\0x00450ca0-0x0045381b.MiniMapDialog.md --apply --queue-timeout 240`
  - Result: exit code 0, `ok: 1`.
  - Notable side effects: applied UID/reference links, updated [UID:0000XK] stats/projection, rebuilt `tools/validator.ini`, and reported generated coverage reports as `autogen_report_noop`.
- Implementation validator, MiniMap file support:
  - Command: `python .\tools\validator.py --mode file --file by-file\MiniMap.md --apply --queue-timeout 240`
  - Result: exit code 0, `ok: 1`.
  - Notable side effects: inserted [UID:0000XK] links, rebuilt `tools/validator.ini`, and reported generated coverage reports as `autogen_report_noop`.
- Implementation validator, MiniMapDialog class support:
  - Command: `python .\tools\validator.py --mode file --file by-class\MiniMapDialog.md --apply --queue-timeout 240`
  - Result: exit code 0, `ok: 1`.
  - Notable side effects: inserted UID links for [UID:0000XL], [UID:0000XM], and [UID:0000XK], added a reference-index entry, updated [UID:00008C] stats/projection, rebuilt `tools/validator.ini`, and reported generated coverage reports as `autogen_report_noop`.
- Optional support validators: not run because `by-class/MiniMapRenderer.md`, `by-memory/0x00453df0-0x004563b5.MiniMapRendererAndControls.md`, `by-memory/0x00452260-0x0045239a.GetControlLayout_452260.md`, `by-global/GetControlLayout_452260.md`, `by-memory/0x004536e0-0x00453732.FontStyleClearRules.md`, and `by-memory/0x0067a7c4-0x0067a7c8.g_pMiniMapDialog.md` were checked and already contained same-or-greater detail for their accepted facts.

## Changed Files

- Created: `tools/leaser/Agents/Agent-B004/research/0000XK-MiniMapDialog-source-quality.md`.
- Modified by B004 implementation:
  - `by-memory/0x00450ca0-0x0045381b.MiniMapDialog.md`
  - `by-file/MiniMap.md`
  - `by-class/MiniMapDialog.md`
  - `tools/leaser/Agents/Agent-B004/research/0000XK-MiniMapDialog-source-quality.md`
- Validator-managed side effects: the scoped validators updated UID/reference links in the changed by-* docs and refreshed project validator/autogen bookkeeping such as `tools/validator.ini`, projected stats, and no-op generated report checks. No `-coverage-report.md` file was edited by B004.
- Renamed: none.
- Moved to executed: none.

## Implementation Tracking Checklist

Initial report-only pass:

- [x] Supervisor validation required before implementation. Proof: supervisor accepted this report and issued implementation callback `B004-implement-minimap-dialog-source-quality-0000XK-mcp-20260623`.
- [x] Target doc to update: `by-memory/0x00450ca0-0x0045381b.MiniMapDialog.md` with metadata `88/89`, current MCP/PE evidence, raw role/no-route proof, padding/table/successor boundary, vtable/singleton proof, shared-helper exclusions, score rationale, and aggregate no-code proof. Proof: updated metadata, `Covered Ranges`, `2026-06-23 B004 MCP-Backed Source-Quality Recheck`, `Exclusions And Caveats`, `Assignment Decision`, `Score Rationale`, and change log.
- [x] Support doc to update: `by-file/MiniMap.md` with current [UID:0000XK] session evidence, raw-label resolution, MiniMap owner retained, score/no-code rationale, and compact-vs-split source placement retained. Proof: added `2026-06-23 B004 MiniMapDialog source-quality sync` note with session `80de0a67`, 23 modeled functions, raw labels, owner/emitter/no-code decision, and compact-versus-split caveat.
- [x] Support doc to update: `by-class/MiniMapDialog.md` with current raw `RefreshMiniMap`, symbol-pane append helper, marker-center update path, and class-context-versus-file-root owner rationale. Proof: updated `Method Families`, added `B004 Raw-Label And Aggregate-Owner Recheck`, updated boundary caveats, and added change log entry.
- [x] Support docs to check and either update or mark already sufficient: `by-class/MiniMapRenderer.md`, `by-memory/0x00453df0-0x004563b5.MiniMapRendererAndControls.md`, `by-memory/0x00452260-0x0045239a.GetControlLayout_452260.md`, `by-global/GetControlLayout_452260.md`, `by-memory/0x004536e0-0x00453732.FontStyleClearRules.md`, and `by-memory/0x0067a7c4-0x0067a7c8.g_pMiniMapDialog.md`. Proof: checked with scoped `rg`; MiniMapRenderer already documents `UpdateViewOriginFromPlayer`, raw `0x00454e30` no-code caveat, and blank class C++; MiniMapRendererAndControls already documents the `0x00452ea0` caller chain, raw `0x00454e30`, aggregate no-code proof, and rejected alternatives; GetControlLayout pages already document seven constructor callers and rectangle table; FontStyleClearRules already rejects MiniMap ownership and documents the two MiniMap cleanup callers as scoped cleanup; g_pMiniMapDialog already documents zero bytes and the same eight xrefs.
- [x] Metadata/score changes to apply: raise [UID:0000XK] to `COMPLETION:88`, `CONFIDENCE:89`; keep owner/emitter/reconstructable/emitter-position unchanged. Proof: target metadata now has `COMPLETION:88`, `CONFIDENCE:89`, `CANONICAL_OWNER:0000LE`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000LE`, blank `EMITTER_POSITION_OPTIONAL`.
- [x] Owner/emitter/reconstructable changes to apply: none; explicitly retain [UID:0000LE] `MiniMap` and blank aggregate C++. Proof: target `RECONSTRUCTION_CPP` remains blank and target/support docs state the aggregate no-code proof.
- [x] Split/rename/new-child changes to apply: no required split. If supervisor separately authorizes optional coverage cleanup, use the exact child ranges/metadata recommended in the Range / Split section. Proof: no child pages were created; target states raw labels remain documented inside [UID:0000XK] and optional future raw/shared-helper children would be documentation-only/no-emitter unless a new route appears.
- [x] Source-placement and IDA rename/type/comment changes to apply or confirm not applicable: documentation-only source-facing labels for raw starts; no IDA DB edits. Proof: no IDA DB/tool-state edits were made; target records documentation-only roles for `0x004517a0`, `0x00452ce0`, and `0x00452ea0`.
- [x] First-draft C++ or no-code proof to apply: apply aggregate no-code proof; no aggregate C++. Proof: target and support docs retain blank aggregate C++ and document mixed class/free/helper/support bytes, zero raw start routes, and duplicate-output risk.
- [x] Exact target/support doc facts to incorporate at report-level detail: current MCP session/provenance, function inventory, raw disassembly roles, xrefs, PE scan, vtable/global facts, rejected alternatives, and score cap. Proof: incorporated in target `2026-06-23 B004 MCP-Backed Source-Quality Recheck`, `by-file/MiniMap.md` sync note, and `by-class/MiniMapDialog.md` raw-label section.
- [x] Historical/stale assumptions, rejected alternatives, and negative evidence to preserve: older 22-function text as superseded; generated `EnqueueRequest` rejected; no-route raw starts; shared helper external callers; class-only/no-owner/renderer/FileDownloader/MapPane alternatives rejected. Proof: target preserves current inventory superseding older 22-function wording, rejects `EnqueueRequest`, and records route failures and ownership rejections; support docs include the same decisions at context level.
- [x] Wave2/Wave3 mentions or artifacts encountered and ignored/rejected as stale: generated `class_MiniMapDialog.cpp` and simroot names treated as leads only. Proof: retained as historical lead language only in the report; no by-* implementation used generated names as authority.
- [x] Open questions to close or document as evidence-backed unresolved: all current score/C++ blockers resolved as documented no-code/no-split decisions or optional documentation-only split recommendations. Proof: target `Assignment Decision` and `Score Rationale` document why `88/89` is defensible and why no C++/child split is emitted now.
- [x] Validators to run after implementation: target, MiniMap file, MiniMapDialog class, and any optional support docs changed, using scoped `validator.py --mode file --apply --queue-timeout 240`. Proof: three changed by-* docs validated with exit code 0 and `ok: 1`; optional support docs were not changed.
- [x] Supervisor-owned coverage-report text to apply: exact [UID:0000XK] replacement row supplied above. Proof: coverage row remains in this report; B004 did not edit any `-coverage-report.md`.

Implementation callback pass:

- [x] Report accepted by supervisor for implementation: accepted callback received for `0000XK-MiniMapDialog-source-quality.md`.
- [x] All accepted target/support doc details incorporated at report-level detail: target, MiniMap file page, and MiniMapDialog class page updated; optional support docs checked and already sufficient as described above.
- [x] Metadata/score/owner/emitter/split/rename/C++ changes applied or explicitly not applied with reason: target raised to `88/89`; owner/emitter/reconstructable/emitter position unchanged; aggregate C++ blank; no raw child pages or IDA renames created.
- [x] Historical/stale assumptions, rejected alternatives, and negative evidence preserved: older 22-function/current-session gap superseded, generated `EnqueueRequest` rejected, raw no-route proof retained, shared-helper external callers retained, and class-only/no-owner/renderer/FileDownloader/MapPane alternatives rejected.
- [x] Open questions resolved or documented with evidence-backed unresolved rationale: remaining original private spelling and compact-versus-split source-file uncertainty now affects confidence cap only, not an unresearched blocker; no-score/C++ blockers are resolved by no-code/no-split proof.
- [x] Validators run and results recorded: target, `by-file/MiniMap.md`, and `by-class/MiniMapDialog.md` each exited 0 with `ok: 1`.
- [x] Supervisor-owned coverage-report/tracker text supplied or confirmed unchanged: exact coverage replacement row remains supplied above; no coverage report edited.
- [x] Remaining unapplied accepted items listed with exact blocker: none. All accepted non-coverage items were applied or checked already-sufficient with proof.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B004","command_id":"000000004165","destination_path":"executed-b-agent-research/B004/0000XK-MiniMapDialog-source-quality.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:17","uid":"0000XK"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
