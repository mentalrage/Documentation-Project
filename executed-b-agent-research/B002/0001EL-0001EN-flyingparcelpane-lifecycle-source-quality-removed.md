<!-- REMOVED-MATERIAL-ARCHIVE -->
# Removed Material Archive

- Status: Non-authoritative archival material only.
- Source report: `E:\NTK\GhidraBridge\source-3\project-documentation\executed-b-agent-research\B002\0001EL-0001EN-flyingparcelpane-lifecycle-source-quality.md`
- Safety: This file must never be executed, replayed, or used as an operational runbook.
- Credit: This archive provides no gate, score, coverage, IDA, validator, or lifecycle credit.

# Removed Executable Code Archive

- Source report: [0001EL-0001EN-flyingparcelpane-lifecycle-source-quality.md](0001EL-0001EN-flyingparcelpane-lifecycle-source-quality.md)
- Source report SHA256 before cleanup: `C95C0508C41078AB14D5936ADA10340E0287482237431CE2D21DA0CD411355C3`
- Cleanup generated: `2026-08-11T12:47:01Z`
- Removed executable blocks: `1`
- Scope: exact executable or command-shaped fenced blocks removed from the source report by supervisor housekeeping.
- Authority: this file is not a B-agent research report and grants no Gate 1, Gate 2, IDA, validator, score, or lifecycle credit.
- Safety: do not execute, import, evaluate, or use any block in this archive as an operational instruction.

## Removed Block R001

- Original source lines: `414-427`
- Original language: `powershell`
- Block SHA256: `E7E87290DEFE127B977AA74882ED17B69EBE381CB1237EA318A05C17D22D4381`

```powershell
python .\tools\validator.py --mode file --file .\by-memory\0x00546b80-0x00546d64.FlyingParcelPaneRawLifecycleAndStart.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file .\by-memory\0x00546b80-0x00546bb5.FlyingParcelPaneCleanupDestructorBody.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file .\by-memory\0x00546bc0-0x00546d64.FlyingParcelPaneStartAnimation.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file .\by-memory\0x00546ed0-0x00546f37.FlyingParcelPaneScalarDeletingDestructor.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file .\by-class\FlyingParcelPane.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file .\by-file\ParcelPane.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file .\by-type\by-struct\ParcelNotificationPaneLayouts.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file .\by-memory\0x00621bb0-0x00621d50.ParcelNotificationVtableData.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file .\by-memory\-coverage-report.md --apply --queue-timeout 240
python .\tools\memory_ranges.py report
python .\tools\validator.py --mode autogen --apply --queue-timeout 240
python .\tools\validator.py --mode rescore --apply --queue-timeout 240
```
