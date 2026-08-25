** TARGET-REPORT-UID:0002HG **
** AUTHOR-AGENT-ID:B001 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# 0002HG EmployeeItemPropertyDialogPaneOnCommand Source-Quality Report

Agent: `B001`
Assignment: `B001-report-employee-item-property-dialog-command-source-quality-0002HG-mcp-20260623`
Target: [UID:0002HG][0x004a4660-0x004a476e.EmployeeItemPropertyDialogPaneOnCommand](../../../by-memory/0x004a4660-0x004a476e.EmployeeItemPropertyDialogPaneOnCommand.md)
Mode: report-only MCP-backed research
MCP session: `80de0a67`

No by-* docs, generated/project-level files, IDA DB state, tool state, or `-coverage-report.md` files were edited during this report-only pass. No subagents were used.

## Recommendation

Apply a target repair, not a no-change disposition.

| Item | Current | Recommended |
| --- | --- | --- |
| `COMPLETION` | `85` | `88` |
| `CONFIDENCE` | `88` | `91` |
| `CANONICAL_OWNER` | `000138` | `00004D` |
| `EMITTER_UIDS` | `000138` | `00004D` |
| `RECONSTRUCTABLE` | `TRUE` | `TRUE` |
| `EMITTER_POSITION_OPTIONAL` | blank | blank |
| Formal C++ | blank | add first-draft method C++ |

Rationale: current MCP proves the function is the `EmployeeItemPropertyDialogPane` primary vtable command/action slot, with exact bounds, exact successor, a data-only vtable xref, all three action behaviors, the text-edit/control route, the decimal parse helper, the TimerHandler scheduling route, and the parent command helper payload consumption. The current direct class [UID:00004D][EmployeeItemPropertyDialogPane](../../../by-class/EmployeeItemPropertyDialogPane.md) and file [UID:0000J0][EmployeeDialogPane](../../../by-file/EmployeeDialogPane.md) clear the active code-entry route, so the aggregate [UID:000138][EmployeeDialogPanes](../../../by-memory/0x004a1d70-0x004a4e6b.EmployeeDialogPanes.md) should remain an owning range/support aggregate rather than the formal owner/emitter for this exact class method.

## Current MCP Evidence

MCP was available. `server_health` on session `80de0a67` returned status `ok`, IDB `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, module `NexusTK.exe`, `auto_analysis_ready:true`, `hexrays_ready:true`, and `strings_cache_ready:true`.

Validated target facts:

- `lookup_funcs`/decompile identify `0x004a4660` as `sub_4A4660`, size `0x10e`; the byte stream ends with `retn 8`, followed by two `0xcc` bytes at `0x004a476e-0x004a4770`.
- Successor boundary is real: `0x004a4770` is `sub_4A4770`, not a continuation of `0x004a4660`.
- `xrefs_to 0x004a4660` returns a single data xref from vtable slot `0x00618fe4`; `xrefs_to 0x00618fe4` has no direct refs to the slot address itself. This is vtable dispatch data, not standalone data ownership.
- `get_int 0x00618fe4 u32le` returns `0x004a4660`, matching [UID:0002MF][EmployeeItemPropertyDialogPaneVtableData](../../../by-memory/0x00618f98-0x00619034.EmployeeItemPropertyDialogPaneVtableData.md).
- The target callees are `sub_498C10`, `sub_4944F0`, `sub_5975E0`, `sub_49EB90`, `sub_49DAD0`, and `@__security_check_cookie@4`.
- `get_string 0x00610660` resolves the decimal format literal as `%d`; [UID:00028M][CrtStdioScanOptionsStorage](../../../by-memory/0x0067a768-0x0067a770.CrtStdioScanOptionsStorage.md) documents `sub_4944F0` as the wide scanf-family wrapper using `__stdio_common_vswscanf`.
- `sub_498C10` is [UID:0002OA][TextEditControlPaneReadTextForwarder](../../../by-memory/0x00498c10-0x00498c1f.TextEditControlPaneReadTextForwarder.md), so the returned control is a text edit control route.
- `sub_5975E0` is [UID:0001K8][TimerHandlerScheduleRemoveWrappers](../../../by-memory/0x005975e0-0x0059760d.TimerHandlerScheduleRemoveWrappers.md), the generic `TimerHandler::ScheduleTimer` wrapper, not a direct packet writer.

Validated support facts:

- Current constructor MCP for `0x004a41c0` shows `DialogPane("Property", 20, 1)`, owner storage at `this+0x26c`, selected-record storage at `this+0x280`, vtable installs, icon rect write at `this+0x270`, price-edit creation from record `+0x410`, item name label from `+0x008`, current value label from `+0x40c`, and focus setup for control id `3`.
- Current sibling quantity action MCP for `0x004a4a30` shows the same inherited control-manager route at `this+0x1fc`, action id `1` as submit/confirm, action id `2` as close/cancel, text read through `sub_498C10`, decimal parse through `sub_4944F0`, and scheduling through owner `+0xa4`.
- Current parent command helper MCP for `0x004a2c80` shows switch cases `0` through `5`, opcode `0x54`, packet family byte `1`, subcommand bytes matching event ids, and case `2` reading `this+456` and `this+460` before serializing a 19-byte packet. Because the target schedules through `parent+0xa4`, those two reads map back to primary parent offsets `parent+0x26c` and `parent+0x270`.

Important integer conversions confirmed during the pass:

| Hex | Decimal | Report use |
| --- | ---: | --- |
| `0x10e` | `270` | target size |
| `0x1fc` | `508` | inherited control manager pointer |
| `0x26c` | `620` | property-dialog owner field and parent pending value field |
| `0x270` | `624` | property-dialog icon rect and parent pending state field |
| `0x280` | `640` | selected `EmployeeRecord*` |
| `0x40c` | `1036` | record current price/value |
| `0x410` | `1040` | record editable price/value seed |
| `0xa4` | `164` | `DialogPane` tertiary/TimerHandler view |
| `0x80` | `128` | text buffer capacity |

## Branch Behavior

Current decompilation of `0x004a4660` resolves all action ids used by this method:

| Action id | Best source name | Exact behavior |
| --- | --- | --- |
| `1` | `kEmployeeItemPropertyConfirmAction` | If owner is non-null, seeds a local price from `m_itemRecord->editablePriceValue` (`record+0x410`), fetches control id `3` through the inherited control manager at `this+0x1fc`, reads 128 wide characters from the text edit, parses `%d`, and only when the parsed value is nonzero writes parent `+0x26c/+0x270`, schedules employee event `2`, then closes. A null owner or parsed zero returns without closing. |
| `0` | `kEmployeeItemPropertyRemoveAction` | If owner is non-null, schedules employee event `3` on `owner+0xa4` with the selected record id and current `record+0x40c` value, then closes. If owner is null, it still closes. Parent `SendCommand` case `3` serializes only the record id, so the current-value argument is preserved in the schedule call for binary/source-shape fidelity but is not packet payload. |
| `2` | `kEmployeeItemPropertyCloseAction` | Close-only path through `sub_49EB90` and `sub_49DAD0`; no command is scheduled. |
| other | no named command | Return without closing or scheduling. |

The current target doc omits the action id `2` close-only branch and describes parent `+0x26c` as a pending selected record pointer. Both should be corrected. The record pointer is already stored on the property dialog at `this+0x280`; the parent fields are command-2 pending payload fields.

## Source-Facing Names

Recommended names for the target and support docs:

| Binary location | Recommended source-facing name | Evidence and rejected alternatives |
| --- | --- | --- |
| method `0x004a4660` | `EmployeeItemPropertyDialogPane::OnCommand(int actionId, int actionParam)` | Primary vtable slot `0x00618fe4` under the property dialog class. The raw function returns with `retn 8`, reads the first stack arg as action id, and ignores the second stack arg. |
| action id `1` | `kEmployeeItemPropertyConfirmAction` | Constructor builds the editable price control from `record+0x410`; branch reads control id `3`, parses text, stages command `2`, and closes only on nonzero parsed price. `Confirm` ranks over generic `OK` because the code validates and dispatches an edit payload. |
| action id `0` | `kEmployeeItemPropertyRemoveAction` | Branch does not read edited text and schedules event/subcommand `3`, whose parent command helper serializes a record-id-only packet. `Remove` or `Clear` ranks over `Reset price` because command `3` does not serialize the current value despite receiving it in the schedule wrapper. Use `Remove` in target docs and note the packet-shape evidence. |
| action id `2` | `kEmployeeItemPropertyCloseAction` | Close-only branch mirrors the sibling quantity dialog action id `2`; no packet or pending field write. |
| control id `3` | `kEmployeeItemPropertyPriceEditControlId` / `m_priceEdit` | Constructor creates an edit control seeded from `record+0x410`, calls focus setup for id `3`, and target action `1` fetches id `3` before text read/parse. |
| `this+0x1fc` | inherited `DialogPane::m_controlManager` | [UID:0001U4][DialogPaneLayout](../../../by-type/by-struct/DialogPaneLayout.md) now explicitly prefers `m_controlManager` over the generated alias `m_controls`; target dispatches vtable slot `+0x10` with control id `3`. |
| returned control | `TextEditControlPane*` | The only consumer is `sub_498C10`, the `TextEditControlPane` read-text forwarder, with 128-wide buffer capacity. |
| `this+0x26c` | `m_owner` / `m_parentDialog` | Constructor stores the owning `EmployeeDialogPane*`; target reads it before scheduling through `owner+0xa4`. Use `m_owner` in C++ to match existing generated employee/add-item style, and mention `parentDialog` as the layout role. |
| `this+0x270` | `m_itemIconRect` | Constructor writes `(20,21,68,69)`; paint reads this rect. The target does not touch it, so it should stay in layout/support rather than the target touched-state table unless noted as adjacent derived tail. |
| `this+0x280` | `m_itemRecord` | Constructor stores selected `EmployeeRecord*`; paint and target read id/current/editable values. |
| parent `+0x26c` | `m_pendingPropertyPriceValue` | Target writes parsed nonzero price; parent command case `2` reads it as `this+456` from the TimerHandler subobject and serializes it as a dword payload. It is not a record pointer. |
| parent `+0x270` | `m_pendingPropertyPriceState` | Target writes `1`; parent command case `2` reads it as `this+460` and serializes it as the second command-2 dword payload. Treat as a state/mode dword rather than a bool because the packet writer stores a full dword. |
| record `+0x000` | `employeeItemId` / `id` | Existing [UID:0001UD][EmployeeRecord](../../../by-type/by-struct/EmployeeRecord.md) parser and command paths support both names. C++ can use `employeeItemId` for clarity. |
| record `+0x40c` | `priceValue` / `displayValue` | Constructor formats it as current displayed price; target passes it to event `3`, and parent case `3` ignores the second scheduled arg. Use `priceValue` in target-context docs and keep `displayValue` alias on the broad record layout. |
| record `+0x410` | `editablePriceValue` / `editableValue` | Constructor seeds the editable price control from it; target uses it as parse default. Use `editablePriceValue` in target-context docs and keep broader alias on the record layout. |
| helper `0x005975e0` | `TimerHandler::ScheduleTimer` | Accepted [UID:0001K8] C++ and current xrefs prove this is a generic timer scheduling wrapper. The target should not call it a packet sender. |
| helper `0x004a2c80` | `EmployeeDialogPane::SendCommand` / TimerHandler callback | Parent vtable slot `0x00618f94` and switch cases serialize opcode `0x54` employee commands. This is the packet writer reached later by the scheduled event, not the immediate helper called by target. |

## First-Draft C++ Readiness

The method clears the active code-entry gate:

- `RECONSTRUCTABLE:TRUE`.
- Recommended `EMITTER_UIDS:00004D`; [UID:00004D] surfaces to [UID:0000J0][EmployeeDialogPane](../../../by-file/EmployeeDialogPane.md) and generated output `auto-generated/NexusTK/ui/dialogs/EmployeeDialogPane.cpp`.
- `(88 + 91) / 2 = 89.5`, greater than `85`.
- Dependencies used by the draft have documented routes: `DialogPane::m_controlManager`, `TextEditControlPane::ReadText`, wide scanf wrapper, `TimerHandler::ScheduleTimer`, inherited close helpers, `EmployeeRecord`, and `EmployeeDialogPane::SendCommand`.

Recommended C++ to place in the target page:

```cpp
void EmployeeItemPropertyDialogPane::OnCommand(int actionId, int actionParam)
{
    (void)actionParam;

    if (actionId == kEmployeeItemPropertyConfirmAction) {
        if (m_owner != NULL) {
            int price = m_itemRecord->editablePriceValue;
            wchar_t priceText[128];
            TextEditControlPane *priceEdit =
                static_cast<TextEditControlPane *>(
                    m_controlManager->GetControl(kEmployeeItemPropertyPriceEditControlId));

            priceEdit->ReadText(priceText, 128);
            swscanf(priceText, L"%d", &price);

            if (price != 0) {
                m_owner->m_pendingPropertyPriceValue = price;
                m_owner->m_pendingPropertyPriceState = 1;
                m_owner->m_timerHandler.ScheduleTimer(
                    kEmployeeCommandUpdatePropertyPrice,
                    0,
                    m_itemRecord->employeeItemId,
                    0);
                SlideClose();
                CloseDialog();
            }
        }
        return;
    }

    if (actionId == kEmployeeItemPropertyRemoveAction) {
        if (m_owner != NULL) {
            m_owner->m_timerHandler.ScheduleTimer(
                kEmployeeCommandRemovePropertyItem,
                0,
                m_itemRecord->employeeItemId,
                m_itemRecord->priceValue);
        }
        SlideClose();
        CloseDialog();
        return;
    }

    if (actionId == kEmployeeItemPropertyCloseAction) {
        SlideClose();
        CloseDialog();
    }
}
```

Notes for implementation:

- The draft intentionally includes `actionParam` and casts it unused because the binary consumes two stack arguments but only reads the first.
- The confirm path must not close on null owner or parsed zero. That early-return behavior is visible in the current branch structure.
- The remove path closes even when owner is null. That matches the `goto LABEL_9` path.
- `kEmployeeCommandUpdatePropertyPrice` should map to event/subcommand `2`; `kEmployeeCommandRemovePropertyItem` should map to event/subcommand `3`.
- `m_controlManager` is preferred in formal docs because [UID:0001U4] names `+0x1fc` that way. If local generated EmployeeDialogPane style still uses `m_controls`, add an alias note rather than reverting the source-quality name.

## Owner, Emitter, And Placement

Ranked alternatives:

1. `CANONICAL_OWNER:00004D`, `EMITTER_UIDS:00004D` for target `0002HG`: recommended. The function is a vtable method of `EmployeeItemPropertyDialogPane`, the class parent clears the gate, and the class already routes to the EmployeeDialogPane file.
2. Keep `CANONICAL_OWNER:000138`, `EMITTER_UIDS:000138`: reject for the exact method. The aggregate is a valid range index/support owner for the employee-dialog island, but it is broader than the exact class method and should not be the C++ emitter once the class route is clear.
3. `CANONICAL_OWNER:00004C`, `EMITTER_UIDS:00004C`: reject for the target. The parent dialog owns the command packet writer and pending payload fields, but `0x004a4660` dispatches from the property-dialog vtable slot, stores/reads property-dialog tail fields, and belongs to [UID:00004D].
4. `CANONICAL_OWNER:0000J0`, `EMITTER_UIDS:0000J0`: reject for the target. The file owns the source module, but by-structure prefers the narrowest true owner; the class owner is available and more precise.
5. Non-emitting target with class/support docs carrying all behavior: reject. The body is source-authored custom game UI logic and now has sufficient branch, field, helper, and route evidence for first-draft C++.

## Support Document Changes To Apply If Accepted

Target [UID:0002HG] should be updated at report-level detail:

- Header: `COMPLETION:88`, `CONFIDENCE:91`, `CANONICAL_OWNER:00004D`, `EMITTER_UIDS:00004D`.
- Status: replace stale "medium for final button/control names" with current-session resolution of action ids, control id `3`, inherited control manager, text-edit read, pending parent fields, and timer/packet route.
- Behavior and command flow: add action id `2`; distinguish action id `1` no-close on zero parsed value; action id `0` close-even-with-null-owner; other ids return.
- Touched state: correct parent `+0x26c/+0x270` to pending property price payload fields; move selected record pointer to `this+0x280`; identify inherited `+0x1fc` as `m_controlManager`.
- IDA evidence: replace the 2026-06-14 stale session language with current session `80de0a67` facts from this report.
- Reconstruction notes: replace blank-C++ rationale with the C++ readiness explanation and add the first-draft method body.
- Changes log: add a 2026-06-23 B001 source-quality entry with the score/owner/emitter/C++ change and evidence summary.

Support pages:

- [UID:00004D][EmployeeItemPropertyDialogPane](../../../by-class/EmployeeItemPropertyDialogPane.md): raise `86/87 -> 87/89`; update method map for `OnCommand`, action constants, control id `3`, owner/record fields, and remove the old broad final-gate wording as a reason for blank method C++.
- [UID:00004C][EmployeeDialogPane](../../../by-class/EmployeeDialogPane.md): keep score unless the implementation also rewrites the parent command helper table; add target-specific field notes for `m_pendingPropertyPriceValue` and `m_pendingPropertyPriceState`, and state that scheduled events `2` and `3` route through `EmployeeDialogPane::SendCommand`.
- [UID:0000J0][EmployeeDialogPane](../../../by-file/EmployeeDialogPane.md): keep score; update the `EmployeeItemPropertyDialogPane` row to state that `0002HG` now emits through [UID:00004D] with first-draft C++ while the broad file still owns the source module.
- [UID:000138][EmployeeDialogPanes](../../../by-memory/0x004a1d70-0x004a4e6b.EmployeeDialogPanes.md): keep score and blank aggregate C++; add a child-routing note that `0002HG` is no longer aggregate-emitted and that the aggregate remains a non-code range/support index.
- [UID:0001UB][EmployeeItemPropertyDialogPaneLayout](../../../by-type/by-struct/EmployeeItemPropertyDialogPaneLayout.md): raise `85/90 -> 86/91`; rename/alias `+0x1fc` to inherited `DialogPane::m_controlManager`, `+0x26c` to owner/parent dialog, `+0x270` to `m_itemIconRect`, and `+0x280` to `m_itemRecord`; remove the specific target blocker that control/member names block `0002HG` C++.
- [UID:0001UD][EmployeeRecord](../../../by-type/by-struct/EmployeeRecord.md): keep score; add a target-context note that `+0x000` is sent as employee item id, `+0x40c` is the current/display price used by the remove/clear schedule call, and `+0x410` is the editable price seed used by the property editor.
- [UID:0003KW][EmployeeDialogPaneSendCommand](../../../by-memory/0x004a2c80-0x004a2f5d.EmployeeDialogPaneSendCommand.md): raise `87/90 -> 88/91` if the packet case table is added; document cases `2` and `3` at the same detail as this report, including the TimerHandler subobject offset mapping where `this+456/+460` corresponds to primary parent `+0x26c/+0x270`.
- [UID:0001XH][EmployeeDialogPaneVtables](../../../by-type/by-vtable/EmployeeDialogPaneVtables.md) and [UID:0002MF][EmployeeItemPropertyDialogPaneVtableData](../../../by-memory/0x00618f98-0x00619034.EmployeeItemPropertyDialogPaneVtableData.md): keep scores; add a short support note that slot `0x00618fe4` now has first-draft C++ on `0002HG` and direct class owner/emitter `00004D`.
- [UID:0002HE][EmployeeItemPropertyDialogPaneConstructor](../../../by-memory/0x004a41c0-0x004a456b.EmployeeItemPropertyDialogPaneConstructor.md): keep score unless the constructor is separately selected; add a support note that current MCP confirms price-edit setup from `record+0x410`, current-price label from `record+0x40c`, and focus/control id `3`, which now unblocks the target `OnCommand` C++.
- [UID:0002HI][EmployeeQuantityInputDialogPaneOnAction](../../../by-memory/0x004a4a30-0x004a4adb.EmployeeQuantityInputDialogPaneOnAction.md): no edit required; use as supporting negative/positive sibling evidence only.

## Score Rationale

Recommended target completion `88`: the target now has current-session proof for exact range, byte boundary, successor, vtable-only xref, action ids `0/1/2`, close/no-close behavior, text edit/control route, parse helper, TimerHandler schedule helper, parent command-helper payload consumption, corrected parent pending fields, corrected owner/emitter route, and a first-draft C++ body.

Recommended target confidence `91`: independent MCP checks and support docs agree on the method boundary, vtable slot, constructor-created price edit, inherited `DialogPane` control-manager field, record fields, `TextEditControlPane` read-text helper, wide scanf helper, generic TimerHandler schedule wrapper, and parent `EmployeeDialogPane::SendCommand` switch cases. The score stays below final-audit levels because the exact original private constant spellings are not recovered from symbols, constructor C++ remains blank, and the broader `EmployeeRecord` layout still carries shared-context aliases.

## Rejected No-Code And No-Score Dispositions

- No-code because action labels are not original symbol names: rejected. The branch semantics are specific enough for source-facing constants, and first-draft C++ can use clearly documented inferred names.
- No-code because parent pending fields were unclear: rejected. Current parent command helper proves target writes become command-2 packet payloads via TimerHandler subobject offset mapping.
- No-code because `sub_5975E0` looked like a packet sender: rejected. [UID:0001K8] and current xrefs prove the immediate call is generic timer scheduling; packet serialization happens in `EmployeeDialogPane::SendCommand`.
- Keep aggregate owner/emitter because the target sits inside `0x004a1d70-0x004a4e6b`: rejected for this exact method. Range aggregation is not the narrowest source owner once [UID:00004D] clears the route.
- Split a new child page: rejected. `0002HG` is already an exact child for the full modeled method; no smaller source-authored child body exists inside it.
- Move behavior entirely into `EmployeeDialogPane`: rejected. Parent fields and command helper are support evidence, but vtable ownership and derived tail fields prove the method belongs to `EmployeeItemPropertyDialogPane`.

## Supervisor-Owned Coverage Text

Do not edit coverage during the B-agent implementation callback unless explicitly reassigned. If the report is accepted, the supervisor should apply these exact coverage changes after real doc edits and validator output are verified.

Replace the current [UID:0002HG] row in `by-memory/-coverage-report.md` with:

```md
        - [UID:0002HG][0x004a4660-0x004a476e.EmployeeItemPropertyDialogPaneOnCommand](by-memory/0x004a4660-0x004a476e.EmployeeItemPropertyDialogPaneOnCommand.md) 0x004a4660-0x004a476e | method | EmployeeItemPropertyDialogPane::OnCommand : reconstructable : 88% : very strong : B001 2026-06-23 current MCP session `80de0a67` resolves the property-dialog command/action slot: exact `0x10e` body ending before successor `0x004a4770`, vtable slot `0x00618fe4`, action id `1` confirm path through price edit control id `3`, `TextEditControlPane::ReadText`, `%d` parse, nonzero validation, parent pending price fields `+0x26c/+0x270`, scheduled event/subcommand `2`; action id `0` remove/clear path scheduling event/subcommand `3` with selected record id and current `record+0x40c`; action id `2` close-only path; generic TimerHandler scheduling via `0x005975e0`; parent command serialization in `EmployeeDialogPane::SendCommand`; owner/emitter rerouted to [UID:00004D][EmployeeItemPropertyDialogPane](by-class/EmployeeItemPropertyDialogPane.md); first-draft C++ is present on the target page.
```

Replace the current [UID:00004D] row in `by-class/-coverage-report.md` if the class score is raised:

```md
- [UID:00004D][EmployeeItemPropertyDialogPane](by-class/EmployeeItemPropertyDialogPane.md) : reconstructable : 87% : strong : Feature-private EmployeeDialogPane property/price editor attached to [UID:0000J0][EmployeeDialogPane](by-file/EmployeeDialogPane.md); B001 2026-06-23 current MCP resolves `OnCommand` action ids `0/1/2`, price edit control id `3`, inherited `m_controlManager`, owner/record fields, parent pending price payload fields, TimerHandler scheduling, and parent command cases `2/3`; [UID:0002HG] now owns first-draft C++ through this class while constructor/paint/destructor and broader record/layout aliases remain below final-audit status.
```

Replace the current [UID:0001UB] row in `by-type/by-struct/-coverage-report.md` if the layout score is raised:

```md
- [UID:0001UB][EmployeeItemPropertyDialogPaneLayout](by-type/by-struct/EmployeeItemPropertyDialogPaneLayout.md) : reconstructable : 86% : very strong : Derived property dialog layout attached to [UID:00004D][EmployeeItemPropertyDialogPane](by-class/EmployeeItemPropertyDialogPane.md); B001 2026-06-23 current MCP and support docs resolve inherited `DialogPane::m_controlManager` at `+0x1fc`, owner `EmployeeDialogPane*` at `+0x26c`, `m_itemIconRect` at `+0x270`, selected `EmployeeRecord*` at `+0x280`, constructor price-edit setup from `record+0x410`, current-value label from `record+0x40c`, target command use of control id `3`, and first-draft C++ readiness for [UID:0002HG].
```

If [UID:0003KW] is raised and the supervisor keeps manual by-memory coverage in sync with exact generated children, insert this row under the EmployeeDialogPanes child list near the other `0x004a2c80` range children:

```md
        - [UID:0003KW][0x004a2c80-0x004a2f5d.EmployeeDialogPaneSendCommand](by-memory/0x004a2c80-0x004a2f5d.EmployeeDialogPaneSendCommand.md) 0x004a2c80-0x004a2f5d | method | EmployeeDialogPane::SendCommand : reconstructable : 88% : very strong : B001 2026-06-23 current MCP documents opcode `0x54` employee command serialization cases `0-5`, with target-relevant case `2` reading TimerHandler-subobject `this+456/+460` as primary parent `+0x26c/+0x270` pending property price payloads and case `3` serializing the selected record id only; this is the packet writer reached after `TimerHandler::ScheduleTimer`, not the immediate helper called by `EmployeeItemPropertyDialogPane::OnCommand`.
```

## Implementation Tracking Checklist

- [x] Lease only the immediate by-* files selected for the accepted implementation batch; do not lease coverage files; release all leases immediately after edits and scoped validators. Proof: B001 leased the 11 accepted by-* docs only for the edit/validator batches; no `-coverage-report.md` file was leased or edited; `python leaser.py B001 unlease` returned `Success` for all 11 changed by-* docs after validation.
- [x] Update [UID:0002HG] metadata to `88/91`, owner/emitter `00004D`, reconstructable true, blank emitter position. Proof: `by-memory/0x004a4660-0x004a476e.EmployeeItemPropertyDialogPaneOnCommand.md` now has `COMPLETION:88`, `CONFIDENCE:91`, `CANONICAL_OWNER:00004D`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:00004D`, and a blank `EMITTER_POSITION_OPTIONAL`.
- [x] Update [UID:0002HG] behavior, command-flow, touched-state, IDA evidence, reconstruction notes, score rationale, cross-reference/change-log sections with the current MCP evidence and corrected action/field/helper names from this report. Proof: target page now records current MCP session `80de0a67` facts for range `0x004a4660-0x004a476e`, successor `0x004a4770`, vtable slot `0x00618fe4`, action ids `1/0/2`, control id `3`, inherited `m_controlManager`, selected record at `this+0x280`, parent pending fields `+0x26c/+0x270`, `TimerHandler::ScheduleTimer`, and parent `EmployeeDialogPane::SendCommand`.
- [x] Add the first-draft C++ body to [UID:0002HG] exactly preserving action id `1` no-close-on-zero/null-owner behavior, action id `0` close-even-if-owner-null behavior, and action id `2` close-only behavior. Proof: target `RECONSTRUCTION_CPP CODE` now contains `EmployeeItemPropertyDialogPane::OnCommand(int actionId, int actionParam)` with confirm action guarded by non-null owner and nonzero parsed price before close, remove action closing after optional schedule, close-only action, and default return.
- [x] Update [UID:00004D] `EmployeeItemPropertyDialogPane` with the accepted method map, constants/control names, owner/record fields, first-draft C++ route, and score `87/89` if accepted. Proof: `by-class/EmployeeItemPropertyDialogPane.md` now has `COMPLETION:87`, `CONFIDENCE:89`, an updated [UID:0002HG] method-map row, action/control/owner/record/pending-field evidence, first-draft C++ routing through the class, and replacement of stale broad final-gate wording.
- [x] Update [UID:00004C] `EmployeeDialogPane` with pending property price field names and the scheduled event/subcommand `2/3` route through `EmployeeDialogPane::SendCommand`. Proof: `by-class/EmployeeDialogPane.md` now documents `m_pendingPropertyPriceValue`, `m_pendingPropertyPriceState`, TimerHandler scheduling from the child, SendCommand case `2` payload mapping, case `3` id-only serialization, and the rejected stale selected-record-pointer assumption.
- [x] Update [UID:0000J0] `EmployeeDialogPane` file page with target owner/emitter reroute to [UID:00004D] and file-level source placement notes. Proof: `by-file/EmployeeDialogPane.md` now states [UID:0002HG] emits through [UID:00004D] while the source module remains `EmployeeDialogPane.cpp`, and preserves the broad file's class/source placement role.
- [x] Update [UID:000138] aggregate to preserve blank aggregate C++ and record that [UID:0002HG] emits through the class child, not the aggregate. Proof: `by-memory/0x004a1d70-0x004a4e6b.EmployeeDialogPanes.md` now keeps aggregate owner/emitter/C++ unchanged while noting exact children can emit through direct owners and that [UID:0002HG] is class-emitted through [UID:00004D].
- [x] Update [UID:0001UB] layout with inherited `m_controlManager`, owner/parent, icon rect, item record, price-edit control id `3`, and score `86/91` if accepted. Proof: `by-type/by-struct/EmployeeItemPropertyDialogPaneLayout.md` now has `COMPLETION:86`, `CONFIDENCE:91`, names `+0x1fc` as inherited `DialogPane::m_controlManager`, `+0x26c` as owner/parent, `+0x270` as `m_itemIconRect`, `+0x280` as `m_itemRecord`, and records control id `3` plus parent pending-field mapping.
- [x] Update [UID:0001UD] `EmployeeRecord` with target-context aliases for `employeeItemId`, `priceValue`, and `editablePriceValue` without forcing a broad record score change. Proof: `by-type/by-struct/EmployeeRecord.md` keeps score unchanged and adds B001 target-context notes for `+0x000`, `+0x40c`, and `+0x410`.
- [x] Update [UID:0003KW] `EmployeeDialogPaneSendCommand` with the case table and TimerHandler-subobject offset mapping; raise to `88/91` if accepted. Proof: `by-memory/0x004a2c80-0x004a2f5d.EmployeeDialogPaneSendCommand.md` now has `COMPLETION:88`, `CONFIDENCE:91`, a command case table for cases `0-5`, and target-relevant offset mapping from TimerHandler-subobject `this+456/+460` to primary parent `+0x26c/+0x270`.
- [x] Add short support notes to [UID:0001XH] and [UID:0002MF] confirming vtable slot `0x00618fe4` now has target first-draft C++ and direct class owner/emitter `00004D`. Proof: `by-type/by-vtable/EmployeeDialogPaneVtables.md` and `by-memory/0x00618f98-0x00619034.EmployeeItemPropertyDialogPaneVtableData.md` both now record slot/address `0x00618fe4 -> 0x004a4660`, [UID:0002HG], owner/emitter [UID:00004D], and first-draft C++.
- [x] Add a support note to [UID:0002HE] constructor confirming current-session price edit/control id `3` evidence; do not add constructor C++ unless separately accepted. Proof: `by-memory/0x004a41c0-0x004a456b.EmployeeItemPropertyDialogPaneConstructor.md` now records current MCP confirmation of price-edit setup from `record+0x410`, current price label from `record+0x40c`, selected name evidence, control id `3`, and keeps constructor C++ blank with target-specific unblock rationale only.
- [x] Do not edit [UID:0002HI] unless a supervisor requests sibling sync; retain it as supporting evidence only. Proof: `by-memory/0x004a4a30-0x004a4adb.EmployeeQuantityInputDialogPaneOnAction.md` was not edited; no contradiction was found during implementation.
- [x] Do not edit any `-coverage-report.md`; leave the exact replacement/insert text above for supervisor-owned application. Proof: coverage files were not edited by B001; exact supervisor-owned replacement/insert text remains in the `Supervisor-Owned Coverage Text` section above for `by-memory/-coverage-report.md`, `by-class/-coverage-report.md`, `by-type/by-struct/-coverage-report.md`, and optional [UID:0003KW] by-memory insertion.
- [x] Run scoped validators from `E:\NTK\GhidraBridge\source-3\project-documentation` for every changed by-* file, using `python tools\validator.py --mode file --file <by-*> --apply`; record exit code, `ok` count, warnings, and generated/autogen side effects. Proof: all 11 scoped validator commands below returned `EXIT:0`, `ok:1`, and `WARNINGS:none` in the compact proof pass; each compact pass reported validator-owned side-effect counters `autogen_cpp_conflict:5`, `autogen_cpp_noop:270`, `autogen_emitter_has_no_code:541`, `autogen_registry_rebuild:1`, `autogen_registry_stale:2`, and `projected_stats_update:1`. The earlier edit-batch validator for the target also applied the accepted metadata/owner/C++ registry updates (`completion_update`, `confidence_update`, `canonical_owner_update`, `autogen_registry_update`, `autogen_cpp_update`) and UID/reference link normalization.
- [x] Re-read `tools/leaser/Agents/Agent-B001/current_leases.md` after unlease/release commands and report no active B001 leases before returning implementation completion. Proof: the shared lease report `tools/leaser/Agents/current_leases.md` was re-read after unlease and showed `No active leases.`

Validator command proof from compact pass, all run from `E:\NTK\GhidraBridge\source-3\project-documentation`:

| File | Command | Exit | ok | Warnings | Side effects |
| --- | --- | --- | --- | --- | --- |
| `by-memory\0x004a4660-0x004a476e.EmployeeItemPropertyDialogPaneOnCommand.md` | `python .\tools\validator.py --mode file --file by-memory\0x004a4660-0x004a476e.EmployeeItemPropertyDialogPaneOnCommand.md --apply --queue-timeout 240` | `0` | `1` | none | `autogen_cpp_conflict:5`; `autogen_cpp_noop:270`; `autogen_emitter_has_no_code:541`; `autogen_registry_rebuild:1`; `autogen_registry_stale:2`; `projected_stats_update:1` |
| `by-class\EmployeeItemPropertyDialogPane.md` | `python .\tools\validator.py --mode file --file by-class\EmployeeItemPropertyDialogPane.md --apply --queue-timeout 240` | `0` | `1` | none | same validator-owned counters as above |
| `by-class\EmployeeDialogPane.md` | `python .\tools\validator.py --mode file --file by-class\EmployeeDialogPane.md --apply --queue-timeout 240` | `0` | `1` | none | same validator-owned counters as above |
| `by-file\EmployeeDialogPane.md` | `python .\tools\validator.py --mode file --file by-file\EmployeeDialogPane.md --apply --queue-timeout 240` | `0` | `1` | none | same validator-owned counters as above |
| `by-memory\0x004a1d70-0x004a4e6b.EmployeeDialogPanes.md` | `python .\tools\validator.py --mode file --file by-memory\0x004a1d70-0x004a4e6b.EmployeeDialogPanes.md --apply --queue-timeout 240` | `0` | `1` | none | same validator-owned counters as above |
| `by-type\by-struct\EmployeeItemPropertyDialogPaneLayout.md` | `python .\tools\validator.py --mode file --file by-type\by-struct\EmployeeItemPropertyDialogPaneLayout.md --apply --queue-timeout 240` | `0` | `1` | none | same validator-owned counters as above |
| `by-type\by-struct\EmployeeRecord.md` | `python .\tools\validator.py --mode file --file by-type\by-struct\EmployeeRecord.md --apply --queue-timeout 240` | `0` | `1` | none | same validator-owned counters as above |
| `by-memory\0x004a2c80-0x004a2f5d.EmployeeDialogPaneSendCommand.md` | `python .\tools\validator.py --mode file --file by-memory\0x004a2c80-0x004a2f5d.EmployeeDialogPaneSendCommand.md --apply --queue-timeout 240` | `0` | `1` | none | same validator-owned counters as above |
| `by-type\by-vtable\EmployeeDialogPaneVtables.md` | `python .\tools\validator.py --mode file --file by-type\by-vtable\EmployeeDialogPaneVtables.md --apply --queue-timeout 240` | `0` | `1` | none | same validator-owned counters as above |
| `by-memory\0x00618f98-0x00619034.EmployeeItemPropertyDialogPaneVtableData.md` | `python .\tools\validator.py --mode file --file by-memory\0x00618f98-0x00619034.EmployeeItemPropertyDialogPaneVtableData.md --apply --queue-timeout 240` | `0` | `1` | none | same validator-owned counters as above |
| `by-memory\0x004a41c0-0x004a456b.EmployeeItemPropertyDialogPaneConstructor.md` | `python .\tools\validator.py --mode file --file by-memory\0x004a41c0-0x004a456b.EmployeeItemPropertyDialogPaneConstructor.md --apply --queue-timeout 240` | `0` | `1` | none | same validator-owned counters as above |

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B001","command_id":"000000004165","destination_path":"executed-b-agent-research/B001/0002HG-EmployeeItemPropertyDialogPaneOnCommand-source-quality.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:16","uid":"0002HG"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
