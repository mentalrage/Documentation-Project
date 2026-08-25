*** UID:000060 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000J7 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000J7 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
namespace {

class HandlerFindFunc : public TreeFindFunc<EventHandler *> {
public:
    explicit HandlerFindFunc(EventHandler *handler)
        : m_handler(handler)
    {
    }

    virtual bool IsMatch(EventHandler **candidate)
    {
        return *candidate == m_handler;
    }

private:
    EventHandler *m_handler;
};

}

[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# HandlerFindFunc

## Current Accepted UID0004YK Predicate Contract

HandlerFindFunc is an EventDispatcher.cpp-local concrete implementation of TreeFindFunc<EventHandler *>. Its only virtual method is bool IsMatch(EventHandler **candidate), which compares *candidate with m_handler. The base has one virtual slot and no virtual destructor; the concrete vptr is at +0 and m_handler at +4, matching the predicate setup and call at 0x004a78f0/0x004a7d60.

## Status

- Confidence: strong for predicate behavior, anonymous-namespace helper identity, dispatcher-local ownership, and exact vtable/search-helper evidence; medium-high for the final source-facing declaration shape.
- Likely source file: [UID:0000J7][EventDispatcher](by-file/EventDispatcher.md)
- Generated recovery hint: `source-3/simroot_v2/class_HandlerFindFunc.cpp`; use only as a lead because the final source shape may have been a file-local predicate rather than a standalone class.
- Imported source hint: `HandlerFindFunc.cpp`, retained as a search term rather than proof of final file ownership.
- Main address doc: [UID:000146][0x004a7cd0-0x004a7df3.EventDispatcherHandlerTreeSupport](by-memory/0x004a7cd0-0x004a7df3.EventDispatcherHandlerTreeSupport.md)

## Class Purpose

`HandlerFindFunc` is a tiny predicate object used by event-dispatcher handler tree/list code. The active method compares an input handler value against the object's expected handler id. Current evidence makes the behavior source-authored dispatcher support, but not a standalone feature class: it is best treated as an anonymous-namespace or file-local predicate/helper in [UID:0000J7][EventDispatcher](by-file/EventDispatcher.md) until a final header/source declaration is proven.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| `IsMatch` | `0x004a7d60-0x004a7d72` | Returns true when `*value == m_expectedHandlerId`; IDA reports size `0x12` / 18 bytes (Verified with int_convert.py) and an eight-instruction body ending in `retn 4`. |

## Evidence Map

| Evidence | Impact |
| --- | --- |
| [UID:000146][0x004a7cd0-0x004a7df3.EventDispatcherHandlerTreeSupport](by-memory/0x004a7cd0-0x004a7df3.EventDispatcherHandlerTreeSupport.md) | Records `0x004a7d60-0x004a7d72` as the predicate method inside the dispatcher handler-tree support island. |
| [UID:0001UF][EventDispatcherHandlerTreeLayouts](by-type/by-struct/EventDispatcherHandlerTreeLayouts.md) | Records IDA MCP disassembly evidence that `0x004a7d60` compares `*arg` against `this[1]`, validating the stored expected-handler slot at offset `+0x04`. |
| [UID:00004M][EventDispatcher](by-class/EventDispatcher.md) and [UID:0000J7][EventDispatcher](by-file/EventDispatcher.md) | Keep the predicate with dispatcher traversal support rather than a standalone feature source. |
| 2026-06-13 live IDA MCP | Reconfirmed `sub_4A7D60` size `0x12` / 18 bytes (Verified with int_convert.py), no callees, one data xref from vtable slot `0x00619648`, and no ordinary code callers because the dispatcher search helper calls the predicate through the stack-installed vtable. |
| 2026-06-13 live IDA MCP decompile/disasm of `0x004a78f0` | Reconfirmed the search helper stores the expected handler at predicate slot `+0x04`, installs ``anonymous namespace'::HandlerFindFunc::vftable` at `0x004a7900`/`0x004a7905`, scans records in `0x1c` / 28-byte strides (Verified with int_convert.py), skips disabled byte `+0x18` / 24 (Verified with int_convert.py), passes `record + 0x14` / 20 (Verified with int_convert.py) to the virtual predicate call, and writes the matched iterator index at `iterator + 0x08`. |

## Binary Shape

The predicate is the only behavior attributed to this helper identity. The layout evidence is intentionally small:

| Field / parameter | Meaning | Evidence |
| --- | --- | --- |
| `this + 0x04` | expected handler id/value | [UID:0001UF][EventDispatcherHandlerTreeLayouts](by-type/by-struct/EventDispatcherHandlerTreeLayouts.md) records the `this[1]` compare used by `0x004a7d60`. |
| input pointer | candidate handler value | [UID:0001UF][EventDispatcherHandlerTreeLayouts](by-type/by-struct/EventDispatcherHandlerTreeLayouts.md) records `0x004a78f0` passing `record + 0x14` into the predicate. |
| candidate record `+0x14` | handler value in the 28-byte handler-record vector | [UID:0001UF][EventDispatcherHandlerTreeLayouts](by-type/by-struct/EventDispatcherHandlerTreeLayouts.md) maps the 28-byte dispatcher handler record and names offset `+0x14` as the handler field. |
| candidate record `+0x18` | disabled flag gate before predicate call | [UID:0001UF][EventDispatcherHandlerTreeLayouts](by-type/by-struct/EventDispatcherHandlerTreeLayouts.md) records `0x004a78f0` skipping records when byte `+0x18` is nonzero. |

This means the class page should not grow into a duplicate method-body page. The canonical raw range and surrounding sparse helper island live in [UID:000146][0x004a7cd0-0x004a7df3.EventDispatcherHandlerTreeSupport](by-memory/0x004a7cd0-0x004a7df3.EventDispatcherHandlerTreeSupport.md); this page exists to preserve the source-facing predicate identity and its relationship to the dispatcher record layout.

## Structural Decision

No split or rename is needed for this pass. IDA names the vtable as ``anonymous namespace'::HandlerFindFunc::vftable`, and the only vtable reference is from [UID:000144][0x004a78f0-0x004a7979.EventDispatcherFindHandlerIterator](by-memory/0x004a78f0-0x004a7979.EventDispatcherFindHandlerIterator.md) at `0x004a7900`. That supports keeping `HandlerFindFunc` as a dispatcher-local predicate identity rather than merging it into [UID:00004M][EventDispatcher](by-class/EventDispatcher.md) or promoting it as an independent feature class.

The neighboring `0x004a7d50-0x004a7d55` body in [UID:000146][0x004a7cd0-0x004a7df3.EventDispatcherHandlerTreeSupport](by-memory/0x004a7cd0-0x004a7df3.EventDispatcherHandlerTreeSupport.md) is a one-instruction tail-jump thunk to [UID:000148][0x004a87a0-0x004a8810.EventDispatcherHandlerRecordVectorFree](by-memory/0x004a87a0-0x004a8810.EventDispatcherHandlerRecordVectorFree.md). It is not part of this predicate, not a `Tree<EventHandler *>` method, and not a standalone product behavior; B008's 2026-06-19 local PE audit records it only to close the sparse-island padding/range map.

The final reconstructed source should probably declare it as a small anonymous-namespace struct or local predicate near the handler-record search helper. The current class page remains useful because generated sources and vtable/RTTI evidence expose it as a distinct source-facing helper identity.

## Reconstruction Notes

- Reconstructable: true as a tiny dispatcher-local support class or source-local predicate.
- Parent: [UID:0000J7][EventDispatcher](by-file/EventDispatcher.md), because the predicate only supports dispatcher handler lookup.
- C++: accepted first-draft declaration route now emits a small anonymous-namespace `HandlerFindFunc` predicate with `IsMatch` and `m_handler`, followed by `[[CHILDREN]]` for child route composition. Exact original field spelling remains final-audit work, but the page is no longer a blank/no-code emitter.
- `AUTOGEN_PARENT_POSITION_OPTIONAL:80` keeps it near the dispatcher handler-tree support in generated assembly order, but the final source should decide whether this appears as a small struct, a local predicate object, or inline comparison logic.

## Ownership Notes

Keep this with [UID:00004M][EventDispatcher](by-class/EventDispatcher.md), not as an independent feature source. It exists to support handler lookup/compaction in the dispatcher tree/list structures.

The neighboring helper families reinforce that placement: [UID:000144][0x004a78f0-0x004a7979.EventDispatcherFindHandlerIterator](by-memory/0x004a78f0-0x004a7979.EventDispatcherFindHandlerIterator.md) is the caller-side scan helper, [UID:000145][0x004a7b10-0x004a7c2a.EventDispatcherHandlerRecordVectorInsert](by-memory/0x004a7b10-0x004a7c2a.EventDispatcherHandlerRecordVectorInsert.md) manages the same 28-byte record vector, and [UID:000148][0x004a87a0-0x004a8810.EventDispatcherHandlerRecordVectorFree](by-memory/0x004a87a0-0x004a8810.EventDispatcherHandlerRecordVectorFree.md) frees the backing storage.

## Score Rationale

Completion is now `88` because the page records the live IDA predicate body, vtable-slot reference, caller-side stack predicate construction, 28-byte record stride, `+0x14` handler field, `+0x18` disabled gate, iterator writeback, dispatcher-only ownership, structural decision to keep the helper identity without splitting or renaming, and the accepted anonymous-namespace first-draft declaration. Confidence is `92`: the compare behavior, anonymous-namespace vtable identity, EventDispatcher ownership, and declaration route are directly verified; remaining uncertainty is limited to exact original member spelling.

## Open Questions

- Exact source declaration form: anonymous-namespace struct, local functor, or compiler-materialized helper around the search helper.
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

- 2026-06-30 B010 accepted EventDispatcher implementation callback:
  - Before: `COMPLETION:86`, `CONFIDENCE:90`, with predicate behavior documented but formal C++ still blank.
  - Changed to: `COMPLETION:88`, `CONFIDENCE:92`; owner/emitter unchanged as [UID:0000J7][EventDispatcher](by-file/EventDispatcher.md), and formal `RECONSTRUCTION_CPP` now emits the accepted anonymous-namespace predicate declaration plus `[[CHILDREN]]`.
  - Evidence: accepted B010 report used IDA MCP session `supervisor_resume_20260629` and existing predicate evidence for `0x004a7d60-0x004a7d72`, `0x00619648` vtable slot, `0x004a78f0` stack construction, handler field `+0x14`, and disabled byte `+0x18`.
- 2026-06-29 B012 implementation of UID000146 empty-emitter report:
  - Score unchanged at `86/90`.
  - Summary/evidence: replaced the stale `95/95 final-source gate` wording with the current target-specific no-code rationale and marker relationship. The predicate remains proven EventDispatcher-local behavior, but its standalone class page should not emit a duplicate body while UID000146 emits only the formal split/index marker.
- 2026-06-13 Agent-A001 Goal 2 class-quality pass:
  - Before: `COMPLETION:76`, `CONFIDENCE:86`.
  - After: `COMPLETION:86`, `CONFIDENCE:90`; parent remains [UID:0000J7][EventDispatcher](by-file/EventDispatcher.md).
  - Summary/evidence: live IDA MCP session `a001_goal2_0002UM` reconfirmed `sub_4A7D60` as the `0x12` / 18-byte (Verified with int_convert.py) predicate body, the `0x00619648` vtable slot, and the `0x004a78f0` search helper's stack construction of ``anonymous namespace'::HandlerFindFunc::vftable`. The helper remains a dispatcher-local predicate identity, not a standalone feature class or a candidate for splitting.
- 2026-06-21 Rule 26 incorporation of B008 source-quality report:
  - Score unchanged at `86/90`.
  - Summary/evidence: B008's local PE audit did not change this predicate's body, but it closed the surrounding support-island map by identifying `0x004a7d50-0x004a7d55` as a vector-free tail-jump thunk. This page now records that the thunk is not a `HandlerFindFunc`, tree, or product method.
- 2026-06-07:
  - Before: the page was `72/86` and only summarized the compare helper, dispatcher ownership, and final declaration caveat.
  - After: raised completion to `76` with explicit binary-shape, ownership, autogen-position, and score-rationale sections.
  - Summary/evidence: [UID:0001UF][EventDispatcherHandlerTreeLayouts](by-type/by-struct/EventDispatcherHandlerTreeLayouts.md) documents `this + 0x04`, candidate record `+0x14`, and disabled byte `+0x18`; [UID:000146][0x004a7cd0-0x004a7df3.EventDispatcherHandlerTreeSupport](by-memory/0x004a7cd0-0x004a7df3.EventDispatcherHandlerTreeSupport.md) places the exact `0x004a7d60-0x004a7d72` body inside dispatcher tree support; sibling vector/scan/free pages keep the helper under EventDispatcher rather than a standalone source module. Confidence is unchanged because this pass did not resolve the final source-facing predicate declaration.
- Completion/confidence score update: existed before as `0/0`; changed to `64/76`. Summary: predicate behavior, dispatcher ownership, one known method, and open naming questions are documented, but the page remains narrow and the exact original functor/source name is unresolved. Evidence: `0x004a7cd0-0x004a7df3.EventDispatcherHandlerTreeSupport`, `EventDispatcher`, and handler tree layout references.
- 2026-06-02:
  - Before: predicate behavior was documented, but reconstructable/autogen parent metadata was blank.
  - After: scored as `72/86`, marked reconstructable, and attached under [UID:0000J7][EventDispatcher](by-file/EventDispatcher.md).
  - Summary/evidence: handler-tree support and layout pages provided exact method-range and disassembly evidence for the stored-handler comparison; C++ remained blank in that historical pass pending final functor/source declaration confidence. Superseded by the 2026-06-30 B010 route-marker implementation above.
