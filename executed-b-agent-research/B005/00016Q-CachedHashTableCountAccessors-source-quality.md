** TARGET-REPORT-UID:00016Q **
** AUTHOR-AGENT-ID:B005 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.6 | xHigh **

# UID00016Q CachedHashTable Count Accessors Source-Quality Research

## Finalized Report / Current Recommendation

- Current recommendation: retain [UID:00016Q] as the exact paired non-virtual accessor child for `CachedHashTable::GetSlotCount() const` and `CachedHashTable::GetEntryCount() const`. The accepted ordinary callback now has the target at `94/95`, preserves owner/emitter [UID:0000HZ], and keeps the existing formal CPP bodies unchanged.
- Final disposition: source-authored, reconstructable utility code in `NexusTK/util/CachedHashTable.cpp`; no direct surviving caller or pointer route is present, so the best liveness classification is retained utility/legacy API rather than dead padding or compiler output.
- Required action: the current live-MCP evidence, resolved source-facing field/type/name decisions, padding and reachability proof, historical IDA-state correction, and target score changes are incorporated in the ordinary docs. The supervisor still owns the structured IDA type/name/comment actions in Section 21, four manual coverage-row replacements and their scoped validation, coherent generated refresh/readback, and lifecycle execution in that order.
- Confidence: very strong for ranges, bytes, behavior, ABI, class identity, field semantics, ownership, and source placement; strong for reconstructed lexical names and signed count declarations.

## Supporting Research

- Current target and support documentation: [UID:00016Q], [UID:0000HZ] by-file, [UID:00001F] by-class, [UID:00016P] raw helpers, [UID:00016O] lifecycle, [UID:0001TU] layout, [UID:0001X6] vtable, and generated `NexusTK/util/CachedHashTable.cpp`.
- Matching archived research found by UID/name search: B002 `executed-b-agent-research/B002/00016P-cached-hash-table-raw-helpers-source-quality.md` and B009 `executed-b-agent-research/B009/00016O-CachedHashTableLifecycle-source-quality.md`. They are corroborating historical research, not current IDA-state authority.
- Historical correction: [UID:0001TU] records that source-quality names were applied on 2026-06-16, and B002 later observed those names. The current canonical IDB instead has `sub_4C64B0` and `sub_4C64C0`, `_DWORD *this` prototypes, absent comments, and no `CachedHashTable` local UDT. The old rename statement remains useful history but is not the current persisted state.
- Current generated source is validator-owned command `000000021763`, SHA256 `883A5528C88E8448D5E45E7D9F5299DBDD2BF2E565291E2E5737D7C7279CBC0E`, 1166 bytes. It emits the two exact target bodies and five unrelated same-file empty markers; no generated header exists for this source family.
- Report lifecycle state is authoritative only from the report's current path and validator-owned status/history metadata. This body makes no claim that the report has been executed or archived.

## Target

- Target UID: [UID:00016Q].
- Additional target UIDs: none. Related UIDs are support evidence only and are not independently rescored by this report.
- Declared-target inventory: `by-memory/0x004c64b0-0x004c64c4.CachedHashTableCountAccessors.md`, paired exact method child and current CPP emitter.
- Target path: `by-memory/0x004c64b0-0x004c64c4.CachedHashTableCountAccessors.md`.
- Source queue/report row at research start: `auto-generated/-ag-research-tracker.md` by-memory row, `86/91`, reconstructable `true`, report count `0`. Generated tracker state remains supervisor-owned and was not refreshed by B005.
- Current supervisor classification: Gate 1 accepted; B005 ordinary implementation and physical revalidation callback complete; supervisor Gate 2A/2B, generated/manual coverage, and lifecycle work remain pending.
- Current target-document scores and parent state: `COMPLETION:94`, `CONFIDENCE:95`, `CANONICAL_OWNER:0000HZ`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000HZ`, blank optional position.

## Current Target State

- Current metadata is internally routed and reconstructable at accepted `94/95`; target prose now includes the current canonical IDB recheck and source-quality conclusions.
- Existing owner/emitter state is correct: [UID:0000HZ] owns `NexusTK/util/CachedHashTable.cpp`, while [UID:00001F] is the semantic class support page.
- Existing C++ state is source-shaped and behaviorally exact: both formal CPP definitions are present. Formal H is blank.
- Existing target questions were original accessor spelling, exact field spelling/signedness, direct reachability, persisted IDA names/types/comments, and whether the pair should split. This report resolves each into a selected source-quality direction rather than retaining an investigation placeholder.
- Resolved ordinary-doc drift: the target now ranks final source names, [UID:0001TU] historicalizes old aliases and the earlier rename record while recording the current raw canonical IDA state, and class/file support pages carry the accepted accessor evidence. The manual coverage row remains supervisor-owned and stale until C16Q-063 is applied.
- Related docs checked: [UID:0000HZ], [UID:00001F], [UID:00016P], [UID:00016O], [UID:0001TU], [UID:0001X6], and current generated memory/research reports.
- Current artifact/lifecycle status: this is a non-executable research and implementation-handoff artifact. Execution/archive truth is supervisor-owned and authoritative only from the report's current path plus validator-owned status/history metadata.

## Executive Recommendation

Keep the exact paired page and its existing [UID:0000HZ] owner/emitter route. Do not split the two accessors: they are adjacent, semantically paired count queries from one class, have identical ABI/source shape, and the existing page covers both bodies plus only their internal alignment gap without crossing into the neighboring raw helper.

Adopt `GetSlotCount` for `+0x10` and `GetEntryCount` for `+0x14`. Adopt `int` for both source return fields because the existing source family and project count APIs consistently use signed `int`, the constructor receives both sizes as 32-bit integers, and all valid object states are nonnegative. Unsigned branch conditions in index/loop helpers do not outweigh that source convention; they enforce bounds for indexes and valid capacities. Adopt `m_entries`, `m_slotState`, `m_entrySize`, `m_slotCount`, `m_entryCount`, and `m_hashSeed[4]` as the consistent human-written field set.

Keep the target at its now-applied `94/95`. The exact bodies, field offsets, class RTTI, ABI, boundaries, source placement, formal CPP, and negative route evidence are closed. Completion remains below `95` because the class-wide formal header and raw helper family are owned by broader support work, not because this target's C++ is unresolved.

## Supervisor Active Recheck

- Trigger: the supervisor assigned UID00016Q specifically as score-improvement research and required live IDA MCP, exhaustive blocker resolution, exact formal CPP/H, and structured IDA handoff.
- Split repair before a final report: not required. The page is already the narrowest useful paired source unit; a one-function-per-page split would add routing overhead without improving binary or source fidelity.
- Source-bearing children: the page contains exactly two source methods. Both have exact formal CPP; the internal `0xcc` alignment is non-source. No source-bearing target child remains missing.
- Callback boundary: B005 changed only the four accepted ordinary by-* destinations and this report, ran only their four scoped file validators, and did not edit coverage/generated/tracker/validator-state/lifecycle files or IDA. The scoped validator normally updated projected completion statistics and deferred generated refresh under its own ownership.

## Inference Research Guidance Check

- IDA fact: exact instructions, range heads/ends, current names/types/comments, xrefs, bytes, RTTI names, vtable route, constructor field writes, and local-type absence.
- Documentation evidence: current owner/emitter routing, source tree, layout, helper semantics, historical PE-aware no-route scan, and existing formal CPP.
- Inference: original lexical names, signed source declarations, retained-utility liveness, and the most plausible human field style.
- Existing docs were not treated as proof of current IDA state. Their historical rename statement was directly contradicted by the current canonical IDB and is therefore historicalized rather than copied forward.
- `by-structure.md` discipline supports keeping one paired page because the range maps two exact methods and internal compiler alignment while excluding predecessor and successor helpers.
- Wave2/Wave3 mentions in old support pages were encountered and ignored as stale workflow/source authority. No conclusion relies on them.

## Heuristic / Inference Reanalysis And Validation

| Issue | Evidence checked | Best resolution | Status |
| --- | --- | --- | --- |
| Accessor names | Exact offsets, constructor writes, raw helper semantics, project getter naming, old reports | `GetSlotCount` and `GetEntryCount` are the highest-probability human names. `GetCapacity`/`GetCount` are shorter alternatives but lose the class's two-count distinction. | resolved by inference |
| Field names | Constructor/destructor/helpers/accessors and current formal CPP | Use `m_entries`, `m_slotState`, `m_entrySize`, `m_slotCount`, `m_entryCount`, `m_hashSeed[4]`; keep older `entriesBuffer`/`slotStateBuffer` terms as historical descriptive aliases. | resolved by inference |
| Count signedness | 32-bit loads/stores, constructor args, unsigned bounds branches, project source style | Use `int` for size/count fields and accessor returns; use `unsigned int` only for slot indexes. This preserves all valid-state behavior and matches existing project conventions. | resolved by inference |
| Buffer types | Byte-granular allocation/copy/state operations | `unsigned char *m_entries` and `unsigned char *m_slotState`; `void *` is too weak for source reconstruction. | resolved by binary semantics |
| Active runtime route | `xrefs_to`, bidirectional `xref_query`, VA/RVA pattern search, historical PE scan, vtable inspection | No direct route survives. Classify as retained utility/legacy API, not padding, dead data, or compiler-only code. | exact negative evidence |
| Owner/source placement | RTTI, constructor/vtable/helper cluster, current docs, no feature callers | [UID:0000HZ] `NexusTK/util/CachedHashTable.cpp`. | resolved |
| Pair vs split | Exact items and padding boundaries | Keep paired page. Both source methods are exact and the internal alignment belongs to their physical cluster. | resolved |
| Formal H | Target, class page, generated output | Keep child H blank. Member declarations must be inserted only inside the complete class declaration owned by [UID:00001F]; standalone child declarations would be invalid C++. | resolved |
| IDA source quality | Current names/types/comments and absent UDT | Create the exact 0x1c analysis UDT, then apply the two source-quality function names, pointer-to-const receiver types, and comments under supervisor Gate 2B. | implementation-ready handoff |

Rejected alternatives:

- `GetCapacity` plus `GetCount`: plausible generic-container vocabulary, but weaker than names that preserve the exact slot-versus-entry distinction already supported throughout this source family.
- Unsigned return types: possible at the machine-code level, but weaker than established project `int` count APIs and current formal source; unsigned comparisons are explained by index/bounds semantics.
- Inline methods in a header: rejected because each accessor has a distinct out-of-line binary body and address.
- Feature-local ownership: rejected because no caller, string, global, resource, packet route, or feature state ties the pair to a feature module.
- No-owner/non-reconstructable: rejected because the methods are complete source-authored class code over exact fields and already emit behaviorally exact C++.

## Evidence Standards Used

- Direct live IDA MCP evidence: `idb_list`, `server_health`, `lookup_funcs`, `analyze_function`, `decompile`, `disasm`, `get_bytes`, `inspect_items`, `get_comments`, `stack_frame`, `xrefs_to`, `xref_query`, `find_bytes`, `entity_query`, `type_query`, `type_inspect`, and `search_structs`.
- Binary context: exact function and item boundaries, surrounding `0xcc` regions, constructor field writers, vtable/RTTI data, and negative address/pointer searches.
- Documentation context: target/support by-* pages, matching archived B reports, current generated C++, manual coverage, generated memory coverage, and research tracker.
- Evidence ladder: live canonical IDB facts override historical report assertions; exact bytes and field writer/reader agreement outrank decompiler labels; inference is used only for source spelling and declared signedness after direct evidence narrows the choices.
- Tool context: session health is `status:ok`, Hex-Rays and strings cache are ready, and all required bounded IDB queries succeeded. `auto_analysis_ready:false` is recorded but did not make MCP unavailable under the current skill.

## Evidence Checked

- IDA MCP session: `supervisor-b005-final-persisted-verify-20260810`, canonical `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, worker PID `25308` at `idb_list` readback.
- Health: module `NexusTK.exe`, image base `0x00400000`, `status:ok`, Hex-Rays ready, strings cache ready with 2068 entries, and bounded live queries successful.
- Target functions: lookup, full analysis, decompile, disassembly, stack frame, exact bytes, containing items, and all four comment channels for both starts.
- Class support: constructor analysis at `0x004c6160`, destructor analysis at `0x004c6260`, vtable bytes/xrefs at `0x0061aac4`, RTTI names at `0x00647de8` and `0x0067640c`, and current local-type catalog state.
- Negative route checks: zero incoming start xrefs, zero exclusive-end xrefs, bidirectional xref query, zero little-endian VA/RVA pointer hits, vtable slot inventory, and historical external rel32/Jcc/short-branch/VA/RVA scan.
- Body-pattern check: `8B 41 10 C3` has six image matches and `8B 41 14 C3` has three. Therefore the four-byte shapes alone do not identify the class; constructor/layout/RTTI adjacency supplies the class proof.
- Documentation/generated checks: target and all named support pages, matching B002/B009 reports, manual coverage line 1677, generated memory row 1020, research tracker row 1683, and generated `CachedHashTable.cpp` command `000000021763`.
- Support manual-coverage inspection after the ordinary callback:
  - [UID:0000HZ] `by-file/-coverage-report.md` line 43, SHA256 `5CD0F53214FEE83C7281A5C4DAFA8BBB14827C81DBDD1C154ED81CD376D49285`. Exact current row text follows; the `>` quote marker is not part of the row:
    > - [UID:0000HZ][CachedHashTable](by-file/CachedHashTable.md) : reconstructable : 84% : strong : `NexusTK/util/CachedHashTable.cpp` utility hash/cache class with live IDA lifecycle boundaries, exact vtable-data child, raw helper island, count accessors, and no-caller caveat documented.
    The path is current, but `84%` is stale against the unchanged by-file metadata `85`, and the summary omits the accepted accessor ABI/RTTI/name/type/current-IDA-state additions.
  - [UID:00001F] `by-class/-coverage-report.md` line 77, SHA256 `4F76F695284E20D8FE8EEFCEC6DB86429B2841DD11D71F048693F46A5A05E8B0`, currently reads exactly: `- [UID:00001F][CachedHashTable](by-class/CachedHashTable.md) : reconstructable : 86% : strong : Utility hash/cache table layout, live IDA lifecycle boundaries, raw helper island, exact vtable-data child range, and no-caller caveat are documented; live construction remains unresolved.` The path and `86%` are current, but the summary is stale because it omits both explicit non-virtual getter rows, the selected `m_` member set, and the child-CPP/whole-class-H declaration boundary.
  - [UID:0001TU] `by-type/by-struct/-coverage-report.md` line 24, SHA256 `51ACA03865C84EAA426E63CE427539F72BD7944E3B1B86B6C5AB8A9F9B9FA051`. Exact current row text follows; the `>` quote marker is not part of the row:
    > - [UID:0001TU][CachedHashTableLayout](by-type/by-struct/CachedHashTableLayout.md) : reconstructable : 85% : strong : C001 2026-06-16 live IDA refresh reconfirmed the 28-byte `CachedHashTable` constructor/destructor/accessor layout, raw helper no-function/no-xref status, vtable-only lifecycle refs, and no live construction callers; safe IDA names were applied for modeled lifecycle/accessor methods while final field/helper names remain provisional.
    The path and `85%` are current, but the summary is factually stale: fresh canonical readback has raw accessor names/no local UDT, and the callback selected the final source-facing field set while historicalizing old aliases and the earlier rename record.
- Intentionally skipped: no mutation, save, process control, validator, generated refresh, coverage edit, lifecycle command, or report execution was permitted in report-only scope.

## Claim And Incorporation Ledger

| Claim ID | Target UID | Claim | Confidence | Evidence | Destination doc/section | Action | Verification state |
| --- | --- | --- | --- | --- | --- | --- | --- |
| C16Q-001 | 00016Q | Method `[0x004c64b0,0x004c64b4)` has exact bytes `8B 41 10 C3`. | exact | `get_bytes` | `by-memory/0x004c64b0-0x004c64c4.CachedHashTableCountAccessors.md` / Covered Ranges | incorporate | applied |
| C16Q-002 | 00016Q | Method `[0x004c64c0,0x004c64c4)` has exact bytes `8B 41 14 C3`. | exact | `get_bytes` | `by-memory/0x004c64b0-0x004c64c4.CachedHashTableCountAccessors.md` / Covered Ranges | incorporate | applied |
| C16Q-003 | 00016Q | Internal `[0x004c64b4,0x004c64c0)` is one twelve-byte `0xCC` item with name absent and type absent. | exact | `inspect_items` | `by-memory/0x004c64b0-0x004c64c4.CachedHashTableCountAccessors.md` / Range Analysis | incorporate | applied |
| C16Q-004 | 00016Q | Predecessor `[0x004c64a7,0x004c64b0)` is one nine-byte `0xCC` item with name absent and type absent outside the target. | exact | `inspect_items` | `by-memory/0x004c64b0-0x004c64c4.CachedHashTableCountAccessors.md` / Boundary Analysis | incorporate | applied |
| C16Q-005 | 00016Q | Successor `[0x004c64c4,0x004c64d0)` is one twelve-byte `0xCC` item with name absent and type absent outside the target. | exact | `inspect_items` | `by-memory/0x004c64b0-0x004c64c4.CachedHashTableCountAccessors.md` / Boundary Analysis | incorporate | applied |
| C16Q-006 | 00016Q | The first method returns `m_slotCount` from object offset `+0x10`. | exact semantics | `decompile` | `by-memory/0x004c64b0-0x004c64c4.CachedHashTableCountAccessors.md` / Behavior | incorporate | applied |
| C16Q-007 | 00016Q | The second method returns `m_entryCount` from object offset `+0x14`. | exact semantics | `decompile` | `by-memory/0x004c64b0-0x004c64c4.CachedHashTableCountAccessors.md` / Behavior | incorporate | applied |
| C16Q-008 | 00016Q | The first method is a leaf `int __thiscall` non-virtual accessor with implicit ECX receiver and only the return-address stack row. | exact ABI | `stack_frame` | `by-memory/0x004c64b0-0x004c64c4.CachedHashTableCountAccessors.md` / ABI | incorporate | applied |
| C16Q-009 | 00016Q | The second method is a leaf `int __thiscall` non-virtual accessor with implicit ECX receiver and only the return-address stack row. | exact ABI | `stack_frame` | `by-memory/0x004c64b0-0x004c64c4.CachedHashTableCountAccessors.md` / ABI | incorporate | applied |
| C16Q-010 | 00016Q | The first method start has zero incoming xrefs. | exact negative | `xrefs_to` | `by-memory/0x004c64b0-0x004c64c4.CachedHashTableCountAccessors.md` / Reachability | incorporate | applied |
| C16Q-011 | 00016Q | The second method start has zero incoming xrefs. | exact negative | `xrefs_to` | `by-memory/0x004c64b0-0x004c64c4.CachedHashTableCountAccessors.md` / Reachability | incorporate | applied |
| C16Q-012 | 00016Q | Little-endian VA/RVA searches for `0x004c64b0` found no pointer route. | exact negative | `find_bytes` | `by-memory/0x004c64b0-0x004c64c4.CachedHashTableCountAccessors.md` / Reachability History | incorporate | applied |
| C16Q-013 | 00016Q | Little-endian VA/RVA searches for `0x004c64c0` found no pointer route. | exact negative | `find_bytes` | `by-memory/0x004c64b0-0x004c64c4.CachedHashTableCountAccessors.md` / Reachability History | incorporate | applied |
| C16Q-014 | 00016Q | The accessor byte patterns are not globally unique, so class identity depends on layout/RTTI context. | exact negative | `find_bytes` | `by-memory/0x004c64b0-0x004c64c4.CachedHashTableCountAccessors.md` / Evidence Standards | incorporate | applied |
| C16Q-015 | 00016Q | Constructor `0x004c6160` proves buffers at `+0x04/+0x08`, entry size at `+0x0c`, slot count at `+0x10`, entry count at `+0x14`, and seed at `+0x18`. | exact | `analyze_function` | `by-memory/0x004c64b0-0x004c64c4.CachedHashTableCountAccessors.md` / Field Proof | incorporate | applied |
| C16Q-016 | 00016Q | RTTI complete-object-locator name `??_R4CachedHashTable@@6B@` supports the class identity. | exact | `entity_query` | `by-memory/0x004c64b0-0x004c64c4.CachedHashTableCountAccessors.md` / Class Evidence | incorporate | applied |
| C16Q-017 | 00016Q | RTTI type-descriptor name `??_R0?AVCachedHashTable@@@8` supports the class identity. | exact | `entity_query` | `by-memory/0x004c64b0-0x004c64c4.CachedHashTableCountAccessors.md` / Class Evidence | incorporate | applied |
| C16Q-018 | 00016Q | Vtable `0x0061aac4` routes only scalar deleting destructor `0x004c64f0`; the accessors are non-virtual. | exact | `xrefs_to` | `by-memory/0x004c64b0-0x004c64c4.CachedHashTableCountAccessors.md` / Virtuality Evidence | incorporate | applied |
| C16Q-019 | 00016Q | The local type catalog has no `CachedHashTable` UDT. | exact | `type_query` | `by-memory/0x004c64b0-0x004c64c4.CachedHashTableCountAccessors.md` / IDA Status | incorporate | applied |
| C16Q-020 | 00016Q | Best source fields are `m_entries`, `m_slotState`, `m_entrySize`, `m_slotCount`, `m_entryCount`, and `m_hashSeed[4]` with total size `0x1c`. | strong inference | `analyze_function` | `by-memory/0x004c64b0-0x004c64c4.CachedHashTableCountAccessors.md` / Naming | incorporate | applied |
| C16Q-021 | 00016Q | `GetSlotCount` is the highest-probability source name for the `+0x10` accessor. | strong inference | `decompile` | `by-memory/0x004c64b0-0x004c64c4.CachedHashTableCountAccessors.md` / Names | incorporate | applied |
| C16Q-022 | 00016Q | `GetEntryCount` is the highest-probability source name for the `+0x14` accessor. | strong inference | `decompile` | `by-memory/0x004c64b0-0x004c64c4.CachedHashTableCountAccessors.md` / Names | incorporate | applied |
| C16Q-023 | 00016Q | The best liveness classification is retained utility/legacy API with no surviving direct route. | very strong | `xref_query` | `by-memory/0x004c64b0-0x004c64c4.CachedHashTableCountAccessors.md` / Status And Ownership | incorporate | applied |
| C16Q-024 | 00016Q | Preserve `CANONICAL_OWNER:0000HZ`. | very strong | physical target reread | `by-memory/0x004c64b0-0x004c64c4.CachedHashTableCountAccessors.md` / CANONICAL_OWNER | already-present | already-present |
| C16Q-025 | 00016Q | Final source placement remains `NexusTK/util/CachedHashTable.cpp` through [UID:0000HZ]. | very strong | physical source-route reread | `by-memory/0x004c64b0-0x004c64c4.CachedHashTableCountAccessors.md` / Source Placement | incorporate | applied |
| C16Q-026 | 00016Q | Keep the paired range intact with no split, merge, extension, reclassification, or new child. | strong | `inspect_items` | `by-memory/0x004c64b0-0x004c64c4.CachedHashTableCountAccessors.md` / Range And Split | already-present | already-present |
| C16Q-027 | 00016Q | Preserve the existing formal CPP containing the two out-of-line `int` const accessor definitions. | very strong | physical target CPP reread | `by-memory/0x004c64b0-0x004c64c4.CachedHashTableCountAccessors.md` / RECONSTRUCTION_CPP CODE | already-present | already-present |
| C16Q-028 | 00016Q | Preserve the target formal H as blank because declarations belong in the complete class declaration. | strong | physical target H reread | `by-memory/0x004c64b0-0x004c64c4.CachedHashTableCountAccessors.md` / RECONSTRUCTION_H CODE | already-present | already-present |
| C16Q-029 | 00016Q | Raise `COMPLETION:86` to `94`. | strong | physical target metadata reread | `by-memory/0x004c64b0-0x004c64c4.CachedHashTableCountAccessors.md` / COMPLETION | incorporate | applied |
| C16Q-030 | 00016Q | Replace the target Item Summary with the exact source-ready summary in Section 24. | very strong | physical target Item Summary reread | `by-memory/0x004c64b0-0x004c64c4.CachedHashTableCountAccessors.md` / Item Summary | incorporate | applied |
| C16Q-031 | 00016Q | Add the exact current canonical function-name/type/comment prestate without pruning older valid facts. | very strong | physical target IDA-state reread | `by-memory/0x004c64b0-0x004c64c4.CachedHashTableCountAccessors.md` / IDA Status | incorporate | applied |
| C16Q-032 | 00016Q | Add current accessor body/ABI/RTTI/no-route/name/type evidence without changing file metadata. | strong | physical by-file reread | `by-file/CachedHashTable.md` / UID00016Q Evidence | incorporate | applied |
| C16Q-033 | 00016Q | Add the explicit non-virtual `GetSlotCount` method row without changing class metadata. | strong | physical by-class reread | `by-class/CachedHashTable.md` / Method Inventory / GetSlotCount | incorporate | applied |
| C16Q-034 | 00016Q | Synchronize source-facing field names/types to the selected `m_` field set without changing layout metadata. | strong | physical layout reread | `by-type/by-struct/CachedHashTableLayout.md` / Naming | incorporate | applied |
| C16Q-035 | 00016Q | Retain `entriesBuffer` and `slotStateBuffer` only as historical descriptive aliases. | strong | physical layout reread | `by-type/by-struct/CachedHashTableLayout.md` / Historical Changes | historicalize | applied |
| C16Q-036 | 00016Q | UID00016P already contains same-or-greater raw-helper context and needs no ordinary edit for this target. | strong | physical raw-helper doc reread | `by-memory/0x004c62d0-0x004c64e1.CachedHashTableRawHelpers.md` / current body | already-present | already-present |
| C16Q-037 | 00016Q | UID00016O already contains same-or-greater lifecycle context and needs no ordinary edit for this target. | strong | physical lifecycle doc reread | `by-memory/0x004c6160-0x004c659c.CachedHashTableLifecycle.md` / current body | already-present | already-present |
| C16Q-038 | 00016Q | UID0001X6 already contains same-or-greater vtable context and needs no ordinary edit for this target. | strong | physical vtable doc reread | `by-type/by-vtable/CachedHashTableVtable.md` / current body | already-present | already-present |
| C16Q-039 | 00016Q | Preserve the 2026-06-16 rename record only as superseded history. | exact correction | physical target history reread | `by-memory/0x004c64b0-0x004c64c4.CachedHashTableCountAccessors.md` / Historical IDA State | historicalize | applied |
| C16Q-040 | 00016Q | Supervisor Gate 2B should declare the exact `CachedHashTable` 0x1c analysis UDT from A01. | strong | `type_inspect` | IDA local type `CachedHashTable` | incorporate | proposed |
| C16Q-041 | 00016Q | Supervisor Gate 2B should pure-rename `0x004c64b0` to `CachedHashTable_GetSlotCount`. | strong | `lookup_funcs` | IDA function `0x004c64b0` / name | incorporate | proposed |
| C16Q-042 | 00016Q | Supervisor Gate 2B should apply signature `int __thiscall CachedHashTable_GetSlotCount(const CachedHashTable *this)` at `0x004c64b0`. | strong | `inspect_items` | IDA function `0x004c64b0` / type | incorporate | proposed |
| C16Q-043 | 00016Q | Supervisor Gate 2B should set the exact A02 address regular comment. | strong | `get_comments` | IDA address `0x004c64b0` / regular comment | incorporate | proposed |
| C16Q-044 | 00016Q | Supervisor Gate 2B should set the exact A02 address repeatable comment. | strong | `get_comments` | IDA address `0x004c64b0` / repeatable comment | incorporate | proposed |
| C16Q-045 | 00016Q | Supervisor Gate 2B should set the exact A02 function regular comment. | strong | `get_comments` | IDA function `0x004c64b0` / regular comment | incorporate | proposed |
| C16Q-046 | 00016Q | Supervisor Gate 2B should set the exact A02 function repeatable comment. | strong | `get_comments` | IDA function `0x004c64b0` / repeatable comment | incorporate | proposed |
| C16Q-047 | 00016Q | Supervisor Gate 2B should pure-rename `0x004c64c0` to `CachedHashTable_GetEntryCount`. | strong | `lookup_funcs` | IDA function `0x004c64c0` / name | incorporate | proposed |
| C16Q-048 | 00016Q | Supervisor Gate 2B should apply signature `int __thiscall CachedHashTable_GetEntryCount(const CachedHashTable *this)` at `0x004c64c0`. | strong | `inspect_items` | IDA function `0x004c64c0` / type | incorporate | proposed |
| C16Q-049 | 00016Q | Supervisor Gate 2B should set the exact A03 address regular comment. | strong | `get_comments` | IDA address `0x004c64c0` / regular comment | incorporate | proposed |
| C16Q-050 | 00016Q | Supervisor Gate 2B should set the exact A03 address repeatable comment. | strong | `get_comments` | IDA address `0x004c64c0` / repeatable comment | incorporate | proposed |
| C16Q-051 | 00016Q | Supervisor Gate 2B should set the exact A03 function regular comment. | strong | `get_comments` | IDA function `0x004c64c0` / regular comment | incorporate | proposed |
| C16Q-052 | 00016Q | Supervisor Gate 2B should set the exact A03 function repeatable comment. | strong | `get_comments` | IDA function `0x004c64c0` / repeatable comment | incorporate | proposed |
| C16Q-053 | 00016Q | Preserve predecessor padding `[0x004c64a7,0x004c64b0)` exactly as P01. | exact | `inspect_items` | IDA item `0x004c64a7` | already-present | proposed |
| C16Q-054 | 00016Q | Preserve internal padding `[0x004c64b4,0x004c64c0)` exactly as P02. | exact | `inspect_items` | IDA item `0x004c64b4` | already-present | proposed |
| C16Q-055 | 00016Q | Preserve successor padding `[0x004c64c4,0x004c64d0)` exactly as P03. | exact | `inspect_items` | IDA item `0x004c64c4` | already-present | proposed |
| C16Q-056 | 00016Q | Preserve raw helper `[0x004c64d0,0x004c64e1)` exactly as P04. | exact | `get_bytes` | IDA function candidate `0x004c64d0` | already-present | proposed |
| C16Q-057 | 00016Q | Preserve constructor `[0x004c6160,0x004c6259)` exactly as P05. | exact | `get_bytes` | IDA function `0x004c6160` | already-present | proposed |
| C16Q-058 | 00016Q | Preserve destructor `[0x004c6260,0x004c62ce)` exactly as P06. | exact | `get_bytes` | IDA function `0x004c6260` | already-present | proposed |
| C16Q-059 | 00016Q | Preserve scalar deleting destructor `[0x004c64f0,0x004c659c)` exactly as P07. | exact | `get_bytes` | IDA function `0x004c64f0` | already-present | proposed |
| C16Q-060 | 00016Q | Preserve vtable cell `[0x0061aac4,0x0061aac8)` exactly as P08. | exact | `inspect_items` | IDA data `0x0061aac4` | already-present | proposed |
| C16Q-061 | 00016Q | Preserve RTTI complete-object-locator head `[0x00647de8,0x00647dec)` exactly as P09. | exact | `inspect_items` | IDA data `0x00647de8` | already-present | proposed |
| C16Q-062 | 00016Q | Preserve RTTI type-descriptor head `[0x0067640c,0x00676410)` exactly as P10. | exact | `inspect_items` | IDA data `0x0067640c` | already-present | proposed |
| C16Q-063 | 00016Q | At current line 1677, replace the exact stale UID00016Q manual by-memory row (`84%`, old two-accessor summary) with the exact `94%` row in Section 28. | exact | physical manual coverage reread, SHA256 `8686AAB8ED2AFE4DAE27000C61DEE09AB57F4A6F2DC358F48AA1EEB964915211` | `by-memory/-coverage-report.md` / UID00016Q row | incorporate | proposed |
| C16Q-064 | 00016Q | Run the exact scoped validator for the target after accepted callback edits. | strong | scoped file validator | this report / Validator Results / target receipt | incorporate | applied |
| C16Q-065 | 00016Q | Run the exact scoped validator for `by-file/CachedHashTable.md` after accepted callback edits. | strong | scoped file validator | this report / Validator Results / by-file receipt | incorporate | applied |
| C16Q-066 | 00016Q | Run the exact scoped validator for `by-class/CachedHashTable.md` after accepted callback edits. | strong | scoped file validator | this report / Validator Results / by-class receipt | incorporate | applied |
| C16Q-067 | 00016Q | Run the exact scoped validator for `by-type/by-struct/CachedHashTableLayout.md` after accepted callback edits. | strong | scoped file validator | this report / Validator Results / layout receipt | incorporate | applied |
| C16Q-068 | 00016Q | After accepted ordinary changes and all four supervisor-owned manual coverage replacements validate, and after Gate 2B closes, supervisor should perform one coherent validator-owned generated refresh before lifecycle execution. | strong | ordinary/manual scoped validator receipts plus coherent refresh receipt | this report / Validator Results / pre-execution generated refresh receipt | incorporate | proposed |
| C16Q-069 | 00016Q | Before lifecycle execution, supervisor should verify the generated by-memory row is `coded`, owner `0000HZ`, emitter `0000HZ`, blank position, CPP yes, H no, destination `auto-generated/NexusTK/util/CachedHashTable.cpp`, blank header destination, and the current UID00016Q target path; this table has no score columns. | strong | generated table schema and UID00016Q row reread | `auto-generated/-ag-memory-coverage.md` / UID00016Q row | incorporate | proposed |
| C16Q-070 | 00016Q | Before lifecycle execution, supervisor should verify coherent generated readback shows UID00016Q at `94/95`, combined `94.5`, reconstructable `true`, and the current target path in the research tracker; report-count/execution columns are lifecycle-owned and are recorded as observed rather than used as this Gate 2 requirement. | strong | generated table schema and UID00016Q row reread | `auto-generated/-ag-research-tracker.md` / UID00016Q row | incorporate | proposed |
| C16Q-071 | 00016Q | Preserve `RECONSTRUCTABLE:TRUE`. | very strong | physical target reread | `by-memory/0x004c64b0-0x004c64c4.CachedHashTableCountAccessors.md` / RECONSTRUCTABLE | already-present | already-present |
| C16Q-072 | 00016Q | Preserve `EMITTER_UIDS:0000HZ`. | very strong | physical target reread | `by-memory/0x004c64b0-0x004c64c4.CachedHashTableCountAccessors.md` / EMITTER_UIDS | already-present | already-present |
| C16Q-073 | 00016Q | Raise `CONFIDENCE:91` to `95`. | strong | physical target metadata reread | `by-memory/0x004c64b0-0x004c64c4.CachedHashTableCountAccessors.md` / CONFIDENCE | incorporate | applied |
| C16Q-074 | 00016Q | Add the explicit non-virtual `GetEntryCount` method row without changing class metadata. | strong | physical by-class reread | `by-class/CachedHashTable.md` / Method Inventory / GetEntryCount | incorporate | applied |
| C16Q-075 | 00016Q | Add the child-H/whole-class declaration boundary without changing class metadata. | strong | physical by-class reread | `by-class/CachedHashTable.md` / Header Ownership | incorporate | applied |
| C16Q-076 | 00016Q | Record the current absence of a local `CachedHashTable` UDT. | exact | physical layout reread | `by-type/by-struct/CachedHashTableLayout.md` / IDA Status | incorporate | applied |
| C16Q-077 | 00016Q | State that current canonical names/types/comments require fresh Gate 2B application. | exact correction | physical target IDA-state reread | `by-memory/0x004c64b0-0x004c64c4.CachedHashTableCountAccessors.md` / Current IDA State | incorporate | applied |
| C16Q-078 | 00016Q | Supervisor should physically verify both UID00016Q definitions after coherent generated refresh. | strong | generated physical reread | `auto-generated/NexusTK/util/CachedHashTable.cpp` / UID00016Q definitions | incorporate | proposed |
| C16Q-079 | 00016Q | Supervisor should physically verify zero UID00016Q empty-emitter markers after coherent generated refresh. | strong | generated marker count | `auto-generated/NexusTK/util/CachedHashTable.cpp` / UID00016Q empty marker | incorporate | proposed |
| C16Q-080 | 0000HZ | At current line 43, replace the exact stale UID0000HZ manual by-file row (`84%`, old generic utility summary) with the exact `85%` accessor-evidence row in Section 28. | exact | physical manual coverage reread, SHA256 `5CD0F53214FEE83C7281A5C4DAFA8BBB14827C81DBDD1C154ED81CD376D49285` | `by-file/-coverage-report.md` / UID0000HZ row | incorporate | proposed |
| C16Q-081 | 00001F | At current line 77, replace the exact UID00001F manual by-class row (current `86%`, stale live-construction summary) with the exact explicit-getter/header-boundary row in Section 28. | exact | physical manual coverage reread, SHA256 `4F76F695284E20D8FE8EEFCEC6DB86429B2841DD11D71F048693F46A5A05E8B0` | `by-class/-coverage-report.md` / UID00001F row | incorporate | proposed |
| C16Q-082 | 0001TU | At current line 24, replace the exact UID0001TU manual layout row (current `85%`, stale applied-name/provisional-field summary) with the exact selected-field/current-IDA-state row in Section 28. | exact | physical manual coverage reread, SHA256 `51ACA03865C84EAA426E63CE427539F72BD7944E3B1B86B6C5AB8A9F9B9FA051` | `by-type/by-struct/-coverage-report.md` / UID0001TU row | incorporate | proposed |

## Positive Evidence Summary

- Both accessors are exact, complete, four-byte leaf methods with stable field offsets and valid formal source already emitted.
- The constructor independently writes both fields, while raw helpers use the same layout and distinguish capacity from occupancy.
- Decorated RTTI proves the class name `CachedHashTable`; the local source cluster and vtable prove class ownership even though the accessors are not virtual.
- Existing owner/emitter routing generates the two bodies in `NexusTK/util/CachedHashTable.cpp` without overlap with the blank aggregate helper page.
- The strongest inference chain is exact offset semantics -> constructor/helper distinction -> project getter style -> `GetSlotCount`/`GetEntryCount`, which is sufficient for realistic human source despite stripped lexical symbols.

## IDA MCP Facts

- Function/range facts: `0x004c64b0` and `0x004c64c0` are `sub_4C64B0` and `sub_4C64C0`, each size `0x4`; their exclusive ends are not function starts. `0x004c64d0` is an unmodeled raw helper start.
- Body facts: first body `mov eax,[ecx+10h]; retn`; second `mov eax,[ecx+14h]; retn`; both decompile as `_DWORD *this` indexed loads.
- ABI facts: current prototypes are `int __thiscall(_DWORD *this)`; stack frames contain only `__return_address`; no strings, constants, or callees.
- Data/padding facts: nine `0xcc` bytes precede the first start, twelve separate the methods, and twelve follow the second method before `0x004c64d0`.
- Xref facts: zero incoming xrefs to starts or exclusive ends; no VA/RVA pointer-pattern hits; only internal instruction-flow edges appear in bidirectional queries.
- Vtable/global/type facts: vtable base `off_61AAC4` points first to scalar deleting destructor `0x004c64f0`; RTTI names prove `CachedHashTable`; no `CachedHashTable` local UDT exists.
- Negative IDA facts: all four comment channels on both function entries are absent; padding items are unnamed/untyped; body patterns occur elsewhere and cannot alone prove identity.

## Function / Child Inventory

| Range / Item | UID / Path | Role | Reconstructable | Direct Parent | Score | Status |
| --- | --- | --- | --- | --- | --- | --- |
| `[0x004c64a7,0x004c64b0)` | predecessor padding in UID00016P context | nine-byte `0xcc` alignment | no source | UID00016P aggregate | n/a | protected outside target |
| `[0x004c64b0,0x004c64b4)` | [UID:00016Q] | `CachedHashTable::GetSlotCount() const` | TRUE | [UID:0000HZ] | proposed `94/95` target pair | exact CPP present |
| `[0x004c64b4,0x004c64c0)` | inside [UID:00016Q] | twelve-byte `0xcc` alignment | no source | UID00016Q physical pair | included | preserve |
| `[0x004c64c0,0x004c64c4)` | [UID:00016Q] | `CachedHashTable::GetEntryCount() const` | TRUE | [UID:0000HZ] | proposed `94/95` target pair | exact CPP present |
| `[0x004c64c4,0x004c64d0)` | successor padding in UID00016P context | twelve-byte `0xcc` alignment | no source | UID00016P aggregate | n/a | protected outside target |
| `[0x004c64d0,0x004c64e1)` | [UID:00016P] contained helper | `GetEntryAddressUnchecked(unsigned int)` | TRUE | [UID:0000HZ] | unchanged `86/90` aggregate | raw neighboring helper, no target edit |

Inventory totals for this assignment: two source-bearing methods, one internal padding item, two external boundary-padding items, and one protected neighboring raw helper. No string, global, vtable slot, RTTI object, or data definition belongs to the target's formal source payload.

## Direct Xref / Caller Inventory

| Address / Item | Xref / Caller / Callee | Meaning |
| --- | --- | --- |
| `0x004c64b0` start | zero incoming; one internal flow edge `0x004c64b0 -> 0x004c64b3`; zero callees | no surviving direct caller; complete leaf method |
| `0x004c64b4` exclusive end | zero incoming xrefs | no alternate entry or overlap |
| `0x004c64c0` start | zero incoming; one internal flow edge `0x004c64c0 -> 0x004c64c3`; zero callees | no surviving direct caller; complete leaf method |
| `0x004c64c4` exclusive end | zero incoming xrefs | no alternate entry or overlap |
| VA/RVA patterns for both starts | zero matches | no static pointer-table route |
| `0x0061aac4` class vtable | refs only from constructor `0x004c61a1`, destructor `0x004c6288`, scalar wrapper `0x004c651f`; slot points to `0x004c64f0` | class identity/lifecycle support; accessors are ordinary non-virtual methods |

## Documentation Evidence And IDA Status

- Supporting docs: all named support pages agree on `+0x10` slot capacity, `+0x14` active entry count, object size `0x1c`, [UID:0000HZ] source placement, and exact formal accessor bodies.
- Stale/incomplete docs: target manual coverage remains at historical `84%`; target source-name discussion remains provisional; layout history claims IDA renames were applied, but current canonical IDB does not contain them; layout field terms are not synchronized with target formal `m_` names.
- Generated state: `CachedHashTable.cpp` command `000000021763` emits exactly one UID00016Q marker and both definitions, no UID00016Q empty marker. The generated memory row is coded with CPP yes, H no, route [UID:0000HZ].
- Current IDA status: raw function names, `_DWORD *this` types, absent comments, absent `CachedHashTable` UDT. This is an actionable source-quality gap, not a reason to preserve target score.

## Ranked Ownership Analysis

### 1. [UID:0000HZ] CachedHashTable file owner

- Evidence for: exact adjacent constructor/destructor/helper/accessor cluster, source route, generated destination, utility/container documentation, and no feature-local route.
- Evidence against: no surviving direct constructor or accessor caller.
- Decision: accepted canonical owner/emitter. Liveness affects priority, not authorship.

### 2. [UID:00001F] CachedHashTable class support

- Evidence for: RTTI class identity, layout, method semantics, and class declaration responsibility.
- Evidence against: project source emission routes method definitions through the by-file owner; it is not a separate source file.
- Decision: retain as semantic/type support and future complete-H owner, not direct replacement for [UID:0000HZ].

### 3. Feature-local, no-owner, or compiler-generated alternatives

- Evidence for: absence of direct callers could superficially suggest unused code.
- Evidence against: complete source-shaped methods, constructor-managed fields, RTTI/vtable identity, coherent helper family, and valid out-of-line definitions.
- Decision: rejected. No feature owner is evidenced, and no-owner/compiler classification would lose authentic source code.

### Proposed new file/grouping, if applicable

- Proposed owner/name/path: none; keep `NexusTK/util/CachedHashTable.cpp`.
- Likely full contents: lifecycle methods, raw helper methods after exact split/assembly, and these two count accessors.
- Candidate related items that belong: current class/lifecycle/helper/layout/vtable support pages under their existing routes.
- Candidate related items rejected: neighboring HelpPane methods beginning at `0x004c65a0` and feature modules with no route.
- Standalone, narrow, or broad source-file inference: the target is a narrow paired child inside the broader utility compilation unit.

## Source Placement

- Recommended placement: out-of-line member definitions in `NexusTK/util/CachedHashTable.cpp`, emitted by [UID:0000HZ].
- Fit: the accessors read only class-owned container fields and sit physically among the class helper family. No external subsystem state appears.
- Rejected placements: class-specific standalone `CachedHashTableAccessors.cpp`, header-inline bodies, feature UI/archive files, `LObject.cpp`, and compiler-support files.
- Remaining placement uncertainty: exact original project directory capitalization and whether the original build had a sibling `CachedHashTable.h`; neither changes this target's source file route or bodies.

## Range / Split / Padding / Reclassification Analysis

- Exact target range: `[0x004c64b0,0x004c64c4)` contains two exact four-byte functions and the twelve-byte internal alignment item.
- Predecessor boundary: `[0x004c64a7,0x004c64b0)` is a separate nine-byte data item of `0xcc` bytes and is outside this target.
- Successor boundary: `[0x004c64c4,0x004c64d0)` is a separate twelve-byte data item of `0xcc` bytes before raw helper `[0x004c64d0,0x004c64e1)`.
- Decision: keep one paired target. Do not create two children, extend into padding outside the range, absorb the raw helper, or reclassify internal alignment as source.
- Parent impact: [UID:00016P] remains a blank aggregate and must not duplicate these already-emitting exact methods; [UID:00016O] remains a non-emitting split index.

## Negative Evidence Summary

- No direct code/data refs, callers, VA pointers, RVA pointers, vtable slots, callback-table entries, or endpoint entries reach either accessor.
- Exact body patterns occur in other unrelated getters, so pattern identity does not prove owner or names.
- No original symbols, PDB, local `CachedHashTable` UDT, feature resource, string, global, or caller survives to recover exact lexical spelling.
- The accessors are absent from the class vtable, proving only non-virtual dispatch, not deadness.
- No evidence supports moving ownership to a consumer or dropping the methods. Negative route evidence is recorded as retained-utility liveness context, not used to erase behaviorally exact source.

## IDA Rename / Type / Comment Recommendations

The supervisor should apply A01-A03 only after its normal verified backup/prestate checks. The report contains structured actions, not an executable transaction package.

| Row | Entity | Literal current pre-state | Proposed action | Evidence and safety constraints | Expected immediate/persistence readback |
| --- | --- | --- | --- | --- | --- |
| A01 | Local type `CachedHashTable` | `type_query` total `0`; `type_inspect` exists `false`; `search_structs` empty. `LObject` exists only as an opaque non-UDT declaration. | `declare_type` one new analysis UDT: `struct CachedHashTable { void **vftable; unsigned char *m_entries; unsigned char *m_slotState; int m_entrySize; int m_slotCount; int m_entryCount; unsigned char m_hashSeed[4]; };` | Apply only if the type remains absent. Required x86 size `0x1c`; member offsets `0x00,0x04,0x08,0x0c,0x10,0x14,0x18`. This flattened analysis UDT does not replace the final source inheritance declaration. | `type_inspect` reports one UDT of size `0x1c` with the exact members/types/offsets; no bytes, xrefs, item boundaries, functions, or existing local types change. |
| A02 | Function `[0x004c64b0,0x004c64b4)` | Name `sub_4C64B0`; type `int __thiscall(_DWORD *this)`; address regular absent; address repeatable absent; function regular absent; function repeatable absent; items `[0x4c64b0,0x4c64b3)` code and `[0x4c64b3,0x4c64b4)` `retn`; bytes `8B 41 10 C3`; zero incoming xrefs; stack contains only `__return_address` at `+0x0`, size `0x4`, type `_UNKNOWN *`. | In the literal sequence below: pure rename to `CachedHashTable_GetSlotCount`; set accepted IDA C-style signature `int __thiscall CachedHashTable_GetSlotCount(const CachedHashTable *this)`; set the four literal comment channels. | Rename dry-run first; overwrite disabled; `pure:true`; stop on error. Type only after A01 readback. The implicit ECX receiver pointee gains `const`; no ABI-bearing property may change. | Name and comments match literally; `inspect_items` normalizes the type to `int __thiscall(const CachedHashTable *this)`; decompile reads only `this->m_slotCount`; bytes/items/xrefs and the complete frame remain exact. |
| A03 | Function `[0x004c64c0,0x004c64c4)` | Name `sub_4C64C0`; type `int __thiscall(_DWORD *this)`; address regular absent; address repeatable absent; function regular absent; function repeatable absent; items `[0x4c64c0,0x4c64c3)` code and `[0x4c64c3,0x4c64c4)` `retn`; bytes `8B 41 14 C3`; zero incoming xrefs; stack contains only `__return_address` at `+0x0`, size `0x4`, type `_UNKNOWN *`. | In the literal sequence below: pure rename to `CachedHashTable_GetEntryCount`; set accepted IDA C-style signature `int __thiscall CachedHashTable_GetEntryCount(const CachedHashTable *this)`; set the four literal comment channels. | Same safety as A02. Do not infer a virtual slot or change code/layout. The implicit ECX receiver pointee gains `const`; no ABI-bearing property may change. | Name and comments match literally; `inspect_items` normalizes the type to `int __thiscall(const CachedHashTable *this)`; decompile reads only `this->m_entryCount`; bytes/items/xrefs and the complete frame remain exact. |
| P01 | Padding `[0x004c64a7,0x004c64b0)` | One data item, size 9, bytes all `CC`; name absent; type absent; regular absent; repeatable absent. | Protected no-change. | Outside target; no rename/type/comment/data conversion. | Same head/end/size/bytes/name/type/comments. |
| P02 | Padding `[0x004c64b4,0x004c64c0)` | One data item, size 12, bytes all `CC`; name absent; type absent; regular absent; repeatable absent. | Protected no-change. | Preserve internal alignment; do not turn it into code or split it. | Same head/end/size/bytes/name/type/comments. |
| P03 | Padding `[0x004c64c4,0x004c64d0)` | One data item, size 12, bytes all `CC`; name absent; type absent; regular absent; repeatable absent. | Protected no-change. | Outside target; separates accessor pair from UID00016P raw helper. | Same head/end/size/bytes/name/type/comments. |
| P04 | Raw helper start `0x004c64d0` | One-byte code head `[0x4c64d0,0x4c64d1)`, name absent, type absent, regular absent, repeatable absent; complete helper bytes begin `55 8B EC 8B 41 0C 0F AF 45 08 03 41 04 5D C2 04 00`; zero incoming xrefs. | Protected no-change in this report. | UID00016P owns the already-resolved `GetEntryAddressUnchecked(unsigned int)` helper. Do not create/rename/retype it as collateral to accessor work. | Same current item/name/type/comments/bytes/xrefs. |
| P05 | Constructor `[0x004c6160,0x004c6259)` | Name `sub_4C6160`; size `0xf9`; type `int __thiscall(int this, int, int)`; all four comment channels absent; body SHA256 `47560B2B32152BF6068A71D261247B8A5F5F6EFC79FC6F8BD6D103AFDB0E4782`; zero incoming xrefs. | Protected no-change. | It proves the layout but is outside A01-A03. No rename, type, comment, frame, byte, or boundary action is authorized. | Name/size/type/comments/body hash/xref count and frame rows remain exact. |
| P06 | Destructor `[0x004c6260,0x004c62ce)` | Name `sub_4C6260`; size `0x6e`; type `void __thiscall(LObject *this)`; all four comment channels absent; body SHA256 `CE8B55AF39B5269E62D6330FCDC05CA1AA3D1F3D3209CFFAEFFC1F00124FD57D`; zero incoming xrefs. | Protected no-change. | It is lifecycle support outside A01-A03. No rename, type, comment, frame, byte, or boundary action is authorized. | Name/size/type/comments/body hash/xref count and frame rows remain exact. |
| P07 | Scalar deleting destructor `[0x004c64f0,0x004c659c)` | Name `sub_4C64F0`; size `0xac`; type `_DWORD *__thiscall(_DWORD *Block, char)`; all four comment channels absent; body SHA256 `F12CF55D9DA70CE69F42AA544937A23360C093AD11A0FC56B755778AE9C64F91`; one incoming data xref from `0x0061aac4`. | Protected no-change. | It is the vtable target, not an accessor action. No rename, type, comment, frame, byte, or boundary action is authorized. | Name/size/type/comments/body hash and exact one-xref route remain exact. |
| P08 | Vtable cell `[0x0061aac4,0x0061aac8)` | Name `off_61AAC4`; type absent; regular absent; repeatable absent; bytes `F0 64 4C 00`; SHA256 `953CC62EE283D4E3D967A250D49503F17B65A2AFF748C050B7B8A7677C8784C4`; refs from constructor `0x004c61a1`, destructor `0x004c6288`, and scalar wrapper `0x004c651f`. | Protected no-change. | A01-A03 must not rename/retype/comment/rewrite vtable data. | Exact head/end/name/type/comments/bytes/hash and all three xrefs remain exact. |
| P09 | RTTI complete-object-locator head `[0x00647de8,0x00647dec)` | Name `??_R4CachedHashTable@@6B@`; type absent; regular comment `signature`; repeatable absent; bytes `00 00 00 00`; SHA256 `DF3F619804A92FDB4057192DC43DD748EA778ADC52BC498CE80524C014B81119`; zero incoming xrefs. | Protected no-change. | Decorated RTTI is direct identity evidence and must not be normalized or renamed. | Exact head/end/name/type/comments/bytes/hash and zero-xref count remain exact. |
| P10 | RTTI type-descriptor head `[0x0067640c,0x00676410)` | Name `??_R0?AVCachedHashTable@@@8`; type absent; regular comment `reference to RTTI's vftable`; repeatable absent; bytes `78 50 63 00`; SHA256 `D9B71275A9A7916130EA249960BD68B260E9703707A4B607501033D0ECE0675D`; incoming data xrefs from `0x00647df4` and `0x00647e18`. | Protected no-change. | Decorated RTTI is direct identity evidence and must not be normalized or renamed. | Exact head/end/name/type/comments/bytes/hash and both xrefs remain exact. |

Const-contract resolution and exact endpoint form:

- The formal C++ methods are trailing-`const` members. The public `set_type` endpoint accepts an IDA C-style function-signature string and exposes no trailing-C++-member-qualifier field. A literal declaration ending in `) const` is therefore not the accepted endpoint form.
- IDA's C type grammar can represent the same source no-mutation contract by qualifying the explicit thiscall receiver pointee. The accepted request strings are exactly `int __thiscall CachedHashTable_GetSlotCount(const CachedHashTable *this)` and `int __thiscall CachedHashTable_GetEntryCount(const CachedHashTable *this)` after A01 creates the UDT. Mutable `CachedHashTable *this` is rejected because it would discard the formal source qualifier even though it is ABI-equivalent.
- The current public schema has no read-only parse/dry-run field for `set_type`; live read-only MCP therefore rechecked the literal current types and frames but did not mutate them. Gate 2B must fail closed if either exact request is rejected or if `inspect_items` does not normalize to `int __thiscall(const CachedHashTable *this)`.
- This qualifier is type-system-only: the receiver remains one 32-bit pointer in ECX, return remains 32-bit EAX, calling convention remains `__thiscall`, explicit stack arguments remain zero, and the sole physical frame row remains `__return_address` at `+0x0`, size `0x4`, type `_UNKNOWN *`. It cannot change instructions, bytes, xrefs, function/item boundaries, control flow, or runtime behavior.

Literal public MCP operation schemas. Read-only evidence was refreshed in canonical session `supervisor-b004-uid0002ow-rollback-verify-20260810`; every operation's `database` value must be the exact canonical session selected by supervisor `runtime_attestation` immediately before Gate 2B:

- A01 `declare_type`: `{"decls":"struct CachedHashTable { void **vftable; unsigned char *m_entries; unsigned char *m_slotState; int m_entrySize; int m_slotCount; int m_entryCount; unsigned char m_hashSeed[4]; };","database":"<runtime-attested canonical session ID>"}`.
- A02 rename validation: `rename` with `{"batch":{"func":{"addr":"0x004c64b0","name":"CachedHashTable_GetSlotCount"},"stop_on_error":true,"dry_run":true,"allow_overwrite":false,"pure":true},"database":"<runtime-attested canonical session ID>"}`; apply only after an exact successful dry-run by changing only `dry_run` to `false`.
- A02 type: `set_type` with `{"edits":{"addr":"0x004c64b0","kind":"function","signature":"int __thiscall CachedHashTable_GetSlotCount(const CachedHashTable *this)"},"database":"<runtime-attested canonical session ID>"}`.
- A02 address regular: `set_address_comments` with `{"items":{"addr":"0x004c64b0","comment":"CachedHashTable::GetSlotCount entry."},"database":"<runtime-attested canonical session ID>"}`.
- A02 address repeatable: `set_address_repeatable_comments` with `{"items":{"addr":"0x004c64b0","comment":"Exact non-virtual accessor; returns m_slotCount at +0x10."},"database":"<runtime-attested canonical session ID>"}`.
- A02 function regular: `set_function_comments` with `{"items":{"addr":"0x004c64b0","comment":"Returns the configured slot capacity stored in CachedHashTable::m_slotCount at +0x10."},"database":"<runtime-attested canonical session ID>"}`.
- A02 function repeatable: `set_repeatable_comments` with `{"items":{"addr":"0x004c64b0","comment":"Source: int CachedHashTable::GetSlotCount() const."},"database":"<runtime-attested canonical session ID>"}`.
- A03 rename validation: `rename` with `{"batch":{"func":{"addr":"0x004c64c0","name":"CachedHashTable_GetEntryCount"},"stop_on_error":true,"dry_run":true,"allow_overwrite":false,"pure":true},"database":"<runtime-attested canonical session ID>"}`; apply only after an exact successful dry-run by changing only `dry_run` to `false`.
- A03 type: `set_type` with `{"edits":{"addr":"0x004c64c0","kind":"function","signature":"int __thiscall CachedHashTable_GetEntryCount(const CachedHashTable *this)"},"database":"<runtime-attested canonical session ID>"}`.
- A03 address regular: `set_address_comments` with `{"items":{"addr":"0x004c64c0","comment":"CachedHashTable::GetEntryCount entry."},"database":"<runtime-attested canonical session ID>"}`.
- A03 address repeatable: `set_address_repeatable_comments` with `{"items":{"addr":"0x004c64c0","comment":"Exact non-virtual accessor; returns m_entryCount at +0x14."},"database":"<runtime-attested canonical session ID>"}`.
- A03 function regular: `set_function_comments` with `{"items":{"addr":"0x004c64c0","comment":"Returns the number of occupied entries stored in CachedHashTable::m_entryCount at +0x14."},"database":"<runtime-attested canonical session ID>"}`.
- A03 function repeatable: `set_repeatable_comments` with `{"items":{"addr":"0x004c64c0","comment":"Source: int CachedHashTable::GetEntryCount() const."},"database":"<runtime-attested canonical session ID>"}`.

The supervisor must rerun `tools/list` and `runtime_attestation` before Gate 2B. If the canonical session ID changes, only the `database` field may be rebound to the freshly attested canonical session; every action field, pre-state, safety constraint, and expected readback remains literal.

Complete A02/A03 before/after stack-frame contract:

| Action | Row kind | Before | Allowed after | Protected result |
| --- | --- | --- | --- | --- |
| A02 | implicit receiver | ECX, `_DWORD *this`, not a stack row | ECX, `const CachedHashTable *this`, not a stack row | receiver location, pointer width, and calling convention unchanged; pointee qualification and type name only change |
| A02 | stack row | `__return_address`, offset `+0x0`, size `0x4`, type `_UNKNOWN *` | identical | exact row remains |
| A02 | row counts | explicit arguments `0`; locals `0`; saved-register rows `0`; added rows `0`; removed rows `0` | identical | no row creation, deletion, rename, offset, width, or type delta |
| A03 | implicit receiver | ECX, `_DWORD *this`, not a stack row | ECX, `const CachedHashTable *this`, not a stack row | receiver location, pointer width, and calling convention unchanged; pointee qualification and type name only change |
| A03 | stack row | `__return_address`, offset `+0x0`, size `0x4`, type `_UNKNOWN *` | identical | exact row remains |
| A03 | row counts | explicit arguments `0`; locals `0`; saved-register rows `0`; added rows `0`; removed rows `0` | identical | no row creation, deletion, rename, offset, width, or type delta |

A01 may add only the new local type. A02/A03 may change only their listed name, receiver type, and four comment channels. No action may change bytes, function/item boundaries, xrefs, globals, locals, stack rows, vtable/RTTI data, or any P01-P10 entity.

## First-Draft C++ Recommendation

- Eligible for draft C++: yes; the current target formal CPP is already the recommended human-written source and should remain exact.
- CPP block disposition: preserve this exact formal insertion text:

```cpp
int CachedHashTable::GetSlotCount() const
{
    return m_slotCount;
}

int CachedHashTable::GetEntryCount() const
{
    return m_entryCount;
}
```

- H block disposition: keep [UID:00016Q] formal H blank. These are non-inline member declarations that belong only inside the complete [UID:00001F] `CachedHashTable` class declaration. A child-owned standalone pair would be invalid header source and could duplicate a future whole-class formal H block.
- Behavior preservation: each definition compiles to a direct 32-bit field return under the x86 thiscall ABI and introduces no validation, side effect, or virtual dispatch absent from the binary.
- Source-shape rationale: conventional const getters, `m_` fields, and out-of-line definitions match the project's reconstructed mid-2000s C++ style and do not expose decompiler indexes or raw offsets.
- Inferred names/types: `int`, `GetSlotCount`, `GetEntryCount`, `m_slotCount`, and `m_entryCount` are selected high-probability source names rather than raw `sub_`/`this[4]`/`this[5]` labels.
- Third-party import directive: not applicable; this is NexusTK project code.
- Exact no-code proof: not applicable to CPP. The H blank is a routing/declaration-context decision, not a claim that the methods lack source.

## Final Recommendation

- Recommend target update to `94/95`, unchanged owner/emitter/reconstructable state, unchanged CPP, and blank H with the class-declaration reason above.
- Recommend IDA C-style pointer-to-const receiver signatures for A02/A03. They preserve the formal C++ member-`const` contract without claiming that IDA's function-type display can carry a trailing C++ member qualifier.
- Recommend current-evidence additions to the target, by-file, by-class, and layout support docs. Preserve valid historical research and explicitly correct the noncurrent IDA-rename assertion.
- Recommend supervisor-only IDA A01-A03 and protected-state P01-P10 verification.
- Recommend supervisor-only manual coverage replacement and coherent generated refresh/readback after ordinary callback validation.
- Leave UID00016P, UID00016O, and UID0001X6 unchanged because they already contain same-or-greater related context and have separate ownership/split roles.
- No open question remains that blocks score improvement, owner/emitter routing, source placement, formal CPP, or the exact IDA handoff.

## Recommended Target Doc Changes

- Target path: `by-memory/0x004c64b0-0x004c64c4.CachedHashTableCountAccessors.md`.
- Metadata: `COMPLETION:86 -> 94`, `CONFIDENCE:91 -> 95`; preserve `CANONICAL_OWNER:0000HZ`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000HZ`, and blank optional position.
- Formal CPP: preserve exact current text. Formal H: preserve blank.
- Item Summary replacement: `Source-ready paired non-virtual CachedHashTable accessors return m_slotCount at +0x10 and m_entryCount at +0x14; current live IDA confirms exact four-byte bodies, class RTTI, resolved source-facing names/types, and exhaustive no-direct-route evidence.`
- Add report-level detail for current MCP session/health, exact items and padding, ABI, current names/types/comments, zero route, nonunique body patterns, constructor field proof, RTTI/vtable context, type absence, selected source names/types, retained-utility classification, no-split decision, IDA handoff, and score rationale.
- Historical preservation: keep older body/route evidence, but label the 2026-06-16 name application as historical and superseded by current canonical readback.

## Recommended Support Doc Changes

- `by-file/CachedHashTable.md`: add the current UID00016Q exact-body/ABI/RTTI/no-route result, selected names/types, current raw IDA state, and unchanged `util/CachedHashTable.cpp` route. Keep `85/89` and file ownership unchanged.
- `by-class/CachedHashTable.md`: add explicit non-virtual method rows for `int GetSlotCount() const` and `int GetEntryCount() const`, field/name rationale, and the child-H/whole-class declaration boundary. Keep `86/88` and metadata/formal blocks unchanged.
- `by-type/by-struct/CachedHashTableLayout.md`: synchronize current source-facing field names/types to `m_entries`, `m_slotState`, `m_entrySize`, `m_slotCount`, `m_entryCount`, and `m_hashSeed[4]`; preserve older `entriesBuffer`/`slotStateBuffer` as historical descriptive aliases; record current local-UDT absence and A01 handoff. Keep `85/90` and metadata/formal blocks unchanged.
- `by-memory/0x004c62d0-0x004c64e1.CachedHashTableRawHelpers.md`, `by-memory/0x004c6160-0x004c659c.CachedHashTableLifecycle.md`, and `by-type/by-vtable/CachedHashTableVtable.md`: verified same-or-greater related detail; no ordinary edit required.
- Generated `auto-generated/NexusTK/util/CachedHashTable.cpp`: never edit directly. Verify it only after validator-owned regeneration.

## Score And Metadata Recommendation

- Research-start state: `86/91`, owner/emitter [UID:0000HZ], reconstructable true, exact CPP present, H blank.
- Current applied ordinary-doc state: `94/95`, same owner/emitter/reconstructable/position, exact CPP unchanged, H blank.
- Why higher: the pass closes current IDA-state drift, exact ABI and item topology, class proof, field/type/name decisions, range/split, retained liveness, formal H disposition, manual coverage drift, and supervisor IDA action detail.
- Why not higher: stripped original lexical spellings cannot be directly proven, no surviving caller establishes original public/private exposure, and the complete class header is broader than this child. These caps do not block exact target source.
- Score-improvement attempt:
  - Names: searched RTTI/names/types/docs/reports and selected the highest-probability names.
  - Field types: rechecked constructor and helper use, resolved byte buffers and signed count declarations.
  - Reachability: exhausted xrefs, endpoints, VA/RVA pointers, vtable, and prior PE branch scans; classified retained utility.
  - IDA state: read literal names/types/comments/type catalog and produced exact actions/protected readbacks.
  - H/source placement: inspected class/file/generated routes and selected blank child H plus file-owned CPP.
- No target metadata field remains undecided.

## Open Questions With Attempted Resolution

| Question | Evidence checked | Best supported resolution | Remaining impact |
| --- | --- | --- | --- |
| What were the accessor names? | RTTI, offsets, constructor/helper semantics, project naming, old reports | Use `GetSlotCount` and `GetEntryCount`; alternatives ranked/rejected. | lexical spelling remains inferred only; no implementation blocker |
| Are counts signed? | instructions, bounds branches, constructor args, project APIs, current formal source | Use `int` counts/returns and unsigned indexes. | none for valid-state behavior; confidence cap only |
| Was the API live? | starts/ends xrefs, pointers, body patterns, vtable, historical PE scan | No direct route survives; retain as utility/legacy source. | runtime-priority caveat only |
| Should the pair split? | exact item topology and semantic pairing | No; retain one paired exact child. | none |
| Should target H contain declarations? | target/class formal blocks and generated output | No; declarations belong inside complete class H, not a child fragment. | broader class header remains outside target |
| Can IDA preserve the source member-`const` contract? | current function types/frames, full 0x1c layout, and public `set_type` schema | Yes. The endpoint consumes an IDA C-style function signature, so A02/A03 use `const CachedHashTable *this`; trailing C++ member `const` is not the function-type form, and mutable `CachedHashTable *this` is rejected as source-incomplete. | supervisor Gate 2B must verify normalized type readback |

No unresolved question requires further B-agent investigation for this target. Direct recovery of stripped lexical spelling would require external original symbols/source that are not present, so the report uses the required high-probability human reconstruction rather than raw IDA names.

## Exact Manual Supervisor-Owned Coverage Or Tracker Text

- Inspected manual file: `by-memory/-coverage-report.md`, current line 1677, SHA256 `8686AAB8ED2AFE4DAE27000C61DEE09AB57F4A6F2DC358F48AA1EEB964915211`. The current UID00016Q row is exactly `84%` with the old two-accessor/no-direct-callers summary; it predates the target's current `94/95` metadata.
- Exact replacement in the same position:

`    - [UID:00016Q][0x004c64b0-0x004c64c4.CachedHashTableCountAccessors](by-memory/0x004c64b0-0x004c64c4.CachedHashTableCountAccessors.md) 0x004c64b0-0x004c64c4 | function-pair | CachedHashTableCountAccessors : reconstructable : 94% : strong : Source-ready paired non-virtual accessors return m_slotCount at +0x10 and m_entryCount at +0x14; current live IDA confirms exact four-byte bodies, class RTTI, resolved source-facing names/types, and exhaustive no-direct-route evidence.`

- Inspected support row: `by-file/-coverage-report.md` current line 43, SHA256 `5CD0F53214FEE83C7281A5C4DAFA8BBB14827C81DBDD1C154ED81CD376D49285`, [UID:0000HZ]. The current row is exactly `84%` with the generic utility/hash-cache summary; the path is correct, but both score and summary are stale against current by-file metadata `85/89`. Replace that one row in place with exactly:

The exact replacement row follows; the `>` quote marker is not part of the row:

> - [UID:0000HZ][CachedHashTable](by-file/CachedHashTable.md) : reconstructable : 85% : strong : `NexusTK/util/CachedHashTable.cpp` retains the source-authored utility/legacy hash table; UID00016Q now records exact getter bodies and ABI, constructor/RTTI/vtable class proof, exhaustive no-direct-route evidence, selected source names/types, and the current raw IDA prestate without changing file ownership.

- Inspected support row: `by-class/-coverage-report.md` current line 77, SHA256 `4F76F695284E20D8FE8EEFCEC6DB86429B2841DD11D71F048693F46A5A05E8B0`, [UID:00001F]. The current row is exactly `86%`; its path and score match current by-class metadata `86/88`, but the live-construction summary is stale. Replace that one row in place with exactly:

The exact replacement row follows; the `>` quote marker is not part of the row:

> - [UID:00001F][CachedHashTable](by-class/CachedHashTable.md) : reconstructable : 86% : strong : Utility hash/cache class with exact lifecycle/helper/vtable evidence, explicit non-virtual `int GetSlotCount() const` and `int GetEntryCount() const` rows, selected `m_` members, retained-utility no-route classification, and a documented child-CPP/whole-class-H declaration boundary.

- Inspected support row: `by-type/by-struct/-coverage-report.md` current line 24, SHA256 `51ACA03865C84EAA426E63CE427539F72BD7944E3B1B86B6C5AB8A9F9B9FA051`, [UID:0001TU]. The current row is exactly `85%`; its path and score match current layout metadata `85/90`, but its applied-name/provisional-field current-state summary is factually stale. Replace that one row in place with exactly:

The exact replacement row follows; the `>` quote marker is not part of the row:

> - [UID:0001TU][CachedHashTableLayout](by-type/by-struct/CachedHashTableLayout.md) : reconstructable : 85% : strong : Exact 0x1c constructor/destructor/helper/accessor layout uses `m_entries`, `m_slotState`, `m_entrySize`, `m_slotCount`, `m_entryCount`, and `m_hashSeed[4]`; older buffer aliases and the 2026-06-16 rename record are historical, while fresh canonical readback shows no local `CachedHashTable` UDT and raw accessor names pending supervisor Gate 2B.

- These are four atomic in-place replacements. No insert or delete is needed because the target row and all three support rows exist at the exact paths above.

- No manual replacement is proposed for UID00016P or UID00016O because this report does not change their metadata or paths.
- Reason B005 must not apply: all B agents are barred from `-coverage-report.md`; the supervisor owns these manual replacements and their scoped validation during pre-execution Gate 2 closure.
- Generated `-ag-*` rows must not be edited manually. Their refresh follows the scoped/coherent validator workflow.

## Follow-Up Actions

- Supervisor: perform exact Gate 1 audit on this artifact. Reject back to this same report if any literal section, claim mirror, or action prestate is deficient.
- B005 callback: C16Q-001 through C16Q-039, C16Q-064 through C16Q-067, and C16Q-071 through C16Q-077 were physically verified or applied at Rule 26 depth; all four changed ordinary docs passed scoped validation under JIT leases that were immediately released.
- Supervisor Gate 2B: independently recheck A01-A03/P01-P10 and C16Q-040 through C16Q-062 against the canonical IDB, apply only accepted actions with backup/save/readback discipline, and check supervisor rows only after exact persisted verification.
- Supervisor: after Gate 2B closes, apply and validate C16Q-063 and C16Q-080 through C16Q-082; then run the single pre-execution coherent refresh required by C16Q-068 and verify C16Q-069, C16Q-070, C16Q-078, and C16Q-079 by physically rereading generated `CachedHashTable.cpp`, memory coverage, and research tracker before any lifecycle execution.
- A-agent actions: none.
- Future B research: class-wide header/lifecycle/raw-helper completion belongs to separate assigned targets; it is not an excuse to defer this accessor pair.

## Confidence

- Recommendation confidence: very strong.
- Score confidence: strong for `94/95` under the project's evidence/quality gate.
- Exact binary confidence: effectively complete for both bodies, ABI, boundaries, offsets, and route absence.
- Inference confidence: strong for names/types/source shape because multiple independent class semantics agree.
- Remaining uncertainty: stripped lexical spelling, original access level/header layout, and historical runtime use. None changes target behavior or current owner/emitter/CPP decision.

## Validator Results

- Report-only research ran no validator. After Gate 1 acceptance, B005 ran these exact scoped callback validators from `source-3/project-documentation`:
  - Target: `python .\tools\validator.py --mode file --file by-memory/0x004c64b0-0x004c64c4.CachedHashTableCountAccessors.md --apply --queue-timeout 240`; command `000000021786`; timestamp `2026-08-10T15:32:30-04:00`; exit `0`; `ok:1`; completion/confidence updated to `94/95`; generated refresh deferred.
  - By-file: `python .\tools\validator.py --mode file --file by-file/CachedHashTable.md --apply --queue-timeout 240`; command `000000021787`; timestamp `2026-08-10T15:33:25-04:00`; exit `0`; `ok:1`; metadata unchanged; generated refresh deferred.
  - By-class: `python .\tools\validator.py --mode file --file by-class/CachedHashTable.md --apply --queue-timeout 240`; command `000000021788`; timestamp `2026-08-10T15:34:17-04:00`; exit `0`; `ok:1`; one UID link label normalized by validator; metadata unchanged; generated refresh deferred.
  - Layout: `python .\tools\validator.py --mode file --file by-type/by-struct/CachedHashTableLayout.md --apply --queue-timeout 240`; command `000000021789`; timestamp `2026-08-10T15:35:21-04:00`; exit `0`; `ok:1`; metadata unchanged; generated refresh deferred.
- Physical post-validator receipts: target SHA256 `AF4F9AF572494F5099751CD71F411B319DF71B9452679B89F3650CD0848085B3`; by-file `5ACE4F49534294D01EE710D8A8784D93172E9DA7B004E3F919957ADA9EDAD64D`; by-class `5F8A2451ED22113801234007CD92B60DF411C7CC761AF48614C4E3D6401B71D1`; layout `9D2C0666DBAB365120660D9AEA1601B6AC76BE66A94A576F8AE51B1BFF397324`.
- Same-or-greater no-edit receipts: UID00016P SHA256 `7B1307B2CAA0E3A86A7344D7815358607B2335A5BA4A5B2DC8C2C548C7C580B3`; UID00016O `FD84592E25942BA109C805D799700FD75D4088E1A9149928173223AD633EE843`; UID0001X6 `FC3D13E70C92463B799B9847D919A989BF443C838DD972CB5D4C49E5319F3379`.
- The scoped validators made normal validator-owned projected-stats updates and left generated refresh deferred. B005 did not manually edit generated files, `project-level/-auto-completion-stats.md`, or validator state. After Gate 2B and the four manual coverage replacements validate, one coherent pre-execution generated refresh/readback remains supervisor-owned under C16Q-068 through C16Q-070 and C16Q-078 through C16Q-079.
- Unresolved target-specific validator warnings/errors: none.

## Changed Files

- Modified: `by-memory/0x004c64b0-0x004c64c4.CachedHashTableCountAccessors.md`, `by-file/CachedHashTable.md`, `by-class/CachedHashTable.md`, `by-type/by-struct/CachedHashTableLayout.md`, and this report.
- Physically verified without edit: `by-memory/0x004c62d0-0x004c64e1.CachedHashTableRawHelpers.md`, `by-memory/0x004c6160-0x004c659c.CachedHashTableLifecycle.md`, and `by-type/by-vtable/CachedHashTableVtable.md`.
- Renamed: none.
- No `-coverage-report.md`, generated/tracker file, IDA database, audit/catalog, validator-state file, or lifecycle metadata was edited by B005. Validator-owned projected-stats side effects are recorded above.
- Report lifecycle boundary: execution/archive status is supervisor-owned and authoritative only from the current report path plus validator-owned status/history metadata. B005 did not run `execute_report`, a lifecycle command, or report movement.

## Implementation Tracking Checklist

Initial report-only gates:

- [x] Supervisor Gate 1 passed for accepted SHA256 `53E00928EEBD25C15C71E2F0A38BAFD923C8A9D816328EB9EA400D23453BF8D4` before this callback.
- [x] Required 33 literal headings contain target-specific content.
- [x] Live canonical IDA MCP evidence obtained and MCP remained available.
- [x] Every identified score blocker/open question was investigated to a selected resolution or exact irreducible lexical limit.
- [x] Formal CPP insertion and target-specific blank-H reason supplied.
- [x] Exact manual supervisor-owned coverage text supplied.
- [x] Zero PowerShell, Python, C#, JavaScript, batch, command, or transaction-package fences are present.

Exact claim mirror. Recomputed actor allocation: B005 owns C16Q-001 through C16Q-039, C16Q-064 through C16Q-067, and C16Q-071 through C16Q-077 (50 claims); the supervisor owns C16Q-040 through C16Q-063, C16Q-068 through C16Q-070, and C16Q-078 through C16Q-082 (32 claims). The artifact has 82 claims total: all 50 B005 rows are checked after physical destination verification, and all 32 supervisor rows remain unchecked and proposed.

| Done | Claim ID | Target UID | Claim | Confidence | Evidence | Destination doc/section | Action | Verification state |
| --- | --- | --- | --- | --- | --- | --- | --- | --- |
| [x] | C16Q-001 | 00016Q | Method `[0x004c64b0,0x004c64b4)` has exact bytes `8B 41 10 C3`. | exact | `get_bytes` | `by-memory/0x004c64b0-0x004c64c4.CachedHashTableCountAccessors.md` / Covered Ranges | incorporate | applied |
| [x] | C16Q-002 | 00016Q | Method `[0x004c64c0,0x004c64c4)` has exact bytes `8B 41 14 C3`. | exact | `get_bytes` | `by-memory/0x004c64b0-0x004c64c4.CachedHashTableCountAccessors.md` / Covered Ranges | incorporate | applied |
| [x] | C16Q-003 | 00016Q | Internal `[0x004c64b4,0x004c64c0)` is one twelve-byte `0xCC` item with name absent and type absent. | exact | `inspect_items` | `by-memory/0x004c64b0-0x004c64c4.CachedHashTableCountAccessors.md` / Range Analysis | incorporate | applied |
| [x] | C16Q-004 | 00016Q | Predecessor `[0x004c64a7,0x004c64b0)` is one nine-byte `0xCC` item with name absent and type absent outside the target. | exact | `inspect_items` | `by-memory/0x004c64b0-0x004c64c4.CachedHashTableCountAccessors.md` / Boundary Analysis | incorporate | applied |
| [x] | C16Q-005 | 00016Q | Successor `[0x004c64c4,0x004c64d0)` is one twelve-byte `0xCC` item with name absent and type absent outside the target. | exact | `inspect_items` | `by-memory/0x004c64b0-0x004c64c4.CachedHashTableCountAccessors.md` / Boundary Analysis | incorporate | applied |
| [x] | C16Q-006 | 00016Q | The first method returns `m_slotCount` from object offset `+0x10`. | exact semantics | `decompile` | `by-memory/0x004c64b0-0x004c64c4.CachedHashTableCountAccessors.md` / Behavior | incorporate | applied |
| [x] | C16Q-007 | 00016Q | The second method returns `m_entryCount` from object offset `+0x14`. | exact semantics | `decompile` | `by-memory/0x004c64b0-0x004c64c4.CachedHashTableCountAccessors.md` / Behavior | incorporate | applied |
| [x] | C16Q-008 | 00016Q | The first method is a leaf `int __thiscall` non-virtual accessor with implicit ECX receiver and only the return-address stack row. | exact ABI | `stack_frame` | `by-memory/0x004c64b0-0x004c64c4.CachedHashTableCountAccessors.md` / ABI | incorporate | applied |
| [x] | C16Q-009 | 00016Q | The second method is a leaf `int __thiscall` non-virtual accessor with implicit ECX receiver and only the return-address stack row. | exact ABI | `stack_frame` | `by-memory/0x004c64b0-0x004c64c4.CachedHashTableCountAccessors.md` / ABI | incorporate | applied |
| [x] | C16Q-010 | 00016Q | The first method start has zero incoming xrefs. | exact negative | `xrefs_to` | `by-memory/0x004c64b0-0x004c64c4.CachedHashTableCountAccessors.md` / Reachability | incorporate | applied |
| [x] | C16Q-011 | 00016Q | The second method start has zero incoming xrefs. | exact negative | `xrefs_to` | `by-memory/0x004c64b0-0x004c64c4.CachedHashTableCountAccessors.md` / Reachability | incorporate | applied |
| [x] | C16Q-012 | 00016Q | Little-endian VA/RVA searches for `0x004c64b0` found no pointer route. | exact negative | `find_bytes` | `by-memory/0x004c64b0-0x004c64c4.CachedHashTableCountAccessors.md` / Reachability History | incorporate | applied |
| [x] | C16Q-013 | 00016Q | Little-endian VA/RVA searches for `0x004c64c0` found no pointer route. | exact negative | `find_bytes` | `by-memory/0x004c64b0-0x004c64c4.CachedHashTableCountAccessors.md` / Reachability History | incorporate | applied |
| [x] | C16Q-014 | 00016Q | The accessor byte patterns are not globally unique, so class identity depends on layout/RTTI context. | exact negative | `find_bytes` | `by-memory/0x004c64b0-0x004c64c4.CachedHashTableCountAccessors.md` / Evidence Standards | incorporate | applied |
| [x] | C16Q-015 | 00016Q | Constructor `0x004c6160` proves buffers at `+0x04/+0x08`, entry size at `+0x0c`, slot count at `+0x10`, entry count at `+0x14`, and seed at `+0x18`. | exact | `analyze_function` | `by-memory/0x004c64b0-0x004c64c4.CachedHashTableCountAccessors.md` / Field Proof | incorporate | applied |
| [x] | C16Q-016 | 00016Q | RTTI complete-object-locator name `??_R4CachedHashTable@@6B@` supports the class identity. | exact | `entity_query` | `by-memory/0x004c64b0-0x004c64c4.CachedHashTableCountAccessors.md` / Class Evidence | incorporate | applied |
| [x] | C16Q-017 | 00016Q | RTTI type-descriptor name `??_R0?AVCachedHashTable@@@8` supports the class identity. | exact | `entity_query` | `by-memory/0x004c64b0-0x004c64c4.CachedHashTableCountAccessors.md` / Class Evidence | incorporate | applied |
| [x] | C16Q-018 | 00016Q | Vtable `0x0061aac4` routes only scalar deleting destructor `0x004c64f0`; the accessors are non-virtual. | exact | `xrefs_to` | `by-memory/0x004c64b0-0x004c64c4.CachedHashTableCountAccessors.md` / Virtuality Evidence | incorporate | applied |
| [x] | C16Q-019 | 00016Q | The local type catalog has no `CachedHashTable` UDT. | exact | `type_query` | `by-memory/0x004c64b0-0x004c64c4.CachedHashTableCountAccessors.md` / IDA Status | incorporate | applied |
| [x] | C16Q-020 | 00016Q | Best source fields are `m_entries`, `m_slotState`, `m_entrySize`, `m_slotCount`, `m_entryCount`, and `m_hashSeed[4]` with total size `0x1c`. | strong inference | `analyze_function` | `by-memory/0x004c64b0-0x004c64c4.CachedHashTableCountAccessors.md` / Naming | incorporate | applied |
| [x] | C16Q-021 | 00016Q | `GetSlotCount` is the highest-probability source name for the `+0x10` accessor. | strong inference | `decompile` | `by-memory/0x004c64b0-0x004c64c4.CachedHashTableCountAccessors.md` / Names | incorporate | applied |
| [x] | C16Q-022 | 00016Q | `GetEntryCount` is the highest-probability source name for the `+0x14` accessor. | strong inference | `decompile` | `by-memory/0x004c64b0-0x004c64c4.CachedHashTableCountAccessors.md` / Names | incorporate | applied |
| [x] | C16Q-023 | 00016Q | The best liveness classification is retained utility/legacy API with no surviving direct route. | very strong | `xref_query` | `by-memory/0x004c64b0-0x004c64c4.CachedHashTableCountAccessors.md` / Status And Ownership | incorporate | applied |
| [x] | C16Q-024 | 00016Q | Preserve `CANONICAL_OWNER:0000HZ`. | very strong | physical target reread | `by-memory/0x004c64b0-0x004c64c4.CachedHashTableCountAccessors.md` / CANONICAL_OWNER | already-present | already-present |
| [x] | C16Q-025 | 00016Q | Final source placement remains `NexusTK/util/CachedHashTable.cpp` through [UID:0000HZ]. | very strong | physical source-route reread | `by-memory/0x004c64b0-0x004c64c4.CachedHashTableCountAccessors.md` / Source Placement | incorporate | applied |
| [x] | C16Q-026 | 00016Q | Keep the paired range intact with no split, merge, extension, reclassification, or new child. | strong | `inspect_items` | `by-memory/0x004c64b0-0x004c64c4.CachedHashTableCountAccessors.md` / Range And Split | already-present | already-present |
| [x] | C16Q-027 | 00016Q | Preserve the existing formal CPP containing the two out-of-line `int` const accessor definitions. | very strong | physical target CPP reread | `by-memory/0x004c64b0-0x004c64c4.CachedHashTableCountAccessors.md` / RECONSTRUCTION_CPP CODE | already-present | already-present |
| [x] | C16Q-028 | 00016Q | Preserve the target formal H as blank because declarations belong in the complete class declaration. | strong | physical target H reread | `by-memory/0x004c64b0-0x004c64c4.CachedHashTableCountAccessors.md` / RECONSTRUCTION_H CODE | already-present | already-present |
| [x] | C16Q-029 | 00016Q | Raise `COMPLETION:86` to `94`. | strong | physical target metadata reread | `by-memory/0x004c64b0-0x004c64c4.CachedHashTableCountAccessors.md` / COMPLETION | incorporate | applied |
| [x] | C16Q-030 | 00016Q | Replace the target Item Summary with the exact source-ready summary in Section 24. | very strong | physical target Item Summary reread | `by-memory/0x004c64b0-0x004c64c4.CachedHashTableCountAccessors.md` / Item Summary | incorporate | applied |
| [x] | C16Q-031 | 00016Q | Add the exact current canonical function-name/type/comment prestate without pruning older valid facts. | very strong | physical target IDA-state reread | `by-memory/0x004c64b0-0x004c64c4.CachedHashTableCountAccessors.md` / IDA Status | incorporate | applied |
| [x] | C16Q-032 | 00016Q | Add current accessor body/ABI/RTTI/no-route/name/type evidence without changing file metadata. | strong | physical by-file reread | `by-file/CachedHashTable.md` / UID00016Q Evidence | incorporate | applied |
| [x] | C16Q-033 | 00016Q | Add the explicit non-virtual `GetSlotCount` method row without changing class metadata. | strong | physical by-class reread | `by-class/CachedHashTable.md` / Method Inventory / GetSlotCount | incorporate | applied |
| [x] | C16Q-034 | 00016Q | Synchronize source-facing field names/types to the selected `m_` field set without changing layout metadata. | strong | physical layout reread | `by-type/by-struct/CachedHashTableLayout.md` / Naming | incorporate | applied |
| [x] | C16Q-035 | 00016Q | Retain `entriesBuffer` and `slotStateBuffer` only as historical descriptive aliases. | strong | physical layout reread | `by-type/by-struct/CachedHashTableLayout.md` / Historical Changes | historicalize | applied |
| [x] | C16Q-036 | 00016Q | UID00016P already contains same-or-greater raw-helper context and needs no ordinary edit for this target. | strong | physical raw-helper doc reread | `by-memory/0x004c62d0-0x004c64e1.CachedHashTableRawHelpers.md` / current body | already-present | already-present |
| [x] | C16Q-037 | 00016Q | UID00016O already contains same-or-greater lifecycle context and needs no ordinary edit for this target. | strong | physical lifecycle doc reread | `by-memory/0x004c6160-0x004c659c.CachedHashTableLifecycle.md` / current body | already-present | already-present |
| [x] | C16Q-038 | 00016Q | UID0001X6 already contains same-or-greater vtable context and needs no ordinary edit for this target. | strong | physical vtable doc reread | `by-type/by-vtable/CachedHashTableVtable.md` / current body | already-present | already-present |
| [x] | C16Q-039 | 00016Q | Preserve the 2026-06-16 rename record only as superseded history. | exact correction | physical target history reread | `by-memory/0x004c64b0-0x004c64c4.CachedHashTableCountAccessors.md` / Historical IDA State | historicalize | applied |
| [ ] | C16Q-040 | 00016Q | Supervisor Gate 2B should declare the exact `CachedHashTable` 0x1c analysis UDT from A01. | strong | `type_inspect` | IDA local type `CachedHashTable` | incorporate | proposed |
| [ ] | C16Q-041 | 00016Q | Supervisor Gate 2B should pure-rename `0x004c64b0` to `CachedHashTable_GetSlotCount`. | strong | `lookup_funcs` | IDA function `0x004c64b0` / name | incorporate | proposed |
| [ ] | C16Q-042 | 00016Q | Supervisor Gate 2B should apply signature `int __thiscall CachedHashTable_GetSlotCount(const CachedHashTable *this)` at `0x004c64b0`. | strong | `inspect_items` | IDA function `0x004c64b0` / type | incorporate | proposed |
| [ ] | C16Q-043 | 00016Q | Supervisor Gate 2B should set the exact A02 address regular comment. | strong | `get_comments` | IDA address `0x004c64b0` / regular comment | incorporate | proposed |
| [ ] | C16Q-044 | 00016Q | Supervisor Gate 2B should set the exact A02 address repeatable comment. | strong | `get_comments` | IDA address `0x004c64b0` / repeatable comment | incorporate | proposed |
| [ ] | C16Q-045 | 00016Q | Supervisor Gate 2B should set the exact A02 function regular comment. | strong | `get_comments` | IDA function `0x004c64b0` / regular comment | incorporate | proposed |
| [ ] | C16Q-046 | 00016Q | Supervisor Gate 2B should set the exact A02 function repeatable comment. | strong | `get_comments` | IDA function `0x004c64b0` / repeatable comment | incorporate | proposed |
| [ ] | C16Q-047 | 00016Q | Supervisor Gate 2B should pure-rename `0x004c64c0` to `CachedHashTable_GetEntryCount`. | strong | `lookup_funcs` | IDA function `0x004c64c0` / name | incorporate | proposed |
| [ ] | C16Q-048 | 00016Q | Supervisor Gate 2B should apply signature `int __thiscall CachedHashTable_GetEntryCount(const CachedHashTable *this)` at `0x004c64c0`. | strong | `inspect_items` | IDA function `0x004c64c0` / type | incorporate | proposed |
| [ ] | C16Q-049 | 00016Q | Supervisor Gate 2B should set the exact A03 address regular comment. | strong | `get_comments` | IDA address `0x004c64c0` / regular comment | incorporate | proposed |
| [ ] | C16Q-050 | 00016Q | Supervisor Gate 2B should set the exact A03 address repeatable comment. | strong | `get_comments` | IDA address `0x004c64c0` / repeatable comment | incorporate | proposed |
| [ ] | C16Q-051 | 00016Q | Supervisor Gate 2B should set the exact A03 function regular comment. | strong | `get_comments` | IDA function `0x004c64c0` / regular comment | incorporate | proposed |
| [ ] | C16Q-052 | 00016Q | Supervisor Gate 2B should set the exact A03 function repeatable comment. | strong | `get_comments` | IDA function `0x004c64c0` / repeatable comment | incorporate | proposed |
| [ ] | C16Q-053 | 00016Q | Preserve predecessor padding `[0x004c64a7,0x004c64b0)` exactly as P01. | exact | `inspect_items` | IDA item `0x004c64a7` | already-present | proposed |
| [ ] | C16Q-054 | 00016Q | Preserve internal padding `[0x004c64b4,0x004c64c0)` exactly as P02. | exact | `inspect_items` | IDA item `0x004c64b4` | already-present | proposed |
| [ ] | C16Q-055 | 00016Q | Preserve successor padding `[0x004c64c4,0x004c64d0)` exactly as P03. | exact | `inspect_items` | IDA item `0x004c64c4` | already-present | proposed |
| [ ] | C16Q-056 | 00016Q | Preserve raw helper `[0x004c64d0,0x004c64e1)` exactly as P04. | exact | `get_bytes` | IDA function candidate `0x004c64d0` | already-present | proposed |
| [ ] | C16Q-057 | 00016Q | Preserve constructor `[0x004c6160,0x004c6259)` exactly as P05. | exact | `get_bytes` | IDA function `0x004c6160` | already-present | proposed |
| [ ] | C16Q-058 | 00016Q | Preserve destructor `[0x004c6260,0x004c62ce)` exactly as P06. | exact | `get_bytes` | IDA function `0x004c6260` | already-present | proposed |
| [ ] | C16Q-059 | 00016Q | Preserve scalar deleting destructor `[0x004c64f0,0x004c659c)` exactly as P07. | exact | `get_bytes` | IDA function `0x004c64f0` | already-present | proposed |
| [ ] | C16Q-060 | 00016Q | Preserve vtable cell `[0x0061aac4,0x0061aac8)` exactly as P08. | exact | `inspect_items` | IDA data `0x0061aac4` | already-present | proposed |
| [ ] | C16Q-061 | 00016Q | Preserve RTTI complete-object-locator head `[0x00647de8,0x00647dec)` exactly as P09. | exact | `inspect_items` | IDA data `0x00647de8` | already-present | proposed |
| [ ] | C16Q-062 | 00016Q | Preserve RTTI type-descriptor head `[0x0067640c,0x00676410)` exactly as P10. | exact | `inspect_items` | IDA data `0x0067640c` | already-present | proposed |
| [ ] | C16Q-063 | 00016Q | At current line 1677, replace the exact stale UID00016Q manual by-memory row (`84%`, old two-accessor summary) with the exact `94%` row in Section 28. | exact | physical manual coverage reread, SHA256 `8686AAB8ED2AFE4DAE27000C61DEE09AB57F4A6F2DC358F48AA1EEB964915211` | `by-memory/-coverage-report.md` / UID00016Q row | incorporate | proposed |
| [x] | C16Q-064 | 00016Q | Run the exact scoped validator for the target after accepted callback edits. | strong | scoped file validator | this report / Validator Results / target receipt | incorporate | applied |
| [x] | C16Q-065 | 00016Q | Run the exact scoped validator for `by-file/CachedHashTable.md` after accepted callback edits. | strong | scoped file validator | this report / Validator Results / by-file receipt | incorporate | applied |
| [x] | C16Q-066 | 00016Q | Run the exact scoped validator for `by-class/CachedHashTable.md` after accepted callback edits. | strong | scoped file validator | this report / Validator Results / by-class receipt | incorporate | applied |
| [x] | C16Q-067 | 00016Q | Run the exact scoped validator for `by-type/by-struct/CachedHashTableLayout.md` after accepted callback edits. | strong | scoped file validator | this report / Validator Results / layout receipt | incorporate | applied |
| [ ] | C16Q-068 | 00016Q | After accepted ordinary changes and all four supervisor-owned manual coverage replacements validate, and after Gate 2B closes, supervisor should perform one coherent validator-owned generated refresh before lifecycle execution. | strong | ordinary/manual scoped validator receipts plus coherent refresh receipt | this report / Validator Results / pre-execution generated refresh receipt | incorporate | proposed |
| [ ] | C16Q-069 | 00016Q | Before lifecycle execution, supervisor should verify the generated by-memory row is `coded`, owner `0000HZ`, emitter `0000HZ`, blank position, CPP yes, H no, destination `auto-generated/NexusTK/util/CachedHashTable.cpp`, blank header destination, and the current UID00016Q target path; this table has no score columns. | strong | generated table schema and UID00016Q row reread | `auto-generated/-ag-memory-coverage.md` / UID00016Q row | incorporate | proposed |
| [ ] | C16Q-070 | 00016Q | Before lifecycle execution, supervisor should verify coherent generated readback shows UID00016Q at `94/95`, combined `94.5`, reconstructable `true`, and the current target path in the research tracker; report-count/execution columns are lifecycle-owned and are recorded as observed rather than used as this Gate 2 requirement. | strong | generated table schema and UID00016Q row reread | `auto-generated/-ag-research-tracker.md` / UID00016Q row | incorporate | proposed |
| [x] | C16Q-071 | 00016Q | Preserve `RECONSTRUCTABLE:TRUE`. | very strong | physical target reread | `by-memory/0x004c64b0-0x004c64c4.CachedHashTableCountAccessors.md` / RECONSTRUCTABLE | already-present | already-present |
| [x] | C16Q-072 | 00016Q | Preserve `EMITTER_UIDS:0000HZ`. | very strong | physical target reread | `by-memory/0x004c64b0-0x004c64c4.CachedHashTableCountAccessors.md` / EMITTER_UIDS | already-present | already-present |
| [x] | C16Q-073 | 00016Q | Raise `CONFIDENCE:91` to `95`. | strong | physical target metadata reread | `by-memory/0x004c64b0-0x004c64c4.CachedHashTableCountAccessors.md` / CONFIDENCE | incorporate | applied |
| [x] | C16Q-074 | 00016Q | Add the explicit non-virtual `GetEntryCount` method row without changing class metadata. | strong | physical by-class reread | `by-class/CachedHashTable.md` / Method Inventory / GetEntryCount | incorporate | applied |
| [x] | C16Q-075 | 00016Q | Add the child-H/whole-class declaration boundary without changing class metadata. | strong | physical by-class reread | `by-class/CachedHashTable.md` / Header Ownership | incorporate | applied |
| [x] | C16Q-076 | 00016Q | Record the current absence of a local `CachedHashTable` UDT. | exact | physical layout reread | `by-type/by-struct/CachedHashTableLayout.md` / IDA Status | incorporate | applied |
| [x] | C16Q-077 | 00016Q | State that current canonical names/types/comments require fresh Gate 2B application. | exact correction | physical target IDA-state reread | `by-memory/0x004c64b0-0x004c64c4.CachedHashTableCountAccessors.md` / Current IDA State | incorporate | applied |
| [ ] | C16Q-078 | 00016Q | Supervisor should physically verify both UID00016Q definitions after coherent generated refresh. | strong | generated physical reread | `auto-generated/NexusTK/util/CachedHashTable.cpp` / UID00016Q definitions | incorporate | proposed |
| [ ] | C16Q-079 | 00016Q | Supervisor should physically verify zero UID00016Q empty-emitter markers after coherent generated refresh. | strong | generated marker count | `auto-generated/NexusTK/util/CachedHashTable.cpp` / UID00016Q empty marker | incorporate | proposed |
| [ ] | C16Q-080 | 0000HZ | At current line 43, replace the exact stale UID0000HZ manual by-file row (`84%`, old generic utility summary) with the exact `85%` accessor-evidence row in Section 28. | exact | physical manual coverage reread, SHA256 `5CD0F53214FEE83C7281A5C4DAFA8BBB14827C81DBDD1C154ED81CD376D49285` | `by-file/-coverage-report.md` / UID0000HZ row | incorporate | proposed |
| [ ] | C16Q-081 | 00001F | At current line 77, replace the exact UID00001F manual by-class row (current `86%`, stale live-construction summary) with the exact explicit-getter/header-boundary row in Section 28. | exact | physical manual coverage reread, SHA256 `4F76F695284E20D8FE8EEFCEC6DB86429B2841DD11D71F048693F46A5A05E8B0` | `by-class/-coverage-report.md` / UID00001F row | incorporate | proposed |
| [ ] | C16Q-082 | 0001TU | At current line 24, replace the exact UID0001TU manual layout row (current `85%`, stale applied-name/provisional-field summary) with the exact selected-field/current-IDA-state row in Section 28. | exact | physical manual coverage reread, SHA256 `51ACA03865C84EAA426E63CE427539F72BD7944E3B1B86B6C5AB8A9F9B9FA051` | `by-type/by-struct/-coverage-report.md` / UID0001TU row | incorporate | proposed |

Implementation callback gates remain supervisor-controlled:

- [x] Report accepted by supervisor for implementation at the exact pre-callback SHA recorded above.
- [x] All accepted ordinary target/support claims incorporated at report-level detail.
- [x] Claim ledger and exact claim mirror updated truthfully with physical destination receipts.
- [ ] Supervisor-owned IDA actions applied and persisted readback verified.
- [x] Metadata/score/CPP/H changes applied exactly as accepted.
- [x] Historical evidence and rejected alternatives preserved.
- [x] Scoped validators run for every changed ordinary doc.
- [ ] Generated output and manual coverage updated and read back by the supervisor.
- [x] Report body is lifecycle-neutral and B005 did not execute or move the report.

READY_FOR_SUPERVISOR_GATE1_REVIEW

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B005","command_id":"000000021880","destination_path":"executed-b-agent-research/B005/00016Q-CachedHashTableCountAccessors-source-quality.md","details":"report executed into central archive","event":"executed","source_path":"tools/leaser/Agents/Agent-B005/research/00016Q-CachedHashTableCountAccessors-source-quality.md","timestamp":"2026-08-11T10:00:12-04:00","uid":"00016Q"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
