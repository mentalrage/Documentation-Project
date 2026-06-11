*** UID:0000SQ | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
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
- Exact storage page: [UID:0002WJ][0x0067ab9c-0x0067aba0.g_pWebBoardDialog](by-memory/0x0067ab9c-0x0067aba0.g_pWebBoardDialog.md)
- Current generated names: `dword_67AB9C`
- Likely type: `WebBoardDialog*`
- Owner hypothesis: [UID:0000G2][WebBoardDialog](by-class/WebBoardDialog.md)
- Likely source module: [UID:0000P9][WebBoardDialog](by-file/WebBoardDialog.md)
- Rebuild handling: source-declared module/global singleton pointer; the `0xffffffff` binary initializer is linker output for source-level static storage.
- Autogen parent: [UID:0000P9][WebBoardDialog](by-file/WebBoardDialog.md), position `40`; final C++ remains blank under the `95+` source gate.

## Symbol Role

`g_pWebBoardDialog` is the active singleton pointer for the live browser-backed web-board dialog. It represents active dialog lifetime and open/close checks for the board-specific browser pane, not generic browser infrastructure.

## Lifetime And Users

| Site | Use | Notes |
| --- | --- | --- |
| `0x0046d0d1` / `0x0046d0d8` | Constructor set and local cleanup path | Part of [UID:0000Z7][0x0046d050-0x0046d324.WebBoardDialog](by-memory/0x0046d050-0x0046d324.WebBoardDialog.md); stores the constructed active dialog pointer. |
| `0x0046d330` | Destructor clear | Active dialog destructor/unwind companion clears singleton state. |
| `0x00470250` | Cleanup helper clear | Shared browser/web-board cleanup path clears the active singleton before object teardown completes. |
| `0x00470796` | Scalar-delete clear | Scalar deleting destructor path clears singleton parity with ordinary destruction. |
| `0x00554d3f`, `0x005bd0a1`, `0x005bd20e` | Singleton checks/users | Menu/map/browser-adjacent callers test whether the active web-board dialog is already present before opening or closing it. |

## Evidence

- `0x0046d050` stores the constructed `WebBoardDialog` pointer at `0x0067ab9c`.
- `0x0046d330`, `0x00470250`, and `0x00470790` clear the same address during destructor/unwind/scalar-delete paths.
- IDA `xrefs_to 0x0067ab9c` also sees menu/map/browser-adjacent users at `0x00554d3f`, `0x005bd0a1`, and `0x005bd20e`, matching singleton open/close checks.
- 2026-05-31 IDA MCP `py_eval` recheck confirms `0x0067ab9c` is a 4-byte `.data` item named `dword_67AB9C`, initialized to `0xffffffff`, with 8 data xrefs: constructor set/cleanup at `0x0046d0d1` and `0x0046d0d8`, destructor/unwind clears at `0x0046d330`, `0x00470250`, and `0x00470796`, and singleton state checks at `0x00554d3f`, `0x005bd0a1`, and `0x005bd20e`.
- A004 live IDA MCP on 2026-06-07 reconfirmed the same initialized four-byte storage and 8 refs across 6 functions while reviewing the mixed singleton cluster split.
- [UID:0000P9][WebBoardDialog](by-file/WebBoardDialog.md) documents the active dialog source family, active/old split, URL escape helpers, and board-specific packet/resource behavior.

## Ownership Decision

Declare this with [UID:0000P9][WebBoardDialog](by-file/WebBoardDialog.md), next to [UID:0000SR][g_pWebBoardDialogOld](by-global/g_pWebBoardDialogOld.md). It is browser-coupled but board-specific, so it should not be migrated as generic [UID:0000HV][Browser](by-file/Browser.md) state.

The active singleton differs from the old singleton at `0x0067aba0`: this page owns the live/browser-backed `WebBoardDialog` path, while the old page owns the fixed-art `WebBoardDialogOld` path. Both belong in the same board-dialog source module because the file page now inventories both variants and their shared board/browser dependencies.

The exact memory child is [UID:0002WJ][0x0067ab9c-0x0067aba0.g_pWebBoardDialog](by-memory/0x0067ab9c-0x0067aba0.g_pWebBoardDialog.md). It is assigned here because the child and this direct global parent both meet the corrected `85/85` gate.

## Cross-References

- [UID:0000G2][WebBoardDialog](by-class/WebBoardDialog.md)
- [UID:0000P9][WebBoardDialog](by-file/WebBoardDialog.md)
- [UID:0002WJ][0x0067ab9c-0x0067aba0.g_pWebBoardDialog](by-memory/0x0067ab9c-0x0067aba0.g_pWebBoardDialog.md)
- [UID:0000Z7][0x0046d050-0x0046d324.WebBoardDialog](by-memory/0x0046d050-0x0046d324.WebBoardDialog.md)
- [UID:0000Z9][0x0046d580-0x0046da63.WebBoardDialogHandleBoardResponse](by-memory/0x0046d580-0x0046da63.WebBoardDialogHandleBoardResponse.md)
- [UID:000278][0x0066d430-0x0066d468.BrowserUrlEscapeCharacterSets](by-memory/0x0066d430-0x0066d468.BrowserUrlEscapeCharacterSets.md)
- [UID:0000SR][g_pWebBoardDialogOld](by-global/g_pWebBoardDialogOld.md)
- [UID:0000HV][Browser](by-file/Browser.md)

## Changes

- 2026-06-06 A010 active singleton evidence consolidation:
  - Before: `COMPLETION:76`, `CONFIDENCE:86`, with address/xref evidence but limited lifetime structure and active/old ownership rationale.
  - Changed to: `COMPLETION:84`, `CONFIDENCE:88`, explicit source-declared rebuild handling, likely pointer type, autogen/source-gate note, lifetime/user table, and active-vs-old ownership explanation.
  - Summary/evidence: existing IDA MCP evidence records the `.data` storage at `0x0067ab9c`, `0xffffffff` initializer, constructor set/cleanup xrefs at `0x0046d0d1` and `0x0046d0d8`, destructor/cleanup/scalar clears at `0x0046d330`, `0x00470250`, and `0x00470796`, and singleton checks at `0x00554d3f`, `0x005bd0a1`, and `0x005bd20e`; the by-file page now documents both active and old web-board dialog variants in `WebBoardDialog.cpp`.
- 2026-05-31 reconstruction metadata and grading:
  - What existed before: `COMPLETION:0`, `CONFIDENCE:0`, blank `RECONSTRUCTABLE`, and no autogen parent.
  - Changed to: `COMPLETION:76`, `CONFIDENCE:86`, `RECONSTRUCTABLE:TRUE`, parent [UID:0000P9][WebBoardDialog](by-file/WebBoardDialog.md), and ordered file-local position `40`.
  - Summary/evidence: IDA MCP confirms the exact singleton storage, initial value, constructor store, destructor/unwind clears, and singleton check xrefs; final C++ remains blank because the source declaration shape and surrounding emitted code do not meet the 95+ final-source gate.
- 2026-06-07 A004 split-rule correction:
  - Before: `COMPLETION:84`, `CONFIDENCE:88`.
  - Changed to: `COMPLETION:86`, `CONFIDENCE:90`.
  - Summary/evidence: live IDA MCP reconfirmed exact initialized storage, 8 refs across 6 functions, active constructor stores, destructor/cleanup/scalar clears, and singleton checks. The page now explicitly records the pending exact child split blocked by new-file lease rejection.
- 2026-06-07 A004 Batch 046 split:
  - Before: page recorded the exact child as pending.
  - Changed to: linked exact child [UID:0002WJ][0x0067ab9c-0x0067aba0.g_pWebBoardDialog](by-memory/0x0067ab9c-0x0067aba0.g_pWebBoardDialog.md).
  - Summary/evidence: child page now carries the initialized storage/xref evidence and assigns directly here under the corrected gate.
