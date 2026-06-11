*** UID:0001YN | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# RingBuffer Vtables

## Status

- Entity kind: MSVC vtable inventory
- Owner module: [UID:0000N8][RingBuffer](by-file/RingBuffer.md)
- Owner classes: [UID:0000C1][RingBuffer](by-class/RingBuffer.md), [UID:0000C2][RingBufferIterator](by-class/RingBufferIterator.md)
- Confidence: confirmed vtable addresses, slots, boundaries, and vptr-store sites; medium only for final public/private source exposure of `RingBufferIterator`.
- Exact by-memory child/evidence range: [UID:0002OQ][0x006230c8-0x006230e8.RingBufferVtableData](by-memory/0x006230c8-0x006230e8.RingBufferVtableData.md)
- Evidence: 2026-05-26 and 2026-06-01 IDA MCP `py_eval` over function objects, raw helper starts, vtable entries, complete-object-locator pointers, and data xrefs.

## RingBuffer

IDA names the primary table as `??_7RingBuffer@@6B@` at `0x006230cc`. The complete-object-locator pointer is immediately before the table at `0x006230c8`.

| Slot | Target | Notes |
| --- | --- | --- |
| `+0x00` | `0x005567b0` | `RingBuffer` scalar deleting destructor. |
| `+0x04` | `0x004f4b10` | Shared `LObject` virtual. |
| `+0x08` | `0x0041b6c0` | `nullsub_18`. |

Observed stores/xrefs to the table base:

- `0x00556408`: constructor vptr store.
- `0x00556508`: non-deleting cleanup body reinstalls the vptr before destruction.
- `0x005567df`: scalar deleting destructor vptr store.

The dword at `0x006230d8` is adjacent RTTI data for `RingBufferIterator`, not a fourth `RingBuffer` virtual slot.

## RingBufferIterator

IDA names the companion table as `??_7RingBufferIterator@@6B@` at `0x006230dc`. The complete-object-locator pointer is immediately before the table at `0x006230d8`.

| Slot | Target | Notes |
| --- | --- | --- |
| `+0x00` | `0x00556890` | `RingBufferIterator` scalar deleting destructor. |
| `+0x04` | `0x004f4b10` | Shared `LObject` virtual. |
| `+0x08` | `0x0041b6c0` | `nullsub_18`. |

Observed store/xref to the table base:

- `0x005566d7`: raw constructor-shaped body stores the iterator vptr.

The dword at `0x006230e8` is adjacent RTTI data for the next class (`ScreenPane`), not a fourth iterator virtual slot.

## Boundary Evidence

IDA MCP `py_eval` on 2026-06-01 confirms the exact data island boundaries:

| Address | Observed value | Interpretation |
|---|---|---|
| `0x006230c4` | `0x00000000` | Terminator after the preceding menu string data. |
| `0x006230c8` | `0x0064edb8` -> `??_R4RingBuffer@@6B@` | `RingBuffer` complete-object-locator pointer. |
| `0x006230cc` | `0x005567b0` -> `sub_5567B0` | Start of `??_7RingBuffer@@6B@`. |
| `0x006230d8` | `0x0064ee04` -> `??_R4RingBufferIterator@@6B@` | `RingBufferIterator` complete-object-locator pointer. |
| `0x006230dc` | `0x00556890` -> `sub_556890` | Start of `??_7RingBufferIterator@@6B@`. |
| `0x006230e8` | `0x0064ee50` -> `??_R4ScreenPane@@6B@` | Next class boundary; excluded from this vtable family. |

The 2026-06-07 A004 Batch 013 read-only IDA MCP refresh reconfirmed the same layout and added current xref details:

- `0x006230cc` is referenced by vptr stores at `0x00556408`, `0x00556508`, and `0x005567df`.
- `0x006230dc` is referenced by the raw `RingBufferIterator` constructor-shaped vptr store at `0x005566d7`.
- Slot targets still resolve to `0x005567b0-0x00556887`, `0x004f4b10-0x004f4b16`, `0x0041b6c0-0x0041b6c3`, and `0x00556890-0x005568c8`.
- The predecessor terminator at `0x006230c4` and successor `ScreenPane` COL pointer at `0x006230e8` keep [UID:0002OQ][0x006230c8-0x006230e8.RingBufferVtableData](by-memory/0x006230c8-0x006230e8.RingBufferVtableData.md) as the exact child range.

## Child Routing Gate

[UID:0002OQ][0x006230c8-0x006230e8.RingBufferVtableData](by-memory/0x006230c8-0x006230e8.RingBufferVtableData.md) uses this page as its detailed slot/layout evidence, but its autogen parent is now [UID:0000N8][RingBuffer](by-file/RingBuffer.md). A003 Batch 065 found that generated memory coverage rejects this nested by-vtable UID as an autogen parent (`autogen_parent_unknown`), while the file root now clears the corrected gate at `86/85` and directly owns the declarations that emit both vtables. This by-vtable page remains reconstructable evidence at `86/90`, but it stays autogen-unassigned upward until a later source-declaration routing pass can attach it without reintroducing generated coverage errors.

## Wave3 Status

Wave3 now emits both classes from the shared `util/RingBuffer.cpp` module. The live generated metadata reports one vtable for `RingBuffer` at `0x006230cc` and one vtable for `RingBufferIterator` at `0x006230dc`.

Current active source emits the main queue and iterator methods. Raw helper bytes that are still not IDA function objects are accounted in Wave3 memory coverage as reviewed class ranges: `0x00556670`, `0x005566a0`, and `0x005566b0` on `RingBuffer`, plus `0x00556700` on `RingBufferIterator`. The constructor-shaped `0x005566c0` body is active as the `RingBufferIterator` constructor.

## Score Rationale

Completion is now `86` because the page documents both COL pointers, both three-slot vtables, all slot targets, vptr-store xrefs, predecessor/successor boundaries, the exact by-memory child, and the assignment-gate rationale. Confidence is now `90` for the vtable-layout claims after the 2026-06-07 IDA MCP refresh; confidence is not higher because source-level exposure of the iterator companion is still resolved only as a file-local/class-layout question in the class/file docs.

## Cross-References

- [UID:0000N8][RingBuffer](by-file/RingBuffer.md)
- [UID:0000C1][RingBuffer](by-class/RingBuffer.md)
- [UID:0000C2][RingBufferIterator](by-class/RingBufferIterator.md)
- [UID:0001G4][0x005563d0-0x005568c8.RingBuffer](by-memory/0x005563d0-0x005568c8.RingBuffer.md)
- [UID:0002OQ][0x006230c8-0x006230e8.RingBufferVtableData](by-memory/0x006230c8-0x006230e8.RingBufferVtableData.md)
- [Wave3 data issues](../../wave3_data_issues.md)

## Changes

- 2026-06-01:
  - Before: the page was marked `0/0` despite already containing useful vtable-slot documentation, and the exact by-memory vtable-data child was missing.
  - Changed to: scored the page as `84/89`, marked it reconstructable, added exact child [UID:0002OQ][0x006230c8-0x006230e8.RingBufferVtableData](by-memory/0x006230c8-0x006230e8.RingBufferVtableData.md), and recorded the `0x006230c8-0x006230e8` boundary evidence.
  - Summary/evidence: IDA MCP `py_eval` confirms both complete-object-locator pointers, both three-slot vtables, vptr stores at `0x00556408`, `0x00556508`, `0x005567df`, and `0x005566d7`, and the next `ScreenPane` boundary at `0x006230e8`.
- 2026-06-07 A004 Batch 013 associated-parent refresh:
  - Before: the page was `84/89`, just below the corrected parent-assignment gate for exact child [UID:0002OQ][0x006230c8-0x006230e8.RingBufferVtableData](by-memory/0x006230c8-0x006230e8.RingBufferVtableData.md).
  - Changed to: raised to `86/90`, added the 2026-06-07 IDA MCP xref refresh, and recorded that the exact RingBuffer vtable-data child is now assigned here while this by-vtable page remains unassigned upward.
  - Summary/evidence: the refreshed child page and IDA MCP pass confirm the exact dword sequence, slot targets, RingBuffer and RingBufferIterator vptr-store sites, and `ScreenPane` successor boundary; local vtable-data precedent supports by-memory-to-by-vtable parent attachment.
- 2026-06-07 A003 Batch 065 coverage-error repair:
  - Before: [UID:0002OQ][0x006230c8-0x006230e8.RingBufferVtableData](by-memory/0x006230c8-0x006230e8.RingBufferVtableData.md) pointed at this by-vtable UID and generated memory coverage reported `autogen_parent_unknown`.
  - Changed to: kept this page as the `86/90` by-vtable evidence inventory, but rerouted the exact memory child to [UID:0000N8][RingBuffer](by-file/RingBuffer.md) after that file reached `86/85`.
  - Summary/evidence: the file root owns the source declarations that emit both vtables and satisfies the corrected parent gate; this page remains the canonical slot/COL/xref inventory rather than the autogen parent.
