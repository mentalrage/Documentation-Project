*** UID:000043 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:87 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000KC | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000KC | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
// No standalone class-page emission for DropGoldInputPane; constructor source is [UID:0001MH][0x005b4b70-0x005b4bb0.DropGoldInputPaneRawConstructor](by-memory/0x005b4b70-0x005b4bb0.DropGoldInputPaneRawConstructor.md) and submit/helper evidence is documented by [UID:0001MG][0x005b44b0-0x005b538a.DropGiveInputPanes](by-memory/0x005b44b0-0x005b538a.DropGiveInputPanes.md).
[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# DropGoldInputPane

## Status

- Confidence: strong for class identity, submit behavior, raw constructor bytes, vtable identity, packet behavior, exact neighboring raw packet helper split, and item-action module placement; the raw constructor itself remains retained/no-route because IDA does not model `0x005b4b70` as a function and no direct xref targets that start.
- Likely source file: [UID:0000KC][ItemActionInputPanes](by-file/ItemActionInputPanes.md)
- Address ranges: raw constructor [UID:0001MH][0x005b4b70-0x005b4bb0.DropGoldInputPaneRawConstructor](by-memory/0x005b4b70-0x005b4bb0.DropGoldInputPaneRawConstructor.md), aggregate methods [UID:0001MG][0x005b44b0-0x005b538a.DropGiveInputPanes](by-memory/0x005b44b0-0x005b538a.DropGiveInputPanes.md)
- Current recovered file: `source-3/simroot_v2/class_DropGoldInputPane.cpp`; this is treated as a migration artifact. Preferred source placement remains [UID:0000KC][ItemActionInputPanes](by-file/ItemActionInputPanes.md) / `ui/dialogs/ItemActionInputPanes.cpp`.

## Class Purpose

`DropGoldInputPane` is the numeric prompt used after the drop command selects gold. It parses a decimal amount and sends a five-byte drop-gold packet if the local-player/UserPane item-command busy gate is clear.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| `DropGoldInputPane::DropGoldInputPane()` | `0x005b4b70-0x005b4bb0` | Retained raw constructor-shaped body with formal first-draft C++ on [UID:0001MH][0x005b4b70-0x005b4bb0.DropGoldInputPaneRawConstructor](by-memory/0x005b4b70-0x005b4bb0.DropGoldInputPaneRawConstructor.md); IDA does not recognize this as a function start, but the live gold branch in [UID:000044][DropInputPane](by-class/DropInputPane.md) mirrors the same `NumberInputPane` construction, prompt id `7`, and vtable triad. |
| `DropGoldInputPane::OnSubmit()` | `0x005b4bb0-0x005b4c4a` | Reads numeric text, parses `%u`, gates on player/client-state busy byte `+0x3ec0`, writes opcode `0x24`, writes amount big-endian, and queues packet length `5`. `OnSubmitGoldAmount` is a descriptive recovered alias, not the preferred source-facing method spelling. |
| `static SendDropGoldPacket(unsigned int amount)` | `0x005b4c50-0x005b4cb9` | [UID:0003FM][0x005b4c50-0x005b4cb9.SendDropGoldPacketRaw](by-memory/0x005b4c50-0x005b4cb9.SendDropGoldPacketRaw.md) records the adjacent no-`this` retained raw helper for the same drop-gold packet format. The submit body duplicates/inlines the packet construction; there is no direct binary call from `0x005b4bb0` to `0x005b4c50`. |

## Evidence Notes

- IDA MCP confirms `0x005b4bb0` but reports no function at `0x005b4b70`; `xrefs_to 0x005b4b70` and pointer-pattern checks are empty, so the raw constructor must not be described as directly called.
- 2026-05-27 raw IDA disassembly confirms the constructor-shaped bytes at `0x005b4b70-0x005b4bb0`: localized prompt id `7`, `NumberInputPane` base construction, and vtable stores to `0x0062fea4`, `0x0062fef4`, and `0x0062ff24`.
- The live reachability evidence is the [UID:000044][DropInputPane](by-class/DropInputPane.md) gold shortcut branch at `0x005b4a9a-0x005b4abf`, which calls the language lookup with id `7`, invokes `NumberInputPane`, and stores the same `0x0062fea4`/`0x0062fef4`/`0x0062ff24` vtables inline. Best model: source-real class with a retained out-of-line constructor body plus a live inline construction sequence.
- 2026-06-25 B007 rechecked [UID:0001MH][0x005b4b70-0x005b4bb0.DropGoldInputPaneRawConstructor](by-memory/0x005b4b70-0x005b4bb0.DropGoldInputPaneRawConstructor.md) with current MCP session `80de0a67`: exact `0x40` / 64-byte raw constructor body (Verified with int_convert.py), no modeled function, expected decompile failure, no raw-start xrefs, zero VA/RVA pointer hits, zero PE rel32 call/jump routes, prompt id `7`, `NumberInputPane` base construction, and the same three vptr stores. B007 also decoded the current STR.RES record for id `7` as `How much do you want to drop, and no longer own?`, which supports the prompt role while preserving the source-facing language lookup.
- 2026-05-27 IDA decompilation of `0x005b4bb0` confirms the packet path uses [UID:0000QK][g_pCollectionData](by-global/g_pCollectionData.md) / historical `dword_67A748` byte `+0x3ec0` as a local-player/UserPane item-command busy gate and queues `[0x24, amount:u32be]` through [UID:0000Q5][g_packetSender](by-global/g_packetSender.md). The local zero byte written after the five sent bytes is scratch/termination hygiene, not part of the sent packet length.
- This class is created from [UID:000044][DropInputPane](by-class/DropInputPane.md) when the input character is backslash (`0x5c`), slash (`0x2f`), or dollar (`0x24`).
- 2026-06-12 A005 Batch253 split the adjacent raw packet body [UID:0003FM][0x005b4c50-0x005b4cb9.SendDropGoldPacketRaw](by-memory/0x005b4c50-0x005b4cb9.SendDropGoldPacketRaw.md), verified it as a no-function/no-xref/no-pointer `0x69` / 105-byte body (Verified with int_convert.py), and reconfirmed [UID:0001MH][0x005b4b70-0x005b4bb0.DropGoldInputPaneRawConstructor](by-memory/0x005b4b70-0x005b4bb0.DropGoldInputPaneRawConstructor.md) as a `0x40` / 64-byte raw constructor (Verified with int_convert.py).

## Source Quality / Inference Notes

- Owner/emitter stays [UID:0000KC][ItemActionInputPanes](by-file/ItemActionInputPanes.md). Rejected owners: [UID:00009L][NumberInputPane](by-class/NumberInputPane.md) only owns reusable numeric input behavior; [UID:000044][DropInputPane](by-class/DropInputPane.md) creates this prompt but does not own the distinct class/vtables; [UID:0000QK][g_pCollectionData](by-global/g_pCollectionData.md), `UserPane`, `Socket`, and [UID:0000Q5][g_packetSender](by-global/g_packetSender.md) provide state or transport, not this prompt class.
- The primary vtable action slot at `+0x48` points to `0x005b4bb0`; sibling [UID:00005T][GiveGoldInputPane](by-class/GiveGoldInputPane.md) and [UID:000044][DropInputPane](by-class/DropInputPane.md) support `OnSubmit` as the preferred source-facing method name. `OnSubmitGoldAmount` remains useful only as a descriptive alias or split filename.
- Prompt id `7` is now resource-backed as the drop-gold amount prompt. Keep source as a language-manager lookup, not an English literal. Descriptive constants such as `kPromptDropGoldAmount` or `IDS_DROP_GOLD_AMOUNT` remain possible future enum names, but no original source spelling is recovered.
- The busy field at `g_pUserPane + 0x3ec0` / stable alias `g_pCollectionData + 0x3ec0` is best described as `m_itemCommandBusy` / item-command busy gate. Avoid `m_cashShopBusy` here because observed users include drop/give gold and direct item-action sends.
- `0x004f2300`, `0x004944f0`, `0x00575380`, and `0x005753f0` have clear roles (input text extraction, `%u` parse, packet byte write, and amount encoding), but their final source names belong to support-owner passes.
- Class-page formal output is now an accepted comment-only no-standalone marker because class declaration shape, submit-method child ownership, and adjacent helper policy belong to exact children/support pages. [UID:0001MH][0x005b4b70-0x005b4bb0.DropGoldInputPaneRawConstructor](by-memory/0x005b4b70-0x005b4bb0.DropGoldInputPaneRawConstructor.md) now carries the formal first-draft constructor C++; [UID:0003FM][0x005b4c50-0x005b4cb9.SendDropGoldPacketRaw](by-memory/0x005b4c50-0x005b4cb9.SendDropGoldPacketRaw.md) and a future exact child for `0x005b4bb0-0x005b4c4a` should own helper/submit C++ when ready. The raw constructor's no-route state is a confidence cap, not an old `95+` no-code rule.

## Assignment Gate

- Assignment decision: assigned to [UID:0000KC][ItemActionInputPanes](by-file/ItemActionInputPanes.md).
- Child gate: `87/88` after B001 Rule 26 incorporation; the class now has exact constructor, submit, vtable, packet-format, neighboring raw helper, prompt id, busy-gate, packet sender, creator-relationship, retained/no-route constructor, and live inline-construction evidence.
- Parent gate: [UID:0000KC][ItemActionInputPanes](by-file/ItemActionInputPanes.md) is `90/85`.
- Remaining cap: IDA still does not model the raw constructor start as a function, direct raw constructor reachability remains inferred from inline vtable-store mirrors, the submit body lacks an exact child page, and final base/virtual/helper names are not 95/95-ready.

## Cross-References

- [UID:0000KC][ItemActionInputPanes](by-file/ItemActionInputPanes.md)
- [UID:0001XU][ItemActionInputPaneVtableFamily](by-type/by-vtable/ItemActionInputPaneVtableFamily.md)
- [UID:0001MH][0x005b4b70-0x005b4bb0.DropGoldInputPaneRawConstructor](by-memory/0x005b4b70-0x005b4bb0.DropGoldInputPaneRawConstructor.md)
- [UID:0003FM][0x005b4c50-0x005b4cb9.SendDropGoldPacketRaw](by-memory/0x005b4c50-0x005b4cb9.SendDropGoldPacketRaw.md)
- [UID:0001MG][0x005b44b0-0x005b538a.DropGiveInputPanes](by-memory/0x005b44b0-0x005b538a.DropGiveInputPanes.md)
- [UID:000044][DropInputPane](by-class/DropInputPane.md)
- [UID:0000QK][g_pCollectionData](by-global/g_pCollectionData.md)
- [UID:0000Q5][g_packetSender](by-global/g_packetSender.md)

## B005 2026-06-30 Empty-Emitter Callback

- Formal output: the `RECONSTRUCTION_CPP CODE` block emits the accepted no-standalone marker plus `[[CHILDREN]]` so exact routed children can assemble under this route. The constructor already has an exact child, while submit/helper evidence remains routed through the Drop/Give split family.
- Route proof: exact retained constructor source is [UID:0001MH][0x005b4b70-0x005b4bb0.DropGoldInputPaneRawConstructor](by-memory/0x005b4b70-0x005b4bb0.DropGoldInputPaneRawConstructor.md); live submit method evidence is `0x005b4bb0-0x005b4c4a` inside [UID:0001MG][0x005b44b0-0x005b538a.DropGiveInputPanes](by-memory/0x005b44b0-0x005b538a.DropGiveInputPanes.md); retained packet helper evidence is [UID:0003FM][0x005b4c50-0x005b4cb9.SendDropGoldPacketRaw](by-memory/0x005b4c50-0x005b4cb9.SendDropGoldPacketRaw.md). [UID:0001XU][ItemActionInputPaneVtableFamily](by-type/by-vtable/ItemActionInputPaneVtableFamily.md) records `DropGoldInputPane::OnSubmit()` at the primary `+0x48` slot.
- Rejected emission: this class page should not duplicate the exact constructor child or create a whole class declaration before the submit child is split out of [UID:0001MG][0x005b44b0-0x005b538a.DropGiveInputPanes](by-memory/0x005b44b0-0x005b538a.DropGiveInputPanes.md).

## Changes

- 2026-06-22 Rule 26 support sync from B001 [UID:0001OR][0x0067a748-0x0067a74c.g_pCollectionData](by-memory/0x0067a748-0x0067a74c.g_pCollectionData.md):
  - Updated the item-command busy gate to source-facing `g_pUserPane + 0x3ec0`; `g_pCollectionData` remains the stable alias path.
- 2026-05-30:
  - Before: completion/confidence metadata was left at unevaluated `0/0`.
  - After: scored as `72/78`.
  - Summary/evidence: numeric prompt role, raw constructor bytes, submit method, busy gate, packet encoding, vtable identity, and creator relationship are documented; confidence stays below the other drop panes because constructor reachability/modeling remains raw.
- 2026-06-02 metadata/evidence refresh:
  - Before: page metadata left `RECONSTRUCTABLE` and `AUTOGEN_PARENT_UID` blank.
  - After: raised to `80/84`, marked reconstructable, and attached to [UID:0000KC][ItemActionInputPanes](by-file/ItemActionInputPanes.md).
  - Evidence: [UID:0001MH][0x005b4b70-0x005b4bb0.DropGoldInputPaneRawConstructor](by-memory/0x005b4b70-0x005b4bb0.DropGoldInputPaneRawConstructor.md) and [UID:0001MG][0x005b44b0-0x005b538a.DropGiveInputPanes](by-memory/0x005b44b0-0x005b538a.DropGiveInputPanes.md) now record refreshed constructor, submit, vtable, packet, and item-action ownership evidence.
- 2026-06-12 A005 Batch253:
  - Before: `80/84`, below the strict child side despite already carrying `AUTOGEN_PARENT_UID:0000KC`.
  - Changed to: `85/86`; parent remains [UID:0000KC][ItemActionInputPanes](by-file/ItemActionInputPanes.md).
  - Evidence: Batch253 split [UID:0003FM][0x005b4c50-0x005b4cb9.SendDropGoldPacketRaw](by-memory/0x005b4c50-0x005b4cb9.SendDropGoldPacketRaw.md), raised [UID:0001MH][0x005b4b70-0x005b4bb0.DropGoldInputPaneRawConstructor](by-memory/0x005b4b70-0x005b4bb0.DropGoldInputPaneRawConstructor.md) to `85/88`, and recorded exact no-function/no-xref/no-pointer, packet, vtable, prompt, and padding evidence.
- 2026-06-20 B001 Rule 26 incorporation:
  - Before: `85/86` and still used stale cash-shop/broad raw-reachability wording.
  - Changed to: `87/88`; owner/emitter remains [UID:0000KC][ItemActionInputPanes](by-file/ItemActionInputPanes.md), and class C++ remains blank.
  - Evidence: B001 revalidated the raw constructor, live inline construction mirror at `0x005b4a9a-0x005b4abf`, primary submit slot, adjacent no-route helper, prompt id `7`, `%u` parse, item-command busy gate, packet shape `[0x24, amount:u32be]`, rejected owner alternatives, and no-class-page-C++ rationale.
- 2026-06-25 B007 DropGold raw-constructor implementation:
  - Score unchanged at `87/88`; class C++ remains blank.
  - Updated constructor status to reflect [UID:0001MH][0x005b4b70-0x005b4bb0.DropGoldInputPaneRawConstructor](by-memory/0x005b4b70-0x005b4bb0.DropGoldInputPaneRawConstructor.md) now emitting formal first-draft `DropGoldInputPane::DropGoldInputPane()` C++ through this class route, while no-function/no-route evidence remains a raw-body/callgraph caveat.
  - Evidence: current MCP session `80de0a67`, exact raw bytes, prompt id `7` and STR.RES text, `NumberInputPane` base construction, vptr stores, live [UID:000044][DropInputPane](by-class/DropInputPane.md) inline construction mirror, no direct raw-start xrefs, no VA/RVA pointer hits, and no PE rel32 route to `0x005b4b70`.
