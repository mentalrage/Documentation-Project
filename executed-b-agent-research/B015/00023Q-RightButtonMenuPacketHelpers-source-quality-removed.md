<!-- REMOVED-MATERIAL-ARCHIVE -->
# Removed Material Archive

- Status: Non-authoritative archival material only.
- Source report: `E:\NTK\GhidraBridge\source-3\project-documentation\executed-b-agent-research\B015\00023Q-RightButtonMenuPacketHelpers-source-quality.md`
- Safety: This file must never be executed, replayed, or used as an operational runbook.
- Credit: This archive provides no gate, score, coverage, IDA, validator, or lifecycle credit.

# Removed Executable Code Archive

- Source report: [00023Q-RightButtonMenuPacketHelpers-source-quality.md](00023Q-RightButtonMenuPacketHelpers-source-quality.md)
- Source report SHA256 before cleanup: `C49816B20437077007BE45A49817755B3D29A6821EB987959CFFC4F5F3327F2A`
- Cleanup generated: `2026-08-11T12:47:19Z`
- Removed executable blocks: `2`
- Scope: exact executable or command-shaped fenced blocks removed from the source report by supervisor housekeeping.
- Authority: this file is not a B-agent research report and grants no Gate 1, Gate 2, IDA, validator, score, or lifecycle credit.
- Safety: do not execute, import, evaluate, or use any block in this archive as an operational instruction.

## Removed Block R001

- Original source lines: `430-436`
- Original language: `powershell`
- Block SHA256: `A15D8E28F45F9F077EED1875C9D4AFE468B2D75E1D46569C712781937536AD35`

```powershell
python .\tools\validator.py --mode file --file by-memory\0x00555780-0x005558c2.RightButtonMenuPacketHelpers.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-class\RightButtonMenuPane.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-file\RightButtonMenuPane.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-memory\0x00554b40-0x0055577b.RightButtonMenuPaneCore.md --apply --queue-timeout 240
python .\tools\validator.py --mode autogen --apply --queue-timeout 240
```

## Removed Block R002

- Original source lines: `440-442`
- Original language: `powershell`
- Block SHA256: `80AA9C6C3DDE137200FAC407C3C7D2314D311D995236E431A8B26BE9C56934AC`

```powershell
python .\tools\validator.py --mode file --file by-memory\-coverage-report.md --apply --queue-timeout 240
```
