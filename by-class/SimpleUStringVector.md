*** UID:0000DA | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:89 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000OB | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000OB | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL:10 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
#include "StringUtil.h"

[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
namespace mystr
{
template <class CharT>
struct mychar_traits;

template <class CharT, class Traits>
class StringBase;
}

typedef wchar_t *SimpleUStringHandle;

class SimpleUStringVector
{
public:
    SimpleUStringVector();
    ~SimpleUStringVector();

    void Clear();
    unsigned int Size() const;
    mystr::StringBase<wchar_t, mystr::mychar_traits<wchar_t> >&
        operator[](unsigned int index);
    const mystr::StringBase<wchar_t, mystr::mychar_traits<wchar_t> >&
        operator[](unsigned int index) const;
    void PushBack(
        const mystr::StringBase<wchar_t, mystr::mychar_traits<wchar_t> > &value);
    void PushBack(const SimpleUStringHandle *value);

private:
    SimpleUStringHandle *m_begin;
    SimpleUStringHandle *m_end;
    SimpleUStringHandle *m_capacity;

    SimpleUStringHandle *GrowAndInsert(SimpleUStringHandle *position,
                                       const SimpleUStringHandle *value);
};
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# SimpleUStringVector

## UID0000MS Minimal Source-Facing Facade - 2026-08-25

The public declaration now exposes the operations used by ProfileStorage and existing callers: `Clear`, `Size`, mutable/const indexing, and `PushBack` from `mystr::StringBase<wchar_t>`. The existing handle-pointer `PushBack` remains the exact modeled implementation boundary. The source-facing overload/facade maps the one-pointer StringBase object to the same four-byte handle-slot representation; it does not introduce 24-byte inline strings.

Object layout remains exactly 12 bytes: three pointers `m_begin`, `m_end`, and `m_capacity`. Element stride remains four bytes, and destructor/grow/push-back children keep their established owner and ranges. This callback adds the declarations needed by current Config/ProfileStorage source without changing storage, child bodies, ownership, or emitter routing.

## UID0000IF Complete-Type And Namespace-Scope Route - 2026-08-24

- This class is StringUtil H emitter position `10`, after UID0000D9 opens the shared guard and before StringIter. Its exact `SimpleUStringHandle` typedef and three-pointer `SimpleUStringVector` declaration move from CPP to H so Config can embed the type by value legally.
- Formal CPP is now exactly the sibling `StringUtil.h` include followed by namespace-scope `[[CHILDREN]]`. Destructor, grow/insert, and push-back definitions therefore remain class-owned children but can no longer be expanded inside a class declaration.
- The class-local child placeholder is absent from formal H. No second guard, duplicate vector declaration, inline-24-byte element model, alternate API, or new storage owner is introduced.
- Ownership UID0000OB, score `88/89`, exact 12-byte begin/end/capacity layout, pointer-backed four-byte slot model, child ownership, and unrelated evidence remain unchanged. Generated proof requires the declaration once between SimpleUString and StringIter and every vector child at namespace scope in CPP.

## Summary

`SimpleUStringVector` is a small begin/end/capacity container for contiguous 4-byte pointer-backed [UID:0000D9][SimpleUString](by-class/SimpleUString.md) / string-handle slots. It destroys owned string handles, grows storage by copy-constructing slots into a new buffer, and provides a push-back fast path.

## Likely Original Placement

- Source: [UID:0000OB][StringUtil](by-file/StringUtil.md)
- Proposed path: `util/StringUtil.cpp`
- Autogen parent: [UID:0000OB][StringUtil](by-file/StringUtil.md)
- Confidence: strong for utility ownership, exact helper ranges, 4-byte slot behavior, and child attachment; medium-high for exact original file split.

## Methods

- [UID:000112][0x00493f10-0x00493f79.SimpleUStringVectorDestructor](by-memory/0x00493f10-0x00493f79.SimpleUStringVectorDestructor.md): destructor, destroys all 4-byte string-handle slots and frees backing storage; B001-016 attaches this exact child directly to this class.
- [UID:00012G][0x0049cc40-0x0049ce48.SimpleUStringVectorGrowAndInsert](by-memory/0x0049cc40-0x0049ce48.SimpleUStringVectorGrowAndInsert.md): grow/insert method, rerouted directly to this class by the 2026-06-17 B002 source-quality execution.
- [UID:0001J4][0x00584910-0x0058498b.SimpleUStringVectorPushBack](by-memory/0x00584910-0x0058498b.SimpleUStringVectorPushBack.md): push-back method, rerouted directly to this class by the 2026-06-17 B001 source-quality execution.

## Evidence

- Earlier metadata names this class from the raw class lead `cls_0x493f10`; this is treated only as a lead.
- Live IDA decompilation proves the layout is a standard `begin`, `end`, `capacity` pointer triplet and that element stride is four bytes.
- `DATFile::ReadAllLines` is a clear caller for grow/insert when appending converted lines.
- The StringBase delimiter split/tokenization helper at `0x005839c0` calls push-back at two sites and calls grow/insert directly at two other sites.
- Config and Socket override notes already model matching `SimpleUStringVector` fields.
- 2026-06-04 live IDA confirms the corrected last-byte-inclusive ranges: `0x00493f10-0x00493f79`, `0x0049cc40-0x0049ce48`, and `0x00584910-0x0058498b`, with `0xcc` padding immediately after each function.
- Live IDA caller/callee checks report 19 callers to the destructor, 7 callers to grow/insert, 2 callers to push-back, and helper calls through `0x00582a90`, `0x00582b70`, `0x0049d530`, and `0x00584ba0`.
- 2026-06-17 B002 source-quality reanalysis rerouted [UID:00012G][0x0049cc40-0x0049ce48.SimpleUStringVectorGrowAndInsert](by-memory/0x0049cc40-0x0049ce48.SimpleUStringVectorGrowAndInsert.md) from direct [UID:0000OB][StringUtil](by-file/StringUtil.md) ownership to this class. The method reads/writes only the vector triplet, uses 4-byte pointer-backed wide string handle slots, is called by sibling push-back on growth, and remains emitted through the StringUtil source family.
- B002 rejected the false-friend inline 24-byte [UID:0003MS][StaticSimpleUStringVector_69B39C](by-global/StaticSimpleUStringVector_69B39C.md) model for this class method because `GrowAndInsert` shifts pointer differences by two and copy/destroys one dword string-handle slot at a time.
- 2026-06-17 B001 source-quality reanalysis rerouted [UID:0001J4][0x00584910-0x0058498b.SimpleUStringVectorPushBack](by-memory/0x00584910-0x0058498b.SimpleUStringVectorPushBack.md) from direct [UID:0000OB][StringUtil](by-file/StringUtil.md) ownership to this class. The method appends one 4-byte pointer-backed wide string-handle slot, uses share/refcount and private-copy fast paths, delegates to [UID:00012G][0x0049cc40-0x0049ce48.SimpleUStringVectorGrowAndInsert](by-memory/0x0049cc40-0x0049ce48.SimpleUStringVectorGrowAndInsert.md) on capacity exhaustion, and remains emitted through the StringUtil source family.
- 2026-07-01 B007 implementation callback: the formal declaration uses a `SimpleUStringHandle` alias because the slot model is pointer-backed and four bytes wide. The accepted report rejected inline 24-byte `SimpleUString` elements for this vector; that inline storage belongs to the standalone SSO object, not the vector's slot array.

## Batch 129 Parent-Gate Audit

This class is the direct owner for [UID:0001W6][SimpleUStringVectorLayout](by-type/by-struct/SimpleUStringVectorLayout.md). The layout page describes the class's own `begin/end/capacity` object state rather than a free helper record. 2026-06-08 live IDA MCP reconfirmed the exact helper starts and sizes: destructor `0x00493f10` size `0x6a`, grow/insert `0x0049cc40` size `0x209`, and push-back `0x00584910` size `0x7c`. The same live pass reconfirmed caller fan-in for all three helpers and callee sets through the string-handle construct/destroy helpers, supporting the 4-byte string-handle slot model.

## Recovered Metadata Caveats

Live IDA reports `GrowAndInsert` start `0x0049cc40` with size `0x209`, making `0x0049ce48` the last executable byte, while earlier metadata records an end around `0x0049ce23`. Use IDA-confirmed function size for memory-range decisions.

## Score Rationale

| Score | Rationale |
| --- | --- |
| Completion `88` | The page now records all three high-confidence child helpers, the accepted formal class declaration and `SimpleUStringHandle` typedef, the attached StringUtil parent, live IDA range/caller/callee evidence, 4-byte slot behavior, vector triplet layout, metadata caveats, and the direct layout-type ownership audit. Completion remains capped because exact original public API spelling and file split remain inferred. |
| Confidence `89` | Confidence is strong for StringUtil utility ownership and vector behavior because live IDA confirms ranges, decompilation shape, caller sets, child helpers, padding, and the pointer-slot model. It remains below final-source confidence because the original source could still have split this helper into a narrower string-vector implementation file. |

## Cross-References

- File: [UID:0000OB][StringUtil](by-file/StringUtil.md)
- Memory: [UID:000112][0x00493f10-0x00493f79.SimpleUStringVectorDestructor](by-memory/0x00493f10-0x00493f79.SimpleUStringVectorDestructor.md), [UID:00012G][0x0049cc40-0x0049ce48.SimpleUStringVectorGrowAndInsert](by-memory/0x0049cc40-0x0049ce48.SimpleUStringVectorGrowAndInsert.md), [UID:0001J4][0x00584910-0x0058498b.SimpleUStringVectorPushBack](by-memory/0x00584910-0x0058498b.SimpleUStringVectorPushBack.md)
- Layout: [UID:0001W6][SimpleUStringVectorLayout](by-type/by-struct/SimpleUStringVectorLayout.md)
- Related: [UID:0000D9][SimpleUString](by-class/SimpleUString.md), [UID:0000IN][DATFile](by-file/DATFile.md), [UID:0000IE][Config](by-file/Config.md), [UID:0000DD][Socket](by-class/Socket.md)

## Changes

- 2026-07-01 B007 [UID:0000OB][StringUtil](by-file/StringUtil.md) implementation callback: raised score to `88/89`, inserted the accepted `SimpleUStringVector` formal class declaration and `SimpleUStringHandle` typedef, and preserved the pointer-slot versus inline-SSO distinction.
- 2026-06-25 B010 [UID:0002RQ][0x00583970-0x00584052.StringBaseReplaceTrimAndLocks](by-memory/0x00583970-0x00584052.StringBaseReplaceTrimAndLocks.md) support sync:
  - Score unchanged.
  - Evidence: updated the two `0x005839c0` caller descriptions from stale `StringBase replace worker` / generic mutation wording to `StringBase delimiter split/tokenization helper` while preserving direct [UID:0000DA][SimpleUStringVector](by-class/SimpleUStringVector.md) ownership for push-back/grow helpers.
- Before: completion/confidence were unevaluated at `0/0`.
- Changed to: completion `78`, confidence `76`.
- Evidence: the page documents container layout, likely utility placement, destructor/grow/push-back ranges, key callers, layout cross-reference, and metadata range caveat; completion remains limited because it lacks source-ready C++ and full caller inventory.

- 2026-05-31: Corrected the vector element model and exact memory ranges.
  - Before: the page described contiguous `SimpleUString` elements without spelling out the recovered slot size and kept reconstructable metadata blank.
  - After: marked the class reconstructable, documented 4-byte pointer-backed string-handle slots, linked the last-byte-inclusive function pages, and raised scores to `82/84`.
  - Evidence: IDA MCP decompilation of the destructor, grow/insert, and push-back helpers shows pointer differences shifted by two and slot construction/destruction through string-handle helpers; byte checks confirm padding after each corrected function range.
- 2026-06-04 live IDA attachment pass:
  - Before: `COMPLETION:82`, `CONFIDENCE:84`, `AUTOGEN_PARENT_UID` blank, and stale metadata caveat wording.
  - After: `COMPLETION:84`, `CONFIDENCE:88`, `AUTOGEN_PARENT_UID:0000OB`, and live IDA evidence/caller counts recorded.
  - Evidence: live IDA reconfirmed destructor/grow/push-back bounds, 4-byte slot arithmetic, child helper calls, caller counts, and padding. C++ remains blank because final API/source split remains below the 95/95 gate.
- 2026-06-08 A002 Batch129 parent-gate refresh:
  - Before: `COMPLETION:84`, `CONFIDENCE:88`.
  - After: `COMPLETION:85`, `CONFIDENCE:88`.
  - Evidence: added the direct owner audit for [UID:0001W6][SimpleUStringVectorLayout](by-type/by-struct/SimpleUStringVectorLayout.md) and refreshed live IDA MCP evidence for the destructor, grow/insert, and push-back helper starts, caller sets, and callees. Confidence remains unchanged because the final public API/source split remains provisional.
- 2026-06-10 B001-016 split audit:
  - Changed to: no score change.
  - Evidence: [UID:000112][0x00493f10-0x00493f79.SimpleUStringVectorDestructor](by-memory/0x00493f10-0x00493f79.SimpleUStringVectorDestructor.md) was raised to `85/89` and rerouted from direct file parent [UID:0000OB][StringUtil](by-file/StringUtil.md) to this class after IDA MCP reconfirmed the destructor range, decompilation, disassembly, caller/callee set, padding, and vector triplet layout.
- 2026-06-17 B002 source-quality execution:
  - Changed to: no score change.
  - Evidence: [UID:00012G][0x0049cc40-0x0049ce48.SimpleUStringVectorGrowAndInsert](by-memory/0x0049cc40-0x0049ce48.SimpleUStringVectorGrowAndInsert.md) was raised to `86/90` and rerouted from direct file parent [UID:0000OB][StringUtil](by-file/StringUtil.md) to this class after B002 reconfirmed the exact function body/padding, seven caller xrefs, 4-byte string-handle element semantics, target-local range copy/destroy helpers, shared StringBase handle dependencies, and source-authored vector-method treatment.
- 2026-06-17 B001 source-quality execution:
  - Changed to: no score change.
  - Evidence: [UID:0001J4][0x00584910-0x0058498b.SimpleUStringVectorPushBack](by-memory/0x00584910-0x0058498b.SimpleUStringVectorPushBack.md) was raised to `86/90` and rerouted from direct file parent [UID:0000OB][StringUtil](by-file/StringUtil.md) to this class after B001 reconfirmed exact body/padding, two caller xrefs from the StringBase split/tokenization helper, 4-byte string-handle append semantics, share/refcount and private-copy fast paths, slow-path delegation to [UID:00012G][0x0049cc40-0x0049ce48.SimpleUStringVectorGrowAndInsert](by-memory/0x0049cc40-0x0049ce48.SimpleUStringVectorGrowAndInsert.md), and source-authored vector-method treatment.
