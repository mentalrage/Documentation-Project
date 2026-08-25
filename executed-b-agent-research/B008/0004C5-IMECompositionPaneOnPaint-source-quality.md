** TARGET-REPORT-UID:0004C5 **
** AUTHOR-AGENT-ID:B008 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **

# 0004C5 IMECompositionPaneOnPaint Source-Quality Report

## Finalized Report / Current Recommendation
- Implemented callback disposition: [UID:0004C5] `by-memory/0x004e7840-0x004e7912.IMECompositionPaneOnPaint.md` has been converted from a blank-emitter split child into an emitting `IMECompositionPane::OnPaint()` child under [UID:00006G] `IMECompositionPane`.
- Final disposition: source-authored virtual paint method; exact range is stable, owner/source route is correct, and the prior "graphics helper names remain open" blocker is resolved by current GrafPort and Surface callback support docs.
- Applied action: target metadata is now `COMPLETION:88`, `CONFIDENCE:91`, `CANONICAL_OWNER:00006G`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:00006G`, blank optional position, with the exact formal C++ block inserted.
- Confidence: high for range, owner, offsets, helper sequence, and first-draft source shape; capped below final-source certainty only because exact original member/callback spellings such as `m_drawMode` and `FillRect` are descriptive project-standard names, not PDB/source-literal names.

## Target
- Target UID: `0004C5`.
- Target path: `by-memory/0x004e7840-0x004e7912.IMECompositionPaneOnPaint.md`.
- Pre-callback generated tracker row: [UID:0004C5] was `80/86`, reconstructable true, reports `0`, and non-emitting.
- Current supervisor classification: implementation callback complete; supervisor verification/report execution remains.
- Current scores and parent state after callback: target `88/91`; direct class [UID:00006G] `IMECompositionPane` remains `88/91`; source file [UID:0000K5] `IMEPanes` remains `90/88`; containing aggregate [UID:000189] `IMEPaneFamily` remains `87/90`.

## Current Target State
- Existing metadata: `COMPLETION:80`, `CONFIDENCE:86`, `CANONICAL_OWNER:00006G`, `RECONSTRUCTABLE:TRUE`, blank `EMITTER_UIDS`, blank position, blank `RECONSTRUCTION_CPP CODE`.
- Existing owner/emitter/reconstructable state: direct owner is already correct as [UID:00006G] `IMECompositionPane`; source route is [UID:00006G] -> [UID:0000K5] `IMEPanes`. The target is reconstructable but non-emitting only because no child-specific C++ had been accepted.
- Existing C++/emitter state: formal block is blank; generated `auto-generated/NexusTK/input/IMEPanes.cpp` consequently lacks `IMECompositionPane::OnPaint`.
- Existing blocker: the page says "Detailed graphics helper names remain a child-specific C++ task" and keeps formal C++ blank. Current support docs resolve those helper names sufficiently for first-draft C++.
- Related docs checked: target page, `by-class/IMECompositionPane.md`, `by-file/IMEPanes.md`, `by-memory/0x004e70f0-0x004e8433.IMEPaneFamily.md`, `by-memory/0x004e7470-0x004e763c.IMECompositionSetCompositionString.md`, `by-memory/0x004e7810-0x004e7838.IMECompositionPaneOnKeyEvent.md`, `by-memory/0x004e7920-0x004e7927.IMECompositionPaneGetCompositionWidth.md`, `by-memory/0x004e7380-0x004e744d.IMECompositionPaneConstructor.md`, GrafPort helper docs [UID:000162], [UID:000168], [UID:00016C], Surface callback table [UID:0001PI], generated tracker/coverage, generated `IMEPanes.cpp`, and prior executed B-agent reports for IME panes and `SetCompositionString`.

## Executive Recommendation
- Best direct owner: keep [UID:00006G] `IMECompositionPane`.
- Source placement: emit through [UID:00006G] into [UID:0000K5] `IMEPanes`, matching the accepted class shell route and the existing `[[CHILDREN]]` insertion point.
- Target disposition: keep one exact by-memory child at `0x004e7840-0x004e7912`; do not split, merge into the aggregate, or reroute to GrafPort/Surface.
- Rescore/emit: implemented at `88/91`, `EMITTER_UIDS:00006G`, with first-draft C++ populated.
- Remaining condition: supervisor verification and report execution/archive; no implementation blocker remains.

## Supervisor Active Recheck
- Triggering instruction: report-first research for [UID:0004C5] `by-memory/0x004e7840-0x004e7912.IMECompositionPaneOnPaint.md`; do not edit target/support by-* docs until validation/callback.
- Split repair required: no new split is required. The exact child already exists and matches the IDA function boundary.
- Source-bearing children in scope: this assignment is one exact child method. Sibling composition methods were read for field/source-route context but are outside implementation scope unless support text needs synchronization later.

## Inference Research Guidance Check
- `by-structure.md` requires by-memory C++ to cover only the page's own range. The recommended C++ covers only `0x004e7840-0x004e7912`; it does not inline `SetCompositionString`, `DrawWideText`, `DrawRectFrame`, or callback-table implementations.
- Evidence separation:
  - IDA fact: function size, padding, vtable xref, instruction sequence, callee addresses, offsets, local caret rectangle shape.
  - Documentation evidence: accepted GrafPort names (`SetDrawColor`, `SetTextColor`, `MoveTo`, `DrawRectFrame`, `DrawWideText`, `GetLineHeight`), `FillRect`/slot-7 wording, `IMECompositionPane` field names.
  - Inference: source spelling `m_drawMode` and wrapper `FillRect` are project-standard descriptive spellings for inherited GrafPort/Surface behavior.
- Wave2/Wave3 handling: the aggregate page has a historical "Current Wave3 owners" note. It supports the already-accepted IME class grouping but is not used as independent proof. Current MCP evidence and current by-* pages control this recommendation.

## Heuristic / Inference Reanalysis And Validation
- Generated/raw helper labels: rejected `sub_4B9660`, `sub_4B9680`, `sub_4B9600`, `sub_4BA450`, `sub_4BAB70`, `sub_4BAAA0`, `unk_69B3FC`, and stale generated `g_pfnLockSurface` as source names. Current support docs map them to `SetDrawColor`, `SetTextColor`, `MoveTo`, `DrawRectFrame`, `DrawWideText`, `GetLineHeight`, and a fill/pane-region callback source-facing wrapper such as `FillRect`.
- Field offsets: accepted current class/support names `compositionCursorX` at `+0xf8` and `compositionText[256]` at `+0xfc`. IDA reads `+0xf8` for caret left/right and scans `+0xfc` as a null-terminated UTF-16 buffer.
- Inherited drawing state: IDA directly clears `this+0x70` before filling/drawing. Current GrafPort/Pane docs support descriptive `m_drawMode` / draw-blit mode wording. This is inherited draw state, not an `IMECompositionPane` local flag.
- Rect field inference: IDA uses `this+0x44` as a 16-byte bounds rectangle and reads `+0x44` left and `+0x50` bottom. Current pane/GrafPort docs consistently call this `m_bounds` / `RectBounds`.
- Source placement: rejected GrafPort ownership because the body is a virtual pane paint method whose only xref is an IMECompositionPane vtable cell. Rejected Surface ownership because slot `0x0069b3fc` is only a callee/dependency.
- Formal C++ blocker: resolved. Exact helper spelling is still descriptive rather than source-literal, but the score-blocker audit standard treats that as a confidence cap, not a reason to keep source-authored executable targets marker-only.
- Rejected no-code disposition: not applicable. The function has a modeled function object, one vtable data xref, exact source class owner, stable dependency names, and a coherent virtual method body.

## Evidence Standards Used
- Evidence types used: IDA MCP `server_health`, `lookup_funcs`, `analyze_function`, `disasm`, `xrefs_to`, `get_bytes`, `get_int`, `callees`, `stack_frame`, `basic_blocks`; current by-* documentation; generated tracker and generated C++; executed B-agent reports for accepted IME and GrafPort/Surface support.
- Strength: high. The function body has exact bounds and simple straight-line behavior with one string-length loop. Helper roles are independently documented by current support pages.
- Limitation: no PDB/source symbols exist for final member/callback spellings. This affects confidence only, not reconstructability or first-draft C++ readiness.

## Evidence Checked
- IDA MCP availability: direct JSON-RPC listener `http://127.0.0.1:13337/mcp`, session `supervisor_resume_20260629`, `server_health` status `ok`, IDB `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, worker PID `24256`, `auto_analysis_ready:true`, `hexrays_ready:true`.
- IDA MCP function/range checks:
  - `lookup_funcs 0x004e7840` -> `sub_4E7840`, size `0xd2`.
  - `lookup_funcs 0x004e7912` -> not a function.
  - `lookup_funcs 0x004e7920` -> `sub_4E7920`, size `0x7`.
  - `lookup_funcs 0x004e7810` -> `sub_4E7810`, size `0x28`.
- IDA MCP byte checks:
  - `get_bytes 0x004e7838 size 8` -> eight `0xcc` bytes before the target.
  - `get_bytes 0x004e7900 size 32` includes final cookie check, `retn` at `0x004e7911`, then `0xcc` padding.
  - `get_bytes 0x004e7912 size 14` -> fourteen `0xcc` bytes before the next function at `0x004e7920`.
- IDA MCP vtable/xref checks:
  - `xrefs_to 0x004e7840` -> one data xref at `0x0061c430`, no code callers.
  - `get_int 0x0061c430 u32le` -> `0x004e7840`.
  - `xrefs_to 0x0061c430` -> no xrefs to the vtable cell address itself.
- IDA MCP disassembly/decompilation checks:
  - `disasm 0x004e7840` -> 72 instructions, total 72, start `push ebp`, end `retn` at `0x004e7911`.
  - `analyze_function 0x004e7840` -> three basic blocks, one UTF-16 scan loop, local four-dword caret rectangle, stack cookie only compiler support.
  - `callees 0x004e7840` -> `sub_4B9660`, `unk_69B3FC`, `sub_4BA450`, `sub_4B9680`, `sub_4B9600`, `sub_4BAB70`, `sub_4BAAA0`, and `__security_check_cookie`.
- Support docs checked:
  - [UID:00006G] records `compositionCursorX +0xf8`, `compositionText[256] +0xfc`, and `OnPaint 0x004e7840-0x004e7912`.
  - [UID:00018A] records `compositionCursorX = MeasureTextWidth(...) + 3` and notes that OnPaint reads `+0xf8` for a one-pixel caret rectangle.
  - [UID:000162] maps `0x004b9660` to `SetDrawColor`, `0x004b9680` to primary `SetTextColor`, and `0x004b9600` to `MoveTo`.
  - [UID:000168] maps `0x004ba450` to `GrafPort::DrawRectFrame`.
  - [UID:00016C] maps `0x004bab70` to `GrafPort::DrawWideText` and `0x004baaa0` to `GrafPort::GetLineHeight`.
  - [UID:0001PI] maps `0x0069b3fc` to broad slot-7 fill/invalidation/presentation infrastructure and rejects stale generated `g_pfnLockSurface` wording for paint paths.
- Generated/tracker checks:
  - `auto-generated/-ag-research-tracker.md` shows [UID:0000K5] with 16/16 and zero empty markers, but [UID:0004C5] remains `80/86`, reconstructable, reports `0`.
  - `auto-generated/-ag-coverage-report-by-memory.md` shows [UID:0004C5] emits_code false.
  - `auto-generated/NexusTK/input/IMEPanes.cpp` is validator-generated and currently lacks `IMECompositionPane::OnPaint`; no generated file was edited.
- Failed/unavailable/skipped checks: none. MCP was available and responsive. Validators were intentionally not run because this is report-only and no by-* file was edited.

## Claim And Incorporation Ledger
| Claim ID | Claim | Confidence | Evidence | Destination doc/section | Action | Verification state |
| --- | --- | --- | --- | --- | --- | --- |
| C1 | `0x004e7840-0x004e7912` is one exact function, size `0xd2`, with `0xcc` padding before and after. | High | MCP `lookup_funcs`, `disasm`, `get_bytes`; no function at `0x004e7912`, successor at `0x004e7920`. | Target `MCP Evidence`, `Score Rationale`, `Changes`. | incorporate | applied; target records size `0xd2`, no function at `0x004e7912`, successor `0x004e7920`, and `0xcc` padding before/after. Validator `000000003177` passed with `ok:1`. |
| C2 | The inbound route is a virtual table data xref only: slot `0x0061c430` contains `0x004e7840`; no direct code callers. | High | MCP `xrefs_to 0x004e7840`, `get_int 0x0061c430`, `xrefs_to 0x0061c430`. | Target `MCP Evidence`; class method inventory/evidence. | incorporate | applied; target records vtable cell `0x0061c430`, no direct code callers, and class method row links UID0004C5 as the emitting `OnPaint` child. |
| C3 | Direct owner/source route remains [UID:00006G] `IMECompositionPane` -> [UID:0000K5] `IMEPanes`; not GrafPort, Surface, or the aggregate. | High | Current target/class/file/aggregate docs; vtable slot; callee-only relationship to GrafPort/Surface helpers. | Target `Status`/`Reconstruction Notes`; class/file/aggregate support notes. | incorporate | applied; target keeps owner `00006G`, sets emitter `00006G`, and support docs record file route through [UID:0000K5]. GrafPort, Surface, aggregate, and no-code routes are rejected in target notes. |
| C4 | The body clears inherited draw/blit mode byte `this+0x70` before drawing. | Medium-high | MCP disasm `mov byte ptr [edi+70h], 0`; GrafPort docs treat `+0x70` as `m_drawMode`/draw-blit mode. | Target `Behavior`, `Draw Sequence And Fields`, formal C++. | incorporate | applied; target formal C++ begins `m_drawMode = 0;`, and behavior/table prose documents inherited draw-blit mode with spelling caveat. |
| C5 | Background fill and frame sequence is `SetDrawColor(143)`, fill `m_bounds`, `SetDrawColor(128)`, `DrawRectFrame(&m_bounds)`. | High | MCP disasm at `0x4e7854-0x4e787d`; GrafPort and Surface support docs. | Target `Behavior`, `Draw Sequence And Fields`, formal C++. | incorporate | applied; target C++ and draw-sequence table preserve the color `143` fill and color `128` frame behavior. |
| C6 | Text sequence is `SetTextColor(128)`, `MoveTo(m_bounds.left + 2, m_bounds.bottom - 2)`, null-scan `compositionText`, then `DrawWideText(compositionText, length)`. | High | MCP disasm/decompile at `0x4e7882-0x4e78c3`; class field docs. | Target `Behavior`, `Draw Sequence And Fields`, formal C++. | incorporate | applied; target C++ contains the exact text-color, move, scan, and counted `DrawWideText` sequence. |
| C7 | Caret rectangle is `{left=compositionCursorX, top=2, right=compositionCursorX+1, bottom=GetLineHeight()+2}`, then color `128` fill. | High | MCP disasm/decompile at `0x4e78c8-0x4e78fc`; [UID:00018A] field proof. | Target `Behavior`, `Draw Sequence And Fields`, formal C++; class/file/aggregate support rows. | incorporate | applied; target C++ and support rows record the one-pixel `compositionCursorX` caret rectangle and `GetLineHeight()+2` bottom. |
| C8 | `FillRect` is the best target-local source-facing wrapper for slot `0x0069b3fc`; raw `unk_69B3FC`/`g_pfnLockSurface` must remain evidence aliases only. | Medium-high | Surface callback docs and comparable paint pages (`ProgressBarControlPane`, `RectangleControlPane`, `FpsPane`, macro draw). | Target `Helper Mapping`, `Reconstruction Notes`, formal C++. | incorporate | applied; target uses `FillRect(&m_bounds)` and `FillRect(&caretRect)`, documents Surface slot `0x0069b3fc`, and rejects raw/stale aliases as source names. |
| C9 | Target should be raised from `80/86` to `88/91` and made emitting through `EMITTER_UIDS:00006G`. | High | Exact range, vtable owner, resolved helpers, first-draft C++ readiness, parent/class/file scores clear gate. | Target metadata and `Score Rationale`. | incorporate | applied; target metadata is `COMPLETION:88`, `CONFIDENCE:91`, `EMITTER_UIDS:00006G`, owner/reconstructable/blank position preserved. Validator `000000003177` reported completion/confidence/registry updates. |
| C10 | Support docs should be synchronized only where useful: class method row, file/aggregate child summary, and possibly SetCompositionString cross-reference. Helper docs already cover names and need no edit for this target. | Medium-high | Current support docs already contain most route/field facts but target-specific OnPaint details are still generic. | `by-class/IMECompositionPane.md`, `by-file/IMEPanes.md`, `by-memory/0x004e70f0-0x004e8433.IMEPaneFamily.md`; optional [UID:00018A]. | incorporate | applied; class/file/aggregate rows and evidence notes were updated. [UID:00018A] was already-present for the field/caret relationship and left unchanged; helper docs were excluded-with-reason because they already contain the accepted names and no target-specific churn was needed. |
| C11 | Generated `NexusTK/input/IMEPanes.cpp` should refresh after validators and include the new `IMECompositionPane::OnPaint` block under UID0004C5. | High | Current generated file lacked OnPaint because target was blank-emitter; class/file route already emits other IME children. | Validator/generation checkpoint, not manual generated edit. | incorporate | applied; validators refreshed generated output. `auto-generated/NexusTK/input/IMEPanes.cpp` header shows `validator-command-id: 000000003181`, refreshed `2026-06-30T16:09:15-04:00`, and contains `// UID:0004C5` plus `void IMECompositionPane::OnPaint()` with no UID0004C5 empty marker. |

## Positive Evidence Summary
- Exact function identity: MCP reports `sub_4E7840` size `0xd2`, with `0xcc` padding before and after, and no function at the end address.
- Owner proof: the only inbound xref is the vtable data xref at `0x0061c430`, and that cell contains `0x004e7840`; current class/aggregate docs already identify this slot as `IMECompositionPane::OnPaint`.
- Behavior proof: the disassembly directly shows the full sequence of drawing state setup, two rectangle fills, frame draw, text baseline setup, UTF-16 null-length scan, wide-text draw, and one-pixel caret fill.
- Field proof: `compositionText` and `compositionCursorX` are already accepted class fields; [UID:00018A] proves the setter writes both and records that this paint child consumes `compositionCursorX` as the caret x coordinate.
- Helper-name proof: accepted GrafPort and Surface docs provide reusable source-facing names. The remaining uncertainty is exact original spelling, not target behavior.

## IDA MCP Facts
- Function/range facts:
  - `0x004e7840`: `sub_4E7840`, size `0xd2`.
  - `0x004e7912`: not a function; padding begins immediately after `retn`.
  - `0x004e7920`: next modeled function, `sub_4E7920`, size `0x7`.
- Data/table/padding facts:
  - `0x004e7838-0x004e783f`: eight `0xcc` bytes.
  - `0x004e7912-0x004e791f`: fourteen `0xcc` bytes.
  - `0x0061c430 u32le`: `0x004e7840`.
- Xref facts:
  - `xrefs_to 0x004e7840`: one data xref, `0x0061c430`, no code callers.
  - `xrefs_to 0x0069b3fc`: many slot-7 users; report only uses this as dependency evidence, not ownership.
- Callee facts:
  - `0x004b9660` size `0xd` -> `SetDrawColor`.
  - `0x004b9680` size `0xd` -> `SetTextColor`.
  - `0x004b9600` size `0x13` -> `MoveTo`.
  - `0x004ba450` size `0xeb` -> `DrawRectFrame`.
  - `0x004bab70` size `0x158` -> `DrawWideText`.
  - `0x004baaa0` size `0x25` -> `GetLineHeight`.
  - `0x0069b3fc` -> Surface callback slot 7 / fill-invalidate-presentation dependency.
- Negative IDA facts:
  - No direct code callers to the target start.
  - No separate function at the target end.
  - No resource strings, EPF/EPD loads, or image-library calls in this body.
  - No helper ownership transfer evidence; all non-compiler callees are shared dependencies.

## Function / Child Inventory
| Range / Item | UID / Path | Role | Reconstructable | Direct Parent | Score | Status |
| --- | --- | --- | --- | --- | --- | --- |
| `0x004e7810-0x004e7838` | [UID:0004C4] `IMECompositionPaneOnKeyEvent` | Key event handler forwards composition text to `SetCompositionString`. | TRUE | [UID:00006G] | `82/89` | Context sibling; not changed by this report. |
| `0x004e7840-0x004e7912` | [UID:0004C5] `IMECompositionPaneOnPaint` | Paints composition popup background, frame, text, and one-pixel caret. | TRUE | [UID:00006G] | implemented `88/91` | Primary target; now emits first-draft C++. |
| `0x004e7920-0x004e7927` | [UID:0004C6] `IMECompositionPaneGetCompositionWidth` | Returns `compositionCursorX`. | TRUE | [UID:00006G] | `82/89` | Context sibling; confirms field meaning. |
| `0x004e70f0-0x004e8433` | [UID:000189] `IMEPaneFamily` | Aggregate/container for IME pane children. | TRUE | [UID:0000K5] | `87/90` | Should stay aggregate with `[[CHILDREN]]`; do not move child body into it. |

## Direct Xref / Caller Inventory
| Address / Item | Xref / Caller / Callee | Meaning |
| --- | --- | --- |
| `0x004e7840` | data xref from `0x0061c430`; no code callers | Virtual dispatch body, not directly called helper. |
| `0x0061c430` | u32 value `0x004e7840` | IMECompositionPane vtable slot for the paint method. |
| `0x004b9660` | called at `0x4e785d`, `0x4e7875`, `0x4e78f1` | Set active draw/fill color to `143`, `128`, and `128`. |
| `0x0069b3fc` | called at `0x4e7868` and `0x4e78fc` | Fill/invalidate/presentation callback; source-facing `FillRect` for this body. |
| `0x004ba450` | called at `0x4e787d` | Draw frame around inherited bounds. |
| `0x004b9680` | called at `0x4e7889` | Set text color to `128`. |
| `0x004b9600` | called at `0x4e789d` | Move text cursor to `bounds.left+2`, `bounds.bottom-2`. |
| `0x004bab70` | called at `0x4e78c3` | Draw `compositionText` with computed length. |
| `0x004baaa0` | called at `0x4e78de` | Get line height for caret rectangle bottom. |

## Documentation Evidence And IDA Status
- Existing docs that support the conclusion:
  - Target already identifies exact owner/source route and field relationship.
  - [UID:00006G] already lists `OnPaint 0x004e7840-0x004e7912` and fields `compositionCursorX` and `compositionText`.
  - [UID:000189] lists this exact range as `IMECompositionPane::OnPaint`.
  - [UID:00018A] confirms `compositionCursorX` is a cached text-width/cursor x value and that OnPaint consumes it for a one-pixel caret rectangle.
  - GrafPort/Surface support docs resolve all graphics helper names used by the target.
- Existing docs that are stale/incomplete:
  - Target reconstruction notes still say graphics helper names remain a child-specific C++ task.
  - Target emitter remains blank despite the helper-name and field blockers now being resolved.
  - Generated `IMEPanes.cpp` lacks this method because the source page is still non-emitting.
- Generated/coverage state:
  - Do not edit generated output manually. After callback validators, generated `NexusTK/input/IMEPanes.cpp` should refresh and include UID0004C5.

## Ranked Ownership Analysis

### 1. [UID:00006G] IMECompositionPane
- Evidence for: current class doc declares the method; vtable data xref supplies a virtual-method route; body reads class fields `+0xf8/+0xfc`; sibling setter/key/accessor pages form a coherent `IMECompositionPane` cluster.
- Evidence against: none meaningful. Helper callees belong to GrafPort/Surface, but they are dependencies rather than owner evidence.
- Decision: keep direct owner and set `EMITTER_UIDS:00006G`.

### 2. [UID:0000K5] IMEPanes File
- Evidence for: this is the correct source-file route for the class shell and child emission.
- Evidence against: file page is not the direct method owner; emitting should flow through class [UID:00006G].
- Decision: keep as source file parent through [UID:00006G], not direct owner on target metadata.

### 3. [UID:00005V] GrafPort / [UID:0000TN] SurfaceRenderCallbackTable
- Evidence for: all draw/text/fill operations call GrafPort and Surface helper infrastructure.
- Evidence against: no inbound ownership route to these helpers; the target function is an IMECompositionPane vtable body and consumes IMECompositionPane state.
- Decision: reject as owner; cite only as dependencies/source-facing helper support.

### 4. [UID:000189] IMEPaneFamily
- Evidence for: aggregate contains the range and already tracks source placement.
- Evidence against: aggregate is a container/split plan; by-structure requires exact child bodies to emit from their own pages.
- Decision: do not paste child C++ into aggregate; update aggregate summary only if callback touches support docs.

## Source Placement
- Recommended source file/class/global/module placement: `IMECompositionPane::OnPaint()` under [UID:00006G] `IMECompositionPane`, emitted through [UID:0000K5] `by-file/IMEPanes.md`.
- Why it fits: constructor, key handler, setter, accessor, and paint method all sit in the contiguous IME pane family, and the accepted `IMEPanes.cpp` route already has a class shell with `[[CHILDREN]]`.
- Rejected placements: GrafPort/Surface helper sources, aggregate-only body, raw helper page, or no-owner marker.
- Remaining placement uncertainty: none that affects callback implementation.

## Range / Split / Padding / Reclassification Analysis
- Exact range/boundary facts: keep `0x004e7840-0x004e7912`; `lookup_funcs` reports size `0xd2`; `retn` is at `0x004e7911`; `0x004e7912-0x004e791f` is `0xcc` padding; successor `0x004e7920` is the tiny composition-width accessor.
- Children/subranges: no new child pages. The UTF-16 scan loop and caret rectangle setup are internal to the paint method.
- Padding/table/data/code distinctions: `0x0061c430` is a vtable data cell, not code; `0x0069b3fc` is shared callback-table storage/callee evidence.
- Parent/container impact: aggregate [UID:000189] remains a container and should not duplicate the target C++.

## Negative Evidence Summary
- No direct code caller exists; the method is virtual through a vtable cell.
- No evidence supports moving the body to GrafPort or Surface; those are callee dependencies.
- No evidence supports keeping the formal block blank; the prior helper-name blocker is addressed by current support pages.
- No evidence supports new source helpers or splits; the body is one simple method with a local `RectBounds`.
- No string/resource/image-library evidence is present; this paint method draws only text and rectangles from existing pane state.

## IDA Rename / Type / Comment Recommendations
- Proposed source-facing names/types:
  - `IMECompositionPane::OnPaint()`.
  - `compositionCursorX` for `this+0xf8`.
  - `compositionText` for `this+0xfc`.
  - `m_drawMode` for inherited `this+0x70`.
  - `m_bounds` / `RectBounds` for inherited rectangle at `this+0x44`.
  - `SetDrawColor`, `SetTextColor`, `MoveTo`, `DrawRectFrame`, `DrawWideText`, `GetLineHeight`, and `FillRect`.
- Evidence: current support pages listed above and live MCP instruction sequence.
- Items intentionally left unchanged: no IDA DB renames/comments are requested in this report. Raw labels should remain searchable evidence aliases in prose.
- IDA DB edits: not requested.

## First-Draft C++ Recommendation
- Eligible for draft C++: yes. The target is a real source-authored virtual method with an accepted class owner, exact range, stable field names, stable helper dependencies, and a coherent source route.
- Recommended code: exact insertion text now applied to the target `RECONSTRUCTION_CPP CODE` block:

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
void IMECompositionPane::OnPaint()
{
    m_drawMode = 0;

    SetDrawColor(143);
    FillRect(&m_bounds);

    SetDrawColor(128);
    DrawRectFrame(&m_bounds);

    SetTextColor(128);
    MoveTo(m_bounds.left + 2, m_bounds.bottom - 2);

    const wchar_t *scan = compositionText;
    while (*scan != L'\0') {
        ++scan;
    }

    DrawWideText(compositionText, static_cast<int>(scan - compositionText));

    RectBounds caretRect;
    caretRect.left = compositionCursorX;
    caretRect.top = 2;
    caretRect.right = compositionCursorX + 1;
    caretRect.bottom = GetLineHeight() + 2;

    SetDrawColor(128);
    FillRect(&caretRect);
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

- Third-party import directive: not applicable.
- Reason it preserves exact original behavior:
  - Directly mirrors the instruction order: clear `+0x70`; set/fill color `143`; set/frame color `128`; set text color `128`; move to left+2/bottom-2; scan UTF-16 text to a terminator; draw counted wide text; build local caret rect with left `+0xf8`, top `2`, right `+0xf8+1`, bottom `GetLineHeight()+2`; set color `128`; fill caret rect.
  - The null-scan uses `scan - compositionText`, matching IDA's post-increment loop and `sar eax, 1` length calculation.
- Reason it matches plausible source shape: pane paint methods in this project use inherited drawing state, `RectBounds`, source-facing wrappers, and class field names rather than raw callback globals or decompiler temporaries.
- Inferred names used instead of IDA labels: `m_drawMode`, `m_bounds`, `FillRect`, and exact method/helper spellings are current project-source-facing names; raw labels remain in evidence.
- Reason code should not remain blank: current evidence resolves the old graphics-helper blocker; leaving this marker-only would hide a source-authored virtual body that now meets the code-entry gate after the implemented score lift.

## Final Recommendation
- Exact target changes recommended:
  - `COMPLETION:88`
  - `CONFIDENCE:91`
  - `CANONICAL_OWNER:00006G` unchanged
  - `RECONSTRUCTABLE:TRUE` unchanged
  - `EMITTER_UIDS:00006G`
  - `EMITTER_POSITION_OPTIONAL:` blank
  - populate exact formal C++ block above
  - update item summary, behavior, evidence, reconstruction notes, score rationale, and changes to preserve MCP proof and rejected alternatives.
- Exact parent/support changes recommended:
  - `by-class/IMECompositionPane.md`: update the `OnPaint` row and evidence note to say UID0004C5 now has first-draft C++ and exact helper sequence.
  - `by-file/IMEPanes.md`: update IMECompositionPane contents/support note to include the newly emitting paint body, if not already covered at same-or-greater detail by intervening edits.
  - `by-memory/0x004e70f0-0x004e8433.IMEPaneFamily.md`: update the child inventory row for `0x004e7840-0x004e7912` from generic text/caret wording to the detailed background/frame/text/caret fill sequence, if not already present.
  - `by-memory/0x004e7470-0x004e763c.IMECompositionSetCompositionString.md`: optional cross-reference only; current field/caret proof is already sufficient and may be left unchanged if the callback agent judges no new support fact is needed.
  - GrafPort and Surface helper pages: no change required for this target; they already resolve helper names.
- Items left no-owner/non-emitting: none in this target.
- Future work outside scope: sibling `0004C4`, `0004C6`, constructor, and other IME children may still be improved separately, but they are not required for UID0004C5.

## Recommended Target Doc Changes
- Target path: `by-memory/0x004e7840-0x004e7912.IMECompositionPaneOnPaint.md`.
- Exact report facts to incorporate:
  - Current MCP session `supervisor_resume_20260629` confirms `sub_4E7840` size `0xd2`, exact end `0x004e7912`, padding before/after, and vtable xref at `0x0061c430`.
  - Body sequence: clear inherited `m_drawMode`, fill bounds color `143`, frame bounds color `128`, set text color `128`, move text baseline to `left+2/bottom-2`, draw counted `compositionText`, then fill a one-pixel caret rectangle using `compositionCursorX` and `GetLineHeight`.
  - Preserve raw aliases as evidence only and reject stale `g_pfnLockSurface`/blank-helper wording.
- Metadata/score/owner/emitter/C++ changes: apply metadata listed in Final Recommendation and formal block above.
- Historical/stale assumptions to preserve as rejected: old "graphics helper names remain open" and blank C++ disposition are superseded by current MCP and support-doc evidence.

## Recommended Support Doc Changes
- Support path: `by-class/IMECompositionPane.md`.
  - Incorporate: method row/evidence note should state that [UID:0004C5] now paints background, frame, text, and caret with exact helper sequence; fields `compositionCursorX` and `compositionText` are consumed by the emitted C++.
  - Metadata/link changes: no class score change required unless callback agent sees current accepted content justifies it.
- Support path: `by-file/IMEPanes.md`.
  - Incorporate: IMECompositionPane source contents include emitted `OnPaint`; generated file should refresh through validator.
  - Metadata changes: likely none; file already clears emitter gate.
- Support path: `by-memory/0x004e70f0-0x004e8433.IMEPaneFamily.md`.
  - Incorporate: child inventory row for `0x004e7840-0x004e7912` should record the exact paint sequence and first-draft C++ readiness.
  - Metadata changes: none required; aggregate should remain container/source-placement page.
- Optional support path: `by-memory/0x004e7470-0x004e763c.IMECompositionSetCompositionString.md`.
  - Incorporate only if needed: add a one-line cross-reference that UID0004C5 now formally consumes `compositionCursorX` as the caret left coordinate and `compositionText` as the drawn UTF-16 string. Current content already covers this at useful detail, so leaving it unchanged is acceptable.
- Helper support docs: [UID:000162], [UID:000168], [UID:00016C], [UID:0001PI] are already sufficient; do not churn them for this target unless a concurrent accepted edit has changed names.

## Score And Metadata Recommendation
- Current score/metadata: `80/86`, owner `00006G`, reconstructable true, blank emitter/formal.
- Recommended score/metadata: `88/91`, owner `00006G`, reconstructable true, emitter `00006G`, blank position, formal C++ populated.
- Score rationale:
  - Completion `88`: exact range/padding, vtable route, field offsets, helper sequence, source owner, source placement, rejected alternatives, and first-draft C++ are all resolved. It is below the low/mid 90s because helper/member spellings remain descriptive rather than source-literal.
  - Confidence `91`: behavior and ownership are strongly supported by live MCP and current docs. Confidence is not higher because callback typedef/name finalization for slot `0x0069b3fc` remains global Surface/GrafPort work.
- Score-improvement attempt:
  - Helper-name blocker researched through [UID:000162], [UID:000168], [UID:00016C], and [UID:0001PI]; result: resolved sufficiently for first-draft code.
  - Field-name blocker researched through [UID:00006G], [UID:00018A], and siblings; result: `compositionCursorX` and `compositionText` are accepted.
  - Range/source-route blocker researched through MCP bytes/xrefs/vtable and support pages; result: no split/reroute needed.
- Metadata fields to leave unchanged: UID, canonical owner, reconstructable true, and blank position.

## Open Questions With Attempted Resolution
- Exact original spelling for `m_drawMode`: current support uses `m_drawMode` / draw-blit mode for inherited `+0x70`. Resolution: use `m_drawMode` in first draft and document as inferred/descriptive.
- Exact original callback wrapper for slot `0x0069b3fc`: support docs use `FillRect`, `PreparePaneRegion`, or `g_pfnFillOrInvalidateRect` depending callsite. Resolution: this body fills `m_bounds` and a caret rectangle after setting draw color, so `FillRect` is the best local source-facing wrapper; raw callback name stays evidence only.
- Exact color constant names for `143` and `128`: no source enum names were found. Resolution: keep numeric constants in C++ to preserve behavior.
- Remaining unresolved items: no target-specific blocker remains. All remaining uncertainty is naming confidence, not a reason to leave the target non-emitting.

## Follow-Up Actions
- Supervisor action remaining: verify this callback implementation claim-by-claim, then execute/archive the report through the supervisor-owned validator lifecycle command if accepted.
- No B008 follow-up blockers remain for UID0004C5.
- Sibling IME child improvements remain outside this callback unless separately assigned.

## Implementation Callback Results
- Mode: implementation callback after supervisor acceptance.
- Files changed:
  - `by-memory/0x004e7840-0x004e7912.IMECompositionPaneOnPaint.md`
  - `by-class/IMECompositionPane.md`
  - `by-file/IMEPanes.md`
  - `by-memory/0x004e70f0-0x004e8433.IMEPaneFamily.md`
  - `tools/leaser/Agents/Agent-B008/research/0004C5-IMECompositionPaneOnPaint-source-quality.md`
- Support docs not changed:
  - `by-memory/0x004e7470-0x004e763c.IMECompositionSetCompositionString.md`: already had same-or-better field/caret relationship detail for `compositionCursorX` and `compositionText`.
  - GrafPort/Surface helper pages: excluded-with-reason; existing docs already define the accepted helper names and callback slot roles.
- Leases used:
  - Acquired as `B008`: `by-memory/0x004e7840-0x004e7912.IMECompositionPaneOnPaint.md`, `by-class/IMECompositionPane.md`, `by-file/IMEPanes.md`, and `by-memory/0x004e70f0-0x004e8433.IMEPaneFamily.md`.
  - Release command: `python leaser.py B008 unlease`.
  - Release result: success for all four leased files, reported under resolved `C:\FastStorage\NTK_Sources\source-3\project-documentation\...` paths.
  - Final lease report: no active B008 leases listed.
- Generated/manual edit discipline:
  - No manual edits to generated files, generated reports, manual `-coverage-report.md` files, validator state, queue files, lock files, IDA DB, executed archives, or supervisor ledgers.
  - Validator-owned generated files/reports refreshed through scoped validators only.

## Confidence
- Recommendation confidence: high.
- Score confidence: high for implemented `88/91`; conservative enough to reflect descriptive helper/member names.
- Remaining uncertainty: exact original spellings for inherited draw mode and Surface callback wrapper. This is documented as a naming-confidence caveat and no longer blocks emission.

## Validator Results
- Working directory for all commands: `E:\NTK\GhidraBridge\source-3\project-documentation`.
- `python .\tools\validator.py --mode file --file by-memory\0x004e7840-0x004e7912.IMECompositionPaneOnPaint.md --apply --wait-generated --queue-timeout 240`
  - `command_id: 000000003177`
  - `command_timestamp: 2026-06-30T16:08:17-04:00`
  - exit code `0`
  - `ok: 1`
  - generated refresh: completed; `generated_refresh_command_id: 000000003177`, `generated_refresh_timestamp: 2026-06-30T16:08:17-04:00`
  - relevant target side effects: completion update to `88`, confidence update to `91`, emitter registry update to `00006G`, formal block registry update from blank to block, UID link/reference-index updates.
- `python .\tools\validator.py --mode file --file by-class\IMECompositionPane.md --apply --wait-generated --queue-timeout 240`
  - `command_id: 000000003178`
  - `command_timestamp: 2026-06-30T16:08:40-04:00`
  - exit code `0`
  - `ok: 1`
  - generated refresh: completed; `generated_refresh_command_id: 000000003178`, `generated_refresh_timestamp: 2026-06-30T16:08:40-04:00`
  - relevant target side effects: reference index added UID0004C5 from class support page.
- `python .\tools\validator.py --mode file --file by-file\IMEPanes.md --apply --wait-generated --queue-timeout 240`
  - `command_id: 000000003179`
  - `command_timestamp: 2026-06-30T16:08:57-04:00`
  - exit code `0`
  - `ok: 1`
  - generated refresh: completed; `generated_refresh_command_id: 000000003179`, `generated_refresh_timestamp: 2026-06-30T16:08:57-04:00`
  - relevant target side effects: reference index added UID0004C5 from source-file support page.
- `python .\tools\validator.py --mode file --file by-memory\0x004e70f0-0x004e8433.IMEPaneFamily.md --apply --queue-timeout 240`
  - `command_id: 000000003181`
  - `command_timestamp: 2026-06-30T16:09:15-04:00`
  - exit code `0`
  - `ok: 1`
  - generated refresh: deferred by command output; generated `IMEPanes.cpp` nevertheless refreshed to this command id/timestamp immediately afterward.
  - relevant target side effects: projected stats update; no target-specific warnings.
- Warnings/common diagnostics: validator reported broad pre-existing `autogen_emitter_has_no_code`, `autogen_children_marker_missing`, and `autogen_children_fallback_insert` diagnostics during generated refresh. No UID0004C5-specific validator error or warning was reported.
- Generated freshness:
  - `auto-generated/NexusTK/input/IMEPanes.cpp` header after validation:
    - `validator-command-id: 000000003181`
    - `validator-refreshed-at: 2026-06-30T16:09:15-04:00`
    - `validator-refresh-source: deferred-generated-refresh`
  - This header is equal to the final aggregate validator command and newer than the required target/class/file `--wait-generated` commands.
  - `rg` found `// UID:0004C5 | by-memory/0x004e7840-0x004e7912.IMECompositionPaneOnPaint.md | Completion:88 | Confidence:91` and `void IMECompositionPane::OnPaint()` in generated `IMEPanes.cpp`.
  - No UID0004C5 empty-emitter marker remains in generated `IMEPanes.cpp`.

## Changed Files
- Created: none in callback mode.
- Modified:
  - `by-memory/0x004e7840-0x004e7912.IMECompositionPaneOnPaint.md`
  - `by-class/IMECompositionPane.md`
  - `by-file/IMEPanes.md`
  - `by-memory/0x004e70f0-0x004e8433.IMEPaneFamily.md`
  - `tools/leaser/Agents/Agent-B008/research/0004C5-IMECompositionPaneOnPaint-source-quality.md`
- Renamed: none.
- Report execution: blank; supervisor runs report execution after verification.

## Implementation Tracking Checklist

Report-only evidence pass:
- [x] Supervisor validation required before implementation.
- [x] Current target state and actual evidence checked recorded.
- [x] Current MCP evidence collected with narrow schema-current calls; MCP was available and responsive.
- [x] Claim And Incorporation Ledger prepared with destination/action and report-only `proposed` verification state.
- [x] Metadata/score changes to apply identified but not implemented.
- [x] Score-limiting blockers researched to resolution or confidence-capped implementation-ready inference.
- [x] Owner/emitter/reconstructable changes to apply identified but not implemented.
- [x] Split/rename/new-child changes confirmed not applicable.
- [x] Source-placement, range, padding, and reclassification analysis completed.
- [x] Exact first-draft C++ insertion text prepared.
- [x] Third-party import directive confirmed not applicable.
- [x] Exact target/support doc facts to incorporate listed.
- [x] Historical/stale assumptions and rejected alternatives preserved.
- [x] Wave3 mention encountered in aggregate doc and treated as historical context only.
- [x] Open questions closed or documented as naming-confidence caveats.
- [x] Validators to run during callback listed.
- [x] Generated refresh expectation documented without editing generated files.

Implementation callback pass:
- [x] Report accepted by supervisor for implementation. Proof: user/supervisor callback explicitly accepted `research/0004C5-IMECompositionPaneOnPaint-source-quality.md` for implementation.
- [x] Re-read target/support docs and check leases immediately before editing. Proof: re-read target, class, file, aggregate, optional SetCompositionString, report, current lease report, and leaser README; no active relevant lease conflict was present.
- [x] Target metadata `88/91`, `EMITTER_UIDS:00006G`, and exact C++ block applied. Proof: `by-memory/0x004e7840-0x004e7912.IMECompositionPaneOnPaint.md` metadata now has `COMPLETION:88`, `CONFIDENCE:91`, `EMITTER_UIDS:00006G`, unchanged owner/reconstructable/blank position, and the accepted formal `IMECompositionPane::OnPaint()` block.
- [x] Target behavior/evidence/reconstruction/score/changelog text updated at report-level detail. Proof: target now contains MCP evidence, draw sequence table, helper mapping, field consumption, rejected alternatives, stale blocker historicalization, score rationale, and 2026-06-30 B008 change entry.
- [x] Support docs updated or explicitly marked already-present/excluded with proof. Proof: `by-class/IMECompositionPane.md`, `by-file/IMEPanes.md`, and `by-memory/0x004e70f0-0x004e8433.IMEPaneFamily.md` were updated; `by-memory/0x004e7470-0x004e763c.IMECompositionSetCompositionString.md` was already present for field/caret relation; GrafPort/Surface helper pages excluded because current helper names were already present.
- [x] Claim And Incorporation Ledger updated from `proposed` to `applied`, `already-present`, `excluded-with-reason`, or `blocked`. Proof: all C1-C11 rows now have callback verification states and proof; no row remains `proposed`.
- [x] Historical/stale assumptions, rejected alternatives, and negative evidence preserved in by-* docs. Proof: target rejects stale graphics-helper/no-code blocker, raw helper/source-name aliases, GrafPort/Surface/aggregate/no-code/source-split alternatives, and no-direct-code-caller/vtable-only evidence.
- [x] Scoped validators run and command ids/timestamps/exit/ok/warnings recorded. Proof: validators `000000003177`, `000000003178`, `000000003179`, and `000000003181` all exited `0` with `ok:1`; common unrelated generated-refresh diagnostics are recorded above.
- [x] Generated `NexusTK/input/IMEPanes.cpp` freshness confirmed by validator with `--wait-generated`. Proof: target/class/file validators used `--wait-generated`; generated `IMEPanes.cpp` header is `validator-command-id: 000000003181`, `validator-refreshed-at: 2026-06-30T16:09:15-04:00`, and contains UID0004C5 `IMECompositionPane::OnPaint()` with no UID0004C5 empty marker.
- [x] All leases released immediately after the edit/validator batch. Proof: `python leaser.py B008 unlease` reported success for target/class/file/aggregate leases; final current lease report lists no active B008 leases.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B008","command_id":"000000004165","destination_path":"executed-b-agent-research/B008/0004C5-IMECompositionPaneOnPaint-source-quality.md","details":"legacy registry reconstruction","event":"executed","source_path":"tools/leaser/Agents/Agent-B008/research/0004C5-IMECompositionPaneOnPaint-source-quality.md","timestamp":"2026-06-30T16:21:32","uid":"0004C5"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
