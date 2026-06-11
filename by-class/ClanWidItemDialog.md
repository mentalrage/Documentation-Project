*** UID:00002N | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:82 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000I9 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# ClanWidItemDialog

## Status

- Confidence: strong for constructor/caller/vtable/packet evidence; medium for final field names and shared slide-helper ownership.
- Likely source file: [UID:0000I9][ClanBank](by-file/ClanBank.md)
- Documented source grouping: [UID:0000I9][ClanBank](by-file/ClanBank.md), with a possible `ClanItemDialogs.cpp` split.

## Class Purpose

`ClanWidItemDialog` is the clan-bank item withdraw dialog. It parses title/detail/list payload text from the packet, creates the `DL_15` dialog with a `ClanItemListPane`, reads selected item plus quantity, and sends the withdraw request packet.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| `ClanWidItemDialog` | `0x0048a810-0x0048ace4` | Builds the dialog, decodes packet text, constructs `ClanItemListPane`, quantity edit, and UI/input attachments. |
| vtable-reset helper | `0x0048acf0-0x0048ad0f` | Standalone IDA-modeled helper; resets class vtables before base cleanup. |
| `OnDialogAction` | `0x0048ad10-0x0048ade8` | On OK, reads selected item and quantity, calls packet sender, then OK/Cancel closes. |
| `SendWithdrawRequestPacket` | `0x0048adf0-0x0048ae64` | Sends opcode `0x4b`, subtype `12`, action `1`, item type, and quantity. |

## Evidence Notes

- 2026-06-05 live IDA MCP confirms real starts at `0x0048a810`, `0x0048acf0`, `0x0048ad10`, and `0x0048adf0`, with sizes `0x4d5`, `0x1f`, `0xd9`, and `0x75`.
- `callers`/`xrefs_to` report constructor code xrefs from [UID:00021C][0x00484f70-0x0048540b.ClanStatusPacketDispatcher](by-memory/0x00484f70-0x0048540b.ClanStatusPacketDispatcher.md) at `0x004853fa` and from [UID:00021S][0x004877d0-0x00488594.ClanStatusPacketDialogHandlers](by-memory/0x004877d0-0x00488594.ClanStatusPacketDialogHandlers.md) opener island `0x00488510` at `0x0048857b`.
- `xrefs_to` reports no direct code callers for `OnDialogAction` or `SendWithdrawRequestPacket`; their anchors are vtable data xrefs `0x00616164 -> 0x0048ad10` and `0x00616178 -> 0x0048adf0`.
- Constructor decompilation stores `ClanWidItemDialog` vtables at `0x0048a86a`, `0x0048a870`, and `0x0048a87a`, decodes packet text with `MultiByteToWideChar`, creates the `DL_15` dialog shell, constructs [UID:00002G][ClanItemListPane](by-class/ClanItemListPane.md) via `0x0048ae70`, wires OK/Cancel controls, attaches through the UI root/global at `0x0069b36c`, and starts the shared slide helper `0x0049ec80`.
- `OnDialogAction` handles button id `1` by retrieving controls `5` and `6`, reading the selected clan item from the list, parsing the amount text, dispatching through virtual slot `+0x5c`, then sharing the close path with button id `2` through `0x0049ed60` and `0x0049dad0`.
- `SendWithdrawRequestPacket` writes bytes `0x4b`, `12`, `1`, the item type byte, a big-endian 16-bit amount, terminates the local packet buffer, then sends six bytes through the packet-sender global at `0x0067a7ec` via `0x00574bb0`.
- The withdraw dialog constructs `ClanItemListPane`, supporting a shared `ClanBank.cpp` or `ClanItemDialogs.cpp` grouping with the deposit dialog.

## Reconstruction Notes

Keep the final C++ block blank until the inherited `ClanItemDialog` fields, control IDs, virtual slot names, and shared slide-helper ownership are named consistently. The current evidence is enough for source-authored class reconstruction and ClanBank parent attachment, but not for the 95/95 final-code gate.

## Score Rationale

| Field | Value | Reason |
| --- | ---: | --- |
| Completion | 82 | Constructor boundaries, constructor callers, vtable-only action/send anchors, packet-string decoding, `ClanItemListPane` construction, button handling, packet byte layout, reconstructability, and ClanBank parent are documented. Remaining work is final field/control naming and shared animation helper placement. |
| Confidence | 86 | Live IDA callers/callees/xrefs/decompilation agree with the memory page and ClanBank ownership. Confidence remains below final because the action/send methods are vtable-only and the exact original signatures and field names are unrecovered. |

## Cross-References

- [UID:0000I9][ClanBank](by-file/ClanBank.md)
- [UID:00010P][0x0048a810-0x0048ae65.ClanWidItemDialog](by-memory/0x0048a810-0x0048ae65.ClanWidItemDialog.md)
- [UID:00002F][ClanItemDialog](by-class/ClanItemDialog.md)
- [UID:00002G][ClanItemListPane](by-class/ClanItemListPane.md)
- [UID:00021C][0x00484f70-0x0048540b.ClanStatusPacketDispatcher](by-memory/0x00484f70-0x0048540b.ClanStatusPacketDispatcher.md)
- [UID:00021S][0x004877d0-0x00488594.ClanStatusPacketDialogHandlers](by-memory/0x004877d0-0x00488594.ClanStatusPacketDialogHandlers.md)
- [UID:00012V][0x0049ec80-0x0049ee41.ClanDialogSlideAnimation](by-memory/0x0049ec80-0x0049ee41.ClanDialogSlideAnimation.md)

## Changes

- What existed before: the page documented confirmed withdraw-item dialog methods and dependencies, but metadata was still `0/0`.
- What it was changed to: scores were set to `74/84`.
- Summary and evidence: constructor, vtable reset, dialog action, packet sender, and `ClanItemListPane` dependency are covered; detailed widget field layout and final module split remain incomplete.
- 2026-06-05: First marked reconstructable but left `AUTOGEN_PARENT_UID` blank at `74/84` because it was below the 80/80 parent-attachment gate. A later live IDA refresh raised the page to `82/86` and attached parent [UID:0000I9][ClanBank](by-file/ClanBank.md).
  - Before: the class page had confirmed method starts and basic dependency notes, but lacked exact function sizes, vtable-only action/send anchors, detailed constructor behavior, packet byte layout, and a score rationale.
  - After: the page records constructor callers from the dispatcher and retained opener, vtable stores/data xrefs, packet text decoding, `DL_15` setup, `ClanItemListPane` construction, OK/Cancel handling, withdraw packet bytes, and final-code caveats.
  - Summary/evidence: IDA MCP `lookup_funcs`, `callers`, `callees`, `xrefs_to`, and `decompile` on `0x0048a810`, `0x0048acf0`, `0x0048ad10`, and `0x0048adf0`.
- 2026-06-05: Removed stale recovered-file, generated-helper, and global-label wording; score remains `82/86`.
