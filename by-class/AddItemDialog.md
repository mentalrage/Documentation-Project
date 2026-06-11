*** UID:000007 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:85 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:89 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000KE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# AddItemDialog

## Status

- Confidence: strong for behavior and item-dialog module placement.
- Likely source file: [UID:0000KE][ItemDialogs](by-file/ItemDialogs.md)
- Address range: [UID:00014T][0x004ae4c0-0x004b0b15.ItemExchangeMixDialogs](by-memory/0x004ae4c0-0x004b0b15.ItemExchangeMixDialogs.md)
- Parent attachment: [UID:0000KE][ItemDialogs](by-file/ItemDialogs.md) is now `90/87`, so this class remains attached to the item-dialog source module under the corrected gate.
- C++ reconstruction: intentionally blank because the final child-control field names, row-storage type, and packet-helper names are not 95/95 final-source quality.

## Class Purpose

`AddItemDialog` is the base modal item-selection dialog used by exchange-style workflows. It creates a [UID:00008W][MyItemListPane](by-class/MyItemListPane.md) player-inventory picker, supports high-resolution and low-resolution layouts, handles action buttons, and updates button availability from the selected item state.

## Class Shape

- Base class: dialog pane family with three vfptr views at object offsets `+0x00`, `+0xa0`, and `+0xa4`.
- Primary child control: [UID:00008W][MyItemListPane](by-class/MyItemListPane.md), wrapped by a scrollable pane.
- Layout mode: branches on the client display mode byte to build high-resolution and low-resolution resource layouts.
- Owner/context field: live `OnButtonClick` evidence reads the dword at object offset `+0x26c` while serializing selected item rows; exact final field name is still provisional.
- Source placement: reusable item picker code belongs in [UID:0000KE][ItemDialogs](by-file/ItemDialogs.md), not exchange/session or inventory-pane source.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| `AddItemDialog` core | [UID:00033Q][0x004ae4c0-0x004aea7d.AddItemDialogCore](by-memory/0x004ae4c0-0x004aea7d.AddItemDialogCore.md) | Constructor, non-deleting destructor, action handler, and button-state updater. |
| `ExchangePacketCloseHandler` | [UID:000317][0x004aea80-0x004aeab0.AddItemDialogExchangePacketCloseHandler](by-memory/0x004aea80-0x004aeab0.AddItemDialogExchangePacketCloseHandler.md) | Vtable-only secondary-view handler that reacts to packet bytes `0x42/0x04`, dismisses the dialog, and invokes the primary close slot. |
| `SubmitPacketHelper` | [UID:00033R][0x004aeab0-0x004aeb30.AddItemDialogSubmitPacketHelper](by-memory/0x004aeab0-0x004aeb30.AddItemDialogSubmitPacketHelper.md) | Singleton getter plus raw packet helper for opcode `0x4a/1`; IDA does not model the helper as a function, but byte evidence is exact. |
| `SecondaryDestructorAdjustorThunk` | `0x004b08a1-0x004b08ac` | Compiler-generated secondary-view adjustor thunk for the destructor path. |
| `TertiaryDestructorAdjustorThunk` | `0x004b08ac-0x004b08b7` | Compiler-generated tertiary-view adjustor thunk for the delete path. |
| `ScalarDeletingDestructor` | `0x004b0910-0x004b096f` | Restores vtables, clears the active singleton, runs the destructor path, and conditionally frees. |

## Evidence Notes

- IDA MCP `lookup_funcs` on 2026-06-06 confirms the exact half-open ranges listed above, including the 0xb-byte adjustor thunks.
- IDA MCP `callers 0x004ae4c0` reports constructor calls from `EmployeeDialogPane::OnButtonAction` inline construction (`0x004a339f`), `ExchangeDialog::OnButtonAction` (`0x004ad124`), `MixItemDialog::HandleAction` (`0x004af924`), and the `AddMixingItemDialog` constructor (`0x004b0031`).
- IDA MCP `callers 0x004ae930` reports the derived [UID:000006][AddEmployeeItemDialog](by-class/AddEmployeeItemDialog.md) action handler forwarding non-confirm actions to the base handler at `0x004a4b60`.
- IDA MCP reports `MyItemListPane` constructor calls inside this constructor at `0x004ae63e` and `0x004ae7f0`.
- IDA MCP vtable checks confirm table bases at `0x00619e8c`, `0x00619eec`, and `0x00619f1c`, installed at object offsets `+0x00`, `+0xa0`, and `+0xa4`; live store sites include `0x004ae500`, `0x004ae509`, `0x004ae513`, destructor/reset stores at `0x004ae900`, `0x004ae906`, `0x004ae910`, and scalar-deleting stores at `0x004b0916`, `0x004b091c`, and `0x004b0926`.
- IDA MCP xrefs to [UID:0002AY][0x0069b328-0x0069b330.ItemDialogSingletonGlobals](by-memory/0x0069b328-0x0069b330.ItemDialogSingletonGlobals.md) show the active AddItemDialog singleton is published at `0x004ae8d2` and cleared at `0x004ae91a` and `0x004b0930`; sibling cleanup at `0x004b0990` belongs to the AddMixingItemDialog destructor path.
- Decompilation of `0x004ae930` shows button id `1` iterating selected item rows, writing opcode-like bytes including `74` and `1`, reading object offset `+0x26c`, and sending the built seven-byte record through the packet helper; button id `2` shares the close path. Decompilation of `0x004aea40` shows child selector `1` for the action button, child selector `3` for the picker/list control, and virtual enable/disable dispatch from the selection-state check.
- 2026-06-08 IDA MCP `lookup_funcs`, `decompile`, `callers`, `callees`, and `xrefs_to` split the previously aggregate-only `0x004aea80-0x004aeab0` handler: it has a vtable ref at `0x00619efc`, no direct callers, checks packet bytes `0x42/0x04`, adjusts `this - 0xa0`, calls close helper `0x0049eb90`, and then invokes the primary close slot.
- 2026-06-10 B001-026 split the previously aggregate-only core and raw helper rows as [UID:00033Q][0x004ae4c0-0x004aea7d.AddItemDialogCore](by-memory/0x004ae4c0-0x004aea7d.AddItemDialogCore.md) and [UID:00033R][0x004aeab0-0x004aeb30.AddItemDialogSubmitPacketHelper](by-memory/0x004aeab0-0x004aeb30.AddItemDialogSubmitPacketHelper.md). The raw helper has no ordinary xrefs, but disassembly confirms opcode `0x4a`, subtype `1`, context read at `this+0x26c`, and a seven-byte packet send.
- This is item-selection UI and should not be merged into item inventory panes or item image libraries.

## Score Rationale

- Completion is raised to `85` because the page now records exact half-open method ranges, constructor callers, derived fallback caller, MyItemListPane construction sites, vtable stores, singleton publish/clear refs, button/update behavior, the packet-close helper child, parent attachment, and the reconstruction gate.
- Confidence is raised to `89` because ownership, range, vtable layout, singleton lifecycle, and key behavior are live IDA-confirmed; it remains below 95 because final source-facing names for fields, row storage, inherited packet-handler slots, and packet helpers are still unresolved.

## Cross-References

- [UID:0000KE][ItemDialogs](by-file/ItemDialogs.md)
- [UID:00008W][MyItemListPane](by-class/MyItemListPane.md)
- [UID:00014T][0x004ae4c0-0x004b0b15.ItemExchangeMixDialogs](by-memory/0x004ae4c0-0x004b0b15.ItemExchangeMixDialogs.md)
- [UID:000317][0x004aea80-0x004aeab0.AddItemDialogExchangePacketCloseHandler](by-memory/0x004aea80-0x004aeab0.AddItemDialogExchangePacketCloseHandler.md)
- [UID:00033Q][0x004ae4c0-0x004aea7d.AddItemDialogCore](by-memory/0x004ae4c0-0x004aea7d.AddItemDialogCore.md)
- [UID:00033R][0x004aeab0-0x004aeb30.AddItemDialogSubmitPacketHelper](by-memory/0x004aeab0-0x004aeb30.AddItemDialogSubmitPacketHelper.md)
- [UID:00033Y][0x004b08a1-0x004b0b15.ItemExchangeDestructorAndThunkStrip](by-memory/0x004b08a1-0x004b0b15.ItemExchangeDestructorAndThunkStrip.md)
- [UID:0001XV][ItemDialogVtableFamily](by-type/by-vtable/ItemDialogVtableFamily.md)
- [UID:0002AY][0x0069b328-0x0069b330.ItemDialogSingletonGlobals](by-memory/0x0069b328-0x0069b330.ItemDialogSingletonGlobals.md)
- [UID:000008][AddItemWithCountDialog](by-class/AddItemWithCountDialog.md)
- [UID:000009][AddMixingItemDialog](by-class/AddMixingItemDialog.md)

## Changes

- 2026-06-06 live IDA attachment pass:
  - What existed before: the page was scored `72/86`, had no autogen parent, used stale source-owner wording, and recorded several function ranges with final executed-byte endpoints instead of half-open IDA ranges.
  - What changed: raised scores to `82/88`, attached the class to [UID:0000KE][ItemDialogs](by-file/ItemDialogs.md), converted method rows to half-open live IDA ranges, replaced stale owner wording with IDA-backed caller/vtable/singleton/behavior evidence, added score rationale, and kept final C++ blank below the 95/95 gate.
  - Summary/evidence: IDA MCP `lookup_funcs`, `callers`, `callees`, `decompile`, and `py_eval` on 2026-06-06 confirm the constructor/destructor/action/update/thunk boundaries, constructor caller fanout, AddEmployee fallback caller, MyItemListPane construction sites, AddItemDialog vtable stores, active singleton publish/clear refs, and selected-row/action-button behavior.
- What existed before: the page had strong evidence but metadata remained `0/0`, and the class-level layout/source-placement summary was implicit in evidence bullets.
- What it was changed to: scores were set to `72/86`, and a class-shape section now records base/vfptr layout, child picker ownership, layout branching, and final source placement.
- Summary and evidence: existing IDA MCP function/vtable checks support strong confidence, while unresolved exact field naming keeps completion below high.
- 2026-06-05: Reclassified autogen metadata from unclassified to `RECONSTRUCTABLE:TRUE`. Current IDA MCP `lookup_funcs` re-confirmed the constructor, destructor, command handler, and button-state method starts at `0x004ae4c0`, `0x004ae900`, `0x004ae930`, and `0x004aea40`, and `callers` showed the constructor is live from nearby item/exchange dialog code. Parent attachment was deferred at that time because the class completion score was still below the 80+ attachment gate.
- 2026-06-08 A007 Batch 116 packet handler split:
  - Before: score `82/88`; `0x004aea80` was mentioned only as an unsplit aggregate helper.
  - After: score `85/89`; added exact child [UID:000317][0x004aea80-0x004aeab0.AddItemDialogExchangePacketCloseHandler](by-memory/0x004aea80-0x004aeab0.AddItemDialogExchangePacketCloseHandler.md), keeping final C++ blank.
  - Summary/evidence: current IDA MCP confirms the `0x30`-byte vtable-only helper, vtable ref `0x00619efc`, `0x42/0x04` packet check, `this - 0xa0` adjustment, close helper call, and direct AddItemDialog ownership. This raises the class above the strict 85/85 parent gate for the new child.
- 2026-06-10 B001-026 split repair:
  - Added exact core child [UID:00033Q][0x004ae4c0-0x004aea7d.AddItemDialogCore](by-memory/0x004ae4c0-0x004aea7d.AddItemDialogCore.md), exact raw helper child [UID:00033R][0x004aeab0-0x004aeb30.AddItemDialogSubmitPacketHelper](by-memory/0x004aeab0-0x004aeb30.AddItemDialogSubmitPacketHelper.md), and linked the non-emitting mixed destructor/thunk strip [UID:00033Y][0x004b08a1-0x004b0b15.ItemExchangeDestructorAndThunkStrip](by-memory/0x004b08a1-0x004b0b15.ItemExchangeDestructorAndThunkStrip.md).
  - Evidence: B001 IDA disassembly confirmed the raw helper body that the broad aggregate had not split; class score remains `85/89`, which clears the direct-parent gate.
