*** UID:00005U | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:85 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000KC | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000KC | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
// No standalone class-page emission for GiveInputPane; exact Give method bodies and gold-branch evidence are documented in [UID:0001MG][0x005b44b0-0x005b538a.DropGiveInputPanes](by-memory/0x005b44b0-0x005b538a.DropGiveInputPanes.md).
[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# GiveInputPane

## B003 2026-07-20 Event Contract Synchronization

- The compact `0x005b5040` help override is source-facing `bool HandleKeyOrTextEvent(Event *event)`: translate key/modifiers through `g_pEventMan`, require translated `?`, exact Shift `0x04`, and key-down, switch tab `2` with `NULL`, play effect `0x198` at 100, return true, and otherwise forward to the existing input-pane base.
- Give target/slot/amount, confirmation and packet behavior, constructors, children, vtable/compiler evidence, scores, route, formal block, and unrelated history remain unchanged. Historical `OnKeyInput`/`InputEvent`/`NarrowInputKey`/`false` terminology is superseded only.

## Status

- Confidence: strong for behavior and item-action input module placement.
- Likely source file: [UID:0000KC][ItemActionInputPanes](by-file/ItemActionInputPanes.md)
- Address range: [UID:0001MG][0x005b44b0-0x005b538a.DropGiveInputPanes](by-memory/0x005b44b0-0x005b538a.DropGiveInputPanes.md)
- Autogen parent: [UID:0000KC][ItemActionInputPanes](by-file/ItemActionInputPanes.md); both child and direct parent now clear the strict `85/85` gate.
- Current recovered file: `source-3/simroot_v2/class_GiveInputPane.cpp`
- Formal output on this class page is now the accepted comment-only no-standalone marker pending method/declaration work, prompt text fields, base `CharInputPane` method names, and final helper names. The gold-branch constructor child [UID:0001MI][0x005b52b0-0x005b52f0.GiveGoldInputPaneRawConstructor](by-memory/0x005b52b0-0x005b52f0.GiveGoldInputPaneRawConstructor.md) is no longer blocked and now emits formal first-draft `GiveGoldInputPane` constructor C++ through [UID:00005T][GiveGoldInputPane](by-class/GiveGoldInputPane.md). [UID:0001MG][0x005b44b0-0x005b538a.DropGiveInputPanes](by-memory/0x005b44b0-0x005b538a.DropGiveInputPanes.md) now emits only the accepted split/index aggregate marker and must not be treated as a synthetic class/body source.

## Class Purpose

`GiveInputPane` is the standard item-give prompt. It accepts a single inventory slot letter, routes gold selection into `GiveGoldInputPane`, and opens a confirmation callback for normal item slots.

It is the non-all variant paired with [UID:00005S][GiveAllInputPane](by-class/GiveAllInputPane.md). Both live in the same drop/give item-action cluster and use the same prompt/input framework as the drop-side siblings.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| `GiveInputPane` | `0x005b4f70-0x005b5037` | Constructs the prompt with player name and installs the three-view item-action input vtables. |
| `OnKeyInput` | `0x005b5040-0x005b50ac` | Handles the help-panel shortcut and delegates normal character input. |
| `OnConfirmInput` | `0x005b50b0-0x005b5223` | Converts slot input, branches gold selection into `GiveGoldInputPane`, or opens normal-item give confirmation. |

## Evidence Notes

- [UID:0001MG][0x005b44b0-0x005b538a.DropGiveInputPanes](by-memory/0x005b44b0-0x005b538a.DropGiveInputPanes.md) records IDA-confirmed half-open ranges for `0x005b4f70-0x005b5037`, `0x005b5040-0x005b50ac`, and `0x005b50b0-0x005b5223`.
- The same aggregate records pure padding at `0x005b5037-0x005b5040` and `0x005b50ac-0x005b50b0`, which keeps the three modeled method boundaries clean.
- The gold branch inline-constructs [UID:00005T][GiveGoldInputPane](by-class/GiveGoldInputPane.md) rather than calling the raw constructor start: it allocates `0x108` / 264 bytes (Verified with int_convert.py), resolves localized prompt id `0x2b` / `43` (Verified with int_convert.py), calls the [UID:00009L][NumberInputPane](by-class/NumberInputPane.md) constructor, and stores the `GiveGoldInputPane` vtables `0x00630048`, `0x00630098`, and `0x006300c8` at the same offsets mirrored by [UID:0001MI][0x005b52b0-0x005b52f0.GiveGoldInputPaneRawConstructor](by-memory/0x005b52b0-0x005b52f0.GiveGoldInputPaneRawConstructor.md). B015/B005 found no direct route to the raw constructor start, so this page owns the creator/dispatcher branch only, not the child class implementation; the exact constructor child now emits formal first-draft C++ through `GiveGoldInputPane`.
- B003 Rule 26 reanalysis resolves the normal-item confirmation action construction: `OnConfirmInput` calls [UID:0002VM][0x005b7450-0x005b74dd.CreateUserPaneDoubleParamCallback](by-memory/0x005b7450-0x005b74dd.CreateUserPaneDoubleParamCallback.md) at `0x005b5198`, binding `UserPane::SendGiveItemPacket(signed char,bool)` at `0x005ad720`, [UID:0000QK][g_pCollectionData](by-global/g_pCollectionData.md) / source-facing `g_pUserPane` as the target, the selected slot local, and `m_allItems=false`. The returned action object is stored by [UID:0001N4][0x005b75d0-0x005b760e.ConfirmInputPaneConstructor](by-memory/0x005b75d0-0x005b760e.ConfirmInputPaneConstructor.md), then invoked through [UID:000366][0x004f2a10-0x004f2a58.ConfirmInputPaneInvokeAcceptedAction](by-memory/0x004f2a10-0x004f2a58.ConfirmInputPaneInvokeAcceptedAction.md) / [UID:0001N5][0x005b77b0-0x005b77c8.UserPaneDoubleParamCallback](by-memory/0x005b77b0-0x005b77c8.UserPaneDoubleParamCallback.md) after a `y`/`Y` response.
- The former raw span after `0x005b5223` is now split: `0x005b5223-0x005b5230` is `0x0d` / 13 bytes of padding (Verified with int_convert.py), [UID:0003FO][0x005b5230-0x005b52ac.SendGiveItemPacketRaw](by-memory/0x005b5230-0x005b52ac.SendGiveItemPacketRaw.md) is the exact give-item packet helper body, `0x005b52ac-0x005b52b0` is `0x04` / 4 bytes of padding (Verified with int_convert.py), and [UID:0001MI][0x005b52b0-0x005b52f0.GiveGoldInputPaneRawConstructor](by-memory/0x005b52b0-0x005b52f0.GiveGoldInputPaneRawConstructor.md) is the exact raw `GiveGoldInputPane` constructor.
- This class is the give counterpart to [UID:000044][DropInputPane](by-class/DropInputPane.md).
- 2026-06-12 A005 Batch253 live IDA MCP verified [UID:0003FO][0x005b5230-0x005b52ac.SendGiveItemPacketRaw](by-memory/0x005b5230-0x005b52ac.SendGiveItemPacketRaw.md) as a no-function/no-xref/no-pointer `0x7c` / 124-byte raw helper (Verified with int_convert.py) that checks busy byte `+0x3ec0`, writes opcode `0x29`, writes the slot byte, writes mode byte `0`, and queues a 3-byte packet.
- B012 UID0001MG implementation keeps this class under [UID:0000KC][ItemActionInputPanes](by-file/ItemActionInputPanes.md) and records the surrounding `0x005b44b0-0x005b538a` island as a split/index aggregate marker only. Real source for this class should be emitted through exact method/class work, not by pasting a synthetic `DropGiveInputPanes` body into the aggregate.

## State And Dependencies

| Dependency | Role | Reconstruction Note |
| --- | --- | --- |
| [UID:00005T][GiveGoldInputPane](by-class/GiveGoldInputPane.md) | Numeric gold-give prompt reached from the gold slot branch. | This page proves inline construction and prompt/vtable choice; ownership/emission stay with [UID:0000KC][ItemActionInputPanes](by-file/ItemActionInputPanes.md) and the `GiveGoldInputPane` class page. Exact constructor child [UID:0001MI][0x005b52b0-0x005b52f0.GiveGoldInputPaneRawConstructor](by-memory/0x005b52b0-0x005b52f0.GiveGoldInputPaneRawConstructor.md) now emits formal first-draft C++ while this creator page emits only the accepted comment-only no-standalone marker. |
| [UID:00005S][GiveAllInputPane](by-class/GiveAllInputPane.md) | Sibling prompt for all-items give behavior. | Share naming and prompt framework, but keep all-items callback handling separate. |
| [UID:0001XU][ItemActionInputPaneVtableFamily](by-type/by-vtable/ItemActionInputPaneVtableFamily.md) | Three-view vtable family for direct item-action prompts. | Source should declare the class and let vtables rebuild from virtual methods. |
| [UID:0003FO][0x005b5230-0x005b52ac.SendGiveItemPacketRaw](by-memory/0x005b5230-0x005b52ac.SendGiveItemPacketRaw.md) | Adjacent raw packet helper for lower-slot give sends. | Direct file-scope helper under [UID:0000KC][ItemActionInputPanes](by-file/ItemActionInputPanes.md); class docs link it as associated behavior. |
| [UID:0002VM][0x005b7450-0x005b74dd.CreateUserPaneDoubleParamCallback](by-memory/0x005b7450-0x005b74dd.CreateUserPaneDoubleParamCallback.md) | Confirmation action-object factory for the accepted higher-slot give path. | Captures `UserPane::SendGiveItemPacket`, selected slot, and `m_allItems=false`; [UID:000035][ConfirmInputPane](by-class/ConfirmInputPane.md) stores and invokes the object. |
| [UID:0000Q5][g_packetSender](by-global/g_packetSender.md) | Give-gold path ultimately queues opcode `0x2a`. | Packet send details live with `GiveGoldInputPane`; this class owns the routing branch. |

## Autogen And Score Notes

This page is attached for autogen to [UID:0000KC][ItemActionInputPanes](by-file/ItemActionInputPanes.md). The direct parent clears the parent side at `90/85`, and this class now clears the child side at `85/88` after the raw helper split and constructor child refresh.

This creator/dispatcher class page emits only the accepted comment-only no-standalone marker because prompt/local field names, source-facing helper names, and base class virtual names still need a focused method-level pass. That class-page caveat does not apply to [UID:0001MI][0x005b52b0-0x005b52f0.GiveGoldInputPaneRawConstructor](by-memory/0x005b52b0-0x005b52f0.GiveGoldInputPaneRawConstructor.md), whose exact constructor source is now populated through `GiveGoldInputPane`.

## Cross-References

- [UID:0000KC][ItemActionInputPanes](by-file/ItemActionInputPanes.md)
- [UID:0001XU][ItemActionInputPaneVtableFamily](by-type/by-vtable/ItemActionInputPaneVtableFamily.md)
- [UID:0001MG][0x005b44b0-0x005b538a.DropGiveInputPanes](by-memory/0x005b44b0-0x005b538a.DropGiveInputPanes.md)
- [UID:0003FO][0x005b5230-0x005b52ac.SendGiveItemPacketRaw](by-memory/0x005b5230-0x005b52ac.SendGiveItemPacketRaw.md)
- [UID:00005S][GiveAllInputPane](by-class/GiveAllInputPane.md)
- [UID:00005T][GiveGoldInputPane](by-class/GiveGoldInputPane.md)
- [UID:0001MI][0x005b52b0-0x005b52f0.GiveGoldInputPaneRawConstructor](by-memory/0x005b52b0-0x005b52f0.GiveGoldInputPaneRawConstructor.md)
- [UID:000044][DropInputPane](by-class/DropInputPane.md)
- [UID:0002VM][0x005b7450-0x005b74dd.CreateUserPaneDoubleParamCallback](by-memory/0x005b7450-0x005b74dd.CreateUserPaneDoubleParamCallback.md)
- [UID:0001N4][0x005b75d0-0x005b760e.ConfirmInputPaneConstructor](by-memory/0x005b75d0-0x005b760e.ConfirmInputPaneConstructor.md)
- [UID:0001N5][0x005b77b0-0x005b77c8.UserPaneDoubleParamCallback](by-memory/0x005b77b0-0x005b77c8.UserPaneDoubleParamCallback.md)

## B005 2026-06-30 Empty-Emitter Callback

- Formal output: the `RECONSTRUCTION_CPP CODE` block emits the accepted no-standalone marker plus `[[CHILDREN]]` so exact routed children can assemble under this route. The page routes Give method ownership rather than emitting a separate whole-class body.
- Route proof: [UID:0001MG][0x005b44b0-0x005b538a.DropGiveInputPanes](by-memory/0x005b44b0-0x005b538a.DropGiveInputPanes.md) covers the Give constructor `0x005b4f70-0x005b5037`, key handler `0x005b5040-0x005b50ac`, and confirm/gold-routing handler `0x005b50b0-0x005b5223`. Exact single-give helper evidence is [UID:0003FO][0x005b5230-0x005b52ac.SendGiveItemPacketRaw](by-memory/0x005b5230-0x005b52ac.SendGiveItemPacketRaw.md), and the gold branch constructs [UID:00005T][GiveGoldInputPane](by-class/GiveGoldInputPane.md) / [UID:0001MI][0x005b52b0-0x005b52f0.GiveGoldInputPaneRawConstructor](by-memory/0x005b52b0-0x005b52f0.GiveGoldInputPaneRawConstructor.md). [UID:0001XU][ItemActionInputPaneVtableFamily](by-type/by-vtable/ItemActionInputPaneVtableFamily.md) records Give vtable stores.
- Rejected emission: no separate class-page body is source-shaped here because exact method/helper evidence is already routed and the gold branch belongs to the GiveGold split.

## Changes

- 2026-06-29 B012 UID0001MG support sync:
  - Score unchanged at `85/88`; cross-linked [UID:0001MG][0x005b44b0-0x005b538a.DropGiveInputPanes](by-memory/0x005b44b0-0x005b538a.DropGiveInputPanes.md) as the accepted split/index aggregate marker, not a source body for this class.
  - Preserved the existing class-page no-code rationale: exact method/class declaration work remains separate from the aggregate marker.
- 2026-06-25 B005 GiveGold constructor support sync:
  - Score unchanged at `85/88`.
  - Updated the gold-branch evidence, dependency notes, and autogen caveat to record that [UID:0001MI][0x005b52b0-0x005b52f0.GiveGoldInputPaneRawConstructor](by-memory/0x005b52b0-0x005b52f0.GiveGoldInputPaneRawConstructor.md) now emits formal first-draft constructor C++ through [UID:00005T][GiveGoldInputPane](by-class/GiveGoldInputPane.md), while this page still owns only the inline creator/dispatcher branch.
  - Evidence: current MCP session `80de0a67` reconfirmed allocation `0x108` / 264 bytes, prompt id `0x2b` / 43, `NumberInputPane` base construction, the three `GiveGoldInputPane` vtables, no raw-start route to `0x005b52b0`, and `0x00630090 -> 0x005b52f0` as the live submit route.
- 2026-06-22 B015 GiveGold support sync:
  - Score unchanged at `85/88`.
  - Clarified that `OnConfirmInput` inline-constructs [UID:00005T][GiveGoldInputPane](by-class/GiveGoldInputPane.md) with prompt id `0x2b` and vtables `0x00630048/0x00630098/0x006300c8`, while [UID:0001MI][0x005b52b0-0x005b52f0.GiveGoldInputPaneRawConstructor](by-memory/0x005b52b0-0x005b52f0.GiveGoldInputPaneRawConstructor.md) remains retained/no-route evidence. This creator relationship does not transfer class ownership to `GiveInputPane`.
- 2026-06-20 B003 Rule 26 support sync:
  - Score unchanged at `85/88`.
  - Added the concrete confirmation action-object factory route: `UserPane::SendGiveItemPacket`, captured slot, and `m_allItems=false` through [UID:0002VM][0x005b7450-0x005b74dd.CreateUserPaneDoubleParamCallback](by-memory/0x005b7450-0x005b74dd.CreateUserPaneDoubleParamCallback.md), [UID:0001N4][0x005b75d0-0x005b760e.ConfirmInputPaneConstructor](by-memory/0x005b75d0-0x005b760e.ConfirmInputPaneConstructor.md), and [UID:0001N5][0x005b77b0-0x005b77c8.UserPaneDoubleParamCallback](by-memory/0x005b77b0-0x005b77c8.UserPaneDoubleParamCallback.md).
- 2026-06-10 A002 strict-gate repair:
  - Before: `AUTOGEN_PARENT_UID:0000KC` still attached this class to [UID:0000KC][ItemActionInputPanes](by-file/ItemActionInputPanes.md) even though the class score is only `80/87`.
  - After: cleared `AUTOGEN_PARENT_UID` and left the score unchanged at `80/87`.
  - Reason: the direct parent now clears the parent side at `90/85`, but the child side must also be at least `85/85`; this class still needs the raw helper span after `0x005b5223`, prompt/local field names, and final source-facing base method names resolved before assignment.
  - Evidence: existing class, by-file, and [UID:0001MG][0x005b44b0-0x005b538a.DropGiveInputPanes](by-memory/0x005b44b0-0x005b538a.DropGiveInputPanes.md) documentation already records the modeled ranges and blockers; no new live IDA evidence was used.
- 2026-06-12 A005 Batch253:
  - Before: `80/87`, parent blank under the strict child-side gate, with the raw helper span after `0x005b5223` still unsplit.
  - Changed to: `85/88`, `AUTOGEN_PARENT_UID:0000KC`.
  - Evidence: Batch253 created [UID:0003FO][0x005b5230-0x005b52ac.SendGiveItemPacketRaw](by-memory/0x005b5230-0x005b52ac.SendGiveItemPacketRaw.md), documented exact padding around it and [UID:0001MI][0x005b52b0-0x005b52f0.GiveGoldInputPaneRawConstructor](by-memory/0x005b52b0-0x005b52f0.GiveGoldInputPaneRawConstructor.md), raised the constructor child to `85/88`, and verified the no-function/no-xref/no-pointer give packet helper body, opcode `0x29`, mode byte `0`, busy gate, and three-byte send behavior.
- 2026-06-07: Raised `COMPLETION` from `74` to `80`, raised `CONFIDENCE` from `86` to `87`, and attached `AUTOGEN_PARENT_UID:0000KC`.
  - Before: the page documented the three core methods and give/gold role, but lacked parent metadata, raw-span caveats, dependency mapping, and score rationale.
  - After: the page records parent-gate reasoning, exact half-open method ranges, clean padding boundaries, gold raw-constructor dependency, raw helper blocker after `0x005b5223`, sibling/drop-side relationships, and final-C++ blockers.
  - Evidence: [UID:0000KC][ItemActionInputPanes](by-file/ItemActionInputPanes.md) is `90/80`; [UID:0001MG][0x005b44b0-0x005b538a.DropGiveInputPanes](by-memory/0x005b44b0-0x005b538a.DropGiveInputPanes.md) records the modeled function map, raw helper map, vtable family, and give-gold prompt dependency.
- Completion/confidence score update: existed before as `0/0`; changed to `74/86`. Summary: standard give prompt role, constructor/key/confirm methods, gold branch, sibling relationship, and item-action module placement are documented with strong confidence; remaining work is detailed layout naming and final source reconstruction. Evidence: `0x005b44b0-0x005b538a` memory page, IDA-confirmed starts for `0x005b4f70`, `0x005b5040`, and `0x005b50b0`, plus GiveAll/GiveGold cross-references.
- 2026-06-05: Marked reconstructable for autogen.
  - Before: `RECONSTRUCTABLE` was blank, leaving the standard give item action prompt unclassified in generated class coverage.
  - After: set `RECONSTRUCTABLE:TRUE`; left `AUTOGEN_PARENT_UID` blank because the class score is `74/86`, below the 80 completion attachment gate.
  - Summary/evidence: live IDA MCP reconfirms real starts at `0x005b4f70`, `0x005b5040`, and `0x005b50b0`, matching the documented give/gold-branch behavior and sibling `ItemActionInputPanes` placement.
