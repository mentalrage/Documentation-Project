*** UID:0000CZ | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:82 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000KF | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# ServerItemMenuDialog

## Status

- Confidence: strong for behavior, item-menu placement, live method boundaries, factory callers, vtable identity, row-list construction, selected-action packet dispatch, and parent placement.
- Likely source file: [UID:0000KF][ItemMenuDialogs](by-file/ItemMenuDialogs.md), under the broader [UID:0000KE][ItemDialogs](by-file/ItemDialogs.md) family
- Address range: [UID:0001BO][0x0051a520-0x0051c46d.ItemMenuDialogs](by-memory/0x0051a520-0x0051c46d.ItemMenuDialogs.md)
- Parent attachment: [UID:0000KF][ItemMenuDialogs](by-file/ItemMenuDialogs.md) is `86/80` with valid `NexusTK/ui/dialogs/` placement and already owns the server/client item-menu dialog family.

## Class Purpose

`ServerItemMenuDialog` displays item actions supplied by server packet data. It initializes a context menu from packet/action data, dispatches the selected menu action, and updates action availability.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| `InitializeFromPacket` | `0x0051a520-0x0051ac8e` | Builds the server-provided item action menu from packet/object data, installs the dialog vtables, inline-constructs the private item list, appends parsed rows, and creates the surrounding controls. |
| `OnDialogAction` | `0x0051acb0-0x0051ae42` | Dispatches the selected server menu row by building opcode `0x39` from the selected row text and row context fields. |
| `UpdateActionAvailability` | `0x0051ae50-0x0051ae8d` | Checks the list/object state and toggles the action button through control virtual slots. |

## Evidence Notes

- 2026-06-04 live IDA MCP confirms modeled functions at `0x0051a520-0x0051ac8e`, `0x0051acb0-0x0051ae42`, and `0x0051ae50-0x0051ae8d`; the adjacent `0x0051ae90` list constructor start is still raw/unmodeled, and the next modeled dialog constructor starts at `0x0051b880`.
- Constructor xrefs to `0x0051a520` come from the shared menu factory path at `0x0051762b` and the adjusted server-item wrapper at `0x00517a5d`.
- The constructor installs the three `ServerItemMenuDialog` vtables at `0x0051a596 -> 0x0061eea8`, `0x0051a59c -> 0x0061ef08`, and `0x0051a5a6 -> 0x0061ef38`.
- Vtable data refs tie `0x0051acb0` to slot `0x0061eef0` and `0x0051ae50` to slot `0x0061eef4`, confirming those are the dialog's action and availability/update virtuals.
- The constructor parses packet object/status data at `0x0051a5ea -> 0x004d1f30` from `packet + 6`, converts packet strings with `MultiByteToWideChar`, creates the `DLGMERC3.EPF` UI, and appends parsed row strings into the private list.
- The dialog inline-constructs [UID:0000D0][ServerItemMenuItemList](by-class/ServerItemMenuItemList.md): `0x0051a69c` allocates the list object, `0x0051a6da` calls the `ListPane` constructor, `0x0051a6ff/0x0051a705/0x0051a70f` install list vtables `0x0061ef44/0x0061efcc/0x0061effc`, and `0x0051a720` stores the owning dialog pointer at list offset `0x158`.
- `0x0051acb0` fetches control/list slot `6` through the dialog child registry at `this + 0x1fc`, uses the selected index at list offset `0x134`, fetches the row with `0x004f3dc0`, writes opcode `0x39`, serializes list context fields `0x14c/0x150/0x154`, converts the selected wide text with `WideCharToMultiByte`, and sends through `dword_67A7EC` and `0x00574bb0`.
- `0x0051ae50` fetches controls `1` and `6` through `this + 0x1fc`, checks item/list state with `0x004f3e20`, and dispatches to control vtable slots `+0x4c` or `+0x50` depending on whether an action is available.
- Remaining uncertainty is mostly naming/layout polish: helper names are still generic and the private row-list constructor has a raw unmodeled sibling range. Final reconstruction C++ stays blank.

## Cross-References

- [UID:0000KF][ItemMenuDialogs](by-file/ItemMenuDialogs.md)
- [UID:0001Y5][MerchantMenuDialogVtableFamily](by-type/by-vtable/MerchantMenuDialogVtableFamily.md)
- [UID:0000KE][ItemDialogs](by-file/ItemDialogs.md)
- [UID:0001BO][0x0051a520-0x0051c46d.ItemMenuDialogs](by-memory/0x0051a520-0x0051c46d.ItemMenuDialogs.md)
- [UID:0000D0][ServerItemMenuItemList](by-class/ServerItemMenuItemList.md)
- [UID:00002P][ClientItemMenuDialog](by-class/ClientItemMenuDialog.md)

## Changes

- Before: completion/confidence were unevaluated at `0/0`.
- Changed to: completion `78`, confidence `76`.
- Evidence: the page documents behavior, likely file ownership, by-memory grouping, three confirmed method starts, and generated-name caveat; confidence remains capped by suspect generated method naming.
- 2026-06-04: raised from `78/76` to `82/84`, marked `RECONSTRUCTABLE:TRUE`, and attached to [UID:0000KF][ItemMenuDialogs](by-file/ItemMenuDialogs.md).
  - Summary/evidence: live IDA MCP confirms function boundaries, factory callers, dialog vtable installs, action/update vtable slots, packet/object parsing, `DLGMERC3.EPF` UI construction, inline `ServerItemMenuItemList` construction, selected-row opcode `0x39` packet serialization, packet sender, and availability-toggle control flow.
  - Remaining gaps: final C++ remains blank because helper names, exact source-level field names, and the raw neighboring list constructor are not yet at the 95/95 reconstruction threshold.
