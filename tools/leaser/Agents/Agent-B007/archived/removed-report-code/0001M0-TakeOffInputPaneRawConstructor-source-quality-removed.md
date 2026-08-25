<!-- REMOVED-MATERIAL-ARCHIVE -->
# Removed Material Archive

- Status: Non-authoritative archival material only.
- Source report: `E:\NTK\GhidraBridge\source-3\project-documentation\executed-b-agent-research\B007\0001M0-TakeOffInputPaneRawConstructor-source-quality.md`
- Safety: This file must never be executed, replayed, or used as an operational runbook.
- Credit: This archive provides no gate, score, coverage, IDA, validator, or lifecycle credit.

# Removed Executable Code Archive

- Source report: [0001M0-TakeOffInputPaneRawConstructor-source-quality.md](0001M0-TakeOffInputPaneRawConstructor-source-quality.md)
- Source report SHA256 before cleanup: `8D9A10EBB8D0D2B1686F53DF390221A2F01FF1EBA194B70C191D7B4A035F4D57`
- Cleanup generated: `2026-08-11T12:47:12Z`
- Removed executable blocks: `2`
- Scope: exact executable or command-shaped fenced blocks removed from the source report by supervisor housekeeping.
- Authority: this file is not a B-agent research report and grants no Gate 1, Gate 2, IDA, validator, score, or lifecycle credit.
- Safety: do not execute, import, evaluate, or use any block in this archive as an operational instruction.

## Removed Block R001

- Original source lines: `445-447`
- Original language: `powershell`
- Block SHA256: `A4DDA0968A91BB37324CFDC77F9DFF65E97F91F81DB14473C981CF615AAB373E`

```powershell
python .\tools\validator.py --mode file --file by-memory\0x005b26e0-0x005b2720.TakeOffInputPaneRawConstructor.md --apply --queue-timeout 240 --wait-generated
```

## Removed Block R002

- Original source lines: `451-456`
- Original language: `powershell`
- Block SHA256: `A8C9CA2D02B0AC40159EF759D40591B9B4DBD0B82198F581A752D02AB35BE5E0`

```powershell
python .\tools\validator.py --mode file --file by-class\TakeOffInputPane.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-file\ItemActionInputPanes.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-memory\0x005b2720-0x005b296b.TakeOffInputPane.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-type\by-vtable\ItemActionInputPaneVtableFamily.md --apply --queue-timeout 240
```
