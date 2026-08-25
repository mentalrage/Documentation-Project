<!-- REMOVED-MATERIAL-ARCHIVE -->
# Removed Material Archive

- Status: Non-authoritative archival material only.
- Source report: `E:\NTK\GhidraBridge\source-3\project-documentation\tools\leaser\Agents\Older-Research\Agent-B014\0001GY-ScrollCollectionPaneClearHighlightRaw-source-quality.md`
- Safety: This file must never be executed, replayed, or used as an operational runbook.
- Credit: This archive provides no gate, score, coverage, IDA, validator, or lifecycle credit.

# Removed Executable Code Archive

- Source report: [0001GY-ScrollCollectionPaneClearHighlightRaw-source-quality.md](0001GY-ScrollCollectionPaneClearHighlightRaw-source-quality.md)
- Source report SHA256 before cleanup: `3D1330124557C4238B035F98DC289D0C2E1D81C955CDD05E16A5C27EB6FFA6BB`
- Cleanup generated: `2026-08-11T12:47:18Z`
- Removed executable blocks: `2`
- Scope: exact executable or command-shaped fenced blocks removed from the source report by supervisor housekeeping.
- Authority: this file is not a B-agent research report and grants no Gate 1, Gate 2, IDA, validator, score, or lifecycle credit.
- Safety: do not execute, import, evaluate, or use any block in this archive as an operational instruction.

## Removed Block R001

- Original source lines: `300-302`
- Original language: `powershell`
- Block SHA256: `FC4925DD57A292B4B8182505C798E4D8E3B93AEDB061AE928AC2E8102A2CB9BC`

```powershell
cd E:\NTK\GhidraBridge\source-3\project-documentation
```

## Removed Block R002

- Original source lines: `306-313`
- Original language: `powershell`
- Block SHA256: `E216FD715E35129C675CE233A865B8DDBCE3C98C024196A8F1FA2286758B0827`

```powershell
python .\tools\validator.py --mode file --file by-memory\0x00563200-0x0056325c.ScrollCollectionPaneResetScrollStateRaw.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-class\ScrollCollectionPane.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-file\ScrollCollectionPane.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-memory\0x00561db0-0x0056325c.ScrollCollectionPane.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-type\by-struct\ScrollCollectionPaneLayout.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-type\by-vtable\ScrollCollectionPaneVtables.md --apply --queue-timeout 240 --wait-generated
```
