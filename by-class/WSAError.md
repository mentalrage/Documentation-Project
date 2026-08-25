*** UID:0000GB | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:87 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000J5 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000J5 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
// WSAError class-level source is covered by [UID:0000J5][Error](by-file/Error.md) and exact constructor child [UID:0002HM][0x004a64a0-0x004a64c5.WSAErrorConstructor](by-memory/0x004a64a0-0x004a64c5.WSAErrorConstructor.md); this page emits no standalone partial declaration while the WSAError formatter at 0x004a64d0 and hierarchy-wide message virtual remain future exact-source work.
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# WSAError

## Status

- Confidence: strong for class responsibility and shared error-module placement.
- Historical generated-output lead: `class_WSAError.cpp`; use IDA and the linked by-* docs as current scoring authority.
- Likely source module: [UID:0000J5][Error](by-file/Error.md)
- Current range: [UID:00013X][0x004a60d0-0x004a6a76.ErrorWrappers](by-memory/0x004a60d0-0x004a6a76.ErrorWrappers.md)
- Exact constructor: [UID:0002HM][0x004a64a0-0x004a64c5.WSAErrorConstructor](by-memory/0x004a64a0-0x004a64c5.WSAErrorConstructor.md)
- Vtable anchor: RTTI `0x006193e8`, vtable `0x006193ec`
- Evidence basis: live IDA MCP checks plus existing Error module, vtable, string, socket-boundary, and exact constructor docs.

## Responsibility

`WSAError` captures `WSAGetLastError` and formats Winsock failures for display or exception reporting.

## Important Methods

| Address | Current name | Notes |
| --- | --- | --- |
| `0x004a64a0` | `WSAError::WSAError()` | Source-ready exact child [UID:0002HM][0x004a64a0-0x004a64c5.WSAErrorConstructor](by-memory/0x004a64a0-0x004a64c5.WSAErrorConstructor.md); calls base `LObject` setup, installs the `WSAError` vtable, and initializes `int m_errorCode` from `WSAGetLastError()`. |
| `0x004a64d0` | `FormatErrorMessage` | Formats `WSAError` using `FormatMessageW` or raw code fallback. |

## Ownership Notes

The constructor is called from socket/transport code, but implementation belongs with [UID:0000J5][Error](by-file/Error.md). Transport ownership remains with [UID:0000DD][Socket](by-class/Socket.md).

2026-05-26 IDA MCP recheck reports `WSAError::WSAError` at `0x004a64a0` as a real `0x25`-byte function, `FormatErrorMessage` at `0x004a64d0` as a real `0x79`-byte function, and the vtable write/xref to `0x006193ec` at `0x004a64af`.

2026-06-14 A001 IDA MCP refresh on database `b001_0003gy` reconfirmed `0x004a64a0` size `0x25`, `0x004a64d0` size `0x79`, the constructor vtable store to `0x006193ec`, the single socket caller at `0x00577a28`, and the format-method vtable slot ref at `0x006193f8`.

The refreshed formatter decompilation calls the process `FormatMessageW` thunk (`0x0069be6c`) with the stored Winsock code at `this+0x04`, then writes either the resolved-message form using the `WSAError: %s` literal at `0x006195a4` or the raw-code fallback using `WSAError: 0x%p` at `0x006195c0`. Both literals are documented by [UID:0003I4][0x00619448-0x00619628.ErrorHierarchyMessageStrings](by-memory/0x00619448-0x00619628.ErrorHierarchyMessageStrings.md).

2026-06-19 B013 rejects stale generated `char *` formatter signatures for the status-code formatter family. This method should be treated as the Error hierarchy's wide-buffer `FormatErrorMessage(wchar_t *destination, size_t destinationChars) const` slot or the eventual project-wide equivalent, not as an ANSI/`char *` output routine.

2026-06-27 B007 implementation for [UID:0002HM][0x004a64a0-0x004a64c5.WSAErrorConstructor](by-memory/0x004a64a0-0x004a64c5.WSAErrorConstructor.md) uses MCP session `80de0a67` to promote the exact constructor child to formal C++. `lookup_funcs`, `decompile`, `disasm`, `callees`, `xrefs_to`, `imports_query`, and `get_bytes` agree on the `0x25` constructor range, base call to `sub_4F4A80` / `LObject::LObject()`, `WSAError` vtable store at `0x004a64af`, `WSAGetLastError` import call at `0x004a64b5`, `int m_errorCode` store at byte offset `+0x04`, one direct socket/gethostbyname throw-site caller at `0x00577a28`, WSAError vtable row `0x006193e8-0x00619404`, formatter slot `0x006193f8 -> 0x004a64d0`, and clean `0xcc` padding before the constructor and before the separate formatter. The accepted source-facing field is `m_errorCode`; exact original spelling remains inferred.

## Autogen Status

Attach this class to [UID:0000J5][Error](by-file/Error.md) as reconstructable error-hierarchy metadata. Keep the class-level C++ block blank until the formatter exact child and the shared `+0x0c` virtual declaration are standardized, but the constructor exact child [UID:0002HM][0x004a64a0-0x004a64c5.WSAErrorConstructor](by-memory/0x004a64a0-0x004a64c5.WSAErrorConstructor.md) now emits formal constructor C++ through this class/file route.

The old class-level phrase that the constructor was blocked by a `90/90+` code-entry gate is superseded. Current by-structure policy allows source entry for exact children with `RECONSTRUCTABLE:TRUE`, confirmed nonblank emitter route, average score above `85`, and enough source-quality evidence. The formatter/declaration caveat still blocks class-wide C++, not the exact constructor child.

## Score Rationale

| Score | Rationale |
| --- | --- |
| Completion `87` | The page now records Winsock wrapper responsibility, direct Error.cpp ownership, source-ready exact constructor support, formatter behavior, vtable/string anchors, socket caller boundary, and current MCP method/xref/decompile/disassembly evidence. Completion rises because [UID:0002HM][0x004a64a0-0x004a64c5.WSAErrorConstructor](by-memory/0x004a64a0-0x004a64c5.WSAErrorConstructor.md) now carries formal constructor C++; it remains below class-level source-ready because the formatter exact child and shared Error declaration are unresolved. |
| Confidence `88` | Confidence is strong for `util/Error.cpp` ownership and constructor behavior because the file parent is `87/85`, the ErrorHierarchy vtable page is `86/90`, the exact constructor child is now `90/92`, and IDA confirms the formatter slot/string usage. Confidence is not higher because `m_errorCode` is inferred and this class still depends on the broader Error hierarchy `+0x0c` declaration cleanup. |

## Cross-References

- [UID:0000J5][Error](by-file/Error.md)
- [UID:0000DD][Socket](by-class/Socket.md)
- [UID:00013X][0x004a60d0-0x004a6a76.ErrorWrappers](by-memory/0x004a60d0-0x004a6a76.ErrorWrappers.md)
- [UID:0001XI][ErrorHierarchyVtables](by-type/by-vtable/ErrorHierarchyVtables.md)

## Changes

- 2026-05-30 completion/confidence scoring:
  - What existed before: `COMPLETION:0` and `CONFIDENCE:0`.
  - Changed to: `COMPLETION:78` and `CONFIDENCE:84`.
  - Summary/evidence: scored from the focused constructor/format-method documentation, shared `Error` module placement, socket caller ownership note, and IDA-confirmed method/vtable evidence; completion is moderate because the page is intentionally small and does not yet spell out the full formatting internals.
- 2026-06-02 autogen ownership:
  - What existed before: reconstructable and parent metadata were blank.
  - Changed to: marked reconstructable and attached to [UID:0000J5][Error](by-file/Error.md), leaving C++ blank.
  - Summary/evidence: strong Winsock wrapper evidence supports `util/Error.cpp`; socket/transport code remains a caller.
- 2026-06-14 A001 Goal 2 refresh:
  - Before: `78/84`, with stale generated-evidence wording and no current formatter detail on the class page.
  - After: `85/86`, preserving Error owner/emitter routing and blank C++ under the active `90/90+` gate.
  - Summary/evidence: live IDA MCP reconfirmed constructor/formatter sizes, vtable store/slot refs, socket caller, string literal refs, and the exact constructor/support aggregate refresh.
- 2026-06-19 B013 signature sync:
  - Score unchanged at `85/86`.
  - Summary/evidence: B013 confirms the WSA formatter belongs to the wide-buffer Error hierarchy message virtual and rejects generated `char *` signatures as final source evidence.
- 2026-06-27 B007 WSAError constructor source-ready sync:
  - Changed score `85/86 -> 87/88`; owner/emitter remain [UID:0000J5][Error](by-file/Error.md), and class-level C++ remains blank.
  - Summary/evidence: accepted B007 implementation for [UID:0002HM][0x004a64a0-0x004a64c5.WSAErrorConstructor](by-memory/0x004a64a0-0x004a64c5.WSAErrorConstructor.md) synchronizes this class with MCP session `80de0a67`: exact `0x25` constructor, `LObject` base setup, `WSAGetLastError`, `int m_errorCode` at `+0x04`, `WSAError` vtable store at `0x004a64af`, single socket/gethostbyname throw-site caller, clean padding before `0x004a64d0`, formal child C++, and rejection of raw/decompiler names, Socket ownership, `DWORD` type drift, and formatter/range merge alternatives. The class-level formatter/declaration work still blocks broad class C++.
