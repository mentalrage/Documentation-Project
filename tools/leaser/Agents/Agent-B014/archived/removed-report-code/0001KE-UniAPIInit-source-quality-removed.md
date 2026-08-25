<!-- REMOVED-MATERIAL-ARCHIVE -->
# Removed Material Archive

- Status: Non-authoritative archival material only.
- Source report: `E:\NTK\GhidraBridge\source-3\project-documentation\executed-b-agent-research\B014\0001KE-UniAPIInit-source-quality.md`
- Safety: This file must never be executed, replayed, or used as an operational runbook.
- Credit: This archive provides no gate, score, coverage, IDA, validator, or lifecycle credit.

# Removed Executable Code Archive

- Source report: [0001KE-UniAPIInit-source-quality.md](0001KE-UniAPIInit-source-quality.md)
- Source report SHA256 before cleanup: `11EBD48EBA09B24A87EF73367D0DC5EA861F9B55DD4A7E9B25C1F0A954A2EF45`
- Cleanup generated: `2026-08-11T12:47:18Z`
- Removed executable blocks: `1`
- Scope: exact executable or command-shaped fenced blocks removed from the source report by supervisor housekeeping.
- Authority: this file is not a B-agent research report and grants no Gate 1, Gate 2, IDA, validator, score, or lifecycle credit.
- Safety: do not execute, import, evaluate, or use any block in this archive as an operational instruction.

## Removed Block R001

- Original source lines: `476-487`
- Original language: `powershell`
- Block SHA256: `1C919A44C7824A5C82A4CBF35BA3FFD36753B10CD5A85C764CFFE62F931F65EC`

```powershell
python .\tools\validator.py --mode file --file .\by-memory\0x005995b0-0x00599a34.UniAPIInit.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file .\by-memory\0x0041a280-0x0041a4a8.WideApiDispatchInit.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file .\by-class\UniAPIInit.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file .\by-file\PlatformApi.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file .\by-global\WideApiDispatchTable.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file .\by-memory\0x0060c440-0x0060c44b.UniAPIInitStaticCleanupWrapper.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file .\by-memory\0x006702c4-0x006702c8.UniAPIInitVtablePointerSlot.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file .\by-memory\0x0062e57c-0x0062e580.UniAPIInitVtableData.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file .\by-memory\0x00599440-0x005995a7.PlatformStringConversionHelpers.md --apply --queue-timeout 240
python .\tools\validator.py --mode autogen --apply --queue-timeout 240
```
