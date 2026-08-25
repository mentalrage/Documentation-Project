*** UID:0002X5 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000I5 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000I5 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL:0 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
class ChattingVarietyPane;

ChattingVarietyPane *g_pChattingVarietyPane = NULL;
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# g_pChattingVarietyPane

## Status

- Address and storage: `[0x0067add8,0x0067addc)`, one 32-bit pointer slot represented physically by [UID:0002X6][0x0067add8-0x0067addc.g_pChattingVarietyPane](by-memory/0x0067add8-0x0067addc.g_pChattingVarietyPane.md).
- Storage page: [UID:0002X6][0x0067add8-0x0067addc.g_pChattingVarietyPane](by-memory/0x0067add8-0x0067addc.g_pChattingVarietyPane.md)
- Type: `ChattingVarietyPane *`.
- Owner/emitter: [UID:0000I5][Chatting](by-file/Chatting.md), position `0` in generated `Chatting.cpp` so the definition precedes constructor and consumer use.
- Source definition: `ChattingVarietyPane *g_pChattingVarietyPane = NULL;` with a forward declaration for the pane class.
- Source disposition: reconstructable semantic global. The physical storage page is deliberately non-emitting to prevent duplicate definitions.

## Evidence

The target-specific audit records exactly 18 executable xrefs for this slot: three writes and 15 reads. [UID:00001Y][ChattingVarietyPane](by-class/ChattingVarietyPane.md) documents the constructor publication at `0x00480c75`, ordinary-destructor clear at `0x00480cba`, compiler scalar-deleting-wrapper clear at `0x00483d70`, eight selector mouse refresh branches at `0x00481270`, `0x004812a7`, `0x004812de`, `0x00481315`, `0x0048134c`, `0x0048138b`, `0x004813ab`, and `0x004813f0`, and selector-dismiss refresh at `0x00481473`.

The remaining consumers are [UID:00035P][0x004f1c00-0x004f2009.LineInputPaneConstructor](by-memory/0x004f1c00-0x004f2009.LineInputPaneConstructor.md) at `0x004f1e32`, line-input key close/reset at `0x004f268c`, `MapPane` exit cleanup at `0x00504983`, SelectObject cleanup at `0x005afc6d`, TargetObject cleanup at `0x005b04ed`, and NewSay empty-backspace cleanup at `0x005b1ce3`. The constructor's current-layout branch first publishes `this` through `g_pUserPane->m_activeLineInputPane`, then invokes the pane's no-argument refresh/invalidation virtual through this singleton; the legacy branch does neither. All dereferences are null-guarded or occur inside pane lifecycle paths; none writes an integer sentinel or retypes the slot.

Physical IDA synchronization remains owned by [UID:0002X6][0x0067add8-0x0067addc.g_pChattingVarietyPane](by-memory/0x0067add8-0x0067addc.g_pChattingVarietyPane.md). Catalog entry 0377 records the applied saved state: one four-byte item named `g_pChattingVarietyPane`, type `ChattingVarietyPane *`, regular comment `Active ChattingVarietyPane singleton pointer used by chat-mode selection and bounds invalidation.`, and repeatable comment `ChattingVarietyPane *g_pChattingVarietyPane;`. Readback preserves zero bytes, all 18 start xrefs, zero interior xrefs, and both adjacent singleton slots. Prestate/backup `4A9360D1...26C94` is dated history; authoritative saved IDB `A0D97FC56A57D864269A7E79227523CB04C3F981C7634F138848D32854375971`, 143,195,218 bytes, saved `2026-07-30T14:32:20.6295670-04:00`, contains the poststate. This semantic page remains the sole source definition and does not authorize a second data item or definition.

The repeated refresh dispatch uses vtable slot `+0x48`, ultimately forwarding to pane bounds invalidation at slot `+0x20`. This confirms live singleton use and the `ChattingVarietyPane *` type. Constructor and ordinary-destructor source carriers remain [UID:0002FA][0x00480c50-0x00480c9f.ChattingVarietyPaneConstructor](by-memory/0x00480c50-0x00480c9f.ChattingVarietyPaneConstructor.md) and the class destructor declaration; the scalar deleting wrapper remains compiler-only and is not copied into this global's C++.

The exact target bytes are `00 00 00 00`, SHA-256 `DF3F619804A92FDB4057192DC43DD748EA778ADC52BC498CE80524C014B81119`. The enclosing 40-byte singleton island hashes to `2C34CE1DF23B838C5ABF2A7F6437CCA3D3067ED509FF25F11DF6B11B582B51EB`. PE mapping places the target in the loader-created virtual tail of `.data`, so the binary shape is exactly consistent with static null initialization.

B005 2026-06-18 target-selection reanalysis records SelectObject and TargetObject mouse-handler consumers: [UID:0001LE][0x005afa10-0x005afc8d.SelectObjectWithKeyboardPaneOnMouseEvent](by-memory/0x005afa10-0x005afc8d.SelectObjectWithKeyboardPaneOnMouseEvent.md) and [UID:0001LL][0x005b0290-0x005b050d.TargetObjectWithKeyboardPaneMouseEvent](by-memory/0x005b0290-0x005b050d.TargetObjectWithKeyboardPaneMouseEvent.md) call virtual slot `+0x48` after confirmed object interaction when `g_pChattingHandlePane+0x111` indicates pending chat-target/current-chat-mode state. This is a Chatting UI refresh dependency, not an ownership move.

## Assignment Gate

Assigned to [UID:0000I5][Chatting](by-file/Chatting.md), now `89/92`. This global is `92/94`: type, ownership, source route, initializer, lifecycle, use graph, and emitter order are closed. The remaining confidence cap is lexical rather than behavioral: `= 0` or tentative zero initialization could generate equivalent storage, but explicit `NULL` is the strongest VC-era, family-consistent human source form.

Rejected alternatives remain bounded: `nullptr` does not match the source/compiler era; `-1` contradicts the loader-zero bytes and null checks; file-local `static` conflicts with cross-family consumers and the class `extern`; raw integer/byte-array or cast-backed declarations discard the proved pane type; a second definition on UID0002X6 would violate one-definition/source-generation requirements.

## Cross-References

- [UID:0000I5][Chatting](by-file/Chatting.md)
- [UID:00001Y][ChattingVarietyPane](by-class/ChattingVarietyPane.md)
- [UID:0002FA][0x00480c50-0x00480c9f.ChattingVarietyPaneConstructor](by-memory/0x00480c50-0x00480c9f.ChattingVarietyPaneConstructor.md)
- [UID:0002B5][0x0067adc4-0x0067adec.UiChatClanSingletonSlots](by-memory/0x0067adc4-0x0067adec.UiChatClanSingletonSlots.md)

## Changes

- 2026-07-30 B008 UID00035P ordinary callback: recorded the exact current-layout LineInputPane constructor consumer and its active-slot-before-refresh ordering, linked the semantic declaration to the physical page's then-supervisor-only materialization/name/type/comment handoff, and preserved the single Chatting.cpp definition, `92/94` score, ownership, and emitter position. Supervisor catalog entry 0377 later applied and verified that physical one-item state without changing this page's source emission.
- 2026-07-21 B004 UID0002X6 source-closure callback: raised the semantic global to `92/94`, set emitter position `0`, retained the exact VC-era `NULL` definition, and added exact storage/PE evidence, all 18 classified references, lifecycle/source ownership, callback liveness, source-order rationale, confidence cap, and rejected alternatives. The physical UID0002X6 page remains blank and non-emitting.
- 2026-06-30 B005 UID0000I5 empty-emitter family callback: inserted formal VC-era singleton definition `ChattingVarietyPane *g_pChattingVarietyPane = NULL;` with an ordinary forward declaration and kept score/owner/emitter route unchanged. Accepted evidence: active MCP reads `0x0067add8` as zero/null storage with 18 xrefs across variety pane lifecycle, selector mouse paths, and UI setup, with exact storage page [UID:0002X6][0x0067add8-0x0067addc.g_pChattingVarietyPane](by-memory/0x0067add8-0x0067addc.g_pChattingVarietyPane.md).
- 2026-06-07 A008 Batch 037 split: created as the canonical global page for the chat mode variety pane singleton.
- 2026-06-18 B005 target-selection support sync: added SelectObject and TargetObject mouse-handler cleanup consumers. Score unchanged.
