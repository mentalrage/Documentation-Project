*** UID:0000KF | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:80 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"NexusTK/ui/dialogs/" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***

# ItemMenuDialogs

## Status

- Confidence: strong for server/client item menu grouping; medium for whether this was a standalone `.cpp` or folded into `ItemDialogs.cpp`.
- Proposed source file: `ui/dialogs/ItemMenuDialogs.cpp`
- Alternative compact legacy placement: `ui/dialogs/ItemDialogs.cpp`
- Current generated sources: `class_ServerItemMenuDialog.cpp`, `class_ServerItemMenuItemList.cpp`, `class_ClientItemMenuDialog.cpp`, and `class_ClientItemMenuItemList.cpp`
- Evidence basis: `source-3/simroot_v2` generated files plus IDA MCP checks on 2026-05-24 and 2026-05-26.
- Vtable/layout anchor: [UID:0001Y5][MerchantMenuDialogVtableFamily](by-type/by-vtable/MerchantMenuDialogVtableFamily.md)

## Hypothesis

The original source likely kept the server and client item context-menu dialogs together with their private list-pane row classes. The dialogs own the packet parsing, object preview, buttons, description text, and scrollable list container. The item-list classes own row records, selection text updates, activation forwarding, and row drawing.

The list classes should stay adjacent to the item-menu dialogs, but shared `ListPane`, image-control, object-preview, network-packet writer, and `MerchantDialogPane` base helpers should not be migrated into this file.

IDA confirms item menu dialog/list vtables at `0x0061eea8-0x0061f15c`. Current generated metadata reports `vtable_count: 0` for the checked item menu classes.

## Proposed Contents

| Entity | Current range | Current file | Role |
| --- | --- | --- | --- |
| `ServerItemMenuDialog` | `0x0051a520-0x0051ae8d` | `class_ServerItemMenuDialog.cpp` | Parses server-provided item menu packet data, creates the dialog controls, and dispatches selected server menu actions. |
| `ServerItemMenuItemList` | `0x0051ae90-0x0051b87a`, destructor glue at `0x00520b13`, `0x00520b1e`, `0x00520ce0` | `class_ServerItemMenuItemList.cpp` | Server-provided item row list; stores entry records, updates description slot `7`, forwards activation to the owner context, and draws item/value rows. |
| `ClientItemMenuDialog` | `0x0051b880-0x0051c46d` | `class_ClientItemMenuDialog.cpp` | Builds client-side item action menus from local inventory state and sends selected action packets. |
| `ClientItemMenuItemList` | `0x0051c470-0x0051ca3c`, shared destructor glue at `0x00520ad1`, `0x00520adc`, `0x00520c20` | `class_ClientItemMenuItemList.cpp` | Client-side item row list; stores owner/item context, appends local item rows, forwards activation, and draws icon/name rows. |

## IDA MCP Evidence

- `ServerItemMenuDialog` methods are IDA functions at `0x0051a520`, `0x0051acb0`, and `0x0051ae50`.
- `ServerItemMenuItemList` has raw constructor/destructor/helper code at `0x0051ae90`, `0x0051af00`, `0x0051af40`, `0x0051afd0`, and `0x0051b190` that IDA does not currently model as function starts. IDA does model the vtable virtuals at `0x0051b100`, `0x0051b2b0`, `0x0051b2c0`, and `0x0051b3e0`.
- `ClientItemMenuDialog` methods are IDA functions at `0x0051b880`, `0x0051c310`, and `0x0051c430`.
- `ClientItemMenuItemList` has IDA functions at `0x0051c470`, `0x0051c6b0`, and `0x0051c6c0`, plus raw helper code at `0x0051c4e0`, `0x0051c550`, and `0x0051c610`.
- IDA xrefs show `ClientItemMenuDialog` calls `ClientItemMenuItemList` construction at `0x0051ba35` and `0x0051bf64`.
- IDA xrefs do not show direct calls to the out-of-line `ServerItemMenuItemList` constructor at `0x0051ae90`; the server dialog contains inline-equivalent vtable writes at `0x0051a6ff`, `0x0051a705`, and `0x0051a70f`.

## Ownership Notes

- `MerchantDialogPane` stays in [UID:0000L9][MerchantDialogPane](by-file/MerchantDialogPane.md). Its [UID:0001BM][0x00517d80-0x00517ebf.MerchantDialogPaneActionStringVirtual](by-memory/0x00517d80-0x00517ebf.MerchantDialogPaneActionStringVirtual.md) is referenced by item menu dialog vtables, but it is not item-menu-specific.
- [UID:000238][0x00517450-0x00517d23.MenuDialogFactoryHelpers](by-memory/0x00517450-0x00517d23.MenuDialogFactoryHelpers.md) is the shared creator/dispatcher that can allocate the item-menu dialogs for packet subtypes `4` and `5`; keep ownership with the broader merchant/menu dialog family.
- `ObjectImageControlPane`, `ImageButtonControlPane`, `StaticTextControlPane`, `ScrollableControlPane`, and `ListPane` are dependencies created by the dialogs, not file contents here.
- Current generated `ServerItemMenuItemList` includes article/mail paging helpers and generic list-count helpers. IDA caller fanout shows those are not private item-menu list code and should be moved or neutralized before source migration.
- Current generated `ClientItemMenuItemList` treats `0x004f3b60` and `0x00520c20` as class destructors, but IDA vtable/xref evidence shows they are shared list-pane destructor glue also used by spell menu item lists.

## Cross-References

- [UID:0000KE][ItemDialogs](by-file/ItemDialogs.md)
- [UID:0001Y5][MerchantMenuDialogVtableFamily](by-type/by-vtable/MerchantMenuDialogVtableFamily.md)
- [UID:0000CZ][ServerItemMenuDialog](by-class/ServerItemMenuDialog.md)
- [UID:0000D0][ServerItemMenuItemList](by-class/ServerItemMenuItemList.md)
- [UID:00002P][ClientItemMenuDialog](by-class/ClientItemMenuDialog.md)
- [UID:00002Q][ClientItemMenuItemList](by-class/ClientItemMenuItemList.md)
- [UID:0001BP][0x0051ae90-0x0051b87a.ServerItemMenuItemList](by-memory/0x0051ae90-0x0051b87a.ServerItemMenuItemList.md)
- [UID:0001BQ][0x0051c470-0x0051ca3c.ClientItemMenuItemList](by-memory/0x0051c470-0x0051ca3c.ClientItemMenuItemList.md)
- [UID:0001BO][0x0051a520-0x0051c46d.ItemMenuDialogs](by-memory/0x0051a520-0x0051c46d.ItemMenuDialogs.md)
- [UID:000238][0x00517450-0x00517d23.MenuDialogFactoryHelpers](by-memory/0x00517450-0x00517d23.MenuDialogFactoryHelpers.md)
- [UID:0000L9][MerchantDialogPane](by-file/MerchantDialogPane.md)
- [UID:0001BM][0x00517d80-0x00517ebf.MerchantDialogPaneActionStringVirtual](by-memory/0x00517d80-0x00517ebf.MerchantDialogPaneActionStringVirtual.md)
- [UID:0000O2][SpellMenuDialogs](by-file/SpellMenuDialogs.md)

## Changes

- 2026-05-30 completion/confidence scoring:
  - What existed before: `COMPLETION:0` and `CONFIDENCE:0`.
  - Changed to: `COMPLETION:86` and `CONFIDENCE:80`.
  - Summary/evidence: server/client item menu dialog and list roles, vtable/layout anchor, raw helper caveats, creator/merchant base boundaries, and cross-references are documented; confidence is capped by possible folding into `ItemDialogs.cpp` and generated list-pane pollution.
- 2026-06-01: Set `PROPOSED_RECONSTRUCTION_PATH` to `NexusTK/ui/dialogs/` so reviewed item-menu child pages can attach without autogen path errors.
