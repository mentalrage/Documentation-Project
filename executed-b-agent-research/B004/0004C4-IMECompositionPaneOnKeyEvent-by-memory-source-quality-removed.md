<!-- REMOVED-MATERIAL-ARCHIVE -->
# Removed Material Archive

- Status: Non-authoritative archival material only.
- Source report: `E:\NTK\GhidraBridge\source-3\project-documentation\executed-b-agent-research\B004\0004C4-IMECompositionPaneOnKeyEvent-by-memory-source-quality.md`
- Safety: This file must never be executed, replayed, or used as an operational runbook.
- Credit: This archive provides no gate, score, coverage, IDA, validator, or lifecycle credit.

# Removed Executable Code Archive

- Source report: [0004C4-IMECompositionPaneOnKeyEvent-by-memory-source-quality.md](0004C4-IMECompositionPaneOnKeyEvent-by-memory-source-quality.md)
- Source report SHA256 before cleanup: `C53082387DC4B3AAF707B68231F65046DE237F40D2270B16EA33A04FC0FE915A`
- Cleanup generated: `2026-08-11T12:47:08Z`
- Removed executable blocks: `1`
- Scope: exact executable or command-shaped fenced blocks removed from the source report by supervisor housekeeping.
- Authority: this file is not a B-agent research report and grants no Gate 1, Gate 2, IDA, validator, score, or lifecycle credit.
- Safety: do not execute, import, evaluate, or use any block in this archive as an operational instruction.

## Removed Block R001

- Original source lines: `287-299`
- Original language: `powershell`
- Block SHA256: `851521834EE8C37526E3E7DC97E06E263EF8B655883BF0D4881AF18F867F2860`

```powershell
python .\tools\validator.py --mode file --file by-memory/0x004e7810-0x004e7838.IMECompositionPaneOnKeyEvent.md --apply --wait-generated --queue-timeout 240
# command_id: 000000004097; command_timestamp: 2026-07-01T17:45:08-04:00; ok: 1; generated_refresh: completed

python .\tools\validator.py --mode file --file by-class/IMECompositionPane.md --apply --wait-generated --queue-timeout 240
# command_id: 000000004098; command_timestamp: 2026-07-01T17:45:23-04:00; ok: 1; generated_refresh: completed

python .\tools\validator.py --mode file --file by-file/IMEPanes.md --apply --wait-generated --queue-timeout 240
# command_id: 000000004099; command_timestamp: 2026-07-01T17:45:37-04:00; ok: 1; generated_refresh: completed

python .\tools\validator.py --mode file --file by-memory/0x004e70f0-0x004e8433.IMEPaneFamily.md --apply --wait-generated --queue-timeout 240
# command_id: 000000004100; command_timestamp: 2026-07-01T17:45:51-04:00; ok: 1; generated_refresh: completed
```
