*** UID:000060 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:72 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000J7 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL:80 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# HandlerFindFunc

## Status

- Confidence: strong for predicate behavior and dispatcher-local ownership; medium for exact original source-facing functor name.
- Likely source file: [UID:0000J7][EventDispatcher](by-file/EventDispatcher.md)
- Current generated file: `source-3/simroot_v2/class_HandlerFindFunc.cpp`
- Imported source hint: `HandlerFindFunc.cpp`
- Main address doc: [UID:000146][0x004a7cd0-0x004a7df3.EventDispatcherHandlerTreeSupport](by-memory/0x004a7cd0-0x004a7df3.EventDispatcherHandlerTreeSupport.md)

## Class Purpose

`HandlerFindFunc` is a tiny predicate object used by event-dispatcher handler tree/list code. The active method compares an input handler value against the object's expected handler id.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| `IsMatch` | `0x004a7d60-0x004a7d71` | Returns true when `*value == m_expectedHandlerId`. |

## Evidence Map

| Evidence | Impact |
| --- | --- |
| [UID:000146][0x004a7cd0-0x004a7df3.EventDispatcherHandlerTreeSupport](by-memory/0x004a7cd0-0x004a7df3.EventDispatcherHandlerTreeSupport.md) | Records `0x004a7d60-0x004a7d71` as the predicate method inside the dispatcher handler-tree support island. |
| [UID:0001UF][EventDispatcherHandlerTreeLayouts](by-type/by-struct/EventDispatcherHandlerTreeLayouts.md) | Records IDA MCP disassembly evidence that `0x004a7d60` compares `*arg` against `this[1]`, validating the stored expected-handler slot at offset `+0x04`. |
| [UID:00004M][EventDispatcher](by-class/EventDispatcher.md) and [UID:0000J7][EventDispatcher](by-file/EventDispatcher.md) | Keep the predicate with dispatcher traversal support rather than a standalone feature source. |

## Reconstruction Notes

- Reconstructable: true as a tiny dispatcher-local support class or source-local predicate.
- Parent: [UID:0000J7][EventDispatcher](by-file/EventDispatcher.md), because the predicate only supports dispatcher handler lookup.
- C++: intentionally blank. The observed method body is simple, but the final source-facing declaration is unresolved: it could have been a named helper class, a local functor, or an inline predicate materialized by the compiler.

## Ownership Notes

Keep this with [UID:00004M][EventDispatcher](by-class/EventDispatcher.md), not as an independent feature source. It exists to support handler lookup/compaction in the dispatcher tree/list structures.

## Open Questions

- Whether this was originally a named local functor, an STL-style predicate, or a decompiler artifact from an inline compare helper.
- Final field name for `m_expectedHandlerId`.

## Cross-References

- [UID:0000J7][EventDispatcher](by-file/EventDispatcher.md)
- [UID:00004M][EventDispatcher](by-class/EventDispatcher.md)
- [UID:000146][0x004a7cd0-0x004a7df3.EventDispatcherHandlerTreeSupport](by-memory/0x004a7cd0-0x004a7df3.EventDispatcherHandlerTreeSupport.md)
- [UID:0001UF][EventDispatcherHandlerTreeLayouts](by-type/by-struct/EventDispatcherHandlerTreeLayouts.md)

## Changes

- Completion/confidence score update: existed before as `0/0`; changed to `64/76`. Summary: predicate behavior, dispatcher ownership, one known method, and open naming questions are documented, but the page remains narrow and the exact original functor/source name is unresolved. Evidence: `0x004a7cd0-0x004a7df3.EventDispatcherHandlerTreeSupport`, `EventDispatcher`, and handler tree layout references.
- 2026-06-02:
  - Before: predicate behavior was documented, but reconstructable/autogen parent metadata was blank.
  - After: scored as `72/86`, marked reconstructable, and attached under [UID:0000J7][EventDispatcher](by-file/EventDispatcher.md).
  - Summary/evidence: handler-tree support and layout pages now provide exact method-range and disassembly evidence for the stored-handler comparison; C++ remains blank pending final functor/source declaration confidence.
