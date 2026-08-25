<!-- REMOVED-MATERIAL-ARCHIVE -->
# Removed Material Archive

- Status: Non-authoritative archival material only.
- Source report: `E:\NTK\GhidraBridge\source-3\project-documentation\executed-b-agent-research\B005\0001AN-MiniMapButtonPaneClearAndThunks-source-quality.md`
- Safety: This file must never be executed, replayed, or used as an operational runbook.
- Credit: This archive provides no gate, score, coverage, IDA, validator, or lifecycle credit.

# Removed Executable Code Archive

- Source report: [0001AN-MiniMapButtonPaneClearAndThunks-source-quality.md](0001AN-MiniMapButtonPaneClearAndThunks-source-quality.md)
- Source report SHA256 before cleanup: `9AFDA5BC0CBB1B35FA3A69AE20693597F609805A1CAA3163BD474D7D513516F5`
- Cleanup generated: `2026-08-11T12:47:08Z`
- Removed executable blocks: `1`
- Scope: exact executable or command-shaped fenced blocks removed from the source report by supervisor housekeeping.
- Authority: this file is not a B-agent research report and grants no Gate 1, Gate 2, IDA, validator, score, or lifecycle credit.
- Safety: do not execute, import, evaluate, or use any block in this archive as an operational instruction.

## Removed Block R001

- Original source lines: `339-352`
- Original language: `powershell`
- Block SHA256: `81C2DFDA7B487C77CF701D9B62CC5574D9A396A7326C91408D6BF7485E7266C5`

```powershell
python .\tools\validator\validate_docs.py --apply --queue-timeout 240 `
  by-memory\0x00503800-0x00503837.MiniMapButtonPaneClearAndThunks.md `
  by-memory\0x00503800-0x0050380b.MiniMapButtonPaneClearSingleton.md `
  by-memory\0x00503821-0x00503837.MiniMapButtonPaneDestructorAdjustorThunks.md `
  by-memory\0x00503900-0x0050395f.MiniMapButtonPaneScalarDeletingDestructor.md `
  by-memory\0x00503620-0x00503649.MiniMapButtonPaneCleanup.md `
  by-class\MiniMapButtonPane.md `
  by-file\MiniMap.md `
  by-global\g_pMiniMapButtonPane.md `
  by-memory\0x0069b4b8-0x0069b4bc.g_pMiniMapButtonPane.md `
  by-memory\0x005031f0-0x0050395f.MapNameAndMiniMapButtonPanes.md `
  by-memory\0x0061e63c-0x0061e6c0.MiniMapButtonPaneVtableData.md
```
