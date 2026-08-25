** TARGET-REPORT-UID:00025A **
** AUTHOR-AGENT-ID:B001 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# 00025A ExchangeItemReadOnlyData Ownership / Split Research

Revision: B001-00025A final, 2026-06-12

## Finalized Report / Current Recommendation

- Current recommendation: repair the physical range boundaries, keep [UID:00025A] parent-blank, and do not create a new `ExchangeItemReadOnlyData` source owner. The corrected range is `0x00619d28-0x0061a3c4`, not `0x00619d2c-0x0061a3c8`.
- Final disposition: [UID:00025A] is a mixed source-bearing `.rdata` inventory over exchange, item-dialog, mix-dialog, callback, alert, money-edit, and resource-string subitems. It should remain `RECONSTRUCTABLE:TRUE` for now because several source-bearing subranges are still only documented through this aggregate or through non-by-memory by-type/resource pages. It should not receive `AUTOGEN_PARENT_UID` until either the range is fully split into exact children or every source-bearing subitem has a gate-clearing direct owner.
- Required action: perform a coordinated rename/range update for [UID:000259], [UID:00025A], [UID:00025B], and [UID:0003IH], then refresh generated references/coverage through the validator. Do not attach [UID:00025A] to `ExchangeDialog`, `ItemDialogs`, `ItemDialogVtableFamily`, `FunctionObjects`, `ExchangeAlertPane`, `ExchangeMoneyEditControlPane`, or `FieldMapPane`.
- Confidence: `91/100` for the boundary repair; `90/100` for leaving the aggregate parent blank; `84/100` for keeping the aggregate reconstructable pending a future full child split; `88/93` recommended post-repair score for [UID:00025A].

## Supporting Research

## Target

- Target UID: `00025A`
- Target path at assignment: `by-memory/0x00619d2c-0x0061a3c8.ExchangeItemReadOnlyData.md`
- Source queue/report row: active `Supervisor_notes.md`, Batch `B001-00025A`, from `auto-generated/-ag-memory-coverage.md`
- Current supervisor classification: `reviewed-85-but-ownership-unknown-under-review`
- Current scores and parent state: `COMPLETION:87`, `CONFIDENCE:92`, `RECONSTRUCTABLE:TRUE`, blank `AUTOGEN_PARENT_UID`
- Corrected physical path recommended by this report: `by-memory/0x00619d28-0x0061a3c4.ExchangeItemReadOnlyData.md`

## Executive Recommendation

The best result is not a direct parent assignment. IDA and PE evidence show that the current aggregate is a physical `.rdata` address neighborhood, not a source-level object owned by one original file. Its contents are real source-declared/generated-binary data, but they belong to multiple source families:

- `ExchangeDialog.cpp` family: `ExchangeDialog`, `ExchangeItemListPane`, `ExchangeAlertPane`, `ExchangeMoneyEditControlPane`, and `DLGEXC*` exchange resource strings.
- `ItemDialogs.cpp` / item-picker family: `AddItemDialog`, `AddItemWithCountDialog`, `MyItemListPane`, `MixItemDialog`, `AddMixingItemDialog`, and item/mix picker resource strings.
- `FunctionObjects.cpp` / callback-template family: the `DoubleParamMemberFunctionObject<...MixItemDialog...>` callback table at the tail.
- `FieldMapPane.cpp` family: starts at the successor COL pointer `0x0061a3c4` and must not be included in [UID:00025A].

Apply the boundary repair first. After repair, keep [UID:00025A] parent blank and keep `RECONSTRUCTABLE:TRUE` until a future full split creates exact by-memory children for the remaining source-bearing ExchangeDialog, ExchangeItemListPane, resource-string, and callback subranges. Reclassifying [UID:00025A] to `RECONSTRUCTABLE:FALSE` now would be premature because not every source-bearing piece inside the aggregate has an exact replacement by-memory child with a gate-clearing direct parent.

## Supervisor Active Recheck

The supervisor assigned one target: [UID:00025A] `0x00619d2c-0x0061a3c8.ExchangeItemReadOnlyData`. C001 had already raised it to `87/92` and left parent blank because the aggregate is mixed.

This B001 pass found two concrete range-boundary issues:

- The 4 bytes before the current start, `0x00619d28-0x00619d2c`, are the `ExchangeDialog` complete-object locator pointer. They belong to [UID:00025A], not to the predecessor [UID:000259] ExceptionHandler diagnostics range.
- The 4 bytes before the current successor start, `0x0061a3c4-0x0061a3c8`, are the `FieldMapPane` complete-object locator pointer. They belong to successor [UID:00025B], not to [UID:00025A].

The pass also found that the callback vtable child [UID:0003IH] currently ends at `0x0061a3c0` but IDA/PE bytes show one additional callback/helper slot at `0x0061a3c0 -> 0x004673f0`; the corrected callback record is `0x0061a3ac-0x0061a3c4`.

No by-* documentation was edited in this pass. The required repair touches a predecessor, the assigned target, a successor, one by-type callback page, generated references, and coverage rows; this report gives exact supervisor-actionable text for a coordinated execution pass.

## Inference Research Guidance Check

`by-structure.md` requires direct parent assignments to reflect the true semantic owner, not the nearest by-file or broad generated output root. It also requires mixed containers to be classified based on whether the container itself is a source-level object.

For [UID:00025A]:

- IDA fact: the range contains multiple class vtables, callback vtable data, and UTF-16 resource strings from several direct source owners.
- Documentation evidence: `by-file/ExchangeDialog.md`, `by-file/ItemDialogs.md`, `by-type/by-vtable/ItemDialogVtableFamily.md`, and the exact alert/money children already reject one-owner treatment.
- Inference: no one existing parent should receive the aggregate. If the project later wants to eliminate the parent-blank aggregate, the right path is a physical child split, not a new umbrella source file.

`inference_research.md` also cautions that final-binary adjacency in `.rdata` is weak ownership evidence by itself. The stronger evidence here is not adjacency alone; it is the combination of RTTI COL pointers, constructor vptr stores, direct IDA xrefs, resource-string consumers, existing source-tree split, and successor/predecessor boundary bytes.

## Evidence Standards Used

- IDA MCP evidence used: `server_health`, `idb_meta`, `entity_query`, `xrefs_to`, `lookup_funcs`, and byte reads around the target boundaries.
- PE evidence used: file-section mapping for `.rdata`, little-endian dword inspection, VA/RVA pointer scans, and direct UTF-16 decoding of the resource strings.
- Documentation evidence used: assigned target page, neighboring by-memory pages [UID:000259] and [UID:00025B], exact children [UID:0002NF] and [UID:0003BK], by-type vtable children [UID:0003ID], [UID:0003IE], [UID:0003IG], [UID:0003IF], [UID:0003IH], source-tree notes for `ExchangeDialog.cpp`, `ItemDialogs.cpp`, `FunctionObjects.cpp`, and `FieldMapPane.cpp`.
- Negative evidence used: no single constructor, vtable family, source-tree source, resource page, class, by-file page, or by-type page covers every subrange; no PE RVA/relative pointer evidence created a hidden one-owner table.

## IDA MCP Facts

Function/range facts:

- Active MCP session: `b001_nexustk`, input `NexusTK.exe`, imagebase `0x00400000`, Hex-Rays ready.
- Current target lies in `.rdata`.
- `entity_query names 0x00619d20-0x0061a3d0` reports named anchors from `??_7ExchangeDialog@@6B@` at `0x00619d2c` through `??_7FieldMapPane@@6B@` at `0x0061a3c8`.
- `entity_query names 0x00619d10-0x00619d30` reports `aSymsetoptions` at `0x00619d18` and `??_7ExchangeDialog@@6B@` at `0x00619d2c`.
- `entity_query names 0x006471e0-0x00647230` reports `??_R4ExchangeDialog@@6B@` at `0x00647204`.
- `entity_query names 0x00647760-0x006477a0` reports `??_R4FieldMapPane@@6B@` at `0x00647788`.

Boundary byte facts:

- Bytes at `0x00619d10` decode `SymSetOptions` ending before a dword at `0x00619d28`.
- Dword at `0x00619d28` is `0x00647204`, the `ExchangeDialog` primary COL pointer.
- Dword at `0x00619d2c` is `0x004b0a20`, the first `ExchangeDialog` vtable slot.
- Dwords at `0x0061a3ac-0x0061a3c0` are `0x00647738`, `0x0049b090`, `0x004f4b10`, `0x0041b6c0`, `0x004b0880`, and `0x004673f0`.
- Dword at `0x0061a3c4` is `0x00647788`, the `FieldMapPane` primary COL pointer.
- Dword at `0x0061a3c8` is `0x004b1260`, the first `FieldMapPane` vtable slot.

String/data facts:

- `0x0061a304`: UTF-16 `DLGEXC1.PAL`
- `0x0061a31c`: UTF-16 `DLGEXC1.EPF`
- `0x0061a334`: UTF-16 `%s(%s)`
- `0x0061a344`: UTF-16 `DLGEXC2.EPF`
- `0x0061a35c`: UTF-16 `DLGEXC2.EPD`
- `0x0061a374`: UTF-16 `%hu`
- `0x0061a37c`: UTF-16 `MIXITEM.PAL`
- `0x0061a394`: UTF-16 `MIXITEM.EPF`

Xref facts:

- `xrefs_to 0x00619d28`: no direct code refs. This is normal for a COL pointer used by the vtable record, not by constructor code.
- `xrefs_to 0x00647204`: one data xref from `0x00619d28`, proving the dword is the `ExchangeDialog` COL pointer.
- `xrefs_to 0x00619d2c`: one constructor store from `0x004ac8f4` inside `0x004ac8a0`.
- `xrefs_to 0x0061a3c0`: no data-object base ref, but the dword value is `0x004673f0`, and `xrefs_to 0x004673f0` includes the data ref from `0x0061a3c0` plus other vtable data refs. `lookup_funcs 0x004673f0` identifies `sub_4673F0`, size `0x6`.
- `xrefs_to 0x00647788`: one data xref from `0x0061a3c4`, proving the dword is the `FieldMapPane` COL pointer.
- `xrefs_to 0x0061a3c8`: one constructor store from `0x004b0bf3` inside `0x004b0bb0`.

Negative IDA facts:

- No hidden start xref at `0x00619d28` makes it an independent object; its role is the COL pointer for the `0x00619d2c` vtable base.
- No hidden source owner covers all table bases and strings in `0x00619d28-0x0061a3c4`.
- No PE absolute/RVA scan produced a table owner outside the IDA xrefs already known.

## Function / Child Inventory

| Range / Item | UID / Path | Role | Reconstructable | Direct Parent | Score | Status |
| --- | --- | --- | --- | --- | --- | --- |
| `0x006196c0-0x00619d28` | [UID:000259] `ExceptionHandlerDiagnosticsReadOnlyData` | ExceptionHandler `.rdata` predecessor, after boundary repair | TRUE | [UID:0000J8] `ExceptionHandler.cpp` | `84/strong` | Recommended end repair only |
| `0x00619d28-0x00619dc4` | no exact by-memory child | `ExchangeDialog` COL/primary/secondary/tertiary vtables | TRUE | likely [UID:00004R] `ExchangeDialog`, but class is `80/82` | not split | Needs future exact child if aggregate is retired |
| `0x00619dc4-0x00619e88` | no exact by-memory child | `ExchangeItemListPane` COL/primary/secondary/tertiary vtables | TRUE | likely [UID:00004S] `ExchangeItemListPane`, but class is `78/84` | not split | Needs future exact child if aggregate is retired |
| `0x00619e88-0x00619f24` | [UID:0003ID] `AddItemDialogVtables` | AddItemDialog vtable cluster | TRUE | [UID:000007] `AddItemDialog` | `88/92` | Existing by-type child covers ownership |
| `0x00619f24-0x00619fe8` | [UID:0001Y8] `MyItemListPaneVtables` | MyItemListPane vtable cluster | TRUE | [UID:00008W] `MyItemListPane` | `87/91` page, parent `85/86` | Existing by-type child covers ownership |
| `0x00619fe8-0x0061a084` | [UID:0003IE] `AddItemWithCountDialogVtables` | AddItemWithCountDialog vtable cluster | TRUE | [UID:000008] `AddItemWithCountDialog` | `88/92` | Existing by-type child covers ownership |
| `0x0061a084-0x0061a120` | [UID:0003IG] `MixItemDialogVtables` | MixItemDialog vtable cluster | TRUE | [UID:00008J] `MixItemDialog` | `89/92` | Existing by-type child covers ownership |
| `0x0061a120-0x0061a1bc` | [UID:0003IF] `AddMixingItemDialogVtables` | AddMixingItemDialog vtable cluster | TRUE | [UID:000009] `AddMixingItemDialog` | `88/92` | Existing by-type child covers ownership |
| `0x0061a1c0-0x0061a260` | [UID:0002NF] `ExchangeAlertPaneVtableData` | ExchangeAlertPane exact by-memory vtable data | TRUE | [UID:00004Q] `ExchangeAlertPane` | `85/91` | Existing exact child |
| `0x0061a260-0x0061a304` | [UID:0003BK] `ExchangeMoneyEditControlPaneVtableData` | ExchangeMoneyEditControlPane exact by-memory vtable data | TRUE | [UID:00004T] `ExchangeMoneyEditControlPane` | `86/92` | Existing exact child |
| `0x0061a304-0x0061a344` | [UID:0001RA] resource documentation only | Exchange dialog resource strings | TRUE / resource-derived or source-declared string refs | [UID:0000J9] `ExchangeDialog.cpp` resource surface | `80/90` resource page | Future by-memory split optional |
| `0x0061a344-0x0061a37c` | no exact by-memory child | item/add-with-count resource strings | TRUE / resource-derived or source-declared string refs | likely `ItemDialogs.cpp` class/resource users | not split | Future exact child if aggregate is retired |
| `0x0061a37c-0x0061a3ac` | no exact by-memory child | `MIXITEM.PAL` / `MIXITEM.EPF` mix resource strings | TRUE / resource-derived or source-declared string refs | likely [UID:00008J] `MixItemDialog` / `ItemDialogs.cpp` | not split | Future exact child if aggregate is retired |
| `0x0061a3ac-0x0061a3c4` | [UID:0003IH] `MixItemDialogDoubleParamCallbackVtable` | callback-template vtable; currently missing tail slot in doc | TRUE | [UID:000041] callback class | `87/91` current, `88/92` recommended | Needs range/slot repair |
| `0x0061a3c4-0x0061a45c` | [UID:00025B] `FieldMapPaneReadOnlyData` | FieldMapPane successor, after boundary repair | TRUE | [UID:00004U] `FieldMapPane` | `80/strong` | Recommended start repair only |

## Direct Xref / Caller Inventory

| Address / Item | Xref / Caller / Callee | Meaning |
| --- | --- | --- |
| `0x00619d2c`, `0x00619d8c`, `0x00619dbc` | `0x004ac8a0` constructor stores | `ExchangeDialog` table cluster |
| `0x00619dc8`, `0x00619e50`, `0x00619e80` | stores from `0x004ac8a0` and raw helper `0x004ae060` | `ExchangeItemListPane` table cluster |
| `0x00619e8c`, `0x00619eec`, `0x00619f1c` | stores from `0x004ae4c0`, `0x004ae900`, `0x004b0910`, `0x004b0970` | `AddItemDialog` table cluster and derived construction paths |
| `0x00619f28`, `0x00619fb0`, `0x00619fe0` | stores from `0x004aeb30` | `MyItemListPane` table cluster |
| `0x00619fec`, `0x0061a04c`, `0x0061a07c` | stores from `0x004af040` | `AddItemWithCountDialog` table cluster |
| `0x0061a088`, `0x0061a0e8`, `0x0061a118` | stores from `0x004af570` | `MixItemDialog` table cluster |
| `0x0061a124`, `0x0061a184`, `0x0061a1b4` | stores from `0x004af8b0` and `0x004b0000` | `AddMixingItemDialog` table cluster |
| `0x0061a1c0`, `0x0061a228`, `0x0061a258` | stores from `0x004b0490` | `ExchangeAlertPane` exact child |
| `0x0061a264`, `0x0061a2cc`, `0x0061a2fc` | stores from `0x004ac8a0` and `0x004b0a60` | `ExchangeMoneyEditControlPane` exact child |
| `0x0061a304`, `0x0061a31c`, `0x0061a334` | refs from `0x004ac8a0` | exchange resource strings |
| `0x0061a344`, `0x0061a35c`, `0x0061a374` | refs from `0x004ae4c0` and `0x004af380` | add-item/add-with-count resource strings |
| `0x0061a37c`, `0x0061a394` | refs from `0x004af570` | mix item resource strings |
| `0x0061a3b0` | refs from `0x004afcc0` and `0x004b0120` | callback-template vtable base |
| `0x0061a3c8` | ref from `0x004b0bb0` | FieldMapPane successor vtable base |

## Documentation Evidence And IDA Status

Existing docs that support the conclusion:

- `by-file/ExchangeDialog.md` already treats `ExchangeDialog`, `ExchangeItemListPane`, `ExchangeMoneyEditControlPane`, `ExchangeAlertPane`, and `g_pExchangeAlertPane` as the exchange source family, but rejects ownership of the generic item/mix picker vtables.
- `by-file/ItemDialogs.md` and `by-project-structure/proposed-source-tree.md` keep `AddItemDialog`, `AddItemWithCountDialog`, `MyItemListPane`, `MixItemDialog`, and `AddMixingItemDialog` with item-dialog and mix-dialog support rather than exchange ownership.
- `by-type/by-vtable/ItemDialogVtableFamily.md` is already an ignored/non-emitting mixed-owner index with exact source-local child vtable pages for the item-dialog family.
- [UID:0002NF] and [UID:0003BK] are exact by-memory children for the exchange alert and exchange money edit control vtable clusters.
- `by-resource/exchange-dialog-resources.md` confirms `DLGEXC1.PAL` at `0x0061a304`, `DLGEXC1.EPF` at `0x0061a31c`, and nearby `MIXITEM.PAL`/`MIXITEM.EPF` strings, while keeping item-picker resources out of the exchange resource owner.
- `by-project-structure/proposed-source-tree.md` explicitly lists `ui/dialogs/ExchangeDialog.cpp`, `ui/dialogs/ItemDialogs.cpp`, `ui/dialogs/MyItemListPane.cpp`, `ui/dialogs/MixItemDialog.cpp`, `util/FunctionObjects.cpp`, and `map/FieldMapPane.cpp` as separate source families.

Existing docs that are stale, incomplete, or contradicted:

- [UID:000259] currently ends at `0x00619d2c`, but `0x00619d28-0x00619d2c` is the `ExchangeDialog` COL pointer.
- [UID:00025A] currently starts at `0x00619d2c`, missing the `ExchangeDialog` COL pointer.
- [UID:00025A] currently ends at `0x0061a3c8`, but `0x0061a3c4-0x0061a3c8` is the `FieldMapPane` COL pointer.
- [UID:00025B] currently starts at `0x0061a3c8`, missing the `FieldMapPane` COL pointer.
- [UID:0003IH] currently documents `0x0061a3ac-0x0061a3c0`, but the table has an additional tail slot at `0x0061a3c0 -> 0x004673f0` and ends before `0x0061a3c4`.
- `by-class/ExchangeDialog.md` is only `80/82`, and `by-class/ExchangeItemListPane.md` is only `78/84`. Those class gates block safe assignment of future exact vtable children until the class pages are repaired.

Generated/coverage report state:

- Current `auto-generated/-ag-memory-coverage.md` shows [UID:00025A] unassigned.
- Current `by-memory/-coverage-report.md` rows use old boundaries for [UID:000259], [UID:00025A], and [UID:00025B].
- Current `by-type/by-vtable/-coverage-report.md` row for [UID:0003IH] uses the stale `0x0061a3ac-0x0061a3c0` range.

## Ranked Ownership Analysis

### 1. Mixed aggregate with blank parent after boundary repair

Evidence for:

- IDA confirms several direct vtable families and resource string groups inside one physical `.rdata` run.
- The source-tree model and current by-file docs split the contents across `ExchangeDialog.cpp`, `ItemDialogs.cpp`, `MyItemListPane.cpp`, `MixItemDialog.cpp`, `FunctionObjects.cpp`, and `FieldMapPane.cpp`.
- Existing exact children already assign some subranges to narrower owners, which would be contradicted by assigning the aggregate to a single parent.
- The corrected start/end boundaries are based on RTTI COL pointer bytes, not on semantic guesswork.

Evidence against:

- The aggregate remains `RECONSTRUCTABLE:TRUE`, so it will continue to appear as unassigned until fully split or reclassified.
- A full physical split would be cleaner but would require new children and parent repairs for `ExchangeDialog` and `ExchangeItemListPane`, whose class pages are currently below the assignment gate.

Decision: best current disposition. Repair boundaries, keep parent blank, and defer full split to a coordinated child-creation batch.

Confidence: `90/100`.

### 2. Assign the aggregate to [UID:0000J9] `ExchangeDialog.cpp`

Evidence for:

- The range begins with `ExchangeDialog` and `ExchangeItemListPane` vtables.
- Exact children for `ExchangeAlertPane` and `ExchangeMoneyEditControlPane` are exchange-owned.
- Exchange resource strings begin at `0x0061a304`.
- `by-file/ExchangeDialog.md` is a high-confidence file owner for the exchange-specific subranges.

Evidence against:

- IDA confirms large middle subranges are item-picker and mix-picker vtables, not exchange-specific code.
- `by-file/ExchangeDialog.md` and proposed source-tree notes explicitly keep `AddItemDialog` and `AddItemWithCountDialog` in `ItemDialogs.cpp`.
- `MyItemListPane` is reusable and documented under its own item-list source family, not private exchange ownership.
- `MIXITEM.PAL` and `MIXITEM.EPF` are not exchange-dialog resources.

Decision: reject aggregate assignment. Use `ExchangeDialog.cpp` only for the exchange-specific children and resource strings.

Confidence: `82/100` rejection.

### 3. Assign the aggregate to [UID:0000KE] `ItemDialogs.cpp` or [UID:0001XV] `ItemDialogVtableFamily`

Evidence for:

- The range contains several exact item-dialog vtable clusters.
- The item-dialog family index explicitly covers `AddItemDialog`, `AddItemWithCountDialog`, `MixItemDialog`, `AddMixingItemDialog`, and the mix callback.
- Resource strings after `0x0061a344` are item/mix dialog strings.

Evidence against:

- The range starts with `ExchangeDialog` and `ExchangeItemListPane`, includes exact `ExchangeAlertPane` and `ExchangeMoneyEditControlPane` vtable data, and ends before `FieldMapPane`.
- `ItemDialogVtableFamily` is an ignored/non-emitting by-type index, not a direct source owner for exchange resource strings or exchange control vtables.
- Existing exchange-specific pages already reject ownership by generic item dialogs.

Decision: reject aggregate assignment. The item-dialog family remains a sub-owner for exact vtable children only.

Confidence: `84/100` rejection.

### 4. Assign the aggregate to [UID:0000JO] `FunctionObjects.cpp` or [UID:000041] callback class

Evidence for:

- The corrected tail includes `0x0061a3ac-0x0061a3c4`, a `DoubleParamMemberFunctionObject<...MixItemDialog...>` callback-template vtable record.
- `by-project-structure/proposed-source-tree.md` gives `FunctionObjects.cpp` as the migration owner for shared callback-object utility support.

Evidence against:

- The callback table is only the tail of the aggregate.
- Constructor references at `0x004afcc0` and `0x004b0120` make it source-local to the mix dialog flow, while the template mechanics are represented by the callback class page.
- FunctionObjects ownership cannot explain the exchange and item-dialog vtable clusters or the resource strings.

Decision: reject aggregate assignment. Repair [UID:0003IH] to include its missing tail slot.

Confidence: `86/100` rejection.

### 5. Assign the aggregate to [UID:00004U] `FieldMapPane` or [UID:0000JA] `FieldMapPane.cpp`

Evidence for:

- The current [UID:00025A] end incorrectly includes `0x0061a3c4-0x0061a3c8`, the `FieldMapPane` COL pointer.
- The successor vtable base `0x0061a3c8` is directly referenced by the `FieldMapPane` constructor path.

Evidence against:

- `FieldMapPane` begins at `0x0061a3c4` after correction and owns none of the preceding exchange/item/mix data.
- The current inclusion is a boundary error, not source ownership.

Decision: reject aggregate assignment. Move `0x0061a3c4` into [UID:00025B].

Confidence: `94/100` rejection.

### Proposed new file/grouping

Proposed owner/name/path: no new source file is recommended.

Rejected possible grouping: `ExchangeItemReadOnlyData.cpp`, `ExchangeItemRdata.cpp`, or a new by-file/source owner for the whole physical run.

Likely full contents if such a grouping were created:

- It would contain only a linker-adjacent run of vtables, RTTI COL pointers, callback-template table data, and resource string literals from multiple existing source families.
- It would duplicate existing source owners rather than represent a plausible original `.cpp`.

Candidate related items that belong to future exact children instead:

- `0x00619d28-0x00619dc4`: future exact `ExchangeDialogVtableData`, after [UID:00004R] is repaired above the parent gate.
- `0x00619dc4-0x00619e88`: future exact `ExchangeItemListPaneVtableData`, after [UID:00004S] is repaired above the parent gate.
- `0x0061a304-0x0061a344`: future exchange resource-string child under the `ExchangeDialog.cpp` resource surface.
- `0x0061a344-0x0061a37c`: future item/add-with-count resource-string child under the item-dialog resource surface.
- `0x0061a37c-0x0061a3ac`: future mix resource-string child under `MixItemDialog` / `ItemDialogs.cpp`.
- `0x0061a3ac-0x0061a3c4`: corrected [UID:0003IH] callback vtable record.

Standalone, narrow, or broad source-file inference: no standalone or broad source-file inference is justified. If a grouping is needed, it should be a non-emitting physical split plan or inventory, not a source module.

## Negative Evidence Summary

- Consumer/read xrefs prove sub-owner use, not aggregate ownership. Constructor stores identify class vtables, but the constructors are from different source families.
- Address adjacency is not treated as same-file proof. The range is linker-adjacent `.rdata` containing RTTI, vtables, strings, and a callback template record.
- Existing documentation that names the aggregate `ExchangeItemReadOnlyData` is a convenient summary, not proof of an original source object.
- No hidden PE pointer table or RVA reference was found that wraps the full aggregate as one source-declared array.
- No single by-class, by-file, by-type, by-global, by-resource, or by-memory page currently covers all contents without contradicting existing exact child ownership.
- Reclassifying [UID:00025A] to `RECONSTRUCTABLE:FALSE` is not safe yet because remaining source-bearing pieces do not all have exact by-memory child replacements and two direct class parents are below the `85/85` gate.

## Final Recommendation

Exact changes recommended:

1. Rename/update [UID:000259] from `by-memory/0x006196c0-0x00619d2c.ExceptionHandlerDiagnosticsReadOnlyData.md` to `by-memory/0x006196c0-0x00619d28.ExceptionHandlerDiagnosticsReadOnlyData.md`.
2. Rename/update [UID:00025A] from `by-memory/0x00619d2c-0x0061a3c8.ExchangeItemReadOnlyData.md` to `by-memory/0x00619d28-0x0061a3c4.ExchangeItemReadOnlyData.md`.
3. Rename/update [UID:00025B] from `by-memory/0x0061a3c8-0x0061a45c.FieldMapPaneReadOnlyData.md` to `by-memory/0x0061a3c4-0x0061a45c.FieldMapPaneReadOnlyData.md`.
4. Update [UID:0003IH] `by-type/by-vtable/MixItemDialogDoubleParamCallbackVtable.md` from `0x0061a3ac-0x0061a3c0` to `0x0061a3ac-0x0061a3c4` and document the extra slot `0x0061a3c0 -> 0x004673f0`.
5. Update [UID:0001XV] `ItemDialogVtableFamily` references to [UID:0003IH] so the callback child range ends at `0x0061a3c4`.
6. Keep [UID:00025A] `RECONSTRUCTABLE:TRUE`, blank parent, and blank C++ code.
7. Raise [UID:00025A] to `COMPLETION:88`, `CONFIDENCE:93` only after the corrected range and boundary evidence are written into the page. Do not raise to `95+`.
8. Raise [UID:0003IH] to `88/92` only after the extra slot and successor boundary are written into the page.

Exact parent assignments recommended:

- [UID:00025A]: no parent assignment.
- [UID:000259]: keep existing parent [UID:0000J8].
- [UID:00025B]: keep existing parent [UID:00004U].
- [UID:0003IH]: keep existing parent [UID:000041].

Exact items left unassigned and why:

- [UID:00025A] remains unassigned because it is a mixed physical `.rdata` inventory. Its real sub-owners are the direct source/class/type/resource pages listed above.

Future work outside this assignment:

- Repair [UID:00004R] `ExchangeDialog` and [UID:00004S] `ExchangeItemListPane` to `85/85+`, then consider creating exact by-memory vtable children for their subranges.
- Consider splitting resource-string subranges only if the supervisor wants [UID:00025A] retired as a non-emitting inventory.
- After all source-bearing exact children exist, re-evaluate whether [UID:00025A] should become `RECONSTRUCTABLE:FALSE`.

## Supervisor-Actionable Coverage And Generated Row Text

Do not edit `by-memory/-coverage-report.md` manually as part of this B001 report. If the supervisor applies the boundary repair, replace the three rows around [UID:000259], [UID:00025A], and [UID:00025B] in address order, between the existing [UID:0003I8] EventMan row and [UID:00025C] FolderSelect row. Keep the existing [UID:0002NF] and [UID:0003BK] child rows nested below [UID:00025A].

```text
    - [UID:000259][0x006196c0-0x00619d28.ExceptionHandlerDiagnosticsReadOnlyData](by-memory/0x006196c0-0x00619d28.ExceptionHandlerDiagnosticsReadOnlyData.md) 0x006196c0-0x00619d28 | vtable/string-data | ExceptionHandlerDiagnosticsReadOnlyData : reconstructable : 84% : strong : ExceptionHandler `.rdata` island with source-module attachment, constructor vtable evidence, exact exception-code static-name consumers, crash-report/logical-address/stack-output format consumers, ImageHlp API-name resolver evidence, adjacent Error/Event boundaries, and a corrected successor boundary ending before the ExchangeDialog COL pointer at 0x00619d28; final literal ordering and declaration shapes remain open.
    - [UID:00025A][0x00619d28-0x0061a3c4.ExchangeItemReadOnlyData](by-memory/0x00619d28-0x0061a3c4.ExchangeItemReadOnlyData.md) 0x00619d28-0x0061a3c4 | vtable/string-data | ExchangeItemReadOnlyData : reconstructable : 88% : very strong : Reviewed mixed exchange/item/mix `.rdata` aggregate starting at the ExchangeDialog primary COL pointer 0x00619d28 and ending before the FieldMapPane primary COL pointer 0x0061a3c4; B001-00025A live IDA/PE checks reconfirmed the vtable-island map, constructor/store refs, byte-backed resource-string boundary at 0x0061a304, corrected callback tail slot 0x0061a3c0 -> 0x004673f0, exact ExchangeAlertPane and ExchangeMoneyEditControlPane children, and no-parent gate because ExchangeDialog, ExchangeItemListPane, ItemDialogs/ItemDialogVtableFamily, MyItemListPane, ExchangeAlertPane, ExchangeMoneyEditControlPane, FunctionObjects, and FieldMapPane own only subranges.
    - [UID:00025B][0x0061a3c4-0x0061a45c.FieldMapPaneReadOnlyData](by-memory/0x0061a3c4-0x0061a45c.FieldMapPaneReadOnlyData.md) 0x0061a3c4-0x0061a45c | vtable/string-data | FieldMapPaneReadOnlyData : reconstructable : 80% : strong : FieldMapPane read-only vtable/string data attached to FieldMapPane; corrected to start at the primary COL pointer 0x0061a3c4 before vtable base 0x0061a3c8, with exact primary/secondary/tertiary vtable views, constructor/vtable-slot evidence chain, boundary/successor notes, aE_0/aPf_1 string-fragment caveats, source-declared/generated-binary handling, and final C++ blank gate documented.
```

Recommended by-type coverage replacement row for [UID:0003IH] in `by-type/by-vtable/-coverage-report.md`, replacing the current `0x0061a3ac-0x0061a3c0` row:

```text
- [UID:0003IH][MixItemDialogDoubleParamCallbackVtable](by-type/by-vtable/MixItemDialogDoubleParamCallbackVtable.md) : reconstructable : 88% : very-strong : Source-local `DoubleParamMemberFunctionObject<...MixItemDialog...>` callback-template vtable page routed to [UID:000041][DoubleParamMemberFunctionObject_void____thiscall_MixItemDialog_____unsigne__h9ece1f1df45d](by-class/DoubleParamMemberFunctionObject_void____thiscall_MixItemDialog_____unsigne__h9ece1f1df45d.md) after child/direct parent cleared the strict gate; B001-00025A live IDA confirms the corrected `0x0061a3ac-0x0061a3c4` record, construction stores, invoke slot at `0x0061a3bc`, additional shared-helper slot `0x0061a3c0 -> 0x004673f0`, unique signature, and FieldMapPane COL successor at `0x0061a3c4`.
```

Expected generated `auto-generated/-ag-memory-coverage.md` rows after by-memory rename/validation, included for supervisor checking only:

```text
| [UID:000259][0x006196c0-0x00619d28.ExceptionHandlerDiagnosticsReadOnlyData](by-memory/0x006196c0-0x00619d28.ExceptionHandlerDiagnosticsReadOnlyData.md) | assigned | `0000J8` |  | no | `auto-generated/NexusTK/platform/ExceptionHandler.cpp` | `by-memory/0x006196c0-0x00619d28.ExceptionHandlerDiagnosticsReadOnlyData.md` |  |
| [UID:00025A][0x00619d28-0x0061a3c4.ExchangeItemReadOnlyData](by-memory/0x00619d28-0x0061a3c4.ExchangeItemReadOnlyData.md) | unassigned |  |  | no |  | `by-memory/0x00619d28-0x0061a3c4.ExchangeItemReadOnlyData.md` |  |
| [UID:00025B][0x0061a3c4-0x0061a45c.FieldMapPaneReadOnlyData](by-memory/0x0061a3c4-0x0061a45c.FieldMapPaneReadOnlyData.md) | assigned | `00004U` |  | no | `auto-generated/NexusTK/map/FieldMapPane.cpp` | `by-memory/0x0061a3c4-0x0061a45c.FieldMapPaneReadOnlyData.md` |  |
```

## Follow-Up Actions

Supervisor actions:

- Lease and rename/update [UID:000259], [UID:00025A], [UID:00025B], [UID:0003IH], and [UID:0001XV] together.
- Apply the coverage-report row changes above after the by-* files validate.
- Run validator on every renamed/edited file with `--apply` so UID annotations and generated references update.
- Move this report to `research/executed/` only after the recommendations are accepted/applied or explicitly rejected.

A-agent actions:

- Repair [UID:00004R] `ExchangeDialog` and [UID:00004S] `ExchangeItemListPane` above `85/85` before assigning future exact vtable child pages.
- If the project wants [UID:00025A] removed from unassigned status, create exact child pages for the remaining ExchangeDialog, ExchangeItemListPane, resource-string, and callback/resource subranges first, then re-evaluate the aggregate as a non-emitting inventory.

B001 future research actions:

- No additional B001 ownership task is needed for [UID:00025A] after the boundary repair unless the supervisor requests the full physical split.

## Confidence

- Boundary repair confidence: `91/100`. The start and end fixes are backed by literal bytes, RTTI COL pointer targets, IDA names, and data xrefs to COL records.
- Parent-blank aggregate confidence: `90/100`. No candidate owner covers the full corrected range without contradicting exact child ownership and source-tree separation.
- Reconstructable-true interim confidence: `84/100`. The aggregate is mixed, but not all source-bearing subitems have exact by-memory replacement children yet. Keeping it TRUE is a conservative coverage choice until full split.
- [UID:00025A] score recommendation: `88/93`. The boundary evidence improves confidence, but unsplit subranges and parent gate blockers keep it below final-audit levels.
- [UID:0003IH] score recommendation: `88/92` after repair. The omitted slot is now identified, but callback template source shape and exact original declarations remain below final-code confidence.
- Remaining uncertainty: exact original source spelling and declaration ordering for the vtable/resource subitems are not recoverable from the current binary evidence; future PDB/linker-map/source artifacts would be the only route to confirmed original file-level declaration order.

## Validator Results

- Command run:

> Executable block R001 was removed from this report and preserved verbatim in [00025A-ExchangeItemReadOnlyData-B001-00025A-removed.md](00025A-ExchangeItemReadOnlyData-B001-00025A-removed.md). The archived block is non-authoritative and must not be executed.

- Result: dry-run file validation scanned the current target, confirmed [UID:00025A] UID header exists, and reported the target file `ok`.
- No `--apply` run was performed because this B001 pass did not edit by-* files and the coverage/generator changes must be applied by the supervisor in a coordinated rename pass.
- No unresolved validator warnings/errors were introduced by this report.

## Changed Files

- Created: `tools/leaser/Agents/Agent-B001/research/00025A-ExchangeItemReadOnlyData-B001-00025A.md`
- Modified: none outside the B001 research folder.
- Renamed: none.
- Moved to executed: none; supervisor should move after applying or rejecting the recommendations.

## Supervisor Execution Result

- 2026-06-12 supervisor accepted and applied the recommended boundary/range repair.
- Renamed [UID:000259] to `by-memory/0x006196c0-0x00619d28.ExceptionHandlerDiagnosticsReadOnlyData.md`.
- Renamed [UID:00025A] to `by-memory/0x00619d28-0x0061a3c4.ExchangeItemReadOnlyData.md`, raised it to `88/93`, kept `RECONSTRUCTABLE:TRUE`, and left `AUTOGEN_PARENT_UID` blank.
- Renamed [UID:00025B] to `by-memory/0x0061a3c4-0x0061a45c.FieldMapPaneReadOnlyData.md`.
- Updated [UID:0003IH] `MixItemDialogDoubleParamCallbackVtable` to `0x0061a3ac-0x0061a3c4`, raised it to `88/92`, and kept parent [UID:000041].
- Updated [UID:0001XV] `ItemDialogVtableFamily`, `by-memory/-coverage-report.md`, `by-type/by-vtable/-coverage-report.md`, and the callback-template parent class note.
- Validator `--mode file --apply` completed with `ok: 1` for the renamed by-memory pages, [UID:0003IH], [UID:0001XV], both coverage reports, and the callback-template parent class.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B001","command_id":"000000004165","destination_path":"executed-b-agent-research/B001/00025A-ExchangeItemReadOnlyData-B001-00025A.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:20","uid":"00025A"} -->
<!-- {"agent":"B001","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 00025A-ExchangeItemReadOnlyData-B001-00025A-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B001/00025A-ExchangeItemReadOnlyData-B001-00025A.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"00025A"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
