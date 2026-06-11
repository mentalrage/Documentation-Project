*** UID:000008 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:85 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:89 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000KE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# AddItemWithCountDialog

## Status

- Confidence: strong for behavior and item-dialog module placement.
- Likely source file: [UID:0000KE][ItemDialogs](by-file/ItemDialogs.md)
- Address range: [UID:00014T][0x004ae4c0-0x004b0b15.ItemExchangeMixDialogs](by-memory/0x004ae4c0-0x004b0b15.ItemExchangeMixDialogs.md)
- Parent attachment: [UID:0000KE][ItemDialogs](by-file/ItemDialogs.md) is `90/87` after the Batch 116 parent-source refresh, so this class is attached to the reusable item-dialog source module.
- Rebuild handling: source-authored item-dialog class; C++ remains blank until constructor parameters, count field names, and inherited dialog slots are final-source quality.

## Class Purpose

`AddItemWithCountDialog` is the quantity-aware item add dialog. It is used when an item action must collect a count before dispatching the selected item operation.

## Class Shape

- Base relationship: item-dialog family sibling/variant of [UID:000007][AddItemDialog](by-class/AddItemDialog.md).
- Vtable family: primary/secondary/tertiary tables at `0x00619fec`, `0x0061a04c`, and `0x0061a07c`.
- Role split: this class owns the item-specific count dispatch path; generic numeric input behavior should remain with the reusable numeric/dialog input classes.
- Stored constructor state: live IDA decompilation stores the exchange/item context dword at `this+0x26c` and the selected item/type byte at `this+0x270`.
- Source placement: [UID:0000KE][ItemDialogs](by-file/ItemDialogs.md).

## Ownership And Boundary Evidence

| Evidence | Meaning |
| --- | --- |
| [UID:0000KE][ItemDialogs](by-file/ItemDialogs.md) lists `AddItemWithCountDialog` in the reusable item-picker/mix source cluster. | The class belongs with generic item dialog source, not with the exchange session window or inventory rendering. |
| [UID:00014T][0x004ae4c0-0x004b0b15.ItemExchangeMixDialogs](by-memory/0x004ae4c0-0x004b0b15.ItemExchangeMixDialogs.md) covers the quantity-aware add-item dialog range around `0x004af040-0x004af4b7`. | The class body is physically inside the reviewed item exchange/mix dialog island, with `0x004af4b7-0x004af570` alignment before `MixItemDialog`. |
| [UID:0001XV][ItemDialogVtableFamily](by-type/by-vtable/ItemDialogVtableFamily.md) records constructor stores for the three dialog vfptr views. | The class is a concrete dialog variant using the same three-view layout as `AddItemDialog`, `MixItemDialog`, and `AddMixingItemDialog`. |
| [UID:00014M][0x004ada90-0x004adb02.ExchangeDialogAddItemWithCountHelper](by-memory/0x004ada90-0x004adb02.ExchangeDialogAddItemWithCountHelper.md) constructs this dialog from exchange packet data. | Exchange is a caller/consumer; it should not own the picker implementation. |
| [UID:00014L][0x004ad320-0x004ad7b3.ExchangeDialogPacketDispatcher](by-memory/0x004ad320-0x004ad7b3.ExchangeDialogPacketDispatcher.md) also constructs this dialog directly for exchange packet subcommand `1`. | The reusable picker has two live constructor call sites from exchange code, but no evidence that the class implementation belongs in `ExchangeDialog.cpp`. |

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| `AddItemWithCountDialog` core | [UID:00033S][0x004af040-0x004af4b7.AddItemWithCountDialogCore](by-memory/0x004af040-0x004af4b7.AddItemWithCountDialogCore.md) | Constructor, confirm/cancel action handler, and count-input state updater. |
| `ExchangePacketCloseHandler` | [UID:000318][0x004af4c0-0x004af4f0.AddItemWithCountDialogExchangePacketCloseHandler](by-memory/0x004af4c0-0x004af4f0.AddItemWithCountDialogExchangePacketCloseHandler.md) | Vtable-only secondary-view handler that reacts to packet bytes `0x42/0x04`, dismisses the dialog, and runs the close helper. |
| `SubmitPacketHelper` | [UID:00033T][0x004af4f0-0x004af570.AddItemWithCountDialogSubmitPacketHelper](by-memory/0x004af4f0-0x004af570.AddItemWithCountDialogSubmitPacketHelper.md) | Raw helper that serializes opcode `0x4a/2/context/item/count` and sends eight bytes; this replaces the stale aggregate "padding" claim. |

## Reconstruction Notes

- Treat this as a reusable `ItemDialogs` picker variant. The exchange packet helper passes data into it, but the class implementation stays with item-dialog UI.
- Do not fold it into [UID:0000M1][NumberInputDialog](by-file/NumberInputDialog.md); this class owns item-specific selection/count dispatch, while number-entry behavior remains a reusable dialog dependency.
- The current evidence supports future reconstruction, but not final emitted C++. The parameter names, inherited slot names, and item/count field layout still need method-level confirmation.

## Evidence Notes

- IDA MCP `lookup_funcs` on 2026-06-06 confirms exact half-open ranges `0x004af040-0x004af371`, `0x004af380-0x004af47a`, and `0x004af480-0x004af4b7`; `0x004af4b7` is not a function and is followed by alignment before `MixItemDialog` starts at `0x004af570`.
- IDA MCP `callers 0x004af040` reports the two constructor call sites: [UID:00014L][0x004ad320-0x004ad7b3.ExchangeDialogPacketDispatcher](by-memory/0x004ad320-0x004ad7b3.ExchangeDialogPacketDispatcher.md) at `0x004ad3bf` and [UID:00014M][0x004ada90-0x004adb02.ExchangeDialogAddItemWithCountHelper](by-memory/0x004ada90-0x004adb02.ExchangeDialogAddItemWithCountHelper.md) at `0x004adaeb`.
- IDA MCP `xrefs_to 0x004af380` and `0x004af480` reports data refs at `0x0061a034` and `0x0061a038`, matching the class-specific action/update virtual slots in the AddItemWithCountDialog vtable.
- IDA MCP vtable checks confirm table bases at `0x00619fec`, `0x0061a04c`, and `0x0061a07c`, installed at object offsets `+0x00`, `+0xa0`, and `+0xa4`; live constructor stores are `0x004af0ae`, `0x004af0b4`, and `0x004af0be`.
- Constructor decompilation records the stored constructor arguments at `this+0x26c` and `this+0x270`, formats a text label through item metadata/global lookup, and builds child controls including the count entry and OK/cancel/action controls.
- Action decompilation reads child selector `4` as the count input, parses it with wide `"%hu"`, clamps values `>= 0xff` down to `255`, serializes packet bytes `0x4a` and `2`, includes the context dword from `this+0x26c`, includes the stored item/type byte from `this+0x270`, and sends an eight-byte record.
- 2026-06-08 IDA MCP split the previously aggregate-only `0x004af4c0-0x004af4f0` helper: it has a vtable ref at `0x0061a05c`, no direct callers, checks packet bytes `0x42/0x04`, adjusts `this - 0xa0`, and calls close helpers `0x0049eb90` and `0x0049dad0`.
- 2026-06-10 B001-026 split the previously aggregate-only core and raw helper rows as [UID:00033S][0x004af040-0x004af4b7.AddItemWithCountDialogCore](by-memory/0x004af040-0x004af4b7.AddItemWithCountDialogCore.md) and [UID:00033T][0x004af4f0-0x004af570.AddItemWithCountDialogSubmitPacketHelper](by-memory/0x004af4f0-0x004af570.AddItemWithCountDialogSubmitPacketHelper.md). The raw helper contradicts the stale target claim that `0x004af4f0-0x004af570` was padding.
- The class belongs with exchange/mix item dialogs rather than generic numeric input panes because it owns the item-specific dispatch.

## Score Rationale

- Completion is raised to `85` because the page now records exact method boundaries, constructor call sites, vtable/action-slot refs, field offsets, count-entry behavior, packet serialization, the packet-close helper child, source placement, parent attachment, and the reconstruction gate.
- Confidence is raised to `89` because range, ownership, vtable layout, caller relationships, and behavior are live IDA-confirmed; it remains below 95 because final field/control names, inherited packet-handler slots, and packet-helper names are still unresolved.

## Cross-References

- [UID:0000KE][ItemDialogs](by-file/ItemDialogs.md)
- [UID:00014T][0x004ae4c0-0x004b0b15.ItemExchangeMixDialogs](by-memory/0x004ae4c0-0x004b0b15.ItemExchangeMixDialogs.md)
- [UID:000318][0x004af4c0-0x004af4f0.AddItemWithCountDialogExchangePacketCloseHandler](by-memory/0x004af4c0-0x004af4f0.AddItemWithCountDialogExchangePacketCloseHandler.md)
- [UID:00033S][0x004af040-0x004af4b7.AddItemWithCountDialogCore](by-memory/0x004af040-0x004af4b7.AddItemWithCountDialogCore.md)
- [UID:00033T][0x004af4f0-0x004af570.AddItemWithCountDialogSubmitPacketHelper](by-memory/0x004af4f0-0x004af570.AddItemWithCountDialogSubmitPacketHelper.md)
- [UID:0001XV][ItemDialogVtableFamily](by-type/by-vtable/ItemDialogVtableFamily.md)
- [UID:000007][AddItemDialog](by-class/AddItemDialog.md)
- [UID:00014M][0x004ada90-0x004adb02.ExchangeDialogAddItemWithCountHelper](by-memory/0x004ada90-0x004adb02.ExchangeDialogAddItemWithCountHelper.md)
- [UID:00014L][0x004ad320-0x004ad7b3.ExchangeDialogPacketDispatcher](by-memory/0x004ad320-0x004ad7b3.ExchangeDialogPacketDispatcher.md)
- [UID:0000M1][NumberInputDialog](by-file/NumberInputDialog.md)

## Changes

- 2026-06-06 live IDA attachment pass:
  - What existed before: the page was scored `72/86`, had no autogen parent, used stale source-owner wording, and recorded final-byte method endpoints.
  - What changed: raised scores to `82/88`, attached the class to [UID:0000KE][ItemDialogs](by-file/ItemDialogs.md), converted method rows to half-open IDA ranges, added constructor caller and vtable-slot evidence, documented stored offsets `+0x26c`/`+0x270`, documented confirm/count packet behavior, and kept final C++ blank below the 95/95 gate.
  - Summary/evidence: IDA MCP `lookup_funcs`, `callers`, `callees`, `xrefs_to`, `decompile`, and byte-boundary checks on 2026-06-06 confirm the three method ranges, two live constructor call sites, data refs for action/update virtual slots, vtable constructor stores, child selector behavior, count clamp, packet serialization, and alignment before `MixItemDialog`.
- What existed before: the page was documented but still scored as unevaluated.
- What it was changed to: scores were set to `66/84`, and a short class-shape section now records vtable anchors, family relationship, role split, and source placement.
- Summary and evidence: IDA MCP confirms the three method starts and vtable bases, but the page still needs deeper field/parameter naming and full method-level cross-links before completion should be high.
- 2026-06-02: Raised from `66/84` to `72/86` after adding ownership/boundary and reconstruction notes.
  - Added evidence tying the class to `ItemDialogs`, the exact `ItemExchangeMixDialogs` range, the item-dialog vtable family, and the exchange helper that constructs it.
  - Kept reconstruction C++ blank because source-quality parameter names, inherited slot names, and count/item field layout are still open.
- 2026-06-05: Reclassified autogen metadata from unclassified to `RECONSTRUCTABLE:TRUE`. Current IDA MCP `lookup_funcs` re-confirmed the constructor/action/dispatch method starts at `0x004af040`, `0x004af380`, and `0x004af480`, and `callers` showed the constructor is still reached from exchange item-dialog helpers. Parent attachment was deferred at that time because the class completion score was still below the 80+ attachment gate.
- 2026-06-08 A007 Batch 116 packet handler split:
  - Before: score `82/88`; `0x004af4c0` was mentioned only as an unsplit aggregate helper.
  - After: score `85/89`; added exact child [UID:000318][0x004af4c0-0x004af4f0.AddItemWithCountDialogExchangePacketCloseHandler](by-memory/0x004af4c0-0x004af4f0.AddItemWithCountDialogExchangePacketCloseHandler.md), keeping final C++ blank.
  - Summary/evidence: current IDA MCP confirms the `0x30`-byte vtable-only helper, vtable ref `0x0061a05c`, `0x42/0x04` packet check, `this - 0xa0` adjustment, close helper calls, and direct AddItemWithCountDialog ownership. This raises the class above the strict 85/85 parent gate for the new child.
- 2026-06-10 B001-026 split repair:
  - Added exact core child [UID:00033S][0x004af040-0x004af4b7.AddItemWithCountDialogCore](by-memory/0x004af040-0x004af4b7.AddItemWithCountDialogCore.md) and raw helper child [UID:00033T][0x004af4f0-0x004af570.AddItemWithCountDialogSubmitPacketHelper](by-memory/0x004af4f0-0x004af570.AddItemWithCountDialogSubmitPacketHelper.md).
  - Evidence: B001 IDA disassembly confirmed the raw `0x4a/2` packet helper; class score remains `85/89`, which clears the direct-parent gate.
