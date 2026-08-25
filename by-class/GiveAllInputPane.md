*** UID:00005S | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:85 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000KC | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000KC | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
// No standalone class-page emission for GiveAllInputPane; this page routes ownership for the exact GiveAll method bodies documented in [UID:0001MG][0x005b44b0-0x005b538a.DropGiveInputPanes](by-memory/0x005b44b0-0x005b538a.DropGiveInputPanes.md).
[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# GiveAllInputPane

## B003 2026-07-20 Event Contract Synchronization

- The compact `0x005b4d90` help override is source-facing `bool HandleKeyOrTextEvent(Event *event)`: translate key/modifiers through `g_pEventMan`, require translated `?`, exact Shift `0x04`, and key-down, switch tab `2` with `NULL`, play effect `0x198` at 100, return true, and otherwise forward to the existing input-pane base.
- GiveAll target/amount, confirmation and packet behavior, constructors, children, vtable/compiler evidence, scores, route, formal block, and unrelated history remain unchanged. Historical `OnKeyInput`/`InputEvent`/`NarrowInputKey`/`false` terminology is superseded only.

## Status

- Confidence: strong for behavior and item-action input module placement.
- Likely source file: [UID:0000KC][ItemActionInputPanes](by-file/ItemActionInputPanes.md)
- Address range: [UID:0001MG][0x005b44b0-0x005b538a.DropGiveInputPanes](by-memory/0x005b44b0-0x005b538a.DropGiveInputPanes.md)
- Autogen parent: [UID:0000KC][ItemActionInputPanes](by-file/ItemActionInputPanes.md), which is `90/85` and owns the direct item-action prompt family.
- Current recovered file: `source-3/simroot_v2/class_GiveAllInputPane.cpp`
- Formal C++ note: class-level formal output is now an accepted comment-only no-standalone marker because the confirmation callback type, prompt text fields, base `CharInputPane` method names, final helper names, and exact method/declaration strategy still need focused class/method work. [UID:0001MG][0x005b44b0-0x005b538a.DropGiveInputPanes](by-memory/0x005b44b0-0x005b538a.DropGiveInputPanes.md) now emits only the accepted split/index aggregate marker; it is not a monolithic class/body substitute.

## Class Purpose

`GiveAllInputPane` is a single-character prompt for giving all items in a selected slot to another player. It mirrors the drop-all prompt shape but builds a give callback and confirmation message.

It is the all-items sibling of [UID:00005U][GiveInputPane](by-class/GiveInputPane.md). The class should stay with the drop/give item-action cluster rather than target-selection or generic command-input code.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| `GiveAllInputPane` | `0x005b4cc0-0x005b4d87` | Constructs prompt with player name and installs the three-view item-action input vtables. |
| `OnKeyInput` | `0x005b4d90-0x005b4dfc` | Handles the help-panel shortcut and delegates character input. |
| `OnSubmitInput` | `0x005b4e00-0x005b4eee` | Converts slot letter, validates inventory range, and creates a give-all confirmation callback. |

## Evidence Notes

- [UID:0001MG][0x005b44b0-0x005b538a.DropGiveInputPanes](by-memory/0x005b44b0-0x005b538a.DropGiveInputPanes.md) records IDA-confirmed half-open ranges for `0x005b4cc0-0x005b4d87`, `0x005b4d90-0x005b4dfc`, and `0x005b4e00-0x005b4eee`.
- The same aggregate records pure padding at `0x005b4d87-0x005b4d90` and `0x005b4dfc-0x005b4e00`, which keeps the three modeled method boundaries clean.
- The former raw span after `0x005b4eee` is now split: `0x005b4eee-0x005b4ef0` is `0x02` / 2 bytes of padding (Verified with int_convert.py), [UID:0003FN][0x005b4ef0-0x005b4f6c.SendGiveAllItemPacketRaw](by-memory/0x005b4ef0-0x005b4f6c.SendGiveAllItemPacketRaw.md) is the exact give-all packet helper body, and `0x005b4f6c-0x005b4f70` is `0x04` / 4 bytes of padding (Verified with int_convert.py).
- Generated source shows callback creation through `GiveItemsToSlot` with the all-items flag set; keep that as behavioral evidence, not final source text.
- B003 Rule 26 reanalysis replaces the ambiguous generated callback wording with the concrete action-object route: `OnSubmitInput` calls [UID:0002VM][0x005b7450-0x005b74dd.CreateUserPaneDoubleParamCallback](by-memory/0x005b7450-0x005b74dd.CreateUserPaneDoubleParamCallback.md) at `0x005b4ec0`, binding `UserPane::SendGiveItemPacket(signed char,bool)` at `0x005ad720`, [UID:0000QK][g_pCollectionData](by-global/g_pCollectionData.md) / source-facing `g_pUserPane` as the target, the selected slot local, and `m_allItems=true`. The returned action object is passed to [UID:0001N4][0x005b75d0-0x005b760e.ConfirmInputPaneConstructor](by-memory/0x005b75d0-0x005b760e.ConfirmInputPaneConstructor.md) with [UID:0000RC][g_pLanguageMan](by-global/g_pLanguageMan.md) string id `0xdf`, then invoked through [UID:000366][0x004f2a10-0x004f2a58.ConfirmInputPaneInvokeAcceptedAction](by-memory/0x004f2a10-0x004f2a58.ConfirmInputPaneInvokeAcceptedAction.md) / [UID:0001N5][0x005b77b0-0x005b77c8.UserPaneDoubleParamCallback](by-memory/0x005b77b0-0x005b77c8.UserPaneDoubleParamCallback.md) after a `y`/`Y` response.
- The class should migrate beside [UID:00005U][GiveInputPane](by-class/GiveInputPane.md) and [UID:00005T][GiveGoldInputPane](by-class/GiveGoldInputPane.md).
- 2026-06-12 A005 Batch253 live IDA MCP verified [UID:0003FN][0x005b4ef0-0x005b4f6c.SendGiveAllItemPacketRaw](by-memory/0x005b4ef0-0x005b4f6c.SendGiveAllItemPacketRaw.md) as a no-function/no-xref/no-pointer `0x7c` / 124-byte raw helper (Verified with int_convert.py) that checks busy byte `+0x3ec0`, writes opcode `0x29`, writes the slot byte, writes mode byte `1`, and queues a 3-byte packet.
- B012 UID0001MG implementation keeps this class under [UID:0000KC][ItemActionInputPanes](by-file/ItemActionInputPanes.md) and records the surrounding `0x005b44b0-0x005b538a` island as a split/index aggregate marker only. Real source for this class should be emitted through exact method/class work, not by pasting a synthetic `DropGiveInputPanes` body into the aggregate.

## State And Dependencies

| Dependency | Role | Reconstruction Note |
| --- | --- | --- |
| [UID:00005U][GiveInputPane](by-class/GiveInputPane.md) | Non-all give prompt sibling. | Share prompt framework naming, but keep all-items callback handling distinct. |
| [UID:00005T][GiveGoldInputPane](by-class/GiveGoldInputPane.md) | Gold give sibling in the same cluster. | The all-items pane does not own gold amount packet send logic. |
| [UID:0001XU][ItemActionInputPaneVtableFamily](by-type/by-vtable/ItemActionInputPaneVtableFamily.md) | Three-view vtable family for direct item-action prompts. | Source should declare the class and let vtables rebuild from virtual methods. |
| [UID:0003FN][0x005b4ef0-0x005b4f6c.SendGiveAllItemPacketRaw](by-memory/0x005b4ef0-0x005b4f6c.SendGiveAllItemPacketRaw.md) | Adjacent raw packet helper for lower-slot give-all sends. | Direct file-scope helper under [UID:0000KC][ItemActionInputPanes](by-file/ItemActionInputPanes.md); class docs link it as associated behavior. |
| [UID:0002VM][0x005b7450-0x005b74dd.CreateUserPaneDoubleParamCallback](by-memory/0x005b7450-0x005b74dd.CreateUserPaneDoubleParamCallback.md) | Confirmation action-object factory for the accepted higher-slot give-all path. | Captures `UserPane::SendGiveItemPacket`, selected slot, and `m_allItems=true`; [UID:000035][ConfirmInputPane](by-class/ConfirmInputPane.md) stores and invokes the object. |
| inventory slot decoding | Submit handler validates a typed slot letter before creating the confirmation callback. | Final field/local names still need method-level reconstruction. |

## Autogen And Score Notes

This page is now attached to [UID:0000KC][ItemActionInputPanes](by-file/ItemActionInputPanes.md). The parent is `90/85`, and this class reaches `85/88` with exact method ranges, sibling relationships, all-items callback behavior, vtable-family evidence, and the former raw-helper blocker split into an exact child page.

The class page emits only the accepted comment-only no-standalone marker because the callback type declaration, prompt/local field names, source-facing helper names, and base class virtual names still need a focused method-level pass.

## Cross-References

- [UID:0000KC][ItemActionInputPanes](by-file/ItemActionInputPanes.md)
- [UID:0001XU][ItemActionInputPaneVtableFamily](by-type/by-vtable/ItemActionInputPaneVtableFamily.md)
- [UID:0001MG][0x005b44b0-0x005b538a.DropGiveInputPanes](by-memory/0x005b44b0-0x005b538a.DropGiveInputPanes.md)
- [UID:0003FN][0x005b4ef0-0x005b4f6c.SendGiveAllItemPacketRaw](by-memory/0x005b4ef0-0x005b4f6c.SendGiveAllItemPacketRaw.md)
- [UID:00005U][GiveInputPane](by-class/GiveInputPane.md)
- [UID:00005T][GiveGoldInputPane](by-class/GiveGoldInputPane.md)
- [UID:000042][DropAllInputPane](by-class/DropAllInputPane.md)
- [UID:0002VM][0x005b7450-0x005b74dd.CreateUserPaneDoubleParamCallback](by-memory/0x005b7450-0x005b74dd.CreateUserPaneDoubleParamCallback.md)
- [UID:0001N4][0x005b75d0-0x005b760e.ConfirmInputPaneConstructor](by-memory/0x005b75d0-0x005b760e.ConfirmInputPaneConstructor.md)
- [UID:0001N5][0x005b77b0-0x005b77c8.UserPaneDoubleParamCallback](by-memory/0x005b77b0-0x005b77c8.UserPaneDoubleParamCallback.md)

## B005 2026-06-30 Empty-Emitter Callback

- Formal output: the `RECONSTRUCTION_CPP CODE` block emits the accepted no-standalone marker plus `[[CHILDREN]]` so exact routed children can assemble under this route. This page routes GiveAll ownership for exact ranges and helper source.
- Route proof: [UID:0001MG][0x005b44b0-0x005b538a.DropGiveInputPanes](by-memory/0x005b44b0-0x005b538a.DropGiveInputPanes.md) covers the GiveAll constructor `0x005b4cc0-0x005b4d87`, key handler `0x005b4d90-0x005b4dfc`, and submit/confirmation handler `0x005b4e00-0x005b4eee`. Exact all-items helper evidence is [UID:0003FN][0x005b4ef0-0x005b4f6c.SendGiveAllItemPacketRaw](by-memory/0x005b4ef0-0x005b4f6c.SendGiveAllItemPacketRaw.md). [UID:0001XU][ItemActionInputPaneVtableFamily](by-type/by-vtable/ItemActionInputPaneVtableFamily.md) records GiveAll vtables `0x0062ff30`, `0x0062ff80`, and `0x0062ffb0`.
- Rejected emission: no whole-class body is emitted here because exact method/helper pages already carry the source-bearing evidence under the [UID:0000KC][ItemActionInputPanes](by-file/ItemActionInputPanes.md) module route.

## Changes

- 2026-06-29 B012 UID0001MG support sync:
  - Score unchanged at `85/88`; replaced stale `95/95` blank-C++ wording with the current method/declaration no-code rationale.
  - Cross-linked [UID:0001MG][0x005b44b0-0x005b538a.DropGiveInputPanes](by-memory/0x005b44b0-0x005b538a.DropGiveInputPanes.md) as the accepted split/index aggregate marker, not a source body for this class.
- 2026-06-20 B003 Rule 26 support sync:
  - Score unchanged at `85/88`.
  - Added the concrete confirmation action-object factory route: `UserPane::SendGiveItemPacket`, captured slot, and `m_allItems=true` through [UID:0002VM][0x005b7450-0x005b74dd.CreateUserPaneDoubleParamCallback](by-memory/0x005b7450-0x005b74dd.CreateUserPaneDoubleParamCallback.md), [UID:0001N4][0x005b75d0-0x005b760e.ConfirmInputPaneConstructor](by-memory/0x005b75d0-0x005b760e.ConfirmInputPaneConstructor.md), and [UID:0001N5][0x005b77b0-0x005b77c8.UserPaneDoubleParamCallback](by-memory/0x005b77b0-0x005b77c8.UserPaneDoubleParamCallback.md).
- 2026-06-07: Raised `COMPLETION` from `74` to `80`, raised `CONFIDENCE` from `86` to `87`, and attached `AUTOGEN_PARENT_UID:0000KC`.
  - Before: the page documented the three core methods and give-all role, but lacked parent metadata, raw-span caveats, dependency mapping, and score rationale.
  - After: the page records parent-gate reasoning, exact half-open method ranges, clean padding boundaries, all-items confirmation behavior, raw helper blocker after `0x005b4eee`, sibling/drop-side relationships, and final-C++ blockers.
  - Evidence: [UID:0000KC][ItemActionInputPanes](by-file/ItemActionInputPanes.md) is `90/80`; [UID:0001MG][0x005b44b0-0x005b538a.DropGiveInputPanes](by-memory/0x005b44b0-0x005b538a.DropGiveInputPanes.md) records the modeled function map, raw helper map, vtable family, and give-side prompt cluster.
- Completion/confidence score update: existed before as `0/0`; changed to `74/86`. Summary: give-all prompt role, constructor/key/submit methods, callback behavior, inventory validation, and sibling placement are documented with strong confidence; remaining work is final source reconstruction and field naming. Evidence: `0x005b44b0-0x005b538a` memory page, IDA-confirmed starts for `0x005b4cc0`, `0x005b4d90`, and `0x005b4e00`, plus ItemActionInputPanes vtable documentation.
- 2026-06-05: Marked reconstructable for autogen.
  - Before: `RECONSTRUCTABLE` was blank, leaving the give-all item action prompt unclassified in generated class coverage.
  - After: set `RECONSTRUCTABLE:TRUE`; left `AUTOGEN_PARENT_UID` blank because the class score is `74/86`, below the 80 completion attachment gate.
  - Summary/evidence: live IDA MCP reconfirms real starts at `0x005b4cc0`, `0x005b4d90`, and `0x005b4e00`, matching the documented item-action input pane behavior and `ItemActionInputPanes` placement.
- 2026-06-12 A005 Batch253:
  - Before: `80/87`; the class was attached to [UID:0000KC][ItemActionInputPanes](by-file/ItemActionInputPanes.md) but remained below the strict child gate, and the raw helper span after `0x005b4eee` was still unsplit.
  - Changed to: `85/88`; parent remains [UID:0000KC][ItemActionInputPanes](by-file/ItemActionInputPanes.md).
  - Evidence: Batch253 created [UID:0003FN][0x005b4ef0-0x005b4f6c.SendGiveAllItemPacketRaw](by-memory/0x005b4ef0-0x005b4f6c.SendGiveAllItemPacketRaw.md), documented exact padding around it, and verified the no-function/no-xref/no-pointer give-all packet helper body, opcode `0x29`, mode byte `1`, busy gate, and three-byte send behavior.
