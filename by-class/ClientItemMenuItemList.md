*** UID:00002Q | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000KF | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000KF | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL:40 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
// ClientItemMenuItemList definitions are emitted by source child UID0001BQ.
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
struct ClientItemMenuEntry
{
    unsigned char actionId;
    unsigned char reserved0;
    unsigned short itemId;
    unsigned char itemStyle;
    unsigned char reserved1;
    wchar_t name[256];
};

class ClientItemMenuItemList : public ListPane
{
public:
    ClientItemMenuItemList(unsigned char packetSubtype,
                           unsigned int menuObjectId,
                           unsigned short menuOptionId,
                           ClientItemMenuDialog *owner);

    void AppendAction(unsigned char actionId,
                      unsigned short itemId,
                      unsigned char itemStyle,
                      const wchar_t *name);
    void SendSelectedAction();
    void SendAction(unsigned char actionId);

    void OnItemActivated() override;
    void DrawListEntry(int rowIndex, void *rowData,
                       RectBounds *rowBounds) override;

private:
    unsigned char m_packetSubtype;
    unsigned char m_reserved0[3];
    unsigned int m_menuObjectId;
    unsigned short m_menuOptionId;
    unsigned short m_reserved1;
    ClientItemMenuDialog *m_owner;
};
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# ClientItemMenuItemList

## Status

- Confidence: strong for item-menu list behavior, corrected row layout, selected/explicit action packet semantics, vtable identity, and shared destructor exclusion; medium-high for exact original helper/prototype names.
- Likely source file: [UID:0000KF][ItemMenuDialogs](by-file/ItemMenuDialogs.md)
- Main address range: [UID:0001BQ][0x0051c470-0x0051ca3c.ClientItemMenuItemList](by-memory/0x0051c470-0x0051ca3c.ClientItemMenuItemList.md)
- Vtable family: [UID:0001Y5][MerchantMenuDialogVtableFamily](by-type/by-vtable/MerchantMenuDialogVtableFamily.md)
- Autogen route: [UID:0000KF][ItemMenuDialogs](by-file/ItemMenuDialogs.md). This class now satisfies the parent/exact-child documentation gate and the memory page carries first-draft C++; exact original helper/prototype names remain inferred.

## Class Purpose

`ClientItemMenuItemList` is the row-list widget for client-side item action menus. It stores packet/item context from the owning dialog, appends locally available inventory item rows, forwards activation into the shared item-action context, and draws icon/name rows.

## Ownership And Behavior

This list is a private row-list companion for [UID:00002P][ClientItemMenuDialog](by-class/ClientItemMenuDialog.md), under the item-menu dialog source family. The constructor has two documented caller refs from the client item-menu dialog, and the memory cluster is already attached to [UID:0000KF][ItemMenuDialogs](by-file/ItemMenuDialogs.md). The vtable family places the primary/secondary/tertiary `ClientItemMenuItemList` tables beside the server item and spell menu list companions.

| Area | Evidence | Notes |
| --- | --- | --- |
| Construction/context | `0x0051c470-0x0051c4dc` | Builds the `ListPane` base, stores packet/menu context at `+0x14c/+0x150/+0x154/+0x158`, and installs three vtable views. |
| Row building | `0x0051c4e0-0x0051c548` | Raw helper-shaped code appends local client item rows with action id, item id/style, and name; remains below final-source quality only because IDA does not model it as a function start. |
| Packet helpers | `0x0051c550-0x0051c603`, `0x0051c610-0x0051c6ac` | Build opcode `0x39` payloads from the selected row or a caller-supplied action byte, using the constructor-saved context fields. B013 narrows the client action shell to the length-`9` selected-action packet. |
| Activation/draw | `0x0051c6b0-0x0051ca3c` | Activation forwards through the owning context at `+0x158`; draw handles selected/unselected row rendering, icon paths, and high-resolution/legacy layout branches. |
| Destructor evidence | [UID:0001BY][0x00520ad1-0x00520ae7.SharedClientSpellMenuListDestructorThunks](by-memory/0x00520ad1-0x00520ae7.SharedClientSpellMenuListDestructorThunks.md), [UID:0001C1][0x00520c20-0x00520c5b.SharedListPaneScalarDeletingDestructor](by-memory/0x00520c20-0x00520c5b.SharedListPaneScalarDeletingDestructor.md) | The destructor glue is shared with spell menu item-list vtables and should rebuild through class declarations/list cleanup, not as private handwritten client-item code. |

## Method Notes

| Method or range | Address | Role |
| --- | --- | --- |
| `ClientItemMenuItemList` | `0x0051c470-0x0051c4dc` | Constructs the `ListPane` with client item-menu row geometry, stores packet/item context fields, and installs three vtables. |
| append row helper | `0x0051c4e0-0x0051c548` | Builds/appends a client item row from item code, item id/style, and display label. |
| selected-action packet helper | `0x0051c550-0x0051c603` | Builds opcode `0x39` payload for the current selected row. |
| explicit-action packet helper | `0x0051c610-0x0051c6ac` | Builds opcode `0x39` payload for a caller-supplied item action byte. |
| `OnItemActivated` thunk | `0x0051c6b0-0x0051c6bb` | Loads owner/context from `this + 0x158` and jumps to shared activation logic at `0x0049de70`. |
| `DrawListEntry` | `0x0051c6c0-0x0051ca3c` | Draws selected/unselected item rows with icon and ellipsis-truncated item name in high-resolution and legacy layouts. |
| shared destructor glue | `0x00520ad1`, `0x00520adc`, `0x00520c20` | Secondary/tertiary adjustor thunks and shared scalar deleting destructor also referenced by spell menu item list vtables. |

## Row Layout And Packet Semantics

The client row is `ClientItemMenuEntry`, `sizeof == 0x206`. This layout is now first-draft C++ ready in [UID:0001BQ][0x0051c470-0x0051ca3c.ClientItemMenuItemList](by-memory/0x0051c470-0x0051ca3c.ClientItemMenuItemList.md).

| Offset | Field | Notes |
| --- | --- | --- |
| `+0x000` | `unsigned char actionId` | Raw append writes a byte; selected packet helper serializes it as the client action. |
| `+0x001` | `unsigned char reserved` | Padding/copied stack byte with no proven semantic read. |
| `+0x002` | `unsigned short itemId` | Raw append writes a word; draw uses it with `itemStyle` for item imagery. |
| `+0x004` | `unsigned char itemStyle` | Raw append writes a byte; draw uses it with `itemId`. |
| `+0x005` | `unsigned char reserved2` | Padding/copied stack byte with no proven semantic read. |
| `+0x006` | `wchar_t name[256]` | Copied by `_wcscpy_s`, drawn as the row label, and ellipsis-truncated in draw paths. |

The source-facing helpers are `AppendAction(unsigned char actionId, unsigned short itemId, unsigned char itemStyle, const wchar_t* name)`, `SendSelectedAction()`, and `SendAction(unsigned char actionId)`. Client opcode `0x39` serializes `m_packetSubtype`, `m_menuObjectId`, `m_menuOptionId`, and selected/explicit `actionId`; B013 supersedes older trailing-null wording for the selected client action path. Shared destructor thunks and `0x00520c20` remain compiler-generated glue; source reconstruction should use ordinary class/list cleanup rather than handwritten scalar deleting destructor code.

## Evidence Notes

- IDA MCP confirms `0x0051c470`, `0x0051c6b0`, and `0x0051c6c0` as functions.
- IDA disassembly confirms raw helper-shaped code at `0x0051c4e0`, `0x0051c550`, and `0x0051c610`, though those addresses are not currently function starts.
- IDA xrefs show `ClientItemMenuDialog` constructs this list from `0x0051ba35` and `0x0051bf64`.
- IDA xrefs show destructor thunks `0x00520ad1` and `0x00520adc`, and scalar deleting destructor `0x00520c20`, are shared by `ClientItemMenuItemList`, `ServerSpellMenuItemList`, and `ClientSpellMenuItemList` vtables.
- 2026-06-20 B001 recheck resolves the exact destructor routing as shared compiler output: primary vtable `0x0061f0a4` routes to [UID:0001C1][0x00520c20-0x00520c5b.SharedListPaneScalarDeletingDestructor](by-memory/0x00520c20-0x00520c5b.SharedListPaneScalarDeletingDestructor.md), secondary `0x0061f12c` routes to [UID:0001BY][0x00520ad1-0x00520ae7.SharedClientSpellMenuListDestructorThunks](by-memory/0x00520ad1-0x00520ae7.SharedClientSpellMenuListDestructorThunks.md) thunk `0x00520ad1`, and tertiary `0x0061f15c` routes to thunk `0x00520adc`. The shared wrapper's `0x15c` / 348-byte size immediate (Verified with `int_convert.py`) is the complete-object size for this menu-item-list layout, not a row field. Source reconstruction should use an ordinary implicit/empty destructor plus `ListPane::~ListPane()`, not a hand-authored scalar deleting destructor.
- Existing generated-owner notes treat `0x004f3b60` as `ClientItemMenuItemList::~ClientItemMenuItemList`, but IDA caller fanout shows it is broad `ListPane` cleanup, not a private client item-menu method.
- 2026-06-14 C001 IDA MCP recheck confirms constructor `0x0051c470` size `0x6c`, activation thunk `0x0051c6b0` size `0x0b`, draw virtual `0x0051c6c0` size `0x37c`, shared adjustor thunks `0x00520ad1`/`0x00520adc`, shared scalar deleting destructor `0x00520c20` size `0x3b`, and successor `ServerSpellMenuDialog` boundary at `0x0051ca40`.
- The same live pass reconfirms raw/non-function status and no direct raw-start xrefs for `0x0051c4e0`, `0x0051c550`, and `0x0051c610`, constructor callers at `0x0051ba35` and `0x0051bf64`, vtable stores to `0x0061f0a4`, `0x0061f12c`, and `0x0061f15c`, activation/draw vtable slots at `0x0061f120` and `0x0061f124`, and shared destructor refs from spell/client item-list vtables.
- Boundary bytes confirm `0x0051c46d-0x0051c470`, `0x0051c4dc-0x0051c4e0`, and `0x0051ca3c-0x0051ca40` are `0xcc` alignment gaps around the modeled/raw bodies.

## 2026-08-22 UID0000KF Accepted Declaration

The formal H channel is the complete private list declaration at ItemMenuDialogs H source position 40. `ClientItemMenuEntry` is exactly `0x206`: action id `+0`, reserved `+1`, item id `+2`, item style `+4`, reserved `+5`, and `wchar_t name[256]` at `+6`. The complete list object remains `0x15c`, with constructor context at `+0x14c/+0x150/+0x154/+0x158`; its base construction is `ListPane(0x206,0x10,0xe4,0x18,false,true,1)`.

UID0001BQ supplies six authored bodies: constructor, direct-copy `AppendAction`, void negative-index-only selected sender, void explicit sender, `OnItemActivated()`, and `DrawListEntry(int,void *,RectBounds *)`. The three raw helper starts have zero direct start xrefs but exact complete bodies and in-cluster callers. Both send paths write opcode `0x39`, subtype, object id, option id, and action id; byte 9 is local-only and `QueueAndSendPacket(...,9)` sends exactly nine bytes. No null-name fallback, selected upper-bound/null-entry guard, boolean result, synthetic owner notifier, or `DrawContext` interface is retained.

The class has an implicit/empty ordinary destructor; UID0001BY adjustors and UID0001C1 shared scalar deleting glue are compiler products shared with spell lists. Completion/confidence are `94/94`; the remaining cap is private lexical spelling and unproven compile/byte parity.

## Score Rationale

| Field | Value | Rationale |
| --- | ---: | --- |
| Completion | 94 | Purpose, object/row layout, six-body inventory, constructor callers, raw-helper liveness, exact packet length, activation/draw behavior, implicit/compiler destructor split, formal H declaration, and source routing are complete. |
| Confidence | 94 | Current class, memory, file, vtable, exact-byte, and generated-route evidence agree; remaining uncertainty is lexical and compile/byte parity rather than behavior or ownership. |

## Cross-References

- [UID:0000KF][ItemMenuDialogs](by-file/ItemMenuDialogs.md)
- [UID:0001Y5][MerchantMenuDialogVtableFamily](by-type/by-vtable/MerchantMenuDialogVtableFamily.md)
- [UID:0000KE][ItemDialogs](by-file/ItemDialogs.md)
- [UID:0001BQ][0x0051c470-0x0051ca3c.ClientItemMenuItemList](by-memory/0x0051c470-0x0051ca3c.ClientItemMenuItemList.md)
- [UID:00002P][ClientItemMenuDialog](by-class/ClientItemMenuDialog.md)
- [UID:0000D0][ServerItemMenuItemList](by-class/ServerItemMenuItemList.md)
- [UID:0000D4][ServerSpellMenuItemList](by-class/ServerSpellMenuItemList.md)
- [UID:00002S][ClientSpellMenuItemList](by-class/ClientSpellMenuItemList.md)
- [UID:00007A][ListPane](by-class/ListPane.md)
- [UID:0001BY][0x00520ad1-0x00520ae7.SharedClientSpellMenuListDestructorThunks](by-memory/0x00520ad1-0x00520ae7.SharedClientSpellMenuListDestructorThunks.md)
- [UID:0001C1][0x00520c20-0x00520c5b.SharedListPaneScalarDeletingDestructor](by-memory/0x00520c20-0x00520c5b.SharedListPaneScalarDeletingDestructor.md)

## Changes

- 2026-06-27 B015 rejected-report amendment support sync: [UID:0001BQ][0x0051c470-0x0051ca3c.ClientItemMenuItemList](by-memory/0x0051c470-0x0051ca3c.ClientItemMenuItemList.md) is the canonical owner for the client item-menu list method/raw-helper cluster, while [UID:0000KF][ItemMenuDialogs](by-file/ItemMenuDialogs.md) remains the generated emitter/source file route. Current MCP session `b001_000241_20260627` rechecked the formal C++ exactness issues: `AppendAction` passes the name pointer directly to `_wcscpy_s` with no null fallback; `SendSelectedAction` returns `void`, checks only negative selected index before fetching the row, has no upper-bound/null-entry guard, and duplicates the packet build; `SendAction` returns `void`; both send helpers write a local-only zero after the action byte and call `QueueAndSendPacket(..., 9)`.
- What existed before: the page documented item-menu row-list behavior, raw helper-shaped packet functions, draw path, and shared destructor caveat, but metadata was still `0/0`.
- What it was changed to: scores were set to `76/82`.
- Summary and evidence: constructor, append/helper ranges, selected/explicit packet helpers, activation, draw, constructor xrefs, and shared destructor ownership are covered; complete row struct names and final helper ownership remain open.
- 2026-06-05: Marked reconstructable for autogen.
  - Before: `RECONSTRUCTABLE` was blank, leaving the class coverage row unclassified.
  - After: `RECONSTRUCTABLE:TRUE`; legacy parent metadata remained blank because the class completion score was below the then-current attachment gate.
  - Evidence: live IDA MCP confirms modeled method starts at `0x0051c470`, `0x0051c6b0`, and `0x0051c6c0`; constructor callers at `0x0051ba35` and `0x0051bf64` come from `ClientItemMenuDialog`.
- 2026-06-07 A001 parent attachment refresh:
  - Changed to: `COMPLETION:82`, `CONFIDENCE:84`, and legacy parent metadata for [UID:0000KF][ItemMenuDialogs](by-file/ItemMenuDialogs.md).
  - Summary/evidence: the class now mirrors the stronger [UID:0001BQ][0x0051c470-0x0051ca3c.ClientItemMenuItemList](by-memory/0x0051c470-0x0051ca3c.ClientItemMenuItemList.md) parent-gate evidence: exact range, client dialog constructor refs, constructor context fields, raw row/packet helpers, activation/draw virtuals, vtable-family anchors, and shared destructor glue caveat. Final C++ remains blank because raw helper modeling and row/packet field names are not final-source quality.
- 2026-06-14 C001 Goal 2 IDA refresh:
  - Before: `82/84`, with stale legacy parent-field wording and no current IDA roll-up.
  - After: `86/86`, with live IDA 9.1 evidence for constructor/activation/draw/destructor-support sizes, raw helper non-function/no-xref status, constructor caller refs, vtable stores/slots, shared destructor refs, and padding boundaries. Owner/emitter routing remains [UID:0000KF][ItemMenuDialogs](by-file/ItemMenuDialogs.md); final C++ stays blank until raw helper source names and row/packet fields are final-quality.
- 2026-06-20 B001 Rule 26 source-quality sync: score unchanged. Added exact primary/secondary/tertiary destructor route details and clarified that [UID:0001C1][0x00520c20-0x00520c5b.SharedListPaneScalarDeletingDestructor](by-memory/0x00520c20-0x00520c5b.SharedListPaneScalarDeletingDestructor.md) is compiler-generated shared glue, not a class source method.
- 2026-06-20 B002 Rule 26 source-quality incorporation: raised to `88/89`, added the exact `0x206` `ClientItemMenuEntry` layout, named helpers `AppendAction`, `SendSelectedAction`, and `SendAction`, documented opcode `0x39` selected/explicit action payloads, and noted that [UID:0001BQ][0x0051c470-0x0051ca3c.ClientItemMenuItemList](by-memory/0x0051c470-0x0051ca3c.ClientItemMenuItemList.md) now carries first-draft C++ while destructor wrappers remain compiler-generated glue.
- 2026-06-21 B013 Rule 26 source-quality incorporation: score unchanged. Rechecked the client selected action path through [UID:00002P][ClientItemMenuDialog](by-class/ClientItemMenuDialog.md) and [UID:00040E][0x0051b880-0x0051c46d.ClientItemMenuDialogMethods](by-memory/0x0051b880-0x0051c46d.ClientItemMenuDialogMethods.md); updated packet-helper wording to the length-`9` `0x39` action-byte shell and removed stale trailing-null language.
