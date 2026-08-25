*** UID:000042 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000KC | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000KC | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
// No standalone class-page emission for DropAllInputPane; this page routes ownership for the exact DropAll method bodies documented in [UID:0001MG][0x005b44b0-0x005b538a.DropGiveInputPanes](by-memory/0x005b44b0-0x005b538a.DropGiveInputPanes.md).
[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# DropAllInputPane

## B003 2026-07-20 Event Contract Synchronization

- The compact `0x005b4580` help override is source-facing `bool HandleKeyOrTextEvent(Event *event)`: translate key/modifiers through `g_pEventMan`, require translated `?`, exact Shift `0x04`, and key-down, switch tab `2` with `NULL`, play effect `0x198` at 100, return true, and otherwise forward to the existing input-pane base.
- This bounded signature/prose correction preserves DropAll construction, confirmation and amount behavior, packet flow, children, vtable/compiler evidence, scores, route, formal block, and all unrelated history. Historical `OnKeyInput`/`InputEvent`/`NarrowInputKey`/`false` terminology is superseded only.

## Status

- Confidence: strong for behavior and item-action input module placement.
- Likely source file: [UID:0000KC][ItemActionInputPanes](by-file/ItemActionInputPanes.md)
- Address range: [UID:0001MG][0x005b44b0-0x005b538a.DropGiveInputPanes](by-memory/0x005b44b0-0x005b538a.DropGiveInputPanes.md)
- Reconstruction note: class-level formal output is now an accepted comment-only no-standalone marker because declaration shape, exact method children, helper/member names, and base virtual names still need a focused method-level pass. [UID:0001MG][0x005b44b0-0x005b538a.DropGiveInputPanes](by-memory/0x005b44b0-0x005b538a.DropGiveInputPanes.md) now emits only the accepted split/index aggregate marker; it is not a monolithic class/body substitute.

## Class Purpose

`DropAllInputPane` is a single-character inventory prompt for dropping all items in a selected slot. It formats a player-specific prompt, accepts a slot letter, validates it against the local inventory limit, and either sends the drop-all packet path or opens a confirmation callback.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| `DropAllInputPane` | `0x005b44b0-0x005b4577` | Constructs the `CharInputPane` prompt and installs vtables. |
| `OnKeyInput` | `0x005b4580-0x005b45ec` | Opens the help/general-purpose panel for the shortcut key and otherwise delegates input. |
| `OnConfirmInput` | `0x005b45f0-0x005b475c` | Converts slot letters, validates inventory range, and sends or confirms the drop-all action. |

## Evidence Notes

- IDA MCP live recheck on 2026-06-07 against `NexusTK.exe` (`md5 4247e04e20b65d6414c7238aa8ff5515`) confirms the modeled functions at `0x005b44b0-0x005b4577`, `0x005b4580-0x005b45ec`, and `0x005b45f0-0x005b475c`.
- The constructor calls the `CharInputPane` path, reads the local player/client state through [UID:0000QK][g_pCollectionData](by-global/g_pCollectionData.md) / historical IDA alias `dword_67A748`, fetches localized prompt id `8` from [UID:0000RC][g_pLanguageMan](by-global/g_pLanguageMan.md), formats the player-specific prompt, and installs vtables `0x0062fd8c`, `0x0062fddc`, and `0x0062fe0c`.
- IDA xrefs to those vtable bases come from the constructor stores plus the command dispatcher and command factory allocation path, matching the direct slash-command item prompt family.
- `OnKeyInput` implements the shared help shortcut path: it checks the keyboard event fields, opens the general-purpose/help UI with category/page `2`, calls the `0x198` help transition path, and otherwise delegates to the base input handler.
- `OnConfirmInput` requires one typed character, converts lowercase `a-z` to slots `1-26` and uppercase `A-Z` to slots `27-52`, and bounds the converted value against [UID:0000PS][g_activeUserStatusPane](by-global/g_activeUserStatusPane.md) offset `+0x284`.
- For lower inventory slots, `OnConfirmInput` also checks the [UID:0000QK][g_pCollectionData](by-global/g_pCollectionData.md) busy byte at historical offset `+0x3ec0` before sending a three-byte [UID:0000Q5][g_packetSender](by-global/g_packetSender.md) packet: opcode `0x08`, selected slot, mode byte `1`.
- For higher slot selections, the method allocates a confirmation pane and passes the selected slot plus drop-all mode byte `1` with the text `Are you sure you want to drop this item? (Y/N)`.
- B003 Rule 26 reanalysis resolves that confirmation action construction: the method calls [UID:0002VM][0x005b7450-0x005b74dd.CreateUserPaneDoubleParamCallback](by-memory/0x005b7450-0x005b74dd.CreateUserPaneDoubleParamCallback.md) at `0x005b46d6`, binding `UserPane::SendDropItemPacket(signed char,bool)` at `0x005ad7a0`, [UID:0000QK][g_pCollectionData](by-global/g_pCollectionData.md) / source-facing `g_pUserPane` as the target, the selected slot local, and `m_allItems=true`. The returned action object is passed to [UID:0001N4][0x005b75d0-0x005b760e.ConfirmInputPaneConstructor](by-memory/0x005b75d0-0x005b760e.ConfirmInputPaneConstructor.md) and later invoked through [UID:000366][0x004f2a10-0x004f2a58.ConfirmInputPaneInvokeAcceptedAction](by-memory/0x004f2a10-0x004f2a58.ConfirmInputPaneInvokeAcceptedAction.md) / [UID:0001N5][0x005b77b0-0x005b77c8.UserPaneDoubleParamCallback](by-memory/0x005b77b0-0x005b77c8.UserPaneDoubleParamCallback.md) only after a `y`/`Y` response.
- This class is part of the direct item action prompt family, not the item selection dialog family.
- B012 UID0001MG implementation keeps this class under [UID:0000KC][ItemActionInputPanes](by-file/ItemActionInputPanes.md) and records the surrounding `0x005b44b0-0x005b538a` island as a split/index aggregate marker only. Real source for this class should be emitted through exact method/class work, not by pasting a synthetic `DropGiveInputPanes` body into the aggregate.

## Assignment Gate

- Assignment decision: assigned to [UID:0000KC][ItemActionInputPanes](by-file/ItemActionInputPanes.md).
- Child gate: `86/88` after Batch 085; the class now has exact method boundaries, vtable evidence, prompt id, key path, slot conversion, packet behavior, and confirmation branch evidence.
- Parent gate: [UID:0000KC][ItemActionInputPanes](by-file/ItemActionInputPanes.md) is `90/85` after the same Batch 085 parent refresh.
- Ownership basis: the class is a direct command-input item prompt implemented in the same item-action pane cluster as `DropInputPane`, `GiveInputPane`, `ThrowInputPane`, `UseInputPane`, `EatInputPane`, `WieldInputPane`, and `WearInputPane`.

## Cross-References

- [UID:0000KC][ItemActionInputPanes](by-file/ItemActionInputPanes.md)
- [UID:0001XU][ItemActionInputPaneVtableFamily](by-type/by-vtable/ItemActionInputPaneVtableFamily.md)
- [UID:0001MG][0x005b44b0-0x005b538a.DropGiveInputPanes](by-memory/0x005b44b0-0x005b538a.DropGiveInputPanes.md)
- [UID:000044][DropInputPane](by-class/DropInputPane.md)
- [UID:000043][DropGoldInputPane](by-class/DropGoldInputPane.md)
- [UID:0000PS][g_activeUserStatusPane](by-global/g_activeUserStatusPane.md)
- [UID:0000QK][g_pCollectionData](by-global/g_pCollectionData.md)
- [UID:0000Q5][g_packetSender](by-global/g_packetSender.md)
- [UID:0000RC][g_pLanguageMan](by-global/g_pLanguageMan.md)
- [UID:0002VM][0x005b7450-0x005b74dd.CreateUserPaneDoubleParamCallback](by-memory/0x005b7450-0x005b74dd.CreateUserPaneDoubleParamCallback.md)
- [UID:0001N4][0x005b75d0-0x005b760e.ConfirmInputPaneConstructor](by-memory/0x005b75d0-0x005b760e.ConfirmInputPaneConstructor.md)
- [UID:0001N5][0x005b77b0-0x005b77c8.UserPaneDoubleParamCallback](by-memory/0x005b77b0-0x005b77c8.UserPaneDoubleParamCallback.md)

## B005 2026-06-30 Empty-Emitter Callback

- Formal output: the `RECONSTRUCTION_CPP CODE` block emits the accepted no-standalone marker plus `[[CHILDREN]]` so exact routed children can assemble under this route. This page remains an index over exact DropAll ranges and helper evidence.
- Route proof: [UID:0001MG][0x005b44b0-0x005b538a.DropGiveInputPanes](by-memory/0x005b44b0-0x005b538a.DropGiveInputPanes.md) covers the exact DropAll constructor `0x005b44b0-0x005b4577`, key handler `0x005b4580-0x005b45ec`, and confirm/slot submit `0x005b45f0-0x005b475c`. Exact all-items helper evidence is [UID:0003FK][0x005b4760-0x005b47dc.SendDropAllItemPacketRaw](by-memory/0x005b4760-0x005b47dc.SendDropAllItemPacketRaw.md). [UID:0001XU][ItemActionInputPaneVtableFamily](by-type/by-vtable/ItemActionInputPaneVtableFamily.md) records DropAll vtables `0x0062fd8c`, `0x0062fddc`, and `0x0062fe0c`.
- Rejected emission: a standalone class body would duplicate the exact range/helper documentation and would turn a class routing page into decompiler-shaped aggregate source.

## Changes

- 2026-06-29 B012 UID0001MG support sync:
  - Score unchanged at `86/88`; replaced stale old-gate blank-C++ wording with the current method/declaration no-code rationale.
  - Cross-linked [UID:0001MG][0x005b44b0-0x005b538a.DropGiveInputPanes](by-memory/0x005b44b0-0x005b538a.DropGiveInputPanes.md) as the accepted split/index aggregate marker, not a source body for this class.
- 2026-06-20 B003 Rule 26 support sync:
  - Score unchanged at `86/88`.
  - Added the concrete confirmation action-object factory route: `UserPane::SendDropItemPacket`, captured slot, and `m_allItems=true` through [UID:0002VM][0x005b7450-0x005b74dd.CreateUserPaneDoubleParamCallback](by-memory/0x005b7450-0x005b74dd.CreateUserPaneDoubleParamCallback.md), [UID:0001N4][0x005b75d0-0x005b760e.ConfirmInputPaneConstructor](by-memory/0x005b75d0-0x005b760e.ConfirmInputPaneConstructor.md), and [UID:0001N5][0x005b77b0-0x005b77c8.UserPaneDoubleParamCallback](by-memory/0x005b77b0-0x005b77c8.UserPaneDoubleParamCallback.md).
- 2026-06-07 A004 Batch 085 class toss-up:
  - Before: `76/84`, `AUTOGEN_PARENT_UID` blank.
  - After: `86/88`, `AUTOGEN_PARENT_UID:0000KC`.
  - Evidence: live IDA MCP confirmed exact constructor/key/submit ranges, vtable triple and factory/dispatcher xrefs, prompt id `8`, help-key path, slot-letter conversion, inventory bound, busy gate, opcode `0x08` drop-all mode byte `1`, and confirmation branch.
  - Assignment: direct parent [UID:0000KC][ItemActionInputPanes](by-file/ItemActionInputPanes.md) also reached `90/85`, satisfying the corrected child-and-parent 85/85 gate.
- 2026-05-30:
  - Before: completion/confidence metadata was left at unevaluated `0/0`.
  - After: scored as `76/84`.
  - Summary/evidence: prompt role, constructor/key/confirm methods, item-action module ownership, packet/action behavior, IDA-confirmed starts, and sibling pane references are documented; remaining work is fuller internal field naming and final C++ reconstruction.
- 2026-06-05: Marked reconstructable for autogen.
  - Before: `RECONSTRUCTABLE` was blank, leaving the class coverage row unclassified.
  - After at that time: `RECONSTRUCTABLE:TRUE`; `AUTOGEN_PARENT_UID` remained blank because the class completion score was below the old attachment gate. Superseded by the 2026-06-07 A004 Batch 085 assignment to [UID:0000KC][ItemActionInputPanes](by-file/ItemActionInputPanes.md).
  - Evidence: live IDA MCP confirms modeled starts at `0x005b44b0`, `0x005b4580`, and `0x005b45f0`; existing project docs place this direct item-action prompt in [UID:0000KC][ItemActionInputPanes](by-file/ItemActionInputPanes.md).
