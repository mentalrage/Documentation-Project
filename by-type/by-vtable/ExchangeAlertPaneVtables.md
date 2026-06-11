*** UID:0001XJ | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:00004Q | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# ExchangeAlertPane Vtables

## Status

- Entity kind: vtable cluster.
- Covered class: [UID:00004Q][ExchangeAlertPane](by-class/ExchangeAlertPane.md).
- Likely source file: [UID:0000J9][ExchangeDialog](by-file/ExchangeDialog.md).
- Exact memory child: [UID:0002NF][0x0061a1c0-0x0061a260.ExchangeAlertPaneVtableData](by-memory/0x0061a1c0-0x0061a260.ExchangeAlertPaneVtableData.md).
- Confidence: strong for vtable bases, constructor stores, button-dispatch slot, and adjustor thunks.
- Autogen status: attached to the `ExchangeAlertPane` class page; final C++ remains blank under the `95/95` reconstruction gate.

## Vtable Bases

| Class view | Base | Constructor store | Object offset | Notes |
| --- | --- | --- | --- | --- |
| primary | `0x0061a1c0` | `0x004b0514` | `+0x00` | Installed after blank `DialogPane` construction and active singleton setup. |
| secondary | `0x0061a228` | `0x004b051a` | `+0xa0` | Secondary dialog/input view. |
| tertiary | `0x0061a258` | `0x004b0524` | `+0xa4` | Event/update-handler view. |

Unlike several neighboring dialog destructors, the scalar deleting destructor at `0x004b09d0` does not reinstall the class vtables; it clears [UID:0000QV][g_pExchangeAlertPane](by-global/g_pExchangeAlertPane.md), calls dialog/base teardown, and conditionally frees storage.

## Notable Slots

| Vtable | Slot | Target | Notes |
| --- | --- | --- | --- |
| primary `0x0061a1c0` | `+0x00` | `0x004b09d0` | `ExchangeAlertPane::ScalarDeletingDestructor`. |
| primary `0x0061a1c0` | `+0x44` | `0x0049f090` | Inherited dialog focus/selection drawing virtual. |
| primary `0x0061a1c0` | `+0x48` | `0x004b0820` | `ExchangeAlertPane::OnButtonClick`. |
| primary `0x0061a1c0` | `+0x50` | `0x0049f1d0` | Inherited dialog content drawing virtual. |
| primary `0x0061a1c0` | `+0x54` | `0x0049f2e0` | Inherited dialog border drawing virtual. |
| primary `0x0061a1c0` | `+0x58` | `0x0049fc00` | Inherited dialog hover/update virtual. |
| primary `0x0061a1c0` | `+0x5c` | `0x0041b6a0` | Base no-op/guard primary callback slot. `OnButtonClick` invokes this slot for button id `1`. |
| primary `0x0061a1c0` | `+0x60` | `0x0041b6a0` | Base no-op/guard secondary callback slot. `OnButtonClick` invokes this slot for button id `2`. |
| secondary `0x0061a228` | `+0x00` | `0x004b08cd` | Adjustor thunk into scalar deleting destructor with `this - 0xa0`. |
| tertiary `0x0061a258` | `+0x00` | `0x004b08d8` | Adjustor thunk into scalar deleting destructor with `this - 0xa4`. |
| tertiary `0x0061a258` | `+0x04` | `0x00544e90` | Base/default event-update slot. |

Do not read primary `+0x64` as an `ExchangeAlertPane` virtual: it is RTTI metadata for the secondary table at `0x0061a228`. Likewise, secondary `+0x2c` is RTTI metadata for the tertiary table, and tertiary `+0x08` belongs to the following `ExchangeMoneyEditControlPane` RTTI region.

## IDA MCP Evidence

- `list_globals *ExchangeAlertPane*` reports vtables at `0x0061a1c0`, `0x0061a228`, and `0x0061a258`, plus RTTI records at `0x006475d0`, `0x00647684`, and `0x00647698`.
- `xrefs_to` the three vtable bases reports constructor stores at `0x004b0514`, `0x004b051a`, and `0x004b0524` inside `ExchangeAlertPane::ExchangeAlertPane` at `0x004b0490`.
- `lookup_funcs` confirms `0x004b0490`, `0x004b0820`, `0x004b0860`, `0x004b08cd`, `0x004b08d8`, `0x004b09d0`, and `0x004b0b20` as function starts.
- `xrefs_to 0x004b0820` reports a primary-vtable data ref at `0x0061a208`.
- `xrefs_to 0x004b08cd` and `0x004b08d8` reports secondary/tertiary vtable data refs at `0x0061a228` and `0x0061a258`.
- `xrefs_to 0x004b0490` reports constructor calls from `0x004ad656`, `0x004ad775`, `0x004ade18`, and `0x004adf8d`, all inside exchange packet/alert helpers.
- 2026-05-31 IDA MCP `py_eval` over `0x0061a1bc-0x0061a280` confirms the exact child range [UID:0002NF][0x0061a1c0-0x0061a260.ExchangeAlertPaneVtableData](by-memory/0x0061a1c0-0x0061a260.ExchangeAlertPaneVtableData.md): `0x0061a1bc`, `0x0061a224`, and `0x0061a254` are `ExchangeAlertPane` RTTI locator dwords, while `0x0061a260` starts the adjacent `ExchangeMoneyEditControlPane` RTTI locator.
- Current Wave3 metadata for `class_ExchangeAlertPane.meta_wave3` reports `vtable_count: 0`, so generated vtable inventory is incomplete despite active source placeholders for `ExchangeAlertPane_vtable`, `ExchangeAlertPane_vtable2`, and `ExchangeAlertPane_vtable3`.

## Reconstruction Notes

Model `ExchangeAlertPane` as an exchange-owned `DialogPane`-derived alert class with three vtable views at `+0x00`, `+0xa0`, and `+0xa4`. The feature-specific behavior is the constructor, singleton ownership, and `OnButtonClick`; most drawing/event behavior is inherited.

`OnButtonClick` invokes primary-table slots `+0x5c` and `+0x60` after slide-close, but this concrete vtable currently holds no-op/guard functions in both slots. Preserve that dispatch pattern in the reconstructed class while avoiding invented callback overrides.

Keep `0x004b08cd` and `0x004b08d8` as compiler-generated adjustor thunks. They should be represented by inheritance/vtable layout, not handwritten source functions.

## Parent Rationale

Attach this vtable cluster to [UID:00004Q][ExchangeAlertPane](by-class/ExchangeAlertPane.md) because the three tables are the class's primary, secondary, and tertiary virtual views installed by `ExchangeAlertPane::ExchangeAlertPane` at `0x004b0490` and consumed by `OnButtonClick`, the scalar deleting destructor, and the compiler-generated adjustor thunks. The class page is already reconstructable, attached to [UID:0000J9][ExchangeDialog](by-file/ExchangeDialog.md), and records the same constructor stores, singleton ownership, button-dispatch slot, exact vtable-data child, and boundary before `ExchangeMoneyEditControlPane`. The vtable page remains the narrow evidence home for slot order and `.rdata` boundaries.

## Cross-References

- [UID:00004Q][ExchangeAlertPane](by-class/ExchangeAlertPane.md)
- [UID:0000J9][ExchangeDialog](by-file/ExchangeDialog.md)
- [UID:0002NF][0x0061a1c0-0x0061a260.ExchangeAlertPaneVtableData](by-memory/0x0061a1c0-0x0061a260.ExchangeAlertPaneVtableData.md)
- [UID:00014V][0x004b0490-0x004b0ba5.ExchangeDialogTail](by-memory/0x004b0490-0x004b0ba5.ExchangeDialogTail.md)
- [UID:00014X][0x004b08cd-0x004b08e3.ExchangeAlertPaneAdjustorThunks](by-memory/0x004b08cd-0x004b08e3.ExchangeAlertPaneAdjustorThunks.md)
- [UID:0000QV][g_pExchangeAlertPane](by-global/g_pExchangeAlertPane.md)
- [UID:0001WZ][AlertPaneVtables](by-type/by-vtable/AlertPaneVtables.md)

## Changes

- 2026-06-07 parent attachment update:
  - What existed before: the vtable cluster was reconstructable but unassigned in generated type coverage despite the owning class and file pages already clearing the attachment gate.
  - What changed: attached the vtable cluster to [UID:00004Q][ExchangeAlertPane](by-class/ExchangeAlertPane.md), raised completion to `86`, and added an explicit parent rationale.
  - Summary/evidence: constructor stores at `0x004b0514`, `0x004b051a`, and `0x004b0524`, exact [UID:0002NF][0x0061a1c0-0x0061a260.ExchangeAlertPaneVtableData](by-memory/0x0061a1c0-0x0061a260.ExchangeAlertPaneVtableData.md), and the class page's `82/88` score support the parent assignment; confidence stays below final-audit level because source-facing callback naming and exact original filename questions remain open.

- 2026-05-31:
  - Before: metadata was unevaluated and the page relied on a vtable-base inventory without a dedicated exact by-memory child page.
  - Changed to: scored as `84/90`, marked reconstructable, and linked to exact child [UID:0002NF][0x0061a1c0-0x0061a260.ExchangeAlertPaneVtableData](by-memory/0x0061a1c0-0x0061a260.ExchangeAlertPaneVtableData.md).
  - Summary/evidence: IDA MCP `py_eval`, `xrefs_to`, `lookup_funcs`, and decompilation confirm the three table bases, constructor stores, key slot targets, adjustor thunks, and the `0x0061a260` boundary before `ExchangeMoneyEditControlPane`.
