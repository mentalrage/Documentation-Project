** TARGET-REPORT-UID:00023A **
** AUTHOR-AGENT-ID:B004 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# 00023A MetaManNodeDestroyHelper Source-Quality Research

## Finalized Report / Current Recommendation

- Current recommendation: keep [UID:00023A] `by-memory/0x00524590-0x005245b1.MetaManNodeDestroyHelper.md` as a narrow `MetaMan` table-map node cleanup helper owned by [UID:000088] `MetaMan`, but document its source disposition more explicitly as old MSVC `std::map<SimpleUString, MetaTable *>` helper glue generated from `MetaMan::m_tables`, not as a handwritten public/private `MetaMan` method.
- Final disposition: no split, merge, ownership move, or reclassification to `MetaTable` is needed. The helper is source-declared/generated-binary style support for `MetaMan::m_tables`: source should express the map member and normal map cleanup/insert rollback, while this exact helper page preserves binary audit evidence.
- Required action if accepted: update only the target page with the current 2026-06-25 live MCP evidence, the generated-helper/no-handwritten-body conclusion, the generated-report stale-state note, and a formal no-body reconstruction comment. Run the scoped validator on the target to refresh validator-owned generated reports.
- Confidence: high for boundary, bytes, caller/callee set, `MetaMan` ownership, and generated map-helper disposition; medium-high for the exact audit/helper spelling `MetaManTableNodeDestroyHelper`, because IDA still names the function `sub_524590` and no original symbol proof is available.

## Supporting Research

## Target

- Target UID: `00023A`
- Target path: `by-memory/0x00524590-0x005245b1.MetaManNodeDestroyHelper.md`
- Assignment id: `B004-report-00023A-metaman-node-destroy-helper-20260625`
- Source queue/report row at assignment: `auto-generated/-ag-research-tracker.md`, `## by-memory` -> `### Not-Covered Files - Reconstructable`, row `74/86`, combined `80.0`, reconstructable `true`, reports `0`.
- Current supervisor classification: report-only B-agent source-quality research; IDA MCP mandatory.
- Current source-page state before this report: target header is already `COMPLETION:87`, `CONFIDENCE:90`, `CANONICAL_OWNER:000088`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:000088`, blank `EMITTER_POSITION_OPTIONAL`, blank formal `RECONSTRUCTION_CPP CODE`.
- Generated state before this report: validator-owned generated reports are stale for this target. `auto-generated/-ag-research-tracker.md` still lists `74/86`, and `auto-generated/-ag-coverage-report-by-memory.md` still renders `74%`, while the source page header is `87/90`.

## Current Target State

- Existing metadata: source page is `87/90`, owner/emitter [UID:000088] `MetaMan`, reconstructable true, formal C++ blank.
- Existing owner/emitter/reconstructable state: direct class parent [UID:000088] `MetaMan`, which routes through [UID:0000LC] `MetaMan` and `NexusTK/metadata/MetaMan.cpp`.
- Existing C++/emitter state: source page emits through [UID:000088] but has an empty reconstruction block. Existing prose says this is intentional because `MetaMan::m_tables` should generate the helper rather than a standalone handwritten body.
- Existing open questions, blockers, placeholder names, stale assumptions, or contradictory claims: no remaining boundary/caller/callee blocker; the remaining source-quality issue is making the helper disposition explicit enough that the blank body is not mistaken for missing first-draft C++. The generated tracker/coverage mismatch is a validator-generated stale-state issue, not a target-doc fact.
- Related target/support docs checked: [UID:000088] `by-class/MetaMan.md`, [UID:0000LC] `by-file/MetaMan.md`, [UID:0001C8] `by-memory/0x005227d0-0x00524581.MetaMan.md`, [UID:0001CA] `by-memory/0x005245c0-0x0052462a.MetaTableRowFindByKey.md`, [UID:0001CB] `by-memory/0x00524630-0x00525914.MetaTable.md`, `by-memory/-ignored.md`, `by-project-structure/proposed-source-tree.md`, generated research/coverage reports, and executed B009 `000088-MetaMan-class-source-quality.md`.

## Executive Recommendation

- Best direct owner: [UID:000088] `MetaMan`. The helper cleans a node from `MetaMan`'s metadata table-name map/tree and has only `MetaMan` tree-helper callers.
- Source disposition: not a standalone human-authored method body. It is old MSVC map/set helper glue for the source-level `std::map<SimpleUString, MetaTable *> m_tables` member.
- Reconstructable/emitter disposition: keep `RECONSTRUCTABLE:TRUE` and `EMITTER_UIDS:000088`, because the rebuilt source must declare/use `m_tables` so the compiler/STL emits equivalent cleanup support. Do not write a helper function body for this exact range.
- Formal C++ recommendation: use only this formal block content if the supervisor wants nonblank emitted-code accounting for this special no-body emitter:

```cpp
// Emitted code for this range is covered by [UID:000088].
```

- Score recommendation after accepted target-doc refresh: source page `COMPLETION:89`, `CONFIDENCE:91`; generated assignment-time `74/86` should be refreshed by validator-owned output, not manually edited.

## Supervisor Active Recheck

- The current user/supervisor instruction requires a report-only research pass, mandatory IDA MCP evidence, no subagents, no target/support by-* edits before callback, and no generated/coverage/validator-state edits.
- The assigned item does not require split repair before a final report. Live MCP confirms one function at `0x00524590-0x005245b1`, padding before and after, and a separate successor helper at `0x005245c0`.
- Every source-bearing child in scope was checked: this exact 33-byte helper is the only source-bearing range in `0x00524590-0x005245b1`. Neighboring spans `0x00524581-0x00524590`, `0x005245b1-0x005245c0`, and `0x0052462a-0x00524630` are all `0xcc` padding.

## Inference Research Guidance Check

- Direct IDA facts, documentation evidence, and inference are separated below. IDA confirms bytes, function size, disassembly, decompiler shape, xrefs, callers, callees, and current labels. Documentation supports the `MetaMan::m_tables` source abstraction. The conclusion that this is generated map helper glue is a strong source-shape inference from those facts plus the surrounding helper family.
- Existing documentation was treated as a lead, not proof. The accepted B009 class report had no live MCP in that session, so this B004 pass rechecked the target against live MCP session `80de0a67`.
- Stale Wave2/Wave3/generated material was not used as authority. Current generated reports were read only to identify stale validator-owned state.
- IDA DB mutation was not requested or performed.

## Heuristic / Inference Reanalysis And Validation

- Source-authored helper versus generated helper:
  - Evidence checked: live MCP `analyze_function`, `decompile`, `xrefs_to`, `xref_query`, `callees`, `get_bytes`, component analysis over `0x00523df0`, `0x00523f50`, `0x005241a0`, `0x00524400`, and `0x00524590`, plus [UID:000088] and [UID:0001C8].
  - Best inference: generated old MSVC `std::map` table-node cleanup helper emitted from `MetaMan::m_tables`.
  - Rejected alternative: handwritten `MetaMan::DestroyNode`-style method. The binary shape is one basic block called only from map/tree insert/rollback helpers, and the source-level class already models the underlying map member.
  - Score/C++ impact: supports a stronger no-code proof and a non-body comment block, not a helper function body.
- Compiler/EH glue versus container helper:
  - Evidence checked: target has no EH state machine, no destructor wrapper delete flag, no vtable slot, no string/resource/global access, and no external consumers. Caller component includes map/tree insertion helpers, one of which references `map/set<T> too long`.
  - Best inference: container helper generated by map/tree implementation, not EH-only cleanup and not scalar deleting destructor support.
  - Rejected alternative: pure ignore/padding/runtime artifact. It is executable code that performs required cleanup for source-declared map nodes, so the memory page should remain reconstructable through the owning source declaration rather than ignored as padding.
- Source placement:
  - Evidence checked: [UID:000088] documents `m_tables`; [UID:0000LC] and `by-project-structure/proposed-source-tree.md` route the metadata subsystem to `metadata/MetaMan.cpp`; [UID:0001CA] and [UID:0001CB] document the following `MetaTable` helpers separately.
  - Best inference: direct semantic owner remains [UID:000088] `MetaMan`; file route remains [UID:0000LC] `MetaMan`.
  - Rejected alternative: direct [UID:000089] `MetaTable` ownership. The helper is before the `MetaTable` constructor island, and all callers are in the `MetaMan` table-name tree helper family.
- Range/split:
  - Evidence checked: live `lookup_funcs` reports `0x00524590` as size `0x21` / 33 bytes (Verified with `tools/int_convert.py`), `0x005245b1` and `0x00524581` are not functions, `0x005245c0` is separate `sub_5245C0`, and live `get_bytes` reports all `0xcc` padding around the helper.
  - Best inference: exact target range is already correct; no child split or merge is safe or needed.
- Generated state:
  - Evidence checked: target source header is `87/90`, while generated research tracker and generated by-memory coverage still show `74/86` / `74%`.
  - Best inference: validator-owned generated state has not caught up to source-page metadata for this UID. This report should recommend scoped validation after target edit, not manual generated-file edits.

## Evidence Standards Used

- Evidence types used: live IDA MCP session/tool schema, function inventory, decompilation, disassembly, callers/callees/xrefs, component analysis, raw bytes, local `tools/int_convert.py`, current by-* docs, generated reports as read-only stale-state inputs, and executed B009 report as accepted context rechecked against live MCP.
- Evidence strength: strong for the target's exact behavior and ownership because the live IDA facts and current source docs independently converge on the same map-node cleanup role.
- Evidence ladder application: direct IDA facts establish range/behavior; xrefs and component analysis establish reachability and context; current class/file docs establish source placement; source-shape inference then decides no handwritten body is appropriate.
- Tool limitations: IDA MCP does not prove original symbol spelling or whether the original source used a flat `MetaMan.cpp` path. Decompiler names such as `Block`, `sub_524590`, and `sub_524400` are evidence only, not source-facing names.

## Evidence Checked

- IDA MCP/manual-disassembly/raw-byte checks performed:
  - JSON-RPC `initialize` and `tools/list` succeeded against `http://127.0.0.1:13337/mcp`.
  - `idb_list` reported active session `80de0a67`, input `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, worker PID `26892`, `is_analyzing:false`.
  - `server_health` on session `80de0a67` reported `status: ok`, module `NexusTK.exe`, imagebase `0x400000`, `auto_analysis_ready:true`, `hexrays_ready:true`, strings cache ready.
  - `lookup_funcs` for `0x00524590`, `0x005245b1`, `0x00524581`, `0x005245c0`, `0x00524400`, and `0x005c7526`.
  - `analyze_function`, `decompile`, `xrefs_to`, `xref_query`, `callees`, and `get_bytes` for `0x00524590`.
  - `analyze_component` over `0x00523df0`, `0x00523f50`, `0x005241a0`, `0x00524400`, and `0x00524590`.
  - `analyze_function` and `decompile` for `0x00524400` and `0x005c7526`.
  - `entity_query` for functions from `0x00523cf0` through `0x005245c0`.
- by-* docs, support docs, old reports, generated reports, and trackers checked:
  - `by-memory/0x00524590-0x005245b1.MetaManNodeDestroyHelper.md`
  - `by-class/MetaMan.md`
  - `by-file/MetaMan.md`
  - `by-memory/0x005227d0-0x00524581.MetaMan.md`
  - `by-memory/0x005245c0-0x0052462a.MetaTableRowFindByKey.md`
  - `by-memory/0x00524630-0x00525914.MetaTable.md`
  - `by-memory/-ignored.md`
  - `by-project-structure/proposed-source-tree.md`
  - `auto-generated/-ag-research-tracker.md`
  - `auto-generated/-ag-memory-coverage.md`
  - `auto-generated/-ag-coverage-report-by-memory.md`
  - `executed-b-agent-research/B009/000088-MetaMan-class-source-quality.md`
  - Agent-B004 `goal.md` and `notes.md`
- Negative checks performed:
  - No non-padding bytes in the immediate pre/post gaps.
  - No caller outside the `MetaMan` map/tree helper family.
  - No strings in the target helper and no direct global, resource, vtable, or packet references from the target.
  - No successor/predecessor function crossing at `0x00524581` or `0x005245b1`.
- Failed, unavailable, or intentionally skipped checks and why:
  - The documented `tools/int_convert_readme.txt` path was absent; the actual file is `tools/int_convert_readme.md` and was read.
  - One initial local `int_convert.py` shell invocation was malformed by quoting; it was discarded and rerun successfully through stdin JSON. Only the successful rerun is cited.
  - No validator was run because this is report-only and no by-* file was edited.
  - No IDA rename/type/comment mutation was attempted because the assignment is report-only and IDA DB edits are not authorized.

## Inference Claim Ledger

| Claim | Confidence | Evidence | Counter-evidence checked | Next verification / remaining uncertainty |
| --- | --- | --- | --- | --- |
| `0x00524590-0x005245b1` is one exact function, not a mixed range. | Confirmed | `lookup_funcs` size `0x21`; `get_bytes` target bytes; padding before/after; `0x005245b1` not a function. | Checked successor `0x005245c0`, previous boundary `0x00524581`, and padding bytes. | None for split; only final-audit byte provenance could raise toward 95+. |
| The helper destroys a map node payload key at `node + 0x10` and frees the node. | Confirmed | Disassembly pushes `esi+0x10`, calls `sub_524400`, then pushes `0x2c` and `esi` to `sub_5C7526`; decompile matches. | Checked callee reset/free behavior and caller component. | Exact original type names remain inferred. |
| Direct owner is [UID:000088] `MetaMan`. | Strong | Three callers are `sub_523DF0`, `sub_523F50`, and `sub_5241A0`, all documented as `MetaMan` table-map/tree helper family; [UID:000088] documents `m_tables`. | Checked [UID:000089] `MetaTable` successor and [UID:0001CA] row helper separately. | No original source symbol proof; source path remains reconstructed. |
| This is generated/container helper glue, not a handwritten method body. | Strong | One basic block; only map/tree rollback callers; component includes `map/set<T> too long`; class page's `std::map<SimpleUString, MetaTable *> m_tables` explains node layout. | Checked EH/destructor/globals/strings/vtable alternatives. | Exact MSVC/STL source spelling not proven. |
| Formal target C++ should not contain a helper body. | Strong | Source should emit map declaration on [UID:000088]; handwritten body would duplicate compiler/STL output and look decompiler-shaped. | Checked current by-structure code gate and supervisor no-body emitter comment guidance. | Supervisor may choose blank block or minimal comment; this report recommends the minimal comment for generated accounting. |

## Positive Evidence Summary

- Direct facts supporting the chosen recommendation:
  - Live MCP reports `sub_524590` at `0x524590`, size `0x21` / 33 bytes (Verified with `tools/int_convert.py`).
  - The helper has one basic block, cyclomatic complexity `1`, no strings, no direct globals, no return value, and two callees: `sub_524400` and `sub_5C7526`.
  - The disassembly computes `node + 0x10`, calls the small-string reset helper, then calls the free wrapper with size `0x2c` / 44 bytes (Verified with `tools/int_convert.py`).
  - Live xrefs show exactly three callers: `0x00523f3e` in `sub_523DF0`, `0x0052418c` in `sub_523F50`, and `0x005243a3` in `sub_5241A0`.
- Corroborating documentation/generated-report evidence:
  - [UID:000088] models `MetaMan::m_tables` as `std::map<SimpleUString, MetaTable *>` and documents the 44-byte raw node layout for audit.
  - [UID:0000LC] routes `MetaMan`, `MetaTable`, metadata packet sync, and loose `Meta.dat` behavior through `metadata/MetaMan.cpp`.
  - `by-memory/-ignored.md` records the surrounding `0xcc` padding spans as metadata subsystem alignment.
- Strongest inference chain and why it is sufficient:
  - The helper's only callers are map/tree helpers, its body only destructs a node key and frees the node, and the class/source docs already model the source-level map member. This is enough to recommend generated map helper/no-body disposition without needing original source symbol proof.

## IDA MCP Facts

- Function/range facts:
  - `lookup_funcs 0x00524590`: `sub_524590`, start `0x524590`, size `0x21`.
  - `lookup_funcs 0x005245b1`: not a function.
  - `lookup_funcs 0x00524581`: not a function.
  - `lookup_funcs 0x005245c0`: `sub_5245C0`, size `0x6a`.
  - `entity_query` over `0x00523cf0-0x005245c0` lists the helper family in address order: `sub_523CF0`, `sub_523DF0`, `sub_523F50`, `sub_5241A0`, `sub_5243C0`, `sub_524400`, `sub_524460`, `sub_524470`, `sub_5244E0`, `sub_524590`, and `sub_5245C0`.
- Disassembly facts:
  - Complete target assembly:

```asm
524590  push ebp
524591  mov ebp, esp
524593  push esi
524594  mov esi, [ebp+Block]
524597  lea eax, [esi+10h]
52459a  push eax
52459b  push ecx
52459c  call sub_524400
5245a1  push 2Ch
5245a3  push esi
5245a4  call sub_5C7526
5245a9  add esp, 10h
5245ac  pop esi
5245ad  pop ebp
5245ae  retn 4
```

- Decompiler facts:
  - Target decompile is:

```c
void __thiscall sub_524590(void *this, void *Block)
{
  sub_524400((int)this, (int)Block + 16); /*0x52459c*/
  sub_5C7526(Block); /*0x5245a4*/
}
```

- Data/table/padding facts:
  - `get_bytes 0x00524581 size 15` returns fifteen `0xcc` bytes (Verified with `tools/int_convert.py`).
  - `get_bytes 0x00524590 size 33` returns `55 8b ec 56 8b 75 08 8d 46 10 50 51 e8 5f fe ff ff 6a 2c 56 e8 7d 2f 0a 00 83 c4 10 5e 5d c2 04 00`.
  - `get_bytes 0x005245b1 size 15` returns fifteen `0xcc` bytes (Verified with `tools/int_convert.py`).
  - `get_bytes 0x0052462a size 6` returns six `0xcc` bytes (Verified with `tools/int_convert.py`).
- Xref facts:
  - `xrefs_to 0x00524590` and `xref_query` both report three inbound code xrefs: `0x00523f3e`, `0x0052418c`, and `0x005243a3`.
  - `analyze_component` reports `sub_523DF0` contains the string `map/set<T> too long`, supporting old map/set helper context.
- Vtable/global/type facts:
  - No direct vtable/global/type references from the target function.
  - Type/layout evidence comes from [UID:000088]'s documented raw node layout and the target's `node + 0x10` / `0x2c` instructions.
- Negative IDA facts:
  - No strings in `sub_524590`.
  - No callers outside `sub_523DF0`, `sub_523F50`, and `sub_5241A0`.
  - No branch structure or EH dispatch in the target.

## Function / Child Inventory

| Range / Item | UID / Path | Role | Reconstructable | Direct Parent | Score | Status |
| --- | --- | --- | --- | --- | --- | --- |
| `0x00524581-0x00524590` | [UID:0000VN] `by-memory/-ignored.md` | Alignment padding before target | False/ignored | metadata subsystem boundary | `100/strong` in ignored ledger | Already covered; no edit recommended. |
| `0x00524590-0x005245b1` | [UID:00023A] target | MetaMan table-map node payload cleanup and free helper | True through source-declared map member | [UID:000088] | current source `87/90`; recommended `89/91` | Update target evidence/no-body comment; no split. |
| `0x005245b1-0x005245c0` | [UID:0000VN] `by-memory/-ignored.md` | Alignment padding after target | False/ignored | metadata subsystem boundary | `100/strong` in ignored ledger | Already covered; no edit recommended. |
| `0x005245c0-0x0052462a` | [UID:0001CA] `MetaTableRowFindByKey` | Separate row-tree lookup helper | True | [UID:0000LC] / [UID:000089] context | `88/90` | Separate source-ready helper; not part of target. |

## Direct Xref / Caller Inventory

| Address / Item | Xref / Caller / Callee | Meaning |
| --- | --- | --- |
| `0x00523f3e` | Call from `sub_523DF0`, size `0x15d` / 349 bytes (Verified with `tools/int_convert.py`) | Map/tree attach/rebalance or insert overflow cleanup; component contains `map/set<T> too long`. |
| `0x0052418c` | Call from `sub_523F50`, size `0x24a` / 586 bytes (Verified with `tools/int_convert.py`) | Insert-with-hint/rollback cleanup path in the same MetaMan table tree family. |
| `0x005243a3` | Call from `sub_5241A0`, size `0x211` / 529 bytes (Verified with `tools/int_convert.py`) | Find-or-insert node helper cleanup path after key construction/comparison work. |
| `0x00524400` | Callee `sub_524400`, size `0x57` / 87 bytes (Verified with `tools/int_convert.py`) | Small-string reset/destructor helper: frees heap backing if capacity is at least 8, resets length to zero, capacity to 7, and writes a UTF-16 NUL. |
| `0x005c7526` | Callee `sub_5C7526`, size `0xe`; decompile calls `j_j___free_base(Block)` | Broad free wrapper; target passes the node pointer after pushing node size `0x2c`. |

## Documentation Evidence And IDA Status

- Existing docs that support the conclusion:
  - [UID:00023A] already documents exact boundary, bytes, three callers, callee behavior, and no-code map-helper policy.
  - [UID:000088] already documents `std::map<SimpleUString, MetaTable *> m_tables`, raw 44-byte map node layout, and the target helper as table-tree node cleanup.
  - [UID:0000LC] already places the metadata subsystem in `metadata/MetaMan.cpp` and lists the target as a metadata tree-node payload cleanup helper.
  - [UID:0001C8] records the same helper family and treats broad aggregate C++ as blank because exact child pages should carry bodies and map glue should not be hand-authored.
- Existing docs that are stale, incomplete, or contradicted:
  - Validator-owned generated tracker/coverage rows still show stale `74/86` / `74%` for [UID:00023A].
  - The target can be clearer that the recommended nonblank formal block, if used, is a comment only and not a source body.
- Generated/coverage report state:
  - `auto-generated/-ag-memory-coverage.md` routes [UID:00023A] as `emits`, owner/emitter `000088`, generated path `auto-generated/NexusTK/metadata/MetaMan.cpp`, but `has_code` is `no`.
  - `auto-generated/-ag-coverage-report-by-memory.md` renders [UID:00023A] with `emits_code:false`, reconstructable, stale `74%`, and old update timestamp.

## Ranked Ownership Analysis

### 1. [UID:000088] MetaMan

- Evidence for:
  - All three callers are inside the documented `MetaMan` table tree helper family before the `MetaTable` successor.
  - [UID:000088] documents the source-level `m_tables` member and raw node layout that match the helper's `node + 0x10` and `0x2c` free behavior.
  - [UID:0000LC] routes `MetaMan` and metadata table management to `metadata/MetaMan.cpp`.
- Evidence against:
  - IDA label remains raw `sub_524590`; original helper symbol is not proven.
  - The helper body is more compiler/STL-shaped than handwritten method-shaped.
- Decision:
  - Accepted as direct semantic owner. The compiler/STL-shaped body affects C++ policy, not ownership.

### 2. [UID:0000LC] MetaMan source file

- Evidence for:
  - File root owns the metadata subsystem and eventual source route.
  - If the helper were a file-local free helper, this would be the next plausible owner.
- Evidence against:
  - Current direct semantic owner should be the narrower `MetaMan` class because the helper exists to support the class member `m_tables`.
  - The class page clears the parent gate and already emits the `m_tables` declaration.
- Decision:
  - Retain as emitter route through [UID:000088] -> [UID:0000LC], not as direct canonical owner.

### 3. [UID:000089] MetaTable / [UID:0001CA] MetaTable row-tree helper

- Evidence for:
  - Address adjacency: `MetaTableRowFindByKey` begins at `0x005245c0`, and `MetaTable` constructor follows at `0x00524630`.
- Evidence against:
  - There is `0x005245b1-0x005245c0` padding before the successor helper.
  - No target caller belongs to `MetaTable`; all target callers are `MetaMan` tree helper paths.
  - Target frees `MetaMan` table-name map nodes, not `MetaTable` row nodes.
- Decision:
  - Rejected. Adjacency is weaker than xrefs/caller context.

### 4. No owner / ignored runtime-only helper

- Evidence for:
  - Body is STL/map helper glue and not a handwritten NexusTK method.
  - The final source should not contain a standalone helper body.
- Evidence against:
  - The helper is generated from a source-level `MetaMan::m_tables` declaration and is necessary for reconstructed behavior.
  - Owner and emitter route are clear through `MetaMan`.
- Decision:
  - Rejected as final metadata. Keep reconstructable through source declaration, with no handwritten body.

## Source Placement

- Recommended source file/class/global/module placement: `MetaMan::m_tables` in [UID:000088] `MetaMan`, routed through [UID:0000LC] `metadata/MetaMan.cpp`.
- Why this placement fits source-tree and subsystem context: `MetaMan.cpp` owns loose `Meta.dat`, metadata packet synchronization, `MetaMan`, `MetaTable`, and metadata table lookup. The target only supports the manager's table-name map node cleanup.
- Rejected placements and why:
  - `MetaTable`: successor adjacency only; no target xrefs.
  - DAT/archive modules: `Meta.dat` metadata cache is loose-file metadata state, not packed archive logic.
  - UI/resource consumers: no direct target caller and no ownership of metadata storage.
- Remaining placement uncertainty: original folder spelling may have been flat `MetaMan.cpp`, but the project reconstruction route `NexusTK/metadata/` remains correct.

## Range / Split / Padding / Reclassification Analysis

- Exact range/boundary facts:
  - Target is `0x00524590-0x005245b1`, 33 bytes (Verified with `tools/int_convert.py`).
  - Preceding gap `0x00524581-0x00524590` is fifteen `0xcc` bytes (Verified with `tools/int_convert.py`).
  - Following gap `0x005245b1-0x005245c0` is fifteen `0xcc` bytes (Verified with `tools/int_convert.py`).
  - Successor padding `0x0052462a-0x00524630` is six `0xcc` bytes (Verified with `tools/int_convert.py`).
- Children/subranges to create, repair, merge, leave ignored, or leave no-owner:
  - None. Existing ignored padding ledger and neighboring exact pages are correct.
- Padding/table/data/code distinctions:
  - Target is executable `.text`; surrounding spans are alignment padding; successor is separate row-tree lookup helper.
- Parent/container impact:
  - No parent range repair is needed. [UID:0001C8] and [UID:000088] already describe this helper as an adjacent continuation / child evidence.

## Negative Evidence Summary

- No direct evidence supports a public/private handwritten `MetaMan` method body: no external callers, no virtual dispatch, no named source symbol, and no behavior beyond key destructor + node free.
- No evidence supports `MetaTable` ownership: the `MetaTable` row helper begins after padding and has different callers/role.
- No evidence supports EH-only cleanup: target has no EH state logic and is directly called by tree helpers as ordinary cleanup.
- No evidence supports a split: target body is one basic block and every byte belongs to the helper.
- No evidence supports manual generated-file repair: stale `auto-generated` rows are validator-owned.

## IDA Rename / Type / Comment Recommendations

- Proposed source-facing audit name: `MetaManTableNodeDestroyHelper`.
- Evidence for name:
  - It cleans the initialized key/payload at node `+0x10`.
  - It frees the exact `0x2c` / 44-byte table-map node.
  - Only `MetaMan` table-tree helper callers reference it.
- Items intentionally left unchanged and why:
  - Do not request an IDA rename in this report-only pass.
  - Do not create a source class/type for the raw node in final C++; [UID:000088] may keep the raw node layout as an audit comment, but source should use `std::map<SimpleUString, MetaTable *>`.
- Whether IDA DB edits are safe, unsafe, or not requested:
  - Not requested. If a later authorized IDA comment/rename pass occurs, `sub_524590 -> MetaManTableNodeDestroyHelper` is evidence-backed for audit, with a comment that it is map-helper glue generated from `MetaMan::m_tables`.

## First-Draft C++ Recommendation

- Eligible for draft C++: eligible only for a no-body emitted marker because the page is reconstructable and has an emitter route, but the helper body itself should be compiler/STL-generated from [UID:000088]'s `std::map` declaration.
- Recommended code: exact formal `RECONSTRUCTION_CPP CODE` header/block insertion text:

```cpp
// Emitted code for this range is covered by [UID:000088].
```

- Reason it preserves exact original behavior: the runtime behavior should be produced by the compiler/STL implementation of `MetaMan::m_tables`; adding a handwritten helper body would duplicate implementation detail and risks diverging from the original map support code.
- Reason it matches the most plausible original precompiled mid-2000s developer source shape: a human source file would declare/use `std::map<SimpleUString, MetaTable *>`, not write a one-block `sub_524590`-style helper that manually calls a small-string reset and free wrapper.
- Inferred source-facing names/types/fields used instead of IDA/decompiler labels: [UID:000088] already uses `MetaMan`, `SimpleUString`, `MetaTable`, and `m_tables`; this target should use `MetaManTableNodeDestroyHelper` only as an audit/helper label.
- Naming/coding style convention used and evidence for consistency: existing metadata docs use `MetaMan`, `MetaTable`, `SimpleUString`, and `m_` member names; the comment keeps those source names and avoids raw `sub_` labels.
- Reason code should remain blank, if the supervisor rejects the comment: the target-specific no-code proof above remains valid; however, the minimal comment is preferred for generated-output accounting because the page currently has an emitter route with no body.
- Exact no-code proof, if not eligible for a body: one-block helper, only map/tree cleanup callers, `node + 0x10` small-string reset, `0x2c` node free, generated from `m_tables`, no public source API, no independent behavior outside container cleanup.

## Final Recommendation

- Exact changes recommended:
  - Update target evidence date/provenance to include live IDA MCP session `80de0a67` on 2026-06-25.
  - Record explicit source disposition: old MSVC map/tree helper generated from `MetaMan::m_tables`; not a handwritten `MetaMan` method; not `MetaTable`; not EH-only glue.
  - Insert the formal no-body comment block shown above, or explicitly preserve a blank block with the same no-code proof if the supervisor rejects emitted comments for this page.
  - Note generated tracker/coverage stale state and refresh through scoped validator.
- Exact parent assignments recommended:
  - Keep `CANONICAL_OWNER:000088`.
  - Keep `EMITTER_UIDS:000088`.
  - Keep `RECONSTRUCTABLE:TRUE`.
- Exact items left no-owner/non-emitting and why:
  - None.
- Exact future work, if any, outside this assignment scope:
  - Broader final-audit work on the complete `MetaMan` tree-helper family can later decide exact original helper spelling and whether any IDA comments/types should be applied. That is not a blocker for this target's current owner/no-code disposition.

## Recommended Target Doc Changes

- Target path: `by-memory/0x00524590-0x005245b1.MetaManNodeDestroyHelper.md`
- Exact report facts to incorporate:
  - Live MCP session `80de0a67` on 2026-06-25 confirmed the target as `sub_524590`, size `0x21` / 33 bytes (Verified with `tools/int_convert.py`), one basic block, callers `sub_523DF0`, `sub_523F50`, `sub_5241A0`, callees `sub_524400` and `sub_5C7526`, exact bytes, and `0xcc` padding around the range.
  - `sub_524400` resets a small-string-shaped payload: heap-free path for capacity at least 8, length reset at `+0x10`, capacity reset to 7, and UTF-16 NUL at payload `+0x00`.
  - `sub_5C7526` wraps `j_j___free_base(Block)`.
  - `analyze_component` ties the caller family to old map/set support and reports `map/set<T> too long` in `sub_523DF0`.
  - Source disposition is generated map/tree node cleanup from `MetaMan::m_tables`, not a handwritten helper body.
  - Generated reports are stale compared with the source header and need validator refresh.
- Metadata/score/owner/emitter/reconstructable/C++ changes:
  - Change source metadata to `COMPLETION:89`, `CONFIDENCE:91`.
  - Keep `CANONICAL_OWNER:000088`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:000088`, blank `EMITTER_POSITION_OPTIONAL`.
  - Set formal `RECONSTRUCTION_CPP CODE` content to the single comment:

```cpp
// Emitted code for this range is covered by [UID:000088].
```

- Historical/stale assumptions, rejected alternatives, and negative evidence to preserve:
  - Preserve the existing A003/B009 history but add that B004 rechecked live MCP because B009's report itself recorded no live MCP access in that session.
  - Preserve rejected alternatives: direct file root owner only, `MetaTable` adjacency ownership, hand-authored method body, ignored padding/runtime-only artifact, and EH-only cleanup.

## Recommended Support Doc Changes

- No required support by-* doc edits in this report's implementation callback.
- [UID:000088] `by-class/MetaMan.md`, [UID:0000LC] `by-file/MetaMan.md`, and [UID:0001C8] `by-memory/0x005227d0-0x00524581.MetaMan.md` already contain the same-or-greater support facts: `m_tables`, map/tree helper policy, target caller set, node layout, and no-code wrapper policy.
- If the supervisor wants support freshness text, it can be limited to cross-checking those pages after the target validator run; this report does not require modifying them to preserve its valid target facts.

## Score And Metadata Recommendation

- Current score/metadata:
  - Source page: `COMPLETION:87`, `CONFIDENCE:90`, `CANONICAL_OWNER:000088`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:000088`.
  - Assignment/generated tracker row: stale `74/86`, combined `80.0`, reports `0`.
- Recommended score/metadata:
  - Source page after implementation: `COMPLETION:89`, `CONFIDENCE:91`, `CANONICAL_OWNER:000088`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:000088`.
- Score rationale and reason not higher/lower:
  - Completion should rise because current live MCP evidence, caller component context, generated-helper classification, no-body formal comment, and generated-stale-state repair plan close the remaining target-specific source-quality blockers.
  - Confidence should rise modestly because live MCP independently rechecked the exact facts under the active mandatory-IDB standard.
  - Do not raise to `95+`: exact original helper symbol/source spelling is not proven; the surrounding map/tree helper family has not received a final whole-family STL/source audit; and the page should not claim final-audit source-body readiness.
- Score-improvement attempt:
  - Blocker: possible source-authored helper body. Research: live caller/callee/body/component analysis. Result: resolved as generated map-helper no-body.
  - Blocker: possible `MetaTable` adjacency ownership. Research: checked successor, padding, xrefs, support docs. Result: rejected; keep `MetaMan`.
  - Blocker: stale generated rows. Research: compared source header and generated reports. Result: validator refresh required; no manual generated edit.
  - Blocker: formal C++ blank despite emitter route. Research: checked by-structure/supervisor no-body comment rule and source-disposition evidence. Result: recommend one-line emitted-code-covered comment.
- Metadata fields to change or leave unchanged:
  - Change only completion/confidence and formal C++ block content.
  - Leave owner/emitter/reconstructable unchanged.

## Open Questions With Attempted Resolution

- Open question: Is this source-authored helper code?
  - Resolution: no standalone handwritten method body is supported; it is generated map/tree cleanup emitted from source-level `m_tables`.
  - Evidence: live one-block body, three map/tree callers, `map/set<T> too long` caller context, `std::map` support docs.
  - Score/C++ impact: supports `89/91` and no helper body.
- Open question: Should it be compiler/EH glue, destructor support, container child, or reclassified?
  - Resolution: container helper child under `MetaMan`; not EH glue, not scalar deleting destructor support, not ignored/padding, not `MetaTable`.
  - Evidence: no EH/branch structure; direct calls from map/tree helpers; exact padding boundaries; target-specific cleanup behavior.
  - Score/C++ impact: keep reconstructable through owning map declaration, with no-body comment.
- Open question: Why not higher than `89/91`?
  - Resolution: exact original helper/source spelling and a final whole-family STL helper audit remain outside this target's current written proof. These are below-95 final-audit caveats, not blockers to owner/emitter/no-body disposition.

## Exact Manual Supervisor-Owned Coverage Or Tracker Text

- No explicit manual `-coverage-report.md` text is supplied because the current assignment did not authorize manual coverage-report editing and the primary stale rows are validator-owned generated reports.
- Do not write row text into `auto-generated/-ag-research-tracker.md`, `auto-generated/-ag-memory-coverage.md`, or `auto-generated/-ag-coverage-report-by-memory.md`.
- Expected refresh path: update the source target page, run the scoped validator on that page, and let validator-owned generated reports refresh. If the legacy manual `by-memory/-coverage-report.md` is still being maintained, any manual row replacement remains supervisor-owned and outside this B004 report-only implementation scope.

## Follow-Up Actions

- Supervisor actions:
  - Report accepted and implementation callback sent for the target page and scoped validator.
  - After verified implementation, execute the report through validator with `python .\tools\validator.py execute_report B004 00023A-MetaManNodeDestroyHelper-source-quality.md 00023A --apply`.
- B004 implementation callback actions:
  - Completed: leased only the target page, applied target page changes at report-level detail, ran `python .\tools\validator.py --mode file --file by-memory/0x00524590-0x005245b1.MetaManNodeDestroyHelper.md --apply --queue-timeout 240 --wait-generated`, recorded command id/timestamp/exit code/`ok` count/generated-refresh state, and released the target lease.
- Other-agent actions:
  - None required for this target.

## Confidence

- Recommendation confidence: high.
- Score confidence: high for `89/91`; below final-audit because original symbol spelling and whole-family STL helper proof are not complete enough for `95+`.
- Remaining uncertainty:
  - Exact original helper symbol spelling is unknown.
  - Exact original source folder may have been flat `MetaMan.cpp`, though the current project route is `metadata/MetaMan.cpp`.
  - The target's machine code is compiler/STL-shaped; final output should rely on source declarations and compiler/runtime support rather than a handwritten body.

## Validator Results

- Commands run during report-only pass: none; no target/support by-* docs were edited before supervisor acceptance.
- Implementation callback validator command, run from `source-3/project-documentation` after the accepted target edit:

> Executable block R001 was removed from this report and preserved verbatim in [00023A-MetaManNodeDestroyHelper-source-quality-removed.md](00023A-MetaManNodeDestroyHelper-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

- Implementation callback validator result: exit code `0`, `command_id: 000000001483`, `command_timestamp: 2026-06-25T13:45:15-04:00`, `scanned markdown files: 1`, `ok: 1`.
- Generated refresh proof: validator reported `generated_refresh: completed`, `generated_refresh_command_id: 000000001483`, `generated_refresh_timestamp: 2026-06-25T13:45:15-04:00`, and `autogen_backup_create ------ tools/validator_autogen_backup/20260625-134535 changed generated files backed up`.
- Target-specific validator actions included `completion_update 00023A ... 89`, `confidence_update 00023A ... 91`, `canonical_owner_update 00023A ... 000088`, `autogen_registry_update 00023A`, `autogen_cpp_update: 1`, `memory_auto_coverage_update: 1`, and `research_tracker_update: 1`.
- Noteworthy non-blocking validator noise: the scoped run still reported project-wide stale registry/missing-file items and two `missing_ref_target` entries for stale [UID:0001CB] registry path `by-memory/0x00524630-0x005258f1.MetaTable.md`. These were pre-existing/generated-state issues outside the accepted target edit; the scoped target file still validated with `ok: 1`.
- Validator normalization note: the formal target block was seeded with the accepted one-line marker `// Emitted code for this range is covered by [UID:000088].`; validator's UID link phase normalized it in-place to the canonical linked form `// Emitted code for this range is covered by [UID:000088][MetaMan](by-class/MetaMan.md).` while keeping the formal block one line and preserving the accepted source-disposition meaning.

## Changed Files

- Created:
  - `tools/leaser/Agents/Agent-B004/research/00023A-MetaManNodeDestroyHelper-source-quality.md`
- Modified:
  - `by-memory/0x00524590-0x005245b1.MetaManNodeDestroyHelper.md`
  - `tools/leaser/Agents/Agent-B004/research/00023A-MetaManNodeDestroyHelper-source-quality.md`
- Validator-owned generated refresh:
  - The scoped validator updated/generated validator-owned state, including `auto-generated` and `project-level` outputs, under command `000000001483`.
  - B004 did not manually edit generated reports, project-level generated files, validator state/cache, IDA DB, or any `-coverage-report.md` file.
- Renamed:
  - None.
- Report execution:
  - Not run by B004 during this callback. Supervisor retains any separate `tools/validator.py execute_report ... --apply` step after verification if desired.
- Lease proof:
  - B004 leased only `by-memory/0x00524590-0x005245b1.MetaManNodeDestroyHelper.md` before editing; lease command returned `Success`.
  - B004 released the target immediately after the scoped validator; unlease command returned `Success`.
  - Post-release `tools/leaser/Agents/current_leases.md` did not list any B004 lease for the target.

## Implementation Tracking Checklist

Initial report-only pass:
- [x] Supervisor validation required before implementation. Proof: supervisor accepted this report and sent the implementation callback for [UID:00023A].
- [x] Target/support docs to update: update `by-memory/0x00524590-0x005245b1.MetaManNodeDestroyHelper.md`; no required support-doc edits because [UID:000088], [UID:0000LC], and [UID:0001C8] already preserve the relevant support facts at same-or-greater detail. Proof: only the target by-memory page was edited; no support by-* docs were changed.
- [x] Current target state and actual evidence checked recorded: preserve source page `87/90` versus generated stale `74/86`, live MCP session `80de0a67`, `server_health`, `lookup_funcs`, `analyze_function`, `decompile`, `xrefs_to`, `xref_query`, `callees`, `get_bytes`, `analyze_component`, `entity_query`, and local `tools/int_convert.py` results. Proof: target `Status`, `Behavior Details`, `IDA Evidence`, `Caller And Callee Evidence`, `Reconstruction Evidence`, and `Changes` now incorporate those facts at report-level detail.
- [x] Metadata/score changes to apply: change source page from `COMPLETION:87`, `CONFIDENCE:90` to `COMPLETION:89`, `CONFIDENCE:91`. Proof: target header and validator actions show `completion_update ... 89` and `confidence_update ... 91`.
- [x] Score-limiting blockers researched to resolution: source-authored-vs-generated role resolved as old MSVC map helper; `MetaTable` adjacency rejected; split rejected; no-body C++ policy resolved; generated stale state assigned to validator refresh. Proof: target `Role`, `Reconstruction Notes`, `Rejected Alternatives And Negative Evidence`, and `Changes` record these decisions.
- [x] Owner/emitter/reconstructable changes to apply: keep `CANONICAL_OWNER:000088`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:000088`, blank `EMITTER_POSITION_OPTIONAL`. Proof: target header keeps those values; validator reported `canonical_owner_update ... 000088`.
- [x] Split/rename/new-child changes to apply: no split, rename, or new child. Proof: target documents exact one-function range and padding; no new by-* file was created.
- [x] Source-placement, range/split/padding/reclassification, or IDA rename/type/comment changes to apply or confirm not applicable: record source disposition as generated map/tree node cleanup from `MetaMan::m_tables`; no IDA DB edits requested. Proof: target `Role` and `Reconstruction Notes` record generated map/tree disposition; no IDA mutation was performed.
- [x] First-draft C++ or no-code proof to apply: insert exact formal comment-only `RECONSTRUCTION_CPP CODE` content `// Emitted code for this range is covered by [UID:000088].`; do not add a helper body. Proof: target formal block contains the one-line source-disposition marker; validator normalized the UID token to the canonical linked UID form while preserving the one-line comment and no-body policy.
- [x] Exact target/support doc facts to incorporate at report-level detail: live target bytes/disassembly/decompile, caller/callee set, `sub_524400` small-string reset behavior, `sub_5C7526` free wrapper, map/set component evidence, `0xcc` boundary padding, stale generated-state note, and rejected alternatives. Proof: target sections listed above now contain each accepted fact; no support-doc edits were required.
- [x] Historical/stale assumptions, rejected alternatives, and negative evidence to preserve: preserve A003/B009 history while noting current live MCP recheck; preserve rejected handwritten method, `MetaTable`, EH-only, ignored-runtime-only, and split alternatives. Proof: target `Changes` preserves A003/B009 history; target rejected-alternatives section lists all rejected alternatives.
- [x] Wave2/Wave3 mentions or artifacts encountered and ignored/rejected as stale: generated/simroot evidence treated as lead/support only; current live MCP and by-* docs control the recommendation. Proof: generated stale state is documented as validator-owned and no Wave2/Wave3 material was promoted as authority.
- [x] Open questions to close or document as evidence-backed unresolved: close exact role, ownership, range, source placement, and C++ no-body decision; leave only below-95 original symbol/folder spelling caveats. Proof: target keeps final spelling caveat while closing role/ownership/range/source-disposition issues.
- [x] Validators to run after implementation: `python .\tools\validator.py --mode file --file by-memory/0x00524590-0x005245b1.MetaManNodeDestroyHelper.md --apply --queue-timeout 240 --wait-generated` from `source-3/project-documentation`. Proof: command `000000001483` exited `0` with `ok: 1`.
- [x] Generated report refresh expected or explicit manual supervisor-owned coverage/tracker text to apply: validator-owned generated reports should refresh stale `74/86`/`74%` state; no manual generated report text and no manual `-coverage-report.md` text supplied. Proof: validator reported `generated_refresh: completed`; B004 did not manually edit generated files or coverage reports.

Implementation callback pass:
- [x] Report accepted by supervisor for implementation. Proof: current callback explicitly accepts `00023A-MetaManNodeDestroyHelper-source-quality.md` and authorizes target-only implementation.
- [x] All accepted target/support doc details incorporated at report-level detail. Proof: target has updated metadata, source-disposition marker, live MCP evidence, callee/caller facts, generated-stale note, and rejected alternatives; support docs required no edit.
- [x] Metadata/score/owner/emitter/split/rename/C++ changes applied or explicitly not applied with reason. Proof: `89/91` applied, owner/emitter/reconstructable fields unchanged, no split/rename/new child, one-line formal marker applied with validator UID-link normalization.
- [x] Historical/stale assumptions, rejected alternatives, and negative evidence preserved. Proof: target `Changes` and `Rejected Alternatives And Negative Evidence` sections preserve the accepted history and negative evidence.
- [x] Open questions resolved or documented with evidence-backed unresolved rationale. Proof: target closes role/owner/range/source-disposition questions and preserves only original helper spelling/family-audit caveats below final-audit confidence.
- [x] Validators run and results recorded. Proof: scoped target validator command `000000001483`, timestamp `2026-06-25T13:45:15-04:00`, exit code `0`, `ok: 1`.
- [x] Generated report refresh completed by validator or explicit manual supervisor-owned coverage/tracker text supplied/confirmed unchanged. Proof: `generated_refresh: completed`; no manual generated/project-level/coverage edits by B004.
- [x] Remaining unapplied accepted items listed with exact blocker. Proof: none; accepted target-only callback is fully applied, target lease released, and the only residual validator noise is unrelated stale registry/missing-file state outside this target.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B004","command_id":"000000004165","destination_path":"executed-b-agent-research/B004/00023A-MetaManNodeDestroyHelper-source-quality.md","details":"legacy registry reconstruction","event":"executed","source_path":"tools/leaser/Agents/Agent-B004/research/00023A-MetaManNodeDestroyHelper-source-quality.md","timestamp":"2026-06-25T13:52:19","uid":"00023A"} -->
<!-- {"agent":"B004","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 00023A-MetaManNodeDestroyHelper-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B004/00023A-MetaManNodeDestroyHelper-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"00023A"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
