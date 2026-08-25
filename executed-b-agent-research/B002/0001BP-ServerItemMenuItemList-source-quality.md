** TARGET-REPORT-UID:0001BP **
** AUTHOR-AGENT-ID:B002 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# B002 Source-Quality Report: 0001BP ServerItemMenuItemList

Assignment: `B002-goal2-server-item-menu-item-list-source-quality-0001BP-20260618`  
Target: [UID:0001BP] `by-memory/0x0051ae90-0x0051b87a.ServerItemMenuItemList.md`  
Primary source family: [UID:0000KF] `by-file/ItemMenuDialogs.md`  
Report-only status: no by-* docs, generated reports, generated source, IDA database, or coverage report files were edited.

## Executive Recommendation

Raise [UID:0001BP] from `85/85` to `88/89` after applying the support-text corrections below. Keep:

```text
CANONICAL_OWNER:0000KF
RECONSTRUCTABLE:TRUE
EMITTER_UIDS:0000KF
```

The target is still best modeled as the private server item-menu row-list class under `NexusTK/ui/dialogs/ItemMenuDialogs.cpp`. The current owner/emitter route is valid, and the active generated route already points [UID:0001BP] to `auto-generated/NexusTK/ui/dialogs/ItemMenuDialogs.cpp`.

The old score was held at `85/85` by three issues: unresolved raw helper reachability, unresolved row-record field names, and the `dword_69AE04` "observer" interpretation. This reanalysis does not prove direct xrefs for the raw helper starts, but it resolves the source-facing `0x408` row layout and resolves `dword_69AE04` as [UID:0000R9] `g_pItemHelpPane`, the active `ItemHelpPane` singleton. Those two resolutions are enough to move the target above the active code-entry gate. Exact original helper spellings remain inferred, so do not raise above the high-80s yet.

## Evidence Checked

Checked local documentation and generated-report state:

- Target [UID:0001BP] `0x0051ae90-0x0051b87a.ServerItemMenuItemList.md`.
- Class page [UID:0000D0] `ServerItemMenuItemList.md`.
- Parent/source pages [UID:0000KF] `ItemMenuDialogs.md`, [UID:0001BO] `0x0051a520-0x0051c46d.ItemMenuDialogs.md`, and [UID:0000CZ] `ServerItemMenuDialog.md`.
- Sibling and control pages [UID:0001BQ] `ClientItemMenuItemList.md`, [UID:0000KT] `ListPane.md`, ListPane helper by-memory pages, [UID:0000R4] `g_useEpfAssets`, [UID:0000R9] `g_pItemHelpPane`, [UID:000228] `HelpPaneSingletonCloseHelpers`, and [UID:00006U] `ItemHelpPane`.
- Vtable support page `by-type/by-vtable/ItemMenuDialogVtables.md`.
- Destructor support pages [UID:0001BZ] destructor thunks and [UID:0001C2] scalar deleting destructor.
- Manual coverage report row for [UID:0001BP], which still says `82%`.
- Generated emission map `auto-generated/-ag-memory-coverage.md`, which routes [UID:0001BP] to `auto-generated/NexusTK/ui/dialogs/ItemMenuDialogs.cpp`.
- Current generated output file `auto-generated/NexusTK/ui/dialogs/ItemMenuDialogs.cpp`, which is zero bytes because the formal C++ block is blank.

Fresh IDA MCP was not available during this B002 pass: `http://127.0.0.1:13337/mcp` did not accept a `tools/list` connection. I therefore did not make new IDA label/type changes. This report relies on the existing IDA-backed documentation and local file checks. I also did not find a usable local executable/IDB/PDB in the allowed workspace roots for an independent byte scan.

## Function And Data Reanalysis

The target range remains correct:

| Range | Current status | Reanalysis |
| --- | --- | --- |
| `0x0051ae90-0x0051aefc` | raw code | Out-of-line constructor. Still no direct IDA function object/xrefs in current docs. Constructor pushes `1, 1, 0, 0x18, 0x15c, 0x10, 0x408`, calls `0x004f3a50`, stores fields `+0x14c/+0x150/+0x154/+0x158`, and installs vtables `0x0061ef44/0x0061efcc/0x0061effc`. |
| `0x0051af00-0x0051af35` | raw code | Non-deleting destructor. Current "observer notification" wording is wrong. It closes the active [UID:0000R9] `g_pItemHelpPane`/`ItemHelpPane` singleton before shared `ListPane` cleanup. |
| `0x0051af40-0x0051afbf` | raw code | Append-row helper. The `0x408` ListPane stride plus string offsets prove the row record layout with `name[256]` at `+0x008` and `description[256]` at `+0x208`. |
| `0x0051afd0-0x0051b0f8` | raw code | Selected-row packet helper. It reads selected index `+0x134`, fetches a row through the shared ListPane selected-entry helper, serializes opcode `0x39`, fields `+0x14c/+0x150/+0x154`, and selected row text. |
| `0x0051b100-0x0051b18d` | modeled virtual | Selection-change handler. It validates the index, fetches row storage, selects owner text control id `7` through owner state at `+0x158`, writes `row + 0x208` description text, clears with `word_60db20` on invalid selection, then delegates to the shared ListPane selection update. |
| `0x0051b190-0x0051b2a8` | raw code | Explicit-text packet helper. Same opcode `0x39` packet shell as `0x0051afd0`, but source text comes from the caller. |
| `0x0051b2b0-0x0051b2bb` | modeled virtual | Activation thunk. Loads owner/context from `this + 0x158` into `ecx` and jumps to `0x0049de70`. Source-facing name should remain inferred, such as `OnItemActivated` or `NotifyOwnerItemActivated`. |
| `0x0051b2c0-0x0051b3e0` | modeled virtual | Event/help handler. Current generated output is structurally corrupted, but docs show it checks event bytes, hit-tests against list geometry at `+0x110`, closes any active `g_pItemHelpPane` through `0x004a0d40`, and allocates/replaces an `ItemHelpPane` for EPF/current asset mode. |
| `0x0051b3e0-0x0051b87a` | modeled virtual | Row draw virtual. Validated range and endpoint. Draws item icon/name/right-aligned value with `g_useEpfAssets`/`byte_66DA97` current-vs-legacy asset/layout branch. |

## Row Record Layout

The row-record layout is no longer an open blocker. The constructor's `ListPane` stride argument is `0x408`. The append helper copies two bounded wide strings. The event helper passes `row + 0x008` to the `ItemHelpPane` constructor path, and the selection handler pushes `row + 0x208` into the owner description text control. This fits exactly:

```cpp
struct ServerItemMenuEntry
{
    unsigned char actionId;        // +0x000, serialized/used as menu action code
    unsigned char itemStyle;       // +0x001, used by item icon/style rendering
    unsigned short itemId;         // +0x002, used by item image lookup/rendering
    unsigned int value;            // +0x004, rendered right-aligned with unsigned formatting
    wchar_t name[256];             // +0x008, display name and ItemHelpPane title/source text
    wchar_t description[256];      // +0x208, owner text control id 7 description
};                                  // sizeof == 0x408
```

Recommended source-facing names:

- Class: `ServerItemMenuItemList`.
- Row struct: `ServerItemMenuEntry` or `ServerItemMenuRow`. Prefer `ServerItemMenuEntry` if aligning with adjacent menu-entry naming; prefer `ServerItemMenuRow` if the source tree uses ListPane "row" terminology elsewhere.
- Fields at `this + 0x14c/+0x150/+0x154/+0x158`: `m_packetSubtype`, `m_menuObjectId`, `m_menuOptionId`, `m_owner`.
- Row fields: `actionId`, `itemStyle`, `itemId`, `value`, `name`, `description`.
- Global: use `g_useEpfAssets` for `byte_66DA97`; do not introduce `g_useHighResLayout` on this page.
- Global at `0x0069ae04`: use `g_pItemHelpPane`; do not use `g_serverItemMenuObserver`, `observer`, or `dword_69AE04` except as historical aliases in evidence text.

## Heuristic / Inference Reanalysis And Validation

Evidence checked:

- Existing IDA-backed target evidence confirms raw constructor/destructor/helper starts at `0x0051ae90`, `0x0051af00`, `0x0051af40`, `0x0051afd0`, and `0x0051b190`, modeled virtuals at `0x0051b100`, `0x0051b2b0`, `0x0051b2c0`, and `0x0051b3e0`, and vtable data refs/stores for `0x0061ef44`, `0x0061efcc`, and `0x0061effc`.
- `ServerItemMenuDialog` documentation proves inline list construction in the owner dialog at `0x0051a69c-0x0051a720`, including the same vtable stores and owner pointer store to list `+0x158`.
- `ItemMenuDialogs` aggregate documentation proves the packet opcode `0x39` is also emitted by the owner dialog action path, tying the list packet helpers to the server item-menu source family.
- `ListPane` documentation proves `+0x134` selected index, shared item-count/get-entry/append/selection-update helpers, and prevents misowning shared `0x004f3bd0`, `0x004f3c50`, `0x004f3dc0`, `0x004f3e20`, `0x004f4480`, or `0x004f45b0` as private `ServerItemMenuItemList` code.
- `g_pItemHelpPane` and `HelpPaneSingletonCloseHelpers` documentation prove `0x0069ae04` is the active `ItemHelpPane` singleton, with direct xrefs at `0x0051af1d`, `0x0051b344`, `0x0051b39e`, and `0x00520d00`.
- Coverage and generated-output checks prove the manual coverage row is stale at `82%`, while the target page header and generated stats have moved to `85/85`; formal generated `ItemMenuDialogs.cpp` remains empty because the formal C++ block is blank.

Best guesses retained:

- Exact original method names are still descriptive/inferred. The decompiled/class-page names `OnItemSelected`, `OnItemActivated`, `HandleMenuEvent`, and `DrawListEntry` are acceptable source-facing names until a stronger symbol source appears.
- `+0x14c` is best named `m_packetSubtype` rather than `m_menuType` because it is serialized in opcode `0x39` packets and derives from the server item-menu constructor argument.
- `+0x150` is best named `m_menuObjectId` or `m_serverObjectId`; `+0x154` is best named `m_menuOptionId`. The exact gameplay noun remains inferred, but packet role and width are solid.
- Event code symbolic names in `0x0051b2c0` remain inferred. The source should describe behavior as menu/list mouse/help handling and avoid overclaiming exact enum names.

Rejected alternatives:

- Reject `g_serverItemMenuObserver` and generic "observer notification" for `0x0069ae04`. The storage is already canonical [UID:0000R9] `g_pItemHelpPane`, and the close path dispatches the `ItemHelpPane` scalar deleting destructor.
- Reject moving the target to `ListPane`. The shared helpers are ListPane-owned, but this target owns the item-menu-specific constructor fields, packet opcode shell, owner text-control update, help-pane event path, and row draw virtual.
- Reject moving the target to `ClientItemMenuItemList`. The client sibling uses the same private-list pattern but is a distinct range and source sibling.
- Reject importing current generated `class_ServerItemMenuItemList.cpp` wholesale. The generator is documented as polluted by article/mail paging helpers and shared ListPane helpers, omits raw helper bodies, and corrupts `HandleMenuEvent`.
- Reject using the scalar deleting destructor page as the formal source implementation site for the ordinary destructor body. Source should express `ServerItemMenuItemList::~ServerItemMenuItemList()` in the class/file target; scalar deleting wrapper pages should document compiler glue or stay blank unless the supervisor has a specific ABI-output policy.

Validation of current docs:

- Validated: half-open endpoint `0x0051b87a`, vtable identities, raw/modeled split, fields `+0x14c/+0x150/+0x154/+0x158`, packet opcode `0x39`, owner text control id `7`, sibling/client boundary, ItemMenuDialogs source placement, and generated-output caveats.
- Contradicted: any use of "observer" or `g_serverItemMenuObserver` for `0x0069ae04`; the "final C++ withheld until 95/95" wording in the class page; and the manual coverage row's `82%`.
- Needs narrowing but is defensible: exact source method names, exact event enum names, exact packet helper class/function names, and exact final physical split if the project later folds item-menu dialogs into a broader item-dialog file. These do not block a first-draft C++ artifact, but they cap confidence below the 90s.

Unresolved blockers and impact:

- No fresh IDA MCP in this session: prevents new direct raw-start/caller checks. Impact: keep confidence at `89`, not `91+`.
- Raw helper starts still lack direct IDA function objects/xrefs in existing docs. Impact: mention raw starts explicitly in target, but do not demote reconstructability because inline construction and vtable/behavior evidence retain the methods.
- Original helper/prototype names remain inferred. Impact: first-draft C++ should be marked source-facing/descriptive and may require later name polish before final checked-in source.
- Generated source currently empty for the ItemMenuDialogs formal output. Impact: once formal C++ is populated, supervisor should regenerate and confirm the output no longer stays zero bytes and no polluted simroot helpers are copied into `ItemMenuDialogs.cpp`.

## First-Draft C++ Recommendation

Recommendation: after the supervisor updates [UID:0001BP] to `88/89`, populate the formal C++ block with the following draft or a mechanically equivalent version. The target then clears the active gate: `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000KF`, and `(88 + 89) / 2 > 85`.

This draft intentionally uses descriptive project-facing helper names for packet writing, ListPane helpers, drawing, and owner-control access. It should not import polluted article/mail/ListPane helper bodies from generated `class_ServerItemMenuItemList.cpp`.

```cpp
struct ServerItemMenuEntry
{
    unsigned char actionId;
    unsigned char itemStyle;
    unsigned short itemId;
    unsigned int value;
    wchar_t name[256];
    wchar_t description[256];
};

ServerItemMenuItemList::ServerItemMenuItemList(
    unsigned char packetSubtype,
    unsigned int menuObjectId,
    unsigned short menuOptionId,
    ServerItemMenuDialog* owner)
    : ListPane(sizeof(ServerItemMenuEntry), 0x10, 0x15c, 0x18, 0, true, true),
      m_packetSubtype(packetSubtype),
      m_menuObjectId(menuObjectId),
      m_menuOptionId(menuOptionId),
      m_owner(owner)
{
}

ServerItemMenuItemList::~ServerItemMenuItemList()
{
    CloseItemHelpPaneSingleton();
}

void ServerItemMenuItemList::AppendItem(
    unsigned char actionId,
    unsigned short itemId,
    unsigned char itemStyle,
    unsigned int value,
    const wchar_t* name,
    const wchar_t* description)
{
    ServerItemMenuEntry entry = {};

    entry.actionId = actionId;
    entry.itemStyle = itemStyle;
    entry.itemId = itemId;
    entry.value = value;
    wcscpy_s(entry.name, name != nullptr ? name : L"");
    wcscpy_s(entry.description, description != nullptr ? description : L"");

    AddEntry(&entry);
}

bool ServerItemMenuItemList::SendSelectedItemText()
{
    if (m_selectedIndex < 0 || m_selectedIndex >= GetItemCount())
        return false;

    ServerItemMenuEntry* entry = static_cast<ServerItemMenuEntry*>(GetSelectedEntry());
    if (entry == nullptr)
        return false;

    return SendItemText(entry->name);
}

bool ServerItemMenuItemList::SendItemText(const wchar_t* text)
{
    PacketBuffer packet;

    packet.WriteByte(0x39);
    packet.WriteByte(m_packetSubtype);
    packet.WriteDword(m_menuObjectId);
    packet.WriteWord(m_menuOptionId);
    packet.WriteWideStringAsMultiByte(text != nullptr ? text : L"");

    SendGamePacket(packet);
    return true;
}

void ServerItemMenuItemList::OnItemSelected(int index)
{
    const wchar_t* description = L"";

    if (index >= 0 && index < GetItemCount())
    {
        ServerItemMenuEntry* entry = static_cast<ServerItemMenuEntry*>(GetSelectedEntry());
        if (entry != nullptr)
            description = entry->description;
    }

    TextControlPane* text = static_cast<TextControlPane*>(m_owner->GetControl(7));
    if (text != nullptr)
        text->SetText(description);

    ListPane::OnItemSelected(index);
}

void ServerItemMenuItemList::OnItemActivated()
{
    m_owner->UpdateSelectedItemState();
}

bool ServerItemMenuItemList::HandleMenuEvent(const MenuEvent& event)
{
    if (event.code == kMenuEventLeave || event.code == kMenuEventCancelHelp)
    {
        CloseItemHelpPaneSingleton();
        return true;
    }

    if (event.code == kMenuEventHoverHelp)
    {
        if (!ContainsPoint(m_itemBounds, event.x, event.y))
            return ListPane::HandleMenuEvent(event);

        if (HitTestItem(event.x, event.y) < 0)
            return ListPane::HandleMenuEvent(event);

        ServerItemMenuEntry* entry = static_cast<ServerItemMenuEntry*>(GetSelectedEntry());
        if (entry != nullptr && g_useEpfAssets)
        {
            CloseItemHelpPaneSingleton();
            new ItemHelpPane(entry->name, this, event.y, event.x, 5000, 0, 0, 0);
        }

        return true;
    }

    return ListPane::HandleMenuEvent(event);
}

void ServerItemMenuItemList::DrawListEntry(
    DrawContext* dc,
    int index,
    const Rect& bounds,
    unsigned int state)
{
    ServerItemMenuEntry* entry = static_cast<ServerItemMenuEntry*>(GetEntry(index));
    if (entry == nullptr)
        return;

    const bool selected = IsItemSelected(index);
    if (selected)
        dc->FillSelectedListRow(bounds);

    Rect iconRect = bounds;
    Rect nameRect = bounds;
    Rect valueRect = bounds;

    if (g_useEpfAssets)
    {
        iconRect.left += 12;
        iconRect.right = iconRect.left + 28;
        nameRect.left += 50;
        nameRect.right -= 90;
        valueRect.left = bounds.right - 90;
        valueRect.right = bounds.right - 30;
        DrawItemIconScaled(dc, entry->itemId, entry->itemStyle, iconRect);
    }
    else
    {
        iconRect.left += 12;
        iconRect.right = iconRect.left + 32;
        nameRect.left += 50;
        nameRect.right -= 62;
        valueRect.left = bounds.right - 62;
        valueRect.right = bounds.right - 2;
        DrawItemIcon(dc, entry->itemId, entry->itemStyle, iconRect);
    }

    wchar_t fittedName[256];
    wcscpy_s(fittedName, entry->name);
    FitWideTextWithEllipsis(dc, fittedName, nameRect.Width());
    dc->DrawText(nameRect, fittedName, selected ? kSelectedTextColor : kNormalTextColor);

    wchar_t valueText[32];
    swprintf_s(valueText, L"%10u", entry->value);
    dc->DrawRightAlignedText(valueRect, valueText, selected ? kSelectedTextColor : kNormalTextColor);
}
```

Placement note: if the supervisor wants a smaller formal block, the essential minimum is the `ServerItemMenuEntry` layout plus method bodies for the constructor, destructor, append helper, two packet helpers, four modeled virtuals, and no shared ListPane/article/mail helpers.

## Exact Supervisor Edits

### Target [UID:0001BP] Header

Replace:

```text
*** COMPLETION:85 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:85 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
```

with:

```text
*** COMPLETION:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:89 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
```

Keep `CANONICAL_OWNER:0000KF`, `RECONSTRUCTABLE:TRUE`, and `EMITTER_UIDS:0000KF`.

### Target [UID:0001BP] Status

Replace the current confidence bullet with:

```text
- Confidence: strong for behavior, range, vtable identity, row-record layout, help-pane singleton linkage, and parent source placement; medium-high for exact original helper/prototype names because raw helper starts still have no IDA function objects or direct xrefs and this B002 pass could not perform a fresh live-MCP byte/xref refresh.
```

Replace the evidence-basis bullet with:

```text
- Evidence basis: existing IDA-backed documentation, targeted 2026-06-01/2026-06-15 IDA MCP checks already recorded in this page, and B002 2026-06-18 local reanalysis of support docs, generated-output routing, stale coverage rows, `g_pItemHelpPane` linkage, and row-record layout. Fresh IDA MCP was unavailable during the B002 pass.
```

### Target [UID:0001BP] Covered Range Table

Replace the `0x0051af00-0x0051af35` row with:

```text
| `0x0051af00-0x0051af35` | raw code | Non-deleting destructor; closes the active `g_pItemHelpPane` / `ItemHelpPane` singleton before shared `ListPane` cleanup. |
```

### Target [UID:0001BP] Parent And Score Rationale

Replace the first paragraph with:

```text
This page is attached to [UID:0000KF][ItemMenuDialogs](by-file/ItemMenuDialogs.md), which has reviewed `NexusTK/ui/dialogs/` placement and remains the strongest source-family route for the server/client item-menu dialog cluster. The class owner [UID:0000D0][ServerItemMenuItemList](by-class/ServerItemMenuItemList.md) records the same constructor, raw helper, virtual, destructor, vtable, packet, `g_pItemHelpPane`, and source-placement evidence. The broader aggregate [UID:0001BO][0x0051a520-0x0051c46d.ItemMenuDialogs](by-memory/0x0051a520-0x0051c46d.ItemMenuDialogs.md) nests this exact island under the server/client item-menu dialog cluster and records the adjacent client list boundary.
```

Replace the score paragraph with:

```text
Completion is raised to `88` because this page now has enough written evidence for source-quality reconstruction: exact half-open range, every contained raw/modeled subrange, constructor field/vtable map, padding checks on both sides, vtable xref fanout, destructor/thunk linkage, packet-helper behavior, row selection/update behavior, the `0x408` row-record layout, `g_pItemHelpPane` close/recreate linkage, and generated-output caveats are all documented here or linked by stable UID. Confidence is raised to `89` because the former `observer` interpretation has been resolved as `g_pItemHelpPane`, and the row layout is derivable from independent stride/string-offset/draw/help evidence. Confidence does not rise further because fresh live MCP was unavailable for this B002 pass, the raw constructor/destructor/helper starts at `0x0051ae90`, `0x0051af00`, `0x0051af40`, `0x0051afd0`, and `0x0051b190` still lack direct IDA function objects or direct xrefs, and exact original helper/prototype names are inferred.
```

### Target [UID:0001BP] New Section After Constructor Field Map

Insert:

```text
## Row Record Layout

The server list row is a `0x408`-byte record. Evidence: the constructor passes `0x408` as the ListPane row stride; the append helper copies two bounded wide strings; the event/help path passes row text at `row + 0x008` into `ItemHelpPane`; the selection handler writes text at `row + 0x208` into owner control id `7`; and the draw virtual uses the leading item/style/id/value fields plus display text.

| Offset | Source-facing field | Evidence |
| --- | --- | --- |
| `+0x000` | `unsigned char actionId` | Appended by the raw row helper and serialized/used as the menu action code. |
| `+0x001` | `unsigned char itemStyle` | Used with item-id/image rendering. |
| `+0x002` | `unsigned short itemId` | Used by item icon/image lookup and draw. |
| `+0x004` | `unsigned int value` | Rendered right-aligned with unsigned numeric formatting. |
| `+0x008` | `wchar_t name[256]` | Copied by `_wcscpy_s`, drawn as the row name, and passed to `ItemHelpPane`. |
| `+0x208` | `wchar_t description[256]` | Copied by `_wcscpy_s` and written to owner text control id `7` on selection. |

Total size is `0x408`, matching the ListPane constructor stride.
```

### Target [UID:0001BP] Behavioral Notes

Replace the `0x0051b2c0-0x0051b3e0` row with:

```text
| `0x0051b2c0-0x0051b3e0` | Checks event code bytes, hit-tests against `this + 0x110`, closes any active [UID:0000R9][`g_pItemHelpPane`](by-global/g_pItemHelpPane.md) through the singleton close helper when dismissing/replacing help, and allocates an `ItemHelpPane` for current/EPF item-help display. | Handles mouse/list events for selection and item help behavior. |
```

Add a behavioral note immediately after the table:

```text
The `0x0069ae04` references in the raw destructor, event helper, and scalar deleting destructor are not a server item-menu observer. They are reads of [UID:0000R9][`g_pItemHelpPane`](by-global/g_pItemHelpPane.md), the process-wide active `ItemHelpPane` singleton.
```

### Target [UID:0001BP] Generated Data Caveats

Replace the section body with:

```text
- The project documentation emitter currently routes this UID to `auto-generated/NexusTK/ui/dialogs/ItemMenuDialogs.cpp`, but that generated file is zero bytes while this page's formal C++ block remains blank.
- Historical/generated `class_ServerItemMenuItemList.cpp` output is polluted: it includes article/mail pagination helpers and shared ListPane helpers that do not belong to this class, omits the raw helper bodies at `0x0051af00`, `0x0051af40`, `0x0051afd0`, and `0x0051b190`, and has a structurally corrupted `HandleMenuEvent` body.
- Do not use generated ownership of article/mail paging helpers or shared list-count helpers to drive `ItemMenuDialogs.cpp` layout. Keep those helpers with their documented owners.
- After the score/support corrections in this B002 report, this page is eligible for a first-draft formal C++ artifact under the active `(COMPLETION + CONFIDENCE) / 2 > 85` code-entry rule.
```

### Target [UID:0001BP] Changes

Add:

```text
- 2026-06-18 B002 source-quality reanalysis: recommended `88/89`, kept owner/emitter [UID:0000KF][ItemMenuDialogs](by-file/ItemMenuDialogs.md), resolved `0x0069ae04`/`dword_69AE04` uses as [UID:0000R9][`g_pItemHelpPane`](by-global/g_pItemHelpPane.md) rather than a server item-menu observer, proved the `0x408` row-record layout (`actionId`, `itemStyle`, `itemId`, `value`, `name[256]`, `description[256]` at `+0x208`), documented stale generated-output pollution/zero-byte formal output, and supplied a first-draft C++ recommendation. Fresh IDA MCP was unavailable in this pass, so exact original helper/prototype names remain inferred.
```

### Class Page [UID:0000D0] `ServerItemMenuItemList.md`

Recommended metadata:

```text
*** COMPLETION:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:89 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
```

Replace the reconstructability bullet:

```text
- Reconstructability: reconstructable as the server-side private item-menu list under [UID:0000KF][ItemMenuDialogs](by-file/ItemMenuDialogs.md). B002 resolved the row-record layout and `g_pItemHelpPane` singleton linkage; remaining caveats are exact original helper/prototype names and the raw helper starts that still lack direct IDA function objects/xrefs.
```

Replace the non-deleting destructor row:

```text
| non-deleting destructor | `0x0051af00-0x0051af35` | Resets vtables, closes the active `g_pItemHelpPane` / `ItemHelpPane` singleton, and tail-calls shared `ListPane` cleanup. |
```

Replace the `0x0051b2c0` evidence bullet:

```text
- IDA-backed documentation of `0x0051b2c0` handles event byte `1`/`4`, hit-tests through geometry/ListPane helpers, closes active [UID:0000R9][`g_pItemHelpPane`](by-global/g_pItemHelpPane.md) through the singleton close helper, and allocates/replaces an `ItemHelpPane` in the EPF/current help path.
```

Replace the `0x00520ce0` evidence bullet:

```text
- IDA-backed documentation of `0x00520ce0` resets the three class vtables, closes active [UID:0000R9][`g_pItemHelpPane`](by-global/g_pItemHelpPane.md), calls `ListPane` cleanup at `0x004f3b60`, and conditionally deletes through `0x004f4ac0`.
```

Replace stale `95/95` wording:

```text
- `RECONSTRUCTABLE:TRUE`: the methods are source-authored UI/list behavior. Formal C++ is eligible once this page and the emitting memory page clear the active code-entry gate: reconstructable, valid emitter, and `(COMPLETION + CONFIDENCE) / 2 > 85`.
```

### Scalar Destructor Page [UID:0001C2]

Recommended metadata if the supervisor accepts the `g_pItemHelpPane` correction:

```text
*** COMPLETION:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:91 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
```

Replace confidence/status wording:

```text
- Confidence: strong for exact boundary, class ownership, vtable restores, `g_pItemHelpPane` singleton close, cleanup path, and parent attachment.
```

Replace covered-range row:

```text
| `0x00520ce0-0x00520d47` | `sub_520CE0` | Resets `ServerItemMenuItemList` vtables, closes active `g_pItemHelpPane`, calls shared list cleanup, and conditionally deletes the object. |
```

Replace behavior item 2:

```text
2. Reads [UID:0000R9][`g_pItemHelpPane`](by-global/g_pItemHelpPane.md) at `0x0069ae04`; if non-null, calls its first virtual slot with argument `1`, matching source-level `delete g_pItemHelpPane;` through the singleton close/destructor path.
```

Replace observer evidence bullets/rows with `g_pItemHelpPane` wording. The formal C++ block may remain blank if the supervisor treats this page as compiler-generated scalar deleting destructor glue and keeps the ordinary destructor body in [UID:0001BP]/[UID:0000D0].

### Manual Coverage Row

Current manual row at `by-memory/-coverage-report.md:2201` is stale at `82%`. Replace that row with:

```text
    - [UID:0001BP][0x0051ae90-0x0051b87a.ServerItemMenuItemList](by-memory/0x0051ae90-0x0051b87a.ServerItemMenuItemList.md) 0x0051ae90-0x0051b87a | class-method/raw-helper cluster | ServerItemMenuItemList : reconstructable : 88% : strong : Server item-menu private ListPane row class under ItemMenuDialogs; B002 2026-06-18 source-quality reanalysis resolves the `0x408` row layout (`actionId`, `itemStyle`, `itemId`, `value`, `name[256]`, `description[256]` at `+0x208`), context fields `+0x14c/+0x150/+0x154/+0x158`, opcode `0x39` selected/explicit string packet helpers, owner description control id `7` update, activation thunk to owner item-state logic, current/legacy `g_useEpfAssets` row draw paths, and `g_pItemHelpPane` close/recreate linkage; generated ServerItemMenuItemList output pollution and blank generated ItemMenuDialogs.cpp are documented; raw helper starts remain non-IDA-functions/no-direct-xref caveat.
```

Also replace the scalar destructor row at `by-memory/-coverage-report.md:2246` if the supervisor applies the scalar page wording:

```text
    - [UID:0001C2][0x00520ce0-0x00520d47.ServerItemMenuItemListScalarDeletingDestructor](by-memory/0x00520ce0-0x00520d47.ServerItemMenuItemListScalarDeletingDestructor.md) 0x00520ce0-0x00520d47 | scalar deleting destructor | ServerItemMenuItemListScalarDeletingDestructor : reconstructable : 86% : strong : Parent-attached ServerItemMenuItemList class-specific scalar deleting destructor; IDA-backed docs confirm exact 0x67 boundary, two adjustor thunk refs, primary vtable slot, three vtable restores, `g_pItemHelpPane` close via 0x0069ae04, shared list cleanup, scalar-delete/delete/guard branches, no ordinary callers, and blank formal C++ remains acceptable if ordinary source destructor is emitted with the class target.
```

### Parent File [UID:0000KF] Optional Support Text

Add to the generated-output/source-placement caveat area:

```text
- B002 2026-06-18 reanalysis keeps `ServerItemMenuItemList` under this ItemMenuDialogs source family but warns against importing historical generated `class_ServerItemMenuItemList.cpp` wholesale. That output mixes true item-menu list virtuals with article/mail pagination helpers and shared ListPane helpers, omits raw item-menu helper bodies, and corrupts the event/help body. The source-facing reconstruction should use the [UID:0001BP] row layout and `g_pItemHelpPane` correction instead.
```

## Generated Output State

The current formal project output for `ItemMenuDialogs.cpp` is zero bytes. That is expected because the formal C++ block for [UID:0001BP] is blank and related formal blocks in the source family are also sparse. It is not proof that the target is non-reconstructable.

The separate generated/simroot `class_ServerItemMenuItemList.cpp` should not be used as source truth. Existing project issue notes already identify the same corruption pattern: article/mail pagination helpers and shared ListPane helpers are assigned to the class, raw helper bodies are omitted, and the event handler body is malformed. The correct supervisor action is to populate a target-specific first draft in [UID:0001BP]/ItemMenuDialogs after the documentation corrections, then regenerate from documentation rather than copy polluted class output.

## Final Recommendation

Apply the documentation corrections, then treat [UID:0001BP] as source-quality enough for a first-draft C++ artifact:

- Owner/emitter: keep [UID:0000KF] `ItemMenuDialogs`.
- Score: target `88/89`.
- C++: populate the target formal block with the first-draft source shape above or an equivalent project-local version.
- Coverage: replace stale `82%` manual row with an `88%` row.
- Support docs: update [UID:0000D0] and [UID:0001C2] to remove `observer`/`g_serverItemMenuObserver` language and use `g_pItemHelpPane`.
- Do not migrate article/mail pagination helpers or shared ListPane helpers into `ServerItemMenuItemList`.

Residual risk is confined to exact original helper/prototype names and event enum names. The source placement, row layout, opcode/context fields, vtables, owner-control update, help-pane singleton linkage, and generated-output correction are sufficiently supported for supervisor incorporation.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B002","command_id":"000000004165","destination_path":"executed-b-agent-research/B002/0001BP-ServerItemMenuItemList-source-quality.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:24","uid":"0001BP"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
