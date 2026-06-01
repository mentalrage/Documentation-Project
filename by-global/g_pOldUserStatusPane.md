*** UID:0000RV | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:76 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# g_pOldUserStatusPane

## Status

- Confidence: strong.
- Address: `0x0069b4ec`
- IDA name: `dword_69B4EC`
- Proposed owner file: [UID:0000P2][UserStatusPane](by-file/UserStatusPane.md)
- Related class: [UID:00009U][OldUserStatusPane](by-class/OldUserStatusPane.md)

## Role

`g_pOldUserStatusPane` stores the active legacy status pane. It is used by legacy status rendering and by [UID:0000F4][TotemFrame](by-class/TotemFrame.md), which reads the old pane and calls `OldUserStatusPane::GetSpiritId` to choose a `TOTFRAME.EPD` frame.

## Evidence Notes

- `OldUserStatusPane::OldUserStatusPane` writes the global at `0x005bda8a` and `0x005bda91`.
- The cleanup body clears it at `0x005bdbce`.
- The singleton clear helper at `0x005bfbe0` writes zero to `0x0069b4ec`.
- The scalar deleting destructor clears it at `0x005bfe05`.
- `TotemFrame::OnPaint` reads the global at `0x00598dec` and calls `0x005bdc60`.
- `LivingObjectPane::HandleServerEntryPacket` reads it before calling `OldUserStatusPane::SetStatusIconId` at `0x005aaed8`.

## 2026-05-30 Review Notes

- IDA MCP `py_eval` on 2026-05-30 confirms `0x0069b4ec` is `dword_69B4EC`, size `4`, in `.data`, with 9 data xrefs.
- Live IDA xrefs confirm constructor writes at `0x005bda8a` and `0x005bda91` in `sub_5BDA40`, cleanup clear at `0x005bdbce` in `sub_5BDB70`, singleton clear at `0x005bfbe0` in `sub_5BFBE0`, and scalar deleting destructor clear at `0x005bfe05` in `sub_5BFDA0`.
- Live IDA xrefs confirm known consumers at `0x00598dec` in `sub_598DD0` and `0x005aaed2` in `sub_5AAC80`; the earlier note rounded the latter to the call-neighborhood address `0x005aaed8`.
- Additional live xrefs at `0x0050490b` in `sub_5047F0` and `0x0059c997` in `sub_59BC90` still need semantic owner naming, so completion remains below full.

## Cross-References

- [UID:0000P2][UserStatusPane](by-file/UserStatusPane.md)
- [UID:00009U][OldUserStatusPane](by-class/OldUserStatusPane.md)
- [UID:0001NR][0x005bda40-0x005bfbc1.OldUserStatusPane](by-memory/0x005bda40-0x005bfbc1.OldUserStatusPane.md)
- [UID:0000OV][TotemFrame](by-file/TotemFrame.md)
- [UID:0001NS][0x005bfbd0-0x005c0034.UiPaneDestructorThunksAndVectorHelper](by-memory/0x005bfbd0-0x005c0034.UiPaneDestructorThunksAndVectorHelper.md)

## Changes

- Before: completion/confidence were ungraded at `0/0`.
- Changed to: completion `76`, confidence `86`.
- Summary/evidence: live IDA MCP on 2026-05-30 verified exact storage, size, segment, 9 xrefs, constructor/destructor/clear-helper writes, and known TotemFrame/LivingObjectPane consumers. Completion remains below full because two consumer xrefs still need semantic owner naming.
