<!-- REMOVED-MATERIAL-ARCHIVE -->
# Removed Material Archive

- Status: Non-authoritative archival material only.
- Source report: `E:\NTK\GhidraBridge\source-3\project-documentation\executed-b-agent-research\B001\0001CO-browsercontrolpaneold-dispatch-range-audit.md`
- Safety: This file must never be executed, replayed, or used as an operational runbook.
- Credit: This archive provides no gate, score, coverage, IDA, validator, or lifecycle credit.

# Removed Executable Code Archive

- Source report: [0001CO-browsercontrolpaneold-dispatch-range-audit.md](0001CO-browsercontrolpaneold-dispatch-range-audit.md)
- Source report SHA256 before cleanup: `81524147E559C32B63516847E306CBD5A068E903A5EE657486ABFC3AAD7150AB`
- Cleanup generated: `2026-08-11T12:46:57Z`
- Removed executable blocks: `2`
- Scope: exact executable or command-shaped fenced blocks removed from the source report by supervisor housekeeping.
- Authority: this file is not a B-agent research report and grants no Gate 1, Gate 2, IDA, validator, score, or lifecycle credit.
- Safety: do not execute, import, evaluate, or use any block in this archive as an operational instruction.

## Removed Block R001

- Original source lines: `401-411`
- Original language: `powershell`
- Block SHA256: `7068A98CC7CECE23511D0E223C9056C457B52CA30F5DB6C7841B0D3EA9279977`

```powershell
python .\tools\validator.py --mode file --file by-memory\0x00528de0-0x00528dec.BrowserControlPaneOldDispatch.md --apply --lock-timeout -1
python .\tools\validator.py --mode file --file by-class\BrowserControlPaneOld.md --apply --lock-timeout -1
python .\tools\validator.py --mode file --file by-file\Browser.md --apply --lock-timeout -1
python .\tools\validator.py --mode file --file by-memory\0x00528d60-0x00528e55.MSGHandler.md --apply --lock-timeout -1
python .\tools\validator.py --mode file --file by-memory\0x0046f310-0x0046f47b.BrowserControlPaneOldHandleBrowserMessage.md --apply --lock-timeout -1
python .\tools\validator.py --mode file --file by-memory\-coverage-report.md --apply --lock-timeout -1
python .\tools\validator.py --mode autogen --apply --lock-timeout -1
python .\tools\memory_ranges.py report
python .\tools\unresolved.py --mode full --apply
```

## Removed Block R002

- Original source lines: `415-418`
- Original language: `powershell`
- Block SHA256: `63934139D4D7AB77CDFF21E118C78F63C1D5877F327A3A956F589FB0FE2B4295`

```powershell
rg -n "00528de0-0x00528deb|0x00528de0-0x00528deb" by-memory by-class by-file by-project-structure auto-generated project-level
rg -n "0001CO|00528de0-0x00528dec|BrowserControlPaneOldDispatch" by-memory\-coverage-report.md auto-generated\-ag-memory-coverage.md by-class\BrowserControlPaneOld.md by-file\Browser.md
```
