*** UID:0000AT | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:93 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000MQ | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000MQ | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
#include "PrimeNumberGenerator.h"

#include <string.h>

[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
#ifndef NEXUSTK_UTIL_PRIMENUMBERGENERATOR_H
#define NEXUSTK_UTIL_PRIMENUMBERGENERATOR_H

#include <deque>

class PrimeNumberGenerator
{
public:
    explicit PrimeNumberGenerator(int limit);
    virtual ~PrimeNumberGenerator();

    int GetPrimeAt(int index) const;

private:
    unsigned int *m_sieveBits;
    std::deque<int> m_primes;
};

#endif
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# PrimeNumberGenerator

## Status

- Confidence: strong for complete behavior, class layout, vtable/RTTI identity, CPP/H composition, and utility ownership; current IDA evidence still does not prove active runtime construction.
- Likely source file: [UID:0000MQ][PrimeNumberGenerator](by-file/PrimeNumberGenerator.md)
- Address ranges: [UID:0001FA][0x0054bcc0-0x0054bcec.PrimeNumberGeneratorGetPrimeAt](by-memory/0x0054bcc0-0x0054bcec.PrimeNumberGeneratorGetPrimeAt.md) and [UID:0001FB][0x0054bcf0-0x0054c15a.PrimeNumberGenerator](by-memory/0x0054bcf0-0x0054c15a.PrimeNumberGenerator.md)
- Historical remnant lead: earlier documentation named `source-3/simroot_v2/class_PrimeNumberGenerator.cpp`; that absent path is not current source truth.
- Imported source file: `PrimeNumberGenerator.cpp`
- Vtable: [UID:0001YG][PrimeNumberGeneratorVtable](by-type/by-vtable/PrimeNumberGeneratorVtable.md)
- UID0001FB callback state: [UID:0001FB][0x0054bcf0-0x0054c15a.PrimeNumberGenerator](by-memory/0x0054bcf0-0x0054c15a.PrimeNumberGenerator.md) is class-owned at `93/92` and emits the exact constructor plus empty destructor at CPP position `20`. No child split is required because the aggregate can represent the source methods while its compiler/STL subranges remain documented and non-emitting.

## Batch 123 Parent-Gate Audit

This historical parent-gate audit established that the class cleared the then-current strict `85/85` gate. The evidence remains valid and class-level: the constructor writes the one-slot vtable at `0x00622420`, the scalar deleting destructor is the only slot target, the layout page records the vptr at `+0x00`, and [UID:0002OK][0x0062241c-0x00622424.PrimeNumberGeneratorVtableData](by-memory/0x0062241c-0x00622424.PrimeNumberGeneratorVtableData.md) records the exact RTTI/vtable island and neighboring boundaries. Current callback scores are `93/92` for this class and `94/93` for [UID:0000MQ][PrimeNumberGenerator](by-file/PrimeNumberGenerator.md); this class remains the direct owner for [UID:0001YG][PrimeNumberGeneratorVtable](by-type/by-vtable/PrimeNumberGeneratorVtable.md) and the concrete vtable-data child.

2026-07-08 B006 refreshed the exact UID0002OK child to `88/93` with a formal generated-binary marker. Current MCP session `2cb2455b` confirmed `0x0062241c -> 0x0064e318`, `0x00622420 -> 0x0054c110`, `0x00622424 -> 0x0064e360`, local `??_7PrimeNumberGenerator@@6B@` at `0x00622420`, vtable stores at `0x0054bd20`, `0x0054c074`, and `0x0054c11a`, and unique signature `18 E3 64 00 10 C1 54 00`. This updates the child evidence and empty-emitter state only; this class page keeps its `86/87` score and file route.

## 2026-06-16 Evidence Refresh

Live IDA MCP against `NexusTK.exe` rechecked the unresolved active-use and raw-helper blockers for this class:

- `lookup_funcs` still reports raw accessor `0x0054bcc0` as `Not a function`, constructor `0x0054bcf0` size `0x372`, Deque element helper `0x0054c0c0` size `0x50`, and scalar deleting destructor `0x0054c110` size `0x4a`.
- `xrefs_to` still reports zero direct refs to the raw accessor and constructor. The only `0x0054c0c0` ref is the raw accessor call at `0x0054bce1`, and the only destructor target ref is the vtable slot at `0x00622420`.
- `xrefs_to 0x00622420` still returns the constructor/destructor-family vptr writes at `0x0054bd20`, raw cleanup island write `0x0054c074`, and scalar deleting destructor write `0x0054c11a`.
- `callees` confirms the constructor fanout through allocation, memset, sieve/support helpers, [UID:0001FD][0x0054c160-0x0054c1f1.DequeClear](by-memory/0x0054c160-0x0054c1f1.DequeClear.md), and free; the Deque element helper has no callees, and the deleting destructor calls `DequeClear` plus delete support.

This resolves the source-quality question far enough to raise confidence above the parent gate: there is no evidence for a feature-local owner or stale merged range, and the remaining blocker is a real negative-use result rather than an uninvestigated caller gap. B005's later source-quality pass resolves the raw accessor enough for a target-local first draft while preserving the active-use caveat below final-audit confidence.

## Class Purpose

`PrimeNumberGenerator` precomputes prime numbers using a wheel-factored sieve over candidates of the form `6k - 1` and `6k + 1`. It clamps the requested maximum to `100..10000000`, seeds primes `2` and `3`, appends discovered primes to an embedded deque, and frees the temporary sieve bitfield after construction.

The class has a vtable and scalar deleting destructor, but current IDA caller checks do not show direct runtime construction. Treat it as a utility/legacy class until a concrete construction site is found.

## Method Notes

| Method or helper | Address | Role |
| --- | --- | --- |
| `GetPrimeAt(int index) const` | [UID:0001FA][0x0054bcc0-0x0054bcec.PrimeNumberGeneratorGetPrimeAt](by-memory/0x0054bcc0-0x0054bcec.PrimeNumberGeneratorGetPrimeAt.md) | Inferred/descriptive raw indexed accessor. Returns `2` for negative indexes; otherwise clamps the requested index to the last generated prime and reads the value through the embedded `m_primes` deque. |
| constructor/destructor aggregate | [UID:0001FB][0x0054bcf0-0x0054c15a.PrimeNumberGenerator](by-memory/0x0054bcf0-0x0054c15a.PrimeNumberGenerator.md) | Class-owned contiguous method island. It emits the complete constructor and empty destructor source while preserving the mixed EH/cleanup/UID0001FC/deleting-destructor subranges as non-emitting compiler consequences. |
| constructor | `0x0054bcf0-0x0054c062` | Initializes the vtable and embedded deque, clamps the limit to `100..10000000`, seeds `2` and `3`, performs the exact paired wheel sieve, appends discovered primes, and frees temporary sieve storage. The broad aggregate is an evidence-backed equivalent representation, so no new split is required for source emission. |
| destructor | Source cause spanning raw cleanup and deleting-wrapper forms | Exact hand-authored source is an empty virtual destructor. Native `std::deque<int>` cleanup, the raw clone at `0x0054c070`, and scalar deleting destructor at `0x0054c110` are compiler consequences and are not separately emitted. |
| scalar deleting destructor | `0x0054c110-0x0054c15a` | Restores the vtable, clears the embedded deque twice, frees backing storage, and conditionally deletes `this`; it remains compiler-generated from `virtual ~PrimeNumberGenerator()` and is never hand-emitted as an ordinary method. |
| Deque element-address helper | [UID:0001FC][0x0054c0c0-0x0054c110.DequeElementAddressHelper](by-memory/0x0054c0c0-0x0054c110.DequeElementAddressHelper.md) | Non-emitting MSVC/Dinkumware [UID:0000IR][Deque](by-file/Deque.md) support used by the raw accessor; not prime-specific class logic. |

## Source Composition And Complete Method Inventory

`PrimeNumberGenerator.h` owns the include guard, `<deque>`, public constructor, virtual destructor, exact accessor declaration, private temporary `unsigned int *m_sieveBits`, and native `std::deque<int> m_primes`. `PrimeNumberGenerator.cpp` includes that header and `<string.h>`, then receives three ordered CPP children:

| Position | UID | Contribution |
| ---: | --- | --- |
| `10` | UID0001FA | Exact `GetPrimeAt(int) const` body. |
| `20` | UID0001FB | Exact constructor and empty virtual destructor. |
| `30` | UID0002OK | Comment-only compiler-generated RTTI/vtable marker. |

The constructor preserves the exact paired-loop quirk: for `upperCandidate = 7; upperCandidate <= limit; upperCandidate += 6`, it tests `upperCandidate - 2` and then `upperCandidate`. It marks multiples starting at the candidate itself, only while `multiple < limit`, and only when the residue is `1` or `5` modulo `6`. Consequently, a terminal `6k-1` candidate can be omitted when its paired upper candidate exceeds the limit; source must not normalize this boundary.

Complete compiler-bound inventory is documented rather than emitted: fourteen `0xcc` bytes at `0x0054c062-0x0054c070`; raw destructor clone `0x0054c070-0x0054c09c`; four-byte alignment; constructor cleanup `0x0054c0a0-0x0054c0bc`; four-byte alignment; UID0001FC `0x0054c0c0-0x0054c110`; scalar deleting destructor `0x0054c110-0x0054c15a`; and six-byte alignment before UID0001FD. Detached constructor tails at `0x00606270-0x0060627b` and `0x0060627b-0x00606296`, plus `UnwindMapEntry` `0x0066392c-0x00663934` and `FuncInfo` `0x00663934-0x00663958`, are compiler EH state, not extra source methods.

The vtable/layout/RTTI source cause is fully represented by this header: UID0001VL and UID0001YG remain direct class-owned documentation views with no emitter, while UID0002OK retains only its explicit compiler-generated marker. There is no class-owned global, static table, resource, custom import, or additional method on current evidence.

## Layout Notes

See [UID:0001VL][PrimeNumberGeneratorLayout](by-type/by-struct/PrimeNumberGeneratorLayout.md). The confirmed local layout is a 28-byte object:

- `+0x00`: `PrimeNumberGenerator` vtable pointer (`0x00622420`).
- `+0x04`: temporary sieve bitfield pointer, allocated during construction and freed before returning.
- `+0x08..+0x18`: old-MSVC `std::deque<int> m_primes`; `+0x18` is the implementation size/count field used by `GetPrimeAt`, not a separate PrimeNumberGenerator scalar.

## Evidence Notes

- IDA MCP `lookup_funcs` confirms `0x0054bcf0` size `0x372`, `0x0054c110` size `0x4a`, and Deque helper `0x0054c0c0` size `0x50`.
- IDA MCP disassembly confirms raw function-shaped accessor code at `0x0054bcc0-0x0054bcec`, though `lookup_funcs` does not model it as a function.
- IDA MCP decompilation of `0x0054c0c0` shows `frontIndex + index` block-map addressing over 4-byte entries, matching [UID:0001U2][DequeLayout](by-type/by-struct/DequeLayout.md).
- IDA MCP `callers` shows [UID:0001FD][0x0054c160-0x0054c1f1.DequeClear](by-memory/0x0054c160-0x0054c1f1.DequeClear.md) is called from the constructor and destructor, while the `PrimeNumberGenerator` constructor/destructor themselves have no direct callers in the current IDB.
- IDA MCP `xrefs_to 0x00622420` shows vtable writes from the constructor/destructor and the vtable entry pointing at the deleting destructor.
- 2026-06-07 A001 exact vtable-data audit on [UID:0002OK][0x0062241c-0x00622424.PrimeNumberGeneratorVtableData](by-memory/0x0062241c-0x00622424.PrimeNumberGeneratorVtableData.md) reconfirmed `0x0062241c -> ??_R4PrimeNumberGenerator@@6B@`, `0x00622420 -> 0x0054c110`, constructor/destructor vtable writes at `0x0054bd20`, `0x0054c074`, and `0x0054c11a`, and neighboring boundaries before `PursuitMessageDialogPane` RTTI at `0x00622424`.
- 2026-07-08 B006 UID0002OK callback: live MCP session `2cb2455b` refreshed the vtable-data child with health ok, exact bytes `18 e3 64 00 10 c1 54 00`, data-cell non-function status, `sub_54C110` size `0x4a`, the same three vtable-base stores, no direct constructor xrefs, and the formal marker that validator-owned generated output now emits for UID0002OK instead of the previous generated `Empty Emitter Marker`.
- 2026-05-26 recheck: active generated output still omits the raw accessor and the Deque element-address helper; `class_PrimeNumberGenerator.meta_wave3` still carries carriage-return-suffixed method names in history/current-name data.
- 2026-05-26 IDA `py_eval` recheck confirms the one-slot vtable at `0x00622420`: RTTI pointer at `0x0062241c`, deleting destructor slot `0x0054c110`, and next class RTTI pointer at `0x00622424`.
- Current `source-3/simroot_v2/class_PrimeNumberGenerator.meta_wave3` still reports `vtable_count: 0`, so [UID:0001YG][PrimeNumberGeneratorVtable](by-type/by-vtable/PrimeNumberGeneratorVtable.md) is the current table inventory anchor.
- Generated metadata describes the embedded container at `+0x08` as a deque-like container with node/map/capacity/head/count fields.
- 2026-06-18 B005 recheck promoted [UID:0001FA][0x0054bcc0-0x0054bcec.PrimeNumberGeneratorGetPrimeAt](by-memory/0x0054bcc0-0x0054bcec.PrimeNumberGeneratorGetPrimeAt.md) to direct class ownership and first-draft source as `int GetPrimeAt(int index) const`. The method name is descriptive rather than symbol-proven because current docs and raw route scans still show no direct callers, but the binary behavior is exact: signed negative indexes return `2`, high indexes clamp through native `m_primes.size() - 1` source semantics, and the selected value is read through compiler/STL subscript support [UID:0001FC][0x0054c0c0-0x0054c110.DequeElementAddressHelper](by-memory/0x0054c0c0-0x0054c110.DequeElementAddressHelper.md). UID0001FC remains under the non-emitting Deque documentation grouping and is not a project utility dependency.
- 2026-07-04 B011 UID0001FB callback uses accepted MCP session `nexustk_supervisor_20260704`: the target range is `0x0054bcf0-0x0054c15a` (`0x46a` / 1130 bytes), `0x0054bcf0` is modeled as `sub_54BCF0` size `0x372`, `0x0054c070` is no-function cleanup that writes vtable `0x00622420` and clears/frees embedded deque state, `0x0054c0a0` is associated with `sub_54BCF0` as `loc_54C0A0` constructor EH cleanup, `0x0054c110` is the scalar deleting destructor size `0x4a`, and direct constructor xrefs remain absent. That supports class-owned aggregate emission while preserving the active-use confidence cap.
- 2026-08-13 B005 whole-file evidence resolves the marker-only endpoint: exact behavior, detached EH chunks/records, raw clone, scalar deleting wrapper, support-helper split, and padding are independently bounded, so UID0001FB can emit only the two hand-authored source methods without pretending compiler artifacts are source. Bounded xrefs remain zero for accessor/constructor entries; this caps active-use confidence but does not block source.

## Score Rationale

| Field | Value | Rationale |
| --- | ---: | --- |
| Completion | `93` | The class now has complete reusable H output, CPP include/child composition, exact source method ordering, complete compiler-bound inventory, virtual-destructor source cause, and synchronized direct type/data children. |
| Confidence | `92` | RTTI, vtable writes, layout, accessor, constructor behavior, EH graph, and native deque consequences converge. The score remains below `95` because active construction, exact original identifier spelling, and exact MSVC/Dinkumware revision are unproven. |

## Cross-References

- [UID:0000MQ][PrimeNumberGenerator](by-file/PrimeNumberGenerator.md)
- [UID:0001FA][0x0054bcc0-0x0054bcec.PrimeNumberGeneratorGetPrimeAt](by-memory/0x0054bcc0-0x0054bcec.PrimeNumberGeneratorGetPrimeAt.md)
- [UID:0001FB][0x0054bcf0-0x0054c15a.PrimeNumberGenerator](by-memory/0x0054bcf0-0x0054c15a.PrimeNumberGenerator.md)
- [UID:0001VL][PrimeNumberGeneratorLayout](by-type/by-struct/PrimeNumberGeneratorLayout.md)
- [UID:0001YG][PrimeNumberGeneratorVtable](by-type/by-vtable/PrimeNumberGeneratorVtable.md)
- [UID:0000IR][Deque](by-file/Deque.md)
- [UID:0001FC][0x0054c0c0-0x0054c110.DequeElementAddressHelper](by-memory/0x0054c0c0-0x0054c110.DequeElementAddressHelper.md)
- [UID:0001QA][client_containers](by-meta/client_containers.md)

## Changes

- 2026-08-13 B005 UID0000MQ whole-file implementation callback:
  - Before: score `86/87`, class declaration embedded in CPP, blank H block, marker-only UID0001FB endpoint, and stale absent-remnant/current-score wording.
  - Changed to: score `93/92`; exact `PrimeNumberGenerator.h` declaration and guard; CPP header/`<string.h>` scaffold; ordered children `10/20/30`; complete method/compiler-bound inventory; exact paired-loop caveat; and current layout/vtable non-emitting source-cause disposition.
  - Preserved the no-direct-construction confidence cap, descriptive identifier caveat, native deque ownership, and all earlier evidence/history.

- 2026-07-12 B003 UID000149 caller synchronization:
  - Preserved score `86/87`, class/file ownership, and child routing.
  - Added the coherent class declaration with `<deque>`, `std::deque<int> m_primes`, constructor/destructor declarations, and `GetPrimeAt`; no unrelated constructor body was invented.
  - Historical custom Deque field/API direction is superseded by native `std::deque<int>` source.

- 2026-07-04 B011 UID0001FB implementation sync:
  - Updated method notes to mark [UID:0001FB][0x0054bcf0-0x0054c15a.PrimeNumberGenerator](by-memory/0x0054bcf0-0x0054c15a.PrimeNumberGenerator.md) as a class-owned aggregate marker rather than a blank unresolved constructor/destructor cluster.
  - Added the scalar deleting destructor caveat, UID0001FC non-emitting standard-library support split, and current MCP-backed active-use cap.
  - Kept the source file route under [UID:0000MQ][PrimeNumberGenerator](by-file/PrimeNumberGenerator.md) and did not change class metadata in this support-only sync.

- 2026-06-18 B005 [UID:0001FA][0x0054bcc0-0x0054bcec.PrimeNumberGeneratorGetPrimeAt](by-memory/0x0054bcc0-0x0054bcec.PrimeNumberGeneratorGetPrimeAt.md) accessor source-quality pass:
  - Updated class support text to route the raw accessor directly through this class instead of only the file root, using inferred source name `GetPrimeAt(int index) const`.
  - Clarified that `+0x08..+0x18` is embedded `m_primes` deque storage and that object offset `+0x18` is the Deque count used by the accessor.
  - Evidence: B005 raw byte/listing/export and route-scan review reconfirmed the exact raw no-function body, no inbound route, positive-control helper call at `0x0054bce1`, signed-index fallback, high-index clamp, and Deque-helper ownership split.

- 2026-06-16 A002 Goal2 class-confidence refresh:
  - Before: `COMPLETION:85`, `CONFIDENCE:85`.
  - After: `COMPLETION:86`, `CONFIDENCE:87`; owner and emitter remain [UID:0000MQ][PrimeNumberGenerator](by-file/PrimeNumberGenerator.md).
  - Evidence: live IDA MCP reconfirmed the raw accessor non-function status, constructor/destructor/helper sizes, zero direct refs to the accessor and constructor, the sole raw accessor call into the Deque element helper, vtable-slot refs at `0x00622420`, constructor/destructor callee sets, and the lack of a feature-local runtime construction path. The score remains below final-source confidence because active runtime construction, final raw-accessor name, and embedded Deque field declarations are still unresolved.
- 2026-06-08 A002 Batch123 parent-gate refresh:
  - Before: `COMPLETION:84`, `CONFIDENCE:84`; below the strict class-parent gate for [UID:0001YG][PrimeNumberGeneratorVtable](by-type/by-vtable/PrimeNumberGeneratorVtable.md).
  - After: `COMPLETION:85`, `CONFIDENCE:85`.
  - Evidence: added the exact [UID:0002OK][0x0062241c-0x00622424.PrimeNumberGeneratorVtableData](by-memory/0x0062241c-0x00622424.PrimeNumberGeneratorVtableData.md) vtable-data audit to the class page and recorded why the class, not just the source file, is the direct owner for the vtable type/data children. Scores stay at the gate because active runtime construction remains unresolved.
- 2026-06-05: Marked `RECONSTRUCTABLE:TRUE` and assigned parent `0000MQ`.
  - Before: reconstruction autogen classification and parent were blank despite IDA-backed class, file, memory, layout, and vtable evidence for a utility prime-table generator.
  - After: classified as reconstructable source attached to [UID:0000MQ][PrimeNumberGenerator](by-file/PrimeNumberGenerator.md).
  - Evidence: live IDA MCP `lookup_funcs` confirms modeled starts at `0x0054bcf0`, `0x0054c0c0`, `0x0054c110`, and `0x0054c160`; `0x0054bcc0` remains raw accessor code not modeled as an IDA function, matching the existing memory evidence. The class score is `84/84` and parent file score is `84/82`, satisfying the 80/80 attach gate.

- 2026-05-30: Changed completion/confidence from `0/0` to `84/84`.
  - Before: The page was unevaluated even though it contained method ownership, layout, vtable, and IDA evidence.
  - After: Scored as high-completion class documentation with remaining uncertainty around active runtime use and generated-output omissions.
  - Evidence: Existing status, method notes, layout notes, vtable notes, IDA MCP evidence notes, and cross-references document the class at class/file/memory/type levels.
