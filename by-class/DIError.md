*** UID:00003W | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:72 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:82 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000J5 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# DIError

## Status

- Confidence: medium for constructor boundary, strong for formatter responsibility.
- Current Wave3 file: `class_DIError.cpp`
- Likely source module: [UID:0000J5][Error](by-file/Error.md)
- Current range: [UID:00013X][0x004a60d0-0x004a6a76.ErrorWrappers](by-memory/0x004a60d0-0x004a6a76.ErrorWrappers.md)
- Evidence basis: `simroot_v2`, Wave3 summary, and IDA MCP checks on 2026-05-23.

## Responsibility

`DIError` wraps DirectInput HRESULT-style failures and formats them into readable DirectInput error messages.

In the shared error layout, `DIError` belongs to the stored-status-code family: vtable at `0x00619374`, caller HRESULT stored at byte offset `+0x04`, message/format slot `0x004a61e0`, shared scalar deleting destructor `0x004a68a0`, and shared name/descriptor slot `0x004a6a70`.

## Important Methods

| Address | Current name | Notes |
| --- | --- | --- |
| `0x004a61b0` | `DIError` | Wave3 projected constructor start; IDA does not recognize a function here. |
| `0x004a61e0` | `FormatErrorMessage` | IDA-confirmed function that formats DirectInput errors. |

## Ownership Notes

Use only the confirmed formatter range for source migration until the constructor projection is resolved. The implementation still belongs with shared errors, not `input/InputMan.cpp`.

2026-05-25 IDA recheck: `0x004a61b0` still has no function record, direct callers, or data xrefs. Disassembly is constructor-shaped raw code: it calls base object setup, stores the HRESULT at offset `+4`, installs the `DIError` vtable, and returns. Treat it as raw constructor bytes until Wave3/IDA boundaries are reconciled.

## Autogen Status

Attach this class to [UID:0000J5][Error](by-file/Error.md) as reconstructable hierarchy metadata, but leave C++ blank. The formatter and vtable/layout evidence are strong; the constructor start and final declaration spelling are not ready for emitted source.

## Score Rationale

| Score | Rationale |
| --- | --- |
| Completion `72` | The page records DirectInput responsibility, shared error-module ownership, stored-code layout, vtable slot evidence, confirmed formatter, raw constructor caveat, and no-code autogen handling. Completion remains capped because the constructor is not split as an IDA-modeled function page and final field/member names are unresolved. |
| Confidence `82` | The formatter, vtable, layout family, and source owner are strongly supported by existing error hierarchy docs. Confidence is not higher because `0x004a61b0` remains constructor-shaped raw code without IDA function/caller/xref confirmation. |

## Cross-References

- [UID:0000J5][Error](by-file/Error.md)
- [UID:00013X][0x004a60d0-0x004a6a76.ErrorWrappers](by-memory/0x004a60d0-0x004a6a76.ErrorWrappers.md)
- [UID:0001XI][ErrorHierarchyVtables](by-type/by-vtable/ErrorHierarchyVtables.md)
- [UID:0001UE][ErrorObjectLayouts](by-type/by-struct/ErrorObjectLayouts.md)
- [UID:0002ND][0x00619344-0x00619448.ErrorHierarchyVtableData](by-memory/0x00619344-0x00619448.ErrorHierarchyVtableData.md)
- [Wave3 data issues](../wave3_data_issues.md)

## Changes

- 2026-06-02:
  - Before: scored `64/74`, reconstructability and parent blank.
  - After: scored `72/82`, marked reconstructable, and attached to [UID:0000J5][Error](by-file/Error.md) with C++ blank.
  - Why: existing vtable/layout/error-wrapper evidence strongly supports shared `util/Error.cpp` ownership and DirectInput formatter behavior, while the constructor start remains a raw projected boundary.
- 2026-05-30:
  - Before: completion/confidence metadata was left at unevaluated `0/0`.
  - After: scored as `64/74`.
  - Summary/evidence: DirectInput formatter responsibility, shared error-module placement, confirmed formatter range, and raw constructor caveat are documented; confidence remains limited until the constructor boundary is reconciled.
