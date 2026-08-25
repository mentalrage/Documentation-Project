** TARGET-REPORT-UID:00017Y **
** AUTHOR-AGENT-ID:B013 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **

# 00017Y ItemObjImageLibSingletonClearHelper Source-Quality Research

## Finalized Report / Current Recommendation

- Target: [UID:00017Y] `by-memory/0x004e5ba0-0x004e5bab.ItemObjImageLibSingletonClearHelper.md`.
- Current recommendation: keep the target reconstructable, file-owned, and routed through [UID:0000KH] `ItemObjImageLib`, but resolve the source form as compiler-generated constructor EH cleanup glue. Do not hand-port this helper as source C++.
- Required target action if accepted: raise from `85/90` to `87/93`; keep `CANONICAL_OWNER:0000KH`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000KH`, and blank `EMITTER_POSITION_OPTIONAL`; keep the formal C++ block empty.
- Final disposition: file-level singleton lifetime helper for `g_pItemObjImageLib`, reached only through the `ItemObjImageLib` constructor SEH/C++ unwind funclet at `0x00600158`. The source-owned effect is the constructor/destructor/global lifetime state, not an independently authored `ClearSingleton` function or class method.
- Confidence: very strong for exact range, body, global target, SEH cleanup route, no ordinary caller/callee state, no literal pointer-table route, and owner/source placement. Remaining uncertainty is only final original class/header/singleton declaration spelling and whether the compiler emits the same funclet shape from the final reconstructed source.

## Target

- Target UID: `00017Y`.
- Target path: `by-memory/0x004e5ba0-0x004e5bab.ItemObjImageLibSingletonClearHelper.md`.
- Required report path: `tools/leaser/Agents/Agent-B013/research/00017Y-ItemObjImageLibSingletonClearHelper-source-quality.md`.
- Assignment id: `B013-report-00017Y-ItemObjImageLibSingletonClearHelper-source-quality-20260627`.
- Current metadata in target page: `COMPLETION:85`, `CONFIDENCE:90`, `CANONICAL_OWNER:0000KH`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000KH`, blank `RECONSTRUCTION_CPP CODE`.
- Current support state: class [UID:00006W] is `88/89`, file [UID:0000KH] is `89/86`, global [UID:0000RA] is `88/89`, storage child [UID:0001OT] is `86/90`, and local cluster [UID:00017N] is a non-emitting `86/90` container.
- Current generated state observed read-only: `auto-generated/-ag-memory-coverage.md` shows [UID:00017Y] routed through [UID:0000KH] but `no` code. `auto-generated/-ag-research-tracker.md` and `auto-generated/-ag-coverage-report-by-memory.md` still show stale `78/90` target score data. Do not edit generated files manually.

## Current Target State

The page already records the exact two-instruction body, the singleton storage, neighboring helper boundaries, no direct ordinary callers/callees, and the broad 65-reference lifecycle/consumer set for `g_pItemObjImageLib`.

The remaining source-quality blocker was the source role:

- It is not an ItemObjImageLib class method. The helper has no arguments, no `this` read, no callees, and only writes the singleton.
- It is not a public or file-local handwritten API. There is no ordinary callsite and no direct VA/RVA/literal pointer route to the function start.
- It is not an unresolved static-lifetime black box anymore. Current MCP shows a constructor-associated SEH cleanup funclet at `0x00600158` that tail-jumps to this helper, and the constructor prologue installs `SEH_4DEC30` at `0x004dec35`.
- It should stay reconstructable because it is source-owned lifecycle state for `ItemObjImageLib`, but the exact bytes should be regenerated from constructor/global cleanup semantics rather than hand-written as a `ClearSingleton` function.

## Evidence Checked

Project/workflow files read:

- `tools/leaser/Agents/Agent-B013/goal.md`.
- Project-level `ntk-b-agent-workflow` skill and required workflow references.
- `by-structure.md` and the by-memory guidance already loaded for this B-agent workflow.

Target/support docs checked:

- [UID:00017Y] `by-memory/0x004e5ba0-0x004e5bab.ItemObjImageLibSingletonClearHelper.md`.
- [UID:00017N] `by-memory/0x004dec30-0x004df500.ItemObjImageLibLocalMethodCluster.md`.
- [UID:00017O] `by-memory/0x004dee20-0x004dee4d.ItemObjImageLibDestructor.md`.
- [UID:0002VC] `by-memory/0x004e6580-0x004e65dc.ItemObjImageLibScalarDeletingDestructor.md`.
- [UID:00006W] `by-class/ItemObjImageLib.md`.
- [UID:0000KH] `by-file/ItemObjImageLib.md`.
- [UID:0000RA] `by-global/g_pItemObjImageLib.md`.
- [UID:0001OT] `by-memory/0x0067a758-0x0067a75c.g_pItemObjImageLib.md`.
- Comparable singleton-clear helper pages for EffectObjImageLib, LightObjImageLib, MapTileImageLib, and MonsterImageLib.

Generated/current-state files checked read-only:

- `auto-generated/-ag-memory-coverage.md`.
- `auto-generated/-ag-research-tracker.md`.
- `auto-generated/-ag-coverage-report-by-memory.md`.

Prior reports used as leads and rechecked against current docs/MCP:

- Executed B002 report [UID:00017O] `executed-b-agent-research/B002/00017O-ItemObjImageLibDestructor-source-quality.md`.
- Executed B014 report [UID:0002VC] `executed-b-agent-research/B014/0002VC-ItemObjImageLibScalarDeletingDestructor-source-quality.md`.
- Current by-* implementations resulting from those reports.

## MCP Evidence Baseline

Current live IDA MCP session used for this report:

- Endpoint: `http://127.0.0.1:13337/mcp`.
- Session: `b001_000241_20260627`.
- `idb_list`: one active worker session for `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, worker PID `23132`, `is_analyzing:false`, `is_active:true`.
- `server_health b001_000241_20260627`: `status:"ok"`, module `NexusTK.exe`, IDB path `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, input path `C:\Users\admin\Desktop\Clone\NexusTK\NexusTK.exe`, imagebase `0x400000`, `auto_analysis_ready:true`, `hexrays_ready:true`, `strings_cache_ready:true`.
- Evidence collection time: 2026-06-27 local pass window.

Integer conversions checked with `tools/int_convert.py` and MCP `int_convert`:

- `0xb = 11` bytes.
- `0x05 = 5` bytes.
- `0x04 = 4` bytes.

## IDA MCP Facts

### Function and boundary facts

| Query | Current MCP result | Meaning |
| --- | --- | --- |
| `lookup_funcs 0x004e5ba0` | `sub_4E5BA0`, size `0xb` | Exact target function `0x004e5ba0-0x004e5bab`, size 11 bytes. |
| `lookup_funcs 0x004e5baa` | inside `sub_4E5BA0` | Last instruction is inside the target. |
| `lookup_funcs 0x004e5bab` | not a function | Confirms end-exclusive boundary. |
| `lookup_funcs 0x004e5bb0` | `sub_4E5BB0`, size `0xb` | Neighboring LightObjImageLib clear helper starts after padding. |
| `lookup_funcs 0x004dec30` | `sub_4DEC30`, size `0x1eb` | Constructor owning the SEH cleanup route. |
| `lookup_funcs 0x004dee20` | not a function | Ordinary raw destructor remains separate and unmodeled. |
| `lookup_funcs 0x004e6580` | `sub_4E6580`, size `0x5c` | Scalar deleting destructor remains separate. |

`get_bytes 0x004e5ba0 size 27` returns the complete helper bytes followed by padding and the next helper start:

```text
c7 05 58 a7 67 00 00 00 00 00 c3 cc cc cc cc cc c7 05 50 b4 69 00 00 00 00 00 c3
```

Interpretation:

- `0x004e5ba0-0x004e5bab`: `c7 05 58 a7 67 00 00 00 00 00 c3`, the full target body.
- `0x004e5bab-0x004e5bb0`: five `0xcc` bytes.
- `0x004e5bb0`: next singleton helper, not part of this target.

### Behavior facts

Current decompilation:

```text
void sub_4E5BA0()
{
  dword_67A758 = 0; /*0x4e5ba0*/
}
```

Current disassembly:

```asm
0x004e5ba0  mov dword_67A758, 0
0x004e5baa  retn
```

`analyze_function 0x004e5ba0` reports:

- Prototype: `void()`.
- Size: 11 bytes.
- Basic blocks: 1.
- Cyclomatic complexity: 1.
- Strings: none.
- Constants: none.
- Callees: none.
- Ordinary callers: none.
- Xrefs to the helper: one code xref from `0x00600158`.
- Xrefs from the helper: data ref to `0x0067a758` and the normal code-flow xref to `0x004e5baa`.

### Constructor SEH cleanup route

Current MCP resolves the only incoming helper route as constructor SEH/C++ unwind cleanup:

| Query | Current result | Meaning |
| --- | --- | --- |
| `xrefs_to 0x004e5ba0` | one xref from `0x00600158`, type `code`, function context `sub_4DEC30` | The helper is reached by constructor-associated cleanup code, not ordinary source calls. |
| `find code_ref 0x004e5ba0` | one match at `0x00600158` | Confirms the same route. |
| `find data_ref 0x004e5ba0` | zero matches | No data-table pointer route to the helper. |
| `find_bytes a0 5b 4e 00` | zero matches | No direct VA literal pointer bytes for `0x004e5ba0`. |
| `find_bytes a0 5b 0e 00` | zero matches | No direct RVA literal pointer bytes for `0x004e5ba0`. |

Constructor prologue:

```asm
0x004dec33  push 0FFFFFFFFh
0x004dec35  push offset SEH_4DEC30
0x004dec3a  mov eax, large fs:0
0x004dec54  mov large fs:0, eax
```

SEH/C++ frame handler block:

```asm
0x00600152  mov ecx, [ebp+var_4C]
0x00600155  add ecx, 4
0x00600158  jmp sub_4E5BA0
0x0060015d  mov ecx, [ebp+var_4C]
0x00600160  add ecx, 4
0x00600163  jmp loc_4E5B10
0x00600168  lea ecx, [ebp+var_40]
0x0060016b  jmp sub_49C160
0x00600170  SEH_4DEC30:
0x0060018b  mov eax, offset stru_65DEA0
0x00600190  jmp ___CxxFrameHandler3
```

Interpretation:

- The constructor installs `SEH_4DEC30`; the handler uses `___CxxFrameHandler3`.
- The helper route is a cleanup funclet jump immediately before `SEH_4DEC30`, associated by MCP with `sub_4DEC30`.
- The funclet loads the constructor's saved object pointer and adds `4`, but `sub_4E5BA0` ignores `ecx` and clears only the global. This shape matches generated cleanup glue, not source-authored API code.
- Neighboring funclets in the same constructor cleanup region jump to `LObject` cleanup, `ProtectedArray<ItemInfo>` cleanup at `0x004e5b10`, and DATFile cleanup at `0x0049c160`. This places [UID:00017Y] in the constructor unwinding cleanup set.

### Singleton lifecycle facts

`xrefs_to 0x0067a758` reports 65 direct xrefs. Lifecycle refs include:

| Address | Function context | Meaning |
| --- | --- | --- |
| `0x004dec7b` | `sub_4DEC30` | Constructor publishes the constructed object pointer. |
| `0x004dec82` | `sub_4DEC30` | Constructor fallback/guard path clears the singleton. |
| `0x004dee3b` | raw [UID:00017O] ordinary destructor body | Ordinary cleanup clears the singleton. |
| `0x004e5ba0` | this target | Constructor EH cleanup helper clears the singleton. |
| `0x004e659e` | `sub_4E6580` scalar deleting destructor | Deleting destructor clears the singleton. |

`insn_query 0x004dec30-0x004e6600 op_any 0x0067a758` finds exactly those five lifecycle writes in the ItemObjImageLib lifecycle span. The same scoped query for the `ItemObjImageLib` vtable `0x0061b73c` finds constructor, raw destructor, and scalar deleting destructor stores; the helper does not touch vtables or object fields.

### Component and neighboring helper facts

`analyze_component 0x004dec30,0x004dee20,0x004e5ba0,0x004e6580` reports:

- Constructor `sub_4DEC30`: modeled function with constructor/resource loading callees.
- Ordinary destructor `0x004dee20`: no function.
- Scalar deleting destructor `sub_4E6580`: modeled function, size 92 bytes.
- This helper `sub_4E5BA0`: size 11, no callees, one block.
- Internal call graph: no ordinary edges between the selected functions.
- Shared globals: `ProtectedArray<ItemInfo>` vtable, `ItemObjImageLib` vtable, and `dword_67A758`; the singleton is shared by constructor, this helper, and scalar deleting destructor.

Neighboring bytes around `0x004e5b90` show the image-library clear-helper island:

```text
0x004e5b90  c7 05 44 a7 67 00 00 00 00 00 c3  ; prior singleton clear helper
0x004e5b9b  cc cc cc cc cc
0x004e5ba0  c7 05 58 a7 67 00 00 00 00 00 c3  ; ItemObjImageLib helper
0x004e5bab  cc cc cc cc cc
0x004e5bb0  c7 05 50 b4 69 00 00 00 00 00 c3  ; LightObjImageLib helper
```

Do not merge this helper with adjacent helpers; each `0xb` body writes a distinct singleton global.

## Heuristic / Inference Reanalysis And Validation

### 1. Is this a source-authored helper?

Decision: no, not as an independent source function.

Evidence:

- The helper has no ordinary callers and no callees.
- Its only incoming route is `jmp sub_4E5BA0` from the constructor-associated SEH funclet at `0x00600158`.
- It has no direct data-ref route, no VA pointer bytes, and no RVA pointer bytes.
- The helper ignores `ecx`, even though the cleanup funclet computes a subobject pointer before the jump.
- Neighboring constructor cleanup funclets tail-jump to cleanup routines for base/member/local objects. This helper belongs to that generated cleanup set.

Rejected alternatives:

- Emit `static void ClearItemObjImageLibSingleton() { g_pItemObjImageLib = 0; }`. Rejected because that would invent a handwritten source helper where the only live route is compiler EH cleanup.
- Treat it as `ItemObjImageLib::ClearSingleton`. Rejected because the target has no class-method shape and no source callsite; the class page's method-table wording should be corrected.
- Treat it as unused/dead code. Rejected because MCP reports a constructor cleanup code xref at `0x00600158`.

### 2. What is the static-lifetime/EH mechanism?

Decision: this exact binary helper is constructor EH cleanup glue for the `ItemObjImageLib` singleton state.

Evidence:

- The constructor installs `SEH_4DEC30` at `0x004dec35` and uses `___CxxFrameHandler3`.
- The helper xref is a cleanup funclet jump inside the same constructor-associated SEH region.
- The constructor publishes `g_pItemObjImageLib` at `0x004dec7b` before later object/member/resource initialization work that can require cleanup on unwind.
- The helper's only effect is to clear that published singleton.

Static-lifetime wording:

- The broader source state is a process-wide singleton owned by `ItemObjImageLib.cpp`.
- The observed helper itself is not proven to be a CRT `atexit` or static-destructor table callback; the current route is constructor SEH cleanup.
- Normal lifetime cleanup is already represented by [UID:00017O] ordinary destructor and [UID:0002VC] scalar deleting destructor. This helper covers construction-unwind singleton clearing.

### 3. Should this remain reconstructable/emitting?

Decision: yes, keep reconstructable and routed, but with blank formal C++.

Evidence:

- The helper mutates project-owned singleton state and must be accounted for by the rebuilt source.
- Owner and source route are strong: `ItemObjImageLib.cpp` owns the singleton, constructor, ordinary destructor, scalar deleting destructor, and consumers.
- The helper shape is generated cleanup glue. The source should express the equivalent constructor/global lifetime semantics and let the compiler/runtime emit the funclet as needed.

Rejected alternatives:

- `RECONSTRUCTABLE:FALSE`: rejected because the behavior is not padding, thunk-only noise, or third-party runtime code. It is project singleton cleanup state.
- Comment-only formal marker in this exact page: not recommended in this report. The established sibling singleton-clear helper policy is blank formal C++ plus explicit no-code proof. Comment-only markers are already used for the class-routed scalar deleting destructor wrapper [UID:0002VC], where generated coverage needed an ABI-wrapper marker. If the project later standardizes comment markers for all singleton EH cleanup helpers, it should do that coherently across the helper island rather than only for [UID:00017Y].
- Standalone C++ body: rejected because it would pollute `ItemObjImageLib.cpp` with generated EH cleanup source and could duplicate constructor/destructor singleton semantics.

### 4. Direct owner and emitter route

Decision: keep [UID:0000KH] `ItemObjImageLib` as direct owner/emitter.

Evidence:

- The helper writes only [UID:0000RA] `g_pItemObjImageLib`, which is owned by the `ItemObjImageLib` module.
- The only incoming route is constructor-associated cleanup for `sub_4DEC30`, which is file/module-owned and already routed through [UID:0000KH].
- The helper has no `this` use and no class API shape, so direct class ownership [UID:00006W] is weaker than file/source-root ownership for this exact helper.
- The analogous EffectObjImageLib, LightObjImageLib, MapTileImageLib, and MonsterImageLib singleton-clear helpers are file-owned blank-C++ cleanup glue.

Rejected alternatives:

- Direct class owner [UID:00006W]: rejected for this exact helper because the helper is not a method, unlike the scalar deleting destructor [UID:0002VC].
- Global owner [UID:0000RA]: rejected because the global is state touched by the helper, not the source owner of the helper mechanism.
- Local cluster [UID:00017N]: rejected because it is a non-emitting index/container. Exact child/tail pages carry ownership.
- Neighboring image-library file owners: rejected by the `0x0067a758` target global and constructor SEH route.

### 5. Range, split, and padding

Decision: no split or merge.

Evidence:

- `lookup_funcs` reports `sub_4E5BA0` size `0xb`.
- `0x004e5bab` is not a function and is the correct end-exclusive boundary.
- `0x004e5bab-0x004e5bb0` is five `0xcc` bytes before the LightObjImageLib helper.
- The previous and next helper bodies write different singleton addresses.

## First-Draft C++ Recommendation

- Eligible for source accounting: yes. The target is `RECONSTRUCTABLE:TRUE`, routed through [UID:0000KH], and current/recommended scores are above the active code-entry gate.
- Recommended formal C++ content: keep blank.
- Reason: the target is generated constructor EH cleanup glue. Original source should be represented by `ItemObjImageLib` singleton state, constructor publication/failure cleanup, and destructor cleanup, not by a named helper body.
- Source-facing wording to use in prose: "constructor SEH cleanup helper" or "constructor-unwind singleton clear helper."
- Source-facing wording to avoid: `ItemObjImageLib::ClearSingleton`, `ClearItemObjImageLibSingleton`, `atexit callback`, or "direct static destructor table callback" unless future MCP/IDA evidence proves a different route.

Formal block should remain:

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

## Recommended Target Doc Changes

Target path: `by-memory/0x004e5ba0-0x004e5bab.ItemObjImageLibSingletonClearHelper.md`.

Recommended metadata:

```text
*** COMPLETION:87 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:93 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000KH | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000KH | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
```

Recommended `Item Summary` replacement:

```text
Constructor SEH cleanup helper for ItemObjImageLib singleton state; current MCP confirms exact 0xb mov/retn body clearing dword_67A758, one constructor cleanup jump at 0x00600158, no ordinary callers/callees, no VA/RVA/data pointer route, 65 singleton xrefs, and blank-C++ generated cleanup-glue disposition.
```

Recommended prose updates:

- Replace "final helper spelling/static-lifetime mechanism remain below C++ emission confidence" with "current MCP resolves the route as constructor SEH cleanup glue; final C++ remains blank because this is generated cleanup funclet code, not a source-authored API."
- Add current MCP session `b001_000241_20260627`, server health, IDB/input paths, Hex-Rays ready state.
- Add exact lookup/decompile/disasm/analyze facts for `0x004e5ba0`.
- Add SEH route evidence: constructor `push offset SEH_4DEC30` at `0x004dec35`; cleanup funclet at `0x00600152-0x00600158`; handler uses `___CxxFrameHandler3`.
- Add pointer-route negatives: `find data_ref 0x004e5ba0` zero, VA bytes `a0 5b 4e 00` zero, RVA bytes `a0 5b 0e 00` zero.
- Preserve lifecycle refs to `0x0067a758` and neighboring helper boundary proof.
- Preserve rejected alternatives: no class-method naming, no standalone `ClearSingleton` source body, no no-owner/non-reconstructable downgrade, no merge with adjacent helpers.

## Recommended Support Doc Changes

### `by-class/ItemObjImageLib.md`

Add a narrow support sync:

- Change the method-table row label from `ItemObjImageLib::ClearSingleton` to a non-method label such as `ItemObjImageLib constructor SEH singleton cleanup helper` or `ItemObjImageLib singleton cleanup helper`.
- State that [UID:00017Y] is file-level/generated constructor cleanup glue, not a class method and not a source-authored API.
- Mention the current route `0x004dec35 -> SEH_4DEC30`, cleanup jump `0x00600158 -> 0x004e5ba0`, no ordinary callers/callees, and blank formal C++.
- No score change is required.

### `by-file/ItemObjImageLib.md`

Add a narrow source-root sync:

- [UID:00017Y] remains file-owned under [UID:0000KH] and routes to `NexusTK/render/ItemObjImageLib.cpp`.
- Current MCP resolves the helper as constructor SEH cleanup glue for singleton publication/unwind, not a handwritten file-local helper.
- The file remains responsible for equivalent singleton constructor/destructor semantics, while the exact helper formal C++ remains blank.
- No score/path change is required.

### `by-memory/0x004dec30-0x004df500.ItemObjImageLibLocalMethodCluster.md`

Add a narrow tail-page sync:

- Update the [UID:00017Y] related-tail row to say it is the constructor SEH singleton cleanup helper for `g_pItemObjImageLib`, reached via cleanup jump `0x00600158`.
- Keep it separate from the non-emitting cluster and from the scalar deleting destructor [UID:0002VC].
- No score change is required.

### `by-global/g_pItemObjImageLib.md`

Add a narrow lifecycle sync:

- Change the [UID:00017Y] write-site description from generic "tiny cleanup helper" to "constructor SEH/unwind cleanup helper that clears the singleton."
- Add current MCP evidence that `xrefs_to 0x0067a758` still reports 65 refs and that the lifecycle writes remain `0x004dec7b`, `0x004dec82`, `0x004dee3b`, `0x004e5ba0`, and `0x004e659e`.
- No score change is required.

### `by-memory/0x0067a758-0x0067a75c.g_pItemObjImageLib.md`

Add the same narrow lifecycle sync as the global page if supervisor wants storage-level wording aligned:

- [UID:00017Y] is the constructor SEH/unwind cleanup helper, not a source-authored normal call target.
- Current storage remains zero-initialized and still has 65 direct refs.
- No score change is required.

### Support pages checked and no edit required unless supervisor widens scope

- [UID:00017O] ordinary destructor already records the normal cleanup clear at `0x004dee3b` and the blank-C++ proof.
- [UID:0002VC] scalar deleting destructor already records the vtable-backed wrapper route, cleanup parity, and formal comment-only no-code marker.
- [UID:0001XW] vtable and [UID:0001UU] layout pages do not need this helper-specific SEH wording for the target to be source-quality.

## Score And Metadata Recommendation

Current target state:

- `COMPLETION:85`
- `CONFIDENCE:90`
- `CANONICAL_OWNER:0000KH`
- `RECONSTRUCTABLE:TRUE`
- `EMITTER_UIDS:0000KH`
- formal C++ blank

Recommended target state:

- `COMPLETION:87`
- `CONFIDENCE:93`
- `CANONICAL_OWNER:0000KH`
- `RECONSTRUCTABLE:TRUE`
- `EMITTER_UIDS:0000KH`
- formal C++ blank

Rationale:

- Completion rises because the previous source blocker is resolved: the helper is constructor SEH cleanup glue, not an unresolved static-lifetime or source-helper mystery.
- Confidence rises because current MCP independently confirms the live route, exact bytes, body, global xrefs, no-caller/no-callee state, and pointer-route negatives.
- Scores stay below final-audit range because the exact final source declaration/header/singleton mechanism still is not symbol-proven, and the rebuilt compiler's funclet shape cannot be guaranteed solely from this page.
- Owner/emitter stay [UID:0000KH] because this is file-level singleton cleanup glue with no class-method shape.

## Open Questions With Attempted Resolution

Resolved in this pass:

- Helper role: resolved as constructor SEH cleanup glue.
- Static-lifetime/EH route: resolved as `SEH_4DEC30` / `___CxxFrameHandler3` constructor unwind cleanup, not a normal source callsite.
- No-code disposition: resolved; keep formal C++ blank with explicit no-code proof.
- Owner route: resolved; keep direct file owner/emitter [UID:0000KH].
- Range/split: resolved; no split or merge.
- Global ownership: resolved; global is support state, not owner.

Remaining and score impact:

- Exact original source expression for the singleton remains not symbol-proven. It may be explicit assignment, singleton template/base machinery, or a compiler-specific constructor cleanup consequence.
- Final class/header declaration shape remains broader `ItemObjImageLib` work and should not be forced through this tiny helper.
- Sibling singleton-clear helpers use the same blank-C++ generated cleanup policy. Any future decision to add comment-only markers should be a coherent helper-island policy pass.

## Exact Manual Supervisor-Owned Coverage Or Tracker Text

No manual `-coverage-report.md` edit is requested or permitted for B013.

Generated observations for supervisor/validator only:

- `auto-generated/-ag-memory-coverage.md` currently shows [UID:00017Y] routed through [UID:0000KH] with no code.
- `auto-generated/-ag-research-tracker.md` currently shows stale `78/90` data for [UID:00017Y], despite the live target page being `85/90`.
- `auto-generated/-ag-coverage-report-by-memory.md` currently shows stale `78/90` text with the old unresolved static-lifetime wording.
- After implementation, run scoped validators on changed by-* pages and let validator/generated refresh handle generated Markdown. Do not edit generated files manually.

## Validator Plan For Implementation Callback

Run from `E:\NTK\GhidraBridge\source-3\project-documentation` after accepted by-* edits. Run only validators for files actually changed:

> Executable block R001 was removed from this report and preserved verbatim in [00017Y-ItemObjImageLibSingletonClearHelper-source-quality-removed.md](00017Y-ItemObjImageLibSingletonClearHelper-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

Do not run validators for generated/project-level files, coverage reports, validator/tool state, or unrelated by-* files. Record command id, timestamp, exit code, `ok` count, warnings, and generated-refresh state during implementation.

## Changed Files In Report-Only Pass

- Created: `tools/leaser/Agents/Agent-B013/research/00017Y-ItemObjImageLibSingletonClearHelper-source-quality.md`.
- No by-* docs edited.
- No generated files edited.
- No project-level files edited.
- No validator/tool state edited.
- No IDA DB edits made.
- No leases taken.

## Changed Files In Implementation Callback

- Updated target: `by-memory/0x004e5ba0-0x004e5bab.ItemObjImageLibSingletonClearHelper.md`.
- Updated support: `by-class/ItemObjImageLib.md`, `by-file/ItemObjImageLib.md`, `by-memory/0x004dec30-0x004df500.ItemObjImageLibLocalMethodCluster.md`, `by-global/g_pItemObjImageLib.md`, and `by-memory/0x0067a758-0x0067a75c.g_pItemObjImageLib.md`.
- No edit needed: [UID:00017O] already records ordinary destructor cleanup and blank-C++ proof; [UID:0002VC] already records scalar deleting destructor wrapper/no-code proof; [UID:0001XW] and [UID:0001UU] do not carry stale helper-specific SEH statements that block this target disposition.
- No generated reports, generated C++ files, manual `-coverage-report.md` files, IDA DB, MCP state, or unrelated docs were manually edited. Scoped validators performed their normal validator/projection bookkeeping and reported generated refresh deferred.

## Implementation Tracking Checklist

Report-only pass:

- [x] Read current B013 goal and project-level `ntk-b-agent-workflow` instructions.
- [x] Confirmed report-only scope: no by-* docs, generated/project-level files, IDA DB, tool state, or `-coverage-report.md` files edited.
- [x] Checked MCP health/session: `idb_list` and `server_health` for session `b001_000241_20260627` succeeded; active IDB is `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`.
- [x] Rechecked target boundary/body with MCP `lookup_funcs`, `get_bytes`, `decompile`, `disasm`, `analyze_function`, and `callees`.
- [x] Rechecked source route with MCP `xrefs_to`, `xref_query`, `find code_ref`, `find data_ref`, `find_bytes`, `disasm`, and `insn_query`; resolved the live route as constructor SEH cleanup jump `0x00600158 -> 0x004e5ba0`.
- [x] Rechecked constructor evidence: `0x004dec35` pushes `SEH_4DEC30`, `0x00600170` handler uses `___CxxFrameHandler3`, and adjacent cleanup funclets match generated cleanup routing.
- [x] Rechecked global lifecycle evidence: `xrefs_to 0x0067a758` count 65 and lifecycle writes at `0x004dec7b`, `0x004dec82`, `0x004dee3b`, `0x004e5ba0`, and `0x004e659e`.
- [x] Rechecked neighboring singleton-helper island boundaries and no-split/no-merge decision.
- [x] Checked generated tracker/coverage state read-only with `rg`; did not edit generated files.
- [x] Produced this report at `tools/leaser/Agents/Agent-B013/research/00017Y-ItemObjImageLibSingletonClearHelper-source-quality.md`.

Implementation callback checklist:

- [x] Supervisor accepts this report for implementation callback in `Agent-B013/goal.md`. Proof: goal assignment `B013-implement-00017Y-ItemObjImageLibSingletonClearHelper-source-quality-20260627` names this accepted report and target.
- [x] Lease only the exact by-* edit set immediately before editing, then release leases immediately after the edit/validator batch. Proof: `python .\tools\leaser\leaser.py B013 lease ...` returned `Success` for the six changed by-* paths; post-validator `unlease` found no active B013 lease for those paths, and `tools/leaser/Agents/current_leases.md` contained no B013 rows.
- [x] Target doc `by-memory/0x004e5ba0-0x004e5bab.ItemObjImageLibSingletonClearHelper.md`: set `COMPLETION:87`, `CONFIDENCE:93`, kept owner/emitter [UID:0000KH], kept `RECONSTRUCTABLE:TRUE`, kept formal C++ blank. Proof: validator `000000004826` recorded `completion_update 00017Y 87`, `confidence_update 00017Y 93`, `canonical_owner_update 00017Y 0000KH`, and `ok: 1`.
- [x] Target prose: added current MCP session/health, exact body/boundary, constructor SEH cleanup route, pointer-route negatives, global lifecycle xrefs, generated cleanup-glue/no-code proof, and rejected alternatives. Proof: target sections `Current MCP Evidence`, `Constructor SEH Cleanup Route`, `Ownership And No-Code Disposition`, and `Rejected Alternatives`.
- [x] Target `Item Summary`: replaced stale unresolved wording with the recommended constructor SEH cleanup summary. Proof: target metadata now states constructor SEH cleanup helper, exact `0xb` body, cleanup jump `0x00600158`, no ordinary callers/callees, pointer-route negatives, 65 xrefs, and blank-C++ generated cleanup-glue disposition.
- [x] `by-class/ItemObjImageLib.md`: removed method-shaped `ItemObjImageLib::ClearSingleton` row and described [UID:00017Y] as file-level/generated constructor cleanup helper; no score change. Proof: method table row now reads `Constructor SEH singleton cleanup helper`; validator `000000004827` returned exit 0 / `ok: 1`.
- [x] `by-file/ItemObjImageLib.md`: added source-root sync for constructor SEH cleanup glue and blank-C++ policy; no score/path change. Proof: `Owned And Nearby Helpers` and `Singleton Global` sections mention session `b001_000241_20260627`; validator `000000004828` returned exit 0 / `ok: 1`.
- [x] `by-memory/0x004dec30-0x004df500.ItemObjImageLibLocalMethodCluster.md`: updated [UID:00017Y] tail-page wording with cleanup jump `0x00600158`; no score change. Proof: related tail row, split coverage row, singleton storage, evidence notes, and change log now reflect constructor SEH cleanup; validator `000000004829` returned exit 0 / `ok: 1`.
- [x] `by-global/g_pItemObjImageLib.md`: updated [UID:00017Y] write-site description and current lifecycle-xref note; no score change. Proof: write evidence and B013 lifecycle paragraph now call `0x004e5ba0` constructor SEH/unwind cleanup; validator `000000004830` returned exit 0 / `ok: 1`.
- [x] `by-memory/0x0067a758-0x0067a75c.g_pItemObjImageLib.md`: updated storage-level lifecycle wording; no score change. Proof: write-site row, 2026-06-06 evidence bullet, B013 paragraph, and change log now describe constructor SEH/unwind cleanup; validator `000000004831` returned exit 0 / `ok: 1`.
- [x] Confirm no edit needed for [UID:00017O], [UID:0002VC], [UID:0001XW], and [UID:0001UU] unless supervisor widens scope. Proof: [UID:00017O] already records ordinary destructor cleanup and helper separation; [UID:0002VC] already records vtable wrapper route and no-code marker; [UID:0001XW]/[UID:0001UU] have no blocking helper-specific stale statement.
- [x] Run scoped validators only for changed by-* files and record command ids/timestamps/exit status/ok counts/warnings/generated-refresh state.
- [x] Do not edit generated reports, generated C++ files, project-level generated files, manual `-coverage-report.md` files, validator/tool state, IDA DB, or unrelated docs manually. Proof: edits were limited to the six by-* docs plus this implementation checklist; validator outputs recorded normal projection bookkeeping and `generated_refresh: deferred`.
- [x] Release all B013 leases and confirm no active B013 leases remain. Proof: `current_leases.md` after the validator batch showed no B013 entries; only unrelated B003/B006/B009 leases were present.

Implementation validator proof:

| Command ID | Timestamp | File | Exit / ok | Warnings | Generated refresh |
| --- | --- | --- | --- | --- | --- |
| `000000004826` | `2026-06-27T23:51:29-04:00` | `by-memory/0x004e5ba0-0x004e5bab.ItemObjImageLibSingletonClearHelper.md` | exit 0 / `ok: 1` | none reported | deferred |
| `000000004827` | `2026-06-27T23:51:36-04:00` | `by-class/ItemObjImageLib.md` | exit 0 / `ok: 1` | existing `missing_ref_uid` for `0003LZ`/`0003ND` | deferred |
| `000000004828` | `2026-06-27T23:51:46-04:00` | `by-file/ItemObjImageLib.md` | exit 0 / `ok: 1` | existing `missing_ref_uid` for `0003LZ`/`0003ND`/`0003ZN`; existing `missing_ref_target` for `00027I` stale target path | deferred |
| `000000004829` | `2026-06-27T23:51:53-04:00` | `by-memory/0x004dec30-0x004df500.ItemObjImageLibLocalMethodCluster.md` | exit 0 / `ok: 1` | existing `missing_ref_uid` for `0003LZ`/`0003ND`/`0003ZN` | deferred |
| `000000004830` | `2026-06-27T23:52:00-04:00` | `by-global/g_pItemObjImageLib.md` | exit 0 / `ok: 1` | none reported | deferred |
| `000000004831` | `2026-06-27T23:52:10-04:00` | `by-memory/0x0067a758-0x0067a75c.g_pItemObjImageLib.md` | exit 0 / `ok: 1` | none reported | deferred |

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B013","command_id":"000000004165","destination_path":"executed-b-agent-research/B013/00017Y-ItemObjImageLibSingletonClearHelper-source-quality.md","details":"legacy registry reconstruction","event":"executed","source_path":"tools/leaser/Agents/Agent-B013/research/00017Y-ItemObjImageLibSingletonClearHelper-source-quality.md","timestamp":"2026-06-28T00:04:25","uid":"00017Y"} -->
<!-- {"agent":"B013","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 00017Y-ItemObjImageLibSingletonClearHelper-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B013/00017Y-ItemObjImageLibSingletonClearHelper-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"00017Y"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
