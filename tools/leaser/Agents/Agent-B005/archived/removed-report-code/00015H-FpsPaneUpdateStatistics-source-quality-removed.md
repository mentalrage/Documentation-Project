<!-- REMOVED-MATERIAL-ARCHIVE -->
# Removed Material Archive

- Status: Non-authoritative archival material only.
- Source report: `E:\NTK\GhidraBridge\source-3\project-documentation\executed-b-agent-research\B005\00015H-FpsPaneUpdateStatistics-source-quality.md`
- Safety: This file must never be executed, replayed, or used as an operational runbook.
- Credit: This archive provides no gate, score, coverage, IDA, validator, or lifecycle credit.

# Removed Executable Code Archive

- Source report: [00015H-FpsPaneUpdateStatistics-source-quality.md](00015H-FpsPaneUpdateStatistics-source-quality.md)
- Source report SHA256 before cleanup: `FB415B44FFFF41D2258E1F9DE7AB3F1F700E9C7B4628CA111EFB06A450B179A1`
- Cleanup generated: `2026-08-11T12:47:08Z`
- Removed executable blocks: `2`
- Scope: exact executable or command-shaped fenced blocks removed from the source report by supervisor housekeeping.
- Authority: this file is not a B-agent research report and grants no Gate 1, Gate 2, IDA, validator, score, or lifecycle credit.
- Safety: do not execute, import, evaluate, or use any block in this archive as an operational instruction.

## Removed Block R001

- Original source lines: `430-434`
- Original language: `powershell`
- Block SHA256: `AE68867B6FB77A5011CFE0A01B59E8D242D5BEE4DF40779FA00E2C30336F3F76`

```powershell
python tools\validator.py --mode file --file by-memory\0x004b68b0-0x004b69b0.FpsPaneUpdateStatistics.md --apply --queue-timeout 240
python tools\validator.py --mode file --file by-class\FpsPane.md --apply --queue-timeout 240
python tools\validator.py --mode file --file by-file\FpsPane.md --apply --queue-timeout 240
```

## Removed Block R002

- Original source lines: `438-448`
- Original language: `powershell`
- Block SHA256: `B1206367EC04DF911E63CEA0C0E3E326B765FB9547BFC5B28B801097B92B0747`

```powershell
python tools\validator.py --mode file --file by-type\by-struct\FpsPaneLayout.md --apply --queue-timeout 240
python tools\validator.py --mode file --file by-type\by-vtable\FpsPane_vtables.md --apply --queue-timeout 240
python tools\validator.py --mode file --file by-memory\0x0061a61c-0x0061a6a4.FpsPaneVtableData.md --apply --queue-timeout 240
python tools\validator.py --mode file --file by-global\g_activeMapPane.md --apply --queue-timeout 240
python tools\validator.py --mode file --file by-memory\0x0067a764-0x0067a768.ActiveMapPaneSingleton.md --apply --queue-timeout 240
python tools\validator.py --mode file --file by-memory\0x005051c0-0x00505228.DrawVisibleTilesHelper.md --apply --queue-timeout 240
python tools\validator.py --mode file --file by-memory\0x00532530-0x00532f67.ObjectListAccessorsAndSweeps.md --apply --queue-timeout 240
python tools\validator.py --mode file --file by-memory\0x00532530-0x0053272e.MapPaneSpatialIndex.md --apply --queue-timeout 240
python tools\validator.py --mode file --file by-memory\0x005975e0-0x0059760d.TimerHandlerScheduleRemoveWrappers.md --apply --queue-timeout 240
```
