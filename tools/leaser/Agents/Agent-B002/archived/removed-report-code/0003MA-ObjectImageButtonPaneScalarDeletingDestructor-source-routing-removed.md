<!-- REMOVED-MATERIAL-ARCHIVE -->
# Removed Material Archive

- Status: Non-authoritative archival material only.
- Source report: `E:\NTK\GhidraBridge\source-3\project-documentation\executed-b-agent-research\B002\0003MA-ObjectImageButtonPaneScalarDeletingDestructor-source-routing.md`
- Safety: This file must never be executed, replayed, or used as an operational runbook.
- Credit: This archive provides no gate, score, coverage, IDA, validator, or lifecycle credit.

# Removed Executable Code Archive

- Source report: [0003MA-ObjectImageButtonPaneScalarDeletingDestructor-source-routing.md](0003MA-ObjectImageButtonPaneScalarDeletingDestructor-source-routing.md)
- Source report SHA256 before cleanup: `5344A46D263F88ADE568079A28A666DE297ADEA490B49A6F6460969816FA316F`
- Cleanup generated: `2026-08-11T12:47:02Z`
- Removed executable blocks: `1`
- Scope: exact executable or command-shaped fenced blocks removed from the source report by supervisor housekeeping.
- Authority: this file is not a B-agent research report and grants no Gate 1, Gate 2, IDA, validator, score, or lifecycle credit.
- Safety: do not execute, import, evaluate, or use any block in this archive as an operational instruction.

## Removed Block R001

- Original source lines: `536-547`
- Original language: `powershell`
- Block SHA256: `CCED8D3062BF5F1032008048BFA79C8CD0CEDC3B9D1296EEDDE847C3EC32E05D`

```powershell
python .\tools\validator.py --mode file --file .\by-memory\0x00520c60-0x00520c9b.ObjectImageButtonPaneScalarDeletingDestructor.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file .\by-memory\0x00520ae7-0x00520afd.ObjectImageButtonPaneDestructorThunks.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file .\by-class\ObjectImageButtonPane.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file .\by-class\ObjectImageControlPane.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file .\by-file\ObjectImageControlPane.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file .\by-memory\0x00520820-0x00520a90.ObjectImageButtonPaneCore.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file .\by-memory\0x00520abb-0x00520e2b.MenuDialogDestructorThunks.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file .\by-memory\0x0061ec10-0x0061fa3c.MerchantMenuDialogReadOnlyData.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file .\by-file\SpecializedButtonPanes.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file .\by-memory\-ignored.md --apply --queue-timeout 240
```
