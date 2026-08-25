*** UID:0000SR | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000P9 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000P9 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
WebBoardDialogOld *g_pWebBoardDialogOld = NULL;
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# g_pWebBoardDialogOld

## Status

- Confidence: very strong for address, pointer type, source ownership, zero initialization, and the complete five-reference lifetime route
- Address: `0x0067aba0`
- Exact storage page: [UID:0002WK][0x0067aba0-0x0067aba4.g_pWebBoardDialogOld](by-memory/0x0067aba0-0x0067aba4.g_pWebBoardDialogOld.md)
- Current source-facing name: `g_pWebBoardDialogOld`; current IDA item begins as `unk_67ABA0` because the four-byte interval is still four one-byte unknown heads
- Type: `WebBoardDialogOld *`
- Owner hypothesis: [UID:0000G3][WebBoardDialogOld](by-class/WebBoardDialogOld.md)
- Likely source module: [UID:0000P9][WebBoardDialog](by-file/WebBoardDialog.md)
- Rebuild handling: source-declared module/global singleton pointer; current MCP reads the slot as zero/null-initialized source static storage.
- Autogen parent: [UID:0000P9][WebBoardDialog](by-file/WebBoardDialog.md), position `50`; B010 emits the source-level singleton definition here so exact storage child [UID:0002WK][0x0067aba0-0x0067aba4.g_pWebBoardDialogOld](by-memory/0x0067aba0-0x0067aba4.g_pWebBoardDialogOld.md) can stay marker-only.

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
- Current read-only MCP evidence records exactly five xrefs: constructor publication/cleanup at `0x0046e6ba` and `0x0046e6c1`, the ordinary source destructor clear at `0x0046e8c0`, helper/unwind clear at `0x00470260`, and scalar-wrapper clear at `0x004707f6`. The ordinary source destructor in [UID:000212][0x0046e8c0-0x0046e9f5.WebBoardDialogOldDestructionAndMouseCallbacks](by-memory/0x0046e8c0-0x0046e9f5.WebBoardDialogOldDestructionAndMouseCallbacks.md) clears only this singleton; BrowserPane/base teardown and scalar-wrapper behavior are compiler-generated elsewhere.
- Current IDA prestate for `[0x0067aba0,0x0067aba4)` is four separate one-byte unknown heads with first name `unk_67ABA0`, no declaration/type, bytes `00 00 00 00`, blank address regular/repeatable comments, function comments N/A, and frame/locals N/A. Exact-name query `g_pWebBoardDialogOld` returns zero collisions. Neighbor `0x0067ab9c` is active `g_pWebBoardDialog` storage and `0x0067aba4` begins MainMenuPane singleton storage.
- Supervisor Gate 2B may replace only that exact interval with one physical four-byte `WebBoardDialogOld *` item named `g_pWebBoardDialogOld` and address-regular comment `WebBoardDialogOld singleton pointer; published by the old constructor and cleared by ordinary, unwind, and scalar-destruction paths.` Expected readback is the same zero bytes and five xrefs, blank address-repeatable comment, function comments N/A, and unchanged neighbor boundaries. Any byte, xref, boundary, collision, or type-parse drift is a stop condition; no array, nonzero initializer, or adjacent-item absorption is allowed.
- `simroot_v2/class_RankingDialog.cpp` emits this symbol because of stale generated ownership, but the constructor/resource/response path is web-board-specific.
- Historical 2026-05-31 IDA MCP `py_eval` described `0x0067aba0` as a 4-byte `.data` item named `dword_67ABA0`, with the same five data xrefs. The current one-byte-head readback above supersedes only that old physical-item/name description, not the address, zero bytes, lifetime, or source ownership.
- B010 2026-06-30 current MCP evidence supersedes stale nonzero-initializer wording: the slot reads as zero/null-initialized, and the source definition is `WebBoardDialogOld *g_pWebBoardDialogOld = NULL;`.
- A004 live IDA MCP on 2026-06-07 reconfirmed the same initialized four-byte storage and 5 refs across 4 functions while reviewing the mixed singleton cluster split.
- [UID:0000P9][WebBoardDialog](by-file/WebBoardDialog.md) documents the old dialog's constructor, resource usage, request helper, response parser, URL escape helper, destruction callbacks, and stale `RankingDialog` generated-owner pollution.
- B008 2026-06-19 class source-quality reanalysis closes the final class/type framing as `WebBoardDialogOld *g_pWebBoardDialogOld`. The class page now routes through [UID:0000P9][WebBoardDialog](by-file/WebBoardDialog.md), rejects `OldWebBoardDialog` spelling and RankingDialog ownership, and uses this singleton as one of the primary active-vs-old split anchors.

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

- 2026-08-03 B002 UID000212 implementation callback:
  - Raised the score from `88/92` to `90/94` after recording the ordinary-destructor role, exact five-reference lifetime inventory, and complete current sparse-item prestate.
  - Preserved the sole source definition `WebBoardDialogOld *g_pWebBoardDialogOld = NULL;` and blank H channel. Added the exact supervisor-owned four-byte pointer-item action, deterministic readback, neighbor protections, collision result, and stop conditions without mutating IDA.
  - Retained the older `dword_67ABA0` evidence only as explicitly historical; current live state begins with `unk_67ABA0` across four one-byte heads.

- 2026-06-30 B010 empty-emitter implementation callback:
  - Raised score to `88/92`, inserted source-level `WebBoardDialogOld *g_pWebBoardDialogOld = NULL;`, and corrected stale initializer wording to current zero/null evidence.
  - Evidence/disposition: this by-global page is the sole source definition site; exact storage child [UID:0002WK][0x0067aba0-0x0067aba4.g_pWebBoardDialogOld](by-memory/0x0067aba0-0x0067aba4.g_pWebBoardDialogOld.md) must not duplicate storage.

- 2026-06-21 B008 old-class singleton sync:
  - Added the final class/type framing from [UID:0000G3][WebBoardDialogOld](by-class/WebBoardDialogOld.md): this global is `WebBoardDialogOld *g_pWebBoardDialogOld` under [UID:0000P9][WebBoardDialog](by-file/WebBoardDialog.md), with RankingDialog placement rejected as generated-output pollution.

- 2026-06-06 A010 old singleton evidence consolidation:
  - Before: `COMPLETION:76`, `CONFIDENCE:86`, with address/xref evidence but limited lifetime structure and stale `RankingDialog` ownership rationale.
  - Changed to: `COMPLETION:84`, `CONFIDENCE:88`, explicit source-declared rebuild handling, likely pointer type, autogen/source-gate note, lifetime table, stronger old-variant ownership explanation, and additional old helper cross-references.
  - Summary/evidence: existing IDA MCP evidence records the `.data` storage at `0x0067aba0`, constructor set/cleanup xrefs at `0x0046e6ba` and `0x0046e6c1`, destructor/cleanup/scalar clears at `0x0046e8c0`, `0x00470260`, and `0x004707f6`, plus the by-file page's old-variant helper inventory and stale `RankingDialog` owner caveat; B010 later corrected the initializer wording to current zero/null evidence.
- 2026-05-31 reconstruction metadata and grading:
  - What existed before: `COMPLETION:0`, `CONFIDENCE:0`, blank `RECONSTRUCTABLE`, and no autogen parent.
  - Changed to: `COMPLETION:76`, `CONFIDENCE:86`, `RECONSTRUCTABLE:TRUE`, parent [UID:0000P9][WebBoardDialog](by-file/WebBoardDialog.md), and ordered file-local position `50`.
  - Summary/evidence: IDA MCP confirms the exact singleton storage, initial value, constructor store, destructor/unwind clears, and the generated RankingDialog owner is stale; B010 later emitted the accepted source pointer definition on this by-global page.
- 2026-06-07 A004 split-rule correction:
  - Before: `COMPLETION:84`, `CONFIDENCE:88`.
  - Changed to: `COMPLETION:86`, `CONFIDENCE:90`.
  - Summary/evidence: live IDA MCP reconfirmed exact initialized storage, 5 refs across 4 functions, old constructor stores, destructor/cleanup/scalar clears, and stale generated-owner exclusion. The page now explicitly records the pending exact child split blocked by new-file lease rejection.
- 2026-06-07 A004 Batch 046 split:
  - Before: page recorded the exact child as pending.
  - Changed to: linked exact child [UID:0002WK][0x0067aba0-0x0067aba4.g_pWebBoardDialogOld](by-memory/0x0067aba0-0x0067aba4.g_pWebBoardDialogOld.md).
  - Summary/evidence: child page now carries the initialized storage/xref evidence and assigns directly here under the corrected gate.
