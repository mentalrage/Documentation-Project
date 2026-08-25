*** UID:0002XA | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000I5 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000I5 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL:0 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
class ChattingVarietySelectPane;

ChattingVarietySelectPane *g_pChattingVarietySelectPane = NULL;
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# g_pChattingVarietySelectPane

## Status

- Address: `0x0067addc`
- Storage page: [UID:0002XB][0x0067addc-0x0067ade0.g_pChattingVarietySelectPane](by-memory/0x0067addc-0x0067ade0.g_pChattingVarietySelectPane.md)
- Source type: `ChattingVarietySelectPane *` with external linkage.
- Owner: [UID:0000I5][Chatting](by-file/Chatting.md)
- Source placement: sole Chatting translation-unit definition at emitter position `0`; [UID:00001Z][ChattingVarietySelectPane](by-class/ChattingVarietySelectPane.md) supplies the one matching `extern` declaration at class position `10`.

## Evidence

The exact physical storage child [UID:0002XB][0x0067addc-0x0067ade0.g_pChattingVarietySelectPane](by-memory/0x0067addc-0x0067ade0.g_pChattingVarietySelectPane.md) contains four loader-zeroed bytes, SHA256 `DF3F619804A92FDB4057192DC43DD748EA778ADC52BC498CE80524C014B81119`, in the virtual `.data` tail. This semantic page is the only source object needed to regenerate that storage. Explicit `NULL` is the highest-probability VC-era initializer and is behavior-equivalent to implicit static zero; raw `dword_67ADDC`, an integer/void object, `static` internal linkage, an anonymous namespace, function-local storage, and a duplicate physical-page definition are rejected.

Fresh MCP proves exactly seven address references. Runtime reads are UID0002FC's popup-present test at `0x00480d7f` and UID0002FD's paint-state read at `0x00480eb2`. The remaining five are compiler-lowered direct-`Singleton<ChattingVarietySelectPane>` publication, unwind fallback, ordinary destruction, and scalar-wrapper stores/clears at `0x00480dc2`, `0x00480dc9`, `0x00481115`, `0x0048119d`, and `0x00483e04`. RTTI identifies the direct Singleton base and PMD `+0xf8`; therefore these writes are class-lifetime lowering, not evidence for a second handwritten global or explicit constructor/destructor assignments.

The source-order contract is one incomplete class declaration followed by this one external definition before any use. The complete selector class later declares the same pointer once with `extern`. UID0002XB is now false/non-emitting with blank formal C++, so generated `Chatting.cpp` must contain exactly one definition and no physical marker, alias, or duplicate source.

## Assignment Gate

Assigned directly to [UID:0000I5][Chatting](by-file/Chatting.md) and source-ready at `92/94`. The retained raw constructor, compact helper declarations, complete popup handler, destructor source/compiler split, typed class declaration, and final Chatting source route are all resolved on their exact pages; no former score blocker remains deferred.

## Cross-References

- [UID:0000I5][Chatting](by-file/Chatting.md)
- [UID:00001Z][ChattingVarietySelectPane](by-class/ChattingVarietySelectPane.md)
- [UID:000106][0x00481ad0-0x00481b5b.ChattingVarietySelectPaneHitTest](by-memory/0x00481ad0-0x00481b5b.ChattingVarietySelectPaneHitTest.md)
- [UID:0002B5][0x0067adc4-0x0067adec.UiChatClanSingletonSlots](by-memory/0x0067adc4-0x0067adec.UiChatClanSingletonSlots.md)

## Changes

- 2026-07-21 B002 UID0002XB source-quality callback:
  - Raised the semantic global to `92/94`, set emitter position `0`, retained UID0000I5 ownership/emission, and preserved the exact sole definition `ChattingVarietySelectPane *g_pChattingVarietySelectPane = NULL;`.
  - Added exact physical-child/hash/PE-zero proof, complete seven-reference role classification, direct-Singleton publication/clear explanation, external-linkage/header split, source ordering, one-definition/generated contract, rejected alternatives, and closure of the historical raw-constructor/helper/source-split blockers.
- 2026-06-30 B005 UID0000I5 empty-emitter family callback: inserted formal VC-era singleton definition `ChattingVarietySelectPane *g_pChattingVarietySelectPane = NULL;` with an ordinary forward declaration and kept score/owner/emitter route unchanged. Accepted evidence: active MCP reads `0x0067addc` as zero/null storage with seven xrefs across selector popup lifecycle and consumers, with exact storage page [UID:0002XB][0x0067addc-0x0067ade0.g_pChattingVarietySelectPane](by-memory/0x0067addc-0x0067ade0.g_pChattingVarietySelectPane.md).
- 2026-06-07 A008 Batch 037 split: created as the canonical global page for the chat mode selector popup singleton.
- 2026-06-16 C001 Goal 2 safe IDA refresh:
  - Changed to: score `86/90`; owner/emitter retained [UID:0000I5][Chatting](by-file/Chatting.md).
  - Summary/evidence: live IDA confirmed zero-filled storage bytes, the exact 7-ref set, and selector open/destructor/scalar-destructor refs; saved `g_pChattingVarietySelectPane`, `ChattingVarietySelectPane_Destructor`, and `ChattingVarietySelectPane_ScalarDeletingDestructor`. At that time formal C++ remained blank; the 2026-06-30 B005 callback supersedes that for the global definition only, while the raw constructor and exact helper/source-split names remain capped on their own pages.
