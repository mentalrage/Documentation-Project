** TARGET-REPORT-UID:0000ZT **
** AUTHOR-AGENT-ID:B010 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# 0000ZT / 0000ZW / 0000ZY / 000101 / 000103 ChangeMan Source-Quality Research

## Finalized Report / Current Recommendation

- Current recommendation: keep the ChangeMan constructor, register method, filtered unregister method, and comparator as source-authored ChangeMan source items; keep the scalar deleting destructor as source-declared/generated-binary destructor support with no formal target C++ body.
- Final disposition: no split is required. The target ranges are already exact half-open ranges. The main needed work is a source-quality refresh: names, signatures, score rows, and first-draft source bodies for source-authored leaves.
- Required action: supervisor/A-agent should update the target docs and coverage rows, then validate the edited by-* pages. B010 did not edit by-* files.
- Confidence: strong for ownership, layout, list behavior, comparator semantics, and destructor no-code handling; medium-high for exact original spelling of listener/scope names because no source headers are available and live IDA MCP was offline during this run.

## Supporting Research

## Target

- Target UIDs: `0000ZT`, `0000ZW`, `0000ZY`, `000101`, `000103`
- Target paths:
  - `by-memory/0x0047ec70-0x0047ed20.ChangeManConstructor.md`
  - `by-memory/0x0047ed50-0x0047ed80.ChangeManRegister.md`
  - `by-memory/0x0047ed80-0x0047ee18.ChangeManUnregisterFiltered.md`
  - `by-memory/0x0047ef20-0x0047ef3f.CompareChangeEntries.md`
  - `by-memory/0x0047ef50-0x0047efae.ChangeManScalarDeletingDestructor.md`
- Source queue/report row: refreshed `project-level/-auto-completion-stats.md`, low-score ChangeMan source-quality cluster.
- Current supervisor classification: B-preferred source-quality and heuristic/inference pass.
- Current scores and parent state:

| UID | Current score | Owner | Emitter | Current state |
| --- | --- | --- | --- | --- |
| `0000ZT` | `84/90` | `00001K` ChangeMan class | `00001K` | Constructor, source-authored, blank formal C++ |
| `0000ZW` | `84/90` | `00001K` ChangeMan class | `00001K` | Register method, source-authored, blank formal C++ |
| `0000ZY` | `84/90` | `00001K` ChangeMan class | `00001K` | Filtered unregister method, source-authored, blank formal C++ |
| `000101` | `84/90` | `0000I2` ChangeMan file | `0000I2` | File-local comparator helper, source-authored, blank formal C++ |
| `000103` | `84/90` | `00001K` ChangeMan class | `00001K` | MSVC scalar deleting destructor wrapper, blank formal C++ |

## Executive Recommendation

- Raise `0000ZT` from `84/90` to `86/90` after adding the source-quality note below and first-draft constructor body.
- Raise `0000ZW` from `84/90` to `86/90` after replacing the return-type caveat with the checked best inference: source-facing `void`, with the unused `EAX` insert-index residue rejected as non-contractual.
- Raise `0000ZY` from `84/90` to `86/90` after replacing the bool-only `allMessages` wording with byte/enum scope semantics: exact `1` means all message types, exact `0` means message-type match, other nonzero values do not match dispatch.
- Raise `000101` from `84/90` to `86/91` after recording the comparator as a file-local `static`/private helper that compares only `ChangeManEntry::owner` and exists to group registrations for `SortedListFindFirstEqual`.
- Raise `000103` from `84/90` to `86/91` if the page is updated to prove no formal C++ body should be populated in that memory page. Keep `RECONSTRUCTABLE:TRUE`, owner/emitter `00001K`, and a blank `RECONSTRUCTION_CPP CODE` block because the source declaration/destructor semantics are required, while the scalar deleting wrapper itself is compiler-generated.
- Do not change owner/emitter routing for these five targets.

## Supervisor Active Recheck

- Supervisor instruction: `ChangeMan source-quality cluster [UID:0000ZT], [UID:0000ZW], [UID:0000ZY], [UID:000101], and [UID:000103]`.
- Split repair: not required. Existing exact target ranges are bounded by adjacent exact children or padding. The only stale split text found was in older B002 optional row recommendations that used `0x0047ed73`, `0x0047ee1c`, and `0x0047ef33`; those are rejected. Current exact ranges are `0x0047ed50-0x0047ed80`, `0x0047ed80-0x0047ee18`, and `0x0047ef20-0x0047ef3f`.
- Source-bearing children in scope: all five target pages are already represented. Four source-authored pages are ready for first-draft source bodies; the scalar deleting destructor is intentionally no-code in its formal block.

## Inference Research Guidance Check

- `by-structure.md` code-entry gate: all five targets are reconstructable, have nonblank emitters that route to `auto-generated/NexusTK/app/ChangeMan.cpp`, and have average scores greater than `85`. This makes code entry eligible, not automatic.
- `inference_research.md` impact: address adjacency alone was not used as ownership proof. Ownership is based on constructor allocation, class layout, vtable refs, singleton lifecycle, wrapper callers, list field access, and file/class pages clearing the routing gate.
- Existing documentation was treated as evidence, not authority. The current pages are internally consistent, while older B002 optional row ranges are stale and rejected.
- IDA fact versus inference:
  - IDA fact from existing docs: exact function sizes/bounds, xrefs, disassembly stores/calls, list slot offsets, vtable slot, singleton xrefs.
  - Documentation evidence: by-class/by-file/type/global pages and current generated reports.
  - Inference: source names, return types, enum spelling, and whether `ChangeMan.cpp` was standalone versus folded into `Application.cpp`.

## Heuristic / Inference Reanalysis And Validation

### Issue: register/unregister source names

- Best direction: keep filenames/descriptive docs as `ChangeManRegister` and `ChangeManUnregisterFiltered`, but first-draft C++ should use `ChangeMan::Register` and a filtered overload `ChangeMan::Unregister`.
- Evidence checked: `ApplicationRegisterChangeListener` and `ApplicationUnregisterChangeListener` wrapper leaves forward through `g_pChangeMan`; `ChangeMan` class page records safe IDA names `ChangeMan_Register` and `ChangeMan_UnregisterFiltered`; B002 prior report names the API family as `Register(...)`, filtered unregister, dispatch, and broad `UnregisterObject`.
- Rejected alternatives:
  - `Application` ownership: rejected because Application only forwards through `g_pChangeMan`.
  - `BackPane` ownership: rejected because BackPane only consumes broad cleanup.
  - raw `sub_47ED50` / `sub_47ED80`: rejected because descriptive names and wrappers now provide stronger naming evidence.
  - `UnregisterListener` for `0x0047ed80`: too narrow unless qualified, because it filters by owner, optional listener, and message scope.
- Residual caveat, not a blocker: exact original overload spelling is not source-proven. This should not cap the pages below `86`, but it should be recorded as descriptive/inferred.

### Issue: register/unregister return types

- Best direction: source-facing `void` for both `ChangeMan::Register` and filtered `ChangeMan::Unregister`.
- Evidence checked: target docs show register ends after `SortedListInsertSorted` and unregister ends after removals; wrapper docs record forwarding bodies and do not document any caller consuming a result. Current Application wrapper pages also keep C++ blank because exact public API spelling is not final.
- Rejected alternatives:
  - `int Register(...)` returning the insert index: possible binary residue because `SortedListInsertSorted` returns an index in `EAX`, but no checked wrapper/caller documentation proves a return-value contract. Mid-2000s source registration APIs commonly used `void` when callers did not consume an id.
  - bool success/failure: no branch or caller-use evidence supports success semantics.
- Residual caveat, not a blocker: live IDA caller-use proof could not be refreshed because MCP was offline. Existing wrapper/caller docs are sufficient for the `void` recommendation and the unavailable live refresh is documented as a confidence caveat, not an open question.

### Issue: entry/list layout

- Best direction: keep `ChangeManEntry` as a `0x10` byte record, 16 decimal bytes (Verified with `int_convert.py`), with owner/listener/scope/messageType at `+0x00/+0x04/+0x08/+0x0c`.
- Evidence checked: register stack stores, dispatch/unregister reads, comparator first-dword compare, `SortedList(0x10, CompareChangeEntries, 0x64)` construction where `0x64` is 100 decimal (Verified with `int_convert.py`).
- Rejected alternatives:
  - embedded list storage in `ChangeMan`: rejected because `ChangeManLayout` records only an 8-byte object and `+0x04` is an external `SortedList *`.
  - bool-only `allMessages`: rejected because dispatch treats only exact `1` as wildcard and exact `0` as message-typed; other nonzero scope values skip.
- Residual caveat, not a blocker: final enum spelling is not source-proven. Recommended descriptive enum: `ChangeMessageScope_MatchType = 0`, `ChangeMessageScope_AllTypes = 1`.

### Issue: list helper names

- Best direction: use `SortedList::InsertSorted`, `SortedList::FindFirstEqual`, `SortedList::GetElementAt`, and `SortedList::RemoveRange(index, 1)` or `RemoveAt(index, 1)` as descriptive helper names.
- Evidence checked: `SortedList` class/file pages and exact child pages `00037J`, `00037K`, `00037N`, and `00037P`.
- Rejected alternatives:
  - ChangeMan-local list helpers: rejected because exact helper pages are owned by `SortedList`, not `ChangeMan`.
  - `LowerBound` as final helper name: behaviorally close, but existing `SortedListFindFirstEqual` page proves `_bsearch` plus backward first-equal scan, so `FindFirstEqual` is more precise.
- Residual caveat, not a blocker: exact public `SortedList` header names are not source-proven. Descriptive helper names are sufficient for first-draft code and source-quality docs.

### Issue: comparator semantics

- Best direction: `CompareChangeEntries` is a file-local comparator that compares only `ChangeManEntry::owner` and returns `-1`, `0`, or `1`.
- Evidence checked: comparator target page, constructor data ref at `0x0047ece4`, and `ChangeManEntry` layout.
- Rejected alternatives:
  - Compare listener/message fields: rejected because docs record only the first dword load/compare.
  - Class method: rejected because it is passed as a plain comparator callback and has no `this` use.
  - public utility comparator: rejected because its only documented use is `ChangeMan` list construction.
- Residual caveat, not a blocker: exact linkage spelling (`static`, anonymous namespace, private file helper) is not source-proven. For mid-2000s C++, `static int CompareChangeEntries(...)` is the safest first draft.

### Issue: singleton/list owner

- Best direction: `g_pChangeMan`, `ChangeManLayout`, `ChangeManEntry`, `ChangeManVtable`, and the target methods belong to `ChangeMan.cpp` / `ChangeMan` class. `SortedList` owns the list mechanics; `Application` and `BackPane` are caller surfaces.
- Evidence checked: by-file `ChangeMan`, by-class `ChangeMan`, `g_pChangeMan`, `ChangeManLayout`, `ChangeManEntry`, Application wrapper leaves, BackPane broad unregister references.
- Rejected alternatives:
  - Absorb into `Application.cpp`: possible original-source layout, but rejected for current routing because the file page and proposed source tree already model `app/ChangeMan.cpp`, and the class has independent singleton/vtable/list state.
  - Attach comparator to class: weaker than file-local helper routing because the comparator is not a method.
  - Leave no-owner/non-emitting: rejected because all direct owner/emitter routes clear the current gates.
- Residual caveat, not a blocker: exact original folder remains medium confidence, but `NexusTK/app/ChangeMan.cpp` is the best current source root.

### Issue: scalar deleting destructor no-code proof

- Best direction: keep `000103` reconstructable and routed through `ChangeMan`, but do not populate that page's formal C++ block. Its body is MSVC scalar deleting destructor wrapper mechanics plus the source destructor's cleanup semantics.
- Evidence checked: `ChangeManScalarDeletingDestructor` page records the vtable slot-only xref at `0x00614cd0`, no direct code callers, vtable restore, list virtual destructor call with delete flag `1`, `g_pChangeMan` clear, `LObject` base cleanup, and optional delete flag handling. Constructor-cleanup and singleton-clear pages show separate compiler cleanup support.
- Rejected alternatives:
  - Enter scalar-deleting wrapper C++ in the target block: rejected because final source should declare/define `~ChangeMan()` and let MSVC regenerate deleting destructor glue.
  - Mark `000103` `RECONSTRUCTABLE:FALSE`: rejected for this unique destructor because the destructor semantics are source-declared/generated-binary effects for the `ChangeMan` class and current emitted route documents class lifetime. This differs from shared/folded wrapper-only helpers that have no unique source destructor semantics.
  - Populate no destructor source anywhere: rejected because `m_changeList` release and singleton clear are source-relevant `ChangeMan` lifetime behavior.
- Resolved placement decision: the proper place for the ordinary `~ChangeMan()` source body is the class/source declaration context, not the scalar deleting destructor page's formal block.

### Issue: owner/emitter routing and generated-output pollution

- Best direction: keep existing owner/emitter metadata for all five target pages. The formal C++ for source-authored method/helper pages can be populated after support declarations are synced; `000103` remains marker/no-code.
- Evidence checked: `auto-generated/-ag-memory-coverage.md` rows show all five targets route to `auto-generated/NexusTK/app/ChangeMan.cpp`; `by-file/ChangeMan.md` has valid `NexusTK/app/` path.
- Rejected alternatives:
  - route register/unregister methods to Application: rejected because wrappers are exact separate Application leaves.
  - route comparator through class: rejected because file-local helper has no `this`.
  - emit scalar deleting wrapper source: rejected as generated-output pollution.
- Residual caveat, not a blocker: class/type support snippets for `ChangeMan`, `ChangeManEntry`, `ChangeListener`, `ChangeMessageScope`, and `SortedList` should be synchronized before final generated C++ is considered complete.

## Evidence Standards Used

- Existing IDA-backed docs: target pages, aggregate ChangeMan page, ChangeMan class/file/type/global pages, Application wrapper pages, SortedList pages, Message pages.
- Generated reports: `by-memory/-coverage-report.md`, `auto-generated/-ag-memory-coverage.md`, `project-level/-auto-completion-stats.md`, `project-level/-resolved.md`, `project-level/-unresolved.md`.
- Prior B-agent report: B002 `0000ZZ-000100-changeman-method-source-quality.md` was used as a checked prior for API family and scope semantics, but its optional stale address rows are rejected.
- Live IDA MCP: attempted `http://127.0.0.1:13337/mcp`, `/sse`, and `/config.html` on 2026-06-19; all failed with connection refused/unable to connect. No fresh live-MCP facts were created by B010 in this run.
- Conversion proof: `int_convert.py` verified `0x10 == 16`, `0x18 == 24`, `0x64 == 100`, `0x1f == 31`, `0x30 == 48`, `0x98 == 152`, `0xb0 == 176`, and `0x5e == 94`.

## IDA MCP Facts

- Function/range facts from existing docs:
  - `0x0047ec70-0x0047ed20`, size `0xb0` / 176 decimal (Verified with `int_convert.py`): constructor.
  - `0x0047ed50-0x0047ed80`, size `0x30` / 48 decimal (Verified with `int_convert.py`): register method.
  - `0x0047ed80-0x0047ee18`, size `0x98` / 152 decimal (Verified with `int_convert.py`): filtered unregister method.
  - `0x0047ef20-0x0047ef3f`, size `0x1f` / 31 decimal (Verified with `int_convert.py`): comparator helper.
  - `0x0047ef50-0x0047efae`, size `0x5e` / 94 decimal (Verified with `int_convert.py`): scalar deleting destructor wrapper.
- Data/table/padding facts from existing docs:
  - `ChangeMan` object is `0x08` bytes: vtable/base at `+0x00`, `SortedList *` at `+0x04`.
  - `ChangeManEntry` is `0x10` bytes / 16 decimal (Verified with `int_convert.py`).
  - `SortedList` allocation object size is `0x18` bytes / 24 decimal (Verified with `int_convert.py`).
  - comparator is passed with initial capacity `0x64` / 100 decimal (Verified with `int_convert.py`).
  - destructor successor padding `0x0047efae-0x0047efb0` is `0xcc` before `ChattingUI`.
- Xref facts from existing docs:
  - Constructor called from `Application::Initialize`.
  - Register only directly called by `ApplicationRegisterChangeListener`.
  - Filtered unregister only directly called by `ApplicationUnregisterChangeListener`.
  - Comparator xref is constructor data/call argument.
  - Scalar deleting destructor has vtable data ref at `0x00614cd0` and no direct code callers.
- Vtable/global/type facts:
  - `ChangeManVtable` at `0x00614cd0` has first slot `0x0047ef50`.
  - `g_pChangeMan` at `0x0067ab2c` has lifecycle writes/clears from constructor/cleanup/destructor and reads from Application/BackPane wrappers.
- Negative IDA facts:
  - No evidence that Application or BackPane owns ChangeMan internals.
  - No evidence that `CompareChangeEntries` is a class method.
  - No evidence that the scalar deleting destructor should be hand-written in final source.

## Function / Child Inventory

| Range / Item | UID / Path | Role | Reconstructable | Direct Parent | Score Recommendation | Status |
| --- | --- | --- | --- | --- | --- | --- |
| `0x0047ec70-0x0047ed20` | `0000ZT` constructor | Source constructor | TRUE | `00001K` | `84/90 -> 86/90` | Update doc/row; first-draft C++ ready |
| `0x0047ed50-0x0047ed80` | `0000ZW` register | Source method | TRUE | `00001K` | `84/90 -> 86/90` | Update doc/row; first-draft C++ ready |
| `0x0047ed80-0x0047ee18` | `0000ZY` filtered unregister | Source method | TRUE | `00001K` | `84/90 -> 86/90` | Update doc/row; first-draft C++ ready |
| `0x0047ef20-0x0047ef3f` | `000101` comparator | File-local helper | TRUE | `0000I2` | `84/90 -> 86/91` | Update doc/row; first-draft C++ ready |
| `0x0047ef50-0x0047efae` | `000103` scalar deleting destructor | Generated-binary destructor wrapper | TRUE | `00001K` | `84/90 -> 86/91` | Update doc/row; keep formal C++ blank |

## Direct Xref / Caller Inventory

| Address / Item | Xref / Caller / Callee | Meaning |
| --- | --- | --- |
| `Application::Initialize` at `0x004644c1` | calls constructor | Constructs `ChangeMan` singleton |
| `0x004f4b43` | calls `0x0047ed50` | Application wrapper forwards listener registration |
| `0x004f4b63` | calls `0x0047ed80` | Application wrapper forwards filtered unregister |
| `0x0047ece4` | pushes/refs `0x0047ef20` | Constructor passes comparator to `SortedList` |
| `0x00614cd0` | vtable slot refs `0x0047ef50` | Destructor wrapper is vtable-generated support |
| `0x0067ab2c` | singleton global | Constructor publishes, cleanup/destructor clear, wrappers consume |

## Documentation Evidence And IDA Status

- Existing docs that support the conclusion:
  - `by-file/ChangeMan.md` owns `app/ChangeMan.cpp` and lists class/layout/vtable/entry/global/comparator.
  - `by-class/ChangeMan.md` records the complete method family and safe IDA labels.
  - `by-type/by-struct/ChangeManEntry.md` records the 4-field record and exact scope semantics.
  - `by-class/SortedList.md` and exact SortedList child pages prove helper ownership and descriptive names.
  - Application wrapper pages prove caller surface without owning the ChangeMan internals.
- Existing docs that are stale, incomplete, or contradicted:
  - Target pages still say formal final C++ remains blank under older or over-conservative final-source wording even though the active combined-score gate makes the four source-authored bodies eligible for first draft.
  - Older B002 optional rows used stale ranges for `0000ZW`, `0000ZY`, and `000101`; current target paths are correct.
  - Several unresolved rows still list generated `sub_4F3690`, `sub_4F3780`, `sub_4F4A90`, and `sub_4F4AC0` references, but those are support-helper names outside this target cluster.
- Generated/coverage report state:
  - `auto-generated/-ag-memory-coverage.md` marks the five targets as routed/emitting to `auto-generated/NexusTK/app/ChangeMan.cpp`.
  - `by-memory/-coverage-report.md` rows for the five targets are stale at `84%`.
  - `project-level/-auto-completion-stats.md` still lists all five target UIDs in low-score memory rows with combined `87.0`.

## Ranked Ownership Analysis

### 1. `ChangeMan` class and `app/ChangeMan.cpp`

- Evidence for: constructor allocation/lifecycle, `g_pChangeMan`, ChangeMan vtable, 8-byte layout, list field at `+0x04`, class/file docs, wrapper calls through singleton, valid source route.
- Evidence against: exact original source file could have been folded into `Application.cpp`, but current class/file/source-tree docs support a small app helper module and no evidence requires folding.
- Decision: accepted. Keep existing owner/emitter routes.

### 2. `Application`

- Evidence for: Application constructs singleton and owns wrapper methods that are direct callers for register/unregister/dispatch.
- Evidence against: wrappers load `g_pChangeMan` and call methods on ChangeMan. Application does not own list field, comparator, vtable, entry layout, or destructor behavior.
- Decision: rejected as target owner; accepted as caller/wrapper surface.

### 3. `SortedList`

- Evidence for: owns helper implementations at `0x004f3690`, `0x004f3780`, virtual get/remove slots, and storage mechanics.
- Evidence against: does not own `ChangeManEntry`, `g_pChangeMan`, comparator, or ChangeMan method bodies.
- Decision: rejected as target owner except for helper name support.

### Proposed new file/grouping, if applicable

- Proposed owner/name/path: no new owner required. Existing `by-file/ChangeMan.md` / `NexusTK/app/ChangeMan.cpp` remains the best current source grouping.
- Likely full contents: `ChangeMan` class, `ChangeManEntry`, `ChangeMan` layout declarations, `g_pChangeMan`, `CompareChangeEntries`, constructor/register/unregister/dispatch/broad cleanup/destructor semantics, and vtable generated by compiler.
- Candidate related items that belong: `0000ZT`, `0000ZW`, `0000ZY`, `0000ZZ`, `000100`, `000101`, `000103`, `0000QI`, `0001P4`, `0001TV`, `0001TW`, `0001X7`, `0002M8`.
- Candidate related items rejected: Application wrapper leaves stay with Application; SortedList helper bodies stay with SortedList; compiler cleanup helper `000102` and constructor cleanup `0000ZV` stay non-reconstructable as standalone source.
- Standalone, narrow, or broad source-file inference: narrow app helper source file, not a broad Application source takeover.

## Negative Evidence Summary

- Application wrapper caller evidence proves reachability, not ownership.
- BackPane teardown evidence proves use of broad unregister, not BackPane ownership of ChangeMan internals.
- Physical adjacency before ChattingUI does not imply chat ownership; padding separates the ranges.
- `SortedList` helper calls do not make these methods utility-owned; the list is a member field.
- Scalar deleting destructor body should not be copied into source just because it contains source cleanup semantics; its delete-flag wrapper is compiler ABI glue.

## First-Draft C++ Recommendation

The four source-authored target bodies are first-draft ready if the receiving class/file support declarations are added or already present. Exact original spellings remain descriptive, but the behavior and routing are strong enough for the active first-draft gate. The scalar deleting destructor target should stay blank.

Support declarations needed by the emitted source:

```cpp
enum ChangeMessageScope {
    ChangeMessageScope_MatchType = 0,
    ChangeMessageScope_AllTypes = 1
};

struct ChangeManEntry {
    void *owner;
    ChangeListener *listener;
    ChangeMessageScope scope;
    unsigned int messageType;
};
```

Recommended `000101` comparator body:

```cpp
static int CompareChangeEntries(const void *left, const void *right)
{
    const ChangeManEntry *leftEntry =
        static_cast<const ChangeManEntry *>(left);
    const ChangeManEntry *rightEntry =
        static_cast<const ChangeManEntry *>(right);

    const uintptr_t leftOwner = reinterpret_cast<uintptr_t>(leftEntry->owner);
    const uintptr_t rightOwner = reinterpret_cast<uintptr_t>(rightEntry->owner);

    if (leftOwner < rightOwner)
        return -1;
    if (leftOwner > rightOwner)
        return 1;
    return 0;
}
```

Recommended `0000ZT` constructor body:

```cpp
ChangeMan::ChangeMan()
    : LObject(),
      m_changeList(NULL)
{
    g_pChangeMan = this;
    m_changeList = new SortedList(sizeof(ChangeManEntry),
                                  CompareChangeEntries,
                                  100);
}
```

Recommended `0000ZW` register body:

```cpp
void ChangeMan::Register(void *owner,
                         ChangeListener *listener,
                         unsigned int messageType,
                         ChangeMessageScope scope)
{
    ChangeManEntry entry;
    entry.owner = owner;
    entry.listener = listener;
    entry.scope = scope;
    entry.messageType = messageType;

    m_changeList->InsertSorted(&entry);
}
```

Recommended `0000ZY` filtered unregister body:

```cpp
void ChangeMan::Unregister(void *owner,
                           ChangeListener *listener,
                           unsigned int messageType,
                           ChangeMessageScope scope)
{
    ChangeManEntry key;
    key.owner = owner;

    int index = m_changeList->FindFirstEqual(&key);
    if (index < 0)
        return;

    int count = m_changeList->GetCount();
    for (; index < count; ++index) {
        ChangeManEntry *entry =
            static_cast<ChangeManEntry *>(m_changeList->GetElementAt(index));
        if (entry == NULL || entry->owner != owner)
            break;

        const bool listenerMatches =
            (listener == NULL || entry->listener == listener);
        const bool messageMatches =
            (scope == ChangeMessageScope_AllTypes) ||
            (scope == ChangeMessageScope_MatchType &&
             entry->messageType == messageType);

        if (listenerMatches && messageMatches) {
            m_changeList->RemoveRange(index, 1);
            --index;
            --count;
        }
    }
}
```

Recommended ordinary destructor draft for class/source context only, not for `000103` formal block:

```cpp
ChangeMan::~ChangeMan()
{
    delete m_changeList;
    m_changeList = NULL;
    g_pChangeMan = NULL;
}
```

Do not populate `000103` with the ordinary destructor draft unless the supervisor intentionally moves destructor-source emission to that page and documents that the scalar-deleting wrapper details are excluded. The cleaner current recommendation is to keep `000103` as no-code proof and put ordinary destructor source in the class/source declaration context when the `ChangeMan` class C++ scaffold is populated.

## Exact Coverage Report Replacement Rows

Do not edit `by-memory/-coverage-report.md` directly from this B-agent report. Suggested replacements for the current rows at the existing address-ordered placement:

```text
    - [UID:0000ZT][0x0047ec70-0x0047ed20.ChangeManConstructor](by-memory/0x0047ec70-0x0047ed20.ChangeManConstructor.md) 0x0047ec70-0x0047ed20 | constructor | ChangeManConstructor : reconstructable : 86% : strong : B010 source-quality recheck confirms source-authored ChangeMan construction: `LObject` base setup, `g_pChangeMan` publication, vtable install, external `SortedList*` member allocation at `+0x04`, `sizeof(ChangeManEntry) == 0x10` / 16 decimal (Verified with `int_convert.py`), `CompareChangeEntries` callback, and initial capacity `0x64` / 100 decimal (Verified with `int_convert.py`); owner/emitter remain ChangeMan class UID `00001K`, and first-draft constructor C++ is ready after support declarations sync.
    - [UID:0000ZW][0x0047ed50-0x0047ed80.ChangeManRegister](by-memory/0x0047ed50-0x0047ed80.ChangeManRegister.md) 0x0047ed50-0x0047ed80 | method | ChangeManRegister : reconstructable : 86% : strong : B010 source-quality recheck confirms source-facing `void ChangeMan::Register(owner, listener, messageType, scope)`, stack construction of a `0x10` / 16-byte `ChangeManEntry` (Verified with `int_convert.py`), field order owner/listener/scope/messageType, sole Application register-wrapper caller, and `SortedList::InsertSorted` helper use; rejected int-return contract because caller docs do not prove returned insert-index use, and first-draft C++ is ready with descriptive listener/scope names.
    - [UID:0000ZY][0x0047ed80-0x0047ee18.ChangeManUnregisterFiltered](by-memory/0x0047ed80-0x0047ee18.ChangeManUnregisterFiltered.md) 0x0047ed80-0x0047ee18 | method | ChangeManUnregisterFiltered : reconstructable : 86% : strong : B010 source-quality recheck confirms filtered unregister by owner/listener/messageType/scope, `SortedList::FindFirstEqual` lower-bound behavior, same-owner scan, listener-null wildcard, exact scope semantics (`1` all messages, `0` message-type match, other nonzero values skip), `SortedList` get/remove slot use, post-remove index/count compensation, sole Application unregister-wrapper caller, and first-draft C++ readiness with enum-style scope.
    - [UID:000101][0x0047ef20-0x0047ef3f.CompareChangeEntries](by-memory/0x0047ef20-0x0047ef3f.CompareChangeEntries.md) 0x0047ef20-0x0047ef3f | comparator helper | CompareChangeEntries : reconstructable : 86% : strong : B010 source-quality recheck confirms this file-local `ChangeMan.cpp` comparator compares only `ChangeManEntry::owner`, returns `-1/0/1`, is passed by the constructor to `SortedList`, and exists to group equal-owner registrations for first-equal scans; rejected class-method/public-helper ownership, owner/emitter remain file UID `0000I2`, and first-draft static comparator C++ is ready.
    - [UID:000103][0x0047ef50-0x0047efae.ChangeManScalarDeletingDestructor](by-memory/0x0047ef50-0x0047efae.ChangeManScalarDeletingDestructor.md) 0x0047ef50-0x0047efae | scalar deleting destructor | ChangeManScalarDeletingDestructor : reconstructable : 86% : strong : B010 source-quality recheck confirms source-declared/generated-binary destructor support: vtable-slot-only entry at `0x00614cd0`, no direct ordinary code callers, `m_changeList` virtual destruction with delete flag `1`, field clear, `g_pChangeMan` clear, `LObject` base cleanup, and MSVC delete-flag storage-free wrapper; keep owner/emitter `00001K` but leave formal C++ blank because final source should define normal `~ChangeMan()` and let the compiler regenerate scalar deleting destructor glue.
```

`auto-generated/-ag-memory-coverage.md` should update automatically after the by-* files are edited and validated; do not hand-edit it.

## Final Recommendation

- Exact changes applied by B010: created this research report only.
- Exact parent assignments recommended: keep existing `CANONICAL_OWNER` and `EMITTER_UIDS` for all five targets.
- Exact items left no-owner/non-emitting: none in this cluster.
- Exact future work outside this assignment scope:
  - Update `by-class/ChangeMan.md` with the recommended API family and first-draft class support declarations.
  - Update `by-type/by-struct/ChangeManEntry.md` to close the bool/scope wording with enum-style names.
  - Consider a class-source scaffold on `ChangeMan` so method children have a stable final insertion context.
  - Validate edited by-* pages and let validator refresh autogen reports.

## Follow-Up Actions

- Supervisor actions:
  - Apply the doc/score recommendations or assign an A/C agent to apply them under leases.
  - Apply the exact coverage replacement rows above when updating `by-memory/-coverage-report.md`.
- A-agent actions:
  - Lease and update the target pages if accepted.
  - Run validator file scans for changed pages.
- B010 future research actions:
  - If IDA MCP becomes available, run a narrow caller-use audit for `ApplicationRegisterChangeListener` and `ApplicationUnregisterChangeListener` call sites to further confirm the source-facing `void` return decision.

## Confidence

- Recommendation confidence: strong for ownership/routing and no split; strong for comparator/list/layout semantics; medium-high for source spelling.
- Score confidence: `86/90` or `86/91` recommendations are justified; do not raise any target to `95+`.
- Residual uncertainty, non-blocking: live MCP was unavailable, exact original listener interface spelling is not recovered, and exact `SortedList` public header names are descriptive.

## Validator Results

- Commands run: none. This report is under `tools/leaser/Agents/Agent-B010/research`, outside validator by-* scope.
- Results: not applicable.
- Any unresolved validator warnings/errors: not checked by B010 because no by-* file was changed.

## Changed Files

- Created: `tools/leaser/Agents/Agent-B010/research/0000ZT-0000ZW-0000ZY-000101-000103-ChangeMan-source-quality.md`
- Modified: none outside B010 research.
- Renamed: none.
- Moved to executed: none.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B010","command_id":"000000004165","destination_path":"executed-b-agent-research/B010/0000ZT-0000ZW-0000ZY-000101-000103-ChangeMan-source-quality.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:34","uid":"0000ZT"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
