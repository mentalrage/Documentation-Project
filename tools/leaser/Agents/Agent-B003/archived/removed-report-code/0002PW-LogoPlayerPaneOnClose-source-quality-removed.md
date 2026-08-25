<!-- REMOVED-MATERIAL-ARCHIVE -->
# Removed Material Archive

- Status: Non-authoritative archival material only.
- Source report: `E:\NTK\GhidraBridge\source-3\project-documentation\executed-b-agent-research\B003\0002PW-LogoPlayerPaneOnClose-source-quality.md`
- Safety: This file must never be executed, replayed, or used as an operational runbook.
- Credit: This archive provides no gate, score, coverage, IDA, validator, or lifecycle credit.

# Removed Executable Code Archive

- Source report: [0002PW-LogoPlayerPaneOnClose-source-quality.md](0002PW-LogoPlayerPaneOnClose-source-quality.md)
- Source report SHA256 before cleanup: `AE28B26EE153AE8FD746F2DF6EEEB0B83B3958AA1EB331ABBDB714C3AC25B58E`
- Cleanup generated: `2026-08-11T12:47:05Z`
- Removed executable blocks: `2`
- Scope: exact executable or command-shaped fenced blocks removed from the source report by supervisor housekeeping.
- Authority: this file is not a B-agent research report and grants no Gate 1, Gate 2, IDA, validator, score, or lifecycle credit.
- Safety: do not execute, import, evaluate, or use any block in this archive as an operational instruction.

## Removed Block R001

- Original source lines: `405-415`
- Original language: `powershell`
- Block SHA256: `7824D9B56910EBFEB5E29C70AF2EB209038D884527C6356B16DEACB13DE53D06`

```powershell
cd E:\NTK\GhidraBridge\source-3\project-documentation

python .\tools\validator.py --mode file --file .\by-memory\0x004f5620-0x004f5634.LogoPlayerPaneOnClose.md --apply --queue-timeout 240 --lock-timeout -1
python .\tools\validator.py --mode file --file .\by-class\LogoPlayerPane.md --apply --queue-timeout 240 --lock-timeout -1
python .\tools\validator.py --mode file --file .\by-memory\0x004f53b0-0x004f570c.LogoPlayerPane.md --apply --queue-timeout 240 --lock-timeout -1
python .\tools\validator.py --mode file --file .\by-file\StartupLogoPanes.md --apply --queue-timeout 240 --lock-timeout -1
python .\tools\validator.py --mode file --file .\by-memory\-coverage-report.md --apply --queue-timeout 240 --lock-timeout -1
python .\tools\validator.py --mode autogen --apply --queue-timeout 240 --lock-timeout -1
python .\tools\validator.py --mode rescore --apply --queue-timeout 240 --lock-timeout -1
```

## Removed Block R002

- Original source lines: `419-421`
- Original language: `powershell`
- Block SHA256: `DCA4F043CA412364D8E20AD52E2A190026337C5E4BB5B183D3761CD0AF8C78DD`

```powershell
python .\tools\validator.py --mode file --file .\by-file\FunctionObjects.md --apply --queue-timeout 240 --lock-timeout -1
```
