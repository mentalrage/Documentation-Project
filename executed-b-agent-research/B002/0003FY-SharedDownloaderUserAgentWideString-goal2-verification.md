** TARGET-REPORT-UID:0003FY **
** AUTHOR-AGENT-ID:B002 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
** REPORT-VALIDATION-STATUS: needs-revalidation **
** REPORT-REVALIDATION-REASON: target_uid_unknown: 0003FY **
# Final Recommendation

Keep [UID:0003FY] `by-memory/0x0060d7e0-0x0060d7f4.SharedDownloaderUserAgentWideString.md` exactly as a reconstructable pooled literal with no canonical declaration owner and two proven source-use emitters:

- `CANONICAL_OWNER:NONE`
- `RECONSTRUCTABLE:TRUE`
- `EMITTER_UIDS:0000JC,0000LE`
- `EMITTER_POSITION_OPTIONAL:` blank
- `RECONSTRUCTION_CPP CODE:` blank
- Keep current score `COMPLETION:88`, `CONFIDENCE:93`.

No owner change, emitter change, split, merge, reclassification, child page, IDA repair, score change, or `by-memory/-coverage-report.md` row replacement is recommended. This is not the blank-emitter helper pattern: the no-owner state is correct because no single declaration/source owner is proven, while the two emitters are correct because FileDownloader and MiniMap are both independently proven source-use roots for the one physical `L"HTTPTEST"` user-agent literal.

The no-code state should also remain. Without a proven named shared declaration, emitting a standalone `static`/global declaration would invent source structure. Final reconstructed consumer code should spell the literal at the consuming WinINet call sites unless later source/debug evidence proves a named shared declaration.

---

## Target

- Target UID: `0003FY`
- Target page: `E:\NTK\GhidraBridge\source-3\project-documentation\by-memory\0x0060d7e0-0x0060d7f4.SharedDownloaderUserAgentWideString.md`
- Coverage source checked: `E:\NTK\GhidraBridge\source-3\project-documentation\auto-generated\-ag-memory-coverage.md`
- Shared coverage row checked but not edited: `E:\NTK\GhidraBridge\source-3\project-documentation\by-memory\-coverage-report.md`
- Prior report used only as evidence: `Agent-B001/research/executed/0003FY-SharedDownloaderUserAgentWideString-live-goal2-no-owner-pass.md`

Current generated state in `auto-generated/-ag-memory-coverage.md` is `no-owner`, owner `NONE`, emitters `0000JC`,`0000LE`, no generated code, and route path shown through `auto-generated/NexusTK/network/FileDownloader.cpp`. The generated emitter list section still records both [UID:0000JC] `FileDownloader` and [UID:0000LE] `MiniMap`.

## Current Documentation Evidence

The current target page identifies the range as:

- `0x0060d7e0-0x0060d7f2`: UTF-16LE `HTTPTEST` plus terminator.
- `0x0060d7f2-0x0060d7f4`: two zero bytes before the successor minimap literal child at `0x0060d7f4`.

The enclosing [UID:0003AL] `0x0060d7e0-0x0060d9c0.CashShopDownloaderLiterals` page is already a reviewed `RECONSTRUCTABLE:FALSE` split-audit container. Its exact child split separates:

- [UID:0003FY] this shared user-agent literal.
- [UID:0003FZ] shared minimap download literals, also no-owner with FileDownloader/MiniMap emitters.
- [UID:0003G0] FileDownloader-only item-shop version literals.
- [UID:0003G1] shared `version` JSON key.
- [UID:0003G2] FileDownloader-only catalog URL.

Current emitter root checks:

- [UID:0000JC] `by-file/FileDownloader.md` is a valid file root at `85/88`, `CANONICAL_OWNER:FILE`, `PROPOSED_RECONSTRUCTION_PATH:"NexusTK/network/"`. It documents the `FileDownloader::OnMessage` dispatch for messages `10000`, `10001`, and `10002`, with helper targets `0x0041a750`, `0x0041ae20`, and `0x0041aa00`.
- [UID:0000LE] `by-file/MiniMap.md` is a valid file root at `85/86`, `CANONICAL_OWNER:FILE`, `PROPOSED_RECONSTRUCTION_PATH:"NexusTK/map/"`. It documents the MiniMapDownloader source family, `DownloadMinimap_453AA0`, and the raw MiniMap-side helper caveat at `0x00454e30-0x00455040`.

The current `by-memory/-coverage-report.md` row already says to keep `CANONICAL_OWNER:NONE` while retaining `EMITTER_UIDS:0000JC,0000LE`; it does not need replacement.

## Current IDA MCP Evidence

Fresh live IDA MCP evidence was collected against `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe.i64` / input `NexusTK.exe`. `server_health` reported image base `0x400000`, `auto_analysis_ready:true`, `hexrays_ready:true`, and `strings_cache_ready:true`.

Bytes and string layout:

- `get_bytes 0x0060d7e0` returned `48 00 54 00 54 00 50 00 54 00 45 00 53 00 54 00 00 00 00 00 30 00 30 00 30 00 00 00 25 00 30 00`.
- The first 18 bytes decode as UTF-16LE `HTTPTEST\0`.
- The full target range is 20 bytes: `HTTPTEST\0` plus two zero padding bytes.
- IDA `get_string` reports `0x0060d7e0` as `H` and `0x0060d7e4` as `TPTEST`, matching IDA's split labels rather than a second real literal. The raw bytes prove one physical UTF-16LE user-agent literal.
- `get_string 0x0060d7f4` reports successor minimap literal head `0`; `0x0060d7fc`, `0x0060d808`, `0x0060d818`, and `0x0060d894` decode as `%03d`, `.mnm`, the S3 minimap URL prefix, and `Downloading : %d\n`.

Xrefs:

`xrefs_to 0x0060d7e0` returned exactly five data refs:

| Xref | Function context | Source-use route |
| --- | --- | --- |
| `0x0041a773` | `sub_41A750`, size `0x2ae` | FileDownloader message `10000` minimap-file helper. |
| `0x0041aa3b` | `sub_41AA00`, size `0x41c` | FileDownloader message `10002` cash-shop version helper. |
| `0x0041ae5b` | `sub_41AE20`, size `0x2ec` | FileDownloader message `10001` catalog helper. |
| `0x00453ac3` | `sub_453AA0`, size `0x2af` | MiniMapDownloader modeled minimap helper. |
| `0x00454e52` | no IDA function | Raw MiniMap-side helper body. |

Negative and boundary refs:

- `xrefs_to 0x0060d7e4`: zero refs.
- `xrefs_to 0x0060d7f2`: zero refs.
- `xrefs_to 0x0060d7f4`: two refs, `0x0041a794` in `sub_41A750` and `0x00453ae4` in `sub_453AA0`, proving `0x0060d7f4` is the next minimap literal child, not part of this user-agent item.
- `lookup_funcs 0x00454e30`, `0x00454e52`, and `0x00455040`: not functions.
- `lookup_funcs 0x00455050`: next modeled function `sub_455050`, size `0x3`.
- `xrefs_to 0x00454e30`: zero incoming refs to the raw helper start.

Instruction-site evidence:

- `disasm 0x0041a750` shows `0x0041a773: push offset szAgent; lpszAgent`, then `0x0041a77e: call ds:InternetOpenW`.
- `disasm 0x00454e30` shows a complete function-shaped raw body. At `0x00454e52` it pushes `offset szAgent`, at `0x00454e5d` it calls `InternetOpenW`, and then it pushes `.mnm` and the S3 minimap URL literals. This strengthens the MiniMap source-use route without proving a standalone owner.

Component/search evidence:

- `analyze_component` over `0x0041a750`, `0x0041aa00`, `0x0041ae20`, and `0x00453aa0` lists `0x0060d7e0` / `szAgent` as a shared global/string accessed by all four modeled downloader helpers. Its internal call graph has no edges among those four functions.
- `find_bytes` for the exact UTF-16LE `HTTPTEST\0` pattern found one match at `0x0060d7e0`.
- `find_bytes` for absolute little-endian `e0 d7 60 00` found five matches: `0x0041a774`, `0x0041aa3c`, `0x0041ae5c`, `0x00453ac4`, and `0x00454e53`.
- `find_bytes` for interior/tail absolute addresses `e4 d7 60 00` and `f2 d7 60 00` found zero matches.
- `find_bytes` for successor address `f4 d7 60 00` found two matches: `0x0041a796` and `0x00453ae6`.
- `make_signature_for_range 0x00454e30-0x00455040` produced a unique signature for the raw MiniMap-side helper.

## Independent PE Evidence

A read-only PE scan of `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe` independently confirmed:

- Image base: `0x00400000`.
- Target raw offset: `0x20c1e0`.
- Target bytes: `48 00 54 00 54 00 50 00 54 00 45 00 53 00 54 00 00 00 00 00`.
- UTF-16 decode over the literal bytes: `HTTPTEST\0`.

Raw pattern results:

- UTF-16LE `HTTPTEST\0`: one hit at VA `0x0060d7e0`.
- Full 20-byte child with padding: one hit at VA `0x0060d7e0`.
- Absolute VA bytes for `0x0060d7e0`: five hits at VAs `0x0041a774`, `0x0041aa3c`, `0x0041ae5c`, `0x00453ac4`, and `0x00454e53`.
- Absolute VA bytes for `0x0060d7e4` and `0x0060d7f2`: zero hits.
- Absolute VA bytes for successor `0x0060d7f4`: two hits at `0x0041a796` and `0x00453ae6`.
- RVA-form refs for `0x0020d7e0`, `0x0020d7e4`, `0x0020d7f2`, and `0x0020d7f4`: zero hits.

This independently matches the IDA xref story.

## Owner And Emitter Analysis

### Accepted: `CANONICAL_OWNER:NONE`, `EMITTER_UIDS:0000JC,0000LE`

Evidence for no canonical owner:

- There is one physical literal used by two independent source families.
- No named shared declaration, global object, constants table, source/debug symbol, initializer, or address-taken data object is proven.
- Assigning FileDownloader would overclaim the MiniMapDownloader and raw MiniMap-side uses.
- Assigning MiniMap would overclaim the three FileDownloader helper uses.
- The enclosing literal pool is a non-emitting split-audit container, not a source declaration owner.

Evidence for FileDownloader emitter `0000JC`:

- Three modeled FileDownloader helper functions directly push `szAgent` before `InternetOpenW`: `sub_41A750`, `sub_41AA00`, and `sub_41AE20`.
- [UID:0000JC] `FileDownloader` is a valid file root and documents those helper families under `NexusTK/network/`.
- [UID:00004W] `FileDownloader` class is parented/emitted through [UID:0000JC] and documents the `OnMessage` dispatch to message IDs `10000`, `10001`, and `10002`.

Evidence for MiniMap emitter `0000LE`:

- The modeled MiniMapDownloader helper `sub_453AA0` directly pushes `szAgent` before `InternetOpenW`.
- The raw MiniMap-side helper at `0x00454e30-0x00455040` also pushes `szAgent`, then uses minimap `.mnm` and S3 URL literals.
- [UID:0000LE] `MiniMap` is a valid file root and currently owns the MiniMapDownloader and MiniMap renderer/control aggregate pages.

Decision: accepted. This is the current by-structure pooled-literal case: no single canonical owner, but multiple proven source-use emitters.

### Rejected: canonical owner [UID:0000JC] `FileDownloader`

Evidence for:

- It has the majority of direct refs, three of five.
- The literal physically follows FileDownloader vtable data at `0x0060d7a4-0x0060d7e0`.

Evidence against:

- It does not cover the MiniMapDownloader ref at `0x00453ac3`.
- It does not cover the raw MiniMap-side helper ref at `0x00454e52`.
- Address adjacency is weaker than cross-source xref distribution for pooled literals.

Decision: reject as canonical owner; retain as emitter.

### Rejected: canonical owner [UID:0000LE] `MiniMap`

Evidence for:

- Both MiniMapDownloader and the raw MiniMap-side helper use the literal.
- The successor minimap literal group follows at `0x0060d7f4` and uses the same FileDownloader/MiniMap source-use pattern.

Evidence against:

- Three direct refs are FileDownloader-dispatched helpers, including item-shop version/catalog helpers that are not MiniMap-owned.

Decision: reject as canonical owner; retain as emitter.

### Rejected: new shared constants/global owner

Evidence for:

- The one physical literal is shared.

Evidence against:

- No source-facing constants module, named global declaration, or table object is proven.
- Current `by-structure.md` says not to invent a standalone global/helper file solely to avoid `NONE` for pooled literals.
- Reconstructing this as a named global would imply declaration ownership that the binary does not show.

Decision: reject.

### Rejected: split/reclassification/IDA repair

Evidence for considering:

- IDA splits labels as `szAgent` at `0x0060d7e0` and `aTptest` at `0x0060d7e4`.
- The raw helper at `0x00454e30` is function-shaped but not modeled.

Evidence against:

- Raw bytes prove one UTF-16LE `HTTPTEST\0` literal, not two source literals.
- There are zero refs to `0x0060d7e4` and zero refs to the tail at `0x0060d7f2`.
- The successor literal at `0x0060d7f4` is already a separate child and has its own refs.
- Creating an IDA function at `0x00454e30` would not change literal ownership; the raw body has no incoming refs to its start.

Decision: no split, reclassification, child creation, or IDA repair is required for this verification.

## Why No Reconstruction C++ Remains Correct

This page represents literal bytes, not a proven source declaration. It has emitters because the source-use contexts are proven, but there is no evidence that the original source had a named `static const wchar_t[]`, global, or shared constants object. A generated standalone declaration would invent structure and risk producing a source form that did not exist.

The correct current documentation model is:

- Keep the literal page reconstructable and routed through both source-use roots.
- Keep the literal page's C++ block blank.
- Let final emitted consumer functions spell `L"HTTPTEST"` at the WinINet `InternetOpenW` call sites unless future evidence proves a named shared declaration.

## Exact Recommended Changes

No documentation or coverage edits are recommended.

- Target page: no change.
- `by-memory/-coverage-report.md`: no change; no replacement row.
- `auto-generated/-ag-memory-coverage.md`: read-only generated input; no direct edit.
- Owner: keep `NONE`.
- Emitters: keep `0000JC,0000LE`.
- New child pages: none.
- Reconstruction C++: keep blank.

## Validation And Execution Notes

- Used current `goal.md`, `Supervisor.md`, `by-structure.md`, tracker context, target page, generated coverage, shared coverage row, enclosing/sibling memory pages, and candidate emitter/owner docs as current documentation evidence.
- Used fresh live IDA MCP for bytes, strings, xrefs, function lookup, disassembly, component analysis, byte-pattern search, and raw-helper signature evidence.
- Used an independent read-only PE scan for literal uniqueness and absolute/RVA pointer evidence.
- Used the prior executed report only as evidence and a checklist, not as the conclusion.
- No dry runs were used.
- No validator run was needed because no by-* documentation, coverage report, or generated/project state was modified.
- No lease was needed because the only file created is inside the Agent-B002 research folder.

## Confidence

Recommendation confidence: high, `94`.

The evidence is very strong for one physical pooled `L"HTTPTEST"` literal, five direct source-use refs, exactly two valid file-root emitters, and no single declaration owner. Confidence stops below final-audit range because the stripped binary cannot prove whether the original source used repeated literal spelling, a macro, a local constant, or a private shared declaration that was later pooled.

## Changed Files

- Created `E:\NTK\GhidraBridge\source-3\project-documentation\tools\leaser\Agents\Agent-B002\research\0003FY-SharedDownloaderUserAgentWideString-goal2-verification.md`

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"command_id":"000000004167","details":"report marked for revalidation","event":"needs-revalidation","issue":"target_uid_unknown: 0003FY","source_path":"executed-b-agent-research/B002/0003FY-SharedDownloaderUserAgentWideString-goal2-verification.md","timestamp":"2026-07-01T19:52:03-04:00"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
