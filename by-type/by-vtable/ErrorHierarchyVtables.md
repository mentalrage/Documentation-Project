*** UID:0001XI | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# Error Hierarchy Vtables

## Status

- Confidence: strong for the slot map and main wrapper vtable run; medium for final source-level virtual names.
- Current entity kind: vtable/layout evidence for the shared [UID:0000J5][Error](by-file/Error.md) hierarchy.
- Likely owner header/source: `util/Error.h` / `util/Error.cpp`.
- Exact memory data: [UID:0002ND][0x00619344-0x00619448.ErrorHierarchyVtableData](by-memory/0x00619344-0x00619448.ErrorHierarchyVtableData.md) and [UID:0002NE][0x006125a8-0x006125bc.PasswordErrorVtableData](by-memory/0x006125a8-0x006125bc.PasswordErrorVtableData.md).
- Evidence basis: IDA MCP disassembly, xrefs, decompilation, `strings`, and `py_eval` symbol/dword lookup through 2026-05-31. `wave3.py` was not executed for this pass.

## Common Slot Shape

The small error hierarchy uses a five-slot virtual interface after the MSVC RTTI pointer:

| Slot | Role hypothesis | Notes |
| --- | --- | --- |
| `+0x00` | scalar deleting destructor | Different subclasses use different destructor helpers depending on owned storage. |
| `+0x04` | inherited `LObject`/runtime virtual | All observed tables use `0x004f4b10`. |
| `+0x08` | no-op virtual | All observed tables use `nullsub_18`. |
| `+0x0c` | copy/format message into caller buffer | Base [UID:00004J][Error](by-class/Error.md) is pure virtual here; concrete classes format or copy stored text. |
| `+0x10` | error name or descriptor | Most wrappers use `0x004a6a70`; [UID:0000A8][PasswordError](by-class/PasswordError.md) uses a descriptor helper at `0x00467400`. |

## Main Vtable Run

IDA disassembles one contiguous `.rdata` run from `0x00619340` through `0x00619448`. The exact vtable-data child is [UID:0002ND][0x00619344-0x00619448.ErrorHierarchyVtableData](by-memory/0x00619344-0x00619448.ErrorHierarchyVtableData.md):

| Class | RTTI pointer | Vtable | Destructor | Message slot | Name/descriptor slot |
| --- | --- | --- | --- | --- | --- |
| [UID:00004J][Error](by-class/Error.md) | `0x00619340` | `0x00619344` | `0x004a68e0` | `__purecall` | `0x004a6a70` |
| [UID:0000G7][Win32Error](by-class/Win32Error.md) | `0x00619358` | `0x0061935c` | `0x004a68a0` | `0x004a6100` | `0x004a6a70` |
| [UID:00003W][DIError](by-class/DIError.md) | `0x00619370` | `0x00619374` | `0x004a68a0` | `0x004a61e0` | `0x004a6a70` |
| [UID:00003L][DDError](by-class/DDError.md) | `0x00619388` | `0x0061938c` | `0x004a68a0` | `0x004a6290` | `0x004a6a70` |
| [UID:000045][DSError](by-class/DSError.md) | `0x006193a0` | `0x006193a4` | `0x004a68a0` | `0x004a6360` | `0x004a6a70` |
| [UID:00004K][ErrorMessage](by-class/ErrorMessage.md) | `0x006193b8` | `0x006193bc` | `0x004a6920` | [UID:00013Z][0x004a6410-0x004a6429.ErrorMessageCopyMessage](by-memory/0x004a6410-0x004a6429.ErrorMessageCopyMessage.md) | `0x004a6a70` |
| [UID:00004X][FileError](by-class/FileError.md) | `0x006193d0` | `0x006193d4` | `0x004a6970` | [UID:000140][0x004a6480-0x004a6499.FileErrorCopyMessage](by-memory/0x004a6480-0x004a6499.FileErrorCopyMessage.md) | `0x004a6a70` |
| [UID:0000GB][WSAError](by-class/WSAError.md) | `0x006193e8` | `0x006193ec` | `0x004a68a0` | `0x004a64d0` | `0x004a6a70` |
| [UID:00006Q][InternetError](by-class/InternetError.md) | `0x00619400` | `0x00619404` | `0x004a69c0` | `0x004a6670` | `0x004a6a70` |
| [UID:00006P][InternetConnectionError](by-class/InternetConnectionError.md) | `0x00619418` | `0x0061941c` | `0x004a69c0` | `0x004a6780` | `0x004a6a70` |
| [UID:00008V][MyError](by-class/MyError.md) | `0x00619430` | `0x00619434` | `0x004a6a10` | `0x004a6840` | `0x004a6a70` |

`0x00619448` is adjacent non-vtable data, not another slot in the `MyError` table.

## PasswordError Vtable

[UID:0000A8][PasswordError](by-class/PasswordError.md) is outside the main `0x00619340` run. The exact vtable-data child is [UID:0002NE][0x006125a8-0x006125bc.PasswordErrorVtableData](by-memory/0x006125a8-0x006125bc.PasswordErrorVtableData.md):

| Class | RTTI pointer | Vtable | Destructor | Message slot | Descriptor slot |
| --- | --- | --- | --- | --- | --- |
| [UID:0000A8][PasswordError](by-class/PasswordError.md) | `0x006125a4` | `0x006125a8` | `0x00467300` | `0x004a6840` | `0x00467400` |

IDA `py_eval` resolves `??_7PasswordError@@6B@` to `0x006125a8`, and `xrefs_to 0x006125a8` finds the constructor write at `0x00467172`. The descriptor helper at `0x00467400` returns `0x006125bc`, which points to descriptor/string data for the password-warning label. It is not the vtable pointer itself.

## Data Caveats

- `DIError::DIError` at `0x004a61b0`, `DSError::DSError` at `0x004a6330`, and `ErrorMessage::ErrorMessage` at `0x004a63e0` remain constructor-shaped raw code, not IDA function records.
- Generated `class_PasswordError.cpp` currently emits `GetErrorDescriptor` as returning `&PasswordError_vtable`; IDA proves the function returns `0x006125bc` descriptor data instead.
- [UID:00013Z][0x004a6410-0x004a6429.ErrorMessageCopyMessage](by-memory/0x004a6410-0x004a6429.ErrorMessageCopyMessage.md) and [UID:000140][0x004a6480-0x004a6499.FileErrorCopyMessage](by-memory/0x004a6480-0x004a6499.FileErrorCopyMessage.md) are real vtable slot helpers for `ErrorMessage` and `FileError`, but current generated output omits one or both from the active class files.

## Cross-References

- [UID:0002ND][0x00619344-0x00619448.ErrorHierarchyVtableData](by-memory/0x00619344-0x00619448.ErrorHierarchyVtableData.md)
- [UID:0002NE][0x006125a8-0x006125bc.PasswordErrorVtableData](by-memory/0x006125a8-0x006125bc.PasswordErrorVtableData.md)
- [UID:0001UE][ErrorObjectLayouts](by-type/by-struct/ErrorObjectLayouts.md)
- [UID:0000J5][Error](by-file/Error.md)
- [UID:00013Z][0x004a6410-0x004a6429.ErrorMessageCopyMessage](by-memory/0x004a6410-0x004a6429.ErrorMessageCopyMessage.md)
- [UID:000140][0x004a6480-0x004a6499.FileErrorCopyMessage](by-memory/0x004a6480-0x004a6499.FileErrorCopyMessage.md)
- [UID:00013X][0x004a60d0-0x004a6a76.ErrorWrappers](by-memory/0x004a60d0-0x004a6a76.ErrorWrappers.md)
- [UID:0000YS][0x004657d0-0x00467406.PasswordGuardAndFatalError](by-memory/0x004657d0-0x00467406.PasswordGuardAndFatalError.md)
- [Wave3 data issues](../../wave3_data_issues.md)

## Changes

- 2026-05-31:
  - What existed before: metadata was unevaluated at `0/0`, and the vtable inventory did not have exact by-memory child pages for the main hierarchy run or the separate `PasswordError` table.
  - Changed to: `COMPLETION:84`, `CONFIDENCE:88`, `RECONSTRUCTABLE:TRUE`, plus exact memory children [UID:0002ND][0x00619344-0x00619448.ErrorHierarchyVtableData](by-memory/0x00619344-0x00619448.ErrorHierarchyVtableData.md) and [UID:0002NE][0x006125a8-0x006125bc.PasswordErrorVtableData](by-memory/0x006125a8-0x006125bc.PasswordErrorVtableData.md).
  - Summary/evidence: IDA MCP verified vtable globals, slot dwords, constructor/store xrefs, function sizes for virtual targets, the `0x00619448` string boundary, and the `0x006125bc` descriptor boundary. Confidence remains below final audit because some source-level virtual names and raw constructor starts remain unresolved.
