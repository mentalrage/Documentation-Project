*** UID:0000RV | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000P2 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000P2 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
OldUserStatusPane *g_pOldUserStatusPane = NULL;
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# g_pOldUserStatusPane

## Status

- Confidence: strong for address, lifetime, parent ownership, and known consumers; medium-high for final source declaration details.
- Address: `0x0069b4ec`
- Storage: `0x4` / 4-byte `.data` singleton slot. Current B009 MCP bytes are `00 00 00 00`; older `0xffffffff` notes are historical and superseded for current source reconstruction.
- Proposed owner file: [UID:0000P2][UserStatusPane](by-file/UserStatusPane.md)
- Related class: [UID:00009U][OldUserStatusPane](by-class/OldUserStatusPane.md)
- Exact storage child: [UID:0002WG][0x0069b4ec-0x0069b4f0.g_pOldUserStatusPane](by-memory/0x0069b4ec-0x0069b4f0.g_pOldUserStatusPane.md)

## Score Rationale

- Completion `86`: this page now ties the exact storage child, owner file, related class, constructor publish/fallback refs, cleanup clears, map-exit teardown, TotemFrame, UserListDialogPane, and LivingObjectPane consumers together with the neighboring split-index context. It remains below final-source scoring because original declaration spelling/linkage and final semantic names for all call sites are not audited to source-emission quality.
- Confidence `90`: strong for address, one-dword storage, xref family, lifetime, and [UID:0000P2][UserStatusPane](by-file/UserStatusPane.md) ownership. It remains below `95` because final C++ is intentionally blank and the declaration form is still reconstructed from binary/documentation evidence.

## Role

`g_pOldUserStatusPane` stores the active legacy status pane instance for the older UI layout. It is published by `OldUserStatusPane` construction, cleared by the normal cleanup/destructor paths, removed during map-exit UI teardown, and read by legacy status consumers such as [UID:0000F4][TotemFrame](by-class/TotemFrame.md), [UID:0000OZ][UserListDialogPane](by-file/UserListDialogPane.md), and [UID:0000KU][LivingObjectPane](by-file/LivingObjectPane.md).

## Evidence Notes

- Live IDA MCP `xrefs_to 0x0069b4ec` on 2026-06-06 reports nine data xrefs: two constructor writes, one cleanup clear, one singleton-clear helper, one scalar-deleting-destructor clear, and four consumers.
- Historical note: earlier `get_bytes 0x0069b4ec size 4` output was recorded as `0xff 0xff 0xff 0xff`. B009 supersedes that stale initializer evidence with current MCP bytes `00 00 00 00`.
- [UID:0002WG][0x0069b4ec-0x0069b4f0.g_pOldUserStatusPane](by-memory/0x0069b4ec-0x0069b4f0.g_pOldUserStatusPane.md) records the exact `0x4` / 4-byte storage child (Verified with int_convert.py), predecessor/successor boundaries, and the Batch044 split out of the mixed singleton cluster.
- `OldUserStatusPane::OldUserStatusPane` writes either the constructed instance or a null fallback at `0x005bda8a` and `0x005bda91`, after pane-base construction and before installing `OldUserStatusPane` vtables.
- The non-deleting cleanup body clears the slot at `0x005bdbce`, the compact singleton-clear helper clears it at `0x005bfbe0`, and the scalar deleting destructor clears it at `0x005bfe05`.
- [UID:0002QH][0x005047f0-0x00504b6b.MapPaneExitToMenuTeardown](by-memory/0x005047f0-0x00504b6b.MapPaneExitToMenuTeardown.md) reads the slot at `0x0050490b`, tests it, and removes the old status pane through the common pane detach helper before continuing compact/new status and chat-pane teardown.
- `TotemFrame::OnPaint` reads the slot at `0x00598dec`, calls `OldUserStatusPane::GetSpiritId` at `0x005bdc60`, and uses the result to choose the `TOTFRAME.EPD` frame.
- `UserListDialogPane::UserListDialogPane` reads the slot at `0x0059c997`, calls the `OldUserStatusPane` nation accessor at `0x005bdc30`, and uses the legacy nation value while constructing the initial user-list controls.
- `LivingObjectPane::HandleServerEntryPacket` reads the slot at `0x005aaed2` before calling `OldUserStatusPane::SetStatusIconId` in the packet/status icon update path.

## 2026-05-30 Review Notes

- IDA MCP on 2026-05-30 confirmed the exact `0x0069b4ec` storage, size `4`, `.data` placement, and nine data xrefs.
- The 2026-05-30 consumer audit confirmed the TotemFrame and LivingObjectPane consumers; the 2026-06-06 follow-up resolves the previously open MapPane exit-teardown and UserListDialogPane constructor consumers.
- Live IDA decompilation on 2026-06-05 confirmed the constructor publish/fallback behavior and cleanup/destructor clearing paths.
- Known consumer coverage now accounts for every live direct xref to the singleton slot. Completion remains below final reconstruction level because this page documents storage ownership and usage, not a final audited C++ global declaration.

## Cross-References

- [UID:0000P2][UserStatusPane](by-file/UserStatusPane.md)
- [UID:00009U][OldUserStatusPane](by-class/OldUserStatusPane.md)
- [UID:0001NR][0x005bda40-0x005bfbc1.OldUserStatusPane](by-memory/0x005bda40-0x005bfbc1.OldUserStatusPane.md)
- [UID:0002QH][0x005047f0-0x00504b6b.MapPaneExitToMenuTeardown](by-memory/0x005047f0-0x00504b6b.MapPaneExitToMenuTeardown.md)
- [UID:0001KI][0x0059bc90-0x0059f25b.UserListDialogPaneAndUserListPane](by-memory/0x0059bc90-0x0059f25b.UserListDialogPaneAndUserListPane.md)
- [UID:0000OV][TotemFrame](by-file/TotemFrame.md)
- [UID:0000OZ][UserListDialogPane](by-file/UserListDialogPane.md)
- [UID:0000KU][LivingObjectPane](by-file/LivingObjectPane.md)
- [UID:0001NS][0x005bfbd0-0x005c0034.UiPaneDestructorThunksAndVectorHelper](by-memory/0x005bfbd0-0x005c0034.UiPaneDestructorThunksAndVectorHelper.md)
- [UID:0002WG][0x0069b4ec-0x0069b4f0.g_pOldUserStatusPane](by-memory/0x0069b4ec-0x0069b4f0.g_pOldUserStatusPane.md)

## Changes

- 2026-06-30 B009 implementation callback:
  - Added formal zero-initialized global C++.
  - Historicalized stale `ff ff ff ff` initializer language. Current MCP bytes at `0x0069b4ec` are `00 00 00 00`; xrefs remain the documented nine constructor/cleanup/consumer refs.
- 2026-06-11 A005 Batch239: Raised `84/88` to `86/90` by linking the exact one-dword memory child [UID:0002WG][0x0069b4ec-0x0069b4f0.g_pOldUserStatusPane](by-memory/0x0069b4ec-0x0069b4f0.g_pOldUserStatusPane.md), verifying `0x4` / 4-byte storage with int_convert.py, and confirming [UID:0000P2][UserStatusPane](by-file/UserStatusPane.md) remains above the parent-side gate. This made the global page eligible as the direct parent for the exact storage child; B009 later superseded the older blank-C++/95-gate wording with a zero-initialized global definition.

- Before: completion/confidence were ungraded at `0/0`.
- Changed to: completion `76`, confidence `86`.
- Summary/evidence: live IDA MCP on 2026-05-30 verified exact storage, size, segment, 9 xrefs, constructor/destructor/clear-helper writes, and known TotemFrame/LivingObjectPane consumers. Completion remains below full because two consumer xrefs still need semantic owner naming.

- 2026-06-05 autogen classification:
  - What existed before: autogen metadata was blank, so the singleton was reported as unclassified.
  - Changed to: `RECONSTRUCTABLE:TRUE` with `AUTOGEN_PARENT_UID:0000P2`; `RECONSTRUCTION_CPP CODE` remains empty.
  - Summary/evidence: live IDA MCP `xrefs_to 0x0069b4ec` and decompilation of `0x005bda40`, `0x005bdb70`, `0x005bfbe0`, and `0x005bfda0` prove NexusTK-owned `OldUserStatusPane` singleton storage owned by [UID:0000P2][UserStatusPane](by-file/UserStatusPane.md). No final C++ body was added at that time under the older 95/95 gate; B009 later superseded this with a zero-initialized global definition.

- 2026-06-06 xref/cleanup pass:
  - What existed before: the page still carried raw singleton/function labels and treated the MapPane teardown and UserListDialogPane constructor xrefs as unnamed consumers.
  - Changed to: completion `84`, confidence `88`, source-facing consumer descriptions, and direct links to the MapPane teardown and UserList dialog memory aggregates.
  - Summary/evidence: live IDA MCP `xrefs_to`, `get_bytes`, `lookup_funcs`, `decompile`, and `disasm` on 2026-06-06 account for all nine direct xrefs, initialized storage bytes, constructor publish/fallback behavior, all cleanup clears, MapPane exit removal, TotemFrame spirit-frame selection, UserListDialogPane nation initialization, and LivingObjectPane status-icon updates. No final C++ body was added at that time under the older 95/95 gate; B009 later superseded this with a zero-initialized global definition and current-zero byte evidence.
