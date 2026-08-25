** TARGET-REPORT-UID:00012B **
** AUTHOR-AGENT-ID:B002 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# B002 Source-Quality Report: [UID:00012B] DATManagers

Assignment: `B002-report-00012B-dat-managers-source-quality-20260626`  
Rework assignment: `B002-rework-00012B-dat-managers-source-quality-20260626`  
Second rework assignment: `B002-rework2-00012B-dat-managers-source-quality-20260626`  
Target: [UID:00012B] `by-memory/0x0049bd30-0x0049d6ed.DATManagers.md`  
Mode: report-only research first. No by-* target/support docs, generated files, validator state/cache, IDA DB, or coverage reports were edited.

## Current Target State

Live target metadata before this report:

| Field | Value |
| --- | --- |
| `COMPLETION` | `86` |
| `CONFIDENCE` | `88` |
| `CANONICAL_OWNER` | `0000IO` |
| `RECONSTRUCTABLE` | `TRUE` |
| `EMITTER_UIDS` | `0000IO` |
| formal C++ | blank |

The page currently describes a broad `DATFileMgr.cpp` manager/container/resolver aggregate. The central stale blocker is not lack of evidence for one body; it is that the half-open range `0x0049bd30-0x0049d6ed` contains multiple source owners and several unmodeled raw destructor/EH-helper bodies. A single formal C++ block on [UID:00012B] would duplicate or misplace code that belongs to exact child targets and existing non-manager pages.

Rework decision: [UID:00012B] must be a non-emitting overlap/index page, not a reconstructable emitter. The implementation callback should set `CANONICAL_OWNER:NONE`, `RECONSTRUCTABLE:FALSE`, blank `EMITTER_UIDS`, blank `EMITTER_POSITION_OPTIONAL`, and keep the formal C++ block empty. The source route `NexusTK/archive/DATFileMgr.cpp`/[UID:0000IO] remains valid for manager-owned child methods only; direct class/file ownership and emitter routing belong on exact child pages, not on this mixed parent.

## Live IDA MCP Evidence

MCP evidence is live from session `80de0a67`.

| Evidence item | Result |
| --- | --- |
| `idb_list` | one active owned/adopted worker session, `pid=26892`, `is_analyzing=false` |
| `server_health` | `status=ok`, `idb_path=E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, `module=NexusTK.exe`, `input_path=C:\Users\admin\Desktop\Clone\NexusTK\NexusTK.exe`, `imagebase=0x400000`, `auto_analysis_ready=true`, `hexrays_ready=true`, `strings_cache_ready=true`, `strings_cache_size=2067` |
| evidence timestamp | original evidence pass `2026-06-26T01:29:46-04:00`; first rework refresh `2026-06-26T01:43:59-04:00`; second rework refresh `2026-06-26T02:03:41-04:00`; formal-block rework refresh `2026-06-26T02:58:38-04:00` from active worker session `80de0a67` |

Key live MCP calls used: `lookup_funcs`, `list_funcs`, `decompile`, `insn_query`, `callees`, `xrefs_to`, `get_bytes`, `get_int`, `get_global_value`, `make_signature_for_range`, and `entity_query`. The formal-block refresh also rechecked `idb_list`, `server_health(database=80de0a67)`, and `lookup_funcs(database=80de0a67)` for raw starts `0x0049be50`, `0x0049c0d0`, and `0x0049c750`; the session stayed active/owned/adopted with `pid=26892`, `is_analyzing=false`, `status=ok`, `auto_analysis_ready=true`, `hexrays_ready=true`, and those three raw starts still reported `Not a function`.

## Exact Range And Child Map

IDA `lookup_funcs`/`list_funcs` shows 42 modeled functions from `0x0049bd00-0x0049d720`; [UID:00012B] itself spans a mixed island, not only manager methods.

| Range | IDA state | Owner/disposition |
| --- | --- | --- |
| `0x0049bd20-0x0049bd2c` | raw/no function; outside target | existing [UID:000227] public `DATFileMgr::FindEntryByName` forwarder; preserve outside [UID:00012B] |
| `0x0049bd2c-0x0049bd30` | `cc cc cc cc` | padding before target start |
| `0x0049bd30-0x0049be41` | `sub_49BD30`, size `0x111` | `DATFileMgr::DATFileMgr`, manager-owned |
| `0x0049be41-0x0049be50` | fifteen `cc` bytes after ctor `ret` | padding |
| `0x0049be50-0x0049be6d` | raw/no function, unique signature | ordinary `DATFileMgr::~DATFileMgr`, manager-owned; no direct xrefs |
| `0x0049be6d-0x0049be70` | three `cc` bytes | padding |
| `0x0049be70-0x0049be7c` | `sub_49BE70`, size `0x0c` | existing [UID:00012C] public `DATFileMgr::LoadDATFile`/`LoadDATFileIndex` forwarder |
| `0x0049be7c-0x0049be80` | four `cc` bytes | padding |
| `0x0049be80-0x0049c0c9` | `sub_49BE80`, size `0x249` | `DATFileContainer::DATFileContainer`, manager/file-owned |
| `0x0049c0c9-0x0049c0d0` | seven `cc` bytes | padding |
| `0x0049c0d0-0x0049c130` | raw/no function, unique signature | ordinary `DATFileContainer::~DATFileContainer`, manager/file-owned; no direct xrefs |
| `0x0049c130-0x0049c6f2` | modeled DATFile methods | non-owner overlap; belongs to [UID:00012D]/[UID:0000IN] DATFile |
| `0x0049c700-0x0049c71d` | `sub_49C700`, size `0x1d` | existing [UID:00012E] `HasDATEntry`, manager-file free helper |
| `0x0049c720-0x0049c74b` | `sub_49C720`, size `0x2b` | non-owner DATFile `OpenByIndex` |
| `0x0049c74b-0x0049c750` | five `cc` bytes | padding |
| `0x0049c750-0x0049c7f7` | raw/no function; last live byte `0x0049c7f6` | existing [UID:00012F] ordinary `_DATFileMgr::~_DATFileMgr`; no start xrefs |
| `0x0049c7f7-0x0049c800` | nine `cc` bytes | padding |
| `0x0049c800-0x0049cac4` | `sub_49C800`, size `0x2c4` | `_DATFileMgr::LoadDATFileIndex` |
| `0x0049cad0-0x0049cba5` | `sub_49CAD0`, size `0xd5` | `_DATFileMgr::FindEntryByName` |
| `0x0049cbb0-0x0049cc39` | `sub_49CBB0`, size `0x89` | file-local `CreateDATEntryNode` |
| `0x0049cc40-0x0049ce49` | `sub_49CC40`, size `0x209` | non-owner [UID:00012G] `SimpleUStringVector::GrowAndInsert` |
| `0x0049ce50-0x0049d0c2` | `sub_49CE50`, size `0x272` | `DATFileResolver::InsertOrFindEntry`; includes EH cleanup edges |
| `0x0049d0d0-0x0049d175` | `sub_49D0D0`, size `0xa5` | resolver remove/free-node EH/helper path, manager-owned support, not standalone public API |
| `0x0049d180-0x0049d18b` | `sub_49D180`, size `0x0b` | singleton clear helper; compiler/static-cleanup style, not a public DAT API |
| `0x0049d190-0x0049d26c` | `sub_49D190`, size `0xdc` | existing [UID:00012H] `DATFileResolver::~DATFileResolver`/destroy |
| `0x0049d270-0x0049d275` | `sub_49D270`, size `0x05` | non-owner wide-string handle destructor thunk |
| `0x0049d280-0x0049d2cc` | `sub_49D280`, size `0x4c` | non-owner DATFile scalar deleting destructor |
| `0x0049d2d0-0x0049d349` | `sub_49D2D0`, size `0x79` | `DATFileContainer` scalar deleting destructor, compiler generated from class dtor |
| `0x0049d350-0x0049d38b` | `sub_49D350`, size `0x3b` | `DATFileMgr` scalar deleting destructor, compiler generated from class dtor |
| `0x0049d390-0x0049d3ce` | `sub_49D390`, size `0x3e` | non-owner [UID:00012I] `File` base scalar deleting destructor |
| `0x0049d3d0-0x0049d488` | `sub_49D3D0`, size `0xb8` | `_DATFileMgr` scalar deleting destructor, compiler generated wrapper around ordinary cleanup |
| `0x0049d490-0x0049d4bd` | `sub_49D490`, size `0x2d` | `AllocateDATEntryNode` / sentinel-node allocator |
| `0x0049d4c0-0x0049d4e4` | `sub_49D4C0`, size `0x24` | non-owner `DestroyWideStringHandleRange`, tied to [UID:00012G]/StringUtil |
| `0x0049d4f0-0x0049d521` | `sub_49D4F0`, size `0x31` | resolver EH cleanup node removal/free helper, not standalone public source |
| `0x0049d530-0x0049d5a0` | `sub_49D530`, size `0x70` | non-owner `CopyConstructWideStringHandleRange`, tied to [UID:00012G]/StringUtil |
| `0x0049d5a0-0x0049d5dc` | `sub_49D5A0`, size `0x3c` | `CreateDATEntryNode` EH cleanup/free helper |
| `0x0049d5e0-0x0049d6ed` | `sub_49D5E0`, size `0x10d` | `DATFileResolver::FindNodeByKey` |
| `0x0049d6ed-0x0049d6f0` | three `cc` bytes | target-end padding |
| `0x0049d6f0` | raw/no function | outside target; next raw constructor-like body, then modeled `sub_49D740` at `0x0049d740` |

Important correction: the current target's "not every byte in broad span" language is too weak. The page is an overlap index across multiple already-owned source modules plus raw/no-function destructors and EH helpers. It must not be treated as a single source emitter.

## Behavioral Evidence

`DATFileMgr::DATFileMgr` at `0x0049bd30`:
- One code xref from `Application__Constructor` at `0x00463655`.
- Stores `g_pDATFileMgr`/`unk_67AB40` at `0x0049bd67`, with a null-clear path at `0x0049bd6e` for the constructor-adjusted null case.
- Installs public vtable `0x00618914`.
- Allocates `0x30` bytes for `_DATFileMgr`, installs `_DATFileMgr` vtable `0x006189cc`, initializes the embedded `DATFileResolver`, calls `AllocateDATEntryNode(0, 0)` for the resolver sentinel, initializes resolver buckets with `sub_423B00(..., 8)`, then clears archive-container vector begin/end/capacity at `_DATFileMgr +0x24/+0x28/+0x2c`.

`DATFileMgr::~DATFileMgr` raw body at `0x0049be50-0x0049be6d`:
- No IDA function and no start xrefs.
- Writes public vtable `0x00618914`, deletes `m_impl` through its vtable if non-null, clears `g_pDATFileMgr`, and returns.
- It is source-declared destructor behavior; the scalar deleting wrapper at `0x0049d350` is compiler-generated and must not be hand-authored separately.

`DATFileMgr::LoadDATFile`/`LoadDATFileIndex` forwarder at `0x0049be70`:
- Fourteen xrefs: `Application__Constructor` at `0x004637be`, twelve calls in `sub_4639D0`, and one call in `sub_467410`.
- Decompilation: loads `this[1]` and tail-jumps/calls `_DATFileMgr::LoadDATFileIndex` at `0x0049c800`.
- This should be class-owned by [UID:00003I] `DATFileMgr`, not only file-owned by [UID:0000IO].

`DATFileContainer::DATFileContainer` at `0x0049be80`:
- Three xrefs: `_DATFileMgr::LoadDATFileIndex` at `0x0049c8bd` plus two other archive-loader construction sites at `0x004dbce3` and `0x004dbedf`.
- Initializes vtable `0x0061891c`, `m_fileHandle=-1`, `m_mappingHandle=0`, `m_mappedView=0`, `m_finalPayloadOffset=0`, `m_entryCount=0`, and `m_entries=0`.
- Opens the passed path using import slot `0x0069be34`; if direct open fails, retries with `"../" + path`.
- Creates a read-only mapping through import slot `0x0069be48`, maps through `MapViewOfFile`, reports failures via `MessageBoxW`, allocates/throws `Win32Error`, reads entry count from mapped dword 0, sets `m_entries = mappedBase + 4`, and reads the final boundary record's offset into `m_finalPayloadOffset`.

`DATFileContainer::~DATFileContainer` raw body at `0x0049c0d0-0x0049c130`:
- No IDA function and no start xrefs.
- Restores vtable `0x0061891c`, unmaps `m_mappedView`, closes `m_mappingHandle`, closes `m_fileHandle` if not `-1`, clears mapped view/entry count/entry pointer, then returns.
- Scalar deleting wrapper at `0x0049d2d0` is vtable-only and compiler generated.

`HasDATEntry` at `0x0049c700`:
- Seventeen code xrefs across resource/UI/archive consumers.
- Decompiles to a global-manager probe: `sub_49CAD0(*(_DWORD **)(unk_67AB40 + 4), String, 0) != 0`.
- It belongs to `DATFileMgr.cpp` as a free helper/API, not to `DATFile`, `DATArchive`, or a consumer module.

`_DATFileMgr::~_DATFileMgr` raw body at `0x0049c750-0x0049c7f7`:
- `lookup_funcs 0x0049c750` is `Not a function`; `xrefs_to 0x0049c750` reports zero start xrefs.
- Raw bytes show `_DATFileMgr` vtable store `0x006189cc`, deletion of each non-null `DATFileContainer*` in the archive vector, vector-storage free with MSVC aligned-allocation validation, zeroing of `_DATFileMgr +0x24/+0x28/+0x2c`, and call to `DATFileResolver` destroy at `0x0049d190`.
- The invalid-parameter call at `0x0049c7f2-0x0049c7f6` is part of the raw body; padding begins at `0x0049c7f7`.

`_DATFileMgr::LoadDATFileIndex` at `0x0049c800`:
- One xref from the public load forwarder at `0x0049be77`.
- Builds a `"../" + Source` fallback, checks path existence through `0x004b81f0`, constructs a `DATFileContainer`, appends it to the `_DATFileMgr` archive-container vector through vector insert helper `0x00437710`, iterates `0x11`-byte DAT entry records, normalizes entry names through StringBase/string helpers, rejects duplicates through `_DATFileMgr::FindEntryByName`, creates `DATEntryNode`s, links them into the resolver list, and calls `DATFileResolver::InsertOrFindEntry`.

`_DATFileMgr::FindEntryByName` at `0x0049cad0`:
- Four xrefs: raw public forwarder at `0x0049bd27`, `DATFile::Open` at `0x0049c1b8`, `HasDATEntry` at `0x0049c711`, and `_DATFileMgr::LoadDATFileIndex` duplicate check at `0x0049c9c0`.
- Normalizes the query string, calls `DATFileResolver::FindNodeByKey`, returns false on resolver sentinel, and if `outLocation` is non-null writes node `+0x0c` and node `+0x10`.

`CreateDATEntryNode` at `0x0049cbb0`:
- One xref from `_DATFileMgr::LoadDATFileIndex` at `0x0049ca0f`.
- Calls `AllocateDATEntryNode`, copy-constructs the string handle into node `+0x08`, stores `DATFileContainer*` at node `+0x0c`, and stores entry index at node `+0x10`.
- Calls to `0x0049d5a0` are EH cleanup/free support, not source-level helper calls.

`DATFileResolver::InsertOrFindEntry` at `0x0049ce50`:
- Two xrefs: `_DATFileMgr::LoadDATFileIndex` at `0x0049ca54` and recursive rehash call at `0x0049d061`.
- Hash is `hash = ch + 5 * hash` over the wide string, bucket index `hash & m_bucketMask`.
- If an equivalent key already exists, the newly-created node is unlinked/freed and the result is `(existingNode, inserted=false)`.
- If new, the node is moved/linked into the bucket/list state, `m_entryCount` is considered for load-factor growth, buckets grow by `*8` below `0x200` buckets and by `*2` above that, and entries are reinserted after `sub_423B00` bucket-vector growth.
- `0x0049d0d0` and `0x0049d4f0` are cleanup/remove helpers reached from this body/EH edges; they should be documented under resolver support, not split as public source APIs.

`DATFileResolver::~DATFileResolver` at `0x0049d190`:
- Existing [UID:00012H] already has source-ready C++ and should remain the exact emission target for resolver cleanup.
- It frees bucket storage with aligned-allocation validation, resets bucket triplet, detaches the circular list sentinel, destroys node strings, frees nodes, and frees the sentinel.

`DATFileResolver::FindNodeByKey` at `0x0049d5e0`:
- One xref from `_DATFileMgr::FindEntryByName` at `0x0049cb4c`.
- Uses the same `ch + 5 * hash` and `m_bucketMask`, walks bucket/list links, compares wide string handles/contents, returns the matching node or resolver sentinel.

## Vtable, Singleton, And Data Evidence

Live vtable/global evidence from `get_bytes`, `get_int`, and `xrefs_to`:

| Address | Live value/bytes | Meaning |
| --- | --- | --- |
| `0x00618910` | dword `0x0064645c` | `DATFileMgr` RTTI locator |
| `0x00618914` | dword `0x0049d350` | `DATFileMgr` scalar deleting destructor slot |
| `0x00618918` | dword `0x00646414` | `DATFileContainer` RTTI locator |
| `0x0061891c` | dword `0x0049d2d0` | `DATFileContainer` scalar deleting destructor slot |
| `0x006189c8` | dword `0x006463cc` | `_DATFileMgr` RTTI locator |
| `0x006189cc` | dword `0x0049d3d0` | `_DATFileMgr` scalar deleting destructor slot |
| `0x0067ab40` | live IDB dword `0x00000000` | raw singleton storage for source alias `g_pDATFileMgr` |

Important stale-evidence correction and exact support-doc wording: existing singleton docs must not continue to state `ff ff ff ff` as current live bytes. Use this wording in the `g_pDATFileMgr` support docs: "Live IDA MCP session `80de0a67` reads bytes `00 00 00 00`, `u32le=0`, and `get_global_value=0x0` at `0x0067ab40`; document source storage as `DATFileMgr *g_pDATFileMgr = 0` for the current IDB, with the 24 xrefs preserving the alias and write/read route. Older `ff ff ff ff` wording is stale or historical unless a separate original-file byte audit proves it for a different evidence source." The support-doc edit should be applied to [UID:0000QQ] `by-global/g_pDATFileMgr.md`, [UID:0001P6] `by-memory/0x0067ab40-0x0067ab44.g_pDATFileMgr.md`, and the singleton note in [UID:0000IO] `by-file/DATFileMgr.md` if that page repeats the stale byte claim.

Vtable xrefs:
- `xrefs_to 0x00618914`: `0x49bd81`, raw `0x49be50`, `0x49d359`.
- `xrefs_to 0x0061891c`: `0x49bec5`, raw `0x49c0d6`, `0x49d2d9`.
- `xrefs_to 0x006189cc`: `0x49bda1`, raw `0x49c755`, `0x49d3dd`.

`xrefs_to 0x0067ab40` reports 24 references, including constructor publish/null-clear at `0x49bd67/0x49bd6e`, raw destructor clear at `0x49be63`, `HasDATEntry` read at `0x49c703`, clear helper at `0x49d180`, scalar-deleting public destructor clear at `0x49d36d`, application/startup/cleanup references, and DAT archive lookup readers.

## Field And Helper Aliases

These names are source-facing aliases recommended for support docs. They should replace raw `mbr_0x*` style blockers where the page already has enough evidence.

`DATFileMgr`:

| Offset | Alias | Evidence |
| --- | --- | --- |
| `+0x00` | vptr | vtable store `0x00618914` in ctor/dtors |
| `+0x04` | `m_impl` | public wrappers load `[this+4]`; ctor stores heap `_DATFileMgr*` |

`_DATFileMgr`:

| Offset | Alias | Evidence |
| --- | --- | --- |
| `+0x00` | vptr | vtable store `0x006189cc` |
| `+0x04` through `+0x23` | `m_resolver` | embedded `DATFileResolver`; ctor passes `_DATFileMgr + 4` to resolver bucket init; dtors call resolver destroy on `this+4` |
| `+0x24` | `m_archiveContainersBegin` | ctor/dtor/vector logic reads first container pointer |
| `+0x28` | `m_archiveContainersEnd` | append and destructor iteration endpoint |
| `+0x2c` | `m_archiveContainersCapacity` | vector free/growth endpoint |

`DATFileResolver` relative to `_DATFileMgr +0x04`:

| Resolver offset | `_DATFileMgr` offset | Alias |
| --- | --- | --- |
| `+0x00` | `+0x04` | `m_maxLoadFactor` (`1.0f` written as `0x3f800000`) |
| `+0x04` | `+0x08` | `m_entryListSentinel` |
| `+0x08` | `+0x0c` | `m_entryCount` |
| `+0x0c` | `+0x10` | `m_bucketsBegin` |
| `+0x10` | `+0x14` | `m_bucketsEnd` |
| `+0x14` | `+0x18` | `m_bucketsCapacity` |
| `+0x18` | `+0x1c` | `m_bucketMask` |
| `+0x1c` | `+0x20` | `m_bucketCount` |

`DATFileContainer`:

| Offset | Alias | Evidence |
| --- | --- | --- |
| `+0x00` | vptr | vtable store `0x0061891c` |
| `+0x04` | `m_fileHandle` | initialized `-1`, closed if not `-1` |
| `+0x08` | `m_mappingHandle` | result of mapping creation import `0x0069be48`, closed when non-null |
| `+0x0c` | `m_mappedView` | result of `MapViewOfFile`, unmapped when non-null |
| `+0x10` | `m_finalPayloadOffset` | final boundary row offset from mapped DAT index |
| `+0x14` | `m_entryCount` | mapped dword 0 |
| `+0x18` | `m_entries` | first `0x11`-byte entry record at `mappedBase + 4` |

`DATEntryNode` is a 20-byte resolver/list node:

| Offset | Alias | Evidence |
| --- | --- | --- |
| `+0x00` | `m_next` | traversal uses offset 0; allocator initializes link 0 |
| `+0x04` | `m_prev` | list rewiring uses offset 4 |
| `+0x08` | `m_entryName` | StringBase/wide string handle copied/destroyed here |
| `+0x0c` | `m_container` | `_DATFileMgr::FindEntryByName` writes this to `outLocation[0]` |
| `+0x10` | `m_entryIndex` | `_DATFileMgr::FindEntryByName` writes this to `outLocation[1]` |

`DATEntryLocation` should remain the two-dword output record used by public/internal find calls: `container` plus `entryIndex`. The older open question about final DAT entry sentinel naming should be corrected: [UID:0000UC] and [UID:0001QC] support a final boundary row/offset model; do not document it as a guaranteed empty name sentinel.

Second-rework source-facing C++ aliases, inferred from current support docs and live MCP:

| Source-facing name | Kind | Evidence and intended use |
| --- | --- | --- |
| `DATEntryRecord` | packed archive table row | Existing [UID:0000UC] documents the `uint32 startOffset` plus `char name[13]` record consumed by `DATFileContainer`, `_DATFileMgr::LoadDATFileIndex`, `DATFile::Open`, and `DATFile::OpenByIndex`. Use it in first-draft manager/container C++ instead of raw 17-byte pointer arithmetic. |
| `SimpleUString` | UTF-16 string wrapper | Existing string docs and decompiler calls around `0x00582560-0x00584540` support a project string object for normalized names. Use `SimpleUString` for temporary DAT entry names and node keys. |
| `DATEntryNode` | 20-byte resolver/list node | Fields are fixed above: `m_next`, `m_prev`, `m_entryName`, `m_container`, `m_entryIndex`. |
| `DATEntryLocation` | two-field output | Existing `_DATFileMgr` support docs already declare `FindEntryByName(const wchar_t *, DATEntryLocation *)`; use `m_container` and `m_entryIndex`. |
| `DATFileResolverResult` | inferred small return struct | Source-shaped replacement for the hidden struct-return pair from `DATFileResolver::InsertOrFindEntry`: `DATEntryNode *m_node; bool m_inserted;`. |
| `DATFileContainerVectorAppend` | inferred file-local vector helper | Source-facing helper for the archive-container pointer-vector growth path through `0x00437710`; keeps `_DATFileMgr::LoadDATFileIndex` readable without leaking vector-growth helper labels. |
| `DATFileContainerVectorFree` | inferred file-local vector helper | Source-facing helper for the MSVC vector-storage free path in raw `_DATFileMgr::~_DATFileMgr`; wraps the large-allocation guard/free sequence without exposing CRT guard details as game source. |
| `DATFileExists` | inferred file-local path helper | Source-facing replacement for `sub_4B81F0` checks used by `_DATFileMgr::LoadDATFileIndex` before constructing a container. |
| `ShowDATFileError` / `ShowDATFileMapError` | inferred file-local UI/error helpers | Source-facing wrappers for the `sub_41B9B0` wide-format plus `MessageBoxW` paths in `DATFileContainer::DATFileContainer` before throwing `Win32Error`. |
| `NormalizeDATEntryName` | inferred file-local string helper | Covers the observed ANSI-to-wide conversion, uppercase/normalization, and string assignment sequence in `0x0049c800` and `0x0049cad0`. It is not a new public API. |
| `DATEntryNameEquals` | inferred file-local comparison helper | Source-facing wrapper for the same wide string comparison used by `FindNodeByKey` and duplicate insertion checks. |
| `HashDATEntryName` | inferred file-local hash helper | Source-facing wrapper for the repeated `hash = ch + 5 * hash` loop in resolver insert/find. |
| `DATFileResolver::ReserveBucketCount` | inferred private resolver helper | Source-facing name for bucket-vector growth/rebuild behavior through `sub_423B00`; it belongs to resolver support docs, not a standalone source file. |
| `DATFileResolver::GetFirstBucketNode` / `GetBucketEndNode` | inferred private resolver helpers | Source-facing wrappers for the bucket begin/end sentinel selection used by `InsertOrFindEntry` and `FindNodeByKey`. |
| `DATFileResolver::LinkEntryIntoBucket` / `AppendEntryNode` / `RebuildBuckets` | inferred private resolver helpers | Source-facing helpers for the list rewiring, global entry-list append, and recursive bucket rebuild behavior observed in `0x0049ce50` and the load path. |
| `UnlinkEntryNode` | inferred file-local helper | Source-facing wrapper for duplicate-rejection unlink behavior before `FreeDATEntryNode`. |
| `FreeDATEntryNode` | inferred file-local cleanup helper | Source-facing name for releasing a node key and freeing its 20-byte node storage when duplicate insertion rejects a newly allocated node. |

These inferred names are now the recommended implementation names. The report no longer treats absence of original symbol proof as a reason to keep eligible child C++ blank.

## Ownership Ranking

1. [UID:0000IO] `DATFileMgr` file is the best source owner for `DATFileMgr`, `_DATFileMgr`, `DATFileContainer`, `DATFileResolver`, `HasDATEntry`, node allocation/creation, and resolver support helpers. This is supported by singleton/vtable routes, public wrapper fan-in, construction/destruction lifecycle, archive-container vector ownership, and existing support docs.
2. [UID:00003I] `DATFileMgr` class should directly own public wrapper methods including [UID:00012C] and [UID:000227]. The file remains the source-family/emitter route.
3. [UID:000004] `_DATFileMgr`, [UID:00003H] `DATFileContainer`, and [UID:00003J] `DATFileResolver` should own their exact class methods/fields, emitted through [UID:0000IO].
4. [UID:0000IN] `DATFile` owns the `0x0049c130-0x0049c6f2`, `0x0049c720-0x0049c74b`, and `0x0049d280-0x0049d2cc` overlaps. These must not be absorbed into [UID:00012B].
5. [UID:0000DA]/[UID:0000OB] `SimpleUStringVector`/StringUtil owns `0x0049cc40`, `0x0049d4c0`, and `0x0049d530`.
6. [UID:0000JB]/[UID:00004V] `File` owns `0x0049d390-0x0049d3ce`.

Rejected owners/splits:
- Do not move this cluster to `DATArchive`; that page is an umbrella contract, not the manager implementation.
- Do not fold `DATFile` or `DATIndexVector` into `DATFileMgr`; they have separate owner evidence and caller fanout.
- Do not create standalone `DATFileResolver.cpp`, `_DATFileMgr.cpp`, or `DATFileContainer.cpp`; current source route remains `NexusTK/archive/DATFileMgr.cpp` with internal/helper classes.
- Do not hand-author vtable data, scalar deleting destructors, or compiler/EH cleanup helpers as ordinary source.
- Do not merge [UID:000227] into [UID:00012B]; it is a distinct raw public find forwarder outside the target boundary.

## Formal C++ Disposition

[UID:00012B] should keep an empty formal `RECONSTRUCTION_CPP CODE` block and should be reclassified as non-reconstructable/non-emitting. This is the correction to the rejected `RECONSTRUCTABLE:TRUE`/`EMITTER_UIDS:0000IO` recommendation. Live IDA proves the parent range is a mixed overlap/index across manager-owned source bodies, non-owner DATFile/SimpleUStringVector/File bodies, compiler-generated scalar deleting destructors, EH cleanup helpers, and padding. No single source declaration, method body, file-scope helper, or C++ translation-unit construct corresponds to `0x0049bd30-0x0049d6ed` as one emitter.

Exact no-code proof for [UID:00012B]:
- The target contains non-owner DATFile methods and destructors, SimpleUStringVector helpers, and the File base destructor.
- It contains raw/no-function class destructors at `0x0049be50`, `0x0049c0d0`, and `0x0049c750` that are source-declared/destructor-body evidence but not modeled as IDA functions.
- It contains compiler-generated scalar deleting destructors, vtable stores, string-handle thunks, and EH cleanup helpers that must be regenerated from declarations/body source, not hand-written in a broad aggregate block.
- The exact method bodies have separable owners and should emit from exact child pages/class pages, not from this overlap index.
- The current source route is still `NexusTK/archive/DATFileMgr.cpp` for manager-owned children, but route evidence is not parent-emitter evidence. Parent `CANONICAL_OWNER` must be `NONE`, blank `EMITTER_UIDS`; child pages carry [UID:0000IO], [UID:00003I], [UID:000004], [UID:00003H], or [UID:00003J] as appropriate.

No draft/example/marker C++ insertion is recommended for [UID:00012B]. Leave no comment marker inside the block.

## Implementation-Ready Split/Child Plan

This report no longer recommends a high-score parent while child repair remains vague. The implementation callback should first reclassify the parent as the non-emitting index below, then apply the support-doc wording and only create/repair the child pages explicitly approved by the supervisor. New child UIDs are assigned by the project tooling/validator; the exact file names, ranges, metadata, summaries, and C++/no-code dispositions are fixed here so the supervisor does not need to invent the plan.

Parent reclassification:

| Path | Range | Required metadata | Required Item Summary | C++ disposition |
| --- | --- | --- | --- | --- |
| `by-memory/0x0049bd30-0x0049d6ed.DATManagers.md` | `0x0049bd30-0x0049d6ed` | `COMPLETION:88`, `CONFIDENCE:92`, `CANONICAL_OWNER:NONE`, `RECONSTRUCTABLE:FALSE`, blank `EMITTER_UIDS`, blank `EMITTER_POSITION_OPTIONAL` | `Non-emitting DAT manager island overlap/index for exact manager/container/resolver child methods, raw ordinary destructors, compiler/EH helpers, padding, and known non-owner DATFile/SimpleUStringVector/File overlaps; source route for manager-owned children remains NexusTK/archive/DATFileMgr.cpp, but this parent has no direct emitter.` | Keep `RECONSTRUCTION_CPP CODE` empty with no marker/comment text. |

Existing pages that remain distinct:

| Existing page | Range | Action |
| --- | --- | --- |
| [UID:000227] `by-memory/0x0049bd20-0x0049bd2c.DATFileMgrFindEntryForwarder.md` | `0x0049bd20-0x0049bd2c`, outside [UID:00012B] | Do not merge into [UID:00012B]. Optional cross-reference only: public `DATFileMgr::FindEntryByName` forwarder is adjacent but outside the parent boundary. |
| [UID:00012D] DATFile pages | `0x0049c130-0x0049c6f2` and `0x0049c720-0x0049c74b` portions inside the parent span | Keep DATFile-owned; do not re-own to DATFileMgr. |
| [UID:00012G] SimpleUStringVector page | `0x0049cc40-0x0049ce49` | Keep vector/generic string owner; do not re-own to DATFileMgr. |
| [UID:00012H] `by-memory/0x0049d190-0x0049d26c.DATFileResolverDestroy.md` | `0x0049d190-0x0049d26c` | Keep as exact resolver destructor page; parent only links it as one child/overlap. |
| [UID:00012I] File base scalar deleting destructor page | `0x0049d390-0x0049d3ce` | Keep File-owned/compiler-generated; parent only records the overlap. |

Child creation/repair targets:

| Action | Exact path/name | Range | Owner and emitter metadata | Item Summary detail | C++/no-code disposition |
| --- | --- | --- | --- | --- | --- |
| Create child | `by-memory/0x0049bd30-0x0049be41.DATFileMgrConstructor.md` | `0x0049bd30-0x0049be41` | `COMPLETION:86`, `CONFIDENCE:90`, `CANONICAL_OWNER:00003I`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:00003I` | Public `DATFileMgr::DATFileMgr` constructor; one code xref from `Application__Constructor` at `0x00463655`; publishes `g_pDATFileMgr` at `0x0049bd67`, null-clears at `0x0049bd6e`, installs vtable `0x00618914`, allocates `0x30`-byte `_DATFileMgr`, installs `_DATFileMgr` vtable `0x006189cc`, initializes resolver sentinel/buckets, and clears archive-container vector fields. | Formal child C++ C++-1 below. |
| Create child | `by-memory/0x0049be50-0x0049be6d.DATFileMgrDestructor.md` | `0x0049be50-0x0049be6d` | `COMPLETION:88`, `CONFIDENCE:92`, `CANONICAL_OWNER:00003I`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:00003I` | Raw ordinary `DATFileMgr::~DATFileMgr` body; `lookup_funcs` says `Not a function`; no start xrefs; writes public vtable `0x00618914`, deletes `m_impl` through its vtable if non-null, clears `g_pDATFileMgr` at `0x0049be63`, then returns. | Formal child C++ C++-2 below. |
| Repair existing [UID:00012C] | `by-memory/0x0049be70-0x0049be7c.ForwardLoadDATFileIndex.md` | `0x0049be70-0x0049be7c` | `COMPLETION:90`, `CONFIDENCE:93`, `CANONICAL_OWNER:00003I`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:00003I` | Public `DATFileMgr::LoadDATFile`/load-index forwarder; 14 call xrefs; loads `this->m_impl` and tail-calls `_DATFileMgr::LoadDATFileIndex` at `0x0049c800`; source route through `DATFileMgr.cpp` but direct class owner is `DATFileMgr`. | Formal child C++ C++-3 below. |
| Create child | `by-memory/0x0049be80-0x0049c0c9.DATFileContainerConstructor.md` | `0x0049be80-0x0049c0c9` | `COMPLETION:88`, `CONFIDENCE:90`, `CANONICAL_OWNER:00003H`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:00003H` | `DATFileContainer::DATFileContainer` mapped-archive constructor; opens requested path, retries with `"../"`, creates file mapping, maps view, reports/throws Win32Error on open/map failure, reads entry count/base/final payload, and stores handles/view/entry table in `+0x04..+0x18`. | Formal child C++ C++-6 below. |
| Create child | `by-memory/0x0049c0d0-0x0049c130.DATFileContainerDestructor.md` | `0x0049c0d0-0x0049c130` | `COMPLETION:88`, `CONFIDENCE:91`, `CANONICAL_OWNER:00003H`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:00003H` | Raw ordinary `DATFileContainer::~DATFileContainer`; `lookup_funcs` says `Not a function`; no direct start xrefs; restores vtable `0x0061891c`, unmaps `m_mappedView`, closes `m_mappingHandle`, closes `m_fileHandle`, and clears fields. | Formal child C++ C++-4 below. |
| Repair existing [UID:00012E] | `by-memory/0x0049c700-0x0049c71d.HasDATEntry.md` | `0x0049c700-0x0049c71d` | `COMPLETION:90`, `CONFIDENCE:92`, `CANONICAL_OWNER:0000IO`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000IO` | File-scope `HasDATEntry` helper in `DATFileMgr.cpp`; 17 xrefs; reads `g_pDATFileMgr`, calls the internal/public find path, and returns boolean existence without moving ownership to DATFile. | Formal child C++ C++-5 below. |
| Repair existing [UID:00012F] | `by-memory/0x0049c750-0x0049c7f6._DATFileMgrRawDestructor.md` | live body `0x0049c750-0x0049c7f7`, filename may preserve last-live-byte policy `0x0049c7f6` | `COMPLETION:88`, `CONFIDENCE:92`, `CANONICAL_OWNER:000004`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:000004` | Raw ordinary `_DATFileMgr::~_DATFileMgr`; `lookup_funcs` says `Not a function`; no start xrefs; `insn_query` confirms vtable restore at `0x49c755`, archive-container delete loop over `+0x24/+0x28`, vector storage free/zero at `0x49c797-0x49c7de`, and resolver cleanup call on `this+4` at `0x49c7e8`. | Formal child C++ C++-7 below. |
| Create child | `by-memory/0x0049c800-0x0049cac4._DATFileMgrLoadDATFileIndex.md` | `0x0049c800-0x0049cac4` | `COMPLETION:88`, `CONFIDENCE:90`, `CANONICAL_OWNER:000004`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:000004` | `_DATFileMgr::LoadDATFileIndex`; one xref from the public load wrapper; checks direct and `"../"` paths, constructs `DATFileContainer`, appends it to archive vector, iterates 0x11-byte DAT entry records, normalizes entry names, rejects duplicates, creates entry nodes, and inserts them into resolver. | Formal child C++ C++-8 below. |
| Create child | `by-memory/0x0049cad0-0x0049cba5._DATFileMgrFindEntryByName.md` | `0x0049cad0-0x0049cba5` | `COMPLETION:88`, `CONFIDENCE:91`, `CANONICAL_OWNER:000004`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:000004` | `_DATFileMgr::FindEntryByName`; four xrefs; normalizes query, calls resolver find, rejects sentinel, and writes node `+0x0c/+0x10` container/index outputs. | Formal child C++ C++-9 below. |
| Create child | `by-memory/0x0049cbb0-0x0049cc39.CreateDATEntryNode.md` | `0x0049cbb0-0x0049cc39` | `COMPLETION:89`, `CONFIDENCE:92`, `CANONICAL_OWNER:0000IO`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000IO` | File-local/static `CreateDATEntryNode` helper; allocates a node, copies the normalized string into `+0x08`, stores container at `+0x0c`, stores entry index at `+0x10`, and leaves next/prev linkage for resolver insertion. | Formal child C++ C++-10 below. |
| Keep non-owner | `by-memory/0x0049cc40-0x0049ce49.*SimpleUStringVector*.md` | `0x0049cc40-0x0049ce49` | keep current [UID:00012G] owner/emitter | Generic string-vector growth/insert helper; not DATFileMgr source. | No C++ on parent; do not re-own. |
| Create child | `by-memory/0x0049ce50-0x0049d0c2.DATFileResolverInsertOrFindEntry.md` | `0x0049ce50-0x0049d0c2` | `COMPLETION:88`, `CONFIDENCE:91`, `CANONICAL_OWNER:00003J`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:00003J` | `DATFileResolver::InsertOrFindEntry`; hashes with `hash = ch + 5*hash`, uses `hash & mask`, removes/frees duplicate new node with inserted false, links new nodes, and grows/reinserts buckets by `*8` below `0x200` else `*2`. | Formal child C++ C++-11 below. |
| No standalone page | `0x0049d0d0-0x0049d175` resolver remove/free cleanup helper | `0x0049d0d0-0x0049d175` | Do not create a child page in this implementation; record only in parent/support docs | EH/remove/free helper for resolver failure path; not a public source API. | No source C++; regenerated from resolver method/destructor source and compiler EH. |
| No standalone page | `0x0049d180-0x0049d18b` singleton clear helper | `0x0049d180-0x0049d18b` | Do not create a child page in this implementation; record only in parent/support docs | Small helper clears `g_pDATFileMgr`; support docs should mention it as singleton lifecycle evidence. | No source C++; helper is not a separate source-owned function. |
| No standalone page | `0x0049d270-0x0049d275`, `0x0049d2d0-0x0049d349`, `0x0049d350-0x0049d38b`, `0x0049d3d0-0x0049d488` | exact ranges as listed | Do not create child pages in this implementation; class support pages own the source declarations | Wide-string handle thunk and scalar deleting destructor wrappers for DATFileContainer, DATFileMgr, and `_DATFileMgr`. | No source C++; compiler output from destructors/class declarations. |
| Create child | `by-memory/0x0049d490-0x0049d4bd.AllocateDATEntryNode.md` | `0x0049d490-0x0049d4bd` | `COMPLETION:90`, `CONFIDENCE:93`, `CANONICAL_OWNER:0000IO`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000IO` | File-local allocator for resolver entry nodes; allocates/initializes `DATEntryNode` storage used by sentinel and per-entry nodes. | Formal child C++ C++-12 below. |
| No standalone page | `0x0049d4f0-0x0049d521` and `0x0049d5a0-0x0049d5dc` | exact ranges as listed | Do not create child pages in this implementation; record only in parent/support docs | EH cleanup/free helpers for resolver insertion and `CreateDATEntryNode` failure paths. | No source C++; compiler/EH cleanup regenerated from owning source bodies. |
| Create child | `by-memory/0x0049d5e0-0x0049d6ed.DATFileResolverFindNodeByKey.md` | `0x0049d5e0-0x0049d6ed` | `COMPLETION:89`, `CONFIDENCE:92`, `CANONICAL_OWNER:00003J`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:00003J` | `DATFileResolver::FindNodeByKey`; hashes with the same `ch + 5*hash` scheme, masks bucket index, walks bucket list, compares normalized keys, and returns matching node or sentinel. | Formal child C++ C++-13 below. |

Formal child C++ insertion text for child pages marked above. Each block below is exact `RECONSTRUCTION_CPP CODE` header/block insertion text for the named destination page, not a body-only sample.

C++-1, destination `by-memory/0x0049bd30-0x0049be41.DATFileMgrConstructor.md`:

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
DATFileMgr::DATFileMgr()
    : m_impl(0)
{
    g_pDATFileMgr = this;
    m_impl = new _DATFileMgr;
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

C++-2, destination `by-memory/0x0049be50-0x0049be6d.DATFileMgrDestructor.md`:

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
DATFileMgr::~DATFileMgr()
{
    delete m_impl;
    g_pDATFileMgr = 0;
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

C++-3, destination `by-memory/0x0049be70-0x0049be7c.ForwardLoadDATFileIndex.md`:

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
bool DATFileMgr::LoadDATFile(const wchar_t *path)
{
    return m_impl->LoadDATFileIndex(path);
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

C++-4, destination `by-memory/0x0049c0d0-0x0049c130.DATFileContainerDestructor.md`:

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
DATFileContainer::~DATFileContainer()
{
    if (m_mappedView != NULL) {
        UnmapViewOfFile(m_mappedView);
    }
    if (m_mappingHandle != NULL) {
        CloseHandle(m_mappingHandle);
    }
    if (m_fileHandle != INVALID_HANDLE_VALUE) {
        CloseHandle(m_fileHandle);
    }
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

C++-5, destination `by-memory/0x0049c700-0x0049c71d.HasDATEntry.md`:

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
bool HasDATEntry(const wchar_t *entryName)
{
    return g_pDATFileMgr != 0 && g_pDATFileMgr->FindEntryByName(entryName, 0);
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

C++-6, destination `by-memory/0x0049be80-0x0049c0c9.DATFileContainerConstructor.md`:

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
DATFileContainer::DATFileContainer(const wchar_t *path)
    : m_fileHandle(INVALID_HANDLE_VALUE),
      m_mappingHandle(NULL),
      m_mappedView(NULL),
      m_finalPayloadOffset(0),
      m_entryCount(0),
      m_entries(0)
{
    wchar_t retryPath[80];

    m_fileHandle = CreateFileW(path, GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
    if (m_fileHandle == INVALID_HANDLE_VALUE) {
        wcscpy(retryPath, L"..\\");
        wcscat_s(retryPath, 80, path);
        m_fileHandle = CreateFileW(retryPath, GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
    }

    if (m_fileHandle == INVALID_HANDLE_VALUE) {
        return;
    }

    m_mappingHandle = CreateFileMappingW(m_fileHandle, NULL, PAGE_READONLY, 0, 0, NULL);
    if (m_mappingHandle == NULL) {
        ShowDATFileError(path);
        throw Win32Error();
    }

    m_mappedView = MapViewOfFile(m_mappingHandle, FILE_MAP_READ, 0, 0, 0);
    if (m_mappedView == NULL) {
        ShowDATFileMapError(path, GetLastError());
        throw Win32Error();
    }

    m_entryCount = *(unsigned int *)m_mappedView;
    m_entries = (DATEntryRecord *)((char *)m_mappedView + 4);
    m_finalPayloadOffset = m_entries[m_entryCount - 1].startOffset;
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

C++-7, destination `by-memory/0x0049c750-0x0049c7f6._DATFileMgrRawDestructor.md`:

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
_DATFileMgr::~_DATFileMgr()
{
    DATFileContainer **it;

    for (it = m_archiveContainersBegin; it != m_archiveContainersEnd; ++it) {
        delete *it;
    }

    if (m_archiveContainersBegin != 0) {
        DATFileContainerVectorFree(m_archiveContainersBegin, m_archiveContainersCapacity);
        m_archiveContainersBegin = 0;
        m_archiveContainersEnd = 0;
        m_archiveContainersCapacity = 0;
    }
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

C++-8, destination `by-memory/0x0049c800-0x0049cac4._DATFileMgrLoadDATFileIndex.md`:

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
bool _DATFileMgr::LoadDATFileIndex(const wchar_t *archivePath)
{
    wchar_t retryPath[80];
    DATFileContainer *container;
    unsigned int entryIndex;

    wcscpy(retryPath, L"../");
    wcscat_s(retryPath, 80, archivePath);

    if (!DATFileExists(archivePath) && !DATFileExists(retryPath)) {
        return false;
    }

    container = new DATFileContainer(archivePath);
    DATFileContainerVectorAppend(&m_archiveContainersBegin, &m_archiveContainersEnd, &m_archiveContainersCapacity, container);

    for (entryIndex = 0; entryIndex < container->m_entryCount; ++entryIndex) {
        const DATEntryRecord *record = &container->m_entries[entryIndex];
        SimpleUString entryName(record->name);

        if (!entryName.empty()) {
            NormalizeDATEntryName(entryName);
            if (!FindEntryByName(entryName.c_str(), 0)) {
                DATEntryNode *node = CreateDATEntryNode(m_resolver.m_entryListSentinel->m_next,
                                                        m_resolver.m_entryListSentinel->m_next->m_prev,
                                                        entryName,
                                                        container,
                                                        entryIndex);
                m_resolver.AppendEntryNode(node);
                m_resolver.InsertOrFindEntry(node);
            }
        }
    }

    return true;
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

C++-9, destination `by-memory/0x0049cad0-0x0049cba5._DATFileMgrFindEntryByName.md`:

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
bool _DATFileMgr::FindEntryByName(const wchar_t *entryName, DATEntryLocation *outLocation)
{
    SimpleUString normalizedName(entryName);
    DATEntryNode *node;

    NormalizeDATEntryName(normalizedName);
    node = m_resolver.FindNodeByKey(normalizedName);
    if (node == m_resolver.m_entryListSentinel) {
        return false;
    }

    if (outLocation != 0) {
        outLocation->m_container = node->m_container;
        outLocation->m_entryIndex = node->m_entryIndex;
    }

    return true;
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

C++-10, destination `by-memory/0x0049cbb0-0x0049cc39.CreateDATEntryNode.md`:

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
static DATEntryNode *CreateDATEntryNode(DATEntryNode *next,
                                        DATEntryNode *prev,
                                        const SimpleUString& entryName,
                                        DATFileContainer *container,
                                        unsigned int entryIndex)
{
    DATEntryNode *node = AllocateDATEntryNode(next, prev);

    node->m_entryName = entryName;
    node->m_container = container;
    node->m_entryIndex = entryIndex;
    return node;
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

C++-11, destination `by-memory/0x0049ce50-0x0049d0c2.DATFileResolverInsertOrFindEntry.md`:

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
DATFileResolverResult DATFileResolver::InsertOrFindEntry(DATEntryNode *node)
{
    DATFileResolverResult result;
    unsigned int bucketIndex;
    DATEntryNode *current;
    DATEntryNode *bucketEnd;

    bucketIndex = HashDATEntryName(node->m_entryName) & m_bucketMask;
    current = GetFirstBucketNode(bucketIndex);
    bucketEnd = GetBucketEndNode(bucketIndex);

    while (current != bucketEnd) {
        current = current->m_next;
        if (DATEntryNameEquals(current->m_entryName, node->m_entryName)) {
            UnlinkEntryNode(node);
            --m_entryCount;
            FreeDATEntryNode(node);
            result.m_node = current;
            result.m_inserted = false;
            return result;
        }
    }

    LinkEntryIntoBucket(bucketIndex, node, current);
    if ((float)m_entryCount / (float)m_bucketCount > m_maxLoadFactor) {
        unsigned int newBucketCount = m_bucketCount < 0x200 ? m_bucketCount * 8 : m_bucketCount * 2;
        ReserveBucketCount(newBucketCount);
        RebuildBuckets();
    }

    result.m_node = node;
    result.m_inserted = true;
    return result;
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

C++-12, destination `by-memory/0x0049d490-0x0049d4bd.AllocateDATEntryNode.md`:

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
static DATEntryNode *AllocateDATEntryNode(DATEntryNode *next, DATEntryNode *prev)
{
    DATEntryNode *node = new DATEntryNode;

    if (next != 0) {
        node->m_next = next;
        node->m_prev = prev;
    } else {
        node->m_next = node;
        node->m_prev = node;
    }

    return node;
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

C++-13, destination `by-memory/0x0049d5e0-0x0049d6ed.DATFileResolverFindNodeByKey.md`:

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
DATEntryNode *DATFileResolver::FindNodeByKey(const SimpleUString& entryName) const
{
    unsigned int bucketIndex;
    DATEntryNode *current;
    DATEntryNode *bucketEnd;

    bucketIndex = HashDATEntryName(entryName) & m_bucketMask;
    current = GetFirstBucketNode(bucketIndex);
    bucketEnd = GetBucketEndNode(bucketIndex);

    while (current != bucketEnd) {
        if (DATEntryNameEquals(current->m_entryName, entryName)) {
            return current;
        }
        current = current->m_next;
    }

    return m_entryListSentinel;
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

## Recommended Documentation Changes

Target [UID:00012B] `by-memory/0x0049bd30-0x0049d6ed.DATManagers.md`:
- Change the Item Summary to state that the page is a non-emitting overlap/index for the DAT manager island, with exact child emission sites and known non-owner overlaps.
- Set metadata to `COMPLETION:88`, `CONFIDENCE:92`, `CANONICAL_OWNER:NONE`, `RECONSTRUCTABLE:FALSE`, blank `EMITTER_UIDS`, blank `EMITTER_POSITION_OPTIONAL`, and keep formal C++ blank.
- Replace "field names/helper splits open" with the alias tables above.
- Replace "final C++ intentionally blank because aggregate" with the target-specific non-emitting-index no-code proof above.
- Add live MCP session `80de0a67` evidence: health, exact function map, raw destructor starts, exact target boundary, vtable bytes, singleton xrefs/current value, decompile evidence for `0x0049be80`, `0x0049c800`, `0x0049cad0`, `0x0049cbb0`, `0x0049ce50`, `0x0049d490`, `0x0049d5e0`, `insn_query` raw destructor evidence, and non-owner overlaps.
- Correct/expand child coverage to include omitted raw `DATFileMgr::~DATFileMgr` at `0x0049be50`, raw `DATFileContainer::~DATFileContainer` at `0x0049c0d0`, resolver EH/remove helper at `0x0049d0d0`, singleton clear helper at `0x0049d180`, small in-span cleanup helpers, and the formal child C++ routing C++-1 through C++-13.
- Preserve the existing source route `NexusTK/archive/DATFileMgr.cpp`; do not split into standalone resolver/container files.

Support [UID:0000IO] `by-file/DATFileMgr.md`:
- Add the exact manager-owned child map and mark non-owner overlaps explicitly.
- Add the field/type/helper aliases for `DATFileMgr`, `_DATFileMgr`, `DATFileContainer`, `DATFileResolver`, `DATEntryRecord`, `DATEntryNode`, `DATEntryLocation`, `DATFileResolverResult`, `DATFileContainerVectorAppend`, `DATFileContainerVectorFree`, `DATFileExists`, `ShowDATFileError`, `ShowDATFileMapError`, `NormalizeDATEntryName`, `HashDATEntryName`, `DATEntryNameEquals`, `UnlinkEntryNode`, `FreeDATEntryNode`, and the resolver private helpers named in C++-11/C++-13.
- Document `HasDATEntry` as a file-scope/free helper in `DATFileMgr.cpp`.
- Replace old source-quality blockers with "broad aggregate resolved as non-emitting overlap; exact child pages are the method emitters and now have first-draft C++ insertion text."
- Add the exact singleton wording from the live-byte correction: current IDB storage at `0x0067ab40` is `00 00 00 00`/`0`, source alias is `DATFileMgr *g_pDATFileMgr = 0`, and old `ff ff ff ff` wording is stale unless explicitly labeled historical.
- Keep file metadata unchanged unless validator policy requires a score sync from child coverage; this report does not recommend a by-file score change.

Support [UID:00003I] `by-class/DATFileMgr.md`:
- Add/confirm layout `vptr` and `m_impl`.
- Add/confirm public methods: constructor at `0x0049bd30`, ordinary destructor raw `0x0049be50`, public `FindEntryByName` forwarder [UID:000227], public `LoadDATFile` forwarder [UID:00012C], scalar deleting destructor `0x0049d350` as compiler generated.
- State that the constructor/destructor/load wrapper child pages carry first-draft formal C++ C++-1, C++-2, and C++-3. [UID:00012C] should use class direct owner [UID:00003I] with file route [UID:0000IO].
- Keep class metadata unchanged; this report does not recommend a by-class score change.

Support [UID:000004] `by-class/_DATFileMgr.md`:
- Keep `_DATFileMgr` spelling; do not replace with unsupported `DATFileMgrImpl`.
- Add ordinary destructor raw child [UID:00012F], load/find methods, node helper call flow, archive-container vector aliases, and the first-draft formal C++ routes C++-7, C++-8, and C++-9.
- Keep class declaration source-facing; method bodies emit on exact by-memory children.
- Keep class metadata unchanged; this report does not recommend a by-class score change.

Support [UID:00003H] `by-class/DATFileContainer.md`:
- Replace raw field labels with `m_fileHandle`, `m_mappingHandle`, `m_mappedView`, `m_finalPayloadOffset`, `m_entryCount`, and `m_entries`.
- Add ordinary raw destructor at `0x0049c0d0-0x0049c130` and scalar deleting destructor `0x0049d2d0-0x0049d349`.
- Document constructor path/open fallback and error behavior at report-level detail, with C++-6 and C++-4 as exact child formal C++ routes.
- Keep class metadata unchanged; this report does not recommend a by-class score change.

Support [UID:00003J] `by-class/DATFileResolver.md`:
- Keep current layout aliases and add `DATEntryNode`, `DATFileResolverResult`, bucket helper, hash helper, and comparison helper aliases used by C++-11/C++-13.
- Add `InsertOrFindEntry`, `FindNodeByKey`, `AllocateDATEntryNode`, `CreateDATEntryNode`, and cleanup-helper roles. `AllocateDATEntryNode` and `CreateDATEntryNode` are file-local helpers emitted through [UID:0000IO], not resolver members.
- State `0x0049d0d0`, `0x0049d4f0`, and `0x0049d5a0` are cleanup/support helpers, not standalone public APIs.
- Keep class metadata unchanged; this report does not recommend a by-class score change.

Support [UID:0000QQ]/[UID:0001P6] `g_pDATFileMgr` docs:
- Apply exact wording: "Live IDA MCP session `80de0a67` reads bytes `00 00 00 00`, `u32le=0`, and `get_global_value=0x0` at `0x0067ab40`; document source storage as `DATFileMgr *g_pDATFileMgr = 0` for the current IDB, with the 24 xrefs preserving the alias and write/read route. Older `ff ff ff ff` wording is stale or historical unless a separate original-file byte audit proves it for a different evidence source."
- Preserve source alias `g_pDATFileMgr` and 24-xref route.

Existing non-owner pages:
- Do not move [UID:00012D] DATFile, [UID:00012G] SimpleUStringVector, or [UID:00012I] File into DATFileMgr.
- This report does not require editing those owners to resolve [UID:00012B]; the parent and DATFileMgr support docs can carry the overlap note.

## Score Rationale

The rejected `90/92` parent score is no longer recommended. A reconstructable/emitting score increase is not justified for a parent that has no source emitter and still depends on separate child bodies for full source reconstruction.

Recommended target score after implementation: `COMPLETION:88`, `CONFIDENCE:92`.

- `COMPLETION:88` is justified because the parent will have exact boundaries, live MCP evidence, range/owner map, field aliases, no-code proof, child-page creation/repair specs, and singleton correction. It should not reach `90+` completion because the parent is now an index and method formal C++ belongs on exact child pages.
- `CONFIDENCE:92` is justified by live MCP health, function/raw-start boundaries, xrefs, vtable bytes, `g_pDATFileMgr` value/xrefs, and non-owner overlap proof. Confidence should not rise above `92` as part of this parent callback because child pages and validators carry their own route metadata.

Support pages can receive no score change unless the implementation callback applies the detailed support wording. Optional score ceilings are listed above and should not be exceeded as part of this parent rework. Do not raise generated/non-owner pages as part of this target.

Child score rationale:
- Child pages marked `RECONSTRUCTABLE:TRUE` now all have formal first-draft C++ insertion text. Their `85+` metadata is justified by current live MCP decompilation/raw disassembly plus source-facing names already supported in `DATFileMgr`, `_DATFileMgr`, `DATFileContainer`, `DATFileResolver`, `DATEntryRecord`, and string support docs.
- No child now uses missing original symbols, layout exactness, or helper-name uncertainty as a final no-code proof. The only blank-C++ dispositions are parent/index, non-owner overlaps, compiler-generated wrappers, and EH/cleanup glue that should be regenerated from owning source bodies.
- C++ uses plausible late-1999 through mid-2000s C++ style: it avoids the C++11 null pointer literal, lambdas, type-deduction declarations, and other C++11-only syntax.

## Implementation Tracking Checklist

Implementation callback completed by Agent-B002 on 2026-06-26. Accepted edits are applied or were already present at equal-or-greater detail. Lease proof: the edit/validator batch leased the 21 target/support/child by-* paths; final release/confirmation command `python leaser.py B002 unlease` from `tools/leaser` returned `B002: No active leases`, and `tools/leaser/Agents/current_leases.md` contains no B002 rows.

Checked items for the implementation callback:

- [x] Target [UID:00012B] metadata set to `COMPLETION:88`, `CONFIDENCE:92`, `CANONICAL_OWNER:NONE`, `RECONSTRUCTABLE:FALSE`, blank `EMITTER_UIDS`, blank `EMITTER_POSITION_OPTIONAL`. Proof: `by-memory/0x0049bd30-0x0049d6ed.DATManagers.md` header.
- [x] Target formal `RECONSTRUCTION_CPP CODE` block left empty with no marker/comment text. Proof: [UID:00012B] formal code block remains blank; validator `000000002280` exited 0.
- [x] Target Item Summary updated to non-emitting overlap/index language. Proof: [UID:00012B] Item Summary and Overview sections.
- [x] Target evidence updated with MCP session `80de0a67`, health (`status=ok`, `pid=26892`, `is_analyzing=false`, `auto_analysis_ready=true`), exact boundaries, raw destructor starts, 42 modeled-function span map, and non-owner overlaps. Proof: [UID:00012B] "2026-06-26 B002 live MCP evidence" and ownership map sections.
- [x] Target stale "field names/helper splits open" blocker replaced with field/helper alias tables. Proof: [UID:00012B] field/helper alias sections and support-page cross references.
- [x] Target stale aggregate-C++ blocker replaced with exact non-emitting-index no-code proof and child emission-site table. Proof: [UID:00012B] no-code proof plus child emission-site map.
- [x] Raw `DATFileMgr::~DATFileMgr` at `0x0049be50-0x0049be6d` added to target child map. Proof: [UID:00012B] child map row for [UID:00043A].
- [x] Raw `DATFileContainer::~DATFileContainer` at `0x0049c0d0-0x0049c130` added to target child map. Proof: [UID:00012B] child map row for [UID:00043C].
- [x] Existing [UID:00012F] raw `_DATFileMgr::~_DATFileMgr` endpoint clarified as half-open `0x0049c750-0x0049c7f7`/last live byte `0x0049c7f6`, preserving filename policy. Proof: `by-memory/0x0049c750-0x0049c7f6._DATFileMgrRawDestructor.md` Item Summary, Boundary, and implementation-repair sections.
- [x] Non-owner DATFile, SimpleUStringVector, wide-string thunk, and File overlap rows preserved/rejected from DATFileMgr ownership. Proof: [UID:00012B] non-owner overlap table and validator `000000002280` ok count 11.
- [x] [UID:0000IO] `by-file/DATFileMgr.md` updated with source split, field/type/helper aliases, helper roles, non-emitting parent wording, exact singleton zero-initialization wording, and no by-file score change. Proof: `by-file/DATFileMgr.md` DATManagers implementation sections; validator `000000002281` exited 0, ok count 11.
- [x] [UID:00003I] `by-class/DATFileMgr.md` updated with `m_impl`, public method map, raw ordinary destructor, [UID:00012C] class-owner repair, first-draft C++ routes C++-1/C++-2/C++-3, and no class score change. Proof: `by-class/DATFileMgr.md` B002 implementation sections; validator `000000002282` exited 0, ok count 3.
- [x] [UID:000004] `by-class/_DATFileMgr.md` updated with vector aliases, raw destructor route, method/helper map, first-draft C++ routes C++-7/C++-8/C++-9, and no class score change. Proof: `by-class/_DATFileMgr.md` B002 implementation sections; validator `000000002283` exited 0, ok count 7.
- [x] [UID:00003H] `by-class/DATFileContainer.md` updated with field aliases, constructor/destructor map, source behavior, first-draft C++ routes C++-6/C++-4, and no class score change. Proof: `by-class/DATFileContainer.md` B002 implementation sections; validator `000000002284` exited 0, ok count 3, with residual pre-existing `missing_ref_uid 0003B6` diagnostic.
- [x] [UID:00003J] `by-class/DATFileResolver.md` updated with node/result/helper aliases, resolver method/helper roles, cleanup-helper policy, first-draft C++ routes C++-11/C++-13, and no class score change. Proof: `by-class/DATFileResolver.md` B002 implementation sections; validator `000000002285` exited 0, ok count 5.
- [x] [UID:0000QQ] `by-global/g_pDATFileMgr.md`, [UID:0001P6] `by-memory/0x0067ab40-0x0067ab44.g_pDATFileMgr.md`, and repeated singleton note in [UID:0000IO] `by-file/DATFileMgr.md` updated with the exact live-byte sentence from this report. Proof: global/memory singleton sections record `DATFileMgr *g_pDATFileMgr = 0`; validators `000000002286` and `000000002287` exited 0, ok count 1 each.
- [x] Created `by-memory/0x0049bd30-0x0049be41.DATFileMgrConstructor.md` with metadata `86/90`, owner/emitter [UID:00003I], first-draft C++ C++-1. Proof: validator `000000002267` assigned [UID:000439], exited 0.
- [x] Created `by-memory/0x0049be50-0x0049be6d.DATFileMgrDestructor.md` with metadata `88/92`, owner/emitter [UID:00003I], first-draft C++ C++-2. Proof: validator `000000002268` assigned [UID:00043A], exited 0.
- [x] Repaired [UID:00012C] `by-memory/0x0049be70-0x0049be7c.ForwardLoadDATFileIndex.md` to metadata `90/93`, owner/emitter [UID:00003I], first-draft C++ C++-3. Proof: header and B002 repair section; validator `000000002269` exited 0, ok count 1.
- [x] Created `by-memory/0x0049be80-0x0049c0c9.DATFileContainerConstructor.md` with metadata `88/90`, owner/emitter [UID:00003H], first-draft C++ C++-6. Proof: validator `000000002270` assigned [UID:00043B], exited 0.
- [x] Created `by-memory/0x0049c0d0-0x0049c130.DATFileContainerDestructor.md` with metadata `88/91`, owner/emitter [UID:00003H], first-draft C++ C++-4. Proof: validator `000000002271` assigned [UID:00043C], exited 0.
- [x] Repaired [UID:00012E] `by-memory/0x0049c700-0x0049c71d.HasDATEntry.md` to metadata `90/92`, owner/emitter [UID:0000IO], first-draft C++ C++-5. Proof: header and B002 callback section; validator `000000002272` exited 0, ok count 1.
- [x] Repaired [UID:00012F] `by-memory/0x0049c750-0x0049c7f6._DATFileMgrRawDestructor.md` to metadata `88/92`, owner/emitter [UID:000004], half-open live body note `0x0049c750-0x0049c7f7`, first-draft C++ C++-7. Proof: header, Boundary, formal C++ block; validator `000000002273` exited 0, ok count 1.
- [x] Created `by-memory/0x0049c800-0x0049cac4._DATFileMgrLoadDATFileIndex.md` with metadata `88/90`, owner/emitter [UID:000004], first-draft C++ C++-8. Proof: validator `000000002274` assigned [UID:00043D], exited 0.
- [x] Created `by-memory/0x0049cad0-0x0049cba5._DATFileMgrFindEntryByName.md` with metadata `88/91`, owner/emitter [UID:000004], first-draft C++ C++-9. Proof: validator `000000002275` assigned [UID:00043E], exited 0.
- [x] Created `by-memory/0x0049cbb0-0x0049cc39.CreateDATEntryNode.md` with metadata `89/92`, owner/emitter [UID:0000IO], first-draft C++ C++-10. Proof: validator `000000002276` assigned [UID:00043F], exited 0.
- [x] Created `by-memory/0x0049ce50-0x0049d0c2.DATFileResolverInsertOrFindEntry.md` with metadata `88/91`, owner/emitter [UID:00003J], first-draft C++ C++-11. Proof: validator `000000002277` assigned [UID:00043G], exited 0.
- [x] Created `by-memory/0x0049d490-0x0049d4bd.AllocateDATEntryNode.md` with metadata `90/93`, owner/emitter [UID:0000IO], first-draft C++ C++-12. Proof: validator `000000002278` assigned [UID:00043H], exited 0.
- [x] Created `by-memory/0x0049d5e0-0x0049d6ed.DATFileResolverFindNodeByKey.md` with metadata `89/92`, owner/emitter [UID:00003J], first-draft C++ C++-13. Proof: validator `000000002279` assigned [UID:00043I], exited 0.
- [x] Did not create standalone emitting pages for `0x0049d0d0-0x0049d175`, `0x0049d180-0x0049d18b`, `0x0049d270-0x0049d275`, `0x0049d2d0-0x0049d349`, `0x0049d350-0x0049d38b`, `0x0049d3d0-0x0049d488`, `0x0049d4f0-0x0049d521`, or `0x0049d5a0-0x0049d5dc`; recorded them only as parent/support non-emitting compiler/EH/helper evidence. Proof: no by-memory files for those ranges were created; [UID:00012B] and support docs retain them as non-emitting evidence.
- [x] Formal C++ inserted only into the formal `RECONSTRUCTION_CPP CODE` block of child pages C++-1 through C++-13; no C++ inserted into [UID:00012B], non-owner overlap pages, compiler-generated wrapper pages, or EH helper notes. Proof: child pages [UID:000439]-[UID:00043I] plus repaired [UID:00012C]/[UID:00012E]/[UID:00012F]; target [UID:00012B] code block remains blank.
- [x] Validators run for every edited/created by-* file after supervisor implementation callback, using the scoped commands listed below. Proof: validator table in this section.
- [x] Report checklist updated with checked items, files changed, validator command IDs/timestamps/exit status, and lease use/release proof after implementation. Proof: this implementation tracking section.

Validator proof from `E:\NTK\GhidraBridge\source-3\project-documentation`:

| File | Command id | Timestamp | Exit | Ok count |
| --- | --- | --- | --- | --- |
| `by-memory\0x0049bd30-0x0049be41.DATFileMgrConstructor.md` | `000000002267` | `2026-06-26T04:11:00-04:00` | 0 | not emitted during new UID insert; [UID:000439] assigned |
| `by-memory\0x0049be50-0x0049be6d.DATFileMgrDestructor.md` | `000000002268` | `2026-06-26T04:11:02-04:00` | 0 | not emitted during new UID insert; [UID:00043A] assigned |
| `by-memory\0x0049be70-0x0049be7c.ForwardLoadDATFileIndex.md` | `000000002269` | `2026-06-26T04:11:03-04:00` | 0 | 1 |
| `by-memory\0x0049be80-0x0049c0c9.DATFileContainerConstructor.md` | `000000002270` | `2026-06-26T04:11:05-04:00` | 0 | not emitted during new UID insert; [UID:00043B] assigned |
| `by-memory\0x0049c0d0-0x0049c130.DATFileContainerDestructor.md` | `000000002271` | `2026-06-26T04:11:06-04:00` | 0 | not emitted during new UID insert; [UID:00043C] assigned |
| `by-memory\0x0049c700-0x0049c71d.HasDATEntry.md` | `000000002272` | `2026-06-26T04:11:08-04:00` | 0 | 1 |
| `by-memory\0x0049c750-0x0049c7f6._DATFileMgrRawDestructor.md` | `000000002273` | `2026-06-26T04:11:09-04:00` | 0 | 1 |
| `by-memory\0x0049c800-0x0049cac4._DATFileMgrLoadDATFileIndex.md` | `000000002274` | `2026-06-26T04:11:11-04:00` | 0 | not emitted during new UID insert; [UID:00043D] assigned |
| `by-memory\0x0049cad0-0x0049cba5._DATFileMgrFindEntryByName.md` | `000000002275` | `2026-06-26T04:11:12-04:00` | 0 | not emitted during new UID insert; [UID:00043E] assigned |
| `by-memory\0x0049cbb0-0x0049cc39.CreateDATEntryNode.md` | `000000002276` | `2026-06-26T04:11:14-04:00` | 0 | not emitted during new UID insert; [UID:00043F] assigned |
| `by-memory\0x0049ce50-0x0049d0c2.DATFileResolverInsertOrFindEntry.md` | `000000002277` | `2026-06-26T04:11:15-04:00` | 0 | not emitted during new UID insert; [UID:00043G] assigned |
| `by-memory\0x0049d490-0x0049d4bd.AllocateDATEntryNode.md` | `000000002278` | `2026-06-26T04:11:17-04:00` | 0 | not emitted during new UID insert; [UID:00043H] assigned |
| `by-memory\0x0049d5e0-0x0049d6ed.DATFileResolverFindNodeByKey.md` | `000000002279` | `2026-06-26T04:11:19-04:00` | 0 | not emitted during new UID insert; [UID:00043I] assigned |
| `by-memory\0x0049bd30-0x0049d6ed.DATManagers.md` | `000000002280` | `2026-06-26T04:11:30-04:00` | 0 | 11 |
| `by-file\DATFileMgr.md` | `000000002281` | `2026-06-26T04:11:41-04:00` | 0 | 11 |
| `by-class\DATFileMgr.md` | `000000002282` | `2026-06-26T04:11:43-04:00` | 0 | 3 |
| `by-class\_DATFileMgr.md` | `000000002283` | `2026-06-26T04:11:44-04:00` | 0 | 7 |
| `by-class\DATFileContainer.md` | `000000002284` | `2026-06-26T04:11:46-04:00` | 0 | 3; residual pre-existing `missing_ref_uid 0003B6` diagnostic |
| `by-class\DATFileResolver.md` | `000000002285` | `2026-06-26T04:11:47-04:00` | 0 | 5 |
| `by-global\g_pDATFileMgr.md` | `000000002286` | `2026-06-26T04:11:49-04:00` | 0 | 1 |
| `by-memory\0x0067ab40-0x0067ab44.g_pDATFileMgr.md` | `000000002287` | `2026-06-26T04:12:00-04:00` | 0 | 1 |

All scoped validator runs reported `generated_refresh: deferred`. The implementation did not manually edit generated files, project-level generated files, coverage reports, validator/tool state, or the IDA DB.

Expected validator commands from `E:\NTK\GhidraBridge\source-3\project-documentation` after implementation:

> Executable block R001 was removed from this report and preserved verbatim in [00012B-DATManagers-source-quality-removed.md](00012B-DATManagers-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B002","command_id":"000000004165","destination_path":"executed-b-agent-research/B002/00012B-DATManagers-source-quality.md","details":"legacy registry reconstruction","event":"executed","source_path":"tools/leaser/Agents/Agent-B002/research/00012B-DATManagers-source-quality.md","timestamp":"2026-06-26T04:18:25","uid":"00012B"} -->
<!-- {"agent":"B002","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 00012B-DATManagers-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B002/00012B-DATManagers-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"00012B"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
