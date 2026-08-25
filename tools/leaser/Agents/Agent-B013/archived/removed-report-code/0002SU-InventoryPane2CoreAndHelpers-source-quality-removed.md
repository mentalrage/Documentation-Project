<!-- REMOVED-MATERIAL-ARCHIVE -->
# Removed Material Archive

- Status: Non-authoritative archival material only.
- Source report: `E:\NTK\GhidraBridge\source-3\project-documentation\executed-b-agent-research\B013\0002SU-InventoryPane2CoreAndHelpers-source-quality.md`
- Safety: This file must never be executed, replayed, or used as an operational runbook.
- Credit: This archive provides no gate, score, coverage, IDA, validator, or lifecycle credit.

# Removed Executable Code Archive

- Source report: [0002SU-InventoryPane2CoreAndHelpers-source-quality.md](0002SU-InventoryPane2CoreAndHelpers-source-quality.md)
- Source report SHA256 before cleanup: `2F8DD59821F3716919AEC4EA914083A9CEF290F119D8EB766061B3A5AE9430FD`
- Cleanup generated: `2026-08-11T12:47:18Z`
- Removed executable blocks: `4`
- Scope: exact executable or command-shaped fenced blocks removed from the source report by supervisor housekeeping.
- Authority: this file is not a B-agent research report and grants no Gate 1, Gate 2, IDA, validator, score, or lifecycle credit.
- Safety: do not execute, import, evaluate, or use any block in this archive as an operational instruction.

## Removed Block R001

- Original source lines: `266-268`
- Original language: `powershell`
- Block SHA256: `23EBDEABF24F7B8197A875C060093F64A30E9398B48406757113DF3B093D5DFA`

```powershell
python .\tools\validator.py --mode file --file by-memory/0x004ee6b0-0x004ef510.InventoryPane2CoreAndHelpers.md --queue-timeout 240
```

## Removed Block R002

- Original source lines: `730-749`
- Original language: `powershell`
- Block SHA256: `B53DCFB44B1031878F03F575DEF0E8B8C428194CA68D5D9AC272258322B32C68`

```powershell
python .\tools\validator.py --mode file --file by-memory/0x004ee6b0-0x004ef510.InventoryPane2CoreAndHelpers.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-memory/0x004ee6b0-0x004ee6cf.InventoryPane2Destructor.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-memory/0x004ee6d0-0x004ee6dc.InventoryPane2RefreshEmbeddedPane.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-memory/0x004ee6e0-0x004ee6e1.InventoryPane2SourceEmptyVirtual.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-memory/0x004ee6f0-0x004eee5c.InventoryPane2OnPaint.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-memory/0x004eee60-0x004eeedc.InventoryPane2OnKeyEvent.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-memory/0x004eeee0-0x004ef290.InventoryPane2OnMouseEvent.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-memory/0x004ef290-0x004ef3fc.InventoryPane2OnServerMessage.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-memory/0x004ef400-0x004ef460.InventoryPane2SendUseItemSlotPacketRaw.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-memory/0x004ef460-0x004ef50b.InventoryPane2SendDragDropItemPacketRaw.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-memory/0x004ea130-0x004efbb7.InventoryPanes.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-class/InventoryPane2.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-file/InventoryPane.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-memory/0x004ee650-0x004ee6a7.InventoryPane2RawConstructor.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-memory/0x004ef630-0x004efa95.InventoryPane2TailHelpersAndDestructor.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-memory/0x004efa40-0x004efa95.InventoryPane2ScalarDeletingDestructor.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-memory/0x0061c7a4-0x0061c9c4.InventoryPaneReadOnlyData.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-memory/0x0061c86c-0x0061c8f8.InventoryPane2VtableData.md --apply --queue-timeout 240
```

## Removed Block R003

- Original source lines: `753-755`
- Original language: `powershell`
- Block SHA256: `CEC881CCF92146E69F1546A9FDC566F6B5BBE01A7C143EB02804D74F65284129`

```powershell
python .\tools\validator.py --mode documented --remove-missing --apply --queue-timeout 240
```

## Removed Block R004

- Original source lines: `759-761`
- Original language: `powershell`
- Block SHA256: `CB34CE16C9D94D50A08CD0A8339671846268D732AE9980562BE386A213C0CF77`

```powershell
python .\tools\validator.py execute_report B013 0002SU-InventoryPane2CoreAndHelpers-source-quality.md 0002SU --apply
```
