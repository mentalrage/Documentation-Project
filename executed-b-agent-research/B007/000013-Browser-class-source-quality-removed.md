<!-- REMOVED-MATERIAL-ARCHIVE -->
# Removed Material Archive

- Status: Non-authoritative archival material only.
- Source report: `E:\NTK\GhidraBridge\source-3\project-documentation\executed-b-agent-research\B007\000013-Browser-class-source-quality.md`
- Safety: This file must never be executed, replayed, or used as an operational runbook.
- Credit: This archive provides no gate, score, coverage, IDA, validator, or lifecycle credit.

# Removed Executable Code Archive

- Source report: [000013-Browser-class-source-quality.md](000013-Browser-class-source-quality.md)
- Source report SHA256 before cleanup: `6DD0FCF71A2B48BD729A27C0AF9ED64003E66FD98C21D8A80F83D28139BFDDAC`
- Cleanup generated: `2026-08-11T12:47:11Z`
- Removed executable blocks: `2`
- Scope: exact executable or command-shaped fenced blocks removed from the source report by supervisor housekeeping.
- Authority: this file is not a B-agent research report and grants no Gate 1, Gate 2, IDA, validator, score, or lifecycle credit.
- Safety: do not execute, import, evaluate, or use any block in this archive as an operational instruction.

## Removed Block R001

- Original source lines: `708-711`
- Original language: `powershell`
- Block SHA256: `0B64499A6AD2A5047C1ED8F5AB90BAD3DC6FFED01FDE6F23756611D09352D943`

```powershell
python .\tools\validator.py --mode file --file by-class\Browser.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-class\-coverage-report.md --apply --queue-timeout 240
```

## Removed Block R002

- Original source lines: `715-735`
- Original language: `powershell`
- Block SHA256: `A3CAD988084F9EAC4FC2D8904AE07B38EA2E170F229FE6B42B5EDE56A0E5F8DF`

```powershell
python .\tools\validator.py --mode file --file by-file\Browser.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-memory\0x0046f540-0x0046f66f.BrowserQueryInterface.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-memory\0x0046f670-0x0046f808.BrowserComStubMethods.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-memory\0x0046fb80-0x0046fca5.BrowserDocHostShowUiStubs.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-memory\0x0046f480-0x0046f53e.BrowserNonDeletingDestructor.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-memory\0x00470330-0x00470406.BrowserScalarDeletingDestructor.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-memory\0x0046f810-0x0046fb80.BrowserInvokeAndSwitchTable.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-memory\0x00470dd0-0x00470f10.BrowserNavigate.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-memory\0x00470fdc-0x0047107c.BrowserOleAdjustorAndDelegationThunks.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-memory\0x00613830-0x00613e18.BrowserVtablesAndStrings.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-memory\0x00631580-0x00631660.BrowserComGuidConstants.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-global\DIID_DWebBrowserEvents2.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-global\BrowserDispatchEventId.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-global\BrowserInitFlags.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-global\BrowserMessageId.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-class\BrowserWindow.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-class\BrowserControlPaneOld.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-class\BrowserThread.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-class\BrowserControlPane.md --apply --queue-timeout 240
```
