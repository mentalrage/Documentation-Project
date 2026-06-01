*** UID:00005M | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:66 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:82 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# FunctionObjectT_class_mystr__StringBase_wchar_t__struct_mystr__mychar_traits_wchar_t_____

## Status

- Confidence: strong for string-argument callback-base support.
- Likely source: [UID:0000JO][FunctionObjects](by-file/FunctionObjects.md)
- Current recovered file: `source-3/simroot_v2/class_FunctionObjectT_class_mystr__StringBase_wchar_t__struct_mystr__mychar_traits_wchar_t_____.cpp`
- Known method address: `0x0052a460-0x0052a49e`

## Class Purpose

This is a generated instantiation of `FunctionObjectT<mystr::StringBase<wchar_t, mystr::mychar_traits<wchar_t>>>`. Current output only exposes scalar deleting destructor support for the string-argument callback base.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| scalar deleting destructor | `0x0052a460-0x0052a49e` | Resets the `FunctionObjectT<StringBase>` vtable, destroys `LObject`, and conditionally deletes storage while respecting the `flags & 4` guard. |

## Evidence Notes

- This method is physically adjacent to [UID:00008U][MusicControlDialog](by-class/MusicControlDialog.md) callback support.
- Existing string documentation previously flagged this generated file as template/deleting-destructor support rather than primary [UID:0000OB][StringUtil](by-file/StringUtil.md) ownership.

## Cross-References

- [UID:0000JO][FunctionObjects](by-file/FunctionObjects.md)
- [UID:0001WQ][FunctionObjectTemplates](by-type/by-template/FunctionObjectTemplates.md)
- [UID:0001CP][0x00528e60-0x0052a535.MusicControlDialog](by-memory/0x00528e60-0x0052a535.MusicControlDialog.md)
- [UID:0000OB][StringUtil](by-file/StringUtil.md)

## Changes

- Completion/confidence score update: existed before as `0/0`; changed to `66/82`. Summary: generated string-argument callback template purpose and scalar destructor behavior are documented, but the page is intentionally narrow and does not yet recover the full template/header structure. Evidence: destructor range `0x0052a460-0x0052a49e`, MusicControlDialog adjacency, and FunctionObject template documentation.
