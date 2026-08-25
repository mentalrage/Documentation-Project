*** UID:00002N | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:89 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000I9 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# ClanWidItemDialog

## Status

- Confidence: strong for constructor/caller/vtable/packet evidence; medium for final field names and shared slide-helper ownership.
- Likely source file: [UID:0000I9][ClanBank](by-file/ClanBank.md)
- Documented source grouping: [UID:0000I9][ClanBank](by-file/ClanBank.md), with a possible `ClanItemDialogs.cpp` split.
- Emission status: non-emitting class index. This page preserves class-level ownership and inventory notes, while [UID:00010P][0x0048a810-0x0048ae65.ClanWidItemDialog](by-memory/0x0048a810-0x0048ae65.ClanWidItemDialog.md) emits the constructor, action handler, and withdraw packet sender method bodies through [UID:0000I9][ClanBank](by-file/ClanBank.md). Keep `EMITTER_UIDS:` blank here unless a future class declaration or `[[CHILDREN]]` container is deliberately authored.

## Class Purpose

`ClanWidItemDialog` is the clan-bank item withdraw dialog. It parses title/detail/list payload text from the packet, creates the `DL_15` dialog with a `ClanItemListPane`, reads selected item plus quantity, and sends the withdraw request packet.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| `ClanWidItemDialog` | `0x0048a810-0x0048ace5` | Builds the dialog, decodes packet text, constructs `ClanItemListPane`, quantity edit, and UI/input attachments. |
| vtable-reset helper | `0x0048acf0-0x0048ad0f` | Generated class teardown support; resets class vtables before shared base cleanup and should not be emitted as a handwritten method. |
| `OnDialogAction` | `0x0048ad10-0x0048ade9` | On OK, reads selected item and quantity, calls packet sender, then OK/Cancel closes. |
| `SendWithdrawRequestPacket` | `0x0048adf0-0x0048ae65` | Sends opcode `0x4b`, subtype `12`, action `1`, selected clan-bank `slotIndex`, and quantity. |

## Evidence Notes

- 2026-06-05 live IDA MCP confirms real starts at `0x0048a810`, `0x0048acf0`, `0x0048ad10`, and `0x0048adf0`, with sizes `0x4d5`, `0x1f`, `0xd9`, and `0x75`.
- `callers`/`xrefs_to` report constructor code xrefs from [UID:00021C][0x00484f70-0x0048540b.ClanStatusPacketDispatcher](by-memory/0x00484f70-0x0048540b.ClanStatusPacketDispatcher.md) at `0x004853fa` and from [UID:00021S][0x004877d0-0x00488594.ClanStatusPacketDialogHandlers](by-memory/0x004877d0-0x00488594.ClanStatusPacketDialogHandlers.md) opener island `0x00488510` at `0x0048857b`.
- `xrefs_to` reports no direct code callers for `OnDialogAction` or `SendWithdrawRequestPacket`; their anchors are vtable data xrefs `0x00616164 -> 0x0048ad10` and `0x00616178 -> 0x0048adf0`.
- Constructor decompilation stores `ClanWidItemDialog` vtables at `0x0048a86a`, `0x0048a870`, and `0x0048a87a`, decodes packet text with `MultiByteToWideChar`, creates the `DL_15` dialog shell, constructs [UID:00002G][ClanItemListPane](by-class/ClanItemListPane.md) via `0x0048ae70`, wires OK/Cancel controls, attaches through the UI root/global at `0x0069b36c`, and starts the shared slide helper `0x0049ec80`.
- `OnDialogAction` handles button id `1` by retrieving controls `5` and `6`, reading the selected clan item from the list, parsing the amount text, dispatching through virtual slot `+0x5c`, then sharing the close path with button id `2` through `0x0049ed60` and `0x0049dad0`.
- `SendWithdrawRequestPacket` writes bytes `0x4b`, `12`, `1`, the selected clan-bank slot byte, a big-endian 16-bit amount, terminates the local packet buffer, then sends six bytes through the packet-sender global at `0x0067a7ec` via `0x00574bb0`.
- The withdraw dialog constructs `ClanItemListPane`, supporting a shared `ClanBank.cpp` or `ClanItemDialogs.cpp` grouping with the deposit dialog.
- 2026-06-16 B001 [UID:00010Q][0x0048ae70-0x0048b1b1.ClanItemListPane](by-memory/0x0048ae70-0x0048b1b1.ClanItemListPane.md) relationship recheck: `ClanWidItemDialog` constructs `ClanItemListPane` at `0x0048ab68`, and its OK/action path reads the selected row through the generic ListPane selected-entry thunk before sending withdraw slot/quantity data. This confirms `ClanItemListPane` as the withdraw-side bank item picker and keeps the pane in the ClanBank/item-dialog source cluster.
- 2026-06-15 live IDA MCP recheck on session `a003_objectlist_dispatch_20260615` reconfirms modeled function anchors `sub_48A810` size `0x4d5`, `sub_48ACF0` size `0x1f`, `sub_48AD10` size `0xd9`, and `sub_48ADF0` size `0x75`.
- The same recheck confirms constructor xrefs from `0x004853fa` and `0x0048857b`; `OnDialogAction` and `SendWithdrawRequestPacket` remain vtable-only with data xrefs `0x00616164 -> 0x0048ad10` and `0x00616178 -> 0x0048adf0`.
- `analyze_component` over the four anchors reports the constructor as the class interface function, 23 constructor callees, 7 action callees, 4 packet-sender callees, and no internal call-graph edge between the modeled methods. `make_signature_for_range(0x0048a810,0x0048ae65)` returns a unique wildcarded range signature for the whole documented class span.
- 2026-06-28 B008 accepted implementation pass on MCP session `supervisor_20260628_resume` reconfirmed the four function ranges: constructor `0x0048a810-0x0048ace5`, generated vtable-reset/destructor support `0x0048acf0-0x0048ad0f`, action handler `0x0048ad10-0x0048ade9`, and sender `0x0048adf0-0x0048ae65`; `0x0048ae65-0x0048ae70` remains padding before [UID:00010Q][0x0048ae70-0x0048b1b1.ClanItemListPane](by-memory/0x0048ae70-0x0048b1b1.ClanItemListPane.md).
- The same pass resolved the old empty-emitter source-quality blocker for the active method bodies: [UID:00010P][0x0048a810-0x0048ae65.ClanWidItemDialog](by-memory/0x0048a810-0x0048ae65.ClanWidItemDialog.md) now emits formal C++ for the constructor, `OnDialogAction`, and `SendWithdrawRequestPacket`.
- The selected-row byte sent by `SendWithdrawRequestPacket` is now documented as `slotIndex`, not `itemType`: the action path reads byte zero from the selected [UID:00002G][ClanItemListPane](by-class/ClanItemListPane.md) row, and the child list-pane page identifies that byte as the clan-bank slot index.
- The horizontal slide open/close operations remain dependencies on the shared [UID:00012U][0x0049eac0-0x0049f081.DialogPaneSlideAnimation](by-memory/0x0049eac0-0x0049f081.DialogPaneSlideAnimation.md) helpers. This class does not own the slide implementation.
- The vtable-reset helper at `0x0048acf0` is generated class teardown support: it stores inherited vtables and tail-jumps to shared base cleanup. It should be accounted for by ordinary class hierarchy teardown, not emitted here or as a separate handwritten source method.

## Reconstruction Notes

This page is intentionally a non-emitting class index after the 2026-06-28 accepted implementation pass. The exact method bodies now emit from [UID:00010P][0x0048a810-0x0048ae65.ClanWidItemDialog](by-memory/0x0048a810-0x0048ae65.ClanWidItemDialog.md), while this class page preserves class-level purpose, method inventory, evidence notes, and source placement. Leaving `EMITTER_UIDS:0000I9` here with blank C++ would recreate the empty-emitter marker; keep the emitter blank unless a future pass adds a real class declaration or `[[CHILDREN]]` container.

## Score Rationale

| Field | Value | Reason |
| --- | ---: | --- |
| Completion | 86 | Constructor boundaries, constructor callers, vtable-only action/send anchors, packet-string decoding, `ClanItemListPane` construction, button handling, packet byte layout, component summary, unique range signature, reconstructability, and ClanBank ownership/source route are documented. This class page is now intentionally non-emitting while [UID:00010P][0x0048a810-0x0048ae65.ClanWidItemDialog](by-memory/0x0048a810-0x0048ae65.ClanWidItemDialog.md) emits the method bodies. Remaining work is final class declaration/field-layout polish. |
| Confidence | 89 | Live IDA callers/callees/xrefs/component evidence agree with the memory page and ClanBank ownership. Confidence remains below final because the action/send methods are vtable-only and the exact original signatures and field names are unrecovered. |

## Cross-References

- [UID:0000I9][ClanBank](by-file/ClanBank.md)
- [UID:00010P][0x0048a810-0x0048ae65.ClanWidItemDialog](by-memory/0x0048a810-0x0048ae65.ClanWidItemDialog.md)
- [UID:00002F][ClanItemDialog](by-class/ClanItemDialog.md)
- [UID:00002G][ClanItemListPane](by-class/ClanItemListPane.md)
- [UID:00021C][0x00484f70-0x0048540b.ClanStatusPacketDispatcher](by-memory/0x00484f70-0x0048540b.ClanStatusPacketDispatcher.md)
- [UID:00021S][0x004877d0-0x00488594.ClanStatusPacketDialogHandlers](by-memory/0x004877d0-0x00488594.ClanStatusPacketDialogHandlers.md)
- [UID:00012U][0x0049eac0-0x0049f081.DialogPaneSlideAnimation](by-memory/0x0049eac0-0x0049f081.DialogPaneSlideAnimation.md)
- [UID:00012V][0x0049ec80-0x0049ee42.ClanDialogSlideAnimation](by-memory/0x0049ec80-0x0049ee42.ClanDialogSlideAnimation.md)

## Changes

- What existed before: the page documented confirmed withdraw-item dialog methods and dependencies, but metadata was still `0/0`.
- What it was changed to: scores were set to `74/84`.
- Summary and evidence: constructor, vtable reset, dialog action, packet sender, and `ClanItemListPane` dependency are covered; detailed widget field layout and final module split remain incomplete.
- 2026-06-05: First marked reconstructable but left `AUTOGEN_PARENT_UID` blank at `74/84` because it was below the 80/80 parent-attachment gate. A later live IDA refresh raised the page to `82/86` and attached parent [UID:0000I9][ClanBank](by-file/ClanBank.md).
  - Before: the class page had confirmed method starts and basic dependency notes, but lacked exact function sizes, vtable-only action/send anchors, detailed constructor behavior, packet byte layout, and a score rationale.
  - After: the page records constructor callers from the dispatcher and retained opener, vtable stores/data xrefs, packet text decoding, `DL_15` setup, `ClanItemListPane` construction, OK/Cancel handling, withdraw packet bytes, and final-code caveats.
  - Summary/evidence: IDA MCP `lookup_funcs`, `callers`, `callees`, `xrefs_to`, and `decompile` on `0x0048a810`, `0x0048acf0`, `0x0048ad10`, and `0x0048adf0`.
- 2026-06-05: Removed stale recovered-file, generated-helper, and global-label wording; score remains `82/86`.
- 2026-06-15 A002 Goal 2 by-class refresh: raised from `82/86` to `86/89` with no owner/emitter changes. Live IDA reconfirmed all four modeled method sizes, constructor callers, vtable-only action/send anchors, packet/action component shape, and unique documented-range signature. C++ remains blank because control/member names, inherited dialog field layout, and shared slide-helper ownership are still not source-quality.
- 2026-06-16 B001 [UID:00010Q][0x0048ae70-0x0048b1b1.ClanItemListPane](by-memory/0x0048ae70-0x0048b1b1.ClanItemListPane.md) relationship note: added evidence that this class is the active constructor/consumer for `ClanItemListPane`; no score or route change.
- 2026-06-28 B008 accepted implementation: cleared `EMITTER_UIDS:` to make this page a non-emitting class index while preserving `CANONICAL_OWNER:0000I9` and `RECONSTRUCTABLE:TRUE`. [UID:00010P][0x0048a810-0x0048ae65.ClanWidItemDialog](by-memory/0x0048a810-0x0048ae65.ClanWidItemDialog.md) now emits the method bodies, so this support page no longer produces a blank class-level empty-emitter marker.
