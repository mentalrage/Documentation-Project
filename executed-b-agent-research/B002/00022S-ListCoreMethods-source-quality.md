** TARGET-REPORT-UID:00022S **
** AUTHOR-AGENT-ID:B002 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **

# 00022S ListCoreMethods Source-Quality / Split Research

Agent: B002  
Date: 2026-06-25  
Assignment id: B002-report-00022S-list-core-methods-20260625  
Mode: report-only research  
Target: `by-memory/0x004f3140-0x004f35fd.ListCoreMethods.md`

No target/support by-* docs, generated reports, project-level generated files, validator state/cache, IDA DB, or coverage-report files were edited.

## Finalized Report / Current Recommendation

- Current recommendation: keep [UID:00022S] as a reviewed non-emitting `List` method-cluster index, not as an independent source-emitting item.
- Final disposition: the source-bearing bodies are the exact child pages [UID:0003JT] through [UID:0003K5]. Those children should route to [UID:000079] `List`, then [UID:0000KS] `List.cpp` under `NexusTK/util/`. The aggregate remains `RECONSTRUCTABLE:FALSE`, `CANONICAL_OWNER:NONE`, blank emitter, blank C++.
- Required action: repair validator registration for the existing child pages with validator file scans, update the target and child pages with this current MCP evidence and source-quality names, populate the child `Item Summary` fields, and refresh generated reports through validator/autogen. Do not edit validator.ini or generated reports by hand.
- Confidence: high for aggregate non-emitting disposition, split boundaries, padding, direct List ownership of the children, and `util/List.cpp` source route; medium-high for final public/private method spellings and child formal C++ readiness.

## Target

- Target UID: `00022S`
- Target path: `by-memory/0x004f3140-0x004f35fd.ListCoreMethods.md`
- Source queue/report row: `auto-generated/-ag-research-tracker.md`, by-memory Not-Covered Files - Reconstructable, assignment-time row `72/88`, combined `80.0`, reconstructable `true`, reports `0`.
- Current source-page metadata read during this pass: `COMPLETION:90`, `CONFIDENCE:91`, `CANONICAL_OWNER:NONE`, `RECONSTRUCTABLE:FALSE`, blank `EMITTER_UIDS`, blank `RECONSTRUCTION_CPP`.
- Current generated-report mismatch: `-ag-research-tracker.md`, `-ag-coverage-report-by-memory.md`, and `project-level/-auto-completion-stats.md` still show stale `72/88` / reconstructable wording. `-ag-memory-coverage.md` does show the current not-reconstructable state, but does not list the child UIDs.

## Current Target State

The target page already documents the correct high-level split: ten modeled functions, three raw function-shaped helpers, internal `0xcc` padding, and a non-emitting aggregate disposition. It links every child page and states the children attach directly to [UID:000079] `List`.

Current blockers found during this pass:

- The existing child files [UID:0003JT] through [UID:0003K5] are not registered in `validator.ini`. A dry-run validator scan of the aggregate reported `missing_ref_uid` for every child reference; a dry-run scan of [UID:0003JT] reported it would add a new UID path mapping.
- Generated reports therefore omit these exact reconstructable children and keep stale queue rows for the aggregate.
- The child pages have blank `Item Summary` fields, so even after registration their generated coverage rows will be weak until summaries are filled.
- The target page still has stale wording that says the cluster is below a `95+` C++ threshold. The active rule no longer requires 95+ merely to enter C++, but this aggregate still must remain no-code because it is non-reconstructable and source code belongs only on child pages.
- Child formal C++ should not be inserted from this aggregate report. The child methods are source-authored and routed, but final helper API spellings for MemoryMan allocation/copy wrappers and the shared `List` declaration/header shape remain unresolved in the supporting docs.

Related docs checked:

- `by-class/List.md`
- `by-file/List.md`
- `by-memory/0x004f3060-0x004f30d5.ListConstructor.md`
- `by-memory/0x004f30e0-0x004f3139.ListNonDeletingDestructor.md`
- all child pages [UID:0003JT] through [UID:0003K5]
- `by-memory/0x004f3600-0x004f3a43.SortedList.md`
- `by-memory/0x0061ce28-0x0061ce84.ListSortedListVtableData.md`
- `by-file/MemoryMan.md` and allocation/copy helper pages for `sub_516030`, `sub_516050`, `sub_516170`, `sub_516190`, `sub_516220`, and `sub_516240`
- `by-project-structure/proposed-source-tree.md`
- `by-meta/client_containers.md`
- `auto-generated/-ag-research-tracker.md`, `-ag-coverage-report-by-memory.md`, `-ag-memory-coverage.md`, and `auto-generated/NexusTK/util/List.cpp`
- executed B-agent reports `B008/000191-ListConstructor-source-quality.md` and `B005/00032H-ConfigEntryVectorCopyWrappersRaw-source-quality.md`

## Executive Recommendation

Do not merge this range back into a single source-bearing by-memory page and do not create new children. The split is structurally correct: each modeled method/helper has its own exact child page, and every internal gap is alignment. The implementation callback should repair the validator registration/generated-state problem and improve the target/child documentation, not change the aggregate owner/emitter.

Recommended metadata for the aggregate after implementation:

```text
COMPLETION:90
CONFIDENCE:91
CANONICAL_OWNER:NONE
RECONSTRUCTABLE:FALSE
EMITTER_UIDS:
RECONSTRUCTION_CPP: blank
```

Do not raise the aggregate score yet. The binary facts are strong enough for a higher score in isolation, but generated coverage currently omits the children, the child UID references are not in validator state, and child source summaries/C++ readiness remain incomplete. Those are active source-quality blockers for this aggregate's documented split.

## Supervisor Active Recheck

The supervisor/user instruction was a report-only B002 assignment for [UID:00022S], with mandatory IDA MCP evidence and no target/support doc edits until implementation callback. IDA MCP was available and used. No subagents were spawned.

This target did not require split execution before the report: the exact child files already exist. The current issue is split incorporation/registration/source-quality completion, not missing address children.

Every source-bearing child in scope has an exact file and range. The blocker is that those child UIDs are not registered in validator state and are absent from generated reports; the fix is validator file registration plus doc updates, not hand edits to generated reports or validator.ini.

## Inference Research Guidance Check

The recommendation separates:

- IDA facts: current MCP function inventory, decompilation, xrefs, raw helper disassembly, signatures, and padding bytes.
- Documentation facts: current target/class/file/helper pages, proposed source tree, executed reports.
- Inference: source-facing method names, source placement, and no-code/C++ readiness.

Generated Wave/simroot material was treated only as a lead. `source-3/simroot_v2/class_List.cpp` was not present in this workspace during this pass, and current generated `auto-generated/NexusTK/util/List.cpp` is stale/partial. No Wave2/Wave3 claim was used as authority.

## Evidence Standards Used

Evidence types used:

- IDA MCP `server_health`, `tools/list`, `lookup_funcs`, `entity_query`, `xrefs_to`, `callees`, `analyze_function`, `insn_query`, `get_bytes`, and `make_signature_for_range`.
- Dry-run validator file scans with no `--apply`.
- Current by-* target/support docs and generated reports.
- Prior executed B-agent reports as leads, rechecked against current docs and MCP where relevant.

The evidence ladder favors current IDA facts for boundaries/behavior, current by-* docs for ownership/source placement, and executed reports only where they explain accepted naming context. The main tool limitation is that IDA still does not model `0x004f3560`, `0x004f35a0`, and `0x004f35e0` as functions, so their role is based on raw instruction decoding, unique signatures, and placement in the List method island rather than modeled call graph edges.

## Evidence Checked

### IDA MCP Availability

- JSON-RPC initialized against `http://127.0.0.1:13337/mcp`; MCP session id `7ae61d76-0d58-423d-8b84-7a9294d57c33`.
- `idb_list` reported active database session `80de0a67`, `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, worker PID `26892`.
- `server_health` reported `status: ok`, module `NexusTK.exe`, input path `C:\Users\admin\Desktop\Clone\NexusTK\NexusTK.exe`, imagebase `0x400000`, auto-analysis ready, Hex-Rays ready, strings cache ready.

### MCP Function Inventory

`lookup_funcs` on 2026-06-25 confirms:

| Address | IDA result | Meaning |
| --- | --- | --- |
| `0x004f3140` | `sub_4F3140`, size `0x8c` | `List::AssignFrom` / copy-from helper |
| `0x004f31d0` | `sub_4F31D0`, size `0xcf` | count resize |
| `0x004f32a0` | `sub_4F32A0`, size `0x4` | data pointer accessor |
| `0x004f32b0` | `sub_4F32B0`, size `0x2a` | element accessor |
| `0x004f32e0` | `sub_4F32E0`, size `0xd5` | insert-at/range |
| `0x004f33c0` | `sub_4F33C0`, size `0x15` | append wrapper |
| `0x004f33e0` | `sub_4F33E0`, size `0xb3` | remove-at/range |
| `0x004f34a0` | `sub_4F34A0`, size `0xb` | remove-all wrapper |
| `0x004f34b0` | `sub_4F34B0`, size `0x82` | swap elements |
| `0x004f3540` | `sub_4F3540`, size `0x1b` | qsort wrapper |
| `0x004f3560` | not a function | raw helper body |
| `0x004f35a0` | not a function | raw helper body |
| `0x004f35e0` | not a function | raw helper body |
| `0x004f3600` | `sub_4F3600`, size `0x81` | successor `SortedList` constructor |

All documented internal end/padding addresses also returned `Not a function`.

### MCP Decompiler And Callee Facts

- `0x004f3140`: copies source `+0x04/+0x08/+0x0c/+0x10`, frees current data through `sub_516170` when non-null, allocates through `sub_516050`, copies bytes through `sub_516220`.
- `0x004f31d0`: computes old/new page counts from `m_pageSize` and `m_count`; grows via `sub_516050`/`sub_516190`, shrinks via `sub_516190`, stores requested count.
- `0x004f32a0`: returns `this[4]` / `m_data`.
- `0x004f32b0`: returns null for absent data, negative index, or nonzero index beyond `m_count`; otherwise returns `m_data + index * m_elementSize`.
- `0x004f32e0`: computes page growth, reallocates if needed, shifts tail with `sub_516240`, increments count, copies inserted bytes with `sub_516220`.
- `0x004f33c0`: virtual-dispatches insert slot `+0x14` with current count as insertion index.
- `0x004f33e0`: shifts tail left with `sub_516240`, shrinks allocation if page count falls, subtracts removed count.
- `0x004f34a0`: virtual-dispatches remove slot `+0x1c` with `index=0`, `count=m_count`.
- `0x004f34b0`: allocates scratch buffer of `m_elementSize`, calls virtual slot `+0x10` to fetch both elements, performs three `sub_516220` copies, and frees scratch with `sub_516170`. Raw disassembly proves both stack arguments are indices; IDA's `Size` parameter name is misleading.
- `0x004f3540`: calls CRT `_qsort(m_data, m_count, m_elementSize, compare)`.

### MCP Xref Facts

Key `xrefs_to` results:

| Target | Count | Meaning |
| --- | ---: | --- |
| `0x004f3140` | 2 | Config copy wrappers at `0x0048ea7c` and `0x0048ea9a`; supports `AssignFrom` naming. |
| `0x004f31d0` | 4 | TextEdit/TextBox count-resize call sites at `0x0058e7e2`, `0x0058e82e`, `0x00590087`, `0x005900d3`. |
| `0x004f32a0` | 4 | vtable/data refs at `0x00613124`, `0x0061b350`, `0x0061ce38`, `0x0061ce64`. |
| `0x004f32b0` | 31 | HierList, object/resource, TextEdit/TextBox, and vtable/data refs. |
| `0x004f32e0` | 4 | HierList insert caller plus vtable/data refs. |
| `0x004f33c0` | 4 | HierList append jump/caller plus vtable/data refs. |
| `0x004f33e0` | 3 | HierList remove caller plus vtable/data refs. |
| `0x004f34a0` | 3 | vtable/data refs only in current result. |
| `0x004f34b0` | 4 | HierList swap caller plus vtable/data refs. |
| `0x004f3540` | 11 | item/list sorting call sites in the `0x00549c20`, `0x0054ab90`, `0x0059bc90`, `0x0059d1f0`, `0x0059d250`, and `0x0059d2b0` bands. |
| `0x004f3560` | 0 | no xrefs to raw helper start. |
| `0x004f35a0` | 0 | no xrefs to raw helper start. |
| `0x004f35e0` | 0 | no xrefs to raw helper start. |
| `0x0061ce2c` | 5 | List vtable refs from constructor/destructor and SortedList transitions at `0x004f3095`, `0x004f3108`, `0x004f3635`, `0x004f383f`, `0x004f38df`. |

### Raw Helper Evidence

`insn_query` decoded:

- `0x004f3560-0x004f3597`: exact-element-capacity helper. It multiplies `m_elementSize * requestedElementCount`, tests `m_data`, calls `sub_516050` when null or `sub_516190` when non-null, stores the result in `m_data`, and returns with `retn 4`. It does not update `m_count`.
- `0x004f35a0-0x004f35db`: page-count-capacity helper. It reads the stack argument as page count, substitutes `m_pageSize` when zero, multiplies by `m_elementSize`, calls `sub_516190(oldData, bytes)`, stores the result in `m_data`, and returns with `retn 4`.
- `0x004f35e0-0x004f35fd`: page-count calculation helper. It returns `1` for non-positive element counts, otherwise computes `(elementCount - 1) / m_pageSize + 1`.

`make_signature_for_range` returned `unique:true` for all three raw helper bodies.

### Padding / Boundary Evidence

`get_bytes` confirmed every internal documented gap is all `0xcc`:

`0x004f31cc-0x004f31d0`, `0x004f329f-0x004f32a0`, `0x004f32a4-0x004f32b0`, `0x004f32da-0x004f32e0`, `0x004f33b5-0x004f33c0`, `0x004f33d5-0x004f33e0`, `0x004f3493-0x004f34a0`, `0x004f34ab-0x004f34b0`, `0x004f3532-0x004f3540`, `0x004f355b-0x004f3560`, `0x004f3597-0x004f35a0`, `0x004f35db-0x004f35e0`, and `0x004f35fd-0x004f3600`.

### Validator Dry-Run Evidence

No apply was used.

- `python .\tools\validator.py --mode file --file by-memory/0x004f3140-0x004f35fd.ListCoreMethods.md --queue-timeout 240`
  - `command_id: 000000001453`
  - `command_timestamp: 2026-06-25T13:37:30-04:00`
  - exit code `0`, `ok: 1`, `apply: False`
  - reported `completion_update 00022S ... 90`, `confidence_update ... 91`, `canonical_owner_update ... NONE`, and `autogen_registry_update ... true -> false` as dry-run state corrections.
  - reported `missing_ref_uid` for every child UID `0003JT` through `0003K5`.
- `python .\tools\validator.py --mode file --file by-memory/0x004f3140-0x004f31cc.ListAssignFrom.md --queue-timeout 240`
  - `command_id: 000000001454`
  - `command_timestamp: 2026-06-25T13:37:31-04:00`
  - exit code `0`, `ok: 1`, `apply: False`
  - reported `path_update 0003JT ... new UID mapping`, proving the child page exists but is absent from validator state.

## Inference Claim Ledger

| Claim | Confidence | Evidence | Counter-evidence checked | Next verification / remaining uncertainty |
| --- | --- | --- | --- | --- |
| `00022S` should remain a non-emitting aggregate/index. | High | Current target metadata, exact child pages, MCP inventory, padding bytes, child/source owner docs. | Direct source-bearing aggregate route rejected because children own every body; generated stale row rejected because source metadata and MCP support non-emitting state. | Register children and refresh generated reports. |
| Child pages [UID:0003JT]-[UID:0003K5] are real source-bearing List methods/helpers. | High | Existing files, MCP boundaries/decompilation/raw disassembly, List class/file docs. | Raw helper no-xref status checked; no evidence they belong to another class/file. | Validator registration and child summaries are needed before generated reports reflect them. |
| Source route is [UID:000079] `List` -> [UID:0000KS] `NexusTK/util/List.cpp`. | High | `by-class/List.md`, `by-file/List.md`, proposed source tree, broad generic callers, vtable refs. | UI, render, Config, HierList, SortedList, ObjectList, and MemoryMan routes checked and rejected as consumers/dependencies/siblings. | Exact original file split with `SortedList.cpp` remains open but does not affect `List` child routing. |
| `List::AssignFrom` is the best source-facing name for `0x004f3140`. | High | B005 executed report, current `xrefs_to` two Config copy wrappers, body replaces destination list with source dimensions/data. | `CopyFrom` remains an acceptable alternate, but `AssignFrom` better reflects destination-side mutation and current support docs. | Broader List API naming pass may choose alternate spelling. |
| Broad aggregate formal C++ must remain blank. | Certain | `RECONSTRUCTABLE:FALSE`, child pages own bodies, by-structure C++ block is limited to represented range. | Stale `95+` gate wording checked and rejected; active code gate is not the reason. | Child-specific formal C++ can be decided only on child pages after registry/source API repair. |

## Positive Evidence Summary

- The IDA-modeled method boundaries exactly match the target's child inventory.
- The three raw helper bodies decode as coherent `List` private helpers, have unique signatures, and sit between modeled `List::Sort` and `SortedList::SortedList`.
- Every gap in the target range is `0xcc` alignment.
- Vtable/data refs place the virtual slots under the `List` vtable and derived List-like vtables.
- Existing `List` class/file docs already define the generic fixed-width layout and `NexusTK/util/List.cpp` source route.
- B005 accepted caller research supports `List::AssignFrom` for `0x004f3140`.

## Negative Evidence Summary

- No direct xrefs exist to raw helper starts `0x004f3560`, `0x004f35a0`, or `0x004f35e0`; their source status is based on raw body evidence and placement, not modeled callers.
- No evidence supports a separate aggregate source item for `0x004f3140-0x004f35fd`.
- No evidence supports assigning the aggregate to `SortedList`; `SortedList` starts at `0x004f3600` after `0xcc` alignment and has its own vtable/class docs.
- No evidence supports assigning List methods to MemoryMan. MemoryMan owns allocation/copy helpers, while List only calls them.
- Generated reports currently omit child UIDs and show stale aggregate score/reconstructable state; these generated rows are contradicted by source page metadata and validator dry-run diagnostics.

## Function / Child Inventory

| Range / Item | UID / Path | Role | Reconstructable | Direct Parent | Score | Status |
| --- | --- | --- | --- | --- | --- | --- |
| `0x004f3140-0x004f31cc` | [UID:0003JT] `ListAssignFrom` | destination-side copy/assignment from another `List` | TRUE | [UID:000079] `List` | `85/90` | existing child, missing validator registration |
| `0x004f31d0-0x004f329f` | [UID:0003JU] `ListSetCount` | logical count resize and capacity grow/shrink | TRUE | [UID:000079] `List` | `86/90` | existing child, missing validator registration |
| `0x004f32a0-0x004f32a4` | [UID:0003JV] `ListGetData` | virtual backing-data accessor | TRUE | [UID:000079] `List` | `86/92` | existing child, missing validator registration |
| `0x004f32b0-0x004f32da` | [UID:0003JW] `ListGetElementAt` | virtual bounds-checked element accessor | TRUE | [UID:000079] `List` | `87/91` | existing child, missing validator registration |
| `0x004f32e0-0x004f33b5` | [UID:0003JX] `ListInsertRange` | virtual insert-at/range method | TRUE | [UID:000079] `List` | `87/90` | existing child, missing validator registration |
| `0x004f33c0-0x004f33d5` | [UID:0003JY] `ListAppendRange` | append wrapper through insert slot | TRUE | [UID:000079] `List` | `86/91` | existing child, missing validator registration |
| `0x004f33e0-0x004f3493` | [UID:0003JZ] `ListRemoveRange` | virtual remove-at/range method | TRUE | [UID:000079] `List` | `87/90` | existing child, missing validator registration |
| `0x004f34a0-0x004f34ab` | [UID:0003K0] `ListClear` | remove-all wrapper through remove slot | TRUE | [UID:000079] `List` | `86/91` | existing child, missing validator registration |
| `0x004f34b0-0x004f3532` | [UID:0003K1] `ListSwapElements` | virtual element swap through scratch buffer | TRUE | [UID:000079] `List` | `86/90` | existing child, missing validator registration |
| `0x004f3540-0x004f355b` | [UID:0003K2] `ListSort` | non-virtual qsort wrapper | TRUE | [UID:000079] `List` | `86/91` | existing child, missing validator registration |
| `0x004f3560-0x004f3597` | [UID:0003K3] `ListReserveExactElementCountRaw` | raw exact-element-capacity helper | TRUE | [UID:000079] `List` | `85/88` | existing child, missing validator registration |
| `0x004f35a0-0x004f35db` | [UID:0003K4] `ListReservePageCountRaw` | raw page-capacity helper | TRUE | [UID:000079] `List` | `85/88` | existing child, missing validator registration |
| `0x004f35e0-0x004f35fd` | [UID:0003K5] `ListPageCountForElementCountRaw` | raw page-count calculation helper | TRUE | [UID:000079] `List` | `85/89` | existing child, missing validator registration |

## Ranked Ownership Analysis

### 1. Aggregate remains no-owner/non-emitting; children attach to [UID:000079] `List`

Evidence for:

- `00022S` is a grouping range whose exact source-bearing child pages already cover every method/helper body.
- The child methods consistently use the `List` layout: `m_elementSize`, `m_pageSize`, `m_count`, `m_data`.
- List vtable refs and [UID:000079] document these virtual slots as `List` methods.
- [UID:0000KS] routes `List` to `NexusTK/util/List.cpp`.

Evidence against:

- Generated reports currently have stale aggregate rows and omit child rows.
- Child pages are not registered in validator state.

Decision: accepted. Generated/validator skew is a repair item, not evidence against the source ownership.

### 2. Direct aggregate owner [UID:000079] `List`

Evidence for:

- All contained source-bearing bodies are List methods/helpers.

Evidence against:

- By-structure treats the broad aggregate as an index/container after exact child split.
- Setting the aggregate owner/emitter would duplicate child source output and risk parent/child conflation.

Decision: rejected for the aggregate; accepted only for child pages.

### 3. [UID:0000KS] `List.cpp` as direct owner

Evidence for:

- Final file placement is `NexusTK/util/List.cpp`.

Evidence against:

- Semantic direct owner for methods is the `List` class; file is the emitter root through the class.

Decision: keep as file route, not direct aggregate owner.

### 4. [UID:0000NU] / [UID:0000DF] `SortedList`

Evidence for:

- `SortedList` is adjacent and derives from `List`.

Evidence against:

- `SortedList` starts at `0x004f3600` after padding. The target's last raw helper ends at `0x004f35fd`, followed by three `0xcc` bytes.
- The `List` vtable and child docs support base `List`, not `SortedList`, for this target range.

Decision: rejected.

### 5. [UID:0000L7] `MemoryMan`

Evidence for:

- Most methods call MemoryMan allocation/free/realloc/copy wrappers.

Evidence against:

- MemoryMan helper calls are dependencies. The receiver layout and vtable slots are `List`.

Decision: rejected as owner.

## Source Placement

Recommended source placement:

- Aggregate: no emitted source placement; keep as by-memory audit/index page.
- Children: [UID:000079] `List`, emitted through [UID:0000KS] `List` to `auto-generated/NexusTK/util/List.cpp`.

This matches:

- `by-file/List.md` proposed module `NexusTK/util/List.cpp`;
- `by-project-structure/proposed-source-tree.md` utility container section;
- `by-meta/client_containers.md`, which keeps generic containers under `util/`;
- current vtable/class docs.

Rejected placements:

- Feature modules such as Config, HierList, TextEditPane, ObjectList, ImageLib: caller/consumer evidence only.
- MemoryMan: dependency owner only.
- SortedList: adjacent derived class, not owner of base List methods.

## Range / Split / Padding / Reclassification Analysis

No new split is recommended. The current exact child split is correct.

Required repair is not address splitting; it is validator registration and generated-report refresh:

- Scan/register all child pages [UID:0003JT] through [UID:0003K5] with validator file mode.
- Re-scan the aggregate so UID references resolve.
- Refresh generated reports/autogen through validator, not manual edits.

The aggregate should remain `RECONSTRUCTABLE:FALSE`. Exact children remain `RECONSTRUCTABLE:TRUE`.

## IDA Rename / Type / Comment Recommendations

No IDA DB edits were made or requested for this report-only pass.

Source-facing naming recommendations for docs/future IDA comment pass:

| Address | Recommended source-facing name | Confidence | Notes |
| --- | --- | ---: | --- |
| `0x004f3140` | `List::AssignFrom` | high | `CopyFrom` acceptable alternate; current Config callers support destination-side assignment. |
| `0x004f31d0` | `List::SetCount` | medium-high | Could be `SetSize`; behavior is logical count change plus storage resize. |
| `0x004f32a0` | `List::GetData` | high | vtable accessor returning `m_data`. |
| `0x004f32b0` | `List::GetElementAt` | high | vtable element accessor. |
| `0x004f32e0` | `List::InsertAt` / `InsertRange` | medium-high | Takes index, count, source bytes; current child filename uses range. |
| `0x004f33c0` | `List::Append` / `AppendRange` | medium-high | Wrapper through insert slot with current count. |
| `0x004f33e0` | `List::RemoveAt` / `RemoveRange` | medium-high | Takes first index and count. |
| `0x004f34a0` | `List::RemoveAll` | medium-high | Prefer `RemoveAll` over `Clear` because current class docs/vtable map use `RemoveAll`; `Clear` remains a search alias. |
| `0x004f34b0` | `List::SwapElements` | high | Raw disassembly rejects IDA `Size` parameter name. |
| `0x004f3540` | `List::Sort` | high | qsort wrapper. |
| `0x004f3560` | `List::ReserveElementCapacity` | medium | Current filename `ReserveExactElementCountRaw` is descriptive; no xrefs prove original name. |
| `0x004f35a0` | `List::ReservePageCapacity` | medium | Current filename `ReservePageCountRaw` is descriptive; no xrefs prove original name. |
| `0x004f35e0` | `List::PageCountForElementCount` | medium-high | Exact formula proven; no xrefs prove original private helper name. |

## First-Draft C++ Recommendation

Eligible for aggregate draft C++: no.

Exact aggregate no-code proof:

- [UID:00022S] is `RECONSTRUCTABLE:FALSE`.
- The aggregate range is an index/container for exact child pages, not an original source function/class body.
- By-structure says by-memory C++ must represent the page's own range and must not paste child source into the parent. Emitting code here would duplicate or conflate child methods.
- The target's old "below 95+ threshold" rationale should be replaced. The correct no-code reason is non-emitting aggregate disposition plus child-page ownership, not the old 95+ rule.

Child-page C++ recommendation:

- Do not insert formal C++ into the child pages as part of this aggregate callback unless the supervisor explicitly expands the callback to child C++ implementation. Current child pages meet the minimum score/emitter gate, but generated/validator registration is broken, `Item Summary` fields are blank, and MemoryMan copy/allocation helper final API names remain unresolved. That makes formal child C++ from this broad aggregate pass unsafe.
- Implementation should first register the child pages, add summaries, update source-facing names/no-code rationale, and refresh generated output. A later child-specific C++ pass can insert formal code after the shared `List` declaration and MemoryMan helper declarations are chosen.

## Final Recommendation

Recommended changes:

- Keep aggregate metadata `90/91`, `CANONICAL_OWNER:NONE`, `RECONSTRUCTABLE:FALSE`, blank emitter, blank C++.
- Add a 2026-06-25 B002 live-MCP evidence/change note to the target.
- Replace the stale 95+ C++-blocker wording with the aggregate no-code proof above.
- Register existing child pages [UID:0003JT] through [UID:0003K5] through validator file scans; do not edit validator.ini by hand.
- Add concise `Item Summary` text to every child page.
- Update child docs to use the source-facing names in this report, with `RemoveAll` preferred over `Clear` in source API wording while preserving `Clear` as a file/search alias.
- Refresh generated reports through validator/autogen after registration/doc edits. No manual generated-report or coverage-report edit is needed.

## Recommended Target Doc Changes

Target path: `by-memory/0x004f3140-0x004f35fd.ListCoreMethods.md`

Incorporate these facts:

- 2026-06-25 IDA MCP session/database facts from this report.
- Function inventory and raw helper evidence from the MCP tables above.
- Current validator dry-run facts:
  - aggregate dry-run command `000000001453` found missing child UIDs in validator.ini;
  - child dry-run command `000000001454` showed [UID:0003JT] would receive a new UID mapping if applied.
- Generated report mismatch: generated tracker/stats rows are stale; `-ag-memory-coverage.md` knows the aggregate is not-reconstructable but omits the child pages.
- No-code proof: aggregate is non-reconstructable and child-owned; remove stale "95+" rationale.

Recommended score/metadata:

- Keep current `90/91`, owner none, reconstructable false, emitter blank, code blank until the child registration/generated-report issue is repaired.

## Recommended Support Doc Changes

Support paths:

- All child pages [UID:0003JT] through [UID:0003K5].
- `by-class/List.md`
- `by-file/List.md`
- optional `by-project-structure/proposed-source-tree.md` only if supervisor wants generated-report-skew notes in source-tree guidance; no source-tree placement change is needed.

Child `Item Summary` texts to add:

| Child | Summary text |
| --- | --- |
| `0003JT` | `Destination-side List assignment helper that replaces this list's layout/count/data from another List, freeing old backing storage and copying element bytes.` |
| `0003JU` | `List count-resize method that recomputes page capacity, grows or shrinks backing storage, and stores the requested logical count.` |
| `0003JV` | `Virtual List data accessor returning the backing buffer pointer.` |
| `0003JW` | `Virtual List element accessor returning a fixed-width element pointer for valid indices and null for invalid or absent storage.` |
| `0003JX` | `Virtual List insert-at/range method that grows storage, shifts the tail, increments count, and copies caller bytes into the gap.` |
| `0003JY` | `Virtual List append wrapper that inserts caller records at the current logical count through the insert slot.` |
| `0003JZ` | `Virtual List remove-at/range method that shifts the tail down, shrinks backing storage when page capacity drops, and decrements count.` |
| `0003K0` | `Virtual List remove-all wrapper that removes the full current count from index zero through the remove slot.` |
| `0003K1` | `Virtual List element-swap method using a one-element scratch buffer and virtual element accessors.` |
| `0003K2` | `Non-virtual List sort wrapper that calls qsort over the backing buffer using count, element size, and caller comparator.` |
| `0003K3` | `Raw private List capacity helper that allocates or reallocates backing storage for an exact requested element count without changing count.` |
| `0003K4` | `Raw private List capacity helper that reallocates backing storage for a requested page count, falling back to default page size when zero.` |
| `0003K5` | `Raw private List page-count helper returning one page for non-positive counts or rounded-up element-count pages otherwise.` |

Support facts to incorporate in `by-class/List.md` and/or `by-file/List.md`:

- The core child pages are currently exact but need validator registration.
- Source-facing API naming direction:
  - `AssignFrom`, `SetCount`, `GetData`, `GetElementAt`, `InsertAt`, `Append`, `RemoveAt`, `RemoveAll`, `SwapElements`, `Sort`.
  - Private helpers should be documented as capacity/page-count helpers, not left as raw `sub_4F3560`-style names.
- The aggregate [UID:00022S] is no-code because it is a non-emitting index. Formal method C++ belongs on child pages only after the shared `List` declaration and MemoryMan helper API names are ready.

## Score And Metadata Recommendation

Current source page metadata:

```text
COMPLETION:90
CONFIDENCE:91
CANONICAL_OWNER:NONE
RECONSTRUCTABLE:FALSE
EMITTER_UIDS:
```

Recommended metadata now:

```text
COMPLETION:90
CONFIDENCE:91
CANONICAL_OWNER:NONE
RECONSTRUCTABLE:FALSE
EMITTER_UIDS:
```

Reason not higher:

- Child UID references are currently missing from validator.ini.
- Generated coverage/tracker output omits the children and shows stale aggregate score/reconstructable status.
- Child `Item Summary` fields are blank.
- Child formal C++ remains unsafe until registry/source API repair is done.

Score-improvement attempt:

- Rechecked all function boundaries, raw helper bodies, padding, xrefs, and source placement through live IDA MCP.
- Checked generated reports and found the stale/missing-child state.
- Ran validator dry-runs to prove the missing-child issue is validator registration, not missing files.
- Produced an implementation-ready repair plan with exact child pages, summaries, validator commands, and no-code rationale.

## Open Questions With Attempted Resolution

Closed:

- Should the broad range remain single source-bearing item? No; it should remain a non-emitting index.
- Are more children needed? No; the existing child set covers all method/helper bodies and padding.
- Are raw helpers code? Yes, source-authored function-shaped private helpers, even though IDA does not model them.
- Is the aggregate C++ block eligible? No; it is non-reconstructable and child-owned.
- Is the stale generated `72/88` row authoritative? No; validator dry-run and source page metadata show current `90/91` source state, with missing child registration causing generated skew.

Remaining:

- Exact original public/private `List` method spellings are not source-proven. This report recommends source-facing names based on behavior and caller/vtable evidence.
- Exact formal child C++ remains blocked by shared `List` declaration/header and MemoryMan helper API naming. This does not block aggregate disposition.

## Exact Manual Supervisor-Owned Coverage Or Tracker Text

No manual coverage-report or tracker text should be applied. The generated reports should be repaired by validator file scans and autogen refresh after child registration/doc edits. Do not edit `by-memory/-coverage-report.md`, any `-coverage-report.md`, or `auto-generated/-ag-*` rows by hand.

## Follow-Up Actions

Supervisor actions:

- Accept or reject this report.
- If accepted, send B002 an implementation callback that explicitly permits the required validator file scans if validator state updates are allowed for this repair. Otherwise supervisor should run the validator lifecycle commands directly.

B002 implementation callback actions if accepted:

- Edit only the listed target/support docs under leases.
- Register child pages with validator file scans rather than hand-editing validator state.
- Run scoped validators and report command ids/timestamps/results.

## Confidence

- Recommendation confidence: high.
- Score confidence: medium-high for retaining `90/91` until registry/generated issues are repaired.
- Remaining uncertainty: exact original method names and child formal C++ source shape.

## Validator Results

Commands run:

> Executable block R001 was removed from this report and preserved verbatim in [00022S-ListCoreMethods-source-quality-removed.md](00022S-ListCoreMethods-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

Results:

- Both commands were dry-run only (`apply: False`) and exited `0`.
- Aggregate dry-run command id `000000001453`, timestamp `2026-06-25T13:37:30-04:00`, `ok: 1`, reported missing child UIDs and generated refresh `would-defer`.
- Child dry-run command id `000000001454`, timestamp `2026-06-25T13:37:31-04:00`, `ok: 1`, reported `path_update 0003JT ... new UID mapping` as dry-run only.

No generated output was applied. No validator state was changed.

Recommended implementation validators after accepted edits:

> Executable block R002 was removed from this report and preserved verbatim in [00022S-ListCoreMethods-source-quality-removed.md](00022S-ListCoreMethods-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

If support docs are edited, also validate:

> Executable block R003 was removed from this report and preserved verbatim in [00022S-ListCoreMethods-source-quality-removed.md](00022S-ListCoreMethods-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

Implementation callback validator results after accepted edits:

| File | Command id | Timestamp | Exit | ok | Generated refresh |
| --- | --- | --- | ---: | ---: | --- |
| `by-memory/0x004f3140-0x004f31cc.ListAssignFrom.md` | `000000001536` | `2026-06-25T13:55:14-04:00` | 0 | 1 | completed, same id/timestamp |
| `by-memory/0x004f31d0-0x004f329f.ListSetCount.md` | `000000001541` | `2026-06-25T13:55:39-04:00` | 0 | 1 | completed, same id/timestamp |
| `by-memory/0x004f32a0-0x004f32a4.ListGetData.md` | `000000001546` | `2026-06-25T13:56:19-04:00` | 0 | 1 | completed, same id/timestamp |
| `by-memory/0x004f32b0-0x004f32da.ListGetElementAt.md` | `000000001549` | `2026-06-25T13:57:01-04:00` | 0 | 1 | completed, same id/timestamp |
| `by-memory/0x004f32e0-0x004f33b5.ListInsertRange.md` | `000000001552` | `2026-06-25T13:57:32-04:00` | 0 | 1 | completed, same id/timestamp |
| `by-memory/0x004f33c0-0x004f33d5.ListAppendRange.md` | `000000001554` | `2026-06-25T13:58:10-04:00` | 0 | 1 | completed, same id/timestamp |
| `by-memory/0x004f33e0-0x004f3493.ListRemoveRange.md` | `000000001555` | `2026-06-25T13:58:32-04:00` | 0 | 1 | completed, same id/timestamp |
| `by-memory/0x004f34a0-0x004f34ab.ListClear.md` | `000000001556` | `2026-06-25T13:58:44-04:00` | 0 | 1 | completed, same id/timestamp |
| `by-memory/0x004f34b0-0x004f3532.ListSwapElements.md` | `000000001557` | `2026-06-25T13:58:55-04:00` | 0 | 1 | completed, same id/timestamp |
| `by-memory/0x004f3540-0x004f355b.ListSort.md` | `000000001558` | `2026-06-25T13:59:06-04:00` | 0 | 1 | completed, same id/timestamp |
| `by-memory/0x004f3560-0x004f3597.ListReserveExactElementCountRaw.md` | `000000001559` | `2026-06-25T13:59:17-04:00` | 0 | 1 | completed, same id/timestamp |
| `by-memory/0x004f35a0-0x004f35db.ListReservePageCountRaw.md` | `000000001560` | `2026-06-25T13:59:29-04:00` | 0 | 1 | completed, same id/timestamp |
| `by-memory/0x004f35e0-0x004f35fd.ListPageCountForElementCountRaw.md` | `000000001561` | `2026-06-25T13:59:40-04:00` | 0 | 1 | completed, same id/timestamp |
| `by-memory/0x004f3140-0x004f35fd.ListCoreMethods.md` | `000000001562` | `2026-06-25T13:59:51-04:00` | 0 | 1 | completed, same id/timestamp |
| `by-class/List.md` | `000000001563` | `2026-06-25T14:00:03-04:00` | 0 | 1 | completed, same id/timestamp |
| `by-file/List.md` | `000000001564` | `2026-06-25T14:00:14-04:00` | 0 | 1 | completed, same id/timestamp |

Validator side effects and warnings:

- Child scans applied new UID mappings for every requested child page `0003JT` through `0003K5`; the aggregate scan then resolved those child UID references and updated `00022S` generated registry state to `RECONSTRUCTABLE:FALSE`.
- `auto-generated/-ag-coverage-report-by-memory.md`, `auto-generated/-ag-research-tracker.md`, and `auto-generated/NexusTK/util/List.cpp` headers were inspected after validation and show `validator-command-id: 000000001567` and `validator-refreshed-at: 2026-06-25T14:03:29-04:00`, which is newer than the final B002 scoped validator command `000000001564`. The generated by-memory coverage rows list `00022S` and every child `0003JT` through `0003K5` with the new `Item Summary` text.
- Repeated unrelated validator warnings remained: `autogen_registry_stale: 169`, `memory_coverage_metadata_missing_file: 167`, and `autogen_children_marker_missing: 9`. The edited support scans also reported pre-existing `missing_ref_uid 00037L` references in `by-class/List.md` and `by-file/List.md`; that scalar-deleting-destructor registry repair is outside this narrowed callback and was not widened into this implementation.

## Changed Files

Created:

- `tools/leaser/Agents/Agent-B002/research/00022S-ListCoreMethods-source-quality.md`

Modified:

- Implementation callback modified target/support docs:
  - `by-memory/0x004f3140-0x004f35fd.ListCoreMethods.md`
  - child pages `by-memory/0x004f3140-0x004f31cc.ListAssignFrom.md` through `by-memory/0x004f35e0-0x004f35fd.ListPageCountForElementCountRaw.md`
  - `by-class/List.md`
  - `by-file/List.md`
- Validator-managed side effects refreshed generated reports/autogen output and validator UID mappings through scoped `--apply --wait-generated`; no generated, project-level, coverage-report, validator state/cache, or IDA DB file was edited by hand.

Renamed:

- None.

Leases:

- Implementation callback leased the aggregate, 13 child pages, `by-class/List.md`, and `by-file/List.md` as B002 for the immediate edit/validator batch.
- Release was attempted immediately after the validator batch; `leaser.py B002 unlease ...` reported `Rejected[No active lease]` for each path because the short leases had already expired during the validator sequence. `tools/leaser/Agents/Agent-B002/current_leases.md` was checked afterward and showed no active B002 leases.

Report execution:

- Leave blank during B-agent pass. Supervisor runs `tools/validator.py execute_report ... --apply` only after validation and implementation verification.

## Implementation Tracking Checklist

Initial report-only pass:

- [x] Supervisor validation required before implementation. Proof: user/supervisor callback accepted this report for implementation under assignment `B002-implement-00022S-list-core-methods-20260625`.
- [x] Target doc to update: `by-memory/0x004f3140-0x004f35fd.ListCoreMethods.md` with 2026-06-25 IDA MCP evidence, validator dry-run missing-child diagnostics, generated-report mismatch, and corrected aggregate no-code proof. Proof: target now has `2026-06-25 B002 Registration And Source-Route Recheck`, updated `Item Summary`, and superseded aggregate no-code rationale.
- [x] Support docs to update: all child pages [UID:0003JT] through [UID:0003K5] with concise `Item Summary` text and source-facing naming/no-code rationale from this report. Proof: every child has a nonblank `Item Summary` and a `Source-Facing Context` section.
- [x] Optional support docs to update if accepted: `by-class/List.md` and `by-file/List.md` with child registration caveat, method naming direction, and aggregate no-code/source placement clarification. Proof: both support docs now record the 2026-06-25 B002 registration/source-summary repair and source-facing method/helper direction.
- [x] Current target state and actual evidence checked recorded: target metadata, generated mismatch, MCP session/database, function inventory, decompilation, xrefs, raw helper disassembly, signatures, padding, and validator dry-runs are recorded in this report. Proof: original report preserved; target now incorporates the accepted MCP/validator/generator facts.
- [x] Metadata/score changes to apply: keep aggregate `90/91`, `CANONICAL_OWNER:NONE`, `RECONSTRUCTABLE:FALSE`, blank emitter/code; do not follow stale generated `72/88` rows. Proof: aggregate metadata unchanged; validator command `000000001562` refreshed generated registry state as false reconstructable.
- [x] Score-limiting blockers researched to repair plan: child UID registry absence, generated-report omission, blank child summaries, stale 95+ wording, raw helper no-xref state, and child C++ readiness are each addressed with evidence and implementation-ready action. Proof: children registered, summaries filled, generated rows refreshed, obsolete `95+` aggregate rationale replaced, raw-helper no-xref status preserved, and child C++ deferral documented.
- [x] Owner/emitter/reconstructable changes to apply: none for aggregate; keep children as `CANONICAL_OWNER:000079`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:000079` after validator registration. Proof: no by-* metadata changes were made beyond text/summary edits; child validator scans registered the existing metadata.
- [x] Split/rename/new-child changes to apply: no new split; no rename required. Existing child pages must be registered by validator file scans. Proof: no files renamed/created; validator commands `000000001536` through `000000001561` registered children `0003JT` through `0003K5`.
- [x] Source-placement, range/split/padding/reclassification changes: confirm aggregate as non-emitting index; confirm all internal gaps as `0xcc`; confirm successor `SortedList` starts at `0x004f3600`. Proof: aggregate target preserves padding/successor evidence and now records the accepted non-emitting index rationale.
- [x] IDA rename/type/comment changes: none applied; optional future IDA comment/name recommendations are listed in this report if an IDA edit pass is authorized. Proof: no IDA DB edits were made; source-facing names were documented in Markdown only.
- [x] First-draft C++ or no-code proof to apply: aggregate no-code proof only; no child C++ from this aggregate report unless supervisor explicitly expands scope. Proof: all formal `RECONSTRUCTION_CPP CODE` blocks remain blank; aggregate and child pages record the callback-scoped no-code rationale.
- [x] Exact target/support doc facts to incorporate at report-level detail: include MCP tables, xref counts, raw helper instruction semantics, validator dry-run diagnostics, generated skew, child summary table, and source-facing method-name table. Proof: target carries B002 MCP/validator/generator evidence; children carry source-facing context; class/file support docs carry method/helper direction.
- [x] Historical/stale assumptions, rejected alternatives, and negative evidence to preserve: stale 95+ C++ gate wording should be superseded; stale generated `72/88` row should be documented as generated skew; raw helper no-xref status should be preserved. Proof: aggregate explicitly supersedes stale `95+` rationale and generated skew; raw-helper pages preserve no-xref/no-function modeling limits.
- [x] Wave2/Wave3 mentions or artifacts encountered and ignored/rejected as stale: generated/simroot references treated as leads only; `source-3/simroot_v2/class_List.cpp` not present in workspace. Proof: no Wave/simroot claim was promoted to authority in target/support docs.
- [x] Open questions to close or document as evidence-backed unresolved: exact original method spellings and child formal C++ source shape remain unresolved with score/C++ impact recorded. Proof: child `Source-Facing Context` sections document preferred names, aliases, and why formal C++ is deferred.
- [x] Validators to run: child file scans, aggregate scan, and edited support scans as listed above; use validator commands, not hand edits to validator.ini/generated reports. Proof: validators `000000001536` through `000000001564` ran with `--apply --queue-timeout 240 --wait-generated`, exit 0, `ok=1`.
- [x] Generated report refresh expected: after validator `--apply --wait-generated`, `-ag-memory-coverage.md`, `-ag-coverage-report-by-memory.md`, `-ag-research-tracker.md`, generated `NexusTK/util/List.cpp`, and stats rows should be checked for freshness by command id/timestamp. No manual coverage/tracker text is needed. Proof: inspected generated headers show command id `000000001567` and timestamp `2026-06-25T14:03:29-04:00`, newer than B002's final validator command; by-memory auto coverage rows list `00022S` and `0003JT` through `0003K5` with new summaries.

Implementation callback pass:

- [x] Report accepted by supervisor for implementation. Proof: callback assignment `B002-implement-00022S-list-core-methods-20260625` accepted the split/registration/source-summary repair.
- [x] Leases acquired only for immediate edits and released immediately after validators. Proof: B002 leased the aggregate, children, and two support docs immediately before editing; release was attempted immediately after validation, and current lease report confirmed no active B002 leases because they expired during the validator batch.
- [x] All accepted target/support doc details incorporated at report-level detail. Proof: target, all child pages, `by-class/List.md`, and `by-file/List.md` carry the accepted evidence/source-summary/no-code/source-route facts.
- [x] Child pages registered via validator file scans, or supervisor-owned validator-state repair documented if B002 is not authorized to update validator state. Proof: child file validators `000000001536`, `000000001541`, `000000001546`, `000000001549`, `000000001552`, `000000001554`, `000000001555`, `000000001556`, `000000001557`, `000000001558`, `000000001559`, `000000001560`, and `000000001561` applied new path mappings for `0003JT` through `0003K5`.
- [x] Metadata/score/owner/emitter/split/C++ changes applied or explicitly not applied with reason. Proof: metadata intentionally unchanged; no split/rename/new child; no C++ added because this callback did not widen into child source-body emission.
- [x] Historical/stale assumptions, rejected alternatives, and negative evidence preserved. Proof: aggregate records stale generated state, superseded `95+` rationale, rejected `SortedList`/MemoryMan/feature ownership, and raw helper no-xref status.
- [x] Open questions resolved or documented with evidence-backed unresolved rationale. Proof: method spellings are documented as source-facing direction with aliases; child formal C++ remains deferred for shared `List` declaration and MemoryMan helper API settlement.
- [x] Validators run and results recorded with command id, timestamp, exit code, ok count, generated refresh status, and generated-header freshness. Proof: implementation validator table above records all 16 scoped commands; generated headers inspected at command id `000000001567`, newer than the final B002 scoped command.
- [x] Remaining unapplied accepted items listed with exact blocker. Proof: no accepted item remains unapplied. Residual `missing_ref_uid 00037L` warnings are pre-existing support-doc registry state outside this narrowed callback.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B002","command_id":"000000004165","destination_path":"executed-b-agent-research/B002/00022S-ListCoreMethods-source-quality.md","details":"legacy registry reconstruction","event":"executed","source_path":"tools/leaser/Agents/Agent-B002/research/00022S-ListCoreMethods-source-quality.md","timestamp":"2026-06-25T14:10:56","uid":"00022S"} -->
<!-- {"agent":"B002","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 00022S-ListCoreMethods-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B002/00022S-ListCoreMethods-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"00022S"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
