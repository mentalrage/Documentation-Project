** TARGET-REPORT-UID:00030E **
** AUTHOR-AGENT-ID:B002 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.6 | xHigh **
# UID00030E TextEditPaneOnMouseEvent Ownership / Split Research


## Finalized Report / Current Recommendation

- Applied callback state: [UID:00030E] is the exact source-authored `bool TextEditPane::OnMouseEvent(Event *event)` child of [UID:0000EO] TextEditPane, emitted through [UID:0000ON] TextEditPane. It is `92/94`, `RECONSTRUCTABLE:TRUE`, owner/emitter `0000EO`, blank optional position, and `Nested:0`; Destination 1 is installed as the complete behavior-preserving method body.
- Final disposition: the modeled function remains `[0x00590de0,0x0059116c)` and the trailing `[0x0059116c,0x00591180)` twenty-byte region remains its compiler-generated five-entry local switch table. The table receives no separate source page or handwritten array. The target owns the source `switch` that regenerates it.
- Callback result: the complete mouse-handler body is installed on UID00030E; Destinations 3-4 refine the only semantic caller of `TextEditObject` vtable slot `+0x10` from historical `OnAction(int,int,int)` to `OnMouseEvent(Event *,bool,unsigned int)`; and Destinations 6-7 carry the bounded aggregate/file prose. Destination 2 remains current at whitespace-normalized semantic parity and Destination 5 remains byte-equal, so both were verified read-only. B004 UID0003N0 and B005 UID00030F remain executed and centralized. Terminal B005 artifact `executed-b-agent-research/B005/00030F-TextEditPaneOnKeyEvent-source-quality.md`, post-lifecycle SHA256 `C6B14C8772182E53D454E4011DD231D9EDB9744F94040663E592D0AFFC0FCAB4`, executed by supervisor command `000000015329`, still exclusively owns the six-child UID0001JS split. Its real UID0004U9 file-local word-boundary and UID0004UA autoscroll pages remain applied read-only dependencies consumed without duplicate page or body. The exact six-action manual handoff remains supervisor-owned and unapplied by B002.
- Confidence: very strong for range, liveness, ABI, event cases, fields, helper behavior, table disposition, owner, and source file; strong for descriptive original-unknown private helper and click-state spellings. These spellings are evidence-backed source-facing inference, not recovered symbols, and cap the recommendation at `92/94` rather than final-audit confidence.

## Supporting Research

- This is a new direct report for [UID:00030E]. No executed, archived, legacy, or active exact-range B report was found under the searched report roots. Older reports are support evidence only.
- Central executed root `executed-b-agent-research/` was searched with `UID00030E`, `00030E`, `0x00590de0`, `0x00591180`, `TextEditPaneOnMouseEvent`, `TextEditPane::OnMouseEvent`, `sub_590DE0`, `0x0058f690`, `0x0058f9a0`, `0x0058fa00`, and `s_mouseSelectionAnchor`. Relevant opened reports were B004 `0000ON-TextEditPane-empty-emitter-family-source-quality.md`, B004 `00030C-TextEditPaneOnDraw-source-quality.md`, B005 `0001JS-TextEditPaneInputNavigationWrapAndTextRunHelpers-source-quality.md`, B001 `0001JP-0001JS-texteditpane-format-nav-source-quality.md`, B001 `00018E-InputMan-source-quality.md`, and B005 `0000EO-TextEditPane-class-source-quality.md`. They prove the family route, Event-independent method role, helper islands, `CompleteImeComposition`, and earlier blank-body blocker, but none reconstructs UID00030E.
- Legacy executed roots `tools/leaser/Agents/Older-Research/` and `tools/leaser/Agents/SpecialReports/` were searched with the same terms and produced no direct match.
- Archived roots `archived/b-agent-reports-20260623/` and `archived/duplicate-loose-b-agent-reports/` were searched with the same terms and produced no direct match.
- Active roots `tools/leaser/Agents/Agent-B001/research/` through `Agent-B005/research/` were searched with the same terms. B004 UID0003N0 is centralized at `executed-b-agent-research/B004/0003N0-TextEditPaneCoreAfterTextBoxPane-source-quality.md`, final-read SHA256 `6916471DDD88638D7D28E28F211D73A4615A1C1C842F571D2D4D82A76662BEE6`, 91,724 bytes/906 lines, execution command `000000015177`; its UID0004TC/TD/TE/TF union is the durable ordinary base. B005 UID00030F is now centralized at `executed-b-agent-research/B005/00030F-TextEditPaneOnKeyEvent-source-quality.md`, post-lifecycle SHA256 `C6B14C8772182E53D454E4011DD231D9EDB9744F94040663E592D0AFFC0FCAB4`, 178,580 bytes/1,845 lines, execution command `000000015329`; the former active research path no longer exists. It preserves twelve managed destinations, six real UID0001JS children, complete UID0004U9/UID0004UA bodies, exact no-duplicate B002 coordination, source-semantic `m_unusedClickState +0x168`, compiler-natural alignment, and full generated/validator proof. Earlier B005 active-path hashes are historical repair snapshots and are not current dependency authority. No B001-B005 report other than this artifact directly targets UID00030E.
- No-loss comparison result: Destination 2 incorporates B004's four private draw/refresh helpers and B005's complete expanded `CopySelectionToScrap`, bool key/key-up, navigation dispatcher, wrap-measure, distinct member/file-local word-boundary, bool autoscroll, and composition union. UID00030E's stronger direct offset evidence supersedes only stale spellings that conflict with the mouse body: `m_dragSelectionActive` becomes `m_selectionReversed`, `m_mouseMode` becomes the exact click-state field group, and autoscroll arguments become `(y,x)`. B005 independently confirms the latter and strengthens its return to `bool`. Destination 5 updates B004 UID0004TC's sole stale active-endpoint token. No B004 body, B005 child/body, or residual UID0001JS debt is duplicated or dropped.
- B005 dependency validation: fresh read-only MCP `idb_list` rediscovered active database `9b0396a3`, worker PID 15732. HTTP session `b1bdab9a-78d8-426e-bb0a-b966669d164a` returned `server_health:ok` with auto-analysis, Hex-Rays, and strings ready; bounded-call session `6394e934-3d01-4a2d-904a-bbaa506515e3` returned UID00030E `sub_590DE0` size `0x38c`, UID0004U9 `sub_594B50` size `0x160`, and UID0004UA `sub_594CB0` size `0x162`. Their first 16 bytes were respectively `55 8b ec 83 ec 20 53 56 57 8b f9 f6 87 5c 01 00`, `55 8b ec 80 7d 14 00 56 57 66 8b 7d 0c 75 32 8b`, and `55 8b ec 53 8b d9 57 33 ff f6 83 5c 01 00 00 01`. Prior complete reads remain exact: UID0004U9 is 352 bytes, SHA256 `33798227F960F8091AFB961D915136FD0275ED6D530360F825422AED0E372978`; UID0004UA is 354 bytes, SHA256 `303B3931B327517E97504D8C56CD9FD7450974CAE6BE2D4927A4E87C29011FB2`. B005 exclusively owns both applied pages; B002 consumes the real UIDs/contracts and creates no duplicate.
- Historical B004 UID0000ON deferred this source body until Event/helper naming was closed. That deferral is superseded here by current Event declarations, pane-capture precedents, direct helper decompilation, InputMan's accepted composition-finalizer identity, and field-use reanalysis.
- Historical B005 UID0000EO proposed `int OnMouseEvent(Event *)`, provisional fields around `+0x158..+0x173`, and `s_mouseSelectionAnchor = -1`; current Event/binary/global pages supersede those points with `bool`, corrected field roles, and zero-initialized `static short s_mouseSelectionAnchor = 0`.

## Target

- Target UID: `00030E`.
- Target path: `by-memory/0x00590de0-0x00591180.TextEditPaneOnMouseEvent.md`.
- Source queue/report row: at the final waited-read boundary, tracker command `000000015346`, refreshed `2026-07-20T13:31:37-04:00`, SHA256 `8DD00EFBEB8D924375C940CB55B000E9E938F65111308ACAC87ABEE92FB0A4F3`, 1,530,688 bytes/6,205 lines, records UID00030E at line 3241 as `92/94`, combined `93.0`, reconstructable true, `Nested 0`, zero direct reports; UID0004U9/UID0004UA occur at lines 3248/3249 at `92/94`; executed UID00030F occurs at line 3920 at `92/94` with one B005 direct report; UID0001JS occurs at line 4154 at `90/92`; and externally executed B003 UID0001NG occurs at line 5345 at `92/94`, false, with one B003 direct report. Commands 15338, 15333, 15329, 15325, and their hashes remain explicit historical epochs. This observation is time-bounded rather than an indefinite tracker lock.
- Current callback classification: source-bearing reconstructable virtual method plus local compiler switch table; owner/emitter UID0000EO; complete formal C++ installed and target blank-emitter blocker cleared.
- Current scores and parent state: target `92/94`; class [UID:0000EO] `93/94`; file [UID:0000ON] `93/93`; parent aggregate [UID:0001JM] `87/91`; module-static anchor [UID:000303] `87/91`.

## Current Target State

- Applied metadata: `COMPLETION:92`, `CONFIDENCE:94`, `CANONICAL_OWNER:0000EO`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000EO`, blank optional position, complete Destination 1 formal block, and `Nested:0`.
- Owner/emitter/reconstructable state remains unchanged and correct. The method is the primary-vtable `+0x60` override in `TextEditPane.cpp`; no source/file migration or new owner was introduced.
- Current waited generated proof is validator command `000000015346`, refreshed `2026-07-20T13:31:37-04:00`, SHA256 `C7565637EDC6BA9CF10F7635234EDE2F028C22FC5F449231DFED9C20BA83C64E`, 62,112 bytes/1,824 lines. It contains one UID00030E provenance marker, exactly one `TextEditPane::OnMouseEvent` definition, zero UID00030E Empty Emitter Markers, one static anchor definition with eight target uses, one complete TextEditPane class, one TextEditObject mouse-hook declaration and one empty definition, one UID0004TC definition using `m_selectionReversed`, one UID0004U9 body plus its one prototype, one UID0004UA body, one intentional UID0001JS parent marker, and zero stale `OnAction`, `m_dragSelectionActive`, or `m_mouseMode` tokens. The target contains exactly two direct `::FindWordBoundary` calls and two ignored `AutoScrollSelectionToPoint(y,x)` calls. No handwritten switch table or vtable array appears.
- External freshness state: command `000000015333` centralized B003 UID0001NG, and command `000000015346` is the callback's final waited generated/tracker epoch. The current B003 artifact remains `executed-b-agent-research/B003/0001NG-SpellSlotInputPaneScalarDeletingDestructor-source-quality.md`, post-lifecycle SHA256 `2ADF3713C07ED694C0FCBC90048EAEC9C0162B295142327F84CCAA14524A775D`, 83,454 bytes/601 lines; supervisor coverage commands `000000015330`-`000000015332` and lifecycle command `000000015333` are external provenance, not B002 work. Commands 15338 and earlier generated/tracker snapshots are historical.
- Current manual roots after those external commands are by-memory SHA256 `A389E147EF2DD89DBB0E5B2D6491942E399512834FB7BB8C88F96FF79AC89E5C`, 1,851,119 bytes/4,396 lines; by-class `22ADD1F1931D9A32C0F68E0532E741FAB11C5A2BD7958D585063839BF0D0093A`, 239,369/623; and by-file `BE87AED1FF6456C49A9D4A5F815A496EF7FBF2ED825B005F2FE832E5663CB998`, 137,501/316. They preserve all 23 B005 rows and all nine B003 rows; the six B002 actions remain unapplied and are rebased below without overlap.
- All former open questions remain closed in the applied graph: Event type/payload direction, AL/bool return, capture helpers, composition helper, text hit-test role, line/format binary-search helpers, distinct member/file-local word-boundary helpers, applied UID0004U9/UID0004UA bodies, click-state fields, inline-object hook signature, asset-mode release return, switch-table ownership, and source placement have current direct answers. The former serialized B005 prerequisite is fulfilled without creating or modifying either dependency child.
- Historical stale class members are now superseded in the current union: `+0x158` is selection direction, live `+0x15a` is selection visibility, `+0x160/+0x164/+0x166/+0x167` are last-click time/index/hit-part/repeat count, `m_dirty` and `m_maskedText` are at `+0x169/+0x16a`, limits are at `+0x16c/+0x16e`, B005's independent composition booleans remain at `+0x170/+0x171`, and the constructor parameters remain at `+0x172/+0x173`.
- Related target/support docs checked: UID0000EO, UID0000ON, UID0001JM, UID000303, UID0000EN, UID00040S, B004 UID0004TC/TD/TE/TF, Event class/file, InputMan class/file/memory, `g_useEpfAssets`, ScrollablePane, RectBounds, List, final-read generated TextEditPane.cpp, tracker, manual by-memory/by-class/by-file/by-global/by-vtable coverage, active B001-B005 goals/reports, and lease ledger.
- Current artifact/lifecycle status: B002's authorized ordinary implementation, scoped validators, lease releases, final waited generation, and same-report reconciliation are complete. The six manual coverage actions and all report execution, movement, and archive state remain supervisor/validator-owned; this report does not assert their current or future lifecycle disposition.

## Executive Recommendation

- Keep UID00030E as one exact source method. Do not split five event cases into synthetic children; their common locals, click state, static anchor, and one local switch table support one original method.
- Emit a complete `bool TextEditPane::OnMouseEvent(Event *event)` body. Preserve all five cases and every unusual edge: an inactive editor returns true; move without capture returns false; left down/double click require `m_contentRect`; repeated-click timing is strict `< previous + 500`; format-object notification has no format-index/object-container guards beyond the observed object pointer and selected-index checks; IME composition finalization occurs before down-only capture; hit testing is deliberately repeated after focus/capture work; left-up return depends on `g_useEpfAssets != 1`; right-down clears selection; unknown types return false.
- Use the current Event ABI (`m_type`, pointer `m_y`, `m_x`, `m_modifiers`, `m_messageTime`) and exact existing enum names. Do not create a target-local event record.
- Correct the complete `TextEditPane` declaration rather than hiding live offsets behind padding or raw casts. Add exact private helper declarations with descriptive source names. Preserve B004's executed OnDraw/helper union and B005's expanded key/key-up/clipboard/navigation/wrap/word/autoscroll/composition union. The complete destination contains `TextEditRange`, the file-local `__stdcall` prototype, the distinct member wrapper, and bool `(y,x)` autoscroll without reproducing either B005-owned body.
- Rename the `TextEditObject` no-op slot used by this target to `OnMouseEvent(Event *,bool,unsigned int)`. This is stronger than retaining generic `OnAction`: the target is the only semantic callsite, and both TextEditObject/EPFTextEditObject vtables route the same source-empty slot.

## Supervisor Active Recheck

- The supervisor assigned UID00030E specifically to resolve the blank-formal and source-quality blockers rather than repeat the old deferral.
- The item requires a code/table distinction but not a source-method split. The exact method body ends at `0x0059116c`; the target page extends through the compiler table at `0x00591180`.
- Every source-bearing item needed for this recommendation has a precise disposition: UID00030E receives complete source; TextEditObject/UID00040S receive the refined empty mouse hook; the current TextEditPane declaration and UID0004TC body already match Destinations 2 and 5 and are verify-only; B005 UID0004U9/UID0004UA exclusively supply the file-local word-boundary and bool autoscroll definitions; Event/InputMan/global/capture support is source-bearing or verify-only. OnMouseEvent source closure is claimed only as this complete combined graph, never as D1 alone.
- Collision inventory at the final coordination read: B004 UID0003N0 is executed under command 15177; B005 UID00030F is executed under command 15329 at archive SHA `C6B14C87...CAB4`; UID0004U9/UID0004UA and the full UID0001JS union are applied. B002 owns only UID00030E, the TextEditObject class/core hook correction, and bounded aggregate/file prose. Current Destination 2 and Destination 5 are verify-only because their accepted values already match. B002 must not lease or edit UID0001JS or any B005 child. Final lease-ledger reread showed no B002, UID00030E, UID0001JS, TextEditPane, or shared-destination lease; volatile unrelated leases do not change this ownership boundary.

## Inference Research Guidance Check

- The incorporated inference discipline requires source-era human forms when symbols are stripped, while preserving direct binary behavior and clearly distinguishing inference from fact. It rejects `sub_*`, `this+N`, synthetic raw event structs, and decompiler temporaries in formal C++.
- Existing documentation was treated as fallible. In particular, the current class formal's `m_dragSelectionActive`, `m_mouseMode`, and post-`+0x160` packing were checked against direct instruction offsets and rejected where contradicted.
- Direct IDA facts are ranges, bytes, ABI cleanup, CFG, vtable/data xrefs, branches, constants, offsets, call targets, and global accesses. Documentation evidence supplies accepted subsystem/type vocabulary. Inference supplies original-unknown private helper and member spellings only.
- Wave2-era names `FinalizeIMEComposition`, `FindWordBoundary`, and `ClearActivePaneEntry_5449F0` were encountered. They were not accepted merely because they are old artifacts. Current executed reports and direct bodies independently support `CompleteImeComposition`, word-selection semantics, and `Pane::ReleaseMouseCapture`; the old artifacts are historical corroboration only.

## Heuristic / Inference Reanalysis And Validation

- Method identity: primary vtable cell `0x0062dff4` points to `0x00590de0`; the slot is primary `+0x60`, matching current Event/Pane family documentation for `OnMouseEvent`. `char` in Hex-Rays is the AL representation of source `bool`, not a reason to retain `char` or `int` in C++.
- Event ABI: `event+4/+8/+0xc/+0x10/+0x18` match current `Event::m_type` and pointer payload y/x/modifiers/messageTime exactly. The target never uses pointer `m_detail` at `+0x14`.
- Capture helpers: direct decompilation proves `0x005449d0` forwards the Pane's `this+0xa0` event-handler view to the global event manager, `0x005449f0` clears that capture, and `0x00544a00` tests equality. Existing FittingRoom/ScrollPane reports consistently name them `CaptureMouse`, `ReleaseMouseCapture`, and `HasMouseCapture`.
- Composition helper: `0x004e9490` gets the application HWND, calls `ImmGetContext`, `ImmNotifyIME(context,0x15,1,0)`, then `ImmReleaseContext`. Executed B001 InputMan identifies the standalone source helper as `BOOL __stdcall CompleteImeComposition()`, with this target as its sole caller. Destination 1 declares it directly before the method so current generated TextEditPane.cpp has compile-visible cross-TU linkage; by-file roots do not emit formal reconstruction metadata.
- Hit-test helper: `0x0058f690` subtracts positioned text-area top/left, maps negative y to text offset zero/hit-part zero, maps y below content to text length/hit-part `-1`, otherwise finds the line and iterates runs through `0x005936e0`. Best source name is `GetTextOffsetAtPoint(int y,int x,signed char *hitPart) const`; `HitTestText` is acceptable but less precise.
- Selection lookup helpers: `0x0058f0d0` binary-searches 16-byte line records by text offset; `0x0058f1b0` binary-searches 4-byte format runs. Best names are `GetLineIndexForTextOffset` and `GetFormatRunIndexForTextOffset`.
- Click-range helpers: `0x0058f9a0` is the four-argument member `GetWordSelectionRange` wrapper and `0x0058fa00` is `GetLineSelectionRange`; the latter intentionally ignores hit part. Separately, UID00030E's post-click and drag paths directly call B005's later file-local `FindWordBoundary(const wchar_t *,short,short,bool,TextEditRange *)` at `0x00594b50`. D1 therefore uses the member wrapper only for the saved repeated-click range and calls `::FindWordBoundary` directly at the two observed later sites.
- Selection mutation: `0x0058f2a0` clamps signed-short endpoints, normalizes visible start/end, writes direction at `+0x158`, updates `+0x144/+0x146`, invalidates changed spans, may reset `+0x167`, and scrolls the active endpoint. Current public name `SetSelectionRange` is behaviorally correct.
- Drag autoscroll: B005's complete D12 and independent MCP agree that `0x00594cb0` is `bool AutoScrollSelectionToPoint(int y,int x)`, not void `(x,y)`. It requires editor flag bit zero and selection-visible `+0x15a`, compares x/y to `m_contentRect`, clamps each pixel delta to 48, applies horizontal axis 1 directly, converts vertical pixels to signed line units through `GetLineHeight`, applies vertical axis 0, and returns true on both gated and full paths. UID00030E ignores the return exactly as the binary does.
- Inline object hook: one-character selection dispatches vtable slot `+0x10` on `TextRunFormatData::object` with `(event,repeatedClick,messageTime)`. The base slot at `0x00594f20` and EPF-derived reuse are source-empty, but the callsite proves semantic name/signature. Generic `OnAction(int,int,int)` is rejected as stale.
- Field resolution: direct uses prove `m_selectionReversed +0x158`, `m_currentFormatValid +0x159`, `m_selectionVisible +0x15a`, descriptive `m_scrollRangeDirty +0x15b`, `m_editorFlags +0x15c`, `m_lastClickTime +0x160`, `m_lastClickTextOffset +0x164`, `m_lastClickHitPart +0x166`, `m_repeatClickCount +0x167`, inferred source-semantic `unsigned char m_unusedClickState +0x168`, `m_dirty +0x169`, `m_maskedText +0x16a`, compiler-natural alignment at `+0x16b`, `m_maxLength +0x16c`, and `m_maxLines +0x16e`. The final B005 bounded constructor/mouse/selection/family access scan proves `+0x168` is physically occupied between byte fields and therefore is not natural padding, while finding no surviving direct access; `m_unusedClickState` is the strongest source-safe descriptive field, with exact original spelling and bool-versus-byte intent retained as lexical uncertainty. B005's independent key-handler evidence further resolves byte `+0x170` as `m_replacePreviousCompositionText` and `+0x171` as `m_replacedCompositionText`; constructor parameters remain `m_useDefaultAlignment +0x172` and `m_useThousandsSeparator +0x173`. The historical one-word `m_inputState`, provisional reserved-byte characterization, and explicit `+0x16b` padding member are rejected as current source declarations.
- Repeat timing: the binary uses unsigned `eventTime >= oldTime + 500` as the non-repeat branch, so source repeat is strict `eventTime < oldTime + 500` plus identical text offset. No overflow hardening or `<=` normalization is allowed.
- Local table: all five dwords in `[0x0059116c,0x00591180)` point into the same function. Cases 1 and 2 share `0x00590e1b`; case 0 is `0x00591051`; case 3 is `0x00591130`; case 4 is `0x00591158`. This is compiler output of the source switch.
- Rejected alternatives: free-function mouse handler, TextBoxPane owner, Event.cpp owner, InputMan owner, five synthetic case children, handwritten jump table, direct raw offsets, pointer-to-int `OnAction` casts, `m_mouseMode` at `+0x160`, `m_dragSelectionActive` at `+0x158`, `AutoScrollSelectionToPoint(x,y)`, unconditional true left-up return, and a safe-normalized object/format guard path.
- Remaining lexical uncertainty is bounded to private names. No behavioral, ABI, source-placement, or formal-C++ blocker remains in the combined B002 target plus B005-owned dependency graph. The former B005 child-registration prerequisite is externally complete: UID0004U9 and UID0004UA are current applied definitions. They remain read-only B005-owned dependencies and are not a reason for B002 to duplicate pages or bodies.

## Evidence Standards Used

- IDA MCP: fresh `idb_list`, `server_health`, `lookup_funcs`, `get_bytes`, `decompile`, `disasm`, `analyze_function`, `analyze_component`, `xrefs_to`, rendered-listing searches, and caller/callee evidence using database `9b0396a3`. The full target pass used streamable HTTP session `1f386679-d9f6-406c-a82a-c93e5698ed69`; bounded target recheck used `2acd11cb-2054-419b-ad2e-7ba428883ebc`; the earlier dependency-consumption pass used `17b2029b-e88b-4cf0-b9c3-efc1385e666a`; final health and bounded real-UID rechecks used sessions `b1bdab9a-78d8-426e-bb0a-b966669d164a` and `6394e934-3d01-4a2d-904a-bbaa506515e3`. All returned the same database and exact word/autoscroll evidence. HTTP session IDs are evidence-time transport observations, not durable availability claims.
- Binary evidence: exact function/table/successor bytes, local PE SHA256 ranges, prologue/epilogue cleanup, 52-block CFG, local switch destinations, vtable bytes, global xrefs, helper bodies, and field-offset searches.
- Documentation evidence: current by-memory/by-class/by-file/by-global pages, executed reports, active reports/goals, generated source/tracker, manual coverage, and lease ledger.
- Negative evidence: zero ordinary target callers, no helper-start callers where vtable/internal routing explains liveness, no external table targets, no source strings naming the private helpers, no separate source-file cluster, and no exact-range prior report.
- The evidence ladder is sufficient for a human first draft because every branch and externally visible side effect is direct. Confidence is below 95 only because stripped private lexical names cannot be original-proof.

## Evidence Checked

- IDA MCP/manual checks: final fresh `idb_list` returned sole active NexusTK database `9b0396a3`, worker PID 15732; `server_health` returned `ok` with auto-analysis, Hex-Rays, and string cache ready; bounded `get_bytes` returned target entry `55 8b ec 83 ec 20 53 56 57 8b f9 f6 87 5c 01 00`; `lookup_funcs` returned `sub_590DE0` size `0x38c`. Earlier bounded reads at table/successor and full target analysis returned 284 instructions, 52 blocks, complexity 26, 13 callees, no ordinary callers, and one data xref; helper decompilation and tail disassembly verified signatures/`retn` widths; vtable bytes and anchor xrefs were read directly.
- Raw/local PE checks: method `[0x00590de0,0x0059116c)` is 908 bytes SHA256 `5AD5AA067995784C8F00C242FD4F421A6B2FC4B82AA1118D45C4A199C0CE55D8`; table is 20 bytes SHA256 `728CCDB1D78A7BEE58F538D33BD1D57ADF7519358CC75BAE6202FA9F74F1FEFC`; complete target is 928 bytes SHA256 `740CB7C5CA014C5AD9132B172241DB8514575CE74BEE6883D9E7753D6754D0B6`; predecessor stub/padding SHA256 is `88B7F14AC2AD80B818129C3BE7B37B8DAB9E56FB55ABC83ECE779D1C5F8AC13D`; successor head SHA256 is `58851088882A30F9FFF3553E2D71E537E6C9EC364DD3F9763366DFAB87C83343`.
- Docs checked: target, UID0001JM, UID0000EO, UID0000ON, UID000303, UID0000EN, UID00040S, Event class/file, InputMan class/file/memory, ScrollablePane, RectBounds, List, `g_useEpfAssets`, TextEdit read-only/vtable pages, current generated TextEditPane.cpp, tracker, and manual coverage.
- Historical roots and exact terms are recorded under Supporting Research. The search returned nine central executed matches, zero legacy/archive matches, zero B001/B003 active matches, one B004 support match, and one B005 support match; every relevant match listed there was opened and classified, and no exact-header/direct-range report precedes this artifact.
- Current overlap checks: B001-B005 top goals/reports and lease ledger were read at the final-read boundary. B004's terminal UID0003N0 artifact and current ordinary pages supply the durable draw/refresh union. B005 UID00030F is executed under supervisor command `000000015329`; its centralized post-lifecycle artifact SHA256 `C6B14C8772182E53D454E4011DD231D9EDB9744F94040663E592D0AFFC0FCAB4` and current ordinary/generated pages supply the adjacent key and six-child UID0001JS union. B003's Event work is externally completed current support. B002 held and holds no lease.
- Intentionally skipped: no IDA mutation, source import, validator, generated refresh, ordinary edit, coverage edit, tracker edit, or lifecycle command is permitted in report-only phase.

## Claim And Incorporation Ledger

| Claim ID | Claim | Confidence | Evidence | Destination doc/section | Action | Verification state |
| --- | --- | --- | --- | --- | --- | --- |
| C01 | Exact target is method `[0x00590de0,0x0059116c)` plus local switch table `[0x0059116c,0x00591180)`. | very strong | lookup, bytes, table pointers, successor | D1 target / range sections | incorporate | applied |
| C02 | Method/table/combined SHA256 values and predecessor/successor boundaries are exact. | very strong | local PE extraction and MCP reads | D1 target evidence | incorporate | applied |
| C03 | `0x0062dff4 -> 0x00590de0` is primary vtable `+0x60`; no ordinary caller is required for liveness. | very strong | vtable bytes/xref/current slot docs | D1, D2 | incorporate | applied |
| C04 | Source ABI is `bool TextEditPane::OnMouseEvent(Event *event)` with AL result and `retn 4`. | very strong | prologue/epilogue, Event/vtable siblings | D1, D2 | incorporate | applied |
| C05 | Inactive `kTextEditInteractive` state returns true before payload reads. | very strong | entry `test +0x15c,0x80` and branch | D1 | incorporate | applied |
| C06 | Event pointer payload is y `+8`, x `+0xc`, modifiers `+0x10`, time `+0x18`; Event types 0-4 match current enum. | very strong | target loads and current Event formal | D1, D2; Event verify-only | already-present | already-present |
| C07 | Cursor move requires mouse capture, updates drag selection, autoscrolls, and returns true; no capture returns false. | very strong | case-0 CFG and capture helper bodies | D1 | incorporate | applied |
| C08 | Left down/double click require `PointInRect(y,x,&m_contentRect)` and otherwise return false. | very strong | shared case entry | D1 | incorporate | applied |
| C09 | Repeat is strict `< oldTime+500` and same text offset; then time/index/hit-part fields are updated. | very strong | unsigned branch and writes +160/+164/+166 | D1, D2 | incorporate | applied |
| C10 | One-character selected inline object receives `(event,repeatedClick,currentMessageTime)` through vtable slot +0x10 with observed minimal guards. | very strong | format-run/table walk and virtual call | D1, D3, D4 | incorporate | applied |
| C11 | Shift extends from selection end when reversed, otherwise selection start. | very strong | modifier bit 4 and +158 branch | D1, D2 | incorporate | applied |
| C12 | Repeated click increments +167; value <=1 chooses word range and >1 chooses line range; non-repeat resets count and anchor. | very strong | exact branches/callees | D1, D2 | incorporate | applied |
| C13 | `s_mouseSelectionAnchor` is a zero-initialized static short with all eight xrefs inside UID00030E. | very strong | UID000303 bytes/xrefs/current formal | D1; UID000303 verify-only | already-present | already-present |
| C14 | `CompleteImeComposition()` is standalone InputMan.cpp support and is called before down-only capture. | very strong | helper decompile, executed B001, call order | D1; InputMan verify-only | incorporate | applied |
| C15 | Left-down alone captures mouse; double-click does not issue another capture call. | very strong | post-composition event-type compare | D1 | incorporate | applied |
| C16 | Click handling deliberately repeats hit testing after composition/capture before setting final range. | very strong | two `0x58f690` callsites | D1 | incorporate | applied |
| C17 | Left-up releases capture if owned, then returns `g_useEpfAssets != 1`; no normalization to unconditional true. | very strong | case-3 CFG and global compare | D1 | incorporate | applied |
| C18 | Right-down clears selection to `(0,0)` and returns true; unknown event types return false. | very strong | case-4/default CFG | D1 | incorporate | applied |
| C19 | `GetTextOffsetAtPoint(y,x,signed char*)` is the strongest source name/signature for `0x0058f690`. | strong | helper decompile/callback/ABI | D2; UID0001JM/UID0000ON prose | incorporate | applied |
| C20 | `GetLineIndexForTextOffset` and `GetFormatRunIndexForTextOffset` are exact binary-search helper roles. | strong | direct helper decompilation/disassembly | D2; UID0001JM/UID0000ON prose | incorporate | applied |
| C21 | Member `GetWordSelectionRange` at `0x0058f9a0` and `GetLineSelectionRange` at `0x0058fa00` preserve exact four-argument ABI, but UID00030E's later repeat-adjustment calls use B005's distinct file-local five-argument primitive directly; the line helper intentionally ignores hit part. | very strong | 58f9a0/58fa00 bodies, target callsites, B005 D11 | D1, D2; UID0001JM/UID0000ON prose | incorporate | applied |
| C22 | `AutoScrollSelectionToPoint` is exact `bool (int y,int x)`, not current void `(x,y)`; both UID00030E callers ignore its always-true return. | certain | two callsites, complete helper CFG, B005 D12 | D1, D2; B005 child dependency | reject-stale | applied |
| C23 | The corrected `+0x158..+0x173` field layout is live and source-safe; old drag/mouse-mode packing is contradicted. | very strong | constructor, target, field-use searches, helpers | D2; class/file/aggregate prose | reject-stale | applied |
| C24 | `TextEditObject::OnAction(int,int,int)` is superseded by `OnMouseEvent(Event*,bool,unsigned int)` from its only semantic caller. | strong | target virtual call, two vtable cells, no-op body | D3, D4 | reject-stale | applied |
| C25 | Local jump table is compiler-owned and must not receive a source/data child or handwritten table. | very strong | all five entries point into target switch | D1 target prose | reject-invalid | excluded-with-reason |
| C26 | UID00030E owner/emitter UID0000EO and file UID0000ON are correct; TextBoxPane/Event/InputMan/new file are rejected owners. | very strong | class/vtable/helper/file neighborhood | D1, D2, D6-D7 prose | already-present | already-present |
| C27 | Target should move `86/90 -> 92/94`, retaining true/owner/emitter/blank position/Nested 0. | strong | blocker closure and direct behavior proof | D1 / coverage | incorporate | applied |
| C28 | Earlier blank-body, `int` return, `-1` anchor initializer, raw offsets, and provisional names remain labeled historical, not silently deleted. | very strong | current and executed docs | target/support Changes/history | historicalize | applied |
| C29 | No null/format-index/time-overflow/safe-clamp/event-pointer guards, compiler ABI source, or normalized release return may be invented. | very strong | negative CFG/disassembly | D1 / negative evidence | reject-invalid | excluded-with-reason |
| C30 | Exact six-action manual coverage handoff, generated assertions over the applied B004/B005 union, validators, and zero-lease proof are callback obligations; B002 does not edit manual/generated state. | very strong | workflow/current files/archives/lease ledger | coverage/checklist/results | incorporate | applied |
| C31 | B004's applied UID0004TC/TD/TE/TF helper union is required no-loss support and must remain once each. | very strong | current ordinary docs, executed B004 command 15177, generated command 15346 | D2, D5-D7 | already-present | already-present |
| C32 | B005's executed key/key-up/clipboard/navigation/wrap/word/autoscroll/composition union, compiler-natural alignment, and semantic `m_unusedClickState +0x168` disposition are current applied no-loss support. | certain | terminal B005 archive SHA C6B14C87...CAB4, current ordinary/generated pages, live MCP comparison | D1-D2, D6-D7, read-only B005 UID0004U9/UID0004UA dependencies | already-present | already-present |
| C33 | UID0004TC's historical `m_dragSelectionActive` token denoted the same +0x158 direction bit directly proven here as `m_selectionReversed`; current UID0004TC already carries the corrected token and exact D5 body. | very strong | current UID0004TC, OnMouse/SetSelectionRange offset uses, D5 parity | D5/UID0004TC verify-only | already-present | already-present |
| C34 | B004 and B005 ordinary lanes are externally applied and stable; B002 callback must reread that complete union and apply only the remaining target/TextEditObject/aggregate/file delta without loss. | very strong | current archives, ordinary hashes, generated command 15346, lease ledger | support plan/checklist | incorporate | applied |
| C35 | B005 exclusively owns the six-child UID0001JS split and registration; B002 must not create a UID0001JS direct report or either consumed helper page. | certain | supervisor coordination/B005 report | support plan/checklist | reject-invalid | excluded-with-reason |
| C36 | File-local `FindWordBoundary` is exact `[0x00594b50,0x00594cb0)`, 352 bytes, SHA256 `33798227...2978`, `__stdcall`, five arguments, and writes `TextEditRange`. | certain | fresh bytes/decompile/xrefs/B005 D11 | D1-D2/external B005 child | incorporate | applied |
| C37 | The word primitive groups only space/tab/CR/LF, has five callsites in three functions, and is distinct from the `0x0058f9a0` member wrapper. | certain | complete CFG/callers/B005 C66-C68 | D1-D2/support prose | incorporate | applied |
| C38 | B005-owned `AutoScrollSelectionToPoint` is exact `[0x00594cb0,0x00594e12)`, 354 bytes, SHA256 `303B3931...1FB2`, and returns true on every path. | certain | fresh bytes/decompile/xrefs/B005 D12 | D1-D2/external B005 child | incorporate | applied |
| C39 | Autoscroll gates on editor flag bit zero and selection visibility, clamps each pixel delta to 48, uses axes 1/0, and converts vertical pixels with line height. | certain | complete CFG/callees/B005 D12 | D1-D2/support prose | incorporate | applied |
| C40 | UID00030E directly calls the file-local word primitive twice and bool autoscroll twice; declarations alone are not linkable source closure. | certain | target decompile callsites 590fee/5910cd/591041/591120 | D1/generated assertions | reject-stale | applied |
| C41 | B002 target D1 consumes B005 UID0004U9 `FindWordBoundary` and UID0004UA `AutoScrollSelectionToPoint` without copying their managed bodies or creating duplicate pages. | certain | terminal B005 archive, real current pages, ownership/emitter rules | support plan/checklist | already-present | already-present |
| C42 | UID0001JS is the applied B005-owned `90/92` blank-formal split index; its six exact children emit independently and its residual non-target source pockets do not authorize a duplicate aggregate body. | certain | terminal B005 inventory/formals/current UID0001JS | UID0001JS verify/coordination | already-present | already-present |
| C43 | Executed B004 UID0003N0 archive command 15177 is the durable ordinary base; earlier active-path/Gate2 wording is historical. | certain | executed archive/current pages | current state/support plan | historicalize | applied |
| C44 | Waited validator command `000000015346`, timestamp `2026-07-20T13:31:37-04:00`, produced the callback's time-bounded generated/tracker epoch: tracker SHA256 `8DD00EFBEB8D924375C940CB55B000E9E938F65111308ACAC87ABEE92FB0A4F3`, 1,530,688 bytes/6,205 lines, and TextEditPane.cpp SHA256 `C7565637EDC6BA9CF10F7635234EDE2F028C22FC5F449231DFED9C20BA83C64E`, 62,112 bytes/1,824 lines. Commands 15338/15333/15329 and their hashes remain explicit historical epochs. | certain | current tracker/generated headers and readback, executed B003/B005 archives, current manual roots | Target/current state/results/checklist | historicalize | applied |

## Positive Evidence Summary

- Direct facts: exact method/table boundaries and hashes; one primary-vtable data xref; AL/bool return; 52 blocks and complexity 26; complete five-case CFG; accepted Event offsets/types; exact helper calls; eight anchor xrefs; exact click fields; direct `g_useEpfAssets` branch; and no ordinary callers.
- Corroborating docs: current Event formal closes the record ABI; current ScrollablePane names `m_contentRect`; current pane-event reports close capture helper names; executed InputMan closes `CompleteImeComposition`; current TextEdit tables close record/list types; UID000303 closes static-anchor storage and initialization.
- Strongest inference chain: helper bodies plus their target argument order and state use support stable descriptive names. These names allow source-shaped C++ without changing behavior or inventing new binary functions.

## IDA MCP Facts

- Function/range facts: `sub_590DE0`, size `0x38c` / 908, 284 instructions, 52 basic blocks, complexity 26; method body ends at `0x0059116c`; successor `sub_591180` begins exactly at `0x00591180`.
- Data/table/padding facts: table bytes are `51 10 59 00 1b 0e 59 00 1b 0e 59 00 30 11 59 00 58 11 59 00`; cases are 0,1,2,3,4. B005 independently resolves predecessor `[0x00590dc5,0x00590de0)` as eleven CC bytes, source-authored false-return key-up virtual `[0x00590dd0,0x00590dd5)`, then eleven CC bytes; none belongs to UID00030E.
- Xref facts: target has one data xref at `0x0062dff4`; no ordinary code callers; `s_mouseSelectionAnchor` has eight data xrefs, all in target; `0x00594f20` has two vtable data xrefs at `0x0062e058` and `0x0062e134`.
- Vtable/global/type facts: primary slot `+0x60`; `g_useEpfAssets` at `0x0066da97`; anchor at `0x0069be04`; current Event pointer payload exact; TextEdit table pointers at `+0x134/+0x138/+0x13c/+0x140` use 2/16/16/4-byte records.
- Dependency helper facts: the earlier complete session `17b2029b-e88b-4cf0-b9c3-efc1385e666a` and final health/bounded sessions `b1bdab9a-78d8-426e-bb0a-b966669d164a` / `6394e934-3d01-4a2d-904a-bbaa506515e3` rediscovered database `9b0396a3`, worker PID 15732, health `ok`, and exact B005 ranges. `0x00594b50` is 352 bytes, 141 instructions, 43 blocks/complexity 26, five callsites in three callers, SHA256 `33798227F960F8091AFB961D915136FD0275ED6D530360F825422AED0E372978`, and `retn 0x14`; `0x00594cb0` is 354 bytes, 128 instructions, 29 blocks/complexity 20, two UID00030E callsites, SHA256 `303B3931B327517E97504D8C56CD9FD7450974CAE6BE2D4927A4E87C29011FB2`, and `retn 8` with AL set true at both exits.
- Dependency source facts: direct calls at `0x00590fee` and `0x005910cd` pass UTF-16 storage, text length, caret, hit part converted to bool, and a two-short range to the file-local primitive; calls at `0x00591041` and `0x00591120` pass `(y,x)` to autoscroll and ignore its bool result. These exact B005 D11/D12 bodies are required generated definitions, not declarations or independent future debt.
- Negative IDA facts: no external table target, no separate case functions, no target EH/cookie frame, no ordinary caller, no null event/list/table checks, no format-index sentinel guard in the selected-object route, and no direct `g_pInputMan` access in target.

## Function / Child Inventory

| Range / Item | UID / Path | Role | Reconstructable | Direct Parent | Score | Status |
| --- | --- | --- | --- | --- | --- | --- |
| `0x00590de0-0x0059116c` | UID00030E target | `TextEditPane::OnMouseEvent` | true | UID0000EO | `86/90 -> 92/94` | source body proposed |
| `0x0059116c-0x00591180` | inside UID00030E | local switch table | compiler-emitted by source switch | UID00030E | covered | no handwritten source |
| `0x005909f0-0x00590dc5` | UID00030F | adjacent key handler | true | UID0000EO | current `92/94` | B005 applied/executed; read-only to B002 |
| `0x00590dc5-0x00590dd0` | UID0000VN ignored | key/key-up alignment | false | UID0001JM | `100` | excluded from target |
| `0x00590dd0-0x00590dd5` | UID0004TZ | `TextEditPane::OnKeyUp` false virtual | true | UID0000EO | current `92/94` | B005 applied/executed; excluded from target |
| `0x00590dd5-0x00590de0` | UID0000VN ignored | key-up/mouse alignment | false | UID0001JM | `100` | excluded from target |
| `0x00591180...` | successor in UID0001JM | next TextEditPane helper | true/raw family | UID0000EO | existing | excluded from target |
| `0x0058f0d0` | inside UID0001JM | line-index binary search | true source helper | UID0000EO | aggregate-held | named support |
| `0x0058f1b0` | inside UID0001JM | format-run binary search | true source helper | UID0000EO | aggregate-held | named support |
| `0x0058f2a0` | inside UID0001JM | `SetSelectionRange` | true source helper | UID0000EO | aggregate-held | accepted support |
| `0x0058f690` | inside UID0001JM | text-point hit test | true source helper | UID0000EO | aggregate-held | named support |
| `0x0058f9a0` | inside UID0001JM | word selection range | true source helper | UID0000EO | aggregate-held | named support |
| `0x0058fa00` | inside UID0001JM | line selection range | true source helper | UID0000EO | aggregate-held | named support |
| `0x00594b50-0x00594cb0` | UID0004U9 `by-memory/0x00594b50-0x00594cb0.FindWordBoundary.md` | file-local `__stdcall FindWordBoundary` | true | UID0000ON | current `92/94` | B005-applied D11 body; B002 consumes contract/UID only |
| `0x00594cb0-0x00594e12` | UID0004UA `by-memory/0x00594cb0-0x00594e12.TextEditPaneAutoScrollSelectionToPoint.md` | `bool TextEditPane::AutoScrollSelectionToPoint(y,x)` | true | UID0000EO | current `92/94` | B005-applied D12 body; B002 consumes contract/UID only |
| `0x00594040-0x00594e60` | UID0001JS | six-child split index plus bounded residual source debt | true, blank parent formal | UID0000ON | current `90/92` | B005-applied parent/children; no B002 report/body |
| `0x00594f20-0x00594f23` | UID00040S submethod | empty TextEditObject click hook | true source-empty virtual | UID0000EN | `87/90 -> 89/92` | semantic rename proposed |
| `0x00591400-0x005914c4` | UID0004TC | `RefreshTextRange` | true source method | UID0000EO | `92/94` unchanged | B004 body preserved; +0x158 token sync proposed |
| `0x0069be04-0x0069be06` | UID000303 | module static selection anchor | true | UID0000ON | `87/91` | already source-bearing |

## Direct Xref / Caller Inventory

| Address / Item | Xref / Caller / Callee | Meaning |
| --- | --- | --- |
| `0x0062dff4` | target pointer | primary vtable `+0x60` liveness |
| target ordinary callers | none | expected virtual-only dispatch |
| `0x00590e30` | `PointInRect` | left-click/double-click content hit gate |
| `0x00590e40`, `0x00590f8f`, `0x0059106e` | `GetTextOffsetAtPoint` | initial click, post-composition click, drag move |
| `0x00590ea1` | format-run index helper | one-character inline-object lookup |
| `0x00590ef5` | TextEditObject slot `+0x10` | inline object mouse notification |
| `0x00590f2f` | word selection helper | first repeat expansion |
| `0x00590f28` | line selection helper | later repeat expansion |
| `0x00590fee`, `0x005910cd` | B005 file-local `::FindWordBoundary` | direct later word-range expansion in click/drag paths |
| `0x00590f6b` | `CompleteImeComposition` | commits IME state before capture/range update |
| `0x00590f78` | `CaptureMouse` | left-button-down only |
| `0x0059113b` | `ReleaseMouseCapture` | left-button-up when owned |
| `0x00591115`, `0x00591036`, `0x0059115c` | `SetSelectionRange` | drag/click/right-button selection updates |
| `0x00591120`, `0x00591041` | `AutoScrollSelectionToPoint(y,x)` | drag/click edge scrolling |
| `0x0069be04` eight refs | six writes/two reads in target | shared source static anchor only |

## Documentation Evidence And IDA Status

- Evidence-time/pre-callback target state accurately recorded the method/table split, vtable route, anchor, broad behavior, owner, blank body, naming blocker, and `86/90` score. Those blank-emitter facts are historical. Current UID00030E is `92/94`, has complete Destination 1, and hashes to `4042553F82F90C28026C03196735DCFC6A7745467CAE4ADDF0F7B001D9FE8856`, 18,321 bytes/261 lines.
- Current UID0000EO SHA256 `471C8B493EEB6B150E490D7D03DE44D822DD142D1D777CB67557F883B7B8752D`, 83,532 bytes/666 lines, remains read-only and contains the complete constructor/destructor/serialization/OnDraw/callback/table/static union, executed B004 UID0004TC/TD/TE/TF support, and executed B005 key/key-up/clipboard/six-child UID0001JS union. Destination 2 is whitespace-normalized source-equal. Current UID0000ON SHA256 `7972CD02AC5B47776A5D110C45065B715089DCDF00475BE8005385E6D66AB50C`, 99,212 bytes/479 lines, adds the accepted UID00030E provenance/source/dependency/compiler prose without duplicating target or B005 helper bodies.
- Current UID0001JM SHA256 `BB1DAD3000232EBE1BA5A187B67320E3F8F00EC84A28EB5B7BFA696C01C56314`, 41,780 bytes/218 lines, remains the `87/91` blank-formal split aggregate and now records source-ready UID00030E closure over the complete executed B004/B005 union without changing its non-emitting disposition.
- Final-read UID0004TC SHA256 `803DFFF6C97A89CF4C8806C72FAAF8010A3DB5AF51F2E08F011ECC2A1DAC62DD`, 9,424/111, is `92/94` and already uses `m_selectionReversed` in its complete body. Destination 5 is byte-equal to current formal source and is therefore verify-only. UID0004TD/TE/TF are same-or-greater and read-only to B002.
- Current UID0000EN/UID00040S preserve the payload-oriented TextEditObject layout and two empty virtual hooks while replacing only the historical generic second-hook spelling. UID0000EN is `90/93`, SHA256 `5F0C88A900D51FFD147D6022EEC65C72F2FC491C13CBDECCF2B391E4A09A5AB0`, 19,532 bytes/176 lines; UID00040S is `89/92`, SHA256 `5BA40E9616FE630B5AAACE95CE46A49C07EF4BFBB9A4FD08F85245D6F0DBF4E1`, 10,340/133.
- Final-read unchanged dependency snapshots are UID0001JS `2ADBACE12B942BAC1616315F7038BCBA8464A92A927BDD6A793CBD5D683A1B9B`, 28,420/206; UID0004U9 `C6B4D7106142250A0EB839DF88D3CBD2AF22404DCCA4EC4D3A83EF91E8BDA667`, 6,242/116; UID0004UA `933AD3AA695207246FB83FC8B32A2EC4D72B14D033FFDDB00C69AE7475FE77C2`, 6,246/108; and UID000303 `970A71AA1E557791945B391B48C68D46C3860866BE2E1E4E183B87467D386D41`, 7,242/81. Event class/file remain `990F3E969A8A697868C29DE05FD57140502D78B1373C1F3BA0D9056BD2DFB97A` / `032A30AEEE73730E6ED09515A8B60651C7E97491F07506F5510159B9E348E96C`; InputMan class/file remain `B5C67449C305CEE8120DACD9505630A2EA994DEC7BD380D8C48C5EA17F09F301` / `B1C5EF85699445E675F845E811489793B39EEA86BD93F3003F37FC150D083EDA`; `g_useEpfAssets` remains `63105269A3F90B2E11AAD2B457D4A35DA4EC8FEAEBC4B8A3E86120882DA21E10`. These are time-bounded evidence, not locks on later unrelated work.
- Event, InputMan, anchor, and global support were reread as source-ready and same-or-greater; no ordinary support edit was required. Destination 1 now supplies compile-visible `CompleteImeComposition` and `g_useEpfAssets` declarations in the valid target emitter while by-file placement remains prose-only.
- Historical generated command 15325/SHA `84020715...951BC6` correctly showed one target Empty Emitter Marker and zero target definitions before this callback. Current waited command 15346/SHA `C7565637...3C64E`, 62,112 bytes/1,824 lines, removes that marker, emits one target method, preserves the complete B004/B005 union, and satisfies every structural assertion recorded in Current Target State.

## Ranked Ownership Analysis

### 1. TextEditPane / TextEditPane.cpp

- Evidence for: primary TextEditPane vtable entry; direct access to TextEditPane tables, selection fields, text-area bounds, flags, and static anchor; contiguous placement between TextEditPane OnKeyEvent and lower TextEditPane helpers; all callees are Pane/TextEditPane/InputMan support.
- Evidence against: exact original private helper/member spellings are stripped.
- Decision: accepted direct class owner UID0000EO and file owner UID0000ON. Lexical uncertainty does not weaken semantic ownership.

### 2. TextBoxPane or another derived text pane

- Evidence for: derived panes inherit or override nearby TextEdit virtuals.
- Evidence against: target pointer is in the TextEditPane primary table itself; body uses only base TextEdit state and no derived fields; derived tables may inherit this slot.
- Decision: rejected as target owner; derived uses are inherited consumer evidence.

### 3. Event.cpp, InputMan.cpp, or a new mouse-selection module

- Evidence for: method consumes Event and calls an InputMan helper.
- Evidence against: neither support subsystem owns TextEdit tables/selection state or vtable; one consumed helper does not move a member method; the contiguous source neighborhood already supports TextEditPane.cpp.
- Decision: rejected. Event/InputMan remain support dependencies only; no new source file is justified.

### Proposed new file/grouping, if applicable

- Not applicable. No new file/grouping is proposed.
- The likely full contents remain the existing TextEditPane.cpp family, including TextEditPane, TextEditObject/TextEditScrap/EPFTextEditObject support, callbacks, module statics, and exact child methods.
- Five case blocks and the local table are rejected as separate child/file groupings.

## Source Placement

- Recommended placement: `NexusTK/ui/controls/TextEditPane.cpp`, as a protected virtual `TextEditPane` definition emitted from UID00030E through UID0000EO/UID0000ON.
- Header/source placement: `TextEditPane` and `TextEditObject` declarations remain in their complete class formals. Destination 2 carries B005's exact `TextEditRange`, file-local `static void __stdcall FindWordBoundary(...)` prototype, distinct member wrapper declaration, and bool `(y,x)` autoscroll declaration. B005 exclusively owns the later D11 file-local body and D12 member body in TextEditPane.cpp; UID00030E calls them but does not define or register them. Current cross-TU compile visibility for unrelated support remains guaranteed by placing `BOOL __stdcall CompleteImeComposition();` and `extern bool g_useEpfAssets;` directly before UID00030E's definition. UID0004TC remains an ordinary TextEditPane.cpp member body; Destination 5 changes no linkage or source order.
- The target-local declarations do not create duplicate definitions. UID00018E/InputMan remains the sole `CompleteImeComposition` definition; UID0000SW remains the sole `g_useEpfAssets` definition; B005 UID0004U9 and UID0004UA remain the sole helper definition emitters.
- Rejected placements: Event.cpp, InputMan.cpp, TextBoxPane.cpp, standalone MouseSelection.cpp, a by-file formal block, and aggregate UID0001JM C++.
- Remaining uncertainty: only probable original header filename and exact private lexical spellings. B005's validator-issued identities are now fixed as UID0004U9 and UID0004UA; they close the direct helper graph without creating any B002 page-creation task.

## Range / Split / Padding / Reclassification Analysis

- Exact target range stays `[0x00590de0,0x00591180)`.
- Exact method body is `[0x00590de0,0x0059116c)`. It has a conventional prologue, `retn 4`, and no EH/cookie frame.
- Exact local table is `[0x0059116c,0x00591180)`. The source `switch(event->m_type)` regenerates this table; it is not a source-authored array and must not be emitted separately.
- Predecessor `[0x00590dc5,0x00590de0)` is outside UID00030E and consists exactly of 11 CC bytes, B005-owned source-authored `OnKeyUp` `[0x00590dd0,0x00590dd5)`, and 11 CC bytes. The two padding spans each hash to `3682C0A62515050101266CC639BF81F5D8C5395F49E7DA93FCC22603018E0943`; the five-byte method is `32 c0 c2 04 00`, SHA256 `CC0E3CB106EB0FDEC984D44A563D98C3DA80700BBB8D2BE4E66EBD54A9919626`. Their combined 27-byte SHA256 remains `88B7F14AC2AD80B818129C3BE7B37B8DAB9E56FB55ABC83ECE779D1C5F8AC13D`. Successor source begins at `0x00591180`; no byte is absorbed from either side.
- Parent UID0001JM remains a non-emitting split/source index with blank formal C++. This report does not duplicate its whole range or create helper children. B004's UID0004TC/TD/TE/TF children and B005's applied UID0004TZ key-up, UID0004U1 clipboard reader, six UID0001JS children, and D2-D12 bodies remain independently owned. UID0001JS stays B005's applied `90/92` blank-formal split index with exact residual source debt; B002 consumes only current UID0004U9/UID0004UA contracts.
- UID00030E needs no rename/path migration: its current path and UID are source-correct.

## Negative Evidence Summary

- Zero ordinary callers do not make the method dead: the primary-vtable data xref is direct liveness.
- The local jump table is not a raw helper or static source table; every entry is an internal case label.
- InputMan does not own the method merely because it supplies composition finalization.
- Event does not own the method merely because its payload controls dispatch.
- TextBoxPane and other derived panes do not own an inherited base implementation.
- There is no evidence for `m_mouseMode` at `+0x160`, `m_dragSelectionActive` as a distinct state at `+0x158`, `(x,y)` autoscroll order, `int` return, `s_mouseSelectionAnchor=-1`, or generic integer `OnAction` after current reanalysis. B004 UID0004TC's `m_dragSelectionActive` token is explicitly historicalized as a prior spelling for the same +0x158 active-endpoint/direction bit, not retained as a second member.
- The binary has no null event pointer guard, no table/list pointer guard, no format-index sentinel guard in the selected-object path, no click-time overflow hardening, no endpoint widening, and no unconditional true left-up return. Adding those would change behavior.
- Compiler artifacts excluded from handwritten source: vtable dispatch syntax, jump-table array/addresses, AL/retn ABI, raw List vtable calls, and pointer arithmetic over members.

## IDA Rename / Type / Comment Recommendations

- Read-only recommendation only; this report does not mutate IDA.
- `sub_590DE0` -> `TextEditPane::OnMouseEvent(Event *)`, return `bool`, one Event pointer argument.
- `sub_58F690` -> `TextEditPane::GetTextOffsetAtPoint(int y,int x,signed char *hitPart) const`.
- `sub_58F0D0` -> `TextEditPane::GetLineIndexForTextOffset(short) const`.
- `sub_58F1B0` -> `TextEditPane::GetFormatRunIndexForTextOffset(short) const`.
- `sub_58F9A0` -> `TextEditPane::GetWordSelectionRange(short,signed char,short *,short *) const`, source `void` because EAX is not consumed.
- `sub_58FA00` -> `TextEditPane::GetLineSelectionRange(short,signed char,short *,short *) const`, source `void`; second argument is ABI-real but body-unused.
- `sub_594B50` -> file-local `static void __stdcall FindWordBoundary(const wchar_t *,short,short,bool,TextEditRange *)`; keep distinct from the earlier member wrapper and assign the body/page only through B005.
- `sub_594CB0` -> `bool TextEditPane::AutoScrollSelectionToPoint(int y,int x)`; assign the body/page only through B005.
- `sub_4E9490` -> `CompleteImeComposition`, preserving current accepted `BOOL __stdcall` source declaration.
- `sub_5449D0/sub_5449F0/sub_544A00` -> inherited `CaptureMouse`, `ReleaseMouseCapture`, `HasMouseCapture`.
- `nullsub_59` / `0x00594f20` -> `TextEditObject::OnMouseEvent(Event *,bool,unsigned int)`; preserve source-empty body and compiler-generated vtable dispatch.
- Comments should record table ownership, strict 500-ms comparison, left-up asset-mode return asymmetry, second hit-test pass, and inferred/private spelling confidence. No IDA edits are requested.

## First-Draft C++ Recommendation

- Eligible for draft C++: yes. Five destination-specific formal blocks follow. No C++ appears elsewhere in this report.
- Destination 1: [UID:00030E] target, exact formal insertion.

*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
extern bool g_useEpfAssets;
BOOL __stdcall CompleteImeComposition();

namespace {
const unsigned int kTextEditRepeatedClickMilliseconds = 500;
const signed char kTextHitAfterCharacter = 2;
}

bool TextEditPane::OnMouseEvent(Event *event)
{
    if ((m_editorFlags & kTextEditInteractive) == 0)
        return true;

    const int y = event->m_payload.m_pointer.m_y;
    const int x = event->m_payload.m_pointer.m_x;

    switch (event->m_type) {
    case kEventCursorMove:
    {
        if (!HasMouseCapture())
            return false;

        signed char hitPart;
        short textOffset = GetTextOffsetAtPoint(y, x, &hitPart);
        if (m_repeatClickCount != 0) {
            TextEditRange range;
            if (m_repeatClickCount <= 1) {
                ::FindWordBoundary(
                    static_cast<const wchar_t *>(m_textStorage->GetData(0)),
                    GetTextLength(),
                    textOffset,
                    hitPart != 0,
                    &range);
            } else {
                GetLineSelectionRange(textOffset,
                                      hitPart,
                                      &range.start,
                                      &range.end);
            }

            if (m_savedSelectionStart >= textOffset) {
                textOffset = range.start;
                s_mouseSelectionAnchor = m_savedSelectionEnd;
            } else {
                textOffset = range.end;
                s_mouseSelectionAnchor = m_savedSelectionStart;
            }
        } else if (hitPart == kTextHitAfterCharacter) {
            ++textOffset;
        }

        SetSelectionRange(s_mouseSelectionAnchor, textOffset);
        AutoScrollSelectionToPoint(y, x);
        return true;
    }

    case kEventLeftButtonDown:
    case kEventLeftButtonDoubleClick:
    {
        if (!PointInRect(y, x, &m_contentRect))
            return false;

        signed char hitPart;
        const short clickedOffset = GetTextOffsetAtPoint(y, x, &hitPart);
        const unsigned int messageTime =
            event->m_payload.m_pointer.m_messageTime;
        const bool repeatedClick =
            messageTime < m_lastClickTime + kTextEditRepeatedClickMilliseconds &&
            clickedOffset == m_lastClickTextOffset;

        m_lastClickTime = messageTime;
        m_lastClickTextOffset = clickedOffset;
        m_lastClickHitPart = hitPart;

        if (m_selectionEnd - m_selectionStart == 1) {
            const short runIndex =
                GetFormatRunIndexForTextOffset(m_selectionStart);
            TextEditFormatRun *run = static_cast<TextEditFormatRun *>(
                m_formatRuns->GetElementAt(runIndex));
            TextEditFormatRecord *record = static_cast<TextEditFormatRecord *>(
                m_formatTable->GetElementAt(run->formatIndex));
            TextEditObject *object = record->format.object;
            if (object != NULL &&
                m_selectionStart <= clickedOffset &&
                clickedOffset < m_selectionEnd) {
                object->OnMouseEvent(event, repeatedClick, m_lastClickTime);
            }
        }

        if ((event->m_payload.m_pointer.m_modifiers & kEventModifierShift) != 0) {
            s_mouseSelectionAnchor =
                m_selectionReversed ? m_selectionEnd : m_selectionStart;
        } else if (repeatedClick) {
            ++m_repeatClickCount;
            if (m_repeatClickCount <= 1) {
                GetWordSelectionRange(clickedOffset,
                                      m_lastClickHitPart,
                                      &m_savedSelectionStart,
                                      &m_savedSelectionEnd);
            } else {
                GetLineSelectionRange(clickedOffset,
                                      m_lastClickHitPart,
                                      &m_savedSelectionStart,
                                      &m_savedSelectionEnd);
            }
        } else {
            m_repeatClickCount = 0;
            s_mouseSelectionAnchor = clickedOffset;
        }

        CompleteImeComposition();
        if (event->m_type == kEventLeftButtonDown)
            CaptureMouse();

        signed char currentHitPart;
        short currentOffset = GetTextOffsetAtPoint(y, x, &currentHitPart);
        if (m_repeatClickCount != 0) {
            TextEditRange range;
            if (m_repeatClickCount <= 1) {
                ::FindWordBoundary(
                    static_cast<const wchar_t *>(m_textStorage->GetData(0)),
                    GetTextLength(),
                    currentOffset,
                    currentHitPart != 0,
                    &range);
            } else {
                GetLineSelectionRange(currentOffset,
                                      currentHitPart,
                                      &range.start,
                                      &range.end);
            }

            if (m_savedSelectionStart >= currentOffset) {
                currentOffset = range.start;
                s_mouseSelectionAnchor = m_savedSelectionEnd;
            } else {
                currentOffset = range.end;
                s_mouseSelectionAnchor = m_savedSelectionStart;
            }
        } else if (currentHitPart == kTextHitAfterCharacter) {
            ++currentOffset;
        }

        SetSelectionRange(s_mouseSelectionAnchor, currentOffset);
        AutoScrollSelectionToPoint(y, x);
        return true;
    }

    case kEventLeftButtonUp:
        if (HasMouseCapture())
            ReleaseMouseCapture();
        return g_useEpfAssets != 1;

    case kEventRightButtonDown:
        SetSelectionRange(0, 0);
        return true;

    default:
        return false;
    }
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

- Destination 2: [UID:0000EO] complete `TextEditPane` declaration union, retained as the exact callback verification contract after normalized parity against the stable B004/B005 class surface.

*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
class Event;
class FontImageLib;
class List;
class StringIter;
class TextEditObject;
class TextEditPane;
class TextEditScrap;
struct Point;
struct TextRunMeasureState;
extern FontImageLib *g_pFontImageLib;
namespace mystr {
template <class CharT> struct mychar_traits;
template <class CharT, class Traits> class StringBase;
}

struct TextEditLineRecord
{
    unsigned short startIndex;
    int top;
    int remainingWidth;
    unsigned short wrapState;
};

struct TextRunFormatData
{
    unsigned short legacyAssetMode;
    unsigned int textColor;
    TextEditObject *object;
};

struct TextEditFormatRecord
{
    short referenceCount;
    TextRunFormatData format;
};

struct TextEditFormatRun
{
    unsigned short startIndex;
    short formatIndex;
};

struct TextEditRange
{
    short start;
    short end;
};

static void __stdcall FindWordBoundary(const wchar_t *text,
                                       short textLength,
                                       short caretIndex,
                                       bool forward,
                                       TextEditRange *range);

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
    void SetText(const wchar_t *text,
                 short length,
                 short selectStart,
                 short selectEnd);
    void ClearText();
    void SetSelectionRange(short start, short end);
    void SelectAll();
    void ApplySelectionFormat(unsigned char formatMask,
                              const void *formatData);
    void InsertEmbeddedObject(TextEditObject *object, int width, int height);
    void SetMaxLength(short maxLength);
    void SetMaxLines(short maxLines);
    void EnableMaskedText();
    void SetEditActiveState(bool editActive, bool selectAll);
    bool IsEmpty() const;
    void ScrollToTop();
    unsigned char GetMode() const { return m_mode; }

    void CopySelectionToScrap(TextEditScrap *scrap);
    void PasteFromClipboard(TextEditScrap *scrap);
    short GetLineCount() const;
    void SetViewportBounds(const RectBounds *bounds);
    void GetTextAreaBounds(RectBounds *bounds) const;
    void SetTextAreaBounds(const RectBounds *bounds);
    virtual void OnDraw();

protected:
    virtual bool OnKeyEvent(Event *event);
    virtual bool OnKeyUp(Event *event);
    virtual bool OnMouseEvent(Event *event);

    void InvalidateTextRegion(short start, short end);
    void DeleteSelectionOrBackspace();
    void FindWordBoundary(short index, short *wordStart, short *wordEnd) const;
    bool AutoScrollSelectionToPoint(int y, int x);

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
    int InsertTextRange(const wchar_t *text,
                        short length,
                        const unsigned short *formatPayload,
                        int formatFlags);
    void DeleteTextRange(short start, short end);
    void HandleNavigationKey(Event *event);
    short GetNavigationCaretIndex(Event *event, short caretIndex) const;
    short MeasureTextRunWrapSegment(const wchar_t *text,
                                    short textLength,
                                    int textOffset,
                                    int *remainingWidth,
                                    signed char *hitPart,
                                    unsigned short segmentFlags,
                                    int xOffset) const;
    void RebuildLineTable(short *firstLine, short *lastLine);
    void IterateTextRuns(short firstLine,
                         short lastLine,
                         TextRunIteratorCallback callback,
                         void *context);
    short GetLineIndexForTextOffset(short textOffset) const;
    short GetFormatRunIndexForTextOffset(short textOffset) const;
    short GetTextOffsetAtPoint(int y,
                               int x,
                               signed char *hitPart) const;
    void GetWordSelectionRange(short textOffset,
                               signed char hitPart,
                               short *rangeStart,
                               short *rangeEnd) const;
    void GetLineSelectionRange(short textOffset,
                               signed char hitPart,
                               short *rangeStart,
                               short *rangeEnd) const;
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
    void BuildTextRangeRectangles(short start,
                                  short end,
                                  List *rectangles) const;
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
    bool m_selectionReversed;
    bool m_currentFormatValid;
    bool m_selectionVisible;
    bool m_scrollRangeDirty;
    unsigned int m_editorFlags;
    unsigned int m_lastClickTime;
    short m_lastClickTextOffset;
    signed char m_lastClickHitPart;
    unsigned char m_repeatClickCount;
    unsigned char m_unusedClickState;
    bool m_dirty;
    bool m_maskedText;
    short m_maxLength;
    short m_maxLines;
    bool m_replacePreviousCompositionText;
    bool m_replacedCompositionText;
    bool m_useDefaultAlignment;
    bool m_useThousandsSeparator;
};

[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

- Destination 3: [UID:0000EN] complete `TextEditObject` declaration with the target-proven click hook.

*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
class Event;
class TextEditPane;
struct TextEditLineRecord;
struct TextRunFormatData;

static bool __cdecl TextRunMeasureCallback(TextEditLineRecord *line,
                                           const TextRunFormatData *format,
                                           const wchar_t *text,
                                           int textOffset,
                                           unsigned short charCount,
                                           unsigned short segmentFlags,
                                           void *context,
                                           TextEditPane *pane);

class TextEditObject : public LObject
{
public:
    TextEditObject(void *ownerHandle);
    virtual ~TextEditObject();

    int GetObjectType() const;
    void GetPayloadPair(int *outPair) const;
    void *GetOwnerHandle() const;
    void SetPayloadPair(int first, int second);

    virtual void OnUpdate();
    virtual void OnMouseEvent(Event *event,
                              bool repeatedClick,
                              unsigned int messageTime);

protected:
    friend bool __cdecl TextRunMeasureCallback(TextEditLineRecord *line,
                                               const TextRunFormatData *format,
                                               const wchar_t *text,
                                               int textOffset,
                                               unsigned short charCount,
                                               unsigned short segmentFlags,
                                               void *context,
                                               TextEditPane *pane);

    int m_objectType;
    void *m_ownerHandle;
    int m_payload0;
    int m_payload1;
};
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

- Destination 4: [UID:00040S] complete existing method cluster with only the target-proven hook rename/signature changed.

*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
TextEditObject::TextEditObject(void *ownerHandle)
    : LObject(),
      m_objectType(0),
      m_ownerHandle(ownerHandle),
      m_payload0(0),
      m_payload1(0)
{
}

TextEditObject::~TextEditObject()
{
}

int TextEditObject::GetObjectType() const
{
    return m_objectType;
}

void TextEditObject::GetPayloadPair(int *outPair) const
{
    outPair[0] = m_payload0;
    outPair[1] = m_payload1;
}

void *TextEditObject::GetOwnerHandle() const
{
    return m_ownerHandle;
}

void TextEditObject::SetPayloadPair(int first, int second)
{
    m_payload0 = first;
    m_payload1 = second;
}

void TextEditObject::OnUpdate()
{
}

void TextEditObject::OnMouseEvent(Event *, bool, unsigned int)
{
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

- Destination 5: [UID:0004TC] complete B004 `RefreshTextRange` body with only the source-facing +0x158 field token synchronized to Destination 2.

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
        ScrollCaretIntoView(m_selectionReversed
                                ? m_selectionStart
                                : m_selectionEnd);
    }
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

- Destinations 6-7 are applied prose-only updates to UID0001JM and UID0000ON: exact method/table range, helper signatures, corrected fields, source order, cross-TU declaration route, compiler exclusions, executed-B004/executed-B005 union, collision order, and historical assumptions. No reconstruction metadata was added on by-file UID0000ON, and aggregate UID0001JM remains blank-formal.
- Destinations 8-11 were verified read-only for UID000303, Event class/file, UID00018E/InputMan, and `g_useEpfAssets`; no direct drift or edit was found.
- External B005 dependency contracts, not B002 destinations: applied UID0004U9 exclusively emits file-local `FindWordBoundary` at `[0x00594b50,0x00594cb0)`, and applied UID0004UA exclusively emits `TextEditPane::AutoScrollSelectionToPoint` at `[0x00594cb0,0x00594e12)`. B002 consumes those exact current pages/bodies without copying either managed body. Waited generated closure verifies both existing definitions once alongside the new UID00030E definition.
- Reason behavior is exact: the source reproduces every branch, strict comparison, repeated hit test, state write, helper order, virtual call, global read, return, and absent guard while leaving ABI/table/vtable lowering to the compiler.
- Reason source shape is plausible: one ordinary protected virtual, existing class/private helpers and list types, module static anchor, external declarations, named enum cases, and no decompiler offsets or synthetic case functions match the surrounding late-1990s/early-2000s C++ style.

## Final Recommendation

- C01-C44 and managed Destinations 1-5 are terminally applied or verified under their legal ledger states; Destinations 6-7 are applied prose-only target-family updates and Destinations 8-11 remain read-only verification contracts. B005 UID0004U9/UID0004UA remain applied external definitions, not B002 destinations.
- UID00030E is `92/94`; UID, path, owner/emitter UID0000EO, reconstructable true, blank position, and Nested 0 are preserved.
- Preserve the local jump table inside the target range as compiler-generated method-local data.
- The complete TextEditPane class/file/aggregate union was rebased over executed B004 command 15177 and executed B005 command 15329 after immediate destination rereads. All B004 helper children and every B005 key/key-up/clipboard/navigation/wrap/word/autoscroll/composition declaration, body, child, residual UID0001JS range, and real UID remain present. Destination 2 was verified at whitespace-normalized semantic parity and Destination 5 at byte equality, both read-only.
- TextEditObject and UID00040S were refined only for the proven second virtual hook; all payload, constructor/destructor, first hook, friend, owner, and source-route detail remains.
- Event, InputMan, static anchor, `g_useEpfAssets`, ScrollablePane, RectBounds, List, vtable/data, and unrelated TextEdit children were verified unchanged.
- No investigable behavior/source-shape blocker remains in the combined B002+B005 graph. B005 child issuance/application is complete; UID0004U9 and UID0004UA are fixed read-only dependencies and do not authorize duplicate B002 pages.

## Recommended Target Doc Changes

- Target path: `by-memory/0x00590de0-0x00591180.TextEditPaneOnMouseEvent.md`.
- Metadata: `92/94`, owner/emitter UID0000EO, true, blank position, Nested 0.
- Destination 1 is installed byte-for-byte. The current Item Summary identifies the complete bool virtual, body/table split, primary `+0x60` route, Event ABI, five cases, strict repeated-click timing, direct B005 file-local word-boundary calls, ignored bool autoscroll returns, inline-object callback, IME/capture order, static anchor, asset-mode release asymmetry, and compiler-only table.
- Exact bytes/hashes, CFG, instruction count, callers/callees/xrefs, fields, helper signatures, no-null/no-guard facts, source order, source placement, negative evidence, rejected alternatives, score rationale, and historical deferral are incorporated.
- Preserve earlier evidence as labeled history, including the prior blank-formal blocker; do not retain it as current truth.

## Recommended Support Doc Changes

- `by-class/TextEditPane.md`: Destination 2 was verified at whitespace-normalized source parity in SHA256 `471C8B493EEB6B150E490D7D03DE44D822DD142D1D777CB67557F883B7B8752D`, 83,532 bytes/666 lines, and remained read-only. The complete executed-B004/executed-B005 union, including `TextEditRange`, file-local word prototype, distinct member wrapper, six UID0001JS member/helper declarations, bool `(y,x)` autoscroll, two composition booleans, `m_selectionReversed`, `m_unusedClickState`, and compiler-natural alignment remains preserved.
- `by-memory/0x00591400-0x005914c4.TextEditPaneRefreshTextRange.md`: Destination 5 was verified byte-equal at SHA256 `803DFFF6C97A89CF4C8806C72FAAF8010A3DB5AF51F2E08F011ECC2A1DAC62DD`, 9,424 bytes/111 lines; `92/94`, range, owner/emitter, reconstructability, position, nesting, behavior, and `m_selectionReversed` remain unchanged.
- `by-file/TextEditPane.md`: the prose-only UID00030E method/source order, B005 file-local word/member-autoscroll dependency and real-UID links, helper/linkage route, target table disposition, corrected field inventory, inline-object dependency, generated expectations, residual UID0001JS debt boundary, compiler exclusions, and collision history are applied at SHA256 `7972CD02AC5B47776A5D110C45065B715089DCDF00475BE8005385E6D66AB50C`, 99,212 bytes/479 lines. No by-file reconstruction metadata was added.
- `by-memory/0x0058dce0-0x00591300.TextEditPaneCoreBeforeTextBoxPane.md`: the non-emitting aggregate formal remains blank; exact UID00030E source-ready status, table boundary, helper/field/source-order inventory, executed-B004/expanded-B005 coordination, and no-duplicate helper rule are applied at SHA256 `BB1DAD3000232EBE1BA5A187B67320E3F8F00EC84A28EB5B7BFA696C01C56314`, 41,780 bytes/218 lines.
- `by-memory/0x00594040-0x00594e60.TextEditPaneInputNavigationWrapAndTextRunHelpers.md` and B005's six applied child pages are B005-owned read-only dependencies to B002. B002 must neither lease nor edit them unless a later supervisor callback explicitly reassigns scope; consume UID0004U9/UID0004UA and their exact contracts only.
- `by-class/TextEditObject.md`: Destination 3 is installed at `90/93`, SHA256 `5F0C88A900D51FFD147D6022EEC65C72F2FC491C13CBDECCF2B391E4A09A5AB0`, 19,532 bytes/176 lines, with all unrelated layout/method/history preserved.
- `by-memory/0x00594e60-0x00594f23.TextEditObjectCoreMethods.md`: Destination 4 is installed at `89/92`, SHA256 `5BA40E9616FE630B5AAACE95CE46A49C07EF4BFBB9A4FD08F85245D6F0DBF4E1`, 10,340 bytes/133 lines; only the provisional second-hook disposition changed and all other exact bodies remain.
- UID000303: verify-only; current static definition and eight-xref/zero-initializer proof already satisfy the target.
- Event class/file: verify-only and B003-owned concurrent scope. Preserve complete current Event union and exact pointer payload.
- UID00018E/InputMan: verify-only definition owner. Add no duplicate definition; target emitter contains only an external declaration.
- `g_useEpfAssets`: verify-only definition owner. Add no duplicate global.
- ScrollablePane/RectBounds/List/vtable/read-only pages: verify-only unless concrete stale target-specific prose is found.

## Score And Metadata Recommendation

- Historical pre-callback target: `86/90`, UID0000EO owner/emitter, true, blank position, Nested 0, blank formal.
- Applied target: `92/94`, metadata otherwise unchanged, complete formal body.
- Reason not lower: exact range/hash, complete CFG, vtable liveness, Event ABI, every branch/helper/field/global, source owner, source-shaped target C++, and the complete externally owned word/autoscroll bodies are closed.
- Reason not higher: stripped original symbols leave private helper/member lexical spellings inferred. B005 child issuance is complete and no longer caps readiness; `94` remains appropriate because original private spellings and probable header factoring are not recoverable.
- Score-improvement attempts: Event blocker removed through current declaration; capture blocker removed by direct helper decompilation and sibling reports; composition blocker removed by direct body and executed InputMan report; field blocker removed by offset-use searches/constructor; click-hook blocker removed by the only semantic vtable caller; table blocker removed by pointer decoding; word/autoscroll blocker removed by applied B005 UID0004U9/UID0004UA plus independent MCP hash/body/caller validation; owner/source blocker removed by vtable/neighborhood; generated blocker receives exact callback assertions over the current complete union.
- UID0000EO remains `93/94`; UID0000ON remains `93/93`; UID0001JM remains `87/91` because it is a broad non-emitting split index; UID0004TC remains `92/94`; UID000303 remains `87/91`; UID0000EN becomes `90/93`; UID00040S becomes `89/92`.

## Open Questions With Attempted Resolution

- Original private spellings: no symbols/strings survive. Helper bodies, argument roles, class state, and sibling vocabulary support the recommended names. This is resolved by evidence-backed descriptive inference, with confidence cap only.
- `+0x15b`: direct writes/reads tie it to delayed scroll-range refresh; `m_scrollRangeDirty` is the best descriptive spelling. It does not affect UID00030E body but is required to avoid falsely treating a live byte as padding in the complete class.
- `+0x168/+0x16b`: final accepted B005 bounded constructor, mouse, selection, clipboard, family-listing, and memory-operand checks found no surviving direct access to `+0x168`, but byte fields continue through `+0x169/+0x16a`, so it is physically occupied source storage rather than natural alignment. Destination 2 therefore uses inferred `unsigned char m_unusedClickState`; the exact original spelling and bool-versus-byte intent remain irrecoverable and confidence-capped. `+0x16b` is compiler-natural alignment before `short m_maxLength`, so no explicit source padding member is emitted. The earlier B002 reserved/coalesced-byte and explicit-padding disposition is historical and superseded.
- B004/B005 union conflict: executed B004 ordinary helpers and executed B005 ordinary source were read directly. B005's two composition booleans, six UID0001JS declarations/bodies, `TextEditRange`, file-local word prototype, bool `(y,x)` autoscroll, `m_selectionReversed`, and `m_unusedClickState` are current. Destination 2 is normalized-equal and Destination 5 is byte-equal to that current union. The historical `m_dragSelectionActive` and `m_mouseMode` spellings remain superseded by direct UID00030E/SetSelectionRange evidence. B005 owns UID0004U9/UID0004UA; this is deterministic non-overlap, not deferred behavior.
- Left-up current-mode false return: direct branch proves it; likely caller/dispatch policy consumes it. It is preserved rather than normalized.
- Why line range takes hit part: ABI/callers push it, body ignores it. Preserve the parameter for source compatibility; do not delete it based on decompiler use.
- Cross-TU composition declaration: probable original header placement cannot be named exactly. A direct external declaration in the valid target formal block is compile-visible and does not duplicate the UID00018E definition.
- B005 child identities: resolved and applied as UID0004U9 `by-memory/0x00594b50-0x00594cb0.FindWordBoundary.md` and UID0004UA `by-memory/0x00594cb0-0x00594e12.TextEditPaneAutoScrollSelectionToPoint.md`, each `92/94` with its accepted owner/emitter and complete managed body. B002 consumes them read-only and invents no replacement.
- No open question blocks target source, score, owner, emitter, range, or generated verification. The former B005 serialization question is externally complete under command 15329.

## Exact Manual Supervisor-Owned Coverage Or Tracker Text

- Inspected manual files: `by-memory/-coverage-report.md`, `by-class/-coverage-report.md`, `by-file/-coverage-report.md`, `by-global/-coverage-report.md`, and `by-type/by-vtable/-coverage-report.md`; no root `by-struct/-coverage-report.md` exists. B005's twenty-three-row handoff and B003's later nine-row handoff are already supervisor-applied and must not be repeated or replaced. Exactly six B002 actions remain below, rebased over that complete 32-row external union. No manual by-global change is needed because `g_useEpfAssets` is verify-only. No by-vtable change is needed because compiler-owned TextEditPane table data and slot topology remain unchanged. No Event row change is needed because current Event class/file coverage already includes the externally applied B005 union and UID00030E does not alter Event metadata.
- Current final-read hashes are time-bounded evidence after external supervisor commands `000000015330`-`000000015332`: by-memory SHA256 `A389E147EF2DD89DBB0E5B2D6491942E399512834FB7BB8C88F96FF79AC89E5C`, 1,851,119 bytes/4,396 lines; by-class SHA256 `22ADD1F1931D9A32C0F68E0532E741FAB11C5A2BD7958D585063839BF0D0093A`, 239,369/623; by-file SHA256 `BE87AED1FF6456C49A9D4A5F815A496EF7FBF2ED825B005F2FE832E5663CB998`, 137,501/316; by-global SHA256 `4F96E6C2DE7E9BDCDEA2537579EF1D2CE1C0884E421B1D29D23757A8913BD97D`, 90,566/213; by-type/by-vtable SHA256 `C3E8589578BE56A7783C2D3C43E5C44DCCB939E0776BC673E521D4C7CE762339`, 64,938/142. The pre-B003 command-15326/15327/15328 hashes `4BB897...4B220`, `B666A6...321255`, and `63FFCA...F006C` are explicitly historical snapshots, not current manual authority.
- Exact B005 23-row preservation proof: by-memory retains UID0001JM, UID00030F, padding `[0x00590dc5,0x00590dd0)`, UID0004TZ, padding `[0x00590dd5,0x00590de0)`, UID0004T8, UID0004U1, padding `[0x00591c65,0x00591c70)`, UID0001JS, UID0004U3, UID0004U5, UID0004U7, UID0004U8, UID0004U9, UID0004UA, UID0001JT, UID0003DV, and UID0001JO; by-class retains UID00004L, UID0000EO, and UID0000EP; by-file retains UID0000J6 and UID0000ON. All 23 current rows were reread and remain unchanged by this report-only repair.
- Exact B003 nine-row preservation proof: by-memory retains UID0001LN at line 3598, UID0004UC at line 3609, UID0001N9 at line 3695, padding `[0x005b7db4,0x005b7dc0)` at line 3704, UID0001NG at line 3705, padding `[0x005b7e84,0x005b7e90)` at line 3706, and UID00026W at line 4069; by-class retains UID0000DS at line 517; by-file retains UID0000O0 at line 261. These nine rows were externally applied/validated by supervisor commands 15330-15332 and are preserved byte-for-byte as the current union.
- Current B002 anchor proof over the complete union: by-memory line 3304 contains B005's applied UID0001JM row; lines 3313-3316 contain UID00030F, padding, UID0004TZ, and padding; line 3321 preserves B004 UID0004TC; lines 3342-3348 contain UID0001JS and all six children including UID0004U9/UID0004UA; line 3350 is UID0002XX and line 3351 is UID0001JU. UID00030E and UID00040S remain absent. By-class line 550 and by-file line 284 contain the full applied B004/B005 union but not UID00030E; by-class line 549 still has provisional TextEditObject `OnAction`. Therefore the exact remaining handoff is three by-memory actions, two by-class actions, and one by-file action, with no B003 or B005 row deletion/replacement beyond the expressly proposed UID0001JM/UID0000EO/UID0000ON no-loss replacements below.
- Action 1, by-memory addition under UID0001JM: insert immediately after current `[0x00590dd5,0x00590de0)` padding at line 3316 and before UID0004T0. Preserve every surrounding B005 row:

`        - [UID:00030E][0x00590de0-0x00591180.TextEditPaneOnMouseEvent](by-memory/0x00590de0-0x00591180.TextEditPaneOnMouseEvent.md) 0x00590de0-0x00591180 | virtual method plus local switch table | TextEditPaneOnMouseEvent : reconstructable : 92% : very-strong : Complete source-ready bool TextEditPane::OnMouseEvent with exact 908-byte method/20-byte compiler table split and hashes, primary-vtable +0x60 liveness, current Event pointer ABI, five-case move/down/double/up/right behavior, strict 500-ms repeat timing, member saved-range expansion plus direct UID0004U9 file-local FindWordBoundary and UID0004UA bool (y,x) autoscroll dependencies, signed-short anchor/range direction, one-character TextEditObject click hook, IME-finalize then down-only capture order, deliberate second hit test, current-mode left-up false asymmetry, no invented guards, and compiler-only table/ABI exclusions.`

- Action 2, by-memory replacement for current UID0001JM line 3304, preserving all B004/B005 facts and adding UID00030E:

`        - [UID:0001JM][0x0058dce0-0x00591300.TextEditPaneCoreBeforeTextBoxPane](by-memory/0x0058dce0-0x00591300.TextEditPaneCoreBeforeTextBoxPane.md) 0x0058dce0-0x00591300 | source-bearing split aggregate | TextEditPaneCoreBeforeTextBoxPane : reconstructable : 87% : very-strong : Exact non-emitting TextEditPane pre-TextBox source index preserving source-ready constructor/destructor/ReleaseFormatObjects/EncodeState/OnDraw/range/draw helpers, exact four List fields, signed format references, compiler/padding boundaries, all current B004 detail, and applied B005 UID00030F OnKeyEvent, UID0004TZ OnKeyUp, clipboard/navigation/wrap/word/autoscroll/composition union; adds source-ready UID00030E OnMouseEvent with exact body/table split, primary +0x60 route, current Event ABI, click/drag/anchor/inline-object/IME/capture behavior, corrected +0x158..+0x173 selection/click/composition/alignment layout, direct UID0004U9/UID0004UA dependencies, helper signatures, and compiler exclusions while the aggregate formal remains blank and all exact children emit independently.`

- Action 3, by-memory addition beneath UID0002XX at the source-ordered UID00040S location and before UID0001JU:

`        - [UID:00040S][0x00594e60-0x00594f23.TextEditObjectCoreMethods](by-memory/0x00594e60-0x00594f23.TextEditObjectCoreMethods.md) 0x00594e60-0x00594f23 | class-method cluster | TextEditObjectCoreMethods : reconstructable : 89% : very-strong : Complete TextEditObject constructor/destructor/accessor/payload/no-op-hook source preserving the exact payload-oriented layout while the sole semantic UID00030E caller resolves the second virtual hook as source-empty OnMouseEvent(Event *,bool,unsigned int), superseding provisional OnAction(int,int,int) without changing vtable order or EPF inheritance.`

- Action 4, by-class replacement for current UID0000EO line 550, preserving the complete B004/B005 row and adding UID00030E:

`- [UID:0000EO][TextEditPane](by-class/TextEditPane.md) : reconstructable : 93% : very-strong : Complete TextEditPane declaration preserving the executed B004 constructor/destructor/serialization/OnDraw/range/draw-helper union, exact four List fields and signed format records with compiler-natural alignment, and applied B005 bool OnKeyEvent/OnKeyUp, clipboard scrap, navigation/delete/dispatcher/wrap/UID0004U9 file-local word/UID0004UA autoscroll/composition union; adds source-ready OnMouseEvent, exact +0x158..+0x173 selection-direction/click/dirty/masked/limit/composition/alignment layout, current Event contract, TextEditObject click route, class closure before children, and compiler table/vtable/ABI exclusions without duplicating or losing any shared method, field, helper, body, or child.`

- Action 5, by-class replacement for current UID0000EN line 549:

`- [UID:0000EN][TextEditObject](by-class/TextEditObject.md) : reconstructable : 90% : very-strong : Complete LObject-derived TextEditObject declaration with object-type, owner-handle, protected payload-pair storage, public get/set helpers, provisional OnUpdate, target-proven source-empty OnMouseEvent(Event *,bool,unsigned int) click hook, exact TextRunMeasureCallback friendship, and unchanged TextEditPane.cpp ownership/vtable order.`

- Action 6, by-file replacement for current UID0000ON line 284, preserving the full B004/B005 row and adding UID00030E:

`- [UID:0000ON][TextEditPane](by-file/TextEditPane.md) : reconstructable : 93% : very-strong : Rich text editor implementation preserving the complete executed B004 constructor/destructor/serialization/OnDraw/range-helper union, four List fields, signed format records, exact post-TextBox helper order, and applied B005 UID00030F/UID0004TZ/clipboard/six-child UID0001JS union; adds source-ready UID00030E OnMouseEvent with exact method/table range, Event ABI, five pointer cases, click/drag/static-anchor/inline-object/IME/capture behavior, direct UID0004U9/UID0004UA dependencies, corrected TextEditPane field/helper declarations, exact source order, residual UID0001JS debt boundary, and compiler exclusions while InputMan and g_useEpfAssets remain sole external definition owners and no shared TextEditPane source is duplicated or lost.`

- Exact six-action row text is supervisor-owned. B002 must not edit manual coverage; validator-generated coverage does not apply these rows.

## Follow-Up Actions

- B002's authorized callback work is complete: all five changed ordinary pages were leased, reread, rebased, validated, and released serially; Destinations 2 and 5 and all remaining support were verified read-only; C01-C44 are terminal; and waited command 15346 supplies the generated/tracker readback.
- The exact six-action manual coverage handoff below remains supervisor-owned. At the callback final-read boundary, the current manual files still preserve the B005 23-row and B003 nine-row union while all six B002 rows remain unapplied. B002 made no manual coverage edit.
- Generated proof is terminal for this callback epoch: exactly one UID00030E method and static anchor definition; no target Empty Emitter Marker; one complete TextEditPane class; one renamed TextEditObject hook declaration and empty definition; one UID0004TC definition using `m_selectionReversed`; one UID0004U9 file-local body plus its declaration and one UID0004UA bool body; zero stale `m_dragSelectionActive`, `m_mouseMode`, or `OnAction` tokens; no duplicate external definition; one intentional UID0001JS parent marker; no handwritten jump-table/vtable/ABI source; and all B004/B005 children/methods preserved.
- Excluded work remains deliberate, not blocked: no UID0001JS/helper duplication, no Event/InputMan/global/read-only support edit, no compiler table/vtable/wrapper source, no manual coverage edit, and no report lifecycle operation by B002.
- Current/future Gate 2, manual coverage application, report validation, execution, movement, and archive state are supervisor/validator-owned and are not asserted as global lifecycle truth by this report.

## Confidence

- Recommendation confidence: very strong.
- Score confidence: strong at `92/94`.
- Remaining uncertainty: original private lexical names and probable original header filename only. All runtime behavior, ABI, range/table, state layout, source owner/file, and target formal body are resolved.

## Validator Results

- `000000015339`, `2026-07-20T13:24:27-04:00`, UID00030E, exit `0`, `ok:1`: applied completion `92`, confidence `94`, blank-to-block registry transition, and registry hash update; no warning rows; generated refresh deferred; validator-owned projected-stats/registry side effects only.
- `000000015340`, `2026-07-20T13:26:16-04:00`, UID0000EN, exit `0`, `ok:1`: applied completion `90`, confidence `93`, and registry hash update; 12 pre-existing `missing_ref_uid` warnings (including UID00040S/UID0003GA); generated refresh deferred; validator-owned projected-stats/registry side effects only.
- `000000015343`, `2026-07-20T13:27:34-04:00`, UID00040S, exit `0`, `ok:1`: applied score `89/92`, canonical owner, path/UID registration, block hash, header blank, and seven reference-index additions; four pre-existing `missing_ref_uid` warnings for UID0003GA/UID0003M8; generated refresh deferred; validator-owned projected-stats/registry/reference side effects only.
- `000000015344`, `2026-07-20T13:29:00-04:00`, UID0001JM, exit `0`, `ok:1`: added UID00040S/UID0004U9/UID0004UA references; no warning rows; generated refresh deferred; validator-owned projected-stats/reference side effects only.
- `000000015345`, `2026-07-20T13:30:36-04:00`, UID0000ON, exit `0`, `ok:1`: added UID00030E/UID00040S/UID0004U9/UID0004UA references; 50 pre-existing `missing_ref_uid` warnings on the large file page; generated refresh deferred; validator-owned projected-stats/reference side effects only.
- Final authorized waited command `000000015346`, `2026-07-20T13:31:37-04:00`, UID00030E, exit `0`, `ok:1`: rebuilt 5,166-node/4,152-edge registry and completed generated refresh. Project-wide diagnostics were 13 fallback child insertions, 86 missing preferred child markers, and 137 emitter-has-no-code notices, none target-specific failures; 280 generated metadata files refreshed as validator-owned side effects. B002 did not edit generated, tracker, registry, or stats files manually.
- Generated result: `auto-generated/NexusTK/ui/controls/TextEditPane.cpp`, command 15346, SHA256 `C7565637EDC6BA9CF10F7635234EDE2F028C22FC5F449231DFED9C20BA83C64E`, 62,112 bytes/1,824 lines. Exact structural/readback assertions are recorded in Current Target State and all passed.
- Tracker result: `auto-generated/-ag-research-tracker.md`, command 15346, SHA256 `8DD00EFBEB8D924375C940CB55B000E9E938F65111308ACAC87ABEE92FB0A4F3`, 1,530,688 bytes/6,205 lines; UID00030E is `92/94` at line 3241. Commands 15338, 15333, 15329, and 15325 remain historical epochs.
- External artifact proof remains `executed-b-agent-research/B003/0001NG-SpellSlotInputPaneScalarDeletingDestructor-source-quality.md`, post-lifecycle SHA256 `2ADF3713C07ED694C0FCBC90048EAEC9C0162B295142327F84CCAA14524A775D`, 83,454 bytes/601 lines. Final-read manual hashes are by-memory `A389E147EF2DD89DBB0E5B2D6491942E399512834FB7BB8C88F96FF79AC89E5C`, 1,851,119 bytes/4,396 lines; by-class `22ADD1F1931D9A32C0F68E0532E741FAB11C5A2BD7958D585063839BF0D0093A`, 239,369/623; and by-file `BE87AED1FF6456C49A9D4A5F815A496EF7FBF2ED825B005F2FE832E5663CB998`, 137,501/316. They preserve the B005 23-row and B003 nine-row union while the six B002 actions remain supervisor-owned and unapplied.
- MCP result: healthy streamable endpoint at evidence time; target sessions `1f386679-d9f6-406c-a82a-c93e5698ed69` / `2acd11cb-2054-419b-ad2e-7ba428883ebc`, complete dependency session `17b2029b-e88b-4cf0-b9c3-efc1385e666a`, and final health/bounded sessions `b1bdab9a-78d8-426e-bb0a-b966669d164a` / `6394e934-3d01-4a2d-904a-bbaa506515e3`, database `9b0396a3`; `server_health` status `ok`; bounded target/helper/vtable/global calls plus exact UID0004U9/UID0004UA bytes, hashes, decompilations, CFG, and caller checks returned real data. Session health is evidence-time, not an indefinite availability claim.
- Unresolved validator errors: none. Warning rows are the pre-existing scoped/project-wide diagnostics enumerated above and do not block the accepted destination or generated assertions.

## Changed Files

- Same report updated: `tools/leaser/Agents/Agent-B002/research/00030E-TextEditPaneOnMouseEvent-source-quality.md`.
- Modified ordinary target: `by-memory/0x00590de0-0x00591180.TextEditPaneOnMouseEvent.md`, SHA256 `4042553F82F90C28026C03196735DCFC6A7745467CAE4ADDF0F7B001D9FE8856`, 18,321 bytes/261 lines.
- Modified ordinary support: `by-class/TextEditObject.md`, SHA256 `5F0C88A900D51FFD147D6022EEC65C72F2FC491C13CBDECCF2B391E4A09A5AB0`, 19,532 bytes/176 lines.
- Modified ordinary support: `by-memory/0x00594e60-0x00594f23.TextEditObjectCoreMethods.md`, SHA256 `5BA40E9616FE630B5AAACE95CE46A49C07EF4BFBB9A4FD08F85245D6F0DBF4E1`, 10,340 bytes/133 lines.
- Modified ordinary prose: `by-memory/0x0058dce0-0x00591300.TextEditPaneCoreBeforeTextBoxPane.md`, SHA256 `BB1DAD3000232EBE1BA5A187B67320E3F8F00EC84A28EB5B7BFA696C01C56314`, 41,780 bytes/218 lines.
- Modified ordinary prose: `by-file/TextEditPane.md`, SHA256 `7972CD02AC5B47776A5D110C45065B715089DCDF00475BE8005385E6D66AB50C`, 99,212 bytes/479 lines; no reconstruction metadata added.
- Verified ordinary read-only: `by-class/TextEditPane.md`, SHA256 `471C8B493EEB6B150E490D7D03DE44D822DD142D1D777CB67557F883B7B8752D`, 83,532 bytes/666 lines; Destination 2 whitespace-normalized parity.
- Verified ordinary read-only: `by-memory/0x00591400-0x005914c4.TextEditPaneRefreshTextRange.md`, SHA256 `803DFFF6C97A89CF4C8806C72FAAF8010A3DB5AF51F2E08F011ECC2A1DAC62DD`, 9,424 bytes/111 lines; Destination 5 byte parity.
- Verified B005 dependencies read-only: UID0004U9 SHA256 `C6B4D7106142250A0EB839DF88D3CBD2AF22404DCCA4EC4D3A83EF91E8BDA667`, 6,242 bytes/116 lines; UID0004UA SHA256 `933AD3AA695207246FB83FC8B32A2EC4D72B14D033FFDDB00C69AE7475FE77C2`, 6,246 bytes/108 lines; UID0001JS SHA256 `2ADBACE12B942BAC1616315F7038BCBA8464A92A927BDD6A793CBD5D683A1B9B`, 28,420 bytes/206 lines.
- Read-only coordination artifacts: executed B004 UID0003N0 archive SHA `6916471...BEE6`; executed B005 UID00030F archive SHA `C6B14C8772182E53D454E4011DD231D9EDB9744F94040663E592D0AFFC0FCAB4`, command `000000015329`; executed B003 UID0001NG archive SHA `2ADF3713C07ED694C0FCBC90048EAEC9C0162B295142327F84CCAA14524A775D`, command `000000015333`; no edit to any archive.
- Read-only final-boundary external state: tracker/generated command 15346 and hashes above; command 15338/SHA `A54CEEB3...22FB`, command 15333/SHA `0D15D817...C0190`, and commands 15335/15337 remain historical. Manual by-memory/by-class/by-file hashes remain `A389E147...E5C` / `22ADD1F...93A` / `BE87AED1...998` after supervisor commands 15330-15332. No tracker, generated, or manual file was edited manually.
- Renamed: none.
- Ordinary edits are exactly the five files listed above. Generated/tracker/validator registry/reference/stats changes were validator-owned effects of commands 15339-15346; manual coverage/audit/goal/supervisor/IDA files were not edited.
- Leases: five ordinary leases were acquired serially and released immediately after their scoped validators; final lease-ledger readback shows zero B002 leases and zero total leases.
- Report execution: B002 does not run report execution or lifecycle commands. Exact current/future report path and lifecycle state are supervisor/validator-owned.

## Implementation Tracking Checklist

Initial report-only pass:
- [x] Supervisor Gate 1 accepted exact pre-callback SHA `A95477F07BBE403B13FD131DCFA7AC13AD1101568CE2C4089B820A4F4077EF5C` before implementation.
- [x] Confirm target preflight SHA256 `19A9818BD16EEB33D7A4BC09B463B56B908CD9FEFB95D7B6B2A5A8CDCB654CA0` and reread before edit.
- [x] Apply target `92/94`, owner/emitter UID0000EO, true, blank position, Nested 0.
- [x] Install Destination 1 byte-for-byte.
- [x] Preserve exact body/table/predecessor/successor boundaries and hashes.
- [x] Incorporate complete CFG/instruction/caller/callee/vtable/global evidence.
- [x] Preserve all five event cases, strict repeat timing, and return asymmetries.
- [x] Preserve absent null/index/overflow guards and compiler exclusions.
- [x] Rebase executed B004 UID0003N0 helper union and B005 UID00030F expanded key/key-up/clipboard/navigation/wrap/word/autoscroll/composition union before B002 shared edits; preserve the externally applied B003 nine-row manual union unchanged.
- [x] Confirm terminal B005 archive SHA `C6B14C8772182E53D454E4011DD231D9EDB9744F94040663E592D0AFFC0FCAB4`, command `000000015329`, and reread the full artifact/current destinations.
- [x] Confirm B005 exclusively owns UID0001JS and all six applied child pages; create no duplicate report, page, or body.
- [x] Verify UID0004U9 word-helper range/hash/ABI/body and UID0004UA autoscroll range/hash/ABI/body against live MCP and current pages.
- [x] Verify complete Destination 2 remains present at same-or-greater semantic detail; no concrete drift required an edit.
- [x] Apply corrected `+0x158..+0x173` field inventory and helper signatures.
- [x] Install Destinations 3-4 and remove accepted stale `OnAction(int,int,int)` spelling.
- [x] Verify Destination 5 remains byte-equal to current UID0004TC with `m_selectionReversed`; no concrete drift required an edit.
- [x] Preserve TextEditObject payload/friend/first-hook/vtable/source-route content.
- [x] Add Destinations 6-7 UID0001JM/UID0000ON prose only; keep aggregate/by-file formals unchanged/absent.
- [x] Verify Event/InputMan/anchor/global/ScrollablePane/RectBounds/List support same-or-greater.
- [x] Confirm every C01-C44 Action uses the permitted enum vocabulary and every terminal Verification state is one of `applied`, `already-present`, or `excluded-with-reason`.
- [x] Preserve all historical assumptions as labeled history.
- [x] Preserve rejected alternatives and negative evidence.
- [x] Confirm no third-party import applies.
- [x] Confirm no IDA mutation was requested or performed.
- [x] Supply the exact six supervisor-owned manual coverage additions/replacements over the preserved B005 23-row plus B003 nine-row union without editing coverage.
- [x] Re-read all current manual rows/hashes and tracker command 15346 immediately before callback return; preserve command 15333 as B003 execution provenance and later pre-callback epochs as history.
- [x] Confirm no duplicate UID00030E report exists.
- [x] Confirm the report-only phase changed only this report; callback ordinary changes are exactly the five paths recorded below, and B002 holds zero leases.

Implementation callback pass:
- [x] Exact pre-callback report accepted by supervisor for implementation.
- [x] Reread current target and every support destination before leasing.
- [x] Reread current B004 UID0003N0 final report/destinations and preserve its complete union.
- [x] Reread current B005 UID00030F final report/destinations and preserve its complete union.
- [x] Confirm `[0x00594b50,0x00594cb0)` is UID0004U9 and `[0x00594cb0,0x00594e12)` is UID0004UA everywhere; no coordination token remains.
- [x] Verify UID0004U9/UID0004UA contain exact D11/D12 bodies and matching `92/94` owner/emitter routes; neither was leased or edited.
- [x] Confirm both current B005 bodies/UIDs remain consistent with the accepted archive; no B002 substitute was created.
- [x] Reread executed B003 UID0001NG artifact/current nine-row manual union and B003 Event final union; preserve both and keep Event docs read-only.
- [x] Lease only UID00030E immediately before edit.
- [x] Apply all target evidence, metadata, body, history, and negative facts without compression.
- [x] Scoped-validate UID00030E as command 15339 and record timestamp/exit/ok/warnings/side effects/hash.
- [x] Release UID00030E lease immediately.
- [x] Reread UID0000EO and verify Destination 2 whitespace-normalized parity; leave read-only because no concrete drift exists.
- [x] Record UID0000EO current hash and Destination 2 already-present parity proof.
- [x] Exclude the conditional UID0000EO repair path because parity proved no repair or lease was required.
- [x] Lease/update/validate/release UID0000EN under Destination 3.
- [x] Lease/update/validate/release UID00040S under Destination 4.
- [x] Reread UID0004TC and verify Destination 5 exact parity; leave read-only because no concrete drift exists.
- [x] Lease/update/validate/release UID0001JM prose with formal remaining blank.
- [x] Lease/update/validate/release UID0000ON prose with no reconstruction metadata.
- [x] Leave all verify-only support unchanged because no concrete contradiction was found.
- [x] Terminalize C01-C44 only from destination evidence using legal final states.
- [x] Run one authorized final waited TextEditPane refresh as command 15346.
- [x] Verify exactly one complete TextEditPane class and one UID00030E definition.
- [x] Verify zero UID00030E Empty Emitter Markers.
- [x] Verify exactly one UID0004U9 file-local FindWordBoundary body and one UID0004UA bool AutoScrollSelectionToPoint body.
- [x] Verify UID00030E has two direct word-helper calls and two ignored bool autoscroll calls with no duplicate wrapper substitution.
- [x] Verify one `s_mouseSelectionAnchor` definition and eight target uses with no duplicate global.
- [x] Verify one TextEditObject click-hook declaration and empty definition with no stale accepted `OnAction` spelling.
- [x] Verify no duplicate CompleteImeComposition or g_useEpfAssets definition.
- [x] Verify no handwritten local switch table, vtable, RTTI, cookie, EH, adjustor, or deleting-wrapper source.
- [x] Verify all executed-B004 and executed-B005 methods/children/formals remain present in source order, with one intentional UID0001JS parent marker only for B005's bounded residual debt.
- [x] Verify UID0004TC uses `m_selectionReversed` once and no stale active `m_dragSelectionActive`/`m_mouseMode` class token remains.
- [x] Reread generated file independently and record command/header/hash/bytes/lines/assertion counts.
- [x] Reread manual coverage after external commands 15330-15332 and provide the exact six-row current supervisor handoff over the preserved B005/B003 union only.
- [x] Update Validator Results, Changed Files, ledger, current state, and checklist truthfully against tracker command 15346, B003 lifecycle command 15333, and current external manual hashes.
- [x] Confirm every changed ordinary file hash and every lease release.
- [x] Confirm zero B002 leases and no prohibited/manual/lifecycle edits.
- [x] Stop at the supervisor callback return contract; never execute, move, or archive the report.

READY_FOR_SUPERVISOR_GATE2_REVIEW

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B002","command_id":"000000015350","destination_path":"executed-b-agent-research/B002/00030E-TextEditPaneOnMouseEvent-source-quality.md","details":"report executed into central archive","event":"executed","source_path":"tools/leaser/Agents/Agent-B002/research/00030E-TextEditPaneOnMouseEvent-source-quality.md","timestamp":"2026-07-20T13:58:41-04:00","uid":"00030E"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
