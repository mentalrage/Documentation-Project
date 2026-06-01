*** UID:0000PQ | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:78 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:74 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# g_activeDialogCount / byte_69B380

## Status

- Confidence: medium for final symbol name; strong for address and gating behavior at the documented call sites.
- Address: `0x0069b380`
- Size: 1 byte
- IDA name: `byte_69B380`
- Primary memory doc: [UID:0001PH][0x0069b380-0x0069b381.g_activeDialogCount](by-memory/0x0069b380-0x0069b381.g_activeDialogCount.md)
- Likely owner: shared UI/dialog or input state.

## Purpose

This byte gates some UI-driven packet sends. `TakeOffInputPane` and the shared take-off helper only send equipment-removal packets when this byte is not positive (`byte_69B380 <= 0`).

The current generated name `g_activeDialogCount` is plausible but not final. Wider xrefs span dialog/input and UI code, and the initial static byte is `0xff`, so the final type may be a signed modal/input gate flag rather than a count.

## Evidence Notes

- IDA `py_eval` on 2026-05-27 read the initial byte at `0x0069b380` as `0xff`.
- IDA xrefs include `0x005b27d3` in [UID:0001M2][0x005b27c0-0x005b2827.SendTakeOffPacket](by-memory/0x005b27c0-0x005b2827.SendTakeOffPacket.md) and `0x005b2914` in [UID:0000EC][TakeOffInputPane](by-class/TakeOffInputPane.md).
- Additional xrefs appear in dialog/UI neighborhoods such as `0x0049d8a0`, `0x004ecb50`, `0x0057d9c0`, and `0x0057e620`; those owners need separate review before the final symbol name is locked.

## Cross-References

- [UID:0001PH][0x0069b380-0x0069b381.g_activeDialogCount](by-memory/0x0069b380-0x0069b381.g_activeDialogCount.md)
- [UID:0000EC][TakeOffInputPane](by-class/TakeOffInputPane.md)
- [UID:0001M2][0x005b27c0-0x005b2827.SendTakeOffPacket](by-memory/0x005b27c0-0x005b2827.SendTakeOffPacket.md)
- [UID:0000KC][ItemActionInputPanes](by-file/ItemActionInputPanes.md)

## Changes

- Completion/confidence scoring: existed before as ungraded `0/0`; changed to `78/74`. Summary/evidence: the page documents the byte address, gating behavior, initial value, take-off caller evidence, and related refs, but wider UI/dialog xrefs and final symbol meaning are still unresolved.
