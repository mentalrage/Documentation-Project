** TARGET-REPORT-UID:00003K **
** AUTHOR-AGENT-ID:B009 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# 00003K DATIndexVector Class Source-Quality Research

Assignment: `B009-goal2-datindexvector-class-source-quality-00003K-20260619`

This was report-only B-agent work. I did not edit by-* docs, generated coverage reports, generated source, IDA DB files, or `by-memory/-coverage-report.md`.

## Target

- Target UID: [UID:00003K]
- Target path: `E:\NTK\GhidraBridge\source-3\project-documentation\by-class\DATIndexVector.md`
- Required report path: `E:\NTK\GhidraBridge\source-3\project-documentation\tools\leaser\Agents\Agent-B009\research\00003K-DATIndexVector-class-source-quality.md`
- Current target metadata: `COMPLETION:85`, `CONFIDENCE:86`, `CANONICAL_OWNER:0000IP`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000IP`, blank formal C++.
- Current generated route: [UID:0000IP] `by-file/DATIndexVector.md` -> `auto-generated/NexusTK/archive/DATIndexVector.cpp`.

## Executive Recommendation

Raise [UID:00003K] `DATIndexVector` from `85/86` to `88/90`, keep `CANONICAL_OWNER:0000IP`, keep `RECONSTRUCTABLE:TRUE`, and keep `EMITTER_UIDS:0000IP`.

The stale open question about "value-table view versus bucket/list view" can now be resolved at high confidence: the two views are the same original object, not two independent source classes. `DATIndexVector::ResizeAndFill` is the bucket-table resize/fill helper. It treats each bucket as two dword slots (`DATIndexVectorBucket { first, last }`) and fills empty bucket ranges with the list head/sentinel stored at object offset `+0x04`. The older `fillValue` name is an implementation-view alias for `m_listHead`, not evidence of a separate value-vector class.

Recommended final field names for the class page:

| Offset | Recommended field | Type | Evidence |
| --- | --- | --- | --- |
| `+0x00` | `m_maxLoadFactor` | `float` | `InsertNode` compares `nodeCount / bucketCount` against this field before rehash. |
| `+0x04` | `m_listHead` | `DATIndexVectorNode*` | Insert/find/remove use it as the intrusive-list sentinel; destructor passes `this + 4` to `StdListTidy8ByteList`; `ResizeAndFill` uses the same dword as the fill value for empty bucket first/last slots. |
| `+0x08` | `m_nodeCount` | `uint32_t` | Insert/remove update this count and the generic list-state cleanup treats `this+4` as `{ head, count }`. |
| `+0x0c` | `m_bucketsBegin` | `DATIndexVectorBucket*` | Resize/destructor manage the allocation begin; insert/find/remove index buckets from this pointer. |
| `+0x10` | `m_bucketsEnd` | `DATIndexVectorBucket*` | Resize writes active end after `bucketCount * 2` dword fill. |
| `+0x14` | `m_bucketsCapacity` | `DATIndexVectorBucket*` | Resize/destructor manage the allocation capacity/end pointer. |
| `+0x18` | `m_bucketMask` | `uint32_t` | Insert/find/remove mask the FNV-1a hash with this value; `ResizeAndFill` writes `bucketCount - 1`. |
| `+0x1c` | `m_bucketCount` | `uint32_t` | Insert computes load factor against this count; `ResizeAndFill` writes the requested bucket count. |

The class should remain a standalone helper under [UID:0000IP] `DATIndexVector`. Current path `NexusTK/archive/DATIndexVector.cpp` is still the best implementation route because the imported/source-tree evidence names `DATIndexVector.cpp` and archive/DAT manager use is strong. The final folder remains reviewable because caller fanout includes non-DAT systems, but that is not enough to move it to `util/` or `common/` now.

Recommended class/header C++ is now ready as a declaration-level draft. Method bodies should remain on their method pages and should not be inserted into the class page. The class draft should use source-facing names, not the old `DATIndexVectorLayout { fillValue, valuesBegin }` recovery overlay.

## Evidence Checked

Documentation and generated state checked:

- Primary target [UID:00003K] `by-class/DATIndexVector.md`.
- File parent [UID:0000IP] `by-file/DATIndexVector.md`.
- Support structs [UID:0001U0] `by-type/by-struct/DATIndexVectorBucket.md` and [UID:0001U1] `by-type/by-struct/DATIndexVectorNode.md`.
- DATIndexVector method/helper docs:
  - [UID:0002U7] `by-memory/0x004233f0-0x00423465.DATIndexVectorFillValueRangeHelper.md`
  - [UID:0000WW] `by-memory/0x00423b00-0x00423c3d.DATIndexVectorResizeAndFill.md`
  - [UID:0000XS] `by-memory/0x00457100-0x0045730f.DATIndexVectorInsertNode.md`
  - [UID:0000XT] `by-memory/0x00457310-0x004573b3.DATIndexVectorRemoveNodeHelper.md`
  - [UID:0000XU] `by-memory/0x004573d0-0x00457429.DATIndexVectorDestructor.md`
  - [UID:0000XX] `by-memory/0x00457580-0x00457613.DATIndexVectorFindNodeByKey.md`
- Generic list support docs:
  - [UID:0000KR] `by-file/LinkedList.md`
  - [UID:0000XR] `by-memory/0x004570e0-0x00457100.StdListBuyNodeWithPayload8.md`
  - [UID:0000XV] `by-memory/0x00457430-0x00457473.StdListTidy8ByteList.md`
  - [UID:0000XW] `by-memory/0x00457550-0x0045757d.StdListBuyNode8.md`
  - [UID:0001UZ] `by-type/by-struct/LinkedListState.md`
  - [UID:0001V0] `by-type/by-struct/ListNode.md`
- Source-layout and container context:
  - `by-project-structure/proposed-source-tree.md`
  - [UID:0001QA] `by-meta/client_containers.md`
  - `wave3_data_issues.md` DATIndexVector notes.
- Prior reports used as leads:
  - B001 executed linked-list helper report `0000XR-0000XV-0000XW-linkedlist-node-helpers-source-quality.md`
  - B002 executed minimap report `0002JL-0002JM-0000XQ-minimap-version-manager-source-quality.md`
  - B002 executed `_DATFileMgr` raw destructor report `00012F-datfilemgr-raw-destructor-source-quality.md`
- Generated outputs and reports:
  - `auto-generated/NexusTK/archive/DATIndexVector.cpp`
  - `source-3/simroot_v2/class_DATIndexVector.cpp`
  - `auto-generated/-ag-class-coverage.md`
  - `auto-generated/-ag-file-coverage.md`
  - `auto-generated/-ag-type-coverage.md`
  - `auto-generated/-ag-memory-coverage.md`
  - `by-class/-coverage-report.md`
  - `by-file/-coverage-report.md`
  - `by-type/by-struct/-coverage-report.md`
  - `by-memory/-coverage-report.md`

I did not run new live IDA MCP commands in this report-only turn because no IDA MCP connector/tool is exposed in the current session. The report rechecks and reconciles the current by-* docs' saved live IDA evidence, prior executed B reports, generated output, coverage rows, and source-tree context. This limits final confidence to `90`, not because the layout evidence is weak, but because no fresh IDA session was available to rename/type directly during this pass.

## Current Function And Support Inventory

| UID | Range / item | Current score | Source-quality conclusion |
| --- | --- | ---: | --- |
| [UID:0002U7] | `0x004233f0-0x00423465` fill-value range helper | `85/88` | DATIndexVector-private/static DWORD range fill support called only from `ResizeAndFill`; can be inlined into `ResizeAndFill` in final source. |
| [UID:0000WW] | `0x00423b00-0x00423c3d` resize/fill | `85/90` | Bucket-table resize/fill, not a separate value-vector class. It grows/fills `DATIndexVectorBucket[]` as paired dword slots initialized to `m_listHead`. |
| [UID:0000XS] | `0x00457100-0x0045730f` insert | `86/90` | Source-owned keyed insert/duplicate/rehash method. It is the primary bucket/list algorithm body. |
| [UID:0000XT] | `0x00457310-0x004573b3` remove helper | `85/90` | DATIndexVector-private cleanup helper; current best descriptive name remains `DATIndexVectorRemoveNodeHelper`, with `RemoveNodeForInsertUnwind` as a more specific but less proven source-facing name. |
| [UID:0000XU] | `0x004573d0-0x00457429` destructor | `85/90` | Source-owned destructor body for bucket allocation plus generic list-state teardown; not generic `LinkedList` ownership. |
| [UID:0000XX] | `0x00457580-0x00457613` find | `85/90` | Keyed lookup over the same FNV-1a bucket ranges. |
| [UID:0001U0] | `DATIndexVectorBucket` | `85/90` | Two pointer range `{ first, last }` over the intrusive list; likely implementation struct. |
| [UID:0001U1] | `DATIndexVectorNode` | `85/89` | 16-byte semantic node overlay `{ next, prev, key, value }`; source visibility remains partly inferred because it overlaps MSVC list node internals. |

Boundary facts from saved live IDA evidence:

- `DATIndexVectorFillValueRangeHelper`: `0x004233f0-0x00423465`, size `0x75` / 117 bytes, no callees, two callers inside `ResizeAndFill`.
- `DATIndexVectorResizeAndFill`: `0x00423b00-0x00423c3d`, size `0x13d` / 317 bytes, fourteen callers across fitting-room, minimap, DAT manager, MonsterImageLib, and rehash.
- `DATIndexVectorInsertNode`: `0x00457100-0x0045730f`, size `0x20f` / 527 bytes, previous `StdListBuyNodeWithPayload8` ends exactly at `0x00457100`, one `0xcc` byte before the remove helper.
- `DATIndexVectorRemoveNodeHelper`: `0x00457310-0x004573b3`, size `0xa3` / 163 bytes, one caller at `0x00457301` from `InsertNode` cleanup.
- `DATIndexVectorDestructor`: `0x004573d0-0x00457429`, size `0x59` / 89 bytes, tail-jumps to `StdListTidy8ByteList`.
- `DATIndexVectorFindNodeByKey`: `0x00457580-0x00457613`, size `0x93` / 147 bytes.

## Heuristic / Inference Reanalysis And Validation

### 1. Value-table view versus bucket/list view

Best conclusion: one original `DATIndexVector` object, not two source classes and not an accidental merge.

Evidence:

- `ResizeAndFill` takes a requested logical `entryCount`, doubles it to a dword count, and fills that range with object offset `+0x04`.
- Insert/find/remove interpret the bucket allocation at `+0x0c` as 8-byte buckets, i.e. two dword pointer slots per bucket.
- Empty bucket first/last pointers are the list sentinel at object offset `+0x04`. Therefore the "fill value" is exactly the empty-bucket sentinel/list head.
- `ResizeAndFill` writes `entryCount - 1` to `+0x18`, which insert/find/remove use as the bucket mask.
- `ResizeAndFill` writes `entryCount` to `+0x1c`, which insert uses as `m_bucketCount` for load-factor calculations.
- Destructor frees/clears the `+0x0c/+0x10/+0x14` allocation triple and then passes `this + 4` to the generic list cleanup helper. That matches one object layout: list state at `+0x04/+0x08`, bucket vector at `+0x0c/+0x14`.

Rejected alternatives:

- Separate `DATIndexVectorLayout` value-vector class: rejected. The so-called values are bucket first/last pointer slots; no caller evidence supports a separate `uint32_t` value table with independent semantics.
- Two adjacent helper templates collapsed by recovery: rejected for the class-level model. The same object offsets are used coherently by resize, insert, remove, find, and destructor.
- `ResizeAndFill` as fitting-room category storage: rejected. It has fourteen callers and writes the same bucket-mask/count fields used by the DATIndexVector algorithms.

Source-quality impact:

- Replace old `scalar00/fillValue/reserved08/valuesBegin/valuesEnd/valuesCapacity/lastIndex/entryCount` as the primary class layout.
- Keep those names only as historical recovery aliases, explicitly superseded by the bucket/list layout.
- `ResizeAndFill` should be described as bucket-table resize/fill. If a method-body C++ pass happens later, source-facing signature should likely be `void ResizeAndFill(int bucketCount)` because no documented caller consumes the incidental `EAX = bucketCount - 1` value. The binary leaves that value in `EAX`, but the source contract appears side-effect based.

### 2. Generic linked-list boundary

Best conclusion: generic MSVC/Dinkumware list helpers are non-emitting compiler/STL support, but `DATIndexVector` owns the higher-level keyed bucket algorithm and the semantic node/bucket overlays needed for reconstructed source.

Evidence:

- B001 reclassified `StdListBuyNode8`, `StdListBuyNodeWithPayload8`, and `StdListTidy8ByteList` as non-emitting MSVC/Dinkumware `std::list<T>` support based on `"list<T> too long"` diagnostics, runtime `operator new`/free thunks, and unrelated typed consumers.
- `DATIndexVectorDestructor` tail-calls `StdListTidy8ByteList(this + 4)`, proving the object embeds an STL-list-like state at `+0x04`, but it first frees the DATIndexVector bucket allocation at `+0x0c/+0x10/+0x14`.
- `DATIndexVectorInsertNode`, `RemoveNodeHelper`, and `FindNodeByKey` do not just allocate/free list nodes. They hash four-byte keys, choose buckets, maintain bucket first/last ranges, duplicate-collapse nodes, and trigger bucket-table rehash.

Rejected alternatives:

- Move DATIndexVector children to [UID:0000KR] `LinkedList`: rejected. `LinkedList` only covers generic compiler/STL helper bodies as non-emitting support.
- Emit `StdListNode8` and `StdList8State` as custom project types inside `DATIndexVector`: rejected. The B001 report and updated support docs classify those as binary overlays, not source-authored NexusTK structs.
- Ignore `DATIndexVectorNode` because it overlaps list-node internals: rejected for documentation/reconstruction. Consumers and helper bodies use a semantic `{ key, value }` payload over that node shape; the node overlay is needed to explain `FindNodeByKey` return values and caller payloads.

Source-quality impact:

- Keep `DATIndexVectorNode` as a DATIndexVector-owned semantic node overlay, while noting it is a source reconstruction/descriptive type and may correspond to a `std::list` node/payload in original compiler output.
- Keep `DATIndexVectorBucket` as the DATIndexVector-owned two-pointer bucket range.
- Do not move or duplicate `StdList*` helpers into `DATIndexVector.cpp`.

### 3. Final field names and struct names

Best current names:

```cpp
struct DATIndexVectorNode {
    DATIndexVectorNode* next;
    DATIndexVectorNode* prev;
    int key;
    void* value;
};

struct DATIndexVectorBucket {
    DATIndexVectorNode* first;
    DATIndexVectorNode* last;
};

class DATIndexVector {
    float m_maxLoadFactor;
    DATIndexVectorNode* m_listHead;
    unsigned int m_nodeCount;
    DATIndexVectorBucket* m_bucketsBegin;
    DATIndexVectorBucket* m_bucketsEnd;
    DATIndexVectorBucket* m_bucketsCapacity;
    unsigned int m_bucketMask;
    unsigned int m_bucketCount;
};
```

Evidence:

- `m_listHead` is the lower-churn source-facing name because current generated/source docs use `listHead`, minimap docs use `m_versionListHead`, and the field behaves as the list head/sentinel.
- `m_sentinel` would also be accurate, but using it as the final field name would force more churn across existing support docs. Recommended docs should say "list head/sentinel" once and use `m_listHead` consistently.
- `DATIndexVectorNode::value` should remain a `void*` or caller-specific payload pointer. MiniMap uses it as an expected version string, MonsterImageLib uses it as archive-reader/bounds-bucket payload, and DAT manager likely uses it as a DAT-entry/container payload. A single narrower type would be wrong.
- `DATIndexVectorNode::key` is a four-byte integer. FNV-1a hashes exactly four bytes and lookup compares the stored dword.
- `DATIndexVectorBucket::first/last` are not node-owned fields and not a count/hash record. Insert/find/remove prove they are range boundaries inside one intrusive list.

Rejected alternatives:

- `fillValue` at `+0x04`: keep only as a recovery alias. It is `m_listHead` used as the fill source for empty buckets.
- `reserved08` at `+0x08`: rejected. It is live `m_nodeCount`.
- `valuesBegin/valuesEnd/valuesCapacity`: use only as historical aliases. The source-facing allocation is `m_bucketsBegin/m_bucketsEnd/m_bucketsCapacity`.
- Generic `HashNode` or `IndexNode`: plausible but lower confidence than current DATIndexVector names because the imported/source tree and docs consistently use DATIndexVector, while no original generic type symbol survives.

### 4. Source placement and owner/emitter route

Ranked source placement:

1. [UID:0000IP] `DATIndexVector` / `NexusTK/archive/DATIndexVector.cpp`: accepted. Imported/source-tree evidence names `DATIndexVector.cpp`, the current validator route is valid, and DAT manager use is strong. Broad caller fanout means standalone, not manager-private.
2. `util/` or `common/` container source: plausible but not selected now. Non-DAT callers support a future folder move, but there is no stronger source-layout clue than the current `DATIndexVector.cpp` route.
3. [UID:0000IO] `DATFileMgr.cpp`: rejected. `ResizeAndFill`, `InsertNode`, and `FindNodeByKey` are reached from MiniMapVersionManager and MonsterImageLib, not just DAT manager code.
4. [UID:0000KR] `LinkedList`: rejected. It owns only non-emitting STL list support overlays/helpers.
5. Consumer-specific owners (`MiniMapVersionManager`, `MonsterImageLib`, fitting-room item-state helpers): rejected. They consume embedded indices and payloads; they do not own the reusable class.

Owner/emitter recommendation:

- [UID:00003K] should keep `CANONICAL_OWNER:0000IP` and `EMITTER_UIDS:0000IP`.
- [UID:0000IP] may stay at path `NexusTK/archive/`.
- Support docs should say `archive/` is a current reconstruction path, not proven original folder. The original project could still have kept this in a common container folder, but changing path now would be less supported than retaining current route.

### 5. Caller fanout

The caller spread supports standalone helper ownership:

- `ResizeAndFill` has fourteen saved live caller sites:
  - fitting-room item-state/category paths: `0x004220cc`, `0x0042257e`, `0x004235ea`
  - minimap version-manager construction/teardown/rehash: `0x00456464`, `0x00456509`, `0x0045677a`, `0x004572a0`, `0x00457509`
  - DAT manager code: `0x0049bdf3`, `0x0049d03f`
  - MonsterImageLib construction/destruction: `0x004daf84`, `0x004dafdc`, `0x004dc379`, `0x004dc3fe`
- `InsertNode` callers:
  - `0x00457041` inside MiniMapVersionManager update
  - `0x004572c2` self-call during rehash
  - `0x004dbf97` and `0x004dc011` inside MonsterImageLib archive/bounds logic
- `FindNodeByKey` callers:
  - `0x004570c2` MiniMapVersionManager lookup wrapper
  - `0x004dbe9d` and `0x004dc139` MonsterImageLib archive/bounds logic
- `RemoveNodeHelper` only has `0x00457301` inside `InsertNode`, so it is private cleanup/unwind support, not a public erase API.
- Destructor callers include MiniMapVersionManager teardown/scalar deleting paths, MonsterImageLib teardown paths, and additional helpers at `0x004e5cf0`, `0x004e67bf`, and `0x004e67c7`.

Rejected ownership conclusions from fanout:

- DAT manager use cannot own the helper because minimap and MonsterImageLib call the same method family.
- MiniMap/MonsterImageLib cannot own the helper because DAT manager and fitting-room callers also initialize/resize the same layout.
- `RemoveNodeHelper` should not be promoted to public API solely because it is a method-shaped body; its only observed route is an `InsertNode` cleanup edge.

### 6. Method/helper source names

Recommended current names:

- `DATIndexVectorFillValueRangeHelper`: keep for [UID:0002U7]. It is descriptive and correct. In final source it may be an inline/private static helper or replaced by a loop/fill call inside `ResizeAndFill`.
- `DATIndexVector::ResizeAndFill`: keep as documentation name for now, but support docs should clarify that it resizes/fills bucket slots. If a later source polish pass wants a more human name, `ResizeBuckets` or `ResizeBucketTable` is more source-facing.
- `DATIndexVector::InsertNode`: keep. It is the clearest current name for the method that inserts a prepared list node and handles duplicate/rehash behavior.
- `DATIndexVectorRemoveNodeHelper`: keep as canonical doc label. Add that `RemoveNodeForInsertUnwind` is the best high-specificity private helper name if the implementation wants to emphasize the sole cleanup-edge caller.
- `DATIndexVector::~DATIndexVector`: keep.
- `DATIndexVector::FindNodeByKey`: keep. A source-facing overload may take `const int& key`; binary docs may keep `const void* keyBytes` for exact FNV evidence.

Rejected names:

- `DATIndexVectorFillSlotRaw`: stale generated/raw name, already superseded.
- `DATIndexVectorValueTable`: misleading because the storage is bucket pairs.
- `EraseNode` as public API: too broad for the single cleanup-edge evidence.
- Generic `HashTable`/`HashMap`: plausible family behavior, but no original generic name evidence; use DATIndexVector until stronger source evidence appears.

### 7. Generated output pollution

Current `auto-generated/NexusTK/archive/DATIndexVector.cpp` contains only comments with empty emitter markers for the class, six methods/helpers, and two support structs. `source-3/simroot_v2/class_DATIndexVector.cpp` contains useful but non-final generated C++ with duplicate class/struct declarations, reinterpret-cast wrappers, address thunks, old `DATIndexVectorLayout` fields, and method bodies that extend beyond class-declaration scope.

Recommendation:

- Do not copy `simroot_v2/class_DATIndexVector.cpp` into formal docs.
- Use it only as a lead confirming that current generated recovery also maps `+0x04` to list head and `+0x0c/+0x14` to buckets.
- Populate the class page with a declaration-level first draft and field names, not full method bodies.
- Leave method-body C++ to method pages or a later method-specific source-quality pass.

### 8. Remaining open questions and score impact

Resolved:

- Value-table/bucket-list split: resolved as one 32-byte object with a bucket table stored as dword pairs.
- Generic list boundary: resolved. `StdList*` helpers are non-emitting compiler/STL support; DATIndexVector owns keyed bucket logic.
- Direct owner/emitter route: resolved enough to keep [UID:0000IP] and class/file emitter route.
- Field names: resolved to the recommended names above, with historical aliases retained for recovery traceability.

Still open but not blocking the recommended score:

- Original folder: `archive/` remains best current path, but `common/` or `util/` remains plausible. This caps confidence below final.
- Public/private header visibility for `DATIndexVectorBucket` and `DATIndexVectorNode`: `Bucket` is likely private implementation detail; `Node` is a semantic overlay needed by current reconstructed APIs and consumer payload docs. No preserved UDT/source symbol proves exact visibility.
- Exact source signature of `InsertNode`: binary/docs support "returns node and inserted flag" either via result object or pointer/out-flag. Current generated direction `DATIndexVectorNode* InsertNode(DATIndexVectorNode* node, bool* inserted)` is usable as first-draft declaration, but method-specific C++ should recheck call sites before formal body insertion.
- Exact source signature of `FindNodeByKey`: binary hashes a pointer to four key bytes; source likely accepted `const int& key` or equivalent. Keep docs explicit about both source-facing and binary-facing forms.

Score impact:

- These unresolved issues are narrow source-shape questions, not ownership/layout blockers. They justify `88/90`, not `95+`.

## First-Draft C++ Recommendation

Populate the [UID:00003K] class page's formal C++ with a declaration-level draft only. The class page should not contain method bodies. Support struct pages may either emit their own struct declarations or be included above this class if the supervisor chooses one consolidated header block; avoid duplicate struct definitions in generated output.

Recommended target class C++:

```cpp
#include <cstdint>

struct DATIndexVectorNode;
struct DATIndexVectorBucket;

class DATIndexVector {
public:
    ~DATIndexVector();

    void ResizeAndFill(int bucketCount);
    DATIndexVectorNode* InsertNode(DATIndexVectorNode* node, bool* inserted);
    DATIndexVectorNode* FindNodeByKey(const int& key) const;

private:
    float m_maxLoadFactor;
    DATIndexVectorNode* m_listHead;
    std::uint32_t m_nodeCount;
    DATIndexVectorBucket* m_bucketsBegin;
    DATIndexVectorBucket* m_bucketsEnd;
    DATIndexVectorBucket* m_bucketsCapacity;
    std::uint32_t m_bucketMask;
    std::uint32_t m_bucketCount;
};

[[CHILDREN]]
```

Rationale:

- This is plausible mid-2000s C++ declaration style: small helper class, raw pointers, `int` keys, `bool*` inserted out-parameter, and no modern containers forced into the declaration.
- It avoids decompiler-shaped `reinterpret_cast` address thunks and old recovery overlay names.
- It does not invent a standalone constructor. Current initialization appears inlined in consumers/constructors; no exact constructor child page exists.
- It uses `const int& key` for source-facing `FindNodeByKey`, while the method page should still document the binary-level four-byte key pointer and FNV-1a behavior.
- If method-body pages later prove an sret pair signature for `InsertNode`, adjust only that declaration. The field layout and source route remain valid.

Recommended support struct C++ for later support-doc callback, if the supervisor wants to populate struct pages too:

```cpp
struct DATIndexVectorNode {
    DATIndexVectorNode* next;
    DATIndexVectorNode* prev;
    int key;
    void* value;
};
```

```cpp
struct DATIndexVectorBucket {
    DATIndexVectorNode* first;
    DATIndexVectorNode* last;
};
```

Support-struct C++ caveat: these are source-reconstruction support declarations. They map a semantic DATIndexVector node/bucket view over MSVC list/vector implementation storage. Do not present them as proven original public UDT names.

## Score And Metadata Recommendations

[UID:00003K] `by-class/DATIndexVector.md`:

```text
*** COMPLETION:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000IP | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000IP | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
```

Rationale:

- Completion rises because the report resolves the class's largest open source-quality blocker, finalizes field names, ranks source-placement alternatives, separates generic list support from class-owned bucket logic, and supplies first-draft declaration C++.
- Confidence rises because method/support docs agree on one object layout and caller fanout. Confidence remains capped at `90` because fresh IDA MCP was unavailable in this session, exact source folder still has an archive/common caveat, and final method signatures still need per-method body review.

[UID:0000IP] `by-file/DATIndexVector.md` optional support score:

- Recommend `87/87 -> 88/88` if the supervisor updates the file page in the same callback, because the file-level "value-table/hash-view split" caveat can be resolved.
- Keep `PROPOSED_RECONSTRUCTION_PATH:"NexusTK/archive/"` and `CANONICAL_OWNER:FILE`.
- If the supervisor wants a target-only callback, leave file score unchanged but still update the stale caveat text.

Support struct and method pages:

- No required score changes for [UID:0001U0], [UID:0001U1], or the six by-memory children in this callback. Their current scores remain defensible.
- Update text where stale `value-table`, `fillValue`, or `lastIndex/entryCount` wording obscures the bucket-table interpretation. If a later callback also populates support struct C++, reassess [UID:0001U0] and [UID:0001U1] scores then.

## Recommended Target And Support Doc Changes

### [UID:00003K] `by-class/DATIndexVector.md`

Replace the current `## Responsibility` with a source-quality responsibility section:

```text
`DATIndexVector` is a reusable keyed bucket/list index helper. The current best model is one 0x20-byte object that combines an embedded MSVC-list-style sentinel/count state at `+0x04/+0x08` with a bucket table at `+0x0c/+0x14`. `ResizeAndFill` does not prove a second value-vector class: it resizes the bucket table as paired dword slots and fills empty bucket first/last entries with the list head/sentinel stored at `+0x04`.

The class is archive-named and currently routes through [UID:0000IP][DATIndexVector](by-file/DATIndexVector.md) to `NexusTK/archive/DATIndexVector.cpp`, but broad caller fanout means it is a standalone helper rather than a private DAT manager subobject. Keep the folder as `archive/` for now because the imported/source-tree route supports it; treat `common/`/`util/` as a future folder-only review question, not an ownership blocker.
```

Replace `## Layout Notes` with the field table from this report and a historical note:

```text
The old `DATIndexVectorLayout { scalar00, fillValue, reserved08, valuesBegin, valuesEnd, valuesCapacity, lastIndex, entryCount }` view is a recovery overlay. Its fields map to the same source object as follows: `fillValue` is `m_listHead`, `reserved08` is `m_nodeCount`, `valuesBegin/valuesEnd/valuesCapacity` are `m_bucketsBegin/m_bucketsEnd/m_bucketsCapacity`, `lastIndex` is `m_bucketMask`, and `entryCount` is `m_bucketCount`.
```

Add a `## Generic List Boundary` section:

```text
`DATIndexVector` embeds a list state compatible with the non-emitting MSVC/Dinkumware support helpers documented under [UID:0000KR][LinkedList](by-file/LinkedList.md). Those `StdList*` helper bodies should not be emitted as custom DATIndexVector source. `DATIndexVector` owns only the keyed FNV-1a bucket algorithms, bucket table state, node/bucket semantic overlays, and destructor storage release before delegating generic list teardown.
```

Update `## Open Questions`:

- Remove the unresolved "value-table and hash bucket/list view are one class or two classes" question.
- Keep only:
  - final folder `archive/` versus `common/`/`util`;
  - exact public/private visibility of `DATIndexVectorNode` and `DATIndexVectorBucket`;
  - exact method signatures for `InsertNode` result reporting and `FindNodeByKey` key reference/pointer form.

Add the first-draft class C++ block from this report.

Append a `2026-06-19 B009 source-quality recheck` change entry with:

```text
- 2026-06-19 B009 source-quality recheck:
  - Recommended before/after: `85/86 -> 88/90`.
  - Summary/evidence: rechecked the class, file, method, support-struct, generated-output, proposed-source-tree, client-container, and prior B-agent list/minimap/DAT reports. The previous value-table/bucket-list split caveat is resolved as one 0x20-byte object: `ResizeAndFill` operates on two-dword bucket slots, uses the list head at `+0x04` as the empty-bucket fill value, writes `m_bucketMask` at `+0x18`, and writes `m_bucketCount` at `+0x1c`. Field names are now `m_maxLoadFactor`, `m_listHead`, `m_nodeCount`, `m_bucketsBegin`, `m_bucketsEnd`, `m_bucketsCapacity`, `m_bucketMask`, and `m_bucketCount`. Generic `StdList*` helpers remain non-emitting compiler/STL support, while DATIndexVector owns keyed bucket logic and semantic node/bucket overlays.
```

### [UID:0000IP] `by-file/DATIndexVector.md`

Update file-level rationale to remove the unresolved value-table/hash-view blocker:

```text
The current class-level recheck resolves the old value-table/hash-view split as one object: the resize/fill helper manages the bucket table as paired dword entries and fills empty bucket first/last pointers with the list head sentinel. The remaining file-level caveats are folder/header questions, not class identity questions.
```

Keep `NexusTK/archive/DATIndexVector.cpp` and `DATIndexVector.h` as proposed module/header. Add that `common/` or `util/` remains a possible folder-only migration if later original-source evidence outweighs the imported `DATIndexVector.cpp` route.

### [UID:0000WW] `DATIndexVectorResizeAndFill`

Update wording from "value-table resize/fill method" to "bucket-table resize/fill method". Add:

```text
The stored fill value at object offset `+0x04` is the list head/sentinel pointer. `ResizeAndFill` uses it to initialize every bucket's `first` and `last` pointer in the two-dword bucket table. The writes to `+0x18` and `+0x1c` are source-facing `m_bucketMask = bucketCount - 1` and `m_bucketCount = bucketCount`.
```

Add a source-signature note:

```text
The binary leaves `bucketCount - 1` in `EAX`, but no documented caller currently depends on the return value. A source-facing method declaration may be `void ResizeAndFill(int bucketCount)` unless later caller evidence proves the return is source-visible.
```

### [UID:0002U7] `DATIndexVectorFillValueRangeHelper`

Add:

```text
The helper fills dword slots in the bucket table, not arbitrary semantic values. In the DATIndexVector caller, the source dword is `m_listHead`, so a bucket table resize initializes empty bucket first/last pointers to the sentinel.
```

### [UID:0000XS] `DATIndexVectorInsertNode`

Add:

```text
Use the class-level field names `m_maxLoadFactor`, `m_listHead`, `m_nodeCount`, `m_bucketsBegin`, `m_bucketMask`, and `m_bucketCount`. The result form is still a source-signature question: current generated output uses `DATIndexVectorNode* InsertNode(DATIndexVectorNode* node, bool* inserted)`, while the binary/decompiler can also be described as returning node plus inserted flag through an out/result object. This does not block class layout.
```

### [UID:0000XT] `DATIndexVectorRemoveNodeHelper`

Add:

```text
Best high-specificity private name is `RemoveNodeForInsertUnwind`; keep `DATIndexVectorRemoveNodeHelper` as the stable documentation name unless a later implementation pass wants to emphasize the sole cleanup-edge caller. Do not document this as a public erase API.
```

### [UID:0000XU] `DATIndexVectorDestructor`

Add:

```text
The destructor confirms the unified layout: it frees `m_bucketsBegin/m_bucketsEnd/m_bucketsCapacity`, then delegates the embedded list state at `this + 4` (`m_listHead`, `m_nodeCount`) to non-emitting `StdListTidy8ByteList`.
```

### [UID:0000XX] `DATIndexVectorFindNodeByKey`

Add:

```text
Source-facing declaration can be `FindNodeByKey(const int& key) const`, while binary documentation should preserve that the helper hashes exactly four bytes from the incoming key address and compares against `node->key`.
```

### [UID:0001U0] `DATIndexVectorBucket`

Add:

```text
`DATIndexVectorBucket` is the two-dword bucket-table entry allocated and filled by `DATIndexVector::ResizeAndFill`. Empty `first` and `last` both equal `DATIndexVector::m_listHead`.
```

### [UID:0001U1] `DATIndexVectorNode`

Add:

```text
`DATIndexVectorNode` is the semantic payload overlay for the 16-byte list node used by the DATIndexVector algorithms. Its `key` is always the four-byte value hashed by FNV-1a; `value` is caller-specific and should stay `void*` at this generic level.
```

### [UID:0001QA] `client_containers.md`

Update the DATIndexVector bullet:

```text
[UID:0000IP][DATIndexVector](by-file/DATIndexVector.md) is a standalone keyed bucket/list index helper. Its old value-table view is now resolved as the bucket-table resize/fill path; it remains tracked here because non-DAT callers use it, but current reconstruction path stays `archive/DATIndexVector.cpp`.
```

### [UID:0000KR] `LinkedList.md`

No score change required. If touched, add only a cross-reference sentence:

```text
`DATIndexVector` embeds an STL-list-compatible state and calls `StdListTidy8ByteList`, but its bucket table, FNV-1a keying, duplicate collapse, and node/bucket semantic overlays remain [UID:00003K][DATIndexVector](by-class/DATIndexVector.md) source ownership.
```

## Exact Coverage Text

Do not edit `by-memory/-coverage-report.md`. No by-memory coverage-row replacement is required for this report unless the supervisor chooses to rescore method pages beyond the target class/file update.

Recommended replacement row for `by-class/-coverage-report.md`:

```markdown
- [UID:00003K][DATIndexVector](by-class/DATIndexVector.md) : reconstructable : 88% : strong : B009 source-quality recheck resolves the stale value-table/bucket-list split as one 0x20-byte DATIndexVector object: `ResizeAndFill` resizes paired dword bucket slots, fills empty bucket first/last with the list head at `+0x04`, and writes `m_bucketMask`/`m_bucketCount` at `+0x18/+0x1c`; final field names, standalone [UID:0000IP] route, broad fitting-room/minimap/DAT/MonsterImageLib caller fanout, non-emitting StdList boundary, node/bucket support roles, rejected DATFileMgr/consumer/LinkedList ownership, and first-draft class/header C++ are documented.
```

Optional replacement row for `by-file/-coverage-report.md` if [UID:0000IP] is raised to `88/88`:

```markdown
- [UID:0000IP][DATIndexVector](by-file/DATIndexVector.md) : reconstructable : 88% : strong : Standalone `NexusTK/archive/DATIndexVector.cpp` file with exact resize/fill, insert, remove cleanup, destructor, and find method inventory; B009 recheck resolves the old value-table/hash-view split as one bucket-table/list-head object, preserves broad fitting-room/minimap/DAT/MonsterImageLib caller fanout, keeps generic StdList helpers non-emitting under LinkedList support, documents node/bucket support records and private remove-helper ownership, and leaves only folder/header/source-declaration caveats.
```

If the file score stays `87/87`, do not replace the by-file coverage row.

No `by-type/by-struct/-coverage-report.md` replacement is required unless the supervisor changes [UID:0001U0] or [UID:0001U1] scores.

## IDA Rename / Type / Comment Recommendations

Function names already present in docs remain appropriate:

- `sub_4233F0` -> `DATIndexVectorFillValueRangeHelper` (high confidence)
- `sub_423B00` -> `DATIndexVectorResizeAndFill` or `DATIndexVectorResizeBuckets` (high behavior confidence; current name lower churn)
- `sub_457100` -> `DATIndexVectorInsertNode` (high confidence)
- `sub_457310` -> `DATIndexVectorRemoveNodeHelper`; optional comment "private cleanup edge from InsertNode; not public erase" (high ownership confidence, medium exact source name)
- `sub_4573D0` -> `DATIndexVectorDestructor` / `DATIndexVector::~DATIndexVector` (high confidence)
- `sub_457580` -> `DATIndexVectorFindNodeByKey` (high confidence)

Nearby helper recommendations:

- `sub_423C50` -> `DATIndexVectorEnsureBucketStorageCapacity` or `EnsureBucketTableCapacity` (medium-high; only `ResizeAndFill` caller in current docs)
- `sub_423C40` -> leave as shared alignment/rounding helper until a separate pass; callers are not DATIndexVector-only (medium/low)
- `sub_423E00` -> shared aligned dword storage free helper, not DATIndexVector-private (medium-high)

IDA type/comment recommendations:

- Add a `DATIndexVector` structure/class comment showing the eight fields listed in this report.
- Add member comment at `+0x04`: "list head/sentinel; also ResizeAndFill fill source for empty bucket first/last".
- Add member comment at `+0x0c`: "bucket table begin; table entries are DATIndexVectorBucket { first, last }".
- Add member comments at `+0x18/+0x1c`: "bucket mask" and "bucket count".
- Add `DATIndexVectorBucket` with `first`, `last`.
- Add `DATIndexVectorNode` with `next`, `prev`, `key`, `value`, but mark it as a semantic overlay over 16-byte list-node storage if IDA comments support annotations.
- Do not rename or move `StdList*` helpers to DATIndexVector.

## Implementation Instructions For Supervisor Callback

1. Lease all target/support docs before editing.
2. Do not edit `by-memory/-coverage-report.md`.
3. Update [UID:00003K] `by-class/DATIndexVector.md`:
   - Metadata `85/86 -> 88/90`.
   - Keep `CANONICAL_OWNER:0000IP`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000IP`.
   - Replace stale layout split text with the unified layout and field table.
   - Add generic list boundary text.
   - Add rejected alternatives and source-placement ranking.
   - Add the declaration-level class C++ block from this report.
   - Add B009 change entry and score rationale.
4. Update [UID:0000IP] `by-file/DATIndexVector.md`:
   - Replace old value-table/hash-view split caveat with the resolved bucket-table interpretation.
   - Optionally raise `87/87 -> 88/88`; if raised, use the exact by-file coverage row above.
   - Keep `NexusTK/archive/` route and folder caveat.
5. Update support docs with report-level detail:
   - [UID:0000WW] `DATIndexVectorResizeAndFill`: bucket table, sentinel fill value, `m_bucketMask/m_bucketCount`, return-value caveat.
   - [UID:0002U7] fill helper: range fill over bucket table dwords.
   - [UID:0000XS] insert: current field names and result-signature caveat.
   - [UID:0000XT] remove helper: private cleanup/unwind, not public erase.
   - [UID:0000XU] destructor: free bucket allocation then list cleanup.
   - [UID:0000XX] find: source-facing `const int& key` option plus binary four-byte-key evidence.
   - [UID:0001U0] bucket and [UID:0001U1] node: final fields and source-visibility caveat.
   - [UID:0001QA] `client_containers.md`: update DATIndexVector bullet.
   - [UID:0000KR] `LinkedList.md`: optional cross-reference only; no score change.
6. Exact class coverage row:
   - Replace the [UID:00003K] row in `by-class/-coverage-report.md` with the row in `## Exact Coverage Text`.
7. Exact by-file coverage row:
   - Only replace [UID:0000IP] row in `by-file/-coverage-report.md` if the supervisor accepts the optional file score raise.
8. Expected validation commands from `E:\NTK\GhidraBridge\source-3\project-documentation`:

> Executable block R001 was removed from this report and preserved verbatim in [00003K-DATIndexVector-class-source-quality-removed.md](00003K-DATIndexVector-class-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

If fewer support docs are edited, validate only the edited files plus the target and changed coverage reports.

Expected validation result: each scoped file validator should return `ok:1`; autogen should refresh `auto-generated/NexusTK/archive/DATIndexVector.cpp` so [UID:00003K] no longer appears as an empty emitter marker once the class C++ block is accepted.

## Final Recommendation

Proceed with the target raise and class/header C++ insertion after supervisor review. The evidence supports `DATIndexVector` as a single class with a unified list-head plus bucket-table layout. The remaining issues are source polish and folder/header visibility, not blockers to target class documentation or declaration-level C++.

Changed files in this report-only pass:

- Created: `tools/leaser/Agents/Agent-B009/research/00003K-DATIndexVector-class-source-quality.md`
- Modified: none outside the B009 research folder.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B009","command_id":"000000004165","destination_path":"executed-b-agent-research/B009/00003K-DATIndexVector-class-source-quality.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:33","uid":"00003K"} -->
<!-- {"agent":"B009","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 00003K-DATIndexVector-class-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B009/00003K-DATIndexVector-class-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"00003K"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
