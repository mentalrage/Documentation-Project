** TARGET-REPORT-UID:0003N0 **
** AUTHOR-AGENT-ID:B004 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.6 | xHigh **

# UID0003N0 TextEditPaneCoreAfterTextBoxPane Source-Closure Research

## Finalized Report / Current Recommendation

- Implemented disposition: UID0003N0 is now a `92/94` non-emitting split index owned by UID0000EO TextEditPane, retaining exact `[0x00591400,0x005917c9)`, blank emitter, blank position, blank formal C++, and `Nested:8`.
- Four exact source-method children were registered serially in address order: UID0004TC `RefreshTextRange` `[0x00591400,0x005914c4)`, UID0004TD `GetCaretBounds` `[0x005914d0,0x0059151c)`, UID0004TE `DrawTextRange` `[0x00591640,0x005916b5)`, and UID0004TF `DrawCaret` `[0x005916c0,0x0059173e)`. Existing UID0004T1 and UID00030D remain exact unchanged children and UID0004T8 remains the unchanged external successor.
- Callback result: Destinations 1-11 and C3N0-001 through C3N0-046 are applied at report-level detail; all eleven changed ordinary pages passed scoped validation, B004's historical callback waited command `000000015126` passed, generated source satisfies every positive/negative assertion, all temporary UIDs are gone, and no implementation item remains. Fresh external scoped validators `000000015162` through `000000015172` and external waited command `000000015173` subsequently revalidated the same implemented source result.
- Lifecycle boundary: B004 performed no report execution, lifecycle, count, probe, move, or archive command. Report validation, execution, counting, path movement, and archive state remain durable external supervisor/validator-owned facts and are not asserted as pending or complete here.
- Confidence: very strong for ranges, bytes, ABI, control flow, behavior, owner, source file, split, and no-code parent; strong for the descriptive private method spellings. Exact original lexical spellings for three zero-xref helpers and bits `0x08/0x10` are unrecoverable and cap confidence below 95.

## Supporting Research

- Fresh live IDA MCP research used database `9b0396a3`. At evidence time, `idb_list` returned one active NexusTK worker, PID 15732; `server_health` returned `status=ok`, auto-analysis ready, Hex-Rays ready, string cache ready, image base `0x00400000`, and NexusTK.exe as the module.
- Direct search terms were `UID0003N0`, `0003N0`, `0x00591400`, `0x005917c9`, `0x005914d0`, `0x00591640`, `0x005916c0`, `TextEditPaneCoreAfterTextBoxPane`, `TextEditPane`, `RefreshTextRange`, `BuildTextRangeRectangles`, `InvalidateTextRegion`, `GetCaretBounds`, `DrawTextRange`, `DrawCaret`, `raw pocket`, and source-family/owner terms.
- Executed report `executed-b-agent-research/B001/0002ZY-TextEditPaneConstructor-source-quality.md`, SHA256 `4F82A22DDBCF3710F997EE6196A6B5172232773D565060B22DB3FC8181D51ED3`, was opened. It directly establishes `sub_591400` as `TextEditPane::RefreshTextRange`, the declaration and constructor calls, shared table/field names, and the `TextRunMeasureState` source shape.
- Executed report `executed-b-agent-research/B004/00030C-TextEditPaneOnDraw-source-quality.md`, SHA256 `2FA94C3CB8C37036E3E6D2D8EB5CE294516B05A3B7E73B06F1404C08BD9527E0`, was opened. It supplies direct target-family evidence for the two historically broad raw pockets, exact UID0004T1/UID00030D boundaries, current OnDraw behavior, callback state, flags, fields, and the prior explicit decision not to reclassify those pockets without a dedicated pass.
- Executed report `executed-b-agent-research/B005/000478-UserListDialogPaneHandleKeyOrTextEvent-source-quality.md`, SHA256 `5AFC509272899F621192229CF475F07EB0426A5CB60E91DA0A7168BC46D698AE`, was opened. It establishes the finalized UID0004T8 successor, exact seven-byte predecessor padding, current TextEditPane file union, and preservation requirements for UID0003N0.
- Executed reports `executed-b-agent-research/B001/0001JN-TextEditPaneSerialization-source-quality.md` SHA256 `11633D4340C8D62E43112AE3A455D65ECDF30A5B506DF7BF5F423A7E067C281D` and `executed-b-agent-research/B003/0002ZZ-TextEditPaneDestructor-source-quality.md` SHA256 `6CC99704A40C5BFD8F13199E3F175811B53A6282473AFD905BC9194DEA7FFA93` were opened. They preserve the class/file union, exact List/table fields, constructor/destructor/source boundaries, and broad-aggregate no-duplicate-source policy; neither contains direct raw-pocket closure.
- Executed report `executed-b-agent-research/B004/0001JO-TextBoxPane-source-quality.md`, SHA256 `E98CBB28F3D4C44571DC6C40F7C53E3AF015EAA26B713BF0AD076534574A0161`, was opened. It confirms the TextBox/TextEdit barrier, predecessor padding, and TextEditPane ownership of `0x00591400-0x005917c9`, but does not split the raw pockets.
- Executed report `executed-b-agent-research/B003/0003R9-SelfLookPane2ShowSpelledView-source-quality.md`, SHA256 `74DEF84CCDA8CD602B9512AD94CFBA12CB0181204015E8D50BD5E5A9CF2C58E4`, was opened. It confirms the accepted `GetTextAreaBounds`/`SetTextAreaBounds` and caret/text-area consumer contracts; it has no direct report for the target methods.
- At the report-first coordination checkpoint, active B001-B005 research roots were searched. No separate active report for UID0003N0 or any of the four proposed children was found; B004's then-current goal was the only active assignment match, so no callback-owner collision existed.
- `tools/leaser/Agents/Older-Research` and `tools/leaser/Agents/SpecialReports` were searched with the same terms and produced no direct target report. The actual project archive root `archived` exists and contained no matching Markdown report. These are explicit no-direct-report outcomes, not missing-root claims.
- Wave2/Wave3 wording was not used as authority. Any older generated names or broad raw labels were treated as stale leads and revalidated against live bytes, control flow, current docs, and current generated output.

## Target

- Target UID: `0003N0`.
- Target path: `by-memory/0x00591400-0x005917c9.TextEditPaneCoreAfterTextBoxPane.md`.
- Assignment-time target SHA256 was `CDBE5FCE3EFF3BB9E5E3028ACF4A093152501EE6DA759905CAD22B50A30FB665`, 11,422 bytes, 91 lines; the historical tracker state was `85/88`, reconstructable true, with zero direct reports.
- Current target SHA256 is `7E16A2C1531D42F6F3C9C91F4C0285D746A8614D75E82F91876906EE01E44E61`, 16,610 bytes, 115 lines.
- Implemented classification: non-emitting TextEditPane split index, owner UID0000EO, blank emitter/position/formal, reconstructable false, `92/94`, `Nested:8`.
- Historical B004 report-only artifact path: `tools/leaser/Agents/Agent-B004/research/0003N0-TextEditPaneCoreAfterTextBoxPane-source-quality.md`. External report validation, execution, count, path movement, and archive state are supervisor/validator-owned and are not asserted by this artifact.

## Current Target State

- Current metadata is `COMPLETION:92`, `CONFIDENCE:94`, `CANONICAL_OWNER:0000EO`, `RECONSTRUCTABLE:FALSE`, blank `EMITTER_UIDS`, blank position, blank formal C++, and `Nested:8`.
- The page now records the complete exact six-child/five-padding partition with real UIDs 0004TC, 0004TD, 0004T1, 0004TE, 0004TF, and 00030D, plus unchanged external successor UID0004T8. No broad raw pocket, placeholder, or in-scope source-emitter gap remains.
- The exact parent bytes `[0x00591400,0x005917c9)` total 969 bytes and hash to `C7EFA7E5A25A6E9C3B44ADBFEC60E3D6A403C7D97A6B84D40EAB75FAE0BDB5A3`.
- Exact post-callback ordinary state is:

| Path | SHA256 | Bytes / lines | Applied role |
| --- | --- | ---: | --- |
| `by-memory/0x00591400-0x005917c9.TextEditPaneCoreAfterTextBoxPane.md` | `7E16A2C1531D42F6F3C9C91F4C0285D746A8614D75E82F91876906EE01E44E61` | 16,610 / 115 | D1 parent reclassification/inventory |
| `by-memory/0x00591400-0x005914c4.TextEditPaneRefreshTextRange.md` | `12A3A252361B5BBA1A152288A9695B5FB4EFB793579F930504A960FAF25037AD` | 9,353 / 111 | D2 UID0004TC exact child |
| `by-memory/0x005914d0-0x0059151c.TextEditPaneGetCaretBounds.md` | `AAEC6C44EDCD504A5E2C037EDEF02DF368762287482645B1498C8B2DC484712B` | 7,422 / 90 | D3 UID0004TD exact child |
| `by-memory/0x00591640-0x005916b5.TextEditPaneDrawTextRange.md` | `16E003B8DA05EBFF2BF196D4F2A2E11003EFAD2FB21E2669A2CBD750FFDBB1D1` | 8,063 / 99 | D4 UID0004TE exact child |
| `by-memory/0x005916c0-0x0059173e.TextEditPaneDrawCaret.md` | `6E507D8FB54C93F7622B03FB9BC7D02BE66E919991952183294537B2D9D527ED` | 8,096 / 95 | D5 UID0004TF exact child |
| `by-memory/0x00590810-0x005909e3.TextEditPaneOnDraw.md` | `F08C3C8DAC89E8F1DFB7C53AE13402E6C0CEF6BE2AC1799A2DDB285D4A2C8E59` | 15,055 / 149 | D6 source-call-shape rebase |
| `by-class/TextEditPane.md` | `CDF87C541EAD0FAE91AAC91C6E299C8D4F941EDC673C48C1E42FA6F5CBA7A270` | 78,589 / 603 | D7 complete class union |
| `by-file/TextEditPane.md` | `68F44BBA20D5B5042FCD28BB917207291B8C14239B2DF7B3C11C5D655919DDB5` | 92,092 / 447 | D8 source order/route |
| `by-memory/0x0058dce0-0x00591300.TextEditPaneCoreBeforeTextBoxPane.md` | `B0056EE2D394A5839746A73DBEA7338476F4E8F79621FB3900B3563E77BCCDDC` | 36,442 / 196 | D9 helper vocabulary support |
| `by-memory/0x00591300-0x005954b3.TextBoxPaneNoncontiguousAuditMap.md` | `3AA18711A69B90AD832ADF21459BEE0CA24F29D88785A284D26F4BAACEF8CB7F` | 31,052 / 196 | D10 child-union synchronization |
| `by-memory/-ignored.md` | `C4DCDE7FD9C3A3743F88252CA52E63AFF7CDE401EDECE2CAC903EFAE7B5C23AD` | 1,069,723 / 5,228 | D11 five exact padding entries |

- Verify-only pages remain unchanged: UID0004T1 SHA `9AFBFD01CB6F92B08F1E2654CF7BEC7516A5836CF7D8C96A23B5114BE5A4C1F3`, 8,771/123; UID00030D SHA `1592AFFF40BF20F4BF5C265D3DF3181BC8D8671C21377AC828C23B100BA76441`, 7,530/80; UID0004T8 SHA `13C874D265DC21797B16780850CE1E9593F024259B691F7FFC3D4BCCE4521236`, 13,018/160.
- Current generated `auto-generated/NexusTK/ui/controls/TextEditPane.cpp` is external validator command/header `000000015173`, refreshed `2026-07-20T07:06:50-04:00`, SHA256 `0DF602407C885AE1CCE45DBE2D3E2DEA377BDABC9B99050F7DDD457F0A197B77`, 34,687 bytes/975 lines. It contains one qualified definition each for `OnDraw`, `RefreshTextRange`, `GetCaretBounds`, `BuildTextRangeRectangles`, `DrawTextRange`, `DrawCaret`, and `InvalidateTextRegion`. UID0003N0 occurs zero times because the parent is non-emitting. UID0004TC, UID0004TD, UID0004TE, and UID0004TF each occur exactly once as the normal provenance comment for its emitted definition, while each child's `Empty Emitter Marker` occurs zero times. Zero raw helper name, cookie, EH, vtable, manual cleanup, or duplicate source is present. Exactly five Empty Emitter Markers remain, all unrelated pre-existing UID0001JM/UID00030F/UID00030E/UID0001JP/UID0001JS debt. B004 waited command `000000015126` and commands `14932`, `15003`, and `15028` are historical generated checkpoints, not the current external epoch.
- The last read-only tracker snapshot immediately before this report edit was external deferred-refresh command/header `000000015145`, refreshed `2026-07-20T06:34:45-04:00`, SHA256 `A5AD12525934F61FAA3D12E257139DDDCA302B7C2CD06237789A5022846A4FE2`, 1,521,291 bytes/6,171 lines. Its line 3796 records UID0003N0 at `92/94`, reconstructable false. Commands `15027`, `15128`, `15136`, `15140`, and `15143` are historical pre-callback/intermediate epochs. The unrelated external deferred queue was still advancing, so this is explicitly an evidence-time snapshot rather than a durable assertion of the later tracker hash; UID0003N0 row semantics were unchanged across those epochs.
- Supervisor applied and validated the exact coverage handoff externally: by-memory command `000000015174` at `2026-07-20T07:31:00-04:00`, by-class command `000000015175` at `2026-07-20T07:31:11-04:00`, and by-file command `000000015176` at `2026-07-20T07:31:18-04:00`, each exit 0/ok 1. Current read-only baselines are by-memory SHA256 `00628B4984D76EEE97407C84A75897AAD3FABF8F413B5773A7FDED4989A73D49`, 1,832,000 bytes/4,350 lines; by-class SHA256 `37708DD4D953E150B99AB0BFA54D61DC8C3EEB97D76AD77832E37FF86F0B5A78`, 238,962/623; by-file SHA256 `7A7A0E96E61711F4F6F89E80BC01E999F028D1FC1E902D053BC8ABFD5792030E`, 137,429/316; and unchanged by-struct SHA256 `FEB144165B08A72402ED071C1C359C7A9BCE12A93541B84C2721A1D477805AE0`, 57,041/137. UID0003N0, UID0004TC/UID0004TD/UID0004TE/UID0004TF, all five target-padding rows, merged UID0000EO, and merged UID0000ON each occur exactly once; no B004 manual coverage delta remains. B004 did not edit coverage.
- All eleven ordinary edit/validation leases were released immediately. The first report-only reconciliation lease expired during final auditing; its cleanup returned `Rejected[No active lease]`. A later short report lease was acquired only for the generated-marker wording repair and released before that return. This post-coverage report-only reconciliation used no lease, so zero B004 leases remain. B004 did not manually edit generated, tracker, manual coverage, audit, supervisor, validator-state, IDA, lifecycle, or archive files and ran no report lifecycle command.

## Executive Recommendation

- Split first. The existing page is not one C++ body. It contains four new exact source methods, two already exact children, and five compiler-alignment gaps.
- Route every source method through class UID0000EO and file UID0000ON `NexusTK/ui/controls/TextEditPane.cpp`.
- Keep UID0003N0 as the complete address inventory and no-code proof. A parent body would duplicate six children and is therefore invalid.
- Rebase UID00030C OnDraw to the most realistic human source call graph: `DrawTextRange(firstVisibleLine,lastVisibleLine)` and `DrawCaret()`. The compiler inlined those private helpers, which explains the byte-identical logic in OnDraw plus retained zero-xref out-of-line bodies.
- Preserve UID0004T1 and UID00030D exactly. Do not move, merge, duplicate, or rescore them.
- Keep class/file scores `93/94` and `93/93`; this pass closes the target island but unrelated TextEditPane input/navigation/formatting raw debt still caps the broader pages.

## Supervisor Active Recheck

- The historical report-first assignment required target-specific closure of modeled `0x00591400` plus raw pockets beginning `0x005914d0` and `0x00591640`; the accepted callback has now applied that closure.
- Before implementation, exact split repair was required because the historical broad raw-pocket endpoints included padding and two separate methods in the second pocket. The accepted callback has now implemented the exact six-child/five-padding partition with real UIDs and no residual broad pocket.
- Every source-bearing body in the assigned envelope now has an exact range, ABI, behavior, source identity, owner, source file, score, managed C++ destination, and registration plan. No source-bearing child in this range is deferred.

## Inference Research Guidance Check

- `by-structure.md` was applied as an evidence-separation rule: byte ranges, instructions, xrefs, calls, offsets, and padding are IDA facts; source method names and flag labels are ranked inference; existing docs and reports are corroboration, not substitutes for target evidence.
- The old assumptions that each broad raw pocket was a single unresolved body, that zero direct xrefs implied no source, and that UID0003N0 should emit as an aggregate were treated as uncertain and rechecked.
- The strongest source-shape inference is optimization-based and bounded: three small private methods have ordinary prologue/epilogue/source control flow and exact logic duplicated in a live OnDraw body, but no direct xrefs. Retained out-of-line definitions plus inlined calls explain all evidence without inventing unreachable pseudo-source.
- No raw, `sub_`, `func_`, byte-offset field expression, compiler cookie, explicit vtable, or future-investigation name remains in recommended C++.
- Wave2/Wave3 material was not accepted as current authority.

## Heuristic / Inference Reanalysis And Validation

| Issue | Reanalysis | Resolution |
| --- | --- | --- |
| `0x00591400` generated name | Live function analysis, 20 xrefs, constructor report, and current declaration were compared. | Exact source-facing identity remains `void TextEditPane::RefreshTextRange(short start, short end)`. |
| First raw pocket extent | Instruction walk stops at `retn 8` at `0x591519`; four `0xcc` bytes follow. | Exact child is `[0x005914d0,0x0059151c)`, not through `0x0059151f`. |
| First raw pocket role | It maps a signed-short caret index through `GetCaretLocalPoint`, constructs a 16-byte RectBounds, applies the same left-edge rule as OnDraw, and adds line height. | `void TextEditPane::GetCaretBounds(short caretIndex, RectBounds *bounds) const`. |
| Second broad raw pocket count | Instruction walk finds a `retn 8` at `0x5916b2`, eleven CC bytes, another prologue at `0x5916c0`, and `retn` at `0x59173d`. | Two children: DrawTextRange `[0x591640,0x5916b5)` and DrawCaret `[0x5916c0,0x59173e)`. |
| Draw helper role | Clip query, empty-rect rejection, zeroed TextRunDrawState, flag-0x40 inverse boolean, DrawTextRunCallback, and IterateTextRuns exactly duplicate OnDraw's text-run section. | `void TextEditPane::DrawTextRange(short firstLine, short lastLine)`. |
| Caret helper role | Read-only gate, selection-start caret geometry, m_textColor, SetDrawColor, and g_pfnFillRect exactly duplicate OnDraw's caret section. | `void TextEditPane::DrawCaret()`. |
| Zero direct xrefs | Raw-start xref queries found only each body's fall-through first instruction, not inbound calls/data pointers. OnDraw contains byte-equivalent logic. | Retained out-of-line private source methods whose source calls were inlined; not compiler helpers and not no-code fragments. |
| `0x0058f0d0` helper | Binary search uses TextEditLineRecord start/end text indices and returns signed short. Fourteen exact call sites include RefreshTextRange twice. | `short GetLineIndexForTextOffset(short textOffset) const`; `FindLine` is too vague. |
| `0x0058e890` helper | It maps a caret to local coordinates and updates horizontal/vertical scroll positions, returning whether scroll changed. | `bool ScrollCaretIntoView(short caretIndex)`; generic invalidate/layout names are rejected. |
| `0x08`/`0x10` flags | RefreshTextRange tests 0x08 before all work; SetSelectionRange tests combined 0x18 before repaint; 0x10 skips only invalidation/caret scroll after line rebuild/measure. | Exact behavioral labels are suspend-refresh (`0x08`) and suppress-display-update (`0x10`). Formal C++ uses exact literals to avoid falsely claiming original lexical constants. |
| `+0x110` rectangle | ScrollablePane support resolves this inherited RectBounds as `m_contentRect`; slot +0x20 is Pane::InvalidateRect. | Use `InvalidateRect(&m_contentRect)`, not raw `this+0x110` or a target-private rectangle. |
| Text area | Current TextEdit docs resolve `+0x120/+0x124/+0x128` as the positioned text area left/top/right aliases over ScrollablePane's positioned content rectangle. | Preserve accepted `m_textAreaLeft/Top/Right` vocabulary and do not add layout-changing duplicate fields. |
| Measure state initialization | The target stores only availableWidth; TextRunMeasureCallback overwrites remainingWidth/scratch before first use. The constructor's accepted human source uses aggregate initialization. | Use `TextRunMeasureState state = { width, 0, 0 };`; optimizer removal of dead zero stores explains the binary. |
| Parent emitter | Six distinct methods plus padding cannot be one source body. | Parent false/non-emitting, blank formal. |
| OnDraw duplication | Current source-ready OnDraw spells inlined helper bodies directly. Exact retained helpers make helper calls the stronger original source graph. | Rebase only those two bounded sections to calls; preserve every other OnDraw branch and behavior. |
| Scores | All binary/source blockers are resolved, but exact private lexical spellings and zero-xref retention remain inferred; broader class/file still have unrelated debt. | Parent 92/94; Refresh 92/94; three raw children 91/93; class/file scores unchanged. |

- Rejected `GetCursorRect`: project vocabulary and the explicit signed-short caret index favor caret, while the method returns through caller-owned `RectBounds` and is const.
- Rejected `DrawLines`: arguments are line indexes but the shared source vocabulary is text runs; the method's entire body delegates to `IterateTextRuns` and `DrawTextRunCallback`.
- Rejected `PaintCaret`: current class/file use `OnDraw` plus `Draw...` helper vocabulary; `DrawCaret` is the strongest consistent private name.
- Rejected embedded-fragment/no-code disposition: each raw body has a complete independent ABI, prologue, return cleanup, behavior, and alignment-delimited endpoint.
- Rejected compiler-generated disposition: no cookie/EH/vtable/adjustor-only semantics define these bodies; cookies are incidental lowering around ordinary source in two children.
- Rejected direct body duplication in UID0003N0: it would emit six methods twice.

## Evidence Standards Used

- Strongest evidence: live IDA MCP bytes/instruction queries, modeled-function analysis, bounded xrefs, exact ABI returns, call graph, and address-delimited padding.
- Corroborating evidence: current ordinary by-memory/class/file docs, exact existing formal C++, generated `TextEditPane.cpp`, manual coverage, tracker state, and opened executed reports.
- Inference ladder: exact binary behavior first; current accepted project types/helpers second; same-file duplicate/inlining controls third; lexical naming and source-order inference last.
- Zero xrefs were treated as negative liveness evidence requiring a source-shape explanation, not as automatic no-code proof. Duplicate inlined bodies and normal retained out-of-line method forms supply that explanation.
- Confidence remains below 95 because symbols/source are absent and original private method/flag spellings cannot be proven, not because any behavior or destination is unresolved.

## Evidence Checked

- IDA MCP: fresh `idb_list`, `server_health`, `lookup_funcs`, `analyze_function`, `insn_query`, `search_text`, `xref_query`, bounded `get_bytes`, and exact range hashes against database `9b0396a3`.
- Modeled functions analyzed: `0x00591400`, `0x0058e890`, `0x0058f0d0`, `0x0058ea80`, `0x0058f2a0`, `0x0058fef0`, `0x005905f0`, `0x00591180`, and `0x00591200`.
- Raw ranges decoded instruction by instruction: `[0x005914d0,0x0059151c)`, `[0x00591640,0x005916b5)`, and `[0x005916c0,0x0059173e)`; surrounding CC gaps were independently hashed.
- Xrefs checked at `0x00591400`, `0x005914d0`, `0x00591640`, `0x005916c0`, UID0004T1, UID00030D, callbacks, and helper callees. Pointer/data routes to raw starts were absent.
- Current docs opened: target, UID0004T1, UID00030D, UID00030C, UID0001JM, UID0001JO, UID0000EO, UID0000ON, TextRunMeasureCallback, DrawTextRunCallback, ScrollablePane, Pane, Rect/GrafPort helpers, and `by-memory/-ignored.md`.
- Old-report roots and exact paths/results are enumerated under Supporting Research. Active, executed, Older-Research, SpecialReports, and actual `archived` roots were all checked.
- Current generated `TextEditPane.cpp`, generated tracker row, and manual by-memory/by-class/by-file/by-struct coverage files were read-only inputs.
- Negative checks: no IDA function object at raw starts, no direct raw-start xrefs, no separate source file/owner, no vtable slot route, no string/resource/global ownership pivot, no compiler-only body, no duplicate current exact child, and no active competing B-agent report.
- Intentionally skipped: IDA rename/type/comment mutation, ordinary edits, validator calls, generated refresh, coverage edits, leases, and lifecycle commands are forbidden in Gate 1.

## Claim And Incorporation Ledger

| Claim ID | Claim | Confidence | Evidence | Destination doc/section | Action | Verification state |
| --- | --- | --- | --- | --- | --- | --- |
| C3N0-001 | UID0003N0 exact envelope is `[0x00591400,0x005917c9)`, 969 bytes, SHA256 `C7EFA7...B5A3`. | exact | MCP bytes/hash | D1 Exact Range | incorporate | applied |
| C3N0-002 | Pre-callback target SHA was `CDBE5...B665` with 85/88 true, owner/emitter 0000EO, Nested 8; current D1 SHA is `7E16A2...4E61` with 92/94 false, owner 0000EO, blank emitter, Nested 8. | exact | pre/post file readback | D1 metadata/history | incorporate | applied |
| C3N0-003 | Parent contains six methods and five padding spans and cannot emit one body. | exact | split inventory | D1 no-code proof | incorporate | applied |
| C3N0-004 | `[0x591400,0x5914c4)` is a 196-byte thiscall method, 59 instructions, 9 blocks, complexity 5. | exact | analyze_function | D2 evidence | incorporate | applied |
| C3N0-005 | `0x591400` has 20 exact code xrefs from nine modeled caller families. | exact | xref inventory | D2 liveness | incorporate | applied |
| C3N0-006 | The accepted source identity is `RefreshTextRange(short,short)`. | strong | constructor report/current declaration/body | D2 formal/class/file | incorporate | applied |
| C3N0-007 | Flag 0x08 suppresses all refresh work; flag 0x10 suppresses only display invalidation/caret scrolling after layout. | exact behavior/lexical inferred | target/SetSelectionRange | D2 behavior | incorporate | applied |
| C3N0-008 | `0x58f0d0` is a signed-short text-offset-to-line-index binary search. | strong | decompile/records/callers | D2/D9 support | incorporate | applied |
| C3N0-009 | Refresh calls RebuildLineTable on first/last line references. | exact | target instructions | D2 formal | incorporate | applied |
| C3N0-010 | Nonzero alignment runs TextRunMeasureCallback with width `right-left` and callback-safe zeroed trailing state. | exact/source-shape strong | target/callback/constructor | D2 formal | incorporate | applied |
| C3N0-011 | Refresh invalidates inherited `m_contentRect` through Pane slot +0x20. | exact | call/ScrollablePane/Pane docs | D2 formal | incorporate | applied |
| C3N0-012 | Refresh scrolls the active drag endpoint or ordinary selection end into view through `0x58e890`. | exact | target/helper analysis | D2/D9 | incorporate | applied |
| C3N0-013 | `[0x5914d0,0x59151c)` is a complete 76-byte `retn 8` method, not the old inclusive raw pocket. | exact | insn_query/hash | D3 evidence | incorporate | applied |
| C3N0-014 | First raw child ABI is const thiscall with signed-short caret index and caller-owned RectBounds output. | strong | stack order/read-only body | D3 formal | incorporate | applied |
| C3N0-015 | First raw child constructs exact caret bounds with conditional left decrement, right x+1, and bottom y+lineHeight. | exact | instructions | D3 formal | incorporate | applied |
| C3N0-016 | Best source name is `GetCaretBounds`, with `GetCursorRect` rejected. | strong | project vocabulary/behavior | D3/class/file | incorporate | applied |
| C3N0-017 | First raw child has zero inbound direct/pointer xrefs but matches duplicated OnDraw/DrawCaret geometry. | exact | xrefs/body compare | D3 liveness | incorporate | applied |
| C3N0-018 | `[0x591640,0x5916b5)` is a complete 117-byte `retn 8` method. | exact | insn_query/hash | D4 evidence | incorporate | applied |
| C3N0-019 | Draw child skips iteration only for empty/invalid clip. | exact | branch/callees | D4 formal | incorporate | applied |
| C3N0-020 | Draw child zero-initializes TextRunDrawState and sets applyRunTextColor to inverse flag 0x40. | exact | SSE stores/flag/callback | D4 formal | incorporate | applied |
| C3N0-021 | Best source identity is `DrawTextRange(short firstLine, short lastLine)`. | strong | OnDraw duplicate/callback vocabulary | D4/class/file | incorporate | applied |
| C3N0-022 | DrawTextRange has zero direct start xrefs and is a retained method with inlined OnDraw call. | strong | negative xrefs/duplicate control | D4 liveness | incorporate | applied |
| C3N0-023 | `[0x5916c0,0x59173e)` is a complete 126-byte no-argument method. | exact | insn_query/hash | D5 evidence | incorporate | applied |
| C3N0-024 | Caret child returns under read-only flag 0x04. | exact | instructions/current flag proof | D5 formal | incorporate | applied |
| C3N0-025 | Caret child uses selection start, exact GetCaretBounds geometry, m_textColor, SetDrawColor, and g_pfnFillRect. | exact/source-shape strong | body/OnDraw duplicate | D5 formal | incorporate | applied |
| C3N0-026 | Best source identity is `DrawCaret()`, not PaintCaret or compiler support. | strong | vocabulary/body | D5/class/file | incorporate | applied |
| C3N0-027 | DrawCaret has zero direct start xrefs and is retained with its OnDraw call inlined. | strong | xrefs/duplicate control | D5 liveness | incorporate | applied |
| C3N0-028 | Five internal gaps are exact CC padding with hashes recorded in the split section. | exact | bytes/hash | D1/D11 | incorporate | applied |
| C3N0-029 | UID0004T1 remains exact 92/94 BuildTextRangeRectangles and unchanged. | exact | current doc/formal/hash `9AFBFD...C1F3` | verify-only | incorporate | already-present |
| C3N0-030 | UID00030D remains exact 91/93 InvalidateTextRegion and unchanged. | exact | current doc/formal/hash `1592AF...6441` | verify-only | incorporate | already-present |
| C3N0-031 | UID0004T8 remains the external successor after seven CC bytes and is unchanged. | exact | current doc/B005 report/hash `13C874...1236` | verify-only | incorporate | already-present |
| C3N0-032 | UID00030C should call DrawTextRange and DrawCaret in human source while preserving exact inlined binary behavior. | strong | duplicate source bodies/MSVC optimization | D6 formal | incorporate | applied |
| C3N0-033 | UID0000EO is canonical class owner/emitter for all four new methods. | very strong | class/file/caller/source family | D1-D7 | incorporate | applied |
| C3N0-034 | UID0000ON `NexusTK/ui/controls/TextEditPane.cpp` is sole source placement. | very strong | current route/adjacency | D8 | incorporate | applied |
| C3N0-035 | Parent should be 92/94 false with blank emitter/position/formal and Nested 8. | strong | split/no-code/score audit | D1 | incorporate | applied |
| C3N0-036 | Refresh child should be 92/94; three zero-xref children should each be 91/93; all use Nested 0. | strong | per-child evidence/lexical cap | D2-D5 | incorporate | applied |
| C3N0-037 | Class needs five private declarations, preserving complete current union and closing before children. | exact/source names strong | current class/formals | D7 | incorporate | applied |
| C3N0-038 | Class/file scores remain 93/94 and 93/93 because unrelated raw families remain. | strong | current tracker/docs | D7/D8 | incorporate | applied |
| C3N0-039 | Front aggregate should record GetLineIndexForTextOffset and ScrollCaretIntoView names without claiming exact child splits outside scope. | strong | helper analysis | D9 | incorporate | applied |
| C3N0-040 | Broad UID0001JO audit map must list the four new TextEdit-owned children without ownership change. | exact | range hierarchy | D10 | incorporate | applied |
| C3N0-041 | Historical pre-callback generated command 15028 had one UID0003N0 empty marker and no four new definitions; it is retained only as the implementation baseline. | exact at checkpoint | historical generated readback | report/generated history | incorporate | applied |
| C3N0-042 | Current external generated command 15173 has exactly one definition for each new method and existing UID0004T1/UID00030D/UID00030C; UID0003N0 occurs zero times; UID0004TC/UID0004TD/UID0004TE/UID0004TF each occurs once as a normal provenance comment and has zero `Empty Emitter Marker`; exactly five unrelated Empty Emitter Markers remain. | exact | current external waited generated readback | generated verification | incorporate | applied |
| C3N0-043 | Supervisor command 15174 applied and validated the exact by-memory replacement, four child additions, and five padding additions; UID0003N0, UID0004TC/TD/TE/TF, and every padding range each occur exactly once at current lines 3311-3321. | exact | current SHA `00628B...3D49`; command 15174 exit 0/ok 1; occurrence counts all 1 | supervisor-applied coverage proof | incorporate | applied |
| C3N0-044 | Supervisor commands 15175/15176 applied and validated the literal no-loss UID0000EO/UID0000ON unions at current lines 550/284; each merged row occurs exactly once and preserves every prior concrete fact plus the accepted source-closure detail. Current by-struct still has zero TextEditPane/TextRun rows and requires no delta. | exact | current SHAs `37708D...5A78` / `7A7A0E...030E` / `FEB144...AE0`; commands 15175/15176 exit 0/ok 1; occurrence proof | supervisor-applied coverage proof | incorporate | applied |
| C3N0-045 | Old reports are leads: constructor/OnDraw/B005 directly corroborate; serialization/destructor/TextBox/SelfLook preserve unions only. | exact | opened paths/search | D1-D10 history | incorporate | applied |
| C3N0-046 | Callback registered children serially, replaced placeholders, used one-file leases/scoped validators, completed waited refresh, supplied literal no-loss manual rows, and released all leases; supervisor commands 15174-15176 later applied and validated those rows externally. B004 performed zero coverage or lifecycle actions. | exact workflow | commands 15063-15126, external 15174-15176, current lease/coverage readback | checklist/validator/coverage proof | incorporate | applied |

## Positive Evidence Summary

- Exact method delimiters are unusually strong: each raw body has a conventional prologue, complete return cleanup, and CC padding before the next source method.
- The three raw bodies reproduce cohesive subgraphs already present in OnDraw: caret bounds, run drawing, and caret drawing. This is positive evidence for inlining, not merely adjacency.
- RefreshTextRange is already named and declared by the accepted constructor union and has 20 exact code xrefs.
- All child methods use established TextEditPane fields/types/helpers and remain within one uninterrupted TextEditPane source corridor.
- Existing UID0004T1 and UID00030D prove the current class/file emitter model and source order immediately between/after the new children.

## IDA MCP Facts

- Function `0x00591400`: size 196, prototype `void __thiscall(int,short,short)`, 59 instructions, 9 blocks, complexity 5, 20 code xrefs.
- Raw `0x005914d0`: 33 instructions, `retn 8`, exclusive end `0x0059151c`, zero inbound xrefs.
- Raw `0x00591640`: 40 instructions, `retn 8`, exclusive end `0x005916b5`, zero inbound xrefs.
- Raw `0x005916c0`: 45 instructions, plain `retn`, exclusive end `0x0059173e`, zero inbound xrefs.
- Exact child hashes are `54B8675B93DF48F5682F80C72D05D5850D9CC3273C63A91673D69F9329120472`, `8338FCB9112937812F8C19F5FDC56E579D137C11460332EC0C109AF3C76E488A`, `39E4B769B323AB96D37AEF4DB503C832D26F58495E4DC8A3C51367B172D2A162`, and `7488872051033A555B5D0970608AC7A0C413EB56505A256AEB36937C163E5CD4` in address order.
- UID0004T1 current bytes hash `905BE22D36B4A79C6612E06835CBD24937217B07A4C7920C35F2F1B5492EB38A`; UID00030D current bytes hash `B81D5845E28D31895DE0A006B3F426F22293067873FEEF42B31372ECB5ACB085`.
- Padding hashes are listed under Range / Split / Padding / Reclassification Analysis.
- No target string/resource reference, alternate owner global, vtable entry for the private raw helpers, or external source-file route exists.

## Function / Child Inventory

| Range / Item | UID / Path | Role | Reconstructable | Direct Parent | Score | Status |
| --- | --- | --- | --- | --- | --- | --- |
| `[0x00591400,0x005917c9)` | UID0003N0 current path | non-emitting split index | FALSE | UID0001JO audit map / owner UID0000EO | 92/94 | reclassify |
| `[0x00591400,0x005914c4)` | UID0004TC / `by-memory/0x00591400-0x005914c4.TextEditPaneRefreshTextRange.md` | private method | TRUE | UID0003N0 | 92/94 | registered first |
| `[0x005914c4,0x005914d0)` | UID0000VN ignored entry | padding | FALSE | UID0003N0 | ignored | add exact entry |
| `[0x005914d0,0x0059151c)` | UID0004TD / `by-memory/0x005914d0-0x0059151c.TextEditPaneGetCaretBounds.md` | private const method | TRUE | UID0003N0 | 91/93 | registered second |
| `[0x0059151c,0x00591520)` | UID0000VN ignored entry | padding | FALSE | UID0003N0 | ignored | add exact entry |
| `[0x00591520,0x00591639)` | UID0004T1 | BuildTextRangeRectangles | TRUE | UID0003N0 | 92/94 | preserve unchanged |
| `[0x00591639,0x00591640)` | UID0000VN ignored entry | padding | FALSE | UID0003N0 | ignored | add exact entry |
| `[0x00591640,0x005916b5)` | UID0004TE / `by-memory/0x00591640-0x005916b5.TextEditPaneDrawTextRange.md` | private method | TRUE | UID0003N0 | 91/93 | registered third |
| `[0x005916b5,0x005916c0)` | UID0000VN ignored entry | padding | FALSE | UID0003N0 | ignored | add exact entry |
| `[0x005916c0,0x0059173e)` | UID0004TF / `by-memory/0x005916c0-0x0059173e.TextEditPaneDrawCaret.md` | private method | TRUE | UID0003N0 | 91/93 | registered fourth |
| `[0x0059173e,0x00591740)` | UID0000VN ignored entry | padding | FALSE | UID0003N0 | ignored | add exact entry |
| `[0x00591740,0x005917c9)` | UID00030D | InvalidateTextRegion | TRUE | UID0003N0 | 91/93 | preserve unchanged |
| `[0x005917c9,0x005917d0)` | UID0000VN current entry | padding | FALSE | external boundary | ignored | preserve unchanged |
| `[0x005917d0,0x00591a1c)` | UID0004T8 | PutScrapToClipboard | TRUE | UID0000ON | 91/93 | external sibling unchanged |

Historical pre-registration templates above have been replaced with real validator-issued UIDs 0004TC, 0004TD, 0004TE, and 0004TF in exact address order; no temporary UID remains.

## Direct Xref / Caller Inventory

| Address / Item | Xref / Caller / Callee | Meaning |
| --- | --- | --- |
| `0x00591400` | code xrefs `0x58dfcb, 0x58e079, 0x58e872, 0x58ee41, 0x58fe62, 0x58fee1, 0x58ff2d, 0x58ffc8, 0x590019, 0x590111, 0x59019e, 0x590683, 0x590b3a, 0x590cf6, 0x5911f1, 0x59128d, 0x5912a5, 0x59415a, 0x594188, 0x5941db` | Live shared refresh method. |
| `0x00591400` | callees `0x58f0d0`, `0x592c20`, `0x593500`, callback `0x593c20`, Pane slot +0x20, `0x58e890` | Text-offset mapping, line rebuild/measure, invalidation, caret scroll. |
| `0x005914d0` | zero inbound code/data/pointer xrefs | Retained out-of-line helper; source use inlined. |
| `0x005914d0` | callees `0x58f740`, `0x4baaa0` | Caret local point and line height. |
| `0x00591640` | zero inbound code/data/pointer xrefs | Retained out-of-line helper; OnDraw use inlined. |
| `0x00591640` | callees `0x4b96c0`, `0x4b7eb0`, `0x593500`, callback `0x593db0` | Clip gate and text-run drawing. |
| `0x005916c0` | zero inbound code/data/pointer xrefs | Retained out-of-line helper; OnDraw use inlined. |
| `0x005916c0` | callees `0x58f740`, `0x4baaa0`, `0x4b9660`, callback slot `0x0069b3fc` | Caret geometry/color/fill. |
| UID0004T1 | callers OnDraw `0x590943`, TextBox invalidation `0x5913b9`, UID00030D `0x591789` | Existing exact shared range-rectangle child. |
| UID00030D | zero direct callers | Retained source helper; accepted exact body remains unchanged. |

## Documentation Evidence And IDA Status

- Current UID0003N0 is accurate about owner, source file, existing child boundaries, and external successor but stale/incomplete about raw-pocket split, source identities, score, reconstructable state, and generated disposition.
- Current UID0000EO already declares RefreshTextRange and the exact callback/record/list union. It lacks GetLineIndexForTextOffset, ScrollCaretIntoView, GetCaretBounds, DrawTextRange, and DrawCaret declarations.
- Current UID00030C behavior is exact but currently spells the two inlined private helper bodies directly. The bounded D6 rebase improves human source shape without changing behavior.
- Current UID0000ON routes all relevant code through `NexusTK/ui/controls/TextEditPane.cpp` and should retain its 93/93 score while adding the exact four-child/source-order union.
- Current UID0001JM records `0x58e890` only as a generic scroll helper and does not name `0x58f0d0`; D9 closes those support names without creating out-of-scope child pages.
- Current post-command-15174 by-memory lines 3311-3321 contain the exact non-emitting UID0003N0 row, UID0004TC/UID0004TD/UID0004TE/UID0004TF rows, and all five interleaved target-padding rows exactly once. Post-command-15175/15176 class/file rows 550/284 each contain the exact merged no-loss UID0000EO/UID0000ON union once. Current by-struct contains zero TextEditPane/TextRun rows, so no by-struct delta was or is triggered.
- Historical pre-callback generated command `000000015028` contained a UID0003N0 Empty Emitter Marker because the parent was then true with a blank block. The implemented false parent removes that marker: current external command `000000015173` contains zero UID0003N0 occurrences, while UID0004TC/UID0004TD/UID0004TE/UID0004TF each appears once as a normal provenance comment for its emitted definition and has zero `Empty Emitter Marker`.

## Ranked Ownership Analysis

### 1. TextEditPane / TextEditPane.cpp

- Evidence for: every receiver field is TextEditPane/ScrollablePane state; callees are TextEditPane layout/draw helpers; methods sit between exact TextEditPane children; duplicate logic occurs in TextEditPane::OnDraw; current constructor/class/file already name RefreshTextRange.
- Evidence against: exact private lexical spellings are absent and three bodies have zero direct start xrefs.
- Decision: accepted owner UID0000EO and file UID0000ON. Zero xrefs are explained by inlining and do not outweigh the complete receiver/source-family evidence.

### 2. TextBoxPane

- Evidence for: the historical broad UID0001JO audit map begins at `0x00591300`, immediately before the target.
- Evidence against: TextBoxPane exact override island ends before `0x00591400`; all target fields/helpers and duplicate source are TextEditPane; UID0001JO is explicitly noncontiguous and non-emitting.
- Decision: rejected as source owner. Keep UID0001JO only as the hierarchy/audit-map parent.

### 3. Compiler/support or no-source raw fragments

- Evidence for: no direct xrefs to three raw starts and two bodies include security cookies.
- Evidence against: complete thiscall ABIs, ordinary project control flow, typed project callees, exact duplicate inlined logic, and independent aligned endpoints. Cookies are compiler lowering around source, not body semantics.
- Decision: rejected. Only the CC gaps are compiler padding.

### Proposed new file/grouping, if applicable

- No new source file. Create only four exact by-memory child pages under the existing TextEditPane.cpp route.
- Keep file-local callbacks and all existing children in the current source union.
- Reject a `TextEditPaneDrawing.cpp`, TextBoxPane source file, generic Rect helper file, or compiler-support grouping.

## Source Placement

- Recommended source file: `NexusTK/ui/controls/TextEditPane.cpp`, current by-file owner UID0000ON.
- Recommended class: private methods of UID0000EO `TextEditPane`.
- Source order follows addresses: RefreshTextRange, GetCaretBounds, existing BuildTextRangeRectangles, DrawTextRange, DrawCaret, existing InvalidateTextRegion, then external file-local PutScrapToClipboard.
- OnDraw earlier in the same translation unit calls DrawTextRange and DrawCaret; optimization inlines those calls while retaining out-of-line method definitions.
- Rejected placements: TextBoxPane.cpp, ScrollablePane.cpp, GrafPort.cpp, a separate clipboard file, and compiler runtime.
- Remaining uncertainty is only original lexical spelling, not placement or callable surface.

## Range / Split / Padding / Reclassification Analysis

- Exact full envelope: `[0x00591400,0x005917c9)`, 969 bytes, SHA256 `C7EFA7E5A25A6E9C3B44ADBFEC60E3D6A403C7D97A6B84D40EAB75FAE0BDB5A3`.
- Exact child/padding partition:

| Range | Bytes | SHA256 | Disposition |
| --- | ---: | --- | --- |
| `[0x591400,0x5914c4)` | 196 | `54B8675B93DF48F5682F80C72D05D5850D9CC3273C63A91673D69F9329120472` | new RefreshTextRange child |
| `[0x5914c4,0x5914d0)` | 12 | `A0D08A155AA4E9AADD5DA959565DE99ACC8DC9DBDA96EC3852DDE76C97330902` | CC padding |
| `[0x5914d0,0x59151c)` | 76 | `8338FCB9112937812F8C19F5FDC56E579D137C11460332EC0C109AF3C76E488A` | new GetCaretBounds child |
| `[0x59151c,0x591520)` | 4 | `8843B54D2DF63CA265CF4A05D27DD2B29A74FB476D296DD44A0E171D74B441CA` | CC padding |
| `[0x591520,0x591639)` | 281 | `905BE22D36B4A79C6612E06835CBD24937217B07A4C7920C35F2F1B5492EB38A` | existing UID0004T1 |
| `[0x591639,0x591640)` | 7 | `F145ECA66705DE68FF53C6D80E34D8F9A5B535FFA157194AA98BDB68AEA4368D` | CC padding |
| `[0x591640,0x5916b5)` | 117 | `39E4B769B323AB96D37AEF4DB503C832D26F58495E4DC8A3C51367B172D2A162` | new DrawTextRange child |
| `[0x5916b5,0x5916c0)` | 11 | `3682C0A62515050101266CC639BF81F5D8C5395F49E7DA93FCC22603018E0943` | CC padding |
| `[0x5916c0,0x59173e)` | 126 | `7488872051033A555B5D0970608AC7A0C413EB56505A256AEB36937C163E5CD4` | new DrawCaret child |
| `[0x59173e,0x591740)` | 2 | `E3966E3275BE536A16092EC0CADF1638F718218E616FBBE8FF1C5E67FFF4DEF2` | CC padding |
| `[0x591740,0x5917c9)` | 137 | `B81D5845E28D31895DE0A006B3F426F22293067873FEEF42B31372ECB5ACB085` | existing UID00030D |

- Add all five padding gaps between child pages to UID0000VN. The two-byte `0x59173e-0x591740` interval is exact compiler alignment and receives its own ignored entry; no padding byte remains implicitly owned by the parent and none emits source.
- Parent `Nested:8` remains the raw indentation delta required by the current UID0001JO/UID0002RU/UID0003N0 hierarchy. Every address-sorted new sibling child uses `Nested:0`, so cumulative indentation remains unchanged through the island.
- Parent reclassification to false removes only aggregate emission. It does not change class ownership, address coverage, or child source eligibility.

## Negative Evidence Summary

- No direct code/data/pointer xref reaches any of the three raw starts.
- No alternate class vtable, global receiver, constructor/destructor, string, resource, packet, or file-local callback route claims the raw bodies.
- No body consists solely of vptr writes, flags adjustment, operator delete, EH cleanup, thunk adjustment, or guard support.
- No evidence supports treating the second raw pocket as one `[0x591640,0x591740)` method; a complete return and eleven CC bytes separate two methods.
- No evidence supports one UID0003N0 source body; the exact child ABIs are incompatible with aggregate emission.
- No evidence justifies moving UID0004T1, UID00030D, or UID0004T8 or changing their scores/bodies.
- At the report-first coordination checkpoint, no active B-agent report owned the same target or proposed new child paths; the callback preserved the subsequently current shared TextEditPane union.

## IDA Rename / Type / Comment Recommendations

- In a separately authorized IDA mutation pass only, rename/type:
  - `0x00591400` -> `TextEditPane__RefreshTextRange`, `void __thiscall(TextEditPane *, short, short)`.
  - raw `0x005914d0` -> `TextEditPane__GetCaretBounds`, `void __thiscall(const TextEditPane *, short, RectBounds *)`.
  - raw `0x00591640` -> `TextEditPane__DrawTextRange`, `void __thiscall(TextEditPane *, short, short)`.
  - raw `0x005916c0` -> `TextEditPane__DrawCaret`, `void __thiscall(TextEditPane *)`.
  - `0x0058f0d0` -> `TextEditPane__GetLineIndexForTextOffset`, `short __thiscall(const TextEditPane *, short)`.
  - `0x0058e890` -> `TextEditPane__ScrollCaretIntoView`, `bool __thiscall(TextEditPane *, short)`.
- Add comments distinguishing exact flag behavior from inferred names: `0x08` suppresses all RefreshTextRange work; `0x10` suppresses display invalidation/caret scrolling after line layout.
- IDA DB edits are not requested or performed in this assignment.

## First-Draft C++ Recommendation

Seven complete managed destinations follow. Historical temporary child tokens were replaced with validator-issued UIDs 0004TC, 0004TD, 0004TE, and 0004TF before cross-linking; these blocks are the exact implemented formals.

### Destination 1 - UID0003N0 parent

*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

Exact no-code proof: the envelope contains six independent source methods and five internal padding gaps. Four new children plus UID0004T1 and UID00030D own all source-bearing bytes; UID0000VN owns all five non-source intervals. Parent source would duplicate child definitions and the parent has no declaration/container payload distinct from UID0000EO. Therefore false/blank is required, not a below-threshold fallback.

### Destination 2 - UID0004TC RefreshTextRange

*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
void TextEditPane::RefreshTextRange(short start, short end)
{
    if ((m_editorFlags & 0x08) != 0)
        return;

    short firstLine = GetLineIndexForTextOffset(start);
    short lastLine = GetLineIndexForTextOffset(end);
    RebuildLineTable(&firstLine, &lastLine);

    if (m_textAlignment != 0) {
        TextRunMeasureState state = {
            m_textAreaRight - m_textAreaLeft,
            0,
            0
        };
        IterateTextRuns(firstLine,
                        lastLine,
                        TextRunMeasureCallback,
                        &state);
    }

    if ((m_editorFlags & 0x10) == 0) {
        InvalidateRect(&m_contentRect);
        ScrollCaretIntoView(m_dragSelectionActive
                                ? m_selectionStart
                                : m_selectionEnd);
    }
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

### Destination 3 - UID0004TD GetCaretBounds

*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
void TextEditPane::GetCaretBounds(short caretIndex,
                                  RectBounds *bounds) const
{
    Point caretPoint;
    GetCaretLocalPoint(&caretPoint, caretIndex);

    bounds->left = caretPoint.x;
    if (m_textAreaLeft < caretPoint.x)
        --bounds->left;
    bounds->top = caretPoint.y;
    bounds->right = caretPoint.x + 1;
    bounds->bottom = caretPoint.y + GetLineHeight();
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

### Destination 4 - UID0004TE DrawTextRange

*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
void TextEditPane::DrawTextRange(short firstLine, short lastLine)
{
    RectBounds clipBounds;
    GetClipRect(&clipBounds);
    if (IsRectEmptyOrInvalid(&clipBounds))
        return;

    TextRunDrawState drawState = { 0 };
    drawState.applyRunTextColor =
        (m_editorFlags & kTextEditUseCurrentTextColor) == 0;
    IterateTextRuns(firstLine,
                    lastLine,
                    DrawTextRunCallback,
                    &drawState);
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

### Destination 5 - UID0004TF DrawCaret

*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
void TextEditPane::DrawCaret()
{
    if ((m_editorFlags & kTextEditReadOnly) != 0)
        return;

    RectBounds caretBounds;
    GetCaretBounds(m_selectionStart, &caretBounds);
    SetDrawColor(m_textColor);
    g_pfnFillRect(this, &caretBounds);
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

### Destination 6 - complete UID00030C OnDraw rebase

*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
void TextEditPane::OnDraw()
{
    const unsigned int oldDrawColor = m_drawColor;
    m_drawMode = 0;
    SetDrawColor((m_editorFlags & kTextEditBlackBackground) != 0
                     ? 0
                     : m_textBackColor);
    g_pfnFillRect(this, &m_bounds);
    SetDrawColor(oldDrawColor);

    RectBounds clipBounds;
    GetClipRect(&clipBounds);
    const short lastVisibleLine =
        GetLineIndexForY(clipBounds.bottom - m_textAreaTop - 1);
    const short firstVisibleLine =
        GetLineIndexForY(clipBounds.top - m_textAreaTop);
    DrawTextRange(firstVisibleLine, lastVisibleLine);

    if ((m_editorFlags & kTextEditInteractive) == 0)
        return;

    if (m_selectionStart < m_selectionEnd) {
        List selectionRects(sizeof(RectBounds), 16);
        BuildTextRangeRectangles(m_selectionStart,
                                 m_selectionEnd,
                                 &selectionRects);
        for (int index = 0; index < selectionRects.GetCount(); ++index) {
            CompositePixels(static_cast<const RectBounds *>(
                selectionRects.GetElementAt(index)));
        }
        return;
    }

    DrawCaret();
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

### Destination 7 - complete UID0000EO class union

*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
class Event;
class List;
class TextEditObject;
class TextEditPane;
class TextEditScrap;
struct Point;
struct TextRunMeasureState;
namespace mystr {
template <class CharT> struct mychar_traits;
template <class CharT, class Traits> class StringBase;
}

struct TextEditLineRecord
{
    unsigned short startIndex;
    unsigned short reserved02;
    int top;
    int remainingWidth;
    unsigned short wrapState;
    unsigned short reserved0e;
};

struct TextRunFormatData
{
    unsigned short legacyAssetMode;
    unsigned short reserved02;
    unsigned int textColor;
    TextEditObject *object;
};

struct TextEditFormatRecord
{
    short referenceCount;
    unsigned short reserved02;
    TextRunFormatData format;
};

struct TextEditFormatRun
{
    unsigned short startIndex;
    short formatIndex;
};

struct TextRunMeasureState
{
    int availableWidth;
    int remainingWidth;
    int scratch;
};

struct TextRunDrawState
{
    RectBounds lineRect;
    RectBounds clippedLineRect;
    bool applyRunTextColor;
};

typedef bool (__cdecl *TextRunIteratorCallback)(TextEditLineRecord *line,
                                                const TextRunFormatData *format,
                                                const wchar_t *text,
                                                int textOffset,
                                                unsigned short charCount,
                                                unsigned short segmentFlags,
                                                void *context,
                                                TextEditPane *pane);

static bool __cdecl TextRunMeasureCallback(TextEditLineRecord *line,
                                           const TextRunFormatData *format,
                                           const wchar_t *text,
                                           int textOffset,
                                           unsigned short charCount,
                                           unsigned short segmentFlags,
                                           void *context,
                                           TextEditPane *pane);

static bool __cdecl DrawTextRunCallback(TextEditLineRecord *line,
                                        const TextRunFormatData *format,
                                        const wchar_t *text,
                                        int textOffset,
                                        unsigned short charCount,
                                        unsigned short segmentFlags,
                                        void *context,
                                        TextEditPane *pane);

class TextEditPane : public ScrollablePane
{
public:
    TextEditPane(int viewportWidth,
                 int viewportHeight,
                 int textAreaWidth,
                 int textAreaHeight,
                 int textColor,
                 int textBackColor,
                 bool hasHorizontalScrollbar,
                 bool hasVerticalScrollbar,
                 unsigned int editorFlags,
                 unsigned short legacyAssetMode,
                 bool useDefaultAlignment,
                 bool useThousandsSeparator);
    virtual ~TextEditPane();

    short CopyWideText(wchar_t *outText, short capacity) const;
    mystr::StringBase<wchar_t, mystr::mychar_traits<wchar_t> > GetText() const;
    short GetTextLength() const;
    void GetCaretRange(short *start, short *end) const;
    void GetCaretLocalPoint(Point *point, short caretIndex) const;
    unsigned char *EncodeState(unsigned short *outSize) const;
    void DecodeState(const unsigned char *data, unsigned short size);

    void InsertText(const wchar_t *text, int flags);
    void SetText(const wchar_t *text, short length, short selectStart, short selectEnd);
    void ClearText();
    void SetSelectionRange(short start, short end);
    void SelectAll();
    void ApplySelectionFormat(unsigned char formatMask, const void *formatData);
    void InsertEmbeddedObject(TextEditObject *object, int width, int height);
    void SetMaxLength(short maxLength);
    void SetMaxLines(short maxLines);
    void EnableMaskedText();
    void SetEditActiveState(bool editActive, bool selectAll);
    bool IsEmpty() const;
    void ScrollToTop();
    unsigned char GetMode() const { return m_mode; }

    void PasteFromClipboard(TextEditScrap *scrap);
    short GetLineCount() const;
    void SetViewportBounds(const RectBounds *bounds);
    void GetTextAreaBounds(RectBounds *bounds) const;
    void SetTextAreaBounds(const RectBounds *bounds);
    virtual void OnDraw();

protected:
    virtual int OnKeyEvent(Event *event);
    virtual bool OnMouseEvent(Event *event);

    void InvalidateTextRegion(short start, short end);
    void DeleteSelection();
    void FindWordBoundary(short index, short *wordStart, short *wordEnd) const;
    void AutoScrollSelectionToPoint(int x, int y);

private:
    friend bool __cdecl TextRunMeasureCallback(TextEditLineRecord *line,
                                               const TextRunFormatData *format,
                                               const wchar_t *text,
                                               int textOffset,
                                               unsigned short charCount,
                                               unsigned short segmentFlags,
                                               void *context,
                                               TextEditPane *pane);
    friend bool __cdecl DrawTextRunCallback(TextEditLineRecord *line,
                                            const TextRunFormatData *format,
                                            const wchar_t *text,
                                            int textOffset,
                                            unsigned short charCount,
                                            unsigned short segmentFlags,
                                            void *context,
                                            TextEditPane *pane);

    void ReleaseFormatObjects();
    void RebuildLineTable(short *firstLine, short *lastLine);
    void IterateTextRuns(short firstLine,
                         short lastLine,
                         TextRunIteratorCallback callback,
                         void *context);
    short GetLineIndexForTextOffset(short textOffset) const;
    bool ScrollCaretIntoView(short caretIndex);
    void RefreshTextRange(short start, short end);
    void GetCaretBounds(short caretIndex, RectBounds *bounds) const;
    void DrawTextRange(short firstLine, short lastLine);
    void DrawCaret();
    void ApplyFormatRange(short start,
                          short end,
                          unsigned char formatMask,
                          const TextRunFormatData *format);
    void LoadCurrentFormat();
    void BuildTextRangeRectangles(short start, short end, List *rectangles) const;
    short GetLineIndexForY(int y) const;

    int m_activeLineIndex;
    List *m_textStorage;
    List *m_lineTable;
    List *m_formatTable;
    List *m_formatRuns;
    short m_selectionStart;
    short m_selectionEnd;
    short m_savedSelectionStart;
    short m_savedSelectionEnd;
    TextRunFormatData m_currentFormat;
    bool m_dragSelectionActive;
    bool m_currentFormatValid;
    unsigned int m_editorFlags;
    unsigned char m_mouseMode;
    bool m_dirty;
    bool m_maskedText;
    short m_maxLength;
    short m_maxLines;
    unsigned short m_inputState;
    bool m_useDefaultAlignment;
    bool m_useThousandsSeparator;
};

[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

- These bodies preserve exact original behavior while expressing the strongest human source graph. `GetCaretBounds`, `DrawTextRange`, and `DrawCaret` calls are inferred to have been inlined; their out-of-line bodies remain emitted once.
- Exact binary facts remain separate from lexical inference. The literals `0x08` and `0x10` are deliberate because behavior is exact but original symbolic names are not.
- No C++ exists in this artifact outside the exact managed blocks above.

## Final Recommendation

- D1-D11 are applied exactly. Four child pages were registered serially as UID0004TC/UID0004TD/UID0004TE/UID0004TF, and every temporary UID was replaced throughout report, ordinary links, inventories, and manual handoff text.
- UID0003N0 retains owner UID0000EO and is now false/non-emitting with zero UID occurrence and no emitted body.
- Exactly four new private method definitions emit through UID0000EO; existing UID0004T1/UID00030D/UID0004T8 remain unchanged.
- UID00030C is rebased only from duplicated inlined bodies to `DrawTextRange`/`DrawCaret` calls, preserving its score and every branch/field/helper semantic.
- No source-bearing or investigable work remains within the assigned envelope. Work outside the envelope is not claimed by this report.

## Recommended Target Doc Changes

- Target path: `by-memory/0x00591400-0x005917c9.TextEditPaneCoreAfterTextBoxPane.md`.
- Applied 92/94, owner 0000EO, reconstructable false, blank emitter/position/formal, Nested 8.
- Replaced broad raw-pocket language with the exact 11-row partition, four real child UIDs, five internal ignored entries, existing children, and external successor.
- Applied parent Item Summary: `Non-emitting TextEditPane split index for exact UID0004TC RefreshTextRange, UID0004TD GetCaretBounds, UID0004T1 BuildTextRangeRectangles, UID0004TE DrawTextRange, UID0004TF DrawCaret, and UID00030D InvalidateTextRegion children; five internal CC padding spans are non-source, all methods route through UID0000EO/UID0000ON, and aggregate C++ remains blank to prevent duplicate emission.`
- Preserved exact parent/child bytes and hashes, callers/callees, zero-xref inlining evidence, current B001/B003/B004/B005 union, negative evidence, rejected alternatives, source order, and historical raw-pocket classification.

## Recommended Support Doc Changes

- D2-D5 are registered and complete with exact metadata, Item Summary, behavior/evidence/history/negative/rejected/score sections, managed bodies, owner/emitter UID0000EO, blank position, and Nested 0.
- D6 preserves UID00030C 92/94 metadata and all exact evidence while replacing only formal source duplication with the complete helper-call form and documented inlining parity.
- D7 preserves the complete class union and 93/94 while installing the complete class block with five added private declarations, target child/range/source behavior, and lexical caps.
- D8 preserves 93/93 and all B001/B003/B004/B005 content while adding exact source order, four children, two external helper names, inlining relationship, parent false state, and generated results.
- D9 preserves 87/91/blank and adds bounded `GetLineIndexForTextOffset` and `ScrollCaretIntoView` contracts plus their target caller relationship.
- D10 preserves 88/92 false/ownerless/blank/Nested -8 and adds the complete four-child TextEditPane union under UID0003N0 without claiming TextBox ownership.
- D11 adds exact `[5914c4,5914d0)`, `[59151c,591520)`, `[591639,591640)`, `[5916b5,5916c0)`, and `[59173e,591740)` CC padding entries with hashes and adjacency.
- Verify-only UID0004T1, UID00030D, UID0004T8, TextRunMeasureCallback, DrawTextRunCallback, ScrollablePane, Pane, Rect/GrafPort, and constructor/destructor/serialization pages remain unchanged; validator-managed reverse-index/generated side effects are recorded separately.

## Score And Metadata Recommendation

- UID0003N0 historical 85/88 true owner/emitter 0000EO state is superseded by current 92/94 false owner 0000EO, blank emitter/position/formal, Nested 8.
- RefreshTextRange child: 92/94, true, owner/emitter 0000EO, blank position, Nested 0.
- GetCaretBounds, DrawTextRange, DrawCaret children: 91/93 each, true, owner/emitter 0000EO, blank position, Nested 0.
- UID00030C stays 92/94; UID0004T1 stays 92/94; UID00030D stays 91/93; UID0004T8 stays 91/93.
- UID0000EO stays 93/94 and UID0000ON stays 93/93. The target island is closed, but unrelated key/mouse/navigation/formatting raw families prevent broader final-audit scores.
- Completion improvement is justified by exact split, formal bodies, helper/source graph, generated plan, and no-code parent proof. Confidence remains below 95 solely because private symbols and two flag names are absent.

## Open Questions With Attempted Resolution

- Exact original private names: symbols, strings, old reports, sibling vocabulary, callers, duplicates, and file route were checked. `GetCaretBounds`, `DrawTextRange`, and `DrawCaret` are the strongest project-consistent names. Remaining lexical uncertainty caps score but does not block C++.
- Exact flag names for 0x08/0x10: every use in the TextEdit corridor was searched. Their behavior is exact, but no symbolic name survives. Formal source uses literals and prose records descriptive semantics.
- Why zero-xref methods survive: xrefs, pointer routes, vtables, and duplicates were checked. Complete out-of-line methods plus exact inlined OnDraw logic make ordinary retained methods the highest-probability source shape.
- Should OnDraw remain duplicated: compiler output is behavior-equal either way, but retained helpers make helper calls the stronger human source. D6 provides the full no-loss rebase.
- Should the parent emit declarations: declarations belong to UID0000EO and method bodies to exact children. Parent has no unique source payload, so blank false is definitive.
- No investigable question remains unresolved. Only irrecoverable lexical certainty limits confidence.

## Exact Manual Supervisor-Owned Coverage Or Tracker Text

- Historical pre-application snapshots were supervisor validators `15158` (`by-memory`) SHA256 `25A7542D3FEA9C2FBDFA4C9CBB4D44A0CE6B220498E17A203837B1803ABD97A6`, `15159` (`by-class`) SHA256 `0BA9950EF44A7F69EA4F879F6A930E45768988AC553B493238D9BDFF860624DB`, and `15160` (`by-file`) SHA256 `D52DD7A9FA38EB4724B9C486208D9B860F82719C8620C6F973C72787CC4A75E5`, each exit 0/ok 1. Supervisor then applied the exact rows retained below and validated them with by-memory command `15174` at `2026-07-20T07:31:00-04:00`, by-class command `15175` at `2026-07-20T07:31:11-04:00`, and by-file command `15176` at `2026-07-20T07:31:18-04:00`, each exit 0/ok 1. Current read-only files are `by-memory/-coverage-report.md` SHA256 `00628B4984D76EEE97407C84A75897AAD3FABF8F413B5773A7FDED4989A73D49` (1,832,000 bytes/4,350 lines), `by-class/-coverage-report.md` SHA256 `37708DD4D953E150B99AB0BFA54D61DC8C3EEB97D76AD77832E37FF86F0B5A78` (238,962/623), `by-file/-coverage-report.md` SHA256 `7A7A0E96E61711F4F6F89E80BC01E999F028D1FC1E902D053BC8ABFD5792030E` (137,429/316), and unchanged `by-type/by-struct/-coverage-report.md` SHA256 `FEB144165B08A72402ED071C1C359C7A9BCE12A93541B84C2721A1D477805AE0` (57,041/137).
- Current by-memory anchors are UID0003N0 line 3311, UID0004TC line 3312, first padding line 3313, UID0004TD line 3314, second padding line 3315, third padding line 3317, UID0004TE line 3318, fourth padding line 3319, UID0004TF line 3320, and fifth padding line 3321. Each target/child/padding row occurs exactly once. Merged UID0000EO occurs once at by-class line 550 and merged UID0000ON occurs once at by-file line 284. The by-struct file still contains zero `TextEditPane` and zero `TextRun` occurrences; its one general RectBoundsLayout row at line 96 remains unaffected, so no by-struct addition/replacement/deletion was required.
- The exact target replacement, four real-UID child additions, five ignored-padding additions, class replacement, and file replacement below are retained verbatim as the supervisor-applied handoff evidence. Each is now present exactly once at same-or-greater detail. The class/file rows preserve every concrete prior fact before adding B004's accepted source-closure detail; they are unions, not summaries. No temporary UID token and no B004 manual coverage delta remain.
- Supervisor-applied UID0003N0 by-memory replacement retained as exact applied text:

`        - [UID:0003N0][0x00591400-0x005917c9.TextEditPaneCoreAfterTextBoxPane](by-memory/0x00591400-0x005917c9.TextEditPaneCoreAfterTextBoxPane.md) 0x00591400-0x005917c9 | non-emitting split index | TextEditPaneCoreAfterTextBoxPane : not_reconstructable : 92% : very-strong : Exact non-emitting TextEditPane post-TextBox split index for RefreshTextRange, GetCaretBounds, UID0004T1 BuildTextRangeRectangles, DrawTextRange, DrawCaret, and UID00030D InvalidateTextRegion; exact child ranges/bytes/hashes/ABI/source order and five internal CC padding spans are closed, all source routes through UID0000EO/UID0000ON, and aggregate C++ remains blank to prevent duplicate emission.`

- Supervisor-applied exact real-UID child rows retained in address order beneath UID0003N0, interleaved with the padding rows below:

`        - [UID:0004TC][0x00591400-0x005914c4.TextEditPaneRefreshTextRange](by-memory/0x00591400-0x005914c4.TextEditPaneRefreshTextRange.md) 0x00591400-0x005914c4 | private method | TextEditPaneRefreshTextRange : reconstructable : 92% : very-strong : Exact live TextEditPane::RefreshTextRange with 20 code xrefs, signed-short text-offset-to-line lookup, line-table rebuild, alignment-dependent TextRunMeasureCallback pass, suspend-refresh/display flags, inherited m_contentRect invalidation, active endpoint caret scrolling, complete human C++, and compiler-cookie exclusion.`

`        - [UID:0004TD][0x005914d0-0x0059151c.TextEditPaneGetCaretBounds](by-memory/0x005914d0-0x0059151c.TextEditPaneGetCaretBounds.md) 0x005914d0-0x0059151c | private const method | TextEditPaneGetCaretBounds : reconstructable : 91% : very-strong : Exact retained TextEditPane::GetCaretBounds source with signed-short caret index, caller-owned RectBounds, Point {y,x}, text-area-left decrement rule, one-pixel right edge, line-height bottom, zero direct raw-start xrefs, inlined OnDraw/DrawCaret parity, and complete human C++.`

`        - [UID:0004TE][0x00591640-0x005916b5.TextEditPaneDrawTextRange](by-memory/0x00591640-0x005916b5.TextEditPaneDrawTextRange.md) 0x00591640-0x005916b5 | private method | TextEditPaneDrawTextRange : reconstructable : 91% : very-strong : Exact retained TextEditPane::DrawTextRange source with clip reread/empty rejection, zeroed TextRunDrawState, inverse current-color flag, DrawTextRunCallback iteration, signed-short line endpoints, zero direct raw-start xrefs, inlined OnDraw parity, and complete human C++.`

`        - [UID:0004TF][0x005916c0-0x0059173e.TextEditPaneDrawCaret](by-memory/0x005916c0-0x0059173e.TextEditPaneDrawCaret.md) 0x005916c0-0x0059173e | private method | TextEditPaneDrawCaret : reconstructable : 91% : very-strong : Exact retained TextEditPane::DrawCaret source with read-only gate, selection-start caret bounds, m_textColor, SetDrawColor, exact g_pfnFillRect ABI, zero direct raw-start xrefs, inlined OnDraw parity, complete human C++, and cookie/compiler-lowering exclusion.`

- Supervisor-applied exact ignored rows retained at their corresponding address positions in by-memory coverage:

`        - [UID:0000VN][-ignored](by-memory/-ignored.md) 0x005914c4-0x005914d0 | padding | TextEditPane RefreshTextRange to GetCaretBounds alignment : ignored : 100% : very-strong : Twelve exact 0xcc compiler-alignment bytes, SHA256 A0D08A155AA4E9AADD5DA959565DE99ACC8DC9DBDA96EC3852DDE76C97330902.`

`        - [UID:0000VN][-ignored](by-memory/-ignored.md) 0x0059151c-0x00591520 | padding | TextEditPane GetCaretBounds to BuildTextRangeRectangles alignment : ignored : 100% : very-strong : Four exact 0xcc compiler-alignment bytes, SHA256 8843B54D2DF63CA265CF4A05D27DD2B29A74FB476D296DD44A0E171D74B441CA.`

`        - [UID:0000VN][-ignored](by-memory/-ignored.md) 0x00591639-0x00591640 | padding | TextEditPane BuildTextRangeRectangles to DrawTextRange alignment : ignored : 100% : very-strong : Seven exact 0xcc compiler-alignment bytes, SHA256 F145ECA66705DE68FF53C6D80E34D8F9A5B535FFA157194AA98BDB68AEA4368D.`

`        - [UID:0000VN][-ignored](by-memory/-ignored.md) 0x005916b5-0x005916c0 | padding | TextEditPane DrawTextRange to DrawCaret alignment : ignored : 100% : very-strong : Eleven exact 0xcc compiler-alignment bytes, SHA256 3682C0A62515050101266CC639BF81F5D8C5395F49E7DA93FCC22603018E0943.`

`        - [UID:0000VN][-ignored](by-memory/-ignored.md) 0x0059173e-0x00591740 | padding | TextEditPane DrawCaret to InvalidateTextRegion alignment : ignored : 100% : very-strong : Two exact 0xcc compiler-alignment bytes, SHA256 E3966E3275BE536A16092EC0CADF1638F718218E616FBBE8FF1C5E67FFF4DEF2.`

- Supervisor-applied by-class UID0000EO same-score no-loss replacement retained as exact applied text:

`- [UID:0000EO][TextEditPane](by-class/TextEditPane.md) : reconstructable : 93% : very-strong : Complete TextEditPane declaration preserving the exact constructor, ordinary destructor, source-ready EncodeState(unsigned short *outSize) const, low-word text/16-16-4 serialization fields, private ReleaseFormatObjects, compiler-vtable boundary, exact four List * fields and 2/16/16/4-byte element tables m_textStorage/wchar_t, m_lineTable/TextEditLineRecord, m_formatTable/TextEditFormatRecord, and m_formatRuns/TextEditFormatRun, signed TextEditFormatRecord reference counts, complete TextRunDrawState before OnDraw, exact TextRunMeasureCallback and DrawTextRunCallback friends, source-ready OnDraw, private BuildTextRangeRectangles/GetLineIndexForY helpers, caret/text-area/selection/scroll APIs, class closure before children, and residual unrelated raw-helper caps only; adds exact private GetLineIndexForTextOffset, ScrollCaretIntoView, UID0004TC RefreshTextRange, UID0004TD GetCaretBounds, UID0004TE DrawTextRange, and UID0004TF DrawCaret declarations while preserving BuildTextRangeRectangles and InvalidateTextRegion, makes OnDraw call DrawTextRange and DrawCaret in human source, and records exact source order RefreshTextRange -> GetCaretBounds -> BuildTextRangeRectangles -> DrawTextRange -> DrawCaret -> InvalidateTextRegion. UID0004TC has 20 code xrefs; UID0004TD/UID0004TE/UID0004TF are retained out-of-line source methods with zero direct start xrefs whose uses are optimizer-inlined in OnDraw; UID0003N0 is the false/non-emitting split index and compiler padding remains non-source.`

- Supervisor-applied by-file UID0000ON same-score no-loss replacement retained as exact applied text:

`- [UID:0000ON][TextEditPane](by-file/TextEditPane.md) : reconstructable : 93% : very-strong : Rich text editor implementation preserving the source-ready twelve-argument constructor, ordinary destructor, private ReleaseFormatObjects helper, signed format-record reference counts, exact four List * fields and element/record types m_textStorage/wchar_t (2 bytes), m_lineTable/TextEditLineRecord (16 bytes), m_formatTable/TextEditFormatRecord (16 bytes), and m_formatRuns/TextEditFormatRun (4 bytes), exact EncodeState order/width/truncation/ownership behavior, shared TextRunMeasureCallback/DrawTextRunCallback measure/draw callbacks, active-editor and IME lifecycle, exact caret/text-area/selection/scroll APIs, compiler wrapper/vtable/base/EH separation, TextEdit support-object split from TextFilter, and separately bounded residual raw islands; preserves exact file-local UID0004T8 PutScrapToClipboard source with TextEditScrap duplicate ownership, CRLF normalization, ACP/CF_TEXT publication, pointer Win32Error/cleanup behavior, select/copy/cut/UserList callers, and the final UID00030C OnDraw union. Adds exact post-TextBox source order UID0004TC RefreshTextRange -> UID0004TD GetCaretBounds -> UID0004T1 BuildTextRangeRectangles -> UID0004TE DrawTextRange -> UID0004TF DrawCaret -> UID00030D InvalidateTextRegion, with the exact child ranges and five interleaved compiler-padding spans; UID0004TC's 20 code xrefs, UID0004TD/UID0004TE/UID0004TF zero-start-xref retained-source status and optimizer-inlined OnDraw parity, source-ready UID00030C calls to DrawTextRange and DrawCaret, helper contracts/types, complete human C++, and UID0003N0 false/non-emitting parent disposition are closed without changing the NexusTK/ui/controls/TextEditPane.cpp route or unrelated raw-family score cap.`

- The supervisor applied these exact rows and validated them through commands `15174`-`15176`; B004 made no manual coverage edit. Validator-generated tracker/coverage output is not a substitute for this verified manual parity.

## Follow-Up Actions

- External boundary: supervisor application and validation of the exact manual coverage handoff are complete external facts under commands `15174`-`15176`. Report validation, execution, count, path movement, and archive state remain supervisor/validator-owned facts; this artifact neither directs nor asserts those lifecycle states.
- A-agent actions: none required for the target decision. Optional separately authorized IDA renames/types may use the recommendations above.
- B004 callback scope D1-D11 is complete, including serial registration/placeholder replacement, scoped validators, waited generated readback, and same-report terminal reconciliation.
- No implementation item or B004 manual coverage delta remains inside the assigned range. The exact applied handoff is retained above as durable supervisor-owned coverage evidence.

## Confidence

- Recommendation confidence: 94/100. Exact boundaries, source semantics, owner, and file route converge.
- Score confidence: 93/100. The score caps reflect lexical/inlining inference rather than missing behavior.
- Remaining uncertainty: original private method and flag symbol spellings only. No uncertainty affects range, ABI, split, owner/emitter, source placement, behavior, or eligibility for formal C++.

## Validator Results

- Every scoped command ran from `source-3/project-documentation`, exited `0`, and reported `ok:1`; registration commands assigned the listed UID and deferred generation. Warnings were pre-existing reference/index warnings only and did not invalidate any changed page.

| Command | Timestamp | Scope/result | Side effects |
| --- | --- | --- | --- |
| `000000015063` | `2026-07-20T06:04:52-04:00` | Registered/validated UID0004TC; exit 0, ok 1 | UID assigned; registry/reference/stats metadata; generated deferred |
| `000000015064` | `2026-07-20T06:06:20-04:00` | Registered/validated UID0004TD; exit 0, ok 1 | UID assigned; registry/reference/stats metadata; generated deferred |
| `000000015071` | `2026-07-20T06:07:29-04:00` | Registered/validated UID0004TE; exit 0, ok 1 | UID assigned; registry/reference/stats metadata; generated deferred |
| `000000015081` | `2026-07-20T06:08:45-04:00` | Registered/validated UID0004TF; exit 0, ok 1 | UID assigned; registry/reference/stats metadata; generated deferred |
| `000000015107` | `2026-07-20T06:12:35-04:00` | UID0003N0 D1; exit 0, ok 1 | registry/reference/stats metadata; generated deferred |
| `000000015117` | `2026-07-20T06:15:34-04:00` | UID00030C D6; exit 0, ok 1 | registry update, three new references, stats metadata; generated deferred |
| `000000015118` | `2026-07-20T06:17:33-04:00` | UID0000EO D7; exit 0, ok 1 | registry update, five references, one normalized UID link, pre-existing missing-ref warnings; generated deferred |
| `000000015119` | `2026-07-20T06:19:13-04:00` | UID0000ON D8; exit 0, ok 1 | six references, nine normalized UID links, pre-existing missing-ref warnings; generated deferred |
| `000000015120` | `2026-07-20T06:20:06-04:00` | UID0001JM D9; exit 0, ok 1 | two references/stats metadata; generated deferred |
| `000000015121` | `2026-07-20T06:21:12-04:00` | UID0001JO D10; exit 0, ok 1 | seven references/stats metadata, pre-existing missing-ref warnings; generated deferred |
| `000000015122` | `2026-07-20T06:22:35-04:00` | UID0000VN D11; exit 0, ok 1 | seven references/stats metadata, pre-existing ignored-page missing-ref warnings; generated deferred |
| `000000015126` | `2026-07-20T06:22:56-04:00` | Historical B004 callback-final UID0003N0 `--wait-generated`; exit 0, ok 1 | registry rebuild and authorized generated refresh completed at that callback epoch |
| `000000015162`-`000000015172` | external post-callback epoch | Fresh supervisor scoped validators; each exit 0, ok 1 | external revalidation only; no B004 ordinary edit |
| `000000015173` | `2026-07-20T07:06:50-04:00` | Current external waited generated refresh; exit 0, ok 1 | current `TextEditPane.cpp` authority; no B004 generated edit |
| `000000015174` | `2026-07-20T07:31:00-04:00` | Supervisor-applied by-memory coverage validation; exit 0, ok 1 | exact parent/child/padding handoff present once; no B004 coverage edit |
| `000000015175` | `2026-07-20T07:31:11-04:00` | Supervisor-applied by-class coverage validation; exit 0, ok 1 | exact merged UID0000EO row present once; no B004 coverage edit |
| `000000015176` | `2026-07-20T07:31:18-04:00` | Supervisor-applied by-file coverage validation; exit 0, ok 1 | exact merged UID0000ON row present once; no B004 coverage edit |

- Exact formal equality check: report Destinations 1-7 equal the managed blocks in UID0003N0, UID0004TC, UID0004TD, UID0004TE, UID0004TF, UID00030C, and UID0000EO respectively; D1 is exactly blank and D2-D7 lengths are 822/406/456/251/1,164/7,536 normalized characters.
- Historical B004 command `000000015126` established the callback-generated result. Current external command `000000015173` revalidates it: exactly one definition each for RefreshTextRange, GetCaretBounds, DrawTextRange, DrawCaret, existing OnDraw, UID0004T1 BuildTextRangeRectangles, and UID00030D InvalidateTextRegion; zero UID0003N0 occurrences; exactly one normal provenance comment each for UID0004TC/UID0004TD/UID0004TE/UID0004TF; zero `Empty Emitter Marker` for each new child; zero duplicate/raw/sub/offset/cookie/EH/vtable/manual-cleanup source. Exactly five unrelated pre-existing Empty Emitter Markers remain precisely accounted for.

## Changed Files

- Created and registered: UID0004TC `by-memory/0x00591400-0x005914c4.TextEditPaneRefreshTextRange.md`; UID0004TD `by-memory/0x005914d0-0x0059151c.TextEditPaneGetCaretBounds.md`; UID0004TE `by-memory/0x00591640-0x005916b5.TextEditPaneDrawTextRange.md`; UID0004TF `by-memory/0x005916c0-0x0059173e.TextEditPaneDrawCaret.md`.
- Modified ordinary: `by-memory/0x00591400-0x005917c9.TextEditPaneCoreAfterTextBoxPane.md`, `by-memory/0x00590810-0x005909e3.TextEditPaneOnDraw.md`, `by-class/TextEditPane.md`, `by-file/TextEditPane.md`, `by-memory/0x0058dce0-0x00591300.TextEditPaneCoreBeforeTextBoxPane.md`, `by-memory/0x00591300-0x005954b3.TextBoxPaneNoncontiguousAuditMap.md`, and `by-memory/-ignored.md`.
- Modified report: this same `tools/leaser/Agents/Agent-B004/research/0003N0-TextEditPaneCoreAfterTextBoxPane-source-quality.md` artifact, preserving all research and managed blocks while recording terminal callback truth.
- Renamed: none. Verify-only UID0004T1, UID00030D, and UID0004T8 remain at the exact hashes listed in Current Target State.
- Validator-owned side effects only: generated `TextEditPane.cpp`, tracker/registry/reference/projected-stat metadata refreshed through authorized ordinary validators. B004 made no manual edit to any generated, tracker, registry, validator-state, or stats file.
- Supervisor-owned post-callback changes: exact manual by-memory/by-class/by-file coverage text was applied and validated externally under commands `15174`/`15175`/`15176`; this reconciliation edits only the report and records the resulting hashes/anchors.
- Leases: one path at a time immediately before edit; every ordinary lease released immediately after its scoped validator. The first report-only reconciliation lease expired during final auditing and cleanup returned `Rejected[No active lease]`; the later short generated-marker wording-repair lease was released before that return. This post-coverage report reconciliation used no lease, and zero B004 leases remain.
- Report execution: not run by B004. No lifecycle, move, archive, count, probe, revalidation, or `execute_report` command was run.

## Implementation Tracking Checklist

Initial report-only pass:

- [x] Supervisor validation required before implementation.
- [x] Re-read UID0003N0 immediately before callback and preserve concurrent detail.
- [x] Set UID0003N0 to 92/94, owner 0000EO, false, blank emitter/position/formal, Nested 8.
- [x] Install the exact D1 blank managed block and parent no-code proof.
- [x] Register `[0x00591400,0x005914c4)` first and capture its real UID.
- [x] Replace every UID0004TC pre-registration token before cross-linking.
- [x] Install D2 RefreshTextRange metadata, evidence, Item Summary, and exact formal body.
- [x] Register `[0x005914d0,0x0059151c)` second and capture its real UID.
- [x] Replace every UID0004TD pre-registration token before cross-linking.
- [x] Install D3 GetCaretBounds metadata, evidence, Item Summary, and exact formal body.
- [x] Register `[0x00591640,0x005916b5)` third and capture its real UID.
- [x] Replace every UID0004TE pre-registration token before cross-linking.
- [x] Install D4 DrawTextRange metadata, evidence, Item Summary, and exact formal body.
- [x] Register `[0x005916c0,0x0059173e)` fourth and capture its real UID.
- [x] Replace every UID0004TF pre-registration token before cross-linking.
- [x] Confirm no placeholder token remains anywhere after registration.
- [x] Install D5 DrawCaret metadata, evidence, Item Summary, and exact formal body.
- [x] Preserve UID0004T1 body/score/metadata/hash exactly.
- [x] Preserve UID00030D body/score/metadata/hash exactly.
- [x] Preserve UID0004T8 external sibling and seven-byte boundary exactly.
- [x] Apply D6 complete UID00030C OnDraw helper-call rebase without behavior loss.
- [x] Preserve UID00030C 92/94 metadata and all unrelated source/evidence.
- [x] Apply D7 complete UID0000EO class block and close class before `[[CHILDREN]]`.
- [x] Preserve all B001/B003/B004/B005 class declarations and fields.
- [x] Keep UID0000EO at 93/94; do not inflate support score.
- [x] Apply D8 UID0000ON source order/route/inlining evidence at report-level detail.
- [x] Keep UID0000ON at 93/93; do not inflate support score.
- [x] Apply D9 helper vocabulary to UID0001JM while preserving blank aggregate and 87/91.
- [x] Apply D10 complete child union to UID0001JO while preserving false/ownerless/blank/Nested -8.
- [x] Add `[0x5914c4,0x5914d0)` exact ignored entry.
- [x] Add `[0x59151c,0x591520)` exact ignored entry.
- [x] Add `[0x591639,0x591640)` exact ignored entry.
- [x] Add `[0x5916b5,0x5916c0)` exact ignored entry.
- [x] Add `[0x59173e,0x591740)` exact ignored entry.
- [x] Preserve all historical broad-pocket wording as superseded history, not current truth.
- [x] Preserve exact byte hashes, ABI, CFG, callers/callees, xrefs, fields, globals, and helper contracts.
- [x] Preserve zero-xref/inlining liveness analysis and rejected no-code/compiler alternatives.
- [x] Preserve exact source placement and current complete TextEditPane union.
- [x] Apply every C3N0-001 through C3N0-046 claim at report-level detail.
- [x] Update Claim And Incorporation Ledger with real UIDs and callback verification states.
- [x] Replace all pre-registration manual-row placeholders with real UIDs.
- [x] Re-read manual by-memory/class/file coverage after supervisor commands 15174-15176; the exact parent/child/padding handoff and no-loss UID0000EO/UID0000ON unions are applied once each, preserve every concrete prior fact, and require no remaining B004 coverage delta.
- [x] Re-read the existing by-struct manual file and confirm from its current rows that no TextEditPane-specific addition/replacement/deletion is required.
- [x] Acquire only one ordinary-file lease immediately before each edit.
- [x] Reread each destination after lease acquisition and preserve concurrent content.
- [x] Run one scoped validator per changed ordinary page while its lease is active.
- [x] Record every validator command ID, timestamp, exit, ok, warnings, and side effects.
- [x] Release each lease immediately after edit/validation.
- [x] Run one final authorized waited UID0003N0 refresh after all ordinary edits.
- [x] Verify one emitted definition for each of the four new real UIDs.
- [x] Verify one UID00030C, UID0004T1, and UID00030D definition each.
- [x] Verify UID0003N0 occurs zero times; UID0004TC/UID0004TD/UID0004TE/UID0004TF each has one normal provenance comment and zero `Empty Emitter Marker`.
- [x] Verify zero raw/sub/helper-offset/cookie/EH/vtable/manual-cleanup source artifacts.
- [x] Verify unrelated generated definitions/markers remain same-or-greater and accounted for.
- [x] Record exact final ordinary/generated/tracker/manual hashes and readback.
- [x] Update Current Target State, recommendations, Changed Files, Validator Results, ledger, and checklist to callback truth.
- [x] Confirm no manual coverage/generated/tracker/audit/supervisor/IDA/lifecycle file was edited.
- [x] Confirm zero leases remain.
- [x] Confirm B004 ran no `execute_report`, lifecycle, probe, count, move, archive, or revalidation command.

Implementation callback pass:

- [x] Exact report artifact accepted by supervisor for implementation.
- [x] All accepted D1-D11 details incorporated at report-level depth.
- [x] Four children registered serially and every temporary UID replaced.
- [x] All C3N0-001 through C3N0-046 verification states are legal terminal states with destination proof.
- [x] Metadata/score/owner/emitter/split/C++ changes applied exactly.
- [x] Historical assumptions, negative evidence, rejected alternatives, and source-placement rationale preserved.
- [x] All scoped validators pass and command evidence is recorded.
- [x] Final waited generated readback passes every positive and negative assertion.
- [x] Exact supervisor-owned manual coverage handoff uses real UIDs, was applied and validated by commands 15174-15176, and matches current rows/hashes once each.
- [x] No accepted implementation item remains unapplied.
- [x] Zero leases remain and no forbidden file/command was touched.

READY_FOR_SUPERVISOR_EXECUTE

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B004","command_id":"000000015177","destination_path":"executed-b-agent-research/B004/0003N0-TextEditPaneCoreAfterTextBoxPane-source-quality.md","details":"report executed into central archive","event":"executed","source_path":"tools/leaser/Agents/Agent-B004/research/0003N0-TextEditPaneCoreAfterTextBoxPane-source-quality.md","timestamp":"2026-07-20T07:38:59-04:00","uid":"0003N0"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
