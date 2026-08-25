** TARGET-REPORT-UID:0004D5 **
** AUTHOR-AGENT-ID:B008 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | Medium **
# 0004D5 StartupNoticeDrawPcxImage Source-Quality Research


## Finalized Report / Current Recommendation
- Implemented recommendation: UID0004D5 has been promoted from the earlier family-split baseline to a direct source-quality target at `COMPLETION:89`, `CONFIDENCE:91`.
- Final disposition: keep `CANONICAL_OWNER:0000O5`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000O5`, and blank `EMITTER_POSITION_OPTIONAL`; the target evidence and formal C++ now describe a StartupWindow-local `DIBitmap` draw helper.
- Applied action: B008 replaced the stale `PcxImage *` formal body with the exact formal block in this report, preserved the StartupWindow source route, documented current MCP session `ddf5b602`, and synced target-relevant support notes where stale.
- Confidence: high for range, behavior, callsites, ownership, and source route; capped below final audit by the absence of IDB UDT records and by inferred source-facing helper/member spellings.

## Supporting Research
- Historical assignment state: B008 first produced this as report-only research for UID0004D5. Current callback state: supervisor Gate 1 passed, B008 completed the implementation callback, accepted target/support by-* changes were applied, scoped validators ran, and B008 did not manually edit generated files, coverage reports, validator state, lifecycle/archive state, or supervisor ledgers.
- Historical MCP incident context: an earlier attempt found the listener reachable but `idb_list` returned zero sessions. This final report does not rely on that fallback state; all binary claims below were refreshed against supervisor-verified session `ddf5b602`.
- Direct-report gap: `rg` over active Agent research folders and `executed-b-agent-research` found no prior direct UID0004D5 report. The target exists because B008's executed `0000O5-StartupWindow-empty-emitter-family-source-quality.md` created it during a family split, and B010's executed `0001IO-StartupWindowUpdateCheck-source-quality.md` inventoried it as a draw helper. This report is the first direct UID0004D5 source-quality artifact.
- Existing useful leads: the older B008 family report created the child at `86/88` with a `PcxImage *` formal body; B010 identified the best source name `StartupNoticeDrawPcxImage`; current by-file/class/aggregate docs already route StartupWindow notice orchestration through UID0000O5 and keep PCX decoding in ImageLoaders.

## Target
- Target UID: `0004D5`.
- Target path: `by-memory/0x00581dc0-0x00581e35.StartupNoticeDrawPcxImage.md`.
- Source queue/report row at assignment time: `auto-generated/-ag-research-tracker.md` -> `## by-memory` -> not-covered reconstructable row for UID0004D5, then `86/88`, average `87.0`, reconstructable `true`.
- Current supervisor classification: accepted direct by-memory source-quality report with implementation callback completed by B008.
- Current scores and parent state after callback: target metadata is `COMPLETION:89`, `CONFIDENCE:91`, `CANONICAL_OWNER:0000O5`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000O5`, blank emitter position.

## Current Target State
- Pre-callback metadata was `86/88`, owner/emitter `0000O5`, reconstructable true. Post-callback metadata is `89/91`, owner/emitter `0000O5`, reconstructable true.
- Owner/emitter/reconstructable state remained correct and unchanged. StartupWindow owns notice-specific paint orchestration; ImageLoaders owns `LoadPcxImage` and PCX decode/DIB construction.
- Pre-callback C++/emitter state generated UID0004D5 as `static void StartupNoticeDrawPcxImage(HDC targetDc, PcxImage *image, int x, int y)`. Post-callback generated `auto-generated/NexusTK/app/StartupWindow.cpp` refreshed through deferred validator-owned command `000000006519` and emits UID0004D5 at `89/91` as `static void StartupNoticeDrawPcxImage(HDC targetDc, DIBitmap *image, int x, int y)`.
- Pre-callback blockers were the thin evidence section, stale `PcxImage *`, and absent citation of current session `ddf5b602`, exact bytes, instruction count, xrefs, boundary padding, DIBitmap accessor identities, no local UDT evidence, and `void` versus IDA `BOOL` rationale. These facts are now incorporated into the target/support docs; the remaining original-name/type spelling uncertainty is a confidence cap only.
- Related target/support docs checked: target page; `by-memory/0x00581100-0x005815aa.StartupWindowUpdateCheckWindowProc.md`; `by-memory/0x005818d0-0x005819cc.StartupNoticeLoadAssets.md`; `by-file/StartupWindow.md`; `by-class/StartupWindow.md`; `by-memory/0x005807d0-0x0058206e.StartupWindowUpdateCheck.md`; `by-item/StartupWindowUnmodeledNoticeHelpers_5815b0_581b7f.md`; `by-resource/startup-update-notice-resources.md`; `by-file/ImageLoaders.md`; `by-file/DIBitmap.md`; `by-class/DIBitmap.md`; `by-memory/0x004a17b0-0x004a18a8.LoadPcxImage.md`; generated `auto-generated/NexusTK/app/StartupWindow.cpp`; generated `-ag-*` tracker/coverage rows; matching active/executed B-agent reports.
- Current artifact/lifecycle status: this artifact records B008's completed implementation callback and scoped validator results. Supervisor-owned report execution remains outside B008 scope; B008 did not run `execute_report` or any lifecycle/archive command.

## Heuristic / Inference Reanalysis And Validation
- Helper source name: `StartupNoticeDrawPcxImage` remains the best source-facing name. Direct facts are `sub_581DC0`, exact WndProc paint callsites, GDI bitmap/DC calls, and StartupWindow notice asset context. The source-facing name is inferred/descriptive, not an IDB symbol.
- Argument type: `PcxImage *` is stale. `LoadPcxImage` returns `DIBitmap *` in current ImageLoaders docs, and DIBitmap docs identify `0x004a1770` as the bitmap handle accessor, `0x004a1780` as guarded width, and `0x004a1790` as guarded height. Current MCP `type_query` found no `DIBitmap`, `Pcx`, or `StartupWindow` UDT names in the IDB, so the type is documentation/source-facing, but `DIBitmap *` is the best supported source type.
- Return type: current MCP decompile infers `BOOL __cdecl` because the final `DeleteDC` call leaves a value in `EAX`. Both direct WndProc callsites ignore the return value, and returning `DeleteDC` would report cleanup success rather than draw success. A human-written file-local paint helper is more plausibly `void` with `DeleteDC(imageDc);` as the final cleanup statement. This keeps the existing source-facing `void` return and documents the IDA `BOOL` inference as a confidence cap, not a required source change.
- HDC/source-bitmap flow: the target creates a compatible memory DC from the destination HDC, checks the source image pointer and bitmap handle, obtains width and height from DIBitmap accessors, fetches the bitmap handle again, selects it into the compatible DC, calls `BitBlt(targetDc, x, y, width, height, imageDc, 0, 0, SRCCOPY)`, then selects NULL and deletes the compatible DC.
- Clipping and coordinate semantics: no clipping, masking, alpha, transparency, source offset, or stretch logic appears in UID0004D5. The passed `x`/`y` are direct destination coordinates, source origin is always `(0, 0)`, dimensions come from DIBitmap requested width/height, and ROP is `0x00CC0020` / `SRCCOPY`.
- Caller set: direct xrefs to UID0004D5 are only WndProc paint-path calls at `0x00581306` and `0x00581337`. The loader path is upstream data flow, not a direct UID0004D5 caller: `LoadPcxImage` has six modeled WndProc refs and six raw UID0004D1 refs, producing DIBitmap objects consumed by this draw helper.
- WndProc support caveat: generated/high-level WndProc text currently presents a background draw plus a two-button loop. Current MCP proves two static draw-helper callsites: background at `0x00581306` and one loop-body call instruction at `0x00581337`; runtime iteration/source-shape cleanup belongs to the WndProc page, while UID0004D5 should only claim the two static refs and the target helper behavior.
- Rejected alternatives: not ImageLoaders ownership, not DIBitmap ownership, not a generic PCX decoder/loader, not raw padding or a range extension, not the broad StartupWindow aggregate body, not an unmodeled helper tracker emitter, and not an IDA DB rename/type-edit task in this pass.

## Evidence Standards Used
- IDA MCP direct facts: `idb_list`, `server_health`, `lookup_funcs`, `get_bytes`, `xrefs_to`, `func_profile`, `decompile`, `type_query`, and bounded `insn_query` under session `ddf5b602`.
- Binary evidence strength: exact target range, exact byte sequence, 46 instructions, 4 basic blocks, two direct xrefs from the same WndProc function, import refs, helper accessor refs, and exact predecessor/successor padding.
- Documentation evidence: current target/support by-* docs, current generated C++ output, generated tracker/coverage rows, and matching executed B reports were used as leads and checked against current MCP evidence.
- Confidence limits: no IDB UDT records for `DIBitmap`, `Pcx`, or `StartupWindow`; final original spelling for the helper, DIBitmap accessors, and StartupWindow fields is inferred from docs and behavior rather than PDB/type proof.

## Evidence Checked
- IDA MCP checks performed: `initialize` and `tools/list` succeeded for streamable MCP client session `762143c9-4e1a-462f-b41b-9b8f137d9fc6`; `idb_list` call id `13` returned active NexusTK IDB session `ddf5b602`; `server_health` call id `14` returned `status:"ok"`, auto-analysis ready, Hex-Rays ready, and strings cache ready.
- Target MCP checks: `lookup_funcs` call id `15`; `get_bytes` call id `17`; `xrefs_to` call id `18`; `func_profile` call id `19`; `decompile` call id `20`; bounded target `insn_query` call id `32`.
- Caller/support MCP checks: WndProc `decompile` call id `21`; DIBitmap accessor `lookup_funcs` call id `22`; `type_query` call id `23`; accessor decompiles call ids `24` through `26`; `xrefs_to` for `LoadPcxImage` and accessors call id `27`; bounded WndProc callsite `insn_query` call id `31`.
- by-* docs, support docs, old reports, generated reports, and trackers checked: target page, StartupWindow file/class/WndProc/aggregate/helper tracker/resource pages, ImageLoaders, DIBitmap file/class/LoadPcxImage, generated `StartupWindow.cpp`, generated research tracker/memory coverage/by-memory coverage, active B004 UID0004D1 report, executed B008 `0000O5`, executed B010 `0001IO`, and executed B009 ImageLoaders report.
- Negative checks performed: xrefs to `0x00581e35` and `0x00581db2` returned zero; `lookup_funcs` for padding endpoints returned not functions; type catalog queries for `*DIBitmap*`, `*Pcx*`, and `*StartupWindow*` returned zero IDB type records; ownership candidates outside StartupWindow were checked and rejected through dependency direction.
- Failed or intentionally skipped checks: an initial local PowerShell JSON helper serialized MCP arguments incorrectly for call ids `10` through `12`; corrected calls immediately succeeded. A schema-focused `tools/list` retry timed out once and was replaced by narrower evidence calls plus a later successful selected schema read. No broad/unbounded list, search, callgraph, or batch-analysis call was used for evidence.

## Claim And Incorporation Ledger
| Claim ID | Claim | Confidence | Evidence | Destination doc/section | Action | Verification state |
| --- | --- | --- | --- | --- | --- | --- |
| C-0004D5-01 | UID0004D5 should cite current MCP session `ddf5b602`, not only older B008/B010 split evidence. | High | `idb_list` id `13`; `server_health` id `14`. | Target `Evidence` / `Changes`; support `by-file`, `by-class`, aggregate, and WndProc notes cite `ddf5b602`. | incorporate | applied |
| C-0004D5-02 | Exact modeled function remains `0x00581dc0-0x00581e35`, `sub_581DC0`, size `0x75` / 117 bytes, 46 instructions, 4 blocks. | High | `lookup_funcs` id `15`; `func_profile` id `19`; `int_convert.py` verified `0x75` -> 117. | Target `Status`/`Evidence`; aggregate child row; file/class support rows. | incorporate | applied |
| C-0004D5-03 | Exact bytes are the 117-byte body beginning `55 8b ec 53 56 ...` and ending `5e 5b 5d c3`. | High | `get_bytes` id `17`; target `insn_query` id `32`. | Target `Evidence` records beginning/end byte proof. | incorporate | applied |
| C-0004D5-04 | Boundary padding is exact: `0x00581db2-0x00581dc0` fourteen `0xcc` bytes and `0x00581e35-0x00581e40` eleven `0xcc` bytes. | High | `get_bytes` id `17`; `lookup_funcs` id `15`; `int_convert.py` verified `0xe` -> 14 and `0xb` -> 11. | Target `Evidence`; aggregate child row and changes note. | incorporate | applied |
| C-0004D5-05 | Direct UID0004D5 xrefs are only WndProc paint callsites `0x00581306` and `0x00581337`. | High | `xrefs_to 0x00581dc0` id `18`; WndProc `decompile` id `21`; callsite `insn_query` id `31`. | Target caller evidence; WndProc support note; aggregate behavior summary; file/class support notes. | incorporate | applied |
| C-0004D5-06 | Helper creates compatible DC, guards image pointer/bitmap handle, calls DIBitmap width/height/bitmap accessors, selects bitmap, BitBlt's with `SRCCOPY`, selects NULL, and deletes DC. | High | `decompile` id `20`; target `insn_query` id `32`; accessor decompiles ids `24`-`26`. | Target formal C++ and evidence; generated `StartupWindow.cpp` UID0004D5 block refreshed at validator-owned generated command `000000006519`. | incorporate | applied |
| C-0004D5-07 | Source image argument should be `DIBitmap *`, not stale `PcxImage *`. | Medium-high | `LoadPcxImage` doc returns `DIBitmap *`; DIBitmap docs identify accessors; MCP `type_query` id `23` found no competing IDB `Pcx` type. | Target formal C++ and evidence; file/class/aggregate support notes; generated `StartupWindow.cpp` line 481 shows `DIBitmap *image`. | incorporate | applied |
| C-0004D5-08 | Keep source-facing return `void`; IDA `BOOL` decompile is a cleanup-return artifact because callers ignore the value and the final call is `DeleteDC`, not draw-result propagation. | Medium-high | `decompile` id `20`; `xrefs_to` id `18`; callsite `insn_query` id `31`. | Target formal C++ and evidence; class/aggregate notes record `void` confidence cap. | incorporate | applied |
| C-0004D5-09 | No clipping/transparent blit/stretched draw logic exists in UID0004D5; coordinates pass directly to destination x/y and source origin is `(0,0)`. | High | `decompile` id `20`; `insn_query` id `32` pushes `0`, `0`, `SRCCOPY`, width, height, x, y, target HDC. | Target evidence; WndProc, file, class, and aggregate support notes. | incorporate | applied |
| C-0004D5-10 | StartupWindow remains the owner/emitter; ImageLoaders/DIBitmap are dependencies only. | High | WndProc callers, StartupWindow support docs, ImageLoaders/DIBitmap docs, `LoadPcxImage` xrefs id `27`. | Target metadata unchanged; target/support docs state StartupWindow ownership and dependency-only ImageLoaders/DIBitmap roles. | incorporate | applied |
| C-0004D5-11 | Generated `StartupWindow.cpp` was coded but stale at `86/88` and used `PcxImage *`; validator-owned generated output should refresh after implementation. | High | generated `StartupWindow.cpp` lines around UID0004D5; generated tracker/memory coverage rows. | Validator-owned generated command `000000006519` refreshed `auto-generated/NexusTK/app/StartupWindow.cpp`; UID0004D5 now shows `Completion:89 | Confidence:91` and `DIBitmap *image`. | incorporate | applied |
| C-0004D5-12 | Reject range extension/padding/raw-helper/no-owner/generic decoder alternatives. | High | Padding/xref facts; ownership/source route docs; target GDI draw behavior. | Target evidence/rejected alternatives; file/class/aggregate support notes preserve dependency and ownership boundaries. | incorporate | applied |

## Positive Evidence Summary
- Direct target facts: current MCP resolves `0x00581dc0` as `sub_581DC0`, size `0x75`, with a full 46-instruction draw helper, exact bytes, and exact cleanup tail.
- Caller facts: `xrefs_to 0x00581dc0` returns two code refs, both inside `sub_581100` WndProc. The first pushes background image at `this+0x10` with x/y zero; the second is the loop-body call that selects a state-dependent notice-button image pointer and pushes row x/y fields.
- Data-flow facts: WndProc first-paint logic loads six `brm_*.pcx` assets through `sub_4A17B0` / source-facing `LoadPcxImage`, stores DIBitmap pointers, computes button rectangles through width/height accessors, and then draws through UID0004D5.
- Dependency facts: DIBitmap docs and current accessor decompiles match target behavior: `0x004a1770` returns `this[11]` / HBITMAP, `0x004a1780` returns guarded width, and `0x004a1790` returns guarded height.
- Generated/source-route evidence: generated `StartupWindow.cpp` already emits a UID0004D5 body through UID0000O5, proving the emitter route is live; this pass improves its source-quality type/order/evidence rather than creating a new route.

## IDA MCP Facts
- Function/range facts: `lookup_funcs` id `15` reports `0x00581dc0 -> sub_581DC0`, size `0x75`; `0x00581e35` and `0x00581db2` are not functions; successor `0x00581e40 -> sub_581E40`, size `0x106`; WndProc `0x00581100 -> sub_581100`, size `0x4aa`; `0x005818d0` is not a function; `0x004a17b0 -> sub_4A17B0`, size `0xf8`.
- Target bytes: `55 8b ec 53 56 ff 75 08 ff 15 2c d0 60 00 8b 75 0c 8b d8 85 f6 74 4a 8b ce e8 92 f9 f1 ff 85 c0 74 3f 57 8b ce e8 96 f9 f1 ff 8b ce 8b f8 e8 9d f9 f1 ff 8b 4d 0c 8b f0 e8 73 f9 f1 ff 50 53 ff 15 4c d0 60 00 68 20 00 cc 00 6a 00 6a 00 53 56 57 ff 75 14 ff 75 10 ff 75 08 ff 15 44 d0 60 00 5f 6a 00 53 ff 15 4c d0 60 00 53 ff 15 48 d0 60 00 5e 5b 5d c3`.
- Data/table/padding facts: `0x00581db2-0x00581dc0` is fourteen `0xcc` bytes; `0x00581e35-0x00581e40` is eleven `0xcc` bytes; neither padding endpoint has xrefs.
- Xref facts: `xrefs_to 0x00581dc0` id `18` reports two refs: `0x00581306` and `0x00581337`, both in `sub_581100`. `xrefs_to 0x004a17b0` id `27` reports twelve refs: six modeled WndProc PCX-loader refs at `0x00581227`, `0x00581237`, `0x00581246`, `0x00581256`, `0x005812a3`, `0x005812ba`, and six raw UID0004D1 refs at `0x005818f1`, `0x00581901`, `0x00581911`, `0x00581921`, `0x0058196d`, `0x00581984`.
- Callee/import facts: target decompile references `CreateCompatibleDC` at `0x0060d02c`, `SelectObject` at `0x0060d04c`, `BitBlt` at `0x0060d044`, `DeleteDC` at `0x0060d048`, and DIBitmap accessor helpers `0x004a1770`, `0x004a1780`, and `0x004a1790`.
- Type facts: `type_query` id `23` returned zero IDB type records for `*DIBitmap*`, `*Pcx*`, and `*StartupWindow*`; source-facing types remain documentation-backed inferences.
- Negative IDA facts: no direct refs to padding endpoints, no IDB UDT proof for final helper argument type, no target-local string refs, and no extra direct callers beyond WndProc.

## Function / Child Inventory
| Range / Item | UID / Path | Role | Reconstructable | Direct Parent | Score | Status |
| --- | --- | --- | --- | --- | --- | --- |
| `0x00581100-0x005815aa` | [UID:0004CT][StartupWindowUpdateCheckWindowProc](by-memory/0x00581100-0x005815aa.StartupWindowUpdateCheckWindowProc.md) | WndProc caller/paint orchestration | TRUE | `0000O5` | currently source-ready | Support caller context; not the target body. |
| `0x005818d0-0x005819cc` | [UID:0004D1][StartupNoticeLoadAssets](by-memory/0x005818d0-0x005819cc.StartupNoticeLoadAssets.md) | Raw lazy PCX asset loader/button init | TRUE | `0000O5` | `88/91` | Upstream asset producer, not a UID0004D5 caller. |
| `0x00581db2-0x00581dc0` | padding | destructor-to-draw alignment | FALSE | none | ignored | Fourteen `0xcc` bytes. |
| `0x00581dc0-0x00581e35` | [UID:0004D5][StartupNoticeDrawPcxImage](by-memory/0x00581dc0-0x00581e35.StartupNoticeDrawPcxImage.md) | StartupWindow-local GDI draw helper | TRUE | `0000O5` | recommend `89/91` | This target. |
| `0x00581e35-0x00581e40` | padding | draw-to-find alignment | FALSE | none | ignored | Eleven `0xcc` bytes. |
| `0x00581e40-0x00581f46` | [UID:0004D6][AnsiSmallStringFindFrom](by-memory/0x00581e40-0x00581f46.AnsiSmallStringFindFrom.md) | successor string helper | TRUE | `0000O5` | `86/88` | Boundary successor only. |
| `0x004a1770/1780/1790` | [UID:000136][DIBitmapDestructorAndAccessors](by-memory/0x004a1740-0x004a17ad.DIBitmapDestructorAndAccessors.md) support cluster | DIBitmap bitmap handle/width/height accessors | TRUE support | DIBitmap/ImageLoaders relationship | support | Dependency, not UID0004D5 owner. |

## Direct Xref / Caller Inventory
| Address / Item | Xref / Caller / Callee | Meaning |
| --- | --- | --- |
| `0x00581306` | WndProc code ref to `sub_581DC0` | Paint path draws `this+0x10` background image at destination `(0,0)`. |
| `0x00581337` | WndProc code ref to `sub_581DC0` | Paint loop body draws a state-selected notice-button DIBitmap at row x/y fields. |
| `0x00581dd9` and `0x00581df8` | UID0004D5 refs to `0x004a1770` | Checks and then fetches HBITMAP handle. |
| `0x00581de5` | UID0004D5 ref to `0x004a1780` | Gets guarded requested width. |
| `0x00581dee` | UID0004D5 ref to `0x004a1790` | Gets guarded requested height. |
| `0x00581dc8` | `CreateCompatibleDC` | Creates memory DC from target HDC. |
| `0x00581dff` and `0x00581e24` | `SelectObject` | Selects bitmap, then selects NULL before cleanup. |
| `0x00581e1a` | `BitBlt` | Copies full DIBitmap image with source origin `(0,0)` and `SRCCOPY`. |
| `0x00581e2b` | `DeleteDC` | Deletes compatible DC; return value is ignored by callers. |

## Documentation Evidence And IDA Status
- Existing docs that support the conclusion: StartupWindow file/class docs already treat notice paint/loading/helpers as StartupWindow-owned and keep ImageLoaders as PCX decoding owner. DIBitmap docs identify the exact accessors consumed by UID0004D5. ImageLoaders docs identify `LoadPcxImage` as returning `DIBitmap *`.
- Pre-callback docs that were stale, incomplete, or contradicted: UID0004D5 target evidence was thin and not current-MCP-backed; target formal C++ used `PcxImage *`; generated `StartupWindow.cpp` carried the same stale `PcxImage *` target body at `86/88`. Callback result: target/support docs and validator-owned generated output now incorporate the refreshed `DIBitmap *` type/order/evidence. WndProc high-level C++ should still not be used to claim more than two static UID0004D5 callsite instructions without a separate WndProc pass.
- Pre-callback generated/coverage report state: `auto-generated/-ag-research-tracker.md` listed UID0004D5 at `86/88`; `auto-generated/-ag-memory-coverage.md` marked it coded, owner/emitter `0000O5`, generated file `auto-generated/NexusTK/app/StartupWindow.cpp`; generated C++ emitted UID0004D5 but had not incorporated this report's refreshed type/order/evidence. Post-callback generated freshness is recorded under `Validator Results`.

## Ranked Ownership Analysis

### 1. StartupWindow / UID0000O5
- Evidence for: both direct target xrefs are from StartupWindow WndProc paint handling; target consumes StartupWindow-loaded notice image pointers and WndProc destination HDC/coordinates; current target already emits through `StartupWindow.cpp`; support docs place notice UI orchestration in StartupWindow.
- Evidence against: target depends on DIBitmap and GDI/ImageLoaders helpers, and exact helper spelling is inferred.
- Decision: retain as canonical owner and emitter.

### 2. ImageLoaders / UID0000K3
- Evidence for: `LoadPcxImage` creates the DIBitmap objects consumed by UID0004D5, and ImageLoaders owns PCX load/decode/DIB factory code.
- Evidence against: UID0004D5 does not decode or load PCX files. It only performs StartupWindow-specific paint orchestration after assets are already loaded; all direct callers are StartupWindow WndProc callsites.
- Decision: dependency only; reject as owner/emitter.

### 3. DIBitmap / UID00003V or UID0000IV
- Evidence for: UID0004D5 consumes DIBitmap accessors and an HBITMAP handle.
- Evidence against: the target is not a DIBitmap method; receiver is not a DIBitmap `this`; it creates a transient compatible DC around a caller-provided destination HDC and caller-provided coordinates. DIBitmap owns bitmap storage/accessors, not this StartupWindow paint helper.
- Decision: dependency/type support only; reject as owner/emitter.

### 4. Broad StartupWindow aggregate or unmodeled helper tracker
- Evidence for: the helper lives in the broader `0x005807d0-0x0058206e` StartupWindow update-check neighborhood and was created by a family split.
- Evidence against: exact child page exists, direct range is modeled and source-bearing, and parent/tracker pages should not duplicate child C++.
- Decision: keep support/index role only; exact child remains the emitter.

### Proposed new file/grouping, if applicable
- Proposed owner/name/path: no new file. Continue emitting through [UID:0000O5][StartupWindow](by-file/StartupWindow.md), generated path `NexusTK/app/StartupWindow.cpp`.
- Likely full contents: unchanged StartupWindow notice/update helpers and class methods; UID0004D5 is one file-local static draw helper among the notice helpers.
- Candidate related items that belong: WndProc, notice asset loader, button hit/set/reset/invalidation helpers, notice window setup, startup update string/curl helpers as already documented.
- Candidate related items rejected: ImageLoaders PCX loader/factory/decoder and DIBitmap class/accessors remain in their own owners.
- Standalone, narrow, or broad source-file inference: narrow file-local helper inside existing StartupWindow source file.

## Source Placement
- Recommended source file/class/global/module placement: `NexusTK/app/StartupWindow.cpp`, file-local static helper.
- Why this placement fits source-tree and subsystem context: direct callers are StartupWindow WndProc paint paths; helper uses StartupWindow notice assets, rectangles, and paint HDC; generated output already routes through StartupWindow.
- Rejected placements and why: not `render/ImageLoaders.cpp` because no decode/load policy; not `render/DIBitmap.cpp` because not a DIBitmap method; not a separate PCX drawing module because direct use is only StartupWindow notice paint; not broad aggregate/parent because exact child owns the function body.
- Remaining placement uncertainty: exact original helper name and exact local parameter names are inferred; this caps confidence but does not block source emission.

## Range / Split / Padding / Reclassification Analysis
- Exact range/boundary facts: half-open target is `0x00581dc0-0x00581e35`; predecessor `0x00581db2-0x00581dc0` is fourteen `0xcc` bytes; successor `0x00581e35-0x00581e40` is eleven `0xcc` bytes.
- Children/subranges to create, repair, merge, leave ignored, or leave no-owner: no new children needed; keep padding ignored/non-emitting; keep successor UID0004D6 separate.
- Padding/table/data/code distinctions: target bytes are executable prologue/body/tail; adjacent bytes are alignment padding; no data table or mixed owner inside target range.
- Parent/container impact: aggregate/support child rows were updated so UID0004D5 carries direct B008 coverage at `89/91`; parent aggregate remains non-duplicating context.

## Negative Evidence Summary
- Not padding: modeled function, 46 instructions, decompiles, two direct callers, GDI/import and DIBitmap accessor calls.
- Not a range extension: both sides are `0xcc` alignment and the successor at `0x00581e40` is a separate string helper.
- Not ImageLoaders ownership: target consumes a DIBitmap pointer but does not perform PCX path lookup, DAT/file-buffer access, PCX decode, DIB section construction, or resource packaging.
- Not DIBitmap ownership: target is a free/static paint helper over caller-provided HDC/coordinates and does not use a DIBitmap `this` receiver as the function receiver.
- Not generic GDI helper: all direct callers are StartupWindow notice WndProc callsites and the image pointers come from StartupWindow notice assets.
- Not source-proof for IDA DB type names: `type_query` found no `DIBitmap`, `Pcx`, or `StartupWindow` UDT records; source-facing names should be documented as inferred/descriptive.
- Not proof that the helper returns draw success: `BitBlt` result is not captured, and the only return-like value is `DeleteDC` in `EAX` after cleanup. Callers ignore it.

## IDA Rename / Type / Comment Recommendations
- Proposed source-facing names/types/comments: keep documentation/source-facing helper name `StartupNoticeDrawPcxImage`; use `DIBitmap *image`, `HDC targetDc`, `HDC imageDc`, `HBITMAP bitmap`, `width`, and `height` in formal C++.
- Evidence for each proposed name/type/comment: StartupWindow paint caller context, current DIBitmap accessor docs, `LoadPcxImage` return type, GDI import usage, direct xrefs.
- Items intentionally left unchanged and why: no IDA DB rename/type/comment edit requested. Current IDB names remain `sub_581DC0`, `sub_4A1770`, `sub_4A1780`, and `sub_4A1790`; documentation source-facing names are sufficient for this report.
- Whether IDA DB edits are safe, unsafe, or not requested: not requested. This B008 callback was documentation-only, and no IDB writes were allowed or performed.

## First-Draft C++ Recommendation
- Eligible for draft C++: yes. The target is reconstructable, has a valid owner/emitter route, clears the combined-score gate, has exact range/padding/caller/callee evidence, and the source role is narrow and well constrained.
- Recommended code: exact formal `RECONSTRUCTION_CPP CODE` header/block insertion text:

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
static void StartupNoticeDrawPcxImage(HDC targetDc, DIBitmap *image, int x, int y)
{
    HDC imageDc = CreateCompatibleDC(targetDc);
    if (image != NULL && image->GetBitmapHandle() != NULL) {
        int width = image->GetWidth();
        int height = image->GetHeight();
        HBITMAP bitmap = image->GetBitmapHandle();

        SelectObject(imageDc, bitmap);
        BitBlt(targetDc, x, y, width, height, imageDc, 0, 0, SRCCOPY);
    }

    SelectObject(imageDc, NULL);
    DeleteDC(imageDc);
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

- Reason it preserves exact original behavior: the code preserves target HDC input, source image pointer guard, bitmap handle guard, width/height/bitmap accessor order, `SelectObject`, `BitBlt` with source `(0,0)` and `SRCCOPY`, null deselect, and `DeleteDC` cleanup. Callers ignore any return value, so source-facing `void` does not change observed behavior.
- Reason it matches the most plausible original precompiled mid-2000s developer source shape: a file-local static helper in `StartupWindow.cpp` is simpler and more human-plausible than exposing a generic GDI helper or returning cleanup success from a draw helper.
- Inferred source-facing names/types/fields used instead of IDA/decompiler labels: `DIBitmap`, `GetBitmapHandle`, `GetWidth`, `GetHeight`, `targetDc`, `imageDc`, `bitmap`, `width`, `height`.
- Naming/coding style convention used and evidence for consistency: current StartupWindow/ImageLoaders generated/docs already use PascalCase helper names and simple Win32/GDI types; DIBitmap docs use `GetBitmapHandle`, `GetWidth`, and `GetHeight`.
- Reason code should remain blank, if applicable: not applicable; code should remain nonblank and source-ready.
- Exact no-code proof, if not eligible: not applicable.

## Final Recommendation
- Exact changes recommended: update UID0004D5 target to `COMPLETION:89`, `CONFIDENCE:91`; preserve owner/emitter/reconstructable metadata; replace the formal code block with the `DIBitmap *` helper above; add current MCP evidence for bytes, range, padding, callsites, GDI calls, DIBitmap accessor flow, no-clipping semantics, and negative alternatives.
- Exact parent assignments recommended: keep `CANONICAL_OWNER:0000O5`, `EMITTER_UIDS:0000O5`, and blank emitter position. No parent/owner move.
- Exact items left no-owner/non-emitting and why: predecessor/successor padding remains ignored/non-emitting; broad aggregate/tracker pages remain non-duplicating support because the exact child emits the body.
- Exact future work outside this assignment scope: a separate WndProc source-quality pass may reconcile the high-level WndProc loop/body text with current static callsite evidence; no UID0004D5 implementation depends on that pass.

## Recommended Target Doc Changes
- Target path: `by-memory/0x00581dc0-0x00581e35.StartupNoticeDrawPcxImage.md`.
- Exact report facts to incorporate: current MCP session `ddf5b602`; exact range `0x00581dc0-0x00581e35`; size `0x75` / 117 bytes; 46 instructions; 4 basic blocks; exact bytes; predecessor/successor padding; two WndProc xrefs `0x00581306` and `0x00581337`; GDI import calls; DIBitmap accessors; no local IDB UDTs; no clipping/transparent/stretch behavior; `SRCCOPY`; `DeleteDC` cleanup-return artifact; source-facing `void` rationale.
- Metadata/score/owner/emitter/reconstructable/C++ changes: set `COMPLETION:89`, `CONFIDENCE:91`; keep `CANONICAL_OWNER:0000O5`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000O5`, blank `EMITTER_POSITION_OPTIONAL`; replace formal C++ with this report's exact formal block.
- Historical/stale assumptions, rejected alternatives, and negative evidence to preserve: older B008 family-report creation at `86/88` is historical; stale `PcxImage *` type should be historicalized; reject ImageLoaders/DIBitmap/generic helper/padding/range-extension/no-owner alternatives.

## Recommended Support Doc Changes
- Support path: `by-file/StartupWindow.md`.
  - Exact report facts to incorporate: add/sync a concise UID0004D5 note that direct B008 evidence confirms the draw helper at `89/91`, current MCP session `ddf5b602`, `DIBitmap *` source-facing argument, two WndProc refs, GDI compatible-DC/select/BitBlt/delete flow, and ImageLoaders/DIBitmap dependency boundary.
  - Metadata/link/score/coverage/source-placement changes: no file score change required unless supervisor chooses; do not duplicate target C++.
- Support path: `by-class/StartupWindow.md`.
  - Exact report facts to incorporate: add/sync a notice draw helper row or method note for UID0004D5, including two WndProc refs and the source-ready draw helper route through UID0000O5.
  - Metadata/link/score/coverage/source-placement changes: no class score change required; keep helper body on exact by-memory child.
- Support path: `by-memory/0x005807d0-0x0058206e.StartupWindowUpdateCheck.md`.
  - Exact report facts to incorporate: update the UID0004D5 child row from a generic one-line helper to direct `89/91` source-ready coverage with range, callsites, padding, DIBitmap/GDI behavior, and no-duplicate-parent-body policy.
  - Metadata/link/score/coverage/source-placement changes: parent aggregate metadata should remain unchanged unless a broader supervisor pass says otherwise.
- Support path: `by-memory/0x00581100-0x005815aa.StartupWindowUpdateCheckWindowProc.md`.
  - Exact report facts to incorporate only if stale in target-relevant text: record that current MCP finds exactly two static UID0004D5 call instructions at `0x00581306` and `0x00581337`; avoid claiming extra direct draw-helper callsites. Full WndProc loop/body source repair is outside this UID0004D5 report unless supervisor explicitly broadens callback scope.
  - Metadata/link/score/coverage/source-placement changes: no score change required for this support sync.
- Support paths already sufficient or dependency-only: `by-memory/0x005818d0-0x005819cc.StartupNoticeLoadAssets.md`, `by-resource/startup-update-notice-resources.md`, `by-file/ImageLoaders.md`, `by-file/DIBitmap.md`, `by-class/DIBitmap.md`, and `by-memory/0x004a17b0-0x004a18a8.LoadPcxImage.md` already contain same-or-greater support for PCX asset loading, ImageLoaders ownership, DIBitmap accessor roles, or resource packaging; update only if a callback audit finds directly stale UID0004D5 wording.

## Score And Metadata Recommendation
- Pre-callback score/metadata: `COMPLETION:86`, `CONFIDENCE:88`, `CANONICAL_OWNER:0000O5`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000O5`, blank emitter position.
- Applied score/metadata: `COMPLETION:89`, `CONFIDENCE:91`; owner/reconstructable/emitter/position preserved.
- Score rationale and reason not higher/lower: completion improves because the exact body, bytes, range, padding, xrefs, GDI flow, accessors, generated state, ownership/source placement, and rejected alternatives are now documented. Confidence improves because all important target claims are current MCP-backed. Scores remain below final-audit levels because original source spelling and IDB UDT/type records are absent, and source-facing `void` is a source-shape inference over a decompiler `BOOL` artifact.
- Score-improvement attempt: PCX/GDI draw-helper behavior resolved; HDC/source bitmap flow resolved; clipping/coordinate semantics resolved as no clipping and direct x/y; caller set resolved as two static WndProc refs; loader path resolved as upstream asset production; ownership resolved as StartupWindow; source-facing name retained as inferred but good; formal C++ readiness resolved with exact block.
- Metadata fields to change or leave unchanged: change only completion/confidence and formal C++ body/content summary/evidence. Do not change canonical owner, emitter, reconstructable state, or emitter position.

## Open Questions With Attempted Resolution
- Open question: is the source argument `PcxImage *` or `DIBitmap *`?
  - Evidence checked: ImageLoaders `LoadPcxImage` exact child, DIBitmap file/class docs, target accessor decompiles, `type_query` for `*Pcx*` and `*DIBitmap*`.
  - Resolution: use `DIBitmap *`; `PcxImage *` is stale/descriptive.
  - Score/C++ impact: supports formal C++ replacement and score increase.
- Open question: should helper return `BOOL`?
  - Evidence checked: target decompile, target disassembly tail, direct WndProc callers/callsite disassembly.
  - Resolution: keep source-facing `void`; IDA's `BOOL` inference comes from final `DeleteDC` value, callers ignore it, and returning cleanup success would be semantically odd for a draw helper.
  - Score/C++ impact: confidence cap but not a C++ blocker.
- Open question: does the helper clip, mask, or perform transparent draw?
  - Evidence checked: target decompile/disassembly and GDI call args.
  - Resolution: no; only `BitBlt` with `SRCCOPY`, dimensions from DIBitmap, source origin `(0,0)`, no clipping other than normal Win32 paint/DC clipping outside this helper.
  - Score/C++ impact: resolved.
- Open question: what is the direct caller set?
  - Evidence checked: `xrefs_to 0x00581dc0`, WndProc decompile, bounded callsite disassembly.
  - Resolution: exactly two static call instructions in WndProc at `0x00581306` and `0x00581337`; asset loader is upstream data-flow support, not a direct caller.
  - Score/C++ impact: resolved for UID0004D5; a separate WndProc pass can refine WndProc high-level loop source if needed.
- Remaining unresolved item: exact original helper/accessor/field spelling.
  - Evidence checked: current IDB names, type catalog, support docs, generated output, old reports.
  - Why no safer answer exists now: no IDB UDT/PDB/type records or original source path proof.
  - Score/C++ impact: use best source-facing descriptive names and keep confidence at `91`, not higher. Future evidence required would be original symbols, source, or a stronger saved IDB rename/type pass.

## Exact Manual Supervisor-Owned Coverage Or Tracker Text
- Not applicable. Generated tracker/coverage files are validator-owned and were not manually edited by B008. Scoped validators refreshed validator-owned state and generated `auto-generated/NexusTK/app/StartupWindow.cpp` through normal side effects.

## Follow-Up Actions
- Supervisor actions: perform supervisor verification of the completed B008 callback, then run supervisor-owned report execution only if verification passes.
- B008 callback actions: completed. B008 edited only leased target/support by-* docs, ran scoped validators, updated this report ledger/checklist, released leases, and stopped before supervisor-owned `execute_report`.
- Future research actions: optional separate WndProc source-quality pass if the supervisor wants to reconcile the full high-level WndProc paint loop/body with current callsite evidence.

## Confidence
- Recommendation confidence: high.
- Score confidence: high for `89/91`.
- Remaining uncertainty: exact original names/types and whether the original source declared the helper `void` or `BOOL`; current behavioral and caller evidence support the recommended `void` formal source shape.

## Validator Results
- Target command: `python .\tools\validator.py --mode file --file by-memory/0x00581dc0-0x00581e35.StartupNoticeDrawPcxImage.md --apply --queue-timeout 240`; `command_id: 000000006479`; `command_timestamp: 2026-07-04T19:12:52-04:00`; exit code `0`; `ok: 1`; warnings/errors: none. Side effects included `completion_update 0004D5 89`, `confidence_update 0004D5 91`, `autogen_registry_update`, `uid_link_insert 0000O5`, reference-index additions for UID0004CT/UID0004D6, projected stats update, and `generated_refresh: deferred`.
- WndProc support command: `python .\tools\validator.py --mode file --file by-memory/0x00581100-0x005815aa.StartupWindowUpdateCheckWindowProc.md --apply --queue-timeout 240`; `command_id: 000000006480`; `command_timestamp: 2026-07-04T19:12:58-04:00`; exit code `0`; `ok: 1`; warnings/errors: none. Side effects included reference-index addition for UID0004D5, projected stats update, and `generated_refresh: deferred`.
- File support command: `python .\tools\validator.py --mode file --file by-file/StartupWindow.md --apply --queue-timeout 240`; `command_id: 000000006514`; `command_timestamp: 2026-07-04T19:30:38-04:00`; exit code `0`; `ok: 1`; warnings/errors: none. Side effects included projected stats update and `generated_refresh: deferred`.
- Class support command: `python .\tools\validator.py --mode file --file by-class/StartupWindow.md --apply --queue-timeout 240`; `command_id: 000000006515`; `command_timestamp: 2026-07-04T19:30:44-04:00`; exit code `0`; `ok: 1`; warnings/errors: none. Side effects included reference-index addition for UID0004D5, projected stats update, and validator-owned generated refresh.
- Aggregate support command: `python .\tools\validator.py --mode file --file by-memory/0x005807d0-0x0058206e.StartupWindowUpdateCheck.md --apply --queue-timeout 240`; `command_id: 000000006516`; `command_timestamp: 2026-07-04T19:30:54-04:00`; exit code `0`; `ok: 1`; warnings/errors: none. Side effects included projected stats update and `generated_refresh: deferred`.
- Generated freshness observation: `auto-generated/NexusTK/app/StartupWindow.cpp` header now reports `validator-command-id: 000000006519`, `validator-refreshed-at: 2026-07-04T19:31:54-04:00`, `validator-refresh-source: deferred-generated-refresh`. The generated UID0004D5 block now shows `Completion:89 | Confidence:91` and `static void StartupNoticeDrawPcxImage(HDC targetDc, DIBitmap *image, int x, int y)` with the accepted body.

## Changed Files
- Created during report-only phase: `tools/leaser/Agents/Agent-B008/research/0004D5-StartupNoticeDrawPcxImage-source-quality.md`.
- Modified by B008 callback: `by-memory/0x00581dc0-0x00581e35.StartupNoticeDrawPcxImage.md`; `by-memory/0x00581100-0x005815aa.StartupWindowUpdateCheckWindowProc.md`; `by-file/StartupWindow.md`; `by-class/StartupWindow.md`; `by-memory/0x005807d0-0x0058206e.StartupWindowUpdateCheck.md`; this report.
- Validator-owned side effects observed: scoped validators updated validator/autogen registry state, projected stats, reference index state, and validator-owned generated `auto-generated/NexusTK/app/StartupWindow.cpp`. B008 did not manually edit generated files, coverage reports, validator state, lifecycle/archive state, or supervisor ledgers.
- Renamed: none.
- Report execution: not run. B008 did not run `execute_report`, dry-run/probing variants, registry lifecycle commands, report moves, or archive commands.

## Implementation Tracking Checklist

Initial report-only pass:
- [x] Supervisor Gate 1 validation passed for this report artifact before callback.
- [x] Target/support docs to update were listed: target `by-memory/0x00581dc0-0x00581e35.StartupNoticeDrawPcxImage.md`; support `by-file/StartupWindow.md`, `by-class/StartupWindow.md`, `by-memory/0x005807d0-0x0058206e.StartupWindowUpdateCheck.md`, and target-relevant callsite wording in `by-memory/0x00581100-0x005815aa.StartupWindowUpdateCheckWindowProc.md`.
- [x] Assignment-time target state and actual evidence checked were recorded: `86/88` metadata, old `PcxImage *` formal C++, generated coded state, and MCP session `ddf5b602` evidence.

Implementation callback pass:
- [x] Claim And Incorporation Ledger updated with destination and verification state for every accepted claim: rows C-0004D5-01 through C-0004D5-12 are `applied`.
- [x] Metadata/score changes applied: target now has `COMPLETION:89`, `CONFIDENCE:91`; owner/emitter/reconstructable/position unchanged.
- [x] Score-limiting blockers incorporated at report-level detail: PCX/GDI behavior, HDC flow, clipping/coordinates, direct callers, loader data flow, ownership, source-facing type/name, and C++ readiness are documented in target/support docs.
- [x] Owner/emitter/reconstructable state preserved: `CANONICAL_OWNER:0000O5`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000O5`, blank `EMITTER_POSITION_OPTIONAL`.
- [x] Split/rename/new-child changes: none; padding remains padding and successor UID0004D6 remains separate.
- [x] Source-placement/range/padding/reclassification and IDA rename/type/comment state applied or accounted for: StartupWindow remains source route; no IDA DB edit requested; target/support docs preserve exact padding and no local UDT evidence.
- [x] First-draft C++ applied: target formal block now contains the accepted `DIBitmap *` formal helper; generated `StartupWindow.cpp` reflects it.
- [x] Third-party import directive: not applicable.
- [x] Exact target/support facts incorporated: MCP session, range/bytes/padding/xrefs, GDI calls, DIBitmap accessor flow, no-clipping semantics, source-facing return/type rationale, generated stale state repair, and rejected alternatives.
- [x] Historical/stale assumptions, rejected alternatives, and negative evidence preserved: older `PcxImage *` and split-only evidence are historical; ImageLoaders/DIBitmap/generic helper/padding/range-extension/no-owner alternatives remain rejected.
- [x] Wave2/Wave3 mentions or artifacts: older generated/simroot output remains lead material only; no Wave2/Wave3 artifact was used as authority.
- [x] Open questions documented as evidence-backed confidence caps: original helper/accessor/type spellings and exact original return spelling remain inferred but no longer block C++.
- [x] Validators run for every edited by-* file: commands `000000006479`, `000000006480`, `000000006514`, `000000006515`, and `000000006516`, all exit `0` / `ok: 1`.
- [x] Generated freshness checked: validator-owned `StartupWindow.cpp` header is refreshed at command `000000006519` and contains UID0004D5 at `89/91` with `DIBitmap *image`; B008 made no manual generated/coverage edits.
- [x] Leases used/released: B008 leased target/WndProc for the first edit/validator batch and released both; after waiting out B007/B010/B011 support leases, B008 leased `by-file/StartupWindow.md`, `by-class/StartupWindow.md`, and aggregate support for the support edit/validator batch and released all three. Final current lease report showed no active leases.
- [x] Lifecycle boundary preserved: B008 did not run `execute_report`, dry-run/probing variants, registry lifecycle commands, report moves, archive commands, or supervisor ledger edits.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B008","command_id":"000000006566","destination_path":"executed-b-agent-research/B008/0004D5-StartupNoticeDrawPcxImage-source-quality.md","details":"report executed into central archive","event":"executed","source_path":"tools/leaser/Agents/Agent-B008/research/0004D5-StartupNoticeDrawPcxImage-source-quality.md","timestamp":"2026-07-04T20:15:02-04:00","uid":"0004D5"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
