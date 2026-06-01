*** UID:0001VL | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:72 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
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

## IDA Evidence

- `lookup_funcs` reports the constructor-like body at `0x0054bcf0` as size `0x372`.
- 2026-05-31 IDA MCP decompilation of `0x0054bcf0` writes `PrimeNumberGenerator::vftable` at `+0x00`, zeroes `+0x08/+0x0c/+0x10/+0x14/+0x18`, allocates an 8-byte object into `+0x08`, calls `Deque::Clear` with `this + 0x08`, and appends prime seeds through `Deque::PushBack` with `this + 0x08`.
- The same decompilation stores the temporary sieve pointer at `+0x04`, uses it for bit operations during construction, and frees it before returning.
- The raw indexed accessor at `0x0054bcc0` reads count at `+0x18`, adds `0x08` to `this`, and calls [UID:0001FC][0x0054c0c0-0x0054c110.DequeElementAddressHelper](by-memory/0x0054c0c0-0x0054c110.DequeElementAddressHelper.md), confirming the embedded deque starts at `+0x08`.

## Cross-References

- [UID:0000MQ][PrimeNumberGenerator](by-file/PrimeNumberGenerator.md)
- [UID:0000AT][PrimeNumberGenerator](by-class/PrimeNumberGenerator.md)
- [UID:0001FA][0x0054bcc0-0x0054bcec.PrimeNumberGeneratorGetPrimeAt](by-memory/0x0054bcc0-0x0054bcec.PrimeNumberGeneratorGetPrimeAt.md)
- [UID:0001FB][0x0054bcf0-0x0054c15a.PrimeNumberGenerator](by-memory/0x0054bcf0-0x0054c15a.PrimeNumberGenerator.md)
- [UID:0001YG][PrimeNumberGeneratorVtable](by-type/by-vtable/PrimeNumberGeneratorVtable.md)
- [UID:0001U2][DequeLayout](by-type/by-struct/DequeLayout.md)

## Changes

- 2026-05-31 scoring, reconstructability, and embedded Deque terminology:
  - What existed before: completion/confidence metadata was unevaluated at `0/0`, `RECONSTRUCTABLE` was blank, size evidence referenced current metadata, and embedded Deque fields used older generic labels.
  - Changed to: `COMPLETION:72`, `CONFIDENCE:86`, `RECONSTRUCTABLE:TRUE`, IDA-based size evidence, and field labels aligned to the corrected [UID:0001U2][DequeLayout](by-type/by-struct/DequeLayout.md).
  - Summary/evidence: IDA MCP decompilation of `0x0054bcf0` directly proves the vtable, temporary sieve pointer, embedded deque start at `+0x08`, deque helper calls, and field writes through `+0x18`; the page remains below `95+` because exact original member names, full constructor source shape, and the unresolved Deque `+0x00` semantic name are not near-final.
