** TARGET-REPORT-UID:0000WJ **
** AUTHOR-AGENT-ID:B004 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# 0000WJ CashShopVersionAndCatalogDownload Source-Quality Report

Agent: B004  
Assignment: `B004-report-cashshop-version-and-catalog-download-source-quality-0000WJ-mcp-20260623`  
Date: 2026-06-23  
MCP endpoint/session: `http://127.0.0.1:13337/mcp`, database `80de0a67`  
Target: [UID:0000WJ] `by-memory/0x0041aa00-0x0041b2c9.CashShopVersionAndCatalogDownload.md`

## Finalized Report / Current Recommendation

- Current recommendation: change [UID:0000WJ] from an emitting/reconstructable FileDownloader aggregate to a reviewed non-emitting exact-child inventory: `COMPLETION:88`, `CONFIDENCE:90`, `CANONICAL_OWNER:NONE`, `RECONSTRUCTABLE:FALSE`, blank `EMITTER_UIDS`, blank `EMITTER_POSITION_OPTIONAL`, and blank aggregate C++.
- Final disposition: current MCP session `80de0a67` and the supplemental PE scan confirm the child function boundaries, dispatch routes, request IDs `10000`/`10001`/`10002`, WinINet/JsonCpp/string/global refs, submit-helper callers, and successor boundary. The numeric range is fully understood, but it is not a single source declaration or source-emitting function/class method.
- First-draft C++ recommendation: do not add aggregate C++ to [UID:0000WJ]. Keep C++ on the exact child worker pages that already emit source-shaped bodies, especially [UID:0002TS] `DownloadCashShopVersion` and [UID:0002TT] `DownloadCashShopCatalog`. Keep the submit/helper child pages responsible for their own later C++ decisions.
- Required action if accepted: update the target page and synchronize support docs that still present [UID:0000WJ] as an emitting FileDownloader aggregate. Do not edit coverage reports directly; exact supervisor-owned replacement text is supplied below.
- Confidence: high for range, child inventory, direct routes, request IDs, downloader/fitting-room payload behavior, and no aggregate C++ proof; medium-high for exact original helper spellings, final source-file split, and whether every submit helper was originally declared in `FileDownloader.cpp` or split across feature files.

## Supporting Research

## Target

- Target UID: `0000WJ`.
- Target path: `E:\NTK\GhidraBridge\source-3\project-documentation\by-memory\0x0041aa00-0x0041b2c9.CashShopVersionAndCatalogDownload.md`.
- Required report path: `E:\NTK\GhidraBridge\source-3\project-documentation\tools\leaser\Agents\Agent-B004\research\0000WJ-CashShopVersionAndCatalogDownload-source-quality.md`.
- Current queue row: `project-level/-auto-completion-stats.md` lists `0000WJ | 85 | 88 | 86.5`.
- Current generated route row: `auto-generated/-ag-memory-coverage.md` still marks [UID:0000WJ] as `emits` through `auto-generated/NexusTK/network/FileDownloader.cpp`, but generated `FileDownloader.cpp` only has an empty emitter marker for this aggregate while exact children emit their own code.
- Current coverage row: `by-memory/-coverage-report.md` still has the older `aggregate | CashShopVersionAndCatalogDownload : reconstructable : 80% : strong` text.
- Current target metadata: `COMPLETION:85`, `CONFIDENCE:88`, `CANONICAL_OWNER:0000JC`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000JC`, blank `EMITTER_POSITION_OPTIONAL`, blank C++.

## Current Target State

- The page covers `0x0041aa00-0x0041b2c9`, a contiguous exact-child subset of the larger [UID:0000WI] `FileDownloader Dispatch And Support Inventory`.
- Covered exact children:
  - [UID:0002TS] `0x0041aa00-0x0041ae1c.DownloadCashShopVersion`.
  - [UID:0002TT] `0x0041ae20-0x0041b10c.DownloadCashShopCatalog`.
  - [UID:0002TU] `0x0041b110-0x0041b180.FileDownloaderOnMessage`.
  - [UID:0002CJ] `0x0041b180-0x0041b1f5.FileDownloaderSubmitMinimapRequest`.
  - [UID:0002CK] `0x0041b200-0x0041b26d.FileDownloaderSubmitCashShopCatalogRequest`.
  - [UID:0002CL] `0x0041b270-0x0041b2c9.FileDownloaderSubmitCashShopVersionRequest`.
- The target currently states the range is attached to FileDownloader but keeps aggregate C++ blank because FileDownloader, CashShopVersionRequest, FittingRoom, and MiniMap/source-split questions remain unresolved.
- The later [UID:0000WI] inventory repair is more precise: it treats the larger dispatch cluster as non-emitting, with exact children carrying direct ownership. [UID:0000WJ] should be brought into the same model because it is also a numeric address inventory, not an independently emitted source unit.

## Executive Recommendation

[UID:0000WJ] should become a non-emitting exact-child inventory. The current range is useful as a documentation index for the cash-shop version/catalog download path and adjacent submit helpers, but it should not remain an emitting reconstructable FileDownloader target.

The exact child pages already carry the source-bearing work:

- [UID:0002TS] emits `static void __stdcall DownloadCashShopVersion(CashShopVersionRequest *request)` through [UID:0000JC] `FileDownloader`.
- [UID:0002TT] emits `static void __stdcall DownloadCashShopCatalog(CashShopRequest *request)` through [UID:0000JC] `FileDownloader`.
- [UID:0001SF] emits `FileDownloaderMessageId` values `10000`, `10001`, and `10002`.
- [UID:0000QH]/[UID:0001OP] emit or document `FileDownloader *g_pFileDownloader`, while [UID:00028I] documents `g_pFittingRoomDialog`.

Adding aggregate C++ to [UID:0000WJ] would duplicate child output and obscure the real split between FileDownloader dispatch mechanics, CashShop request payloads, fitting-room state, and minimap request submission. The correct source-quality improvement is metadata/body correction plus support-doc synchronization.

## Supervisor Active Recheck

- Trigger: supervisor assigned a report-only MCP-backed redo/update for [UID:0000WJ], requiring current MCP session `80de0a67`.
- MCP session: `idb_list` returned one active/adopted worker-backed database session `80de0a67`, input path `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, filename `NexusTK.exe.i64`, `is_active:true`, `is_analyzing:false`, backend `worker`, PID/worker PID `16104`.
- MCP health: `server_health(database=80de0a67)` returned `status:"ok"`, IDB path `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, module `NexusTK.exe`, input executable `C:\Users\admin\Desktop\Clone\NexusTK\NexusTK.exe`, imagebase `0x400000`, `auto_analysis_ready:true`, `hexrays_ready:true`, `strings_cache_ready:true`, strings cache size `2067`.
- Executable provenance: both `C:\Users\admin\Desktop\Clone\NexusTK\NexusTK.exe` and `E:\NTK\Resources\NexusTK\NexusTK.exe` hash to SHA-256 `9AEC210BBC5CE592176A21DD8E9D9FD8F250B8D9EA78237915A99BA8CFA9A632`.
- PE section map from the supplemental scan:
  - `.text`: RVA `0x1000`, virtual size `2143404`, raw `0x400-0x20bfff`.
  - `.rdata`: RVA `0x20d000`, virtual size `389310`, raw `0x20c400-0x26b5ff`.
  - `.data`: RVA `0x26d000`, virtual size `196132`, raw `0x26ae00-0x2785ff`.
  - `.rsrc`: RVA `0x29d000`, virtual size `89144`, raw `0x278600-0x28e3ff`.
- Report-only status: no leases were taken. No by-* docs, generated/project-level files, coverage reports, IDA DB files, or tool-state files were edited.

## Inference Research Guidance Check

The workflow evidence ladder is applied as follows:

- Direct facts: MCP function lookup, bytes, xrefs, callees, decompilation, global values, string/global queries, vtable values, and local PE route scans.
- Documentation evidence: target page, exact child pages, FileDownloader/CashShopVersionRequest/FittingRoom support docs, generated output, generated memory coverage, current stats, and current memory coverage row.
- Inference: source-facing names such as `DownloadCashShopVersion`, `DownloadCashShopCatalog`, `SubmitCashShopCatalogRequest`, `SubmitCashShopVersionRequest`, `m_itemShopVersion`, and `m_activeCatalogRequest`; exact source-file placement for submit helpers; and whether some helpers were originally free functions or private methods.
- Stale evidence handled: older target wording that leaves [UID:0000WJ] as a reconstructable FileDownloader aggregate is superseded by current child-level evidence and by the already-executed [UID:0000WI] mixed-inventory repair.
- Wave2/Wave3 material: generated output and generated coverage were used only as route/output-state evidence. No stale generated `g_pCashShopRequest` name was accepted over the corrected `g_pFileDownloader` docs.

## Evidence Standards Used

- MCP tools used: `initialize`, `tools/list`, `idb_list`, `server_health`, `lookup_funcs`, `get_bytes`, `xrefs_to`, `callees`, `analyze_function`, `decompile`, `disasm`, `find`, `get_global_value`, `get_string`, and `list_globals`.
- Local supplement: PE SHA-256, section map, direct `E8`/`E9`/near-conditional control-transfer scan, and absolute VA/RVA/raw-offset dword scans for the child starts and successor start.
- Documentation checked: target page, all six exact child pages, [UID:0000WI] parent inventory, [UID:0000JC] `FileDownloader` file, [UID:00004W] `FileDownloader` class, [UID:0000I1]/[UID:00001I] `CashShopVersionRequest`, [UID:0000JE] `FittingRoom`, `by-global/g_pCashShopRequest.md` current stale-alias page, `by-memory/0x0067a738-0x0067a73c.g_pCashShopRequest.md`, `by-memory/0x0067a73c-0x0067a740.g_pFittingRoomDialog.md`, `by-type/by-constant/DownloaderMessageIds.md`, generated `FileDownloader.cpp`, generated `FittingRoom.cpp`, generated memory coverage, project stats, and current memory coverage row.
- Evidence limit: MCP/PE can prove binary routes, ranges, and payload behavior. They cannot prove original helper spelling, header/private placement, or final source-file split without source/PDB evidence.

## Evidence Checked

MCP function/range checks:

- `lookup_funcs` confirms:
  - `0x0041aa00`: `sub_41AA00`, size `0x41c`.
  - `0x0041ae20`: `sub_41AE20`, size `0x2ec`.
  - `0x0041b110`: `sub_41B110`, size `0x70`.
  - `0x0041b180`: `sub_41B180`, size `0x75`.
  - `0x0041b1f5`: not a function.
  - `0x0041b200`: `sub_41B200`, size `0x6d`.
  - `0x0041b26d`: not a function.
  - `0x0041b270`: `sub_41B270`, size `0x59`.
  - `0x0041b2c9`: not a function.
  - `0x0041b2d0`: `___std_fs_create_symbolic_link@8`, size `0x14`; this is the already-rejected IDA name for the successor [UID:0003GY] queue wrapper, outside [UID:0000WJ].
- `get_bytes` confirms the range has normal MSVC `0xcc` alignment gaps:
  - `0x0041ae1c-0x0041ae20`: four `cc` bytes between version and catalog workers.
  - `0x0041b10c-0x0041b110`: four `cc` bytes between catalog worker and `OnMessage`.
  - `0x0041b1f5-0x0041b200`: eleven `cc` bytes between minimap submit and catalog submit.
  - `0x0041b26d-0x0041b270`: three `cc` bytes between catalog submit and version submit.
  - `0x0041b2c9-0x0041b2d0`: seven `cc` bytes immediately after the target before the successor queue wrapper.

MCP xref/callee checks:

- `xrefs_to(0x0041aa00)` returns one code xref: `0x0041b13c` inside `sub_41B110`.
- `xrefs_to(0x0041ae20)` returns one code xref: `0x0041b156` inside `sub_41B110`.
- `xrefs_to(0x0041b110)` returns one data xref: `0x0060d7d4`, the FileDownloader vtable slot whose value is `0x0041b110`.
- `xrefs_to(0x0041b180)` returns one code xref: `0x00451d18` inside `sub_451C90`.
- `xrefs_to(0x0041b200)` returns one code xref: `0x0041cd0f` inside `sub_41CB70`.
- `xrefs_to(0x0041b270)` returns one code xref: `0x0041c21b` inside `sub_41BDD0`.
- `callees(0x0041b110)` returns calls to `0x0041ae20`, `0x0041a750`, `0x005c7526`, and `0x0041aa00`; the default base-thread fallback `0x00596920` appears in decompile/disassembly.

Global/vtable/string checks:

- `get_global_value(0x0067a738)` and `get_global_value(0x0067a73c)` both read zero image-initialized dwords.
- `xrefs_to(0x0067a738)` returns nine data xrefs, including submit caller paths at `0x0041c215`, `0x0041cd09`, and `0x00451cf8`; current docs correctly treat this as `FileDownloader *g_pFileDownloader`, with stale physical filenames retained.
- `xrefs_to(0x0067a73c)` returns sixteen data xrefs. Relevant target refs are `0x0041ad75` in `DownloadCashShopVersion`, `0x0041b0ba` in `DownloadCashShopCatalog`, and `0x0041b258` in the catalog submit helper.
- `get_global_value(0x0060d798)` reads `0x0041b5e0`, the `CashShopVersionRequest` scalar deleting destructor slot. `xrefs_to(0x0060d798)` returns the version-submit vtable write at `0x0041b2a4` and destructor support at `0x0041b5ea`.
- `get_global_value(0x0060d7a0)` reads `0x0041b570`, the `CashShopRequest` scalar deleting destructor slot. `xrefs_to(0x0060d7a0)` returns the catalog-submit vtable write at `0x0041b22d` and destructor support at `0x0041b576`, plus older raw refs.
- `get_global_value(0x0060d7d4)` reads `0x0041b110`, proving the `FileDownloader::OnMessage` vtable slot route.
- `get_string(0x0060d94c)` returns `version`. Decompilation of `0x0041aa00` shows this key passed to the JsonCpp-style lookup helper.
- `list_globals` confirms saved RTTI/vtable names for `FileDownloader`, `CashShopVersionRequest`, `CashShopRequest`, and FittingRoom classes. Those names support class/payload identity but do not make the aggregate a single source owner.

Decompile/disassembly checks:

- `decompile(0x0041aa00)` shows `InternetOpenW(&szAgent, ...)`, `InternetOpenUrlW(... L"https://secure.kru.com/itemshop/data/itemshop.ver" ...)`, five `InternetSetOptionW` timeout calls with `3000`, HTTP status query, content-length query into request `+0x08`, progress into request `+0x0c`, debug text `L"Downloading : %d / %d\n"`, JsonCpp reader/parse helpers, key `"version"`, and a copy into `dword_67A73C + 1936` (`+0x790`).
- `decompile(0x0041ae20)` shows the same WinINet skeleton with URL `L"https://secure.kru.com/itemshop/data/itemshop.json"`, `3000` timeouts, content-length/progress updates, append into the request string at `+0x10`, completion byte write at `+0x04`, and conditional virtual delete when `g_pFittingRoomDialog == NULL` or `g_pFittingRoomDialog + 0x7a8` does not still own the request.
- `decompile(0x0041b110)` shows the dispatch switch:
  - `case 10000`: if payload, call `sub_41A750(payload)` then free payload.
  - `case 10001`: if payload, call `sub_41AE20(payload)`.
  - `case 10002`: if payload, call `sub_41AA00(payload)` then destroy through the payload vtable.
  - default: call base thread handler `sub_596920(this, messageId, payload, arg4)`.
- `decompile(0x0041b180)` shows a `0x238` allocation, zeroed state/progress fields, map id at `+0x0c`, `wcscpy_s` to `+0x218` with size `0x10`, `wcscpy_s` to `+0x10` with size `0x104`, and queue post `sub_596960(this, 10000, payload, 0)`.
- `decompile(0x0041b200)` shows a `0x28` allocation, `CashShopRequest::vftable` at `+0`, state/completion byte at `+0x04`, dwords at `+0x08/+0x0c`, small-string state at `+0x10/+0x20/+0x24`, queue post `sub_596960(this, 10001, payload, 0)`, and store to `dword_67A73C + 1960` (`+0x7a8`) when the fitting-room dialog exists.
- `decompile(0x0041b270)` shows a `0x10` allocation, `CashShopVersionRequest::vftable` at `+0`, state byte at `+0x04`, dwords at `+0x08/+0x0c`, queue post `sub_596960(this, 10002, payload, 0)`, and a null-allocation fallback that posts `10002` with null payload.

Caller-context checks:

- `decompile(0x0041bdd0)` shows `FittingRoomDialog` constructor setup, writes `dword_67A73C = this` or zero, installs FittingRoom vtables, then calls `sub_41B270((void *)dword_67A738)` at `0x0041c21b`.
- `decompile(0x0041cb70)` shows `sub_41B200((void *)dword_67A738)` at `0x0041cd0f` in the fitting-room action path.
- `decompile(0x00451c90)` shows `v7 = (void *)dword_67A738` at `0x00451cf8` and `sub_41B180(v7, *(this+456), mapCode, outputPath)` at `0x00451d18`, followed by a timer schedule.

Generated-output checks:

- `auto-generated/NexusTK/network/FileDownloader.cpp` currently emits `g_pFileDownloader`, the `DownloadMinimapFile`, `DownloadCashShopVersion`, and `DownloadCashShopCatalog` first-draft worker bodies, and `FileDownloaderMessageId`.
- The same generated file shows [UID:0000WJ], [UID:0002TU], [UID:0002CJ], [UID:0002CK], and [UID:0002CL] as empty emitter markers.
- `auto-generated/NexusTK/cashshop/FittingRoom.cpp` still contains stale generated spelling `SubmitCashShopVersionRequest(g_pCashShopRequest, 10002)`. This is generated-output caveat only; support docs already correct `0x0067a738` to `FileDownloader *g_pFileDownloader`.

## PE Route Scan Supplement

The local PE scan used `E:\NTK\Resources\NexusTK\NexusTK.exe`, SHA-256 `9AEC210BBC5CE592176A21DD8E9D9FD8F250B8D9EA78237915A99BA8CFA9A632`, imagebase `0x400000`.

| Target | RVA | Raw | Direct control hits | VA dword hits | RVA dword hits | Raw-offset dword hits |
| --- | ---: | ---: | --- | --- | --- | --- |
| `0x0041aa00` | `0x1aa00` | `0x19e00` | `0x41b13c -> 0x41aa00` | 0 | 0 | 0 |
| `0x0041ae20` | `0x1ae20` | `0x1a220` | `0x41b156 -> 0x41ae20` | 0 | 0 | 0 |
| `0x0041b110` | `0x1b110` | `0x1a510` | 0 | 1 at raw `0x20c1d4` (`0x0060d7d4` vtable slot) | 0 | 0 |
| `0x0041b180` | `0x1b180` | `0x1a580` | `0x451d18 -> 0x41b180` | 0 | 0 | 0 |
| `0x0041b200` | `0x1b200` | `0x1a600` | `0x41cd0f -> 0x41b200` | 0 | 0 | 0 |
| `0x0041b270` | `0x1b270` | `0x1a670` | `0x41c21b -> 0x41b270` | 0 | 0 | 0 |
| `0x0041b2d0` | `0x1b2d0` | `0x1a6d0` | 0 | 0 | 0 | 0 |

This independently corroborates the MCP xrefs. It also confirms no direct PE route into the successor `0x0041b2d0` queue wrapper from this assignment's range.

## Function / Child Inventory

| Range | UID / page | MCP function | Role | Source/C++ disposition |
| --- | --- | --- | --- | --- |
| `0x0041aa00-0x0041ae1c` | [UID:0002TS] `DownloadCashShopVersion` | `sub_41AA00`, size `0x41c` | Downloads `itemshop.ver`, parses JSON key `version`, writes FittingRoomDialog `+0x790` | Reconstructable child; first-draft C++ already emitted through FileDownloader |
| `0x0041ae1c-0x0041ae20` | ignored padding | not a function | four `cc` bytes | no source code |
| `0x0041ae20-0x0041b10c` | [UID:0002TT] `DownloadCashShopCatalog` | `sub_41AE20`, size `0x2ec` | Downloads `itemshop.json`, fills `CashShopRequest` text/progress/completion | Reconstructable child; first-draft C++ already emitted through FileDownloader |
| `0x0041b10c-0x0041b110` | ignored padding | not a function | four `cc` bytes | no source code |
| `0x0041b110-0x0041b180` | [UID:0002TU] `FileDownloaderOnMessage` | `sub_41B110`, size `0x70` | Dispatches message IDs `10000`/`10001`/`10002` | Reconstructable child; C++ still capped by Thread handler signature/source shape |
| `0x0041b180-0x0041b1f5` | [UID:0002CJ] `FileDownloaderSubmitMinimapRequest` | `sub_41B180`, size `0x75` | Allocates minimap request payload and posts `10000` | Reconstructable child; helper/payload names remain provisional |
| `0x0041b1f5-0x0041b200` | ignored padding | not a function | eleven `cc` bytes | no source code |
| `0x0041b200-0x0041b26d` | [UID:0002CK] `FileDownloaderSubmitCashShopCatalogRequest` | `sub_41B200`, size `0x6d` | Allocates `CashShopRequest`, posts `10001`, stores active catalog request at FittingRoomDialog `+0x7a8` | Reconstructable child; helper/source split remains provisional |
| `0x0041b26d-0x0041b270` | ignored padding | not a function | three `cc` bytes | no source code |
| `0x0041b270-0x0041b2c9` | [UID:0002CL] `FileDownloaderSubmitCashShopVersionRequest` | `sub_41B270`, size `0x59` | Allocates `CashShopVersionRequest`, posts `10002`, preserves null-payload fallback | Reconstructable child; helper/source split remains provisional |
| `0x0041b2c9-0x0041b2d0` | outside target padding | not a function | seven `cc` bytes | boundary before [UID:0003GY] |

## Positive Evidence Summary

- The target's numeric range is fully covered by exact child functions and padding; no unmodeled function or data island remains inside `0x0041aa00-0x0041b2c9`.
- The two cash-shop workers have direct dispatch-only routes from `FileDownloader::OnMessage`.
- The dispatch function has a concrete FileDownloader vtable route through `0x0060d7d4`.
- The three submit helpers have direct callers that pass `g_pFileDownloader` / `dword_67A738`.
- The version/catalog workers share the same WinINet skeleton, URLs, timeout constants, content-length/progress fields, debug literal, and cleanup shape.
- The version worker's JsonCpp path and `FittingRoomDialog+0x790` write support the `m_itemShopVersion` field name.
- The catalog worker and submit helper's `FittingRoomDialog+0x7a8` reads/writes support the `m_activeCatalogRequest` field name.
- `CashShopVersionRequest` and `CashShopRequest` vtable values and payload sizes are confirmed in the current session.
- Exact child pages already carry or gate their source-shaped C++; the aggregate has no extra behavior beyond child ordering.

## Negative Evidence / Rejected Alternatives

- Reject aggregate FileDownloader C++: [UID:0000WJ] has no single function body, vtable slot, method, or declaration. It is a contiguous address range that spans multiple exact child pages.
- Reject retaining [UID:0000WJ] as an emitting reconstructable target: generated `FileDownloader.cpp` already emits child bodies and leaves [UID:0000WJ] as an empty marker. Keeping the aggregate as `emits` creates duplicate/empty-output pressure.
- Reject CashShopVersionRequest as aggregate owner: it owns payload identity and the version-request vtable/destructor context, but the workers and dispatch are FileDownloader message handlers and the catalog path uses `CashShopRequest`.
- Reject FittingRoom as aggregate owner: FittingRoom owns dialog state and triggers catalog/version requests, but the worker-thread dispatch and HTTP worker bodies are FileDownloader-routed. FittingRoom is a state consumer and caller context, not the owner of the whole range.
- Reject MiniMap as aggregate owner: only [UID:0002CJ] is a minimap submit helper. The rest of the range is cash-shop/catalog/version/dispatch logic.
- Reject no-owner for exact child functions: each child has live routes and appropriate direct owner/source context. The no-owner recommendation applies only to the aggregate page's canonical owner, not to exact child pages.
- Reject generated stale `g_pCashShopRequest` naming as proof: current docs and MCP global routes support `g_pFileDownloader` for `0x0067a738`; the generated FittingRoom spelling is stale output and should not override support docs.
- Reject source reconstruction that emits IDA-shaped manual vtable stores for the aggregate. Payload vtable writes are child facts and should remain in child/support details, not a synthetic aggregate function.

## Heuristic / Inference Reanalysis And Validation

1. Function boundary: MCP and PE agree on all starts, sizes, and padding. The target begins at a real worker function and ends exactly at the end of the version submit helper. The successor `0x0041b2d0` is outside the target and has no route from this scan.
2. Request IDs: `10000` maps to minimap file download, `10001` maps to cash-shop catalog download, and `10002` maps to cash-shop version download. The values appear in both `OnMessage` dispatch and submit helpers.
3. Worker names: `DownloadCashShopVersion` and `DownloadCashShopCatalog` are source-facing names supported by URL, payload, and dispatcher evidence. They remain inferred, not original-symbol proof.
4. Submit helper names: `FileDownloaderSubmitMinimapRequest`, `FileDownloaderSubmitCashShopCatalogRequest`, and `FileDownloaderSubmitCashShopVersionRequest` are best current source-facing names, but final original spellings and method/free-function placement remain uncertain.
5. Source-file split: FileDownloader is the strongest emitter for worker and queue mechanics. FittingRoom owns UI/dialog state and direct version/catalog trigger context. CashShopVersionRequest/CashShopRequest own payload layout/destructors. No evidence combines all of those into one C++ declaration for [UID:0000WJ].
6. Code-entry gate: the exact child worker pages already crossed the current code-entry threshold and emit first-draft C++. The aggregate should not use its average score to emit duplicate C++ because it is a non-source inventory.
7. Score impact: current MCP evidence improves confidence and completion for the aggregate as documentation, but the correct source-quality fix is non-emitting classification rather than first-draft aggregate C++.

## Ranked Ownership / Source-Placement Alternatives

### 1. Non-emitting exact-child inventory for [UID:0000WJ] - recommended

- Evidence for: the range is fully explained by exact children; child pages already own source-level reconstruction; current [UID:0000WI] precedent uses the same non-emitting inventory model for the broader cluster.
- Evidence against: the range is contiguous and heavily FileDownloader-related, so a FileDownloader-biased filename remains understandable.
- Decision: recommend `CANONICAL_OWNER:NONE`, `RECONSTRUCTABLE:FALSE`, blank emitter, blank aggregate C++. Use the page as an index/evidence summary.

### 2. [UID:0000JC] FileDownloader as canonical owner/emitter - rejected for aggregate, accepted for exact children

- Evidence for: `OnMessage` is a FileDownloader vtable method, workers are called only by FileDownloader dispatch, submit helpers post through the FileDownloader singleton, and generated worker C++ routes through `NexusTK/network/FileDownloader.cpp`.
- Evidence against: the aggregate includes FittingRoom state writes/reads, CashShop request payloads, a minimap submit helper, and multiple exact children with their own code-entry decisions. A FileDownloader aggregate C++ block would duplicate child output.
- Decision: keep FileDownloader as source owner/emitter for the exact FileDownloader children and support docs; remove it as canonical owner/emitter for [UID:0000WJ] itself.

### 3. CashShopVersionRequest / CashShopRequest payload ownership - rejected for aggregate

- Evidence for: version submit writes `CashShopVersionRequest::vftable` and uses a `0x10` payload; catalog submit writes `CashShopRequest::vftable` and uses a `0x28` payload.
- Evidence against: payload classes do not own FileDownloader worker-thread dispatch, WinINet worker bodies, or minimap submit helper.
- Decision: use payload pages as support context only.

### 4. FittingRoom source family - rejected for aggregate

- Evidence for: FittingRoom constructor calls version submit, fitting action calls catalog submit, version worker writes `m_itemShopVersion`, and catalog request uses `m_activeCatalogRequest`.
- Evidence against: FittingRoom is caller/state context. The HTTP workers and `OnMessage` are FileDownloader-routed.
- Decision: support-context update only if stale; not canonical owner for [UID:0000WJ].

### 5. MiniMap / MapPane source family - rejected for aggregate

- Evidence for: `0x0041b180` is the minimap submit helper and has caller `0x00451d18`.
- Evidence against: one helper inside the range cannot own the cash-shop version/catalog workers or FileDownloader dispatch.
- Decision: mention as child-context only.

### 6. No-owner/non-emitting for all children - rejected

- Evidence for: some helper spellings/source-file placement remain inferred.
- Evidence against: every child start has a live route and direct behavioral context. The child pages are not dead/no-route artifacts.
- Decision: no-owner applies only to the aggregate target as an inventory; exact children retain their direct routes.

## Source Placement

- Recommended target placement: [UID:0000WJ] remains a by-memory range index, not a generated source declaration.
- Recommended source-bearing placements:
  - Worker bodies and `OnMessage`/submit mechanics: [UID:0000JC] `NexusTK/network/FileDownloader.cpp`.
  - Request payload identity/destructors/vtables: `CashShopRequest` and `CashShopVersionRequest` support docs.
  - FittingRoom state fields and caller context: [UID:0000JE] `NexusTK/cashshop/FittingRoom.cpp` and `FittingRoomDialog`.
  - Minimap submit caller context: MapPane/MiniMap support docs only.
- Remaining uncertainty: exact original helper spellings, private/static/free-function placement, whether submit helpers were authored in FileDownloader or a feature source file with a downloader receiver, and final `Thread::OnMessage` signature shape.

## Score / Metadata / C++ Recommendation

Recommended [UID:0000WJ] metadata:

```text
COMPLETION:88
CONFIDENCE:90
CANONICAL_OWNER:NONE
RECONSTRUCTABLE:FALSE
EMITTER_UIDS:
EMITTER_POSITION_OPTIONAL:
```

C++ recommendation:

```text
Leave [UID:0000WJ] RECONSTRUCTION_CPP blank.
```

No-code proof:

- The range is an aggregate inventory, not one function.
- Exact child pages already emit or gate first-draft C++ independently.
- The generated source currently has [UID:0000WJ] only as an empty marker while child pages emit the source-shaped worker bodies.
- Adding aggregate C++ would duplicate child reconstruction and risk mixing FileDownloader, CashShop request, FittingRoom, and MiniMap source responsibilities into a synthetic source block.

Score rationale:

- Raise completion from `85` to `88` because current MCP/PE evidence fully revalidates the child inventory, padding, dispatch IDs, globals, vtables, worker behavior, and successor boundary.
- Raise confidence from `88` to `90` because current IDB and PE route scans agree and no unresolved range hole remains.
- Do not raise higher because original helper spellings, source-file/private placement, `OnMessage` final signature, and submit-helper C++ signatures remain inferred. The aggregate itself remains non-emitting even though its exact children are source-quality candidates.

## Target / Support Doc Changes Needed If Accepted

Required target update:

- `by-memory/0x0041aa00-0x0041b2c9.CashShopVersionAndCatalogDownload.md`
  - Change metadata to `88/90`, `CANONICAL_OWNER:NONE`, `RECONSTRUCTABLE:FALSE`, blank `EMITTER_UIDS`, blank C++.
  - Rename/title/body wording to make it a non-emitting exact-child inventory while preserving the existing filename.
  - Add a `2026-06-23 B004 MCP-backed source-quality recheck` section with session `80de0a67`, IDB/executable provenance, SHA-256, function inventory, padding, xrefs, decompile facts, PE route scan, generated-output caveats, rejected alternatives, and no-code proof.
  - Preserve child-level details for `itemshop.ver`, `itemshop.json`, JsonCpp key `"version"`, request IDs `10000`/`10001`/`10002`, `g_pFileDownloader`, `g_pFittingRoomDialog`, `m_itemShopVersion +0x790`, `m_activeCatalogRequest +0x7a8`, vtable writes, and null-payload fallback.

Required support synchronization:

- `by-file/FileDownloader.md`
  - State that [UID:0000WJ] is a non-emitting exact-child inventory, while exact children remain FileDownloader-routed.
  - Add current MCP session `80de0a67` evidence for `OnMessage` cases, one-dispatch-call worker routes, vtable slot `0x0060d7d4`, submit helper direct callers, and no aggregate C++.
  - Preserve existing first-draft worker declarations and message enum.
- `by-class/FileDownloader.md`
  - Synchronize the same FileDownloader class route facts for `OnMessage`, worker dispatch, and submit helpers.
  - Make clear that FileDownloader is not the canonical owner of the aggregate page itself after reclassification.
- `by-memory/0x0041a670-0x0041b69f.FileDownloaderDispatch.md`
  - It already has the correct non-emitting mixed-inventory model at same-or-greater breadth. Update only if needed to mention [UID:0000WJ] has also been refreshed as a non-emitting subset inventory.

Support docs to check and update only if stale contradictions remain:

- `by-file/FittingRoom.md` and `by-class/FittingRoomDialog.md`: should continue to document `m_itemShopVersion`, `m_activeCatalogRequest`, constructor version-submit call, and catalog-submit/action relationship as FittingRoom context, not aggregate ownership.
- `by-file/CashShopVersionRequest.md` and `by-class/CashShopVersionRequest.md`: should continue to own payload identity/destructor/vtable support while keeping `0x0041b270` cross-linked to FileDownloader routing.
- `by-file/CashShopRequest.md` and `by-class/CashShopRequest.md`: should continue to own catalog request payload layout and destructor identity while keeping catalog submit/worker context cross-linked.
- `by-global/g_pCashShopRequest.md` and `by-memory/0x0067a738-0x0067a73c.g_pCashShopRequest.md`: already corrected to stale physical filename alias for `g_pFileDownloader`; update only if they still cite [UID:0000WJ] as aggregate source owner.
- `by-memory/0x0067a73c-0x0067a740.g_pFittingRoomDialog.md`: update only if stale wording implies FittingRoom owns FileDownloader dispatch.
- `by-type/by-constant/DownloaderMessageIds.md`: likely already sufficient; update only if the current MCP session note is required.

Do not edit:

- Any `-coverage-report.md` file during implementation; supervisor applies coverage.
- Generated/project-level files manually.
- IDA DB or MCP/tool state.

## Supervisor-Owned Coverage Text

Current stale row in `by-memory/-coverage-report.md`:

```text
        - [UID:0000WJ][0x0041aa00-0x0041b2c9.CashShopVersionAndCatalogDownload](by-memory/0x0041aa00-0x0041b2c9.CashShopVersionAndCatalogDownload.md) 0x0041aa00-0x0041b2c9 | aggregate | CashShopVersionAndCatalogDownload : reconstructable : 80% : strong : Cash-shop/fitting-room HTTP download aggregate attached to FileDownloader; exact child pages cover `itemshop.ver`/`itemshop.json` download helpers, FileDownloader message `10000`/`10001`/`10002` dispatch, minimap/catalog/version submit helpers, padding, request payload cross-links, and unresolved FileDownloader/CashShopVersionRequest/FittingRoom source split keeps C++ blank.
```

Replace with:

```text
        - [UID:0000WJ][0x0041aa00-0x0041b2c9.CashShopVersionAndCatalogDownload](by-memory/0x0041aa00-0x0041b2c9.CashShopVersionAndCatalogDownload.md) 0x0041aa00-0x0041b2c9 | aggregate | CashShopVersionAndCatalogDownloadInventory : ignored : 88% : strong : 2026-06-23 B004 MCP/PE-backed non-emitting exact-child inventory for cash-shop version/catalog workers, FileDownloader message dispatch, and minimap/catalog/version submit helpers; exact children carry source ownership/emission through FileDownloader, CashShopVersionRequest, FittingRoom/MiniMap context, while the aggregate has no single source declaration or aggregate C++.
```

Supervisor/project-level generated effects expected after accepted implementation and validator/autogen/rescore:

- [UID:0000WJ] should no longer appear as an `emits` row in generated memory coverage.
- `project-level/-auto-completion-stats.md` should reflect `88/90` for [UID:0000WJ] after validator/rescore, if supervisor applies the metadata recommendation.

## Expected Validators After Implementation

Run from `E:\NTK\GhidraBridge\source-3\project-documentation` for every changed by-* doc:

> Executable block R001 was removed from this report and preserved verbatim in [0000WJ-CashShopVersionAndCatalogDownload-source-quality-removed.md](0000WJ-CashShopVersionAndCatalogDownload-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

If support docs are edited because stale contradictions are found, also run the corresponding scoped file validators, for example:

> Executable block R002 was removed from this report and preserved verbatim in [0000WJ-CashShopVersionAndCatalogDownload-source-quality-removed.md](0000WJ-CashShopVersionAndCatalogDownload-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

## Open Questions / Closure

- Closed: exact function starts, sizes, padding, request IDs, direct routes, worker behavior, vtable/global routes, and successor boundary.
- Closed: generated stale `g_pCashShopRequest` name is not authoritative; `0x0067a738` is the FileDownloader singleton route in current docs and MCP xrefs.
- Closed: [UID:0000WJ] should not receive aggregate C++ because child pages already carry source-output decisions.
- Open but capped: exact original names/signatures for submit helpers, exact original `OnMessage` signature, source-file/private/static placement of helpers, and whether original code grouped some helper declarations outside `FileDownloader.cpp`.

## Implementation Tracking Checklist

Report-only pass status:

- [x] Read current `Agent-B004/goal.md` and applied `ntk-b-agent-workflow` rules for report-only research.
- [x] Read target page and relevant support docs without taking leases or editing by-* docs.
- [x] Performed current MCP health/session/provenance checks for session `80de0a67`.
- [x] Performed bounded MCP function, byte, xref, callee, decompile, global/vtable, string, and caller-context checks.
- [x] Performed supplemental local PE route scan for child starts and successor start.
- [x] Wrote this report only under `tools/leaser/Agents/Agent-B004/research/`.

Accepted implementation callback status:

- [x] Leased and updated `by-memory/0x0041aa00-0x0041b2c9.CashShopVersionAndCatalogDownload.md`: metadata changed to `COMPLETION:88`, `CONFIDENCE:90`, `CANONICAL_OWNER:NONE`, `RECONSTRUCTABLE:FALSE`, blank `EMITTER_UIDS`, blank `EMITTER_POSITION_OPTIONAL`, and blank aggregate C++; body now reclassifies [UID:0000WJ] as a non-emitting exact-child inventory and preserves session `80de0a67`, executable SHA/provenance, child inventory, padding, xrefs/routes, decompile facts, PE scan, generated-output caveats, rejected alternatives, score rationale, and no-code proof. Validator proof: `python .\tools\validator.py --mode file --file by-memory\0x0041aa00-0x0041b2c9.CashShopVersionAndCatalogDownload.md --apply --queue-timeout 240`, exit code `0`, `ok: 1`.
- [x] Leased and updated `by-file/FileDownloader.md`: added `2026-06-23 B004 Aggregate Reclassification` support note stating [UID:0000WJ] is now non-emitting while exact children remain FileDownloader-routed; included `OnMessage` worker routes, vtable slot `0x0060d7d4`, submit helper callers, `g_pFileDownloader`, `g_pFittingRoomDialog`, `m_itemShopVersion +0x790`, `m_activeCatalogRequest +0x7a8`, and no aggregate C++ proof. Validator proof: `python .\tools\validator.py --mode file --file by-file\FileDownloader.md --apply --queue-timeout 240`, exit code `0`, `ok: 1`.
- [x] Leased and updated `by-class/FileDownloader.md`: added the matching class-level aggregate reclassification note, preserving FileDownloader class route facts for `OnMessage`, worker dispatch, submit helpers, the vtable slot, and explicit clarification that FileDownloader is not the canonical owner of the aggregate page after reclassification. Validator proof: `python .\tools\validator.py --mode file --file by-class\FileDownloader.md --apply --queue-timeout 240`, exit code `0`, `ok: 1`.
- [x] Leased and updated `by-memory/0x0041a670-0x0041b69f.FileDownloaderDispatch.md`: added a subset-inventory note tying [UID:0000WJ] to the same non-emitting exact-child inventory model as the broader [UID:0000WI] dispatch/support inventory, with `CANONICAL_OWNER:NONE`, `RECONSTRUCTABLE:FALSE`, and blank aggregate C++. Validator proof: `python .\tools\validator.py --mode file --file by-memory\0x0041a670-0x0041b69f.FileDownloaderDispatch.md --apply --queue-timeout 240`, exit code `0`, `ok: 1`.
- [x] Checked `by-file/FittingRoom.md` and `by-class/FittingRoomDialog.md`: no edit applied. Existing support detail already treats `m_itemShopVersion +0x790`, `m_activeCatalogRequest +0x7a8`, constructor version-submit, and catalog-submit/action relationship as FittingRoom context rather than aggregate ownership; no direct stale contradiction required an edit.
- [x] Checked `by-file/CashShopVersionRequest.md` and `by-class/CashShopVersionRequest.md`: no edit applied. Existing text keeps payload identity/destructor/vtable support and cross-links the version-submit helper to FileDownloader routing at same-or-greater detail.
- [x] Checked `by-file/CashShopRequest.md` and `by-class/CashShopRequest.md`: no edit applied. Existing text keeps catalog payload layout/destructor identity separate from FileDownloader worker/submit routing and does not require [UID:0000WJ] aggregate ownership.
- [x] Checked `by-global/g_pCashShopRequest.md` and `by-memory/0x0067a738-0x0067a73c.g_pCashShopRequest.md`: no edit applied. Both already identify the stale physical filename alias and source-facing `FileDownloader *g_pFileDownloader`; no [UID:0000WJ] aggregate-owner contradiction found.
- [x] Checked `by-memory/0x0067a73c-0x0067a740.g_pFittingRoomDialog.md`: no edit applied. Existing text documents the [UID:0000WJ] worker/helper refs as FittingRoom dialog uses, not FittingRoom ownership of FileDownloader dispatch.
- [x] Checked `by-type/by-constant/DownloaderMessageIds.md`: no edit applied. It already carries the `10000`/`10001`/`10002` message-id declarations and child-route descriptions at sufficient detail for this implementation.
- [x] Ran scoped validators for every changed by-* doc from `E:\NTK\GhidraBridge\source-3\project-documentation`; all four commands above returned exit code `0` and `ok: 1`.
- [x] Did not edit any `-coverage-report.md` file. The exact supervisor-owned replacement row above remains in this report for supervisor application.
- [x] Recorded validator side effects: each validator rebuilt `validator.ini` metadata (`autogen_registry_rebuild: 1`), reported `autogen_report_noop: 7` for generated coverage reports unchanged, and updated the validator-managed projected path completion section in `project-level/-auto-completion-stats.md`; no generated coverage report changed.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B004","command_id":"000000004165","destination_path":"executed-b-agent-research/B004/0000WJ-CashShopVersionAndCatalogDownload-source-quality.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:17","uid":"0000WJ"} -->
<!-- {"agent":"B004","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 0000WJ-CashShopVersionAndCatalogDownload-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B004/0000WJ-CashShopVersionAndCatalogDownload-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"0000WJ"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
