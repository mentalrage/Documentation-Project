<!-- REMOVED-MATERIAL-ARCHIVE -->
# Removed Material Archive

- Status: Non-authoritative archival material only.
- Source report: `E:\NTK\GhidraBridge\source-3\project-documentation\executed-b-agent-research\B014\000039-CopyWindow-class-source-quality.md`
- Safety: This file must never be executed, replayed, or used as an operational runbook.
- Credit: This archive provides no gate, score, coverage, IDA, validator, or lifecycle credit.

# Removed Executable Code Archive

- Source report: [000039-CopyWindow-class-source-quality.md](000039-CopyWindow-class-source-quality.md)
- Source report SHA256 before cleanup: `9123A4C868A5EFCBB4CA6B18691DF3DD0F512002DCD3BEAFF9E6D828CF2B7DBE`
- Cleanup generated: `2026-08-11T12:47:18Z`
- Removed executable blocks: `1`
- Scope: exact executable or command-shaped fenced blocks removed from the source report by supervisor housekeeping.
- Authority: this file is not a B-agent research report and grants no Gate 1, Gate 2, IDA, validator, score, or lifecycle credit.
- Safety: do not execute, import, evaluate, or use any block in this archive as an operational instruction.

## Removed Block R001

- Original source lines: `618-627`
- Original language: `powershell`
- Block SHA256: `E7FEA17D1B7B414D1165DCB790A8EDAF00BC646D4382575E86FC025203B03D5F`

```powershell
python .\tools\validator.py --mode file --file .\by-class\CopyWindow.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file .\by-file\CopyWindow.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file .\by-memory\0x005544c0-0x0055454b.CopyWindow.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file .\by-memory\0x00553e60-0x00553f36.ConnectionClosedDialogInitHelper.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file .\by-memory\0x00622e78-0x00622f1c.CopyWindowVtableData.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file .\by-memory\0x00622f3c-0x00622f44.CopyWindowNoButtonWideString.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file .\by-memory\0x00622f44-0x00622f4c.CopyWindowYesButtonWideString.md --apply --queue-timeout 240
python .\tools\validator.py --mode autogen --apply --queue-timeout 240
```
