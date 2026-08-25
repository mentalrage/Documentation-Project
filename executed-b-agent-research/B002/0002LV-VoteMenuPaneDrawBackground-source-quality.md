** TARGET-REPORT-UID:0002LV **
** AUTHOR-AGENT-ID:B002 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.6 | xHigh **
# UID0002LV VoteMenuPaneDrawBackground Source-Quality Report


## Finalized Report / Current Recommendation

- B002 implementation callback is complete for the accepted C01-C30 and
  Destinations 1-5 scope. UID0002LV remains the separate source-authored
  `VoteMenuPane::DrawBackground` virtual at `[0x00555c70,0x00555ce1)`,
  now at `92/94`, with direct semantic owner/emitter UID0000FX,
  reconstructable true, blank optional position, `Nested:0`, exact Item
  Summary, and byte-equal Destination 1.
- Finalized source disposition is one behaviorally exact human-shaped method
  body. The
  target initializes one local `EPFTileContext`, performs one
  `g_pEPFLib` layout lookup for `SUBWIN.EPF` entry `8`, copies inherited
  `GrafPort::m_visibleBounds`, writes inherited
  `GrafPort::m_drawMode = 1`, insets all four edges by one pixel through direct
  field operations, and calls inherited
  `GrafPort::DrawTiledBackground` with `SUBWIN.PAL`.
- The complete first shared VoteMenuPane baseline is applied: UID0000FX is
  `90/92` with byte-equal Destination 5; UID0000P6 is `91/92` with no by-file
  reconstruction metadata; UID0001FY is false/non-emitting blank-formal
  `90/93`; UID0001Z1 is false/non-emitting blank-formal `90/93`; and
  UID0001WH is false/non-emitting blank-formal `90/92`.
- Collision disposition: B004 owns independent report-only target UID0002LW
  DrawBorder and has produced evidence-time artifact
  `tools/leaser/Agents/Agent-B004/research/0002LW-VoteMenuPaneDrawBorder-source-quality.md`,
  SHA256
  `DD82D3866C35019AD8AB02EFD50605AEE3C7CD22E79276EEF8784D616EC81CB4`,
  `81,659` bytes / `1,018` lines, at the latest final coordination read.
  This is a time-scoped coordination snapshot, not a durable assertion that
  B004's active artifact cannot receive a later report-only successor.
  B002 owns UID0002LV and did not lease or edit UID0002LW. UID0002LW is
  currently still `86/90`, SHA256
  `1D3F948371C7FFB7C672939E8228FAE0C61D3EA4384D595B9D6796DD7158EBD6`,
  and its B004 callback has not started. The deterministic shared callback
  order is preserved: this B002 baseline is first; B004 later rereads it and
  applies only its separately accepted UID0002LW delta.
- Scoped validators `000000014383`, `000000014384`, `000000014385`,
  `000000014386`, `000000014387`, and `000000014393` passed with exit `0` /
  `ok:1`. Authorized waited command `000000014396` passed and completed
  generated refresh. The latest read-only generated header observed after
  concurrent validator activity is command `000000014399`.
- B002 work and leases are complete. Manual coverage and report lifecycle are
  supervisor-owned; the report does not assert execution, move, or archive
  state.
- Confidence: very strong for behavior, ABI, range, liveness, fields,
  resources, helpers, ownership, and source placement; strong for exact
  original local-variable spelling and the source-header alias boundary
  between `EPFTileContext` and the shared frame-record view.

## Supporting Research

Required process material read:

- canonical `tools/leaser/Agents/Agent-B002/goal.md`;
- project skill `ntk-b-agent-workflow/SKILL.md`;
- `references/b-agent-research-and-implementation-workflow.md`;
- `references/b-agent-report-template.md`;
- `references/score-blocker-audit-standard.md`;
- current `by-structure.md`, including ownership, emitter, compiler-output,
  report-only, generated-output, and manual-coverage rules.

Final callback ordinary and generated evidence read:

- UID0002LV target, UID0002LW adjacent DrawBorder, UID0001FY aggregate,
  UID0000FX class, UID0000P6 file, UID0001Z1 vtable cluster, UID0001WH
  layout, and UID0003CY exact vtable-data child;
- UID00004I `EPFTileContext`, UID0000BY `ResourceLayoutTable`, UID0000QU
  `g_pEPFLib`, UID00016A `GrafPort::DrawTiledBackground`, UID00005V
  `GrafPort`, UID0000A2 `Pane`, UID0001VH `PaneLayout`, and UID0000BU
  `RectBounds`;
- validator-owned generated
  `auto-generated/NexusTK/ui/menu/VoteMenuPane.cpp`;
- final-read manual `by-memory`, `by-class`, `by-file`,
  `by-type/by-vtable`, and `by-type/by-struct` coverage rows.

Historical-report search terms were:

`TARGET-REPORT-UID:0002LV`, `UID0002LV`, `VoteMenuPaneDrawBackground`,
`0x00555c70`, `SetDrawClipEnabled`, `FillTiledRect`,
`LoadResourceLayoutTile`, `VoteMenuPane`, `SUBWIN.EPF`,
`SUBWIN.PAL`, `UID0000FX`, `UID0000P6`, `UID0001FY`,
`UID0001Z1`, `0x004816d0`, `0x005552f0`, and `0x005bd5b0`.

Every required report root was searched:

| Root searched | Exact outcome | Classification |
| --- | --- | --- |
| `executed-b-agent-research/**` | Seven relevant artifacts were opened: B003 VoteMenuPane family, B003 UID0001FY, B003 UID0002LU, B014 UID0000FX, B005 UID0001FX RightButtonMenuPane, B003 ChattingVarietySelectPane family, and B003 MenuVarietyPanes family. | Executed supporting or historical evidence. None has `TARGET-REPORT-UID:0002LV`; the old B003 family artifact includes UID0002LV but is not a current exact-target standalone report. |
| `archived/**` | No match for the exact target terms. | No additional evidence. |
| `tools/leaser/Agents/Older-Research/**` | No match. | No additional evidence. |
| `tools/leaser/Agents/SpecialReports/**` | No match. | No additional evidence. |
| legacy per-agent `research/executed/**` | No match. | No additional evidence. |
| active `tools/leaser/Agents/**` | B002 goal/report and B004's active UID0002LW goal/report matched; no second active exact UID0002LV report exists. Latest evidence-time B004 artifact observed at the final coordination read was SHA256 `DD82D3866C35019AD8AB02EFD50605AEE3C7CD22E79276EEF8784D616EC81CB4`, `81,659` bytes / `1,018` lines. | Current collision/coordination evidence. B004 owns only the adjacent DrawBorder target, incorporates B002's support plan and alias as its observed union, and explicitly requires B002-first/shared-rebase-second ordering. A later B004 report-only successor is a callback-time reread requirement, not a contradiction to this time-scoped snapshot. |

Relevant opened-report findings:

- B003's historical VoteMenuPane family report supplied the stale
  `SetDrawClipEnabled`, `LoadResourceLayoutTile`, `FillTiledRect`, `Rect`,
  and `m_bounds` draft. Fresh current support and MCP evidence reject those
  spellings as current source-facing recommendations while preserving the
  old report as provenance.
- B003 UID0001FY confirms the exact child/padding inventory and source-file
  route. Its current blank reconstructable aggregate produces an empty marker;
  the page's own index-only description supports non-emitting
  reclassification.
- B003 UID0002LU confirms the class/file/aggregate current union and proves the
  primary virtual order immediately preceding UID0002LV. Its verify-only
  treatment of UID0002LV did not reanalyze or correct the target body.
- B014 UID0000FX confirms the class declaration, primary virtual name
  `DrawBackground`, direct class owner, file route, and compiler-generated
  vtable/thunk policy.
- Current accepted RankingRewardInfoDialog class formal supplies the exact
  period-plausible alias `typedef EPFTileContext FrameDrawRecord;`. That alias
  resolves the otherwise incompatible current source spellings:
  `LookupLayoutEntry` writes `EPFTileContext *`, while
  `DrawTiledBackground` currently declares `const FrameDrawRecord *`.
- B005 UID0001FX and B003 Chatting/MenuVariety reports identify independent
  `0x71` SUBWIN background methods. Fresh MCP proves their instruction and
  behavior shape matches UID0002LV while their distinct vtable cells and
  addresses reject covered-by or shared-body treatment.
- B004's current UID0002LW report independently resolves DrawBorder to a
  source-ready direct EPFTileContext/RectBounds/resource/render sequence and
  proposes shared class/file scores `90/92` and `91/92`. Its final coordination
  artifact now explicitly adopts B002's UID0001FY `90/93`, UID0001Z1 `90/93`,
  and UID0001WH `90/92` semantic-owner-retaining false/non-emitting
  dispositions. The earlier B004 SHA
  `111A994E8278C3771DD7DFCB870658D7C1843F14D5B5BD07CCD20562A15E14E9`
  predated that synchronization and is historical only.

## Target

- Target UID: `0002LV`.
- Target path:
  `by-memory/0x00555c70-0x00555ce1.VoteMenuPaneDrawBackground.md`.
- Source queue: current `auto-generated/-ag-research-tracker.md`,
  `by-memory` not-covered reconstructable row.
- Queue state at assignment: `86/90`, reconstructable true, zero direct
  exact-target reports.
- Exact half-open range: `[0x00555c70,0x00555ce1)`.
- Exact size: `0x71` / 113 bytes.
- Exact target-byte SHA256:
  `04DF87088E9AEBFF0C23EA55C65C93EDEFEF470865D40A5BA719A9B208183E40`.
- Current owner/emitter: UID0000FX `VoteMenuPane`.
- Source root: UID0000P6, `NexusTK/ui/menu/VoteMenuPane.cpp`.

## Current Target State

- Current applied metadata: `92/94`, owner/emitter UID0000FX,
  reconstructable true, blank optional position, `Nested:0`.
- Current formal body is byte-equal to Destination 1 and uses only accepted
  source-facing APIs and fields.
- Historical pre-callback formal defects were:
  - it calls unproved `InitEPFTileContext` instead of the accepted
    `EPFTileContext::Initialize`;
  - it calls unproved `LoadResourceLayoutTile` instead of the accepted
    `g_pEPFLib->LookupLayoutEntry`;
  - it calls `SetDrawClipEnabled(true)`, but exact offset and GrafPort support
    prove a draw-mode byte store;
  - it uses historical `Rect` and `m_bounds`, while current accepted inherited
    state is `RectBounds` and `GrafPort::m_visibleBounds`;
  - it calls unproved `SetRect` and `FillTiledRect` wrappers not present in the
    body or required by current shared APIs.
- The current target Item Summary and score rationale now include the complete
  range/hash/instruction/CFG/padding/vtable/resource/callee/type/field/
  negative/comparator/source-placement evidence. The old caveat state is
  preserved only as history.
- Historical pre-callback generated snapshot:
  `auto-generated/NexusTK/ui/menu/VoteMenuPane.cpp`, external validator command
  `000000014382`, refreshed `2026-07-16T16:37:07-04:00`, SHA256
  `B025487CF3CEA1E1F62FA42FE22DCC012DF4C32B832F710BF7C25758AB3E88D3`,
  `8,559` bytes / `280` lines. It contains exactly one UID0002LV definition,
  but that definition still has the seven stale source-facing tokens above.
- That historical snapshot had blank-emitter markers for UID0001WH,
  UID0001Z1, and UID0001FY. Those are support-disposition defects, not target
  liveness evidence.
- Current generated readback has one complete VoteMenuPane class, one
  `typedef EPFTileContext FrameDrawRecord;`, one exact UID0002LV definition,
  no target stale token, and zero UID0002LV/UID0001FY/UID0001Z1/UID0001WH
  Empty Emitter Markers. UID0002LW remains one unchanged B004-owned `86/90`
  pre-callback body; no future B004 score or replacement body is asserted as
  current.
- B004's current goal/report assigns UID0002LW DrawBorder independently. The
  final report-only recheck observed B004 artifact SHA256
  `DD82D3866C35019AD8AB02EFD50605AEE3C7CD22E79276EEF8784D616EC81CB4`,
  `81,659` bytes / `1,018` lines, while UID0002LW and all shared ordinary pages
  remained at their pre-callback hashes. This is an evidence-time coordination
  snapshot, not an assertion about a later B004 report successor or supervisor
  lifecycle state.

## Executive Recommendation

Applied implementation is one direct target body and no feature-local wrapper:

1. initialize a stack `EPFTileContext`;
2. request `SUBWIN.EPF` entry `8` through `g_pEPFLib`;
3. copy inherited visible bounds;
4. set inherited draw mode `1`;
5. increment left/top and decrement right/bottom exactly once;
6. invoke inherited tiled-background drawing with `SUBWIN.PAL`;
7. return without a lookup-result branch, context release, mode restore, or
   fallback.

UID0002LV remains a separate class method. The same normalized compiler shape
at three sibling addresses is copy/idiom evidence, not a common emitted body:
each sibling has its own function address and vtable cell.

The helper/type naming conflict is closed as follows:

- the local is source-facing `EPFTileContext` because the exact initializer
  and `ResourceLayoutTable::LookupLayoutEntry` producer write that accepted
  0x28-byte layout;
- the target calls the accepted inherited `DrawTiledBackground` API directly;
- current target-family and accepted DialogPane callers already pass an
  `EPFTileContext`-shaped record to that API, so no cast, duplicate record, or
  decompiler-shaped adapter belongs in the target;
- `FrameDrawRecord` remains the shared render-API alias/view spelling used by
  other producers. Destination 5 places the already accepted
  `typedef EPFTileContext FrameDrawRecord;` before the complete VoteMenuPane
  class, making both current helper declarations compile-compatible while the
  observed local remains an `EPFTileContext`.

## Supervisor Active Recheck

- Supervisor Gate 1 authorization matched accepted report SHA
  `F9E5C54D2B2B7154AD1FFC0704503F9DB52A07D94F1D9C0C36A28DE345D8FF22`
  before ordinary edits.
- B002 edited only the six accepted ordinary pages and this report. Manual
  coverage, generated output, validator state, audit, tracker, IDA, and
  lifecycle files were not manually edited.
- Mandatory live MCP was healthy on adopted database `64c11373`, worker PID
  `21508`.
- `server_health` returned `status:ok`, image base `0x00400000`,
  auto-analysis ready, Hex-Rays ready, and string cache ready with 2067
  entries.
- Bounded target bytes, lookup, full analysis, helper analyses, vtable bytes,
  resource bytes, xrefs, and type-catalog checks all returned valid current
  data.
- One initial local PowerShell client-shape attempt used the reserved
  `$args`-style pattern and failed before a valid IDB tool request. It was
  corrected to a hashtable key assignment; all valid bounded IDB calls then
  succeeded. This was not an MCP outage and no fallback evidence is used.
- No split or new child was required.
- UID0002LW remains B004-owned and its ordinary SHA256 remains
  `1D3F948371C7FFB7C672939E8228FAE0C61D3EA4384D595B9D6796DD7158EBD6`.
  B002 established the first shared baseline without editing that target;
  B004's later callback must reread/rebase and preserve the complete union.
- All B002 leases were released immediately after their scoped validators;
  current B002 lease count is zero.

## Inference Research Guidance Check

- IDA facts, current documentation facts, historical report claims, and
  source-shape inferences are separated throughout this report.
- Current field/helper names were not inherited from the old report merely
  because they were already emitted.
- Stale Wave2/Wave3 naming and the `simroot_v2` route were not used as
  authority.
- Exact binary behavior is preserved ahead of stylistic cleanup.
- Source shape is ordinary Visual C++ 6/7-era code: one local record, one local
  rectangle, direct member/global calls, direct field increments/decrements,
  and no modern abstraction.
- Compiler-only security-cookie scaffolding and SIMD copy scheduling are
  excluded from handwritten source.
- The source-quality recommendation uses the strongest current names even
  though original debug symbols do not survive. Remaining spelling uncertainty
  caps confidence below 95 but does not block exact C++.

## Heuristic / Inference Reanalysis And Validation

| Issue | Evidence checked | Best current resolution | Rejected alternatives |
| --- | --- | --- | --- |
| Method liveness | One primary-vtable data xref at `0x00623040`; constructor, ordinary destructor, and scalar wrapper store/restore primary base `0x00622ff8`; no direct code caller. | Live virtual `VoteMenuPane::DrawBackground`. | Dead helper, raw orphan, compiler glue, or file-local free function. |
| Local 0x28-byte record | Exact `lea ecx,[ebp-0x3c]` call to `0x00457a60`; current EPFTileContext declaration; lookup writes accepted fields. | `EPFTileContext tile`, initialized by `tile.Initialize()`. | Unstructured `int[10]`, independent `FrameDrawRecord` copy, or heap object. |
| Resource lookup | Receiver load from `0x0067a744`; `SUBWIN.EPF`; index `8`; output is the local record; current ResourceLayoutTable method. | `g_pEPFLib->LookupLayoutEntry` with the literal and index. | `LoadResourceLayoutTile`, free loader, VoteMenuPane-owned resource manager, or hard-coded tile bytes. |
| Resource strings | Exact UTF-16 bytes at `0x00610b74` and `0x00610b8c`; target and three sibling pairs use them. | Literals `SUBWIN.EPF` and `SUBWIN.PAL`. | Pointer-table names, runtime-composed names, `DLGFRAME`, or resource ownership by VoteMenuPane. |
| `this+0x44` | Exact 16-byte copy; current Pane/GrafPort support resolves offset `+0x44` as inherited `GrafPort::m_visibleBounds`. | `RectBounds backgroundBounds = m_visibleBounds`. | Historical `m_bounds`, `m_localBounds`, VoteMenuPane-local field, or BackPane-owned bounds. |
| `this+0x70` | Exact byte store `1`; DrawTiledBackground later reads the same GrafPort byte as callback mode; WaterFilter and other callers use modes `0/1/2`. | Inherited `m_drawMode = 1`. | `SetDrawClipEnabled`, visibility, dirty flag, Pane mode, Boolean clip toggle, or background-ready byte. |
| Inset source shape | OWORD copy followed by top increment, right decrement, left increment, bottom decrement; no call to RectBounds member/free helpers. | Four direct edge mutations after the value copy. | `SetRect`, an out-of-line `RectBounds::Inset` call, width/height constructor, or hidden target helper. |
| Final draw helper | `ecx=this`, arguments rectangle, local record, and palette; current UID00016A helper has 26 callers and exact matching target call at `0x00555ccd`. | Inherited `DrawTiledBackground`. | `FillTiledRect`, Surface-owned free function, Ranking-owned helper, or direct callback dispatch in this target. |
| Lookup return/failure handling | Target has one basic block and ignores the lookup return. | No branch or fallback. | Null check, index-range fallback, exception, or early return. |
| Local lifetime | No release/destructor call after DrawTiledBackground; lookup supplies borrowed resource pointers. | No explicit `ReleaseBuffers`. | Invented RAII cleanup, explicit free, or mask release. |
| Draw-mode lifetime | One write to `1`, no restore in target. | Preserve the non-restored store. | Scoped save/restore or post-draw reset. |
| Source return type | Primary virtual class declaration, plain `ret`, no result use. | `void`. | Boolean success, lookup return, tile count, or helper result. |
| Duplicate sibling bodies | Fresh analyses at `0x004816d0`, `0x005552f0`, and `0x005bd5b0`: each size `0x71`, one block, same callees, offsets, constants, and decompiled operations, with distinct vtable cells. | Repeated source idiom/copy in four pane classes. | One covered-by emitter, inherited one-address base implementation, linker thunk, or common file-local helper. |
| Source file | Class declaration and every sibling method in the VoteMenuPane island route to UID0000P6. | `NexusTK/ui/menu/VoteMenuPane.cpp`. | GrafPort.cpp, ResourceLayoutTable.cpp, RightButtonMenuPane.cpp, Chatting.cpp, or shared SUBWIN utility file. |
| Support empty emitters | UID0001FY says it is an index and exact children emit; UID0001Z1 says compiler-generated; UID0001WH says class declaration owns fields. | Semantic ownership retained, reconstruction/emission disabled on those three support pages. | Blank reconstructable emitters or handwritten duplicate source. |
| Frame-record type boundary | `LookupLayoutEntry` formal takes `EPFTileContext *`; `DrawTiledBackground` formal takes `const FrameDrawRecord *`; layouts are identical and accepted RankingRewardInfoDialog source already uses `typedef EPFTileContext FrameDrawRecord;`. | Preserve local `EPFTileContext`; add the exact typedef to UID0000FX before the class. | C-style/reinterpret cast, duplicate copy, a second stack record, or changing target behavior. |

No investigable behavior, ownership, field, type, helper, source-placement, or
formal-C++ blocker remains for UID0002LV.

## Evidence Standards Used

- Primary evidence: live MCP function lookup, exact bytes, decompilation,
  disassembly, basic blocks, callees, xrefs, vtable/data bytes, and resource
  bytes.
- Current documentation evidence: accepted EPFTileContext,
  ResourceLayoutTable, GrafPort, Pane, RectBounds, VoteMenuPane class/file, and
  current generated source contracts.
- Historical evidence: opened executed reports only after exact search; their
  claims were independently checked.
- Comparator evidence: three independent same-shape sibling functions.
- Negative evidence: no direct caller, no alternate pointer/table route, no
  extra block, no failure path, no cleanup, no mode restore, no target-owned
  helper, no source reason to handwrite compiler scaffolding.
- Evidence is sufficient for `92/94`; exact original local names and shared
  frame-record typedef spelling remain below final-audit proof, so neither
  score is raised to 95.

## Evidence Checked

Live MCP calls on database `64c11373`:

- fresh `idb_list`;
- `server_health`;
- `lookup_funcs` for target, adjacent method, three duplicate comparators, and
  all three direct callees;
- bounded `get_bytes` for target plus predecessor/successor padding, three
  comparator bodies, resource strings, and primary vtable slice;
- full `analyze_function` with assembly for UID0002LV;
- `analyze_function` for all three duplicate comparator bodies;
- `analyze_function` for `0x00457a60`, `0x004d02f0`, and `0x004ba6b0`;
- `xrefs_to` for target, primary vtable base, resource literals, and
  `g_pEPFLib`;
- bounded type-catalog queries for `EPFTileContext`, `FrameDrawRecord`, and
  VoteMenuPane. No named IDA type object exists for those strings, so current
  by-* declarations remain the source-facing type evidence.

Exact implementation file evidence, before -> current:

- target SHA256 `54ACD079...A822` ->
  `70B78AB115846DE326A30CCE90237E07AB59C8F8F1F8E87599CEF5340838C523`;
- UID0002LW SHA256
  `1D3F948371C7FFB7C672939E8228FAE0C61D3EA4384D595B9D6796DD7158EBD6`;
- B004 UID0002LW report SHA256
  `DD82D3866C35019AD8AB02EFD50605AEE3C7CD22E79276EEF8784D616EC81CB4`
  at the latest evidence-time coordination read;
- UID0001FY `B0BF6485...A865` ->
  `30EF35FFB91B65C021F418008B44B77732093578F4DF791047AD34A12F3AA3FE`;
- UID0000FX `0FD33C3C...3DC8` ->
  `D94517A8C5872A419006B1BB6E3DB3DC8A1A90E8667FECC1F70AB32AB3EB037F`;
- UID0000P6 `70271629...3977` ->
  `91C0F3DCD97309FFE4983056F444F860433AFADBA4F53E12541AE96ED12C5605`;
- UID0001Z1 `7FE50F5D...ADF0` ->
  `08061D4275E25ED6E2D3A776C846FAAF323B925213F0CF9D8A99C71DA1756822`;
- UID0001WH `CA5AD94A...D629` ->
  `FEE4938C2DF76C570F6F0ECE5271A7D5A7D6AD66667F53334E27E10E3903EC77`.

## Claim And Incorporation Ledger

| Claim ID | Claim | Confidence | Evidence | Destination doc/section | Action | Verification state |
| --- | --- | --- | --- | --- | --- | --- |
| C01 | Mandatory MCP database `64c11373` was healthy at evidence collection. | Very strong | Fresh list, health, bounded real bytes. | Target evidence; report MCP sections | incorporate | applied |
| C02 | UID0002LV is exactly `[0x00555c70,0x00555ce1)`, 113 bytes, SHA256 `04DF...3E40`. | Very strong | Lookup plus full target bytes/local SHA. | UID0002LV range/evidence/summary | incorporate | applied |
| C03 | Eight leading and fifteen trailing `0xcc` bytes are external alignment, not target code. | Very strong | Bounded bytes `[0x00555c68,0x00555cf0)`. | UID0002LV range; UID0001FY inventory | incorporate | applied |
| C04 | The method is 39 instructions, one basic block, cyclomatic complexity 1. | Very strong | Full assembly and analyzer. | UID0002LV instruction/CFG evidence | incorporate | applied |
| C05 | Security-cookie prologue/epilogue and SIMD copy scheduling are compiler output. | Very strong | Assembly. | UID0002LV compiler exclusions | incorporate | applied |
| C06 | The sole target xref is primary vtable cell `0x00623040`; no direct code caller exists. | Very strong | Analyze/xrefs. | UID0002LV liveness; UID0001Z1 | incorporate | applied |
| C07 | Primary vtable base `0x00622ff8` is installed/restored by constructor, ordinary destructor, and scalar wrapper. | Very strong | Xrefs at `0x00555913`, `0x00555975`, `0x0055634c`. | UID0002LV liveness; UID0001Z1 | incorporate | applied |
| C08 | Source identity is `void VoteMenuPane::DrawBackground()`. | Very strong | Class declaration, primary slot order, ABI, neighboring virtuals. | UID0002LV formal; UID0000FX prose | incorporate | applied |
| C09 | Local `[ebp-0x3c]` is one 0x28-byte `EPFTileContext`. | Very strong | Initializer analysis and current layout. | UID0002LV local/type evidence | incorporate | applied |
| C10 | `0x00457a60` is source-facing `EPFTileContext::Initialize`. | Very strong | One-block initializer and current UID00004I. | UID0002LV formal/evidence | incorporate | applied |
| C11 | `g_pEPFLib` and `LookupLayoutEntry` are the source-facing resource route. | Very strong | Receiver load, helper analysis, current singleton/facet docs. | UID0002LV formal/evidence; UID0000P6 | incorporate | applied |
| C12 | Resource literal is exact UTF-16 `SUBWIN.EPF`, entry index `8`. | Very strong | Bytes, SHA, target operands/xrefs. | UID0002LV formal/evidence | incorporate | applied |
| C13 | Palette literal is exact UTF-16 `SUBWIN.PAL`. | Very strong | Bytes, SHA, target operand/xref. | UID0002LV formal/evidence | incorporate | applied |
| C14 | `this+0x44..0x50` is inherited `GrafPort::m_visibleBounds`. | Very strong | Exact copy plus current Pane/GrafPort layout. | UID0002LV formal; class/file prose | incorporate | applied |
| C15 | `this+0x70` is inherited `GrafPort::m_drawMode`, written to `1`. | Very strong | Exact store plus DrawTiledBackground consumer and current support. | UID0002LV formal; class/file prose | incorporate | applied |
| C16 | The destination rectangle is a value copy with one-pixel direct edge inset. | Very strong | Exact OWORD copy and four arithmetic instructions. | UID0002LV formal/evidence | incorporate | applied |
| C17 | Final callee is inherited `GrafPort::DrawTiledBackground`. | Very strong | Exact call and current UID00016A. | UID0002LV formal/evidence | incorporate | applied |
| C18 | Lookup result is ignored; there is no failure/fallback branch. | Very strong | One-block CFG/decompile. | UID0002LV behavior/negative evidence | incorporate | applied |
| C19 | There is no explicit context release, draw-mode restore, null check, or extra invalidation. | Very strong | Complete assembly. | UID0002LV behavior/negative evidence | incorporate | applied |
| C20 | Three same-shape sibling methods prove a copied SUBWIN idiom but not common emission. | Very strong | Fresh analyses/vtable cells at `0x004816d0`, `0x005552f0`, `0x005bd5b0`. | UID0002LV comparator evidence | incorporate | applied |
| C21 | Stale `InitEPFTileContext`, `SetDrawClipEnabled`, `LoadResourceLayoutTile`, `FillTiledRect`, `SetRect`, target-local `Rect`, and target-local `m_bounds` source claims are superseded. | Very strong | Current support and exact body. | UID0002LV history; UID0000FX/UID0000P6 prose | historicalize | applied |
| C22 | Destination 1 is the exact target formal body. | Very strong | C08-C19. | UID0002LV managed block | incorporate | applied |
| C23 | Target metadata is `92/94`; owner/emitter/true/blank-position/Nested0 remain. | Very strong | Closed blockers and stable route. | UID0002LV metadata | incorporate | applied |
| C24 | UID0000FX has Destination 5: its complete class formal plus the accepted `EPFTileContext`/`FrameDrawRecord` alias, bounded UID0002LV evidence, and exact `90/92`; B004's second callback preserves that union and adds UID0002LW prose. | Strong | Class route, target closure, accepted alias precedent, and current B004 shared recommendation. | UID0000FX formal/prose/score | incorporate | applied |
| C25 | UID0000P6 retains no by-file reconstruction metadata, has UID0002LV source-order/dependency/history evidence, and is exactly `91/92`; B004's second callback preserves this union and adds UID0002LW prose. | Strong | File route, generated ordering, and current B004 shared recommendation. | UID0000P6 prose/score | incorporate | applied |
| C26 | UID0001FY is an index-only, semantic-owner-retaining, false, non-emitting, blank-formal aggregate at `90/93`. | Very strong | Exact children emit; page says no duplication; historical pre-callback marker is gone. | UID0001FY metadata/prose/formal | incorporate | applied |
| C27 | UID0001Z1 is compiler-generated, semantic-owner-retaining, false, non-emitting, blank-formal vtable support at `90/93`. | Very strong | Vtable bytes/stores and class source cause. | UID0001Z1 metadata/prose/formal | incorporate | applied |
| C28 | UID0001WH fields are emitted by UID0000FX; the layout page is semantic-owner-retaining, false, non-emitting, and blank-formal at `90/92`. | Very strong | Layout page's own no-code policy; historical pre-callback marker is gone. | UID0001WH metadata/prose/formal | incorporate | applied |
| C29 | UID0002LW remains B004-owned and currently `86/90`; latest evidence-time B004 artifact SHA `DD82...1CB4` requires B002-first/B004-second shared rebase, B002 performs no UID0002LW target edit, and future B004 `92/94` work is not current state. | Very strong | Active canonical B004 goal/report, current UID0002LW metadata/hash, and time-scoped artifact reread. | Report coordination; callback checklist | not-applicable | excluded-with-reason |
| C30 | Manual coverage rows describe only the current B002-applied baseline, preserve UID0002LW as B004-owned `86/90` pending callback, and record scoped validators, final waited generated assertions, current hashes, and zero-lease proof. | Very strong | Workflow/manual files/current UID0002LW/generated snapshot. | Coverage, Validator Results, Changed Files, checklist | incorporate | applied |

All Action cells retain the accepted report vocabulary. Terminal Verification
states are `applied` for C01-C28/C30 and `excluded-with-reason` for the
B004-owned UID0002LW target edit in C29.

Claim-by-claim callback proof:

| Claim | Terminal destination proof |
| --- | --- |
| Proof for C01 | Evidence-time MCP provenance remains in Target, Evidence Checked, and IDA MCP Facts; callback required no IDA mutation. |
| Proof for C02 | UID0002LV Address Range/IDA Evidence/Item Summary record exact range, size, and SHA. |
| Proof for C03 | UID0002LV IDA Evidence and UID0001FY Covered Ranges retain both exact padding spans. |
| Proof for C04 | UID0002LV Item Summary/IDA Evidence record 39 instructions, one block, complexity 1. |
| Proof for C05 | UID0002LV Score Rationale/Reconstruction Notes exclude cookie and SIMD scheduling from source. |
| Proof for C06 | UID0002LV and UID0001Z1 record sole cell `0x00623040` and zero direct callers. |
| Proof for C07 | UID0002LV and UID0001Z1 record stores/restores `0x00555913/0x00555975/0x0055634c`. |
| Proof for C08 | UID0002LV Destination 1 and UID0000FX declaration emit exact `void DrawBackground()`. |
| Proof for C09 | UID0002LV Behavior/IDA Evidence and Destination 1 use one local `EPFTileContext`. |
| Proof for C10 | UID0002LV body/evidence uses `tile.Initialize()`; generated target readback matches. |
| Proof for C11 | UID0002LV body/evidence and UID0000P6 use `g_pEPFLib->LookupLayoutEntry`. |
| Proof for C12 | UID0002LV body/evidence records `SUBWIN.EPF`, entry 8, and exact resource hash. |
| Proof for C13 | UID0002LV body/evidence records `SUBWIN.PAL` and exact resource hash. |
| Proof for C14 | UID0002LV, UID0000FX, UID0000P6, and UID0001WH use inherited `m_visibleBounds`. |
| Proof for C15 | UID0002LV, UID0000FX, UID0000P6, and UID0001WH use inherited `m_drawMode = 1`. |
| Proof for C16 | UID0002LV Destination 1 and generated readback contain all four direct edge mutations. |
| Proof for C17 | UID0002LV body/evidence and UID0000P6 route the final inherited `DrawTiledBackground` call. |
| Proof for C18 | UID0002LV Behavior/negative evidence records ignored lookup result and no fallback branch. |
| Proof for C19 | UID0002LV Behavior/Reconstruction Notes record no release, restore, null check, or invalidation. |
| Proof for C20 | UID0002LV IDA Evidence retains all three distinct same-shape comparator addresses. |
| Proof for C21 | UID0002LV, UID0000FX, and UID0000P6 label all seven stale target tokens historical/superseded. |
| Proof for C22 | UID0002LV formal block is byte-equal to report Destination 1 and generated definition. |
| Proof for C23 | UID0002LV is `92/94`, UID0000FX owner/emitter, true, blank position, Nested0; command 14383 passed. |
| Proof for C24 | UID0000FX is `90/92` with byte-equal Destination 5 and full no-loss union; command 14387 passed. |
| Proof for C25 | UID0000P6 is `91/92`, FILE-owned, prose-only, with no reconstruction metadata; commands 14393/14396 passed. |
| Proof for C26 | UID0001FY is `90/93`, semantic owner UID0000P6, false, blank emitter/position/formal; command 14384 passed. |
| Proof for C27 | UID0001Z1 is `90/93`, semantic owner UID0000FX, false, blank emitter/position/formal; command 14385 passed. |
| Proof for C28 | UID0001WH is `90/92`, semantic owner UID0000FX, false, blank emitter/position/formal; command 14386 passed. |
| Proof for C29 | UID0002LW was never leased or edited; it remains `86/90`, ordinary SHA `1D3F9483...EBD6`, with one pre-B004 generated body, and B004 owns its later delta. |
| Proof for C30 | The corrected manual rows describe only B002-applied current state and explicitly leave UID0002LW at `86/90` pending B004; validator, generated, hash, checklist, and zero-lease proof remain recorded below. |

## Positive Evidence Summary

- Exact target boundary, size, SHA, 39-instruction body, one block, and
  surrounding padding are verified.
- One primary-vtable cell points to the target; three lifecycle sites establish
  the live VoteMenuPane vtable.
- The target uses exactly the accepted EPFTileContext initializer,
  ResourceLayoutTable lookup, GrafPort fields, and DrawTiledBackground helper.
- Exact resource strings, tile index, bounds fields, mode value, and call order
  are directly observable.
- Three independent class methods reproduce the same compiler shape, strongly
  supporting a simple copied human source idiom.
- Current VoteMenuPane class/file ownership and source order already fit the
  target without a new file, class, helper, or child.

## IDA MCP Facts

- Evidence-time adopted database: `64c11373`, `NexusTK.exe.i64`, worker PID
  `21508`.
- Final bounded evidence recheck: fresh `idb_list` returned that sole live
  session; `server_health` was ok with auto-analysis, Hex-Rays, and strings
  ready; `get_bytes(0x00555c70,16)` returned real target bytes; full
  disassembly/decompilation reconfirmed the bounds load before the mode store.
- Target lookup: `sub_555C70`, size `0x71`.
- Target prototype inferred by IDA: one-argument hidden-receiver `void`
  thiscall.
- Target analysis: 113 bytes, 39 instructions, one block, complexity 1.
- Target byte SHA256:
  `04DF87088E9AEBFF0C23EA55C65C93EDEFEF470865D40A5BA719A9B208183E40`.
- Predecessor padding: eight `0xcc` bytes.
- Successor padding: fifteen `0xcc` bytes.
- Target data xref: `0x00623040`.
- Primary base xrefs: `0x00555913`, `0x00555975`, `0x0055634c`.
- Callees: `0x00457a60`, `0x004d02f0`, `0x004ba6b0`, and security-cookie
  check.
- Resource xrefs in target: `0x00555c97` to `SUBWIN.EPF`,
  `0x00555ca5` to `SUBWIN.PAL`.
- `SUBWIN.EPF` exact 22-byte UTF-16-plus-null SHA256:
  `7077915D0DE751D089340CB662D4C3C825030F2D53C74DEB49B7EF2A46A03C55`.
- `SUBWIN.PAL` exact 22-byte UTF-16-plus-null SHA256:
  `845854037B679051CFF8F13ACBA39E9374CDE53DA44998AB2BED383DAA71430A`.
- Type catalog: no named IDA type entries for EPFTileContext,
  FrameDrawRecord, or VoteMenuPane; current source types are documentation
  reconstructions grounded in exact field behavior.

## Function / Child Inventory

| Range / item | UID / path | Role | Current disposition | Direct parent | Applied score | Status |
| --- | --- | --- | --- | --- | --- | --- |
| `0x00555c68-0x00555c70` | UID0000VN ignored ledger | Alignment | false/ignored | none | unchanged | Exact eight `0xcc` bytes. |
| `0x00555c70-0x00555ce1` | UID0002LV target | `VoteMenuPane::DrawBackground` | true, emitting | UID0000FX | `92/94` | Destination 1 applied. |
| `0x00555ce1-0x00555cf0` | UID0000VN ignored ledger | Alignment | false/ignored | none | unchanged | Exact fifteen `0xcc` bytes. |
| `0x00555cf0-0x00556012` | UID0002LW | `VoteMenuPane::DrawBorder` | B004-owned, true/emitting | UID0000FX | current `86/90`; B004 callback pending | Read-only comparator/coordination; no B002 target edit. |
| `0x005558d0-0x0055606d` | UID0001FY | Exact core index | false, non-emitting | UID0000P6 semantic owner | `90/93` | Destination 2 metadata/prose/blank formal applied. |
| VoteMenuPane class | UID0000FX | Class declaration, frame-record alias, and virtuals | true, emitting | UID0000P6 | `90/92` | Destination 5 and B002 target prose applied first; B004 border prose remains callback-second. |
| VoteMenuPane file | UID0000P6 | Source root | file root | FILE | `91/92` | B002 target prose applied first; B004 border prose remains callback-second; no reconstruction metadata. |
| VoteMenuPane vtable cluster | UID0001Z1 | Compiler-generated support | false, non-emitting | UID0000FX semantic owner | `90/93` | Destination 3 applied. |
| VoteMenuPane layout | UID0001WH | Non-emitting layout support | false, non-emitting | UID0000FX semantic owner | `90/92` | Destination 4 applied. |
| Exact vtable data | UID0003CY | Read-only table child | verify-only in B002 | UID0000FX | unchanged | Existing source-declared/generated-binary evidence remains compatible. |

## Direct Xref / Caller Inventory

| Address / item | Xref / caller / callee | Meaning |
| --- | --- | --- |
| `0x00623040 -> 0x00555c70` | Primary vtable data reference | Only target liveness route; virtual dispatch. |
| `0x00555913 -> 0x00622ff8` | Raw constructor store | Installs primary VoteMenuPane view. |
| `0x00555975 -> 0x00622ff8` | Ordinary destructor restore | Lifecycle ownership. |
| `0x0055634c -> 0x00622ff8` | Scalar wrapper restore | Compiler-wrapper lifecycle parity. |
| `0x00555c86 -> 0x00457a60` | Direct call | Initializes local tile context. |
| `0x00555c9c -> 0x004d02f0` | Direct call | Resource layout lookup. |
| `0x00555ccd -> 0x004ba6b0` | Direct call | Tiled-background draw. |
| `0x004816d0` / vtable `0x00614f74` | ChattingVarietySelectPane comparator | Separate same-shape source method. |
| `0x005552f0` / vtable `0x00622fb0` | RightButtonMenuPane comparator | Separate same-shape source method. |
| `0x005bd5b0` / vtable `0x00630e10` | MenuVarietySelectPane comparator | Separate same-shape source method. |

## Documentation Evidence And IDA Status

Current applied documentation facts:

- UID00004I declares the exact EPFTileContext layout and `Initialize`.
- UID0000BY documents `LookupLayoutEntry` as the producer that fills an
  EPFTileContext from a resource name and entry index.
- UID0000QU documents `g_pEPFLib` as ImageLib-owned singleton/facet storage
  exposing that lookup family.
- UID00016A and UID00005V document `DrawTiledBackground`,
  `m_visibleBounds`, and `m_drawMode`.
- UID0000A2 and UID0001VH explicitly supersede generic Pane `m_bounds` at
  `+0x44` with inherited `GrafPort::m_visibleBounds`.
- UID0000BU supplies the accepted `RectBounds` declaration.
- UID0000FX declares `virtual void DrawBackground()` and now carries the
  compile-facing `struct EPFTileContext;` plus
  `typedef EPFTileContext FrameDrawRecord;` alias without changing layout,
  access, methods, or child ordering.

Evidence-time / pre-callback documentation defects, now superseded:

- UID0002LV used seven descriptive or stale source tokens.
- UID0001FY was reconstructable/emitting despite describing itself as a
  non-duplicating index.
- UID0001Z1 was reconstructable/emitting despite its compiler-generated
  no-code policy.
- UID0001WH was reconstructable/emitting despite declaring that UID0000FX
  owns the source fields.
- Generated output therefore had one stale target body and three support empty
  markers.

Current applied disposition:

- UID0002LV is `92/94` with exact Destination 1 and no stale target token.
- UID0001FY is semantic-owner-retaining false/non-emitting blank-formal
  `90/93`.
- UID0001Z1 is semantic-owner-retaining false/non-emitting blank-formal
  `90/93`.
- UID0001WH is semantic-owner-retaining false/non-emitting blank-formal
  `90/92`.
- UID0000FX is `90/92` with byte-equal Destination 5; UID0000P6 is prose-only
  `91/92`.
- Validator commands 14383-14387 and 14393 applied the ordinary state.
  Current generated readback has one exact UID0002LV body and zero target or
  support Empty Emitter Markers.
- B004's evidence-time UID0002LW report is complete report-only research, not
  an ordinary implementation. Its latest observed SHA `DD82...1CB4` carries the
  same final class/file scores and explicitly preserves B002's UID0001FY
  `90/93`, UID0001Z1 `90/93`, and UID0001WH `90/92` false/non-emitting
  support plan. Current `by-structure.md` sections 265-267 and the generated
  marker evidence therefore have one collision-free shared disposition across
  both observed reports; a later B004 successor remains a callback-time reread.

Generated state is validator-owned and volatile. Historical command
`000000014382` proves the pre-callback defect. Authorized waited command
`000000014396` completed the callback refresh; latest read-only header
`000000014399` is recorded as the post-callback evidence snapshot without
asserting future header stability.

## Ranked Ownership Analysis

### 1. UID0000FX VoteMenuPane class

- Evidence for:
  - target is a primary VoteMenuPane vtable slot;
  - current class declaration already names the virtual;
  - adjacent methods and lifecycle code are class-owned;
  - the body consumes only inherited GrafPort state and shared resource APIs.
- Evidence against:
  - no direct code caller exists, as expected for a virtual.
- Decision: direct semantic owner and emitter. Retain UID0000FX.

### 2. UID0000P6 VoteMenuPane source file

- Evidence for:
  - class and exact children already emit in one VoteMenuPane source root;
  - target address lies inside the VoteMenuPane method island;
  - resource use and helper order match the class's background/border role.
- Evidence against:
  - shared render/resource dependencies live elsewhere, but dependency
    ownership does not move the method.
- Decision: source root remains `NexusTK/ui/menu/VoteMenuPane.cpp`.

### 3. Shared GrafPort or SUBWIN helper ownership

- Evidence for:
  - the target calls shared GrafPort and resource APIs;
  - four classes contain same-shape source.
- Evidence against:
  - each class has a distinct body and vtable cell;
  - target does not define the shared callees;
  - no common wrapper function is called.
- Decision: dependencies/comparator evidence only. Reject ownership transfer.

### Proposed new file/grouping, if applicable

- Not applicable. No new file, helper, class, table, global, or child is
  justified.
- A hypothetical shared SUBWIN helper is rejected because the binary contains
  four independent bodies and no callable helper route.

## Source Placement

- Recommended placement:
  `NexusTK/ui/menu/VoteMenuPane.cpp`, emitted through UID0000FX into
  UID0000P6.
- Required source-visible type route: include the EPFTileContext declaration
  through the established image/render header route and emit Destination 5's
  `FrameDrawRecord` typedef before the VoteMenuPane class. No by-file
  reconstruction metadata is needed.
- Method order remains class declaration, constructor, destructor,
  OnMouseEvent, OnDismiss, OnPaint, DrawBackground, DrawBorder, singleton, and
  file-local helpers under the current first-seen route.
- Optional emitter position remains blank. Assigning a position only to this
  method would move it ahead of unpositioned earlier methods, so a target-only
  position would be incorrect.
- Rejected placements:
  - GrafPort.cpp: owns the callee, not this virtual;
  - ImageLib/ResourceLayoutTable.cpp: owns the resource lookup;
  - RightButtonMenuPane.cpp, Chatting.cpp, or MenuVariety source: comparator
    classes only;
  - a new SUBWIN utility source: no callable body or unique source object.

## Range / Split / Padding / Reclassification Analysis

- Target boundary is exact and needs no split or merge.
- `[0x00555c68,0x00555c70)` and
  `[0x00555ce1,0x00555cf0)` remain ignored alignment.
- UID0002LW begins exactly at `0x00555cf0` and remains separate.
- UID0001FY is a documentation/index aggregate, not a distinct source object.
  Exact child pages carry every source body, so false/non-emitting is the
  correct container disposition.
- UID0001Z1 and UID0001WH are source-declared support: the class declaration
  causes compiler tables and owns layout fields. They do not emit separate
  source.
- B004's evidence-time report is not a competing owner for those support
  pages. It is a separately owned sibling-method report whose coordinated plan
  is additive and callback-second, explicitly preserving B002's support
  dispositions. Its earlier pre-coordination `89/92`/true aggregate snapshot
  is historical and no longer a current recommendation.
- UID0003CY remains exact read-only-data evidence. B002 does not need to
  duplicate the same compiler disposition onto that unregistered/no-current-
  marker child absent callback-time drift.

## Negative Evidence Summary

- No direct code caller to UID0002LV.
- No second data/pointer xref to the target.
- No branch, loop, failure path, fallback, null check, or return-value use.
- No context release, heap allocation, object destructor, draw-mode restore,
  or invalidation.
- No call to `RectBounds::Inset`, `SetRect`, `FillTiledRect`,
  `SetDrawClipEnabled`, or a target-local SUBWIN helper.
- No evidence that `+0x70` is clip enable, Pane mode, visibility, or dirty
  state.
- No evidence that `+0x44` is VoteMenuPane-local or generic Pane-owned
  `m_bounds`.
- No evidence that same-shape siblings share one emitted function.
- No evidence for a new source file or helper.
- No named IDA UDT/type survives for the inferred source declarations.
- No reason to handwrite SIMD moves, security-cookie operations, vptr stores,
  table arrays, RTTI, adjustor thunks, or scalar-wrapper mechanics.

## IDA Rename / Type / Comment Recommendations

- Source-facing function name: `VoteMenuPane::DrawBackground`.
- Source-facing local names: `tile` and `backgroundBounds`.
- Source-facing local types: `EPFTileContext` and `RectBounds`.
- Source-facing compatible render alias:
  `typedef EPFTileContext FrameDrawRecord;`.
- Source-facing inherited fields: `m_visibleBounds`, `m_drawMode`.
- Source-facing calls:
  `EPFTileContext::Initialize`,
  `g_pEPFLib->LookupLayoutEntry`,
  and `DrawTiledBackground`.
- Suggested IDA comment at the target start:
  VoteMenuPane primary virtual; SUBWIN entry-8 inset tiled background.
- Suggested comments at offsets:
  - `+0x44`: inherited GrafPort visible bounds;
  - `+0x70`: inherited GrafPort draw mode.
- No IDA mutation was authorized or performed during research or callback.
- Historical `sub_555C70`, `dword_67A744`, and `off_610B74/off_610B8C`
  remain useful search aliases only.

## First-Draft C++ Recommendation

Destination 1, UID0002LV target, exact managed insertion text:

```cpp
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
void VoteMenuPane::DrawBackground()
{
    EPFTileContext tile;
    tile.Initialize();
    g_pEPFLib->LookupLayoutEntry(L"SUBWIN.EPF", 8, &tile);

    RectBounds backgroundBounds = m_visibleBounds;
    m_drawMode = 1;

    ++backgroundBounds.left;
    ++backgroundBounds.top;
    --backgroundBounds.right;
    --backgroundBounds.bottom;

    DrawTiledBackground(&backgroundBounds, &tile, L"SUBWIN.PAL");
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

Destination 2, UID0001FY aggregate, exact blank managed block after changing
the page to non-reconstructable/non-emitting:

```cpp
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

Destination 3, UID0001Z1 vtable cluster, exact blank managed block after
changing the page to non-reconstructable/non-emitting:

```cpp
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

Destination 4, UID0001WH layout support, exact blank managed block after
changing the page to non-reconstructable/non-emitting:

```cpp
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

Destination 5, UID0000FX complete VoteMenuPane class formal. Preserve every
existing declaration and add only the source-compatible frame-record alias:

```cpp
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
struct PaneMouseEvent;
struct PaneEvent;
struct Rect;
struct EPFTileContext;
typedef EPFTileContext FrameDrawRecord;

class VoteMenuPane : public Pane
{
public:
    VoteMenuPane(int voteType, const wchar_t *targetName);
    virtual ~VoteMenuPane();

protected:
    virtual bool OnMouseEvent(const PaneMouseEvent *event);
    virtual bool OnDismiss(const PaneEvent *event);
    virtual void OnPaint();
    virtual void DrawBackground();
    virtual void DrawBorder();

private:
    enum {
        kPromoteRow = 0,
        kDemoteRow = 1,
        kNoVoteRow = -1
    };

    unsigned char m_voteRowPressed;       // +0xf8
    signed char m_highlightedVoteRow;     // +0xf9
    unsigned char m_reservedFA[2];        // +0xfa..+0xfb alignment
    int m_voteType;                       // +0xfc; constructor context, not row submit flag
    wchar_t m_targetName[0x21];           // +0x100
};

extern VoteMenuPane *g_pVoteMenuPane;

static void GetVoteMenuItemRect(int row, Rect *rect);
static int HitTestVoteMenuItem(int x, int y);
static void SubmitVote(const wchar_t *targetName, unsigned char voteFlag);

[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

Why Destination 1 preserves behavior:

- all explicit calls, literals, values, state writes, rectangle operations, and
  call order match the complete one-block body;
- no unobserved checks or cleanup are added;
- compiler-only cookie/SIMD details are omitted;
- direct edge operations match the absence of an out-of-line inset call.
- Destination 5 changes no class layout or method declaration. Its typedef
  gives the two accepted names for the same 0x28-byte source record and makes
  the existing `DrawTiledBackground` declaration accept Destination 1's local
  without a cast or copy.

Why it matches plausible period source:

- ordinary stack locals and direct member calls;
- no reverse-engineering casts, raw addresses, synthetic wrappers, templates,
  lambdas, or modern helpers;
- names follow current project render/UI conventions.

## Final Recommendation

- Destination 1 is applied to UID0002LV at `92/94`; owner/emitter UID0000FX,
  true, blank optional position, `Nested:0`, exact range, and title are
  retained.
- June descriptive helper/body provenance is preserved as explicitly
  historical and superseded.
- Exact target evidence is incorporated into UID0000FX, UID0000P6, and
  UID0001FY without loss of unrelated content.
- Destinations 2-4 and their accepted metadata are applied; aggregate,
  vtable, and layout support are semantic-owner-retaining, false,
  non-emitting, and marker-free.
- Destination 5 is applied byte-for-byte to UID0000FX. The EPFTileContext local
  is compile-compatible with the accepted FrameDrawRecord-named API without a
  cast, duplicate object, or wrapper.
- UID0002LW remains unchanged under B004 ownership. The complete B002 baseline
  records its current `86/90` metadata and pre-callback body only. It is ready
  for B004's later serialized reread/rebase; B004 must preserve all B002
  support metadata, alias, background facts, and unrelated union content.
- Verify-only UID0003CY and shared graphics/resource/type pages were reread;
  no concrete contradiction required an edit.
- No child, rename, split, source route move, global, wrapper, or third-party
  import was introduced.

## Recommended Target Doc Changes

Target:
`by-memory/0x00555c70-0x00555ce1.VoteMenuPaneDrawBackground.md`.

Applied:

- score `86/90 -> 92/94`;
- retain UID/path/title/range/owner/emitter/reconstructable/blank position/
  `Nested:0`;
- replace formal body with Destination 1;
- replace Item Summary with a complete source-ready summary of the exact
  113-byte, 39-instruction, one-block method;
- add exact target SHA, resource string hashes, vtable liveness, callee roles,
  compiler exclusions, local type, inherited field names, direct inset
  arithmetic, no-check/no-cleanup/no-restore behavior, comparator inventory,
  source placement, rejected alternatives, and score rationale;
- preserve June findings as explicitly historical/superseded assumptions.

Applied target Item Summary:

Fresh live IDA MCP proves the exact 113-byte, 39-instruction, one-block
primary-vtable DrawBackground virtual: initialize a local 0x28-byte
EPFTileContext, load SUBWIN.EPF entry 8 through g_pEPFLib, copy inherited
GrafPort visible bounds, set inherited draw mode 1, inset each edge by one
pixel, and call GrafPort::DrawTiledBackground with SUBWIN.PAL; exact
bytes/hash, resource data, vtable-only liveness, padding, same-shape sibling
comparators, compiler-cookie exclusion, no cleanup/failure/restore branch, and
source-ready formal C++ are documented.

## Recommended Support Doc Changes

1. `by-class/VoteMenuPane.md`:
   - installed Destination 5, preserving every existing declaration and adding
     only `struct EPFTileContext;` plus
     `typedef EPFTileContext FrameDrawRecord;` before the class;
   - added exact UID0002LV source behavior, inherited fields/helpers, resource
     literals, sibling-copy evidence, and stale-helper historicalization;
   - raised `89/91` to exactly `90/92`;
   - established B002's background baseline first; B004's report then adds its
     border delta at the same score without replacing B002 or unrelated facts.
2. `by-file/VoteMenuPane.md`:
   - kept source path and no reconstruction metadata;
   - added exact UID0002LV source order, graphics/resource dependencies,
     EPFTileContext header/FrameDrawRecord alias visibility,
     no-duplicate/no-wrapper decision, and B004 shared-lane coordination;
   - raised `90/90` to exactly `91/92`;
   - established B002's background baseline first; B004 then adds its
     border delta while preserving the complete source union.
3. `by-memory/0x005558d0-0x0055606d.VoteMenuPaneCore.md`:
   - set `90/93`, retained semantic owner UID0000P6;
   - set reconstructable false, blank emitter/position/formal;
   - preserved every child/padding/lifecycle fact and updated UID0002LV to
     `92/94` exact source-ready state;
   - labeled old blank-reconstructable marker state historical.
4. `by-type/by-vtable/VoteMenuPaneVtables.md`:
   - set `90/93`, retained semantic owner UID0000FX;
   - set reconstructable false, blank emitter/position/formal;
   - preserved all table bases, slots, stores, thunks, boundaries, and source
     declaration causation.
5. `by-type/by-struct/VoteMenuPaneLayout.md`:
   - set `90/92`, retained semantic owner UID0000FX;
   - set reconstructable false, blank emitter/position/formal;
   - preserved every field/offset and state-use fact because UID0000FX already
     emits the declaration.
6. UID0002LW:
   - remained comparison/coordination only for B002;
   - B004 owns its report and any target body;
   - evidence-time B004 report SHA256 is
     `DD82D3866C35019AD8AB02EFD50605AEE3C7CD22E79276EEF8784D616EC81CB4`
     at the latest final coordination read;
   - B004 callback is second for shared pages and must preserve B002's stronger
     UID0001FY/UID0001Z1/UID0001WH dispositions.
7. UID0003CY, UID00004I, UID0000BY, UID0000QU, UID00016A, UID00005V,
   UID0000A2, UID0001VH, and UID0000BU:
   - verified read-only; no concrete drift required an edit.

## Score And Metadata Recommendation

| UID | Before | Applied | Metadata disposition |
| --- | --- | --- | --- |
| UID0002LV | `86/90` | `92/94` | Retain owner/emitter UID0000FX, true, blank position, Nested0; install Destination 1. |
| UID0000FX | `89/91` | `90/92` | Retain UID0000P6 owner/emitter, true, position0; Destination 5 preserves the complete class, adds the EPFTileContext/FrameDrawRecord alias, and carries B002 background evidence. B004 border prose remains pending its separate callback. |
| UID0000P6 | `90/90` | `91/92` | Retain FILE owner and `NexusTK/ui/menu/`; no by-file reconstruction metadata; current state contains the B002 baseline while B004's border delta remains pending. |
| UID0001FY | `88/91` | `90/93` | Retain semantic owner UID0000P6; false, blank emitter/position/formal. |
| UID0001Z1 | `85/90` | `90/93` | Retain semantic owner UID0000FX; false, blank emitter/position/formal. |
| UID0001WH | `87/90` | `90/92` | Retain semantic owner UID0000FX; false, blank emitter/position/formal. |
| UID0002LW | `86/90` | unchanged/B004 decision | B002 no target edit. |

Score-blocker audit:

- Helper names: resolved to current accepted member/global APIs.
- Field names: resolved to inherited `m_visibleBounds` and `m_drawMode`.
- Local types: resolved to `EPFTileContext` and `RectBounds`.
- Resource names/data: exact bytes and hashes recovered.
- Source shape: complete one-block method reconstructed.
- Liveness: vtable-only route and lifecycle stores proven.
- Source placement: existing class/file route proven.
- Split/range: exact and unchanged.
- C++ blocker: closed with Destinations 1 and 5; current helper parameter names
  are compile-compatible without a cast.
- Remaining original spelling uncertainty: local names and whether the
  EPFTileContext/FrameDrawRecord alias originally lived in a shared header or
  the source file are not symbol-proven. They do not change behavior or
  compile-era plausibility and justify staying below 95.

## Open Questions With Attempted Resolution

- Is the target dead because it has no direct caller?
  - No. The primary vtable cell and lifecycle stores prove virtual liveness.
- Is `+0x70` a clip-enable Boolean?
  - No. Current GrafPort and caller evidence prove a draw-mode byte; value `1`
    is passed to the tile-render callback.
- Is the bounds field `m_bounds`?
  - Historical target-family docs used that alias. Current Pane/GrafPort
    evidence resolves the physical field as inherited `m_visibleBounds`.
- Should source call `RectBounds::Inset(1,1)`?
  - The exact target has no such call. Direct edge mutations are the strongest
    behavior-identical representation and avoid inventing an inline/out-of-line
    choice.
- Is the local a `FrameDrawRecord`?
  - The initializer plus ResourceLayout producer identify the concrete local as
    an EPFTileContext-shaped resource record. The shared draw API may expose an
    alias/view in original headers, but no cast or second local exists in the
    binary. `EPFTileContext` is the safest target-local spelling, and
    Destination 5 uses the already accepted exact alias
    `typedef EPFTileContext FrameDrawRecord;` to satisfy the current helper
    declaration.
- Do the three duplicate bodies imply one covered-by source?
  - No. Each has a distinct address and vtable cell. A shared inherited body
    would normally produce a common target pointer; no common wrapper is
    called.
- Is explicit tile cleanup required?
  - No cleanup call exists. The lookup supplies borrowed frame pointers and the
    target returns directly after drawing.
- Should the draw mode be restored?
  - No restore exists in the complete body; adding one would change state.
- Does UID0002LW need B002 repair to make UID0002LV source-ready?
  - No. UID0002LV compiles and behaves through already-declared
    `DrawBackground`; B004 owns DrawBorder independently. B004's evidence-time
    report SHA `DD82...1CB4` explicitly makes its shared callback second, so
    it can rebase over B002 without target collision; any later B004 successor
    must preserve or explicitly reconcile that order.
- Do B002 and B004 disagree about UID0001FY?
  - Their evidence-time score/state text differs. B004 retains the older
    reconstructable `89/92` aggregate snapshot, while current
    `by-structure.md` requires false for a reviewed index-only container whose
    exact children emit all source. B002 therefore sets UID0001FY false at
    `90/93`; B004's no-loss second callback adds only border prose and must not
    revert that stronger current-rule disposition.
- Any unresolved blocker that prevents Destination 1?
  - No.

## Exact Manual Supervisor-Owned Coverage Or Tracker Text

Read-only manual snapshots at final callback reconciliation:

- `by-memory/-coverage-report.md`: SHA256
  `9BDD57D6A8C1F5849E266E134A28BDDA2714E493961A4811DC3C41A046EEA1CC`,
  `1,787,822` bytes / `4,276` lines; UID0001FY at line 2900, UID0002LV at
  line 2910, and UID0002LW at line 2912.
- `by-class/-coverage-report.md`: SHA256
  `CB0FAFE2951D401180E105D419F7CF46B19092ABA2BC024CDF9762A93223DF8F`,
  `230,735` bytes / `622` lines; UID0000FX at line 593.
- `by-file/-coverage-report.md`: SHA256
  `280C5E3D281D8166B3950851F0E450F841A54623A20D02C7514FE221C4E14E57`,
  `132,360` bytes / `316` lines; UID0000P6 at line 302.
- `by-type/by-vtable/-coverage-report.md`: SHA256
  `5A4301D55512C1824F78B310113A22FDEB3EC458BBBB7B9D2C9A43C3BFDA7057`,
  `65,209` bytes / `142` lines; UID0001Z1 at line 131.
- `by-type/by-struct/-coverage-report.md`: SHA256
  `1B794F9B0E9AD32D6A0901FC69E9CA99C6F335B26D50E12881DEDFAC4C6F80A6`,
  `57,045` bytes / `137` lines; UID0001WH at line 126.

Supervisor-only exact replacements:

File/placement: `by-memory/-coverage-report.md`, replace UID0001FY row:

```text
    - [UID:0001FY][0x005558d0-0x0055606d.VoteMenuPaneCore](by-memory/0x005558d0-0x0055606d.VoteMenuPaneCore.md) 0x005558d0-0x0055606d | aggregate class-method index | VoteMenuPaneCore : ignored : 90% : very strong : Exact non-duplicating VoteMenuPane core index at 90/93 preserves the raw constructor boundary, every exact method child, all internal and successor padding, vtable/helper routes, and source/compiler distinctions while remaining semantic file-owned support with blank formal C++. Current applied children include exact 92/94 UID0002LU OnPaint and B002's exact 92/94 UID0002LV EPFTileContext/m_drawMode/m_visibleBounds background body. UID0002LW remains the separate B004-owned reconstructable 86/90 border child with its current pre-callback body and is pending B004's serialized callback; no future 92/94 score, local-coordinate body, loop inventory, or frame inventory is asserted as current. The aggregate emits no duplicate body or Empty Emitter Marker.
```

File/placement: `by-memory/-coverage-report.md`, replace UID0002LV row:

```text
      - [UID:0002LV][0x00555c70-0x00555ce1.VoteMenuPaneDrawBackground](by-memory/0x00555c70-0x00555ce1.VoteMenuPaneDrawBackground.md) 0x00555c70-0x00555ce1 | method | VoteMenuPaneDrawBackground : reconstructable : 92% : very strong : Fresh B002 live MCP proves the exact 0x71-byte, 39-instruction, one-block primary-vtable VoteMenuPane::DrawBackground method and SHA256 04DF87088E9AEBFF0C23EA55C65C93EDEFEF470865D40A5BA719A9B208183E40; it initializes EPFTileContext, loads SUBWIN.EPF entry 8 through g_pEPFLib, copies inherited GrafPort m_visibleBounds, sets inherited m_drawMode to 1, directly insets all four edges by one pixel, and calls GrafPort::DrawTiledBackground with SUBWIN.PAL. Vtable-only liveness, exact padding, resource bytes/hashes, three same-shape but separately emitted sibling methods, no lookup/fallback/cleanup/restore branch, compiler exclusions, rejected stale helper aliases, class/file ownership, and exact formal C++ are documented.
```

File/placement: `by-class/-coverage-report.md`, replace UID0000FX row:

```text
- [UID:0000FX][VoteMenuPane](by-class/VoteMenuPane.md) : reconstructable : 90% : very strong : VoteMenuPane at 90/92 remains attached to [UID:0000P6][VoteMenuPane](by-file/VoteMenuPane.md) with its complete Pane-derived declaration, EPFTileContext/FrameDrawRecord compatibility alias, three vtable views, singleton, tail layout, row constants, target name, file-local helpers, class closure before children, and compiler-wrapper exclusions. UID0002LU retains exact direct GrafPort paint behavior, and UID0002LV resolves DrawBackground through EPFTileContext::Initialize, g_pEPFLib, inherited m_drawMode/m_visibleBounds, direct one-pixel inset, and DrawTiledBackground. UID0002LW remains the separate B004-owned reconstructable 86/90 DrawBorder child with its current pre-callback body, pending B004's serialized callback; this row does not pre-apply B004's future score, local-coordinate body, loops, frames, or RenderTileFrame route. Historical target-local m_bounds and synthetic clip/fill/resource aliases are superseded for UID0002LV only; no cast, new helper declaration, owner transfer, duplicate body, or handwritten compiler table is introduced by the B002 baseline.
```

File/placement: `by-file/-coverage-report.md`, replace UID0000P6 row:

```text
- [UID:0000P6][VoteMenuPane](by-file/VoteMenuPane.md) : reconstructable : 91% : very strong : NexusTK/ui/menu/VoteMenuPane.cpp at 91/92 retains the complete class/method/helper/singleton source split, EPFTileContext header and FrameDrawRecord alias visibility, exact child ranges, packet behavior, SUBWIN resource behavior, compiler-wrapper exclusions, and generated route. UID0002LU preserves exact direct-call OnPaint C++, and UID0002LV emits exact source-ready background drawing through EPFTileContext, g_pEPFLib, inherited GrafPort m_drawMode/m_visibleBounds, direct one-pixel inset, and DrawTiledBackground. UID0002LW remains the separate B004-owned reconstructable 86/90 border child with one current pre-callback generated body and is pending B004's serialized callback; no future B004 score, local-coordinate source, loop/frame inventory, lookup frequency, or RenderTileFrame implementation is represented as currently applied. The B002 baseline introduces no cast, new synthetic background helper, duplicate body, or handwritten ABI source.
```

File/placement: `by-type/by-vtable/-coverage-report.md`, replace UID0001Z1
row:

```text
- [UID:0001Z1][VoteMenuPaneVtables](by-type/by-vtable/VoteMenuPaneVtables.md) : ignored : 90% : very strong : Exact primary/secondary/tertiary VoteMenuPane vtable support at 90/93 with all bases, slot targets, constructor/destructor/scalar-wrapper stores, RTTI/string boundaries, adjustor thunks, and helper distinctions preserved. Semantic owner remains [UID:0000FX][VoteMenuPane](by-class/VoteMenuPane.md), whose class declarations and exact method children regenerate the tables; this compiler-generated cluster is non-reconstructable/non-emitting and produces no handwritten table or Empty Emitter Marker.
```

File/placement: `by-type/by-struct/-coverage-report.md`, replace UID0001WH
row:

```text
- [UID:0001WH][VoteMenuPaneLayout](by-type/by-struct/VoteMenuPaneLayout.md) : ignored : 90% : very strong : Exact VoteMenuPane layout support at 90/92 retains the three view offsets, m_voteRowPressed +0xf8, m_highlightedVoteRow +0xf9, alignment +0xfa..+0xfb, m_voteType +0xfc, m_targetName[0x21] +0x100, row geometry, and normalized secondary-view evidence. Semantic owner remains [UID:0000FX][VoteMenuPane](by-class/VoteMenuPane.md), whose class formal already emits the fields; this layout page is non-reconstructable/non-emitting and produces no duplicate declaration or Empty Emitter Marker.
```

No manual coverage edit is requested for the UID0002LW target row from B002;
B004 owns that row. The shared UID0001FY/UID0000FX/UID0000P6 replacement text
above describes only the current B002-applied baseline, adds B002's
compile-facing EPFTileContext/FrameDrawRecord alias closure, and preserves
UID0002LW as the separate B004-owned `86/90` child pending callback. It
deliberately omits B004's future `92/94` score and future border-body details.
After B004 completes its own callback, B004 or the supervisor must provide the
then-current no-loss successor rows. B002 must not edit any manual coverage
file.

Final readback confirms all six B002-owned current rows remain stale relative
to the applied ordinary metadata, so the exact replacement text above remains
the supervisor-owned B002-baseline handoff. No manual row was edited by B002.
Supervisor coverage application at this stage must not pre-apply pending B004
border work; later B004 coverage synchronization must rebase over these rows
without losing B002 facts.

## Follow-Up Actions

- B002's accepted implementation, scoped validators, waited generated
  verification, report reconciliation, and lease release are complete.
- UID0002LW remains B004-owned. Any later B004 callback must reread the current
  class/file/aggregate baseline, starting from current UID0002LW `86/90`, and
  apply only its accepted border delta without reverting B002 or unrelated
  content.
- The exact six-row manual coverage handoff remains in this report. Manual
  coverage application and all report validation/execution/move/archive state
  are supervisor/validator-owned; the exact current report path and any
  validator-owned lifecycle footer are authoritative.
- B002 does not run `execute_report` or any report lifecycle command.
- No A-agent work, IDA mutation, new child, rename, split, source-route move,
  wrapper, or third-party import is required.

## Confidence

- Range/boundary/hash: very strong.
- Liveness and class ownership: very strong.
- Resource strings/index and helper identities: very strong.
- Field names and source behavior: very strong.
- Source file/order: very strong.
- Exact original local spelling and shared EPFTileContext/frame-record header
  alias: strong but not final-symbol proof.
- Target score recommendation `92/94`: very strong.
- Support reclassification: very strong.

## Validator Results

- Scoped validator command:
  `python .\tools\validator.py --mode file --file <path> --apply --queue-timeout 240`.

| Command ID | Timestamp | Destination | Exit / ok | Result and target-specific side effects |
| --- | --- | --- | --- | --- |
| `000000014383` | `2026-07-16T16:43:57-04:00` | UID0002LV target | `0 / 1` | Applied `92/94` and target formal hash update; generated refresh deferred. |
| `000000014384` | `2026-07-16T16:45:07-04:00` | UID0001FY aggregate | `0 / 1` | Applied `90/93`, true -> false, emitter UID0000P6 -> blank; generated refresh deferred. |
| `000000014385` | `2026-07-16T16:45:52-04:00` | UID0001Z1 vtable | `0 / 1` | Applied `90/93`, true -> false, emitter UID0000FX -> blank; removed reconstructable stats row and recommended later broad rescore; generated refresh deferred. |
| `000000014386` | `2026-07-16T16:46:32-04:00` | UID0001WH layout | `0 / 1` | Applied `90/92`, true -> false, emitter UID0000FX -> blank; added UID0002LV reference, removed reconstructable stats row, and recommended later broad rescore; generated refresh deferred. |
| `000000014387` | `2026-07-16T16:47:25-04:00` | UID0000FX class | `0 / 1` | Applied `90/92` and Destination 5 registry hash; generated refresh deferred. |
| `000000014393` | `2026-07-16T16:48:21-04:00` | UID0000P6 file | `0 / 1` | Applied `91/92`, added UID0002LV reference; generated refresh deferred. |
| `000000014396` | `2026-07-16T16:48:42-04:00` | UID0000P6 final `--wait-generated` | `0 / 1` | Rebuilt 5,092-node/4,097-edge autogen registry, refreshed 280 generated metadata outputs, and completed generated refresh. |

- Commands 14383-14393 produced no target-specific warning or error. The
  final broad generated refresh reported existing project-wide diagnostics:
  `autogen_children_fallback_insert:13`,
  `autogen_children_marker_missing:85`, and
  `autogen_emitter_has_no_code:142`. The displayed examples were unrelated
  pages; none names UID0002LV, UID0001FY, UID0001Z1, UID0001WH, UID0000FX, or
  UID0000P6.
- Authorized waited refresh command is `000000014396`. Later concurrent
  validator activity advanced the volatile generated header. Latest read-only
  `auto-generated/NexusTK/ui/menu/VoteMenuPane.cpp` snapshot:
  - header command `000000014399`;
  - refreshed `2026-07-16T16:49:17-04:00`;
  - SHA256
    `5FF63C1DBCDC73CA6F40591AF6780A0312B221D49236590288B636C706381AD6`;
  - `8,257` bytes / `272` lines.
- Independent generated assertions:
  - exactly one complete `VoteMenuPane : public Pane` class;
  - exactly one `typedef EPFTileContext FrameDrawRecord;` before the class;
  - exactly one UID0002LV definition and exactly one UID0002LW definition;
  - UID0002LV contains one `tile.Initialize`, one `LookupLayoutEntry` with
    `SUBWIN.EPF`/8, one `m_visibleBounds` copy, one `m_drawMode = 1`, all four
    direct edge mutations, and one `DrawTiledBackground` with `SUBWIN.PAL`;
  - target block contains zero `InitEPFTileContext`,
    `LoadResourceLayoutTile`, `SetDrawClipEnabled`, `SetRect`, `FillTiledRect`,
    target-local `Rect`, or target-local `m_bounds`;
  - zero UID0002LV, UID0001FY, UID0001Z1, or UID0001WH Empty Emitter Markers;
  - UID0002LW's generated pre-B004 body remains present exactly once and its
    ordinary page hash is unchanged;
  - no handwritten vtable, RTTI, adjustor, scalar-wrapper, cookie, or raw
    address source was introduced. Existing unrelated UID0001G3/UID0001FZ
    markers remain outside this callback.
- Report lifecycle/probe/count/revalidation/execute commands run by B002:
  none.

## Changed Files

- Same report updated in place:
  `tools/leaser/Agents/Agent-B002/research/0002LV-VoteMenuPaneDrawBackground-source-quality.md`.
- Ordinary changed files:

| Path | Before SHA256 / bytes / lines | Current SHA256 / bytes / lines | Lease / validator |
| --- | --- | --- | --- |
| `by-memory/0x00555c70-0x00555ce1.VoteMenuPaneDrawBackground.md` | `54ACD079...A822` / 6,500 / 92 | `70B78AB115846DE326A30CCE90237E07AB59C8F8F1F8E87599CEF5340838C523` / 9,777 / 155 | B002 lease released; 14383 |
| `by-memory/0x005558d0-0x0055606d.VoteMenuPaneCore.md` | `B0BF6485...A865` / 20,288 / 131 | `30EF35FFB91B65C021F418008B44B77732093578F4DF791047AD34A12F3AA3FE` / 22,521 / 175 | B002 lease released; 14384 |
| `by-type/by-vtable/VoteMenuPaneVtables.md` | `7FE50F5D...ADF0` / 11,158 / 105 | `08061D4275E25ED6E2D3A776C846FAAF323B925213F0CF9D8A99C71DA1756822` / 12,774 / 147 | B002 lease released; 14385 |
| `by-type/by-struct/VoteMenuPaneLayout.md` | `CA5AD94A...D629` / 9,919 / 82 | `FEE4938C2DF76C570F6F0ECE5271A7D5A7D6AD66667F53334E27E10E3903EC77` / 11,810 / 118 | B002 lease released; 14386 |
| `by-class/VoteMenuPane.md` | `0FD33C3C...3DC8` / 19,265 / 156 | `D94517A8C5872A419006B1BB6E3DB3DC8A1A90E8667FECC1F70AB32AB3EB037F` / 21,968 / 215 | B002 lease released; 14387 |
| `by-file/VoteMenuPane.md` | `70271629...3977` / 16,822 / 120 | `91C0F3DCD97309FFE4983056F444F860433AFADBA4F53E12541AE96ED12C5605` / 20,430 / 176 | B002 lease released; 14393 and waited 14396 |

- Read-only UID0002LW target remains SHA256
  `1D3F948371C7FFB7C672939E8228FAE0C61D3EA4384D595B9D6796DD7158EBD6`,
  `8,479` bytes / `105` lines.
- Verify-only dependencies reread unchanged: UID0003CY
  `CC322C88...F823`, EPFTileContext `7EC740D8...7F28`,
  ResourceLayoutTable `2DF0FDC0...3D64`, g_pEPFLib `871E781E...157`,
  GrafPort `F1AD6340...053C`, Pane `C0A7AFC8...52EA`, PaneLayout
  `93749A6E...FE89`, and RectBounds `71005750...370E`.
- B002 manually changed no `-coverage-report.md`, generated, tracker, audit,
  supervisor, validator-state, lifecycle, archive, or IDA file. Generated and
  projected-stat changes above are validator-owned side effects.
- Renamed/created ordinary files: none. New UIDs/splits/source moves: none.
- All six ordinary leases were short, serial, and explicitly released. Current
  B002 lease count: zero.
- Report execution/lifecycle/move/archive commands: none.

## Implementation Tracking Checklist

Initial report-only requirements:

- [x] Supervisor Gate 1 authorization matched accepted SHA before implementation.
- [x] Confirm this report contains exactly the permitted Action values
  `incorporate`, `already-present`, `historicalize`, `reject-stale`,
  `reject-invalid`, `not-applicable`.
- [x] Terminalize every ledger Verification state as `applied` or
  `excluded-with-reason` with separate proof.
- [x] Recheck whether callback evidence required a fresh MCP pass; no outage,
  session-dependent failure, or new binary blocker required additional IDA work.
- [x] Apply UID0002LV target `92/94` metadata while retaining UID0000FX
  owner/emitter, reconstructable true, blank position, and Nested0.
- [x] Apply Destination 1 byte-for-byte.
- [x] Apply Destination 5 byte-for-byte, preserving the complete UID0000FX
  class and adding only the EPFTileContext/FrameDrawRecord alias.
- [x] Apply the exact target Item Summary and full range/hash/instruction/CFG/
  vtable/resource/type/field/helper/negative/history/score evidence.
- [x] Preserve the exact eight-byte predecessor and fifteen-byte successor
  padding.
- [x] Historicalize stale `InitEPFTileContext`, `SetDrawClipEnabled`,
  `LoadResourceLayoutTile`, `FillTiledRect`, `SetRect`, target-local `Rect`,
  and target-local `m_bounds` claims.
- [x] Update UID0000FX at report-level detail without losing its complete class
  formal or unrelated B003/B014 evidence; preserve the new alias in B004's
  callback-second rebase.
- [x] Update UID0000P6 at report-level detail without adding by-file
  reconstruction metadata.
- [x] Update UID0001FY to `90/93`, semantic owner UID0000P6, false,
  non-emitting, blank position/formal, preserving every child and padding row.
- [x] Update UID0001Z1 to `90/93`, semantic owner UID0000FX, false,
  non-emitting, blank position/formal, preserving all vtable evidence.
- [x] Update UID0001WH to `90/92`, semantic owner UID0000FX, false,
  non-emitting, blank position/formal, preserving all layout evidence.
- [x] Reread verify-only UID0003CY and shared EPFTileContext,
  ResourceLayoutTable, g_pEPFLib, GrafPort, Pane, PaneLayout, and RectBounds
  pages; no concrete callback-time contradiction required an edit.
- [x] Do not edit or lease UID0002LW; B004 owns that target.
- [x] Before shared edits, reread B004's evidence-time artifact
  `DD82...1CB4` and current ordinary result; preserve B002-first/B004-second
  complete-union ordering without circular hash churn.
- [x] Lease only one ordinary file immediately before editing.
- [x] Reread each destination after acquiring its lease.
- [x] Run one scoped validator per changed ordinary page.
- [x] Release each lease immediately after its scoped validator.
- [x] Run final UID0000P6 validation with `--wait-generated`.
- [x] Verify generated exact target count/body/token assertions.
- [x] Verify generated VoteMenuPane.cpp contains exactly one source-visible
  EPFTileContext/FrameDrawRecord alias before the class and no target cast.
- [x] Verify UID0001FY/UID0001Z1/UID0001WH support markers are gone.
- [x] Verify no UID0002LW body/detail was overwritten.
- [x] Preserve exact historical reports, rejected alternatives, negative
  evidence, and B002/B004 collision order.
- [x] Preserve no-new-child/no-split/no-rename/no-third-party-import
  disposition.
- [x] Keep exact supervisor-owned manual coverage rows in this report; B002
  does not edit coverage.
- [x] Update C01-C30 to legal terminal callback states with destination proof.
- [x] Record every changed-file before/after hash.
- [x] Record validator command, command ID, timestamp, exit, ok, warnings, and
  side effects for each changed page.
- [x] Record final generated header, hash, bytes, lines, and semantic readback.
- [x] Confirm zero leases and zero prohibited edits.

Implementation callback pass:

- [x] Exact Gate-1-passed report authorization matched before ordinary edits.
- [x] All accepted target/support details incorporated at report-level depth.
- [x] C01-C30 terminalized as applied, already-present,
  excluded-with-reason, or blocked with exact proof.
- [x] Every accepted metadata/formal/prose/history item applied or explicitly
  dispositioned.
- [x] B004 ownership/link and current UID0002LW `86/90` pre-callback state
  preserved without pre-applying its future border score/body; callback-second
  no-loss rebase remains explicit.
- [x] Scoped validators and final waited generated assertions passed.
- [x] Manual coverage handoff reread and updated to callback-time current
  hashes/anchors without B002 edits.
- [x] Changed Files, Validator Results, current state, and checklist reconciled.
- [x] All leases released.
- [x] No execute_report, lifecycle, move, archive, generated, coverage,
  tracker, audit, supervisor, validator-state, or IDA mutation performed.

READY_FOR_SUPERVISOR_GATE2_REVIEW

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B002","command_id":"000000014423","destination_path":"executed-b-agent-research/B002/0002LV-VoteMenuPaneDrawBackground-source-quality.md","details":"report executed into central archive","event":"executed","source_path":"tools/leaser/Agents/Agent-B002/research/0002LV-VoteMenuPaneDrawBackground-source-quality.md","timestamp":"2026-07-16T17:11:59-04:00","uid":"0002LV"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
