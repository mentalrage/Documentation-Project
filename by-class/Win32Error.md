*** UID:0000G7 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:87 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000J5 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000J5 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
// Win32Error definitions remain owned by [UID:0000J5][Error](by-file/Error.md) and exact method children. The complete guarded Error.h declaration is emitted once by [UID:00004J][Error](by-class/Error.md); this class page emits no duplicate CPP or H source.
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# Win32Error

## Status

- Confidence: strong for class responsibility and shared error-module placement.
- Historical generated-output lead: `class_Win32Error.cpp`; use IDA and the linked by-* docs as current scoring authority.
- Likely source module: [UID:0000J5][Error](by-file/Error.md)
- Current range: [UID:00013X][0x004a60d0-0x004a6a76.ErrorWrappers](by-memory/0x004a60d0-0x004a6a76.ErrorWrappers.md)
- Exact constructor: [UID:0002HJ][0x004a60d0-0x004a60f5.Win32ErrorConstructor](by-memory/0x004a60d0-0x004a60f5.Win32ErrorConstructor.md)
- Vtable anchor: RTTI `0x00619358`, vtable `0x0061935c`
- Evidence basis: live IDA MCP checks plus existing Error module, vtable, string, and exact constructor docs.

## Responsibility

`Win32Error` captures a Win32 last-error code and formats it into a readable message for display or exception reporting.

## Important Methods

| Address | Current name | Notes |
| --- | --- | --- |
| `0x004a60d0` | `Win32Error::Win32Error()` | Source-ready exact child [UID:0002HJ][0x004a60d0-0x004a60f5.Win32ErrorConstructor](by-memory/0x004a60d0-0x004a60f5.Win32ErrorConstructor.md); calls base `LObject` setup, installs the `Win32Error` vtable, and initializes `m_errorCode` from `GetLastError()`. |
| `0x004a6100` | `FormatErrorMessage` | Uses `FormatMessageW`; falls back to raw code formatting. |

## Ownership Notes

This is a generic platform error wrapper. Keep implementation in `util/Error.cpp`; callers from startup, file, network, or rendering code should only construct it.

2026-05-26 IDA MCP recheck reports `Win32Error::Win32Error` at `0x004a60d0` as a real `0x25`-byte function, `FormatErrorMessage` at `0x004a6100` as a real `0xa3`-byte function, and the vtable write/xref to `0x0061935c` at `0x004a60df`.

2026-06-14 A001 IDA MCP refresh on database `b001_0003gy` reconfirmed `0x004a60d0` size `0x25`, `0x004a6100` size `0xa3`, the constructor vtable store to `0x0061935c`, and the format-method vtable slot ref at `0x00619368`. Constructor xrefs still show broad subsystem callers, while the formatter is reached through the vtable data.

The refreshed formatter decompilation calls the process `FormatMessageW` thunk (`0x0069be6c`) into a local buffer using the stored code at `this+0x04`, then formats either the resolved text with the `Win32Error` literals at `0x00619448`/`0x00619460` or the raw-code fallback literal at `0x00619478`. Both string ranges are documented by [UID:0003I4][0x00619448-0x00619628.ErrorHierarchyMessageStrings](by-memory/0x00619448-0x00619628.ErrorHierarchyMessageStrings.md).

2026-06-19 B013 keeps `FormatErrorMessage(wchar_t *destination, size_t destinationChars) const` as the current best source-facing name/signature for this formatter slot once the hierarchy-wide virtual spelling is standardized. The method remains aggregate-only until an exact child page is created.

2026-06-27 B002 implementation for [UID:0002HJ][0x004a60d0-0x004a60f5.Win32ErrorConstructor](by-memory/0x004a60d0-0x004a60f5.Win32ErrorConstructor.md) uses MCP session `80de0a67` to promote the exact constructor child to formal C++. `lookup_funcs`, `decompile`, `disasm`, `callees`, `analyze_function`, `xrefs_to`, and `get_bytes` agree on the `0x25` constructor range, base call to `sub_4F4A80` / `LObject::LObject()`, `Win32Error` vtable store at `0x004a60df`, `GetLastError` import call at `0x004a60e5`, `m_errorCode` store at byte offset `+0x04`, 27 direct caller refs, single vtable-base xref at `0x004a60df`, formatter slot ref at `0x00619368`, and clean `0xcc` padding before the constructor and before the separate formatter at `0x004a6100`. The accepted source-facing field is `m_errorCode`; exact original spelling remains inferred.

## Autogen Status

This class remains attached to [UID:0000J5][Error](by-file/Error.md). [UID:00004J][Error](by-class/Error.md) owns the single complete `Error.h` guard and emits the `Win32Error : public Error` declaration inside that guard after `MyError`; this page keeps both formal channels non-duplicating. The constructor exact child [UID:0002HJ][0x004a60d0-0x004a60f5.Win32ErrorConstructor](by-memory/0x004a60d0-0x004a60f5.Win32ErrorConstructor.md) retains its formal constructor body; formatter implementation remains with the Error method family and is not duplicated here.

The old class-level phrase that the constructor was blocked by a `90/90+` code-entry gate is superseded. The current declaration closes the Error.h dependency needed by this callback. A future exact formatter child can refine body routing without invalidating the present declaration or constructor source.

## Score Rationale

| Score | Rationale |
| --- | --- |
| Completion `87` | The page records class responsibility, direct Error.cpp ownership, exact constructor support, formatter behavior, vtable/string anchors, broad callers, and the coordinated formal H declaration. It remains below class-family completion because the formatter has no exact method child in this callback. |
| Confidence `88` | IDA proves ownership, constructor behavior, error-code storage, formatter slot, and string usage. Confidence is capped by inferred `m_errorCode` spelling and remaining hierarchy-wide formatter-body routing, not by the declaration needed here. |

## Cross-References

- [UID:0000J5][Error](by-file/Error.md)
- [UID:00013X][0x004a60d0-0x004a6a76.ErrorWrappers](by-memory/0x004a60d0-0x004a6a76.ErrorWrappers.md)
- [UID:0001XI][ErrorHierarchyVtables](by-type/by-vtable/ErrorHierarchyVtables.md)

## UID0000LI Declaration Support - 2026-08-15

The formal Error.h route now contains the exact declaration required by the two Monitor-family pointer throws inside the one guard owned by [UID:00004J][Error](by-class/Error.md). Existing constructor and formatter ownership remains in Error exact children; this class page adds no duplicate CPP or H body. The parent-owned declaration preserves `DWORD m_errorCode`, `Win32Error()`, and `virtual int FormatErrorMessage(wchar_t *, size_t) const` on the existing Error base.

## Guard Ownership Repair - 2026-08-15

The earlier child-emitter route appended `Win32Error` after [UID:00004J][Error](by-class/Error.md) had already emitted `#endif`, which left the declaration outside `NEXUSTK_UTIL_ERROR_H` and allowed redefinition on repeated inclusion. The corrected route places the complete declaration and its eight-byte size check inside the Error page's single formal guard, adds `<windows.h>` there for the `DWORD` member, and leaves this child H channel blank. No method definition moved and no second declaration remains.

## Changes

- 2026-05-30 completion/confidence scoring:
  - What existed before: `COMPLETION:0` and `CONFIDENCE:0`.
  - Changed to: `COMPLETION:78` and `CONFIDENCE:84`.
  - Summary/evidence: scored from the constructor/format method documentation, shared `Error` module placement, generic ownership note, and IDA-confirmed function/vtable evidence; completion is moderate because the page is focused and does not yet fully document formatting internals.
- 2026-06-02 autogen ownership:
  - What existed before: reconstructable and parent metadata were blank.
  - Changed to: marked reconstructable and attached to [UID:0000J5][Error](by-file/Error.md) with C++ blank.
  - Summary/evidence: strong class confidence and the `Error` file parent support `util/Error.cpp` placement; final C++ remains deferred.
- 2026-06-14 A001 Goal 2 refresh:
  - Before: `78/84`, with stale generated-evidence wording and no current formatter detail on the class page.
  - After: `85/86`, preserving Error owner/emitter routing and blank C++ under the active `90/90+` gate.
  - Summary/evidence: live IDA MCP reconfirmed constructor/formatter sizes, vtable store/slot refs, constructor caller breadth, string literal refs, and the exact constructor/support aggregate refresh.
- 2026-06-19 B013 formatter policy sync:
  - Score unchanged at `85/86`.
  - Summary/evidence: B013 keeps this formatter under the wide-buffer Error hierarchy message virtual and leaves C++ blank until the exact formatter child and final declaration spelling are created.
- 2026-06-27 B002 Win32Error constructor implementation:
  - Before: `85/86`, with class-level C++ blank and the constructor still described as source-known but not emitting.
  - After: `87/88`, preserving [UID:0000J5][Error](by-file/Error.md) ownership/emitter routing and a blank class-level C++ block.
  - Summary/evidence: accepted B002 report for [UID:0002HJ][0x004a60d0-0x004a60f5.Win32ErrorConstructor](by-memory/0x004a60d0-0x004a60f5.Win32ErrorConstructor.md) synchronizes this class with MCP session `80de0a67`: source-ready `Win32Error::Win32Error()`, `m_errorCode(GetLastError())`, exact range/padding/caller/vtable proof, and rejection of caller ownership, broad aggregate emission, decompiler-shaped source, local-only `m_lastError` drift, and adjacent formatter merge. The class-level C++ remains blank because `Win32Error::FormatErrorMessage` and the hierarchy-wide message virtual declaration are still separate unresolved work.
