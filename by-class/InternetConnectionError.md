*** UID:00006P | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:85 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000J5 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# InternetConnectionError

## Status

- Confidence: strong for class responsibility and shared error-module placement.
- Current Wave3 file: `class_InternetConnectionError.cpp`
- Direct source module: [UID:0000J5][Error](by-file/Error.md)
- Current range: [UID:00013X][0x004a60d0-0x004a6a76.ErrorWrappers](by-memory/0x004a60d0-0x004a6a76.ErrorWrappers.md)
- Vtable anchor: RTTI `0x00619418`, vtable `0x0061941c`
- Evidence basis: `simroot_v2`, Wave3 summary, and IDA MCP checks on 2026-05-23.

## Responsibility

`InternetConnectionError` captures extended WinINet response information and stores the text for display/copy-out.

## Important Methods

| Address | Current name | Notes |
| --- | --- | --- |
| `0x004a6690` | `InternetConnectionError` | Calls `InternetGetLastResponseInfoA`, converts text to wide, and stores it. |
| `0x004a6780` | `CopyErrorMessage` | Copies the stored wide message. |

## Layout And Vtable Evidence

This class uses the `SimpleUString`-message storage family also used by [UID:00006Q][InternetError](by-class/InternetError.md). The object has the vtable pointer at `+0x00` and the owned string object at `+0x04`; the shared string-subobject destructor at `0x004a69c0` services both `InternetError` and `InternetConnectionError`.

IDA MCP recheck on 2026-06-07 reports:

- `InternetConnectionError::InternetConnectionError` is still the exact `0x004a6690-0x004a6772` modeled function, and `CopyErrorMessage` is still `0x004a6780-0x004a679e`.
- The constructor stores vtable `0x0061941c` at `0x004a66da`, calls `InternetGetLastResponseInfoA` at `0x004a6708`, and uses the neighboring string helpers at `0x00582b20`, `0x00582730`, `0x00582830`, `0x00582c60`, `0x00582b70`, and `0x00582b30`.
- The vtable run has RTTI at `0x00619418`, vtable base `0x0061941c`, destructor slot `0x004a69c0`, message-copy slot `0x004a6780` at `0x00619428`, and common name/descriptor helper `0x004a6a70` at `0x0061942c`.
- `CopyErrorMessage` calls `0x00584540` before `_wcscpy_s`, matching the stored wide-message copy-out behavior.
- The broader `Error.cpp` raw-constructor caveats remain: `0x004a61b0`, `0x004a6330`, and `0x004a63e0` still have no IDA function objects. They do not block this class assignment because the direct parent page now records the caveat and still clears the strict gate.

## Ownership Notes

This is a specialization of the internet error family. Keep it in the shared error module and let HTTP/download code reference it.

2026-05-26 IDA MCP recheck reports `InternetConnectionError::InternetConnectionError` at `0x004a6690` as a real `0xe2`-byte function, `CopyErrorMessage` at `0x004a6780` as a real `0x1e`-byte function, and the vtable write/xref to `0x0061941c` at `0x004a66da`.

## Assignment Gate

`AUTOGEN_PARENT_UID` is set to [UID:0000J5][Error](by-file/Error.md). The class now clears `85/88`, the direct file parent was refreshed to `87/85`, and the parent page directly owns the shared error hierarchy. Final C++ stays blank because helper names, broader virtual declarations, and sibling raw-constructor records are not final-source quality.

## Cross-References

- [UID:0000J5][Error](by-file/Error.md)
- [UID:00006Q][InternetError](by-class/InternetError.md)
- [UID:00013X][0x004a60d0-0x004a6a76.ErrorWrappers](by-memory/0x004a60d0-0x004a6a76.ErrorWrappers.md)
- [UID:0001XI][ErrorHierarchyVtables](by-type/by-vtable/ErrorHierarchyVtables.md)

## Changes

- 2026-06-05: Marked `RECONSTRUCTABLE:TRUE` after live IDA MCP on `NexusTK.exe` confirmed the WinINet response-error constructor at `0x004a6690` and copy method at `0x004a6780`. Left `AUTOGEN_PARENT_UID` blank because this class is below the 80 completion attachment gate even though [UID:0000J5][Error](by-file/Error.md) is the likely source-module parent.
- Completion/confidence score update: existed before as `0/0`; changed to `74/86`. Summary: WinINet response-error responsibility, constructor/copy method behavior, vtable anchor, shared error-module placement, and IDA recheck evidence are documented with strong confidence; remaining work is final C++ body reconstruction and broader hierarchy integration. Evidence: `ErrorWrappers`, `ErrorHierarchyVtables`, `InternetError`, function starts `0x004a6690`/`0x004a6780`, and vtable `0x0061941c`.
- 2026-06-07 Agent-A002 Batch 091 parent-gate pass:
  - Before: `74/86`, reconstructable but unassigned, with only a short constructor/copy summary.
  - Changed to: `85/88` and `AUTOGEN_PARENT_UID:0000J5`.
  - Summary/evidence: live IDA MCP reconfirmed exact constructor/copy bounds, the vtable store at `0x004a66da`, WinINet response-info call, string-helper call family, copy-out through `_wcscpy_s`, and the `SimpleUString` storage/destructor family. Direct parent [UID:0000J5][Error](by-file/Error.md) now clears `87/85`; final C++ remains blank until the broader error hierarchy declarations and helper names are final.
