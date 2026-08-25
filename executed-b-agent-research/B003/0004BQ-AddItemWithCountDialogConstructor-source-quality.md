** TARGET-REPORT-UID:0004BQ **
** AUTHOR-AGENT-ID:B003 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.6 | xHigh **
# 0004BQ AddItemWithCountDialogConstructor Ownership / Split Research


## Finalized Report / Current Recommendation

- Implemented recommendation: the shallow constructor draft is replaced by the complete source-facing `AddItemWithCountDialog::AddItemWithCountDialog(unsigned int exchangeSessionId, char inventorySlot)` body, direct owner/emitter [UID:000008] `AddItemWithCountDialog` is retained, and the source route is [UID:0000KE] `NexusTK/ui/dialogs/ItemDialogs.cpp` at emitter position `10`.
- Implemented disposition: the exact `[0x004af040,0x004af371)` body remains one source-authored constructor. It directly constructs `DialogPane(L"", 9, 1)`, not `AddItemDialog`; builds five exact controls; formats localized string id `158` with the selected local-inventory record's `displayName`; stores exchange-session and signed inventory-slot state after control setup; creates, shows, and vertically slides the dialog. No split or reclassification was applied.
- Callback result: C01-C20 and B003-owned formal blocks R1/R2/R3/R5/R6 are incorporated at destination level. B002-owned UID0004BS was re-read only and its `92/94`, position-30 managed block equals R4 byte-for-byte. B005-owned control destinations were not edited. Sixteen changed ordinary by-* pages passed scoped validation and waited command `000000009954` refreshed and verified the generated ItemDialogs and ExchangeDialog sources; a later external validator refresh advanced both headers to command `000000009979` at `2026-07-13T13:25:20-04:00` without changing the verified structure or method counts.
- Confidence: `94/100` for target behavior, range, ABI, layout, ownership, and source form. Original lexical spellings and access control are inferred from behavior and project conventions rather than recovered symbols, so the recommendation remains below `95`.

## Supporting Research

The assigned target was created by executed B007 report `executed-b-agent-research/B007/0000KE-ItemDialogs-empty-emitter-family-source-quality.md`. That report correctly split the physical cluster and assigned UID0004BQ, but its constructor draft was intentionally shallow: it used the wrong `AddItemDialog` base, guessed an unsigned item/type parameter, invented `CreateCountInputControls`, and invented a constructor-time `UpdateActionButton` call. This report treats those lines as historical hypotheses, not evidence.

The mandatory historical search used these exact terms: `UID0004BQ`, `UID:0004BQ`, `0004BQ`, `0x004af040`, `AddItemWithCountDialogConstructor`, `sub_4AF040`, `AddItemWithCountDialog`, `ExchangeDialog`, `DLGEXC3`, and `AddItemWithCountDialogVtables`.

The exact roots and outcomes were:

| Root | Outcome |
| --- | --- |
| `executed-b-agent-research/**` | One `0004BQ` match, nine exact-address matches, one exact constructor-name match, two raw-name matches, fifteen `AddItemWithCountDialog` matches, fifty broad `ExchangeDialog` matches, eight `DLGEXC3` matches, and three exact vtable-page-name matches. The broad count increased from 49 to 50 when supervisor command `000000009874` moved B001 UID0004BN into this root at `2026-07-13T12:30:41-04:00`; direct and incidental results are classified below. |
| `archived/**` | No match for the exact UID, range, constructor name, raw name, class name, or exact vtable-page name. |
| `tools/leaser/Agents/Older-Research/**` | No match for the exact UID, range, constructor name, raw name, class name, or exact vtable-page name. |
| `tools/leaser/Agents/SpecialReports/**` | No match for the exact UID, range, constructor name, raw name, class name, or exact vtable-page name. |
| `tools/leaser/Agents/Agent-B001/research/**` through `Agent-B005/research/**` | Re-run after the B001 lifecycle transition: the former active B001 UID0004BN path no longer exists and the remaining B001 research root has no exact-term match. At callback evidence time, B002 `0004BS-AddItemWithCountDialogUpdateActionButton-source-quality.md` was the dedicated UID0004BS report and owned that updater target; it treated this B003 constructor/class/action work as exclusive support. B005 `0004BP-AddItemDialogUpdateActionButton-source-quality.md` owned sibling/control support and independently proved DialogPane `GetChild<T>`, ImageButton `Enable`/`Disable`, synchronous `OnCreate` refresh, and AddItemWithCount's separate updater override. No report in those searched roots duplicated UID0004BQ itself. |

All fifteen executed `AddItemWithCountDialog` matches were opened or target-classified:

| Executed report | Classification and target-specific use |
| --- | --- |
| `B007/0000KE-ItemDialogs-empty-emitter-family-source-quality.md` | Direct historical origin of UID0004BQ/0004BR/0004BS. Its split is retained; its shallow target C++ and item/type naming are superseded. |
| `B011/00033T-AddItemWithCountDialogSubmitPacketHelper-source-quality.md` | Direct retained-helper support. Its no-route/raw-body/inline-duplicate and eight-sent-byte conclusions remain valid; `selected item/type` is narrowed to `inventory slot`. |
| `B015/00014L-ExchangeDialogPacketDispatcher-source-quality.md` | Direct live caller support. Subcommand `1` allocates `0x274` and calls the target; the old `selectedItemType` label is superseded by signed `inventorySlot`. |
| `B003/00014M-ExchangeDialogAddItemWithCountHelper-source-quality.md` | Direct retained caller support. The exact helper body and no-route result remain valid; its packet byte is a local inventory-slot index, not an item type. |
| `B006/0003U9-LivingObjectPaneGetInventorySlotAddress-source-quality.md` | Direct type and field support. It proves signed `char`, `0x1fc` record stride, and `displayName` at record `+0x06`. |
| `B001/00014T-ItemExchangeMixDialogs.md` | Direct aggregate/source-boundary support. Exchange constructs the class but does not own ItemDialogs implementation. |
| `B001/00025A-ExchangeItemReadOnlyData-B001-00025A.md` | Direct three-vtable cluster and ItemDialogs ownership support. |
| `B002/00025A-ExchangeItemReadOnlyData-post-migration.md` | Direct current vtable child and `%hu` format child routing support. |
| `B003/00049Q-ExchangeDialogOnButtonAction-source-quality.md` | Negative caller boundary. UID00049Q does not construct this dialog; only dispatcher and retained helper call the target. |
| `B003/00033R-AddItemDialogSubmitPacketHelper-source-quality.md` | Sibling packet/helper policy support for opcode `0x4A/1` versus this class's `0x4A/2`. |
| `B001/0004BM-AddItemDialogConstructor-source-quality.md` | Strong sibling-constructor and ItemDialogs source-style support. It does not prove inheritance; target MCP proves the classes are direct `DialogPane` siblings. |
| `B009/00033V-MixItemDialogSubmitPacketHelper-source-quality.md` | Sibling retained-helper policy only; no target ownership or body fact. |
| `B012/00014R-ExchangeItemListPaneRawUpsertHelper-source-quality.md` | Exchange list-pane ownership boundary only; no target body fact. |
| `B002/00014O-exchange-dialog-cancel-alert-source-quality.md` | Exchange alert boundary only; no target body fact. |
| `B002/00014P-exchange-dialog-ready-alert-source-quality.md` | Exchange alert boundary only; no target body fact. |

The fifty broad `ExchangeDialog` report matches were also classified so that incidental mentions are not promoted to target evidence:

| Match group | Reports | Classification |
| --- | --- | --- |
| Direct caller/session/source boundary | `B015/00014L`, `B003/00014M`, `B005/00049P`, `B001/00014K`, `B011/0000J9`, `B001/00014T`, `B007/0000KE`, `B001/00025A`, `B002/00025A-post-migration`, `B003/00049Q`, `B001/0004BM`, `B005/0000KC` | Used for live-versus-retained caller status, primary/secondary exchange-session field reconciliation, object allocation size, ItemDialogs-versus-ExchangeDialog source ownership, and negative construction routes. |
| Exchange-specific controls, list, money, key, focus, ready, cancel, or alert behavior | `B009/0004CF`, `B015/00004S`, `B006/00049V`, `B004/0004A0`, `B009/00014Q`, `B002/00049Y`, `B002/00049R`, `B001/00014V`, `B006/00014N`, `B013/00049U`, `B004/00014S`, `B001/00049T`, `B002/00014O`, `B002/00014P`, `B012/00014R`, `B012/00049S`, `B012/00049W`, `B003/00049Z` | Support only for the ExchangeDialog source boundary, historical control-state conventions, or session-field naming. Stronger callback-time B002/B005 evidence resolves the target-facing calls as distinct `Enable`/`Disable`; these reports do not own target code. |
| Item/mix or shared-control siblings | `B012/00014W`, `B003/00033R`, `B011/00033T`, `B003/00011H`, `B001/0003LQ`, `B001/0003LQ-second-pass`, `B003/0003LQ-post-migration-recheck`, `B003/0003LQ-current-goal2-pass` | Used only where they prove retained-helper policy, text-edit emptiness behavior, or generic control APIs. |
| Incidental or unrelated term matches | `B001/0000XZ`, `B001/0000X6`, `B005/000259`, `B006/0000K1`, `B005/00014D`, `B001/000342`, `B002/0002SW`, `B002/00000B`, `B002/0001ZG`, `B003/00016Z`, `B003/00014Z`, `B001/0004BN` | Rejected as target evidence after classification; the word `ExchangeDialog` is contextual or incidental. B001 UID0004BN is now executed sibling-destructor work at `executed-b-agent-research/B001/0004BN-AddItemDialogDestructor-source-quality.md`; it changes no UID0004BQ range/body/owner fact and requires no B003 action. |

The eight executed `DLGEXC3` matches were checked as resource/control support. B004 `0002HH` and B002 `0001CV-0001CX-0001CY-0001D0` provide sibling quantity-dialog control conventions; B007 `000256` and `0003V6`, B014 `0001OE`, B004 `0002MG`, and B008 `0000J0` establish the shared resource literal and boundary; B012 `0000X5` is a documented byte-pattern false positive and is rejected. None changes target ownership.

The B002 UID0004BS and B005 UID0004BP reports were opened and classified after the broad family search and re-read at callback time. B002 was authoritative for UID0004BS and supplied the exact updater block reproduced as coordination block R4; B003 kept that by-memory page verify-only. Its callback-time page is `92/94`, position `30`, and its 549-character normalized managed block equals R4 exactly. B005's target was the sibling AddItemDialog updater at `0x004aea40`, so its target body and B005-owned support edits were not duplicated. Together those independently modeled the control-manager instruction patterns, accepted DialogPane typed-child API, ControlPane/ImageButton enable/disable slots, and `DialogPane::OnCreate -> 0x0049fe20 -> virtual +0x4c` route. Live B003 MCP confirmed UID0004BS has the matching selector-1/selector-4/two-tail shape and that UID0004BQ's `OnCreate` callee reaches `0x0049fe20` at `0x0049e119`.

## Target

- Target UID: `0004BQ`.
- Target path: `by-memory/0x004af040-0x004af371.AddItemWithCountDialogConstructor.md`.
- Source queue/report row: validator-refreshed `auto-generated/-ag-research-tracker.md`, `## by-memory` -> `### Not-Covered Files - Reconstructable`, score `86/90`, report count `0` at assignment.
- Historical assignment classification: report-only source-quality research requiring mandatory live IDA MCP and a complete implementation-ready source form; exact report SHA `2C8EE75748470595074F839A761AF4FE20EF436192C1D56861FC4C7AB044048C` passed supervisor Gate 1 before this callback.
- Implemented scores and parent state: target `92/94`, owner/emitter UID000008, reconstructable true, optional position `10`, `Nested:0`; class UID000008 `91/93`; aggregate UID00033S `91/93`; by-file UID0000KE remains `91/90`.

## Current Target State

- Historical pre-callback metadata: `COMPLETION:86`, `CONFIDENCE:90`, `CANONICAL_OWNER:000008`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:000008`, blank `EMITTER_POSITION_OPTIONAL`, and `Nested:0`.
- Existing owner/emitter/reconstructable state: owner and emitter are correct. The target is source-authored and reconstructable through `AddItemWithCountDialog` in ItemDialogs.
- Historical pre-callback C++/emitter state: nonempty but false. It derived from `AddItemDialog`, initialized guessed fields in an initializer list, called nonexistent `CreateCountInputControls`, and called `UpdateActionButton`; none matched the target instruction sequence.
- Resolved blockers and contradictions: the wrong base class, unsigned item/type parameter, field name, omitted five-control construction, localization/resource lookup, display-name formatting, lifecycle calls, member-store timing, invented constructor helpers, false action signature/helpers/initialization/close flow, false packet-handler signature/null test, false updater boolean setter, incomplete indirect-update timing, and missing EH/range/padding proof are now corrected in the B003-owned destinations. The rejected forms remain documented as history and negative evidence.
- Related docs checked: UID00033S, UID000008, UID0000KE, UID0004BR, UID0004BS, UID000318, UID00033T, UID00014L, UID00014M, UID0003IE, UID0001XV, UID0003U9, AddItemDialog constructor/class, ExchangeDialog class/file/aggregate, ItemExchangeMixDialogs, LanguageMan string resource support, DialogPane/EventHandler/TextEdit/control contracts, B002 UID0004BS, B005 UID0004BP, executed B001 UID0004BN, and generated `auto-generated/NexusTK/ui/dialogs/ItemDialogs.cpp` and `ExchangeDialog.cpp`.
- Implemented artifact state: B003 changed only the sixteen ordinary by-* destinations listed under Changed Files plus this same research/implementation-callback artifact. Validator-supported UID-preserving renames established the current UID0004BR and UID000318 paths. B003 did not edit UID0004BS, B005-owned control pages, generated output, audit/supervisor/validator state, coverage/tracker files, or B001 history. B003 performed no report execute/lifecycle/move/archive command; report validation/execution/count/path/archive state is external and is neither asserted nor directed here.

## Executive Recommendation

Direct class owner/emitter UID000008 and file owner UID0000KE are retained. The target is `92/94` at position `10`, remains reconstructable with `Nested:0`, and carries R1 exactly.

UID000008 is a source-emitting direct `DialogPane` subclass at `91/93` with the exact `0x274` layout and managed class block R2. The direct base call and complete control behavior reject `AddItemDialog` inheritance even though both classes occupy the same source family.

Aggregate UID00033S is `91/93`; UID0004BR was validator-preservingly renamed to `AddItemWithCountDialogOnControlCommand`, is `92/94` at position `20`, and carries R3. B002-owned UID0004BS was not edited by B003; its independently implemented `92/94`, position-30 body equals R4 exactly. UID000318 was validator-preservingly renamed to `AddItemWithCountDialogHandlePacketEvent`, is `92/94` at position `40`, and carries R5. UID00033T remains `86/90`, reconstructable true, owner/emitter UID000008, blank formal C++, and no-route retained-helper status.

Signed inventory-slot meaning and exact method contracts are synchronized through every B003-owned contradictory support page. Scores and routes for UID00014L, UID00014M, ExchangeDialog class/file/aggregate, ItemExchangeMixDialogs, accessor support, quantity format, EventHandler/DialogPane/TextEdit/control dependencies, resource support, and both vtable pages remain as accepted except for the explicitly listed target/class/aggregate/child score changes. Both vtable pages now follow the UID000318 renamed path and exact `HandlePacketEvent` slot wording while retaining blank formal C++.

## Supervisor Active Recheck

- The supervisor assigned new report-only UID0004BQ research after UID00036Y was executed and archived.
- During this report pass, supervisor command `000000009874` executed B001 UID0004BN and moved it to `executed-b-agent-research/B001/0004BN-AddItemDialogDestructor-source-quality.md`; the former active B001 path is absent. That sibling lifecycle change was re-searched and does not alter UID0004BQ.
- At callback evidence time B002 owned dedicated updater UID0004BS and B005 owned sibling/control UID0004BP support. This implementation consumed their compatible contracts without editing or claiming either target page; the current UID0004BS managed block equals R4 exactly.
- The target required source-quality repair, not a new physical split. The B007 split into UID0004BQ/0004BR/0004BS remains correct.
- Every source-bearing item triggered by the constructor has a complete formal destination/coordination block or an exact preserved no-code/unchanged disposition. No child was created; UID0004BR and UID000318 completed validator-preserving source-name renames, while B002-owned UID0004BS remains at its existing path.

## Inference Research Guidance Check

- The project inference rules required treating existing names and generated C++ as hypotheses. That directly exposed `AddItemDialog`, `selectedItemType`, `CreateCountInputControls`, `HasValidCountInput`, and constructor-time `UpdateActionButton` as stale abstractions.
- Direct IDA facts are exact addresses, bytes, calls, stores, stack cleanup, resource ids, vtable values, control arguments, xrefs, and padding. Documentation evidence supplies accepted project names for controls/globals and source routes. Inference supplies stripped lexical spellings such as `exchangeSessionId`, `inventorySlot`, `m_inventorySlot`, local variable names, and access specifiers.
- Binary behavior takes priority over nearby class similarity. `AddItemDialog` is a source sibling, not the base, because the target directly invokes `DialogPane` and builds a different complete control tree.
- Wave2/Wave3-era artifacts encountered in old reports were ignored as stale. No current conclusion depends on those systems.

## Heuristic / Inference Reanalysis And Validation

| Issue | Resolution | Evidence and classification |
| --- | --- | --- |
| Constructor signature | `AddItemWithCountDialog(unsigned int exchangeSessionId, char inventorySlot)` | `retn 8` and caller stack shape prove two four-byte ABI slots. The target loads the second low byte; both callers use narrow-char conversion; UID0003U9 sign-extends its `char` slot argument. Types are behavior-backed source inference. |
| Base class | Direct `DialogPane`, not `AddItemDialog` | Call `0x004af08d -> 0x0049d8a0` passes `L"", 9, 1`. There is no call to `0x004ae4c0`, and the target builds a complete independent DLGEXC3 control tree. Direct IDA fact. |
| First parameter | Exchange/session id | Both callers pass ExchangeDialog primary `+0x26c` or secondary-view `+0x1cc`; target stores it at `+0x26c`; action/helper serialize it big-endian. Behavior-backed descriptive name. |
| Second parameter | Signed local inventory slot | Target immediately calls `g_pUserPane->GetInventorySlotAddress(inventorySlot)` and uses record `displayName`; UID0003U9 proves signed `char` indexing and a `0x1fc` slot-record stride. `item type`, item id, style, count, and object id are rejected. |
| Derived fields | `m_exchangeSessionId` at `+0x26c`, `m_inventorySlot` at `+0x270` | Constructor stores, action/helper reads, caller values, and packet serialization agree. Names are descriptive, not symbol proof. |
| Class layout | DialogPane base `0x26c`; dword `+0x26c`; char `+0x270`; natural tail `+0x271..+0x273`; total `0x274` | Both callers allocate `0x274`; accepted DialogPane layout ends at `+0x26c`. No explicit padding field belongs in source. |
| Vptr sequence | Primary `0x00619fec` at `+0`, secondary `0x0061a04c` at `+0xa0`, tertiary `0x0061a07c` at `+0xa4` | Exact stores at `0x004af0ae`, `0x004af0b4`, and `0x004af0be`; compiler-generated and excluded from source. |
| Control APIs | Direct `InitRectBounds`, `AddControl(new ...)`, resource, selector, lifecycle, and inherited `GetChild<T>` calls | Exact call/argument sequence plus accepted DialogPane, TextEditControlPane, sibling ItemDialogs, and Clan/Employee dialog source conventions. Free selector helpers and `CreateCountInputControls` are rejected. |
| Prompt source | `g_pLanguageMan->GetLocalizedString(158)` formatted with `LocalInventorySlotRecord::displayName` | Immediate `0x9e`, call to `0x004f0350`, call to UID0003U9, `+6` pointer adjustment, secure wide formatter `0x0041b9b0`, and current STR.RES id 158 text. The English text remains resource-owned and is not hard-coded. |
| Prompt buffer | `wchar_t promptText[256]` | Stack reserves the exact wide buffer and passes count `256` to `swprintf_s`. Source local name inferred. |
| Update timing | No direct constructor call; `OnCreate` synchronously invokes the generic refresh wrapper and virtual updater | No target call to `0x004af480`. Target calls `DialogPane::OnCreate` at `0x004af337`; live `xrefs_to 0x0049fe20` and `decompile 0x0049dfd0` show `OnCreate` calls the generic refresh at `0x0049e119`, which dispatches primary slot `+0x4c`. AddItemWithCount's slot `0x0061a038` points to UID0004BS, so initial empty input disables the action button before show. |
| Updater predicate and control state | If selector-4 TextEdit is empty, selector-1 ImageButton `Disable()`; otherwise `Enable()` | `0x004af480` has 22 instructions/three blocks, gets selectors 1 and 4, calls `TextEditControlPane::IsEmpty` at `0x00498c60`, and tail-jumps to distinct slots `+0x50`/`+0x4c`. DialogPane `GetChild<T>` and B005's independent base/ImageButton slot audit resolve the APIs. `SetEnabled(bool)` and `HasValidCountInput` are rejected. |
| Primary command signature | `void OnControlCommand(int controlIndex, int notifyCode)` | UID0004BR ends in `retn 8`, returns no value, consumes the first stack argument as selector/control index, and ignores the second. Current DialogPane declares primary slot `+0x48` with this exact two-argument contract. Historical `int OnAction(unsigned int)` is rejected. |
| Command text/parse helpers | `GetChild<TextEditControlPane>(4)`, `ReadText(countText, 4)`, then `swscanf(countText, L"%hu", &parsedCount)` | Live UID0004BR disassembly calls UID0002OA `ReadText` and the CRT wide-scanf wrapper `0x004944f0`; stack storage is `wchar_t[16]`, read capacity is 4, and no pre-parse initialization store exists. Invented `GetCountInputText` and `ParseUnsignedShort` are rejected. |
| Command packet/close source shape | Uninitialized 9-byte local packet, exact writes 0..7, explicit scratch byte 8 zero, eight-byte send, then `SlideClose()` and `CloseDialog()` | UID0004BR's 85 instructions/five blocks prove `%hu` clamp at `>= 0xff`, signed slot low-byte serialization, count low byte, unsent zero, and both close calls for controls 1/2. Zero-initialized packet syntax, missing slide-close, and `return 0` are rejected. |
| Secondary packet signature | `bool HandlePacketEvent(Event *event)` | UID000318 is the secondary EventHandler `+0x10` slot, loads `event->packet` from `+0x0c`, tests `0x42/0x04`, adjusts `this-0xa0` only as compiler MI lowering, and always returns false. Historical `int OnClosePacket(const unsigned char *)`, raw adjustment, and null test are rejected. |
| Singleton/registration | No class singleton publication; normal dialog lifecycle only | No target write to item-dialog singleton globals. `OnCreate`, `OnShow`, and `SlideOpenVertical` perform framework attachment/display. |
| Member-store timing | Body assignments after all five controls/selectors and before final `OnCreate` | Exact stores at `0x004af307` and `0x004af316`. Initializer-list field assignment is rejected because it changes observable construction/failure order. |
| EH/source form | Ordinary base construction and five `new` expressions | Five allocation cleanup funclets and one base-cleanup state are compiler lowering. Explicit catches/deletes/vptr/cookie code is rejected. |
| Duplicate/inline body | No duplicate target body | Exact 33-byte prefix search returns only `0x004af040`; unique function signature is `55 8B EC 6A FF 68 5A E5 5F 00`. The dispatcher and retained helper duplicate only the caller-side allocation/call expression. |
| Source placement | `NexusTK/ui/dialogs/ItemDialogs.cpp` | Physical neighborhood, vtable route, current by-file ownership, sibling AddItemDialog/MixItemDialog, and generated route agree. ExchangeDialog is a caller, not implementation owner. |
| Access control | Public constructor/virtual callbacks; private fields in first draft | Constructor is externally instantiated; virtual callbacks are framework-facing. Exact original `public/protected/private` spelling is stripped, so this remains inferred and caps score. |

Rejected alternatives are: AddItemDialog inheritance, unsigned item/type semantics, direct item-id lookup, hard-coded English prompt, explicit vptr stores, explicit EH cleanup, explicit padding member, singleton publication, direct constructor-time updater call, later-only updater timing, vague control-builder/free-selector helpers, `GetCountInputText`, `ParseUnsignedShort`, zero-initialized action packet, `OnAction(unsigned int)`, `OnClosePacket(const unsigned char *)`, packet-event null test, `SetEnabled(bool)`, numeric validation in the updater, ExchangeDialog ownership, NumberInputDialog ownership, a target split, aggregate-only/no-code treatment, and a retained-helper body emitted in addition to the live inline command send.

## Evidence Standards Used

- Mandatory live IDA MCP: `idb_list`, `server_health`, bounded `lookup_funcs`, `get_bytes`, `disasm`, `decompile`, `analyze_function`, `analyze_component`, `basic_blocks`, `xrefs_to`, `find_bytes`, and signature creation, including fresh action/updater/packet-handler method and `OnCreate` refresh-route checks.
- Exact binary evidence: complete 817-byte target read and SHA256, physical instruction count, external EH chunks, basic blocks, caller xrefs, vtable stores, resource/global/helper xrefs, allocation sizes, stack cleanup, and boundary bytes.
- Current documentation: target/class/file/aggregate pages, exact action/update/close/helper children, caller pages, vtable pages, current DialogPane `OnControlCommand`/`GetChild<T>` contracts, EventHandler packet-family contract, TextEdit `ReadText`/`IsEmpty`, ControlPane/ImageButton state evidence, LivingObjectPane inventory accessor, STR.RES resource page, callback-time B002 UID0004BS and B005 UID0004BP evidence, executed B001 UID0004BN, and generated ItemDialogs.cpp.
- Historical evidence: every exact-target/class match and all broad ExchangeDialog matches were classified rather than assumed relevant.
- Evidence ladder: direct bytes and calls control behavior/range/type decisions; coherent cross-method data flow controls field semantics; current docs control project-stable source names/routes only where binary evidence does not contradict them; inference is explicitly capped below symbol proof.

## Evidence Checked

- IDA MCP/manual/raw checks: database `supervisor_nexustk_20260713`; healthy transport session `80c85738-6bac-4bd0-b1d2-df24ee466275`; target lookup, all target bytes, first/last instructions, total/physical instruction counts, target hash, exact prefix uniqueness, target xrefs, both caller bodies, component functions, updater assembly, secure formatter body, inventory accessor, resource/global xrefs, and vtable relationships.
- by-* and generated checks: all target/support pages named in the assignment; every page containing `selected item/type`, `selectedItemType`, or `m_selectedItemType`; `auto-generated/NexusTK/ui/dialogs/ItemDialogs.cpp` command header `000000009852` at evidence time; STR.RES resource support; AddItemDialog sibling constructor; Clan and Employee quantity-dialog control conventions.
- Historical/current searches: exact terms and roots listed under Supporting Research, including executed, archived, Older-Research, SpecialReports, and B001-B005 research roots. The search was repeated after B001 command `000000009874`: the former B001 research path is absent, its executed report contributes only the fiftieth incidental `ExchangeDialog` match, and callback-time B002 UID0004BS is classified as direct updater support/exclusive target ownership rather than a duplicate UID0004BQ report.
- Negative checks: no call to AddItemDialog constructor, no direct target call to updater, no singleton write, no internal split/function start, no duplicate target prefix, no second normal return, no target-owned destructor code, no hard-coded English prompt, no item-id lookup, no current static route to retained helper UID00033T, no action return value, no action pre-parse/count/packet zero initialization, no updater boolean setter, no packet-handler null test, and no source-authored raw secondary-this adjustment.
- Failed/unavailable/intentionally skipped: no valid MCP call failed after the corrected JSON argument shape. IDA mutation, local process management, by-* edits, leases, validators, lifecycle commands, and generated-file edits were intentionally prohibited and not attempted.

## Claim And Incorporation Ledger

| Claim ID | Claim | Confidence | Evidence | Destination doc/section | Action | Verification state | Implementation proof |
| --- | --- | --- | --- | --- | --- | --- | --- |
| C01 | Mandatory MCP evidence was captured against healthy database `supervisor_nexustk_20260713`; at `2026-07-13T12:20:07-04:00` health was `ok`, analysis/Hex-Rays/strings ready, and bounded target lookup succeeded. | exact | `idb_list`, `server_health`, `lookup_funcs` | UID0004BQ IDA Evidence; report Evidence Checked | incorporate | applied | Target IDA evidence retains the bounded health/lookup facts; UID0004BQ passed scoped validator `000000009907`. |
| C02 | Target is exactly `[0x004af040,0x004af371)`, size `0x331`/817, SHA256 `C564ED1BB9A099D848C683B7D69A9E0A297C758CCF07B9A61D827AAD02F1908E`, 234 physical instructions plus 37 external EH instructions, 25 basic blocks, and one normal `retn 8`. | exact | lookup, full bytes, disasm, analyze_function | UID0004BQ range/boundary evidence | incorporate | applied | Exact range, size, hash, instruction/CFG counts, return, and pads are in UID0004BQ; validator `000000009907` returned exit 0/ok 1. |
| C03 | Source signature is `__thiscall` constructor with `unsigned int exchangeSessionId` and signed `char inventorySlot`; it returns `this` by constructor ABI. | very strong | target load/store, callers, `retn 8`, UID0003U9 `movsx` | UID0004BQ signature; UID000008 declaration | incorporate | applied | R1 and R2 use the exact signature/type; target/class validators `000000009907`/`000000009910` passed. |
| C04 | Caller xrefs are live dispatcher `0x004ad3bf` and no-route retained helper `0x004adaeb`; both allocate `0x274` and pass exchange id plus packet byte `+2` as inventory slot. | exact/very strong | xrefs, both caller bodies, route scans | UID0004BQ caller table; UID00014L; UID00014M; ExchangeDialog supports | incorporate | applied | Target, dispatcher, retained helper, ExchangeDialog class/file/aggregate carry live-versus-no-route evidence; validators `000000009907`, `000000009924`, `000000009926`, `000000009928`, `000000009931`, and `000000009933` passed. |
| C05 | AddItemWithCountDialog directly derives from DialogPane and calls `DialogPane(L"",9,1)`; AddItemDialog is a sibling, not a base. | exact | direct call and absent AddItemDialog call/control behavior | UID0004BQ, UID000008, UID0000KE, UID00033S | reject-stale | applied | R1/R2 and target/class/parent/file prose reject stale AddItemDialog inheritance; validators `000000009907`, `000000009910`, `000000009913`, and `000000009935` passed. |
| C06 | Compiler stores class vtables `0x00619fec/0x0061a04c/0x0061a07c` at `+0/+0xa0/+0xa4`; source must not hand-write vptrs. | exact | target stores, UID0003IE/UID0001XV | UID0004BQ and UID000008 evidence; vtables verify-only | already-present | already-present | Target/class evidence and both vtable pages preserve compiler no-code treatment; validators `000000009907`, `000000009910`, `000000009945`, and `000000009951` confirm blank vtable formal blocks. B003 waited command `000000009954` and later observed external header command `000000009979` both contain zero manual vtable-address assignments. |
| C07 | First control is `EPFImageControlPane` using bounds `(0,0,239,283)`, `DLGEXC3.EPF`, frame 0, mode 1, and `PAL01.PAL`; allocation is `0x14c`. | exact | target bytes/calls/resource xrefs | UID0004BQ control table and R1 | incorporate | applied | Exact control/resource/allocation evidence and R1 are in UID0004BQ; validator `000000009907` passed. |
| C08 | Controls two and three are image buttons 36 and 22 at `(50,149,113,173)` and `(129,149,192,173)`; insertion selectors are action 1 and cancel 2. | exact | target call sequence/arguments | UID0004BQ control table and R1 | incorporate | applied | Exact buttons, rectangles, insertion order, and selectors are in UID0004BQ R1/evidence; validator `000000009907` passed. |
| C09 | Packet byte inventory slot is resolved through `g_pUserPane->GetInventorySlotAddress(char)`; prompt formatting uses record `displayName`, LanguageMan id 158, and `swprintf_s` count 256. | very strong | calls `0x5a3870/0x4f0350/0x41b9b0`, `+6`, STR.RES extraction | UID0004BQ; UID000008; UID0001RP resource support | incorporate | applied | Target/class and STR.RES page carry the signed accessor, `displayName`, id 158/`0x9e`, count 256, package provenance, and no-hard-code rule; validators `000000009907`, `000000009910`, and `000000009943` passed. |
| C10 | Prompt static text uses `(28,35,211,107)` and exact style/color flags; count edit uses `(28,111,211,123)` and full TextEdit arguments, becoming selector 4. | exact | target push/call order and sibling signatures | UID0004BQ control table and R1 | incorporate | applied | UID0004BQ documents and emits both exact controls, arguments, rectangles, and selector order; validator `000000009907` passed. |
| C11 | Exact common tail is background resource, hover 4, focused 1, pending 2, field stores, final bounds, OnCreate overlay, OnShow back pane, and SlideOpenVertical; no singleton or direct updater call occurs, while OnCreate synchronously reaches generic refresh and virtual UID0004BS. | exact | target tail, `0x49dfd0 -> 0x49fe20`, vtable `0x61a038` | UID0004BQ, UID000008, UID00033S, UID0004BS, UID0000KE | incorporate | applied | R1 plus target/class/aggregate/file prose preserves exact ordering and indirect updater route; validators `000000009907`, `000000009910`, `000000009913`, and `000000009935` passed. UID0004BS was read-only and equals R4. |
| C12 | Class layout is base `0x26c`, dword `+0x26c`, char `+0x270`, natural tail through `+0x273`, total `0x274`; no explicit padding field. | very strong | caller allocations, DialogPane layout, field stores/reads | UID000008 class layout and R2; UID0004BQ | incorporate | applied | UID000008 contains the exact layout table and natural-padding rationale; R2 has only the two members. Target/class validators `000000009907`/`000000009910` passed. |
| C13 | Base cleanup state and five allocation cleanup funclets are compiler EH; source uses ordinary base construction/new expressions without explicit catches, deletes, cookies, or vptr code. | exact/source inference | external chunks `0x005fe509-0x005fe57d`, state sequence | UID0004BQ EH/negative evidence | incorporate | applied | UID0004BQ preserves every funclet/state exclusion and R1 uses ordinary source constructs; validator `000000009907` passed. |
| C14 | UID0004BR is `void OnControlCommand(int controlIndex, int notifyCode)`: control 1 gets selector-4 TextEdit, `ReadText(...,4)`, parses `%hu`, clamps `>=0xff`, writes the uninitialized local packet explicitly through scratch byte 8, sends eight bytes using `m_inventorySlot`, then slides/closes; control 2 only slides/closes. | exact/very strong | 85 instructions/five blocks, `retn 8`, UID0002OA, `0x4944f0`, constructor/action/helper data flow | validator-preserving UID0004BR rename and R3; UID000008/33S/33T/0000KE supports | reject-stale | applied | UID0004BR preserved its UID through the old-to-current validator path update, carries R3, `92/94`, position 20, and exhaustive evidence; validator `000000009916` passed and synchronized reverse links. |
| C15 | UID0004BS uses typed selectors 1/4, `IsEmpty`, and distinct `Disable()`/`Enable()` tails; no null test or boolean setter. It is not directly constructor-called but runs synchronously through `OnCreate -> 0x49fe20 -> virtual +0x4c`. | exact | 22 instructions/three blocks, slots `+0x50/+0x4c`, xref `0x61a038`, OnCreate xref/decompile, DialogPane, B002/B005 support | B002-owned UID0004BS exact R4; B003-owned UID000008/UID00033S coordination; control-contract links | reject-stale | applied | B003 class/aggregate/file/vtable prose incorporates the contract; validators `000000009910`, `000000009913`, `000000009935`, `000000009945`, and `000000009951` passed. Read-only normalized comparison found UID0004BS `92/94`, position 30, and exact R4 equality (`549 == 549` characters). |
| C16 | Direct source route remains UID000008 -> UID0000KE -> `NexusTK/ui/dialogs/ItemDialogs.cpp`; positions are constructor 10, control command 20, updater 30, packet event 40. | strong | physical/source family, current route, sibling order | target/control-command/updater/packet-event metadata; class/file docs | incorporate | applied | UID0004BQ/4BR/318 positions are 10/20/40; read-only UID0004BS is 30; class/file route and order are synchronized. Validators `000000009907`, `000000009910`, `000000009916`, `000000009919`, and `000000009935` passed. |
| C17 | No target split/reclassification: predecessor ends `0x004af031`, fifteen `0xcc` bytes precede target; fifteen `0xcc` bytes follow target to `0x004af380`; exact prefix has one match. | exact | lookup/get_bytes/find_bytes/signature | UID0004BQ range/padding/negative evidence | incorporate | applied | UID0004BQ and UID00033S retain exact predecessor/successor pads, prefix uniqueness, and no-split disposition; validators `000000009907`/`000000009913` passed. |
| C18 | Target score rises `86/90 -> 92/94`, metadata otherwise preserved except position 10, summary replacement, and exact formal block R1. | strong | C02-C17 | UID0004BQ header/body/formal | incorporate | applied | UID0004BQ is `92/94`, owner/emitter/reconstructable/Nested preserved, position 10, exact summary/R1; validator `000000009907` passed. |
| C19 | Class rises `85/89 -> 91/93`, parent rises `86/90 -> 91/93`, UID0004BR rises `88/91 -> 92/94`, B002 independently owns UID0004BS `86/90 -> 92/94`, and UID000318 rises `88/90 -> 92/94`; UID0004BR/UID000318 are validator-preservingly renamed, B003 applies R2/R3/R5, and R4 remains exact B002 coordination. | strong | full family/component, ABI, EventHandler, DialogPane, TextEdit, ownership, and control analysis | B003: UID000008/33S/4BR/318; B002 verify-only target UID0004BS | incorporate | applied | Class/parent/renamed children carry exact scores, summaries, evidence, and R2/R3/R5; validators `000000009910`, `000000009913`, `000000009916`, and `000000009919` passed. UID0004BS remained untouched and equals R4 exactly. |
| C20 | Caller formal R6 and all direct stale item/type wording become signed inventory-slot wording; retained helper/no-route, exact R5 packet-handler behavior, vtable no-code policy, file routes, packet negatives, and historical assumptions remain preserved. | strong | complete support text sweep and historical searches | UID00014L/14M, UID00033T, UID000318, UID0003IE/1XV, UID0000KE/0000J9/00004R/00014K/00014T, UID0001RP | incorporate | applied | All listed B003 destinations carry exact signed-slot/history/no-code/source evidence; validators `000000009919`, `000000009921`, `000000009924`, `000000009926`, `000000009928`, `000000009931`, `000000009933`, `000000009935`, `000000009940`, `000000009943`, `000000009945`, and `000000009951` passed. Waited command `000000009954` emitted R6 and each ItemDialogs definition once; later observed external command `000000009979` preserves those exact counts. |

## Positive Evidence Summary

- The target's direct base call, complete control construction, vtable stores, field stores, and dialog lifecycle form a coherent constructor with no unexplained block.
- Both caller sites pass the same exchange-session and packet-byte values, while the target's inventory accessor and prompt dereference prove the packet byte is an inventory slot.
- Action and retained helper serialize the same stored byte, proving constructor-to-submit lifetime and field identity.
- Existing DialogPane layout and both `0x274` allocations close the exact class tail without invented members.
- Current ItemDialogs source routing, sibling constructors, and vtable pages independently agree with class/file ownership.

## IDA MCP Facts

- Function/range facts: `sub_4AF040`, `0x331` bytes, exact end `0x004af371`, 234 physical instructions, 25 blocks, one normal return at `0x004af36e retn 8`; IDA's 271 total includes 37 external EH/handler instructions.
- Triggered-method facts: UID0004BR is `0xfa`/250 bytes, 85 instructions, five blocks, and two `retn 8` exits with no return-value store; UID0004BS is `0x37`/55 bytes, 22 instructions, three blocks, and two virtual tail exits; UID000318 is `0x30`/48 bytes, 18 instructions, four blocks, one `retn 4`, and an always-false `AL` result. These exact support checks drive R2-R5 and the two validator-preserving source-name renames.
- Data/table/padding facts: target SHA256 is `C564ED1BB9A099D848C683B7D69A9E0A297C758CCF07B9A61D827AAD02F1908E`; exact prefix occurs once; pre-pad `[0x004af031,0x004af040)` and post-pad `[0x004af371,0x004af380)` are fifteen `0xcc` bytes each.
- Xref facts: target callers at `0x004ad3bf` and `0x004adaeb`; DLGEXC3 refs at `0x004af0f8/0x004af2d1`; PAL01 ref `0x004af0e8`; LanguageMan call `0x004af1e4`; inventory accessor call `0x004af1d0`; updater vtable ref `0x0061a038`.
- Vtable/global/type facts: table bases `0x00619fec/0x0061a04c/0x0061a07c`; canonical globals `g_pUserPane`, `g_pLanguageMan`, `g_mainUiLayerSlots.overlayPaneLayerContext`, and `g_pBackPane`; `LocalInventorySlotRecord::displayName` begins at `+0x06`.
- Allocation/control facts: exact allocations are `0x14c`/332 for the EPF image and `0x114`/276 for each action button, cancel button, static text, and text edit. Every successful object is immediately transferred through `AddControl`; no child pointer is stored as a derived member.
- Resource-package facts: zero-based STR.RES id `158` is line 159 of the current 248-line resource payload; the `baram.dat` entry begins at decimal offset `11,268,984`, has decimal size `7,058`, and currently decodes to `How many %ss will you add?`. The source body must retain the runtime lookup rather than embed that language variant.
- EH facts: external state-zero base cleanup begins at `0x005fe509`; five allocation cleanup funclets begin at `0x005fe514`, `0x005fe522`, `0x005fe530`, `0x005fe53e`, and `0x005fe54c`; frame-handler/cookie support begins at `0x005fe55a`. These are associated compiler chunks, not source children.
- Negative IDA facts: no AddItemDialog constructor call, no updater call, no singleton store, no nested target function, no duplicate exact prefix, and no static route to raw helper `0x004af4f0`.

### Basic-Block Coverage

The bounded live `basic_blocks` result reports exactly 25 nodes. Sixteen are contiguous source-body blocks inside `[0x004af040,0x004af371)`; the remaining nine are compiler-associated cleanup/handler or external terminal nodes. Every in-range byte belongs to exactly one listed block, and no external node changes the authored target range.

| Block range | Size | Successor(s) | Classification |
| --- | ---: | --- | --- |
| `0x004af040-0x004af0e8` | 168 | `0x004af0e8`, `0x004af106` | in-range constructor |
| `0x004af0e8-0x004af106` | 30 | `0x004af108` | in-range constructor |
| `0x004af106-0x004af108` | 2 | `0x004af108` | in-range allocation-null branch |
| `0x004af108-0x004af149` | 65 | `0x004af149`, `0x004af15b` | in-range constructor |
| `0x004af149-0x004af15b` | 18 | `0x004af15d` | in-range constructor |
| `0x004af15b-0x004af15d` | 2 | `0x004af15d` | in-range allocation-null branch |
| `0x004af15d-0x004af1a4` | 71 | `0x004af1a4`, `0x004af1b6` | in-range constructor |
| `0x004af1a4-0x004af1b6` | 18 | `0x004af1b8` | in-range constructor |
| `0x004af1b6-0x004af1b8` | 2 | `0x004af1b8` | in-range allocation-null branch |
| `0x004af1b8-0x004af22d` | 117 | `0x004af22d`, `0x004af251` | in-range constructor |
| `0x004af22d-0x004af251` | 36 | `0x004af253` | in-range constructor |
| `0x004af251-0x004af253` | 2 | `0x004af253` | in-range allocation-null branch |
| `0x004af253-0x004af291` | 62 | `0x004af291`, `0x004af2c1` | in-range constructor |
| `0x004af291-0x004af2c1` | 48 | `0x004af2c3` | in-range constructor |
| `0x004af2c1-0x004af2c3` | 2 | `0x004af2c3` | in-range allocation-null branch |
| `0x004af2c3-0x004af371` | 174 | none | in-range constructor return |
| `0x005fe509-0x005fe514` | 11 | `0x0049d9f0` | external base cleanup |
| `0x005fe514-0x005fe522` | 14 | none | external allocation cleanup 1 |
| `0x005fe522-0x005fe530` | 14 | none | external allocation cleanup 2 |
| `0x005fe530-0x005fe53e` | 14 | none | external allocation cleanup 3 |
| `0x005fe53e-0x005fe54c` | 14 | none | external allocation cleanup 4 |
| `0x005fe54c-0x005fe55a` | 14 | none | external allocation cleanup 5 |
| `0x005fe55a-0x005fe582` | 40 | `0x005c956c` | external frame-handler/cookie support |
| `0x0049d9f0` | 0 | none | external terminal node |
| `0x005c956c` | 0 | none | external terminal node |

## Function / Child Inventory

| Range / Item | UID / Path | Role | Reconstructable | Direct Parent | Score | Status |
| --- | --- | --- | --- | --- | --- | --- |
| `0x004af031-0x004af040` | parent-only padding | predecessor alignment | no source | UID00014U/physical neighborhood | n/a | preserve external padding |
| `0x004af040-0x004af371` | UID0004BQ target | constructor | true | UID000008 | `92/94` implemented | source block R1 applied; position 10 |
| `0x004af371-0x004af380` | UID00033S parent-only padding | alignment | no source | UID00033S | n/a | preserve |
| `0x004af380-0x004af47a` | UID0004BR; current validator-preserved path `0x004af380-0x004af47a.AddItemWithCountDialogOnControlCommand.md` | control-command handler | true | UID000008 | `92/94` implemented | exact ABI/helpers/packet/close block R3; position 20 |
| `0x004af47a-0x004af480` | UID00033S parent-only padding | alignment | no source | UID00033S | n/a | preserve |
| `0x004af480-0x004af4b7` | UID0004BS | button updater | true | UID000008 | B002-owned `92/94` implemented | B003 verify-only comparison proves current position 30 managed block equals R4 exactly |
| `0x004af4b7-0x004af4c0` | physical/file alignment | padding | no source | source neighborhood | n/a | preserve |
| `0x004af4c0-0x004af4f0` | UID000318; current validator-preserved path `0x004af4c0-0x004af4f0.AddItemWithCountDialogHandlePacketEvent.md` | packet-event virtual | true | UID000008 | `92/94` implemented | exact EventHandler block R5; position 40 |
| `0x004af4f0-0x004af570` | UID00033T | retained raw submit helper | true, non-emitting body | UID000008 | `86/90` unchanged | blank formal/no-route preserved; wording sync only |

## Direct Xref / Caller Inventory

| Address / Item | Xref / Caller / Callee | Meaning |
| --- | --- | --- |
| `0x004ad3bf` | UID00014L dispatcher -> target | Live opcode `0x42`, subcommand `1` construction path; passes secondary-view exchange id and packet inventory slot. |
| `0x004adaeb` | UID00014M retained helper -> target | Source-shaped but no-route duplicate caller; passes primary exchange id and the same inventory slot. |
| `0x004af08d` | target -> `DialogPane` constructor | Exact direct base construction `L"",9,1`; rejects AddItemDialog inheritance. |
| `0x004af0ae/0x004af0b4/0x004af0be` | target -> vtable stores | Compiler-installed three class views. |
| `0x004af0e8/0x004af0f8` | target -> `PAL01.PAL`/`DLGEXC3.EPF` | First background control resource operands. |
| `0x004af1d0` | target -> UID0003U9 | Signed inventory-slot record lookup. |
| `0x004af1e4` | target -> LanguageMan lookup | Exact localized id `158`. |
| `0x004af1f7` | target -> secure formatter `0x0041b9b0` | `swprintf_s`-shape prompt formatting with 256-wide-character destination. |
| `0x004af2d1` | target -> `DLGEXC3.EPF` | Background-resource assignment. |
| `0x004af307/0x004af316` | target field stores | Exchange id and signed slot are stored after control/selector setup. |
| `0x004af337/0x004af346/0x004af34d` | target lifecycle calls | OnCreate overlay, OnShow back pane, SlideOpenVertical. |
| `0x0049e119` | DialogPane OnCreate -> `0x0049fe20` | Synchronous generic refresh; wrapper dispatches primary `+0x4c` to UID0004BS after target controls/vptrs/fields exist. |
| `0x004af3cc/0x004af3d7/0x004af3e9` | UID0004BR control lookup/read/parse | Selector 4, UID0002OA `ReadText(...,4)`, then wide `%hu` scan. |
| `0x004af455/0x004af45c/0x004af463` | UID0004BR send/close tail | Eight-byte send, SlideClose, then CloseDialog for control 1; control 2 enters the same close pair. |
| `0x004af49d/0x004af4a2/0x004af4b1/0x004af4b4` | UID0004BS selector/predicate/tails | Selector 4 TextEdit `IsEmpty`; empty -> `Disable` slot `+0x50`, nonempty -> `Enable` slot `+0x4c`. |
| `0x004af4c6/0x004af4d5/0x004af4ea` | UID000318 EventHandler path | `event->packet`, compiler secondary-this `-0xa0`, and always-false result. |
| `0x0061a034/0x0061a038/0x0061a05c` | vtables -> control command/updater/packet event | Live virtual routes for UID0004BR, UID0004BS, and UID000318. |

## Documentation Evidence And IDA Status

- Existing docs that support the conclusion: UID0003U9 gives the exact signed accessor and record fields; UID0003IE/UID0001XV give exact vtable ownership; current DialogPane gives `OnControlCommand` and `GetChild<T>`; EventHandler gives `HandlePacketEvent(Event*)`; UID0002OA/TextEdit give `ReadText`/`IsEmpty`; UID00033T gives packet lifetime; callback-time B002 UID0004BS and B005 UID0004BP evidence gives exact enable/disable and generic-refresh contracts; UID0004BM gives accepted ItemDialogs source style; UID0001RP gives current STR.RES package provenance; executed B001 UID0004BN preserves only sibling destructor/order history.
- Existing docs that are stale or contradicted: target formal C++; target summary; AddItemWithCountDialog base/field/caller wording; parent `item/type`; UID0004BR basename/signature/helpers/field/packet initialization/close sequence; UID0004BS placeholder body (independently owned by B002); UID000318 basename/signature/null test/adjustment/close helper; caller `selectedItemType`; ExchangeDialog and ItemDialogs support wording; B007 shallow constructor assumptions.
- Historical pre-callback generated state: validator-owned `auto-generated/NexusTK/ui/dialogs/ItemDialogs.cpp`, command `000000009852`, emitted the false target body and an Empty Emitter Marker for UID000008. A later historical read-only recheck after supervisor execution of B001 UID0004BN observed command `000000009890`, refreshed `2026-07-13T12:45:06-04:00`: AddItemDialog's destructor was present, while UID0004BQ still had the shallow constructor, UID0004BR the stale `OnAction`, UID0004BS its placeholder, UID000318 the stale `OnClosePacket`, and UID000008/UID00033T Empty Emitter Markers. Post-callback waited command `000000009954`, refreshed `2026-07-13T13:16:52-04:00`, emitted the UID000008 class closed at line 203 followed at namespace scope by R1, R3, exact B002 R4, and R5 once each; it had no UID0004BQ or UID000008 Empty Emitter Marker and no `AddItemWithCountDialog::OnAction` or `AddItemWithCountDialog::OnClosePacket` definition. The latest read-only audit observed later external header command `000000009979`, refreshed `2026-07-13T13:25:20-04:00`, with the same structure and counts. UID00033T remains an intentional blank-formal Empty Emitter Marker. Generated output remained validator-owned and was inspected read-only.

## Ranked Ownership Analysis

### 1. UID000008 AddItemWithCountDialog through UID0000KE ItemDialogs

- Evidence for: class-specific RTTI/vtables, target field lifetime into class virtuals, physical ItemDialogs island, sibling source style, current canonical route, and generated path.
- Evidence against: exact original header split and lexical access specifiers are stripped.
- Decision: direct owner/emitter and file route retained.

### 2. UID00004R ExchangeDialog through UID0000J9 ExchangeDialog

- Evidence for: live and retained constructor call sites originate in exchange packet handling and provide the session id.
- Evidence against: ExchangeDialog only allocates/constructs the reusable dialog; target uses AddItemWithCountDialog vtables/fields/resources and later handles its own control-command/update/packet-event behavior.
- Decision: caller/support owner only; rejected as target owner/source file.

### 3. UID000007 AddItemDialog / NumberInputDialog / Employee quantity dialogs

- Evidence for: related dialog UI patterns and shared controls/resources.
- Evidence against: target does not call AddItemDialog, does not build its list, does not publish its singleton, and does not invoke NumberInputDialog. Employee/number dialogs are convention support only.
- Decision: sibling/dependency evidence; rejected as base or owner.

### Proposed new file/grouping, if applicable

- No new file was needed or created. The implementation uses the existing `NexusTK/ui/dialogs/ItemDialogs.cpp` route.
- Keep AddItemDialog, AddItemWithCountDialog, MixItemDialog, AddMixingItemDialog, and retained item-dialog helper documentation in the established source family.
- Keep ExchangeDialog implementation, LivingObjectPane inventory storage, LanguageMan resource loading, and generic controls in their existing owners.

## Source Placement

- Recommended placement: class declaration and methods under UID000008, emitted by UID0000KE to `NexusTK/ui/dialogs/ItemDialogs.cpp`.
- Source order: class declaration followed by constructor position 10, control-command position 20, updater position 30, packet-event position 40; retained no-route helper remains documented with blank formal C++.
- Why: address/source island, class vtables, project source tree, sibling classes, and current generated route all agree.
- Rejected placements: `ExchangeDialog.cpp`, `NumberInputDialog.cpp`, `LivingObjectPane.cpp`, `EmployeeDialogPane.cpp`, a new `AddItemWithCountDialog.cpp`, or aggregate-only output. A future coordinated ItemDialogs file split would require broader evidence and is outside this assignment.

## Range / Split / Padding / Reclassification Analysis

- Exact target range is `[0x004af040,0x004af371)`, `0x331`/817 bytes. All 234 physical instructions belong to the constructor. One normal return ends at `0x004af371` exclusive.
- IDA's additional 37 instructions at `0x005fe509-0x005fe57d` are external base/allocation cleanup and frame-handler chunks associated with the same constructor, not children to split.
- Predecessor UID0002JQ function ends at `0x004af031`; `[0x004af031,0x004af040)` is fifteen `0xcc` bytes. `[0x004af371,0x004af380)` is another fifteen-byte `0xcc` span before UID0004BR.
- No internal function start, jump table, data table, foreign owner, or padding exists inside the target. Exact prefix search has one match.
- Parent UID00033S keeps `Nested:8`; target/control-command/updater keep `Nested:0`; retained helper UID00033T keeps its established relative `Nested:-8`. No nesting value is derived from child count.
- No target split, merge, rename, ignored-range conversion, compiler-only reclassification, or child registration was applied. The two separately addressable support methods kept their exact UIDs/ranges and completed validator-preserving path/title renames from historical behavior labels to `OnControlCommand` and `HandlePacketEvent`.

## Negative Evidence Summary

- No call or inlined behavior supports `AddItemDialog` base construction.
- No instruction supports `CreateCountInputControls`, a direct constructor call to `UpdateActionButton`, hard-coded prompt text, item-type semantics, singleton publication, explicit member initializer timing, or numeric input validation in UID0004BS. The separately proved synchronous `OnCreate` virtual refresh is retained.
- No target byte belongs to the predecessor, successor, vtable data, STR.RES payload, or retained helper.
- No exact duplicate target body exists. Caller-side duplicated allocation/call code does not make the constructor inline or no-code.
- Consumer xrefs from ExchangeDialog do not transfer implementation ownership. Shared DLGEXC3/PAL01 resources do not transfer resource ownership.
- Vptr writes, cookie checks, far cleanup funclets, and delete-on-construction-failure paths are compiler-generated effects, not authored source statements.

## IDA Rename / Type / Comment Recommendations

- Source-facing function name: `AddItemWithCountDialog::AddItemWithCountDialog` for `sub_4AF040`.
- Source-facing parameters: `unsigned int exchangeSessionId`, `char inventorySlot`.
- Source-facing fields: `unsigned int m_exchangeSessionId`, `char m_inventorySlot`.
- Source-facing locals: `RectBounds bounds`, `wchar_t promptText[256]`, `LocalInventorySlotRecord *inventoryItem`.
- Source-facing primary callback: `void OnControlCommand(int controlIndex, int notifyCode)`; validator-preservingly rename UID0004BR from the historical `OnAction` basename.
- Source-facing updater: keep `UpdateActionButton`; express selectors through DialogPane `GetChild<T>`, `TextEditControlPane::IsEmpty`, and distinct ImageButton `Enable()`/`Disable()` calls. UID0004BS remains B002-owned.
- Source-facing secondary callback: `bool HandlePacketEvent(Event *event)`; validator-preservingly rename UID000318 from the historical packet-close basename and let the compiler generate secondary-this adjustment.
- Source-facing caller local: `char inventorySlot`, replacing `unsigned char selectedItemType`.
- IDA DB edits are not requested and were not performed. If a later supervisor-approved IDA pass applies types, it must preserve exact ABI slots, signed low-byte semantics, and compiler EH chunks.

## First-Draft C++ Recommendation

The source-bearing destination blocks are R1 target constructor, R2 class declaration, R3 exact control-command replacement, R4 B002-owned updater coordination, R5 exact packet-event replacement, and R6 live dispatcher caller-name/type correction. These blocks remain complete destination or explicit coordination values; no partial snippets are intended. B003 applied R1/R2/R3/R5/R6 exactly. R4 is reproduced byte-for-byte from B002's dedicated UID0004BS Destination 1, was not B003 edit authority, and equals the callback-time UID0004BS page exactly.

### R1 - UID0004BQ target constructor

*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
AddItemWithCountDialog::AddItemWithCountDialog(unsigned int exchangeSessionId,
                                               char inventorySlot)
    : DialogPane(L"", 9, 1)
{
    RectBounds bounds;
    wchar_t promptText[256];

    InitRectBounds(&bounds, 0, 0, 239, 283);
    AddControl(new EPFImageControlPane(L"DLGEXC3.EPF", 0, 1,
                                       &bounds, L"PAL01.PAL"));

    InitRectBounds(&bounds, 50, 149, 113, 173);
    AddControl(new ImageButtonControlPane(36, &bounds));

    InitRectBounds(&bounds, 129, 149, 192, 173);
    AddControl(new ImageButtonControlPane(22, &bounds));

    LocalInventorySlotRecord *inventoryItem =
        g_pUserPane->GetInventorySlotAddress(inventorySlot);
    swprintf_s(promptText, 256,
               g_pLanguageMan->GetLocalizedString(158),
               inventoryItem->displayName);

    InitRectBounds(&bounds, 28, 35, 211, 107);
    AddControl(new StaticTextControlPane(promptText, true, 128, 0,
                                         &bounds, false, false));

    InitRectBounds(&bounds, 28, 111, 211, 123);
    AddControl(new TextEditControlPane(L"", true, 128, 0,
                                       &bounds, false, false, false, false,
                                       1.0f, 0));

    SetBackgroundResource(L"DLGEXC3.EPF", NULL);
    SetHoverControl(4);
    SetFocusedControl(1);
    SetPendingControl(2);

    m_exchangeSessionId = exchangeSessionId;
    m_inventorySlot = inventorySlot;

    InitRectBounds(&bounds, 0, 0, 239, 283);
    OnCreate(&bounds, 0, NULL, g_mainUiLayerSlots.overlayPaneLayerContext);
    OnShow(NULL, g_pBackPane);
    SlideOpenVertical();
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

### R2 - UID000008 class declaration

*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
class Event;

class AddItemWithCountDialog : public DialogPane
{
public:
    AddItemWithCountDialog(unsigned int exchangeSessionId,
                           char inventorySlot);

    virtual void OnControlCommand(int controlIndex, int notifyCode);
    virtual bool HandlePacketEvent(Event *event);
    virtual void UpdateActionButton();

private:
    unsigned int m_exchangeSessionId;
    char m_inventorySlot;
};

[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

### R3 - UID0004BR control-command handler

*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
void AddItemWithCountDialog::OnControlCommand(int controlIndex, int notifyCode)
{
    (void)notifyCode;

    if (controlIndex == 1)
    {
        wchar_t countText[16];
        unsigned short parsedCount;
        TextEditControlPane *countInput =
            GetChild<TextEditControlPane>(4);

        countInput->ReadText(countText, 4);
        swscanf(countText, L"%hu", &parsedCount);
        if (parsedCount >= 0xff)
            parsedCount = 0xff;

        unsigned char packet[9];
        PacketBufferWriteUInt8(0x4a, packet);
        PacketBufferWriteUInt8(2, packet + 1);
        PacketBufferWriteUInt32BE(m_exchangeSessionId, packet + 2);
        PacketBufferWriteUInt8(m_inventorySlot, packet + 6);
        PacketBufferWriteUInt8(static_cast<unsigned char>(parsedCount),
                               packet + 7);
        packet[8] = 0;
        g_packetSender->QueueAndSendPacket(packet, 8);
    }
    else if (controlIndex != 2)
    {
        return;
    }

    SlideClose();
    CloseDialog();
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

### R4 - UID0004BS updater

*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
void AddItemWithCountDialog::UpdateActionButton()
{
    ImageButtonControlPane *actionButton =
        GetChild<ImageButtonControlPane>(1);
    TextEditControlPane *countInput =
        GetChild<TextEditControlPane>(4);

    if (countInput->IsEmpty())
        actionButton->Disable();
    else
        actionButton->Enable();
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

### R5 - UID000318 packet-event handler

*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
bool AddItemWithCountDialog::HandlePacketEvent(Event *event)
{
    const unsigned char *packet = event->packet;

    if (packet[0] == 0x42 && packet[1] == 4)
    {
        SlideClose();
        CloseDialog();
    }

    return false;
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

### R6 - UID00014L dispatcher

*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
bool ExchangeDialog::DispatchExchangePacket(Event *event)
{
    const unsigned char *packet = event->packet;
    if (packet[0] != 0x42) {
        return false;
    }

    switch (packet[1]) {
    case 1: {
        const char inventorySlot =
            static_cast<char>(PacketReadByte(packet + 2));
        new AddItemWithCountDialog(m_exchangeSessionId, inventorySlot);
        return true;
    }

    case 2: {
        const bool remoteSide = PacketReadByte(packet + 2) != 0;
        const unsigned char rowKey = PacketReadByte(packet + 3);
        const unsigned short itemId = PacketReadUInt16BE(packet + 4);
        const unsigned char color = PacketReadByte(packet + 6);
        const unsigned int nameLength = PacketReadByte(packet + 7);

        char nameBytes[256];
        wchar_t nameText[256];
        memcpy(nameBytes, packet + 8, nameLength);
        nameBytes[nameLength] = 0;

        int converted = MultiByteToWideChar(CP_ACP, 0, nameBytes,
                                            nameLength, nameText, 256);
        nameText[static_cast<unsigned char>(converted)] = 0;

        ExchangeItemListPane *list =
            static_cast<ExchangeItemListPane *>(GetControl(remoteSide ? 8 : 5));

        int insertIndex = list->GetRowCount();
        for (int i = 0; i < insertIndex; ++i) {
            const ExchangeItemListRow *existing =
                static_cast<const ExchangeItemListRow *>(list->GetRow(i));
            if (existing->key == rowKey) {
                list->RemoveRows(i, 1);
                insertIndex = i;
                break;
            }
        }

        ExchangeItemListRow row;
        memset(&row, 0, sizeof(row));
        row.key = rowKey;
        row.itemId = itemId;
        row.color = color;
        wcscpy_s(row.name, 256, nameText);
        list->InsertRow(insertIndex, &row);
        return true;
    }

    case 3: {
        const bool remoteSide = PacketReadByte(packet + 2) != 0;
        const unsigned int amount = PacketReadUInt32BE(packet + 3);

        ControlPane *control;
        if (remoteSide) {
            control = GetControl(9);
        } else {
            if (amount == 0) {
                SetExchangeAmount(0);
            }
            control = GetControl(6);
        }

        wchar_t text[32];
        swprintf_s(text, 32, L"%u", amount);
        control->SetText(text);
        return true;
    }

    case 4: {
        char textBytes[256];
        wchar_t message[256];

        const unsigned int length = PacketReadByte(packet + 3);
        memcpy(textBytes, packet + 4, length);
        textBytes[length] = 0;

        int converted = MultiByteToWideChar(CP_ACP, 0, textBytes,
                                            length, message, 256);
        message[static_cast<unsigned char>(converted)] = 0;

        if (g_pExchangeAlertPane != 0) {
            g_pExchangeAlertPane->Close(1);
        }

        new ExchangeAlertPane(message, this, g_szDialogOk, 0);
        SlideClose();
        CloseDialogPane(this);

        if (g_pAddItemDialog != 0) {
            CloseDialogPane(g_pAddItemDialog);
        }
        return true;
    }

    case 5: {
        const bool remoteReady = PacketReadByte(packet + 2) != 0;

        if (remoteReady) {
            m_peerReadyConfirmed = 1;
            if (m_localReadyConfirmed != 1) {
                RefreshSelectedControlAfterStateUpdate();
                return true;
            }
        } else {
            const unsigned char wasPeerReady = m_peerReadyConfirmed;
            m_localOfferPending = 0;
            m_localReadyConfirmed = 1;
            if (wasPeerReady != 1) {
                RefreshSelectedControlAfterStateUpdate();
                return true;
            }
        }

        char textBytes[256];
        wchar_t message[256];

        const unsigned int length = PacketReadByte(packet + 3);
        memcpy(textBytes, packet + 4, length);
        textBytes[length] = 0;

        int converted = MultiByteToWideChar(CP_ACP, 0, textBytes,
                                            length, message, 256);
        message[static_cast<unsigned char>(converted)] = 0;

        if (g_pExchangeAlertPane != 0) {
            CloseActiveExchangeAlertPane();
        }

        new ExchangeAlertPane(message, this, g_szDialogOk, 0);
        SlideClose();
        CloseDialogPane(this);
        return true;
    }

    default:
        return true;
    }
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

R1 preserves exact observed behavior and source order while leaving vptrs, cookies, and EH cleanup to the compiler. R2 closes the class before `[[CHILDREN]]`, gives natural layout without raw offset comments or artificial padding, and declares the accepted DialogPane/EventHandler callback contracts. R3 reproduces the two-argument void ABI, typed control read, `%hu` parse, exact clamp, intentionally uninitialized locals, eight-byte send, scratch byte, and slide/close flow. R4 is the B002-owned exact three-block updater using typed child lookup and separate disable/enable tails. R5 replaces the stale raw-packet/null-test draft with the exact EventHandler source override and compiler-generated secondary-this adjustment. R6 preserves the accepted dispatcher body and changes only the exact packet-byte type/name and target call.

The source shape is period-consistent with the accepted project reconstruction: raw owning allocations are transferred directly to the dialog control host; fixed stack arrays, `NULL`, `swprintf_s`, explicit casts, and direct singleton/global access match sibling ItemDialogs and input-dialog code; there is no modern RAII/container abstraction or decompiler-shaped offset access. Names follow established project spellings for `RectBounds`, control classes, DialogPane setup, LanguageMan, UserPane inventory access, and packet helpers. No third-party import directive applies.

UID00033T remains blank because its exact body has no static route and duplicates the live control-command send. UID0003IE/UID0001XV vtable C++ remains blank/non-emitting because vtables are compiler output from declarations. B002-owned UID0004BS was verified against R4 rather than edited by B003: the normalized managed blocks are exactly equal at 549 characters each.

## Final Recommendation

- C01-C20 are applied with destination-specific proof in the ledger.
- UID0004BQ remains one reconstructable constructor under UID000008/UID0000KE; no target split/rename/new UID occurred. Only the separately listed validator-preserving UID0004BR/UID000318 support renames were performed.
- B003-owned target/class/control-command/packet-event/dispatcher managed blocks equal R1/R2/R3/R5/R6. B002-owned UID0004BS equals coordination block R4 and was not edited by B003.
- The retained-helper blank formal policy and vtable compiler no-code policy are preserved.
- Every directly affected B003-owned support page now uses signed inventory-slot semantics without changing unrelated behavior, scores, or routes.
- Executed B001 UID0004BN remained read-only; B002/B005 ownership was re-read before shared edits. No statement here directs or predicts another agent's lifecycle.
- IDA, generated files, coverage/tracker files, supervisor state, validator state, and report lifecycle remained external to B003's manual edits.

## Recommended Target Doc Changes

- Target path: `by-memory/0x004af040-0x004af371.AddItemWithCountDialogConstructor.md`.
- Implemented metadata: `86/90 -> 92/94`; owner/emitter UID000008 unchanged; reconstructable true unchanged; `Nested:0` unchanged; position `10`.
- Exact Item Summary value: `Direct DialogPane-derived AddItemWithCountDialog constructor; builds DLGEXC3 controls and a localized inventory-slot count prompt, stores exchange-session/slot state, then creates, shows, and vertically slides the dialog.`
- Formal C++: R1 applied exactly.
- Body detail: exact range/size/hash/instructions/blocks/return, both callers and live/no-route status, direct base, all controls/resources/rectangles/selectors, localization/record fields, field layout and timing, lifecycle order, EH compiler exclusions, unique-body check, source route, score rationale, and every rejected stale assumption.

## Recommended Support Doc Changes

| Support path | Exact report facts to incorporate | Metadata/formal disposition |
| --- | --- | --- |
| `by-class/AddItemWithCountDialog.md` UID000008 | Direct DialogPane base; exact `0x274` layout; field/parameter semantics; one live plus one retained constructor call; exact `OnControlCommand`, `HandlePacketEvent`, and updater declarations; complete control/vtable/lifecycle/history evidence. | Implemented `85/89 -> 91/93`; exact R2; route unchanged. |
| `by-memory/0x004af040-0x004af4b7.AddItemWithCountDialogCore.md` UID00033S | Exhaustive constructor/control-command/updater inventory; slot semantics; direct-versus-indirect updater timing; padding and retained-helper relation. Exact Item Summary: `AddItemWithCountDialog source cluster: direct DialogPane constructor, count-aware control-command handler, and empty-text action-button updater, with internal padding retained on the aggregate.` | Implemented `86/90 -> 91/93`; existing `[[CHILDREN]]` aggregate block and `Nested:8` unchanged. |
| Historical `by-memory/0x004af380-0x004af47a.AddItemWithCountDialogOnAction.md` -> current `by-memory/0x004af380-0x004af47a.AddItemWithCountDialogOnControlCommand.md` UID0004BR | Completed validator-preserving rename; exact two-argument void ABI, selector-4 TextEdit read capacity 4, `%hu` parse, uninitialized locals, `>=255` clamp, signed inventory-slot packet, eight-byte send/unsent scratch, and slide/close flow. Exact Item Summary: `AddItemWithCountDialog control-command override; control 1 reads and clamps selector-4 count text, sends opcode 0x4A/2 with the signed inventory slot, then slides/closes, while control 2 only slides/closes.` | Implemented `88/91 -> 92/94`; position `20`; exact R3. |
| `by-memory/0x004af480-0x004af4b7.AddItemWithCountDialogUpdateActionButton.md` UID0004BS | Exact selectors, `IsEmpty`, distinct `Disable`/`Enable`, no null test, no direct constructor call, and synchronous generic OnCreate refresh. Exact B002 Item Summary: `AddItemWithCountDialog virtual action-button updater; retrieves action button selector 1 and count editor selector 4, then disables for empty text and enables for nonempty text through distinct state virtuals.` | B002-owned `86/90 -> 92/94`, position `30`, exact R4. B003 read-only verification; no edit/lease/validator. |
| Historical `by-memory/0x004af4c0-0x004af4f0.AddItemWithCountDialogExchangePacketCloseHandler.md` -> current `by-memory/0x004af4c0-0x004af4f0.AddItemWithCountDialogHandlePacketEvent.md` UID000318 | Completed validator-preserving rename; exact EventHandler `+0x10` override, `event->packet`, no null test, `0x42/0x04`, compiler secondary-this adjustment, slide/close, and always-false return. Exact Item Summary: `AddItemWithCountDialog EventHandler packet-family override; server packet 0x42/0x04 slides and closes the dialog, and every path returns false.` | Implemented `88/90 -> 92/94`; position `40`; exact R5. |
| `by-memory/0x004af4f0-0x004af570.AddItemWithCountDialogSubmitPacketHelper.md` UID00033T | Signed inventory-slot prose and candidate-field text synchronized; raw `0x80` body, no route, live inline duplicate, eight sent bytes, unsent scratch zero, blank formal, and score preserved. Exact Item Summary: `Retained no-route AddItemWithCountDialog count-packet helper; exact raw body mirrors live OnControlCommand serialization and keeps formal C++ blank.` | Implemented wording only; `86/90`, blank formal, and position unchanged. |
| `by-memory/0x004ad320-0x004ad7b3.ExchangeDialogPacketDispatcher.md` UID00014L | Subcommand 1 now uses signed inventory slot and remains the only live constructor route; every other case is preserved. | Implemented exact R6; `89/91` unchanged. |
| `by-memory/0x004ada90-0x004adb02.ExchangeDialogAddItemWithCountHelper.md` UID00014M | Inventory-slot semantics are synchronized; exact body/padding/EH/no-route and dispatcher covered-by marker are preserved. | Implemented wording only; `86/90` and formal marker unchanged. |
| `by-class/ExchangeDialog.md`, `by-file/ExchangeDialog.md`, `by-memory/0x004ac8a0-0x004ae4b6.ExchangeDialog.md` UID00014K | Direct helper/caller history now uses inventory slot; primary/secondary exchange-id reconciliation is preserved. | Implemented wording only; scores/routes/formal unchanged. |
| `by-file/ItemDialogs.md` UID0000KE | Current route is `NexusTK/ui/dialogs/ItemDialogs.cpp`; exact constructor/control-command/updater/packet-event/helper children and renamed paths, signed-slot semantics, retained-helper policy, and executed sibling ownership history are recorded. | Implemented wording only; `91/90` unchanged. |
| `by-memory/0x004ae4c0-0x004b0ba5.ItemExchangeMixDialogs.md` UID00014T | AddItemWithCount slot semantics are corrected; the non-emitting broad aggregate and source-boundary evidence are preserved. | Implemented wording only; scores/routes unchanged. |
| `by-resource/str-res-localized-strings.md` UID0001RP | Carries confirmed zero-based id 158 / `0x9e`, current text `How many %ss will you add?`, target consumer, package provenance, and no-hard-coded-English rule. | Implemented wording only; `89/94` unchanged. |
| `by-type/by-vtable/AddItemWithCountDialogVtables.md` UID0003IE and `ItemDialogVtableFamily.md` UID0001XV | Exact tables/compiler no-code proof is preserved; primary `+0x48` names UID0004BR `OnControlCommand`, primary `+0x4c` names UID0004BS updater, and secondary `+0x10` names UID000318 `HandlePacketEvent`. | Implemented prose/link synchronization; scores/owners/routes/blank formal C++ unchanged. |
| `by-class/DialogPane.md` UID00003T, `by-class/EventHandler.md` UID00004N, TextEdit UID0002OA/UID0004K7, B005 control destinations, and B002 UID0004BS | Existing or independently owned exact API facts support R2-R5. | Verified read-only by B003; no duplicate B002/B005 edit. |
| `by-memory/0x005a3870-0x005a3889.LivingObjectPaneGetInventorySlotAddress.md` UID0003U9 and quantity-format UID0003NI | Existing signed accessor/display-name and `%hu` facts are already sufficient. | Verify-only, unchanged. |
| `executed-b-agent-research/B001/0004BN-AddItemDialogDestructor-source-quality.md` | Executed sibling destructor/source-order history only; its incidental ExchangeDialog wording does not alter this target. | Read-only external lifecycle state; no B003 by-* or report edit destination. |

## Score And Metadata Recommendation

- Historical pre-callback target: `86/90`, owner/emitter UID000008, reconstructable true, blank position, `Nested:0`.
- Implemented target: `92/94`, same owner/emitter/reconstructable/nesting, position `10`, exact R1.
- Why not lower: every instruction block, caller, field, control, resource, lifecycle call, EH effect, boundary, and source route is accounted for.
- Why not `95+`: original parameter/member/local spelling and exact class access control are stripped; inherited UI method lexical spellings remain project-stable inference; retained helper source integration remains deliberately no-route/blank.
- Score-improvement attempt results:
  - Base blocker: resolved by direct base call and negative AddItemDialog call/behavior.
  - Parameter blocker: resolved from caller packet source, signed accessor, prompt dereference, and submit reuse.
  - Field/layout blocker: resolved from allocations, DialogPane size, stores, action/helper reads, and natural alignment.
  - Control/helper blocker: resolved from every target call, current DialogPane/EventHandler/TextEdit declarations, callback-time B002 UID0004BS, B005 control-slot proof, and live B003 action/updater/packet-handler disassembly.
  - Resource blocker: resolved to exact shared filenames and STR.RES id 158 payload provenance.
  - Update timing blocker: resolved as no direct call but synchronous indirect `OnCreate -> 0x49fe20 -> virtual +0x4c` refresh.
  - EH/source-shape blocker: resolved to ordinary base/new expressions and compiler cleanup.
  - Source-placement blocker: resolved to existing ItemDialogs route with caller-only Exchange boundary.
  - Lexical/access blocker: exhausted binary/docs/reports/generated output; remains inferred and only caps below 95.

## Open Questions With Attempted Resolution

- Original lexical spelling: no PDB/source symbol or recovered UDT member names exist. Behavior-backed names in R1-R6 use current accepted interface contracts where available and the highest-probability coherent local spellings elsewhere. Impact: confidence cap only, no C++ blocker.
- Original access specifiers: external construction proves constructor accessibility, but callback methods could have been public or protected. The project-generated convention uses public virtual declarations; private data fields are the least permissive coherent choice. Impact: class score cap only.
- Retained UID00033T source integration: exhaustive route scans show no static route, while live control-command code duplicates the send. Keep blank formal and preserve its binary evidence. This does not block target/class/control-command/updater/packet-event C++.
- Concurrent ownership: at callback evidence time B002 owned UID0004BS and B005 owned shared control destinations. Resolution: R4 is exact B002 coordination; B003 left those targets verify-only, re-read current paths before shared edits, and confirmed the B002 page equals R4. Executed B001 UID0004BN remained read-only history.
- Resource language variants: current package proves id 158 text, not universal English text. R1 correctly retains the runtime lookup, so no C++ blocker.
- Explicit destructor: no class-specific authored destructor behavior or singleton cleanup exists. Let the compiler/base hierarchy supply implicit destruction; do not invent a declaration/body solely from vtable ABI support.

## Exact Manual Supervisor-Owned Coverage Or Tracker Text

- Not applicable. The queue and generated coverage are validator-owned. The target `Item Summary`/score was updated through its ordinary by-* page and scoped validator; B003 wrote no manual coverage/tracker row.

## Follow-Up Actions

- Implementation and scoped/generated verification are complete. No B003-owned accepted item remains unapplied.
- Report validation/execution/count/path/move/archive state is external supervisor/validator-owned and is neither asserted nor directed by this artifact. B003 performed no report execute, lifecycle, move, or archive command.
- UID0004BS and B005-owned control pages remain external verify-only dependencies; they were not leased, edited, or validated by B003. Executed B001 UID0004BN remains external read-only history.
- Later source/symbol evidence may supersede only the explicitly inferred lexical names; no additional assignment or lifecycle action is prescribed here.

## Confidence

- Recommendation confidence: `94/100`.
- Score confidence: high for target `92/94`, class/parent `91/93`, B003-owned control-command/packet-event `92/94`, and B002-owned updater `92/94`; support scores listed unchanged are deliberately conservative.
- Remaining uncertainty: stripped local/member spellings, access specifiers, and retained-helper original source integration only. No remaining uncertainty blocks exact first-draft constructor/class/control-command/updater/packet-event/caller code.

## Validator Results

All commands ran from `source-3/project-documentation` with `--apply --queue-timeout 240`; every scoped run returned exit `0`, `ok:1`, and `generated_refresh: deferred`. Each edit lease was released immediately after its scoped validator. Validator-managed metadata/reference/statistics side effects were accepted; generated/coverage/registry files were never edited manually.

| Changed ordinary by-* destination | command_id | command_timestamp | Exit / ok | Relevant side effects and warnings |
| --- | --- | --- | --- | --- |
| `by-memory/0x004af040-0x004af371.AddItemWithCountDialogConstructor.md` | `000000009907` | `2026-07-13T12:58:18-04:00` | `0 / 1` | Completion/confidence, position and formal hash registered; references/statistics updated; generated deferred. |
| `by-class/AddItemWithCountDialog.md` | `000000009910` | `2026-07-13T12:59:49-04:00` | `0 / 1` | Class scores/formal hash/references/statistics updated; generated deferred. |
| `by-memory/0x004af040-0x004af4b7.AddItemWithCountDialogCore.md` | `000000009913` | `2026-07-13T13:00:50-04:00` | `0 / 1` | Aggregate scores/summary/references/statistics updated; generated deferred. |
| Historical UID0004BR path -> `by-memory/0x004af380-0x004af47a.AddItemWithCountDialogOnControlCommand.md` | `000000009916` | `2026-07-13T13:02:03-04:00` | `0 / 1` | Validator preserved UID0004BR, registered old-to-current `path_update`, scores/position/formal hash, and reverse-link updates; generated deferred. |
| Historical UID000318 path -> `by-memory/0x004af4c0-0x004af4f0.AddItemWithCountDialogHandlePacketEvent.md` | `000000009919` | `2026-07-13T13:03:08-04:00` | `0 / 1` | Validator preserved UID000318, registered path/scores/position/formal hash and reverse-link updates; 12 pre-existing missing-ref warnings for unrelated absent UIDs were reported; generated deferred. |
| `by-memory/0x004af4f0-0x004af570.AddItemWithCountDialogSubmitPacketHelper.md` | `000000009921` | `2026-07-13T13:04:14-04:00` | `0 / 1` | Added UID0004BR reference; retained blank formal/no-route; generated deferred. |
| `by-memory/0x004ad320-0x004ad7b3.ExchangeDialogPacketDispatcher.md` | `000000009924` | `2026-07-13T13:05:17-04:00` | `0 / 1` | R6 hash/source text synchronized; generated deferred. |
| `by-memory/0x004ada90-0x004adb02.ExchangeDialogAddItemWithCountHelper.md` | `000000009926` | `2026-07-13T13:06:08-04:00` | `0 / 1` | Signed-slot support prose synchronized; generated deferred. |
| `by-class/ExchangeDialog.md` | `000000009928` | `2026-07-13T13:06:59-04:00` | `0 / 1` | Added direct support reference and synchronized caller/source history; generated deferred. |
| `by-file/ExchangeDialog.md` | `000000009931` | `2026-07-13T13:08:04-04:00` | `0 / 1` | Source-state wording synchronized; one pre-existing missing UID0003U3 warning; generated deferred. |
| `by-memory/0x004ac8a0-0x004ae4b6.ExchangeDialog.md` | `000000009933` | `2026-07-13T13:08:48-04:00` | `0 / 1` | Aggregate caller/field/source-boundary evidence synchronized; generated deferred. |
| `by-file/ItemDialogs.md` | `000000009935` | `2026-07-13T13:09:47-04:00` | `0 / 1` | Source route/children/history/references synchronized while preserving B005 content; five pre-existing missing UID0003IG warnings; generated deferred. |
| `by-memory/0x004ae4c0-0x004b0ba5.ItemExchangeMixDialogs.md` | `000000009940` | `2026-07-13T13:11:39-04:00` | `0 / 1` | Broad source-boundary and signed-slot history synchronized; generated deferred. |
| `by-resource/str-res-localized-strings.md` | `000000009943` | `2026-07-13T13:12:39-04:00` | `0 / 1` | Resource id/text/consumer/provenance reference added; two pre-existing missing UID0003O5 warnings; generated deferred. |
| `by-type/by-vtable/AddItemWithCountDialogVtables.md` | `000000009945` | `2026-07-13T13:13:41-04:00` | `0 / 1` | Slot links/names and compiler no-code prose synchronized; generated deferred. |
| `by-type/by-vtable/ItemDialogVtableFamily.md` | `000000009951` | `2026-07-13T13:16:26-04:00` | `0 / 1` | Added UID0004BR/UID0004BS references and exact slot prose; seven pre-existing missing UID0003IG/UID0003IH warnings; generated deferred. |

Final authorized waited refresh: `python .\tools\validator.py --mode file --file by-file\ItemDialogs.md --apply --wait-generated --queue-timeout 240`, command `000000009954`, timestamp `2026-07-13T13:16:52-04:00`, exit `0`, `ok:1`, `generated_refresh: completed`. It rebuilt the validator-owned autogen registry/metadata and coverage outputs, reported five pre-existing missing UID0003IG references on ItemDialogs, and produced both relevant generated headers at command/timestamp equality. A later validator-owned external refresh advanced both headers to `000000009979` / `2026-07-13T13:25:20-04:00`; this does not alter B003's waited command proof.

Latest read-only generated proof for `auto-generated/NexusTK/ui/dialogs/ItemDialogs.cpp` and `ExchangeDialog.cpp`: both headers were observed at external command `000000009979`, refreshed `2026-07-13T13:25:20-04:00`, which is newer than B003's waited command. UID000008's class closes at line 203 before namespace-scope children. UID0004BQ R1, UID0004BR R3, UID0004BS R4, and UID000318 R5 each emit once at their current paths; there are zero `AddItemWithCountDialog::OnAction` and zero `AddItemWithCountDialog::OnClosePacket` definitions, zero UID0004BQ/UID000008 Empty Emitter Markers, and zero manual `0x00619fec/0x0061a04c/0x0061a07c` vtable assignments. UID00033T and compiler-vtable pages retain intentional blank-formal markers. ExchangeDialog emits the signed `const char inventorySlot = static_cast<char>(PacketReadByte(packet + 2)); new AddItemWithCountDialog(m_exchangeSessionId, inventorySlot);` R6 sequence exactly once.

## Changed Files

- Modified and scoped-validated: `by-memory/0x004af040-0x004af371.AddItemWithCountDialogConstructor.md`, `by-class/AddItemWithCountDialog.md`, `by-memory/0x004af040-0x004af4b7.AddItemWithCountDialogCore.md`, `by-memory/0x004af4f0-0x004af570.AddItemWithCountDialogSubmitPacketHelper.md`, `by-memory/0x004ad320-0x004ad7b3.ExchangeDialogPacketDispatcher.md`, `by-memory/0x004ada90-0x004adb02.ExchangeDialogAddItemWithCountHelper.md`, `by-class/ExchangeDialog.md`, `by-file/ExchangeDialog.md`, `by-memory/0x004ac8a0-0x004ae4b6.ExchangeDialog.md`, `by-file/ItemDialogs.md`, `by-memory/0x004ae4c0-0x004b0ba5.ItemExchangeMixDialogs.md`, `by-resource/str-res-localized-strings.md`, `by-type/by-vtable/AddItemWithCountDialogVtables.md`, and `by-type/by-vtable/ItemDialogVtableFamily.md`.
- Validator-preservingly renamed/modified/validated: historical `by-memory/0x004af380-0x004af47a.AddItemWithCountDialogOnAction.md` -> current `by-memory/0x004af380-0x004af47a.AddItemWithCountDialogOnControlCommand.md` (UID0004BR); historical `by-memory/0x004af4c0-0x004af4f0.AddItemWithCountDialogExchangePacketCloseHandler.md` -> current `by-memory/0x004af4c0-0x004af4f0.AddItemWithCountDialogHandlePacketEvent.md` (UID000318).
- Historical B003 research/implementation-callback artifact path before any external supervisor lifecycle: `tools/leaser/Agents/Agent-B003/research/0004BQ-AddItemWithCountDialogConstructor-source-quality.md`; this is the artifact updated by B003 in this callback.
- Read-only/verify-only: B002-owned UID0004BS (exact R4 equality), B005-owned ImageButtonControlPane/ControlPane Enable/Disable and other controls, DialogPane/EventHandler/TextEdit/accessor/quantity-format APIs, executed B001 UID0004BN report/page, and generated ItemDialogs/ExchangeDialog C++.
- Forbidden/manual-edit set remained untouched: generated/coverage/tracker/supervisor/audit/validator registry/queue/lock/lifecycle/archive files, UID0004BS, B005 control pages, and other agents' reports.
- Every B003 edit lease was one-file and released immediately after its scoped validator; the final lease report contained no B003 row. B003 performed no report execute/lifecycle/move/archive command. External report validation/execution/count/path/archive state is neither asserted nor directed by this artifact.

## Implementation Tracking Checklist

Initial report-only pass:
- [x] Supervisor validation completed before implementation: exact pre-callback report SHA `2C8EE75748470595074F839A761AF4FE20EF436192C1D56861FC4C7AB044048C` passed Gate 1.
- [x] Target/support destinations were the exact paths listed under Recommended Target Doc Changes and Recommended Support Doc Changes; all B003-owned destinations are listed under Changed Files.
- [x] Target state and evidence remain recorded: historical metadata/generated state, mandatory MCP evidence, repeated report searches, B001 command `000000009874` classification, callback-time B002/B005 boundaries, and every direct contradiction are preserved.
- [x] Claim And Incorporation Ledger C01-C20 now uses only legal action and callback verification enums and includes destination/validator/generated implementation proof.
- [x] Metadata/scores implemented: target `92/94`, class/parent `91/93`, UID0004BR/UID000318 `92/94`, positions `10/20/40`; B002-owned UID0004BS independently stands at `92/94`/position `30`; every other listed score/route is unchanged.
- [x] Score-limiting blockers were researched and preserved: only stripped lexical/access spellings and retained-helper integration cap the accepted scores.
- [x] Owner/emitter/reconstructable state is preserved exactly; UID000008/UID0000KE routes and UID00033T blank-formal policy remain unchanged.
- [x] No split/new child was made; validator-preserving UID0004BR/UID000318 renames completed with exact ranges/UIDs/owner/emitter/reconstructable/Nested/padding preserved.
- [x] Source placement/order and range/split/padding/reclassification evidence were applied; no IDA mutation occurred.
- [x] B003-owned R1/R2/R3/R5/R6 were applied exactly; read-only UID0004BS comparison proves exact R4 equality; UID00033T/vtable blank formal dispositions are preserved.
- [x] Third-party import directive is not applicable because this is NexusTK project code, not a third-party embed.
- [x] All C01-C20 target/support facts, tables, negatives, history, scores, and source rationale were incorporated at report-level detail.
- [x] B007 shallow body, item/type naming, false base/helper/updater calls, compiler exclusions, no-route helper, and rejected owners remain explicit history/negative evidence.
- [x] Wave2/Wave3 artifacts encountered in history remain explicitly rejected as current evidence.
- [x] Lexical/access/retained-helper/resource-variant questions retain evidence-backed resolution or bounded uncertainty and score impact.
- [x] Every actually B003-changed ordinary by-* page passed its scoped validator; UID0004BS/B005 pages were not leased, edited, or validated by B003.
- [x] Waited command `000000009954` completed generated refresh; no generated/coverage/tracker file was manually edited.

Implementation callback pass:
- [x] Supervisor authorized implementation against exact Gate-1-passed SHA `2C8EE75748470595074F839A761AF4FE20EF436192C1D56861FC4C7AB044048C`.
- [x] B002/B005 reports, ownership, shared pages, and leases were re-read before edits; executed B001 UID0004BN remained read-only at its executed path.
- [x] Every accepted B003-owned target/support detail is incorporated at report-level depth without dropping behavior, layout, call flow, negatives, source placement, history, or score rationale.
- [x] C01-C20 ledger rows are final and contain exact destinations plus validator/generated proof.
- [x] Metadata/score/owner/emitter/split/rename/C++ changes were applied exactly or excluded with the documented ownership/no-code reason.
- [x] Historical/stale assumptions, rejected alternatives, and negative evidence are preserved in target/support prose and this report.
- [x] Open questions retain evidence-backed closure or bounded confidence-cap rationale; no source/code blocker remains.
- [x] Sixteen scoped validators and final waited command `000000009954` are recorded with command IDs, timestamps, exit/ok, side effects/warnings, and lease-release state.
- [x] Generated verification passed: ItemDialogs.cpp has R2 closed before R1/R3/R4/R5 namespace-scope definitions, each definition once at its current path, no AddItemWithCount old callback definitions, no UID0004BQ/UID000008 Empty Emitter Marker, and no manual vtable assignments; ExchangeDialog.cpp has corrected R6 once. B003's waited headers equaled command `000000009954`/`2026-07-13T13:16:52-04:00`; latest read-only headers were newer external command `000000009979`/`2026-07-13T13:25:20-04:00` with the same proof.
- [x] No B003-owned accepted item remains unapplied. UID0004BS/R4 and B005 control pages are satisfied as verify-only ownership exclusions, and no B003 lease remains.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B003","command_id":"000000009998","destination_path":"executed-b-agent-research/B003/0004BQ-AddItemWithCountDialogConstructor-source-quality.md","details":"report executed into central archive","event":"executed","source_path":"tools/leaser/Agents/Agent-B003/research/0004BQ-AddItemWithCountDialogConstructor-source-quality.md","timestamp":"2026-07-13T13:37:33-04:00","uid":"0004BQ"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
