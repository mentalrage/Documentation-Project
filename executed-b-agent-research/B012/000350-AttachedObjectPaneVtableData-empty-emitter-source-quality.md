** TARGET-REPORT-UID:000350 **
** AUTHOR-AGENT-ID:B012 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **

# 000350 AttachedObjectPaneVtableData Empty-Emitter Source-Quality Report

Assignment: `B012-report-000350-AttachedObjectPaneVtableData-empty-emitter-source-quality-20260628`
Agent: `Agent-B012`
Mode: report-only research. No leases, target/support by-* edits, generated-file edits, project-level generated edits, manual coverage edits, validator/tool-state edits, subagents, IDA DB edits, or IDA process management were performed.
Revision note: existing report preserved and revised in place on 2026-06-29 for the current B-agent report standard. The revision adds a Rule 26 `Claim And Incorporation Ledger`, current-MCP recheck state, explicit blocker/open-question closure, Wave2/Wave3 reliance confirmation, and a file-specific implementation checklist. It does not change the core recommendation.

Target: [UID:000350] `by-memory/0x00620544-0x006205f8.AttachedObjectPaneVtableData.md`
Required report path: `tools/leaser/Agents/Agent-B012/research/000350-AttachedObjectPaneVtableData-empty-emitter-source-quality.md`

## Executive Conclusion

[UID:000350] is an exact `0xb4` / 180-byte compiler-emitted RTTI/vtable child for [UID:00000M] `AttachedObjectPane`. Current IDA MCP evidence confirms that the half-open range starts at the `AttachedObjectPane` complete-object RTTI pointer dword `0x00620544`, contains primary and adjusted vtable views at `0x00620548`, `0x006205c0`, and `0x006205f0`, and ends exactly before the `EffectObjectPane` RTTI pointer dword at `0x006205f8`.

The current owner/emitter route is correct. The source-quality issue is not a missing split or wrong owner; it is the unresolved generated empty-emitter state. This target should receive a formal marker-only C++ block that explicitly says the data is regenerated from the class declaration and virtual methods, with no hand-authored raw vtable or RTTI table.

| Field | Current target | Recommended |
| --- | --- | --- |
| `COMPLETION` | `85` | `87` |
| `CONFIDENCE` | `88` | `91` |
| `CANONICAL_OWNER` | `00000M` | `00000M` |
| `RECONSTRUCTABLE` | `TRUE` | `TRUE` |
| `EMITTER_UIDS` | `00000M` | `00000M` |
| `EMITTER_POSITION_OPTIONAL` | blank | blank |
| Formal `RECONSTRUCTION_CPP CODE` | blank | insert exact marker below |

Exact formal no-raw-vtable marker for [UID:000350]:

```cpp
// Compiler-emitted RTTI/vtable data for AttachedObjectPane is regenerated from
// [UID:00000M] AttachedObjectPane class declarations, virtual method definitions,
// destructor wrappers, and the [UID:0000HJ] AttachedObjectPane.cpp source module.
// No raw vtable or RTTI dword tables are hand-authored for this .rdata range.
```

Insert this marker between the target's multiline `*** RECONSTRUCTION_CPP CODE:BEGIN` and `*** RECONSTRUCTION_CPP CODE:END` lines. Keep the inline `RECONSTRUCTION_CPP CODE:[[[]]]` header value blank.

Disposition decision: formal covered-by/no-raw-vtable marker plus support repair and score movement. A rare blank no-code proof is rejected because the target is reconstructable, has a valid class emitter route, clears the scoring gate, and blank formal C++ currently produces an avoidable `Empty Emitter Marker` in generated output.

## Files And Evidence Read

Direct assignment/rules:

| File | Use |
| --- | --- |
| `tools/leaser/Agents/Agent-B012/goal.md` | Active assignment, report path, target UID/path, report-only restrictions, MCP-unavailable override, and required focus areas. |
| `.codex/skills/ntk-b-agent-workflow/SKILL.md` | Project-level B-agent workflow, report-only mode, MCP expectations, leasing, validation, and final response rules. |
| `.codex/skills/ntk-b-agent-workflow/references/b-agent-research-and-implementation-workflow.md` | Required research sections, empty-emitter/source-quality disposition, support-doc checklist, implementation callback expectations, and exclusions. |
| `.codex/skills/ntk-b-agent-workflow/references/supervisor-rule26-review-and-incorporation-standard.md` | Rule 26 evidence standard, support-doc incorporation standard, exact formal C++ requirement, validator proof expectations, and checklist expectations. |
| `.codex/skills/ntk-b-agent-workflow/references/score-blocker-audit-standard.md` | Current standard for closing named score/source-quality blockers, open questions, and rare no-improvement claims. |
| `by-structure.md`, `tools/validator_README.txt`, `tools/int_convert_readme.md` | Project scoring, owner/emitter, reconstructable/code gate, source-declared/generated-binary handling, validator behavior, and integer-conversion guidance. |
| `by-memory/-guidance.md`, `by-file/-guidance.md`, `by-type/-guidance.md`, `by-type/by-vtable/-guidance.md`, `by-class/-guidance.md` | Local documentation conventions and generated-data/source-placement guidance. |

Target/support docs:

| File | Use |
| --- | --- |
| `by-memory/0x00620544-0x006205f8.AttachedObjectPaneVtableData.md` | Current metadata, blank formal C++, stale summary/body contradiction, range table, vtable stores, and current assignment-gate prose. |
| `by-class/AttachedObjectPane.md` | Direct class parent [UID:00000M], current `85/88` gate-clearing state, method/vtable evidence, final C++ withholding reasons, and generated-state staleness. |
| `by-file/AttachedObjectPane.md` | Source module [UID:0000HJ], current `86/86` gate-clearing state, source-route contents, overlay/helper scope, and class/file reconstruction blockers. |
| `by-memory/0x005380b0-0x005387a3.AttachedObjectPane.md` | Constructor/destructor/attach/detach/source-range evidence, target vtable refs, and stale summary wording still mentioning old gate failure. |
| `by-memory/0x00620284-0x00620c74.ObjectPaneReadOnlyData.md` | Parent mixed `.rdata` aggregate, exact child boundary inventory, current stale [UID:000350] row, and non-emitting aggregate disposition. |
| `by-memory/0x00620498-0x00620544.FlyingObjectPaneVtableData.md` | Predecessor exact vtable child ending at `0x00620544`. |
| `by-memory/0x006205f8-0x006206ac.EffectObjectPaneVtableData.md` | Successor exact vtable child beginning at `0x006205f8`. |
| `by-class/ObjectPane.md`, `by-file/ObjectPane.md`, `by-type/by-struct/AttachedObjectRegistryLayout.md` | Base ObjectPane layout, ObjectPane-family vtable context, and `AttachedObjectPane` registry member offset support. |
| `auto-generated/NexusTK/map/AttachedObjectPane.cpp` | Read-only generated state; confirms [UID:000350] currently appears as an `Empty Emitter Marker`. |
| `auto-generated/-ag-research-tracker.md`, `auto-generated/-ag-coverage-report-by-memory.md` | Read-only generated stale state: target and class routing/summary rows lag current source docs. |
| `executed-b-agent-research/B001/000260-ObjectPaneReadOnlyData.md` | Historical split report; [UID:000350] was originally left unassigned because [UID:00000M] was `82/88`. Current source docs supersede that gate state. |
| `tools/leaser/Agents/Agent-A004/notes.md` | Historical implementation notes showing [UID:000350] was later assigned to [UID:00000M] after class improvement, without changing score. |
| Recent sibling reports `Agent-B013/research/00034Y-ItemObjectPaneVtableData-empty-emitter-source-quality.md` and `Agent-B006/research/00034X-StaticObjectPaneVtableData-empty-emitter-source-quality.md` | Local report precedent for exact vtable children: formal marker-only source coverage, no raw vtable arrays, support-row repair, and scoped validator plans. |

## Current MCP Session

IDA MCP was available and used. Only read-only tools were called. The original report evidence was collected from session `agent_b009_0002my_20260628`; the 2026-06-29 revision rechecked the key target facts against the supervisor-restored active session `07c55da0`.

| Evidence | Result |
| --- | --- |
| Revision listener | `127.0.0.1:13337` reachable. |
| Endpoint | `http://127.0.0.1:13337/mcp` |
| Initialize | JSON-RPC initialize succeeded; server `ida-pro-mcp` version `1.0.0`, protocol `2025-06-18`. |
| Active session for revision | `07c55da0` |
| IDB path | `E:\NTK\Resources\NexusTK\NexusTK.exe.i64` |
| Revision session state | `backend:"worker"`, `owned:true`, `adopted:true`, `pid:9064`, `worker_pid:9064`, `is_active:true`, `is_analyzing:false`. |
| Revision `server_health` | `status:"ok"`, module `NexusTK.exe`, input path `C:\Users\admin\Desktop\Clone\NexusTK\NexusTK.exe`, imagebase `0x400000`, `auto_analysis_ready:true`, `hexrays_ready:true`, `strings_cache_ready:true`, strings cache size `2067`. |

Selected read-only MCP tools used: `tools/list`, `idb_list`, `server_health`, `entity_query`, `get_bytes`, `get_int`, `find`, `xrefs_to`, `lookup_funcs`, `disasm`, `analyze_function`, and `int_convert`.

Revision recheck on session `07c55da0`:

| Tool | Rechecked fact |
| --- | --- |
| `entity_query` names/strings | Names remain `??_7AttachedObjectPane@@6B@` at `0x00620548`, `_0` at `0x006205c0`, `_1` at `0x006205f0`, and successor `??_7EffectObjectPane@@6B@` at `0x006205fc`; strings in `0x00620544-0x006205f8` remain empty. |
| `xrefs_to` | Vtable refs remain `0x00620548 -> 0x005380d5/0x00538132`, `0x006205c0 -> 0x005380db/0x00538138`, `0x006205f0 -> 0x005380e5/0x00538142`; successor vtable base `0x006205fc` remains referenced from `0x005387e9`, `0x00538880`, and `0x0053d125`; predecessor adjusted view `0x0062053c` remains referenced from `0x00537d2c`. |
| `get_bytes` | Start bytes at `0x00620544` still begin `f0 d0 64 00 a0 cf 53 00`; final target view at `0x006205ec` remains `18 d1 64 00 99 ce 53 00 a0 86 53 00`; successor bytes at `0x006205f8` still begin `2c d1 64 00 00 d1 53 00`. |
| `find type=data_ref` | No refs to RTTI boundary dwords `0x00620544`, `0x006205bc`, `0x006205ec`, or `0x006205f8`; vtable bases retain only constructor/destructor refs. |

## Current Target State

| Field | Current value |
| --- | --- |
| UID | `000350` |
| Range/title | `0x00620544-0x006205f8 AttachedObjectPane Vtable Data` |
| Completion/confidence | `85` / `88` |
| Canonical owner | `00000M` |
| Reconstructable | `TRUE` |
| Emitter UIDs | `00000M` |
| Formal C++ | blank |
| Generated output | `auto-generated/NexusTK/map/AttachedObjectPane.cpp` currently has `[UID:000350] ... Empty Emitter Marker`. |

The target body is mostly directionally correct: it identifies source-declared compiler-emitted RTTI/vtable data, attaches the child to [UID:00000M], and says the class/file gates now clear. The header `Item Summary` is stale because it still says the parent is blank due to the direct class parent being `82/88`. Current source docs and validator-refreshed headers show [UID:00000M] at `85/88` and [UID:0000HJ] at `86/86`; both clear the strict `85/85` gate. The stale summary should be replaced.

## Live MCP Range Evidence

`entity_query` over `0x00620544-0x00620604` reports the three `AttachedObjectPane` vtable-base names inside the target and the successor `EffectObjectPane` vtable base just after it:

| Address | Name | Segment |
| --- | --- | --- |
| `0x00620548` | `??_7AttachedObjectPane@@6B@` | `.rdata` |
| `0x006205c0` | `??_7AttachedObjectPane@@6B@_0` | `.rdata` |
| `0x006205f0` | `??_7AttachedObjectPane@@6B@_1` | `.rdata` |
| `0x006205fc` | `??_7EffectObjectPane@@6B@` | `.rdata` |

`get_bytes` for the full target confirmed 180 bytes. The first bytes are:

```text
0xf0 0xd0 0x64 0x00 0xa0 0xcf 0x53 0x00 ...
```

The final target bytes are:

```text
... 0x18 0xd1 0x64 0x00 0x99 0xce 0x53 0x00 0xa0 0x86 0x53 0x00
```

Neighbor byte reads confirm the exact half-open boundaries:

| Address | Bytes | Meaning |
| --- | --- | --- |
| `0x0062053c` | `f1 ce 53 00 20 7f 53 00 f0 d0 64 00 a0 cf 53 00` | Previous `FlyingObjectPane` adjusted slot values end at `0x00620544`; `0x00620544` begins with `AttachedObjectPane` RTTI pointer `0x0064d0f0`. |
| `0x006205f8` | `2c d1 64 00 00 d1 53 00 10 4b 4f 00 c0 b6 41 00` | Successor `EffectObjectPane` starts at RTTI pointer `0x0064d12c`, then vtable base slot `0x0053d100` at `0x006205fc`. |

`int_convert` with explicit sizes verifies the table/view sizes:

| Hex | Decimal | Use |
| --- | ---: | --- |
| `0xb4` | 180 | full target range length |
| `0x78` | 120 | complete-object RTTI plus primary view span `0x00620544-0x006205bc` |
| `0x30` | 48 | first adjusted RTTI plus adjusted view span `0x006205bc-0x006205ec` |
| `0x0c` | 12 | final adjusted RTTI plus two-slot adjusted view span `0x006205ec-0x006205f8` |
| `0xa0` | 160 | first adjusted this offset |
| `0xa4` | 164 | second adjusted this offset |
| `0x128` | 296 | registry/member slot used by constructor/destructor support docs |

## Dword Layout

`get_int u32le` over every target dword confirms the exact layout:

| Address | Dword | Role |
| --- | --- | --- |
| `0x00620544` | `0x0064d0f0` | complete-object RTTI locator pointer for `AttachedObjectPane` |
| `0x00620548` | `0x0053cfa0` | primary slot 0, scalar deleting destructor |
| `0x0062054c` | `0x004f4b10` | inherited/shared primary virtual slot |
| `0x00620550` | `0x0041b6c0` | inherited/shared primary virtual slot, `nullsub_18` |
| `0x00620554` | `0x00537740` | inherited/shared ObjectPane-family virtual slot |
| `0x00620558` | `0x0041d680` | inherited/shared primary virtual slot, `nullsub_19` |
| `0x0062055c` | `0x00544730` | inherited/shared ObjectPane-family virtual slot |
| `0x00620560` | `0x00544750` | inherited/shared ObjectPane-family virtual slot |
| `0x00620564` | `0x005447a0` | inherited/shared ObjectPane-family virtual slot |
| `0x00620568` | `0x00537720` | inherited/shared ObjectPane-family virtual slot |
| `0x0062056c` | `0x00544a20` | inherited/shared ObjectPane-family virtual slot |
| `0x00620570` | `0x00544b80` | inherited/shared ObjectPane-family virtual slot |
| `0x00620574` | `0x00537760` | inherited/shared ObjectPane-family virtual slot |
| `0x00620578` | `0x00544c70` | inherited/shared ObjectPane-family virtual slot |
| `0x0062057c` | `0x00544cb0` | inherited/shared ObjectPane-family virtual slot |
| `0x00620580` | `0x00544ce0` | inherited/shared ObjectPane-family virtual slot |
| `0x00620584` | `0x00544d30` | inherited/shared ObjectPane-family virtual slot |
| `0x00620588` | `0x00544d70` | inherited/shared ObjectPane-family virtual slot |
| `0x0062058c` | `0x0041b6a0` | guard/check stub slot |
| `0x00620590` | `0x00538300` | `AttachedObjectPane` attach-object virtual slot |
| `0x00620594` | `0x00538460` | `AttachedObjectPane` detach-object virtual slot |
| `0x00620598` | `0x00469050` | shared ObjectPane-family virtual slot |
| `0x0062059c` | `0x00537800` | shared ObjectPane-family virtual slot |
| `0x006205a0` | `0x00537880` | shared ObjectPane-family virtual slot |
| `0x006205a4` | `0x0041b6c0` | shared `nullsub_18` slot |
| `0x006205a8` | `0x00469080` | shared ObjectPane-family virtual slot |
| `0x006205ac` | `0x0041b6c0` | shared `nullsub_18` slot |
| `0x006205b0` | `0x005378a0` | shared ObjectPane-family virtual slot |
| `0x006205b4` | `0x00538600` | `AttachedObjectPane` viewport/map synchronization slot |
| `0x006205b8` | `0x005ca28c` | `__purecall` |
| `0x006205bc` | `0x0064d104` | first adjusted RTTI locator pointer |
| `0x006205c0` | `0x0053ce8e` | first adjusted slot 0, `this-0xa0` thunk to scalar deleting destructor |
| `0x006205c4` | `0x0041d6b0` | adjusted-view virtual slot |
| `0x006205c8` | `0x00544dc0` | adjusted-view virtual slot |
| `0x006205cc` | `0x00544dd0` | adjusted-view virtual slot |
| `0x006205d0` | `0x0041d6b0` | adjusted-view virtual slot |
| `0x006205d4` | `0x00544df0` | adjusted-view virtual slot |
| `0x006205d8` | `0x00544e00` | adjusted-view virtual slot |
| `0x006205dc` | `0x004a89f0` | adjusted-view virtual slot |
| `0x006205e0` | `0x00544e10` | adjusted-view virtual slot |
| `0x006205e4` | `0x00544e30` | adjusted-view virtual slot |
| `0x006205e8` | `0x00544e70` | adjusted-view virtual slot |
| `0x006205ec` | `0x0064d118` | second adjusted RTTI locator pointer |
| `0x006205f0` | `0x0053ce99` | second adjusted slot 0, `this-0xa4` thunk to scalar deleting destructor |
| `0x006205f4` | `0x005386a0` | adjusted-view owner/release support slot |

`lookup_funcs` confirms every non-RTTI dword in this range resolves either to a function, thunk, runtime stub, or `__purecall`; none of the target addresses themselves are executable function starts.

## Xrefs, Constructor Stores, And Destructor Restores

`xrefs_to` and `find type=data_ref/immediate` both report the same vptr store/restore sites:

| Vtable base | Xrefs / immediates |
| --- | --- |
| `0x00620548` | `0x005380d5` constructor store, `0x00538132` destructor restore |
| `0x006205c0` | `0x005380db` constructor store, `0x00538138` destructor restore |
| `0x006205f0` | `0x005380e5` constructor store, `0x00538142` destructor restore |

The RTTI boundary dwords have no direct code/data refs as addresses, which is expected for RTTI pointer dwords in MSVC vtable data:

| Address | Direct refs |
| --- | --- |
| `0x00620544` | none |
| `0x006205bc` | none |
| `0x006205ec` | none |
| `0x006205f8` | none, because it is the successor RTTI boundary |

The pointed RTTI records have exactly the expected data-ref pattern:

| RTTI record pointer | Data refs |
| --- | --- |
| `0x0064d0f0` | `0x00620544` |
| `0x0064d104` | `0x006205bc` |
| `0x0064d118` | `0x006205ec` |
| `0x0064d12c` | `0x006205f8` successor `EffectObjectPane` RTTI pointer |

`disasm 0x005380b0` confirms the `AttachedObjectPane` constructor:

| Address | Instruction meaning |
| --- | --- |
| `0x005380c5` | calls base constructor `sub_5372D0` |
| `0x005380cd` | stores constructor argument to `[esi+0x128]`, the attached-object registry/member slot |
| `0x005380d5` | writes `0x00620548` to `[esi]` |
| `0x005380db` | writes `0x006205c0` to `[esi+0xa0]` |
| `0x005380e5` | writes `0x006205f0` to `[esi+0xa4]` |
| `0x005380f5` | returns with `retn 0x10` |

`disasm 0x00538100` and `analyze_function 0x00538100` confirm the ordinary destructor:

| Evidence | Result |
| --- | --- |
| Vptr restores | `0x00538132 -> [esi] = 0x00620548`, `0x00538138 -> [esi+0xa0] = 0x006205c0`, `0x00538142 -> [esi+0xa4] = 0x006205f0`. |
| Attached payload use | Reads attached payload at `[this+0x118]`. |
| Registry/member use | Reads registry/member at `[this+0x128]` / decimal 296. |
| Detach registry call | Calls `sub_53AEC0(registry, this)` at `0x005382b0`. |
| Base/object cleanup | Calls helper routines including `sub_53C810`, `sub_4B8E00`, `sub_506CC0`, payload virtual destructor through `[eax]`, `sub_544B80`, and base cleanup `sub_5373A0`. |
| Callers | Includes `sub_53CFA0` scalar deleting destructor plus overlay/companion destructor paths such as `sub_538880`, `sub_538E40`, `sub_539360`, `sub_53D060`, `sub_53D100`, `sub_53D240`, and `sub_53D620`. |

Destructor wrapper and adjusted-thunk proof:

| Function | Evidence |
| --- | --- |
| `0x0053cfa0` / `sub_53CFA0`, size `0x3b` | Scalar deleting destructor. Calls `sub_538100` at `0x0053cfa6`, conditionally frees/deletes based on the delete flag, and returns `this`. Primary vtable slot at `0x00620548` points here. |
| `0x0053ce8e` / `sub_53CE8E`, size `0x0b` | Adjustor thunk: `sub ecx, 0A0h; jmp sub_53CFA0`. First adjusted vtable slot at `0x006205c0` points here. |
| `0x0053ce99` / `sub_53CE99`, size `0x0b` | Adjustor thunk: `sub ecx, 0A4h; jmp sub_53CFA0`. Second adjusted vtable slot at `0x006205f0` points here. |

Representative slot xrefs support the source-method split:

| Function | Data/code refs |
| --- | --- |
| `0x0053cfa0` | data ref from `0x00620548`; code refs from adjusted thunks `0x0053ce94` and `0x0053ce9f`. |
| `0x0053ce8e` | data ref from `0x006205c0`. |
| `0x0053ce99` | data ref from `0x006205f0`. |
| `0x00538300` | data refs from `0x00620590` and sibling object-pane vtables; documented as `AttachObject`. |
| `0x00538460` | data refs from `0x00620594` and sibling object-pane vtables; documented as `DetachObject`. |
| `0x00538600` | data refs from `0x006205b4` and overlay-pane sibling vtables. |
| `0x005386a0` | data ref from `0x006205f4` and sibling adjusted views. |

## Boundary And Neighbor Recheck

The predecessor [UID:00034Z] `FlyingObjectPaneVtableData` ends exactly at `0x00620544`:

- `by-memory/0x00620498-0x00620544.FlyingObjectPaneVtableData.md` records the predecessor range ending at `0x00620544`.
- `entity_query` reports `??_7FlyingObjectPane@@6B@_1` at `0x0062053c`, not inside the target.
- `xrefs_to 0x0062053c` reports the predecessor adjusted view store from `0x00537d2c`.
- Bytes at `0x0062053c` show the predecessor's final slot values followed immediately by `0x0064d0f0`, the `AttachedObjectPane` RTTI pointer at target start.

The successor [UID:000351] `EffectObjectPaneVtableData` starts exactly at `0x006205f8`:

- `by-memory/0x006205f8-0x006206ac.EffectObjectPaneVtableData.md` records the successor range beginning at `0x006205f8`.
- `find type=data_ref` reports `0x0064d12c` only at `0x006205f8`, confirming this is the successor RTTI pointer.
- `entity_query` reports `??_7EffectObjectPane@@6B@` at `0x006205fc`.
- `xrefs_to 0x006205fc` reports `EffectObjectPane` vtable refs from `0x005387e9`, `0x00538880`, and `0x0053d125`.
- `xrefs_to 0x006205f8` reports no direct refs, matching the RTTI-pointer boundary pattern.

The broad [UID:000260] `ObjectPaneReadOnlyData` aggregate correctly remains parent-blank and non-emitting. It is a mixed `.rdata` inventory spanning ObjectList, base ObjectPane, Static/Item/Flying/Attached/Effect object panes, BowGauge/HitBar/DamageNumber/ObjectInfo panes, Motion/Living/Lighting/Sound data, resource strings/constants, and an OptionPane RTTI boundary. No single class or file should own or emit the aggregate.

## Negative Evidence

- `entity_query strings` over `0x00620544-0x006205f8` returns zero strings. This is not a resource or literal-data child.
- `lookup_funcs` confirms the target addresses are not functions. There is no callable body to decompile or source-authored algorithm to port inside [UID:000350].
- The only direct refs to the three vtable bases are constructor/destructor vptr stores and restores. No evidence suggests a handwritten source array references or initializes this range directly.
- `find type=immediate` and `find type=data_ref` show no hidden refs to the RTTI boundary dwords `0x00620544`, `0x006205bc`, `0x006205ec`, or successor boundary `0x006205f8`. The vtable bases, not RTTI pointer addresses, carry the code refs.
- No evidence supports splitting the target at `0x006205bc` or `0x006205ec`; those are adjusted RTTI/view boundaries for the same class, with `this-0xa0` and `this-0xa4` destructor thunks.
- No evidence supports merging with `FlyingObjectPaneVtableData` or `EffectObjectPaneVtableData`; current names, bytes, refs, and successor/predecessor pages prove exact half-open boundaries.
- No evidence supports reassigning this child to the broad [UID:000260] aggregate; that page is intentionally mixed-owner and `RECONSTRUCTABLE:FALSE`.
- No evidence supports bypassing the class and assigning directly to [UID:0000HJ] as the emitter. The `AttachedObjectPane` class declaration is the narrower semantic owner that causes the compiler to emit this RTTI/vtable data.
- No evidence supports keeping blank formal C++ as a rare no-code proof. A marker is the correct formal representation of "covered by class declarations/methods, no raw vtable source".

## Source-Shape And Ownership Analysis

Recommended source-facing identity:

```text
AttachedObjectPane compiler-emitted RTTI/vtable data generated from the AttachedObjectPane class declaration and virtual method definitions.
```

Owner/emitter route:

```text
[UID:000350] -> [UID:00000M] AttachedObjectPane -> [UID:0000HJ] AttachedObjectPane.cpp -> NexusTK/map/
```

Why the current route is correct:

- The constructor writes the three `AttachedObjectPane` vptrs to `this`, `this+0xa0`, and `this+0xa4`.
- The ordinary destructor restores the same three vptrs before releasing attached payload/registry state and calling base cleanup.
- The scalar deleting destructor and two adjusted thunks are internally consistent with the primary and adjusted views.
- Primary vtable slots include `AttachedObjectPane` attach/detach/synchronization methods documented in the executable source range.
- The direct class parent [UID:00000M] is current `85/88`, and the file parent [UID:0000HJ] is current `86/86`; both clear the strict `85/85` gate.
- The previous B001 split report's "unassigned; class `82/88`" state is historical. Current source docs supersede it.

Rejected alternatives:

| Alternative | Decision |
| --- | --- |
| Raw C++ arrays for the `AttachedObjectPane` vtables/RTTI | Rejected. This would hand-author MSVC ABI data that should be regenerated from declarations and virtual methods. |
| Standalone source body for [UID:000350] | Rejected. The range is `.rdata`, not a source-authored function body. |
| `RECONSTRUCTABLE:FALSE` with blank emitter | Rejected. The range is reconstructable as source-declared/generated-binary output of a known class. |
| Move owner/emitter to [UID:0000HJ] directly | Rejected. The class [UID:00000M] is the narrower semantic owner and clears the gate. |
| Fold into [UID:000260] `ObjectPaneReadOnlyData` | Rejected. The aggregate is intentionally non-emitting and mixed-owner. |
| Merge with predecessor/successor vtable children | Rejected. Exact RTTI/vtable boundaries are proven at `0x00620544` and `0x006205f8`. |
| Keep blank formal C++ as rare no-code proof | Rejected. The target has a valid emitter route and should emit an explicit covered-by/no-raw-vtable marker. |

## Empty-Emitter Disposition

Current generated output still shows:

```text
// UID:000350 | by-memory\0x00620544-0x006205f8.AttachedObjectPaneVtableData.md | Completion:85 | Confidence:88 | Empty Emitter Marker
```

That marker is now avoidable. [UID:000350] is not waiting for a raw table body. It needs a formal comment that encodes the source disposition: compiler-emitted `.rdata` generated by the [UID:00000M] class declaration, destructor wrappers, and virtual method definitions in [UID:0000HJ].

The formal marker in the Executive Conclusion is intentionally more specific than a generic "covered by UID" line because this assignment requires a no-raw-vtable disposition. The implementation should not add `void*` arrays, dword tables, RTTI structs, or standalone source bodies for this range.

## Score And Metadata Recommendation

Target [UID:000350]:

- Raise `COMPLETION` from `85` to `87`.
  - Reason: implementation would resolve the stale parent-blank summary, add current MCP proof, prove exact range/view boundaries, document constructor/destructor stores and adjusted thunks, reject raw-table/aggregate alternatives, and replace the generated empty marker with a formal no-raw-vtable marker.
- Raise `CONFIDENCE` from `88` to `91`.
  - Reason: live MCP independently reconfirms names, bytes, refs, function targets, disassembly, destructor behavior, adjusted views, no-string/no-hidden-boundary evidence, and neighbor boundaries. Confidence stays below final 95 because final source declarations/field names for the broader `AttachedObjectPane` class/file remain below final-source level and generated tracker rows are stale until validator refresh.
- Keep `CANONICAL_OWNER:00000M`.
- Keep `RECONSTRUCTABLE:TRUE`.
- Keep `EMITTER_UIDS:00000M`.
- Keep `EMITTER_POSITION_OPTIONAL` blank.
- Insert the exact formal marker from the Executive Conclusion.

Suggested replacement `Item Summary`:

```text
Exact `AttachedObjectPane` RTTI/vtable child assigned to [UID:00000M]; current MCP confirms the `0x00620544-0x006205f8` / `0xb4`-byte range, RTTI pointer dwords to `??_R4AttachedObjectPane@@6B@` / `_0` / `_1`, primary and adjusted vtable bases at `0x00620548`, `0x006205c0`, and `0x006205f0`, constructor/destructor vptr stores at `this+0`, `this+0xa0`, and `this+0xa4`, adjusted destructor thunks `0x0053ce8e` and `0x0053ce99`, exact predecessor `FlyingObjectPane` and successor `EffectObjectPane` boundaries, and a formal no-raw-vtable marker because this compiler-emitted data is regenerated from the class declaration/methods rather than hand-authored C++ arrays.
```

Support page score changes are not recommended in this pass. The class and file pages remain broader source-quality targets with withheld final C++ for field names, helper names, overlay folding, and class declaration details. This report only resolves the exact vtable child and related stale support prose.

## Claim And Incorporation Ledger

Implementation callback verification state is now recorded for every row. Allowed states are `applied`, `already-present`, `excluded-with-reason`, or `blocked`.

| Claim ID | Claim | Confidence | Evidence | Destination doc/section | Action | Verification state | Implementation proof |
| --- | --- | --- | --- | --- | --- | --- | --- |
| C001 | [UID:000350] is the exact half-open `0x00620544-0x006205f8` / `0xb4`-byte `AttachedObjectPane` RTTI/vtable child, not an executable function body or resource string range. | High | Original `get_bytes`/`get_int`; revision `get_bytes`; `entity_query` strings total `0`; `lookup_funcs` on target data. | Target `by-memory/0x00620544-0x006205f8.AttachedObjectPaneVtableData.md`, range/evidence section. | incorporate | applied | Target now has `## B012 Current MCP Evidence`, `## Dword Layout And Slot Roles`, and `## Boundary And Negative Evidence` with the exact range, zero strings, and data-only disposition. |
| C002 | The primary and adjusted vtable bases are `0x00620548`, `0x006205c0`, and `0x006205f0`, named `??_7AttachedObjectPane@@6B@`, `_0`, and `_1`. | High | Original and revision `entity_query` names on `0x00620544-0x00620604`. | Target evidence table and class support note. | incorporate | applied | Target evidence table records all three bases; class/file support notes repeat the bases and vptr-store route. |
| C003 | The three RTTI locator pointer dwords are `0x00620544 -> 0x0064d0f0`, `0x006205bc -> 0x0064d104`, and `0x006205ec -> 0x0064d118`. | High | Original full `get_int` dword layout; revision boundary bytes; RTTI data-ref search. | Target dword/layout section. | incorporate | applied | Target `Dword Layout And Slot Roles` table records all three RTTI locator dwords and their roles. |
| C004 | Constructor `0x005380b0` writes the three vptrs at `0x005380d5`, `0x005380db`, and `0x005380e5` to `this`, `this+0xa0`, and `this+0xa4`. | High | Original `disasm 0x005380b0`; original and revision `xrefs_to`/`find data_ref`. | Target vptr-store evidence; `by-class/AttachedObjectPane.md` support note; `by-file/AttachedObjectPane.md` source-route note. | incorporate | applied | Target current-refs table and class/file B012 notes record the constructor vptr stores at all three offsets. |
| C005 | Destructor `0x00538100` restores the same three vptrs at `0x00538132`, `0x00538138`, and `0x00538142`, then releases attached payload/registry state and calls base cleanup. | High | Original `disasm` and `analyze_function`; original and revision `xrefs_to`; existing source-range doc. | Target destructor evidence; `by-memory/0x005380b0-0x005387a3.AttachedObjectPane.md` support note. | incorporate | applied | Target current-refs table records the destructor stores; source-range support note records UID000350 marker-only generated-binary coverage for the same cluster. |
| C006 | Scalar deleting destructor slot `0x0053cfa0` and adjusted thunks `0x0053ce8e` (`this-0xa0`) and `0x0053ce99` (`this-0xa4`) prove the adjusted views belong to the same class vtable family. | High | Original `disasm` for destructor wrapper and thunks; slot xrefs from target dwords. | Target adjusted-view/thunk evidence. | incorporate | applied | Target dword layout and thunk proof identify `0x0053cfa0`, `0x0053ce8e`, and `0x0053ce99`. |
| C007 | The predecessor boundary is exact: [UID:00034Z] ends at `0x00620544`, and `0x0062053c` is the predecessor `FlyingObjectPane` adjusted view, referenced from `0x00537d2c`. | High | Predecessor doc; original/revision `xrefs_to 0x0062053c`; neighbor bytes. | Target boundary section; optional no-edit preservation for `FlyingObjectPaneVtableData`. | incorporate | applied | Target `Boundary And Negative Evidence` records predecessor boundary and xref; predecessor page was not edited. |
| C008 | The successor boundary is exact: [UID:000351] starts at `0x006205f8`, successor RTTI pointer is `0x0064d12c`, and successor vtable base `0x006205fc` is `EffectObjectPane`. | High | Successor doc; original/revision bytes; revision `entity_query`; revision `xrefs_to 0x006205fc`. | Target boundary section; optional no-edit preservation for `EffectObjectPaneVtableData`. | incorporate | applied | Target boundary section and aggregate B012 note record the `0x006205f8` successor boundary; successor page was not edited. |
| C009 | Negative evidence rejects raw data/function/string interpretations: no strings in range, no target addresses are functions, and no hidden refs target RTTI boundary dwords. | High | `entity_query strings`; `lookup_funcs`; original/revision `find type=data_ref` and `find type=immediate`. | Target negative evidence section. | incorporate | applied | Target negative evidence records zero strings, no function-body interpretation, no hidden RTTI-boundary refs, and rejected raw-table/source alternatives. |
| C010 | `CANONICAL_OWNER:00000M` and `EMITTER_UIDS:00000M` are correct; direct class [UID:00000M] and file [UID:0000HJ] clear the strict gate. | High | Current target header/body; `by-class/AttachedObjectPane.md` `85/88`; `by-file/AttachedObjectPane.md` `86/86`; constructor/destructor vptr evidence. | Target metadata/source-shape section; class/file support notes. | already-present | applied | Target header preserves owner/emitter `00000M`; class remains `85/88`; file remains `86/86`; support notes were added without changing class/file metadata. |
| C011 | The target's stale summary saying the parent is blank because the class was `82/88` is superseded by current class/file gate state. | High | Target summary/body contradiction; current class/file docs; historical B001 report and A004 notes. | Target `Item Summary`; `ObjectPaneReadOnlyData` child row; source-range stale wording if edited. | reject-stale | applied | Target summary, source-range summary/change log, and aggregate child row now use the current class-owned marker route instead of old blank/class-`82/88` wording. |
| C012 | Completion should move from `85` to `87` and confidence from `88` to `91`; owner/emitter/reconstructable/emitter-position metadata stays otherwise unchanged. | Medium-high | Current MCP proof, support-doc gate check, formal marker disposition, remaining class/file final-C++ limits. | Target metadata header and score rationale. | incorporate | applied | Target header is `COMPLETION:87`, `CONFIDENCE:91`, owner/emitter unchanged, reconstructable true, and emitter position blank; validator `000000000262` and post-restore `000000000269` reported `ok:1`. |
| C013 | The exact formal C++ should be the no-raw-vtable marker from the Executive Conclusion; inline C++ header value remains blank. | High | Code-entry gate satisfied; generated output currently has `Empty Emitter Marker`; no raw vtable source evidence. | Target multiline `RECONSTRUCTION_CPP CODE` block. | incorporate | applied | Target multiline C++ block contains the exact plain marker; inline `RECONSTRUCTION_CPP CODE:[[[]]]` remains blank. A final target `--uid-only` pass `000000000269` preserved the exact marker after reference-phase link expansion from the full validator. |
| C014 | [UID:000350] source output is covered by class declaration, virtual methods, destructor wrappers, and [UID:0000HJ] source module; no raw `void*`, dword, RTTI, or standalone table source should be authored. | High | Source-shape analysis, constructor/destructor stores, adjusted thunks, negative evidence. | Target no-code proof; class/file support notes; generated-output expectation. | incorporate | applied | Target marker/reconstruction notes plus class/file support notes state class-declared/generated-binary coverage and reject raw RTTI/vtable dword tables. |
| C015 | `by-class/AttachedObjectPane.md` needs a support note but no score/metadata/formal C++ change for this target. | Medium-high | Class page already gates and lists vtable evidence; broader class final-C++ blockers are outside this exact vtable child. | `by-class/AttachedObjectPane.md` evidence/changes section. | incorporate | applied | Class Evidence Notes and Changes sections add B012 UID000350 evidence; class score/metadata/formal C++ remain unchanged. |
| C016 | `by-file/AttachedObjectPane.md` needs a source-module support note but no score/metadata/formal C++ change for this target. | Medium-high | File page already gates and owns the source module; broader file source issues are outside the exact vtable child. | `by-file/AttachedObjectPane.md` source-route/evidence section. | incorporate | applied | File Proposed Contents, IDA MCP Evidence, File-Root State, and Changes sections now carry the source-module/no-raw-table route; file score/metadata/formal C++ remain unchanged. |
| C017 | `by-memory/0x005380b0-0x005387a3.AttachedObjectPane.md` has related stale gate/vtable-child wording that should be repaired during the accepted UID000350 implementation callback. | Medium-high | Source-range summary/gate wording read during report; current target/class/file route. | Source-range support doc summary/evidence or change log. | incorporate | applied | Source-range Item Summary, Evidence Details, and Change Log now describe UID000350 as class-owned marker-only generated-binary coverage while preserving existing method evidence. |
| C018 | `by-memory/0x00620284-0x00620c74.ObjectPaneReadOnlyData.md` should keep non-emitting aggregate metadata but repair the [UID:000350] exact-child row to assigned-to [UID:00000M]. | High | Aggregate doc exact child table; current target metadata and class gate; B001 historical state. | Aggregate exact-child table/changes note. | incorporate | applied | Aggregate child row now assigns UID000350 to [UID:00000M] and records B012 boundary/marker evidence; aggregate header remains non-emitting, owner blank, `RECONSTRUCTABLE:FALSE`. |
| C019 | [UID:00034Z] and [UID:000351] neighbor pages are boundary evidence only; no neighbor-page edits are required unless the supervisor explicitly broadens scope. | High | Target boundary recheck; current assignment scope. | Neighbor docs. | not-applicable | excluded-with-reason | Neighbor pages were checked for boundary evidence but not edited because the accepted callback scope covered UID000350 target/support docs only. |
| C020 | [UID:000351] has its own stale summary/empty-emitter issue, but that is a separate target and must not be silently changed during UID000350 implementation. | High | Successor doc read; current assignment names UID000350 only. | Successor doc exclusion note in report/checklist only. | not-applicable | excluded-with-reason | `by-memory/0x006205f8-0x006206ac.EffectObjectPaneVtableData.md` was left unchanged; UID000351 remains separate supervisor work. |
| C021 | Generated C++, generated reports, manual coverage reports, validator/tool state, lock files, executed archives, and IDA DB must not be edited manually. | High | Current assignment and B-agent workflow. | Implementation checklist; final response. | not-applicable | applied | Only by-* docs and this report were manually edited. Generated outputs were refreshed by validators only; no manual coverage/tool/lock/executed/IDA DB edits and no `execute_report` run. |
| C022 | The report and recommendation do not rely on stale Wave2/Wave3 or recovered-source material. | High | Evidence sources are current by-* docs, current/generated reports as leads, executed B001/A004 history, and IDA MCP. No Wave2/Wave3/recovered-source material was used. | Report blocker-closure section and checklist. | not-applicable | already-present | Blocker-closure text remains in place; implementation edits cite current MCP session `07c55da0`, current by-* docs, and validator-generated state, not stale Wave2/Wave3/recovered-source material. |
| C023 | Generated output should refresh only through scoped validators, and `auto-generated/NexusTK/map/AttachedObjectPane.cpp` should be inspected read-only after `--wait-generated`. | Medium-high | Validator workflow; current generated file has UID000350 empty marker. | Validator plan/checklist; no generated-file edit. | incorporate | applied | Full scoped validators refreshed generated output through validator command `000000000267`; read-only inspection shows `auto-generated/NexusTK/map/AttachedObjectPane.cpp` UID000350 at `87/91` with no `Empty Emitter Marker`. |
| C024 | No IDA rename/type/comment or IDA DB edit is recommended for this task. | High | Target is documentation/source-output marker work; IDA DB edits are prohibited by assignment. | Report/checklist only. | not-applicable | applied | No IDA MCP write operation, rename, type, comment, or IDB save was performed during implementation. |

## Support-Doc Edit List

Required if the supervisor accepts the report:

| File | Required implementation edit |
| --- | --- |
| `by-memory/0x00620544-0x006205f8.AttachedObjectPaneVtableData.md` | Update score to `87/91`; keep owner/emitter/reconstructable route; insert the exact formal no-raw-vtable marker; replace stale parent-blank summary; add current MCP session evidence, dword/layout evidence, xref/vptr-store evidence, destructor/adjusted-thunk proof, boundary/negative evidence, rejected alternatives, and score rationale at report-level detail. |
| `by-class/AttachedObjectPane.md` | Add a concise support note that B012 current MCP session `07c55da0` reconfirmed [UID:000350] as class-owned compiler-emitted RTTI/vtable data, and that the target should emit a no-raw-vtable marker rather than raw arrays. Keep class score/metadata/formal C++ unchanged unless supervisor broadens scope. |
| `by-file/AttachedObjectPane.md` | Add a concise source-module note that `AttachedObjectPane.cpp` covers [UID:000350] through the class declaration, destructor wrappers, and virtual methods, not a handwritten vtable table. Keep file score/metadata/formal C++ unchanged. |
| `by-memory/0x005380b0-0x005387a3.AttachedObjectPane.md` | Repair stale summary/gate wording: the source range is no longer parent-blank for below-gate reasons, and its vtable child [UID:000350] is resolved as a marker-only generated-binary child. Preserve existing constructor/destructor/attach/detach evidence. |
| `by-memory/0x00620284-0x00620c74.ObjectPaneReadOnlyData.md` | Repair the [UID:000350] exact-child row from old "blank; class `82/88`" wording to assigned to [UID:00000M] after the class gate cleared. Keep aggregate score, owner blank, and `RECONSTRUCTABLE:FALSE` unchanged. |
| `by-memory/0x00620498-0x00620544.FlyingObjectPaneVtableData.md` | No required edit. Preserve predecessor boundary; edit only if the supervisor explicitly requests neighbor support sync. |
| `by-memory/0x006205f8-0x006206ac.EffectObjectPaneVtableData.md` | No required edit for this target. It has its own stale summary issue but is outside UID000350 unless the supervisor explicitly broadens scope. |
| Generated files/reports | Do not edit manually. Scoped validators should refresh generated output after accepted by-* edits. |

Do not edit `by-memory/-coverage-report.md`, `by-class/-coverage-report.md`, `by-file/-coverage-report.md`, `auto-generated/*`, `project-level/*`, validator state, leaser state, generated C++ by hand, executed research archives, or the IDA DB.

## Validator Plan For Implementation Callback

Run scoped validators from `source-3/project-documentation` after accepted by-* edits:

> Executable block R001 was removed from this report and preserved verbatim in [000350-AttachedObjectPaneVtableData-empty-emitter-source-quality-removed.md](000350-AttachedObjectPaneVtableData-empty-emitter-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

If optional neighbor docs are edited, validate each touched neighbor file with the same scoped file-mode validator. After validation, inspect generated output read-only:

> Executable block R002 was removed from this report and preserved verbatim in [000350-AttachedObjectPaneVtableData-empty-emitter-source-quality-removed.md](000350-AttachedObjectPaneVtableData-empty-emitter-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

Expected generated result:

- `auto-generated/NexusTK/map/AttachedObjectPane.cpp` has a `validator-command-id` / `validator-refreshed-at` equal to or newer than the final `--wait-generated` command.
- The [UID:000350] row no longer says `Empty Emitter Marker`; it carries the formal no-raw-vtable marker text from the target.
- Other empty markers in the generated file remain untouched unless separately validated by their own accepted reports.

## Residual Risks

- Exact original source spelling for every inherited ObjectPane-family virtual slot remains descriptive in surrounding docs. This does not block [UID:000350] because ownership/range/source disposition is proven by RTTI/vtable names, constructor/destructor vptr stores, and adjusted thunks.
- [UID:00000M] and [UID:0000HJ] still withhold final formal class/file C++ due broader field names, helper naming, source folding, and overlay-boundary questions. That keeps [UID:000350] below final-audit scores but does not affect the no-raw-vtable marker.
- Generated tracker/coverage rows are stale relative to current source docs and should refresh only through validator/generator flow.
- Neighbor [UID:000351] `EffectObjectPaneVtableData` has a similar stale summary/empty-emitter issue, but it is a separate target and should not be silently changed during UID000350 implementation.

## Open Question And Blocker Closure

No named UID000350 blocker remains deferred.

| Issue / blocker named in report | Resolution for supervisor review |
| --- | --- |
| Target summary/body contradiction | Resolved. Current source docs and MCP evidence support the body/header owner route, not the old summary. Implementation must replace the stale parent-blank summary and historicalize/reject the old `82/88` gate state in support docs. |
| Empty emitter / blank formal C++ | Resolved. The target is above the code-entry gate, has valid `EMITTER_UIDS:00000M`, and has a target-specific no-raw-vtable marker. Rare blank no-code is rejected. |
| Exact RTTI/vtable range and adjusted views | Resolved. Original full evidence and revision session `07c55da0` confirm `0x00620544-0x006205f8`, primary and adjusted views, constructor/destructor stores, and predecessor/successor boundaries. No split/merge remains open. |
| Owner/emitter route | Resolved. Keep [UID:00000M] as canonical owner/emitter; direct file [UID:0000HJ] remains support/source module, not direct target owner. |
| Broad `ObjectPaneReadOnlyData` aggregate | Resolved. It stays non-emitting and owner blank; only its stale [UID:000350] child row/changes note should be repaired. |
| Class/file final formal C++ blockers | Explicitly excluded from target score movement beyond `87/91`. They belong to broader [UID:00000M]/[UID:0000HJ] class/file reconstruction, not to this exact `.rdata` vtable child. They cap confidence below final-audit but do not block the formal marker. |
| Inherited ObjectPane-family slot names | Explicitly nonblocking for UID000350. The exact slot dword inventory and source-method refs should be preserved, but final original spelling for inherited virtual methods is a broader class-family issue and not required to resolve the no-raw-vtable marker. |
| Generated tracker/coverage staleness | Converted to implementation-ready validator work. Do not edit generated files; run scoped validators and inspect generated output read-only after `--wait-generated`. |
| Neighbor [UID:000351] stale summary/empty emitter | Explicitly excluded by assignment scope. It is a separate target; UID000350 implementation must not silently change it. |
| Wave2/Wave3 or recovered-source reliance | Closed. No Wave2/Wave3 or recovered-source material is used as evidence in this report. Current evidence comes from IDA MCP, current by-* docs, generated files as read-only state, and searched historical B/A reports as historical leads only. |
| IDA DB rename/type/comment edits | Excluded by assignment. No IDA DB edit is needed or allowed for this report. |
| Manual coverage/tracker edits | Excluded by assignment. Validator-owned generated reports should refresh from by-* source docs; no manual `-coverage-report.md` text is requested. |

## Implementation Tracking Checklist

Implementation callback status after supervisor acceptance. All accepted items are applied, already present, or excluded with reason.

| Step | Required callback work | File-specific proof to record during callback |
| --- | --- | --- |
| [x] Supervisor validation | Supervisor accepts this revised report for implementation and provides an implementation callback. | Current user callback accepted this report for implementation and references [UID:000350] plus this report path. |
| [x] Lease only active edit set | Check current leases, then lease only the by-* files being edited in the immediate batch. Do not lease generated/manual coverage/tool-state files. | B012 leased the five accepted by-* edit paths before editing. Final unlease attempt for all five paths reported `Rejected[No active lease]`, and `tools/leaser/Agents/current_leases.md` now says `No active leases.` |
| [x] Update Claim And Incorporation Ledger | For each ledger row C001-C024, update `Verification state` after implementation to `applied`, `already-present`, `excluded-with-reason`, or `blocked`. | Ledger rows C001-C024 above now carry workflow-valid states and proof; no `proposed` rows remain. |
| [x] Update target metadata | In `by-memory/0x00620544-0x006205f8.AttachedObjectPaneVtableData.md`, set `COMPLETION:87`, `CONFIDENCE:91`; preserve `CANONICAL_OWNER:00000M`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:00000M`, and blank `EMITTER_POSITION_OPTIONAL`. | Target header now shows `87/91`, owner/emitter `00000M`, `RECONSTRUCTABLE:TRUE`, and blank emitter position. Full target validator command `000000000262` at `2026-06-29T01:27:53-04:00` exited 0 with `ok:1`; post-restore target `--uid-only` command `000000000269` at `2026-06-29T01:30:08-04:00` exited 0 with `ok:1`. |
| [x] Insert exact target formal marker | In the target multiline `RECONSTRUCTION_CPP CODE` block, insert exactly the no-raw-vtable marker from the Executive Conclusion; keep inline `RECONSTRUCTION_CPP CODE:[[[]]]` blank. | Target multiline C++ block contains the exact plain marker. Full validator reference phase link-expanded UID annotations, so the target block was restored to exact text afterward and confirmed by `--uid-only` command `000000000269`; inline C++ remains blank. |
| [x] Replace target stale summary | In the target `Item Summary`, remove the parent-blank/class-`82/88` claim and use the current assigned/no-raw-vtable summary from `Score And Metadata Recommendation`. | Target summary now assigns UID000350 to [UID:00000M], lists current MCP proof, and describes the formal no-raw-vtable marker; stale `82/88` wording is only retained as historical/resolved context in body/change notes. |
| [x] Incorporate target evidence at report detail | In the target body, add/preserve current MCP session `07c55da0`, exact bytes/dwords, RTTI/vtable bases, constructor/destructor vptr stores, scalar deleting destructor, adjusted thunks, predecessor/successor boundaries, negative evidence, rejected alternatives, and score rationale. | Target now contains `B012 Current MCP Evidence`, `Dword Layout And Slot Roles`, `Boundary And Negative Evidence`, `Score Rationale`, and Changes entries covering all accepted evidence details. |
| [x] Update class support note | In `by-class/AttachedObjectPane.md`, add B012 evidence that session `07c55da0` reconfirmed [UID:000350] as class-owned compiler-emitted RTTI/vtable data covered by class declarations/methods, not raw arrays. Keep class score, metadata, and formal C++ unchanged. | Class Evidence Notes and Changes sections now include the B012 UID000350 support note; class score/metadata/formal C++ are unchanged. Scoped class validator batch item `000000000263` exited 0. |
| [x] Update file support note | In `by-file/AttachedObjectPane.md`, add source-module wording that [UID:000350] is regenerated through `AttachedObjectPane.cpp` declarations, destructor wrappers, and virtual method definitions, not a hand-authored vtable table. Keep file score, metadata, and formal C++ unchanged. | File Proposed Contents, IDA MCP Evidence, File-Root State, and Changes sections now carry the no-raw-vtable source route; file score/metadata/formal C++ are unchanged. Scoped file validator batch item `000000000264` exited 0. |
| [x] Repair source-range support wording | In `by-memory/0x005380b0-0x005387a3.AttachedObjectPane.md`, repair stale gate/summary wording and note that [UID:000350] is now marker-only generated-binary coverage; preserve constructor/destructor/attach/detach evidence. | Source-range Item Summary, Evidence Details, and Change Log now record UID000350 marker-only generated-binary coverage and preserve the existing executable-cluster evidence. Scoped source-range validator batch item `000000000265` exited 0. |
| [x] Repair aggregate child row | In `by-memory/0x00620284-0x00620c74.ObjectPaneReadOnlyData.md`, update the [UID:000350] exact-child row/changes note from old blank/class-`82/88` wording to assigned to [UID:00000M]. Keep aggregate score, owner blank, and `RECONSTRUCTABLE:FALSE` unchanged. | Aggregate child row, B012 evidence note, and Changes section now record UID000350 as assigned to [UID:00000M]; aggregate header remains owner blank and `RECONSTRUCTABLE:FALSE`. Scoped aggregate validator batch item `000000000266` exited 0; final generated refresh completed as `000000000267`. |
| [x] Preserve neighbor boundaries without editing neighbor pages | Do not edit `by-memory/0x00620498-0x00620544.FlyingObjectPaneVtableData.md` or `by-memory/0x006205f8-0x006206ac.EffectObjectPaneVtableData.md` unless a new supervisor callback explicitly adds them. | Ledger C019/C020 are `excluded-with-reason`; neighbor pages were read as boundary evidence and not edited. |
| [x] Preserve exclusions | Do not edit generated reports, generated C++ files, project-level generated files, manual `-coverage-report.md` files, validator/tool state, lock files, executed research archives, IDA DB, or supervisor ledgers; do not run `execute_report`. | No forbidden file was manually edited. Generated outputs and validator metadata changed only through validator runs; no manual coverage reports, lock files, executed archives, IDA DB, or supervisor ledgers were edited, and `execute_report` was not run. |
| [x] Confirm Wave2/Wave3 non-reliance | Preserve the report's statement that no stale Wave2/Wave3/recovered-source material supports the recommendation. | Blocker-closure text remains; implementation edits cite current MCP `07c55da0`, current by-* docs, and validator-generated state rather than stale Wave2/Wave3/recovered-source material. |
| [x] Run target validator | From `source-3/project-documentation`, run `python .\tools\validator.py --mode file --file by-memory\0x00620544-0x006205f8.AttachedObjectPaneVtableData.md --apply --queue-timeout 240 --wait-generated`. | Full target validator command `000000000262`, timestamp `2026-06-29T01:27:53-04:00`, exited 0 with `ok:1`; post-restore target `--uid-only` command `000000000269`, timestamp `2026-06-29T01:30:08-04:00`, exited 0 with `ok:1` and `generated_refresh: skipped` by `--uid-only`. |
| [x] Run class validator | Run `python .\tools\validator.py --mode file --file by-class\AttachedObjectPane.md --apply --queue-timeout 240 --wait-generated`. | Scoped class validator ran in the five-file batch and exited 0; batch command sequence advanced through `000000000263`, with final generated refresh reaching `000000000267`. |
| [x] Run file validator | Run `python .\tools\validator.py --mode file --file by-file\AttachedObjectPane.md --apply --queue-timeout 240 --wait-generated`. | Scoped file validator ran in the five-file batch and exited 0; batch command sequence advanced through `000000000264`, with final generated refresh reaching `000000000267`. |
| [x] Run source-range validator | Run `python .\tools\validator.py --mode file --file by-memory\0x005380b0-0x005387a3.AttachedObjectPane.md --apply --queue-timeout 240 --wait-generated`. | Scoped source-range validator ran in the five-file batch and exited 0; batch command sequence advanced through `000000000265`, with final generated refresh reaching `000000000267`. |
| [x] Run aggregate validator | Run `python .\tools\validator.py --mode file --file by-memory\0x00620284-0x00620c74.ObjectPaneReadOnlyData.md --apply --queue-timeout 240 --wait-generated`. | Scoped aggregate validator ran in the five-file batch and exited 0; visible batch tail shows `VALIDATOR_EXIT by-memory\0x00620284-0x00620c74.ObjectPaneReadOnlyData.md 0`, and generated output now carries validator command `000000000267`. |
| [x] Inspect generated output read-only | After the final `--wait-generated`, inspect `auto-generated/NexusTK/map/AttachedObjectPane.cpp` read-only for [UID:000350]; it should show the formal marker and no longer show `Empty Emitter Marker`. Do not edit generated output. | Read-only inspection shows `auto-generated/NexusTK/map/AttachedObjectPane.cpp` header `validator-command-id: 000000000267`, `validator-refreshed-at: 2026-06-29T01:28:52-04:00`, and UID000350 at `Completion:87 | Confidence:91` with the no-raw-vtable marker; UID000350 no longer has `Empty Emitter Marker` in generated output. |
| [x] Release leases | Release all B012 leases immediately after the edit/validator batch, or verify they already expired and no active B012 lease remains. | Final unlease command for all five by-* paths reported `Rejected[No active lease]`; `tools/leaser/Agents/current_leases.md` says `No active leases.` |
| [x] Final implementation report | Report changed files, unchanged excluded files, validators, generated-refresh state, ledger/checklist states, score before/after, owner/emitter unchanged, no split/rename/new child, and no-code marker proof. | Ready for final callback response: all ledger/checklist rows are resolved, target moved `85/88 -> 87/91`, owner/emitter unchanged, no split/rename/new child, and the exact no-raw-vtable marker is present in the target. |

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B012","command_id":"000000004165","destination_path":"executed-b-agent-research/B012/000350-AttachedObjectPaneVtableData-empty-emitter-source-quality.md","details":"legacy registry reconstruction","event":"executed","source_path":"tools/leaser/Agents/Agent-B012/research/000350-AttachedObjectPaneVtableData-empty-emitter-source-quality.md","timestamp":"2026-06-29T01:42:10","uid":"000350"} -->
<!-- {"agent":"B012","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 000350-AttachedObjectPaneVtableData-empty-emitter-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B012/000350-AttachedObjectPaneVtableData-empty-emitter-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"000350"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
