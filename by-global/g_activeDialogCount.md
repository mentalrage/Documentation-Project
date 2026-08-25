*** UID:0000PQ | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000IT | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000IT | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
signed char g_activeDialogCount;
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
extern signed char g_activeDialogCount;
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# g_activeDialogCount / byte_69B380
## UID0000LU Signed Declaration Resolution - 2026-08-15

The final owner route is one loader-zero definition `signed char g_activeDialogCount;` in DialogPane CPP and one declaration `extern signed char g_activeDialogCount;` in DialogPane H. Signed positive-only consumers remain exact: values greater than zero block immediate actions, while zero or negative values permit them.

Fresh PE/IDA evidence in UID0001PH proves loader-zero initialization. Earlier `0xff` initial-value wording is retained below only as a superseded evidence-time assumption, not current initialization authority. Inventory, NewSpell, and take-off modules remain consumers and create no storage.

## Status

- Confidence: strong for address, DialogPane ownership, one-byte boundary, full direct-xref set, mutator/consumer split, and gating behavior at the documented call sites; medium-high for the final source declaration/type because the byte is initialized to `0xff`.
- Address: `0x0069b380`
- Size: 1 byte
- IDA name: `byte_69B380`
- Primary memory doc: [UID:0001PH][0x0069b380-0x0069b381.g_activeDialogCount](by-memory/0x0069b380-0x0069b381.g_activeDialogCount.md)
- Owner: [UID:0000IT][DialogPane](by-file/DialogPane.md) shared dialog lifetime state. This child now clears `86/88`, and the direct parent clears `86/85`, so retaining `AUTOGEN_PARENT_UID:0000IT` satisfies the strict `85/85` child/parent gate.
- Autogen parent: [UID:0000IT][DialogPane](by-file/DialogPane.md); C++ remains blank because the signed/bias convention and final declaration form are below the `95+` source gate.

## Purpose

This byte is maintained by common `DialogPane` lifetime code and gates some UI-driven packet sends. `TakeOffInputPane`, inventory, and spell inventory consumers only perform immediate actions when this byte is not positive (`byte_69B380 <= 0`).

The current generated name `g_activeDialogCount` is now strongly supported as dialog lifetime state, but not final-source quality. The initial static byte is `0xff`, so the final declaration may need an explicit signed type or bias convention instead of a plain unsigned count.

## Evidence Notes

- IDA `py_eval` on 2026-05-27 read the initial byte at `0x0069b380` as `0xff`; [UID:0001PH][0x0069b380-0x0069b381.g_activeDialogCount](by-memory/0x0069b380-0x0069b381.g_activeDialogCount.md) records a later IDA-backed refresh with neighboring bytes and direct xrefs.
- [UID:0001PH][0x0069b380-0x0069b381.g_activeDialogCount](by-memory/0x0069b380-0x0069b381.g_activeDialogCount.md) is scored `88/91` and documents 13 direct data xrefs: the `DialogPane` constructor increments the byte at `0x0049d902`, the `DialogPane` destructor decrements it at `0x0049da31`, and inventory/spell/item-action consumers only compare it as an input/action gate.
- The same storage page records live bytes for `0x0069b378-0x0069b39c`, splits the preceding two main-UI layer slots at `0x0069b378-0x0069b380`, and records no direct refs to `0x0069b381`, keeping this global to one byte.
- IDA xrefs include `0x005b27d3` in [UID:0001M2][0x005b27c0-0x005b2827.SendTakeOffPacket](by-memory/0x005b27c0-0x005b2827.SendTakeOffPacket.md) and `0x005b2914` in [UID:0000EC][TakeOffInputPane](by-class/TakeOffInputPane.md).
- B006 2026-06-21 source-quality recheck of [UID:0001M2][0x005b27c0-0x005b2827.SendTakeOffPacket](by-memory/0x005b27c0-0x005b2827.SendTakeOffPacket.md) confirms the first-draft helper should preserve the signed gate as `if (g_activeDialogCount <= 0)`. Do not model this consumer as `uint8_t`, `if (!g_activeDialogCount)`, or `== 0`; the initial `0xff` byte and signed `jg` skip condition require positive-only active-dialog blocking semantics.
- The reviewed mutators are in [UID:0000IT][DialogPane](by-file/DialogPane.md); inventory, spell, and item-action modules are consumers and should not own the storage. [UID:0000IT][DialogPane](by-file/DialogPane.md) is now `86/85`, with exact base-dialog aggregate support from [UID:00012R][0x0049d8a0-0x0049feae.DialogPane](by-memory/0x0049d8a0-0x0049feae.DialogPane.md) at `86/88`.
- Live IDA MCP on 2026-06-14 rechecked the exact 13 direct xrefs to `0x0069b380`: DialogPane mutators at `0x0049d902` and `0x0049da31`, inventory gates at `0x004ed126`, `0x004ed4e5`, `0x004ed667`, `0x004edce3`, `0x004edd61`, and `0x004ee483`, spell gates at `0x0057ddae`, `0x0057df37`, and `0x0057e633`, and take-off gates at `0x005b27d3` and `0x005b2914`. The recheck found no direct xref from `0x0069b381`, preserving the one-byte storage boundary from the exact memory page.

## Score Rationale

| Field | Value | Rationale |
| --- | ---: | --- |
| Completion | 86 | The page now records exact address/size, one-byte boundary, initial value, constructor/destructor mutators, all 13 direct xrefs, consumer families, direct storage page support, owner rejection for consumer modules, and strict parent-gate status. |
| Confidence | 88 | Address and owner are backed by the exact storage page, DialogPane file page, base-dialog aggregate, and 2026-06-14 live xref recheck. Confidence remains below final levels because the `0xff` initial value leaves the final signed/bias declaration convention unresolved. |
| Parent | [UID:0000IT][DialogPane](by-file/DialogPane.md) | Child `86/88` and direct parent `86/85` clear the strict `85/85` gate, and the nonblank emitter route targets `auto-generated/NexusTK/ui/core/DialogPane.cpp`. |

## Cross-References

- [UID:0001PH][0x0069b380-0x0069b381.g_activeDialogCount](by-memory/0x0069b380-0x0069b381.g_activeDialogCount.md)
- [UID:0000EC][TakeOffInputPane](by-class/TakeOffInputPane.md)
- [UID:0001M2][0x005b27c0-0x005b2827.SendTakeOffPacket](by-memory/0x005b27c0-0x005b2827.SendTakeOffPacket.md)
- [UID:0000KC][ItemActionInputPanes](by-file/ItemActionInputPanes.md)
- [UID:0000IT][DialogPane](by-file/DialogPane.md)

## Changes

- Completion/confidence scoring: existed before as ungraded `0/0`; changed to `78/74`. Summary/evidence: the page documents the byte address, gating behavior, initial value, take-off caller evidence, and related refs, but wider UI/dialog xrefs and final symbol meaning are still unresolved.
- 2026-06-03 DialogPane ownership pass:
  - Before: the global page remained unparented at `78/74`, even though its exact memory page had stronger IDA-backed owner evidence.
  - Changed to: completion/confidence `82/84`, `RECONSTRUCTABLE:TRUE`, and `AUTOGEN_PARENT_UID:0000IT`.
  - Evidence: [UID:0000IT][DialogPane](by-file/DialogPane.md) is `86/80` and documents the common-dialog lifetime owner; [UID:0001PH][0x0069b380-0x0069b381.g_activeDialogCount](by-memory/0x0069b380-0x0069b381.g_activeDialogCount.md) is `86/88`, reconstructable, attached to DialogPane, and records the IDA-confirmed constructor increment, destructor decrement, 13 data xrefs, initial `0xff` byte, and consumer-only reads from inventory/spell/item-action code. C++ remains blank because the final declaration form and signed/bias convention are not at the `95+` code-emission threshold.
- 2026-06-10 A001 strict-gate repair:
  - Changed to: completion/confidence `85/86`, keeping `RECONSTRUCTABLE:TRUE` and `AUTOGEN_PARENT_UID:0000IT`.
  - Evidence: [UID:0001PH][0x0069b380-0x0069b381.g_activeDialogCount](by-memory/0x0069b380-0x0069b381.g_activeDialogCount.md) is now `88/91` with exact one-byte boundary, 13 xrefs, constructor/destructor mutators, and consumer-only gate reads; [UID:0000IT][DialogPane](by-file/DialogPane.md) is now `86/85` with the base aggregate [UID:00012R][0x0049d8a0-0x0049feae.DialogPane](by-memory/0x0049d8a0-0x0049feae.DialogPane.md) at `86/88`. The child and direct parent now clear the strict `85/85` gate.
- 2026-06-14 A003 score refresh:
  - Before: `85/86`; the exact memory page already supported a stronger xref/boundary confidence level.
  - Changed to: `86/88`, retaining [UID:0000IT][DialogPane](by-file/DialogPane.md) as canonical owner/emitter and keeping reconstruction C++ blank.
  - Summary/evidence: live IDA MCP rechecked the exact 13-ref set, including DialogPane constructor/destructor mutators and consumer-only inventory, spell, and take-off gates. Final C++ remains blocked by the `0xff` initial value and unresolved signed/bias declaration convention.
- 2026-06-21 B006 SendTakeOffPacket support sync:
  - Added the source-ready `g_activeDialogCount <= 0` consumer expression for [UID:0001M2][0x005b27c0-0x005b2827.SendTakeOffPacket](by-memory/0x005b27c0-0x005b2827.SendTakeOffPacket.md), preserving the signed/bias caveat and leaving score/ownership unchanged.
