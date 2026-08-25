** TARGET-REPORT-UID:0000JU **
** AUTHOR-AGENT-ID:B004 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **

# 0000JU HelpPanes Empty-Emitter Family Source-Quality Report

Status: FINISHED_IMPLEMENTATION (accepted first-batch callback applied 2026-06-30)

## Assignment

- Target: [UID:0000JU] `by-file/HelpPanes.md`
- Generated file: `auto-generated/NexusTK/ui/controls/HelpPanes.cpp`
- Queue: Files With Empty Emitters front queue
- Required report path: `tools/leaser/Agents/Agent-B004/research/0000JU-HelpPanes-empty-emitter-family-source-quality.md`
- Original mode: report-only research. I did not edit target/support by-* docs, generated files, coverage reports, validator/tool state, IDA DB, executed archives, supervisor ledgers, lock files, or lease state during the original research pass.
- Accepted first-batch implementation callback: applied on 2026-06-30 to the bounded by-* rows listed in the checklist below. Generated output and validator-owned metadata were refreshed only by the scoped validators.
- No subagents were spawned.

## Executive Recommendation

The current `HelpPanes.cpp` empty-emitter family is not one missing function. It is a mixed queue of class routing pages, singleton/global declarations, exact storage pages, one raw no-entry helper, one broad WillBeChanged method-cluster that still needs a split, and one source-declared/generated-binary `.rdata` island.

Recommended bounded first implementation batch:

1. Add no-standalone class markers plus `[[CHILDREN]]` insertion points to the class pages that already have exact child coverage:
   [UID:000063] `HelpPane`, [UID:000064] `HelpPane__SimpleHelpTextPartPane`, [UID:00006U] `ItemHelpPane`, [UID:0000D6] `SimpleHelpPane`, and [UID:0000D7] `SimpleHelpPane2`.
2. Add first-draft singleton declarations to the by-global pages and covered-by/no-duplicate comments to their exact storage pages:
   [UID:0000R9]/[UID:0001PD], [UID:0000S9]/[UID:0001PC], [UID:0000SA]/[UID:0001OY], and [UID:0000SS]/[UID:0001PK].
3. Add explicit no-code formal marker comments to [UID:00022N] `HelpPaneFadeStateUpdate` and [UID:00025G] `HelpItemHelpReadOnlyData`; do not emit hand-written function/data bodies.
4. Correct stale `g_pWillBeChangedItemPane` byte wording in [UID:0000SS] and [UID:0001PK]: current MCP reads `0x0069b414` as `00 00 00 00` / `0`, not `ff ff ff ff` / `0xffffffff`.

Follow-up batch, not the bounded first batch: split [UID:00016U] `WillBeChangedPreviewPanes` into exact item/spell method children, then add class route markers for [UID:0000G5] `WillBeChangedItemPane` and [UID:0000G6] `WillBeChangedSpellPane`. Do not emit a broad aggregate C++ block from [UID:00016U].

## Current Generated State

Current generated header checked read-only:

- `auto-generated/NexusTK/ui/controls/HelpPanes.cpp`
- `validator-command-id: 000000001897`
- `Source by-file UID: 0000JU`

The current file emits source bodies for [UID:00048E]-[UID:00048O], [UID:000228], [UID:00016T], and [UID:00022O], then carries these 18 empty markers:

| UID | Path | Current score | Marker disposition |
| --- | --- | --- | --- |
| `000063` | `by-class/HelpPane.md` | `85/89` | Class routing/index page; exact children exist, class needs no-standalone marker plus `[[CHILDREN]]`, not aggregate method C++. |
| `000064` | `by-class/HelpPane__SimpleHelpTextPartPane.md` | `87/89` | Class routing/index page; exact children exist and some child C++ is already present in by-memory docs, but current generated file still does not surface those child bodies. Needs class route marker plus `[[CHILDREN]]`. |
| `00006U` | `by-class/ItemHelpPane.md` | `86/86` | Class routing/index page over exact ItemHelpPane children. Needs no-standalone marker plus `[[CHILDREN]]`; do not paste child bodies into class page. |
| `0000D6` | `by-class/SimpleHelpPane.md` | `86/88` | Class routing/index page over emitted child bodies [UID:00048E]-[UID:00048J]. Needs no-standalone marker plus `[[CHILDREN]]` or equivalent accepted class-index marker. |
| `0000D7` | `by-class/SimpleHelpPane2.md` | `88/88` | Class routing/index page over emitted child bodies [UID:00048K]-[UID:00048O], factory [UID:00016T], and helpers [UID:00022O]. Needs no-standalone marker plus `[[CHILDREN]]`. |
| `0000G5` | `by-class/WillBeChangedItemPane.md` | `85/88` | Follow-up with [UID:00016U] split. Do not emit class marker first unless child split is accepted or supervisor explicitly wants a class-only marker. |
| `0000G6` | `by-class/WillBeChangedSpellPane.md` | `86/87` | Follow-up with [UID:00016U] split. Do not emit class marker first unless child split is accepted or supervisor explicitly wants a class-only marker. |
| `0000R9` | `by-global/g_pItemHelpPane.md` | `86/88` | Singleton declaration source item. Emit `static ItemHelpPane *g_pItemHelpPane = nullptr;` with `[[CHILDREN]]`; route storage child as covered/no duplicate. |
| `0000S9` | `by-global/g_pSimpleHelpPane.md` | `87/90` | Singleton declaration source item. Emit `static SimpleHelpPane *g_pSimpleHelpPane = nullptr;` with `[[CHILDREN]]`; route storage child as covered/no duplicate. |
| `0001PC` | `by-memory/0x0069ae00-0x0069ae04.g_pSimpleHelpPane.md` | `87/90` | Exact storage child for [UID:0000S9]. Add covered-by/no-duplicate formal comment; do not emit a second definition. |
| `0000SA` | `by-global/g_pSimpleHelpPane2.md` | `87/92` | Singleton declaration source item. Emit `static SimpleHelpPane2 *g_pSimpleHelpPane2 = nullptr;` with `[[CHILDREN]]`; route storage child as covered/no duplicate. |
| `0001OY` | `by-memory/0x0067a7d4-0x0067a7d8.g_pSimpleHelpPane2.md` | `87/92` | Exact storage child for [UID:0000SA]. Add covered-by/no-duplicate formal comment; do not emit a second definition. |
| `0000SS` | `by-global/g_pWillBeChangedItemPane.md` | `86/89` | Singleton declaration source item. Emit `static WillBeChangedItemPane *g_pWillBeChangedItemPane = nullptr;` with `[[CHILDREN]]`; update stale initializer wording to current zero bytes. |
| `00022N` | `by-memory/0x004c6eb0-0x004c6f89.HelpPaneFadeStateUpdate.md` | `87/88` | Exact raw no-entry HelpPane style-state body. Keep reconstructable and HelpPanes-owned, but add a no-formal-C++ marker/proof. Do not invent a callable method body. |
| `00016U` | `by-memory/0x004c78e0-0x004c82cf.WillBeChangedPreviewPanes.md` | `85/90` | Broad method-cluster over two classes plus padding. Follow-up split required; no aggregate C++. |
| `00025G` | `by-memory/0x0061aad0-0x0061b340.HelpItemHelpReadOnlyData.md` | `89/92` | Source-declared/generated-binary `.rdata` island. Add no-raw-data marker; do not hand-port vtable/RTTI/string bytes. |
| `0001PD` | `by-memory/0x0069ae04-0x0069ae08.g_pItemHelpPane.md` | `86/90` | Exact storage child. Prefer route through [UID:0000R9] or add covered-by/no-duplicate formal comment; do not emit a second definition. |
| `0001PK` | `by-memory/0x0069b414-0x0069b418.g_pWillBeChangedItemPane.md` | `86/90` | Exact storage child. Prefer route through [UID:0000SS] or add covered-by/no-duplicate formal comment; update stale initializer wording to current zero bytes. |

## MCP Evidence

Current MCP was available and used. I did not start, stop, restart, or kill MCP/IDA/Python processes.

- Endpoint: `http://127.0.0.1:13337/mcp`
- Active database/session: `supervisor_resume_20260629`
- `idb_list`: one active worker session for `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, `is_analyzing:false`, `is_active:true`, `pid:17592`, `worker_pid:17592`
- `server_health`: `status:ok`, module `NexusTK.exe`, imagebase `0x400000`, `auto_analysis_ready:true`, `hexrays_ready:true`, `strings_cache_ready:true`, `strings_cache_size:2067`

Current targeted MCP facts:

- `lookup_funcs` reports no function at `0x004c6eb0` or `0x004c6f89`; `xrefs_to 0x004c6eb0` reports zero xrefs. This reconfirms [UID:00022N] as exact raw no-entry code with no proven callable route.
- `lookup_funcs` reconfirms `SimpleHelpPane`/`SimpleHelpPane2` starts: `0x004c6f90` size `0x2f7`, `0x004c7290` size `0x77`, `0x004c74b0` size `0x125`, and successor factory `0x004c7680` size `0x160`. `xrefs_to 0x004c6f90` has 18 direct constructor callers; `xrefs_to 0x004c74b0` remains zero; `0x004c7610`, `0x004c7620`, and `0x004c7670` have vtable/data refs at `0x0061acec`, `0x0061acbc`, and `0x0061acc0`.
- `lookup_funcs` reconfirms [UID:00016U] method starts: `0x004c78e0` size `0x296`, `0x004c7b80` size `0x29`, `0x004c7bb0` size `0x34d`, `0x004c7f90` size `0x130`, `0x004c80c0` size `0x1f`, `0x004c80e0` size `0x164`, `0x004c8250` size `0x3a`, and `0x004c8290` size `0x3f`. Current xrefs reconfirm item constructor caller `0x004ed40f`, item paint vtable/data ref `0x0061ad38`, spell constructor caller `0x0057df03`, and spell paint/mouse/key vtable/data refs `0x0061adc0`, `0x0061adcc`, `0x0061add0`.
- `lookup_funcs` reconfirms ItemHelpPane starts: constructor `0x004c82d0` size `0x843`, paint `0x004c8bd0` size `0x3fd0`, populate `0x004ccca0` size `0x1456`, and support helper `0x004ce160` size `0x4b`. Current xrefs reconfirm four ItemHelpPane constructor callers and the paint vtable/data ref `0x0061ae48`.
- `xrefs_to` singleton slots reconfirm exact current ref counts:
  - `0x0069ae00 g_pSimpleHelpPane`: 23 refs; current bytes/value `00 00 00 00` / `0`.
  - `0x0067a7d4 g_pSimpleHelpPane2`: 9 refs; current bytes/value `00 00 00 00` / `0`.
  - `0x0069ae04 g_pItemHelpPane`: 20 refs; current bytes/value `00 00 00 00` / `0`.
  - `0x0069b414 g_pWillBeChangedItemPane`: 5 refs; current bytes/value `00 00 00 00` / `0`.
- `get_bytes` reconfirms key padding:
  - `0x004c6f89-0x004c6f90`: seven `0xcc`.
  - `0x004c7b76-0x004c7b80`: ten `0xcc`.
  - `0x004c7ba9-0x004c7bb0`: seven `0xcc`.
  - `0x004c7efd-0x004c7f00`: three `0xcc`.
  - `0x004c8244-0x004c8250`: twelve `0xcc`.
  - `0x004c828a-0x004c8290`: six `0xcc`.
  - `0x004c82cf`: one `0xcc` before the `ItemHelpPane` successor.
- `entity_query(kind=names)` over `0x0061aad0-0x0061b340` returns 100 named items. The vtable sequence is:
  `SimpleHelpTextPartPane<HelpPane>` at `0x0061aad4/0x0061ab20/0x0061ab50`,
  `HelpPane` at `0x0061ab5c/0x0061aba8/0x0061abd8`,
  `SimpleHelpPane` at `0x0061abe4/0x0061ac30/0x0061ac60`,
  `SimpleHelpPane2` at `0x0061ac6c/0x0061acb8/0x0061ace8`,
  `WillBeChangedItemPane` at `0x0061acf4/0x0061ad40/0x0061ad70`,
  `WillBeChangedSpellPane` at `0x0061ad7c/0x0061adc8/0x0061adf8`,
  and `ItemHelpPane` at `0x0061ae04/0x0061ae50/0x0061ae80`, followed by item-help literals through `0x0061b330`.

## Prior Report Search

Executed B-agent reports checked as provenance:

- B001 `00016R-HelpPaneCore-source-quality.md`: split `HelpPaneCore` into exact children and made [UID:00016R] a non-emitting split index.
- B013 `000064-HelpPane__SimpleHelpTextPartPane-source-quality.md`: resolved text-part fields and route/no-route proof; class-level C++ should be declaration/index only, with method bodies on child pages.
- B012 `00022N-HelpPaneFadeStateUpdate-source-quality.md`: kept [UID:00022N] HelpPanes-owned and reconstructable but formal C++ blank because no function object, xref, vtable, or pointer route is proven.
- B007 `00016S-SimpleHelpPanes-source-quality.md`: split [UID:00016S] into exact `SimpleHelpPane` and `SimpleHelpPane2` method children; parent is non-emitting.
- B009 `00016T-SimpleHelpPane2Factory-source-quality.md`: made [UID:00016T] source-ready first-draft factory C++.
- B009 `00022O-SimpleHelpPane2FactoryHelpers-source-quality.md`: made [UID:00022O] source-ready first-draft wrapper/predicate C++.
- B001 `00016V-item-help-pane-core-source-quality.md`: split ItemHelpPaneCore into exact children; parent is non-emitting.
- B006 `0003PN-ItemHelpPaneOnPaintFrame-source-quality.md`: resolved `OnPaintFrame` owner, field names, helper roles, and jump-table separation while keeping formal C++ deferred.
- B015 `00022P-HelpTooltipSupportHelpers-empty-emitter-source-quality.md`: reclassified support helpers as non-emitting compiler/STL/EH support metadata; no standalone helper C++.
- B001 `000228-help-pane-singleton-close-source-quality.md`: resolved file-local singleton close helpers and gave first-draft singleton declarations for `g_pSimpleHelpPane` and `g_pItemHelpPane`.

No dedicated executed report for [UID:00016U] or the WillBeChanged class pages was found under `executed-b-agent-research`. Those rows rely on current support docs, current MCP, and prior class/global refresh notes rather than a dedicated source-quality split report.

## Heuristic Reanalysis

### Class Empty Markers

The class pages are not suitable places to paste all child method bodies. They are routing/declaration/class-evidence pages. The local by-class guidance says class pages may use a formal no-standalone marker plus `[[CHILDREN]]` when method bodies belong to exact by-memory children.

Accepted local precedent: `by-class/ConfirmDeleteAlert.md` uses a block comment explaining no standalone class-level C++ and then `[[CHILDREN]]`, at `87/89`, to clear the empty marker while keeping exact children as body owners.

Recommended class-marker shape:

```cpp
/*
[UID:xxxx] No standalone class-level C++ is emitted from this class page.
Exact method/helper/source bodies are represented by the child pages listed in this documentation; this class page remains the class-level route and evidence owner and must not duplicate child method bodies.
*/
[[CHILDREN]]
```

Apply this pattern to [UID:000063], [UID:000064], [UID:00006U], [UID:0000D6], and [UID:0000D7] in the bounded first implementation batch. For [UID:0000G5] and [UID:0000G6], wait for the [UID:00016U] exact child split unless the supervisor explicitly wants a class-only marker first.

### Singleton Globals And Exact Storage

The singleton pages should not all define the same object independently. Use one source declaration per singleton, preferably on the by-global symbol page, with exact storage children carrying a covered-by/no-duplicate marker.

Recommended formal global snippets:

```cpp
static ItemHelpPane *g_pItemHelpPane = nullptr;

[[CHILDREN]]
```

```cpp
static SimpleHelpPane *g_pSimpleHelpPane = nullptr;

[[CHILDREN]]
```

```cpp
static SimpleHelpPane2 *g_pSimpleHelpPane2 = nullptr;

[[CHILDREN]]
```

```cpp
static WillBeChangedItemPane *g_pWillBeChangedItemPane = nullptr;

[[CHILDREN]]
```

Recommended storage-child comment:

```cpp
// Emitted declaration for this singleton storage is covered by [UID:xxxx].
```

For [UID:0001PD] and [UID:0001PK], the implementation should consider owner/emitter normalization to their by-global symbol pages ([UID:0000R9] and [UID:0000SS]) because [UID:0001PC] and [UID:0001OY] already use that model. If validator/by-structure rejects the metadata conversion, keep the current metadata and use the covered-by comment with an explicit reason in the report checklist.

### Raw Helper And Generated-Binary Data

[UID:00022N] is real executable HelpPanes behavior but currently has no source-callable route. Do not author a method body. Use a formal marker/proof, for example:

```cpp
/*
[UID:00022N] No formal C++ body is emitted for this raw HelpPane style-state body.
Current MCP reports no modeled function at 0x004c6eb0 and no xrefs to 0x004c6eb0; prior PE/xref scans found no vtable, function-pointer, or absolute-pointer route. Keep the behavior documented here until a source-callable entry route is proven.
*/
```

[UID:00025G] is source-declared/generated-binary data. Do not hand-port vtables, RTTI, or string bytes. Use a formal marker/proof, for example:

```cpp
/*
[UID:00025G] HelpPanes read-only data is source-declared/generated-binary output.
The compiler/linker regenerates this range from the HelpPane, SimpleHelpPane, SimpleHelpPane2, WillBeChanged, and ItemHelpPane class declarations, virtual methods, RTTI, and item-help string literals. Do not hand-port the raw rdata bytes as source.
*/
```

### WillBeChanged Follow-Up Split

[UID:00016U] should not remain a reconstructable blank-code aggregate long-term. It spans two classes and ten methods plus padding. The exact split is already documented and current MCP reconfirms the boundaries:

| Proposed child | Range | Owner |
| --- | --- | --- |
| `WillBeChangedItemPaneConstructor` | `0x004c78e0-0x004c7b76` | [UID:0000G5] |
| `WillBeChangedItemPaneNonDeletingDestructor` | `0x004c7b80-0x004c7ba9` | [UID:0000G5] |
| `WillBeChangedItemPaneOnPaint` | `0x004c7bb0-0x004c7efd` | [UID:0000G5] |
| `WillBeChangedItemPaneOnEvent` | `0x004c7f00-0x004c7f4e` | [UID:0000G5] |
| `WillBeChangedItemPaneOnKeyEvent` | `0x004c7f50-0x004c7f8f` | [UID:0000G5] |
| `WillBeChangedSpellPaneConstructor` | `0x004c7f90-0x004c80c0` | [UID:0000G6] |
| `WillBeChangedSpellPaneNonDeletingDestructor` | `0x004c80c0-0x004c80df` | [UID:0000G6] |
| `WillBeChangedSpellPaneOnPaint` | `0x004c80e0-0x004c8244` | [UID:0000G6] |
| `WillBeChangedSpellPaneHandleMouseInput` | `0x004c8250-0x004c828a` | [UID:0000G6] |
| `WillBeChangedSpellPaneHandleKeyInput` | `0x004c8290-0x004c82cf` | [UID:0000G6] |

After child creation, convert [UID:00016U] to a non-emitting split index (`RECONSTRUCTABLE:FALSE`, blank `EMITTER_UIDS`) and route [UID:0000G5]/[UID:0000G6] through no-standalone class markers plus `[[CHILDREN]]`.

## Ranked Ownership

1. [UID:0000JU] `HelpPanes` by-file owner remains the best source-family root for this empty-emitter family. The classes, globals, raw helpers, `.rdata`, singleton close helpers, factory, support helpers, and destructor wrappers all sit in the HelpPanes tooltip/help source neighborhood.
2. Class pages are the correct direct semantic owners for exact method children: [UID:000063], [UID:000064], [UID:00006U], [UID:0000D6], [UID:0000D7], [UID:0000G5], and [UID:0000G6]. They should not become method-body aggregates.
3. By-global pages are the correct direct semantic owners for singleton symbols. Exact storage memory pages should either route through those globals or carry covered-by/no-duplicate comments.
4. [UID:00022N] remains file-owned rather than class-owned because no function object, vtable slot, or pointer route proves a class-method entry. It is HelpPane-specific behavior but not currently a source-emitting callable method.
5. [UID:00025G] remains HelpPanes-owned source-declared/generated-binary data. Do not move it to ItemHelpPane, WillBeChanged, GrafPort, or MetaMan; those are partial owners/consumers/dependencies for pieces of the rdata island, not the whole mixed range.

Rejected ownership alternatives:

- Do not route ItemHelpPane method/data rows to MetaMan; MetaMan is a lookup dependency, not the tooltip presentation owner.
- Do not route WillBeChanged item singleton storage to adjacent [UID:0001PJ] `g_pMetaMan`; current xrefs and class evidence bind it to the preview pane.
- Do not move the family to MiniMap, InventoryPane, ItemDialogs, SelfLookPane, or caller feature files. Those are consumers/callers.
- Do not create new `ItemHelpPane.cpp` or `WillBeChangedPanes.cpp` roots in this pass. Existing docs preserve those as plausible future source splits but current evidence does not prove original compilation-unit separation.

## Score And Metadata Recommendations

First implementation batch should avoid unnecessary score churn unless the supervisor wants a coverage-stat update. Suggested metadata:

- [UID:000063], [UID:000064], [UID:00006U], [UID:0000D6], [UID:0000D7]: keep current owner/emitter metadata; add no-standalone marker plus `[[CHILDREN]]`.
- [UID:0000R9], [UID:0000S9], [UID:0000SA], [UID:0000SS]: keep owner/emitter route through [UID:0000JU]; add singleton declaration plus `[[CHILDREN]]`.
- [UID:0001PC], [UID:0001OY]: keep owner/emitter route through the corresponding global page; add covered-by/no-duplicate comment.
- [UID:0001PD]: preferred owner/emitter normalization to [UID:0000R9]; if rejected, keep [UID:0000JU] and add covered-by comment.
- [UID:0001PK]: preferred owner/emitter normalization to [UID:0000SS]; if rejected, keep [UID:0000JU] and add covered-by comment.
- [UID:00022N]: keep `RECONSTRUCTABLE:TRUE`, owner/emitter [UID:0000JU], score `87/88`; add no-formal-C++ marker/proof.
- [UID:00025G]: keep `RECONSTRUCTABLE:TRUE`, owner/emitter [UID:0000JU], score `89/92`; add source-declared/generated-binary marker/proof.
- [UID:00016U], [UID:0000G5], [UID:0000G6]: follow-up split batch. Do not change in the first batch unless accepted explicitly.

## Implementation Callback Result

Accepted first-batch implementation was applied to 16 by-* docs: five class-route pages, four by-global singleton pages, four exact singleton-storage pages, [UID:00022N], [UID:00025G], and [UID:0000JU] `by-file/HelpPanes.md`.

Lease record:

- Short leases were requested immediately before editing the 16 by-* docs and every lease request returned `Success`.
- Release was attempted immediately after the edit/validator batch. The leaser returned `Rejected[No active lease]` for each path, and a follow-up lease report showed no active B004 leases. Only unrelated expired Supervisor leases remained.

Scoped validator record:

| Path | command_id | command_timestamp | exit | ok |
| --- | --- | --- | --- | --- |
| `by-class/HelpPane.md` | `000000001949` | `2026-06-30T01:19:46-04:00` | `0` | `1` |
| `by-class/HelpPane__SimpleHelpTextPartPane.md` | `000000001950` | `2026-06-30T01:19:48-04:00` | `0` | `1` |
| `by-class/ItemHelpPane.md` | `000000001951` | `2026-06-30T01:19:49-04:00` | `0` | `1` |
| `by-class/SimpleHelpPane.md` | `000000001952` | `2026-06-30T01:19:51-04:00` | `0` | `1` |
| `by-class/SimpleHelpPane2.md` | `000000001953` | `2026-06-30T01:19:53-04:00` | `0` | `1` |
| `by-global/g_pItemHelpPane.md` | `000000001954` | `2026-06-30T01:19:54-04:00` | `0` | `1` |
| `by-global/g_pSimpleHelpPane.md` | `000000001955` | `2026-06-30T01:19:56-04:00` | `0` | `1` |
| `by-global/g_pSimpleHelpPane2.md` | `000000001957` | `2026-06-30T01:19:58-04:00` | `0` | `1` |
| `by-global/g_pWillBeChangedItemPane.md` | `000000001958` | `2026-06-30T01:20:00-04:00` | `0` | `1` |
| `by-memory/0x0069ae00-0x0069ae04.g_pSimpleHelpPane.md` | `000000001959` | `2026-06-30T01:20:02-04:00` | `0` | `1` |
| `by-memory/0x0067a7d4-0x0067a7d8.g_pSimpleHelpPane2.md` | `000000001960` | `2026-06-30T01:20:03-04:00` | `0` | `1` |
| `by-memory/0x0069ae04-0x0069ae08.g_pItemHelpPane.md` | `000000001961` | `2026-06-30T01:20:05-04:00` | `0` | `1` |
| `by-memory/0x0069b414-0x0069b418.g_pWillBeChangedItemPane.md` | `000000001963` | `2026-06-30T01:20:07-04:00` | `0` | `1` |
| `by-memory/0x004c6eb0-0x004c6f89.HelpPaneFadeStateUpdate.md` | `000000001965` | `2026-06-30T01:20:09-04:00` | `0` | `1` |
| `by-memory/0x0061aad0-0x0061b340.HelpItemHelpReadOnlyData.md` | `000000001967` | `2026-06-30T01:20:12-04:00` | `0` | `1` |
| `by-file/HelpPanes.md` | `000000001969` | `2026-06-30T01:20:15-04:00` | `0` | `1` |

Generated freshness:

- `auto-generated/NexusTK/ui/controls/HelpPanes.cpp` was inspected only through validator-owned refresh/header metadata.
- Current generated header after queue catch-up: `validator-command-id: 000000001969`, `validator-refreshed-at: 2026-06-30T01:20:15-04:00`, `validator-refresh-source: deferred-generated-refresh`, `Source by-file UID: 0000JU`.
- Accepted first-batch marker/declaration rows are present in generated output. The remaining empty markers are the explicitly excluded follow-up rows [UID:0000G5], [UID:0000G6], and [UID:00016U].
- Child-output duplicate check found one generated instance each for [UID:00048E]-[UID:00048O], [UID:00016T], [UID:00022O], and [UID:000228]. A residual generated duplicate of `g_pSimpleHelpPane` and `g_pItemHelpPane` remains inside existing [UID:000228] output; [UID:000228] was not in this callback scope and was not edited.

## Implementation Tracking Checklist

- [x] Update [UID:000063] `by-class/HelpPane.md` with no-standalone class marker plus `[[CHILDREN]]`; do not paste child method bodies into this class page. Proof: validator `000000001949` exit `0` ok `1`.
- [x] Update [UID:000064] `by-class/HelpPane__SimpleHelpTextPartPane.md` with no-standalone class marker plus `[[CHILDREN]]`. Proof: validator `000000001950` exit `0` ok `1`. Generated output now carries the class marker; child body surfacing for [UID:0003ZU], [UID:0003ZV], and [UID:0003ZX] remains a validator registry/child-attachment follow-up because this callback forbids validator state edits and the validator reported missing child UID references.
- [x] Update [UID:00006U] `by-class/ItemHelpPane.md` with no-standalone class marker plus `[[CHILDREN]]`; keep [UID:0003PN] formal C++ deferred. Proof: validator `000000001951` exit `0` ok `1`.
- [x] Update [UID:0000D6] `by-class/SimpleHelpPane.md` with no-standalone class marker plus `[[CHILDREN]]`; ensure no duplicate generation of [UID:00048E]-[UID:00048J]. Proof: validator `000000001952` exit `0` ok `1`; generated duplicate check found one instance each.
- [x] Update [UID:0000D7] `by-class/SimpleHelpPane2.md` with no-standalone class marker plus `[[CHILDREN]]`; ensure no duplicate generation of [UID:00048K]-[UID:00048O], [UID:00016T], or [UID:00022O]. Proof: validator `000000001953` exit `0` ok `1`; generated duplicate check found one instance each.
- [x] Update [UID:0000R9] `by-global/g_pItemHelpPane.md` with `static ItemHelpPane *g_pItemHelpPane = nullptr;` and `[[CHILDREN]]`. Proof: validator `000000001954` exit `0` ok `1`.
- [x] Update [UID:0000S9] `by-global/g_pSimpleHelpPane.md` with `static SimpleHelpPane *g_pSimpleHelpPane = nullptr;` and `[[CHILDREN]]`. Proof: validator `000000001955` exit `0` ok `1`.
- [x] Update [UID:0000SA] `by-global/g_pSimpleHelpPane2.md` with `static SimpleHelpPane2 *g_pSimpleHelpPane2 = nullptr;` and `[[CHILDREN]]`. Proof: validator `000000001957` exit `0` ok `1`.
- [x] Update [UID:0000SS] `by-global/g_pWillBeChangedItemPane.md` with `static WillBeChangedItemPane *g_pWillBeChangedItemPane = nullptr;`, `[[CHILDREN]]`, and current MCP byte wording `00 00 00 00` / `0`. Proof: validator `000000001958` exit `0` ok `1`.
- [x] Update [UID:0001PC] `by-memory/0x0069ae00-0x0069ae04.g_pSimpleHelpPane.md` with a covered-by/no-duplicate comment pointing to [UID:0000S9]. Proof: validator `000000001959` exit `0` ok `1`.
- [x] Update [UID:0001OY] `by-memory/0x0067a7d4-0x0067a7d8.g_pSimpleHelpPane2.md` with a covered-by/no-duplicate comment pointing to [UID:0000SA]. Proof: validator `000000001960` exit `0` ok `1`.
- [x] Update [UID:0001PD] `by-memory/0x0069ae04-0x0069ae08.g_pItemHelpPane.md` with a covered-by/no-duplicate comment pointing to [UID:0000R9]; owner/emitter normalization to [UID:0000R9] was accepted. Proof: validator `000000001961` exit `0` ok `1`.
- [x] Update [UID:0001PK] `by-memory/0x0069b414-0x0069b418.g_pWillBeChangedItemPane.md` with a covered-by/no-duplicate comment pointing to [UID:0000SS], current MCP byte wording `00 00 00 00` / `0`, and owner/emitter normalization to [UID:0000SS]. Proof: validator `000000001963` exit `0` ok `1`.
- [x] Update [UID:00022N] `by-memory/0x004c6eb0-0x004c6f89.HelpPaneFadeStateUpdate.md` with the no-formal-C++ marker/proof; preserve the no-function/no-xref evidence and keep behavior documentation. Proof: validator `000000001965` exit `0` ok `1`.
- [x] Update [UID:00025G] `by-memory/0x0061aad0-0x0061b340.HelpItemHelpReadOnlyData.md` with the source-declared/generated-binary no-raw-data marker/proof. Proof: validator `000000001967` exit `0` ok `1`.
- [x] Update [UID:0000JU] `by-file/HelpPanes.md` to record the first-batch decisions at report-level detail: class markers/children, singleton declaration routing, raw helper no-code proof, rdata no-raw-data proof, current singleton byte correction for `g_pWillBeChangedItemPane`, and [UID:00016U] follow-up split status. Proof: validator `000000001969` exit `0` ok `1`.
- [x] Follow-up only: split [UID:00016U] into the ten exact children listed above, then convert [UID:00016U] to a non-emitting split index and update [UID:0000G5]/[UID:0000G6]. Proof: excluded with reason by supervisor scope limit for this callback; no split pages or [UID:0000G5]/[UID:0000G6] completion edits were made.
- [x] Do not edit generated files, generated reports, coverage reports, validator state, IDA DB, executed archives, supervisor ledgers, lock files, or leases by hand. Proof: only by-* docs and this B004 report were manually edited; generated HelpPanes.cpp and validator-owned metadata changed only through validators.
- [x] Run scoped validators for each changed by-* doc from `source-3/project-documentation` with `python .\tools\validator.py --mode file --file <relative-by-star-path> --apply --queue-timeout 240`. Proof: command IDs `000000001949` through `000000001969` listed above all exited `0` with ok `1`.
- [x] Inspect generated `auto-generated/NexusTK/ui/controls/HelpPanes.cpp` only through validator-owned refresh/header metadata after implementation. Confirm removed/resolved markers and check for duplicate child output. Proof: header reached `validator-command-id:000000001969`; accepted rows are present; [UID:0000G5], [UID:0000G6], and [UID:00016U] remain empty by accepted exclusion; residual duplicate singleton declarations from [UID:000228] are recorded as out-of-scope follow-up.

## Claim And Incorporation Ledger

| Claim | Evidence | Implementation disposition |
| --- | --- | --- |
| MCP is available and current evidence was used. | `server_health` for `supervisor_resume_20260629` returned `status:ok`, Hex-Rays ready, strings cache ready. | Incorporated. MCP was checked again for implementation and remained available; no fallback-only evidence was used. |
| Current generated file had 18 empty markers before implementation. | Read-only pre-callback `HelpPanes.cpp` header `validator-command-id:000000001897`; marker inventory above. | Incorporated. Validator-owned refresh advanced to `validator-command-id:000000001969`; accepted first-batch rows are no longer empty markers, while [UID:0000G5], [UID:0000G6], and [UID:00016U] remain follow-up empty markers by scope. |
| Class pages are routing/index pages, not aggregate method-body owners. | by-class guidance; existing `ConfirmDeleteAlert` no-standalone marker plus `[[CHILDREN]]`; executed B001/B007/B001 split reports. | Applied to [UID:000063], [UID:000064], [UID:00006U], [UID:0000D6], and [UID:0000D7]. Validators `000000001949`-`000000001953` passed. |
| `HelpPane__SimpleHelpTextPartPane` child C++ exists but is not in current generated output. | `by-memory/0x004c65a0...`, `0x004c6630...`, and `0x004c6880...` have formal C++; pre-callback generated `HelpPanes.cpp` only showed class empty marker for [UID:000064]. | Partially applied with explicit exclusion reason. The class route marker was applied and validated. Generated child assembly for [UID:0003ZU], [UID:0003ZV], and [UID:0003ZX] still depends on validator registry/child attachment, which was outside callback scope. |
| Singleton globals should emit once. | Current MCP xrefs/bytes for four singleton slots; B001 singleton close helper report; by-global examples. | Applied to by-global [UID:0000R9], [UID:0000S9], [UID:0000SA], [UID:0000SS] and storage [UID:0001PC], [UID:0001OY], [UID:0001PD], [UID:0001PK]. Validators `000000001954`-`000000001963` passed. Residual duplicate declarations from existing [UID:000228] generated output are out of scope for this callback. |
| `g_pWillBeChangedItemPane` initializer wording is stale. | Current MCP `get_bytes` and `get_int` read `0x0069b414` as zeros/value 0. | Applied to [UID:0000SS], [UID:0001PK], and [UID:0000JU]. Validators `000000001958`, `000000001963`, and `000000001969` passed. |
| [UID:00022N] should not emit a method body now. | Current MCP no function at `0x004c6eb0`, no xrefs to `0x004c6eb0`; B012 no-route proof. | Applied. [UID:00022N] now has a no-formal-C++ marker/proof; validator `000000001965` passed. |
| [UID:00025G] should not emit raw vtable/string bytes. | Current MCP `.rdata` name inventory; existing docs classify source-declared/generated-binary. | Applied. [UID:00025G] now has a source-declared/generated-binary no-raw-data marker/proof; validator `000000001967` passed. |
| [UID:00016U] is still a broad split candidate. | Current MCP boundaries/xrefs/padding; current docs list ten functions plus padding; no dedicated executed split report found. | Excluded with reason. Supervisor scope explicitly forbade splitting [UID:00016U] or treating [UID:0000G5]/[UID:0000G6] as completed in this callback. [UID:00016U], [UID:0000G5], and [UID:0000G6] remain follow-up. |
| No support docs outside HelpPanes family need edits in the first batch. | Dependency docs already own GrafPort, RectBounds, PaneSetMode, Timer wrappers, MetaMan, EventMan, and shared constants. | Applied. No dependency-owner docs outside the accepted by-* target list were edited. |

## Final Report Status

FINISHED_IMPLEMENTATION

Accepted first-batch implementation callback applied. No generated files, generated reports, coverage reports, validator/tool state, IDA DB, executed archives, supervisor ledgers, lock files, or leases were manually edited.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B004","command_id":"000000004165","destination_path":"executed-b-agent-research/B004/0000JU-HelpPanes-empty-emitter-family-source-quality.md","details":"legacy registry reconstruction","event":"executed","source_path":"tools/leaser/Agents/Agent-B004/research/0000JU-HelpPanes-empty-emitter-family-source-quality.md","timestamp":"2026-06-30T02:37:06","uid":"0000JU"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
