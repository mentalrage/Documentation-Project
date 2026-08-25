*** UID:0000SQ | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000P9 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000P9 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
WebBoardDialog *g_pWebBoardDialog = NULL;
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# g_pWebBoardDialog

## Status

- Confidence: very strong for address, pointer type, source ownership, zero initialization, and complete eight-reference lifetime/use route
- Address: `0x0067ab9c`
- Exact storage page: [UID:0002WJ][0x0067ab9c-0x0067aba0.g_pWebBoardDialog](by-memory/0x0067ab9c-0x0067aba0.g_pWebBoardDialog.md)
- Current source-facing name: `g_pWebBoardDialog`; current IDA interval is four one-byte undefined heads beginning with `unk_67AB9C`
- Type: `WebBoardDialog *`
- Owner hypothesis: [UID:0000G2][WebBoardDialog](by-class/WebBoardDialog.md)
- Likely source module: [UID:0000P9][WebBoardDialog](by-file/WebBoardDialog.md)
- Rebuild handling: source-declared module/global singleton pointer; current MCP reads the slot as zero/null-initialized source static storage.
- Autogen parent: [UID:0000P9][WebBoardDialog](by-file/WebBoardDialog.md), position `40`; B010 emits the source-level singleton definition here so exact storage child [UID:0002WJ][0x0067ab9c-0x0067aba0.g_pWebBoardDialog](by-memory/0x0067ab9c-0x0067aba0.g_pWebBoardDialog.md) can stay marker-only.

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
- Current live read-only MCP records exactly eight xrefs: constructor publication/cleanup at `0x0046d0d1` and `0x0046d0d8`; ordinary destructor clear at `0x0046d330`; helper/unwind and scalar-wrapper clears at `0x00470250` and `0x00470796`; and singleton checks at `0x00554d3f`, `0x005bd0a1`, and `0x005bd20e`.
- Current IDA prestate for `[0x0067ab9c,0x0067aba0)` is four separate one-byte undefined heads, first named `unk_67AB9C`, with no type and bytes `00 00 00 00`. Address regular/repeatable comments are blank; function comments and frame/locals are N/A. Exact query `g_pWebBoardDialog` reports zero collisions. Neighbors `0x0067ab98` and old singleton storage at `0x0067aba0` remain separate.
- Supervisor Gate 2B may recreate only this exact interval as one physical `WebBoardDialog *` item named `g_pWebBoardDialog` with address-regular comment `WebBoardDialog singleton pointer; published by active constructors and cleared by ordinary, unwind, scalar-destruction, and shutdown paths.` Address-repeatable remains blank and function comments remain N/A. Deterministic readback requires the same zero bytes/eight xrefs, exact bounds/name/type/comment, and unchanged neighbors. Byte/xref/boundary/type/collision drift stops the action; no array, nonzero initializer, or old-singleton absorption is authorized.
- Historical 2026-05-31 IDA MCP `py_eval` described `0x0067ab9c` as one 4-byte `.data` item named `dword_67AB9C`, with the same eight data xrefs. Current sparse-item evidence supersedes only that old item/name description.
- B010 2026-06-30 current MCP evidence supersedes stale nonzero-initializer wording: the slot reads as zero/null-initialized, and the source definition is `WebBoardDialog *g_pWebBoardDialog = NULL;`.
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

- 2026-08-03 B002 UID000212 implementation callback:
  - Raised `88/92 -> 90/94`, preserved the sole CPP definition `WebBoardDialog *g_pWebBoardDialog = NULL;`, blank H, owner/emitter route, and all active-vs-old ownership evidence.
  - Added all eight exact xrefs and the complete current four-one-byte-head IDA prestate, collision result, supervisor-owned pointer-item action, deterministic readback, neighbor protections, and stop conditions without mutating IDA.

- 2026-06-30 B010 empty-emitter implementation callback:
  - Raised score to `88/92`, inserted source-level `WebBoardDialog *g_pWebBoardDialog = NULL;`, and corrected stale initializer wording to current zero/null evidence.
  - Evidence/disposition: this by-global page is the sole source definition site; exact storage child [UID:0002WJ][0x0067ab9c-0x0067aba0.g_pWebBoardDialog](by-memory/0x0067ab9c-0x0067aba0.g_pWebBoardDialog.md) must not duplicate storage.

- 2026-06-06 A010 active singleton evidence consolidation:
  - Before: `COMPLETION:76`, `CONFIDENCE:86`, with address/xref evidence but limited lifetime structure and active/old ownership rationale.
  - Changed to: `COMPLETION:84`, `CONFIDENCE:88`, explicit source-declared rebuild handling, likely pointer type, autogen/source-gate note, lifetime/user table, and active-vs-old ownership explanation.
  - Summary/evidence: existing IDA MCP evidence records the `.data` storage at `0x0067ab9c`, constructor set/cleanup xrefs at `0x0046d0d1` and `0x0046d0d8`, destructor/cleanup/scalar clears at `0x0046d330`, `0x00470250`, and `0x00470796`, and singleton checks at `0x00554d3f`, `0x005bd0a1`, and `0x005bd20e`; B010 later corrected the initializer wording to current zero/null evidence.
- 2026-05-31 reconstruction metadata and grading:
  - What existed before: `COMPLETION:0`, `CONFIDENCE:0`, blank `RECONSTRUCTABLE`, and no autogen parent.
  - Changed to: `COMPLETION:76`, `CONFIDENCE:86`, `RECONSTRUCTABLE:TRUE`, parent [UID:0000P9][WebBoardDialog](by-file/WebBoardDialog.md), and ordered file-local position `40`.
  - Summary/evidence: IDA MCP confirms the exact singleton storage, initial value, constructor store, destructor/unwind clears, and singleton check xrefs; B010 later emitted the accepted source pointer definition on this by-global page.
- 2026-06-07 A004 split-rule correction:
  - Before: `COMPLETION:84`, `CONFIDENCE:88`.
  - Changed to: `COMPLETION:86`, `CONFIDENCE:90`.
  - Summary/evidence: live IDA MCP reconfirmed exact initialized storage, 8 refs across 6 functions, active constructor stores, destructor/cleanup/scalar clears, and singleton checks. The page now explicitly records the pending exact child split blocked by new-file lease rejection.
- 2026-06-07 A004 Batch 046 split:
  - Before: page recorded the exact child as pending.
  - Changed to: linked exact child [UID:0002WJ][0x0067ab9c-0x0067aba0.g_pWebBoardDialog](by-memory/0x0067ab9c-0x0067aba0.g_pWebBoardDialog.md).
  - Summary/evidence: child page now carries the initialized storage/xref evidence and assigns directly here under the corrected gate.
