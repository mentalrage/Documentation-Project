<!-- REMOVED-MATERIAL-ARCHIVE -->
# Removed Material Archive

- Status: Non-authoritative archival material only.
- Source report: `E:\NTK\GhidraBridge\source-3\project-documentation\executed-b-agent-research\B001\0000YG-softwareblend16-halfblend-block-source-quality.md`
- Safety: This file must never be executed, replayed, or used as an operational runbook.
- Credit: This archive provides no gate, score, coverage, IDA, validator, or lifecycle credit.

# Removed Executable Code Archive

- Source report: [0000YG-softwareblend16-halfblend-block-source-quality.md](0000YG-softwareblend16-halfblend-block-source-quality.md)
- Source report SHA256 before cleanup: `A9C2FA8F5F8FCE8304CACB80F10AB722423AD1AD72AFBC75FBDAB42718F21AB5`
- Cleanup generated: `2026-08-11T12:46:56Z`
- Removed executable blocks: `2`
- Scope: exact executable or command-shaped fenced blocks removed from the source report by supervisor housekeeping.
- Authority: this file is not a B-agent research report and grants no Gate 1, Gate 2, IDA, validator, score, or lifecycle credit.
- Safety: do not execute, import, evaluate, or use any block in this archive as an operational instruction.

## Removed Block R001

- Original source lines: `408-412`
- Original language: `powershell`
- Block SHA256: `A1DB90D86B5106D45AB8C52F07856E73172C20B9B17091AEE553C02C78A7826B`

```powershell
python E:\NTK\GhidraBridge\source-3\project-documentation\tools\validator.py --mode file --file E:\NTK\GhidraBridge\source-3\project-documentation\by-memory\0x00460c10-0x00460c8c.HalfBlendSpan16Blocks.md --apply
python E:\NTK\GhidraBridge\source-3\project-documentation\tools\validator.py --mode file --file E:\NTK\GhidraBridge\source-3\project-documentation\by-memory\-coverage-report.md --apply
python E:\NTK\GhidraBridge\source-3\project-documentation\tools\validator.py --mode autogen --apply
```

## Removed Block R002

- Original source lines: `416-420`
- Original language: `powershell`
- Block SHA256: `C9F087FC7FD512F5B482F4085D38168542BAE81FEBF31328AA55E55721A1BF28`

```powershell
rg -n "0000YG|HalfBlendSpan16Blocks|0x00460c10-0x00460c8c" E:\NTK\GhidraBridge\source-3\project-documentation\by-memory\-coverage-report.md E:\NTK\GhidraBridge\source-3\project-documentation\project-level\-auto-completion-stats.md E:\NTK\GhidraBridge\source-3\project-documentation\auto-generated\-ag-memory-coverage.md
rg -n "00460c0a-0x00460c10|00460c8c-0x00460c90" E:\NTK\GhidraBridge\source-3\project-documentation\by-memory\-ignored.md E:\NTK\GhidraBridge\source-3\project-documentation\by-memory\-coverage-report.md
Get-Item E:\NTK\GhidraBridge\source-3\project-documentation\auto-generated\NexusTK\render\SoftwareBlend16.cpp | Select-Object FullName,Length
```
