<!-- REMOVED-MATERIAL-ARCHIVE -->
# Removed Material Archive

- Status: Non-authoritative archival material only.
- Source report: `E:\NTK\GhidraBridge\source-3\project-documentation\executed-b-agent-research\B009\00041D-NewHumanImageLibLoadAcc2DrwTable-source-quality.md`
- Safety: This file must never be executed, replayed, or used as an operational runbook.
- Credit: This archive provides no gate, score, coverage, IDA, validator, or lifecycle credit.

# Removed Executable Code Archive

- Source report: [00041D-NewHumanImageLibLoadAcc2DrwTable-source-quality.md](00041D-NewHumanImageLibLoadAcc2DrwTable-source-quality.md)
- Source report SHA256 before cleanup: `B4736A829AEAF5E7A133C4BE1420A9A596E7110E2E25C78CEE21ABCE826E5ADB`
- Cleanup generated: `2026-08-11T12:47:15Z`
- Removed executable blocks: `1`
- Scope: exact executable or command-shaped fenced blocks removed from the source report by supervisor housekeeping.
- Authority: this file is not a B-agent research report and grants no Gate 1, Gate 2, IDA, validator, score, or lifecycle credit.
- Safety: do not execute, import, evaluate, or use any block in this archive as an operational instruction.

## Removed Block R001

- Original source lines: `298-306`
- Original language: `powershell`
- Block SHA256: `28530C32527E5372CE2291A433F357A386DDA2D6901FECD91B42B8B1801CEE98`

```powershell
python .\tools\validator.py --mode file --file by-memory/0x004e1800-0x004e19c5.NewHumanImageLibLoadAcc2DrwTable.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-class/NewHumanImageLib.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-file/NewHumanImageLib.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-memory/0x004dfd10-0x004e024a.NewHumanImageLibConstructor.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-memory/0x004dfd10-0x004e4d79.NewHumanImageLibLocalMethodCluster.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-type/by-struct/NewHumanImageLibLayout.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-resource/new-human-motion-tables.md --apply --queue-timeout 240
```
