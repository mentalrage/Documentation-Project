** TARGET-REPORT-UID:00017O **
** AUTHOR-AGENT-ID:B002 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# B002 Report - [UID:00017O] ItemObjImageLibDestructor Source Quality

## Assignment

- Agent: B002.
- Assignment ID: `B002-report-item-obj-image-lib-destructor-source-quality-00017O-mcp-20260623`.
- Target: [UID:00017O][0x004dee20-0x004dee4d.ItemObjImageLibDestructor](../../../../../by-memory/0x004dee20-0x004dee4d.ItemObjImageLibDestructor.md).
- Required report path: `tools/leaser/Agents/Agent-B002/research/00017O-ItemObjImageLibDestructor-source-quality.md`.
- Pass type: report-only research originally; supervisor accepted this report and B002 completed the implementation callback on 2026-06-23. The report-only pass did not edit by-* docs, generated/project-level files, IDA DB state, tool state, or coverage reports. The implementation callback edited only the accepted target/support by-* docs and this report checklist; B002 did not edit any `-coverage-report.md` file.
- Current target metadata before this report: `COMPLETION:84`, `CONFIDENCE:91`, `CANONICAL_OWNER:0000KH`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000KH`, blank `EMITTER_POSITION_OPTIONAL`, blank formal `RECONSTRUCTION_CPP`.

## Executive Recommendation

Raise [UID:00017O] from `84/91` to `86/92`, keep `CANONICAL_OWNER:0000KH`, keep `RECONSTRUCTABLE:TRUE`, keep `EMITTER_UIDS:0000KH`, keep `EMITTER_POSITION_OPTIONAL` blank, and keep formal C++ blank.

The current MCP pass proves the exact raw ordinary-destructor bytes, half-open range, padding fences, no-function/decompile-failure state, no direct code/data/pointer route to `0x004dee20`, class and `ProtectedArray<ItemInfo>` vtable stores, singleton clear, tail jump to `LObject` cleanup, and scalar-deleting-destructor parity. The score can rise because the target page can now replace stale `95/95` code-gate language with current MCP session `261fb29b` evidence and a real target-specific no-code proof.

Do not add first-draft C++ in this pass. The current code-entry minimum is met by the existing/recommended metadata, but the source body is not safe to emit: the raw range is a compiler-integrated complete-object destructor sequence that includes vptr stores, embedded `ProtectedArray<ItemInfo>` cleanup, singleton/global clear, and base cleanup. Emitting manual `free`, vptr writes, base calls, or deleting-destructor scaffolding would be decompiler-shaped. Emitting a simple source body such as `g_pItemObjImageLib = 0` is also unsafe because the observed binary order clears the singleton after the member cleanup and before the `LObject` base cleanup, which is more consistent with generated destructor/base or singleton cleanup ordering than with an ordinary handwritten destructor body.

## MCP Evidence Baseline

Current live IDA MCP session used for this report:

- Endpoint: `http://127.0.0.1:13337/mcp`.
- Session: `261fb29b`.
- `idb_list`: one active worker session for `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, PID/worker PID `12132`, `is_analyzing:false`, `is_active:true`.
- `server_health 261fb29b`: `status:"ok"`, module `NexusTK.exe`, IDB path `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, input path `C:\Users\admin\Desktop\Clone\NexusTK\NexusTK.exe`, imagebase `0x400000`, `auto_analysis_ready:true`, `hexrays_ready:true`, `strings_cache_ready:true`.

The earlier stale session `b880584f` was not used for conclusions after the supervisor resume. Existing by-* docs and old reports were treated as leads only and rechecked against current MCP where the report makes target-driving claims.

## Current Documentation Evidence Checked

Target/support docs reviewed:

- [UID:00017O][0x004dee20-0x004dee4d.ItemObjImageLibDestructor](../../../../../by-memory/0x004dee20-0x004dee4d.ItemObjImageLibDestructor.md).
- [UID:00006W][ItemObjImageLib](../../../../../by-class/ItemObjImageLib.md).
- [UID:0000KH][ItemObjImageLib](../../../../../by-file/ItemObjImageLib.md).
- [UID:00017N][0x004dec30-0x004df500.ItemObjImageLibLocalMethodCluster](../../../../../by-memory/0x004dec30-0x004df500.ItemObjImageLibLocalMethodCluster.md).
- [UID:0002VC][0x004e6580-0x004e65dc.ItemObjImageLibScalarDeletingDestructor](../../../../../by-memory/0x004e6580-0x004e65dc.ItemObjImageLibScalarDeletingDestructor.md).
- [UID:0001XW][ItemObjImageLibVtable](../../../../../by-type/by-vtable/ItemObjImageLibVtable.md).
- [UID:0001UU][ItemObjImageLibLayout](../../../../../by-type/by-struct/ItemObjImageLibLayout.md).
- [UID:0000RA][g_pItemObjImageLib](../../../../../by-global/g_pItemObjImageLib.md).
- [UID:0001OT][0x0067a758-0x0067a75c.g_pItemObjImageLib](../../../../../by-memory/0x0067a758-0x0067a75c.g_pItemObjImageLib.md).
- [UID:00017Y][0x004e5ba0-0x004e5bab.ItemObjImageLibSingletonClearHelper](../../../../../by-memory/0x004e5ba0-0x004e5bab.ItemObjImageLibSingletonClearHelper.md).
- [UID:0001UT][ItemInfo](../../../../../by-type/by-struct/ItemInfo.md).
- [UID:0001VM][ProtectedArrayLayout](../../../../../by-type/by-struct/ProtectedArrayLayout.md).
- [UID:0001WR][ProtectedArrayTemplates](../../../../../by-type/by-template/ProtectedArrayTemplates.md).
- [UID:0000MU][ProtectedArray](../../../../../by-file/ProtectedArray.md).
- `by-memory/-coverage-report.md` row for [UID:00017O], read only.

Prior-report status checked:

- No existing B002 `00017O` report existed before this file.
- Supervisor assignment history shows older B006 `00017O` queues/correction attempts, but disk checks recorded no report file. Those entries are not accepted evidence.
- B005 constructor report context is already incorporated into the constructor page and tracker, but this pass does not rely on it without current MCP support.

## Function And Range Inventory

Current MCP `lookup_funcs` results:

| Query | Result |
| --- | --- |
| `0x004dee1b` | Not a function. |
| `0x004dee20` | Not a function. |
| `0x004dee4c` | Not a function. |
| `0x004dee4d` | Not a function. |
| `0x004dee50` | `sub_4DEE50`, size `0x16a`, next modeled draw function. |
| `0x004dec30` | `sub_4DEC30`, size `0x1eb`, constructor. |
| `0x004e6580` | `sub_4E6580`, size `0x5c`, scalar deleting destructor. |
| `0x004e65dc` | Not a function. |
| `0x004e65e0` | `sub_4E65E0`, size `0xbd`, LightObjImageLib scalar deleting destructor successor. |
| `0x004e5b10` | Resolves inside broad `sub_4DEC30`, the raw `ProtectedArray<ItemInfo>` ordinary destructor island entry. |
| `0x004e6180` | `sub_4E6180`, size `0x2f`, `ProtectedArray<ItemInfo>` scalar deleting destructor. |
| `0x004e5ba0` | `sub_4E5BA0`, size `0xb`, singleton-clear helper. |
| `0x004f4a90` | `sub_4F4A90`, size `0x7`, base `LObject` cleanup helper. |
| `0x005c7799` | `j_j_j___free_base`, size `0x5`, free thunk. |

`int_convert` in the active MCP session verified:

- `0x2d` = `45` bytes (Verified with int_convert.py/MCP `int_convert` equivalent).
- `0x5` = `5` bytes (Verified with int_convert.py/MCP `int_convert` equivalent).
- `0x3` = `3` bytes (Verified with int_convert.py/MCP `int_convert` equivalent).
- `0x5c` = `92` bytes (Verified with int_convert.py/MCP `int_convert` equivalent).
- `0x28` = `40` bytes (Verified with int_convert.py/MCP `int_convert` equivalent).
- `0x14` = `20` bytes (Verified with int_convert.py/MCP `int_convert` equivalent).
- `0x0c` = `12` bytes (Verified with int_convert.py/MCP `int_convert` equivalent).

## Raw Bytes, Padding, And Disassembly

MCP `get_bytes` over `0x004dee1b` confirms:

- `0x004dee1b-0x004dee20`: five `0xcc` alignment bytes.
- `0x004dee20-0x004dee4d`: exact raw destructor bytes:

```text
56 8b f1 c7 06 3c b7 61 00 ff 76 0c c7 46 04 34 b7 61 00 e8 61 89 0e 00 83 c4 04 c7 05 58 a7 67 00 00 00 00 00 8b ce 5e e9 43 5c 01 00
```

- `0x004dee4d-0x004dee50`: three `0xcc` alignment bytes.
- `0x004dee50`: `push ebp`, the next modeled draw-function prologue.

MCP `insn_query` over `0x004dee1b-0x004dee50` reports:

| Address | Instruction | Function model |
| --- | --- | --- |
| `0x004dee1b` | `align 10h` | none |
| `0x004dee20` | `push esi` | none |
| `0x004dee21` | `mov esi, ecx` | none |
| `0x004dee23` | `mov dword ptr [esi], offset ??_7ItemObjImageLib@@6B@` | none |
| `0x004dee29` | `push dword ptr [esi+0Ch]` | none |
| `0x004dee2c` | `mov dword ptr [esi+4], offset ??_7?$ProtectedArray@UItemInfo@@@@6B@` | none |
| `0x004dee33` | `call j_j_j___free_base` | none |
| `0x004dee38` | `add esp, 4` | none |
| `0x004dee3b` | `mov dword_67A758, 0` | none |
| `0x004dee45` | `mov ecx, esi` | none |
| `0x004dee47` | `pop esi` | none |
| `0x004dee48` | `jmp sub_4F4A90` | none |
| `0x004dee4d` | `align 10h` | none |

MCP `decompile 0x004dee20` returns `code:null`, `error:"Decompilation failed at 0x4dee20"`, matching the no-function model. MCP `disasm 0x004dee20` can still render raw listing with `name:"<no function>"`, and it annotates refs from the vtable/global/base-helper operands.

The `jmp sub_4F4A90` at `0x004dee48` occupies bytes through `0x004dee4c`; therefore the correct half-open end stays `0x004dee4d`.

## Cleanup Sequence And Field Roles

Current MCP evidence supports this exact flow:

1. `ecx` is the object pointer; `mov esi, ecx` saves `this`.
2. `0x004dee23` restores the `ItemObjImageLib` vtable at object offset `+0x00`.
3. `0x004dee29` pushes `[this+0x0c]`, the `ProtectedArray<ItemInfo>::m_entries` pointer. In object layout terms, `m_itemInfos` begins at object `+0x04`; suboffset `+0x08` is therefore object `+0x0c`.
4. `0x004dee2c` restores the embedded `ProtectedArray<ItemInfo>` vtable at object offset `+0x04`.
5. `0x004dee33` calls `j_j_j___free_base` on the pushed entry-buffer pointer.
6. `0x004dee3b` clears `dword_67A758`, the backing storage for the canonical source-facing singleton `g_pItemObjImageLib`.
7. `0x004dee45-0x004dee48` restores `ecx=this`, pops `esi`, and tail-jumps to `sub_4F4A90`, the `LObject` cleanup helper.

The destructor does not read or update `m_itemInfos.m_count` at object `+0x08`, the provisional default/reserved capacity at object `+0x10`, or the default/fallback `ItemInfo` row at object `+0x14`. Those roles remain supported by the constructor/table/draw docs, but they are not active in this destructor body.

Current MCP listing still names the singleton storage operand `dword_67A758`. The source-facing global name `g_pItemObjImageLib` remains the best project documentation name because the lifecycle refs, constructor publish, destructor clears, and consumers all target the same singleton slot. Do not claim the current session itself displays `g_pItemObjImageLib` unless the IDB is renamed again in a later IDA-maintenance pass.

## Xrefs, Liveness, And Pointer Routes

Current MCP negative evidence:

- `xref_query to 0x004dee20`: total `0`, no cross-references to the raw ordinary-destructor start.
- `find data_ref 0x004dee20`: count `0`.
- `find code_ref 0x004dee20`: count `0`.
- `find_bytes "20 ee 4d 00"` for the VA `0x004dee20`: zero matches.
- `find_bytes "20 ee 0d 00"` for the RVA `0x000dee20`: zero matches.
- `callees 0x004dee20`: `No function found`.
- `analyze_function 0x004dee20`: `No function at 0x4dee20`.

Current MCP positive ownership/lifecycle evidence:

- `xref_query to 0x0061b73c`: exactly three refs: constructor store at `0x004dec8c`, raw destructor store at `0x004dee23`, and scalar deleting destructor store at `0x004e6586`.
- `xref_query to 0x0061b734`: five refs: constructor `0x004dec92`, raw destructor `0x004dee2c`, `ProtectedArray<ItemInfo>` ordinary destructor `0x004e5b13`, `ProtectedArray<ItemInfo>` deleting destructor `0x004e6189`, and scalar deleting destructor `0x004e658f`.
- `find data_ref 0x0061b73c`: same three class-vtable operand sites.
- `find data_ref 0x0061b734`: same five protected-array-vtable operand sites.
- `find data_ref 0x0067a758`: sixty-five matches, including lifecycle writes/clears at `0x004dec7b`, `0x004dec82`, `0x004dee3b`, `0x004e5ba0`, and `0x004e659e`.
- Scoped `insn_query` over `0x004dec30-0x004e6600` for operand `0x0067a758` finds the constructor publish/clear, raw destructor clear, singleton-clear helper clear, and scalar deleting destructor clear.
- Scoped `insn_query` over the same range for `0x0061b73c` finds only constructor, raw destructor, and scalar deleting destructor vtable stores.
- Scoped `insn_query` over the same range for `0x0061b734` finds constructor, raw destructor, `ProtectedArray<ItemInfo>` ordinary/scalar destructors, and ItemObjImageLib scalar deleting destructor stores.

Pointer-pattern checks:

| Pattern | Meaning | Current result |
| --- | --- | --- |
| `20 ee 4d 00` | VA pointer to `0x004dee20` | zero matches |
| `20 ee 0d 00` | RVA pointer to `0x004dee20` | zero matches |
| `80 65 4e 00` | VA pointer to scalar deleting destructor `0x004e6580` | one match at `0x0061b73c` |
| `a0 5b 4e 00` | VA pointer to singleton-clear helper `0x004e5ba0` | zero literal matches, while `find code_ref` finds cleanup-table/code ref `0x00600158` |
| `3c b7 61 00` | class vtable operand | `0x004dec8e`, `0x004dee25`, `0x004e6588` |
| `34 b7 61 00` | `ProtectedArray<ItemInfo>` vtable operand | `0x004dec94`, `0x004dee2f`, `0x004e5b15`, `0x004e618b`, `0x004e6592` |
| `58 a7 67 00` | singleton storage operand | 65 matches |

Interpretation: the raw ordinary destructor bytes are real and class-owned, but current MCP still proves no direct live caller, data pointer, VA/RVA literal, or vtable slot to the raw start itself. Its source-quality C++ cannot be justified by a proven live source-facing route to `0x004dee20`; the scalar deleting destructor is the vtable-backed live ABI entry.

## Scalar Deleting Destructor Comparison

Current MCP `decompile 0x004e6580`:

```text
*Block = &ItemObjImageLib::`vftable`;
v4 = (void *)Block[3];
Block[1] = &ProtectedArray<ItemInfo>::`vftable`;
j_j_j___free_base(v4);
dword_67A758 = 0;
sub_4F4A90(Block);
if ((a2 & 1) == 0 || (a2 & 4) != 0)
    return Block;
sub_4F4AC0(Block);
return Block;
```

Current MCP `disasm 0x004e6580` confirms:

- `0x004e6586`: class vtable restore.
- `0x004e658c`: push `[this+0x0c]`.
- `0x004e658f`: `ProtectedArray<ItemInfo>` vtable restore at `this+0x04`.
- `0x004e6596`: free entry buffer.
- `0x004e659e`: clear singleton storage.
- `0x004e65aa`: call `sub_4F4A90`.
- `0x004e65b2-0x004e65bb`: scalar delete predicate: delete only when `(flags & 1) != 0 && (flags & 4) == 0`.
- `0x004e65ca`: guarded/vector-like path pushes size `0x28` / `40` bytes (Verified with int_convert.py/MCP `int_convert` equivalent) and calls `_guard_check_icall_nop`.
- `0x004e65dc-0x004e65e0`: four `0xcc` bytes before `0x004e65e0`.

Current MCP `analyze_function 0x004e6580` reports size `92`, five basic blocks, cyclomatic complexity `2`, callees `sub_4F4A90`, `sub_4F4AC0`, `j_j_j___free_base`, and `_guard_check_icall_nop`, no ordinary callers, and one data xref to the function from `0x0061b73c`.

Decision: [UID:0002VC] is the vtable-backed scalar deleting destructor. It should not be merged with [UID:00017O], and [UID:00017O] should not inherit the scalar wrapper's delete-flag code. The two pages should cross-reference each other as parity/comparison evidence.

## ProtectedArray<ItemInfo> Comparison

Current MCP `insn_query 0x004e5b10-0x004e5b20` confirms the raw ordinary `ProtectedArray<ItemInfo>` destructor body:

| Address | Instruction |
| --- | --- |
| `0x004e5b10` | `push dword ptr [ecx+8]` |
| `0x004e5b13` | `mov dword ptr [ecx], offset ??_7?$ProtectedArray@UItemInfo@@@@6B@` |
| `0x004e5b19` | `call j_j_j___free_base` |
| `0x004e5b1e` | `pop ecx` |
| `0x004e5b1f` | `retn` |

Current MCP `decompile 0x004e6180` confirms the scalar deleting `ProtectedArray<ItemInfo>` body frees `Block[2]`, restores the concrete protected-array vtable, optionally deletes the `ProtectedArray<ItemInfo>` object when the delete flag is set, and returns.

Interpretation: the [UID:00017O] body is not solely a `ProtectedArray<ItemInfo>` destructor. It embeds or sequences the same protected-array cleanup for the member at `this+0x04`, but also restores the outer class vtable, clears the ItemObj singleton, and tail-jumps to `LObject` cleanup. Therefore `ProtectedArray` is a dependency/helper role, not the canonical owner of [UID:00017O].

## Owner, Emitter, And Source Placement

Recommended metadata:

- Keep `CANONICAL_OWNER:0000KH`.
- Keep `RECONSTRUCTABLE:TRUE`.
- Keep `EMITTER_UIDS:0000KH`.
- Keep `EMITTER_POSITION_OPTIONAL:` blank.

Rationale:

- The body is semantically `ItemObjImageLib` lifecycle code: it restores the `ItemObjImageLib` vtable, tears down the embedded item-info row array, clears the item object image library singleton, and then runs the shared `LObject` base cleanup.
- [UID:00006W] `ItemObjImageLib` is the source-facing class context and should remain heavily cross-linked in prose.
- [UID:0000KH] `ItemObjImageLib` is the current file/output root for the constructor, scalar deleting destructor, singleton clear helper, item-info table loading, frame-availability helper, and item draw family. Keeping this raw destructor routed through `NexusTK/render/ItemObjImageLib.cpp` preserves the established source placement.
- Do not promote this to no-owner/non-emitting: the body has strong vtable/global/layout evidence and a coherent source family.
- Do not make `g_pItemObjImageLib` the canonical owner: the global is state mutated by the destructor, not the source owner of the method body.
- Do not move it under `ProtectedArray`: the protected-array cleanup is a member subobject operation inside an outer class destructor.
- Do not route it through the local method cluster [UID:00017N] as an emitting aggregate: [UID:00017N] is a non-emitting neighborhood/container page whose exact child pages carry source ownership.

Class-owner caveat: by-structure's direct-owner rule generally favors class ownership for methods, and [UID:00006W] is the semantic class support page. However, the existing ItemObjImageLib exact method pages currently route owner/emitter through [UID:0000KH], and this narrow target is not the right place to change only one child page to class-owner metadata while constructor/scalar/helper siblings remain file-owned. A future coherent class-owner normalization pass can revisit all exact ItemObjImageLib method children together.

## Source-Facing Names And Types

Recommended source-facing names:

- Destructor name: `ItemObjImageLib::~ItemObjImageLib` is the correct descriptive source-facing name for this raw body.
- Embedded array field: use `m_itemInfos`.
- Entry buffer field: use `m_itemInfos.m_entries` for object offset `+0x0c`.
- Protected-array vtable/data role: `ProtectedArray<ItemInfo>` at object `+0x04`.
- Singleton storage source name: keep `g_pItemObjImageLib` as the documentation/source-facing name for `0x0067a758`, while noting current MCP displays `dword_67A758`.
- Base cleanup: describe `0x004f4a90` as `LObject` cleanup/base destructor support, not as an ItemObj-specific helper.

Names still not final-audit proven:

- Exact original singleton symbol spelling remains slightly open because current MCP disassembly uses `dword_67A758`.
- `ProtectedArray<T>` member names `m_entries`, `m_count`, and `m_defaultCapacity`/`m_reservedCount` are project-supported descriptive names, but the exact original header spelling is not recovered.
- `ItemInfo` field names are not used in this destructor body. Constructor/draw docs keep `itemTableId`, `paletteSlot`, `alpha`, `renderFlagsOrMode`, and `allowPaletteFilter`, with `itemTableId` and `renderFlagsOrMode` still descriptive.
- The class declaration's exact relationship to the `Singleton<ItemObjImageLib>` RTTI/support records remains important for the final source destructor shape. The current binary order suggests singleton cleanup may be generated/base cleanup rather than an ordinary destructor body statement, but this report does not final-audit the class inheritance declaration.

## First-Draft C++ Decision

Do not populate [UID:00017O] `RECONSTRUCTION_CPP` during an implementation callback for this report.

This is not because of the stale `95/95` code gate. Under the current by-structure rule, [UID:00017O] is already or would remain minimum-gate eligible: `RECONSTRUCTABLE:TRUE`, nonblank emitter route through [UID:0000KH], and combined score above `85`. The blocker is target-specific source shape, not the numeric gate.

No-code proof:

- The page's raw range represents compiler-integrated destructor teardown, not a clean standalone handwritten body. The bytes include vptr writes, member cleanup, singleton clear, and a tail jump to base cleanup.
- Adding C++ that manually writes vtables, calls `free`, calls the base destructor helper, or handles ABI/delete flags would be decompiler-shaped and not plausible mid-2000s source.
- Adding `ItemObjImageLib::~ItemObjImageLib() { g_pItemObjImageLib = 0; }` is not safe: the binary clears the singleton after the embedded `ProtectedArray<ItemInfo>` cleanup and before `LObject` cleanup. If `m_itemInfos` is a normal C++ member, a handwritten destructor body statement would normally execute before member teardown; the observed order points to generated/base/singleton cleanup details that require the final class declaration to model correctly.
- Adding an empty destructor is also premature: it might be the eventual source-facing shape, but only if the singleton clear is proven to come from inherited/static singleton support and not an explicit source body with compiler-specific ordering. That proof is not yet written into the class/layout docs.
- The raw ordinary destructor start has no current MCP code refs, data refs, VA/RVA literal pointers, or vtable slot. The live vtable-backed entry is the scalar deleting destructor at `0x004e6580`, which itself is compiler-shaped and should not be hand-written.
- The source-level representation should likely be resolved at the class/file declaration level after `Singleton<ItemObjImageLib>` inheritance/static cleanup, `ProtectedArray<ItemInfo>` member declaration, and `LObject` base teardown policy are standardized.

Score impact: completion can rise because the no-code proof is now explicit and current-session backed, but the lack of safe formal C++ and unresolved final destructor/source-body shape keep completion below `90` and confidence below final-audit range.

## Rejected Alternatives

- `NO_OWNER`: rejected. Current MCP proves class vtable stores, protected-array member cleanup, singleton lifecycle clearing, scalar-deleting parity, and file-family placement.
- `RECONSTRUCTABLE:FALSE` or ignored/padding: rejected. The target contains executable destructor instructions with source-owned lifecycle semantics.
- Merge with [UID:0002VC] scalar deleting destructor: rejected. The scalar deleting destructor is a separate modeled function at `0x004e6580-0x004e65dc`, has the vtable data pointer at `0x0061b73c`, has delete-flag handling, and should remain a distinct compiler-shaped wrapper page.
- Merge into [UID:00017N] local method cluster only: rejected. The cluster is a non-emitting index/container; [UID:00017O] is an exact child with independent bytes, behavior, metadata, and support needs.
- Assign to [UID:0000RA] `g_pItemObjImageLib`: rejected. The global is touched state and ownership evidence, not a method owner.
- Assign to [UID:0000MU] `ProtectedArray`: rejected. The protected-array cleanup pattern is a member-subobject dependency only.
- Assign to `LObject`: rejected. The target tail-jumps to `LObject` cleanup, but the outer body is ItemObjImageLib cleanup.
- Emit manual C++ destructor body now: rejected by the no-code proof above.

## Stale Or Superseded Documentation Corrected

- Target page stale `95/95` final-source-gate wording has been replaced with the current combined-score/emitter policy and target-specific no-code proof.
- [UID:00006W] class-page stale `90/90+` class-code-gate wording has been replaced with target-specific class-C++ blockers: missing exact draw-method child pages, unresolved final class declaration/inheritance/source-body shape, and avoiding duplication of constructor/remap child code.
- Support docs now clarify that current MCP session `261fb29b` renders the singleton operand as `dword_67A758`; `g_pItemObjImageLib` remains the source-facing documentation name unless a future IDB rename pass is reverified.
- Older local PE/Capstone fallback notes remain useful historical leads in support pages, but target-driving [UID:00017O] statements now use current MCP session `261fb29b`.

## Score And Metadata Recommendation

| Field | Current | Recommended | Rationale |
| --- | ---: | ---: | --- |
| `COMPLETION` | `84` | `86` | Current MCP pass adds session health, exact non-function inventory, bytes/padding, decompile failure, raw listing, lifecycle xrefs, pointer-route negatives, protected-array comparison, corrected code-entry policy, and target-specific no-code proof. Completion remains below `90` because no formal source body is safe and final class/destructor source shape remains unresolved. |
| `CONFIDENCE` | `91` | `92` | Confidence rises modestly because current MCP independently reconfirms every target-driving binary fact. It stays below final-audit range because current IDB still uses a generic singleton operand name and the exact source-level destructor/inheritance expression remains open. |
| `CANONICAL_OWNER` | `0000KH` | `0000KH` | Keep established ItemObjImageLib file ownership/output routing for exact method children; document [UID:00006W] class context in prose. |
| `RECONSTRUCTABLE` | `TRUE` | `TRUE` | Custom source-owned lifecycle cleanup must be reproduced through class/file declarations and generated destructor support. |
| `EMITTER_UIDS` | `0000KH` | `0000KH` | Output route remains `NexusTK/render/ItemObjImageLib.cpp`. |
| `EMITTER_POSITION_OPTIONAL` | blank | blank | No special insertion point needed while formal C++ stays blank. |
| `RECONSTRUCTION_CPP` | blank | blank | Keep blank with the no-code proof above. |

## Supervisor-Owned Coverage Text

After the accepted implementation callback, the target page is updated to `86/92`. Supervisor-owned coverage application remains: replace the current [UID:00017O] row in `by-memory/-coverage-report.md` with:

```text
        - [UID:00017O][0x004dee20-0x004dee4d.ItemObjImageLibDestructor](by-memory/0x004dee20-0x004dee4d.ItemObjImageLibDestructor.md) 0x004dee20-0x004dee4d | destructor | ItemObjImageLib::~ItemObjImageLib : reconstructable : 86% : strong : Current MCP session `261fb29b` confirms exact raw ordinary destructor bytes, five-byte pre-padding, three-byte post-padding, unmodeled-function/decompile-failure status, ItemObjImageLib vtable restore, `ProtectedArray<ItemInfo>` vtable restore and `m_entries` buffer free, singleton clear at `0x004dee3b`, tail jump to `LObject` cleanup, scalar-deleting destructor parity, no direct code/data/VA/RVA pointer route to `0x004dee20`, file owner/emitter route through `ItemObjImageLib.cpp`, and blank formal C++ with a target-specific no-code proof because the raw body is compiler-integrated destructor teardown rather than safe handwritten source.
```

Do not let B002 edit `by-memory/-coverage-report.md`; this row is supervisor-owned.

## Open Questions And Limits

- Exact final source declaration/inheritance shape for `ItemObjImageLib` is not final-audited. The visible RTTI support for `Singleton<ItemObjImageLib>` and the binary cleanup order suggest singleton clearing may be generated/base cleanup, but this report does not prove the full class declaration.
- Exact original symbol spelling for `g_pItemObjImageLib` remains slightly caveated because current MCP displays `dword_67A758`.
- Exact original member names in `ProtectedArray<T>` remain descriptive/project-standard, not PDB-proven.
- The raw ordinary destructor has no direct current MCP liveness route to `0x004dee20`. This does not make the bytes irrelevant, but it is a material C++-emission blocker.

## Implementation Tracking Checklist

Report-only pass:

- [x] Read current B002 goal and project-level `ntk-b-agent-workflow` instructions: `Agent-B002/goal.md`, `ntk-b-agent-workflow/SKILL.md`, and `references/b-agent-research-and-implementation-workflow.md`.
- [x] Confirmed report-only scope: no by-* docs, generated/project-level files, IDA DB, tool state, or `-coverage-report.md` files edited.
- [x] Checked MCP health/session: `idb_list` and `server_health` for session `261fb29b` succeeded; active IDB is `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`.
- [x] Rechecked target function/non-function inventory with MCP `lookup_funcs`: `0x004dee20`, `0x004dee4c`, and `0x004dee4d` remain non-functions; `0x004dee50` is the next modeled function; scalar deleting destructor and helpers are modeled as documented.
- [x] Rechecked raw bytes/padding/disassembly: MCP `get_bytes`, `insn_query`, `disasm`, and `decompile` prove the exact range, fences, raw listing, and decompile failure.
- [x] Rechecked callers/callees/xrefs/liveness: MCP `xref_query`, `find data_ref`, `find code_ref`, `find_bytes`, `callees`, and `analyze_function` prove no direct start refs/pointers and document vtable/global positive refs.
- [x] Rechecked scalar deleting destructor comparison: MCP `decompile`, `disasm`, and `analyze_function` for `0x004e6580`.
- [x] Rechecked `ProtectedArray<ItemInfo>` cleanup comparison: MCP `insn_query 0x004e5b10-0x004e5b20` and `decompile/disasm 0x004e6180`.
- [x] Rechecked current coverage row in `by-memory/-coverage-report.md` without editing it.
- [x] Produced this report at `tools/leaser/Agents/Agent-B002/research/00017O-ItemObjImageLibDestructor-source-quality.md`.

Accepted implementation callback pass:

- [x] Leased exact by-* edit set before editing: target, required class/file pages, cluster/scalar/vtable/layout/global/storage/singleton support pages. Proof: `python .\tools\leaser\leaser.py B002 lease ...` returned `Success` for all ten paths.
- [x] Target doc edit completed: `by-memory/0x004dee20-0x004dee4d.ItemObjImageLibDestructor.md` now has `COMPLETION:86`, `CONFIDENCE:92`, unchanged `CANONICAL_OWNER:0000KH`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000KH`, blank emitter position, and blank formal C++.
- [x] Target stale code-gate wording superseded: target now states blank C++ is due to target-specific source shape, no live pointer route, and compiler-integrated vptr/member/base cleanup, not the old `95/95` gate.
- [x] Target MCP evidence incorporated: target now records current session `261fb29b`, lookup inventory, exact bytes, padding fences, raw disassembly, decompile/analyze/callee failure at the raw start, xref/liveness negatives, vtable/global positives, pointer-pattern negatives, scalar-wrapper comparison, and `ProtectedArray<ItemInfo>` comparison.
- [x] Target exact range/body facts preserved: `0x004dee20-0x004dee4d`, exact 45-byte string, five-byte pre-padding, three-byte post-padding, cleanup sequence, tail jump through `0x004dee4c`, and no-function status.
- [x] Target rejected alternatives preserved: no-owner, ignored/padding, scalar-deleting merge, aggregate-only ownership, singleton-global ownership, `ProtectedArray<ItemInfo>` ownership, `LObject`/base ownership, and forced live C++ are all rejected in the target page.
- [x] `by-class/ItemObjImageLib.md` updated: current [UID:00017O] MCP pass, no-function/no-pointer caveat, exact bytes/padding, vtable/global refs, no-code caveat, and corrected class-C++ rationale are present; class C++ remains blank.
- [x] `by-file/ItemObjImageLib.md` updated: current destructor evidence, owner/emitter route, no-code proof, `NexusTK/render/ItemObjImageLib.cpp` source-placement rationale, and `dword_67A758`/`g_pItemObjImageLib` naming split are present.
- [x] `by-memory/0x004dec30-0x004df500.ItemObjImageLibLocalMethodCluster.md` updated: [UID:00017O] row and evidence notes now use current MCP session `261fb29b` for the destructor-specific no-function/no-pointer/range proof while preserving the non-emitting cluster status.
- [x] `by-memory/0x004e6580-0x004e65dc.ItemObjImageLibScalarDeletingDestructor.md` updated: current MCP comparison to [UID:00017O], scalar wrapper vtable route, cleanup parity, predicate, and blank-C++/no-merge rationale are present.
- [x] `by-type/by-vtable/ItemObjImageLibVtable.md` updated: current three class-vtable refs `0x004dec8c`/`0x004dee23`/`0x004e6586`, live scalar slot `0x0061b73c -> 0x004e6580`, and no pointer route to `0x004dee20` are present.
- [x] `by-type/by-struct/ItemObjImageLibLayout.md` updated: ordinary destructor-specific field evidence records `m_itemInfos.m_entries` at `+0x0c`, template vtable at `+0x04`, no touches to `+0x08/+0x10/+0x14`, and current `dword_67A758` label caveat.
- [x] `by-global/g_pItemObjImageLib.md` and `by-memory/0x0067a758-0x0067a75c.g_pItemObjImageLib.md` updated: current MCP display label `dword_67A758`, source-facing name `g_pItemObjImageLib`, lifecycle refs, and ownership-negative destructor-start pointer-route result are present.
- [x] `by-memory/0x004e5ba0-0x004e5bab.ItemObjImageLibSingletonClearHelper.md` updated: current MCP helper size/xref proof and separation from [UID:00017O] are present.
- [x] Metadata/C++ implementation completed: formal target C++ remains blank with the accepted no-code proof; no `ItemObjImageLib::~ItemObjImageLib` body was emitted.
- [x] Coverage left supervisor-owned: B002 did not edit `by-memory/-coverage-report.md`; the exact replacement row remains in this report under `Supervisor-Owned Coverage Text`.
- [x] Validator run: `python .\tools\validator.py --mode file --file by-memory\0x004dee20-0x004dee4d.ItemObjImageLibDestructor.md --apply --queue-timeout 240` -> exit code `0`, `ok: 1`. First full run applied `completion_update 00017O 86`, `confidence_update 00017O 92`, removed [UID:00017O] from `Low_Completion_Reconstructable`, updated projected stats, and rebuilt the autogen registry.
- [x] Validator run: `python .\tools\validator.py --mode file --file by-class\ItemObjImageLib.md --apply --queue-timeout 240` -> exit code `0`, `ok: 1`.
- [x] Validator run: `python .\tools\validator.py --mode file --file by-file\ItemObjImageLib.md --apply --queue-timeout 240` -> exit code `0`, `ok: 1`.
- [x] Validator run: `python .\tools\validator.py --mode file --file by-memory\0x004dec30-0x004df500.ItemObjImageLibLocalMethodCluster.md --apply --queue-timeout 240` -> exit code `0`, `ok: 1`.
- [x] Validator run: `python .\tools\validator.py --mode file --file by-memory\0x004e6580-0x004e65dc.ItemObjImageLibScalarDeletingDestructor.md --apply --queue-timeout 240` -> exit code `0`, `ok: 1`.
- [x] Validator run: `python .\tools\validator.py --mode file --file by-type\by-vtable\ItemObjImageLibVtable.md --apply --queue-timeout 240` -> exit code `0`, `ok: 1`.
- [x] Validator run: `python .\tools\validator.py --mode file --file by-type\by-struct\ItemObjImageLibLayout.md --apply --queue-timeout 240` -> exit code `0`, `ok: 1`.
- [x] Validator run: `python .\tools\validator.py --mode file --file by-global\g_pItemObjImageLib.md --apply --queue-timeout 240` -> exit code `0`, `ok: 1`.
- [x] Validator run: `python .\tools\validator.py --mode file --file by-memory\0x0067a758-0x0067a75c.g_pItemObjImageLib.md --apply --queue-timeout 240` -> exit code `0`, `ok: 1`.
- [x] Validator run: `python .\tools\validator.py --mode file --file by-memory\0x004e5ba0-0x004e5bab.ItemObjImageLibSingletonClearHelper.md --apply --queue-timeout 240` -> exit code `0`, `ok: 1`.
- [x] Validator side effects recorded: repeated scoped runs reported known non-target warnings/notices only, including stale registry entries `0003E6`/`00026U`, explicit `[[CHILDREN]]` marker preferences, five pre-existing `autogen_cpp_conflict` files, projected stats updates, registry rebuilds, and auto-generated coverage report no-ops. No `-coverage-report.md` file was edited by B002.
- [x] Lease release/expiry checked: `python .\tools\leaser\leaser.py B002 unlease ...` returned `Rejected[No active lease]` for all ten paths after validators, and `tools/leaser/Agents/current_leases.md` then listed only unrelated B005 Application leases, with no active B002 leases remaining.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B002","command_id":"000000004165","destination_path":"executed-b-agent-research/B002/00017O-ItemObjImageLibDestructor-source-quality.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:16","uid":"00017O"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
