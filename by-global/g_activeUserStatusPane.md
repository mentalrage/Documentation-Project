*** UID:0000PS | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000P2 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# g_activeUserStatusPane

## Status

- Confidence: strong for `UserStatusPane` singleton role, medium for final canonical name.
- Address: `0x0069ae0c`
- IDA name: `dword_69AE0C`
- Current source-facing name: `g_activeUserStatusPane`
- Memory doc: [UID:0001PE][0x0069ae0c-0x0069ae10.g_activeUserStatusPane](by-memory/0x0069ae0c-0x0069ae10.g_activeUserStatusPane.md)
- Proposed owner file: [UID:0000P2][UserStatusPane](by-file/UserStatusPane.md)
- Related class: [UID:0000FS][UserStatusPane](by-class/UserStatusPane.md)

## Role

`g_activeUserStatusPane` stores the active newer `UserStatusPane` instance. The constructor writes the singleton, cleanup and scalar deleting destructor paths clear it, and many UI paths read it to access or invalidate the local status pane.

Several inventory/user-pane paths also read fields through this same pointer. For example, [UID:0000LO][MyItemListPane](by-file/MyItemListPane.md) reads the inventory slot count from `dword_69AE0C + 0x284` before enumerating item slots through the local-player slot-address helper. Treat aliases that assign this storage to `g_pEffectObjImageLib` or raw `DAT_0069ae0c` as pollution.

[UID:00001J][ChangeItemSlotInputPane](by-class/ChangeItemSlotInputPane.md) also reads byte offset `+0x284` from this singleton while validating typed item-slot letters. Some analysis aliases may call the receiver `g_pLocalPlayer`, but IDA address evidence still points to this `dword_69AE0C` storage.

This global is intentionally high fan-out. A 2026-05-27 IDA MCP xref pass counted 67 direct xrefs across 44 containing-function buckets. That fan-out comes from UI/status panes, item/inventory commands, local-player helpers, and singleton lifecycle paths sharing the active status-pane object rather than from multiple separate globals.

## Evidence Notes

- `UserStatusPane::UserStatusPane` writes the global at `0x005b83fa` and `0x005b8401`.
- The cleanup body clears it at `0x005b858e`.
- The singleton clear helper at `0x005bfc00` writes zero to `0x0069ae0c`.
- The scalar deleting destructor clears it at `0x005bff85`.
- IDA reports many broader UI xrefs, so the current name should remain provisional until final global naming review.
- 2026-05-27 xref audit: IDA MCP reports 67 direct xrefs to `dword_69AE0C`, grouped across 44 containing-function buckets. The direct writes are still limited to `UserStatusPane` construction/cleanup/destructor paths.
- 2026-05-26 recheck: IDA MCP reports `0x0069ae0c` as `dword_69AE0C`, size `4`, in `.data`. `MyItemListPane::MyItemListPane` reads byte offset `+0x284` from the pointee at `0x004aebe0`.
- 2026-05-27 recheck: IDA decompilation of `ChangeItemSlotInputPane::OnSubmitInput` reads the same byte offset `+0x284` from `dword_69AE0C` at `0x005b3125` before accepting source/destination item slots.
- 2026-05-27 recheck: IDA decompilation of `WieldInputPane::OnSubmitInput` and `WearInputPane::OnSubmitInput` reads the same byte offset `+0x284` at `0x005b64dc` and `0x005b670d` before accepting typed item-slot letters.
- 2026-05-27 recheck: IDA decompilation of `ThrowInputPane::OnSubmitInput`, `UseInputPane::OnSubmitInput`, and `EatInputPane::OnConfirmInput` reads byte offset `+0x284` at `0x005b5a3d`, `0x005b5e4a`, and `0x005b606d` before accepting typed item-slot letters.
- 2026-06-05 IDA MCP recheck confirmed 67 direct xrefs to `0x0069ae0c`, including the documented lifecycle and inventory/status consumers.

## Cross-References

- [UID:0000P2][UserStatusPane](by-file/UserStatusPane.md)
- [UID:0000FS][UserStatusPane](by-class/UserStatusPane.md)
- [UID:0001PE][0x0069ae0c-0x0069ae10.g_activeUserStatusPane](by-memory/0x0069ae0c-0x0069ae10.g_activeUserStatusPane.md)
- [UID:0001NM][0x005b83b0-0x005baafe.UserStatusPane](by-memory/0x005b83b0-0x005baafe.UserStatusPane.md)
- [UID:0001NS][0x005bfbd0-0x005c0034.UiPaneDestructorThunksAndVectorHelper](by-memory/0x005bfbd0-0x005c0034.UiPaneDestructorThunksAndVectorHelper.md)
- [UID:00001J][ChangeItemSlotInputPane](by-class/ChangeItemSlotInputPane.md)
- [UID:0000EY][ThrowInputPane](by-class/ThrowInputPane.md)
- [UID:0000FG][UseInputPane](by-class/UseInputPane.md)
- [UID:000047][EatInputPane](by-class/EatInputPane.md)
- [UID:0000G4][WieldInputPane](by-class/WieldInputPane.md)
- [UID:0000G0][WearInputPane](by-class/WearInputPane.md)

## Changes

- Completion/confidence scoring: existed before as ungraded `0/0`; changed to `90/84`. Summary/evidence: the page documents the singleton address, lifecycle writes/clears, high xref count, representative inventory/status consumers, alias pollution warnings, and class/memory refs; final canonical global name remains open.
- 2026-06-05: Marked reconstructable and attached to [UID:0000P2][UserStatusPane](by-file/UserStatusPane.md).
  - Reason: live IDA MCP recheck confirms this source-declared singleton is written/cleared by `UserStatusPane` lifecycle code and read by status/inventory consumers.
