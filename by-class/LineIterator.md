*** UID:000078 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000NZ | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000NZ | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL:10 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
#include "../../util/StringBase.h"

class LineIterator
{
public:
    LineIterator(const wchar_t *text, unsigned int length)
        : m_text(text),
          m_length(length),
          m_offset(0)
    {
    }

    virtual ~LineIterator()
    {
    }

    mystr::StringBase<wchar_t, mystr::mychar_traits<wchar_t> > &
    ReadNextLine(
        mystr::StringBase<wchar_t, mystr::mychar_traits<wchar_t> > &line);

private:
    const wchar_t *m_text;
    unsigned int m_length;
    unsigned int m_offset;
};

[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# LineIterator

## Status

- Confidence: very strong for layout, behavior, virtual-destructor source cause, vtable data, and local-helper ownership; high for the inferred inline declaration and source placement.
- Source route: file-private helper emitted through [UID:0000NZ][SpelledPane](by-file/SpelledPane.md). [UID:0000KQ][LineIterator](by-file/LineIterator.md) remains a non-source historical index.
- Type/layout docs: [UID:0001UY][LineIteratorLayout](by-type/by-struct/LineIteratorLayout.md), [UID:0001XZ][LineIterator_vtable](by-type/by-vtable/LineIterator_vtable.md)
- Concrete vtable data: [UID:00038W][0x00624780-0x00624788.LineIteratorVtableData](by-memory/0x00624780-0x00624788.LineIteratorVtableData.md)
- C134 compile closure: because this file-private declaration emits before `SpelledPane.h` in `SpelledPane.cpp`, it directly includes `../../util/StringBase.h`. This preserves the established local-helper placement while making `mystr::StringBase` and `mychar_traits` complete before the `ReadNextLine` declaration; moving the class after `SpelledPane.h`, duplicating StringBase declarations, or relying on a PCH is unnecessary and rejected.

## Class Purpose

`LineIterator` is a small helper used to read newline-delimited text from a memory buffer. The visible use is `SpelledPane::ParseAndLoadEntries`, where generated source and IDA decompilation initialize a 16-byte stack object:

```text
+0x00 vtable
+0x04 data pointer
+0x08 length in UTF-16 code units
+0x0c current offset in UTF-16 code units
```

and then repeatedly calls [UID:000190][0x004f3020-0x004f3060.LineIteratorReadNextLine](by-memory/0x004f3020-0x004f3060.LineIteratorReadNextLine.md).

2026-07-07 B011 callback: accepted MCP session `43ccf853` reconfirmed `ReadNextLine` at `0x004f3020-0x004f3060`, the two-only `SpelledPane::ParseAndLoadEntries` call sites `0x0056c15b` and `0x0056c285`, stack construction of the four-dword iterator at `0x0056c133-0x0056c146`, and the one-slot vtable/destructor support. UID000190 now carries first-draft method C++ owned/emitted through this class, with inferred source-facing fields `m_text`, `m_length`, and `m_offset`; this does not by itself finalize the whole class declaration.

## Methods

| Address | Method | Role |
| --- | --- | --- |
| `0x004f3020` | [UID:000190][0x004f3020-0x004f3060.LineIteratorReadNextLine](by-memory/0x004f3020-0x004f3060.LineIteratorReadNextLine.md) | Returns the next UTF-16 line slice, advances `m_offset`, and now has target-specific first-draft C++ on the by-memory page. |
| `0x00573240` | ordinary destructor | Resets the `LineIterator` vtable and returns. |
| `0x00573540` | scalar deleting destructor | Resets vtable, conditionally deletes 16-byte object, returns `this`. |

## Class-Owned Data

| Address | Data | Evidence |
| --- | --- | --- |
| `0x00624780-0x00624788` | [UID:00038W][0x00624780-0x00624788.LineIteratorVtableData](by-memory/0x00624780-0x00624788.LineIteratorVtableData.md) | Complete-object-locator/RTTI dword followed by one vtable slot at `0x00624784 -> 0x00573540`; the next byte range starts the UTF-16 `LOOKEXT.EPF` resource string. |

## Resolved Declaration And Remaining Caveat

`ReadNextLine` is not a virtual slot. The complete migration-ready source declaration is now formalized above: inline two-argument constructor, explicit inline empty virtual destructor, one out-of-line `ReadNextLine`, and three exact data members. The only residual caveat is physical token placement: the binary cannot distinguish a private adjacent header from a source-local declaration in SpelledPane, so the generated route uses the only observed source context without fabricating a standalone translation unit.

2026-05-26 recheck confirms the issue remains current. `lookup_funcs` models `0x004f3020`, `0x00573240`, and `0x00573540`; `xrefs_to 0x00624784` still shows only the stack construction and destructor vtable stores, while `xrefs_to 0x00624788` points to self-look rendering code that uses the adjacent `LOOKEXT.EPF` string.

2026-05-31 IDA MCP recheck confirms the same shape: `sub_4F3020` is called only by `sub_56C0E0` at `0x0056c15b` and `0x0056c285`; `sub_56C0E0` constructs a four-dword stack object with the vtable, data pointer, length, and zero offset; `0x00624784` contains only the scalar deleting destructor slot before the adjacent `LOOKEXT.EPF` string. The old parent/C++ blanking conclusion from that pass is historical and superseded by the 2026-07-15 direct destructor/declaration audit below.

2026-06-04 IDA MCP recheck confirms parent attachment is now justified: `sub_4F3020` is exactly `0x004f3020-0x004f3060`, its only code refs are `0x0056c15b` and `0x0056c285` inside `sub_56C0E0`, and `sub_56C0E0` initializes the four stack dwords at `0x0056c133`, `0x0056c13c`, `0x0056c143`, and `0x0056c146`. The ordinary destructor is exactly `0x00573240-0x00573247`; the scalar deleting destructor is exactly `0x00573540-0x00573564` and deletes a 16-byte block when flag bit 1 is set. The one-slot vtable at `0x00624784` points to `0x00573540`; `0x00624788` is the adjacent `LOOKEXT.EPF` string, not another class slot.

2026-06-12 Agent-A004 Batch 272 IDA MCP recheck confirms the same class boundary and raises the current parent gate: `sub_56C0E0` still constructs the four-dword stack object, `xrefs_to 0x004f3020` still returns only `0x0056c15b` and `0x0056c285`, `xrefs_to 0x00624784` is limited to the stack-constructor store plus ordinary/scalar destructor stores, and the exact vtable child [UID:00038W][0x00624780-0x00624788.LineIteratorVtableData](by-memory/0x00624780-0x00624788.LineIteratorVtableData.md) now routes here. The source form remains a tiny helper used by SpelledPane parsing rather than a proven standalone public class.

2026-07-07 B011 source-quality sync confirms this page is the direct semantic owner for UID000190. The only observed callers remain parser calls inside `sub_56C0E0`, so SpelledPane remains the source context, but ownership stays with the class because the parser stack object has a vtable, destructor stores, and a 16-byte layout. Score moves to `87/90`: stronger than before because the method body, dependency helper, inferred field names, and first-draft readiness are now recorded; still below final-source quality because the complete declaration, destructor emission policy, and final local-helper/file folding remain open.

## Cross-References

- [UID:0000KQ][LineIterator](by-file/LineIterator.md)
- [UID:0001UY][LineIteratorLayout](by-type/by-struct/LineIteratorLayout.md)
- [UID:0001XZ][LineIterator_vtable](by-type/by-vtable/LineIterator_vtable.md)
- [UID:00038W][0x00624780-0x00624788.LineIteratorVtableData](by-memory/0x00624780-0x00624788.LineIteratorVtableData.md)
- [UID:000190][0x004f3020-0x004f3060.LineIteratorReadNextLine](by-memory/0x004f3020-0x004f3060.LineIteratorReadNextLine.md)
- [UID:0001HL][0x00573240-0x00573247.LineIteratorDestructor](by-memory/0x00573240-0x00573247.LineIteratorDestructor.md)
- [UID:0001HO][0x00573540-0x00573564.LineIteratorScalarDeletingDestructor](by-memory/0x00573540-0x00573564.LineIteratorScalarDeletingDestructor.md)
- [UID:0000DK][SpelledPane](by-class/SpelledPane.md)

## Changes

- Completion/confidence score update: existed before as `0/0`; changed to `70/68`. Summary: the helper layout, read-next-line role, destructor addresses, vtable neighborhood, and owner caveats are documented, but this is still not a migration-ready standalone class definition. Evidence: stack-object layout in `SpelledPane::ParseAndLoadEntries`, linked read-line/destructor memory pages, and open vtable/string-boundary cleanup notes.
- 2026-05-31 scoring and reconstructable classification:
  - What existed before: `COMPLETION:70`, `CONFIDENCE:68`, and blank `RECONSTRUCTABLE`.
  - Changed to: `COMPLETION:76`, `CONFIDENCE:82`, and `RECONSTRUCTABLE:TRUE`.
  - Summary/evidence: current IDA MCP reverified the read-line callers, stack layout, vtable slot, destructor stores, and adjacent string boundary. Scores remain below 95 because final original source placement and declaration style are still unresolved.
- 2026-06-04 parent and evidence update:
  - What existed before: scored `76/82`, reconstructable, with blank `AUTOGEN_PARENT_UID`.
  - Changed to: scored `82/86` and attached to [UID:0000KQ][LineIterator](by-file/LineIterator.md).
  - Summary/evidence: live IDA MCP reverified the exact function ranges, two-only `ReadNextLine` callers, four-dword stack construction, ordinary/scalar destructor bodies, delete-size behavior, and one-slot vtable boundary. At that time, original declaration/source placement was treated as a blank-C++ blocker; the 2026-07-07 B011 callback supersedes that blocker for UID000190 while keeping the full class declaration blank.
- 2026-06-12 Agent-A004 Batch 272 parent-gate update:
  - What existed before: scored `82/86`, attached to [UID:0000KQ][LineIterator](by-file/LineIterator.md), and missing the exact vtable-data child.
  - Changed to: scored `86/89`, with [UID:00038W][0x00624780-0x00624788.LineIteratorVtableData](by-memory/0x00624780-0x00624788.LineIteratorVtableData.md) documented as class-owned data.
  - Summary/evidence: live IDA MCP reverified the single `LineIterator` vtable slot, stack-constructor/destructor xrefs, `ReadNextLine` caller-only use, ordinary/scalar destructor bodies, and the `LOOKEXT.EPF` successor boundary; the score remains below 95 because the original declaration form is still unresolved.
- 2026-07-07 Agent-B011 UID000190 callback:
  - What existed before: scored `86/89`, with UID000190 still described as not ready for method C++ under historical threshold language.
  - Changed to: scored `87/90`, preserving owner/emitter through [UID:0000KQ][LineIterator](by-file/LineIterator.md) and keeping this class formal C++ blank.
  - Summary/evidence: accepted B011 report implemented UID000190 as a class-owned first-draft `ReadNextLine` method, with MCP session `43ccf853` proof for two parser callers, four-dword stack setup, inferred `m_text`/`m_length`/`m_offset` fields, `InitializeWideFromRange`, and the existing vtable/destructor support.

## 2026-07-15 B003 UID0001HL Complete Declaration Callback

### Source shape and access model

- LineIterator is a small file-private helper used only by `SpelledPane::ParseAndLoadEntries`. Every observed construction and both UID000190 calls are in that parser; no heap construction, independent static state, registration route, or non-SpelledPane consumer exists.
- The public constructor/destructor/method interface and private fields are the narrowest realistic source-safe declaration. The parser constructs the helper directly, while exact anonymous-namespace or private-header wrapping is not symbol-proven and is not fabricated.
- The inline constructor initializes `m_text`, `m_length`, and `m_offset` in declaration order. Parser stores at `0x0056c133`, `0x0056c143`, and `0x0056c146` plus the compiler vptr store at `0x0056c13c` prove this exact two-argument source shape and the zero initial offset.
- The explicit inline empty virtual destructor is required source, not optional decoration. RTTI hierarchy descriptor `0x006501c4` reports one base descriptor and its array contains only LineIterator; there is no base from which virtual destruction could be inherited.

### Exact layout

| Complete offset | Source member | Evidence |
| --- | --- | --- |
| `+0x00` | implicit compiler vptr | Construction, UID0001HL, and UID0001HO stores all reference `0x00624784`. |
| `+0x04` | `const wchar_t *m_text` | Parser input-pointer store and UID000190 UTF-16 indexing. |
| `+0x08` | `unsigned int m_length` | Parser length store and unsigned UID000190 end comparison. |
| `+0x0c` | `unsigned int m_offset` | Parser zero initialization and UID000190 unsigned cursor update. |

- Exact complete size is `0x10` / 16 bytes, independently confirmed by the parser four-dword object and UID0001HO allocation-release size.
- There is no base subobject, member padding, or tail padding beyond the four dwords on x86. The vptr is compiler-managed and therefore absent from the human member declaration.

### Method and compiler inventory

| Address/data | Disposition |
| --- | --- |
| UID000190 `[0x004f3020,0x004f3060)` | Human out-of-line `ReadNextLine`, nonvirtual, position 20, existing body unchanged. |
| UID0001HL `[0x00573240,0x00573247)` | Live EH-only complete-object materialization of the inline destructor, position 30, covered marker. |
| UID0001HO `[0x00573540,0x00573564)` | Compiler scalar-deleting wrapper, false/non-emitting. |
| UID00038W `[0x00624780,0x00624788)` | Compiler RTTI/COL plus sole deleting-destructor slot, position 40, covered marker. |

- The vtable at `0x00624784` has one slot, UID0001HO. UID000190 is not virtual. Address `0x00624788` begins UTF-16 `LOOKEXT.EPF`, so it is not a second slot.
- UID0001HL is reached only through parser EH thunk `[0x00607b5d,0x00607b65)` after the stack object becomes live. The optimized normal path has no destructor call, which supports an inline empty destructor rather than a handwritten out-of-line definition.

### Source placement, confidence, and rejected alternatives

- Direct class owner/emitter is now UID0000NZ SpelledPane at position 10; `[[CHILDREN]]` is deliberately after the complete class closing `};`, keeping qualified UID000190 and child markers at namespace scope.
- Standalone UID0000KQ source routing is rejected because no independent source responsibility exists. A private adjacent header cannot be excluded, but it does not justify another generated source root.
- Reject an implicit nonvirtual destructor, handwritten out-of-line destructor body, raw aggregate initializer, signed length/offset fields, explicit vptr member/store, source scalar-deleting method, manual operator delete, RTTI/vtable arrays, parser EH/cookie code, raw addresses, and `sub_*` labels.
- Historical blank-declaration and unresolved-placement statements above remain provenance. This callback supersedes them with the complete declaration and raises the score to `92/94`; the remaining confidence cap is exact token/file placement, not behavior or layout.
