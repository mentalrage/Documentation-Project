*** UID:000060 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:64 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:76 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# HandlerFindFunc

## Status

- Confidence: strong for predicate behavior; medium for exact owner name.
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
