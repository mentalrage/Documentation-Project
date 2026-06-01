*** UID:0000SP | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:76 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000P6 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# g_pVoteMenuPane

## Status

- Confidence: strong.
- Address: `0x0069ba38`
- Memory doc: [UID:0001Q0][0x0069ba38-0x0069ba3c.g_pVoteMenuPane](by-memory/0x0069ba38-0x0069ba3c.g_pVoteMenuPane.md)
- Current generated owner: `class_VoteMenuPane.cpp`
- Proposed owner file: [UID:0000P6][VoteMenuPane](by-file/VoteMenuPane.md)

## Symbol Role

`g_pVoteMenuPane` is the active vote popup singleton. `VoteMenuPane` constructor stores the newly created pane here, and both ordinary and deleting destructors clear it.

The neighboring [UID:0000N7][RightButtonMenuPane](by-file/RightButtonMenuPane.md) event/cancel code checks this pointer to dismiss an active vote popup while right-click menu interaction changes.

## Evidence Notes

- Wave3 metadata identifies this global as `DAT_0069ba38`.
- IDA MCP `py_eval` reports the raw item as `dword_69BA38`, size `4`, in `.data`.
- IDA xrefs to `0x0069ba38` include:
  - `0x005558f8` inside the raw `VoteMenuPane` constructor;
  - `0x0055599d` inside `VoteMenuPane::~VoteMenuPane`;
  - `0x00556374` inside `VoteMenuPane::ScalarDeletingDestructor`;
  - `RightButtonMenuPane` event/cancel references at `0x00554ca5`, `0x00554ee8`, `0x00554f1a`, `0x00554f93`, and `0x005552a3`.
- 2026-05-26 recheck: IDA MCP still reports `0x0069ba38` as raw `dword_69BA38`, size `4`, in `.data`, with the same vote-popup lifecycle writes and right-click dismissal reads.
- IDA MCP `py_eval` rechecked `0x0069ba38` on 2026-05-31 and confirmed IDA name `dword_69BA38`, initial dword `0xffffffff`, and 8 data xrefs: five RightButtonMenuPane dismissal/event reads, one raw constructor write at `0x005558f8`, destructor clear at `0x0055599d`, and scalar deleting destructor clear at `0x00556374`.

## Data Caveat

Current active `class_RightButtonMenuPane.cpp` renders several `0x0069ba38` uses as `g_pBulletinSession`. Treat those names as generated global-owner pollution. `g_pBulletinSession` is a separate bulletin/mail dialog singleton, while `0x0069ba38` is the vote popup singleton.

## Cross-References

- [UID:0000FX][VoteMenuPane](by-class/VoteMenuPane.md)
- [UID:0000P6][VoteMenuPane](by-file/VoteMenuPane.md)
- [UID:0001Q0][0x0069ba38-0x0069ba3c.g_pVoteMenuPane](by-memory/0x0069ba38-0x0069ba3c.g_pVoteMenuPane.md)
- [UID:0000N7][RightButtonMenuPane](by-file/RightButtonMenuPane.md)
- [Wave3 data issues](../wave3_data_issues.md)

## Changes

- 2026-05-31: Updated reconstruction metadata and scores from live IDA evidence.
  - Before: completion/confidence were `0/0`, reconstructable state was blank, and no parent file UID was assigned.
  - After: `COMPLETION:76`, `CONFIDENCE:84`, `RECONSTRUCTABLE:TRUE`, and `AUTOGEN_PARENT_UID:0000P6` for [UID:0000P6][VoteMenuPane](by-file/VoteMenuPane.md). `RECONSTRUCTION_CPP CODE` remains blank because the page is below the 95+ final-source threshold.
  - Evidence: IDA MCP rechecked `0x0069ba38` as a 4-byte singleton pointer with 8 data xrefs spanning VoteMenuPane construction/destruction and RightButtonMenuPane dismissal reads; it also preserves the generated `g_pBulletinSession` alias warning.
