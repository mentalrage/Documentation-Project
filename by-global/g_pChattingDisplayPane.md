*** UID:0002WX | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000I5 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000I5 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
class ChattingPane;

ChattingPane *g_pChattingDisplayPane = NULL;

[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# g_pChattingDisplayPane

## Status

- Address/storage: exact loader-zeroed dword `[0x0067adcc,0x0067add0)` on [UID:0002WY][0x0067adcc-0x0067add0.g_pChattingDisplayPane](by-memory/0x0067adcc-0x0067add0.g_pChattingDisplayPane.md); bytes `00 00 00 00`, payload SHA256 `DF3F619804A92FDB4057192DC43DD748EA778ADC52BC498CE80524C014B81119`.
- Source type/name: `ChattingPane *g_pChattingDisplayPane`.
- Owner/emitter: [UID:0000I5][Chatting](by-file/Chatting.md), `NexusTK/social/Chatting.cpp`.
- Source declaration route: one `extern ChattingPane *g_pChattingDisplayPane;` through [UID:00001X][ChattingPane](by-class/ChattingPane.md).
- Source definition route: this page emits the sole definition with VC-era `NULL`; `[[CHILDREN]]` emits the exact physical marker after it.
- Scores `92/94` reflect exact storage, source type/name, all references, publication/clear/read lifetime, declaration/definition placement, one-definition proof, and compiler-wrapper exclusion.

## Evidence

The exhaustive direct-reference set contains 20 sites: publication `0x0047effd`; compiler adjusted-null fallback `0x0047f004`; ordinary source clear `0x0047f25d`; constructor-unwind clear `0x004839e0`; scalar-wrapper clear `0x00483cf9`; and reads `0x00480943`, `0x00480b48`, `0x00481ccc`, `0x00481e16`, `0x00481e35`, `0x00481e5e`, `0x00504947`, `0x005579eb`, `0x00557a3c`, `0x00557dc7`, `0x00557e18`, `0x00558189`, `0x005581da`, `0x0059de73`, and `0x0059de9b`. The role total is one publication, four clear manifestations, and fifteen reads.

[UID:0002EO][0x0047efb0-0x0047f1ce.ChattingPaneConstructor](by-memory/0x0047efb0-0x0047f1ce.ChattingPaneConstructor.md) owns the unconditional source publication. Its adjusted-null fallback is compiler lowering, not a handwritten null branch. [UID:0002EP][0x0047f1d0-0x0047f27e.ChattingPaneDestructor](by-memory/0x0047f1d0-0x0047f27e.ChattingPaneDestructor.md) owns the unconditional source clear. The cleanup helper and scalar deleting wrapper in [UID:0002GI][0x004839c0-0x00483ef7.ChattingUiDestructorGlueFamily](by-memory/0x004839c0-0x00483ef7.ChattingUiDestructorGlueFamily.md) are compiler manifestations and must not emit duplicate source.

The fifteen reads cover modify-height layout, handle scrolling/invalidation, MapPane UI removal, JPG/BMP/PNG screenshot status messages, and user-list source messages. They consistently use this value as a `ChattingPane`/inherited pane receiver or null-test before receiver use. They prove type and liveness, not ownership.

B003 2026-06-28 source-quality implementation for [UID:0002FT][0x00481d60-0x0048214f.ChattingHandlePaneOnMouseEvent](by-memory/0x00481d60-0x0048214f.ChattingHandlePaneOnMouseEvent.md) records two additional source-quality dependency facts for this singleton: the handle mode and secondary-chat release paths invalidate `g_pChattingDisplayPane->m_bounds`, and the secondary-chat toggle calls `ScrollWidget::Enable` or `ScrollWidget::Disable` on the display pane's scroll widget at object offset `+0xfc`. These are consumers of the display pane singleton, not ownership changes.

## One-Definition And Negative Evidence

- The four static zero bytes and absence of a dynamic initializer support `= NULL`; historical `0xffffffff`, integer, and sentinel interpretations are superseded.
- This semantic page owns the only definition. The physical child is marker-only; the class surface supplies only an `extern`; consumers supply neither declaration nor definition.
- No consumer publishes the pointer, no second source definition exists, and no evidence supports ScreenshotCapture, UserListDialogPane, MapPane, a handle pane, or the mixed storage aggregate as owner.
- No new file, split, child, initializer helper, conditional destructor guard, compiler-wrapper body, or IDA mutation is required.

## Assignment Gate

Assigned to [UID:0000I5][Chatting](by-file/Chatting.md), which becomes `89/93` in this accepted callback. The relationship is direct because Chatting.cpp owns the definition, constructor/destructor lifecycle, and class source family. This page and its exact storage child are both `92/94`.

## Cross-References

- [UID:0000I5][Chatting](by-file/Chatting.md)
- [UID:00001X][ChattingPane](by-class/ChattingPane.md)
- [UID:000104][0x0047efb0-0x00483ef7.ChattingUI](by-memory/0x0047efb0-0x00483ef7.ChattingUI.md)
- [UID:0002B5][0x0067adc4-0x0067adec.UiChatClanSingletonSlots](by-memory/0x0067adc4-0x0067adec.UiChatClanSingletonSlots.md)

## Changes

- 2026-07-21 B001 UID0002WY source-quality callback: raised this semantic global from `86/90` to `92/94`, retained owner/emitter UID0000I5 and blank position, added `[[CHILDREN]]` after the sole `ChattingPane *g_pChattingDisplayPane = NULL;` definition, and documented exact storage/hash, all 20 references and 1/4/15 roles, constructor/destructor/compiler lifetime, external declaration route, consumer/non-owner evidence, and one-definition exclusions. The former `85/88` Chatting assignment text is superseded by the accepted `89/93` file state.
- 2026-06-30 B005 UID0000I5 empty-emitter family callback: inserted formal VC-era singleton definition `ChattingPane *g_pChattingDisplayPane = NULL;` with an ordinary forward declaration and kept score/owner/emitter route unchanged. Accepted evidence: active MCP reads `0x0067adcc` as zero/null storage with 20 xrefs across chat display construction, message/paint paths, destructor/scalar clear paths, and UI consumers, with exact storage page [UID:0002WY][0x0067adcc-0x0067add0.g_pChattingDisplayPane](by-memory/0x0067adcc-0x0067add0.g_pChattingDisplayPane.md).
- 2026-06-07 A008 Batch 037 split: created as the canonical global page for the chat display pane singleton.
- 2026-06-28 B003 support sync: added [UID:0002FT][0x00481d60-0x0048214f.ChattingHandlePaneOnMouseEvent](by-memory/0x00481d60-0x0048214f.ChattingHandlePaneOnMouseEvent.md) dependency notes for display-pane invalidation and `ScrollWidget::Enable/Disable` at display pane `+0xfc`. Score unchanged.
