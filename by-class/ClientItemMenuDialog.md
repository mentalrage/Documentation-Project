*** UID:00002P | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000KF | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000KF | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL:30 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
// ClientItemMenuDialog definitions are emitted by source child UID00040E.
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
class ClientItemMenuDialog : public MerchantDialogPane
{
public:
    ClientItemMenuDialog(const RectBounds& bounds,
                         const unsigned char *payload,
                         unsigned char menuMode);
    virtual ~ClientItemMenuDialog() {}

    void OnControlCommand(int controlId, int notifyCode) override;
    void UpdateActionButton() override;

private:
    unsigned char m_packetSubtype;
    unsigned char m_reserved[3];
};
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# ClientItemMenuDialog

## Status

- Confidence: strong for behavior and item-menu placement.
- Likely source file: [UID:0000KF][ItemMenuDialogs](by-file/ItemMenuDialogs.md), under the broader [UID:0000KE][ItemDialogs](by-file/ItemDialogs.md) family
- Address range: exact method child [UID:00040E][0x0051b880-0x0051c46d.ClientItemMenuDialogMethods](by-memory/0x0051b880-0x0051c46d.ClientItemMenuDialogMethods.md), indexed by [UID:0001BO][0x0051a520-0x0051c46d.ItemMenuDialogs](by-memory/0x0051a520-0x0051c46d.ItemMenuDialogs.md)
- Current generated files: `auto-generated/NexusTK/ui/dialogs/ItemMenuDialogs.cpp` and `ItemMenuDialogs.h`; the old `source-3/simroot_v2/class_ClientItemMenuDialog.cpp` path is historical evidence only.
- Autogen status: attached to direct file parent [UID:0000KF][ItemMenuDialogs](by-file/ItemMenuDialogs.md). First-draft C++ for the exact dialog methods now lives in [UID:00040E][0x0051b880-0x0051c46d.ClientItemMenuDialogMethods](by-memory/0x0051b880-0x0051c46d.ClientItemMenuDialogMethods.md); [UID:0001BQ][0x0051c470-0x0051ca3c.ClientItemMenuItemList](by-memory/0x0051c470-0x0051ca3c.ClientItemMenuItemList.md) carries the private client row-list C++.

## Class Purpose

`ClientItemMenuDialog` is the client-side item context menu. It builds local menu actions for an item, dispatches selected commands, and keeps the action state synchronized with selection and mode flags.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| `ClientItemMenuDialog` | `0x0051b880-0x0051c30a` | Builds the client-side item action menu from bounds, packet payload, and inherited menu mode flag, then wires the client item-list rows into the dialog. |
| `OnControlCommand` | `0x0051c310-0x0051c422` | Dispatches command id `1` selected-action sends, command id `2` shared request/cancel sends, and command id `3` close-only behavior. |
| `UpdateActionButton` | `0x0051c430-0x0051c46d` | Enables/disables local item menu actions and ends before the `0x0051c470` client list constructor. |

## Field And Payload Notes

| Offset | Field | Evidence |
| --- | --- | --- |
| inherited `+0x26c` | `menuMode` / inherited mode flag | Constructor argument 3 is stored into inherited `MerchantDialogPane` state; factory subtype `5` currently passes `0`. |
| inherited `+0x270` | `unsigned int m_menuObjectId` | Owned by `MerchantDialogPane`, populated from payload bytes `1..4` through the big-endian dword reader, reused by command id `2`, and copied into the client list's distinct list-owned identifier. The dialog does not redeclare this base field. |
| `+0x274` | `unsigned char m_packetSubtype` | Populated from payload byte `0` and forwarded to `ClientItemMenuItemList`. |
| `+0x275..+0x277` | padding | No additional client-dialog-owned fields were found in this method range. |

The constructor source shape is `ClientItemMenuDialog(const RectBounds& bounds, const unsigned char *payload, unsigned char menuMode)`. [UID:000238][0x00517450-0x00517d23.MenuDialogFactoryHelpers](by-memory/0x00517450-0x00517d23.MenuDialogFactoryHelpers.md) reaches it through subtype `5` / `kClientItemMenu`, using `InitDlgMerc1Bounds`; older `const Rect&` spelling was a stale alias. The constructor calls `MerchantDialogPane(menuMode)`, parses the payload as dialog data, assigns the big-endian object id to inherited `m_menuObjectId`, parses object status/image at `payload + 6`, converts text to UTF-16, reads `menuOptionId`, and constructs `ClientItemMenuItemList(m_packetSubtype, m_menuObjectId, menuOptionId, this)`. It then resolves packet-supplied action bytes through UID0003U9 into local inventory-backed rows. The list receives a copied identifier but owns that distinct list field; the dialog does not redeclare the base dword.

## Layout Branches

The constructor contains two layout/resource branches selected by `g_useEpfAssets` / `byte_66DA97`:

| Branch | Resources | Approximate controls |
| --- | --- | --- |
| current EPF | `DLGMERC1.EPF`, `PAL01.PAL` | Background `(0,0,315,353)`, object image `(20,20,94,128)`, text `(105,40,276,128)`, list `(36,144,294,288)`, action/cancel/close buttons around `(44,310,107,334)`, `(121,310,184,334)`, and `(198,310,261,334)`. |
| legacy EPD | `DLGMERC1.EPD`, `NPAL8.PAL` | Background `(0,0,314,356)`, object image `(35,37,72,92)`, text `(122,37,266,133)`, list `(36,141,278,285)`, action/cancel/close buttons around `(44,306,116,322)`, `(121,306,193,322)`, and `(198,306,270,322)`. |

Control id `1` is the primary action button, control id `6` is the list host whose embedded list pointer is read at host `+0x108`, and control id `3` is the default close/cancel control used during constructor setup.

## Rule 26 Source-Quality Notes

B002's 2026-06-19/20 aggregate report is now incorporated through exact source-bearing child [UID:00040E][0x0051b880-0x0051c46d.ClientItemMenuDialogMethods](by-memory/0x0051b880-0x0051c46d.ClientItemMenuDialogMethods.md). The broad [UID:0001BO][0x0051a520-0x0051c46d.ItemMenuDialogs](by-memory/0x0051a520-0x0051c46d.ItemMenuDialogs.md) page is a non-emitting split index; this class owns the client dialog methods before the `0x0051c46d-0x0051c470` padding and [UID:0001BQ][0x0051c470-0x0051ca3c.ClientItemMenuItemList](by-memory/0x0051c470-0x0051ca3c.ClientItemMenuItemList.md) owns the adjacent client list.

B013's source-quality pass resolves the command helper confusion and supersedes the older trailing-null wording for the selected-action path. Command id `1` fetches control id `6`, reads the embedded list pointer at host `+0x108`, checks the selected index, obtains the selected row, serializes opcode `0x39`, `m_packetSubtype`, inherited `m_menuObjectId`, `m_menuOptionId`, and selected `ClientItemMenuEntry::actionId`, sends length `9`, then closes. Command id `2` calls inherited [UID:0004H8][0x00517ec0-0x00517f26.MerchantDialogPaneSendMenuRequestPacket](by-memory/0x00517ec0-0x00517f26.MerchantDialogPaneSendMenuRequestPacket.md) `MerchantDialogPane::SendMenuRequestPacket()`; it builds opcode `0x43`, subtype `1`, and inherited `m_menuObjectId`, sends length `6`, then closes. Command id `3` closes only. The vtable-family entry `0x0061f078 -> 0x00517d80` is separate inherited action-string glue, not the command id `2` route.

The private client row layout is `actionId` at `+0x000`, reserved byte at `+0x001`, `itemId` at `+0x002`, `itemStyle` at `+0x004`, reserved byte at `+0x005`, and `name[256]` at `+0x006`. `DLGMERC1.EPF` / `DLGMERC1.EPD` remain the supported current/legacy resource names; do not invent palette globals. Source-facing command ids are `1`, `2`, and `3`; raw button construction constants `0x0e`, `0x10`, and `0x0f` are not row command ids.

B006 resolves the inventory dependency as [UID:0003U9][0x005a3870-0x005a3889.UserPaneGetInventorySlotAddress](by-memory/0x005a3870-0x005a3889.UserPaneGetInventorySlotAddress.md). This class consumes `LocalInventorySlotRecord` entries from the local-player inventory table and reads their `active`, `itemId`, `iconStyle`, and `displayName` fields before appending a `ClientItemMenuEntry`; it does not own that table and should not rename server-menu `actionId` bytes as inventory slots. The accessor is a `UserPane::GetInventorySlotAddress` member owned by class UID0000FQ and emitted through file UID0000P1.

Dependencies that remain outside this class and source file include `Socket::QueueAndSendPacket`, `g_packetSender`, scalar packet readers/writers, `ObjectStatusBlob::ParseTaggedStatus`, `ListPane`, `ObjectImageControlPane`, `ImageButtonControlPane`, `StaticTextControlPane`, inherited `MerchantDialogPane::SendMenuRequestPacket`, and [UID:0003U9][0x005a3870-0x005a3889.UserPaneGetInventorySlotAddress](by-memory/0x005a3870-0x005a3889.UserPaneGetInventorySlotAddress.md) `UserPane::GetInventorySlotAddress` through class [UID:0000FQ][UserPane](by-class/UserPane.md) and file [UID:0000P1][UserPane](by-file/UserPane.md). The accepted source route is `NexusTK/ui/dialogs/ItemMenuDialogs.cpp`.

Historical / superseded dependency wording: the earlier `LivingObjectPaneGetInventorySlotAddress` name and LivingObjectPane ownership were retained from an adjusted-base/raw-offset interpretation. They lost current authority when UID0003U9's accepted formal source and the complete UID0000FQ/UID0000P1 declarations established a UserPane-owned accessor over `LocalInventorySlotRecord`; the item-menu class remains only a consumer.

The class page emits declaration-level C++ only. Full constructor, command, and update method bodies belong on [UID:00040E][0x0051b880-0x0051c46d.ClientItemMenuDialogMethods](by-memory/0x0051b880-0x0051c46d.ClientItemMenuDialogMethods.md), avoiding duplicate source between class and exact memory children.

## Ownership And Layout Evidence

| Evidence area | Source | Meaning |
| --- | --- | --- |
| source module | [UID:0000KF][ItemMenuDialogs](by-file/ItemMenuDialogs.md) | The narrow direct parent owns server/client item menu dialogs and their private row-list classes under `NexusTK/ui/dialogs/`; broader [UID:0000KE][ItemDialogs](by-file/ItemDialogs.md) is context, not the direct parent. |
| executable range | [UID:00040E][0x0051b880-0x0051c46d.ClientItemMenuDialogMethods](by-memory/0x0051b880-0x0051c46d.ClientItemMenuDialogMethods.md) | Confirms the client dialog constructor/command/state methods and the boundary immediately before `ClientItemMenuItemList`. |
| list companion | [UID:00002Q][ClientItemMenuItemList](by-class/ClientItemMenuItemList.md) and [UID:0001BQ][0x0051c470-0x0051ca3c.ClientItemMenuItemList](by-memory/0x0051c470-0x0051ca3c.ClientItemMenuItemList.md) | The dialog constructs the client row-list at two sites and should keep it in the same source module. |
| vtable family | [UID:0001Y5][MerchantMenuDialogVtableFamily](by-type/by-vtable/MerchantMenuDialogVtableFamily.md) | Places the class in the merchant/menu dialog vtable family with primary/secondary/tertiary `ClientItemMenuDialog` views. |

## Behavioral Evidence

- The constructor is reached from menu dialog factory helpers at `0x00517677` and `0x00517ae7`, matching client-side item action menu packet/factory flows.
- The constructor stores `ClientItemMenuDialog` vtable bases `0x0061f008`, `0x0061f068`, and `0x0061f098` at `0x0051b8e9`, `0x0051b8ef`, and `0x0051b8f9`.
- `OnControlCommand` and `UpdateActionButton` are vtable-referenced at `0x0061f050` and `0x0061f054`, respectively, tying the two virtual methods to the same client item-menu class view.
- The dialog constructs [UID:00002Q][ClientItemMenuItemList](by-class/ClientItemMenuItemList.md) at `0x0051ba35` and `0x0051bf64`; current IDA shows those are the only direct callers/xrefs to the `0x0051c470` list constructor.
- The client dialog range ends at `0x0051c46d`, followed by padding through `0x0051c470` and the separate client list constructor. This keeps the class boundary clean without splitting or merging the list class into this page.

## Evidence Notes

- Wave3 summary identifies this as the client-side context menu dialog for item actions; live IDA evidence, not Wave3 alone, drives the current score and routing.
- IDA MCP confirms all three method starts and current sizes `0xa8a`, `0x112`, and `0x3d`.
- This should stay near `ServerItemMenuDialog` because both implement item-action menu UI from different authority sources.
- IDA xrefs show this dialog constructs [UID:00002Q][ClientItemMenuItemList](by-class/ClientItemMenuItemList.md) at `0x0051ba35` and `0x0051bf64`; keep the list class in the same source module.
- 2026-06-07 A001 Batch081 live IDA recheck confirms the direct parent gate: child `ClientItemMenuDialog` is now `85/86`, and direct parent [UID:0000KF][ItemMenuDialogs](by-file/ItemMenuDialogs.md) is `86/85` after associated parent evidence was refreshed. Assignment to broader [UID:0000KE][ItemDialogs](by-file/ItemDialogs.md) is intentionally avoided because it is not the narrow direct item-menu owner.
- 2026-06-20 B002 Rule 26 split incorporation creates [UID:00040E][0x0051b880-0x0051c46d.ClientItemMenuDialogMethods](by-memory/0x0051b880-0x0051c46d.ClientItemMenuDialogMethods.md) as the exact source-bearing client dialog method page, keeps [UID:0001BO][0x0051a520-0x0051c46d.ItemMenuDialogs](by-memory/0x0051a520-0x0051c46d.ItemMenuDialogs.md) non-emitting, and routes private list behavior through [UID:0001BQ][0x0051c470-0x0051ca3c.ClientItemMenuItemList](by-memory/0x0051c470-0x0051ca3c.ClientItemMenuItemList.md).

## 2026-08-22 UID0000KF Accepted Declaration

The formal H channel supersedes the older `HandleMenuCommand`, `UpdateActionButtonState`, derived-`m_dialogId`, and CPP-local declaration forms. The exact `0x278` object inherits `m_menuDialogType +0x26c` and `m_menuObjectId +0x270` from MerchantDialogPane, then owns `m_packetSubtype +0x274` and three reserved bytes. UID00040E supplies the constructor `[0x0051b880,0x0051c30a)`, void command virtual `[0x0051c310,0x0051c422)`, and action-button update `[0x0051c430,0x0051c46d)`.

Factory routes `0x00517677` and `0x00517ae7` and vtable views `0x0061f008/0x0061f068/0x0061f098` bind the class. The constructor reads subtype and big-endian object id, parses `ObjectStatusBlob`, reads text and menu option, resolves local action bytes through UID0003U9, appends only active inventory slots, and preserves both exact `DLGMERC1.EPF`/`PA` and `DLGMERC1.EPD`/`NP` control layouts. `OnControlCommand(int,int)` at cell `0x0061f050` ignores nonzero notify codes; control `1` sends the selected nine-byte action packet and closes, `2` calls inherited six-byte request/close, and `3` closes. `UpdateActionButton()` at `0x0061f054` uses control `1` and list `6` selection count. Shared default/scalar deleting destructors remain compiler-generated through UID0001BW/UID0001C0.

Completion/confidence are `94/94`: layout, payload/inventory/UI behavior, factory/vtable route, exact three definitions, H ownership, and compiler exclusions are closed. Exact original private lexical spelling and compile/byte parity remain the score cap.

## Score Rationale

Completion/confidence are `94/94`. Exact method-child routing, factory subtype `5`, three vtable-bound definitions, client-list coupling, inherited/derived layout, payload and local-inventory flow, both resource/layout branches, command semantics, shared request ownership, dependency exclusions, formal H, and compiler-only destructor handling are complete. The remaining cap is inferred lexical style plus unproven compile/runtime/byte parity.

## Cross-References

- [UID:0000KF][ItemMenuDialogs](by-file/ItemMenuDialogs.md)
- [UID:0001Y5][MerchantMenuDialogVtableFamily](by-type/by-vtable/MerchantMenuDialogVtableFamily.md)
- [UID:0000KE][ItemDialogs](by-file/ItemDialogs.md)
- [UID:0001BO][0x0051a520-0x0051c46d.ItemMenuDialogs](by-memory/0x0051a520-0x0051c46d.ItemMenuDialogs.md)
- [UID:00040E][0x0051b880-0x0051c46d.ClientItemMenuDialogMethods](by-memory/0x0051b880-0x0051c46d.ClientItemMenuDialogMethods.md)
- [UID:00002Q][ClientItemMenuItemList](by-class/ClientItemMenuItemList.md)
- [UID:0000CZ][ServerItemMenuDialog](by-class/ServerItemMenuDialog.md)

## Changes

- 2026-08-21 B002 Gate 2A stage: corrected layout, constructor, selected-action, command-2, dependency, and generated-route ownership to the inherited MerchantDialogPane field and `SendMenuRequestPacket()`. Its then-current `m_dialogId` spelling and the earlier TextMenu attribution are superseded by the 2026-08-22 accepted `m_menuObjectId` correction above; list-owned identifiers remain unchanged.
- 2026-06-21 Rule 26 support sync from B006 [UID:0003U9][0x005a3870-0x005a3889.UserPaneGetInventorySlotAddress](by-memory/0x005a3870-0x005a3889.UserPaneGetInventorySlotAddress.md):
  - Added the local inventory slot record dependency for row population while preserving action-id semantics for server/client packet rows.
- What existed before: the page documented client item-menu behavior, methods, source placement, and list-class construction evidence, but metadata was still `0/0`.
- What it was changed to: scores were set to `76/84`.
- Summary and evidence: constructor, command handling, action-button state, item-menu placement, and related list class are covered; detailed menu action table and final field/layout names remain incomplete.
- 2026-06-05: Marked reconstructable for autogen.
  - Before: `RECONSTRUCTABLE` was blank, leaving the class coverage row unclassified.
  - After: `RECONSTRUCTABLE:TRUE`; `AUTOGEN_PARENT_UID` remains blank because the class completion score is below the 80% attachment gate.
  - Evidence: live IDA MCP confirms modeled method starts at `0x0051b880`, `0x0051c310`, and `0x0051c430`, with dispatcher callers into the constructor from `0x00517677` and `0x00517ae7`; existing project docs place the class in [UID:0000KF][ItemMenuDialogs](by-file/ItemMenuDialogs.md).
- 2026-06-07 A001 Batch081 strict parent-gate update:
  - What existed before: `76/84`, reconstructable, but unassigned with only compact client-menu evidence and a below-gate direct parent.
  - Changed to: `85/86` and `AUTOGEN_PARENT_UID:0000KF` after refreshing [UID:0000KF][ItemMenuDialogs](by-file/ItemMenuDialogs.md) from `86/80` to `86/85`.
  - Summary/evidence: added exact half-open method ranges, factory callers, vtable stores, virtual-row refs, exclusive `ClientItemMenuItemList` constructor coupling, and the clean boundary before `0x0051c470`. Final C++ remains blank until action tables, packet fields, and layout fields are source-quality.
- 2026-06-20 B002 Rule 26 split incorporation: raised to `88/89`, linked exact method child [UID:00040E][0x0051b880-0x0051c46d.ClientItemMenuDialogMethods](by-memory/0x0051b880-0x0051c46d.ClientItemMenuDialogMethods.md), and documented client opcode `0x39` action payload semantics, `DLGMERC1.EPF` / `DLGMERC1.EPD` resource handling, command-id versus button-constant separation, and corrected [UID:0001BQ][0x0051c470-0x0051ca3c.ClientItemMenuItemList](by-memory/0x0051c470-0x0051ca3c.ClientItemMenuItemList.md) row layout before first-draft C++ emission.
- 2026-06-21 B013 Rule 26 source-quality incorporation: score unchanged at `88/89`. Added declaration-level class C++, source-facing fields `m_menuObjectId`/`m_packetSubtype`, payload parsing, current/legacy layout branches, dependency exclusions, and command id semantics. Corrected command id `2` to `TextMenuDialog::SendMenuRequestPacket` at `0x00517ec0`, rejected `0x00517d80` as the command route, and narrowed the selected client action packet to the documented length-`9` opcode `0x39` payload.

## Historical B002 UID0000OP Shared-Base Reconciliation

The complete class declaration has moved from formal CPP to H. Exact size is 0x278; inherited `m_menuObjectId` occupies +0x270, only `m_packetSubtype` plus padding remain derived at +0x274, and no duplicate dialog-owned identifier storage remains.

All five factory wrappers allocate exactly `0x278`; live constructors place the packet dword at `this+0x270` and the family byte at `this+0x274`. This proves one inherited dword plus one derived byte and three bytes of tail padding without moving any list-owned identifier, allocation, vtable, packet field, or runtime branch. The existing family score is intentionally unchanged; only the accepted shared-base ownership/formal-source defect is corrected.
