*** UID:0000FX | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# VoteMenuPane

## Status

- Confidence: strong for confirmed methods and helper ownership; medium cap remains for final source/code because IDA does not model `0x005558d0` as a function and exact original helper names are not final.
- Likely source file: [UID:0000P6][VoteMenuPane](by-file/VoteMenuPane.md)
- Current recovered file: `source-3/simroot_v2/class_VoteMenuPane.cpp`
- Singleton: [UID:0000SP][g_pVoteMenuPane](by-global/g_pVoteMenuPane.md) at [UID:0001Q0][0x0069ba38-0x0069ba3c.g_pVoteMenuPane](by-memory/0x0069ba38-0x0069ba3c.g_pVoteMenuPane.md)
- Vtables: [UID:0001Z1][VoteMenuPaneVtables](by-type/by-vtable/VoteMenuPaneVtables.md)

## Class Purpose

`VoteMenuPane` is a two-option SUBWIN popup for target-player voting. It tracks Promote/Demote hover and selection state, draws the popup, and sends the selected vote request for the stored target player name.

## Method Notes

| Method/helper | Address | Role |
| --- | --- | --- |
| `VoteMenuPane` | [UID:0002LQ][0x005558d0-0x00555945.VoteMenuPaneRawConstructor](by-memory/0x005558d0-0x00555945.VoteMenuPaneRawConstructor.md) | Raw constructor-shaped code; creates the `Pane` base, sets `g_pVoteMenuPane`, stores `voteType`, initializes selection state, installs vtables, and copies the target name. |
| `~VoteMenuPane` | [UID:0002LR][0x00555950-0x005559bc.VoteMenuPaneDestructor](by-memory/0x00555950-0x005559bc.VoteMenuPaneDestructor.md) | Clears the singleton and removes/destroys pane state. |
| `OnMouseEvent` | [UID:0002LS][0x005559c0-0x00555ad5.VoteMenuPaneOnMouseEvent](by-memory/0x005559c0-0x00555ad5.VoteMenuPaneOnMouseEvent.md) | Handles hover/down/up events, hit-tests Promote/Demote, calls `SubmitVote`, and closes the right-click menu. |
| `OnDismiss` | [UID:0002LT][0x00555ae0-0x00555aef.VoteMenuPaneOnDismiss](by-memory/0x00555ae0-0x00555aef.VoteMenuPaneOnDismiss.md) | Dismisses the associated owner/session pane. |
| `OnPaint` | [UID:0002LU][0x00555af0-0x00555c68.VoteMenuPaneOnPaint](by-memory/0x00555af0-0x00555c68.VoteMenuPaneOnPaint.md) | Draws Promote/Demote labels and selected-row highlight. |
| `DrawBackground` | [UID:0002LV][0x00555c70-0x00555ce1.VoteMenuPaneDrawBackground](by-memory/0x00555c70-0x00555ce1.VoteMenuPaneDrawBackground.md) | Fills the SUBWIN background. |
| `DrawBorder` | [UID:0002LW][0x00555cf0-0x00556012.VoteMenuPaneDrawBorder](by-memory/0x00555cf0-0x00556012.VoteMenuPaneDrawBorder.md) | Draws the tiled SUBWIN border. |
| `GetItemRect` | [UID:0002LX][0x00556020-0x0055606d.VoteMenuPaneGetItemRect](by-memory/0x00556020-0x0055606d.VoteMenuPaneGetItemRect.md) | Computes the two vote-row rectangles. |
| `VoteMenuPaneHitTest` | [UID:0002LY][0x00556070-0x005560fb.VoteMenuPaneHitTest](by-memory/0x00556070-0x005560fb.VoteMenuPaneHitTest.md) | Two-row hit-test helper currently generated under `BulletinSession`. |
| `SubmitVote` | [UID:0002LZ][0x00556100-0x00556211.VoteMenuPaneSubmitVote](by-memory/0x00556100-0x00556211.VoteMenuPaneSubmitVote.md) | Sends opcode `0x46`, submode `0`, target name length/name bytes, and promote/demote flag. |
| destructor adjustor thunks | `0x00556228`, `0x00556233` | Compiler-generated secondary-base deleting-destructor thunks; vtable layout evidence only. |
| `ScalarDeletingDestructor` | `0x00556320-0x005563cd` | Deleting destructor body. |

## Layout Notes

- The class inherits from `Pane` and installs primary and secondary vtables at the same offsets as neighboring menu panes.
- State fields identified from constructor/decompile evidence: selection flag at `+0xf8`, selected row at `+0xf9`, vote type at `+0xfc`, and target name at `+0x100`.
- See [UID:0001WH][VoteMenuPaneLayout](by-type/by-struct/VoteMenuPaneLayout.md).

## Evidence Notes

- Active generated output omits `0x00556070` and `0x00556100` from the `VoteMenuPane` file even though IDA caller evidence ties both only to `VoteMenuPane::OnMouseEvent`.
- Active generated output keeps `0x00556228` and `0x00556233` in the disabled companion; IDA confirms both as 0xb-byte functions.
- 2026-05-26 current generated output still has the same helper split. IDA still reports `0x005558d0` as not-a-function, and still confirms `0x00556070`, `0x00556100`, `0x00556228`, `0x00556233`, and `0x00556320` with the expected sizes.
- 2026-05-26 IDA MCP vtable pass confirms `VoteMenuPane` vtables at `0x00622ff8`, `0x0062304c`, and `0x0062307c`, installed by raw constructor stores at `0x00555913`, `0x00555919`, and `0x00555923`. Current Wave3 metadata still reports `vtable_count: 0`.
- `OnMouseEvent` is secondary-table slot `+0x04`; the two-row hit-test helper at `0x00556070` and vote-submit helper at `0x00556100` are direct callees, not vtable slots.
- Wave3 metadata notes stored method-name control characters for constructor/destructor/deleting destructor.
- 2026-05-31 IDA MCP recheck confirms the exact child function boundaries, `0x00556070`/`0x00556100` xrefs from `OnMouseEvent`, `0x00556020` xref from `OnPaint`, vtable xrefs from constructor/destructors, and `g_pVoteMenuPane` constructor/destructor writes.

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
