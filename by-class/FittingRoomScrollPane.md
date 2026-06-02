*** UID:000054 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:72 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000JE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# FittingRoomScrollPane

## Status

- Confidence: strong for the local `0x0041d870-0x0041eb8c` scroll-pane interaction/draw core and medium for final source placement.
- Current Wave3 file: `class_FittingRoomScrollPane.cpp`
- Proposed source module: [UID:0000JE][FittingRoom](by-file/FittingRoom.md), with possible later move to `ui/core/ScrollBar.cpp`
- Autogen status: reconstructable class attached to the fitting-room source module; C++ is intentionally blank until field names, base-adjusted receiver layout, and source placement versus generic scrollbar code are final.
- Evidence basis: Wave3 inspection, generated source, and IDA MCP checks on 2026-05-23 with constructor-boundary recheck on 2026-05-25 and scroll-pane core split on 2026-05-30.

## Role

Scrollbar pane used by fitting-room list controls. It draws EPF-backed scroll parts, tracks hot/pressed parts, handles mouse drag and auto-repeat timers, and notifies the parent list pane when scroll position changes.

## Confirmed Methods

| Address | Method | Notes |
| --- | --- | --- |
| [UID:0002D2][0x0041d870-0x0041da51.FittingRoomScrollPaneOnMouseEvent](by-memory/0x0041d870-0x0041da51.FittingRoomScrollPaneOnMouseEvent.md) | `OnMouseEvent` | Vtable-only mouse handler; handles hit testing, thumb drag setup, active part state, timer/capture behavior, and mouse-up cleanup. |
| [UID:0002D3][0x0041da60-0x0041da65.FittingRoomScrollPaneDefaultFalseVirtual](by-memory/0x0041da60-0x0041da65.FittingRoomScrollPaneDefaultFalseVirtual.md) | `DefaultVirtualFalse` | Vtable-referenced `return false` predicate/hook stub; final virtual slot name still open. |
| [UID:0002D4][0x0041da70-0x0041daa3.FittingRoomScrollPaneOnTimer](by-memory/0x0041da70-0x0041daa3.FittingRoomScrollPaneOnTimer.md) | `OnTimer` | Auto-repeat scroll timer for held scrollbar parts. |
| [UID:0002D6][0x0041dab0-0x0041e1c6.FittingRoomScrollPaneOnDraw](by-memory/0x0041dab0-0x0041e1c6.FittingRoomScrollPaneOnDraw.md) | `OnDraw` | Draws horizontal/vertical scrollbar background, buttons, track, and thumb with fitting-room resource tables. |
| [UID:0002D8][0x0041e1d0-0x0041e4ed.FittingRoomScrollPaneHitTestPart](by-memory/0x0041e1d0-0x0041e4ed.FittingRoomScrollPaneHitTestPart.md) | `HitTestPart` | Returns leading button, page before thumb, thumb, page after thumb, trailing button, or `0xff`. |
| [UID:0002D7][0x0041e4f0-0x0041e777.FittingRoomScrollPaneGetPartRect](by-memory/0x0041e4f0-0x0041e777.FittingRoomScrollPaneGetPartRect.md) | `GetPartRect` | Calculates button/page/thumb rectangles from orientation, range, current value, and skin size. |
| [UID:0002DA][0x0041e780-0x0041e8af.FittingRoomScrollPaneRawPartStateHelpers](by-memory/0x0041e780-0x0041e8af.FittingRoomScrollPaneRawPartStateHelpers.md) | `SetHotPart` / `BeginPartPress` | Raw helper pair; generated starts are not IDA functions yet, but byte review confirms normal helper bodies. |
| [UID:0002D5][0x0041e8b0-0x0041e970.FittingRoomScrollPaneProcessActivePart](by-memory/0x0041e8b0-0x0041e970.FittingRoomScrollPaneProcessActivePart.md) | `ProcessActivePart` | Applies active scroll-part behavior or forwards thumb dragging. |
| [UID:0002D9][0x0041e970-0x0041eb24.FittingRoomScrollPaneUpdateThumbDragScroll](by-memory/0x0041e970-0x0041eb24.FittingRoomScrollPaneUpdateThumbDragScroll.md) | `UpdateThumbDragScroll` | Converts thumb drag position into scroll value and notifies the owning list pane. |
| [UID:0002DB][0x0041eb30-0x0041eb8c.FittingRoomScrollPaneResetScrollStateRaw](by-memory/0x0041eb30-0x0041eb8c.FittingRoomScrollPaneResetScrollStateRaw.md) | `ResetScrollState` | Raw helper that stops the repeat timer and clears active/hot scrollbar part state. |
| [UID:0002DY][0x00421480-0x004214bb.ScrollPaneFamilyScalarDeletingDestructor](by-memory/0x00421480-0x004214bb.ScrollPaneFamilyScalarDeletingDestructor.md) | scalar deleting destructor wrapper | Shared generated wrapper used by several scroll-pane-family vtables; base teardown plus optional delete. |
| `0x0045aa00-0x0045ab48` | `BeginScrollDrag` | Drag setup helper. |
| `0x0045ab50-0x0045ac0f` | `UpdateScrollOnMove` | Scroll update during drag. |
| `0x00497aa0-0x0049802f` | parent scroll helpers | Additional scroll handling currently attached by Wave3. |

## Boundary Cautions

- Wave3 lists a constructor at `0x0041d6c0`, but IDA MCP reports `0x0041d6c0` is not a function start. Generated source for that constructor is still useful as layout evidence, but source migration should not treat the address as a confirmed IDA function.
- 2026-05-25 IDA MCP recheck: `xrefs_to 0x0041d6c0` reports no references. Disassembly at that address is constructor-shaped raw code that calls `0x00544460`, installs `FittingRoomScrollPane` vtables, and initializes scroll state bytes/words, but the confirmed `FittingRoomListPane` constructor at `0x0041eb90` performs equivalent child setup inline after allocating `272` bytes.
- The generated `OnMouseEvent` source currently casts through `TextEditPane` and `FittingRoomDialog` helpers. That may be inherited scrollbar infrastructure rather than true fitting-room-only ownership.
- 2026-05-30 IDA MCP function inventory reports modeled scroll-pane method starts at `0x0041d870`, `0x0041da60`, `0x0041da70`, `0x0041dab0`, `0x0041e1d0`, `0x0041e4f0`, `0x0041e8b0`, and `0x0041e970`. IDA still lacks function records at `0x0041e780`, `0x0041e7f0`, and `0x0041eb30`, but byte review confirms raw helper bodies that need function-boundary repair.
- `OnMouseEvent` is reached through a vtable data xref at `0x0060dcd8`, not direct code callers. IDA decompilation uses an adjusted receiver and accesses the logical scroll-pane base at `this - 0xa0`.
- [UID:0002DY][0x00421480-0x004214bb.ScrollPaneFamilyScalarDeletingDestructor](by-memory/0x00421480-0x004214bb.ScrollPaneFamilyScalarDeletingDestructor.md) is generated binary support shared by scroll-pane-family vtables. Document it for vtable completeness, but do not hand-author a distinct source method unless a later class-layout pass proves the original source exposed one.

## Score Rationale

| Score | Rationale |
| --- | --- |
| Completion `72` | The local mouse, timer, draw, hit-test, geometry, active-part, drag-update, reset, and deleting-destructor evidence is split into exact pages. Completion remains capped by the raw constructor boundary, unresolved field names, and possible later migration of generic scrollbar behavior out of `FittingRoom`. |
| Confidence `84` | Modeled function starts, vtable data xrefs, sibling cross-calls, and fitting-room resource tables consistently identify this scroll-pane class. Confidence is not higher because the constructor is raw/non-modeled and decompiler output uses a secondary-base receiver adjustment. |

## Cross-References

- [UID:0000JE][FittingRoom](by-file/FittingRoom.md)
- [UID:000053][FittingRoomListPane](by-class/FittingRoomListPane.md)
- [UID:0000WR][0x0041ba40-0x004245f5.FittingRoomUiCore](by-memory/0x0041ba40-0x004245f5.FittingRoomUiCore.md)
- [UID:0000NF][ScrollBar](by-file/ScrollBar.md)
- [UID:0002D2][0x0041d870-0x0041da51.FittingRoomScrollPaneOnMouseEvent](by-memory/0x0041d870-0x0041da51.FittingRoomScrollPaneOnMouseEvent.md)
- [UID:0002D3][0x0041da60-0x0041da65.FittingRoomScrollPaneDefaultFalseVirtual](by-memory/0x0041da60-0x0041da65.FittingRoomScrollPaneDefaultFalseVirtual.md)
- [UID:0002D4][0x0041da70-0x0041daa3.FittingRoomScrollPaneOnTimer](by-memory/0x0041da70-0x0041daa3.FittingRoomScrollPaneOnTimer.md)
- [UID:0002D6][0x0041dab0-0x0041e1c6.FittingRoomScrollPaneOnDraw](by-memory/0x0041dab0-0x0041e1c6.FittingRoomScrollPaneOnDraw.md)
- [UID:0002D8][0x0041e1d0-0x0041e4ed.FittingRoomScrollPaneHitTestPart](by-memory/0x0041e1d0-0x0041e4ed.FittingRoomScrollPaneHitTestPart.md)
- [UID:0002D7][0x0041e4f0-0x0041e777.FittingRoomScrollPaneGetPartRect](by-memory/0x0041e4f0-0x0041e777.FittingRoomScrollPaneGetPartRect.md)
- [UID:0002DA][0x0041e780-0x0041e8af.FittingRoomScrollPaneRawPartStateHelpers](by-memory/0x0041e780-0x0041e8af.FittingRoomScrollPaneRawPartStateHelpers.md)
- [UID:0002D5][0x0041e8b0-0x0041e970.FittingRoomScrollPaneProcessActivePart](by-memory/0x0041e8b0-0x0041e970.FittingRoomScrollPaneProcessActivePart.md)
- [UID:0002D9][0x0041e970-0x0041eb24.FittingRoomScrollPaneUpdateThumbDragScroll](by-memory/0x0041e970-0x0041eb24.FittingRoomScrollPaneUpdateThumbDragScroll.md)
- [UID:0002DB][0x0041eb30-0x0041eb8c.FittingRoomScrollPaneResetScrollStateRaw](by-memory/0x0041eb30-0x0041eb8c.FittingRoomScrollPaneResetScrollStateRaw.md)
- [UID:0002DY][0x00421480-0x004214bb.ScrollPaneFamilyScalarDeletingDestructor](by-memory/0x00421480-0x004214bb.ScrollPaneFamilyScalarDeletingDestructor.md)

## Changes

- 2026-06-02: Raised the class page to 72/84, marked it reconstructable, and attached it to [UID:0000JE][FittingRoom](by-file/FittingRoom.md). Added score rationale and kept C++ blank because the class layout and possible generic scrollbar source split are not final.
- 2026-05-30: Existing `OnMouseEvent` row used an address-only range ending at `0x0041da50`. Changed it to an exact by-memory UID link ending at `0x0041da51` and recorded the vtable-only caller model. Evidence: IDA MCP `py_eval`, `decompile`, `callees`, `callers`, and `xrefs_to` for `0x0041d870`.
- 2026-05-30: Existing method rows for timer, draw, geometry, hot-part state, and reset state were address-only and left most of the local core unresolved. Changed them to exact by-memory UID links for all modeled `0x0041d870-0x0041eb24` functions and raw helper pages for `0x0041e780-0x0041e8af` and `0x0041eb30-0x0041eb8c`. Evidence: IDA MCP function inventory, decompilation/xrefs/callees, and byte/disassembly review across the helper gaps.
- 2026-05-30: Added the shared scroll-pane-family scalar deleting destructor wrapper from the mixed `0x00421310-0x004216cb` island for vtable completeness. Evidence: IDA MCP data refs from scroll-pane-family vtables and decompilation of `0x00421480`.
