** TARGET-REPORT-UID:00012H **
** AUTHOR-AGENT-ID:B005 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# 00012H DATFileResolverDestroy Source-Quality Research

## Finalized Report / Current Recommendation

- Target: [UID:00012H] `by-memory/0x0049d190-0x0049d26c.DATFileResolverDestroy.md`.
- Recommendation: raise the target from `84/88` to `86/90`, keep `CANONICAL_OWNER:00003J`, keep `RECONSTRUCTABLE:TRUE`, keep `EMITTER_UIDS:00003J`, and populate a first-draft C++ block for the resolver destructor/cleanup body.
- Source placement: keep the source root in [UID:0000IO] `DATFileMgr` / `NexusTK/archive/DATFileMgr.cpp`. Treat [UID:00003J] `DATFileResolver` as an internal helper/member type embedded at `_DATFileMgr + 4`, not as evidence for a standalone `DATFileResolver.cpp`.
- Direct source-facing method name: prefer `DATFileResolver::~DATFileResolver()` for final C++ because both observed callers are `_DATFileMgr` destructor paths. Keep `Destroy` as the current documentation alias if a mechanical rename is not desired.
- Required supervisor action: update the target/support docs and supervisor-owned memory coverage with the exact text below. I did not edit `by-memory/-coverage-report.md` or any by-* documentation.

IDA MCP was unavailable during this pass (`127.0.0.1:13337` refused connection), so I used incorporated current docs, prior executed B002 [UID:00012F] evidence, local raw IDA export JSON, and `C:\Users\admin\Desktop\CTools\Output\ida\memory\memory.bin` scans. The local evidence was sufficient to revalidate and extend the current page.

## Evidence Sources Checked

- Current docs: target page, [UID:00012F] `_DATFileMgrRawDestructor`, [UID:00012B] `DATManagers`, [UID:00003J] `DATFileResolver`, [UID:000004] `_DATFileMgr`, [UID:0000IO] `DATFileMgr`, [UID:0000IP]/[UID:00003K] `DATIndexVector`, [UID:0000OA] `StringBase`, [UID:0002RN] `StringBaseShareAssignAndAccess`, [UID:0002RT] `StringBaseReleaseAndCapacity`, and [UID:0002MB] `_DATFileMgrVtableData`.
- Prior executed B-agent lead: `Agent-B002/research/executed/00012F-datfilemgr-raw-destructor-source-quality.md`.
- Raw export JSON: `0x0049bd30`, `0x0049c800`, `0x0049cad0`, `0x0049cbb0`, `0x0049ce50`, `0x0049d0d0`, `0x0049d180`, `0x0049d190`, `0x0049d270`, `0x0049d280`, `0x0049d3d0`, `0x0049d490`, `0x0049d4f0`, `0x0049d5e0`, `0x00582b70`, `0x005833a0`, and `0x005c7526`.
- Raw memory image: `C:\Users\admin\Desktop\CTools\Output\ida\memory\memory.bin`, using segment base `0x00401000` from `raw_ida_export_data/segments/segments.json`.
- Numeric conversions: `0xdc`/220, `0x1f`/31, `0x1000`/4096, `0x14`/20, `0x18`/24, `0x20`/32, `0x30`/48, and `0x3f800000`/1065353216 were verified with `tools/int_convert.py`.

## Boundary / Bytes / Reachability

The target half-open range is exactly `0x0049d190-0x0049d26c`, size `0xdc` / 220 bytes (Verified with `int_convert.py`). The raw export reports `sub_49D190`, signature `void __thiscall(void ***this)`, size 220, with `xrefs_to` only from `0x0049c7e8` and `0x0049d462`.

Memory bytes confirm the range starts at `0x0049d190` with a normal prologue (`56 8b f1`) and ends at the `5f 5b c3` return through `0x0049d26b`. The apparent `0xcc` bytes at `0x0049d1e9-0x0049d1ef` and `0x0049d210-0x0049d21f` are inside the modeled function extent and separate cold/internal blocks; they are not external padding.

Adjacent boundary map:

| Range | Evidence / decision |
| --- | --- |
| `0x0049d180-0x0049d18b` | Prior helper `sub_49D180`, 11 bytes, clears `g_pDATFileMgr` / `0x0067ab40`. |
| `0x0049d18b-0x0049d190` | Five `0xcc` bytes before the target. |
| `0x0049d190-0x0049d26c` | Target resolver cleanup/destructor, 220 bytes. |
| `0x0049d26c-0x0049d270` | Four `0xcc` bytes after the target. |
| `0x0049d270-0x0049d275` | Separate 5-byte thunk `sub_49D270`, tail-jumps to `0x00582b70`; has broad EH jump fan-in unrelated to DAT resolver ownership. |
| `0x0049d275-0x0049d280` | Eleven `0xcc` bytes. |
| `0x0049d280-0x0049d2cc` | `File` scalar deleting destructor, vtable-referenced at `0x00618924`; not part of this target. |
| `0x0049d2cc-0x0049d2d0` | Four `0xcc` bytes before `DATFileContainer` scalar deleting destructor. |

Route checks from `memory.bin`:

- VA pointer pattern hits for `0x0049d190`: `0`.
- Direct `E8/E9 rel32` hits to `0x0049d190`: `2`, at `0x0049c7e8` and `0x0049d462`.
- Positive controls worked: `0x0049d280` has a VA pointer at `0x00618924`, `0x0049d2d0` at `0x0061891c`, and `0x0049d3d0` at `0x006189cc`.
- Additional positive controls: `0x006189cc` appears as an immediate in the `_DATFileMgr` vtable stores at `0x0049bda3`, `0x0049c757`, and `0x0049d3df`; direct rel32 scan found 411 calls/jumps to `0x00582b70` and 617 calls to `0x005c7526`.

Best reachability inference: this target is reached only through `_DATFileMgr` teardown. The raw ordinary destructor [UID:00012F] has no direct inbound route but calls this target at `0x0049c7e8`; the virtual/scalar deleting destructor is the vtable route at `0x006189cc -> 0x0049d3d0` and calls this target at `0x0049d462`.

## Behavior And Layout

Constructor context at `0x0049bd30` allocates a `0x30` / 48-byte `_DATFileMgr` object (Verified with `int_convert.py`), installs the `_DATFileMgr` vtable, initializes the resolver subobject at `_DATFileMgr + 4`, allocates the 0x14-byte sentinel through `0x0049d490`, writes `0x3f800000` / 1065353216 as float `1.0f` (Verified with `int_convert.py`), calls `0x00423b00` to size the bucket vector to 8 bucket records, and clears archive-vector fields at `_DATFileMgr +0x24/+0x28/+0x2c`.

Defensible resolver layout relative to `DATFileResolver`:

| Offset | Source-facing field | Evidence |
| --- | --- | --- |
| `+0x00` | `m_maxLoadFactor` | Constructor writes float `1.0f`; `InsertOrFindEntry` compares `entryCount / bucketCount` against this value before rehash. |
| `+0x04` | `m_entryListSentinel` | Constructor stores the sentinel node from `0x0049d490`; destructor resets `sentinel->next` and `sentinel->prev`, then frees the sentinel. |
| `+0x08` | `m_entryCount` | Constructor clears; load/index increments; duplicate insert decrements; destructor clears. |
| `+0x0c` | `m_bucketsBegin` | Constructor/rehash allocate; destructor frees and clears. |
| `+0x10` | `m_bucketsEnd` | Bucket-vector end pointer; destructor clears with begin/capacity. |
| `+0x14` | `m_bucketsCapacity` | Used by destructor for allocation-size and large-allocation validation. |
| `+0x18` | `m_bucketMask` | `InsertOrFindEntry` and `FindNodeByKey` use `hash & mask`. |
| `+0x1c` | `m_bucketCount` | Rehash load-factor denominator and resize target. |

The required `+0x00/+0x04/+0x08/+0x0c/+0x10/+0x14` fields are therefore not unresolved. The `+0x18/+0x1c` fields are not directly torn down by this function, but sibling helpers prove them and they should be included in the class/support layout to prevent future field-name ambiguity.

Defensible node and bucket structure:

- `DATEntryNode` is `0x14` / 20 bytes (Verified with `int_convert.py`): `+0x00 next`, `+0x04 prev`, `+0x08 keyText` as a 4-byte ref-counted wide `StringBase`/wide-string handle, `+0x0c archiveContainer`, and `+0x10 entryIndex`.
- The sentinel is allocated with the same `0x14` byte node allocator. Its `next`/`prev` are self-linked; payload fields are not source-meaningful.
- `DATBucketRecord` is an 8-byte pair inside the bucket vector. Current best descriptive names are `stopNode` and `linkAnchor` because `InsertOrFindEntry` and `FindNodeByKey` use the first dword as the bucket boundary and the second as a pointer/link anchor for entering the doubly linked list.

Helper roles:

- `0x00582b70` is `sub_582B70`, 54 bytes, a wide release/destructor wrapper forwarding to `0x005833a0` `ReleaseWideBuffer`. It is a broad `StringBase` dependency, not a DAT owner.
- `0x005833a0` performs the actual ref-counted wide-buffer release: skips the wide empty sentinel, calls `InterlockedDecrement(data - 0x0c)`, returns 64/128/256/512 capacity buffers to wide string pools, otherwise heap-frees the 12-byte-prefixed allocation, and resets the handle.
- `0x005c7526` is the shared CRT/free wrapper, decompiled as `void __cdecl sub_5C7526(void *Block) { j_j___free_base(Block); }`. It has broad fan-in and is not an ownership signal.
- The large-allocation branch in `0x0049d190` is MSVC allocator/vector safety behavior: if the bucket storage span rounded by `& 0xfffffffc` is at least `0x1000` / 4096 bytes (Verified with `int_convert.py`), the function checks the back-pointer cookie and rejects a gap greater than `0x1f` / 31 bytes (Verified with `int_convert.py`) before freeing the true base pointer.

## Caller Relationship Revalidated

[UID:00012F] `_DATFileMgrRawDestructor`:

- B002 proved the raw ordinary destructor has no modeled IDA function object and no direct VA/RVA/rel32 inbound route, but its bytes are coherent source-authored destructor semantics.
- It restores `_DATFileMgr` vtable `0x006189cc`, tears down archive-container vector fields `_DATFileMgr +0x24/+0x28/+0x2c`, then calls this resolver cleanup at `0x0049c7e8` on `this + 4`.
- This validates target ownership as `_DATFileMgr` embedded-member teardown, not a standalone public API.

`_DATFileMgr::DeletingDestructor` at `0x0049d3d0`:

- Raw export reports size `0xb8` / 184 bytes, vtable data xref from `0x006189cc`, and calls this target at `0x0049d462`.
- It performs the same archive-vector cleanup and resolver cleanup, then conditionally frees `this` when the delete flag is set.
- The vtable page [UID:0002MB] correctly treats `0x006189cc -> 0x0049d3d0` as the scalar deleting destructor route. This target is the non-virtual embedded member destructor/callee, not a vtable slot.

## Ownership / Source Placement Ranking

1. [UID:0000IO] `DATFileMgr` / `NexusTK/archive/DATFileMgr.cpp` source root, with [UID:00003J] `DATFileResolver` as an internal helper/member type. This is the best route. The constructor, load/find/insert helpers, both destructors, singleton, vtables, archive-vector fields, and resolver fields all sit in the manager cluster and current generated coverage already emits the target through `archive/DATFileMgr.cpp`.
2. [UID:000004] `_DATFileMgr` class. This is the direct containing class and lifetime owner. It should be documented as the embedding owner, but changing the target canonical owner from [UID:00003J] is unnecessary because the target is specifically the resolver subobject's destructor body.
3. Standalone `DATFileResolver.cpp`. Rejected. No constructor, public API callers, vtable, singleton, file-local string, or non-manager route supports a separate original source file. The class page should remain an internal helper/member documentation page.
4. [UID:0000IP]/[UID:00003K] `DATIndexVector`. Rejected. It shares resize/fill helper `0x00423b00`, but DATIndexVector is an integer-key/FNV-style reusable helper with minimap, fitting-room, and monster-image callers. The resolver hashes UTF-16 names with `hash = ch + 5 * hash` and is manager-private.
5. [UID:0000OA] `StringBase` / [UID:0000OB] `StringUtil`. Rejected as owner. They explain `keyText` storage and `0x00582b70`, but those are dependencies only.
6. [UID:0000KR] `LinkedList`. Rejected as owner. The circular sentinel/list mechanics are generic, but the bucket vector, hash, payload fields, and callers are DAT-manager specific.
7. [UID:0000IM] `DATArchive` umbrella or no-owner/ignored. Rejected. A concrete `DATFileMgr.cpp` source root exists and the target is source-required teardown, not padding, runtime-only filler, or coverage-only evidence.

## First-Draft C++ Recommendation

The formal `RECONSTRUCTION_CPP CODE` block should be populated for [UID:00012H]. This target is now above the active `(completion + confidence) / 2 > 85` threshold, has a nonblank owner/emitter route, and the prior blockers can be closed with target-specific evidence:

- Generated helper names are replaceable: `sub_582B70` is a wide `StringBase` release/destructor wrapper, `sub_5C7526` is a heap/free wrapper, and the large-allocation check is allocator policy.
- Field names are defensible from constructor/load/find/insert/destructor context, not only from the generated `class_DATFileResolver.cpp`.
- The source shape is a destructor or private cleanup method for an internal member type in `DATFileMgr.cpp`. The exact original spelling is not proven, but `DATFileResolver::~DATFileResolver()` is more source-facing than `sub_49D190` or bare `Destroy`.

Recommended first-draft C++ for the formal block:

```cpp
struct DATBucketRecord;
struct DATEntryNode;

static void FreeHeapBlock(void *block);
static void InvalidParameterNoInfoNoReturn();

static void FreeMsvcVectorStorage(void *first, void *capacity)
{
    char *begin = (char *)first;
    char *end = (char *)capacity;
    void *block = first;
    unsigned int span = ((unsigned int)(end - begin)) & 0xfffffffcU;

    if (span >= 0x1000U) {
        void *base = *((void **)first - 1);
        if ((unsigned int)(begin - (char *)base - 4) > 0x1fU)
            InvalidParameterNoInfoNoReturn();
        block = base;
    }

    FreeHeapBlock(block);
}

DATFileResolver::~DATFileResolver()
{
    if (m_bucketsBegin != 0) {
        FreeMsvcVectorStorage(m_bucketsBegin, m_bucketsCapacity);
        m_bucketsBegin = 0;
        m_bucketsEnd = 0;
        m_bucketsCapacity = 0;
    }

    DATEntryNode *sentinel = m_entryListSentinel;
    DATEntryNode *node = sentinel->next;

    sentinel->next = sentinel;
    sentinel->prev = sentinel;
    m_entryCount = 0;

    while (node != sentinel) {
        DATEntryNode *next = node->next;
        node->entryName.~WideString();
        FreeHeapBlock(node);
        node = next;
    }

    FreeHeapBlock(sentinel);
}
```

Implementation notes for incorporation:

- `WideString` should resolve to the project's pointer-backed wide `StringBase` facade or equivalent 4-byte wide string handle. Do not use a raw `wchar_t *` field in final headers unless the wider string-family audit explicitly chooses that facade spelling.
- `FreeMsvcVectorStorage` can be folded into an existing allocator/vector helper if one is already declared by the source root. The important source behavior is the MSVC large-allocation cookie check, not the helper name.
- If the supervisor prefers keeping the method label `Destroy`, the body can be emitted as `void DATFileResolver::Destroy()` with the same content, but the destructor name better explains the two `_DATFileMgr` teardown callers.

## Heuristic / Inference Reanalysis And Validation

### Exact Range And Split

- Evidence checked: target page, raw export `0x0049d190.json`, `memory.bin` bytes, `0x0049d180.json`, `0x0049d270.json`, `0x0049d280.json`, and current aggregate docs.
- Rejected alternatives: extending the target through `0x0049d2d0`; splitting internal `0xcc` blocks out of `0x0049d190`; treating `0x0049d270` as part of resolver cleanup.
- Best inference: target remains `0x0049d190-0x0049d26c`; after-boundary support docs should explicitly split padding, `0x0049d270` string-release thunk, `0x0049d280` File scalar deleting destructor, and padding before `0x0049d2d0`.
- Impact: raises score because boundary/padding is more exact; no target split/rename needed; C++ readiness improves because no extra successor helper is being hand-ported as resolver code.

### Reachability And Caller Model

- Evidence checked: raw export xrefs to target, `memory.bin` VA/pointer/rel32 scan, B002 [UID:00012F] raw destructor evidence, `_DATFileMgr` vtable page, and scalar deleting destructor export.
- Rejected alternatives: hidden pointer-table route to `0x0049d190`; direct callers beyond the two destructor paths; treating the raw ordinary destructor no-route state as evidence against this target.
- Best inference: two direct calls only, both from `_DATFileMgr` destructors; indirect external reachability is through `_DATFileMgr` vtable slot `0x006189cc -> 0x0049d3d0 -> 0x0049d190`.
- Impact: ownership stays in DAT manager; C++ should be destructor/member cleanup, not public free function or callback.

### Resolver Field Names

- Evidence checked: constructor `0x0049bd30`, load/index `0x0049c800`, insert/find `0x0049ce50`, remove helper `0x0049d0d0`, node allocator `0x0049d490`, node free helper `0x0049d4f0`, lookup `0x0049d5e0`, and target destructor.
- Rejected alternatives: leaving `+0x04-+0x23` as unresolved bytes; using only generated `mbr_0x*` names; using DATIndexVector field names wholesale.
- Best inference: field map is `m_maxLoadFactor`, `m_entryListSentinel`, `m_entryCount`, `m_bucketsBegin`, `m_bucketsEnd`, `m_bucketsCapacity`, `m_bucketMask`, and `m_bucketCount`.
- Impact: removes the formal field-name blocker for this target and justifies a completion raise. Confidence still stays below final because original header spelling is not proven.

### Node And Key Type

- Evidence checked: `CreateEntryNode` writes key at node `+0x08`, archive pointer at `+0x0c`, entry index at `+0x10`; destructor releases `node + 2` through `0x00582b70`; StringBase docs identify `0x00582b70` as a wide release wrapper.
- Rejected alternatives: node key as ordinary borrowed `const wchar_t *`; node owner as StringBase; sentinel as a different node type requiring a split.
- Best inference: node field `+0x08` is a 4-byte ref-counted wide string handle, source-facing as `WideString entryName` or `mystr::StringBase<wchar_t,...> entryName`; sentinel uses the same 0x14-byte allocation but only the links matter.
- Impact: source field/type naming is good enough for first-draft C++; exact final string typedef remains a support-level string-family issue, not a blocker for this cleanup body.

### Helper Names

- Evidence checked: raw exports for `0x00582b70`, `0x005833a0`, and `0x005c7526`, plus StringBase support docs.
- Rejected alternatives: treating `sub_582B70` as DAT-specific; treating `sub_5C7526` as source owner; leaving compiler names in final report.
- Best inference: use `ReleaseWideString` / wide `StringBase` destructor for `0x00582b70` and `FreeHeapBlock` / allocator free for `0x005c7526`.
- Impact: helper-name blocker is resolved for first-draft source. Confidence remains capped because exact public `StringBase` API spelling is outside this target.

### DATFileResolver Class Reality

- Evidence checked: no standalone constructor function, no standalone vtable, no direct non-manager callers, constructor initializes subobject inline at `_DATFileMgr+4`, both destructors call cleanup on `_DATFileMgr+4`, and manager load/find/insert helpers are the only behavioral context.
- Rejected alternatives: standalone `DATFileResolver.cpp`; no-owner/generated-only; folding into DATIndexVector.
- Best inference: `DATFileResolver` is a defensible internal helper/member type or type alias inside `DATFileMgr.cpp`. It is not proven as a separately compiled project class file. Keeping [UID:00003J] as canonical method owner is still useful because the subobject has a coherent destructor and layout.
- Impact: metadata owner/emitter can remain as-is; support docs should close the open "standalone or internal member" question in favor of internal member/helper. No split/range change.

### Final C++ Readiness

- Evidence checked: current blank target C++ rationale, class page blank rationale, generated `class_DATFileResolver.cpp`, raw export behavior, and source gate rules.
- Rejected alternatives: withhold all C++ solely because original names are not 95% proven; emit a standalone `DATFileResolver.cpp`; emit generated modern/scaffolded code verbatim.
- Best inference: populate first-draft destructor C++ on the target page, but keep it explicitly first-draft and attached to `DATFileMgr.cpp` internal helper/member source. Do not populate aggregate [UID:00012B] or broad class/file pages with final code yet.
- Impact: target can rise to `86/90`; support pages can keep broader final-source caveats.

## Metadata Recommendations

Target [UID:00012H]:

```text
*** COMPLETION:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:00003J | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:00003J | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
```

Populate the formal C++ block with the first-draft destructor body above, adjusted to local style if the supervisor wants `Destroy` instead of `~DATFileResolver`.

Support [UID:00003J] `DATFileResolver`:

- Recommended score: raise from `85/88` to `86/89`.
- Keep `CANONICAL_OWNER:0000IO`, `RECONSTRUCTABLE:TRUE`, and `EMITTER_UIDS:0000IO`.
- Rationale: this pass resolves the field map and source-shape blocker enough to document the internal helper/member type, while still capping below final because exact original type spelling and header/API exposure are not proven.

No score changes are required for [UID:000004] `_DATFileMgr`, [UID:0000IO] `DATFileMgr`, or [UID:00012B] `DATManagers`, but their open source-shape text should be updated so this target does not keep reappearing as a bare blocker.

## Exact Support-Doc Incorporation Plan

### Target Page [UID:00012H]

Replace the current final-C++ bullet in `## Status` with:

```text
- Final C++ should now be populated as a first-draft internal `DATFileResolver` destructor/cleanup body. The remaining caveat is exact original type/API spelling, not target-specific behavior, field layout, ownership, or helper identity.
```

Replace the current confidence bullet with:

```text
- Confidence: strong for modeled function range, bytes, cleanup behavior, two destructor callers, resolver/hash-table layout, helper roles, and DATFileMgr.cpp ownership; medium-high for exact original internal helper type spelling.
```

Replace the current layout table with:

```text
| Offset | Role |
| --- | --- |
| `+0x00` | `m_maxLoadFactor`; constructor writes `1.0f`, insert/rehash checks `entryCount / bucketCount` against it. |
| `+0x04` | `m_entryListSentinel`; 0x14-byte circular-list sentinel node. |
| `+0x08` | `m_entryCount`; cleared by this cleanup and updated by insert/remove paths. |
| `+0x0c` | `m_bucketsBegin`; bucket-record vector begin. |
| `+0x10` | `m_bucketsEnd`; bucket-record vector end. |
| `+0x14` | `m_bucketsCapacity`; bucket-record vector capacity, used by the large-allocation free check. |
| `+0x18` | `m_bucketMask`; sibling find/insert helpers use `hash & mask`. |
| `+0x1c` | `m_bucketCount`; sibling insert/rehash helpers use it as the load-factor denominator. |
```

Replace the current `## IDA MCP Boundary Evidence` table with the boundary table from this report's `Boundary / Bytes / Reachability` section, including the separate `0x0049d270` and `0x0049d280` successor ranges.

Append to `## Source Reconstruction Notes`:

```text
2026-06-18 B005 source-quality reanalysis closes the target-specific C++ blockers. The best source-facing spelling is an internal helper/member destructor, `DATFileResolver::~DATFileResolver()`, in `DATFileMgr.cpp`; `Destroy` may remain as a documentation alias if the page title is kept stable. `DATFileResolver` is not supported as a standalone source file, but the subobject layout and destructor body are strong enough for first-draft C++ on this exact target.

Use the field names `m_maxLoadFactor`, `m_entryListSentinel`, `m_entryCount`, `m_bucketsBegin`, `m_bucketsEnd`, `m_bucketsCapacity`, `m_bucketMask`, and `m_bucketCount`. Use `DATEntryNode` for the 0x14-byte list node with `next`, `prev`, wide-string `entryName`, `archiveContainer`, and `entryIndex`. Treat `0x00582b70` as the wide StringBase/string-handle release wrapper and `0x005c7526` as the heap free wrapper; neither helper is DAT ownership evidence.
```

Append to `## Changes`:

```text
- 2026-06-18 B005 source-quality reanalysis:
  - Before: score `84/88`; final C++ was blank because generated helper names, resolver field names, and source-level helper/class shape were not finalized.
  - Recommended after: score `86/90`; metadata owner/emitter remain [UID:00003J][DATFileResolver](by-class/DATFileResolver.md), reconstructable stays true, and first-draft C++ should be populated.
  - Summary/evidence: raw export and `memory.bin` rechecks confirm the exact `0xdc` / 220-byte body, five-byte predecessor padding, four-byte successor padding before a separate `0x0049d270` string-release thunk, only two direct call routes at `0x0049c7e8` and `0x0049d462`, zero VA pointer hits to the target start, and positive vtable/pointer controls for adjacent destructors. Constructor, load/find/insert, and cleanup helpers resolve the resolver fields through `+0x1c`, the 0x14-byte node layout, the wide StringBase key release helper, and the MSVC large-allocation free policy. Best source shape is an internal `DATFileResolver` member destructor in `DATFileMgr.cpp`, not standalone `DATFileResolver.cpp`.
```

### [UID:00003J] `DATFileResolver`

Replace the `Source-facing placement` bullet with:

```text
- Source-facing placement: internal helper/member type embedded in [UID:000004][_DATFileMgr](by-class/_DATFileMgr.md) and emitted through [UID:0000IO][DATFileMgr](by-file/DATFileMgr.md), not a standalone original `DATFileResolver.cpp`.
```

Replace the reconstructable/final C++ status bullet with:

```text
- Reconstructable: true as DAT manager project code. The exact cleanup child [UID:00012H] is now first-draft C++ ready as `DATFileResolver::~DATFileResolver()` / cleanup, while this class page should keep broad final C++ blank until the full manager header/source declaration is coordinated.
```

Replace the sentence beginning `This may not have been...` with:

```text
This was likely an embedded helper object or STL-like hash/list member inside `_DATFileMgr`. Current evidence supports keeping `DATFileResolver` as the source-facing internal helper type name for reconstruction, but not as a separate project feature or separate source file.
```

Add `+0x18` and `+0x1c` rows to the layout table:

```text
| `+0x18` | bucket mask used by `FindNodeByKey` and `InsertOrFindEntry` | `+0x1c` |
| `+0x1c` | bucket count / max bucket index used by load-factor rehash | `+0x20` |
```

Replace the method row with:

```text
| `~DATFileResolver` / `Destroy` | [UID:00012H][0x0049d190-0x0049d26c.DATFileResolverDestroy](by-memory/0x0049d190-0x0049d26c.DATFileResolverDestroy.md) | Destructor-style cleanup called from both `_DATFileMgr` teardown bodies; frees bucket storage, walks entry nodes, releases wide-string keys, frees nodes, and frees the sentinel. |
```

Append to `## Changes`:

```text
- 2026-06-18 B005 source-quality reanalysis: recommend raising from `85/88` to `86/89`. Raw export, local byte scans, constructor context, find/insert helpers, and target destructor behavior resolve the field map through `+0x1c` and the source-shape question: keep `DATFileResolver` as an internal `_DATFileMgr` helper/member type in `DATFileMgr.cpp`, not as a standalone file. The exact cleanup child [UID:00012H] is first-draft C++ ready; the broader class page remains below final-source C++ because exact original type/header spelling is still not proven.
```

### [UID:000004] `_DATFileMgr`

Replace the `0x04-0x23` layout row with:

```text
| `0x04-0x23` | embedded `DATFileResolver` name-index state: `m_maxLoadFactor`, `m_entryListSentinel`, `m_entryCount`, `m_bucketsBegin`, `m_bucketsEnd`, `m_bucketsCapacity`, `m_bucketMask`, and `m_bucketCount` | medium-high |
```

Append to `## Evidence Notes`:

```text
- 2026-06-18 B005 reanalysis of [UID:00012H] resolves the embedded resolver field map and source shape. The resolver subobject begins at `_DATFileMgr + 4`; constructor `0x0049bd30` initializes a 0x14-byte sentinel, max load factor `1.0f`, and an initial 8-bucket vector, while load/find/insert helpers prove bucket mask/count at resolver `+0x18/+0x1c`. Treat the cleanup body at `0x0049d190` as the internal `DATFileResolver` destructor/member cleanup, not standalone `DATFileResolver.cpp`.
```

### [UID:0000IO] `DATFileMgr`

Replace the proposed contents note for [UID:00003J] with:

```text
| [UID:00003J][DATFileResolver](by-class/DATFileResolver.md) | [UID:00012H][0x0049d190-0x0049d26c.DATFileResolverDestroy](by-memory/0x0049d190-0x0049d26c.DATFileResolverDestroy.md) | `archive/DATFileMgr.cpp` internal helper/member | Embedded resolver/hash-table member; source-facing cleanup is best represented as `DATFileResolver::~DATFileResolver()` / cleanup, not as a separate `DATFileResolver.cpp`. |
```

Replace the open question:

```text
- Decide whether `DATFileResolver` should remain as a named class in source or become an internal struct/member in `_DATFileMgr`.
```

with:

```text
- `DATFileResolver` should remain a named internal helper/member type in `DATFileMgr.cpp` for reconstruction. Current evidence rejects a standalone `DATFileResolver.cpp`; exact original header spelling remains reviewable.
```

### [UID:00012B] `DATManagers`

Replace the covered-range role for [UID:00012H] with:

```text
| [UID:00012H][0x0049d190-0x0049d26c.DATFileResolverDestroy](by-memory/0x0049d190-0x0049d26c.DATFileResolverDestroy.md) | `DATFileResolver::~DATFileResolver` / cleanup | Destructor-style cleanup for the embedded `_DATFileMgr + 4` resolver subobject. |
```

Replace the function-map row label for `0x0049d190` similarly:

```text
| `0x0049d190` | `0x0049d190-0x0049d26c` | `DATFileResolver::~DATFileResolver` / cleanup, tracked separately as `UID:00012H` | 2 |
```

Replace the open question:

```text
- Decide whether `DATFileResolver` should remain a source-level class or become an internal helper/struct in the manager header.
```

with:

```text
- Keep `DATFileResolver` as an internal helper/member type in the manager source/header; do not split it to a standalone source file under current evidence.
```

Append to `## IDA MCP Boundary Notes`:

```text
- 2026-06-18 B005 local raw-export/byte recheck refines the post-[UID:00012H] boundary: `0x0049d26c-0x0049d270` is four `0xcc` bytes, `0x0049d270-0x0049d275` is a separate thunk to the wide string release wrapper `0x00582b70`, `0x0049d275-0x0049d280` is eleven `0xcc` bytes, `0x0049d280-0x0049d2cc` is the `File` scalar deleting destructor, and `0x0049d2cc-0x0049d2d0` is four `0xcc` bytes before `DATFileContainer` teardown.
```

## Exact Coverage Row Recommendation

Placement context: replace the current [UID:00012H] row in `by-memory/-coverage-report.md` between [UID:0000VN] `0x0049ce49-0x0049ce50` padding and [UID:00012I] `0x0049d390-0x0049d3cd.FileBaseDestructor`.

Exact replacement row:

```text
    - [UID:00012H][0x0049d190-0x0049d26c.DATFileResolverDestroy](by-memory/0x0049d190-0x0049d26c.DATFileResolverDestroy.md) : reconstructable : 86% : strong : Embedded DAT resolver/hash-table destructor/cleanup; B005 raw-export and memory-byte recheck confirms exact `0xdc` / 220-byte range, predecessor/successor padding and adjacent `0x0049d270` thunk boundary, only two direct destructor callers at `0x0049c7e8` and `0x0049d462`, resolver fields `+0x00` through `+0x1c`, 0x14-byte list nodes, bucket-vector large-allocation guard, wide StringBase key release via `0x00582b70`, heap free wrapper `0x005c7526`, internal `DATFileMgr.cpp` helper/member ownership, and first-draft destructor C++ readiness.
```

## Validation / Expected Generated Impact

Expected after supervisor applies recommendations and validates:

- [UID:00012H] should leave the refreshed low-completion `84/88` queue and become `86/90`.
- [UID:00003J] should become `86/89` if the support-page score recommendation is accepted.
- Generated memory coverage should still route [UID:00012H] as `emits`, owner/emitter `00003J`, generated path `auto-generated/NexusTK/archive/DATFileMgr.cpp`.
- The empty generated file at `auto-generated/NexusTK/archive/DATFileMgr.cpp` is not evidence against this route; it is current generation state, not source ownership evidence.

Suggested supervisor validation commands after applying by-* and coverage edits:

> Executable block R001 was removed from this report and preserved verbatim in [00012H-DATFileResolverDestroy-source-quality-removed.md](00012H-DATFileResolverDestroy-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

## Changed Files

- Created: `tools/leaser/Agents/Agent-B005/research/00012H-DATFileResolverDestroy-source-quality.md`
- Modified by-* docs: none.
- Modified coverage reports: none.
- Modified generated files: none.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B005","command_id":"000000004165","destination_path":"executed-b-agent-research/B005/00012H-DATFileResolverDestroy-source-quality.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:30","uid":"00012H"} -->
<!-- {"agent":"B005","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 00012H-DATFileResolverDestroy-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B005/00012H-DATFileResolverDestroy-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"00012H"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
