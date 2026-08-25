** TARGET-REPORT-UID:000004 **
** AUTHOR-AGENT-ID:B015 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# 000004 _DATFileMgr Class Source-Quality Report

## Final Recommendation

- Target: [UID:000004] `by-class/_DATFileMgr.md`.
- Current target score/state: `87/85`, `CANONICAL_OWNER:0000IO`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000IO`, blank formal C++.
- Recommended target metadata: raise to `COMPLETION:89`, `CONFIDENCE:88`; keep owner/emitter [UID:0000IO] `DATFileMgr`.
- Source route: `NexusTK/archive/DATFileMgr.cpp`, as an internal/private implementation class behind the public `DATFileMgr` wrapper.
- C++ policy: first-draft class declaration is now justified for `_DATFileMgr`; do not emit method bodies from this class page. Keep the raw ordinary destructor child [UID:00012F] blank until the destructor body, scalar deleting destructor, and vtable route are coordinated by implementation.
- Coverage policy: no `by-memory/-coverage-report.md` row change is required for this class-only pass. Include a class coverage row replacement if the supervisor applies the score/source-shape update.

## Target Paths

- Target path: `source-3/project-documentation/by-class/_DATFileMgr.md`
- Required report path: `source-3/project-documentation/tools/leaser/Agents/Agent-B015/research/000004-_DATFileMgr-class-source-quality.md`
- Primary source parent: `source-3/project-documentation/by-file/DATFileMgr.md`
- Key support pages checked:
  - `by-class/DATFileMgr.md`
  - `by-class/DATFileResolver.md`
  - `by-memory/0x0049bd30-0x0049d6ed.DATManagers.md`
  - `by-memory/0x0049c750-0x0049c7f6._DATFileMgrRawDestructor.md`
  - `by-memory/0x0049d190-0x0049d26c.DATFileResolverDestroy.md`
  - `by-type/by-vtable/DATManagerVtables.md`
  - `by-memory/0x006189c8-0x006189d0._DATFileMgrVtableData.md`
  - `by-memory/0x0067ab40-0x0067ab44.g_pDATFileMgr.md`

## Evidence Checked

- Current target page and DAT manager support pages.
- Executed prior reports used as leads, then validated against current pages:
  - `Agent-B002/research/executed/00012F-datfilemgr-raw-destructor-source-quality.md`
  - `Agent-B005/research/executed/00012H-DATFileResolverDestroy-source-quality.md`
- Local raw export JSON:
  - `exports/0049bd30.json`
  - `exports/0049c750.json`
  - `exports/0049c800.json`
  - `exports/0049cad0.json`
  - `exports/0049cbb0.json`
  - `exports/0049ce50.json`
  - `exports/0049d190.json`
  - `exports/0049d220.json`
  - `exports/0049d3d0.json`
  - `exports/0049d490.json`
  - `exports/0049d5e0.json`
- Generated `simroot_v2` leads, not used as authority:
  - `class__DATFileMgr.cpp`
  - `class_DATFileMgr.cpp`
  - `class_DATFileResolver.cpp`
- Coverage rows:
  - `by-class/-coverage-report.md`
  - `auto-generated/-ag-class-coverage.md`
  - `auto-generated/-ag-memory-coverage.md`

I could not re-run a PE route scan from the workspace because no `NexusTK.exe` or memory image is present under the current repo roots. The report therefore uses the already-incorporated B002/B005 raw PE findings in current docs plus local export JSON and support pages.

## Heuristic / Inference Reanalysis And Validation

### Class Identity And Source Placement

Best inference: keep `_DATFileMgr` as the source-facing private implementation class name and route it through `DATFileMgr.cpp`.

Evidence:

- `DATFileMgr::DATFileMgr` at `0x0049bd30` allocates `0x30` bytes, installs `_DATFileMgr` vtable `0x006189cc`, initializes the resolver/hash/list state, clears the archive-container vector fields, and stores the inner object pointer at public wrapper offset `+0x04`.
- `g_pDATFileMgr` points to the public `DATFileMgr` wrapper, not directly to `_DATFileMgr`; public helper paths read wrapper `+0x04` to reach the private implementation.
- `_DATFileMgr` vtable data [UID:0002MB] records RTTI/pre-vtable `0x006189c8` and one slot `0x006189cc -> 0x0049d3d0`, with constructor/destructor vptr stores at `0x0049bda1`, `0x0049c755`, and `0x0049d3dd`.
- The adjacent `0x006189d0` dword is UTF-16 `"../"` data used by `_DATFileMgr::LoadDATFileIndex`, not another virtual slot.

Rejected alternatives:

- Rename to `DATFileMgrImpl` now: plausible source style, but unsupported by binary labels and increases churn. The current RTTI/vtable labels use `_DATFileMgr`; keep this spelling until stronger source evidence appears.
- Split to `class__DATFileMgr.cpp`: rejected as a Wave3 staging artifact. The file page already places public wrapper, private implementation, container, resolver, singleton, and helper bodies in `NexusTK/archive/DATFileMgr.cpp`.
- Route to `DATArchive`: rejected because `DATArchive` is a subsystem grouping, not the direct source owner for the implementation class.

### Embedded DATFileResolver Field Layout

Best inference: `_DATFileMgr +0x04..+0x23` is a concrete embedded resolver/hash-table member, currently best named `m_resolver` of internal type `DATFileResolver`.

Resolved layout:

| `_DATFileMgr` offset | Resolver offset | Source-facing field |
| --- | --- | --- |
| `+0x04` | `+0x00` | `DATFileResolver::m_maxLoadFactor` |
| `+0x08` | `+0x04` | `DATFileResolver::m_entryListSentinel` |
| `+0x0c` | `+0x08` | `DATFileResolver::m_entryCount` |
| `+0x10` | `+0x0c` | `DATFileResolver::m_bucketsBegin` |
| `+0x14` | `+0x10` | `DATFileResolver::m_bucketsEnd` |
| `+0x18` | `+0x14` | `DATFileResolver::m_bucketsCapacity` |
| `+0x1c` | `+0x18` | `DATFileResolver::m_bucketMask` |
| `+0x20` | `+0x1c` | `DATFileResolver::m_bucketCount` |

Evidence:

- Constructor context writes `1.0f` to resolver `+0x00`, allocates a `0x14`-byte sentinel with `0x0049d490`, calls the bucket resize/fill helper with size `8`, and clears archive-container vector fields after the resolver subobject.
- `0x0049ce50` and `0x0049d5e0` use `this +0x18` as the bucket mask and `this +0x1c` as bucket count/load-factor denominator.
- `0x0049d190-0x0049d26c` is accepted as `DATFileResolver::~DATFileResolver()` / cleanup, called from both `_DATFileMgr` teardown paths on `this + 4`.

Rejected alternatives:

- Leave offsets `+0x08..+0x23` as unknown byte fields: rejected by constructor, resolver cleanup, insert/find, and node-search evidence.
- Treat `DATFileResolver` as a standalone original `DATFileResolver.cpp`: rejected. Every proven use is embedded in `_DATFileMgr`; no separate vtable, standalone constructor route, public API, or non-manager owner exists.
- Fold the resolver into `DATIndexVector`: rejected. `DATIndexVector` is shared outside the DAT manager; the resolver hashes and stores uppercase wide DAT entry names.

### Archive-Container Vector Fields

Best inference: `_DATFileMgr +0x24/+0x28/+0x2c` are the begin/end/capacity triplet for loaded DAT archive containers.

Recommended field names:

- `m_archiveContainersBegin`
- `m_archiveContainersEnd`
- `m_archiveContainersCapacity`

Evidence:

- `LoadDATFileIndex` constructs a `DATFileContainer`, appends it through offsets `+0x24/+0x28/+0x2c`, and grows the vector when `end == capacity`.
- The raw ordinary destructor iterates from `+0x24` to `+0x28`, deletes each non-null `DATFileContainer *` through vslot 0 with flag `1`, then frees vector allocation using `+0x2c` for the large-allocation guard and clears all three fields.
- The modeled scalar deleting destructor at `0x0049d3d0` has the same archive-vector teardown followed by optional object free.

Rejected alternatives:

- `m_loadedFiles*`: too generic. These entries are mapped DAT archive containers, not arbitrary files.
- A custom container object at `+0x24`: current evidence is a raw pointer-vector triplet; no separate class/vtable/member API is shown.

### Method Names And Signatures

Best source-facing inventory:

| Address / range | Current raw/generated name | Recommended source role |
| --- | --- | --- |
| `0x0049bd30` init window | public `DATFileMgr::DATFileMgr` | Public wrapper constructor; allocates/initializes `_DATFileMgr` inline. |
| `0x0049c750-0x0049c7f6` | raw `~cls_0x49c750` | `_DATFileMgr::~_DATFileMgr()` ordinary/non-deleting destructor semantics; no direct route, no formal C++ yet on child. |
| `0x0049c800-0x0049cac4` | `FUN_0049c800` | `_DATFileMgr::LoadDATFileIndex(const wchar_t *archivePath)` returning boolean success. |
| `0x0049cad0-0x0049cba5` | `FUN_0049cad0` | `_DATFileMgr::FindEntryByName(const wchar_t *entryName, DATEntryLocation *outLocation)` returning boolean found. |
| `0x0049cbb0-0x0049cc39` | `FUN_0049cbb0` | file-local/static `CreateDATEntryNode(DATEntryNode *listRoot, DATEntryNode *insertBefore, const DATEntrySeed *seed)`; not an instance method because the export calling convention is `__stdcall` and it has no `this`. |
| `0x0049ce50-0x0049d0c2` | `meth_0x49ce50` | `DATFileResolver::InsertOrFindEntry(...)`; called on `_DATFileMgr + 4`, so resolver ownership is stronger than `_DATFileMgr` instance ownership. |
| `0x0049d190-0x0049d26c` | `meth_0x49d190` / `Destroy` | `DATFileResolver::~DATFileResolver()` / cleanup. |
| `0x0049d3d0-0x0049d488` | `~_DATFileMgr` in generated export | compiler-generated scalar deleting destructor wrapper / vtable slot route for `_DATFileMgr`; do not hand-name as the ordinary source destructor body. |
| `0x0049d490-0x0049d4bd` | `FUN_0049d490` | file-local/static `AllocateDATEntryNode(DATEntryNode *previousNode, DATEntryNode *nextNode)`; not an instance method because no `this` is used. |
| `0x0049d5e0-0x0049d6ed` | `meth_0x49d5e0` | `DATFileResolver::FindNodeByKey(const wchar_t *entryName)`; called on `_DATFileMgr + 4`. |

The current target page's method table mostly uses acceptable documentation names, but the report recommends tightening the source-facing ownership of `InsertOrFindEntry`, `FindNodeByKey`, `CreateEntryNode`, and `AllocateNode` so generated/helper names do not leak into final source policy.

### Raw Ordinary Destructor And Deleting Destructor Policy

Best inference: source should express one virtual destructor on `_DATFileMgr`; the binary's scalar deleting destructor and vtable slot are compiler-generated consequences.

Evidence:

- B002 proves `0x0049c750-0x0049c7f6` is coherent ordinary destructor code, has no IDA function object at the start, has no direct VA/RVA/rel32 route to the start, restores vtable `0x006189cc`, tears down archive-container vector fields, and calls resolver cleanup at `0x0049c7e8`.
- The vtable slot at `0x006189cc` points to `0x0049d3d0`, not to the ordinary destructor body.
- The scalar deleting destructor at `0x0049d3d0` repeats cleanup and conditionally frees `this` based on the delete flag.

Recommendation:

- `_DATFileMgr` class page should declare `virtual ~_DATFileMgr();`.
- Do not hand-port vtable bytes or scalar deleting destructor code.
- Do not populate [UID:00012F] with duplicate destructor C++ until a supervisor implementation pass decides where the single ordinary destructor body will live.

### Leading-Underscore / Class-Name Uncertainty

Best inference: `_DATFileMgr` remains the right working source-facing name.

Evidence for:

- IDA/vtable pages use `_DATFileMgr` labels for RTTI/vtable data.
- Public wrapper is already named `DATFileMgr`, so the leading underscore accurately conveys private implementation status.
- Existing file/class/memory docs consistently use `_DATFileMgr`; changing now would disconnect support evidence.

Remaining uncertainty:

- The exact original source spelling could have been `_DATFileMgr`, `DATFileMgrImpl`, or another private helper. No source/header evidence proves a replacement. This uncertainty caps confidence but is not a blocker for a first-draft class declaration.

## First-Draft C++ Recommendation

Populate the `_DATFileMgr` class page formal C++ with a declaration-level sketch only. Do not include method bodies here.

Recommended first-draft block:

```cpp
class DATFileContainer;
class DATFileResolver;
struct DATEntryLocation;

class _DATFileMgr {
public:
    _DATFileMgr();
    virtual ~_DATFileMgr();

    bool LoadDATFileIndex(const wchar_t *archivePath);
    bool FindEntryByName(const wchar_t *entryName, DATEntryLocation *outLocation);

private:
    DATFileResolver m_resolver;
    DATFileContainer **m_archiveContainersBegin;
    DATFileContainer **m_archiveContainersEnd;
    DATFileContainer **m_archiveContainersCapacity;
};
```

Implementation caveat: because `DATFileResolver` is stored by value, the generated file must have a `DATFileResolver` declaration before this class declaration. The preferred low-churn route is to add or ensure a minimal resolver declaration in the same `DATFileMgr.cpp` source cluster, not to replace `m_resolver` with raw bytes.

No method-body C++ should be added to this target page. `LoadDATFileIndex`, `FindEntryByName`, resolver insert/find/destroy, and destructor bodies should remain on exact child method pages after their source-quality reviews.

## Score Recommendation

Recommended target metadata:

```text
*** COMPLETION:89 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000IO | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000IO | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
```

Rationale:

- Completion rises because prior raw destructor and resolver reports are now incorporated, field layout is resolved through `_DATFileMgr +0x2c`, method ownership can be corrected, and class-declaration C++ is ready.
- Confidence rises because vtable/type ownership, source file routing, wrapper relation, resolver layout, and archive vector semantics are strongly supported. It remains below final because exact original private class spelling, final wide-string typedef names, and some helper prototypes remain inferred.

## Exact Target Changes To Apply Later

For `by-class/_DATFileMgr.md`:

1. Update metadata to `89/88`; keep owner/emitter route unchanged.
2. Replace the status text that says field names/original private spelling block formal C++. New policy: first-draft class declaration is ready, while method bodies and scalar deleting destructor code remain child-page/compiler-generated policy.
3. Add the first-draft class declaration block above.
4. Update layout notes:
   - `+0x04-+0x23`: embedded `DATFileResolver m_resolver` with fields `m_maxLoadFactor`, `m_entryListSentinel`, `m_entryCount`, `m_bucketsBegin`, `m_bucketsEnd`, `m_bucketsCapacity`, `m_bucketMask`, `m_bucketCount`.
   - `+0x24/+0x28/+0x2c`: `m_archiveContainersBegin`, `m_archiveContainersEnd`, `m_archiveContainersCapacity`.
5. Update method table/source-shape notes:
   - `0x0049c800`: `_DATFileMgr::LoadDATFileIndex(const wchar_t *archivePath)`.
   - `0x0049cad0`: `_DATFileMgr::FindEntryByName(const wchar_t *entryName, DATEntryLocation *outLocation)`.
   - `0x0049ce50`: `DATFileResolver::InsertOrFindEntry`, not a raw `_DATFileMgr` instance method.
   - `0x0049d5e0`: `DATFileResolver::FindNodeByKey`, not a raw `_DATFileMgr` instance method.
   - `0x0049cbb0` and `0x0049d490`: file-local/static node helpers, not instance methods.
   - `0x0049d3d0`: scalar deleting destructor/vtable route, not source-authored ordinary destructor body.
6. Add rejected alternatives:
   - no standalone `_DATFileMgr.cpp`
   - no standalone `DATFileResolver.cpp`
   - no `DATIndexVector` ownership
   - no hand-authored vtable/static table
   - no renaming away from `_DATFileMgr` without stronger original-source evidence
7. Add a new change-log entry summarizing this B015 report and the `87/85 -> 89/88` recommendation.

## Support-Doc Changes To Apply Later

### `by-file/DATFileMgr.md`

Add or replace source-shape text:

```text
- B015 `_DATFileMgr` class reanalysis keeps the public/private manager pair in `NexusTK/archive/DATFileMgr.cpp` and treats `_DATFileMgr` as a private implementation class, not a separate recovered source file. The class declaration is first-draft ready with `DATFileResolver m_resolver` at offset `+0x04` and archive-container vector fields at `+0x24/+0x28/+0x2c`.
- Source-facing helper ownership should be tightened: `0x0049ce50` and `0x0049d5e0` are `DATFileResolver` member helpers reached on `_DATFileMgr + 4`; `0x0049cbb0` and `0x0049d490` are file-local/static node helpers; the scalar deleting destructor at `0x0049d3d0` is compiler-generated vtable-route code.
```

### `by-class/DATFileMgr.md`

Replace stale data issue text that says `_DATFileMgr` has many unknown bytes:

```text
- `_DATFileMgr` field layout is now mostly resolved for source routing: public wrapper `DATFileMgr` stores the inner manager pointer at `+0x04`; the inner manager has `DATFileResolver m_resolver` at `+0x04` and `m_archiveContainersBegin/End/Capacity` at `+0x24/+0x28/+0x2c`. Exact original private class spelling and final string typedef names remain review items, not blockers for class declaration.
```

No score change is required for this support page, but `86/86 -> 87/87` would be defensible if the stale field issue is removed.

### `by-class/DATFileResolver.md`

Add a method-ownership note:

```text
- B015 `_DATFileMgr` class reanalysis confirms that resolver behavior is broader than the cleanup child: `0x0049ce50` is best named `DATFileResolver::InsertOrFindEntry`, `0x0049d5e0` is best named `DATFileResolver::FindNodeByKey`, and `0x0049d190-0x0049d26c` remains `DATFileResolver::~DATFileResolver()` / cleanup. The type is an internal member/helper in `DATFileMgr.cpp`, not a standalone source file.
```

Optional score if this support text is added: `86/89 -> 87/90`. It is not required for the target implementation.

### `by-memory/0x0049bd30-0x0049d6ed.DATManagers.md`

Replace method-map labels for resolver/static helpers:

```text
| `0x0049cbb0` | `0x0049cbb0-0x0049cc39` | file-local/static `CreateDATEntryNode` helper | 1 |
| `0x0049ce50` | `0x0049ce50-0x0049d0c2` | `DATFileResolver::InsertOrFindEntry` on `_DATFileMgr + 4` | 2 |
| `0x0049d490` | `0x0049d490-0x0049d4bd` | file-local/static `AllocateDATEntryNode` helper | 2 |
| `0x0049d5e0` | `0x0049d5e0-0x0049d6ed` | `DATFileResolver::FindNodeByKey` on `_DATFileMgr + 4` | 1 |
```

Replace the open field-name question with:

```text
- `_DATFileMgr` class-level fields are now resolved enough for source declaration: embedded `DATFileResolver m_resolver` plus archive-container vector begin/end/capacity. Remaining questions are final original spellings, final wide-string typedef, and DAT entry sentinel semantics.
```

### Vtable Pages

No required changes. `DATManagerVtables.md` and `_DATFileMgrVtableData.md` already state that the one-slot vtable is emitted from the class declaration and virtual destructor and should not be hand-ported.

## Exact Coverage Text

No `by-memory/-coverage-report.md` replacement row is required for this class-only task. Leave the existing [UID:00012F], [UID:00012H], and [UID:0002MB] memory rows unchanged.

If the supervisor applies the target class update, replace the [UID:000004] row in `by-class/-coverage-report.md` with:

```text
- [UID:000004][_DATFileMgr](by-class/_DATFileMgr.md) : reconstructable : 89% : strong : B015 source-quality reanalysis confirms the internal DAT manager implementation class in [UID:0000IO][DATFileMgr](by-file/DATFileMgr.md), first-draft class declaration readiness, embedded `DATFileResolver m_resolver` layout through `_DATFileMgr +0x20`, archive-container vector fields `+0x24/+0x28/+0x2c`, raw ordinary destructor semantics/no-route policy, scalar deleting destructor/vtable compiler-generated policy, public wrapper `DATFileMgr` relation, resolver member helper ownership for insert/find, static node helper roles, and rejected standalone `_DATFileMgr.cpp`/`DATFileResolver.cpp`/`DATIndexVector` ownership alternatives.
```

Expected generated class coverage after autogen if the formal C++ block is populated:

```text
| [UID:000004][_DATFileMgr](by-class/_DATFileMgr.md) | emits | `0000IO` | `0000IO` |  | yes | `auto-generated/NexusTK/archive/DATFileMgr.cpp` | `by-class/_DATFileMgr.md` |  |
```

## Validator Commands For Implementation Callback

Run from `source-3/project-documentation` after applying target/support docs:

> Executable block R001 was removed from this report and preserved verbatim in [000004-_DATFileMgr-class-source-quality-removed.md](000004-_DATFileMgr-class-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

Expected results: all edited files validate; autogen updates `_DATFileMgr` class coverage from `no` to `yes` if the class declaration block is populated.

## IDA Rename / Type / Comment Recommendations

High confidence:

- Keep class/type name `_DATFileMgr`.
- Rename `0x0049c800` to `_DATFileMgr::LoadDATFileIndex`.
- Rename `0x0049cad0` to `_DATFileMgr::FindEntryByName`.
- Rename `0x0049d190` to `DATFileResolver::~DATFileResolver` or `DATFileResolver::Destroy` if destructor spelling is mechanically difficult.
- Rename `0x0049d3d0` to `_DATFileMgr::ScalarDeletingDestructor` / compiler deleting destructor, not ordinary `~_DATFileMgr`.
- Type `_DATFileMgr +0x24/+0x28/+0x2c` as `DATFileContainer **` vector begin/end/capacity.

Medium-high confidence:

- Rename `0x0049ce50` to `DATFileResolver::InsertOrFindEntry`.
- Rename `0x0049d5e0` to `DATFileResolver::FindNodeByKey`.
- Rename `0x0049cbb0` to `CreateDATEntryNode` as a file-local/static helper.
- Rename `0x0049d490` to `AllocateDATEntryNode` as a file-local/static helper.
- Type `_DATFileMgr +0x04` as `DATFileResolver m_resolver`.

Medium confidence:

- Use `DATEntryLocation` for the two-dword `(DATFileContainer *, entryIndex)` out parameter from `FindEntryByName`.
- Use `DATEntrySeed` for the `(name, archiveContainer, entryIndex)` node-creation input.
- Use `DATBucketRecord` with `stopNode` and `linkAnchor` names; these names describe the observed behavior, but original names remain unproven.

## Open Questions After Reanalysis

- Exact original source spelling of `_DATFileMgr`: keep current spelling; no safe replacement exists.
- Exact wide-string typedef/API: use existing `StringBase`/`SimpleUString` family docs; do not invent raw `wchar_t *` ownership for node keys.
- Exact original names for `DATEntryLocation`, `DATEntrySeed`, `DATBucketRecord`: current names are descriptive first-draft names.
- DAT entry final-row sentinel/final-boundary semantics: relevant to `DATFileContainer`, not a blocker for `_DATFileMgr` class declaration.

## Changed Files In This Pass

- Created: `tools/leaser/Agents/Agent-B015/research/000004-_DATFileMgr-class-source-quality.md`
- Modified by-* docs: none.
- Modified coverage reports: none.
- Modified generated files: none.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B015","command_id":"000000004165","destination_path":"executed-b-agent-research/B015/000004-_DATFileMgr-class-source-quality.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:37","uid":"000004"} -->
<!-- {"agent":"B015","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 000004-_DATFileMgr-class-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B015/000004-_DATFileMgr-class-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"000004"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
