** TARGET-REPORT-UID:0001BR **
** AUTHOR-AGENT-ID:B001 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# [UID:0001BR] SpellMenuDialogs Source-Quality Reanalysis

Agent: B001  
Assignment ID: `B001-report-spell-menu-dialogs-source-quality-0001BR-mcp-20260623`  
Target: `by-memory/0x0051ca40-0x0051e998.SpellMenuDialogs.md`  
Report path: `tools/leaser/Agents/Agent-B001/research/0001BR-SpellMenuDialogs-source-quality.md`  
Mode: report-only research; no target/support by-* edits performed.

## Executive Recommendation

Change [UID:0001BR] from a reconstructable broad emitter into a reviewed non-emitting split index:

| Field | Current | Recommended |
| --- | --- | --- |
| `COMPLETION` | `88` | `90` |
| `CONFIDENCE` | `86` | `92` |
| `CANONICAL_OWNER` | `0000O2` | `0000O2` |
| `RECONSTRUCTABLE` | `TRUE` | `FALSE` |
| `EMITTER_UIDS` | `0000O2` | blank |
| formal aggregate C++ | blank | blank, with no-code proof |

Reason: the target is not one source method or one coherent C++ declaration. It is a compact physical source-family range containing two dialog classes, two private list classes, modeled methods, raw no-function helper bodies, and internal alignment. The current aggregate can be a high-confidence source-family map, but exact child pages should own emission. This follows the already accepted project pattern for [UID:0001BO] `ItemMenuDialogs` and [UID:0001BS] `ArgumentedMenuDialogs`.

Create four source-bearing child pages under [UID:0000O2] `SpellMenuDialogs`:

| Proposed child | Range | Direct owner | Emitter | Formal C++ |
| --- | --- | --- | --- | --- |
| `ServerSpellMenuDialogMethods` | `0x0051ca40-0x0051d6fd` | [UID:0000D3] `ServerSpellMenuDialog` | [UID:0000O2] | yes |
| `ServerSpellMenuItemList` | `0x0051d700-0x0051db38` | [UID:0000D4] `ServerSpellMenuItemList` | [UID:0000O2] | yes |
| `ClientSpellMenuDialogMethods` | `0x0051db40-0x0051e63d` | [UID:00002R] `ClientSpellMenuDialog` | [UID:0000O2] | yes |
| `ClientSpellMenuItemList` | `0x0051e640-0x0051e998` | [UID:00002S] `ClientSpellMenuItemList` | [UID:0000O2] | yes |

Also reclassify [UID:0000VH] `SpellMenuActionButtonState_51d6c0_51e600` as a non-emitting support/index page once the server/client dialog method children own the two update helpers. It should keep the evidence, but it should not emit duplicate C++.

## Current State Checked

Current target header:

- `COMPLETION:88`
- `CONFIDENCE:86`
- `CANONICAL_OWNER:0000O2`
- `RECONSTRUCTABLE:TRUE`
- `EMITTER_UIDS:0000O2`
- blank `RECONSTRUCTION_CPP CODE`

Current generated root:

- `auto-generated/NexusTK/ui/dialogs/SpellMenuDialogs.cpp` is not zero bytes; it contains only generated empty-emitter markers for [UID:00002R], [UID:00002S], [UID:0000D3], [UID:0000D4], [UID:0000VH], [UID:0001BR], and [UID:00031X].
- `auto-generated/-ag-memory-coverage.md` currently marks [UID:0001BR] as `emits`, owner/emitter `0000O2`, `has_code:no`.
- `project-level/-auto-completion-stats.md` currently records [UID:0001BR] as `88/86` and [UID:0000VH] as `86/91`.

The current target and by-file page still name [UID:0001Y5] `MerchantMenuDialogVtableFamily` as the primary vtable/layout anchor. That is stale as a primary anchor. The mixed parent remains useful context, but the owner-specific direct anchor is [UID:00031X] `SpellMenuDialogVtables`, which already maps only `ServerSpellMenuDialog`, `ServerSpellMenuItemList`, `ClientSpellMenuDialog`, and `ClientSpellMenuItemList` to [UID:0000O2].

## MCP Evidence

MCP was mandatory and available. I used session `80de0a67`.

Health check:

- `server_health(database='80de0a67')` returned `status:"ok"`.
- IDB path: `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`.
- Module: `NexusTK.exe`.
- Input path: `C:\Users\admin\Desktop\Clone\NexusTK\NexusTK.exe`.
- Imagebase: `0x400000`.
- Hex-Rays ready: `true`.
- Strings cache ready: `true`.
- Local file MD5 for the input executable: `4247E04E20B65D6414C7238AA8FF5515`.

Function boundary refresh:

| Address | MCP result | Recommended interpretation |
| --- | --- | --- |
| `0x0051ca40` | `sub_51CA40`, size `0xada` | `ServerSpellMenuDialog` constructor, half-open `0x0051ca40-0x0051d51a`. |
| `0x0051d520` | `sub_51D520`, size `0x192` | `ServerSpellMenuDialog::HandleMenuCommand`, half-open `0x0051d520-0x0051d6b2`. |
| `0x0051d6c0` | `sub_51D6C0`, size `0x3d` | `ServerSpellMenuDialog::UpdateActionButtonState`, half-open `0x0051d6c0-0x0051d6fd`. |
| `0x0051d700` | `sub_51D700`, size `0x6c` | `ServerSpellMenuItemList` constructor, half-open `0x0051d700-0x0051d76c`. |
| `0x0051da20` | `sub_51DA20`, size `0x0b` | `ServerSpellMenuItemList::NotifyOwnerSpellActivated`, half-open `0x0051da20-0x0051da2b`. |
| `0x0051da30` | `sub_51DA30`, size `0x108` | `ServerSpellMenuItemList::DrawListEntry`, half-open `0x0051da30-0x0051db38`. |
| `0x0051db40` | `sub_51DB40`, size `0x993` | `ClientSpellMenuDialog` constructor, half-open `0x0051db40-0x0051e4d3`. |
| `0x0051e4e0` | `sub_51E4E0`, size `0x112` | `ClientSpellMenuDialog::HandleMenuCommand`, half-open `0x0051e4e0-0x0051e5f2`. |
| `0x0051e600` | `sub_51E600`, size `0x3d` | `ClientSpellMenuDialog::UpdateActionButtonState`, half-open `0x0051e600-0x0051e63d`. |
| `0x0051e640` | `sub_51E640`, size `0x6c` | `ClientSpellMenuItemList` constructor, half-open `0x0051e640-0x0051e6ac`. |
| `0x0051e880` | `sub_51E880`, size `0x0b` | `ClientSpellMenuItemList::NotifyOwnerSpellActivated`, half-open `0x0051e880-0x0051e88b`. |
| `0x0051e890` | `sub_51E890`, size `0x108` | `ClientSpellMenuItemList::DrawListEntry`, half-open `0x0051e890-0x0051e998`. |
| `0x0051e998` | not a function | `0xcc` alignment before [UID:0001BS]. |
| `0x0051e9a0` | `sub_51E9A0`, size `0x796` | `ArgumentedMenuMenuDialog`, outside this spell-menu range. |
| `0x004f3e20` | `sub_4F3E20`, size `0x54` | shared `ListPane::GetSelectionCount`, not spell-owned. |
| `0x00482fb0` | `sub_482FB0`, size `0x256` | real `ChattingColorListPane` constructor, not used by spell menu. |

Boundary bytes:

- `0x0051d51a-0x0051d520`, `0x0051d6b2-0x0051d6c0`, `0x0051d6fd-0x0051d700`, `0x0051e4d3-0x0051e4e0`, `0x0051e5f2-0x0051e600`, `0x0051e63d-0x0051e640`, and `0x0051e998-0x0051e9a0` are `0xcc` padding.
- The existing target table should be corrected from end addresses such as `0x0051d519`, `0x0051d6b1`, and `0x0051e4d2` to half-open function endpoints.

Owner-specific vtables:

`entity_query(kind='names', min_addr='0x0061f160', max_addr='0x0061f430')` returned exactly the spell-menu vtable names before the argumented-menu successor:

- `0x0061f168`, `0x0061f1c8`, `0x0061f1f8`: `ServerSpellMenuDialog`.
- `0x0061f204`, `0x0061f28c`, `0x0061f2bc`: `ServerSpellMenuItemList`.
- `0x0061f2c8`, `0x0061f328`, `0x0061f358`: `ClientSpellMenuDialog`.
- `0x0061f364`, `0x0061f3ec`, `0x0061f41c`: `ClientSpellMenuItemList`.
- `0x0061f428`: `ArgumentedMenuMenuDialog` successor outside the spell owner-specific child.

Xref evidence:

| Target | MCP xrefs |
| --- | --- |
| `0x0051ca40` | code refs from `0x005176c3` in `sub_517450` and `0x00517b77` in `sub_517B10`. |
| `0x0051db40` | code refs from `0x0051770b` in `sub_517450` and `0x00517c07` in `sub_517BA0`. |
| `0x0051d700` | code refs from `0x0051cbee` and `0x0051d131`, both inside `ServerSpellMenuDialog` construction. |
| `0x0051e640` | code refs from `0x0051dce7` and `0x0051e189`, both inside `ClientSpellMenuDialog` construction. |
| `0x0051d520` | data/vtable-only ref at `0x0061f1b0`. |
| `0x0051d6c0` | data/vtable-only ref at `0x0061f1b4`. |
| `0x0051e4e0` | data/vtable-only ref at `0x0061f310`. |
| `0x0051e600` | data/vtable-only ref at `0x0061f314`. |
| `0x0051da20` | data/vtable-only ref at `0x0061f280`. |
| `0x0051da30` | data/vtable-only ref at `0x0061f284`. |
| `0x0051e880` | data/vtable-only ref at `0x0061f3e0`. |
| `0x0051e890` | data/vtable-only ref at `0x0061f3e4`. |
| `0x004f3e20` | 14 code refs across list-based UI update helpers, including `0x0051d6e8` and `0x0051e628`. |
| `0x00482fb0` | only chat-color constructor callers `0x00482837` and `0x0048295d`, both inside `sub_4824E0`; no spell-menu callers. |

The broad listing search I attempted for raw helper start immediates timed out client-side after the direct `xrefs_to` batch completed. A post-timeout `server_health` check still returned `status:"ok"`, so I treated that broad listing search as nonessential and did not use it as proof. The direct IDA xref result is the controlling current evidence for the raw helper starts.

## Split Findings

The existing target and class pages omit source-shaped raw no-function helper bodies between the list constructors and the modeled activation/draw virtuals. These are not padding and not compiler-only glue.

### Server List Body Map

| Range | IDA status | Source-facing role | Evidence |
| --- | --- | --- | --- |
| `0x0051d700-0x0051d76c` | modeled function | `ServerSpellMenuItemList` constructor | Calls `ListPane::ListPane(514, 16, 228, 12, 0, 1, 1)` and stores context at `+0x14c/+0x150/+0x154/+0x158`. |
| `0x0051d76c-0x0051d770` | padding | no source | `0xcc`. |
| `0x0051d770-0x0051d7c8` | raw no-function body | `AppendSpellName` | Builds a `0x202` row: word at `+0`, UTF-16 name at `+2`, calls `ListPane::AddEntry`. |
| `0x0051d7c8-0x0051d7d0` | padding | no source | `0xcc`. |
| `0x0051d7d0-0x0051d8fd` | raw no-function body | `SendSelectedSpellName` | Uses selected index `+0x134`, `ListPane::GetItem`, row text at `+2`, opcode `0x39`, context fields `+0x14c/+0x150/+0x154`, and sends length `wide-name-byte-length + 9`. |
| `0x0051d8fd-0x0051d900` | padding | no source | `0xcc`. |
| `0x0051d900-0x0051da1f` | raw no-function body | `SendSpellName` | Explicit-name opcode `0x39` send helper with same packet shell and `ret 4`. |
| `0x0051da1f-0x0051da20` | padding | no source | `0xcc`. |
| `0x0051da20-0x0051da2b` | modeled function | `NotifyOwnerSpellActivated` | Loads owner at `+0x158` and tail-jumps to shared owner state update at `0x49de70`. |
| `0x0051da2b-0x0051da30` | padding | no source | `0xcc`. |
| `0x0051da30-0x0051db38` | modeled function | `DrawListEntry` | Draws text from row `+2`, selection fill/color, ellipsis fitting, and `DrawTextInRect`. |
| `0x0051db38-0x0051db40` | padding | no source | `0xcc`. |

`xrefs_to` for raw starts `0x0051d770`, `0x0051d7d0`, and `0x0051d900` returned zero direct refs. They still deserve source-bearing child coverage because they are complete retained class helper bodies, match the list row model, and mirror the accepted `ClientItemMenuItemList` raw helper treatment.

### Client List Body Map

| Range | IDA status | Source-facing role | Evidence |
| --- | --- | --- | --- |
| `0x0051e640-0x0051e6ac` | modeled function | `ClientSpellMenuItemList` constructor | Calls `ListPane::ListPane(516, 16, 228, 12, 0, 1, 1)` and stores context at `+0x14c/+0x150/+0x154/+0x158`. |
| `0x0051e6ac-0x0051e6b0` | padding | no source | `0xcc`. |
| `0x0051e6b0-0x0051e711` | raw no-function body | `AppendSpell` | Builds a `0x204` row: one-byte spell slot at `+0`, natural padding at `+1`, word field at `+2`, UTF-16 name at `+4`, calls `ListPane::AddEntry`. |
| `0x0051e711-0x0051e720` | padding | no source | `0xcc`. |
| `0x0051e720-0x0051e7d3` | raw no-function body | `SendSelectedSpell` | Uses selected index `+0x134`, selected row byte `+0`, opcode `0x39`, context fields `+0x14c/+0x150/+0x154`, and sends fixed length `9`. |
| `0x0051e7d3-0x0051e7e0` | padding | no source | `0xcc`. |
| `0x0051e7e0-0x0051e87e` | raw no-function body | `SendSpell` | Explicit one-byte spell slot/action send helper, fixed length `9`, `ret 4`. |
| `0x0051e87e-0x0051e880` | padding | no source | `0xcc`. |
| `0x0051e880-0x0051e88b` | modeled function | `NotifyOwnerSpellActivated` | Loads owner at `+0x158` and tail-jumps to shared owner state update at `0x49de70`. |
| `0x0051e88b-0x0051e890` | padding | no source | `0xcc`. |
| `0x0051e890-0x0051e998` | modeled function | `DrawListEntry` | Draws text from row `+4`, selection fill/color, ellipsis fitting, and `DrawTextInRect`. |
| `0x0051e998-0x0051e9a0` | padding | no source | `0xcc`; successor is [UID:0001BS]. |

`xrefs_to` for raw starts `0x0051e6b0`, `0x0051e720`, and `0x0051e7e0` returned zero direct refs. As with the server list, they are source-shaped retained class helpers and should be documented in the exact list child page.

## Packet And Row Models

Shared packet context fields for both spell lists:

- `+0x14c` / decimal 332: packet/menu subtype byte.
- `+0x150` / decimal 336: object/menu id dword.
- `+0x154` / decimal 340: menu option/list parameter word.
- `+0x158` / decimal 344: owning dialog pointer.

Conversions verified through MCP `int_convert`: `0x278` = 632, `0x15c` = 348, `0x108` = 264, `0x134` = 308, `0x14c` = 332, `0x150` = 336, `0x154` = 340, `0x158` = 344, `0x206` = 518, `0x204` = 516, `0x148` = 328, `0x13a6ec` = 1287916, `0x13a834` = 1288244, `0x13a83c` = 1288252, and `0x39` = 57.

Server rows:

- List constructor uses row size `514` / `0x202`.
- Raw append body stores a word at row `+0` and copies the display name to row `+2`.
- The dialog constructor inline row build stores zero in the first word, skips a packet-side 4-byte row prefix before the length-prefixed text, converts multibyte text to wide text, and appends the row.
- The selected send helper serializes the row text, not the first word.
- Best first-draft row type: `ServerSpellMenuEntry { unsigned short reserved; wchar_t name[256]; }`. `reserved` is intentional: no current draw/send/action evidence gives the first word a source-facing semantic name.

Client rows:

- List constructor uses row size `516` / `0x204`.
- Local-player spell loop covers one-based slots `1..52`.
- The active flag check is `g_pUserPane + slot * 0x148 + 0x13a834`.
- The row label source is `g_pUserPane + slot * 0x148 + 0x13a83c`.
- Raw append stores the one-byte spell slot at row `+0`, a word field at `+2`, and the display name at `+4`.
- The constructor stores the one-based slot byte and zeroes the word field when adding local-player spells.
- The selected and explicit send helpers serialize the row byte at `+0`, not the word at `+2`.
- Best first-draft row type: `ClientSpellMenuEntry { unsigned char spellSlot; unsigned short reserved; wchar_t name[256]; }`; MSVC natural padding supplies row byte `+1` and places the word at `+2`.

Opcode route:

- Both server and client action paths send opcode `0x39`.
- Server selected helper sends `opcode, subtype, object/menu id, option id, string-length byte, multibyte row name, trailing zero`, with total length `convertedNameLength + 9`.
- Client selected/explicit helper sends fixed length `9`: `opcode, subtype, object/menu id, option id, selected spell slot/action byte, trailing zero`.
- Request command id `2` calls `TextMenuDialog::SendMenuRequestPacket` at `0x00517ec0`; this is not the inherited `0x00517d80` action-string virtual.
- Close command id `3` closes without sending opcode `0x39`.
- Action command id `1` closes after the selected-send attempt, even if no row is selected.

## Action-Button State

Both update helpers decompile to the same shape:

- Fetch child/control slot `1` from `this[127]`; this is the action button.
- Fetch child/control slot `6`; this is the spell list.
- Load list storage at `+0x108` / decimal 264.
- Call shared `ListPane::GetSelectionCount` / `sub_4F3E20`.
- If positive, tail-dispatch action-button virtual slot `+0x4c`; otherwise tail-dispatch slot `+0x50`.

`sub_4F3E20` is not a spell-owned helper. Live xrefs show 14 callers across list-based update methods. The spell calls are only two of the caller set.

[UID:0000VH] should remain as an evidence/support page for this shared pattern, but source emission should move to the exact server/client dialog method children to avoid duplicate C++.

## ChattingColorListPane Pollution Rejection

The generated `ChattingColorListPane*` local type in the client update helper is rejected as type/name pollution.

Evidence checked:

- `xrefs_to 0x00482fb0` returns only `0x00482837` and `0x0048295d`, both inside `sub_4824E0`, the real chat-color construction path.
- The client spell update helper has only the vtable slot ref `0x0061f314`; it does not call or construct `ChattingColorListPane`.
- `ClientSpellMenuItemList` constructor calls are exactly `0x0051dce7` and `0x0051e189` from `ClientSpellMenuDialog`.
- `ClientSpellMenuItemList::DrawListEntry` reads text from row `+4`, matching the spell row model, not chat-color rows.
- [UID:00031X] gives decorated `ClientSpellMenuItemList` vtable bases and constructor store evidence inside [UID:0000O2].

Do not move any spell-menu code to [UID:00001S] `ChattingColorListPane` or [UID:0000I5] `Chatting`.

## Owner And Source Placement Ranking

| Candidate | Decision | Reason |
| --- | --- | --- |
| [UID:0000O2] `SpellMenuDialogs` | selected | Direct file owner for all four spell classes; factory subtypes `6` and `8`, vtables, constructor stores, row models, resource use, and generated root all agree. |
| [UID:0000D3]/[UID:00002R] dialog classes | selected as direct child owners | Exact dialog method child pages should own constructor/command/update bodies. |
| [UID:0000D4]/[UID:00002S] list classes | selected as direct child owners | Exact list child pages should own constructors, raw helpers, activation thunks, draw methods, and row structs. |
| [UID:00031X] `SpellMenuDialogVtables` | support anchor | Correct owner-specific vtable page; not the executable method owner. |
| [UID:0001Y5] `MerchantMenuDialogVtableFamily` | mixed-family context only | Useful parent context, but stale as the primary anchor for [UID:0001BR] because [UID:00031X] now exists. |
| [UID:0000OP] `TextMenuDialogs` / [UID:000238] factory helpers | rejected as owner | Factory/dispatcher constructs spell dialogs, but concrete spell methods and vtables live under [UID:0000O2]. |
| [UID:0000KF] `ItemMenuDialogs` | rejected | Strong sibling pattern, but item source owns item row models and item vtables only. |
| [UID:0000HI] `ArgumentedMenuDialogs` | rejected | Adjacent successor at `0x0051e9a0`; not spell source. |
| [UID:0000KT] `ListPane` | rejected as method owner | Supplies shared storage/selection helpers and base constructor, but spell row structs and packet context fields are private spell-list source. |
| [UID:00001S] `ChattingColorListPane` / [UID:0000I5] `Chatting` | rejected | Generated local type pollution; live constructor xrefs stay in chat-color UI only. |
| [UID:0000P1] `UserPane` / [UID:0000QK] `g_pUserPane` | dependency only | Client constructor reads local spell records through the active UserPane pointer; ownership of the spell menu UI stays with [UID:0000O2]. |
| New `MenuDialogFactory.cpp` | rejected for this target | Possible future physical split for [UID:000238], but not a stronger owner for concrete spell-menu methods. |

## Score Rationale

[UID:0001BR] should move from `88/86` to `90/92`.

Completion increases because the current pass resolves every named source-quality blocker into concrete documentation changes:

- exact half-open method endpoints and padding;
- raw no-function helper bodies in both spell-list classes;
- server and client row layouts;
- one-based local spell slot loop and UserPane offsets;
- opcode `0x39` packet split between server string and client spell-slot byte;
- command ids `1`, `2`, and `3`;
- action-button child slots and shared `ListPane::GetSelectionCount` route;
- owner-specific vtable anchor [UID:00031X];
- generated `ChattingColorListPane` pollution rejection;
- aggregate no-code proof and exact child formal C++ insertion text.

Confidence increases because current IDA MCP session `80de0a67` reconfirmed the boundary, xref, vtable, decompile, and byte evidence. Confidence is not `95+` because formal C++ still uses inferred source-facing wrapper/helper names (`PacketBuffer`, `ReadMenuText`, `CreateSpellMenuLayout`, `SendGamePacket`, and related view classes) rather than recovered original declarations. That is a confidence cap only; it does not block the recommended child C++ because the formal blocks preserve behavior, packet/layout semantics, and source ownership without raw IDA names.

## Aggregate No-Code Proof

[UID:0001BR] should keep its formal C++ block blank after reclassification.

Target-specific proof:

- The range spans four classes and at least fifteen source-bearing method/helper bodies plus alignment.
- A single aggregate C++ block would either duplicate exact child pages or hide which class owns each method.
- The range contains raw no-function helper bodies that must be documented with class-local helper names and zero-direct-ref caveats.
- Accepted sibling pages [UID:0001BO] and [UID:0001BS] use the same non-emitting split-index pattern when a compact source-family address range crosses multiple source classes and exact children own emission.
- Exact child pages can carry the formal C++ without losing source detail; the aggregate can carry the map, split status, rejected alternatives, and score rationale.

## Formal C++ For Recommended Child Pages

The following C++ is not illustrative prose. It is exact proposed formal `RECONSTRUCTION_CPP CODE` insertion text for the recommended new child pages. If the supervisor accepts different child names or real UIDs, keep the formal block contents with the matching child target.

### `by-memory/0x0051ca40-0x0051d6fd.ServerSpellMenuDialogMethods.md`

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
ServerSpellMenuDialog::ServerSpellMenuDialog(const Rect& bounds,
                                             const unsigned char* payload,
                                             unsigned char menuMode)
    : MerchantDialogPane(bounds, menuMode),
      m_menuObjectId(PacketBufferReadUInt32BE(payload + 1))
{
    ObjectStatusBlob objectStatus;
    const unsigned char packetSubtype = payload[0];
    const unsigned char* cursor = payload + 6;

    cursor = objectStatus.ParseTaggedStatus(cursor);
    SetObjectImage(objectStatus);

    wchar_t description[256];
    cursor = ReadMenuText(cursor, description, _countof(description));
    SetDialogText(description);

    const unsigned short menuOptionId = PacketBufferReadUInt16BE(cursor);
    cursor += sizeof(unsigned short);

    ServerSpellMenuItemList* list = new ServerSpellMenuItemList(
        packetSubtype,
        m_menuObjectId,
        menuOptionId,
        this);

    const unsigned short entryCount = PacketBufferReadUInt16BE(cursor);
    cursor += sizeof(unsigned short);

    for (unsigned int i = 0; i < entryCount; ++i) {
        cursor += 4;

        wchar_t spellName[256];
        cursor = ReadMenuText(cursor, spellName, _countof(spellName));
        list->AppendSpellName(0, spellName);
    }

    CreateSpellMenuLayout(g_useEpfAssets ? kCurrentDlgMerc1Layout
                                         : kLegacyDlgMerc1Layout);
    AddControl(6, list);
    UpdateActionButtonState();
}

void ServerSpellMenuDialog::HandleMenuCommand(int commandId, void* context)
{
    UNREFERENCED_PARAMETER(context);

    switch (commandId) {
    case 1:
        if (ServerSpellMenuItemList* list = GetServerSpellMenuList(6))
            list->SendSelectedSpellName();
        CloseDialog();
        break;

    case 2:
        TextMenuDialog::SendMenuRequestPacket(m_menuObjectId);
        break;

    case 3:
        CloseDialog();
        break;
    }
}

void ServerSpellMenuDialog::UpdateActionButtonState()
{
    ControlPane* actionButton = GetControl(1);
    ServerSpellMenuItemList* list = GetServerSpellMenuList(6);
    const bool hasSelection = list != NULL && list->GetSelectionCount() > 0;

    if (actionButton != NULL)
        actionButton->SetEnabled(hasSelection);
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

### `by-memory/0x0051d700-0x0051db38.ServerSpellMenuItemList.md`

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
struct ServerSpellMenuEntry
{
    unsigned short reserved;
    wchar_t name[256];
};

ServerSpellMenuItemList::ServerSpellMenuItemList(
    unsigned char packetSubtype,
    unsigned int menuObjectId,
    unsigned short menuOptionId,
    ServerSpellMenuDialog* owner)
    : ListPane(sizeof(ServerSpellMenuEntry), 0x10, 0xe4, 0x0c, 0, true, true),
      m_packetSubtype(packetSubtype),
      m_menuObjectId(menuObjectId),
      m_menuOptionId(menuOptionId),
      m_owner(owner)
{
}

void ServerSpellMenuItemList::AppendSpellName(unsigned short reserved, const wchar_t* name)
{
    ServerSpellMenuEntry entry;

    entry.reserved = reserved;
    wcscpy_s(entry.name, _countof(entry.name), name != NULL ? name : L"");

    AddEntry(&entry);
}

bool ServerSpellMenuItemList::SendSelectedSpellName()
{
    if (m_selectedIndex < 0 || m_selectedIndex >= GetItemCount())
        return false;

    ServerSpellMenuEntry* entry = static_cast<ServerSpellMenuEntry*>(GetEntryAt(m_selectedIndex));
    if (entry == NULL)
        return false;

    return SendSpellName(entry->name);
}

bool ServerSpellMenuItemList::SendSpellName(const wchar_t* name)
{
    PacketBuffer packet;

    packet.WriteByte(0x39);
    packet.WriteByte(m_packetSubtype);
    packet.WriteDword(m_menuObjectId);
    packet.WriteWord(m_menuOptionId);
    packet.WriteWideStringAsMultiByte(name != NULL ? name : L"");

    SendGamePacket(packet);
    return true;
}

void ServerSpellMenuItemList::NotifyOwnerSpellActivated()
{
    m_owner->UpdateActionButtonState();
}

void ServerSpellMenuItemList::DrawListEntry(
    DrawContext* dc,
    int index,
    const ServerSpellMenuEntry* entry,
    const Rect& bounds)
{
    if (entry == NULL)
        return;

    const bool selected = IsItemSelected(index);
    if (selected)
        dc->FillSelectedListRow(bounds);

    dc->SetTextColor(selected ? kSelectedTextColor : kNormalTextColor);
    dc->SetTransparentTextBackground();

    wchar_t fittedName[256];
    wcscpy_s(fittedName, _countof(fittedName), entry->name);

    Rect textBounds = bounds;
    CenterListTextVertically(textBounds, 12);
    FitWideTextWithEllipsis(dc, fittedName, textBounds.Width());
    dc->DrawText(textBounds, fittedName);
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

### `by-memory/0x0051db40-0x0051e63d.ClientSpellMenuDialogMethods.md`

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
ClientSpellMenuDialog::ClientSpellMenuDialog(const Rect& bounds,
                                             const unsigned char* payload,
                                             unsigned char menuMode)
    : MerchantDialogPane(bounds, menuMode),
      m_menuObjectId(PacketBufferReadUInt32BE(payload + 1)),
      m_packetSubtype(payload[0])
{
    ObjectStatusBlob objectStatus;
    const unsigned char* cursor = payload + 6;

    cursor = objectStatus.ParseTaggedStatus(cursor);
    SetObjectImage(objectStatus);

    wchar_t description[256];
    cursor = ReadMenuText(cursor, description, _countof(description));
    SetDialogText(description);

    const unsigned short menuOptionId = PacketBufferReadUInt16BE(cursor);
    cursor += sizeof(unsigned short);

    ClientSpellMenuItemList* list = new ClientSpellMenuItemList(
        m_packetSubtype,
        m_menuObjectId,
        menuOptionId,
        this);

    for (unsigned char slot = 1; slot <= 52; ++slot) {
        const UserPaneSpellSlotRecord* spell = g_pUserPane->GetSpellSlot(slot);
        if (spell != NULL && spell->active)
            list->AppendSpell(slot, 0, spell->name);
    }

    CreateSpellMenuLayout(g_useEpfAssets ? kCurrentDlgMerc1Layout
                                         : kLegacyDlgMerc1Layout);
    AddControl(6, list);
    UpdateActionButtonState();
}

void ClientSpellMenuDialog::HandleMenuCommand(int commandId, void* context)
{
    UNREFERENCED_PARAMETER(context);

    switch (commandId) {
    case 1:
        if (ClientSpellMenuItemList* list = GetClientSpellMenuList(6))
            list->SendSelectedSpell();
        CloseDialog();
        break;

    case 2:
        TextMenuDialog::SendMenuRequestPacket(m_menuObjectId);
        break;

    case 3:
        CloseDialog();
        break;
    }
}

void ClientSpellMenuDialog::UpdateActionButtonState()
{
    ControlPane* actionButton = GetControl(1);
    ClientSpellMenuItemList* list = GetClientSpellMenuList(6);
    const bool hasSelection = list != NULL && list->GetSelectionCount() > 0;

    if (actionButton != NULL)
        actionButton->SetEnabled(hasSelection);
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

### `by-memory/0x0051e640-0x0051e998.ClientSpellMenuItemList.md`

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
struct ClientSpellMenuEntry
{
    unsigned char spellSlot;
    unsigned short reserved;
    wchar_t name[256];
};

ClientSpellMenuItemList::ClientSpellMenuItemList(
    unsigned char packetSubtype,
    unsigned int menuObjectId,
    unsigned short menuOptionId,
    ClientSpellMenuDialog* owner)
    : ListPane(sizeof(ClientSpellMenuEntry), 0x10, 0xe4, 0x0c, 0, true, true),
      m_packetSubtype(packetSubtype),
      m_menuObjectId(menuObjectId),
      m_menuOptionId(menuOptionId),
      m_owner(owner)
{
}

void ClientSpellMenuItemList::AppendSpell(
    unsigned char spellSlot,
    unsigned short reserved,
    const wchar_t* name)
{
    ClientSpellMenuEntry entry;

    entry.spellSlot = spellSlot;
    entry.reserved = reserved;
    wcscpy_s(entry.name, _countof(entry.name), name != NULL ? name : L"");

    AddEntry(&entry);
}

bool ClientSpellMenuItemList::SendSelectedSpell()
{
    if (m_selectedIndex < 0 || m_selectedIndex >= GetItemCount())
        return false;

    ClientSpellMenuEntry* entry = static_cast<ClientSpellMenuEntry*>(GetEntryAt(m_selectedIndex));
    if (entry == NULL)
        return false;

    return SendSpell(entry->spellSlot);
}

bool ClientSpellMenuItemList::SendSpell(unsigned char spellSlot)
{
    PacketBuffer packet;

    packet.WriteByte(0x39);
    packet.WriteByte(m_packetSubtype);
    packet.WriteDword(m_menuObjectId);
    packet.WriteWord(m_menuOptionId);
    packet.WriteByte(spellSlot);

    SendGamePacket(packet);
    return true;
}

void ClientSpellMenuItemList::NotifyOwnerSpellActivated()
{
    m_owner->UpdateActionButtonState();
}

void ClientSpellMenuItemList::DrawListEntry(
    DrawContext* dc,
    int index,
    const ClientSpellMenuEntry* entry,
    const Rect& bounds)
{
    if (entry == NULL)
        return;

    const bool selected = IsItemSelected(index);
    if (selected)
        dc->FillSelectedListRow(bounds);

    dc->SetTextColor(selected ? kSelectedTextColor : kNormalTextColor);
    dc->SetTransparentTextBackground();

    wchar_t fittedName[256];
    wcscpy_s(fittedName, _countof(fittedName), entry->name);

    Rect textBounds = bounds;
    CenterListTextVertically(textBounds, 12);
    FitWideTextWithEllipsis(dc, fittedName, textBounds.Width());
    dc->DrawText(textBounds, fittedName);
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

## Recommended Support Doc Changes

### `by-memory/0x0051ca40-0x0051e998.SpellMenuDialogs.md`

Apply the metadata change to `90/92`, keep owner `0000O2`, set `RECONSTRUCTABLE:FALSE`, blank `EMITTER_UIDS`, keep formal C++ blank, and rewrite status as a non-emitting split index.

Replace the covered ranges with the four child-page rows and internal method/helper tables above. Preserve the prior factory, vtable, action-button, and chat-pollution evidence, but update it with session `80de0a67` evidence and the raw helper discovery.

Correct the vtable/layout anchor from primary [UID:0001Y5] to primary [UID:00031X], with [UID:0001Y5] as mixed-family context.

Add a no-code proof matching this report's aggregate no-code proof.

### `by-file/SpellMenuDialogs.md`

Raise to `90/91` if the child pages are created and incorporated.

Replace the proposed contents with:

- [new child] `ServerSpellMenuDialogMethods` `0x0051ca40-0x0051d6fd`
- [new child] `ServerSpellMenuItemList` `0x0051d700-0x0051db38`
- [new child] `ClientSpellMenuDialogMethods` `0x0051db40-0x0051e63d`
- [new child] `ClientSpellMenuItemList` `0x0051e640-0x0051e998`
- [UID:00031X] owner-specific spell vtables
- [UID:0000VH] non-emitting action-button-state support index

Add the raw helper inventory, row models, command ids, packet shapes, and `g_pUserPane` spell-slot typed view. Preserve `DLGMERC1.EPF` / `DLGMERC1.EPD`, `PAL01.PAL` / `NPAL8.PAL`, object-image, static text, and list-control dependency notes as dependencies rather than owner moves.

### `by-class/ServerSpellMenuDialog.md`

Raise to `90/91` after child creation.

Update method rows to exact half-open endpoints:

- constructor `0x0051ca40-0x0051d51a`
- command `0x0051d520-0x0051d6b2`
- update `0x0051d6c0-0x0051d6fd`

Add that formal C++ lives on the new `ServerSpellMenuDialogMethods` child, not on the class page. Add command semantics: id `1` sends selected server row name and closes, id `2` sends request packet through `0x00517ec0`, id `3` closes, all other ids return.

### `by-class/ClientSpellMenuDialog.md`

Raise to `90/91` after child creation.

Update method rows to exact half-open endpoints:

- constructor `0x0051db40-0x0051e4d3`
- command `0x0051e4e0-0x0051e5f2`
- update `0x0051e600-0x0051e63d`

Replace the stale "spell code" wording with selected one-byte spell slot/action byte where the packet path reads row `+0`. Add that the constructor loops one-based spell slots `1..52`, tests active byte at `g_pUserPane + slot * 0x148 + 0x13a834`, and copies display name from `+0x13a83c`.

### `by-class/ServerSpellMenuItemList.md`

Raise to `90/91` after child creation.

Expand method notes beyond constructor/activation/draw:

- constructor `0x0051d700-0x0051d76c`
- raw `AppendSpellName` `0x0051d770-0x0051d7c8`
- raw `SendSelectedSpellName` `0x0051d7d0-0x0051d8fd`
- raw `SendSpellName` `0x0051d900-0x0051da1f`
- activation `0x0051da20-0x0051da2b`
- draw `0x0051da30-0x0051db38`

Add the `ServerSpellMenuEntry` row layout and zero-direct-ref caveat for the raw helpers.

### `by-class/ClientSpellMenuItemList.md`

Raise to `90/91` after child creation.

Expand method notes beyond constructor/activation/draw:

- constructor `0x0051e640-0x0051e6ac`
- raw `AppendSpell` `0x0051e6b0-0x0051e711`
- raw `SendSelectedSpell` `0x0051e720-0x0051e7d3`
- raw `SendSpell` `0x0051e7e0-0x0051e87e`
- activation `0x0051e880-0x0051e88b`
- draw `0x0051e890-0x0051e998`

Add the `ClientSpellMenuEntry` row layout, one-based slot semantics, and zero-direct-ref caveat for the raw helpers.

### `by-item/SpellMenuActionButtonState_51d6c0_51e600.md`

Recommended after child creation:

| Field | Current | Recommended |
| --- | --- | --- |
| `COMPLETION` | `86` | `88` |
| `CONFIDENCE` | `91` | `92` |
| `CANONICAL_OWNER` | `0000O2` | `0000O2` |
| `RECONSTRUCTABLE` | `TRUE` | `FALSE` |
| `EMITTER_UIDS` | `0000O2` | blank |
| formal C++ | blank | blank |

This page becomes a non-emitting evidence index over the two update helpers because exact dialog method children own the emitted source. Preserve all child-slot, `+0x108`, `sub_4F3E20`, vtable-only ref, and chat-pollution evidence.

### `by-type/by-vtable/SpellMenuDialogVtables.md`

Score can remain `88/92`. Add links to the four new child pages and preserve the destructor-glue exclusion. No formal C++ is required on the vtable page.

### `by-type/by-vtable/MerchantMenuDialogVtableFamily.md`

No score/metadata change required. Optionally add a short support note that [UID:00031X] is the direct spell-menu vtable anchor for [UID:0001BR], while [UID:0001Y5] remains the mixed-family index.

### `by-global/g_pCollectionData.md` and `by-memory/0x0067a748-0x0067a74c.g_pCollectionData.md`

No score/metadata change required. If the supervisor wants cross-reference polish, add one support note that `ClientSpellMenuDialog` consumes the existing one-based spell-slot typed view: active byte `+0x13a834` and name text `+0x13a83c`.

### `by-memory/0x004f3bb0-0x004f3f20.ListPaneItemSelectionStorageHelpers.md`

No score/metadata change required. If the supervisor wants cross-reference polish, add the spell-menu selected-send callers as additional `ListPane::GetItem` / `GetEntryAt` and `ListPane::GetSelectionCount` consumers.

## Supervisor-Owned Coverage Text

Do not edit any `-coverage-report.md` file during the B-agent implementation callback unless explicitly instructed. After real UIDs are assigned to the new child pages, the supervisor should apply equivalent coverage changes.

### `by-memory/-coverage-report.md`

Replace the existing [UID:0001BR] row text with:

```text
    - [UID:0001BR][0x0051ca40-0x0051e998.SpellMenuDialogs](by-memory/0x0051ca40-0x0051e998.SpellMenuDialogs.md) 0x0051ca40-0x0051e998 | split index / source-family map | SpellMenuDialogs : ignored : 90% : very strong : B001 2026-06-23 MCP session 80de0a67 reclassified this broad server/client spell-menu range as a non-emitting split index under [UID:0000O2] SpellMenuDialogs after live IDA confirmed exact dialog method boundaries, raw spell-list helper bodies, row layouts, opcode 0x39 server-string versus client spell-slot send paths, action-button child slots 1/6, owner-specific [UID:00031X] spell vtables, ChattingColorListPane pollution rejection, and 0xcc padding through the successor at 0x0051e9a0; exact child pages own source emission.
```

Insert child rows after the parent row once real UIDs exist:

```text
        - [UID:00042F][0x0051ca40-0x0051d6fd.ServerSpellMenuDialogMethods](by-memory/0x0051ca40-0x0051d6fd.ServerSpellMenuDialogMethods.md) 0x0051ca40-0x0051d6fd | class method cluster | ServerSpellMenuDialogMethods : reconstructable : 90% : very strong : Exact source-bearing child for ServerSpellMenuDialog constructor, command handler, and action-button updater; MCP session 80de0a67 confirms factory refs 0x005176c3/0x00517b77, vtable slots 0x0061f1b0/0x0061f1b4, constructor/list construction, command ids 1/2/3, opcode 0x39 selected server row-name send, request route 0x00517ec0, child slots 1/6, shared ListPane::GetSelectionCount, and formal first-draft C++.
        - [UID:00042G][0x0051d700-0x0051db38.ServerSpellMenuItemList](by-memory/0x0051d700-0x0051db38.ServerSpellMenuItemList.md) 0x0051d700-0x0051db38 | class method/helper cluster | ServerSpellMenuItemList : reconstructable : 90% : very strong : Exact source-bearing child for ServerSpellMenuItemList constructor, raw AppendSpellName, raw SendSelectedSpellName, raw SendSpellName, activation thunk, and draw method; MCP session 80de0a67 confirms row size 0x202, row text at +2, packet context fields +0x14c/+0x150/+0x154/+0x158, zero direct xrefs to raw helper starts, vtable refs for activation/draw, opcode 0x39 server string send, and formal first-draft C++.
        - [UID:00042H][0x0051db40-0x0051e63d.ClientSpellMenuDialogMethods](by-memory/0x0051db40-0x0051e63d.ClientSpellMenuDialogMethods.md) 0x0051db40-0x0051e63d | class method cluster | ClientSpellMenuDialogMethods : reconstructable : 90% : very strong : Exact source-bearing child for ClientSpellMenuDialog constructor, command handler, and action-button updater; MCP session 80de0a67 confirms factory refs 0x0051770b/0x00517c07, local UserPane spell-slot active/name offsets +0x13a834/+0x13a83c with 0x148 stride over one-based slots 1..52, command ids 1/2/3, opcode 0x39 selected spell-slot byte send, request route 0x00517ec0, child slots 1/6, ChattingColorListPane rejection, and formal first-draft C++.
        - [UID:00042I][0x0051e640-0x0051e998.ClientSpellMenuItemList](by-memory/0x0051e640-0x0051e998.ClientSpellMenuItemList.md) 0x0051e640-0x0051e998 | class method/helper cluster | ClientSpellMenuItemList : reconstructable : 90% : very strong : Exact source-bearing child for ClientSpellMenuItemList constructor, raw AppendSpell, raw SendSelectedSpell, raw SendSpell, activation thunk, and draw method; MCP session 80de0a67 confirms row size 0x204, spell slot byte at +0, reserved word at +2, row text at +4, packet context fields +0x14c/+0x150/+0x154/+0x158, zero direct xrefs to raw helper starts, vtable refs for activation/draw, opcode 0x39 fixed length-9 client spell-slot send, and formal first-draft C++.
```

### `by-item/-coverage-report.md`

Replace [UID:0000VH] row text with:

```text
- [UID:0000VH][SpellMenuActionButtonState_51d6c0_51e600](by-item/SpellMenuActionButtonState_51d6c0_51e600.md) : ignored : 88% : very strong : Non-emitting support index for the server/client spell-menu action-button update helpers; exact source emission moves to the ServerSpellMenuDialogMethods and ClientSpellMenuDialogMethods children. MCP session 80de0a67 confirms both 0x3d-byte vtable-only helpers, child slot 1 action button, child slot 6 spell list, list storage +0x108, shared ListPane::GetSelectionCount at 0x004f3e20 with 14 callers, action-button virtual slots +0x4c/+0x50, and generated ChattingColorListPane type pollution rejection.
```

## Rejected Alternatives

| Alternative | Rejection |
| --- | --- |
| Keep [UID:0001BR] as broad C++ emitter | Would put four class bodies and raw helper bodies in one aggregate block, duplicate exact child responsibility, and obscure row/list ownership. |
| Keep [UID:0001BR] reconstructable true with blank emitter | Less precise than accepted sibling split-index pattern; generated root would keep an empty marker for an aggregate that should not own emission. |
| Split every modeled function into one page each | Possible but inferior to current project pattern. Dialog method clusters and list clusters preserve class locality, row structs, helper relationships, and padding without exploding tiny support pages. |
| Put action-button helpers only in [UID:0000VH] | Duplicates class method source; the helpers are virtual methods on the two dialog classes. [UID:0000VH] should be support evidence only. |
| Treat raw list helpers as padding | Rejected by raw disassembly: each helper has full prologue/body/return, stack-cookie where expected, class fields, packet sends or row append calls. |
| Treat raw list helpers as unreachable junk | Rejected as a no-code reason because they are source-shaped retained class helpers, parallel accepted item-menu raw helpers, even though direct xrefs are zero. |
| Move client spell rows to `SpellManager` or `g_pSpellMan` | Rejected by current [UID:0000QK]/[UID:0001OR] support: spell records are a typed `g_pUserPane` view. |
| Move client update/list code to `ChattingColorListPane` | Rejected by constructor xrefs, vtables, renderer row offset, and no spell refs to the real chat constructor. |
| Use `ClientSpellMenuEntry::spellCode` for row `+0` | Rejected by send helpers: row `+0` is the one-byte selected spell slot/action byte. The word at `+2` is not serialized in current evidence. |

## Implementation Tracking Checklist

Implementation callback pass completed by B001 on 2026-06-23. All checked items below were applied or intentionally left supervisor-owned as stated.

- [x] Update `by-memory/0x0051ca40-0x0051e998.SpellMenuDialogs.md`: metadata `88/86 -> 90/92`, `RECONSTRUCTABLE:FALSE`, blank `EMITTER_UIDS`, blank formal C++, non-emitting split-index status, [UID:00031X] primary vtable anchor, exact child inventory, raw helper body maps, packet/row/action-button evidence, rejected alternatives, and aggregate no-code proof. Proof: file now records [UID:00042F]/[UID:00042G]/[UID:00042H]/[UID:00042I] child inventory, current MCP session `80de0a67` evidence, split-index no-code proof, and rejected alternatives; clean validator command exited 0 with 1 ok.
- [x] Create `by-memory/0x0051ca40-0x0051d6fd.ServerSpellMenuDialogMethods.md`: metadata `90/91`, owner [UID:0000D3], emitter [UID:0000O2], exact constructor/command/update ranges and padding, current MCP evidence, command id semantics, and the formal C++ block from this report. Proof: validator assigned [UID:00042F]; formal `RECONSTRUCTION_CPP CODE` block contains the accepted `ServerSpellMenuDialog` constructor/command/update C++; clean validator command exited 0 with 1 ok.
- [x] Create `by-memory/0x0051d700-0x0051db38.ServerSpellMenuItemList.md`: metadata `90/91`, owner [UID:0000D4], emitter [UID:0000O2], exact modeled/raw/padding ranges, zero-direct-ref caveat for raw helpers, row layout, opcode `0x39` server string path, activation/draw evidence, and the formal C++ block from this report. Proof: validator assigned [UID:00042G]; formal `RECONSTRUCTION_CPP CODE` block contains the accepted `ServerSpellMenuEntry` / `ServerSpellMenuItemList` C++; clean validator command exited 0 with 1 ok.
- [x] Create `by-memory/0x0051db40-0x0051e63d.ClientSpellMenuDialogMethods.md`: metadata `90/91`, owner [UID:00002R], emitter [UID:0000O2], exact constructor/command/update ranges and padding, current MCP evidence, one-based UserPane spell-slot loop, command id semantics, ChattingColorListPane rejection, and the formal C++ block from this report. Proof: validator assigned [UID:00042H]; formal `RECONSTRUCTION_CPP CODE` block contains the accepted `ClientSpellMenuDialog` constructor/command/update C++; clean validator command exited 0 with 1 ok.
- [x] Create `by-memory/0x0051e640-0x0051e998.ClientSpellMenuItemList.md`: metadata `90/91`, owner [UID:00002S], emitter [UID:0000O2], exact modeled/raw/padding ranges, zero-direct-ref caveat for raw helpers, row layout, opcode `0x39` client length-9 path, activation/draw evidence, and the formal C++ block from this report. Proof: validator assigned [UID:00042I]; formal `RECONSTRUCTION_CPP CODE` block contains the accepted `ClientSpellMenuEntry` / `ClientSpellMenuItemList` C++; clean validator command exited 0 with 1 ok.
- [x] Update `by-file/SpellMenuDialogs.md`: recommended score `88/86 -> 90/91`; replace proposed contents with the four new child pages; add raw helper inventory, row models, command IDs, action-button state route, direct [UID:00031X] anchor, generated-pollution rejection, and no duplicate destructor-glue policy. Proof: page now lists [UID:00042F]/[UID:00042G]/[UID:00042H]/[UID:00042I], direct [UID:00031X] anchor, row/packet models, command/state behavior, exclusions, and destructor-glue policy; clean validator command exited 0 with 1 ok.
- [x] Update `by-class/ServerSpellMenuDialog.md`: recommended score `88/90 -> 90/91`; exact half-open method endpoints; link the new dialog child; add command ids `1/2/3`, request route `0x00517ec0`, server row-name send, close behavior, and formal C++ location. Proof: page links [UID:00042F], lists exact endpoints and command semantics; clean validator command exited 0 with 1 ok.
- [x] Update `by-class/ClientSpellMenuDialog.md`: recommended score `86/90 -> 90/91`; exact half-open method endpoints; link the new dialog child; add one-based spell slot loop, `g_pUserPane` offsets, selected spell-slot byte wording, request route, close behavior, and formal C++ location. Proof: page links [UID:00042H], records one-based slots `1..52`, offsets `+0x13a834/+0x13a83c`, selected byte wording, and ChattingColorListPane rejection; clean validator command exited 0 with 1 ok.
- [x] Update `by-class/ServerSpellMenuItemList.md`: recommended score `86/88 -> 90/91`; add raw helper inventory, row layout, packet context fields, zero-direct-ref caveat, activation/draw details, and formal C++ location. Proof: page links [UID:00042G] and lists constructor/raw append/raw send/activation/draw inventory; clean validator command exited 0 with 1 ok.
- [x] Update `by-class/ClientSpellMenuItemList.md`: recommended score `85/89 -> 90/91`; add raw helper inventory, row layout, packet context fields, one-byte selected spell slot wording, zero-direct-ref caveat, activation/draw details, and formal C++ location. Proof: page links [UID:00042I] and lists constructor/raw append/raw send/activation/draw inventory with one-byte selected slot/action wording; clean validator command exited 0 with 1 ok.
- [x] Update `by-item/SpellMenuActionButtonState_51d6c0_51e600.md`: recommended metadata `86/91 -> 88/92`, `RECONSTRUCTABLE:FALSE`, blank `EMITTER_UIDS`, keep formal C++ blank, preserve support evidence and state that exact dialog method children own emission. Proof: page is now a non-emitting support index linking [UID:00042F] and [UID:00042H]; clean validator command exited 0 with 1 ok.
- [x] Update `by-type/by-vtable/SpellMenuDialogVtables.md`: no score change; add links to the four child pages and keep owner-specific vtable evidence/destructor-glue exclusion. Proof: page now links [UID:00042F]/[UID:00042G]/[UID:00042H]/[UID:00042I] in status, table, and cross-references; clean validator command exited 0 with 1 ok.
- [x] Optional support note in `by-type/by-vtable/MerchantMenuDialogVtableFamily.md`: no score change; clarify [UID:00031X] is the direct spell anchor for [UID:0001BR]. Proof: B001 2026-06-23 note added under split result; clean validator command exited 0 with 1 ok.
- [x] Optional support note in `by-global/g_pCollectionData.md` and `by-memory/0x0067a748-0x0067a74c.g_pCollectionData.md`: no score change; add client spell menu consumption of active byte `+0x13a834` and name `+0x13a83c`. Proof: both pages now link [UID:00042H]/[UID:00042I] and record the client spell-menu active/name view; each clean validator command exited 0 with 1 ok.
- [x] Optional support note in `by-memory/0x004f3bb0-0x004f3f20.ListPaneItemSelectionStorageHelpers.md`: no score change; add spell-menu selected-send and update helper consumers. Proof: page now records [UID:00042G]/[UID:00042I] `0x004f3dc0` selected-entry consumers and [UID:00042F]/[UID:00042H] `0x004f3e20` update consumers; clean validator command exited 0 with 1 ok.
- [x] Run scoped validators from `E:\NTK\GhidraBridge\source-3\project-documentation` for every changed/created by-* file with `python .\tools\validator.py --mode file --file <relative-path> --apply --queue-timeout 240`. Proof: all 16 changed/created by-* files were validated in clean batches after the interrupted queue drained; each command exited 0 and reported 1 ok. Full log: `tools/leaser/Agents/Agent-B001/0001BR-implementation-validator.log`.
- [x] Report validator command, exit code, ok count, warnings, and generated/project-level side effects after implementation callback. Proof: final response reports all clean commands; validator side effects were autogen registry/report updates, generated backup creation, UID/reference/stat updates, and known stale registry rows for missing `0003E6`/`00026U`; no `-coverage-report.md` file was manually edited.
- [x] Supervisor-owned coverage: apply the `by-memory/-coverage-report.md` and `by-item/-coverage-report.md` replacement/insert text from this report after real child UIDs are assigned; B001 must not edit coverage reports by default. Proof: coverage snippets above now use real child UIDs [UID:00042F], [UID:00042G], [UID:00042H], and [UID:00042I]; no `-coverage-report.md` files were edited by B001.
- [x] Implementation callback only: update this checklist with checkmarks and proof after accepted edits and validators. Proof: this checklist has been checked and proofed after by-* edits, clean validators, and lease release.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B001","command_id":"000000004165","destination_path":"executed-b-agent-research/B001/0001BR-SpellMenuDialogs-source-quality.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:16","uid":"0001BR"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
