** TARGET-REPORT-UID:0000ET **
** AUTHOR-AGENT-ID:B012 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# 0000ET TextMenuItemList Class Source-Quality Report

Assignment: B012 Rule 26 source-quality pass for [UID:0000ET] `TextMenuItemList`

Status: FINISHED, report-only. I did not edit `by-*` documentation and did not edit `by-memory/-coverage-report.md`.

## Target Paths

- Target: `E:\NTK\GhidraBridge\source-3\project-documentation\by-class\TextMenuItemList.md`
- Required report: `E:\NTK\GhidraBridge\source-3\project-documentation\tools\leaser\Agents\Agent-B012\research\0000ET-TextMenuItemList-class-source-quality.md`
- Current target metadata: `COMPLETION:86`, `CONFIDENCE:85`, `CANONICAL_OWNER:0000OP`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000OP`, blank formal C++.
- Current source/file owner: [UID:0000OP] `by-file/TextMenuDialogs.md`, proposed source path `NexusTK/ui/dialogs/TextMenuDialogs.cpp`.
- Primary containing memory page: [UID:0001BN] `by-memory/0x00517ec0-0x0051a417.TextMenuDialogs.md`.
- Destructor-glue support pages: [UID:00037G] `by-memory/0x00520b55-0x00520b6a.TextMenuItemListDestructorThunks.md` and [UID:00037H] `by-memory/0x00520df0-0x00520e2b.TextMenuItemListScalarDeletingDestructor.md`.

## Summary Recommendation

Keep [UID:0000ET] source-bearing and emitting under [UID:0000OP] `TextMenuDialogs`. The current gate is not the old `95/95` bar: the active C++ entry rule is `RECONSTRUCTABLE:TRUE`, nonblank emitter, and `(COMPLETION + CONFIDENCE) / 2 > 85`. `TextMenuItemList` is already `86/85`, has a valid emitter, and the recoverable class methods are ordinary source logic. The stale "below 95/95, no C++" line should be replaced.

Recommended metadata after implementation:

- `COMPLETION:89`
- `CONFIDENCE:88`
- `CANONICAL_OWNER:0000OP`
- `RECONSTRUCTABLE:TRUE`
- `EMITTER_UIDS:0000OP`

Reason for score cap: constructor ownership, row record layout, callers, draw behavior, and destructor-glue policy are now strong. Keep confidence below final-source levels because the exact original spelling of the list virtual at `0x00519840`, exact GrafPort helper names, and the no-xref raw reply helpers are still inferred/descriptive rather than proven source names.

Recommended source-facing class shape:

- Private helper class in `TextMenuDialogs.cpp`, used by `TextMenuDialog`.
- Base class: `ListPane`.
- Size: `0x158` bytes.
- Row payload size: `0x202` bytes.
- Row record: `unsigned short itemId` at row offset `+0`, followed by `wchar_t label[256]` at row offset `+2`.
- List-local owner/context fields:
  - `+0x14c`: `m_menuType` / `m_dialogType`, one byte copied from `TextMenuDialog +0x274`.
  - `+0x150`: `m_menuId` / `m_dialogId`, dword copied from `TextMenuDialog +0x270`.
  - `+0x154`: `m_ownerDialog`, non-owning `TextMenuDialog *`.
- Recommended first-draft method names:
  - `TextMenuItemList::TextMenuItemList(unsigned char menuType, unsigned long menuId, TextMenuDialog *ownerDialog)`
  - `int TextMenuItemList::AddTextEntry(unsigned short itemId, const wchar_t *label)`
  - `void TextMenuItemList::ForwardOwnerSelectionState()` or `NotifyOwnerSelectionChanged()` for the one-line `0x00519840` virtual. I recommend `ForwardOwnerSelectionState` in docs because it describes the binary without overclaiming the virtual-slot source name.
  - `void TextMenuItemList::DrawListItem(unsigned int itemIndex, const TextMenuItemListEntry *entry, const Rect *itemRect)`
  - Ordinary `virtual ~TextMenuItemList()` declaration/default body only; do not hand-port scalar deleting destructor or adjustor thunk bodies.

## Evidence Checked

Local documentation and generated/source evidence checked:

- Target class doc `source-3/project-documentation/by-class/TextMenuItemList.md`.
- Parent/support docs:
  - `source-3/project-documentation/by-file/TextMenuDialogs.md`
  - `source-3/project-documentation/by-class/TextMenuDialog.md`
  - `source-3/project-documentation/by-class/TextInputMenuDialog.md`
  - `source-3/project-documentation/by-memory/0x00517ec0-0x0051a417.TextMenuDialogs.md`
  - `source-3/project-documentation/by-memory/0x00520abb-0x00520e2b.MenuDialogDestructorThunks.md`
  - `source-3/project-documentation/by-memory/0x00520b55-0x00520b6a.TextMenuItemListDestructorThunks.md`
  - `source-3/project-documentation/by-memory/0x00520df0-0x00520e2b.TextMenuItemListScalarDeletingDestructor.md`
  - `source-3/project-documentation/by-type/by-vtable/TextMenuDialogVtables.md`
  - `source-3/project-documentation/by-type/by-vtable/MerchantMenuDialogVtableFamily.md`
  - `source-3/project-documentation/by-memory/0x0061ec10-0x0061fa3c.MerchantMenuDialogReadOnlyData.md`
  - `source-3/project-documentation/by-class/ListPane.md`
  - `source-3/project-documentation/by-file/ListPane.md`
  - `source-3/project-documentation/by-memory/0x004f3bb0-0x004f3f20.ListPaneItemSelectionStorageHelpers.md`
  - `source-3/project-documentation/by-memory/0x0049de70-0x0049df14.DialogPaneActivateFocusedControlRaw.md`
- Coverage/generated rows:
  - `source-3/project-documentation/by-class/-coverage-report.md`
  - `source-3/project-documentation/by-file/-coverage-report.md`
  - `source-3/project-documentation/by-memory/-coverage-report.md` read only.
  - `source-3/project-documentation/auto-generated/-ag-class-coverage.md`
  - `source-3/project-documentation/auto-generated/-ag-memory-coverage.md`
  - `source-3/project-documentation/project-level/-auto-completion-stats.md`
  - `source-3/project-documentation/wave3_data_issues.md`
- Active generated source used as a lead, not authority:
  - `source-3/simroot_v2/class_TextMenuItemList.cpp`
  - `source-3/simroot_v2/class_TextMenuItemList.cpp.disabled`
- Local exported function data:
  - `source-3/core/data/cache/prewave/functions/0x00517f30.json`
  - `source-3/core/data/cache/prewave/functions/0x00519210.json`
  - `source-3/core/data/cache/prewave/functions/0x005194c0.json`
  - `source-3/core/data/cache/prewave/functions/0x00519520.json`
  - `source-3/core/data/cache/prewave/functions/0x00519590.json`
  - `source-3/core/data/cache/prewave/functions/0x005195f0.json`
  - `source-3/core/data/cache/prewave/functions/0x00519720.json`
  - `source-3/core/data/cache/prewave/functions/0x00519840.json`
  - `source-3/core/data/cache/prewave/functions/0x00519850.json`
  - `source-3/core/data/cache/prewave/functions/0x00520b55.json`
  - `source-3/core/data/cache/prewave/functions/0x00520b60.json`
  - `source-3/core/data/cache/prewave/functions/0x00520df0.json`
- Local bundle evidence for decompiled bodies, xrefs, signatures, size, and generated summaries under `source-3/core/data/cache/prewave/_bundles`.

No live IDA MCP tool was exposed in this session. This report relies on current local exported IDA/Ghidra evidence and prior live-IDA-backed docs already present in the repo. Claims sourced from existing docs are treated as documentation evidence; claims from the JSON exports are treated as direct local export evidence.

## Function And Layout Findings

### Constructor `0x00519520-0x00519580`

The constructor is a normal class constructor, not a compiler helper. The local export gives a `__thiscall` constructor with parameters matching `unsigned char`, `unsigned long`, and owner pointer:

```cpp
TextMenuItemList * __thiscall TextMenuItemList(
    TextMenuItemList *this,
    undefined1 param_1,
    undefined4 param_2,
    undefined4 param_3)
```

IDA decompilation is source-shaped:

```cpp
sub_4F3A50(this, 514, 16, 228, 12, 0, (void *)1, 1);
this[332] = a2;
*((DWORD *)this + 84) = a3;
*((DWORD *)this + 85) = a4;
*(_DWORD *)this = &TextMenuItemList::`vftable';
*((DWORD *)this + 40) = &TextMenuItemList::`vftable';
*((DWORD *)this + 41) = &TextMenuItemList::`vftable';
```

Field mapping:

| Offset | Recommended source name | Evidence |
| --- | --- | --- |
| inherited `ListPane` `+0x000-0x149` | base `ListPane` | Constructor delegates to `ListPane` with row size `514`, capacity/visible-count `16`, width `228`, row height `12`, and two truthy list flags. |
| `+0x14a/+0x14b` | padding/unused tail bytes | Wave2 class metadata shows two byte slots before the local fields; no direct behavior found in this pass. |
| `+0x14c` | `m_menuType` / `m_dialogType` | Constructor stores byte parameter copied from `TextMenuDialog +0x274`; opcode `0x39` serializers send the same byte after the opcode. |
| `+0x14d-0x14f` | alignment padding | Dword at `+0x150` follows the byte field. |
| `+0x150` | `m_menuId` / `m_dialogId` | Constructor stores dword parameter copied from `TextMenuDialog +0x270`; opcode `0x39` serializers write it as big-endian dword. |
| `+0x154` | `m_ownerDialog` | Constructor stores caller `TextMenuDialog *this`; `0x00519840` and the raw reply helpers dereference it as owner dialog state. |

Constructor callers are both inside `TextMenuDialog` construction:

- `0x0051814d` in the `g_useEpfAssets == 1` / high-res layout branch.
- `0x005186d4` in the standard layout branch.

Both call sites allocate `0x158` bytes and pass `TextMenuDialog +0x274`, `TextMenuDialog +0x270`, and the owner `TextMenuDialog *`. This rejects the active generated source's `TextMenu *ownerMenu` type; the receiver is a `TextMenuDialog *` owner pointer.

### Row Record Layout And `AddTextEntry` `0x00519590-0x005195e7`

`AddTextEntry` is source-bearing. It constructs a temporary row record on the stack and calls `ListPane::AddEntry` at `0x004f3c50`. The Ghidra export signature is:

```cpp
undefined __thiscall meth_0x519590(TextMenuItemList *this, undefined2 param_1, wchar_t *param_2)
```

IDA/Ghidra body:

- Stores the caller item id as a 16-bit value at the first stack slot.
- Copies the caller label into the immediately following wide-character buffer.
- Calls `_wcscpy_s(destination, 0x100u, source)`.
- Passes the address of the 16-bit id to `ListPane::AddEntry`.
- Returns the `ListPane::AddEntry` result.

The correct source row is:

```cpp
struct TextMenuItemListEntry {
    unsigned short itemId;
    wchar_t label[256];
};
```

Why `label[256]`, not IDA's misleading `wchar_t Destination[257]`:

- `ListPane` row size is `514` bytes (`0x202`) from the constructor.
- The first two bytes are the `unsigned short itemId`.
- The remaining `512` bytes hold `256` UTF-16 characters.
- `_wcscpy_s` receives `0x100`, which is the destination character count for the label, not `257`.
- The decompiler's `Destination[257]` is a frame-layout artifact caused by naming the buffer starting at `itemId + 2`.

Recommended source signature:

```cpp
int TextMenuItemList::AddTextEntry(unsigned short itemId, const wchar_t *label)
```

Return type `int` is preferred because `ListPane::AddEntry` returns a value and `AddTextEntry` tail-returns it. The single modeled caller ignores the return, but the binary still preserves it.

Caller and branch evidence:

- The standard "more than 6 entries" branch calls `AddTextEntry` around `0x005189ed`.
- The high-res/EPF branch duplicates the same row shape inline and calls `ListPane::AddEntry` directly around `0x0051847e` rather than calling `AddTextEntry`.
- The small-menu branch stores item ids in `TextMenuDialog +0x280` and creates direct controls, so it does not use `TextMenuItemList` rows.

This means `AddTextEntry` is a source helper, but it is not the only row append route in the compiled constructor. The support docs should state both the direct `ListPane::AddEntry` branch and the modeled helper call branch.

### Selection-State Forwarder `0x00519840-0x0051984a`

`0x00519840` is an 11-byte virtual method body:

```asm
mov ecx, [ecx + 0x154]
jmp 0x0049de70
```

It reads `m_ownerDialog` and tail-jumps to [UID:0003KO] `DialogPaneActivateFocusedControlRaw` at `0x0049de70`. The target raw helper is owned by `DialogPane` and activates the focused control: it reads focused control id `owner +0x200`, checks active state, applies visual state `0x0b`, invalidates through the active screen pane global, sleeps `0x85` ms, clears prior selected state, resets owner fields `+0x224/+0x228`, and dispatches the focused control's virtual slot `+0x48`.

Recommended documentation name: `ForwardOwnerSelectionState`.

Reasoning:

- The function belongs to `TextMenuItemList` because the vtable slot and this-adjustment evidence identify the receiver as the list.
- The behavior is not a standalone selection algorithm; it forwards to owner-dialog focused-control activation.
- Existing docs call it a "selection-state forwarder"; that is directionally correct and should be retained in the method map with the exact tailcall target.
- `UpdateScrollButtons` is a bad name for this function. The `TextMenuDialog::UpdateScrollButtons` body at `0x005194c0` is separate and calls `ListPane::GetSelectionCount`; `0x00519840` does not call it.
- `ActivateFocusedControl` is a good name for the callee at `0x0049de70`, but using that as the `TextMenuItemList` method name would hide the fact that the list method is only a forwarding virtual.

Recommended C++ shape:

```cpp
void TextMenuItemList::ForwardOwnerSelectionState()
{
    m_ownerDialog->ActivateFocusedControl();
}
```

The owner method name `ActivateFocusedControl` is descriptive from the support page, not proven original spelling. This is not a C++ blocker because the binary body is a direct owner-dialog tailcall.

### `DrawListItem` `0x00519850-0x005198d0`

`DrawListItem` is source-bearing list-row drawing logic. The export signature is:

```cpp
undefined __thiscall virt_meth_0x519850(
    TextMenuItemList *this,
    undefined4 param_1,
    int param_2,
    undefined4 *param_3)
```

Recommended signature:

```cpp
void TextMenuItemList::DrawListItem(
    unsigned int itemIndex,
    const TextMenuItemListEntry *entry,
    const Rect *itemRect)
```

Behavior:

- Calls `ListPane::IsItemSelected` at `0x004f3f00`.
- If selected:
  - sets a drawing color/value to `37`;
  - invokes the global draw/fill callback at `dword_69B3FC` with `this` and the item rectangle;
  - uses text color/value `128`.
- If not selected, uses text color/value `37`.
- Calls GrafPort-style helper `0x004b9680` with the text color.
- Sets byte `this +0x88` to `1`; in current docs this is best treated as inherited draw/text state, not a `TextMenuItemList` field.
- Calls `0x004b9690(this, 0)`.
- Calls `0x004b9600(this, rect[0], rect[3])`, moving to the left/bottom of the row rectangle.
- Scans the row label at `entry +2` for a null terminator.
- Calls `0x004bab70(this, entry->label, length)` to draw the wide label.

Recommended helper names for source text are descriptive until the GrafPort island receives a final naming audit:

- `SetDrawColor` / `SetTextColor` for `0x004b9660` and `0x004b9680`.
- `SetTextMode` or `SetTextOpaque` for `0x004b9690`.
- `MoveTo` for `0x004b9600`.
- `DrawWideText` for `0x004bab70`.
- `g_drawPaneRect` or `g_paneFillProc` for `dword_69B3FC`.

Do not leave the target page with raw `dword_69B3FC` or `sub_4BAB70` as uninvestigated names. If exact original helper names are not accepted in the implementation callback, the docs should explicitly mark these as descriptive GrafPort helper names.

### Raw Reply Helpers `0x005195f0` And `0x00519720`

The containing memory page documents two raw opcode `0x39` reply serializers immediately after `AddTextEntry`. They should be incorporated into the class page as behavioral neighbors, but they should not be emitted as normal class C++ until a source route or xref is recovered.

`0x005195f0-0x0051971d` selected-row reply helper:

- IDA does not model a clean function/xref route in current docs.
- Reads selected index from inherited `ListPane +0x134`.
- If selected index is negative, returns without sending.
- Calls `ListPane::GetSelectedEntry` at `0x004f3dc0`.
- Reads the selected row id from row offset `+0`.
- Builds opcode `0x39`:
  - byte opcode `0x39`;
  - byte `m_menuType` from `this +0x14c`;
  - big-endian dword `m_menuId` from `this +0x150`;
  - selected item id through the 16-bit packet writer at `0x005753a0`;
  - optional extra string from owner `TextMenuDialog +0x27c` if owner byte `+0x279` is set;
  - trailing null byte.
- Sends via the shared packet sender at `DAT_0067a7ec` / `0x00574bb0`.
- Has a `<0x100` packet-length range check and calls `__report_rangecheckfailure` on overflow.

Best descriptive name if this body is later routed: `SendSelectedTextMenuReply()`.

`0x00519720-0x0051983a` explicit-id reply helper:

- Same packet construction and owner/context fields.
- Takes an explicit `unsigned short itemId` parameter instead of reading the selected row.
- Same optional extra string handling and packet send.
- No direct modeled caller or vtable route found in current docs/exports.

Best descriptive name if this body is later routed: `SendTextMenuReply(unsigned short itemId)`.

Rejected source-emission direction:

- Do not put these helpers into the class C++ block yet as active methods. They have strong behavior, but no recovered caller, pointer ref, or vtable placement. Emitting them as ordinary source would imply a source route that the evidence does not prove.
- Do document them in `TextMenuItemList.md` and the aggregate `TextMenuDialogs` memory page, because they duplicate the packet shape used by `TextMenuDialog::OnDialogAction` and explain why the list mirrors `m_menuType`, `m_menuId`, and `m_ownerDialog`.

### Destructor Glue `0x00520b55`, `0x00520b60`, `0x00520df0`

The destructor support is compiler-generated glue and should remain non-emitting in the exact child pages:

- `0x00520b55`: `SUB ECX,0xa0; JMP 0x00520df0`.
- `0x00520b60`: `SUB ECX,0xa4; JMP 0x00520df0`.
- `0x00520df0`: scalar deleting destructor wrapper. It calls the `ListPane` base destructor at `0x004f3b60`, then uses delete flags:
  - if `flags & 1` is clear, returns `this`;
  - if `flags & 4` is set, calls the sized delete path with size `0x158`;
  - otherwise calls the normal delete helper.

Source-level conclusion:

- `TextMenuItemList` needs only an ordinary virtual destructor declaration/default body in source documentation.
- `m_ownerDialog` is non-owning and is not freed by `TextMenuItemList`.
- Row storage is owned by the inherited `ListPane` lists and released by the base destructor.
- The generated source's `ClientItemMenuItemList::~ClientItemMenuItemList()` label is owner/type pollution and should not be copied into docs.
- Do not hand-port the scalar deleting destructor or adjustor thunks into [UID:0000ET]'s first-draft source.

## Relationship To TextMenuDialog And TextInputMenuDialog

`TextMenuItemList` belongs with `TextMenuDialog` inside `TextMenuDialogs.cpp`.

Accepted source route:

- [UID:0000OP] `TextMenuDialogs`
- `NexusTK/ui/dialogs/TextMenuDialogs.cpp`
- Private/helper class near `TextMenuDialog`.

Why this route is strongest:

- Both constructor callers are inside `TextMenuDialog` construction.
- The constructor mirrors `TextMenuDialog +0x274` and `+0x270` into list fields and stores the owner dialog pointer.
- `TextMenuDialog::OnDialogAction` directly retrieves the list control and reads `TextMenuItemList` row records for the scrollable menu path.
- The opcode `0x39` reply packet shape is a text-menu dialog action packet, not generic `ListPane` behavior.
- `TextInputMenuDialog` is a sibling in the same source file. It shares file placement and dialog infrastructure, but it does not own the list class.

Rejected routes:

- Standalone `TextMenuItemList.cpp`: rejected. There is no independent allocation/caller family outside `TextMenuDialog`, and the class is tightly coupled to dialog fields and opcode `0x39`.
- `ListPane.cpp`: rejected. `ListPane` owns storage helpers and selection APIs, but `TextMenuItemList` owns text-menu row shape, owner-context mirrors, and drawing.
- `TextInputMenuDialog`: rejected. It is a sibling consumer of the same file family, not a caller/owner of the item list.
- `ArgumentedMenuDialogs`: rejected for this class. The current `TextMenuDialogs` owner split is correct; argumented menu dialogs have their own file route.

## Heuristic / Inference Reanalysis

### Row Layout Candidates

Accepted: `unsigned short itemId; wchar_t label[256];`

Rejected alternatives:

- `wchar_t label[257]`: rejected as a decompiler local artifact. It ignores the two-byte id at the start of the copied row and conflicts with the `0x202` row size and `_wcscpy_s(..., 0x100, ...)`.
- Separate id and label pointers: rejected. `AddEntry` receives one contiguous stack record whose first two bytes are the id and whose next bytes are the copied label.
- `signed short itemId`: mechanically possible because the raw field is 16-bit, but source/protocol direction should be `unsigned short` because ids are serialized as 16-bit packet values and read with zero-extension in callers.

### Constructor Field Names

Accepted source-facing direction:

- `m_menuType` / `m_dialogType` for `+0x14c`.
- `m_menuId` / `m_dialogId` for `+0x150`.
- `m_ownerDialog` for `+0x154`.

Best implementation wording: "menu type/dialog type" and "menu id/dialog id" on first introduction, then use one consistent pair. I recommend `m_menuType` and `m_menuId` in C++ because the class name and packet role are menu-facing; cross-reference that these mirror `TextMenuDialog +0x274/+0x270`.

Rejected:

- `ownerId` only: too vague. The dword is sent in opcode `0x39` as the dialog/menu context id.
- `TextMenu *ownerMenu`: generated type pollution. Callers pass `TextMenuDialog *`.
- Owning pointer semantics for `+0x154`: rejected. The list never deletes the owner; the owner constructs and embeds the list through a control.

### `AddTextEntry` Name

Accepted: `AddTextEntry`.

This name is already used by the docs/generated metadata and matches behavior. Alternatives like `AddMenuItem`, `AddItem`, or `AppendTextItem` are plausible but weaker because there is no source symbol proof and changing the established descriptive name would reduce cross-doc consistency.

### Selection Forwarder Name

Accepted descriptive doc name: `ForwardOwnerSelectionState`.

Rejected:

- `UpdateScrollButtons`: contradicted by the separate `0x005194c0` method.
- `DrawSelection`: no drawing occurs in this wrapper; drawing happens in the raw `DialogPane` helper after it takes over the owner dialog.
- `ListPane::ActivateFocusedControl`: wrong owner. The body forwards from `TextMenuItemList` to the owner `TextMenuDialog`, whose base `DialogPane` has the raw activation behavior.

### `DrawListItem` Signature

Accepted: a `ListPane` virtual taking item index, row pointer, and rectangle pointer.

The exact source type for the rectangle is not proven in this pass. The docs can use `Rect`, `RectBounds`, or the local project's established rectangle type if one is already chosen elsewhere. Avoid raw `int *` in the final class-level prose except as binary evidence.

### Raw Helper Policy

Accepted: document `0x005195f0` and `0x00519720` as raw no-xref reply serializers in the class/support docs; do not emit them as source methods yet.

Rejected:

- Treating them as dead padding: rejected. They have complete packet serializer bodies and match live text-menu action packet semantics.
- Emitting them as normal class source: rejected due lack of direct modeled callers, pointer refs, or vtable route.
- Splitting them under `ListPane`: rejected. Their fields and opcode are `TextMenuDialog`/`TextMenuItemList` specific.

### Destructor Policy

Accepted: exact child pages remain no-code compiler glue; class page carries only ordinary destructor semantics.

Rejected:

- Moving scalar deleting destructor source into [UID:0000ET]'s C++ block: rejected as compiler wrapper logic.
- Using generated `ClientItemMenuItemList` destructor name: rejected as source/type pollution.
- Marking destructor as a custom owner cleanup path: rejected. No list-local field cleanup is visible beyond inherited `ListPane` teardown.

## First-Draft C++ Recommendation

The target is eligible for first-draft C++ under the current gate. Recommended class-page C++ block:

```cpp
struct TextMenuItemListEntry {
    unsigned short itemId;
    wchar_t label[256];
};

class TextMenuItemList : public ListPane {
public:
    TextMenuItemList(unsigned char menuType,
                     unsigned long menuId,
                     TextMenuDialog *ownerDialog);
    virtual ~TextMenuItemList();

    int AddTextEntry(unsigned short itemId, const wchar_t *label);

protected:
    virtual void ForwardOwnerSelectionState();
    virtual void DrawListItem(unsigned int itemIndex,
                              const TextMenuItemListEntry *entry,
                              const Rect *itemRect);

private:
    unsigned char m_menuType;
    unsigned long m_menuId;
    TextMenuDialog *m_ownerDialog;
};

TextMenuItemList::TextMenuItemList(unsigned char menuType,
                                   unsigned long menuId,
                                   TextMenuDialog *ownerDialog)
    : ListPane(sizeof(TextMenuItemListEntry), 16, 228, 12, 0, 1, 1),
      m_menuType(menuType),
      m_menuId(menuId),
      m_ownerDialog(ownerDialog)
{
}

TextMenuItemList::~TextMenuItemList()
{
}

int TextMenuItemList::AddTextEntry(unsigned short itemId, const wchar_t *label)
{
    TextMenuItemListEntry entry;

    entry.itemId = itemId;
    wcscpy_s(entry.label, 0x100, label);
    return AddEntry(&entry);
}

void TextMenuItemList::ForwardOwnerSelectionState()
{
    m_ownerDialog->ActivateFocusedControl();
}

void TextMenuItemList::DrawListItem(unsigned int itemIndex,
                                    const TextMenuItemListEntry *entry,
                                    const Rect *itemRect)
{
    int textColor = 37;

    if (IsItemSelected(itemIndex)) {
        SetDrawColor(37);
        g_drawPaneRect(this, itemRect);
        textColor = 128;
    }

    SetTextColor(textColor);
    SetTextOpaque(1);
    SetTextMode(0);
    MoveTo(itemRect->left, itemRect->bottom);
    DrawWideText(entry->label, wcslen(entry->label));
}
```

Implementation notes for this C++ block:

- `Rect`, `SetDrawColor`, `SetTextColor`, `SetTextOpaque`, `SetTextMode`, `MoveTo`, `DrawWideText`, `g_drawPaneRect`, and `ActivateFocusedControl` are descriptive source-facing names pending the GrafPort/DialogPane naming audit. Do not degrade them back to raw `sub_`/`dword_` names in final docs; instead mark them as descriptive if exact original names are not settled.
- The destructor body is intentionally empty/default. It represents ordinary source semantics. The compiler-generated scalar deleting destructor and this-adjustor thunks remain documented in [UID:00037G] and [UID:00037H].
- Do not add `SendSelectedTextMenuReply` or `SendTextMenuReply` to this C++ block unless a later route audit finds xrefs or source placement for `0x005195f0`/`0x00519720`.

## Recommended Target Doc Changes

Update `by-class/TextMenuItemList.md` at report-level detail:

1. Header:
   - Set `COMPLETION:89`.
   - Set `CONFIDENCE:88`.
   - Keep `CANONICAL_OWNER:0000OP`.
   - Keep `RECONSTRUCTABLE:TRUE`.
   - Keep `EMITTER_UIDS:0000OP`.
   - Fill `RECONSTRUCTION_CPP` with the first-draft C++ above, adjusted only if the supervisor accepts different field/helper spellings.
2. Status:
   - Replace "some helper/thunk bodies are omitted from current emitted source" with a more precise split:
     - constructor/AddTextEntry/selection forwarder/DrawListItem are source-bearing;
     - raw reply serializers are documented but no-route;
     - destructor thunks/scalar deleting destructor are compiler-generated non-emitting glue.
   - Replace the stale below-`95/95` no-code explanation with the active `85/85` gate analysis.
3. Class purpose:
   - State exact row payload: `0x202` bytes, `unsigned short itemId` + `wchar_t label[256]`.
   - State exact list-local fields at `+0x14c`, `+0x150`, and `+0x154`.
   - State `m_ownerDialog` is non-owning.
4. Method map:
   - Keep constructor, `AddTextEntry`, `ForwardOwnerSelectionState`, `DrawListItem`, destructor thunk child, and scalar deleting destructor child.
   - Add a raw-neighbor subsection for `0x005195f0-0x0051971d` and `0x00519720-0x0051983a`, with packet semantics and no-route policy.
5. Evidence notes:
   - Add constructor caller details at `0x0051814d` and `0x005186d4`.
   - Add standard large-list `AddTextEntry` call and high-res direct `ListPane::AddEntry` branch.
   - Add `TextMenuDialog::OnDialogAction` evidence that reads the selected row's first word and serializes opcode `0x39`.
   - Add destructor flags/sized-delete details, but explicitly state this stays no-code compiler glue.
6. Heuristic/source-quality section:
   - Preserve rejected alternatives: generated `TextMenu *`, `ClientItemMenuItemList`, `label[257]`, standalone file, `ListPane` owner, `TextInputMenuDialog` owner, raw reply helper emission, and scalar deleting destructor emission.
   - Preserve negative evidence: no direct xrefs/routes for `0x005195f0` and `0x00519720`; no reason to free `m_ownerDialog`; no `UpdateScrollButtons` call from `0x00519840`.
7. Changes:
   - Add a dated B012 source-quality entry explaining the score raise, C++ gate update, row-layout closure, helper policy, and support-doc update needs.

## Recommended Support Doc Changes

Update `by-file/TextMenuDialogs.md`:

- Add a `TextMenuItemList` source-shape paragraph under the `TextMenuDialog` family:
  - private helper class in `TextMenuDialogs.cpp`;
  - row payload `0x202`;
  - context mirrors `m_menuType`, `m_menuId`, `m_ownerDialog`;
  - standard branch calls `AddTextEntry`, high-res branch directly appends the same row via `ListPane::AddEntry`;
  - raw reply serializers are documented but not emitted;
  - destructor glue is in non-emitting child pages.
- Keep [UID:0000OP] as owner/emitter. No source-file split is recommended.

Update `by-memory/0x00517ec0-0x0051a417.TextMenuDialogs.md`:

- In the TextMenuItemList range map, add exact row layout and constructor field mapping.
- State `0x00519590` returns `ListPane::AddEntry`.
- State `0x00519840` is a tailcall to [UID:0003KO] `DialogPaneActivateFocusedControlRaw`.
- Expand the raw helper notes for `0x005195f0` and `0x00519720` with selected-row vs explicit-id packet details, optional extra string handling, packet sender global, and no-xref/no-emission policy.
- Add the high-res direct row append evidence from `TextMenuDialog` construction so `AddTextEntry` is not described as the only append route.

Update `by-class/TextMenuDialog.md`:

- Add a cross-reference noting that scrollable text menus use `TextMenuItemListEntry` rows, read the selected row id from row offset `+0`, and serialize opcode `0x39` with `TextMenuItemList` mirrored fields.
- Clarify that `TextMenuDialog +0x270/+0x274` are mirrored into `TextMenuItemList +0x150/+0x14c`.
- Do not transfer ownership of `TextMenuItemList` away from [UID:0000OP].

Update `by-memory/0x0049de70-0x0049df14.DialogPaneActivateFocusedControlRaw.md` only if the implementation callback includes support docs beyond the class/file/memory target:

- Add one sentence that `TextMenuItemList` virtual `0x00519840` forwards owner `TextMenuDialog *` to this raw helper by loading `this +0x154` into `ECX` and tail-jumping to `0x0049de70`.

No direct changes are recommended to [UID:00037G] or [UID:00037H] beyond cross-references from the class page. Those child pages already carry the correct non-reconstructable/no-emitter direction.

## Exact Callback Implementation Instructions

If the supervisor accepts this report, send B012 an implementation callback with these exact tasks:

1. Lease/edit only the accepted target/support docs. Minimum target set:
   - `by-class/TextMenuItemList.md`
   - `by-file/TextMenuDialogs.md`
   - `by-memory/0x00517ec0-0x0051a417.TextMenuDialogs.md`
   - `by-class/-coverage-report.md` if coverage wording is updated.
   - Optional support docs only if accepted: `by-class/TextMenuDialog.md`, `by-memory/0x0049de70-0x0049df14.DialogPaneActivateFocusedControlRaw.md`, `by-file/-coverage-report.md`.
2. Do not edit `by-memory/-coverage-report.md`; carry the exact pending replacement row from this report for supervisor-owned application.
3. Apply the target metadata recommendation: `89/88`, owner/emitter unchanged, reconstructable true.
4. Insert first-draft C++ for the class. Keep the destructor ordinary/default. Do not emit scalar deleting destructor, adjustor thunks, `0x005195f0`, or `0x00519720`.
5. Incorporate report facts claim-by-claim, not as a compact summary:
   - exact row layout and rejected `label[257]`;
   - constructor field mapping and caller addresses;
   - `AddTextEntry` return/caller/direct-append branch;
   - selection forwarder tailcall and rejected `UpdateScrollButtons`;
   - `DrawListItem` helper roles;
   - raw reply helper packet semantics and no-route policy;
   - destructor glue behavior and no-code policy;
   - source-file route and rejected alternatives;
   - score rationale and current 85/85 gate.
6. Run the scoped validator commands in the validation section and report exact results. If a validator changes generated state because of C++ insertion, list the changed generated/autogen files separately.

## Exact Coverage Text

Replace the current [UID:0000ET] row in `by-class/-coverage-report.md` with:

```md
- [UID:0000ET][TextMenuItemList](by-class/TextMenuItemList.md) : reconstructable : 89% : strong : TextMenuDialogs-owned scrollable text-menu list with resolved `0x202` row payload (`unsigned short itemId` plus `wchar_t label[256]`), constructor context mirrors at `+0x14c/+0x150/+0x154`, AddTextEntry/direct-AddEntry append paths, owner-dialog selection forwarder, DrawListItem label rendering, raw reply-helper no-route policy, and non-emitting destructor-glue children [UID:00037G][0x00520b55-0x00520b6a.TextMenuItemListDestructorThunks](by-memory/0x00520b55-0x00520b6a.TextMenuItemListDestructorThunks.md)/[UID:00037H][0x00520df0-0x00520e2b.TextMenuItemListScalarDeletingDestructor](by-memory/0x00520df0-0x00520e2b.TextMenuItemListScalarDeletingDestructor.md) documented.
```

Optional by-file coverage row replacement if `by-file/TextMenuDialogs.md` receives the recommended support update:

```md
- [UID:0000OP][TextMenuDialogs](by-file/TextMenuDialogs.md) : reconstructable : 90% : strong : Text/text-input menu dialog family with factory helpers, assigned [UID:00031Y][TextMenuDialogVtables](by-type/by-vtable/TextMenuDialogVtables.md), TextMenuItemList row-layout/source-route and raw-helper policy, IDA vtable/store evidence, ownership notes, and corrected split from [UID:0000HI][ArgumentedMenuDialogs](by-file/ArgumentedMenuDialogs.md) documented.
```

Supervisor-owned `by-memory/-coverage-report.md` replacement row if the memory aggregate support page is updated. Replace the current [UID:0001BN] nested row with:

```md
    - [UID:0001BN][0x00517ec0-0x0051a417.TextMenuDialogs](by-memory/0x00517ec0-0x0051a417.TextMenuDialogs.md) 0x00517ec0-0x0051a417 | class-method/raw-helper aggregate | TextMenuDialogs : reconstructable : 86% : strong : Text-menu dialog aggregate with request packet helper, constructor, paint, action, scroll-button updater, TextMenuItemList constructor/`0x202` row layout/AddTextEntry/direct-AddEntry append/draw helpers, owner-dialog selection forwarder, raw selected-row and explicit-id opcode `0x39` reply serializers without direct xrefs, TextInputMenuDialog constructor/button/validation paths, factory callers, vtable-family evidence, and adjacent text-input reply helper caveat documented.
```

If the implementation callback updates only the class page and not the memory aggregate, no `by-memory/-coverage-report.md` change is required for this pass.

## Validation Commands Needed After Implementation

Run from `E:\NTK\GhidraBridge`:

> Executable block R001 was removed from this report and preserved verbatim in [0000ET-TextMenuItemList-class-source-quality-removed.md](0000ET-TextMenuItemList-class-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

If optional support docs are edited:

> Executable block R002 was removed from this report and preserved verbatim in [0000ET-TextMenuItemList-class-source-quality-removed.md](0000ET-TextMenuItemList-class-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

If the supervisor applies the `by-memory/-coverage-report.md` row later:

> Executable block R003 was removed from this report and preserved verbatim in [0000ET-TextMenuItemList-class-source-quality-removed.md](0000ET-TextMenuItemList-class-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

No validators were run during this report-only pass because no by-* docs were edited.

## IDA Rename / Type / Comment Recommendations

High confidence:

- Rename `0x00519520` to `TextMenuItemList::TextMenuItemList`.
- Rename `0x00519590` to `TextMenuItemList::AddTextEntry`.
- Rename `0x00519850` to `TextMenuItemList::DrawListItem`.
- Type the row argument to `DrawListItem` as `const TextMenuItemListEntry *`.
- Define `TextMenuItemListEntry` as `{ uint16_t itemId; wchar_t label[256]; }`.
- Type `TextMenuItemList +0x154` as `TextMenuDialog *m_ownerDialog`.

Medium-high confidence:

- Name `TextMenuItemList +0x14c` `m_menuType` or `m_dialogType`.
- Name `TextMenuItemList +0x150` `m_menuId` or `m_dialogId`.
- Rename `0x00519840` to `TextMenuItemList::ForwardOwnerSelectionState`.
- Comment `0x00519840`: "Loads non-owning owner dialog from +0x154 and tailcalls DialogPane focused-control activation at 0x0049de70."

Medium confidence:

- Label `0x005195f0` as raw/no-route `TextMenuItemList::SendSelectedTextMenuReply` candidate, but keep it non-emitting unless xrefs/source route are found.
- Label `0x00519720` as raw/no-route `TextMenuItemList::SendTextMenuReply(unsigned short itemId)` candidate, but keep it non-emitting unless xrefs/source route are found.
- Apply descriptive GrafPort helper names used by `DrawListItem` only after checking the local GrafPort naming convention so helper labels remain consistent project-wide.

Low/no direct action:

- Do not rename the scalar deleting destructor child to a source destructor method in final docs. Keep [UID:00037H] as compiler-generated deleting destructor wrapper.
- Do not use generated `ClientItemMenuItemList` labels for any `TextMenuItemList` destructor path.

## Open Questions Closed Or Remaining

Closed:

- The page should remain source-bearing, not no-code.
- The old `95/95` no-C++ rationale is stale under the active validator gate.
- Row record layout is `unsigned short itemId` plus `wchar_t label[256]`.
- `+0x14c/+0x150/+0x154` are list-local mirrors of owner text-menu context and owner pointer.
- `AddTextEntry` is a real source helper but not the only append route.
- `0x00519840` is an owner-dialog activation/selection-state forwarder, not `UpdateScrollButtons`.
- Destructor thunk/scalar-delete children are compiler-generated and should remain no-code.
- `TextMenuDialogs.cpp` is the correct source route; `ListPane`, `TextInputMenuDialog`, standalone file, and `ArgumentedMenuDialogs` routes are rejected.

Remaining, with score impact:

- Exact original spelling for `0x00519840` remains unproven. The recommended descriptive name `ForwardOwnerSelectionState` is strong enough for docs/C++ but caps confidence below final-source levels.
- Exact GrafPort helper names around `0x004b9660`, `0x004b9680`, `0x004b9690`, `0x004b9600`, and `0x004bab70` remain dependent on the broader GrafPort naming audit. Use descriptive names in this class page and mark them as inferred if needed.
- `0x005195f0` and `0x00519720` have strong behavior but no recovered direct route. Document them as raw no-xref reply serializers and do not emit as normal source until route evidence appears.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B012","command_id":"000000004165","destination_path":"executed-b-agent-research/B012/0000ET-TextMenuItemList-class-source-quality.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:35","uid":"0000ET"} -->
<!-- {"agent":"B012","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 0000ET-TextMenuItemList-class-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B012/0000ET-TextMenuItemList-class-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"0000ET"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
