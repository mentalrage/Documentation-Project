*** UID:0000ET | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000OP | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000OP | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL:20 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
struct TextMenuItemListEntry {
    unsigned short itemId;
    wchar_t label[256];
};

typedef char TextMenuItemListEntrySizeMustBe514[
    (sizeof(TextMenuItemListEntry) == 0x202) ? 1 : -1];

class TextMenuItemList : public ListPane
{
public:
    TextMenuItemList(unsigned char menuType,
                     unsigned int menuId,
                     TextMenuDialog *ownerDialog);

    void AddTextEntry(unsigned short itemId, const wchar_t *label);
    void SendSelectedTextMenuReply();

protected:
    virtual void OnItemActivated();
    virtual void DrawListEntry(int rowIndex, void *rowData,
                               RectBounds *rowBounds);

private:
    void SendTextMenuReply(unsigned short itemId);

    unsigned char m_menuType;              // +0x14c
    unsigned char m_reserved14d[3];
    unsigned int m_menuId;                 // +0x150
    TextMenuDialog *m_ownerDialog;         // +0x154, non-owning
};

typedef char TextMenuItemListSizeMustBe344[
    (sizeof(TextMenuItemList) == 0x158) ? 1 : -1];

TextMenuItemList::TextMenuItemList(unsigned char menuType,
                                   unsigned int menuId,
                                   TextMenuDialog *ownerDialog)
    : ListPane(sizeof(TextMenuItemListEntry), 16, 228, 12, 0, 1, 1),
      m_menuType(menuType),
      m_menuId(menuId),
      m_ownerDialog(ownerDialog)
{
}

void TextMenuItemList::AddTextEntry(unsigned short itemId,
                                    const wchar_t *label)
{
    TextMenuItemListEntry entry;
    entry.itemId = itemId;
    wcscpy_s(entry.label, 256, label);
    AddEntry(&entry);
}

[[CHILDREN]]

void TextMenuItemList::OnItemActivated()
{
    m_ownerDialog->ActivateFocusedControl();
}

void TextMenuItemList::DrawListEntry(int rowIndex, void *rowData,
                                     RectBounds *rowBounds)
{
    const TextMenuItemListEntry *entry =
        static_cast<const TextMenuItemListEntry *>(rowData);
    int textColor = 37;

    if (IsItemSelected(rowIndex)) {
        SetDrawColor(37);
        g_drawPaneRect(this, rowBounds);
        textColor = 128;
    }

    SetTextColor(textColor);
    SetTextOpaque(1);
    SetTextMode(0);
    MoveTo(rowBounds->left, rowBounds->bottom);
    DrawWideText(entry->label, wcslen(entry->label));
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# TextMenuItemList

## Status

- Confidence: accepted `94/94` for the list role, exact layout, inherited-slot method identities, retained reply helpers, nested compiler inlining, source route, and destructor policy. Descriptive GrafPort helper spellings remain bounded implementation names without changing the accepted method identity.
- Likely source file: [UID:0000OP][TextMenuDialogs](by-file/TextMenuDialogs.md)
- Main address range: [UID:0001BN][0x00517ec0-0x0051a417.TextMenuDialogs](by-memory/0x00517ec0-0x0051a417.TextMenuDialogs.md)
- Destructor/thunk range: [UID:0001BX][0x00520abb-0x00520e2b.MenuDialogDestructorThunks](by-memory/0x00520abb-0x00520e2b.MenuDialogDestructorThunks.md)
- Current generated files: `auto-generated/NexusTK/ui/dialogs/TextMenuDialogs.cpp` and `TextMenuDialogs.h`; the old `source-3/simroot_v2/class_TextMenuItemList.cpp` path is historical evidence only.
- Current gate result: clears the active `85/85` source route with [UID:0000OP][TextMenuDialogs](by-file/TextMenuDialogs.md) as owner/emitter. The class declaration includes retained `SendSelectedTextMenuReply()` from [UID:0004HE][0x005195f0-0x0051971d.TextMenuItemListRawSelectedRowReplySerializer](by-memory/0x005195f0-0x0051971d.TextMenuItemListRawSelectedRowReplySerializer.md) and private `SendTextMenuReply(unsigned short itemId)` from [UID:0004HF][0x00519720-0x0051983a.TextMenuItemListRawExplicitIdReplySerializer](by-memory/0x00519720-0x0051983a.TextMenuItemListRawExplicitIdReplySerializer.md). Compiler destructor glue remains non-emitting.

## Class Purpose

`TextMenuItemList` is the private `ListPane`-derived scrollable row list used by `TextMenuDialog`. It stores a text-menu context byte, a menu/dialog id, a non-owning owner dialog pointer, and fixed-size row records containing a 16-bit menu item id followed by UTF-16 label text. It belongs in [UID:0000OP][TextMenuDialogs](by-file/TextMenuDialogs.md), not a standalone list source file, because both constructor callers are inside `TextMenuDialog`, the list mirrors `TextMenuDialog` fields, `TextMenuDialog::OnControlCommand` reads the selected list row, and the adjacent raw helpers serialize the text-menu opcode `0x39` reply shape.

## Source-Facing Layout

| Offset or payload byte | Source-facing name | Evidence and policy |
| --- | --- | --- |
| inherited `+0x000-0x149` | `ListPane` base | Constructor delegates to `ListPane` with row size `514` (`0x202`), count `16`, width `228`, row height `12`, zero/flag parameters, and two truthy list flags. |
| `+0x14a/+0x14b` | unused tail/padding | Wave/class metadata leaves two byte slots before the list-local fields; no behavior was found for them in the B012 pass. |
| `+0x14c` | `m_menuType` / `m_dialogType` | One-byte value copied from `TextMenuDialog +0x274`; opcode `0x39` serializers send the same byte after the opcode. C++ uses `m_menuType` because the class and packet role are menu-facing. |
| `+0x14d-0x14f` | alignment padding | Dword `m_menuId` follows the one-byte type. |
| `+0x150` | `m_menuId` / `m_dialogId` | Dword value copied from `TextMenuDialog +0x270`; opcode `0x39` serializers write it as a big-endian dword. C++ uses `m_menuId` while documenting the dialog-id alias. |
| `+0x154` | `m_ownerDialog` | Non-owning `TextMenuDialog *` passed by the owner constructor; used by the `0x00519840` forwarder and raw reply helpers. The list never deletes this pointer. |
| row `+0x000` | `TextMenuItemListEntry::itemId` | Unsigned 16-bit menu item id. It is read with zero-extension and serialized through the 16-bit packet writer. |
| row `+0x002` | `TextMenuItemListEntry::label[256]` | The remaining `512` row bytes hold `256` UTF-16 characters. `_wcscpy_s(..., 0x100, ...)` uses the destination character count, so decompiler `wchar_t Destination[257]` is a stack-layout artifact caused by naming the buffer after the preceding word id. |

## Method Map

| Address | Method | Role |
| --- | --- | --- |
| `0x00519520-0x00519580` | `TextMenuItemList(unsigned char menuType, unsigned long menuId, TextMenuDialog *ownerDialog)` | Normal source constructor. Allocated with object size `0x158`, calls `ListPane(sizeof(TextMenuItemListEntry), 16, 228, 12, 0, 1, 1)`, stores `m_menuType`, `m_menuId`, and non-owning `m_ownerDialog`, then installs the three TextMenuItemList vtable views. |
| `0x00519590-0x005195e7` | `AddTextEntry(unsigned short itemId, const wchar_t *label)` | Builds a stack `TextMenuItemListEntry`, writes the 16-bit id, copies `label` into `entry.label` with `_wcscpy_s(..., 0x100, ...)`, calls `ListPane::AddEntry`, and returns that result. |
| [UID:0004HE][0x005195f0-0x0051971d.TextMenuItemListRawSelectedRowReplySerializer](by-memory/0x005195f0-0x0051971d.TextMenuItemListRawSelectedRowReplySerializer.md) | `SendSelectedTextMenuReply()` | Retained ordinary source wrapper. Reads inherited `m_selectedIndex`, returns when negative, fetches the row with `GetItem`, then calls private `SendTextMenuReply(entry->itemId)`. The retained binary copy contains the callee inlined after this selected-row prefix and has zero direct routes. |
| [UID:0004HF][0x00519720-0x0051983a.TextMenuItemListRawExplicitIdReplySerializer](by-memory/0x00519720-0x0051983a.TextMenuItemListRawExplicitIdReplySerializer.md) | `SendTextMenuReply(unsigned short itemId)` | Retained private source helper. Serializes opcode `0x39`, `m_menuType`, big-endian `m_menuId`, explicit big-endian `itemId`, optional owner extra text, the guarded non-sent terminator, and sends through `g_packetSender`. Its exact 282-byte body is compiler-inlined into UID0004HE and transitively into live UID0004HC. |
| `0x00519840-0x0051984a` | `OnItemActivated` | Accepted inherited-slot override. Loads `m_ownerDialog` from `this +0x154` into `ECX` and tail-jumps to [UID:0003KO][0x0049de70-0x0049df14.DialogPaneActivateFocusedControlRaw](by-memory/0x0049de70-0x0049df14.DialogPaneActivateFocusedControlRaw.md). The earlier descriptive alias `ForwardOwnerSelectionState` is historical, not current identity. |
| `0x00519850-0x005198d0` | `DrawListEntry(unsigned int itemIndex, const TextMenuItemListEntry *entry, const Rect *itemRect)` | Accepted source-bearing list virtual. Checks `ListPane::IsItemSelected`, fills selected rows through the pane-rect callback, chooses text color `128` for selected or `37` for normal, sets inherited GrafPort/text state, moves to row left/bottom, scans `entry->label`, and draws the wide label text. |
| [UID:00037G][0x00520b55-0x00520b6a.TextMenuItemListDestructorThunks](by-memory/0x00520b55-0x00520b6a.TextMenuItemListDestructorThunks.md) | vtable adjustor thunks | Compiler-generated secondary/tertiary deleting-destructor thunks. The current filename uses final included byte `0x00520b6a`; actual half-open byte coverage is `0x00520b55-0x00520b6b`. |
| [UID:00037H][0x00520df0-0x00520e2b.TextMenuItemListScalarDeletingDestructor](by-memory/0x00520df0-0x00520e2b.TextMenuItemListScalarDeletingDestructor.md) | scalar deleting destructor | Compiler-generated primary deleting-destructor wrapper for the text-menu item-list teardown path. |

## Function Evidence And Source-Quality Decisions

### Constructor `0x00519520-0x00519580`

The constructor is ordinary source logic, not compiler glue. Local export/decompiler evidence shows a `__thiscall` body with an `unsigned char` menu/dialog type, an `unsigned long` menu/dialog id, and an owner pointer. The body delegates to `ListPane` with row size `514`, count/visible count `16`, width `228`, row height `12`, and two truthy list flags, then stores the copied owner context and writes the primary/secondary/tertiary vtable addresses. `TextMenuDialog` constructs the list in both layout branches:

- `0x0051814d`: the `g_useEpfAssets == 1` / high-resolution layout branch allocates `0x158` bytes and passes `TextMenuDialog +0x274`, `TextMenuDialog +0x270`, and the owner `TextMenuDialog *`.
- `0x005186d4`: the standard layout branch allocates the same object size and passes the same owner fields.

Those call sites reject the generated/source-polluted `TextMenu *ownerMenu` type. The receiver owns a non-owning `TextMenuDialog *m_ownerDialog` pointer.

### Row Append Helper `0x00519590-0x005195e7`

`AddTextEntry` is a real source helper and should remain in the class C++ block. It constructs one contiguous stack record: `unsigned short itemId` followed immediately by `wchar_t label[256]`. It copies the caller label with `_wcscpy_s(destination, 0x100, source)` and tail-returns `ListPane::AddEntry(&entry)`, so `int AddTextEntry(unsigned short itemId, const wchar_t *label)` is the best current source signature.

The standard large-list constructor branch calls `AddTextEntry` at `0x005189ed`. The high-resolution/EPF branch duplicates the same row layout inline and calls `ListPane::AddEntry` directly around `0x0051847e`; therefore the docs should not imply `AddTextEntry` is the only append route. The small-menu branch stores ids in `TextMenuDialog +0x280` and builds direct controls instead of using `TextMenuItemList` rows.

### OnItemActivated `0x00519840-0x0051984a`

This virtual body is exactly an owner-dialog forwarder:

```asm
mov ecx, [ecx + 0x154]
jmp 0x0049de70
```

It belongs to `TextMenuItemList` because the vtable slot and this-adjustment evidence identify the receiver as the list, but the behavior is delegated to the owner dialog's focused-control activation helper. The accepted inherited-slot identity is `OnItemActivated`. `ForwardOwnerSelectionState` was a useful pre-slot descriptive alias but is now historical. `UpdateScrollButtons` is rejected because the separate accepted `TextMenuDialog::UpdateActionButton` body at `0x005194c0` calls `ListPane::GetSelectionCount`. `ActivateFocusedControl` remains a descriptive callee name for UID0003KO, not the list method identity.

### DrawListEntry `0x00519850-0x005198d0`

`DrawListEntry` is source-bearing list-row rendering. It calls `ListPane::IsItemSelected`; selected rows set/fill draw color `37` through the global pane-rect callback at `dword_69B3FC` and switch the text color to `128`, while normal rows use text color `37`. The body then calls GrafPort-style helpers at `0x004b9680`, `0x004b9690`, `0x004b9600`, and `0x004bab70`, sets inherited byte `this +0x88` to `1`, scans the wide label at row offset `+2`, and draws the measured label text.

The first-draft C++ intentionally uses descriptive helper names pending the broader GrafPort naming audit: `SetDrawColor`, `SetTextColor`, `SetTextOpaque`, `SetTextMode`, `MoveTo`, `DrawWideText`, and `g_drawPaneRect`. These are source-facing names, not proof of final original spelling. The docs should not regress to uninvestigated `dword_69B3FC`, `sub_4BAB70`, or similar raw-only names without preserving the helper roles.

### Retained Selected-Row Reply And Explicit-Id Sibling

The adjacent bodies form one nested opcode `0x39` source family and explain why the list mirrors `m_menuType`, `m_menuId`, and `m_ownerDialog`. UID0004HE owns selected-row policy; UID0004HF owns the explicit-id packet serializer that the compiler inlined into it.

- [UID:0004HE][0x005195f0-0x0051971d.TextMenuItemListRawSelectedRowReplySerializer](by-memory/0x005195f0-0x0051971d.TextMenuItemListRawSelectedRowReplySerializer.md) is retained source wrapper `SendSelectedTextMenuReply()`. It reads inherited `m_selectedIndex` at `+0x134`, returns when negative, calls `ListPane::GetItem(m_selectedIndex)`, reads unsigned row `itemId` at `+0`, and calls `SendTextMenuReply(entry->itemId)`.
- The exact standalone UID0004HE body is `[0x005195f0,0x0051971d)`, SHA256 `94B5D776499D730276233ECDDBD03FCAC7CD73258CF8B0FEC82868A2EDD16C8A`. It has zero start xrefs, zero external inbound xrefs to all 80 instruction heads, no VA/RVA/raw-offset pointer route, and no vtable cell. Those remain confidence-capping negative evidence, not a dead-code conclusion.
- [UID:0004HF][0x00519720-0x0051983a.TextMenuItemListRawExplicitIdReplySerializer](by-memory/0x00519720-0x0051983a.TextMenuItemListRawExplicitIdReplySerializer.md) is retained private helper `SendTextMenuReply(unsigned short itemId)`. Its exact body `[0x00519720,0x0051983a)`, size 282 and SHA256 `CB928A0115A74BA12B714758CA0A23D6D26C83C7480E418894371E8746C4C65A`, writes opcode `0x39`, list context, explicit id, optional owner string, guarded local terminator, and the pre-terminator send length.
- Source liveness and factoring are established by exact nine-stage alignment across UID0004HF, UID0004HE, and the complete live compiler-inline expansion `[0x0051938f,0x00519492)`, SHA256 `23788D4E9028044606F1B0BBF9C19F80E34F4EEBF966B09B474A57ED4813734C`, inside vtable-routed [UID:0004HC][0x00519210-0x005194b1.TextMenuDialogOnDialogAction](by-memory/0x00519210-0x005194b1.TextMenuDialogOnDialogAction.md). This supports `OnControlCommand -> SendSelectedTextMenuReply -> SendTextMenuReply(itemId)` despite zero direct routes to either retained helper copy.

`SendSelectedTextMenuReply` and private `SendTextMenuReply(unsigned short itemId)` are the best source-facing names supported by class vocabulary, ABI, independent prior inference, and the nested-inline family. No surviving symbol proves their exact lexical spelling, which caps confidence but does not justify raw labels or duplicated developer source. Do not move either serializer to `ListPane`, PacketBuffer, or Socket: those are dependencies, while the fields, opcode, selection policy, and physical placement are TextMenuItemList-specific.

## Destructor And Vtable Layout

`TextMenuItemList` uses the same three-view list-pane vtable shape as the related menu-list companions: a primary list-pane view with 33 slots, a secondary view with 11 slots, and a tertiary view with 2 slots. [UID:00031Y][TextMenuDialogVtables](by-type/by-vtable/TextMenuDialogVtables.md) records constructor `0x00519520` storing the three vtable views at `0x00519560`, `0x00519566`, and `0x00519570`.

The destructor first slots are compiler output, not source-visible class methods:

| View | Vtable slot | Target | Source meaning |
| --- | --- | --- | --- |
| Primary | `0x0061ed48[0]` | [UID:00037H][0x00520df0-0x00520e2b.TextMenuItemListScalarDeletingDestructor](by-memory/0x00520df0-0x00520e2b.TextMenuItemListScalarDeletingDestructor.md) | Primary scalar deleting destructor wrapper generated from the ordinary `TextMenuItemList` destructor. |
| Secondary | `0x0061edd0[0]` | [UID:00037G][0x00520b55-0x00520b6a.TextMenuItemListDestructorThunks](by-memory/0x00520b55-0x00520b6a.TextMenuItemListDestructorThunks.md) thunk `0x00520b55-0x00520b60` | Adjusted deleting-destructor thunk. Best current inherited-layout inference is `this - 0xa0`, forwarding to `0x00520df0`. |
| Tertiary | `0x0061ee00[0]` | [UID:00037G][0x00520b55-0x00520b6a.TextMenuItemListDestructorThunks](by-memory/0x00520b55-0x00520b6a.TextMenuItemListDestructorThunks.md) thunk `0x00520b60-0x00520b6b` | Adjusted deleting-destructor thunk. Best current inherited-layout inference is `this - 0xa4`, forwarding to `0x00520df0`. |

Source reconstruction should model the ordinary `TextMenuItemList` destructor/class layout inside [UID:0000OP][TextMenuDialogs](by-file/TextMenuDialogs.md). Do not emit handwritten `virt_meth_0x520b55`, `virt_meth_0x520b60`, adjusted-this thunks, scalar deleting destructor wrappers, direct source `operator delete` calls, or guarded-size helper calls for the compiler glue pages.

`0x00520df0` is a scalar deleting destructor wrapper generated by the compiler. It calls the inherited `ListPane` destructor at `0x004f3b60` and then applies delete flags: if `flags & 1` is clear it returns `this`, if `flags & 4` is set it takes the sized-delete path for object size `0x158`, otherwise it calls the normal delete helper. The source-level destructor is ordinary/default; `m_ownerDialog` is non-owning and is not freed here, and row storage belongs to the inherited `ListPane` teardown. The generated `ClientItemMenuItemList::~ClientItemMenuItemList()` label is owner/type pollution and should not be copied into this page.

## Evidence Notes

- Wave3 summary: maintains and renders text-menu dialog rows, including entry creation and scalar-destruction behavior.
- IDA/local export evidence confirms all listed modeled starts. The constructor has callers inside `TextMenuDialog` at `0x0051814d` and `0x005186d4`; `AddTextEntry` is called from the large-list branch at `0x005189ed`; the high-resolution branch appends the same row shape directly through `ListPane::AddEntry`.
- `TextMenuDialog::OnControlCommand` retrieves list control id `6` and calls `SendSelectedTextMenuReply()` on action id `1`, then closes. The observed handler bytes contain the helper's full compiler-inline expansion and corroborate `TextMenuItemListEntry::itemId` at row offset `+0` without requiring reconstructed source to reach into list-private fields.
- Historical generated output was useful as lead material but is not current authority: the pre-callback `TextMenu *ownerMenu`, `ClientItemMenuItemList`, and decompiler-sized `label[257]` forms were superseded. Current validator-generated `TextMenuDialogs.cpp` uses the accepted source-facing route.
- 2026-06-11 Batch166 split review added exact non-reconstructable destructor-glue children [UID:00037G][0x00520b55-0x00520b6a.TextMenuItemListDestructorThunks](by-memory/0x00520b55-0x00520b6a.TextMenuItemListDestructorThunks.md) and [UID:00037H][0x00520df0-0x00520e2b.TextMenuItemListScalarDeletingDestructor](by-memory/0x00520df0-0x00520e2b.TextMenuItemListScalarDeletingDestructor.md), replacing the previous reliance on the mixed [UID:0001BX][0x00520abb-0x00520e2b.MenuDialogDestructorThunks](by-memory/0x00520abb-0x00520e2b.MenuDialogDestructorThunks.md) aggregate for exact thunk/destructor boundaries.
- B010 source-routing review confirms [UID:00037G][0x00520b55-0x00520b6a.TextMenuItemListDestructorThunks](by-memory/0x00520b55-0x00520b6a.TextMenuItemListDestructorThunks.md) has no ordinary callers and consists only of two 0x0b-byte vtable-only adjusted deleting-destructor thunks that forward to [UID:00037H][0x00520df0-0x00520e2b.TextMenuItemListScalarDeletingDestructor](by-memory/0x00520df0-0x00520e2b.TextMenuItemListScalarDeletingDestructor.md). The source context is this class, but canonical owner/emitter metadata stays blank on the exact thunk/scalar-wrapper pages because those bytes are compiler-generated ABI support.

## Heuristic And Inference Reanalysis

Accepted source route:

- [UID:0000OP][TextMenuDialogs](by-file/TextMenuDialogs.md), likely physical source `NexusTK/ui/dialogs/TextMenuDialogs.cpp`.
- `TextMenuItemList` is a private/helper class near `TextMenuDialog`, not an independently allocated global list class.
- Exact row payload is `unsigned short itemId; wchar_t label[256];`.
- Exact local fields are the owner context byte at `+0x14c`, the owner/menu id dword at `+0x150`, and the non-owning `TextMenuDialog *` owner pointer at `+0x154`.
- `AddTextEntry`, retained `SendSelectedTextMenuReply`, private retained `SendTextMenuReply(unsigned short)`, `OnItemActivated`, and `DrawListEntry` are source-bearing. Destructor thunks/scalar wrapper remain compiler-generated non-emitting glue.

Rejected alternatives:

- `wchar_t label[257]`: rejected as a decompiler frame artifact that ignores the leading two-byte id and conflicts with row size `0x202` plus `_wcscpy_s(..., 0x100, ...)`.
- Separate id and label pointers: rejected because `ListPane::AddEntry` receives one contiguous stack record.
- `signed short itemId`: mechanically possible but weaker than `unsigned short`, because callers zero-extend and packet serializers write a 16-bit value.
- `TextMenu *ownerMenu`: rejected generated type pollution; both constructor callers pass `TextMenuDialog *`.
- Owning semantics for `+0x154`: rejected because no delete/free path targets the owner pointer.
- Standalone `TextMenuItemList.cpp`, `ListPane.cpp`, `TextInputMenuDialog`, or `ArgumentedMenuDialogs` ownership: rejected by constructor callers, owner field mirrors, opcode `0x39` packet semantics, and source-file family evidence.
- Naming `0x00519840` `UpdateScrollButtons`: rejected; accepted identity is `OnItemActivated`, and the separate `TextMenuDialog::UpdateActionButton` method is at `0x005194c0`. The rejected name is retained only to identify the old alternative.
- Treating either `0x005195f0` or `0x00519720` as blank solely because direct xrefs are zero: rejected. UID0004HE and UID0004HF form a retained wrapper/helper pair whose complete nested behavior survives inline in live UID0004HC.
- Emitting scalar deleting destructor or adjustor thunks as source: rejected as ABI/compiler output.

## Remaining Open Questions

- The inherited vtable slot establishes `OnItemActivated` as the accepted source identity for `0x00519840`. `ForwardOwnerSelectionState` remains only a historical descriptive alias for the proven tail-forwarding behavior.
- Exact GrafPort helper names around `0x004b9660`, `0x004b9680`, `0x004b9690`, `0x004b9600`, and `0x004bab70` remain dependent on the broader GrafPort naming audit. This page uses descriptive names and marks them as inferred.
- Exact original spelling and access tokens for `SendTextMenuReply(unsigned short itemId)` are not preserved. Private access and this spelling are the strongest current human-source inference from ABI, class vocabulary, source order, and nested-inline use; this is a confidence cap rather than an emission blocker.

## Cross-References

- [UID:0000OP][TextMenuDialogs](by-file/TextMenuDialogs.md)
- [UID:0001Y5][MerchantMenuDialogVtableFamily](by-type/by-vtable/MerchantMenuDialogVtableFamily.md)
- [UID:0000ES][TextMenuDialog](by-class/TextMenuDialog.md)
- [UID:0000ER][TextInputMenuDialog](by-class/TextInputMenuDialog.md)
- [UID:0004HE][0x005195f0-0x0051971d.TextMenuItemListRawSelectedRowReplySerializer](by-memory/0x005195f0-0x0051971d.TextMenuItemListRawSelectedRowReplySerializer.md)
- [UID:0004HF][0x00519720-0x0051983a.TextMenuItemListRawExplicitIdReplySerializer](by-memory/0x00519720-0x0051983a.TextMenuItemListRawExplicitIdReplySerializer.md)

## Changes

- 2026-08-21 B002 Gate 2A repair:
  - Replaced active descriptive/stale identities with accepted inherited-slot names `OnItemActivated` and `DrawListEntry`, while retaining `ForwardOwnerSelectionState` and `DrawListItem` only as historical aliases.
  - Reconciled the current generated route and removed the stale copied `proposed` claim-mapping table without removing exact layout, packet, xref, nested-inline, or compiler-disposition evidence.
- 2026-08-15 B006 accepted UID0004HF implementation callback:
  - Raised score from `91/91` to `93/93` and added private declaration `void SendTextMenuReply(unsigned short itemId);`.
  - Reconstructed UID0004HE as the selected-row wrapper and UID0004HF as its retained explicit-id serializer, including exact body identity, packet role, nested live inline chain, source order, zero-route interpretation, and lexical-confidence cap.
  - Replaced all independently unresolved/blank/self-contained UID0004HF conclusions while preserving exact negative route evidence and compiler-glue exclusions.
- 2026-08-14 B005 accepted UID0004HE source-quality callback:
  - Changed score from `89/88` to `91/91` and inserted the public `SendSelectedTextMenuReply()` declaration after `AddTextEntry`.
  - Incorporated the exact target ABI, selected-index/GetItem behavior, row-id and opcode `0x39` packet order, optional owner-string path, cursor guard, non-sent terminator, all-head zero-route evidence, range hash, active UID0004HC inline counterpart, source placement, and compiler exclusions.
  - Preserved UID0004HF as independently unresolved and historicalized only the obsolete blanket conclusion that both zero-xref serializers must remain blank.
- 2026-07-04 B009 accepted UID0001BN split/container callback:
  - Added cross-links to exact blank-C++ no-route raw serializer children [UID:0004HE][0x005195f0-0x0051971d.TextMenuItemListRawSelectedRowReplySerializer](by-memory/0x005195f0-0x0051971d.TextMenuItemListRawSelectedRowReplySerializer.md) and [UID:0004HF][0x00519720-0x0051983a.TextMenuItemListRawExplicitIdReplySerializer](by-memory/0x00519720-0x0051983a.TextMenuItemListRawExplicitIdReplySerializer.md).
  - Preserved existing source-emitting `TextMenuItemList` ordinary method C++ as already present; no class metadata change.
- Before: reconstruction autogen metadata was unclassified.
- Changed to: marked `RECONSTRUCTABLE:TRUE` and attached to [UID:0000OP][TextMenuDialogs](by-file/TextMenuDialogs.md).
- Evidence: 2026-06-05 IDA MCP on `NexusTK.exe` (`md5 4247e04e20b65d6414c7238aa8ff5515`) confirmed the documented constructor, entry append helper, selection-state forwarder, row drawing method, adjustor thunks, and scalar deleting destructor at `0x00519520`, `0x00519590`, `0x00519840`, `0x00519850`, `0x00520b55`, `0x00520b60`, and `0x00520df0`; this page and parent [UID:0000OP][TextMenuDialogs](by-file/TextMenuDialogs.md) both meet the 80/80 parent gate. Historical no-code policy was superseded by the 2026-06-21 B012 Rule 26 pass; destructor glue remains compiler output and should not be emitted as handwritten methods.
- Before: completion/confidence were unevaluated at `0/0`.
- Changed to: completion `84`, confidence `82`.
- Evidence: the page documents private list role, row layout, constructor/add/forwarder/draw/destructor-thunk ranges, caller evidence, and current emitted-source omissions; confidence remains capped by omitted helper/thunk bodies.
- 2026-06-11 A002 Batch166 destructor-glue split:
  - Before: `84/82`; the list behavior was documented, but the destructor-thunk evidence stayed inside a mixed island and below the strict 85/85 gate.
  - Changed to: `86/85`, with exact non-reconstructable children [UID:00037G][0x00520b55-0x00520b6a.TextMenuItemListDestructorThunks](by-memory/0x00520b55-0x00520b6a.TextMenuItemListDestructorThunks.md) and [UID:00037H][0x00520df0-0x00520e2b.TextMenuItemListScalarDeletingDestructor](by-memory/0x00520df0-0x00520e2b.TextMenuItemListScalarDeletingDestructor.md).
  - Evidence: the split records the `0x00520b55-0x00520b6a` adjustor pair, `0x00520df0-0x00520e2b` scalar deleting destructor, vtable refs, endpoint padding before [UID:0001C3][0x00520e30-0x005227c6.MessageAndMessageShowPane](by-memory/0x00520e30-0x005227c6.MessageAndMessageShowPane.md), and exact neighboring boundaries.
- 2026-06-21 B010 Rule 26 source-routing sync:
  - Score unchanged at `86/85`.
  - Added the primary/secondary/tertiary destructor slot layout, exact [UID:00037G][0x00520b55-0x00520b6a.TextMenuItemListDestructorThunks](by-memory/0x00520b55-0x00520b6a.TextMenuItemListDestructorThunks.md) half-open coverage `0x00520b55-0x00520b6b`, vtable slots `0x0061ed48`/`0x0061edd0`/`0x0061ee00`, constructor table-store route, inherited-layout adjustor inference, and ordinary-destructor-only source policy.
- 2026-06-21 B012 Rule 26 source-quality incorporation:
  - Changed score from `86/85` to `89/88`.
  - Added first-draft C++ for the source-bearing constructor, `AddTextEntry`, `ForwardOwnerSelectionState`, and `DrawListItem`, with `TextMenuItemListEntry { unsigned short itemId; wchar_t label[256]; }`, `m_menuType`, `m_menuId`, and non-owning `m_ownerDialog`.
  - Closed the stale below-`95/95` no-code rationale under the active `85/85` gate. Kept raw selected-row/explicit-id opcode `0x39` reply serializers documented as no-route neighbors rather than emitted source methods, and kept destructor adjustor/scalar-wrapper bytes as non-emitting compiler glue.
  - Preserved rejected alternatives and inference outcomes: generated `TextMenu *ownerMenu`, `ClientItemMenuItemList`, `label[257]`, standalone/list/input/argumented owner routes, `UpdateScrollButtons` for `0x00519840`, raw helper emission without route evidence, and source-authored scalar deleting destructor code are all rejected.

## B002 UID0000OP Accepted Whole-File Reconciliation

Private 0x158 list/0x202 row, fields +0x14c/+0x150/+0x154, position 20, slots OnItemActivated/DrawListEntry, and retained reply helpers.

### Exact Accepted Inventory Disposition

| ID | Exact identity / range | O/E/P | Historical pre-callback -> accepted current score and metadata | CPP/H/compiler and generated disposition | Destination / claim |
| --- | --- | --- | --- | --- | --- |
| I020 | `TextMenuItemList` constructor `[0x00519520,0x00519581)`, SHA256 `0D6A1E631E7D8E5E6B9A16FAAB0AB03D894BD15B2662FEF5EEBF73C2D315085B` | O `0000OP`; E `0000OP`; P `0000ET` | UID0000ET `93/93 -> 94/94`; true; position blank -> `20` | UID0000ET CPP only; D25850 source present, callback preserves/repairs private type order | UID0000ET / C034 |
| I021 | `TextMenuItemList::AddTextEntry [0x00519590,0x005195e8)`, SHA256 `EF5C430022AF8A12D745CB0EF67D7C07DF8B461E00312CBBBC0DFC4DB9CA33F5` | O `0000OP`; E `0000OP`; P `0000ET` | UID0000ET `93/93 -> 94/94`; true; position blank -> `20` | UID0000ET CPP only; D25850 source present, callback preserves exact row storage | UID0000ET / C035 |
| I022 | retained `TextMenuItemList::SendSelectedTextMenuReply [0x005195f0,0x0051971d)`, SHA256 `94B5D776499D730276233ECDDBD03FCAC7CD73258CF8B0FEC82868A2EDD16C8A` | O `0000ET`; E `0000ET`; P `0000ET` | UID0004HE stays `93/94`; true; position follows class `20` | child CPP; no H; D25850 retained body present, callback changes only caller spelling as specified | UID0004HE / C036 |
| I023 | raw retained `TextMenuItemList::SendTextMenuReply [0x00519720,0x0051983a)`, SHA256 `CB928A0115A74BA12B714758CA0A23D6D26C83C7480E418894371E8746C4C65A` | O `0000ET`; E `0000ET`; P `0000ET` | UID0004HF stays `93/94`; true; position follows class `20` | child CPP; no H; D25850 retained body present; IDA remains raw with already-present AP | UID0004HF / C037 |
| I024 | `TextMenuItemList::OnItemActivated [0x00519840,0x0051984b)`, SHA256 `F2C071C8204BCC00E278617B3B90AB449ECC07B06E405ED3D5D305B6C0B4C98F` | O `0000OP`; E `0000OP`; P `0000ET` | UID0000ET `93/93 -> 94/94`; true; position blank -> `20` | UID0000ET CPP only; D25850 old inherited name, callback repairs | UID0000ET / C038 |
| I025 | `TextMenuItemList::DrawListEntry [0x00519850,0x005198d1)`, SHA256 `717048638DECF81230979B110517B11C2E3883CF0D5AE40705B28287ABC0BBB6` | O `0000OP`; E `0000OP`; P `0000ET` | UID0000ET `93/93 -> 94/94`; true; position blank -> `20` | UID0000ET CPP only; D25850 old inherited name, callback repairs | UID0000ET / C039 |
| I053 | private `TextMenuItemListEntry`, size `0x202` | O `0000OP`; E `0000OP`; P `0000ET` | UID0000ET `93/93 -> 94/94`; true; position `20` | CPP only; D25850 representation incomplete, callback emits before list class | UID0000ET / C011 |
| I054 | private `TextMenuItemList`, size `0x158` | O `0000OP`; E `0000OP`; P `0000ET` | UID0000ET `93/93 -> 94/94`; true; position `20` | CPP only; D25850 source exists with stale inherited labels, callback repairs | UID0000ET / C011 |

### Exact Caller / Xref Disposition

| ID | Exact inbound code set/count | Exact inbound data set/count | Exact outgoing call disposition |
| --- | --- | --- | --- |
| I020 | `{51814d,5186d4}` / 2 | `{}` / 0 | target `{4f3a50}` |
| I021 | `{5189ed}` / 1 | `{}` / 0 | targets `{5cd657,4f3c50,5c772f}` |
| I022 | `{}` / 0 | `{}` / 0 | targets `{4f3dc0,516030,575380,5753f0,5753a0,584540,5757d0,574bb0,5c772f,5c7655}` |
| I023 | `{}` / 0 | `{}` / 0 | calls `519736->516030,51974e->575380,519771->575380,519792->5753f0,5197b4->5753a0,5197ef->584540,5197f5->5757d0,519820->574bb0,51982a->5c772f,519835->5c7655` |
| I024 | `{}` / 0 | `{61edc4}` / 1 | none; the bounded body contains no call instruction |
| I025 | `{}` / 0 | `{61edc8}` / 1 | targets `{4f3f00,4b9660,4b9680,4b9690,4b9600,4bab70}` |
| I053 | not an address entity | not an address entity | source row type; no independent instruction body |
| I054 | not an address entity | not an address entity | source class; code call closure is I020-I025 |

The formal source channel above is authoritative. Older generated names and body-only sketches are dated provenance; compiler vtables, RTTI, adjustor thunks, and deleting wrappers are regenerated from ordinary source and are not handwritten. This is first-party NexusTK source, so no third-party import directive applies.
