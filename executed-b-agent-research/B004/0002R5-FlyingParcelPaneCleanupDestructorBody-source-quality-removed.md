<!-- REMOVED-MATERIAL-ARCHIVE -->
# Removed Material Archive

- Status: Non-authoritative archival material only.
- Source report: `E:\NTK\GhidraBridge\source-3\project-documentation\executed-b-agent-research\B004\0002R5-FlyingParcelPaneCleanupDestructorBody-source-quality.md`
- Safety: This file must never be executed, replayed, or used as an operational runbook.
- Credit: This archive provides no gate, score, coverage, IDA, validator, or lifecycle credit.

# Removed Executable Code Archive

- Source report: [0002R5-FlyingParcelPaneCleanupDestructorBody-source-quality.md](0002R5-FlyingParcelPaneCleanupDestructorBody-source-quality.md)
- Source report SHA256 before cleanup: `D26CBB57C20C21BB085AC6BA061910A04617938E93F379BFC73426D5F447344D`
- Cleanup generated: `2026-08-11T12:47:07Z`
- Removed executable blocks: `1`
- Scope: exact executable or command-shaped fenced blocks removed from the source report by supervisor housekeeping.
- Authority: this file is not a B-agent research report and grants no Gate 1, Gate 2, IDA, validator, score, or lifecycle credit.
- Safety: do not execute, import, evaluate, or use any block in this archive as an operational instruction.

## Removed Block R001

- Original source lines: `400-410`
- Original language: `powershell`
- Block SHA256: `E623E9B0769A3C16473BFA27CB5C7CDCC424843D17EA20010C3C0D61861BA136`

```powershell
python .\tools\validator.py --mode file --file by-memory\0x00546b80-0x00546bb5.FlyingParcelPaneCleanupDestructorBody.md --apply --wait-generated --queue-timeout 240
python .\tools\validator.py --mode file --file by-class\FlyingParcelPane.md --apply --wait-generated --queue-timeout 240
python .\tools\validator.py --mode file --file by-file\ParcelPane.md --apply --wait-generated --queue-timeout 240
python .\tools\validator.py --mode file --file by-memory\0x00546b80-0x00546d64.FlyingParcelPaneRawLifecycleAndStart.md --apply --wait-generated --queue-timeout 240
python .\tools\validator.py --mode file --file by-memory\0x00546ed0-0x00546f37.FlyingParcelPaneScalarDeletingDestructor.md --apply --wait-generated --queue-timeout 240
python .\tools\validator.py --mode file --file by-type\by-struct\ParcelNotificationPaneLayouts.md --apply --wait-generated --queue-timeout 240
python .\tools\validator.py --mode file --file by-memory\0x00621bb0-0x00621d50.ParcelNotificationVtableData.md --apply --wait-generated --queue-timeout 240
python .\tools\validator.py --mode file --file by-type\by-vtable\ParcelNotificationVtableFamily.md --apply --wait-generated --queue-timeout 240
python .\tools\validator.py --mode file --file by-memory\0x00546d70-0x00546dee.FlyingParcelPaneAnimateStep.md --apply --wait-generated --queue-timeout 240
```
