** TARGET-REPORT-UID:0002FP **
** AUTHOR-AGENT-ID:B002 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# B002-goal2-chatting-ui-raw-helper-source-quality-0002FP-0002FQ-0002FW-0002G0-0002G1-0002G9-20260616

Status: FINISHED

Scope: report-only B-agent research for [UID:0002FP], [UID:0002FQ], [UID:0002FW], [UID:0002G0], [UID:0002G1], and [UID:0002G9]. No by-* docs, generated reports, source files, IDA DB, or coverage report were edited.

## Evidence Checked

Instruction and project rules checked:

- `tools/leaser/Agents/Supervisor.md`
- `tools/leaser/Agents/Agent-B002/goal.md`
- `tools/leaser/Agents/Agent-B002/notes.md`
- `by-structure.md`
- `inference_research.md`
- `by-project-structure/proposed-source-tree.md`

Target docs checked:

- `by-memory/0x00481b60-0x00481bb9.ChattingVarietySelectPaneStateCompareHelper.md`
- `by-memory/0x00481bc0-0x00481c05.ChattingVarietySelectPaneStateSnapshotHelper.md`
- `by-memory/0x00482310-0x00482400.ChatButtonRectHelperRaw.md`
- `by-memory/0x00482c40-0x00482c54.ChattingColorPaneRefreshColorSelectHelperRaw.md`
- `by-memory/0x00482c60-0x00482c9f.ChattingColorPaneSyncColorListSelectionHelperRaw.md`
- `by-memory/0x00483260-0x0048326f.ChattingColorListPaneGetSelectedColorValueRaw.md`

Neighbor and owner docs checked:

- `by-class/ChattingVarietySelectPane.md`
- `by-class/ChattingHandlePane.md`
- `by-class/ChattingColorPane.md`
- `by-class/ChattingColorSelectPane.md`
- `by-class/ChattingColorListPane.md`
- `by-file/Chatting.md`
- `by-memory/0x004811c0-0x00481461.ChattingVarietySelectPaneOnMouseEvent.md`
- `by-memory/0x00481ad0-0x00481b5b.ChattingVarietySelectPaneHitTest.md`
- `by-memory/0x00481d60-0x0048214f.ChattingHandlePaneOnMouseEvent.md`
- `by-memory/0x00482150-0x004822f6.ChattingHandlePaneOnPaint.md`
- `by-memory/0x00482300-0x0048230a.ChattingHandlePaneRefreshForwarder.md`
- `by-memory/0x00482400-0x004824e0.GetChatButtonAtPoint.md`
- `by-memory/0x004824e0-0x00482b01.ChattingColorPaneConstructor.md`
- `by-memory/0x00482b30-0x00482c32.ChattingColorPaneOnButtonResponse.md`
- `by-memory/0x00482ca0-0x00482d3c.ChattingColorSelectPaneConstructor.md`
- `by-memory/0x00482d60-0x00482f4f.ChattingColorSelectPaneDrawItem.md`
- `by-memory/0x00482f50-0x00482fa5.ChattingColorSelectPaneOnSelectionChanged.md`
- `by-memory/0x00482fb0-0x00483206.ChattingColorListPaneConstructor.md`
- `by-memory/0x00483210-0x0048325b.ChattingColorListPaneSelectCurrentColor.md`
- `by-memory/0x00483270-0x004832b9.ChattingColorListPaneFindIndexByColorValue.md`
- `by-memory/0x004832c0-0x00483414.ChattingColorListPaneDrawItem.md`
- `by-memory/0x00483420-0x00483487.ChattingColorListPaneOnItemSelected.md`
- `by-memory/0x00615284-0x00615460.ChattingStringResourceData.md`
- `by-memory/0x00615460-0x00615560.ChattingColorTableConstants.md`
- `by-memory/0x005afa10-0x005afc8d.SelectObjectWithKeyboardPaneOnMouseEvent.md`
- `by-memory/0x005b0290-0x005b050d.TargetObjectWithKeyboardPaneMouseEvent.md`
- `by-global/g_pChattingHandlePane.md`
- `by-memory/0x0067ade0-0x0067ade4.g_pChattingHandlePane.md`
- `by-memory/-coverage-report.md`
- `auto-generated/-ag-memory-coverage.md`
- `project-level/-auto-completion-stats.md`

IDA MCP evidence from read-only `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`:

- `lookup_funcs` confirmed these entries are not modeled functions: `0x00481b60`, `0x00481bc0`, `0x00482310`, `0x00482c40`, `0x00482c60`, `0x00483260`.
- `lookup_funcs` confirmed modeled neighbors: `sub_481AD0`, `sub_481D60`, `GetChatButtonAtPoint` at `0x00482400`, `sub_4824E0`, `sub_482F50`, `sub_483210`, `sub_483270`, `sub_483420`.
- `xrefs_to` found zero entry xrefs to all six raw targets.
- `xrefs_to 0x004823e0` found the local switch-table data xref from `0x00482321`.
- `xrefs_to 0x00483210` found raw helper calls at `0x00482c8c` and `0x00482c98`, plus modeled calls from `0x00482f90` and `0x00482f9b`.
- `xrefs_to 0x004f3dc0` found the `0002G9` internal call at `0x00483266` and modeled color-list uses at `0x00483289` and `0x00483440`.
- `xrefs_to 0x00482400` found two modeled callers in `ChattingHandlePane::OnMouseEvent` at `0x00481dca` and `0x00481ec9`.
- `insn_query` checked exact instruction ranges for all six raw targets.
- `get_bytes` checked padding/range boundaries around `0x00481b5b-0x00481c05`, `0x0048230a-0x00482400`, `0x00482c32-0x00482c9f`, and `0x0048325b-0x004832b9`.
- `analyze_component` checked `0x004811c0`, `0x00481ad0`, `0x00481d60`, `0x00482150`, `0x00482400`, `0x004824e0`, `0x00482ca0`, `0x00482d60`, `0x00482f50`, `0x00482fb0`, `0x00483210`, `0x00483270`, `0x004832c0`, and `0x00483420`.
- `decompile` checked `0x00481d60`, `0x00482150`, `0x00482400`, `0x00482f50`, `0x00483210`, `0x00483270`, and `0x00483420`.

Raw PE scan evidence:

- Read-only script parsed `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`.
- Image base: `0x400000`.
- `.text`: VA `0x401000-0x60c600`, file raw `0x400`, size `0x20b600`.
- `.rdata`: VA `0x60d000-0x66c200`.
- `.data`: VA `0x66d000-0x69ce24`.
- `.rsrc`: VA `0x69d000-0x6b2e00`.
- For `0x00481b60`, `0x00481bc0`, `0x00482310`, `0x00482c40`, `0x00482c60`, and `0x00483260`, the scan found zero absolute VA pointer hits, zero RVA pointer hits, and zero direct `E8/E9` rel32 branch hits.

## Heuristic / Inference Reanalysis And Validation

### 0002FP and 0002FQ ownership/type

The current `ChattingVarietySelectPane*State*Helper` names are not supported by field evidence. These helpers are physically near the variety-select range, but their field accesses match `ChattingHandlePane`, not `ChattingVarietySelectPane`.

The compare helper at `0x00481b60` compares a caller-provided record against `ecx+0x111`, `ecx+0x114`, `ecx+0x118`, `ecx+0x11c`, `ecx+0x120`, and `ecx+0x124`. The snapshot helper at `0x00481bc0` writes those same fields into the record. `ChattingHandlePane::OnMouseEvent` and `ChattingHandlePane::OnPaint` document these active fields and inline equivalent compare/copy behavior. The snapshot mirror in the live methods is `this+0xf8`, `+0xf9`, `+0xfc`, `+0x100`, `+0x104`, `+0x108`, and `+0x10c`.

Best current record type: `ChattingHandlePaneRenderStateSnapshot`.

Best current fields:

- `+0x00`: `valid`, one byte.
- `+0x01`: `leftToggle` or `leftOption`, one byte, active source `this+0x111`, persisted from config offset `+2678401` and toggled by button index 0.
- `+0x04`: `modeIndex` or `chatDisplayMode`, dword, active source `this+0x114`, cycled modulo 3 by button index 2 and persisted at config offset `+2678396`.
- `+0x08`: `secondaryChatEnabled`, one byte, active source `this+0x118`, persisted at config offset `+2678400` and tied to `sub_55C3A0/sub_55C3C0` on `*(dword_67ADCC + 252)`.
- `+0x0c`: `leftButtonPaintState`, dword, active source `this+0x11c`.
- `+0x10`: `middleButtonPaintState`, dword, active source `this+0x120`.
- `+0x14`: `rightButtonPaintState`, dword, active source `this+0x124`.

The helpers are source-authored retained helper bodies, not compiler helper artifacts. The bodies perform semantic record compare/copy work and return with `ret 4`; they are not thunks, destructors, RTTI glue, or ABI adapters. However, IDA entry xrefs and raw PE VA/RVA/rel32 scans found no inbound route, and the reachable mouse/paint code inlines equivalent logic. Best liveness conclusion: retained no-route helpers from `ChattingHandlePane` source, likely unused after source-level inline/refactor or object-level retention. They should remain reconstructable because the bytes are present and source-shaped, but final C++ should stay blank until the original helper signature/name is source-grade.

### 0002FW rectangle helper

`0x00482310` is not a compiler artifact. It is a source-shaped output-rectangle helper with `ret 8`, a local switch table at `0x004823e0`, and calls to `sub_4B7C50(outRect, left, top, right, bottom)`.

The rectangle constants exactly match adjacent [UID:000107] `GetChatButtonAtPoint` and `ChattingHandlePane` mouse/paint behavior:

- index 0: `(0,4,19,21)`
- index 1: `(21,0,624,24)`
- index 2: `(630,4,649,21)`
- index 3: `(649,4,668,21)`
- default: `(-1,-1,-1,-1)`

IDA entry xrefs and raw PE VA/RVA/rel32 scans found no inbound route to `0x00482310`. The best name is `GetChatButtonRectRaw` or, if the supervisor wants a name that reflects the out-parameter, `SetChatButtonRectByIndexRaw`. Because the helper is a free/file-local companion to `GetChatButtonAtPoint`, `CANONICAL_OWNER:0000I5` and `EMITTER_UIDS:0000I5` remain the safest route. The helper is reconstructable but final C++ should stay blank until the source signature and call route are no longer inferred.

### 0002G0 and 0002G1 color-pane ownership/source route

The current docs route `0002G0` and `0002G1` through `Chatting` because `ChattingColorPane` was previously below gate. That reason is stale. `by-class/ChattingColorPane.md` is now `85/88`, so these two helpers should route directly through [UID:00001T] `ChattingColorPane`.

`0x00482c40` reads owner child pointer `this+0x26c`, null-checks it, passes `child+0x44`, and calls the child's vtable slot `+0x20`. Best role: refresh/invalidate the color category selector child. Best helper name: `ChattingColorPaneRefreshCategorySelectorRaw`.

`0x00482c60` reads the selector child at owner `+0x26c`, reads its selected value at selector `+0x134`, writes the owner selected-category cache at `+0x2a8`, then refreshes both color-list panes at `+0x270` and `+0x274` through [UID:0002G8] `ChattingColorListPaneSelectCurrentColor`. This mirrors the post-base-handler body of `ChattingColorSelectPane::OnSelectionChanged` at `0x00482f50`.

Best current `ChattingColorPane` field names:

- `+0x26c`: `m_categorySelector`
- `+0x270`: `m_primaryColorList`
- `+0x274`: `m_secondaryColorList`
- `+0x278`: `m_primaryColorByCategory`
- `+0x290`: `m_secondaryColorByCategory`
- `+0x2a8`: `m_selectedCategory` or `m_currentColorCategory`

The primary/secondary naming is inferred from list constructor mode and `0x00483210`: when list mode byte `+0x150` is true, the current color comes from owner table `+0x278`; when false, it comes from `+0x290`. `0x00483420` writes back to the same two tables.

IDA entry xrefs and raw PE VA/RVA/rel32 scans found no inbound route to either helper entry. They are source-authored retained no-route owner helpers, not compiler-generated thunks. They should remain reconstructable but not final-C++-ready yet.

### 0002G9 selected color item/value type

`0x00483260` pushes the selected row field at `this+0x134`, calls the shared list item accessor `sub_4F3DC0`, returns `*(item+4)`, and returns. It is a tiny source-shaped accessor for the current selected swatch value.

Best current item record type: `ChattingColorSwatchItem` or `ChattingColorListItem`.

Best current value field: `ChattingColorSwatchItem::colorValue` at item offset `+0x04`.

This field role is validated by [UID:0002GA] `ChattingColorListPaneFindIndexByColorValue`, which compares item `+0x04` to a requested color value, and by [UID:0002GC] `ChattingColorListPaneOnItemSelected`, which writes item `+0x04` into the owner color table for the active category. The field at item `+0x00` remains unresolved and should not be overnamed.

IDA entry xrefs and raw PE VA/RVA/rel32 scans found no inbound route to `0x00483260`. The likely reason is an unused retained accessor, with reachable code using equivalent inlined accessor logic. It should remain reconstructable under `ChattingColorListPane`, but final C++ should stay blank until source exposure/name is source-grade.

### Split/merge/range and source placement

The raw ranges are valid and should remain separate targets. Padding evidence confirms the intended starts/ends:

- `0002FP` begins after five `0xcc` bytes following `0x00481b5b`; `0002FQ` follows after seven `0xcc` bytes.
- `0002FW` begins after six `0xcc` bytes following `0x0048230a`; its local jump table is internal at `0x004823e0`, and `0x00482400` starts the adjacent modeled hit-test function.
- `0002G0` and `0002G1` are separated by padding after `0x00482c32` and by twelve `0xcc` bytes between helper bodies.
- `0002G9` starts after five `0xcc` bytes following `0x0048325b` and ends before `0x00483270`.

No merge is recommended. No split is recommended. `social/Chatting.cpp` remains the current stable source output route for all six. A future `social/ChatColorDialog.cpp` split remains plausible for color-pane classes, but there is not enough evidence to move these targets to that file now.

## Per-Target Recommendations

### [UID:0002FP] `0x00481b60-0x00481bb9`

Recommended score: `86/90`.

Owner/emitter: change from `00001Z` to `00001V`.

Reconstructable: `TRUE`.

Final C++ decision: leave blank. The behavior and owner are now strong enough to clear `85/85`, but there is still no inbound xref/PE route and the helper name/signature are inferred.

Recommended name/path: rename from `ChattingVarietySelectPaneStateCompareHelper` to `ChattingHandlePaneRenderStateCompareHelperRaw`.

Exact doc text to add/change:

```markdown
## B002 2026-06-16 Source-Quality Reanalysis

B002 recommends renaming this page from `ChattingVarietySelectPaneStateCompareHelper` to `ChattingHandlePaneRenderStateCompareHelperRaw` and changing owner/emitter to [UID:00001V][ChattingHandlePane](by-class/ChattingHandlePane.md). Fresh IDA MCP and raw PE checks show this entry remains unmodeled and unreferenced (`xrefs_to 0x00481b60` is empty; raw VA/RVA/rel32 scans found no inbound pointer or branch), but the compared fields are not selector-popup fields. They exactly match [UID:0002FT] and [UID:0002FU] ChattingHandlePane live/rendered state: active fields at `+0x111/+0x114/+0x118/+0x11c/+0x120/+0x124` compared against a 0x18-byte snapshot record with `valid`, `leftToggle`, `modeIndex`, `secondaryChatEnabled`, and three button paint-state dwords.

The best current liveness classification is source-authored retained no-route helper body, not compiler/ABI glue and not a reachable adapter. It is likely an unused/private helper retained from `ChattingHandlePane` source while the reachable mouse/paint methods inline equivalent compare/snapshot logic. Keep `RECONSTRUCTABLE:TRUE` because the body is NexusTK source-shaped code present in `.text`, but keep final C++ blank until the original helper exposure/signature is source-grade.
```

Exact metadata edits:

```markdown
COMPLETION:86
CONFIDENCE:90
CANONICAL_OWNER:00001V
EMITTER_UIDS:00001V
```

Exact coverage row replacement text:

```markdown
        - [UID:0002FP][0x00481b60-0x00481bb9.ChattingHandlePaneRenderStateCompareHelperRaw](by-memory/0x00481b60-0x00481bb9.ChattingHandlePaneRenderStateCompareHelperRaw.md) 0x00481b60-0x00481bb9 | raw retained handle-state helper | ChattingHandlePaneRenderStateCompareHelperRaw : reconstructable : 86% : strong : B002 live IDA/raw PE reanalysis verifies exact compare-helper bytes, zero xrefs/VA/RVA/rel32 inbound hits, no modeled function, and a 0x18-byte render-state snapshot record matching ChattingHandlePane active fields `+0x111/+0x114/+0x118/+0x11c/+0x120/+0x124`; source-authored no-route helper, not selector-owned or compiler glue.
```

### [UID:0002FQ] `0x00481bc0-0x00481c05`

Recommended score: `86/90`.

Owner/emitter: change from `00001Z` to `00001V`.

Reconstructable: `TRUE`.

Final C++ decision: leave blank. The behavior and owner are now strong enough to clear `85/85`, but there is still no inbound xref/PE route and the helper name/signature are inferred.

Recommended name/path: rename from `ChattingVarietySelectPaneStateSnapshotHelper` to `ChattingHandlePaneRenderStateSnapshotHelperRaw`.

Exact doc text to add/change:

```markdown
## B002 2026-06-16 Source-Quality Reanalysis

B002 recommends renaming this page from `ChattingVarietySelectPaneStateSnapshotHelper` to `ChattingHandlePaneRenderStateSnapshotHelperRaw` and changing owner/emitter to [UID:00001V][ChattingHandlePane](by-class/ChattingHandlePane.md). Fresh IDA MCP and raw PE checks show this entry remains unmodeled and unreferenced (`xrefs_to 0x00481bc0` is empty; raw VA/RVA/rel32 scans found no inbound pointer or branch), but the copied fields are not selector-popup fields. They exactly match [UID:0002FT] and [UID:0002FU] ChattingHandlePane live/rendered state: active fields at `+0x111/+0x114/+0x118/+0x11c/+0x120/+0x124` copied into a 0x18-byte snapshot record with `valid`, `leftToggle`, `modeIndex`, `secondaryChatEnabled`, and three button paint-state dwords.

The best current liveness classification is source-authored retained no-route helper body, not compiler/ABI glue and not a reachable adapter. It is likely an unused/private helper retained from `ChattingHandlePane` source while the reachable mouse/paint methods inline equivalent compare/snapshot logic. Keep `RECONSTRUCTABLE:TRUE` because the body is NexusTK source-shaped code present in `.text`, but keep final C++ blank until the original helper exposure/signature is source-grade.
```

Exact metadata edits:

```markdown
COMPLETION:86
CONFIDENCE:90
CANONICAL_OWNER:00001V
EMITTER_UIDS:00001V
```

Exact coverage row replacement text:

```markdown
        - [UID:0002FQ][0x00481bc0-0x00481c05.ChattingHandlePaneRenderStateSnapshotHelperRaw](by-memory/0x00481bc0-0x00481c05.ChattingHandlePaneRenderStateSnapshotHelperRaw.md) 0x00481bc0-0x00481c05 | raw retained handle-state helper | ChattingHandlePaneRenderStateSnapshotHelperRaw : reconstructable : 86% : strong : B002 live IDA/raw PE reanalysis verifies exact snapshot-helper bytes, zero xrefs/VA/RVA/rel32 inbound hits, no modeled function, and copies ChattingHandlePane active fields into the same 0x18-byte render-state snapshot record used by OnMouseEvent/OnPaint; source-authored no-route helper, not selector-owned or compiler glue.
```

### [UID:0002FW] `0x00482310-0x00482400`

Recommended score: `86/90`.

Owner/emitter: keep `0000I5`.

Reconstructable: `TRUE`.

Final C++ decision: leave blank. It is source-shaped and source-placeable, but there is no inbound xref/PE route and the source signature is inferred from the out-rect calling convention.

Recommended name/path: rename from `ChatButtonRectHelperRaw` to `GetChatButtonRectRaw` if the supervisor wants the name aligned with adjacent `GetChatButtonAtPoint`. If the file is not renamed, keep the existing path and apply the same body/metadata conclusion.

Exact doc text to add/change:

```markdown
## B002 2026-06-16 Source-Quality Reanalysis

B002 recommends treating this as a retained file-local `GetChatButtonRectRaw` helper in [UID:0000I5][Chatting](by-file/Chatting.md). Fresh IDA MCP and raw PE checks show this entry remains unmodeled and unreferenced (`xrefs_to 0x00482310` is empty; raw VA/RVA/rel32 scans found no inbound pointer or branch), but the local switch table at `0x004823e0` is referenced from the helper body and the rectangle constants exactly match [UID:000107] `GetChatButtonAtPoint` and [UID:0002FT] `ChattingHandlePane::OnMouseEvent`.

The best current liveness classification is source-authored retained no-route helper body, not compiler/ABI glue. It writes one of the known chat-button rectangles to a caller-provided output rect and returns with `ret 8`. Keep `RECONSTRUCTABLE:TRUE`, keep owner/emitter on `Chatting` because the helper is file-local rather than a class virtual/member, and keep final C++ blank until an inbound source call/signature is recovered.
```

Exact metadata edits:

```markdown
COMPLETION:86
CONFIDENCE:90
CANONICAL_OWNER:0000I5
EMITTER_UIDS:0000I5
```

Exact coverage row replacement text:

```markdown
        - [UID:0002FW][0x00482310-0x00482400.GetChatButtonRectRaw](by-memory/0x00482310-0x00482400.GetChatButtonRectRaw.md) 0x00482310-0x00482400 | raw retained chat-button rectangle helper | GetChatButtonRectRaw : reconstructable : 86% : strong : B002 live IDA/raw PE reanalysis verifies the unmodeled output-rectangle helper, local five-entry switch table, zero entry xrefs/VA/RVA/rel32 inbound hits, `ret 8`, and exact rectangle constants matching adjacent [UID:000107] GetChatButtonAtPoint and ChattingHandlePane mouse/paint behavior; source-authored file-local no-route helper.
```

### [UID:0002G0] `0x00482c40-0x00482c54`

Recommended score: `86/90`.

Owner/emitter: change from `0000I5` to `00001T`.

Reconstructable: `TRUE`.

Final C++ decision: leave blank. The owner/source route is now strong, but there is still no inbound xref/PE route and the original helper exposure is inferred.

Recommended name/path: rename from `ChattingColorPaneRefreshColorSelectHelperRaw` to `ChattingColorPaneRefreshCategorySelectorRaw`.

Exact doc text to add/change:

```markdown
## B002 2026-06-16 Source-Quality Reanalysis

B002 recommends renaming this helper to `ChattingColorPaneRefreshCategorySelectorRaw` and changing owner/emitter to [UID:00001T][ChattingColorPane](by-class/ChattingColorPane.md). The current note that this must route through `Chatting` because the color-pane class is below gate is stale; [UID:00001T] is now `85/88`.

Fresh IDA MCP and raw PE checks show this entry remains unmodeled and unreferenced (`xrefs_to 0x00482c40` is empty; raw VA/RVA/rel32 scans found no inbound pointer or branch). The body reads the selector child pointer at owner `+0x26c`, null-checks it, passes `child+0x44`, and calls the child vtable slot `+0x20`. The best current role is refreshing/invalidating the color category selector child. Keep `RECONSTRUCTABLE:TRUE`, but keep final C++ blank until an inbound source call/signature is recovered.
```

Exact metadata edits:

```markdown
COMPLETION:86
CONFIDENCE:90
CANONICAL_OWNER:00001T
EMITTER_UIDS:00001T
```

Exact coverage row replacement text:

```markdown
        - [UID:0002G0][0x00482c40-0x00482c54.ChattingColorPaneRefreshCategorySelectorRaw](by-memory/0x00482c40-0x00482c54.ChattingColorPaneRefreshCategorySelectorRaw.md) 0x00482c40-0x00482c54 | raw retained color-pane selector refresh helper | ChattingColorPaneRefreshCategorySelectorRaw : reconstructable : 86% : strong : B002 live IDA/raw PE reanalysis verifies exact raw helper bytes, zero entry xrefs/VA/RVA/rel32 inbound hits, selector child pointer at owner `+0x26c`, child bounds argument `+0x44`, vtable refresh/invalidate slot `+0x20`, and now-valid direct ChattingColorPane owner route after [UID:00001T] reached 85/88.
```

### [UID:0002G1] `0x00482c60-0x00482c9f`

Recommended score: `86/90`.

Owner/emitter: change from `0000I5` to `00001T`.

Reconstructable: `TRUE`.

Final C++ decision: leave blank. The owner/source route is now strong, but there is still no inbound xref/PE route and the original helper exposure is inferred.

Recommended name/path: rename from `ChattingColorPaneSyncColorListSelectionHelperRaw` to `ChattingColorPaneSyncColorListsToCategoryRaw`.

Exact doc text to add/change:

```markdown
## B002 2026-06-16 Source-Quality Reanalysis

B002 recommends renaming this helper to `ChattingColorPaneSyncColorListsToCategoryRaw` and changing owner/emitter to [UID:00001T][ChattingColorPane](by-class/ChattingColorPane.md). The current note that this must route through `Chatting` because the color-pane class is below gate is stale; [UID:00001T] is now `85/88`.

Fresh IDA MCP and raw PE checks show this entry remains unmodeled and unreferenced (`xrefs_to 0x00482c60` is empty; raw VA/RVA/rel32 scans found no inbound pointer or branch). The body reads `m_categorySelector` at owner `+0x26c`, copies the selector selected value at `+0x134` into owner `m_selectedCategory` at `+0x2a8`, then refreshes `m_primaryColorList` and `m_secondaryColorList` at `+0x270/+0x274` through [UID:0002G8] `ChattingColorListPaneSelectCurrentColor`. This is the same owner-side sync behavior reached from [UID:0002G6] `ChattingColorSelectPane::OnSelectionChanged`. Keep `RECONSTRUCTABLE:TRUE`, but keep final C++ blank until an inbound source call/signature is recovered.
```

Exact metadata edits:

```markdown
COMPLETION:86
CONFIDENCE:90
CANONICAL_OWNER:00001T
EMITTER_UIDS:00001T
```

Exact coverage row replacement text:

```markdown
        - [UID:0002G1][0x00482c60-0x00482c9f.ChattingColorPaneSyncColorListsToCategoryRaw](by-memory/0x00482c60-0x00482c9f.ChattingColorPaneSyncColorListsToCategoryRaw.md) 0x00482c60-0x00482c9f | raw retained color-pane list sync helper | ChattingColorPaneSyncColorListsToCategoryRaw : reconstructable : 86% : strong : B002 live IDA/raw PE reanalysis verifies exact raw helper bytes, zero entry xrefs/VA/RVA/rel32 inbound hits, selector `+0x26c` selected value `+0x134`, owner selected-category cache `+0x2a8`, primary/secondary list pointers `+0x270/+0x274`, two transfers to [UID:0002G8] select-current helper, and direct ChattingColorPane owner route.
```

### [UID:0002G9] `0x00483260-0x0048326f`

Recommended score: `86/90`.

Owner/emitter: keep `00001S`.

Reconstructable: `TRUE`.

Final C++ decision: leave blank. The helper is semantically clear, but there is no inbound xref/PE route and the source helper name/type exposure are inferred.

Recommended name/path: keep `ChattingColorListPaneGetSelectedColorValueRaw`.

Exact doc text to add/change:

```markdown
## B002 2026-06-16 Source-Quality Reanalysis

B002 recommends keeping this helper under [UID:00001S][ChattingColorListPane](by-class/ChattingColorListPane.md) as `ChattingColorListPaneGetSelectedColorValueRaw`. Fresh IDA MCP and raw PE checks show this entry remains unmodeled and unreferenced (`xrefs_to 0x00483260` is empty; raw VA/RVA/rel32 scans found no inbound pointer or branch), but the body is source-shaped: it passes the selected row index at `this+0x134` to the shared list item accessor `0x004f3dc0`, then returns the selected item's value at offset `+0x04`.

Best current item type is `ChattingColorSwatchItem` or `ChattingColorListItem`; best current field name is `colorValue` at item `+0x04`. This is validated by [UID:0002GA], which compares item `+0x04` against a requested color, and [UID:0002GC], which writes item `+0x04` into the active owner color table. The likely reason for no direct entry xref is a retained unused accessor with equivalent logic inlined in reachable methods. Keep `RECONSTRUCTABLE:TRUE`, but keep final C++ blank until an inbound source call/signature is recovered.
```

Exact metadata edits:

```markdown
COMPLETION:86
CONFIDENCE:90
CANONICAL_OWNER:00001S
EMITTER_UIDS:00001S
```

Exact coverage row replacement text:

```markdown
        - [UID:0002G9][0x00483260-0x0048326f.ChattingColorListPaneGetSelectedColorValueRaw](by-memory/0x00483260-0x0048326f.ChattingColorListPaneGetSelectedColorValueRaw.md) 0x00483260-0x0048326f | raw retained selected swatch value helper | ChattingColorListPaneGetSelectedColorValueRaw : reconstructable : 86% : strong : B002 live IDA/raw PE reanalysis verifies the selected-index item accessor, zero entry xrefs/VA/RVA/rel32 inbound hits, selected-row field `+0x134`, shared list item accessor `0x004f3dc0`, and return of inferred `ChattingColorSwatchItem::colorValue` at item offset `+0x04`; source-authored no-route helper under ChattingColorListPane.
```

## Supporting Class/File Doc Edits Recommended

For `by-class/ChattingVarietySelectPane.md`, remove or revise the two method rows that currently claim [UID:0002FP] and [UID:0002FQ] as variety-select state helpers. Exact replacement note:

```markdown
B002 2026-06-16 reanalysis moved the former `ChattingVarietySelectPaneStateCompareHelper` and `ChattingVarietySelectPaneStateSnapshotHelper` pages to `ChattingHandlePane`: their `this+0x111/+0x114/+0x118/+0x11c/+0x120/+0x124` active fields and 0x18-byte snapshot record match handle-pane render state, not variety-select popup state. Variety-select evidence remains with [UID:000106] and [UID:0002FJ].
```

For `by-class/ChattingHandlePane.md`, add these method rows:

```markdown
| render-state compare helper | [UID:0002FP][0x00481b60-0x00481bb9.ChattingHandlePaneRenderStateCompareHelperRaw](by-memory/0x00481b60-0x00481bb9.ChattingHandlePaneRenderStateCompareHelperRaw.md) | Raw no-route retained helper that compares a 0x18-byte render-state snapshot record against active handle fields `+0x111/+0x114/+0x118/+0x11c/+0x120/+0x124`; current mouse handler inlines equivalent compare logic. |
| render-state snapshot helper | [UID:0002FQ][0x00481bc0-0x00481c05.ChattingHandlePaneRenderStateSnapshotHelperRaw](by-memory/0x00481bc0-0x00481c05.ChattingHandlePaneRenderStateSnapshotHelperRaw.md) | Raw no-route retained helper that writes the active handle fields into the same 0x18-byte snapshot record; current paint handler inlines equivalent copy into `this+0xf8..+0x10c`. |
```

For `by-class/ChattingColorPane.md`, add this field/source-quality note:

```markdown
B002 2026-06-16 raw-helper reanalysis confirms direct ownership for [UID:0002G0] and [UID:0002G1] now that this class is `85/88`. Use `+0x26c` as the category selector child, `+0x270/+0x274` as primary/secondary color-list children, `+0x278/+0x290` as the two six-entry color tables, and `+0x2a8` as the selected/current category cache. The raw helpers remain no-route retained source-shaped helpers, so they are reconstructable but not final-C++-ready.
```

For `by-file/Chatting.md`, no source file route change is recommended now. Exact note if supervisor wants one:

```markdown
B002 2026-06-16 reanalysis keeps the raw chat UI helpers in `social/Chatting.cpp`. A future `social/ChatColorDialog.cpp` split remains plausible for color-pane classes, but current evidence supports only class-owner cleanup for [UID:0002G0]/[UID:0002G1], not a file move.
```

## IDA/Source Changes Recommended

No IDA DB edits are recommended from this B-agent report. Safety rationale: all six entries are currently not modeled IDA functions, all six have zero entry xrefs, and raw PE scans found zero inbound absolute VA/RVA/rel32 references. The safe action is documentation and coverage cleanup first. If a future supervisor pass chooses to create IDA functions/labels, use these names:

- `ChattingHandlePaneRenderStateCompareHelperRaw` at `0x00481b60`
- `ChattingHandlePaneRenderStateSnapshotHelperRaw` at `0x00481bc0`
- `GetChatButtonRectRaw` at `0x00482310`
- `ChattingColorPaneRefreshCategorySelectorRaw` at `0x00482c40`
- `ChattingColorPaneSyncColorListsToCategoryRaw` at `0x00482c60`
- `ChattingColorListPaneGetSelectedColorValueRaw` at `0x00483260`

No source code edits are recommended. These targets should not emit final C++ yet because they remain no-route retained helper bodies with inferred source names/signatures.

## Validator/Report Refresh Commands

After applying the documentation edits and file renames, the supervisor should run:

> Executable block R001 was removed from this report and preserved verbatim in [0002FP-0002G9-chatting-ui-raw-helper-source-quality-removed.md](0002FP-0002G9-chatting-ui-raw-helper-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

If the supervisor defers file renames, substitute the current six by-memory filenames in the file-mode validator commands and keep the same score/owner/source-quality text.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B002","command_id":"000000004165","destination_path":"executed-b-agent-research/B002/0002FP-0002G9-chatting-ui-raw-helper-source-quality.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:25","uid":"0002FP"} -->
<!-- {"agent":"B002","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 0002FP-0002G9-chatting-ui-raw-helper-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B002/0002FP-0002G9-chatting-ui-raw-helper-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"0002FP"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
