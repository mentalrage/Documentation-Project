** TARGET-REPORT-UID:0000J9 **
** AUTHOR-AGENT-ID:B011 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# 0000J9 ExchangeDialog Empty-Emitter Family Source-Quality Report

## Finalized Report / Current Recommendation

- Current recommendation: implement a narrow ExchangeDialog family empty-emitter repair, not a new broad rewrite. The file already has a strong source route and 20 populated emitters; the remaining 14 generated empty markers are class/vtable/global/tail-adjacent markers that need either exact formal declaration/comment text, first-draft C++, or one split repair for the mixed ExchangeAlertPane core cluster.
- Final disposition: keep [UID:0000J9][ExchangeDialog](../../../../../by-file/ExchangeDialog.md) as the source file route. Keep ExchangeDialog, ExchangeItemListPane, ExchangeMoneyEditControlPane, ExchangeAlertPane, and the alert singleton in this source family. Do not move these items to VectorHelpers, SystemMessagePanes, TimerMgr, raw runtime, or a separate source file.
- Required action after supervisor acceptance: edit only the target/support by-* docs listed below, create the three proposed exact children for the current [UID:00033W] mixed core cluster, update metadata/formal C++ blocks at report-level detail, then run scoped validators for every changed by-* file and final `by-file/ExchangeDialog.md` with `--wait-generated`.
- Confidence: high for ownership/source route, range boundaries, vtable/global facts, and formal no-code dispositions; moderate-high for the two source-facing money-edit helper names because their behavior is exact but the original virtual method names are inferred from slot use.

## Supporting Research

## Target

- Target UID: `0000J9`.
- Target path: `by-file/ExchangeDialog.md`.
- Source queue/report row: `auto-generated/-ag-research-tracker.md` -> `## Files With Empty Emitters`, row `ExchangeDialog | 34 | 20 | 14 | 58.8%`.
- Current supervisor classification: file with empty emitters; report-only research requested by `B011-report-0000J9-ExchangeDialog-empty-emitter-family-20260630`.
- Current scores and parent state: target is `COMPLETION:88`, `CONFIDENCE:86`, `CANONICAL_OWNER:FILE`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000J9`, blank formal C++. Generated `auto-generated/NexusTK/ui/dialogs/ExchangeDialog.cpp` was refreshed by validator command `000000003020` at `2026-06-30T15:17:56-04:00` and still contains exactly the 14 empty markers named in `goal.md`.

## Current Target State

- Existing metadata: `by-file/ExchangeDialog.md` already documents the ExchangeDialog source file route, accepted constructor/button/packet/list/money/body children, retained duplicate covered-by markers, and the private list and money controls.
- Existing owner/emitter/reconstructable state: the file owns emission for ExchangeDialog family pages through class owners; the exact `0x004ac8a0-0x004ae4b6` code aggregate is already a non-emitting split inventory, not a body owner.
- Existing C++/emitter state: 20 emitters are populated in generated output. The remaining empty markers are the 14 class/vtable/global/tail-adjacent pages in this assignment; none should become standalone unrelated source files.
- Existing stale or contradictory claims:
  - `by-memory/0x0069b330-0x0069b334.g_pExchangeAlertPane.md` says the slot was initialized to `0xffffffff`; current MCP `get_bytes 0x0069b330 size 4` returns `00 00 00 00`.
  - `by-memory/0x00619dc4-0x00619e88.ExchangeItemListPaneVtableData.md` still says the draw child remains non-emitting; current target and generated source show [UID:0004A0] emits `ExchangeItemListPane::DrawItemEntry`.
  - Several class markers are still blank because previous reports avoided class declaration shells. Current score-blocker rules require per-class audits and either safe declaration/no-code proof text or exact split/source repairs.
- Related target/support docs checked:
  - `by-file/ExchangeDialog.md`
  - `by-class/ExchangeAlertPane.md`
  - `by-class/ExchangeDialog.md`
  - `by-class/ExchangeItemListPane.md`
  - `by-class/ExchangeMoneyEditControlPane.md`
  - `by-global/g_pExchangeAlertPane.md`
  - all 10 current by-memory/by-type empty marker docs named in `goal.md`
  - supporting `by-memory/0x004b0490-0x004b0ba5.ExchangeDialogTail.md`
  - supporting `by-memory/0x0061a260-0x0061a304.ExchangeMoneyEditControlPaneVtableData.md`
  - supporting destructor/thunk-strip docs for the alert and money edit panes
  - generated `auto-generated/NexusTK/ui/dialogs/ExchangeDialog.cpp`
  - prior executed reports `B001/00014K`, `B001/00014V`, `B015/00004S`, and `B015/00014L` as lead material, validated against current docs/MCP.

## Executive Recommendation

- Keep `ExchangeDialog.cpp` as the file route. The empty markers are not evidence for a new source file.
- Repair [UID:00033W] as a mixed core split/container. It currently spans three different source-level items: the large alert constructor, alert button callback, and alert singleton-clear helper. Keep the current page as a non-emitting inventory and create exact child pages:
  - `by-memory/0x004b0490-0x004b0819.ExchangeAlertPaneConstructor.md`
  - `by-memory/0x004b0820-0x004b0860.ExchangeAlertPaneOnButtonClick.md`
  - `by-memory/0x004b0860-0x004b086b.ExchangeAlertPaneSingletonClearHelper.md`
- Emit first-draft C++ for the small routed helpers where behavior and source placement are exact: `ExchangeAlertPane::OnButtonClick`, alert singleton clear, `CloseActiveExchangeAlertPane`, `ExchangeMoneyEditControlPane::OnActivate`, `ExchangeMoneyEditControlPane::OnKeyEvent`, and `g_pExchangeAlertPane`.
- Use formal no-code proof comments, not raw vtable bytes, for vtable data/type pages. The compiler generated those tables from class declarations and virtual methods.
- Use class declaration/no-code route markers for the four class pages. ExchangeItemListPane can safely declare `ExchangeItemListRow`; the other class pages should not emit full member layouts because inherited base fields and complete source header order are not fully proven.
- Do not raise the root to a very high score. The family can clear empty markers, but the alert constructor remains below code gate because current same-pass evidence does not prove source-quality inherited helper names or exact original layout syntax.

## Supervisor Active Recheck

- The supervisor instruction is report-first research only for `[UID:0000J9] by-file/ExchangeDialog.md`; no by-* implementation until callback.
- The assigned item did require split repair before final implementation because [UID:00033W] is one marker over a constructor, button callback, and singleton-clear helper.
- Every current source-bearing child in scope is either recommended for populated formal C++ now, recommended as a generated vtable/global/comment route, or split into exact children with a concrete code/no-code disposition. No final item is left as a generic deferral.

## Inference Research Guidance Check

- `by-structure.md` was applied as follows:
  - source must be placed at the class/file owner rather than a raw address when a class method route is proven;
  - compiler-generated vtables should not be hand-emitted as byte arrays;
  - mixed ranges should be split or turned into non-emitting inventories instead of emitting one artificial body;
  - above-gate items need formal `RECONSTRUCTION_CPP CODE` content or an exact no-code proof.
- Existing assumptions treated as uncertain and rechecked:
  - alert global initializer value;
  - ExchangeItemListPane draw-child emission status;
  - whether alert/money edit helper names could be promoted from descriptive to source-facing;
  - whether class pages could safely emit complete layouts.
- IDA facts are separated below from documentation evidence and inference. Source-facing names such as `OnPrimaryButton`, `OnSecondaryButton`, `OnActivate`, `OnKeyEvent`, `ExchangeItemListRow`, and `g_pExchangeAlertPane` are inferred/descriptive but backed by vtable slots, constructor stores, current generated source, and existing accepted docs.
- No Wave2/Wave3 source was accepted as authoritative. Old unrefined source and re-agent decompiler output were opened only as lead material and rejected wherever they used false generated symbols or unsupported decompiler-shaped class names.

## Heuristic / Inference Reanalysis And Validation

- Generated names: `sub_4B0490`, `sub_4B0820`, `sub_4B0860`, `sub_4B0B20`, `sub_4B0B40`, and `sub_4B0B60` are IDA labels only. The report recommends source-facing names only where vtable slot or caller role makes the source role specific.
- Class names: `ExchangeDialog`, `ExchangeAlertPane`, `ExchangeItemListPane`, and `ExchangeMoneyEditControlPane` are stable in current docs and generated source. The family path `NexusTK/ui/dialogs/ExchangeDialog.cpp` remains supported by resource names and accepted child method docs.
- Field names/layouts: full class member layout is not emitted for `ExchangeDialog`, `ExchangeAlertPane`, or `ExchangeMoneyEditControlPane`. Current evidence proves selected offsets and roles, but a complete source header would still require invented inherited field order. This is not a blocker for target repair because exact child methods carry bodies and class markers can carry explicit declaration/children route comments.
- `ExchangeItemListRow`: safe to emit as a row struct. Current docs, generated source, accepted B015/B009/B004 findings, and draw/list helpers converge on key `+0`, item id `+2`, color `+4`, `wchar_t name[256] +6`, total size `0x206`.
- Alert constructor: behavior is well documented and MCP-decompiled, but a final source body would require naming and typing several inherited UI helpers (`0x0049d8a0`, `0x00516030`, `0x005447c0`, `0x004b8e00`, `0x004baa70`, `0x0058ee90`, `0x00499xxx`, `0x0049dfd0`, `0x0049e190`, `0x0049eac0`) plus resolving a decompiler artifact in the right-button-only width path. After checking current docs, MCP, generated output, old unrefined source, and re-agent output, the safe recommendation is a below-code-gate exact constructor child with detailed behavior evidence, not a guessed constructor body.
- Vtables: the vtable pages have exact address evidence and should remain documented, but literal vtable array C++ would be a binary reconstruction artifact, not source-quality developer code.
- Singleton storage: the by-global page should emit the one source declaration/definition. The exact by-memory storage page should only carry a covered-by comment and the corrected zero-filled current MCP bytes.
- Rejected alternatives:
  - `ExchangeDialog` class owner for alert pane methods: rejected because alert constructor installs alert vtables and owns the alert singleton, while ExchangeDialog callers only allocate/use the alert.
  - direct standalone source file for `ExchangeAlertPane`: rejected because current file route and adjacent dialogs/resources keep the alert pane local to ExchangeDialog.
  - raw helper standalone bodies for retained duplicate list/update helpers: rejected by accepted covered-by reports and current generated source.
  - `TimerMgr` ownership: rejected because the only timer evidence in this family is the ExchangeDialog amount-confirm timer event; none of the current 14 markers is a TimerMgr method or data item.
  - raw vtable byte arrays: rejected as compiler-generated output.

## Evidence Standards Used

- Evidence types used: IDA MCP `idb_list`, `server_health`, `lookup_funcs`, `xrefs_to`, `decompile`, `get_bytes`; current generated output; existing by-* docs; old executed B-agent reports as leads; negative checks for end-address functions and direct code xrefs; raw byte checks for vtables/global/padding.
- Evidence strength: ownership and boundaries are direct IDA facts plus current accepted docs. Method names are source-facing inferences. Complete class layouts remain intentionally limited.
- Tool state: MCP was available and healthy; this is not a fallback-only report.

## Evidence Checked

- IDA MCP/manual-disassembly/raw-byte checks performed:
  - `idb_list`: active session `supervisor_resume_20260629`, active worker for `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, worker pid `24256`, auto-analysis not running.
  - `server_health`: `status:"ok"`, module `NexusTK.exe`, imagebase `0x400000`, auto-analysis ready, Hex-Rays ready, strings cache ready.
  - `lookup_funcs`:
    - `0x004b0490 -> sub_4B0490`, size `0x389`.
    - `0x004b0819`: not a function.
    - `0x004b0820 -> sub_4B0820`, size `0x40`.
    - `0x004b0860 -> sub_4B0860`, size `0x0b`.
    - `0x004b086b`: not a function.
    - `0x004b0b20 -> sub_4B0B20`, size `0x11`.
    - `0x004b0b31`: not a function.
    - `0x004b0b40 -> sub_4B0B40`, size `0x14`.
    - `0x004b0b54`: not a function.
    - `0x004b0b60 -> sub_4B0B60`, size `0x36`.
    - `0x004b0b96`: not a function.
    - `0x00619d28`, `0x00619dc4`, `0x0061a1c0`, and `0x0069b330`: not functions.
  - `xrefs_to`:
    - `0x004b0490`: callers `0x004ad656`, `0x004ad775`, `0x004ade18`, `0x004adf8d`.
    - `0x004b0820`: data xref `0x0061a208`.
    - `0x004b0b20`: callers `0x004ad741`, `0x004adf59`.
    - `0x004b0b40`: data xref `0x0061a2c0`.
    - `0x004b0b60`: data xref `0x0061a2d4`.
    - `0x0069b330`: refs at `0x004ad611`, `0x004ad739`, `0x004addd3`, `0x004adf51`, `0x004b04ff`, `0x004b0506`, `0x004b0860`, `0x004b09d6`, and `0x004b0b20`.
  - `decompile 0x004b0820`: checks button ids 1/2, calls `0x0049eb90`, then virtual slots `+0x5c`/`+0x60`, then `0x0049dad0`.
  - `decompile 0x004b0860`: writes zero to `0x0069b330`.
  - `decompile 0x004b0b20`: if singleton is non-null, calls its first vtable slot with argument `1`.
  - `decompile 0x004b0b40`: calls `0x00498c00(this, 1, 1)` and returns `0x00494c30(this)`.
  - `decompile 0x004b0b60`: requires event byte `+4 == 10`, byte `+9 == 1`, UTF-16 digit at `+0x0a`, calls `0x00498d90(this)`, returns true; otherwise false.
  - `decompile 0x004b0490`: confirms DialogPane construction, alert singleton set, vtables `0x0061a1c0/0x0061a228/0x0061a258`, message measurement/clamping, static text creation, optional left/right text buttons, centered bounds, show/focus setup, and parent pane pointer storage at primary `+0x26c`.
  - `get_bytes 0x0061a1bc size 0xa8`, `0x00619d28 size 0xc0`, `0x00619dc4 size 0xc8`: confirm vtable data boundaries and successor starts.
  - `get_bytes 0x0069b330 size 4`: confirms current bytes `00 00 00 00`.
  - `get_bytes 0x004b0b31 size 0x6f`: confirms padding around the money edit helpers.
- by-* docs, support docs, old reports, generated reports, and trackers checked:
  - all current target/support docs named under `Current Target State`;
  - `auto-generated/NexusTK/ui/dialogs/ExchangeDialog.cpp`;
  - `auto-generated/-ag-research-tracker.md`;
  - executed reports `B001/00014K`, `B001/00014V`, `B015/00004S`, `B015/00014L`;
  - unrefined backup source and re-agent code for the alert/money snippets as non-authoritative leads.
- Negative checks performed:
  - no function at each exclusive end address;
  - no code caller to `0x004b0b40` or `0x004b0b60` other than vtable data;
  - no current non-zero initializer byte at `0x0069b330`;
  - no source-quality literal vtable ownership.
- Failed, unavailable, or intentionally skipped checks:
  - `source-3/simroot_v2` does not exist in this workspace; old references to that path were treated as stale lead references.
  - No leases and no validators were run because this is report-only.

## Claim And Incorporation Ledger

| Claim ID | Claim | Confidence | Evidence | Destination doc/section | Action | Verification state |
| --- | --- | --- | --- | --- | --- | --- |
| C-0000J9-01 | `ExchangeDialog.cpp` remains the source-file route for the family. | High | Current `by-file/ExchangeDialog.md`, generated path, accepted child docs, resources, MCP callers. | `by-file/ExchangeDialog.md` status/evidence and changes. | Apply root empty-emitter family summary and metadata refresh. | applied: root metadata/status/family section/change log updated; final validator `000000003160` ok:1. |
| C-0000J9-02 | Current generated source has 34 emitters, 20 populated and 14 empty. | High | `auto-generated/NexusTK/ui/dialogs/ExchangeDialog.cpp` header and empty markers. | `by-file/ExchangeDialog.md`. | Record current generated state and expected no-empty-marker refresh after implementation. | applied: root family section records baseline; generated file header `validator-command-id: 000000003160`; accepted-family `Empty Emitter Marker` search has no matches. |
| C-00033W-01 | [UID:00033W] is a mixed range and should become a non-emitting split inventory. | High | MCP function starts at `0x004b0490`, `0x004b0820`, `0x004b0860`; no function at `0x004b0819`/`0x004b086b`; current page spans three source roles. | `by-memory/0x004b0490-0x004b086b.ExchangeAlertPaneCore.md`. | Set `RECONSTRUCTABLE:FALSE`, blank `EMITTER_UIDS`, describe exact children. | applied: parent converted to non-emitting split inventory and validated by `000000003140` ok:7. |
| C-00033W-02 | Create constructor child `0x004b0490-0x004b0819`; keep below code gate. | Medium-high | MCP decompile and old lead checks prove behavior but not final inherited helper names/source layout. | New `by-memory/0x004b0490-0x004b0819.ExchangeAlertPaneConstructor.md`. | Create exact child with no formal C++ and detailed no-code proof. | applied: validator assigned [UID:0004CF]; blank emitter/formal no-code proof validated by `000000003137`. |
| C-00033W-03 | Create `ExchangeAlertPane::OnButtonClick` child and emit first-draft C++. | High | Vtable data xref `0x0061a208`; decompile exact button id/slot/close behavior. | New `by-memory/0x004b0820-0x004b0860.ExchangeAlertPaneOnButtonClick.md`. | Create child, owner/emitter `00004Q`, formal C++. | applied: validator assigned [UID:0004CG]; owner/emitter/formal C++ validated by `000000003138`. |
| C-00033W-04 | Create singleton-clear child and emit source helper. | High | Decompile is exact `g_pExchangeAlertPane = 0`; singleton xrefs include destructor/constructor/close helper. | New `by-memory/0x004b0860-0x004b086b.ExchangeAlertPaneSingletonClearHelper.md`. | Create child, owner/emitter `00004Q`, formal C++. | applied: validator assigned [UID:0004CH]; owner/emitter/formal C++ validated by `000000003139`. |
| C-00033Z-01 | `0x004b0b20` is the active alert close helper, not a broad dialog body. | High | MCP callers `0x004ad741`/`0x004adf59`; xrefs to singleton; decompile. | `by-memory/0x004b0b20-0x004b0b31.ExchangeAlertPaneCloseActiveHelper.md`. | Populate formal C++. | applied: formal `CloseActiveExchangeAlertPane` block and score validated by `000000003143` ok:1. |
| C-00004Q-01 | `ExchangeAlertPane` class marker can safely emit declaration/children route, not full layout. | High | Constructor vtable stores, class doc, scalar destructor/thunks, vtable data. | `by-class/ExchangeAlertPane.md`. | Add class declaration shell and `[[CHILDREN]]`; update audit. | applied: formal class/children route and child refs validated by `000000003141` ok:10. |
| C-0002NF-01 | Alert vtable data should be a formal no-code proof comment. | High | Raw bytes and constructor stores; compiler-generated table. | `by-memory/0x0061a1c0-0x0061a260.ExchangeAlertPaneVtableData.md`. | Add formal no-code comment. | applied: formal no-literal-vtable comment validated by `000000003144` ok:1. |
| C-0001XJ-01 | Alert vtable type page should route through class/vtable data, not literal arrays. | High | Same vtable evidence. | `by-type/by-vtable/ExchangeAlertPaneVtables.md`. | Add formal no-code comment plus `[[CHILDREN]]`. | applied: formal no-code/children marker validated by `000000003145` ok:1. |
| C-00004R-01 | `ExchangeDialog` class marker should emit only a children-route declaration marker. | High | Many exact children already emit; full layout still not source-quality. | `by-class/ExchangeDialog.md`. | Add formal class-route comment and `[[CHILDREN]]`. | applied: formal class-route block and `88/90` validated by `000000003153` ok:1. |
| C-0003NE-01 | ExchangeDialog vtable data should be comment-only. | High | Constructor stores `0x00619d2c/0x00619d8c/0x00619dbc`; raw bytes. | `by-memory/0x00619d28-0x00619dc4.ExchangeDialogVtableData.md`. | Add formal no-code comment. | applied: formal no-literal-vtable comment and `88/92` validated by `000000003154` ok:1. |
| C-00004S-01 | `ExchangeItemListRow` declaration is safe on `ExchangeItemListPane`; helper declarations beyond emitted virtuals remain unsafe. | High | Accepted B015/B009/B004 docs; current generated source; row offsets/size. | `by-class/ExchangeItemListPane.md`. | Add row struct, narrow class declaration, `[[CHILDREN]]`; refresh stale draw status. | applied: row struct/class/children marker and `89/90` validated by `000000003155` ok:1; stale `87/89` support caveat in `by-class/ExchangeDialog.md` corrected and validated by `000000003182` ok:1. |
| C-0003NF-01 | ExchangeItemListPane vtable data should be comment-only and stale draw non-emitter text should be corrected. | High | Raw bytes, vtable slots, current generated `DrawItemEntry`. | `by-memory/0x00619dc4-0x00619e88.ExchangeItemListPaneVtableData.md`. | Add formal no-code comment and support refresh. | applied: formal no-literal-vtable comment and stale draw text correction validated by `000000003156` ok:1. |
| C-00004T-01 | `ExchangeMoneyEditControlPane` class marker can emit a narrow class-route marker. | Medium-high | Money vtable child, helper xrefs, destructor/thunk docs. | `by-class/ExchangeMoneyEditControlPane.md`. | Add narrow class declaration/comment and `[[CHILDREN]]`. | applied: formal class/children route and `88/90` validated by `000000003157` ok:1. |
| C-000340-01 | Activation helper is vtable-routed money edit source behavior. | Medium-high | Vtable xref `0x0061a2c0`; decompile exact calls. | `by-memory/0x004b0b40-0x004b0b54.ExchangeMoneyEditControlPaneActivationHelper.md`. | Populate formal C++. | applied: formal `OnActivate` block and `87/90` validated by `000000003158` ok:1. |
| C-000341-01 | Digit handler is vtable-routed money edit source behavior. | High | Vtable xref `0x0061a2d4`; decompile exact event checks and action. | `by-memory/0x004b0b60-0x004b0b96.ExchangeMoneyEditControlPaneDigitKeyHandler.md`. | Populate formal C++. | applied: formal `OnKeyEvent` block and `88/91` validated by `000000003159` ok:1. |
| C-0000QV-01 | `g_pExchangeAlertPane` should emit the one source global definition. | High | Singleton xrefs and current zero storage. | `by-global/g_pExchangeAlertPane.md`. | Add formal global definition. | applied: formal `static ExchangeAlertPane *g_pExchangeAlertPane = NULL;` and `88/92` validated by `000000003147` ok:1. |
| C-0002VZ-01 | Exact global storage page should be covered-by the by-global definition and correct the stale `0xffffffff` claim. | High | `get_bytes 0x0069b330 size 4` returns zero bytes. | `by-memory/0x0069b330-0x0069b334.g_pExchangeAlertPane.md`. | Add formal covered-by comment; update evidence. | applied: formal covered-by comment/current zero-byte correction and `89/92` validated by `000000003149` ok:1. |

## Positive Evidence Summary

- Direct facts supporting the chosen recommendation:
  - all current code functions have exact MCP function sizes and xrefs;
  - vtable data xrefs point to the relevant class constructors and slots;
  - singleton references are confined to ExchangeDialog alert creation/cleanup/close paths;
  - generated `ExchangeDialog.cpp` already emits adjacent accepted bodies through this route.
- Corroborating documentation/generated-report evidence:
  - target and child docs already describe ExchangeDialog constructor, packet dispatcher, button actions, list and money controls, and covered-by duplicate helper policy;
  - generated output has no evidence of a competing source file.
- Strongest inference chain:
  - vtable-routed helper + class constructor vtable stores + accepted source-file route + current generated child body pattern is sufficient to classify the small helper functions as class-source methods even when original symbols are absent.

## IDA MCP Facts

- Function/range facts:
  - `sub_4B0490` is `0x389` bytes and ends at `0x004b0819`.
  - `sub_4B0820` is `0x40` bytes and ends at `0x004b0860`.
  - `sub_4B0860` is `0x0b` bytes and ends at `0x004b086b`.
  - `sub_4B0B20` is `0x11` bytes and ends at `0x004b0b31`.
  - `sub_4B0B40` is `0x14` bytes and ends at `0x004b0b54`.
  - `sub_4B0B60` is `0x36` bytes and ends at `0x004b0b96`.
- Data/table/padding facts:
  - `0x0061a1c0-0x0061a260` is alert vtable data and ends before money edit RTTI/COL data.
  - `0x00619d28-0x00619dc4` is ExchangeDialog vtable data and ends before ExchangeItemListPane COL.
  - `0x00619dc4-0x00619e88` is ExchangeItemListPane vtable data and ends before AddItemDialog COL.
  - `0x0069b330` contains zero bytes in the current IDB.
- Xref facts:
  - alert constructor has four callers from ExchangeDialog packet/cancel/ready paths;
  - close-active helper has two callers from cancel/ready paths;
  - money edit activation/digit helpers are vtable-only by current xrefs.
- Vtable/global/type facts:
  - ExchangeAlertPane constructor stores `0x0061a1c0`, `0x0061a228`, `0x0061a258`.
  - ExchangeDialog constructor stores `0x00619d2c`, `0x00619d8c`, `0x00619dbc`.
  - ExchangeItemListPane constructor/list setup stores `0x00619dc8`, `0x00619e50`, `0x00619e80`.
  - `g_pExchangeAlertPane` has nine current references across create/close/clear/destruct paths.
- Negative IDA facts:
  - exclusive end addresses are not function starts;
  - data/vtable/global addresses are not functions;
  - money edit helpers have no direct code caller apart from vtable data.

## Function / Child Inventory

| Range / Item | UID / Path | Role | Reconstructable | Direct Parent | Score | Status |
| --- | --- | --- | --- | --- | --- | --- |
| file route | `0000J9 by-file/ExchangeDialog.md` | ExchangeDialog source file | TRUE | FILE | current `88/86`, recommend `90/88` | Keep route; clear 14 empty markers. |
| class | `00004Q by-class/ExchangeAlertPane.md` | Alert pane class marker | TRUE | `0000J9` | current `86/89`, recommend `88/90` | Emit declaration/children marker. |
| `0x004b0490-0x004b086b` | `00033W ExchangeAlertPaneCore` | Mixed constructor/callback/clear cluster | recommend FALSE | `00004Q` | current `85/88`, recommend `88/90` container | Convert to non-emitting inventory. |
| `0x004b0490-0x004b0819` | new `ExchangeAlertPaneConstructor` | Alert constructor | TRUE | `00004Q` | recommend `84/86` | Create exact below-code-gate child. |
| `0x004b0820-0x004b0860` | new `ExchangeAlertPaneOnButtonClick` | Button callback | TRUE | `00004Q` | recommend `88/91` | Create and emit first-draft C++. |
| `0x004b0860-0x004b086b` | new `ExchangeAlertPaneSingletonClearHelper` | Singleton clear | TRUE | `00004Q` | recommend `88/92` | Create and emit first-draft C++. |
| `0x004b0b20-0x004b0b31` | `00033Z` | Active alert close helper | TRUE | `00004Q` | current `85/90`, recommend `88/92` | Emit first-draft C++. |
| `0x0061a1c0-0x0061a260` | `0002NF` | Alert vtable data | TRUE | `00004Q` | current `85/91`, recommend `88/92` | Formal no-code proof comment. |
| vtable type | `0001XJ` | Alert vtable route | TRUE | `00004Q` | current `86/90`, recommend `88/92` | Formal no-code proof comment. |
| class | `00004R by-class/ExchangeDialog.md` | Main dialog class marker | TRUE | `0000J9` | current `86/88`, recommend `88/90` | Children-route marker. |
| `0x00619d28-0x00619dc4` | `0003NE` | ExchangeDialog vtable data | TRUE | `00004R` | current `86/91`, recommend `88/92` | Formal no-code proof comment. |
| class | `00004S by-class/ExchangeItemListPane.md` | Private list pane class marker | TRUE | `0000J9` | current `87/89`, recommend `89/90` | Emit row struct + narrow declaration/children marker. |
| `0x00619dc4-0x00619e88` | `0003NF` | List pane vtable data | TRUE | `00004S` | current `85/90`, recommend `88/92` | Formal no-code proof comment; stale draw text fix. |
| class | `00004T by-class/ExchangeMoneyEditControlPane.md` | Money edit class marker | TRUE | `0000J9` | current `85/88`, recommend `88/90` | Narrow class route marker. |
| `0x004b0b40-0x004b0b54` | `000340` | Money edit activation helper | TRUE | `00004T` | current `85/88`, recommend `87/90` | Emit first-draft C++. |
| `0x004b0b60-0x004b0b96` | `000341` | Money edit digit key handler | TRUE | `00004T` | current `85/89`, recommend `88/91` | Emit first-draft C++. |
| global | `0000QV by-global/g_pExchangeAlertPane.md` | Source global pointer | TRUE | `0000J9` | current `87/90`, recommend `88/92` | Emit source global definition. |
| `0x0069b330-0x0069b334` | `0002VZ` | Exact global storage | TRUE | `0000J9` | current `88/90`, recommend `89/92` | Formal covered-by comment and byte correction. |

## Direct Xref / Caller Inventory

| Address / Item | Xref / Caller / Callee | Meaning |
| --- | --- | --- |
| `0x004b0490` | callers `0x004ad656`, `0x004ad775`, `0x004ade18`, `0x004adf8d` | Alert construction from ExchangeDialog cancel/ready paths. |
| `0x004b0820` | data xref `0x0061a208` | Alert button callback vtable slot. |
| `0x004b0860` | singleton write and xref in alert cleanup path | Alert singleton clear. |
| `0x004b0b20` | callers `0x004ad741`, `0x004adf59` | Close active alert before replacement. |
| `0x004b0b40` | data xref `0x0061a2c0` | Money edit activation vtable slot. |
| `0x004b0b60` | data xref `0x0061a2d4` | Money edit digit key vtable slot. |
| `0x0069b330` | nine refs across ExchangeDialog/ExchangeAlertPane paths | Local alert singleton storage. |

## Documentation Evidence And IDA Status

- Existing docs that support the conclusion:
  - `by-file/ExchangeDialog.md` already names ExchangeDialog.cpp as the source route and documents accepted body emitters.
  - `by-memory/0x004b0490-0x004b0ba5.ExchangeDialogTail.md` already frames the tail as exact child inventory, not one source body.
  - `by-class/ExchangeItemListPane.md` and accepted B015/B009/B004 reports prove row layout and current list child body disposition.
  - `by-memory/0x0061a260-0x0061a304.ExchangeMoneyEditControlPaneVtableData.md` proves money edit vtable slots and owner.
- Existing docs that are stale, incomplete, or contradicted:
  - alert core cluster needs split repair;
  - singleton storage initializer claim must change from `0xffffffff` to current zero-filled bytes;
  - ExchangeItemListPane vtable page must stop saying the draw child is non-emitting;
  - class/vtable pages need formal no-code/declaration blocks to remove empty markers.
- Generated/coverage report state:
  - generated C++ is current enough for this report and contains exactly the 14 empty markers.
  - no generated reports or coverage reports should be edited manually.

## Ranked Ownership Analysis

### 1. ExchangeDialog.cpp / ExchangeDialog Family

- Evidence for: generated source path, target source route, resource names, accepted child methods, current vtable/caller evidence, and existing docs all keep these items local to ExchangeDialog.
- Evidence against: none for the current 14 markers.
- Decision: accepted owner/source route.

### 2. ExchangeAlertPane Class Owner For Alert Marker Children

- Evidence for: alert constructor stores alert vtables, alert button callback is in alert vtable, singleton is set/cleared/destructed by alert class paths, close-active helper consumes the alert singleton.
- Evidence against: callers live in ExchangeDialog packet paths, but call sites do not transfer ownership.
- Decision: alert class owns alert constructor/callback/clear/close/vtable data; file route remains ExchangeDialog.cpp.

### 3. ExchangeMoneyEditControlPane Class Owner For Money Helpers

- Evidence for: helper starts are vtable-only via money edit vtable data; docs identify this as the local amount input control.
- Evidence against: no direct code callers and original virtual slot names are absent.
- Decision: class owner is correct; use conservative inferred method names in first-draft C++ and cap confidence.

### 4. Rejected Generic Raw/Runtime/Helper Ownership

- Evidence for: none beyond raw addresses.
- Evidence against: vtable/caller/global docs all identify class/file owners; by-structure discourages raw helper ownership where class route exists.
- Decision: reject.

## Source Placement

- Recommended source file/class/global/module placement:
  - all target/support edits route through `NexusTK/ui/dialogs/ExchangeDialog.cpp`;
  - alert child methods under `ExchangeAlertPane`;
  - list pane declaration under `ExchangeItemListPane`;
  - money edit helpers under `ExchangeMoneyEditControlPane`;
  - singleton source definition under `g_pExchangeAlertPane`.
- Why this fits: all current callers, resources, and generated output are within ExchangeDialog exchange UI behavior.
- Rejected placements:
  - `VectorHelpers`, `TimerMgr`, generic UI runtime, or a new file are unsupported by xrefs and current docs.
- Remaining placement uncertainty: none that blocks implementation. Only original method names for money edit activation and exact alert constructor source syntax remain confidence caps.

## Range / Split / Padding / Reclassification Analysis

- Exact range/boundary facts:
  - [UID:00033W] spans `0x004b0490-0x004b086b`, but MCP confirms three functions inside it.
  - end addresses `0x004b0819`, `0x004b0860`, and `0x004b086b` align with function boundaries and/or next start.
  - `0x004b0b31-0x004b0b40` and `0x004b0b54-0x004b0b60` are padding between separate tail helpers.
- Children/subranges to create:
  - `0x004b0490-0x004b0819.ExchangeAlertPaneConstructor`
  - `0x004b0820-0x004b0860.ExchangeAlertPaneOnButtonClick`
  - `0x004b0860-0x004b086b.ExchangeAlertPaneSingletonClearHelper`
- Parent/container impact:
  - [UID:00033W] should no longer emit; it remains useful as a split inventory with `Nested` updated to include the three exact children.
  - No split is needed for [UID:00033Z], [UID:000340], or [UID:000341]; each is already exact.

## Per-Class Empty Marker Audits

### [UID:00004Q] ExchangeAlertPane

- Constructor/destructor route checked: constructor at `0x004b0490`; scalar deleting destructor at `0x004b09d0`; adjustor thunks at `0x004b08cd` and `0x004b08d8`.
- Vtable slots checked: primary/secondary/tertiary vtables at `0x0061a1c0`, `0x0061a228`, `0x0061a258`; button slot at `0x0061a208 -> 0x004b0820`; default/no-op extension slots at `0x0061a21c/0x0061a220 -> 0x0041b6a0`.
- Method inventory checked: constructor, button callback, singleton clear, close-active helper, destructor/thunks.
- Fields/offsets checked: parent pane pointer at primary `+0x26c`; singleton storage at `0x0069b330`; inherited dialog/list controls are not fully layout-final.
- Base class checked: constructor calls the DialogPane constructor and installs multiple DialogPane-style vtable facets.
- Direct child ownership checked: alert-specific code and vtable data belong to `ExchangeAlertPane`; callers from `ExchangeDialog` do not own the methods.
- Declaration shell safety: safe if limited to class/method declarations and `[[CHILDREN]]`; unsafe to emit full member layout or constructor body here.

### [UID:00004R] ExchangeDialog

- Constructor/destructor route checked: accepted constructor child `0x004ac8a0-0x004ad0aa`; vtable data at `0x00619d28-0x00619dc4`; destructors/thunks documented in existing children.
- Vtable slots checked: constructor stores `0x00619d2c`, `0x00619d8c`, `0x00619dbc`; existing method children already cover button, close, state update, packet dispatcher, key, focus, money, and cancel/send paths.
- Method inventory checked: current root doc lists accepted emitting children and covered-by duplicates.
- Fields/offsets checked: exchange id, control ids, local/remote offer flags, amount, timer handler, amount-decrease lock, active controls; not enough for a full original class layout.
- Base class checked: DialogPane-style construction and callbacks.
- Direct child ownership checked: exact children own source bodies; raw duplicate helpers remain covered-by dispatcher where proven.
- Declaration shell safety: safe only as a formal class-route/children marker. Full class definition with fields is unsafe because it would invent member order and inherited base shape.

### [UID:00004S] ExchangeItemListPane

- Constructor/destructor route checked: raw constructor child `0x004ae060-0x004ae0a4` and current inline constructor equivalents in ExchangeDialog constructor.
- Vtable slots checked: primary `0x00619dc8`, secondary `0x00619e50`, tertiary `0x00619e80`; null selection callback `0x00619e40 -> 0x004ae1b0`; draw callback `0x00619e48 -> 0x004ae1c0`.
- Method inventory checked: constructor, no-op selection, draw entry, raw upsert/find covered-by dispatcher case `2`.
- Fields/offsets checked: row key `+0`, item id `+2`, color `+4`, name `+6`, row size `0x206`; list control fields inherited.
- Base class checked: constructor base initializer is `ListPane(sizeof(ExchangeItemListRow), 8, 0x9c, 0x18, 0, 1, 1)`.
- Direct child ownership checked: list pane children stay under `ExchangeItemListPane`; dispatcher inlines retained row helper behavior and remains the live source route for packet updates.
- Declaration shell safety: safe to emit `ExchangeItemListRow` and narrow virtual/constructor declarations with `[[CHILDREN]]`; unsafe to emit standalone helper declarations for `SetOfferItem`/`FindOfferItemRowByKey` as source bodies because no direct code route exists.

### [UID:00004T] ExchangeMoneyEditControlPane

- Constructor/destructor route checked: class doc and destructor/thunk strip; no separate source constructor body is required for this callback.
- Vtable slots checked: money edit vtable data at `0x0061a260-0x0061a304`; activation slot `0x0061a2c0 -> 0x004b0b40`; digit key slot `0x0061a2d4 -> 0x004b0b60`.
- Method inventory checked: activation helper, digit key handler, scalar deleting destructor, adjustor thunks, shared return-true compiler/shared slot.
- Fields/offsets checked: inherited text edit/control fields only; event offsets from digit handler are exact but event struct name is inferred.
- Base class checked: helper calls are inherited control/text-edit routines; exact base class member layout is not final.
- Direct child ownership checked: helpers belong under `ExchangeMoneyEditControlPane`, not generic text edit runtime, because vtable data owns the entry points.
- Declaration shell safety: safe for a narrow class-route marker and two inferred virtual method declarations; unsafe for full layout.

## Resource / Global / Vtable Disposition Audits

- [UID:0002NF] `ExchangeAlertPaneVtableData`: exact data table, not source-authored byte array. Emit a target-specific no-code proof comment.
- [UID:0001XJ] `ExchangeAlertPaneVtables`: type-level vtable route. Emit a target-specific no-code proof comment plus `[[CHILDREN]]`.
- [UID:0003NE] `ExchangeDialogVtableData`: exact compiler-generated vtable data from ExchangeDialog class. Emit no-code proof comment.
- [UID:0003NF] `ExchangeItemListPaneVtableData`: exact compiler-generated vtable data from ExchangeItemListPane class. Emit no-code proof comment and correct stale draw-child text.
- [UID:0000QV] `g_pExchangeAlertPane`: source-level global pointer. Emit one definition.
- [UID:0002VZ] exact storage: physical storage for the global. Emit covered-by comment and correct bytes to current zero-filled MCP state.

## Negative Evidence Summary

- Old unrefined backup source contains decompiler-shaped artifacts and false names; it did not prove constructor helper names or full class layouts.
- Re-agent code snippets are useful comparisons but contain generated names and false inherited method routes; current MCP and docs supersede them.
- Lack of direct callers to money edit helpers does not make them dead code; the vtable data is the source route.
- Lack of original symbols is not used as a final blocker by itself. Each non-emitting recommendation is tied to mixed-range split, compiler-generated vtable data, physical storage duplication, or unsafe full-layout emission after specific evidence checks.

## IDA Rename / Type / Comment Recommendations

- Proposed source-facing names/types/comments:
  - `ExchangeAlertPane::OnButtonClick(int buttonId)` for `0x004b0820`.
  - `ClearExchangeAlertPaneSingleton()` for `0x004b0860`.
  - `CloseActiveExchangeAlertPane()` for `0x004b0b20`.
  - `ExchangeMoneyEditControlPane::OnActivate()` for `0x004b0b40`.
  - `ExchangeMoneyEditControlPane::OnKeyEvent(KeyEvent *event)` for `0x004b0b60`.
  - `ExchangeItemListRow` for the private list row.
  - `g_pExchangeAlertPane` for storage `0x0069b330`.
- Evidence for each proposed name/type/comment is listed in MCP facts and per-class audits.
- Items intentionally left unchanged:
  - no IDA DB rename/type edits are requested;
  - no full class layouts are emitted for ExchangeDialog, ExchangeAlertPane, or ExchangeMoneyEditControlPane.
- IDA DB edits are not requested by this B-agent pass.

## First-Draft C++ Recommendation

Eligible for draft C++:

- new `0x004b0820-0x004b0860.ExchangeAlertPaneOnButtonClick`
- new `0x004b0860-0x004b086b.ExchangeAlertPaneSingletonClearHelper`
- `0x004b0b20-0x004b0b31.ExchangeAlertPaneCloseActiveHelper`
- `0x004b0b40-0x004b0b54.ExchangeMoneyEditControlPaneActivationHelper`
- `0x004b0b60-0x004b0b96.ExchangeMoneyEditControlPaneDigitKeyHandler`
- `by-global/g_pExchangeAlertPane.md`
- class/vtable/global storage markers listed below as formal declaration/comment/no-code blocks.

### [UID:00004Q] ExchangeAlertPane formal block

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
// ExchangeAlertPane source bodies are carried by exact child pages in this source file route.
// This class marker intentionally does not emit a full member layout because inherited
// DialogPane fields and exact original header order are not source-quality from current evidence.
class ExchangeAlertPane;

[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

Reason it preserves behavior: it routes exact child methods without inventing class layout.

### [UID:00033W] ExchangeAlertPaneCore formal block after split

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

Exact no-code proof: this page becomes a non-emitting split inventory for three exact child ranges; emitting one body here would merge constructor, callback, and singleton-clear helper into a false source construct.

### New constructor child `0x004b0490-0x004b0819.ExchangeAlertPaneConstructor`

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

Exact no-code proof: current MCP proves constructor behavior, vtable stores, singleton setup, message measurement, optional button creation, centering, and parent pointer storage, but same-pass evidence does not prove source-quality names/signatures for the inherited UI helpers or the original layout syntax. Old unrefined source and re-agent code are decompiler-shaped and do not raise this child above the code gate. Recommended score `84/86` keeps the constructor documented but non-emitting.

### New `ExchangeAlertPaneOnButtonClick` formal block

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
void ExchangeAlertPane::OnButtonClick(int buttonId)
{
    if (buttonId < 1 || buttonId > 2)
        return;

    SlideClose();

    if (buttonId == 1)
        OnPrimaryButton();
    else
        OnSecondaryButton();

    CloseDialogPane();
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

Reason it preserves exact behavior: MCP decompile checks id range `1..2`, calls the inherited slide/close-prep helper, dispatches vtable slots `+0x5c` or `+0x60`, and then calls the inherited close/remove helper. `OnPrimaryButton`/`OnSecondaryButton` are descriptive source-facing names for the two extension slots.

### New `ExchangeAlertPaneSingletonClearHelper` formal block

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
static void ClearExchangeAlertPaneSingleton()
{
    g_pExchangeAlertPane = NULL;
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

Reason it preserves exact behavior: MCP decompile is a single write of zero to `0x0069b330`.

### [UID:00033Z] ExchangeAlertPaneCloseActiveHelper formal block

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
static void CloseActiveExchangeAlertPane()
{
    if (g_pExchangeAlertPane != NULL)
        g_pExchangeAlertPane->Close(1);
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

Reason it preserves exact behavior: MCP decompile calls the active alert object's first vtable slot with argument `1` when the singleton is non-null; the apparent undefined null return is a decompiler artifact because source does nothing on null.

### [UID:0002NF] ExchangeAlertPaneVtableData formal block

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
// ExchangeAlertPane vtable data at 0x0061a1c0-0x0061a260 is compiler-generated
// from the class declaration, destructor/thunks, OnButtonClick, and extension slots.
// The source reconstruction must not emit a literal vtable byte array.
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

### [UID:0001XJ] ExchangeAlertPaneVtables formal block

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
// ExchangeAlertPane vtable/type coverage is represented by the class declaration and
// exact vtable-data child; the compiler emits the binary tables.
[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

### [UID:00004R] ExchangeDialog formal block

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
// ExchangeDialog owns the exact exchange session method bodies emitted by its children.
// This marker intentionally avoids a full class layout because inherited DialogPane
// facets and final member order remain documentation-only, not source-quality C++.
class ExchangeDialog;

[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

### [UID:0003NE] ExchangeDialogVtableData formal block

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
// ExchangeDialog vtable data at 0x00619d28-0x00619dc4 is compiler-generated
// from the ExchangeDialog class and emitted method children. Do not reconstruct it
// as a literal source array.
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

### [UID:00004S] ExchangeItemListPane formal block

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
struct ExchangeItemListRow
{
    unsigned char key;
    unsigned char reserved1;
    unsigned short itemId;
    unsigned char color;
    unsigned char reserved5;
    wchar_t name[256];
};

class ExchangeItemListPane;

[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

Reason it preserves exact behavior: the row struct is directly supported by row offsets and size `0x206`; only a forward class declaration is emitted, so full list-pane layout is not invented.

### [UID:0003NF] ExchangeItemListPaneVtableData formal block

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
// ExchangeItemListPane vtable data at 0x00619dc4-0x00619e88 is compiler-generated
// from the private list-pane declaration, constructor, no-op selection callback,
// and DrawItemEntry override. Do not reconstruct it as a literal source array.
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

### [UID:00004T] ExchangeMoneyEditControlPane formal block

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
// ExchangeMoneyEditControlPane source behavior is carried by the exact activation
// and digit-key handler children. This marker avoids a full inherited text-edit
// layout because only the vtable-routed override behavior is source-quality here.
class ExchangeMoneyEditControlPane;

[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

### [UID:000340] ExchangeMoneyEditControlPaneActivationHelper formal block

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
int ExchangeMoneyEditControlPane::OnActivate()
{
    SetEditActiveState(true, true);
    return TextEditControlPane::OnActivate();
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

Reason it preserves exact behavior: MCP decompile calls inherited `0x00498c00(this, 1, 1)` and tail-returns `0x00494c30(this)`. Method/base names are descriptive source-facing names and cap confidence.

### [UID:000341] ExchangeMoneyEditControlPaneDigitKeyHandler formal block

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
bool ExchangeMoneyEditControlPane::OnKeyEvent(KeyEvent *event)
{
    if (event->type != 10 || event->isKeyDown != 1)
        return false;

    if (event->wideChar < L'0' || event->wideChar > L'9')
        return false;

    CommitCurrentEditText();
    return true;
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

Reason it preserves exact behavior: MCP decompile checks event byte `+4 == 10`, byte `+9 == 1`, UTF-16 digit at `+0x0a`, calls inherited `0x00498d90`, then returns true.

### [UID:0000QV] g_pExchangeAlertPane formal block

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
static ExchangeAlertPane *g_pExchangeAlertPane = NULL;
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

Reason it preserves exact behavior: current MCP storage bytes are zero and all writes/reads treat the slot as the local active alert pointer.

### [UID:0002VZ] exact global storage formal block

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
// Exact storage at 0x0069b330 for g_pExchangeAlertPane is emitted once by
// [UID:0000QV]. Current MCP bytes are 00 00 00 00, not an explicit 0xffffffff
// initializer.
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

Third-party import directive: not applicable.

## Final Recommendation

- Exact changes recommended:
  - Update root `by-file/ExchangeDialog.md` to summarize the empty-emitter family repair and adjust score to `90/88`.
  - Convert [UID:00033W] to a non-emitting split inventory and create the three exact children listed above.
  - Populate formal blocks for the 14 current markers and new child pages exactly as recommended, with implementation allowed to adjust only minor local naming if current docs already establish a better source-facing name.
  - Correct stale singleton initializer and list draw non-emitter statements.
- Exact parent assignments recommended:
  - alert split children: owner/emitter `00004Q` except constructor child blank emitter due below-gate score;
  - money helpers: owner/emitter `00004T`;
  - vtable data/type pages: keep existing class owners and emit only formal no-code comments;
  - global source definition: owner/emitter `0000J9`;
  - exact global storage: keep owner `0000J9` and emit only covered-by comment.
- Exact items left non-emitting:
  - [UID:00033W] as split inventory;
  - new alert constructor child because current evidence does not support final source-quality constructor C++.
- Remaining external work outside assignment scope: none required to accept this report. The constructor child can be upgraded only if later original-source evidence or a coordinated base-UI API recovery proves the inherited helper names and layout; current same-pass evidence has been exhausted.

## Recommended Target Doc Changes

- Target path: `by-file/ExchangeDialog.md`.
- Exact report facts to incorporate:
  - current MCP session state and generated empty-marker list;
  - [UID:00033W] split/container repair;
  - alert class/helper/vtable/global singleton dispositions;
  - money edit helper dispositions;
  - vtable data no-literal-array policy;
  - corrected current bytes for `g_pExchangeAlertPane`;
  - rejected alternatives: new source file, raw helper ownership, literal vtable arrays, TimerMgr ownership.
- Metadata/score/owner/emitter/reconstructable/C++ changes:
  - `COMPLETION:90`
  - `CONFIDENCE:88`
  - keep `CANONICAL_OWNER:FILE`
  - keep `RECONSTRUCTABLE:TRUE`
  - keep `EMITTER_UIDS:0000J9`
  - keep root formal C++ blank unless current project convention prefers a file-route comment.
- Historical/stale assumptions and negative evidence to preserve:
  - old simroot/unrefined source is lead material only;
  - root still does not claim complete full class layouts;
  - the alert constructor remains documented below code gate.

## Recommended Support Doc Changes

- `by-class/ExchangeAlertPane.md`:
  - set `88/90`;
  - populate the class marker formal block;
  - update method inventory to point [UID:00033W] to the three exact children;
  - preserve that full member layout is not emitted.
- `by-memory/0x004b0490-0x004b086b.ExchangeAlertPaneCore.md`:
  - set split/container disposition;
  - `RECONSTRUCTABLE:FALSE`;
  - blank `EMITTER_UIDS`;
  - update `Nested` to account for new children;
  - keep a precise range inventory and no standalone body.
- New `by-memory/0x004b0490-0x004b0819.ExchangeAlertPaneConstructor.md`:
  - recommend `84/86`, owner `00004Q`, `RECONSTRUCTABLE:TRUE`, blank `EMITTER_UIDS`, blank formal C++;
  - document constructor behavior and exact no-code proof.
- New `by-memory/0x004b0820-0x004b0860.ExchangeAlertPaneOnButtonClick.md`:
  - recommend `88/91`, owner/emitter `00004Q`, formal C++ populated.
- New `by-memory/0x004b0860-0x004b086b.ExchangeAlertPaneSingletonClearHelper.md`:
  - recommend `88/92`, owner/emitter `00004Q`, formal C++ populated.
- `by-memory/0x004b0b20-0x004b0b31.ExchangeAlertPaneCloseActiveHelper.md`:
  - recommend `88/92`, formal C++ populated.
- `by-memory/0x0061a1c0-0x0061a260.ExchangeAlertPaneVtableData.md`:
  - recommend `88/92`, formal no-code comment.
- `by-type/by-vtable/ExchangeAlertPaneVtables.md`:
  - recommend `88/92`, formal no-code/children marker.
- `by-class/ExchangeDialog.md`:
  - recommend `88/90`, formal children-route marker, no full layout.
- `by-memory/0x00619d28-0x00619dc4.ExchangeDialogVtableData.md`:
  - recommend `88/92`, formal no-code comment.
- `by-class/ExchangeItemListPane.md`:
  - recommend `89/90`, emit row struct and narrow class/children marker, refresh draw child status.
- `by-memory/0x00619dc4-0x00619e88.ExchangeItemListPaneVtableData.md`:
  - recommend `88/92`, formal no-code comment, remove stale non-emitting draw statement.
- `by-class/ExchangeMoneyEditControlPane.md`:
  - recommend `88/90`, formal class route marker and child inventory refresh.
- `by-memory/0x004b0b40-0x004b0b54.ExchangeMoneyEditControlPaneActivationHelper.md`:
  - recommend `87/90`, formal C++ populated.
- `by-memory/0x004b0b60-0x004b0b96.ExchangeMoneyEditControlPaneDigitKeyHandler.md`:
  - recommend `88/91`, formal C++ populated.
- `by-global/g_pExchangeAlertPane.md`:
  - recommend `88/92`, formal global definition.
- `by-memory/0x0069b330-0x0069b334.g_pExchangeAlertPane.md`:
  - recommend `89/92`, formal covered-by comment, current bytes corrected to zero.

## Score And Metadata Recommendation

- Current score/metadata:
  - root: `88/86`, owner `FILE`, reconstructable true, emitter `0000J9`.
  - 14 child markers: mostly `85-88` completion and `88-91` confidence with blank formal C++.
- Recommended score/metadata:
  - root: `90/88`.
  - exact recommendations are listed in the Function / Child Inventory.
- Score rationale:
  - higher because current MCP resolves exact boundaries, callers, singleton bytes, vtable routes, and implementation-ready formal blocks for all current empty markers;
  - not higher because the alert constructor remains below code gate and several source-facing names are descriptive/inferred rather than original-symbol proven.
- Score-improvement attempt:
  - class markers audited for constructor/destructor route, vtable slots, methods, fields, base class, direct child ownership, and declaration safety;
  - table/global markers audited for source-facing declaration shape and binary-generated storage/table proof;
  - old source and re-agent leads checked and rejected where not source-quality;
  - MCP evidence used for all exact functions/data pages.
- Metadata fields:
  - keep class/file owner relationships;
  - clear `EMITTER_UIDS` only for the mixed [UID:00033W] container and the below-gate constructor child;
  - keep or add emitters for formal code/comment marker pages.

## Open Questions With Attempted Resolution

- Alert constructor final C++:
  - Evidence checked: MCP decompile, current docs, generated output, old unrefined source, re-agent source, support docs, caller xrefs.
  - Resolution: create a below-code-gate exact constructor child with detailed behavior evidence and no formal C++; do not emit guessed helper names or a merged cluster body.
  - Remaining uncertainty: exact original inherited helper names and source-level layout syntax are unavailable in current evidence; this affects only that constructor child, not family ownership or empty-marker repair.
- Money edit activation method name:
  - Evidence checked: vtable slot, decompile, class/vtable docs.
  - Resolution: use descriptive `OnActivate` and cap confidence at `90`; behavior is exact.
- Event field names in digit handler:
  - Evidence checked: decompile offsets, existing generated `KeyEvent` use in ExchangeDialog `OnKeyEvent`.
  - Resolution: use `event->type`, `event->isKeyDown`, and `event->wideChar` as source-facing field names; preserve offset evidence in docs.
- Global storage initializer:
  - Evidence checked: current MCP bytes.
  - Resolution: current storage is zero-filled; stale `0xffffffff` claim must be replaced.

## Exact Manual Supervisor-Owned Coverage Or Tracker Text

- Not applicable. Do not edit `auto-generated/-ag-*`, coverage reports, validator state, or supervisor ledgers manually. The validator should refresh generated output after implementation.

## Follow-Up Actions

- Supervisor actions: validate this report and send implementation callback if accepted.
- A-agent actions: none.
- B011 implementation callback actions after acceptance: apply the recommended by-* doc edits, create new exact child docs for [UID:00033W] split, update this report ledger/checklist with applied proof, run scoped validators, and return an implementation checkpoint.

## Confidence

- Recommendation confidence: high.
- Score confidence: medium-high.
- Remaining uncertainty: limited to non-blocking original method names/source layout for the alert constructor and two money edit virtual name choices. These are handled by a below-code-gate constructor child and confidence caps for emitted helper names.

## Validator Results

- Callback validators were run from `E:\NTK\GhidraBridge\source-3\project-documentation`; all listed commands exited `0`.
- New-child UID assignment and split batch:
  - `python .\tools\validator.py --mode file --file by-memory/0x004b0490-0x004b0819.ExchangeAlertPaneConstructor.md --apply --queue-timeout 240` -> command `000000003137`, `2026-06-30T15:41:25-04:00`, ok count not emitted during UID-insert phase, assigned UID `0004CF`, generated refresh deferred.
  - `python .\tools\validator.py --mode file --file by-memory/0x004b0820-0x004b0860.ExchangeAlertPaneOnButtonClick.md --apply --queue-timeout 240` -> command `000000003138`, `2026-06-30T15:41:31-04:00`, ok count not emitted during UID-insert phase, assigned UID `0004CG`, generated refresh deferred.
  - `python .\tools\validator.py --mode file --file by-memory/0x004b0860-0x004b086b.ExchangeAlertPaneSingletonClearHelper.md --apply --queue-timeout 240` -> command `000000003139`, `2026-06-30T15:41:45-04:00`, ok count not emitted during UID-insert phase, assigned UID `0004CH`, generated refresh deferred.
  - `python .\tools\validator.py --mode file --file by-memory/0x004b0490-0x004b086b.ExchangeAlertPaneCore.md --apply --queue-timeout 240` -> command `000000003140`, `2026-06-30T15:41:55-04:00`, ok `7`, generated refresh deferred.
  - `python .\tools\validator.py --mode file --file by-class/ExchangeAlertPane.md --apply --queue-timeout 240` -> command `000000003141`, `2026-06-30T15:42:07-04:00`, ok `10`, generated refresh deferred.
  - `python .\tools\validator.py --mode file --file by-memory/0x004b0490-0x004b0ba5.ExchangeDialogTail.md --apply --queue-timeout 240` -> command `000000003142`, `2026-06-30T15:42:18-04:00`, ok `7`, generated refresh deferred.
- Alert/global support batch:
  - `python .\tools\validator.py --mode file --file by-memory/0x004b0b20-0x004b0b31.ExchangeAlertPaneCloseActiveHelper.md --apply --queue-timeout 240` -> command `000000003143`, `2026-06-30T15:44:23-04:00`, ok `1`, generated refresh deferred.
  - `python .\tools\validator.py --mode file --file by-memory/0x0061a1c0-0x0061a260.ExchangeAlertPaneVtableData.md --apply --queue-timeout 240` -> command `000000003144`, `2026-06-30T15:44:30-04:00`, ok `1`, generated refresh deferred.
  - `python .\tools\validator.py --mode file --file by-type/by-vtable/ExchangeAlertPaneVtables.md --apply --queue-timeout 240` -> command `000000003145`, `2026-06-30T15:44:43-04:00`, ok `1`, generated refresh deferred.
  - `python .\tools\validator.py --mode file --file by-global/g_pExchangeAlertPane.md --apply --queue-timeout 240` -> command `000000003147`, `2026-06-30T15:44:52-04:00`, ok `1`, generated refresh deferred.
  - `python .\tools\validator.py --mode file --file by-memory/0x0069b330-0x0069b334.g_pExchangeAlertPane.md --apply --queue-timeout 240` -> command `000000003149`, `2026-06-30T15:45:03-04:00`, ok `1`, generated refresh deferred.
- Class/vtable/money batch:
  - `python .\tools\validator.py --mode file --file by-class/ExchangeDialog.md --apply --queue-timeout 240` -> command `000000003153`, `2026-06-30T15:50:57-04:00`, ok `1`, generated refresh deferred.
  - `python .\tools\validator.py --mode file --file by-memory/0x00619d28-0x00619dc4.ExchangeDialogVtableData.md --apply --queue-timeout 240` -> command `000000003154`, `2026-06-30T15:51:03-04:00`, ok `1`, generated refresh deferred.
  - `python .\tools\validator.py --mode file --file by-class/ExchangeItemListPane.md --apply --queue-timeout 240` -> command `000000003155`, `2026-06-30T15:51:12-04:00`, ok `1`, generated refresh deferred; warning `missing_ref_uid 0003U3` was pre-existing/unrelated to B011 edits.
  - `python .\tools\validator.py --mode file --file by-memory/0x00619dc4-0x00619e88.ExchangeItemListPaneVtableData.md --apply --queue-timeout 240` -> command `000000003156`, `2026-06-30T15:51:23-04:00`, ok `1`, generated refresh deferred.
  - `python .\tools\validator.py --mode file --file by-class/ExchangeMoneyEditControlPane.md --apply --queue-timeout 240` -> command `000000003157`, `2026-06-30T15:51:32-04:00`, ok `1`, generated refresh deferred; warnings `missing_ref_uid 0003BK` and `0003LQ` are existing validator-registry reference warnings.
  - `python .\tools\validator.py --mode file --file by-memory/0x004b0b40-0x004b0b54.ExchangeMoneyEditControlPaneActivationHelper.md --apply --queue-timeout 240` -> command `000000003158`, `2026-06-30T15:51:44-04:00`, ok `1`, generated refresh deferred.
  - `python .\tools\validator.py --mode file --file by-memory/0x004b0b60-0x004b0b96.ExchangeMoneyEditControlPaneDigitKeyHandler.md --apply --queue-timeout 240` -> command `000000003159`, `2026-06-30T15:51:51-04:00`, ok `1`, generated refresh deferred.
- Final root/generated refresh:
  - `python .\tools\validator.py --mode file --file by-file/ExchangeDialog.md --apply --wait-generated --queue-timeout 240` -> command `000000003160`, `2026-06-30T15:55:53-04:00`, ok `1`, generated refresh completed, generated refresh command `000000003160`, generated refresh timestamp `2026-06-30T15:55:53-04:00`.
  - Generated `auto-generated/NexusTK/ui/dialogs/ExchangeDialog.cpp` header is current to command `000000003160` and `validator-refreshed-at: 2026-06-30T15:55:53-04:00`.
  - Accepted-family marker check found no `Empty Emitter Marker` rows. [UID:0004CF] constructor child is intentionally absent from generated output because it has blank `EMITTER_UIDS`; former [UID:00033W] container is also non-emitting.
- Targeted supervisor correction callback:
  - `python .\tools\validator.py --mode file --file by-class\ExchangeDialog.md --apply --queue-timeout 240` -> command `000000003182`, `2026-06-30T16:10:04-04:00`, exit `0`, ok `1`, generated refresh deferred.
  - Correction applied: `by-class/ExchangeDialog.md` `## Remaining Caveats` now states [UID:00004S][ExchangeItemListPane](../../../../../by-class/ExchangeItemListPane.md) is current `89/90`, emits the `ExchangeItemListRow` declaration/class marker plus `[[CHILDREN]]`, remains a private control routed through `ExchangeDialog.cpp`, and owns exact list-pane method bodies through [UID:00004S] rather than outer [UID:00004R][ExchangeDialog](../../../../../by-class/ExchangeDialog.md).
- Validator-owned/generated side effects observed: `project-level/-auto-completion-stats.md`, validator metadata, `auto-generated/-ag-research-tracker.md`, generated C++ metadata, and generated coverage metadata were updated by validators only; none were edited manually.

## Changed Files

- Created:
  - `by-memory/0x004b0490-0x004b0819.ExchangeAlertPaneConstructor.md` -> validator-assigned [UID:0004CF].
  - `by-memory/0x004b0820-0x004b0860.ExchangeAlertPaneOnButtonClick.md` -> validator-assigned [UID:0004CG].
  - `by-memory/0x004b0860-0x004b086b.ExchangeAlertPaneSingletonClearHelper.md` -> validator-assigned [UID:0004CH].
- Modified:
  - `by-file/ExchangeDialog.md`
  - `by-class/ExchangeAlertPane.md`
  - `by-class/ExchangeDialog.md`
  - `by-class/ExchangeItemListPane.md`
  - `by-class/ExchangeMoneyEditControlPane.md`
  - `by-global/g_pExchangeAlertPane.md`
  - `by-memory/0x004b0490-0x004b086b.ExchangeAlertPaneCore.md`
  - `by-memory/0x004b0490-0x004b0ba5.ExchangeDialogTail.md`
  - `by-memory/0x004b0b20-0x004b0b31.ExchangeAlertPaneCloseActiveHelper.md`
  - `by-memory/0x0061a1c0-0x0061a260.ExchangeAlertPaneVtableData.md`
  - `by-type/by-vtable/ExchangeAlertPaneVtables.md`
  - `by-memory/0x00619d28-0x00619dc4.ExchangeDialogVtableData.md`
  - `by-memory/0x00619dc4-0x00619e88.ExchangeItemListPaneVtableData.md`
  - `by-memory/0x004b0b40-0x004b0b54.ExchangeMoneyEditControlPaneActivationHelper.md`
  - `by-memory/0x004b0b60-0x004b0b96.ExchangeMoneyEditControlPaneDigitKeyHandler.md`
  - `by-memory/0x0069b330-0x0069b334.g_pExchangeAlertPane.md`
  - `tools/leaser/Agents/Agent-B011/research/0000J9-ExchangeDialog-empty-emitter-family-source-quality.md`
- Renamed:
  - none.
- Report execution: left blank for supervisor.

## Implementation Tracking Checklist

Initial report-only pass:
- [x] Supervisor validation required before implementation. Proof: supervisor accepted this report and sent callback `B011-implement-0000J9-ExchangeDialog-empty-emitter-family-20260630`.
- [x] Target/support docs to update: `by-file/ExchangeDialog.md`; the 14 current marker docs; three new exact children under [UID:00033W]; stale support text on ExchangeItemListPane vtable/global storage pages. Proof: changed-files section lists all touched by-* docs and three new child pages.
- [x] Current target state and actual evidence checked recorded: MCP health/session, function sizes, xrefs, decompiles, bytes, current generated empty markers, and existing docs recorded in this report. Proof: report evidence sections retained; root doc now includes B011 empty-emitter family disposition.
- [x] Claim And Incorporation Ledger updated with destination and verification state for every accepted claim. Proof: every ledger row above is now `applied` with file/validator proof.
- [x] Metadata/score changes to apply: root `90/88`; per-child scores in Function / Child Inventory. Proof: validators `000000003137` through `000000003160` updated/validated accepted scores, including root `90/88`.
- [x] Score-limiting blockers researched to resolution, implementation-ready repair/split recommendation, or rare exact evidence-backed no-improvement proof after all reasonable current routes were exhausted. Proof: constructor child remains no-code below gate; class/table/global docs now carry formal target-specific route/no-code comments or first-draft bodies.
- [x] Owner/emitter/reconstructable changes to apply: [UID:00033W] non-emitting split inventory; constructor child blank emitter; remaining marker pages emit formal code/comment/children markers through current owners. Proof: [UID:00033W] validated by `000000003140`; child UIDs `0004CF/0004CG/0004CH` assigned by `000000003137`-`000000003139`; final generated file contains no accepted-family empty markers.
- [x] Split/rename/new-child changes to apply: create three exact [UID:00033W] children with the names/ranges listed. Proof: new child pages created and validator-assigned UIDs [UID:0004CF], [UID:0004CG], and [UID:0004CH].
- [x] Source-placement, range/split/padding/reclassification, or IDA rename/type/comment changes to apply or confirm not applicable. Proof: split/source route documented in root, [UID:00033W], [UID:00004Q], and [UID:00014V]; no IDA DB edits requested or made.
- [x] First-draft C++ or no-code proof to apply: exact formal blocks supplied for all recommended emitting/no-code pages. Proof: formal blocks inserted into [UID:0004CG], [UID:0004CH], [UID:00033Z], [UID:0002NF], [UID:0001XJ], [UID:00004R], [UID:0003NE], [UID:00004S], [UID:0003NF], [UID:00004T], [UID:000340], [UID:000341], [UID:0000QV], and [UID:0002VZ]; [UID:0004CF] remains blank by proof.
- [x] Third-party import directive to apply or confirm not applicable: not applicable. Proof: no third-party source/import directive used.
- [x] Exact target/support doc facts to incorporate at report-level detail. Proof: root and support docs now include split inventory, child UIDs, singleton byte correction, stale draw correction, vtable no-literal policy, rejected alternatives, and score rationale.
- [x] Historical/stale assumptions, rejected alternatives, and negative evidence to preserve. Proof: root and support docs preserve old simroot/Wave as lead-only, singleton `0xffffffff` correction, no literal vtable arrays, no standalone raw helper/source file, no TimerMgr, and no full invented layouts.
- [x] Wave2/Wave3 mentions or artifacts encountered and ignored/rejected as stale, if applicable. Proof: root/status and class docs retain old generated/simroot material as lead-only where relevant.
- [x] Open questions to close or document as evidence-backed unresolved. Proof: constructor helper/layout uncertainty is captured in [UID:0004CF] no-code proof; money edit method names are confidence-capped but formalized on [UID:000340]/[UID:000341].
- [x] Validators to run after callback. Proof: Validator Results section records every scoped validator and the final root `--wait-generated` command.
- [x] Generated report refresh expected or explicit manual supervisor-owned coverage/tracker text to apply. Proof: final root validator `000000003160` completed generated refresh; no manual tracker/coverage edits were made.

Implementation callback pass:
- [x] Report accepted by supervisor for implementation. Proof: callback received for accepted report and assignment `B011-implement-0000J9-ExchangeDialog-empty-emitter-family-20260630`.
- [x] All accepted target/support doc details incorporated at report-level detail. Proof: changed-files section and ledger map every accepted claim to an applied file/validator result.
- [x] Claim And Incorporation Ledger updated with destination and verification state for every accepted claim. Proof: ledger now has no pending rows.
- [x] Metadata/score/owner/emitter/split/rename/C++ changes applied or explicitly not applied with reason. Proof: validators applied score/registry/formal blocks; by-file root remains by-file schema without unsupported `RECONSTRUCTABLE`/`EMITTER_UIDS` headers per `by-file/-guidance.md`.
- [x] Historical/stale assumptions, rejected alternatives, and negative evidence preserved. Proof: root/support docs preserve singleton byte correction, draw-emitter correction, no literal vtable arrays, no TimerMgr/VectorHelpers relocation, and old generated source as lead material only.
- [x] Open questions resolved or documented with evidence-backed unresolved rationale. Proof: [UID:0004CF] constructor remains below gate by exact no-code proof; money edit names are documented as descriptive confidence caps.
- [x] Validators run and results recorded. Proof: Validator Results section lists command IDs/timestamps/exit/ok counts.
- [x] Generated report refresh completed by validator or explicit manual supervisor-owned coverage/tracker text supplied/confirmed unchanged. Proof: generated `ExchangeDialog.cpp` header is command `000000003160`/timestamp `2026-06-30T15:55:53-04:00`; accepted-family empty-marker search found no matches.
- [x] Targeted supervisor correction for stale `ExchangeItemListPane` support state in `by-class/ExchangeDialog.md` applied. Proof: `## Remaining Caveats` now says [UID:00004S] is current `89/90`, preserves the private-control/source-route and method-ownership distinction, and scoped validator `000000003182` returned ok `1`.
- [x] Remaining unapplied accepted items listed with exact blocker. Proof: none remain unapplied; no unchecked blockers.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B011","command_id":"000000004165","destination_path":"executed-b-agent-research/B011/0000J9-ExchangeDialog-empty-emitter-family-source-quality.md","details":"legacy registry reconstruction","event":"executed","source_path":"tools/leaser/Agents/Agent-B011/research/0000J9-ExchangeDialog-empty-emitter-family-source-quality.md","timestamp":"2026-06-30T16:15:18","uid":"0000J9"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
