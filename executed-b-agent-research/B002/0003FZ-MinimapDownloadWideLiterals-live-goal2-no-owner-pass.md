** TARGET-REPORT-UID:0003FZ **
** AUTHOR-AGENT-ID:B002 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
** REPORT-VALIDATION-STATUS: needs-revalidation **
** REPORT-REVALIDATION-REASON: target_uid_unknown: 0003FZ **
# Final Recommendation

Keep [UID:0003FZ] `by-memory/0x0060d7f4-0x0060d8b8.MinimapDownloadWideLiterals.md` unchanged:

- `CANONICAL_OWNER:NONE`
- `EMITTER_UIDS:0000JC,0000LE`
- `RECONSTRUCTABLE:TRUE`
- no split, merge, reclassification, child creation, or canonical-owner assignment
- no reconstruction C++ in this pass

This is a valid strange owner/emitter split case. The range is reconstructable source-declared/generated-binary literal data, but no single declaration owner is defensible. Live IDA MCP and a fresh PE scan confirm the same physical UTF-16LE minimap literal block is used by both the FileDownloader message `10000` path (`sub_41A750`, rooted at [UID:0000JC] `FileDownloader`) and the MiniMapDownloader path (`sub_453AA0`, rooted at [UID:0000LE] `MiniMap`), with additional raw MiniMap-neighborhood references at `0x00454e6f`, `0x00454e7b`, and `0x00454fcc`. Assigning the block to either file would overclaim the other real source-use context; inventing a shared constants owner is not supported by source/debug/name/global evidence.

No shared coverage-report edit is required. If the supervisor wants a refreshed provenance row anyway, use this exact replacement text:

```text
            - [UID:0003FZ][0x0060d7f4-0x0060d8b8.MinimapDownloadWideLiterals](by-memory/0x0060d7f4-0x0060d8b8.MinimapDownloadWideLiterals.md) 0x0060d7f4-0x0060d8b8 | string-data | MinimapDownloadWideLiterals : reconstructable : 89% : very-strong : B002 2026-06-14 live Goal 2 IDA MCP and independent PE scans reconfirm the exact UTF-16LE minimap `000`/`%03d`/`.mnm`/S3 URL/`%s%s/%s%s`/progress literal block, unique full-block bytes, exact successor boundary at the `0x0060d8b8` item-shop version URL child, two modeled source-use families in FileDownloader message `10000` (`sub_41A750`) and MiniMapDownloader (`sub_453AA0`), raw MiniMap-side refs at `0x00454e6f`, `0x00454e7b`, and `0x00454fcc`, absolute-VA operand hits matching those refs, no RVA-form refs, and no source/debug/global/shared-constants declaration evidence. Keep `CANONICAL_OWNER:NONE` because FileDownloader, MiniMap, and the physical mixed container each overclaim declaration ownership; retain `EMITTER_UIDS:0000JC,0000LE` because both file roots are proven source-use emitters.
```

---

# Supporting Research

## Target

- Target UID: `0003FZ`
- Target path: `by-memory/0x0060d7f4-0x0060d8b8.MinimapDownloadWideLiterals.md`
- Assigned tracker section: `Active 2026-06-14 Live Goal 2 No-Owner Memory Pass`
- Current generated state: `CANONICAL_OWNER:NONE`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000JC,0000LE`
- Current scores: `COMPLETION:89`, `CONFIDENCE:93`
- Source queue context: no-owner memory row with existing emitters, not a blank non-emitting row

## Evidence Standard

This pass used current documentation as leads and current IDA/PE evidence as the deciding layer. The relevant `by-structure.md` rule is that `CANONICAL_OWNER` records semantic declaration ownership, while `EMITTER_UIDS` records generated source-use routing. Pooled literals can stay `CANONICAL_OWNER:NONE` while using multiple emitters when no single declaration owner is proven.

`inference_research.md` also warns against relying on physical `.rdata` adjacency alone. I treated the surrounding literal pool and existing target text as hypotheses, then rechecked bytes, xrefs, function ownership, and candidate file roots.

## Current Documentation Evidence

The target page currently documents these subranges:

| Range | Literal | Current representative refs |
| --- | --- | --- |
| `0x0060d7f4-0x0060d7fc` | UTF-16LE `000`, with overlapping IDA dword heads | FileDownloader `0x0041a794`, `0x0041a7a0`; MiniMapDownloader `0x00453ae4`, `0x00453aed` |
| `0x0060d7fc-0x0060d808` | UTF-16LE `%03d` | `0x0041a7d2`, `0x00453b12` |
| `0x0060d808-0x0060d818` | UTF-16LE `.mnm` | `0x0041a7e2`, `0x00453b22`, raw `0x00454e6f` |
| `0x0060d818-0x0060d880` | UTF-16LE `https://s3.amazonaws.com/kru-downloads/tk/minimaps/` | `0x0041a7f2`, `0x00453b32`, raw `0x00454e7b` |
| `0x0060d880-0x0060d894` | UTF-16LE `%s%s/%s%s` | `0x0041a7f7`, `0x00453b37` |
| `0x0060d894-0x0060d8b8` | UTF-16LE `Downloading : %d\n` | `0x0041a988`, `0x00453cd7`, raw `0x00454fcc` |

Relevant parent and neighbor docs:

- [UID:0003AL] `0x0060d7e0-0x0060d9c0.CashShopDownloaderLiterals` is a non-emitting split-audit container. It already splits this physical pool into exact literal children and intentionally avoids one parent for the mixed pool.
- [UID:0003FY] `0x0060d7e0-0x0060d7f4.SharedDownloaderUserAgentWideString` has the same `0000JC,0000LE` emitter pattern, but it is a different pooled user-agent literal also used by item-shop FileDownloader helpers.
- [UID:0003G0] `0x0060d8b8-0x0060d94c.CashShopVersionDownloadWideLiterals` is FileDownloader-only and starts exactly at the target successor boundary.
- [UID:0003G1] `0x0060d94c-0x0060d958.SharedVersionJsonKey` is a separate shared ASCII key with different emitters.
- [UID:0000JC] `FileDownloader` is `85/88`, has a valid `NexusTK/network/` source path, and documents the FileDownloader message `10000-10002` dispatch family.
- [UID:0000LE] `MiniMap` is `85/86`, has a valid `NexusTK/map/` source path, and documents MiniMapDownloader, MiniMapRenderer, MiniMapDialog, and related minimap state under the current file root.

## Live IDA MCP Facts

Active MCP state:

- Session: `a001_goal2_class_batch`
- Input: `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`
- IDB: `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe.i64`
- Imagebase: `0x400000`
- Hex-Rays and auto-analysis: ready

Function and address lookup:

- `0x0041a750` is `sub_41A750`, size `0x2ae`.
- All FileDownloader refs in the target block map inside `sub_41A750`.
- `0x00453aa0` is `sub_453AA0`, size `0x2af`.
- All modeled MiniMap refs in the target block map inside `sub_453AA0`.
- `0x00454e30`, `0x00454e6f`, `0x00454e7b`, and `0x00454fcc` are not IDA-modeled functions.
- `0x0060d7f4` and `0x0060d8b8` are data, not functions.

Literal bytes:

- `get_bytes 0x0060d7f4 size 0xc4` decodes as UTF-16LE `000`, `%03d`, `.mnm`, `https://s3.amazonaws.com/kru-downloads/tk/minimaps/`, `%s%s/%s%s`, and `Downloading : %d\n`.
- `get_bytes 0x0060d8b8` begins a separate UTF-16LE `https://...` item-shop version URL child.

Xrefs to target literal starts:

| Address | IDA xrefs |
| --- | --- |
| `0x0060d7f4` | `0x0041a794` in `sub_41A750`; `0x00453ae4` in `sub_453AA0` |
| `0x0060d7f8` | `0x0041a7a0` in `sub_41A750`; `0x00453aed` in `sub_453AA0` |
| `0x0060d7fc` | `0x0041a7d2` in `sub_41A750`; `0x00453b12` in `sub_453AA0` |
| `0x0060d808` | `0x0041a7e2` in `sub_41A750`; `0x00453b22` in `sub_453AA0`; raw `0x00454e6f` |
| `0x0060d818` | `0x0041a7f2` in `sub_41A750`; `0x00453b32` in `sub_453AA0`; raw `0x00454e7b` |
| `0x0060d880` | `0x0041a7f7` in `sub_41A750`; `0x00453b37` in `sub_453AA0` |
| `0x0060d894` | `0x0041a988` in `sub_41A750`; `0x00453cd7` in `sub_453AA0`; raw `0x00454fcc` |
| `0x0060d8b8` | one successor ref at `0x0041aa64` in `sub_41AA00`, outside this target |

Consumer function facts:

- `xrefs_to 0x0041a750` reports one code xref at `0x0041b168` in `sub_41B110`, matching `FileDownloader::OnMessage`.
- `xrefs_to 0x00453aa0` reports `0x00453a16` in `sub_453A00`, matching `MiniMapDownloader::OnThreadTask`, plus an unmodeled xref at `0x004539f4`.
- `xrefs_to 0x00454e30` reports no incoming references, so the raw helper body is supporting MiniMap-side consumer evidence, not a routable parent on its own.
- `callees` for both `sub_41A750` and `sub_453AA0` list the same WinINet/file/debug API set: `InternetOpenW`, `InternetOpenUrlW`, `InternetSetOptionW`, `HttpQueryInfoW`, `InternetQueryDataAvailable`, `InternetReadFile`, `WriteFile`, `OutputDebugStringW`, `CloseHandle`, `InternetCloseHandle`, `sub_41B9B0`, and imported file create/delete thunks.

Decompiler facts:

- `sub_41A750` opens WinINet with `szAgent`, formats a `000`/`%03d` directory from the FileDownloader request payload, formats the S3 minimap URL, downloads through WinINet, writes the local `.mnm`, and emits `Downloading : %d\n`.
- `sub_453AA0` performs the same minimap download logic for the MiniMapDownloader task block and returns a success byte.
- The two helpers are behaviorally related but sit behind different source owners: FileDownloader thread message dispatch versus MiniMapDownloader worker task dispatch.

IDA string-cache caveat:

- `find_regex` did not reliably expose the target UTF-16 block, returning only unrelated/minimap-neighbor strings. This is consistent with known IDA wide-string decoding issues in this project. The bytes and xrefs are direct evidence and are stronger than the string-cache result.

## Independent PE Scan

Read-only binary scan:

- File: `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`
- MD5: `4247e04e20b65d6414c7238aa8ff5515`
- Imagebase: `0x400000`
- Target block file offset: `0x20c1f4` in `.rdata`
- Target block size: `0xc4`

Decoded strings:

- `0x0060d7f4`: `000`
- `0x0060d7f8`: overlapping/tail `0`
- `0x0060d7fc`: `%03d`
- `0x0060d808`: `.mnm`
- `0x0060d818`: `https://s3.amazonaws.com/kru-downloads/tk/minimaps/`
- `0x0060d880`: `%s%s/%s%s`
- `0x0060d894`: `Downloading : %d\n`
- `0x0060d8b8`: successor `https://secure.kru.com/itemshop/data/itemshop.ver`

Pattern and pointer findings:

- The full `0x0060d7f4-0x0060d8b8` byte block occurs exactly once.
- The long URL, URL-format string, and progress string each occur exactly once.
- Short generic literals are not unique: `000`, `0`, `%03d`, and `.mnm` have unrelated duplicates elsewhere, so they should not drive ownership by themselves.
- Whole-file little-endian VA dword hits match IDA xrefs:
  - `0x0060d7f4`: `0x0041a796`, `0x00453ae6`
  - `0x0060d7f8`: `0x0041a7a2`, `0x00453aef`
  - `0x0060d7fc`: `0x0041a7d3`, `0x00453b13`
  - `0x0060d808`: `0x0041a7e3`, `0x00453b23`, `0x00454e70`
  - `0x0060d818`: `0x0041a7f3`, `0x00453b33`, `0x00454e7c`
  - `0x0060d880`: `0x0041a7f8`, `0x00453b38`
  - `0x0060d894`: `0x0041a989`, `0x00453cd8`, `0x00454fcd`
- No RVA-form dword hits were found for any target literal start.

## Function / Child Inventory

| Item | UID / Path | Role | Reconstructable | Owner / Emitters | Score | Decision |
| --- | --- | --- | --- | --- | --- | --- |
| Target literal block | [UID:0003FZ] `by-memory/0x0060d7f4-0x0060d8b8.MinimapDownloadWideLiterals.md` | Shared minimap download literals | TRUE | `CANONICAL_OWNER:NONE`; emitters `0000JC,0000LE` | `89/93` | Keep unchanged |
| FileDownloader consumer | [UID:0002TR] `by-memory/0x0041a750-0x0041a9fe.DownloadMinimapFile.md` | Message `10000` minimap download helper | TRUE | `0000JC` | `80/84` | Consumer evidence for emitter; A-agent can improve later |
| MiniMapDownloader consumer | [UID:0000XN] `by-memory/0x00453910-0x00453def.MiniMapDownloader.md` | MiniMap worker/downloader class and helper | TRUE | `0000LE` | `86/90` | Confirms MiniMap emitter |
| Mixed literal container | [UID:0003AL] `by-memory/0x0060d7e0-0x0060d9c0.CashShopDownloaderLiterals.md` | Split-audit container | FALSE | none | `89/92` | Do not use as owner/emitter |
| Prior literal sibling | [UID:0003FY] `by-memory/0x0060d7e0-0x0060d7f4.SharedDownloaderUserAgentWideString.md` | Pooled user-agent literal | TRUE | `NONE`; emitters `0000JC,0000LE` | `88/93` | Separate sibling, do not merge |
| Successor literal sibling | [UID:0003G0] `by-memory/0x0060d8b8-0x0060d94c.CashShopVersionDownloadWideLiterals.md` | Item-shop version/progress literals | TRUE | `0000JC` | `86/91` | Boundary confirms no widening |

## Ranked Ownership Analysis

### 1. `CANONICAL_OWNER:NONE` with emitters `0000JC,0000LE`

Evidence for:

- Every substantive target literal is referenced from both `sub_41A750` and `sub_453AA0`.
- `sub_41A750` is called by FileDownloader message dispatch at `0x0041b168` inside `sub_41B110`.
- `sub_453AA0` is called by MiniMapDownloader task dispatch at `0x00453a16` inside `sub_453A00`.
- Raw MiniMap-neighborhood refs to `.mnm`, the S3 URL, and the progress string further support MiniMap source-use.
- Both file roots clear the current 85/85 route gate: FileDownloader is `85/88`, MiniMap is `85/86`.
- No evidence proves a source-level shared declaration object.

Evidence against:

- This leaves the target with no canonical declaration owner, which is less tidy than a single-parent model.

Decision:

- Accepted. This is the most accurate current representation under the owner/emitter split.

### 2. Canonical owner `0000JC` FileDownloader

Evidence for:

- The `FileDownloader` page owns the thread-backed HTTP dispatcher and message `10000` path.
- The target block is consumed by `DownloadMinimapFile` under `FileDownloader::OnMessage`.
- Neighboring item-shop URL literals after `0x0060d8b8` are FileDownloader-owned.

Evidence against:

- The same target block is consumed by `MiniMapDownloader::OnThreadTask`.
- Raw MiniMap-side refs to `.mnm`, the S3 URL, and progress text are outside FileDownloader.
- FileDownloader is a consumer/source-use route, not a proven declaration owner for all pooled minimap literals.

Decision:

- Rejected as canonical owner. Keep as emitter `0000JC`.

### 3. Canonical owner `0000LE` MiniMap

Evidence for:

- The literals are semantically minimap download constants.
- The MiniMap file owns the MiniMapDownloader class/source family and related minimap `.rdata`.
- `sub_453AA0` and raw MiniMap-side refs are direct MiniMap evidence.

Evidence against:

- FileDownloader message `10000` independently consumes the full block.
- Assigning the block to MiniMap would hide the generic downloader-dispatch source-use path.
- The current `MiniMap.md` page itself says `DownloadMinimapFile_41A750` remains a shared FileDownloader helper unless later task-structure review proves otherwise.

Decision:

- Rejected as canonical owner. Keep as emitter `0000LE`.

### 4. New shared constants file or global declaration

Evidence for:

- A modern source tree might factor these repeated literals into a shared constant.
- The whole target block is one physical string pool group.

Evidence against:

- There is no source/debug name, global symbol, pointer object, relocation grouping, or explicit declaration artifact for a shared constants object.
- PE/IDA evidence looks like compiler/linker string pooling of literal operands, not a hand-authored table.
- A new file would create a declaration owner that is not proven and would be broader than the actual evidence.

Decision:

- Rejected. Do not create `DownloaderLiterals`, `MiniMapDownloadConstants`, or similar.

### 5. Split inside `0003FZ`

Evidence for:

- The block contains multiple strings and some strings have raw MiniMap refs while others do not.

Evidence against:

- The modeled FileDownloader and MiniMapDownloader helpers consume the full logical set.
- The subranges would retain the same owner/emitter conclusion or produce generic tiny-literal pages.
- The current split already separates the user-agent sibling, minimap block, FileDownloader-only item-shop block, shared `version` key, and catalog URL.

Decision:

- Rejected. No child split would improve ownership or source routing.

## Negative Evidence Summary

- No single file owner covers all uses without overclaiming another source family.
- No named global/static declaration points at the block.
- No source/debug path, PDB artifact, object-file marker, or dedicated constants table was found.
- Physical adjacency to FileDownloader vtable/user-agent and item-shop literals is not enough; the surrounding container is already documented as a mixed split-audit page.
- The low score of [UID:0002TR] `DownloadMinimapFile` does not invalidate the FileDownloader emitter because live IDA proves the xref and the FileDownloader file root itself clears the emitter route gate. It is a documentation-improvement follow-up, not a blocker for this literal page.

## Final Recommendation

Do not edit the target metadata. The exact final state should remain:

```text
CANONICAL_OWNER:NONE
RECONSTRUCTABLE:TRUE
EMITTER_UIDS:0000JC,0000LE
EMITTER_POSITION_OPTIONAL:
RECONSTRUCTION_CPP CODE: blank
```

No coverage-report update is required. No split, merge, reclassification, parent repair, or new child page is justified.

## Follow-Up Actions

- A-agent follow-up: improve [UID:0002TR] `DownloadMinimapFile` from `80/84` if this consumer is later needed for final-source C++ around the FileDownloader route.
- Supervisor follow-up: no action required unless you want the optional refreshed coverage row above.
- Future source reconstruction: when final C++ is written for the downloader helpers, spell these literals at the consuming FileDownloader and MiniMap source-use sites unless later evidence proves a named shared declaration.

## Confidence

- Recommendation confidence: high.
- Factual confidence: very high for bytes, range boundaries, xrefs, modeled consumers, raw MiniMap-side refs, and emitter route validity.
- Remaining uncertainty: final source-level literal pooling versus repeated literal spelling in original source. That uncertainty blocks a canonical declaration owner, not the two-emitter route.

## Validator Results

- Validator not run.
- Reason: this pass changed only an Agent-B002 research report and did not edit by-memory/by-file metadata, target docs, UID references in shared docs, or generated/coverage files.

## Changed Files

- Created: `tools/leaser/Agents/Agent-B002/research/0003FZ-MinimapDownloadWideLiterals-live-goal2-no-owner-pass.md`
- Modified: none outside the Agent-B002 research folder
- Leases used: none

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"command_id":"000000004167","details":"report marked for revalidation","event":"needs-revalidation","issue":"target_uid_unknown: 0003FZ","source_path":"executed-b-agent-research/B002/0003FZ-MinimapDownloadWideLiterals-live-goal2-no-owner-pass.md","timestamp":"2026-07-01T19:52:03-04:00"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
