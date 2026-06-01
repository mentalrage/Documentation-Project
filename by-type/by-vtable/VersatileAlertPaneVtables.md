*** UID:0001Z0 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# VersatileAlertPane Vtables

## Status

- Entity kind: vtable cluster.
- Covered class: [UID:0000FU][VersatileAlertPane](by-class/VersatileAlertPane.md).
- Likely source file: [UID:0000HE][AlertPanes](by-file/AlertPanes.md).
- Confidence: strong for vtable bases, constructor stores, callback virtual slots, and destructor slots.
- Exact memory child: [UID:0002P1][0x00618ba0-0x00618c44.VersatileAlertPaneVtableData](by-memory/0x00618ba0-0x00618c44.VersatileAlertPaneVtableData.md).

## Vtable Bases

| Class view | Base | Constructor store | Object offset | Notes |
| --- | --- | --- | --- | --- |
| primary | `0x00618ba4` | `0x004a06b6` | `+0x00` | Installed after `AlertPane` base construction. |
| secondary | `0x00618c0c` | `0x004a06bc` | `+0xa0` | Secondary dialog/input view. |
| tertiary | `0x00618c3c` | `0x004a06c6` | `+0xa4` | Event/update-handler view. |

The same three vtables are also reinstalled by the cleanup-shaped body at [UID:00012Y][0x004a06e0-0x004a0714.VersatileAlertPaneRawCleanup](by-memory/0x004a06e0-0x004a0714.VersatileAlertPaneRawCleanup.md) and by the scalar deleting destructor at `0x004a0cd0-0x004a0d37`.

## Notable Slots

| Vtable | Slot | Target | Notes |
| --- | --- | --- | --- |
| primary `0x00618ba4` | `+0x00` | `0x004a0cd0` | `VersatileAlertPane::ScalarDeletingDestructor`. |
| primary `0x00618ba4` | `+0x44` | `0x0049f090` | Inherited dialog focus/selection drawing virtual. |
| primary `0x00618ba4` | `+0x48` | `0x004a0580` | Inherited `AlertPane::DismissDialog` action-dispatch path. |
| primary `0x00618ba4` | `+0x50` | `0x0049f1d0` | Inherited dialog content drawing virtual. |
| primary `0x00618ba4` | `+0x54` | `0x0049f2e0` | Inherited dialog border drawing virtual. |
| primary `0x00618ba4` | `+0x58` | `0x0049fc00` | Inherited dialog hover/update virtual. |
| primary `0x00618ba4` | `+0x5c` | `0x004a0720` | `VersatileAlertPane::OnAccept`, reports result `1` through the stored callback. |
| primary `0x00618ba4` | `+0x60` | `0x004a0740` | `VersatileAlertPane::OnCancel`, reports result `0` through the stored callback. |
| secondary `0x00618c0c` | `+0x00` | `0x004a0cb0` | Adjustor thunk into the scalar deleting destructor with `this - 0xa0`. |
| tertiary `0x00618c3c` | `+0x00` | `0x004a0cbb` | Adjustor thunk into the scalar deleting destructor with `this - 0xa4`. |
| tertiary `0x00618c3c` | `+0x04` | `0x00544e90` | Base/default event-update slot. |

Do not read primary `+0x64` as a `VersatileAlertPane` virtual: it is RTTI metadata for the secondary table at `0x00618c0c`. Likewise, secondary `+0x2c` is RTTI metadata for the tertiary table, and tertiary `+0x08` belongs to the following `ModelessDialogPane` RTTI region.

## IDA MCP Evidence

- IDA MCP `py_eval` on 2026-06-01 confirms the exact RTTI-adjacent data range `0x00618ba0-0x00618c44`: `0x00618ba0`, `0x00618c08`, and `0x00618c38` point to `VersatileAlertPane` RTTI records, while `0x00618c44` points to the following `ModelessDialogPane` RTTI record and is outside this item.
- `list_globals *VersatileAlertPane*` reports vtables at `0x00618ba4`, `0x00618c0c`, and `0x00618c3c`, plus RTTI records at `0x00646644`, `0x006466a8`, and `0x006466bc`.
- `xrefs_to` the three vtable bases reports constructor stores at `0x004a06b6`, `0x004a06bc`, and `0x004a06c6` inside `VersatileAlertPane::VersatileAlertPane` at `0x004a0690`.
- The same vtable bases have data xrefs from `0x004a06e9`, `0x004a06ef`, and `0x004a06f9` inside an unreferenced cleanup-shaped body, and from `0x004a0cdc`, `0x004a0ce2`, and `0x004a0cec` inside the scalar deleting destructor.
- `lookup_funcs` confirms `0x004a0690`, `0x004a0720`, `0x004a0740`, `0x004a0cb0`, `0x004a0cbb`, and `0x004a0cd0` as function starts. IDA does not currently model `0x004a06e0` as a function, and `xrefs_to 0x004a06e0` returns no callers.
- `xrefs_to 0x004a0690` reports constructor calls from `0x005301de` and `0x0058b5c5`.
- `0x00618c44` points to `??_R4ModelessDialogPane@@6B@`, followed by `??_7ModelessDialogPane@@6B@` at `0x00618c48`, proving that the versatile alert vtable cluster ends before `0x00618c44`.

## Reconstruction Notes

Model `VersatileAlertPane` as a thin `AlertPane` subclass with three vtable views at `+0x00`, `+0xa0`, and `+0xa4`. The class-specific behavior is concentrated in the callback object at offset `+0x270` and the two primary-table callback extension slots at `+0x5c` and `+0x60`.

Keep `0x004a0cb0` and `0x004a0cbb` as compiler adjustor thunks, not source methods. Keep [UID:00012Y][0x004a06e0-0x004a0714.VersatileAlertPaneRawCleanup](by-memory/0x004a06e0-0x004a0714.VersatileAlertPaneRawCleanup.md) documented as unreferenced cleanup-shaped code unless later xrefs prove it is an explicitly callable method.

## Cross-References

- [UID:0000FU][VersatileAlertPane](by-class/VersatileAlertPane.md)
- [UID:0000HE][AlertPanes](by-file/AlertPanes.md)
- [UID:00012X][0x004a0690-0x004a0752.VersatileAlertPaneCallbacks](by-memory/0x004a0690-0x004a0752.VersatileAlertPaneCallbacks.md)
- [UID:00012Y][0x004a06e0-0x004a0714.VersatileAlertPaneRawCleanup](by-memory/0x004a06e0-0x004a0714.VersatileAlertPaneRawCleanup.md)
- [UID:000130][0x004a0cb0-0x004a0d37.VersatileAlertPaneDestructor](by-memory/0x004a0cb0-0x004a0d37.VersatileAlertPaneDestructor.md)
- [UID:0001WZ][AlertPaneVtables](by-type/by-vtable/AlertPaneVtables.md)
- [UID:00012W][0x0049feb0-0x004a0686.AlertPaneCore](by-memory/0x0049feb0-0x004a0686.AlertPaneCore.md)
- [UID:0002P1][0x00618ba0-0x00618c44.VersatileAlertPaneVtableData](by-memory/0x00618ba0-0x00618c44.VersatileAlertPaneVtableData.md)

## Changes

- What existed before: this page listed the three vtable bases and slot evidence, but kept completion/confidence at `0/0`, cited incomplete Wave3 metadata, and did not have a precise by-memory child range.
- What changed: completion/confidence is now `84/90`, `RECONSTRUCTABLE` is marked `TRUE`, the stale Wave3 caveat was replaced with IDA MCP boundary evidence, and the exact child range [UID:0002P1][0x00618ba0-0x00618c44.VersatileAlertPaneVtableData](by-memory/0x00618ba0-0x00618c44.VersatileAlertPaneVtableData.md) was added.
- Evidence: IDA MCP `py_eval` on 2026-06-01 read the RTTI/vtable dwords and xrefs at `0x00618ba0-0x00618c44`, with `ModelessDialogPane` RTTI beginning at `0x00618c44`.
