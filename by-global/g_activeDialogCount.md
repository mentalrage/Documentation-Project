*** UID:0000PQ | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:82 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000IT | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# g_activeDialogCount / byte_69B380

## Status

- Confidence: strong for address, DialogPane ownership, and gating behavior at the documented call sites; medium-high for the final source declaration/type because the byte is initialized to `0xff`.
- Address: `0x0069b380`
- Size: 1 byte
- IDA name: `byte_69B380`
- Primary memory doc: [UID:0001PH][0x0069b380-0x0069b381.g_activeDialogCount](by-memory/0x0069b380-0x0069b381.g_activeDialogCount.md)
- Owner: [UID:0000IT][DialogPane](by-file/DialogPane.md) shared dialog lifetime state.
- Autogen parent: [UID:0000IT][DialogPane](by-file/DialogPane.md); C++ remains blank because the signed/bias convention and final declaration form are below the `95+` source gate.

## Purpose

This byte is maintained by common `DialogPane` lifetime code and gates some UI-driven packet sends. `TakeOffInputPane`, inventory, and spell inventory consumers only perform immediate actions when this byte is not positive (`byte_69B380 <= 0`).

The current generated name `g_activeDialogCount` is now strongly supported as dialog lifetime state, but not final-source quality. The initial static byte is `0xff`, so the final declaration may need an explicit signed type or bias convention instead of a plain unsigned count.

## Evidence Notes

- IDA `py_eval` on 2026-05-27 read the initial byte at `0x0069b380` as `0xff`; [UID:0001PH][0x0069b380-0x0069b381.g_activeDialogCount](by-memory/0x0069b380-0x0069b381.g_activeDialogCount.md) records a later 2026-06-02 IDA refresh with neighboring bytes and direct xrefs.
- [UID:0001PH][0x0069b380-0x0069b381.g_activeDialogCount](by-memory/0x0069b380-0x0069b381.g_activeDialogCount.md) documents 13 direct data xrefs: the `DialogPane` constructor increments the byte at `0x0049d902`, the `DialogPane` destructor decrements it at `0x0049da31`, and inventory/spell/item-action consumers only compare it as an input/action gate.
- IDA xrefs include `0x005b27d3` in [UID:0001M2][0x005b27c0-0x005b2827.SendTakeOffPacket](by-memory/0x005b27c0-0x005b2827.SendTakeOffPacket.md) and `0x005b2914` in [UID:0000EC][TakeOffInputPane](by-class/TakeOffInputPane.md).
- The reviewed mutators are in [UID:0000IT][DialogPane](by-file/DialogPane.md); inventory, spell, and item-action modules are consumers and should not own the storage.

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
