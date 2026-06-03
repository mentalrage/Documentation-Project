*** UID:00001Z | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# ChattingVarietySelectPane

## Status

- Confidence: strong for confirmed vtable methods and selector behavior; medium for raw constructor/state helpers that IDA does not model as functions or expose through xrefs.
- Likely source file: [UID:0000I5][Chatting](by-file/Chatting.md)
- Address range: [UID:000104][0x0047efb0-0x00483ef7.ChattingUI](by-memory/0x0047efb0-0x00483ef7.ChattingUI.md)
- Current recovered file: `source-3/simroot_v2/class_ChattingVarietySelectPane.cpp`

## Class Purpose

`ChattingVarietySelectPane` is the popup chat-mode selector. It lets the player choose Talk, Shout, Whisper, Group, Clan, or Color, then opens the matching input/color flow.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| compact button rectangle helper | [UID:0002FF][0x00481010-0x00481056.ChattingVarietySelectPaneRowRectHelper](by-memory/0x00481010-0x00481056.ChattingVarietySelectPaneRowRectHelper.md) | Raw IDA-unmodeled helper now kept with [UID:00001Y][ChattingVarietyPane](by-class/ChattingVarietyPane.md); included here only because it sits immediately before the raw selector constructor and supports opening this popup. |
| compact button hit-test helper | [UID:0002FG][0x00481060-0x004810ea.ChattingVarietySelectPaneInitialHitTest](by-memory/0x00481060-0x004810ea.ChattingVarietySelectPaneInitialHitTest.md) | Raw IDA-unmodeled helper now kept with [UID:00001Y][ChattingVarietyPane](by-class/ChattingVarietyPane.md); it tests the compact button rectangle, not the six-row popup list. |
| `ChattingVarietySelectPane` | [UID:0002FH][0x004810f0-0x00481146.ChattingVarietySelectPaneConstructorRaw](by-memory/0x004810f0-0x00481146.ChattingVarietySelectPaneConstructorRaw.md) | Raw constructor body; IDA does not model it as a function start, but byte decode proves real constructor code. |
| destructor body | [UID:0002FI][0x00481150-0x004811bc.ChattingVarietySelectPaneDestructor](by-memory/0x00481150-0x004811bc.ChattingVarietySelectPaneDestructor.md) | Clears `g_pChattingVarietySelectPane` after vtable/subobject cleanup and base teardown. |
| `OnMouseEvent` | [UID:0002FJ][0x004811c0-0x00481461.ChattingVarietySelectPaneOnMouseEvent](by-memory/0x004811c0-0x00481461.ChattingVarietySelectPaneOnMouseEvent.md) | Hover/click/release dispatcher for the six selector rows; commits Talk/Shout/Whisper/Group/Clan/Color actions. |
| `OnDismiss` | [UID:0002FK][0x00481470-0x0048148f.ChattingVarietySelectPaneOnDismiss](by-memory/0x00481470-0x0048148f.ChattingVarietySelectPaneOnDismiss.md) | Refreshes the compact chat-mode button and dismisses the popup. |
| `OnPaint` | [UID:0002FL][0x00481490-0x004816ce.ChattingVarietySelectPaneOnPaint](by-memory/0x00481490-0x004816ce.ChattingVarietySelectPaneOnPaint.md) | Paints selector labels and the hover/pressed highlight frame. |
| `SetupBackground` | [UID:0002FN][0x004816d0-0x00481741.ChattingVarietySelectPaneSetupBackground](by-memory/0x004816d0-0x00481741.ChattingVarietySelectPaneSetupBackground.md) | Tiles/fills the selector interior from `SUBWIN.EPF`. |
| `DrawBorder` | [UID:0002FO][0x00481750-0x00481a72.ChattingVarietySelectPaneDrawBorder](by-memory/0x00481750-0x00481a72.ChattingVarietySelectPaneDrawBorder.md) | Draws the `SUBWIN.EPF` border edges and corners. |
| `GetVarietyItemRect` | [UID:0002FM][0x00481a80-0x00481acd.ChattingVarietySelectPaneGetItemRect](by-memory/0x00481a80-0x00481acd.ChattingVarietySelectPaneGetItemRect.md) | Returns per-row selector rectangles. |
| [UID:000106][0x00481ad0-0x00481b5b.ChattingVarietySelectPaneHitTest](by-memory/0x00481ad0-0x00481b5b.ChattingVarietySelectPaneHitTest.md) | `0x00481ad0-0x00481b5b` | Six-row selector hit-test helper used by `OnMouseEvent`; previously left in the BulletinSession owner-review bucket. |
| state compare helper | [UID:0002FP][0x00481b60-0x00481bb9.ChattingVarietySelectPaneStateCompareHelper](by-memory/0x00481b60-0x00481bb9.ChattingVarietySelectPaneStateCompareHelper.md) | Raw IDA-unmodeled/unxrefed helper that compares a record against fields at `this + 0x111..0x124`. |
| state snapshot helper | [UID:0002FQ][0x00481bc0-0x00481c05.ChattingVarietySelectPaneStateSnapshotHelper](by-memory/0x00481bc0-0x00481c05.ChattingVarietySelectPaneStateSnapshotHelper.md) | Raw IDA-unmodeled/unxrefed helper that writes the same field group to a record. |
| `ScalarDeletingDestructor` | `0x00483db0` | Clears popup state during deletion. |

## Evidence Notes

- IDA MCP reports no modeled function at `0x004810f0`, but 2026-05-31 raw decode confirms a complete constructor body at `0x004810f0-0x00481146`.
- IDA MCP raw decode also confirms unmodeled helper bodies at `0x00481010-0x00481056` and `0x00481060-0x004810ea`; current IDA xrefs do not identify callers for those helpers. Their `(0,0,62,24)` geometry matches the compact `ChattingVarietyPane` button, not the six-row popup selector list.
- IDA MCP confirms exact function boundaries and vtable entries for `0x00481150`, `0x004811c0`, `0x00481470`, `0x00481490`, `0x004816d0`, `0x00481750`, and `0x00481a80`.
- IDA MCP on 2026-05-26 confirms `0x00481ad0` is a six-row hit-test helper with callers only at `0x0048124d` and `0x00481430` inside `ChattingVarietySelectPane::OnMouseEvent`.
- IDA MCP on 2026-05-31 confirms raw unmodeled helper bodies at `0x00481b60-0x00481bb9` and `0x00481bc0-0x00481c05`; both are unxrefed in IDA but operate on the same `this + 0x111..0x124` field group.
- IDA decompilation of `OnMouseEvent` ties selector rows to talk/shout/whisper/group/clan/color commands. The row-2 helper is currently misnamed as a standard-library symbol by IDA and should be treated as unresolved project behavior.

## Cross-References

- [UID:0000I5][Chatting](by-file/Chatting.md)
- [UID:000104][0x0047efb0-0x00483ef7.ChattingUI](by-memory/0x0047efb0-0x00483ef7.ChattingUI.md)
- [UID:0002FF][0x00481010-0x00481056.ChattingVarietySelectPaneRowRectHelper](by-memory/0x00481010-0x00481056.ChattingVarietySelectPaneRowRectHelper.md)
- [UID:0002FG][0x00481060-0x004810ea.ChattingVarietySelectPaneInitialHitTest](by-memory/0x00481060-0x004810ea.ChattingVarietySelectPaneInitialHitTest.md)
- [UID:0002FH][0x004810f0-0x00481146.ChattingVarietySelectPaneConstructorRaw](by-memory/0x004810f0-0x00481146.ChattingVarietySelectPaneConstructorRaw.md)
- [UID:0002FI][0x00481150-0x004811bc.ChattingVarietySelectPaneDestructor](by-memory/0x00481150-0x004811bc.ChattingVarietySelectPaneDestructor.md)
- [UID:0002FJ][0x004811c0-0x00481461.ChattingVarietySelectPaneOnMouseEvent](by-memory/0x004811c0-0x00481461.ChattingVarietySelectPaneOnMouseEvent.md)
- [UID:0002FK][0x00481470-0x0048148f.ChattingVarietySelectPaneOnDismiss](by-memory/0x00481470-0x0048148f.ChattingVarietySelectPaneOnDismiss.md)
- [UID:0002FL][0x00481490-0x004816ce.ChattingVarietySelectPaneOnPaint](by-memory/0x00481490-0x004816ce.ChattingVarietySelectPaneOnPaint.md)
- [UID:0002FN][0x004816d0-0x00481741.ChattingVarietySelectPaneSetupBackground](by-memory/0x004816d0-0x00481741.ChattingVarietySelectPaneSetupBackground.md)
- [UID:0002FO][0x00481750-0x00481a72.ChattingVarietySelectPaneDrawBorder](by-memory/0x00481750-0x00481a72.ChattingVarietySelectPaneDrawBorder.md)
- [UID:0002FM][0x00481a80-0x00481acd.ChattingVarietySelectPaneGetItemRect](by-memory/0x00481a80-0x00481acd.ChattingVarietySelectPaneGetItemRect.md)
- [UID:000106][0x00481ad0-0x00481b5b.ChattingVarietySelectPaneHitTest](by-memory/0x00481ad0-0x00481b5b.ChattingVarietySelectPaneHitTest.md)
- [UID:0002FP][0x00481b60-0x00481bb9.ChattingVarietySelectPaneStateCompareHelper](by-memory/0x00481b60-0x00481bb9.ChattingVarietySelectPaneStateCompareHelper.md)
- [UID:0002FQ][0x00481bc0-0x00481c05.ChattingVarietySelectPaneStateSnapshotHelper](by-memory/0x00481bc0-0x00481c05.ChattingVarietySelectPaneStateSnapshotHelper.md)
- [UID:00001Y][ChattingVarietyPane](by-class/ChattingVarietyPane.md)
- [UID:00001T][ChattingColorPane](by-class/ChattingColorPane.md)

## Changes

- What existed before: the page documented confirmed popup methods, hit-test ownership, and constructor caveat, but metadata was still `0/0`.
- What it was changed to: scores were set to `72/80`.
- Summary and evidence: selector rows, mouse/dismiss/paint/background/border helpers, and hit-test helper are covered; projected constructor reachability and final field layout remain incomplete.
- 2026-05-31: Updated completion/confidence from `72/80` to `76/84` after documenting the raw unmodeled constructor/helper bodies and exact destructor body before the existing mouse-dispatch range. Evidence: IDA MCP raw decode, function boundary checks, decompilation, xref checks, and padding audit.
- 2026-05-31: Updated completion/confidence from `76/84` to `84/88` after adding exact pages for mouse dispatch, dismiss, paint, background setup, border drawing, row rectangle, hit-test, and raw state compare/snapshot helpers through `0x00481c10`. Evidence: IDA MCP function iteration, vtable xrefs, decompilation, raw disassembly, and padding audit.
- 2026-06-03: Clarified that the raw `0x00481010`/`0x00481060` compact-button helpers are cross-referenced setup support but attach to [UID:00001Y][ChattingVarietyPane](by-class/ChattingVarietyPane.md), while this popup's own six-row geometry remains [UID:0002FM][0x00481a80-0x00481acd.ChattingVarietySelectPaneGetItemRect](by-memory/0x00481a80-0x00481acd.ChattingVarietySelectPaneGetItemRect.md) and [UID:000106][0x00481ad0-0x00481b5b.ChattingVarietySelectPaneHitTest](by-memory/0x00481ad0-0x00481b5b.ChattingVarietySelectPaneHitTest.md).
