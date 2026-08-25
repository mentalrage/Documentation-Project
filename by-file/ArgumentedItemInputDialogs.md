*** UID:0000HH | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:93 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"NexusTK/ui/dialogs/" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:FILE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***

# ArgumentedItemInputDialogs

## Status

- Confidence: very strong for the confirm/quantity dialog behavior, exact function boundaries, vtable/RTTI anchors, caller set, packet-send helper format, layouts, resources, and complete source/header route.
- Accepted source placement: standalone `NexusTK/ui/dialogs/ArgumentedItemInputDialogs.cpp` with sibling `ArgumentedItemInputDialogs.h`. The former folded-file possibility is retained below only as a historical alternative superseded by the complete two-class code/data boundary.
- Proposed module folder: `ui/dialogs/`
- Candidate file: `NexusTK/ui/dialogs/ArgumentedItemInputDialogs.cpp`
- Historical folded candidate: `NexusTK/ui/dialogs/ArgumentedMenuDialogs.cpp` (superseded; its list-context helpers remain a dependency).
- Evidence basis: live IDA MCP function/disassembly/decompilation checks on 2026-06-04 and 2026-06-14, including direct xrefs, tail instructions, vtable/RTTI data, resource/string refs, packet constants, and generated-output route confirmation.
- Boundary correction: B001 2026-06-16 routes `0x0051f450`, `0x0051f510`, and `0x0051f640` through [UID:00000I][ArgumentedMenuMenuItemList](by-class/ArgumentedMenuMenuItemList.md). This file owns the input pane constructors/actions that call or construct from those list-context helpers.
- Historical B008 2026-07-04 limited callback: [UID:0001BT][0x0051fc90-0x00520539.ArgumentedItemInputDialogs](by-memory/0x0051fc90-0x00520539.ArgumentedItemInputDialogs.md) established the four-way split but could not create children under that callback. B010 created and routed all four exact method pages; the old deferral is no longer current.

## Hypothesis

The original client likely kept the argumented item purchase confirmation and quantity dialogs near the argumented merchant menu code. These panes are not general item-action prompts: they are opened from an argumented menu row, validate the displayed price, optionally ask for a quantity, and send fixed opcode `0x39` using the copied argumented menu context.

Likely compact source layout:

```text
NexusTK/ui/dialogs/ArgumentedMenuDialogs.cpp
NexusTK/ui/dialogs/ArgumentedItemInputDialogs.cpp
```

Possible folded layout:

```text
NexusTK/ui/dialogs/ArgumentedMenuDialogs.cpp
```

## Proposed Contents

| Entity | Exact range | Role |
| --- | --- | --- |
| external list-context helper | [UID:0003VI][0x0051f450-0x0051f4fe.ArgumentedMenuOpenBuyConfirmDialog](by-memory/0x0051f450-0x0051f4fe.ArgumentedMenuOpenBuyConfirmDialog.md) | Reads the selected argumented menu entry and allocates `ArgumentedItemConfirmInputDialogPane`; owned by [UID:00000I][ArgumentedMenuMenuItemList](by-class/ArgumentedMenuMenuItemList.md). |
| external list-context helper | [UID:0003VJ][0x0051f510-0x0051f5a5.ArgumentedMenuOpenQuantityDialogOrSendSingle](by-memory/0x0051f510-0x0051f5a5.ArgumentedMenuOpenQuantityDialogOrSendSingle.md) | Sends quantity `1` directly or allocates `ArgumentedItemQuantityInputDialogPane`; owned by [UID:00000I][ArgumentedMenuMenuItemList](by-class/ArgumentedMenuMenuItemList.md). |
| external list-context helper | [UID:0003VL][0x0051f640-0x0051f706.ArgumentedMenuSendItemQuantityPacket](by-memory/0x0051f640-0x0051f706.ArgumentedMenuSendItemQuantityPacket.md) | Serializes the final 14-byte opcode `0x39` argumented item quantity packet from list context; owned by [UID:00000I][ArgumentedMenuMenuItemList](by-class/ArgumentedMenuMenuItemList.md). |
| [UID:000554][0x0051fc90-0x0051ff6c.ArgumentedItemQuantityInputDialogPaneConstructor](by-memory/0x0051fc90-0x0051ff6c.ArgumentedItemQuantityInputDialogPaneConstructor.md) | `[0x0051fc90,0x0051ff6c)` | Builds the `ArgumentQuantity` dialog and copies menu/list context; exact source body emits through UID00000G at position 10. |
| [UID:000555][0x0051ff70-0x005200c4.ArgumentedItemQuantityInputDialogPaneOnControlCommand](by-memory/0x0051ff70-0x005200c4.ArgumentedItemQuantityInputDialogPaneOnControlCommand.md) | `[0x0051ff70,0x005200c4)` | Preserves unsigned validation, both alerts, packet send, and always-close control-1 behavior; emits through UID00000G at position 20. |
| [UID:000557][0x005200d0-0x005203be.ArgumentedItemConfirmInputDialogPaneConstructor](by-memory/0x005200d0-0x005203be.ArgumentedItemConfirmInputDialogPaneConstructor.md) | `[0x005200d0,0x005203be)` | Builds the price-confirm dialog and stores copied context, max quantity, expected price, and argument id; emits through UID00000F at position 10. |
| [UID:000558][0x005203c0-0x00520539.ArgumentedItemConfirmInputDialogPaneOnControlCommand](by-memory/0x005203c0-0x00520539.ArgumentedItemConfirmInputDialogPaneOnControlCommand.md) | `[0x005203c0,0x00520539)` | Preserves mismatch no-close behavior, direct one-item send, quantity-dialog branch, and close ordering; emits through UID00000F at position 20. |

## Live IDA Evidence

2026-06-04 IDA MCP checks confirmed:

- Function boundaries and tails:
  - `0x0051f450-0x0051f4fe`, final `retn` at `0x0051f4fd`; no direct code/data refs to the start.
  - `0x0051f510-0x0051f5a5`, final `retn 8` at `0x0051f5a2`; no direct code/data refs to the start.
  - `0x0051f640-0x0051f706`, final `retn 8` at `0x0051f703`.
  - `0x0051fc90-0x0051ff6c`, final `retn 0Ch` at `0x0051ff69`.
  - `0x0051ff70-0x005200c4`, final `retn 8` at `0x005200c1`.
  - `0x005200d0-0x005203be`, final `retn 14h` at `0x005203bb`.
  - `0x005203c0-0x00520539`, final `retn 8` at `0x00520536`.
- `SendArgumentedItemQuantityPacket` has direct call refs from `0x0051f504`, `0x0051f58d`, `0x0052008e`, and `0x00520501`, covering both helper paths and both dialog action paths.
- The quantity dialog constructor is called from `0x0051f570` and `0x005204ec`; the confirm dialog constructor is called from `0x0051f22a` and `0x0051f4de`.
- Constructor vtable stores anchor the two classes:
  - Quantity stores `??_7ArgumentedItemQuantityInputDialogPane@@6B@` at `0x0051fcec`, plus secondary vtables at `0x0051fcf2` and `0x0051fcfc`.
  - Confirm stores `??_7ArgumentedItemConfirmInputDialogPane@@6B@` at `0x00520147`, plus secondary vtables at `0x0052014d` and `0x00520157`.
- Vtable data refs point to the action handlers: `0x0061f5d0 -> 0x0051ff70` for the quantity handler and `0x0061f66c -> 0x005203c0` for the confirm handler.
- `0x00520046` resolves inside `0x0051ff70-0x005200c4`, not to a separate function start.
- The next function starts at `0x00520540` and belongs to `ObjectImageControlPane`, so the argumented input-dialog memory slice ends before that function.

Behavior evidence from live decompilation/disassembly:

- `0x0051f450` checks the selected row index, fetches the row context, uses the buy/price-confirm prompt string, and calls the confirm-dialog constructor at `0x005200d0`.
- `0x0051f510` branches on quantity `<= 1`: it calls `0x0051f640` with quantity `1`, otherwise allocates class id `628`, reads prompt resource id `246` through `dword_67A750`, and calls `0x0051fc90`.
- `0x0051f640` writes opcode `0x39`, context fields from offsets `+0x14c`, `+0x150`, and `+0x154`, the selected argument id, and the quantity byte, then sends 14 bytes through [UID:0000Q5][g_packetSender](by-global/g_packetSender.md) / historical `dword_67A7EC`.
- `0x0051ff70` parses decimal input, rejects values above `100` with the `You can't buy more than 100.` alert string, rejects zero with the `How much?` alert string, and calls `0x0051f640` for valid nonzero quantities.
- `0x005203c0` parses the typed price, compares it with the expected price stored in the confirm dialog, uses the `Price is different.` alert string on mismatch, and otherwise dispatches to `0x0051f640` or `0x0051fc90`.

## 2026-06-14 C001 IDA MCP Refresh

Current IDA MCP health reports `NexusTK.exe.i64`, image base `0x400000`, auto-analysis ready, Hex-Rays ready, and strings cache ready. The refreshed checks support raising completion above the old floor without changing the file route.

- `lookup_funcs` reconfirms the helper/dialog inventory: `0x0051f450` size `0xae`, `0x0051f510` size `0x95`, `0x0051f640` size `0xc6`, `0x0051fc90` size `0x2dc`, `0x0051ff70` size `0x154`, `0x005200d0` size `0x2ee`, `0x005203c0` size `0x179`, and unrelated successor `0x00520540` size `0x75`.
- `analyze_component` shows the internal purchase-flow edges: `0x0051f450 -> 0x005200d0`, `0x0051f510 -> 0x0051fc90/0x0051f640`, `0x0051ff70 -> 0x0051f640`, and `0x005203c0 -> 0x0051fc90/0x0051f640`.
- Fresh `xrefs_to` reconfirms four packet-send helper refs at `0x0051f504`, `0x0051f58d`, `0x0052008e`, and `0x00520501`; quantity-constructor refs at `0x0051f570` and `0x005204ec`; confirm-constructor refs at `0x0051f22a` and `0x0051f4de`; and no direct xrefs to `0x0051f510`.
- `analyze_function 0x0051f640` decompiles the final packet as opcode `0x39` / decimal `57` (Verified with `int_convert.py`), copies context fields from `this+0x14c`, `this+0x150`, and `this+0x154`, writes a fixed subcommand byte `1`, appends argument id and quantity, and sends decimal `14` / hex `0xe` bytes (Verified with `int_convert.py`) through `0x00574bb0`.
- `analyze_function 0x0051f510` reconfirms the quantity branch: count `<= 1` sends quantity `1` directly, otherwise allocates class id decimal `628` / hex `0x274` and reads prompt id decimal `246` / hex `0xf6` (both Verified with `int_convert.py`) before constructing the quantity dialog.

## 2026-07-04 B008 UID0001BT Limited Callback

Current B008 MCP session `eb7ce28b` keeps this file as the owner/emitter route for UID0001BT while correcting the source shape. `server_health` was OK for `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, and current `lookup_funcs` reports raw IDB names `sub_51FC90`, `sub_51FF70`, `sub_5200D0`, and `sub_5203C0`; the C001 method names remain documentation/source-facing names rather than current live IDB names.

UID0001BT now emits only an aggregate child-route marker through this file. The four source-bearing input-pane method bodies remain planned exact child pages:

- `0x0051fc90-0x0051ff6c` quantity constructor: constructor refs at `0x0051f570` and `0x005204ec`; vtable stores to `0x0061f588`, `0x0061f5e8`, and `0x0061f618`.
- `0x0051ff70-0x005200c4` quantity action: vtable data slot `0x0061f5d0`, quantity limit `0x64` / decimal `100` (Verified with `int_convert.py`), UTF-16LE validation strings `You can't buy more than 100.` and `How much?`, and packet-helper call at `0x0052008e`.
- `0x005200d0-0x005203be` confirm constructor: constructor refs at `0x0051f22a` and `0x0051f4de`; vtable stores to `0x0061f624`, `0x0061f684`, and `0x0061f6b4`.
- `0x005203c0-0x00520539` confirm action: vtable data slot `0x0061f66c`, UTF-16LE `Price is different.`, quantity-dialog dispatch at `0x005204ec`, and packet-helper call at `0x00520501`.

Boundary proof: `0x00520046` resolves inside `sub_51FF70`, not a separate function; `0x00520539` is not a function; successor `0x00520540` is a separate `ObjectImageControlPane`-family function. Current byte checks show `0xcc` padding between the four functions and before the successor.

Do not create one broad function body here. UID0001BT's current role is to assemble exact future children and to remove the previous bare empty marker from generated output. Child page creation was explicitly deferred by the B008 limited callback scope.

## Ownership Notes

- These helpers and panes belong to the argumented merchant/menu purchase flow, not chat-color, generic item-dialog, or frame-chrome code.
- [UID:0003VL][0x0051f640-0x0051f706.ArgumentedMenuSendItemQuantityPacket](by-memory/0x0051f640-0x0051f706.ArgumentedMenuSendItemQuantityPacket.md) consumes the `ArgumentedMenuMenuItemList` context layout: command type at `+0x14c`, owner id at `+0x150`, list parameter at `+0x154`, and owner dialog pointer at `+0x158`.
- Quantity/confirm input dialog constructors call [UID:0003VF][0x0051f290-0x0051f30b.ArgumentedMenuMenuItemListCopyConstructor](by-memory/0x0051f290-0x0051f30b.ArgumentedMenuMenuItemListCopyConstructor.md), and their action handlers call [UID:0003VL][0x0051f640-0x0051f706.ArgumentedMenuSendItemQuantityPacket](by-memory/0x0051f640-0x0051f706.ArgumentedMenuSendItemQuantityPacket.md).
- The no-direct-xref status of `0x0051f450` and `0x0051f510` remains the main reachability caveat. Their bodies still match the argumented item purchase flow and are adjacent to the argumented menu/input dialog island.
- The final standalone-vs-folded file decision should be made with the neighboring [UID:0000HI][ArgumentedMenuDialogs](by-file/ArgumentedMenuDialogs.md) and [UID:0000OP][TextMenuDialogs](by-file/TextMenuDialogs.md) pages.

## Migration Notes

Preferred migration, once the broader argumented-menu source split is finalized:

```text
NexusTK/ui/dialogs/ArgumentedItemInputDialogs.cpp
  ArgumentedItemConfirmInputDialogPane
  ArgumentedItemQuantityInputDialogPane
  OpenArgumentedItemConfirmDialog / ShowBuyConfirmDialog
  OpenQuantityDialogOrSendSingle
  SendArgumentedItemQuantityPacket
```

Do not write one broad reconstruction body for UID0001BT. The behavior and boundaries are strong and the emitter route surfaces, but source output should be child-first: UID0001BT supplies the aggregate `[[CHILDREN]]` insertion point, and the future exact method pages should carry any first-draft method C++ only after source-facing names, signatures, member fields, and the standalone-vs-folded source decision are settled. The limited B008 callback did not authorize creating those child pages.

## Score Rationale

| Field | Value | Rationale |
| --- | ---: | --- |
| Completion | 93 | The file now has an exhaustive four-method source inventory, two complete class/header routes, exact layouts, six vtable views, two seven-base RTTI graphs, four owned literals, compiler-artifact dispositions, dependency closure, and ten exact child/type/resource pages. |
| Confidence | 94 | Exact ranges, behavior, packet path, class tables, fields, resources, callers, and standalone code/data boundaries are strongly constrained. The remaining cap is original lexical filename/access/identifier spelling and absent rebuilt-binary comparison, not a source-code blocker. |

## 2026-08-17 B010 Whole-File Source Closure

- Accepted module pair: `NexusTK/ui/dialogs/ArgumentedItemInputDialogs.cpp` and `ArgumentedItemInputDialogs.h`.
- Exact source order: quantity class declaration then confirm class declaration in H; quantity constructor, quantity `OnControlCommand`, confirm constructor, and confirm `OnControlCommand` in CPP. UID0001BT is a no-duplicate index, not a broad method emitter.
- Exact code children: UID000554, UID000555, UID000557, and UID000558. Exact layouts: UID000556 and UID000559. Compiler/data coverage: UID00055A and UID00055C. Literal/resource ownership: UID00055B and UID00055D.
- Runtime fidelity includes pointer-based full control constructors, 239x283 DLGEXC3/PAL01 layout, focus/pending/hover order, copied 0x15c list context, unsigned quantity comparison, zero alert, mismatch no-close path, one-item versus quantity branch, packet widths, close ordering, and the observed no-cleanup lifetime of `m_menuContext`.
- External helper bodies remain in `ArgumentedMenuDialogs.cpp` under UID00000I. Its complete sibling header supplies the copy constructor, selected-entry type, private helpers, packet method, and friend coupling used by this module.
- Five alignment spans and the `ObjectImageControlPane` successor remain excluded. Six vtables, six COL cells, two CHDs/seven-base RTTI graphs, deleting wrappers, and adjustor thunks are compiler-covered and never emitted as raw arrays or handwritten wrappers.
- The four owned wide literals remain in exact method source. Shared DLGEXC3, PAL01, `%d`, `OK`, localization, BackPane, MainUiGraph, and control APIs remain dependencies rather than reowned data.
- Third-party import does not apply: this is first-party reconstructed NexusTK UI source. Wave2/Wave3 material is rejected as stale and was not used as evidence.
- Weak direct-start reachability for `0x0051f450` and `0x0051f510` caps only those private helper spellings. Exact bodies, adjacency, selected-row fields, constructor/send calls, and UID00000I ownership make them source-eligible dependencies rather than blockers to this file.

## Cross-References

- [UID:00000F][ArgumentedItemConfirmInputDialogPane](by-class/ArgumentedItemConfirmInputDialogPane.md)
- [UID:00000G][ArgumentedItemQuantityInputDialogPane](by-class/ArgumentedItemQuantityInputDialogPane.md)
- [UID:0000TY][ArgumentedItemPurchaseHelpers_51f450_51f640](by-item/ArgumentedItemPurchaseHelpers_51f450_51f640.md)
- [UID:0001BT][0x0051fc90-0x00520539.ArgumentedItemInputDialogs](by-memory/0x0051fc90-0x00520539.ArgumentedItemInputDialogs.md)
- [UID:0001BS][0x0051e9a0-0x0051fc8d.ArgumentedMenuDialogs](by-memory/0x0051e9a0-0x0051fc8d.ArgumentedMenuDialogs.md)
- [UID:0000Q5][g_packetSender](by-global/g_packetSender.md)
- [UID:0000OP][TextMenuDialogs](by-file/TextMenuDialogs.md)
- [UID:00000H][ArgumentedMenuMenuDialog](by-class/ArgumentedMenuMenuDialog.md)
- [UID:00000I][ArgumentedMenuMenuItemList](by-class/ArgumentedMenuMenuItemList.md)

## Changes

- 2026-06-07: Replaced the raw `dword_67A7EC` packet-send reference with canonical [UID:0000Q5][g_packetSender](by-global/g_packetSender.md) wording.
  - Before: the argumented item packet helper evidence described the 14-byte send through the historical generated global only.
  - After: the page links the resolved packet sender while retaining the historical label for IDA traceability.
  - Evidence: the generated resolved-name report maps `dword_67A7EC` to `g_packetSender`, and the existing live IDA notes tie the `0x0051f640` helper to the final `0x39` argumented item purchase packet send.

- 2026-06-04: Raised grading from `72/82` to `82/88` and set `PROPOSED_RECONSTRUCTION_PATH` to `NexusTK/ui/dialogs/`.
  - Before: the page relied on stale non-live provenance and older IDA notes, had inclusive endpoint wording for several ranges, and left the proposed path blank.
  - After: the page uses live IDA MCP evidence for exact half-open boundaries, direct refs, vtable stores, handler vtable slots, packet constants, resource/string refs, and false-start handling for `0x00520046`.
  - Score rationale: completion increased because the helper, constructor, action-handler, vtable, and packet-send evidence now reconstructs the module shape with high confidence. It remains below source-quality code-entry level because `0x0051f450`/`0x0051f510` still have no direct start refs and the final standalone-vs-folded source split is unresolved.

- 2026-06-14 C001: Raised grading from `82/88` to `86/89`.
  - Before: the page had strong 2026-06-04 IDA evidence but no current MCP refresh, stale source-entry wording, and no explicit current score table.
  - After: added current IDA MCP health, refreshed function sizes/call edges/xref sets, verified opcode/count conversions with `int_convert.py`, and documented why the active emitter route still does not justify final source code.
  - Evidence: `lookup_funcs`, `analyze_component`, `xrefs_to`, and `analyze_function` reconfirm the argumented item helper/dialog cluster, the opcode `0x39` 14-byte packet helper, quantity-dialog branch, class constructor refs, and successor boundary before `ObjectImageControlPane`.
- 2026-06-16 B001 boundary correction:
  - Changed helper ownership wording without changing score.
  - Evidence: B001 split audit proved `0x0051f450`, `0x0051f510`, and `0x0051f640` are source-bearing [UID:00000I][ArgumentedMenuMenuItemList](by-class/ArgumentedMenuMenuItemList.md) helpers. This file owns only the input pane constructors/actions at `0x0051fc90-0x00520539` that consume those helpers.
- 2026-07-04 B008 UID0001BT limited implementation callback:
  - Score unchanged on this file root.
  - Synchronized UID0001BT from a broad blank-emitter blocker to a reconstructable aggregate child-route marker with current MCP session `eb7ce28b` evidence, exact four-method split plan, current raw IDB name caveat, generated empty-marker correction, and explicit child-page deferral by supervisor scope.
