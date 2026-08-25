** TARGET-REPORT-UID:00017E **
** AUTHOR-AGENT-ID:B003 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# 00017E MonsterImageLibGetArchiveBoundsBucket Source-Quality Research

## Finalized Report / Current Recommendation
- Current recommendation: keep [UID:00017E] `by-memory/0x004dbe60-0x004dc174.MonsterImageLibGetArchiveBoundsBucket.md` assigned to [UID:00008N] `by-class/MonsterImageLib.md` with emitter [UID:00008N], keep `RECONSTRUCTABLE:TRUE`, keep blank emitter position, and refresh the target/support docs with live MCP evidence from session `80de0a67`.
- Final disposition: exact child method of `MonsterImageLib`, not a DAT subsystem helper, not an aggregate, not a padding/widening target, and not a merge with the adjacent resolver, raw local helper, or old EPF builder.
- Required action: update the target score from `COMPLETION:85` / `CONFIDENCE:90` to `COMPLETION:88` / `CONFIDENCE:91`; preserve the blank formal C++ block with an exact no-code proof; update support docs listed below.
- Confidence: high for behavior, range, direct owner/emitter, and source placement; moderate-high for source-facing names because original symbols are unavailable and the raw DATIndexVector node API still blocks a source-quality method body.

## Supporting Research

## Target
- Target UID: `00017E`.
- Target path: `by-memory/0x004dbe60-0x004dc174.MonsterImageLibGetArchiveBoundsBucket.md`.
- Source queue/report row: `auto-generated/-ag-research-tracker.md` row for `00017E` under by-memory reconstructable work. The generated row is stale at `78/88`, while the current target page is already `85/90`.
- Current supervisor classification: report-only source-quality research for `MonsterImageLibGetArchiveBoundsBucket`.
- Current scores and parent state: target page is `COMPLETION:85`, `CONFIDENCE:90`, `CANONICAL_OWNER:00008N`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:00008N`, blank `EMITTER_POSITION_OPTIONAL`, blank `RECONSTRUCTION_CPP`.

## Current Target State
- Existing metadata: `UID:00017E`, range `0x004dbe60-0x004dc174`, current `85/90`, owner/emitter `00008N`, reconstructable true.
- Existing owner/emitter/reconstructable state: correct and should stay unchanged. `00008N` is the `MonsterImageLib` class, emitted by `by-file/MonsterImageLib.md` into `auto-generated/NexusTK/render/MonsterImageLib.cpp`.
- Existing C++/emitter state: formal C++ block is blank. The current stale reason says final source names/C++ remain below final-audit status.
- Existing open questions, blockers, placeholder names, stale assumptions, or contradictory claims:
  - The target summary still presents the function as behavior-confirmed but source/C++ blocked.
  - Generated coverage still reports old `78/88` metadata and an empty emitter marker.
  - `by-file/MonsterImageLib.md` still describes this target as disabled/excluded from active emission, which is stale against the target page's owner/emitter fields and the generated coverage row that already treats it as emitted with `emits_code:false`.
  - The third code xref to `0x004dbe60` at `0x004dc279` was previously carried as a raw/local ref. Live MCP shows it is in an IDA-undefined prologued helper at `0x004dc240-0x004dc2db`, outside this target. It should not be ignored, but it also should not widen `00017E`.
  - The function's exact original source body remains unsafe to emit because the current binary body uses raw `DATIndexVector` node/list internals and heap lifetime/cleanup paths for DAT objects that are not yet source-ready as a clean public API.
- Related target/support docs checked:
  - `by-class/MonsterImageLib.md`
  - `by-file/MonsterImageLib.md`
  - `by-memory/0x004dac40-0x004dc420.MonsterImageLibLocalMethodCluster.md`
  - `by-memory/0x004dac40-0x004daebc.MonsterImageLibLoadMonsterTables.md`
  - `by-memory/0x004db010-0x004db0f7.MonsterImageLibDestructor.md`
  - `by-memory/0x004e5990-0x004e5a62.VectorGrowArchiveIndex.md`
  - `by-class/DATIndexVector.md`
  - `by-file/DATIndexVector.md`
  - `by-class/DATFile.md`
  - `by-class/DATFileContainer.md`
  - `by-memory/0x0049c130-0x0049d2cc.DATFile.md`
  - `by-type/by-struct/MonsterImageLibLayout.md`
  - `by-type/by-struct/MonsterArchiveBoundsBucket.md`
  - `by-type/by-struct/MonsterArchiveBoundsEntry.md`
  - `by-type/by-struct/RectBoundsLayout.md`
  - `by-file/DATArchive.md`
  - old report `executed-b-agent-research/B001/0001VA-MonsterArchiveBoundsBucket.md`
  - old report `executed-b-agent-research/B011/00017D-MonsterImageLibDestructor-source-quality.md`
  - generated rows in `auto-generated/-ag-memory-coverage.md`, `auto-generated/-ag-research-tracker.md`, `auto-generated/-ag-coverage-report-by-memory.md`, and `auto-generated/NexusTK/render/MonsterImageLib.cpp`.

## Executive Recommendation
- Best direct owner: [UID:00008N] `by-class/MonsterImageLib.md`.
- Best source file: [UID:0000LJ] `by-file/MonsterImageLib.md`, generated source root `auto-generated/NexusTK/render/MonsterImageLib.cpp`.
- Target disposition: keep as a source-bearing exact method child, update behavior/source-quality evidence, keep formal C++ blank under an explicit no-code proof.
- Score disposition: raise target to `88/91`. The score should move because this pass resolves the raw xref, exact boundary, live MCP freshness, source-facing method/member names, source placement, and no-code proof. It should not move higher because final formal C++ would currently require inventing unsupported high-level cache APIs or emitting raw list/node code.
- Required condition before formal C++ can be added later: the project must settle source-ready declarations/lifetime APIs for the `DATIndexVector` key/value node operations used here and the heap-owned `DATFileContainer`/`DATFile` reader pair, so the body can be written without raw `this[15]`, list sentinel manipulation, decompiler temporaries, or invented wrappers.

## Supervisor Active Recheck
- The active user instruction assigns report-only research for [UID:00017E] and forbids by-* edits before supervisor callback.
- No split repair was allowed during this report-only pass.
- The assigned target does not require splitting: `lookup_funcs` confirms `sub_4DBE60` covers `0x004dbe60` with size `0x315`, and padding starts after the target's final EH/list-too-long call at `0x004dc170`.
- A related source-bearing gap was found at `0x004dc240-0x004dc2db`. It is outside the target, has no xrefs to its start, and should be documented in the local cluster as a separate IDA-undefined helper/gap. It does not change the target range or owner.

## Inference Research Guidance Check
- `by-structure.md` allows this target to remain reconstructable/emitting because the target is reconstructable, has nonblank owner/emitter, and the score average is above the active code-entry gate. The blank formal C++ block means generated output remains an empty emitter marker, not a body.
- Existing documentation assumptions treated as uncertain and rechecked:
  - old generated `78/88` metadata;
  - the stale "disabled/excluded" wording in the file doc;
  - raw xref `0x004dc279`;
  - exact DAT/cache/helper source names;
  - whether the target should be merged with `0x004dc180`, `0x004dc240`, or `0x004db8b0`;
  - whether a formal C++ body can be safely emitted now.
- Direct IDA fact: function range, callers, callees, disassembly, stack/ABI, string bytes, boundary/padding, data xrefs, and cleanup ownership routes.
- Documentation evidence: current by-* docs already converge on `MonsterImageLib`, `m_openArchiveIndex`, `m_boundsBucketIndex`, `MonsterArchiveBoundsBucket`, `MonsterArchiveBoundsEntry`, `DATIndexVector`, `DATFile`, and `DATFileContainer`.
- Inference: source-facing method name `GetArchiveBoundsBucket`, parameter name `archiveIndex`, cache names, and bucket/entry member names are the best current human-readable reconstruction, but not original-symbol proof.
- Wave2/Wave3 artifacts: none found in the checked target/support docs. Generated rows are stale validator output, not Wave2/Wave3 material.

## Heuristic / Inference Reanalysis And Validation
- Function role: `MonsterImageLib::GetArchiveBoundsBucket(int archiveIndex)` is strongly supported. Live decompile starts by searching the `+0x3c` bounds-bucket index for the argument key, lazily constructs/opens `DATA/MON%d.DAT` on miss, inserts the opened archive reader through the `+0x1c` cache, constructs a 12-byte bucket, inserts it through the `+0x3c` cache, reads the bucket header and entries, then returns the cached bucket pointer.
- Return type: `MonsterArchiveBoundsBucket *` is strongly supported. Consumers treat the return as a header at `+0x00` and an entry pointer at `+0x08`; resolver and render-bounds callers dereference `entryCount` and index `entries + 24 * index`.
- Parameter name/type: `int archiveIndex` is strongly supported. It is used as the `DATA/MON%d.DAT` format argument and as the key for both DAT index vectors. Existing raw `ArgList`/`a2` names should be rejected in source-facing docs and C++.
- Cache fields: `m_openArchiveIndex` at `+0x1c` and `m_boundsBucketIndex` at `+0x3c` remain the best source-facing names. Target disassembly uses `lea eax, [edi+1Ch]` for the opened-reader cache insertion and `this + 15`/`[edi+40h]` for the bounds-bucket cache lookup/sentinel. `tools/int_convert.py` verifies `0x1c` is decimal 28 and `0x3c` is decimal 60.
- Bucket record: `MonsterArchiveBoundsBucket` size `0x0c` is direct. Target executes `operator new(0x0c)`, reads 8 header bytes into that allocation, stores the allocated entry array at offset `+0x08`, and returns a cache value pointing to this object. `tools/int_convert.py` verifies `0x0c` is decimal 12.
- Entry record: `MonsterArchiveBoundsEntry` size `0x18` is direct. Target computes `(entryCount + 1) * 24` with `lea eax, [eax+eax*2]` followed by `shl eax, 3`, reads four 16-bit bounds and two 32-bit offsets per entry, calls `sub_4B7C50` for the `RectBounds` field, then adds the DAT payload base to both pointer fields. `tools/int_convert.py` verifies `0x18` is decimal 24.
- DAT string/source: raw bytes at `0x0061c07c` decode as UTF-16LE `DATA/MON%d.DAT`; the same string address is referenced from `LoadMonsterArchives` at `0x004dbca1` and this target at `0x004dbeb4`. The immediately following UTF-16LE string is `MON%d.EPF`, which belongs to the old EPF builder path and is separate evidence, not a reason to merge.
- Caller/reachability: normal callers are `ComputeRenderBounds` at `0x004db647` and `ResolveMonsterArchiveBounds` at `0x004dc1b9`; `RenderMonster` and `RenderMonsterImage` reach the bucket through the resolver at `0x004dc180`. The third xref at `0x004dc279` is a call from an IDA-undefined helper at `0x004dc240-0x004dc2db`.
- Source placement: `MonsterImageLib` is the owner because the method is a `thiscall` over `MonsterImageLib` layout offsets, uses `m_archiveOffsets`, `m_openArchiveIndex`, and `m_boundsBucketIndex`, is called by other `MonsterImageLib` methods, and is cleaned up by `MonsterImageLib::ClearLoadedData`.
- Rejected raw names: `sub_4DBE60`, `ArgList`, `this + 15`, `this[16]`, `v7`, `v18`, `aDa_3`, `sub_457580` as final target prose should be replaced by source-facing names except inside evidence.
- Rejected `DWORD`, `long`, or `void *` source types: the argument is semantically an archive index; the return is semantically a `MonsterArchiveBoundsBucket *`; entry offsets become byte pointers relative to the DAT payload base.
- Rejected caller ownership: render callers consume the bucket; they do not own the cache or DAT reader lifetime.
- Rejected DAT subsystem ownership: DAT functions are callees and storage abstractions. The key, cache, path format, and cleanup are `MonsterImageLib` state.
- Rejected merge with formatter/header/declaration work: `DATA/MON%d.DAT` string formatting is part of the method, but the unresolved DAT class declarations only block formal C++; they do not block documenting this exact child or its owner/emitter.
- Rejected merge with `0x004dc180`: the resolver consumes this bucket and returns/copies per-frame entry data. It has its own function start, xrefs, and `0xb5` size.
- Rejected merge with `0x004dc240`: the IDA-undefined helper starts with its own prologue at `0x004dc240`, ends with `retn 8` at `0x004dc2db`, is followed by alignment before `ClearLoadedData`, and lies outside the target. It should be a separate cluster gap/candidate, not a target range extension.
- Rejected merge with `0x004db8b0`: live `xrefs_to 0x004db8b0` reports zero callers. It is an old `MON%d.EPF` builder-like helper that shares layout concepts but is not the live lazy `DATA/MON%d.DAT` loader.
- Rejected aggregate emission: the local method cluster spans many methods and unresolved gaps; this exact function should stay a child under the class. The aggregate should stay non-reconstructable/index-only.

## Evidence Standards Used
- IDA MCP endpoint/session: live MCP at `http://127.0.0.1:13337/mcp`, session `80de0a67`.
- Server health: `server_health` returned `status:"ok"`, IDB `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, module `NexusTK.exe`, input path `C:\Users\admin\Desktop\Clone\NexusTK\NexusTK.exe`, imagebase `0x400000`, `auto_analysis_ready:true`, `hexrays_ready:true`, `strings_cache_ready:true`, string cache size `2067`.
- 2026-06-27 B003 recheck: MCP still uses session `80de0a67`; `server_health` remains `status:"ok"` with Hex-Rays and strings cache ready. Fresh `lookup_funcs`, `xrefs_to`/`xref_query`, `get_bytes`, `decompile`, `disasm`, `analyze_function`, `analyze_component`, `insn_query`, and `get_string` calls reconfirm the same target range, callers, string bytes, raw helper gap, and support-callee set recorded below. No fallback-only evidence was used.
- Evidence types used: `lookup_funcs`, `analyze_function`, `decompile`, `disasm`, `xrefs_to`, `xref_query`, `get_bytes`, `get_string`, `find_regex`, `search_text`, `insn_query`, by-* docs, generated rows, and old B-agent reports as leads.
- Evidence ladder: direct MCP facts and raw bytes were preferred for range, ABI, calls, string bytes, and entry layout; support docs were used for source-facing names and source-tree placement; inference was used only where original symbols are absent.
- Tool limitations: IDA MCP cannot prove original source names, exact local variable names, or exact class API design. The decompiler shows raw list/node internals and is not by itself a safe source body.

## Evidence Checked
- IDA MCP/manual-disassembly/raw-byte checks performed:
  - `idb_list` confirmed active session `80de0a67`.
  - `server_health` confirmed ready Hex-Rays and strings cache.
  - `lookup_funcs` for `0x004dbe60`, `0x004dc174`, `0x004dc180`, `0x004db5c0`, `0x004dbc60`, `0x004dc2e0`, DAT helper callees, DATIndexVector callees, and `sub_4B7C50`.
  - `analyze_function` and `decompile` for the target, direct callers, resolver, archive loader, cleanup, and EPF builder.
  - `disasm` for the target, including total instruction count and ABI.
  - `xrefs_to` / `xref_query` for target, resolver, old EPF builder, `DATA/MON%d.DAT` string, DAT helpers, and DATIndexVector helper calls.
  - `get_bytes` for target start/end/padding and `0x0061c07c` string bytes.
  - `search_text`, `xrefs_to`, and `insn_query` for the raw `0x004dc279` xref gap.
  - `tools/int_convert.py` for `0x315`, `0x0c`, `0x18`, `0x1c`, `0x3c`, `0x14`, `0x20`, `0x24`, `0x40`, `0x50`, `0xffffffe`, and `268435454`.
- Support API audit performed for the no-code decision:
  - `by-class/DATIndexVector.md` currently provides a class declaration and field names, but only exposes `FindNodeByKey(const int& key)` and `InsertNode(DATIndexVectorNode* node, bool* inserted)`. It does not define a source-level `Insert(key, value)`/cache-insert API matching this target's two raw node-allocation and list-count insertion sequences.
  - `by-memory/0x00457100-0x0045730f.DATIndexVectorInsertNode.md` and `by-memory/0x00457580-0x00457613.DATIndexVectorFindNodeByKey.md` confirm the exact low-level node/bucket behavior used here, but both still preserve source-signature/folder caveats and keep method C++ blank.
  - `by-class/DATFile.md` and `by-class/DATFileContainer.md` confirm the reader/container roles, `OpenByIndex`, stream reads, and mapped payload base, but still record provisional member/API names and unresolved public/internal ownership semantics for the exact source surface this method would need.
  - `MonsterArchiveBoundsBucket`, `MonsterArchiveBoundsEntry`, and `MonsterImageLibLayout` are strong enough for field/layout documentation and score movement, but they do not provide the missing source-level cache/DAT ownership API.
- by-* docs, support docs, old reports, generated reports, and trackers checked: see "Current Target State" support list.
- Negative checks performed:
  - `xrefs_to 0x004db8b0` returned no callers.
  - `lookup_funcs 0x004dc240` and `0x004dc279` returned not a function.
  - `xrefs_to 0x004dc240` returned no xrefs to the helper start.
  - `search_text` for `call sub_4DBE60` over `0x004dc235-0x004dc2e0` returned no rendered hit, while `insn_query` over the same range showed the raw call at `0x004dc279`; this confirms a listing/cache/rendering limitation, not absence of code.
  - `find_regex DATA/MON.*DAT` returned no match because the string is UTF-16LE and `get_string` only returned `DA`; raw bytes were used instead.
- Failed, unavailable, or intentionally skipped checks:
  - No IDA DB edits, function definitions, renames, type applications, or comments were made because report-only instructions prohibit IDA DB edits.
  - No by-* docs were edited because this is report-only.
  - No generated files were edited. Stale generated state is recorded for validator/supervisor refresh.

## Inference Claim Ledger
| Claim | Confidence | Evidence | Counter-evidence checked | Next verification / remaining uncertainty |
| --- | --- | --- | --- | --- |
| `00017E` is `MonsterImageLib::GetArchiveBoundsBucket(int archiveIndex)` | High | `thiscall` over `MonsterImageLib` offsets, `DATA/MON%d.DAT` formatting, cache lookups at `+0x3c`, direct callers in `MonsterImageLib` methods | DAT helper ownership, caller ownership, EPF builder merge, aggregate ownership rejected | Original symbol/name unavailable |
| Return type is `MonsterArchiveBoundsBucket *` | High | Consumers use `+0x00` entry count and `+0x08` entries; target allocates 12-byte bucket and inserts that pointer into cache | Raw `int`/`void *` decompiler return rejected | Exact original typedef/class declaration unavailable |
| `+0x1c` is `m_openArchiveIndex` and `+0x3c` is `m_boundsBucketIndex` | High | Target inserts opened reader through `+0x1c` and bucket through `+0x3c`; cleanup walks `this+32` and `this+64` list heads and clears counts | Generic DATIndexVector ownership rejected | Exact original member spelling unavailable |
| Bucket layout is count/header fields plus entries pointer | High | Target reads 8 header bytes into 0x0c allocation and stores entry array at `+0x08`; support docs match | Middle fields are not consumed by live render callers | Original names for `+0x02/+0x04/+0x06` remain descriptive |
| Entry size is 24 bytes with `RectBounds`, `payloadStart`, `payloadEnd` | High | `24 * (entryCount + 1)`, four 16-bit reads, two 32-bit reads, `InitRectBounds`, base rebasing, sentinel | Raw two-pointer interpretations checked against resolver and render-bounds consumers | Exact original record name unavailable |
| Formal C++ should remain blank now | High | Binary uses raw node/list internals, unresolved DAT object lifetime wrappers, and current support docs expose only low-level `DATIndexVectorNode*` insert/find declarations, not a source-ready key/value cache insertion API | Possible high-level wrapper body, support-doc `FindNodeByKey`/`InsertNode` composition, and raw decompiler-like body all considered and rejected | Needs a documented source-level cache/DAT ownership API before the method body can be written without invented wrappers or raw internals |
| The raw xref at `0x004dc279` is an out-of-target helper, not target padding | High | `insn_query` shows prologue at `0x004dc240`, call at `0x004dc279`, returns at `0x004dc270/0x004dc2b6/0x004dc2db`, align at `0x004dc2de` | `lookup_funcs` no function, `xrefs_to 0x004dc240` none | A separate future target could model it, but it does not block `00017E` |

## Positive Evidence Summary
- Direct facts supporting the recommendation:
  - `lookup_funcs 0x004dbe60` returns `sub_4DBE60`, size `0x315`; `tools/int_convert.py` verifies `0x315` is 789.
  - The target decompile and disassembly confirm the lazy cache-miss loader, DAT construction/opening, `+0x1c/+0x3c` cache inserts, header read, 24-byte entry allocation, entry loop, payload-base rebasing, and sentinel.
  - `xrefs_to 0x004dbe60` shows normal callers in `sub_4DB5C0` and `sub_4DC180`, both `MonsterImageLib` local methods.
  - `ClearLoadedData` walks and frees both the opened archive cache and the bounds-bucket cache, proving `MonsterImageLib` owns the allocations created here.
- Corroborating documentation/generated-report evidence:
  - Class, file, layout, bucket, entry, DATIndexVector, DATFile, and DATFileContainer docs all match the dependency direction and source route.
  - Generated coverage already points the target to `auto-generated/NexusTK/render/MonsterImageLib.cpp`, but with stale score and empty emitter marker.
- Strongest inference chain: the function's receiver layout, direct callers, cleanup ownership, path literal, and cache field writes all converge on `MonsterImageLib`, while DAT classes and bucket/entry structs are dependencies or data layouts rather than owners.

## IDA MCP Facts
- Function/range facts:
  - `lookup_funcs`: `0x004dbe60` -> `sub_4DBE60`, size `0x315`; `0x004dc174` still resolves inside `sub_4DBE60`; `0x004dc180` -> `sub_4DC180`, size `0xb5`.
  - Target `disasm`: return type `int`, arguments `this:_DWORD *` and `ArgList:int`, total 307 instructions, final normal ABI `retn 4`.
  - Target decompile prototype: `int __thiscall(_DWORD *this, int ArgList)`.
- Data/table/padding facts:
  - Bytes at `0x004dbe50` show previous return bytes, five `0xcc` bytes, and the target prologue at `0x004dbe60`.
  - Bytes at `0x004dc150` show final normal epilogue/retn at `0x004dc15e`, two list-too-long calls at `0x004dc166` and `0x004dc170`, then `0xcc` padding before the `0x004dc180` prologue.
  - Bytes at `0x0061c07c` decode as UTF-16LE `DATA/MON%d.DAT`, followed by `MON%d.EPF`.
- Xref facts:
  - `xrefs_to 0x004dbe60`: `0x004db647` in `sub_4DB5C0`; `0x004dc1b9` in `sub_4DC180`; raw code xref `0x004dc279` with no function.
  - `xrefs_to 0x004dc180`: `0x004db1a5` in `sub_4DB100` and `0x004db47a` in `sub_4DB3B0`.
  - `xrefs_to 0x0061c07c`: `0x004dbca1` in `sub_4DBC60` and `0x004dbeb4` in `sub_4DBE60`.
  - `xrefs_to 0x0049c720`: target at `0x004dbf2a` and archive loader at `0x004dbd53`.
  - `xrefs_to 0x00457580`: target at `0x004dbe9d` and `0x004dc139`.
  - `xrefs_to 0x00457100`: target at `0x004dbf97` and `0x004dc011`.
- Vtable/global/type facts:
  - DAT reader virtual calls through `[eax+0x18]` and `[eax+0x20]` are used for seek/read-style operations.
  - `sub_49C550` returns the DAT data pointer used as payload base; target xref at `0x004dc04d`.
  - `sub_4B7C50` initializes `RectBounds` in each entry and the sentinel.
- Negative IDA facts:
  - `xrefs_to 0x004db8b0` has zero callers.
  - `lookup_funcs 0x004dc240`, `0x004dc279`, and `0x004dc2a0` return not a function; `insn_query` proves the code exists but is not modeled as a function.
  - `xrefs_to 0x004dc240` has no xrefs to the helper start.

## Function / Child Inventory
| Range / Item | UID / Path | Role | Reconstructable | Direct Parent | Score | Status |
| --- | --- | --- | --- | --- | --- | --- |
| `0x004dbe60-0x004dc174` | `00017E` / target path | Lazy `DATA/MON%d.DAT` archive bounds bucket loader | TRUE | `00008N` | Current `85/90`, recommended `88/91` | Exact target, keep assigned/emitting, blank C++ |
| `0x004dc180-0x004dc234` | listed in cluster | Resolver/entry consumer reached by render methods | TRUE candidate | `MonsterImageLib` | cluster child not assigned here | Separate function, do not merge |
| `0x004dc240-0x004dc2db` | no UID found | IDA-undefined local helper copying `RectBounds` from a bucket entry | Unknown/not assigned | likely `MonsterImageLib` | none | Record as cluster gap, not target padding |
| `0x004db8b0-0x004dbc51` | listed in cluster | old `MON%d.EPF` merged-bounds builder-like helper | Reconstructable candidate but no live callers | `MonsterImageLib` cluster | cluster doc only | No callers, reject merge/owner route |
| `0x004dc2e0-0x004dc414` | cluster `ClearLoadedData` | Cleanup for open archive and bounds-bucket caches | TRUE candidate | `MonsterImageLib` | cluster child not assigned here | Confirms target allocation ownership |

## Direct Xref / Caller Inventory
| Address / Item | Xref / Caller / Callee | Meaning |
| --- | --- | --- |
| `0x004db647` | call to `0x004dbe60` from `sub_4DB5C0` | `ComputeRenderBounds` obtains a bucket and copies entry `RectBounds` when frame index is in range |
| `0x004dc1b9` | call to `0x004dbe60` from `sub_4DC180` | resolver obtains bucket and populates a render/payload output record |
| `0x004dc279` | raw call to `0x004dbe60` from IDA-undefined `0x004dc240` helper | separate local helper/gap, not a normal caller in current function table |
| `0x004db1a5` | call to `0x004dc180` from `sub_4DB100` | `RenderMonster` uses resolver path |
| `0x004db47a` | call to `0x004dc180` from `sub_4DB3B0` | `RenderMonsterImage` uses resolver path |
| `0x004dbeb4` | data xref to `0x0061c07c` | target formats `DATA/MON%d.DAT` |
| `0x004dbca1` | data xref to `0x0061c07c` | `LoadMonsterArchives` scans the same archive family |
| `0x004dbf97`, `0x004dc011` | calls to `DATIndexVectorInsertNode` | opened reader and bucket cache insertions |
| `0x004dbe9d`, `0x004dc139` | calls to `DATIndexVectorFindNodeByKey` | initial cache lookup and final return-from-cache path |
| `0x004dc04d` | call to `DATFile::GetDataPointer`-style helper | obtains payload base for pointer rebasing |
| `0x004dc0dd`, `0x004dc116` | calls to `RectBounds` initializer | initializes entries and sentinel |

## Documentation Evidence And IDA Status
- Existing docs that support the conclusion:
  - `by-class/MonsterImageLib.md` already owns the surrounding methods and documents `m_archiveOffsets`, `m_openArchiveIndex`, `m_boundsBucketIndex`, bucket entries, and cleanup ownership.
  - `by-file/MonsterImageLib.md` places the class in `NexusTK/render/MonsterImageLib.cpp` and already identifies `MONSTER.DNA`, `MONSTER.DND`, and `DATA/MON%d.DAT` as resource inputs.
  - `MonsterImageLibLayout.md` has the exact `+0x1c` and `+0x3c` DATIndexVector fields.
  - `MonsterArchiveBoundsBucket.md` and `MonsterArchiveBoundsEntry.md` already describe the 12-byte bucket and 24-byte entries this target confirms.
  - `DATIndexVector.md`, `DATFile.md`, and `DATFileContainer.md` provide the dependency classes this method uses.
- Existing docs that are stale, incomplete, or contradicted:
  - generated rows report old `78/88`;
  - file doc says target is disabled/excluded even though target metadata and generated memory coverage say it is emitted with an empty body;
  - local method cluster omits the IDA-undefined `0x004dc240-0x004dc2db` helper/gap;
  - target blank-C++ rationale should be replaced with a precise no-code proof rather than broad "final source names/C++ remain below final-audit".
- Generated/coverage report state:
  - `auto-generated/-ag-memory-coverage.md` row: `emits`, owner/emitter `00008N`, generated path `auto-generated/NexusTK/render/MonsterImageLib.cpp`, emits code `no`.
  - `auto-generated/-ag-research-tracker.md` row: stale `78/88`, combined `83.0`.
  - `auto-generated/-ag-coverage-report-by-memory.md` row: stale `78%` with old summary.
  - `auto-generated/NexusTK/render/MonsterImageLib.cpp` line for UID `00017E` is an empty emitter marker with old `Completion:78 | Confidence:88`.

## Ranked Ownership Analysis

### 1. [UID:00008N] `by-class/MonsterImageLib.md`
- Evidence for: all normal callers are `MonsterImageLib` methods; target receiver offsets match `MonsterImageLibLayout`; target constructs `DATA/MON%d.DAT` archive-specific bounds for monster image rendering; `ClearLoadedData` frees the exact caches and allocations; file doc already owns neighboring monster table/archive logic.
- Evidence against: original source symbols are unavailable; the raw helper at `0x004dc240` is not modeled as a function in IDA. These do not weaken class ownership because the raw helper also uses the same `MonsterImageLib` layout.
- Decision: keep as canonical owner/emitter.

### 2. [UID:0000LJ] `by-file/MonsterImageLib.md`
- Evidence for: direct source file for the class and neighboring methods; path/resource domain is monster rendering; target generated output already lands in `NexusTK/render/MonsterImageLib.cpp`.
- Evidence against: the file doc itself should not be the direct canonical owner while the class owner is available and already passes the gate.
- Decision: keep as source file through class route; update stale "disabled/excluded" wording.

### 3. DAT subsystem docs (`DATFile`, `DATFileContainer`, `DATIndexVector`, `DATArchive`)
- Evidence for: target constructs DAT container/reader objects, uses `OpenByIndex`, `Read`/`Seek` virtual calls, `GetDataPointer`, and DATIndexVector find/insert helpers.
- Evidence against: all DAT docs are callees/shared containers; they do not own the `MonsterImageLib` caches, archive key semantics, path format decision, or cleanup.
- Decision: reject as owner; use only as support dependencies and C++ blocker context.

### 4. Bucket/entry layout docs
- Evidence for: target creates and fills `MonsterArchiveBoundsBucket` and `MonsterArchiveBoundsEntry` data.
- Evidence against: types are data layouts owned by/used under `MonsterImageLib`; they do not own the method's control flow or DAT file opening.
- Decision: reject as owner; update support evidence.

### 5. Local aggregate `0x004dac40-0x004dc420`
- Evidence for: address cluster and method inventory contain the target.
- Evidence against: aggregate is intentionally non-reconstructable and mixed across many functions; exact child owner exists.
- Decision: reject as direct owner/emitter; update cluster inventory facts.

## Source Placement
- Recommended placement: `MonsterImageLib::GetArchiveBoundsBucket(int archiveIndex)` under `by-class/MonsterImageLib.md`, emitted to `NexusTK/render/MonsterImageLib.cpp` through `by-file/MonsterImageLib.md`.
- Why this placement fits: the method consumes class fields, is called by class render helpers, creates class-owned cache entries, and is cleaned by the class destructor/ClearLoadedData path. The string and archive logic are specific to monster image resources.
- Rejected placements:
  - `NexusTK/archive`: DAT code is dependency-only.
  - `NexusTK/ui/core`: `RectBounds` initializer is dependency-only.
  - a new `MonsterArchiveBounds` source file: no independent owner or non-class xrefs support it.
  - `0x004db8b0` EPF builder: no callers, different string/resource path.
- Remaining placement uncertainty: exact original method and member spelling is inferred, not symbol-proven. This affects final C++ wording, not owner/emitter.

## Range / Split / Padding / Reclassification Analysis
- Exact target range facts:
  - target function start `0x004dbe60`;
  - `lookup_funcs` size `0x315` means 789 bytes;
  - target body includes SEH/security-cookie setup, normal return at `0x004dc15e`, and two list-too-long throw calls at `0x004dc166` and `0x004dc170`;
  - last call ends at `0x004dc174`; padding begins at `0x004dc175`; next modeled function starts at `0x004dc180`.
- Children/subranges:
  - no split inside `00017E`;
  - do not widen to include `0x004dc180` resolver or `0x004dc240` raw helper;
  - do not merge with `0x004db8b0` EPF builder.
- Padding/table/data/code distinctions:
  - `0x004dc175-0x004dc17f` is padding before `0x004dc180`;
  - `0x004dc235` and `0x004dc2de` are align directives around the IDA-undefined helper;
  - `0x004dc240-0x004dc2db` is code-looking and source-bearing but outside this target.
- Parent/container impact: local method cluster should mention the raw helper/gap and normal caller grouping. No target split is needed.

## Negative Evidence Summary
- Consumer/read xrefs do not prove ownership outside `MonsterImageLib`; they only prove render-path use. Ownership is assigned because the same class initializes, caches, consumes, and cleans the data.
- DAT helper callees do not prove DAT ownership; the target supplies the monster-specific archive index and path format.
- Adjacency to `0x004dc180` and `0x004dc240` does not prove a merge; both have separate prologues/returns or function starts and distinct consumer roles.
- The old `0x004db8b0` EPF builder shares entry-shape behavior, but has no direct callers and uses `MON%d.EPF`; it is not the live DAT lazy-loader.
- The fact that formal C++ is blank does not make the target no-owner/non-emitting. It only means generated code remains an empty marker until the source-level helper APIs are safe.

## IDA Rename / Type / Comment Recommendations
- Proposed source-facing names/types for docs, not IDA DB:
  - `MonsterImageLib::GetArchiveBoundsBucket(int archiveIndex)`
  - return `MonsterArchiveBoundsBucket *`
  - `m_openArchiveIndex` for `+0x1c`
  - `m_boundsBucketIndex` for `+0x3c`
  - `MonsterArchiveBoundsBucket::entryCount`, `maxExtent02`, `maxExtent04`, `header06`, `entries`
  - `MonsterArchiveBoundsEntry::rect`, `payloadStart`, `payloadEnd`
  - descriptive locals in prose only: archive path, DAT container, DAT reader, entry table offset, payload base, entry cursor.
- Evidence for each: see MCP facts and layout support docs above.
- Items intentionally left unchanged:
  - no IDA function rename, type declaration, stack variable declaration, or comment changes should be made during this report-only pass;
  - raw `0x004dc240` helper should not receive a formal name in this report because it lacks a modeled function/UID and has no start xrefs.
- Whether IDA DB edits are safe: not requested and prohibited by the assignment.

## First-Draft C++ Recommendation
- Eligible for draft C++: metadata gate says yes (`RECONSTRUCTABLE:TRUE`, owner/emitter set, average score above 85), but source-quality C++ should not be inserted yet.
- Recommended code: keep the formal `RECONSTRUCTION_CPP CODE` block blank.
- Third-party import directive: not applicable.
- Reason code should remain blank:
  - The binary body exposes raw `DATIndexVector` implementation details: direct sentinel comparison, `sub_4570E0` node allocation, manual list links, node-count increments, and `sub_457100` insertion calls. A source-quality body cannot safely use raw `this[15]`/node internals, but no current support doc proves a high-level cache API that would reproduce the exact behavior.
  - The current `DATIndexVector` class declaration is useful but insufficient for this method body: it has `FindNodeByKey(const int& key)` and `InsertNode(DATIndexVectorNode* node, bool* inserted)`, while this target creates raw key/value nodes, patches list state, increments node counts, then calls `InsertNode`. A formal method body would therefore have to either expose raw node construction/list mutation in `MonsterImageLib` source or invent a higher-level `insert(key, value)` API that the current docs do not support.
  - The method heap-allocates both a `DATFileContainer`-like object and a `DATFile`-like reader, has compiler EH cleanup states for those allocations, stores reader ownership in `m_openArchiveIndex`, and relies on `ClearLoadedData` to destroy both reader/container and bucket/entry arrays. A formal body would need exact ownership wrapper semantics, not just behavior prose.
  - `DATFile` virtual calls at `+0x18` and `+0x20` are behavior-clear as seek/read, but the exact public declaration/source spelling of those methods, the `OpenByIndex`/`GetDataPointer` interaction, and the heap lifetime split between `DATFileContainer` and `DATFile` remain unresolved in the support docs that would be required for a human-looking source body.
  - The middle bucket header fields `+0x02/+0x04/+0x06` are direct data fields but original names are not proven. A full method body could use neutral names, but the larger blocker is the source-level container/cache API.
  - Emitting raw decompiler-style C++ would violate source-quality rules; emitting clean high-level C++ would invent APIs not currently documented. The correct report outcome is source-ready documentation with a blank formal code block.
- Exact no-code proof: live MCP proves the target behavior and owner well enough for `88/91`, and the current pass explicitly audited the dependent `DATIndexVector`, `DATFile`, `DATFileContainer`, bucket, entry, and layout support docs. Those docs are strong enough to document this method but not strong enough to supply a source-ready cache node/value insertion API or heap-owned DAT reader/container lifetime API. Therefore a formal `RECONSTRUCTION_CPP CODE` body is unsafe now: it would either encode raw node/list internals in `MonsterImageLib` source, use decompiler-shaped storage such as `this[15]`, or invent a higher-level cache wrapper that is not supported by current evidence.

## Final Recommendation
- Exact changes recommended:
  - update target metadata to `COMPLETION:88` and `CONFIDENCE:91`;
  - keep owner/emitter/reconstructable and blank emitter position unchanged;
  - keep formal C++ block blank;
  - replace broad stale blank-C++ reason with the no-code proof above;
  - add live MCP evidence, boundary/padding, caller/callee, string, cache, layout, cleanup, and raw helper-gap facts.
- Exact parent assignments recommended: keep `CANONICAL_OWNER:00008N`; keep `EMITTER_UIDS:00008N`.
- Exact items left no-owner/non-emitting and why: none inside this target. The `0x004dc240-0x004dc2db` raw helper is outside this target and has no UID in this report; only document it as a local-cluster gap/candidate.
- Exact future work outside this assignment scope: a separate supervisor assignment may create/model the `0x004dc240-0x004dc2db` helper if coverage requires it. This is not a blocker for implementing `00017E` target/support documentation.

## Recommended Target Doc Changes
- Target path: `by-memory/0x004dbe60-0x004dc174.MonsterImageLibGetArchiveBoundsBucket.md`.
- Exact report facts to incorporate:
  - live MCP session `80de0a67` health and IDB path;
  - `lookup_funcs` target/neighbor sizes and exact boundary;
  - raw bytes at start/end proving padding before and after;
  - decompile/disasm evidence for cache lookup, DAT path formatting, DAT container/reader construction, `OpenByIndex`, seek/read virtuals, open reader cache insert, bucket allocation/cache insert, header read, entry allocation, entry loop, pointer rebasing, sentinel, final return;
  - `xrefs_to` target, resolver, string, DAT helpers, DATIndexVector helpers;
  - raw helper `0x004dc240-0x004dc2db` as out-of-target caller/gap;
  - `int_convert.py` checks for all cited sizes/offsets;
  - cleanup ownership via `ClearLoadedData`.
- Metadata/score/owner/emitter/reconstructable/C++ changes:
  - `COMPLETION:85` -> `COMPLETION:88`;
  - `CONFIDENCE:90` -> `CONFIDENCE:91`;
  - keep `CANONICAL_OWNER:00008N`;
  - keep `RECONSTRUCTABLE:TRUE`;
  - keep `EMITTER_UIDS:00008N`;
  - keep blank `EMITTER_POSITION_OPTIONAL`;
  - keep formal C++ block blank.
- Suggested Item Summary replacement:
  - `Live MCP session 80de0a67 confirms the exact 0x315-byte lazy DATA/MON%d.DAT bounds-bucket loader: it looks up the +0x3c bounds-bucket cache, constructs/opens the missing archive, inserts the reader through the +0x1c open-archive cache, allocates and caches a 0x0c bucket, reads an 8-byte header, allocates 0x18-byte entries plus a zero-bounds sentinel, rebases payload pointers by the DAT payload base, and returns the cached bucket; source owner/emitter remain MonsterImageLib, while formal C++ remains intentionally blank pending source-ready cache/DAT ownership APIs.`
- Historical/stale assumptions, rejected alternatives, and negative evidence to preserve:
  - generated `78/88` rows are stale;
  - old "disabled/excluded" wording is stale;
  - raw `sub_4DBE60`/`ArgList`/`this[15]` names rejected;
  - `DWORD`/`long`/`void *` source types rejected;
  - DAT/DATIndexVector/layout/caller/aggregate ownership rejected;
  - merge with resolver, raw helper, padding, or EPF builder rejected;
  - no formal C++ yet for exact source API reasons.

## Recommended Support Doc Changes
- `by-class/MonsterImageLib.md`:
  - Update the method inventory row for `GetArchiveBoundsBucket` to say [UID:00017E] is source-placement/source-behavior ready, owner/emitter-confirmed, and still formal-C++ blank under a specific cache/DAT API no-code proof.
  - Add current MCP evidence summary for `+0x1c` open archive cache, `+0x3c` bounds bucket cache, `DATA/MON%d.DAT`, bucket/entry allocation, cleanup ownership, and normal caller grouping.
  - Record the raw `0x004dc240-0x004dc2db` helper as an IDA-undefined local helper/gap if the class inventory section tracks local functions.
  - Recommended score: `86/88` -> `87/89`. Do not go higher because constructor/render helper/formal declaration work and exact C++ for this target remain incomplete.
- `by-file/MonsterImageLib.md`:
  - Replace stale "disabled/excluded from active emission" wording for [UID:00017E] with "emitted through the class route as an empty marker/no-code child pending source-ready cache/DAT API declarations."
  - Preserve broad file/aggregate C++ blank and source-root caveats.
  - No score change recommended.
- `by-memory/0x004dac40-0x004dc420.MonsterImageLibLocalMethodCluster.md`:
  - Update the target inventory row/facts for `0x004dbe60-0x004dc174`.
  - Add a cluster note that live MCP found an IDA-undefined prologued helper at `0x004dc240-0x004dc2db`, with a raw call to target at `0x004dc279`, no xrefs to the helper start, and alignment before `ClearLoadedData`. Do not merge it with [UID:00017E].
  - Preserve aggregate `RECONSTRUCTABLE:FALSE` and no aggregate C++.
  - No score change required unless the supervisor chooses to credit the inventory correction.
- `by-type/by-struct/MonsterImageLibLayout.md`:
  - Add live MCP evidence for `m_openArchiveIndex` at `+0x1c` and `m_boundsBucketIndex` at `+0x3c`: target inserts reader into the former and bucket into the latter; cleanup frees/clears both.
  - Preserve `+0x0c` reserved/unobserved caveat and broader original-spelling caveats.
  - Optional score change only if desired: `86/90` -> `87/90`; no required score change.
- `by-type/by-struct/MonsterArchiveBoundsBucket.md`:
  - Add live MCP evidence that target allocates 0x0c bytes, reads exactly 8 header bytes, stores the entry pointer at `+0x08`, inserts the bucket into `m_boundsBucketIndex`, and consumers use `entryCount` and `entries`.
  - Preserve neutral names for `+0x02/+0x04/+0x06` because live render consumers still do not prove original names.
  - No required score change.
- `by-type/by-struct/MonsterArchiveBoundsEntry.md`:
  - Add live MCP evidence that target allocates 0x18-byte rows plus one sentinel, reads four signed 16-bit bounds and two 32-bit offsets, initializes `RectBounds`, rebases both pointers by DAT payload base, and writes a zero-bounds sentinel with both pointers set to `payloadBase + entryTableOffset`.
  - Preserve original-name caveat; no required score change.
- `by-class/DATIndexVector.md` and exact child docs:
  - No required support edit. If touched for context, only add a cross-reference that [UID:00017E] uses `FindNodeByKey` twice and `InsertNode` twice through raw node/list storage; do not claim a high-level map API exists.
- `by-class/DATFile.md`, `by-class/DATFileContainer.md`, and `by-memory/0x0049c130-0x0049d2cc.DATFile.md`:
  - No required support edit. The target report can cite them as dependencies; do not alter their unresolved field/API caveats from this target alone.
- Generated reports and generated C++:
  - Do not edit directly. Validators/supervisor execute step should refresh stale generated metadata and the `MonsterImageLib.cpp` empty marker header.

## Score And Metadata Recommendation
- Current score/metadata:
  - `COMPLETION:85`
  - `CONFIDENCE:90`
  - `CANONICAL_OWNER:00008N`
  - `RECONSTRUCTABLE:TRUE`
  - `EMITTER_UIDS:00008N`
  - blank `EMITTER_POSITION_OPTIONAL`
  - blank formal C++.
- Recommended score/metadata:
  - `COMPLETION:88`
  - `CONFIDENCE:91`
  - owner/emitter/reconstructable/emitter-position unchanged
  - formal C++ remains blank.
- Score rationale:
  - Up: live MCP refresh, exact boundary/padding, ABI, direct xrefs, raw helper resolution, source owner/source-file placement, field/type names, cleanup ownership, and no-code proof are now implementation-ready.
  - Not higher: original source symbols are unavailable, exact local variable names are unavailable, target C++ still cannot be written without unresolved `DATIndexVector`/DAT ownership API shape, and `0x004dc240` remains a separate unmodeled helper outside target.
- Score-improvement attempt:
  - Boundary blocker: resolved with `lookup_funcs`, `get_bytes`, and disasm.
  - Raw xref blocker: resolved as out-of-target helper/gap with `insn_query`.
  - Source owner blocker: resolved to `MonsterImageLib` with callers, layout, string, and cleanup.
  - DAT/cache naming blocker: source-facing names supported by current docs and target access; exact original spelling still not provable but no longer blocks documentation.
  - Formal C++ blocker: investigated through target decompile, DATIndexVector class/method docs, DATFile/DATFileContainer docs, bucket/entry/layout docs, cleanup, and raw list-node evidence. Current support declarations do not provide the required source-level key/value cache insertion or DAT lifetime API, so the blocker remains only as a precise no-code proof, not as unperformed future research.
- Metadata fields to leave unchanged: `CANONICAL_OWNER`, `RECONSTRUCTABLE`, `EMITTER_UIDS`, `EMITTER_POSITION_OPTIONAL`.

## Open Questions With Attempted Resolution
- Open question: should `00017E` emit formal C++ now?
  - Evidence checked: target decompile/disasm, DATIndexVector declaration/docs, InsertNode/FindNode docs, DATFile/DATFileContainer docs, cleanup ownership, local source style from `LoadMonsterTables`.
  - Resolution: no. Behavior is source-ready, but formal body is unsafe because the source-level cache/reader ownership APIs are not settled.
  - Score/C++ impact: target can rise to `88/91`; C++ remains blank.
- Open question: does raw xref `0x004dc279` imply the target range is incomplete?
  - Evidence checked: `lookup_funcs`, `xrefs_to`, `xref_query`, `search_text`, `insn_query`, raw bytes.
  - Resolution: no. It is an IDA-undefined helper at `0x004dc240-0x004dc2db`, outside target, with no xrefs to start. Document as cluster gap.
  - Score/range impact: no split of target; support cluster update recommended.
- Open question: do `+0x02/+0x04/+0x06` bucket header fields have final original names?
  - Evidence checked: target load, old EPF builder report, consumers, bucket support doc.
  - Resolution: use neutral descriptive names already present (`maxExtent02`, `maxExtent04`, `header06`) and preserve original-spelling caveat.
  - Score impact: no target blocker; support type names remain cautious.
- Open question: is `DATA/MON%d.DAT` string proof reliable despite `get_string` returning `DA`?
  - Evidence checked: raw bytes at `0x0061c07c`, xrefs to the address, LoadMonsterArchives shared xref.
  - Resolution: yes. It is UTF-16LE; `get_string` truncation is a tool limitation.

## Exact Manual Supervisor-Owned Coverage Or Tracker Text
- Not applicable. Do not edit manual `-coverage-report.md` files or validator-owned `auto-generated/-ag-*` reports for this target.
- Generated rows should refresh through target/support validators and the supervisor `execute_report` flow.

## Follow-Up Actions
- Supervisor actions:
  - Review this report and decide whether to accept the target/support edits.
  - If accepted, send implementation callback with the files listed in the checklist.
  - After implementation validation, execute the report with validator `execute_report` so generated tracker rows refresh.
- A-agent actions: none requested.
- B003 future research actions: none required for [UID:00017E]. A separate assignment can cover the unmodeled `0x004dc240-0x004dc2db` helper if the supervisor wants a new UID/child.

## Confidence
- Recommendation confidence: high for owner/source placement and target behavior.
- Score confidence: medium-high. `88/91` is conservative because formal C++ remains blank.
- Remaining uncertainty: original source spelling and high-level helper/API shapes for the cache and DAT reader ownership model.

## Validator Results
- Implementation validators run from `E:\NTK\GhidraBridge\source-3\project-documentation`:
  - `python .\tools\validator.py --mode file --file by-memory/0x004dbe60-0x004dc174.MonsterImageLibGetArchiveBoundsBucket.md --apply --queue-timeout 240 --wait-generated`
    - exit code `0`; `command_id: 000000004106`; `command_timestamp: 2026-06-27T10:32:20-04:00`; `ok: 1`; generated refresh completed for command `000000004106`.
  - `python .\tools\validator.py --mode file --file by-class/MonsterImageLib.md --apply --queue-timeout 240`
    - exit code `0`; `command_id: 000000004107`; `command_timestamp: 2026-06-27T10:32:40-04:00`; `ok: 1`; generated refresh deferred.
  - `python .\tools\validator.py --mode file --file by-file/MonsterImageLib.md --apply --queue-timeout 240 --wait-generated`
    - exit code `0`; `command_id: 000000004108`; `command_timestamp: 2026-06-27T10:32:47-04:00`; `ok: 1`; generated refresh completed for command `000000004108`.
  - `python .\tools\validator.py --mode file --file by-memory/0x004dac40-0x004dc420.MonsterImageLibLocalMethodCluster.md --apply --queue-timeout 240`
    - exit code `0`; `command_id: 000000004109`; `command_timestamp: 2026-06-27T10:33:02-04:00`; `ok: 1`; generated refresh deferred.
  - `python .\tools\validator.py --mode file --file by-type/by-struct/MonsterImageLibLayout.md --apply --queue-timeout 240`
    - exit code `0`; `command_id: 000000004110`; `command_timestamp: 2026-06-27T10:33:09-04:00`; `ok: 1`; generated refresh deferred.
  - `python .\tools\validator.py --mode file --file by-type/by-struct/MonsterArchiveBoundsBucket.md --apply --queue-timeout 240`
    - exit code `0`; `command_id: 000000004111`; `command_timestamp: 2026-06-27T10:33:20-04:00`; `ok: 1`; generated refresh deferred.
  - `python .\tools\validator.py --mode file --file by-type/by-struct/MonsterArchiveBoundsEntry.md --apply --queue-timeout 240`
    - exit code `0`; `command_id: 000000004112`; `command_timestamp: 2026-06-27T10:33:26-04:00`; `ok: 1`; generated refresh deferred.
- Validator side effects:
  - Target score updated to `88/91`; class score updated to `87/89`.
  - Validator inserted missing UID links for [UID:00017E] references in the class/file/cluster docs.
  - Validator refreshed projected stats and validator-owned generated state; the `--wait-generated` target/file commands completed generated refresh.
  - A later deferred generated refresh caught up at `auto-generated/NexusTK/render/MonsterImageLib.cpp` with `validator-command-id: 000000004112`; the generated marker now shows `UID:00017E` as `Completion:88 | Confidence:91 | Empty Emitter Marker`.
  - The target/file `--wait-generated` commands reported unrelated existing stale registry/missing-file warnings (`autogen_registry_stale`/`memory_coverage_metadata_missing_file`) outside this target family. They did not block the scoped files (`ok: 1`).

## Changed Files
- Created: `tools/leaser/Agents/Agent-B003/research/00017E-MonsterImageLibGetArchiveBoundsBucket-source-quality.md`.
- Modified by implementation callback:
  - `by-memory/0x004dbe60-0x004dc174.MonsterImageLibGetArchiveBoundsBucket.md`
  - `by-class/MonsterImageLib.md`
  - `by-file/MonsterImageLib.md`
  - `by-memory/0x004dac40-0x004dc420.MonsterImageLibLocalMethodCluster.md`
  - `by-type/by-struct/MonsterImageLibLayout.md`
  - `by-type/by-struct/MonsterArchiveBoundsBucket.md`
  - `by-type/by-struct/MonsterArchiveBoundsEntry.md`
  - validator-owned generated/project state refreshed by scoped validators.
- Renamed: none.
- Report execution: pending supervisor verification. The supervisor runs `tools/validator.py execute_report ... --apply` after claim-by-claim verification.

## Lease Cleanup
- B003 acquired short implementation leases for the seven target/support by-* docs before editing.
- Cleanup command `python .\tools\leaser\leaser.py B003 unlease ...` returned `Rejected[No active lease]` for each path, meaning the leases had already expired or been cleared.
- `tools/leaser/Agents/current_leases.md` was checked after cleanup and contains no B003 lease entries.

## Implementation Tracking Checklist

Initial report-only pass:
- [x] Supervisor validation required before implementation. Proof: implementation callback accepted this report and assigned these exact edits.
- [x] Target/support docs updated:
  - [x] `by-memory/0x004dbe60-0x004dc174.MonsterImageLibGetArchiveBoundsBucket.md` updated with `88/91`, live MCP evidence, no-code proof, and rejected alternatives.
  - [x] `by-class/MonsterImageLib.md` updated with method row, source-quality sync, empty-marker/no-code disposition, raw helper-gap note, and `87/89` score.
  - [x] `by-file/MonsterImageLib.md` updated to replace stale disabled/excluded wording with class-routed empty-marker/no-code disposition.
  - [x] `by-memory/0x004dac40-0x004dc420.MonsterImageLibLocalMethodCluster.md` updated with [UID:00017E] row detail and `0x004dc240-0x004dc2db` helper/gap note.
  - [x] `by-type/by-struct/MonsterImageLibLayout.md` updated with `+0x1c/+0x3c` live MCP support and `+0x0c` caveat.
  - [x] `by-type/by-struct/MonsterArchiveBoundsBucket.md` updated with 0x0c allocation, 8-byte header, `+0x08` pointer, cache insertion, and neutral-name caveat.
  - [x] `by-type/by-struct/MonsterArchiveBoundsEntry.md` updated with 0x18 rows, RectBounds initialization, payload-base rebasing, and sentinel proof.
- [x] Current target state and actual evidence checked recorded. Proof: target/support docs now record live MCP session `80de0a67`, server/IDB health, range/boundary/caller/string/cache facts, raw helper-gap checks, cleanup ownership, and support docs.
- [x] Metadata/score changes applied:
  - [x] target `COMPLETION:85` -> `COMPLETION:88`.
  - [x] target `CONFIDENCE:90` -> `CONFIDENCE:91`.
  - [x] class score `86/88` -> `87/89`.
  - [x] file/cluster/type support docs kept current scores as accepted.
- [x] Score-limiting blockers documented as resolved/no-code:
  - [x] boundary/padding resolved in target evidence.
  - [x] raw xref `0x004dc279` documented as separate `0x004dc240-0x004dc2db` helper/gap in target and cluster.
  - [x] owner/source placement documented under `MonsterImageLib` / `NexusTK/render/MonsterImageLib.cpp`.
  - [x] cache/bucket/entry names documented as source-facing inferred names.
  - [x] formal C++ blocker documented as exact no-code proof.
- [x] Owner/emitter/reconstructable fields kept as accepted:
  - [x] `CANONICAL_OWNER:00008N`.
  - [x] `RECONSTRUCTABLE:TRUE`.
  - [x] `EMITTER_UIDS:00008N`.
  - [x] blank `EMITTER_POSITION_OPTIONAL`.
- [x] Split/rename/new-child disposition applied:
  - [x] no split or rename for [UID:00017E].
  - [x] no new child created.
  - [x] local cluster note added for `0x004dc240-0x004dc2db` helper/gap.
- [x] Source-placement/range/reclassification/IDA DB decisions applied:
  - [x] source placement under `MonsterImageLib`/`NexusTK/render/MonsterImageLib.cpp` documented.
  - [x] `0x004dc175-0x004dc17f` padding before `0x004dc180` documented.
  - [x] `0x004dc240-0x004dc2db` documented as out-of-target IDA-undefined helper/gap.
  - [x] no IDA DB rename/type/comment edits made.
- [x] First-draft C++ / no-code proof applied:
  - [x] target formal C++ block remains blank.
  - [x] exact no-code proof added for raw DATIndexVector node/list internals and DAT reader/container ownership API uncertainty.
- [x] Third-party import directive not applicable:
  - [x] no import directive; multiline C++ block remains blank.
- [x] Exact target/support doc facts incorporated at report-level detail:
  - [x] live MCP endpoint/session/health facts.
  - [x] lookup/range/ABI/instruction facts where relevant to docs.
  - [x] boundary/padding bytes.
  - [x] decompile/disasm behavior facts.
  - [x] xref/caller/callee/string facts.
  - [x] int_convert.py conversion facts.
  - [x] cleanup ownership facts.
  - [x] generated stale state facts.
- [x] Historical/stale assumptions, rejected alternatives, and negative evidence preserved:
  - [x] stale generated `78/88`.
  - [x] stale disabled/excluded file-doc wording corrected and preserved as a change note.
  - [x] rejected raw/decompiler names and raw source types.
  - [x] rejected DAT/caller/type/aggregate ownership.
  - [x] rejected merge with resolver, raw helper, padding, and EPF builder.
  - [x] `xrefs_to 0x004db8b0` zero-callers.
  - [x] no IDA DB edits.
- [x] Wave2/Wave3 mentions/artifacts: none found in checked target/support docs.
- [x] Open questions closed or documented:
  - [x] owner/source/range/raw-xref questions closed.
  - [x] unresolved original source spelling and formal C++ API shape documented as no-code proof.
- [x] Validators run after accepted implementation edits:
  - [x] target validator: `000000004106`, exit `0`, `ok: 1`, generated refresh completed.
  - [x] class validator: `000000004107`, exit `0`, `ok: 1`.
  - [x] file validator: `000000004108`, exit `0`, `ok: 1`, generated refresh completed.
  - [x] cluster validator: `000000004109`, exit `0`, `ok: 1`.
  - [x] layout validator: `000000004110`, exit `0`, `ok: 1`.
  - [x] bucket validator: `000000004111`, exit `0`, `ok: 1`.
  - [x] entry validator: `000000004112`, exit `0`, `ok: 1`.
- [x] Generated report refresh / coverage/tracker:
  - [x] validator-owned generated state refreshed by scoped validators where applicable; generated refresh completed for target/file `--wait-generated` commands.
  - [x] no manual coverage/tracker text applied or edited by B003.

Implementation callback pass:
- [x] Report accepted by supervisor for implementation.
- [x] All accepted target/support doc details incorporated at report-level detail.
- [x] Metadata/score/owner/emitter/split/rename/C++ changes applied or explicitly not applied with reason.
- [x] Historical/stale assumptions, rejected alternatives, and negative evidence preserved.
- [x] Open questions resolved or documented with evidence-backed unresolved rationale.
- [x] Validators run and results recorded.
- [x] Generated report refresh completed by validator where required; no manual coverage/tracker text supplied/edited by B003.
- [x] Remaining unapplied accepted items listed with exact blocker: none.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B003","command_id":"000000004165","destination_path":"executed-b-agent-research/B003/00017E-MonsterImageLibGetArchiveBoundsBucket-source-quality.md","details":"legacy registry reconstruction","event":"executed","source_path":"tools/leaser/Agents/Agent-B003/research/00017E-MonsterImageLibGetArchiveBoundsBucket-source-quality.md","timestamp":"2026-06-27T10:40:29","uid":"00017E"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
