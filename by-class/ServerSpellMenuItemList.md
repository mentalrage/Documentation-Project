*** UID:0000D4 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:91 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000O2 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000O2 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL:20 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
// ServerSpellMenuItemList definitions are emitted by source child UID0004Y5.
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
struct ServerSpellMenuEntry;

class ServerSpellMenuItemList : public ListPane
{
public:
    ServerSpellMenuItemList(unsigned char packetSubtype,
                            unsigned int menuObjectId,
                            unsigned short menuOptionId,
                            ServerSpellMenuDialog *owner);

    void AppendSpellName(unsigned short reserved, const wchar_t *name);
    bool SendSelectedSpellName();
    bool SendSpellName(const wchar_t *name);

    virtual void NotifyOwnerSpellActivated();
    virtual void DrawListEntry(DrawContext *dc,
                               int index,
                               const ServerSpellMenuEntry *entry,
                               const Rect& bounds);

private:
    unsigned char m_packetSubtype;
    unsigned char m_reserved14d[3];
    unsigned int m_menuObjectId;
    unsigned short m_menuOptionId;
    unsigned short m_reserved156;
    ServerSpellMenuDialog *m_owner;
};
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# ServerSpellMenuItemList

## Status

- Likely source file: [UID:0000O2][SpellMenuDialogs](by-file/SpellMenuDialogs.md).
- Exact method/helper child: [UID:0004Y5][0x0051d700-0x0051db38.ServerSpellMenuItemList](by-memory/0x0051d700-0x0051db38.ServerSpellMenuItemList.md).
- Parent split index: [UID:0001BR][0x0051ca40-0x0051e998.SpellMenuDialogs](by-memory/0x0051ca40-0x0051e998.SpellMenuDialogs.md).
- Direct vtable anchor: [UID:00031X][SpellMenuDialogVtables](by-type/by-vtable/SpellMenuDialogVtables.md).
- Formal source route: this page emits the ordered private-list H declaration and an explicit CPP delegation comment; exact by-memory child UID0004Y5 owns all list definitions. The source declaration, not handwritten ABI glue, causes the documented vtables and deleting wrappers.

## Class Purpose

`ServerSpellMenuItemList` is the list-pane widget for server-supplied spell menu rows. It stores packet/action context, appends server row names, sends selected or explicit row names, forwards activation to the owner, and draws highlighted spell rows with ellipsis truncation.

## Method And Helper Notes

| Method/helper | Address | Role |
| --- | --- | --- |
| constructor | `0x0051d700-0x0051d76c` | Constructs fixed-layout list pane with row size `0x202` and stores context fields. |
| raw `AppendSpellName` | `0x0051d770-0x0051d7c8` | Builds a row with reserved word at `+0`, name text at `+2`, and appends it through `ListPane::AddEntry`. |
| raw `SendSelectedSpellName` | `0x0051d7d0-0x0051d8fd` | Reads selected index `+0x134`, gets the row through `ListPane::GetItem`, and sends row text at `+2`. |
| raw `SendSpellName` | `0x0051d900-0x0051da1f` | Explicit-name opcode `0x39` send helper. |
| activation | `0x0051da20-0x0051da2b` | Loads owner at `+0x158` and tail-jumps to the owner state update. |
| draw | `0x0051da30-0x0051db38` | Draws selected/unselected row background and text from row `+2`, with ellipsis fitting. |

## Evidence Notes

- MCP session `80de0a67` reports constructor refs from `ServerSpellMenuDialog` at `0x0051cbee` and `0x0051d131`.
- The constructor calls `ListPane::ListPane(514, 16, 228, 12, 0, 1, 1)` and stores context at `+0x14c/+0x150/+0x154/+0x158`.
- Raw starts `0x0051d770`, `0x0051d7d0`, and `0x0051d900` have zero direct `xrefs_to`, but they are complete retained helper bodies with row append or packet send behavior, not padding.
- Server rows use reserved word `+0` and display name `+2`; the first word remains named `reserved` because current draw/send/action evidence gives no stronger source-facing semantic.
- Packet sends use opcode `0x39`, context fields `+0x14c/+0x150/+0x154`, string-length byte, multibyte selected row name, and trailing zero.
- Shared destructor thunks and scalar deleting destructor remain compiler output documented by [UID:0001BY][0x00520ad1-0x00520ae7.SharedClientSpellMenuListDestructorThunks](by-memory/0x00520ad1-0x00520ae7.SharedClientSpellMenuListDestructorThunks.md) and [UID:0001C1][0x00520c20-0x00520c5b.SharedListPaneScalarDeletingDestructor](by-memory/0x00520c20-0x00520c5b.SharedListPaneScalarDeletingDestructor.md); do not duplicate them as handwritten source methods.

## Cross-References

- [UID:0004Y5][0x0051d700-0x0051db38.ServerSpellMenuItemList](by-memory/0x0051d700-0x0051db38.ServerSpellMenuItemList.md)
- [UID:0004Y4][0x0051ca40-0x0051d6fd.ServerSpellMenuDialogMethods](by-memory/0x0051ca40-0x0051d6fd.ServerSpellMenuDialogMethods.md)
- [UID:0000O2][SpellMenuDialogs](by-file/SpellMenuDialogs.md)
- [UID:0000D3][ServerSpellMenuDialog](by-class/ServerSpellMenuDialog.md)
- [UID:00002S][ClientSpellMenuItemList](by-class/ClientSpellMenuItemList.md)
- [UID:0001BR][0x0051ca40-0x0051e998.SpellMenuDialogs](by-memory/0x0051ca40-0x0051e998.SpellMenuDialogs.md)
- [UID:00031X][SpellMenuDialogVtables](by-type/by-vtable/SpellMenuDialogVtables.md)
- [UID:0003U0][0x004f3bb0-0x004f3f20.ListPaneItemSelectionStorageHelpers](by-memory/0x004f3bb0-0x004f3f20.ListPaneItemSelectionStorageHelpers.md)
- [UID:0001BY][0x00520ad1-0x00520ae7.SharedClientSpellMenuListDestructorThunks](by-memory/0x00520ad1-0x00520ae7.SharedClientSpellMenuListDestructorThunks.md)
- [UID:0001C1][0x00520c20-0x00520c5b.SharedListPaneScalarDeletingDestructor](by-memory/0x00520c20-0x00520c5b.SharedListPaneScalarDeletingDestructor.md)

## Changes

- 2026-08-22 B002 UID0000OP Gate 2A empty-emitter closure: set ordered emitter position `20`, added the complete private-list H declaration and explicit CPP delegation to UID0004Y5, and preserved compiler-owned destructor/vtable glue.
- 2026-06-23 B001 accepted implementation: raised from `86/88` to `90/91`, linked the new list child, added raw helper inventory, row layout, packet context fields, zero-direct-ref caveat, activation/draw details, shared destructor exclusion, and formal C++ location.
