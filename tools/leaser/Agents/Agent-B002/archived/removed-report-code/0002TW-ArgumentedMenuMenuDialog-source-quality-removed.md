<!-- REMOVED-MATERIAL-ARCHIVE -->
# Removed Material Archive

- Status: Non-authoritative archival material only.
- Source report: `E:\NTK\GhidraBridge\source-3\project-documentation\executed-b-agent-research\B002\0002TW-ArgumentedMenuMenuDialog-source-quality.md`
- Safety: This file must never be executed, replayed, or used as an operational runbook.
- Credit: This archive provides no gate, score, coverage, IDA, validator, or lifecycle credit.

# Removed Executable Code Archive

- Source report: [0002TW-ArgumentedMenuMenuDialog-source-quality.md](0002TW-ArgumentedMenuMenuDialog-source-quality.md)
- Source report SHA256 before cleanup: `4798179B03BB10187CC72AFC5EB3B9BBC5613E71E2CE9FC6E5B1F791B6602998`
- Cleanup generated: `2026-08-11T12:47:02Z`
- Removed executable blocks: `1`
- Scope: exact executable or command-shaped fenced blocks removed from the source report by supervisor housekeeping.
- Authority: this file is not a B-agent research report and grants no Gate 1, Gate 2, IDA, validator, score, or lifecycle credit.
- Safety: do not execute, import, evaluate, or use any block in this archive as an operational instruction.

## Removed Block R001

- Original source lines: `465-471`
- Original language: `powershell`
- Block SHA256: `51992C519F90F634B53E214F9A9619C45904C143AEF5DDF6CC59C5C7F1036409`

```powershell
python .\tools\validator.py --mode file --file by-memory\0x0051e9a0-0x0051f28d.ArgumentedMenuMenuDialog.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-class\ArgumentedMenuMenuDialog.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-file\ArgumentedMenuDialogs.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-memory\0x0051e9a0-0x0051fc8d.ArgumentedMenuDialogs.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-type\by-vtable\ArgumentedMenuDialogVtables.md --apply --queue-timeout 240
```
