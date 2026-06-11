*** UID:0000C0 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:85 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000N7 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# RightButtonMenuPane

## Status

- Confidence: strong for class role and boundaries.
- Likely source file: [UID:0000N7][RightButtonMenuPane](by-file/RightButtonMenuPane.md)
- Main address ranges: [UID:0001FX][0x00554b40-0x0055577b.RightButtonMenuPaneCore](by-memory/0x00554b40-0x0055577b.RightButtonMenuPaneCore.md), [UID:00023Q][0x00555780-0x005558c2.RightButtonMenuPacketHelpers](by-memory/0x00555780-0x005558c2.RightButtonMenuPacketHelpers.md), [UID:0001G0][0x00556212-0x00556228.RightButtonMenuPaneDestructorThunks](by-memory/0x00556212-0x00556228.RightButtonMenuPaneDestructorThunks.md), and [UID:0001G2][0x00556240-0x00556314.RightButtonMenuPaneScalarDeletingDestructor](by-memory/0x00556240-0x00556314.RightButtonMenuPaneScalarDeletingDestructor.md)
- Current recovered file: `source-3/simroot_v2/class_RightButtonMenuPane.cpp`

## Class Purpose

`RightButtonMenuPane` is the right-click target context menu. It draws a SUBWIN-styled menu for a selected target and handles Look, Trade, Whisper, Group, and Info actions.

## Method Map

| Address | Method | Role |
| --- | --- | --- |
| `0x00554b40-0x00554b96` | `RightButtonMenuPane::RightButtonMenuPane()` | Constructs pane state, installs vtables, and sets `g_pRightButtonMenuPane`. |
| `0x00554ba0-0x00554c33` | `~RightButtonMenuPane()` | Clears highlighted object state, removes/unregisters pane, and clears global pointer. |
| `0x00554c40-0x00554f59` | `OnEvent(EventMsg*)` | Handles hover, click, outside cancel, and action dispatch. |
| `0x00554f90-0x00554fb3` | `OnCancel()` | Dismisses associated menu sessions. |
| `0x00554fc0-0x00555298` | `OnPaint()` | Draws labels and selected row highlight. |
| `0x005552f0-0x00555692` | Background/border drawing | Draws SUBWIN background fill and border tiles. |
| `0x005556a0-0x005556ed` | `GetMenuItemRect(int, RECT*)` | Computes menu row rectangle. |
| `0x005556f0-0x0055577b` | `HitTestMenuItem(int, int)` | Five-row hit-test helper currently emitted under `BulletinSession`; IDA callers are only this class. |
| `0x00555780-0x005558c2` | packet helper island | Raw packet builders adjacent to the right-click menu core; no direct caller xrefs yet, but IDA confirms packet construction through `dword_67A7EC`. |
| `0x00556212-0x00556228` | Adjustor/thunk helpers | Compiler-generated vtable-referenced deleting-destructor thunks. |
| `0x00556240-0x00556314` | `ScalarDeletingDestructor(char flags)` | Destructor wrapper. |

## Evidence Notes

- Wave3 grades the class at effective `97.6`.
- IDA MCP confirms all listed starts as exact functions.
- Current emitted source omits the tiny thunk bodies at `0x00556212` and `0x0055621d`.
- The neighboring [UID:0000FX][VoteMenuPane](by-class/VoteMenuPane.md) starts at raw constructor boundary `0x005558d0`, so the former broad right-click memory page has been split into exact non-overlapping ranges.
- Active generated `RightButtonMenuPane` code uses `g_pBulletinSession` for some `0x0069ba38` references. Treat those as [UID:0000SP][g_pVoteMenuPane](by-global/g_pVoteMenuPane.md) [UID:0001Q0][0x0069ba38-0x0069ba3c.g_pVoteMenuPane](by-memory/0x0069ba38-0x0069ba3c.g_pVoteMenuPane.md) until the generated global owner is fixed.
- 2026-05-26 recheck: IDA callers still report the only direct `0x005556f0` calls at `0x00554c95` and `0x00554d27` inside `RightButtonMenuPane::OnEvent`; no `BulletinSession` caller evidence was found.
- 2026-06-01 recheck: raw starts `0x00555780` and `0x005557e0` have no direct caller or pointer xrefs, but their packet-building behavior and placement keep them provisionally attached to this class/file.
- 2026-06-07 A010 parent-gate refresh: live IDA xrefs to [UID:00029Z][0x0069b4f0-0x0069b4f4.RightButtonMenuPaneSingleton](by-memory/0x0069b4f0-0x0069b4f4.RightButtonMenuPaneSingleton.md) reconfirm constructor publish, destructor clear, scalar-deleting destructor clear, six menu/open-state consumers in `0x00507150`, and exact neighboring singleton boundaries.

## Cross-References

- [UID:0000N7][RightButtonMenuPane](by-file/RightButtonMenuPane.md)
- [UID:0001FX][0x00554b40-0x0055577b.RightButtonMenuPaneCore](by-memory/0x00554b40-0x0055577b.RightButtonMenuPaneCore.md)
- [UID:00023Q][0x00555780-0x005558c2.RightButtonMenuPacketHelpers](by-memory/0x00555780-0x005558c2.RightButtonMenuPacketHelpers.md)
- [UID:0000FX][VoteMenuPane](by-class/VoteMenuPane.md)
- [UID:0000SP][g_pVoteMenuPane](by-global/g_pVoteMenuPane.md)
- [UID:0001Q0][0x0069ba38-0x0069ba3c.g_pVoteMenuPane](by-memory/0x0069ba38-0x0069ba3c.g_pVoteMenuPane.md)
- [UID:0000MN][PopupMenuControls](by-file/PopupMenuControls.md)
- [UID:0000L8][MenuVarietyPanes](by-file/MenuVarietyPanes.md)

## Changes

- 2026-05-30: Changed completion/confidence from `0/0` to `84/86`.
  - Before: The page was unevaluated despite documenting menu behavior, exact method boundaries, destructor thunks, split ranges, and generated global-owner caveats.
  - After: Scored as high completion and strong confidence for the right-click target menu.
  - Evidence: Existing method map, Wave3 grade note, IDA exact-start evidence, caller evidence for hit testing, and global/source ownership caveats support the score.
- 2026-06-01: Added the adjacent packet helper island to the class map as provisional ownership.
  - Evidence: IDA MCP confirms packet-builder bodies at `0x00555780` and `0x005557e0`, an internal `0xcc` alignment gap, and no direct caller/pointer xrefs; ownership remains by adjacency and behavior rather than direct calls.
- 2026-06-05: Marked reconstructable and attached to [UID:0000N7][RightButtonMenuPane](by-file/RightButtonMenuPane.md) because the class is `84/86` and the parent is `84/86`, satisfying the 80/80 parent gate. Live IDA MCP `lookup_funcs` confirms exact starts for the core/destructor methods at `0x00554b40`, `0x00554ba0`, `0x00554c40`, `0x00554f90`, `0x00554fc0`, `0x005552f0`, `0x005556a0`, `0x005556f0`, `0x00556212`, `0x0055621d`, and `0x00556240`; current `callers` confirms the constructor reference at `0x00507685`.
- 2026-06-07 A010 Batch044 parent-gate update: Raised `84/86` to `85/88` after adding refreshed singleton storage xrefs and boundary evidence. This supports [UID:00029Z][0x0069b4f0-0x0069b4f4.RightButtonMenuPaneSingleton](by-memory/0x0069b4f0-0x0069b4f4.RightButtonMenuPaneSingleton.md) assignment to this class under the corrected 85/85 gate; final C++ remains blank.
