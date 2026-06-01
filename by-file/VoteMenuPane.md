*** UID:0000P6 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"NexusTK/ui/menu/" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***

# VoteMenuPane

## Status

- Confidence: strong for behavior and VoteMenuPane source ownership; medium cap remains for exact original source split and final source names.
- Proposed module: `ui/menu/VoteMenuPane.cpp`
- Alternative compact placement: [UID:0000N7][RightButtonMenuPane](by-file/RightButtonMenuPane.md)
- Current recovered source: `source-3/simroot_v2/class_VoteMenuPane.cpp`
- Singleton: [UID:0000SP][g_pVoteMenuPane](by-global/g_pVoteMenuPane.md) at [UID:0001Q0][0x0069ba38-0x0069ba3c.g_pVoteMenuPane](by-memory/0x0069ba38-0x0069ba3c.g_pVoteMenuPane.md)

## File Role

`VoteMenuPane` is the small right-click vote popup used to promote or demote a target player. It draws a two-row SUBWIN-styled menu, tracks hover/selection state, sends the vote packet, and closes through the same owner/session dismissal path used by the right-click menu area.

This belongs in `ui/menu/` beside [UID:0000N7][RightButtonMenuPane](by-file/RightButtonMenuPane.md), not in [UID:0000HX][BulletinSession](by-file/BulletinSession.md). The current generated `BulletinSession` ownership for vote/right-click hit-test helpers is caller pollution.

## Proposed Contents

| Entity | Address | Current generated owner | Role |
| --- | --- | --- | --- |
| `VoteMenuPane` core methods | [UID:0001FY][0x005558d0-0x0055606d.VoteMenuPaneCore](by-memory/0x005558d0-0x0055606d.VoteMenuPaneCore.md) | `class_VoteMenuPane.cpp` | Constructor, destructor, input handler, paint, background/border draw, and item rectangle helper. |
| `VoteMenuPaneHitTest` | [UID:0002LY][0x00556070-0x005560fb.VoteMenuPaneHitTest](by-memory/0x00556070-0x005560fb.VoteMenuPaneHitTest.md) | `class_BulletinSession.cpp` | Two-row hit-test helper for Promote/Demote rows. |
| `SubmitVote` | [UID:0002LZ][0x00556100-0x00556211.VoteMenuPaneSubmitVote](by-memory/0x00556100-0x00556211.VoteMenuPaneSubmitVote.md) | not active as a `VoteMenuPane` method | Converts target name to multibyte and sends opcode `0x46` with the promote/demote flag. |
| [UID:0001Z1][VoteMenuPaneVtables](by-type/by-vtable/VoteMenuPaneVtables.md) | `0x00622ff8`, `0x0062304c`, `0x0062307c` | generated metadata reports `vtable_count: 0` | Primary, secondary, and tertiary virtual views for the vote popup. |
| destructor thunks | `0x00556228-0x0055623e` | disabled `class_VoteMenuPane.cpp` | Compiler-generated secondary-base deleting-destructor adjustor thunks; track for vtable layout but ignore as handwritten source. |
| scalar deleting destructor | `0x00556320-0x005563cd` | `class_VoteMenuPane.cpp` | Clears singleton, destroys pane/base state, and optionally frees memory. |
| [UID:0000SP][g_pVoteMenuPane](by-global/g_pVoteMenuPane.md) | [UID:0001Q0][0x0069ba38-0x0069ba3c.g_pVoteMenuPane](by-memory/0x0069ba38-0x0069ba3c.g_pVoteMenuPane.md) | `class_VoteMenuPane.cpp` | Active vote popup singleton. |

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
- IDA MCP callers show `0x00556070` and `0x00556100` are only called from `VoteMenuPane::OnMouseEvent`.
- IDA xrefs to `0x0069ba38` include `VoteMenuPane` constructor/destructors and `RightButtonMenuPane` event/cancel code.
- 2026-05-26 recheck: current `simroot_v2/class_VoteMenuPane.cpp` still omits the helper bodies at `0x00556070` and `0x00556100`; current `class_BulletinSession.cpp` still owns `0x00556070` under a generated `BulletinSession` method name.
- 2026-05-26 recheck: IDA decompiles the thunk pair at `0x00556228` and `0x00556233` as `this - 0xa0` / `this - 0xa4` adjustors that jump to `0x00556320`; these are now recorded in [UID:0000VN][-ignored](by-memory/-ignored.md).
- 2026-05-31 IDA MCP recheck split the core and helper aggregates into exact memory pages. `0x00556070` and `0x00556100` remain direct callees from [UID:0002LS][0x005559c0-0x00555ad5.VoteMenuPaneOnMouseEvent](by-memory/0x005559c0-0x00555ad5.VoteMenuPaneOnMouseEvent.md), confirming they belong in this source module rather than `BulletinSession`.

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
