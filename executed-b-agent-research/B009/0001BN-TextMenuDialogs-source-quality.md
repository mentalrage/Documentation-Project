** TARGET-REPORT-UID:0001BN **
** AUTHOR-AGENT-ID:B009 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | Medium **
# 0001BN TextMenuDialogs Source-Quality Report


## Finalized Report / Current Recommendation

- Current recommendation after Gate 1 repair: convert [UID:0001BN] `by-memory/0x00517ec0-0x0051a417.TextMenuDialogs.md` from a low-score empty-emitter aggregate into a reviewed non-emitting split/container for the text-menu source island, and create implementation-ready exact child pages for the remaining source-bearing `TextMenuDialog` bodies and no-route raw serializers.
- Final disposition: UID0001BN itself should keep a blank formal `RECONSTRUCTION_CPP CODE` block because one aggregate body would duplicate existing children and mix several classes. The implementation improvement is not "future research"; it is a concrete split plan: exact children for `TextMenuDialog::SendMenuRequestPacket`, constructor, paint, action, scroll-button update, and three raw opcode `0x39` serializer bodies, with existing [UID:0000ET], [UID:0000ER], [UID:000238], and [UID:000239] marked already-present.
- Implementation callback status: accepted report SHA `7D78E3DDD6E80A6AE2D6070352DF216195CBED3D67025C1C113B5B08DDA4E7C0` was applied by B009. The target now records current MCP session `60724697` evidence, supersedes the prior unchanged-score/no-child conclusion, sets UID0001BN to a non-emitting split/container (`COMPLETION:90`, `CONFIDENCE:92`, owner `0000OP`, reconstructable true, blank target formal C++, and blank target `EMITTER_UIDS`), and links exact child pages for the source-bearing and raw serializer subranges.
- Confidence: high for owner/range/source placement/split-container disposition; high for exact child ranges and raw-helper no-code disposition; medium-high for the supplied source-emitting child formal C++ insertion text, with the large constructor/paint/action blocks still capped by support-helper naming and source-style inference.

## Supporting Research

- Lifecycle/status notes: this report began as the Medium report-only artifact for UID0001BN and passed supervisor Gate 1. During the implementation callback, B009 edited only accepted by-* target/support/child docs and this report, ran scoped validators, and did not run `execute_report`, lifecycle/archive/registry commands, or manual report moves. Generated files and validator state were affected only by validator side effects.
- MCP status: `server_health` for `60724697` returned `status:"ok"`, module `NexusTK.exe`, imagebase `0x400000`, `auto_analysis_ready:true`, `hexrays_ready:true`, and `strings_cache_ready:true`.
- Documentation context: current docs already include B010/B012/B013 support repairs for `TextInputMenuDialog`, `TextMenuItemList`, `MenuDialogFactoryHelpers`, `TextInputMenuDialogReplyPacketHelper`, and the text-menu vtable family. This report rechecks whether the broad UID0001BN target itself should now emit C++ or be rescored.

## Target

- Target UID: `0001BN`.
- Target path: `by-memory/0x00517ec0-0x0051a417.TextMenuDialogs.md`.
- Source queue/report row: `auto-generated/-ag-research-tracker.md` -> `## by-memory` -> `### Not-Covered Files - Reconstructable`, row `86/88`, combined `87.0`, reconstructable true.
- Current supervisor classification: Medium B-agent implementation callback applied; awaiting supervisor execution/Gate 2 review.
- Current scores and parent state after callback: target is `COMPLETION:90`, `CONFIDENCE:92`, `CANONICAL_OWNER:0000OP`, `RECONSTRUCTABLE:TRUE`, blank `EMITTER_UIDS`, blank optional position, blank formal C++.

## Current Target State

- Current metadata: `90/92`, owner [UID:0000OP] `TextMenuDialogs`, reconstructable true, blank target `EMITTER_UIDS`, blank optional position, blank formal target C++.
- Current owner/emitter/reconstructable state: semantically owned by the `TextMenuDialogs.cpp` source bucket in `NexusTK/ui/dialogs/`; UID0001BN itself is now a reviewed non-emitting split/container while exact source-bearing child pages emit through [UID:0000OP].
- Current C++/emitter state: formal target C++ block is blank by design. Generated `auto-generated/NexusTK/ui/dialogs/TextMenuDialogs.cpp` from validator command `000000006297`, refreshed `2026-07-04T12:29:29-04:00`, emits the new source-bearing child UIDs [UID:0004H8], [UID:0004H9], [UID:0004HA], [UID:0004HC], and [UID:0004HD] plus prior support children, while UID0001BN remains non-emitting and raw serializer children [UID:0004HB], [UID:0004HE], and [UID:0004HF] remain blank/no-route by evidence.
- Current open questions/blockers: no implementation blocker remains for the accepted callback. Original-name polish and raw serializer route recovery remain confidence caps only; they do not require target-level aggregate C++ or prevent the current split/container disposition.
- Related target/support docs checked: `by-file/TextMenuDialogs.md`, `by-class/TextMenuDialog.md`, `by-class/TextMenuItemList.md`, `by-class/TextInputMenuDialog.md`, `by-memory/0x00517450-0x00517d23.MenuDialogFactoryHelpers.md`, `by-memory/0x0051a420-0x0051a51c.TextInputMenuDialogReplyPacketHelper.md`, `by-type/by-vtable/MerchantMenuDialogVtableFamily.md`, `by-type/by-vtable/TextMenuDialogVtables.md`, generated `auto-generated/NexusTK/ui/dialogs/TextMenuDialogs.cpp`, and executed reports B010/B012/B013/B001.
- Current artifact/lifecycle status: this report is the post-callback implementation artifact awaiting supervisor execution/Gate 2 review. B009 ran scoped validators and did not run lifecycle or execution commands.

## Executive Recommendation

Keep UID0001BN attached to [UID:0000OP], but change its disposition from empty-emitter aggregate to non-emitting split/container. The target is not an exact method page; it spans `TextMenuDialog`, `TextMenuItemList`, `TextInputMenuDialog`, raw packet serializers, padding, and adjacent source relationships. A target-wide body remains wrong, but leaving the target unchanged is also wrong because the remaining source-bearing `TextMenuDialog` subranges are now identified and can be split.

The implementation-ready improvement has been applied as a split/container update plus child-page creation. UID0001BN documents the whole source island and carries no direct emitter, while exact child pages carry the remaining source output under [UID:0000OP]. Existing children/support pages already cover factory helpers, `TextMenuItemList`, `TextInputMenuDialog`, and adjacent input reply helper; the accepted callback added the exact `TextMenuDialog` method/raw-helper child set listed in this report.

## Supervisor Active Recheck

- Triggering instruction: new Medium B-agent report-only research for UID0001BN, then supervisor MCP restore with live session `60724697`.
- Split repair required before final report: required. The earlier report-only conclusion that no immediate split repair was required is superseded. Current docs already split factory helper [UID:000238], adjacent reply helper [UID:000239], class-level `TextMenuItemList` [UID:0000ET], `TextInputMenuDialog` [UID:0000ER], and vtables [UID:00031Y], but UID0001BN still contains un-emitted source-bearing `TextMenuDialog` method bodies and raw serializers.
- Source-bearing child status: exact existing source-bearing children/support pages were checked and marked already-present. The callback created exact children for `0x00517ec0-0x00517f26` [UID:0004H8], `0x00517f30-0x00518e17` [UID:0004H9], `0x00518e20-0x00519102` [UID:0004HA], `0x00519110-0x0051920c` [UID:0004HB], `0x00519210-0x005194b1` [UID:0004HC], `0x005194c0-0x00519511` [UID:0004HD], `0x005195f0-0x0051971d` [UID:0004HE], and `0x00519720-0x0051983a` [UID:0004HF].

## Inference Research Guidance Check

- `by-structure.md` and the B-agent workflow were applied: source facts were separated into by-memory aggregate evidence, by-class declarations, by-file source placement, and by-vtable compiler-generated declarations.
- Existing documentation assumptions treated as uncertain: old local MCP session references, generated source as authority, decompiler temporary names, no-route raw helper status, and broad aggregate C++ eligibility.
- IDA facts: MCP function inventory, bytes, xrefs, callees, and decompile/disasm snippets from session `60724697`.
- Documentation evidence: current by-* support pages and executed B010/B012/B013 reports.
- Inference: source-facing names such as `SendMenuRequestPacket`, `ForwardOwnerSelectionState`, `DrawListItem`, `OnButtonPress`, `UpdateSubmitButtonState`, and `SendInputReply` are accepted descriptive/source-quality names from support docs, not new original-name proof from this target.
- Wave2/Wave3: generated source and old generated metadata were used only as leads/current-output state. No stale Wave2/Wave3 source was accepted as authority.

## Heuristic / Inference Reanalysis And Validation

- Owner/source placement: [UID:0000OP] `TextMenuDialogs` remains the best source bucket. Evidence: constructor routes from factory helpers, vtable stores from text-menu constructors, generated `TextMenuDialogs.cpp`, and source-family docs. Rejected moving the target to `MerchantDialogPane`, `ItemMenuDialogs`, `SpellMenuDialogs`, `ArgumentedMenuDialogs`, `PacketBuffer`, or `TextEditControlPane`.
- Range/split/padding: live MCP confirms 12 modeled starts in `0x00517ec0-0x0051a420` and no modeled functions at raw helper starts `0x00519110`, `0x005195f0`, `0x00519720`, or successor raw `0x0051a420`. Padding bytes are all `0xcc` between modeled/raw bodies. Existing half-open target range ending at `0x0051a417` remains correct because `0x0051a417-0x0051a420` is padding before adjacent [UID:000239].
- Raw helper roles: `0x00519110`, `0x005195f0`, and `0x00519720` are complete opcode `0x39` serializers, but current xref checks return zero direct xrefs to each raw start. They should remain documented as raw no-route text-menu/list helpers, not emitted as ordinary target-level C++ methods.
- Generated names and decompiler artifacts: `sub_517EC0`, `sub_519210`, `sub_51A280`, stack-cookie scaffolding, `Destination[257]`, raw `unk_69B3FC`, and scalar deleting destructor labels are rejected as final source names. Current support docs already replace them with descriptive source names where safe.
- Caller/reachability: `TextMenuDialog` and `TextInputMenuDialog` constructors have factory callers; `TextMenuItemList` constructor has only `TextMenuDialog` callers; `AddTextEntry` has one `TextMenuDialog` caller; `0x00519840` and `TextInput` action/update are vtable-routed; raw serializers have no direct refs.
- C++ readiness: exact children/support pages already emit source where the current evidence supports it. UID0001BN as a whole is not eligible for a single formal C++ block because it would duplicate emitted child C++ and mix multiple class bodies plus no-route raw helpers. The repair resolution is to create exact by-memory children for the remaining source-bearing bodies and make UID0001BN a non-emitting split/container.
- Resolved blockers: final original spellings for some `TextMenuDialog` helpers are still not externally proven, but that does not block child-page creation because the current class page already uses stable descriptive names and MCP confirms exact ranges/roles. Raw serializer routing remains unproven, so the two list raw helpers and one text-menu raw helper should become exact no-route raw-helper child pages with blank formal C++ and explicit no ordinary method emission until pointer/caller evidence is recovered.

## Evidence Standards Used

- Evidence types used: IDA MCP `server_health`, `lookup_funcs`, `entity_query`, `get_bytes`, `xrefs_to`, `callees`, `decompile`, and `disasm`; current by-* docs; generated `TextMenuDialogs.cpp`; executed B reports; tracker/stat rows.
- Evidence strength: high for range, modeled starts, raw no-function starts, xref/callee relationships, current generated output, and source owner. Confidence is capped because several helper names are inferred and three raw serializers remain no-route despite strong behavior.
- Evidence ladder: direct MCP facts override generated output; current by-* support docs and executed reports are treated as incorporated documentation evidence; generated source is only output-state proof.

## Evidence Checked

- IDA MCP/manual-disassembly/raw-byte checks performed: health for `60724697`; `lookup_funcs` on target starts/boundaries; `entity_query` range inventory; `get_bytes` for prologues/padding/end boundary; `xrefs_to` for constructors, raw helpers, vtables, and adjacent helper; `callees` for representative methods; `decompile` for `TextMenuDialog` constructor/paint/action/update, request helper, list constructor/add/draw, and text-input action/update; `disasm` for raw helpers `0x00519110`, `0x005195f0`, `0x00519720`.
- by-* docs, support docs, old reports, generated reports, and trackers checked: target, `TextMenuDialogs` file, three class pages, factory helper, adjacent reply helper, vtable docs, generated `TextMenuDialogs.cpp`, `auto-generated/-ag-research-tracker.md`, `project-level/-auto-completion-stats.md`, executed B010/B012/B013 reports.
- Negative checks performed: raw helper starts have no direct xrefs; `0x0051a420` is outside target and has no direct xrefs; generated UID0001BN remains an Empty Emitter Marker; vtable refs route class methods but do not justify one aggregate C++ block.
- Failed/unavailable/skipped checks and why: no failed MCP calls after restore. During the later implementation callback, scoped validators were run only for changed by-* docs and child pages; no lifecycle/report execution commands were run.

## Claim And Incorporation Ledger

| Claim ID | Claim | Confidence | Evidence | Destination doc/section | Action | Verification state |
| --- | --- | --- | --- | --- | --- | --- |
| C-0001BN-01 | Supersede the earlier unchanged-score conclusion: set UID0001BN to reviewed non-emitting split/container metadata `COMPLETION:90`, `CONFIDENCE:92`, owner `0000OP`, reconstructable true, blank optional position, blank formal C++, and blank target `EMITTER_UIDS` once child emitters carry exact source. | High | Gate 1 repair; live MCP/generator show aggregate/index source shape and identified child work. | `by-memory/0x00517ec0-0x0051a417.TextMenuDialogs.md` header, Item Summary, Reconstruction Status, Score Rationale, Changes. | applied | Verified by validator `000000006293` exit 0 ok 1; target now `90/92`, blank target emitter/C++. |
| C-0001BN-02 | Current MCP session `60724697` should be recorded as the fresh evidence source. | High | `server_health` ok, Hex-Rays ready. | Target `IDA MCP Evidence`; `by-file/TextMenuDialogs.md` B009 source-quality paragraph. | applied | Verified by target/support text and validator `000000006293` / `000000006294`. |
| C-0001BN-03 | The range has 12 modeled function starts and three interior raw serializer bodies; the current half-open range ending at `0x0051a417` is correct. | High | `entity_query`, `lookup_funcs`, `get_bytes`. | Target `Covered Ranges`, `Range And Boundary Evidence`, `IDA MCP Evidence`. | applied | Verified by target validator `000000006293`; covered ranges now link [UID:0004H8]-[UID:0004HF]. |
| C-0001BN-04 | Raw serializers `0x00519110`, `0x005195f0`, and `0x00519720` are behaviorally text-menu/list-owned but have zero direct xrefs; create exact no-route raw-helper child pages with the blank formal header/begin/end insertion text in this report rather than ordinary method emitters. | High | `lookup_funcs` not functions; `xrefs_to` zero; raw disassembly shows opcode `0x39` payloads. | [UID:0004HB], [UID:0004HE], [UID:0004HF]; target raw-helper notes; class/file cross-links. | applied | Child validators `000000006282`, `000000006286`, `000000006287` assigned/accepted blank no-route pages; support validators `000000006294`/`000000006296`. |
| C-0001BN-05 | `TextMenuItemList` source C++ is already present at same-or-greater detail through [UID:0000ET]. | High | Class formal block and generated output contain constructor, destructor, `AddTextEntry`, `ForwardOwnerSelectionState`, `DrawListItem`. | `by-class/TextMenuItemList.md`; generated `TextMenuDialogs.cpp`; target generated-output proof. | already-present plus cross-links applied | Ordinary source left unchanged; raw child cross-links to [UID:0004HE]/[UID:0004HF] applied and validator `000000006296` exit 0 ok 1. |
| C-0001BN-06 | `TextInputMenuDialog` class declaration and adjacent reply helper source are already present at same-or-greater detail through [UID:0000ER] and [UID:000239]. | High | Class/reply formal blocks and generated output show wide-input `SendInputReply`. | `by-class/TextInputMenuDialog.md`, [UID:000239], generated output proof. | already-present | No edit required; generated `TextMenuDialogs.cpp` command `000000006297` still emits [UID:0000ER] and [UID:000239]. |
| C-0001BN-07 | [UID:000238] factory helpers already emit formal C++ in `TextMenuDialogs.cpp` and are support context for this aggregate. | High | [UID:000238] formal block and generated output. | [UID:000238]; target/source-route notes. | already-present | No edit required; generated `TextMenuDialogs.cpp` command `000000006297` still emits [UID:000238]. |
| C-0001BN-08 | Feature-family owner alternatives remain rejected: Merchant base, item/spell/argumented owners, PacketBuffer, TextEditControlPane, and raw compiler/vtable artifacts. | High | Caller/xref/vtable docs and current MCP checks. | Target `IDA MCP Evidence`, ownership/source placement/rejected alternatives, Changes. | applied | Verified by target validator `000000006293`; support source-root paragraph also applied in `by-file/TextMenuDialogs.md` validator `000000006294`. |
| C-0001BN-09 | Generated `TextMenuDialogs.cpp` should be cited as current output-state proof: UID0001BN is non-emitting while exact children/supports emit. | High | Generated header `000000006297`; emitted child UIDs [UID:0004H8], [UID:0004H9], [UID:0004HA], [UID:0004HC], [UID:0004HD]. | Target `Reconstruction Notes` / `Score Rationale`; report validator results. | applied | `--wait-generated` validator `000000006297` completed; generated header matches command/timestamp and Select-String confirms child emissions. |
| C-0001BN-10 | Create source-emitting child pages for `TextMenuDialog::SendMenuRequestPacket`, constructor, `OnPaint`, `OnDialogAction`, and `UpdateScrollButtons`; use the exact formal `RECONSTRUCTION_CPP CODE` insertion text in this report, wire them to owner/emitter `0000OP`, and cross-link from `by-class/TextMenuDialog.md` and the target container. | High | MCP decompile/caller/vtable evidence; class method map already names the bodies; exact formal insertion blocks added. | [UID:0004H8], [UID:0004H9], [UID:0004HA], [UID:0004HC], [UID:0004HD]; `by-class/TextMenuDialog.md`; target child inventory. | applied | Child validators `000000006279`-`000000006281`, `000000006283`, `000000006285`; support validator `000000006295`; generated output `000000006297` emits the five child bodies. |
| C-0001BN-11 | Preserve support docs already present for `TextMenuItemList`, `TextInputMenuDialog`, factory helpers, reply helper, and vtables; update only cross-links if child creation changes the parent inventory. | Medium-high | Support docs checked and current generated output matches them. | `by-file/TextMenuDialogs.md`, `by-class/TextMenuDialog.md`, `by-class/TextMenuItemList.md`; TextInput/factory/reply/vtable docs unchanged. | applied/already-present | Cross-links/source-root inventory applied where needed; TextInput/factory/reply/vtable support excluded from edits because same-or-greater detail was already present. |

## Positive Evidence Summary

- Direct facts supporting recommendation: `60724697` MCP confirms the target range, 12 modeled starts, raw no-function serializer starts, boundary padding, constructor/factory callers, vtable store refs, and current callees.
- Corroborating documentation/generated-report evidence: `TextMenuDialogs.cpp` emits exact support/source children and keeps UID0001BN as an expected Empty Emitter Marker. Current class/file/vtable docs all route the text-menu family through [UID:0000OP].
- Strongest inference chain: a broad source island containing several class methods plus raw helper islands should be documented as a coordination aggregate. The exact reconstructable bodies should be emitted from narrower pages; emitting UID0001BN directly would duplicate or distort that structure.

## IDA MCP Facts

- Function/range facts: `lookup_funcs` confirms modeled starts at `0x00517ec0` size `0x66`, `0x00517f30` size `0xee7`, `0x00518e20` size `0x2e2`, `0x00519210` size `0x2a1`, `0x005194c0` size `0x51`, `0x00519520` size `0x61`, `0x00519590` size `0x58`, `0x00519840` size `0xb`, `0x00519850` size `0x81`, `0x005198e0` size `0x996`, `0x0051a280` size `0x155`, and `0x0051a3e0` size `0x37`.
- Data/table/padding facts: `get_bytes` shows `0xcc` padding at `0x00517f26-0x00517f30`, `0x00519102-0x00519110`, `0x005195e8-0x005195f0`, `0x0051971d-0x00519720`, and `0x0051a417-0x0051a420`. Raw starts begin with normal prologues but are not IDA-modeled functions.
- Xref facts: `0x00517ec0` has seven reuse callers across text, input, item, spell, and argumented menu action handlers. `0x00517f30` and `0x005198e0` each have four factory/wrapper constructor refs. `0x00519520` has two constructor refs from `TextMenuDialog`; `0x00519590` has one add-entry caller. Raw starts `0x00519110`, `0x005195f0`, `0x00519720`, and `0x0051a420` have zero xrefs.
- Vtable/global/type facts: `0x0061ecac`, `0x0061ed48`, and `0x0061ee0c` each have constructor-store xrefs from `TextMenuDialog`, `TextMenuItemList`, and `TextInputMenuDialog` constructors respectively. Vtable refs to `0x00519840`, `0x0051a280`, and `0x0051a3e0` confirm virtual route for those narrow functions.
- Negative IDA facts: no direct route was found for raw serializer starts; no current evidence supports moving the target to a generic packet or edit-control owner; no target-level single function exists for UID0001BN.

## Function / Child Inventory

| Range / Item | UID / Path | Role | Reconstructable | Direct Parent | Score | Status |
| --- | --- | --- | --- | --- | --- | --- |
| `0x00517ec0-0x0051a417` | [UID:0001BN] target | Broad text-menu class/raw-helper aggregate | TRUE | [UID:0000OP] | recommend `90/92` | Convert to non-emitting split/container; keep blank aggregate C++; create exact children. |
| `0x00517450-0x00517d23` | [UID:000238] | Menu dialog factory helpers | TRUE | [UID:0000OP] | `90/93` | Already emits formal C++. |
| `0x00517ec0-0x00519510` | [UID:0000ES] class context | `TextMenuDialog` methods | TRUE | [UID:0000OP] | `86/86` | Class marker blank; target documents method island. |
| `0x00519520-0x005198d0` | [UID:0000ET] class context | `TextMenuItemList` private list | TRUE | [UID:0000OP] | `89/88` | Already emits class/method C++. |
| `0x005198e0-0x0051a417` | [UID:0000ER] class context | `TextInputMenuDialog` constructor/action/update | TRUE | [UID:0000OP] | `88/88` | Already emits declaration; exact bodies remain in aggregate/support. |
| `0x0051a420-0x0051a51c` | [UID:000239] adjacent helper | `TextInputMenuDialog::SendInputReply` raw helper | TRUE | [UID:0000ER] | `90/89` | Already emits formal C++. |
| `0x0061ecac-0x0061ee9c` | [UID:00031Y] | Text menu vtables | TRUE/source-declared | [UID:0000OP] | `87/91` | Blank C++; compiler-generated vtable output. |

## Implementation-Ready Split / Child Plan

UID0001BN is now the non-emitting split/container for the complete `0x00517ec0-0x0051a417` island. The following exact children were the implementation-ready recommendations and were created during the callback with validator-assigned UIDs.

| Proposed child path | Range | Owner | Emitter | Reconstructable | Completion / Confidence | Formal C++ disposition |
| --- | --- | --- | --- | --- | --- | --- |
| `by-memory/0x00517ec0-0x00517f26.TextMenuDialogSendMenuRequestPacket.md` | `0x00517ec0-0x00517f26` | [UID:0000ES] / source file [UID:0000OP] | `0000OP` | TRUE | `91/93` | Source-emitting child. First draft is small and implementation-ready: send opcode `0x43`, subtype byte `1`, dialog id at `+0x270`, trailing zero, send length `6`, then close the dialog. |
| `by-memory/0x00517f30-0x00518e17.TextMenuDialogConstructor.md` | `0x00517f30-0x00518e17` | [UID:0000ES] / [UID:0000OP] | `0000OP` | TRUE | `88/90` | Source-emitting child with exact formal insertion text in `Formal Child Reconstruction C++ Insertion Text`; placed on the child, not UID0001BN. |
| `by-memory/0x00518e20-0x00519102.TextMenuDialogOnPaint.md` | `0x00518e20-0x00519102` | [UID:0000ES] / [UID:0000OP] | `0000OP` | TRUE | `89/91` | Source-emitting child with exact formal insertion text in `Formal Child Reconstruction C++ Insertion Text`. |
| `by-memory/0x00519110-0x0051920c.TextMenuDialogRawSelectionReplySerializer.md` | `0x00519110-0x0051920c` | [UID:0000ES] / [UID:0000OP] | blank | TRUE / raw no-route | `86/91` | Exact raw-helper child with blank formal C++. It serializes opcode `0x39`, fields `+0x274`, `+0x270`, selected item id from `+0x280 + index*2`, optional extra string from `+0x27c` when `+0x279` is set, trailing zero, `<0x100` guard, and packet send. No direct xrefs; do not emit as ordinary source until route evidence exists. |
| `by-memory/0x00519210-0x005194b1.TextMenuDialogOnDialogAction.md` | `0x00519210-0x005194b1` | [UID:0000ES] / [UID:0000OP] | `0000OP` | TRUE | `90/92` | Source-emitting child with exact formal insertion text in `Formal Child Reconstruction C++ Insertion Text`. |
| `by-memory/0x005194c0-0x00519511.TextMenuDialogUpdateScrollButtons.md` | `0x005194c0-0x00519511` | [UID:0000ES] / [UID:0000OP] | `0000OP` | TRUE | `91/92` | Source-emitting child with exact formal insertion text in `Formal Child Reconstruction C++ Insertion Text`. |
| `by-memory/0x005195f0-0x0051971d.TextMenuItemListRawSelectedRowReplySerializer.md` | `0x005195f0-0x0051971d` | [UID:0000ET] / [UID:0000OP] | blank | TRUE / raw no-route | `86/91` | Exact raw-helper child with blank formal C++. It reads selected index at inherited `ListPane +0x134`, fetches row data through `ListPane::GetSelectedEntry`, serializes opcode `0x39`, `m_menuType`, `m_menuId`, row `itemId`, optional owner extra string, trailing zero, `<0x100` guard, and packet send. No direct xrefs; do not duplicate [UID:0000ET] ordinary methods. |
| `by-memory/0x00519720-0x0051983a.TextMenuItemListRawExplicitIdReplySerializer.md` | `0x00519720-0x0051983a` | [UID:0000ET] / [UID:0000OP] | blank | TRUE / raw no-route | `86/91` | Exact raw-helper child with blank formal C++. Same packet shape as the selected-row serializer, but uses an explicit unsigned short item id argument. No direct xrefs; keep non-emitting until route evidence exists. |

Child creation should also update `by-class/TextMenuDialog.md` from blank class-level method map to source-ready cross-links for these exact pages. `by-class/TextMenuItemList.md` already emits ordinary list methods; only cross-links to the two no-route raw children are needed if they are created.

## Formal Child Reconstruction C++ Insertion Text

The following blocks are the exact formal insertion text recommended for supervisor-approved child pages. They intentionally avoid UID0001BN aggregate C++ and avoid decompiler temporaries, SEH state variables, raw vtable stores, stack-cookie scaffolding, and raw offsets except where field names are still documented support aliases. Support declarations required by the constructor/action/paint blocks are listed immediately after the source blocks.

For source-emitting children, the `<insert the C++ block below>` line in each header template is an instruction, not literal target text; the adjacent `cpp` block is the exact content to place between `RECONSTRUCTION_CPP CODE:BEGIN` and `RECONSTRUCTION_CPP CODE:END`.

### Child `0x00517ec0-0x00517f26.TextMenuDialogSendMenuRequestPacket`

Recommended header:

```text
*** COMPLETION:91 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:93 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000ES | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000OP | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
<insert the C++ block below>
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

Recommended formal `RECONSTRUCTION_CPP CODE` insertion:

```cpp
void TextMenuDialog::SendMenuRequestPacket()
{
    PacketBuffer packet;

    packet.WriteUInt8(0x43);
    packet.WriteUInt8(1);
    packet.WriteUInt32(m_dialogId);
    packet.WriteUInt8(0);

    g_packetSender.Send(packet.Data(), packet.Size());
    Close();
}
```

### Child `0x00517f30-0x00518e17.TextMenuDialogConstructor`

Recommended header:

```text
*** COMPLETION:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000ES | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000OP | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
<insert the C++ block below>
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

Recommended formal `RECONSTRUCTION_CPP CODE` insertion:

```cpp
TextMenuDialog::TextMenuDialog(bool hasExtraString,
                               const RectBounds& bounds,
                               const unsigned char *payload,
                               unsigned char merchantDialogType)
    : MerchantDialogPane(kTextMenuDialogTitle, true, true),
      m_dialogId(0),
      m_dialogType(merchantDialogType),
      m_itemCount(0),
      m_hasExtraString(hasExtraString),
      m_extraString()
{
    TextMenuPayloadReader reader(payload);
    RectBounds controlBounds;

    m_replyType = reader.ReadUInt8();
    m_dialogId = reader.ReadUInt32();
    const ObjectImageDescriptor objectImage = reader.ReadObjectImage();
    const std::wstring promptText = reader.ReadAnsiStringAsWide();

    if (m_hasExtraString)
        m_extraString = reader.ReadStringObject();

    TextMenuItemList *list = new TextMenuItemList(m_replyType, m_dialogId, this);
    m_itemCount = reader.ReadUInt8();

    if (g_useHighResolutionTextMenuLayout) {
        AddImageControl(RectBounds(0, 0, 315, 353), L"DLGMERC1.EPF", 0, kDialogImagePalette);
        AddButtonControl(RectBounds(44, 310, 107, 334), kButtonCancel, 14);
        AddButtonControl(RectBounds(121, 310, 184, 334), kButtonOk, 16);
        AddButtonControl(RectBounds(198, 310, 261, 334), kButtonClose, 15);
        AddObjectImageControl(RectBounds(20, 20, 94, 128), objectImage);
        AddStaticTextControl(RectBounds(105, 40, 276, 128), promptText, true, 128, 143);

        for (unsigned char i = 0; i < m_itemCount; ++i) {
            const std::wstring label = reader.ReadAnsiStringAsWide8();
            const unsigned short itemId = reader.ReadUInt16();
            m_itemIds[i] = itemId;
            list->AddTextEntry(itemId, label.c_str());
        }

        AddListControl(RectBounds(36, 144, 294, 288), list);
        SetDefaultControlId(1);
        SetCancelControlId(3);
        SetFocusedControlId(6);
        ApplyBounds(bounds, false);
        InitDialogImage(L"DLGMERC1.EPF", 0);
    } else {
        if (m_itemCount <= 6) {
            AddButtonControl(RectBounds(92, 18 * m_itemCount + 192, 164, 18 * m_itemCount + 208), kButtonOk, 16);
            AddButtonControl(RectBounds(169, 18 * m_itemCount + 192, 241, 18 * m_itemCount + 208), kButtonClose, 15);
            AddObjectImageControl(RectBounds(60, 38, 97, 93), objectImage);
            AddStaticTextControl(RectBounds(129, 36, 273, 132), promptText, true, 128, 143);

            for (unsigned char i = 0; i < m_itemCount; ++i) {
                const std::wstring label = reader.ReadAnsiStringAsWide8();
                const unsigned short itemId = reader.ReadUInt16();
                m_itemIds[i] = itemId;
                AddTextButtonControl(RectBounds(86, 18 * i + 154, 255, 18 * i + 172), label.c_str());
            }

            ApplyBounds(RectBounds(bounds.left, bounds.top, bounds.left + 432, bounds.top + 18 * (m_itemCount + 19)), false);
            SetDefaultControlId(1);
            SetCancelControlId(1);
        } else {
            AddImageControl(RectBounds(0, 0, 314, 356), L"DLGMERC1.EPD", 0, L"NP");
            AddButtonControl(RectBounds(44, 306, 116, 322), kButtonCancel, 14);
            AddButtonControl(RectBounds(121, 306, 193, 322), kButtonOk, 16);
            AddButtonControl(RectBounds(198, 306, 270, 322), kButtonClose, 15);
            AddObjectImageControl(RectBounds(35, 37, 72, 92), objectImage);
            AddStaticTextControl(RectBounds(122, 37, 266, 133), promptText, true, 128, 143);

            for (unsigned char i = 0; i < m_itemCount; ++i) {
                const std::wstring label = reader.ReadAnsiStringAsWide8();
                const unsigned short itemId = reader.ReadUInt16();
                m_itemIds[i] = itemId;
                list->AddTextEntry(itemId, label.c_str());
            }

            AddListControl(RectBounds(36, 141, 278, 285), list);
            SetFocusedControlId(6);
            SetDefaultControlId(1);
            SetCancelControlId(3);
            ApplyBounds(bounds, false);
            InitDialogImage(L"DLGMERC1.EPD", 0);
        }
    }

    SetModal(true);
    ShowDialog(bounds, false, false, g_dialogLayer);
    SetOwnerFrame(g_mainWindowHandle);
}
```

### Child `0x00518e20-0x00519102.TextMenuDialogOnPaint`

Recommended header:

```text
*** COMPLETION:89 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:91 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000ES | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000OP | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
<insert the C++ block below>
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

Recommended formal `RECONSTRUCTION_CPP CODE` insertion:

```cpp
void TextMenuDialog::OnPaint()
{
    if (g_useHighResolutionTextMenuLayout)
        return;

    RectBounds top;
    RectBounds middle;
    RectBounds buttonTop;
    RectBounds buttonMiddle;
    RectBounds buttonBottom;
    RectBounds bottom;

    InitRectBounds(top);
    InitRectBounds(middle);
    InitRectBounds(buttonTop);
    InitRectBounds(buttonMiddle);
    InitRectBounds(buttonBottom);
    InitRectBounds(bottom);

    m_shouldFillBackground = false;
    SetTextColor(0);
    DrawCurrentPaneFrame(m_clientRect);
    SetTextColor(128);

    LoadEpdFrame(g_dialogTiles, L"MERTOP.EPD", 0, top);
    LoadEpdFrame(g_dialogTiles, L"MERMID.EPD", 0, middle);
    LoadEpdFrame(g_dialogTiles, L"MERBTOP.EPD", 0, buttonTop);
    LoadEpdFrame(g_dialogTiles, L"MERBUT.EPD", 0, buttonMiddle);
    LoadEpdFrame(g_dialogTiles, L"MERBBOT.EPD", 0, buttonBottom);
    LoadEpdFrame(g_dialogTiles, L"MERBOT.EPD", 0, bottom);

    const int npImage = FindImageResource(g_imageLibrary, L"NP");
    RectBounds dst(0, 0, 332, 100);
    DrawEpdFrame(top, dst, npImage);

    dst.Offset(0, 100);
    dst.SetVerticalFrom(middle.top, middle.bottom + 18);
    DrawEpdFrame(middle, dst, npImage);

    dst.Offset(0, 18);
    DrawEpdFrame(middle, dst, npImage);

    dst.SetVerticalFrom(buttonTop.top, buttonTop.bottom);
    DrawEpdFrame(buttonTop, dst, npImage);

    dst.SetVerticalFrom(buttonMiddle.top, buttonMiddle.bottom);
    for (unsigned char i = 0; i < m_itemCount; ++i) {
        dst.Offset(0, 18);
        DrawEpdFrame(buttonMiddle, dst, npImage);
    }

    dst.Offset(0, 18);
    dst.SetVerticalFrom(buttonBottom.top, buttonBottom.bottom);
    DrawEpdFrame(buttonBottom, dst, npImage);

    dst.Offset(0, 18);
    dst.SetVerticalFrom(bottom.top, bottom.bottom + 70);
    DrawEpdFrame(bottom, dst, npImage);
}
```

### Child `0x00519210-0x005194b1.TextMenuDialogOnDialogAction`

Recommended header:

```text
*** COMPLETION:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000ES | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000OP | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
<insert the C++ block below>
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

Recommended formal `RECONSTRUCTION_CPP CODE` insertion:

```cpp
void TextMenuDialog::OnDialogAction(int controlId, unsigned int actionId)
{
    if (m_itemCount <= 6 && !g_useHighResolutionTextMenuLayout) {
        if (actionId == 0) {
            SendMenuRequestPacket();
            return;
        }

        if (actionId == 1)
            return;

        if (actionId < 4)
            return;

        SendMenuReply(m_replyType, m_dialogId, m_itemIds[actionId - 4]);
        Close();
        return;
    }

    if (actionId == 1) {
        TextMenuItemList *list = static_cast<TextMenuItemList *>(GetControlById(6));
        if (list->GetSelectedIndex() < 0) {
            Close();
            return;
        }

        const TextMenuItemListEntry *entry = list->GetSelectedEntry();
        SendMenuReply(list->m_menuType, list->m_menuId, entry->itemId);
        Close();
        return;
    }

    if (actionId == 2) {
        SendMenuRequestPacket();
        return;
    }

    if (actionId == 3)
        Close();
}
```

### Child `0x005194c0-0x00519511.TextMenuDialogUpdateScrollButtons`

Recommended header:

```text
*** COMPLETION:91 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000ES | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000OP | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
<insert the C++ block below>
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

Recommended formal `RECONSTRUCTION_CPP CODE` insertion:

```cpp
void TextMenuDialog::UpdateScrollButtons()
{
    if (m_itemCount <= 6 && !g_useHighResolutionTextMenuLayout)
        return;

    ControlPane *okButton = GetControlById(1);
    TextMenuItemList *list = static_cast<TextMenuItemList *>(GetControlById(6));

    if (list->HasSelectedEntry())
        okButton->Activate();
    else
        okButton->Deactivate();
}
```

### Raw Helper Child Blank-C++ Insertion Text

The three raw serializer children should be created as exact no-route children with blank formal C++. They are reconstructable documentation targets because their behavior is known, but they are not source-emitting children until route evidence exists.

Recommended header for `0x00519110-0x0051920c.TextMenuDialogRawSelectionReplySerializer`:

```text
*** COMPLETION:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:91 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000ES | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

Recommended header for `0x005195f0-0x0051971d.TextMenuItemListRawSelectedRowReplySerializer`:

```text
*** COMPLETION:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:91 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000ET | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

Recommended header for `0x00519720-0x0051983a.TextMenuItemListRawExplicitIdReplySerializer`:

```text
*** COMPLETION:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:91 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000ET | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

### Required Support Declarations For The Child C++

These declarations are implementation-ready support recommendations for [UID:0000OP] / `by-class/TextMenuDialog.md`. They are limited to helpers already evidenced by the target's packet, layout, and dialog-control behavior.

```cpp
class TextMenuDialog : public MerchantDialogPane {
public:
    TextMenuDialog(bool hasExtraString,
                   const RectBounds& bounds,
                   const unsigned char *payload,
                   unsigned char merchantDialogType);

    void SendMenuRequestPacket();
    void OnPaint() override;
    void OnDialogAction(int controlId, unsigned int actionId) override;
    void UpdateScrollButtons();

private:
    void SendMenuReply(unsigned char replyType, unsigned int dialogId, unsigned short itemId);

    unsigned char m_dialogType;       // inherited +0x26c merchant-dialog subtype context
    unsigned int m_dialogId;          // +0x270
    unsigned char m_replyType;        // +0x274 / packet reply byte used by opcode 0x39
    unsigned char m_itemCount;        // +0x278
    bool m_hasExtraString;            // +0x279
    StringObject m_extraString;       // +0x27c, exact backing type remains support-owned
    unsigned short m_itemIds[128];    // +0x280 selected item ids; constructor uses observed bounded option count
};

class TextMenuPayloadReader {
public:
    explicit TextMenuPayloadReader(const unsigned char *payload);
    unsigned char ReadUInt8();
    unsigned short ReadUInt16();
    unsigned int ReadUInt32();
    ObjectImageDescriptor ReadObjectImage();
    std::wstring ReadAnsiStringAsWide();
    std::wstring ReadAnsiStringAsWide8();
    StringObject ReadStringObject();
};

void TextMenuDialog::SendMenuReply(unsigned char replyType, unsigned int dialogId, unsigned short itemId);
```

## Direct Xref / Caller Inventory

| Address / Item | Xref / Caller / Callee | Meaning |
| --- | --- | --- |
| `0x00517ec0` | 7 callers: `0x519362`, `0x51a2b1`, `0x51aced`, `0x51c34d`, `0x51d55d`, `0x51e51d`, `0x51f1ad` | Shared cancel/request helper reused by menu families. |
| `0x00517f30` | 4 constructor refs at `0x5174df`, `0x51752d`, `0x517809`, `0x517899` | `TextMenuDialog` factory/wrapper construction. |
| `0x00519110` | 0 xrefs | Raw text-menu selection reply helper, behavior strong but route absent. |
| `0x00519520` | 2 refs at `0x51814d`, `0x5186d4` | `TextMenuDialog` constructs private list in two layout branches. |
| `0x00519590` | 1 ref at `0x5189ed` | Standard large-list branch appends row. |
| `0x005195f0` / `0x00519720` | 0 xrefs each | Raw selected-row and explicit-id serializers, not ordinary emitted methods yet. |
| `0x00519840` | vtable data ref `0x61edc4` | Virtual forwarder for list selection state. |
| `0x005198e0` | 4 refs at `0x51757b`, `0x5175c9`, `0x517929`, `0x5179b9` | `TextInputMenuDialog` factory/wrapper construction. |
| `0x0051a280` / `0x0051a3e0` | vtable data refs `0x61ee54`, `0x61ee58` | Text-input virtual action/update methods. |
| `0x0051a420` | 0 xrefs | Adjacent retained raw helper; already handled by [UID:000239]. |

## Documentation Evidence And IDA Status

- Existing docs that support the conclusion: target page already maps the covered ranges; [UID:0000OP] records source placement; [UID:0000ET], [UID:0000ER], [UID:000238], [UID:000239], and [UID:00031Y] carry same-or-greater support detail for source children, fields, vtables, and compiler artifact exclusions.
- Existing docs that were stale, incomplete, or contradicted before callback: target's earlier low-score empty-emitter disposition needed replacement with session `60724697`, explicit split/container proof, and the exact child plan. The callback applied that repair and support docs were updated only where child cross-links/source-ready notes were needed.
- Generated/coverage report state: pre-callback generated command `000000006160` showed UID0001BN as an Empty Emitter Marker and listed UID0001BN at `86/88`. Post-callback validator command `000000006297` refreshed `TextMenuDialogs.cpp`; UID0001BN remains intentionally non-emitting while [UID:0004H8], [UID:0004H9], [UID:0004HA], [UID:0004HC], and [UID:0004HD] emit child bodies.

## Ranked Ownership Analysis

### 1. [UID:0000OP] TextMenuDialogs

- Evidence for: target header; source placement; factory constructor refs; text-menu vtable stores; class pages; generated source root; packet opcode family; exact child output.
- Evidence against: target is broad and contains un-emitted raw helpers/methods, but that argues against target C++ rather than against owner.
- Decision: selected; owner unchanged, but emitter disposition changes to non-emitting container after child split.

### 2. Individual classes [UID:0000ES], [UID:0000ET], [UID:0000ER]

- Evidence for: many subranges are class methods; [UID:0000ET] and [UID:0000ER] already carry formal class/source C++; [UID:000239] is class-owned by [UID:0000ER].
- Evidence against: no single class owns the full UID0001BN range. `TextMenuDialog`, `TextMenuItemList`, and `TextInputMenuDialog` are all present.
- Decision: use as support/direct child owners only; do not change UID0001BN owner away from file bucket.

### 3. Rejected feature or infrastructure owners

- Evidence for: the range calls PacketBuffer/string/pane/list helpers and is adjacent to item/spell/argumented menu families.
- Evidence against: callees do not own caller packet semantics; constructor/vtable routes are text-menu specific; item/spell/argumented families have separate source buckets; MerchantDialogPane is only the base class.
- Decision: rejected as target owners.

### Proposed new file/grouping, if applicable

- Proposed owner/name/path: no new source file recommended. Continue using [UID:0000OP] `NexusTK/ui/dialogs/TextMenuDialogs.cpp`.
- Likely full contents: current [UID:0000OP] contents already include factory helpers, `TextMenuDialog`, `TextMenuItemList`, `TextInputMenuDialog`, vtable declarations, and adjacent raw helper where routed.
- Candidate related items that belong: [UID:000238], [UID:0001BN], [UID:000239], [UID:00031Y], class pages [UID:0000ES]/[UID:0000ET]/[UID:0000ER].
- Candidate related items rejected: item-menu, spell-menu, argumented-menu concrete classes and vtables except as consumers/siblings.
- Standalone, narrow, or broad source-file inference: broad dialog-family source file, not a one-target source file and not a generic packet/edit-control module.

## Source Placement

- Recommended source file/class/global/module placement: `NexusTK/ui/dialogs/TextMenuDialogs.cpp` through [UID:0000OP].
- Why this placement fits source-tree and subsystem context: modal packet-driven merchant/NPC dialogs, factory helpers, text/list/text-input classes, and opcode `0x39`/`0x43` reply/request logic are all local to the UI dialogs source family.
- Rejected placements and why: `ui/menu` rejected because this is modal dialog behavior, not reusable popup controls; PacketBuffer/network rejected because they are callees; item/spell/argumented source buckets rejected because their constructors and vtables are separate consumers/siblings.
- Remaining placement uncertainty: only final physical folding with adjacent merchant/menu modules remains a project-wide source-tree choice; it does not block current owner/emitter metadata.

## Range / Split / Padding / Reclassification Analysis

- Exact range/boundary facts: UID0001BN is `0x00517ec0-0x0051a417` half-open. `0x0051a417-0x0051a420` is nine bytes of `0xcc` padding before adjacent raw helper [UID:000239] at `0x0051a420`.
- Children/subranges to create, repair, merge, leave ignored, or leave no-owner: create the exact child set in `Implementation-Ready Split / Child Plan`. This is required for score improvement because the target's source-bearing blockers are now resolved to exact child pages rather than deferred. No merge is recommended; no range is left no-owner.
- Padding/table/data/code distinctions: all sampled gaps are `0xcc` padding; raw serializer bodies start with prologues but are not IDA-modeled functions.
- Parent/container impact: convert UID0001BN to a higher-confidence non-emitting split/container. Existing source children remain attached to [UID:0000OP]; new source-emitting children should carry the `TextMenuDialog` method bodies; raw no-route serializer children should remain blank C++ with raw-helper/no-route evidence.

## Negative Evidence Summary

- No single function or class maps to the whole UID0001BN range.
- Raw serializers have behavior but no direct xrefs, pointer refs, or vtable refs at their starts.
- Generated UID0001BN is an Empty Emitter Marker while exact child/support C++ already exists.
- Vtable refs prove class ownership and compiler-declared layout but do not justify hand-authored vtable or thunk source.
- PacketBuffer/TextEditControlPane/g_packetSender are callee/support layers, not owners of dialog-specific opcode payloads.

## IDA Rename / Type / Comment Recommendations

- Proposed source-facing names/types/comments: no IDA DB edits requested. Target documentation should continue using accepted names `TextMenuDialog::SendMenuRequestPacket`, `TextMenuItemList::AddTextEntry`, `TextMenuItemList::ForwardOwnerSelectionState`, `TextMenuItemList::DrawListItem`, `TextInputMenuDialog::OnButtonPress`, `TextInputMenuDialog::UpdateSubmitButtonState`, and raw serializer names as descriptive no-route comments.
- Evidence for each proposed name/type/comment: class/formal blocks and current MCP decompilation/disassembly support the roles; original spelling is not proven for every helper.
- Items intentionally left blank and why: raw `0x00519110`, `0x005195f0`, and `0x00519720` get exact no-route child pages with blank C++; target formal C++ remains blank because UID0001BN is the split/container.
- Whether IDA DB edits are safe, unsafe, or not requested: not requested and not performed during either the report-only pass or the implementation callback.

## First-Draft C++ Recommendation

- Eligible for draft C++: not as UID0001BN aggregate. Narrow support pages already emit source where eligible, and this repair recommends new exact children for the remaining eligible source-bearing `TextMenuDialog` bodies.
- Recommended target code: keep the UID0001BN formal `RECONSTRUCTION_CPP CODE` block blank because UID0001BN becomes a non-emitting split/container.
- Third-party import directive: not applicable.
- Reason it preserves exact original behavior: blank aggregate C++ prevents duplicate emission and prevents invented call flow over raw/no-route serializer bodies. Existing exact child/support C++ preserves behavior where scoped evidence is strong, and the recommended new child pages give each remaining source-bearing body its own insertion point.
- Reason it matches the most plausible original precompiled mid-2000s developer source shape: a real source file would contain several classes and methods, but the documentation system's target-level formal block for this broad by-memory aggregate would not be a natural source unit. Class/helper pages are the correct source units.
- Inferred source-facing names/types/fields used instead of IDA/decompiler labels: use support-doc accepted names listed above; no new target-wide code names introduced.
- Naming/coding style convention used and evidence for consistency: Visual C++ era class methods, simple helper names, enum/control-id names, and source-file grouping already present in support docs.
- Reason target code should remain blank: UID0001BN spans multiple classes, raw helper islands, padding, and already-emitted child/support C++. A formal aggregate C++ block would duplicate [UID:0000ET], [UID:0000ER], [UID:000239], and [UID:000238] output and would force decompiler-shaped scaffolding for raw no-route helpers.
- Child first-draft C++ recommendation: source-emitting child pages were created for `SendMenuRequestPacket`, constructor, `OnPaint`, `OnDialogAction`, and `UpdateScrollButtons`, using the exact formal insertion text in `Formal Child Reconstruction C++ Insertion Text`. The target aggregate still stays blank.
- Raw-helper no-code proof: current MCP confirms no modeled functions and no direct xrefs for `0x00519110`, `0x005195f0`, and `0x00519720`. These are source-shaped packet serializers, but best inferred support declarations cannot safely introduce them as callable C++ methods until route evidence exists. Their correct implementation-ready disposition is exact raw-helper child pages with blank formal C++ and strong behavior evidence, not omission.

## Final Recommendation

- Exact changes applied in callback: UID0001BN was updated as a non-emitting split/container; target/support docs cite MCP session `60724697`, live 12-modeled-start inventory, raw helper/no-xref facts, boundary bytes, generated output state, rejected alternatives, and the exact child plan. Recommended exact children were created and assigned validator UIDs [UID:0004H8] through [UID:0004HF].
- Exact parent assignments recommended: keep [UID:0000OP] as source file owner. Child method pages should have semantic owner [UID:0000ES] or [UID:0000ET] as listed, and source emitter [UID:0000OP] for source-emitting children. Raw no-route children should have blank emitter until route evidence supports ordinary source emission.
- Exact items left no-owner/non-emitting and why: none left no-owner. Raw serializers become class/file-owned exact raw children with blank formal C++ because no xrefs/pointer routes were found.
- Exact future work outside this assignment scope: none required for Gate 1. Implementation callback can apply the target container metadata and create/update the exact child docs from the table. Deeper original-name polishing can happen later without blocking this disposition.

## Recommended Target Doc Changes

- Target path: `by-memory/0x00517ec0-0x0051a417.TextMenuDialogs.md`.
- Exact report facts to incorporate:
  - Current MCP session `60724697` health and evidence source.
  - `entity_query` returned 12 modeled functions in `0x00517ec0-0x0051a420`.
  - `lookup_funcs`/`get_bytes` boundary and raw-helper proof for `0x00517f26`, `0x00519110`, `0x005195f0`, `0x00519720`, `0x0051a417`, and `0x0051a420`.
  - Xref facts for request helper reuse, constructor callers, list constructor/add routes, vtable-only routes, and zero-xref raw serializers.
  - Generated `TextMenuDialogs.cpp` command `000000006160` output: [UID:0000ER], [UID:000239], [UID:0000ET], and [UID:000238] emit source; [UID:0001BN] remains an Empty Emitter Marker.
  - Rejected alternatives: target aggregate C++, generic packet/edit-control ownership, item/spell/argumented owner transfer, source-authored compiler/vtable artifacts.
- Metadata/score/owner/emitter/reconstructable/C++ changes: set UID0001BN to `COMPLETION:90`, `CONFIDENCE:92`, keep `CANONICAL_OWNER:0000OP`, keep `RECONSTRUCTABLE:TRUE`, make target `EMITTER_UIDS` blank for the non-emitting split/container, keep optional position blank, and keep formal C++ blank.
- Historical/stale assumptions, rejected alternatives, and negative evidence to preserve: older local MCP-session evidence should be labeled historical if mentioned; preserve raw no-route caveats and exact-child emission policy.

## Recommended Support Doc Changes

- `by-file/TextMenuDialogs.md`: update source-root inventory to record UID0001BN as a non-emitting split/container and add the exact child set. Existing factory/list/input/vtable support remains already-present.
- `by-class/TextMenuDialog.md`: update from blank class-level method map to source-ready child cross-links for `SendMenuRequestPacket`, constructor, `OnPaint`, `OnDialogAction`, and `UpdateScrollButtons`; add raw child cross-link for `TextMenuDialogRawSelectionReplySerializer` with no-route/blank-C++ policy.
- `by-class/TextMenuItemList.md`: already present at same-or-greater detail for ordinary methods and already emits source C++; add cross-links only for the two exact no-route raw serializer children if they are created.
- `by-class/TextInputMenuDialog.md`: already present at same-or-greater detail and already emits class declaration/support C++.
- `by-memory/0x00517450-0x00517d23.MenuDialogFactoryHelpers.md`: already emits formal first-draft C++; no edit required.
- `by-memory/0x0051a420-0x0051a51c.TextInputMenuDialogReplyPacketHelper.md`: already emits corrected `SendInputReply(const wchar_t *)`; no edit required.
- `by-type/by-vtable/TextMenuDialogVtables.md` and `MerchantMenuDialogVtableFamily.md`: already present at same-or-greater detail for vtable owner split and compiler-generated policy; no edit required.

## Score And Metadata Recommendation

- Historical before-callback score/metadata: `COMPLETION:86`, `CONFIDENCE:88`, owner/emitter [UID:0000OP], reconstructable true, blank formal C++.
- Current implemented score/metadata: `COMPLETION:90`, `CONFIDENCE:92`, owner [UID:0000OP], reconstructable true, blank target `EMITTER_UIDS`, blank optional position, blank formal target C++.
- Score rationale and reason not higher/lower: the target should improve because the previous score-limiting blockers are now resolved into an implementation-ready split/container plan with exact child ranges, owners, emitters, formal child C++ insertion text, and raw-helper no-code dispositions. It should not exceed low 90s because the constructor/paint/action blocks remain first-draft source-quality reconstructions with support-helper dependencies, and the raw serializers still lack route evidence.
- Score-improvement attempt:
  - Owner/emitter: checked target, file/class/vtable docs, generated output, xrefs; resolved as correct.
  - Source placement: checked file doc and generated path; resolved as correct.
  - Split/range/padding: checked current MCP starts/bytes/successor; exact split repair required and specified.
  - Raw helper route: checked function model and xrefs; still zero direct refs for raw starts, so exact raw no-route child pages with blank C++ are required.
  - Field/type/helper blockers: checked class/support docs; many are already resolved on support pages, but not enough to emit whole aggregate.
  - C++ readiness: considered target aggregate body and rejected with target-specific proof; child-page C++/no-code dispositions are supplied.
- Metadata fields to change or leave unchanged: change completion/confidence to `90/92`, blank UID0001BN `EMITTER_UIDS` for split/container status, keep owner `0000OP`, reconstructable true, blank optional position, and blank formal C++.

## Open Questions With Attempted Resolution

- Open question: should UID0001BN emit a source block now that the file root has source output?
  - Evidence checked: generated `TextMenuDialogs.cpp`, target range, exact support emissions, current MCP raw/no-route facts.
  - Resolution: no target-wide source block. UID0001BN should become a non-emitting split/container and exact children should emit or record no-code raw-helper dispositions.
- Open question: do raw serializers at `0x00519110`, `0x005195f0`, and `0x00519720` justify exact child pages now?
  - Evidence checked: `lookup_funcs`, `xrefs_to`, raw disassembly, class field usage.
  - Resolution: yes for exact child pages, no for ordinary source-emitting methods. Create raw no-route child pages with blank formal C++ and explicit packet semantics.
- Open question: can final original spellings for un-emitted `TextMenuDialog` helpers be proven from this pass?
  - Evidence checked: target/class docs, decompilation, callers/callees, generated output.
  - Resolution: descriptive names are defensible for docs, but exact original spelling remains unavailable. This caps confidence and supports blank aggregate C++.
- Remaining unresolved questions: none that block Gate 1 repair. Original spellings and route recovery remain confidence caps, but exact child pages can be created now using descriptive names and current MCP evidence.

## Exact Manual Supervisor-Owned Coverage Or Tracker Text

- Not applicable. No manual `-coverage-report.md` or supervisor-owned tracker edit is recommended. Validator-owned generated tracker/report files should refresh from source docs if supervisor later implements and executes this report.

## Follow-Up Actions

- Supervisor actions: perform Gate 2 verification and, if satisfied, run the supervisor-only report execution/lifecycle step. B009 stops at `READY_FOR_SUPERVISOR_EXECUTE`.
- A-agent actions: none.
- B009 future research actions: none required. The exact child plan has been applied; only supervisor verification/execution remains.

## Confidence

- Recommendation confidence: high.
- Score confidence: medium-high for repaired `90/92`.
- Remaining uncertainty: exact original names for remaining un-emitted `TextMenuDialog` methods and route status for raw serializers.

## Validator Results

- Child page validators:
  - `python .\tools\validator.py --mode file --file by-memory/0x00517ec0-0x00517f26.TextMenuDialogSendMenuRequestPacket.md --apply --queue-timeout 240`: command_id `000000006279`, timestamp `2026-07-04T12:23:31-04:00`, exit `0`, ok count not printed; UID [UID:0004H8] inserted, generated refresh deferred.
  - `python .\tools\validator.py --mode file --file by-memory/0x00517f30-0x00518e17.TextMenuDialogConstructor.md --apply --queue-timeout 240`: command_id `000000006280`, timestamp `2026-07-04T12:23:35-04:00`, exit `0`, ok count not printed; UID [UID:0004H9] inserted, generated refresh deferred.
  - `python .\tools\validator.py --mode file --file by-memory/0x00518e20-0x00519102.TextMenuDialogOnPaint.md --apply --queue-timeout 240`: command_id `000000006281`, timestamp `2026-07-04T12:23:37-04:00`, exit `0`, ok count not printed; UID [UID:0004HA] inserted, generated refresh deferred.
  - `python .\tools\validator.py --mode file --file by-memory/0x00519110-0x0051920c.TextMenuDialogRawSelectionReplySerializer.md --apply --queue-timeout 240`: command_id `000000006282`, timestamp `2026-07-04T12:23:39-04:00`, exit `0`, ok count not printed; UID [UID:0004HB] inserted, generated refresh deferred.
  - `python .\tools\validator.py --mode file --file by-memory/0x00519210-0x005194b1.TextMenuDialogOnDialogAction.md --apply --queue-timeout 240`: command_id `000000006283`, timestamp `2026-07-04T12:23:41-04:00`, exit `0`, ok count not printed; UID [UID:0004HC] inserted, generated refresh deferred.
  - `python .\tools\validator.py --mode file --file by-memory/0x005194c0-0x00519511.TextMenuDialogUpdateScrollButtons.md --apply --queue-timeout 240`: command_id `000000006285`, timestamp `2026-07-04T12:23:43-04:00`, exit `0`, ok count not printed; UID [UID:0004HD] inserted, generated refresh deferred.
  - `python .\tools\validator.py --mode file --file by-memory/0x005195f0-0x0051971d.TextMenuItemListRawSelectedRowReplySerializer.md --apply --queue-timeout 240`: command_id `000000006286`, timestamp `2026-07-04T12:23:45-04:00`, exit `0`, ok count not printed; UID [UID:0004HE] inserted, generated refresh deferred.
  - `python .\tools\validator.py --mode file --file by-memory/0x00519720-0x0051983a.TextMenuItemListRawExplicitIdReplySerializer.md --apply --queue-timeout 240`: command_id `000000006287`, timestamp `2026-07-04T12:23:47-04:00`, exit `0`, ok count not printed; UID [UID:0004HF] inserted, generated refresh deferred.
- Existing by-* doc validators:
  - `python .\tools\validator.py --mode file --file by-memory/0x00517ec0-0x0051a417.TextMenuDialogs.md --apply --queue-timeout 240`: command_id `000000006293`, timestamp `2026-07-04T12:27:56-04:00`, exit `0`, ok `1`; warnings were pre-existing missing UID references `0003KO`, `00037C`, `00037D`, and `0003YO`; generated refresh deferred.
  - `python .\tools\validator.py --mode file --file by-file/TextMenuDialogs.md --apply --queue-timeout 240`: command_id `000000006294`, timestamp `2026-07-04T12:27:58-04:00`, exit `0`, ok `1`; warnings were pre-existing missing UID references `0003IP`, `00037E`, `00037F`, `00037D`, and `00037C`; generated refresh deferred.
  - `python .\tools\validator.py --mode file --file by-class/TextMenuDialog.md --apply --queue-timeout 240`: command_id `000000006295`, timestamp `2026-07-04T12:28:00-04:00`, exit `0`, ok `1`; warnings were pre-existing missing UID references `00037E` and `00037F`; generated refresh deferred.
  - `python .\tools\validator.py --mode file --file by-class/TextMenuItemList.md --apply --queue-timeout 240`: command_id `000000006296`, timestamp `2026-07-04T12:28:02-04:00`, exit `0`, ok `1`; warnings were pre-existing missing UID reference `0003KO`; generated refresh deferred.
  - `python .\tools\validator.py --mode file --file by-file/TextMenuDialogs.md --apply --queue-timeout 240 --wait-generated`: command_id `000000006297`, timestamp `2026-07-04T12:29:29-04:00`, exit `0`, ok `1`; same pre-existing missing UID references as command `000000006294`; generated refresh completed.
- Generated freshness proof: `auto-generated/NexusTK/ui/dialogs/TextMenuDialogs.cpp` header records `validator-command-id: 000000006297`, `validator-refreshed-at: 2026-07-04T12:29:29-04:00`, and last write `2026-07-04 12:29:35`. It emits [UID:0004H8], [UID:0004H9], [UID:0004HA], [UID:0004HC], and [UID:0004HD]; raw serializer children [UID:0004HB], [UID:0004HE], and [UID:0004HF] remain blank/no-route as intended.

## Changed Files

- Repaired in place after callback: `tools/leaser/Agents/Agent-B009/research/0001BN-TextMenuDialogs-source-quality.md`.
- Modified target/support docs: `by-memory/0x00517ec0-0x0051a417.TextMenuDialogs.md`, `by-file/TextMenuDialogs.md`, `by-class/TextMenuDialog.md`, and `by-class/TextMenuItemList.md`.
- Created child docs: `by-memory/0x00517ec0-0x00517f26.TextMenuDialogSendMenuRequestPacket.md`, `by-memory/0x00517f30-0x00518e17.TextMenuDialogConstructor.md`, `by-memory/0x00518e20-0x00519102.TextMenuDialogOnPaint.md`, `by-memory/0x00519110-0x0051920c.TextMenuDialogRawSelectionReplySerializer.md`, `by-memory/0x00519210-0x005194b1.TextMenuDialogOnDialogAction.md`, `by-memory/0x005194c0-0x00519511.TextMenuDialogUpdateScrollButtons.md`, `by-memory/0x005195f0-0x0051971d.TextMenuItemListRawSelectedRowReplySerializer.md`, and `by-memory/0x00519720-0x0051983a.TextMenuItemListRawExplicitIdReplySerializer.md`.
- Generated/validator side effects: scoped validators refreshed generated metadata/research tracker/projected stats and generated `auto-generated/NexusTK/ui/dialogs/TextMenuDialogs.cpp`; B009 did not hand-edit generated files, coverage reports, validator state, archives, lifecycle files, supervisor ledgers, or generated C++.
- Report execution: not run. B009 did not run `execute_report`, dry-run/probe variants, lifecycle/archive/registry commands, or manual report moves.

## Implementation Tracking Checklist

Initial report-only pass:
- [x] Supervisor validation required before implementation. Gate 1 passed for SHA `7D78E3DDD6E80A6AE2D6070352DF216195CBED3D67025C1C113B5B08DDA4E7C0`.
- [x] Target/support docs to update were identified: target `by-memory/0x00517ec0-0x0051a417.TextMenuDialogs.md`, `by-file/TextMenuDialogs.md`, `by-class/TextMenuDialog.md`, exact child pages, and `by-class/TextMenuItemList.md` raw child cross-links.
- [x] Current target state and actual evidence checked recorded: MCP session `60724697`, target metadata, generated output state, function inventory, boundary bytes, xrefs/callees, raw helper no-route evidence, and no-code proof remain in this report and were incorporated into docs.
- [x] Claim And Incorporation Ledger updated with destination and verification state for every accepted claim: ledger rows C-0001BN-01 through C-0001BN-11 now record applied/already-present states.
- [x] Metadata/score changes applied: target set to `90/92`, owner `0000OP`, blank target `EMITTER_UIDS`, reconstructable true, blank optional position, blank formal C++.
- [x] Score-limiting blockers researched to resolution, implementation-ready recommendation, or exact no-improvement proof: owner/emitter, source placement, split/range/padding, raw helper routes, generated-name/compiler artifacts, support fields/types, caller/reachability, generated output, and C++ readiness were checked and resolved to split/container plus child pages.
- [x] Owner/emitter/reconstructable changes applied: UID0001BN canonical owner remains `0000OP`, target emitter is blank, reconstructable remains true; source-emitting children use emitter `0000OP`, raw no-route children use blank emitter.
- [x] Split/rename/new-child changes applied: exact child pages were created for `0x00517ec0-0x00517f26` [UID:0004H8], `0x00517f30-0x00518e17` [UID:0004H9], `0x00518e20-0x00519102` [UID:0004HA], `0x00519110-0x0051920c` [UID:0004HB], `0x00519210-0x005194b1` [UID:0004HC], `0x005194c0-0x00519511` [UID:0004HD], `0x005195f0-0x0051971d` [UID:0004HE], and `0x00519720-0x0051983a` [UID:0004HF].
- [x] Source-placement, range/split/padding/reclassification, or IDA rename/type/comment changes applied or confirmed not applicable: target evidence refreshed; no IDA DB edit requested or performed.
- [x] First-draft C++ or no-code proof applied: target formal C++ remains blank; source-emitting child pages contain the exact formal child C++ blocks; raw serializer child pages contain blank formal C++ and no-route proof.
- [x] Third-party import directive confirmed not applicable.
- [x] Exact target/support doc facts incorporated at report-level detail: current MCP session, 12 modeled starts, boundary bytes, constructor/list/action xrefs, raw zero-xref serializers, generated exact-child output, and rejected alternatives were applied.
- [x] Historical/stale assumptions, rejected alternatives, and negative evidence preserved: raw no-route and aggregate blank-C++ policy are preserved; older output-state facts are historical or superseded by `000000006297`.
- [x] Wave2/Wave3 mentions or artifacts encountered and ignored/rejected as stale: generated output/tracker used only as lead/current-state; no stale Wave2/Wave3 source accepted as authority.
- [x] Open questions closed or documented as evidence-backed unresolved: exact child pages resolve the target blocker; original-name polish and raw serializer route recovery remain confidence caps.
- [x] Validators run: child validators `000000006279`-`000000006287`, target/support validators `000000006293`-`000000006296`, and generated wait validator `000000006297`.
- [x] Generated report refresh expected or explicit manual supervisor-owned coverage/tracker text supplied/confirmed unchanged: no manual tracker text; validator-owned generated refresh completed under command `000000006297`.

Implementation callback pass:
- [x] Report accepted by supervisor for implementation at SHA `7D78E3DDD6E80A6AE2D6070352DF216195CBED3D67025C1C113B5B08DDA4E7C0`.
- [x] All accepted target/support doc details incorporated at report-level detail.
- [x] Claim And Incorporation Ledger updated with destination and verification state for every accepted claim.
- [x] Metadata/score/owner/emitter/split/rename/C++ changes applied or explicitly marked already-present/not applicable.
- [x] Historical/stale assumptions, rejected alternatives, and negative evidence preserved.
- [x] Open questions resolved or documented with evidence-backed unresolved rationale.
- [x] Validators run and results recorded in `Validator Results`.
- [x] Generated report refresh completed by validator command `000000006297`; generated `TextMenuDialogs.cpp` is fresh and emits the expected child bodies.
- [x] Remaining unapplied accepted items listed with exact blocker: none.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B009","command_id":"000000006304","destination_path":"executed-b-agent-research/B009/0001BN-TextMenuDialogs-source-quality.md","details":"report executed into central archive","event":"executed","source_path":"tools/leaser/Agents/Agent-B009/research/0001BN-TextMenuDialogs-source-quality.md","timestamp":"2026-07-04T12:38:09-04:00","uid":"0001BN"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
