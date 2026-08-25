<!-- REMOVED-MATERIAL-ARCHIVE -->
# Removed Material Archive

- Status: Non-authoritative archival material only.
- Source report: `E:\NTK\GhidraBridge\source-3\project-documentation\executed-b-agent-research\B001\000194-listpane-source-split-audit.md`
- Safety: This file must never be executed, replayed, or used as an operational runbook.
- Credit: This archive provides no gate, score, coverage, IDA, validator, or lifecycle credit.

# Removed Executable Code Archive

- Source report: [000194-listpane-source-split-audit.md](000194-listpane-source-split-audit.md)
- Source report SHA256 before cleanup: `805902796032D47B18363DBE6AEE0B37932A1599EF472BD3AE88F17B870F16DC`
- Cleanup generated: `2026-08-11T12:46:56Z`
- Removed executable blocks: `1`
- Scope: exact executable or command-shaped fenced blocks removed from the source report by supervisor housekeeping.
- Authority: this file is not a B-agent research report and grants no Gate 1, Gate 2, IDA, validator, score, or lifecycle credit.
- Safety: do not execute, import, evaluate, or use any block in this archive as an operational instruction.

## Removed Block R001

- Original source lines: `624-637`
- Original language: `powershell`
- Block SHA256: `8B0FC4874212D715AEBD8B678D82BCA02B9EB8BF2E94C25BE9F364755F552A6F`

```powershell
python .\tools\validator.py --mode file --file by-memory\0x004f3a50-0x004f3bb0.ListPaneConstructionAndBaseDestructor.md --apply --lock-timeout -1
python .\tools\validator.py --mode file --file by-memory\0x004f3bb0-0x004f3f20.ListPaneItemSelectionStorageHelpers.md --apply --lock-timeout -1
python .\tools\validator.py --mode file --file by-memory\0x004f3f20-0x004f4190.ListPaneScrollMetricVirtuals.md --apply --lock-timeout -1
python .\tools\validator.py --mode file --file by-memory\0x004f4190-0x004f43e0.ListPaneInputKeyHandlersAndSwitchTables.md --apply --lock-timeout -1
python .\tools\validator.py --mode file --file by-memory\0x004f43e0-0x004f45b0.ListPanePaintHitTestGeometry.md --apply --lock-timeout -1
python .\tools\validator.py --mode file --file by-memory\0x004f45b0-0x004f4920.ListPaneSelectionNavigationRawClampHelpers.md --apply --lock-timeout -1
python .\tools\validator.py --mode file --file by-memory\0x004f4920-0x004f4a77.ListPaneEnsureVisibleDestructorThunks.md --apply --lock-timeout -1
python .\tools\validator.py --mode file --file by-memory\0x004f3a50-0x004f4a77.ListPane.md --apply --lock-timeout -1
python .\tools\validator.py --mode file --file by-file\ListPane.md --apply --lock-timeout -1
python .\tools\validator.py --mode file --file by-class\ListPane.md --apply --lock-timeout -1
python .\tools\validator.py --mode file --file by-memory\-coverage-report.md --apply --lock-timeout -1
python .\tools\memory_ranges.py report
```
