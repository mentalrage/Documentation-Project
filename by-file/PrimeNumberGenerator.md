*** UID:0000MQ | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:82 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"NexusTK/util/" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***

# PrimeNumberGenerator

## Status

- Confidence: strong for utility ownership, layout, and vtable identity; unresolved for active runtime use.
- Proposed module: `util/PrimeNumberGenerator.cpp`
- Proposed header: `util/PrimeNumberGenerator.h`
- Current recovered source: `source-3/simroot_v2/class_PrimeNumberGenerator.cpp`
- Main class: [UID:0000AT][PrimeNumberGenerator](by-class/PrimeNumberGenerator.md)
- Main vtable: [UID:0001YG][PrimeNumberGeneratorVtable](by-type/by-vtable/PrimeNumberGeneratorVtable.md)
- Main address docs: [UID:0001FA][0x0054bcc0-0x0054bcec.PrimeNumberGeneratorGetPrimeAt](by-memory/0x0054bcc0-0x0054bcec.PrimeNumberGeneratorGetPrimeAt.md) and [UID:0001FB][0x0054bcf0-0x0054c15a.PrimeNumberGenerator](by-memory/0x0054bcf0-0x0054c15a.PrimeNumberGenerator.md)

## File Role

`PrimeNumberGenerator.cpp` is a small algorithm/container utility source. The recovered class builds a prime table up to a clamped limit using a wheel-factored sieve, stores prime values in an embedded [UID:0000IR][Deque](by-file/Deque.md)-style block container, then frees the temporary sieve bitfield after construction.

Current IDA caller checks show no direct constructor callers in the database, so treat this as recovered utility or legacy support rather than a feature-owned runtime dependency.

## Proposed Contents

| Entity | Address evidence | Role |
| --- | --- | --- |
| [UID:0000AT][PrimeNumberGenerator](by-class/PrimeNumberGenerator.md) | `0x0054bcc0`, `0x0054bcf0`, `0x0054c110` | Raw indexed-prime accessor, sieve constructor, and scalar deleting destructor. |
| [UID:0001VL][PrimeNumberGeneratorLayout](by-type/by-struct/PrimeNumberGeneratorLayout.md) | Ghidra size `0x1c` | Vtable pointer, temporary sieve pointer, and embedded 4-byte-entry deque fields. |
| [UID:0001FC][0x0054c0c0-0x0054c110.DequeElementAddressHelper](by-memory/0x0054c0c0-0x0054c110.DequeElementAddressHelper.md) | IDA function size `0x50` | Generic Deque element-address helper used by the raw prime accessor; document with [UID:0000IR][Deque](by-file/Deque.md), not as PrimeNumberGenerator-owned logic. |

## Evidence Notes

- Active metadata imports `PrimeNumberGenerator` from `PrimeNumberGenerator.cpp` with grade `95.8` and summary "Generates and stores prime numbers using a wheel-factored Sieve of Eratosthenes with deque storage."
- IDA MCP confirms constructor `0x0054bcf0` size `0x372` and scalar deleting destructor `0x0054c110` size `0x4a`.
- IDA MCP disassembly on 2026-05-25 shows raw accessor code at `0x0054bcc0-0x0054bcec`: it returns `2` for negative indexes, clamps high indexes to `count - 1`, then reads the selected value through `0x0054c0c0`.
- IDA MCP decompilation of `0x0054c0c0` shows Deque block-map address arithmetic rather than prime-specific behavior.
- IDA MCP confirms `0x0054c160` size `0x91` as [UID:0001FD][0x0054c160-0x0054c1f1.DequeClear](by-memory/0x0054c160-0x0054c1f1.DequeClear.md), called from the constructor and destructor.
- IDA MCP caller checks return no direct callers for the constructor, destructor, or Deque element-address helper in the current database.
- 2026-05-26 IDA MCP recheck reconfirms the same modeled function boundaries, no modeled callers for constructor/destructor/element-address helper, and the raw `0x0054bce1` xref into the Deque helper.
- Current `simroot_v2` still has no emitted source for `0x0054bcc0` or `0x0054c0c0`.
- IDA MCP xrefs show the vtable at `0x00622420` references the deleting destructor and is written by the constructor/destructor bodies.
- 2026-05-26 IDA `py_eval` recheck confirms `0x00622420` is a one-slot table with RTTI pointer at `0x0062241c`, deleting destructor slot `0x0054c110`, and the next class RTTI pointer at `0x00622424`.
- 2026-05-31 IDA MCP recheck: the raw accessor at `0x0054bcc0` is still not a modeled IDA function, constructor `0x0054bcf0-0x0054c062` and scalar deleting destructor `0x0054c110-0x0054c15a` remain modeled functions, and `0x0054c160-0x0054c1f1` remains the shared Deque clear helper called by both constructor/destructor paths. The vtable slot at `0x00622420` still points to `0x0054c110`, with writes from the constructor/destructor family. No direct constructor/destructor callers are modeled, so active-use confidence remains capped.
- 2026-06-01 IDA MCP recheck confirms the raw accessor exact instruction body at `0x0054bcc0-0x0054bcec`, the modeled constructor/destructor ranges, vtable writes at `0x0054bd20`, `0x0054c074`, and `0x0054c11a`, and raw cleanup helper bodies at `0x0054c070-0x0054c09c` and `0x0054c0a0-0x0054c0bc`. Confidence is now strong enough for source ownership and autogen parenting, though active runtime use remains unresolved.

## Generated Output Caveats

- Active output omits the raw accessor at `0x0054bcc0` and the Deque helper at `0x0054c0c0`; do not silently fold either one into the constructor.
- Active `class_PrimeNumberGenerator.meta_wave3` reports `vtable_count: 0` despite the IDA-confirmed [UID:0001YG][PrimeNumberGeneratorVtable](by-type/by-vtable/PrimeNumberGeneratorVtable.md) at `0x00622420`.
- `class_PrimeNumberGenerator.meta_wave3` still reports stored method-name control characters for constructor `0x0054bcf0` and scalar deleting destructor `0x0054c110`, with `current_name` values ending in `\\r`. That is a data-cleanup issue, not a behavior issue.
- The generated C++ is useful algorithm evidence but uses modernized style and invented container names; final source should match the project's older C++ style when rewritten.

## Source-Structure Decision

Keep this under `util/` beside [UID:0000IR][Deque](by-file/Deque.md), [UID:0000KS][List](by-file/List.md), [UID:0000HZ][CachedHashTable](by-file/CachedHashTable.md), and other reusable containers/algorithm helpers. Nothing in current caller evidence ties it to UI, map, archive, or audio.

## Cross-References

- [UID:0000AT][PrimeNumberGenerator](by-class/PrimeNumberGenerator.md)
- [UID:0001FA][0x0054bcc0-0x0054bcec.PrimeNumberGeneratorGetPrimeAt](by-memory/0x0054bcc0-0x0054bcec.PrimeNumberGeneratorGetPrimeAt.md)
- [UID:0001FB][0x0054bcf0-0x0054c15a.PrimeNumberGenerator](by-memory/0x0054bcf0-0x0054c15a.PrimeNumberGenerator.md)
- [UID:0001VL][PrimeNumberGeneratorLayout](by-type/by-struct/PrimeNumberGeneratorLayout.md)
- [UID:0001YG][PrimeNumberGeneratorVtable](by-type/by-vtable/PrimeNumberGeneratorVtable.md)
- [UID:0000IR][Deque](by-file/Deque.md)
- [UID:0001FC][0x0054c0c0-0x0054c110.DequeElementAddressHelper](by-memory/0x0054c0c0-0x0054c110.DequeElementAddressHelper.md)
- [UID:0001FD][0x0054c160-0x0054c1f1.DequeClear](by-memory/0x0054c160-0x0054c1f1.DequeClear.md)
- [UID:0001QA][client_containers](by-meta/client_containers.md)

## Changes

- Before: completion/confidence were ungraded at `0/0`.
- Changed to: completion `84`, confidence `78`.
- Summary/evidence: the page documents utility role, layout/vtable evidence, proposed contents, IDA boundaries, generated-output caveats, Deque helper split, source placement, and cross-references; confidence remains capped by unresolved active runtime use and omitted generated source bodies.
- 2026-05-31 projected reconstruction path:
  - What existed before: `PROPOSED_RECONSTRUCTION_PATH` was blank.
  - Changed to: `NexusTK/util/`.
  - Summary/evidence: `by-project-structure/proposed-source-tree.md` places `PrimeNumberGenerator.cpp` under `util/`, and the 2026-05-31 IDA MCP pass confirms the class remains a standalone algorithm/container utility with no feature-specific caller ownership.
- 2026-06-01 confidence/autogen parent support:
  - What existed before: confidence was `78`, which was below the threshold used for child autogen parenting even though utility ownership was already strong.
  - Changed to: confidence `82`.
  - Summary/evidence: IDA MCP reconfirmed exact raw accessor behavior, constructor/destructor ranges, raw cleanup helper boundaries, vtable writes, DequeClear calls, and source placement under `NexusTK/util/`; confidence remains capped below class/method pages because there are still no modeled runtime construction callers.
