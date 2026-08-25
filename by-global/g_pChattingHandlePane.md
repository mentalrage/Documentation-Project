*** UID:0002XE | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000I5 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000I5 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL:0 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
class ChattingHandlePane;

ChattingHandlePane *g_pChattingHandlePane = 0;
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# g_pChattingHandlePane

## Status

- Address: `0x0067ade0`
- Storage page: [UID:0002XF][0x0067ade0-0x0067ade4.g_pChattingHandlePane](by-memory/0x0067ade0-0x0067ade4.g_pChattingHandlePane.md)
- Type: `ChattingHandlePane *`
- Owner: [UID:0000I5][Chatting](by-file/Chatting.md)
- Source position: `0`, before the complete class declaration and all method definitions in `NexusTK/social/Chatting.cpp`.
- One-definition policy: this page emits the sole externally linked zero definition. UID0002XF and UID0002B5 are physical/index evidence and emit nothing.

## Evidence

The mixed-range audit records 15 xrefs for this slot. [UID:00001V][ChattingHandlePane](by-class/ChattingHandlePane.md) documents the constructor store, destructor and scalar-deleting destructor clear paths, persisted config state, and reads from chat/map UI consumers.

### B002 2026-07-21 Semantic Global / Lifetime Closure

- The exact physical bytes are loader-zeroed storage, not an authored `0xffffffff` initializer. The source-facing definition uses period-consistent `0`; `NULL` would produce the same storage but is superseded here for consistency with the accepted direct-Singleton sibling source.
- Fresh MCP classifies all fifteen references: five compiler-lifetime references at `0x00481c58`, `0x00481c5f`, `0x00481d4a`, `0x004839c0`, and `0x00483bc0`; ten runtime reads at `0x0047f932`, `0x00480740`, `0x004808a0`, `0x00480bc0`, `0x004f266b`, `0x00504994`, `0x005a514b`, `0x005afc50`, `0x005b04d0`, and `0x005b1cc6`.
- RTTI directly names `Singleton<ChattingHandlePane>` with PMD `+0xf8`. The constructor's adjusted-null publication and ordinary/unwind/scalar clears are template/base compiler lowering, not explicit statements in the derived constructor/destructor. The formal global definition remains necessary because the Singleton specialization references this semantic slot.
- Runtime meanings are exhaustive: current-layout ChattingPane paint gate; ChattingBackPane mode/secondary visibility; modify-height mouse and paint gates; LineInputPane pending-target cleanup; null-checked MapPane teardown; current-say dispatcher gate; SelectObject/TargetObject cleanup; and NewSayToUser empty-backspace transition.
- Established-lifetime consumers that omit a null guard do not imply local ownership. The one guarded teardown read also does not own the definition. The declaration remains in the complete [UID:00001V][ChattingHandlePane](by-class/ChattingHandlePane.md) class/header formal.
- Rejected source shapes are `static`/internal linkage, a second definition on UID0002XF, an aggregate definition on UID0002B5, explicit constructor/destructor publication/clear, and handwritten vptr/EH/scalar/vtable/RTTI mechanics.

B005 2026-06-18 target-selection reanalysis records SelectObject and TargetObject mouse-handler consumers: [UID:0001LE][0x005afa10-0x005afc8d.SelectObjectWithKeyboardPaneOnMouseEvent](by-memory/0x005afa10-0x005afc8d.SelectObjectWithKeyboardPaneOnMouseEvent.md) and [UID:0001LL][0x005b0290-0x005b050d.TargetObjectWithKeyboardPaneMouseEvent](by-memory/0x005b0290-0x005b050d.TargetObjectWithKeyboardPaneMouseEvent.md) check `g_pChattingHandlePane+0x111` before clearing UserPane chat-target/current-chat-mode state and refreshing `g_pChattingVarietyPane`. This is a Chatting dependency used by target-selection cleanup, not an ownership move.

B009 2026-06-26 source-quality implementation for [UID:0002RX][0x005a5110-0x005a5337.OpenInputPaneForCurrentSayMode](by-memory/0x005a5110-0x005a5337.OpenInputPaneForCurrentSayMode.md) records the same `+0x111` byte as the pending chat-target gate read by the current-mode dispatcher. If this pending state is true, the dispatcher bypasses the EPF/current-mode switch and opens the default say input path. Use source-facing language such as `m_chatTargetPending` or "pending chat target state"; do not promote the raw offset as the final source name.

B003 2026-06-28 source-quality implementation for [UID:0002FT][0x00481d60-0x0048214f.ChattingHandlePaneOnMouseEvent](by-memory/0x00481d60-0x0048214f.ChattingHandlePaneOnMouseEvent.md) resolves the same byte's write side: the left chat-handle button toggles class-side `ChattingHandlePane::m_chatTargetPending`, and every mouse-up path persists it as config-side `g_pConfig->m_chatHandleLeftToggle` at `+0x28de81`. This is one dual-role state byte, not a conflict between target-selection naming and chat-handle config naming.

B007 2026-06-29 source-quality implementation for [UID:0002F3][0x00480740-0x004807aa.ChattingBackPaneUpdateVisibility](by-memory/0x00480740-0x004807aa.ChattingBackPaneUpdateVisibility.md) adds this global as the handle-state source for `ChattingBackPane::UpdateVisibility`. Current MCP session `B006_0002F1_20260629` shows the method reading `g_pChattingHandlePane` from `0x0067ade0`, then loading `+0x114` as `m_chatHandleModeIndex` and byte `+0x118` as `m_secondaryChatEnabled`. The active branch requires nonzero `m_chatHandleModeIndex` and true `m_secondaryChatEnabled`; mode index `1` drives the back pane to alpha `0.7f`, other nonzero modes drive alpha `0.3f`, and the inactive branch uses mode/color state `1`/`0`. This is a consumer of the `ChattingHandlePane` state fields, not an ownership move for the back-pane virtual.

B004's 2026-07-13 source-quality implementation for [UID:0002EV][0x0047f8d0-0x0047fbc5.ChattingPaneOnPaint](by-memory/0x0047f8d0-0x0047fbc5.ChattingPaneOnPaint.md) adds a direct display-paint consumer of this singleton. In current `g_useEpfAssets == 1` layout, OnPaint loads `g_pChattingHandlePane` from `0x0067ade0`, reads `m_secondaryChatEnabled` at `+0x118` without a null check, and skips clip acquisition/message iteration when false while still setting draw color zero and filling `m_bounds`. The legacy branch does not read this singleton. This is consumer evidence only; owner/emitter and singleton lifetime remain with Chatting/ChattingHandlePane.

## Assignment Gate

Assigned to [UID:0000I5][Chatting](by-file/Chatting.md), currently `89/93`. This global is `92/94`, reconstructable, emitted once by Chatting at position `0`; its physical child is `92/94` false/non-emitting.

## Cross-References

- [UID:0000I5][Chatting](by-file/Chatting.md)
- [UID:00001V][ChattingHandlePane](by-class/ChattingHandlePane.md)
- [UID:0002F3][0x00480740-0x004807aa.ChattingBackPaneUpdateVisibility](by-memory/0x00480740-0x004807aa.ChattingBackPaneUpdateVisibility.md)
- [UID:0002EV][0x0047f8d0-0x0047fbc5.ChattingPaneOnPaint](by-memory/0x0047f8d0-0x0047fbc5.ChattingPaneOnPaint.md)
- [UID:0002FR][0x00481c10-0x00481d2a.ChattingHandlePaneConstructor](by-memory/0x00481c10-0x00481d2a.ChattingHandlePaneConstructor.md)
- [UID:0002B5][0x0067adc4-0x0067adec.UiChatClanSingletonSlots](by-memory/0x0067adc4-0x0067adec.UiChatClanSingletonSlots.md)

## Changes

- 2026-07-21 B002 UID0002XF callback: raised `86/90` to `92/94`, set source position `0`, retained owner/emitter UID0000I5, normalized the sole definition to `ChattingHandlePane *g_pChattingHandlePane = 0;`, and incorporated exact loader-zero/one-definition, all-fifteen-reference, direct-Singleton, runtime-consumer, compiler-exclusion, source-order, negative-evidence, and historical-initializer facts.
- 2026-07-13 B004 UID0002EV support synchronization: added ChattingPane::OnPaint as a direct `m_secondaryChatEnabled` read consumer at `+0x118`, including the current-layout-only gate, no-null-check contract, disabled fill-but-no-iteration behavior, and dependency-only ownership disposition. Score, singleton definition, owner/emitter, route, and all existing consumers remain unchanged at `86/90`.
- 2026-06-30 B005 UID0000I5 empty-emitter family callback: inserted formal VC-era singleton definition `ChattingHandlePane *g_pChattingHandlePane = NULL;` with an ordinary forward declaration and kept score/owner/emitter route unchanged. Accepted evidence: active MCP reads `0x0067ade0` as zero/null storage with 15 xrefs across handle constructor/destructor, button/mode methods, back-pane consumers, map/target cleanup, and say-mode dispatch, with exact storage page [UID:0002XF][0x0067ade0-0x0067ade4.g_pChattingHandlePane](by-memory/0x0067ade0-0x0067ade4.g_pChattingHandlePane.md).
- 2026-06-07 A008 Batch 037 split: created as the canonical global page for the chat handle pane singleton.
- 2026-06-18 B005 target-selection support sync: added SelectObject and TargetObject mouse-handler cleanup consumers. Score unchanged.
- 2026-06-26 B009 SayInputPanes support sync: added [UID:0002RX][0x005a5110-0x005a5337.OpenInputPaneForCurrentSayMode](by-memory/0x005a5110-0x005a5337.OpenInputPaneForCurrentSayMode.md) as a dispatcher consumer of `g_pChattingHandlePane + 0x111` and recorded the source-facing `m_chatTargetPending` interpretation. Score unchanged.
- 2026-06-28 B003 support sync: added [UID:0002FT][0x00481d60-0x0048214f.ChattingHandlePaneOnMouseEvent](by-memory/0x00481d60-0x0048214f.ChattingHandlePaneOnMouseEvent.md) as the left-handle toggle writer/persistor for `m_chatTargetPending` and documented its config-side persisted name `m_chatHandleLeftToggle`. Score unchanged.
- 2026-06-29 B007 UID0002F3 support sync: added [UID:0002F3][0x00480740-0x004807aa.ChattingBackPaneUpdateVisibility](by-memory/0x00480740-0x004807aa.ChattingBackPaneUpdateVisibility.md) as a consumer of `m_chatHandleModeIndex` at `+0x114` and `m_secondaryChatEnabled` at `+0x118`; the back-pane method reads these fields to choose alpha/mode/color refresh behavior. Score unchanged.
