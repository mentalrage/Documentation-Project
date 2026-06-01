*** UID:0001X7 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:91 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# ChangeMan Vtable

## Status

- Entity kind: primary `ChangeMan` vtable.
- Vtable base: `0x00614cd0`.
- RTTI pointer: `0x00614ccc -> 0x00644090` (`??_R4ChangeMan@@6B@`).
- Exact data page: [UID:0002M8][0x00614cd0-0x00614cdc.ChangeManVtableData](by-memory/0x00614cd0-0x00614cdc.ChangeManVtableData.md).
- Confidence: strong for table base, slot boundary, and inherited `LObject` slot meanings.
- Owner: [UID:0000I2][ChangeMan](by-file/ChangeMan.md).

## Slots

| Slot | Address | Current interpretation | Notes |
| --- | --- | --- | --- |
| `+0x00` | `0x0047ef50` | `ChangeMan::ScalarDeletingDestructor` | Releases the sorted registration list, clears [UID:0000QI][g_pChangeMan](by-global/g_pChangeMan.md), destroys `LObject`, and optionally frees storage. |
| `+0x04` | `0x004f4b10` | inherited `LObject` runtime/type helper | IDA decompilation returns `&off_61CF44`; this slot matches the base helper shared by other `LObject`-derived classes. |
| `+0x08` | `0x0041b6c0` | inherited/default no-op virtual | Shared two-argument no-op body, currently `nullsub_18`. |

The table stops after `+0x08`. The next dword at `0x00614cdc` is RTTI data for `ChattingPane` (`??_R4ChattingPane@@6B@`), and the next vtable begins at `0x00614ce0`.

## Evidence

- IDA MCP `.rdata` inspection on 2026-05-26 and 2026-05-31 reads the three function-pointer slots at `0x00614cd0`, `0x00614cd4`, and `0x00614cd8`, followed immediately by `ChattingPane` RTTI at `0x00614cdc`.
- IDA MCP `py_eval` on 2026-05-31 reads `0x00614ccc -> 0x00644090` (`??_R4ChangeMan@@6B@`) and `0x00614cdc -> 0x00644168` (`??_R4ChattingPane@@6B@`), proving the exclusive vtable-data boundary captured by [UID:0002M8][0x00614cd0-0x00614cdc.ChangeManVtableData](by-memory/0x00614cd0-0x00614cdc.ChangeManVtableData.md).
- IDA MCP `xrefs_to 0x00614cd0` reports vptr stores from `ChangeMan::ChangeMan` at `0x0047ecc9`, from the compiler-generated constructor cleanup fragment at `0x0047ed26`, and from `ChangeMan::ScalarDeletingDestructor` at `0x0047ef59`.
- IDA MCP `xrefs_to 0x0047ef50` reports the vtable slot data reference at `0x00614cd0`.
- IDA MCP decompilation of the constructor and scalar deleting destructor both names `ChangeMan::\`vftable'` at this address.
- Current `source-3/simroot_v2/class_ChangeMan.meta_wave3` still reports `vtable_count: 0`, so this page is the reconstruction anchor until generated vtable inventory is fixed.

## Cross-References

- [UID:00001K][ChangeMan](by-class/ChangeMan.md)
- [UID:0000I2][ChangeMan](by-file/ChangeMan.md)
- [UID:0002M8][0x00614cd0-0x00614cdc.ChangeManVtableData](by-memory/0x00614cd0-0x00614cdc.ChangeManVtableData.md)
- [UID:0000ZU][0x0047ec70-0x0047efae.ChangeMan](by-memory/0x0047ec70-0x0047efae.ChangeMan.md)
- [UID:0000ZV][0x0047ed20-0x0047ed50.ChangeManConstructorCleanup](by-memory/0x0047ed20-0x0047ed50.ChangeManConstructorCleanup.md)
- [UID:000103][0x0047ef50-0x0047efae.ChangeManScalarDeletingDestructor](by-memory/0x0047ef50-0x0047efae.ChangeManScalarDeletingDestructor.md)
- [UID:0000QI][g_pChangeMan](by-global/g_pChangeMan.md)
- [Wave3 data issues](../../wave3_data_issues.md)

## Changes

- 2026-05-31: Grading changed from `0/0` to `84/91`, and `RECONSTRUCTABLE` was set to `TRUE`.
  - Before: the vtable page had strong slot notes but remained unevaluated and did not point to an exact by-memory data slice.
  - After: the page points to [UID:0002M8][0x00614cd0-0x00614cdc.ChangeManVtableData](by-memory/0x00614cd0-0x00614cdc.ChangeManVtableData.md) as the exact 12-byte vtable data range.
  - Evidence: IDA MCP `lookup_funcs`, `py_eval`, and `xrefs_to` on 2026-05-31 reconfirmed the three slot values, RTTI boundary before/after the table, constructor/destructor vptr-store xrefs, and destructor slot data xref.
