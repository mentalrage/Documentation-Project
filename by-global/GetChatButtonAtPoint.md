*** UID:0000SX | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000I5 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000I5 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
// Emitted code for GetChatButtonAtPoint is covered by [UID:000107][0x00482400-0x004824e0.GetChatButtonAtPoint](by-memory/0x00482400-0x004824e0.GetChatButtonAtPoint.md).
[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# GetChatButtonAtPoint

## Status

- Confidence: strong for behavior, switch-table tail, source-facing signature, and chat ownership; current IDA session `43ccf853` names the function `sub_482400`, so `GetChatButtonAtPoint` is retained as an inferred source-facing helper name rather than current IDA-label proof.
- Address range: [UID:000107][0x00482400-0x004824e0.GetChatButtonAtPoint](by-memory/0x00482400-0x004824e0.GetChatButtonAtPoint.md)
- Symbol kind: recovered free helper, likely original file-local/static helper.
- Likely owner file: [UID:0000I5][Chatting](by-file/Chatting.md)

## Role

`GetChatButtonAtPoint` maps a mouse coordinate to one of the fixed [UID:00001V][ChattingHandlePane](by-class/ChattingHandlePane.md) hit regions. It is used only by the mouse-down and mouse-up paths in `ChattingHandlePane::OnMouseEvent`, at call sites `0x00481dca` and `0x00481ec9`. The source-facing helper signature is `static signed char GetChatButtonAtPoint(int mouseY, int mouseX)`, matching the project `PointInRect(int y, int x, const RectBounds *bounds)` convention and the live caller push order.

The memory page now covers `0x00482400-0x004824e0` because IDA raw head review shows the switch jump table at `0x004824cc-0x004824e0` belongs to this helper. The rectangle set matches [UID:0002FW][0x00482310-0x00482400.GetChatButtonRectRaw](by-memory/0x00482310-0x00482400.GetChatButtonRectRaw.md), but B003 2026-06-28 confirmed that the reachable hover/move path in [UID:0002FT][0x00481d60-0x0048214f.ChattingHandlePaneOnMouseEvent](by-memory/0x00481d60-0x0048214f.ChattingHandlePaneOnMouseEvent.md) does not call either helper. Hover tests the inherited pane bounds and the three visible button rectangles inline; only down/up call `GetChatButtonAtPoint`.

Historical 2026-06-16 C001 live IDA refresh saved the function label `GetChatButtonAtPoint` at `0x00482400`. Current 2026-07-07 B006 MCP session `43ccf853` instead reports `lookup_funcs GetChatButtonAtPoint` as `Not found` and `0x00482400 -> sub_482400`, size `0xc9`; keep the source-facing name but document the current IDA-label caveat. The same current evidence reports only the two `ChattingHandlePane::OnMouseEvent` calls at `0x00481dca` and `0x00481ec9`, the helper-owned switch-table reference from `0x00482421`, and a unique signature for `0x00482400-0x004824e0`.

## Call-Site Caveat

IDA disassembly shows the caller pushes the event coordinate fields directly, so keep this helper modeled with a coordinate-style signature rather than as a `this` plus event-object wrapper. B006 2026-07-07 rechecked the pushes as `[event + 0x0c]` then `[event + 0x08]`; because the callee forwards its first coordinate to `PointInRect`'s y/top-bottom argument, source calls should be `GetChatButtonAtPoint(event->mouseY, event->mouseX)`.

Do not use this helper as evidence for chat-handle drag/resize behavior. Return `1` is the middle body/input strip used by the mouse-down path to call the current say-mode input dispatcher when the user pane has no pending target object; resize/drag ownership belongs to `ChattingModifyHeightPane`.

## Source Placement

Treat this as a private/static helper in `NexusTK/social/Chatting.cpp`, beside `ChattingHandlePane`. Do not infer an original standalone `GetChatButtonAtPoint.cpp` source file from the helper name alone. This global/name page intentionally emits only the coverage marker plus the `[[CHILDREN]]` insertion point above; the full helper body is emitted by [UID:000107][0x00482400-0x004824e0.GetChatButtonAtPoint](by-memory/0x00482400-0x004824e0.GetChatButtonAtPoint.md), not duplicated on this semantic global page.

## Cross-References

- [UID:000107][0x00482400-0x004824e0.GetChatButtonAtPoint](by-memory/0x00482400-0x004824e0.GetChatButtonAtPoint.md)
- [UID:0000I5][Chatting](by-file/Chatting.md)
- [UID:00001V][ChattingHandlePane](by-class/ChattingHandlePane.md)
- [UID:0002FT][0x00481d60-0x0048214f.ChattingHandlePaneOnMouseEvent](by-memory/0x00481d60-0x0048214f.ChattingHandlePaneOnMouseEvent.md)
- [UID:0002FW][0x00482310-0x00482400.GetChatButtonRectRaw](by-memory/0x00482310-0x00482400.GetChatButtonRectRaw.md)
- [UID:000104][0x0047efb0-0x00483ef7.ChattingUI](by-memory/0x0047efb0-0x00483ef7.ChattingUI.md)

## Changes

- 2026-07-07 B006 UID000107 implementation callback: raised `COMPLETION:86` / `CONFIDENCE:91` to `88/92`, preserved owner [UID:0000I5][Chatting](by-file/Chatting.md), `RECONSTRUCTABLE:TRUE`, and `EMITTER_UIDS:0000I5`, replaced the blank formal block with a coverage marker plus `[[CHILDREN]]` insertion point for [UID:000107][0x00482400-0x004824e0.GetChatButtonAtPoint](by-memory/0x00482400-0x004824e0.GetChatButtonAtPoint.md), corrected the source-facing signature to `GetChatButtonAtPoint(int mouseY, int mouseX)`, and documented current IDA session `43ccf853` label caveat plus pre-callback generated `Chatting.cpp` header `000000007832` / `2026-07-07T03:37:36-04:00`. The `[[CHILDREN]]` route keeps the global page non-duplicating while allowing the exact UID000107 child body to assemble under the accepted Chatting source route.

- 2026-06-28 B003 support sync: documented that [UID:0002FT][0x00481d60-0x0048214f.ChattingHandlePaneOnMouseEvent](by-memory/0x00481d60-0x0048214f.ChattingHandlePaneOnMouseEvent.md) uses this coordinate helper only on mouse down/up, that hover uses inline visible-button rectangles, and that the body-strip hit is input-dispatch behavior rather than drag/resize ownership. Score unchanged.
- 2026-06-16 C001 Goal 2 global/IDA refresh:
  - Changed to: `COMPLETION:86` and `CONFIDENCE:91`.
  - Summary/evidence: live IDA MCP session `b001_mappane_0001AW_20260616` reconfirmed function body `0x00482400-0x004824c9`, tail bytes through `0x004824e0`, the five jump-table dwords at `0x004824cc-0x004824e0`, the two coordinate call sites inside `ChattingHandlePane::OnMouseEvent`, and the adjacent raw rectangle helper table at `0x004823e0-0x004823f4`. C001 saved the `GetChatButtonAtPoint` IDA function label. Final C++ remains blank because the exact original file-local helper spelling and the rectangle companion's unmodeled/no-xref origin are still unresolved.

- 2026-05-30: Grading changed from `0/0` to `80/86`.
  - Before: page documented coordinate hit-test behavior, chat ownership, generated call-site mismatch, and source placement but remained unevaluated.
  - After: score reflects documented role, exact memory anchor, private chat-helper placement, and call-site caveat.
  - Evidence: the linked memory/chat pages record that the helper maps event coordinates to `ChattingHandlePane` button regions and that IDA pushes coordinate fields directly.
- 2026-05-31: Grading changed from `80/86` to `84/90`.
  - Before: page referenced the helper but did not account for the switch-table tail or companion rectangle helper.
  - After: page records the corrected `0x00482400-0x004824e0` by-memory range and cross-references the raw rectangle helper.
  - Evidence: IDA MCP raw head review confirms `jpt_482421` at `0x004824cc-0x004824e0`, and the companion helper at `0x00482310` writes the same four rectangles.
- 2026-06-05: Marked reconstructable and attached to [UID:0000I5][Chatting](by-file/Chatting.md).
  - Reason: live IDA MCP recheck confirms `sub_482400`, size `0xc9`, two callers inside `ChattingHandlePane::OnMouseEvent`, rectangle/point-test callees, and private chat-helper ownership.
