*** UID:000040 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:76 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# DoubleParamMemberFunctionObject0_void____thiscall_UserPane_____signed_char__h43ff6c8e0528

## Status

- Confidence: strong for `UserPane` drop/give confirmation callback role.
- Likely source: [UID:0000JO][FunctionObjects](by-file/FunctionObjects.md) template support, instantiated by drop/give input pane code.
- Current recovered file: `source-3/simroot_v2/class_DoubleParamMemberFunctionObject0_void____thiscall_UserPane_____signed_char__h43ff6c8e0528.cpp`
- Related memory: [UID:0001N5][0x005b77b0-0x005b77c8.UserPaneDoubleParamCallback](by-memory/0x005b77b0-0x005b77c8.UserPaneDoubleParamCallback.md)

## Class Purpose

This generated callback wrapper binds a `UserPane` member function with two captured arguments: a signed slot-like byte and a boolean. Existing Wave2 report text ties the construction sites to drop/give confirmation paths.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| `Invoke` | `0x005b77b0-0x005b77c8` | Applies the stored object adjustment and calls the captured `UserPane` callback with the stored signed-char and bool values. |

## Evidence Notes

- IDA `lookup_funcs 0x005b77b0` confirms a real `0x18` byte function.
- IDA `xrefs_to 0x005b77b0` reports a vtable/data reference at `0x00630a84`.
- The generated layout is 24 bytes: vtable, callback pointer, object base, object adjustment, signed-char argument, and bool argument.

## Cross-References

- [UID:0000JO][FunctionObjects](by-file/FunctionObjects.md)
- [UID:0001WQ][FunctionObjectTemplates](by-type/by-template/FunctionObjectTemplates.md)
- [UID:0000FQ][UserPane](by-class/UserPane.md)
- [UID:000044][DropInputPane](by-class/DropInputPane.md)
- [UID:00005U][GiveInputPane](by-class/GiveInputPane.md)

## Changes

- 2026-05-30:
  - Before: completion/confidence metadata was left at unevaluated `0/0`.
  - After: scored as `76/84`.
  - Summary/evidence: callback wrapper role, invoke method, vtable xref, generated layout, and drop/give `UserPane` construction-site ownership are documented; remaining uncertainty is final source-facing template/header spelling.
