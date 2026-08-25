** TARGET-REPORT-UID:00023P **
** AUTHOR-AGENT-ID:B002 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# Final Recommendation

Keep [UID:00023P] `by-memory/0x00554640-0x00554675.WordRefCountHelpers.md` unchanged:

- `CANONICAL_OWNER:NONE`
- `EMITTER_UIDS:` blank
- `RECONSTRUCTABLE:TRUE`
- no split and no child pages
- no reconstruction C++ and no source emitter

This is still a reconstructable source-authored helper island, but it has no proven direct owner or source-use route under the current owner/emitter model. The three helpers form a coherent 16-bit intrusive reference-count family, yet live IDA and independent PE scans show no callers, code refs, data refs, xref signatures, raw VA/RVA pointers, or relative branches to any helper start. Creating a new `util/WordRefCountHelpers` or `IntrusiveWordRefCount` file would be a plausible placement guess, not an 85/85 direct parent. Attaching it to adjacent dialog or Region/Motion code would be worse because those pages have explicit padding boundaries and unrelated ownership evidence.

No shared coverage-report edit is required. If the supervisor wants a provenance refresh anyway, use this exact replacement row text:

```text
    - [UID:00023P][0x00554640-0x00554675.WordRefCountHelpers](by-memory/0x00554640-0x00554675.WordRefCountHelpers.md) 0x00554640-0x00554675 | function cluster | WordRefCountHelpers : reconstructable : 88% : strong : B002 2026-06-14 live Goal 2 IDA MCP and independent PE scans reconfirm a coherent, unique three-helper 16-bit intrusive refcount island with modeled initializer `0x00554640-0x0055464b`, raw increment helper `0x00554650-0x00554654`, raw release/free helper `0x00554660-0x00554675`, exact surrounding/internal `0xcc` padding, decompiled `_WORD` initializer, zero code/data refs and xref signatures to all three helper starts, zero immediate VA/RVA references, zero absolute-VA/RVA/raw-pointer hits, zero relative-branch targets, unique exact helper byte patterns, no `refcount`/`intrusive`/`WordRef` metadata strings, and negative controls showing the `push 2` free-wrapper idiom also appears only in MiniMapVersionManager cleanup/destructor paths plus this island. Existing ReconnectDialog/CopyWindow/Region/Motion/StringBase/StringUtil/LinkedList/PoolAllocator/LObject/MiniMapVersionManager/CRT owners are rejected; a narrow `util/WordRefCountHelpers` or `IntrusiveWordRefCount` source family remains the best-if-forced hypothesis but does not clear owner/emitter assignment without caller, table, type, source, or object-file evidence.
```

---

# Research

## Scope

- Target: [UID:00023P] `0x00554640-0x00554675.WordRefCountHelpers`.
- Current metadata rechecked from the target page: `COMPLETION:88`, `CONFIDENCE:92`, `CANONICAL_OWNER:NONE`, `RECONSTRUCTABLE:TRUE`, blank `EMITTER_UIDS`, blank `EMITTER_POSITION_OPTIONAL`, blank reconstruction C++.
- This was a fresh pass. Prior reports were treated as background only; the recommendation below is based on current target docs, current adjacent/candidate owner docs, live IDA MCP evidence, and a new read-only PE scan.

## Live IDA MCP Evidence

Active session:

- MCP database: `a001_goal2_class_batch`
- Input: `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`
- IDB: `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe.i64`
- Imagebase: `0x400000`
- Auto-analysis and Hex-Rays: ready

Function and boundary checks:

- `lookup_funcs` reports only `sub_554640` at `0x00554640` in the target island, size `0x0b`.
- `0x0055464b`, `0x00554650`, `0x00554654`, `0x00554660`, and `0x00554675` are not IDA function starts.
- The successor `0x00554680` is `sub_554680`, size `0x61`, matching the separate Region/Motion rectangle aggregate.
- The free wrapper `0x005c7526` is `sub_5C7526`, size `0x0e`.

Decompilation and bytes:

```c
_WORD *__thiscall sub_554640(_WORD *this)
{
  *this = 1;
  return this;
}
```

- IDA disassembly for `0x00554640` is exactly four instructions: `mov eax, 1`; `mov [ecx], ax`; `mov eax, ecx`; `retn`.
- `get_bytes 0x00554635 size 11` is all `0xcc`.
- `get_bytes 0x00554640 size 0x35` matches the initializer, five `0xcc` bytes, `66 ff 01 c3`, twelve `0xcc` bytes, and the release/free helper.
- `get_bytes 0x00554675 size 11` is all `0xcc`.
- `decompile 0x005c7526` returns `void __cdecl sub_5C7526(void *Block) { j_j___free_base(Block); }`.

Reference checks:

- `xrefs_to` reports zero xrefs to `0x00554640`, `0x00554650`, and `0x00554660`.
- As a contrast control, `xrefs_to 0x00554680` reports broad caller fanout and truncates after the first five of many code refs, confirming the reference tooling is working on the adjacent Region constructor.
- `find type=code_ref` reports zero matches for all three helper starts.
- `find type=data_ref` reports zero matches for all three helper starts.
- `find type=immediate` reports zero matches for all three helper VAs and RVAs.
- `find_xref_signatures` returns no signatures and `total_xrefs:0` for all three helper starts.
- `find_regex '(refcount|ref count|referencecount|intrusive|WordRef)'` returns zero string/name matches.

Pattern checks:

- Initializer pattern `b8 01 00 00 00 66 89 01 8b c1 c3`: one IDB hit at `0x00554640`.
- Increment pattern `66 ff 01 c3`: one IDB hit at `0x00554650`.
- Release pattern `66 ff 09 66 83 39 00 7f 0b 6a 02 51 e8 b5 2e 07 00 83 c4 08 c3`: one IDB hit at `0x00554660`.
- Release tail `6a 02 51 e8 b5 2e 07 00 83 c4 08 c3`: one IDB hit at `0x00554669`.
- Little-endian VA and RVA byte patterns for `0x00554640`, `0x00554650`, and `0x00554660` return no IDB byte hits.

## Independent PE Scan

Read-only binary scan target:

- File: `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`
- MD5: `4247e04e20b65d6414c7238aa8ff5515`
- Imagebase: `0x400000`

Findings:

- Target file offsets map inside `.text`: `0x00554640 -> 0x153a40`, `0x00554650 -> 0x153a50`, `0x00554660 -> 0x153a60`.
- The exact initializer, increment, release, and release-tail byte patterns each occur once in the file, at `0x00554640`, `0x00554650`, `0x00554660`, and `0x00554669`.
- Whole-file scans find zero little-endian VA dwords and zero RVA dwords for `0x00554640`, `0x00554650`, and `0x00554660`.
- Raw executable-section branch scans find zero `E8`, `E9`, `0F 8x`, short conditional, `EB`, or `E3` branch targets to any helper start.
- The only `push 2` plus direct call to `sub_5C7526` sites found are `0x004564b6`, `0x004574b6`, and this island at `0x00554669`; the first two are MiniMapVersionManager cleanup/destructor-region negative controls, not ownership evidence for this target.

## Current Documentation Cross-Checks

Adjacent ranges:

- [UID:0001FT] `0x00553c10-0x00554635.ConnectionClosedReconnectDialogs` is a non-emitting mixed map. It explicitly ends at `0x00554635`; exact children carry ReconnectDialog/ConnectionClosedDialog/CopyWindow ownership. It lists this WordRefCountHelpers page only as the following range.
- Coverage report padding row `0x00554635-0x00554640` is all `0xcc`, separating the reconnect cleanup/destructor tail from this target.
- [UID:0001FW] `0x00554680-0x00554b38.RegionAndMotionRect` starts after the target's trailing padding. Its current metadata routes to [UID:0000N3] Region, and live docs record broad Region/Motion dirty-rectangle caller fanout.
- Coverage report padding row `0x00554675-0x00554680` is all `0xcc`, separating this target from Region/Motion.

Candidate owner pages:

- [UID:0000N0] `ReconnectDialog`: owns connection/reconnect dialog classes, singleton globals, exact method/destructor children, and the CopyWindow side-path exclusion. It has no reference path into `0x00554640-0x00554675`.
- [UID:0000IH] `CopyWindow`: owns only the raw constructor/callback island at `0x005544c0-0x0055454b` and excludes the reconnect-flow helper as a caller-side construction path. No current doc ties it to the word-count island.
- [UID:0000N3] `Region` and [UID:0000LL] `Motion`: explicitly split Region dirty-rectangle helpers from timer-driven Motion animation. Their documented safe Region island begins at `0x00554680`, after padding, and uses rectangle/LObject/vtable evidence rather than a word counter.
- [UID:0000OA] `StringBase` and [UID:0000OB] `StringUtil`: own/refine ref-counted string infrastructure, but the documented string-buffer family uses a 12-byte header, 32-bit interlocked reference counts, sentinels, pools, and `StringBase` metadata. That contradicts this target's 16-bit object-head counter and direct `free(this)` behavior.
- [UID:0000KR] `LinkedList`: owns a separate sentinel doubly-linked-list helper family at `0x004570e0`, `0x00457430`, and `0x00457550`; its allocation/free pattern and two-word payload nodes do not match this island.
- [UID:0000MM] `PoolAllocator`: owns fixed-size block pool mechanics and free-list return helpers; this target calls the CRT free wrapper directly and has no lock/free-list/chunk-list behavior.
- [UID:0000KV] `LObject`: owns the true one-vptr base/runtime shell around `0x004f4a80-0x004f4c0d` and explicitly excludes polluted string-family ownership. This target has no vtable, runtime-class record, or LObject metadata path.
- [UID:0000LF] `MiniMapVersionManager`: its destructor/cleanup area supplies the only two non-target `push 2` free-wrapper idiom sites, but that only proves an allocator/deleting-cleanup idiom exists elsewhere. There are no xrefs from MiniMapVersionManager to this helper island.

## Ownership Ranking

1. New narrow `util/WordRefCountHelpers` or `IntrusiveWordRefCount` source family: best if forced, because the bytes form a complete init/addref/release helper family. Rejected for actual assignment because there are no callers, tables, source names, type names, object-file boundaries, or sibling helpers proving this file root at 85/85.
2. Existing `StringBase` / `StringUtil`: rejected. The only positive theme is "reference count", but current docs and IDA evidence show incompatible string layouts and mechanics.
3. Adjacent `ReconnectDialog`, `ConnectionClosedDialog`, `CopyWindow`, `Region`, or `Motion`: rejected. Physical proximity is defeated by exact `0xcc` padding boundaries and by the adjacent pages' current source ownership evidence.
4. `LinkedList`, `PoolAllocator`, `LObject`, `MiniMapVersionManager`, or CRT: rejected. Each has either incompatible behavior or only a shared callee/idiom without a reference path.

## Why Reconstructable But Non-Emitting Is Correct

The target is reconstructable because the behavior is small and clear:

- initialize `word [this]` to `1`
- increment `word [ecx]`
- decrement `word [ecx]`; free `this` through `sub_5C7526` when the signed count is no longer positive

That does not imply it should emit. Under the current system, emission requires a proven source route through a canonical owner or one or more emitters. This island has no proven consumers and no source-facing declaration evidence. Emitting it into a guessed utility file would create source that cannot currently be placed, named, or referenced with 85/85 confidence. Keeping it as `RECONSTRUCTABLE:TRUE` with `CANONICAL_OWNER:NONE` and blank `EMITTER_UIDS` preserves the recovered behavior while preventing speculative source output.

## Split Decision

No split is needed. The three executable helper bodies and internal padding are already one coherent micro-family:

- `0x00554640-0x0055464b`: modeled initializer
- `0x0055464b-0x00554650`: padding
- `0x00554650-0x00554654`: raw increment helper
- `0x00554654-0x00554660`: padding
- `0x00554660-0x00554675`: raw release/free helper

Splitting would create three smaller no-owner/non-emitting helper pages with no new owner evidence and worse documentation overhead. The master page already clears the strict documentation gate.

## Validation And Edits

- Files edited: only this Agent-B002 research report.
- Shared target page edited: no.
- Shared coverage report edited: no.
- Leases: not needed because no shared project documentation files were edited.
- Validator: not run because no by-memory/by-file/by-class metadata or coverage files were changed.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B002","command_id":"000000004165","destination_path":"executed-b-agent-research/B002/00023P-WordRefCountHelpers-live-goal2-no-owner-pass.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:24","uid":"00023P"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
