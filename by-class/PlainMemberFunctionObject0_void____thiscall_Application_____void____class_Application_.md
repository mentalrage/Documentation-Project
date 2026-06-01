*** UID:0000AJ | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:68 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:82 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# PlainMemberFunctionObject0_void____thiscall_Application_____void____class_Application_

## Status

- Confidence: strong for zero-argument `Application` callback wrapper role.
- Likely source: [UID:0000JO][FunctionObjects](by-file/FunctionObjects.md) template support, instantiated by [UID:0000HG][Application](by-file/Application.md) paths.
- Current recovered file: `source-3/simroot_v2/class_PlainMemberFunctionObject0_void____thiscall_Application_____void____class_Application_.cpp`
- Related memory: [UID:0000YU][0x004671a0-0x004673f6.ApplicationFunctionObject0Callbacks](by-memory/0x004671a0-0x004673f6.ApplicationFunctionObject0Callbacks.md)

## Class Purpose

This generated class binds a zero-argument `Application` member function to a small callback object. Existing Wave2 notes mention this family around deferred `Application::RequestExit` behavior, and active generated source exposes the generic invoke/object-size virtuals.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| `Invoke` | `0x004671a0-0x004671ad` | Applies the stored `this` adjustment and calls the captured `Application` member callback. |
| `GetObjectSize` | `0x004673f0-0x004673f6` | Returns the 24-byte callback object size. |

## Evidence Notes

- IDA `lookup_funcs` confirms `0x004671a0` as a real `0x0d` byte function.
- IDA `xrefs_to 0x004671a0` and `0x004673f0` reports vtable/data references, not direct feature calls.
- The generated layout contains callback pointer, object pointer bytes, `this` adjustment, and a reserved size slot.

## Cross-References

- [UID:0000JO][FunctionObjects](by-file/FunctionObjects.md)
- [UID:00005L][FunctionObject0](by-class/FunctionObject0.md)
- [UID:0001WQ][FunctionObjectTemplates](by-type/by-template/FunctionObjectTemplates.md)
- [UID:00000D][Application](by-class/Application.md)

## Changes

- Before: completion/confidence metadata were `0/0` despite the page documenting this as a zero-argument `Application` callback wrapper with concrete invoke and size virtuals.
- Changed to: `COMPLETION:68` and `CONFIDENCE:82`.
- Evidence: IDA-confirmed function starts, vtable/data xrefs, object-size virtual, generated callback layout, and `FunctionObjects`/`Application` placement are documented; completion remains moderate because the exact allocation/caller context and original template instantiation naming are not exhaustive.
