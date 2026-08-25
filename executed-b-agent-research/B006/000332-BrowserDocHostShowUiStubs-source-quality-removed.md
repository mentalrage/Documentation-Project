<!-- REMOVED-MATERIAL-ARCHIVE -->
# Removed Material Archive

- Status: Non-authoritative archival material only.
- Source report: `E:\NTK\GhidraBridge\source-3\project-documentation\executed-b-agent-research\B006\000332-BrowserDocHostShowUiStubs-source-quality.md`
- Safety: This file must never be executed, replayed, or used as an operational runbook.
- Credit: This archive provides no gate, score, coverage, IDA, validator, or lifecycle credit.

# Removed Executable Code Archive

- Source report: [000332-BrowserDocHostShowUiStubs-source-quality.md](000332-BrowserDocHostShowUiStubs-source-quality.md)
- Source report SHA256 before cleanup: `F397B639F7914E1869D78C6D8F8CCF5E523FD679C4D6E81F9F71D8A5DDC65935`
- Cleanup generated: `2026-08-11T12:47:11Z`
- Removed executable blocks: `1`
- Scope: exact executable or command-shaped fenced blocks removed from the source report by supervisor housekeeping.
- Authority: this file is not a B-agent research report and grants no Gate 1, Gate 2, IDA, validator, score, or lifecycle credit.
- Safety: do not execute, import, evaluate, or use any block in this archive as an operational instruction.

## Removed Block R001

- Original source lines: `403-411`
- Original language: `powershell`
- Block SHA256: `2CD33BF721DCF61C11AA42106A49D271D21618CE0FB92940DB9C62D5707DA338`

```powershell
python .\tools\validator.py --mode file --file by-memory\0x0046fb80-0x0046fca5.BrowserDocHostShowUiStubs.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-class\Browser.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-memory\0x0046f540-0x0046f66f.BrowserQueryInterface.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-memory\0x006131b4-0x006139df.BrowserVtablesAndStrings.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-file\Browser.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-memory\0x00631580-0x00631660.BrowserComGuidConstants.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-memory\0x0046f010-0x004710b8.BrowserOleLegacyAndHelpers.md --apply --queue-timeout 240
```
