*** UID:00006Q | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:78 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# InternetError

## Status

- Confidence: strong for class responsibility and shared error-module placement.
- Current Wave3 file: `class_InternetError.cpp`
- Likely source module: [UID:0000J5][Error](by-file/Error.md)
- Current range: [UID:00013X][0x004a60d0-0x004a6a76.ErrorWrappers](by-memory/0x004a60d0-0x004a6a76.ErrorWrappers.md)
- Vtable anchor: RTTI `0x00619400`, vtable `0x00619404`
- Evidence basis: existing by-memory/by-type documentation and recorded IDA MCP checks through 2026-06-03.

## Responsibility

`InternetError` is a base WinINet-related error object. It loads WinINet/system error text and stores it in an internal string for later copy-out.

## Important Methods

| Address | Current name | Notes |
| --- | --- | --- |
| `0x004a6550` | `InternetError` | Initializes base object, loads `WININET.DLL`, formats last error, and stores text. |
| `0x004a6670` | `GetErrorText` | Copies stored error text to a caller buffer. |

## Ownership Notes

Keep this wrapper in `util/Error.cpp`. HTTP/download modules should construct it but not absorb the generic WinINet error class.

2026-05-26 IDA MCP recheck reports `InternetError::InternetError` at `0x004a6550` as a real `0x11a`-byte function, `GetErrorText` at `0x004a6670` as a real `0x1e`-byte function, and the vtable write/xref to `0x00619404` at `0x004a65a2`.

The exact constructor page [UID:0002HN][0x004a6550-0x004a666a.InternetErrorConstructor](by-memory/0x004a6550-0x004a666a.InternetErrorConstructor.md) now records the half-open range, `WININET.DLL`, `LoadLibraryW`/`FormatMessageW` slot roles, fallback text fragments, owned `SimpleUString` member at `+0x04`, vtable slots, and `httpget::Notification` allocation caller. [UID:0001UE][ErrorObjectLayouts](by-type/by-struct/ErrorObjectLayouts.md) and [UID:0001XI][ErrorHierarchyVtables](by-type/by-vtable/ErrorHierarchyVtables.md) carry the shared layout/vtable context for this wrapper family.

## Autogen Status

Autogen parent is intentionally blank under the strict `85/85` child/direct-parent gate. The direct source parent is [UID:0000J5][Error](by-file/Error.md), which clears the parent side at `87/85`, but this class remains `78/86` and therefore fails the child side.

C++ stays blank because the WinINet formatting locals, `GetErrorText` body, shared string-wrapper declaration, and final source spelling are not final-source quality.

## Cross-References

- [UID:0000J5][Error](by-file/Error.md)
- [UID:00006P][InternetConnectionError](by-class/InternetConnectionError.md)
- [UID:00013X][0x004a60d0-0x004a6a76.ErrorWrappers](by-memory/0x004a60d0-0x004a6a76.ErrorWrappers.md)
- [UID:0001XI][ErrorHierarchyVtables](by-type/by-vtable/ErrorHierarchyVtables.md)

## Changes

- 2026-06-10 A002 strict-gate and evidence refresh:
  - Before: `COMPLETION:74`, `CONFIDENCE:86`, `AUTOGEN_PARENT_UID:0000J5`, and `AUTOGEN_PARENT_POSITION_OPTIONAL:180`.
  - After: `COMPLETION:78`, `CONFIDENCE:86`, with parent metadata cleared.
  - Reason: the direct source parent [UID:0000J5][Error](by-file/Error.md) clears the parent side at `87/85`, but this class remains below the child completion gate at `78/86`; assignment must wait for a fuller method/destructor/source-shape pass.
  - Evidence: existing exact constructor page [UID:0002HN][0x004a6550-0x004a666a.InternetErrorConstructor](by-memory/0x004a6550-0x004a666a.InternetErrorConstructor.md), [UID:0001UE][ErrorObjectLayouts](by-type/by-struct/ErrorObjectLayouts.md), and [UID:0001XI][ErrorHierarchyVtables](by-type/by-vtable/ErrorHierarchyVtables.md) now provide more detailed written support than the old class row, but `GetErrorText`, the shared destructor slot, and final source naming remain incomplete. No new live IDA evidence was used.
- Completion/confidence score update: existed before as `0/0`; changed to `74/86`. Summary: WinINet/system-error wrapper responsibility, constructor/text-copy methods, vtable anchor, module placement, and IDA recheck evidence are documented with strong confidence; remaining work is final C++ body reconstruction and full error-hierarchy integration. Evidence: `ErrorWrappers`, `ErrorHierarchyVtables`, `InternetConnectionError`, function starts `0x004a6550`/`0x004a6670`, and vtable `0x00619404`.
- 2026-06-02 autogen ownership:
  - Before: reconstructable and parent metadata were blank.
  - After: marked reconstructable and attached to [UID:0000J5][Error](by-file/Error.md), leaving C++ blank.
  - Summary/evidence: strong constructor/text-copy/vtable evidence supports shared `Error.cpp` ownership; downloader/cash-shop code remains caller-side.
