*** UID:0001YG | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:91 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000AT | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:FALSE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# PrimeNumberGenerator Vtable

## Status

- Entity kind: primary MSVC vtable.
- Vtable base: `0x00622420`.
- Complete-object-locator pointer: `0x0062241c -> 0x0064e318` (`??_R4PrimeNumberGenerator@@6B@`).
- Direct class owner: [UID:0000AT][PrimeNumberGenerator](by-class/PrimeNumberGenerator.md).
- Source route: [UID:0000MQ][PrimeNumberGenerator](by-file/PrimeNumberGenerator.md).
- Exact vtable-data range: [UID:0002OK][0x0062241c-0x00622424.PrimeNumberGeneratorVtableData](by-memory/0x0062241c-0x00622424.PrimeNumberGeneratorVtableData.md).
- Disposition: documentation-only compiler vtable/RTTI view. The virtual class declaration in UID0000AT is the complete hand-authored source cause; this page has no emitter and both formal blocks remain blank.
- Confidence: strong for table base, one-slot boundary, independently bounded RTTI graph, and non-emitting source disposition.

## Slots

| Slot | Target | Notes |
| --- | --- | --- |
| `+0x00` | `0x0054c110` | `PrimeNumberGenerator::ScalarDeletingDestructor`. |

The next dword at `0x00622424` is `??_R4PursuitMessageDialogPane@@6B@`, so the `PrimeNumberGenerator` table has one slot.

## Evidence

- 2026-05-26 IDA `py_eval` read `0x0062241c` as the `PrimeNumberGenerator` RTTI pointer and `0x00622420` as `0x0054c110`.
- 2026-06-01 IDA MCP `py_eval` rechecked the exact data island: `0x00622418` is still a `PrettyButtonControlPane2` slot, `0x0062241c` is `PrimeNumberGenerator` RTTI, `0x00622420` points to the scalar deleting destructor, and `0x00622424` begins `PursuitMessageDialogPane` RTTI.
- [UID:0002OK][0x0062241c-0x00622424.PrimeNumberGeneratorVtableData](by-memory/0x0062241c-0x00622424.PrimeNumberGeneratorVtableData.md) is the exact data child at `88/93`; it records the same RTTI/vtable dwords, constructor/destructor vptr writes, modeled destructor target, neighboring boundaries, and formal generated-binary marker.
- 2026-07-08 B006 UID0002OK callback: current MCP session `2cb2455b` confirmed `0x0062241c -> 0x0064e318`, `0x00622420 -> 0x0054c110`, `0x00622424 -> 0x0064e360`, local `??_7PrimeNumberGenerator@@6B@` at `0x00622420`, `sub_54C110` size `0x4a`, vtable-base stores at `0x0054bd20`, `0x0054c074`, and `0x0054c11a`, and unique signature `18 E3 64 00 10 C1 54 00`.
- 2026-06-08 A002 parent-gate follow-up improved [UID:0000AT][PrimeNumberGenerator](by-class/PrimeNumberGenerator.md) to `85/85`, so this source-level vtable type now has a direct class parent that clears the strict gate. [UID:0000MQ][PrimeNumberGenerator](by-file/PrimeNumberGenerator.md) remains the broader source module.
- `xrefs_to 0x0054c110` reports the vtable data reference from `0x00622420`.
- `xrefs_to 0x00622420` reports vtable stores from the constructor at `0x0054bd20` and deleting destructor at `0x0054c11a`, plus the raw constructor-neighborhood store at `0x0054c074`.
- Historical `source-3/simroot_v2/class_PrimeNumberGenerator.meta_wave3` reported `vtable_count: 0`. That absent/stale remnant remains lead history only; this page is the IDA-backed vtable/RTTI inventory anchor.

## RTTI Graph And Non-Emission

| Entity | Current physical form and exact bytes/hash | Exact xrefs | Interpretation |
| --- | --- | --- | --- |
| Vtable prefix `0x0062241c-0x00622420` | Four-byte unnamed/untyped data cell; `18 E3 64 00`; SHA256 `46301757AC96AC5EADAEC13111751F22587E4EBE48A0405EF9088E146E37216F` | Bounded zero inbound; outbound pointer to `0x0064e318` | Complete Object Locator pointer immediately before the table. |
| Vtable slot `0x00622420-0x00622424` | Decorated `??_7PrimeNumberGenerator@@6B@`; `10 C1 54 00`; SHA256 `80AABAD462EAF4C3FF3FBF46EEAB7E2410D4D71259A89F80F8435A6D22E92572` | Inbound stores/refs `0x0054bd20`, `0x0054c074`, `0x0054c11a`; outbound `0x0054c110` | Sole scalar deleting-destructor slot. |
| COL `0x0064e318-0x0064e32c` | `??_R4PrimeNumberGenerator@@6B@`; five physical dwords; `00 00 00 00 00 00 00 00 00 00 00 00 E8 88 67 00 2C E3 64 00`; SHA256 `4E82F79CFD48DA3883D8E9F46C05689756EF5DD3CAF346C6CAC97496830684D5` | Inbound `0x0062241c`; outbound fields `0x0064e324 -> 0x006788e8`, `0x0064e328 -> 0x0064e32c` | Exact Complete Object Locator. |
| CHD `0x0064e32c-0x0064e33c` | `??_R3PrimeNumberGenerator@@8`; four physical dwords; `00 00 00 00 00 00 00 00 01 00 00 00 3C E3 64 00`; SHA256 `74C098F11063BBFC7B0DE37E97290C7ABA86D1438E6A22B62D4A22EE3D7A02D4` | Inbound `0x0064e328`, `0x0064e35c`; outbound `0x0064e338 -> 0x0064e33c` | One-base Class Hierarchy Descriptor. |
| BCA `0x0064e33c-0x0064e344` | `??_R2PrimeNumberGenerator@@8` pointer dword plus protected undefined zero tail; `44 E3 64 00 00 00 00 00`; SHA256 `7A2965862ECED0E441090FD6EA2BE37ABA29F32AFA9F281844316AC8A76FFC46` | Inbound `0x0064e338`; outbound `0x0064e33c -> 0x0064e344`; zero bounded xrefs to tail `0x0064e340-0x0064e344` | One-entry Base Class Array plus padding; do not aggregate or type the zero tail. |
| BCD `0x0064e344-0x0064e360` | `??_R1A@?0A@EA@PrimeNumberGenerator@@8`; seven dwords; `E8 88 67 00 00 00 00 00 00 00 00 00 FF FF FF FF 00 00 00 00 40 00 00 00 2C E3 64 00`; SHA256 `45FF97B873DF29802C7519A8CDF0DD0C39E19FCFCE150DE93D5320F3B868E052` | Inbound `0x0064e33c`; outbound `0x0064e344 -> 0x006788e8`, `0x0064e35c -> 0x0064e32c` | Base Class Descriptor with PMD `{0,-1,0}` and attributes `0x40`. |
| TypeDescriptor `0x006788e8-0x0067890c` | `??_R0?AVPrimeNumberGenerator@@@8`; two dwords, 27-byte `.?AVPrimeNumberGenerator@@` string, one pad byte; `78 50 63 00 00 00 00 00 2E 3F 41 56 50 72 69 6D 65 4E 75 6D 62 65 72 47 65 6E 65 72 61 74 6F 72 40 40 00 00`; SHA256 `CC647DF2969BCFE1E9A86EA3268FBE2B46A7FD5BDBF1F3F8254230DD76B4485D` | Inbound `0x0064e324`, `0x0064e344`; outbound RTTI-vftable pointer `0x006788e8 -> 0x00635078`; class-name bytes have no independent xref | Exact compiler TypeDescriptor. |

`RECONSTRUCTABLE:FALSE` and blank emitter/positions prevent two invalid outcomes: an empty generated child and fabricated hand-written vtable/RTTI definitions. UID0000AT's virtual destructor declaration causes the compiler to generate this graph; UID0002OK separately retains its intentional comment-only generated-binary marker at CPP position `30`.

## Score Rationale

| Field | Value | Rationale |
| --- | ---: | --- |
| Completion | `91` | The page independently records the one-slot table, vtable prefix, COL, CHD, BCA/padding, BCD, TypeDescriptor, exact physical topology, bytes/hashes, xrefs, owner, and non-emitting source cause. |
| Confidence | `94` | Decorated names, exact data graph, constructor/destructor vptr stores, and scalar deleting-destructor target directly identify the class. Only exact compiler revision and active runtime use remain unproven. |

## Cross-References

- [UID:0002OK][0x0062241c-0x00622424.PrimeNumberGeneratorVtableData](by-memory/0x0062241c-0x00622424.PrimeNumberGeneratorVtableData.md)
- [UID:0000MQ][PrimeNumberGenerator](by-file/PrimeNumberGenerator.md)
- [UID:0000AT][PrimeNumberGenerator](by-class/PrimeNumberGenerator.md)
- [UID:0001VL][PrimeNumberGeneratorLayout](by-type/by-struct/PrimeNumberGeneratorLayout.md)
- [UID:0001FB][0x0054bcf0-0x0054c15a.PrimeNumberGenerator](by-memory/0x0054bcf0-0x0054c15a.PrimeNumberGenerator.md)
- [UID:0001FA][0x0054bcc0-0x0054bcec.PrimeNumberGeneratorGetPrimeAt](by-memory/0x0054bcc0-0x0054bcec.PrimeNumberGeneratorGetPrimeAt.md)

## Changes

- 2026-08-13 B005 UID0000MQ whole-file implementation callback:
  - Before: score `85/91`, `RECONSTRUCTABLE:TRUE`, emitter UID0000AT, blank formal blocks, aggregate RTTI description, and stale `simroot_v2` current-state wording.
  - Changed to: score `91/94`, `RECONSTRUCTABLE:FALSE`, blank emitter/positions, historicalized remnant text, exact independent COL/CHD/BCA/BCD/TypeDescriptor records with bytes/hashes/xrefs, and explicit class-header source-cause protection.
  - Preserved class ownership, one-slot identity, exact UID0002OK data child, all prior evidence/history, and blank CPP/H blocks.

- 2026-06-08 A002 Batch123:
  - Before: `COMPLETION:84`, `CONFIDENCE:90`, legacy parent field blank.
  - After: `COMPLETION:85`, `CONFIDENCE:91`, now represented as `CANONICAL_OWNER:0000AT` and `EMITTER_UIDS:0000AT`.
  - Evidence: reused the exact [UID:0002OK][0x0062241c-0x00622424.PrimeNumberGeneratorVtableData](by-memory/0x0062241c-0x00622424.PrimeNumberGeneratorVtableData.md) audit and improved [UID:0000AT][PrimeNumberGenerator](by-class/PrimeNumberGenerator.md) to `85/85`. The one-slot vtable type is generated from the class declaration, so the class is the actual direct parent; the file page remains source-module context.
- 2026-06-01:
  - What existed before: this vtable page had strong IDA evidence but the validator-tracked header remained `0/0`, and no exact `by-memory` page captured the `0x0062241c-0x00622424` RTTI/vtable-data island.
  - Changed to: scored the page as a strong but non-final vtable inventory, marked it reconstructable, and linked [UID:0002OK][0x0062241c-0x00622424.PrimeNumberGeneratorVtableData](by-memory/0x0062241c-0x00622424.PrimeNumberGeneratorVtableData.md) as the exact address-range evidence page.
  - Summary/evidence: IDA MCP `py_eval` on 2026-06-01 read the surrounding dwords, confirmed data xrefs to `0x00622420` from constructor/destructor code, and confirmed the neighboring boundaries before `PrettyButtonControlPane2` and `PursuitMessageDialogPane` data.
