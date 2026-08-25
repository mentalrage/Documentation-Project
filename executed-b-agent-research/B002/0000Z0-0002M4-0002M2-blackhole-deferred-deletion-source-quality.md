** TARGET-REPORT-UID:0000Z0 **
** AUTHOR-AGENT-ID:B002 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# 0000Z0 / 0002M4 / 0002M2 BlackHole Deferred Deletion Source-Quality

Assignment: `B002-goal2-blackhole-deferred-deletion-source-quality-0000Z0-0002M4-0002M2-20260617`

Report status: final for supervisor review. This is report-only work; no by-* docs, generated reports, generated source, IDA DB, source files, or `by-memory/-coverage-report.md` were edited.

## Scope And Primary Recommendation

Primary targets:

- [UID:0000Z0] `by-memory/0x004690b0-0x00469288.BlackHoleDeferredDeletionQueue.md`
- [UID:0002M4] `by-memory/0x00469200-0x00469233.BlackHoleReleaseQueuedOwnedObjects.md`
- [UID:0002M2] `by-memory/0x00469240-0x00469288.BlackHoleScalarDeletingDestructor.md`

Recommended outcome:

- [UID:0000Z0] should stop being treated as an emitting source body. Reclassify it as a non-emitting exact-method index over the BlackHole constructor, destructor, generic enqueue, pane enqueue adapter, drain method, scalar deleting destructor wrapper, and internal padding. Recommended score: `88/92`, `RECONSTRUCTABLE:FALSE`, canonical owner `[UID:00000W] BlackHole`, no emitter, no formal C++.
- [UID:0002M4] is a real source-authored `BlackHole` method. Raise to `87/92`, keep owner/emitter `[UID:00000W] BlackHole`, keep reconstructable/emitting, and populate first-draft C++ if the supervisor accepts the `LObject*` queue-entry spelling.
- [UID:0002M2] is the MSVC scalar deleting destructor wrapper for `BlackHole`. Raise to `86/92`, keep owner/emitter `[UID:00000W] BlackHole`, keep reconstructable as a source-declared/generated-binary virtual destructor artifact, but leave formal C++ blank.

The open source-facing question that remains is header spelling, not behavior: whether final emitted headers model `Singleton<BlackHole>` explicitly or only model the recovered process-global pointer. That should not cap [UID:0002M4] below the 85/85 gate.

## Evidence Checked

Existing docs reviewed:

- Primary target pages [UID:0000Z0], [UID:0002M4], [UID:0002M2].
- Support pages [UID:00000W] `BlackHole`, [UID:0000HR] `BlackHole` file, [UID:0002M0] constructor, [UID:0002M1] ordinary destructor, [UID:0002M3] generic enqueue, [UID:0000Z1] pane-specific enqueue, [UID:0000Q8] `g_pApplicationCleanupQueue`, [UID:00028K] storage, [UID:0001TT] layout, [UID:0001X2] vtable, [UID:000079] `List`, and [UID:0000EO] `EventDispatcher`.
- Support callers in `ApplicationCleanupResources`, `PaneCore`, `Motion`, and generated/source-tree coverage.
- Existing executed B reports were searched for this UID/range. No prior BlackHole-specific B report was found; older reports only mention the BlackHole deferred-delete route as supporting context.

Live IDA/MCP and binary evidence checked:

- Functions:
  - `0x004690b0`: `BlackHole_Constructor`, size `0x46`.
  - `0x00469100`: `BlackHole_Destructor`, size `0x15`.
  - `0x00469120`: `sub_469120`, size `0x51`.
  - `0x00469180`: `sub_469180`, size `0x7a`.
  - `0x00469200`: `sub_469200`, size `0x33`.
  - `0x00469240`: `sub_469240`, size `0x48`.
  - `0x00469288`: no function; successor bytes are padding / next vtable-data region, not another BlackHole body.
- Direct-edge evidence:
  - [UID:0002M4] has direct callers at `0x00464c19` inside application cleanup and `0x004a6c4a` inside idle processing.
  - [UID:0002M2] has a vtable data reference from `0x00613118`.
  - Generic enqueue [UID:0002M3] has a direct caller at `0x0053a0bc` from the `Motion` timer path.
  - Pane enqueue [UID:0000Z1] has 83 direct code refs, including `Pane::MarkForDeletion` at `0x005446a7`.
- Pointer/table evidence:
  - `0x00613118` points to `0x00469240`, followed by inherited `List`/`LObject` virtual entries.
  - RTTI globals include `BlackHole`, `List`, and `Singleton<BlackHole>`, supporting a `List` primary base plus singleton template relationship.
  - `0x0067a74c` is read/written as the process-global BlackHole pointer. The constructor writes it, ordinary and scalar deleting destructors clear it, and callers load it before queue/drain calls.
- Exact padding:
  - `0x004690f6-0x00469100`, `0x00469115-0x00469120`, `0x00469171-0x00469180`, `0x004691fa-0x00469200`, `0x00469233-0x00469240`, and `0x00469288-0x00469290` are `0xcc` alignment.
- Generated output:
  - `auto-generated/NexusTK/ui/core/BlackHole.cpp` exists but is empty.
  - `auto-generated/-ag-memory-coverage.md` routes the exact BlackHole child methods to `BlackHole.cpp` but reports no code for them.

## Source Shape And Names

Best source-facing class shape:

```cpp
class BlackHole : public List, public Singleton<BlackHole>
{
public:
    BlackHole();
    virtual ~BlackHole();

    void EnqueueIfMissing(LObject* object);
    void QueuePaneForDeferredDeletion(Pane* pane);
    void ReleaseQueuedOwnedObjects();
};

extern BlackHole* g_pApplicationCleanupQueue;
```

The `Singleton<BlackHole>` base/template relationship is strongly supported by RTTI and by the constructor's `this + 0x14` empty-subobject-looking artifact. The binary does not require a distinct data member for the singleton base; the real storage is the global pointer at `0x0067a74c`. If final headers do not model `Singleton<T>` yet, the class should still remain `class BlackHole : public List` with the recovered global documented as the singleton storage.

Best names and signatures:

- Constructor: `BlackHole::BlackHole()`; calls `List::List(4, 1024)`, stores the singleton/global pointer, and installs the BlackHole vtable.
- Ordinary destructor: `BlackHole::~BlackHole()` non-deleting body; clears the singleton/global pointer and tail-calls `List::~List()`.
- Generic enqueue: `void BlackHole::EnqueueIfMissing(LObject* object)` or, if `LObject` is not available in the final header pass, `void BlackHole::EnqueueIfMissing(void* object)` with a comment that entries must be polymorphic owned objects. Behavior is null guard, linear duplicate scan, append one pointer.
- Pane enqueue adapter: `void BlackHole::QueuePaneForDeferredDeletion(Pane* pane)`. It is not a PaneChildRegistry body. It detaches the pane from layer/event/timer ownership before sharing the same duplicate-suppressing append path.
- Drain method: `void BlackHole::ReleaseQueuedOwnedObjects()`. It visits every queued pointer, deletes non-null entries through the first virtual slot, then clears the inherited list.
- Scalar deleting destructor wrapper: compiler-generated `BlackHole::` scalar deleting destructor for the virtual destructor slot. No handwritten source body should be entered for [UID:0002M2].

Queue entry type:

- Storage is exactly a fixed-size `List` of 4-byte pointer entries: constructor passes `elementSize=4`, `pageSize=1024`.
- The queue does not hold arbitrary POD pointers. Drain calls each queued object's first vtable slot with delete flag `1`, which is source-equivalent to `delete object;` through a polymorphic base pointer.
- The best high-probability type is `LObject*`: `LObject` is the documented runtime base with a scalar deleting destructor in vtable slot 0, and both queued families checked here are object/pane-style polymorphic instances. If final project headers do not yet make every queued family derive visibly from `LObject`, use `void*` in metadata but describe the semantic type as "owned polymorphic object pointer."

Inherited `List` API and base policy:

- `BlackHole` should be modeled as deriving from `List`, not containing a `List` member. The constructor calls `List::List` with `ecx=this`; methods use inherited `count` at `this+0x0c`; and virtual slots match `List::GetElementAt` at `+0x10`, `List::Append` at `+0x18`, and `List::RemoveAll` at `+0x20`.
- Composition is rejected because no `this+member` list address is formed. Generic `List` ownership is also rejected for the exact BlackHole methods because callers load `g_pApplicationCleanupQueue` and dispatch BlackHole-specific cleanup semantics.

Singleton storage naming:

- Keep `g_pApplicationCleanupQueue` as the documentation/emission name for `0x0067a74c`. It is more precise than `g_pBlackHole` because all direct consumers use it as the deferred application cleanup queue.
- Add a support note that RTTI proves a `Singleton<BlackHole>` relationship; if a future header pass formalizes `Singleton<T>`, `g_pApplicationCleanupQueue` can be described as the instantiated singleton storage/backing pointer rather than an unrelated public global.

## Target-By-Target Findings

### [UID:0000Z0] BlackHoleDeferredDeletionQueue

This range is not one source-authored method. It is an aggregate island from `0x004690b0` through `0x00469288` containing six exact child functions and five internal padding gaps. The exact children already carry the source behavior. Keeping the aggregate reconstructable/emitting risks duplicate generated source or a misleading formal C++ block.

Recommendation:

- `COMPLETION:88`
- `CONFIDENCE:92`
- `CANONICAL_OWNER:00000W`
- `RECONSTRUCTABLE:FALSE`
- `EMITTER_UIDS:` blank
- Formal C++ blank with an explicit "exact-method index only" reason.

### [UID:0002M4] BlackHoleReleaseQueuedOwnedObjects

This is a real `BlackHole` method and the name is defensible. It has two direct lifecycle callers and exact behavior: iterate inherited list count, fetch each 4-byte pointer through `List::GetElementAt`, delete non-null queued objects through virtual destructor slot 0 with flag `1`, and clear the list through `List::RemoveAll`.

Recommendation:

- `COMPLETION:87`
- `CONFIDENCE:92`
- `CANONICAL_OWNER:00000W`
- `RECONSTRUCTABLE:TRUE`
- `EMITTER_UIDS:00000W`
- Populate first-draft C++ if the supervisor accepts `LObject*` as the queue-entry spelling.

### [UID:0002M2] BlackHoleScalarDeletingDestructor

This is not handwritten logic. It is the compiler wrapper for the virtual destructor slot: restore the BlackHole vtable, clear `g_pApplicationCleanupQueue`, call `List::~List`, optionally free storage based on the delete flags, and handle the guarded vector-delete-looking path. The source declaration that produces it is `virtual ~BlackHole();`, not a separate source method.

Recommendation:

- `COMPLETION:86`
- `CONFIDENCE:92`
- `CANONICAL_OWNER:00000W`
- `RECONSTRUCTABLE:TRUE`
- `EMITTER_UIDS:00000W`
- Formal C++ must remain blank for [UID:0002M2]. The behavior belongs to the virtual destructor declaration / ordinary destructor body, not to a user-authored scalar deleting destructor source block.

## Heuristic / Inference Reanalysis And Validation

Best defensible inferences:

- `BlackHole` is a `List`-derived singleton cleanup queue. Evidence: `List::List(4,1024)` is invoked with `this`, inherited `List` count/data access is used in every queue method, the vtable contains inherited `List` entries, and RTTI includes `BlackHole`, `List`, and `Singleton<BlackHole>`.
- The queue stores owned polymorphic object pointers. Evidence: entries are 4 bytes, duplicate comparison dereferences pointer entries, drain calls the pointed object's first virtual slot with delete flag `1`, and all checked producers pass pane/object instances after detaching them from other ownership lists.
- `g_pApplicationCleanupQueue` is the best current global name. Evidence: it is the exact storage at `0x0067a74c`; it is constructed during application startup, drained during idle and cleanup, and cleared by both destructor paths. `g_pBlackHole` is shorter but loses the cleanup-queue role used by all callers.
- [UID:0000Z1] is `BlackHole::QueuePaneForDeferredDeletion(Pane*)`, not a `PaneChildRegistry` or `Pane` implementation. Evidence: the method uses the BlackHole inherited list and global queue object, has many pane callers, and performs pane-specific detachment only as pre-cleanup before appending to the BlackHole queue.
- [UID:0002M4] should be represented as source `delete object;`, not as an explicit scalar-deleting-destructor call. Evidence: C++ virtual `delete` through `LObject*` produces the observed vtable slot 0 call with delete flag `1`; source code would not normally spell the scalar deleting destructor.
- [UID:0002M2] stays reconstructable but C++ blank. Evidence: the wrapper is needed by the vtable and rebuild ABI, but it is compiler-generated from `virtual ~BlackHole()` and should not be entered as user source.

Rejected alternatives:

- Dead or unreferenced helper island: rejected. [UID:0002M4] has two direct callers, [UID:0002M2] is vtable-referenced, generic enqueue has a Motion caller, pane enqueue has broad direct pane callers, and the constructor/destructor are tied to application lifecycle.
- Aggregate source body for [UID:0000Z0]: rejected. The range contains multiple functions plus `0xcc` pads; exact children are the correct source units.
- `List` composition: rejected. The binary never computes a list member address; it constructs and accesses `List` at object offset 0.
- Queue of panes only: rejected. The generic enqueue caller from `Motion` proves at least one non-pane producer, while the pane helper is only an adapter.
- Arbitrary `void*` ownership with no type direction: rejected. Drain requires a valid vtable and delete semantics. `void*` is acceptable only as a conservative emitted spelling if the common base header is not ready.
- Handwritten scalar deleting destructor source: rejected. The delete flag handling, vtable slot reference, guard check, and optional storage free match MSVC-generated deleting destructor glue.
- Moving implementation into `Pane` or `Motion`: rejected. Those classes enqueue themselves, but the list storage, singleton pointer, deduplication, and drain ownership belong to BlackHole.

Validation of existing docs:

- Current child behavior docs for constructor/destructor/enqueue/pane enqueue/drain/scalar destructor are directionally correct.
- Existing [UID:0000Z0] reconstructable/emitting aggregate treatment is now contradicted by the exact-child evidence and should be reclassified.
- Existing [UID:0002M4] blank-C++ rationale is outdated: the former blocker was queued object type and inherited `List` API names. `List` API names are now documented, and `LObject*` is the best defensible queue-entry type.
- Existing [UID:0002M2] blank-C++ treatment is correct, but the reason should be sharpened to "MSVC scalar deleting destructor wrapper produced by source virtual destructor declaration."
- Existing `PaneChildRegistry` stale alias should remain ignored, but [UID:0000Z1] metadata should be normalized to BlackHole class ownership if the supervisor touches support pages.

Score/source-placement/final-C++ impact:

- [UID:0000Z0] improves by becoming a non-emitting exact-method index rather than trying to clear the source-body gate.
- [UID:0002M4] clears the 85/85 gate and is ready for a formal source-like method body.
- [UID:0002M2] clears the evidence gate but must keep formal C++ blank because only the declaration is source-authored.
- Support class/file docs can safely state `BlackHole.cpp`, `class BlackHole : public List, public Singleton<BlackHole>`, and `g_pApplicationCleanupQueue` as singleton backing storage. Exact header spelling can stay below final audit without blocking the primary method score changes.

## First-Draft C++ Recommendation

[UID:0000Z0] should not receive a formal `RECONSTRUCTION_CPP CODE` block. It should be non-reconstructable/non-emitting because it is an exact-method index.

[UID:0002M4] can receive the following first-draft C++ if the supervisor accepts `LObject*` for the queued entry type:

```cpp
void BlackHole::ReleaseQueuedOwnedObjects()
{
    for (int i = 0; i < count; ++i)
    {
        LObject* object = *reinterpret_cast<LObject**>(GetElementAt(i));
        if (object != NULL)
            delete object;
    }

    RemoveAll();
}
```

If final headers avoid exposing `LObject` in `BlackHole.cpp`, use a private typedef such as `typedef LObject BlackHoleQueuedObject;` or keep the formal signature note as `void*` storage while preserving `delete object;` source semantics. Do not replace the `delete` with an explicit scalar-deleting-destructor call in source C++.

[UID:0002M2] should not receive a formal C++ block. The correct source representation is the class declaration / ordinary destructor:

```cpp
class BlackHole : public List, public Singleton<BlackHole>
{
public:
    virtual ~BlackHole();
};
```

Support-only draft snippets if the supervisor chooses a class-wide follow-up in the same pass:

```cpp
BlackHole::BlackHole()
    : List(sizeof(LObject*), 1024)
{
    g_pApplicationCleanupQueue = this;
}

BlackHole::~BlackHole()
{
    g_pApplicationCleanupQueue = NULL;
}

void BlackHole::EnqueueIfMissing(LObject* object)
{
    if (object == NULL)
        return;

    for (int i = 0; i < count; ++i)
    {
        if (*reinterpret_cast<LObject**>(GetElementAt(i)) == object)
            return;
    }

    Append(1, &object);
}

void BlackHole::QueuePaneForDeferredDeletion(Pane* pane)
{
    if (pane == NULL)
        return;

    pane->RemoveFromLayer();
    pane->UnregisterEventHandler();
    g_pTimerMgr->RemoveAllPendingEvents(&pane->timerHandler);
    EnqueueIfMissing(pane);
}
```

Do not treat the support snippets as a request to populate non-primary formal blocks unless the supervisor also updates those support pages. They are included to make the source shape explicit and to prevent stale `PaneChildRegistry` or raw `sub_469180` naming from surviving.

## Exact Score And Metadata Recommendations

Primary targets:

| UID | Current | Recommended | Metadata recommendation |
|---|---:|---:|---|
| `0000Z0` | `82/90` | `88/92` | `CANONICAL_OWNER:00000W`; `RECONSTRUCTABLE:FALSE`; `EMITTER_UIDS:` blank; formal C++ blank; describe as exact-method index. |
| `0002M4` | `82/90` | `87/92` | Keep `CANONICAL_OWNER:00000W`; keep `RECONSTRUCTABLE:TRUE`; keep `EMITTER_UIDS:00000W`; populate first-draft C++. |
| `0002M2` | `82/90` | `86/92` | Keep `CANONICAL_OWNER:00000W`; keep `RECONSTRUCTABLE:TRUE`; keep `EMITTER_UIDS:00000W`; formal C++ blank as generated scalar deleting destructor wrapper. |

Support recommendations:

- [UID:00000W] `BlackHole` class: update source-shape text to `List` primary base plus `Singleton<BlackHole>` relationship, `g_pApplicationCleanupQueue` backing storage, and `LObject*` / owned polymorphic pointer queue entries. Recommended class score after update: `88/93`.
- [UID:0000HR] `BlackHole` file: keep route `NexusTK/ui/core/BlackHole.cpp`; update to say the file is empty only because child formal C++ is mostly blank, not because the class is dead. Recommended file score after update: `87/92`.
- [UID:0001TT] `BlackHoleLayout`: update from unresolved concrete shape to `List` primary base, size `0x14`, pointer-entry list, singleton relationship external/empty. Recommended layout score: `87/93`.
- [UID:0001X2] `BlackHoleVtable`: update slot table to identify [UID:0002M2] as generated scalar deleting destructor and inherited `List` virtual entries. Recommended score: `88/92`.
- [UID:0000Q8] and [UID:00028K] `g_pApplicationCleanupQueue`: keep name, add `Singleton<BlackHole>` backing-storage caveat. Recommended scores: global `89/90`, storage `88/91`.
- [UID:0000Z1] `BlackHoleQueuePaneForDeferredDeletion`: fix metadata if needed to `CANONICAL_OWNER:00000W`, `EMITTER_UIDS:00000W`; reject `PaneChildRegistry` source ownership. Recommended score: `88/93`.
- [UID:0002M3] `BlackHoleEnqueueIfMissing`: update queued-entry type and Motion caller meaning; recommended score `87/92`.
- [UID:0002M0] and [UID:0002M1]: no behavioral score change required, but coverage should be synchronized from stale `80%` to the current `86%` if the supervisor refreshes coverage rows.

## Support Docs To Update

Suggested supervisor-owned edits:

- `by-memory/0x004690b0-0x00469288.BlackHoleDeferredDeletionQueue.md`: reclassify as non-emitting exact-method index, update owner to [UID:00000W], and remove any implication that the aggregate itself needs formal source C++.
- `by-memory/0x00469200-0x00469233.BlackHoleReleaseQueuedOwnedObjects.md`: add `LObject*`/owned polymorphic pointer inference, inherited `List` API names, direct lifecycle callers, and first-draft C++.
- `by-memory/0x00469240-0x00469288.BlackHoleScalarDeletingDestructor.md`: sharpen generated-wrapper policy and explicitly say formal C++ remains blank.
- `by-class/BlackHole.md`: add final declaration shape, `List` primary base, `Singleton<BlackHole>` RTTI evidence, queue-entry type direction, and method names.
- `by-file/BlackHole.md`: update source route and generated-empty caveat.
- `by-global/g_pApplicationCleanupQueue.md` and storage page [UID:00028K]: add singleton backing-storage relationship.
- `by-type/by-struct/BlackHoleLayout.md` and `by-type/by-vtable/BlackHoleVtable.md`: update inherited `List` layout and scalar deleting destructor policy.
- `by-memory/0x00469180-0x004691fa.BlackHoleQueuePaneForDeferredDeletion.md`: normalize owner/emitter to BlackHole class if not already applied in the page body.
- `proposed-source-tree.md`: optional text-only clarification that `BlackHole.cpp` is a real source file with class child methods; the stale `PaneChildRegistry` row is only an ignored historical alias.

## Supervisor-Owned by-memory/-coverage-report.md Row Text

Replace the current BlackHole block beginning at the [UID:0000Z0] row with this text if the supervisor applies the primary recommendations and support row sync:

```md
    - [UID:0000Z0][0x004690b0-0x00469288.BlackHoleDeferredDeletionQueue](by-memory/0x004690b0-0x00469288.BlackHoleDeferredDeletionQueue.md) 0x004690b0-0x00469288 | class aggregate / exact-method index | BlackHoleDeferredDeletionQueue : not_reconstructable : 88% : very strong : B002 2026-06-17 reclassifies this as a non-emitting exact-method index over BlackHole constructor/destructor/enqueue/pane-queue/drain/scalar-deleting-wrapper children plus internal `0xcc` padding; exact children carry source ownership through [UID:00000W] and source file [UID:0000HR], so no aggregate formal C++ should be emitted.
        - [UID:0002M0][0x004690b0-0x004690f6.BlackHoleConstructor](by-memory/0x004690b0-0x004690f6.BlackHoleConstructor.md) 0x004690b0-0x004690f6 | constructor | BlackHoleConstructor : reconstructable : 86% : very strong : Exact BlackHole constructor bounds; `List(sizeof(pointer),1024)` primary-base setup, singleton/global write to `g_pApplicationCleanupQueue`, BlackHole vtable install, Application initialization caller, and adjacent `0xcc` padding are documented; class-wide source shape is `List` plus `Singleton<BlackHole>`.
        - [UID:0000VN][-ignored](by-memory/-ignored.md) 0x004690f6-0x00469100 | padding | BlackHole constructor/destructor alignment : ignored : 100% : strong : Confirmed `0xcc` alignment padding.
        - [UID:0002M1][0x00469100-0x00469115.BlackHoleDestructor](by-memory/0x00469100-0x00469115.BlackHoleDestructor.md) 0x00469100-0x00469115 | destructor | BlackHoleDestructor : reconstructable : 86% : very strong : Exact BlackHole non-deleting destructor bounds; vtable restore, `g_pApplicationCleanupQueue` clear, tail call to shared `List` teardown, no direct code callers outside generated destructor paths, and adjacent `0xcc` padding are documented.
        - [UID:0000VN][-ignored](by-memory/-ignored.md) 0x00469115-0x00469120 | padding | BlackHole destructor/enqueue alignment : ignored : 100% : strong : Confirmed `0xcc` alignment padding.
        - [UID:0002M3][0x00469120-0x00469171.BlackHoleEnqueueIfMissing](by-memory/0x00469120-0x00469171.BlackHoleEnqueueIfMissing.md) 0x00469120-0x00469171 | class method | BlackHoleEnqueueIfMissing : reconstructable : 87% : very strong : Generic BlackHole enqueue helper with Motion caller `0x0053a0bc`, null guard, inherited `List::GetElementAt` duplicate scan over owned polymorphic pointer entries, append through `List::Append`, and adjacent `0xcc` padding; source-facing signature should be `EnqueueIfMissing(LObject*)` or conservative `void*` storage with ownership note.
        - [UID:0000VN][-ignored](by-memory/-ignored.md) 0x00469171-0x00469180 | padding | BlackHole enqueue/pane-queue alignment : ignored : 100% : strong : Confirmed `0xcc` alignment padding.
        - [UID:0000Z1][0x00469180-0x004691fa.BlackHoleQueuePaneForDeferredDeletion](by-memory/0x00469180-0x004691fa.BlackHoleQueuePaneForDeferredDeletion.md) 0x00469180-0x004691fa | class method | BlackHoleQueuePaneForDeferredDeletion : reconstructable : 88% : very strong : Pane-specific BlackHole adapter with broad pane callers, detach-from-layer/event/timer cleanup, inherited `List` duplicate suppression and append, rejected `PaneChildRegistry` ownership, and adjacent `0xcc` padding; canonical owner/emitter should be [UID:00000W].
        - [UID:0000VN][-ignored](by-memory/-ignored.md) 0x004691fa-0x00469200 | padding | BlackHole pane-queue/drain alignment : ignored : 100% : strong : Confirmed `0xcc` alignment padding.
        - [UID:0002M4][0x00469200-0x00469233.BlackHoleReleaseQueuedOwnedObjects](by-memory/0x00469200-0x00469233.BlackHoleReleaseQueuedOwnedObjects.md) 0x00469200-0x00469233 | class method | BlackHoleReleaseQueuedOwnedObjects : reconstructable : 87% : very strong : BlackHole drain helper with cleanup/idle callers `0x00464c19` and `0x004a6c4a`, inherited `List::GetElementAt` loop over owned polymorphic pointer entries, source-equivalent virtual `delete`, final `List::RemoveAll`, adjacent `0xcc` padding, and accepted first-draft method C++.
        - [UID:0000VN][-ignored](by-memory/-ignored.md) 0x00469233-0x00469240 | padding | BlackHole drain/deleting-destructor alignment : ignored : 100% : strong : Confirmed `0xcc` alignment padding.
        - [UID:0002M2][0x00469240-0x00469288.BlackHoleScalarDeletingDestructor](by-memory/0x00469240-0x00469288.BlackHoleScalarDeletingDestructor.md) 0x00469240-0x00469288 | deleting destructor wrapper | BlackHoleScalarDeletingDestructor : reconstructable : 86% : very strong : MSVC scalar deleting destructor wrapper referenced by BlackHole vtable `0x00613118`; restores vtable, clears singleton/global storage, calls shared `List` teardown, conditionally frees object storage, and must keep formal C++ blank because the source-authored representation is `virtual ~BlackHole()`.
```

Keep the existing ignored stale-alias row for [UID:0000Z2] immediately after this block unless the supervisor separately deletes historical aliases.

If the storage global row is also updated, replace the [UID:00028K] row with:

```md
    - [UID:00028K][0x0067a74c-0x0067a750.g_pApplicationCleanupQueue](by-memory/0x0067a74c-0x0067a750.g_pApplicationCleanupQueue.md) 0x0067a74c-0x0067a750 | global pointer storage | g_pApplicationCleanupQueue : reconstructable : 88% : very strong : BlackHole singleton/deferred-cleanup queue backing pointer; constructor writes it, ordinary/scalar deleting destructor paths clear it, application idle/cleanup and pane/object producers read it, and RTTI supports a `Singleton<BlackHole>` source relationship while the recovered documentation/emission name remains `g_pApplicationCleanupQueue`.
```

## Validation Commands

After applying supervisor-owned doc and coverage edits:

> Executable block R001 was removed from this report and preserved verbatim in [0000Z0-0002M4-0002M2-blackhole-deferred-deletion-source-quality-removed.md](0000Z0-0002M4-0002M2-blackhole-deferred-deletion-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

Optional generated-output check after autogen:

> Executable block R002 was removed from this report and preserved verbatim in [0000Z0-0002M4-0002M2-blackhole-deferred-deletion-source-quality-removed.md](0000Z0-0002M4-0002M2-blackhole-deferred-deletion-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

## Changed Files And Leases

Changed files:

- `tools/leaser/Agents/Agent-B002/research/0000Z0-0002M4-0002M2-blackhole-deferred-deletion-source-quality.md`

Leases used: none. This was a research-report edit inside Agent-B002's assigned folder; no supervisor-owned by-* or coverage files were modified.

## Blockers And Follow-Up

No blocker remains for the primary recommendations.

Useful follow-up work:

- Apply a small support pass to [UID:0002M3] and [UID:0000Z1] so the generic and pane enqueue helpers use the same `LObject*` / owned-polymorphic-pointer wording as [UID:0002M4].
- Decide in a class/header-wide pass whether `Singleton<BlackHole>` is represented explicitly in generated declarations or only documented as RTTI/source-provenance for the global pointer.
- If formal C++ is populated for [UID:0002M4], run autogen and inspect `auto-generated/NexusTK/ui/core/BlackHole.cpp` for duplicate aggregate output; [UID:0000Z0] should be non-emitting before that check.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B002","command_id":"000000004165","destination_path":"executed-b-agent-research/B002/0000Z0-0002M4-0002M2-blackhole-deferred-deletion-source-quality.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:23","uid":"0000Z0"} -->
<!-- {"agent":"B002","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 0000Z0-0002M4-0002M2-blackhole-deferred-deletion-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B002/0000Z0-0002M4-0002M2-blackhole-deferred-deletion-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"0000Z0"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
