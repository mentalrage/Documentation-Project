*** UID:0001YY | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# TextFilter Vtable

## Status

- Entity kind: vtable inventory.
- Address: `0x0062e184-0x0062e18c`, with the primary vtable base at `0x0062e188`.
- Owner class: [UID:0000EQ][TextFilter](by-class/TextFilter.md).
- Owner file hypothesis: [UID:0000OO][TextFilter](by-file/TextFilter.md).
- Confidence: strong for address and one-slot extent; current generated metadata is incomplete.
- Exact vtable-data child: [UID:0002OZ][0x0062e184-0x0062e18c.TextFilterVtableData](by-memory/0x0062e184-0x0062e18c.TextFilterVtableData.md)

## Layout

| Slot | Target | Meaning |
| --- | --- | --- |
| `+0x00` | `0x005958d0` | `TextFilter` scalar deleting destructor. |

This vtable has only one confirmed slot. IDA disassembly after `0x0062e18c` enters adjacent `TextPad` RTTI/vtable data, so do not treat the following `0x0062e18c+` words as `TextFilter` virtual methods.

## Evidence

- IDA MCP `list_globals ??_7TextFilter*` on 2026-05-26 returns `??_7TextFilter@@6B@` at `0x0062e188`.
- IDA MCP `xrefs_to 0x0062e188` reports stores from `TextFilter::TextFilter` at `0x00595778` and `0x0059578b`, the non-deleting destructor-like body at `0x005957a0`, and the scalar deleting destructor at `0x005958da`.
- IDA MCP `xrefs_to 0x005958d0` reports the vtable slot at `0x0062e188`.
- 2026-06-01 IDA MCP `py_eval` confirms `0x0062e184` as `??_R4TextFilter@@6B@`, `0x0062e188` as `??_7TextFilter@@6B@`, and `0x0062e18c` as the following `TextPad` RTTI-adjacent word.

## Cross-References

- [UID:0000OO][TextFilter](by-file/TextFilter.md)
- [UID:0000EQ][TextFilter](by-class/TextFilter.md)
- [UID:0001JU][0x00595760-0x005958fe.TextFilterAndSanitizer](by-memory/0x00595760-0x005958fe.TextFilterAndSanitizer.md)
- [UID:0002OZ][0x0062e184-0x0062e18c.TextFilterVtableData](by-memory/0x0062e184-0x0062e18c.TextFilterVtableData.md)
- [UID:0000SG][g_pTextFilter](by-global/g_pTextFilter.md)
- [Wave3 data issues](../../wave3_data_issues.md)

## Changes

- What existed before: this page described the one-slot vtable but remained scored `0/0`, used `0x0062e188-0x0062e18c` as the address span, did not link an exact by-memory child range, and cited generated metadata incompleteness as evidence.
- What it was changed to: the page now uses the exact IDA-confirmed `0x0062e184-0x0062e18c` vtable-data span, marks the item reconstructable, links the exact child page, and keeps the generated metadata issue only as a caveat.
- Summary and evidence: 2026-06-01 IDA MCP `py_eval` verified the `TextFilter` RTTI-adjacent word, the one-slot vtable, constructor/destructor xrefs, preceding `MBOLS.EPD` string data, and the `TextPad` boundary at `0x0062e18c`.
