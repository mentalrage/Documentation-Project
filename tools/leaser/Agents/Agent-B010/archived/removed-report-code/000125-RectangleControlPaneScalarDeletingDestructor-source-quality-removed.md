<!-- REMOVED-MATERIAL-ARCHIVE -->
# Removed Material Archive

- Status: Non-authoritative archival material only.
- Source report: `E:\NTK\GhidraBridge\source-3\project-documentation\executed-b-agent-research\B007\000125-RectangleControlPaneScalarDeletingDestructor-source-quality.md`
- Safety: This file must never be executed, replayed, or used as an operational runbook.
- Credit: This archive provides no gate, score, coverage, IDA, validator, or lifecycle credit.

# Removed Executable Code Archive

- Source report: [000125-RectangleControlPaneScalarDeletingDestructor-source-quality.md](000125-RectangleControlPaneScalarDeletingDestructor-source-quality.md)
- Source report SHA256 before cleanup: `FA565ED23CDB12B97B971E885A3EB0C16C6B6E7FD4FD254364A7ED7CBB31049D`
- Cleanup generated: `2026-08-11T12:47:15Z`
- Removed executable blocks: `1`
- Scope: exact executable or command-shaped fenced blocks removed from the source report by supervisor housekeeping.
- Authority: this file is not a B-agent research report and grants no Gate 1, Gate 2, IDA, validator, score, or lifecycle credit.
- Safety: do not execute, import, evaluate, or use any block in this archive as an operational instruction.

## Removed Block R001

- Original source lines: `359-367`
- Original language: `powershell`
- Block SHA256: `87137890657F0960073AA179D41070CE939D8D393FA8F2B2DDB187B0DEBD7714`

```powershell
cd E:\NTK\GhidraBridge\source-3\project-documentation
python .\tools\validator.py --mode file --file by-memory\0x0049b490-0x0049b4e5.RectangleControlPaneScalarDeletingDestructor.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-class\RectangleControlPane.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-file\RectangleControlPane.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-memory\0x00499c60-0x00499d37.RectangleControlPaneCore.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-memory\0x0049afc1-0x0049afd7.RectangleControlPaneAdjustorThunks.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-memory\0x0049af11-0x0049b8d5.ButtonChoiceControlDestructors.md --apply --queue-timeout 240
```
