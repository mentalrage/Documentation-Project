<!-- REMOVED-MATERIAL-ARCHIVE -->
# Removed Material Archive

- Status: Non-authoritative archival material only.
- Source report: `E:\NTK\GhidraBridge\source-3\project-documentation\executed-b-agent-research\B001\0002T2-IconsPaneOnMouseEvent-source-quality.md`
- Safety: This file must never be executed, replayed, or used as an operational runbook.
- Credit: This archive provides no gate, score, coverage, IDA, validator, or lifecycle credit.

# Removed Executable Code Archive

- Source report: [0002T2-IconsPaneOnMouseEvent-source-quality.md](0002T2-IconsPaneOnMouseEvent-source-quality.md)
- Source report SHA256 before cleanup: `5AC9AE92305D89B9321D6EA39CB50CA803FD7C34E6EF424FA9DE126474CDB5F4`
- Cleanup generated: `2026-08-11T12:46:59Z`
- Removed executable blocks: `1`
- Scope: exact executable or command-shaped fenced blocks removed from the source report by supervisor housekeeping.
- Authority: this file is not a B-agent research report and grants no Gate 1, Gate 2, IDA, validator, score, or lifecycle credit.
- Safety: do not execute, import, evaluate, or use any block in this archive as an operational instruction.

## Removed Block R001

- Original source lines: `413-419`
- Original language: `powershell`
- Block SHA256: `8B06AC649E42C0C0545D60603F2422C37B2BB4FE019B0ECB44C6D8D3437E0159`

```powershell
python .\tools\validator.py --mode file --file "by-memory\0x004cf3e0-0x004cf74b.IconsPaneOnMouseEvent.md" --apply --wait-generated --queue-timeout 240
python .\tools\validator.py --mode file --file "by-class\IconsPane.md" --apply --wait-generated --queue-timeout 240
python .\tools\validator.py --mode file --file "by-file\IconsPane.md" --apply --wait-generated --queue-timeout 240
python .\tools\validator.py --mode file --file "by-memory\0x004cf1f0-0x004cf8d5.IconsPaneCore.md" --apply --wait-generated --queue-timeout 240
python .\tools\validator.py --mode file --file "by-file\IconsPane.md" --apply --wait-generated --queue-timeout 240
```
