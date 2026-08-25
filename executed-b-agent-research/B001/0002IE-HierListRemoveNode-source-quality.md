** TARGET-REPORT-UID:0002IE **
** AUTHOR-AGENT-ID:B001 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# Agent-B001 Report - [UID:0002IE] HierListRemoveNode Source Quality

Agent: Agent-B001

Assignment id: B001-report-0002IE-hier-list-remove-node-20260626

Mode: report-only research first

Report date: 2026-06-26

Target: [UID:0002IE] `by-memory/0x004ceb00-0x004ceb45.HierListRemoveNode.md`

Required report path: `tools/leaser/Agents/Agent-B001/research/0002IE-HierListRemoveNode-source-quality.md`

## Report-Only Compliance

This pass edited only this Agent-B001 research report. It did not edit target/support `by-*` docs, generated files, project-level files, validator state/cache, IDA DB, `by-memory/-coverage-report.md`, or any other `-coverage-report.md`.

No leases were taken because report-only work writes only under this agent's `research/` folder. No subagents were spawned.

IDA MCP was available and used. The report is not fallback-only.

## Executive Recommendation

Keep [UID:0002IE] as a source-authored, reconstructable `HierList` method owned and emitted through [UID:000065] `HierList`, with [UID:0000JV] `NexusTK/util/HierList.cpp` as the file route.

Recommended metadata after implementation:

| Field | Current target header | Recommended |
| --- | ---: | ---: |
| `COMPLETION` | 86 | 90 |
| `CONFIDENCE` | 90 | 92 |
| `CANONICAL_OWNER` | 000065 | 000065 |
| `RECONSTRUCTABLE` | TRUE | TRUE |
| `EMITTER_UIDS` | 000065 | 000065 |
| Formal C++ | blank | add exact `HierList::RemoveByPayload` method body below |

Reason: current MCP confirms the exact modeled function, one Layer caller, the resolved `FindNodeByPayload` call, child-list scalar delete and clear through `HierListNode::childList`, and virtual `RemoveAt(index, 1)` dispatch on the owner list returned by the lookup helper. The old blank-C++ blocker is now resolvable because [UID:0002IK] already carries formal `FindNodeByPayload` C++, [UID:0001UQ] documents `HierListNode::childList` and `payload`, and [UID:000079] / [UID:0002II] document the virtual remove-at route. This exact target can safely carry first-draft formal C++ now.

Best source-facing name: `HierList::RemoveByPayload(const void *payload)`.

## Current Target State

`by-memory/0x004ceb00-0x004ceb45.HierListRemoveNode.md` currently has:

- Header: `COMPLETION:86`, `CONFIDENCE:90`, `CANONICAL_OWNER:000065`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:000065`, blank formal C++.
- Correct owner/source route: [UID:000065] `HierList` -> [UID:0000JV] `NexusTK/util/HierList.cpp`.
- Correct aggregate route: child of non-emitting [UID:00016X] `0x004ce730-0x004cee52.HierList`.
- Current blocker text: exact source API spelling/declaration is treated as inferred, so formal C++ is blank.
- Generated-state caveat: generated/project-level files are read-only in this report. Implementation should rely on validators to refresh generated outputs, not manual generated edits.

Support docs reviewed:

- [UID:00016X] `by-memory/0x004ce730-0x004cee52.HierList.md`
- [UID:000065] `by-class/HierList.md`
- [UID:0000JV] `by-file/HierList.md`
- [UID:0001UQ] `by-type/by-struct/HierListNode.md`
- [UID:0002IA] `by-memory/0x004ce7e0-0x004ce839.HierListTailInsertWrapper.md`
- [UID:0002IB] `by-memory/0x004ce840-0x004ce854.HierListDefaultInsertWrapper.md`
- [UID:0002IC] `by-memory/0x004ce860-0x004ce9ad.HierListInsertBefore.md`
- [UID:0002ID] `by-memory/0x004ce9b0-0x004ceafc.HierListInsertAfter.md`
- [UID:0002IF] `by-memory/0x004ceb50-0x004ceb62.HierListGetElementAt.md`
- [UID:0002II] `by-memory/0x004cebc0-0x004cebec.HierListRemoveAt.md`
- [UID:0002IK] `by-memory/0x004cec30-0x004ced0f.HierListFindNodeByData.md`
- [UID:0002IL] `by-memory/0x004ced10-0x004ceda4.HierListUpdateHierarchy.md`
- [UID:0002I9] `by-memory/0x004ce760-0x004ce7d1.HierListNonDeletingDestructor.md`
- [UID:0002IM] `by-memory/0x004cedb0-0x004cee52.HierListScalarDeletingDestructor.md`
- [UID:000079] `by-class/List.md`
- [UID:0003JZ] `by-memory/0x004f33e0-0x004f3493.ListRemoveRange.md`
- [UID:00018W] `by-memory/0x004f0480-0x004f1bf6.Layer.md`
- Executed B reports: B001 `00016X-hierlist-source-quality.md`, B003 `0002IA-HierListTailInsertWrapper-source-quality.md`, B004 `0002IK-HierListFindNodeByData-source-quality.md`, and B015 `0002IB-HierListDefaultInsertWrapper-source-quality.md`.

## Live IDA MCP Evidence

Active MCP provenance:

- Endpoint `http://127.0.0.1:13337/mcp` responded to `initialize`; negotiated protocol `2025-06-18`.
- `tools/list` was checked before target calls.
- Active IDB session from `idb_list`: `80de0a67`.
- IDB path: `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`.
- Module/input from `server_health`: module `NexusTK.exe`, input path `C:\Users\admin\Desktop\Clone\NexusTK\NexusTK.exe`, imagebase `0x400000`.
- Health: `status:"ok"`, `auto_analysis_ready:true`, `hexrays_ready:true`, strings cache ready, `is_analyzing:false`.
- Relevant active call shapes used here include `lookup_funcs(queries,database)`, `xrefs_to(addrs,database)`, `callees(addrs,database)`, `analyze_function(addr,database)`, `decompile(addr,database)`, `disasm(addr,database)`, `get_bytes(regions,database)`, `make_signature_for_range(start,end,database)`, `find_bytes(patterns,database)`, `xref_query(queries,database)`, and `int_convert(inputs,database)`.

Function and boundary facts:

- `lookup_funcs` reports `sub_4CEB00` at `0x004ceb00`, size `0x45`; `0x45` is 69 decimal bytes.
- `lookup_funcs 0x004ceb44` resolves inside `sub_4CEB00`.
- `lookup_funcs 0x004ceb45` reports not a function.
- `lookup_funcs 0x004ceafc` reports not a function; this is the alignment span after [UID:0002ID].
- `lookup_funcs 0x004ceb50` reports successor `sub_4CEB50`, size `0x12`.
- `get_bytes 0x004ceafc size 0x60` shows four `0xcc` bytes before the target, the exact target body, eleven `0xcc` bytes from `0x004ceb45` through `0x004ceb4f`, and successor [UID:0002IF] prologue bytes at `0x004ceb50`.
- `get_bytes 0x004ceb00 size 69` returns the exact target bytes from prologue `55 8b ec 83 ec 08` through `5e 8b e5 5d c2 04 00`.
- `make_signature_for_range 0x004ceb00-0x004ceb45` returns a unique wildcarded IDA signature.

Function profile and call graph:

- `xrefs_to 0x004ceb00` reports exactly one code xref: `0x004f0b25` inside [UID:00018W] `Layer::RemoveChild` / `sub_4F0A60`.
- `callees 0x004ceb00` reports one direct modeled callee: `sub_4CEC30`, now [UID:0002IK] `HierList::FindNodeByPayload`.
- `analyze_function 0x004ceb00` reports prototype `int __thiscall(_DWORD *this, int)`, size 69, five basic blocks, cyclomatic complexity 3, caller `sub_4F0A60`, callee `sub_4CEC30`, no strings, and no constants.
- `decompile 0x004ceb00` shows `sub_4CEC30(this, a2, &ownerList, &index)`, stores the returned node in `esi`, tests it, reads `node + 0x04`, optionally calls the child list vtable slot `0` with delete flag `1`, clears `node + 0x04`, then calls `(*(ownerList->vtable + 0x1c))(ownerList, index, 1)`.
- `disasm 0x004ceb00` confirms the same sequence:
  - `0x004ceb12` calls `sub_4CEC30`.
  - `0x004ceb1d` loads `ecx = [esi+4]`, the child `HierList*`.
  - `0x004ceb26-0x004ceb28` pushes delete flag `1` and calls the child list vtable slot `0`.
  - `0x004ceb2a` clears `dword ptr [esi+4]`.
  - `0x004ceb31-0x004ceb3b` loads the owner list out parameter, pushes count `1`, pushes the found index, and calls vtable slot `+0x1c`.
  - `0x004ceb42` returns with `retn 4`, matching one explicit stack argument.

Lookup helper relationship:

- `xrefs_to 0x004cec30` reports nine code refs: raw [UID:0002IA] ref `0x004ce812`, [UID:0002IC] refs `0x004ce8d5`, `0x004ce906`, `0x004ce974`, [UID:0002ID] refs `0x004cea28`, `0x004cea59`, `0x004ceac3`, this target ref `0x004ceb12`, and self-recursion `0x004cecca`.
- [UID:0002IK] already proves the helper returns a full `HierListNode *` and writes owner `HierList **` plus zero-based `int *` index. This target consumes exactly those outputs.

Layer caller:

- `lookup_funcs 0x004f0a60` reports `sub_4F0A60`, size `0xdd`; `lookup_funcs 0x004f0b25` resolves inside that same function.
- `decompile 0x004f0a60` shows the caller searches for a Layer pane node, performs Layer-side region/child cleanup, sets `v9 = v5 + 8`, and calls `sub_4CEB00((_DWORD *)this[1], v9)` at `0x004f0b25`.
- `disasm 0x004f0a60` confirms `0x004f0b21 push edi`, `0x004f0b22 mov ecx, [eax+4]`, and `0x004f0b25 call sub_4CEB00`. This means the explicit argument is the Layer node payload pointer, not a `HierListNode *`, and the `this` object is the Layer-owned root `HierList`.

Negative evidence:

- `lookup_funcs` retains raw generated names (`sub_4CEB00`, `sub_4CEC30`, `sub_4F0A60`); no recovered original symbol for the target name was present in the live IDB lookup.
- `analyze_function 0x004ceb00` reports no strings/constants that would reveal a source name.
- `find_bytes` for little-endian pointer bytes to `0x004ceb00` and target end `0x004ceb45` returned no matches. The only live incoming target evidence is the direct Layer code xref at `0x004f0b25`.
- `xrefs_to 0x004ceb45` reports no cross-references, supporting the endpoint/padding conclusion.

## Behavior

This method removes a stored payload from the `HierList` tree.

Step order:

1. Calls `FindNodeByPayload(payload, &ownerList, &index)`.
2. If no node is found, returns immediately.
3. If the found node has a child list at `node->childList`, deletes that child list through the child list's virtual deleting destructor and then clears `node->childList`.
4. Calls the owning list's virtual `RemoveAt(index, 1)` slot so the actual owner list removes exactly one row and repairs shifted hierarchy links through [UID:0002II].

The method does not compare payload bytes itself. The recursive lookup helper owns payload matching and returns the exact owner list plus index. The method does not remove by node pointer from the caller; the Layer caller passes a payload pointer (`LayerNode + 0x08`) and the target resolves the node internally.

## Source-Form And Name Resolution

Best source-facing form:

```cpp
void HierList::RemoveByPayload(const void *payload);
```

Rationale:

- `FindNodeByPayload` is now the accepted source-facing lookup helper. The remove method should use the same `Payload` terminology because its argument is the caller payload bytes, not a `HierListNode *`.
- `RemoveByPayload` distinguishes this method from [UID:0002II] `RemoveAt(index, count)`, the virtual index/count removal method actually used at the tail of this target.
- `RemoveNode` remains a useful stable by-memory label and documentation alias because the method ultimately removes a found node. It is less precise as emitted source spelling because the explicit argument is not a node pointer.
- `Remove` is plausible as a public API name, but it is too broad in a class that already has `RemoveAt` and a base `List::RemoveAt` route.
- `DeleteNode` or `DeleteByPayload` overstates the operation. The method deletes only nested child-list ownership before removing the row; the payload row itself is removed through the list storage mutation.
- The method is source-authored class logic, not compiler ABI glue: it has one explicit payload argument, one Layer caller, a lookup helper, source-owned child-list cleanup, and a virtual remove-at mutation.

Return type decision:

- The binary leaves `eax` as zero on miss and as the `RemoveAt` call result on success, but no source caller currently consumes that value as a semantic result. The only modeled caller is a decompiler-shaped `return sub_4CEB00(...)` tail in `Layer::RemoveChild`, which is consistent with a `void` call at the end of a void source method.
- Existing accepted insertion wrappers [UID:0002IA] and [UID:0002IB] use `void` even when the live register may preserve delegate-call output. `void` is the most human source-facing form for this side-effect-only removal operation.
- Confidence remains below final-audit level because the exact original return spelling is inferred rather than symbol-proven.

## Rejected Alternatives

1. Leave formal C++ blank because the original API spelling is not symbol-proven.
   Rejected. Rule 26 requires best-defensible source reconstruction for above-gate exact children. Current evidence resolves behavior, ownership, parameter role, support declarations, and a plausible human source name.

2. Keep the emitted method name as `HierListRemoveNode`.
   Rejected as primary source spelling. It is a stable by-memory label, but the explicit argument is a payload pointer, not a node pointer. `RemoveByPayload` better matches the accepted `FindNodeByPayload` helper and avoids implying caller-owned node access.

3. Use `Remove(const void *payload)`.
   Rejected as primary spelling because it is plausible but too generic beside `RemoveAt(index, count)`. It can remain a lower-ranked future class-wide alias if the final declaration pass prefers shorter public API names.

4. Use `int` return type.
   Rejected for first-draft source. The observed result is not a source-level status contract; it is the natural residual register from `FindNodeByPayload` on miss and virtual `RemoveAt` on success. The known caller is a Layer cleanup path, not a consumer of the return value.

5. Move the method to `Layer`.
   Rejected. Layer is the sole known consumer, but the method operates on `HierList` state, calls the `HierList` recursive lookup helper, deletes `HierList` child lists, and dispatches through the owner `HierList` vtable.

6. Move the method to `List`.
   Rejected. `List` supplies the virtual remove-at storage operation, but payload lookup, node header cleanup, child `HierList*` ownership, and owner-list recursion are HierList-specific.

7. Treat this target as non-emitting because [UID:00016X] is a non-emitting aggregate.
   Rejected. [UID:00016X] is the non-emitting physical index. [UID:0002IE] is the exact source-bearing method range and should emit through [UID:000065].

8. Hand-code the scalar deleting destructor wrapper.
   Rejected. Source should use `delete node->childList;`. The compiler emits the virtual deleting-destructor call with flag `1`; source should not expose the ABI flag call as hand-written code.

## Formal C++ Disposition

Formal `RECONSTRUCTION_CPP CODE` for [UID:0002IE] should be added now. Exact insertion text for the target page's formal C++ block:

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
void HierList::RemoveByPayload(const void *payload)
{
    HierList *ownerList;
    int index;
    HierListNode *node = FindNodeByPayload(payload, &ownerList, &index);
    if (node == NULL) {
        return;
    }

    if (node->childList != NULL) {
        delete node->childList;
        node->childList = NULL;
    }

    ownerList->RemoveAt(index, 1);
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

Why this is target-range safe:

- It covers only `0x004ceb00-0x004ceb45`; it does not paste the lookup helper, remove-at override, destructor, or `Layer` caller into this target.
- `FindNodeByPayload(payload, &ownerList, &index)` matches the direct `0x004ceb12 -> 0x004cec30` call and consumes [UID:0002IK]'s accepted owner/index outputs.
- `node->childList` matches row offset `+0x04`, documented by [UID:0001UQ] and used by this target at `0x004ceb1d`.
- `delete node->childList;` expresses the virtual slot-0 deleting-destructor call with delete flag `1` without hand-authoring compiler ABI details.
- `node->childList = NULL;` matches `0x004ceb2a`.
- `ownerList->RemoveAt(index, 1);` matches the `0x004ceb31-0x004ceb3b` virtual slot `+0x1c` dispatch and preserves the owner-list behavior when the matched node lives in a child list rather than the root list.

Support declaration/source-shape requirements:

- [UID:000065] `HierList` should record `void RemoveByPayload(const void *payload);` as the accepted source-facing role for [UID:0002IE], while keeping the stable by-memory label `HierListRemoveNode`.
- [UID:0000JV] `HierList.cpp` should list `0x004ceb00` as formal exact-child `RemoveByPayload` C++ rather than an unresolved remove helper.
- [UID:00016X] aggregate should keep non-emitting status and update the child table/source-quality notes to show [UID:0002IE] now carries exact-child `RemoveByPayload` C++.
- [UID:0002IK] does not require a code change, but support text may note that [UID:0002IE] is now an accepted consumer of `FindNodeByPayload(payload, &ownerList, &index)`.
- [UID:0002II] does not require formal C++ from this report; a support note may identify this target's `ownerList->RemoveAt(index, 1)` as a virtual caller of the remove-at override.
- [UID:00018W] Layer docs do not need ownership changes. Optional support wording can name the `Layer::RemoveChild` call at `0x004f0b25` as using `HierList::RemoveByPayload`.

## Score And Metadata Rationale

Recommend `90/92` rather than keeping `86/90` blank-code status:

- Completion rises because the target can now carry current MCP provenance, exact function/caller/callee/byte/signature evidence, source-form decision, rejected alternatives, formal first-draft C++, and support-doc callback requirements.
- Confidence rises because multiple independent evidence paths agree: target decompilation, target disassembly, unique signature, endpoint padding, Layer caller context, [UID:0002IK] accepted lookup semantics, [UID:0001UQ] node layout, [UID:0002II] remove-at slot, and [UID:0002IM] destructor/delete behavior.
- Keep below final-audit territory because `RemoveByPayload` and `void` are inferred source-facing spellings, not recovered original symbols, and the broader class still has unresolved final declarations for the insert cores, destructor policy, and hierarchy repair helper.
- Keep `CANONICAL_OWNER:000065`, `RECONSTRUCTABLE:TRUE`, and `EMITTER_UIDS:000065`.
- No split, merge, range extension, owner change, emitter change, or path rename is recommended.

## Required Implementation Edits If Accepted

Target doc: `by-memory/0x004ceb00-0x004ceb45.HierListRemoveNode.md`

- Update header scores to `COMPLETION:90`, `CONFIDENCE:92`; keep `CANONICAL_OWNER:000065`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:000065`, and blank `EMITTER_POSITION_OPTIONAL`.
- Insert the exact formal `HierList::RemoveByPayload` C++ block above.
- Update Item Summary to name the source-facing payload removal role.
- Add current MCP provenance: endpoint, active IDB session `80de0a67`, health ok, analysis idle, Hex-Rays ready, checked schema/call shapes.
- Add current target evidence: `lookup_funcs`, `xrefs_to`, `callees`, `analyze_function`, `decompile`, `disasm`, `get_bytes`, unique signature, `find_bytes` negative pointer checks, and Layer caller context.
- Replace stale blank-C++/API-deferred wording with the accepted source-form decision: emitted source spelling `RemoveByPayload`, stable by-memory label `HierListRemoveNode`.
- Add a score rationale explaining why the page moves to `90/92` and why it is not higher.
- Add rejected alternatives from this report.

Support docs:

- `by-class/HierList.md`: update the method map/source-shape notes so [UID:0002IE] is accepted formal `void HierList::RemoveByPayload(const void *payload)` C++; add the method declaration/source role and note it uses accepted `FindNodeByPayload`.
- `by-file/HierList.md`: update proposed contents/migration notes so `0x004ceb00` is no longer an unresolved blank remove helper after implementation; record `RemoveByPayload` as the emitted target.
- `by-memory/0x004ce730-0x004cee52.HierList.md`: update the child table/source-quality notes for [UID:0002IE] to mention formal `RemoveByPayload` C++ on the exact child page; keep aggregate `RECONSTRUCTABLE:FALSE` and blank `EMITTER_UIDS`.
- `by-memory/0x004cec30-0x004ced0f.HierListFindNodeByData.md`: optional support note that [UID:0002IE] now emits the accepted consumer of the owner/index outputs.
- `by-memory/0x004cebc0-0x004cebec.HierListRemoveAt.md`: optional support note that [UID:0002IE] uses the owner-list virtual `RemoveAt(index, 1)` dispatch.
- `by-memory/0x004f0480-0x004f1bf6.Layer.md`: optional support note naming `Layer::RemoveChild`'s `0x004f0b25` call as `HierList::RemoveByPayload`; do not change ownership.
- No direct edit is required to `by-type/by-struct/HierListNode.md`, `by-class/List.md`, or `by-memory/0x004cedb0-0x004cee52.HierListScalarDeletingDestructor.md`; existing support docs already contain the needed `childList`, `payload`, virtual remove-at, and destructor/delete behavior.

Generated/project-level/coverage:

- Do not manually edit `auto-generated/*`, `project-level/*`, validator state/cache, IDA DB, `by-memory/-coverage-report.md`, or any `-coverage-report.md`.
- Let validators refresh generated outputs. If `auto-generated/NexusTK/util/HierList.cpp` or `auto-generated/-ag-research-tracker.md` still show stale state afterward, report that as validator/generated-state lag rather than hand-editing.
- If the supervisor owns a coverage refresh, the likely replacement row for this exact child is:

```markdown
        - [UID:0002IE][0x004ceb00-0x004ceb45.HierListRemoveNode](by-memory/0x004ceb00-0x004ceb45.HierListRemoveNode.md) 0x004ceb00-0x004ceb45 | method | HierListRemoveNode / RemoveByPayload : reconstructable : 90% : strong : Exact `HierList::RemoveByPayload(payload)` method; resolves the payload through `FindNodeByPayload`, deletes and clears any child list at `node->childList`, then dispatches owner-list `RemoveAt(index, 1)` with formal first-draft C++ on the exact child page.
```

## Suggested Validators For Accepted Implementation

From `E:\NTK\GhidraBridge\source-3\project-documentation`, after acquiring only the immediate edit-file leases:

> Executable block R001 was removed from this report and preserved verbatim in [0002IE-HierListRemoveNode-source-quality-removed.md](0002IE-HierListRemoveNode-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

If optional support notes are edited, also run the corresponding scoped validators:

> Executable block R002 was removed from this report and preserved verbatim in [0002IE-HierListRemoveNode-source-quality-removed.md](0002IE-HierListRemoveNode-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

No source-doc validators were run in this report-only pass because no `by-*` source docs were edited.

## Report Readiness Proof

- [x] Current `goal.md` read.
- [x] Project-level `ntk-b-agent-workflow` skill read and applied before report work.
- [x] Target and required support pages checked.
- [x] Existing executed HierList B reports checked for source-name consistency.
- [x] Live IDA MCP used successfully; report is not fallback-only.
- [x] Function boundary, endpoint padding, caller/callee set, disassembly, decompilation, bytes, unique signature, and negative pointer/start evidence checked.
- [x] Source-form/name/C++ blocker resolved in this report.
- [x] Exact formal C++ insertion text supplied in full target header/block format.
- [x] Required implementation callback edits and validator plan supplied.

## Implementation Tracking Checklist

- [x] Supervisor accepts this report for implementation.
  - Proof: current supervisor callback instructed Agent-B001 to proceed with the accepted implementation callback for [UID:0002IE] `HierListRemoveNode`, using this report and the actual target path `by-memory/0x004ceb00-0x004ceb45.HierListRemoveNode.md`.
- [x] Lease only immediate accepted edit files immediately before implementation; do not lease during supervisor review.
  - Proof: immediate B001 leases were active only for `by-memory/0x004ceb00-0x004ceb45.HierListRemoveNode.md`, `by-class/HierList.md`, `by-file/HierList.md`, and `by-memory/0x004ce730-0x004cee52.HierList.md` during the edit/validator batch.
- [x] Update [UID:0002IE] target metadata to `COMPLETION:90`, `CONFIDENCE:92`; keep owner/emitter/reconstructable metadata unchanged.
  - Proof: target header now has `COMPLETION:90`, `CONFIDENCE:92`, `CANONICAL_OWNER:000065`, `RECONSTRUCTABLE:TRUE`, and `EMITTER_UIDS:000065`.
- [x] Insert exact `void HierList::RemoveByPayload(const void *payload)` formal C++ block into [UID:0002IE].
  - Proof: [UID:0002IE] formal `RECONSTRUCTION_CPP CODE` block now contains `void HierList::RemoveByPayload(const void *payload)` with `FindNodeByPayload(payload, &ownerList, &index)`, null-node return, `delete node->childList`, `node->childList = NULL`, and `ownerList->RemoveAt(index, 1)`.
- [x] Add current MCP provenance and exact target evidence to [UID:0002IE].
  - Proof: [UID:0002IE] section `2026-06-26 B001 Accepted Source-Quality Implementation` records active MCP session `80de0a67`, endpoint/schema/health readiness, `lookup_funcs`, `xrefs_to`, `callees`, `analyze_function`, `get_bytes`, unique signature, `find_bytes` negative checks, Layer caller context, and the decompile/disasm sequence.
- [x] Add source-form decision and rejected alternatives to [UID:0002IE].
  - Proof: [UID:0002IE] now records `RemoveByPayload` as the source-facing name, `HierListRemoveNode` as a stable by-memory label, inferred `void` return rationale, source-level `delete` instead of hand-authored scalar-deleting-destructor ABI, and rejected blank-C++, `HierListRemoveNode` primary source spelling, generic `Remove`, `int` return, `Layer` ownership, `List` ownership, aggregate emission, and hand-coded destructor-wrapper alternatives.
- [x] Update [UID:000065] `by-class/HierList.md` with the `RemoveByPayload` declaration/source role and relation to `FindNodeByPayload`.
  - Proof: `by-class/HierList.md` method map and ownership notes now list [UID:0002IE] as accepted formal `HierList::RemoveByPayload(const void *payload)` exact-child C++; support text records the `FindNodeByPayload(payload, &ownerList, &index)` dependency, `HierListNode::childList`, and owner-list `RemoveAt(index, 1)`.
- [x] Update [UID:0000JV] `by-file/HierList.md` so `0x004ceb00` is no longer listed as an unresolved blank remove helper.
  - Proof: `by-file/HierList.md` proposed contents and migration notes now list `0x004ceb00` as formal `HierList::RemoveByPayload(const void *payload)` exact-child C++; changes section records removal from the unresolved blank remove-helper bucket.
- [x] Update [UID:00016X] aggregate child table/source-quality notes for formal [UID:0002IE] exact-child C++ while keeping aggregate non-emitting.
  - Proof: `by-memory/0x004ce730-0x004cee52.HierList.md` keeps `RECONSTRUCTABLE:FALSE` and blank `EMITTER_UIDS`; child table, evidence notes, autogen status, source-quality decisions, and changes section now identify [UID:0002IE] as formal `HierList::RemoveByPayload` exact-child C++.
- [x] If optional support notes are edited, update only the relevant support files listed above; do not broaden into unrelated HierList methods.
  - Proof: optional support files were not edited; implementation was limited to the accepted target plus required `HierList` class/file/aggregate support docs.
- [x] Do not manually edit generated files, project-level files, validator state/cache, IDA DB, `by-memory/-coverage-report.md`, or any `-coverage-report.md`.
  - Proof: no manual edits were made to generated/project-level/coverage/tool/IDA files. Validator side effects were tool-owned: validator registry/stat updates, projected stats updates, research tracker update during the by-file pass, and completed generated refresh.
- [x] Run scoped validators for every changed `by-*` file and record command, working directory, exit code, command id/timestamp, `ok` count, and generated-refresh state.
  - Proof:
    - Working directory for all validators: `E:\NTK\GhidraBridge\source-3\project-documentation`.
    - `python .\tools\validator.py --mode file --file by-memory\0x004ceb00-0x004ceb45.HierListRemoveNode.md --apply --queue-timeout 240 --wait-generated` -> command_id `000000002500`, command_timestamp `2026-06-26T06:19:04-04:00`, exit code `0`, `ok: 1`, `generated_refresh: completed`, generated_refresh_command_id `000000002500`, generated_refresh_timestamp `2026-06-26T06:19:04-04:00`.
    - `python .\tools\validator.py --mode file --file by-class\HierList.md --apply --queue-timeout 240 --wait-generated` -> command_id `000000002502`, command_timestamp `2026-06-26T06:19:29-04:00`, exit code `0`, `ok: 1`, `generated_refresh: completed`, generated_refresh_command_id `000000002502`, generated_refresh_timestamp `2026-06-26T06:19:29-04:00`.
    - `python .\tools\validator.py --mode file --file by-file\HierList.md --apply --queue-timeout 240 --wait-generated` -> command_id `000000002504`, command_timestamp `2026-06-26T06:19:50-04:00`, exit code `0`, `ok: 1`, `generated_refresh: completed`, generated_refresh_command_id `000000002504`, generated_refresh_timestamp `2026-06-26T06:19:50-04:00`.
    - `python .\tools\validator.py --mode file --file by-memory\0x004ce730-0x004cee52.HierList.md --apply --queue-timeout 240 --wait-generated` -> command_id `000000002505`, command_timestamp `2026-06-26T06:20:08-04:00`, exit code `0`, `ok: 1`, `generated_refresh: completed`, generated_refresh_command_id `000000002505`, generated_refresh_timestamp `2026-06-26T06:20:08-04:00`.
    - Scoped validators reported existing unrelated stale-registry/missing-file diagnostics; no target-specific validation failure was reported.
- [x] Release every implementation lease immediately after the edit/validator batch.
  - Proof: ran `python .\tools\leaser\leaser.py B001 unlease by-memory\0x004ceb00-0x004ceb45.HierListRemoveNode.md by-class\HierList.md by-file\HierList.md by-memory\0x004ce730-0x004cee52.HierList.md`; all four returned `Rejected[No active lease]`, meaning the short lease had already expired or cleared by cleanup time. Follow-up `tools/leaser/Agents/current_leases.md` shows no B001 entries. It does show later B011 leases on related HierList support files after B001's cleanup, so B001 has no active lock remaining.
- [x] Perform post-validation read-only checks for [UID:0002IE] target header/C++ and generated `HierList.cpp` [UID:0002IE] marker/body state.
  - Proof: read-only checks confirmed [UID:0002IE] target header `90/92` with unchanged owner/emitter/reconstructable fields and formal `RemoveByPayload` C++ block. `auto-generated/NexusTK/util/HierList.cpp` already emits [UID:0002IE] at `Completion:90`, `Confidence:92` with `void HierList::RemoveByPayload(const void *payload)`, but its generated header still reports validator-command-id `000000002496`, older than this implementation's `--wait-generated` validator commands. No manual generated-file edit was made.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B001","command_id":"000000004165","destination_path":"executed-b-agent-research/B001/0002IE-HierListRemoveNode-source-quality.md","details":"legacy registry reconstruction","event":"executed","source_path":"tools/leaser/Agents/Agent-B001/research/0002IE-HierListRemoveNode-source-quality.md","timestamp":"2026-06-26T06:32:31","uid":"0002IE"} -->
<!-- {"agent":"B001","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 0002IE-HierListRemoveNode-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B001/0002IE-HierListRemoveNode-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"0002IE"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
