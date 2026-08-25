** TARGET-REPORT-UID:00023P **
** AUTHOR-AGENT-ID:B001 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# 00023P WordRefCountHelpers Ownership / Split Research

Revision: Agent-B001 current Goal 2 no-owner memory pass, 2026-06-13 21:56 -04:00

## Finalized Report / Current Recommendation

- Target UID/path: [UID:00023P] `by-memory/0x00554640-0x00554675.WordRefCountHelpers.md`.
- Current metadata should remain unchanged: `COMPLETION:88`, `CONFIDENCE:92`, `CANONICAL_OWNER:NONE`, `RECONSTRUCTABLE:TRUE`, blank `EMITTER_UIDS`, blank `EMITTER_POSITION_OPTIONAL`, and blank reconstruction C++.
- Best current disposition: keep this as a reconstructable but ownerless/non-emitting helper island. The byte and IDA evidence show real source-required lifetime helper code, but no current owner, caller, pointer table, source-use context, or type metadata proves a canonical owner or emitter route.
- Best if-forced source-family hypothesis: a narrow utility helper such as `NexusTK/util/WordRefCountHelpers.cpp` or an `IntrusiveWordRefCount` private helper family. This is still only a placement inference from the three-helper behavior, not a defensible by-structure owner assignment.
- Existing owners rejected: ReconnectDialog/ConnectionClosedDialog, CopyWindow, Region, Motion, StringBase, StringUtil, LinkedList, PoolAllocator, LObject, MiniMapVersionManager, and CRT/runtime.
- Split/merge/reclassify decision: no split, no merge, no rename, no reclassification, no score change, no coverage-report replacement. Keep the single memory page as the smallest useful coherent family: initializer, addref, release/free, and internal padding.
- Code gate: no C++ should be entered. The page is `88/92`, but it lacks a proven owner/emitter route and final source/API shape, so it does not satisfy the current `90/90+` source-output gate.

## Target

- Target page: `E:\NTK\GhidraBridge\source-3\project-documentation\by-memory\0x00554640-0x00554675.WordRefCountHelpers.md`
- Current target metadata:

```text
*** UID:00023P ***
*** COMPLETION:88 ***
*** CONFIDENCE:92 ***
*** CANONICAL_OWNER:NONE ***
*** RECONSTRUCTABLE:TRUE ***
*** EMITTER_UIDS: ***
*** EMITTER_POSITION_OPTIONAL: ***
```

- Current generated autogen rows still show no owner and blank emission:

```text
auto-generated/-ag-memory-coverage.md:2747:
| [UID:00023P][0x00554640-0x00554675.WordRefCountHelpers](by-memory/0x00554640-0x00554675.WordRefCountHelpers.md) | no-owner | `NONE` |  |  | no |  | `by-memory/0x00554640-0x00554675.WordRefCountHelpers.md` |  |

auto-generated/-ag-memory-coverage.md:3496:
| [UID:00023P][0x00554640-0x00554675.WordRefCountHelpers](by-memory/0x00554640-0x00554675.WordRefCountHelpers.md) | no-owner | `by-memory/0x00554640-0x00554675.WordRefCountHelpers.md` |  |  |  |
```

## Executive Recommendation

Leave [UID:00023P] `CANONICAL_OWNER:NONE` with blank `EMITTER_UIDS`.

This is a last-resort no-owner recommendation after ranking the plausible owner outcomes. The binary facts are unusually strong: the helper island is byte-unique, has stable boundaries, has no xrefs or pointer-table references to its three helper starts, and has no source-facing names or strings. The ownership facts are weak: there is no caller, data ref, vtable slot, indirect-call table, owning type, source path, PDB/linker-map clue, or direct source-use context.

The only positive source-layout inference is behavioral: `0x00554640`, `0x00554650`, and `0x00554660` form a compact init/addref/release helper family over a 16-bit object-head counter. That supports reconstructable helper code, but it does not prove which existing file or new file should own or emit it.

The exact condition that would change this decision is discovery of at least one of the following: a caller or pointer table to any helper start, a hidden dispatch table or object layout using the first word as this counter, a PDB/linker/source artifact, a reliable object-file neighborhood map, or multiple independent source-use contexts proving emitter UIDs.

## Supervisor Active Recheck

This pass read the current target page, current generated coverage rows, current manual by-memory coverage row, current padding ledger, relevant neighboring/candidate owner docs, and prior B001/B002 reports as background only. The prior reports were not treated as final authority.

Live IDA MCP was re-run against database `b001_0003gy` for `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`. `server_health` reported:

```text
status: ok
idb_path: E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe.i64
module: NexusTK.exe
input_path: E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe
imagebase: 0x400000
auto_analysis_ready: true
hexrays_ready: true
strings_cache_ready: true
strings_cache_size: 2067
```

An independent read-only PE scan was also run against `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`, MD5 `4247e04e20b65d6414c7238aa8ff5515`.

## Evidence Standards Used

- IDA MCP facts are treated as ground truth for function starts, function sizes, bytes, disassembly, decompilation, direct xrefs, names, and strings.
- The independent PE scan is used as byte-level control evidence for exact patterns, VA/RVA dword references, relative branches, and free-wrapper idiom sites.
- Existing documentation is used as lead evidence only. Every important owner decision below is checked against IDA and PE facts where possible.
- Consumer xrefs are not ownership proof. In this target there are no consumer xrefs to weigh, which blocks both canonical ownership and emitter assignment.
- No wave2/wave3 source data was used. No dry runs were used.

## IDA MCP Facts

### Function and boundary facts

`lookup_funcs` returned:

| Query | IDA result |
| --- | --- |
| `0x005545f0` | `sub_5545F0`, size `0x45`; previous modeled function ends at `0x00554635` |
| `0x00554635` | not a function |
| `0x00554640` | `sub_554640`, size `0x0b` |
| `0x0055464b` | not a function |
| `0x00554650` | not a function |
| `0x00554654` | not a function |
| `0x00554660` | not a function |
| `0x00554675` | not a function |
| `0x00554680` | `sub_554680`, size `0x61`; next modeled Region constructor |
| `0x00554b00` | `sub_554B00`, size `0x38`; Region scalar deleting destructor |
| `0x005c7526` | `sub_5C7526`, size `0x0e`; free wrapper |
| `0x00456480` | `sub_456480`, size `0xb2`; MiniMapVersionManager cleanup negative control |
| `0x00457480` | `sub_457480`, size `0xc7`; MiniMapVersionManager deleting destructor negative control |

The current IDA function inventory in `0x00554500-0x00554720` contains reconnect/copy cleanup functions up through `sub_5545F0`, the target's single modeled helper at `0x00554640`, then Region/Motion functions starting at `0x00554680`, `0x005546f0`, `0x00554700`, and `0x00554720`. `entity_query` found no names in `0x00554600-0x00554700`.

### Bytes and raw disassembly facts

`get_bytes` for `0x00554635-0x00554680` returned:

```text
0x00554635: cc cc cc cc cc cc cc cc cc cc cc
0x00554640: b8 01 00 00 00 66 89 01 8b c1 c3
0x0055464b: cc cc cc cc cc
0x00554650: 66 ff 01 c3
0x00554654: cc cc cc cc cc cc cc cc cc cc cc cc
0x00554660: 66 ff 09 66 83 39 00 7f 0b 6a 02 51 e8 b5 2e 07 00 83 c4 08 c3
0x00554675: cc cc cc cc cc cc cc cc cc cc cc
```

`insn_query` over `0x00554635-0x00554680` decoded:

```asm
0x00554635  align 10h
0x00554640  mov eax, 1
0x00554645  mov [ecx], ax
0x00554648  mov eax, ecx
0x0055464a  retn
0x0055464b  align 10h
0x00554650  inc word ptr [ecx]
0x00554653  retn
0x00554654  align 10h
0x00554660  dec word ptr [ecx]
0x00554663  cmp word ptr [ecx], 0
0x00554667  jg short locret_554674
0x00554669  push 2
0x0055466b  push ecx
0x0055466c  call sub_5C7526
0x00554671  add esp, 8
0x00554674  retn
0x00554675  align 10h
```

IDA decompiles the only modeled function as:

```c
_WORD *__thiscall sub_554640(_WORD *this)
{
  *this = 1;
  return this;
}
```

IDA decompiles `sub_5C7526` as:

```c
void __cdecl sub_5C7526(void *Block)
{
  j_j___free_base(Block);
}
```

The raw release helper is therefore an unmodeled decrement/release/free helper that passes `ecx` to the free wrapper and caller-cleans the extra pushed constant.

### Xref facts

`xrefs_to` and `xref_query` returned zero xrefs to every target helper/padding boundary checked inside the island:

| Address | Current xrefs |
| --- | ---: |
| `0x00554640` | `0` |
| `0x0055464b` | `0` |
| `0x00554650` | `0` |
| `0x00554654` | `0` |
| `0x00554660` | `0` |
| `0x00554675` | `0` |

Positive control: `xref_query` to `0x00554680` returned total `90`, and the PE branch scan found `89` relative code branches/calls plus one VA dword pointer to `0x00554680`. This shows the reference search is capable of finding the next Region constructor while finding none for the target helper starts.

`find_xref_signatures` returned empty signature sets and `total_xrefs:0` for `0x00554640`, `0x00554650`, and `0x00554660`.

### Callee and comparison facts

`callees 0x00554640` returned no callees. The raw release bytes call `0x005c7526`; `callees 0x005c7526` returns `j_j___free_base`.

IDA decompilation of `0x00456480` and `0x00457480` shows the other `push 2` free-wrapper negative controls are MiniMapVersionManager cleanup/destructor paths. Both walk MiniMapVersionManager list nodes, call `sub_5C7526(i[3])` on payload strings, free nodes, call cleanup helpers, and clear `dword_67A7DC`. This makes the `push 2` form an allocator/deleting-destructor/free idiom, not a MiniMap owner signal for [UID:00023P].

### Signature and name facts

`find_bytes` and `make_signature` found unique helper signatures:

| Range/start | Signature/pattern | Hits |
| --- | --- | ---: |
| `0x00554640` | `B8 01 00 00 00 66 89 01 8B C1 C3` | `1` |
| `0x00554650` | `66 FF 01 C3` | `1` |
| `0x00554660` | `66 FF 09 66 83 39 00 7F 0B 6A 02 51 E8 B5 2E 07 00 83 C4 08 C3` | `1` |
| `0x00554669` | `6A 02 51 E8 B5 2E 07 00 83 C4 08 C3` | `1` |
| `0x00554640` | shortest unique IDA signature `B8 01 00 00 00 66 89 01` | unique |
| `0x00554650` | shortest unique IDA signature `66 FF 01` | unique |
| `0x00554660` | shortest unique IDA signature `66 FF 09 66 83 39 00` | unique |
| full range `0x00554640-0x00554675` | full-range IDA signature including padding-free helper bodies | unique |

`find_regex '(?i)(refcount|referencecount|wordref|word ref|intrusive|rsds|nb10|pdb)'` returned zero string matches in the current IDB strings cache. No local symbol/name evidence ties this target to a source type or source file.

## Independent PE Scan Facts

The independent scanner parsed these executable sections:

| Section | VA | Raw | Raw size |
| --- | --- | --- | --- |
| `.text` | `0x00401000` | `0x400` | `0x20b600` |
| `.rdata` | `0x0060d000` | `0x20ba00` | `0x5f200` |
| `.data` | `0x0066d000` | `0x26ac00` | `0xd800` |
| `.rsrc` | `0x0069d000` | `0x278400` | `0x15e00` |

Pattern results:

| Pattern | Count | Hit |
| --- | ---: | --- |
| initializer full bytes | `1` | `0x00554640` |
| increment full bytes | `1` | `0x00554650` |
| release full bytes | `1` | `0x00554660` |
| short initializer signature | `1` | `0x00554640` |
| short increment signature | `1` | `0x00554650` |
| short release signature | `1` | `0x00554660` |

Pointer and branch scan results:

| Target | VA dword hits | RVA dword hits | relative branch/call hits |
| --- | ---: | ---: | ---: |
| `0x00554640` | `0` | `0` | `0` |
| `0x00554650` | `0` | `0` | `0` |
| `0x00554660` | `0` | `0` | `0` |
| `0x00554675` | `0` | `0` | `0` |
| `0x00554680` | `1` at `0x00504178` | `0` | `89` |

Direct calls to `0x005c7526` across `.text`: `617`. Only three such call sites have a preceding `push 2` in the same local call setup:

| Call | Preceding `push 2` | Context |
| --- | --- | --- |
| `0x004564bb` | `0x004564b6` | MiniMapVersionManager cleanup |
| `0x004574bb` | `0x004574b6` | MiniMapVersionManager deleting destructor |
| `0x0055466c` | `0x00554669` | target release/free helper |

The PE scan independently confirms the central blocker: there is no raw direct-reference evidence to any helper start.

## Function / Child Inventory

| Range / Item | UID / Path | Role | Reconstructable | Direct Parent | Score | Status |
| --- | --- | --- | --- | --- | --- | --- |
| `0x00554640-0x0055464b` | [UID:00023P] target subrange | modeled initializer, writes `word [this]=1` and returns `this` | yes | none proven | `88/92` page | keep in target |
| `0x0055464b-0x00554650` | [UID:0000VN] `by-memory/-ignored.md` padding ledger | five `0xcc` alignment bytes | no source code | none | ledger | keep internal padding |
| `0x00554650-0x00554654` | [UID:00023P] target subrange | raw addref helper, `inc word ptr [ecx]; retn` | yes | none proven | `88/92` page | keep in target |
| `0x00554654-0x00554660` | [UID:0000VN] `by-memory/-ignored.md` padding ledger | twelve `0xcc` alignment bytes | no source code | none | ledger | keep internal padding |
| `0x00554660-0x00554675` | [UID:00023P] target subrange | raw release/free helper, `dec`, signed `>0` test, otherwise free `this` | yes | none proven | `88/92` page | keep in target |
| `0x00554635-0x00554640` | [UID:0000VN] `by-memory/-ignored.md` padding ledger | leading alignment from reconnect cleanup tail | no source code | none | ledger | do not merge with predecessor |
| `0x00554675-0x00554680` | [UID:0000VN] `by-memory/-ignored.md` padding ledger | trailing alignment before Region constructor | no source code | none | ledger | do not merge with successor |

Splitting the three helper bodies into separate memory pages would not improve ownership. They form one coherent retained helper family, and all three share the same no-xref/no-owner blocker.

## Direct Xref / Caller Inventory

There are no direct callers, data refs, pointer dwords, RVA dwords, relative branches, xref signatures, or source-use contexts for `0x00554640`, `0x00554650`, or `0x00554660`.

The absence is not due to a broken search: `0x00554680` immediately after the target has 90 IDA xrefs and 89 relative branch/call hits in the PE scan, plus one VA pointer dword at `0x00504178`.

## Documentation Evidence

- Current target page already documents exact bytes, raw-helper status, zero xrefs, unique signatures, and rejected owners. This pass reconfirmed those claims with live IDA MCP and an independent PE scan.
- `auto-generated/-ag-memory-coverage.md` still reports [UID:00023P] as reconstructable `no-owner` with blank emission.
- `by-memory/-coverage-report.md` line 12 records the manual state: [UID:00023P] clears 85% but remains `CANONICAL_OWNER:NONE` with blank `EMITTER_UIDS` because no direct owner or source-use emitter route is proven.
- `by-memory/-ignored.md` records `0x00554635-0x00554640`, `0x0055464b-0x00554650`, `0x00554654-0x00554660`, and `0x00554675-0x00554680` as compiler/linker alignment bytes around and inside this island.
- [UID:0001FT] `0x00553c10-0x00554635.ConnectionClosedReconnectDialogs` ends before the target and is a mixed non-emitting map whose exact reconnect/copy children carry their own ownership.
- [UID:0001FW] `0x00554680-0x00554b38.RegionAndMotionRect` starts after target trailing padding and has independent Region/Motion rectangle behavior, Region vtable evidence, and broad UI/render caller fanout.
- [UID:0000OA] `StringBase` and [UID:0001VQ] `RefCountedStringBufferHeader` document the real string refcount layout as a 12-byte header before the data pointer, 32-bit `InterlockedIncrement`/`InterlockedDecrement`, sentinel pointers, and fixed string-buffer pools. That contradicts direct StringBase ownership for this 16-bit object-head counter.
- [UID:0000KR] `LinkedList` owns sentinel-based 16-byte linked-list node helpers; [UID:0000MM] `PoolAllocator` owns fixed-block pool mechanics; [UID:0000KV] `LObject` owns the vtable/runtime shell. None match this no-vtable 16-bit refcount/free island.
- [UID:0000LF] `MiniMapVersionManager` is useful only as a negative control for the `push 2` free-wrapper idiom, not an owner. Its current docs and decompilation tie the other two `push 2` sites to MiniMap list cleanup.

## Ranked Ownership Analysis

### 1. New narrow `util/WordRefCountHelpers` / `IntrusiveWordRefCount`

Recommendation rank: best if forced, but still not assignable.

Evidence for:

- The three bodies form a complete tiny lifetime helper family: initialize to one, increment, decrement and free.
- The object state is simple and source-like: first word is the counter, helper uses `this` in `ecx`, and release frees the object when the signed counter is no longer positive.
- The helper byte patterns are unique, so this does not appear to be a broad compiler-generated thunk template repeated throughout the binary.
- No existing feature owner has positive references, making a narrow utility helper more plausible than forcing ownership by physical adjacency.
- `by-project-structure/proposed-source-tree.md` already has a broad `NexusTK/util/` area for small shared helpers and container/string infrastructure.

Evidence against assignment:

- No caller, direct branch, data ref, pointer-table slot, xref signature, source string, type name, or object-file boundary links this island to a source file.
- Creating a by-file owner from this evidence would create a one-item orphan source root based only on behavior. The by-structure owner gate requires the correct direct owner, not merely a plausible route.
- There are no source-use contexts, so even a no-canonical-owner multi-emitter model is unsupported.

Conclusion: record this as the best future owner if new evidence appears, but do not create or assign it now.

### 2. ReconnectDialog / ConnectionClosedDialog / CopyWindow adjacency

Recommendation rank: rejected.

Evidence for:

- The target physically follows [UID:00038K] `0x00554550-0x00554635.ConnectionReconnectDialogCleanupAndDestructorThunks`.
- The broader address neighborhood before the target contains reconnect, connection-closed, and CopyWindow code.

Evidence against:

- IDA and the padding ledger show `0x00554635-0x00554640` is eleven `0xcc` bytes before the target.
- No xref links reconnect, connection-closed, CopyWindow, singleton globals, vtables, RTTI, or callbacks to any of the helper starts.
- The predecessor functions are destructor/cleanup wrappers over dialog singletons and vtables; the target has no vtable, singleton clear, callback, alert, packet, or text-edit behavior.
- [UID:0001FT] is intentionally a non-emitting mixed map; exact children carry source ownership. Merging this unrelated no-xref island back into it would make the mixed map less accurate.

Conclusion: physical adjacency alone is not enough. Reject.

### 3. Region / Motion adjacency

Recommendation rank: rejected.

Evidence for:

- The next modeled function begins at `0x00554680`, only after eleven trailing padding bytes.

Evidence against:

- The target is separated from `Region::Region` by `0x00554675-0x00554680` padding.
- `0x00554680` has strong positive Region evidence: 90 IDA xrefs, 89 PE branch hits, one VA pointer, `LObject` construction, Region vtable store, and rectangle clear behavior.
- The target has none of that evidence. It has no Region vtable, no `LObject` construction/destruction, no rectangle fields, and no Region/Motion callers.
- [UID:0000N3] `Region` explicitly owns the `0x00554680-0x00554b38` Region/dirty-rectangle island and excludes unrelated Motion/source pollution.

Conclusion: reject Region/Motion ownership and do not merge the target into [UID:0001FW].

### 4. StringBase / StringUtil

Recommendation rank: rejected despite abstract refcount theme.

Evidence for:

- The target is a refcount-like helper, and [UID:0000OA] `StringBase` / [UID:0000OB] `StringUtil` own important client string refcount infrastructure elsewhere.

Evidence against:

- `StringBase` uses a 12-byte header before the data pointer: `refCount`, `length`, and `capacity`.
- String refcounts are 32-bit and use `InterlockedIncrement`/`InterlockedDecrement`; the target uses a 16-bit word at object offset zero with simple `inc`/`dec`.
- String release checks sentinel pointers and returns storage to fixed pool globals or heap; the target directly frees `this`.
- IDA string/name searches found no `StringBase`, `mystr`, `refcount`, `word ref`, or other metadata tied to this island.
- There are zero refs between known string helpers and the target starts.

Conclusion: reject as a direct owner and emitter.

### 5. LinkedList / PoolAllocator / LObject

Recommendation rank: rejected.

Evidence for:

- These are nearby conceptual utility candidates: lifetime, list, allocation, and base object helpers.

Evidence against:

- [UID:0000KR] `LinkedList` manages sentinel doubly-linked list nodes and has known helpers at `0x004570e0`, `0x00457430`, and `0x00457550`; its node/state layout is not a 16-bit object-head counter.
- [UID:0000MM] `PoolAllocator` manages fixed-size pool chunks/free lists under a critical section; the target only increments/decrements a word and calls a free wrapper.
- [UID:0000KV] `LObject` is a one-vptr runtime/base shell with vtable/runtime-class data; the target has no vtable, no runtime class, and no `LObject` xrefs.

Conclusion: reject.

### 6. MiniMapVersionManager

Recommendation rank: rejected, negative-control only.

Evidence for:

- The only other `push 2` before `sub_5C7526` call sites are in MiniMapVersionManager cleanup/destructor functions.

Evidence against:

- IDA decompilation shows those sites free MiniMapVersionManager list-node payload strings and list nodes during class teardown.
- They do not call or reference `0x00554640`, `0x00554650`, or `0x00554660`.
- Sharing a free-wrapper call idiom is not source ownership.

Conclusion: reject.

### 7. CRT/runtime/compiler-generated

Recommendation rank: rejected as final classification, retained as caveat.

Evidence for:

- The raw starts are not modeled as functions except the initializer.
- Release calls a CRT free wrapper and pushes an extra constant that decompilation ignores.

Evidence against:

- The three helper bodies are custom executable lifetime behavior, not padding, import glue, security-cookie support, EH/RTTI, or an obvious CRT library function.
- The exact byte family is unique, not a repeated compiler helper template.
- The initializer/addref/release pattern is source-required if any object/type uses it.

Conclusion: keep `RECONSTRUCTABLE:TRUE`; do not reclassify as ignored/runtime/compiler-generated.

## Proposed New Owner Contents If Future Evidence Appears

If a caller/table/source artifact later proves a real utility owner, the likely narrow contents would be:

| Candidate item | Include? | Reason |
| --- | --- | --- |
| [UID:00023P] `0x00554640-0x00554675.WordRefCountHelpers` | yes | init/addref/release family over a 16-bit object-head counter |
| internal padding `0x0055464b-0x00554650` and `0x00554654-0x00554660` | no source code, document as alignment only | compiler/linker alignment inside the helper island |
| predecessor reconnect/copy cleanup `0x00554550-0x00554635` | no | dialog singleton/vtable cleanup, separate source family |
| successor Region/Motion rect island `0x00554680-0x00554b38` | no | Region/dirty-rectangle helper family with strong independent owner |
| StringBase/string-buffer helpers | no | incompatible 12-byte header and 32-bit interlocked counters |
| LinkedList/PoolAllocator helpers | no | different list/pool layouts and different caller evidence |

This would be a standalone/narrow utility owner, not a broad refcount subsystem, unless future evidence finds additional functions or data using the same object layout.

## Split / Merge / Reclassification Decision

- No split: the modeled initializer and two raw helper bodies are one cohesive helper family and share one ownership blocker.
- No merge with predecessor: the reconnect/copy cleanup range ends at `0x00554635`, then padding separates it from the target.
- No merge with successor: Region begins at `0x00554680`, then has strong positive Region evidence that the target lacks.
- No reclassification to ignored/runtime: the bytes are executable source-required lifetime logic, not padding or pure CRT/compiler artifact.
- No new by-file page: a one-target utility file based only on no-xref byte behavior would overstate direct owner evidence.
- No emitter assignment: no source-use contexts exist, so this is not a pooled-constant multi-emitter case.

## Shared Report / Coverage Text

No coverage-report replacement is needed. The current manual `by-memory/-coverage-report.md` row is still accurate and should be retained. If the supervisor wants to restamp the retained row, the exact text should be:

```text
    - [UID:00023P][0x00554640-0x00554675.WordRefCountHelpers](by-memory/0x00554640-0x00554675.WordRefCountHelpers.md) 0x00554640-0x00554675 | function cluster | WordRefCountHelpers : reconstructable : 88% : strong : B002 second-pass live IDA and independent PE scans reconfirm a coherent, unique three-helper 16-bit intrusive refcount island with modeled initializer `0x00554640-0x0055464b`, raw increment helper `0x00554650-0x00554654`, raw release/free helper `0x00554660-0x00554675`, exact surrounding/internal `0xcc` padding, decompiled `_WORD` initializer, zero xrefs/xref signatures to all three helper starts, zero absolute-VA/RVA/relative-branch references, unique exact and wildcarded full-range signatures, unique per-helper byte patterns, no local names in `0x00554600-0x00554700`, no `refcount`/`intrusive`/PDB metadata strings, and negative controls showing the `push 2` free-wrapper idiom also appears only in MiniMapVersionManager cleanup/destructor paths plus this island. Existing ReconnectDialog/CopyWindow/Region/Motion/StringBase/StringUtil/LinkedList/PoolAllocator/LObject/MiniMapVersionManager/CRT owners are rejected; a narrow `util/WordRefCountHelpers` or `IntrusiveWordRefCount` source-family remains the best-if-forced hypothesis but does not clear owner/emitter assignment without caller, table, type, source, or object-file evidence.
```

Autogen row replacement is also not needed. The current no-owner rows accurately reflect the metadata:

```text
| [UID:00023P][0x00554640-0x00554675.WordRefCountHelpers](by-memory/0x00554640-0x00554675.WordRefCountHelpers.md) | no-owner | `NONE` |  |  | no |  | `by-memory/0x00554640-0x00554675.WordRefCountHelpers.md` |  |

| [UID:00023P][0x00554640-0x00554675.WordRefCountHelpers](by-memory/0x00554640-0x00554675.WordRefCountHelpers.md) | no-owner | `by-memory/0x00554640-0x00554675.WordRefCountHelpers.md` |  |  |  |
```

## Applied Changes And Validation

- By-* docs edited: none.
- Generated docs edited: none.
- `by-memory/-coverage-report.md` edited: no, per supervisor instruction.
- Leases acquired: none required, because no leased-scope documentation was edited.
- Validator run: not run. There were no by-* documentation changes to validate, and the user explicitly prohibited dry runs.
- Research report created: `tools/leaser/Agents/Agent-B001/research/00023P-WordRefCountHelpers-current-goal2-pass.md`.

## Follow-Up Actions

- Keep [UID:00023P] in the Goal 2 no-owner list unless the supervisor considers the current no-owner/non-emitting state fully accepted for this pass.
- Do not create `WordRefCountHelpers.cpp` yet. Create or assign such an owner only if new evidence proves the helper island's direct source owner or at least one source-use/emitter context.
- Future agents should focus on hidden indirect evidence if this remains important: table scans beyond simple dword VAs/RVAs, object-layout consumers with a 16-bit first-field counter, linker/PDB/map artifacts, or adjacent object-file grouping evidence.
- Do not add reconstruction C++ until owner/emitter route, source names, and API shape meet the current `90/90+` source-output standard.

## Final Decision

[UID:00023P] should remain:

```text
CANONICAL_OWNER:NONE
RECONSTRUCTABLE:TRUE
EMITTER_UIDS:
EMITTER_POSITION_OPTIONAL:
RECONSTRUCTION_CPP CODE: blank
```

This is a reconstructable no-owner/non-emitting helper island, not a pooled-constant multi-emitter case and not an ignored runtime artifact. The best if-forced owner is a narrow `NexusTK/util/WordRefCountHelpers` or `IntrusiveWordRefCount` source family, but current live IDA and PE evidence does not prove that owner strongly enough to apply it.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B001","command_id":"000000004165","destination_path":"executed-b-agent-research/B001/00023P-WordRefCountHelpers-current-goal2-pass.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:20","uid":"00023P"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
