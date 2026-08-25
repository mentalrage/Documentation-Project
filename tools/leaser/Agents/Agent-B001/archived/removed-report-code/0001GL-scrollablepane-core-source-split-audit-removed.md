<!-- REMOVED-MATERIAL-ARCHIVE -->
# Removed Material Archive

- Status: Non-authoritative archival material only.
- Source report: `E:\NTK\GhidraBridge\source-3\project-documentation\executed-b-agent-research\B001\0001GL-scrollablepane-core-source-split-audit.md`
- Safety: This file must never be executed, replayed, or used as an operational runbook.
- Credit: This archive provides no gate, score, coverage, IDA, validator, or lifecycle credit.

# Removed Executable Code Archive

- Source report: [0001GL-scrollablepane-core-source-split-audit.md](0001GL-scrollablepane-core-source-split-audit.md)
- Source report SHA256 before cleanup: `DCA14726625B0843513E966D46B424D4ACB8CFAF0ED0FB3769C5EE9223294B6F`
- Cleanup generated: `2026-08-11T12:46:57Z`
- Removed executable blocks: `1`
- Scope: exact executable or command-shaped fenced blocks removed from the source report by supervisor housekeeping.
- Authority: this file is not a B-agent research report and grants no Gate 1, Gate 2, IDA, validator, score, or lifecycle credit.
- Safety: do not execute, import, evaluate, or use any block in this archive as an operational instruction.

## Removed Block R001

- Original source lines: `348-357`
- Original language: `powershell`
- Block SHA256: `F00CE16F29E64FF6BD5E60A23CD10D484D5C563547D26A367B7B6379961D2662`

```powershell
cd E:\NTK\GhidraBridge\source-3\project-documentation
python .\tools\validator.py --mode file --file by-memory\0x0055e660-0x0055f44f.ScrollablePaneCore.md --apply
python .\tools\validator.py --mode file --file by-class\ScrollablePane.md --apply
python .\tools\validator.py --mode file --file by-file\ScrollBar.md --apply
python .\tools\validator.py --mode file --file by-memory\0x004985a0-0x004988cc.ScrollableControlPaneCore.md --apply
python .\tools\validator.py --mode file --file by-memory\0x0055d960-0x005654ec.TextEditPaneScrollbarVariants.md --apply
python .\tools\validator.py --mode documented --remove-missing --apply
python .\tools\memory_ranges.py report
```
