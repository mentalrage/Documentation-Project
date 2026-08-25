** TARGET-REPORT-UID:0000HJ **
** AUTHOR-AGENT-ID:B009 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **

# 0000HJ AttachedObjectPane Empty-Emitter Family Source-Quality Report

Assignment: `B009-report-0000HJ-AttachedObjectPane-empty-emitter-family-20260701`  
Mode: report-only research originally; implementation callback applied on 2026-07-01 after supervisor acceptance. No generated-file edits, coverage-report edits, validator/tool-state edits, queue/archive/supervisor-ledger edits, subagents, or IDA DB edits were performed by hand.
Revision note: targeted revision after supervisor review. The original report's static-pool comment-only disposition was rechecked against current MCP wrapper/call/data evidence and current PoolAllocator docs. The revised recommendation now treats [UID:0002WP], [UID:0002WQ], and [UID:0002WU] as first-draft source declaration targets.

Target: [UID:0000HJ] `by-file/AttachedObjectPane.md`  
Generated file: `auto-generated/NexusTK/map/AttachedObjectPane.cpp`  
Required report path: `tools/leaser/Agents/Agent-B009/research/0000HJ-AttachedObjectPane-empty-emitter-family-source-quality.md`

## Executive Conclusion

[UID:0000HJ] is a valid source-file root for `NexusTK/map/AttachedObjectPane.cpp`. At report time the generated file contained 14 empty emitter markers; after the accepted 2026-07-01 implementation callback and `--wait-generated` validation, the seven first-batch markers below are filled and the generated file has only the intentionally deferred seven class/aggregate empty markers. The right first implementation batch was not to write monolithic C++ for the broad class/executable aggregate pages. Current MCP and by-* evidence show that the immediately actionable markers are exact compiler/source-generated data children: vtable/string/table markers need no-raw/no-standalone formal comments, while the three exact static pool-storage children should receive first-draft `PoolAllocator` source declarations.

| UID | Target | Disposition |
| --- | --- | --- |
| [UID:000353] | `HitBarObjectPaneVtableData` | Add formal no-raw-vtable marker, mirroring accepted UID000350/UID000355 and the already-applied UID000354 marker pattern. |
| [UID:0002YR] | `DeadSignResourceString` | Add formal resource-literal coverage marker; literal is referenced by HitBar dead-sign render source, not hand-authored as a raw `.rdata` block. |
| [UID:0002YS] | `DamageNumberResourceStrings` | Add formal resource-literal coverage marker for `%d`, `DMGNUM.EPF`, and `DMGNUM.PAL`; stale parent-blank summary should be repaired. |
| [UID:0002WP] | `HitBarObjectPanePoolStaticStorage` | Add first-draft declaration `static PoolAllocator g_hitBarObjectPanePool(0x138, 4);`; current MCP bytes are zero-filled and wrapper constants/xrefs are exact. |
| [UID:0002WQ] | `DamageNumberObjectPanePoolStaticStorage` | Add first-draft declaration `static PoolAllocator g_damageNumberObjectPanePool(0x148, 8);`; current MCP bytes are zero-filled and wrapper constants/xrefs are exact. |
| [UID:0002WU] | `BalloonObjectPanePoolStaticStorage` | Add first-draft declaration `static PoolAllocator g_balloonObjectPanePool(0x1e0, 0x10);`; current MCP bytes are zero-filled and wrapper constants/xrefs are exact. |
| [UID:0003CC] | `ObjectOverlayFrameIndexTables` | Add formal no-standalone-table marker preserving B001-057 file-root ownership and no-xref/no-name caveat. |

The remaining seven empty markers should stay out of the first implementation batch:

| UID | Target | Reason |
| --- | --- | --- |
| [UID:00000M] | `by-class/AttachedObjectPane.md` | Class declaration/body is still blocked by field names, consumed registry naming, and anchor/helper folding. |
| [UID:00000U] | `by-class/BalloonObjectPane.md` | Class aggregate still depends on unsplit methods, inferred custom-color/tail/base-virtual names, and raw helper liveness caveats. |
| [UID:0000YZ] | `0x00467b30-0x0046904e.BalloonObjectPane` | Accepted B005/B008 disposition: mixed method island, padding, raw no-xref helpers, EH cleanup, thunks, and scalar-deleting destructor glue; no aggregate C++. |
| [UID:00003F] | `by-class/DamageNumberObjectPane.md` | Declaration/body blocked by field names, style/sign enum names, digit buffer, animation timing fields, and helper names. |
| [UID:000067] | `by-class/HitBarObjectPane.md` | Declaration/body blocked by deeper field naming and final body shape; support text also needs stale generated/Wave wording cleanup. |
| [UID:00009P] | `by-class/ObjectInfoObjectPane.md` | Declaration/body blocked by class declaration, label/string offsets, config flag names, and draw-state details. |
| [UID:0001D8] | `0x005380b0-0x005387a3.AttachedObjectPane` | Mixed executable aggregate with several methods, raw/non-function helper bytes, and shared helper bodies; split exact children before C++. |

This recommendation removes meaningful empty markers without inventing class declarations, broad aggregate bodies, handwritten vtable arrays, raw pool bytes, or standalone string/table definitions. The pool declarations use best-inferred `g_*ObjectPanePool` names already recorded by [UID:0000TI] `PoolAllocatorStaticInstances`; missing exact original spelling caps confidence but no longer blocks first-draft source emission.

## Current Generated Marker Inventory

At report time, `auto-generated/NexusTK/map/AttachedObjectPane.cpp` had 18 emitters, 4 filled and 14 empty. After implementation validator command `000000003317`, refreshed at `2026-07-01T04:59:24-04:00`, the generated file has 11 filled emitters and 7 empty deferred emitters. Filled emitters now include [UID:000350] `AttachedObjectPaneVtableData`, [UID:000276] `BalloonObjectPaneStaticMasks`, [UID:0002WU] `BalloonObjectPanePoolStaticStorage`, [UID:000354] `DamageNumberObjectPaneVtableData`, [UID:0002YS] `DamageNumberResourceStrings`, [UID:0002WQ] `DamageNumberObjectPanePoolStaticStorage`, [UID:000353] `HitBarObjectPaneVtableData`, [UID:0002YR] `DeadSignResourceString`, [UID:0002WP] `HitBarObjectPanePoolStaticStorage`, [UID:000355] `ObjectInfoObjectPaneVtableData`, and [UID:0003CC] `ObjectOverlayFrameIndexTables`.

Original empty markers and implementation disposition:

| UID | Generated marker | Classification |
| --- | --- | --- |
| `00000M` | `by-class\AttachedObjectPane.md` | excluded-with-reason: class declaration/body deferred by field names, consumed registry naming, and anchor/helper folding blockers. |
| `00000U` | `by-class\BalloonObjectPane.md` | support note applied, formal class C++ excluded-with-reason: unsplit methods, inferred custom-color/tail/base-virtual names, and raw helper liveness caveats. |
| `0000YZ` | `0x00467b30-0x0046904e.BalloonObjectPane.md` | excluded-with-reason: split-needed executable method island; not in accepted first batch. |
| `0002WU` | `BalloonObjectPanePoolStaticStorage.md` | applied: first-batch `static PoolAllocator g_balloonObjectPanePool(0x1e0, 0x10);` generated. |
| `00003F` | `by-class\DamageNumberObjectPane.md` | support note applied, formal class C++ excluded-with-reason: field names, style/sign enum, digit buffer, animation timing, and helper names still deferred. |
| `0002YS` | `DamageNumberResourceStrings.md` | applied: first-batch source-literal marker generated. |
| `0002WQ` | `DamageNumberObjectPanePoolStaticStorage.md` | applied: first-batch `static PoolAllocator g_damageNumberObjectPanePool(0x148, 8);` generated. |
| `000067` | `by-class\HitBarObjectPane.md` | support note applied, formal class C++ excluded-with-reason: deeper field naming and final body shape still deferred. |
| `000353` | `HitBarObjectPaneVtableData.md` | applied: first-batch no-raw vtable marker generated. |
| `0002YR` | `DeadSignResourceString.md` | applied: first-batch source-literal marker generated. |
| `0002WP` | `HitBarObjectPanePoolStaticStorage.md` | applied: first-batch `static PoolAllocator g_hitBarObjectPanePool(0x138, 4);` generated. |
| `00009P` | `by-class\ObjectInfoObjectPane.md` | excluded-with-reason: class declaration/body deferred and not in accepted first batch. |
| `0001D8` | `0x005380b0-0x005387a3.AttachedObjectPane.md` | excluded-with-reason: split-needed executable aggregate; not in accepted first batch. |
| `0003CC` | `ObjectOverlayFrameIndexTables.md` | applied: first-batch no-standalone-table marker generated. |

## Evidence Read

Workflow and standards:

| File | Use |
| --- | --- |
| `.codex/skills/ntk-b-agent-workflow/SKILL.md` | B-agent workflow requirements and report-only restrictions. |
| `.codex/skills/ntk-b-agent-workflow/references/b-agent-research-and-implementation-workflow.md` | Empty-emitter/source-quality report requirements, implementation-callback expectations, and checklist/ledger requirements. |
| `.codex/skills/ntk-b-agent-workflow/references/score-blocker-audit-standard.md` | Score/blocker closure standard and open-question handling. |
| `.codex/skills/ntk-b-agent-workflow/references/b-agent-report-template.md` | Required report sections and ledger/checklist shape. |
| `by-structure.md` | Source-quality, owner/emitter, code-gate, by-memory C++ block, metadata, and IDA MCP Output Discipline rules. |
| `tools/leaser/Agents/Agent-B009/goal.md` | Current assignment, target, report path, queue source, skipped rows, report-only restrictions, and no-fallback-only MCP requirement. |

Target/generated docs:

| File | Use |
| --- | --- |
| `by-file/AttachedObjectPane.md` | File-root role, proposed contents, current score, accepted source routes, source-root caveats, and prior accepted evidence. |
| `auto-generated/NexusTK/map/AttachedObjectPane.cpp` | Current generated marker inventory and already-filled sibling marker precedent. |
| `auto-generated/-ag-research-tracker.md` | Queue row: [UID:0000HJ] has 18 total emitters, 4 filled, 14 empty, 22.2% complete. |

Current by-* support docs:

| File | Use |
| --- | --- |
| `by-class/AttachedObjectPane.md` | Current `85/88`, blank formal C++, class-shape blockers, vtable child relation. |
| `by-class/BalloonObjectPane.md` | Current `85/90`, blank formal C++, accepted B005/B008 method-island evidence, static mask/pool context. |
| `by-class/DamageNumberObjectPane.md` | Current `86/90`, blank formal C++, resource/vtable support, field/body blockers. |
| `by-class/HitBarObjectPane.md` | Current `85/89`, blank formal C++, method/vtable/pool/resource support, stale wording needing cleanup. |
| `by-class/ObjectInfoObjectPane.md` | Current `85/89`, blank formal C++, vtable support, field/body blockers. |
| `by-memory/0x00467b30-0x0046904e.BalloonObjectPane.md` | Accepted aggregate no-code disposition, split map, raw helper liveness, direct owner [UID:00000U]. |
| `by-memory/0x005380b0-0x005387a3.AttachedObjectPane.md` | Mixed executable aggregate, method/raw/shared-helper starts, split-needed disposition. |
| `by-memory/0x00620734-0x006207e8.HitBarObjectPaneVtableData.md` | Exact vtable child currently blank. |
| `by-memory/0x00620bc0-0x00620bdc.DeadSignResourceString.md` | Exact HitBar literal child currently blank. |
| `by-memory/0x00620bdc-0x00620c10.DamageNumberResourceStrings.md` | Exact DamageNumber literal child currently blank and summary still stale. |
| `by-memory/0x00620c10-0x00620c64.ObjectOverlayFrameIndexTables.md` | File-root no-xref table currently blank with no original declaration name. |
| `by-memory/0x0069b934-0x0069b95c.HitBarObjectPanePoolStaticStorage.md` | Exact HitBar pool storage currently blank; current bytes need zero-filled refresh. |
| `by-memory/0x0069b95c-0x0069b984.DamageNumberObjectPanePoolStaticStorage.md` | Exact DamageNumber pool storage currently blank; current bytes need zero-filled refresh. |
| `by-memory/0x0069b9fc-0x0069ba24.BalloonObjectPanePoolStaticStorage.md` | Exact Balloon pool storage currently blank; current bytes need zero-filled refresh and stale summary repair. |
| `by-global/PoolAllocatorStaticInstances.md` | Current cross-cutting pool inventory; records exact object-pane pool addresses, block sizes, chunk counts, concrete owner placement, and preferred descriptive names `g_hitBarObjectPanePool`, `g_damageNumberObjectPanePool`, and `g_balloonObjectPanePool`. |
| `by-file/PoolAllocator.md` | Allocator mechanics owner; states concrete static pool globals should be declared beside consuming modules, not collapsed into `PoolAllocator.cpp`. |
| `by-type/by-struct/PoolAllocatorLayout.md` | Confirms 40-byte `PoolAllocator` layout and constructor/destructor/allocate/free behavior. |

Executed accepted reports:

| Report | Use |
| --- | --- |
| `executed-b-agent-research/B012/000350-AttachedObjectPaneVtableData-empty-emitter-source-quality.md` | Precedent for exact no-raw-vtable formal marker, score movement, and support repair. |
| `executed-b-agent-research/B004/000354-DamageNumberObjectPaneVtableData-empty-emitter-source-quality.md` | Accepted marker-only vtable implementation; current generated output now has a filled covered-by line. |
| `executed-b-agent-research/B005/000355-ObjectInfoObjectPaneVtableData-empty-emitter-source-quality.md` | Precedent for exact no-raw-vtable formal marker under this file root. |
| `executed-b-agent-research/B004/000276-BalloonObjectPaneStaticMasks-source-quality.md` | Filled static-data precedent when exact source table and xrefs are proven. |
| `executed-b-agent-research/B005/0000YZ-BalloonObjectPane-source-quality.md` and `B008/0000YZ-BalloonObjectPane-source-quality.md` | Accepted no-monolithic-aggregate disposition, owner/emitter route through [UID:00000U], raw helper caveats, and split map. |
| `executed-b-agent-research/B001/0003CC-ObjectOverlayFrameIndexTables.md` | Accepted [UID:0003CC] file-root ownership, no direct xrefs/names, and no class/MapPane/standalone owner. |

## Current MCP Session

IDA MCP was available and used; this report is not fallback-only. Calls were narrow, read-only, paged/schema-current, and bounded to exact relevant addresses.

| Evidence | Result |
| --- | --- |
| Endpoint | `http://127.0.0.1:13337/mcp` |
| Initialize | command id `1`, succeeded; server `ida-pro-mcp` version `1.0.0`, protocol `2025-06-18`. |
| `tools/list` | command ids `2` and filtered `5`, used to confirm current schemas for `idb_list`, `server_health`, `lookup_funcs`, `xrefs_to`, `entity_query`, `get_bytes`, `disasm`, and `int_convert`. |
| `idb_list` | command id `3`, one active session: `supervisor_resume_20260629`, `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, active worker PID `14860`, `is_analyzing:false`. |
| `server_health` | command id `4`, `status:"ok"`, module `NexusTK.exe`, imagebase `0x400000`, auto-analysis ready, Hex-Rays ready, strings cache ready, strings cache size `2067`. |

MCP evidence calls:

| Command id | Tool | Scope |
| --- | --- | --- |
| `6` | `lookup_funcs` | Exact function/address batch for AttachedObjectPane, BalloonObjectPane, HitBar, DamageNumber, and ObjectInfo anchors. |
| `7` | `xrefs_to` | Exact vtable bases, literal addresses, table bases, and pool bases with `limit:30`. |
| `8` | `get_bytes` | Exact byte reads for HitBar vtable range, resource-string tail, frame-index table, and three 40-byte pool blocks. |
| `9` | `entity_query` | Bounded names queries for `0x00620720-0x00620800`, `0x00620bb0-0x00620c80`, and `0x0069b920-0x0069ba40`, with count caps. |
| `10` | `lookup_funcs` | Exact startup/cleanup wrapper and destructor function addresses for the pool-storage children. |
| `11-16` | `disasm` | Bounded disassembly of six tiny pool startup/cleanup wrappers, `max_instructions:20`. |
| `17` | `int_convert` | Exact size/constant conversions: `0xb4`, `0x28`, `0x54`, `0x1e0`, `0x148`, `0x138`, `0x10`. |
| `21-22` | `idb_list`, `server_health` | Targeted revision recheck: same `supervisor_resume_20260629` session active, non-analyzing, MCP health OK, Hex-Rays/string caches ready. |
| `23` | `xrefs_to` | Targeted revision recheck for the three pool bases and shared allocator constructor/allocate/free/destructor targets with `limit:40`. |
| `24` | `get_bytes` | Targeted revision recheck: exact 40-byte reads for [UID:0002WP], [UID:0002WQ], and [UID:0002WU], all zero-filled. |
| `25` | `lookup_funcs` | Targeted revision recheck: exact startup wrappers, cleanup wrappers, allocator mechanics, unwind wrappers, and owner destructor/free sites. |
| `26-31` | `disasm` | Targeted revision recheck: bounded disassembly of three startup wrappers and three cleanup wrappers, confirming constants, pool bases, `PoolAllocator` constructor calls, and cleanup jumps. |

No broad list/search/disassembly/callgraph/type/batch-analysis calls were used.

## Current MCP Facts

### Executable Aggregates

`lookup_funcs` command `6` confirms the broad aggregates are not safe single C++ bodies:

| Address | Current function result |
| --- | --- |
| `0x005380b0` | function `sub_5380B0`, size `0x46` |
| `0x00538100` | function `sub_538100`, size `0x1f8` |
| `0x00538300` | function `sub_538300`, size `0x15f` |
| `0x00538460` | function `sub_538460`, size `0x15c` |
| `0x005385c0` | function `sub_5385C0`, size `0x7` |
| `0x005385d0` | not a function |
| `0x005385f0` | not a function |
| `0x00538600` | function `sub_538600`, size `0x92` |
| `0x005386a0` | function `sub_5386A0`, size `0x1d` |
| `0x005386c0` | function `sub_5386C0`, size `0xe3` |
| `0x00467b30` | function `sub_467B30`, size `0x711` |
| `0x00468250` | not a function |
| `0x004682c0` | function `sub_4682C0`, size `0x1dc` |
| `0x00468e00` | not a function |
| `0x00468f80` | function `sub_468F80`, size `0xce` |

This confirms [UID:0001D8] and [UID:0000YZ] are mixed method/raw/glue aggregates. Formal code should be added only after exact child splits, not as monolithic blocks.

### HitBar Vtable Data

`entity_query` command `9` reports names inside and around [UID:000353]:

| Address | Name |
| --- | --- |
| `0x00620738` | `??_7HitBarObjectPane@@6B@` |
| `0x006207b0` | `??_7HitBarObjectPane@@6B@_0` |
| `0x006207e0` | `??_7HitBarObjectPane@@6B@_1` |
| `0x006207ec` | successor `??_7DamageNumberObjectPane@@6B@` |

`xrefs_to` command `7` confirms primary and adjusted vtable bases are referenced from the same HitBar constructor/destructor paths:

| Address | Xref summary |
| --- | --- |
| `0x00620738` | refs from `0x00538d93`, `0x00538e10`, `0x00538e40`, `0x0053d265` |
| `0x006207b0` | refs from `0x00538d99`, `0x00538e16`, `0x00538e46`, `0x0053d26b` |
| `0x006207e0` | refs from `0x00538da3`, `0x00538e20`, `0x00538e50`, `0x0053d275` |
| RTTI pointer dwords `0x00620734`, `0x006207ac`, `0x006207dc`, and successor `0x006207e8` | no direct xrefs expected for boundary locator dwords |

`get_bytes` command `8` reads exactly `0xb4` / 180 bytes for the range, matching the same three-view shape used by accepted siblings [UID:000350], [UID:000354], and [UID:000355].

### Resource Strings

`entity_query` command `9` and `get_bytes` command `8` confirm the string tail:

| Address | Name/literal | Xref |
| --- | --- | --- |
| `0x00620bc0` | `aDeadsignEpf` / UTF-16 `DEADSIGN.EPF` | `0x00539075` in `sub_539030` |
| `0x00620bdc` | `aD_3` / `%d` | `0x005392e3` in `sub_539230` |
| `0x00620be0` | `aDmgnumEpf` / UTF-16 `DMGNUM.EPF` | `0x00539551` in `sub_5394D0` |
| `0x00620bf8` | `aDmgnumPal` / UTF-16 `DMGNUM.PAL` | `0x00539563` in `sub_5394D0` |
| `0x00620c10` | start of numeric table, not string data | no xrefs in representative table-base check |

These are source literal references in HitBar/DamageNumber methods, not standalone handwritten raw `.rdata` blocks.

### Static Pool Storage

Initial `get_bytes` command `8` and revision `get_bytes` command `24` confirm all three current 40-byte pool storage items are zero-filled, not all-`ff` in the current IDB byte image:

| UID | Address | Current bytes | Xref count |
| --- | --- | --- | --- |
| [UID:0002WP] HitBar pool | `0x0069b934` | 40 zero bytes | 7 |
| [UID:0002WQ] DamageNumber pool | `0x0069b95c` | 40 zero bytes | 6 |
| [UID:0002WU] Balloon pool | `0x0069b9fc` | 40 zero bytes | 6 |

`disasm` commands `11-16` and revision commands `26-31` confirm startup and cleanup wrappers:

| Pool | Startup wrapper | Constants | Cleanup wrapper |
| --- | --- | --- | --- |
| Balloon | `0x0041a040` | `push 0x10`, `push 0x1e0`, `ecx = 0x0069b9fc` | `0x0060c320` forwards pool base to cleanup |
| DamageNumber | `0x0041a060` | `push 8`, `push 0x148`, `ecx = 0x0069b95c` | `0x0060c330` forwards pool base to cleanup |
| HitBar | `0x0041a0c0` | `push 4`, `push 0x138`, `ecx = 0x0069b934` | `0x0060c360` forwards pool base to cleanup |

`int_convert` command `17` verifies `0x28` / 40 bytes, `0x1e0` / 480 bytes, `0x148` / 328 bytes, `0x138` / 312 bytes, and `0x10` / 16 chunks.

Revision `xrefs_to` command `23` rechecked the pool bases and allocator mechanics:

| Target | Direct pool-base refs |
| --- | --- |
| [UID:0002WP] `0x0069b934` | 7 refs: static constructor `0x0041a0c0`, allocation paths `0x0050e4c0`, `0x0050e690`, `0x0050edd0`, unwind free `0x00514be0`, scalar destructor return `0x0053d240`, cleanup `0x0060c360`. |
| [UID:0002WQ] `0x0069b95c` | 6 refs: static constructor `0x0041a060`, allocation paths `0x0050ef00`, `0x00512960`, unwind free `0x00514b20`, scalar destructor return `0x0053d060`, cleanup `0x0060c330`. |
| [UID:0002WU] `0x0069b9fc` | 6 refs: static constructor `0x0041a040`, scalar destructor/free path `0x00468f80`, allocation paths `0x0050e100`, `0x00511710`, unwind free `0x00514ae0`, cleanup `0x0060c320`. |

The same revision xref call confirms shared allocator mechanics remain cross-cutting, not the source owner for concrete pool declarations: `0x004b13d0` has 19 static constructor callers, `0x004b1400` has 33 allocation callers, `0x004b14c0` has 30 free callers, and `0x004b1520` has 19 cleanup-wrapper callers.

Current [UID:0000TI] `PoolAllocatorStaticInstances` explicitly says exact pool-storage children carry reconstructable source declarations and records preferred descriptive names for these three pools: `g_hitBarObjectPanePool`, `g_damageNumberObjectPanePool`, and `g_balloonObjectPanePool`. [UID:0000MM] `PoolAllocator` owns allocator mechanics only and says concrete static pool globals should be declared beside their consuming modules. Therefore missing exact original spelling/linkage is not enough to justify comment-only markers here. The correct first-draft formal C++ for the three pool children is source-level `PoolAllocator` declarations in this `AttachedObjectPane.cpp` route, using the exact wrapper constants and best-inferred `g_*ObjectPanePool` names.

Generated-output expectation after accepted implementation and scoped validation: the three pool empty markers should be replaced by declaration lines, not comments, for example `static PoolAllocator g_hitBarObjectPanePool(0x138, 4);`, `static PoolAllocator g_damageNumberObjectPanePool(0x148, 8);`, and `static PoolAllocator g_balloonObjectPanePool(0x1e0, 0x10);`.

### ObjectOverlayFrameIndexTables

`get_bytes` command `8` confirms [UID:0003CC] is still the 84-byte table:

```text
0xf1, 0xf3, 0xf5, 0xf7, 0xf1, 0xf3, 0xf5
0x2f, 0x2e, 0x2d, 0x2c, 0x2f, 0x2e, 0x2d
0xe0, 0xe1, 0xe2, 0xe3, 0xe0, 0xe1, 0xe2
```

`xrefs_to` command `7` confirms representative table addresses `0x00620c10`, `0x00620c14`, `0x00620c2c`, `0x00620c48`, and `0x00620c60` have zero direct xrefs. `entity_query` command `9` confirms names around the range but none inside it; the next named item is `??_7OptionPane@@6B@` at `0x00620c74`. This matches the executed B001-057 ownership report and preserves the file-root/no-narrow-class caveat.

## Ownership And Source-Placement Analysis

### Accepted Source Root

[UID:0000HJ] `by-file/AttachedObjectPane.md` should remain the file root for `NexusTK/map/AttachedObjectPane.cpp`. It groups the base `AttachedObjectPane` lifecycle, Balloon, HitBar, DamageNumber, ObjectInfo, and file-local attached overlay data. Current file score `86/86` is sufficient for routing and should not change from this report.

### Ranked Direct-Owner Decisions

| Rank | Candidate | Decision |
| --- | --- | --- |
| 1 | Narrow class owners for class data: [UID:000067], [UID:00003F], [UID:00000U] | Accept for vtable/string/pool children where direct class evidence exists. The generated source still routes through [UID:0000HJ]. |
| 2 | File root [UID:0000HJ] | Accept for file-local no-xref table [UID:0003CC] and for mixed aggregate routing context. Reject as direct owner where a narrow class child is proven. |
| 3 | Broad aggregates [UID:0001D8], [UID:0000YZ] | Keep as audited containers until exact method child pages exist. Do not emit monolithic C++. |
| 4 | MapPane, BowGaugeObjectPane, ObjectPane, standalone file roots | Reject for current empty markers. MapPane is caller/consumer; BowGauge is a separate HUD gauge; ObjectPane is broader base context; standalone source files lack current source-tree evidence. |

## Heuristic / Inference Reanalysis

The generated output contains empty markers because several pages clear the numeric emitter gate while their formal C++ blocks remain blank. Numeric gate clearance is not enough to justify broad C++ insertion.

Accepted heuristic refinements:

- Exact vtable data should use formal marker-only source coverage when a class declaration and virtual methods regenerate the RTTI/vtable. This is already accepted for [UID:000350], [UID:000354], and [UID:000355]; [UID:000353] is the remaining sibling.
- Source string literals should not be emitted as raw `.rdata` arrays. Until exact method bodies are split/emitted, use formal coverage comments that name the owning class path and exact literals.
- Static `PoolAllocator` object storage is source-declared/generated-binary support. Current docs already assign concrete pool declarations to consuming modules and provide best-inferred `g_*ObjectPanePool` names; exact original spelling/linkage remains provisional but does not block first-draft declarations for these exact children.
- No-xref file-local table [UID:0003CC] should not become a handwritten table declaration without an original name or consumer. The accepted B001 evidence supports file-root ownership, but confidence for exact declaration spelling remains capped.
- Broad executable aggregates and class pages should not receive placeholder declarations or monolithic bodies simply to clear empty markers.

## Positive Evidence

- [UID:0000HJ] is the current source route for the attached overlay family and already emits four filled sibling entries.
- [UID:000353] has exact HitBar RTTI/vtable boundaries, names, and constructor/destructor xrefs, matching accepted sibling vtable patterns.
- [UID:0002YR] and [UID:0002YS] have exact literal boundaries and direct method xrefs to HitBar/DamageNumber code.
- [UID:0002WP], [UID:0002WQ], and [UID:0002WU] have exact 40-byte storage, exact startup/cleanup wrappers, exact block-size/chunk constants, direct allocation/free/destructor/static-cleanup xrefs, and current `PoolAllocatorStaticInstances` support for source-level `g_*ObjectPanePool` declarations.
- [UID:0003CC] has current bytes matching B001-057 and no direct xrefs/names, supporting file-root/no-standalone-declaration treatment.
- [UID:0000YZ] and [UID:0001D8] current MCP lookups show mixed functions and non-function islands, confirming aggregate C++ is unsafe.

## Negative Evidence

- No current evidence supports raw vtable/RTTI dword arrays in source for [UID:000353].
- No current evidence supports raw standalone `.rdata` string blocks for [UID:0002YR] or [UID:0002YS].
- Original pool variable spellings/linkage are not proven for [UID:0002WP], [UID:0002WQ], or [UID:0002WU]. That caps confidence and requires best-inferred names, but current PoolAllocator docs and exact owner evidence are strong enough for first-draft declarations rather than comment-only markers.
- No direct xrefs or names identify the original declaration for [UID:0003CC].
- No exact child pages exist yet for the individual [UID:0001D8] AttachedObjectPane methods/helpers.
- [UID:0000YZ] remains a mixed Balloon method island with raw no-xref helpers at `0x00468250` and `0x00468e00`, EH cleanup, adjustor thunks, and scalar-deleting destructor glue.
- Class pages still document field/name/body blockers; adding speculative class declarations would lower source quality.

## Score And Metadata Recommendations

Recommended target/file-root metadata:

| UID | Current | Recommended |
| --- | --- | --- |
| [UID:0000HJ] `AttachedObjectPane.md` | `86/86`, `CANONICAL_OWNER:FILE` | Keep `86/86`, keep file root. Add evidence/changelog notes only if implementation applies first-batch support docs. |

Recommended first-batch child metadata:

| UID | Current | Recommended |
| --- | --- | --- |
| [UID:000353] | `86/89`, owner/emitter `000067` | `88/91`, same owner/emitter, formal no-raw-vtable marker. |
| [UID:0002YR] | `85/90`, owner/emitter `000067` | `86/91`, same owner/emitter, formal resource-literal marker. |
| [UID:0002YS] | `86/92`, owner/emitter `00003F` | `87/92`, same owner/emitter, formal resource-literal marker and stale summary repair. |
| [UID:0002WP] | `86/92`, owner/emitter `000067` | `88/93`, same owner/emitter, formal `g_hitBarObjectPanePool` declaration and current-zero byte correction. |
| [UID:0002WQ] | `85/91`, owner/emitter `00003F` | `88/93`, same owner/emitter, formal `g_damageNumberObjectPanePool` declaration and current-zero byte correction. |
| [UID:0002WU] | `85/91`, owner/emitter `00000U` | `88/93`, same owner/emitter, formal `g_balloonObjectPanePool` declaration, current-zero byte correction, and stale summary repair. |
| [UID:0003CC] | `86/91`, owner/emitter `0000HJ` | keep `86/91`, same owner/emitter, formal no-standalone-table marker. |

Deferred marker metadata should remain unchanged until a split/declaration callback addresses the named blockers.

## Exact Formal C++ Recommendations

### [UID:000353] `HitBarObjectPaneVtableData`

Insert between the target's multiline `RECONSTRUCTION_CPP CODE:BEGIN` and `END` lines:

```cpp
// Compiler-emitted RTTI/vtable data for HitBarObjectPane is regenerated from
// [UID:000067] HitBarObjectPane class declarations, virtual method definitions,
// destructor wrappers, and the [UID:0000HJ] AttachedObjectPane.cpp source module.
// No raw vtable or RTTI dword tables are hand-authored for this .rdata range.
```

### [UID:0002YR] `DeadSignResourceString`

```cpp
// HitBarObjectPane source references L"DEADSIGN.EPF" from its dead-sign render path.
// No standalone raw .rdata string block is hand-authored for [UID:0002YR].
```

### [UID:0002YS] `DamageNumberResourceStrings`

```cpp
// DamageNumberObjectPane source references "%d", L"DMGNUM.EPF", and L"DMGNUM.PAL".
// No standalone raw .rdata string block is hand-authored for [UID:0002YS].
```

### [UID:0002WP] `HitBarObjectPanePoolStaticStorage`

```cpp
static PoolAllocator g_hitBarObjectPanePool(0x138, 4);
```

### [UID:0002WQ] `DamageNumberObjectPanePoolStaticStorage`

```cpp
static PoolAllocator g_damageNumberObjectPanePool(0x148, 8);
```

### [UID:0002WU] `BalloonObjectPanePoolStaticStorage`

```cpp
static PoolAllocator g_balloonObjectPanePool(0x1e0, 0x10);
```

These declarations intentionally use exact numeric constructor constants from the startup wrappers instead of `sizeof(Class)` because the owning class formal declarations are still deferred. A later final-source pass may replace the numeric block-size arguments with `sizeof(HitBarObjectPane)`, `sizeof(DamageNumberObjectPane)`, or `sizeof(BalloonObjectPane)` only after the class layouts are complete and the generated output remains equivalent.

### [UID:0003CC] `ObjectOverlayFrameIndexTables`

```cpp
// ObjectOverlayFrameIndexTables is documented as file-local attached-overlay constant data.
// Current IDA evidence has no direct xrefs or original declaration name for [UID:0003CC],
// so no standalone source table is emitted from this marker.
```

## Open Questions And Closure

| Question | Current answer |
| --- | --- |
| Is [UID:0000HJ] the right file root? | Yes. Keep `NexusTK/map/AttachedObjectPane.cpp` as source route. |
| Should broad aggregates emit first-draft C++ now? | No. [UID:0000YZ] and [UID:0001D8] require exact method/raw/helper child splits first. |
| Should class pages receive speculative shells? | No. Current blockers are explicit and not solved by marker-only comments. |
| Should [UID:000353] mirror accepted vtable marker handling? | Yes. It is the only remaining sibling exact vtable child in this generated file without a formal marker. |
| Should pool storage use raw byte arrays or comment-only markers? | No. Current evidence points to class/module-owned static `PoolAllocator` declarations. Use first-draft `g_*ObjectPanePool` declarations with exact wrapper constants; do not emit raw bytes and do not leave these as comment-only markers. |
| Are old all-`ff` pool byte notes current? | No. Current MCP reads all three 40-byte blocks as zero-filled. Support docs should be corrected during implementation. |
| Should [UID:0003CC] become a narrow class child? | No. B001-057 and current MCP retain file-root ownership with no direct xrefs/names. |

## Claim And Incorporation Ledger

| Claim / target | Source evidence | Proposed action | Verification |
| --- | --- | --- | --- |
| [UID:0000HJ] remains source file root for attached overlays | Current by-file page, generated path, class/memory routes, MCP caller/data evidence | `already-present` plus support sync applied | verified: `by-file/AttachedObjectPane.md` updated in Proposed Contents, File-Root State, and Changes; validator `000000003314` at `2026-07-01T04:58:54-04:00`, exit 0, `ok: 1`. |
| Generated file originally had 14 empty markers and 4 filled markers | `auto-generated/NexusTK/map/AttachedObjectPane.cpp` read-only inventory | `applied` first-batch fill | verified: generated header `validator-command-id: 000000003317`, `validator-refreshed-at: 2026-07-01T04:59:24-04:00`; first-batch seven are no longer empty and the intentionally deferred seven remain empty. |
| [UID:000353] should receive no-raw-vtable marker | Current MCP commands `7-9`, by-memory page, accepted UID000350/354/355 reports | `applied` | verified: `by-memory/0x00620734-0x006207e8.HitBarObjectPaneVtableData.md` now `88/91` with formal no-raw-vtable marker; validator `000000003307` at `2026-07-01T04:57:42-04:00`, exit 0, `ok: 1`; generated UID000353 marker is filled. |
| [UID:0002YR] should receive no-raw string-literal marker | Current MCP commands `7-9`, by-memory page | `applied` | verified: `by-memory/0x00620bc0-0x00620bdc.DeadSignResourceString.md` now `86/91` with `DEADSIGN.EPF` source-literal marker; validator `000000003308` at `2026-07-01T04:57:52-04:00`, exit 0, `ok: 1`; generated UID0002YR marker is filled. |
| [UID:0002YS] should receive no-raw string-literal marker and stale summary repair | Current MCP commands `7-9`, by-memory page with stale summary | `applied` | verified: `by-memory/0x00620bdc-0x00620c10.DamageNumberResourceStrings.md` now `87/92` with `%d`/`DMGNUM.EPF`/`DMGNUM.PAL` source-literal marker and repaired summary; validator `000000003309` at `2026-07-01T04:58:02-04:00`, exit 0, `ok: 1`; generated UID0002YS marker is filled. |
| [UID:0002WP] should receive `static PoolAllocator g_hitBarObjectPanePool(0x138, 4);` and current zero-byte correction | Current MCP commands `7-8`, `10`, `13`, `16`, `17`, revision commands `23-25`, `28`, `31`, current `PoolAllocatorStaticInstances` docs | `applied` | verified: `by-memory/0x0069b934-0x0069b95c.HitBarObjectPanePoolStaticStorage.md` now `88/93` with formal declaration and current zero-filled byte evidence; validator `000000003310` at `2026-07-01T04:58:12-04:00`, exit 0, `ok: 1`; generated UID0002WP emits the declaration. |
| [UID:0002WQ] should receive `static PoolAllocator g_damageNumberObjectPanePool(0x148, 8);` and current zero-byte correction | Current MCP commands `7-8`, `10`, `12`, `15`, `17`, revision commands `23-25`, `27`, `30`, current `PoolAllocatorStaticInstances` docs | `applied` | verified: `by-memory/0x0069b95c-0x0069b984.DamageNumberObjectPanePoolStaticStorage.md` now `88/93` with formal declaration and current zero-filled byte evidence; validator `000000003311` at `2026-07-01T04:58:23-04:00`, exit 0, `ok: 1`; generated UID0002WQ emits the declaration. |
| [UID:0002WU] should receive `static PoolAllocator g_balloonObjectPanePool(0x1e0, 0x10);`, current zero-byte correction, and stale summary repair | Current MCP commands `7-8`, `10-11`, `14`, `17`, revision commands `23-26`, `29`, current `PoolAllocatorStaticInstances` docs | `applied` | verified: `by-memory/0x0069b9fc-0x0069ba24.BalloonObjectPanePoolStaticStorage.md` now `88/93` with formal declaration, current zero-filled byte evidence, and repaired summary; validator `000000003312` at `2026-07-01T04:58:33-04:00`, exit 0, `ok: 1`; generated UID0002WU emits the declaration. |
| [UID:0003CC] should receive no-standalone-table marker | Executed B001-057, current MCP commands `7-9`, by-memory page | `applied` | verified: `by-memory/0x00620c10-0x00620c64.ObjectOverlayFrameIndexTables.md` now has formal no-standalone-table marker preserving no-xref/no-name caveat; validator `000000003313` at `2026-07-01T04:58:44-04:00`, exit 0, `ok: 1`; generated UID0003CC marker is filled. |
| [UID:0000YZ] should stay aggregate C++ blank | Executed B005/B008, current MCP command `6`, current by-memory page | `excluded-with-reason` | verified: not edited in this callback; generated UID0000YZ remains one of seven intentional empty markers because exact method/raw helper splits are still required. |
| [UID:0001D8] should stay aggregate C++ blank until exact child splits | Current by-memory page, current MCP command `6` | `excluded-with-reason` | verified: not edited in this callback; generated UID0001D8 remains one of seven intentional empty markers because the executable aggregate still needs exact child splits. |
| [UID:00000M], [UID:00000U], [UID:00003F], [UID:000067], [UID:00009P] class pages remain declaration-deferred | Current class pages and named field/body blockers | `already-present` / `excluded-with-reason`; support notes applied where in callback scope | verified: formal class C++ blocks remain blank; support docs updated for UID00000U/00003F/000067 only. Validators: UID000067 `000000003315`, UID00003F `000000003316`, UID00000U `000000003317`, all exit 0, `ok: 1`. UID00000M and UID00009P not edited because outside accepted first batch. |
| Old "parent blank/below gate" summaries in [UID:0002YS] and [UID:0002WU] are stale | Current metadata shows owner/emitter set and parents gate-clear | `applied` | verified: UID0002YS summary now routes to UID00003F source literals; UID0002WU summary now routes to UID00000U formal pool declaration. |
| Old all-`ff` pool byte claims are stale for current IDB image | Current MCP `get_bytes` command `8` and revision command `24` read zero-filled pools | `applied` | verified: UID0002WP/0002WQ/0002WU storage tables and evidence now record current zero-filled 40-byte storage; old all-`ff` wording remains only as historical dated evidence where applicable. |
| Original pool names are not proven but best-inferred `g_*ObjectPanePool` names are sufficient for first-draft source | [UID:0000TI] descriptive global-name table and class-specific xrefs/wrappers | `applied` with confidence cap | verified: three pool children emit best-inferred `g_*ObjectPanePool` declarations, retain numeric wrapper constants, and note exact original spelling/linkage remains inferred. |

## File-Specific Implementation Tracking Checklist

Recommended implementation callback scope:

- [x] Lease and edit [UID:000353] `by-memory/0x00620734-0x006207e8.HitBarObjectPaneVtableData.md`; add formal no-raw-vtable marker, raise to `88/91`, and update summary/evidence with current MCP session `supervisor_resume_20260629`. Proof: validator `000000003307`, `2026-07-01T04:57:42-04:00`, exit 0, `ok: 1`.
- [x] Lease and edit [UID:0002YR] `by-memory/0x00620bc0-0x00620bdc.DeadSignResourceString.md`; add formal resource-literal marker, optionally raise to `86/91`, and preserve `0x00539075` HitBar xref. Proof: validator `000000003308`, `2026-07-01T04:57:52-04:00`, exit 0, `ok: 1`.
- [x] Lease and edit [UID:0002YS] `by-memory/0x00620bdc-0x00620c10.DamageNumberResourceStrings.md`; add formal resource-literal marker, optionally raise to `87/92`, repair stale "parent blank/below gate" summary, and preserve `%d`/`DMGNUM.EPF`/`DMGNUM.PAL` xrefs. Proof: validator `000000003309`, `2026-07-01T04:58:02-04:00`, exit 0, `ok: 1`.
- [x] Lease and edit [UID:0002WP] `by-memory/0x0069b934-0x0069b95c.HitBarObjectPanePoolStaticStorage.md`; insert formal `static PoolAllocator g_hitBarObjectPanePool(0x138, 4);`, raise to `88/93`, record current zero-filled bytes, preserve wrapper/xref evidence, and historicalize older all-`ff` wording. Proof: validator `000000003310`, `2026-07-01T04:58:12-04:00`, exit 0, `ok: 1`.
- [x] Lease and edit [UID:0002WQ] `by-memory/0x0069b95c-0x0069b984.DamageNumberObjectPanePoolStaticStorage.md`; insert formal `static PoolAllocator g_damageNumberObjectPanePool(0x148, 8);`, raise to `88/93`, record current zero-filled bytes, preserve wrapper/xref evidence, and historicalize older all-`ff` wording. Proof: validator `000000003311`, `2026-07-01T04:58:23-04:00`, exit 0, `ok: 1`.
- [x] Lease and edit [UID:0002WU] `by-memory/0x0069b9fc-0x0069ba24.BalloonObjectPanePoolStaticStorage.md`; insert formal `static PoolAllocator g_balloonObjectPanePool(0x1e0, 0x10);`, raise to `88/93`, record current zero-filled bytes, preserve wrapper/xref evidence, and repair stale summary/below-gate wording. Proof: validator `000000003312`, `2026-07-01T04:58:33-04:00`, exit 0, `ok: 1`.
- [x] Lease and edit [UID:0003CC] `by-memory/0x00620c10-0x00620c64.ObjectOverlayFrameIndexTables.md`; add formal no-standalone-table marker while preserving file-root ownership and no-xref/no-name caveat. Proof: validator `000000003313`, `2026-07-01T04:58:44-04:00`, exit 0, `ok: 1`.
- [x] Lease and edit [UID:0000HJ] `by-file/AttachedObjectPane.md`; update Proposed Contents / File-Root State / Changes to list the newly covered first-batch markers, the three `g_*ObjectPanePool` declarations, and current pool zero-byte correction. Do not add final file-root C++. Proof: validator `000000003314`, `2026-07-01T04:58:54-04:00`, exit 0, `ok: 1`.
- [x] Lease and edit [UID:000067] `by-class/HitBarObjectPane.md`; update evidence notes for [UID:000353], [UID:0002YR], and [UID:0002WP] declaration coverage. Also clean stale generated/Wave wording if encountered in the touched section. Proof: validator `000000003315`, `2026-07-01T04:59:04-04:00`, exit 0, `ok: 1`; stale Wave wording converted to historical context.
- [x] Lease and edit [UID:00003F] `by-class/DamageNumberObjectPane.md`; update reconstruction/evidence notes for [UID:0002YS] and [UID:0002WQ] declaration coverage. Proof: validator `000000003316`, `2026-07-01T04:59:14-04:00`, exit 0, `ok: 1`.
- [x] Lease and edit [UID:00000U] `by-class/BalloonObjectPane.md`; update static pool notes for [UID:0002WU] declaration coverage and current zero-filled byte state. Proof: validator `000000003317`, `2026-07-01T04:59:24-04:00`, exit 0, `ok: 1`.
- [x] Validate every edited file with scoped `tools/validator.py --mode file --file ... --apply --queue-timeout 240 --wait-generated`. Proof: command IDs `000000003307` through `000000003317`, all exit 0, all `ok: 1`, all `generated_refresh: completed`.
- [x] Confirm generated `auto-generated/NexusTK/map/AttachedObjectPane.cpp` refresh removes the seven first-batch empty markers or report generated-refresh state exactly; expected new pool output is the three `static PoolAllocator g_*ObjectPanePool(...)` declarations, not comment-only markers. Proof: generated header `validator-command-id: 000000003317`, `validator-refreshed-at: 2026-07-01T04:59:24-04:00`; UID0002WP/0002WQ/0002WU emit the three `static PoolAllocator` declarations, and UID000353/0002YR/0002YS/0003CC are filled marker comments.

Deferred / excluded from first batch:

- [x] Do not edit [UID:00000M] `by-class/AttachedObjectPane.md` in the first batch unless the callback explicitly requests a class declaration pass. Status: excluded-with-reason; not in accepted edit list.
- [x] Do not edit [UID:00000U], [UID:00003F], [UID:000067], or [UID:00009P] formal class C++ blocks beyond support-note updates unless the callback explicitly accepts declaration shells. Status: support notes applied to UID00000U/00003F/000067 only; formal class C++ remains blank; UID00009P not edited.
- [x] Do not populate [UID:0000YZ] aggregate C++; split exact Balloon method child pages first if implementation scope changes. Status: excluded-with-reason; not edited and generated marker remains intentionally empty.
- [x] Do not populate [UID:0001D8] aggregate C++; split exact AttachedObjectPane method/helper child pages first if implementation scope changes. Status: excluded-with-reason; not edited and generated marker remains intentionally empty.
- [x] Do not edit coverage reports, generated files, validator state, queue files, archives, supervisor ledgers, or IDA DB. Status: complied manually; validator-owned generated reports/C++ refreshed through scoped validator runs only.

## Implementation Callback Status

Implementation callback completed on 2026-07-01. Leases were used for the 11 accepted by-* files and this report, validators were run with `--wait-generated`, and generated `auto-generated/NexusTK/map/AttachedObjectPane.cpp` refreshed under validator command `000000003317`. Remaining unchecked blockers: none for the accepted first batch; deferred broad class/aggregate emitters remain intentionally empty pending separate split/declaration callbacks.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B009","command_id":"000000004165","destination_path":"executed-b-agent-research/B009/0000HJ-AttachedObjectPane-empty-emitter-family-source-quality.md","details":"legacy registry reconstruction","event":"executed","source_path":"tools/leaser/Agents/Agent-B009/research/0000HJ-AttachedObjectPane-empty-emitter-family-source-quality.md","timestamp":"2026-07-01T05:06:08","uid":"0000HJ"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
