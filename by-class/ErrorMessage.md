*** UID:00004K | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:64 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:70 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# ErrorMessage

## Status

- Confidence: medium because the constructor start is projected.
- Current Wave3 file: `class_ErrorMessage.cpp`
- Likely source module: [UID:0000J5][Error](by-file/Error.md)
- Current range: [UID:00013X][0x004a60d0-0x004a6a76.ErrorWrappers](by-memory/0x004a60d0-0x004a6a76.ErrorWrappers.md)
- Evidence basis: `simroot_v2`, Wave3 summary, and IDA MCP checks on 2026-05-23.

## Responsibility

`ErrorMessage` appears to be a small display/name wrapper in the error hierarchy. It supplies an error-name virtual and a destructor path.

## Important Methods

| Address | Current name | Notes |
| --- | --- | --- |
| `0x004a63e0` | `ErrorMessage` | Wave3 projected constructor start; IDA does not recognize a function here. |
| [UID:00013Y][0x004a6400-0x004a640b.ErrorBaseCleanupHelper](by-memory/0x004a6400-0x004a640b.ErrorBaseCleanupHelper.md) | cleanup helper | IDA-confirmed helper that resets the base `Error` vtable and calls base cleanup; omitted from current generated output. |
| [UID:00013Z][0x004a6410-0x004a6429.ErrorMessageCopyMessage](by-memory/0x004a6410-0x004a6429.ErrorMessageCopyMessage.md) | copy helper | IDA-confirmed vtable slot helper that copies the stored wide message from `this + 4`; omitted from current generated output. |
| `0x004a6920` | `ScalarDeletingDestructor` | Resets to base error vtable and tears down `LObject`. |
| `0x004a6a70` | `GetErrorName` | Returns the base display name string. |

## Ownership Notes

Do not use the projected constructor as a rename anchor. The destructor/name helper still belongs in the shared error module.

2026-05-26 IDA recheck: `0x004a63e0` still has no function record, direct callers, or data xrefs, but disassembly shows a raw constructor-shaped body installing the `ErrorMessage` vtable. IDA confirms [UID:00013Y][0x004a6400-0x004a640b.ErrorBaseCleanupHelper](by-memory/0x004a6400-0x004a640b.ErrorBaseCleanupHelper.md) and [UID:00013Z][0x004a6410-0x004a6429.ErrorMessageCopyMessage](by-memory/0x004a6410-0x004a6429.ErrorMessageCopyMessage.md) as real adjacent helpers that current `simroot_v2` output does not emit. `0x004a6410` is referenced from the `ErrorMessage` vtable message slot at `0x006193c8`.

## Cross-References

- [UID:0000J5][Error](by-file/Error.md)
- [UID:00013X][0x004a60d0-0x004a6a76.ErrorWrappers](by-memory/0x004a60d0-0x004a6a76.ErrorWrappers.md)
- [UID:00013Y][0x004a6400-0x004a640b.ErrorBaseCleanupHelper](by-memory/0x004a6400-0x004a640b.ErrorBaseCleanupHelper.md)
- [UID:00013Z][0x004a6410-0x004a6429.ErrorMessageCopyMessage](by-memory/0x004a6410-0x004a6429.ErrorMessageCopyMessage.md)
- [Wave3 data issues](../wave3_data_issues.md)

## Changes

- 2026-05-30:
  - Before: completion/confidence metadata was left at unevaluated `0/0`.
  - After: scored as `64/70`.
  - Summary/evidence: display-message wrapper role, projected constructor caveat, cleanup/copy helpers, destructor/name helper, and omitted generated helper evidence are documented; confidence remains limited because the constructor is still not an IDA-modeled function.
