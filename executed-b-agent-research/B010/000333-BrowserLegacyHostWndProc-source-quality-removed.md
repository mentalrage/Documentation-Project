<!-- REMOVED-MATERIAL-ARCHIVE -->
# Removed Material Archive

- Status: Non-authoritative archival material only.
- Source report: `E:\NTK\GhidraBridge\source-3\project-documentation\executed-b-agent-research\B010\000333-BrowserLegacyHostWndProc-source-quality.md`
- Safety: This file must never be executed, replayed, or used as an operational runbook.
- Credit: This archive provides no gate, score, coverage, IDA, validator, or lifecycle credit.

# Removed Executable Code Archive

- Source report: [000333-BrowserLegacyHostWndProc-source-quality.md](000333-BrowserLegacyHostWndProc-source-quality.md)
- Source report SHA256 before cleanup: `B0E0A98D6A441ADBD55C824A878C53356CBF3A567F36C875CB72FCE636AEC1CA`
- Cleanup generated: `2026-08-11T12:47:15Z`
- Removed executable blocks: `1`
- Scope: exact executable or command-shaped fenced blocks removed from the source report by supervisor housekeeping.
- Authority: this file is not a B-agent research report and grants no Gate 1, Gate 2, IDA, validator, score, or lifecycle credit.
- Safety: do not execute, import, evaluate, or use any block in this archive as an operational instruction.

## Removed Block R001

- Original source lines: `419-425`
- Original language: `powershell`
- Block SHA256: `D5877FE8A2DDBF99798F1B4783CA1B91EC622B864B842BF3166F2F264391003F`

```powershell
python .\tools\validator.py --mode file --file by-memory\0x0046fcb0-0x0046ff50.BrowserLegacyHostWndProc.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-global\g_pCurrentBrowserHost.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-memory\0x0067ab88-0x0067ab90.BrowserThreadHostGlobals.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-memory\0x00470a00-0x00470dc9.BrowserThreadInitializeBrowserHost.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-file\Browser.md --apply --queue-timeout 240
```
