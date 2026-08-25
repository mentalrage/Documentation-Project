** TARGET-REPORT-UID:0004C9 **
** AUTHOR-AGENT-ID:B010 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# B010 Source Quality Report: [UID:0004C9] IMECandidatePane::OnPaint

Assignment: `B010-report-0004C9-IMECandidatePaneOnPaint-20260630`
Mode: report-first research only
Agent: B010
Report timestamp: 2026-06-30T15:53:01-04:00

Target:

- [UID:0004C9] `by-memory/0x004e7d30-0x004e7f1a.IMECandidatePaneOnPaint.md`
- Queue basis: `auto-generated/-ag-research-tracker.md` -> `## by-memory` -> `### Not-Covered Files - Reconstructable`
- Tracker state: `80/86`, combined `83.0`, reconstructable `true`, reports `0`

## Current Target State

[UID:0004C9] is an exact IMECandidatePane paint split child. The page currently has:

- `COMPLETION: 80`
- `CONFIDENCE: 86`
- `CANONICAL_OWNER: 00006F`
- `RECONSTRUCTABLE: TRUE`
- blank `EMITTER_UIDS`
- blank formal `RECONSTRUCTION_CPP`

The target page already points to owner [UID:00006F] `IMECandidatePane`, source route `[00006F] -> [0000K5] IMEPanes`, and aggregate [UID:000189] `IMEPaneFamily`. Its current blocker text says detailed draw-call and row-highlight names remain a child-specific C++ task. Current evidence resolves that blocker: the function is a source-authored virtual paint body with enough exact helper, field, and row-loop evidence for a first-draft formal C++ body.

## MCP Availability And Provenance

Current IDA MCP evidence was available and used. No fallback-only evidence was used.

- MCP server: `ida-pro-mcp`, protocol `2025-06-18`
- `idb_list`: active worker session `supervisor_resume_20260629`
- Active IDB: `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`
- `server_health`: `status: ok`, `auto_analysis_ready: true`, `hexrays_ready: true`, `strings_cache_ready: true`, `strings_cache_size: 2067`
- Worker process: active MCP-owned/adopted worker for `NexusTK.exe.i64`
- Narrow MCP calls used: `lookup_funcs`, `analyze_function`, `decompile`, `disasm`, `xrefs_to`, `callees`, and helper decompiles/components for direct callees only

Key function identity evidence:

- `lookup_funcs 0x004e7d30` -> `sub_4E7D30`, size `0x1ea`
- Function range is exactly `0x004e7d30-0x004e7f1a`
- `lookup_funcs 0x004e7f1a` -> no function
- `lookup_funcs 0x004e7f20` -> next function `sub_4E7F20`, size `0xd5`
- `analyze_function 0x004e7d30`: size 490 bytes, 29 basic blocks, cyclomatic complexity 14
- `xrefs_to 0x004e7d30`: data xref from vtable address `0x0061c4b8`; no direct code callers
- `callees 0x004e7d30`: `0x004b9660`, `0x0069b3fc`, `0x004ba450`, `0x004b9680`, `0x004baaa0`, `0x004b9600`, `0x004bab70`, `0x005c772f`

## Project Evidence Checked

By-doc and generated leads checked:

- `by-memory/0x004e7d30-0x004e7f1a.IMECandidatePaneOnPaint.md`
- `by-class/IMECandidatePane.md` [UID:00006F]
- `by-file/IMEPanes.md` [UID:0000K5]
- `by-memory/0x004e70f0-0x004e8433.IMEPaneFamily.md` [UID:000189]
- `by-memory/0x004e7930-0x004e7b6c.IMECandidateShowCandidateList.md` [UID:00018B]
- `by-memory/0x004ba9a0-0x004bad66.GrafPortTextRunHelpers.md`
- `by-memory/0x004b95e0-0x004b969f.GrafPortDrawStateAccessors.md`
- `by-memory/0x004e8450-0x004e8ae6.IMECandidateQueueAndDestructors.md`
- `by-class/CandidateStringQueue.md`
- `by-type/by-template/CandidateStringDequeTemplate.md`
- `auto-generated/-ag-research-tracker.md`
- `auto-generated/-ag-memory-coverage.md`
- `auto-generated/NexusTK/input/IMEPanes.cpp`
- Prior B008 report `executed-b-agent-research/B008/0000K5-IMEPanes-empty-emitter-family-source-quality.md`

Generated-output state:

- `auto-generated/-ag-memory-coverage.md` lists [UID:0004C9] as `non-emits`, owner `00006F`, blank emitter.
- `auto-generated/NexusTK/input/IMEPanes.cpp` was last refreshed by validator command `000000003148` at `2026-06-30T15:45:03-04:00`.
- Searching that generated file for `UID:0004C9`, `IMECandidatePaneOnPaint`, and `0x004e7d30` found no target marker or code. This is expected from the blank `EMITTER_UIDS`; the accepted fix should cause [UID:0004C9] to route through [UID:00006F] into [UID:0000K5] and appear in generated `IMEPanes.cpp`.

Prior-report state:

- B008 created or classified [UID:0004C9] as an exact child under `IMEPanes`, but explicitly left newly-created child pages with blank `EMITTER_UIDS` and blank child-specific body until a child-specific report accepted the body.
- No prior active B-agent report for [UID:0004C9] was found before this assignment.

## Positive Evidence

The body is a real source-authored virtual paint routine, not a compiler wrapper or no-code case.

Function-level evidence:

- Vtable xref at `0x0061c4b8` identifies the routine as a virtual method body.
- The function has a security cookie, 29 basic blocks, a row loop, conditionals, drawing calls, and string traversal. This is not a scalar deleting destructor, thunk, or empty forwarding wrapper.
- It draws a full candidate popup background/frame, then iterates visible candidate strings and conditionally draws the selected-row highlight.

Helper-name evidence:

- `0x004b9660` writes `this + 0x74`; accepted helper page names this `GrafPort::SetDrawColor`.
- `0x004b9680` writes `this + 0x7c`; accepted helper page names this `GrafPort::SetTextColor`. The helper page also says stale generated `SetBkColor` naming for this address should not be used.
- `0x004b9600` writes current draw cursor X/Y at `this + 0x6c` and `this + 0x68`; accepted helper page names this `GrafPort::MoveTo`.
- `0x004ba450` is accepted as `GrafPort::DrawRectFrame`.
- `0x004baaa0` is accepted as `GrafPort::GetLineHeight`.
- `0x004bab70` is accepted as `GrafPort::DrawWideText(const wchar_t *text, int charCount)`.
- `0x0069b3fc` is an external surface fill/callback used here for the whole bounds and selected-row rectangle. Source-facing draft should use the existing pane/GrafPort fill helper name, recommended as `FillRect`, with the exact external address documented.

Field and layout evidence:

- [UID:00006F] class shell already places `visibleCandidates` at `+0xf8`, `selectedCandidateRow` at `+0x10c`, `candidateAnchorY` at `+0x110`, and `candidateAnchorX` at `+0x114`.
- Target disassembly reads:
  - `this + 0xf8`: deque storage/proxy area for `visibleCandidates`
  - `this + 0x104`: deque head/offset
  - `this + 0x108`: deque active element count
  - `this + 0x10c`: `selectedCandidateRow`
- The target does not read `candidateAnchorX` or `candidateAnchorY`; those are setup/layout fields used by [UID:00018B] `ShowCandidateList`.
- [UID:00018B] already proves the same class fields and source route by populating `visibleCandidates`, `selectedCandidateRow`, popup bounds, and invalidation for the candidate pane.
- Candidate deque support pages prove the STL/Dinkumware container shape should be source-authored as `std::deque<std::wstring>`, not as generated raw map/offset arithmetic.

Behavior evidence from target decompile/disassembly:

- Initial background:
  - `SetDrawColor(143)`
  - fill `bounds` via `0x0069b3fc(this, this + 0x44)`
- Frame and default text:
  - `SetDrawColor(128)`
  - `DrawRectFrame(&bounds)`
  - `SetTextColor(128)`
- Row metrics:
  - calls `GetLineHeight()`
  - computes `rowStep = lineHeight + 2`
  - initializes text baseline to `rowStep`
- Loop:
  - loops from deque head/offset to head plus active count
  - calls `MoveTo(1, textY)` for every row
  - increments row index and text Y by `rowStep`
- Selected row:
  - compares row index with `selectedCandidateRow` at `+0x10c`
  - selected rect `left = 1`
  - selected rect `top = row * (lineHeight + 2) + 2`
  - selected rect `right = bounds.right - bounds.left`
  - selected rect `bottom = top + lineHeight + 1`
  - fills selected rect through `0x0069b3fc`
  - temporarily sets text color to `143`
  - draws selected text
  - restores text color to `128`
- Non-selected row:
  - draws text at the current cursor using the default text color
- String drawing:
  - generated raw code follows Dinkumware deque map slots and short-string heap/inline selection
  - source-level code should use `const std::wstring& candidate = *it`
  - target computes the wide-character length with a manual `wcslen`-equivalent loop before `DrawWideText`

## Negative Evidence And Rejected Alternatives

Rejected no-code disposition:

- Not acceptable. The body has nontrivial paint logic, custom row geometry, container traversal, and draw helper calls. It is neither compiler-only nor a pure declaration/route marker.

Rejected wrapper/thunk disposition:

- Not acceptable. The function does not simply forward to another target. It directly performs drawing and iteration.

Rejected "leave helper names open":

- Not acceptable. The direct GrafPort helper addresses are already documented in accepted helper pages, and MCP confirms the target calls those exact helpers.

Rejected owner `GrafPort`:

- `GrafPort` supplies drawing helpers, but the function reads IMECandidatePane fields and is reached by the IMECandidatePane vtable slot.

Rejected owner `InputMan` or IME manager:

- Event/input manager code may drive IME state, but this target is pane-side paint output over candidate-list fields and bounds.

Rejected owner `CandidateStringQueue` or raw STL helper:

- Raw deque internals appear only because of compiler lowering. Source-authored code should use the `IMECandidatePane::visibleCandidates` member.

Rejected new by-file/source split:

- Existing route `[00006F] -> [0000K5]` is correct. [UID:0000K5] already owns IME pane-side UI source. No new file, split, rename, or owner move is needed.

Rejected function split:

- `lookup_funcs` proves the exact function is `0x004e7d30` size `0x1ea`, ending at `0x004e7f1a`; the next function starts at `0x004e7f20`. The whole routine is one virtual paint method.

## Heuristic And Inference Reanalysis

The current `80/86` state is explainable as a source-quality gap, not as a true unreconstructable target:

- Earlier B008 work intentionally established split children and deferred their child-specific bodies.
- The target was left non-emitting because no child-specific C++ had been accepted yet.
- The route is already known and valid through [UID:00006F] and [UID:0000K5].
- The decompiler exposes raw Dinkumware deque arithmetic, but support pages and [UID:00018B] already justify the source-level member as `std::deque<std::wstring> visibleCandidates`.
- The remaining inferred names are ordinary source-facing helper names around an external fill call and palette constants; those should be documented as caveats, not allowed to block formal C++ insertion.

Inference limits to preserve:

- Color constants `143` and `128` are exact binary values. No evidence proves original symbolic names.
- `FillRect` is the recommended source-facing name for the `0x0069b3fc` external fill operation, but the exact original method/member name is not proven.
- The selected-row rectangle is expressed in local pane coordinates; `right = bounds.right - bounds.left` matches the disassembly's width calculation.
- `DrawWideText(candidate.c_str(), static_cast<int>(candidate.length()))` is source-equivalent to the target's manual wide-character length loop.

## Ranked Ownership And Source Placement

1. [UID:00006F] `IMECandidatePane` as canonical owner and emitter route node
   - Evidence: vtable xref at `0x0061c4b8`, class fields read by target, existing class shell with `OnPaint`, and child route already established.
   - Recommendation: keep `CANONICAL_OWNER: 00006F`; set target `EMITTER_UIDS: 00006F`.

2. [UID:0000K5] `IMEPanes` as source file emitter
   - Evidence: existing file owns pane-side IME UI, class [UID:00006F] emits through [UID:0000K5], and generated `IMEPanes.cpp` already contains related IMECandidatePane source.
   - Recommendation: no owner/file move; generated output should place `IMECandidatePane::OnPaint` in `NexusTK/input/IMEPanes.cpp`.

3. [UID:000189] `IMEPaneFamily` as aggregate route/support page
   - Evidence: existing aggregate owns split-family context and has `[[CHILDREN]]`.
   - Recommendation: update only child row/status if implementation callback wants aggregate synchronization.

4. Helper/support pages as evidence-only
   - GrafPort helper pages and candidate deque support pages already carry the needed helper/layout evidence.
   - Recommendation: do not make them implementation targets unless supervisor explicitly requests cross-reference synchronization.

## Score And Metadata Recommendation

Target [UID:0004C9]:

- Before: `COMPLETION: 80`, `CONFIDENCE: 86`, blank `EMITTER_UIDS`, blank formal C++
- After recommended: `COMPLETION: 88`, `CONFIDENCE: 90`, `EMITTER_UIDS: 00006F`, formal C++ body populated
- Rationale: ownership, route, vtable identity, helper names, field layout, row-loop behavior, and generated absence reason are now evidence-backed. Keep below low/mid-90s because original symbolic names for color constants and exact fill-helper name remain inferred.

Support [UID:00006F] `by-class/IMECandidatePane.md`:

- Before: `87/90`
- After recommended: `88/90`
- Rationale: add exact `OnPaint` child behavior and field-use evidence. Class shell and `[[CHILDREN]]` are already correct; only a modest completion increase is warranted.

Support [UID:0000K5] `by-file/IMEPanes.md`:

- Before: `90/88`
- After recommended: unchanged `90/88`
- Rationale: file route is already strong. This target improves one child but does not resolve every IMEPanes split-child body.

Support [UID:000189] `by-memory/0x004e70f0-0x004e8433.IMEPaneFamily.md`:

- Before: `87/90`
- After recommended: unchanged `87/90`
- Rationale: aggregate route is already correct; update the row/disposition for [UID:0004C9] without claiming broader family completion.

Support [UID:00018B] `by-memory/0x004e7930-0x004e7b6c.IMECandidateShowCandidateList.md`:

- Before: `89/91`
- After recommended: unchanged `89/91`
- Rationale: used as field/layout evidence only. No source-quality issue found in that page for this assignment.

GrafPort and deque support pages:

- Recommendation: no score or metadata changes. They are evidence sources only.

## Formal RECONSTRUCTION_CPP Recommendation

Recommended formal `RECONSTRUCTION_CPP CODE` content for [UID:0004C9]:

```cpp
void IMECandidatePane::OnPaint()
{
    SetDrawColor(143);
    FillRect(&bounds);

    SetDrawColor(128);
    DrawRectFrame(&bounds);

    SetTextColor(128);

    const int lineHeight = GetLineHeight();
    const int rowStep = lineHeight + 2;
    int textY = rowStep;
    int row = 0;

    for (CandidateStringList::const_iterator it = visibleCandidates.begin();
         it != visibleCandidates.end();
         ++it, ++row) {
        const std::wstring& candidate = *it;

        MoveTo(1, textY);

        if (row == selectedCandidateRow) {
            RectBounds selectedRowBounds;
            selectedRowBounds.left = 1;
            selectedRowBounds.top = row * rowStep + 2;
            selectedRowBounds.right = bounds.right - bounds.left;
            selectedRowBounds.bottom = selectedRowBounds.top + lineHeight + 1;

            FillRect(&selectedRowBounds);

            SetTextColor(143);
            DrawWideText(candidate.c_str(), static_cast<int>(candidate.length()));
            SetTextColor(128);
        } else {
            DrawWideText(candidate.c_str(), static_cast<int>(candidate.length()));
        }

        textY += rowStep;
    }
}
```

Implementation notes for the formal block:

- Do not leave this as prose-only draft C++; insert it into the target formal `RECONSTRUCTION_CPP CODE` block if supervisor approves implementation.
- Keep numeric color values unless a separate accepted color-constant page proves original symbolic names.
- `FillRect` should be documented in target notes as the source-facing name for external fill call `0x0069b3fc`; if the project has a better accepted fill helper spelling, use that spelling consistently during implementation and record the substitution in the report ledger.
- `CandidateStringList` is already typedefed on [UID:00006F] as `std::deque<std::wstring>`.
- The `RectBounds` field names are source-level names matching existing bounds usage on the class and helper pages.

## Implementation-Ready Target And Support Changes

Target [UID:0004C9] `by-memory/0x004e7d30-0x004e7f1a.IMECandidatePaneOnPaint.md`:

- Set `COMPLETION: 88`.
- Set `CONFIDENCE: 90`.
- Keep `CANONICAL_OWNER: 00006F`.
- Keep `RECONSTRUCTABLE: TRUE`.
- Set `EMITTER_UIDS: 00006F`.
- Populate formal `RECONSTRUCTION_CPP CODE` with the recommended `IMECandidatePane::OnPaint` body above.
- Add evidence notes for:
  - MCP session `supervisor_resume_20260629`
  - function range `0x004e7d30-0x004e7f1a`, size `0x1ea`
  - vtable xref `0x0061c4b8`
  - helper address/name mapping
  - `visibleCandidates` and `selectedCandidateRow` offsets
  - selected-row rectangle formula
  - generated non-emitter absence and expected generated route
  - rejected no-code/wrapper/GrafPort/raw-STL alternatives

Support [UID:00006F] `by-class/IMECandidatePane.md`:

- Recommended metadata: `COMPLETION: 88`, `CONFIDENCE: 90`.
- Keep owner/emitter route unchanged through [UID:0000K5].
- Keep class formal block with `[[CHILDREN]]`.
- Add concise child evidence that `OnPaint` [UID:0004C9] consumes `visibleCandidates`, `selectedCandidateRow`, inherited `bounds`, and GrafPort draw helpers to paint candidate popup rows.
- Add field-use note:
  - `visibleCandidates +0xf8` is traversed as deque source container
  - `selectedCandidateRow +0x10c` selects the highlighted row
  - `candidateAnchorX/Y` are not used by `OnPaint`; they are populated by `ShowCandidateList`

Support [UID:0000K5] `by-file/IMEPanes.md`:

- Recommended score unchanged.
- Add or amend implementation note that [UID:0004C9] is no longer intended to remain non-emitting after accepted callback and should route through [UID:00006F] into generated `NexusTK/input/IMEPanes.cpp`.
- Do not create a new by-file or change file ownership.

Support [UID:000189] `by-memory/0x004e70f0-0x004e8433.IMEPaneFamily.md`:

- Recommended score unchanged.
- Update the split/source-placement table row for `0x004e7d30-0x004e7f1a` to state that [UID:0004C9] has an implementation-ready `IMECandidatePane::OnPaint` body and emits through [UID:00006F] -> [UID:0000K5] once accepted.

Support [UID:00018B] `by-memory/0x004e7930-0x004e7b6c.IMECandidateShowCandidateList.md`:

- No required edit.
- If supervisor wants synchronization, add a cross-reference only: [UID:0004C9] consumes the `visibleCandidates`, `selectedCandidateRow`, and bounds prepared by `ShowCandidateList`.

Evidence-only pages, no implementation edit recommended:

- `by-memory/0x004ba9a0-0x004bad66.GrafPortTextRunHelpers.md`
- `by-memory/0x004b95e0-0x004b969f.GrafPortDrawStateAccessors.md`
- `by-memory/0x004e8450-0x004e8ae6.IMECandidateQueueAndDestructors.md`
- `by-class/CandidateStringQueue.md`
- `by-type/by-template/CandidateStringDequeTemplate.md`

## Generated Output Expectations

After an implementation callback and scoped validation:

- Applied 2026-06-30 B010 implementation callback: [UID:0004C9] no longer has blank `EMITTER_UIDS` and now emits through [UID:00006F].
- Generated `auto-generated/NexusTK/input/IMEPanes.cpp` was refreshed by validator command `000000003166` at `2026-06-30T16:01:30-04:00`, matching the last B010 support validator metadata. Final post-release sanity check observed a newer generated header, command `000000003169` at `2026-06-30T16:02:42-04:00`, with the [UID:0004C9] marker/body still present.
- The generated file contains `// UID:0004C9 | by-memory/0x004e7d30-0x004e7f1a.IMECandidatePaneOnPaint.md | Completion:88 | Confidence:90` and `void IMECandidatePane::OnPaint()`.
- Search found no `UID:0004C9` empty-emitter marker.
- No generated C++ file was edited manually.

## Implementation Callback Validation Results

All validators were run from `E:\NTK\GhidraBridge\source-3\project-documentation` with `--apply --wait-generated --queue-timeout 240`.

| File | Command | command_id | command_timestamp | Exit | ok | Generated state | Warnings / side effects |
|---|---|---|---|---|---|---|---|
| `by-memory/0x004e7d30-0x004e7f1a.IMECandidatePaneOnPaint.md` | `python .\tools\validator.py --mode file --file by-memory/0x004e7d30-0x004e7f1a.IMECandidatePaneOnPaint.md --apply --wait-generated --queue-timeout 240` | `000000003163` | `2026-06-30T16:00:40-04:00` | `0` | `1` | `generated_refresh: completed`, generated command/timestamp matched command metadata. | Target updates included completion/confidence, emitter registry update, `block` C++ registry state, generated C++ update, research tracker/memory auto coverage/projected stats updates; broad existing autogen warnings included `autogen_children_marker_missing:64`, `autogen_emitter_has_no_code:292`, and `autogen_children_fallback_insert:9`. |
| `by-class/IMECandidatePane.md` | `python .\tools\validator.py --mode file --file by-class/IMECandidatePane.md --apply --wait-generated --queue-timeout 240` | `000000003164` | `2026-06-30T16:00:57-04:00` | `0` | `1` | `generated_refresh: completed`, generated command/timestamp matched command metadata. | Completion update for `00006F`, reference index add for `0004C9`, projected stats update; same broad existing autogen marker/no-code warnings. |
| `by-file/IMEPanes.md` | `python .\tools\validator.py --mode file --file by-file/IMEPanes.md --apply --wait-generated --queue-timeout 240` | `000000003165` | `2026-06-30T16:01:13-04:00` | `0` | `1` | `generated_refresh: completed`, generated command/timestamp matched command metadata. | UID link inserts for `0004C9` and `00006F`, reference index add, projected stats update; same broad existing autogen marker/no-code warnings. |
| `by-memory/0x004e70f0-0x004e8433.IMEPaneFamily.md` | `python .\tools\validator.py --mode file --file by-memory/0x004e70f0-0x004e8433.IMEPaneFamily.md --apply --wait-generated --queue-timeout 240` | `000000003166` | `2026-06-30T16:01:30-04:00` | `0` | `1` | `generated_refresh: completed`; `auto-generated/NexusTK/input/IMEPanes.cpp` header now has `validator-command-id: 000000003166`, `validator-refreshed-at: 2026-06-30T16:01:30-04:00`. | UID link insert for `00006F`, memory auto coverage/projected stats updates; same broad existing autogen marker/no-code warnings. |

Generated inspection:

- `auto-generated/NexusTK/input/IMEPanes.cpp` B010 validator header after command `000000003166`: `validator-command-id: 000000003166`, `validator-refreshed-at: 2026-06-30T16:01:30-04:00`, source by-file UID `0000K5`.
- Final post-release sanity check observed current generated header `validator-command-id: 000000003169`, `validator-refreshed-at: 2026-06-30T16:02:42-04:00`; the [UID:0004C9] marker/body remained present.
- [UID:0004C9] marker/body present at generated lines around 95-96 as `void IMECandidatePane::OnPaint()`.
- No `UID:0004C9` empty-emitter marker found.

Lease proof:

- Leased immediately before edit/validator batch as `B010`: `by-memory/0x004e7d30-0x004e7f1a.IMECandidatePaneOnPaint.md`, `by-class/IMECandidatePane.md`, `by-file/IMEPanes.md`, and `by-memory/0x004e70f0-0x004e8433.IMEPaneFamily.md`.
- Lease report showed creation `2026-06-30T19:57:57Z`, expiration `2026-06-30T20:02:57Z`.
- Released immediately after generated inspection: leaser returned `Success` for all four files.

## Claim And Incorporation Ledger

| Claim | Evidence | Recommended incorporation | Status |
|---|---|---|---|
| [UID:0004C9] is exact function `0x004e7d30-0x004e7f1a`, size `0x1ea`. | MCP `lookup_funcs`; next function starts at `0x004e7f20`. | Target evidence section. | applied: target Evidence records exact range/size and next-function boundary. |
| [UID:0004C9] is source-authored virtual paint code, not no-code. | Vtable data xref `0x0061c4b8`; 490-byte body; row loop and draw helpers. | Target no-code rejection and formal C++ body. | applied: target Status/Behavior/Evidence/Reconstruction Notes/Rejected Alternatives and formal C++ body record source-authored virtual paint disposition. |
| Owner remains [UID:00006F]. | Existing target route, class shell, vtable slot, field reads. | Keep `CANONICAL_OWNER: 00006F`. | applied: target metadata unchanged at `CANONICAL_OWNER:00006F`; class/file/aggregate support notes preserve route. |
| Emitter should become [UID:00006F]. | Existing class emits through [UID:0000K5] and has `[[CHILDREN]]`; generated file currently lacks target because emitter is blank. | Set `EMITTER_UIDS: 00006F`. | applied: target metadata `EMITTER_UIDS:00006F`; generated `IMEPanes.cpp` now contains `UID:0004C9` body. |
| Source file remains [UID:0000K5] `IMEPanes`. | File owns IME pane-side UI and generated `IMEPanes.cpp` already contains related IMECandidatePane code. | No file split or owner change. | applied: no split/rename/new file; `by-file/IMEPanes.md` and generated `IMEPanes.cpp` preserve route. |
| `visibleCandidates` is source-level deque member. | [UID:00006F] class shell, [UID:00018B], deque support pages, target reads at `+0xf8/+0x104/+0x108`. | Use `CandidateStringList::const_iterator`. | applied: target formal C++ uses `CandidateStringList::const_iterator`; target/class evidence records offsets and source-level deque member. |
| `selectedCandidateRow` is `+0x10c`. | Target compare against `[esi+10Ch]`; [UID:00006F] and [UID:00018B] field evidence. | Use `if (row == selectedCandidateRow)`. | applied: target formal C++ and target/class evidence record selected-row comparison and offset. |
| Helper names are sufficient for first-draft body. | Accepted GrafPort helper pages and MCP direct helper decompiles. | Use `SetDrawColor`, `SetTextColor`, `MoveTo`, `DrawRectFrame`, `GetLineHeight`, `DrawWideText`, `FillRect`. | applied: target formal C++ uses those names; target/class/file evidence records helper mapping and `FillRect` inference caveat. |
| Color values are exact but symbolic names are unproven. | Target constants `143` and `128`; no source constant page found. | Keep numeric constants and document caveat. | applied: formal C++ keeps `143` and `128`; target/class notes document symbolic-name caveat. |
| Support class should retain `[[CHILDREN]]`. | [UID:00006F] already routes child methods; target should emit through child route. | Do not remove or replace class route marker. | already-present: [UID:00006F] formal class block already had `[[CHILDREN]]`; callback left it unchanged and validator generated target through that route. |
| [UID:0004C9] generated absence is due blank emitter. | Generated `IMEPanes.cpp` lacked target marker after refresh `000000003148`; coverage listed target as non-emits. | Expected output should appear only after emitter/body insertion and validation. | applied: target/generated notes record prior absence; generated `IMEPanes.cpp` now has command `000000003166` and `UID:0004C9` marker/body with no target empty-emitter marker. |

## Implementation Tracking Checklist

- [x] Lease only the accepted target/support by-* files immediately before implementation. Proof: leased target, class, file, and aggregate as `B010` at `2026-06-30T19:57:57Z`, expiring `2026-06-30T20:02:57Z`.
- [x] Update [UID:0004C9] metadata to `88/90` and `EMITTER_UIDS: 00006F`. Proof: target header now has `COMPLETION:88`, `CONFIDENCE:90`, `EMITTER_UIDS:00006F`; validator `000000003163` recorded completion/confidence and emitter registry updates.
- [x] Insert the formal `IMECandidatePane::OnPaint` C++ body into [UID:0004C9]. Proof: target formal `RECONSTRUCTION_CPP CODE` block contains the accepted body; generated `IMEPanes.cpp` line around 95 emits `void IMECandidatePane::OnPaint()`.
- [x] Add target evidence for MCP session, function size/range, vtable xref, helper mapping, offsets, selected-row geometry, generated absence, and rejected alternatives. Proof: target Status, Behavior, Evidence, Reconstruction Notes, Rejected Alternatives, Score Rationale, and Changes sections updated.
- [x] Update [UID:00006F] `IMECandidatePane` with child behavior/field-use evidence and keep `[[CHILDREN]]`. Proof: class score now `88/90`; method/field/evidence/change notes added; formal block still has `[[CHILDREN]]`; validator `000000003164` ok.
- [x] Update [UID:0000K5] `IMEPanes` route/generation expectation without changing owner or source path. Proof: file score/owner/path unchanged; Proposed Contents, Evidence Notes, and Changes now name [UID:0004C9] as an emitting child routed into `NexusTK/input/IMEPanes.cpp`; validator `000000003165` ok.
- [x] Update [UID:000189] split row/disposition for [UID:0004C9] if included in callback scope. Proof: aggregate split row now states [UID:0004C9] is `88/90`, formal C++ populated, emits through [UID:00006F], and rejects no-code/wrapper/raw-STL ownership; validator `000000003166` ok.
- [x] Leave [UID:00018B] unchanged unless supervisor requests cross-reference synchronization. Proof: no edit made; current file state did not conflict because [UID:00018B] already supplied setup-field evidence and the callback treated it as read-only evidence.
- [x] Do not edit generated files, coverage reports, validator state, queue/lock files, IDA DB, or supervisor ledgers. Proof: only by-* docs and this B010 report were manually edited; generated files/reports/tool state were changed only by validator commands.
- [x] Run scoped validators for every changed by-* file during implementation callback. Proof: validators `000000003163`, `000000003164`, `000000003165`, and `000000003166` all exited `0` with `ok:1`.
- [x] Run final scoped file validator with generated wait for `by-file/IMEPanes.md` if [UID:0000K5] is changed. Proof: `by-file/IMEPanes.md` validator `000000003165` ran with `--wait-generated`; subsequent aggregate validator `000000003166` also refreshed generated output.
- [x] Inspect generated `auto-generated/NexusTK/input/IMEPanes.cpp` for [UID:0004C9] marker/body after validation. Proof: generated header command `000000003166`, timestamp `2026-06-30T16:01:30-04:00`; `UID:0004C9` marker/body present; no target empty-emitter marker found. Final post-release sanity check saw newer generated command `000000003169` at `2026-06-30T16:02:42-04:00`, still with `UID:0004C9` marker/body and no target empty-emitter marker.
- [x] Release all leases immediately after the implementation/validation batch. Proof: `python .\tools\leaser\leaser.py B010 unlease ...` returned `Success` for all four leased by-* files.
- [x] Update this report's ledger/checklist with applied/already-present/excluded proof during implementation callback. Proof: this callback section, validation table, ledger statuses, and checked checklist were updated after validation/generation inspection.

## Blockers

No current blocker. MCP was available and returned current IDA-backed evidence. The remaining unknowns are limited to original symbolic color names and the exact original spelling of the external fill helper, and those are documented inference caveats rather than score blockers.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B010","command_id":"000000004165","destination_path":"executed-b-agent-research/B010/0004C9-IMECandidatePaneOnPaint-source-quality.md","details":"legacy registry reconstruction","event":"executed","source_path":"tools/leaser/Agents/Agent-B010/research/0004C9-IMECandidatePaneOnPaint-source-quality.md","timestamp":"2026-06-30T16:11:09","uid":"0004C9"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
