*** UID:0001VL | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:82 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000AT | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# PrimeNumberGeneratorLayout

## Status

- Confidence: strong for object size, vtable pointer, temporary sieve field, and embedded deque field offsets; medium for final source-level member names.
- Likely owner: [UID:0000MQ][PrimeNumberGenerator](by-file/PrimeNumberGenerator.md)
- Primary memory evidence: [UID:0001FB][0x0054bcf0-0x0054c15a.PrimeNumberGenerator](by-memory/0x0054bcf0-0x0054c15a.PrimeNumberGenerator.md)
- Size evidence: constructor field writes through `+0x18` and the embedded [UID:0001U2][DequeLayout](by-type/by-struct/DequeLayout.md) beginning at `+0x08` establish at least `0x1c` bytes.
- Parent attachment: attached to [UID:0000AT][PrimeNumberGenerator](by-class/PrimeNumberGenerator.md), which is scored `84/84` and is the narrow class owner for this layout.

## Layout Hypothesis

`PrimeNumberGenerator` is a small vtable-bearing object with a temporary sieve pointer and an embedded 4-byte-entry deque:

| Offset | Size | Observed field | Evidence |
| --- | --- | --- | --- |
| `+0x00` | 4 | vtable pointer | Constructor/destructor write `PrimeNumberGenerator::vftable_622420`. |
| `+0x04` | 4 | temporary sieve bitfield pointer | Constructor stores the allocated sieve buffer here and frees it before returning. |
| `+0x08` | 4 | embedded deque `+0x00` auxiliary storage slot | Constructor zeroes this field, allocates an 8-byte sentinel-like allocation, stores it here, and passes `this + 8` to deque helpers. Exact source-level meaning follows the unresolved `+0x00` field in [UID:0001U2][DequeLayout](by-type/by-struct/DequeLayout.md). |
| `+0x0c` | 4 | embedded deque `+0x04` block map | Used by deque growth/access logic. |
| `+0x10` | 4 | embedded deque `+0x08` block count | Used with power-of-two mask calculations. |
| `+0x14` | 4 | embedded deque `+0x0c` front index | Used when appending and indexing 4-byte entries. |
| `+0x18` | 4 | embedded deque `+0x10` count | Incremented as primes are appended. |

## Behavior Notes

- The constructor clamps `maxValue` to `100..10000000`.
- The sieve bitfield tracks only wheel candidates related to values of form `6k - 1` and `6k + 1`.
- The embedded deque stores integer prime values; `2` and `3` are seeded before the main sieve loop.
- The raw indexed accessor at `0x0054bcc0` reads count at `+0x18`, clamps high indexes to `count - 1`, then passes the embedded deque at `this + 0x08` to the generic Deque element-address helper.
- The temporary sieve buffer is not persistent object state after construction returns, despite occupying the `+0x04` field during the constructor.
- 2026-05-26 IDA `py_eval` confirms the [UID:0001YG][PrimeNumberGeneratorVtable](by-type/by-vtable/PrimeNumberGeneratorVtable.md) at `0x00622420`, with the RTTI pointer immediately before it at `0x0062241c`.

## Field Lifetime And Users

- `+0x00` is persistent class identity: the constructor and scalar deleting destructor restore/write the one-slot vtable anchored by [UID:0001YG][PrimeNumberGeneratorVtable](by-type/by-vtable/PrimeNumberGeneratorVtable.md).
- `+0x04` is constructor-scope scratch storage, not a durable public member. The constructor stores the sieve bitfield pointer here while marking candidates and frees the buffer before returning; the destructor does not own this field as long-lived state.
- `+0x08..+0x18` is the persistent embedded deque used after construction. The constructor seeds `2` and `3` and pushes discovered primes; the raw accessor [UID:0001FA][0x0054bcc0-0x0054bcec.PrimeNumberGeneratorGetPrimeAt](by-memory/0x0054bcc0-0x0054bcec.PrimeNumberGeneratorGetPrimeAt.md) clamps to `+0x18` count and reads through [UID:0001FC][0x0054c0c0-0x0054c110.DequeElementAddressHelper](by-memory/0x0054c0c0-0x0054c110.DequeElementAddressHelper.md).
- Destructor cleanup belongs to the embedded deque range, not the transient sieve field. [UID:0001FD][0x0054c160-0x0054c1f1.DequeClear](by-memory/0x0054c160-0x0054c1f1.DequeClear.md) is called by the constructor/destructor paths to clear deque storage.

## IDA Evidence

- `lookup_funcs` reports the constructor-like body at `0x0054bcf0` as size `0x372`.
- 2026-05-31 IDA MCP decompilation of `0x0054bcf0` writes `PrimeNumberGenerator::vftable` at `+0x00`, zeroes `+0x08/+0x0c/+0x10/+0x14/+0x18`, allocates an 8-byte object into `+0x08`, calls `Deque::Clear` with `this + 0x08`, and appends prime seeds through `Deque::PushBack` with `this + 0x08`.
- The same decompilation stores the temporary sieve pointer at `+0x04`, uses it for bit operations during construction, and frees it before returning.
- The raw indexed accessor at `0x0054bcc0` reads count at `+0x18`, adds `0x08` to `this`, and calls [UID:0001FC][0x0054c0c0-0x0054c110.DequeElementAddressHelper](by-memory/0x0054c0c0-0x0054c110.DequeElementAddressHelper.md), confirming the embedded deque starts at `+0x08`.
- Existing class/file evidence records `0x0054c110-0x0054c15a` as the scalar deleting destructor and `0x0054c160-0x0054c1f1` as the shared deque clear helper used by constructor/destructor cleanup.
- 2026-06-06 live IDA retry note: `lookup_funcs`/`xrefs_to` and a later minimal `idb_meta` call timed out under load. This update uses only the already-written 2026-05-26 through 2026-06-01 IDA-backed evidence linked from this page and does not add new binary-only facts.

## Attachment And Reconstruction Notes

- `AUTOGEN_PARENT_UID` is [UID:0000AT][PrimeNumberGenerator](by-class/PrimeNumberGenerator.md), not the broader file page, because this is the class object layout rather than a file-level helper type.
- [UID:0000MQ][PrimeNumberGenerator](by-file/PrimeNumberGenerator.md) is also above the `80/80` gate at `84/82`, but the class page is the more precise owner.
- `RECONSTRUCTION_CPP CODE` remains blank. The page documents layout facts needed by final source, but final C++ still needs the original member names, deque declaration spelling, and constructor/destructor rewrite shape to reach the `95/95` gate.

## Score Rationale

- Completion raised from `72` to `82` because the page now separates transient scratch storage from persistent fields, records field users, establishes parent attachment, links the destructor/Deque clear cleanup path, and documents why final C++ remains blank.
- Confidence stays `86` because the core field offsets and class ownership are backed by written IDA evidence, but the 2026-06-06 live recheck timed out and final source member names remain provisional.

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

- 2026-05-31 scoring, reconstructability, and embedded Deque terminology:
  - What existed before: completion/confidence metadata was unevaluated at `0/0`, `RECONSTRUCTABLE` was blank, size evidence referenced current metadata, and embedded Deque fields used older generic labels.
  - Changed to: `COMPLETION:72`, `CONFIDENCE:86`, `RECONSTRUCTABLE:TRUE`, IDA-based size evidence, and field labels aligned to the corrected [UID:0001U2][DequeLayout](by-type/by-struct/DequeLayout.md).
  - Summary/evidence: IDA MCP decompilation of `0x0054bcf0` directly proves the vtable, temporary sieve pointer, embedded deque start at `+0x08`, deque helper calls, and field writes through `+0x18`; the page remains below `95+` because exact original member names, full constructor source shape, and the unresolved Deque `+0x00` semantic name are not near-final.
- 2026-06-06 A004 layout-parent refresh:
  - What existed before: completion was `72`, `AUTOGEN_PARENT_UID` was blank, cleanup/lifetime users were implicit, and the page did not explain why the transient sieve pointer should not be modeled as persistent destructor-owned state.
  - Changed to: completion `82`, parent [UID:0000AT][PrimeNumberGenerator](by-class/PrimeNumberGenerator.md), explicit field lifetime/user notes, cleanup references to [UID:0001FD][0x0054c160-0x0054c1f1.DequeClear](by-memory/0x0054c160-0x0054c1f1.DequeClear.md), and a final-C++ gate note.
  - Summary/evidence: existing IDA-backed class/file/memory pages confirm the vtable, raw accessor, constructor/destructor ranges, Deque helper, and clear-helper calls. A live IDA retry timed out on 2026-06-06, so confidence remains `86`.
