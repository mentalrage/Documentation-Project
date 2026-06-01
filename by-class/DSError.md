*** UID:000045 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:64 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:74 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# DSError

## Status

- Confidence: medium for constructor boundary, strong for formatter responsibility.
- Current Wave3 file: `class_DSError.cpp`
- Likely source module: [UID:0000J5][Error](by-file/Error.md)
- Current range: [UID:00013X][0x004a60d0-0x004a6a76.ErrorWrappers](by-memory/0x004a60d0-0x004a6a76.ErrorWrappers.md)
- Evidence basis: `simroot_v2`, Wave3 summary, and IDA MCP checks on 2026-05-23.

## Responsibility

`DSError` wraps DirectSound HRESULT-style failures and formats DirectSound-specific error text.

## Important Methods

| Address | Current name | Notes |
| --- | --- | --- |
| `0x004a6330` | `DSError` | Wave3 projected constructor start; IDA does not recognize a function here. |
| `0x004a6360` | `FormatErrorMessage` | IDA-confirmed function that formats DirectSound errors. |

## Ownership Notes

Use the formatter as the confirmed migration anchor. Do not move this class into `audio/SoundManager.cpp` solely because DirectSound callers use it.

2026-05-25 IDA recheck: `0x004a6330` still has no function record, direct callers, or data xrefs. Disassembly is constructor-shaped raw code: it calls base object setup, stores the HRESULT at offset `+4`, installs the `DSError` vtable, and returns. Treat it as raw constructor bytes until boundaries are reconciled.

## Cross-References

- [UID:0000J5][Error](by-file/Error.md)
- [UID:00013X][0x004a60d0-0x004a6a76.ErrorWrappers](by-memory/0x004a60d0-0x004a6a76.ErrorWrappers.md)
- [Wave3 data issues](../wave3_data_issues.md)

## Changes

- 2026-05-30:
  - Before: completion/confidence metadata was left at unevaluated `0/0`.
  - After: scored as `64/74`.
  - Summary/evidence: DirectSound formatter responsibility, shared error-module placement, confirmed formatter range, and raw constructor caveat are documented; confidence remains limited until the constructor boundary is reconciled.
