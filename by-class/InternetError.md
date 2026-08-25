*** UID:00006Q | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:85 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000J5 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000J5 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
// InternetError class-level source is covered by [UID:0000J5][Error](by-file/Error.md) and exact constructor child [UID:0002HN][0x004a6550-0x004a666a.InternetErrorConstructor](by-memory/0x004a6550-0x004a666a.InternetErrorConstructor.md); this page emits no standalone partial declaration while the stored-message helper at 0x004a6670 and hierarchy-wide message virtual remain future exact-source work.
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# InternetError

## Status

- Confidence: strong for class responsibility and shared error-module placement.
- Current Wave3 file: `class_InternetError.cpp`
- Likely source module: [UID:0000J5][Error](by-file/Error.md)
- Current range: [UID:00013X][0x004a60d0-0x004a6a76.ErrorWrappers](by-memory/0x004a60d0-0x004a6a76.ErrorWrappers.md)
- Vtable anchor: RTTI `0x00619400`, vtable `0x00619404`
- Evidence basis: existing by-memory/by-type documentation and recorded IDA MCP checks through 2026-06-12.

## Responsibility

`InternetError` is a base WinINet-related error object. It loads WinINet/system error text and stores it in an internal string for later copy-out.

## Important Methods

| Address | Current name | Notes |
| --- | --- | --- |
| `0x004a6550` | `InternetError` | Source-ready exact constructor [UID:0002HN][0x004a6550-0x004a666a.InternetErrorConstructor](by-memory/0x004a6550-0x004a666a.InternetErrorConstructor.md); formal C++ loads `WININET.DLL`, calls `FormatMessageW` with a 255-wide fallback buffer, and assigns `m_message = message`. |
| `0x004a6670` | `GetErrorText` | Copies stored error text to a caller buffer. |
| `0x004a69c0` | shared deleting destructor | Frees the owned `SimpleUString` member at `+0x04`, resets the base `Error` vtable, and runs shared `LObject`/delete handling; this vtable slot is shared with `InternetConnectionError`. |

## Ownership Notes

Keep this wrapper in `util/Error.cpp`. HTTP/download modules should construct it but not absorb the generic WinINet error class.

2026-05-26 IDA MCP recheck reports `InternetError::InternetError` at `0x004a6550` as a real `0x11a`-byte function, `GetErrorText` at `0x004a6670` as a real `0x1e`-byte function, and the vtable write/xref to `0x00619404` at `0x004a65a2`.

The exact constructor page [UID:0002HN][0x004a6550-0x004a666a.InternetErrorConstructor](by-memory/0x004a6550-0x004a666a.InternetErrorConstructor.md) now records the half-open range, `WININET.DLL`, `LoadLibraryW`/`FormatMessageW` slot roles, fallback text fragments, owned `SimpleUString` member at `+0x04`, vtable slots, and `httpget::Notification` allocation caller. [UID:0001UE][ErrorObjectLayouts](by-type/by-struct/ErrorObjectLayouts.md) and [UID:0001XI][ErrorHierarchyVtables](by-type/by-vtable/ErrorHierarchyVtables.md) carry the shared layout/vtable context for this wrapper family.

2026-06-27 B004 source-quality implementation updates that constructor to source-ready formal C++. Live MCP session/database `80de0a67` against `E:\NTK\Resources\NexusTK\NexusTK.exe.i64` confirmed `server_health` ok, the exact `0x11a` modeled range, one caller at `0x0052786c`, `0x00619404` vtable store at `0x004a65a2`, dispatch slots `0x0069be30` / `0x0069be6c` for `LoadLibraryW` / `FormatMessageW`, `0x1800` as `FORMAT_MESSAGE_FROM_HMODULE | FORMAT_MESSAGE_FROM_SYSTEM`, `WININET.DLL` at `0x006195e0`, `General internet error` at `0x006195f8`, the 255-wide local buffer, and the pointer-backed wide `m_message` handle at byte offset `+0x04` initialized by `InitializeEmptyWide` and assigned by `AssignWideLiteral`. The public facade can still be documented as `SimpleUString` while [UID:0002RN][0x005829f0-0x00582d80.StringBaseShareAssignAndAccess](by-memory/0x005829f0-0x00582d80.StringBaseShareAssignAndAccess.md) owns the helper mechanics and [UID:0001W4][SimpleUStringPointerBackedLayout](by-type/by-struct/SimpleUStringPointerBackedLayout.md) documents the one-pointer layout caveat.

2026-06-12 A001 live IDA MCP rechecked the direct class-gate facts. `0x004a6550` remains a modeled `0x11a` constructor ending at `0x004a666a`, `0x004a6670` remains a modeled `0x1e` `GetErrorText` function, and `0x004a69c0` remains a modeled `0x48` shared deleting destructor. The constructor has a single ordinary caller at `0x0052786c` in `sub_5277C0`, writes `??_7InternetError@@6B@` at `0x004a65a2`, initializes/copies the `+0x04` string through `0x00582b20` and `0x00582d20`, loads `WININET.DLL`, calls the resolver slots mapped to `LoadLibraryW` and `FormatMessageW`, and uses fallback string data that decodes to `General internet error`. `GetErrorText` calls `0x00584540(this + 4)` and `_wcscpy_s`, while the shared destructor calls `0x00582b70(this + 4)`, restores the base `Error` vtable at `0x00619344`, and then follows the shared base/delete path. Vtable xrefs confirm `0x00619404` points to the destructor, `0x00619410` points to `GetErrorText`, and `0x00619414` points to the shared error-name helper.

2026-06-19 B013 keeps local `GetErrorText` as a behavior label but warns that the vtable `+0x0c` slot should be standardized across the hierarchy before final source. If the project chooses a single virtual spelling, this helper can be modeled as the `InternetError` implementation of `FormatErrorMessage(wchar_t *destination, size_t destinationChars) const`, copying from the `SimpleUString` member at `+0x04`.

## Autogen Status

Autogen parent is [UID:0000J5][Error](by-file/Error.md). This class now clears `85/88`, the direct source parent clears `87/85`, and the shared WinINet wrapper methods/layout belong to the `util/Error.cpp` hierarchy rather than to HTTP/download caller modules.

Class-level C++ stays blank because `0x004a6670`, the shared string-member destructor/declaration shape, exact historical member typedef spelling, and the hierarchy-wide `+0x0c` virtual name are not final-source quality. This class-level no-code policy does not block [UID:0002HN][0x004a6550-0x004a666a.InternetErrorConstructor](by-memory/0x004a6550-0x004a666a.InternetErrorConstructor.md), which now emits source-ready formal constructor C++ through this class route inside [UID:0000J5][Error](by-file/Error.md).

## Cross-References

- [UID:0000J5][Error](by-file/Error.md)
- [UID:00006P][InternetConnectionError](by-class/InternetConnectionError.md)
- [UID:00013X][0x004a60d0-0x004a6a76.ErrorWrappers](by-memory/0x004a60d0-0x004a6a76.ErrorWrappers.md)
- [UID:0001XI][ErrorHierarchyVtables](by-type/by-vtable/ErrorHierarchyVtables.md)
- [UID:0001UE][ErrorObjectLayouts](by-type/by-struct/ErrorObjectLayouts.md)

## Changes

- 2026-06-27 B004 InternetError constructor source-quality implementation:
  - Score unchanged at `85/88`; this is a targeted exact-constructor source update, not a broad class declaration pass.
  - Added that [UID:0002HN][0x004a6550-0x004a666a.InternetErrorConstructor](by-memory/0x004a6550-0x004a666a.InternetErrorConstructor.md) now emits formal `InternetError::InternetError()` C++ with `LoadLibraryW(L"WININET.DLL")`, a `wchar_t message[255]` fallback initialized to `General internet error`, `FormatMessageW(FORMAT_MESSAGE_FROM_HMODULE | FORMAT_MESSAGE_FROM_SYSTEM, ...)`, and `m_message = message`.
  - Preserved the class-level blank-C++ policy for the unresolved `0x004a6670` output helper, shared destructor/declaration shape, exact original string facade spelling, and hierarchy-wide `+0x0c` virtual name.
- 2026-06-12 A001 Batch 240 direct-parent repair:
  - Before: `78/86`, no autogen parent, and the constructor target [UID:0002HN][0x004a6550-0x004a666a.InternetErrorConstructor](by-memory/0x004a6550-0x004a666a.InternetErrorConstructor.md) could not be assigned because the class was below the child side of the strict gate.
  - After: raised to `85/88` and restored `AUTOGEN_PARENT_UID:0000J5`.
  - Evidence: live IDA MCP reconfirmed the constructor, `GetErrorText`, and shared deleting destructor exact functions; constructor caller/vtable write; `WININET.DLL`, `LoadLibraryW`/`FormatMessageW`, fallback string, and `+0x04` `SimpleUString` storage; `GetErrorText` copy-out behavior; shared destructor cleanup; and the `0x00619404` vtable slot map. [UID:0000J5][Error](by-file/Error.md) already clears `87/85`, so the class/direct-file gate is satisfied.
- 2026-06-19 B013 virtual-name policy sync:
  - Score unchanged at `85/88`.
  - Summary/evidence: B013 keeps this method as a stored-message output helper and records that final source should standardize its `+0x0c` virtual spelling with the rest of the Error hierarchy before emitting class C++.
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
