<!-- REMOVED-MATERIAL-ARCHIVE -->
# Removed Material Archive

- Status: Non-authoritative archival material only.
- Source report: `E:\NTK\GhidraBridge\source-3\project-documentation\executed-b-agent-research\B006\00041A-NewHumanImageLibLoadLayerTable-source-quality.md`
- Safety: This file must never be executed, replayed, or used as an operational runbook.
- Credit: This archive provides no gate, score, coverage, IDA, validator, or lifecycle credit.

# Removed Executable Code Archive

- Source report: [00041A-NewHumanImageLibLoadLayerTable-source-quality.md](00041A-NewHumanImageLibLoadLayerTable-source-quality.md)
- Source report SHA256 before cleanup: `A11B3B00BF97B75EEDB8F9CE94B78CC7603046ECD03B30A552A4D5FD9CE7658A`
- Cleanup generated: `2026-08-11T12:47:11Z`
- Removed executable blocks: `1`
- Scope: exact executable or command-shaped fenced blocks removed from the source report by supervisor housekeeping.
- Authority: this file is not a B-agent research report and grants no Gate 1, Gate 2, IDA, validator, score, or lifecycle credit.
- Safety: do not execute, import, evaluate, or use any block in this archive as an operational instruction.

## Removed Block R001

- Original source lines: `442-451`
- Original language: `powershell`
- Block SHA256: `2E7A92D9405BE4440725355CB4113EBB314C5C2AA78BC960DC93F0AB679769EE`

```powershell
python .\tools\validator.py --mode file --file by-memory/0x004e1040-0x004e11af.NewHumanImageLibLoadLayerTable.md --apply --queue-timeout 240 --wait-generated
python .\tools\validator.py --mode file --file by-class/NewHumanImageLib.md --apply --queue-timeout 240 --wait-generated
python .\tools\validator.py --mode file --file by-file/NewHumanImageLib.md --apply --queue-timeout 240 --wait-generated
python .\tools\validator.py --mode file --file by-memory/0x004dfd10-0x004e4d79.NewHumanImageLibLocalMethodCluster.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-memory/0x004dfd10-0x004e024a.NewHumanImageLibConstructor.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-memory/0x004e50a0-0x004e523e.VectorGrowLayer.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-resource/new-human-motion-tables.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-type/by-struct/NewHumanImageLibLayout.md --apply --queue-timeout 240
```
