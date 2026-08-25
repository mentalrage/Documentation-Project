*** UID:000044 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000KC | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000KC | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
// No standalone class-page emission for DropInputPane; exact Drop method bodies and gold-branch evidence are documented in [UID:0001MG][0x005b44b0-0x005b538a.DropGiveInputPanes](by-memory/0x005b44b0-0x005b538a.DropGiveInputPanes.md).
[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# DropInputPane

## B003 2026-07-20 Event Contract Synchronization

- The compact `0x005b48b0` help override is source-facing `bool HandleKeyOrTextEvent(Event *event)`: translate key/modifiers through `g_pEventMan`, require translated `?`, exact Shift `0x04`, and key-down, switch tab `2` with `NULL`, play effect `0x198` at 100, return true, and otherwise forward to the existing input-pane base.
- Drop slot/count parsing, confirmation, packets, constructors, children, vtable/compiler evidence, scores, route, formal block, and unrelated history remain unchanged. Historical `OnKeyInput`/`InputEvent`/`NarrowInputKey`/`false` vocabulary is superseded only.

## Status

- Confidence: strong for behavior and item-action input module placement.
- Likely source file: [UID:0000KC][ItemActionInputPanes](by-file/ItemActionInputPanes.md)
- Address range: [UID:0001MG][0x005b44b0-0x005b538a.DropGiveInputPanes](by-memory/0x005b44b0-0x005b538a.DropGiveInputPanes.md)
- Reconstruction note: class-level formal output is now an accepted comment-only no-standalone marker because declaration shape, submit-method child split, and helper/member naming belong to exact children/support passes. The inline gold branch now supports formal first-draft constructor C++ on [UID:0001MH][0x005b4b70-0x005b4bb0.DropGoldInputPaneRawConstructor](by-memory/0x005b4b70-0x005b4bb0.DropGoldInputPaneRawConstructor.md); the old `95/95` wording is not a first-draft code gate. [UID:0001MG][0x005b44b0-0x005b538a.DropGiveInputPanes](by-memory/0x005b44b0-0x005b538a.DropGiveInputPanes.md) now emits only the accepted split/index aggregate marker and must not be treated as a synthetic class/body source.

## Class Purpose

`DropInputPane` is the standard item-drop prompt. It accepts a single inventory slot letter, routes gold selection into `DropGoldInputPane`, and sends or confirms the item-drop action for normal inventory slots.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| `DropInputPane` | `0x005b47e0-0x005b48a7` | Constructs the prompt with player name and installs vtables. |
| `OnKeyEvent` | `0x005b48b0-0x005b491c` | Handles help-panel shortcut and delegates normal input. |
| `OnSubmit` | `0x005b4920-0x005b4ae4` | Converts input to a slot, creates `DropGoldInputPane` for gold, or sends/confirm drop item opcode `0x08`. |

## Evidence Notes

- IDA MCP live recheck on 2026-06-07 against `NexusTK.exe` (`md5 4247e04e20b65d6414c7238aa8ff5515`) confirms the modeled functions at `0x005b47e0-0x005b48a7`, `0x005b48b0-0x005b491c`, and `0x005b4920-0x005b4ae4`.
- The constructor calls the `CharInputPane` path, reads the local player/client state through [UID:0000QK][g_pCollectionData](by-global/g_pCollectionData.md) / historical IDA alias `dword_67A748`, fetches localized prompt id `6` from [UID:0000RC][g_pLanguageMan](by-global/g_pLanguageMan.md), formats the player-specific prompt, and installs vtables `0x0062fe18`, `0x0062fe68`, and `0x0062fe98`.
- IDA xrefs to those vtable bases come from the constructor stores plus the command dispatcher and command factory allocation path, matching the direct slash-command item prompt family.
- `OnKeyEvent` implements the same help shortcut path as `DropAllInputPane`: it checks the keyboard event fields, opens the general-purpose/help UI with category/page `2`, calls the `0x198` help transition path, and otherwise delegates to the base input handler.
- `OnSubmit` requires one typed character. The gold shortcut characters backslash (`0x5c`), slash (`0x2f`), and dollar (`0x24`) allocate a `DropGoldInputPane`, request localized prompt id `7`, call the `NumberInputPane` construction path, and install the DropGold vtables `0x0062fea4`, `0x0062fef4`, and `0x0062ff24`.
- B001 Rule 26 reanalysis identifies the gold shortcut construction sequence at `0x005b4a9a-0x005b4abf` as the live inline mirror for [UID:000043][DropGoldInputPane](by-class/DropGoldInputPane.md)'s retained raw constructor [UID:0001MH][0x005b4b70-0x005b4bb0.DropGoldInputPaneRawConstructor](by-memory/0x005b4b70-0x005b4bb0.DropGoldInputPaneRawConstructor.md). That proves the class is live/source-real without proving a direct call to the raw constructor start.
- 2026-06-25 B007 uses the same `0x005b4a9a-0x005b4abf` inline mirror as source-shape proof for formal [UID:0001MH][0x005b4b70-0x005b4bb0.DropGoldInputPaneRawConstructor](by-memory/0x005b4b70-0x005b4bb0.DropGoldInputPaneRawConstructor.md) constructor C++. The retained raw start still has no modeled function, no xrefs, no VA/RVA pointer hits, and no PE rel32 route, so this page should treat the branch as live creator evidence rather than a direct-call anchor.
- For non-gold input, `OnSubmit` converts the slot character, bounds it against [UID:0000PS][g_activeUserStatusPane](by-global/g_activeUserStatusPane.md) offset `+0x284`, and uses [UID:0000QK][g_pCollectionData](by-global/g_pCollectionData.md) historical offset `+0x3ec0` as the busy gate before direct packet send.
- Lower inventory slots send a three-byte [UID:0000Q5][g_packetSender](by-global/g_packetSender.md) packet: opcode `0x08`, selected slot, mode byte `0`. Higher slot selections allocate a confirmation pane with the same selected slot and mode byte `0`.
- B003 Rule 26 reanalysis resolves that confirmation action construction: the method calls [UID:0002VM][0x005b7450-0x005b74dd.CreateUserPaneDoubleParamCallback](by-memory/0x005b7450-0x005b74dd.CreateUserPaneDoubleParamCallback.md) at `0x005b4a05`, binding `UserPane::SendDropItemPacket(signed char,bool)` at `0x005ad7a0`, [UID:0000QK][g_pCollectionData](by-global/g_pCollectionData.md) / source-facing `g_pUserPane` as the target, the selected slot local, and `m_allItems=false`. The returned action object is stored by [UID:0001N4][0x005b75d0-0x005b760e.ConfirmInputPaneConstructor](by-memory/0x005b75d0-0x005b760e.ConfirmInputPaneConstructor.md) and invoked through [UID:000366][0x004f2a10-0x004f2a58.ConfirmInputPaneInvokeAcceptedAction](by-memory/0x004f2a10-0x004f2a58.ConfirmInputPaneInvokeAcceptedAction.md) / [UID:0001N5][0x005b77b0-0x005b77c8.UserPaneDoubleParamCallback](by-memory/0x005b77b0-0x005b77c8.UserPaneDoubleParamCallback.md) after a `y`/`Y` response.
- The class belongs with the direct item action panes because it owns command-input translation and packet dispatch rather than inventory rendering.
- B012 UID0001MG implementation keeps this class under [UID:0000KC][ItemActionInputPanes](by-file/ItemActionInputPanes.md) and records the surrounding `0x005b44b0-0x005b538a` island as a split/index aggregate marker only. Real source for this class should be emitted through exact method/class work, not by pasting a synthetic `DropGiveInputPanes` body into the aggregate.

## Assignment Gate

- Assignment decision: assigned to [UID:0000KC][ItemActionInputPanes](by-file/ItemActionInputPanes.md).
- Child gate: `86/88` after Batch 085; the class now has exact method boundaries, vtable evidence, prompt id, key path, gold branch, slot conversion, packet behavior, and confirmation branch evidence.
- Parent gate: [UID:0000KC][ItemActionInputPanes](by-file/ItemActionInputPanes.md) is `90/85` after the same Batch 085 parent refresh.
- Ownership basis: the class is a direct command-input item prompt implemented in the same item-action pane cluster as `DropAllInputPane`, `GiveInputPane`, `ThrowInputPane`, `UseInputPane`, `EatInputPane`, `WieldInputPane`, and `WearInputPane`.

## Cross-References

- [UID:0000KC][ItemActionInputPanes](by-file/ItemActionInputPanes.md)
- [UID:0001XU][ItemActionInputPaneVtableFamily](by-type/by-vtable/ItemActionInputPaneVtableFamily.md)
- [UID:0001MG][0x005b44b0-0x005b538a.DropGiveInputPanes](by-memory/0x005b44b0-0x005b538a.DropGiveInputPanes.md)
- [UID:000042][DropAllInputPane](by-class/DropAllInputPane.md)
- [UID:000043][DropGoldInputPane](by-class/DropGoldInputPane.md)
- [UID:0000PS][g_activeUserStatusPane](by-global/g_activeUserStatusPane.md)
- [UID:0000QK][g_pCollectionData](by-global/g_pCollectionData.md)
- [UID:0000Q5][g_packetSender](by-global/g_packetSender.md)
- [UID:0000RC][g_pLanguageMan](by-global/g_pLanguageMan.md)
- [UID:0002VM][0x005b7450-0x005b74dd.CreateUserPaneDoubleParamCallback](by-memory/0x005b7450-0x005b74dd.CreateUserPaneDoubleParamCallback.md)
- [UID:0001N4][0x005b75d0-0x005b760e.ConfirmInputPaneConstructor](by-memory/0x005b75d0-0x005b760e.ConfirmInputPaneConstructor.md)
- [UID:0001N5][0x005b77b0-0x005b77c8.UserPaneDoubleParamCallback](by-memory/0x005b77b0-0x005b77c8.UserPaneDoubleParamCallback.md)

## B005 2026-06-30 Empty-Emitter Callback

- Formal output: the `RECONSTRUCTION_CPP CODE` block emits the accepted no-standalone marker plus `[[CHILDREN]]` so exact routed children can assemble under this route. The page routes Drop method ownership rather than emitting a separate body.
- Route proof: [UID:0001MG][0x005b44b0-0x005b538a.DropGiveInputPanes](by-memory/0x005b44b0-0x005b538a.DropGiveInputPanes.md) covers the Drop constructor `0x005b47e0-0x005b48a7`, key handler `0x005b48b0-0x005b491c`, and submit/gold-routing handler `0x005b4920-0x005b4ae4`. Exact single-drop helper evidence is [UID:0003FL][0x005b4af0-0x005b4b6c.SendDropItemPacketRaw](by-memory/0x005b4af0-0x005b4b6c.SendDropItemPacketRaw.md), and the gold branch constructs [UID:000043][DropGoldInputPane](by-class/DropGoldInputPane.md) / [UID:0001MH][0x005b4b70-0x005b4bb0.DropGoldInputPaneRawConstructor](by-memory/0x005b4b70-0x005b4bb0.DropGoldInputPaneRawConstructor.md). [UID:0001XU][ItemActionInputPaneVtableFamily](by-type/by-vtable/ItemActionInputPaneVtableFamily.md) records the Drop vtable stores.
- Rejected emission: no separate class-page body is source-shaped here because exact method/helper evidence is already routed and the gold branch belongs to the DropGold split.

## Changes

- 2026-06-29 B012 UID0001MG support sync:
  - Score unchanged at `86/88`; cross-linked [UID:0001MG][0x005b44b0-0x005b538a.DropGiveInputPanes](by-memory/0x005b44b0-0x005b538a.DropGiveInputPanes.md) as the accepted split/index aggregate marker, not a source body for this class.
  - Preserved the existing class-page no-code rationale: exact submit/method/class declaration work remains separate from the aggregate marker.
- 2026-06-20 B003 Rule 26 support sync:
  - Score unchanged at `86/88`.
  - Added the concrete confirmation action-object factory route: `UserPane::SendDropItemPacket`, captured slot, and `m_allItems=false` through [UID:0002VM][0x005b7450-0x005b74dd.CreateUserPaneDoubleParamCallback](by-memory/0x005b7450-0x005b74dd.CreateUserPaneDoubleParamCallback.md), [UID:0001N4][0x005b75d0-0x005b760e.ConfirmInputPaneConstructor](by-memory/0x005b75d0-0x005b760e.ConfirmInputPaneConstructor.md), and [UID:0001N5][0x005b77b0-0x005b77c8.UserPaneDoubleParamCallback](by-memory/0x005b77b0-0x005b77c8.UserPaneDoubleParamCallback.md).
- 2026-06-07 A004 Batch 085 class toss-up:
  - Before: `76/84`, `AUTOGEN_PARENT_UID` blank.
  - After: `86/88`, `AUTOGEN_PARENT_UID:0000KC`.
  - Evidence: live IDA MCP confirmed exact constructor/key/submit ranges, vtable triple and factory/dispatcher xrefs, prompt id `6`, help-key path, gold shortcut branch, slot-letter conversion, inventory bound, busy gate, opcode `0x08` drop mode byte `0`, and confirmation branch.
  - Assignment: direct parent [UID:0000KC][ItemActionInputPanes](by-file/ItemActionInputPanes.md) also reached `90/85`, satisfying the corrected child-and-parent 85/85 gate.
- 2026-05-30:
  - Before: completion/confidence metadata was left at unevaluated `0/0`.
  - After: scored as `76/84`.
  - Summary/evidence: standard drop prompt role, constructor/key/submit methods, gold branch, opcode behavior, item-action module ownership, and sibling pane links are documented; remaining work is detailed field naming and final reconstructed C++ polish.
- 2026-06-05: Marked reconstructable for autogen.
  - Before: `RECONSTRUCTABLE` was blank, leaving the class coverage row unclassified.
  - After at that time: `RECONSTRUCTABLE:TRUE`; `AUTOGEN_PARENT_UID` remained blank because the class completion score was below the old attachment gate. Superseded by the 2026-06-07 A004 Batch 085 assignment to [UID:0000KC][ItemActionInputPanes](by-file/ItemActionInputPanes.md).
  - Evidence: live IDA MCP confirms modeled starts at `0x005b47e0`, `0x005b48b0`, and `0x005b4920`; existing project docs place this direct item-action prompt in [UID:0000KC][ItemActionInputPanes](by-file/ItemActionInputPanes.md).
- 2026-06-20 B001 Rule 26 incorporation:
  - Score unchanged at `86/88`.
  - Added the exact `0x005b4a9a-0x005b4abf` live inline construction mirror for [UID:000043][DropGoldInputPane](by-class/DropGoldInputPane.md), including prompt id `7`, `NumberInputPane` construction, vtable stores, and retained/no-route raw constructor interpretation.
- 2026-06-25 B007 DropGold constructor support sync:
  - Score unchanged at `86/88`; class-level C++ remains blank.
  - Updated the reconstruction note and evidence to state the inline mirror now supports first-draft constructor C++ on [UID:0001MH][0x005b4b70-0x005b4bb0.DropGoldInputPaneRawConstructor](by-memory/0x005b4b70-0x005b4bb0.DropGoldInputPaneRawConstructor.md), while no-route evidence remains a retained raw-body caveat.
