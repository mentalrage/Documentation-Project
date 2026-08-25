*** UID:0000CZ | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000KF | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000KF | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL:5 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
#include "ItemMenuDialogs.h"
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
#pragma once

#include "MerchantDialogPane.h"
#include "../controls/ListPane.h"

class MouseEvent;

class ServerItemMenuDialog : public MerchantDialogPane
{
public:
    ServerItemMenuDialog(const RectBounds& bounds,
                         const unsigned char *payload,
                         unsigned char menuMode);
    virtual ~ServerItemMenuDialog() {}

    void OnControlCommand(int controlId, int notifyCode) override;
    void UpdateActionButton() override;

private:
    unsigned char m_packetSubtype;
    unsigned char m_reserved[3];
};
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# ServerItemMenuDialog

## Status

- Confidence: strong for behavior, item-menu placement, live method boundaries, factory callers, vtable identity, row-list construction, selected-action packet dispatch, and parent placement.
- Likely source file: [UID:0000KF][ItemMenuDialogs](by-file/ItemMenuDialogs.md), under the broader [UID:0000KE][ItemDialogs](by-file/ItemDialogs.md) family
- Address range: exact method child [UID:00040D][0x0051a520-0x0051ae8d.ServerItemMenuDialogMethods](by-memory/0x0051a520-0x0051ae8d.ServerItemMenuDialogMethods.md), indexed by [UID:0001BO][0x0051a520-0x0051c46d.ItemMenuDialogs](by-memory/0x0051a520-0x0051c46d.ItemMenuDialogs.md)
- Parent attachment: [UID:0000KF][ItemMenuDialogs](by-file/ItemMenuDialogs.md) is the direct `NexusTK/ui/dialogs/` owner for server/client item-menu dialogs and their private row-list classes.

## Class Purpose

`ServerItemMenuDialog` displays item actions supplied by server packet data. It initializes a context menu from packet/action data, dispatches the selected menu action, and updates action availability.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| `ServerItemMenuDialog` | `0x0051a520-0x0051ac8e` | Constructs the server-provided item action menu from packet/object data, installs the dialog vtables, inline-constructs the private item list, appends parsed rows, and creates the surrounding controls. |
| `OnControlCommand` | `0x0051acb0-0x0051ae42` | Dispatches the selected server menu row by building opcode `0x39` from the selected row text and row context fields. |
| `UpdateActionButton` | `0x0051ae50-0x0051ae8d` | Checks the list/object state and toggles the action button through control virtual slots. |

Factory construction reaches this class as `ServerItemMenuDialog(const RectBounds& bounds, const unsigned char *payload, unsigned char menuMode)` from [UID:000238][0x00517450-0x00517d23.MenuDialogFactoryHelpers](by-memory/0x00517450-0x00517d23.MenuDialogFactoryHelpers.md) subtype `4` / `kServerItemMenu`. The bounds are formed inline by `InitDlgMerc1Bounds(&bounds)`, `bounds.right = bounds.left + 425`, and `bounds.bottom = bounds.top + 354`, producing `(100,100,525,454)`; no `InitServerItemMenuBounds` helper exists. The exact method child presents `[0x0051a520,0x0051ac8e)` as this constructor body/parser portion, not a separate post-construction call from the factory.

## Rule 26 Source-Quality Notes

B002's 2026-06-19/20 aggregate report is now incorporated through the exact source-bearing child [UID:00040D][0x0051a520-0x0051ae8d.ServerItemMenuDialogMethods](by-memory/0x0051a520-0x0051ae8d.ServerItemMenuDialogMethods.md). The broader [UID:0001BO][0x0051a520-0x0051c46d.ItemMenuDialogs](by-memory/0x0051a520-0x0051c46d.ItemMenuDialogs.md) page is a non-emitting split index; this class owns only the server dialog methods before the `0x0051ae8d-0x0051ae90` padding and the [UID:0001BP][0x0051ae90-0x0051b87a.ServerItemMenuItemList](by-memory/0x0051ae90-0x0051b87a.ServerItemMenuItemList.md) server row-list child.

Source-facing command ids are `1`, `2`, and `3`: action `1` submits the selected UID0001BP row name through opcode `0x39`, action `2` calls inherited `MerchantDialogPane::SendMenuRequestPacket()` at `0x00517ec0` using inherited `m_menuObjectId`, and action `3` closes the dialog. This request method is distinct from action-string virtual `0x00517d80`. Raw button construction constants `0x0e`, `0x10`, and `0x0f` are skin/control construction constants, not row command ids. The private server list uses the corrected `ServerItemMenuEntry` layout with `itemId` at `+0x000`, `itemStyle` at `+0x002`, reserved byte at `+0x003`, `value` at `+0x004`, `name[256]` at `+0x008`, and `description[256]` at `+0x208`; there is no server row `actionId`.

## Evidence Notes

- 2026-06-04 live IDA MCP confirms modeled functions at `0x0051a520-0x0051ac8e`, `0x0051acb0-0x0051ae42`, and `0x0051ae50-0x0051ae8d`; the adjacent `0x0051ae90` list constructor start is still raw/unmodeled, and the next modeled dialog constructor starts at `0x0051b880`.
- Constructor xrefs to `0x0051a520` come from the shared menu factory path at `0x0051762b` and the adjusted server-item wrapper at `0x00517a5d`.
- The constructor installs the three `ServerItemMenuDialog` vtables at `0x0051a596 -> 0x0061eea8`, `0x0051a59c -> 0x0061ef08`, and `0x0051a5a6 -> 0x0061ef38`.
- Vtable data refs tie `0x0051acb0` to slot `0x0061eef0` and `0x0051ae50` to slot `0x0061eef4`, confirming those are the dialog's action and availability/update virtuals.
- The constructor parses packet object/status data at `0x0051a5ea -> 0x004d1f30` from `packet + 6`, converts packet strings with `MultiByteToWideChar`, creates the `DLGMERC3.EPF` UI, and appends parsed row strings into the private list.
- The dialog inline-constructs [UID:0000D0][ServerItemMenuItemList](by-class/ServerItemMenuItemList.md): `0x0051a69c` allocates the list object, `0x0051a6da` calls the `ListPane` constructor, `0x0051a6ff/0x0051a705/0x0051a70f` install list vtables `0x0061ef44/0x0061efcc/0x0061effc`, and `0x0051a720` stores the owning dialog pointer at list offset `0x158`.
- `0x0051acb0` fetches control/list slot `6` through the dialog child registry at `this + 0x1fc`, uses the selected index at list offset `0x134`, fetches the row with `0x004f3dc0`, writes opcode `0x39`, serializes list context fields `0x14c/0x150/0x154`, converts the selected wide text with `WideCharToMultiByte`, and sends through `dword_67A7EC` and `0x00574bb0`.
- `0x0051ae50` fetches controls `1` and `6` through `this + 0x1fc`, checks item/list state with `0x004f3e20`, and dispatches to control vtable slots `+0x4c` or `+0x50` depending on whether an action is available.
- 2026-06-14 live IDA MCP session `a001_goal2_class_batch` reconfirmed modeled starts at `0x0051a520`, `0x0051acb0`, and `0x0051ae50`, while the adjacent row-list constructor at `0x0051ae90` remains a raw no-function start owned by [UID:0000D0][ServerItemMenuItemList](by-class/ServerItemMenuItemList.md).
- The same live xref pass reconfirmed constructor callers at `0x0051762b` and `0x00517a5d`, vtable installs to `0x0061eea8`, `0x0061ef08`, and `0x0061ef38`, and vtable slots `0x0061eef0 -> 0x0051acb0` and `0x0061eef4 -> 0x0051ae50`.
- Live decompilation of `0x0051acb0` confirms selected-action command handling: action id `1` builds opcode `0x39`, serializes row context bytes/words/dwords, converts selected wide text through `WideCharToMultiByte`, sends through `dword_67A7EC`/`0x00574bb0`, action id `2` forwards to `0x00517ec0`, and action id `3` closes/returns through `0x0049dad0`.
- Remaining uncertainty is mostly exact original spelling for constructor/helper parameter names. First-draft C++ lives in [UID:00040D][0x0051a520-0x0051ae8d.ServerItemMenuDialogMethods](by-memory/0x0051a520-0x0051ae8d.ServerItemMenuDialogMethods.md), while [UID:0001BP][0x0051ae90-0x0051b87a.ServerItemMenuItemList](by-memory/0x0051ae90-0x0051b87a.ServerItemMenuItemList.md) carries the private row-list C++ and corrected row layout.

## 2026-08-22 UID0000KF Accepted Declaration

The formal H channel above supersedes the older `OnDialogAction` / `UpdateActionAvailability` draft and the historical inherited-`m_dialogId` wording. The source-facing class is a `0x278` `MerchantDialogPane` derivative: the base owns `m_menuDialogType` at `+0x26c` and `m_menuObjectId` at `+0x270`; this class owns `m_packetSubtype` at `+0x274` and three reserved bytes through `+0x277`. UID00040D owns the three authored definitions at `[0x0051a520,0x0051ac8e)`, `[0x0051acb0,0x0051ae42)`, and `[0x0051ae50,0x0051ae8d)`; this class page supplies the ItemMenuDialogs CPP include preamble and H declaration only. The one metadata position `5` on UID0000CZ governs both formal channels: it places the CPP include preamble first and the `ServerItemMenuDialog` H declaration first, followed by H owners UID0000D0/UID00002P/UID00002Q at positions `20/30/40`. There is no separate or invented H position `10`; that earlier two-position interpretation is historical and superseded because the validator applies one `EMITTER_POSITION_OPTIONAL` value to every nonblank channel on the page.

The constructor's two factory routes are `0x0051762b` and `0x00517a5d`. It installs primary/secondary/tertiary views `0x0061eea8`, `0x0061ef08`, and `0x0061ef38`, parses packet/object/text/list state, and builds the exact `DLGMERC3.EPF` controls. `OnControlCommand(int,int)` is the void virtual at cell `0x0061eef0`: notify codes other than zero return; control `1` sends the selected server row name and closes, `2` calls the inherited six-byte request, and `3` closes. `UpdateActionButton()` is cell `0x0061eef4` and enables control `1` exactly when list control `6` has a nonzero selection count. Default/scalar deleting destructor entries are compiler output through UID0001BW/UID0001C0, not handwritten methods.

Completion/confidence are `94/94`: constructor identity, fields, complete declaration, factory/vtable routes, UI/parser behavior, source child, and compiler exclusions are closed. Exact original private lexical spellings and compile/byte parity remain below final certainty.

## Score Rationale

Historical pre-callback rationale (superseded by the `94/94` accepted declaration above): completion was raised to `88` because the page recorded current live function boundaries, factory callers, three-view vtable installs, virtual slot xrefs, packet/object parsing, inline server-list construction, selected-action packet behavior, availability update behavior, direct source-file routing, the exact source-bearing child page, and the corrected private row-list layout/packet semantics. Confidence was raised to `89` because the method identities and item-menu ownership were live-IDA verified; remaining lexical uncertainty is now carried in the current `94/94` rationale above.

## Cross-References

- [UID:0000KF][ItemMenuDialogs](by-file/ItemMenuDialogs.md)
- [UID:0001Y5][MerchantMenuDialogVtableFamily](by-type/by-vtable/MerchantMenuDialogVtableFamily.md)
- [UID:0000KE][ItemDialogs](by-file/ItemDialogs.md)
- [UID:0001BO][0x0051a520-0x0051c46d.ItemMenuDialogs](by-memory/0x0051a520-0x0051c46d.ItemMenuDialogs.md)
- [UID:00040D][0x0051a520-0x0051ae8d.ServerItemMenuDialogMethods](by-memory/0x0051a520-0x0051ae8d.ServerItemMenuDialogMethods.md)
- [UID:0000D0][ServerItemMenuItemList](by-class/ServerItemMenuItemList.md)
- [UID:00002P][ClientItemMenuDialog](by-class/ClientItemMenuDialog.md)

## Changes

- 2026-08-21 B002 Gate 2A stage: routed command 2 to inherited `MerchantDialogPane::SendMenuRequestPacket()` and excluded the separate `0x00517d80` virtual; its then-current `m_dialogId` spelling is superseded by the 2026-08-22 accepted `m_menuObjectId` correction above.
- Before: completion/confidence were unevaluated at `0/0`.
- Changed to: completion `78`, confidence `76`.
- Evidence: the page documents behavior, likely file ownership, by-memory grouping, three confirmed method starts, and generated-name caveat; confidence remains capped by suspect generated method naming.
- 2026-06-04: raised from `78/76` to `82/84`, marked `RECONSTRUCTABLE:TRUE`, and attached to [UID:0000KF][ItemMenuDialogs](by-file/ItemMenuDialogs.md).
  - Summary/evidence: live IDA MCP confirms function boundaries, factory callers, dialog vtable installs, action/update vtable slots, packet/object parsing, `DLGMERC3.EPF` UI construction, inline `ServerItemMenuItemList` construction, selected-row opcode `0x39` packet serialization, packet sender, and availability-toggle control flow.
  - Remaining gaps: final C++ remains blank because helper names, exact source-level field names, and the raw neighboring list constructor are not yet at the 95/95 reconstruction threshold.
- 2026-06-14 A002 Goal 2 live class refresh:
  - Before: `82/84`.
  - After: `85/87`; owner and emitter remain [UID:0000KF][ItemMenuDialogs](by-file/ItemMenuDialogs.md).
  - Evidence: live IDA MCP session `a001_goal2_class_batch` reconfirmed all three method starts, the raw `ServerItemMenuItemList` successor start, two constructor callers, the three vtable install sites, action/update virtual slots, and the selected-action opcode `0x39` packet send path.
- 2026-06-20 B002 Rule 26 split incorporation: raised to `88/89`, linked exact method child [UID:00040D][0x0051a520-0x0051ae8d.ServerItemMenuDialogMethods](by-memory/0x0051a520-0x0051ae8d.ServerItemMenuDialogMethods.md), and recorded that [UID:0001BO][0x0051a520-0x0051c46d.ItemMenuDialogs](by-memory/0x0051a520-0x0051c46d.ItemMenuDialogs.md) is a non-emitting split index. The class page now carries the accepted server action semantics, command-id versus button-constant distinction, and corrected [UID:0001BP][0x0051ae90-0x0051b87a.ServerItemMenuItemList](by-memory/0x0051ae90-0x0051b87a.ServerItemMenuItemList.md) row-layout dependency before first-draft C++ emission.
- 2026-06-28 B010 [UID:000238][0x00517450-0x00517d23.MenuDialogFactoryHelpers](by-memory/0x00517450-0x00517d23.MenuDialogFactoryHelpers.md) support sync: score unchanged. Added the `ServerItemMenuDialog(const RectBounds& bounds, const unsigned char *payload, unsigned char menuMode)` factory constructor shape and preserved the exact method child as the constructor parser/setup portion.

## Historical B002 UID0000OP Shared-Base Reconciliation

Exact 0x278 declaration: inherited MerchantDialogPane `m_menuObjectId` at +0x270, derived `m_packetSubtype` at +0x274, three-byte padding, and no duplicate id storage. Constructor body is exact child UID00040D; command 2 calls inherited `SendMenuRequestPacket()`.

All five factory wrappers allocate exactly `0x278`; live constructors place the packet dword at `this+0x270` and the family byte at `this+0x274`. This proves one inherited dword plus one derived byte and three bytes of tail padding without moving any list-owned identifier, allocation, vtable, packet field, or runtime branch. The existing family score is intentionally unchanged; only the accepted shared-base ownership/formal-source defect is corrected.
