<!-- REMOVED-MATERIAL-ARCHIVE -->
# Removed Material Archive

- Status: Non-authoritative archival material only.
- Source report: `E:\NTK\GhidraBridge\source-3\project-documentation\executed-b-agent-research\B003\0002Z8-RainingLayerPaneVtableData-source-quality.md`
- Safety: This file must never be executed, replayed, or used as an operational runbook.
- Credit: This archive provides no gate, score, coverage, IDA, validator, or lifecycle credit.

# Removed Executable Code Archive

- Source report: [0002Z8-RainingLayerPaneVtableData-source-quality.md](0002Z8-RainingLayerPaneVtableData-source-quality.md)
- Source report SHA256 before cleanup: `29C057DBA7A71637053185E32D226E6A0EFE9053831C383112F52823A1DF966C`
- Cleanup generated: `2026-08-11T12:47:05Z`
- Removed executable blocks: `2`
- Scope: exact executable or command-shaped fenced blocks removed from the source report by supervisor housekeeping.
- Authority: this file is not a B-agent research report and grants no Gate 1, Gate 2, IDA, validator, score, or lifecycle credit.
- Safety: do not execute, import, evaluate, or use any block in this archive as an operational instruction.

## Removed Block R001

- Original source lines: `447-449`
- Original language: `powershell`
- Block SHA256: `D489D3A6A61E565EFAADBB96E82B37E5A2907AB15EFF58739C186039C89BEEB7`

```powershell
python .\tools\validator.py --mode file --file by-memory/0x0063121c-0x006312ac.RainingLayerPaneVtableData.md --apply --queue-timeout 240
```

## Removed Block R002

- Original source lines: `465-467`
- Original language: `powershell`
- Block SHA256: `341545078A4CDDBB700169C6A5D69E23314DFD5B455A19AF468E0B9403978CA5`

```powershell
python .\tools\validator.py --mode file --file by-class/RainingLayerPane.md --apply --queue-timeout 240
```
