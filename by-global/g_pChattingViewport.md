*** UID:0002WV | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:87 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000OE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000OE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
class SystemMessagePane;

SystemMessagePane *g_pChattingViewport = 0;
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# g_pChattingViewport

## Status

- Address: `0x0067adc4`
- Storage page: [UID:0002WW][0x0067adc4-0x0067adc8.g_pChattingViewport](by-memory/0x0067adc4-0x0067adc8.g_pChattingViewport.md)
- Type hypothesis: `SystemMessagePane *` / chat viewport pane pointer.
- Owner: [UID:0000OE][SystemMessagePanes](by-file/SystemMessagePanes.md)

## Evidence

This is the first dword split from [UID:0002B5][0x0067adc4-0x0067adec.UiChatClanSingletonSlots](by-memory/0x0067adc4-0x0067adec.UiChatClanSingletonSlots.md). 2026-06-16 live IDA MCP recheck reads the current storage window as zero-filled virtual `.data`, confirms 16 xrefs, and saved the `g_pChattingViewport` data label. The direct lifecycle refs are `SystemMessagePane_Constructor` writes at `0x00584eed`/`0x00584ef4`, `SystemMessagePane_Destructor` clear at `0x00585337`, and `ClearChattingViewportSingleton` clear at `0x0058aad0`, with reads from system-message/UI helper paths.

2026-06-26 B006 [UID:0001M3][0x005b29c0-0x005b2f68.EmotionInputPane](by-memory/0x005b29c0-0x005b2f68.EmotionInputPane.md) source-quality implementation records a direct current-mode consumer. When `g_useEpfAssets == 1`, `EmotionInputPane::OnCharInput` reads this singleton at `0x005b2b35`, clears `+0x130` / inferred `m_refreshOnAppend` before batching the `?` emotion menu, calls `SystemMessagePane::AppendHeaderMarker()` (`0x005854b0`), `AppendColoredText(...)` (`0x005854d0`) for localized title id `31` and entry ids `15-30`, `AppendFooterMarker()` (`0x00585560`), and `RefreshAndPruneMessages()` (`0x00585360`), then reopens `EmotionInputPane`. This is consumer/type evidence for the existing `SystemMessagePane *` singleton only and does not change [UID:0000OE][SystemMessagePanes](by-file/SystemMessagePanes.md) ownership.

## Assignment Gate

Assigned to [UID:0000OE][SystemMessagePanes](by-file/SystemMessagePanes.md), now `89/86`. The relationship is direct because this global is the system-message viewport singleton; neighboring TextFilter, chat, and clan dwords are split into separate globals. The remaining blocker is the final source split between system-message panes and the broader chat/social module, not storage ownership.

## B011 Emission Disposition

Accepted B011 report `0000OE-SystemMessagePanes-empty-emitter-family-source-quality.md` emits this singleton as formal source in `social/SystemMessagePanes.cpp`:

```cpp
class SystemMessagePane;

SystemMessagePane *g_pChattingViewport = 0;
```

The declaration is source-ready because the global has exact storage [UID:0002WW][0x0067adc4-0x0067adc8.g_pChattingViewport](by-memory/0x0067adc4-0x0067adc8.g_pChattingViewport.md), a documented `SystemMessagePane *` type hypothesis, direct constructor/destructor/clear-helper lifecycle refs, and current-mode consumer refs. The exact by-memory storage child carries address/xref proof and should not duplicate this declaration.

## Cross-References

- [UID:0000OE][SystemMessagePanes](by-file/SystemMessagePanes.md)
- [UID:0001J6][0x00584ea0-0x0058af3b.SystemMessagePanes](by-memory/0x00584ea0-0x0058af3b.SystemMessagePanes.md)
- [UID:0002B5][0x0067adc4-0x0067adec.UiChatClanSingletonSlots](by-memory/0x0067adc4-0x0067adec.UiChatClanSingletonSlots.md)

## Changes

- 2026-06-30 B011 accepted empty-emitter implementation:
  - Inserted formal singleton pointer declaration into `RECONSTRUCTION_CPP CODE`.
  - Added emission disposition tying this declaration to exact storage [UID:0002WW][0x0067adc4-0x0067adc8.g_pChattingViewport](by-memory/0x0067adc4-0x0067adc8.g_pChattingViewport.md), `SystemMessagePane *` type evidence, and the rule that the storage child should not duplicate the source symbol.
- 2026-06-07 A008 Batch 037 split: created as the canonical global page for the `0x0067adc4` system-message/chat viewport singleton.
- 2026-06-16 C001 Goal 2 safe IDA refresh:
  - Changed to: score `87/90`; owner/emitter retained [UID:0000OE][SystemMessagePanes](by-file/SystemMessagePanes.md).
  - Summary/evidence: live IDA confirmed zero-filled storage, all 16 refs, saved `g_pChattingViewport`, `SystemMessagePane_Constructor`, `SystemMessagePane_Destructor`, and `ClearChattingViewportSingleton`, and rechecked the source-split blocker against the current SystemMessagePanes parent. Final C++ remains blank pending original declaration/header placement and system-message versus chat source split.
- 2026-06-26 B006 EmotionInputPane support sync:
  - Scores remain `87/90`; owner/emitter [UID:0000OE][SystemMessagePanes](by-file/SystemMessagePanes.md) and blank formal C++ are preserved.
  - Added [UID:0001M3][0x005b29c0-0x005b2f68.EmotionInputPane](by-memory/0x005b29c0-0x005b2f68.EmotionInputPane.md) current-mode `?` menu read at `0x005b2b35`, `+0x130` batch-refresh clear, and helper family calls as consumer evidence only.
