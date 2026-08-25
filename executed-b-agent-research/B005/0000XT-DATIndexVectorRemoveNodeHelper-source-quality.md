** TARGET-REPORT-UID:0000XT **
** AUTHOR-AGENT-ID:B005 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# 0000XT DATIndexVector RemoveNode Helper Source-Quality Research


## Finalized Report / Current Recommendation

- Current recommendation: keep [UID:0000XT][0x00457310-0x004573b3.DATIndexVectorRemoveNodeHelper](../../../../../by-memory/0x00457310-0x004573b3.DATIndexVectorRemoveNodeHelper.md) assigned to [UID:00003K][DATIndexVector](../../../../../by-class/DATIndexVector.md), preserve the stable documentation title `DATIndexVectorRemoveNodeHelper`, and add a source-facing private helper named `RemoveNodeForInsertUnwind`.
- Final disposition: reconstructable DATIndexVector private cleanup helper, not public erase API, not generic LinkedList support, and not MiniMap/Monster/DAT-manager consumer code.
- Required action: update the target by-memory page with current MCP session `b006-0000xu` evidence, replace the stale blank-C++ rationale, insert a first-draft formal C++ helper body, and update [UID:00003K][DATIndexVector](../../../../../by-class/DATIndexVector.md) support declarations so the helper has a private class declaration and concrete node/bucket struct definitions available to generated source.
- Confidence: strong for range, behavior, owner/emitter, and cleanup-edge caller; medium-high for exact original helper spelling and whether the original source expressed this as a named private method versus a local cleanup primitive.

## Supporting Research

This is a new report-only B005 artifact at `tools/leaser/Agents/Agent-B005/research/0000XT-DATIndexVectorRemoveNodeHelper-source-quality.md`. I did not edit target/support by-* docs, generated reports, project-level generated files, manual coverage reports, validator registry/state files, lifecycle/archive files, or executed-report folders. I did not run `execute_report`, dry-run lifecycle probes, archive moves, registry lifecycle commands, or scoped validators.

Current MCP evidence was collected from session `b006-0000xu` after `initialize`, schema-current `tools/list`, `idb_list`, and `server_health`. `server_health` returned `status:"ok"`, IDB `E:\Desktop\Clone\NexusTK\NexusTK.exe.i64`, input `C:\Users\admin\Desktop\Clone\NexusTK\NexusTK.exe`, module `NexusTK.exe`, imagebase `0x400000`, `auto_analysis_ready:true`, `hexrays_ready:true`, and `strings_cache_ready:true`.

The most important new finding relative to the current target page is not a changed owner or range. It is C++ readiness: the generated `auto-generated/NexusTK/archive/DATIndexVector.cpp` still has an empty emitter marker for [UID:0000XT], while current project rules require a first-draft C++ recommendation or no-code proof for reconstructable emitting targets above the code-entry gate. This helper is above that gate and current MCP confirms enough behavior for a conservative formal helper body.

## Target

- Target UID: `0000XT`.
- Target path: `by-memory/0x00457310-0x004573b3.DATIndexVectorRemoveNodeHelper.md`.
- Source queue/report row: `auto-generated/-ag-research-tracker.md` line 1569 at assignment time, `85/90`, combined `87.5`, reconstructable `true`, report count `0`.
- Current supervisor classification: report-only source-quality research for a by-memory reconstructable target.
- Current scores and parent state: target `85/90`; direct class parent [UID:00003K][DATIndexVector](../../../../../by-class/DATIndexVector.md) currently `88/90`; file parent [UID:0000IP][DATIndexVector](../../../../../by-file/DATIndexVector.md) currently `88/88`.

## Current Target State

- Existing metadata: `COMPLETION:85`, `CONFIDENCE:90`, `CANONICAL_OWNER:00003K`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:00003K`, blank `EMITTER_POSITION_OPTIONAL`, and blank formal `RECONSTRUCTION_CPP CODE`.
- Existing owner/emitter/reconstructable state: already assigned through DATIndexVector class/file; this remains correct.
- Existing C++/emitter state: `auto-generated/NexusTK/archive/DATIndexVector.cpp` currently shows an empty emitter marker for [UID:0000XT]. The target body still says C++ remains blank because the page is below a `95/95` final-source bar; that rationale is stale under the current code-entry gate because the target is reconstructable, has nonblank emitters, and averages `87.5`.
- Existing open questions, blockers, placeholder names, stale assumptions, or contradictory claims: exact source-facing helper name and method/free-helper expression remain inferred. The public erase/API alternative remains unsupported. The stale C++ gate text is now the main score/source-quality blocker.
- Related target/support docs checked: [UID:00003K][DATIndexVector](../../../../../by-class/DATIndexVector.md), [UID:0000IP][DATIndexVector](../../../../../by-file/DATIndexVector.md), [UID:0000XS][DATIndexVectorInsertNode](../../../../../by-memory/0x00457100-0x0045730f.DATIndexVectorInsertNode.md), [UID:0000XX][DATIndexVectorFindNodeByKey](../../../../../by-memory/0x00457580-0x00457613.DATIndexVectorFindNodeByKey.md), [UID:0001U1][DATIndexVectorNode](../../../../../by-type/by-struct/DATIndexVectorNode.md), [UID:0001U0][DATIndexVectorBucket](../../../../../by-type/by-struct/DATIndexVectorBucket.md), and generated `auto-generated/NexusTK/archive/DATIndexVector.cpp`.
- Current artifact/lifecycle status: this report is a report-only research artifact awaiting supervisor Gate 1 review; no implementation callback has been performed.

## Heuristic / Inference Reanalysis And Validation

The ownership and source placement inference is stable: the helper hashes `node->key`, selects a DATIndexVector bucket from `m_bucketsBegin` and `m_bucketMask`, repairs `DATIndexVectorBucket::first/last`, unlinks a `DATIndexVectorNode`, decrements `m_nodeCount`, and frees a 16-byte node. Those are DATIndexVector bucket/list semantics, not generic list-only semantics.

The name inference is narrower than the current documentation title. B009 already ranked `RemoveNodeForInsertUnwind` as the best high-specificity private name because the only observed caller is the `InsertNode` cleanup edge. Current MCP strengthens that: bounded disassembly of `InsertNode` shows `call sub_457310` at `0x00457301` immediately followed by `push 0`, `push 0`, and `call __CxxThrowException@8` at `0x0045730a`. That caller context supports an unwind/cleanup helper name, while still preserving `DATIndexVectorRemoveNodeHelper` as the stable doc label.

The type/field inference is implementation-ready. Current target decompilation reads `Block+0x08..0x0b` as key bytes, `Block[0]` as `next`, `Block[1]` as `prev`, `this[1]` as the list head/sentinel, `this[2]` as node count, `this[3]` as bucket table begin, and `this[6]` as bucket mask. Existing support docs already name these as `DATIndexVectorNode::next`, `prev`, `key`, `DATIndexVector::m_listHead`, `m_nodeCount`, `m_bucketsBegin`, and `m_bucketMask`.

The split/range question is resolved. `lookup_funcs` maps `0x00457310` and `0x004573b2` to `sub_457310`, size `0xa3` / 163 bytes (Verified with `tools/int_convert.py`), while `0x004573b3` is not a function and `0x004573c0` is the separate `sub_4573C0`, size `0xb` / 11 bytes (Verified with `tools/int_convert.py`). `get_bytes` shows one `0xcc` byte before the function and thirteen `0xcc` bytes after `0x004573b3`.

The C++ readiness blocker should be resolved by inserting a conservative private method body. The body can use ordinary source-level `delete node` for the node free, matching how accepted [UID:0004HG][DATIndexVectorEnsureBucketStorageCapacity](../../../../../by-memory/0x00423c50-0x00423cf6.DATIndexVectorEnsureBucketStorageCapacity.md) expresses allocator/free lowering as `new[]` and `delete[]`. The helper should return the original next node because the binary stores it through an out parameter even though the current cleanup caller discards it.

Rejected alternatives:

- Public `EraseNode`/`RemoveNode` API: rejected because current `xrefs_to 0x00457310` reports only one code xref, from `InsertNode` cleanup.
- Generic [UID:0000KR][LinkedList](../../../../../by-file/LinkedList.md) ownership: rejected because this helper hashes DATIndexVector keys and repairs bucket first/last boundaries before the generic intrusive unlink.
- MiniMap, MonsterImageLib, fitting-room, or DAT-manager ownership: rejected because no consumer calls this helper directly; the only caller is DATIndexVector `InsertNode`.
- No-code proof: rejected because the target is reconstructable, emits through [UID:00003K], clears the current code-entry gate, and current MCP proves enough behavior for first-draft source.
- Leaving score unchanged because "exact original name is unproven": rejected under `score-blocker-audit-standard.md`; the best supported source-facing name can be explicitly marked inferred.

## Evidence Standards Used

- Direct current MCP evidence: `server_health`, `lookup_funcs`, `func_profile`, `xrefs_to`, `callees`, `get_bytes`, bounded `disasm`, and `decompile` on exact addresses for `0x00457310` and the caller window in `0x00457100`.
- Documentation evidence: current target and direct support docs, especially B009/B002/B001 Rule 26 incorporations already present in DATIndexVector class/file/method/type pages.
- Generated evidence: current `auto-generated/NexusTK/archive/DATIndexVector.cpp` generated header and empty [UID:0000XT] emitter marker; generated memory coverage route showing [UID:0000XT] emits through [UID:00003K].
- Negative evidence: bounded `xrefs_to 0x00457310` shows exactly one code xref; `func_profile` shows zero string refs, one caller, and no consumer fanout; `callees` shows only the node-free callee outside intra-function flow.
- Numeric conversion discipline: documented size conversions use `tools/int_convert.py`.

The evidence is strong enough for first-draft C++ because all state mutations are local, field offsets agree with accepted DATIndexVector support docs, and the only source uncertainty affects helper spelling/API visibility rather than behavior.

## Evidence Checked

- MCP schema/session checks: `initialize`, schema-current `tools/list`, `idb_list`, and `server_health` for database session `b006-0000xu`.
- MCP exact-address function checks: `lookup_funcs` for `0x00457310`, `0x00457301`, `0x004573b2`, `0x004573b3`, and `0x004573c0`.
- MCP target profiling: `func_profile` on `0x00457310` with `include_lists:true`, `max_items:20`, and prototype included.
- MCP xrefs/callees: `xrefs_to 0x00457310` with `limit:20`; `callees 0x00457310` with `limit:20`.
- MCP bytes: `get_bytes` at `0x0045730f`, `0x00457310`, `0x004573a0`, `0x004573b3`, and caller-window bytes at `0x004572e0`.
- MCP disassembly: `disasm 0x00457310` with `max_instructions:160`, `include_total:true`; `disasm 0x00457100` with `offset:120`, `max_instructions:70`, `include_total:true`.
- MCP decompilation: `decompile 0x00457310` with `include_addresses:false`.
- Integer conversion: `python .\tools\int_convert.py 0xa3`, `0x20f`, `0xb`, `0x10`, `0x93`, `0x13d`, and `0xa6`.
- Documentation checked: target by-memory page; DATIndexVector class/file pages; InsertNode and FindNode sibling pages; DATIndexVectorNode and DATIndexVectorBucket type pages; current generated `auto-generated/NexusTK/archive/DATIndexVector.cpp`; generated by-memory coverage and generated memory route rows.
- Old reports searched with `rg`: `0000XT`, `0x00457310`, `0x004573b3`, `DATIndexVectorRemoveNodeHelper`, `RemoveNodeForInsertUnwind`, and `DATIndexVector`.
- Old report matches opened or inspected: B009 `00003K-DATIndexVector-class-source-quality.md` as the true class/source-family report; B004 `0000XP-MiniMapVersionManager-source-quality.md` where the target is kept outside MiniMap ownership; B001 linked-list helper report where DATIndexVector children are documentation evidence for separating custom DATIndexVector code from generic list support; B005 MiniMapSymbol report was a UID-only false positive for a different MiniMap data page and was rejected as target evidence.
- Failed or intentionally skipped checks: no broad list/search/disassembly/callgraph/type/batch-analysis calls were used for target evidence. No IDA DB rename/type writes were attempted.

## Claim And Incorporation Ledger

| Claim ID | Claim | Confidence | Evidence | Destination doc/section | Action | Verification state |
| --- | --- | --- | --- | --- | --- | --- |
| C1 | [UID:0000XT] is exactly `sub_457310`, range `0x00457310-0x004573b3`, size `0xa3` / 163 bytes (Verified with `tools/int_convert.py`). | Strong | MCP `lookup_funcs`; `get_bytes` boundary padding; `disasm` total 58 instructions. | Target `Boundary`, `Live Evidence`, `Score Rationale`. | incorporate | applied |
| C2 | The only current code xref to the helper is `0x00457301` in `sub_457100` / `DATIndexVectorInsertNode`. | Strong | MCP `xrefs_to 0x00457310`; `func_profile` caller list. | Target `Live Evidence`, `Ownership Decision`, `Open Questions`. | incorporate | applied |
| C3 | The caller edge is cleanup/unwind-specific: caller-window disassembly shows `call sub_457310` immediately before `__CxxThrowException@8`. | Strong | MCP bounded `disasm 0x00457100` offset 120. | Target `Behavior`, `Ownership Decision`, `IDA Rename / Type / Comment Recommendations`. | incorporate | applied |
| C4 | The helper hashes four bytes at `node + 0x08` with FNV-1a, masks by `m_bucketMask`, and indexes the bucket table at `m_bucketsBegin`. | Strong | MCP decompile/disasm constants `0x811c9dc5` and `0x01000193`; existing DATIndexVectorNode/Bucket docs. | Target `Behavior`, `Layout Evidence`; support type docs if callback updates them. | incorporate | applied |
| C5 | The helper repairs bucket `first/last`, unlinks intrusive `next/prev`, decrements `m_nodeCount`, frees a `0x10` / 16-byte node (Verified with `tools/int_convert.py`), and returns the original next node. | Strong | MCP decompile/disasm; `callees` reports `sub_5C7526`; `func_profile` constant `0x10`. | Target `Behavior`, `First-Draft C++ Recommendation`. | incorporate | applied |
| C6 | DATIndexVector remains the correct owner/emitter; LinkedList and consumer-specific owners are rejected. | Strong | Current target/class/file docs; B009/B001/B004 report snippets; current MCP body/caller facts. | Target `Ownership Decision`; class/file support docs. | incorporate | applied |
| C7 | `RemoveNodeForInsertUnwind` is the best source-facing private helper name; `DATIndexVectorRemoveNodeHelper` should remain the stable documentation name. | Medium-high | Only cleanup caller; B009 name ranking; no public erase xrefs. | Target `Status`, `Open Questions`, `IDA Rename / Type / Comment Recommendations`; class method row. | incorporate | applied |
| C8 | The target should no longer keep blank C++ under the old `95/95` rationale; first-draft formal C++ is ready if class/support declarations are updated in the same callback. | Medium-high | Current code-entry gate, generated empty marker, current MCP behavior proof. | Target `RECONSTRUCTION_CPP CODE`, `Autogen And C++ Handling`; class C++ support block. | incorporate | applied |
| C9 | Recommended target score is `88/91`, with owner/emitter/reconstructable unchanged. | Medium-high | C++ blocker resolved, current MCP refreshed, exact name still inferred. | Target metadata and score rationale. | incorporate | applied |
| C10 | Generated output should replace the [UID:0000XT] empty marker in `auto-generated/NexusTK/archive/DATIndexVector.cpp` after accepted callback validation/autogen refresh. | Strong | Current generated file contains empty marker; generated memory route says [UID:0000XT] emits through [UID:00003K]. | Target `Autogen And C++ Handling`, implementation checklist. | incorporate | applied |

## Positive Evidence Summary

- Direct facts supporting the chosen recommendation: MCP session `b006-0000xu` confirms the exact helper range, one caller, one external callee, current decompilation, current disassembly, and exact boundary padding. The body is short, self-contained, and maps cleanly to existing DATIndexVector field/type names.
- Corroborating documentation/generated-report evidence: DATIndexVector class/file docs already route this helper through [UID:00003K]/[UID:0000IP]; B009 preserves `RemoveNodeForInsertUnwind` as the best high-specificity private name; generated `DATIndexVector.cpp` already emits sibling method bodies in the same source root.
- Strongest inference chain: one cleanup-edge caller plus bucket-aware body means private DATIndexVector cleanup, not public erase. Existing node/bucket support docs provide enough source-facing structure for formal code.

## IDA MCP Facts

- Function/range facts: `lookup_funcs` resolves `0x00457310` as `sub_457310`, size `0xa3` / 163 bytes (Verified with `tools/int_convert.py`); `0x004573b2` remains inside the function; `0x004573b3` is not a function; `0x004573c0` starts `sub_4573C0`, size `0xb` / 11 bytes (Verified with `tools/int_convert.py`).
- Data/table/padding facts: `get_bytes` reports `0xcc` at `0x0045730f`, prologue bytes at `0x00457310`, the tail call/free/return window at `0x004573a0`, and thirteen `0xcc` bytes at `0x004573b3-0x004573c0`.
- Xref facts: `xrefs_to 0x00457310` reports exactly one code xref, `0x00457301`, in `sub_457100`, size `0x20f` / 527 bytes (Verified with `tools/int_convert.py`).
- Callee facts: `callees 0x00457310` reports only `sub_5C7526` as an external/internal callee. `func_profile` also lists self/intra-function flow plus `sub_5C7526`, zero string refs, 58 instructions, seven basic blocks, one caller, and prototype `_DWORD *__thiscall(_DWORD *this, _DWORD *, _DWORD *Block)`.
- Decompile facts: decompilation computes FNV-1a over four key bytes at `Block+8..Block+0xb`, selects `8 * (hash & this[6]) + this[3]`, repairs bucket boundary pointers, captures `*Block` as the returned next pointer, relinks `Block[1]->next` and `Block[0]->prev`, decrements `this[2]`, calls `sub_5C7526(Block)`, stores next through the out parameter, and returns that out parameter.
- Negative IDA facts: no non-cleanup caller, no string refs, no feature-specific data route, and no public erase-like xref were found in current bounded checks.

## Function / Child Inventory

| Range / Item | UID / Path | Role | Reconstructable | Direct Parent | Score | Status |
| --- | --- | --- | --- | --- | --- | --- |
| `0x00457100-0x0045730f` | [UID:0000XS](../../../../../by-memory/0x00457100-0x0045730f.DATIndexVectorInsertNode.md) | Insert/duplicate/rehash method and sole caller family for target | true | [UID:00003K] | `86/90` | Support doc checked; no required score change in this report. |
| `0x00457310-0x004573b3` | [UID:0000XT](../../../../../by-memory/0x00457310-0x004573b3.DATIndexVectorRemoveNodeHelper.md) | Private cleanup/remove helper | true | [UID:00003K] | current `85/90`, recommended `88/91` | Target of this report. |
| `0x004573c0-0x004573cb` | [UID:0004DE](../../../../../by-memory/0x004573c0-0x004573cb.MiniMapVersionManagerClearSingletonHelper.md) | Separate MiniMap singleton-clear helper | true | [UID:00008H] | `88/93` in current docs | Adjacent next function only; not part of target. |
| `DATIndexVectorNode` | [UID:0001U1](../../../../../by-type/by-struct/DATIndexVectorNode.md) | Semantic 16-byte node overlay | true | [UID:00003K] | `85/89` | Support declaration needed for target C++. |
| `DATIndexVectorBucket` | [UID:0001U0](../../../../../by-type/by-struct/DATIndexVectorBucket.md) | Bucket first/last pair | true | [UID:00003K] | `85/90` | Support declaration needed for target C++. |

## Direct Xref / Caller Inventory

| Address / Item | Xref / Caller / Callee | Meaning |
| --- | --- | --- |
| `0x00457301` | code xref from `sub_457100` to `sub_457310` | Only target caller; cleanup edge inside `DATIndexVectorInsertNode`. |
| `0x004572f3` | caller-window call to `sub_423C40` before target call | Cleanup/throw helper path setup; not target ownership. |
| `0x0045730a` | caller-window call to `__CxxThrowException@8` after target call | Confirms target call is immediately before exception throw. |
| `0x004573a0` | target call to `sub_5C7526` | Node free/runtime delete lowering. |

## Documentation Evidence And IDA Status

- Existing docs that support the conclusion: target page already documents DATIndexVector ownership, bucket/list behavior, and `RemoveNodeForInsertUnwind` as the best high-specificity private name. DATIndexVector class/file pages now carry final field names and an emitted class declaration. DATIndexVectorNode/Bucket docs already document the required fields.
- Existing docs that are stale, incomplete, or contradicted: target `Autogen And C++ Handling` still says formal C++ remains blank because the page is below a `95/95` final-source bar. Current workflow requires C++ or no-code proof for this emitting target now; current evidence supports C++.
- Generated/coverage report state: `auto-generated/NexusTK/archive/DATIndexVector.cpp` currently contains formal C++ for `ResizeAndFill` and `EnsureBucketSlotCapacity`, then an empty emitter marker for [UID:0000XT]. `auto-generated/-ag-memory-coverage.md` routes [UID:0000XT] as emitting through [UID:00003K].

## Ranked Ownership Analysis

### 1. [UID:00003K] DATIndexVector private helper - accepted

- Evidence for: body hashes DATIndexVector node key bytes, indexes DATIndexVector bucket table/mask fields, repairs DATIndexVectorBucket first/last, relinks DATIndexVectorNode next/prev, decrements DATIndexVector node count, and is called only by DATIndexVectorInsertNode cleanup.
- Evidence against: exact original source spelling and whether the source had a named helper versus compiler-split cleanup primitive are not proven.
- Decision: keep owner/emitter [UID:00003K], add private helper declaration/body, and label source name inferred.

### 2. [UID:0000KR] LinkedList generic support - rejected

- Evidence for: the helper performs intrusive list unlink writes and frees a 16-byte node.
- Evidence against: generic list support does not hash keys or repair bucket first/last boundaries. B001 linked-list report separates generic list helpers from DATIndexVector-owned bucket algorithms.
- Decision: reject as canonical owner or emitter; preserve LinkedList only as a support boundary.

### 3. Consumer-specific MiniMap, MonsterImageLib, fitting-room, or DAT-manager ownership - rejected

- Evidence for: DATIndexVector is used by those systems elsewhere.
- Evidence against: current target has no direct consumer callers. B004 MiniMap aggregate report explicitly keeps [UID:0000XT] outside MiniMap ownership. The only target caller is DATIndexVectorInsertNode.
- Decision: reject consumer-specific ownership.

### 4. Public `RemoveNode` / erase API - rejected for current source shape

- Evidence for: the body is a complete bucket/list remove primitive and returns the next node.
- Evidence against: current MCP finds only the `InsertNode` cleanup edge immediately before a throw; no normal erase/clear/public caller exists.
- Decision: document as a private cleanup/unwind helper, not a public API.

### 5. No-owner/non-emitting fallback - rejected

- Evidence for: the exact original helper spelling is not proven.
- Evidence against: owner/emitter route is valid, target is reconstructable, generated route already emits an empty marker, and behavior is clear enough for first-draft C++.
- Decision: not appropriate.

## Source Placement

- Recommended source file/class/global/module placement: [UID:00003K][DATIndexVector](../../../../../by-class/DATIndexVector.md) under [UID:0000IP][DATIndexVector](../../../../../by-file/DATIndexVector.md), generated at `NexusTK/archive/DATIndexVector.cpp`.
- Why this placement fits source-tree and subsystem context: sibling DATIndexVector methods already emit in the same generated source file, and this helper uses the class bucket/list layout.
- Rejected placements and why: `LinkedList` lacks bucket/key semantics; feature consumers lack direct callers; a public API route lacks normal erase callers.
- Remaining placement uncertainty: original folder `archive/` versus common/util remains a class/file-level folder question, not a blocker for this exact helper.

## Range / Split / Padding / Reclassification Analysis

No split, merge, padding reclassification, or child creation is recommended. Current MCP confirms the existing target range is exact. The previous function [UID:0000XS] contains the sole caller at `0x00457301`, `0x0045730f` is a one-byte `0xcc` gap before the target, `0x004573b3-0x004573c0` is thirteen bytes of `0xcc` padding, and `0x004573c0` starts a separate MiniMap singleton-clear helper. Keep the filename range `0x00457310-0x004573b3`.

## Negative Evidence Summary

- No public erase API evidence: `xrefs_to 0x00457310` reports only one cleanup caller, and the caller window immediately throws afterward.
- No generic-list ownership evidence: the body includes bucket selection and bucket first/last repair, which generic list cleanup does not own.
- No consumer-specific owner evidence: no MiniMap, MonsterImageLib, fitting-room, or DAT manager function calls this helper directly.
- No range problem evidence: `0x004573b3` is not a function and post-target bytes are padding until `0x004573c0`.
- No no-code proof: the function is not raw padding, compiler-only import glue, pure CRT/STL helper, or non-emitting lowering. It contains custom bucket/list state maintenance that should be represented in rebuilt source.

## IDA Rename / Type / Comment Recommendations

- Keep the IDA/function documentation label `DATIndexVectorRemoveNodeHelper` for continuity unless a supervised IDA rename pass wants the narrower source-facing name.
- Source-facing private method name recommendation: `DATIndexVector::RemoveNodeForInsertUnwind`.
- Optional IDA comment if a future safe IDA comment pass is authorized: "DATIndexVector private cleanup edge from InsertNode; hashes node key, repairs bucket first/last, unlinks/frees node, returns next; not public erase API."
- Type recommendations: no IDA DB type writes in this report-only pass. Source/support docs should define `DATIndexVectorNode { next, prev, key, value }` and `DATIndexVectorBucket { first, last }` before the new helper body is emitted.

## First-Draft C++ Recommendation

- Eligible for draft C++: yes. The target is `RECONSTRUCTABLE:TRUE`, has nonblank `EMITTER_UIDS:00003K`, averages `87.5`, and current MCP proves a compact deterministic helper body.
- Recommended target code: replace the target's blank formal C++ block with this exact content after the support declaration update below is accepted:

```cpp
DATIndexVectorNode* DATIndexVector::RemoveNodeForInsertUnwind(
    DATIndexVectorNode* node)
{
    const unsigned char* const keyBytes =
        reinterpret_cast<const unsigned char*>(&node->key);

    std::uint32_t hash = 0x811c9dc5U;
    for (int index = 0; index != 4; ++index) {
        hash = (hash ^ keyBytes[index]) * 0x01000193U;
    }

    DATIndexVectorBucket& bucket = m_bucketsBegin[hash & m_bucketMask];
    DATIndexVectorNode* const next = node->next;

    if (bucket.last == node) {
        if (bucket.first == node) {
            bucket.first = m_listHead;
            bucket.last = m_listHead;
        } else {
            bucket.last = node->prev;
        }
    } else if (bucket.first == node) {
        bucket.first = node->next;
    }

    node->prev->next = node->next;
    node->next->prev = node->prev;
    --m_nodeCount;

    delete node;
    return next;
}
```

- Required support declaration update: in [UID:00003K][DATIndexVector](../../../../../by-class/DATIndexVector.md), replace the current forward-only support declarations with concrete declarations before the class, and add the private method declaration:

```cpp
struct DATIndexVectorNode {
    DATIndexVectorNode* next;
    DATIndexVectorNode* prev;
    int key;
    void* value;
};

struct DATIndexVectorBucket {
    DATIndexVectorNode* first;
    DATIndexVectorNode* last;
};
```

and in the `private:` class section:

```cpp
    DATIndexVectorNode* RemoveNodeForInsertUnwind(DATIndexVectorNode* node);
```

- Reason it preserves exact original behavior: it computes the same FNV-1a key hash, masks with `m_bucketMask`, repairs the selected bucket first/last entries in the same cases, captures and returns the original next pointer, performs the same intrusive unlink writes, decrements node count, and frees the node.
- Reason it matches plausible original precompiled mid-2000s source shape: a small private class helper used by an insert unwind path is more plausible than a public API with no public callers or a decompiler-shaped global function. It uses ordinary field/member names already accepted by DATIndexVector docs.
- Inferred source-facing names/types/fields used: `RemoveNodeForInsertUnwind`, `DATIndexVectorNode`, `DATIndexVectorBucket`, `m_listHead`, `m_nodeCount`, `m_bucketsBegin`, and `m_bucketMask`.
- Naming/coding style convention used: current generated DATIndexVector code uses `DATIndexVector::MethodName`, `std::uint32_t`, and `m_` fields; the draft follows that local convention.
- Reason code should remain blank, if applicable: not applicable. A no-code proof is not supported for this target.
- Exact no-code proof, if not eligible: not applicable.

## Final Recommendation

- Exact changes recommended: update target evidence/current-state text, replace stale C++ handling, insert the formal private helper body above, and update class support declarations/private method list.
- Exact parent assignments recommended: keep `CANONICAL_OWNER:00003K`, `EMITTER_UIDS:00003K`, and `RECONSTRUCTABLE:TRUE`.
- Exact items left no-owner/non-emitting and why: none for this target.
- Exact future work outside this assignment scope: broader DATIndexVector method-body passes for [UID:0000XS], [UID:0000XU], [UID:0000XX] can later add their own formal bodies; they are not required to accept this target report.

## Recommended Target Doc Changes

Target path: `by-memory/0x00457310-0x004573b3.DATIndexVectorRemoveNodeHelper.md`.

- Metadata/score: change `COMPLETION:85` to `COMPLETION:88`, change `CONFIDENCE:90` to `CONFIDENCE:91`, and keep `CANONICAL_OWNER:00003K`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:00003K`.
- Formal C++: insert the `DATIndexVector::RemoveNodeForInsertUnwind` method body from `First-Draft C++ Recommendation`.
- Item Summary: replace or extend the current summary with current B005 MCP evidence and C++ readiness. Suggested summary text:

```text
Agent-B005 current MCP session `b006-0000xu` reconfirms this exact private DATIndexVector cleanup helper at `0x00457310-0x004573b3`, size `0xa3` / 163 bytes (Verified with `tools/int_convert.py`), with only caller `0x00457301` from `InsertNode` cleanup immediately before `__CxxThrowException`, one external node-free callee `sub_5C7526`, FNV key hashing, bucket first/last repair, intrusive unlink, count decrement, original-next return, and first-draft private `RemoveNodeForInsertUnwind` C++ now ready; keep public erase/API ownership rejected.
```

- `Status`: update confidence/C++ handling to say behavior and ownership are strong; source-facing helper name remains inferred.
- `Live Evidence`: add MCP session `b006-0000xu` health, lookup/profile/xref/callee/bytes/disasm/decompile results from this report.
- `Behavior`: record the returned `next` pointer and the exact caller-window cleanup/throw context.
- `Open Questions`: close "whether C++ can be entered" as resolved; keep exact original helper spelling and method/free-helper expression as a caveat.
- `Autogen And C++ Handling`: replace the old `95/95` blank-C++ rationale with the current code-entry gate analysis and generated empty-marker state.
- `Score Rationale`: update completion/confidence rationale for current MCP refresh and formal C++ readiness.
- `Changes`: add a B005 report/callback change entry after implementation.

## Recommended Support Doc Changes

### [UID:00003K] `by-class/DATIndexVector.md`

- Update the formal class C++ block so `DATIndexVectorNode` and `DATIndexVectorBucket` are concrete structs before `class DATIndexVector`, not only forward declarations.
- Add private declaration `DATIndexVectorNode* RemoveNodeForInsertUnwind(DATIndexVectorNode* node);`.
- Update the [UID:0000XT] method/helper row to state that the helper now has first-draft formal C++ as a private cleanup/unwind helper, while the stable doc label remains `DATIndexVectorRemoveNodeHelper`.
- No class score change is required; current `88/90` remains defensible because the broader class still has folder/header/signature caveats.

### [UID:0000IP] `by-file/DATIndexVector.md`

- Update the method range row for [UID:0000XT] to mention the accepted private `RemoveNodeForInsertUnwind` formal body if the target C++ is inserted.
- No file path or score change is required.

### [UID:0001U1] `by-type/by-struct/DATIndexVectorNode.md`

- Add a note that the [UID:0000XT] C++ body requires concrete `next`, `prev`, `key`, and `value` declarations and that the definitions are emitted through the DATIndexVector class support block if the supervisor accepts this implementation route.
- No score change is required unless the supervisor chooses to formalize standalone type C++ separately.

### [UID:0001U0] `by-type/by-struct/DATIndexVectorBucket.md`

- Add a note that the [UID:0000XT] C++ body uses `first` and `last` bucket members exactly as already documented.
- No score change is required unless the supervisor chooses to formalize standalone type C++ separately.

### [UID:0000XS] `by-memory/0x00457100-0x0045730f.DATIndexVectorInsertNode.md`

- Add one sentence that [UID:0000XT] now has a first-draft private cleanup helper body named `RemoveNodeForInsertUnwind` and remains the cleanup edge at `0x00457301`, not a public erase API.
- No score change is required for `InsertNode`.

No manual coverage-report or generated-report edits are recommended. Validator/autogen should refresh generated output from source by-* docs after the accepted callback.

## Score And Metadata Recommendation

- Current score/metadata: `COMPLETION:85`, `CONFIDENCE:90`, `CANONICAL_OWNER:00003K`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:00003K`.
- Recommended score/metadata: `COMPLETION:88`, `CONFIDENCE:91`, same owner/reconstructable/emitter fields.
- Score rationale and reason not higher/lower: completion should rise because the remaining C++ blocker is resolved with current MCP-backed first-draft source, the cleanup caller is now rechecked in the current session, and generated output empty-marker handling is implementation-ready. Confidence should rise modestly because behavior/range/caller are fresh and direct, but stay below final audit because `RemoveNodeForInsertUnwind` is inferred and the original source may have expressed the cleanup through a private method, local helper, or template cleanup primitive.
- Score-improvement attempt: investigated the named blockers of source helper name, owner/emitter, split/range, C++ readiness, and support type sufficiency. Owner, range, and C++ readiness are resolved; exact original spelling remains an evidence-backed caveat, not a blocker.
- Metadata fields to change or leave unchanged: only completion/confidence should change. Do not change owner, emitter, reconstructable, range, or filename.

## Open Questions With Attempted Resolution

- Open question: exact original helper name. Evidence checked: current MCP caller edge, B009 name ranking, class/file docs, generated output. Resolution: use inferred `RemoveNodeForInsertUnwind` for source C++, keep `DATIndexVectorRemoveNodeHelper` as stable doc label. Score/C++ impact: no longer blocks first-draft C++; caps confidence.
- Open question: public erase API versus private cleanup helper. Evidence checked: `xrefs_to 0x00457310`, caller-window disassembly, old reports. Resolution: private cleanup helper; public API rejected. Score/C++ impact: source method stays private.
- Open question: exact original source folder/header visibility. Evidence checked: DATIndexVector class/file docs and generated route. Resolution: keep `NexusTK/archive/DATIndexVector.cpp`; broader folder remains class/file-level caveat. Score/C++ impact: no target blocker.
- Open question: support struct public/private declaration location. Evidence checked: current generated output order and support docs. Resolution: for implementation, add concrete support struct definitions in the DATIndexVector class C++ block before the helper body is emitted. Score/C++ impact: required support callback item, not a reason to leave target C++ blank.

## Follow-Up Actions

- Supervisor actions: Gate 1 review this report. If accepted, send a callback that includes the target formal C++ block and the DATIndexVector class support declaration update.
- A-agent actions: none requested.
- B005 future research actions: only if supervisor requests repair or implementation callback for this exact report.

## Confidence

- Recommendation confidence: high for owner/emitter/range/C++ body behavior; medium-high for exact private helper name.
- Score confidence: medium-high for `88/91`.
- Remaining uncertainty: original helper spelling and source-level declaration visibility.

## Validator Results

- Working directory for all validators: `source-3/project-documentation`.
- All requested validators exited `0` with `ok: 1`; no validator warning lines were emitted. Validator-owned UID link normalization and projected stats/autogen registry updates were applied where reported.

| File | Command ID | Timestamp | Exit | ok | Notable apply output | Generated refresh |
| --- | --- | --- | ---: | ---: | --- | --- |
| `by-memory/0x00457310-0x004573b3.DATIndexVectorRemoveNodeHelper.md` | `000000006692` | `2026-07-05T03:04:00-04:00` | 0 | 1 | `completion_update 88`, `confidence_update 91`, autogen registry `blank -> block`, two UID link updates. | `deferred`; command/timestamp matched validator output. |
| `by-class/DATIndexVector.md` | `000000006693` | `2026-07-05T03:04:09-04:00` | 0 | 1 | Autogen registry hash update for class C++ block. | `deferred`; command/timestamp matched validator output. |
| `by-file/DATIndexVector.md` | `000000006694` | `2026-07-05T03:04:17-04:00` | 0 | 1 | Inserted missing UID link for [UID:0000XT]. | `deferred`; command/timestamp matched validator output. |
| `by-type/by-struct/DATIndexVectorNode.md` | `000000006695` | `2026-07-05T03:04:26-04:00` | 0 | 1 | Two UID link updates; stats row update. | `deferred`; command/timestamp matched validator output. |
| `by-type/by-struct/DATIndexVectorBucket.md` | `000000006696` | `2026-07-05T03:04:33-04:00` | 0 | 1 | Two UID link updates; stats row update. | `deferred`; command/timestamp matched validator output. |
| `by-memory/0x00457100-0x0045730f.DATIndexVectorInsertNode.md` | `000000006697` | `2026-07-05T03:04:42-04:00` | 0 | 1 | Two UID link updates. | `deferred`; command/timestamp matched validator output. |

- Generated freshness inspected read-only: `auto-generated/NexusTK/archive/DATIndexVector.cpp` now has header `validator-command-id: 000000006697`, `validator-refreshed-at: 2026-07-05T03:04:42-04:00`, `validator-refresh-source: deferred-generated-refresh`.
- Generated SHA256 after inspection: `6B2B58BB382414C01AA1B2031F34CBB099C11DDFB97B80DA77F36EE4AD34AEED`.
- Generated [UID:0000XT] state: `DATIndexVector::RemoveNodeForInsertUnwind` body is present at the [UID:0000XT] marker with `Completion:88 | Confidence:91`; the old [UID:0000XT] empty marker is gone. Empty markers remain for unrelated sibling UIDs outside this callback.
- Leases used/released: B005 leased the six by-* target/support files for the immediate edit/validator batch, then released all six successfully. Post-release `tools/leaser/Agents/current_leases.md` has no B005 rows; only unrelated B008 leases were active.

## Changed Files

- Modified target/support docs:
  - `by-memory/0x00457310-0x004573b3.DATIndexVectorRemoveNodeHelper.md`
  - `by-class/DATIndexVector.md`
  - `by-file/DATIndexVector.md`
  - `by-type/by-struct/DATIndexVectorNode.md`
  - `by-type/by-struct/DATIndexVectorBucket.md`
  - `by-memory/0x00457100-0x0045730f.DATIndexVectorInsertNode.md`
- Modified B005 report:
  - `tools/leaser/Agents/Agent-B005/research/0000XT-DATIndexVectorRemoveNodeHelper-source-quality.md`
- Validator/lease generated updates observed in this callback:
  - `auto-generated/NexusTK/archive/DATIndexVector.cpp`
  - `project-level/-auto-completion-stats.md`
  - `tools/leaser/Agents/current_leases.md`
- Renamed: none.
- Report execution: not run. B agents must not run `tools/validator.py execute_report`, dry-run/status/probing variants, registry lifecycle commands, manual report moves, or equivalent report execution/archive commands.

## Implementation Tracking Checklist

Initial report-only pass:

- [x] Supervisor validation required before implementation. Proof: user callback states Gate 1 passed for SHA256 `CD76A6F37C566A86D2C408B9D1FED360550DA6FE55B5595D6DBD551707A64EA5`.
- [x] Target doc `by-memory/0x00457310-0x004573b3.DATIndexVectorRemoveNodeHelper.md`: update metadata to `88/91`, keep owner/emitter/reconstructable unchanged, add current MCP session `b006-0000xu` evidence, replace stale C++ handling, insert first-draft `DATIndexVector::RemoveNodeForInsertUnwind` formal code, update Item Summary, Status, Behavior, Live Evidence, Open Questions, Autogen/C++ Handling, Score Rationale, and Changes. Proof: validator `000000006692`, exit `0`, `ok: 1`.
- [x] Support doc `by-class/DATIndexVector.md`: add concrete `DATIndexVectorNode` and `DATIndexVectorBucket` struct definitions in the class C++ block, add private `RemoveNodeForInsertUnwind` declaration, and update [UID:0000XT] method/helper row. Proof: validator `000000006693`, exit `0`, `ok: 1`.
- [x] Support doc `by-file/DATIndexVector.md`: update [UID:0000XT] method-range row after target C++ is accepted; no path/score change. Proof: validator `000000006694`, exit `0`, `ok: 1`.
- [x] Support docs `by-type/by-struct/DATIndexVectorNode.md` and `by-type/by-struct/DATIndexVectorBucket.md`: record that the target helper body relies on the accepted node/bucket fields; no score change unless supervisor chooses standalone type C++ work. Proof: validators `000000006695` and `000000006696`, exit `0`, `ok: 1`.
- [x] Support doc `by-memory/0x00457100-0x0045730f.DATIndexVectorInsertNode.md`: add cleanup-edge cross-reference to the accepted private helper body; no score change. Proof: validator `000000006697`, exit `0`, `ok: 1`.
- [x] Current target state and actual evidence checked recorded from MCP session `b006-0000xu`. Proof: target `Status`, `Boundary`, `Behavior`, and `Live Evidence` now cite the session and evidence facts.
- [x] Claim And Incorporation Ledger updated with destination and verification state for every accepted claim. Proof: C1-C10 are all marked `applied`.
- [x] Metadata/score changes to apply: target `85/90 -> 88/91`; no owner/emitter/reconstructable/path changes. Proof: target header and validator `completion_update 88`, `confidence_update 91`.
- [x] Score-limiting blockers researched to resolution: stale C++ gate resolved; name/source-expression uncertainty documented and no longer blocks first-draft C++. Proof: target `Autogen And C++ Handling`, `Open Questions`, and `Score Rationale`.
- [x] Owner/emitter/reconstructable changes to apply: none; preserve `00003K` and `TRUE`. Proof: target header still has `CANONICAL_OWNER:00003K`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:00003K`.
- [x] Split/rename/new-child changes to apply: none; keep exact range and stable documentation filename. Proof: target path and title unchanged; range remains `0x00457310-0x004573b3`.
- [x] Source-placement, range/split/padding/reclassification, or IDA rename/type/comment changes to apply or confirm not applicable: no IDA DB writes in callback unless supervisor separately authorizes; optional source-facing comment only. Proof: no IDA DB write or rename/type/comment command was run.
- [x] First-draft C++ to apply: target helper body plus support declaration updates listed above. Proof: target formal block and class formal block contain the accepted body/declarations; generated file contains [UID:0000XT] body.
- [x] Third-party import directive to apply or confirm not applicable: not applicable; target is NexusTK source-authored code, not a third-party static embed.
- [x] Exact target/support doc facts to incorporate at report-level detail: all ledger rows C1-C10. Proof: C1-C10 are marked `applied`.
- [x] Historical/stale assumptions, rejected alternatives, and negative evidence to preserve: old `95/95` blank-C++ rationale as superseded, public erase rejection, LinkedList rejection, consumer-specific owner rejection, and only-cleanup-caller evidence. Proof: target `Autogen And C++ Handling`, `Ownership Decision`, `Open Questions`, and `Changes`.
- [x] Wave2/Wave3 mentions or artifacts encountered and ignored/rejected as stale: generated/source-tree outputs used only as current validator/generated context, not as authority over current MCP. Proof: report still treats current MCP as primary evidence and generated output as freshness proof.
- [x] Open questions to close or document as evidence-backed unresolved: exact original helper spelling, folder/header visibility, and support declaration placement. Proof: target `Open Questions`, class/file open questions, and support notes preserve those caveats.
- [x] Validators to run: target, class, file, node, bucket, and InsertNode support validators as listed in `Validator Results`; generated freshness check if generated output is inspected. Proof: validator table above.
- [x] Generated report refresh expected: accepted target/class changes should replace the [UID:0000XT] empty emitter marker in `auto-generated/NexusTK/archive/DATIndexVector.cpp` after validator/autogen refresh; no manual generated report or coverage edit. Proof: generated header `validator-command-id: 000000006697`, [UID:0000XT] body present, generated SHA256 recorded.

Implementation callback pass:

- [x] Report accepted by supervisor for implementation. Proof: user callback says Gate 1 passed for report SHA256 `CD76A6F37C566A86D2C408B9D1FED360550DA6FE55B5595D6DBD551707A64EA5`.
- [x] All accepted target/support doc details incorporated at report-level detail. Proof: six requested by-* files updated and validators `000000006692` through `000000006697` passed.
- [x] Claim And Incorporation Ledger updated with destination and verification state for every accepted claim. Proof: C1-C10 are marked `applied`.
- [x] Metadata/score/owner/emitter/split/rename/C++ changes applied or explicitly not applied with reason. Proof: target score changed to `88/91`; owner/emitter/reconstructable/range/filename/title unchanged; no split/rename/new child applied.
- [x] Historical/stale assumptions, rejected alternatives, and negative evidence preserved. Proof: old `95/95` rationale is superseded, public erase/API and non-DATIndexVector owner routes remain rejected, and only-cleanup-caller evidence remains prominent.
- [x] Open questions resolved or documented with evidence-backed unresolved rationale. Proof: exact source spelling and original method/free-helper expression remain documented caveats, not C++ blockers.
- [x] Validators run and results recorded with command, working directory, command id, timestamp, exit code, `ok` count, and generated-refresh state when applicable. Proof: validator table above.
- [x] Generated report refresh completed by validator or explicit generated freshness state reported. Proof: `auto-generated/NexusTK/archive/DATIndexVector.cpp` inspected with command `000000006697`, timestamp `2026-07-05T03:04:42-04:00`, refresh source `deferred-generated-refresh`, and SHA256 `6B2B58BB382414C01AA1B2031F34CBB099C11DDFB97B80DA77F36EE4AD34AEED`.
- [x] Remaining unapplied accepted items listed with exact blocker. Proof: none; no accepted item remains unapplied and no blocker is open.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B005","command_id":"000000006721","destination_path":"executed-b-agent-research/B005/0000XT-DATIndexVectorRemoveNodeHelper-source-quality.md","details":"report executed into central archive","event":"executed","source_path":"tools/leaser/Agents/Agent-B005/research/0000XT-DATIndexVectorRemoveNodeHelper-source-quality.md","timestamp":"2026-07-05T03:15:08-04:00","uid":"0000XT"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
