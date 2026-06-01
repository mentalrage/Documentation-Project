*** UID:0000EN | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:76 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:78 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# TextEditObject

## Status

- Confidence: strong for class behavior; medium for exact original file split.
- Likely source file: [UID:0000ON][TextEditPane](by-file/TextEditPane.md)
- Main address ranges: `0x00594e60-0x00594f10` and `0x00595670-0x005956ad`
- Current recovered file: `source-3/simroot_v2/class_TextEditObject.cpp`

## Class Purpose

`TextEditObject` is the base object for text-edit payloads or inline objects. It derives from `LObject`, stores an owner/type handle, installs a `TextEditObject` vtable, and provides a no-op virtual update hook that derived classes can override.

## Method Families

| Address | Function | Role |
| --- | --- | --- |
| `0x00594e60-0x00594e98` | `TextEditObject::TextEditObject` | Constructs `LObject`, stores owner/type handle, installs vtable, and initializes owned pointers/state. |
| `0x00594f10-0x00594f10` | `TextEditObject::OnUpdate` | No-op virtual stub. |
| `0x00595670-0x005956ad` | scalar deleting destructor | Deleting-destructor vtable entry. |

## Evidence Notes

- `EPFTextEditObject` inherits the same base shape and initializes `TextEditObject` fields before loading symbol frames.
- The class is tightly located next to `TextEditScrap` and `EPFTextEditObject`, supporting placement under the text-edit implementation module.

## Cross-References

- [UID:0000ON][TextEditPane](by-file/TextEditPane.md)
- [UID:00004H][EPFTextEditObject](by-class/EPFTextEditObject.md)
- [UID:0001JT][0x00594e60-0x005958fe.TextEditSupportObjectsAndFilter](by-memory/0x00594e60-0x005958fe.TextEditSupportObjectsAndFilter.md)

## Changes

- Before: completion/confidence were unevaluated at `0/0`.
- Changed to: completion `76`, confidence `78`.
- Evidence: the page documents the base-object role, likely owner, constructor/no-op/destructor ranges, inheritance context, and support-object memory cluster; completion remains limited because exact file split and derived-object field semantics are not fully detailed.
