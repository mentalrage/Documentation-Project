*** UID:0000SR | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
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
- Exact storage page: [UID:0002WK][0x0067aba0-0x0067aba4.g_pWebBoardDialogOld](by-memory/0x0067aba0-0x0067aba4.g_pWebBoardDialogOld.md)
- Current generated names: `g_pWebBoardDialogOld`, `dword_67ABA0`
- Likely type: `WebBoardDialogOld*`
- Owner hypothesis: [UID:0000G3][WebBoardDialogOld](by-class/WebBoardDialogOld.md)
- Likely source module: [UID:0000P9][WebBoardDialog](by-file/WebBoardDialog.md)
- Rebuild handling: source-declared module/global singleton pointer; the `0xffffffff` binary initializer is linker output for source-level static storage.
- Autogen parent: [UID:0000P9][WebBoardDialog](by-file/WebBoardDialog.md), position `50`; final C++ remains blank under the `95+` source gate.

## Symbol Role

`g_pWebBoardDialogOld` is the active singleton pointer for the legacy fixed-art web-board dialog. It tracks the old board dialog variant that still uses the browser-control path but wraps it in `WEBBOARD.EPD` / `WEBBOARD.PAD` style resources.

## Lifetime And Users

| Site | Use | Notes |
| --- | --- | --- |
| `0x0046e6ba` / `0x0046e6c1` | Constructor set and local cleanup path | Part of [UID:0000ZB][0x0046e640-0x0046e8be.WebBoardDialogOldConstructor](by-memory/0x0046e640-0x0046e8be.WebBoardDialogOldConstructor.md); stores the constructed old dialog pointer. |
| `0x0046e8c0` | Destructor clear | Old-dialog destructor path clears singleton state. |
| `0x00470260` | Cleanup helper clear | Shared browser/web-board cleanup path clears the old singleton. |
| `0x004707f6` | Scalar-delete clear | Scalar deleting destructor path clears singleton parity with ordinary old-dialog destruction. |

## Evidence

- `0x0046e640` installs `WebBoardDialogOld` vtables and stores the constructed object at `0x0067aba0`.
- `0x0046e8c0`, `0x00470260`, and `0x004707f0` clear the same address during destructor/unwind/scalar-delete paths.
- IDA `xrefs_to 0x0067aba0` also sees browser cleanup helpers at `0x00470260` and `0x004707f0`.
- `simroot_v2/class_RankingDialog.cpp` emits this symbol because of stale generated ownership, but the constructor/resource/response path is web-board-specific.
- 2026-05-31 IDA MCP `py_eval` recheck confirms `0x0067aba0` is a 4-byte `.data` item named `dword_67ABA0`, initialized to `0xffffffff`, with 5 data xrefs: constructor set/cleanup at `0x0046e6ba` and `0x0046e6c1`, destructor clear at `0x0046e8c0`, cleanup helper clear at `0x00470260`, and scalar-deleting destructor clear at `0x004707f6`.
- A004 live IDA MCP on 2026-06-07 reconfirmed the same initialized four-byte storage and 5 refs across 4 functions while reviewing the mixed singleton cluster split.
- [UID:0000P9][WebBoardDialog](by-file/WebBoardDialog.md) documents the old dialog's constructor, resource usage, request helper, response parser, URL escape helper, destruction callbacks, and stale `RankingDialog` generated-owner pollution.

## Ownership Decision

Declare this with [UID:0000P9][WebBoardDialog](by-file/WebBoardDialog.md) beside the old variant class and the active singleton [UID:0000SQ][g_pWebBoardDialog](by-global/g_pWebBoardDialog.md). It should be excluded from [UID:0000MZ][RankingDialog](by-file/RankingDialog.md) migrations.

The generated `RankingDialog` placement is stale owner pollution: the exact xrefs are old web-board constructor/destructor/cleanup paths, and the by-file page keeps active and old variants together as board-specific browser dialogs.

The exact memory child is [UID:0002WK][0x0067aba0-0x0067aba4.g_pWebBoardDialogOld](by-memory/0x0067aba0-0x0067aba4.g_pWebBoardDialogOld.md). It is assigned here because the child and this direct global parent both meet the corrected `85/85` gate.

## Cross-References

- [UID:0000G3][WebBoardDialogOld](by-class/WebBoardDialogOld.md)
- [UID:0000P9][WebBoardDialog](by-file/WebBoardDialog.md)
- [UID:0002WK][0x0067aba0-0x0067aba4.g_pWebBoardDialogOld](by-memory/0x0067aba0-0x0067aba4.g_pWebBoardDialogOld.md)
- [UID:0000ZB][0x0046e640-0x0046e8be.WebBoardDialogOldConstructor](by-memory/0x0046e640-0x0046e8be.WebBoardDialogOldConstructor.md)
- [UID:0000ZD][0x0046eaa0-0x0046ee7a.WebBoardDialogOldHandleBoardResponse](by-memory/0x0046eaa0-0x0046ee7a.WebBoardDialogOldHandleBoardResponse.md)
- [UID:000212][0x0046e8c0-0x0046e9f5.WebBoardDialogOldDestructionAndMouseCallbacks](by-memory/0x0046e8c0-0x0046e9f5.WebBoardDialogOldDestructionAndMouseCallbacks.md)
- [UID:000213][0x0046ea30-0x0046ea99.WebBoardDialogOldInitialRequestHelper](by-memory/0x0046ea30-0x0046ea99.WebBoardDialogOldInitialRequestHelper.md)
- [UID:000214][0x0046ee80-0x0046efda.WebBoardDialogOldUrlEscapeHelper](by-memory/0x0046ee80-0x0046efda.WebBoardDialogOldUrlEscapeHelper.md)
- [UID:000278][0x0066d430-0x0066d468.BrowserUrlEscapeCharacterSets](by-memory/0x0066d430-0x0066d468.BrowserUrlEscapeCharacterSets.md)
- [UID:0000SQ][g_pWebBoardDialog](by-global/g_pWebBoardDialog.md)
- [UID:0000MZ][RankingDialog](by-file/RankingDialog.md)

## Changes

- 2026-06-06 A010 old singleton evidence consolidation:
  - Before: `COMPLETION:76`, `CONFIDENCE:86`, with address/xref evidence but limited lifetime structure and stale `RankingDialog` ownership rationale.
  - Changed to: `COMPLETION:84`, `CONFIDENCE:88`, explicit source-declared rebuild handling, likely pointer type, autogen/source-gate note, lifetime table, stronger old-variant ownership explanation, and additional old helper cross-references.
  - Summary/evidence: existing IDA MCP evidence records the `.data` storage at `0x0067aba0`, `0xffffffff` initializer, constructor set/cleanup xrefs at `0x0046e6ba` and `0x0046e6c1`, destructor/cleanup/scalar clears at `0x0046e8c0`, `0x00470260`, and `0x004707f6`, plus the by-file page's old-variant helper inventory and stale `RankingDialog` owner caveat.
- 2026-05-31 reconstruction metadata and grading:
  - What existed before: `COMPLETION:0`, `CONFIDENCE:0`, blank `RECONSTRUCTABLE`, and no autogen parent.
  - Changed to: `COMPLETION:76`, `CONFIDENCE:86`, `RECONSTRUCTABLE:TRUE`, parent [UID:0000P9][WebBoardDialog](by-file/WebBoardDialog.md), and ordered file-local position `50`.
  - Summary/evidence: IDA MCP confirms the exact singleton storage, initial value, constructor store, destructor/unwind clears, and the generated RankingDialog owner is stale; final C++ remains blank because the source declaration shape and surrounding emitted code do not meet the 95+ final-source gate.
- 2026-06-07 A004 split-rule correction:
  - Before: `COMPLETION:84`, `CONFIDENCE:88`.
  - Changed to: `COMPLETION:86`, `CONFIDENCE:90`.
  - Summary/evidence: live IDA MCP reconfirmed exact initialized storage, 5 refs across 4 functions, old constructor stores, destructor/cleanup/scalar clears, and stale generated-owner exclusion. The page now explicitly records the pending exact child split blocked by new-file lease rejection.
- 2026-06-07 A004 Batch 046 split:
  - Before: page recorded the exact child as pending.
  - Changed to: linked exact child [UID:0002WK][0x0067aba0-0x0067aba4.g_pWebBoardDialogOld](by-memory/0x0067aba0-0x0067aba4.g_pWebBoardDialogOld.md).
  - Summary/evidence: child page now carries the initialized storage/xref evidence and assigns directly here under the corrected gate.
