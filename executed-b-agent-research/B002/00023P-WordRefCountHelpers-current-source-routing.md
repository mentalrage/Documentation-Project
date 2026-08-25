** TARGET-REPORT-UID:00023P **
** AUTHOR-AGENT-ID:B002 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# 00023P WordRefCountHelpers Current Source Routing Reanalysis

Assignment: `B002-goal2-word-ref-count-helpers-current-source-routing-00023P-20260618`

Target: [UID:00023P] `source-3/project-documentation/by-memory/0x00554640-0x00554675.WordRefCountHelpers.md`

Report-only scope: I did not edit by-memory docs, generated reports/source, IDA DB content, or `by-memory/-coverage-report.md`.

## Recommendation

Keep [UID:00023P] as a reconstructable no-owner/no-emitter helper island:

- `COMPLETION:88`: keep.
- `CONFIDENCE:92`: keep.
- `CANONICAL_OWNER:NONE`: keep.
- `RECONSTRUCTABLE:TRUE`: keep.
- `EMITTER_UIDS:` blank: keep.
- `EMITTER_POSITION_OPTIONAL:` blank: keep.
- `RECONSTRUCTION_CPP`: blank: keep.
- Do not split, merge, assign to an adjacent feature owner, create a by-file parent, or populate C++ from the current evidence.

The best if-forced source-placement hypothesis remains a narrow utility/source family such as `NexusTK/util/WordRefCountHelpers.cpp` or an internal `IntrusiveWordRefCount` helper. That is still a placement inference only. It does not clear the B-agent owner/emitter gate because there is no caller, pointer table, indirect-call table, vtable, class field owner, source string, object-file route, or generated-source route tying the island to that source family.

One support-only change is warranted if the supervisor refreshes shared coverage: the manual `by-memory/-coverage-report.md` row for UID `00023P` still says `82%` even though the current target page is `88/92`. Exact replacement text is in `## Exact Supervisor Changes Needed`.

## Current Target State Rechecked

The current target page already records the correct no-owner/no-emitter state:

- Header values are `COMPLETION:88`, `CONFIDENCE:92`, `CANONICAL_OWNER:NONE`, `RECONSTRUCTABLE:TRUE`, blank `EMITTER_UIDS`, blank `EMITTER_POSITION_OPTIONAL`, and blank reconstruction C++.
- Covered span is `0x00554640-0x00554675`.
- Neighboring boundaries are clean: previous documented code ends at `0x00554635`, `0x00554635-0x00554640` is alignment padding, the target island ends at `0x00554675`, `0x00554675-0x00554680` is alignment padding, and the next modeled/documented island starts at `0x00554680`.
- The page's current status correctly treats this as "tiny intrusive word reference-count / lifetime helper island" and explicitly rejects `ReconnectDialog`, `CopyWindow`, `Region`, `LObject`, `StringBase`, and `StringUtil` as direct owners.

The current target page includes live IDA evidence through 2026-06-12. In this pass, the local MCP endpoint was not reachable, so I did not claim a new live-IDB session. I rechecked the current docs and added a fresh PE-level scan of the current read-only executable bytes instead. The PE scan agrees with the target page's recorded live-IDB facts.

## Current Binary Evidence Rechecked

Fresh PE scan input:

- File: `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`.
- Size: `2679296`.
- MD5: `4247e04e20b65d6414c7238aa8ff5515`.
- SHA-256: `9aec210bbc5ce592176a21dd8e9d9fd8f250b8d9ea78237915a99ba8cfa9a632`.
- PE image base: `0x00400000`.
- `.text` section: VA `0x00401000`, virtual size `0x20b4ac`, raw offset `0x00000400`, raw size `0x20b600`.

Fresh VA-to-file offset checks:

- `0x00554635` -> `0x00153a35`.
- `0x00554640` -> `0x00153a40`.
- `0x0055464b` -> `0x00153a4b`.
- `0x00554650` -> `0x00153a50`.
- `0x00554654` -> `0x00153a54`.
- `0x00554660` -> `0x00153a60`.
- `0x00554675` -> `0x00153a75`.
- `0x00554680` -> `0x00153a80`.
- `0x005c7526` -> `0x001c6926`.

Fresh bytes for `0x00554635-0x00554680`:

```text
cc cc cc cc cc cc cc cc cc cc cc
b8 01 00 00 00 66 89 01 8b c1 c3
cc cc cc cc cc
66 ff 01 c3
cc cc cc cc cc cc cc cc cc cc cc cc
66 ff 09 66 83 39 00 7f 0b 6a 02 51 e8 b5 2e 07 00 83 c4 08 c3
cc cc cc cc cc cc cc cc cc cc cc
```

Exact helper facts:

- `0x00554640-0x0055464b`: IDA-modeled `sub_554640`; byte body `b8 01 00 00 00 66 89 01 8b c1 c3`; decompiled by the current prewave record as `_WORD *__thiscall sub_554640(_WORD *this) { *this = 1; return this; }`.
- `0x00554650-0x00554654`: raw function-shaped helper; byte body `66 ff 01 c3`; behavior is `inc word ptr [ecx]; retn`.
- `0x00554660-0x00554675`: raw function-shaped release helper; byte body `66 ff 09 66 83 39 00 7f 0b 6a 02 51 e8 b5 2e 07 00 83 c4 08 c3`; behavior is `dec word ptr [ecx]; cmp word ptr [ecx], 0; jg return; push 2; push ecx; call sub_5C7526; add esp, 8; retn`.
- The release compare is signed-positive (`jg`). It returns only while the decremented word is greater than zero; zero or negative falls through to heap free.
- `sub_5C7526` is the current free wrapper recorded by the target page as `void __cdecl sub_5C7526(void *Block) { j_j___free_base(Block); }`.
- The `push 2; push ecx; call sub_5C7526; add esp, 8` sequence means the top stack argument at callee entry is `ecx`, and the earlier `2` is an extra caller-cleaned argument not consumed by the one-argument decompiled free wrapper. This is allocator/deleting-destructor idiom evidence, not a source-owner signal.

Fresh uniqueness checks across the PE:

- Full initializer `b8 01 00 00 00 66 89 01 8b c1 c3`: exactly one hit at `0x00554640`.
- Initializer signature `b8 01 00 00 00 66 89 01`: exactly one hit at `0x00554640`.
- Full increment `66 ff 01 c3`: exactly one hit at `0x00554650`.
- Increment signature `66 ff 01`: exactly one hit at `0x00554650`.
- Full release `66 ff 09 66 83 39 00 7f 0b 6a 02 51 e8 b5 2e 07 00 83 c4 08 c3`: exactly one hit at `0x00554660`.
- Release signature `66 ff 09 66 83 39 00`: exactly one hit at `0x00554660`.
- Release tail `6a 02 51 e8 b5 2e 07 00 83 c4 08 c3`: exactly one hit at `0x00554669`.
- Full island including internal padding from `0x00554640-0x00554675`: exactly one hit at `0x00554640`.

Fresh no-reference checks:

- Absolute-VA dword pointer hits for `0x00554640`, `0x00554650`, `0x00554660`, and `0x00554675`: zero.
- RVA dword pointer hits for `0x00554640`, `0x00554650`, `0x00554660`, and `0x00554675`: zero.
- Direct executable-section branch/call targets to `0x00554640`, `0x00554650`, `0x00554660`, and `0x00554675`: zero. The scan covered `E8/E9` rel32, `0F 8x` rel32, `70-7F` rel8, and `EB` rel8 encodings.
- Current prewave exported function record for `0x00554640` records `name.ida: sub_554640`, `size.ida: 11`, `signature.ida: _WORD *__thiscall(_WORD *this)`, `num_callers.ida: 0`, `num_callees.ida: 0`, `xrefs_to.ida: []`, and `xrefs_from.ida: []`.

Fresh `sub_5C7526` / `push 2` context:

- Direct calls to `sub_5C7526`: `617`.
- Direct calls with nearby `push 2` before the call: three sites only.
- The three `push 2` sites are:
  - `0x004564b6 -> call 0x004564bb`, inside MiniMapVersionManager destructor cleanup.
  - `0x004574b6 -> call 0x004574bb`, inside MiniMapVersionManager scalar deleting destructor cleanup.
  - `0x00554669 -> call 0x0055466c`, inside this target release helper.
- The two MiniMapVersionManager sites free node payload/version strings at node offset `+0x0c` during list/index teardown. They prove the `push 2` form is shared free/deallocation idiom shape, not evidence that UID `00023P` belongs to MiniMapVersionManager.

Fresh string/source-marker scan:

- No ASCII or UTF-16LE hits for `refcount`, `ref count`, `referencecount`, `reference count`, `intrusive`, `WordRef`, `WordRefCount`, `554640`, `554650`, or `554660`.
- No `.pdb`, `RSDS`, or `NB10` debug path marker was found.
- Existing unrelated strings/classes such as `StringBase`, `LObject`, `Region`, `Motion`, `Reconnect`, and `CopyWindow` do occur elsewhere in the image, but the fresh pointer/branch/pattern scans above show no route from those names/families to the helper starts or byte pattern.

## Current Source Route And Supporting Docs Rechecked

Generated/source-route evidence:

- `auto-generated/-ag-memory-coverage.md` still lists UID `00023P` as `no-owner` with canonical owner `NONE`, blank emitter fields, and no output route.
- Repository-wide searches for `WordRefCountHelpers`, `WordRef`, `IntrusiveWordRef`, `0x00554640`, `0x00554650`, and `0x00554660` found only the target page, old research/supervisor tracker text, ignored/coverage references, generated no-owner coverage rows, and prewave function/cache records. No by-file parent, generated source file, simroot source file, or proposed source route exists for this helper family.
- `by-project-structure/proposed-source-tree.md` lists existing `NexusTK/util/` entries such as `LObject.cpp`, `LinkedList.cpp`, `PoolAllocator.cpp`, `StringUtil.cpp`, and `StringBase.cpp`; it does not list `WordRefCountHelpers.cpp`, `IntrusiveWordRefCount.cpp`, or a comparable refcount utility file.
- `source-3/core/data/readonly/prewave/exported-functions/0x00554640.json` and the corresponding cache file expose only the standalone IDA function `sub_554640` with zero callers/callees/xrefs. They do not provide source-family metadata.

Candidate owner rechecks:

- `StringBase` / `StringUtil`: rejected. Current `StringBase` owns the large ref-counted ANSI/UTF-16 string-buffer family at `0x00582500-0x00584d7d`. That family uses a data pointer with a 12-byte header before the returned string data, 32-bit interlocked refcounts at `data - 0x0c`, length/capacity fields, shared sentinels at `0x00670278` / `0x00670290`, and fixed 64/128/256/512 string-buffer pools. UID `00023P` is a direct 16-bit `word [ecx]` object-head counter that frees `this` directly through `sub_5C7526`; it has no string sentinel, pool, data-minus-header layout, or interlocked operation. Current `StringUtil` also contains an explicit precedent against attaching no-xref helper islands to a string utility solely from semantic resemblance.
- `LObject`: rejected. Current `LObject` is the small one-vptr runtime/base shell with constructor/runtime-class/scalar-deleting-destructor evidence. UID `00023P` has no vtable store, no runtime-class record, no RTTI/vtable pointer, no inherited-object field evidence, and no reference route into the `LObject` family.
- `ReconnectDialog` / `ConnectionClosedDialog` / `CopyWindow`: rejected. The prior physical aggregate ends at `0x00554635`; `0x00554635-0x00554640` is `0xcc` alignment before the target. `ReconnectDialog` owns exact dialog methods and cleanup/destructor tails up to that boundary, while `CopyWindow` owns the interleaved `0x005544c0-0x0055454b` island. There are no calls, pointers, vtable references, singleton globals, local names, or shared byte patterns linking those UI/dialog owners to `0x00554640`, `0x00554650`, or `0x00554660`.
- `Region` / `Motion` / `RectBounds`: rejected. The following `RegionAndMotionRect` aggregate starts at `0x00554680` after `0x00554675-0x00554680` padding. It has Region/Motion rectangle-helper evidence, Region vtable/read-only data, rectangle state, and UI/render fanout. The target island is before that boundary and has only a word counter plus free wrapper call. `Motion` specifically owns animation/timer behavior and excludes Region rectangle helpers; none of the current Region/Motion/RectBounds docs point back to the target.
- `MiniMapVersionManager`: rejected. It is a useful negative control because two MiniMapVersionManager destructor paths share the `push 2; push <payload>; call sub_5C7526` idiom. Their source context is map-version list/index cleanup and node payload strings at node `+0x0c`; their addresses are `0x00456480` and `0x00457480`, far from the target. The shared free-call idiom does not transfer ownership.
- CRT/free-wrapper/deleting-destructor idioms: rejected as owners. `sub_5C7526` is a shared free wrapper with 617 direct call sites. Its use proves deallocation behavior only. UID `00023P` is also not a normal scalar deleting destructor body: it has no inbound delete flag parameter, no vtable reset, no base/member destructor calls, no `retn 4`, and no class-specific vtable or RTTI route. The extra `push 2` is caller-cleaned allocator/deletion idiom shape, not a source file.
- Pool/allocator families: rejected. `PoolAllocator` owns fixed-block pool state, locked free lists, chunk allocation, and concrete pool globals. UID `00023P` performs a direct free-wrapper call on `this` and has no pool instance, free-list fields, chunk state, or fixed-size block allocator references.
- `LinkedList` / STL helper families: rejected. Current docs classify list support helpers as non-emitting MSVC/Dinkumware `std::list<T>` support. `StdListTidy8ByteList` and related helpers allocate/free 16-byte nodes or two-dword payload nodes. UID `00023P` has no sentinel/list state, node links, size field, or typed container caller.
- Adjacent feature owners: rejected. Physical adjacency alone is insufficient because both sides are separated by alignment padding, and the current docs assign exact children to the actual neighboring source families.
- New utility by-file parent: plausible but not assignable. A future `NexusTK/util/WordRefCountHelpers.cpp` or an internal `IntrusiveWordRefCount` type is the best narrow source-family hypothesis if policy requires a bucket. Current evidence supports the behavior family but not the direct source route, file name, header placement, function spelling, member/free-function shape, or live use site.

## Heuristic / Inference Reanalysis And Validation

The valid heuristic inference is behavioral, not source-routing: the three bodies form a coherent init/addref/release family for an intrusive 16-bit reference count stored at object offset `+0x00`. The initializer writes `1`, the increment bumps the same word, and the release decrements the same word and frees the object when the signed count is no longer positive. The byte island is unique in the executable, so treating these three snippets as one helper cluster is correct.

The invalid heuristic jump would be to convert that behavioral family into a source owner. No current source-route evidence proves whether these were hand-written utility helpers, compiler-retained inline/template fragments, methods of an unknown counted allocation type, dead unreferenced helper thunks, or externally referenced routines whose route is hidden by absent relocation/source metadata. The absence of direct references is especially important: a helper family can be behaviorally reconstructable and still be non-emitting when no source file or API surface is proven.

The narrow utility hypothesis is stronger than every existing owner candidate because it explains the complete init/addref/release set without relying on unrelated adjacent UI/dialog/map/string owners. It remains below assignment threshold because it is source-placement by shape only. The proposed source tree currently has no such file, current generated coverage has no route, and no current by-file parent can absorb the target without inventing an owner.

The `push 2` idiom is now validated as a free/deallocation idiom rather than a type-owner signature. The PE scan found exactly three `push 2` near-call sites into `sub_5C7526`; two belong to MiniMapVersionManager destructor cleanup of node payload strings, and the third is UID `00023P`. This makes `push 2` a negative control against overfitting: it is not enough to infer MiniMap ownership, a CRT wrapper owner, a deleting destructor owner, or a utility source route.

Raw helper liveness is validated in the only way current evidence allows: the bytes exist in executable `.text`, decode to complete `retn`-terminated helper bodies, are separated by `0xcc` padding, and the modeled initializer has a current prewave active function record. Runtime reachability is not validated: there are no current callers, no pointers, no relative branches, and no generated/source route. Therefore the page should stay reconstructable for behavior but non-emitting for source.

The split/merge heuristic also favors no change. Splitting into three child pages would preserve the same no-owner/no-emitter result while duplicating one coherent lifetime-helper story. Merging into the predecessor or successor would cross explicit alignment boundaries and attach an unreferenced utility island to unrelated UI/dialog/geometry owners. Creating a new by-file parent would give a convenient bucket but would not meet the true-direct-parent requirement.

## First-Draft C++ Recommendation Or Exact Do-Not-Populate Proof

Do not populate the target C++ block.

Exact do-not-populate proof:

- The formal code gate requires a valid emitter route. UID `00023P` has `RECONSTRUCTABLE:TRUE` and `(88 + 92) / 2 = 90`, but `EMITTER_UIDS` is blank and no by-file/global/type emitter is proven.
- The only source-facing name in current recovered data is compiler-generated `sub_554640`; the increment and release helpers are not even IDA-modeled function objects. Any names such as `WordRefCountHelpers`, `IntrusiveWordRefCount`, `AddRef`, or `Release` would be descriptive reverse-engineering names, not recovered source symbols.
- The API surface is unresolved. The bytes support behavior-only signatures of `_WORD *__thiscall sub_554640(_WORD *this)`, `void __thiscall raw_inc_word_ref(_WORD *this)`, and `void __thiscall raw_release_word_ref(_WORD *this)`, but they do not prove whether original source used class members, free functions, static helpers, macros, inline template support, or compiler-emitted local thunks.
- The object type is unresolved. The counter is a 16-bit word at `this + 0x00`, but no caller or type owner proves the containing allocation layout, destructor obligations, signedness contract, overflow policy, or whether freeing on count `<= 0` reflects source intent or compiler lowering.
- The source file is unresolved. Existing candidates are rejected, and the best utility route is still below assignment threshold.
- Emitting C++ under an invented utility owner would create false precision: it would assert final source placement, declaration names, and callable API shape that current evidence explicitly lacks.

If the supervisor later obtains caller/table/source evidence, the behavior to encode should be derived from the exact byte facts above. Until that happens, the correct reconstruction block is blank.

## Exact Supervisor Changes Needed

Target page changes: none.

Do not change the UID `00023P` metadata, owner, emitter fields, reconstruction C++ block, split boundaries, or by-file assignments.

Do not create a new `by-file/WordRefCountHelpers.md`, `by-file/IntrusiveWordRefCount.md`, `by-class/IntrusiveWordRefCount.md`, or generated C++ file from the current evidence. If future evidence proves a route, the likely proposed source path would be under `NexusTK/util/`, but current docs do not justify creating that parent.

Manual coverage support change: recommended. Replace the current stale `by-memory/-coverage-report.md` UID `00023P` row with exactly:

```text
    - [UID:00023P][0x00554640-0x00554675.WordRefCountHelpers](by-memory/0x00554640-0x00554675.WordRefCountHelpers.md) 0x00554640-0x00554675 | function cluster | WordRefCountHelpers : reconstructable : 88% : strong : B002 2026-06-18 current-source-routing pass reconfirmed the coherent unique three-helper 16-bit intrusive refcount island with modeled initializer `0x00554640-0x0055464b`, raw increment helper `0x00554650-0x00554654`, raw release/free helper `0x00554660-0x00554675`, exact surrounding/internal `0xcc` padding, current prewave `_WORD *__thiscall sub_554640(_WORD *this)` record with zero callers/callees/xrefs, fresh PE zero absolute-VA/RVA/relative-branch references to all helper starts, unique full-range and per-helper byte signatures, no source/refcount/intrusive/PDB metadata strings, no generated source route, and only MiniMapVersionManager negative controls for the `push 2` free-wrapper idiom. Existing StringBase/StringUtil/LObject/Region/Motion/ReconnectDialog/CopyWindow/MiniMapVersionManager/CRT/free-wrapper/pool/allocator/list/adjacent owners remain rejected; a narrow `NexusTK/util/WordRefCountHelpers` or `IntrusiveWordRefCount` family is the best if-forced hypothesis but still below owner/emitter assignment threshold, so the target stays `CANONICAL_OWNER:NONE`, blank emitters, and blank C++.
```

Generated report/source changes: none requested and none needed from this report-only assignment. The current generated memory coverage already records the no-owner/no-emitter disposition for UID `00023P`; it does not need a manual edit.

Validation: no by-* or generated docs were modified, so I did not run the metadata validator. The only file added by this work is this report.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B002","command_id":"000000004165","destination_path":"executed-b-agent-research/B002/00023P-WordRefCountHelpers-current-source-routing.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:24","uid":"00023P"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
