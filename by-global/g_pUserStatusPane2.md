*** UID:0000SN | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:72 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000P2 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# g_pUserStatusPane2

## Status

- Confidence: strong.
- Address: `0x0069b4e4`
- IDA name: `dword_69B4E4`
- Proposed owner file: [UID:0000P2][UserStatusPane](by-file/UserStatusPane.md)
- Related class: [UID:0000FT][UserStatusPane2](by-class/UserStatusPane2.md)

## Role

`g_pUserStatusPane2` stores the active compact status-meter pane. It is installed by `UserStatusPane2` construction and cleared by cleanup, singleton-clear, and scalar deleting destructor paths.

## Evidence Notes

- `UserStatusPane2::UserStatusPane2` writes the global at `0x005bab4a` and `0x005bab51`.
- The cleanup body clears it at `0x005bac5e`.
- The singleton clear helper at `0x005bfbf0` writes zero to `0x0069b4e4`.
- The scalar deleting destructor clears it at `0x005bfec5`.
- `InitializeMainUiGraph` constructs the pane in the newer layout at `0x004f83ea`.
- IDA MCP `py_eval` rechecked `0x0069b4e4` on 2026-05-31 and confirmed IDA name `dword_69B4E4`, initial dword `0xffffffff`, and 6 data xrefs: map cleanup read at `0x00504925`, constructor writes at `0x005bab4a` and `0x005bab51`, cleanup clear at `0x005bac5e`, singleton-clear helper at `0x005bfbf0`, and scalar deleting destructor clear at `0x005bfec5`.

## Cross-References

- [UID:0000P2][UserStatusPane](by-file/UserStatusPane.md)
- [UID:0000FT][UserStatusPane2](by-class/UserStatusPane2.md)
- [UID:0001NO][0x005bab00-0x005bc60c.UserStatusPane2](by-memory/0x005bab00-0x005bc60c.UserStatusPane2.md)
- [UID:0001NS][0x005bfbd0-0x005c0034.UiPaneDestructorThunksAndVectorHelper](by-memory/0x005bfbd0-0x005c0034.UiPaneDestructorThunksAndVectorHelper.md)

## Changes

- 2026-05-31: Updated reconstruction metadata and scores from live IDA evidence.
  - Before: completion/confidence were `0/0`, reconstructable state was blank, and no parent file UID was assigned.
  - After: `COMPLETION:72`, `CONFIDENCE:84`, `RECONSTRUCTABLE:TRUE`, and `AUTOGEN_PARENT_UID:0000P2` for [UID:0000P2][UserStatusPane](by-file/UserStatusPane.md). `RECONSTRUCTION_CPP CODE` remains blank because the page is below the 95+ final-source threshold.
  - Evidence: IDA MCP rechecked `0x0069b4e4` as a 4-byte singleton pointer with 6 data xrefs spanning map cleanup, UserStatusPane2 construction, cleanup, singleton-clear helper, and scalar deleting destructor.
