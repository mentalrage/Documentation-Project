<!-- REMOVED-MATERIAL-ARCHIVE -->
# Removed Material Archive

- Status: Non-authoritative archival material only.
- Source report: `E:\NTK\GhidraBridge\source-3\project-documentation\executed-b-agent-research\B015\0001BQ-ClientItemMenuItemList-source-quality.md`
- Safety: This file must never be executed, replayed, or used as an operational runbook.
- Credit: This archive provides no gate, score, coverage, IDA, validator, or lifecycle credit.

# Removed Executable Code Archive

- Source report: [0001BQ-ClientItemMenuItemList-source-quality.md](0001BQ-ClientItemMenuItemList-source-quality.md)
- Source report SHA256 before cleanup: `23E4B2F10D3BA0CB1166E3DE4716AA68790B2CC6D796A8E25098F14248574E81`
- Cleanup generated: `2026-08-11T12:47:18Z`
- Removed executable blocks: `1`
- Scope: exact executable or command-shaped fenced blocks removed from the source report by supervisor housekeeping.
- Authority: this file is not a B-agent research report and grants no Gate 1, Gate 2, IDA, validator, score, or lifecycle credit.
- Safety: do not execute, import, evaluate, or use any block in this archive as an operational instruction.

## Removed Block R001

- Original source lines: `588-593`
- Original language: `powershell`
- Block SHA256: `F3656FBB7310A9FAA19DE2F49FC1E9EF58CADA315BA27FA66E197845DE2A4F9E`

```powershell
python .\tools\validator.py --mode file --file by-memory/0x0051c470-0x0051ca3c.ClientItemMenuItemList.md --apply --queue-timeout 240 --wait-generated
python .\tools\validator.py --mode file --file by-class/ClientItemMenuItemList.md --apply --queue-timeout 240 --wait-generated
python .\tools\validator.py --mode file --file by-file/ItemMenuDialogs.md --apply --queue-timeout 240 --wait-generated
python .\tools\validator.py execute_report B015 0001BQ-ClientItemMenuItemList-source-quality.md 0001BQ --apply
```
