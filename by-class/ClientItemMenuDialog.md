*** UID:00002P | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:85 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000KF | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# ClientItemMenuDialog

## Status

- Confidence: strong for behavior and item-menu placement.
- Likely source file: [UID:0000KF][ItemMenuDialogs](by-file/ItemMenuDialogs.md), under the broader [UID:0000KE][ItemDialogs](by-file/ItemDialogs.md) family
- Address range: [UID:0001BO][0x0051a520-0x0051c46d.ItemMenuDialogs](by-memory/0x0051a520-0x0051c46d.ItemMenuDialogs.md)
- Current recovered file: `source-3/simroot_v2/class_ClientItemMenuDialog.cpp`
- Autogen status: attached to direct file parent [UID:0000KF][ItemMenuDialogs](by-file/ItemMenuDialogs.md), now `86/85` after the A001 Batch081 parent-gate refresh; final C++ remains blank pending source-quality action tables, packet field names, and layout field names.

## Class Purpose

`ClientItemMenuDialog` is the client-side item context menu. It builds local menu actions for an item, dispatches selected commands, and keeps the action state synchronized with selection and mode flags.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| `ClientItemMenuDialog` | `0x0051b880-0x0051c30a` | Builds the client-side item action menu from anchor rectangle, packet/item data, and mode flag, then wires the client item-list rows into the dialog. |
| `HandleMenuCommand` | `0x0051c310-0x0051c422` | Dispatches selected menu action through the local item-action path and packet/send helpers. |
| `UpdateActionButtonState` | `0x0051c430-0x0051c46d` | Enables/disables local item menu actions and ends before the `0x0051c470` client list constructor. |

## Ownership And Layout Evidence

| Evidence area | Source | Meaning |
| --- | --- | --- |
| source module | [UID:0000KF][ItemMenuDialogs](by-file/ItemMenuDialogs.md) | The narrow direct parent owns server/client item menu dialogs and their private row-list classes under `NexusTK/ui/dialogs/`; broader [UID:0000KE][ItemDialogs](by-file/ItemDialogs.md) is context, not the direct parent. |
| executable range | [UID:0001BO][0x0051a520-0x0051c46d.ItemMenuDialogs](by-memory/0x0051a520-0x0051c46d.ItemMenuDialogs.md) | Confirms the client dialog constructor/command/state methods and the boundary immediately before `ClientItemMenuItemList`. |
| list companion | [UID:00002Q][ClientItemMenuItemList](by-class/ClientItemMenuItemList.md) and [UID:0001BQ][0x0051c470-0x0051ca3c.ClientItemMenuItemList](by-memory/0x0051c470-0x0051ca3c.ClientItemMenuItemList.md) | The dialog constructs the client row-list at two sites and should keep it in the same source module. |
| vtable family | [UID:0001Y5][MerchantMenuDialogVtableFamily](by-type/by-vtable/MerchantMenuDialogVtableFamily.md) | Places the class in the merchant/menu dialog vtable family with primary/secondary/tertiary `ClientItemMenuDialog` views. |

## Behavioral Evidence

- The constructor is reached from menu dialog factory helpers at `0x00517677` and `0x00517ae7`, matching client-side item action menu packet/factory flows.
- The constructor stores `ClientItemMenuDialog` vtable bases `0x0061f008`, `0x0061f068`, and `0x0061f098` at `0x0051b8e9`, `0x0051b8ef`, and `0x0051b8f9`.
- `HandleMenuCommand` and `UpdateActionButtonState` are vtable-referenced at `0x0061f050` and `0x0061f054`, respectively, tying the two virtual methods to the same client item-menu class view.
- The dialog constructs [UID:00002Q][ClientItemMenuItemList](by-class/ClientItemMenuItemList.md) at `0x0051ba35` and `0x0051bf64`; current IDA shows those are the only direct callers/xrefs to the `0x0051c470` list constructor.
- The client dialog range ends at `0x0051c46d`, followed by padding through `0x0051c470` and the separate client list constructor. This keeps the class boundary clean without splitting or merging the list class into this page.

## Evidence Notes

- Wave3 summary identifies this as the client-side context menu dialog for item actions; live IDA evidence, not Wave3 alone, drives the current score and routing.
- IDA MCP confirms all three method starts and current sizes `0xa8a`, `0x112`, and `0x3d`.
- This should stay near `ServerItemMenuDialog` because both implement item-action menu UI from different authority sources.
- IDA xrefs show this dialog constructs [UID:00002Q][ClientItemMenuItemList](by-class/ClientItemMenuItemList.md) at `0x0051ba35` and `0x0051bf64`; keep the list class in the same source module.
- 2026-06-07 A001 Batch081 live IDA recheck confirms the direct parent gate: child `ClientItemMenuDialog` is now `85/86`, and direct parent [UID:0000KF][ItemMenuDialogs](by-file/ItemMenuDialogs.md) is `86/85` after associated parent evidence was refreshed. Assignment to broader [UID:0000KE][ItemDialogs](by-file/ItemDialogs.md) is intentionally avoided because it is not the narrow direct item-menu owner.

## Cross-References

- [UID:0000KF][ItemMenuDialogs](by-file/ItemMenuDialogs.md)
- [UID:0001Y5][MerchantMenuDialogVtableFamily](by-type/by-vtable/MerchantMenuDialogVtableFamily.md)
- [UID:0000KE][ItemDialogs](by-file/ItemDialogs.md)
- [UID:0001BO][0x0051a520-0x0051c46d.ItemMenuDialogs](by-memory/0x0051a520-0x0051c46d.ItemMenuDialogs.md)
- [UID:00002Q][ClientItemMenuItemList](by-class/ClientItemMenuItemList.md)
- [UID:0000CZ][ServerItemMenuDialog](by-class/ServerItemMenuDialog.md)

## Changes

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
