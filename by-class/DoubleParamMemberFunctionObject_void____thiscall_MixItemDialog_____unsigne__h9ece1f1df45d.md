*** UID:000041 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:76 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:82 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# DoubleParamMemberFunctionObject_void____thiscall_MixItemDialog_____unsigne__h9ece1f1df45d

## Status

- Confidence: strong for generated double-parameter callback role and MixItemDialog construction-site evidence, medium for final template/header naming.
- Likely source: [UID:0000JO][FunctionObjects](by-file/FunctionObjects.md) template support.
- Current recovered file: `source-3/simroot_v2/class_DoubleParamMemberFunctionObject_void____thiscall_MixItemDialog_____unsigne__h9ece1f1df45d.cpp`
- Related memory: [UID:00014W][0x004b0880-0x004b08a1.MixItemDialogDoubleParamCallback](by-memory/0x004b0880-0x004b08a1.MixItemDialogDoubleParamCallback.md)

## Class Purpose

This generated wrapper dispatches a callback with one runtime context argument and two captured small arguments. The expanded metadata name resolves to a `MixItemDialog` member-function wrapper with `unsigned long`, `signed char`, and `unsigned char` argument types.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| `Invoke(unsigned long context)` | `0x004b0880-0x004b08a1` | Calls the stored member callback with the runtime context plus two bound parameters. |

## Evidence Notes

- IDA `lookup_funcs 0x004b0880` confirms a real `0x21` byte function.
- IDA `xrefs_to 0x004b0880` reports a vtable/data reference at `0x0061a3bc`.
- IDA MCP decompilation on 2026-05-25 shows `sub_4AFCC0` and `sub_4B0120` constructing this object in MixItemDialog/AddMixingItemDialog quantity paths and passing it to `NumberInputDialog`.
- Existing exchange-tail docs mention this address because it sits in an interleaved exchange/item/mix tail island. Construction-site evidence now favors MixItemDialog/NumberInput ownership rather than ExchangeAlertPane ownership.

## Cross-References

- [UID:0000JO][FunctionObjects](by-file/FunctionObjects.md)
- [UID:0001WQ][FunctionObjectTemplates](by-type/by-template/FunctionObjectTemplates.md)
- [UID:00008J][MixItemDialog](by-class/MixItemDialog.md)
- [UID:00009K][NumberInputDialog](by-class/NumberInputDialog.md)
- [UID:00014V][0x004b0490-0x004b0ba5.ExchangeDialogTail](by-memory/0x004b0490-0x004b0ba5.ExchangeDialogTail.md)

## Changes

- 2026-05-30:
  - Before: completion/confidence metadata was left at unevaluated `0/0`.
  - After: scored as `76/82`.
  - Summary/evidence: callback wrapper role, invoke method, vtable xref, MixItemDialog construction sites, NumberInputDialog handoff, and exchange-tail ownership caveat are documented; remaining uncertainty is final template/header naming.
