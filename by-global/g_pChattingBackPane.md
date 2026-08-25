*** UID:0002WZ | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:87 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000I5 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000I5 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
class ChattingBackPane;

ChattingBackPane *g_pChattingBackPane = NULL;
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# g_pChattingBackPane

## Status

- Address: `0x0067add0`
- Storage page: [UID:0002X0][0x0067add0-0x0067add4.g_pChattingBackPane](by-memory/0x0067add0-0x0067add4.g_pChattingBackPane.md)
- Type hypothesis: `ChattingBackPane *`
- Owner: [UID:0000I5][Chatting](by-file/Chatting.md)
- Current IDA label: `g_pChattingBackPane` after the 2026-06-16 C001 refresh.

## Evidence

- 2026-06-16 C001 live IDA MCP confirms the containing `0x0067adc4-0x0067adf4` virtual `.data` window is zero-filled; the older `0xffffffff` storage note in the exact memory child was stale.
- The saved `g_pChattingBackPane` slot has 8 direct xrefs: constructor publish at `0x00480664`, destructor clear at `0x004806ba`, UI/read paths at `0x00480923`, `0x00480af9`, `0x00481e07`, `0x00481e4f`, scalar-deleting destructor clear at `0x00483ac0`, and a later chat UI consumer at `0x00504961`.
- IDA labels saved during this pass: `g_pChattingBackPane`, `ChattingBackPane_Constructor`, `ChattingBackPane_Destructor`, and `ChattingBackPane_ScalarDeletingDestructor`.
- [UID:00001R][ChattingBackPane](by-class/ChattingBackPane.md) and [UID:0002F1][0x00480640-0x00480694.ChattingBackPaneConstructor](by-memory/0x00480640-0x00480694.ChattingBackPaneConstructor.md) document the class/vtable evidence, constructor store, alpha field initialization, destructor clear, scalar-deleting destructor clear, and visibility reads tied to chat handle state.
- B005 2026-06-18 source-quality pass on [UID:0002F2][0x004806a0-0x004806c9.ChattingBackPaneDestructor](by-memory/0x004806a0-0x004806c9.ChattingBackPaneDestructor.md) confirms the ordinary `ChattingBackPane::~ChattingBackPane()` source body clears this slot unconditionally; the scalar deleting wrapper at `0x00483aa0` mirrors the same clear before generated delete handling.
- B003 2026-06-28 source-quality implementation for [UID:0002FT][0x00481d60-0x0048214f.ChattingHandlePaneOnMouseEvent](by-memory/0x00481d60-0x0048214f.ChattingHandlePaneOnMouseEvent.md) records `g_pChattingBackPane` as a dependent refresh target: the handle mode release path and secondary-chat release path invalidate `g_pChattingBackPane->m_bounds`. This is a consumer relationship and does not move ownership from `ChattingBackPane`.

## Assignment Gate

Assigned to [UID:0000I5][Chatting](by-file/Chatting.md). The relationship is direct because this global stores the chat background pane singleton, and the exact storage child now independently clears `87/90`.

## Source-Quality Notes

- Owner/emitter remains [UID:0000I5][Chatting](by-file/Chatting.md). The nearby `0x0067adc4-0x0067adec` aggregate remains a split map, not an emitting parent.
- Formal C++ now carries the source-facing singleton declaration/definition with `NULL` initialization. Exact private field/helper names in the broader chat pane family are still not final, so method bodies remain on their exact child pages.
- Skipped unsafe IDA edits: no prototypes, struct/member names, locals, or raw functions were changed.

## Cross-References

- [UID:0000I5][Chatting](by-file/Chatting.md)
- [UID:00001R][ChattingBackPane](by-class/ChattingBackPane.md)
- [UID:0002F1][0x00480640-0x00480694.ChattingBackPaneConstructor](by-memory/0x00480640-0x00480694.ChattingBackPaneConstructor.md)
- [UID:0002B5][0x0067adc4-0x0067adec.UiChatClanSingletonSlots](by-memory/0x0067adc4-0x0067adec.UiChatClanSingletonSlots.md)

## Changes

- 2026-06-30 B005 UID0000I5 empty-emitter family callback: inserted formal VC-era singleton definition `ChattingBackPane *g_pChattingBackPane = NULL;` with an ordinary forward declaration and kept score/owner/emitter route unchanged. Accepted evidence: active MCP reads `0x0067add0` as zero/null storage with eight lifecycle/consumer xrefs, including constructor, destructor/scalar clear paths, layout/update consumers, and paired storage page [UID:0002X0][0x0067add0-0x0067add4.g_pChattingBackPane](by-memory/0x0067add0-0x0067add4.g_pChattingBackPane.md).
- 2026-06-07 A008 Batch 037 split: created as the canonical global page for the chat background pane singleton.
- 2026-06-16 C001 Goal 2 refresh: Raised `85/89` to `87/90`; live IDA reconfirmed zero-filled storage, the exact 8-reference lifecycle/consumer set, constructor/destructor/scalar-deleting destructor decompilation, and saved `g_pChattingBackPane`, `ChattingBackPane_Constructor`, `ChattingBackPane_Destructor`, and `ChattingBackPane_ScalarDeletingDestructor` labels. The stale `0xffffffff` storage note was corrected in the exact memory child; final C++ remains blocked by declaration/header placement and private field/helper names.
- 2026-06-28 B003 support sync: added [UID:0002FT][0x00481d60-0x0048214f.ChattingHandlePaneOnMouseEvent](by-memory/0x00481d60-0x0048214f.ChattingHandlePaneOnMouseEvent.md) dependency notes for back-pane invalidation on mode and secondary-chat releases. Score unchanged.
