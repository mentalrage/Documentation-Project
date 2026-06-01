*** UID:0000AT | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# PrimeNumberGenerator

## Status

- Confidence: strong for behavior, layout, vtable, and utility ownership; unresolved for active runtime use.
- Likely source file: [UID:0000MQ][PrimeNumberGenerator](by-file/PrimeNumberGenerator.md)
- Address ranges: [UID:0001FA][0x0054bcc0-0x0054bcec.PrimeNumberGeneratorGetPrimeAt](by-memory/0x0054bcc0-0x0054bcec.PrimeNumberGeneratorGetPrimeAt.md) and [UID:0001FB][0x0054bcf0-0x0054c15a.PrimeNumberGenerator](by-memory/0x0054bcf0-0x0054c15a.PrimeNumberGenerator.md)
- Current recovered file: `source-3/simroot_v2/class_PrimeNumberGenerator.cpp`
- Imported source file: `PrimeNumberGenerator.cpp`
- Vtable: [UID:0001YG][PrimeNumberGeneratorVtable](by-type/by-vtable/PrimeNumberGeneratorVtable.md)

## Class Purpose

`PrimeNumberGenerator` precomputes prime numbers using a wheel-factored sieve over candidates of the form `6k - 1` and `6k + 1`. It clamps the requested maximum to `100..10000000`, seeds primes `2` and `3`, appends discovered primes to an embedded deque, and frees the temporary sieve bitfield after construction.

The class has a vtable and scalar deleting destructor, but current IDA caller checks do not show direct runtime construction. Treat it as a utility/legacy class until a concrete construction site is found.

## Method Notes

| Method or helper | Address | Role |
| --- | --- | --- |
| raw indexed accessor | `0x0054bcc0-0x0054bcec` | Returns `2` for negative indexes; otherwise clamps the requested index to the last generated prime and reads the value through the embedded deque. |
| constructor | `0x0054bcf0-0x0054c062` | Initializes the vtable and embedded deque, clamps the limit, builds the sieve bitfield, appends discovered primes, and frees the temporary sieve storage. |
| scalar deleting destructor | `0x0054c110-0x0054c15a` | Restores the vtable, clears the embedded deque twice, frees deque backing storage, and conditionally deletes `this`. |
| Deque element-address helper | `0x0054c0c0-0x0054c110` | Generic [UID:0000IR][Deque](by-file/Deque.md) helper used by the raw accessor; not prime-specific class logic. |

## Layout Notes

See [UID:0001VL][PrimeNumberGeneratorLayout](by-type/by-struct/PrimeNumberGeneratorLayout.md). The confirmed local layout is a 28-byte object:

- `+0x00`: `PrimeNumberGenerator` vtable pointer (`0x00622420`).
- `+0x04`: temporary sieve bitfield pointer, allocated during construction and freed before returning.
- `+0x08..+0x18`: embedded 4-byte-entry deque state used to store generated primes.

## Evidence Notes

- IDA MCP `lookup_funcs` confirms `0x0054bcf0` size `0x372`, `0x0054c110` size `0x4a`, and Deque helper `0x0054c0c0` size `0x50`.
- IDA MCP disassembly confirms raw function-shaped accessor code at `0x0054bcc0-0x0054bcec`, though `lookup_funcs` does not model it as a function.
- IDA MCP decompilation of `0x0054c0c0` shows `frontIndex + index` block-map addressing over 4-byte entries, matching [UID:0001U2][DequeLayout](by-type/by-struct/DequeLayout.md).
- IDA MCP `callers` shows [UID:0001FD][0x0054c160-0x0054c1f1.DequeClear](by-memory/0x0054c160-0x0054c1f1.DequeClear.md) is called from the constructor and destructor, while the `PrimeNumberGenerator` constructor/destructor themselves have no direct callers in the current IDB.
- IDA MCP `xrefs_to 0x00622420` shows vtable writes from the constructor/destructor and the vtable entry pointing at the deleting destructor.
- 2026-05-26 recheck: active generated output still omits the raw accessor and the Deque element-address helper; `class_PrimeNumberGenerator.meta_wave3` still carries carriage-return-suffixed method names in history/current-name data.
- 2026-05-26 IDA `py_eval` recheck confirms the one-slot vtable at `0x00622420`: RTTI pointer at `0x0062241c`, deleting destructor slot `0x0054c110`, and next class RTTI pointer at `0x00622424`.
- Current `source-3/simroot_v2/class_PrimeNumberGenerator.meta_wave3` still reports `vtable_count: 0`, so [UID:0001YG][PrimeNumberGeneratorVtable](by-type/by-vtable/PrimeNumberGeneratorVtable.md) is the current table inventory anchor.
- Generated metadata describes the embedded container at `+0x08` as a deque-like container with node/map/capacity/head/count fields.

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

- 2026-05-30: Changed completion/confidence from `0/0` to `84/84`.
  - Before: The page was unevaluated even though it contained method ownership, layout, vtable, and IDA evidence.
  - After: Scored as high-completion class documentation with remaining uncertainty around active runtime use and generated-output omissions.
  - Evidence: Existing status, method notes, layout notes, vtable notes, IDA MCP evidence notes, and cross-references document the class at class/file/memory/type levels.
