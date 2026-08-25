** TARGET-REPORT-UID:00023P **
** AUTHOR-AGENT-ID:B001 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# 00023P - WordRefCountHelpers current Goal 2 pass

## Final Recommendation

Keep `UID:00023P` as `CANONICAL_OWNER:NONE` with blank `EMITTER_UIDS`.

The current target is a real reconstructable helper island at `0x00554640-0x00554675`, but the current IDA MCP pass still shows no caller, no data pointer, no immediate pointer, no xref signature, no name/string metadata, and no neighboring source owner strong enough to claim it. The best-if-forced source-family remains a narrow missing utility such as `NexusTK/util/WordRefCountHelpers` or `IntrusiveWordRefCount`, but that is only a semantic hypothesis and does not meet by-structure owner/emitter standards.

No split, merge, reclassification, IDA-safe name repair, target metadata edit, or shared coverage-report repair is required. Keep C++ blank because the item remains below the active `90/90+` code-entry gate and has no defensible owner/source route.

Recommended target state:

```text
UID:00023P
CANONICAL_OWNER:NONE
RECONSTRUCTABLE:TRUE
EMITTER_UIDS:
COMPLETION:88
CONFIDENCE:92
RECONSTRUCTION_CPP:
```

## Target And Scope

- Target: `by-memory/0x00554640-0x00554675.WordRefCountHelpers.md`
- Current generated status: reconstructable `no-owner`, `CANONICAL_OWNER:NONE`, blank `EMITTER_UIDS`
- Current generated row reviewed from `auto-generated/-ag-memory-coverage.md`
- Prior background reviewed: `tools/leaser/Agents/Agent-B003/research/executed/00023P-WordRefCountHelpers-current-goal2-pass.md`
- Related docs reviewed as leads, not authority: adjacent ReconnectDialog/Region memory pages, `StringBase`, `StringUtil`, `RefCountedStringBufferHeader`, `LinkedList`, `PoolAllocator`, `LObject`, and `MiniMapVersionManager`

This assignment explicitly prohibited direct edits to by-memory/by-structure docs and `by-memory/-coverage-report.md`; only this B001 research report was changed.

## Evidence Standards Applied

I used the current by-structure owner/emitter model:

- A canonical owner needs direct semantic ownership evidence such as callers, vtables/tables, source-family metadata, type layout, or a coherent documented file/class boundary.
- An emitter needs a proven source-use/output route. A helper being reconstructable is not enough.
- Adjacency and compiler layout are weak evidence, especially around `0xcc` alignment islands.
- Shared or ownerless helpers can remain `CANONICAL_OWNER:NONE` when no source route is provable.
- Reconstruction C++ requires `90/90+` source-quality evidence. This target is still `88/92`, and the missing source owner keeps it out of code entry.

## Current Documentation State

The target page currently records a three-helper word refcount island:

- `0x00554640-0x0055464b`: IDA-modeled initializer helper.
- `0x0055464b-0x00554650`: `0xcc` padding.
- `0x00554650-0x00554654`: raw increment helper.
- `0x00554654-0x00554660`: `0xcc` padding.
- `0x00554660-0x00554675`: raw release/free helper.

The target page already has `CANONICAL_OWNER:NONE`, blank `EMITTER_UIDS`, blank `RECONSTRUCTION_CPP`, `COMPLETION:88`, and `CONFIDENCE:92`. The current generated coverage row also routes it as no-owner with no emitters. That state matches the current evidence.

## IDA MCP Session

Current live evidence was collected from IDA MCP database `b001_0003gy`:

```text
input_path: E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe
module: NexusTK.exe
imagebase: 0x400000
auto_analysis_ready: true
hexrays_ready: true
strings_cache_ready: true
```

Function lookup:

```text
0x00554635: not a function
0x00554640: sub_554640, size 0x0b
0x0055464b: not a function
0x00554650: not a function
0x00554654: not a function
0x00554660: not a function
0x00554675: not a function
0x00554680: sub_554680, next documented Region/Motion function
0x005c7526: sub_5C7526, CRT free wrapper
```

Hex-Rays decompilation for the only IDA-modeled function:

```c
_WORD *__thiscall sub_554640(_WORD *this)
{
  *this = 1;
  return this;
}
```

Raw disassembly confirms the two unmodeled children:

```asm
00554650  inc word ptr [ecx]
00554653  retn

00554660  dec word ptr [ecx]
00554663  cmp word ptr [ecx], 0
00554667  jg short locret_554674
00554669  push 2
0055466b  push ecx
0055466c  call sub_5C7526
00554671  add esp, 8
00554674  retn
```

The callee `sub_5C7526` decompiles as a thin `free` wrapper:

```c
void __cdecl sub_5C7526(void *Block)
{
  j_j___free_base(Block);
}
```

## Raw Bytes And Signature Evidence

Current `get_bytes` over `0x00554635-0x00554680` confirms an isolated alignment island:

```text
0x00554635-0x00554640: 11 bytes of 0xcc padding
0x00554640-0x0055464b: b8 01 00 00 00 66 89 01 8b c1 c3
0x0055464b-0x00554650: 5 bytes of 0xcc padding
0x00554650-0x00554654: 66 ff 01 c3
0x00554654-0x00554660: 12 bytes of 0xcc padding
0x00554660-0x00554675: 66 ff 09 66 83 39 00 7f 0b 6a 02 51 e8 b5 2e 07 00 83 c4 08 c3
0x00554675-0x00554680: 11 bytes of 0xcc padding
```

Current exact signatures are unique:

```text
0x00554640 initializer: unique
0x00554650 increment: unique
0x00554660 release/free: unique
0x00554640-0x00554675 full-range signature including internal padding: unique
```

`find_bytes` found one exact hit for each helper body and zero little-endian VA/RVA pointer-pattern hits for `0x00554640`, `0x00554650`, `0x00554660`, or `0x00554675`. Positive controls found pointer/signature hits for nearby real owned items such as `0x00554680` and the MiniMapVersionManager vtable pointer at `0x006108d4`, so the zero-reference result for this island is meaningful rather than a failed search mode.

## Xrefs And Caller Inventory

Current IDA MCP xref checks:

```text
0x00554640: 0 code refs, 0 data refs, 0 xref signatures
0x00554650: 0 code refs, 0 data refs, 0 xref signatures
0x00554660: 0 code refs, 0 data refs, 0 xref signatures
0x00554675: 0 code refs, 0 data refs
```

The only internal references inside the target are:

```text
0x00554667 -> 0x00554674 internal branch
0x0055466b -> 0x005c7526 call to free wrapper
```

There are no callers to any helper start and no data table containing any helper address. `entity_query` also found no local names in `0x00554600-0x00554700` and no useful strings matching refcount/reference-count/intrusive/word-ref/PDB terms.

## Neighbor And Candidate Owner Analysis

### Adjacent ReconnectDialog / CopyWindow range rejected

The predecessor range ends at `0x00554635` and is separated from this target by `0x0b` bytes of `0xcc` padding. It has its own documented ReconnectDialog ownership and destructor/vtable evidence. There are no references from that range into the word-refcount helpers, and adjacency across padding is not owner evidence.

### Adjacent Region / Motion range rejected

The successor range begins at `0x00554680`, after `0x0b` bytes of `0xcc` padding. It has many positive xrefs and its own Region/Motion ownership evidence. There are no references from Region/Motion functions to `0x00554640`, `0x00554650`, or `0x00554660`, so the next function's documented owner should not absorb this island.

### StringBase / RefCountedStringBufferHeader rejected

The documented StringBase refcount system uses a 12-byte header before the character data pointer and 32-bit interlocked refcounts with capacity/length fields. This target manipulates a 16-bit word at `ecx` itself and frees `ecx` directly when the word count is non-positive. The layouts and synchronization model are incompatible.

### StringUtil rejected

StringUtil is only a broad utility family lead. There are no string names, no string call edges, no string-buffer layout, and no source-route evidence tying this helper island to StringUtil.

### LinkedList / PoolAllocator / LObject rejected

LinkedList has separate sentinel-node helper patterns and callers. PoolAllocator owns fixed-size allocator state, not this direct word-at-object-head release path. LObject is a vptr/runtime shell and does not match this no-vtable word-refcount object layout.

### MiniMapVersionManager / CRT free wrapper rejected

MiniMapVersionManager destructors are useful negative controls because they also reach the CRT free wrapper in class-owned cleanup code, but that proves only that `sub_5C7526` is a common free wrapper. A callee does not own its callers, and no MiniMap code or table references this target island.

### New narrow utility owner remains below assignment threshold

The behavior strongly resembles a tiny intrusive 16-bit refcount helper family:

- initialize count to `1`
- increment `word [ecx]`
- decrement `word [ecx]` and free the object when the count is not positive

That supports the current analyst label `WordRefCountHelpers`, but not a canonical owner. A new `NexusTK/util/WordRefCountHelpers` or `IntrusiveWordRefCount` source-family would be plausible only if caller, table, type, source, or object-file evidence appears later.

## Split / Merge / Reclassification Analysis

No split is recommended. Splitting the initializer, increment, and release helpers would create three smaller ownerless artifacts with the same missing evidence. Keeping them as one function cluster better preserves the shared object-layout semantics and padding-separated helper family.

No merge is recommended. Both neighbors are separated by clear `0xcc` padding and have independent documented ownership. The predecessor and successor owners have no current references to this target.

No reclassification is recommended. This is not compiler/runtime metadata, a vtable, or pure padding. It is executable helper code with reconstructable behavior, so `RECONSTRUCTABLE:TRUE` remains correct.

## Required Edits

Required by-memory target edits: none.

Required by-structure edits: none.

Required `by-memory/-coverage-report.md` edits: none.

Required generated-row repair: none. The current generated no-owner row should remain:

```md
| [UID:00023P][0x00554640-0x00554675.WordRefCountHelpers](by-memory/0x00554640-0x00554675.WordRefCountHelpers.md) | no-owner | `NONE` |  |  | no |  | `by-memory/0x00554640-0x00554675.WordRefCountHelpers.md` |  |
```

Optional supervisor-owned manual coverage-row provenance refresh, if the supervisor wants `by-memory/-coverage-report.md` to cite this B001 current pass instead of older prior-pass text:

```md
- [UID:00023P][0x00554640-0x00554675.WordRefCountHelpers](by-memory/0x00554640-0x00554675.WordRefCountHelpers.md) 0x00554640-0x00554675 | function cluster | WordRefCountHelpers : reconstructable : 88% : strong : B001 current Goal 2 pass reconfirmed a coherent three-helper 16-bit intrusive refcount island: modeled initializer `0x00554640-0x0055464b` writes `word [ecx]=1` and returns `ecx`, raw increment helper `0x00554650-0x00554654` increments `word [ecx]`, and raw release helper `0x00554660-0x00554675` decrements `word [ecx]`, compares it with zero, and calls the CRT free wrapper `sub_5C7526` on `ecx` when the count is not positive. Current IDA MCP evidence shows exact `0xcc` padding before, between, and after the helpers; unique exact initializer/increment/release/full-range byte signatures; zero code refs, data refs, immediate VA/RVA refs, pointer-pattern hits, or xref signatures for `0x00554640`, `0x00554650`, `0x00554660`, and `0x00554675`; no local names in `0x00554600-0x00554700`; and no refcount/intrusive/PDB metadata strings. Adjacent ReconnectDialog/CopyWindow and Region/Motion ranges are separated by padding and have independent ownership; StringBase/RefCountedStringBufferHeader, StringUtil, LinkedList, PoolAllocator, LObject, MiniMapVersionManager, and CRT/free-wrapper ownership hypotheses are rejected. A narrow missing utility source-family such as `WordRefCountHelpers` or `IntrusiveWordRefCount` remains plausible but does not clear canonical-owner or emitter assignment without caller, table, type, source, or object-file evidence.
```

Optional supervisor-owned tracker completion text:

```md
| 00023P | 0x00554640-0x00554675.WordRefCountHelpers | by-memory/0x00554640-0x00554675.WordRefCountHelpers.md | Agent-B001 | 2026-06-14 | complete-no-change | Keep CANONICAL_OWNER:NONE and blank EMITTER_UIDS; B001 current IDA MCP recheck found a unique three-helper 16-bit refcount island with no callers, pointer refs, metadata, or defensible owner/emitter route. | Agent-B001/research/00023P-WordRefCountHelpers-current-goal2-pass.md |
```

## Validation And Lease State

No by-memory, by-structure, by-file, or shared coverage files were edited, so no documentation validator was required for in-scope docs. No dry runs were used.

Changed file:

```text
tools/leaser/Agents/Agent-B001/research/00023P-WordRefCountHelpers-current-goal2-pass.md
```

Lease state:

```text
B001 lease acquired for this report before writing.
B001 lease released after final report verification.
```

## Confidence

Recommendation confidence: `92/100`.

The executable behavior is clear and reconstructable, and the no-owner/no-emitter conclusion is strongly supported by current negative xref, pointer, signature, name, string, neighbor, and candidate-owner evidence. Confidence stops short of absolute because a stripped helper with no callers could still belong to a missing source utility module, but that cannot be assigned under current by-structure standards.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B001","command_id":"000000004165","destination_path":"executed-b-agent-research/B001/00023P-WordRefCountHelpers-current-no-owner-sweep.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:20","uid":"00023P"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
