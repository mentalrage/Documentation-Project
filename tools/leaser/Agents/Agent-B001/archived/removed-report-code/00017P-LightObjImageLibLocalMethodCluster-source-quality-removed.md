<!-- REMOVED-MATERIAL-ARCHIVE -->
# Removed Material Archive

- Status: Non-authoritative archival material only.
- Source report: `E:\NTK\GhidraBridge\source-3\project-documentation\executed-b-agent-research\B001\00017P-LightObjImageLibLocalMethodCluster-source-quality.md`
- Safety: This file must never be executed, replayed, or used as an operational runbook.
- Credit: This archive provides no gate, score, coverage, IDA, validator, or lifecycle credit.

# Removed Executable Code Archive

- Source report: [00017P-LightObjImageLibLocalMethodCluster-source-quality.md](00017P-LightObjImageLibLocalMethodCluster-source-quality.md)
- Source report SHA256 before cleanup: `808C21A4DA4C5627E96CA28004BB7225600F26562745AEA5E53984C47B4B9B20`
- Cleanup generated: `2026-08-11T12:46:56Z`
- Removed executable blocks: `2`
- Scope: exact executable or command-shaped fenced blocks removed from the source report by supervisor housekeeping.
- Authority: this file is not a B-agent research report and grants no Gate 1, Gate 2, IDA, validator, score, or lifecycle credit.
- Safety: do not execute, import, evaluate, or use any block in this archive as an operational instruction.

## Removed Block R001

- Original source lines: `442-448`
- Original language: `powershell`
- Block SHA256: `9B799EC5306B1703723890B5C99C9B6B3C1611AADC2C115C320E5CF35F35FBD6`

```powershell
python tools\validator.py --mode file --file by-memory\0x004df7e0-0x004dfd0a.LightObjImageLibLocalMethodCluster.md --apply --queue-timeout 240 --lock-timeout -1
python tools\validator.py --mode file --file by-file\LightObjImageLib.md --apply --queue-timeout 240 --lock-timeout -1
python tools\validator.py --mode file --file by-class\LightObjImageLib.md --apply --queue-timeout 240 --lock-timeout -1
python tools\validator.py --mode file --file by-type\by-vtable\LightObjImageLibVtable.md --apply --queue-timeout 240 --lock-timeout -1
python tools\validator.py --mode file --file by-memory\0x0061b750-0x0061b768.LightObjImageLibVtableData.md --apply --queue-timeout 240 --lock-timeout -1
```

## Removed Block R002

- Original source lines: `452-455`
- Original language: `powershell`
- Block SHA256: `6C0EF272BD91917627CD29F30419836EC88783FA275D0AE0643B4756388D56E4`

```powershell
python tools\validator.py --mode file --file by-memory\-coverage-report.md --apply --queue-timeout 240 --lock-timeout -1
python tools\validator.py --mode rescore --apply --queue-timeout 240 --lock-timeout -1
```
