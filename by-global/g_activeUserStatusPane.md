*** UID:0000PS | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000P2 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000P2 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
UserStatusPane *g_activeUserStatusPane = NULL;
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# g_activeUserStatusPane

## UID0000LO MyItemListPane Consumer Link - 2026-08-14

[UID:0002JO][0x004aeb30-0x004aec77.MyItemListPaneConstructor](by-memory/0x004aeb30-0x004aec77.MyItemListPaneConstructor.md)
reads `g_activeUserStatusPane->m_inventorySlotCount` to bound its signed
one-based inventory-slot loop. The global remains externally owned with no
score, emitter, declaration, or storage change from this consumer link.

## Status

- Current state: `92/94`; exact `UserStatusPane *` singleton, zero initializer, UserStatusPane.cpp owner, constructor publication, ordinary-destructor clear, and high-fanout consumer semantics are complete.
- Address: `0x0069ae0c`
- IDA name: `g_activeUserStatusPane` (renamed from `unk_69AE0C` by C001 on 2026-06-16 after live xref/lifecycle review)
- Current source-facing name: `g_activeUserStatusPane`
- Memory doc: [UID:0001PE][0x0069ae0c-0x0069ae10.g_activeUserStatusPane](by-memory/0x0069ae0c-0x0069ae10.g_activeUserStatusPane.md)
- Proposed owner file: [UID:0000P2][UserStatusPane](by-file/UserStatusPane.md)
- Related class: [UID:0000FS][UserStatusPane](by-class/UserStatusPane.md)

## Role

`g_activeUserStatusPane` stores the active newer `UserStatusPane` instance. The constructor publishes `this`; the ordinary source destructor unconditionally clears it after freeing the numeric glyph buffer. Scalar-deleting and adjusted destructor paths reach that source destructor through compiler wrappers rather than owning independent source clears.

Several inventory/user-pane paths also read fields through this same pointer. For example, [UID:0000LO][MyItemListPane](by-file/MyItemListPane.md) reads the inventory slot count from `dword_69AE0C + 0x284` before enumerating item slots through the local-player slot-address helper. B006 reconstructs this byte as source-facing `m_inventorySlotCount` for [UID:0001M6][0x005b3010-0x005b3196.ChangeItemSlotInputPane](by-memory/0x005b3010-0x005b3196.ChangeItemSlotInputPane.md); the spelling is inferred, while the offset and inventory-slot-count role are IDA-backed. Treat aliases that assign this storage to `g_pEffectObjImageLib` or raw `DAT_0069ae0c` as pollution.

[UID:00001J][ChangeItemSlotInputPane](by-class/ChangeItemSlotInputPane.md) also reads byte offset `+0x284` from this singleton while validating typed item-slot letters. Some analysis aliases may call the receiver `g_pLocalPlayer`, but IDA address evidence still points to this `dword_69AE0C` storage.

This global is intentionally high fan-out. A 2026-05-27 IDA MCP xref pass counted 67 direct xrefs across 44 containing-function buckets. That fan-out comes from UI/status panes, item/inventory commands, local-player helpers, and singleton lifecycle paths sharing the active status-pane object rather than from multiple separate globals.

## Evidence Notes

- `UserStatusPane::UserStatusPane` writes the global at `0x005b83fa` and `0x005b8401`.
- The ordinary [UID:0003A9][0x005b8530-0x005b85ad.UserStatusPaneDestructor](by-memory/0x005b8530-0x005b85ad.UserStatusPaneDestructor.md) clears it at `0x005b858e`.
- The singleton clear helper at `0x005bfc00` writes zero to `0x0069ae0c`.
- The scalar deleting destructor clears it at `0x005bff85`.
- The saved/source-facing name is final for reconstruction. Historical `g_pEffectObjImageLib`, `g_pLocalPlayer`, `DAT_0069ae0c`, and raw aliases identify consumer confusion and are not alternate owners or current names.
- 2026-05-27 xref audit: IDA MCP reports 67 direct xrefs to `dword_69AE0C`, grouped across 44 containing-function buckets. The direct writes are still limited to `UserStatusPane` construction/cleanup/destructor paths.
- 2026-05-26 recheck: IDA MCP reports `0x0069ae0c` as `dword_69AE0C`, size `4`, in `.data`. `MyItemListPane::MyItemListPane` reads byte offset `+0x284` from the pointee at `0x004aebe0`.
- 2026-05-27 recheck: IDA decompilation of `ChangeItemSlotInputPane::OnSubmitInput` reads the same byte offset `+0x284` from `dword_69AE0C` at `0x005b3125` before accepting source/destination item slots.
- 2026-06-26 B006 recheck: [UID:0001M6][0x005b3010-0x005b3196.ChangeItemSlotInputPane](by-memory/0x005b3010-0x005b3196.ChangeItemSlotInputPane.md) now uses reconstructed source-facing field name `m_inventorySlotCount` for the `+0x284` byte when validating typed item-slot letters; the exact field spelling remains inferred, but the role and offset are confirmed by this page's existing item-list and item-action consumers.
- 2026-05-27 recheck: IDA decompilation of `WieldInputPane::OnSubmitInput` and `WearInputPane::OnSubmitInput` reads the same byte offset `+0x284` at `0x005b64dc` and `0x005b670d` before accepting typed item-slot letters.
- 2026-05-27 recheck: IDA decompilation of `ThrowInputPane::OnSubmitInput`, `UseInputPane::OnSubmitInput`, and `EatInputPane::OnConfirmInput` reads byte offset `+0x284` at `0x005b5a3d`, `0x005b5e4a`, and `0x005b606d` before accepting typed item-slot letters.
- 2026-06-05 IDA MCP recheck confirmed 67 direct xrefs to `0x0069ae0c`, including the documented lifecycle and inventory/status consumers.
- 2026-06-30 B009 MCP recheck reconfirmed current bytes `00 00 00 00` at `0x0069ae0c` and the same high-fanout singleton role. This supports emitting the source declaration as a zero-initialized pointer while keeping aliases such as `g_pEffectObjImageLib`, `g_pLocalPlayer`, and `DAT_0069ae0c` as generated pollution.

## 2026-06-16 C001 IDA Refresh

Live IDA MCP session `b001_mappane_0001AW_20260616` reconfirmed the singleton and closed the IDA-name blocker:

- `entity_query` now reports `g_activeUserStatusPane` at `0x0069ae0c`, between `g_pItemHelpPane` at `0x0069ae04` and `KeyState` at `0x0069ae18`; raw bytes over `0x0069ae00-0x0069ae18` remain zero-filled.
- Saved function labels now identify the lifecycle writers/clearers as `UserStatusPane_Constructor` at `0x005b83b0`, `UserStatusPane_CleanupBody` at `0x005b8530`, `ClearActiveUserStatusPane` at `0x005bfc00`, and `UserStatusPane_ScalarDeletingDestructor` at `0x005bff20`.
- `xrefs_to 0x0069ae0c` still returns exactly 67 direct data xrefs, including the five lifecycle writes/clears and the representative inventory/status consumers already documented on the storage page.
- Decompilation of `MyItemListPane_Constructor`, `ChangeItemSlotInputPane`, `WieldInputPane`, and `WearInputPane` still reads `+0x284` as the item-slot upper bound. This supports keeping inventory/status aliases as consumers of this singleton, not alternate global owners.
- B009 source-emission update: the global now emits `UserStatusPane *g_activeUserStatusPane = NULL;`. The exact linkage/static spelling remains a source-quality inference, but the source-file owner, current-zero storage, and singleton role are strong enough for first-draft output.

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

- 2026-07-20 B001 UID0001NM callback: raised to `92/94`; synchronized the exact pointer type, zero initialization, constructor publication, ordinary-destructor clear, compiler-wrapper reachability, 67-xref consumer role, `m_inventorySlotCount` field access, and historicalized every generated alias without changing the existing formal definition.
- 2026-06-30 B009 implementation callback:
  - Added formal zero-initialized global C++.
  - Summary/evidence: current MCP bytes are `00 00 00 00`, `xrefs_to` reports 67 direct data xrefs, and lifecycle writers/clearers remain confined to the `UserStatusPane` family. Alias pollution remains documented as consumer misuse, not ownership.
- Completion/confidence scoring: existed before as ungraded `0/0`; changed to `90/84`. Summary/evidence: the page documents the singleton address, lifecycle writes/clears, high xref count, representative inventory/status consumers, alias pollution warnings, and class/memory refs; final canonical global name remains open.
- 2026-06-05: Marked reconstructable and attached to [UID:0000P2][UserStatusPane](by-file/UserStatusPane.md).
  - Reason: live IDA MCP recheck confirms this source-declared singleton is written/cleared by `UserStatusPane` lifecycle code and read by status/inventory consumers.
- 2026-06-16 C001 global/IDA refresh:
  - Changed from `90/84` to `91/88`.
  - Summary/evidence: live IDA reconfirmed zeroed storage, neighboring singleton boundaries, the 67-xref set, lifecycle and representative inventory/status consumers, saved `unk_69AE0C -> g_activeUserStatusPane`, and saved four lifecycle function labels. At that time final C++ remained blank because declaration/linkage style still needed source-quality cleanup; B009 later superseded this with a zero-initialized global definition.
- 2026-06-26 B006 ChangeItemSlotInputPane support sync:
  - Score unchanged at `91/88`.
  - Added reconstructed field-name note that offset `+0x284` is used as `m_inventorySlotCount` in [UID:0001M6][0x005b3010-0x005b3196.ChangeItemSlotInputPane](by-memory/0x005b3010-0x005b3196.ChangeItemSlotInputPane.md) for item-slot validation. The name is source-facing inference; the offset and inventory-slot-count role remain IDA-backed.
