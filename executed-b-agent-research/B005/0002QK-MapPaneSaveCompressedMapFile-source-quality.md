** TARGET-REPORT-UID:0002QK **
** AUTHOR-AGENT-ID:B005 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.6 | xHigh **
# UID0002QK MapPaneSaveCompressedMapFile Source-Quality Research


## Finalized Report / Current Recommendation

- Applied recommendation: UID0002QK now emits the exact source-level `void MapPane::SaveCompressedMapFile()` body from Destination 1 at `92/94`, with owner/emitter/range/position/nesting unchanged.
- Final disposition: reconstructable original NexusTK MapPane source, not a compiler helper, aggregate, duplicate, StdioFile method, zlib-owned body, or no-code row.
- Callback result: C01-C35 were incorporated or explicitly excluded with reason at report-level detail across the accepted five-page scope. Five initial scoped validators and waited refresh `000000011892` passed; the narrow Gate 2 repair then passed scoped validator `000000011920` and final waited refresh `000000011921`.
- Confidence: very strong for behavior, ABI, ownership, source placement, field/type/global dependencies, failure state, and formal source shape; lexical confidence is capped below certainty because original private symbols are absent.
- Current lifecycle: B005's accepted implementation callback is complete and independently reviewable. Supervisor-owned execution/archive state remains external to this artifact; B005 ran no execute/probe/move/archive/lifecycle command.

## Supporting Research

### Mandatory MCP availability and evidence-time session

- A fresh streamable-MCP `initialize` returned `ida-pro-mcp 1.0.0` with protocol `2025-06-18`.
- Fresh `idb_list` discovered active/adopted session `6b2e78f3` for `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, worker PID `15716`, `is_analyzing:false`.
- Evidence-time `server_health` returned `status:ok`, module `NexusTK.exe`, image base `0x00400000`, and ready auto-analysis, Hex-Rays, and string cache (`2067` strings). A final lightweight recheck at `2026-07-14T16:35:41-04:00` reconfirmed the same active session and healthy server. These are collection-time facts, not a claim that a transient worker remains alive after review or archival.
- Valid bounded calls for target bytes, function lookup/analysis, basic blocks, disassembly/decompilation, callers, callees, xrefs, helpers, constants, strings, and globals all succeeded. IDA was read-only and no mutation was requested.
- One malformed local batch omitted the required `database` argument because PowerShell's automatic `$args` variable collided with the request builder. The endpoint rejected those requests immediately as client-shape errors. They were not valid bounded IDB calls, were corrected at once, and do not indicate MCP unavailability.

### Prior-report search provenance

- Exact terms actually searched were `0002QK`, `UID:0002QK`, `0x00504e00`, `MapPaneSaveCompressedMapFile`, `SaveCompressedMapFile`, `sub_504E00`, `CMAP`, `compressed map`, `MapPane`, and `NexusTK/map/MapPane.cpp`. Direct-report candidates were the union of exact UID/address/function-name hits plus target-relevant CMAP/compressed-map/AUTOBUF support hits. Broad owner/file terms were evaluated in conjunction with the target UID/address/name; unrelated reports that only contained generic MapPane or incidental CMAP text were not candidate matches and were not misclassified as direct prior coverage.
- Search roots actually checked were central `executed-b-agent-research`; active `tools/leaser/Agents/Agent-B001/research` through `Agent-B015/research`; `tools/leaser/Agents/Older-Research`; `tools/leaser/Agents/SpecialReports`; root `archived`, including any available legacy B-agent report trees. No matching active or legacy archived report existed outside the central executed set.
- Every direct-report candidate and target-relevant support match was opened and classified:
  - `executed-b-agent-research/B004/0000L3-MapPane-empty-emitter-family-source-quality.md`: direct historical blocker inventory, now superseded on source readiness. It established the exact size, four callers, CMAP/compress/free-clear/cache behavior, but explicitly deferred UID0002QK C++ pending helper declarations and final fields.
  - `executed-b-agent-research/B004/00019E-AUTOBUFUnsignedCharConstructor-source-quality.md`: direct support, executed/current. It resolves `_AUTOBUF<unsigned char>` layout, `m_data`/`m_count`, Resize ownership, and automatic cleanup through paired load evidence; it does not audit UID0002QK's direct writer.
  - `executed-b-agent-research/B005/0002QJ-MapPaneLoadCompressedMapFile-empty-emitter-source-quality.md`: direct paired evidence, executed/current. It established canonical fields, exact format/type/AUTOBUF/zlib dependencies, and deliberately left UID0002QK's independent direct-CRT/failure/source-body audit incomplete. It is not a direct save report.
  - `executed-b-agent-research/B002/0002I7-0002QF-mappane-lifecycle-source-quality.md`: incidental executed/current lifecycle support. It identifies destructor call ordering and canonical MapPane cache fields but does not audit the save body.
  - `executed-b-agent-research/B001/0001AW-mappane-packet-source-split-continuation-batch6.md`: incidental executed/current packet-caller support. It identifies the opcode `0x15` handler's call to `sub_504E00`, not save semantics.
  - `executed-b-agent-research/B002/0002QH-0002QI-0002QO-0002QP-0002QQ-000231-MapPaneTeardownObjectPacket-source-quality.md`: incidental executed/current teardown support. It preserves `SaveCompressedMapFile(); SaveUserSettings();` ordering but does not audit save internals.
  - `executed-b-agent-research/B003/0000ZW-ChangeManRegister-source-quality.md`: incidental executed/current generated MapPane cleanup example containing `SaveCompressedMapFile()`; no direct save evidence.
  - `executed-b-agent-research/B005/0001AV-SaveUserSettings-empty-emitter-source-quality.md`: incidental executed/current neighboring caller support. It cites teardown ordering and generated output only; no direct save-body analysis.
  - `executed-b-agent-research/B005/0002UA-WideFormatWrapper-source-quality.md`: incidental executed/current source-shape support. It maps the target's three fixed-260 secure wide-format callsites.
  - `executed-b-agent-research/B007/0000W2-ZlibPublicCompressChecksum-source-quality.md`: incidental executed/current zlib support. It proves lowercase `compress` at `0x00414370` and the target call at `0x00504fea`.
  - `executed-b-agent-research/B009/0001AP-MapPaneWeatherCoordinateObjectCore-source-quality.md`: incidental executed/current range support. It records `sub_504E00` as the exact `0x275`-byte existing child.
  - `executed-b-agent-research/B009/00039S-ScreenPanePresentationModeFlagSetters-source-quality.md`: incidental executed/current exit-route support. It verifies presentation disable follows save and precedes SaveUserSettings; no direct save-body evidence.
- Conclusion: no prior standalone direct UID0002QK report exists. UID0002QJ and the historical MapPane family report provide useful support, but neither closes this assignment's direct writer/failure/free-clear/monster-cache/source-body questions.

## Target

- Target UID: `0002QK`.
- Target path: `by-memory/0x00504e00-0x00505075.MapPaneSaveCompressedMapFile.md`.
- Source queue/report row: current `auto-generated/-ag-research-tracker.md` by-memory Not-Covered Reconstructable row, `86/90`, average `88.0`, reconstructable true, direct-report count `0` at evidence time.
- Assignment-time supervisor classification: direct audit of the first actual UID0002QK empty emitter, distinct from paired UID0002QJ research.
- Current scores and parent state: `92/94`, canonical owner/emitter UID00007Q MapPane, reconstructable true, blank position, Destination 1 formal body, `Nested:0`.

## Current Target State

- Current metadata preserves exact `[0x00504e00,0x00505075)`, MapPane ownership/emission, reconstructability, blank source position, and `Nested:0`; only the accepted scores changed to `92/94`.
- The source-facing name `MapPaneSaveCompressedMapFile` and exact Destination 1 body are applied and agree with all four caller docs and paired `LoadCompressedMapFile`.
- Current target prose records the exact bytes/hash/instruction/CFG evidence, CMAP, two 16-bit dimensions, six-byte tile rows, direct CRT output, lowercase zlib `compress`, ignored ordinary results, all failure exits, tile-buffer release, local AUTOBUF lifetime, and monster-cache clearing.
- The prior AUTOBUF/output-capacity/return/failure/helper/formal blockers are preserved as superseded history. Current support declarations and the exact callback body resolve them without adding compiler lowering.
- The prior phrase `successful write path` is explicitly superseded. Once `_wfopen` succeeds, the ordinary non-throwing body ignores all subsequent `fwrite`, `compress`, and `fclose` results and still frees/nulls `m_tileBuffer`, releases local compressed storage, and clears monster loaded data. Only pre-open ordinary failures retain the buffer and skip the clear, except the null-buffer entry path, which clears monster data without file work. An allocation exception from `_AUTOBUF::Resize` unwinds the automatic buffer but leaves the raw stream and receiver tile storage intact and skips monster clear; the source's lexical scope and raw `FILE *` reproduce that exceptional consequence without handwritten EH.
- Related target/support docs checked: UID0002QJ, UID0004PZ, UID00007Q, UID0000L3, UID00037X, UID0003TK, UID0002QF, UID0002QH, UID0001AT, UID0001AW, UID00042K MapPaneLayout, UID0004HP MapPaneTileRecord, AUTOBUF template/class/file and Resize, zlib, WideApi dispatch, CMAP signature/global storage, MonsterImageLib class/file/global/clear method, resource strings, generated MapPane.cpp, tracker, and manual memory/class/file coverage rows.
- Current artifact/lifecycle status: the accepted callback and narrow Gate 2 consistency repair are applied. Final waited validator command `000000011921` generated exactly one UID0002QK definition and no UID0002QK empty emitter marker. UID0000L3 now treats B004's former blank-formal follow-up status as historical and explicitly superseded by the later source-ready UID0002QK callback.

## Executive Recommendation

- UID0002QK remains directly owned/emitted by UID00007Q MapPane in `NexusTK/map/MapPane.cpp` and now reconstructs as `void MapPane::SaveCompressedMapFile()`.
- Only UID0002QK changed from `86/90` to `92/94`; UID/path/title/range, `RECONSTRUCTABLE:TRUE`, owner/emitter UID00007Q, blank position, and `Nested:0` remain unchanged.
- Destination 1 replaced the blank target formal body exactly. No child, split, aggregate conversion, new UID, third-party import, or covered-by route was introduced.
- UID00007Q and UID0000L3 are synchronized at unchanged scores/formal policy with the exact save behavior, source dependencies, and paired-load distinction.
- UID00037X and UID0003TK are synchronized at unchanged metadata/formals with their exact conditional callsites and ignored return. Existing teardown callers UID0002QF/UID0002QH and broad caller aggregates UID0001AT/UID0001AW remain verify-only.
- All direct support pages and scores were reread. One out-of-scope verify-only contradiction remains in UID0001PN: its current storage-page prose claims caller `0x0050504e` checks the MonsterImageLib singleton, while exact disassembly performs an unconditional load/call. The accepted five-page write cap excluded that page; the target and generated body correctly preserve the unconditional call.

## Supervisor Active Recheck

- The supervisor assigned UID0002QK because UID0002QJ used save only as paired evidence and explicitly left the direct writer/failure/free-clear/monster-cache/source-body audit incomplete.
- No split repair is required. Target bounds are exact and bounded by alignment padding on both sides.
- The sole source-bearing body in scope is applied from Destination 1. All support destinations received the accepted bounded prose synchronization or were reread as verify-only dependencies; no child/source body was deferred.

## Inference Research Guidance Check

- The project inference rules require binary facts, documentation facts, and source-facing inference to remain distinct. Exact instructions, branches, callsites, offsets, constants, xrefs, and bytes below are IDA facts. Existing names and declarations are documentation evidence. Human private names and source syntax are ranked inferences where original symbols are absent.
- Historical assumptions treated as uncertain were IDA's `FILE *__thiscall(int)` return, a success-only cleanup description, a possible StdioFile rewrite, unresolved AUTOBUF declaration style, uppercase `Compress`, alternate field aliases, and the possibility that the body belonged to zlib/PlatformApi/MonsterImageLib.
- Current direct evidence rejects all of those blockers. Caller EAX non-use and plain `ret` support `void`; the save body uses direct CRT; current project declarations supply `_AUTOBUF<unsigned char>`, `Resize`, canonical fields, lowercase `compress`, WideApi names, and `ClearLoadedData`.
- No current explicit Wave2/Wave3 override was found. Historical Wave2/Wave3 artifacts were ignored as stale routing authority.

## Heuristic / Inference Reanalysis And Validation

- **Method name:** `SaveCompressedMapFile` is highest probability from the existing target, four source-facing callers, exact paired `LoadCompressedMapFile`, and generated callsites. `SaveMapToFile`, `WriteCompressedMapCache`, and `SaveCmap` are descriptive alternatives with weaker project evidence.
- **Signature and return:** there are no explicit stack arguments and the method returns with plain `ret`. All four callers ignore EAX. IDA's `FILE *` is last-callee residue, not a semantic return. Best source signature is `void MapPane::SaveCompressedMapFile()`.
- **Receiver fields:** `+0x3f2/+0x3f4/+0x3f6/+0x3f8` are canonical `m_mapId`, `m_mapWidth`, `m_mapHeight`, and `m_tileBuffer`. UID0002QJ/UID0004PZ/MapPaneLayout/MapPaneTileRecord and save/load machine access agree. Later aliases `m_mapWidthTiles`, `m_mapHeightTiles`, and `m_mapTileRecords` are superseded, not parallel members.
- **Tile type and raw size:** width and height are unsigned 16-bit fields. The raw payload is exactly `sizeof(MapPaneTileRecord) * width * height`, where the accepted record is six bytes. A four-byte map-image tile type is rejected by exact multiplication and current struct evidence.
- **Path/source helpers:** three fixed-260 secure formatting sites match the accepted UID0002UA source shape. `g_pfnCreateDirectoryW` and `g_pfnWideOpenFile` are current PlatformApi dispatch names. Rewriting to StdioFile is rejected because target instructions directly call the `_wfopen` slot and CRT writes/close.
- **Header:** the first three writes are exactly four bytes from `g_mapPaneCmapSignature`, then two bytes each from `m_mapWidth` and `m_mapHeight`. No NUL, version, compressed-size prefix, checksum, or record count is written.
- **Compression buffer:** the machine body constructs a local `_AUTOBUF<unsigned char>`, computes `rawSize * 11 / 10 + 12`, resizes it, and passes its storage/count to lowercase zlib `compress`. This is the standard conservative zlib capacity formula present in the binary, not an inferred `compressBound` call.
- **Compression result:** `compress` status is ignored. Its in/out length is used as the payload `fwrite` count. Adding an error branch, retry, zero-length guard, or rollback would change behavior.
- **CRT results:** all header/payload `fwrite` results and `fclose` are ignored. A stream that opened reaches release/null/cache-clear even after a short write, compression error, or close error. Source must not gate cleanup on success.
- **Failure matrix:** null `m_tileBuffer` skips all file work and calls `ClearLoadedData`; SHGetFolderPath failure, either directory-creation failure other than already-exists, and open failure return with the buffer retained and no monster clear; after open, every ordinary CRT/zlib result reaches free/null/local-buffer release/clear. If `Resize` allocation throws, compiler-generated unwind releases the automatic compressed buffer while the raw stream remains open, `m_tileBuffer` remains owned by the receiver, and monster clear is skipped. This exact asymmetry supersedes the vague successful-path wording.
- **Ownership:** MapPane owns the receiver state, path/map identity, cache format integration, and four class callers. PlatformApi, zlib, AUTOBUF, CRT, MapPaneTileRecord, and MonsterImageLib are dependencies, not direct owners.
- **Compiler mechanics:** SEH registration, cookie checks, CxxFrameHandler3, local destructor lowering, allocator thunks, and cleanup chunks are compiler output. A lexical scope places automatic `_AUTOBUF` destruction after tile free/null and before monster clear on the ordinary path, while naturally preserving Resize-exception cleanup; explicit handlers/cookies/thunks must not be handwritten.
- **Range:** exact function end is `0x00505075`; predecessor and successor are pure `0xCC` alignment. No tail, switch table, raw helper, or child belongs inside the method page.
- **Score blockers:** exact ABI, fields, types, globals, helper names, failures, output layout, ownership, source file, caller routes, and C++ are closed. Only unrecoverable original lexical spelling and absent original PDB/source cap the target below `95/95`.

Rejected alternatives:

- `FILE *` return: rejected by caller non-use and control-only exits.
- StdioFile save implementation: rejected by direct `_wfopen`/`fwrite`/`fclose` calls.
- Save only on successful writes: rejected because no post-open status branch exists.
- Free/null on all failures: rejected by pre-open return branches.
- Skip monster clear when tile storage is null: rejected by the direct null branch to `ClearLoadedData`.
- `compressBound`: rejected because binary performs explicit `11/10 + 12` arithmetic.
- Handwritten SEH/cookies/operator thunks: rejected as compiler lowering.
- zlib, PlatformApi, AUTOBUF, CRT, or MonsterImageLib ownership: rejected as dependency/consumer relationships.
- Split/aggregate/no-code/covered-by disposition: rejected because one exact source-authored method occupies the range and all source blockers are closed.

## Evidence Standards Used

- Direct evidence: fresh IDA MCP target bytes/hash, exact function bounds, compact/full disassembly, decompilation, basic-block graph, call graph, four xrefs/callsite windows, helper analysis, constants/strings, global xrefs, and adjacent padding.
- Corroborating evidence: current by-* metadata and accepted formals for MapPane, MapPaneTileRecord, AUTOBUF, zlib, PlatformApi dispatch, CMAP, MonsterImageLib, callers, and paired load.
- Generated/queue evidence: current generated MapPane.cpp empty marker/callers, tracker row, and current manual coverage rows read-only.
- Negative evidence: no explicit arguments, no meaningful EAX consumer, no status branches after open, no size/version/checksum writes, no raw successor inclusion, no additional local function start, and no source symbol inside the target range.
- The evidence ladder supports exact behavior and source shape at very-strong confidence. Binary context cannot recover original private lexical spellings, so naming confidence remains bounded rather than asserted as proof.

## Evidence Checked

- IDA MCP/manual-disassembly/raw-byte checks: `initialize`; fresh and final `idb_list`; `server_health`; `lookup_funcs`; `analyze_function`; `decompile`; `disasm`; `basic_blocks`; `callers`; `callees`; `xrefs_to`; `get_bytes`; `get_int`; bounded entity/name checks; helper analysis for zlib `compress`, AUTOBUF ctor/dtor lowering, and MonsterImageLib clear; target caller instruction windows.
- by-* and support docs: all target/class/file/type/global/helper/caller pages listed in Current Target State, with exact target/class/file manual coverage rows and current generated/tracker state.
- Old reports: every target-relevant match listed under Supporting Research was opened; active, Older-Research, SpecialReports, and archived roots had no direct report match.
- Negative checks: no extra function starts or names in range, no raw successor code, no caller return consumption, no post-open status test, no extra header fields, no StdioFile call, no direct helper ownership transfer, and no third-party implementation body.
- Failed/unavailable/intentionally skipped checks: no valid bounded MCP call failed. The malformed missing-database client batch is documented above. IDA mutation and lifecycle/report commands remained forbidden. The historical report-only pass ran no validator; the accepted callback ran scoped commands `000000011877`, `000000011878`, `000000011881`, `000000011884`, `000000011889`, and waited refresh `000000011892`; the narrow Gate 2 repair then ran scoped command `000000011920` and final waited refresh `000000011921`.

## Claim And Incorporation Ledger

| Claim ID | Claim | Confidence | Evidence | Destination doc/section | Action | Verification state |
| --- | --- | ---: | --- | --- | --- | --- |
| C01 | UID0002QK is exact `[0x00504e00,0x00505075)`, 629 bytes, SHA-256 `595B2258168B19996F00835595DA04821ED0E043FB58082639C605D8FAEAF1BD`. | 100 | MCP bytes/lookup | UID0002QK range/evidence | incorporate | applied |
| C02 | Fifteen predecessor and eleven successor `CC` bytes are alignment excluded from the target. | 100 | MCP bytes/hashes | UID0002QK range/padding | incorporate | applied |
| C03 | Main body has 171 instructions; analysis has 15 blocks/complexity 6 including compiler cleanup/EH chunks. | 99 | disasm/basic_blocks/analyze | UID0002QK CFG/compiler evidence | incorporate | applied |
| C04 | Exact callers are `0x50458b`, `0x50483e`, `0x50bbe7`, `0x510671`; each ignores EAX. | 100 | xrefs/caller windows | target and caller docs | incorporate | applied |
| C05 | Best human signature is `void MapPane::SaveCompressedMapFile()`; IDA `FILE *` is residue. | 99 | ABI/ret/caller non-use | UID0002QK formal/ABI | incorporate | applied |
| C06 | Null `m_tileBuffer` skips file work and still clears MonsterImageLib loaded data. | 100 | direct branch/call | UID0002QK behavior/formal | incorporate | applied |
| C07 | SHGetFolderPathW failure returns with buffer retained and no monster clear. | 100 | direct branch | UID0002QK failure matrix | incorporate | applied |
| C08 | Both directory gates accept success or ERROR_ALREADY_EXISTS; other errors retain buffer and skip clear. | 100 | direct branches/constants | UID0002QK failure matrix/formal | incorporate | applied |
| C09 | Path is `Documents\NexusTK\Maps\TK%06d.cmp`, keyed by unsigned 16-bit `m_mapId`. | 100 | strings/field load/format calls | target/class/file | incorporate | applied |
| C10 | Save opens through `g_pfnWideOpenFile`/`_wfopen` with `L"wb"`; null stream retains state and returns. | 100 | indirect call/slot/mode/branch | target/class/file | incorporate | applied |
| C11 | Header write 1 is exactly four CMAP bytes with no NUL. | 100 | fwrite arguments/data xref | target/formal | incorporate | applied |
| C12 | Header writes 2/3 are exactly two bytes each from width and height. | 100 | fwrite arguments/offsets | target/formal | incorporate | applied |
| C13 | Raw size is six-byte `MapPaneTileRecord` count times 16-bit width/height. | 100 | multiplication/type/paired docs | target/class/file | incorporate | applied |
| C14 | Local output storage is `_AUTOBUF<unsigned char>` grown through accepted `Resize`. | 98 | ctor/vtable/resize/dependency docs | target/formal | incorporate | applied |
| C15 | Output capacity is exact 32-bit `rawSize * 11 / 10 + 12`, not `compressBound`. | 100 | instruction sequence | target/formal/negative | incorporate | applied |
| C16 | Lowercase zlib `compress` is called and its status is ignored. | 100 | helper analysis/xref | target/formal | incorporate | applied |
| C17 | Payload write uses mutated compressed length; `fwrite` result is ignored. | 100 | direct instructions | target/formal/failure | incorporate | applied |
| C18 | `fclose` result is ignored and there is no rollback/remove path. | 100 | direct instructions/negative call graph | target behavior/formal | incorporate | applied |
| C19 | Any opened-stream ordinary CRT/zlib outcome frees/nulls `m_tileBuffer`. | 100 | branch/liveness path | target behavior/formal | incorporate | applied |
| C20 | The ordinary path then releases local compressed storage before calling `g_pMonsterImageLib->ClearLoadedData()`. | 100 | end-of-body instruction order/callee analysis | target behavior/formal | incorporate | applied |
| C21 | Pre-open failures retain tile storage and skip monster clear except the null-buffer clear path; a Resize exception unwinds only automatic compressed storage, leaving the raw stream/tile/cache state uncleared. | 100 | complete CFG/EH cleanup | target Item Summary/failure table | incorporate | applied |
| C22 | Partial/truncated files may remain; no write/compress/close error gate or rollback exists. | 100 | negative branches/callees | target negative/history | incorporate | applied |
| C23 | SEH, cookie, CxxFrameHandler3, cleanup chunks, and thunks are compiler-only. | 100 | instructions/basic blocks | target/formal negative | incorporate | applied |
| C24 | Canonical fields are `m_mapId`, `m_mapWidth`, `m_mapHeight`, `m_tileBuffer`; later aliases are superseded. | 99 | paired docs/offset consumers | target/class/file | incorporate | applied |
| C25 | Save is direct CRT/compress/free-clear; load remains StdioFile/uncompress/allocation and is not merged. | 100 | both exact bodies/docs | target/class/file | incorporate | applied |
| C26 | Owner/emitter is UID00007Q; source file is UID0000L3 `NexusTK/map/MapPane.cpp`. | 99 | receiver/callers/source graph | target/class/file | already-present | already-present |
| C27 | Raise target only `86/90 -> 92/94`, keep other metadata, and apply Destination 1. | 98 | blocker closure/score standard | UID0002QK header/formal | incorporate | applied |
| C28 | Synchronize MapPane class/file prose; preserve `89/89`, `89/85`, paths, and blank formal policies. | 99 | current support audit | UID00007Q/UID0000L3 | incorporate | applied |
| C29 | Add exact save call condition/no-return facts to UID00037X and UID0003TK; preserve scores/formals/routes. | 99 | caller windows/current docs | UID00037X/UID0003TK | incorporate | applied |
| C30 | Verify-only dependencies were reread; accepted contracts are current except UID0001PN's stale caller-null-check sentence, which contradicts the unconditional `0x0050504e` load/call and lies outside the exact five-page write cap. | 98 | support reread/exact caller disassembly | listed verify-only docs and follow-up | already-present | excluded-with-reason |
| C31 | Historical save blockers, success-only wording, and B004's former UID0002QK blank-formal follow-up status are superseded but preserved as rejected history. | 99 | old/current report comparison | target/class/file changes | historicalize | applied |
| C32 | No split/new child/UID/nesting/range or ignored-padding change is needed. | 100 | exact bounds/function map | target metadata | already-present | already-present |
| C33 | Generated MapPane.cpp contains one target definition and no UID0002QK empty marker or compiler-shaped source. | 99 | waited generated readback | final generated verification | incorporate | applied |
| C34 | Supply exact supervisor-owned target/class/file/caller manual coverage text; never edit coverage manually. | 100 | current manual rows | coverage text section | incorporate | applied |
| C35 | No third-party import, IDA mutation, report lifecycle action, or report-only validator applies. | 100 | source ownership/workflow | report/checklist | not-applicable | excluded-with-reason |

### Callback Verification Notes

| Claim | Destination-specific callback proof |
| --- | --- |
| Claims C01-C03 | UID0002QK now contains the exact range/hash/padding/instruction/CFG/compiler evidence; scoped validator `000000011877` returned exit `0`, `ok:1`. |
| Claim C04 | UID0002QK records all four non-use callsites; UID00037X command `000000011884` records `0x0050bbe7`, and UID0003TK command `000000011889` records `0x00510671`. |
| Claims C05-C08 | UID0002QK's ABI, Item Summary, failure table, and exact Destination 1 implement void/no-arg, null-buffer clear, SHGetFolderPathW failure, and both directory gates; `000000011877` passed. |
| Claims C09-C13 | UID0002QK, UID00007Q, and UID0000L3 record the path, unsigned map id, WideApi `_wfopen`, CMAP/dimension header, six-byte records, and raw size; commands `000000011877`, `000000011878`, and `000000011881` passed. |
| Claims C14-C18 | UID0002QK's formal and evidence record `_AUTOBUF<unsigned char>::Resize`, exact capacity, lowercase `compress`, mutated payload length, ignored writes/close, and no rollback; `000000011877` passed. |
| Claims C19-C23 | UID0002QK records ordinary free/null/local-release/cache-clear ordering, complete pre-open and Resize-exception state, partial-file risk, and compiler-only lowering; `000000011877` passed and `000000011892` generated no compiler-shaped source. |
| Claims C24-C25 | UID0002QK/UID00007Q/UID0000L3 use canonical fields and preserve the direct-CRT save versus StdioFile load distinction; `000000011877`, `000000011878`, and `000000011881` passed. |
| Claim C26 | UID00007Q ownership/emission and UID0000L3 `NexusTK/map/MapPane.cpp` routing were already present and remain unchanged after all scoped validators. |
| Claim C27 | UID0002QK alone is `92/94`; all other metadata is preserved and Destination 1 matches the accepted report block byte-for-byte. Validator `000000011877` passed. |
| Claim C28 | UID00007Q remains `89/89` with blank class formal after `000000011878`; UID0000L3 remains `89/85` with unchanged path/formal policy after `000000011881`. |
| Claim C29 | UID00037X remains `85/89`, blank formal/Item Summary, `Nested:8` after `000000011884`; UID0003TK remains `86/90`, blank formal/Item Summary, `Nested:8` after `000000011889`. Both now link the exact conditional void save call. |
| Claim C30 | Every listed dependency was reread without edit. UID0001PN's stale null-check prose was discovered but excluded because the callback authorizes exactly five ordinary pages; exact target/generated source remains unconditional. |
| Claim C31 | Target/class/file pages preserve the old blank-formal and success-only assumptions as explicitly superseded history. Gate 2 repair validator `000000011920` confirms UID0000L3 now states that B004 historically left UID0002QK pending and that Agent-B005's later source-quality callback superseded that status with the source-ready body and no-marker generated result. |
| Claim C32 | UID0002QK retains exact range, blank position, `Nested:0`, and has no child/new UID; adjacent/ignored pages were verify-only. |
| Claim C33 | Final waited command `000000011921` completed; current generated SHA-256 is `1AC07C9EBDBD161DD412013A11F48E131E3852B1EC822A88E03AFCFAF369E19A`: one save, one load, one allocator, two unchanged emitting caller calls, zero UID0002QK empty markers, and zero `compressBound`, StdioFile-save, cookie, CxxFrameHandler, or EH-handler occurrences. |
| Claim C34 | Exact supervisor-owned replacement/addition text below is preserved; B005 did not edit any manual coverage file. |
| Claim C35 | Third-party import and IDA mutation do not apply; execute/probe/move/archive/lifecycle commands were prohibited and not run. |

## Positive Evidence Summary

- Exact target bytes, hash, function size, instruction count, CFG, and padding establish one complete source-authored method.
- Four exact MapPane callsites, receiver-field accesses, paired load naming, and source graph establish class/file ownership and void member signature.
- Direct instructions establish every path/header/compression/write/close/free/null/cache operation and every failure branch.
- Accepted project declarations close the prior source-shape blockers for MapPane fields, six-byte tile rows, AUTOBUF Resize/storage, zlib names/types, WideApi dispatch names, CMAP signature, and MonsterImageLib clear.
- The strongest inference chain is exact machine behavior plus current source-family declarations plus four caller non-use windows. End-of-body disassembly additionally fixes the RAII scope order: receiver tile free/null, local compressed-buffer release, then monster clear. This is sufficient for human C++ without reproducing decompiler labels or compiler lowering.

## IDA MCP Facts

- Function/range facts: `sub_504E00`, start `0x00504e00`, size `0x275`, end-exclusive `0x00505075`; 171 instructions; 15 analyzed blocks; cyclomatic complexity 6.
- Data/table/padding facts: predecessor `[0x00504df1,0x00504e00)` is 15 `CC`; successor `[0x00505075,0x00505080)` is 11 `CC`; `0x0061e6f0` begins `43 4D 41 50`; `0x0060df28` is UTF-16 `wb`; `0x0066db48` stores pointer `0x0061e6f0`.
- Xref facts: four exact code refs to target; two refs to `0x0066db48` are paired load/save; path strings have paired load/save refs; zlib `compress` has target plus one unrelated raw caller; Monster clear has destructor/scalar-delete/target refs.
- Vtable/global/type facts: target uses established MapPane offsets `+0x3f2/+0x3f4/+0x3f6/+0x3f8`, WideApi slots `0x0069be14` and `0x0069be5c`, global `g_pMonsterImageLib` at `0x0069b440`, local AUTOBUF vtable lowering, and accepted six-byte tile type.
- Negative IDA facts: no local names/symbols in target range, no explicit parameters, no meaningful return consumer, no extra local function start, no post-open status branch, no rollback/delete-file call, no header length/version/checksum, and no source reason to include EH/cookie chunks.

## Exact Byte Inventory

| Range | Length | SHA-256 | Disposition |
| --- | ---: | --- | --- |
| `[0x00504df1,0x00504e00)` | 15 | `54CC9DD9593316E80CCAF5D10856E6502A0D75F20473A92FA01D63228EF1624C` | predecessor alignment; excluded |
| `[0x00504e00,0x00505075)` | 629 | `595B2258168B19996F00835595DA04821ED0E043FB58082639C605D8FAEAF1BD` | UID0002QK exact source body |
| `[0x00505075,0x00505080)` | 11 | `3682C0A62515050101266CC639BF81F5D8C5395F49E7DA93FCC22603018E0943` | successor alignment; excluded |

Target head begins `55 8B EC 6A FF 68 AA 22 60 00 64 A1 00 00 00 00 50 81 EC 34 06 00 00 A1 24 2F 67 00 33 C5 89 45`; the body ends with normal frame/cookie restoration and plain `C3` return. The byte identity matches the paired UID0002QJ callback's support hash.

## Function / Child Inventory

| Range / Item | UID / Path | Role | Reconstructable | Direct Parent | Score | Status |
| --- | --- | --- | --- | --- | --- | --- |
| `[0x00504e00,0x00505075)` | UID0002QK target | complete save method | true | UID00007Q | `86/90 -> 92/94` | Destination 1 |
| `[0x00504df1,0x00504e00)` | ignored alignment | predecessor padding | false | none | n/a | preserve ignored |
| `[0x00505075,0x00505080)` | ignored alignment | successor padding | false | none | n/a | preserve ignored |
| `0x00414370` | UID0000W2 support | zlib `compress` wrapper | support | zlib file | unchanged | verify-only |
| `0x004f4a80/0x004f4a90` | AUTOBUF support | inlined local ctor/dtor lowering | support | AUTOBUF | unchanged | verify-only |
| `0x004dc2e0` | MonsterImageLib support | `ClearLoadedData` | support | MonsterImageLib | unchanged | verify-only |

No child page, split, aggregate conversion, or new UID is required.

## Direct Xref / Caller Inventory

| Address / Item | Xref / Caller / Callee | Meaning |
| --- | --- | --- |
| `0x0050458b` | UID0002QF MapPane cleanup | saves before later member teardown; next instruction reads `this+0x41c`; EAX ignored |
| `0x0050483e` | UID0002QH exit-to-menu teardown | saves before ScreenPane disable/removal flow; EAX ignored |
| `0x0050bbe7` | UID00037X map-change core | called only when incoming map id differs; then configuration/state work continues; EAX ignored |
| `0x00510671` | UID0003TK effect/map-state packet | called only when packet map id differs; then configuration/state work continues; EAX ignored |
| `0x00504fea` | zlib `compress` | output pointer, in/out length, tile buffer, raw size; status ignored |
| `0x0050504e` | `g_pMonsterImageLib` virtual/direct method route | enters exact `ClearLoadedData` body at `0x004dc2e0` |

## Documentation Evidence And IDA Status

- At report-only evidence collection, UID0002QK already had exact range/hash, owner, field vocabulary, format, paired distinction, and broad cleanup facts, but its then-blank formal and incomplete failure/source audit were stale. The completed callback replaced that historical blank state with Destination 1 and the full source-ready failure/source audit.
- UID0002QJ and UID0004PZ supply current canonical fields, exact six-byte type, AUTOBUF use, and paired load/allocation distinction without owning the save body.
- At that evidence-time baseline, UID00007Q and UID0000L3 correctly owned/routed MapPane source but described UID0002QK only as paired evidence or blank-formal follow-up work. The completed callback superseded that baseline: both current class/file docs now describe the source-ready save body, and UID0000L3 explicitly preserves B004's pending status only as history.
- At the same baseline, UID00037X and UID0003TK named only `0x504e00`/save among larger flows and omitted the exact branch condition and ignored return. The completed bounded synchronization now records those facts while preserving both pages' broader unresolved scope.
- The evidence-time generated snapshot from validator command `000000011829`, refreshed `2026-07-14T16:26:50-04:00`, SHA-256 `57ED01D5368A0575FE04EB248E5DFC7BA9D50678E9F8270416AD50EBCAC62117`, contained existing `SaveCompressedMapFile();` calls at lines 179/272 and one UID0002QK Empty Emitter Marker at line 1525. Final callback refresh `000000011921` superseded that snapshot with one UID0002QK definition and no UID0002QK empty marker.
- Evidence-time tracker row 1576 listed `86/90`, average `88.0`, reconstructable true, and zero direct reports. Those values are historical collection facts, not permanent lifecycle assertions; this report did not manually change tracker state.

## Ranked Ownership Analysis

### 1. UID00007Q MapPane in UID0000L3 MapPane.cpp

- Evidence for: `this` fields are canonical MapPane state; all four callers are MapPane methods; paired load and allocator are MapPane; path/map identity and final cache invalidation serve MapPane lifecycle.
- Evidence against: no original symbol/PDB survives. This limits spelling confidence only, not owner identity.
- Decision: direct canonical owner/emitter UID00007Q and source file UID0000L3.

### 2. PlatformApi / WideApi dispatch

- Evidence for: target consumes process-wide directory and wide-open function pointers.
- Evidence against: dispatch initialization is centralized and shared across many modules; target owns path policy, format, tile state, and cleanup.
- Decision: dependency only; reject direct ownership.

### 3. zlib, AUTOBUF, CRT, or MonsterImageLib

- Evidence for: target calls or instantiates each support family.
- Evidence against: none owns receiver fields, cache path/header policy, caller route, or complete method behavior. MonsterImageLib is only the final invalidation consumer.
- Decision: dependencies only; reject owner/emitter transfer and third-party import.

### Proposed new file/grouping, if applicable

- Not applicable. Existing `NexusTK/map/MapPane.cpp` is the exact narrow source root; no new file or grouping is justified.

## Source Placement

- Recommended placement: class method emitted through UID00007Q into UID0000L3 `NexusTK/map/MapPane.cpp`, in established address/source order after `LoadCompressedMapFile` and before later MapPane helper families.
- This placement matches paired load, lifecycle callers, field ownership, map-cache resource strings/globals, and current generated file routing.
- Rejected placements: StdioFile/PathUtil because save owns direct integration policy; PlatformApi because dispatch entries are shared; zlib because only API use occurs; MonsterImageLib because only final invalidation is called; AUTOBUF because it is local storage support.
- Remaining placement uncertainty: none affecting emission. Exact original include ordering is not recoverable and does not block source body reconstruction.

## Range / Split / Padding / Reclassification Analysis

- Exact range is one IDA function `[0x00504e00,0x00505075)` with no internal secondary function start or owned data island.
- Predecessor `[0x00504df1,0x00504e00)` and successor `[0x00505075,0x00505080)` are pure alignment and remain ignored outside the target.
- No child page, helper split, merge, nesting delta, parent aggregate conversion, raw successor, or reclassification is required.
- Parent/class/file inventory remains unchanged except bounded source-readiness prose.

## Negative Evidence Summary

- No direct evidence supports `FILE *` return, explicit parameters, StdioFile use, success-gated ordinary cleanup, save-result propagation, compressed-size header, version/checksum, rollback, file deletion, retry, pre-open buffer disposal, or an added null global guard. Conversely, no raw-file RAII exists: a Resize allocation exception does not close the stream or run receiver cleanup.
- No target instruction supports uppercase `Compress`, `compressBound`, newer field aliases, four-byte tile rows, a standalone cache manager owner, or a zlib/PlatformApi/MonsterImageLib method.
- Consumer calls and nearby helpers do not transfer ownership. The exact MapPane receiver and four MapPane callsites outweigh adjacency or dependency labels.
- Compiler cleanup/EH blocks do not justify source-level handlers, cookies, explicit AUTOBUF destructor calls, allocator thunks, or handwritten return mechanics.
- No current direct report exists, and prior historical blocker text cannot be treated as proof that C++ remains unsafe after current helper/type declarations were checked.

## IDA Rename / Type / Comment Recommendations

- Source-facing function: `MapPane::SaveCompressedMapFile`, return `void`, no explicit arguments.
- Source-facing members: `m_mapId` (`unsigned short`), `m_mapWidth` (`unsigned short`), `m_mapHeight` (`unsigned short`), `m_tileBuffer` (`MapPaneTileRecord *`).
- Source-facing globals/dependencies: `g_pfnCreateDirectoryW`, `g_pfnWideOpenFile`, `g_mapPaneCmapSignature`, `g_pMonsterImageLib`, `_AUTOBUF<unsigned char>`, lowercase zlib `compress`.
- Descriptive locals in Destination 1: `documentsPath`, `mapDirectory`, `cachePath`, `cacheFile`, `tileDataSize`, `compressedMap`, `compressedSize`.
- Items intentionally unchanged: IDA database names/types/comments. No IDA mutation is requested; project documentation and formal reconstruction are sufficient.

## First-Draft C++ Recommendation

- Eligible for draft C++: yes. Exact behavior, ABI, dependencies, and source-facing names clear the source-quality gate.
- Destination 1: `by-memory/0x00504e00-0x00505075.MapPaneSaveCompressedMapFile.md`.

*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
void MapPane::SaveCompressedMapFile()
{
    if (m_tileBuffer == NULL)
    {
        g_pMonsterImageLib->ClearLoadedData();
        return;
    }

    wchar_t documentsPath[MAX_PATH];
    if (SHGetFolderPathW(NULL, CSIDL_PERSONAL, NULL, 0, documentsPath) != S_OK)
        return;

    wchar_t mapDirectory[MAX_PATH];
    swprintf_s(mapDirectory, L"%s\\NexusTK", documentsPath);
    if (!g_pfnCreateDirectoryW(mapDirectory, NULL) &&
        GetLastError() != ERROR_ALREADY_EXISTS)
        return;

    swprintf_s(mapDirectory, L"%s\\NexusTK\\Maps", documentsPath);
    if (!g_pfnCreateDirectoryW(mapDirectory, NULL) &&
        GetLastError() != ERROR_ALREADY_EXISTS)
        return;

    wchar_t cachePath[MAX_PATH];
    swprintf_s(cachePath, L"%s\\TK%06d.cmp", mapDirectory, m_mapId);

    FILE *cacheFile = g_pfnWideOpenFile(cachePath, L"wb");
    if (cacheFile == NULL)
        return;

    uLong tileDataSize =
        sizeof(MapPaneTileRecord) * m_mapWidth * m_mapHeight;

    fwrite(g_mapPaneCmapSignature, 1, 4, cacheFile);
    fwrite(&m_mapWidth, 1, sizeof(m_mapWidth), cacheFile);
    fwrite(&m_mapHeight, 1, sizeof(m_mapHeight), cacheFile);

    {
        _AUTOBUF<unsigned char> compressedMap;
        uLongf compressedSize = tileDataSize * 11 / 10 + 12;
        compressedMap.Resize(compressedSize);

        compress(
            compressedMap.m_data,
            &compressedSize,
            reinterpret_cast<const Bytef *>(m_tileBuffer),
            tileDataSize);

        fwrite(compressedMap.m_data, 1, compressedSize, cacheFile);
        fclose(cacheFile);

        delete [] m_tileBuffer;
        m_tileBuffer = NULL;
    }

    g_pMonsterImageLib->ClearLoadedData();
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

- Reason it preserves exact original behavior: it keeps every pre-open branch, null-buffer cache clear, exact path/header/size/capacity/compression/write order, ignored ordinary results, post-open free/null then automatic local-buffer release then cache clear, and the Resize-exception raw-stream/receiver-state consequence without adding rollback, status gates, or handwritten EH.
- Reason it matches plausible late-1999 through mid-2000s source: it uses accepted project field/global/helper names, Win32/CRT APIs, fixed MAX_PATH arrays, `_AUTOBUF`, bundled zlib types, ordinary RAII, and direct member source rather than decompiler locals or generated mechanics.
- Naming/coding style: matches the accepted paired UID0002QJ body and current project formals.
- Third-party import directive: not applicable. This is NexusTK integration code that calls zlib; it is not a vetted static third-party implementation embed.
- Exact no-code proof: not applicable because the target is source-bearing and implementation-ready.

## Final Recommendation

- C01-C35 and Destination 1 were applied or explicitly excluded with reason after supervisor acceptance.
- UID0002QK is `92/94`; owner/emitter UID00007Q, reconstructable true, blank position, exact range/path/title, and `Nested:0` remain unchanged.
- The target Item Summary now states the exact source-ready behavior, including null-buffer clear, pre-open retention/no-clear, and post-open unconditional free/null/clear despite ignored results.
- UID00007Q and UID0000L3 remain at unchanged scores/formals and now contain source-ready save semantics plus the direct-CRT versus StdioFile distinction.
- UID00037X and UID0003TK remain at unchanged metadata/formals and now contain the exact conditional callsites and ignored return.
- Listed support pages remained verify-only. UID0001PN's stale null-check sentence was documented and excluded under the exact five-page write cap; no child, third-party import, manual coverage edit, generated edit, or lifecycle command was introduced.
- No unresolved source-quality work remains inside UID0002QK. Broader UID00037X/UID0003TK body reconstruction is outside this bounded assignment and is not a save-method blocker.

## Recommended Target Doc Changes

- Target path: `by-memory/0x00504e00-0x00505075.MapPaneSaveCompressedMapFile.md`.
- Applied metadata: only `COMPLETION:92` and `CONFIDENCE:94` changed; UID, title, path, exact range, owner/emitter UID00007Q, `RECONSTRUCTABLE:TRUE`, blank position, and `Nested:0` are preserved.
- Exact Item Summary: `Source-ready MapPane compressed-map writer: clears monster loaded data immediately when no tile buffer exists; otherwise writes CMAP, 16-bit dimensions, and a zlib-compressed six-byte tile payload through direct CRT I/O, preserves tile/cache state on pre-open failures, and after any opened-stream write/compress/close result frees/nulls m_tileBuffer and clears monster loaded data.`
- Destination 1 replaced the blank formal block byte-for-byte.
- Exact bytes/hash/instructions/CFG/EH, all four callers and non-use, complete path/header/compression/CRT sequence, all ordinary failure exits plus Resize-exception cleanup, exact tile/local-buffer/cache ordering, dependencies, ownership/source placement, range/padding, negative evidence, and score rationale are applied and validated.
- The old incomplete-AUTOBUF/direct-CRT blocker and phrase `successful write path` are retained as superseded history: both were reasonable before the direct audit but are disproved by current declarations and exact CFG.

## Recommended Support Doc Changes

- `by-class/MapPane.md` (UID00007Q): applied and verified at unchanged `89/89`, owner/file route, fields, and blank complete-class formal. It now records source-ready `SaveCompressedMapFile` inventory; exact direct-CRT header/payload/failure/disposal/local-buffer/monster-clear behavior including the Resize exceptional consequence; paired StdioFile load contrast; four caller roles; and superseded blank-formal history.
- `by-file/MapPane.md` (UID0000L3): applied and verified at unchanged `89/85`, reconstruction path, file metadata, and formal policy. UID0002QK is now a source-ready exact child with source order after load, direct CRT and dependency/includes policy, ordinary and exceptional failure/disposal contract, generated one-definition/no-marker expectation, and superseded blocker history.
- `by-memory/0x0050b080-0x0050bcd8.MapPaneInteractionMapChangeCore.md` (UID00037X): applied and verified at unchanged `85/89`, owner/emitter, range, `Nested:8`, blank Item Summary/formal, and unresolved aggregate scope. It now states only that `0x0050bbe7` calls save when the incoming map id differs, ignores EAX/the void result, and continues configuration/state work before paired load.
- `by-memory/0x005104d0-0x00510958.MapPaneHandleEffectMapStatePacket.md` (UID0003TK): applied and verified at unchanged `86/90`, owner/emitter, range, `Nested:8`, blank Item Summary/formal, and unresolved packet names. Raw `sub_504E00` wording is replaced by the linked source-facing dependency, with exact `0x00510671` map-id-change condition, ignored return, and subsequent config/state work.
- Verify-only/no edit: UID0002QJ, UID0004PZ, UID0002QF, UID0002QH, UID0001AT, UID0001AW, UID00042K, UID0004HP, AUTOBUF class/template/file/constructor/Resize, UID0000W2 zlib, UID0000TQ/UID0002AS WideApi, UID0002ZJ/UID0002ZN CMAP, MonsterImageLib UID00008N class/UID0000LJ file/UID0000RR global/UID0001PN storage/UID00017C local clear cluster, cache resource strings, adjacent/ignored pages, tracker, generated output, and manual coverage. All accepted contracts were current except UID0001PN's stale assertion that `0x0050504e` null-checks the singleton; exact disassembly and current generated source show an unconditional call, and the page was excluded by the exact five-page write cap.

## Score And Metadata Recommendation

- Historical baseline target: `86/90`, UID00007Q owner/emitter, true, blank position/formal, `Nested:0`.
- Current applied target: `92/94`; all non-score metadata remains unchanged and Destination 1 replaces the blank formal.
- Completion rises by six because exact body/source syntax, every failure path, all CRT results, output capacity, AUTOBUF use, caller/return contract, buffer/cache lifecycle, dependency names, and generated expectation are now documented and implementation-ready.
- Confidence rises by four because exact bytes/CFG/callers and accepted support declarations converge on one behavior/owner/source shape. It remains below 95 because original private symbol/local spellings and original source are unavailable.
- Support scores/routes/formals remain unchanged: UID00007Q `89/89`, UID0000L3 `89/85`, UID00037X `85/89`, UID0003TK `86/90`.
- Score-improvement attempt:
  - Return/prototype blocker: caller windows and plain return resolve `void`, no arguments.
  - Direct-CRT failure blocker: full CFG resolves every pre/post-open branch and ignored result.
  - AUTOBUF blocker: current AUTOBUF declarations and target ctor/Resize/destructor lowering resolve source shape.
  - Fields/type blocker: paired load/helper/layout/struct resolve all offsets and six-byte record.
  - Global/helper blocker: WideApi, CMAP, zlib, and MonsterImageLib docs plus exact xrefs resolve names/routes.
  - Source placement blocker: four MapPane callers and existing class/file routing resolve emission.
  - Lexical blocker: exhaustive old-report/current-doc/IDA name search found no original symbol; this only caps confidence and does not justify blank C++.

## Open Questions With Attempted Resolution

- **Original method name?** Resolved to highest-probability `SaveCompressedMapFile`; no original symbol survives, so lexical confidence is capped but formal emission is safe.
- **Return type/arguments?** Resolved to `void` and no explicit arguments from plain `ret`, four non-use windows, and receiver-only ABI.
- **What is written?** Resolved exactly to four CMAP bytes, two 16-bit dimensions, and compressed six-byte tile payload; no other header fields exist.
- **How is output sized?** Resolved to explicit `raw * 11 / 10 + 12`, with zlib's in/out length mutated and used for payload write.
- **Which results gate cleanup?** Resolved: no ordinary CRT/zlib result after open. Pre-open failures retain and skip monster clear; null-buffer clears without I/O; ordinary post-open paths free/null/release-local/clear. A Resize allocation exception performs only automatic local cleanup and skips raw-stream close, receiver release, and monster clear.
- **Is direct CRT source-intentional?** Resolved by indirect `_wfopen` plus direct fwrite/fclose calls and absence of StdioFile methods.
- **Who owns clear behavior?** MapPane owns the call policy; MonsterImageLib owns `ClearLoadedData` implementation.
- **Split or helper child?** Rejected by one exact function and no internal source helper start.
- No evidence-backed unresolved question remains that blocks score, owner/emitter, source placement, range, or C++.

## Exact Manual Supervisor-Owned Coverage Or Tracker Text

- Current manual rows inspected: UID0002QK at `by-memory/-coverage-report.md:2198`; UID00007Q at `by-class/-coverage-report.md:302`; UID0000L3 at `by-file/-coverage-report.md:156`. UID00037X and UID0003TK have no current manual by-memory rows.
- Replace UID0002QK's current row with:

`        - [UID:0002QK][0x00504e00-0x00505075.MapPaneSaveCompressedMapFile](by-memory/0x00504e00-0x00505075.MapPaneSaveCompressedMapFile.md) 0x00504e00-0x00505075 | method | MapPaneSaveCompressedMapFile : reconstructable : 92% : very strong : Source-ready MapPane compressed-map writer with exact 629-byte hash/CFG and four void call routes; clears monster loaded data immediately when no tile buffer exists, otherwise writes CMAP plus two 16-bit dimensions and a six-byte-tile zlib payload through direct CRT I/O, preserves tile/cache state on pre-open failures, and after any opened-stream write/compress/close result frees/nulls m_tileBuffer and clears monster loaded data.`

- Replace UID00007Q's current row with:

`- [UID:00007Q][MapPane](by-class/MapPane.md) : reconstructable : 89% : very-strong : Live game-world pane class at unchanged 89/89 score/route and blank complete-class formal disposition, with source-ready compressed-map load/save methods, exact private tile-buffer allocation contract, canonical map id/width/height/tile fields and six-byte tile type, exact direct-CRT save failure/disposal/monster-cache behavior, packet/render/weather/object families, and TimerPane dependency synchronization.`

- Replace UID0000L3's current row with:

`- [UID:0000L3][MapPane](by-file/MapPane.md) : reconstructable : 89% : very-strong : Major NexusTK/map/MapPane.cpp source root at unchanged score/route with source-ready compressed-map load/save methods and exact allocation child, canonical map dimensions/tile buffer, StdioFile-uncompress versus direct-CRT-compress source distinction, exact save failure/disposal/monster-cache contract, deterministic dependency/order/generated policy, opcode 0x67 TimerPane flow, and retained duplicate 0x005140a0 no-route evidence.`

- Add UID00037X under the MapPane by-memory family in address order at `[0x0050b080,0x0050bcd8)`:

`        - [UID:00037X][0x0050b080-0x0050bcd8.MapPaneInteractionMapChangeCore](by-memory/0x0050b080-0x0050bcd8.MapPaneInteractionMapChangeCore.md) 0x0050b080-0x0050bcd8 | aggregate | MapPaneInteractionMapChangeCore : reconstructable : 85% : strong : Exact MapPane interaction/map-change aggregate at unchanged score/route; its 0x0050bbb0 map-change helper calls SaveCompressedMapFile at 0x0050bbe7 only when the incoming map id differs, ignores the void result, and continues configuration/state work, while broader helper names remain unresolved.`

- Add UID0003TK under UID0001AW's MapPane packet-handler children in address order between UID0001AX `[0x00510400,0x005104c7)` and UID0003TL `[0x00510960,0x00511347)`:

`        - [UID:0003TK][0x005104d0-0x00510958.MapPaneHandleEffectMapStatePacket](by-memory/0x005104d0-0x00510958.MapPaneHandleEffectMapStatePacket.md) 0x005104d0-0x00510958 | method | MapPaneHandleEffectMapStatePacket : reconstructable : 86% : strong : Exact opcode-0x15 MapPane map-state/effect handler at unchanged score/route; on map-id change it calls SaveCompressedMapFile at 0x00510671, ignores the void result, then continues configuration/state work, with broader packet-field/helper names still provisional.`

- All verify-only support rows require no score/path/title/reconstructable or source-quality replacement from this callback.
- B005 must not apply manual coverage text. Manual coverage is supervisor-owned; generated coverage/tracker state is validator/lifecycle-owned and must not be hand-edited or frozen to a pre-execution count.

## Follow-Up Actions

- Supervisor-owned lifecycle state remains external to this artifact. The completed callback artifact supplies durable claim proof and coverage text without directing or asserting execution/archive counts.
- A-agent actions: none required for UID0002QK reconstruction.
- B005 callback responsibilities specified by C01-C35, Destination 1, the five ordinary destinations, scoped validation, and generated assertions are complete.
- Verify-only UID0001PN contains one stale sentence saying caller `0x0050504e` checks the MonsterImageLib singleton; exact disassembly and generated source show an unconditional load/call. The accepted five-page cap excluded that page, so correction remains a supervisor-routed external follow-up and does not alter UID0002QK.
- Future research outside this assignment: broader UID00037X/UID0003TK unresolved helper/packet names may be audited independently; they do not alter the exact save call facts or block UID0002QK.

## Confidence

- Recommendation confidence: 99% for owner/emitter/source placement and 98% for human source body.
- Score confidence: 98% for `92/94` under the project score standard.
- Remaining uncertainty: original private symbol/local spellings and include ordering only. No behavioral, ABI, range, ownership, or emission blocker remains.

## Validator Results

- Historical report-only phase: no validator ran before supervisor Gate 1 acceptance.
- Scoped target: command `000000011877`, `2026-07-14T17:03:33-04:00`, `by-memory/0x00504e00-0x00505075.MapPaneSaveCompressedMapFile.md`, exit `0`, `ok:1`. It registered the 92/94 formal/hash change and deferred generation. Its missing-ref warnings for UID00037X/UID0003TK reflected their then-unregistered validator rows and were resolved by their later scoped commands.
- Scoped class: command `000000011878`, `2026-07-14T17:04:40-04:00`, `by-class/MapPane.md`, exit `0`, `ok:1`. It preserved `89/89` and blank class formal. It reported 75 pre-existing missing-reference warnings and a projected-statistics side effect; generation was deferred.
- Scoped file: command `000000011881`, `2026-07-14T17:06:43-04:00`, `by-file/MapPane.md`, exit `0`, `ok:1`. It preserved `89/85` and path/formal policy. It reported 86 existing missing-reference warnings, one stats-row/projected-statistics update, and deferred generation.
- Scoped aggregate caller: command `000000011884`, `2026-07-14T17:07:17-04:00`, `by-memory/0x0050b080-0x0050bcd8.MapPaneInteractionMapChangeCore.md`, exit `0`, `ok:1`. It registered UID00037X, preserved `85/89`, blank formal/Item Summary and `Nested:8`, normalized the UID0002QK link label, updated validator registry/reference indexes/projected statistics, and deferred generation.
- Scoped packet caller: command `000000011889`, `2026-07-14T17:07:48-04:00`, `by-memory/0x005104d0-0x00510958.MapPaneHandleEffectMapStatePacket.md`, exit `0`, `ok:1`. It registered UID0003TK, preserved `86/90`, blank formal/Item Summary and `Nested:8`, normalized UID0002QJ/UID0002QK link labels, updated validator registry/reference indexes/projected statistics, and deferred generation.
- Initial callback waited refresh: command `000000011892`, `2026-07-14T17:08:00-04:00`, `by-file/MapPane.md`, exit `0`, `ok:1`, `generated_refresh:completed`. Validator-owned side effects were registry rebuild (4,872 nodes/3,927 edges), projected/stat row refresh, generated metadata refresh, `auto-generated/-ag-memory-coverage.md`, `auto-generated/-ag-coverage-report-by-memory.md`, and `auto-generated/NexusTK/map/MapPane.cpp`; B005 edited none manually. Existing project-wide warnings included 84 missing references, 85 missing children markers, 14 fallback children insertions, and 180 emitters with no code; none is a UID0002QK failure.
- Immediate post-command readback after `000000011892`: `auto-generated/NexusTK/map/MapPane.cpp`, 54,921 bytes, refreshed `2026-07-14T17:08:10.4121736-04:00`, SHA-256 `7BDAFC10503DB744B637F83600A79CBEE1BADBAE3BE608450F360EC73A268EC2`.
- Intermediate concurrent readback: validator-owned refresh `000000011901` at `2026-07-14T17:09:40-04:00` retained all UID0002QK assertions at SHA-256 `699783186AEFC15AAF305037C1116316D2624C21B447F3B5E164B954ADE925EA`.
- Gate 2 repair scoped validation: command `000000011920`, `2026-07-14T17:41:54-04:00`, `by-file/MapPane.md`, exit `0`, `ok:1`. It validated the historicalized B004 paragraph, preserved UID0000L3 `89/85`/path/formal policy, reported 84 existing missing-reference warnings, updated the file stats row/projected statistics, and deferred generation.
- Gate 2 repair final waited refresh: command `000000011921`, `2026-07-14T17:42:04-04:00`, `by-file/MapPane.md`, exit `0`, `ok:1`, `generated_refresh:completed`. Validator-owned side effects were the 4,872-node/3,927-edge registry rebuild, 281 generated metadata refreshes, stats/projected-statistics refresh, and the current MapPane generated header; B005 edited no restricted file manually. Existing project-wide warnings were 84 missing references, 85 missing children markers, 14 fallback children insertions, and 180 emitters with no code; none is a UID0002QK failure.
- Final current readback: `auto-generated/NexusTK/map/MapPane.cpp` is 54,921 bytes, modified `2026-07-14T17:42:13.0672919-04:00`, SHA-256 `1AC07C9EBDBD161DD412013A11F48E131E3852B1EC822A88E03AFCFAF369E19A`. UID0002QK assertions remain exact: one `SaveCompressedMapFile`, one `LoadCompressedMapFile`, one `AllocateTileBuffer`, two pre-existing emitting caller calls, one UID0002QK provenance header, and zero UID0002QK empty markers. The body has one lowercase `compress`, four `fwrite`, one `fclose`, two `ClearLoadedData`, no `compressBound`, no StdioFile save, and no `__security_cookie`, `__CxxFrameHandler`, or `__ehhandler`. Source order remains loader, saver, UID00037Y aggregate comment, allocator.
- Every scoped/final command passed. No accepted claim is blocked.

## Changed Files

- Historical creation/callback artifact: `tools/leaser/Agents/Agent-B005/research/0002QK-MapPaneSaveCompressedMapFile-source-quality.md`.
- Modified ordinary pages, exactly five:
  - `by-memory/0x00504e00-0x00505075.MapPaneSaveCompressedMapFile.md` - SHA-256 `85BBF431ECADEBD75EBDB67D5417F7310D19156401B8F64107D0B94471A3D4CA`, 196 lines.
  - `by-class/MapPane.md` - SHA-256 `1A4047A8DC21DE2190552DDF0FC698FEDC9A9C1A3827AB2566B19B41AF30352F`, 461 lines.
  - `by-file/MapPane.md` - SHA-256 `22A21245A8000659722217B259392045BF970F0DB13D1AC41C03A6AA0290C0AD`, 524 lines; Gate 2 repair historicalizes B004's pending status and states the later UID0002QK callback superseded it.
  - `by-memory/0x0050b080-0x0050bcd8.MapPaneInteractionMapChangeCore.md` - SHA-256 `7D6CDC075688E34397E698E13A9D36930985B35E40B567D242B43D0D698B01F4`, 72 lines.
  - `by-memory/0x005104d0-0x00510958.MapPaneHandleEffectMapStatePacket.md` - SHA-256 `239F35500196B693FF5E60BF51FD1395EA2C6D14C2BB7B4BC339AD4CA5EA7B01`, 88 lines.
- Verify-only pages were reread without modification. UID0001PN's exact stale null-check contradiction is recorded as excluded with reason; all other accepted verify-only contracts were current.

### Verify-Only Hash Manifest

| Verify-only path | SHA-256 |
| --- | --- |
| `by-memory/0x00504b90-0x00504df1.MapPaneLoadCompressedMapFile.md` | `7C8CBE08C7EE501DC258A96C6FE39D59B59CFBB7CFF1F00155EDFD4758BD8A63` |
| `by-memory/0x0050e2a0-0x0050e2f4.MapPaneAllocateTileBuffer.md` | `490C78A6CA4B98A87DD346F4E1133CE6D409281898BA9D5A5F95118D9EB6A501` |
| `by-memory/0x00504530-0x005046c6.MapPaneCleanup.md` | `368C578BB36EAAB607D095F0FB00D21AF1971E86D77500FCAE0C35FE8F842F68` |
| `by-memory/0x005047f0-0x00504b6b.MapPaneExitToMenuTeardown.md` | `FB432C860198EDEDF878E65C1EB7BFD2A3341E33796B279D6E1B122D21439394` |
| `by-memory/0x00506970-0x0050e320.MapPaneInputPacketRenderCore.md` | `231AA7E2D10F1253D550573209B618D6BADA8572B270DEB90885169154024D17` |
| `by-memory/0x0050e4c0-0x00514920.MapPanePacketHandlers.md` | `71CF6E2F6012C75866A9D989D19AFFC454A3DD0A70E755AF965F66E6842A38D1` |
| `by-type/by-struct/MapPaneLayout.md` | `21E0758A09B86287F9D3144B7CFC3B656511E477CA2AA91C4F0FE8018035CB93` |
| `by-type/by-struct/MapPaneTileRecord.md` | `E8EE4EE9C74FA3230C2676FFE3AC12CAEA573B991DD547C1025F28E523E16524` |
| `by-class/AUTOBUF_unsigned_char.md` | `BAAFD063F881C199ED7EB24BE3D5F1D6251658CBDF60793A3D41F3BB15E43FF2` |
| `by-type/by-template/AUTOBUF_unsigned_char.md` | `765A5724C9F48B3D6FA2ECD55A7AE0EC24C56CEECDAFE706237CDC00FDC68390` |
| `by-file/AUTOBUF.md` | `B76D27374FE6F6C2157CD79580D78E6926F6B7AFCE52B28E1BF353626C65B63F` |
| `by-memory/0x004f5640-0x004f566a.AUTOBUFUnsignedCharConstructor.md` | `C79FEA58B1F7AF18D7BEA6B955D8705CAD42AE6678C5B8B57ECE296FE17D59F3` |
| `by-memory/0x004e6ab0-0x004e6ad7.AUTOBUFUnsignedCharResize.md` | `3AFFBBF95AED14889CE3DF01F033FF612947423CC23CE52CF059AB2CE1108AF1` |
| `by-memory/0x004142c0-0x00414565.ZlibPublicCompressChecksum.md` | `5E5443A0919F0B61EED2A471B6262858F3A911322E01E8B36134E470321ABA5B` |
| `by-global/WideApiDispatchTable.md` | `CAD07BDEA56F1F8993A06B233A0A32594FC82DA2BE06B35897E019DB671149B4` |
| `by-memory/0x0069be14-0x0069bec4.WideApiDispatchPointerTable.md` | `1A6EDC9EDA55DF7FF6C7B843C33B504B4B35E54D0DBE8CE2A46124F7CDCED367` |
| `by-global/MapPaneCmapSignaturePointer.md` | `C76E7DA6942C1EFDF096D856763BDE8E7F0EAF7DAD40C49462EE7E5548DB7DB5` |
| `by-memory/0x0066db48-0x0066db4c.MapPaneCmapSignaturePointer.md` | `76814825D8812AB4C006961966DAF0CA8BF0C7E00EB16B6A801BDFE1CBAB5CB0` |
| `by-class/MonsterImageLib.md` | `D9BC438FD43A79F39A944104E39F0A29DE302AC13C18AB73CA3FE29C55F2BCBD` |
| `by-file/MonsterImageLib.md` | `F5A7291275CD7A8786D8CF6CF91EAA475251858DBAD7F6E4A692993B41990466` |
| `by-global/g_pMonsterImageLib.md` | `32798A03A3D3202DD53E527E6FCFE7F5A094BFD72E9FC5878F6EE43FCB40E148` |
| `by-memory/0x0069b440-0x0069b444.g_pMonsterImageLib.md` | `28557F62DD484049190826642611B964485D257DABFBFCD1E0484A22486567B2` |
| `by-memory/0x004dac40-0x004dc420.MonsterImageLibLocalMethodCluster.md` | `85AEFE11A2CA2B48D547F0C0CD81AC1E1581F938754EDCAA101D6FB7EAC19680` |
| `by-memory/0x0061e704-0x0061eb08.MapPaneGameServerReadOnlyData.md` | `DED5C0BED3472DFA8199FEA41171E0EDFDA5405777A4901543E168D4431723A7` |
| `by-memory/0x0061e908-0x0061eadc.MapPaneResourceStrings.md` | `83BF1331712F9DCF639AB73196BAEE91AFC70A9A921783E519493CD3485DF0EF` |
| `by-memory/0x0061e924-0x0061e964.MapPaneCachePathStringsAndSelectionMarker.md` | `5B324ADFA9152A241E00E3C14ADA0CC3051215B7322B2EBF331B98FFA059B9DD` |
| `by-memory/-ignored.md` | `A889E73773285DAB5B61225666B99E092F3D11162DAFCEE19561F6B878635B50` |

Restricted read-only evidence hashes at final self-review were manual `by-memory/-coverage-report.md` `1AAB07F590A0385D2DCF86E68E888F699EAB0BEB7A1C632A71ECE1713D8A5C80`, `by-class/-coverage-report.md` `3772E927078043C6DB7DA19B9EE02E94A5EF880AC3D6E093830789161402D282`, `by-file/-coverage-report.md` `E4BA9F22CE42F1A26E2650F09246D7EB3F7E5F68DCDB56B929958BBA7EB3D2E3`, tracker `auto-generated/-ag-research-tracker.md` `3DE519BAD97CFF3EE5FB276B714DE1DCB3895BA90CEFF55E0FF364A818D87385`, and generated `auto-generated/NexusTK/map/MapPane.cpp` `1AC07C9EBDBD161DD412013A11F48E131E3852B1EC822A88E03AFCFAF369E19A`. B005 did not edit any of these manually; hash changes arose from validator-owned or concurrent workspace activity.

- Validator-owned generated/registry/statistics side effects are recorded under Validator Results; no manual coverage, generated, tracker, audit, supervisor, validator-state, lifecycle, queue, lock, goal, or archive file was edited by B005.
- Renamed/moved/deleted files: none. Report execution was not run; no execute/probe/count/move/archive/lifecycle command was issued.
- Lease proof: each ordinary page was leased only for reread/edit/scoped validation and released immediately afterward. The Gate 2 repair leased only `by-file/MapPane.md` and released it immediately after command `000000011920`; current `tools/leaser/lease.json` contains no B005 entry.

## Implementation Tracking Checklist

Initial report-only pass:

- [x] Supervisor Gate 1 accepted exact report SHA `10B19067B363F226C2EBDC3C2C0122B929A08CF82AA2D62F9FA1B08DCC541579` for implementation.
- [x] Exact callback scope fixed to UID0002QK, UID00007Q, UID0000L3, UID00037X, and UID0003TK; listed dependencies classified verify-only.
- [x] Historical target state and actual evidence checked recorded.
- [x] C01-C35 ledger created with legal Action enums and callback-ready destinations.
- [x] Exact metadata/score plan recorded: UID0002QK only `86/90 -> 92/94`; all other metadata/scores preserved.
- [x] ABI, failure matrix, CRT results, output capacity, AUTOBUF, fields/types/globals/helpers, ownership, source placement, and C++ blockers researched to resolution.
- [x] Owner/emitter/reconstructable plan preserved UID00007Q/UID00007Q/TRUE.
- [x] No split/rename/new-child plan; exact range and nesting preserved.
- [x] Source placement, range/split/padding/reclassification, and IDA rename/type/comment decisions recorded.
- [x] First-draft C++ fixed to Destination 1 exactly.
- [x] Third-party import confirmed not applicable; this is NexusTK integration code, not an embedded zlib implementation.
- [x] Exact target/support details, stale history, rejected alternatives, and negative evidence recorded without compression.
- [x] Historical Wave2/Wave3 artifacts rejected as routing authority.
- [x] Open questions closed with only non-blocking original lexical uncertainty retained.
- [x] Scoped validator and waited-refresh plan recorded.
- [x] Exact supervisor-owned manual coverage text supplied; generated/tracker state remains validator/lifecycle-owned.

Implementation callback pass:

- [x] Accepted Gate 1 artifact implemented in the same report lifecycle.
- [x] All accepted target/support details incorporated at report-level detail across exactly five ordinary pages.
- [x] C01-C35 use legal final destination-specific states with adjacent proof; no claim is blocked.
- [x] UID0002QK alone raised to `92/94`; owner/emitter/range/position/nesting preserved; Destination 1 applied exactly; no split/rename/new UID.
- [x] UID00007Q/UID0000L3/UID00037X/UID0003TK scores, routes, metadata, and formal policies preserved while bounded prose was synchronized.
- [x] Historical/stale assumptions, rejected alternatives, negative evidence, and non-blocking lexical cap preserved.
- [x] Open questions remain resolved; UID0001PN's out-of-cap stale sentence is exact, evidence-backed, and excluded with reason.
- [x] Five initial scoped validators plus repair scoped validator `000000011920`, initial waited refresh `000000011892`, and repair final waited refresh `000000011921` ran with command IDs, timestamps, exit/ok, warnings, and side effects recorded.
- [x] Generated MapPane.cpp verified read-only for exactly one UID0002QK definition, no UID0002QK empty marker, unchanged load/save/allocator order and UID00037Y aggregate comment, and no handwritten ABI/EH/cookie/thunk mechanics.
- [x] Exact changed/verify-only files, validator-owned generated side effects, and all lease releases recorded; no accepted item remains unapplied or blocked.
- [x] Manual coverage text remains supervisor-owned; no manual coverage/generated/tracker/audit/supervisor/lifecycle edit or execute/probe/move/archive command was performed.
- [x] Gate 2 consistency repair completed: UID0000L3 line 144 now preserves B004's pending state only as history and explicitly records supersession by the source-ready UID0002QK callback; scoped `000000011920` and waited `000000011921` passed, generated assertions were reconfirmed, and the lease was released.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B005","command_id":"000000011960","destination_path":"executed-b-agent-research/B005/0002QK-MapPaneSaveCompressedMapFile-source-quality.md","details":"report executed into central archive","event":"executed","source_path":"tools/leaser/Agents/Agent-B005/research/0002QK-MapPaneSaveCompressedMapFile-source-quality.md","timestamp":"2026-07-14T17:52:27-04:00","uid":"0002QK"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
