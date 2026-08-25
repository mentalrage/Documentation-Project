** TARGET-REPORT-UID:0002EW **
** AUTHOR-AGENT-ID:B002 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.6 | xHigh **
# UID0002EW ChattingPane SetVisibleRowCount Source-Quality Research

## Finalized Report / Current Recommendation

- Completed recommendation: [UID:0002EW] remains the exact source-bearing ordinary
  `ChattingPane::SetVisibleRowCount(int visibleRows)` child at `92/94`, with
  `CANONICAL_OWNER:00001X`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:00001X`, blank
  optional emitter position, and `Nested:0` retained.
- Final disposition applied: the exact managed block in `First-Draft C++ Recommendation`
  now preserves the leading bounds-copy call, two separate `RectBounds` locals,
  pointer-shaped `SetBounds` call, inherited `m_bounds` invalidation, and
  current/max/apply ordering.
- Completed implementation scope: the target carries C01-C24 at report-level detail;
  bounded score-neutral synchronization is present on [UID:00001X] `ChattingPane`,
  [UID:0000I5] `Chatting`, [UID:000104] `ChattingUI`, and the source-tree paragraph.
  All other reviewed dependencies remain verification-only at same-or-greater detail.
- Confidence: high for exact range, ABI, liveness, callers, argument semantics, field
  unit/type, rectangle construction, virtual call shapes, scrollbar helper identities,
  current-layout route, owner/emitter, and source-ready behavior. The cap below perfect
  reflects stripped original private/local spellings, not an unresolved behavior or C++
  blocker.

## Supporting Research

- Mandatory live evidence was collected read-only on 2026-07-13 after a fresh MCP
  initialize, `idb_list`, and `server_health`. At evidence-collection time the adopted
  NexusTK database session was `160045b9`; health was `ok`, auto-analysis and Hex-Rays
  were ready, and the string cache was ready with 2,067 entries. These are time-scoped
  evidence observations, not a claim about later session availability.
- The IDB path was `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, the input image was
  `C:\Users\admin\Desktop\Clone\NexusTK\NexusTK.exe`, the image base was `0x400000`,
  and the input PE SHA256 was
  `9AEC210BBC5CE592176A21DD8E9D9FD8F250B8D9EA78237915A99BA8CFA9A632`.
- Live `lookup_funcs` returned `sub_47FBD0` at `0x0047fbd0`, size `0x9b`, and live
  disassembly returned 58 instructions ending in `retn 4`. The exact 155-byte target
  body SHA256 is
  `0dcc66f6dea573c9ca76792dba4e09c47e3c9a7072a47e5c84886e050715f48f`.
- Live analysis covered the target, both direct callers, target constructor and class
  layout evidence, `InitRectBounds`, the direct bounds-copy leaf, inherited Pane
  `SetBounds` and `InvalidateRect`, all four ScrollablePane helpers, the ChattingPane
  primary vtable, the active singleton route, both adjacent functions, and the current
  versus legacy `InitializeMainUiGraph` branches.
- Read-only documentation checks covered the target, ChattingPane, Chatting,
  ChattingUI, ChattingModifyHeightPane and both exact callers, ScrollablePane and its
  core, Pane/PaneLayout/PaneVtables, RectBounds class/file/layout/free-helper pages,
  `g_pChattingDisplayPane` semantic/storage pages, `g_useEpfAssets`, the generated
  `NexusTK/social/Chatting.cpp`, the source-tree proposal, ignored padding rows, and the
  relevant executed B001/B003/B005 reports.
- B003's historical 5.5 report established the correct class/file route, field unit,
  callers, and scroll helper direction. This report preserves those accepted facts but
  supersedes its source body where it omitted the live `0x004b8e00` call and used stale
  value/member forms for `SetBounds` and invalidation.
- The initial report-only pass modified no by-* page and used no lease or validator.
  Under the accepted callback, B002 modified only UID0002EW and the four named support
  pages, used and released one short lease per page, ran one scoped validator per page,
  and completed one final waited generated verification. No generated, coverage,
  tracker, supervisor, validator-state, IDA, or lifecycle artifact was edited manually.

## Target

- Target UID: `0002EW`.
- Target path:
  `by-memory/0x0047fbd0-0x0047fc6b.ChattingPaneSetVisibleRowCount.md`.
- Historical source queue/report row: validator command `000000009411`,
  `auto-generated/-ag-research-tracker.md`, `## by-memory` ->
  `### Not-Covered Files - Reconstructable`.
- Accepted callback classification: bounded implementation of C01-C30 is complete;
  neighboring UID0002EU and UID0002EV remained separate no-edit active scopes.
- Applied scores and parent state: `92/94`, semantic owner/emitter UID00001X
  `ChattingPane`, direct source-file ancestor UID0000I5 `Chatting`, exact aggregate
  context UID000104 `ChattingUI`.

## Current Target State

- Applied metadata: `COMPLETION:92`, `CONFIDENCE:94`,
  `CANONICAL_OWNER:00001X`, `RECONSTRUCTABLE:TRUE`,
  `EMITTER_UIDS:00001X`, blank `EMITTER_POSITION_OPTIONAL`, and `Nested:0`.
- Owner/emitter/reconstructable state is retained. The function is a live ordinary
  ChattingPane method and emits through the class and
  `NexusTK/social/Chatting.cpp` route.
- Historical pre-callback formal C++ was populated but not behavior-identical. It omitted the first
  `GetBounds(&currentBounds)` call even though live code executes it; it writes
  `SetBounds(viewport, false)` despite the binary and current Pane convention passing
  `&viewport`; and it invalidates `m_rect`, which is stale, instead of passing
  `&m_bounds` exactly as the binary does at `this+0x44`. The applied formal body corrects
  all three defects exactly.
- The target behavior text now identifies `13 * visibleRows`, viewport edges, two
  callers, the unused first rectangle local, exact virtual targets, target-body absence
  of a screen-mode branch, caller-side current-layout gating, data-route negatives,
  source-level `void`, and exact sync/current/max/apply order.
- Superseded assumptions include the historical FolderTreePane attachment, the old
  SetScrollRange/ResetScrollRange helper direction, value-shaped `SetBounds`, and
  `m_rect`; the target preserves each explicitly as corrected history.
- Related target/support docs checked are listed in `Evidence Checked` and the claim
  ledger. UID0002EU and UID0002EV were read only as adjacent boundary/context pages and
  remain outside this report's implementation ownership.
- B002's research, implementation, scoped validation, generated verification, and lease
  work are complete. Any current or future report path, count, validation, execution,
  move, or archive state is external validator/supervisor-owned and is not asserted.

## Executive Recommendation

- The direct semantic owner and emitter remain [UID:00001X] `ChattingPane`; the
  file route remains [UID:0000I5] `Chatting` at `NexusTK/social/Chatting.cpp`.
- The target remains one exact source-bearing method page. No split, merge, new child,
  compiler-only disposition, covered-by marker, or no-code exception is warranted.
- The target is `92/94`. The evidence resolves every assigned score and
  source-quality blocker, including the previously missing source operation and stale
  call syntax.
- `EMITTER_POSITION_OPTIONAL` remains blank. The ChattingPane child family uses
  blank positions and emits in the correct established order; assigning a lone numeric
  position would create unnecessary ordering drift.
- The exact formal managed block in this report is applied. It does not emit stack-cookie
  prologue/check, vtable mechanics, padding, or decompiler return artifact as source.
- Only target-specific facts were synchronized into class/file/aggregate/source-tree
  support. The separately assigned packet-router and paint pages were not edited, and
  ScrollablePane, RectBounds, Pane, global, and padding sources were not duplicated.

## Supervisor Active Recheck

- The initial instruction assigned report-only UID0002EW research, required fresh live
  IDA MCP, and prohibited by-* edits, leases, validators, and lifecycle/report execution
  during that phase. Gate 1 accepted exact report SHA
  `355E859956A0065BD4810762714F5319DB7313F027F07705D1525379E2F81022` before the
  bounded implementation callback.
- The assigned item does not require split repair. Live function boundaries, bytes, and
  adjacent padding exactly match the existing half-open page range.
- The only source-bearing item in this assignment is the existing exact target page.
  No additional child is needed. Every dependency needed to make the target body
  source-ready either already has a current accepted page or is resolved directly in
  this report.
- UID0002EU and UID0002EV are separately assigned. This report neither incorporates nor
  edits their active artifacts; the callback changed only the target and four named
  support pages.

## Inference Research Guidance Check

- The project workflow and `by-structure.md` require the exact executable method body
  to remain on the by-memory child, the semantic declaration/member ownership to remain
  on the class page, and the source-file route to remain on the by-file page. That
  structure rules out moving this body to callers or duplicating it on an aggregate.
- IDA fact, documentation evidence, and inference are kept separate. Addresses,
  instructions, bytes, xrefs, vtable cells, stores, branches, and call order are direct
  IDA facts. UID names and accepted helper contracts are documentation evidence.
  Private/local spellings and original file organization are source-facing inference.
- Existing generated and historical names were treated as uncertain. FolderTreePane,
  BackPane ownership of the target, `SetScrollRange`, `ResetScrollRange`, `m_rect`, and
  value-shaped `SetBounds` were rechecked rather than inherited.
- Wave2/Wave3 mentions were found in the caller class and current source-tree proposal.
  They were treated only as stale historical leads. Live MCP and current exact by-*
  pages control this recommendation.
- The generated `NexusTK/social/Chatting.cpp` was used only to identify the present
  output defect and expected callback verification; it was not treated as binary truth.

## Heuristic / Inference Reanalysis And Validation

### Exact range and ABI

- `lookup_funcs` and disassembly prove `0x0047fbd0-0x0047fc6b`, size `0x9b`, one
  modeled ordinary function, 58 instructions, one explicit 32-bit stack argument,
  `this` in `ECX`, and `retn 4`.
- Both callers push one integer visible-count argument and set `ECX` from
  `g_pChattingDisplayPane`. This is a nonvirtual direct member call, not a vtable entry,
  callback, thunk, or free function.
- IDA provisionally reports `int` because `EAX` survives the final invalidation and
  cookie check. Both callers immediately overwrite/ignore `EAX`, the established class
  declaration is a setter returning `void`, and no source branch computes a return.
  Source-facing `void` is therefore the highest-probability ABI-compatible type.

### Caller and argument semantics

- Caller `0x0048094a` in `sub_480890` computes
  `(710 - clampedY) / 13` after clamping Y to `50..650`, then enforces a minimum of four.
  It passes the same count to ChattingBackPane layout, this target, the handle rectangle,
  and config storage. The receiver is `g_pChattingDisplayPane`.
- Caller `0x00480b4f` in `sub_480AD0` starts with 40, accepts a requested value when it
  is at most 50, enforces a minimum of four, updates the back-pane viewport, calls this
  target with the same value, and updates the resize handle. Its sole direct caller at
  `0x004f7fd5` passes persisted chat visible-line count.
- These callers prove `visibleRows`/visible-line count semantics, one `int` parameter,
  no target-side need to clamp, and no source-significant return value. They are
  consumers and do not transfer ownership to ChattingModifyHeightPane.

### Current-layout route and screen/global disposition

- `InitializeMainUiGraph` enters the relevant construction path only under
  `byte_66DA97 == 1`, source-facing `g_useEpfAssets`. Inside that branch it allocates the
  0x138-byte ChattingPane, constructs ChattingModifyHeightPane, and calls
  `sub_480AD0` with the persisted visible-line count.
- A separate legacy ChattingPane construction path uses different initial bounds and
  does not construct/call the resize pane path that reaches this target.
- The target itself reads no `g_useEpfAssets`, `g_screenWidth`, `g_screenHeight`,
  `g_pScreenPane`, or other screen/layout global. It uses fixed current-layout edges
  `23, 710 - 13*n, 806, 710` because its only proven source route is already gated by
  the current-layout construction path.
- Neighboring scroll metric virtuals own their own current/legacy branches. Adding a
  second mode branch to this method would invent behavior not present in the binary.

### Field unit, layout, and name

- The target performs one dword store at `this+0x134`, exactly `13 * visibleRows`.
  Constructor allocation is `0x138`, placing this as the final four-byte class field.
- The current-layout constructor writes 104, exactly `8 * 13`, to the same field.
  `GetScrollRange` and `GetPageSize` divide it by 13. These independent producer and
  consumers prove an `int` pixel-height cache, not a row count, short, boolean, pointer,
  or padding.
- Retain `m_visibleChatPixelHeight`. It is descriptive/inferred rather than an original
  symbol, but it is more precise than `m_visibleRowCount`, `m_rowCount`, `field_134`, or
  a generic scroll extent.

### Rectangle locals and construction

- The stack frame has two distinct 16-byte locals: `[ebp-0x24]` receives the leading
  bounds copy and `[ebp-0x14]` receives `InitRectBounds`. They are not one reused local.
- The first `0x004b8e00` call copies inherited Pane bounds at `this+0x44` into the first
  local. The target never reads that local afterward. The call is nevertheless an
  observable out-of-line operation in the binary and must remain in behavior-identical
  source. `currentBounds` is the best bounded local name; `oldBounds` is plausible but
  less consistent with accepted caller pages.
- `InitRectBounds` at `0x004b7c50` writes four `int` edges in left/top/right/bottom
  order. The target pushes left 23, top `710 - 13*n`, right 806, and bottom 710.
- The second local is best named `viewport`. Width/height, x/y/width/height, Windows
  `RECT`, and a heap rectangle are rejected by the four-edge call and accepted
  `RectBounds` support.

### Pane virtual calls

- ChattingPane primary vtable base `0x00614ce0` has slot `+0x20 -> 0x00544800` and
  slot `+0x2c -> 0x00544bd0`.
- At `0x0047fc1c-0x0047fc21`, the target pushes zero, pushes the address of the viewport
  local, and dispatches `+0x2c`. Current accepted Pane docs identify this as
  `SetBounds(const RectBounds *, bool/int)`. The formal call must use `&viewport`.
- At `0x0047fc4e-0x0047fc56`, the target computes `this+0x44`, pushes that pointer, and
  dispatches `+0x20`. Current accepted Pane docs identify this as `InvalidateRect` over
  inherited `m_bounds`. The formal call must use `&m_bounds`; `m_rect`, a null pointer,
  the old local, and the viewport local are contradicted by the instruction operand.
- The second flag value is exactly zero and is best expressed as period-appropriate
  C++98 `false`. No redraw/notify branch exists in this body.

### Scroll helper identities, signatures, and order

- `0x0055e990` is `SyncScrollbars()`. It reads the class scroll metric virtuals,
  clamps/updates child scrollbar state, and recomputes viewport state.
- `0x0055e950` is `short GetScrollPosition(char axis)` and reads selected-child current
  position at child `+0xfe`; axis zero selects the vertical child.
- `0x0055e910` is `short GetScrollMax(char axis)` and reads selected-child maximum/target
  at child `+0x100`; axis zero again selects vertical.
- `0x0055eae0` is
  `ApplyScrollPosition(char axis, unsigned short oldPosition, unsigned short targetPosition)`.
  It no-ops when equal, stores the target, asks the virtual delta helper for old-before-new
  motion, then updates/clips rendering.
- The target calls sync, current, max, then apply with stack order axis 0, zero-extended
  current, zero-extended max. Reversed old/target, SetScrollRange, ResetScrollRange,
  UpdateScrollRange, or direct field assignment are rejected.
- `const unsigned short` locals are C++98-compatible and match both `movzx` operations
  and the apply helper's accepted parameter semantics. A `constexpr` axis constant is
  unnecessary and less period-appropriate than literal zero for this short body.

### Source-facing method and local names

- Retain `SetVisibleRowCount`: callers pass a visible line/row count while the method
  converts it to pixels. `SetVisiblePixelHeight` would misname the parameter contract;
  `ResizeChatViewport` would hide the public caller semantics; `SetLineCount` would
  collide with the caller method that clamps/persists input.
- Retain `visibleRows` in the target declaration/body. `visibleLineCount` is equally
  descriptive at callers, but changing the established class declaration is not needed
  to recover behavior.
- Use `currentBounds`, `viewport`, `currentPosition`, and `maximumPosition` for locals.
  These are inferred descriptive names, not original-symbol claims.

### Compiler, EH, allocation, and failure disposition

- The stack security cookie prologue/check is compiler output and must not become a
  handwritten statement.
- The target has no allocation, free, destructor, EH cleanup, null check, range check,
  status branch, string, packet field, screen-global read, or failure return.
- The bounds-copy output is unused, but removing the call would remove a real operation.
  Conversely, inventing a use of `currentBounds` would add behavior.
- The function is not a scalar/deleting destructor, adjustor thunk, vtable artifact,
  inline-only duplicate, or covered-by compiler body. It needs a real formal source body.

### Owner, emitter, and source route

- Receiver globals, constructor/destructor lifecycle, class layout, vtable family,
  contiguous ChattingPane method island, and both callers all support UID00001X.
- UID0000I5 `Chatting` remains the best existing source file and currently emits the
  class declaration and exact children under `NexusTK/social/Chatting.cpp`.
- A separate `ChattingPane.cpp` is plausible original organization but unsupported by
  current project routing; do not create a new by-file page for one method.
- ChattingModifyHeightPane, ScrollablePane, Pane, RectBounds, BackPane, and
  FolderTreePane are callers/dependencies/stale labels, not target owners.

### Rejected historical and generated alternatives

- FolderTreePane owner: rejected by receiver singleton, ChattingPane field offsets,
  constructor/vtable island, chat callers, and current by-file routing.
- BackPane target owner: rejected. `0x004b8e00` is a called shared bounds-copy leaf;
  its historical generated/documentation label does not transfer ownership of the
  caller at `0x0047fbd0`.
- `SetScrollRange`/`ResetScrollRange`: rejected by live `0x0055eae0` behavior and
  accepted ScrollablePane support.
- `m_visibleRowCount`: rejected for `this+0x134`; the stored unit is pixels.
- `SetBounds(viewport, false)`: superseded for this target by exact pointer ABI and
  current Pane source convention.
- `InvalidateRect(m_rect)`: rejected because the operand is exactly `this+0x44`, current
  inherited `m_bounds`.
- Omitting the leading bounds query: rejected because it is a live call in the exact
  target body, even though its local output is not subsequently consumed.

## Evidence Standards Used

- Highest-weight evidence: live IDA MCP function lookup, decompilation, full disassembly,
  exact bytes, function boundaries, stack frame, callers/xrefs, vtable bytes, direct
  helper bodies, constructor stores, caller-side global receivers, and current/legacy
  branch context.
- Corroborating evidence: current exact by-* pages, existing source-owner routes,
  accepted prior B-agent reports, generated output as defect evidence, and ignored
  padding records.
- Negative evidence: no target data xrefs, no absolute VA or RVA byte hits, no vtable
  entry for the target, no strings, no additional callers, no direct screen/layout
  global, no EH/allocation/free, and no in-range split.
- The evidence ladder is strong enough for a high-confidence first draft because every
  operation and argument is directly observed and all dependency roles have accepted
  support. Only original source spellings and exact historical file factoring remain
  unavailable.
- No fallback-only evidence was used. The mandatory target and support conclusions come
  from live IDA MCP session `160045b9`; local PE hashing is supplemental identity proof.

## Evidence Checked

- IDA MCP checks performed: fresh `idb_list`; `server_health`; `lookup_funcs` for target,
  both callers, rectangle/bounds/Pane/ScrollablePane helpers; `decompile` for target,
  callers, constructor, metrics, Pane helpers, and `InitializeMainUiGraph`; `disasm` for
  the target; `get_bytes` for target and adjacent boundaries; `xref_query` for target and
  singleton; `find_bytes` for target VA/RVA pointer encodings; `entity_query` for
  ChattingPane vtable names; and vtable byte inspection.
- Exact target checks: 155 bytes, 58 instructions, stack frame with two 16-byte locals,
  body SHA256, leading/trailing padding, all calls, virtual slots, stack argument,
  return lowering, and security cookie.
- Caller checks: `0x00480890` and `0x00480ad0` full decompiles, their exact call sites,
  count formulas/clamps, global receiver, config/handle coupling, and non-use of target
  return; `0x004f7d10` current/legacy construction context and persisted initialization.
- Documentation checked: UID0002EW, UID00001X, UID0000I5, UID000104, UID00001W,
  UID0002F6, UID0002F8, UID0000CF, UID0001GL, UID0000A2, UID0001VH, UID0003JA,
  UID0000BU, UID0000N2, UID00015S, UID0001VP, UID0002WX, UID0002WY, UID0000SW,
  UID000161, UID0002ES and its exact metric children, UID0002EY, current generated
  Chatting.cpp, ignored padding, source-tree proposal, and prior B001/B003/B005 reports.
- Negative checks performed: no target data xref, zero target VA/RVA byte hits, no
  target vtable route, no third caller, no target strings, no screen/layout global in the
  target, no target-side clamp/branch, no allocation/free/EH, and no code in the adjacent
  padding.
- Failed or unavailable checks: none that affect the recommendation. IDA database writes,
  validators, generated refreshes, lifecycle probes, and manual coverage/tracker edits
  were intentionally skipped because the report-only assignment prohibits them.

## Claim And Incorporation Ledger

| Claim ID | Claim | Confidence | Evidence | Destination doc/section | Action | Verification state |
| --- | --- | --- | --- | --- | --- | --- |
| C01 | Target becomes `92/94`; owner 00001X, reconstructable true, emitter 00001X, blank position, Nested 0 remain | High | Full target/caller/dependency audit | UID0002EW metadata/status/score | Applied | Verified in target header and command 000000009468 |
| C02 | Exact range is `0x0047fbd0-0x0047fc6b`, size `0x9b`, body SHA256 `0dcc66...f48f` | Exact | lookup/disasm/get_bytes/hash | UID0002EW raw evidence/item summary | Applied | Exact range/size/hash and alignment incorporated |
| C03 | Source ABI is ordinary `void __thiscall` member with one `int` argument and `retn 4` | High | disasm, both callers, return non-use | UID0002EW status/source shape | Applied | Target documents void source ABI and lowering distinction |
| C04 | Exactly two direct callers at `0x0048094a` and `0x00480b4f` pass visible-line counts through g_pChattingDisplayPane | Exact | xref_query and caller decompiles | UID0002EW caller inventory | Applied | Both callers and ignored EAX recorded |
| C05 | Target is current-layout-only by caller/construction route, not by an internal mode branch | High | `InitializeMainUiGraph` current/legacy decompile | UID0002EW behavior; class/file support | Applied | Target/class/file/aggregate distinguish external gate from target body |
| C06 | `this+0x134` is final dword `int m_visibleChatPixelHeight`, storing 13 times rows | High | target store, 0x138 allocation, ctor 104, metric division | UID0002EW; ChattingPane note | Applied | Layout, constructor value, and metric consumers incorporated |
| C07 | Leading `GetBounds(&currentBounds)` call and separate 16-byte local are mandatory despite no later local read | Exact behavior, inferred local name | target stack/disasm, 0x4b8e00 body | UID0002EW formal/behavior | Applied | Exact formal body and explanatory text verified |
| C08 | Viewport is a separate RectBounds with edges 23, 710-13*n, 806, 710 | Exact | stack frame and InitRectBounds call | UID0002EW formal/raw evidence | Applied | Separate viewport local and four edges verified |
| C09 | SetBounds call must pass `&viewport, false` through slot +0x2c -> 0x544bd0 | Exact | target disasm, vtable bytes, Pane helper | UID0002EW formal/behavior | Applied | Pointer form and virtual target verified in docs/generated output |
| C10 | Sync order begins with `SyncScrollbars()` at 0x55e990 after SetBounds | Exact | target disasm/helper decompile | UID0002EW formal/helper table | Applied | Exact post-bounds order verified |
| C11 | 0x55e950 is vertical `GetScrollPosition(0)`/current at child +0xfe | High | helper decompile and ScrollablePane docs | UID0002EW helper evidence | Applied | Current/old role and offset incorporated |
| C12 | 0x55e910 is vertical `GetScrollMax(0)`/maximum at child +0x100 | High | helper decompile and ScrollablePane docs | UID0002EW helper evidence | Applied | Maximum/target role and offset incorporated |
| C13 | 0x55eae0 is ApplyScrollPosition(axis, old/current, target/max), in that order | High | helper body, target pushes, accepted support | UID0002EW formal/helper evidence | Applied | Exact old-before-target call preserved; stale aliases rejected |
| C14 | Final invalidation must be `InvalidateRect(&m_bounds)` through +0x20 -> 0x544800 | Exact | target operand, vtable bytes, Pane docs | UID0002EW formal/behavior | Applied | Exact operand/slot/callee and generated line verified |
| C15 | No clamp, null/failure branch, allocation, free, EH, or screen-global access belongs in the target | Exact negative | complete 58-instruction body | UID0002EW negative/source notes | Applied | Complete negative disposition incorporated |
| C16 | Security cookie and virtual dispatch mechanics are compiler output, not handwritten source | Exact | target prologue/epilogue/vtable calls | UID0002EW compiler disposition | Applied | Compiler/linker lowering excluded from formal source |
| C17 | Retain source-facing `SetVisibleRowCount(int visibleRows)` and reject pixel-height/resize/caller-SetLineCount aliases | High | callers, field conversion, class declaration | UID0002EW naming; ChattingPane class note | Applied | Accepted name retained and alternatives rejected |
| C18 | Use currentBounds, viewport, currentPosition, maximumPosition and unsigned-short locals as bounded source names/types | High | stack/local use, movzx, support signatures | UID0002EW formal/source notes | Applied | Exact bounded names/types appear in target and generated output |
| C19 | Direct semantic owner/emitter remains UID00001X ChattingPane | High | object/vtable/global/caller/class-island evidence | UID0002EW metadata/ownership | Preserved | Target header and class/file route verified |
| C20 | Source route remains UID0000I5 Chatting, `NexusTK/social/Chatting.cpp` | High | by-file route and coherent chat island | UID0002EW/class/file | Preserved | File/class/aggregate/source-tree and generated route agree |
| C21 | No split/new child; 11-byte predecessor and 5-byte successor padding remain compiler/linker ignored bytes | Exact | get_bytes, adjacent lookup, -ignored | UID0002EW range notes; UID000104 | Applied/no-edit | Target and aggregate synchronized; ignored page unchanged |
| C22 | Target has two code xrefs, zero data xrefs, and zero raw VA/RVA pointer hits | Exact | xref_query/find_bytes | UID0002EW liveness/negative evidence | Applied | Full liveness disposition incorporated |
| C23 | FolderTreePane, BackPane target ownership, Set/ResetScrollRange, m_visibleRowCount, value SetBounds, and m_rect are rejected/superseded | High | live target/support audit | UID0002EW historical section; source tree | Applied additively | Historical assumptions retained and explicitly superseded |
| C24 | Destination 1 exact managed block is the only target C++ recommendation | High | all preceding claims | UID0002EW formal block | Applied exactly | Managed lines/body and generated target definition verified |
| C25 | ChattingPane declaration already matches; add target precision without score or formal-block change | High | callback-time class `91/93` and declaration | by-class/ChattingPane.md | Text-only sync applied | Command 000000009470 ok; `91/93` and formal block preserved |
| C26 | Chatting file route remains; add B002 correction note without score change | High | callback-time by-file `87/90` and generated route | by-file/Chatting.md | Text-only sync applied | Command 000000009471 ok; `87/90`/path preserved; two unrelated 0003YK warnings |
| C27 | ChattingUI exact row/range remains; add target source-shape/current-layout detail without score change | High | aggregate boundary and target audit | by-memory/0x0047efb0-0x00483ef7.ChattingUI.md | Text-only sync applied | Command 000000009473 ok; aggregate `88/93`/formal block preserved |
| C28 | Current source-tree line 1403 must supersede stale Wave2/Wave3 FolderTreePane attachment | High | live owner/caller/file evidence | by-project-structure/proposed-source-tree.md | Paragraph replaced | Command 000000009475 ok; durable UID00001X/UID0000I5/UID0000JG route recorded |
| C29 | ScrollablePane, Pane, RectBounds, callers, globals, and ignored padding are verification-only, same-or-greater support | High | direct doc comparison and live support checks | Listed support docs | Verified no-edit | No callback drift contradicted C01-C30; no scope expansion |
| C30 | Callback verification must validate each changed ordinary by-* page, then wait for generated output and verify one UID0002EW body with no target Empty Emitter Marker | High | workflow and generated output | Validator Results/checklist | Completed | Commands 000000009468, 000000009470, 000000009471, 000000009473, and 000000009475 plus waited 000000009476; generated header 000000009477 |

## Positive Evidence Summary

- The exact target is modeled, bounded, and hashed; both adjacent gaps are pure
  `0xcc`, so no hidden child or range repair is needed.
- Both direct callers use `g_pChattingDisplayPane` and pass independently derived visible
  line counts. Constructor, destructor, field, and vtable evidence all converge on
  ChattingPane.
- The dword field is initialized as 104, rewritten as 13 times count, and divided by 13
  by two metric virtuals. Its unit and type are resolved.
- The target's complete call chain is direct and deterministic: bounds copy, pixel-height
  store, rectangle initialization, SetBounds, SyncScrollbars, current, max, apply,
  InvalidateRect.
- Vtable bytes and live helper bodies resolve both inherited Pane virtuals and all four
  ScrollablePane helpers; no unresolved helper alias remains.
- Current/legacy graph construction explains why the target has fixed current-layout
  constants and no mode-global read.
- Existing class and file routes already clear the gate, and the current generated file
  proves the target emits from the expected source path once its formal block is fixed.

## IDA MCP Facts

- Function/range facts: `sub_47FBD0`, start `0x0047fbd0`, size `0x9b`, exclusive end
  `0x0047fc6b`, 58 instructions, `retn 4`, one `int` stack argument, two 16-byte locals,
  security cookie, and body SHA256 `0dcc66...f48f`.
- Data/table/padding facts: predecessor OnPaint ends `0x0047fbc5`; eleven `0xcc` bytes
  occupy `0x0047fbc5-0x0047fbd0`; five `0xcc` bytes occupy
  `0x0047fc6b-0x0047fc70`; successor starts `0x0047fc70`.
- Xref facts: exactly two code xrefs at `0x0048094a` and `0x00480b4f`; zero data xrefs;
  zero `d0 fb 47 00` VA and `d0 fb 07 00` RVA byte hits.
- Vtable/global/type facts: ChattingPane primary table `0x00614ce0`; `+0x20` resolves to
  Pane invalidation `0x00544800`; `+0x2c` resolves to Pane SetBounds `0x00544bd0`;
  receiver singleton storage `0x0067adcc` has 20 lifecycle/consumer refs; allocation is
  312 bytes; target field is dword `+0x134`.
- Negative IDA facts: no target vtable cell, target data pointer, target string, internal
  branch, screen/layout global, allocation/free/EH path, or extra caller.

## Function / Child Inventory

| Range / Item | UID / Path | Role | Reconstructable | Direct Parent | Score | Status |
| --- | --- | --- | --- | --- | --- | --- |
| `0x0047f8d0-0x0047fbc5` | UID0002EV ChattingPaneOnPaint | Exact predecessor, separately assigned | True | UID00001X | `86/90` at research read | Boundary/read-only; no B002 edit |
| `0x0047fbc5-0x0047fbd0` | by-memory/-ignored.md row | 11-byte alignment | No source | None | N/A | Correct, no edit |
| `0x0047fbd0-0x0047fc6b` | UID0002EW target | Ordinary visible-row layout method | True | UID00001X | `86/90 -> 92/94` | Exact source-bearing target |
| `0x0047fc6b-0x0047fc70` | by-memory/-ignored.md row | 5-byte alignment | No source | None | N/A | Correct, no edit |
| `0x0047fc70-0x0047fd3b` | UID0002EX ChattingPaneComputeLineCount | Exact successor | True | UID00001X | `90/92` | Read-only support |
| `0x0047f520-0x0047f6e5` | UID0002ES and UID0004J8-UID0004JD | Scroll metric index/exact children | Mixed index plus exact source children | UID00001X | `92/93` | Same-or-greater support |
| `0x0055e910/50/990/ae0` | UID0001GL ScrollablePaneCore | Max/current/sync/apply dependencies | True aggregate support | UID0000CF | `88/90` | Same-or-greater support |
| `0x004b7c50` | UID00015S RectGeometryHelpers | InitRectBounds | True | UID0000N2 | `90/91` | Same-or-greater support |
| `0x004b8e00` | UID000161 BackPaneGetBounds historical route | Direct 16-byte inherited-bounds copy leaf | True | UID00000S | `87/91` | Dependency only; no target ownership |
| `0x00544800/0x00544bd0` | Pane/PaneVtables/PaneLayout | InvalidateRect/SetBounds | True support | UID0000A2 | same-or-greater | Same-or-greater support |

## Direct Xref / Caller Inventory

| Address / Item | Xref / Caller / Callee | Meaning |
| --- | --- | --- |
| `0x0048094a` | `sub_480890` -> target | Drag-release commit passes computed/clamped visibleLineCount through g_pChattingDisplayPane; return unused |
| `0x00480b4f` | `sub_480AD0` -> target | SetLineCount passes persisted/requested count after 4/min and 50/fallback policy; return unused |
| `0x004f7fd5` | InitializeMainUiGraph -> sub_480AD0 | Current-layout initialization passes persisted chat line count |
| `0x0047fbe8` | target -> `0x004b8e00` | Copies inherited current bounds into first local; local later unused |
| `0x0047fc0f` | target -> `0x004b7c50` | Initializes viewport RectBounds edges |
| `0x0047fc21` | target -> vslot `+0x2c` | SetBounds with `&viewport`, zero/false |
| `0x0047fc26` | target -> `0x0055e990` | SyncScrollbars |
| `0x0047fc2f` | target -> `0x0055e950` | Get vertical current position |
| `0x0047fc3b` | target -> `0x0055e910` | Get vertical maximum |
| `0x0047fc49` | target -> `0x0055eae0` | Apply vertical current as old and maximum as target |
| `0x0047fc56` | target -> vslot `+0x20` | Invalidate inherited `&m_bounds` |
| target start | xref_query data / find_bytes VA/RVA | No data/vtable/pointer route; ordinary direct-call method only |

## Documentation Evidence And IDA Status

- UID00001X already declares `ChattingPane : public ScrollablePane`,
  `SetVisibleRowCount(int visibleRows)`, and final `int m_visibleChatPixelHeight`; live
  evidence validates all three target-facing declarations.
- UID0000I5 already routes the class and exact child to `NexusTK/social/Chatting.cpp`.
  Its historical B003 note is correct on ownership and helper roles but does not contain
  this report's exact formal-body corrections.
- UID0002F6 and UID0002F8 already preserve both target call sites and line-count policy.
  No target-specific formal change is required on those pages.
- UID0000CF/UID0001GL and UID0002EY resolve current/max/apply names and argument order;
  the stale Set/ResetScrollRange interpretation is already historical.
- UID0000A2/UID0001VH/UID0003JA resolve `m_bounds`, InvalidateRect, and SetBounds. Newer
  exact Pane consumers use pointer-shaped rectangle calls, superseding older value-shaped
  chat formal text.
- UID0000BU/UID0000N2/UID00015S/UID0001VP resolve 16-byte RectBounds and exact edge order.
- UID0002WX/UID0002WY resolve `g_pChattingDisplayPane` and its storage/lifecycle route.
- Current generated `NexusTK/social/Chatting.cpp` emits exactly one UID0002EW body, but
  that body currently has the same three source defects as the target formal block. It
  is read-only evidence for expected post-callback verification.
- `by-project-structure/proposed-source-tree.md` still has one current-facing paragraph
  saying Wave2/Wave3 attaches the chat subset to FolderTreePane. That sentence is stale
  against current exact pages and must be superseded during callback.

## Ranked Ownership Analysis

### 1. UID00001X ChattingPane through UID0000I5 Chatting

- Evidence for: exact class method island, `g_pChattingDisplayPane` receiver at both
  callers, constructor/destructor lifecycle, 0x138 object size, final +0x134 field,
  ChattingPane vtable, class declaration, chat-layout semantics, and current generated
  source route.
- Evidence against: only stripped original symbol/file names. No behavioral or routing
  contradiction.
- Decision: accepted direct semantic owner/emitter and source route.

### 2. UID00001W ChattingModifyHeightPane

- Evidence for: contains both direct use contexts and computes/clamps the argument.
- Evidence against: calls through a separate global ChattingPane receiver and has its own
  object layout/vtable. It consumes the method rather than implementing it.
- Decision: caller/support only; reject ownership transfer.

### 3. ScrollablePane, Pane, and RectBounds support families

- Evidence for: own the invoked base helpers, virtual contracts, fields, and rectangle
  type.
- Evidence against: none owns the ChattingPane-specific pixel-height field, fixed chat
  viewport constants, or direct callers.
- Decision: dependencies only; preserve existing pages and avoid duplicate target source.

### 4. FolderTreePane and BackPane historical/generated candidates

- Evidence for: old generated ownership attached chat methods to FolderTreePane;
  `0x004b8e00` has a historical BackPane source-facing page.
- Evidence against: target receiver, layout, vtable, callers, source island, and all
  current exact pages are ChattingPane-specific. A callee's historical label cannot own
  its caller.
- Decision: rejected/superseded aliases retained only for provenance and searchability.

### Proposed new file/grouping, if applicable

- Proposed owner/name/path: not applicable. Retain UID0000I5
  `NexusTK/social/Chatting.cpp`.
- Likely full contents: existing ChattingPane and related chat UI family already listed
  on UID0000I5.
- Candidate related items that belong: this exact target under UID00001X.
- Candidate related items rejected: caller methods, ScrollablePane/Pane/RectBounds
  helpers, padding, FolderTreePane, and a one-method `ChattingPane.cpp` split.
- Standalone, narrow, or broad source-file inference: current broad Chatting module route
  remains the strongest project-supported placement.

## Source Placement

- Recommended placement: exact body on UID0002EW, semantic class declaration/child
  expansion through UID00001X, source file through UID0000I5 at
  `NexusTK/social/Chatting.cpp`.
- This placement fits the contiguous chat UI island, constructor/global lifecycle,
  caller feature, existing source tree, and current generated output.
- Rejected placements: ChattingModifyHeightPane.cpp because it only calls the method;
  ScrollBar.cpp because it only supplies base helpers; RectBounds.cpp because it only
  supplies geometry; BackPane.cpp because `0x004b8e00` is only a callee; FolderTreePane
  because the generated attachment is contradicted; and a new ChattingPane.cpp because
  no current source-route evidence requires it.
- Remaining placement uncertainty: original header/source factoring is stripped, but it
  does not affect the accepted current project route or emitted behavior.

## Range / Split / Padding / Reclassification Analysis

- Exact target range is already correct and half-open: `0x0047fbd0-0x0047fc6b`.
- Predecessor UID0002EV ends at `0x0047fbc5`; the 11-byte gap through `0x0047fbd0` is
  all `0xcc` and already recorded as ignored compiler/linker alignment.
- Successor UID0002EX starts at `0x0047fc70`; the 5-byte gap from `0x0047fc6b` is all
  `0xcc` and already recorded as ignored alignment.
- The target contains one modeled basic block/function body with no internal padding,
  jump table, literal pool, nested function, EH funclet, table, or source-bearing split.
- No child was created, repaired, merged, or ignored; `Nested:0` remains.
- No parent/container metadata change is needed. UID000104 remains aggregate context,
  UID00001X remains direct owner, and UID0000I5 remains file route.

## Negative Evidence Summary

- No target data xref, vtable entry, VA pointer hit, RVA pointer hit, callback table,
  export, relocation route, or third caller was found.
- No string/resource, packet field, allocation, free, EH cleanup, destructor, or target
  return consumer was found.
- No direct target read of `g_useEpfAssets`, screen width/height, g_pScreenPane, or any
  mode/screen global was found. Mode selection occurs in the construction/caller route.
- No target-side input clamp was found; both callers own the range policy.
- No evidence supports a stored row count at +0x134, a value/width-height rectangle,
  reversed scroll arguments, or invalidating any rectangle other than `this+0x44`.
- Consumer xrefs from ChattingModifyHeightPane do not prove caller ownership. Inherited
  helper calls do not prove Pane/ScrollablePane/RectBounds ownership of this method.
- Nearby OnPaint/ComputeLineCount methods and padding do not belong inside the target.
- Existing Wave2/Wave3 and generated FolderTreePane labels were not accepted as current
  source evidence.

## IDA Rename / Type / Comment Recommendations

- Proposed source-facing target name: `ChattingPane::SetVisibleRowCount`; IDA raw name
  `sub_47FBD0` remains an evidence label only.
- Proposed argument/type: source `void` member with `int visibleRows`; IDA's `_DWORD`
  and provisional `int` return are decompiler artifacts.
- Proposed field: `int m_visibleChatPixelHeight` at `+0x134`.
- Proposed locals: `RectBounds currentBounds`, `RectBounds viewport`,
  `const unsigned short currentPosition`, and
  `const unsigned short maximumPosition`.
- Proposed helpers/comments: `GetBounds`, `InitRectBounds`, `SetBounds`,
  `SyncScrollbars`, `GetScrollPosition`, `GetScrollMax`, `ApplyScrollPosition`, and
  `InvalidateRect`; record axis 0 as vertical and current-before-maximum apply order.
- Keep `0x004b8e00`'s existing page/IDA label unchanged in this assignment. The target
  needs the source-facing call syntax but does not justify reowning or renaming that
  shared historical leaf.
- Keep exact original private/local spellings explicitly inferred. Do not claim symbol
  recovery.
- IDA DB edits were not requested or made; no rename, type application, or comment write
  was performed by B002.

## First-Draft C++ Recommendation

- Eligible for draft C++: yes. The target is live source-authored project code with exact
  behavior, arguments, dependency contracts, and source route.
- Applied code: Destination 1, exact current text in UID0002EW's formal managed block:

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
void ChattingPane::SetVisibleRowCount(int visibleRows)
{
    RectBounds currentBounds;
    GetBounds(&currentBounds);

    m_visibleChatPixelHeight = 13 * visibleRows;

    RectBounds viewport;
    InitRectBounds(&viewport, 23, 710 - m_visibleChatPixelHeight, 806, 710);
    SetBounds(&viewport, false);

    SyncScrollbars();

    const unsigned short currentPosition = GetScrollPosition(0);
    const unsigned short maximumPosition = GetScrollMax(0);
    ApplyScrollPosition(0, currentPosition, maximumPosition);

    InvalidateRect(&m_bounds);
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

- This preserves every observed source-level operation in exact order and does not add a
  branch, failure path, return, allocation, cleanup, or mode check.
- It matches a plausible mid-2000s C++ source shape: C++98 `false`, stack POD locals,
  pointer arguments, literal axis zero, ordinary `const unsigned short` locals, no
  `auto`, no lambda, and no `constexpr`.
- Inferred source-facing names replace only decompiler labels: `visibleRows`,
  `currentBounds`, `viewport`, `m_visibleChatPixelHeight`, `currentPosition`,
  `maximumPosition`, and accepted Pane/ScrollablePane helper names.
- The naming convention matches current ChattingPane and related caller declarations:
  `m_` members, lower-camel parameters/locals, PascalCase methods, pointer-form
  RectBounds helpers, and explicit `false` for the bounds flag.
- The historical pre-callback body was not sufficient because it omitted a real call and
  used two stale operand forms. Blank/no-code output remains rejected because the target
  is a live source-authored ordinary method.
- Third-party import directive: not applicable; this is NexusTK project code, not a
  vetted static third-party embed.

## Final Recommendation

- C01-C30 are applied without compression under the accepted bounded callback.
- UID0002EW is `92/94`; UID00001X owner/emitter, true reconstructable, blank position,
  and Nested 0 are preserved. Destination 1 is the exact formal body, and the item
  summary, exact evidence, current-layout route, helper contracts, negative evidence,
  score rationale, and additive B002 change record are synchronized.
- All valid prior B003 research remains historical provenance, while the omitted bounds
  call, value-shaped SetBounds, and m_rect invalidation are labeled superseded.
- Text-only, score-neutral target synchronization is complete on UID00001X, UID0000I5,
  and UID000104; their formal blocks and stronger callback-time scores were preserved.
- The stale FolderTreePane/Wave paragraph now carries durable exact owner/file routing.
- Caller pages, ScrollablePane, Pane, RectBounds, singleton/mode globals, ignored
  padding, UID0002EU, and UID0002EV are unchanged because no callback drift contradicted
  C01-C30.
- No ownerless/non-emitting item, implementation item, validation item, lease, or
  generated-verification blocker remains in B002's bounded callback scope.

## Recommended Target Doc Changes

- Target path:
  `by-memory/0x0047fbd0-0x0047fc6b.ChattingPaneSetVisibleRowCount.md`.
- Applied report facts: C01-C24, all target-specific live MCP facts,
  caller/global/current-layout evidence, field/layout proof, exact helper table/order,
  range/padding negatives, compiler disposition, and score rationale.
- Metadata: changed historical `86/90` to `92/94`; retained owner 00001X, true reconstructable,
  emitter 00001X, blank position, and Nested 0.
- Formal C++: Destination 1 is applied exactly with all three
  literal managed header/begin/end lines.
- Item Summary: the target-specific summary records
  the live ordinary method, two callers, two rectangle locals, pixel-height store,
  pointer-shaped bounds/invalidation, vertical current/max/apply order, exact alignment,
  and rejected stale aliases without repeating generated metadata fields.
- Body text: raw instruction register/address details, source `void`,
  first bounds local, current-layout caller gate, exact virtual targets, target-route
  negatives, and no-added mode/clamp/failure logic are incorporated.
- Historical/stale assumptions preserved: FolderTreePane generated pollution,
  Set/ResetScrollRange aliases, prior B003 5.5 recommendation, and old m_rect/value
  forms, each explicitly labeled superseded rather than silently deleted.

## Recommended Support Doc Changes

- `by-class/ChattingPane.md`: callback-time `91/93`, owner/file route, and formal
  declaration remain unchanged. The B002 target note covers the leading bounds copy,
  fixed current-layout route, pointer-shaped SetBounds and invalidation, exact helper
  order, and UID0002EW `92/94`; UID0002EU/UID0002EV were not touched.
- `by-file/Chatting.md`: callback-time `87/90` and proposed path remain unchanged. The
  additive B002 note supersedes only UID0002EW body defects in the historical B003
  paragraph and confirms exact emission through the existing ChattingPane child route.
- `by-memory/0x0047efb0-0x00483ef7.ChattingUI.md`: aggregate `88/93` metadata and
  formal block remain unchanged. Its UID0002EW row/change note carries exact
  body/current-layout/caller/helper facts without duplicating the formal body.
- `by-project-structure/proposed-source-tree.md`: the stale current-facing
  FolderTreePane/Wave statement is replaced by durable text stating that the historical
  FolderTreePane attachment is superseded; ChattingPane methods are owned by UID00001X,
  file-local packet helpers by UID0000I5, all routed through `social/Chatting.cpp`, while
  filesystem tree-control code remains UID0000JG.
- Verification-only, no edit: UID00001W, UID0002F6, UID0002F8, UID0000CF,
  UID0001GL, UID0000A2, UID0001VH, UID0003JA, UID0000BU, UID0000N2, UID00015S,
  UID0001VP, UID000161, UID0002WX, UID0002WY, UID0000SW, UID0002ES/exact children,
  UID0002EY, and by-memory/-ignored.md.
- UID0002EU and UID0002EV: verified explicit no-edit due separate active assignment ownership.

## Score And Metadata Recommendation

- Historical pre-callback target: `86/90`, owner 00001X, reconstructable true, emitter
  00001X, blank position, Nested 0, populated but defective formal C++.
- Applied target: `92/94`, with every metadata field except completion/confidence
  unchanged and exact formal C++ installed.
- Completion rationale: exact range/ABI, both callers, screen/global route, field
  unit/type/layout, both rectangle locals, all helper identities/signatures/order,
  virtual operands, owner/emitter/file route, compiler disposition, and behavior-identical
  C++ are resolved. The page becomes implementation-complete for its bounded method.
- Confidence rationale: direct live evidence supports every behavior and operand, with
  independent docs for every dependency. Confidence stops at 94 because original
  method/private/local/header spellings are stripped and `GetBounds`' historical source
  declaration placement remains inferred; neither uncertainty affects behavior.
- Blocker attempt 1, omitted first call: full disassembly and stack-frame analysis prove
  the call and distinct local; resolved by adding it exactly.
- Blocker attempt 2, rectangle type/order: live initializer plus RectBounds support prove
  four-int left/top/right/bottom; resolved.
- Blocker attempt 3, SetBounds shape: live push operands, vtable bytes, callee body, and
  current Pane docs prove pointer plus zero; resolved.
- Blocker attempt 4, invalidation target: live `lea this+0x44`, vtable bytes, PaneLayout,
  and PaneSetMode precedent prove `&m_bounds`; resolved.
- Blocker attempt 5, scroll names/order: live helper bodies and accepted ScrollablePane
  family prove sync/current/max/apply and old-before-target; resolved.
- Blocker attempt 6, field name/unit: constructor, allocation size, target store, and
  metric division prove final int pixel height; resolved.
- Blocker attempt 7, screen-mode behavior: target negative plus MainUiGraph branch prove
  caller-side current-layout gating; resolved without inventing a branch.
- Blocker attempt 8, source return/type: `retn 4`, both callers, setter semantics, and
  declaration prove void/int; resolved.
- Blocker attempt 9, owner/source: singleton, class island, vtable, callers, and current
  file route reject FolderTreePane/caller/dependency alternatives; resolved.
- Blocker attempt 10, liveness/split: two code xrefs, no data route, exact bytes, and
  adjacent padding prove live ordinary method/no split; resolved.
- Support scores remain at their stronger callback-time values because target-specific
  facts do not alter their broader established scope; no support page is a blocker.

## Open Questions With Attempted Resolution

- Question: is `this+0x134` a row count or pixel height? Constructor value 104, target
  multiplication by 13, and two metric divisions by 13 prove pixel height. Resolved.
- Question: should the method clamp input? Both callers own clamp policy and the target
  has no branch. No target clamp should be added. Resolved.
- Question: why does the method use fixed current-layout constants without reading mode?
  MainUiGraph constructs/reaches the resize path only under `g_useEpfAssets == 1`; the
  legacy branch uses a different UI path. Resolved.
- Question: is the leading bounds copy dead compiler noise? It is an out-of-line source
  call with a distinct output local. Its output is unused, but the operation is live and
  cannot be omitted from behavior-identical source. Resolved.
- Question: pointer or value/reference SetBounds syntax? Exact stack operand and current
  accepted Pane method convention support pointer syntax for this reconstruction.
  Resolved.
- Question: `m_rect` or `m_bounds`? Exact operand is `this+0x44`; current PaneLayout names
  it inherited `m_bounds`/local bounds, and current formal convention uses `m_bounds`.
  Resolved to `&m_bounds`.
- Question: signed or unsigned local scroll positions? Getters return in AX and caller
  zero-extends both before the unsigned-short apply contract; use unsigned short locals.
  Resolved.
- Question: source return type? No caller consumes EAX and the established setter
  declaration is void. Resolved to void.
- Question: original local/private spellings? Exhaustive live binary and documentation
  checks cannot recover stripped local symbols. The selected names are high-probability
  descriptive source names and impose only the confidence cap from 95 to 94; they do not
  block C++.
- Questions remaining unresolved with behavior/score/C++ impact: none. Original header
  factoring and exact private spellings are bounded nonblocking uncertainty, not deferred
  research work.

## Exact Manual Supervisor-Owned Coverage Or Tracker Text

- Not applicable. The target's auto-generated tracker/coverage rows are validator-owned
  and must not be edited manually.
- By-memory generated summary improvement flowed from the target page's updated
  `Item Summary`, metadata, and completed validator-generated refresh.
- No manual `-coverage-report.md`, tracker, supervisor, or validator-state text was
  applied or needed.

## Follow-Up Actions

- B002's C01-C30 implementation, scoped validators, generated verification, and lease
  releases are complete; no accepted callback item remains unapplied.
- Final read-only generated verification found exactly one UID0002EW marker and one
  `ChattingPane::SetVisibleRowCount` definition in
  `auto-generated/NexusTK/social/Chatting.cpp`, with the leading GetBounds call, pointer
  SetBounds, current/max/apply order, `InvalidateRect(&m_bounds)`, target score `92/94`,
  and no UID0002EW Empty Emitter Marker or duplicate body.
- No A-agent action, new child allocation, new report, IDA edit, manual coverage/tracker
  edit, or additional B002 implementation work is needed for this callback.
- Current or future report path, count, validation, execution, move, and archive state
  remain external validator/supervisor-owned and are not asserted by this artifact.

## Confidence

- Recommendation confidence: high (`94`) because the full body, callers, route, fields,
  helper contracts, and negatives are live-verified.
- Score confidence: high; `92/94` is proportionate to a small exact source-bearing method
  with behavior-complete first draft and stripped original names.
- Remaining uncertainty: exact original private/local spellings and historical source/header
  split only. Neither changes generated behavior, ownership, or implementation readiness.

## Validator Results

- Initial report-only commands: none, as required before the callback.
- Target scoped validator: `python .\tools\validator.py --mode file --file
  by-memory/0x0047fbd0-0x0047fc6b.ChattingPaneSetVisibleRowCount.md --apply
  --queue-timeout 240`; command `000000009468`, timestamp
  `2026-07-13T07:46:31-04:00`, exit `0`, `ok: 1`. It applied completion/confidence,
  registry hash, two link/index normalizations, projected-stat updates, and deferred
  generated refresh.
- ChattingPane scoped validator: same command shape for `by-class/ChattingPane.md`;
  command `000000009470`, timestamp `2026-07-13T07:47:18-04:00`, exit `0`,
  `ok: 1`, projected-stat update, generated refresh deferred, no warning.
- Chatting scoped validator: same command shape for `by-file/Chatting.md`; command
  `000000009471`, timestamp `2026-07-13T07:48:19-04:00`, exit `0`, `ok: 1`,
  projected-stat update, generated refresh deferred. It repeated two pre-existing
  `missing_ref_uid 0003YK` warnings unrelated to UID0002EW.
- ChattingUI scoped validator: same command shape for
  `by-memory/0x0047efb0-0x00483ef7.ChattingUI.md`; command `000000009473`, timestamp
  `2026-07-13T07:49:46-04:00`, exit `0`, `ok: 1`, projected-stat update, generated
  refresh deferred, no warning.
- Source-tree scoped validator: same command shape for
  `by-project-structure/proposed-source-tree.md`; command `000000009475`, timestamp
  `2026-07-13T07:50:12-04:00`, exit `0`, `ok: 1`, one reference-index addition,
  projected-stat update, generated refresh deferred. It repeated seven pre-existing
  missing-reference warnings: UID0003LP, UID00036Q twice, and UID0003WL/0003WM/0003WN/
  0003WO; none is introduced by or specific to UID0002EW.
- Final waited command: `python .\tools\validator.py --mode file --file
  by-memory/0x0047fbd0-0x0047fc6b.ChattingPaneSetVisibleRowCount.md --apply
  --queue-timeout 240 --wait-generated`; command `000000009476`, timestamp
  `2026-07-13T07:50:38-04:00`, exit `0`, `ok: 1`, `generated_refresh: completed`.
  The broad refresh rebuilt validator-owned registry/generated metadata and repeated
  project-wide unrelated aggregate warnings (`14` fallback child inserts, `83` missing
  child markers, `207` emitters with no direct code).
- Generated `auto-generated/NexusTK/social/Chatting.cpp` header records
  `validator-command-id: 000000009477` and
  `validator-refreshed-at: 2026-07-13T07:51:01-04:00`. Read-only inspection found one
  UID0002EW marker, one target definition, one target-local leading GetBounds call,
  exact pointer SetBounds/current-max-apply/invalidation lines, and zero target Empty
  Emitter Markers.
- MCP result: mandatory live research succeeded on evidence-time IDB session `160045b9`;
  no fallback-only target evidence was used.
- Target-specific validator errors or warnings: none. The pre-existing unrelated
  missing-reference and broad generated warnings above remain validator-owned.
- Lease results: B002 leased only the target, ChattingPane, Chatting, ChattingUI, and
  proposed-source-tree page immediately before each edit; every lease command succeeded,
  and each lease was released immediately after that page's scoped validator. Final
  `tools/leaser/Agents/current_leases.md` inspection showed no active leases.

## Changed Files

- B002 callback artifact modified during this work (path at preparation time):
  `tools/leaser/Agents/Agent-B002/research/0002EW-ChattingPaneSetVisibleRowCount-source-quality.md`.
- Manually modified under short released leases:
  `by-memory/0x0047fbd0-0x0047fc6b.ChattingPaneSetVisibleRowCount.md`,
  `by-class/ChattingPane.md`, `by-file/Chatting.md`,
  `by-memory/0x0047efb0-0x00483ef7.ChattingUI.md`, and
  `by-project-structure/proposed-source-tree.md`.
- Explicit no-edit active scopes: UID0002EU
  `by-memory/0x0047f890-0x0047f8c9.ChattingPaneChatPacketRouter.md` and UID0002EV
  `by-memory/0x0047f8d0-0x0047fbc5.ChattingPaneOnPaint.md`.
- Validator-owned side effects: registry/reference/projected-stat metadata and generated
  outputs refreshed by the recorded validator commands. No generated, coverage,
  tracker, supervisor, validator-state, lifecycle, or IDA artifact was edited manually.
- Renamed: none.
- Report execution: not run. No execute_report, lifecycle probe/action, report move, or
  archive command was run.

## Implementation Tracking Checklist

Initial report-only pass:

- [x] Supervisor Gate 1 validation completed before implementation for exact SHA `355E8599...F81022`.
- [x] Target/support docs updated: UID0002EW, UID00001X, UID0000I5, UID000104, and the
      one stale current source-tree paragraph; all listed dependencies verification-only.
- [x] Current target state and actual evidence checked recorded.
- [x] Claim And Incorporation Ledger updated with destination and verification state for
      every accepted claim C01-C30.
- [x] Metadata/score applied: UID0002EW `86/90 -> 92/94`; all other metadata
      preserved.
- [x] Score-limiting blockers researched to resolution, implementation-ready repair, or
      rare exact no-improvement proof.
- [x] Owner/emitter/reconstructable state retained: 00001X/00001X/TRUE and blank
      position; no owner transfer.
- [x] Split/rename/new-child changes: none; exact range and padding retained.
- [x] Source-placement, range/split/padding/reclassification, and IDA rename/type/comment
      dispositions applied or confirmed not applicable.
- [x] First-draft C++ applied exactly from Destination 1 with all literal managed lines.
- [x] Third-party import directive confirmed not applicable; target is NexusTK project
      code and the formal block is direct source, not an import.
- [x] Exact target/support doc facts incorporated at report-level detail.
- [x] Historical/stale assumptions, rejected alternatives, and negative evidence
      preserved additively.
- [x] Wave2/Wave3 mentions encountered and superseded as stale current ownership evidence.
- [x] Open questions closed or documented as bounded evidence-backed uncertainty.
- [x] One scoped validator run per changed ordinary by-* page under short released leases.
- [x] Final authorized `--wait-generated` refresh verifies one exact UID0002EW body and no
      target Empty Emitter Marker or duplicate.

Implementation callback pass:

- [x] Report accepted by supervisor for implementation at exact Gate 1 SHA.
- [x] C01-C30 and all accepted target/support details incorporated without compression.
- [x] Claim And Incorporation Ledger updated from proposed to exact applied/verified state.
- [x] Metadata/score/owner/emitter/split/rename/C++ changes applied or explicitly not
      applied with reason.
- [x] Historical assumptions, rejected names/owners/helpers, negative evidence, and prior
      valid B003 provenance preserved.
- [x] Open questions remain closed after callback drift check.
- [x] One short lease used only for each immediate by-* edit and released after its scoped
      validator.
- [x] One scoped validator run and fully recorded for every changed ordinary by-* page.
- [x] Final authorized waited generated refresh completed and exact Chatting.cpp output
      verified read-only.
- [x] Validator Results, Changed Files, ledger, current state, and checklist reconciled
      archive-neutrally.
- [x] Remaining unapplied accepted items: none.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B002","command_id":"000000009483","destination_path":"executed-b-agent-research/B002/0002EW-ChattingPaneSetVisibleRowCount-source-quality.md","details":"report executed into central archive","event":"executed","source_path":"tools/leaser/Agents/Agent-B002/research/0002EW-ChattingPaneSetVisibleRowCount-source-quality.md","timestamp":"2026-07-13T08:15:41-04:00","uid":"0002EW"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
