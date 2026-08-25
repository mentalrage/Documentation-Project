<!-- REMOVED-MATERIAL-ARCHIVE -->
# Removed Material Archive

- Status: Non-authoritative archival material only.
- Source report: `E:\NTK\GhidraBridge\source-3\project-documentation\executed-b-agent-research\B004\0004A0-ExchangeItemListPaneDrawItemEntry-source-quality.md`
- Safety: This file must never be executed, replayed, or used as an operational runbook.
- Credit: This archive provides no gate, score, coverage, IDA, validator, or lifecycle credit.

# Removed Executable Code Archive

- Source report: [0004A0-ExchangeItemListPaneDrawItemEntry-source-quality.md](0004A0-ExchangeItemListPaneDrawItemEntry-source-quality.md)
- Source report SHA256 before cleanup: `C7EBF861606677CF5EFF67F3AA445C429DA39F2C24F88B70811AB34C224C4A63`
- Cleanup generated: `2026-08-11T12:47:08Z`
- Removed executable blocks: `2`
- Scope: exact executable or command-shaped fenced blocks removed from the source report by supervisor housekeeping.
- Authority: this file is not a B-agent research report and grants no Gate 1, Gate 2, IDA, validator, score, or lifecycle credit.
- Safety: do not execute, import, evaluate, or use any block in this archive as an operational instruction.

## Removed Block R001

- Original source lines: `171-178`
- Original language: `powershell`
- Block SHA256: `07A38F79403651E627A13B76B8402FF67182BA8ECCB37E0DE61ADA9D51292773`

```powershell
python .\tools\validator.py --mode file --file by-memory/0x004ae1c0-0x004ae4b6.ExchangeItemListPaneDrawItemEntry.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-class/ExchangeItemListPane.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-file/ExchangeDialog.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-memory/0x004ac8a0-0x004ae4b6.ExchangeDialog.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-class/ExchangeDialog.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-memory/0x004ae1b0-0x004ae1b3.ExchangeItemListPaneNullVirtual.md --apply --queue-timeout 240
```

## Removed Block R002

- Original source lines: `184-186`
- Original language: `powershell`
- Block SHA256: `5B4E9038B93168BF7756FE9BB272F8CAFD13CC667595AB0F6C49C0096DFD7DB3`

```powershell
python .\tools\validator.py execute_report B004 0004A0-ExchangeItemListPaneDrawItemEntry-source-quality.md 0004A0 --apply
```
