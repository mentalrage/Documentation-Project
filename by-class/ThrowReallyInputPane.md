*** UID:0000EZ | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:87 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:89 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000KC | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000KC | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
// No standalone class-page emission for ThrowReallyInputPane; constructor and confirmed-send helper source is routed by [UID:0001MM][0x005b5b30-0x005b5b7e.ThrowReallyInputPaneRawConstructor](by-memory/0x005b5b30-0x005b5b7e.ThrowReallyInputPaneRawConstructor.md) and [UID:0003NY][0x005b5c20-0x005b5c93.SendThrowConfirmedItemPacketRaw](by-memory/0x005b5c20-0x005b5c93.SendThrowConfirmedItemPacketRaw.md).
[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# ThrowReallyInputPane

## Status

- Confidence: strong for accept behavior, exact raw constructor bytes, inferred `m_itemSlot` layout, vtable identity, inline construction mirrors, formal first-draft constructor C++ readiness, source-ready retained helper C++ on [UID:0003NY][0x005b5c20-0x005b5c93.SendThrowConfirmedItemPacketRaw](by-memory/0x005b5c20-0x005b5c93.SendThrowConfirmedItemPacketRaw.md), and item-action module placement; medium-high for raw-constructor/helper reachability because IDA still has no function object, direct start xref, pointer route, or PE rel32 route for the retained raw starts.
- Likely source file: [UID:0000KC][ItemActionInputPanes](by-file/ItemActionInputPanes.md)
- Address ranges: [UID:0001MM][0x005b5b30-0x005b5b7e.ThrowReallyInputPaneRawConstructor](by-memory/0x005b5b30-0x005b5b7e.ThrowReallyInputPaneRawConstructor.md), [UID:0001ML][0x005b5890-0x005b60c0.ThrowUseEatInputPanes](by-memory/0x005b5890-0x005b60c0.ThrowUseEatInputPanes.md)
- Generated-source leads are not used as authority for this page; the current score is based on IDA MCP and existing project-documentation evidence.
- Reconstruction routing: [UID:0001ML][0x005b5890-0x005b60c0.ThrowUseEatInputPanes](by-memory/0x005b5890-0x005b60c0.ThrowUseEatInputPanes.md) is a non-emitting range inventory, so it is not this class's C++ blocker. Future class source work should stay on this class or exact method/raw children.

## Class Purpose

`ThrowReallyInputPane` is the confirmation prompt for destructive throw/discard behavior. It asks for an affirmative input before sending the throw packet for the stored item slot.

## Class State

| Field | Offset | Type | Evidence and role |
| --- | --- | --- | --- |
| `m_itemSlot` | `+0x108` | `unsigned char` | Source-facing inferred field name for the constructor argument stored by [UID:0001MM][0x005b5b30-0x005b5b7e.ThrowReallyInputPaneRawConstructor](by-memory/0x005b5b30-0x005b5b7e.ThrowReallyInputPaneRawConstructor.md). B006 MCP session `80de0a67` confirms the raw constructor writes `[esi+0x108]`, the inline construction mirrors at `0x005a7b70-0x005a7ba5` and `0x005abacd-0x005abb08` write the same byte, and `ThrowReallyInputPane::OnAccept` at `0x005b5b80` reads `[esi+0x108]`. B007 current MCP session `agent_b009_0002my_20260628` confirms retained helper [UID:0003NY][0x005b5c20-0x005b5c93.SendThrowConfirmedItemPacketRaw](by-memory/0x005b5c20-0x005b5c93.SendThrowConfirmedItemPacketRaw.md) also reads `[esi+0x108]` / `m_itemSlot` for opcode `0x17`, mode `1`, local-only terminator, and send length `3`. The exact original member spelling is inferred, but item-slot role, offset, lifetime, and packet use are confirmed. |

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| `ThrowReallyInputPane` | `0x005b5b30-0x005b5b7e` | Raw constructor-shaped bytes; [UID:0001MM][0x005b5b30-0x005b5b7e.ThrowReallyInputPaneRawConstructor](by-memory/0x005b5b30-0x005b5b7e.ThrowReallyInputPaneRawConstructor.md) now has formal first-draft constructor C++ as `ThrowReallyInputPane::ThrowReallyInputPane(unsigned char itemSlot)`, using prompt id `0xa5`, `CharInputPane` base construction, inferred `m_itemSlot` at `+0x108`, and compiler-generated vtable installation. |
| `OnAccept` | `0x005b5b80-0x005b5c20` | Reads confirmation input and sends opcode `0x17` for the stored slot. |
| `SendThrowConfirmedItemPacket` | `0x005b5c20-0x005b5c93` | Retained thiscall raw helper; [UID:0003NY][0x005b5c20-0x005b5c93.SendThrowConfirmedItemPacketRaw](by-memory/0x005b5c20-0x005b5c93.SendThrowConfirmedItemPacketRaw.md) now emits formal first-draft `void ThrowReallyInputPane::SendThrowConfirmedItemPacket()` C++. It writes opcode `0x17`, mode `1`, and stored `m_itemSlot` at `this+0x108`, clears a local-only trailing byte, and sends length `3` through `g_packetSender->QueueAndSendPacket`. It remains separate/no-route: current MCP, pointer, and PE rel32 scans find no caller/pointer to `0x005b5c20`, and `OnAccept` still inlines the same packet tail rather than calling this helper. |

## Evidence Notes

- 2026-06-13 A003 live IDA MCP database `a002_batch_clear_timer` confirms `0x005b5b80` as `sub_5B5B80`, size `0xa0` / 160 bytes (Verified with `int_convert.py`), but reports no function object at raw constructor start `0x005b5b30`.
- Raw IDA bytes at `0x005b5b30-0x005b5b7e` show prompt id `0xa5` / 165 (Verified with `int_convert.py`), [UID:00001P][CharInputPane](by-class/CharInputPane.md) base construction through `0x004f28a0`, vtables `0x00630278`, `0x006302c8`, and `0x006302f8`, and a stored slot byte at `this + 0x108`.
- The previous `0x005b5b30-0x005b5b80` child range included two trailing `0xcc` bytes; [UID:0001MM][0x005b5b30-0x005b5b7e.ThrowReallyInputPaneRawConstructor](by-memory/0x005b5b30-0x005b5b7e.ThrowReallyInputPaneRawConstructor.md) now documents the exact constructor body and records the `0x005b5b7e-0x005b5b80` padding follow-up for the shared by-memory ledgers.
- IDA xrefs confirm inline construction paths in `UserPane` command handling at `0x005a7b87/0x005a7b8d/0x005a7b97` and helper `0x005aba80` at `0x005abae5/0x005abaeb/0x005abaf5`; both store the same three vtables.
- IDA decompilation of `0x005aba80` allocates `0x10c` / 268 bytes (Verified with `int_convert.py`), resolves the same prompt id, calls `CharInputPane`, and copies the narrowed item slot to `+0x108`.
- IDA decompilation of `0x005b5b80` confirms accepting `y` or `Y`, then sending opcode `0x17`, mode byte `1`, and the stored slot through [UID:0000Q5][g_packetSender](by-global/g_packetSender.md).
- 2026-06-25 B010 source-quality implementation reclassifies [UID:0003NY][0x005b5c20-0x005b5c93.SendThrowConfirmedItemPacketRaw](by-memory/0x005b5c20-0x005b5c93.SendThrowConfirmedItemPacketRaw.md) as this class's retained raw packet helper because the body is thiscall-shaped and reads `this+0x108`.
- Direct-parent gate: this class now clears `86/88`, and child [UID:0001MM][0x005b5b30-0x005b5b7e.ThrowReallyInputPaneRawConstructor](by-memory/0x005b5b30-0x005b5b7e.ThrowReallyInputPaneRawConstructor.md) clears `88/90`, so retaining the child assignment to this direct class parent is justified.
- 2026-06-26 B006 source-quality implementation raises this class to `86/88` because [UID:0001MM][0x005b5b30-0x005b5b7e.ThrowReallyInputPaneRawConstructor](by-memory/0x005b5b30-0x005b5b7e.ThrowReallyInputPaneRawConstructor.md) now emits formal first-draft constructor C++ and the class field role is documented as inferred `m_itemSlot` at `+0x108`. Current MCP session `80de0a67` confirms no raw-start function object, no direct raw-start xrefs, no raw-start pointer hit, exact 78-byte constructor body, prompt id `0xa5`, `g_pLanguageMan->GetLocalizedString`, `CharInputPane` base construction, three `ThrowReallyInputPane` vtable stores, two inline construction mirrors, and accept/helper consumption of the stored slot for opcode `0x17`, mode `1`, length `3`. Those route negatives remain confidence caps, not constructor-C++ blockers.
- 2026-06-28 B007 source-quality implementation raises this class to `87/89` because retained helper [UID:0003NY][0x005b5c20-0x005b5c93.SendThrowConfirmedItemPacketRaw](by-memory/0x005b5c20-0x005b5c93.SendThrowConfirmedItemPacketRaw.md) now carries formal first-draft `ThrowReallyInputPane::SendThrowConfirmedItemPacket()` C++ on its exact page. Current MCP session `agent_b009_0002my_20260628` confirms no IDA function object at `0x005b5c20`, source-shaped prologue/security-cookie/local-buffer bytes, `PacketBufferWriteUInt8` writes for opcode `0x17`, mode `1`, and `m_itemSlot` at `this+0x108`, explicit `QueueAndSendPacket` length `3`, exact end `0x005b5c93`, and no xref/pointer/PE rel32 route to the helper start. The route-negative evidence remains a confidence cap and a warning not to rewrite `OnAccept`; the live accept handler at `0x005b5b80` still serializes the same packet inline and is vtable-routed from `0x006302c0`.

## Cross-References

- [UID:0000KC][ItemActionInputPanes](by-file/ItemActionInputPanes.md)
- [UID:0001XU][ItemActionInputPaneVtableFamily](by-type/by-vtable/ItemActionInputPaneVtableFamily.md)
- [UID:0001MM][0x005b5b30-0x005b5b7e.ThrowReallyInputPaneRawConstructor](by-memory/0x005b5b30-0x005b5b7e.ThrowReallyInputPaneRawConstructor.md)
- [UID:0003NY][0x005b5c20-0x005b5c93.SendThrowConfirmedItemPacketRaw](by-memory/0x005b5c20-0x005b5c93.SendThrowConfirmedItemPacketRaw.md)
- [UID:0001ML][0x005b5890-0x005b60c0.ThrowUseEatInputPanes](by-memory/0x005b5890-0x005b60c0.ThrowUseEatInputPanes.md)
- [UID:0000EY][ThrowInputPane](by-class/ThrowInputPane.md)
- [UID:0000Q5][g_packetSender](by-global/g_packetSender.md)

## B005 2026-06-30 Empty-Emitter Callback

- Formal output: the `RECONSTRUCTION_CPP CODE` block emits the accepted no-standalone marker plus `[[CHILDREN]]` so exact constructor/helper children assemble under this route. Constructor and confirmed-send helper source remain routed through exact child pages.
- Route proof: exact constructor source is [UID:0001MM][0x005b5b30-0x005b5b7e.ThrowReallyInputPaneRawConstructor](by-memory/0x005b5b30-0x005b5b7e.ThrowReallyInputPaneRawConstructor.md); accept handler evidence is `0x005b5b80-0x005b5c20` inside [UID:0001ML][0x005b5890-0x005b60c0.ThrowUseEatInputPanes](by-memory/0x005b5890-0x005b60c0.ThrowUseEatInputPanes.md); exact confirmed-send helper source is [UID:0003NY][0x005b5c20-0x005b5c93.SendThrowConfirmedItemPacketRaw](by-memory/0x005b5c20-0x005b5c93.SendThrowConfirmedItemPacketRaw.md). [UID:0001XU][ItemActionInputPaneVtableFamily](by-type/by-vtable/ItemActionInputPaneVtableFamily.md) records ThrowReally vtables and primary `+0x48 -> 0x005b5b80`.
- Rejected emission: the class page should not duplicate the constructor or helper child, and the accepted route preserves the no-xref/no-pointer retained-helper caveat on [UID:0003NY][0x005b5c20-0x005b5c93.SendThrowConfirmedItemPacketRaw](by-memory/0x005b5c20-0x005b5c93.SendThrowConfirmedItemPacketRaw.md).

## Changes

- 2026-05-30 completion/confidence scoring:
  - What existed before: `COMPLETION:0` and `CONFIDENCE:0`.
  - Changed to: `COMPLETION:82` and `CONFIDENCE:80`.
  - Summary/evidence: scored from the raw constructor/vtable evidence, stored slot layout, accept-body decompilation, packet send behavior, and documented caveat that the constructor bytes are not currently an IDA-defined function start.
- 2026-06-02 reconstructable metadata alignment:
  - Before: class coverage described this page as reconstructable, but page metadata left `RECONSTRUCTABLE` and `AUTOGEN_PARENT_UID` blank.
  - After: set `CONFIDENCE:84`, marked reconstructable, and attached to [UID:0000KC][ItemActionInputPanes](by-file/ItemActionInputPanes.md).
  - Evidence: [UID:0001MM][0x005b5b30-0x005b5b7e.ThrowReallyInputPaneRawConstructor](by-memory/0x005b5b30-0x005b5b7e.ThrowReallyInputPaneRawConstructor.md) and [UID:0001ML][0x005b5890-0x005b60c0.ThrowUseEatInputPanes](by-memory/0x005b5890-0x005b60c0.ThrowUseEatInputPanes.md) now record refreshed constructor, accept handler, vtable, packet, and item-action ownership evidence.
- 2026-06-13 A003 Goal 2 parent-gate repair:
  - Before: `82/84`; child [UID:0001MM][0x005b5b30-0x005b5b7e.ThrowReallyInputPaneRawConstructor](by-memory/0x005b5b30-0x005b5b7e.ThrowReallyInputPaneRawConstructor.md) could not satisfy the inherited strict gate while this direct parent stayed below `85/85`.
  - After: `85/87`, parent [UID:0000KC][ItemActionInputPanes](by-file/ItemActionInputPanes.md) retained, C++ remains blank.
  - Evidence: live IDA MCP database `a002_batch_clear_timer` reconfirmed the corrected raw constructor body `0x005b5b30-0x005b5b7e`, prompt id/base constructor/slot-store/vtable evidence, two inline construction mirrors, exact accept handler behavior at `0x005b5b80`, and the opcode `0x17` mode `1` packet path that consumes the constructor's stored slot.
- 2026-06-25 B010 Throw/Use/Eat aggregate source-quality sync:
  - Score unchanged at `85/87`.
  - Reclassified [UID:0003NY][0x005b5c20-0x005b5c93.SendThrowConfirmedItemPacketRaw](by-memory/0x005b5c20-0x005b5c93.SendThrowConfirmedItemPacketRaw.md) as this class's retained raw helper and updated routing language so [UID:0001ML][0x005b5890-0x005b60c0.ThrowUseEatInputPanes](by-memory/0x005b5890-0x005b60c0.ThrowUseEatInputPanes.md) is a non-emitting inventory, not a class C++ blocker.
  - Evidence: current IDA MCP session `80de0a67` verifies the helper's opcode `0x17`, mode `1`, `this+0x108` slot source, send length `3`, no direct xrefs, and class-private ownership caveat.
- 2026-06-26 B006 ThrowReally constructor source-quality implementation:
  - Before: `85/87`; the constructor row still treated [UID:0001MM][0x005b5b30-0x005b5b7e.ThrowReallyInputPaneRawConstructor](by-memory/0x005b5b30-0x005b5b7e.ThrowReallyInputPaneRawConstructor.md) as raw constructor-shaped bytes with no class field map.
  - After: `86/88`; added inferred `unsigned char m_itemSlot` at `+0x108`, updated the constructor row to record formal first-draft C++ readiness, and preserved [UID:0003NY][0x005b5c20-0x005b5c93.SendThrowConfirmedItemPacketRaw](by-memory/0x005b5c20-0x005b5c93.SendThrowConfirmedItemPacketRaw.md) as a separate class-owned retained helper pending its own helper-quality pass. The B006 blank-C++ conclusion for [UID:0003NY][0x005b5c20-0x005b5c93.SendThrowConfirmedItemPacketRaw](by-memory/0x005b5c20-0x005b5c93.SendThrowConfirmedItemPacketRaw.md) is superseded by the B007 implementation below.
  - Evidence: B006 MCP session `80de0a67` confirms exact `0x005b5b30-0x005b5b7e` retained constructor body, no modeled function at `0x005b5b30`, no raw-start xrefs or pointer hits, prompt id `0xa5`, `g_pLanguageMan->GetLocalizedString`, `CharInputPane` base construction, vtables `0x00630278`/`0x006302c8`/`0x006302f8`, inline construction mirrors at `0x005a7b70-0x005a7ba5` and `0x005abacd-0x005abb08`, and stored-slot consumption by `0x005b5b80` plus [UID:0003NY][0x005b5c20-0x005b5c93.SendThrowConfirmedItemPacketRaw](by-memory/0x005b5c20-0x005b5c93.SendThrowConfirmedItemPacketRaw.md) for opcode `0x17`, mode `1`, send length `3`.
- 2026-06-28 B007 SendThrowConfirmedItemPacket retained-helper implementation:
  - Before: `86/88`; [UID:0003NY][0x005b5c20-0x005b5c93.SendThrowConfirmedItemPacketRaw](by-memory/0x005b5c20-0x005b5c93.SendThrowConfirmedItemPacketRaw.md) was class-owned but still described as blank-C++/no-route.
  - After: `87/89`; [UID:0003NY][0x005b5c20-0x005b5c93.SendThrowConfirmedItemPacketRaw](by-memory/0x005b5c20-0x005b5c93.SendThrowConfirmedItemPacketRaw.md) now emits formal first-draft `void ThrowReallyInputPane::SendThrowConfirmedItemPacket()` C++, while the class page formal block stays blank pending a coordinated class-declaration pass.
  - Evidence: B007 current MCP session `agent_b009_0002my_20260628` and supplemental PE scan confirm source-shaped helper bytes, exact `0x005b5c20-0x005b5c93` boundary, packet layout `[0x17, 1, m_itemSlot]`, send length `3`, local-only terminator, `PacketBufferWriteUInt8`, `g_packetSender->QueueAndSendPacket`, no xrefs to helper start/end, no VA/RVA/end pointer hit, positive-control accept-handler pointer at `0x006302c0`, and no direct `E8`/`E9` rel32 route. Rejected alternatives remain covered-by marker, blank formal helper C++, merge into `OnAccept`, file-static direct ownership, and protocol/helper/global ownership.
