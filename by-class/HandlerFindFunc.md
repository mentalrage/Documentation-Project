*** UID:000060 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:76 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
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
- Generated recovery hint: `source-3/simroot_v2/class_HandlerFindFunc.cpp`; use only as a lead because the final source shape may have been a file-local predicate rather than a standalone class.
- Imported source hint: `HandlerFindFunc.cpp`, retained as a search term rather than proof of final file ownership.
- Main address doc: [UID:000146][0x004a7cd0-0x004a7df3.EventDispatcherHandlerTreeSupport](by-memory/0x004a7cd0-0x004a7df3.EventDispatcherHandlerTreeSupport.md)

## Class Purpose

`HandlerFindFunc` is a tiny predicate object used by event-dispatcher handler tree/list code. The active method compares an input handler value against the object's expected handler id. Current evidence makes the behavior source-authored dispatcher support, but not a standalone feature class: it is best treated as a file-local predicate/helper in [UID:0000J7][EventDispatcher](by-file/EventDispatcher.md) until a final header/source declaration is proven.

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

## Binary Shape

The predicate is the only behavior attributed to this helper identity. The layout evidence is intentionally small:

| Field / parameter | Meaning | Evidence |
| --- | --- | --- |
| `this + 0x04` | expected handler id/value | [UID:0001UF][EventDispatcherHandlerTreeLayouts](by-type/by-struct/EventDispatcherHandlerTreeLayouts.md) records the `this[1]` compare used by `0x004a7d60`. |
| input pointer | candidate handler value | [UID:0001UF][EventDispatcherHandlerTreeLayouts](by-type/by-struct/EventDispatcherHandlerTreeLayouts.md) records `0x004a78f0` passing `record + 0x14` into the predicate. |
| candidate record `+0x14` | handler value in the 28-byte handler-record vector | [UID:0001UF][EventDispatcherHandlerTreeLayouts](by-type/by-struct/EventDispatcherHandlerTreeLayouts.md) maps the 28-byte dispatcher handler record and names offset `+0x14` as the handler field. |
| candidate record `+0x18` | disabled flag gate before predicate call | [UID:0001UF][EventDispatcherHandlerTreeLayouts](by-type/by-struct/EventDispatcherHandlerTreeLayouts.md) records `0x004a78f0` skipping records when byte `+0x18` is nonzero. |

This means the class page should not grow into a duplicate method-body page. The canonical raw range and surrounding sparse helper island live in [UID:000146][0x004a7cd0-0x004a7df3.EventDispatcherHandlerTreeSupport](by-memory/0x004a7cd0-0x004a7df3.EventDispatcherHandlerTreeSupport.md); this page exists to preserve the source-facing predicate identity and its relationship to the dispatcher record layout.

## Reconstruction Notes

- Reconstructable: true as a tiny dispatcher-local support class or source-local predicate.
- Parent: [UID:0000J7][EventDispatcher](by-file/EventDispatcher.md), because the predicate only supports dispatcher handler lookup.
- C++: intentionally blank. The observed method body is simple, but the final source-facing declaration is unresolved: it could have been a named helper class, a local functor, or an inline predicate materialized by the compiler.
- `AUTOGEN_PARENT_POSITION_OPTIONAL:80` keeps it near the dispatcher handler-tree support in generated assembly order, but the final source should decide whether this appears as a small struct, a local predicate object, or inline comparison logic.

## Ownership Notes

Keep this with [UID:00004M][EventDispatcher](by-class/EventDispatcher.md), not as an independent feature source. It exists to support handler lookup/compaction in the dispatcher tree/list structures.

The neighboring helper families reinforce that placement: [UID:000144][0x004a78f0-0x004a7979.EventDispatcherFindHandlerIterator](by-memory/0x004a78f0-0x004a7979.EventDispatcherFindHandlerIterator.md) is the caller-side scan helper, [UID:000145][0x004a7b10-0x004a7c2a.EventDispatcherHandlerRecordVectorInsert](by-memory/0x004a7b10-0x004a7c2a.EventDispatcherHandlerRecordVectorInsert.md) manages the same 28-byte record vector, and [UID:000148][0x004a87a0-0x004a8810.EventDispatcherHandlerRecordVectorFree](by-memory/0x004a87a0-0x004a8810.EventDispatcherHandlerRecordVectorFree.md) frees the backing storage.

## Score Rationale

Completion is raised to `76` because the page now records the source-shape caveat, exact predicate inputs, relationship to the 28-byte handler-record layout, caller-side disabled gate, sibling vector/tree helpers, and autogen-position rationale. Confidence remains `86`: the compare behavior and EventDispatcher ownership are strongly documented by UID-linked IDA-backed pages, while final source-facing type spelling and whether this survived as a named class remain unresolved.

## Open Questions

- Whether this was originally a named local functor, an STL-style predicate, or a decompiler artifact from an inline compare helper.
- Final field name for `m_expectedHandlerId`.

## Cross-References

- [UID:0000J7][EventDispatcher](by-file/EventDispatcher.md)
- [UID:00004M][EventDispatcher](by-class/EventDispatcher.md)
- [UID:000144][0x004a78f0-0x004a7979.EventDispatcherFindHandlerIterator](by-memory/0x004a78f0-0x004a7979.EventDispatcherFindHandlerIterator.md)
- [UID:000145][0x004a7b10-0x004a7c2a.EventDispatcherHandlerRecordVectorInsert](by-memory/0x004a7b10-0x004a7c2a.EventDispatcherHandlerRecordVectorInsert.md)
- [UID:000146][0x004a7cd0-0x004a7df3.EventDispatcherHandlerTreeSupport](by-memory/0x004a7cd0-0x004a7df3.EventDispatcherHandlerTreeSupport.md)
- [UID:000148][0x004a87a0-0x004a8810.EventDispatcherHandlerRecordVectorFree](by-memory/0x004a87a0-0x004a8810.EventDispatcherHandlerRecordVectorFree.md)
- [UID:0001UF][EventDispatcherHandlerTreeLayouts](by-type/by-struct/EventDispatcherHandlerTreeLayouts.md)

## Changes

- 2026-06-07:
  - Before: the page was `72/86` and only summarized the compare helper, dispatcher ownership, and final declaration caveat.
  - After: raised completion to `76` with explicit binary-shape, ownership, autogen-position, and score-rationale sections.
  - Summary/evidence: [UID:0001UF][EventDispatcherHandlerTreeLayouts](by-type/by-struct/EventDispatcherHandlerTreeLayouts.md) documents `this + 0x04`, candidate record `+0x14`, and disabled byte `+0x18`; [UID:000146][0x004a7cd0-0x004a7df3.EventDispatcherHandlerTreeSupport](by-memory/0x004a7cd0-0x004a7df3.EventDispatcherHandlerTreeSupport.md) places the exact `0x004a7d60-0x004a7d71` body inside dispatcher tree support; sibling vector/scan/free pages keep the helper under EventDispatcher rather than a standalone source module. Confidence is unchanged because this pass did not resolve the final source-facing predicate declaration.
- Completion/confidence score update: existed before as `0/0`; changed to `64/76`. Summary: predicate behavior, dispatcher ownership, one known method, and open naming questions are documented, but the page remains narrow and the exact original functor/source name is unresolved. Evidence: `0x004a7cd0-0x004a7df3.EventDispatcherHandlerTreeSupport`, `EventDispatcher`, and handler tree layout references.
- 2026-06-02:
  - Before: predicate behavior was documented, but reconstructable/autogen parent metadata was blank.
  - After: scored as `72/86`, marked reconstructable, and attached under [UID:0000J7][EventDispatcher](by-file/EventDispatcher.md).
  - Summary/evidence: handler-tree support and layout pages now provide exact method-range and disassembly evidence for the stored-handler comparison; C++ remains blank pending final functor/source declaration confidence.
