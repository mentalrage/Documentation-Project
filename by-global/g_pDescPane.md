*** UID:0000QR | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# g_pDescPane

## Status

- Confidence: strong.
- Address: `0x0069adf8`
- Memory doc: [UID:0001PB][0x0069adf8-0x0069adfc.g_pDescPane](by-memory/0x0069adf8-0x0069adfc.g_pDescPane.md)
- Current generated owner: `class_DescPane.cpp`
- Proposed owner file: [UID:0000IS][DescPane](by-file/DescPane.md)

## Symbol Role

`g_pDescPane` is the active description pane singleton. The `DescPane` constructor stores the live object pointer here, the non-deleting and scalar deleting destructors clear it, and a small getter returns the pointer.

## Evidence Notes

- Wave3 metadata identifies this global as `g_pDescPane`; a 2026-05-25 follow-up records it as resolved global-data at the reviewed four-byte storage range documented as `0x0069adf8-0x0069adfc`.
- IDA MCP `py_eval` reports the raw item as `dword_69ADF8`, size `4`, in `.data`.
- IDA xrefs to `0x0069adf8` include:
  - `0x0049d731` inside the raw `DescPane` constructor store;
  - `0x0049d75a` inside the non-deleting destructor clear;
  - `0x0049d770` inside the singleton getter read;
  - `0x0049d860` inside the scalar deleting destructor clear.
- No external caller/xref fanout was observed in the current IDA query, so source ownership stays with `DescPane.cpp`.
- 2026-05-26 recheck: IDA MCP `py_eval` still reports `0x0069adf8` as `dword_69ADF8`, size `4`, in `.data`; `xrefs_to 0x0069adf8` still lists only the four `DescPane` island refs above.

## Cross-References

- [UID:00003Q][DescPane](by-class/DescPane.md)
- [UID:0000IS][DescPane](by-file/DescPane.md)
- [UID:00012K][0x0049d6f0-0x0049d89f.DescPane](by-memory/0x0049d6f0-0x0049d89f.DescPane.md)
- [UID:0001PB][0x0069adf8-0x0069adfc.g_pDescPane](by-memory/0x0069adf8-0x0069adfc.g_pDescPane.md)
- [Wave3 data issues](../wave3_data_issues.md)

## Changes

- Completion/confidence scoring: existed before as ungraded `0/0`; changed to `88/86`. Summary/evidence: the page documents address, memory page, owner, constructor/destructor/getter xrefs, no external fanout, recheck notes, and class/file/memory refs.
