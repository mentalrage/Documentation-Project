*** UID:0000SR | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:76 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000P9 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL:50 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# g_pWebBoardDialogOld

## Status

- Confidence: strong for address and role
- Address: `0x0067aba0`
- Current generated names: `g_pWebBoardDialogOld`, `dword_67ABA0`
- Owner hypothesis: [UID:0000G3][WebBoardDialogOld](by-class/WebBoardDialogOld.md)
- Likely source module: [UID:0000P9][WebBoardDialog](by-file/WebBoardDialog.md)

## Symbol Role

`g_pWebBoardDialogOld` is the active singleton pointer for the legacy fixed-art web-board dialog.

## Evidence

- `0x0046e640` installs `WebBoardDialogOld` vtables and stores the constructed object at `0x0067aba0`.
- `0x0046e8c0`, `0x00470260`, and `0x004707f0` clear the same address during destructor/unwind/scalar-delete paths.
- IDA `xrefs_to 0x0067aba0` also sees browser cleanup helpers at `0x00470260` and `0x004707f0`.
- `simroot_v2/class_RankingDialog.cpp` emits this symbol because of stale generated ownership, but the constructor/resource/response path is web-board-specific.
- 2026-05-31 IDA MCP `py_eval` recheck confirms `0x0067aba0` is a 4-byte `.data` item named `dword_67ABA0`, initialized to `0xffffffff`, with 5 data xrefs: constructor set/cleanup at `0x0046e6ba` and `0x0046e6c1`, destructor clear at `0x0046e8c0`, cleanup helper clear at `0x00470260`, and scalar-deleting destructor clear at `0x004707f6`.

## Ownership Decision

Declare this with [UID:0000P9][WebBoardDialog](by-file/WebBoardDialog.md) beside the old variant class. It should be excluded from [UID:0000MZ][RankingDialog](by-file/RankingDialog.md) migrations.

## Cross-References

- [UID:0000G3][WebBoardDialogOld](by-class/WebBoardDialogOld.md)
- [UID:0000P9][WebBoardDialog](by-file/WebBoardDialog.md)
- [UID:0000ZB][0x0046e640-0x0046e8be.WebBoardDialogOldConstructor](by-memory/0x0046e640-0x0046e8be.WebBoardDialogOldConstructor.md)
- [UID:0000ZD][0x0046eaa0-0x0046ee7a.WebBoardDialogOldHandleBoardResponse](by-memory/0x0046eaa0-0x0046ee7a.WebBoardDialogOldHandleBoardResponse.md)
- [UID:0000SQ][g_pWebBoardDialog](by-global/g_pWebBoardDialog.md)

## Changes

- 2026-05-31 reconstruction metadata and grading:
  - What existed before: `COMPLETION:0`, `CONFIDENCE:0`, blank `RECONSTRUCTABLE`, and no autogen parent.
  - Changed to: `COMPLETION:76`, `CONFIDENCE:86`, `RECONSTRUCTABLE:TRUE`, parent [UID:0000P9][WebBoardDialog](by-file/WebBoardDialog.md), and ordered file-local position `50`.
  - Summary/evidence: IDA MCP confirms the exact singleton storage, initial value, constructor store, destructor/unwind clears, and the generated RankingDialog owner is stale; final C++ remains blank because the source declaration shape and surrounding emitted code do not meet the 95+ final-source gate.
