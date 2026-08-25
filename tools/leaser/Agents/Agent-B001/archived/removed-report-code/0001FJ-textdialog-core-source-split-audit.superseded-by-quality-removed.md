<!-- REMOVED-MATERIAL-ARCHIVE -->
# Removed Material Archive

- Status: Non-authoritative archival material only.
- Source report: `E:\NTK\GhidraBridge\source-3\project-documentation\executed-b-agent-research\B001\0001FJ-textdialog-core-source-split-audit.superseded-by-quality.md`
- Safety: This file must never be executed, replayed, or used as an operational runbook.
- Credit: This archive provides no gate, score, coverage, IDA, validator, or lifecycle credit.

# Removed Executable Code Archive

- Source report: [0001FJ-textdialog-core-source-split-audit.superseded-by-quality.md](0001FJ-textdialog-core-source-split-audit.superseded-by-quality.md)
- Source report SHA256 before cleanup: `2FE8BF1EB39BC0249FA33DCC36AD8B0ADCCB2109E8CE43CD4499AF6BFF1A8E5E`
- Cleanup generated: `2026-08-11T12:46:57Z`
- Removed executable blocks: `1`
- Scope: exact executable or command-shaped fenced blocks removed from the source report by supervisor housekeeping.
- Authority: this file is not a B-agent research report and grants no Gate 1, Gate 2, IDA, validator, score, or lifecycle credit.
- Safety: do not execute, import, evaluate, or use any block in this archive as an operational instruction.

## Removed Block R001

- Original source lines: `554-566`
- Original language: `powershell`
- Block SHA256: `34ECB513CB052F11412AE1D4464272031592FB28C4C308EB6FDA2D3170F7570E`

```powershell
cd E:\NTK\GhidraBridge\source-3\project-documentation
python tools\validator.py --mode file --file by-memory\0x00552110-0x005534a0.TextDialogCore.md --apply
python tools\validator.py --mode file --file by-memory\0x00552110-0x0055317a.TextDialogConstructor.md --apply
python tools\validator.py --mode file --file by-memory\0x00553180-0x00553338.TextDialogHandleDialogAction.md --apply
python tools\validator.py --mode file --file by-memory\0x00553350-0x00553495.TextDialogRawStringReplyPacketHelper.md --apply
python tools\validator.py --mode file --file by-class\TextDialog.md --apply
python tools\validator.py --mode file --file by-file\TextDialog.md --apply
python tools\validator.py --mode file --file by-memory\-ignored.md --apply
python tools\validator.py --mode documented --apply
python tools\memory_ranges.py report
rg -n "00552110-0x005534a0|00552110-0x0055317a|00553180-0x00553338|00553350-0x00553495|005534a0-0x00553609" auto-generated\by-memory-tool-report.md auto-generated\-ag-memory-coverage.md project-level\-auto-completion-stats.md
```
