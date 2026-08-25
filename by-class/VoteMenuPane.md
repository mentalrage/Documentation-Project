*** UID:0000FX | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:93 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:95 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000P6 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000P6 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL:0 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
#include "VoteMenuPane.h"

static void GetVoteMenuItemRect(int row, RectBounds *bounds);
static signed char HitTestVoteMenuItem(int y, int x);
static void SubmitVote(const wchar_t *targetName, bool promote);

[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
class Event;
struct EPFTileContext;
typedef EPFTileContext FrameDrawRecord;

class VoteMenuPane : public Pane
{
public:
    VoteMenuPane(int voteType, const wchar_t *targetName);
    virtual ~VoteMenuPane();

protected:
    virtual bool HandlePointerOrMouseEvent(Event *event);
    virtual bool HandleKeyOrTextEvent(Event *event);
    virtual void OnPaint();
    virtual void DrawBackground();
    virtual void DrawBorder();

private:
    enum {
        kPromoteRow = 0,
        kDemoteRow = 1,
        kNoVoteRow = -1
    };

    bool m_voteRowPressed;
    signed char m_highlightedVoteRow;
    int m_voteType;
    wchar_t m_targetName[0x21];
};

extern VoteMenuPane *g_pVoteMenuPane;
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# VoteMenuPane

## Status

- Confidence: very strong for the complete declaration, natural layout, vtable stores,
  singleton lifecycle, helper ownership, row/packet behavior, exact
  source-ready OnPaint, DrawBackground, and DrawBorder bodies, source
  placement, exact helper interfaces, and compiler-glue exclusions. Remaining completion caps are the raw
  constructor's lack of a direct static caller, intentionally broad
  `m_voteType` semantics, inferred original spellings, the exact historical
  header location of the ABI-compatible frame-record alias, and whether the
  repeated direct border sequence originated in a header or was copied
  manually.
- Likely source file: [UID:0000P6][VoteMenuPane](by-file/VoteMenuPane.md)
- Parent handling: attached to [UID:0000P6][VoteMenuPane](by-file/VoteMenuPane.md)
  at emitter position `0`; this class is `93/95` and the direct file parent is
  `91/92`. The class page emits the complete declaration/prototype layer before
  child method bodies; exact source bodies remain on
  [UID:0002LQ][0x005558d0-0x00555945.VoteMenuPaneRawConstructor](by-memory/0x005558d0-0x00555945.VoteMenuPaneRawConstructor.md)-[UID:0002LZ][0x00556100-0x00556211.VoteMenuPaneSubmitVote](by-memory/0x00556100-0x00556211.VoteMenuPaneSubmitVote.md).
  [UID:0001G3][0x00556320-0x005563cd.VoteMenuPaneScalarDeletingDestructor](by-memory/0x00556320-0x005563cd.VoteMenuPaneScalarDeletingDestructor.md)
  remains compiler-generated and formally blank.
- Historical recovered-source lead:
  `source-3/simroot_v2/class_VoteMenuPane.cpp`; current generated/source route
  is `NexusTK/ui/menu/VoteMenuPane.cpp`.
- Singleton: [UID:0000SP][g_pVoteMenuPane](by-global/g_pVoteMenuPane.md) at [UID:0001Q0][0x0069ba38-0x0069ba3c.g_pVoteMenuPane](by-memory/0x0069ba38-0x0069ba3c.g_pVoteMenuPane.md)
- Vtables: [UID:0001Z1][VoteMenuPaneVtables](by-type/by-vtable/VoteMenuPaneVtables.md)
- EventHandler contract: inherited through Pane at complete-object `+0xa0`; the secondary table maps `HandlePointerOrMouseEvent(Event *)` to `+0x04` and `HandleKeyOrTextEvent(Event *)` to `+0x08`. VoteMenuPane does not list EventHandler as a second direct base.

## Class Purpose

`VoteMenuPane` is a two-option SUBWIN popup for target-player voting. It tracks Promote/Demote hover and selection state, draws the popup, and sends the selected vote request for the stored target player name.

## Source Reconstruction Policy

The formal H block declares the `Pane`-derived class, row constants, confirmed
tail fields, and `g_pVoteMenuPane` singleton. The CPP block includes that
header, declares the three file-local helpers with their recovered exact
interfaces, and places `[[CHILDREN]]` once so exact by-memory children emit
out-of-class method/helper bodies. The H block also declares `EPFTileContext`
and the accepted source-compatible `FrameDrawRecord` alias before the class. That alias makes
UID0002LV's local context compile-visible to the inherited
`DrawTiledBackground(const FrameDrawRecord *)` declaration without a cast,
copy, wrapper, or second record object. The CPP prototype ordering is required
because emitted child bodies call `HitTestVoteMenuItem`,
`GetVoteMenuItemRect`, and `SubmitVote`.

The raw constructor at `0x005558d0` has no rel32 call/jump refs and no absolute-VA raw-start pointer hits, but the body is a complete source-authored constructor with lifecycle/vtable/global evidence. That negative caller evidence caps the score below final audit, not the ability to emit the class shell or first-draft constructor. The class does not own the scalar deleting destructor or secondary adjustor thunks as source methods; those remain compiler-generated ABI products of the declared destructor.

The formal H uses the canonical `Event` declaration already shared by Pane/EventHandler. The historical `PaneMouseEvent` and `PaneEvent` overlays are not class APIs: no valid concrete `PaneMouseEvent` UDT supports the old declaration, `PaneEvent` is absent, and the exact secondary-slot order plus stack cleanup identifies the two legal overrides. The compiler-generated `this - 0xa0` adjustment remains absent from source.

`DrawBorder` intentionally uses the inherited `GrafPort` rendering surface directly. The class declaration needs no `DrawSubwinTile` or other border-only helper: the accepted child body initializes `EPFTileContext`, uses `RectBounds`/`InitRectBounds`/`OffsetRect`, performs direct `g_pEPFLib->LookupLayoutEntry` calls, and invokes inherited `RenderTileFrame`. Historical `DrawSubwinTile` wording is retained only as superseded reconstruction provenance.

Rejected alternatives remain rejected: the vote helpers are not `BulletinSession`, CashShop, inbound packet, or `RightButtonMenuPane` source. `RightButtonMenuPane` only coordinates cleanup after a vote; VoteMenuPane owns the popup behavior and outbound opcode `0x46` packet sender path.

## Method Notes

| Method/helper | Address | Role |
| --- | --- | --- |
| `VoteMenuPane` | [UID:0002LQ][0x005558d0-0x00555945.VoteMenuPaneRawConstructor](by-memory/0x005558d0-0x00555945.VoteMenuPaneRawConstructor.md) | Raw constructor-shaped code; source-facing direction `VoteMenuPane::VoteMenuPane(int voteType, const wchar_t *targetName)`. It calls `Pane::Pane(mode=1)`, sets `g_pVoteMenuPane`, initializes vote-row state, stores `m_voteType`, installs vtables, and copies `targetName`. |
| `~VoteMenuPane` | [UID:0002LR][0x00555950-0x005559bc.VoteMenuPaneDestructor](by-memory/0x00555950-0x005559bc.VoteMenuPaneDestructor.md) | Clears the singleton and removes/destroys pane state. |
| `HandlePointerOrMouseEvent` | [UID:0002LS][0x005559c0-0x00555ad5.VoteMenuPaneOnMouseEvent](by-memory/0x005559c0-0x00555ad5.VoteMenuPaneOnMouseEvent.md) | EventHandler pointer/mouse override; reads canonical Event type/y/x fields, handles hover/down/up, hit-tests Promote/Demote, calls `SubmitVote`, and closes the right-click menu only after a valid submission. |
| `HandleKeyOrTextEvent` | [UID:0002LT][0x00555ae0-0x00555aef.VoteMenuPaneOnDismiss](by-memory/0x00555ae0-0x00555aef.VoteMenuPaneOnDismiss.md) | EventHandler key/text override; ignores its Event payload, marks the pane for deferred deletion, and returns false. |
| `OnPaint` | [UID:0002LU][0x00555af0-0x00555c68.VoteMenuPaneOnPaint](by-memory/0x00555af0-0x00555c68.VoteMenuPaneOnPaint.md) | Source-void primary virtual: draws background/border, performs four direct inherited `MoveTo`/`DrawWideText` Promote/Demote passes at signed midpoint minus 24, gates signed highlighted rows 0/1, obtains the fixed row rectangle, and draws the five-pixel-inset four-edge bevel with palette indices 128/143 reversed by pressed state. |
| `DrawBackground` | [UID:0002LV][0x00555c70-0x00555ce1.VoteMenuPaneDrawBackground](by-memory/0x00555c70-0x00555ce1.VoteMenuPaneDrawBackground.md) | Exact `92/94` source-void primary virtual: initializes local `EPFTileContext`, loads `SUBWIN.EPF` entry 8 through `g_pEPFLib`, copies inherited `m_visibleBounds`, sets inherited `m_drawMode` to 1, directly insets all four edges by one, and calls inherited `DrawTiledBackground` with `SUBWIN.PAL`; no failure, fallback, cleanup, restore, null check, or synthetic wrapper. |
| `DrawBorder` | [UID:0002LW][0x00555cf0-0x00556012.VoteMenuPaneDrawBorder](by-memory/0x00555cf0-0x00556012.VoteMenuPaneDrawBorder.md) | Exact `92/94` source-void primary virtual: initializes one local `EPFTileContext` and zero-origin 7x7 `RectBounds`, derives local width/height from inherited `m_visibleBounds`, performs frame lookups in exact order `1/6/3/4/0/2/5/7`, preserves four mandatory edge `do` loops and four single-corner renders, and calls inherited `RenderTileFrame` with mode `1`, `SUBWIN.PAL`, and `NULL`; no guard, clamp, release, restore, lookup-result branch, enum, or synthetic border helper. |
| `GetItemRect` | [UID:0002LX][0x00556020-0x0055606d.VoteMenuPaneGetItemRect](by-memory/0x00556020-0x0055606d.VoteMenuPaneGetItemRect.md) | Computes the two vote-row rectangles. |
| `VoteMenuPaneHitTest` | [UID:0002LY][0x00556070-0x005560fb.VoteMenuPaneHitTest](by-memory/0x00556070-0x005560fb.VoteMenuPaneHitTest.md) | File-local two-row hit-test helper for Promote/Demote rows; generated `BulletinSession` ownership is rejected caller pollution. |
| `SubmitVote` | [UID:0002LZ][0x00556100-0x00556211.VoteMenuPaneSubmitVote](by-memory/0x00556100-0x00556211.VoteMenuPaneSubmitVote.md) | Sends opcode `0x46`, submode `0`, target name length/name bytes, and vote flag `1` for Promote row `0` or `0` for Demote row `1`. |
| destructor adjustor thunks | `0x00556228`, `0x00556233` | Compiler-generated secondary-base deleting-destructor thunks; vtable layout evidence only. |
| `ScalarDeletingDestructor` | [UID:0001G3][0x00556320-0x005563cd.VoteMenuPaneScalarDeletingDestructor](by-memory/0x00556320-0x005563cd.VoteMenuPaneScalarDeletingDestructor.md) | Compiler-generated scalar deleting destructor wrapper; keep formal C++ blank and model handwritten cleanup through `~VoteMenuPane`. |

## Layout Notes

- The class inherits from `Pane` and installs primary and secondary vtables at the same offsets as neighboring menu panes.
- State fields identified from constructor/decompile evidence: `m_voteRowPressed` at `+0xf8`, signed `m_highlightedVoteRow` at `+0xf9` with `-1` / `0xff` sentinel, natural two-byte alignment before `m_voteType` at `+0xfc`, and `m_targetName[0x21]` at `+0x100`. No source-declared padding member is required.
- Source-facing row constants are `kPromoteRow = 0`, `kDemoteRow = 1`, and `kNoVoteRow = -1`; submit helper flags are derived from the clicked row, not from `m_voteType`. Row `0` sends vote flag `1` for Promote, and row `1` sends vote flag `0` for Demote.
- Canonical Event kinds are modeled from the B003 event-flow reanalysis as cursor move `0`, left-button down `1`, and left-button up/release `3`. `HandlePointerOrMouseEvent` reads `m_type` at `+0x04` and pointer payload y/x at `+0x08/+0x0c`; hover updates `m_highlightedVoteRow`, down sets `m_voteRowPressed` if inside the local pane and otherwise marks the popup for deletion, and release submits only if a press was active.
- Mouse coordinates and the file-local hit-test interface use the established `(y, x)` order. `HitTestVoteMenuItem` returns `signed char` so `kNoVoteRow == -1` is preserved, and `SubmitVote` takes a source-level `bool promote` rather than a byte-shaped decompiler flag.
- Fixed row rectangles are `(0, 6, 79, 22)` for Promote and `(0, 22, 79, 38)` for Demote. `GetVoteMenuItemRect(-1)` returns the sentinel rectangle `(-1, -1, -1, -1)`.
- `OnPaint` reads `m_voteRowPressed` and signed `m_highlightedVoteRow` directly and uses the existing private row constants. Its inherited `MoveTo`, `DrawWideText`, `SetDrawColor`, and `LineTo` calls are legal through the `Pane`/GrafPort inheritance surface; no new VoteMenuPane helper declaration or access broadening is needed.
- `DrawBackground` reads inherited `GrafPort::m_visibleBounds` at
  `+0x44..+0x50` and writes inherited `GrafPort::m_drawMode` at `+0x70`.
  These are not VoteMenuPane tail fields. Historical target-local `m_bounds`
  and synthetic clip/fill/resource helpers are superseded.
- `DrawBorder` also reads inherited `m_visibleBounds`, but only to derive width
  and height. Its source and destination rectangles use a local zero origin;
  pane left/top are not added to edge or corner positions. The method's
  `EPFTileContext` and `RectBounds` objects are stack locals, not VoteMenuPane
  fields.
- See [UID:0001WH][VoteMenuPaneLayout](by-type/by-struct/VoteMenuPaneLayout.md).

## Evidence Notes

- Historical pre-UID0002LT generated output omitted `0x00556070` and `0x00556100` from the `VoteMenuPane` file even though IDA caller evidence tied both only to the method now reconstructed as `VoteMenuPane::HandlePointerOrMouseEvent`.
- Active generated output keeps `0x00556228` and `0x00556233` in the disabled companion; IDA confirms both as 0xb-byte functions.
- 2026-05-26 current generated output still has the same helper split. IDA still reports `0x005558d0` as not-a-function, and still confirms `0x00556070`, `0x00556100`, `0x00556228`, `0x00556233`, and `0x00556320` with the expected sizes.
- 2026-05-26 IDA MCP vtable pass confirms `VoteMenuPane` vtables at `0x00622ff8`, `0x0062304c`, and `0x0062307c`, installed by raw constructor stores at `0x00555913`, `0x00555919`, and `0x00555923`. Current Wave3 metadata still reports `vtable_count: 0`.
- `HandlePointerOrMouseEvent` is secondary-table slot `+0x04`; `HandleKeyOrTextEvent` is secondary-table slot `+0x08`. The two-row hit-test helper at `0x00556070` and vote-submit helper at `0x00556100` are direct callees, not vtable slots.
- Wave3 metadata notes stored method-name control characters for constructor/destructor/deleting destructor.
- 2026-05-31 IDA MCP recheck confirms the exact child function boundaries, `0x00556070`/`0x00556100` xrefs from `OnMouseEvent`, `0x00556020` xref from `OnPaint`, vtable xrefs from constructor/destructors, and `g_pVoteMenuPane` constructor/destructor writes.
- 2026-06-08 A008 IDA MCP recheck confirms the raw constructor tail-field layout (`+0xf8`, `+0xf9`, `+0xfc`, `+0x100`), vtable stores at `0x00555913`/`0x00555919`/`0x00555923`, destructor/scalar-destructor vtable restores, singleton refs at `0x0069ba38`, and direct calls from the method now reconstructed as `HandlePointerOrMouseEvent` to `VoteMenuPaneHitTest` and `SubmitVote`.
- 2026-06-17 B001 source-quality audit confirms `sub_544460` as `Pane::Pane(mode=1)`, keeps the raw constructor live through lifecycle/vtable/singleton evidence despite no static caller, recommends `VoteMenuPane::VoteMenuPane(int voteType, const wchar_t *targetName)`, and resolves the tail field directions to `m_voteRowPressed`, `m_highlightedVoteRow`, `m_voteType`, and `m_targetName[0x21]`. The report also rechecked [UID:0001Q0][0x0069ba38-0x0069ba3c.g_pVoteMenuPane](by-memory/0x0069ba38-0x0069ba3c.g_pVoteMenuPane.md) live bytes as zero-initialized.
- 2026-06-17 B003 source-quality audit confirms the event-kind split, `MarkForDeletion` dismissal path, `RightButtonMenuPane::CloseRightClickAndVoteMenus` close route after submit, `GetVoteMenuItemRect` / `HitTestVoteMenuItem` as VoteMenuPane file-local helpers, `dword_67A7EC` as the outbound packet sender path for `SubmitVote`, and `0x00556320` as compiler-generated scalar deleting destructor glue rather than handwritten source. It rejects the historical `BulletinSession` helper owner for [UID:0002LY][0x00556070-0x005560fb.VoteMenuPaneHitTest](by-memory/0x00556070-0x005560fb.VoteMenuPaneHitTest.md) and rejects CashShop/inbound packet interpretations for [UID:0002LZ][0x00556100-0x00556211.VoteMenuPaneSubmitVote](by-memory/0x00556100-0x00556211.VoteMenuPaneSubmitVote.md).
- 2026-07-15 B003 UID0002LU source-quality callback confirms `OnPaint` as one exact `0x178`-byte, 137-instruction, six-block primary virtual at slot `0x0062303c`, with source return `void` and no direct static caller because dispatch is vtable-based. It first calls `DrawBackground`/`DrawBorder`, draws exact seven-character Promote/Demote literals twice each at `(left+right)/2-24` and `+1`, gates signed rows 0/1, calls `GetVoteMenuItemRect`, and draws left/top then right/bottom edges with palette indices 128/143 reversed by `m_voteRowPressed`. The completed inherited GrafPort contracts prove direct `MoveTo`, `DrawWideText`, `SetDrawColor`, and `LineTo` calls; historical `DrawShadowedCenteredText`/`DrawVoteMenuHighlight` abstractions and outer/inner shade names are superseded, not class APIs.
- The accepted OnPaint formal introduces no handwritten vtable/RTTI arrays, cookie code, raw addresses, explicit compiler scaffolding, or cross-family helper. A rechecked Chatting selector is only evidence for an independently inlined drawing idiom and does not transfer ownership or require a shared declaration.
- 2026-07-16 B002 UID0002LV source-quality callback proves
  `VoteMenuPane::DrawBackground` is one exact 113-byte, 39-instruction,
  one-block virtual with full-byte SHA256
  `04DF87088E9AEBFF0C23EA55C65C93EDEFEF470865D40A5BA719A9B208183E40`
  and sole primary-vtable xref `0x00623040`. The raw constructor, ordinary
  destructor, and scalar wrapper install/restore primary base `0x00622ff8`;
  no direct static caller is expected.
- Exact dependencies are `EPFTileContext::Initialize`,
  `g_pEPFLib->LookupLayoutEntry`, inherited `m_visibleBounds` and
  `m_drawMode`, `RectBounds`, and inherited `DrawTiledBackground`. Resource
  literals are exact `SUBWIN.EPF` entry 8 and `SUBWIN.PAL`. Three separate
  same-shape vtable methods support a copied idiom but not a common helper or
  covered-by emitter.
- B004 retains exclusive target ownership of
  [UID:0002LW][0x00555cf0-0x00556012.VoteMenuPaneDrawBorder](by-memory/0x00555cf0-0x00556012.VoteMenuPaneDrawBorder.md).
  This B002 callback establishes the complete first shared baseline and does
  not alter the border body; B004's serialized callback must reread and
  preserve this declaration, alias, background facts, and unrelated union.
- 2026-07-16 B004 UID0002LW callback followed that serialized boundary and
  preserved the complete executed B002 declaration/background union. The
  border child is one exact `0x322`-byte, 292-instruction, nine-block primary
  virtual with full-byte SHA256
  `CF50B71B823746310492ED905E454767023DA03B91B3FC1AFFB016996FF91F45`
  and sole vtable cell `0x00623044`; constructor, ordinary-destructor, and
  scalar-wrapper stores establish live virtual dispatch despite zero direct
  static callers.
- The accepted border source model is one `EPFTileContext`, local 7x7
  `RectBounds` geometry, local width/height from inherited `m_visibleBounds`,
  frame order `1/6/3/4/0/2/5/7`, four mandatory `do` loops, and inherited
  `RenderTileFrame` calls with mode `1`, `SUBWIN.PAL`, and `NULL`. Three exact
  standalone comparators at `0x00555370`, `0x00481750`, and `0x005bd630` plus
  a larger inlined equivalent at `0x0045b630` support direct
  copied/header-inlined source. They do not justify a class helper.
- Historical pane-absolute loops, `m_bounds`, `DrawSubwinTile`, shared-helper,
  enum/table, compiler-generated, and no-code alternatives are superseded or
  rejected. No class declaration, helper prototype, cast, wrapper, duplicate
  record, vtable array, cookie source, or other B002 content was added or
  removed for the border callback.

## Cross-References

- [UID:0000P6][VoteMenuPane](by-file/VoteMenuPane.md)
- [UID:0001FY][0x005558d0-0x0055606d.VoteMenuPaneCore](by-memory/0x005558d0-0x0055606d.VoteMenuPaneCore.md)
- [UID:0001FZ][0x00556070-0x00556211.VoteMenuPaneHitTestAndSubmit](by-memory/0x00556070-0x00556211.VoteMenuPaneHitTestAndSubmit.md)
- [UID:0002LQ][0x005558d0-0x00555945.VoteMenuPaneRawConstructor](by-memory/0x005558d0-0x00555945.VoteMenuPaneRawConstructor.md)
- [UID:0002LS][0x005559c0-0x00555ad5.VoteMenuPaneOnMouseEvent](by-memory/0x005559c0-0x00555ad5.VoteMenuPaneOnMouseEvent.md)
- [UID:0002LY][0x00556070-0x005560fb.VoteMenuPaneHitTest](by-memory/0x00556070-0x005560fb.VoteMenuPaneHitTest.md)
- [UID:0002LZ][0x00556100-0x00556211.VoteMenuPaneSubmitVote](by-memory/0x00556100-0x00556211.VoteMenuPaneSubmitVote.md)
- [UID:0001Z1][VoteMenuPaneVtables](by-type/by-vtable/VoteMenuPaneVtables.md)
- [UID:0000SP][g_pVoteMenuPane](by-global/g_pVoteMenuPane.md)
- [UID:0001Q0][0x0069ba38-0x0069ba3c.g_pVoteMenuPane](by-memory/0x0069ba38-0x0069ba3c.g_pVoteMenuPane.md)
- [UID:0000C0][RightButtonMenuPane](by-class/RightButtonMenuPane.md)

## Changes

- 2026-05-30 completion/confidence scoring:
  - What existed before: `COMPLETION:0` and `CONFIDENCE:0`.
  - Changed to: `COMPLETION:84` and `CONFIDENCE:80`.
  - Summary/evidence: scored from the popup constructor/destructor/mouse/paint/background/border/rect/hit-test/submit/destructor-thunk map, layout offsets, singleton/vtable evidence, and helper ownership corrections; confidence remains capped because the constructor remains raw bytes rather than an IDA-modeled function.
- 2026-05-31 exact child page split:
  - What existed before: `RECONSTRUCTABLE` was blank, score was `84/80`, and the method table used mostly raw address text.
  - Changed to: `RECONSTRUCTABLE:TRUE`, score `86/84`, and method rows linked to exact child memory pages.
  - Summary/evidence: IDA MCP `lookup_funcs`, `decompile`, `xrefs_to`, `disasm`, and `get_bytes` verified the method boundaries, direct helper callers, vtable/global references, and child/padding split.
- 2026-06-07 parent attachment update:
  - Before: `AUTOGEN_PARENT_UID` was blank even though the class page and [UID:0000P6][VoteMenuPane](by-file/VoteMenuPane.md) already documented the same source owner.
  - Changed to: `AUTOGEN_PARENT_UID:0000P6` and autogen position `10`; reconstruction C++ remains blank.
  - Evidence: the file page scores `88/84`, proposes `NexusTK/ui/menu/`, and records the same constructor/destructor/input/paint/helper, singleton, and vtable ownership evidence.
- 2026-06-08 A008 Batch 128 parent-side refresh:
  - Before: score was `86/84`, which left the current strict parent confidence gate just below threshold for [UID:0001WH][VoteMenuPaneLayout](by-type/by-struct/VoteMenuPaneLayout.md).
  - Changed to: confidence `85`; completion stays `86`.
  - Evidence: live IDA MCP reconfirmed raw constructor layout stores, vtable install/restore xrefs, `g_pVoteMenuPane` singleton refs, `OnMouseEvent` direct calls to hit-test and submit helpers, and `OnPaint` state-byte reads. The score remains conservative because the constructor is still not an IDA-modeled function and final source helper/field names are not audited to final quality.
- 2026-06-17 B001 source-quality support refresh:
  - Summary/evidence: accepted constructor audit records source-facing constructor direction, `Pane::Pane(mode=1)`, row constants, final documentation names for the tail fields, and zero-initialized `g_pVoteMenuPane` storage. Class score is unchanged because formal constructor C++ and the caller-side semantics for `m_voteType` remain below final-output quality.
- 2026-06-17 B003 source-quality support refresh:
  - Summary/evidence: incorporated the event-kind map, row-to-vote-flag map, local helper names, outbound packet sender route, helper-owner rejections, and scalar deleting destructor no-C++ policy from the accepted VoteMenuPane report. Class score is unchanged because this page remains a class-level support page while the exact child pages carry the draft C++.
- 2026-06-19 B014 class source-quality implementation:
  - Changed to `COMPLETION:88`, `CONFIDENCE:90`, `EMITTER_POSITION_OPTIONAL:0`, and populated declaration-level class C++ with helper prototypes and `[[CHILDREN]]`.
  - Summary/evidence: incorporated the B014 class report after direct PE/Capstone recheck confirmed no raw constructor call/VA route, lifecycle refs through vtables and [UID:0000SP][g_pVoteMenuPane](by-global/g_pVoteMenuPane.md), method/helper caller routes, `Promote`/`Demote` strings, `SUBWIN` resource use, outbound opcode `0x46` packet layout, and compiler-generated adjustor/scalar-destructor no-code policy. The class shell now captures `m_voteRowPressed`, `m_highlightedVoteRow`, `m_voteType`, `m_targetName[0x21]`, row constants, and private helper prototypes while leaving exact method/helper bodies to by-memory children.
- 2026-07-15 B003 UID0002LU support synchronization:
  - Changed `88/90` to `89/91`; owner, emitter, position, and the complete managed class declaration remain unchanged.
  - Summary/evidence: exact OnPaint bytes/CFG/vtable route, source-void ABI, direct inherited GrafPort calls, signed row behavior, geometry, and historical synthetic-helper correction close one major class method while broader constructor/resource/helper spelling and `m_voteType` semantics retain the class-level cap.
- 2026-07-16 B002 UID0002LV implementation callback:
  - Changed `89/91` to `90/92`; owner UID0000P6, emitter UID0000P6,
    `RECONSTRUCTABLE:TRUE`, position `0`, and all unrelated declarations remain
    unchanged.
  - Applied complete Destination 5 byte-for-byte, adding only
    `struct EPFTileContext;` and
    `typedef EPFTileContext FrameDrawRecord;` before the class.
  - Added exact UID0002LV bytes/CFG/vtable/resource/field/body/negative/source
    evidence, historicalized stale helper/field aliases, preserved the B004
    border link, and introduced no background/border wrapper or handwritten
    compiler ABI source.
- 2026-07-16 B004 UID0002LW implementation callback:
  - Retained `90/92`, UID0000P6 owner/emitter, position `0`, and the complete
    B002-compatible declaration/formal block byte-for-byte.
  - Added the exact `92/94` DrawBorder child behavior, local-coordinate field
    interpretation, resource/render dependencies, vtable liveness,
    comparator-supported copied/header-inlined source decision, and
    historical correction of `DrawSubwinTile`.
  - Added no border helper declaration and preserved all constructor,
    DrawBackground, OnPaint, helper, singleton, vtable, layout, compiler
    exclusion, and unrelated class facts.
- 2026-07-26 B004 UID0001FZ implementation callback:
  - Raised `90/92` to `93/95`, moved the complete class declaration from the CPP channel to the H channel, and left only the header include, exact file-local helper prototypes, and one `[[CHILDREN]]` marker in CPP.
  - Reconciled `RectBounds`, signed `(y, x)` hit testing, boolean vote submission, inherited `m_visibleBounds`, and natural compiler alignment after the two one-byte state fields. Removed the synthetic explicit padding member while preserving all established class, resource, vtable, and child-method evidence.
- 2026-08-15 B008 UID0002LT accepted implementation callback:
  - Retained `93/95`, UID0000P6 owner/emitter, position `0`, CPP include/prototypes/`[[CHILDREN]]`, layout, singleton, and every unrelated declaration.
  - Replaced only the two stale event declarations with `class Event;`, `HandlePointerOrMouseEvent(Event *)`, and `HandleKeyOrTextEvent(Event *)`, matching Pane's inherited EventHandler contract and secondary slots `+0x04/+0x08`.
  - Historical `OnMouseEvent`/`PaneMouseEvent` and `OnDismiss`/`PaneEvent` forms remain dated superseded evidence rather than current class API. No direct EventHandler base, manual receiver adjustment, vtable array, RTTI record, or thunk source was added.
