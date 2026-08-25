** TARGET-REPORT-UID:0002UW **
** AUTHOR-AGENT-ID:B004 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# UID0002UW PrettyButtonControlPaneVtableData Source-Quality Report

** TARGET: by-memory/0x006222d4-0x00622378.PrettyButtonControlPaneVtableData.md **

## Finalized Report / Current Recommendation

UID0002UW is a reconstructable, class-owned, compiler-emitted RTTI/vtable data child for `PrettyButtonControlPane`. Keep the target under [UID:0000AR] `by-class/PrettyButtonControlPane.md`, keep [UID:0000MP] `by-file/PrettyButtonControlPane.md` as the source-file route, keep `RECONSTRUCTABLE:TRUE`, keep `EMITTER_UIDS:0000AR`, and keep the formal C++ block blank.

Implementation callback status: applied on 2026-07-08. UID0002UW now carries the accepted metadata and no-code disposition:

| Field | Current | Recommended | Reason |
| --- | --- | --- | --- |
| `COMPLETION` | `88` | applied | Current MCP recheck proves the exact `.rdata` range, names, dwords, store xrefs, slot targets, and next boundary; all source-bearing class1 method children are now accepted and generated output is fresh. |
| `CONFIDENCE` | `93` | applied | Current live database `b007_uid0002oc_20260708` reconfirms the binary facts. Confidence stays below final audit because exact original class declaration spelling, RTTI declaration form, and some inherited parameter names remain inferred. |
| `CANONICAL_OWNER` | `0000AR` | `0000AR` | The class declaration owns the vtable/RTTI regeneration. |
| `RECONSTRUCTABLE` | `TRUE` | `TRUE` | Reconstructed by source declarations and virtual method layout, not by hand-emitted data bytes. |
| `EMITTER_UIDS` | `0000AR` | `0000AR` | The class emitter is the correct compiler-output route. |
| `RECONSTRUCTION_CPP` | blank | blank | The generated C++ already uses an empty marker for this vtable data child; adding raw data C++ would duplicate compiler ABI output. |

## Supporting Research

Initial research was performed as report-only work. After Gate 1 passed, the implementation callback edited the accepted target/support by-* docs under short leases, ran scoped file validators, and updated this report artifact. I did not hand-edit generated files, coverage reports, supervisor ledgers, validator state, queues, locks, archives, lifecycle headers/footers, or unrelated docs. I did not run `execute_report`, dry-run/probing execute variants, registry lifecycle/archive commands, manual report moves, `idb_open`, or MCP/IDA process lifecycle commands.

Read-only sources checked:

| Source | Role |
| --- | --- |
| `by-memory/0x006222d4-0x00622378.PrettyButtonControlPaneVtableData.md` | Target metadata, range, view table, score rationale, and stale parent-score wording. |
| `by-class/PrettyButtonControlPane.md` | Direct class owner, accepted method children, stale file-score support note. |
| `by-file/PrettyButtonControlPane.md` | Source-file route, executable split, vtable child integration, current `89/91` file status. |
| `by-memory/0x006222d4-0x006224c0.ButtonPrimePursuitReadOnlyData.md` | Mixed `.rdata` aggregate and neighboring child inventory. |
| `by-memory/0x00622378-0x0062241c.PrettyButtonControlPane2VtableData.md` | Upper boundary comparison for `PrettyButtonControlPane2`. |
| `auto-generated/NexusTK/ui/controls/PrettyButtonControlPane.cpp` | Fresh generated output and expected empty emitter marker for UID0002UW. |
| `auto-generated/-ag-research-tracker.md` | Read-only queue evidence that UID0002UW had zero direct report coverage before this report. |
| Executed B-agent reports for UID0004E3, UID0004E4, UID0004E5, UID0004E6, UID0004E7, UID0004E8, UID0004E9, and UID0001F9 | Accepted source-quality support for constructor, destructor, state, callback, visual-state, paint, click, and file-family placement. |

## Target

- UID: `0002UW`.
- Path: `by-memory/0x006222d4-0x00622378.PrettyButtonControlPaneVtableData.md`.
- Kind: exact `.rdata` RTTI/vtable-data child.
- Half-open range: `0x006222d4-0x00622378`.
- Current owner/emitter: [UID:0000AR] `PrettyButtonControlPane`.
- Current source route: [UID:0000MP] `PrettyButtonControlPane`.
- Containing aggregate: [UID:000267] `0x006222d4-0x006224c0.ButtonPrimePursuitReadOnlyData`.

## Current Target State

The target now records `88/93`, `CANONICAL_OWNER:0000AR`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000AR`, blank `RECONSTRUCTION_CPP`, three vtable views, constructor/destructor/scalar-wrapper store xrefs, key virtual slots, current B004 MCP evidence, queue-resolution text, and the `0x00622378` next-class boundary.

The implementation callback removed the stale current wording that said the direct parent was raised to `85/86`, replaced "Autogen parent" body wording with canonical owner/emitter vocabulary, and updated the class support note that still said the file parent was `86/88`. Current docs show both direct class [UID:0000AR] and file [UID:0000MP] at `89/91`.

## Heuristic / Inference Reanalysis And Validation

The initial heuristic was that a reconstructable by-memory vtable target with zero direct report coverage might hide a missing source owner, missing C++ declaration, or stale no-code proof. The current audit resolves that:

| Heuristic Concern | Result |
| --- | --- |
| Zero direct B-report coverage | True in generated tracker before this report, but it means "no direct B report yet", not "unknown owner". Tracker row: UID0002UW, `85/91`, grade `88.0`, reconstructable `true`, direct report count `0`. |
| Possible no-owner or aggregate-owned data | Rejected. The exact child is class-owned by [UID:0000AR]; [UID:000267] is only the mixed non-emitting aggregate. |
| Possible need for formal C++ data bytes | Rejected. The vtable and RTTI bytes are compiler ABI output from the class declaration and virtual method list. The fresh generated file intentionally emits only an empty marker for UID0002UW. |
| Possible stale slot or xref facts | Rechecked through current MCP database `b007_uid0002oc_20260708`. Store xrefs, slot dwords, function lookups, and neighboring labels all match or improve the target. |
| Possible split/range issue | Rejected. `0x006222d4` is the primary RTTI locator for this class, and `0x00622378` starts the next class2 RTTI locator. |

## Evidence Standards Used

- Prefer current live IDA MCP facts for binary claims.
- Treat generated output as evidence of current validator/emitter behavior, not as a source file to edit by hand.
- Keep compiler-generated vtable/RTTI pages blank in formal C++ unless there is strong evidence for a source-authored data definition.
- Preserve all accepted source-bearing child reports without pruning details.
- Apply score-blocker guidance by resolving the "not-covered" queue reason with this report and by replacing stale blocker language with exact recommendations.

## Evidence Checked

### Current MCP Session

| Tool / Command | Metadata | Result |
| --- | --- | --- |
| JSON-RPC `idb_list` | command id `10`; active database requested/observed as `b007_uid0002oc_20260708` | Active session `b007_uid0002oc_20260708`, input path `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, worker pid `7776`. |
| JSON-RPC `server_health` | command id `11`; database `b007_uid0002oc_20260708` | `status: ok`, module `NexusTK.exe`, `auto_analysis_ready:true`, `hexrays_ready:true`, strings cache ready. |
| JSON-RPC `lookup_funcs` | command id `14` | Confirmed key slot target functions and non-modeled destructor interior addresses. |
| JSON-RPC `entity_query` | command id `16` | Confirmed local symbols at `0x006222d8`, `0x00622340`, and `0x00622370`. |
| JSON-RPC `get_bytes` | command id `17` | Dumped all 164 bytes for `0x006222d4-0x00622378`. |
| JSON-RPC `get_int` | command id `18` | Confirmed dwords for RTTI locators, key slot pointers, and next boundary. |
| JSON-RPC `xrefs_to` | command ids `19`, `20`, `22` | Confirmed store xrefs to view bases, data xrefs from vtable slots to target functions, and no direct xrefs to selected slot addresses. |
| JSON-RPC `entity_query` nearby | command id `23` | Confirmed lower neighboring strings and upper `PrettyButtonControlPane2` / `PrimeNumberGenerator` labels. |
| JSON-RPC `lookup_funcs` nearby | command id `24` | Confirmed modeled function neighbors and non-function destructor interior addresses. |
| JSON-RPC `int_convert` | command id `25` | Verified decimal-to-hex conversions used for dword facts. |

### Generated Freshness

`auto-generated/NexusTK/ui/controls/PrettyButtonControlPane.cpp` was checked before and after implementation:

- Pre-callback reference state: `validator-command-id: 000000007832`, `validator-refreshed-at: 2026-07-07T03:37:36-04:00`, `validator-refresh-source: foreground-generated-refresh`, UID0002UW marker `Completion:85 | Confidence:91 | Empty Emitter Marker`.
- Post-callback generated state: `validator-command-id: 000000007969`, `validator-refreshed-at: 2026-07-08T16:06:18-04:00`, `validator-refresh-source: deferred-generated-refresh`, UID0002UW marker `Completion:88 | Confidence:93 | Empty Emitter Marker`.
- It emits source-bearing UID0004E3, UID0004E4, UID0004E5, UID0004E6, UID0004E7, UID0004E8, and UID0004E9 bodies.
- It emits a comment-only scalar deleting destructor marker for UID0004EM.
- It emits UID0002UW only as the expected empty emitter marker; no generated source body or hand-authored data block is expected for this compiler-emitted RTTI/vtable child.

## Claim And Incorporation Ledger

| Claim ID | Claim | Confidence | Evidence | Destination doc/section | Action | Verification state |
| --- | --- | --- | --- | --- | --- | --- |
| B004-2UW-C01 | UID0002UW covers the exact half-open range `0x006222d4-0x00622378`. | Very high | Current MCP `get_bytes` command id `17`; nearby `entity_query` command id `23`; target page range. | `by-memory/0x006222d4-0x00622378.PrettyButtonControlPaneVtableData.md` `## Range`, `## IDA Evidence`, `## Score And Assignment Rationale` | incorporate | applied |
| B004-2UW-C02 | The view bases are `0x006222d8`, `0x00622340`, and `0x00622370`. | Very high | Current MCP `entity_query` command id `16`; target page view table. | `by-memory/0x006222d4-0x00622378.PrettyButtonControlPaneVtableData.md` `## Vtable Views`, `## IDA Evidence`; `by-file/PrettyButtonControlPane.md` `## Evidence Notes` | incorporate | applied |
| B004-2UW-C03 | Store xrefs to the three view bases are constructor/destructor/scalar-wrapper stores at `0x54b636`, `0x54b6b9`, `0x54bc4c`; `0x54b63c`, `0x54b6bf`, `0x54bc52`; and `0x54b646`, `0x54b6c9`, `0x54bc5c`. | Very high | Current MCP `xrefs_to` command id `19`; accepted UID0004E3 and UID0004E4 reports. | `by-memory/0x006222d4-0x00622378.PrettyButtonControlPaneVtableData.md` `## Vtable Views`, `## IDA Evidence`; `by-class/PrettyButtonControlPane.md` `## Evidence Notes`; `by-file/PrettyButtonControlPane.md` `## Evidence Notes` | incorporate | applied |
| B004-2UW-C04 | Key slot targets are scalar deleting destructor `0x0054bc40`, OnPaint `0x0054b7c0`, SetVisualState `0x0054b750`, secondary thunk `0x0054bb9f`, tertiary thunk `0x0054bbaa`, and OnClick `0x0054b880`. | Very high | Current MCP `get_int` command id `18`; `lookup_funcs` command id `14`; `xrefs_to` command id `20`. | `by-memory/0x006222d4-0x00622378.PrettyButtonControlPaneVtableData.md` `## Key Slot Evidence`, `## IDA Evidence` | incorporate | applied |
| B004-2UW-C05 | No direct xrefs target the OnPaint, SetVisualState, or OnClick slot addresses themselves; reachability is through vtable data. | Very high | Current MCP `xrefs_to` command id `22`; executed UID0004E7, UID0004E8, and UID0004E9 reports. | `by-memory/0x006222d4-0x00622378.PrettyButtonControlPaneVtableData.md` `## IDA Evidence`; `by-class/PrettyButtonControlPane.md` `## Evidence Notes`; `by-file/PrettyButtonControlPane.md` `## Evidence Notes` | incorporate | applied |
| B004-2UW-C06 | `0x006222d4`, `0x0062233c`, and `0x0062236c` are RTTI locator dwords with no direct xrefs; entity names label the vtable bases. | Very high | Current MCP `get_int` command id `18`; `xrefs_to` command id `19`; `entity_query` command id `16`. | `by-memory/0x006222d4-0x00622378.PrettyButtonControlPaneVtableData.md` `## Summary`, `## IDA Evidence`, `## Score And Assignment Rationale` | incorporate | applied |
| B004-2UW-C07 | `0x00622378` starts `PrettyButtonControlPane2` RTTI, so the target should not absorb class2 data. | Very high | Current MCP `get_int` command id `18`; nearby `entity_query` command id `23`; sibling UID0002UX page. | `by-memory/0x006222d4-0x00622378.PrettyButtonControlPaneVtableData.md` `## Summary`, `## Vtable Views`, `## IDA Evidence`; `by-file/PrettyButtonControlPane.md` `## Evidence Notes`; `by-memory/0x006222d4-0x006224c0.ButtonPrimePursuitReadOnlyData.md` `## Evidence Notes` | incorporate | applied |
| B004-2UW-C08 | The correct owner/emitter remains [UID:0000AR] `PrettyButtonControlPane`; [UID:0000MP] is the broader file route. | High | Target header, class/file headers, generated C++ header. | `by-memory/0x006222d4-0x00622378.PrettyButtonControlPaneVtableData.md` metadata header, `## Range`, `## Score And Assignment Rationale`; `by-class/PrettyButtonControlPane.md` `## Evidence Notes`; `by-file/PrettyButtonControlPane.md` `## Evidence Notes` | incorporate | applied |
| B004-2UW-C09 | Formal C++ should remain blank for UID0002UW. | High | Generated empty marker in validator command `000000007832`; compiler-generated RTTI/vtable nature. | `by-memory/0x006222d4-0x00622378.PrettyButtonControlPaneVtableData.md` formal `RECONSTRUCTION_CPP CODE` header/block, `## Reconstruction Notes`; generated freshness note in this report `## Validator Results` | incorporate | applied |
| B004-2UW-C10 | Recommended score is `88/93`. | High | Current MCP recheck, accepted child reports, generated freshness, remaining inference caps. | `by-memory/0x006222d4-0x00622378.PrettyButtonControlPaneVtableData.md` metadata header, Item Summary, `## Score And Assignment Rationale`; generated freshness note in this report `## Evidence Checked` / `## Validator Results` | incorporate | applied |

## Positive Evidence Summary

- Current MCP is healthy and live for the supervisor-provided database `b007_uid0002oc_20260708`.
- The target range begins at the primary RTTI locator dword `0x006222d4` and includes exactly the primary, secondary, and tertiary `PrettyButtonControlPane` vtable views.
- The next dword at `0x00622378` begins `PrettyButtonControlPane2`, proving the upper boundary.
- All key virtual slot pointers resolve to the already documented PrettyButtonControlPane child methods or compiler thunks/wrappers.
- Constructor/destructor/scalar-wrapper paths store the three vtable base addresses at the expected object offsets.
- Direct class [UID:0000AR] and file [UID:0000MP] support pages are now both `89/91`.
- The generated file is current and already emits real source bodies for the source-bearing method children while treating UID0002UW as an empty emitter marker.

## IDA MCP Facts

### Names And Range

Current `entity_query` over `0x006222d4-0x00622378` returned:

| Address | Name |
| --- | --- |
| `0x006222d8` | `??_7PrettyButtonControlPane@@6B@` |
| `0x00622340` | `??_7PrettyButtonControlPane@@6B@_0` |
| `0x00622370` | `??_7PrettyButtonControlPane@@6B@_1` |

Nearby query returned lower `aPower` / `aWerEpf` strings, class2 labels at `0x0062237c`, `0x006223e4`, and `0x00622414`, and `PrimeNumberGenerator` at `0x00622420`. That confirms UID0002UW sits between previous Power read-only data and the `PrettyButtonControlPane2` sibling.

### Dwords

| Address | Current dword | Meaning |
| --- | --- | --- |
| `0x006222d4` | `0x0064e200` | Primary RTTI locator pointer. |
| `0x006222d8` | `0x0054bc40` | Primary scalar deleting destructor slot. |
| `0x0062231c` | `0x0054b7c0` | Primary OnPaint slot. |
| `0x00622320` | `0x0054b750` | Primary SetVisualState / SetState slot. |
| `0x0062233c` | `0x0064e264` | Secondary RTTI locator pointer. |
| `0x00622340` | `0x0054bb9f` | Secondary adjustor thunk slot. |
| `0x0062236c` | `0x0064e278` | Tertiary RTTI locator pointer. |
| `0x00622370` | `0x0054bbaa` | Tertiary adjustor thunk slot. |
| `0x00622374` | `0x0054b880` | Tertiary OnClick slot. |
| `0x00622378` | `0x0064e28c` | Next class2 RTTI locator pointer. |

### Raw Bytes

Current `get_bytes` command id `17` dumped 164 bytes from `0x006222d4`. The sequence decodes as little-endian dwords matching the target's vtable layout:

```text
0x006222d4: 00 e2 64 00 40 bc 54 00 10 4b 4f 00 c0 b6 41 00
0x006222e4: 20 8e 4b 00 80 d6 41 00 30 47 54 00 50 47 54 00
0x006222f4: a0 47 54 00 00 48 54 00 20 4a 54 00 80 4b 54 00
0x00622304: d0 4b 54 00 70 4c 54 00 b0 4c 54 00 e0 4c 54 00
0x00622314: 30 4d 54 00 70 4d 54 00 c0 b7 54 00 50 b7 54 00
0x00622324: b0 4b 49 00 d0 4b 49 00 00 4c 49 00 10 4c 49 00
0x00622334: 30 4c 49 00 f0 42 42 00 64 e2 64 00 9f bb 54 00
0x00622344: b0 4d 54 00 70 4f 49 00 b0 d6 41 00 e0 4d 54 00
0x00622354: f0 4d 54 00 00 4e 54 00 f0 89 4a 00 10 4e 54 00
0x00622364: 30 4e 54 00 70 4e 54 00 78 e2 64 00 aa bb 54 00
0x00622374: 80 b8 54 00
```

## Function / Child Inventory

| Function Address | MCP Name / State | Current Child Meaning |
| --- | --- | --- |
| `0x0054b5e0` | `sub_54B5E0`, size `0xc4` | Constructor, UID0004E3, stores all three class vtable views. |
| `0x0054b6b0` | not a modeled function | Ordinary destructor body interior, UID0004E4 raw body. |
| `0x0054b700` | `sub_54B700`, size `0x19` | SetSelected / state-byte virtual forwarder, UID0004E5. |
| `0x0054b720` | `sub_54B720`, size `0x24` | SetCallback, UID0004E6. |
| `0x0054b750` | `sub_54B750`, size `0x62` | SetVisualState / SetState, UID0004E7. |
| `0x0054b7c0` | `sub_54B7C0`, size `0xb9` | OnPaint, UID0004E8. |
| `0x0054b880` | `sub_54B880`, size `0x39` | OnClick, UID0004E9. |
| `0x0054bb9f` | `sub_54BB9F`, size `0xb` | Secondary adjustor thunk, UID0004EJ. |
| `0x0054bbaa` | `sub_54BBAA`, size `0xb` | Tertiary adjustor thunk, UID0004EK. |
| `0x0054bc40` | `sub_54BC40`, size `0x7d` | Scalar deleting destructor, UID0004EM. |

## Direct Xref / Caller Inventory

### Xrefs To Vtable View Bases

| Vtable Base | Current Xrefs | Meaning |
| --- | --- | --- |
| `0x006222d8` | `0x54b636` in constructor, `0x54b6b9` in raw destructor body, `0x54bc4c` in scalar wrapper | Primary view stores. |
| `0x00622340` | `0x54b63c` in constructor, `0x54b6bf` in raw destructor body, `0x54bc52` in scalar wrapper | Secondary view stores. |
| `0x00622370` | `0x54b646` in constructor, `0x54b6c9` in raw destructor body, `0x54bc5c` in scalar wrapper | Tertiary view stores. |

No xrefs were reported to the RTTI locator dwords `0x006222d4`, `0x0062233c`, or `0x0062236c`, which is expected for metadata records and does not weaken the owner/source placement.

### Xrefs To Slot Targets

| Target | Current Xrefs |
| --- | --- |
| `0x0054bc40` | code xrefs from `0x54bba5` and `0x54bbb0`; data xref from vtable slot `0x006222d8`. |
| `0x0054b7c0` | data xref from slot `0x0062231c`. |
| `0x0054b750` | data xref from slot `0x00622320`. |
| `0x0054bb9f` | data xref from slot `0x00622340`. |
| `0x0054bbaa` | data xref from slot `0x00622370`. |
| `0x0054b880` | data xref from slot `0x00622374`. |

MCP reported no xrefs to slot addresses `0x0062231c`, `0x00622320`, or `0x00622374` themselves, reinforcing that these method children are vtable-only reachable.

## Documentation Evidence And IDA Status

The target preserves the core vtable facts and was updated in place during the implementation callback with current-session evidence, stale wording fixes, queue-resolution wording, and the target-specific no-code proof.

The class page [UID:0000AR] is high-quality and includes all accepted class1 emitting children. The callback repaired the stale support score note that previously said [UID:0000MP] was `86/88`; the class support note now records the current file route as `89/91` and adds the B004 UID0002UW evidence note.

The file page [UID:0000MP] includes UID0002UW, UID0002UX, executable split inventory, source path, accepted class1/class2 methods, and a B004 current-session vtable-data evidence note for UID0002UW.

The aggregate page [UID:000267] is correctly non-reconstructable and mixed-owner. It should remain a broad map, not become the owner or emitter for UID0002UW.

## Ranked Ownership Analysis

| Rank | Candidate | Decision |
| --- | --- | --- |
| 1 | [UID:0000AR] `PrettyButtonControlPane` class | Best owner and current canonical owner. The class declaration and virtual method set cause compiler regeneration of this RTTI/vtable block. |
| 2 | [UID:0000MP] `PrettyButtonControlPane` file | Correct source-file route and broader emitter chain context, but not the direct canonical owner for the exact class vtable child. |
| 3 | [UID:000267] mixed `.rdata` aggregate | Rejected as owner. It spans multiple direct source parents and remains non-emitting. |
| 4 | [UID:0002UX] / [UID:0000AS] `PrettyButtonControlPane2` | Rejected. The next class begins at `0x00622378`; it is an adjacent sibling, not part of UID0002UW. |
| 5 | Power, PrimeNumberGenerator, PursuitMessageDialogPane neighbors | Rejected. Nearby labels prove adjacency only, not ownership. |
| 6 | Compiler/runtime/global owner | Rejected. The vtable bytes are compiler ABI output, but the source-level regeneration route is the class declaration, not a standalone runtime module. |

## Source Placement

Keep source placement under [UID:0000MP] `PrettyButtonControlPane.md`, currently projected as `NexusTK/ui/controls/`. UID0002UW itself should not emit hand-authored C++ into the generated file. The class declaration and source-bearing child methods are the real source placement; the vtable data page documents binary ABI layout and validates that generated compiler output should contain the corresponding RTTI/vtable records.

## Range / Split / Padding / Reclassification Analysis

No split or reclassification is recommended.

| Range / Address | Decision |
| --- | --- |
| `0x006222d4` | Include. Primary RTTI locator pointer for `PrettyButtonControlPane`. |
| `0x006222d8-0x00622338` | Include. Primary vtable view. |
| `0x0062233c` | Include. Secondary RTTI locator pointer. |
| `0x00622340-0x00622368` | Include. Secondary view. |
| `0x0062236c` | Include. Tertiary RTTI locator pointer. |
| `0x00622370-0x00622374` | Include. Tertiary view slots. |
| `0x00622378` | Exclude. Starts `PrettyButtonControlPane2` RTTI locator and sibling UID0002UX. |

There is no padding subrange to carve out inside UID0002UW. The dwords are contiguous RTTI/vtable metadata.

## Negative Evidence Summary

- No direct xrefs to the slot addresses themselves; method reachability is vtable-driven.
- No direct xrefs to the RTTI locator dwords; this is expected metadata behavior and does not justify removing them from the range.
- No current evidence for a handwritten source data definition for this block.
- No current evidence that UID000267, Power, class2, PrimeNumberGenerator, or PursuitMessageDialogPane should own any byte inside UID0002UW.
- No current evidence that this target should emit a C++ byte array, static pointer table, or manually named RTTI object.
- No current evidence that the formal C++ block should contain class declarations; class-level declaration work belongs on [UID:0000AR] and source-bearing children, not on this exact `.rdata` child.

## IDA Rename / Type / Comment Recommendations

No IDA rename is required for the vtable labels returned by current MCP. Optional type/comment work, if a future IDA cleanup pass is authorized, would be:

- Add or preserve comments at `0x006222d4`, `0x0062233c`, and `0x0062236c` identifying primary/secondary/tertiary RTTI locator dwords for `PrettyButtonControlPane`.
- Preserve labels `??_7PrettyButtonControlPane@@6B@`, `??_7PrettyButtonControlPane@@6B@_0`, and `??_7PrettyButtonControlPane@@6B@_1`.
- Avoid renaming the compiler-generated vtable labels to source-level method names; the slot table in documentation is the correct place for those semantics.

## First-Draft C++ Recommendation

No formal C++ insertion is recommended for UID0002UW.

Exact no-code proof:

1. UID0002UW is `.rdata` RTTI/vtable data, not an executable function.
2. Current generated output emits only an empty marker for UID0002UW while emitting the real source-bearing method bodies from the class children.
3. The bytes are regenerated by the compiler from the `PrettyButtonControlPane` class declaration, virtual inheritance/facet layout, and virtual method definitions.
4. Hand-porting the dwords as C++ would duplicate ABI output and risk contradicting the compiler-generated vtable layout.

Therefore preserve:

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

## Final Recommendation

UID0002UW has been implemented as a class-owned, reconstructable, source-declared/generated-binary vtable data page. The target is now `88/93`, stale parent-score and evidence wording is refreshed, current MCP session facts are incorporated, and owner/emitter/C++ disposition remains unchanged.

## Recommended Target Doc Changes

Implementation status for `by-memory/0x006222d4-0x00622378.PrettyButtonControlPaneVtableData.md`:

1. Applied metadata:
   - `COMPLETION:85` -> `COMPLETION:88`.
   - `CONFIDENCE:91` -> `CONFIDENCE:93`.
   - Keep `CANONICAL_OWNER:0000AR`.
   - Keep `RECONSTRUCTABLE:TRUE`.
   - Keep `EMITTER_UIDS:0000AR`.
   - Keep formal C++ blank.
2. Applied Item Summary rewrite removing stale "direct parent was raised to 85/86" language and recording current support status:
   - Direct class [UID:0000AR] is `89/91`.
   - Source file [UID:0000MP] is `89/91`.
   - Current 2026-07-08 MCP session `b007_uid0002oc_20260708` reconfirmed range, dwords, names, xrefs, and next boundary.
3. Applied `## Range` wording replacement from "Autogen parent" to current owner/emitter wording:
   - "Canonical owner/emitter: [UID:0000AR] `PrettyButtonControlPane`; source file route [UID:0000MP] `PrettyButtonControlPane`."
4. Applied current MCP evidence under `## IDA Evidence`:
   - `idb_list` command id `10`, `server_health` command id `11`, healthy database `b007_uid0002oc_20260708`, Hex-Rays ready.
   - `entity_query` command id `16`: labels at `0x006222d8`, `0x00622340`, `0x00622370`.
   - `get_int` command id `18`: exact dwords listed in this report.
   - `xrefs_to` command ids `19`, `20`, `22`: view-base stores, slot-target data xrefs, and no direct xrefs to selected slot addresses.
   - `entity_query` command id `23`: next `PrettyButtonControlPane2` and `PrimeNumberGenerator` boundary labels.
5. Preserved the existing view table, key slot table, and rebuild policy, adding current-session confirmation rather than replacing accepted historical evidence.
6. Applied target-specific no-code proof:
   - UID0002UW is compiler-generated `.rdata` from the class declaration.
   - `PrettyButtonControlPane.cpp` generated at validator command `000000007832`, refreshed `2026-07-07T03:37:36-04:00`, contains an expected empty emitter marker for UID0002UW.
7. Applied score rationale:
   - Completion `88`: exact binary layout, current MCP proof, accepted source-bearing children, generated-output implication, remaining cap for exact original class declaration / RTTI spelling.
   - Confidence `93`: current live evidence and stable support docs, capped below final audit by inferred class declaration details and compiler ABI source-form uncertainty.
8. Applied queue-resolution note:
   - The generated research tracker row had direct report count `0`; this B004 report resolves that coverage reason without changing ownership.

## Recommended Support Doc Changes

Implementation status for support docs:

1. `by-class/PrettyButtonControlPane.md` - applied.
   - Update the Evidence Note that says [UID:0000MP] is `86/88`; current file metadata is `89/91`.
   - Add one concise note that B004 UID0002UW current MCP recheck on 2026-07-08 reconfirmed the three class1 vtable views, store xrefs, and class2 boundary.
   - No metadata change was required.
2. `by-file/PrettyButtonControlPane.md` - applied optional evidence note.
   - B004 UID0002UW recheck confirmed the `0x006222d4-0x00622378` child with current MCP session `b007_uid0002oc_20260708`.
   - No metadata change was required.
3. `by-memory/0x006222d4-0x006224c0.ButtonPrimePursuitReadOnlyData.md` - applied optional exact-child/current-boundary evidence note.
   - UID0002UW remains an exact class-owned child; the aggregate remains non-reconstructable and mixed-owner.
   - No metadata change was required.
4. `auto-generated/NexusTK/ui/controls/PrettyButtonControlPane.cpp` - not edited by hand; validator refresh updated the UID0002UW empty marker to `88/93`.
5. Generated tracker / coverage files - not manually edited. Supervisor tooling should refresh or archive report state as part of normal lifecycle.

## Score And Metadata Recommendation

Applied target score: `88/93`.

Completion rationale:

- Raise above `85` because the direct report now supplies current MCP evidence, generated-output proof, exact dwords, view-base xrefs, slot-target xrefs, boundary proof, parent/file status, and accepted child report integration.
- Do not raise to `90+` because the exact original class declaration, inherited virtual function declaration order as source text, RTTI source spelling, and some field/resource/callback names are still inferred at the class/file level.

Confidence rationale:

- Raise above `91` because current database `b007_uid0002oc_20260708` is healthy and reconfirms all binary facts directly.
- Cap at `93` because vtable/RTTI source generation is compiler-mediated and exact original source spellings remain unproven.

Metadata:

| Field | Recommendation |
| --- | --- |
| `CANONICAL_OWNER` | Keep `0000AR`. |
| `RECONSTRUCTABLE` | Keep `TRUE`. |
| `EMITTER_UIDS` | Keep `0000AR`. |
| `EMITTER_POSITION_OPTIONAL` | Keep blank. |
| `RECONSTRUCTION_CPP` | Keep blank. |

## Open Questions With Attempted Resolution

| Question | Attempted Resolution | Remaining Status |
| --- | --- | --- |
| Is MCP currently available for direct binary evidence? | Supervisor provided active database `b007_uid0002oc_20260708`; `idb_list` and `server_health` returned healthy current state. | Resolved. |
| Was UID0002UW queued because ownership/source was bad? | Read-only tracker row shows direct report count `0`; target owner/emitter is otherwise correct. | Resolved as report-coverage queue reason. |
| Does the primary RTTI locator at `0x006222d4` belong in this child? | Current dword/name/boundary checks and aggregate/sibling docs confirm it is the class1 primary RTTI locator. | Resolved. |
| Should formal C++ contain a vtable initializer or declaration block? | Generated file has an empty marker for UID0002UW and emits real method children; compiler regenerates the vtable. | Resolved: no code. |
| Should score exceed `88/93`? | Remaining exact source declaration and RTTI source spelling uncertainty cap the score. | No higher score recommended in this pass. |

## Exact Manual Supervisor-Owned Coverage Or Tracker Text

No generated tracker or coverage files were manually edited during the report-only pass or implementation callback.

Read-only generated tracker row observed in `auto-generated/-ag-research-tracker.md`:

```markdown
| [UID:0002UW][0x006222d4-0x00622378.PrettyButtonControlPaneVtableData](by-memory/0x006222d4-0x00622378.PrettyButtonControlPaneVtableData.md) | 85/91 | 88.0 | true | 0 |  |  | `by-memory/0x006222d4-0x00622378.PrettyButtonControlPaneVtableData.md` |  |
```

Interpretation: the `0` direct-report count is resolved by this B004 report and callback implementation. It is not evidence that the by-memory target lacks a source owner. Supervisor `execute_report` should handle lifecycle/archive/tracker refresh.

## Follow-Up Actions

1. Supervisor should perform Gate 2 claim-by-claim verification against the changed by-* docs, validator output, generated freshness, ledger, and checklist.
2. If Gate 2 passes, supervisor should run the approved `execute_report` lifecycle command. B004 must not run it or manually move this report.
3. Generated tracker/archive state should be refreshed only by supervisor-owned validator lifecycle tooling.

## Confidence

High. Current live MCP evidence directly verifies the binary layout and cross-references; documentation and generated output are consistent with the compiler-generated no-code disposition. The remaining uncertainty is source-spelling level, not range/owner/source-route level.

## Validator Results

Scoped validators were run from `E:\NTK\GhidraBridge\source-3\project-documentation` after the implementation callback edits:

| File | Command | command_id | command_timestamp | Exit | ok | Relevant Output |
| --- | --- | --- | --- | ---: | ---: | --- |
| `by-memory/0x006222d4-0x00622378.PrettyButtonControlPaneVtableData.md` | `python .\tools\validator.py --mode file --file "by-memory\0x006222d4-0x00622378.PrettyButtonControlPaneVtableData.md" --apply --queue-timeout 240` | `000000007967` | `2026-07-08T16:05:59-04:00` | `0` | `1` | Applied `completion_update` to `88`, `confidence_update` to `93`, UID link inserts for UID0000AR/UID0000MP, projected stats update, `generated_refresh: deferred`. |
| `by-class/PrettyButtonControlPane.md` | `python .\tools\validator.py --mode file --file "by-class\PrettyButtonControlPane.md" --apply --queue-timeout 240` | `000000007968` | `2026-07-08T16:06:06-04:00` | `0` | `1` | Projected stats update; no target metadata changes. |
| `by-file/PrettyButtonControlPane.md` | `python .\tools\validator.py --mode file --file "by-file\PrettyButtonControlPane.md" --apply --queue-timeout 240` | `000000007969` | `2026-07-08T16:06:18-04:00` | `0` | `1` | Projected stats update; generated refresh later updated `PrettyButtonControlPane.cpp`. |
| `by-memory/0x006222d4-0x006224c0.ButtonPrimePursuitReadOnlyData.md` | `python .\tools\validator.py --mode file --file "by-memory\0x006222d4-0x006224c0.ButtonPrimePursuitReadOnlyData.md" --apply --queue-timeout 240` | `000000007971` | `2026-07-08T16:10:36-04:00` | `0` | `1` | Final aggregate validation after support wording normalization; projected stats update; `generated_refresh: deferred`. |

Generated freshness check after validation:

- `auto-generated/NexusTK/ui/controls/PrettyButtonControlPane.cpp` header now shows `validator-command-id: 000000007969`, `validator-refreshed-at: 2026-07-08T16:06:18-04:00`, `validator-refresh-source: deferred-generated-refresh`.
- UID0002UW marker now shows `Completion:88 | Confidence:93 | Empty Emitter Marker`.
- The generated C++ was not edited by hand.
- Earlier aggregate validator command `000000007970` at `2026-07-08T16:06:26-04:00` also exited `0` with `ok:1`; command `000000007971` is the final aggregate validation after the last support wording cleanup.

MCP-backed evidence commands were read-only JSON-RPC calls against active database `b007_uid0002oc_20260708`; command metadata is listed in `Evidence Checked`.

## Changed Files

Edited by B004:

- `by-memory/0x006222d4-0x00622378.PrettyButtonControlPaneVtableData.md`
- `by-class/PrettyButtonControlPane.md`
- `by-file/PrettyButtonControlPane.md`
- `by-memory/0x006222d4-0x006224c0.ButtonPrimePursuitReadOnlyData.md`
- `tools/leaser/Agents/Agent-B004/research/0002UW-PrettyButtonControlPaneVtableData-source-quality.md`

Validator-owned/generated side effects observed:

- `auto-generated/NexusTK/ui/controls/PrettyButtonControlPane.cpp` refreshed by validator to command id `000000007969` and now shows UID0002UW `88/93` empty marker.
- `project-level/-auto-completion-stats.md` projected path completion section was updated by scoped validators.

Not manually edited:

- No generated files.
- No coverage reports.
- No supervisor ledgers, validator state, queues, locks, archives, or lifecycle files.

## Implementation Tracking Checklist

- [x] Lease `by-memory/0x006222d4-0x00622378.PrettyButtonControlPaneVtableData.md` for the immediate target edit batch. Lease command returned `Success`.
- [x] Update UID0002UW metadata from `85/91` to `88/93`, preserving owner/emitter/reconstructable/C++ fields.
- [x] Refresh the target Item Summary, Range, IDA Evidence, no-code proof, queue-resolution note, and score rationale with the current B004 evidence.
- [x] Release the UID0002UW target lease promptly after the target edit. Explicit unlease after the first validator batch returned `Rejected[No active lease]`; current lease report has no B004 entries.
- [x] If support synchronization is approved, lease `by-class/PrettyButtonControlPane.md` and update the stale [UID:0000MP] score note plus optional B004 evidence note. Lease command returned `Success`; edit applied.
- [x] If support synchronization is approved, lease `by-file/PrettyButtonControlPane.md` and add an optional UID0002UW current-session evidence note. Lease command returned `Success`; edit applied.
- [x] If support synchronization is approved, lease `by-memory/0x006222d4-0x006224c0.ButtonPrimePursuitReadOnlyData.md` and add an optional exact-child/current-boundary evidence note. Lease command returned `Success`; edit applied.
- [x] Release all support leases promptly. The first explicit release attempt returned `Rejected[No active lease]`; a fresh aggregate lease was taken for final support wording normalization and released successfully. Current lease report has no B004 entries.
- [x] Run scoped validators only for files actually changed during the implementation callback. Five scoped file validator invocations across four by-* files exited `0` with `ok:1`; final aggregate state is validator command `000000007971`.
- [x] Confirm generated `PrettyButtonControlPane.cpp` refreshes UID0002UW empty marker score after validator execution. Header command id `000000007969`; UID0002UW marker is `88/93`.
- [x] Repair `## Claim And Incorporation Ledger` to the required final-report columns while preserving C01-C10 claims/evidence and adding confidence, destination doc/section, action, and `applied` verification state for each row.
- [x] Do not manually edit generated tracker/coverage/lifecycle files; let supervisor tooling handle them.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B004","command_id":"000000007977","destination_path":"executed-b-agent-research/B004/0002UW-PrettyButtonControlPaneVtableData-source-quality.md","details":"report executed into central archive","event":"executed","source_path":"tools/leaser/Agents/Agent-B004/research/0002UW-PrettyButtonControlPaneVtableData-source-quality.md","timestamp":"2026-07-08T16:27:01-04:00","uid":"0002UW"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
