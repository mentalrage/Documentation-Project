** TARGET-REPORT-UID:00022A **
** AUTHOR-AGENT-ID:B002 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# B002-goal2-eventdispatcher-handler-record-source-quality-00022A-000148-00022B-20260617

Report-only B-agent research for:

- [UID:00022A] `source-3/project-documentation/by-memory/0x004a82b0-0x004a8795.EventDispatcherHandlerRecordRelinkHelpers.md`
- [UID:000148] `source-3/project-documentation/by-memory/0x004a87a0-0x004a8810.EventDispatcherHandlerRecordVectorFree.md`
- [UID:00022B] `source-3/project-documentation/by-memory/0x004a8820-0x004a88d2.EventDispatcherHandlerRecordVectorAllocationHelpers.md`

No by-* docs, generated files, source files, IDA databases, or coverage reports were edited. This report is the only created artifact.

## Evidence Checked

- Assignment and B-agent rules: `tools/leaser/Agents/Supervisor.md`, `tools/leaser/Agents/Agent-B002/goal.md`, `by-structure.md`, and `inference_research.md`.
- Primary targets: [UID:00022A], [UID:000148], and [UID:00022B].
- Support docs: `by-file/EventDispatcher.md`, `by-class/EventDispatcher.md`, `by-type/by-struct/EventDispatcherHandlerTreeLayouts.md`, `by-memory/0x004a6a80-0x004a82a9.EventDispatcher.md`, `by-memory/0x004a78f0-0x004a7979.EventDispatcherFindHandlerIterator.md`, `by-memory/0x004a7b10-0x004a7c2a.EventDispatcherHandlerRecordVectorInsert.md`, `by-memory/0x004a7cd0-0x004a7df3.EventDispatcherHandlerTreeSupport.md`, `by-memory/0x004a7d00-0x004a7d43.EventDispatcherHandlerListDestructor.md`, `by-memory/0x004a88e0-0x004a8966.DequePushBack.md`, `by-memory/0x00439e00-0x00439ea3.DequeDestroy.md`, `by-memory/0x0043e0b0-0x0043e241.DequeEnsureCapacity.md`, `by-class/Deque.md`, and `by-type/by-struct/DequeLayout.md`.
- Generated/source-placement evidence: `project-documentation/auto-generated/-ag-memory-coverage.md`, the zero-byte formal emitter `project-documentation/auto-generated/NexusTK/ui/core/EventDispatcher.cpp`, and `source-3/simroot_v2/ui/core/EventDispatcher.cpp`.
- Exported IDA/Ghidra evidence: `resources/exported_data/functions/0x004a7570.json`, `0x004a7690.json`, `0x004a7e70.json`, `0x004a82b0.json`, `0x004a8350.json`, `0x004a8420.json`, `0x004a8680.json`, `0x004a86b0.json`, `0x004a8740.json`, `0x004a87a0.json`, `0x004a8820.json`, and `0x004a8890.json`.
- Local PE validation: `E:\NTK\Resources\NexusTK\NexusTK.exe`, MD5 `4247E04E20B65D6414C7238AA8FF5515`.
- IDA MCP was attempted through the local `13337` port and MCP resource listing. No listener/resources were available in this session, so fresh validation used checked-in exported decompilation plus direct PE byte/reference scans.

## Score / Metadata Recommendations

| UID | Current score | Recommended score | Owner | Emitter | Reconstructable | C++ recommendation |
| --- | ---: | ---: | --- | --- | --- | --- |
| `00022A` | `82/90` | `88/92` | keep `CANONICAL_OWNER:0000J7` | keep `EMITTER_UIDS:0000J7` | keep `TRUE` | Populate first-draft C++ for the private EventDispatcher helper cluster. |
| `000148` | `82/90` | `89/94` | keep `CANONICAL_OWNER:0000J7` | keep `EMITTER_UIDS:0000J7` | keep `TRUE` | Populate first-draft C++ for vector free/clear. |
| `00022B` | `82/90` | `89/94` | keep `CANONICAL_OWNER:0000J7` | keep `EMITTER_UIDS:0000J7` | keep `TRUE` | Populate first-draft C++ for allocation/free helpers. |

Combined-score status: all three targets currently clear the active first-draft code-entry gate after this reanalysis. They are reconstructable, have nonblank emitter UID `0000J7`, route to `auto-generated/NexusTK/ui/core/EventDispatcher.cpp`, and the recommended `(COMPLETION + CONFIDENCE) / 2` values are above `85`.

The older "final C++ remains blank below 95/95" wording in the target/support docs is stale for first-draft code entry. Recommended corrected wording:

> This target clears the active first-draft code-entry gate because `RECONSTRUCTABLE` is `TRUE`, `EMITTER_UIDS` is nonblank and points to [UID:0000J7][EventDispatcher], and the combined score is above `85`. The `95+` standard should be reserved for final-audit confidence, not for withholding first-draft C++.

## Heuristic / Inference Reanalysis And Validation

The best source-facing abstraction is an EventDispatcher-local handler tree backed by a vector-like array of 28-byte `EventHandlerRecord` entries. It should remain in `ui/core/EventDispatcher.cpp` with any declarations shared through the EventDispatcher/EventHandler support header only if required by adjacent formal blocks. It should not be split into a generic vector source file, Deque source file, or standalone generated pseudo-class file.

Recommended record layout:

| Offset | Source-facing name | Type | Validation |
| --- | --- | --- | --- |
| `+0x00` | `parentIndex` | `int` | `0x004a82b0` writes the parent/current iterator index into new child records; `0x004a8420` checks this before updating parent child endpoints. |
| `+0x04` | `firstChildIndex` | `int` | `0x004a82b0` sets parent `+0x04` to the new child when creating the first child; `0x004a8420` and `0x004a7e70` enumerate descendants from `+0x04`. |
| `+0x08` | `lastChildIndex` | `int` | `0x004a82b0` sets parent `+0x08` to the new child; `0x004a8350` updates parent `+0x08` when appending after the current tail; dispatch helpers start from `+0x08` to route reverse child order. |
| `+0x0c` | `previousSiblingIndex` | `int` | Dispatch helpers advance from the last child through `+0x0c`; `0x004a8420` treats it as the back-link when unlinking a record. |
| `+0x10` | `nextSiblingIndex` | `int` | `0x004a8350` moves the current record's `+0x10` continuation to the new record; `0x004a8420` and `0x004a7e70` follow it while enumerating the forward child list. |
| `+0x14` | `handler` | `EventHandler *` | `0x004a78f0` passes `record + 0x14` to `HandlerFindFunc::IsMatch`; dispatch helpers load this field before virtual handler calls. |
| `+0x18` | `isDisabled` | `unsigned char` / `bool` | `0x004a78f0`, `0x004a7570`, and `0x004a7690` skip nonzero records; `0x004a8420` marks removed subtrees by writing `1`. |
| `+0x19..+0x1b` | padding | 3 bytes | Record stride is `0x1c`; vector copy helpers copy the tail dword at `+0x18`. |

This resolves the earlier ambiguous `link0/link2/link3` names and the layout-page wording that treated `+0x08` as only "sibling/related." The binary supports a first/last child pair: forward maintenance/rebuild walks `firstChildIndex -> nextSiblingIndex`, while event dispatch begins at `lastChildIndex` and walks `previousSiblingIndex` so later/topmost panes receive events first. That dual traversal explains the apparent conflict between `0x004a7e70` (`+0x04/+0x10`) and `0x004a7570`/`0x004a7690` (`+0x08/+0x0c`).

Recommended vector/tree layout:

```cpp
struct EventHandlerRecordVector {
    EventHandlerRecord *begin;
    EventHandlerRecord *end;
    EventHandlerRecord *capacityEnd;
};

struct EventHandlerTree {
    void *vtable;                 // Tree<EventHandler *> / LObject-facing header.
    EventHandlerRecordVector records;
};
```

The vector header is at `EventHandlerTree + 0x04`, which corresponds to dispatcher offsets `+0x08/+0x0c/+0x10` when the embedded tree begins at `EventDispatcher + 0x04`. This matches `0x004a78f0`, `0x004a7b10`, `0x004a7e70`, `0x004a87a0`, and the destructor path that frees `EventDispatcher + 0x08`.

Recommended helper names and signatures:

| Address | Current name | Recommended source-facing helper | Return type | Notes |
| --- | --- | --- | --- | --- |
| `0x004a82b0` | `sub_4A82B0` | `InsertFirstChildHandlerRecord(EventHandlerTree *tree, const EventHandlerIterator *parent, EventHandler *handler)` | `void` | Creates a child record with all child/sibling links `-1`, sets the parent first/last child links to the new index, and appends/inserts into the vector. |
| `0x004a8350` | `sub_4A8350` | `InsertHandlerRecordAfterSibling(EventHandlerTree *tree, const EventHandlerIterator *sibling, EventHandler *handler)` | `void` | Inserts after the selected record in the forward sibling chain; updates parent `lastChildIndex` only when selected record was the tail. The binary carries old `nextSiblingIndex` into the new record but does not patch the old next record's back-link, so the helper is best interpreted as an append/tail-oriented relink helper used by `SetPaneOrder`. |
| `0x004a8420` | `sub_4A8420` | `RemoveHandlerRecordAndDisableSubtree(EventHandlerTree *tree, const EventHandlerIterator *iterator)` | `void` | Uses a shared Deque of integer indexes as a scratch LIFO stack, disables the target subtree, then unlinks the target from the first/last child and previous/next sibling links. |
| `0x004a8680` | `sub_4A8680` | `CreateEventHandlerListNodeLinks(EventHandlerListNode *next, EventHandlerListNode *previous)` | `EventHandlerListNode *` | Allocates 12 bytes and initializes only `next/prev`. Caller owns the payload/handler field. Null `next` creates a self-linked sentinel. |
| `0x004a86b0` | `sub_4A86B0` | `RebindHandlerRecordVectorStorage(EventHandlerRecordVector *records, EventHandlerRecord *newBegin, int count, int capacity)` | `void` source-facing | Frees old storage with MSVC large-allocation validation and publishes new begin/end/capacity pointers. Decompiler EAX is an incidental `capacityEnd` value. |
| `0x004a8740` | `sub_4A8740` | `ReserveHandlerRecordVectorStorage(EventHandlerRecordVector *records, unsigned int capacity)` | `void` source-facing | Allocates a new buffer for the requested capacity, `memmove`s existing records, then rebinds. Decompiler EAX is incidental. |
| `0x004a87a0` | `sub_4A87A0` | `FreeHandlerRecordVector(EventHandlerRecordVector *records)` | `void` | Frees current capacity storage and clears all three pointers. |
| `0x004a8820` | `sub_4A8820` | `AllocateHandlerRecordBuffer(unsigned int count)` | `EventHandlerRecord *` | Count-based 28-byte element allocator with zero-count null return and 32-byte aligned large allocation. |
| `0x004a8890` | `sub_4A8890` | `FreeHandlerRecordBuffer(EventHandlerRecord *records, int count)` | `void` | Count-based paired free helper for buffers allocated by `AllocateHandlerRecordBuffer`. |

Caller/reachability validation from direct PE rel32 scan:

| Target | Direct refs found |
| --- | --- |
| `0x004a82b0` | `call 0x004a6db6` |
| `0x004a8350` | `call 0x004a6d42`, `call 0x004a6d97` |
| `0x004a8420` | `call 0x004a6ed6` |
| `0x004a8680` | `call 0x004a6b61`, `call 0x004a7af9` |
| `0x004a86b0` | `call 0x004a7c12`, `call 0x004a8788` |
| `0x004a8740` | `call 0x004a7fa5` |
| `0x004a87a0` | `call 0x004a6c1c`, `call 0x004a7cdc`, `jmp 0x004a7d50`, `call 0x004a7d8f`, `call 0x004a7e2f`, `call 0x004a8247` |
| `0x004a8820` | `call 0x004a7a43`, `call 0x004a7b91`, `call 0x004a8764` |
| `0x004a8890` | `call 0x004a7a17` |
| `0x004a88e0` | direct calls from `0x004a84a3` and unrelated non-EventDispatcher users, confirming the Deque helper is shared utility code rather than EventDispatcher-owned code. |

Padding/range validation from the PE scan:

| Span | Bytes | Decision |
| --- | --- | --- |
| `0x004a82a9-0x004a82b0` | seven `0xcc` | padding before `00022A` |
| `0x004a8418-0x004a8420` | eight `0xcc` | internal alignment in `00022A` |
| `0x004a86ad-0x004a86b0` | three `0xcc` | internal alignment in `00022A` |
| `0x004a873b-0x004a8740` | five `0xcc` | internal alignment in `00022A` |
| `0x004a8795-0x004a87a0` | eleven `0xcc` | padding between `00022A` and `000148` |
| `0x004a8810-0x004a8820` | sixteen `0xcc` | padding between `000148` and `00022B` |
| `0x004a8889-0x004a8890` | seven `0xcc` | internal alignment in `00022B` |
| `0x004a88d2-0x004a88e0` | fourteen `0xcc` | padding before shared DequePushBack |

Runtime/STL/container boundary:

- The 28-byte handler-record storage is vector-like but should not be emitted as `std::vector<EventHandlerRecord>`. The helpers are visible as source-authored or compiler-emitted container support around a dispatcher-local tree specialization, with explicit begin/end/capacity fields and custom MSVC large-allocation handling.
- The Deque routines at `0x00439e00`, `0x0043e0b0`, and `0x004a88e0` belong to the shared Deque utility owner, not EventDispatcher. `0x004a8420` merely uses that Deque as a temporary integer index stack while disabling descendants.
- The allocator/free validation logic is MSVC runtime allocation policy. It should be expressed in first-draft C++ only as helper behavior, not as a new project abstraction.
- `xmmword_619660` is best treated as a constant initializer for four `-1` index fields, not as a mutable logical global.

Rejected alternatives:

- Keep names such as `sub_4A82B0`, `link0Index`, `link2Index`, or `unknown4`: rejected. The relink/remove/exported decompilation evidence resolves the field semantics enough for source-facing names.
- Model `+0x08` as only "sibling/related": rejected. It is the parent `lastChildIndex` endpoint used as the dispatch starting point.
- Model dispatch traversal and rebuild traversal as contradictory: rejected. They are two directions over the same child list: dispatch starts at `lastChildIndex` and walks `previousSiblingIndex`; rebuild/removal starts at `firstChildIndex` and walks `nextSiblingIndex`.
- Move these helpers to `util/Deque.cpp`: rejected. Deque is a dependency only. The handler-record vector and tree are dispatcher-local.
- Create a new `EventHandlerRecordVector.cpp`: rejected. Callers, owning file docs, class docs, and formal emitter all route to EventDispatcher.
- Leave first-draft C++ blank because scores are not `95/95`: rejected under the active combined-score/emitter gate. Remaining uncertainty is source spelling and exact original helper names, not behavior, range, owner, or code-entry eligibility.

Historical assumptions corrected:

- The prior `95/95 final-code-gate` language is stale for first-draft code entry.
- The old layout page's `+0x04 first child or next child` and `+0x08 sibling/related` language should be replaced with the first/last child and previous/next sibling table above.
- The current docs' "temporary Deque append/grow/destroy use" should be sharpened to "shared Deque<int> scratch stack used to visit and disable descendants."
- The formal output path currently exists but is zero bytes, so no generated EventDispatcher formal code is being overwritten by recommending these blocks.

## First-Draft C++ Recommendation

All three targets should receive first-draft C++ under the active gate. The following code is intentionally source-facing and uses EventDispatcher-local helper names. It avoids preserving `sub_*` names, generated pseudo-class names, and `std::vector` scaffolding.

Recommended shared declarations for the three formal blocks:

```cpp
static const int kNoHandlerRecord = -1;
static const unsigned int kMaxHandlerRecordCount = 0x09249249u;

class EventHandler;

struct EventHandlerRecord {
    int parentIndex;
    int firstChildIndex;
    int lastChildIndex;
    int previousSiblingIndex;
    int nextSiblingIndex;
    EventHandler *handler;
    unsigned char isDisabled;
    unsigned char reserved[3];
};

struct EventHandlerRecordVector {
    EventHandlerRecord *begin;
    EventHandlerRecord *end;
    EventHandlerRecord *capacityEnd;
};

struct EventHandlerTree {
    void *vtable;
    EventHandlerRecordVector records;
};

struct EventHandlerIterator {
    void *vtable;
    EventHandlerTree *tree;
    int index;
};

struct EventHandlerListNode {
    EventHandlerListNode *next;
    EventHandlerListNode *previous;
    EventHandler *handler;
};

static int GetHandlerRecordCount(const EventHandlerRecordVector *records)
{
    return static_cast<int>(records->end - records->begin);
}

static int GetHandlerRecordCapacity(const EventHandlerRecordVector *records)
{
    return static_cast<int>(records->capacityEnd - records->begin);
}
```

Recommended [UID:00022B] first-draft C++:

```cpp
static EventHandlerRecord *AllocateHandlerRecordBuffer(unsigned int count)
{
    unsigned int byteCount = count * sizeof(EventHandlerRecord);

    if (count <= kMaxHandlerRecordCount) {
        if (byteCount < 0x1000u) {
            if (byteCount == 0) {
                return 0;
            }
            return static_cast<EventHandlerRecord *>(operator new(byteCount));
        }
    } else {
        byteCount = 0xffffffffu;
    }

    unsigned int allocationSize = byteCount + 35u;
    if (allocationSize < byteCount) {
        allocationSize = 0xffffffffu;
    }

    void *raw = operator new(allocationSize);
    if (raw == 0) {
        _invalid_parameter_noinfo_noreturn();
    }

    EventHandlerRecord *aligned =
        reinterpret_cast<EventHandlerRecord *>((reinterpret_cast<unsigned int>(raw) + 35u) & 0xffffffe0u);
    reinterpret_cast<void **>(aligned)[-1] = raw;
    return aligned;
}

static void FreeHandlerRecordBuffer(EventHandlerRecord *records, int count)
{
    void *block = records;

    if (static_cast<unsigned int>(count * sizeof(EventHandlerRecord)) >= 0x1000u) {
        void *raw = reinterpret_cast<void **>(records)[-1];
        if (static_cast<unsigned int>(
                reinterpret_cast<unsigned char *>(records) -
                reinterpret_cast<unsigned char *>(raw) - 4) > 0x1fu) {
            _invalid_parameter_noinfo_noreturn();
        }
        block = raw;
    }

    operator delete(block);
}
```

Recommended [UID:000148] first-draft C++:

```cpp
static void FreeHandlerRecordVector(EventHandlerRecordVector *records)
{
    EventHandlerRecord *begin = records->begin;
    if (begin == 0) {
        return;
    }

    void *block = begin;
    unsigned int byteCount =
        static_cast<unsigned int>((records->capacityEnd - begin) * sizeof(EventHandlerRecord));

    if (byteCount >= 0x1000u) {
        void *raw = reinterpret_cast<void **>(begin)[-1];
        if (static_cast<unsigned int>(
                reinterpret_cast<unsigned char *>(begin) -
                reinterpret_cast<unsigned char *>(raw) - 4) > 0x1fu) {
            _invalid_parameter_noinfo_noreturn();
        }
        block = raw;
    }

    operator delete(block);
    records->begin = 0;
    records->end = 0;
    records->capacityEnd = 0;
}
```

Recommended [UID:00022A] first-draft C++:

```cpp
static EventHandlerRecord *InsertHandlerRecord(
    EventHandlerRecordVector *records,
    EventHandlerRecord *insertAt,
    const EventHandlerRecord *source);

static void AppendHandlerRecord(EventHandlerRecordVector *records, const EventHandlerRecord *source)
{
    if (records->end == records->capacityEnd) {
        InsertHandlerRecord(records, records->end, source);
        return;
    }

    *records->end = *source;
    ++records->end;
}

static void InsertFirstChildHandlerRecord(
    EventHandlerTree *tree,
    const EventHandlerIterator *parent,
    EventHandler *handler)
{
    EventHandlerRecordVector *records = &tree->records;
    int newIndex = GetHandlerRecordCount(records);
    EventHandlerRecord *parentRecord = records->begin + parent->index;

    parentRecord->firstChildIndex = newIndex;
    parentRecord->lastChildIndex = newIndex;

    EventHandlerRecord record;
    record.parentIndex = parent->index;
    record.firstChildIndex = kNoHandlerRecord;
    record.lastChildIndex = kNoHandlerRecord;
    record.previousSiblingIndex = kNoHandlerRecord;
    record.nextSiblingIndex = kNoHandlerRecord;
    record.handler = handler;
    record.isDisabled = 0;
    record.reserved[0] = 0;
    record.reserved[1] = 0;
    record.reserved[2] = 0;

    AppendHandlerRecord(records, &record);
}

static void InsertHandlerRecordAfterSibling(
    EventHandlerTree *tree,
    const EventHandlerIterator *sibling,
    EventHandler *handler)
{
    EventHandlerRecordVector *records = &tree->records;
    int newIndex = GetHandlerRecordCount(records);
    EventHandlerRecord *siblingRecord = records->begin + sibling->index;
    int oldNext = siblingRecord->nextSiblingIndex;

    siblingRecord->nextSiblingIndex = newIndex;
    if (oldNext == kNoHandlerRecord && siblingRecord->parentIndex != kNoHandlerRecord) {
        records->begin[siblingRecord->parentIndex].lastChildIndex = newIndex;
    }

    EventHandlerRecord record;
    record.parentIndex = siblingRecord->parentIndex;
    record.firstChildIndex = kNoHandlerRecord;
    record.lastChildIndex = kNoHandlerRecord;
    record.previousSiblingIndex = sibling->index;
    record.nextSiblingIndex = oldNext;
    record.handler = handler;
    record.isDisabled = 0;
    record.reserved[0] = 0;
    record.reserved[1] = 0;
    record.reserved[2] = 0;

    AppendHandlerRecord(records, &record);
}

static void RemoveHandlerRecordAndDisableSubtree(
    EventHandlerTree *tree,
    const EventHandlerIterator *iterator)
{
    EventHandlerRecordVector *records = &tree->records;
    Deque<int> pending;

    pending.push_back(iterator->index);
    while (!pending.empty()) {
        int recordIndex = pending.back();
        pending.pop_back();

        EventHandlerRecord *record = records->begin + recordIndex;
        record->isDisabled = 1;

        for (int childIndex = record->firstChildIndex;
             childIndex != kNoHandlerRecord;
             childIndex = records->begin[childIndex].nextSiblingIndex) {
            pending.push_back(childIndex);
        }
    }

    EventHandlerRecord *record = records->begin + iterator->index;
    int previous = record->previousSiblingIndex;

    if (previous == kNoHandlerRecord && record->parentIndex != kNoHandlerRecord) {
        records->begin[record->parentIndex].firstChildIndex = record->nextSiblingIndex;
        previous = record->previousSiblingIndex;
    }

    int next = record->nextSiblingIndex;

    if (next == kNoHandlerRecord && record->parentIndex != kNoHandlerRecord) {
        records->begin[record->parentIndex].lastChildIndex = record->previousSiblingIndex;
        previous = record->previousSiblingIndex;
        next = record->nextSiblingIndex;
    }

    if (previous != kNoHandlerRecord) {
        records->begin[previous].nextSiblingIndex = next;
    }

    if (next != kNoHandlerRecord) {
        records->begin[next].previousSiblingIndex = record->previousSiblingIndex;
    }
}

static EventHandlerListNode *CreateEventHandlerListNodeLinks(
    EventHandlerListNode *next,
    EventHandlerListNode *previous)
{
    EventHandlerListNode *node =
        static_cast<EventHandlerListNode *>(operator new(sizeof(EventHandlerListNode)));

    if (next != 0) {
        node->next = next;
        node->previous = previous;
    } else {
        node->next = node;
        node->previous = node;
    }

    return node;
}

static void RebindHandlerRecordVectorStorage(
    EventHandlerRecordVector *records,
    EventHandlerRecord *newBegin,
    int count,
    int capacity)
{
    EventHandlerRecord *oldBegin = records->begin;
    if (oldBegin != 0) {
        void *block = oldBegin;
        unsigned int byteCount =
            static_cast<unsigned int>(GetHandlerRecordCapacity(records) * sizeof(EventHandlerRecord));

        if (byteCount >= 0x1000u) {
            void *raw = reinterpret_cast<void **>(oldBegin)[-1];
            if (static_cast<unsigned int>(
                    reinterpret_cast<unsigned char *>(oldBegin) -
                    reinterpret_cast<unsigned char *>(raw) - 4) > 0x1fu) {
                _invalid_parameter_noinfo_noreturn();
            }
            block = raw;
        }

        operator delete(block);
    }

    records->begin = newBegin;
    records->end = newBegin + count;
    records->capacityEnd = newBegin + capacity;
}

static void ReserveHandlerRecordVectorStorage(
    EventHandlerRecordVector *records,
    unsigned int capacity)
{
    int count = GetHandlerRecordCount(records);
    EventHandlerRecord *newBegin = AllocateHandlerRecordBuffer(capacity);
    memmove(newBegin, records->begin, count * sizeof(EventHandlerRecord));
    RebindHandlerRecordVectorStorage(records, newBegin, count, static_cast<int>(capacity));
}
```

The `Deque<int>` names in this draft are source-facing placeholders for the already-owned shared Deque utility. If the formal emitter cannot reference that type yet, the subtree-removal block should either include the existing Deque declarations from `util/Deque.cpp` or keep a narrow forward declaration compatible with [UID:00003P]/[UID:0000IR]. That is a dependency-order issue, not a reason to leave [UID:00022A] blank.

## Exact By-Doc Update Instructions

For `source-3/project-documentation/by-memory/0x004a82b0-0x004a8795.EventDispatcherHandlerRecordRelinkHelpers.md`:

- Replace metadata lines:

```text
*** COMPLETION:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
```

- Replace the current Status bullet "Rebuild handling: source-authored internal `EventDispatcher` container helpers. Keep C++ blank because final helper names, record-field names, and container abstraction shape are not final-source quality." with:

```text
- Rebuild handling: source-authored internal `EventDispatcher` container helpers. First-draft C++ should now be populated because the active combined-score/emitter gate is satisfied and the record fields resolve to `parentIndex`, `firstChildIndex`, `lastChildIndex`, `previousSiblingIndex`, `nextSiblingIndex`, `handler`, and `isDisabled`.
```

- In the "Behavior Summary" table, replace the role text for the first three helpers with:

```text
| `0x004a82b0-0x004a8350` | `InsertFirstChildHandlerRecord` | Creates the first child record for the iterator's current record: it patches the parent record's `firstChildIndex` (`+0x04`) and `lastChildIndex` (`+0x08`) to the current vector-end index, builds a child record with `parentIndex` set to the iterator index, four `-1` child/sibling fields, the caller-provided `EventHandler *`, and a zero disabled byte, then appends directly or calls the vector insert helper when at capacity. |
| `0x004a8350-0x004a8418` | `InsertHandlerRecordAfterSibling` | Appends after the selected sibling in the forward child chain: it moves the selected record's `nextSiblingIndex` (`+0x10`) to the new record, sets selected `nextSiblingIndex` to the new index, updates the parent's `lastChildIndex` (`+0x08`) when the selected sibling was the tail, and creates a new record with `previousSiblingIndex` (`+0x0c`) set to the selected index, copied old next, caller handler, and zero disabled byte. |
| `0x004a8420-0x004a8680` | `RemoveHandlerRecordAndDisableSubtree` | Disables the target record and descendants using the shared Deque as a scratch integer-index stack, enumerating descendants through `firstChildIndex`/`nextSiblingIndex`, then unlinks the target from parent `firstChildIndex`/`lastChildIndex` and sibling `previousSiblingIndex`/`nextSiblingIndex`. |
```

- Populate `RECONSTRUCTION_CPP` with the [UID:00022A] block above after shared declarations are available.

For `source-3/project-documentation/by-memory/0x004a87a0-0x004a8810.EventDispatcherHandlerRecordVectorFree.md`:

- Replace metadata lines:

```text
*** COMPLETION:89 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
```

- Replace "Final C++ remains blank because the final vector type, helper name, and handler-record field names are still provisional." with:

```text
- First-draft C++ should now be populated as `FreeHandlerRecordVector(EventHandlerRecordVector *records)`. The vector type and record field names are resolved enough for first-draft code under the active combined-score/emitter gate.
```

- Populate `RECONSTRUCTION_CPP` with the [UID:000148] block above after shared declarations are available.

For `source-3/project-documentation/by-memory/0x004a8820-0x004a88d2.EventDispatcherHandlerRecordVectorAllocationHelpers.md`:

- Replace metadata lines:

```text
*** COMPLETION:89 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
```

- Replace "Rebuild handling: source-authored internal allocation support for the dispatcher 28-byte handler-record vector. Keep C++ blank because the final container abstraction and helper names remain provisional." with:

```text
- Rebuild handling: source-authored internal allocation support for the dispatcher 28-byte handler-record vector. First-draft C++ should now be populated as `AllocateHandlerRecordBuffer` and `FreeHandlerRecordBuffer`; final audit can still refine exact original helper spelling.
```

- Populate `RECONSTRUCTION_CPP` with the [UID:00022B] block above after shared declarations are available.

For `source-3/project-documentation/by-type/by-struct/EventDispatcherHandlerTreeLayouts.md`:

- Replace the current handler-record offset table with the table from "Heuristic / Inference Reanalysis And Validation" above.
- Replace the score rationale sentence that says final C++ remains blank below the `95/95` gate with:

```text
- First-draft C++ is now appropriate for the emitting by-memory helpers that clear the active combined-score/emitter gate. `95+` remains a final-audit quality target, not a first-draft blocker.
```

For `source-3/project-documentation/by-file/EventDispatcher.md` and `source-3/project-documentation/by-class/EventDispatcher.md`:

- No owner/emitter change is recommended.
- Add a support note near the handler-tree/vector discussion:

```text
The EventDispatcher handler tree uses 28-byte `EventHandlerRecord` entries with `parentIndex`, `firstChildIndex`, `lastChildIndex`, `previousSiblingIndex`, `nextSiblingIndex`, `handler`, and `isDisabled` fields. The helper cluster at `0x004a82b0-0x004a8795`, vector free at `0x004a87a0`, and allocation pair at `0x004a8820-0x004a88d2` should emit through this EventDispatcher source family under the active first-draft code-entry gate.
```

## Supervisor-Owned Coverage Row Replacements

Replace the existing [UID:00022A] row in `source-3/project-documentation/by-memory/-coverage-report.md` near the `0x004a82a9-0x004a82b0` and `0x004a8795-0x004a87a0` padding rows with:

```text
    - [UID:00022A][0x004a82b0-0x004a8795.EventDispatcherHandlerRecordRelinkHelpers](by-memory/0x004a82b0-0x004a8795.EventDispatcherHandlerRecordRelinkHelpers.md) 0x004a82b0-0x004a8795 | method-cluster | EventDispatcher handler-record relink/remove/vector helpers : reconstructable : 88% : strong : Reanalysis resolves the 28-byte record fields as parentIndex/firstChildIndex/lastChildIndex/previousSiblingIndex/nextSiblingIndex/handler/isDisabled, confirms SetPaneOrder/RemovePaneEntry/constructor/rebuild direct callers, all internal and neighboring `0xcc` padding spans, shared Deque<int> scratch-stack dependency for subtree disabling, circular handler-list-node link allocation, vector rebind/reserve helpers, and `ui/core/EventDispatcher.cpp` ownership/emitter. First-draft C++ should be emitted under the active combined-score gate; stale 95/95 blocker wording should be removed.
```

Replace the existing [UID:000148] row between the `0x004a8795-0x004a87a0` and `0x004a8810-0x004a8820` padding rows with:

```text
    - [UID:000148][0x004a87a0-0x004a8810.EventDispatcherHandlerRecordVectorFree](by-memory/0x004a87a0-0x004a8810.EventDispatcherHandlerRecordVectorFree.md) 0x004a87a0-0x004a8810 | function | EventDispatcher handler-record vector free : reconstructable : 89% : strong : Reanalysis confirms the exact `0x70` body, direct callers and `0x004a7d50` thunk, vector header begin/end/capacity fields, 28-byte capacity span math, MSVC large-allocation saved-base validation, runtime free, pointer clears, EventDispatcher ownership/emitter, and resolved `EventHandlerRecordVector`/`EventHandlerRecord` field names. First-draft C++ should be emitted as `FreeHandlerRecordVector` under the active combined-score gate.
```

Replace the existing [UID:00022B] row between the `0x004a8810-0x004a8820` and `0x004a88d2-0x004a88e0` padding rows with:

```text
    - [UID:00022B][0x004a8820-0x004a88d2.EventDispatcherHandlerRecordVectorAllocationHelpers](by-memory/0x004a8820-0x004a88d2.EventDispatcherHandlerRecordVectorAllocationHelpers.md) 0x004a8820-0x004a88d2 | function-pair | EventDispatcher handler-record vector allocation helpers : reconstructable : 89% : strong : Reanalysis confirms allocator/free sizes, internal and neighboring `0xcc` padding spans, zero-count null return, `0x09249249` max record count, 28-byte sizing, small `operator new` path, 32-byte aligned large allocation with saved raw base, paired header validation/free, three allocator callers and one free caller, and EventDispatcher-local source placement. First-draft C++ should be emitted as `AllocateHandlerRecordBuffer`/`FreeHandlerRecordBuffer` under the active combined-score gate.
```

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B002","command_id":"000000004165","destination_path":"executed-b-agent-research/B002/00022A-000148-00022B-eventdispatcher-handler-record-source-quality.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:24","uid":"00022A"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
