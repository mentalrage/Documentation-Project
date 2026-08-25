** TARGET-REPORT-UID:0002TW **
** AUTHOR-AGENT-ID:B002 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **

# 0002TW ArgumentedMenuMenuDialog Source-Quality Report

Agent: B002  
Assignment ID: `B002-report-0002TW-argumented-menu-menu-dialog-20260625`  
Target: `by-memory/0x0051e9a0-0x0051f28d.ArgumentedMenuMenuDialog.md`  
Mode: report-only research. No target/support by-* docs, generated files, coverage reports, validator state/cache, or IDA DB files were edited.

## Executive Recommendation

Update [UID:0002TW] from a documented but blank-code method cluster to a first-draft source-bearing `ArgumentedMenuMenuDialog` method page.

Recommended target metadata:

| Field | Current | Recommended |
| --- | ---: | ---: |
| `COMPLETION` | `86` | `89` |
| `CONFIDENCE` | `89` | `91` |
| `CANONICAL_OWNER` | `00000H` | `00000H` |
| `RECONSTRUCTABLE` | `TRUE` | `TRUE` |
| `EMITTER_UIDS` | `00000H` | `00000H` |
| formal C++ | blank | add first-draft constructor, command, and update methods |

Rationale: live IDA MCP now confirms the constructor/command/update boundaries, factory subtype route, vtable slots, resource/prompt refs, packet field order, list row construction, and command behavior. The formerly named blockers are now narrowed:

- packet byte `payload[0]` is best documented as `m_commandType` / argumented-menu command type at dialog `+0x274`;
- packet dword `payload[1..4]` is best documented as `m_ownerId` / dialog-owner id at dialog `+0x270`;
- the list parameter word after the converted dialog text feeds `ArgumentedMenuMenuItemList::m_listParameter`;
- inline item rows match accepted [UID:0003VH] `ArgumentedMenuItemEntry` field names exactly;
- command id `1` opens the buy-confirm pane, command id `2` calls the shared `TextMenuDialog::SendMenuRequestPacket` opcode `0x43` path, and command id `3` closes;
- `0x0051f250` is the action-button state updater using action control id `1`, list host id `6`, and shared `ListPane::GetSelectionCount`;
- raw island `0x0051f140-0x0051f158` remains a no-route, no-vtable-slot code-shaped caveat and should not become a named source method.

The raw island is not a reason to keep the whole target blank. It can be preserved in prose and as a comment/no-code marker inside the target formal block while the three live source methods emit.

## Current Target State

Current target header:

- `COMPLETION:86`
- `CONFIDENCE:89`
- `CANONICAL_OWNER:00000H`
- `RECONSTRUCTABLE:TRUE`
- `EMITTER_UIDS:00000H`
- blank `RECONSTRUCTION_CPP CODE`
- `Nested:4`

Stale target/support language that should be corrected during implementation:

- [UID:0002TW] still says C++ remains blank below an old `90/90+` reconstruction-code gate. Current `by-structure.md` uses the combined-score gate `(COMPLETION + CONFIDENCE) / 2 > 85` with a valid emitter route, and this target already clears that minimum.
- [UID:00000H] `ArgumentedMenuMenuDialog` repeats the same stale code-gate/no-C++ language and lacks class declaration C++ despite clearing the active minimum gate.
- [UID:0001BS] `ArgumentedMenuDialogs` still has an item summary saying final C++ is held below `95/95`; that should be replaced with the current split-index/source-bearing-child wording.
- `auto-generated/NexusTK/ui/dialogs/ArgumentedMenuDialogs.cpp` is stale relative to source docs: header command `000000001816`, refreshed `2026-06-25T17:10:40-04:00`, still lists [UID:00000H] as `82/84` and [UID:0002TW] as `76/86` empty emitter markers. Treat that generated file as an input to be refreshed by validator, not edited manually.
- `auto-generated/-ag-research-tracker.md` and `auto-generated/-ag-coverage-report-by-memory.md` also still show the stale `82/84` class and `76/86` target rows. Do not edit those reports by hand.

## Evidence Checked

Skill and rules:

- `.codex/skills/ntk-b-agent-workflow/SKILL.md`
- `.codex/skills/ntk-b-agent-workflow/references/b-agent-research-and-implementation-workflow.md`
- `.codex/skills/ntk-b-agent-workflow/references/supervisor-rule26-review-and-incorporation-standard.md`
- `by-structure.md`, especially the current combined-score C++ gate and by-memory range restrictions.
- `tools/int_convert_readme.md`

Target and support docs:

- [UID:0002TW] `by-memory/0x0051e9a0-0x0051f28d.ArgumentedMenuMenuDialog.md`
- [UID:00000H] `by-class/ArgumentedMenuMenuDialog.md`
- [UID:0000HI] `by-file/ArgumentedMenuDialogs.md`
- [UID:0001BS] `by-memory/0x0051e9a0-0x0051fc8d.ArgumentedMenuDialogs.md`
- [UID:00000I] `by-class/ArgumentedMenuMenuItemList.md`
- [UID:0003VG] `by-memory/0x0051f310-0x0051f37a.ArgumentedMenuMenuItemListRawContextConstructor.md`
- [UID:0003VH] `by-memory/0x0051f3c0-0x0051f44e.ArgumentedMenuMenuItemListRawAppendEntryHelper.md`
- [UID:0003VI] `by-memory/0x0051f450-0x0051f4fe.ArgumentedMenuOpenBuyConfirmDialog.md`
- [UID:0003VL] `by-memory/0x0051f640-0x0051f706.ArgumentedMenuSendItemQuantityPacket.md`
- [UID:000238] `by-memory/0x00517450-0x00517d23.MenuDialogFactoryHelpers.md`
- [UID:0000OP] `by-file/TextMenuDialogs.md`
- [UID:000320] `by-type/by-vtable/ArgumentedMenuDialogVtables.md`
- [UID:0001Y5] `by-type/by-vtable/MerchantMenuDialogVtableFamily.md`
- [UID:00025U] `by-memory/0x0061ec10-0x0061fa3c.MerchantMenuDialogReadOnlyData.md`
- Current generated files listed above, read only.
- Executed reports for context: B002 `0003VG`, B004 `0003VH`, B001 `0001BS`, B002 `0001BO`, and B001 `0001BR`.

Live IDA MCP evidence:

- MCP initialize succeeded with HTTP session `4fee46af-266c-4175-acfa-17b665497c67`.
- `idb_list`/current database: `80de0a67`, active worker session for `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`.
- `server_health(database='80de0a67')`: `status:"ok"`, module `NexusTK.exe`, input path `C:\Users\admin\Desktop\Clone\NexusTK\NexusTK.exe`, imagebase `0x400000`, auto-analysis ready, Hex-Rays ready, strings cache ready.
- `lookup_funcs`: `0x0051e9a0` is `sub_51E9A0`, size `0x796`; `0x0051f160` is `sub_51F160`, size `0xec`; `0x0051f250` is `sub_51F250`, size `0x3d`; successor `0x0051f290` is `sub_51F290`, size `0x7b`; `0x0051f140`, `0x0051f136`, `0x0051f28d`, and `0x0051f3c0` are not IDA function starts.
- `xrefs_to`: constructor `0x0051e9a0` has two code refs from `0x00517750` in `sub_517450` and `0x00517c97` in wrapper `sub_517C30`; raw island start `0x0051f140` has zero xrefs; command/update methods have only vtable data refs at `0x0061f470` and `0x0061f474`.
- `xrefs_to 0x0061f904`: `DLGMERC3.EPF` refs at `0x0051eded` and `0x0051f0dd` in this constructor, plus item-menu refs at `0x0051a945` and `0x0051ac35`.
- `xrefs_to 0x0061f930`: prompt refs at `0x0051f1db` in this command handler and `0x0051f48f` in the sibling buy-confirm helper.
- `entity_query names 0x0061f420-0x0061f590`: decorated vtable bases `ArgumentedMenuMenuDialog` at `0x0061f428`, `0x0061f488`, `0x0061f4b8`; `ArgumentedMenuMenuItemList` at `0x0061f4c4`, `0x0061f54c`, `0x0061f57c`; successor `ArgumentedItemQuantityInputDialogPane` at `0x0061f588`.
- `get_bytes 0x0061f428 size 80`: primary dialog vtable slot sequence ends with `0x0051f160` then `0x0051f250`, proving command/update slots and no `0x0051f140` slot.
- `disasm 0x0051f140`: IDA labels it `<no function>`; body loads `this+0x1fc`, pushes control id `7`, calls child virtual slot `+0x10`, loads returned object, and tail-jumps to `0x00498ca0`.
- `decompile 0x00498ca0`: tail target applies a non-null text/string pointer to an object member at `this[67]`; likely text-control update plumbing, but not enough to prove a live source method for the island.
- `decompile 0x00517c30`: wrapper builds rectangle `(100,100,416,455)`, allocates `0x278` bytes, and calls constructor `0x0051e9a0` with payload pointer and mode `0`.
- `decompile 0x00517ec0`: shared `TextMenuDialog::SendMenuRequestPacket` writes opcode `67` (`0x43`), subtype byte `1`, object/dialog id from `this[156]` (`+0x270`), sends six bytes through `g_packetSender`, then closes.
- `decompile 0x0051f160`: command id `1` fetches list host id `6`, checks selected index, gets selected row through `ListPane::GetEntryAt` / `0x004f3dc0`, copies prompt `Do you want to buy this?\n\nConfirm the price.`, allocates `0x27c` bytes for `ArgumentedItemConfirmInputDialogPane`, and passes `row+0x40c` maxQuantity, `row+0x004` price, and `row+0x408` argumentId. Command id `2` calls `0x00517ec0`; command id `3` calls close `0x0049dad0`.
- `decompile 0x0051f250`: fetches control id `1` and control id `6` through `this+0x1fc`, reads the list pointer at host `+0x108`, calls `ListPane::GetSelectionCount` / `0x004f3e20`, then tail-dispatches action-button virtual slot `+0x4c` when selected count is positive, otherwise slot `+0x50`.
- `decompile 0x0051e9a0`: constructor stores dialog vtables, stores mode byte at `+0x26c`, parses packet byte `+0` into `+0x274`, parses dword `+1` into `+0x270`, parses object/image data from `payload+6`, converts a length-prefixed multibyte dialog text block, reads a word list parameter, constructs `ArgumentedMenuMenuItemList` inline with `ListPane(0x410,0x10,0x16a,0x18,0,1,1)`, stores list context fields at `+0x14c/+0x150/+0x154/+0x158`, reads item count, loops item records, appends `ArgumentedMenuItemEntry` rows through `ListPane::AddEntry` at `0x004f3c50`, builds the `DLGMERC3.EPF` controls, sets focus/default/cancel state, applies the factory bounds, and attaches the dialog.

Numeric conversions:

- `0x278` = 632 bytes, dialog allocation size, verified with `tools/int_convert.py`.
- `0x796` = 1942 bytes, constructor size, verified with `tools/int_convert.py`.
- `0xec` = 236 bytes, command-handler size, verified with `tools/int_convert.py`.
- `0x3d` = 61 bytes, action-state updater size, verified with `tools/int_convert.py`.
- `0x410` = 1040 bytes, argumented item row stride, verified with IDA MCP `int_convert`.
- `0x16a` = 362 and `0x18` = 24 for list dimensions, verified with IDA MCP `int_convert`.
- `0x1fc` = 508 for the dialog control manager/child table pointer, verified with IDA MCP `int_convert`.
- `0x270` = 624 and `0x274` = 628 for `m_ownerId` and `m_commandType`, verified with IDA MCP `int_convert`.
- `0x39` = 57 for the selected argumented-item opcode used by list/purchase helpers, verified with IDA MCP `int_convert`.

## Boundary And Inventory Findings

| Range | Current IDA state | Source-facing disposition |
| --- | --- | --- |
| `0x0051e9a0-0x0051f136` | `sub_51E9A0`, size `0x796` | `ArgumentedMenuMenuDialog::ArgumentedMenuMenuDialog(const Rect&, const unsigned char*, unsigned char)` first-draft source-ready. |
| `0x0051f136-0x0051f140` | bytes `0xcc` | alignment, no source. |
| `0x0051f140-0x0051f158` | no IDA function, zero xrefs | unreferenced control-id `7` text-forwarding island; document as raw/no-route and do not promote to method. |
| `0x0051f158-0x0051f160` | alignment | no source. |
| `0x0051f160-0x0051f24c` | `sub_51F160`, size `0xec` | `ArgumentedMenuMenuDialog::HandleMenuCommand(int, void*)` first-draft source-ready. |
| `0x0051f24c-0x0051f250` | alignment | no source. |
| `0x0051f250-0x0051f28d` | `sub_51F250`, size `0x3d` | `ArgumentedMenuMenuDialog::UpdateActionButtonState()` first-draft source-ready. |
| `0x0051f28d-0x0051f290` | bytes `0xcc` | alignment before [UID:0003VF] list constructor. |

The existing target half-open boundary remains correct. No split or new child page is needed for this assignment. The raw island is too small and too unreferenced to justify a separate reconstructable source-bearing child; keeping it in this exact method-cluster page as a raw caveat is the least lossy route.

## Constructor Source Shape

The constructor signature is resolved enough for first-draft C++:

```cpp
ArgumentedMenuMenuDialog::ArgumentedMenuMenuDialog(
    const Rect& bounds,
    const unsigned char* payload,
    unsigned char menuMode);
```

Evidence:

- Factory dispatcher subtype `10` and wrapper `0x00517c30` both allocate `0x278` bytes and pass a bounds rectangle, payload pointer, and mode byte.
- Constructor stores `menuMode` at inherited dialog offset `+0x26c`.
- Constructor stores `payload[0]` at `+0x274`; this is best source-facing `m_commandType` because the inline list construction copies it to `ArgumentedMenuMenuItemList::m_commandType` and [UID:0003VL] serializes that field after opcode `0x39`.
- Constructor stores dword read from `payload+1` at `+0x270`; this is best source-facing `m_ownerId` because [UID:0003VL] serializes it as the owner/dialog id and command id `2` sends it through `TextMenuDialog::SendMenuRequestPacket`.
- Object/image data begins at `payload+6`; the parser returns the offset used to locate the length-prefixed dialog text. Exact helper spelling remains inferred, but the data-flow shape is clear.
- The word immediately after the converted dialog text is `listParameter`; it is stored in list field `m_listParameter` at `+0x154`.
- The constructor inline-constructs the list with the same base call, field stores, and vtable stores accepted for [UID:0003VG]. This proves the constructor and raw explicit-context overload use the same source shape.
- The item loop uses the same row field order accepted for [UID:0003VH]:
  - dword `argumentId`
  - word `itemId`
  - byte `itemStyle`
  - dword `price`
  - byte `maxQuantity`
  - byte length plus ANSI item name converted to UTF-16
  - one byte percent suffix value, with `0xff` meaning no suffix
  - empty description string for constructor-appended rows
  - append through `ListPane::AddEntry`.

Recommended source-facing names:

| Binary field/source | Recommended source name | Confidence | Notes |
| --- | --- | --- | --- |
| dialog `+0x270` | `m_ownerId` | strong inferred | Matches list context and packet helper consumption. |
| dialog `+0x274` | `m_commandType` | strong inferred | Matches list context and opcode `0x39` packet field. |
| post-text word | `listParameter` | strong inferred | Stored in `ArgumentedMenuMenuItemList::m_listParameter`. |
| item dword first field | `argumentId` | strong inferred | Used by confirm/quantity/packet helpers at row `+0x408`. |
| item word | `itemId` | strong | Used by item-image/draw helpers at row `+0x000`. |
| item byte | `itemStyle` | strong inferred | Draw helper style/type input at row `+0x002`. |
| item dword | `price` | strong inferred | Confirm prompt and draw formatting use row `+0x004`. |
| item final byte before name | `maxQuantity` | strong inferred | Confirm/quantity prompt and draw count use row `+0x40c`. |
| percent suffix byte | `percentSuffix` | medium-high inferred | Only display-name decoration; do not model as a row field. |

Rejected constructor alternatives:

- Leave packet fields as provisional: rejected. The list constructor, packet helper, and selected-row consumers give stable source-facing roles.
- Treat the inline list object as a generic `ListPane`: rejected. It installs `ArgumentedMenuMenuItemList` vtables and writes argumented-menu context fields.
- Treat the item percent byte as a row field: rejected. The constructor folds it into the display name by appending `L"(%d%%)"`; accepted [UID:0003VH] already says no separate row percent field.
- Move constructor ownership to `TextMenuDialogs`: rejected as direct owner. `TextMenuDialogs` owns the shared request helper and factory context, but this constructor installs `ArgumentedMenuMenuDialog` vtables and builds argumented item rows under [UID:0000HI].

## Command And Update Semantics

`HandleMenuCommand` should remain the source-facing method name. It matches the sibling item/spell menu docs and describes the virtual slot at `0x0061f470`.

Command behavior:

- command id `1`: fetch list host control id `6`, check selected index, get selected `ArgumentedMenuItemEntry`, copy the prompt `Do you want to buy this?\n\nConfirm the price.`, allocate `ArgumentedItemConfirmInputDialogPane` with prompt/list context/maxQuantity/price/argumentId, and do not close the parent dialog immediately.
- command id `2`: call `TextMenuDialog::SendMenuRequestPacket` at `0x00517ec0`, which writes opcode `0x43`, subtype byte `1`, and owner id `m_ownerId`, sends length `6`, then closes.
- command id `3`: close the dialog only.

`UpdateActionButtonState` should remain the source-facing name. It is the same vtable pattern used by item/spell menu dialogs:

- fetch action button control id `1`;
- fetch list host control id `6`;
- load embedded list pointer at host `+0x108`;
- call shared `ListPane::GetSelectionCount` / `0x004f3e20`;
- dispatch action-button enabled/disabled virtual slot.

Rejected alternatives:

- Route command id `2` to inherited `0x00517d80`: rejected. Live xrefs show command id `2` calls `0x00517ec0`; `0x00517d80` is inherited action-string virtual evidence in the vtable family.
- Treat the confirm dialog helper `0x0051f450` as the command id `1` target: rejected for this exact method. The command handler constructs `0x005200d0` inline; the sibling helper is a list-context helper with zero direct xrefs.
- Rename `UpdateActionButtonState` as a generic `ListPane` method: rejected. The vtable ref and control ids are dialog-class behavior; `ListPane::GetSelectionCount` is only a dependency.

## Raw Island Decision

The `0x0051f140-0x0051f158` body is source-shaped but currently unreachable:

- `lookup_funcs` says `0x0051f140` is not a function.
- `xrefs_to 0x0051f140` returns zero xrefs.
- Primary vtable bytes at `0x0061f428` include `0x0051f160` and `0x0051f250`, not `0x0051f140`.
- `disasm 0x0051f140` shows a tiny control-forwarding body: load dialog child/control table at `this+0x1fc`, fetch control id `7`, call child virtual slot `+0x10`, then tail-jump to `0x00498ca0`.
- `decompile 0x00498ca0` suggests a text/string update helper, which fits the description text control id `7`, but no caller or vtable route proves this island is live source.

Recommended handling:

- Keep the island inside [UID:0002TW]'s boundary evidence.
- Do not create a new child page and do not name it as a formal method.
- Add a short formal-block comment so generated source does not pretend this orphan is a real callable method.
- Keep the island as the reason confidence should not rise to final-audit level.

This is not a no-code proof for the whole target because the constructor, command handler, and updater are live and source-ready.

## Owner And Source Placement Ranking

| Candidate | Decision | Reason |
| --- | --- | --- |
| [UID:00000H] `ArgumentedMenuMenuDialog` | selected direct owner | Constructor stores class vtables, command/update are class vtable slots, and target range is a dialog method cluster. |
| [UID:0000HI] `ArgumentedMenuDialogs` | selected emitter/source file | File root owns argumented menu dialog/list family and staged path `NexusTK/ui/dialogs/ArgumentedMenuDialogs.cpp`. |
| [UID:0000OP] `TextMenuDialogs` | related support only | Owns shared request helper and factory context; current split keeps argumented menu classes in [UID:0000HI]. |
| [UID:00000I] `ArgumentedMenuMenuItemList` | callee/owned child context | Constructor builds and command/update operate on the list, but dialog methods are not list methods. |
| [UID:0000HH] `ArgumentedItemInputDialogs` | callee support only | Confirm pane is allocated by command id `1`; it does not own the command handler. |
| Generic `ListPane`/control infrastructure | dependency only | Supplies base/list/control helpers, but vtables and fields are argumented-menu dialog-specific. |

Final physical file split from `TextMenuDialogs.cpp` remains a packaging caveat, not a source-ownership blocker. Current docs already stage `ArgumentedMenuDialogs.cpp`, and exact source-bearing children for the list tail are under that file root.

## First-Draft C++ Recommendation

[UID:0002TW] clears the current formal C++ gate: it is reconstructable, has emitter route [UID:00000H] -> [UID:0000HI], and its current average score is already above `85`. After the accepted report details are incorporated, the target should emit first-draft method C++.

The following is exact recommended insertion text for [UID:0002TW]'s formal `RECONSTRUCTION_CPP CODE` block. Names are source-facing inferred names, not original symbol proof. Helper/type names such as `ReadMenuText`, `ReadMenuObjectImage`, and `CreateArgumentedMenuLayout` are high-level project source placeholders matching the accepted item-menu first-draft style; the implementation docs must preserve the evidence that those names are inferred.

```cpp
ArgumentedMenuMenuDialog::ArgumentedMenuMenuDialog(const Rect& bounds,
                                                   const unsigned char* payload,
                                                   unsigned char menuMode)
    : MerchantDialogPane(bounds, menuMode),
      m_ownerId(PacketBufferReadUInt32BE(payload + 1)),
      m_commandType(payload[0])
{
    MenuObjectImage objectImage;
    const unsigned char* cursor = ReadMenuObjectImage(payload + 6, objectImage);

    wchar_t dialogText[0x8000];
    cursor = ReadMenuText(cursor, dialogText, _countof(dialogText));

    const unsigned short listParameter = PacketBufferReadUInt16BE(cursor);
    cursor += sizeof(unsigned short);

    ArgumentedMenuMenuItemList* list =
        new ArgumentedMenuMenuItemList(m_commandType,
                                       m_ownerId,
                                       listParameter,
                                       this);

    const unsigned short itemCount = PacketBufferReadUInt16BE(cursor);
    cursor += sizeof(unsigned short);

    for (unsigned int i = 0; i < itemCount; ++i) {
        const unsigned int argumentId = PacketBufferReadUInt32BE(cursor);
        cursor += sizeof(unsigned int);

        const unsigned short itemId = PacketBufferReadUInt16BE(cursor);
        cursor += sizeof(unsigned short);

        const unsigned char itemStyle = *cursor++;

        const unsigned int price = PacketBufferReadUInt32BE(cursor);
        cursor += sizeof(unsigned int);

        const unsigned char maxQuantity = *cursor++;
        const unsigned char nameLength = *cursor++;

        wchar_t itemName[256];
        cursor = ReadMenuText(cursor, nameLength, itemName, _countof(itemName));

        const unsigned char percentSuffix = *cursor++;
        if (percentSuffix != 0xff) {
            wchar_t suffix[256];
            swprintf_s(suffix, _countof(suffix), L"(%d%%)", percentSuffix);
            wcscat_s(itemName, _countof(itemName), suffix);
        }

        list->AppendItem(itemId,
                         itemStyle,
                         price,
                         itemName,
                         L"",
                         argumentId,
                         maxQuantity);
    }

    CreateArgumentedMenuLayout(kArgumentedMenuLayout,
                               objectImage,
                               dialogText,
                               list);
    SetFocusedControl(6);
    SetDefaultCommand(1);
    SetCancelCommand(3);
    ApplyMenuDialogBounds(bounds, L"DLGMERC3.EPF");
}

// Raw no-route island 0x0051f140-0x0051f158 is intentionally not modeled as
// a callable source method. Current IDA has no function object, no xrefs to the
// start, and no ArgumentedMenuMenuDialog vtable slot for it.

void ArgumentedMenuMenuDialog::HandleMenuCommand(int commandId, void* context)
{
    UNREFERENCED_PARAMETER(context);

    switch (commandId) {
    case 1:
        if (ArgumentedMenuMenuItemList* list = GetArgumentedMenuList(6)) {
            const ArgumentedMenuItemEntry* entry = list->GetSelectedEntry();
            if (entry != NULL) {
                wchar_t prompt[128];
                wcscpy_s(prompt,
                         _countof(prompt),
                         L"Do you want to buy this?\n\nConfirm the price.");

                new ArgumentedItemConfirmInputDialogPane(prompt,
                                                         list,
                                                         entry->maxQuantity,
                                                         entry->price,
                                                         entry->argumentId);
            }
        }
        break;

    case 2:
        TextMenuDialog::SendMenuRequestPacket(m_ownerId);
        break;

    case 3:
        CloseDialog();
        break;
    }
}

void ArgumentedMenuMenuDialog::UpdateActionButtonState()
{
    ControlPane* actionButton = GetControl(1);
    ArgumentedMenuMenuItemList* list = GetArgumentedMenuList(6);
    const bool hasSelection = list != NULL && list->GetSelectionCount() > 0;

    if (actionButton != NULL)
        actionButton->SetEnabled(hasSelection);
}
```

Recommended declaration-level C++ insertion for [UID:00000H] `by-class/ArgumentedMenuMenuDialog.md`:

```cpp
class ArgumentedMenuMenuDialog : public MerchantDialogPane
{
public:
    ArgumentedMenuMenuDialog(const Rect& bounds,
                             const unsigned char* payload,
                             unsigned char menuMode);

protected:
    void HandleMenuCommand(int commandId, void* context);
    void UpdateActionButtonState();

private:
    unsigned int m_ownerId;       // +0x270
    unsigned char m_commandType;  // +0x274
    unsigned char m_padding275[3];

    [[CHILDREN]]
};
```

No new by-memory child formal C++ is needed for this report. The existing [UID:0003VG] and [UID:0003VH] list-child formal blocks remain the authoritative constructor/append support for the list class.

## Score Rationale

Recommended [UID:0002TW] `89/91`:

- Completion rises because this report resolves the active field/API/helper naming blockers, records current MCP evidence, replaces the stale code-gate/no-C++ rationale, and supplies first-draft formal C++ for all live source methods in the range.
- Confidence rises because constructor, command, and update behavior now triangulate through live decompile, vtable slots, resource/string xrefs, list-child field docs, and sibling item/spell menu precedent.
- Confidence stays below `95` because helper/type spellings for UI layout, menu-object image parsing, and exact original API names remain inferred, and the raw island remains no-route code-shaped bytes.

Recommended [UID:00000H] class page `88/90`:

- Add declaration-level C++ with `m_ownerId` and `m_commandType`.
- Update method map/source-quality notes to say method-body C++ lives on [UID:0002TW].
- Keep final physical source split caveat, but remove the old `90/90+` blocker.

Recommended [UID:0000HI] file page `88/91`:

- Add that [UID:0002TW] is now first-draft source-bearing, alongside [UID:0003VG] and [UID:0003VH].
- Preserve the file root as an ownership bucket and the final `TextMenuDialogs.cpp` fold as a packaging caveat only.

Recommended [UID:0001BS] aggregate `88/90` score unchanged:

- It is already a non-emitting split index. Update stale item summary/prose only, especially "final C++ held below 95/95" and the [UID:0002TW] row.

Recommended [UID:000320] vtable page `87/91`:

- Add slot-role detail for `ArgumentedMenuMenuDialog` primary table: `0x0061f470 -> HandleMenuCommand` and `0x0061f474 -> UpdateActionButtonState`, plus the explicit no-slot evidence for `0x0051f140`.

## Recommended Target And Support Doc Changes

Implement only after supervisor acceptance.

1. `by-memory/0x0051e9a0-0x0051f28d.ArgumentedMenuMenuDialog.md`
   - Change score to `89/91`.
   - Replace stale `90/90+` code-gate text with current combined-score/emitter gate language.
   - Add current MCP session/database evidence summarized above.
   - Add constructor packet field map and `ArgumentedMenuItemEntry` inline row construction details.
   - Add raw island decision as no-route/no-vtable/no-method, not whole-target no-code.
   - Insert the formal target C++ block from this report.
   - Update item summary to mention first-draft C++ and the raw island caveat.

2. `by-class/ArgumentedMenuMenuDialog.md`
   - Change score to `88/90`.
   - Insert declaration-level C++ block from this report.
   - Add field notes for inherited mode byte `+0x26c`, `m_ownerId +0x270`, `m_commandType +0x274`, and padding `+0x275..+0x277`.
   - Update method map to say [UID:0002TW] now emits first-draft method bodies.
   - Remove old `90/90+` blocker wording.

3. `by-file/ArgumentedMenuDialogs.md`
   - Change score to `88/91`.
   - Update contents/status to say [UID:0002TW] now emits first-draft `ArgumentedMenuMenuDialog` method C++.
   - Preserve file-root C++ blank because it is an ownership bucket.
   - Preserve final physical fold into [UID:0000OP] as only a packaging caveat.

4. `by-memory/0x0051e9a0-0x0051fc8d.ArgumentedMenuDialogs.md`
   - Keep metadata score unchanged unless supervisor chooses to raise after implementation.
   - Update stale item summary/prose that says final C++ is held below `95/95`.
   - Update [UID:0002TW] covered-row/support text to note first-draft formal C++ now lives on the exact dialog child.

5. `by-type/by-vtable/ArgumentedMenuDialogVtables.md`
   - Change score to `87/91`.
   - Add slot-role support for `ArgumentedMenuMenuDialog` command/update slots.
   - Add negative evidence that no vtable slot targets raw `0x0051f140`.

6. Optional support sync only if supervisor wants additional cross-reference polish:
   - `by-class/ArgumentedMenuMenuItemList.md`: add that owning dialog [UID:0002TW] now emits constructor code that inline-builds the same `ArgumentedMenuItemEntry` row layout accepted by [UID:0003VH].
   - `by-memory/0x00517450-0x00517d23.MenuDialogFactoryHelpers.md`: no score change; optionally note the subtype `10` constructor route now has first-draft target C++.
   - `by-memory/0x0061ec10-0x0061fa3c.MerchantMenuDialogReadOnlyData.md`: no score change; current `DLGMERC3.EPF` and prompt string ownership evidence is already sufficient.

No manual `-coverage-report.md` text is required. The implementation should update source docs and let the validator/autogen refresh generated rows.

## Validator And Generated Refresh Expectations

Expected scoped validator commands after implementation, from `source-3/project-documentation`:

> Executable block R001 was removed from this report and preserved verbatim in [0002TW-ArgumentedMenuMenuDialog-source-quality-removed.md](0002TW-ArgumentedMenuMenuDialog-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

If optional support docs are edited, run the same file-mode validator for each touched support page.

Generated refresh expectations:

- `auto-generated/NexusTK/ui/dialogs/ArgumentedMenuDialogs.cpp` should refresh from stale empty emitter markers to include [UID:00000H] declaration C++ and [UID:0002TW] method C++, while preserving existing [UID:0003VG] and [UID:0003VH] child C++.
- `auto-generated/-ag-research-tracker.md` and `auto-generated/-ag-coverage-report-by-memory.md` should update through validator/report execution/autogen, not manual edits.
- Current validator queue status during research: command `python .\tools\validator.py --queue-status` returned `command_id: 000000001820`, timestamp `2026-06-25T17:19:50-04:00`, worker running, zero queued jobs, zero processing jobs.

## Remaining Caveats

- Exact original spellings for UI/layout helper APIs are not recovered. The first-draft block uses source-facing inferred names consistent with accepted item-menu method pages.
- The raw island could represent a retained/unreferenced text-control helper or linker/orphan body, but current evidence does not prove reachability. It must remain documented and unpromoted.
- The final physical packaging choice between `ArgumentedMenuDialogs.cpp` and a broader `TextMenuDialogs.cpp` fold remains open. Current ownership/emitter route through [UID:0000HI] is still the correct documentation and generated-output route.
- The first-draft constructor abstracts a long series of concrete control allocations into source-style layout helpers. That is acceptable for this score range, but a future high-90s audit must reconcile exact control class names, layout helper declarations, and resource wrapper APIs.

## Implementation Tracking Checklist

Implementation callback proof, 2026-06-25:

- [x] Update `by-memory/0x0051e9a0-0x0051f28d.ArgumentedMenuMenuDialog.md`: metadata `86/89 -> 89/91`, current gate wording, MCP evidence, constructor packet/row field map, raw island no-route proof, formal first-draft C++, item summary, and changes note. Proof: target page now has `COMPLETION:89`, `CONFIDENCE:91`, formal constructor/command/update C++ block, updated Item Summary, constructor packet/row map, 2026-06-25 MCP evidence, and 2026-06-25 changes note. Validator `python .\tools\validator.py --mode file --file by-memory\0x0051e9a0-0x0051f28d.ArgumentedMenuMenuDialog.md --apply --queue-timeout 240` exited `0`, `command_id: 000000001879`, `command_timestamp: 2026-06-25T17:51:04-04:00`, `ok: 1`; warning side effects were missing registry refs for `0003VL`/`0003VH`, generated refresh deferred.
- [x] Update `by-class/ArgumentedMenuMenuDialog.md`: metadata `85/87 -> 88/90`, declaration-level C++, field layout `+0x26c/+0x270/+0x274`, method-body route through [UID:0002TW], stale code-gate removal, and changes note. Proof: class page now has `COMPLETION:88`, `CONFIDENCE:90`, declaration-level C++ block, Field Layout table, updated split/reconstruction state, and 2026-06-25 changes note. Validator `python .\tools\validator.py --mode file --file by-class\ArgumentedMenuMenuDialog.md --apply --queue-timeout 240` exited `0`, `command_id: 000000001880`, `command_timestamp: 2026-06-25T17:51:20-04:00`, `ok: 1`; generated refresh deferred.
- [x] Update `by-file/ArgumentedMenuDialogs.md`: metadata `87/90 -> 88/91`, contents/status note that [UID:0002TW] now emits first-draft C++, preserve file-root blank C++ and final physical fold caveat, and changes note. Proof: file page now has `COMPLETION:88`, `CONFIDENCE:91`, status/proposed-contents/autogen notes for [UID:0002TW] as first-draft source-bearing, file-root C++ remains blank as an ownership bucket, and 2026-06-25 changes note. Validator `python .\tools\validator.py --mode file --file by-file\ArgumentedMenuDialogs.md --apply --queue-timeout 240` exited `0`, `command_id: 000000001881`, `command_timestamp: 2026-06-25T17:51:25-04:00`, `ok: 1`; existing missing child UID registry warnings remained, generated refresh deferred.
- [x] Update `by-memory/0x0051e9a0-0x0051fc8d.ArgumentedMenuDialogs.md`: keep split-index metadata unless supervisor decides otherwise, remove stale `95/95`/blank-C++ phrasing for [UID:0002TW], record that exact child now emits method C++, and preserve non-emitting aggregate policy. Proof: aggregate page stayed `88/90`, Item Summary and covered row now say it is a non-emitting split index with [UID:0002TW] first-draft source-bearing, and 2026-06-25 changes note preserves aggregate no-code policy. Validator `python .\tools\validator.py --mode file --file by-memory\0x0051e9a0-0x0051fc8d.ArgumentedMenuDialogs.md --apply --queue-timeout 240` exited `0`, `command_id: 000000001882`, `command_timestamp: 2026-06-25T17:51:33-04:00`, `ok: 1`; existing missing child UID registry warnings remained, generated refresh deferred.
- [x] Update `by-type/by-vtable/ArgumentedMenuDialogVtables.md`: metadata `86/90 -> 87/91`, add command/update slot-role detail, record no-vtable-slot evidence for raw `0x0051f140`, and changes note. Proof: vtable page now has `COMPLETION:87`, `CONFIDENCE:91`, slot table for `0x0061f470 -> 0x0051f160` and `0x0061f474 -> 0x0051f250`, explicit no-slot/no-function/no-xref raw island evidence, score rationale, and changes note. Validator `python .\tools\validator.py --mode file --file by-type\by-vtable\ArgumentedMenuDialogVtables.md --apply --queue-timeout 240` exited `0`, `command_id: 000000001883`, `command_timestamp: 2026-06-25T17:51:38-04:00`, `ok: 1`; existing missing child UID registry warnings remained, generated refresh deferred.
- [x] Optional if accepted: add a short support sync in `by-class/ArgumentedMenuMenuItemList.md` that [UID:0002TW] now emits constructor code using the accepted `ArgumentedMenuItemEntry` row layout. Proof: support page now records the 2026-06-25 B002 sync in Evidence Notes and Changes. Validator `python .\tools\validator.py --mode file --file by-class\ArgumentedMenuMenuItemList.md --apply --queue-timeout 240` exited `0`, `command_id: 000000001884`, `command_timestamp: 2026-06-25T17:51:47-04:00`, `ok: 1`; existing missing child UID registry warnings remained, generated refresh deferred.
- [x] Optional if accepted: add a no-score-change cross-reference in `by-memory/0x00517450-0x00517d23.MenuDialogFactoryHelpers.md` for subtype `10` target C++ readiness. Proof: subtype `10` dispatch row now links [UID:0002TW] as first-draft source-bearing and Changes records the no-score-change sync. Validator `python .\tools\validator.py --mode file --file by-memory\0x00517450-0x00517d23.MenuDialogFactoryHelpers.md --apply --queue-timeout 240` exited `0`, `command_id: 000000001885`, `command_timestamp: 2026-06-25T17:51:54-04:00`, `ok: 1`; existing missing `00040D`/`00040E` registry warnings remained, generated refresh deferred.
- [x] Do not edit generated reports, project-level generated files, validator state/cache, IDA DB, or any `-coverage-report.md`. Proof: manual edits were limited to listed by-* docs and this B002 report checklist. Validator commands produced expected tool-owned side effects, including `projected_stats_update` to `project-level/-auto-completion-stats.md`, autogen registry updates, and deferred generated refresh; no generated/report/project-level/coverage/tool-state/IDA files were manually edited.
- [x] Lease only immediate implementation files during callback, then release leases immediately after the edit/validator batch. Proof: B002 leased only the seven by-* files edited, reacquired after the first lease batch reached expiry during validation, and released all seven with `python .\tools\leaser\leaser.py B002 unlease ...`; `tools/leaser/Agents/current_leases.md` readback after release shows no B002 leases.
- [x] Run scoped validators listed in this report for every edited by-* file. Record each command, `command_id`, `command_timestamp`, exit code, `ok` count, warnings, and generated-refresh state. Proof: validators for all five required pages plus the two optional touched pages are recorded in the checklist items above; every command exited `0` with `ok: 1`. Warnings were missing-ref UID registry diagnostics already outside this callback's manual-edit scope. Each validator reported `generated_refresh: deferred`.
- [x] Confirm generated `auto-generated/NexusTK/ui/dialogs/ArgumentedMenuDialogs.cpp` header is equal/newer than the validator command metadata if supervisor asks to inspect generated C++ before execution. Proof: queue status `python .\tools\validator.py --queue-status` returned `command_id: 000000001886`, `command_timestamp: 2026-06-25T17:52:07-04:00`, worker running, zero queued/processing jobs, zero generated refresh jobs. Generated `auto-generated/NexusTK/ui/dialogs/ArgumentedMenuDialogs.cpp` header shows `validator-command-id: 000000001884`, `validator-refreshed-at: 2026-06-25T17:51:47-04:00`, and contains [UID:00000H] declaration C++ plus [UID:0002TW] method C++; this is newer than the target/class/file validator commands that introduced the emitted code.
- [x] Update this checklist with checkmarks and proof during implementation callback. Proof: this checked implementation proof block was added after doc edits, validator runs, generated queue/header check, and lease cleanup.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B002","command_id":"000000004165","destination_path":"executed-b-agent-research/B002/0002TW-ArgumentedMenuMenuDialog-source-quality.md","details":"legacy registry reconstruction","event":"executed","source_path":"tools/leaser/Agents/Agent-B002/research/0002TW-ArgumentedMenuMenuDialog-source-quality.md","timestamp":"2026-06-25T17:57:46","uid":"0002TW"} -->
<!-- {"agent":"B002","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 0002TW-ArgumentedMenuMenuDialog-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B002/0002TW-ArgumentedMenuMenuDialog-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"0002TW"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
