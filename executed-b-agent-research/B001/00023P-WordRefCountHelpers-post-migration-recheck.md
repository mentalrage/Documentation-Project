** TARGET-REPORT-UID:00023P **
** AUTHOR-AGENT-ID:B001 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# 00023P WordRefCountHelpers Post-Migration Recheck

## Finalized Report / Current Recommendation

- Current recommendation: keep [UID:00023P][0x00554640-0x00554675.WordRefCountHelpers](../../../../../by-memory/0x00554640-0x00554675.WordRefCountHelpers.md) as `CANONICAL_OWNER:NONE`, `RECONSTRUCTABLE:TRUE`, with blank `EMITTER_UIDS`, blank `EMITTER_POSITION_OPTIONAL`, and blank reconstruction C++.
- Final disposition: source-authored or source-required 16-bit intrusive reference-count helper island, probably retained/dead or only reachable through evidence not present in the static binary; no direct semantic owner and no source-use emitter route clears the current model.
- Required action: no metadata edit, no score edit, no split, no merge, no rename, no IDA repair, no reclassification to compiler/runtime-only, and no `by-memory/-coverage-report.md` row change.
- Confidence: high for range/bytes/behavior/no-reference facts; high for rejecting existing owner/emitter routes; medium for the best-if-forced narrow utility-source hypothesis because it has no independent caller, table, type, source, PDB, or object-file evidence.

## Exact Recommendation

Retain the target metadata exactly:

```text
*** COMPLETION:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:NONE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
```

No `by-memory/-coverage-report.md` replacement is required. The current manual row at the `0x00554640-0x00554675` placement remains materially correct:

```text
    - [UID:00023P][0x00554640-0x00554675.WordRefCountHelpers](by-memory/0x00554640-0x00554675.WordRefCountHelpers.md) 0x00554640-0x00554675 | function cluster | WordRefCountHelpers : reconstructable : 88% : strong : B002 second-pass live IDA and independent PE scans reconfirm a coherent, unique three-helper 16-bit intrusive refcount island with modeled initializer `0x00554640-0x0055464b`, raw increment helper `0x00554650-0x00554654`, raw release/free helper `0x00554660-0x00554675`, exact surrounding/internal `0xcc` padding, decompiled `_WORD` initializer, zero xrefs/xref signatures to all three starts, zero absolute-VA/RVA/relative-branch references, unique exact and wildcarded full-range signatures, unique per-helper byte patterns, no local names in `0x00554600-0x00554700`, no `refcount`/`intrusive`/PDB metadata strings, and negative controls showing the `push 2` free-wrapper idiom also appears only in MiniMapVersionManager cleanup/destructor paths plus this island. Existing ReconnectDialog/CopyWindow/Region/Motion/StringBase/StringUtil/LinkedList/PoolAllocator/LObject/MiniMapVersionManager/CRT owners are rejected; a narrow `util/WordRefCountHelpers` or `IntrusiveWordRefCount` source-family remains the best-if-forced hypothesis but does not clear owner/emitter assignment without caller, table, type, source, or object-file evidence.
```

The current generated rows should remain semantically unchanged after normal tool refresh:

```text
| [UID:00023P][0x00554640-0x00554675.WordRefCountHelpers](by-memory/0x00554640-0x00554675.WordRefCountHelpers.md) | no-owner | `NONE` |  |  | no |  | `by-memory/0x00554640-0x00554675.WordRefCountHelpers.md` |  |
| [UID:00023P][0x00554640-0x00554675.WordRefCountHelpers](by-memory/0x00554640-0x00554675.WordRefCountHelpers.md) | no-owner | `by-memory/0x00554640-0x00554675.WordRefCountHelpers.md` |  |  |  |
```

## Supporting Research

## Target

- Target UID: `00023P`
- Target path: `by-memory/0x00554640-0x00554675.WordRefCountHelpers.md`
- Source queue/report row: `auto-generated/-ag-memory-coverage.md` no-owner/non-emitting memory row.
- Tracker: `tools/leaser/Agents/no_owner_b-agent-tracker.md` row `00023P`.
- Current state: `COMPLETION:88`, `CONFIDENCE:92`, `CANONICAL_OWNER:NONE`, `RECONSTRUCTABLE:TRUE`, blank `EMITTER_UIDS`.
- Prior reports reviewed as evidence, not adopted as authority:
  - `tools/leaser/Agents/Agent-B001/research/executed/00023P-WordRefCountHelpers.md`
  - `tools/leaser/Agents/Agent-B001/research/executed/00023P-WordRefCountHelpers-B001-00023P.md`
  - `tools/leaser/Agents/Agent-B003/research/executed/00023P-WordRefCountHelpers-post-migration.md`
  - `tools/leaser/Agents/Agent-B002/research/executed/00023P-WordRefCountHelpers-second-pass.md`

## Executive Recommendation

Keep this as a single no-owner/non-emitting reconstructable helper island. The binary evidence strongly proves the bytes, half-open range, padding boundaries, helper behavior, and absence of static references. It does not prove who declared the helpers, who used them, or where emitted source should be routed.

This is not an invalid `RECONSTRUCTABLE:TRUE` state under the current owner/emitter model. `by-structure.md` allows project-owned source items to stay reconstructable while ownership and source-output routing are unresolved. The page has no emitted C++ and no proven source-use context, so blank `EMITTER_UIDS` is the correct output-routing state. The no-owner-with-emitters model applies to pooled/shared literals or constants with proven consumers; this target is unique executable code with no proven source-use consumer.

Do not recommend reconstruction C++. Although confidence is above `90`, completion remains `88` and the active `90/90+` code-entry gate also requires verified owner/emitter route, source placement, names, dependencies, and surrounding placement. Those source-routing conditions are not met.

## Supervisor Active Recheck

This B001 pass rechecked the current post-migration result independently:

- Read B001 `goal.md`, `by-structure.md` owner/emitter/code-entry rules, and `inference_research.md`.
- Reviewed the current target page, generated rows, manual coverage row, tracker row, prior reports, adjacent by-memory pages, and plausible by-file/by-type owner docs.
- Queried live IDA MCP session `b001_0003gy` for function boundaries, xrefs, decompilation, bytes, signatures, raw pointer-byte patterns, local names, string-regex evidence, and MiniMapVersionManager comparison sites.
- Ran a read-only PE scan of `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe` for exact bytes, duplicate patterns, VA/RVA pointer hits, direct branch/call targets, and `sub_5C7526` free-wrapper idioms.
- No split repair was needed before final recommendation. Splitting the initializer/addref/release bodies would create three children with the same unresolved owner/emitter blocker and would not add source-placement evidence.

## Inference Research Guidance Check

Facts:

- The target is executable `.text` code, not padding.
- The three helper bodies are unique in the binary and form a coherent init/increment/release family.
- Static IDA and raw PE checks find no incoming code/data/pointer/branch references to the three helper starts.

Documentation evidence:

- Adjacent reconnect/copy-window and Region/Motion pages have their own exact boundaries and padding separation.
- The documented StringBase/StringUtil reference-counting family uses an incompatible 12-byte header, 32-bit interlocked counters, sentinels, and pool/heap release logic.
- LinkedList, PoolAllocator, LObject, and MiniMapVersionManager pages describe different concrete ownership chains.

Inference:

- A narrow utility source family such as `NexusTK/util/WordRefCountHelpers.cpp` or an `IntrusiveWordRefCount` helper/type is the best if-forced placement.
- That placement remains below the owner/emitter assignment gate because it is inferred only from behavior, not from a caller, table, type, source artifact, or object-file boundary.

## Evidence Standards Used

Evidence types used:

- IDA MCP `server_health`, `lookup_funcs`, `xrefs_to`, `decompile`, `analyze_function`, `get_bytes`, `make_signature`, `make_signature_for_range`, `find_xref_signatures`, `find_bytes`, `entity_query`, `find_regex`, and comparison-site decompilation/disassembly.
- PE section-aware raw scan for exact bytes, byte-pattern uniqueness, literal VA/RVA dword references, executable-section direct branch/call targets, and `sub_5C7526` call-site shapes.
- Existing by-memory, by-file, by-type, proposed source tree, generated coverage, manual coverage, and tracker documentation.

This evidence is strong enough to reject all current owner/emitter candidates and preserve `NONE` with blank emitters. It is not strong enough to create or assign a new source owner.

## IDA MCP Facts

Live IDA MCP facts from 2026-06-13:

| Field | Value |
| --- | --- |
| Session | `b001_0003gy` |
| IDB path | `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe.i64` |
| Input path | `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe` |
| Module | `NexusTK.exe` |
| Image base | `0x400000` |
| Auto-analysis | ready |
| Hex-Rays | ready |
| Strings cache | ready |

Function and boundary facts:

| Query | IDA result |
| --- | --- |
| `0x00554635` | not a function |
| `0x00554640` | `sub_554640`, size `0x0b` |
| `0x0055464b` | not a function |
| `0x00554650` | not a function |
| `0x00554654` | not a function |
| `0x00554660` | not a function |
| `0x00554675` | not a function |
| `0x00554680` | `sub_554680`, size `0x61` |
| `0x005c7526` | `sub_5C7526`, size `0x0e` |
| `0x00456480` | `sub_456480`, size `0xb2` |
| `0x00457480` | `sub_457480`, size `0xc7` |

IDA decompiles the modeled initializer at `0x00554640` as:

```cpp
_WORD *__thiscall sub_554640(_WORD *this)
{
  *this = 1; /*0x554645*/
  return this; /*0x55464a*/
}
```

IDA decompiles the outgoing free-wrapper dependency at `0x005c7526` as:

```cpp
void __cdecl sub_5C7526(void *Block)
{
  j_j___free_base(Block); /*0x5c752c*/
}
```

Raw bytes from `0x00554635-0x00554680`:

| Range | Bytes |
| --- | --- |
| `0x00554635-0x00554640` | eleven `cc` bytes |
| `0x00554640-0x0055464b` | `b8 01 00 00 00 66 89 01 8b c1 c3` |
| `0x0055464b-0x00554650` | five `cc` bytes |
| `0x00554650-0x00554654` | `66 ff 01 c3` |
| `0x00554654-0x00554660` | twelve `cc` bytes |
| `0x00554660-0x00554675` | `66 ff 09 66 83 39 00 7f 0b 6a 02 51 e8 b5 2e 07 00 83 c4 08 c3` |
| `0x00554675-0x00554680` | eleven `cc` bytes |

Equivalent raw disassembly:

```asm
00554640  mov     eax, 1
00554645  mov     [ecx], ax
00554648  mov     eax, ecx
0055464a  retn
0055464b  cc cc cc cc cc
00554650  inc     word ptr [ecx]
00554653  retn
00554654  cc cc cc cc cc cc cc cc cc cc cc cc
00554660  dec     word ptr [ecx]
00554663  cmp     word ptr [ecx], 0
00554667  jg      short 0x00554674
00554669  push    2
0055466b  push    ecx
0055466c  call    sub_5C7526
00554671  add     esp, 8
00554674  retn
```

Xref facts:

| Address | IDA xrefs |
| --- | --- |
| `0x00554640` | zero |
| `0x00554650` | zero |
| `0x00554660` | zero |
| `0x00554675` | zero |
| `0x00554680` | many code xrefs; the query was capped and marked more available |

`analyze_function 0x00554640` reports prototype `_WORD *__thiscall(_WORD *this)`, one basic block, no callers, no callees, no strings, and no constants list.

Signature and byte-search facts:

| Query | Result |
| --- | --- |
| `make_signature 0x00554640` | `B8 01 00 00 00 66 89 01`, unique |
| `make_signature 0x00554650` | `66 FF 01`, unique |
| `make_signature 0x00554660` | `66 FF 09 66 83 39 00`, unique |
| exact range signature `0x00554640-0x00554675` | unique |
| wildcarded range signature `0x00554640-0x00554675` | unique |
| `find_xref_signatures` for all three starts | `total_xrefs: 0` each |
| exact initializer pattern | one match at `0x00554640` |
| exact increment pattern | one match at `0x00554650` |
| exact release pattern | one match at `0x00554660` |
| exact `push 2; push ecx; call sub_5C7526; add esp, 8; retn` tail | one match at `0x00554669` |

IDA raw pointer-byte checks:

| Pattern | Meaning | Result |
| --- | --- | --- |
| `40 46 55 00` | VA `0x00554640` | none |
| `40 46 15 00` | RVA `0x00154640` | none |
| `50 46 55 00` | VA `0x00554650` | none |
| `50 46 15 00` | RVA `0x00154650` | none |
| `60 46 55 00` | VA `0x00554660` | none |
| `60 46 15 00` | RVA `0x00154660` | none |
| `75 46 55 00` | VA `0x00554675` | none |
| `75 46 15 00` | RVA `0x00154675` | none |
| `80 46 55 00` | VA `0x00554680` positive control | one match at `0x00504178` |

Name/string facts:

- `entity_query` for names in `0x00554600-0x00554700` returned no names.
- `entity_query` for functions in `0x00554500-0x00554720` shows the predecessor function island ending before the target, the target initializer at `0x00554640`, and the successor Region/Motion island beginning at `0x00554680`; no functions at `0x00554650` or `0x00554660`.
- `find_regex` for `refcount|referencecount|ref count|intrusive|wordref|word ref` returned zero string-cache matches.
- `find_regex` for `pdb|RSDS|NB10|WordRef|Intrusive` returned zero string-cache matches.

## PE / Raw Evidence

Read-only PE scan path: `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`.

PE section facts:

| Section | VA range | Role |
| --- | --- | --- |
| `.text` | `0x00401000-0x0060c600` | executable; target is here |
| `.rdata` | `0x0060d000-0x0066c200` | read-only data |
| `.data` | `0x0066d000-0x0069ce24` | writable data |
| `.rsrc` | `0x0069d000-0x006b2e00` | resources |

PE exact byte-pattern hits:

| Pattern | Hits |
| --- | --- |
| initializer exact | one, `0x00554640` |
| increment exact | one, `0x00554650` |
| release exact | one, `0x00554660` |
| free-tail exact | one, `0x00554669` |
| short initializer signature | one, `0x00554640` |
| short increment signature | one, `0x00554650` |
| short release signature | one, `0x00554660` |

PE literal pointer/reference scan:

| Target | Absolute VA dword hits | RVA dword hits | Direct branch/call hits |
| --- | ---: | ---: | ---: |
| `0x00554640` | 0 | 0 | 0 |
| `0x00554650` | 0 | 0 | 0 |
| `0x00554660` | 0 | 0 | 0 |
| `0x00554675` | 0 | 0 | 0 |
| `0x00554680` positive control | 1 absolute pointer hit at `0x00504178` | 0 | many direct call hits |

The branch scan covered executable-section `E8/E9 rel32`, `0F 80-8F rel32`, `EB rel8`, `70-7F rel8`, and `E3 rel8` encodings. The positive-control successor at `0x00554680` confirms the scan can find real code references in this region; the absence for the target starts is meaningful.

Free-wrapper scan:

- Direct calls to `sub_5C7526`: `617`.
- Calls with a nearby `push 2` in the previous 20 bytes: `0x004564bb`, `0x004574bb`, and `0x0055466c`.
- The two non-target sites decompile as MiniMapVersionManager cleanup/destructor loops freeing list payload strings/nodes. They are allocator/deallocation idiom controls, not ownership evidence for `00023P`.

## Function / Child Inventory

| Range / Item | UID / Path | Role | Reconstructable | Direct Owner | Emitters | Score | Status |
| --- | --- | --- | --- | --- | --- | --- | --- |
| `0x00554640-0x00554675` | `00023P` / target page | complete init/addref/release helper island | true | `NONE` | blank | `88/92` | keep as-is |
| `0x00554640-0x0055464b` | contained in target | initializer: `word [this] = 1`; return `this` | true | unresolved | blank | inherited | no split |
| `0x00554650-0x00554654` | contained in target | addref: increment first word | true | unresolved | blank | inherited | no split |
| `0x00554660-0x00554675` | contained in target | release: decrement first word; free when count is not positive | true | unresolved | blank | inherited | no split |
| `0x00554635-0x00554640` | `by-memory/-ignored.md` | leading alignment padding | false/ignored | none | none | `100/strong` | unchanged |
| `0x0055464b-0x00554650` | `by-memory/-ignored.md` | internal alignment padding | false/ignored | none | none | `100/strong` | unchanged |
| `0x00554654-0x00554660` | `by-memory/-ignored.md` | internal alignment padding | false/ignored | none | none | `100/strong` | unchanged |
| `0x00554675-0x00554680` | `by-memory/-ignored.md` | trailing alignment padding | false/ignored | none | none | `100/strong` | unchanged |

## Direct Xref / Caller Inventory

| Address / Item | Xref / Caller / Callee | Meaning |
| --- | --- | --- |
| `0x00554640` | no IDA xrefs, no xref signatures, no raw VA/RVA pointer hits, no branch/call targets | no proven caller, table entry, source-use context, or owner |
| `0x00554650` | no IDA xrefs, no xref signatures, no raw VA/RVA pointer hits, no branch/call targets | raw addref helper has no proven use |
| `0x00554660` | no IDA xrefs, no xref signatures, no raw VA/RVA pointer hits, no branch/call targets | raw release helper has no proven use |
| `0x0055466c -> 0x005c7526` | outgoing free-wrapper call | dependency only; not source ownership |
| `0x00554680` | many IDA xrefs and many PE branch hits | successor Region/Motion constructor island is live and independently referenced |
| `0x004564bb`, `0x004574bb` | other `push 2` free-wrapper sites | MiniMapVersionManager teardown payload/node frees; negative controls |

## Documentation Evidence And IDA Status

Existing docs that support keeping no-owner/non-emitting:

- The target page already documents the three-helper island and the current `CANONICAL_OWNER:NONE` / blank-emitter state; this B001 pass reconfirmed the material IDA and PE facts.
- `by-structure.md` separates semantic owner from output routing and allows `RECONSTRUCTABLE:TRUE` items to remain ownerless/non-emitting when the owner/emitter route is not ready.
- `auto-generated/-ag-memory-coverage.md` lists `00023P` as no-owner with `NONE` and blank emitters.
- The tracker records the prior B002 second-pass and supervisor execution; this pass independently confirms that conclusion remains correct.

Existing docs that block candidate routes:

- [UID:00038K][ConnectionReconnectDialogCleanupAndDestructorThunks](../../../../../by-memory/0x00554550-0x00554635.ConnectionReconnectDialogCleanupAndDestructorThunks.md) ends at `0x00554635`; `0x00554635-0x00554640` is padding before the target.
- [UID:0001FT][ConnectionClosedReconnectDialogs](../../../../../by-memory/0x00553c10-0x00554635.ConnectionClosedReconnectDialogs.md) is a mixed physical map whose exact source children end before the target.
- [UID:0001FW][RegionAndMotionRect](../../../../../by-memory/0x00554680-0x00554b38.RegionAndMotionRect.md) starts at `0x00554680` after target trailing padding and owns the next heavily referenced Region/Motion island, not this helper.
- [UID:0000OA][StringBase](../../../../../by-file/StringBase.md) and [UID:0001VQ][RefCountedStringBufferHeader](../../../../../by-type/by-struct/RefCountedStringBufferHeader.md) document a 12-byte string-buffer prefix, 32-bit `InterlockedIncrement`/`InterlockedDecrement` counts, sentinels, and pool/heap release logic; this contradicts a direct StringBase route for a 16-bit object-head counter that frees `this`.
- [UID:0000OB][StringUtil](../../../../../by-file/StringUtil.md) is a utility-string umbrella and delegates the actual ref-counted string buffer core to `StringBase`; it has no direct source-use evidence for this no-xref island.
- [UID:0000KR][LinkedList](../../../../../by-file/LinkedList.md) owns sentinel-list/node helpers, not a first-word word-counted heap object.
- [UID:0000MM][PoolAllocator](../../../../../by-file/PoolAllocator.md) owns fixed-block pool mechanics; the target uses a free-wrapper directly and touches no pool state.
- [UID:0000KV][LObject](../../../../../by-file/LObject.md) owns a one-vptr runtime/base shell; the target has no vtable/runtime-class evidence.
- [UID:0000LF][MiniMapVersionManager](../../../../../by-file/MiniMapVersionManager.md) owns the two comparison `push 2` free-wrapper sites, but those are minimap list cleanup paths and do not reference this target.

## Ranked Ownership / Emitter Analysis

### 1. Keep `CANONICAL_OWNER:NONE`, blank `EMITTER_UIDS` - recommended

Evidence for:

- Zero IDA xrefs and zero xref signatures to all three helper starts.
- Zero PE absolute-VA, RVA, and direct branch/call references to all three helper starts.
- No local names, source strings, PDB/CodeView markers, vtable slots, callback tables, or type metadata connect the target to a source owner.
- Existing candidate owners are contradicted by padding boundaries, incompatible layouts, or unrelated decompiled behavior.
- Current by-structure rules permit reconstructable but unresolved no-owner/non-emitting backlog while research continues.

Evidence against:

- The three helper bodies look like a deliberate source-level lifetime API.
- The likely original source had some declaration if the code was not retained dead code.

Decision: accept. This state preserves the known behavior without inventing ownership or source-output routing.

### 2. New narrow `NexusTK/util/WordRefCountHelpers.cpp` or `IntrusiveWordRefCount` owner - best if forced, below gate

Evidence for:

- The initializer, addref, and release helpers form a complete small helper family.
- The behavior is generic lifetime management rather than specific UI, Region/Motion, string-buffer, list, pool, or minimap logic.
- `NexusTK/util/` is the natural proposed-source-tree neighborhood for shared utility/container/lifetime support.
- No existing owner is stronger.

Evidence against:

- No caller, pointer table, source-facing name, recovered type, PDB, linker map, object-file boundary, or source-path breadcrumb proves this file or type.
- A new by-file owner would currently contain only this no-xref helper island.
- `by-structure.md` warns not to invent standalone owners or emitters solely to avoid `NONE`.

Decision: record as future hypothesis only. Do not create a by-file owner, set `CANONICAL_OWNER`, or add `EMITTER_UIDS`.

Likely full contents if future evidence supports it:

- One narrow intrusive word-reference-count helper/type with operations equivalent to initialize count to one, increment count, and decrement/free when nonpositive.
- No current neighboring by-memory range should be auto-attached; predecessor and successor islands already have stronger separate owners.

### 3. `StringBase` / `StringUtil` - rejected

Evidence for:

- Abstract refcount/lifetime theme.
- Both are utility-root pages under `NexusTK/util/`.

Blocking facts:

- StringBase refcounts live in a 12-byte header before the returned data pointer, not at the object head.
- StringBase counts are 32-bit and interlocked, not 16-bit word increments/decrements.
- StringBase release uses sentinels and pool/heap selection, not direct `free(this)` for a first-word-counted object.
- No StringBase/StringUtil method, vtable, type, global, or source-use route references `0x00554640`, `0x00554650`, or `0x00554660`.

Decision: reject ownership and emitters.

### 4. ReconnectDialog / ConnectionClosedDialog / CopyWindow - rejected

Evidence for:

- The target physically follows reconnect/copy-window cleanup and destructor code.

Blocking facts:

- The preceding exact child ends at `0x00554635`, followed by eleven `0xcc` bytes before this target.
- No reconnect, connection-closed, or CopyWindow function, vtable, singleton, or callback table targets any helper start.
- The predecessor code is UI/dialog singleton/vtable/destructor behavior, not word-counted heap-object lifetime.

Decision: reject. Adjacency only.

### 5. Region / Motion - rejected

Evidence for:

- The target physically precedes the heavily used Region/Motion constructor island at `0x00554680`.

Blocking facts:

- `0x00554675-0x00554680` is eleven `0xcc` bytes.
- `0x00554680` has many code references and one raw pointer positive-control hit; all target starts have none.
- Region/Motion docs describe vptr and rectangle state, not a first-word reference-count object.

Decision: reject. The positive Region evidence actually emphasizes the target's isolation.

### 6. LinkedList / PoolAllocator / LObject / MiniMapVersionManager / CRT - rejected

Evidence for:

- These are utility or lifetime-adjacent systems.
- MiniMapVersionManager shares the `push 2` free-wrapper idiom at two sites.
- The release helper calls a CRT free-wrapper dependency.

Blocking facts:

- LinkedList is sentinel-node/list-state code with incompatible shape.
- PoolAllocator is fixed-block pool state with chunks, free lists, and lock state; the target has no pool interaction.
- LObject is a vptr/runtime-class base shell.
- MiniMapVersionManager comparison sites free minimap list payloads/nodes and are not callers/owners of the target helpers.
- A free-wrapper dependency with 617 direct callers cannot own every caller-specific lifetime helper.

Decision: reject all as owner/emitter routes.

### 7. Reclassify as compiler-generated or runtime-only - rejected

Evidence for:

- The code is unreferenced in static scans and ends in a deallocation wrapper.

Blocking facts:

- The three routines implement a coherent project-level init/addref/release protocol, not a known CRT/VC runtime helper.
- The exact byte patterns are unique and not FLIRT/runtime-named.
- Only the final deallocation callee is runtime-like.

Decision: keep `RECONSTRUCTABLE:TRUE`.

## Why Blank `EMITTER_UIDS` Is Correct

`EMITTER_UIDS` controls generated output routing, not documentation ownership. A page with blank emitters is not automatically invalid when:

- it is reconstructable,
- it has no emitted C++ block,
- and no source-use context clears the evidence gate.

`00023P` satisfies those conditions. It is not a pooled literal/shared constant case with multiple proven consumers. It has no proven consumers at all. Emitting it through `StringBase`, `StringUtil`, `Region`, `ReconnectDialog`, `PoolAllocator`, `LObject`, `MiniMapVersionManager`, or a newly invented utility file would assert a source route the binary does not currently support.

## Negative Evidence Summary

Checked and rejected:

- IDA modeled function starts at `0x00554650` and `0x00554660`.
- IDA xrefs to `0x00554640`, `0x00554650`, and `0x00554660`.
- IDA xref signatures for all three starts.
- Raw absolute VA and RVA pointer hits for all three starts.
- Raw direct executable-section branch/call encodings to all three starts.
- Duplicate exact helper byte patterns.
- Local names around `0x00554600-0x00554700`.
- String-cache hits for `refcount`, `referencecount`, `ref count`, `intrusive`, `wordref`, `word ref`, `pdb`, `RSDS`, and `NB10`.
- Predecessor reconnect/copy-window ownership across padding.
- Successor Region/Motion ownership across padding.
- StringBase/StringUtil abstract refcount ownership.
- LinkedList, PoolAllocator, LObject, MiniMapVersionManager, and CRT/free-wrapper ownership.

The remaining blocker is precise: no current IDA, raw PE, or documentation evidence proves the original source declaration owner or any emitted source-use route.

## Score / Coverage Effects

- Before score: `88/92`.
- Recommended after score: `88/92`.
- Completion should not be raised to the active code-entry bar because source route, API spelling, type name, live reachability, and original file remain unresolved.
- Confidence should not be lowered because this B001 pass reconfirmed the hard facts and did not find contradictory evidence.
- Reconstructable state remains `TRUE`: this is executable helper logic, not padding or a known runtime-library-only artifact.
- Coverage row: no change required.
- Generated `auto-generated/-ag-memory-coverage.md`: no manual edit required; normal tool refresh should keep the no-owner/non-emitting rows.

## Final Recommendation

Exact changes recommended:

- No target metadata change.
- No score change.
- No `CANONICAL_OWNER` assignment.
- No `EMITTER_UIDS` assignment.
- No `EMITTER_POSITION_OPTIONAL` value.
- No reconstruction C++.
- No split/merge/rename.
- No IDA repair.
- No `by-memory/-coverage-report.md` edit.

Condition that would change the recommendation:

- a direct code/data/table/vtable/reference edge to `0x00554640`, `0x00554650`, or `0x00554660`;
- a recovered source/PDB/linker-map/object-file breadcrumb naming the compilation unit;
- a documented type/class with first-word 16-bit intrusive refcount semantics and references to these helpers;
- or an explicit project-policy decision to create narrow owners for unique no-xref retained helper islands, with the new owner page itself documented and scored before assignment.

## Follow-Up Actions

Supervisor actions:

- Accept this B001 recheck as no metadata/coverage change.
- Do not add emitters for existing utility or adjacent feature owners under current evidence.
- Do not create `WordRefCountHelpers.cpp` merely to reduce no-owner counts unless the project explicitly adopts that policy for retained no-xref helper islands.

A-agent actions:

- Leave the page out of source-output routing until new source-use evidence appears.
- Do not add final C++ while owner/emitter route and API/type names remain unresolved.

B001 future research actions:

- Revisit only if a later target uncovers a matching first-word 16-bit refcount type, hidden dispatch/reference table, or source/debug breadcrumb.

## Confidence

- Recommendation confidence: `91/100`.
- Range/byte confidence: `96/100`.
- No-reference confidence: `95/100`.
- Existing-owner rejection confidence: `90/100`.
- Best-if-forced narrow utility owner hypothesis: `72/100`, below assignment threshold.
- Remaining uncertainty: original source filename, original API/type spelling, whether the helpers are dead retained code, and whether a runtime-only indirect path ever reached them.

## Validator Results

- Validator commands run: none.
- Reason: this assignment created only an Agent-B001 research report and did not edit validator-managed by-* documentation. The user prohibited dry-run modes, and no normal `--apply` validator action was required for an Agent research Markdown file.
- Memory-range mode: not used.
- Unresolved validator warnings/errors from this pass: none.

## Changed Files

- Created: `tools/leaser/Agents/Agent-B001/research/00023P-WordRefCountHelpers-post-migration-recheck.md`
- Modified: none outside Agent-B001 research.
- Renamed: none.
- Moved to executed: none.
- Direct `by-memory/-coverage-report.md` edits: none.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B001","command_id":"000000004165","destination_path":"executed-b-agent-research/B001/00023P-WordRefCountHelpers-post-migration-recheck.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:20","uid":"00023P"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
