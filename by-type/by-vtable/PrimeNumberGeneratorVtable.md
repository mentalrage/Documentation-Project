*** UID:0001YG | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# PrimeNumberGenerator Vtable

## Status

- Entity kind: primary MSVC vtable.
- Vtable base: `0x00622420`.
- Complete-object-locator pointer: `0x0062241c -> 0x0064e318` (`??_R4PrimeNumberGenerator@@6B@`).
- Owner: [UID:0000MQ][PrimeNumberGenerator](by-file/PrimeNumberGenerator.md).
- Exact vtable-data range: [UID:0002OK][0x0062241c-0x00622424.PrimeNumberGeneratorVtableData](by-memory/0x0062241c-0x00622424.PrimeNumberGeneratorVtableData.md).
- Confidence: strong for table base and slot boundary.

## Slots

| Slot | Target | Notes |
| --- | --- | --- |
| `+0x00` | `0x0054c110` | `PrimeNumberGenerator::ScalarDeletingDestructor`. |

The next dword at `0x00622424` is `??_R4PursuitMessageDialogPane@@6B@`, so the `PrimeNumberGenerator` table has one slot.

## Evidence

- 2026-05-26 IDA `py_eval` read `0x0062241c` as the `PrimeNumberGenerator` RTTI pointer and `0x00622420` as `0x0054c110`.
- 2026-06-01 IDA MCP `py_eval` rechecked the exact data island: `0x00622418` is still a `PrettyButtonControlPane2` slot, `0x0062241c` is `PrimeNumberGenerator` RTTI, `0x00622420` points to the scalar deleting destructor, and `0x00622424` begins `PursuitMessageDialogPane` RTTI.
- `xrefs_to 0x0054c110` reports the vtable data reference from `0x00622420`.
- `xrefs_to 0x00622420` reports vtable stores from the constructor at `0x0054bd20` and deleting destructor at `0x0054c11a`, plus the raw constructor-neighborhood store at `0x0054c074`.
- Current `source-3/simroot_v2/class_PrimeNumberGenerator.meta_wave3` still reports `vtable_count: 0`, so this page is the IDA-backed vtable inventory anchor until generated metadata is repaired.

## Cross-References

- [UID:0002OK][0x0062241c-0x00622424.PrimeNumberGeneratorVtableData](by-memory/0x0062241c-0x00622424.PrimeNumberGeneratorVtableData.md)
- [UID:0000MQ][PrimeNumberGenerator](by-file/PrimeNumberGenerator.md)
- [UID:0000AT][PrimeNumberGenerator](by-class/PrimeNumberGenerator.md)
- [UID:0001VL][PrimeNumberGeneratorLayout](by-type/by-struct/PrimeNumberGeneratorLayout.md)
- [UID:0001FB][0x0054bcf0-0x0054c15a.PrimeNumberGenerator](by-memory/0x0054bcf0-0x0054c15a.PrimeNumberGenerator.md)
- [UID:0001FA][0x0054bcc0-0x0054bcec.PrimeNumberGeneratorGetPrimeAt](by-memory/0x0054bcc0-0x0054bcec.PrimeNumberGeneratorGetPrimeAt.md)

## Changes

- 2026-06-01:
  - What existed before: this vtable page had strong IDA evidence but the validator-tracked header remained `0/0`, and no exact `by-memory` page captured the `0x0062241c-0x00622424` RTTI/vtable-data island.
  - Changed to: scored the page as a strong but non-final vtable inventory, marked it reconstructable, and linked [UID:0002OK][0x0062241c-0x00622424.PrimeNumberGeneratorVtableData](by-memory/0x0062241c-0x00622424.PrimeNumberGeneratorVtableData.md) as the exact address-range evidence page.
  - Summary/evidence: IDA MCP `py_eval` on 2026-06-01 read the surrounding dwords, confirmed data xrefs to `0x00622420` from constructor/destructor code, and confirmed the neighboring boundaries before `PrettyButtonControlPane2` and `PursuitMessageDialogPane` data.
