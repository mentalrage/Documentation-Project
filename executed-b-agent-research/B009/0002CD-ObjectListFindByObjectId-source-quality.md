** TARGET-REPORT-UID:0002CD **
** AUTHOR-AGENT-ID:B009 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# 0002CD ObjectListFindByObjectId Source-Quality Report

Assignment: `B009-report-0002CD-object-list-find-by-object-id-source-quality-20260626`  
Agent: `Agent-B009`  
Mode: report-only research first  
Target: [UID:0002CD] `by-memory/0x00532370-0x00532443.ObjectListFindByObjectId.md`  
Required report path: `tools/leaser/Agents/Agent-B009/research/0002CD-ObjectListFindByObjectId-source-quality.md`

## Report-Only Status

This is a report-only B-agent pass. I did not lease files, did not edit by-* documentation, did not edit generated/project-level/manual coverage/tool-state files, and did not edit the IDA database.

IDA MCP was mandatory and was available. Live MCP context used for this report:

- MCP endpoint: `http://127.0.0.1:13337/mcp`
- Listener: `127.0.0.1:13337`, `TcpTestSucceeded=True`
- Process state: listener owner PID `13684` (`python.exe`), active IDA/Python worker PID `26892`
- IDB session: `80de0a67`
- Database: `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`
- `server_health`: `status=ok`, `auto_analysis_ready=true`, `hexrays_ready=true`, module `NexusTK.exe`, imagebase `0x400000`

Queue/context note: `auto-generated/-ag-research-tracker.md` still lists [UID:0002CD] as `80/84`. That generated file is stale context only and was not edited during this report-only assignment. The current target by-* page itself is `85/88`.

## Recommendation Summary

Promote [UID:0002CD] from a documented ObjectList lookup with blank C++ to a formal source-ready ObjectList method:

- Source-facing method: `ObjectList::FindByObjectId(int objectId)`
- Return type: `ObjectPane *`
- Parameter: `int objectId`
- Compared object field: `ObjectPane::m_objectId` at `+0xfc`; keep `m_objectSerial` as a documented alias/caveat, not the preferred method name.
- Metadata recommendation: `COMPLETION:90`, `CONFIDENCE:91`, `CANONICAL_OWNER:00009Q`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:00009Q`, blank emitter position.
- C++ handling: populate the target `RECONSTRUCTION_CPP CODE` block with the exact formal method body below.
- Support-doc correction: replace the target's broad "row/global lists" wording with the exact three storage regions touched by the binary: `m_tertiaryRowLists` at `+0x24`, `m_primaryCellList` at `+0x14`, and `m_secondaryCellList` at `+0x18`.

`FindByObjectId` is the best current source-facing name because accepted MapPane caller pages pass values named `objectId` and `m_pendingActionTargetObjectId`, packet helper docs serialize object ids, and the ObjectPane class/file docs already reject stale `spriteIndex` wording for `+0xfc`. `FindBySerial` remains a searchable synonym only because some object-id fields may have been server serials in the original protocol vocabulary.

## Formal Reconstruction C++

Use this exact C++ block for [UID:0002CD] if the report is accepted:

```cpp
ObjectPane *ObjectList::FindByObjectId(int objectId)
{
    short rowCount = static_cast<short>(m_gridHeight + 4);

    for (short rowIndex = 0; rowIndex < rowCount; ++rowIndex) {
        List *targetList = m_tertiaryRowLists[rowIndex];
        int count = targetList->GetCount();

        for (int index = 0; index < count; ++index) {
            ObjectPane *object =
                *static_cast<ObjectPane **>(targetList->GetElementAt(index));

            if (object->m_objectId == objectId)
                return object;
        }
    }

    int primaryCount = m_primaryCellList->GetCount();
    for (int index = 0; index < primaryCount; ++index) {
        ObjectPane *object =
            *static_cast<ObjectPane **>(m_primaryCellList->GetElementAt(index));

        if (object->m_objectId == objectId)
            return object;
    }

    int secondaryCount = m_secondaryCellList->GetCount();
    for (int index = 0; index < secondaryCount; ++index) {
        ObjectPane *object =
            *static_cast<ObjectPane **>(m_secondaryCellList->GetElementAt(index));

        if (object->m_objectId == objectId)
            return object;
    }

    return NULL;
}
```

The method intentionally has no null checks for the receiver, lists, or object entries. The binary dereferences the receiver fields, the selected `List *`, and the returned element slot directly.

The `short rowCount` is intentional. Live disassembly reads the low word at `ObjectList+0x10`, adds `4`, stores the resulting count, and compares a 16-bit row index before indexing `m_tertiaryRowLists`. The broader ObjectList layout can keep `m_gridHeight` as its established field name; this target's formal code should preserve the observed 16-bit loop shape.

## Evidence Checked

Primary and support docs:

- [UID:0002CD] `by-memory/0x00532370-0x00532443.ObjectListFindByObjectId.md`
- [UID:00023E] `by-memory/0x00531480-0x00532530.ObjectListCategorizeLookupHelpers.md`
- [UID:0002CB] `by-memory/0x00532180-0x005322d0.ObjectListEncodedKeyResolve.md`
- [UID:0002CC] `by-memory/0x005322d0-0x00532370.ObjectListTypeSpecificIndexDispatch.md`
- [UID:0002CE] `by-memory/0x00532450-0x00532530.ObjectListTypeIndexExistsSwitchHelper.md`
- [UID:0002C9] `by-memory/0x005314a0-0x00531c10.ObjectListTypeDispatchInsertCategorize.md`
- [UID:00009Q] `by-class/ObjectList.md`
- [UID:0000M4] `by-file/ObjectList.md`
- [UID:0001VG] `by-type/by-struct/ObjectListLayout.md`
- [UID:000079] `by-class/List.md`
- [UID:00009R] `by-class/ObjectPane.md`
- [UID:0000M5] `by-file/ObjectPane.md`
- [UID:00007Q] `by-class/MapPane.md`
- [UID:0000L3] `by-file/MapPane.md`
- [UID:0002QN] `by-memory/0x00505e00-0x005060e3.MapPaneCreateOrUpdateObjectPane.md`
- [UID:0002QO] `by-memory/0x005060f0-0x00506169.MapPaneRemoveObjectPaneById.md`
- [UID:0003ZS] `by-memory/0x00509030-0x00509439.MapPaneMovementTimerHandler.md`

Context from current ObjectList/MapPane source-quality work:

- [UID:0002C9] now emits `ObjectList::AddObjectPane(ObjectPane *object)` and proves ObjectList pointer-list elements store `ObjectPane *` payloads.
- [UID:0002CE] now emits `ObjectList::ContainsTypedObject(ObjectPane *object)` and explicitly separates type-membership lookup at `+0xf8` from [UID:0002CD]'s id lookup at `+0xfc`.
- [UID:0002CC] is the value-returning typed-key companion and must not be confused with [UID:0002CD]; it dispatches on `m_objectType`, while [UID:0002CD] compares `m_objectId`.
- [UID:0002QN], [UID:0002QO], and [UID:0003ZS] already use `FindByObjectId` in accepted C++ or support tables.

## Fresh IDA MCP Evidence

Live JSON-RPC calls were made against session `80de0a67`; no fallback-only evidence was used.

### MCP Setup

- `initialize` at local time `2026-06-26T20:03:21` returned server `ida-pro-mcp` version `1.0.0`, protocol `2025-06-18`.
- `idb_list` id `2` returned one active session, `80de0a67`, for `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`; `is_analyzing:false`; worker PID `26892`.
- `tools/list` id `3` exposed `server_health`, `lookup_funcs`, `analyze_function`, `decompile`, `disasm`, `xrefs_to`, `callees`, `basic_blocks`, `get_bytes`, and `int_convert`.
- `server_health` id `10` at local time `2026-06-26T20:03:52` returned `status=ok`, `auto_analysis_ready=true`, `hexrays_ready=true`, `strings_cache_ready=true`, module `NexusTK.exe`.

### Function and Boundary Evidence

`lookup_funcs` id `11` returned:

| Query | MCP result |
| --- | --- |
| `0x00532370` | `sub_532370`, size `0xd3` |
| `0x00532443` | not a function |
| `0x00532450` | not a function |
| `0x005322d0` | `sub_5322D0`, size `0x71` |
| `0x00532530` | `sub_532530`, size `0x4` |
| `0x00505e00` | `sub_505E00`, size `0x2e3` |
| `0x005060f0` | `sub_5060F0`, size `0x79` |
| `0x00509030` | `sub_509030`, size `0x409` |

`analyze_function` id `12` for `0x00532370` returned:

- Name: `sub_532370`
- Prototype shape: `int __thiscall(_WORD *this, int)`
- Size: `211` bytes (`0xd3`, verified by `int_convert` id `30`)
- Basic blocks: `18`
- Cyclomatic complexity: `12`
- Direct ordinary callees: none
- Caller functions: `sub_505E00`, `sub_5060F0`, `sub_507150`, `sub_507C90`, `sub_509030`, `sub_50B2B0`, `sub_50B990`, `sub_50DFA0`, `sub_50E320`, `sub_50E4C0`, `sub_50E810`, `sub_511710`, `sub_511C90`, `sub_512960`, `sub_512D60`, `sub_512F20`, and `sub_513310`

The absent direct callee list is expected: this target reaches `List::GetElementAt` through virtual slot `+0x10`, so the dynamic calls do not appear as ordinary direct callees.

`basic_blocks` id `17` confirmed an exact modeled body from `0x532370` through `0x532443`; the final block `0x53243a-0x532443` contains the epilogue and `retn 4`.

`get_bytes` id `18` confirmed:

- `0x00532370` starts with `55 8b ec 83 ec 0c 8b d1`, a normal function prologue.
- `0x00532443-0x00532450` is thirteen bytes of `0xcc` alignment before [UID:0002CE]. `0xd` equals `13` by `int_convert` id `30`.

This validates the current child split:

- [UID:0002CC] body/table ends immediately before `0x00532370`.
- [UID:0002CD] source body is `0x00532370-0x00532443`.
- `0x00532443-0x00532450` is alignment.
- [UID:0002CE] begins at `0x00532450` as a raw function-shaped helper that current IDA does not model as a function.

### Decompile Evidence

`decompile` id `13` for `0x00532370` returned the exact traversal shape:

- Initializes `v13 = this[8] + 4`, which is `ObjectList+0x10` low word plus four padded rows.
- Loops row index `0..v13-1`.
- Selects `*(_DWORD **)(v2[9] + 4 * rowIndex)`, where `v2[9]` maps to `ObjectList+0x24` / `m_tertiaryRowLists`.
- Reads the list count from `selectedList+0x0c`.
- Calls the list virtual function at vtable slot `+0x10` with the loop index.
- Dereferences the returned element slot to an object pointer.
- Compares `*(object + 252)` against the argument. `0xfc` equals `252`, verified by `int_convert` id `30`.
- If no row-list entry matches, repeats the same count/get/compare loop for `v2[5]`, which maps to `ObjectList+0x14` / `m_primaryCellList`.
- If no primary-cell entry matches, repeats the same loop for `v2[6]`, which maps to `ObjectList+0x18` / `m_secondaryCellList`.
- Returns the matched object pointer or `0`.

Important precision correction: this target does not scan the direct global tiers at `+0x2c` through `+0x40`. Existing target wording that says "row/global lists" should be narrowed to "tertiary row list buckets, primary cell list, and secondary cell list."

### Disassembly Evidence

`disasm` id `14` for `0x00532370` returned `85` instructions. Key instructions:

| Address | Instruction | Source meaning |
| --- | --- | --- |
| `0x53237f` | `mov ax, [edx+10h]` | Reads low word of `m_gridHeight`. |
| `0x532383` | `add ax, 4` | Adds padded row count. |
| `0x53239d` | `mov eax, [edx+24h]` | Loads `m_tertiaryRowLists`. |
| `0x5323a0` | `mov ebx, [eax+ecx*4]` | Selects row list by row index. |
| `0x5323a3` | `mov edi, [ebx+0Ch]` | Reads `List::m_count`. |
| `0x5323b5` | `call dword ptr [eax+10h]` | Calls `List::GetElementAt`. |
| `0x5323bb` | `mov eax, [eax]` | Dereferences list element slot to `ObjectPane *`. |
| `0x5323bd` | `cmp [eax+0FCh], ecx` | Compares object `+0xfc` to argument. |
| `0x5323da` | `mov edi, [edx+14h]` | Loads `m_primaryCellList`. |
| `0x5323f5` | `call dword ptr [eax+10h]` | Primary-list `GetElementAt`. |
| `0x5323fa` | `cmp [eax+0FCh], ebx` | Primary-list id comparison. |
| `0x53240b` | `mov edi, [edx+18h]` | Loads `m_secondaryCellList`. |
| `0x532425` | `call dword ptr [eax+10h]` | Secondary-list `GetElementAt`. |
| `0x53242a` | `cmp [eax+0FCh], ebx` | Secondary-list id comparison. |
| `0x532438` | `xor eax, eax` | Null return when no match. |
| `0x532440` | `retn 4` | One-argument thiscall return. |

The three `List` count reads use `+0x0c`, which [UID:000079] documents as `List::m_count`. The three dynamic calls use vtable slot `+0x10`, which [UID:000079] documents as `List::GetElementAt`.

### Xref and Caller Evidence

`xrefs_to` id `15` for `0x00532370` returned `33` code xrefs and `more:false`:

`0x505e36`, `0x506100`, `0x50697a`, `0x507b0f`, `0x507bd1`, `0x5080f2`, `0x50817a`, `0x508244`, `0x508993`, `0x509217`, `0x509391`, `0x50b835`, `0x50b9c8`, `0x50b9db`, `0x50e005`, `0x50e026`, `0x50e27c`, `0x50e349`, `0x50e52e`, `0x50e81c`, `0x5117e9`, `0x511a75`, `0x511b0d`, `0x511bd9`, `0x511d1f`, `0x512a23`, `0x512c44`, `0x512cf6`, `0x512e2a`, `0x512e49`, `0x5130c9`, `0x5133d3`, and `0x513d51`.

Representative live decompiler evidence:

| Caller | MCP evidence | Source-facing meaning |
| --- | --- | --- |
| `0x00505e00` / [UID:0002QN] | `decompile` id `20` calls `sub_532370(*(this+1060), a2)` at `0x505e36`, then uses the result as an existing object pane during create/update. It compares `a2` against the active object field at `active+0xfc`. | `MapPane::CreateOrUpdateObjectPane(..., int objectId, ...)` lookup by object id. |
| `0x005060f0` / [UID:0002QO] | `decompile` id `21` calls `sub_532370(*(this+1060), a2)` at `0x506100`; if found, checks `object+0xf8`, removes it from ObjectList, invalidates, and deletes it. | `MapPane::RemoveObjectPaneById(int objectId)`. |
| `0x00509030` / [UID:0003ZS] | `decompile` id `22` calls `sub_532370(*(this+896), *(this+2148))` at `0x509217` and `sub_532370(*(this+896), *(this+2148))` at `0x509396` in event `8`. Accepted docs map `this+896` to `m_objectList` and `this+2148` to pending action target object id. | Timer/path-follow action target lookup by pending object id. |
| `0x00506970` | `decompile` id `23` is a tiny wrapper returning `sub_532370(this[265], a2)`. | MapPane wrapper around ObjectList id lookup. |
| `0x0050e810` | `decompile` id `24` calls `sub_532370(this[265], a2)` and then uses returned object `+476` attached pane/state. | Another MapPane object-id lookup consumer. |

The caller set spans creation/update, removal, packet/render processing, timer action targeting, and later MapPane object-state helpers. This breadth supports a general base `ObjectPane *` return instead of any one derived pane type.

## Source-Quality Blocker Resolution

| Prior blocker | Resolution |
| --- | --- |
| Source-facing method/helper name | Use `ObjectList::FindByObjectId`. It matches current MapPane formal callers, packet helper names, and `MapPane+0x908` pending target object id docs. Keep `FindBySerial` as a secondary alias only. |
| `+0xfc` field name | Use `ObjectPane::m_objectId` in formal code. Keep `m_objectSerial` in prose as an alias/caveat because some server object ids may be serial-style values, but current source-facing route is object id. |
| Server id vs pane id | Reject as primary names. Callers pass packet/object-update ids and pending target ids; nothing indicates a UI pane allocation id. `serverId` is narrower than the MapPane/object-list API and should stay as protocol context only. |
| Return type | Use `ObjectPane *`. The function returns the stored object pointer from generic ObjectList pointer lists. Callers then branch on `m_objectType`, use virtuals, or cast through downstream helper context. A narrower `LivingObjectPane *` would be false for item/flying/static-style consumers. |
| Parameter type | Use `int objectId`. The binary performs 32-bit equality only, so signedness is not behavior-significant. Current MapPane formal pages use `int objectId`; matching them is the least disruptive source-facing choice. |
| Storage field names | Use `m_tertiaryRowLists`, `m_primaryCellList`, and `m_secondaryCellList`. These names are already accepted in ObjectListLayout and [UID:0002C9]. Do not say this target scans all global tiers. |
| Formal C++ readiness | Ready. The body is one bounded IDA-modeled function, has no target-owned helper calls, uses accepted List/ObjectList/ObjectPane field names, and exactly matches the observed three-loop scan order. |

## Heuristic and Inference Reanalysis

Positive evidence for `FindByObjectId`:

- [UID:0002QN]'s accepted formal C++ calls `m_objectList->FindByObjectId(objectId)` before object create/update and compares the same id against the active object `+0xfc`.
- [UID:0002QO]'s accepted formal C++ calls `m_objectList->FindByObjectId(objectId)` before remove/delete.
- [UID:0003ZS] documents `MapPane+0x908` as pending action target object id and passes it to this helper during event `8`.
- [UID:000231] names the outbound refresh helper `SendObjectRefreshRequest(int objectId)`, supporting the same MapPane object-id vocabulary for missing/stale object lookup.
- [UID:00009R] and [UID:0000M5] already document `ObjectPane+0xfc` as `m_objectId` / `m_objectSerial` and reject stale sprite-index wording.

Counter-evidence and caps:

- The binary itself only proves a 32-bit equality test against `ObjectPane+0xfc`; it does not embed a string or type name proving the original spelling.
- `serial` remains plausible original protocol vocabulary, so implementation should preserve an alias/caveat in prose.
- The target does not search every ObjectList storage tier. It only searches `m_tertiaryRowLists`, `m_primaryCellList`, and `m_secondaryCellList`. Support docs must not overgeneralize the body as a full ObjectList-wide scan.
- The direct callee list is empty because `List::GetElementAt` is virtual. Reports should cite the disassembly vtable calls rather than claiming no dependencies.

## Rejected Alternatives

- `ObjectList::FindBySerial(int serial)`: plausible alias but weaker than `FindByObjectId` because the accepted MapPane source surface consistently says object id.
- `ObjectList::FindByServerId(int serverId)`: too protocol-specific for an ObjectList storage method used by render, timer, and packet/update code.
- `ObjectList::FindByPaneId(int paneId)`: rejected because `+0xfc` is stored on `ObjectPane` and is passed from packet/object id fields, not from pane allocation or UI handles.
- `LivingObjectPane *ObjectList::FindByObjectId(...)`: rejected because the same helper serves item/flying/static-style object paths and returns a base object pointer from generic List payloads.
- `void *` or `int` return: IDA's raw prototype is an artifact of missing types. Callers dereference the returned pointer as object state, and ObjectList stores `ObjectPane *` payloads.
- `ObjectList::FindInGlobalLists`: rejected because the observed fields are `+0x24`, `+0x14`, and `+0x18`, not the direct global tiers at `+0x2c..+0x40`.
- Factoring a local `FindObjectIdInList` helper or lambda into the target C++: rejected for this exact by-memory page. The binary has one function body with three inline loops and no direct helper call.

## Score and Metadata Rationale

Recommended score: `90/91`.

Completion should rise from `85` to `90` because this pass resolves the prior source-facing blockers: method name, parameter, return type, compared field name, exact storage fields, formal C++ body, and support-doc update plan. It remains below final polish because original spelling of `m_objectId` versus `m_objectSerial` is not proven by symbols.

Confidence should rise from `88` to `91` because live MCP confirmed the function boundary, exact decompile, instruction-level field offsets, 33 current xrefs, no direct callees, adjacent alignment bytes, and key MapPane caller semantics. It remains below `95+` because the final original source vocabulary is inferred from callers and support docs rather than recovered from symbols.

Ownership and emission should remain [UID:00009Q] `ObjectList`. The receiver is the ObjectList object, the body reads ObjectList storage fields, the class/file route already clears the gate, and MapPane callers only consume the method through `MapPane::m_objectList`.

## Implementation Plan if Accepted

Apply these by-* updates only during the implementation callback, with leases acquired immediately before edits:

1. Update [UID:0002CD] metadata to `COMPLETION:90`, `CONFIDENCE:91`, `CANONICAL_OWNER:00009Q`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:00009Q`, blank emitter position.
2. Populate [UID:0002CD]'s formal C++ block with the exact `ObjectList::FindByObjectId(int objectId)` body from this report.
3. Replace the target summary/status/open-question wording that says field/return naming is unresolved with the resolved object-id/serial alias policy and `ObjectPane *` return.
4. Correct the target behavior/evidence wording from "row/global lists" to the exact three storage regions: `m_tertiaryRowLists`, `m_primaryCellList`, and `m_secondaryCellList`.
5. Preserve the range evidence: `sub_532370`, size `0xd3` / `211`, body `0x00532370-0x00532443`, thirteen `0xcc` bytes at `0x00532443-0x00532450`, predecessor [UID:0002CC], successor [UID:0002CE].
6. Update [UID:00023E] parent inventory to prefer `ObjectList::FindByObjectId(int objectId)` and remove "or FindBySerial" as an unresolved primary name.
7. Update [UID:00009Q] `ObjectList` and [UID:0000M4] `ObjectList` support docs to record that [UID:0002CD] now has formal C++ and searches `m_tertiaryRowLists`, `m_primaryCellList`, and `m_secondaryCellList` by `ObjectPane::m_objectId`.
8. Update [UID:0001VG] `ObjectListLayout` only as support prose: this target consumes `+0x24`, `+0x14`, and `+0x18`; no new ObjectList fields are introduced.
9. Update [UID:00009R] `ObjectPane` and [UID:0000M5] `ObjectPane` only if needed to make `m_objectId` primary and `m_objectSerial` alias/caveat wording consistent.
10. Update MapPane caller/support pages only where they still say the [UID:0002CD] field/name remains open. [UID:0003ZS] currently has a helper table entry `FindByObjectId / FindBySerial` with field name open; that should become `ObjectList::FindByObjectId` with `m_objectId` primary and serial alias caveat. [UID:0002QN] and [UID:0002QO] already use `FindByObjectId` and may only need a support-note refresh.
11. Do not change [UID:0002CC] or [UID:0002CE] formal C++ as part of this implementation. Their relationship notes are already compatible; only add a relationship/status note if a current read shows stale wording and the file is leased/free.
12. Run scoped validators for each changed by-* file after implementation.

## Implementation Tracking Checklist

- [x] Lease only the exact by-* files to be edited for the implementation callback. Proof: B009 leased only the changed target/support files in immediate batches. Initial batch leased [UID:0002CD], [UID:00009R], [UID:0000M5], and [UID:0003ZS]; B006-held ObjectList files were rejected and not edited through. After B006 expiry B009 leased [UID:00023E] and [UID:0001VG]. After B014 expiry B009 leased [UID:00009Q] and [UID:0000M4].
- [x] Update [UID:0002CD] metadata to `90/91`, owner/emitter `00009Q`, reconstructable true, blank emitter position. Proof: target header now has `COMPLETION:90`, `CONFIDENCE:91`, `CANONICAL_OWNER:00009Q`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:00009Q`, and blank `EMITTER_POSITION_OPTIONAL:`.
- [x] Insert the exact formal `ObjectList::FindByObjectId(int objectId)` C++ block from this report. Proof: target `RECONSTRUCTION_CPP CODE` block now contains the accepted formal `ObjectPane *ObjectList::FindByObjectId(int objectId)` body.
- [x] Preserve MCP evidence for function range, `0xd3` / `211` size, `0x00532443-0x00532450` alignment, no direct callees, and 33 xrefs. Proof: target Raw Code Evidence records MCP session `80de0a67`, `lookup_funcs`/`analyze_function`/`basic_blocks`/`get_bytes`/`decompile`/`disasm`/`xrefs_to` details, size `0xd3` / `211`, body `0x00532370-0x00532443`, thirteen-byte alignment, no ordinary direct callees due virtual `List::GetElementAt`, and the full 33-xref list.
- [x] Update target prose to make `m_objectId` primary and `m_objectSerial` an alias/caveat. Proof: target Status, Behavior, Reconstruction Notes, Open Questions, and Rejected Alternatives now make `m_objectId` primary and retain `m_objectSerial` only as alias/caveat.
- [x] Update target prose to name the exact scan fields `m_tertiaryRowLists`, `m_primaryCellList`, and `m_secondaryCellList`. Proof: target Behavior and formal C++ use those three storage fields and explicitly reject broad direct-global-tier scan wording.
- [x] Update [UID:00023E] parent aggregate relationship/status wording for [UID:0002CD]. Proof: parent row, behavior notes, evidence, ownership decision, score rationale, and change log now name `ObjectList::FindByObjectId(int objectId)`, exact scan fields, `ObjectPane *` return, and child-owned C++ policy.
- [x] Update [UID:00009Q] `ObjectList` and [UID:0000M4] `ObjectList` support docs with report-level details. Proof: class/file docs now include [UID:0002CD] as formal `FindByObjectId`, with exact storage fields, `ObjectPane::m_objectId`, `ObjectPane *` return, alias caveat, and no duplicate class/file C++ body.
- [x] Update [UID:0001VG] `ObjectListLayout` support prose for this target's exact field consumers if stale. Proof: layout Naming Notes and Changes now record [UID:0002CD] consuming `+0x10`, `+0x24`, `+0x14`, `+0x18`, and ObjectPane `+0xfc` without adding fields.
- [x] Update [UID:00009R] / [UID:0000M5] `ObjectPane` only if their `m_objectId` / `m_objectSerial` alias wording is stale after current read. Proof: both ObjectPane class/file docs now make `m_objectId` primary for [UID:0002CD] and preserve `m_objectSerial` as alias/caveat.
- [x] Update MapPane caller/support docs only where they still describe [UID:0002CD]'s field/name as unresolved. Proof: [UID:0003ZS] helper table now uses accepted `ObjectList::FindByObjectId` and `m_objectId` primary wording. [UID:0002QN] and [UID:0002QO] were read as already using `FindByObjectId` and did not need edits.
- [x] Run scoped validators for every changed by-* file and record command IDs, timestamps, exits, and ok counts. Proof: all validator exits were `0` with `ok: 1`: `000000003277` at `2026-06-26T20:18:59-04:00` for [UID:0002CD]; `000000003278` at `20:19:00-04:00` for [UID:00009R]; `000000003279` at `20:19:02-04:00` for [UID:0000M5]; `000000003280` at `20:19:04-04:00` for [UID:0003ZS]; `000000003289` at `20:22:26-04:00` for [UID:00023E]; `000000003290` at `20:22:28-04:00` for [UID:0001VG]; `000000003293` at `20:27:42-04:00` for [UID:00009Q]; `000000003294` at `20:27:44-04:00` for [UID:0000M4]. Each reported `generated_refresh: deferred`.
- [x] Release all leases after the edit/validator batch. Proof: B009 released the first batch after validators `3277-3280`, released the parent/layout batch after validators `3289-3290`, and released the ObjectList class/file batch after validators `3293-3294`.
- [x] Update this report checklist with implementation proof only during the accepted implementation callback. Proof: this checked implementation proof was added after all accepted by-* edits, validators, and lease releases.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B009","command_id":"000000004165","destination_path":"executed-b-agent-research/B009/0002CD-ObjectListFindByObjectId-source-quality.md","details":"legacy registry reconstruction","event":"executed","source_path":"tools/leaser/Agents/Agent-B009/research/0002CD-ObjectListFindByObjectId-source-quality.md","timestamp":"2026-06-26T20:31:24","uid":"0002CD"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
