*** UID:00005L | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:72 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# FunctionObject0

## Status

- Confidence: strong for zero-argument callback-base role.
- Likely source: [UID:0000JO][FunctionObjects](by-file/FunctionObjects.md)
- Current recovered file: `source-3/simroot_v2/class_FunctionObject0.cpp`
- Related memory: [UID:0000YU][0x004671a0-0x004673f6.ApplicationFunctionObject0Callbacks](by-memory/0x004671a0-0x004673f6.ApplicationFunctionObject0Callbacks.md)

## Class Purpose

`FunctionObject0` is the zero-argument callback-object base. It supplies destructor support and a pure-virtual slot used by derived callback wrappers such as the `Application` zero-argument member-function object.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| scalar deleting destructor | `0x004671f0-0x0046722d` | Resets the vtable, destroys the `LObject` base, and conditionally deletes storage. |
| scalar deleting destructor | `0x004672c0-0x004672fd` | Duplicate emitted destructor body with the same behavior. |
| pure virtual call slot | `0x005ca28c-0x005ca2a6` | Calls `_purecall()` and aborts if the abstract slot is invoked. |

## Evidence Notes

- `simroot_v2/class_FunctionObject0.cpp` emits both destructor bodies and the pure-virtual helper.
- IDA `lookup_funcs` confirms `0x005ca28c` as `__purecall` sized `0x1b`.
- The related `PlainMemberFunctionObject0<Application>` derived wrapper has an `Invoke` method at `0x004671a0` and an object-size virtual at `0x004673f0`.

## Cross-References

- [UID:0000JO][FunctionObjects](by-file/FunctionObjects.md)
- [UID:0001WQ][FunctionObjectTemplates](by-type/by-template/FunctionObjectTemplates.md)
- [UID:0000AJ][PlainMemberFunctionObject0_void____thiscall_Application_____void____class_Application_](by-class/PlainMemberFunctionObject0_void____thiscall_Application_____void____class_Application_.md)

## Changes

- Completion/confidence score update: existed before as `0/0`; changed to `72/84`. Summary: zero-argument callback-base role, destructor variants, pure virtual slot, and related derived wrapper are documented with strong confidence; remaining gaps are final header/source template organization and full callback-family mapping. Evidence: related memory page `0x004671a0-0x004673f6`, `__purecall` range `0x005ca28c-0x005ca2a6`, and `PlainMemberFunctionObject0<Application>` cross-reference.
