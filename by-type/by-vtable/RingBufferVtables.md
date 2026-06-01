*** UID:0001YN | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:89 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
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
- Confidence: confirmed vtable addresses and slots; medium for final `RingBufferIterator` source identity.
- Exact by-memory child: [UID:0002OQ][0x006230c8-0x006230e8.RingBufferVtableData](by-memory/0x006230c8-0x006230e8.RingBufferVtableData.md)
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

## Wave3 Status

Wave3 now emits both classes from the shared `util/RingBuffer.cpp` module. The live generated metadata reports one vtable for `RingBuffer` at `0x006230cc` and one vtable for `RingBufferIterator` at `0x006230dc`.

Current active source emits the main queue and iterator methods. Raw helper bytes that are still not IDA function objects are accounted in Wave3 memory coverage as reviewed class ranges: `0x00556670`, `0x005566a0`, and `0x005566b0` on `RingBuffer`, plus `0x00556700` on `RingBufferIterator`. The constructor-shaped `0x005566c0` body is active as the `RingBufferIterator` constructor.

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
