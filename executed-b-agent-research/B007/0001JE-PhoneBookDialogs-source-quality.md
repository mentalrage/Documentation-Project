** TARGET-REPORT-UID:0001JE **
** AUTHOR-AGENT-ID:B007 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# 0001JE PhoneBookDialogs Source-Quality Research

## Finalized Report / Current Recommendation

- Current recommendation: keep [UID:0001JE] `by-memory/0x0058c350-0x0058d74c.PhoneBookDialogs.md` attached to [UID:0000MJ] `by-file/PhoneBookDialog.md` as the `PhoneBookDialog.cpp` source-family aggregate, but keep its formal `RECONSTRUCTION_CPP` block blank.
- Final disposition: source-bearing family, not a single source body. The aggregate should document the complete phone-book/list/entry range and route future code through exact child method pages. It must not paste multiple child method bodies into the aggregate block.
- Required action: update the target inventory with the missing retained no-direct-xref helpers at `0x0058c9c0`, `0x0058ca70`, `0x0058cb30`, `0x0058ced0`, and `0x0058cf20`; correct raw helper end/padding details; add source-quality split/C++ policy; preserve [UID:0001JF] as the existing emitted exact child; keep [UID:0001JL] as CRT/runtime no-code glue.
- Recommended target metadata after implementation: `COMPLETION:88`, `CONFIDENCE:89`, `CANONICAL_OWNER:0000MJ`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000MJ`, blank formal C++ with the no-aggregate-code proof below.
- Confidence: high for boundaries, source family, caller/callee evidence, row layout, generated-name rejection, and child-emission policy; still below final audit because most source-bearing methods remain broad aggregate rows rather than exact child pages with formal C++.

## Target

- Target UID: [UID:0001JE]
- Target path: `source-3/project-documentation/by-memory/0x0058c350-0x0058d74c.PhoneBookDialogs.md`
- Required report path: `source-3/project-documentation/tools/leaser/Agents/Agent-B007/research/0001JE-PhoneBookDialogs-source-quality.md`
- Current metadata: `85/86`, owner/emitter [UID:0000MJ] `PhoneBookDialog`, reconstructable true, C++ blank.
- Assignment type: B-agent report-only source-quality, heuristic/inference, split/emission-policy pass.

## Evidence Checked

- Read target and support docs:
  - `by-memory/0x0058c350-0x0058d74c.PhoneBookDialogs.md`
  - `by-file/PhoneBookDialog.md`
  - `by-class/PhoneBookDialog.md`
  - `by-class/PhoneBookListPane.md`
  - `by-class/PhoneEntryDialog.md`
  - `by-class/DialDialog.md`
  - `by-item/PhoneBookListHelpers_58cfa0_58dcb0.md`
  - `by-memory/0x0058cfa0-0x0058cfdb.PhoneBookSelectedEntryHelper.md`
  - `by-memory/0x0058dcb0-0x0058dcd3.PhoneBookFormattedWriteHelper.md`
  - vtable/resource children `0003DQ`, `0003DR`, `0003DS`, `0003DT`, `0003GV`, `0003GW`, `0003GX`
  - `by-memory/0x0062da10-0x0062df94.TerminalPhoneReadOnlyData.md`
  - `by-project-structure/proposed-source-tree.md`
- Read generated output/coverage:
  - `auto-generated/NexusTK/login/PhoneBookDialog.cpp`
  - `auto-generated/-ag-memory-coverage.md`
  - `auto-generated/-ag-class-coverage.md`
  - `auto-generated/-ag-file-coverage.md`
  - `auto-generated/-ag-item-coverage.md`
  - `by-memory/-coverage-report.md`
  - `by-class/-coverage-report.md`
  - `by-file/-coverage-report.md`
  - `by-item/-coverage-report.md`
- Checked prior B-agent research:
  - `tools/leaser/Agents/Agent-B001/research/executed/0001JF-0001JL-phonebook-helper-source-quality.md`
- Local PE evidence from `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`:
  - PE image base `0x00400000`; `.text` covers executable target range.
  - Manual rel32 call/jump scan for target starts and helper starts.
  - Manual absolute-reference scan for selected targets and vtable heads.
  - Hex dumps around hidden helper gaps, raw helper tails, `OnCommand` jump table, `RenderEntry` tail, and DialDialog successor padding.
- MCP availability check:
  - `list_mcp_resources` returned no resources in this Codex session. This pass used current IDA-backed by-* documentation plus direct local PE byte/ref checks. Existing IDA MCP claims were treated as documentation evidence and revalidated where possible through local bytes/refs.

## Key Findings

### Aggregate C++ Policy

[UID:0001JE] should not receive aggregate-level C++ even though it remains reconstructable and routed to `PhoneBookDialog.cpp`. The range is a multi-method, multi-class source-family map:

- `PhoneBookDialog` constructor, command, save, and retained helper bodies.
- `PhoneBookListPane` setup, retained list helpers, selected-entry helper, activation forwarder, and renderer.
- `PhoneEntryDialog` constructor, validation, and action handler.
- local padding and a six-entry `OnCommand` jump table.
- existing exact emitted child [UID:0001JF] inside the same physical range.

Adding formal C++ to the aggregate would either duplicate [UID:0001JF] or place several child method bodies outside their own exact scopes. The correct implementation path is exact child emission for each source-bearing method/helper, with this aggregate documenting the family and split plan. If a later implementation creates exact child pages for every source-bearing subrange and routes them, the supervisor can consider reclassifying [UID:0001JE] as a non-emitting container; do not do that now because several source-bearing subranges are not yet split.

### Missing Subranges In Current Target Inventory

The target page currently skips real retained helpers between the constructor and `DialSelectedEntry`, and between `SavePhoneBook` and the selected-entry child. These are not padding.

| Half-open range | Inclusive filename range if split | Best source-facing role | Reachability | Recommendation |
| --- | --- | --- | --- | --- |
| `0x0058c350-0x0058c9b5` | `0x0058c350-0x0058c9b4` | `PhoneBookDialog::PhoneBookDialog` | constructor; current docs cite IDA boundary | Keep aggregate row; future exact child if constructor C++ pass is accepted. |
| `0x0058c9b5-0x0058c9c0` | padding | eleven `0xcc` bytes | local PE hex | Add as padding row. |
| `0x0058c9c0-0x0058ca63` | `0x0058c9c0-0x0058ca62` | retained `PhoneBookDialog::AppendPhoneBookEntry` / `AddPhoneBookEntry` wrapper | no rel32 or abs refs to start | Add target row; best name inferred from building a `PhoneBookContactEntry` from flag/name/number and inserting through the dialog-owned list. |
| `0x0058ca63-0x0058ca70` | padding | thirteen `0xcc` bytes | local PE hex | Add padding row. |
| `0x0058ca70-0x0058cb2e` | `0x0058ca70-0x0058cb2d` | retained `PhoneBookDialog::ReplaceSelectedPhoneBookEntry` wrapper | no rel32 or abs refs to start | Add target row; best name inferred from selected-row remove plus rebuilt row insert/update behavior. |
| `0x0058cb2e-0x0058cb30` | padding | two `0xcc` bytes | local PE hex | Add padding row. |
| `0x0058cb30-0x0058cb5d` | `0x0058cb30-0x0058cb5c` | retained `PhoneBookDialog::RemoveSelectedPhoneBookEntry` / `DeleteSelectedEntry` wrapper | no rel32 or abs refs to start | Add target row; it removes selected row through list helper and jumps to dialog/list refresh slot. |
| `0x0058cb5d-0x0058cb60` | padding | three `0xcc` bytes | local PE hex | Add padding row. |
| `0x0058ce15-0x0058ce18` | alignment | three-byte `0f 1f 00` nop | local PE hex | Add note under `OnCommand`. |
| `0x0058ce18-0x0058ce30` | jump table | six dwords: `0x58cd12`, `0x58cd19`, `0x58cd2a`, `0x58cd65`, `0x58cdc9`, `0x58cdf4` | local PE hex | Add as `PhoneBookDialog::OnCommand` local switch table, not generic padding. |
| `0x0058cec7-0x0058ced0` | padding | `0xcc` bytes after `SavePhoneBook` | local PE hex | Add padding row. |
| `0x0058ced0-0x0058cf1d` | `0x0058ced0-0x0058cf1c` | retained `PhoneBookListPane::Initialize` / setup helper | no rel32 refs to start; vtable docs show vptr stores at `0x58cefe`, `0x58cf04`, `0x58cf0e` | Add target row; already mentioned only on class page. |
| `0x0058cf1d-0x0058cf20` | padding | three `0xcc` bytes | local PE hex | Add padding row. |
| `0x0058cf20-0x0058cf9a` | `0x0058cf20-0x0058cf99` | retained `PhoneBookListPane::AppendEntry` / `AddEntry` | no rel32 refs to start | Add target row; list-side row builder and insert helper. |
| `0x0058cf9a-0x0058cfa0` | padding | six `0xcc` bytes | local PE hex | Add padding row. |

The existing post-selected-entry raw helper inventory is directionally right but needs endpoint precision:

| Half-open range | Inclusive filename range if split | Current/proposed role | Correction |
| --- | --- | --- | --- |
| `0x0058cfa0-0x0058cfdc` | existing [UID:0001JF] `0x0058cfa0-0x0058cfdb` | `PhoneBookListPane::GetSelectedEntryData` | Keep. |
| `0x0058cfdc-0x0058cfe0` | padding | four `0xcc` bytes | Keep. |
| `0x0058cfe0-0x0058d075` | `0x0058cfe0-0x0058d074` | retained `PhoneBookListPane::ReplaceSelectedEntryData` | Current target text says `0x0058cfe0-0x0058d073`; local bytes show the `ret 0x0c` includes byte `0x0058d074`, so use half-open end `0x0058d075`. |
| `0x0058d075-0x0058d080` | padding | eleven `0xcc` bytes | Current target implies padding starts earlier; correct it. |
| `0x0058d080-0x0058d08e` | `0x0058d080-0x0058d08d` | retained `PhoneBookListPane::RemoveSelectedEntry` | Keep behavior; clarify endpoint convention. |
| `0x0058d08e-0x0058d090` | padding | two `0xcc` bytes | Add if not explicit. |
| `0x0058d090-0x0058d10e` | `0x0058d090-0x0058d10d` | retained `PhoneBookListPane::SaveEntriesToPhoneCfg` | Keep behavior; raw calls to [UID:0001JL] are at `0x0058d0db` and `0x0058d0ed`. |
| `0x0058d10e-0x0058d110` | padding | two `0xcc` bytes | Keep. |
| `0x0058d110-0x0058d11b` | `0x0058d110-0x0058d11a` | `PhoneBookListPane::DialSelectedEntry` | Existing inclusive row is fine; half-open end is `0x0058d11b`. |
| `0x0058d11b-0x0058d120` | padding | five `0xcc` bytes | Add if not explicit. |
| `0x0058d120-0x0058d263` | `0x0058d120-0x0058d262` | `PhoneBookListPane::RenderEntry` | Existing inclusive row is fine; half-open end is `0x0058d263`. |
| `0x0058d263-0x0058d270` | padding | thirteen `0xcc` bytes | Add if not explicit. |
| `0x0058d74c-0x0058d750` | padding | four `0xcc` bytes before [UID:0001JG] `DialDialog` | Keep; local bytes show `PhoneEntryDialog::OnDialogAction` returns before `DialDialog` prolog. |

## Direct Xref / Caller Inventory

Local PE rel32 scan results:

| Target | Direct rel32 refs found | Interpretation |
| --- | --- | --- |
| `0x0058c9c0` | none | retained dialog add/append wrapper, no live callsite found. |
| `0x0058ca70` | none | retained dialog replace/update wrapper, no live callsite found. |
| `0x0058cb30` | none | retained dialog remove/delete wrapper, no live callsite found. |
| `0x0058cb60` | `call@0x0058cdf4`, `jmp@0x0058d116` | `OnCommand` dial case and `PhoneBookListPane::DialSelectedEntry` forwarder. |
| `0x0058ce30` | `call@0x0058cbdd`, `call@0x0058cd12` | `DialSelectedEntry` saves before dialing; `OnCommand` save/close case. |
| `0x0058ced0` | none | retained list setup helper, no live callsite found. |
| `0x0058cf20` | none | retained list append/add helper, no live callsite found. |
| `0x0058cfa0` | `call@0x0058cd8c` | edit path obtains selected name/number; direct owner [UID:0000AE]. |
| `0x0058cfe0` | none | retained list replace helper, no live callsite found. |
| `0x0058d080` | none | retained list remove helper, no live callsite found. |
| `0x0058d090` | none | retained list save helper, no live callsite found. |
| `0x0058d270` | `call@0x0058cd5b`, `call@0x0058cdc2` | add/edit command cases construct `PhoneEntryDialog`. |
| `0x0058d750` | `call@0x0058cc17` | `PhoneBookDialog::DialSelectedEntry` constructs `DialDialog`. |
| `0x0058dcb0` | `call@0x0058ce94`, `call@0x0058cea6`, `call@0x0058d0db`, `call@0x0058d0ed` | two modeled `SavePhoneBook` writes and two raw list-save writes; still CRT/runtime wrapper. |

Absolute-reference scan:

- No abs32 refs to `0x0058cfa0`, `0x0058cfe0`, `0x0058d080`, `0x0058d090`, `0x0058d750`, or `0x0058dcb0`.
- `0x0058d110` appears at `0x0062dc60` and `0x0058d120` at `0x0062dc64`, proving the `PhoneBookListPane` vtable activation/render slots.
- `0x0062db48`, `0x0062dbe4`, and `0x0062dd44` appear as constructor/setup vptr stores in `.text`, matching the vtable child docs.

## Heuristic / Inference Reanalysis And Validation

### Source Placement

Best placement remains `NexusTK/login/PhoneBookDialog.cpp`, not `TerminalPane.cpp`, despite the terminal-pane relationship. Evidence:

- [UID:0000MJ] already has the projected path `NexusTK/login/` and groups `PhoneBookDialog`, `PhoneBookListPane`, `PhoneEntryDialog`, and `DialDialog`.
- [UID:00026N] splits terminal/setup vtables and phone-book/dial vtables into distinct direct class children.
- `PhoneBookDialog` starts immediately after `TerminalPaneAndSetup` and ends before `DialDialog`, but the phone-book resource strings, `PHONE.CFG`, `DLGTEL1.EPD`, `DLGTEL2.EPD`, list row layout, and dial handoff form a coherent source module.
- `proposed-source-tree.md` already lists `TerminalPane.cpp` and `PhoneBookDialog.cpp` as separate login files. Its phone-book row needs stale wording updates, but its file split direction is still best-supported.

Rejected alternatives:

- Fold into `TerminalPane.cpp`: plausible historically because the flow is terminal/modem UI, but weaker than the existing source-tree split and class/resource grouping.
- Move `PhoneBookListPane` to a generic list file: rejected because the row fields, owner pointer, vtables, resources, and callers are all phone-book specific.
- Treat [UID:0001JE] as a no-owner non-emitter now: rejected because it still documents unsplit source-bearing code that belongs to [UID:0000MJ].

### Row Type And Field Names

Keep `PhoneBookContactEntry`:

```cpp
struct PhoneBookContactEntry
{
    unsigned char entryFlags;
    wchar_t name[64];
    wchar_t phoneNumber[64];
};
```

Evidence:

- [UID:0001JF] copies `entry + 0x02` and `entry + 0x82`, each as 64-wide-character buffers, and returns byte `entry + 0x00`.
- Save paths write the same two wide strings with `%s\n`.
- Render path draws the same fields as two contact columns.
- Add/edit helper paths build the same flag/name/number row and write zero into the flag byte.

Open question closed with a conservative name:

- `entryFlags` remains the safest field name. All checked producer paths write zero, and no checked consumer decodes nonzero bits. Names such as `status`, `favorite`, `deleted`, or `selected` are too specific.

### Shared List Helper Names

Recommended descriptive helper names:

- `0x004f3bd0`: `ListPane::GetItemCount` / `GetEntryCount`.
- `0x004f3dc0`: `ListPane::GetItemAt` / `GetEntryAt`.
- `this + 0x134` in list panes: selected row index.
- `PhoneBookListPane + 0x14c`: `m_ownerDialog`.
- `PhoneBookDialog + 0x1fc`: `m_phoneBookList` or embedded phone-book list pointer.
- `PhoneEntryDialog + 0x26c`: `m_ownerDialog`.
- `PhoneEntryDialog + 0x270`: `m_addMode` or `m_isNewEntry`.

These are inferred/descriptive, not original-proof. They are strong enough for documentation and first-draft child C++ because the behavior and offsets are repeatedly confirmed; they should remain below 95+ until class layouts and inherited base declarations are finalized.

### Retained No-Direct-Xref Helpers

The no-xref helpers should be treated as retained source methods, not padding and not compiler glue. They have normal prologs/epilogs, stack-cookie patterns, calls into list/string helpers, and phone-book-specific row construction. The absence of direct xrefs is best explained as unreferenced member/helper code retained from the object file, consistent with the older compiler/linker model used elsewhere in this project.

Best names:

- `0x0058c9c0`: `PhoneBookDialog::AppendPhoneBookEntry` or `PhoneBookDialog::AddPhoneBookEntry`.
- `0x0058ca70`: `PhoneBookDialog::ReplaceSelectedPhoneBookEntry`.
- `0x0058cb30`: `PhoneBookDialog::RemoveSelectedPhoneBookEntry` or `DeleteSelectedEntry`.
- `0x0058ced0`: `PhoneBookListPane::Initialize` / `Setup`.
- `0x0058cf20`: `PhoneBookListPane::AppendEntry`.
- `0x0058cfe0`: `PhoneBookListPane::ReplaceSelectedEntryData`.
- `0x0058d080`: `PhoneBookListPane::RemoveSelectedEntry`.
- `0x0058d090`: `PhoneBookListPane::SaveEntriesToPhoneCfg`.

Rejected alternatives:

- Compiler-generated names: rejected because bodies are source-like and feature-specific.
- Padding: rejected by executable bytes and calls.
- `ArticleListPane`/`ChattingColorListPane`: rejected as generated owner pollution around shared list helpers.

### SavePhoneBook

`PhoneBookDialog::SavePhoneBook` at `0x0058ce30-0x0058cec7` is source-ready for a first-draft child page:

- Opens `PHONE.CFG` with `wt`.
- Fetches list count with `0x004f3bd0`.
- Fetches each row with `0x004f3dc0`.
- Writes `entry->name` and `entry->phoneNumber` with `L"%s\n"`.
- Closes the file.
- Calls [UID:0001JL] only because the compiler/runtime provided a local `fwprintf` wrapper; source should call normal CRT output.

Do not populate this body in [UID:0001JE]. Create an exact child page first, for example `0x0058ce30-0x0058cec6.PhoneBookDialogSavePhoneBook.md`, or update an existing exact child if one is created by the supervisor callback.

### RenderEntry

`PhoneBookListPane::RenderEntry` at `0x0058d120-0x0058d263` is behaviorally understood but should not be formalized in the aggregate. Best-supported behavior:

- Reads `PhoneBookContactEntry::name` and `PhoneBookContactEntry::phoneNumber`.
- Draws selected-row highlight when the row is selected.
- Truncates each column with ellipsis to fit approximate name and number column widths.
- Uses palette/text drawing helpers rather than [UID:0001JL].

The method is suitable for a first-draft child page if the callback accepts descriptive graphics helper names. It should remain below final audit until palette/text helper names and inherited base declarations are coordinated.

### PhoneEntryDialog

High-probability member names:

- `m_ownerDialog` at `+0x26c`.
- `m_addMode` / `m_isNewEntry` at `+0x270`.
- `m_nameEdit` and `m_numberEdit` for text controls 3 and 4.

Behavior:

- Constructor loads `DLGTEL2.EPD`, creates OK/cancel controls and name/number text controls with 128-character limits, stores owner pointer and mode byte.
- `UpdateButtonState` enables OK/control 1 only when both text controls are non-empty.
- `OnDialogAction` action id 1 copies controls 3 and 4 into 63-character buffers, appends on add mode, replaces the selected contact on edit mode, refreshes owner state, and closes. Action id 2 cancels/closes.

This supports exact child pages and first-draft C++ for `UpdateButtonState` and `OnDialogAction`; class-level C++ should remain blank until field layout and inherited dialog APIs are coordinated.

### PhoneBookFormattedWriteHelper No-Code Policy

[UID:0001JL] should stay `CANONICAL_OWNER:NONE`, `RECONSTRUCTABLE:FALSE`, blank emitters, blank C++.

Evidence:

- Calls `0x0041b9a0` for local CRT stdio option storage.
- Forwards to common formatted-output backend `0x005d2208`.
- Has no phone-book state and no row-specific logic.
- Four callsites are all caller-level formatted writes.

Source should use `fwprintf(file, L"%s\n", value);`. Do not route [UID:0001JL] back to [UID:0000MJ], and do not call it `PhoneBookDialog::WriteWideFormattedLine`.

### Generated-Name / Owner-Pollution Issues

Resolved:

- `ChattingColorListPane` and `ArticleListPane` names around phone-book list helpers are generated owner pollution. They should remain as historical rejected assumptions only.
- Current validator-generated `auto-generated/NexusTK/login/PhoneBookDialog.cpp` emits only [UID:0001JF] code plus empty markers for the class/aggregate/vtable/resource pages. It does not supply source authority for the missing phone-book bodies.
- Stale notes in `proposed-source-tree.md` still say [UID:0001JL] is a "phone-book formatted-write helper under review"; update that to CRT/runtime wrapper no-code.

## First-Draft C++ Recommendation

Do not populate [UID:0001JE] formal C++. The following drafts are for future exact child pages or accepted class/method pages only.

### `PhoneBookDialog::SavePhoneBook` child draft

```cpp
void PhoneBookDialog::SavePhoneBook()
{
    FILE *file = _wfopen(L"PHONE.CFG", L"wt");
    if (file == NULL)
        return;

    const int count = m_phoneBookList->GetEntryCount();
    for (int index = 0; index < count; ++index)
    {
        const PhoneBookContactEntry *entry =
            static_cast<const PhoneBookContactEntry *>(m_phoneBookList->GetEntryAt(index));

        fwprintf(file, L"%s\n", entry->name);
        fwprintf(file, L"%s\n", entry->phoneNumber);
    }

    fclose(file);
}
```

Notes: `GetEntryCount` and `GetEntryAt` are descriptive names for `0x004f3bd0` and `0x004f3dc0`. Use the final shared `ListPane` names if a broader list API pass has accepted alternatives.

### `PhoneBookDialog::DialSelectedEntry` child draft

```cpp
void PhoneBookDialog::DialSelectedEntry()
{
    wchar_t name[64];
    wchar_t phoneNumber[64];

    m_phoneBookList->GetSelectedEntryData(name, _countof(name),
                                          phoneNumber, _countof(phoneNumber));
    SavePhoneBook();
    Close();

    new DialDialog(g_pTerminalPane, phoneNumber);
}
```

Notes: constructor argument order for `DialDialog` should be checked before formal insertion. Behavior direction is strong: selected row copied, phone book saved/closed, `DialDialog` constructed at `0x0058cc17`.

### `PhoneBookDialog::UpdateButtonStates` child draft

```cpp
void PhoneBookDialog::UpdateButtonStates()
{
    const bool hasEntries = (m_phoneBookList->GetEntryCount() > 0);

    EnableControl(kPhoneBookEditButton, hasEntries);
    EnableControl(kPhoneBookDeleteButton, hasEntries);
    EnableControl(kPhoneBookDialButton, hasEntries);
}
```

Notes: control constants need final names from the dialog resource/control mapping.

### retained dialog/list wrapper drafts

```cpp
void PhoneBookDialog::AppendPhoneBookEntry(
    unsigned char entryFlags,
    const wchar_t *name,
    const wchar_t *phoneNumber)
{
    m_phoneBookList->AppendEntry(entryFlags, name, phoneNumber);
    UpdateButtonStates();
}

void PhoneBookDialog::ReplaceSelectedPhoneBookEntry(
    unsigned char entryFlags,
    const wchar_t *name,
    const wchar_t *phoneNumber)
{
    m_phoneBookList->ReplaceSelectedEntryData(entryFlags, name, phoneNumber);
    UpdateButtonStates();
}

void PhoneBookDialog::RemoveSelectedPhoneBookEntry()
{
    m_phoneBookList->RemoveSelectedEntry();
    UpdateButtonStates();
}

void PhoneBookListPane::DialSelectedEntry()
{
    m_ownerDialog->DialSelectedEntry();
}
```

Notes: these names are descriptive. Exact child pages should preserve no-direct-xref evidence and explain that retained source methods may exist without live callsites.

### `PhoneEntryDialog` action/update draft

```cpp
void PhoneEntryDialog::UpdateButtonState()
{
    const bool hasName = (m_nameEdit->GetTextLength() > 0);
    const bool hasNumber = (m_numberEdit->GetTextLength() > 0);

    EnableControl(kOkButton, hasName && hasNumber);
}

void PhoneEntryDialog::OnDialogAction(int controlId)
{
    if (controlId == kOkButton)
    {
        wchar_t name[64];
        wchar_t phoneNumber[64];

        m_nameEdit->GetText(name, _countof(name));
        m_numberEdit->GetText(phoneNumber, _countof(phoneNumber));

        if (m_addMode)
            m_ownerDialog->AppendPhoneBookEntry(0, name, phoneNumber);
        else
            m_ownerDialog->ReplaceSelectedPhoneBookEntry(0, name, phoneNumber);

        m_ownerDialog->UpdateButtonStates();
        Close();
        return;
    }

    if (controlId == kCancelButton)
        Close();
}
```

Notes: exact dialog method names/control constants should be aligned with the wider dialog API pass. The add/edit mode meaning and owner flow are strong enough for child-page draft C++.

## Recommended Target Changes

Target file: `source-3/project-documentation/by-memory/0x0058c350-0x0058d74c.PhoneBookDialogs.md`

1. Change metadata:
   - `COMPLETION:88`
   - `CONFIDENCE:89`
   - Keep `CANONICAL_OWNER:0000MJ`
   - Keep `RECONSTRUCTABLE:TRUE`
   - Keep `EMITTER_UIDS:0000MJ`
   - Keep formal `RECONSTRUCTION_CPP` blank.
2. Update `Status`:
   - State that aggregate C++ remains blank by design because this page spans multiple source methods/classes and an existing exact child.
   - State that exact child pages should emit source bodies.
3. Replace/expand `Covered Ranges` with the full inventory from this report, including hidden retained helpers and padding.
4. Add a `Switch Table / Local Data` note for `0x0058ce18-0x0058ce30`.
5. Correct `0x0058cfe0` helper endpoint to half-open `0x0058d075` / inclusive last byte `0x0058d074`.
6. Add PE evidence:
   - no direct refs for retained helper starts.
   - rel32 refs for live calls listed above.
   - four-byte DialDialog successor padding.
7. Add `First-Draft C++ Readiness`:
   - [UID:0001JF] already emitted.
   - `SavePhoneBook`, `DialSelectedEntry`, `UpdateButtonStates`, `PhoneBookListPane::DialSelectedEntry`, `PhoneEntryDialog::UpdateButtonState`, and `PhoneEntryDialog::OnDialogAction` are draft-ready after exact child pages.
   - `RenderEntry` is behavior-ready with descriptive graphics helpers but should wait for palette/text helper naming before final audit.
   - Constructor is not formal-code-ready as an aggregate; split exact constructor page if supervisor wants it.
8. Add/update rejected alternatives:
   - generated `ChattingColorListPane` and `ArticleListPane` casts are historical pollution.
   - [UID:0001JL] is CRT/runtime glue, not a PhoneBook helper.
   - `entryFlags` nonzero semantics are not proven; neutral name accepted.

## Recommended Support-Doc Changes

### `by-file/PhoneBookDialog.md`

- Add missing retained helper inventory at `0x0058c9c0`, `0x0058ca70`, `0x0058cb30`, `0x0058ced0`, and `0x0058cf20`.
- Update "current recovered sources" wording to say current validator output only emits [UID:0001JF] plus empty markers; generated/simroot class files are search leads only.
- Replace the stale [UID:0001JL] wording with CRT/runtime wrapper no-code policy.
- Add that `PHONE.CFG` format is alternating name and phone-number lines, written with `%s\n` for each field.
- Optional after implementation: raise to `88/88` if these details are incorporated.

### `by-class/PhoneBookDialog.md`

- Add retained wrapper methods:
  - `AppendPhoneBookEntry` at `0x0058c9c0-0x0058ca63`
  - `ReplaceSelectedPhoneBookEntry` at `0x0058ca70-0x0058cb2e`
  - `RemoveSelectedPhoneBookEntry` at `0x0058cb30-0x0058cb5d`
- Add local `OnCommand` jump table `0x0058ce18-0x0058ce30`.
- Add high-probability field `m_phoneBookList` at `+0x1fc`.
- Add first-draft readiness notes for `SavePhoneBook`, `DialSelectedEntry`, and `UpdateButtonStates`.
- Optional after implementation: raise to `88/89`.

### `by-class/PhoneBookListPane.md`

- Add retained list helper `0x0058cf20-0x0058cf9a` as `AppendEntry` / `AddEntry`.
- Correct `0x0058cfe0` endpoint to half-open `0x0058d075`.
- Add endpoint/padding details for `0x0058d110-0x0058d11b` and `0x0058d120-0x0058d263`.
- Keep `m_ownerDialog` at `+0x14c`.
- Add first-draft readiness for `DialSelectedEntry`; add `RenderEntry` behavior-ready but helper-name-capped.
- Optional after implementation: raise to `87/89`.

### `by-class/PhoneEntryDialog.md`

- Replace open-ended field uncertainty with high-probability names:
  - `m_ownerDialog` at `+0x26c`
  - `m_addMode` / `m_isNewEntry` at `+0x270`
  - `m_nameEdit` and `m_numberEdit` for controls 3 and 4
- Add `PhoneBookContactEntry` add/edit row construction details and first-draft readiness for `UpdateButtonState` and `OnDialogAction`.
- Keep class-level C++ blank until inherited dialog/text/list API declarations are coordinated.
- Optional after implementation: raise to `86/89`.

### `by-item/PhoneBookListHelpers_58cfa0_58dcb0.md`

- Add a short cross-reference that this broader B007 pass discovered additional retained source helpers around `0x0058c9c0-0x0058d10e`; keep the item scope focused on [UID:0001JF] and [UID:0001JL].
- No metadata change required.

### `by-project-structure/proposed-source-tree.md`

- In the phone-book bullet, change `0x0058c350-0x0058dc5a` to `0x0058c350-0x0058dc5b`.
- Replace "`PhoneBookFormattedWriteHelper` remains a phone-book formatted-write helper under review" with: [UID:0001JL] is a CRT/runtime `fwprintf`-style wrapper and should remain no-code/no-owner while PhoneBook callers use normal CRT formatted output.
- Add that the phone-book block has retained no-direct-xref dialog/list wrappers and should emit through exact child pages rather than aggregate C++.

## Exact Coverage Text

Do not edit `by-memory/-coverage-report.md` directly. Replace the current [UID:0001JE] row in address order around line 3274 with:

```markdown
    - [UID:0001JE][0x0058c350-0x0058d74c.PhoneBookDialogs](by-memory/0x0058c350-0x0058d74c.PhoneBookDialogs.md) : reconstructable : 88% : strong : Phone-book dialog/list/entry source-family aggregate under [UID:0000MJ][PhoneBookDialog](by-file/PhoneBookDialog.md); B007 2026-06-19 source-quality recheck confirms boundary `0x0058c350-0x0058d74c`, DialDialog successor padding `0x0058d74c-0x0058d750`, direct calls to `SavePhoneBook`, `GetSelectedEntryData`, `PhoneEntryDialog`, and `DialDialog`, no direct refs for retained dialog/list helpers at `0x0058c9c0`, `0x0058ca70`, `0x0058cb30`, `0x0058ced0`, `0x0058cf20`, `0x0058cfe0`, `0x0058d080`, and `0x0058d090`, corrected raw helper tail/padding boundaries, `PhoneBookContactEntry` row layout and `PHONE.CFG` alternating name/number save behavior, CRT formatted-write wrapper exclusion, generated chat/article owner-pollution rejection, and aggregate C++ intentionally blank pending exact child-page emission for source-bearing methods.
```

If the supervisor later accepts exact child-page creation, additional child coverage rows should be inserted in address order for the new pages. This report does not assign UIDs to those not-yet-created pages.

## Validator Needs

No validator command was run because this was report-only and no by-* docs were edited.

Expected commands after accepted implementation, run from `source-3/project-documentation`:

> Executable block R001 was removed from this report and preserved verbatim in [0001JE-PhoneBookDialogs-source-quality-removed.md](0001JE-PhoneBookDialogs-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

If exact child pages are created in the callback, also run file-mode validator on each new child page after creation, then rerun the target aggregate and any edited class/file support pages.

## IDA Rename / Type / Comment Recommendations

These are documentation/IDA suggestions, not changes made in this report:

| Address / item | Recommended label/type/comment | Confidence |
| --- | --- | --- |
| `0x0058c9c0` | `PhoneBookDialog::AppendPhoneBookEntry` or `PhoneBookDialog_AppendPhoneBookEntry_retained` | medium-high |
| `0x0058ca70` | `PhoneBookDialog::ReplaceSelectedPhoneBookEntry` | medium-high |
| `0x0058cb30` | `PhoneBookDialog::RemoveSelectedPhoneBookEntry` / `DeleteSelectedEntry` | medium-high |
| `0x0058cb60` | `PhoneBookDialog::DialSelectedEntry` | high |
| `0x0058cc40` | `PhoneBookDialog::UpdateButtonStates` | high |
| `0x0058ccd0` | `PhoneBookDialog::OnCommand` | high |
| `0x0058ce18` | `PhoneBookDialog::OnCommand` jump table | high |
| `0x0058ce30` | `PhoneBookDialog::SavePhoneBook` | high |
| `0x0058ced0` | `PhoneBookListPane::Initialize` / `Setup` retained helper | medium-high |
| `0x0058cf20` | `PhoneBookListPane::AppendEntry` | medium-high |
| `0x0058cfa0` | `PhoneBookListPane::GetSelectedEntryData` | very high |
| `0x0058cfe0` | `PhoneBookListPane::ReplaceSelectedEntryData` | medium-high |
| `0x0058d080` | `PhoneBookListPane::RemoveSelectedEntry` | medium-high |
| `0x0058d090` | `PhoneBookListPane::SaveEntriesToPhoneCfg` | medium-high |
| `0x0058d110` | `PhoneBookListPane::DialSelectedEntry` | high |
| `0x0058d120` | `PhoneBookListPane::RenderEntry` | high |
| `0x0058d270` | `PhoneEntryDialog::PhoneEntryDialog` | high |
| `0x0058d540` | `PhoneEntryDialog::UpdateButtonState` | high |
| `0x0058d5a0` | `PhoneEntryDialog::OnDialogAction` | high |
| `0x0058dcb0` | `CrtWideFilePrintfWrapper` / runtime `fwprintf` adapter | very high no-code |
| row type | `PhoneBookContactEntry { unsigned char entryFlags; wchar_t name[64]; wchar_t phoneNumber[64]; }` | high |

Recommended comments:

- Comment no-xref retained helpers as source-authored retained methods, not padding.
- Comment [UID:0001JL] as runtime/CRT glue and warn not to route it to `PhoneBookDialog`.
- Comment `0x0058ce18-0x0058ce30` as the `OnCommand` jump table.

## Open Questions And Closure

- Exact original names of retained no-xref helpers: not provable from current evidence. Descriptive names above are high-probability and should be used in docs with "inferred/descriptive" wording.
- Nonzero `entryFlags` meaning: not resolved to a semantic bitfield; checked producer/consumer evidence supports the neutral field name and does not block child C++.
- Exact final shared `ListPane` API names: not original-proof. `GetEntryCount`/`GetEntryAt` are acceptable placeholders if docs identify them as descriptive wrappers for `0x004f3bd0`/`0x004f3dc0`.
- `RenderEntry` helper names: graphics/palette/text helpers remain the limiting issue for final audit. Behavior is clear enough for child-page documentation and a cautious draft, but not for aggregate formal C++.
- Original file split from `TerminalPane.cpp`: current evidence favors `PhoneBookDialog.cpp`; no stronger competing owner found.

## Changed Files

- Created: `source-3/project-documentation/tools/leaser/Agents/Agent-B007/research/0001JE-PhoneBookDialogs-source-quality.md`
- Modified: none
- Target/support by-* docs edited: none
- `by-memory/-coverage-report.md` edited: no

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B007","command_id":"000000004165","destination_path":"executed-b-agent-research/B007/0001JE-PhoneBookDialogs-source-quality.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:32","uid":"0001JE"} -->
<!-- {"agent":"B007","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 0001JE-PhoneBookDialogs-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B007/0001JE-PhoneBookDialogs-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"0001JE"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
