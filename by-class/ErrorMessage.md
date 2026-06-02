*** UID:00004K | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:72 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:82 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000J5 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
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

The stronger current interpretation is that this is the inline-wide-message wrapper family member in [UID:0001UE][ErrorObjectLayouts](by-type/by-struct/ErrorObjectLayouts.md): vtable at `0x006193bc`, inline wide message storage at byte offset `+0x04`, copy slot [UID:00013Z][0x004a6410-0x004a6429.ErrorMessageCopyMessage](by-memory/0x004a6410-0x004a6429.ErrorMessageCopyMessage.md), scalar deleting destructor at `0x004a6920`, and shared name/descriptor slot `0x004a6a70`.

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

## Autogen Status

Attach this class to [UID:0000J5][Error](by-file/Error.md) as reconstructable hierarchy metadata, but leave C++ blank. The class belongs in `util/Error.cpp`, yet the constructor start is still raw/projected and the final class declaration/member spelling is not final-source quality.

## Score Rationale

| Score | Rationale |
| --- | --- |
| Completion `72` | The page records the class role, likely source owner, projected-constructor caveat, vtable slot map, inline-message layout, real copy/cleanup helpers, destructor/name helper, and no-code autogen handling. Completion remains capped because the constructor is not an IDA-modeled function and final declaration details are unresolved. |
| Confidence `82` | The ownership and behavior are strongly supported by the Error file page, ErrorWrappers aggregate, ErrorHierarchyVtables, ErrorObjectLayouts, and exact vtable-data page. Confidence is not higher because `0x004a63e0` remains a raw constructor-shaped start without an IDA function record or caller/xref proof. |

## Cross-References

- [UID:0000J5][Error](by-file/Error.md)
- [UID:00013X][0x004a60d0-0x004a6a76.ErrorWrappers](by-memory/0x004a60d0-0x004a6a76.ErrorWrappers.md)
- [UID:00013Y][0x004a6400-0x004a640b.ErrorBaseCleanupHelper](by-memory/0x004a6400-0x004a640b.ErrorBaseCleanupHelper.md)
- [UID:00013Z][0x004a6410-0x004a6429.ErrorMessageCopyMessage](by-memory/0x004a6410-0x004a6429.ErrorMessageCopyMessage.md)
- [UID:0001XI][ErrorHierarchyVtables](by-type/by-vtable/ErrorHierarchyVtables.md)
- [UID:0001UE][ErrorObjectLayouts](by-type/by-struct/ErrorObjectLayouts.md)
- [UID:0002ND][0x00619344-0x00619448.ErrorHierarchyVtableData](by-memory/0x00619344-0x00619448.ErrorHierarchyVtableData.md)
- [Wave3 data issues](../wave3_data_issues.md)

## Changes

- 2026-06-02:
  - Before: scored `64/70`, reconstructability and parent blank.
  - After: scored `72/82`, marked reconstructable, and attached to [UID:0000J5][Error](by-file/Error.md) with C++ blank.
  - Why: the shared Error file, vtable, layout, and exact vtable-data pages now provide strong evidence for `util/Error.cpp` ownership and inline-message behavior, while the constructor remains a raw projected start.
- 2026-05-30:
  - Before: completion/confidence metadata was left at unevaluated `0/0`.
  - After: scored as `64/70`.
  - Summary/evidence: display-message wrapper role, projected constructor caveat, cleanup/copy helpers, destructor/name helper, and omitted generated helper evidence are documented; confidence remains limited because the constructor is still not an IDA-modeled function.
