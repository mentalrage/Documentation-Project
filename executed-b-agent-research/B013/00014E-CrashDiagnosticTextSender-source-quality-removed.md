<!-- REMOVED-MATERIAL-ARCHIVE -->
# Removed Material Archive

- Status: Non-authoritative archival material only.
- Source report: `E:\NTK\GhidraBridge\source-3\project-documentation\executed-b-agent-research\B013\00014E-CrashDiagnosticTextSender-source-quality.md`
- Safety: This file must never be executed, replayed, or used as an operational runbook.
- Credit: This archive provides no gate, score, coverage, IDA, validator, or lifecycle credit.

# Removed Executable Code Archive

- Source report: [00014E-CrashDiagnosticTextSender-source-quality.md](00014E-CrashDiagnosticTextSender-source-quality.md)
- Source report SHA256 before cleanup: `626D8F5041B73EE258688AE9FC432CA23758B601A99FD8909C90687148129D01`
- Cleanup generated: `2026-08-11T12:47:17Z`
- Removed executable blocks: `3`
- Scope: exact executable or command-shaped fenced blocks removed from the source report by supervisor housekeeping.
- Authority: this file is not a B-agent research report and grants no Gate 1, Gate 2, IDA, validator, score, or lifecycle credit.
- Safety: do not execute, import, evaluate, or use any block in this archive as an operational instruction.

## Removed Block R001

- Original source lines: `530-532`
- Original language: `powershell`
- Block SHA256: `59F85E6ADDB5ECB839F9615F3A13F73A3A0E35B40B1D820365F5C69E44BC9E3B`

```powershell
python source-3/project-documentation/tools/validator.py --mode file --file source-3/project-documentation/by-memory/0x004ab740-0x004ab804.CrashDiagnosticTextSender.md
```

## Removed Block R002

- Original source lines: `538-545`
- Original language: `powershell`
- Block SHA256: `2858A1945094914D68BF28B0F795A612BCC12A4BFE254DD360CB985BE7D35D21`

```powershell
python source-3/project-documentation/tools/validator.py --mode file --file source-3/project-documentation/by-memory/0x004ab740-0x004ab804.CrashDiagnosticTextSender.md --apply
python source-3/project-documentation/tools/validator.py --mode file --file source-3/project-documentation/by-class/ExceptionHandler.md --apply
python source-3/project-documentation/tools/validator.py --mode file --file source-3/project-documentation/by-file/ExceptionHandler.md --apply
python source-3/project-documentation/tools/validator.py --mode file --file source-3/project-documentation/by-memory/0x004ab480-0x004ac89a.ExceptionHandler.md --apply
python source-3/project-documentation/tools/validator.py --mode file --file source-3/project-documentation/by-meta/client_crash_diagnostics.md --apply
python source-3/project-documentation/tools/validator.py --mode file --file source-3/project-documentation/by-memory/0x00466ca0-0x004670ad.CheckTimerSkewAndSendHeartbeat.md --apply
```

## Removed Block R003

- Original source line: `31`
- Original representation: inline PowerShell command and result
- Source report SHA256 before this cleanup: `2F5C36D847745208A397D5BA9BBE282CBB656A4BA62083A5D074C066E0CA6F96`
- Block SHA256: `61D82DF4B3E9AC7BC472FC0774360885F09836B513F09587D14602B2300528CE`

```powershell
Invoke-WebRequest http://127.0.0.1:13337/mcp -> Unable to connect to the remote server
```
