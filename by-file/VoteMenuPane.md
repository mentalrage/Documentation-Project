*** UID:0000P6 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:93 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:95 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"NexusTK/ui/menu/" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:FILE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***

# VoteMenuPane

## Status

- Confidence: very strong for behavior, VoteMenuPane source ownership,
  header/source declaration and prototype ordering, layout/vtable anchors, singleton lifecycle,
  helper routing, packet behavior, exact source-ready OnPaint, DrawBackground,
  and DrawBorder emission, compiler exclusions, and generated-owner pollution
  rejection. Remaining completion caps are exact original spellings, the raw
  constructor's missing direct caller, broad `m_voteType` semantics, the
  original header location of the frame-record alias, and whether the repeated
  direct border source was copied manually or originated in a header.
- Proposed module: `ui/menu/VoteMenuPane.cpp`
- Alternative compact placement: [UID:0000N7][RightButtonMenuPane](by-file/RightButtonMenuPane.md)
- Historical recovered-source lead:
  `source-3/simroot_v2/class_VoteMenuPane.cpp`; current source/generated route
  is `NexusTK/ui/menu/VoteMenuPane.cpp`.
- Singleton: [UID:0000SP][g_pVoteMenuPane](by-global/g_pVoteMenuPane.md) at [UID:0001Q0][0x0069ba38-0x0069ba3c.g_pVoteMenuPane](by-memory/0x0069ba38-0x0069ba3c.g_pVoteMenuPane.md)

## File Role

`VoteMenuPane` is the small right-click vote popup used to promote or demote a target player. It draws a two-row SUBWIN-styled menu, tracks hover/selection state, sends the vote packet, and closes through the same owner/session dismissal path used by the right-click menu area.

This belongs in `ui/menu/` beside [UID:0000N7][RightButtonMenuPane](by-file/RightButtonMenuPane.md), not in [UID:0000HX][BulletinSession](by-file/BulletinSession.md). The current generated `BulletinSession` ownership for vote/right-click hit-test helpers is caller pollution.

Keep the source-authored class, methods, global, and private helpers in the
`VoteMenuPane.h` / `VoteMenuPane.cpp` pair. The class page
[UID:0000FX][VoteMenuPane](by-class/VoteMenuPane.md) emits the complete class
and singleton declaration through H; its CPP channel includes that header,
declares the three file-local helpers, and provides one `[[CHILDREN]]` marker.
Exact by-memory children then emit constructor, destructor, EventHandler pointer/mouse and key/text overrides,
paint, background, border, rectangle, hit-test, and submit bodies in
address/source order. The H declaration also makes `EPFTileContext` and the
source-compatible `FrameDrawRecord` alias visible before UID0002LV.
Compiler-generated vtable/RTTI/adjustor/scalar-destructor support remains
documented but non-emitting.

## Proposed Contents

| Entity | Address | Current generated owner | Role |
| --- | --- | --- | --- |
| `VoteMenuPane` core index | [UID:0001FY][0x005558d0-0x0055606d.VoteMenuPaneCore](by-memory/0x005558d0-0x0055606d.VoteMenuPaneCore.md) | semantic file-owned support | Exact non-reconstructable/non-emitting child and padding inventory; exact children carry constructor, destructor, input, paint, background/border, and item-rectangle source without a duplicate aggregate body or marker. |
| `VoteMenuPane::HandlePointerOrMouseEvent` | [UID:0002LS][0x005559c0-0x00555ad5.VoteMenuPaneOnMouseEvent](by-memory/0x005559c0-0x00555ad5.VoteMenuPaneOnMouseEvent.md) | `NexusTK/ui/menu/VoteMenuPane.cpp` | Exact canonical Event `m_type/y/x` handler: signed two-row hover hit test, visible-bounds press capture, outside dismissal, valid-release promote/demote submit, and menu close only after submission. |
| `VoteMenuPane::HandleKeyOrTextEvent` | [UID:0002LT][0x00555ae0-0x00555aef.VoteMenuPaneOnDismiss](by-memory/0x00555ae0-0x00555aef.VoteMenuPaneOnDismiss.md) | `NexusTK/ui/menu/VoteMenuPane.cpp` | Exact EventHandler key/text override: inherited `+0xa0` facet, one unused `Event *`, one `Pane::MarkForDeletion` call, false return, secondary slot `+0x08`, and no direct code caller. |
| `VoteMenuPane::OnPaint` | [UID:0002LU][0x00555af0-0x00555c68.VoteMenuPaneOnPaint](by-memory/0x00555af0-0x00555c68.VoteMenuPaneOnPaint.md) | `NexusTK/ui/menu/VoteMenuPane.cpp` | Exact source-ready primary virtual: background/border calls; four direct inherited label passes; signed row gate; fixed-row helper; five-pixel inset; four-edge palette reversal. |
| `VoteMenuPane::DrawBackground` | [UID:0002LV][0x00555c70-0x00555ce1.VoteMenuPaneDrawBackground](by-memory/0x00555c70-0x00555ce1.VoteMenuPaneDrawBackground.md) | `NexusTK/ui/menu/VoteMenuPane.cpp` | Exact `92/94` source-ready primary virtual: local EPFTileContext, `SUBWIN.EPF` entry 8 through `g_pEPFLib`, inherited `m_visibleBounds`/`m_drawMode`, direct one-pixel inset, and inherited `DrawTiledBackground` with `SUBWIN.PAL`; no synthetic wrappers or failure/cleanup/restore branch. |
| `VoteMenuPane::DrawBorder` | [UID:0002LW][0x00555cf0-0x00556012.VoteMenuPaneDrawBorder](by-memory/0x00555cf0-0x00556012.VoteMenuPaneDrawBorder.md) | `NexusTK/ui/menu/VoteMenuPane.cpp` | Exact `92/94` source-ready primary virtual: one `EPFTileContext`, zero-origin 7x7 `RectBounds`, local width/height from inherited `m_visibleBounds`, frame order `1/6/3/4/0/2/5/7`, four mandatory `do` loops, four corner renders, one `SUBWIN.EPF` lookup per edge/corner, and inherited `RenderTileFrame` with mode `1`, `SUBWIN.PAL`, and `NULL`; no synthetic helper or pane-absolute coordinate translation. |
| `GetVoteMenuItemRect` | [UID:0002LX][0x00556020-0x0055606d.VoteMenuPaneGetItemRect](by-memory/0x00556020-0x0055606d.VoteMenuPaneGetItemRect.md) | `NexusTK/ui/menu/VoteMenuPane.cpp` | File-local `RectBounds` initializer for the `-1` sentinel and exact fixed row rectangles. |
| `HitTestVoteMenuItem` | [UID:0002LY][0x00556070-0x005560fb.VoteMenuPaneHitTest](by-memory/0x00556070-0x005560fb.VoteMenuPaneHitTest.md) | `NexusTK/ui/menu/VoteMenuPane.cpp` | File-local signed-byte `(y, x)` two-row hit-test helper for Promote/Demote rows; historical `class_BulletinSession.cpp` placement is owner pollution. |
| `SubmitVote` | [UID:0002LZ][0x00556100-0x00556211.VoteMenuPaneSubmitVote](by-memory/0x00556100-0x00556211.VoteMenuPaneSubmitVote.md) | `NexusTK/ui/menu/VoteMenuPane.cpp` | Converts the nonempty target name to CP_ACP bytes and sends raw opcode `0x46`, submode `0`, one-byte target length, target bytes, and boolean Promote/Demote flag through `g_packetSender`. |
| [UID:0001Z1][VoteMenuPaneVtables](by-type/by-vtable/VoteMenuPaneVtables.md) | `0x00622ff8`, `0x0062304c`, `0x0062307c` | generated metadata reports `vtable_count: 0` | Primary, secondary, and tertiary virtual views for the vote popup. |
| destructor thunks | `0x00556228-0x0055623e` | disabled `class_VoteMenuPane.cpp` | Compiler-generated secondary-base deleting-destructor adjustor thunks; track for vtable layout but ignore as handwritten source. |
| scalar deleting destructor | [UID:0001G3][0x00556320-0x005563cd.VoteMenuPaneScalarDeletingDestructor](by-memory/0x00556320-0x005563cd.VoteMenuPaneScalarDeletingDestructor.md) | `class_VoteMenuPane.cpp` | Compiler-generated wrapper that restores vtables, routes cleanup/delete, supports the adjustor thunks, and should not emit handwritten source C++; source cleanup belongs in `~VoteMenuPane`. |
| [UID:0000SP][g_pVoteMenuPane](by-global/g_pVoteMenuPane.md) | [UID:0001Q0][0x0069ba38-0x0069ba3c.g_pVoteMenuPane](by-memory/0x0069ba38-0x0069ba3c.g_pVoteMenuPane.md) | `class_VoteMenuPane.cpp` | Active vote popup singleton. |

## Source Split

The accepted source shape is:

| Source piece | Owning doc | C++ policy |
| --- | --- | --- |
| class declaration, row constants, tail fields, and singleton declaration | [UID:0000FX][VoteMenuPane](by-class/VoteMenuPane.md) | H channel only; natural alignment after the two one-byte state fields. |
| source include, file-local helper prototypes, and child insertion point | [UID:0000FX][VoteMenuPane](by-class/VoteMenuPane.md) | CPP channel only: `#include "VoteMenuPane.h"`, exact `RectBounds`/signed `(y,x)`/`bool` helper interfaces, and one `[[CHILDREN]]`. |
| active singleton definition | [UID:0000SP][g_pVoteMenuPane](by-global/g_pVoteMenuPane.md) | `VoteMenuPane *g_pVoteMenuPane = NULL;` |
| raw constructor | [UID:0002LQ][0x005558d0-0x00555945.VoteMenuPaneRawConstructor](by-memory/0x005558d0-0x00555945.VoteMenuPaneRawConstructor.md) | First-draft `VoteMenuPane::VoteMenuPane(int voteType, const wchar_t *targetName)`; no manual vtable stores. |
| destructor/EventHandler pointer-mouse/EventHandler key-text/paint/background/border | [UID:0002LR][0x00555950-0x005559bc.VoteMenuPaneDestructor](by-memory/0x00555950-0x005559bc.VoteMenuPaneDestructor.md)-[UID:0002LW][0x00555cf0-0x00556012.VoteMenuPaneDrawBorder](by-memory/0x00555cf0-0x00556012.VoteMenuPaneDrawBorder.md) | Exact child method bodies in address/source order. UID0002LS and UID0002LT emit the two inherited EventHandler overrides; UID0002LU emits direct inherited paint calls; UID0002LV emits direct EPFTileContext/resource/bounds/mode/inset/background calls; UID0002LW emits the direct local-coordinate EPFTileContext/RectBounds/layout/render border sequence. No VoteMenuPane-local synthetic drawing wrapper is introduced. |
| private helpers | [UID:0002LX][0x00556020-0x0055606d.VoteMenuPaneGetItemRect](by-memory/0x00556020-0x0055606d.VoteMenuPaneGetItemRect.md)-[UID:0002LZ][0x00556100-0x00556211.VoteMenuPaneSubmitVote](by-memory/0x00556100-0x00556211.VoteMenuPaneSubmitVote.md) | File-local helper bodies for row rectangles, hit testing, and opcode `0x46` vote submission. |
| destructor adjustor thunks and scalar deleting destructor | [UID:0001G1][0x00556228-0x0055623e.VoteMenuPaneDestructorThunks](by-memory/0x00556228-0x0055623e.VoteMenuPaneDestructorThunks.md), [UID:0001G3][0x00556320-0x005563cd.VoteMenuPaneScalarDeletingDestructor](by-memory/0x00556320-0x005563cd.VoteMenuPaneScalarDeletingDestructor.md) | Compiler-generated ABI evidence; no handwritten C++. |

The old generated `class_BulletinSession.cpp` helper placement and CashShop/inbound-packet interpretations are stale owner pollution. Historical `OnMouseEvent`/`PaneMouseEvent` and `OnDismiss`/`PaneEvent` names are also superseded: the current H/CPP contract uses the canonical EventHandler overrides. `RightButtonMenuPane` remains a neighbor and cleanup consumer only; it does not own VoteMenuPane methods, helpers, or singleton storage.

Compilation/source ordering is the H class declaration plus frame-record alias
and singleton declaration; the CPP header include and file-local prototypes
come first in source, followed by exact constructor and
method children next in source/address order; file-local rectangle/hit-test/
submit helpers after methods; compiler ABI support excluded. This by-file page
records source placement only and intentionally has no reconstruction metadata
or managed C++ block.

## Ownership Decision

Keep `VoteMenuPane` as menu UI:

- It is address-adjacent to `RightButtonMenuPane` and uses the same SUBWIN frame style.
- It is selected/dismissed by the right-click menu path through `g_pVoteMenuPane`.
- It does not inspect board/mail article state, so `BulletinSession` is the wrong source owner for its hit-test helpers.
- The class has its own imported `VoteMenuPane.cpp` provenance and a distinct singleton.

## Evidence Notes

- IDA MCP confirms real functions at `0x00555950`, `0x005559c0`, `0x00555ae0`, `0x00555af0`, `0x00555c70`, `0x00555cf0`, `0x00556020`, `0x00556070`, `0x00556100`, `0x00556228`, `0x00556233`, and `0x00556320`.
- IDA MCP reports `0x005558d0` as `Not a function`, but disassembly shows a constructor-shaped body that calls the `Pane` constructor, sets `dword_69BA38`, writes three `VoteMenuPane` vtables, stores `voteType`, and copies a 0x21-wide-character target name.
- IDA MCP confirms vtable bases at `0x00622ff8`, `0x0062304c`, and `0x0062307c`, with raw constructor stores at `0x00555913`, `0x00555919`, and `0x00555923`; current `class_VoteMenuPane.meta_wave3` still reports `vtable_count: 0`.
- IDA MCP callers show `0x00556070` and `0x00556100` are only called from the method now reconstructed as `VoteMenuPane::HandlePointerOrMouseEvent`.
- IDA xrefs to `0x0069ba38` include `VoteMenuPane` constructor/destructors and `RightButtonMenuPane` event/cancel code.
- 2026-05-26 recheck: current `simroot_v2/class_VoteMenuPane.cpp` still omits the helper bodies at `0x00556070` and `0x00556100`; current `class_BulletinSession.cpp` still owns `0x00556070` under a generated `BulletinSession` method name.
- 2026-05-26 recheck: IDA decompiles the thunk pair at `0x00556228` and `0x00556233` as `this - 0xa0` / `this - 0xa4` adjustors that jump to `0x00556320`; these are now recorded in [UID:0000VN][-ignored](by-memory/-ignored.md).
- 2026-05-31 IDA MCP recheck split the core and helper aggregates into exact memory pages. `0x00556070` and `0x00556100` remain direct callees from [UID:0002LS][0x005559c0-0x00555ad5.VoteMenuPaneOnMouseEvent](by-memory/0x005559c0-0x00555ad5.VoteMenuPaneOnMouseEvent.md), confirming they belong in this source module rather than `BulletinSession`.
- 2026-06-08 A008 IDA MCP recheck reconfirmed raw constructor stores for `g_pVoteMenuPane`, three vtable bases, and the tail layout fields, plus destructor/scalar-destructor vtable restores, singleton refs, and direct calls from the pointer/mouse override to `0x00556070`/`0x00556100`. This is enough to bring file confidence to the current parent-gate threshold while retaining the final-source caveats.
- 2026-08-15 B008 UID0002LT source-quality callback identifies secondary EventHandler slot `+0x04` (`0x00623050`) as `HandlePointerOrMouseEvent(Event *)` and `+0x08` (`0x00623054`) as `HandleKeyOrTextEvent(Event *)`. The target's exact 16-byte body, one unused Event argument, `Pane::MarkForDeletion` call, false return, predecessor padding, immediate OnPaint successor, and constructor/destructor table stores preserve placement between UID0002LS and UID0002LU.
- 2026-06-17 B003 source-quality audit resolves [UID:0002LY][0x00556070-0x005560fb.VoteMenuPaneHitTest](by-memory/0x00556070-0x005560fb.VoteMenuPaneHitTest.md) and [UID:0002LZ][0x00556100-0x00556211.VoteMenuPaneSubmitVote](by-memory/0x00556100-0x00556211.VoteMenuPaneSubmitVote.md) as private VoteMenuPane helpers, not BulletinSession helpers. It also documents the hover/down/up event-kind behavior, `MarkForDeletion` outside-click dismissal, post-submit right-click/vote-menu close helper, fixed row rectangles, Promote/Demote flag mapping, packet layout, `dword_67A7EC` sender route, and compiler-generated scalar deleting destructor policy. CashShop/inbound packet and generic BulletinSession helper alternatives are rejected.
- 2026-07-15 B003 UID0002LU source-quality callback resolves the paint body as one source-authored primary virtual at `[0x00555af0,0x00555c68)`, `0x178` bytes, 137 instructions, six blocks, full-byte SHA256 `DAB99C735A0B92A28079F49EE87A9493532F52DEF4CDDD3DFFAEE16FB46AE4DB`, and vtable cell `0x0062303c`. Source signature is `void VoteMenuPane::OnPaint()`; no direct static caller is expected for virtual dispatch.
- The source-ready paint sequence calls `DrawBackground` then `DrawBorder`, computes `(m_visibleBounds.left + m_visibleBounds.right) / 2 - 24`, performs four direct `MoveTo`/`DrawWideText` calls for seven-character Promote/Demote labels at x and x+1, accepts only signed highlighted rows 0/1, calls file-local `GetVoteMenuItemRect`, and draws the `left+5`/`right-5` frame with direct `SetDrawColor`/`LineTo` calls. Pressed state assigns palette 128 to left/top and 143 to right/bottom; unpressed state reverses those edge roles.
- Direct GrafPort dependencies are `MoveTo`, `DrawWideText`, `SetDrawColor`, and `LineTo`. Historical `DrawShadowedCenteredText`, `DrawVoteMenuHighlight`, and outer/inner shade labels are unsupported reconstruction abstractions and are retained only as superseded provenance; there is no helper body, declaration, or macro contract to emit.
- The independently rechecked Chatting selector at `0x00481490` inlines a similar drawing idiom but differs in labels, six-row geometry, helper, and insets. It is comparator evidence for direct source statements, not a shared helper, source owner, or migration route.
- Historical generated command 13366 emitted one UID0002LU body with the two synthetic centered-text calls and one synthetic highlight call. That pre-callback snapshot is evidence of the defect being replaced, not a current source contract. Accepted output must contain one direct-call OnPaint body, no synthetic helper calls, no target Empty Emitter Marker, no duplicate/wrong-range body, and no handwritten vtable, RTTI, cookie, or raw-address source.
- 2026-07-16 B002 UID0002LV callback resolves the exact background virtual at
  `[0x00555c70,0x00555ce1)`: 113 bytes, 39 instructions, one block,
  full-byte SHA256
  `04DF87088E9AEBFF0C23EA55C65C93EDEFEF470865D40A5BA719A9B208183E40`,
  primary vtable cell `0x00623040`, and no direct static caller.
- The source body calls `EPFTileContext::Initialize`,
  `g_pEPFLib->LookupLayoutEntry(L"SUBWIN.EPF", 8, ...)`, copies inherited
  `GrafPort::m_visibleBounds`, writes inherited `m_drawMode = 1`, directly
  insets all four edges, and calls inherited `DrawTiledBackground` with
  `SUBWIN.PAL`. There is no return-value branch, fallback, null check,
  context release, mode restore, clipping wrapper, invalidation, or invented
  background helper.
- Exact resource SHA256 values are
  `7077915D0DE751D089340CB662D4C3C825030F2D53C74DEB49B7EF2A46A03C55`
  for `SUBWIN.EPF` and
  `845854037B679051CFF8F13ACBA39E9374CDE53DA44998AB2BED383DAA71430A`
  for `SUBWIN.PAL`. Separate same-shape primary virtuals show a copied idiom,
  not a shared emitter.
- B002 establishes the complete first shared class/file/aggregate baseline.
  B004 exclusively owns UID0002LW and must reread/rebase its later border
  callback without replacing UID0002LV, the frame-record alias,
  UID0001FY/UID0001Z1/UID0001WH non-emitting states, or unrelated source.
- The serialized B004 callback subsequently preserved that complete executed
  B002 baseline and added only UID0002LW's accepted border delta. The target is
  one exact `0x322`-byte, 292-instruction, nine-block source-void primary
  virtual with full-byte SHA256
  `CF50B71B823746310492ED905E454767023DA03B91B3FC1AFFB016996FF91F45`
  and primary vtable cell `0x00623044`; constructor, ordinary-destructor, and
  scalar-wrapper vtable stores prove liveness despite zero direct static
  callers.
- The exact file-level border behavior is local, not pane-absolute: initialize
  one `EPFTileContext`; initialize a zero-origin 7x7 `RectBounds`; derive only
  width/height from inherited `m_visibleBounds`; look up `SUBWIN.EPF` frames
  `1/6/3/4/0/2/5/7`; preserve four mandatory edge `do` loops and four corners;
  and call inherited `RenderTileFrame` with mode `1`, `SUBWIN.PAL`, and
  `NULL`. There is no guard, clamp, lookup-result branch, release, mode
  restore, extra file helper, or compiler-authored border source.
- Exact standalone comparator bodies at `0x00555370`, `0x00481750`, and
  `0x005bd630`, plus a larger inline equivalent at `0x0045b630`, preserve the
  same sequence and support copied/header-inlined source. They do not establish
  a shared emitter or justify a `DrawSubwinTile` declaration. The historical
  `DrawSubwinTile`, `m_bounds`, pane-left/top arithmetic, `for` loops, helper
  enum/table, and no-code alternatives remain only as rejected or superseded
  provenance.

## Cross-References

- [UID:0000FX][VoteMenuPane](by-class/VoteMenuPane.md)
- [UID:0001FY][0x005558d0-0x0055606d.VoteMenuPaneCore](by-memory/0x005558d0-0x0055606d.VoteMenuPaneCore.md)
- [UID:0001FZ][0x00556070-0x00556211.VoteMenuPaneHitTestAndSubmit](by-memory/0x00556070-0x00556211.VoteMenuPaneHitTestAndSubmit.md)
- [UID:0002LQ][0x005558d0-0x00555945.VoteMenuPaneRawConstructor](by-memory/0x005558d0-0x00555945.VoteMenuPaneRawConstructor.md)
- [UID:0002LS][0x005559c0-0x00555ad5.VoteMenuPaneOnMouseEvent](by-memory/0x005559c0-0x00555ad5.VoteMenuPaneOnMouseEvent.md)
- [UID:0002LY][0x00556070-0x005560fb.VoteMenuPaneHitTest](by-memory/0x00556070-0x005560fb.VoteMenuPaneHitTest.md)
- [UID:0002LZ][0x00556100-0x00556211.VoteMenuPaneSubmitVote](by-memory/0x00556100-0x00556211.VoteMenuPaneSubmitVote.md)
- [UID:0001Z1][VoteMenuPaneVtables](by-type/by-vtable/VoteMenuPaneVtables.md)
- [UID:0001G1][0x00556228-0x0055623e.VoteMenuPaneDestructorThunks](by-memory/0x00556228-0x0055623e.VoteMenuPaneDestructorThunks.md)
- [UID:0001G3][0x00556320-0x005563cd.VoteMenuPaneScalarDeletingDestructor](by-memory/0x00556320-0x005563cd.VoteMenuPaneScalarDeletingDestructor.md)
- [UID:0001WH][VoteMenuPaneLayout](by-type/by-struct/VoteMenuPaneLayout.md)
- [UID:0001Q0][0x0069ba38-0x0069ba3c.g_pVoteMenuPane](by-memory/0x0069ba38-0x0069ba3c.g_pVoteMenuPane.md)
- [UID:0000N7][RightButtonMenuPane](by-file/RightButtonMenuPane.md)
- [UID:0000MN][PopupMenuControls](by-file/PopupMenuControls.md)
- [Wave3 data issues](../wave3_data_issues.md)

## Changes

- Completion/confidence scoring: existed before as ungraded `0/0`; changed to `86/80`. Summary/evidence: the page documents the vote-popup source role, method families, IDA evidence, class refs, packet/menu behavior, and ownership caveats from generated helper pollution.
- 2026-05-31: Assigned validator reconstruction path.
  - Before: `PROPOSED_RECONSTRUCTION_PATH` was blank.
  - After: `PROPOSED_RECONSTRUCTION_PATH:"NexusTK/ui/menu/"`.
  - Evidence: [UID:0001R1][proposed-source-tree](by-project-structure/proposed-source-tree.md) places `VoteMenuPane.cpp` under `ui/menu`; IDA confirms the vote popup core and `g_pVoteMenuPane` lifecycle with RightButtonMenuPane dismissal reads.
- 2026-05-31: Exact memory split and source-ownership confidence update.
  - Before: the page scored `86/80` and referenced several items by raw address only.
  - After: the page scores `88/84` and links the core, hit-test, and submit contents to exact by-memory pages.
  - Evidence: IDA MCP verified the child function boundaries, the two helper xrefs from `OnMouseEvent`, and the split between executable helper bodies and `0xcc` alignment bytes.
- 2026-06-08 A008 Batch 128 strict-gate refresh:
  - Before: score was `88/84`, below the current 85 confidence gate for serving as the direct parent of [UID:0000FX][VoteMenuPane](by-class/VoteMenuPane.md).
  - After: confidence is `85`; completion remains `88`.
  - Evidence: live IDA MCP rechecked raw constructor stores, vtable install/restore refs, singleton refs, and direct hit-test/submit helper xrefs. The score stays below higher final-audit levels because original source split and final field/helper names remain open.
- 2026-06-17 B003 source-quality support refresh:
  - Summary/evidence: incorporated the accepted report's VoteMenuPane-local helper decisions, event-kind and row-flag mappings, packet-sender route, rejected alternative owners/protocol families, and scalar deleting destructor no-C++ policy. File score is unchanged because the exact child pages carry the updated scoring and C++ drafts.
- 2026-06-19 B014 class/file source-quality implementation:
  - Changed to `COMPLETION:89`, `CONFIDENCE:88`.
  - Summary/evidence: accepted the class-shell/prototype conclusion for `NexusTK/ui/menu/VoteMenuPane.cpp`, rejected generated `BulletinSession`/CashShop owner pollution, documented the exact source split across class, global, method/helper children, and compiler-glue support, and recorded that the file should emit the class declaration/prototypes before child method bodies.
- 2026-07-15 B003 UID0002LU support synchronization:
  - Changed `89/88` to `90/90`; `PROPOSED_RECONSTRUCTION_PATH:"NexusTK/ui/menu/"`, file ownership, source route, and all unrelated family content remain unchanged.
  - Summary/evidence: exact UID0002LU source emission, direct GrafPort dependencies, comparator classification, generated synthetic-helper history, and explicit no-helper/no-array exclusions close the file's OnPaint source-quality blocker while other existing constructor/helper caveats retain the score cap.
- 2026-07-16 B002 UID0002LV implementation callback:
  - Changed `90/90` to `91/92`; retained FILE ownership and
    `PROPOSED_RECONSTRUCTION_PATH:"NexusTK/ui/menu/"`.
  - Added the exact DrawBackground source/dependency/negative/compiler/history
    evidence, class-header EPFTileContext/FrameDrawRecord visibility, exact
    source order, and no-duplicate/no-wrapper contract.
  - Preserved all unrelated class/global/method/helper/compiler content and
    the B004-owned UID0002LW link. This by-file root received no reconstruction
    metadata or managed C++ block.
- 2026-07-16 B004 UID0002LW implementation callback:
  - Retained `91/92`, FILE ownership, the `NexusTK/ui/menu/` route, the full
    B002 source union, and the absence of by-file reconstruction metadata.
  - Added only the exact DrawBorder source body/behavior, resource/type/helper
    dependencies, vtable liveness, comparator-supported copied/header-inlined
    source placement, and historical correction of pane-absolute
    `DrawSubwinTile` reconstruction.
  - Preserved UID0002LV, the class alias/declaration, aggregate/vtable/layout
    non-emitting dispositions, all method/helper/compiler entries, and all
    unrelated VoteMenuPane evidence.
- 2026-07-26 B004 UID0001FZ implementation callback:
  - Raised `91/92` to `93/95`, retained FILE ownership and the `NexusTK/ui/menu/` route, and documented the accepted H/CPP split with one class declaration in H and only include/prototypes/children in CPP.
  - Reconciled the exact row geometry, signed `(y, x)` hit-test result, valid-release mouse behavior, CP_ACP raw-array opcode-`0x46` packet construction, boolean Promote/Demote flag, inherited `m_visibleBounds`, natural class alignment, and rejection of historical BulletinSession owner pollution.
- 2026-08-15 B008 UID0002LT accepted implementation callback:
  - Retained `93/95`, FILE ownership, the `NexusTK/ui/menu/` route, the complete class/global/helper/source union, and every compiler exclusion.
  - Synchronized the contents and source split to `HandlePointerOrMouseEvent(Event *)` followed by `HandleKeyOrTextEvent(Event *)`, then `OnPaint`, preserving exact address/source order and one declaration/definition route through UID0000FX.
  - Historical `OnMouseEvent`/`PaneMouseEvent` and `OnDismiss`/`PaneEvent` forms remain dated provenance only; no unrelated module content or by-file reconstruction metadata was introduced.
