** TARGET-REPORT-UID:0002NN **
** AUTHOR-AGENT-ID:B002 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# B002 Goal 2 Clan List And Item Dialog Callback Source Quality

Assignment: `B002-goal2-clan-list-and-item-dialog-callbacks-source-quality-0002NN-0002NO-0002NR-0002O7-0002O8-0002OB-20260617`

Agent: `Agent-B002`

Date: 2026-06-17

Scope: report-only source-quality reanalysis for [UID:0002NN], [UID:0002NO], [UID:0002NR], [UID:0002O7], [UID:0002O8], and [UID:0002OB]. No by-* docs, generated files, source files, IDA DB, or coverage report files were edited.

## Executive Result

All six targets clear the active code-entry gate as currently documented: `RECONSTRUCTABLE:TRUE`, nonblank `EMITTER_UIDS`, valid source route, and combined score `(COMPLETION + CONFIDENCE) / 2 = 86` before any recommended score increase.

The stale "blank C++ until 95/95" rationale should be removed for these six child pages. Current gate policy allows first-draft C++ once source trust is high enough, and this pass resolves the target-level blockers to high-probability source names and placements.

Recommended source placement:

| UID | Best source-facing method | Owner/source |
| --- | --- | --- |
| `0002NN` | `ClanInfoListPane::CanExecuteAction(int)` | `social/Clan.cpp` through `ClanInfoListPane` / `Clan` |
| `0002NO` | `ClanInfoListPane::CanExecuteAlternateAction(int)` | `social/Clan.cpp` through `ClanInfoListPane` / `Clan` |
| `0002NR` | `ClanJoinListPane::OnSelectedRowAction()` | `social/Clan.cpp` through `ClanJoinListPane` / `Clan` |
| `0002O7` | `ClanLeaveConfirmDialog::OnConfirm()` | `social/Clan.cpp` through `ClanLeaveConfirmDialog` / `Clan` |
| `0002O8` | `ClanLeaveConfirmDialog::OnCancel()` | `social/Clan.cpp` through `ClanLeaveConfirmDialog` / `Clan` |
| `0002OB` | `ClanItemDialog::UpdateConfirmButtonState()` | `social/ClanBank.cpp` through `ClanItemDialog` / `ClanBank` |

Important correction: [UID:0002OB] is not the actual confirm submit handler. It is a confirm-button enable/disable updater. The actual deposit/withdraw action remains in the derived `ClanDepItemDialog` / `ClanWidItemDialog` paths.

## Evidence Checked

Primary target pages checked:

- `by-memory/0x00488610-0x00488615.ClanInfoListPaneFalseActionVirtual.md`
- `by-memory/0x00488620-0x00488625.ClanInfoListPaneFalseAlternateVirtual.md`
- `by-memory/0x004888d0-0x004888f1.ClanJoinListPaneSelectedRowAction.md`
- `by-memory/0x0048a0a0-0x0048a0ae.ClanLeaveConfirmDialogConfirm.md`
- `by-memory/0x0048a0b0-0x0048a0be.ClanLeaveConfirmDialogCancel.md`
- `by-memory/0x0048a120-0x0048a1be.ClanItemDialogConfirmValidation.md`

Support pages checked:

- `by-class/ClanInfoListPane.md`
- `by-class/ClanJoinListPane.md`
- `by-class/ClanLeaveConfirmDialog.md`
- `by-class/ClanItemDialog.md`
- `by-file/Clan.md`
- `by-file/ClanBank.md`
- `by-memory/0x00488610-0x004888f1.ClanListPaneVirtuals.md`
- `by-memory/0x00615570-0x006158f4.ClanPaneListVtableData.md`
- `by-memory/0x004f3a50-0x004f4a77.ListPane.md`
- `by-memory/0x00485590-0x00485682.SendClanJoinListSelectionPacket.md`
- `by-memory/0x00498c10-0x00498c1f.TextEditControlPaneReadTextForwarder.md`
- `by-class/DialogPane.md`
- `by-memory/0x0049d8a0-0x0049feae.DialogPane.md`
- `by-class/ControlPane.md`
- `by-memory/0x00494b50-0x00494c80.ControlFamilyStateVirtualHelpers.md`
- `by-memory/0x00494bb0-0x00494bca.ControlPaneSetVisibleFlag.md`
- `by-memory/0x00494bd0-0x00494bea.ControlPaneClearVisibleFlag.md`
- `by-memory/0x00494c10-0x00494c2a.ControlPaneDeactivate.md`
- `by-memory/0x00494c30-0x00494c4a.ControlPaneActivate.md`
- `by-memory/0x00488b40-0x00488fa0.ClanNameInputDialogCore.md`
- `by-memory/0x0054fa20-0x0054fa5d.MenuQuestionDialogUpdateConfirmButtonState.md`
- `by-item/SpellMenuActionButtonState_51d6c0_51e600.md`
- current by-memory, by-class, and by-file coverage rows for target/support UIDs

Fresh local PE byte check:

- Read-only PE: `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`
- Imagebase parsed from PE: `0x00400000`
- Bytes read for `0x00488610`, `0x004888d0`, `0x0048a0a0`, `0x0048a0b0`, and `0x0048a120`.
- The live MCP endpoint was not reachable in this session, so no IDA DB writes or live IDA actions were performed.

Relevant raw bytes:

```text
00488610 20: 32 c0 c2 04 00 cc cc cc cc cc cc cc cc cc cc cc 32 c0 c2 04 00 cc cc cc cc cc cc cc cc cc cc cc
004888d0 21: 8b 81 34 01 00 00 56 8b 35 e4 ad 67 00 85 c0 78 0e 50 e8 d9 b4 06 00 50 8b ce e8 a1 cc ff ff 5e c3
0048a0a0 0e: 8b 0d e4 ad 67 00 6a 01 e8 53 b6 ff ff c3
0048a0b0 0e: 8b 0d e4 ad 67 00 6a 00 e8 43 b6 ff ff c3
0048a120 9e: 55 8b ec 81 ec 04 01 00 00 a1 24 2f 67 00 33 c5 89 45 fc 53 56 57 8b f9 6a 01 8b 8f fc 01 00 00 8b 01 ff 50 10 8b 8f fc 01 00 00 6a 05 8b 18 8b 01 ff 50 10 8b 8f fc 01 00 00 6a 06 8b 30 8b 01 ff 50 10 6a 7f 8b 08 8b 86 08 01 00 00 8b b0 34 01 00 00 8d 85 fc fe ff ff 50 e8 91 ea 00 00 83 fe ff 74 22 66 83 bd fc fe ff ff 00 74 18 8b 03 8b cb ff 50 4c 5f 5e 5b 8b 4d fc 33 cd e8 8d d5 13 00 8b e5 5d c3 8b 03 8b cb ff 50 50 8b 4d fc 5f 5e 33 cd 5b e8 75 d5 13 00 8b e5 5d c3
```

## Heuristic / Inference Reanalysis And Validation

### [UID:0002NN] ClanInfoListPane False Action Virtual

Best defensible source name: `ClanInfoListPane::CanExecuteAction(int)`.

Best defensible signature:

```cpp
bool ClanInfoListPane::CanExecuteAction(int actionId);
```

Evidence:

- Raw bytes are exactly `32 c0 c2 04 00`: `xor al, al; retn 4`.
- `retn 4` proves one 4-byte stack argument is consumed by the callee. A no-argument source signature is not ABI-faithful.
- The class page already uses `CanExecuteAction` for this slot and describes `ClanInfoListPane` as a read-only `TextEditPane` child.
- Target page records a single data xref at `0x00615678`, no direct callers, exact five-byte body, and padding after the function.
- `ClanPaneListVtableData` places the owning vtable in the `ClanInfoListPane` vtable family.
- The source route is stable: `ClanInfoListPane` -> [UID:0000I8] `Clan` -> `social/Clan.cpp`.

Rejected alternatives:

- `void` or no-return action callback: rejected because `AL` is explicitly cleared and the docs interpret the slot as a false-return gate.
- No-argument method: rejected by `retn 4`.
- Padding/compiler artifact: rejected because it has a vtable data xref and an IDA function body.
- `ClanStringListPane` or generic `TextEditPane` ownership: rejected because `0x00615678` is in the `ClanInfoListPane` vtable set and the class page records this method as a local override.

Validation / contradiction of current docs:

- Validates the current behavior and owner.
- Current no-code rationale is stale under the active combined-score gate.
- The final original method spelling is still not proven by symbols, but `CanExecuteAction` is source-facing and defensible enough for first-draft C++ because the body is a pure false gate with one ABI argument.

Score/source-placement/final-C++ impact:

- Recommend `COMPLETION:86`, `CONFIDENCE:91`.
- Keep `CANONICAL_OWNER:00002E`, `EMITTER_UIDS:00002E`, `RECONSTRUCTABLE:TRUE`.
- First-draft C++ is ready.

### [UID:0002NO] ClanInfoListPane False Alternate Virtual

Best defensible source name: `ClanInfoListPane::CanExecuteAlternateAction(int)`.

Best defensible signature:

```cpp
bool ClanInfoListPane::CanExecuteAlternateAction(int actionId);
```

Evidence:

- Raw bytes are the same false-return ABI body: `32 c0 c2 04 00`.
- `xrefs_to` in the target page reports the vtable-only data xref at `0x00615658`.
- The class page already distinguishes this method as `CanExecuteAlternateAction`.
- Target docs and aggregate docs frame the pair as disabled action paths for the passive `ClanInfoListPane`.

Rejected alternatives:

- Duplicating [UID:0002NN] under one method: rejected because the vtable data xrefs are distinct slots.
- Treating it as an alternate constructor/destructor helper: rejected by body shape and slot context.
- No-argument signature: rejected by `retn 4`.

Validation / contradiction of current docs:

- Validates current body, owner, and companion-role documentation.
- Current blank-C++ rationale is stale under the active gate.

Score/source-placement/final-C++ impact:

- Recommend `COMPLETION:86`, `CONFIDENCE:91`.
- Keep `CANONICAL_OWNER:00002E`, `EMITTER_UIDS:00002E`, `RECONSTRUCTABLE:TRUE`.
- First-draft C++ is ready.

### [UID:0002NR] ClanJoinListPane Selected Row Action

Best defensible source name: `ClanJoinListPane::OnSelectedRowAction()`.

Best defensible signature:

```cpp
int ClanJoinListPane::OnSelectedRowAction();
```

Evidence:

- Target docs record exact range `0x004888d0-0x004888f1`, vtable-only xref `0x006157ec`, no direct callers, selected index at `this+0x134`, selected text retrieval through `0x004f3dc0`, `g_pClanStatusPane` load from `0x0067ade4`, and call to `0x00485590`.
- `ClanJoinListPane` class page records vtable base `0x00615770`, selected-row action slot `+0x7c`, shared row draw slot `+0x80`, and two call sites into `SendClanJoinListSelectionPacket` from row action and Enter-key handler.
- `ListPane` docs identify `+0x134` as selected index and `0x004f3dc0` as `ListPane::GetSelectedEntry`.
- `SendClanJoinListSelectionPacket` docs identify the packet `{0x4b,2,1,len,payload}` and its two callers at `0x004888ea` and `0x00488951`.
- Raw PE bytes clarify return behavior:
  - `mov eax, [ecx+0x134]`
  - `test eax, eax`
  - `js 0x004888ef`
  - selected-index negative path jumps to `pop esi; ret`, returning the negative selected index in `EAX`.
  - nonnegative path pushes the index, calls `0x004f3dc0`, pushes the returned selected text pointer, loads `ECX = g_pClanStatusPane`, calls `0x00485590`, then returns with the packet helper return value in `EAX`.

Rejected alternatives:

- Generic `ListPane` ownership: rejected because the function's only semantic work is Clan join-list packet dispatch and the vtable xref is `ClanJoinListPane`.
- `OnKeyEvent`: rejected because the key/event handler is the adjacent function at `0x00488900`; this one has no event argument and only acts on current selection.
- `RefreshJoinList`: rejected because the packet helper used here sends subtype `2`, action `1`, selected row text. The refresh sibling is [UID:00021F] subtype `2`, action `0`.
- `void` return as the only recommendation: rejected for binary-first reconstruction because the negative path deliberately returns the negative selected index and the positive path preserves the helper return.

Validation / contradiction of current docs:

- Validates the current selected-row behavior, owner, source placement, and selected-row offset chain.
- Refines C++ readiness: the method can be emitted as a value-returning action slot if the inherited vtable declaration remains value-returning. If a later source declaration proves the return ignored/void, the body can be source-polished while preserving the same machine-code side effects.

Score/source-placement/final-C++ impact:

- Recommend `COMPLETION:87`, `CONFIDENCE:91`.
- Keep `CANONICAL_OWNER:00002H`, `EMITTER_UIDS:00002H`, `RECONSTRUCTABLE:TRUE`.
- First-draft C++ is ready, with return-type note above.

### [UID:0002O7] ClanLeaveConfirmDialog Confirm

Best defensible source name: `ClanLeaveConfirmDialog::OnConfirm()`.

Best defensible signature:

```cpp
void ClanLeaveConfirmDialog::OnConfirm();
```

Evidence:

- Target docs record exact range `0x0048a0a0-0x0048a0ae`, vtable data xref `0x00615f94`, no direct callers, and only callee `SendClanLeaveResponse`.
- Raw PE bytes are `mov ecx, [0x0067ade4]; push 1; call 0x00485700; ret`.
- `ClanLeaveConfirmDialog` class page already names this method `OnConfirm`.
- `SendClanLeaveResponse` sends packet bytes `{0x4b,3,1,response}` through the shared packet sender; this callback passes response byte `1`.
- Source route is stable: `ClanLeaveConfirmDialog` remains a modal Clan dialog under [UID:0000I8] `Clan`, not `ClanBank`.

Rejected alternatives:

- `AlertPane` base ownership: rejected because the vtable slot is in the clan leave-confirm dialog family and the behavior is clan opcode-specific.
- Shared `OnButtonClick(int)` for both confirm/cancel: not required by evidence. The binary has two distinct tiny vtable slots, each with a hard-coded response byte.
- ClanBank ownership: rejected because this is clan leave status behavior and calls a Clan opcode helper, not item/bank code.

Validation / contradiction of current docs:

- Validates current docs.
- Current final-source caveat around raw constructor reachability should not block first-draft C++ for this vtable-backed child method.

Score/source-placement/final-C++ impact:

- Recommend `COMPLETION:88`, `CONFIDENCE:93`.
- Keep `CANONICAL_OWNER:00002I`, `EMITTER_UIDS:00002I`, `RECONSTRUCTABLE:TRUE`.
- First-draft C++ is ready.

### [UID:0002O8] ClanLeaveConfirmDialog Cancel

Best defensible source name: `ClanLeaveConfirmDialog::OnCancel()`.

Best defensible signature:

```cpp
void ClanLeaveConfirmDialog::OnCancel();
```

Evidence:

- Target docs record exact range `0x0048a0b0-0x0048a0be`, vtable data xref `0x00615f98`, no direct callers, and only callee `SendClanLeaveResponse`.
- Raw PE bytes are `mov ecx, [0x0067ade4]; push 0; call 0x00485700; ret`.
- `ClanLeaveConfirmDialog` class page already names this method `OnCancel`.
- `SendClanLeaveResponse` sends packet bytes `{0x4b,3,1,0}` for this callback.

Rejected alternatives:

- Treating cancel as a pure local close/no packet path: rejected by direct call to `0x00485700` with response byte `0`.
- AlertPane ownership: rejected for the same reason as [UID:0002O7].
- Bank/item ownership: rejected by opcode/source context.

Validation / contradiction of current docs:

- Validates current docs.
- Current blank C++ rationale is stale for this exact child.

Score/source-placement/final-C++ impact:

- Recommend `COMPLETION:88`, `CONFIDENCE:93`.
- Keep `CANONICAL_OWNER:00002I`, `EMITTER_UIDS:00002I`, `RECONSTRUCTABLE:TRUE`.
- First-draft C++ is ready.

### [UID:0002OB] ClanItemDialog Confirm Validation

Best defensible source name: `ClanItemDialog::UpdateConfirmButtonState()`.

Alternative acceptable name: `ClanItemDialog::UpdateOkButtonState()`.

Rejected current class-page name for this child: `OnConfirm`.

Best defensible signature:

```cpp
void ClanItemDialog::UpdateConfirmButtonState();
```

Evidence:

- Target docs record exact range `0x0048a120-0x0048a1be`, size `0x9e`, vtable data refs `0x00616028`, `0x006160c8`, `0x00616168`, no direct callers, control ids `1`, `5`, and `6`, text-control callee `0x00498c10`, selected-row/text checks, stack-cookie epilogue, and enable/disable virtual branches.
- Raw PE bytes refine the exact lookup shape:
  - `this+0x1fc` is loaded three times; this matches `DialogPane`'s inherited control manager pointer.
  - The control manager virtual at `+0x10` is called with ids `1`, `5`, and `6`.
  - The returned lookup result is a holder/slot; the first dword is loaded to get the actual control object.
  - id `1` actual control is held for the final button-state dispatch.
  - id `5` actual control has an embedded/list pointer at `+0x108`; the selected index is then read from `[that + 0x134]`.
  - id `6` actual control is passed as `ECX` to `TextEditControlPaneReadTextForwarder`, with stack buffer and max count `0x7f`.
  - Stack buffer is 128 wide characters; first wide char is checked against zero.
  - Valid path calls id `1` control virtual `+0x4c`; invalid path calls id `1` control virtual `+0x50`.
- `ControlPane` state docs map base vtable offset `+0x4c` to [UID:0003N3] `ControlPaneSetVisibleFlag` and `+0x50` to [UID:0003N4] `ControlPaneClearVisibleFlag`. In caller context, these are consistently documented as action/confirm button enable/disable slots. They are not the active/focus pair at `+0x58`/`+0x5c`.
- `MenuQuestionDialogUpdateConfirmButtonState`, `MenuQuestionDialogLargerUpdateConfirmButtonState`, `SpellMenuActionButtonState`, `BoardListDialog::UpdateButtonState`, and `ClanNameInputDialog::UpdateOkButtonState` all show the same control-manager/button-state idiom: fetch action/OK button, fetch list/text state, then dispatch `+0x4c` on valid/enabled and `+0x50` on invalid/disabled.
- `TextEditControlPaneReadTextForwarder` has 69 ordinary callers and belongs to `TextEditControlPane`, proving this target owns only caller-side validation, not text control implementation.
- `ClanItemDialog` and `ClanBank` pages place this class and derived deposit/withdraw item dialogs under `social/ClanBank.cpp`.

Rejected alternatives:

- `OnConfirm`: rejected because the body sends no deposit/withdraw packet, closes no dialog, and only toggles control id `1` state. Derived action handlers own actual submit behavior.
- `Clan.cpp`: rejected for this child because `ClanItemDialog`, `ClanDepItemDialog`, `ClanWidItemDialog`, bank/item vtables, and resources route through [UID:0000I9] `ClanBank`. The related raw Clan opcode helper strip stays in `Clan.cpp`, but active item-dialog UI behavior is ClanBank-owned.
- `TextEditControlPane` ownership: rejected because `0x00498c10` is only a reusable callee.
- Treating `+0x1fc` as a local ClanItemDialog field: rejected by `DialogPane` layout docs and constructor/cleanup evidence.
- `Activate`/`Deactivate` for final button state names: rejected for this vtable offset. `Activate`/`Deactivate` are base offsets `+0x5c`/`+0x58`; this target calls `+0x4c`/`+0x50`.
- Single `HasValidQuantity()` helper extraction: no evidence of a separately callable helper. Keep logic local in first draft.

Validation / contradiction of current docs:

- Validates exact range, owner, control ids, `+0x1fc`, text buffer, selected-row/text checks, and enable/disable direction.
- Corrects the source-facing role from "confirm callback" / `OnConfirm` to "confirm button state updater" / `UpdateConfirmButtonState`.
- Refines the selected-row chain: the control-manager lookup returns a holder, then id `5` actual control is loaded, then an embedded/list pointer at `+0x108` is used before selected index `+0x134`.

Score/source-placement/final-C++ impact:

- Recommend `COMPLETION:87`, `CONFIDENCE:91`.
- Keep `CANONICAL_OWNER:00002F`, `EMITTER_UIDS:00002F`, `RECONSTRUCTABLE:TRUE`.
- First-draft C++ is ready with behavior-backed control/member names.

## Packet / Source Ownership Split

Keep these source routes:

- `ClanInfoListPane`, `ClanJoinListPane`, and `ClanLeaveConfirmDialog` targets route to [UID:0000I8] `Clan`, proposed source `NexusTK/social/Clan.cpp`.
- `ClanItemDialog::UpdateConfirmButtonState` routes to [UID:0000I9] `ClanBank`, proposed source `NexusTK/social/ClanBank.cpp`.
- The reusable `TextEditControlPaneReadTextForwarder` stays under `TextEditControlPane`.
- The reusable `ListPane::GetSelectedEntry` and selection offset definitions stay under `ListPane`.
- The raw retained Clan opcode helper strip remains `Clan.cpp`; active clan bank item-dialog UI and packet submitters remain `ClanBank.cpp`.

This split resolves the apparent conflict where active deposit/withdraw item dialogs live in `ClanBank`, while some retained no-route opcode helpers physically sit in the broader Clan opcode helper band.

## First-Draft C++ Recommendation

Every target in this assignment clears `85/85` under the current gate. No target-specific no-code proof applies. The snippets below are first-draft source recommendations, not proof of original symbol spelling.

### [UID:0002NN]

```cpp
bool ClanInfoListPane::CanExecuteAction(int /*actionId*/)
{
    return false;
}
```

### [UID:0002NO]

```cpp
bool ClanInfoListPane::CanExecuteAlternateAction(int /*actionId*/)
{
    return false;
}
```

### [UID:0002NR]

Use this if `SendClanJoinListSelectionPacket` remains value-returning in the final helper declaration:

```cpp
int ClanJoinListPane::OnSelectedRowAction()
{
    const int selectedIndex = m_selectedIndex; // inherited ListPane +0x134
    if (selectedIndex < 0)
        return selectedIndex;

    const wchar_t* selectedName =
        static_cast<const wchar_t*>(GetSelectedEntry(selectedIndex));
    return SendClanJoinListSelectionPacket(g_pClanStatusPane, selectedName);
}
```

If the final source declaration makes the packet helper `void`, keep the same side effects but mark the inherited vtable return as ignored in the class declaration. The binary path still leaves helper `EAX` live after the call.

### [UID:0002O7]

```cpp
void ClanLeaveConfirmDialog::OnConfirm()
{
    SendClanLeaveResponse(g_pClanStatusPane, 1);
}
```

### [UID:0002O8]

```cpp
void ClanLeaveConfirmDialog::OnCancel()
{
    SendClanLeaveResponse(g_pClanStatusPane, 0);
}
```

### [UID:0002OB]

Use existing project control-manager/list/text-control APIs if they exist. The holder/slot detail is included here only to show the exact binary chain.

```cpp
void ClanItemDialog::UpdateConfirmButtonState()
{
    ControlPane* confirmButton = m_controlManager->FindControl(1)->control;
    ControlPane* itemListControl = m_controlManager->FindControl(5)->control;
    TextEditControlPane* quantityEdit =
        static_cast<TextEditControlPane*>(m_controlManager->FindControl(6)->control);

    wchar_t quantityText[128];
    ListPane* itemList = itemListControl->m_embeddedListPane; // control +0x108
    const int selectedIndex = itemList->m_selectedIndex;      // ListPane +0x134

    quantityEdit->ReadText(quantityText, 0x7f);

    if (selectedIndex != -1 && quantityText[0] != L'\0')
        confirmButton->Enable();  // vtable +0x4c, base ControlPane +0x101 set
    else
        confirmButton->Disable(); // vtable +0x50, base ControlPane +0x101 clear
}
```

Source-polish notes:

- `FindControl(id)->control` represents the observed holder whose first dword is the actual control pointer. Use the existing local control-manager return type if already named.
- `m_embeddedListPane` is a role name for the id `5` control object's `+0x108` pointer. Exact member spelling remains inferred.
- `Enable` / `Disable` are caller-context names. Base-control child pages currently call these slots `SetVisibleFlag` / `ClearVisibleFlag`; do not substitute `Activate` / `Deactivate` for these two calls.

## Metadata Recommendations

Apply only if the supervisor accepts this reanalysis.

| UID | Completion | Confidence | Owner | Emitter | Reconstructable | C++ |
| --- | ---: | ---: | --- | --- | --- | --- |
| `0002NN` | `86` | `91` | keep `00002E` | keep `00002E` | keep `TRUE` | populate first draft |
| `0002NO` | `86` | `91` | keep `00002E` | keep `00002E` | keep `TRUE` | populate first draft |
| `0002NR` | `87` | `91` | keep `00002H` | keep `00002H` | keep `TRUE` | populate first draft |
| `0002O7` | `88` | `93` | keep `00002I` | keep `00002I` | keep `TRUE` | populate first draft |
| `0002O8` | `88` | `93` | keep `00002I` | keep `00002I` | keep `TRUE` | populate first draft |
| `0002OB` | `87` | `91` | keep `00002F` | keep `00002F` | keep `TRUE` | populate first draft |

No file-row score changes are required. Optional class-row wording updates are useful for `ClanItemDialog` because [UID:0002OB] should be described as `UpdateConfirmButtonState`, not as an actual `OnConfirm` submit handler.

## Supervisor-Owned Coverage Row Replacement Text

Placement: replace the existing target UID rows in `source-3/project-documentation/by-memory/-coverage-report.md` in place. Do not move neighboring padding rows.

Replace current [UID:0002NN] row between the padding row for `0x00488603-0x00488610` and the padding row for `0x00488615-0x00488620` with:

```text
        - [UID:0002NN][0x00488610-0x00488615.ClanInfoListPaneFalseActionVirtual](by-memory/0x00488610-0x00488615.ClanInfoListPaneFalseActionVirtual.md) 0x00488610-0x00488615 | method | ClanInfoListPane::CanExecuteAction : reconstructable : 86% : very strong : B002 2026-06-17 reanalysis confirms exact five-byte `xor al, al; retn 4` false-return body, one consumed stack argument, vtable-only `ClanInfoListPane` slot `0x00615678`, no direct callers, read-only info-pane action-gate intent, stable `ClanInfoListPane`/`Clan.cpp` source route, high-probability source name `CanExecuteAction`, and first-draft C++ readiness under the active combined-score gate.
```

Replace current [UID:0002NO] row between the padding row for `0x00488615-0x00488620` and the padding row for `0x00488625-0x00488630` with:

```text
        - [UID:0002NO][0x00488620-0x00488625.ClanInfoListPaneFalseAlternateVirtual](by-memory/0x00488620-0x00488625.ClanInfoListPaneFalseAlternateVirtual.md) 0x00488620-0x00488625 | method | ClanInfoListPane::CanExecuteAlternateAction : reconstructable : 86% : very strong : B002 2026-06-17 reanalysis confirms exact five-byte `xor al, al; retn 4` false-return body, one consumed stack argument, distinct vtable-only `ClanInfoListPane` slot `0x00615658`, no direct callers, companion read-only info-pane alternate-action gate intent, stable `ClanInfoListPane`/`Clan.cpp` source route, high-probability source name `CanExecuteAlternateAction`, and first-draft C++ readiness under the active combined-score gate.
```

Replace current [UID:0002NR] row between padding `0x004888c1-0x004888d0` and padding `0x004888f1-0x00488900` with:

```text
        - [UID:0002NR][0x004888d0-0x004888f1.ClanJoinListPaneSelectedRowAction](by-memory/0x004888d0-0x004888f1.ClanJoinListPaneSelectedRowAction.md) 0x004888d0-0x004888f1 | method | ClanJoinListPane::OnSelectedRowAction : reconstructable : 87% : very strong : B002 2026-06-17 reanalysis confirms exact `0x21`-byte vtable-only action slot `0x006157ec`, no direct callers, selected-index guard at inherited `ListPane +0x134`, negative-index early return, selected text retrieval through `ListPane::GetSelectedEntry` `0x004f3dc0`, `g_pClanStatusPane` load from `0x0067ade4`, subtype `2` action `1` join-list packet helper call, positive-path helper return preservation, stable `ClanJoinListPane`/`Clan.cpp` source route, and first-draft C++ readiness.
```

Replace current [UID:0002O7] row between padding `0x0048a09e-0x0048a0a0` and padding `0x0048a0ae-0x0048a0b0` with:

```text
        - [UID:0002O7][0x0048a0a0-0x0048a0ae.ClanLeaveConfirmDialogConfirm](by-memory/0x0048a0a0-0x0048a0ae.ClanLeaveConfirmDialogConfirm.md) 0x0048a0a0-0x0048a0ae | function/method | ClanLeaveConfirmDialog::OnConfirm : reconstructable : 88% : very strong : B002 2026-06-17 reanalysis confirms exact vtable-backed confirm callback slot `0x00615f94`, no direct callers, raw bytes `mov ecx,[g_pClanStatusPane]; push 1; call SendClanLeaveResponse; ret`, response byte `1`, downstream packet bytes `{0x4b,3,1,1}`, `ClanLeaveConfirmDialog`/`Clan.cpp` source route, rejection of base AlertPane ownership, and first-draft C++ readiness.
```

Replace current [UID:0002O8] row between padding `0x0048a0ae-0x0048a0b0` and padding `0x0048a0be-0x0048a0c0` with:

```text
        - [UID:0002O8][0x0048a0b0-0x0048a0be.ClanLeaveConfirmDialogCancel](by-memory/0x0048a0b0-0x0048a0be.ClanLeaveConfirmDialogCancel.md) 0x0048a0b0-0x0048a0be | function/method | ClanLeaveConfirmDialog::OnCancel : reconstructable : 88% : very strong : B002 2026-06-17 reanalysis confirms exact vtable-backed cancel callback slot `0x00615f98`, no direct callers, raw bytes `mov ecx,[g_pClanStatusPane]; push 0; call SendClanLeaveResponse; ret`, response byte `0`, downstream packet bytes `{0x4b,3,1,0}`, `ClanLeaveConfirmDialog`/`Clan.cpp` source route, rejection of base AlertPane ownership, and first-draft C++ readiness.
```

Replace current [UID:0002OB] row under the `ClanItemDialog` core area with:

```text
        - [UID:0002OB][0x0048a120-0x0048a1be.ClanItemDialogConfirmValidation](by-memory/0x0048a120-0x0048a1be.ClanItemDialogConfirmValidation.md) 0x0048a120-0x0048a1be | method | ClanItemDialog::UpdateConfirmButtonState : reconstructable : 87% : very strong : B002 2026-06-17 reanalysis confirms exact virtual confirm-button state updater, vtable refs `0x00616028`/`0x006160c8`/`0x00616168`, no direct callers, inherited `DialogPane +0x1fc` control-manager lookups for ids `1`/`5`/`6`, holder-to-control dereference shape, id `5` embedded-list pointer `+0x108` to selected index `+0x134`, id `6` text read through `TextEditControlPaneReadTextForwarder` with 128-wide-char stack buffer and max `0x7f`, valid path button slot `+0x4c` and invalid path slot `+0x50`, `ClanBank.cpp` source route, correction from submit-style `OnConfirm` to `UpdateConfirmButtonState`, and first-draft C++ readiness.
```

Optional class coverage row wording, no class score change required. Placement: replace the existing rows for these UIDs in `source-3/project-documentation/by-class/-coverage-report.md` if the supervisor wants class coverage to reflect first-draft child C++ readiness.

Replace current [UID:00002E] class row with:

```text
- [UID:00002E][ClanInfoListPane](by-class/ClanInfoListPane.md) : reconstructable : 85% : strong : B002 2026-06-17 reanalysis confirms passive read-only `TextEditPane` purpose, inline construction, Wave2 372-byte layout, inactive zero-caller raw constructor evidence, exact false-return virtual bodies, vtable-only refs `0x00615678`/`0x00615658`, high-probability source names `CanExecuteAction`/`CanExecuteAlternateAction`, Clan file parent routing, and first-draft C++ readiness for the two tiny action-gate children while raw constructor reachability remains the class-level cap.
```

Replace current [UID:00002H] class row with:

```text
- [UID:00002H][ClanJoinListPane](by-class/ClanJoinListPane.md) : reconstructable : 86% : very strong : B002 2026-06-17 reanalysis reconfirms inline construction, primary vtable store, shared draw slot, selected-row action and key/event handler function sizes, vtable-only refs, inherited `ListPane +0x134` selected-index use, selected-entry retrieval, negative-index early return and positive-path packet-helper return preservation for `OnSelectedRowAction`, Enter-gated subtype `2` action `1` join packet helper calls, `g_packetSender` dependency, padding boundaries, Clan owner/emitter route, and first-draft C++ readiness for the single selected-row action child while broader class declaration and enum/helper names remain source-polish items.
```

Replace current [UID:00002I] class row with:

```text
- [UID:00002I][ClanLeaveConfirmDialog](by-class/ClanLeaveConfirmDialog.md) : reconstructable : 85% : very strong : raw constructor plus confirm/cancel child pages refreshed with Wave2 zero-caller constructor/filter/base-layout support, live IDA no-function/no-xref and vtable-slot evidence, B002 2026-06-17 callback reanalysis confirming `OnConfirm` sends leave-response byte `1` and `OnCancel` sends byte `0`, exact packet bytes `{0x4b,3,1,response}`, Clan parent routing, and first-draft C++ readiness for both callbacks while raw constructor reachability remains the class-level final-source caveat.
```

Replace current [UID:00002F] class row in `by-class/-coverage-report.md` if supervisor wants the role correction reflected immediately:

```text
- [UID:00002F][ClanItemDialog](by-class/ClanItemDialog.md) : reconstructable : 85% : very strong : raw constructor, vtable-reset, confirm-button state updater, scalar destructor, and thunk child evidence refreshed with Wave2 zero-caller constructor/filter/base-layout support, live IDA vtable/reset/destructor refs, local PE no VA/RVA/relative-branch hits for the raw constructor start, `DialogPane +0x1fc` control-manager validation evidence, `+0x4c/+0x50` button enable/disable slot mapping, ClanBank parent routing, and remaining final-source caveats for constructor reachability and exact member/control spelling.
```

No file coverage replacement is recommended. [UID:0000I8] `Clan` and [UID:0000I9] `ClanBank` already express the correct module split.

## Open Questions Status

All targeted open questions are resolved or reduced to source-polish level:

- False-return virtual intent: resolved as read-only `ClanInfoListPane` action/alternate-action gates.
- Selected-row chain: resolved as inherited `ListPane +0x134`, with helper return behavior clarified from raw PE bytes.
- Confirm/cancel semantics: resolved as leave response bytes `1` and `0`.
- `+0x1fc`: resolved as inherited `DialogPane` control manager pointer.
- `+0x4c`/`+0x50`: resolved as button enable/disable caller-context slots, backed by base `ControlPane` `+0x101` set/clear helpers, not active/focus helpers.
- `ClanItemDialog` method role: corrected to `UpdateConfirmButtonState`, not submit `OnConfirm`.
- Packet/source ownership split: resolved as `Clan.cpp` for clan list/leave helpers, `ClanBank.cpp` for active item-dialog validation.

Remaining nonblocking source-polish items:

- Exact original spelling of action-gate methods and control-manager return types is not symbol-proven.
- Final `ListPane`/packet helper declarations may alter whether `ClanJoinListPane::OnSelectedRowAction` is emitted as value-returning or side-effect-only with ignored return.
- Exact source member name for id `5` control's `+0x108` embedded-list pointer remains inferred.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B002","command_id":"000000004165","destination_path":"executed-b-agent-research/B002/0002NN-0002NO-0002NR-0002O7-0002O8-0002OB-clan-list-item-dialog-source-quality.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:25","uid":"0002NN"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
