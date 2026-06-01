*** UID:00005N | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:70 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:82 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# FunctionObjectT_near_class_mystr__StringBase_wchar_t__struct_mystr__mychar_traits_wchar_t____const___

## Status

- Confidence: strong for const-reference string callback-base support.
- Likely source: [UID:0000JO][FunctionObjects](by-file/FunctionObjects.md)
- Current recovered file: `source-3/simroot_v2/class_FunctionObjectT_near_class_mystr__StringBase_wchar_t__struct_mystr__mychar_traits_wchar_t____const___.cpp`
- Related memory: [UID:0001CS][0x0052f780-0x0052f7fe.FunctionObjectTConstStringDestructors](by-memory/0x0052f780-0x0052f7fe.FunctionObjectTConstStringDestructors.md)

## Class Purpose

This generated instantiation represents `FunctionObjectT<const mystr::StringBase<wchar_t, mystr::mychar_traits<wchar_t>>&>`. It is callback-template support for passing strings by const reference.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| scalar deleting destructor | `0x0052f780-0x0052f7be` | Resets the string-function-object vtable, destroys `LObject`, and conditionally deletes storage with a `flags & 4` guard. |
| scalar deleting destructor | `0x0052f7c0-0x0052f7fe` | Similar emitted destructor body without the `flags & 4` guard. |

## Evidence Notes

- IDA `xrefs_to 0x0052f780` reports a data/vtable reference, consistent with virtual destructor support.
- Current generated source has two nearby destructor variants. Treat them as emitted template support until final type recovery explains the exact vtable split.

## Cross-References

- [UID:0000JO][FunctionObjects](by-file/FunctionObjects.md)
- [UID:0001WQ][FunctionObjectTemplates](by-type/by-template/FunctionObjectTemplates.md)
- [UID:0000OB][StringUtil](by-file/StringUtil.md)

## Changes

- Completion/confidence score update: existed before as `0/0`; changed to `70/82`. Summary: const-reference string callback-template purpose, destructor variants, vtable-reference evidence, and generated-support caveat are documented; full template split and exact vtable distinction remain open. Evidence: memory page `0x0052f780-0x0052f7fe`, IDA vtable xref note, and FunctionObject template documentation.
