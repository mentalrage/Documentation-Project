** TARGET-REPORT-UID:00014L **
** AUTHOR-AGENT-ID:B015 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# 00014L ExchangeDialogPacketDispatcher Source-Quality Research

## Finalized Report / Current Recommendation

- Current recommendation: keep [UID:00014L] `by-memory/0x004ad320-0x004ad7b3.ExchangeDialogPacketDispatcher.md` assigned to [UID:00004R] `ExchangeDialog`, keep `RECONSTRUCTABLE:TRUE`, keep `EMITTER_UIDS:00004R`, and update the page from `84/90` to `89/91`.
- Final disposition: this is the live vtable-routed server exchange packet dispatcher for opcode `0x42`. The dispatcher itself should emit first-draft C++ now, with the five subcommand bodies inlined in the switch. The sibling retained/projected helpers [UID:00014M], [UID:00014N], [UID:00014O], and [UID:00014P] should remain blank until the broader retained-clone policy decides how to preserve no-route duplicate bodies.
- Required action: replace stale "below 95/95 gate" wording with the active combined-score/emitter rule, record the direct PE/Capstone recheck, add the inline-dispatcher source-shape decision, update the coverage row text below, and populate the target's formal `RECONSTRUCTION_CPP CODE` with the first-draft dispatcher body in this report.
- Confidence: high for range, switch table, vtable-only reachability, opcode/subcommand behavior, packet field meanings, primary/secondary `this` reconciliation, and inline-dispatcher source shape. Remaining uncertainty is limited to final original field/helper names and exact declaration spelling for dependent UI/ListPane helpers.

## Supporting Research

## Target

- Target UID: `00014L`.
- Target path: `E:\NTK\GhidraBridge\source-3\project-documentation\by-memory\0x004ad320-0x004ad7b3.ExchangeDialogPacketDispatcher.md`.
- Source queue/report row: current Agent-B015 supervisor assignment `[UID:00014L] ExchangeDialogPacketDispatcher source-quality`.
- Current supervisor classification: B-preferred heuristic/source-quality task for opcode/subcommand naming, packet fields, duplicate helpers, source-shape, switch-table boundary, support rows, scores, and first-draft C++ readiness.
- Current scores and parent state: target `84/90`, `CANONICAL_OWNER:00004R`, `EMITTER_UIDS:00004R`; direct class parent [UID:00004R] is now `86/88`; file route [UID:0000J9] is `88/86` with proposed path `NexusTK/ui/dialogs/`.

## Executive Recommendation

- Best direct owner remains [UID:00004R] `ExchangeDialog`. The dispatcher reads ExchangeDialog state, handles the exchange server opcode, updates exchange controls/ready flags, constructs `ExchangeAlertPane`, and owns the live source behavior currently duplicated by helper bodies.
- Best source route remains [UID:00004R] -> [UID:0000J9] `ExchangeDialog` -> `auto-generated/NexusTK/ui/dialogs/ExchangeDialog.cpp`.
- Do not split or rename [UID:00014L]. Its code body is exact half-open `0x004ad320-0x004ad7b3`; the following NOP/switch-table/data island is boundary evidence, not part of the function range.
- Formal C++ is ready for [UID:00014L] under the current rule because the target is reconstructable, has a valid emitter route, has average score above 85, and the source-shape blocker has a defensible resolution: the dispatcher should express the live switch inline.
- Do not solve the retained-helper pages by making the dispatcher call [UID:00014M]/[UID:00014O]/[UID:00014P]. Direct PE scans and prior IDA checks find no route to those helper starts, while the dispatcher contains their behavior inline.

## Supervisor Active Recheck

- The supervisor assigned only `00014L`; no split repair was required.
- The target is a single IDA-modeled function. The only adjacent non-code data in scope is the compiler-generated switch table immediately after the function body.
- Source-bearing duplicate/helper questions in scope are resolved for the dispatcher: emit this dispatcher inline; keep no-route duplicate helper pages blank until a later binary-retention pass decides whether to emit retained clones separately.

## Inference Research Guidance Check

- `by-structure.md` requires the narrowest true owner and separates semantic ownership from emitter routing. That supports `CANONICAL_OWNER:00004R` and `EMITTER_UIDS:00004R`, not direct file ownership.
- The active reconstruction-code gate is `(COMPLETION + CONFIDENCE) / 2 > 85` with a valid emitter route. The current target already clears the numeric gate; this pass resolves the source-shape issue sufficiently to recommend first-draft code.
- Existing docs were treated as leads. Prior [UID:00014M]/[UID:00014O]/[UID:00014P] B reports are accepted for duplicate-helper facts, but this report rechecked the dispatcher bytes directly because IDA MCP was unavailable in-session.
- Fact/inference split: direct PE/Capstone facts prove instructions, targets, table bytes, pointer hits, and helper no-route scans; existing docs provide earlier IDA MCP decompile/xref facts; names such as `m_exchangeSessionId`, `selectedItemType`, and `HandleExchangePacket` remain inferred/descriptive.

## Heuristic / Inference Reanalysis And Validation

- Opcode and subcommand naming:
  - Best inference: opcode `0x42` is the server-side exchange dialog packet opcode; subcommands `1..5` are `OpenAddItemWithCount`, `UpdateOfferItemRow`, `UpdateMoneyAmount`, `ShowCancelAlert`, and `HandleReadyStateOrAlert`.
  - Evidence checked: direct disassembly compares `packet[0]` to `0x42`; `packet[1] - 1` indexes a five-entry switch table; prior docs connect these packet flows to ExchangeDialog send opcode `0x4A`.
  - Rejected alternatives: RankingDialog reward packets, generic DialogPane event routing, or ItemDialogs ownership. No ranking fields appear, and the dispatcher uses ExchangeDialog state/control ids.
  - Final direction: use descriptive exchange-packet names, not generic `sub_4AD320` or `OnExchangePacket` pollution.

- Subcommand `1` packet fields and helper relationship:
  - Best inference: `packet+2` is a selected item/type token for `AddItemWithCountDialog`; the source-facing case name is `OpenAddItemWithCountDialog`.
  - Evidence checked: direct bytes at `0x004ad380-0x004ad3c6` read `packet+2`, allocate `0x274` / 628 bytes (Verified with int_convert.py), and call `0x004af040`. [UID:00014M] has the same body but no route.
  - `this+0x1cc` in the dispatcher is the secondary-facet view of primary `ExchangeDialog::m_exchangeSessionId` at `this+0x26c`; `0xa0 + 0x1cc = 0x26c` (all offsets Verified with int_convert.py).
  - Rejected alternatives: count byte, opcode byte, item-dialog owner, or direct call to the retained helper. Count is entered later by `AddItemWithCountDialog`; direct PE scans found no branch/pointer route to `0x004ada90`.
  - Final direction: inline this case in dispatcher C++; do not call [UID:00014M].

- Subcommand `2` row/list packet fields:
  - Best inference: `packet+2` is side/list selector, `packet+3` is offer-row key, `packet+4` is item id word, `packet+6` is color/style byte, `packet+7` is item-name byte length, and `packet+8` is counted CP_ACP name bytes.
  - Evidence checked: direct disassembly reads those offsets in order, converts a counted narrow string with `MultiByteToWideChar`, selects control `5` when side is zero and control `8` otherwise, scans `ExchangeItemListPane` row keys, removes an existing row, and inserts a record with key at `+0`, item id at `+2`, color at `+4`, and wide name at `+6`.
  - Rejected alternatives: null-terminated packet string, UTF-16 packet name, or opaque list blob. The counted copy and row layout are instruction-backed and corroborated by [UID:00004S], [UID:00014R], and [UID:00014S].
  - Final direction: source should inline the row-scan/remove/insert logic using ListPane-style operations, not call raw no-route `ExchangeItemListPaneRawUpsertHelper`.

- Subcommand `3` money packet fields:
  - Best inference: `packet+2` selects local versus remote side; `packet+3` is the amount dword read by the packet dword helper. Side zero targets local control `6`, side nonzero targets remote control `9`.
  - Evidence checked: direct case at `0x004ad527-0x004ad59e`; local zero amount calls `0x004ada20` / `ExchangeDialog::SetExchangeAmount(0)`, then formats `%u` from UTF-16 string `0x006191b0` into a 32-WCHAR stack buffer (`0x20` / 32 Verified with int_convert.py) and writes the text via `0x00498ca0`.
  - Rejected alternatives: direct ownership by [UID:00014N] raw helper or a separate money-control owner. [UID:00014N] is a no-function/no-xref raw duplicate; this live case owns the dispatcher behavior.
  - Final direction: name the case `UpdateExchangeMoneyFromPacket` or `HandleMoneyUpdate`, with inline control selection.

- Subcommand `4` cancel/termination alert:
  - Best inference: `packet+3` is byte length and `packet+4` is counted CP_ACP message bytes. The case closes any active exchange alert, constructs a new `ExchangeAlertPane`, runs DialogPane slide close `0x0049eb90`, closes/removes this ExchangeDialog through `0x0049dad0`, and closes active `g_pAddItemDialog` at `0x0069b328` if present.
  - Evidence checked: direct case at `0x004ad5a3-0x004ad681`, prior [UID:00014O] IDA MCP report, `g_pExchangeAlertPane` xrefs, and `OK` text at `0x00613a18`.
  - Rejected alternatives: moving the case to `ExchangeAlertPane` or `ItemDialogs`; alert/add-item objects are dependencies/cleanup targets, not the packet dispatcher owner.
  - Final direction: inline in dispatcher C++; do not call [UID:00014O].

- Subcommand `5` ready/confirm state:
  - Best inference: `packet+2` is ready-side/status. Nonzero marks `m_peerReadyConfirmed`; zero clears local request and sets local confirmed by writing the `+0x270` word to `0x0100`. Only when both sides are ready does it decode `packet+3/+4` message bytes, replace the active alert via `0x004b0b20`, construct a new `ExchangeAlertPane`, slide-close, and close/remove the dialog.
  - Evidence checked: direct case at `0x004ad686-0x004ad791`, prior [UID:00014P] report, [UID:00004R] ready-state field notes, and DialogPane aggregate [UID:00012R] describing `0x0049fe20` as selected-control repaint helper.
  - Rejected alternatives: RankingDialog reward state, single opaque word with no byte semantics, or direct private helper call. Generated RankingDialog ownership is contradicted by field/global usage; helper start `0x004ade60` has no route.
  - Final direction: source can use descriptive fields `m_localOfferPending`, `m_localReadyConfirmed`, and `m_peerReadyConfirmed`, with the caveat that original member names are not proven.

- Secondary-facet `this+0x1cc` versus primary `this+0x26c`:
  - Best inference: same exchange session id field reached through a secondary vtable view installed at object offset `+0xa0`.
  - Evidence checked: dispatcher preserves `ecx` as secondary view, case 3/4/5 explicitly compute primary `this` as `ebx - 0xa0`, case 1 accesses `[ebx+0x1cc]`, and [UID:0003NE] documents ExchangeDialog primary/secondary vtable views.
  - Rejected alternatives: two different exchange ids or packet-local data. Offset arithmetic and packet send/constructor use converge on one field.
  - Final direction: target page should keep the explanation and use primary-field names in C++.

- Duplicate helper bodies [UID:00014M]/[UID:00014P] and raw/projected helpers [UID:00014N]/[UID:00014R]:
  - Best inference: these are retained/projected duplicate helper bodies or recovery artifacts for source logic that the live dispatcher contains inline.
  - Evidence checked: direct PE scans found no rel32 branch targets, full-file VA dwords, RVA dwords, or end-pointer dwords for `0x004ada90`, `0x004adca0`, `0x004add40`, or `0x004ade60`; prior reports found no IDA xrefs; dispatcher cases contain the matching behavior.
  - Rejected alternatives: route the dispatcher source through private helper calls now, or classify helper pages as padding/compiler-only. The bodies are real source behavior, but not currently reachable as calls.
  - Final direction: dispatcher C++ should inline cases; retained helper pages remain reconstructable but blank formal C++ until clone-retention is handled deliberately.

- List-row/money/alert helper names:
  - Best descriptive names: `ExchangeItemListRow`, `FindOfferRowByKey`, `InsertOfferRow`, `RemoveRows`, `SetExchangeAmount`, `SetControlText`, `CloseActiveExchangeAlertPane`, `SlideClose`, and `CloseDialogPane`.
  - Evidence checked: [UID:00004S], [UID:00014R], [UID:00014S], DialogPane aggregate, and direct call targets.
  - Rejected alternatives: raw address names in source-facing prose. Keep raw addresses as evidence only.
  - Final direction: use descriptive names in first-draft code with a note that final declarations may choose project-native spellings.

- Switch-table boundary:
  - Best inference: function body ends half-open at `0x004ad7b3`; `0x004ad7b3` is a NOP/alignment byte; `0x004ad7b4-0x004ad7c8` is the five-entry compiler switch table; `0x004ad7c8-0x004ad7d0` is `0xcc` padding before `OnKeyEvent`.
  - Evidence checked: direct bytes `90 80 d3 4a 00 cb d3 4a 00 27 d5 4a 00 a3 d5 4a 00 86 d6 4a 00 cc...`; dwords point to `0x004ad380`, `0x004ad3cb`, `0x004ad527`, `0x004ad5a3`, and `0x004ad686`.
  - Rejected alternatives: extend the method page through `0x004ad7c8` or split each table dword as source-authored data. The table is compiler-generated support for this switch.
  - Final direction: do not rename/extend the target; optionally add an ignored/support row for `0x004ad7b3-0x004ad7d0` if memory coverage later requires exact non-code accounting.

- Generated-output pollution and C++ readiness:
  - Existing generated `auto-generated/NexusTK/ui/dialogs/ExchangeDialog.cpp` contains only empty emitter markers for this family; it omits source bodies despite valid routes.
  - The target's old C++ blocker is stale. Under the current rule, [UID:00014L] is eligible and source-shape is now resolved enough for first-draft code. The duplicate helper pages remain no-code, but they do not block the live dispatcher C++.

## Evidence Standards Used

- Direct executable evidence: `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`, MD5 `4247e04e20b65d6414c7238aa8ff5515`, SHA256 `9aec210bbc5ce592176a21dd8e9d9fd8f250b8d9ea78237915a99ba8cfa9a632`, image base `0x00400000`, `.text` `0x00401000-0x0060c4ac`.
- Tool evidence from this session: Capstone `5.0.7` disassembly, direct PE section parsing, rel32 and pointer scans, and `tools/int_convert.py` conversions.
- Documentation evidence: target page [UID:00014L], class/file pages [UID:00004R]/[UID:0000J9], aggregate [UID:00014K], duplicate helpers [UID:00014M]/[UID:00014N]/[UID:00014O]/[UID:00014P], list pane docs [UID:00004S]/[UID:00014R]/[UID:00014S], tail/global docs [UID:00014V]/[UID:0000QV], vtable [UID:0003NE], DialogPane aggregate [UID:00012R], proposed source tree, generated coverage/source, and executed B002/B003 reports.
- IDA MCP limitation: direct MCP endpoint `http://127.0.0.1:13337/mcp` was unavailable in this session (`Unable to connect to the remote server`). Existing IDA MCP-backed docs were used as prior evidence and validated where possible with raw executable checks.

## IDA / Raw PE Facts

- Function/range facts:
  - Direct bytes disassemble to `332` instructions from `0x004ad320` through `ret 4` at `0x004ad7b0-0x004ad7b2`.
  - Body size is `0x493` / 1171 bytes (Verified with int_convert.py), matching the documented half-open range `0x004ad320-0x004ad7b3`.
  - Prologue reads `event+0x0c` into the packet pointer and rejects `packet[0] != 0x42`.
  - `packet[1] - 1` is bounds-checked against `4`; out-of-range opcode `0x42` subcommands return true through `0x004ad6bf`.
- Data/table/padding facts:
  - `0x004ad7b3` byte is `0x90`.
  - Switch table dwords at `0x004ad7b4` are `0x004ad380`, `0x004ad3cb`, `0x004ad527`, `0x004ad5a3`, and `0x004ad686`.
  - `0x004ad7c8-0x004ad7d0` is eight `0xcc` bytes before `0x004ad7d0`.
- Xref facts:
  - Full-file dword scan found the sole `0x004ad320` pointer at file offset `0x21879c`, which maps to vtable slot `0x00619d9c`.
  - No rel32 branch target to `0x004ad320` was found, matching vtable/callback reachability.
  - No rel32 or full-file VA/RVA pointer route was found for duplicate helper starts `0x004ada90`, `0x004adca0`, `0x004add40`, or `0x004ade60`.
  - `0x004af040` constructor calls appear only at dispatcher `0x004ad3bf` and helper `0x004adaeb`.
  - `0x004b0490` alert constructor calls appear at dispatcher `0x004ad656`/`0x004ad775` and helper `0x004ade18`/`0x004adf8d`.
  - `0x004b0b20` active-alert close helper calls appear at dispatcher `0x004ad741` and helper `0x004adf59`.
- Vtable/global/type facts:
  - [UID:0003NE] documents the `ExchangeDialog` secondary vtable view containing the dispatcher slot.
  - Direct bytes use `0x0069b330` as the active exchange alert slot and `0x0069b328` as the active add-item dialog cleanup slot.
  - UTF-16 `%u` at `0x006191b0` and UTF-16 `OK` at `0x00613a18` are confirmed by raw bytes.
- Negative facts:
  - No direct code/data route proves that the dispatcher should call [UID:00014M], [UID:00014O], or [UID:00014P].
  - No evidence supports RankingDialog or ItemDialogs as the dispatcher's direct owner.

## Function / Child Inventory

| Range / Item | UID / Path | Role | Reconstructable | Direct Parent | Score | Status |
| --- | --- | --- | --- | --- | --- | --- |
| `0x004ad320-0x004ad7b3` | `00014L` target | Live virtual exchange packet dispatcher | True | `00004R` | current `84/90`, recommend `89/91` | first-draft C++ ready |
| `0x004ad7b3-0x004ad7c8` | no exact page | NOP plus five-entry switch table | False/source-generated support | none | n/a | document as boundary/support, no range extension |
| `0x004ad7c8-0x004ad7d0` | no exact page | `0xcc` padding | False | none | n/a | boundary before `OnKeyEvent` |
| `0x004ada90-0x004adb02` | `00014M` | Retained add-count duplicate helper | True | `00004R` | `86/90` | keep formal C++ blank |
| `0x004adca0-0x004add33` | `00014N` | Raw money-update duplicate | True | `0000J9` | `85/88` | keep formal C++ blank |
| `0x004add40-0x004ade5e` | `00014O` | Retained cancel-alert duplicate helper | True | `00004R` | `86/89` | keep formal C++ blank |
| `0x004ade60-0x004adfab` | `00014P` | Retained ready-alert duplicate helper | True | `00004R` | `86/89` | keep formal C++ blank |

## Direct Xref / Caller Inventory

| Address / Item | Xref / Caller / Callee | Meaning |
| --- | --- | --- |
| `0x00619d9c -> 0x004ad320` | vtable data pointer | Dispatcher is reached virtually through `ExchangeDialog` secondary view. |
| `0x004ad3bf -> 0x004af040` | call | Live add-count dialog construction in subcommand `1`. |
| `0x004ad597 -> 0x00498ca0` | call | Money text write after `%u` formatting. |
| `0x004ad656`, `0x004ad775` -> `0x004b0490` | calls | Alert construction in cancel and ready cases. |
| `0x004ad664`, `0x004ad783` -> `0x0049eb90` | calls | DialogPane slide/animation close before close/remove. |
| `0x004ad66b`, `0x004ad67a`, `0x004ad78a` -> `0x0049dad0` | calls | Close/remove ExchangeDialog and active AddItemDialog. |
| `0x004ad6ba -> 0x0049fe20` | call | DialogPane selected-control refresh wrapper in ready case. |
| `0x004ad741 -> 0x004b0b20` | call | Close active exchange alert in ready-alert case. |

## Documentation Evidence And IDA Status

- Existing docs that support the conclusion:
  - [UID:00014L] already documents the vtable-only dispatcher, opcode guard, five subcommands, return policy, and major callees.
  - [UID:00004R] and [UID:0000J9] now clear the active 85/85 gate and route ExchangeDialog through `ui/dialogs/ExchangeDialog.cpp`.
  - [UID:00014M], [UID:00014O], and [UID:00014P] executed B reports validate the retained-helper/no-direct-xref pattern and identify helper-specific packet fields.
  - [UID:00004S], [UID:00014R], and [UID:00014S] validate the exchange item-list row layout used inline by dispatcher case `2`.
  - [UID:00012R] validates `0x0049fe20` as the selected-control repaint helper.
- Existing docs that are stale or incomplete:
  - [UID:00014L] still says final C++ is blank because of a `95/95` threshold. That policy is superseded.
  - [UID:00014L] should add direct source-shape resolution: dispatcher cases should be inline, while retained helpers remain blank.
  - [UID:00014L] subcommand `2` row should record exact offsets `packet+2/+3/+4/+6/+7/+8`.
  - [UID:00014L] should explicitly mention the switch table dword targets and the NOP/table/padding boundary.
  - `auto-generated/NexusTK/ui/dialogs/ExchangeDialog.cpp` currently has only empty emitter markers for [UID:00014L] and sibling pages.
- Generated/coverage state:
  - `auto-generated/-ag-memory-coverage.md` reports [UID:00014L] as emitting through `00004R` to `auto-generated/NexusTK/ui/dialogs/ExchangeDialog.cpp`, but the emitted source body is empty.
  - `by-memory/-coverage-report.md` row for [UID:00014L] should be replaced if the supervisor accepts the score/C++ update.

## Ranked Ownership Analysis

### 1. [UID:00004R] ExchangeDialog

- Evidence for: owns the exchange session fields, packet semantics, controls `5/6/8/9`, ready-state bytes, alert creation, active alert singleton use, and existing vtable slot at `0x00619d9c`.
- Evidence against: the function receives a secondary-base `this` pointer rather than an obvious primary pointer, but this is explained by the `+0xa0` vtable view and does not weaken class ownership.
- Decision: accepted as direct canonical owner.

### 2. [UID:0000J9] ExchangeDialog file

- Evidence for: established `ui/dialogs/ExchangeDialog.cpp` source route for `ExchangeDialog`, private exchange controls, exchange alert, and singleton state.
- Evidence against: by-structure requires the narrow class owner for class methods; the file UID is the emitter root, not direct semantic owner.
- Decision: accepted as source route through [UID:00004R].

### 3. [UID:00004S] ExchangeItemListPane / [UID:00004Q] ExchangeAlertPane / ItemDialogs

- Evidence for: dispatcher constructs or mutates list, alert, and item-picker objects.
- Evidence against: those are dependencies and child controls. The dispatcher decides exchange packet behavior and uses ExchangeDialog state.
- Decision: rejected as direct dispatcher owner; retained as dependent type/source evidence.

### 4. NONE / Non-emitting / Runtime

- Evidence for: no ordinary direct callers exist.
- Evidence against: vtable pointer exists, body is source-authored UI packet logic, owner/emitter route is valid, and generated output is simply empty because the C++ block is blank.
- Decision: rejected. The dispatcher is reconstructable, owned, and ready for first-draft code.

### Proposed new file/grouping, if applicable

- Proposed owner/name/path: no new file. Use existing [UID:0000J9] `NexusTK/ui/dialogs/ExchangeDialog.cpp`.
- Likely full contents: `ExchangeDialog`, `ExchangeItemListPane`, `ExchangeAlertPane`, `ExchangeMoneyEditControlPane`, `g_pExchangeAlertPane`, exchange resource/vtable children, and the exact exchange-owned memory children listed in [UID:0000J9].
- Candidate related items that belong: `00014K`, `00014L`, `00014M`, `00014N`, `00014O`, `00014P`, `00004R`, `00004S`, `00004T`, `00004Q`, `0000QV`, `0002VZ`, exchange vtable/resource children.
- Candidate related items rejected: `AddItemDialog`, `AddItemWithCountDialog`, `MixItemDialog`, `MyItemListPane`, `FunctionObjects`, and generic DialogPane/ListPane infrastructure remain separate owners/dependencies.
- Standalone, narrow, or broad source-file inference: broad existing feature file, not standalone.

## Negative Evidence Summary

- No direct rel32 or pointer route to retained helper starts supports rewriting the dispatcher as helper calls.
- No RankingDialog field, vtable, singleton, or caller context appears in this dispatcher.
- Add-item and alert object construction are callee/dependency evidence, not ownership transfer.
- The switch table is compiler-generated support and should not extend the source body range.
- Current generated source omission is not negative evidence against reconstructability; it is generated-output incompleteness.

## First-Draft C++ Recommendation

Populate [UID:00014L]'s formal `RECONSTRUCTION_CPP CODE` block with this first-draft source after applying the documentation update. This is the live dispatcher body and should use inline cases. Names are descriptive where original names remain unrecovered.

```cpp
bool ExchangeDialog::DispatchExchangePacket(Event *event)
{
    const unsigned char *packet = event->packet;
    if (packet[0] != 0x42) {
        return false;
    }

    switch (packet[1]) {
    case 1: {
        const unsigned char selectedItemType = PacketReadByte(packet + 2);
        new AddItemWithCountDialog(m_exchangeSessionId, selectedItemType);
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
```

Draft caveats:

- `Event::packet`, `PacketReadByte`, `PacketReadUInt16BE`, `PacketReadUInt32BE`, `ExchangeItemListRow`, `GetControl`, `SetText`, `SlideClose`, `CloseDialogPane`, `CloseActiveExchangeAlertPane`, `RefreshSelectedControlAfterStateUpdate`, `g_szDialogOk`, `m_exchangeSessionId`, `m_localOfferPending`, `m_localReadyConfirmed`, and `m_peerReadyConfirmed` are descriptive source-facing names.
- The row struct should match the documented binary layout: key byte `+0`, item id word `+2`, color byte `+4`, wide name `+6`, total row size `0x206`.
- The final project may replace literal allocation/string helper spellings with real class constructors and utility APIs, but it should keep the dispatcher cases inline unless a later binary-equivalence pass proves a safe retained-helper source pattern.

## Final Recommendation

- Exact changes recommended for [UID:00014L]:
  - `COMPLETION:84 -> 89`
  - `CONFIDENCE:90 -> 91`
  - keep `CANONICAL_OWNER:00004R`
  - keep `RECONSTRUCTABLE:TRUE`
  - keep `EMITTER_UIDS:00004R`
  - populate formal C++ with the inline switch draft above
- Exact parent assignments recommended: no change. Current parent/emitter route is gate-compliant.
- Exact items left no-owner/non-emitting and why: none for this target. The sibling retained helper pages stay owned/emitting-route metadata-wise but blank formal C++ because they have no proven live route and duplicate this dispatcher.
- Exact future work outside this assignment: later `ExchangeDialog.cpp` integration should decide whether retained no-route clone pages need emitted standalone bodies to recreate binary bytes, but that should not block [UID:00014L].

## Coverage / Support Replacement Text

Do not edit `by-memory/-coverage-report.md` directly. If accepted, replace the current [UID:00014L] row in address order after [UID:00014K] and before [UID:00014M] with:

```text
    - [UID:00014L][0x004ad320-0x004ad7b3.ExchangeDialogPacketDispatcher](by-memory/0x004ad320-0x004ad7b3.ExchangeDialogPacketDispatcher.md) 0x004ad320-0x004ad7b3 | method | ExchangeDialogPacketDispatcher : reconstructable : 89% : very-strong : B015 2026-06-19 source-quality reanalysis confirms the live vtable-only ExchangeDialog server packet dispatcher for opcode `0x42`, exact `0x493` / 1171-byte body (Verified with int_convert.py), invalid-opcode false return, opcode-`0x42` default true return, five-entry switch table at `0x004ad7b4-0x004ad7c8`, vtable pointer `0x00619d9c`, subcommand `1` selected item/type byte and secondary-facet `this+0x1cc` to primary `this+0x26c` exchange-id reconciliation, subcommand `2` offer-row fields `packet+2/+3/+4/+6/+7/+8`, subcommand `3` money amount/control update, subcommand `4` cancel-alert/AddItemDialog cleanup, subcommand `5` ready-state/alert flow, no direct PE route to duplicate helper starts `0x004ada90`, `0x004adca0`, `0x004add40`, or `0x004ade60`, and first-draft C++ readiness with dispatcher cases kept inline while retained duplicate helper pages stay blank.
```

Related pre-existing stale support row observed while reviewing this target: [UID:00014K] coverage still says `78%` while the page metadata is `85/88`. If the supervisor touches the same coverage block, replace [UID:00014K]'s row with:

```text
    - [UID:00014K][0x004ac8a0-0x004ae4b6.ExchangeDialog](by-memory/0x004ac8a0-0x004ae4b6.ExchangeDialog.md) 0x004ac8a0-0x004ae4b6 | class-aggregate | ExchangeDialog : reconstructable : 85% : strong : Exchange dialog and private list-pane cluster with IDA-confirmed method starts, raw helper caveats, exact dispatcher/add-count/money/cancel/ready/list child pages, vtable/resource/global xrefs, source-shape notes for retained duplicate helper bodies, and padding/successor boundaries documented.
```

## Follow-Up Actions

- Supervisor actions:
  - Apply the [UID:00014L] target-page score/body/C++ update if accepted.
  - Apply the exact [UID:00014L] coverage replacement row above; optionally fix the stale [UID:00014K] support row.
  - Run targeted validation for the edited target/support docs and autogen after applying C++.
- A-agent actions:
  - When migrating `ExchangeDialog.cpp`, keep [UID:00014L] as the inline dispatcher and avoid importing the stale RankingDialog-generated helper bodies.
  - Keep [UID:00014M]/[UID:00014N]/[UID:00014O]/[UID:00014P] blank unless a later retained-clone policy explicitly emits no-route duplicates.
- B015 future research actions:
  - None required for this target unless the supervisor asks for the broader retained-clone emission policy for the ExchangeDialog helper family.

## Confidence

- Recommendation confidence: high.
- Score confidence: `89/91` is justified by direct byte evidence plus prior MCP-backed documentation. It stays below final-audit quality because IDA MCP was unavailable in this session and some final source declarations/field spellings remain descriptive.
- Remaining uncertainty: original method name, original member names for ready-state bytes, exact project helper names for packet reads/ListPane operations/DialogPane close/refresh methods, and retained duplicate helper emission policy.

## Validator Results

- Validator was not run because this report-only task edited only Agent-B015 research output.
- Commands/evidence run:
  - Attempted IDA MCP `tools/list` at `http://127.0.0.1:13337/mcp`; endpoint unavailable.
  - Direct PE/Capstone dispatcher disassembly and route scans against `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`.
  - `tools/int_convert.py` for `0x493`, `0x274`, `0x270`, `0x100`, `0xa0`, `0x1cc`, `0x26c`, `0x42`, `0x4a`, `0x20`, and related constants.
- Recommended post-edit validation:

> Executable block R001 was removed from this report and preserved verbatim in [00014L-ExchangeDialogPacketDispatcher-source-quality-removed.md](00014L-ExchangeDialogPacketDispatcher-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

## Changed Files

- Created:
  - `E:\NTK\GhidraBridge\source-3\project-documentation\tools\leaser\Agents\Agent-B015\research\00014L-ExchangeDialogPacketDispatcher-source-quality.md`
- Modified:
  - None outside Agent-B015 research.
- Renamed:
  - None.
- Moved to executed:
  - None.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B015","command_id":"000000004165","destination_path":"executed-b-agent-research/B015/00014L-ExchangeDialogPacketDispatcher-source-quality.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:37","uid":"00014L"} -->
<!-- {"agent":"B015","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 00014L-ExchangeDialogPacketDispatcher-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B015/00014L-ExchangeDialogPacketDispatcher-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"00014L"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
