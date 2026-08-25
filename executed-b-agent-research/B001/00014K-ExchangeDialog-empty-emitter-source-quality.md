** TARGET-REPORT-UID:00014K **
** AUTHOR-AGENT-ID:B001 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# 00014K ExchangeDialog Empty-Emitter Source-Quality Report

## Finalized Report / Current Recommendation

- Target: [UID:00014K] `by-memory/0x004ac8a0-0x004ae4b6.ExchangeDialog.md`.
- Assignment: `B001-revise-report-00014K-ExchangeDialog-empty-emitter-source-quality-20260628`.
- Mode: report-only. No by-* docs, generated files, coverage reports, validator/tool state, leases, or IDA database state were edited.
- Final disposition: split/container repair with child-level emission dispositions. [UID:00014K] should stop being a code emitter after exact child coverage is repaired. The page should become a non-emitting memory inventory/source-route container for the ExchangeDialog and private ExchangeItemListPane range, while each exact child either emits real first-draft C++, emits a precise covered-by marker, or is created as a deliberately non-emitting reconstructable child held below code-entry readiness.
- Recommended metadata after implementation:
  - `COMPLETION:88`
  - `CONFIDENCE:90`
  - `CANONICAL_OWNER:0000J9`
  - `RECONSTRUCTABLE:FALSE`
  - `EMITTER_UIDS:`
  - `EMITTER_POSITION_OPTIONAL:`
  - `RECONSTRUCTION_CPP CODE` blank
  - `Nested:0`
- Do not populate aggregate first-draft C++ on [UID:00014K].
- Do not use `[[CHILDREN]]` as the whole repair. Current children do not route through [UID:00014K], and several source-bearing functions/raw bodies inside the range still lack exact child pages.
- Do not use a single covered-by marker for [UID:00014K]. No child or emitted method covers the constructor, button handlers, state helpers, money/focus handlers, list-pane null/draw virtuals, and the newly confirmed raw `0x004adb10` body together.

The empty-emitter failure is real: the target has `RECONSTRUCTABLE:TRUE` and `EMITTER_UIDS:0000J9`, but its formal C++ block is blank. The correct implementation fix is to remove the aggregate emitter route after adding or updating exact child documentation, not to make the broad aggregate emit mixed method bodies. This revised report also resolves the support-child issue: no proposed new child should be created with a nonblank emitter and blank formal C++, and existing retained-helper children in this ExchangeDialog range that already have nonblank emitters and blank formal C++ should receive exact covered-by markers instead of staying empty.

## Supporting Research

### Current Target State

Current [UID:00014K] metadata:

```text
COMPLETION:85
CONFIDENCE:88
CANONICAL_OWNER:0000J9
RECONSTRUCTABLE:TRUE
EMITTER_UIDS:0000J9
RECONSTRUCTION_CPP CODE: blank
```

The target page currently says aggregate C++ is intentionally blank because exact child pages carry source/no-code decisions. That statement is partly true, but incomplete. The current range still contains source-bearing method bodies without exact child pages, and the fresh MCP pass found one additional raw retained item-update body at `0x004adb10-0x004adc96` that is not listed as a child.

Queue/generated state checked:

- `auto-generated/-ag-research-tracker.md` row: [UID:00014K] is `85/88`, combined `86.5`, reconstructable `true`, reports `0`.
- `auto-generated/-ag-coverage-report-by-memory.md` row: [UID:00014K] appears as `emits_code:false` but still `reconstructable`.
- `auto-generated/NexusTK/ui/dialogs/ExchangeDialog.cpp` currently emits [UID:00014L], [UID:00014N], [UID:00014Q], and [UID:00014S], then has an empty emitter marker for [UID:00014K].

### Documents Checked

- Target: `by-memory/0x004ac8a0-0x004ae4b6.ExchangeDialog.md`
- Source route: `by-file/ExchangeDialog.md`
- Class owners/routes: `by-class/ExchangeDialog.md`, `by-class/ExchangeItemListPane.md`
- Generated source: `auto-generated/NexusTK/ui/dialogs/ExchangeDialog.cpp`
- Tracker/coverage generated reports listed above
- Prior executed B reports for [UID:00014L], [UID:00014M], [UID:00014N], [UID:00014O], [UID:00014P], [UID:00014R], [UID:00014S], and [UID:00004S] were treated as incorporated evidence, then rechecked against current MCP where needed.

## Supervisor Active Recheck

MCP was usable on resume.

- `idb_list` returned active sessions including `b009_0001Q4_20260628`.
- Selected database: `b009_0001Q4_20260628`.
- `server_health(database='b009_0001Q4_20260628')` returned `status:"ok"`.
- IDB path: `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`.
- Auto-analysis ready: true.
- Hex-Rays ready: true.
- Strings cache ready: true.
- No MCP process, listener, session, or IDA process was started, stopped, restarted, or killed.
- Revision-time MCP recheck: the earlier `b009_0001Q4_20260628` session was no longer present. The MCP listener was still responsive, so normal MCP `idb_open` was used for `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`; it returned session `880a9892` with `server_health` `ok`, the same IDB path, auto-analysis ready, Hex-Rays ready, and strings cache ready. `entity_query`, `lookup_funcs`, `xrefs_to`, and `insn_query` were rerun against `880a9892` and matched the prior function inventory, raw-start negatives, vtable xrefs, and `0x004adb10` raw-body evidence.

## Inference Research Guidance Check

- The page is a broad physical range containing multiple source functions, exact child pages, raw retained duplicates, and private list-pane methods. Under the project source model, a broad by-memory aggregate should not emit mixed parent C++ when exact children carry method-level source.
- The source root remains [UID:0000J9] `ExchangeDialog.cpp`.
- Direct class ownership should remain narrow:
  - ExchangeDialog methods/helpers: [UID:00004R]
  - ExchangeItemListPane methods/helpers: [UID:00004S]
  - [UID:0000J9] is the file/source route, not the direct owner of every method.
- Existing generated output is a lead, not authority. It already proves the generator will surface blank emitter markers for broad/reconstructable pages with nonblank emitters and blank C++.

## IDA MCP Facts

### Function Inventory

Current `entity_query functions` for `0x004ac8a0-0x004ae4c0` returned:

| Start | IDA name | Size | Disposition impact |
| --- | --- | --- | --- |
| `0x004ac8a0` | `sub_4AC8A0` | `0x80a` | ExchangeDialog constructor, source-bearing, no exact child page. |
| `0x004ad0b0` | `sub_4AD0B0` | `0x11a` | Button action virtual, source-bearing, no exact child page. |
| `0x004ad1d0` | `sub_4AD1D0` | `0x24` | Close virtual, source-bearing, no exact child page. |
| `0x004ad200` | `sub_4AD200` | `0xfd` | Button-state helper, source-bearing, no exact child page. |
| `0x004ad320` | `sub_4AD320` | `0x493` | [UID:00014L], already emits dispatcher C++. |
| `0x004ad7d0` | `sub_4AD7D0` | `0x8f` | Key event virtual, source-bearing, no exact child page. |
| `0x004ad900` | `sub_4AD900` | `0x5f` | Cancel packet sender, source-bearing, no exact child page. |
| `0x004ad960` | `sub_4AD960` | `0xb6` | Submit money/confirm helper, source-bearing, no exact child page. |
| `0x004ada20` | `sub_4ADA20` | `0x64` | Set exchange amount helper, source-bearing, no exact child page. |
| `0x004ada90` | `sub_4ADA90` | `0x72` | [UID:00014M], retained no-route add-count helper. |
| `0x004add40` | `sub_4ADD40` | `0x11f` | [UID:00014O], retained no-route cancel-alert helper. |
| `0x004ade60` | `sub_4ADE60` | `0x14c` | [UID:00014P], retained no-route ready-alert helper. |
| `0x004adfb0` | `sub_4ADFB0` | `0xa3` | Focus-change virtual, source-bearing, no exact child page. |
| `0x004ae1b0` | `nullsub_29` | `0x3` | List-pane null virtual, needs exact child or accepted split policy. |
| `0x004ae1c0` | `sub_4AE1C0` | `0x2f6` | List-pane draw virtual, needs exact child before C++. |
| `0x004ae4c0` | `sub_4AE4C0` | `0x435` | Boundary: next AddItemDialog function, outside [UID:00014K]. |

`lookup_funcs` also confirmed these raw starts are not IDA function objects:

- `0x004adb10`
- `0x004adca0`
- `0x004ae060`
- `0x004ae0b0`
- `0x004ae170`

### Xref And Route Evidence

Positive routed method evidence:

- `0x004ac8a0`: code callers at `0x005086c0` and `0x00513a77`.
- `0x004ad0b0`: vtable data xref at `0x00619d74`.
- `0x004ad1d0`: vtable data xref at `0x00619dc0`.
- `0x004ad200`: vtable data xref at `0x00619d78`.
- `0x004ad320`: vtable data xref at `0x00619d9c`.
- `0x004ad7d0`: vtable data xref at `0x00619d94`.
- `0x004adfb0`: vtable data xref at `0x00619d84`.
- `0x004ae1b0`: vtable data xref at `0x00619e40`.
- `0x004ae1c0`: vtable data xref at `0x00619e48`.
- `0x00619dc8`: refs from constructor stores `0x004acbef`, `0x004acd9c`, and raw constructor store `0x004ae083`.
- `0x0061a304` and `0x0061a31c`: constructor refs to the exchange dialog resources.
- `0x0069b330`: refs from dispatcher, cancel/ready helpers, alert construction/clear/close helpers.

No-route retained/raw helper evidence from current `xrefs_to`:

- `0x004ada90`: zero xrefs.
- `0x004adb10`: zero xrefs.
- `0x004adca0`: zero xrefs.
- `0x004add40`: zero xrefs.
- `0x004ade60`: zero xrefs.
- `0x004ae060`: zero xrefs.
- `0x004ae0b0`: zero xrefs.
- `0x004ae170`: zero xrefs.

### Newly Confirmed Missing Raw Body

Current `insn_query 0x004adb00-0x004adca0` confirmed the gap after [UID:00014M] is not only padding:

- `0x004adb00`: `retn 4`, still inside `sub_4ADA90`.
- `0x004adb02`: alignment to `0x004adb10`.
- `0x004adb10`: raw prologue `push ebp`, not an IDA function object.
- The body parses `packet+2`, `packet+3`, `packet+4`, `packet+6`, and a counted name at `packet+7/+8`.
- It converts the counted narrow name with `MultiByteToWideChar`.
- It selects control `8` or `5` through the dialog control table.
- It scans existing list rows by key, removes a duplicate row, then inserts a row with key, item id, color, and wide name.
- `0x004adc82`: `retn 4`.
- `0x004adc85-0x004adc94`: reachable duplicate-key branch tail.
- `0x004adc96`: alignment begins.
- Recommended exact child body: `0x004adb10-0x004adc96`.
- Padding before [UID:00014N]: `0x004adc96-0x004adca0`.

This raw body is an ExchangeDialog retained duplicate of dispatcher case `2` item-row update behavior. It needs an exact child page or explicit target-row coverage. It is a concrete reason [UID:00014K] cannot be resolved by simply saying "existing children cover the aggregate."

### List-Pane Raw/Vtable Recheck

Current `insn_query 0x004ae050-0x004ae1c0` reconfirmed:

- `0x004ae060-0x004ae0a4`: raw list-pane constructor, no IDA function object.
- `0x004ae0b0-0x004ae167`: raw upsert helper, no IDA function object.
- `0x004ae170-0x004ae1ac`: raw find helper, no IDA function object.
- `0x004ae1b0-0x004ae1b3`: `retn 8` null virtual, IDA `nullsub_29`.
- Padding boundaries at `0x004ae0a4`, `0x004ae167`, `0x004ae1ac`, and `0x004ae1b3`.

`analyze_function 0x004ae1c0` confirms `sub_4AE1C0` size 758 / `0x2f6`, vtable-only route, glyph/name drawing behavior, and a source-bearing draw virtual that should be split before method-body C++.

## Heuristic / Inference Reanalysis And Validation

### 1. Aggregate First-Draft C++ Is Rejected

The target range spans:

- `ExchangeDialog` constructor and virtual methods.
- Existing exact child pages for dispatcher and retained helper dispositions.
- Raw no-function retained duplicates.
- Private `ExchangeItemListPane` constructor/helpers/virtuals.
- Padding and the boundary before AddItemDialog.

A parent C++ block would either duplicate exact child output or mix multiple classes and retained raw bodies in one by-memory aggregate. That would not be source-quality C++ for a single source item.

### 2. `[[CHILDREN]]` Alone Is Rejected

`[[CHILDREN]]` would not cover the unsplit source-bearing functions at `0x004ac8a0`, `0x004ad0b0`, `0x004ad1d0`, `0x004ad200`, `0x004ad7d0`, `0x004ad900`, `0x004ad960`, `0x004ada20`, `0x004adfb0`, `0x004ae1b0`, and `0x004ae1c0`.

It also would not account for the newly confirmed raw `0x004adb10-0x004adc96` retained item-update body. Existing child emitters currently route through [UID:00004R], [UID:00004S], and [UID:0000J9], not through [UID:00014K] as a source wrapper.

### 3. Whole-Target Covered-By Marker Is Rejected

A covered-by marker is valid for exact retained duplicates such as [UID:00014N] and [UID:00014S]. It is not valid for [UID:00014K] because no single emitted child covers every live method and private list-pane virtual in the aggregate.

### 4. Split/Container Repair Is Accepted

After child split repair, [UID:00014K] should match the established broad-aggregate pattern used by [UID:00014T] and [UID:00014V]: high-confidence inventory, no direct aggregate source body, exact child pages carry ownership/emission decisions, and parent `RECONSTRUCTABLE:FALSE`.

### 5. Source Placement Remains Stable

The implementation should keep `ExchangeDialog.cpp` as the source route. The parent [UID:00014K] can remain `CANONICAL_OWNER:0000J9` as an inventory/source-route page, while exact method children should use narrow direct owners:

- [UID:00004R] for `ExchangeDialog` methods and retained dialog helpers.
- [UID:00004S] for `ExchangeItemListPane` methods/helpers.

## Function / Child Inventory And Repair Plan

### Existing Exact Children And Support Ranges

These rows are already exact by-memory pages. The parent split should preserve existing emitted children and repair existing blank nonblank emitters in this ExchangeDialog subrange with exact markers where current evidence proves duplicate coverage.

| UID / path | Range | Owner / emitter route | Proposed state and score | Formal C++ / no-code disposition | Support docs | Validator commands after implementation |
| --- | --- | --- | --- | --- | --- | --- |
| [UID:00014L] `by-memory/0x004ad320-0x004ad7b3.ExchangeDialogPacketDispatcher.md` | `0x004ad320-0x004ad7b3` | Owner [UID:00004R]; `EMITTER_UIDS:00004R`; source route [UID:00004R] -> [UID:0000J9] | Keep `RECONSTRUCTABLE:TRUE`, `89/91` | Keep existing first-draft dispatcher C++ with inline cases `1..5`. | [UID:00014K], [UID:00004R], [UID:0000J9] should continue linking it as the live dispatcher. | `python .\tools\validator.py --mode file --file by-memory/0x004ad320-0x004ad7b3.ExchangeDialogPacketDispatcher.md --apply --queue-timeout 240` if touched. |
| [UID:00014M] `by-memory/0x004ada90-0x004adb02.ExchangeDialogAddItemWithCountHelper.md` | `0x004ada90-0x004adb02` | Owner [UID:00004R]; keep `EMITTER_UIDS:00004R` | Keep `RECONSTRUCTABLE:TRUE`, `86/90` | Replace blank formal block with covered-by marker: `// Emitted code for this retained no-route add-count helper is covered by [UID:00014L] by-memory/0x004ad320-0x004ad7b3.ExchangeDialogPacketDispatcher.md case 1.` This is now implementation-ready because current MCP and B003/B015 evidence prove zero xrefs to `0x004ada90` and equivalent inline dispatcher case `1`; a standalone method body would duplicate uncalled retained code. | Update [UID:00014M], [UID:00014K], [UID:00004R], [UID:0000J9], and [UID:00014L] relationship text. | `python .\tools\validator.py --mode file --file by-memory/0x004ada90-0x004adb02.ExchangeDialogAddItemWithCountHelper.md --apply --queue-timeout 240` |
| [UID:00014N] `by-memory/0x004adca0-0x004add34.ExchangeDialogRawMoneyUpdate.md` | `0x004adca0-0x004add34` | Owner [UID:00004R]; `EMITTER_UIDS:00004R` | Keep `RECONSTRUCTABLE:TRUE`, `88/91` | Keep existing covered-by marker for [UID:00014L] case `3`. | Preserve links from [UID:00014K], [UID:00004R], [UID:0000J9], and [UID:00014L]. | `python .\tools\validator.py --mode file --file by-memory/0x004adca0-0x004add34.ExchangeDialogRawMoneyUpdate.md --apply --queue-timeout 240` if touched. |
| [UID:00014O] `by-memory/0x004add40-0x004ade5e.ExchangeDialogCancelAlertHelper.md` | `0x004add40-0x004ade5f` half-open function; current filename uses documented final-byte spelling `0x004ade5e` | Owner [UID:00004R]; keep `EMITTER_UIDS:00004R` | Keep `RECONSTRUCTABLE:TRUE`, `86/89` | Replace blank formal block with covered-by marker: `// Emitted code for this retained no-route cancel-alert helper is covered by [UID:00014L] by-memory/0x004ad320-0x004ad7b3.ExchangeDialogPacketDispatcher.md case 4.` Current MCP and B002/B015 evidence prove no direct xrefs to `0x004add40` and equivalent inline dispatcher case `4`. Keep filename unless supervisor separately chooses half-open filename normalization. | Update [UID:00014O], [UID:00014K], [UID:00004R], [UID:0000J9], and [UID:00014L] relationship text; remove "blank below gate" wording. | `python .\tools\validator.py --mode file --file by-memory/0x004add40-0x004ade5e.ExchangeDialogCancelAlertHelper.md --apply --queue-timeout 240` |
| [UID:00014P] `by-memory/0x004ade60-0x004adfab.ExchangeDialogReadyAlertHelper.md` | `0x004ade60-0x004adfac` half-open function; current filename uses documented final-byte spelling `0x004adfab` | Owner [UID:00004R]; keep `EMITTER_UIDS:00004R` | Keep `RECONSTRUCTABLE:TRUE`, `86/89` | Replace blank formal block with covered-by marker: `// Emitted code for this retained no-route ready-alert helper is covered by [UID:00014L] by-memory/0x004ad320-0x004ad7b3.ExchangeDialogPacketDispatcher.md case 5.` Current MCP and B002/B015 evidence prove no direct xrefs to `0x004ade60` and equivalent inline dispatcher case `5`. Keep filename unless supervisor separately chooses half-open filename normalization. | Update [UID:00014P], [UID:00014K], [UID:00004R], [UID:0000J9], and [UID:00014L] relationship text; remove "blank below gate" wording. | `python .\tools\validator.py --mode file --file by-memory/0x004ade60-0x004adfab.ExchangeDialogReadyAlertHelper.md --apply --queue-timeout 240` |
| [UID:00014Q] `by-memory/0x004ae060-0x004ae0a4.ExchangeItemListPaneRawConstructor.md` | `0x004ae060-0x004ae0a4` | Owner [UID:00004S]; `EMITTER_UIDS:00004S`; source route [UID:00004S] -> [UID:0000J9] | Keep `RECONSTRUCTABLE:TRUE`, `88/90` | Keep accepted constructor first-draft C++. | Preserve [UID:00004S], [UID:0000J9], and [UID:00014K] references. | `python .\tools\validator.py --mode file --file by-memory/0x004ae060-0x004ae0a4.ExchangeItemListPaneRawConstructor.md --apply --queue-timeout 240` if touched. |
| [UID:00014R] `by-memory/0x004ae0b0-0x004ae167.ExchangeItemListPaneRawUpsertHelper.md` | `0x004ae0b0-0x004ae167` | Owner [UID:00004S]; keep `EMITTER_UIDS:00004S` | Keep `RECONSTRUCTABLE:TRUE`, `86/89` | Replace blank formal block with covered-by marker: `// Emitted code for this retained raw no-route upsert helper is covered by [UID:00014L] by-memory/0x004ad320-0x004ad7b3.ExchangeDialogPacketDispatcher.md case 2.` Current MCP, B012, and B015 evidence prove no route to `0x004ae0b0`, positive-control vtable routes only to `0x004ae1b0/0x004ae1c0`, and equivalent inline dispatcher case `2`. | Update [UID:00014R], [UID:00004S], [UID:0000J9], [UID:00014K], and [UID:00014L] relationship text; replace prose-only no-code proof with marker disposition. | `python .\tools\validator.py --mode file --file by-memory/0x004ae0b0-0x004ae167.ExchangeItemListPaneRawUpsertHelper.md --apply --queue-timeout 240` |
| [UID:00014S] `by-memory/0x004ae170-0x004ae1ac.ExchangeItemListPaneRawFindHelper.md` | `0x004ae170-0x004ae1ac` | Owner [UID:00004S]; `EMITTER_UIDS:00004S` | Keep `RECONSTRUCTABLE:TRUE`, `88/91` | Keep existing covered-by marker for [UID:00014L] case `2`. | Preserve [UID:00004S], [UID:0000J9], [UID:00014K], and [UID:00014L] references. | `python .\tools\validator.py --mode file --file by-memory/0x004ae170-0x004ae1ac.ExchangeItemListPaneRawFindHelper.md --apply --queue-timeout 240` if touched. |

### New Exact Children To Create

Do not hand-write UIDs for these new pages. During implementation, create the files, run the validator on each new file so it assigns a UID, and use `[TMP:"by-memory/..."]` references from support docs until validation resolves them.

All new source-bearing method children below are intentionally non-emitting at creation time unless they have a covered-by marker. This is not a deferral blocker: it is the implementation-ready metadata disposition for this report. They are exact reconstructable child pages that document and split the range, but they carry blank `EMITTER_UIDS` and scores held at or below the code-entry threshold, so they will not create empty nonblank emitters.

| Proposed path / title | Exact range | Owner / emitter route | Proposed state and score | Formal C++ / no-code disposition | Support docs | Validator commands after implementation |
| --- | --- | --- | --- | --- | --- | --- |
| `by-memory/0x004ac8a0-0x004ad0aa.ExchangeDialogConstructor.md` / `ExchangeDialogConstructor` | `0x004ac8a0-0x004ad0aa` | Owner [UID:00004R]; `EMITTER_UIDS:` blank; source route documented as [UID:00004R] -> [UID:0000J9] | `RECONSTRUCTABLE:TRUE`, `COMPLETION:84`, `CONFIDENCE:86` | Formal C++ blank by explicit non-emitting metadata. Score cap: constructor is source-bearing and has callers/resources/vtable stores, but the body is `0x80a`, touches many controls/resources/fields, and current child-specific report does not establish final source declarations or field names. Blank emitter route prevents an empty-emitter marker. | Add to [UID:00014K] covered ranges; add constructor child link to [UID:00004R] and [UID:0000J9]. | `python .\tools\validator.py --mode file --file by-memory/0x004ac8a0-0x004ad0aa.ExchangeDialogConstructor.md --apply --queue-timeout 240` |
| `by-memory/0x004ad0b0-0x004ad1ca.ExchangeDialogOnButtonAction.md` / `ExchangeDialogOnButtonAction` | `0x004ad0b0-0x004ad1ca` | Owner [UID:00004R]; `EMITTER_UIDS:` blank; route [UID:00004R] -> [UID:0000J9] | `RECONSTRUCTABLE:TRUE`, `83/86` | Formal C++ blank by non-emitting metadata. Score cap: vtable-routed and behaviorally understood as OK/add/cancel button handling, but the child is held below code-entry because control-id names, packet helper names, and AddItemDialog interaction source shape are still descriptive. No nonblank emitter is created. | [UID:00014K], [UID:00004R], [UID:0000J9]. | `python .\tools\validator.py --mode file --file by-memory/0x004ad0b0-0x004ad1ca.ExchangeDialogOnButtonAction.md --apply --queue-timeout 240` |
| `by-memory/0x004ad1d0-0x004ad1f4.ExchangeDialogOnClose.md` / `ExchangeDialogOnClose` | `0x004ad1d0-0x004ad1f4` | Owner [UID:00004R]; `EMITTER_UIDS:` blank; route [UID:00004R] -> [UID:0000J9] | `RECONSTRUCTABLE:TRUE`, `82/88` | Formal C++ blank by non-emitting metadata. Score cap: exact vtable-routed close callback, but source-facing close/pending-state field names and inherited callback contract are not finalized in this report. No empty emitter is created. | [UID:00014K], [UID:00004R], [UID:0000J9]. | `python .\tools\validator.py --mode file --file by-memory/0x004ad1d0-0x004ad1f4.ExchangeDialogOnClose.md --apply --queue-timeout 240` |
| `by-memory/0x004ad200-0x004ad2fd.ExchangeDialogUpdateButtonStates.md` / `ExchangeDialogUpdateButtonStates` | `0x004ad200-0x004ad2fd` | Owner [UID:00004R]; `EMITTER_UIDS:` blank; route [UID:00004R] -> [UID:0000J9] | `RECONSTRUCTABLE:TRUE`, `83/86` | Formal C++ blank by non-emitting metadata. Score cap: vtable-routed state-update helper, held below code-entry because packed state byte names and exact control enable/disable helper names remain descriptive. | [UID:00014K], [UID:00004R], [UID:0000J9]. | `python .\tools\validator.py --mode file --file by-memory/0x004ad200-0x004ad2fd.ExchangeDialogUpdateButtonStates.md --apply --queue-timeout 240` |
| `by-memory/0x004ad7d0-0x004ad85f.ExchangeDialogOnKeyEvent.md` / `ExchangeDialogOnKeyEvent` | `0x004ad7d0-0x004ad85f` | Owner [UID:00004R]; `EMITTER_UIDS:` blank; route [UID:00004R] -> [UID:0000J9] | `RECONSTRUCTABLE:TRUE`, `82/87` | Formal C++ blank by non-emitting metadata. Score cap: vtable-routed key handler and money-submit relationship are proven, held below code-entry because exact key-event signature/return semantics and local money-control helper names remain descriptive. | [UID:00014K], [UID:00004R], [UID:0000J9]. | `python .\tools\validator.py --mode file --file by-memory/0x004ad7d0-0x004ad85f.ExchangeDialogOnKeyEvent.md --apply --queue-timeout 240` |
| `by-memory/0x004ad900-0x004ad95f.ExchangeDialogSendCancelPacket.md` / `ExchangeDialogSendCancelPacket` | `0x004ad900-0x004ad95f` | Owner [UID:00004R]; `EMITTER_UIDS:` blank; route [UID:00004R] -> [UID:0000J9] | `RECONSTRUCTABLE:TRUE`, `83/87` | Formal C++ blank by non-emitting metadata. Score cap: caller from button action and opcode/subcommand role are known, held below code-entry because packet-builder helper names and packet-sender abstraction remain descriptive. | [UID:00014K], [UID:00004R], [UID:0000J9]. | `python .\tools\validator.py --mode file --file by-memory/0x004ad900-0x004ad95f.ExchangeDialogSendCancelPacket.md --apply --queue-timeout 240` |
| `by-memory/0x004ad960-0x004ada16.ExchangeDialogSubmitExchangeAmount.md` / `ExchangeDialogSubmitExchangeAmount` | `0x004ad960-0x004ada16` | Owner [UID:00004R]; `EMITTER_UIDS:` blank; route [UID:00004R] -> [UID:0000J9] | `RECONSTRUCTABLE:TRUE`, `83/87` | Formal C++ blank by non-emitting metadata. Score cap: callers from constructor/key/focus paths and money-submit role are known, but confirm/cancel fallback source shape and packet helper names are not finalized. | [UID:00014K], [UID:00004R], [UID:0000J9]. | `python .\tools\validator.py --mode file --file by-memory/0x004ad960-0x004ada16.ExchangeDialogSubmitExchangeAmount.md --apply --queue-timeout 240` |
| `by-memory/0x004ada20-0x004ada84.ExchangeDialogSetExchangeAmount.md` / `ExchangeDialogSetExchangeAmount` | `0x004ada20-0x004ada84` | Owner [UID:00004R]; `EMITTER_UIDS:` blank; route [UID:00004R] -> [UID:0000J9] | `RECONSTRUCTABLE:TRUE`, `83/87` | Formal C++ blank by non-emitting metadata. Score cap: callers and local amount/state role are known, but timer/state flag field names and helper names remain descriptive; no nonblank emitter is created. | [UID:00014K], [UID:00004R], [UID:0000J9]. | `python .\tools\validator.py --mode file --file by-memory/0x004ada20-0x004ada84.ExchangeDialogSetExchangeAmount.md --apply --queue-timeout 240` |
| `by-memory/0x004adb10-0x004adc96.ExchangeDialogRawItemUpdate.md` / `ExchangeDialogRawItemUpdate` | `0x004adb10-0x004adc96`; padding `0x004adc96-0x004adca0` | Owner [UID:00004R]; `EMITTER_UIDS:00004R`; route [UID:00004R] -> [UID:0000J9] | `RECONSTRUCTABLE:TRUE`, `88/91` | Formal covered-by marker: `// Emitted code for this retained raw item-update duplicate is covered by [UID:00014L] by-memory/0x004ad320-0x004ad7b3.ExchangeDialogPacketDispatcher.md case 2.` Current MCP proves raw no-function/no-xref status and equivalent dispatcher case `2`; marker prevents a blank emitter while preserving exact retained-body coverage. | Add to [UID:00014K], [UID:00004R], [UID:0000J9], and [UID:00014L] case-2 relationship text. | `python .\tools\validator.py --mode file --file by-memory/0x004adb10-0x004adc96.ExchangeDialogRawItemUpdate.md --apply --queue-timeout 240` |
| `by-memory/0x004adfb0-0x004ae053.ExchangeDialogOnControlFocusChange.md` / `ExchangeDialogOnControlFocusChange` | `0x004adfb0-0x004ae053` | Owner [UID:00004R]; `EMITTER_UIDS:` blank; route [UID:00004R] -> [UID:0000J9] | `RECONSTRUCTABLE:TRUE`, `82/87` | Formal C++ blank by non-emitting metadata. Score cap: vtable-routed focus-change callback and submit-money call are known, held below code-entry because inherited focus callback signature and money-control text normalization names remain descriptive. | [UID:00014K], [UID:00004R], [UID:0000J9]. | `python .\tools\validator.py --mode file --file by-memory/0x004adfb0-0x004ae053.ExchangeDialogOnControlFocusChange.md --apply --queue-timeout 240` |
| `by-memory/0x004ae1b0-0x004ae1b3.ExchangeItemListPaneNullVirtual.md` / `ExchangeItemListPaneNullVirtual` | `0x004ae1b0-0x004ae1b3`; padding `0x004ae1b3-0x004ae1c0` | Owner [UID:00004S]; `EMITTER_UIDS:` blank; route [UID:00004S] -> [UID:0000J9] | `RECONSTRUCTABLE:TRUE`, `82/88` | Formal C++ blank by non-emitting metadata. Exact no-code proof for now: bytes are only `ret 8`, primary vtable slot `0x00619e40` routes here, but the inherited ListPane callback name/signature is not proven. Emitting an arbitrarily named empty method would create false source API; blank emitter route prevents an empty-emitter marker. | Add exact child link to [UID:00004S], [UID:00014K], and [UID:0000J9]. | `python .\tools\validator.py --mode file --file by-memory/0x004ae1b0-0x004ae1b3.ExchangeItemListPaneNullVirtual.md --apply --queue-timeout 240` |
| `by-memory/0x004ae1c0-0x004ae4b6.ExchangeItemListPaneDrawItemEntry.md` / `ExchangeItemListPaneDrawItemEntry` | `0x004ae1c0-0x004ae4b6`; padding `0x004ae4b6-0x004ae4c0` | Owner [UID:00004S]; `EMITTER_UIDS:` blank; route [UID:00004S] -> [UID:0000J9] | `RECONSTRUCTABLE:TRUE`, `83/87` | Formal C++ blank by non-emitting metadata. Score cap: vtable slot `0x00619e48`, exact `0x2f6` draw body, and row reads are known, held below code-entry because inherited virtual signature, renderer helper names, and row/image helper declarations remain descriptive. No nonblank emitter is created. | Add exact child link to [UID:00004S], [UID:00014K], and [UID:0000J9]. | `python .\tools\validator.py --mode file --file by-memory/0x004ae1c0-0x004ae4b6.ExchangeItemListPaneDrawItemEntry.md --apply --queue-timeout 240` |

### Padding / Support Spans

No new emitter pages should be created for padding. The target/support docs should record these as alignment inside [UID:00014K] or adjacent child notes:

- `0x004ad0aa-0x004ad0b0` after the constructor.
- `0x004ad1ca-0x004ad1d0` after `OnButtonAction`.
- `0x004ad1f4-0x004ad200` after `OnClose`.
- `0x004ad2fd-0x004ad320` before [UID:00014L].
- `0x004ad7b3-0x004ad7d0` as dispatcher switch-table/NOP/padding support, not source body.
- `0x004ad85f-0x004ad900` after `OnKeyEvent`.
- `0x004ad95f-0x004ad960` after `SendCancelPacket`.
- `0x004ada16-0x004ada20` after `SubmitExchangeAmount`.
- `0x004ada84-0x004ada90` before [UID:00014M].
- `0x004adb02-0x004adb10` before the new raw item-update child.
- `0x004adc96-0x004adca0` before [UID:00014N].
- `0x004add34-0x004add40` before [UID:00014O].
- `0x004ade5f-0x004ade60` before [UID:00014P].
- `0x004adfac-0x004adfb0` before `OnControlFocusChange`.
- `0x004ae053-0x004ae060` before [UID:00014Q].
- Existing list-pane padding at `0x004ae0a4-0x004ae0b0`, `0x004ae167-0x004ae170`, `0x004ae1ac-0x004ae1b0`, `0x004ae1b3-0x004ae1c0`, and `0x004ae4b6-0x004ae4c0`.

## Score, Owner, Emitter, And Reconstructable Recommendations

Recommended [UID:00014K] target metadata after split/container implementation:

```text
COMPLETION:88
CONFIDENCE:90
CANONICAL_OWNER:0000J9
RECONSTRUCTABLE:FALSE
EMITTER_UIDS:
EMITTER_POSITION_OPTIONAL:
RECONSTRUCTION_CPP CODE: blank
Nested:0
```

Rationale:

- Completion rises because the current MCP pass adds exact function inventory, current vtable/xref evidence, and the missing raw `0x004adb10-0x004adc96` split.
- Confidence rises because MCP now confirms both positive routed methods and no-route raw bodies in the same live session.
- `RECONSTRUCTABLE:FALSE` is the correct aggregate classification only after the exact child pages and support-child marker repairs in the matrix above are implemented. It means the broad parent is not a source body; it does not mean the child methods are non-source.
- `EMITTER_UIDS` must be blank on [UID:00014K] so the generated source no longer produces an empty emitter marker for this broad inventory page.

## First-Draft C++ / No-Code Disposition

[UID:00014K] should not receive first-draft C++.

Target-specific no-code/metadata proof:

1. The target is an aggregate over multiple source methods and two classes, not one function or one class method.
2. Current exact children already emit or explicitly mark no-code coverage for parts of the range.
3. Current MCP found unsplit source-bearing methods and a missing retained raw item-update body.
4. A parent C++ block would duplicate child output and imply a false single source body.
5. `[[CHILDREN]]` would leave unsplit bodies uncovered.
6. A whole-target covered-by marker has no valid covering target.

Therefore the implementation-ready empty-emitter disposition is metadata/source-structure repair: convert [UID:00014K] to a non-emitting split inventory and move all code/no-code decisions to exact child pages. The child decisions are not left open: new routed method pages are deliberately non-emitting and score-capped; the new raw item-update child and existing no-route retained helpers [UID:00014M], [UID:00014O], [UID:00014P], and [UID:00014R] receive exact covered-by markers; existing emitting children [UID:00014L], [UID:00014N], [UID:00014Q], and [UID:00014S] keep their current formal C++/marker dispositions.

## Recommended Documentation Changes

### Target [UID:00014K]

- Add a current 2026-06-28 MCP recheck section naming both accepted evidence sessions: earlier `b009_0001Q4_20260628` and revision-time `880a9892`.
- Add the missing `0x004adb10-0x004adc96` raw item-update retained duplicate, its covered-by marker disposition, and padding `0x004adc96-0x004adca0`.
- Update the reconstruction note to say the page is a non-emitting split inventory after exact child repair, not an intentionally blank emitter.
- Change metadata as recommended above.
- Keep [UID:0000J9] as the source route.
- Do not add parent formal C++.
- Replace current literal unsplit method rows with TMP references to the new child pages until the validator assigns UIDs:
  - `[TMP:"by-memory/0x004ac8a0-0x004ad0aa.ExchangeDialogConstructor.md"]`
  - `[TMP:"by-memory/0x004ad0b0-0x004ad1ca.ExchangeDialogOnButtonAction.md"]`
  - `[TMP:"by-memory/0x004ad1d0-0x004ad1f4.ExchangeDialogOnClose.md"]`
  - `[TMP:"by-memory/0x004ad200-0x004ad2fd.ExchangeDialogUpdateButtonStates.md"]`
  - `[TMP:"by-memory/0x004ad7d0-0x004ad85f.ExchangeDialogOnKeyEvent.md"]`
  - `[TMP:"by-memory/0x004ad900-0x004ad95f.ExchangeDialogSendCancelPacket.md"]`
  - `[TMP:"by-memory/0x004ad960-0x004ada16.ExchangeDialogSubmitExchangeAmount.md"]`
  - `[TMP:"by-memory/0x004ada20-0x004ada84.ExchangeDialogSetExchangeAmount.md"]`
  - `[TMP:"by-memory/0x004adb10-0x004adc96.ExchangeDialogRawItemUpdate.md"]`
  - `[TMP:"by-memory/0x004adfb0-0x004ae053.ExchangeDialogOnControlFocusChange.md"]`
  - `[TMP:"by-memory/0x004ae1b0-0x004ae1b3.ExchangeItemListPaneNullVirtual.md"]`
  - `[TMP:"by-memory/0x004ae1c0-0x004ae4b6.ExchangeItemListPaneDrawItemEntry.md"]`

### Source Route [UID:0000J9]

- Add the raw `0x004adb10-0x004adc96` item-update duplicate to the packet/control model.
- State that [UID:00014K] is a non-emitting split inventory after repair and that exact child pages carry source/no-code/emitter decisions.
- Add that [UID:00014M], [UID:00014O], [UID:00014P], [UID:00014R], and the new raw item-update child are retained no-route duplicates represented by covered-by markers tied to [UID:00014L] cases `1`, `4`, `5`, `2`, and `2` respectively.
- Preserve `NexusTK/ui/dialogs/ExchangeDialog.cpp` as the source file.

### Class [UID:00004R]

- Add a method note for the raw `0x004adb10-0x004adc96` retained item-update duplicate and tie it to dispatcher case `2`.
- Add TMP links for the exact child pages for constructor, button, close, update, key, send-cancel, submit-amount, set-amount, and focus-change methods.
- Update [UID:00014M], [UID:00014O], and [UID:00014P] method notes to say their formal C++ blocks now contain covered-by markers tied to [UID:00014L] cases `1`, `4`, and `5`, not blank-source placeholders.

### Class [UID:00004S]

- Add TMP links for `0x004ae1b0-0x004ae1b3.ExchangeItemListPaneNullVirtual.md` and `0x004ae1c0-0x004ae4b6.ExchangeItemListPaneDrawItemEntry.md`.
- Update [UID:00014R] notes to say its formal C++ block now contains a covered-by marker tied to [UID:00014L] case `2`, while the new null/draw child pages are non-emitting score-capped pages.

### Generated/Coverage Files

- Do not hand-edit generated files or coverage reports in the implementation callback.
- After validator/generator refresh, `auto-generated/NexusTK/ui/dialogs/ExchangeDialog.cpp` should no longer include empty markers for [UID:00014K], [UID:00014M], [UID:00014O], [UID:00014P], or [UID:00014R].
- New non-emitting method child pages should not produce empty emitter markers because their `EMITTER_UIDS` are blank.

## Implementation Callback Checklist

- [x] Reconfirmed MCP availability before implementation. The stale `b009_0001Q4_20260628`/`880a9892` handles were not usable for live queries, so normal MCP `idb_open` reopened `E:\NTK\Resources\NexusTK\NexusTK.exe.i64` as `B001_00014K_20260628`; `server_health` was `ok`, auto-analysis ready, Hex-Rays ready, and strings cache ready. The target page preserves both accepted sessions and the implementation-time session.
- [x] Created the accepted non-emitting exact child pages:
  - [x] [UID:00049P] `by-memory/0x004ac8a0-0x004ad0aa.ExchangeDialogConstructor.md`, `84/86`, owner [UID:00004R], `RECONSTRUCTABLE:TRUE`, blank `EMITTER_UIDS`, blank C++.
  - [x] [UID:00049Q] `by-memory/0x004ad0b0-0x004ad1ca.ExchangeDialogOnButtonAction.md`, `83/86`, owner [UID:00004R], `RECONSTRUCTABLE:TRUE`, blank `EMITTER_UIDS`, blank C++.
  - [x] [UID:00049R] `by-memory/0x004ad1d0-0x004ad1f4.ExchangeDialogOnClose.md`, `82/88`, owner [UID:00004R], `RECONSTRUCTABLE:TRUE`, blank `EMITTER_UIDS`, blank C++.
  - [x] [UID:00049S] `by-memory/0x004ad200-0x004ad2fd.ExchangeDialogUpdateButtonStates.md`, `83/86`, owner [UID:00004R], `RECONSTRUCTABLE:TRUE`, blank `EMITTER_UIDS`, blank C++.
  - [x] [UID:00049T] `by-memory/0x004ad7d0-0x004ad85f.ExchangeDialogOnKeyEvent.md`, `82/87`, owner [UID:00004R], `RECONSTRUCTABLE:TRUE`, blank `EMITTER_UIDS`, blank C++.
  - [x] [UID:00049U] `by-memory/0x004ad900-0x004ad95f.ExchangeDialogSendCancelPacket.md`, `83/87`, owner [UID:00004R], `RECONSTRUCTABLE:TRUE`, blank `EMITTER_UIDS`, blank C++.
  - [x] [UID:00049V] `by-memory/0x004ad960-0x004ada16.ExchangeDialogSubmitExchangeAmount.md`, `83/87`, owner [UID:00004R], `RECONSTRUCTABLE:TRUE`, blank `EMITTER_UIDS`, blank C++.
  - [x] [UID:00049W] `by-memory/0x004ada20-0x004ada84.ExchangeDialogSetExchangeAmount.md`, `83/87`, owner [UID:00004R], `RECONSTRUCTABLE:TRUE`, blank `EMITTER_UIDS`, blank C++.
  - [x] [UID:00049Y] `by-memory/0x004adfb0-0x004ae053.ExchangeDialogOnControlFocusChange.md`, `82/87`, owner [UID:00004R], `RECONSTRUCTABLE:TRUE`, blank `EMITTER_UIDS`, blank C++.
  - [x] [UID:00049Z] `by-memory/0x004ae1b0-0x004ae1b3.ExchangeItemListPaneNullVirtual.md`, `82/88`, owner [UID:00004S], `RECONSTRUCTABLE:TRUE`, blank `EMITTER_UIDS`, blank C++.
  - [x] [UID:0004A0] `by-memory/0x004ae1c0-0x004ae4b6.ExchangeItemListPaneDrawItemEntry.md`, `83/87`, owner [UID:00004S], `RECONSTRUCTABLE:TRUE`, blank `EMITTER_UIDS`, blank C++.
- [x] Created [UID:00049X] `by-memory/0x004adb10-0x004adc96.ExchangeDialogRawItemUpdate.md` as `88/91`, owner [UID:00004R], `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:00004R`, with exact covered-by marker for [UID:00014L] case `2`.
- [x] Updated existing retained-helper support children with exact covered-by markers: [UID:00014M] case `1`, [UID:00014O] case `4`, [UID:00014P] case `5`, and [UID:00014R] case `2`.
- [x] Changed [UID:00014K] to `RECONSTRUCTABLE:FALSE`, blank `EMITTER_UIDS`, blank C++, `COMPLETION:88`, `CONFIDENCE:90`, and owner [UID:0000J9].
- [x] Updated [UID:00014K] body with current MCP function inventory, raw-start negatives, vtable/data xrefs, `0x004adb10-0x004adc96` raw-body evidence, padding spans, split/container proof, and rejected aggregate-C++/whole-children/whole-covered-by alternatives.
- [x] Updated [UID:0000J9], [UID:00004R], and [UID:00004S] support docs with resolved child links, marker dispositions, source-route ownership, and the split/container disposition.
- [x] Did not manually edit `auto-generated/*`, `project-level/*`, coverage reports, validator/tool state, or the IDA DB. Validator-managed generated/project metadata refresh occurred only through scoped validator runs.
- [x] Ran scoped validators from `source-3/project-documentation` for the new child docs, changed by-memory marker docs, support docs, and final target pass. Proof is listed below.
- [x] Refreshed generated output only through `python .\tools\validator.py --mode file --file by-memory\0x004ac8a0-0x004ae4b6.ExchangeDialog.md --apply --wait-generated`.
- [x] Verified [UID:00014K], [UID:00014M], [UID:00014O], [UID:00014P], and [UID:00014R] no longer appear as empty emitter markers after refresh. New non-emitting children with blank `EMITTER_UIDS` do not appear as empty emitters.

## Validator Results

Implementation validators were run from `source-3/project-documentation`.

- New child UID assignment/file validators:
  - `000000005085` through `000000005096`, timestamps `2026-06-28T14:33:58-04:00` through `2026-06-28T14:34:44-04:00`, exited `0`. These assigned [UID:00049P] through [UID:0004A0]. The frontend printed `ok:1` where reported during assignment, except the first assignment output did not print an explicit ok count and command `000000005096` reported `ok:2` while resolving two related new pages.
  - Follow-up clean validations for the list-pane child pages: `000000005102` [UID:00049Z] and `000000005103` [UID:0004A0], timestamps `2026-06-28T14:48:39-04:00` and `2026-06-28T14:48:41-04:00`, both exited `0`, `ok:1`.
- Existing marker/support validators:
  - `000000005097` [UID:00014M], `000000005098` [UID:00014O], `000000005099` [UID:00014P], `000000005100` [UID:00014R], `000000005101` [UID:00014L], `000000005104` [UID:0000J9], `000000005105` [UID:00004R], and `000000005106` [UID:00004S], timestamps `2026-06-28T14:48:31-04:00` through `2026-06-28T14:48:55-04:00`, all exited `0`, `ok:1`.
- Final target/generated validation:
  - `000000005108`, timestamp `2026-06-28T14:52:10-04:00`, `python .\tools\validator.py --mode file --file by-memory\0x004ac8a0-0x004ae4b6.ExchangeDialog.md --apply --wait-generated`, exited `0`, scanned `1`, `ok:1`, `generated_refresh: completed`, `generated_refresh_command_id: 000000005108`.
  - Expected pre-existing warning persisted: `missing_ref_target 00014T ... by-memory/0x004ae4c0-0x004b0b15.ItemExchangeMixDialogs.md`. The edited docs already link [UID:00014T] to the current `0x004ae4c0-0x004b0ba5` target, and the current file exists with UID `00014T`; this is stale validator registry state outside the accepted `00014K` matrix and was not hand-repaired because tool-state edits are excluded.
  - The same generated pass also printed unrelated global `autogen_registry_stale`/`memory_coverage_metadata_missing_file` diagnostics for missing files outside this assignment. They did not block validation.
- Generated source proof:
  - `auto-generated/NexusTK/ui/dialogs/ExchangeDialog.cpp` header now has `validator-command-id: 000000005108`, `validator-refreshed-at: 2026-06-28T14:52:10-04:00`, and `validator-refresh-source: foreground-generated-refresh`.
  - `rg` over that generated file found no empty-emitter marker for [UID:00014K], [UID:00014M], [UID:00014O], [UID:00014P], [UID:00014R], or the new non-emitting children [UID:00049P]/[UID:00049Q]/[UID:00049R]/[UID:00049S]/[UID:00049T]/[UID:00049U]/[UID:00049V]/[UID:00049W]/[UID:00049Y]/[UID:00049Z]/[UID:0004A0]. [UID:00049X] appears only as a normal covered-by marker under dispatcher case `2`.
  - Targeted generated-source check output: `NO_TARGETED_EMPTY_EMITTER_MARKERS` and `NON_EMITTING_CHILDREN_ABSENT_FROM_GENERATED`.
- Lease proof:
  - The active edit lease batch created at `2026-06-28T18:48:04Z` was released with `leaser.py B001 unlease ...`; each leased by-* path returned `Success`.
  - `tools/leaser/Agents/current_leases.md` now reports `No active leases.`

## Changed Files

- `tools/leaser/Agents/Agent-B001/research/00014K-ExchangeDialog-empty-emitter-source-quality.md`
- `by-memory/0x004ac8a0-0x004ae4b6.ExchangeDialog.md`
- `by-memory/0x004ac8a0-0x004ad0aa.ExchangeDialogConstructor.md`
- `by-memory/0x004ad0b0-0x004ad1ca.ExchangeDialogOnButtonAction.md`
- `by-memory/0x004ad1d0-0x004ad1f4.ExchangeDialogOnClose.md`
- `by-memory/0x004ad200-0x004ad2fd.ExchangeDialogUpdateButtonStates.md`
- `by-memory/0x004ad7d0-0x004ad85f.ExchangeDialogOnKeyEvent.md`
- `by-memory/0x004ad900-0x004ad95f.ExchangeDialogSendCancelPacket.md`
- `by-memory/0x004ad960-0x004ada16.ExchangeDialogSubmitExchangeAmount.md`
- `by-memory/0x004ada20-0x004ada84.ExchangeDialogSetExchangeAmount.md`
- `by-memory/0x004ada90-0x004adb02.ExchangeDialogAddItemWithCountHelper.md`
- `by-memory/0x004adb10-0x004adc96.ExchangeDialogRawItemUpdate.md`
- `by-memory/0x004ad320-0x004ad7b3.ExchangeDialogPacketDispatcher.md`
- `by-memory/0x004add40-0x004ade5e.ExchangeDialogCancelAlertHelper.md`
- `by-memory/0x004ade60-0x004adfab.ExchangeDialogReadyAlertHelper.md`
- `by-memory/0x004adfb0-0x004ae053.ExchangeDialogOnControlFocusChange.md`
- `by-memory/0x004ae0b0-0x004ae167.ExchangeItemListPaneRawUpsertHelper.md`
- `by-memory/0x004ae1b0-0x004ae1b3.ExchangeItemListPaneNullVirtual.md`
- `by-memory/0x004ae1c0-0x004ae4b6.ExchangeItemListPaneDrawItemEntry.md`
- `by-file/ExchangeDialog.md`
- `by-class/ExchangeDialog.md`
- `by-class/ExchangeItemListPane.md`

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B001","command_id":"000000004165","destination_path":"executed-b-agent-research/B001/00014K-ExchangeDialog-empty-emitter-source-quality.md","details":"legacy registry reconstruction","event":"executed","source_path":"tools/leaser/Agents/Agent-B001/research/00014K-ExchangeDialog-empty-emitter-source-quality.md","timestamp":"2026-06-28T14:59:43","uid":"00014K"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
