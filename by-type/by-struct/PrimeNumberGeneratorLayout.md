*** UID:0001VL | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:91 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:93 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000AT | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:FALSE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# PrimeNumberGeneratorLayout

## Status

- Confidence: strong for exact object size, vtable pointer, temporary sieve field, embedded `m_primes` deque offsets, accessor use, lifecycle cleanup, and the class-header source cause; source-facing private-name spelling remains inferred rather than symbol-proven.
- Source root: [UID:0000MQ][PrimeNumberGenerator](by-file/PrimeNumberGenerator.md)
- Primary memory evidence: [UID:0001FB][0x0054bcf0-0x0054c15a.PrimeNumberGenerator](by-memory/0x0054bcf0-0x0054c15a.PrimeNumberGenerator.md)
- Size evidence: constructor field writes through `+0x18` and the embedded [UID:0001U2][DequeLayout](by-type/by-struct/DequeLayout.md) beginning at `+0x08` establish at least `0x1c` bytes.
- Ownership/source attachment: [UID:0000AT][PrimeNumberGenerator](by-class/PrimeNumberGenerator.md), scored `93/92`, owns this documentation-only layout; the source root [UID:0000MQ][PrimeNumberGenerator](by-file/PrimeNumberGenerator.md) is `94/93`. This page intentionally has no emitter because the class H block already expresses the source declaration.
- UID0001FB callback state: [UID:0001FB][0x0054bcf0-0x0054c15a.PrimeNumberGenerator](by-memory/0x0054bcf0-0x0054c15a.PrimeNumberGenerator.md) emits the exact constructor and empty destructor at position `20`. UID0000AT emits `<deque>`, `unsigned int *m_sieveBits`, and native `std::deque<int> m_primes` in the formal H block; no layout source remains deferred.

## Layout Hypothesis

`PrimeNumberGenerator` is a small vtable-bearing object with a temporary sieve pointer and an embedded 4-byte-entry deque:

| Offset | Size | Observed field | Evidence |
| --- | --- | --- | --- |
| `+0x00` | 4 | vtable pointer | Constructor/destructor write `PrimeNumberGenerator::vftable_622420`. |
| `+0x04` | 4 | temporary sieve bitfield pointer | Constructor stores the allocated sieve buffer here and frees it before returning. |
| `+0x08` | 4 | embedded old-MSVC `std::deque<int> m_primes` proxy slot | Constructor zeroes this implementation field, allocates an 8-byte proxy, stores it here, and passes `this + 8` to generated deque support. It is compiler/STL layout, not a project field declaration. |
| `+0x0c` | 4 | embedded `m_primes` deque `+0x04` block map | Used by deque growth/access logic. |
| `+0x10` | 4 | embedded `m_primes` deque `+0x08` block count | Used with power-of-two mask calculations. |
| `+0x14` | 4 | embedded `m_primes` deque `+0x0c` front index | Used when appending and indexing 4-byte entries. |
| `+0x18` | 4 | embedded `m_primes` deque `+0x10` count | Incremented as primes are appended and read by `GetPrimeAt` through native `m_primes.size()` source semantics. |

## Behavior Notes

- The constructor clamps `maxValue` to `100..10000000`.
- The sieve bitfield tracks only wheel candidates related to values of form `6k - 1` and `6k + 1`.
- Native `std::deque<int> m_primes` stores prime values; source executes `m_primes.push_back(2)` and `m_primes.push_back(3)` before later discovered-prime appends, which inline the same push logic.
- The raw indexed accessor at `0x0054bcc0`, drafted as `PrimeNumberGenerator::GetPrimeAt(int index) const`, uses source-facing `m_primes.size()` and `m_primes[index]`; `+0x18` and UID0001FC are old-MSVC implementation details.
- The temporary sieve buffer is not persistent object state after construction returns, despite occupying the `+0x04` field during the constructor.
- UID0001FB's aggregate marker relies on this split: `+0x04` is constructor scratch sieve storage, while `+0x08..+0x18` is the persistent embedded `m_primes` deque used by constructor, accessor, cleanup chunks, and scalar deleting destructor paths.
- 2026-05-26 IDA `py_eval` confirms the [UID:0001YG][PrimeNumberGeneratorVtable](by-type/by-vtable/PrimeNumberGeneratorVtable.md) at `0x00622420`, with the RTTI pointer immediately before it at `0x0062241c`.

## Field Lifetime And Users

- `+0x00` is persistent class identity: the constructor and scalar deleting destructor restore/write the one-slot vtable anchored by [UID:0001YG][PrimeNumberGeneratorVtable](by-type/by-vtable/PrimeNumberGeneratorVtable.md).
- `+0x04` is constructor-scope scratch storage, not a durable public member. The constructor stores the sieve bitfield pointer here while marking candidates and frees the buffer before returning; the destructor does not own this field as long-lived state.
- `+0x08..+0x18` is the persistent embedded `m_primes` deque used after construction. The constructor seeds `2` and `3` and pushes discovered primes; the raw accessor [UID:0001FA][0x0054bcc0-0x0054bcec.PrimeNumberGeneratorGetPrimeAt](by-memory/0x0054bcc0-0x0054bcec.PrimeNumberGeneratorGetPrimeAt.md) clamps to the `+0x18` deque count and reads through [UID:0001FC][0x0054c0c0-0x0054c110.DequeElementAddressHelper](by-memory/0x0054c0c0-0x0054c110.DequeElementAddressHelper.md).
- Destructor cleanup belongs to the embedded deque range, not the transient sieve field. [UID:0001FD][0x0054c160-0x0054c1f1.DequeClear](by-memory/0x0054c160-0x0054c1f1.DequeClear.md) is called by the constructor/destructor paths to clear deque storage.

## IDA Evidence

- 2026-06-14 live IDA MCP in session `a001_goal2_class_batch` reports the constructor-like body at `0x0054bcf0` as size `0x372`, the scalar deleting destructor at `0x0054c110` as size `0x4a`, and the deque clear helper at `0x0054c160` as size `0x91`.
- 2026-05-31 IDA MCP decompilation of `0x0054bcf0` writes `PrimeNumberGenerator::vftable` at `+0x00`, zeroes `+0x08/+0x0c/+0x10/+0x14/+0x18`, allocates an 8-byte object into `+0x08`, calls `Deque::Clear` with `this + 0x08`, and appends prime seeds through `Deque::PushBack` with `this + 0x08`.
- The same decompilation stores the temporary sieve pointer at `+0x04`, uses it for bit operations during construction, and frees it before returning.
- The raw indexed accessor at `0x0054bcc0` reads the `m_primes` count at `+0x18`, adds `0x08` to `this`, and calls [UID:0001FC][0x0054c0c0-0x0054c110.DequeElementAddressHelper](by-memory/0x0054c0c0-0x0054c110.DequeElementAddressHelper.md), confirming the embedded deque starts at `+0x08`.
- 2026-06-18 B005 raw route scan found zero inbound VA/RVA/rel32 routes to the raw accessor entry, but the positive-control rel32 call at `0x0054bce1` still targets [UID:0001FC][0x0054c0c0-0x0054c110.DequeElementAddressHelper](by-memory/0x0054c0c0-0x0054c110.DequeElementAddressHelper.md). That supports descriptive source naming for the accessor without changing the layout owner.
- 2026-06-14 live `xrefs_to 0x00622420` returns exactly three vtable references: constructor store `0x0054bd20`, raw mid-range store `0x0054c074`, and scalar deleting destructor store `0x0054c11a`.
- 2026-06-14 live decompilation of `0x0054c110` writes the same vtable, calls `sub_54C160(Block + 2)` twice, frees the deque storage at `Block[2]`, and conditionally deletes the object. This keeps cleanup attached to the embedded deque and does not make `+0x04` persistent state.
- 2026-06-14 live decompilation of `0x0054c160` walks `this[4]`, block map entries, and `this[1]/this[2]`, then clears `this[1]` and `this[2]`, matching [UID:0001U2][DequeLayout](by-type/by-struct/DequeLayout.md). Live `search_text` confirms `0x0054bcc0` is a raw prologue and not an IDA-modeled function, so the accessor remains range-backed by the by-memory child.
- 2026-07-04 B011 UID0001FB callback reconfirmed via accepted MCP session `nexustk_supervisor_20260704` that constructor decompilation uses `this+0x04` for the temporary sieve pointer and `this+0x08` for embedded deque/proxy state, while cleanup/deleting-destructor paths clear/free the embedded deque and do not make `+0x04` destructor-owned persistent state. `int_convert.py` verified the constructor clamp constants `0x64=100` and `0x989680=10000000`.

## Attachment And Reconstruction Notes

- `CANONICAL_OWNER:0000AT` remains correct because this is the class object layout rather than a file-level helper type.
- `RECONSTRUCTABLE:FALSE`, blank `EMITTER_UIDS`, and blank CPP/H positions are intentional. The layout is a documentation view of source already represented exactly by UID0000AT's formal H declaration; independent output would duplicate the class fields or fabricate layout assertions.
- Both formal blocks remain blank. UID0000AT owns declarations; UID0001FA and UID0001FB own method definitions; UID0002OK owns only the compiler-generated marker. This page owns evidence, not a separate source fragment.
- The old reconstructable/emitting classification is historicalized as a source-routing error: blank layout blocks produced an empty-emitter child even though the class header is the sole human-authored source cause.

## Score Rationale

- Completion is `91` because the exact `0x1c` layout, field lifetimes/users, constructor/accessor/destructor evidence, embedded STL boundary, owner, and explicit non-emitting source-cause disposition are complete.
- Confidence is `93` because all material layout/lifecycle claims agree across constructor/accessor/destructor, vtable, and Deque support evidence. Exact original private-member spelling and compiler-library revision remain unproven, so the page stays below `95`.

## Cross-References

- [UID:0000MQ][PrimeNumberGenerator](by-file/PrimeNumberGenerator.md)
- [UID:0000AT][PrimeNumberGenerator](by-class/PrimeNumberGenerator.md)
- [UID:0001FA][0x0054bcc0-0x0054bcec.PrimeNumberGeneratorGetPrimeAt](by-memory/0x0054bcc0-0x0054bcec.PrimeNumberGeneratorGetPrimeAt.md)
- [UID:0001FB][0x0054bcf0-0x0054c15a.PrimeNumberGenerator](by-memory/0x0054bcf0-0x0054c15a.PrimeNumberGenerator.md)
- [UID:0001FC][0x0054c0c0-0x0054c110.DequeElementAddressHelper](by-memory/0x0054c0c0-0x0054c110.DequeElementAddressHelper.md)
- [UID:0001FD][0x0054c160-0x0054c1f1.DequeClear](by-memory/0x0054c160-0x0054c1f1.DequeClear.md)
- [UID:0001YG][PrimeNumberGeneratorVtable](by-type/by-vtable/PrimeNumberGeneratorVtable.md)
- [UID:0001U2][DequeLayout](by-type/by-struct/DequeLayout.md)

## Changes

- 2026-08-13 B005 UID0000MQ whole-file implementation callback:
  - Before: score `85/89`, `RECONSTRUCTABLE:TRUE`, emitter UID0000AT, blank formal blocks, and stale text deferring the class declaration/constructor rewrite.
  - Changed to: score `91/93`, `RECONSTRUCTABLE:FALSE`, blank emitter/positions, explicit documentation-only source-cause rationale, current class/file scores, and completed CPP/H routing through UID0000AT/UID0001FA/UID0001FB/UID0002OK.
  - Preserved the exact `0x1c` layout, field lifetimes and offsets, native deque implementation evidence, inferred-name caveat, cross-references, and prior change history.

- 2026-07-12 B003 UID000149 Prime synchronization:
  - Preserved score/owner/emitter and blank layout C++.
  - Replaced custom Deque/API direction with native `std::deque<int> m_primes`, exact seed append expressions, later inline append evidence, and `size()`/`operator[]` accessor semantics.

- 2026-07-04 B011 UID0001FB implementation sync:
  - Recorded that the layout already supports the UID0001FB aggregate marker: `+0x04` is constructor scratch sieve storage and `+0x08..+0x18` is embedded `m_primes` deque storage.
  - Clarified that exact original member spelling remains a confidence cap for future class declaration/method-body C++ only, not a blocker for the accepted aggregate-marker parent.

- 2026-06-18 B005 [UID:0001FA][0x0054bcc0-0x0054bcec.PrimeNumberGeneratorGetPrimeAt](by-memory/0x0054bcc0-0x0054bcec.PrimeNumberGeneratorGetPrimeAt.md) accessor source-quality pass:
  - Changed to: explicit `m_primes` embedded deque wording, `GetPrimeAt(int index) const` accessor use, `+0x18` as `m_primes.GetCount()`, and support evidence for the raw accessor's zero inbound route plus positive-control helper call.
  - Summary/evidence: B005's raw byte/listing/export review reconfirmed the exact no-function accessor body and route evidence. The layout page still leaves C++ blank because the accessor now emits its target-local first draft, while this page requires broader class declaration/member spelling before emitting declarations.
- 2026-05-31 scoring, reconstructability, and embedded Deque terminology:
  - What existed before: completion/confidence metadata was unevaluated at `0/0`, `RECONSTRUCTABLE` was blank, size evidence referenced current metadata, and embedded Deque fields used older generic labels.
  - Changed to: `COMPLETION:72`, `CONFIDENCE:86`, `RECONSTRUCTABLE:TRUE`, IDA-based size evidence, and field labels aligned to the corrected [UID:0001U2][DequeLayout](by-type/by-struct/DequeLayout.md).
  - Summary/evidence: IDA MCP decompilation of `0x0054bcf0` directly proves the vtable, temporary sieve pointer, embedded deque start at `+0x08`, deque helper calls, and field writes through `+0x18`; the page remains below `95+` because exact original member names, full constructor source shape, and the unresolved Deque `+0x00` semantic name are not near-final.
- 2026-06-06 A004 layout-parent refresh:
  - What existed before: completion was `72`, `AUTOGEN_PARENT_UID` was blank, cleanup/lifetime users were implicit, and the page did not explain why the transient sieve pointer should not be modeled as persistent destructor-owned state.
  - Changed to: completion `82`, parent [UID:0000AT][PrimeNumberGenerator](by-class/PrimeNumberGenerator.md), explicit field lifetime/user notes, cleanup references to [UID:0001FD][0x0054c160-0x0054c1f1.DequeClear](by-memory/0x0054c160-0x0054c1f1.DequeClear.md), and a final-C++ gate note.
  - Summary/evidence: existing IDA-backed class/file/memory pages confirm the vtable, raw accessor, constructor/destructor ranges, Deque helper, and clear-helper calls. A live IDA retry timed out on 2026-06-06, so confidence remains `86`.
- 2026-06-14 A002 Goal2 score pass:
  - What existed before: `COMPLETION:82`, `CONFIDENCE:86`, with a stale 2026-06-06 live-IDA timeout caveat and legacy parent wording.
  - Changed to: `COMPLETION:85`, `CONFIDENCE:89`, current `CANONICAL_OWNER`/`EMITTER_UIDS` wording, current parent/file scores, and live IDA evidence for constructor/destructor/clear-helper sizes, vtable xrefs, and raw accessor status.
  - Summary/evidence: IDA MCP session `a001_goal2_class_batch` on 2026-06-14 confirmed `0x0054bcf0` size `0x372`, `0x0054c110` size `0x4a`, `0x0054c160` size `0x91`, three vtable xrefs to `0x00622420`, destructor cleanup through `Block + 2`, and `0x0054bcc0` as a raw prologue rather than an IDA-modeled function. Final C++ remains blank because names/declaration spelling are not source-quality.
