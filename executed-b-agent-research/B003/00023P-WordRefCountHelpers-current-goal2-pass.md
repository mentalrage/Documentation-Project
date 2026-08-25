** TARGET-REPORT-UID:00023P **
** AUTHOR-AGENT-ID:B003 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# 00023P WordRefCountHelpers Current Goal 2 Pass

## Finalized Report / Current Recommendation

- Current recommendation: keep [UID:00023P] `by-memory/0x00554640-0x00554675.WordRefCountHelpers.md` as `CANONICAL_OWNER:NONE`, `RECONSTRUCTABLE:TRUE`, blank `EMITTER_UIDS`, blank `EMITTER_POSITION_OPTIONAL`, and blank reconstruction C++.
- Final disposition: source-authored or source-required 16-bit intrusive word reference-count helper island, but no proven direct semantic owner and no proven source-use emitter route.
- Required action: no metadata edit, no score edit, no split, no merge, no reclassification, no IDA-safe name repair, no final C++ entry, and no required `by-memory/-coverage-report.md` edit.
- Confidence: high for range, bytes, behavior, uniqueness, and static no-reference evidence; high for rejecting existing owners/emitters; medium for the best-if-forced narrow utility-source hypothesis, which remains below assignment threshold.

The target should remain a valid no-owner/non-emitting reconstructable item. The current evidence proves a coherent helper family but does not prove who declared it, who called it, whether it was retained dead code, or where final source should be emitted.

## Supporting Research

## Target

- Target UID: `00023P`
- Target path: `by-memory/0x00554640-0x00554675.WordRefCountHelpers.md`
- Source queue/report row: `auto-generated/-ag-memory-coverage.md` no-owner/non-emitting memory row.
- Current supervisor classification: 2026-06-14 B003 current no-owner/non-emitting memory recheck.
- Current scores and parent state: `COMPLETION:88`, `CONFIDENCE:92`, `CANONICAL_OWNER:NONE`, `RECONSTRUCTABLE:TRUE`, blank `EMITTER_UIDS`.
- Current generated primary row:

```text
| [UID:00023P][0x00554640-0x00554675.WordRefCountHelpers](by-memory/0x00554640-0x00554675.WordRefCountHelpers.md) | no-owner | `NONE` |  |  | no |  | `by-memory/0x00554640-0x00554675.WordRefCountHelpers.md` |  |
```

- Current generated secondary row:

```text
| [UID:00023P][0x00554640-0x00554675.WordRefCountHelpers](by-memory/0x00554640-0x00554675.WordRefCountHelpers.md) | no-owner | `by-memory/0x00554640-0x00554675.WordRefCountHelpers.md` |  |  |  |
```

Prior B001/B002/B003 reports were read as background only. This report rechecked the current docs and current live IDA MCP evidence before reaching the same no-change recommendation.

## Executive Recommendation

Leave `00023P` as a single reconstructable no-owner/non-emitting helper island.

The item is not padding, not a mixed physical container, and not a known compiler/runtime-only artifact. It contains three source-shaped helper bodies: initialize a first-word count to `1`, increment that first word, and decrement/free the object when the signed word count is no longer positive.

The assignment remains blocked because no caller, data reference, raw pointer, branch target, vtable slot, callback table, local name, source string, PDB/CodeView breadcrumb, or object-file/source route points at any helper start. A narrow utility source family such as `NexusTK/util/WordRefCountHelpers.cpp` or an `IntrusiveWordRefCount` helper/type is the best if-forced hypothesis, but it is still an inference from behavior only. Do not create that owner or route output to it unless future evidence or an explicit project policy clears the owner/emitter gate.

No reconstruction C++ should be entered. The item is `88/92`, so it does not meet the completion half of the active 90/90+ code-entry gate, and the required owner/emitter/source-placement/naming conditions are also unresolved.

## Supervisor Active Recheck

The current supervisor assignment asks B003 to recheck:

- whether `CANONICAL_OWNER:NONE` is still correct;
- whether blank `EMITTER_UIDS` is still correct;
- whether a canonical owner, emitter route, split/merge, reclassification, IDA-safe name repair, or final non-emitting justification is warranted.

No split repair was required before writing this report. The target already covers one cohesive helper island. Splitting `0x00554640`, `0x00554650`, and `0x00554660` into separate child pages would create three tiny no-owner children with the same missing-source-route blocker and would not add evidence.

Every source-bearing subrange in scope is accounted for by this single page. The padding around and inside the island is already covered by the ignored ledger/coverage rows and does not require new child pages.

## Inference Research Guidance Check

`by-structure.md` separates semantic ownership from output routing:

- `CANONICAL_OWNER` must be the narrowest true semantic/source owner supported by evidence.
- `EMITTER_UIDS` controls generated output routing and should not be filled just because ownership is plausible.
- Confirmed NexusTK source can remain `RECONSTRUCTABLE:TRUE` while owner, emitter, source file, and final C++ are unresolved.
- `CANONICAL_OWNER:NONE` with emitters is appropriate for pooled/shared data with proven source-use contexts; this target is unique executable code with no proven consumer.

`inference_research.md` weighs xrefs, callers, table references, initialization paths, and source/debug metadata above address adjacency. For this target, the hard facts are strong, but they are mostly negative for ownership. Adjacency to ReconnectDialog/CopyWindow on the left and Region/Motion on the right is weak evidence and is contradicted by padding, stronger neighboring ownership docs, and the absence of cross-references.

## Evidence Standards Used

Evidence used in this pass:

- Live IDA MCP `idb_list`, `server_health`, `lookup_funcs`, `xrefs_to`, `disasm`, `decompile`, `get_bytes`, `make_signature`, `make_signature_for_range`, `find_bytes`, and `entity_query`.
- Section-aware PE scan of `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe` for exact bytes, duplicate helper patterns, literal VA/RVA dword references, direct executable branch/call targets, and `sub_5C7526` free-wrapper call-site idioms.
- Current target page, generated memory coverage, manual memory coverage row, supervisor/tracker rows, adjacent memory pages, and plausible utility-owner docs.
- Negative evidence for owners/emitters: no calls, no data refs, no raw pointers, no direct branches, no local/source names, no type/source metadata, and incompatible candidate layouts.

## IDA MCP Facts

Current live IDA session:

| Field | Value |
| --- | --- |
| Session | `b001_0003gy` |
| Input path | `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe` |
| IDB path | `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe.i64` |
| Module | `NexusTK.exe` |
| Image base | `0x00400000` |
| Auto-analysis | ready |
| Hex-Rays | ready |
| Strings cache | ready |

### Function / Range Facts

`lookup_funcs` reports:

| Address | Current IDA result |
| --- | --- |
| `0x00554520` | `sub_554520`, size `0x16` |
| `0x00554540` | `sub_554540`, size `0x0b` |
| `0x00554550` | `sub_554550`, size `0x0b` |
| `0x005545f0` | `sub_5545F0`, size `0x45` |
| `0x00554635` | not a function |
| `0x00554640` | `sub_554640`, size `0x0b` |
| `0x0055464b` | not a function |
| `0x00554650` | not a function |
| `0x00554654` | not a function |
| `0x00554660` | not a function |
| `0x00554675` | not a function |
| `0x00554680` | `sub_554680`, size `0x61` |
| `0x005546f0` | `sub_5546F0`, size `0x0d` |
| `0x00554700` | `sub_554700`, size `0x15` |
| `0x00554b00` | `sub_554B00`, size `0x38` |
| `0x005c7526` | `sub_5C7526`, size `0x0e` |
| `0x00456480` | `sub_456480`, size `0xb2` |
| `0x00457480` | `sub_457480`, size `0xc7` |

`entity_query` for functions in `0x00554500-0x00554720` shows the predecessor reconnect cleanup functions, the single modeled target initializer at `0x00554640`, then the following Region/Motion functions at `0x00554680`, `0x005546f0`, `0x00554700`, and `0x00554720`. It does not model `0x00554650` or `0x00554660` as functions.

### Bytes And Behavior

Current bytes from `0x00554635-0x00554680`:

| Range | Bytes / role |
| --- | --- |
| `0x00554635-0x00554640` | eleven `cc` alignment bytes |
| `0x00554640-0x0055464b` | `b8 01 00 00 00 66 89 01 8b c1 c3` |
| `0x0055464b-0x00554650` | five `cc` alignment bytes |
| `0x00554650-0x00554654` | `66 ff 01 c3` |
| `0x00554654-0x00554660` | twelve `cc` alignment bytes |
| `0x00554660-0x00554675` | `66 ff 09 66 83 39 00 7f 0b 6a 02 51 e8 b5 2e 07 00 83 c4 08 c3` |
| `0x00554675-0x00554680` | eleven `cc` alignment bytes |

Current IDA disassembly:

```asm
00554640  mov     eax, 1
00554645  mov     [ecx], ax
00554648  mov     eax, ecx
0055464a  retn
00554650  inc     word ptr [ecx]
00554653  retn
00554660  dec     word ptr [ecx]
00554663  cmp     word ptr [ecx], 0
00554667  jg      short 0x00554674
00554669  push    2
0055466b  push    ecx
0055466c  call    sub_5C7526
00554671  add     esp, 8
00554674  retn
```

IDA decompiles the modeled initializer at `0x00554640` as a `_WORD *__thiscall` function that writes `1` to `*this` and returns `this`.

IDA decompiles `sub_5C7526` as a one-argument wrapper around `j_j___free_base`. The target release helper passes `ecx` as the block pointer and stack-cleans both the block pointer and an extra pushed `2`, matching a deallocation/deleting-helper idiom rather than a normal source call with two meaningful arguments.

### Xref Facts

`xrefs_to` reports:

| Address | Current xrefs |
| --- | --- |
| `0x00554635` | zero |
| `0x00554640` | zero |
| `0x0055464b` | zero |
| `0x00554650` | zero |
| `0x00554654` | zero |
| `0x00554660` | zero |
| `0x00554669` | one internal branch xref from `0x00554667` |
| `0x0055466c` | one internal code xref from `0x0055466b` |
| `0x00554675` | zero |
| `0x00554680` | many code xrefs; query returned 100 and `more:true` |
| `0x005c7526` | broad fan-in; query returned first five xrefs and `more:true` |
| `0x00456480` | zero xrefs |
| `0x00457480` | data xref at `0x006108d4` |

Positive controls are important here:

- `0x00554680`, the following Region constructor, has many code xrefs.
- `0x00457480` has the MiniMapVersionManager vtable data xref at `0x006108d4`.
- `sub_5C7526` has broad fan-in.

Those controls show the query path is finding normal references. The target helper starts remain unreferenced.

### Signature And Byte Search Facts

IDA `make_signature` produced unique signatures:

| Address | Signature | Unique |
| --- | --- | --- |
| `0x00554640` | `B8 01 00 00 00 66 89 01` | yes |
| `0x00554650` | `66 FF 01` | yes |
| `0x00554660` | `66 FF 09 66 83 39 00` | yes |

`make_signature_for_range 0x00554640-0x00554675` produced unique wildcarded and exact range signatures in the current IDB.

IDA `find_bytes` found:

| Pattern | Result |
| --- | --- |
| initializer exact bytes | one hit at `0x00554640` |
| increment exact bytes | one hit at `0x00554650` |
| release exact bytes | one hit at `0x00554660` |
| `push 2; push ecx; call sub_5C7526; add esp,8; retn` tail | one hit at `0x00554669` |
| VA `0x00554640` / RVA `0x00154640` | zero |
| VA `0x00554650` / RVA `0x00154650` | zero |
| VA `0x00554660` / RVA `0x00154660` | zero |
| VA `0x00554675` / RVA `0x00154675` | zero |
| VA `0x00554680` positive control | one hit at `0x00504178` |
| VA `0x00457480` positive control | one hit at `0x006108d4` |

### Name / String Facts

`entity_query` for names in `0x00554600-0x00554700` returned zero names.

`entity_query` for strings matching `refcount`, `referencecount`, `ref count`, `intrusive`, `wordref`, `word ref`, `pdb`, `rsds`, or `nb10` returned zero matches.

IDA string-cache searches do find candidate-owner family names elsewhere, such as `StringBase`, `LObject`, `Region`, `Motion`, `ReconnectDialog`, `CopyWindow`, and `MiniMapVersion`, but no name or string reference connects those families to the helper starts.

### Free-Wrapper Idiom Controls

The two non-target `push 2` / `sub_5C7526` sites are MiniMapVersionManager cleanup/deleting paths:

| Site | Current evidence | Meaning |
| --- | --- | --- |
| `0x004564bb` | in `sub_456480`; vtable store to `MiniMapVersionManager`, loop over `this[19]`, frees `i[3]` | MiniMapVersionManager list payload cleanup |
| `0x004574bb` | in `sub_457480`; same loop plus optional final `sub_5C7526(Block)` deleting path | MiniMapVersionManager scalar deleting destructor |
| `0x0055466c` | target release helper | same deallocation idiom, not an ownership edge |

This makes the `push 2` form a deallocation idiom control, not evidence that `00023P` belongs to MiniMapVersionManager.

## PE / Raw Evidence

Read-only PE scan target:

```text
E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe
```

PE section facts:

| Section | VA range | Role |
| --- | --- | --- |
| `.text` | `0x00401000-0x0060c600` | executable; target is here |
| `.rdata` | `0x0060d000-0x0066c200` | read-only data |
| `.data` | `0x0066d000-0x0069ce24` | writable data |
| `.rsrc` | `0x0069d000-0x006b2e00` | resources |

Exact byte-pattern scan:

| Pattern | Hits |
| --- | --- |
| initializer exact | `0x00554640` only |
| increment exact | `0x00554650` only |
| release exact | `0x00554660` only |
| release free tail | `0x00554669` only |

Literal VA/RVA pointer scan:

| Target | Hits |
| --- | --- |
| `0x00554640` VA/RVA | none |
| `0x00554650` VA/RVA | none |
| `0x00554660` VA/RVA | none |
| `0x00554675` VA/RVA | none |
| `0x00554680` VA positive control | `0x00504178` |
| `0x00457480` VA positive control | `0x006108d4` |

Direct branch/call scan covered executable-section `E8/E9 rel32`, `0F 80-8F rel32`, short conditional branches, short jumps, and loop-style short branches:

| Target | Branch/call hit count |
| --- | ---: |
| `0x00554640` | 0 |
| `0x00554650` | 0 |
| `0x00554660` | 0 |
| `0x00554675` | 0 |
| `0x00554680` positive control | 89 |
| `0x00457480` | 0 |

Free-wrapper scan:

- Direct calls to `0x005c7526`: `617`.
- Calls with `push 2` in the previous 20 bytes: `0x004564bb`, `0x004574bb`, and `0x0055466c`.

## Function / Child Inventory

| Range / Item | UID / Path | Role | Reconstructable | Direct Parent | Score | Status |
| --- | --- | --- | --- | --- | --- | --- |
| `0x00554640-0x00554675` | `00023P` / `by-memory/0x00554640-0x00554675.WordRefCountHelpers.md` | complete init/addref/release word-count helper island | true | `NONE`; blank emitters | `88/92` | keep as-is |
| `0x00554640-0x0055464b` | contained in `00023P` | initializer: first word set to `1`, return `this` | true | unresolved | inherited | no split |
| `0x00554650-0x00554654` | contained in `00023P` | addref: increment first word | true | unresolved | inherited | no split |
| `0x00554660-0x00554675` | contained in `00023P` | release: decrement first word and free object when count is not positive | true | unresolved | inherited | no split |
| `0x00554635-0x00554640` | `by-memory/-ignored.md` | leading alignment padding | false/ignored | none | strong | unchanged |
| `0x0055464b-0x00554650` | `by-memory/-ignored.md` | internal alignment padding | false/ignored | none | strong | unchanged |
| `0x00554654-0x00554660` | `by-memory/-ignored.md` | internal alignment padding | false/ignored | none | strong | unchanged |
| `0x00554675-0x00554680` | `by-memory/-ignored.md` | trailing alignment padding | false/ignored | none | strong | unchanged |

## Direct Xref / Caller Inventory

| Address / Item | Xref / Caller / Callee | Meaning |
| --- | --- | --- |
| `0x00554640` | no IDA xrefs; no VA/RVA pointer hits; no PE branch/call hits | no proven caller, table entry, source-use context, or owner |
| `0x00554650` | no IDA xrefs; no VA/RVA pointer hits; no PE branch/call hits | raw addref helper has no proven use |
| `0x00554660` | no IDA xrefs; no VA/RVA pointer hits; no PE branch/call hits | raw release helper has no proven use |
| `0x0055466c -> 0x005c7526` | outgoing free-wrapper call | dependency only; not owner evidence |
| `0x00554680` | many IDA xrefs and 89 PE direct call hits | successor Region/Motion island is live; does not own target |
| `0x004564bb`, `0x004574bb` | other `push 2` free-wrapper sites | MiniMapVersionManager cleanup/deleting idiom controls; not target owner evidence |

## Documentation Evidence And IDA Status

Existing docs that support the conclusion:

- Target page records the same exact helper/padding layout, current `CANONICAL_OWNER:NONE`, blank emitters, score `88/92`, repeated no-reference evidence, and rejected owner candidates. The current IDA/PE pass reconfirms the material facts.
- `by-memory/-coverage-report.md` currently lists `00023P` as a reconstructable `88% : strong` function cluster with B002 second-pass evidence and rejects existing feature/utility owners.
- `auto-generated/-ag-memory-coverage.md` lists `00023P` as `no-owner`, owner `NONE`, blank emitters, no generated code, and no destination.
- `by-memory/0x00554550-0x00554635.ConnectionReconnectDialogCleanupAndDestructorThunks.md` ends the predecessor cleanup/destructor child at `0x00554635` and documents the following `0xcc` padding before this target.
- `by-memory/0x00554680-0x00554b38.RegionAndMotionRect.md` starts the successor Region/Motion island at `0x00554680` after target trailing padding and has independent Region/Motion constructor/vtable/rectangle evidence.

Existing docs that block candidate owners:

- `StringBase.md` and `RefCountedStringBufferHeader.md` document a 12-byte string-buffer prefix, 32-bit refcounts, interlocked operations, sentinels, and pools. That is incompatible with a 16-bit count at object head and direct `free(this)`.
- `StringUtil.md` is a broader string utility coordinator and routes actual ref-counted string-buffer mechanics through `StringBase`; it has no direct source-use evidence for this helper island.
- `LinkedList.md` owns sentinel-list nodes/state and has a real caller spread; this target has no sentinel/list shape and no refs to the linked-list helpers.
- `PoolAllocator.md` owns fixed-block allocator/pool state; this target calls the free wrapper directly and touches no pool state.
- `LObject.md` owns a one-vptr runtime/base shell; this target has no vtable/runtime-class evidence.
- `MiniMapVersionManager.md` owns the two comparison `push 2` free-wrapper paths; their decompiled behavior is minimap list payload/node cleanup, not a route to this helper island.

## Ranked Ownership Analysis

### 1. Keep `CANONICAL_OWNER:NONE`, blank `EMITTER_UIDS` - accepted

Evidence for:

- No static xrefs to the three helper starts.
- No raw absolute-VA or RVA pointer hits.
- No direct branch/call targets to the helper starts.
- No vtable/table/callback slot evidence.
- No local names or source/debug strings.
- Existing candidate owners either stop before/after padding or have incompatible layouts.
- Current owner/emitter rules explicitly allow `RECONSTRUCTABLE:TRUE` unresolved items to remain no-owner/non-emitting while research continues.

Evidence against:

- The three helper bodies look deliberate and source-authored.
- If the code is not retained dead code, the original project likely had a narrow helper/type declaration for it.

Decision: accept. This is the only current state that preserves the source-authored evidence without inventing a route.

### 2. New narrow `NexusTK/util/WordRefCountHelpers.cpp` or `IntrusiveWordRefCount` owner - best if forced, below gate

Evidence for:

- The range forms a complete small init/addref/release family.
- The behavior is generic lifetime management.
- The proposed source tree already has `NexusTK/util/` for utility/container/lifetime support.
- No existing owner is stronger.

Evidence against:

- No caller, data reference, pointer table, recovered type, source-facing name, PDB/CodeView string, linker map, object-file boundary, or source-path breadcrumb proves this owner.
- A new owner file would currently contain only this no-xref helper island.
- Creating a by-file root solely to reduce no-owner counts would violate the owner/emitter guidance.

Decision: keep as future hypothesis only. Do not create a by-file owner and do not add emitters.

Likely contents if future evidence supports this owner:

- one narrow intrusive word-reference-count helper/type declaration;
- initializer equivalent to first-word count initialization;
- addref equivalent to first-word increment;
- release equivalent to first-word decrement and deletion/free on nonpositive count;
- no automatic inclusion of adjacent reconnect/Region/String/List/Pool/LObject/MiniMap items.

### 3. `StringBase` / `StringUtil` - rejected

Evidence for:

- Abstract refcount and utility placement theme.
- Both live under `NexusTK/util/`.

Evidence against:

- StringBase uses a 12-byte header before the character data pointer.
- StringBase refcounts are 32-bit and interlocked.
- StringBase release uses sentinels and pool/heap selection.
- This target uses a 16-bit word at `this`, no sentinel, no string data pointer, no capacity/length header, and direct free of `this`.
- No StringBase or StringUtil source-use path references the helper starts.

Decision: reject canonical ownership and emitter routing.

### 4. ReconnectDialog / ConnectionClosedDialog / CopyWindow - rejected

Evidence for:

- The target physically follows reconnect/copy-window cleanup/destructor code.

Evidence against:

- Predecessor exact child ends at `0x00554635`.
- `0x00554635-0x00554640` is alignment padding.
- Reconnect/ConnectionClosed/CopyWindow vtables, singleton globals, methods, and read-only data do not reference any helper start.
- The predecessor behavior is dialog singleton/vtable/destructor cleanup, not word-counted heap-object lifetime.

Decision: reject. This is adjacency-only evidence.

### 5. Region / Motion - rejected

Evidence for:

- The target physically precedes the heavily referenced Region/Motion island.
- Region/Motion are utility-like UI-core helpers.

Evidence against:

- `0x00554675-0x00554680` is alignment padding.
- `0x00554680` has many code refs and one VA pointer positive-control hit, while target helper starts have none.
- Region/Motion docs describe an `LObject` vptr plus rectangle fields, not first-word reference-count state.
- No Region/Motion vtable, constructor, destructor, or field path touches this island.

Decision: reject.

### 6. LinkedList / PoolAllocator / LObject / MiniMapVersionManager / CRT - rejected

Evidence for:

- These are utility or lifetime-adjacent systems.
- MiniMapVersionManager has the two non-target `push 2` free-wrapper sites.
- The release helper calls the same free wrapper used broadly across the binary.

Evidence against:

- LinkedList is sentinel-node/list-state code.
- PoolAllocator is fixed-block pool/chunk/free-list state.
- LObject is a vptr/runtime-class base shell.
- MiniMapVersionManager comparison sites free minimap list payloads/nodes and do not reference the target.
- `sub_5C7526` has 617 direct calls in the PE scan; a shared free-wrapper dependency cannot own every caller-specific lifetime helper.

Decision: reject all as owners and emitters.

### 7. Reclassify as compiler/runtime-only - rejected

Evidence for:

- The island is statically unreferenced and eventually calls a free wrapper.

Evidence against:

- The three-operation init/addref/release protocol is source-shaped and project-specific enough to retain.
- The byte patterns are unique.
- IDA does not identify the island as CRT/library code.
- Only the terminal deallocation callee is runtime-like.

Decision: keep `RECONSTRUCTABLE:TRUE`.

## Negative Evidence Summary

Checked and rejected:

- IDA xrefs to `0x00554640`, `0x00554650`, and `0x00554660`.
- IDA function objects at `0x00554650` and `0x00554660`.
- Raw VA and RVA dword pointers to all helper starts.
- Direct executable-section branch/call targets to all helper starts.
- Duplicate helper byte patterns.
- Local names in `0x00554600-0x00554700`.
- `refcount`, `referencecount`, `intrusive`, `wordref`, PDB, RSDS, and NB10 string evidence.
- Reconnect/CopyWindow ownership across leading padding.
- Region/Motion ownership across trailing padding.
- StringBase/StringUtil thematic refcount routing.
- LinkedList, PoolAllocator, LObject, MiniMapVersionManager, and CRT/free-wrapper routing.

Consumer/read xrefs are not merely weak here; they are absent for the target starts. Address adjacency is the only positive signal for neighboring feature owners, and padding plus stronger neighboring ownership docs make it insufficient.

## Final Recommendation

Exact changes applied or recommended:

- No `by-memory` target edit.
- No `auto-generated/-ag-memory-coverage.md` edit.
- No direct `by-memory/-coverage-report.md` edit.
- No score change.
- No `CANONICAL_OWNER` assignment.
- No `EMITTER_UIDS` assignment.
- No `EMITTER_POSITION_OPTIONAL` value.
- No reconstruction C++.
- No split, merge, rename, reclassification, or IDA repair.

Target header should remain:

```text
UID:00023P
COMPLETION:88
CONFIDENCE:92
CANONICAL_OWNER:NONE
RECONSTRUCTABLE:TRUE
EMITTER_UIDS:
EMITTER_POSITION_OPTIONAL:
```

No replacement manual coverage row is required. The current row is materially correct. If the supervisor wants the shared row to cite this B003 current pass, use this exact replacement at the existing `0x00554640-0x00554675` placement:

```text
    - [UID:00023P][0x00554640-0x00554675.WordRefCountHelpers](by-memory/0x00554640-0x00554675.WordRefCountHelpers.md) 0x00554640-0x00554675 | function cluster | WordRefCountHelpers : reconstructable : 88% : strong : B003 current Goal 2 pass reconfirms a coherent, unique three-helper 16-bit intrusive word refcount island with modeled initializer `0x00554640-0x0055464b`, raw increment helper `0x00554650-0x00554654`, raw release/free helper `0x00554660-0x00554675`, exact surrounding/internal `0xcc` padding, decompiled `_WORD` initializer, zero xrefs to all three helper starts, only internal branch/callee refs inside the release helper, zero absolute-VA/RVA pointer hits, zero PE-level direct branch/call targets to the helper starts, unique exact helper byte patterns and exact/wildcarded full-range signatures, no local names in `0x00554600-0x00554700`, no `refcount`/`intrusive`/PDB metadata strings, and PE free-wrapper controls showing `push 2` before `sub_5C7526` only at MiniMapVersionManager cleanup/destructor sites plus this release helper. Existing ReconnectDialog/CopyWindow/Region/Motion/StringBase/StringUtil/LinkedList/PoolAllocator/LObject/MiniMapVersionManager/CRT owners are rejected; a narrow `util/WordRefCountHelpers` or `IntrusiveWordRefCount` source-family remains the best-if-forced hypothesis but does not clear owner/emitter assignment without caller, table, type, source, or object-file evidence.
```

## Follow-Up Actions

Supervisor actions:

- Accept this B003 current Goal 2 pass as no metadata change.
- Optionally replace the manual coverage row with the B003 wording above; this is not required for correctness.
- Do not add emitters for existing utility or adjacent feature owners under current evidence.

A-agent actions:

- Leave final C++ blank.
- Do not route this helper during routine no-owner cleanup unless new caller/source-use evidence appears.

B003 future research actions:

- Revisit only if another target uncovers a matching first-word 16-bit intrusive refcount type, hidden dispatch/reference table, PDB/source/debug breadcrumb, or explicit project policy for unique no-xref retained helper islands.

## Confidence

- Recommendation confidence: `91/100`.
- Range/byte confidence: `96/100`.
- No-reference confidence: `95/100`.
- Existing-owner rejection confidence: `90/100`.
- Best-if-forced narrow utility owner hypothesis: `72/100`, below assignment threshold.
- Remaining uncertainty: original source filename, source-facing API/type names, whether these helpers were retained dead code, and whether a runtime-only indirect mechanism ever reached them.

## Validator Results

- Commands run: none.
- Reason: no `by-*`, generated, project-level, or shared coverage files were edited. This pass created only an Agent-B003 research report, so no validator `--apply` operation was needed.
- Dry runs used: none.
- Unresolved validator warnings/errors from this pass: none.

## Changed Files

- Created: `tools/leaser/Agents/Agent-B003/research/00023P-WordRefCountHelpers-current-goal2-pass.md`
- Modified: none.
- Renamed: none.
- Direct `by-memory/-coverage-report.md` edits: none.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B003","command_id":"000000004165","destination_path":"executed-b-agent-research/B003/00023P-WordRefCountHelpers-current-goal2-pass.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:27","uid":"00023P"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
