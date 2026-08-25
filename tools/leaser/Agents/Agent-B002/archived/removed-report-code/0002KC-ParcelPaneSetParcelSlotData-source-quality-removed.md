<!-- REMOVED-MATERIAL-ARCHIVE -->
# Removed Material Archive

- Status: Non-authoritative archival material only.
- Source report: `E:\NTK\GhidraBridge\source-3\project-documentation\executed-b-agent-research\B002\0002KC-ParcelPaneSetParcelSlotData-source-quality.md`
- Safety: This file must never be executed, replayed, or used as an operational runbook.
- Credit: This archive provides no gate, score, coverage, IDA, validator, or lifecycle credit.

# Removed Executable Code Archive

- Source report: [0002KC-ParcelPaneSetParcelSlotData-source-quality.md](0002KC-ParcelPaneSetParcelSlotData-source-quality.md)
- Source report SHA256 before cleanup: `2E27D8E68529B9E61496AEB4179ED8412C3FD92588E770E7F2DA24DEA091D67C`
- Cleanup generated: `2026-08-11T12:47:02Z`
- Removed executable blocks: `1`
- Scope: exact executable or command-shaped fenced blocks removed from the source report by supervisor housekeeping.
- Authority: this file is not a B-agent research report and grants no Gate 1, Gate 2, IDA, validator, score, or lifecycle credit.
- Safety: do not execute, import, evaluate, or use any block in this archive as an operational instruction.

## Removed Block R001

- Original source lines: `234-239`
- Original language: `powershell`
- Block SHA256: `278FA65CB946CDFC6F0A7E4A374C351FB5765B9211D726C76E29107B30A85886`

```powershell
python .\tools\validator.py --mode file --file by-memory\0x005464b0-0x00546575.ParcelPaneSetParcelSlotData.md --apply --queue-timeout 240 --wait-generated
python .\tools\validator.py --mode file --file by-class\ParcelPane.md --apply --queue-timeout 240 --wait-generated
python .\tools\validator.py --mode file --file by-file\ParcelPane.md --apply --queue-timeout 240 --wait-generated
python .\tools\validator.py --mode file --file by-type\by-struct\ParcelNotificationPaneLayouts.md --apply --queue-timeout 240 --wait-generated
```
