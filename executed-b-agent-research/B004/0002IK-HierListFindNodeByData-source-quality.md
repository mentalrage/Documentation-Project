** TARGET-REPORT-UID:0002IK **
** AUTHOR-AGENT-ID:B004 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# Agent-B004 Report - [UID:0002IK] HierListFindNodeByData Source Quality

Agent: Agent-B004
Assignment id: B004-rework-0002IK-HierListFindNodeByData-20260625
Mode: rejected report rework
Report date: 2026-06-25

Target: [UID:0002IK] `by-memory/0x004cec30-0x004ced0f.HierListFindNodeByData.md`
Source queue: `auto-generated/-ag-research-tracker.md`, `## by-memory` -> `### Not-Covered Files - Reconstructable`

## Original Report-Only Compliance

The pre-acceptance research pass edited only this B004 report file. It did not edit target/support by-* docs, generated files, project-level files, validator state/cache, IDA DB, `by-memory/-coverage-report.md`, or any `-coverage-report.md`. No leases were taken during report-only work. No subagents were spawned.

IDA MCP was available and used. The report is not fallback-only.

Implementation callback compliance, leases, validators, support-doc edits, and generated side effects are recorded in the checked implementation tracking checklist below.

## Executive Recommendation

Keep [UID:0002IK] as a source-authored, reconstructable `HierList` class helper owned and emitted through [UID:000065] `HierList`, with [UID:0000JV] `NexusTK/util/HierList.cpp` as the file route.

Recommended metadata after implementation:

| Field | Current target header | Recommended |
| --- | ---: | ---: |
| `COMPLETION` | 87 | 91 |
| `CONFIDENCE` | 89 | 92 |
| `CANONICAL_OWNER` | 000065 | 000065 |
| `RECONSTRUCTABLE` | TRUE | TRUE |
| `EMITTER_UIDS` | 000065 | 000065 |
| Formal C++ | blank | add exact `HierList::FindNodeByPayload` method body |

Reason: current MCP confirms the exact function object, end boundary, padding, xrefs, caller/callee set, recursive child-list `this` flow, payload byte-compare semantics, and out-parameter writes. The rejected report treated missing generated scaffolding as a blocker; this rework resolves that blocker by using the best source-facing inferred names and by moving the required declarations/layout support into [UID:000065] `HierList`, [UID:0001UQ] `HierListNode`, and [UID:000079] `List` support notes instead of leaving the above-gate target blank. The target is a complete source-authored function body and can safely carry first-draft formal C++ now.

## Current Target State

`by-memory/0x004cec30-0x004ced0f.HierListFindNodeByData.md` currently has:

- Header: `COMPLETION:87`, `CONFIDENCE:89`, `CANONICAL_OWNER:000065`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:000065`, blank formal C++.
- Item summary: recursively byte-compares payloads and returns matched row plus owner list and zero-based index out parameters.
- Correct current owner/source route: [UID:000065] `HierList` -> [UID:0000JV] `NexusTK/util/HierList.cpp`.
- Internal inconsistency: the header is `87/89`, but the `Score Rationale` table still says `86/88`.
- Generated-state caveat: `auto-generated/-ag-research-tracker.md` still lists this row as `76/86`, `auto-generated/-ag-coverage-report-by-memory.md` still renders stale `emits_code:false`, and `auto-generated/NexusTK/util/HierList.cpp` still shows [UID:0002IK] as `Completion:76 | Confidence:86 | Empty Emitter Marker`. These generated files are read-only inputs here; implementation should use validators, not manual generated edits, to refresh them.

Support docs reviewed:

- `by-class/HierList.md`
- `by-file/HierList.md`
- `by-type/by-struct/HierListNode.md`
- `by-memory/0x004ce730-0x004cee52.HierList.md`
- caller/support children [UID:0002IA]-[UID:0002IL] where relevant, especially [UID:0002IC], [UID:0002ID], [UID:0002IE], [UID:0002IF], and [UID:0002IL]
- `by-class/List.md`, [UID:0003JW] `by-memory/0x004f32b0-0x004f32da.ListGetElementAt.md`, `by-class/Layer.md`
- `by-project-structure/proposed-source-tree.md`
- executed report `executed-b-agent-research/B001/00016X-hierlist-source-quality.md`

## Live IDA MCP Evidence

Active MCP provenance:

- Endpoint `http://127.0.0.1:13337/mcp` responded to `initialize`, `tools/list`, `idb_list`, `server_health`, and target inspection calls.
- Session: `80de0a67`
- IDB: `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`
- Module/input: `NexusTK.exe`; imagebase `0x400000`
- Health: `status:"ok"`, auto-analysis ready, Hex-Rays ready, strings cache ready.
- Current schema was checked. Relevant active call shapes were `lookup_funcs(queries,database)`, `decompile(addr,database)`, `disasm(addr,database)`, `xrefs_to(addrs,database)`, `callees(addrs,database)`, `analyze_function(addr,database)`, `get_bytes(regions,database)`, and `make_signature_for_range(start,end,database)`. An old-style `func_profile(addr,database)` call was not used because the current schema expects `queries`; the profile facts below come from `analyze_function` and `disasm`.

Function and boundary facts:

- `lookup_funcs` reports `sub_4CEC30` at `0x004cec30`, size `0xdf`; `0xdf` is 223 decimal bytes (Verified with `int_convert.py`).
- `lookup_funcs 0x004ced0e` resolves inside `sub_4CEC30`.
- `lookup_funcs 0x004ced0f` reports not a function.
- `lookup_funcs 0x004ced10` reports successor `sub_4CED10`, size `0x94`.
- `lookup_funcs 0x004cec22` reports not a function; the preceding [UID:0002IJ] function ends before alignment.
- `get_bytes 0x004cec20 size 256` shows `0xcc` alignment before `0x004cec30`, the `sub_4CEC30` prologue `55 8b ec 83 ec 08 ...`, the epilogue `33 c0 5f 5e 5b 8b e5 5d c2 0c 00`, then one `0xcc` at `0x004ced0f` before the `0x004ced10` prologue.
- `make_signature_for_range 0x004cec30-0x004ced0f` returns a unique wildcarded IDA signature.

Function profile and call graph:

- `analyze_function 0x004cec30` reports size `0xdf`, 89 instructions, 26 basic blocks, cyclomatic complexity 19, prototype `int __thiscall(_DWORD *this, int, _DWORD *, int *)`, callers `sub_4CE860`, `sub_4CE9B0`, `sub_4CEB00`, and self-recursion, and no string refs.
- `callees 0x004cec30` reports only `sub_4F32B0` and recursive `sub_4CEC30`.
- `xrefs_to 0x004cec30` reports nine code refs:
  - `0x004ce812`, no modeled function, inside raw [UID:0002IA] tail insert wrapper.
  - `0x004ce8d5`, `0x004ce906`, `0x004ce974` in [UID:0002IC] `HierListInsertBefore`.
  - `0x004cea28`, `0x004cea59`, `0x004ceac3` in [UID:0002ID] `HierListInsertAfter`.
  - `0x004ceb12` in [UID:0002IE] `HierListRemoveNode`.
  - `0x004cecca` inside `sub_4CEC30` itself.

Payload compare and recursion:

- Disassembly at `0x004cec38` stores `ecx` as the current `HierList*`; `0x004cec42` compares row index `edi` against `[esi+0x0c]`, the current list count.
- `0x004cec5b` calls base `List::GetElementAt` at `0x004f32b0` for the raw row pointer. The function does not call the `HierList` virtual payload accessor.
- `0x004cec63` loads the requested payload pointer from `arg_0`.
- `0x004cec66` subtracts `0x0b` from `[this+0x04]`, so the compare length is `elementSizeWithHierarchyOverhead - 0x0b`; `0x0b` is 11 decimal (Verified with `int_convert.py`).
- `0x004cec6c` compares against `row + 0x08`; `0x08` is 8 decimal (Verified with `int_convert.py`).
- `0x004cec74-0x004cec83` are the dword equality loop; `0x004cec8a-0x004cecb5` are byte-tail checks for up to three remaining bytes. This is byte-value equality, not pointer equality.
- On mismatch, `0x004cecba` loads `ecx = [row+0x04]`, tests for a child `HierList*`, pushes the same three explicit arguments at `0x004cecc1`, `0x004cecc4`, and `0x004cecc7`, and calls `sub_4CEC30` at `0x004cecca`. This disassembly corrects the decompiler caveat: Hex-Rays prints the recursive call as if it omitted the `this` argument, but `ecx` is the child list.
- A nonzero descendant result is stored at `0x004cecd1` and marks the search successful at `0x004cecd4`; the current loop then returns that descendant result without overwriting the child-owned out parameters.

Out-parameter writes:

- On local match, `0x004cecd9-0x004cece3` tests the second explicit argument and writes the current `HierList*` to `*outOwnerList`.
- `0x004cece5-0x004cecec` tests the third explicit argument and writes `edi`, the current loop row, to `*outIndex`.
- `0x004ced04` returns zero on miss; `0x004ced0c` returns with `retn 0Ch`, consuming three explicit stack arguments. `0x0c` is 12 decimal (Verified with `int_convert.py`).

Caller usage:

- [UID:0002IC] `HierListInsertBefore` call sites use local out storage:
  - `0x004ce8ca-0x004ce8d5` passes `&var_14` and `&var_10` while resolving a parent payload.
  - `0x004ce96b-0x004ce974` passes `&var_10` as the index output for sibling/reference lookup.
  - `0x004ce979-0x004ce97e` uses the resolved owner list and index before insertion.
- [UID:0002ID] `HierListInsertAfter` mirrors the same owner/index use:
  - `0x004cea1d-0x004cea28` passes owner/index locals for parent lookup.
  - `0x004ceaba-0x004ceac3` passes `&var_10` for sibling/reference lookup.
  - `0x004ceacb-0x004ceacc` proceeds to push insertion arguments after the resolved index path.
- [UID:0002IE] `HierListRemoveNode` passes a local index address before `0x004ceb12`, stores the returned node in `esi`, reads child list `node+0x04`, and later removes one row from the owner list using the found index.
- [UID:0002IA] documents the raw wrapper call at `0x004ce812` as a parent lookup used to choose a child-list tail sibling before forwarding to the insert-before core.

## Heuristic / Inference Reanalysis

Best source-facing role:

- Existing documentation name `HierListFindNodeByData` is a stable page label.
- Best source-facing method role remains `FindNodeByPayload`: every live route treats the first explicit argument as caller payload bytes, not a `HierListNode*`, and the function returns the full matched row node so callers can inspect/delete child state.
- `FindNodeByData` is not wrong as a documentation alias, but `FindNodeByPayload` is more precise for emitted source because the comparison target is `HierListNode + 0x08` payload bytes.

Accepted layout facts:

- `this + 0x04` is inherited `List::m_elementSize` with HierList overhead included.
- `this + 0x0c` is inherited `List::m_count`.
- `row + 0x00` is the parent node pointer, supported by [UID:0001UQ] and [UID:0002IL].
- `row + 0x04` is child `HierList*`, proven again by `0x004cecba` child recursion.
- `row + 0x08` is caller payload start, proven by the compare target and [UID:0002IF] payload accessor.
- The compare length remains `elementSize - 0x0b`, so the trailing three bytes in the list stride still have no target-local semantic load/store evidence. They should remain documented as trailing reserved/padding bytes, not flags.

Best formal source-shape inference for this target:

- Method name: use `HierList::FindNodeByPayload`. It is stronger than `FindNodeByData` for emitted code because the function accepts caller payload bytes, compares those bytes against `HierListNode::payload`, and returns the containing `HierListNode*`. Keep `HierListFindNodeByData` only as the stable by-memory page/search alias.
- Return type: use `HierListNode*`. The returned address is the raw row pointer from base `List::GetElementAt`, not `void* payload`, and [UID:0002IE] consumes the returned row's `childList` field before removing it.
- Payload parameter: use `const void *payload`. Callers pass caller-owned payload records; the function never writes through the pointer and only byte-compares it.
- Owner-list out parameter: use `HierList **outOwnerList`. Local matches write the current `this`; descendant matches preserve the child-owned write from recursion.
- Index out parameter: use `int *outIndex`. The function writes `edi`, a zero-based row index used by insert/remove paths.
- Raw row access: call `List::GetElementAt(index)` explicitly, not `GetElementAt(index)`, because the binary calls the base row accessor `0x004f32b0`; the `HierList` virtual override [UID:0002IF] would add `0x08` and return payload only.
- Fields used by the method body: inherited `m_elementSize` and `m_count` from [UID:000079] `List`; `HierListNode::childList` at `+0x04`; `HierListNode::payload` at `+0x08`.
- Compare expression: `memcmp(payload, node->payload, m_elementSize - 11) == 0` is the best source-facing representation. The binary is a compiler-emitted dword loop plus byte tail for exact byte equality; a hand-written dword loop would be decompiler-shaped and less plausible than a source `memcmp` or equivalent byte comparison.

Ownership/source placement:

- Confirmed owner: [UID:000065] `HierList`.
- Confirmed file route: [UID:0000JV] `NexusTK/util/HierList.cpp`.
- Parent aggregate [UID:00016X] remains a non-emitting split/index. This exact child page is the source-bearing method documentation route.
- `Layer` is a consumer/caller source for public operation names, not owner of the recursive lookup helper.
- `List` owns the base fixed-width storage/accessor, not the hierarchy-aware recursive search.

## Rejected Alternatives

1. Move the method to `Layer`.
   Rejected. Current xrefs show Layer reaches the search only through HierList insert/remove paths. The searched structure is a `HierList` node tree with a HierList vtable and child `HierList*` recursion.

2. Move the method to `List`.
   Rejected. The only `List` role is `sub_4F32B0`, the base element-address helper. The recursive child-list pointer, owner-list out parameter, payload offset `+0x08`, and `elementSize - 0x0b` compare are HierList-specific.

3. Reclassify the target as a non-emitting child of aggregate [UID:00016X].
   Rejected. [UID:00016X] is already the non-emitting physical index. [UID:0002IK] is an exact modeled function and source-authored helper body; it should stay reconstructable/emitting through [UID:000065].

4. Rename the by-memory file now to `HierListFindNodeByPayload`.
   Rejected for this callback unless the supervisor explicitly wants a rename. The stable UID and existing cross-references already identify the target, and class/file docs can record `FindNodeByPayload` as the best source-facing role without path churn.

5. Treat the compare as pointer equality.
   Rejected. MCP disassembly proves dword and byte-tail value comparisons against `row + 0x08`.

6. Treat `0x004ced0f` as part of the function.
   Rejected. `lookup_funcs 0x004ced0f` reports not a function, bytes show one `0xcc` alignment byte, and `0x004ced10` starts [UID:0002IL].

7. Leave formal C++ blank because generated `HierList.cpp` still has empty markers.
   Rejected in this rework. Current Rule 26/code-entry rules require a best defensible formal body for an above-gate complete function unless rare target-specific evidence closes every source-shape route. The support docs already document the needed layout fields and accessors strongly enough to carry inferred declarations; missing generated output is a validator/source-sequencing symptom, not a blocker for this exact method body.

8. Use a minimal covered-by/comment block instead of a method body.
   Rejected. [UID:0002IK] is itself the full source-bearing function range and is not covered by another emitting method. A covered-by comment would hide an eligible exact function body and would not improve generated `HierList.cpp`.

## Formal C++ Disposition

Formal `RECONSTRUCTION_CPP CODE` for [UID:0002IK] should be added now. Exact insertion text for the target page's `RECONSTRUCTION_CPP CODE:BEGIN/END` block:

```cpp
HierListNode *HierList::FindNodeByPayload(const void *payload, HierList **outOwnerList, int *outIndex)
{
    const int payloadSize = m_elementSize - 11;

    for (int index = 0; index < m_count; ++index) {
        HierListNode *node = static_cast<HierListNode *>(List::GetElementAt(index));
        if (memcmp(payload, node->payload, payloadSize) == 0) {
            if (outOwnerList != NULL) {
                *outOwnerList = this;
            }
            if (outIndex != NULL) {
                *outIndex = index;
            }
            return node;
        }

        if (node->childList != NULL) {
            HierListNode *found = node->childList->FindNodeByPayload(payload, outOwnerList, outIndex);
            if (found != NULL) {
                return found;
            }
        }
    }

    return NULL;
}
```

Why this is target-range safe:

- The code is only the full method body represented by `0x004cec30-0x004ced0f`; it does not paste class declarations, node declarations, base `List` methods, or sibling HierList methods into this by-memory page.
- `List::GetElementAt(index)` expresses the direct base call to `0x004f32b0` and avoids the derived virtual payload accessor at [UID:0002IF].
- `memcmp(payload, node->payload, payloadSize) == 0` expresses the source-level byte equality that the compiler lowered into the observed dword loop plus byte tail. It preserves zero-length equality, exact byte-value comparison, and no pointer-equality behavior.
- The local-match path writes `this` and the zero-based local index only when the corresponding out pointer is non-null, then returns the raw node pointer.
- The child path recurses through `node->childList` with the same three explicit arguments and returns the descendant row without overwriting descendant-owned out parameters.
- The miss path returns `NULL`.

Support declaration/source-shape requirements for implementation:

- [UID:000065] `by-class/HierList.md` should record the private method declaration `HierListNode *FindNodeByPayload(const void *payload, HierList **outOwnerList, int *outIndex);` and the fact that this exact child now provides formal method C++ even while the broader class still needs a coordinated source pass for wrappers/destructors.
- [UID:0001UQ] `by-type/by-struct/HierListNode.md` should support the field names used by the body: `HierListNode *parent`, `HierList *childList`, and `unsigned char payload[1]` or an equivalent flexible payload spelling, with the existing note that the extra three stride bytes remain trailing reserved/padding bytes.
- [UID:000079] `by-class/List.md` already documents `m_elementSize`, `m_count`, and `List::GetElementAt`; implementation should add or confirm a support note that derived `HierList` method bodies use those inherited fields and an explicit base accessor call.
- [UID:0000JV] `by-file/HierList.md` should record that the file-level source scaffold needs the C runtime byte-compare declaration, for example `<string.h>`, for this method body's `memcmp` call.

## Score And Metadata Rationale

Recommend `91/92` rather than the rejected `89/91` blank-code recommendation:

- Completion can rise from 87 to 91 because the target can now carry current-session MCP evidence plus formal source-level method C++, source-facing names, and support declaration requirements for the exact emitted method body.
- Confidence can rise from 89 to 92 because current disassembly and xrefs independently confirm the decompiler's behavior, correct its recursive-call caveat, and support the chosen C++ names/types through existing `HierList`, `HierListNode`, and `List` documentation.
- Keep below final-audit territory because exact original spellings are still inferred, `memcmp` is a source-level reconstruction of the compiler's byte-compare lowering rather than recovered source text, and the broader `HierList` class/wrapper/destructor source pass remains incomplete.
- Keep `CANONICAL_OWNER:000065`, `RECONSTRUCTABLE:TRUE`, and `EMITTER_UIDS:000065`.
- No split, merge, range rename, owner change, or emitter change is recommended.

## Recommended Implementation Edits If Accepted

Target doc: `by-memory/0x004cec30-0x004ced0f.HierListFindNodeByData.md`

- Update header scores to `COMPLETION:91` and `CONFIDENCE:92`.
- Sync the `Score Rationale` table to the header.
- Add current 2026-06-25 MCP session evidence: session `80de0a67`, database path, server health, checked schema, function lookup, boundary/padding bytes, unique signature, xrefs, callers/callees, compare-loop instructions, child-list recursion, and out-parameter writes.
- Keep owner/emitter/reconstructable metadata unchanged.
- Insert the formal `HierListNode *HierList::FindNodeByPayload(const void *payload, HierList **outOwnerList, int *outIndex)` C++ body above into the target `RECONSTRUCTION_CPP CODE:BEGIN/END` block.
- Preserve the best source-facing name conclusion: `FindNodeByPayload` is the emitted method name; the current by-memory page name can remain stable as a search/documentation alias.
- Add a `Changes` entry for the B004 source-quality report.

Support docs:

- `by-class/HierList.md`: add a B004 rework note that [UID:0002IK] now has formal first-draft method C++, declare/source-shape the private `FindNodeByPayload(const void *, HierList **, int *)` method, and clarify that broader wrappers/destructors still need coordinated class-wide C++.
- `by-file/HierList.md`: add a current evidence bullet that 2026-06-25 MCP session `80de0a67` reconfirmed `0x004cec30` fan-in from the raw wrapper, insert-before, insert-after, remove, and self-recursion; [UID:0002IK] should no longer be treated as an empty-marker-only blocker after implementation; and the file-level source scaffold should include the C runtime byte-compare declaration needed for `memcmp`.
- `by-type/by-struct/HierListNode.md`: add a support note that the B004 target-specific pass reconfirmed the source-facing fields `parent`, `childList`, and `payload`, with `childList` at `+0x04`, payload compare start at `+0x08`, and no semantic evidence for the trailing three stride bytes.
- `by-class/List.md`: add or confirm a support note that HierList method C++ relies on inherited `m_elementSize`/`m_count` and an explicit `List::GetElementAt` base call for raw rows; [UID:0003JW] already documents the accessor behavior and needs no separate edit unless the supervisor wants a cross-reference.

Generated/project-level/coverage:

- Do not manually edit generated files, `project-level` reports, validator state/cache, `by-memory/-coverage-report.md`, or any `-coverage-report.md`.
- After implementation validators, generated reports should be allowed to refresh from source docs. If `auto-generated/NexusTK/util/HierList.cpp` or `auto-generated/-ag-research-tracker.md` still show stale scores afterward, report that as validator/generated-state lag rather than hand-editing.

Validators after accepted implementation:

> Executable block R001 was removed from this report and preserved verbatim in [0002IK-HierListFindNodeByData-source-quality-removed.md](0002IK-HierListFindNodeByData-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

`by-class/List.md` was not edited because it already contained same-or-greater support detail for inherited `m_elementSize`/`m_count` and `List::GetElementAt`; no List validator was required.

## Implementation Tracking Checklist

Implementation callback proof, 2026-06-25:

- [x] Lease only the accepted editable files immediately before implementation; do not lease during research or supervisor review.
  Proof: from `source-3/project-documentation`, ran `python .\tools\leaser\leaser.py Agent-B004 lease by-memory\0x004cec30-0x004ced0f.HierListFindNodeByData.md by-class\HierList.md by-file\HierList.md by-type\by-struct\HierListNode.md`; exit code `0`; each of the four paths returned `Success`. No lease was taken for `by-class/List.md` because no edit was needed.
- [x] Update `by-memory/0x004cec30-0x004ced0f.HierListFindNodeByData.md` header scores to `91/92`; keep `CANONICAL_OWNER:000065`, `RECONSTRUCTABLE:TRUE`, and `EMITTER_UIDS:000065`.
  Proof: post-validator readback shows target header `COMPLETION:91`, `CONFIDENCE:92`, `CANONICAL_OWNER:000065`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:000065`, and blank `EMITTER_POSITION_OPTIONAL`.
- [x] Sync the target `Score Rationale` table and caveats to the new score and current evidence.
  Proof: target `Score Rationale` now records `Completion | 91` and `Confidence | 92`; `Confidence And Caveats` now states formal first-draft C++ is supported while remaining below final audit for inferred source spelling and broader class cleanup.
- [x] Add the 2026-06-25 MCP provenance and schema/session facts to the target page.
  Proof: target section `2026-06-25 MCP Refresh` records endpoint `http://127.0.0.1:13337/mcp`, session `80de0a67`, IDB `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, module/imagebase, health, and checked schema call shapes.
- [x] Add boundary evidence for `0x004cec30-0x004ced0f`, one-byte `0xcc` padding at `0x004ced0f-0x004ced10`, successor [UID:0002IL], and the unique signature result.
  Proof: target `2026-06-25 MCP Refresh` and `Boundary Evidence` sections record `lookup_funcs` at `0x004cec30`, inside/end/successor checks, bytes before/after, the `0x004ced0f` alignment byte, [UID:0002IL] successor, and unique `make_signature_for_range` result.
- [x] Add behavior evidence for `sub_4F32B0` raw-row access, `elementSize - 0x0b` compare length, `row + 0x08` payload compare, dword loop plus byte tail, child-list recursion through `row + 0x04`, and zero return on miss.
  Proof: target `Behavior` details `0x004cec5b` base `List::GetElementAt`, `0x004cec66` `m_elementSize - 0x0b`, `0x004cec6c` `row+0x08`, `0x004cec74-0x004cec83` dword loop, `0x004cec8a-0x004cecb5` byte tail, `0x004cecba-0x004cecca` child recursion, and `0x004ced04` miss return.
- [x] Add caller/callee evidence preserving all nine code refs to `0x004cec30`, including raw wrapper ref `0x004ce812`, three insert-before refs, three insert-after refs, remove ref `0x004ceb12`, and self-recursion `0x004cecca`.
  Proof: target `2026-06-25 MCP Refresh` lists all nine refs: `0x004ce812`, `0x004ce8d5`, `0x004ce906`, `0x004ce974`, `0x004cea28`, `0x004cea59`, `0x004ceac3`, `0x004ceb12`, and `0x004cecca`; direct callees are [UID:0003JW] `ListGetElementAt` and self-recursion.
- [x] Add out-parameter evidence: optional owner-list write from current `this` and optional zero-based index write from loop register `edi`; note callers consume those outputs for insert/remove decisions.
  Proof: target `Behavior` records `0x004cecd9-0x004cece3` owner write, `0x004cece5-0x004cecec` `edi` index write, descendant out-param preservation, and caller use by insert-before, insert-after, and remove.
- [x] Add the source-facing name decision: `FindNodeByPayload` is the emitted method name; stable by-memory page name can remain unchanged as a search/documentation alias.
  Proof: target `Status` and `Source Shape And Rejected Alternatives` record `HierList::FindNodeByPayload` as emitted method name and `HierListFindNodeByData` as stable by-memory alias; no file rename was made.
- [x] Insert the exact formal `RECONSTRUCTION_CPP CODE:BEGIN/END` method body from this report into the target page.
  Proof: post-validator readback shows the exact formal `HierListNode *HierList::FindNodeByPayload(const void *payload, HierList **outOwnerList, int *outIndex)` body between the target `RECONSTRUCTION_CPP CODE:BEGIN/END` markers.
- [x] Add support declaration notes required by that method body: `HierListNode *FindNodeByPayload(const void *payload, HierList **outOwnerList, int *outIndex)`, raw row access through `List::GetElementAt(index)`, inherited `m_elementSize`/`m_count`, `HierListNode::childList`, and `HierListNode::payload`.
  Proof: target `Source Shape And Rejected Alternatives` and `by-class/HierList.md` now record the private declaration and source-shape requirements; `by-class/HierList.md` explicitly names inherited `m_elementSize`/`m_count`, `List::GetElementAt(index)`, `HierListNode::payload`, and `HierListNode::childList`.
- [x] Add rejected alternatives: `Layer` owner, `List` owner, aggregate non-emitter reclassification, by-memory rename churn, pointer-compare interpretation, endpoint extension into `0x004ced0f`, blank-C++/empty-marker excuse, and covered-by/comment-only block.
  Proof: target `Source Shape And Rejected Alternatives` lists and rejects all eight alternatives.
- [x] Update `by-class/HierList.md` with the B004 rework note and private method declaration/source-shape context.
  Proof: `by-class/HierList.md` method map now marks [UID:0002IK] as formal first-draft `HierList::FindNodeByPayload` C++; `Ownership Notes`, `Autogen Status`, and `Changes` include the private declaration and broader class-pass caveat.
- [x] Update `by-file/HierList.md` with the B004 current MCP fan-in note, state that [UID:0002IK] now has formal method C++ after this callback, and record the file-level `memcmp` include/declaration requirement.
  Proof: `by-file/HierList.md` `Evidence`, `Migration Notes`, and `Changes` now record session `80de0a67` fan-in, exact-child formal `FindNodeByPayload` C++, and the `<string.h>` or equivalent `memcmp` declaration requirement.
- [x] Update `by-type/by-struct/HierListNode.md` with the reconfirmed `parent`/`childList`/`payload` field names and trailing-byte note.
  Proof: `by-type/by-struct/HierListNode.md` `Layout`, `IDA Evidence`, and `Changes` now record source-facing `parent`, `childList`, and `payload`, `childList` at `+0x04`, payload at `+0x08`, and no semantic evidence for trailing stride bytes.
- [x] Update or confirm `by-class/List.md` support for inherited `m_elementSize`/`m_count` and explicit base `List::GetElementAt` raw-row access; if no edit is made, record that the existing List doc already contains same-or-greater detail.
  Proof: no `by-class/List.md` edit was made. Readback confirms same-or-greater existing detail: `m_elementSize` at line 45, `m_count` at line 47, vtable slot `List::GetElementAt` at line 61, and method row at line 76 returning `data + index * elementSize` for valid indexes.
- [x] Run the scoped validator(s) from `source-3/project-documentation` with `--wait-generated` for every changed by-* file and record command, exit code, `command_id`, `command_timestamp`, `ok` count, and generated-refresh state.
  Proof: working directory for all runs was `E:\NTK\GhidraBridge\source-3\project-documentation`; validator resolved root `C:\FastStorage\NTK_Sources\source-3\project-documentation`.
  - `python .\tools\validator.py --mode file --file by-memory\0x004cec30-0x004ced0f.HierListFindNodeByData.md --apply --queue-timeout 240 --wait-generated`; exit `0`; `command_id: 000000001858`; `command_timestamp: 2026-06-25T17:29:32-04:00`; `ok: 1`; `generated_refresh: completed`; side effects included `completion_update`, `confidence_update`, `canonical_owner_update`, `autogen_registry_update`, `autogen_cpp_update:1`, `memory_auto_coverage_update:1`, `research_tracker_update:1`, `projected_stats_update:1`, `uid_link_insert:1`, `uid_link_update:4`, `reference_index_add:7`, and `autogen_backup_create:3`.
  - `python .\tools\validator.py --mode file --file by-class\HierList.md --apply --queue-timeout 240 --wait-generated`; exit `0`; `command_id: 000000001860`; `command_timestamp: 2026-06-25T17:29:55-04:00`; `ok: 1`; `generated_refresh: completed`; side effects included `canonical_owner_update`, `autogen_registry_update:2`, `uid_link_update:1`, `projected_stats_update:1`, and `autogen_backup_create:3`.
  - `python .\tools\validator.py --mode file --file by-file\HierList.md --apply --queue-timeout 240 --wait-generated`; exit `0`; `command_id: 000000001862`; `command_timestamp: 2026-06-25T17:30:09-04:00`; `ok: 1`; `generated_refresh: completed`; side effects included `completion_update`, `confidence_update`, `canonical_owner_update`, `reference_index_add:1`, `research_tracker_update:1`, `memory_auto_coverage_update:1`, `autogen_report_update:1`, `autogen_cpp_update:1`, `projected_stats_update:1`, and `autogen_backup_create:3`.
  - `python .\tools\validator.py --mode file --file by-type\by-struct\HierListNode.md --apply --queue-timeout 240 --wait-generated`; exit `0`; `command_id: 000000001864`; `command_timestamp: 2026-06-25T17:30:24-04:00`; `ok: 1`; `generated_refresh: completed`; side effects included `completion_update`, `confidence_update`, `canonical_owner_update`, `autogen_registry_update:2`, `reference_index_add:1`, `research_tracker_update:1`, `autogen_cpp_update:1`, `projected_stats_update:1`, and `autogen_backup_create:3`.
  Common validator warnings/metadata notices across the batch were project-wide generated-state notices, not target failures: `autogen_registry_stale:159`, `memory_coverage_metadata_missing_file:157`, `autogen_emitter_has_no_code:433`, and `autogen_children_marker_missing:9`.
- [x] Do not manually edit `auto-generated/*`, `project-level/*`, validator state/cache, IDA DB, `by-memory/-coverage-report.md`, or any `-coverage-report.md`.
  Proof: manual edits were limited to the four leased source docs and this B004 report checklist. Generated/projected-stat/coverage/tracker changes listed above were validator-owned side effects from `--apply --wait-generated`; no generated, project-level, coverage-report, validator state/cache, or IDA DB file was manually edited.
- [x] Release every implementation lease immediately after the edit/validator batch and record proof that no accepted lease remains active.
  Proof: from `source-3/project-documentation`, ran `python .\tools\leaser\leaser.py Agent-B004 unlease by-memory\0x004cec30-0x004ced0f.HierListFindNodeByData.md by-class\HierList.md by-file\HierList.md by-type\by-struct\HierListNode.md`; exit code `0`; each path returned `Success`. Post-release `tools/leaser/Agents/Agent-B004/current_leases.md` readback contains no `Agent-B004` row; only stale Supervisor rows from 2026-06-18 remain.

## Implementation Result

Implementation is complete for [UID:0002IK]. The target now carries `91/92` scores, unchanged owner/emitter metadata, exact formal `HierList::FindNodeByPayload` C++, current MCP evidence, source-shape rationale, and rejected alternatives. Accepted support details were incorporated into `by-class/HierList.md`, `by-file/HierList.md`, and `by-type/by-struct/HierListNode.md`; `by-class/List.md` was confirmed sufficient and left untouched.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B004","command_id":"000000004165","destination_path":"executed-b-agent-research/B004/0002IK-HierListFindNodeByData-source-quality.md","details":"legacy registry reconstruction","event":"executed","source_path":"tools/leaser/Agents/Agent-B004/research/0002IK-HierListFindNodeByData-source-quality.md","timestamp":"2026-06-25T17:37:34","uid":"0002IK"} -->
<!-- {"agent":"B004","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 0002IK-HierListFindNodeByData-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B004/0002IK-HierListFindNodeByData-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"0002IK"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
