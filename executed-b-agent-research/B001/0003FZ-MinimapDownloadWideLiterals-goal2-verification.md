** TARGET-REPORT-UID:0003FZ **
** AUTHOR-AGENT-ID:B001 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
** REPORT-VALIDATION-STATUS: needs-revalidation **
** REPORT-REVALIDATION-REASON: target_uid_unknown: 0003FZ **
# [UID:0003FZ] MinimapDownloadWideLiterals Goal 2 Verification

## FINAL RECOMMENDATION

No change is recommended. Keep the current generated state:

- `CANONICAL_OWNER:NONE`
- `RECONSTRUCTABLE:TRUE`
- `EMITTER_UIDS:0000JC,0000LE`
- no `RECONSTRUCTION_CPP` body
- no split, merge, reclassification, child-page creation, IDA repair, or coverage-row edit required for this target

This is a valid pooled-literal/source-use case. A single canonical declaration owner is not defensible because the physical UTF-16LE minimap download literal group is consumed by both the FileDownloader message path and the MiniMap downloader path. The blank-owner decision is separate from emission routing: the current two emitters are justified because current IDA evidence proves real source-use contexts under [UID:0000JC] `FileDownloader` and [UID:0000LE] `MiniMap`.

Exact `by-memory/-coverage-report.md` replacement row: not applicable. The current shared coverage row already records the no-owner/two-emitter decision, so no direct edit or pending replacement text is needed.

---

## Current Documentation Checked

- Target page: `by-memory/0x0060d7f4-0x0060d8b8.MinimapDownloadWideLiterals.md`
  - Current header is `COMPLETION:89`, `CONFIDENCE:93`, `CANONICAL_OWNER:NONE`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000JC,0000LE`.
  - The page describes a UTF-16LE minimap download literal group bounded at `0x0060d7f4-0x0060d8b8`, with the successor item-shop version URL starting at `0x0060d8b8`.
- Coverage source: `auto-generated/-ag-memory-coverage.md`
  - Current generated state lists no canonical owner and emitters `0000JC`,`0000LE`.
- Shared coverage report: `by-memory/-coverage-report.md`
  - Current row already says B002/B001 reviews kept `CANONICAL_OWNER:NONE` and retained `EMITTER_UIDS:0000JC,0000LE` because FileDownloader message `10000`, MiniMapDownloader, and raw MiniMap-side refs consume the block.
- Candidate roots:
  - [UID:0000JC] `by-file/FileDownloader.md` clears `85/85` and documents the FileDownloader message `10000` minimap helper path.
  - [UID:0000LE] `by-file/MiniMap.md` clears `85/85` and documents the MiniMapDownloader path.
- Candidate consumers:
  - [UID:0002TR] `by-memory/0x0041a750-0x0041a9fe.DownloadMinimapFile.md` is the FileDownloader-side consumer.
  - [UID:0000XN] `by-memory/0x00453910-0x00453def.MiniMapDownloader.md` is the MiniMap-side consumer.
- Prior report used as evidence only:
  - `Agent-B002/research/executed/0003FZ-MinimapDownloadWideLiterals-live-goal2-no-owner-pass.md`.

## Fresh IDA MCP Evidence

IDA MCP session used for this pass:

- Session: `a001_goal2_class_batch`
- Input: `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`
- Backend: worker, active, not analyzing

`get_string` and `get_bytes` confirm the target range contains these UTF-16LE strings:

| Address | String |
| --- | --- |
| `0x0060d7f4` | `000` |
| `0x0060d7f8` | overlapping `0` head inside the `000` bytes |
| `0x0060d7fc` | `%03d` |
| `0x0060d808` | `.mnm` |
| `0x0060d818` | `https://s3.amazonaws.com/kru-downloads/tk/minimaps/` |
| `0x0060d880` | `%s%s/%s%s` |
| `0x0060d894` | `Downloading : %d\n` |
| `0x0060d8b8` | successor `https://secure.kru.com/itemshop/data/itemshop.ver` |

`xrefs_to` confirms two modeled consumer functions for every target literal, plus raw MiniMap-neighborhood refs for selected literals:

- `0x0060d7f4`: `0x0041a794` in `sub_41A750`, `0x00453ae4` in `sub_453AA0`
- `0x0060d7f8`: `0x0041a7a0` in `sub_41A750`, `0x00453aed` in `sub_453AA0`
- `0x0060d7fc`: `0x0041a7d2` in `sub_41A750`, `0x00453b12` in `sub_453AA0`
- `0x0060d808`: `0x0041a7e2` in `sub_41A750`, `0x00453b22` in `sub_453AA0`, raw `0x00454e6f`
- `0x0060d818`: `0x0041a7f2` in `sub_41A750`, `0x00453b32` in `sub_453AA0`, raw `0x00454e7b`
- `0x0060d880`: `0x0041a7f7` in `sub_41A750`, `0x00453b37` in `sub_453AA0`
- `0x0060d894`: `0x0041a988` in `sub_41A750`, `0x00453cd7` in `sub_453AA0`, raw `0x00454fcc`
- `0x0060d8b8`: only `0x0041aa64` in `sub_41AA00`, confirming the successor string belongs to the next FileDownloader-only child rather than this minimap block.

Defined helper evidence:

- `sub_41A750` is called from `sub_41B110` at `0x0041b168`. The caller subtracts `0x2710` from the message value, so the matched branch is message `10000`.
- `sub_453AA0` is called from `sub_453A00` at `0x00453a16`.
- The two modeled helpers push the same target literals and call the same wide download/write API set. Filtered IDA disassembly shows both helpers use `szAgent`, `dword_60D7F4`, `dword_60D7F8`, `a03d`, `aMnm`, `aHttpsS3Amazona`, `aSSSS`, and `aDownloadingD`.
- `callees` for both `sub_41A750` and `sub_453AA0` include `InternetOpenW`, `InternetOpenUrlW`, `HttpQueryInfoW`, `InternetQueryDataAvailable`, `InternetReadFile`, `WriteFile`, `OutputDebugStringW`, `CloseHandle`, and the shared formatter `sub_41B9B0`.

Raw MiniMap-neighborhood evidence:

- The raw range starting at `0x00454e30` is not an IDA-modeled function, but `insn_query` over `0x00454e30-0x00455030` shows a complete downloader-shaped body.
- That raw body pushes `szAgent`, `.mnm` at `0x00454e6f`, the S3 minimap URL at `0x00454e7b`, and `Downloading : %d\n` at `0x00454fcc`, then calls WinINet/file APIs.
- This raw body strengthens the MiniMap-side source-use evidence, but it does not require a new emitter or canonical owner because the modeled MiniMap helper `sub_453AA0` already establishes the [UID:0000LE] emitter route.

## Fresh PE Byte Evidence

Read-only PE scan target:

- `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`
- Image base: `0x00400000`
- Target VA range: `0x0060d7f4-0x0060d8b8`
- Length: `0xc4` bytes, decimal `196`
- File offset: `0x20c1f4`
- Exact block hit count: one, at file offset `0x20c1f4` / VA `0x0060d7f4`

Absolute pointer/immediate hits match IDA xrefs:

- `0x0060d7f4`: `0x0041a796`, `0x00453ae6`
- `0x0060d7f8`: `0x0041a7a2`, `0x00453aef`
- `0x0060d7fc`: `0x0041a7d3`, `0x00453b13`
- `0x0060d808`: `0x0041a7e3`, `0x00453b23`, `0x00454e70`
- `0x0060d818`: `0x0041a7f3`, `0x00453b33`, `0x00454e7c`
- `0x0060d880`: `0x0041a7f8`, `0x00453b38`
- `0x0060d894`: `0x0041a989`, `0x00453cd8`, `0x00454fcd`
- `0x0060d8b8`: `0x0041aa65`

RVA-form pointer scans for the same addresses returned zero hits, so the current evidence is absolute-VA use in code, not an alternate RVA table.

## Candidate Owner And Emitter Analysis

[UID:0000JC] `FileDownloader`

- Emitter: yes. `sub_41A750` consumes the full minimap block, and `sub_41B110` dispatches to it from the message `10000` branch.
- Canonical owner: no. FileDownloader does not cover the MiniMapDownloader modeled consumer or the raw MiniMap-neighborhood downloader body. Assigning it as canonical owner would overclaim declaration ownership for a physical pooled block used by another source family.

[UID:0000LE] `MiniMap`

- Emitter: yes. `sub_453AA0` consumes the full minimap block through the MiniMapDownloader path, and raw refs at `0x00454e6f`, `0x00454e7b`, and `0x00454fcc` are also in the MiniMap-side downloader neighborhood.
- Canonical owner: no. MiniMap does not cover the FileDownloader message `10000` path. Assigning it as canonical owner would overclaim declaration ownership for literals also used by FileDownloader.

Blank emitters

- Rejected. This target is reconstructable data with proven source-use contexts under two current file roots. Leaving `EMITTER_UIDS` blank would hide literals that both reconstructed source families need.

Synthetic shared constants owner

- Rejected. Current docs and IDA evidence prove shared use, but they do not prove a separate source declaration unit or constants file. Under `by-structure.md`, shared use is enough for multiple emitters, not enough for inventing a canonical declaration owner.

Per-string split

- Rejected. The internal strings are consumed together by the same FileDownloader and MiniMap modeled helpers. Splitting the block into per-literal child pages would not produce different owners or emitters and would lose the useful grouped minimap-download context.

Merge with adjacent literals

- Rejected. `0x0060d8b8` starts the item-shop version URL and has only the FileDownloader-only `sub_41AA00` xref. The left neighbor [UID:0003FY] is the shared user-agent literal. The current boundaries are supported by both IDA strings and PE bytes.

IDA repair

- Not required for this target. The raw `0x00454e30` body is function-shaped and useful evidence, but defining or promoting it is a separate MiniMap-side function modeling question. The target ownership/emitter route is already proven by current modeled helpers.

## Exact Recommended Changes

No documentation metadata changes are recommended.

- Do not edit `by-memory/0x0060d7f4-0x0060d8b8.MinimapDownloadWideLiterals.md`.
- Do not edit `by-memory/-coverage-report.md`.
- Do not create child pages.
- Do not change the generated no-owner/two-emitter route.

If a future coverage refresh rewrites this row, the expected semantic result should remain:

- owner class: no-owner
- canonical owner: `NONE`
- emitters: `0000JC`,`0000LE`
- note: pooled UTF-16LE minimap download literals used by FileDownloader message `10000` and MiniMapDownloader.

## Validation Notes

No leases were required because this pass only writes the Agent-B001 research report and does not modify shared `by-*` documentation.

No dry runs were used.

The local workspace is not a Git checkout, so git status/diff validation is unavailable here. File existence and current target/coverage text were checked directly from disk before writing this report.

## Confidence

High. The current `89/93` score remains appropriate. The evidence independently confirms the bytes, exact boundary, modeled xrefs, callers, API behavior, raw MiniMap-side refs, and current two-emitter routing. Confidence is not raised further because the original source declaration model for the pooled literals is still not recoverable from current IDA/PE evidence.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"command_id":"000000004167","details":"report marked for revalidation","event":"needs-revalidation","issue":"target_uid_unknown: 0003FZ","source_path":"executed-b-agent-research/B001/0003FZ-MinimapDownloadWideLiterals-goal2-verification.md","timestamp":"2026-07-01T19:52:03-04:00"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
