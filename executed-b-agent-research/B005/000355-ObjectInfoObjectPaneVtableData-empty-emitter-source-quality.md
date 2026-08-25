** TARGET-REPORT-UID:000355 **
** AUTHOR-AGENT-ID:B005 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **

# 000355 ObjectInfoObjectPaneVtableData Empty-Emitter Source-Quality Report

Assignment: `B005-report-000355-ObjectInfoObjectPaneVtableData-empty-emitter-source-quality-20260628`

Mode: report-only research. No leases, target/support by-* edits, generated-file edits, project-level generated edits, manual coverage edits, validator/tool-state edits, subagents, IDA DB edits, or IDA process management were performed.

Target: [UID:000355] `by-memory/0x0062089c-0x00620950.ObjectInfoObjectPaneVtableData.md`

## Executive Conclusion

[UID:000355] is an exact `0xb4` / 180-byte compiler-emitted RTTI/vtable child for [UID:00009P] `ObjectInfoObjectPane`. Current IDA MCP evidence confirms the half-open range starts at the `ObjectInfoObjectPane` complete-object RTTI pointer dword `0x0062089c`, contains primary and adjusted vtable views at `0x006208a0`, `0x00620918`, and `0x00620948`, and ends exactly before the `Motion` RTTI pointer dword at `0x00620950`.

The owner/emitter route is correct. The remaining source-quality issue is the blank formal C++ block, which currently surfaces in generated output as an `Empty Emitter Marker`. The correct implementation is a marker-only formal C++ block through the class declaration/source route, not raw RTTI/vtable arrays and not a new executable body.

| Field | Current target | Recommended |
| --- | --- | --- |
| `COMPLETION` | `88` | `88` |
| `CONFIDENCE` | `92` | `92` |
| `CANONICAL_OWNER` | `00009P` | `00009P` |
| `RECONSTRUCTABLE` | `TRUE` | `TRUE` |
| `EMITTER_UIDS` | `00009P` | `00009P` |
| `EMITTER_POSITION_OPTIONAL` | blank | blank |
| Formal `RECONSTRUCTION_CPP CODE` | blank | insert exact marker below |

Exact formal `RECONSTRUCTION_CPP CODE` insertion text for [UID:000355]:

```cpp
// Compiler-emitted RTTI/vtable data for ObjectInfoObjectPane is regenerated from
// [UID:00009P] ObjectInfoObjectPane class declarations, virtual method definitions,
// destructor wrappers, and the [UID:0000HJ] AttachedObjectPane.cpp source module.
// No raw vtable or RTTI dword tables are hand-authored for this .rdata range.
```

Keep the inline `RECONSTRUCTION_CPP CODE:[[[]]]` header value blank and insert the marker between the multiline `RECONSTRUCTION_CPP CODE:BEGIN` / `END` lines.

## Files And Evidence Read

Workflow/rules:

- `.codex/skills/ntk-b-agent-workflow/SKILL.md`
- `.codex/skills/ntk-b-agent-workflow/references/b-agent-research-and-implementation-workflow.md`
- `.codex/skills/ntk-b-agent-workflow/references/supervisor-rule26-review-and-incorporation-standard.md`
- `tools/leaser/Agents/Agent-B005/goal.md`
- `by-structure.md`
- `tools/int_convert_readme.md`
- `by-memory/-guidance.md`, `by-type/-guidance.md`, and `by-type/by-vtable/-guidance.md`

Target/support docs:

- `by-memory/0x0062089c-0x00620950.ObjectInfoObjectPaneVtableData.md`
- `by-class/ObjectInfoObjectPane.md`
- `by-file/AttachedObjectPane.md`
- `by-memory/0x00620284-0x00620c74.ObjectPaneReadOnlyData.md`
- `by-memory/0x00538bc0-0x00539bb2.ObjectOverlayPanes.md`
- `by-memory/0x0053d620-0x0053d65b.ObjectInfoObjectPaneScalarDeletingDestructor.md`
- Neighbor vtable children [UID:000354] `DamageNumberObjectPaneVtableData` and [UID:000356] `MotionVtableData`

Read-only generated state:

- `auto-generated/NexusTK/map/AttachedObjectPane.cpp`
- `auto-generated/-ag-research-tracker.md`
- `auto-generated/-ag-coverage-report-by-memory.md`

## Current Target State

The source by-memory page already has the right structural route but stale generated/formal state:

- Header is `88/92`, owner/emitter [UID:00009P], `RECONSTRUCTABLE:TRUE`, blank formal C++.
- Body correctly classifies the item as `source-declared/generated-binary` RTTI/vtable data regenerated from class source.
- Body already records that the class parent [UID:00009P] is `85/89` and the source file [UID:0000HJ] is `86/86`, so the strict gate is satisfied.
- Header `Item Summary` is stale: it still says the parent is blank because the direct class parent is `82/88`.
- Current generated `auto-generated/NexusTK/map/AttachedObjectPane.cpp` line 45 still shows `UID:000355 ... Completion:85 | Confidence:88 | Empty Emitter Marker`.
- Generated `-ag-research-tracker.md` and `-ag-coverage-report-by-memory.md` also still show stale `85/88` / empty-emitter state. These files must refresh through validator/generator flow only.

## Current MCP Session

IDA MCP was available and used. This report is not fallback-only.

| Evidence | Result |
| --- | --- |
| Endpoint | `http://127.0.0.1:13337/mcp` |
| Active session | `agent_b009_0002my_20260628` |
| IDB path | `E:\NTK\Resources\NexusTK\NexusTK.exe.i64` |
| Worker state | `backend:"worker"`, `owned:true`, `adopted:true`, `pid:2412`, `worker_pid:2412`, `is_active:true`, `is_analyzing:false` |
| `server_health` | `status:"ok"`, module `NexusTK.exe`, input path `C:\Users\admin\Desktop\Clone\NexusTK\NexusTK.exe`, imagebase `0x400000`, auto-analysis ready, Hex-Rays ready, strings cache ready, string cache size `2067` |

Read-only MCP tools used: `idb_list`, `server_health`, `entity_query`, `get_bytes`, `get_int`, `xrefs_to`, `lookup_funcs`, `analyze_function`, `disasm`, and `int_convert`.

## Live MCP Range Evidence

`entity_query` over `0x006207e0-0x00620960` reports the expected vtable-base sequence around the target:

| Address | Name | Segment |
| --- | --- | --- |
| `0x006207ec` | `??_7DamageNumberObjectPane@@6B@` | `.rdata` |
| `0x00620864` | `??_7DamageNumberObjectPane@@6B@_0` | `.rdata` |
| `0x00620894` | `??_7DamageNumberObjectPane@@6B@_1` | `.rdata` |
| `0x006208a0` | `??_7ObjectInfoObjectPane@@6B@` | `.rdata` |
| `0x00620918` | `??_7ObjectInfoObjectPane@@6B@_0` | `.rdata` |
| `0x00620948` | `??_7ObjectInfoObjectPane@@6B@_1` | `.rdata` |
| `0x00620954` | `??_7Motion@@6B@` | `.rdata` |

`entity_query` over the RTTI target area confirms the pointed RTTI records:

| Address | Name |
| --- | --- |
| `0x0064d3a8` | `??_R4ObjectInfoObjectPane@@6B@` |
| `0x0064d3bc` | `??_R3ObjectInfoObjectPane@@8` |
| `0x0064d3cc` | `??_R2ObjectInfoObjectPane@@8` |
| `0x0064d3f0` | `??_R1A@?0A@EA@ObjectInfoObjectPane@@8` |
| `0x0064d40c` | `??_R4ObjectInfoObjectPane@@6B@_0` |
| `0x0064d420` | `??_R4ObjectInfoObjectPane@@6B@_1` |
| `0x0064cd00` | successor `??_R4Motion@@6B@` |

`get_bytes` for `0x0062089c` size `180` starts with `a8 d3 64 00 20 d6 53 00`, meaning the target starts at the ObjectInfo RTTI pointer `0x0064d3a8` and primary slot `0x0053d620`. `get_bytes` for `0x00620950` starts with `00 cd 64 00 90 d5 53 00`, proving the successor starts at Motion RTTI `0x0064cd00` and Motion primary slot `0x0053d590`.

`int_convert` with explicit sizes confirms:

| Hex | Decimal | Use |
| --- | ---: | --- |
| `0xb4` | 180 | full target range length |
| `0x78` | 120 | primary RTTI plus primary view span `0x0062089c-0x00620914` |
| `0x30` | 48 | first adjusted RTTI plus view span `0x00620914-0x00620944` |
| `0x0c` | 12 | final adjusted RTTI plus two-slot view span `0x00620944-0x00620950` |
| `0xa0` | 160 | first adjusted this offset |
| `0xa4` | 164 | second adjusted this offset |

## Dword And Slot Evidence

Representative `get_int u32le` values:

| Table address | Dword value | Meaning |
| --- | --- | --- |
| `0x0062089c` | `0x0064d3a8` | complete-object RTTI locator pointer |
| `0x006208a0` | `0x0053d620` | primary slot 0, scalar deleting destructor |
| `0x006208f0` | `0x00539760` | `ObjectInfoObjectPane` tooltip-rect override slot |
| `0x006208fc` | `0x005398e0` | `ObjectInfoObjectPane` draw-tooltip override slot |
| `0x0062090c` | `0x00539b20` | `ObjectInfoObjectPane` directional-position override slot |
| `0x00620910` | `0x00539700` | `ObjectInfoObjectPane` update-position override slot |
| `0x00620914` | `0x0064d40c` | first adjusted RTTI locator pointer |
| `0x00620918` | `0x0053cf5c` | first adjusted slot 0, `this-0xa0` thunk to scalar deleting destructor |
| `0x00620944` | `0x0064d420` | second adjusted RTTI locator pointer |
| `0x00620948` | `0x0053cf67` | second adjusted slot 0, `this-0xa4` thunk to scalar deleting destructor |
| `0x0062094c` | `0x005386a0` | second adjusted owner/release support slot |
| `0x00620950` | `0x0064cd00` | successor `Motion` RTTI locator pointer, excluded |
| `0x00620954` | `0x0053d590` | successor `Motion` primary slot, excluded |

`lookup_funcs` confirms the relevant function targets:

| Address | Function | Size |
| --- | --- | --- |
| `0x005395b0` | `sub_5395B0` constructor | `0x96` / 150 |
| `0x00539700` | `sub_539700` update-position override | `0x5b` / 91 |
| `0x00539760` | `sub_539760` tooltip-rect override | `0x17e` / 382 |
| `0x005398e0` | `sub_5398E0` draw-tooltip override | `0x240` / 576 |
| `0x00539b20` | `sub_539B20` directional-position override | `0x92` / 146 |
| `0x0053d620` | `sub_53D620` scalar deleting destructor | `0x3b` / 59 |
| `0x0053cf5c` | `sub_53CF5C` adjusted destructor thunk | `0x0b` / 11 |
| `0x0053cf67` | `sub_53CF67` adjusted destructor thunk | `0x0b` / 11 |
| `0x00538100` | `sub_538100` attached-base cleanup | `0x1f8` / 504 |
| `0x004f4ac0` | `sub_4F4AC0` generic/free helper | `0x40` / 64 |

## Xrefs, Vptr Stores, And Thunks

`xrefs_to` for the three ObjectInfo vtable bases reports one constructor data xref each:

| Vtable base | Xrefs |
| --- | --- |
| `0x006208a0` | `0x005395df` inside constructor `sub_5395B0` |
| `0x00620918` | `0x005395e5` inside constructor `sub_5395B0` |
| `0x00620948` | `0x005395ef` inside constructor `sub_5395B0` |

The RTTI pointer dwords `0x0062089c`, `0x00620914`, `0x00620944`, and successor boundary `0x00620950` have no direct xrefs as addresses. That is expected for MSVC RTTI locator pointer dwords and does not weaken the table classification.

`analyze_function` for constructor `0x005395b0` confirms the three vptr writes:

```text
5395df  mov dword ptr [edi], offset ??_7ObjectInfoObjectPane@@6B@
5395e5  mov dword ptr [edi+0A0h], offset ??_7ObjectInfoObjectPane@@6B@_0
5395ef  mov dword ptr [edi+0A4h], offset ??_7ObjectInfoObjectPane@@6B@_1
```

The scalar deleting destructor and adjustor thunks are slot targets, not separate vtable emitters:

- `sub_53D620` calls `sub_538100` at `0x0053d626` and `sub_4F4AC0` at `0x0053d637`; current MCP did not show a destructor-side vptr restore for this class.
- `sub_53CF5C` is a two-instruction adjusted thunk: `sub ecx, 0A0h; jmp sub_53D620`.
- `sub_53CF67` is a two-instruction adjusted thunk: `sub ecx, 0A4h; jmp sub_53D620`.

`xrefs_to` for representative slot targets confirms the table ties:

| Slot target | Data/code refs |
| --- | --- |
| `0x0053d620` | data ref from `0x006208a0`; code refs from thunks at `0x0053cf62` and `0x0053cf6d` |
| `0x00539760` | data ref from `0x006208f0` |
| `0x005398e0` | data ref from `0x006208fc` |
| `0x00539b20` | data ref from `0x0062090c` |
| `0x00539700` | data ref from `0x00620910` |
| `0x0053cf5c` | data ref from `0x00620918` |
| `0x0053cf67` | data ref from `0x00620948` |

## Positive Evidence

- The target is an exact `.rdata` RTTI/vtable child, not executable code and not a hand-authored source table.
- The start dword points to `??_R4ObjectInfoObjectPane@@6B@`; the successor dword points to `??_R4Motion@@6B@`.
- The range contains one primary view and two adjusted views for the same class family.
- The constructor writes the three vtable bases to `this`, `this+0xa0`, and `this+0xa4`, proving the views are generated from the class inheritance/layout shape.
- Primary slots include the documented ObjectInfo-specific virtuals at `0x00539760`, `0x005398e0`, `0x00539b20`, and `0x00539700`.
- Adjusted first slots target `this`-adjustor thunks that jump to the same scalar deleting destructor.
- Direct class parent [UID:00009P] and file root [UID:0000HJ] both clear the strict gate in current source docs.
- Generated tracker/coverage rows are stale relative to the source by-memory page and should refresh after implementation validation.

## Negative / Counter-Evidence

- There is no evidence for manually emitted C++ arrays of RTTI records, vtable dwords, function pointers, or raw `.rdata` bytes.
- There is no evidence that [UID:000260] `ObjectPaneReadOnlyData` should own or emit this exact child; that page is a mixed non-emitting aggregate.
- There is no evidence that [UID:0000HJ] should bypass [UID:00009P] as the direct owner. The vtable is emitted from the class declaration and virtual methods, then routed through the file source module.
- There is no evidence for splitting this target at `0x006208a0`, `0x00620914`, `0x00620918`, `0x00620944`, or `0x00620948`; those are internal views in one class RTTI/vtable family.
- The lack of direct xrefs to RTTI boundary dwords is expected and does not justify a blank formal block.
- The scalar deleting destructor and two adjusted thunks are already separate executable targets or slot targets; they do not justify hand-authoring the vtable data.
- A rare blank no-code proof is not appropriate here because the target is reconstructable, has a valid emitter route, has high enough score, and the source disposition can be represented by a formal no-raw-vtable marker.

## Heuristic / Inference Reanalysis

Best source disposition: `source-declared/generated-binary` with marker-only source coverage through [UID:00009P] `ObjectInfoObjectPane`.

The human-authored source that regenerates this range is the `ObjectInfoObjectPane` class declaration, virtual method definitions, destructor wrappers, and source module relationship under [UID:0000HJ] `AttachedObjectPane.cpp`. The formal C++ block should therefore document source coverage without pretending this `.rdata` child has a standalone source body.

Rejected alternatives:

- Raw vtable/RTTI array: rejected because it is reverse-engineering scaffolding, not original source shape.
- Keep the formal block blank: rejected because it leaves a reconstructable, routed target as an `Empty Emitter Marker`.
- Move ownership to the file root: rejected because the class is the narrow semantic owner.
- Move ownership to the read-only aggregate: rejected because [UID:000260] is mixed inventory and `RECONSTRUCTABLE:FALSE`.
- Create children for each adjusted view: rejected because the primary and adjusted views form one class-owned vtable/RTTI unit.

## Score And Metadata Recommendation

Keep the target at `88/92`.

Why not raise: the current source page already captures exact boundaries, owner/emitter, constructor stores, adjusted views, slot targets, and neighbor boundaries. Adding the marker resolves the generated empty-emitter state but does not prove the complete original class declaration, field layout, or final virtual names.

Why not lower: current MCP reconfirms the essential source-page evidence and finds no conflicting owner, split, or boundary facts.

Metadata stays:

- `CANONICAL_OWNER:00009P`
- `RECONSTRUCTABLE:TRUE`
- `EMITTER_UIDS:00009P`
- `EMITTER_POSITION_OPTIONAL:` blank
- `Nested:0`

## Recommended Target Doc Changes

Target file: `by-memory/0x0062089c-0x00620950.ObjectInfoObjectPaneVtableData.md`

1. Keep scores and owner/emitter metadata unchanged at `88/92`, owner/emitter [UID:00009P].
2. Replace the stale `Item Summary` with non-stale wording such as:

```text
Exact ObjectInfoObjectPane RTTI/vtable child assigned to the ObjectInfoObjectPane class; current MCP reconfirms primary and adjusted vtable bases, constructor vptr stores, destructor/adjustor slots, and DamageNumber/Motion boundaries; emitted source is a no-raw-vtable marker because the compiler regenerates this data from the class declaration.
```

3. Insert the exact formal marker:

```cpp
// Compiler-emitted RTTI/vtable data for ObjectInfoObjectPane is regenerated from
// [UID:00009P] ObjectInfoObjectPane class declarations, virtual method definitions,
// destructor wrappers, and the [UID:0000HJ] AttachedObjectPane.cpp source module.
// No raw vtable or RTTI dword tables are hand-authored for this .rdata range.
```

4. Add a current B005 MCP evidence note with session `agent_b009_0002my_20260628`, range size `0xb4` / 180, dword boundaries, constructor stores at `0x005395df`, `0x005395e5`, `0x005395ef`, and the absence of direct RTTI-boundary xrefs.
5. Update reconstruction notes to say the formal output is a marker-only no-raw-vtable disposition, while method declarations/bodies remain under the class/file route.
6. Add a generated-state note that current generated files are stale and must be refreshed by scoped validation, not manual edits.

## Recommended Support Doc Changes

`by-class/ObjectInfoObjectPane.md`

- Keep score and metadata unchanged.
- Add a concise B005 evidence note that current MCP reconfirmed [UID:000355] as the class-owned RTTI/vtable child and that [UID:000355] should carry the formal no-raw-vtable marker.
- Preserve the current class-level C++ blank state; this report does not solve final class declaration, field offset, config flag, or draw-state blockers.

`by-file/AttachedObjectPane.md`

- Keep score and metadata unchanged.
- Add a concise B005 source-route/generated-state note that [UID:000355] is emitted through the `ObjectInfoObjectPane` class under this source module and should no longer appear as an `Empty Emitter Marker` after the target marker and generated refresh.

`by-memory/0x00620284-0x00620c74.ObjectPaneReadOnlyData.md`

- No required edit. The aggregate already lists [UID:000355] as assigned to [UID:00009P] and remains correctly non-emitting.

Neighbor/sibling vtable pages:

- No required edit to [UID:000354] or [UID:000356]. They are useful boundary controls, not part of this implementation callback.

Generated files/reports:

- Do not manually edit `auto-generated/NexusTK/map/AttachedObjectPane.cpp`, `auto-generated/-ag-research-tracker.md`, or `auto-generated/-ag-coverage-report-by-memory.md`.
- After implementation and validation, `AttachedObjectPane.cpp` should show UID000355 with the marker comment and not as `Empty Emitter Marker`.

## Claim And Incorporation Ledger

| # | Accepted claim/fact | Action | Destination / reason | Verification state |
| --- | --- | --- | --- | --- |
| 1 | Target [UID:000355] remains `COMPLETION:88`, `CONFIDENCE:92`, `CANONICAL_OWNER:00009P`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:00009P`, and blank `EMITTER_POSITION_OPTIONAL`. | already-present | Target header already had these values and scoped validator `000000000221` preserved them. | already-present |
| 2 | Target inline `RECONSTRUCTION_CPP CODE:[[[]]]` remains blank. | already-present | Target header retained blank inline value after validation. | already-present |
| 3 | Target multiline formal C++ must resolve the empty emitter with the accepted no-raw-vtable marker. | incorporate | Inserted marker in target multiline block. Validator normalized UID tokens to markdown UID links in the source doc/generated comment, while preserving the marker content and no-raw-vtable disposition. | applied |
| 4 | Stale target `Item Summary` saying parent blank/below `82/88` must be rejected. | reject-stale | Replaced with current class-owned, MCP, boundary, and marker disposition. | applied |
| 5 | Exact range `0x0062089c-0x00620950` and `0xb4` / 180-byte size must be preserved. | incorporate | Target `Range`, current B005 evidence note, and validator-refreshed generated coverage row preserve range/size. | applied |
| 6 | Primary and adjusted views at `0x006208a0`, `0x00620918`, and `0x00620948` must be preserved. | incorporate | Target current B005 evidence note records all three bases and view spans. | applied |
| 7 | RTTI dword boundaries at `0x0062089c`, `0x00620914`, `0x00620944`, and successor `0x00620950` must be preserved. | incorporate | Target current B005 evidence note records each dword target and excludes Motion at `0x00620950`. | applied |
| 8 | Constructor vptr stores at `0x005395df`, `0x005395e5`, and `0x005395ef` must be preserved. | incorporate | Target current B005 evidence note and class/file support notes record the three stores. | applied |
| 9 | Slot refs for primary destructor, ObjectInfo overrides, and adjusted thunks must be preserved. | incorporate | Target current B005 evidence note records `0x0053d620`, `0x00539760`, `0x005398e0`, `0x00539b20`, `0x00539700`, `0x0053cf5c`, and `0x0053cf67`. | applied |
| 10 | Absence of direct RTTI-boundary xrefs must be preserved as expected negative evidence. | incorporate | Target current B005 evidence note records no direct xrefs for RTTI pointer dwords and the successor boundary dword. | applied |
| 11 | Destructor/adjustor shape must be preserved: scalar deleting destructor calls cleanup/free helpers; thunks subtract `0xa0`/`0xa4` and jump to destructor. | incorporate | Target current B005 evidence note records `sub_53D620`, `sub_538100`, `sub_4F4AC0`, `sub_53CF5C`, and `sub_53CF67`. | applied |
| 12 | DamageNumber predecessor and Motion successor boundaries must be preserved. | incorporate | Target summary/evidence and file support note preserve `DamageNumberObjectPane` predecessor and `Motion` successor boundary. | applied |
| 13 | Direct class/file route must be preserved: owner/emitter [UID:00009P], generated through [UID:0000HJ]. | incorporate | Target assignment gate/reconstruction notes, class support note, and file support note record the route. | applied |
| 14 | Raw RTTI/vtable arrays must be rejected. | incorporate | Target reconstruction notes explicitly reject raw RTTI/vtable arrays and file support note says not to add raw dword tables. | applied |
| 15 | Keeping the formal C++ blank must be rejected. | reject-invalid | Target formal marker now resolves the empty-emitter state; generated output confirms UID000355 is not an empty marker. | applied |
| 16 | Direct file ownership and read-only aggregate ownership must be rejected. | incorporate | Target assignment gate/reconstruction notes reject bypassing [UID:00009P] and reject broad aggregate ownership. | applied |
| 17 | Splitting each adjusted view into children must be rejected. | incorporate | Target reconstruction notes explicitly reject adjusted-view child splits. | applied |
| 18 | [UID:00009P] support page should retain class-level C++ blank and final class blockers. | incorporate | Class support note added marker relationship while preserving blank class C++ and unresolved field/config/draw-state blockers. | applied |
| 19 | [UID:0000HJ] support page should record generated-state/source-route note for UID000355. | incorporate | File support notes and change log record UID000355 emits through ObjectInfo under this source module and should not be an empty marker after refresh. | applied |
| 20 | [UID:000260] ObjectPaneReadOnlyData does not require edit unless conflicting stale UID000355 text exists. | not-applicable | The aggregate already listed UID000355 as assigned to [UID:00009P] and was not edited; B004 later acquired a separate lease on that file, so B005 did not touch it. | excluded-with-reason |
| 21 | Generated reports/C++ and tool state must not be manually edited. | not-applicable | No manual edits were made to generated files, manual coverage reports, validator/tool state, lock files, or IDA DB. Scoped validators produced validator-owned generated/tool-state side effects, reported below. | excluded-with-reason |
| 22 | Validators and generated-output proof must be recorded. | incorporate | Validator command IDs, timestamps, `ok` counts, generated refresh state, and generated UID000355 proof are recorded in `Validator Results`. | applied |

## Validators Expected After Implementation

Run scoped validators only during the implementation callback, from `source-3/project-documentation`. A practical sequence:

> Executable block R001 was removed from this report and preserved verbatim in [000355-ObjectInfoObjectPaneVtableData-empty-emitter-source-quality-removed.md](000355-ObjectInfoObjectPaneVtableData-empty-emitter-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

If support docs are not edited because the supervisor chooses a target-only implementation, skip their validators and record the same-or-greater-detail proof.

Post-validation read-only checks:

> Executable block R002 was removed from this report and preserved verbatim in [000355-ObjectInfoObjectPaneVtableData-empty-emitter-source-quality-removed.md](000355-ObjectInfoObjectPaneVtableData-empty-emitter-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

Do not run `execute_report`; supervisor owns execution after verification.

## Validator Results

Implementation callback validators were run from `E:\NTK\GhidraBridge\source-3\project-documentation`:

| Command | Exit | `command_id` | `command_timestamp` | `ok` | Generated refresh / notes |
| --- | ---: | --- | --- | ---: | --- |
| `python .\tools\validator.py --mode file --file by-memory\0x0062089c-0x00620950.ObjectInfoObjectPaneVtableData.md --apply --queue-timeout 240 --wait-generated` | 0 | `000000000221` | `2026-06-29T00:53:01-04:00` | 1 | `generated_refresh: completed`, `generated_refresh_command_id: 000000000221`. Validator preserved target `88/92`, owner/emitter [UID:00009P], and refreshed generated output/reports. It also normalized bare UID tokens inside the formal marker into markdown UID links. |
| `python .\tools\validator.py --mode file --file by-class\ObjectInfoObjectPane.md --apply --queue-timeout 240` | 0 | `000000000223` | `2026-06-29T00:53:25-04:00` | 1 | `generated_refresh: deferred`; class metadata stayed `85/89`, owner/emitter [UID:0000HJ]. |
| `python .\tools\validator.py --mode file --file by-file\AttachedObjectPane.md --apply --queue-timeout 240 --wait-generated` | 0 | `000000000225` | `2026-06-29T00:53:32-04:00` | 1 | `generated_refresh: completed`, `generated_refresh_command_id: 000000000225`; file metadata stayed `86/86`, `CANONICAL_OWNER:FILE`, path `NexusTK/map/`. |

Validator-owned side effects observed: `auto-generated/NexusTK/map/AttachedObjectPane.cpp`, `auto-generated/-ag-research-tracker.md`, `auto-generated/-ag-coverage-report-by-memory.md`, `project-level/-auto-completion-stats.md`, and `tools/validator.ini` changed during scoped validation/generation. These were not edited manually. Validators also reported unrelated stale registry/missing-file diagnostics for many other UIDs; no UID000355-specific validator failure remained.

Generated-output proof:

- `auto-generated/NexusTK/map/AttachedObjectPane.cpp` was inspected after validation. The latest observed header was `validator-command-id: 000000000231` and `validator-refreshed-at: 2026-06-29T00:56:05-04:00`, which is newer than B005's required generated refresh command `000000000225`.
- UID000355 appears as `Completion:88 | Confidence:92`.
- The generated UID000355 block contains the no-raw-vtable marker text, and UID000355 is not an `Empty Emitter Marker`.
- Queue status command `000000000232` at `2026-06-29T00:56:49-04:00` reported `queued jobs: 0`, `processing jobs: 0`, `queued generated refresh jobs: 0`, and `processing generated refresh jobs: 0`.
- `auto-generated/-ag-coverage-report-by-memory.md` now reports UID000355 `emits_code:true` and the updated item summary.
- `auto-generated/-ag-research-tracker.md` now reports UID000355 at `88/92`, combined `90.0`, reconstructable `true`.

Lease proof:

- B005 leased `by-memory\0x0062089c-0x00620950.ObjectInfoObjectPaneVtableData.md`, `by-class\ObjectInfoObjectPane.md`, and `by-file\AttachedObjectPane.md` immediately before the edit/validator batch.
- B005 released all three leases after validators and generated inspection. A post-release lease report showed no B005 leases; B004 held a separate lease on [UID:000260], which B005 did not edit.

## Implementation Tracking Checklist

- [x] Claim and incorporation ledger added and resolved.
  - Proof: `## Claim And Incorporation Ledger` records 22 accepted claims/facts with actions and callback verification states.
- [x] Target doc keeps `CANONICAL_OWNER:00009P`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:00009P`, blank `EMITTER_POSITION_OPTIONAL`, and score `88/92`.
  - Proof: target header preserved these values; validator `000000000221` reported `ok:1`.
- [x] Target stale `Item Summary` is replaced with current parent-gate, MCP, boundary, and marker disposition.
  - Proof: target header now says exact class-owned RTTI/vtable child, current MCP, primary/adjusted bases, constructor stores, destructor/adjustor slots, DamageNumber/Motion boundaries, and no-raw-vtable marker disposition.
- [x] Target formal C++ block contains the recommended no-raw-vtable marker.
  - Proof: marker inserted in target multiline formal block; validator normalized UID tokens to markdown links but generated output carries the marker and no raw vtable arrays.
- [x] Target evidence records current MCP session `agent_b009_0002my_20260628`, range size `0xb4` / 180, primary/adjusted views, constructor vptr stores, slot refs, and successor `Motion` boundary.
  - Proof: target `IDA Evidence` now has a current B005 implementation callback recheck subsection with these facts.
- [x] Target preserves stale/historicalized claims and rejected alternatives.
  - Proof: target `Reconstruction Notes` rejects raw RTTI/vtable arrays, keeping formal C++ blank, direct file ownership, broad aggregate ownership, and adjusted-view splits; `Changes` logs the stale below-gate summary replacement.
- [x] `by-class/ObjectInfoObjectPane.md` receives concise B005 sync without metadata or class formal C++ changes.
  - Proof: class `Evidence Notes`, `Reconstruction State`, and `Changes` record UID000355 current MCP confirmation and formal no-raw-vtable marker while preserving class C++ blockers.
- [x] `by-file/AttachedObjectPane.md` receives concise B005 source-route/generated-state sync without metadata changes.
  - Proof: file `IDA MCP Evidence`, `File-Root State`, and `Changes` record UID000355 emits through ObjectInfo under this module and should no longer be an empty marker after refresh.
- [x] [UID:000260] aggregate is not edited because it already has same-or-greater non-emitting aggregate routing and no conflicting stale UID000355 text in B005 scope.
  - Proof: B005 did not lease or edit [UID:000260]; the ledger marks it `excluded-with-reason`.
- [x] No by-memory aggregate, sibling vtable, generated report, generated C++ file, manual coverage report, lock file, or IDA DB is manually edited.
  - Proof: manual edits were limited to the three accepted by-* docs and this B005 report. Validators produced generated/tool-state side effects, recorded above.
- [x] Scoped validators run after implementation edits.
  - Proof: validators `000000000221`, `000000000223`, and `000000000225` all exited 0 with `ok:1`.
- [x] Generated `auto-generated/NexusTK/map/AttachedObjectPane.cpp` inspected after validation and UID000355 no longer appears as an `Empty Emitter Marker`.
  - Proof: latest observed generated header is command `000000000231`, refreshed `2026-06-29T00:56:05-04:00`, newer than B005's required refresh command `000000000225`; UID000355 appears at `88/92` with the no-raw-vtable marker and not as an empty emitter.
- [x] Leases released immediately after the edit/validator batch.
  - Proof: `leaser.py B005 unlease ...` returned `Success` for all three leased files; post-release `current_leases.md` showed no B005 rows.
- [x] Final callback report includes validator commands/results and generated-output proof.
  - Proof: this `Validator Results` section records command IDs, timestamps, `ok` counts, generated refresh state, generated UID000355 proof, and validator-owned side effects.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B005","command_id":"000000004165","destination_path":"executed-b-agent-research/B005/000355-ObjectInfoObjectPaneVtableData-empty-emitter-source-quality.md","details":"legacy registry reconstruction","event":"executed","source_path":"tools/leaser/Agents/Agent-B005/research/000355-ObjectInfoObjectPaneVtableData-empty-emitter-source-quality.md","timestamp":"2026-06-29T00:58:11","uid":"000355"} -->
<!-- {"agent":"B005","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 000355-ObjectInfoObjectPaneVtableData-empty-emitter-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B005/000355-ObjectInfoObjectPaneVtableData-empty-emitter-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"000355"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
