*** UID:00002S | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:91 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000O2 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000O2 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL:40 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
// ClientSpellMenuItemList definitions are emitted by source child UID0004Y7.
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
struct ClientSpellMenuEntry;

class ClientSpellMenuItemList : public ListPane
{
public:
    ClientSpellMenuItemList(unsigned char packetSubtype,
                            unsigned int menuObjectId,
                            unsigned short menuOptionId,
                            ClientSpellMenuDialog *owner);

    void AppendSpell(unsigned char spellSlot,
                     unsigned short reserved,
                     const wchar_t *name);
    bool SendSelectedSpell();
    bool SendSpell(unsigned char spellSlot);

    virtual void NotifyOwnerSpellActivated();
    virtual void DrawListEntry(DrawContext *dc,
                               int index,
                               const ClientSpellMenuEntry *entry,
                               const Rect& bounds);

private:
    unsigned char m_packetSubtype;
    unsigned char m_reserved14d[3];
    unsigned int m_menuObjectId;
    unsigned short m_menuOptionId;
    unsigned short m_reserved156;
    ClientSpellMenuDialog *m_owner;
};
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# ClientSpellMenuItemList

## Status

- Likely source file: [UID:0000O2][SpellMenuDialogs](by-file/SpellMenuDialogs.md).
- Exact method/helper child: [UID:0004Y7][0x0051e640-0x0051e998.ClientSpellMenuItemList](by-memory/0x0051e640-0x0051e998.ClientSpellMenuItemList.md).
- Parent split index: [UID:0001BR][0x0051ca40-0x0051e998.SpellMenuDialogs](by-memory/0x0051ca40-0x0051e998.SpellMenuDialogs.md).
- Direct vtable anchor: [UID:00031X][SpellMenuDialogVtables](by-type/by-vtable/SpellMenuDialogVtables.md).
- Formal source route: this page emits the ordered private-list H declaration and an explicit CPP delegation comment; exact by-memory child UID0004Y7 owns all list definitions. The source declaration, not handwritten ABI glue, causes the documented vtables and deleting wrappers.

## Class Purpose

`ClientSpellMenuItemList` is the list-pane widget for client-local spell menu rows. It stores packet/action context, stores each row's selected spell slot/action byte, sends selected or explicit spell-slot bytes, forwards activation to the owner, and draws highlighted spell names with ellipsis truncation.

## Method And Helper Notes

| Method/helper | Address | Role |
| --- | --- | --- |
| constructor | `0x0051e640-0x0051e6ac` | Constructs fixed-layout list pane with row size `0x204` and stores context fields. |
| raw `AppendSpell` | `0x0051e6b0-0x0051e711` | Builds a row with one-byte spell slot/action byte at `+0`, reserved word at `+2`, display text at `+4`, and appends it through `ListPane::AddEntry`. |
| raw `SendSelectedSpell` | `0x0051e720-0x0051e7d3` | Reads selected index `+0x134`, gets the row through `ListPane::GetItem`, and sends row byte `+0`. |
| raw `SendSpell` | `0x0051e7e0-0x0051e87e` | Explicit one-byte spell slot/action opcode `0x39` send helper. |
| activation | `0x0051e880-0x0051e88b` | Loads owner at `+0x158` and tail-jumps to the owner state update. |
| draw | `0x0051e890-0x0051e998` | Draws selected/unselected row background and text from row `+4`, with ellipsis fitting. |

## Evidence Notes

- MCP session `80de0a67` reports constructor refs from `ClientSpellMenuDialog` at `0x0051dce7` and `0x0051e189`.
- The constructor calls `ListPane::ListPane(516, 16, 228, 12, 0, 1, 1)` and stores context at `+0x14c/+0x150/+0x154/+0x158`.
- Raw starts `0x0051e6b0`, `0x0051e720`, and `0x0051e7e0` have zero direct `xrefs_to`, but they are complete retained helper bodies with row append or packet send behavior, not padding.
- Client rows use one-byte spell slot/action byte at `+0`, reserved word at `+2`, and display name `+4`. The selected and explicit send helpers serialize the row byte at `+0`; the word at `+2` is not serialized.
- Packet sends use opcode `0x39` and fixed length `9`: opcode, subtype, object/menu id, option id, selected spell slot/action byte, and trailing zero.
- Shared destructor thunks and scalar deleting destructor remain compiler output documented by [UID:0001BY][0x00520ad1-0x00520ae7.SharedClientSpellMenuListDestructorThunks](by-memory/0x00520ad1-0x00520ae7.SharedClientSpellMenuListDestructorThunks.md) and [UID:0001C1][0x00520c20-0x00520c5b.SharedListPaneScalarDeletingDestructor](by-memory/0x00520c20-0x00520c5b.SharedListPaneScalarDeletingDestructor.md); do not duplicate them as handwritten source methods.

## Cross-References

- [UID:0004Y7][0x0051e640-0x0051e998.ClientSpellMenuItemList](by-memory/0x0051e640-0x0051e998.ClientSpellMenuItemList.md)
- [UID:0004Y6][0x0051db40-0x0051e63d.ClientSpellMenuDialogMethods](by-memory/0x0051db40-0x0051e63d.ClientSpellMenuDialogMethods.md)
- [UID:0000O2][SpellMenuDialogs](by-file/SpellMenuDialogs.md)
- [UID:00002R][ClientSpellMenuDialog](by-class/ClientSpellMenuDialog.md)
- [UID:0000D4][ServerSpellMenuItemList](by-class/ServerSpellMenuItemList.md)
- [UID:0001BR][0x0051ca40-0x0051e998.SpellMenuDialogs](by-memory/0x0051ca40-0x0051e998.SpellMenuDialogs.md)
- [UID:00031X][SpellMenuDialogVtables](by-type/by-vtable/SpellMenuDialogVtables.md)
- [UID:0003U0][0x004f3bb0-0x004f3f20.ListPaneItemSelectionStorageHelpers](by-memory/0x004f3bb0-0x004f3f20.ListPaneItemSelectionStorageHelpers.md)
- [UID:0000QK][g_pCollectionData](by-global/g_pCollectionData.md)
- [UID:0001OR][0x0067a748-0x0067a74c.g_pCollectionData](by-memory/0x0067a748-0x0067a74c.g_pCollectionData.md)
- [UID:0001BY][0x00520ad1-0x00520ae7.SharedClientSpellMenuListDestructorThunks](by-memory/0x00520ad1-0x00520ae7.SharedClientSpellMenuListDestructorThunks.md)
- [UID:0001C1][0x00520c20-0x00520c5b.SharedListPaneScalarDeletingDestructor](by-memory/0x00520c20-0x00520c5b.SharedListPaneScalarDeletingDestructor.md)

## Changes

- 2026-08-22 B002 UID0000OP Gate 2A empty-emitter closure: set ordered emitter position `40`, added the complete private-list H declaration and explicit CPP delegation to UID0004Y7, and preserved compiler-owned destructor/vtable glue.
- 2026-06-23 B001 accepted implementation: raised from `85/89` to `90/91`, linked the new list child, added raw helper inventory, row layout, packet context fields, selected spell slot/action byte wording, zero-direct-ref caveat, activation/draw details, shared destructor exclusion, and formal C++ location.
