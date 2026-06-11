*** UID:00002Q | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:82 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000KF | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# ClientItemMenuItemList

## Status

- Confidence: strong for item-menu list behavior; medium for shared destructor ownership.
- Likely source file: [UID:0000KF][ItemMenuDialogs](by-file/ItemMenuDialogs.md)
- Main address range: [UID:0001BQ][0x0051c470-0x0051ca3c.ClientItemMenuItemList](by-memory/0x0051c470-0x0051ca3c.ClientItemMenuItemList.md)
- Vtable family: [UID:0001Y5][MerchantMenuDialogVtableFamily](by-type/by-vtable/MerchantMenuDialogVtableFamily.md)
- Autogen parent: [UID:0000KF][ItemMenuDialogs](by-file/ItemMenuDialogs.md). This class now satisfies the parent-attachment gate; final C++ stays blank because raw helper starts and row/packet field names are not final-source quality.

## Class Purpose

`ClientItemMenuItemList` is the row-list widget for client-side item action menus. It stores packet/item context from the owning dialog, appends locally available inventory item rows, forwards activation into the shared item-action context, and draws icon/name rows.

## Ownership And Behavior

This list is a private row-list companion for [UID:00002P][ClientItemMenuDialog](by-class/ClientItemMenuDialog.md), under the item-menu dialog source family. The constructor has two documented caller refs from the client item-menu dialog, and the memory cluster is already attached to [UID:0000KF][ItemMenuDialogs](by-file/ItemMenuDialogs.md). The vtable family places the primary/secondary/tertiary `ClientItemMenuItemList` tables beside the server item and spell menu list companions.

| Area | Evidence | Notes |
| --- | --- | --- |
| Construction/context | `0x0051c470-0x0051c4dc` | Builds the `ListPane` base, stores packet/menu context at `+0x14c/+0x150/+0x154/+0x158`, and installs three vtable views. |
| Row building | `0x0051c4e0-0x0051c548` | Raw helper-shaped code appends local client item rows; remains below final-source quality because IDA does not model it as a function start. |
| Packet helpers | `0x0051c550-0x0051c603`, `0x0051c610-0x0051c6ac` | Build opcode `0x39` payloads from the selected row or a caller-supplied action byte, using the constructor-saved context fields. |
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
| `DrawMenuItemEntry` | `0x0051c6c0-0x0051ca3c` | Draws selected/unselected item rows with icon and ellipsis-truncated item name in high-resolution and legacy layouts. |
| shared destructor glue | `0x00520ad1`, `0x00520adc`, `0x00520c20` | Secondary/tertiary adjustor thunks and shared scalar deleting destructor also referenced by spell menu item list vtables. |

## Evidence Notes

- IDA MCP confirms `0x0051c470`, `0x0051c6b0`, and `0x0051c6c0` as functions.
- IDA disassembly confirms raw helper-shaped code at `0x0051c4e0`, `0x0051c550`, and `0x0051c610`, though those addresses are not currently function starts.
- IDA xrefs show `ClientItemMenuDialog` constructs this list from `0x0051ba35` and `0x0051bf64`.
- IDA xrefs show destructor thunks `0x00520ad1` and `0x00520adc`, and scalar deleting destructor `0x00520c20`, are shared by `ClientItemMenuItemList`, `ServerSpellMenuItemList`, and `ClientSpellMenuItemList` vtables.
- Existing generated-owner notes treat `0x004f3b60` as `ClientItemMenuItemList::~ClientItemMenuItemList`, but IDA caller fanout shows it is broad `ListPane` cleanup, not a private client item-menu method.

## Score Rationale

| Field | Value | Rationale |
| --- | ---: | --- |
| Completion | 82 | The page now records purpose, file parent, constructor callers, context fields, raw row/packet helpers, activation and draw behavior, vtable-family evidence, shared destructor caveat, parent attachment, and no-code rationale. |
| Confidence | 84 | Existing IDA-backed memory/type docs strongly support the owner and range. Confidence remains below final-audit level because three helper starts are raw/non-modeled and final row-record, packet-helper, and field names remain provisional. |

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

- What existed before: the page documented item-menu row-list behavior, raw helper-shaped packet functions, draw path, and shared destructor caveat, but metadata was still `0/0`.
- What it was changed to: scores were set to `76/82`.
- Summary and evidence: constructor, append/helper ranges, selected/explicit packet helpers, activation, draw, constructor xrefs, and shared destructor ownership are covered; complete row struct names and final helper ownership remain open.
- 2026-06-05: Marked reconstructable for autogen.
  - Before: `RECONSTRUCTABLE` was blank, leaving the class coverage row unclassified.
  - After: `RECONSTRUCTABLE:TRUE`; `AUTOGEN_PARENT_UID` remains blank because the class completion score is below the 80% attachment gate.
  - Evidence: live IDA MCP confirms modeled method starts at `0x0051c470`, `0x0051c6b0`, and `0x0051c6c0`; constructor callers at `0x0051ba35` and `0x0051bf64` come from `ClientItemMenuDialog`.
- 2026-06-07 A001 parent attachment refresh:
  - Changed to: `COMPLETION:82`, `CONFIDENCE:84`, and `AUTOGEN_PARENT_UID:0000KF`.
  - Summary/evidence: the class now mirrors the stronger [UID:0001BQ][0x0051c470-0x0051ca3c.ClientItemMenuItemList](by-memory/0x0051c470-0x0051ca3c.ClientItemMenuItemList.md) parent-gate evidence: exact range, client dialog constructor refs, constructor context fields, raw row/packet helpers, activation/draw virtuals, vtable-family anchors, and shared destructor glue caveat. Final C++ remains blank because raw helper modeling and row/packet field names are not final-source quality.
