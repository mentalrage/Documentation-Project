<!-- REMOVED-MATERIAL-ARCHIVE -->
# Removed Material Archive

- Status: Non-authoritative archival material only.
- Source report: `E:\NTK\GhidraBridge\source-3\project-documentation\executed-b-agent-research\B002\000020-CheatDetector-class-source-quality.md`
- Safety: This file must never be executed, replayed, or used as an operational runbook.
- Credit: This archive provides no gate, score, coverage, IDA, validator, or lifecycle credit.

# Removed Executable Code Archive

- Source report: [000020-CheatDetector-class-source-quality.md](000020-CheatDetector-class-source-quality.md)
- Source report SHA256 before cleanup: `A4271A2CA5EDE3AA82D458916ACB1F857CB789715D2065CD373BC3FCCEE154AE`
- Cleanup generated: `2026-08-11T12:47:00Z`
- Removed executable blocks: `2`
- Scope: exact executable or command-shaped fenced blocks removed from the source report by supervisor housekeeping.
- Authority: this file is not a B-agent research report and grants no Gate 1, Gate 2, IDA, validator, score, or lifecycle credit.
- Safety: do not execute, import, evaluate, or use any block in this archive as an operational instruction.

## Removed Block R001

- Original source lines: `839-851`
- Original language: `powershell`
- Block SHA256: `5D285598195703E2E4569F5E8E1D43BE90F3CB1E4B81EB2B364527CE3E129563`

```powershell
python .\tools\validator.py --mode file --file by-class\CheatDetector.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-memory\0x00483f90-0x00483fd9.CheatDetectorTimeSnapshotHelper.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-memory\0x00483f00-0x0048402d.CheatDetector.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-memory\0x00483fe0-0x0048402d.CheatDetectorVirtualClearAndDestructor.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-file\CheatDetector.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-global\g_pCheatDetector.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-memory\0x0067ab3c-0x0067ab40.g_pCheatDetector.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-type\by-vtable\CheatDetectorVtable.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-memory\0x00615560-0x00615570.CheatDetectorVtableData.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-meta\client_anticheat.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-project-structure\proposed-source-tree.md --apply --queue-timeout 240
```

## Removed Block R002

- Original source lines: `855-857`
- Original language: `powershell`
- Block SHA256: `55DBB9A557BB30932E04453A9F35160AD38D87254477AD2F279896EF67F09828`

```powershell
python .\tools\validator.py --mode file --file auto-generated\NexusTK\security\CheatDetector.cpp --apply --queue-timeout 240
```
