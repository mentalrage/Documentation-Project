*** UID:00005T | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:87 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:89 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000KC | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000KC | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
// No standalone class-page emission for GiveGoldInputPane; constructor source is [UID:0001MI][0x005b52b0-0x005b52f0.GiveGoldInputPaneRawConstructor](by-memory/0x005b52b0-0x005b52f0.GiveGoldInputPaneRawConstructor.md) and submit/helper evidence is documented by [UID:0001MG][0x005b44b0-0x005b538a.DropGiveInputPanes](by-memory/0x005b44b0-0x005b538a.DropGiveInputPanes.md).
[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# GiveGoldInputPane

## Status

- Confidence: strong for submit behavior, raw constructor bytes, vtable identity, packet behavior, exact constructor-boundary evidence, creator relationship, current global/helper naming, and item-action module placement; medium for raw-constructor/raw-helper reachability because both source-shaped islands still have no proven entry route.
- Likely source file: [UID:0000KC][ItemActionInputPanes](by-file/ItemActionInputPanes.md)
- Address ranges: raw constructor [UID:0001MI][0x005b52b0-0x005b52f0.GiveGoldInputPaneRawConstructor](by-memory/0x005b52b0-0x005b52f0.GiveGoldInputPaneRawConstructor.md), live submit body inside aggregate [UID:0001MG][0x005b44b0-0x005b538a.DropGiveInputPanes](by-memory/0x005b44b0-0x005b538a.DropGiveInputPanes.md), adjacent no-route raw helper [UID:0003MW][0x005b5390-0x005b53f9.SendGiveGoldPacketRaw](by-memory/0x005b5390-0x005b53f9.SendGiveGoldPacketRaw.md)
- Current recovered file: `source-3/simroot_v2/class_GiveGoldInputPane.cpp`; use it only as a generated/simulation lead because it contains stale names such as `QuitInputPane::ReadInputText`, `g_pPlayerData`, synthetic busy structs, and generated packet-sender classes.

## Class Purpose

`GiveGoldInputPane` is the numeric prompt opened by [UID:00005U][GiveInputPane](by-class/GiveInputPane.md) when the give command selects gold instead of an inventory item. It prompts with localized string id `0x2b` / `43`, parses an unsigned decimal amount, checks the active local [UID:0000QK][g_pCollectionData](by-global/g_pCollectionData.md) stable alias / source-facing `g_pUserPane` item-command busy byte at `+0x3ec0`, and queues a five-byte give-gold packet through the Socket send path.

The packet is exactly `[0x2a, amount:u32be]`. The submit body and the adjacent raw helper both write a sixth local zero byte after the amount, but the [UID:0001HU][0x00574bb0-0x00574c13.QueueAndSendPacket](by-memory/0x00574bb0-0x00574c13.QueueAndSendPacket.md) call uses explicit length `5`, so the zero byte is not transmitted.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| `GiveGoldInputPane::GiveGoldInputPane()` | [UID:0001MI][0x005b52b0-0x005b52f0.GiveGoldInputPaneRawConstructor](by-memory/0x005b52b0-0x005b52f0.GiveGoldInputPaneRawConstructor.md) | Raw constructor-shaped body with formal first-draft constructor C++ on the exact by-memory page. IDA still does not recognize this as a function start, and whole-file pointer checks found no start route; the live `GiveInputPane::OnConfirmInput` gold branch duplicates this construction inline, so no-route remains a confidence cap rather than a C++ blocker. |
| `OnSubmit` / descriptive `OnSubmitGoldAmount` | `0x005b52f0-0x005b538a` | Vtable-routed primary action/submit slot. Reads numeric text, parses `%u`, gates on `g_pUserPane->m_itemCommandBusy`, writes opcode `0x2a`, writes amount big-endian, and queues packet length `5`. Preserve `OnSubmit` as the base virtual role until the input-pane virtual spelling is finalized; use `OnSubmitGoldAmount` as the source-quality descriptive name for the future exact child. |
| `static SendGiveGoldPacket(unsigned int amount)` | `0x005b5390-0x005b53f9` | [UID:0003MW][0x005b5390-0x005b53f9.SendGiveGoldPacketRaw](by-memory/0x005b5390-0x005b53f9.SendGiveGoldPacketRaw.md) is an adjacent no-`this` retained raw helper that builds the same packet. It has no proven caller, pointer, vtable, callback, or computed-call route, while the live submit method emits equivalent packet logic inline. |

## Evidence Notes

- IDA MCP confirms `0x005b52f0` but reports no function at `0x005b52b0`.
- 2026-05-27 raw IDA disassembly confirms the constructor-shaped bytes at `0x005b52b0-0x005b52f0`: localized prompt id `0x2b` / `43`, `NumberInputPane` base construction, and vtable stores to `0x00630048`, `0x00630098`, and `0x006300c8`.
- 2026-05-27 IDA decompilation of `0x005b52f0` confirms the packet path uses [UID:0000QK][g_pCollectionData](by-global/g_pCollectionData.md) stable alias / source-facing [UID:0001OR][0x0067a748-0x0067a74c.g_pCollectionData](by-memory/0x0067a748-0x0067a74c.g_pCollectionData.md) byte `+0x3ec0` as an item-command busy gate and queues `[0x2a, amount:u32be]` through [UID:0000Q5][g_packetSender](by-global/g_packetSender.md).
- This class is created from [UID:00005U][GiveInputPane](by-class/GiveInputPane.md). The creator relationship does not move ownership to `GiveInputPane`; both classes are compact neighbors in [UID:0000KC][ItemActionInputPanes](by-file/ItemActionInputPanes.md).
- 2026-06-12 A005 Batch253 reconfirmed [UID:0001MI][0x005b52b0-0x005b52f0.GiveGoldInputPaneRawConstructor](by-memory/0x005b52b0-0x005b52f0.GiveGoldInputPaneRawConstructor.md) as a no-function/no-xref/no-pointer raw constructor with exact `0x40` / 64-byte size (Verified with int_convert.py), `0x04` / 4-byte pre-padding (Verified with int_convert.py), prompt id `0x2b` / 43 (Verified with int_convert.py), and the same vtable store triad mirrored by [UID:00005U][GiveInputPane](by-class/GiveInputPane.md)'s gold branch.
- 2026-06-19 B015 raw PE pass confirms the local executable md5 `4247e04e20b65d6414c7238aa8ff5515`, `.text` range `0x00401000-0x0060c4ac`, and the exact local boundary sequence: `0x005b50b0-0x005b5223` GiveInputPane confirm/gold route; `0x005b5223-0x005b5230` thirteen bytes of `0xcc`; `0x005b5230-0x005b52ac` adjacent give-item helper; `0x005b52ac-0x005b52b0` four bytes of `0xcc`; `0x005b52b0-0x005b52f0` raw constructor; `0x005b52f0-0x005b538a` submit method; `0x005b538a-0x005b5390` six bytes of `0xcc`; `0x005b5390-0x005b53f9` raw give-gold helper; and `0x005b53f9-0x005b5400` seven bytes of `0xcc`.
- Whole-file pointer/immediate checks from the B015 pass found zero hits to raw constructor start `0x005b52b0`, one hit to submit start `0x005b52f0` at primary vtable slot `0x00630090`, and zero hits to raw helper start/end `0x005b5390` / `0x005b53f9`. The `0x00630048`, `0x00630098`, and `0x006300c8` vtable immediates appear in exactly the live inline `GiveInputPane` branch and the raw constructor island.
- 2026-06-25 B005 current MCP session `80de0a67` supersedes the prior raw-constructor no-code direction for [UID:0001MI][0x005b52b0-0x005b52f0.GiveGoldInputPaneRawConstructor](by-memory/0x005b52b0-0x005b52f0.GiveGoldInputPaneRawConstructor.md) while preserving its negative evidence. The session reconfirmed the exact `0x40` / 64-byte constructor body, prompt id `0x2b` through `g_pLanguageMan->GetLocalizedString`, [UID:00009L][NumberInputPane](by-class/NumberInputPane.md) base construction, vtable stores `0x00630048`, `0x00630098`, and `0x006300c8` at `this+0`, `this+0xa0`, and `this+0xa4`, `0x005b52ac-0x005b52b0` padding, no modeled function or raw-start route, and the matching [UID:00005U][GiveInputPane](by-class/GiveInputPane.md) inline construction mirror.
- The submit method copies up to 15 wide characters through [UID:00035R][0x004f2300-0x004f230f.LineInputPaneCopyText](by-memory/0x004f2300-0x004f230f.LineInputPaneCopyText.md), checks positive copied length, calls the wide scanf wrapper [UID:000221][0x004941e0-0x00494519.MsvcComAndFormattingHelpers](by-memory/0x004941e0-0x00494519.MsvcComAndFormattingHelpers.md) at `0x004944f0` with format string `%u`, writes opcode through [UID:0003YJ][0x00575380-0x00575470.PacketBufferScalarBigEndianWriteHelpers](by-memory/0x00575380-0x00575470.PacketBufferScalarBigEndianWriteHelpers.md), writes the amount through `PacketBufferWriteUInt32BE`, and calls Socket-owned `QueueAndSendPacket` with length `5`.

## Heuristic / Inference Reanalysis And Validation

- Owner/emitter: keep [UID:0000KC][ItemActionInputPanes](by-file/ItemActionInputPanes.md). The drop/give item-action cluster, sibling [UID:000043][DropGoldInputPane](by-class/DropGoldInputPane.md), vtable family [UID:0001XU][ItemActionInputPaneVtableFamily](by-type/by-vtable/ItemActionInputPaneVtableFamily.md), adjacent packet helpers, and proposed `NexusTK/ui/dialogs/ItemActionInputPanes.cpp` source path all support this placement.
- Rejected owners: [UID:00005U][GiveInputPane](by-class/GiveInputPane.md) is the creator/dispatcher and should cross-reference this class but not absorb it; [UID:00009L][NumberInputPane](by-class/NumberInputPane.md) only owns reusable numeric input behavior; [UID:0000P1][UserPane](by-file/UserPane.md) owns the local-player state and packet callback targets; Socket and PacketBuffer own transport/scalar writers only; `GroupInputPane` starts after clean padding at `0x005b5400` and does not own this give-gold cluster.
- Prompt id `0x2b` / `43` is best documented as an inferred `kGiveGoldPromptStringId` / `LANG_PROMPT_GIVE_GOLD_AMOUNT` constant. Do not claim original enum spelling or a literal English prompt until the language table is recovered.
- Busy gate: use canonical source-facing `g_pUserPane->m_itemCommandBusy` at `+0x3ec0`. Keep `g_pCollectionData`, `g_pPlayerData`, and raw `dword_67A748` only as historical/generated aliases. Reject cash-shop-only names for this path because the observed consumers are item/gold action sends.
- Packet names: use [UID:0000Q5][g_packetSender](by-global/g_packetSender.md), `QueueAndSendPacket`, `PacketBufferWriteUInt8`, and `PacketBufferWriteUInt32BE`. Reject stale/generated names such as `g_pCashShopRequest`, `PacketSender::QueueAndSend`, `WriteByteZ_575380`, and `WriteUInt32BEZ_5753F0` for final source-facing documentation.
- Packet semantics: opcode `0x2a` is the give-gold packet. There is no subtype byte. The amount is an unsigned 32-bit quantity serialized big-endian in bytes `1..4`; the local byte after the amount is scratch/termination hygiene and is not included in the sent length.
- Raw constructor policy: [UID:0001MI][0x005b52b0-0x005b52f0.GiveGoldInputPaneRawConstructor](by-memory/0x005b52b0-0x005b52f0.GiveGoldInputPaneRawConstructor.md) is class-identifying source-shaped code and now carries formal first-draft `GiveGoldInputPane::GiveGoldInputPane()` C++ through this class route. Current evidence still shows no direct start route, so `0x005b52b0` should not be used as an IDA callgraph anchor; the no-route result is a confidence cap, not a constructor C++ blocker. The live [UID:00005U][GiveInputPane](by-class/GiveInputPane.md) creator branch remains supporting mirror evidence and does not transfer ownership to `GiveInputPane`.
- Raw helper policy: [UID:0003MW][0x005b5390-0x005b53f9.SendGiveGoldPacketRaw](by-memory/0x005b5390-0x005b53f9.SendGiveGoldPacketRaw.md) is best source-facing `SendGiveGoldPacket(unsigned int amount)`, but remains no-code/no-route until a caller/source route is found or retained no-route helper bodies are intentionally emitted project-wide.

## C++ Readiness And No-Code Proof

Formal output on this class page is now the accepted comment-only no-standalone marker; constructor and submit/helper source remain routed through the exact child/range pages.

- Class pages should not absorb full method bodies. The constructor body is now emitted by exact child [UID:0001MI][0x005b52b0-0x005b52f0.GiveGoldInputPaneRawConstructor](by-memory/0x005b52b0-0x005b52f0.GiveGoldInputPaneRawConstructor.md); the live submit body `0x005b52f0-0x005b538a` still lacks an exact by-memory child, so there is no proper method-body owner for submit-method C++.
- The class page can eventually emit declarations, but `ItemActionInputPanes.cpp` still needs coordinated class declaration strategy across the adjacent drop/give prompt classes and base virtual names.
- The raw constructor's zero-route evidence is retained as an audit caveat and confidence cap after B005, not as a reason to keep [UID:0001MI][0x005b52b0-0x005b52f0.GiveGoldInputPaneRawConstructor](by-memory/0x005b52b0-0x005b52f0.GiveGoldInputPaneRawConstructor.md)'s formal C++ blank. The adjacent raw helper [UID:0003MW][0x005b5390-0x005b53f9.SendGiveGoldPacketRaw](by-memory/0x005b5390-0x005b53f9.SendGiveGoldPacketRaw.md) remains no-code/no-route until a caller/source route appears or retained no-route packet helpers are intentionally emitted project-wide.
- The generated simulator file contains stale/generated names and should not be copied into source reconstruction.

Review-only future method body for a dedicated `0x005b52f0-0x005b538a.GiveGoldInputPaneSubmitGoldAmount` child:

```cpp
void GiveGoldInputPane::OnSubmitGoldAmount()
{
    wchar_t text[16];
    unsigned int amount;
    unsigned char packet[6];

    if (LineInputPane::CopyText(text, 15) <= 0)
        return;

    amount = 0;
    WideStringScanf(text, L"%u", &amount);

    if (g_pUserPane->m_itemCommandBusy != 0)
        return;

    PacketBufferWriteUInt8(0x2a, packet);
    PacketBufferWriteUInt32BE(amount, packet + 1);
    packet[5] = 0;
    QueueAndSendPacket(g_packetSender, packet, 5);
}
```

Constructor source now lives on [UID:0001MI][0x005b52b0-0x005b52f0.GiveGoldInputPaneRawConstructor](by-memory/0x005b52b0-0x005b52f0.GiveGoldInputPaneRawConstructor.md), using literal prompt id `0x2b` with `g_pLanguageMan->GetLocalizedString`. Inferred names such as `kGiveGoldPromptStringId` / `LANG_PROMPT_GIVE_GOLD_AMOUNT` remain prose-only until a language-table enum/source spelling is recovered.

## Assignment Gate

- Assignment decision: assigned to [UID:0000KC][ItemActionInputPanes](by-file/ItemActionInputPanes.md).
- Child gate: `87/89` after B015 source-quality incorporation; the class now has exact constructor, submit, vtable, packet-format, prompt id, busy-gate, packet sender, raw helper, current helper/global names, rejected alternatives, and creator-relationship evidence.
- Parent gate: [UID:0000KC][ItemActionInputPanes](by-file/ItemActionInputPanes.md) is `90/85`.
- Remaining cap: IDA still does not model the raw constructor start as a function, direct raw constructor/helper reachability remains absent, the submit body still needs an exact child page before method C++ is emitted, and final base virtual/declaration names remain below final audit.

## Cross-References

- [UID:0000KC][ItemActionInputPanes](by-file/ItemActionInputPanes.md)
- [UID:0001XU][ItemActionInputPaneVtableFamily](by-type/by-vtable/ItemActionInputPaneVtableFamily.md)
- [UID:0001MI][0x005b52b0-0x005b52f0.GiveGoldInputPaneRawConstructor](by-memory/0x005b52b0-0x005b52f0.GiveGoldInputPaneRawConstructor.md)
- [UID:0001MG][0x005b44b0-0x005b538a.DropGiveInputPanes](by-memory/0x005b44b0-0x005b538a.DropGiveInputPanes.md)
- [UID:0003FO][0x005b5230-0x005b52ac.SendGiveItemPacketRaw](by-memory/0x005b5230-0x005b52ac.SendGiveItemPacketRaw.md)
- [UID:0003MW][0x005b5390-0x005b53f9.SendGiveGoldPacketRaw](by-memory/0x005b5390-0x005b53f9.SendGiveGoldPacketRaw.md)
- [UID:00005U][GiveInputPane](by-class/GiveInputPane.md)
- [UID:0000QK][g_pCollectionData](by-global/g_pCollectionData.md)
- [UID:0000Q5][g_packetSender](by-global/g_packetSender.md)
- [UID:0003YJ][0x00575380-0x00575470.PacketBufferScalarBigEndianWriteHelpers](by-memory/0x00575380-0x00575470.PacketBufferScalarBigEndianWriteHelpers.md)
- [UID:0001HU][0x00574bb0-0x00574c13.QueueAndSendPacket](by-memory/0x00574bb0-0x00574c13.QueueAndSendPacket.md)

## B005 2026-06-30 Empty-Emitter Callback

- Formal output: the `RECONSTRUCTION_CPP CODE` block emits the accepted no-standalone marker plus `[[CHILDREN]]` so exact routed children can assemble under this route. The constructor has an exact source child, while submit/helper evidence remains routed through the Drop/Give split family.
- Route proof: exact retained constructor source is [UID:0001MI][0x005b52b0-0x005b52f0.GiveGoldInputPaneRawConstructor](by-memory/0x005b52b0-0x005b52f0.GiveGoldInputPaneRawConstructor.md); live submit evidence is `0x005b52f0-0x005b538a` inside [UID:0001MG][0x005b44b0-0x005b538a.DropGiveInputPanes](by-memory/0x005b44b0-0x005b538a.DropGiveInputPanes.md); adjacent retained helper evidence is [UID:0003MW][0x005b5390-0x005b53f9.SendGiveGoldPacketRaw](by-memory/0x005b5390-0x005b53f9.SendGiveGoldPacketRaw.md). [UID:0001XU][ItemActionInputPaneVtableFamily](by-type/by-vtable/ItemActionInputPaneVtableFamily.md) records primary slot `0x00630090 -> 0x005b52f0`.
- Rejected emission: [UID:0003MW][0x005b5390-0x005b53f9.SendGiveGoldPacketRaw](by-memory/0x005b5390-0x005b53f9.SendGiveGoldPacketRaw.md) stays no-code because the submit method emits equivalent packet logic inline; this class page should not duplicate the exact constructor child or synthesize an un-split submit declaration.

## Changes

- 2026-06-25 B005 GiveGold raw-constructor source-quality implementation:
  - Score unchanged at `87/89`; class formal C++ remains blank pending declaration/method-body strategy.
  - Updated [UID:0001MI][0x005b52b0-0x005b52f0.GiveGoldInputPaneRawConstructor](by-memory/0x005b52b0-0x005b52f0.GiveGoldInputPaneRawConstructor.md) notes to record that the exact child now emits first-draft `GiveGoldInputPane::GiveGoldInputPane()` C++ through this class route, using `g_pLanguageMan->GetLocalizedString(0x2b)` and `NumberInputPane` base construction while preserving no-function/no-start-xref/no-pointer evidence as confidence caps.
  - Evidence: current MCP session `80de0a67` reconfirmed exact constructor bytes, `0x005b52ac-0x005b52b0` padding, vtable stores `0x00630048/0x00630098/0x006300c8`, matching [UID:00005U][GiveInputPane](by-class/GiveInputPane.md) inline construction, and the live submit route `0x00630090 -> 0x005b52f0`.
- 2026-06-22 B015 Rule 26 source-quality incorporation:
  - Before: `85/86`, with stale cash-shop/broad busy-state wording, older generated-name caveats, and no exact raw helper/source-quality direction.
  - Changed to: `87/89`; owner/emitter remain [UID:0000KC][ItemActionInputPanes](by-file/ItemActionInputPanes.md), and class C++ remains blank pending declaration/submit-child strategy. B015's constructor-child no-code direction is superseded by the 2026-06-25 B005 implementation above.
  - Evidence: B015 raw PE recheck confirmed exact boundaries/padding, zero pointer hits to `0x005b52b0`, one vtable pointer route to `0x005b52f0` through `0x00630090`, zero pointer hits to raw helper `0x005b5390`, live inline construction in [UID:00005U][GiveInputPane](by-class/GiveInputPane.md), prompt id `0x2b`, `NumberInputPane` base construction, `g_pUserPane +0x3ec0` / `m_itemCommandBusy`, PacketBuffer writer names, Socket-owned `g_packetSender` / `QueueAndSendPacket`, packet layout `[0x2a, amount:u32be]`, and rejected owner/name alternatives.
- Completion/confidence score update: existed before as `0/0`; changed to `72/78`. Summary: numeric give-gold behavior, packet format, busy gate, raw constructor bytes, vtable identity, and creation path are documented; confidence remains capped by raw-constructor reachability/modeling. Evidence: raw constructor page `0x005b52b0-0x005b52f0`, aggregate Drop/Give input page, IDA decompilation of `0x005b52f0`, and `g_pCollectionData`/`g_packetSender` cross-references.
- 2026-06-02 metadata/evidence refresh:
  - Before: page metadata left `RECONSTRUCTABLE` and `AUTOGEN_PARENT_UID` blank.
  - After: raised to `80/84`, marked reconstructable, and attached to [UID:0000KC][ItemActionInputPanes](by-file/ItemActionInputPanes.md).
  - Evidence: [UID:0001MI][0x005b52b0-0x005b52f0.GiveGoldInputPaneRawConstructor](by-memory/0x005b52b0-0x005b52f0.GiveGoldInputPaneRawConstructor.md) and [UID:0001MG][0x005b44b0-0x005b538a.DropGiveInputPanes](by-memory/0x005b44b0-0x005b538a.DropGiveInputPanes.md) now record refreshed constructor, submit, vtable, packet, and item-action ownership evidence.
- 2026-06-12 A005 Batch253:
  - Before: `80/84`, below the strict child side despite already carrying `AUTOGEN_PARENT_UID:0000KC`.
  - Changed to: `85/86`; parent remains [UID:0000KC][ItemActionInputPanes](by-file/ItemActionInputPanes.md).
  - Evidence: Batch253 raised [UID:0001MI][0x005b52b0-0x005b52f0.GiveGoldInputPaneRawConstructor](by-memory/0x005b52b0-0x005b52f0.GiveGoldInputPaneRawConstructor.md) to `85/88` and recorded exact no-function/no-xref/no-pointer, packet, vtable, prompt, and padding evidence.
