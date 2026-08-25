<!-- REMOVED-MATERIAL-ARCHIVE -->
# Removed Material Archive

- Status: Non-authoritative archival material only.
- Source report: `E:\NTK\GhidraBridge\source-3\project-documentation\executed-b-agent-research\B009\0001BI-Memmove0Wrapper-source-quality.md`
- Safety: This file must never be executed, replayed, or used as an operational runbook.
- Credit: This archive provides no gate, score, coverage, IDA, validator, or lifecycle credit.

# Removed Executable Code Archive

- Source report: [0001BI-Memmove0Wrapper-source-quality.md](0001BI-Memmove0Wrapper-source-quality.md)
- Source report SHA256 before cleanup: `45F8316C83B46A3A3590EC76D5DBF8E2688758B7A96E07F11EC28082AD5E9A0D`
- Cleanup generated: `2026-08-11T12:47:14Z`
- Removed executable blocks: `1`
- Scope: exact executable or command-shaped fenced blocks removed from the source report by supervisor housekeeping.
- Authority: this file is not a B-agent research report and grants no Gate 1, Gate 2, IDA, validator, score, or lifecycle credit.
- Safety: do not execute, import, evaluate, or use any block in this archive as an operational instruction.

## Removed Block R001

- Original source lines: `453-461`
- Original language: `powershell`
- Block SHA256: `3703609BE548C6626A28B2CC73A8620A726037232EBBAC21887F004FE2C64F36`

```powershell
python .\tools\validator.py --mode file --file by-memory\0x00516240-0x00516258.Memmove0Wrapper.md --apply --queue-timeout 240 --wait-generated
python .\tools\validator.py --mode file --file by-class\MemoryMan.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-file\MemoryMan.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-memory\0x00516000-0x0051628e.MemoryManAndAllocationHelpers.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-global\MemoryAllocationHelpers.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-type\by-struct\MemoryManLayout.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-memory\0x00516220-0x00516238.MemmoveWrapper.md --apply --queue-timeout 240  # only if B009 edits the sibling relationship/status note
```
