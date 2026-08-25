<!-- REMOVED-MATERIAL-ARCHIVE -->
# Removed Material Archive

- Status: Non-authoritative archival material only.
- Source report: `E:\NTK\GhidraBridge\source-3\project-documentation\executed-b-agent-research\B004\00013A-AddEmployeeItemDialog-source-quality.md`
- Safety: This file must never be executed, replayed, or used as an operational runbook.
- Credit: This archive provides no gate, score, coverage, IDA, validator, or lifecycle credit.

# Removed Executable Code Archive

- Source report: [00013A-AddEmployeeItemDialog-source-quality.md](00013A-AddEmployeeItemDialog-source-quality.md)
- Source report SHA256 before cleanup: `706DBB7CB69AD490BDBAF404FF0B9C835ACD678077C8EB420E59820944F4E185`
- Cleanup generated: `2026-08-11T12:47:06Z`
- Removed executable blocks: `3`
- Scope: exact executable or command-shaped fenced blocks removed from the source report by supervisor housekeeping.
- Authority: this file is not a B-agent research report and grants no Gate 1, Gate 2, IDA, validator, score, or lifecycle credit.
- Safety: do not execute, import, evaluate, or use any block in this archive as an operational instruction.

## Removed Block R001

- Original source lines: `443-445`
- Original language: `powershell`
- Block SHA256: `EEFC39FA0C2E83A61D9C3A3E05D939CFF11FBF3B4E176E2F74715BA2085063DF`

```powershell
Test-NetConnection 127.0.0.1 -Port 13337
```

## Removed Block R002

- Original source lines: `449-451`
- Original language: `powershell`
- Block SHA256: `E8C64698ECC92A42C1286B90F2549A29F497D3284196E237822AC585C34ADF23`

```powershell
Get-FileHash 'E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe' -Algorithm SHA256
```

## Removed Block R003

- Original source lines: `457-461`
- Original language: `powershell`
- Block SHA256: `2FFDB31F6A98D07657CEDAA17DCCE11F9710C13C1589585D91CF179C41FF3170`

```powershell
rg -n "UID:00013A|0x004a4b20|AddEmployeeItemDialog" `
  "E:\NTK\GhidraBridge\source-3\project-documentation\by-memory\-coverage-report.md" `
  "E:\NTK\GhidraBridge\source-3\project-documentation\by-memory\0x004a4b20-0x004a4d3b.AddEmployeeItemDialog.md"
```
