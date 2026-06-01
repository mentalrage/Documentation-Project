*** UID:0000SQ | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:76 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000P9 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL:40 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# g_pWebBoardDialog

## Status

- Confidence: strong for address and role
- Address: `0x0067ab9c`
- Current generated names: `dword_67AB9C`
- Owner hypothesis: [UID:0000G2][WebBoardDialog](by-class/WebBoardDialog.md)
- Likely source module: [UID:0000P9][WebBoardDialog](by-file/WebBoardDialog.md)

## Symbol Role

`g_pWebBoardDialog` is the active singleton pointer for the live browser-backed web-board dialog.

## Evidence

- `0x0046d050` stores the constructed `WebBoardDialog` pointer at `0x0067ab9c`.
- `0x0046d330`, `0x00470250`, and `0x00470790` clear the same address during destructor/unwind/scalar-delete paths.
- IDA `xrefs_to 0x0067ab9c` also sees menu/map/browser-adjacent users at `0x00554d3f`, `0x005bd0a1`, and `0x005bd20e`, matching singleton open/close checks.
- 2026-05-31 IDA MCP `py_eval` recheck confirms `0x0067ab9c` is a 4-byte `.data` item named `dword_67AB9C`, initialized to `0xffffffff`, with 8 data xrefs: constructor set/cleanup at `0x0046d0d1` and `0x0046d0d8`, destructor/unwind clears at `0x0046d330`, `0x00470250`, and `0x00470796`, and singleton state checks at `0x00554d3f`, `0x005bd0a1`, and `0x005bd20e`.

## Ownership Decision

Declare this with [UID:0000P9][WebBoardDialog](by-file/WebBoardDialog.md). It is browser-coupled but board-specific, so it should not be migrated as generic [UID:0000HV][Browser](by-file/Browser.md) state.

## Cross-References

- [UID:0000G2][WebBoardDialog](by-class/WebBoardDialog.md)
- [UID:0000P9][WebBoardDialog](by-file/WebBoardDialog.md)
- [UID:0000Z7][0x0046d050-0x0046d324.WebBoardDialog](by-memory/0x0046d050-0x0046d324.WebBoardDialog.md)
- [UID:0000Z9][0x0046d580-0x0046da63.WebBoardDialogHandleBoardResponse](by-memory/0x0046d580-0x0046da63.WebBoardDialogHandleBoardResponse.md)
- [UID:0000SR][g_pWebBoardDialogOld](by-global/g_pWebBoardDialogOld.md)

## Changes

- 2026-05-31 reconstruction metadata and grading:
  - What existed before: `COMPLETION:0`, `CONFIDENCE:0`, blank `RECONSTRUCTABLE`, and no autogen parent.
  - Changed to: `COMPLETION:76`, `CONFIDENCE:86`, `RECONSTRUCTABLE:TRUE`, parent [UID:0000P9][WebBoardDialog](by-file/WebBoardDialog.md), and ordered file-local position `40`.
  - Summary/evidence: IDA MCP confirms the exact singleton storage, initial value, constructor store, destructor/unwind clears, and singleton check xrefs; final C++ remains blank because the source declaration shape and surrounding emitted code do not meet the 95+ final-source gate.
