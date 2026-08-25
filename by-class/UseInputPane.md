*** UID:0000FG | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000KC | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000KC | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
// No standalone class-page emission for UseInputPane; live use dispatch remains [UID:0001KN][0x005a3e30-0x005a3ff3.UserPaneUseInventorySlot](by-memory/0x005a3e30-0x005a3ff3.UserPaneUseInventorySlot.md) and adjacent helper source is [UID:0003NZ][0x005b5e60-0x005b5ebe.SendUseItemSlotPacketRaw](by-memory/0x005b5e60-0x005b5ebe.SendUseItemSlotPacketRaw.md).
[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# UseInputPane

## B003 2026-07-20 Event Contract Synchronization

- The compact `0x005b5d70` help override is `bool HandleKeyOrTextEvent(Event *event)`: translate key/modifiers, require translated `?`, exact Shift `0x04`, and key-down, switch tab `2` with `NULL`, play effect `0x198` at 100, return true, otherwise use the existing base handler.
- Use construction, selected-slot/use packet behavior, children, vtable/compiler evidence, scores, route, formal block, and history remain unchanged. Stale `OnKeyInput`/`InputEvent`/`NarrowInputKey`/`false` wording is superseded only.

## Status

- Confidence: strong for behavior and item-action input module placement.
- Likely source file: [UID:0000KC][ItemActionInputPanes](by-file/ItemActionInputPanes.md)
- Address range: [UID:0001ML][0x005b5890-0x005b60c0.ThrowUseEatInputPanes](by-memory/0x005b5890-0x005b60c0.ThrowUseEatInputPanes.md)
- Historical recovered-source lead: `source-3/simroot_v2/class_UseInputPane.cpp` is an older generated/recovered migration artifact only. Current authority for this class and adjacent [UID:0003NZ][0x005b5e60-0x005b5ebe.SendUseItemSlotPacketRaw](by-memory/0x005b5e60-0x005b5ebe.SendUseItemSlotPacketRaw.md) routing is current IDA MCP evidence plus accepted by-* documentation, not the recovered file.
- Reconstruction routing: [UID:0001ML][0x005b5890-0x005b60c0.ThrowUseEatInputPanes](by-memory/0x005b5890-0x005b60c0.ThrowUseEatInputPanes.md) is a non-emitting range inventory, so it is not this class's C++ blocker. Future class source work should stay on this class or exact method/raw children.
- Adjacent retained helper routing: [UID:0003NZ][0x005b5e60-0x005b5ebe.SendUseItemSlotPacketRaw](by-memory/0x005b5e60-0x005b5ebe.SendUseItemSlotPacketRaw.md) is now source-ready as a formal first-draft static ItemAction helper `SendUseItemSlotPacket(char itemSlot)` on its exact child page. This does not populate this class page's C++ block and does not change the live `UseInputPane::OnSubmitInput` route through [UID:0001KN][0x005a3e30-0x005a3ff3.UserPaneUseInventorySlot](by-memory/0x005a3e30-0x005a3ff3.UserPaneUseInventorySlot.md).

## Class Purpose

`UseInputPane` is the item-use prompt. It accepts a single inventory slot letter and dispatches the use flow for that slot, which may lead into target-selection handling for usable items.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| `UseInputPane` | `0x005b5ca0-0x005b5d67` | Constructs the prompt with player name and installs vtables. |
| `OnCharInput` | `0x005b5d70-0x005b5ddc` | Handles help-panel shortcut and delegates normal input. |
| `OnSubmitInput` | `0x005b5de0-0x005b5e5c` | Converts slot letter and dispatches item-use slot handling. |

## Evidence Notes

- Historical Wave3 generated-source lead used the provisional `LivingObjectPane::UseSpellSlot` name for the selected-slot dispatch. Treat that output only as an old generated lead; current IDA MCP/by-* authority is that `UseInputPane::OnSubmitInput` calls [UID:0001KN][0x005a3e30-0x005a3ff3.UserPaneUseInventorySlot](by-memory/0x005a3e30-0x005a3ff3.UserPaneUseInventorySlot.md), and it is not authority for [UID:0003NZ][0x005b5e60-0x005b5ebe.SendUseItemSlotPacketRaw](by-memory/0x005b5e60-0x005b5ebe.SendUseItemSlotPacketRaw.md).
- IDA MCP confirms all three function starts.
- IDA MCP recheck on 2026-05-27 confirms the constructor uses prompt id `0x09`, calls `CharInputPane::CharInputPane`, gets the local player name from [UID:0000QK][g_pCollectionData](by-global/g_pCollectionData.md) / historical IDA alias `dword_67A748`, formats the prompt, and installs vtables `0x00630304`, `0x00630354`, and `0x00630384`.
- IDA decompilation of `0x005b5de0` confirms slot conversion: lowercase `a-z` becomes `1-26`, uppercase `A-Z` becomes `27-52`, and the accepted value is bounded by [UID:0000PS][g_activeUserStatusPane](by-global/g_activeUserStatusPane.md) offset `+0x284`.
- The submit path calls [UID:0001KN][0x005a3e30-0x005a3ff3.UserPaneUseInventorySlot](by-memory/0x005a3e30-0x005a3ff3.UserPaneUseInventorySlot.md) with [UID:0000QK][g_pCollectionData](by-global/g_pCollectionData.md) / historical IDA alias `dword_67A748` and the validated slot. Current generated name `LivingObjectPane::UseSpellSlot` remains provisional because macro docs tie this address to inventory/item-tab state.
- Targeted use flow should cross-reference [UID:00006X][ItemWhoInputPane](by-class/ItemWhoInputPane.md).
- 2026-06-25 B010 source-quality implementation confirms adjacent retained helper [UID:0003NZ][0x005b5e60-0x005b5ebe.SendUseItemSlotPacketRaw](by-memory/0x005b5e60-0x005b5ebe.SendUseItemSlotPacketRaw.md) sends opcode `0x1c`, selected slot byte, and length `2` with no direct caller proof; this does not replace the live `OnSubmitInput` call to [UID:0001KN][0x005a3e30-0x005a3ff3.UserPaneUseInventorySlot](by-memory/0x005a3e30-0x005a3ff3.UserPaneUseInventorySlot.md).
- 2026-06-29 B008 implementation upgrades the adjacent retained helper to formal first-draft C++ as static file helper `SendUseItemSlotPacket(char itemSlot)` on [UID:0003NZ][0x005b5e60-0x005b5ebe.SendUseItemSlotPacketRaw](by-memory/0x005b5e60-0x005b5ebe.SendUseItemSlotPacketRaw.md). Current MCP session `agent_b009_0002my_20260628` confirms no function/start-xref/pointer route to the helper, opcode `0x1c`, signed stack-slot byte, local terminator, send length `2`, and clean separation from both this class's live submit dispatch through [UID:0001KN][0x005a3e30-0x005a3ff3.UserPaneUseInventorySlot](by-memory/0x005a3e30-0x005a3ff3.UserPaneUseInventorySlot.md) and the `EatInputPane` opcode `0x1a` path. The class-level formal C++ block now emits only the accepted comment-only no-standalone marker outside a separate accepted UseInputPane method/class report.

## UID0001KN Submit-Route Synchronization

`UseInputPane::OnSubmitInput` calls [UID:0001KN][0x005a3e30-0x005a3ff3.UserPaneUseInventorySlot](by-memory/0x005a3e30-0x005a3ff3.UserPaneUseInventorySlot.md) at exact call site `0x005b5e51`. The submit path validates one ASCII letter and maps lowercase `a..z` to one-based slots `1..26` or uppercase `A..Z` to slots `27..52` before making the call through the active local-player/LivingObjectPane receiver.

The callee's source signature is `void LivingObjectPane::UseInventorySlot(unsigned char slot)`. On this machine path, incidental `AL` from the callee may reach the UseInputPane epilogue, but the submit path does not test, store, or otherwise consume a semantic callee result. UID0001KN's early/direct-send/final-setter exits carry incompatible residues, independently ruling out a return contract. Historical `UseSpellSlot` remains superseded generated naming; adjacent retained `SendUseItemSlotPacket` is not substituted for this live route.

## Cross-References

- [UID:0000KC][ItemActionInputPanes](by-file/ItemActionInputPanes.md)
- [UID:0001XU][ItemActionInputPaneVtableFamily](by-type/by-vtable/ItemActionInputPaneVtableFamily.md)
- [UID:0001ML][0x005b5890-0x005b60c0.ThrowUseEatInputPanes](by-memory/0x005b5890-0x005b60c0.ThrowUseEatInputPanes.md)
- [UID:0001KN][0x005a3e30-0x005a3ff3.UserPaneUseInventorySlot](by-memory/0x005a3e30-0x005a3ff3.UserPaneUseInventorySlot.md)
- [UID:0003NZ][0x005b5e60-0x005b5ebe.SendUseItemSlotPacketRaw](by-memory/0x005b5e60-0x005b5ebe.SendUseItemSlotPacketRaw.md)
- [UID:00006X][ItemWhoInputPane](by-class/ItemWhoInputPane.md)
- [UID:0000PS][g_activeUserStatusPane](by-global/g_activeUserStatusPane.md)
- [UID:0000QK][g_pCollectionData](by-global/g_pCollectionData.md)
- [UID:000047][EatInputPane](by-class/EatInputPane.md)

## B005 2026-06-30 Empty-Emitter Callback

- Formal output: the `RECONSTRUCTION_CPP CODE` block emits the accepted no-standalone marker plus `[[CHILDREN]]` so exact routed children can assemble under this route. Use method source stays split between the live dispatch route and the retained helper child.
- Route proof: [UID:0001ML][0x005b5890-0x005b60c0.ThrowUseEatInputPanes](by-memory/0x005b5890-0x005b60c0.ThrowUseEatInputPanes.md) covers Use constructor `0x005b5ca0-0x005b5d67`, key handler `0x005b5d70-0x005b5ddc`, and submit/dispatch path `0x005b5de0-0x005b5e5c`. The live use path calls [UID:0001KN][0x005a3e30-0x005a3ff3.UserPaneUseInventorySlot](by-memory/0x005a3e30-0x005a3ff3.UserPaneUseInventorySlot.md); retained helper source is [UID:0003NZ][0x005b5e60-0x005b5ebe.SendUseItemSlotPacketRaw](by-memory/0x005b5e60-0x005b5ebe.SendUseItemSlotPacketRaw.md). [UID:0001XU][ItemActionInputPaneVtableFamily](by-type/by-vtable/ItemActionInputPaneVtableFamily.md) records Use vtable slots.
- Rejected emission: the class page should not duplicate live dispatch or retained helper children, and [UID:0003NZ][0x005b5e60-0x005b5ebe.SendUseItemSlotPacketRaw](by-memory/0x005b5e60-0x005b5ebe.SendUseItemSlotPacketRaw.md) remains separate from Eat's opcode `0x1a` path.

## Changes

- 2026-07-13 B002 UID0001KN support synchronization:
  - Added exact live call site `0x005b5e51`, one-based letter-to-slot mapping, accepted `UseInventorySlot` name/signature, and proof that no semantic target return is consumed despite incidental `AL` epilogue propagation.
  - Preserved UseInputPane's `86/88` score, owner/emitter, comment-only class disposition, and separation from retained `SendUseItemSlotPacket`; no class formal method body was added.
- 2026-06-29 B008 stale Wave3/recovered-source correction:
  - Score unchanged at `86/88`; historicalized the `source-3/simroot_v2/class_UseInputPane.cpp` recovered-file line and the Wave3 `LivingObjectPane::UseSpellSlot` evidence line so they are old generated/migration leads only, not current authority.
  - Current authority remains IDA MCP/by-* evidence: the live `UseInputPane::OnSubmitInput` route calls [UID:0001KN][0x005a3e30-0x005a3ff3.UserPaneUseInventorySlot](by-memory/0x005a3e30-0x005a3ff3.UserPaneUseInventorySlot.md), and adjacent [UID:0003NZ][0x005b5e60-0x005b5ebe.SendUseItemSlotPacketRaw](by-memory/0x005b5e60-0x005b5ebe.SendUseItemSlotPacketRaw.md) emits only on its exact child page as `SendUseItemSlotPacket(char itemSlot)`.
- 2026-06-07 A008 alias cleanup:
  - Before: constructor and submit evidence used bare `dword_67A748` wording for the local-player/client-state pointer.
  - Changed to: canonical [UID:0000QK][g_pCollectionData](by-global/g_pCollectionData.md) wording while preserving `dword_67A748` as the historical IDA alias.
  - Evidence: the global page records `0x0067a748` as a broad player/client-state pointer, including item-command prompt and use-dispatch views.
- Before: reconstruction autogen metadata was unclassified.
- Changed to: marked `RECONSTRUCTABLE:TRUE` and attached to [UID:0000KC][ItemActionInputPanes](by-file/ItemActionInputPanes.md).
- Evidence: 2026-06-05 IDA MCP on `NexusTK.exe` (`md5 4247e04e20b65d6414c7238aa8ff5515`) confirmed the documented constructor, char-input handler, and submit handler starts at `0x005b5ca0`, `0x005b5d70`, and `0x005b5de0`; this page and parent [UID:0000KC][ItemActionInputPanes](by-file/ItemActionInputPanes.md) both met the then-current parent gate. No C++ was emitted in that pass; current routing treats [UID:0001ML][0x005b5890-0x005b60c0.ThrowUseEatInputPanes](by-memory/0x005b5890-0x005b60c0.ThrowUseEatInputPanes.md) as a no-code range inventory rather than this class's source blocker.
- 2026-06-25 B010 Throw/Use/Eat aggregate source-quality sync:
  - Score unchanged at `86/88`.
  - Updated routing language so [UID:0001ML][0x005b5890-0x005b60c0.ThrowUseEatInputPanes](by-memory/0x005b5890-0x005b60c0.ThrowUseEatInputPanes.md) is a non-emitting inventory, not a class C++ blocker, and added the adjacent [UID:0003NZ][0x005b5e60-0x005b5ebe.SendUseItemSlotPacketRaw](by-memory/0x005b5e60-0x005b5ebe.SendUseItemSlotPacketRaw.md) opcode `0x1c` caveat.
- 2026-06-29 B008 SendUseItemSlotPacket adjacent-helper sync:
  - Score unchanged at `86/88`; added that [UID:0003NZ][0x005b5e60-0x005b5ebe.SendUseItemSlotPacketRaw](by-memory/0x005b5e60-0x005b5ebe.SendUseItemSlotPacketRaw.md) now emits formal first-draft static helper `SendUseItemSlotPacket(char itemSlot)` on the exact child page while this class page remains blank-C++.
  - Evidence: B008 current MCP recheck confirms [UID:0003NZ][0x005b5e60-0x005b5ebe.SendUseItemSlotPacketRaw](by-memory/0x005b5e60-0x005b5ebe.SendUseItemSlotPacketRaw.md) is a retained no-route/no-pointer helper that sends opcode `0x1c` and a selected slot byte with length `2`; live `UseInputPane::OnSubmitInput` continues to call [UID:0001KN][0x005a3e30-0x005a3ff3.UserPaneUseInventorySlot](by-memory/0x005a3e30-0x005a3ff3.UserPaneUseInventorySlot.md), so the helper must not be inserted into this class method body without future route evidence.
- 2026-05-30 completion/confidence scoring:
  - What existed before: `COMPLETION:0` and `CONFIDENCE:0`.
  - Changed to: `COMPLETION:86` and `CONFIDENCE:88`.
  - Summary/evidence: scored from IDA-confirmed constructor/char/submit methods, prompt id, vtable stores, slot validation, inventory-use dispatch target, and item-action input grouping.
