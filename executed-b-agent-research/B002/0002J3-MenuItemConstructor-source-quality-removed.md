<!-- REMOVED-MATERIAL-ARCHIVE -->
# Removed Material Archive

- Status: Non-authoritative archival material only.
- Source report: `E:\NTK\GhidraBridge\source-3\project-documentation\executed-b-agent-research\B002\0002J3-MenuItemConstructor-source-quality.md`
- Safety: This file must never be executed, replayed, or used as an operational runbook.
- Credit: This archive provides no gate, score, coverage, IDA, validator, or lifecycle credit.

# Removed Executable Code Archive

- Source report: [0002J3-MenuItemConstructor-source-quality.md](0002J3-MenuItemConstructor-source-quality.md)
- Source report SHA256 before cleanup: `8D84E219E1B81B6E4FE4870D3134557A5E9B86117704B429F67B021AA372613B`
- Cleanup generated: `2026-08-11T12:47:02Z`
- Removed executable blocks: `2`
- Scope: exact executable or command-shaped fenced blocks removed from the source report by supervisor housekeeping.
- Authority: this file is not a B-agent research report and grants no Gate 1, Gate 2, IDA, validator, score, or lifecycle credit.
- Safety: do not execute, import, evaluate, or use any block in this archive as an operational instruction.

## Removed Block R001

- Original source lines: `359-361`
- Original language: `powershell`
- Block SHA256: `6D9283A99469D409CF91272DC99B60DACEF1982E61C1789DE1B2A6693FD58C1E`

```powershell
'["0x67","0x18","0x14","0x04","0x10","0x0f","0x08","0x01","0x09"]' | python source-3\project-documentation\tools\int_convert.py --pretty
```

## Removed Block R002

- Original source lines: `365-368`
- Original language: `powershell`
- Block SHA256: `BBEC6AFC00EEF87EBD56989276AA4E992FDCFB8B68E69D629DC380731A2F26BC`

```powershell
rg -n "UID:0002J3|MenuItem::MenuItem|m_enabled|m_selected|InitRectBounds|0x00516ef0" source-3\project-documentation\by-memory source-3\project-documentation\by-class source-3\project-documentation\by-file source-3\project-documentation\auto-generated
rg -n "0002J3|0x00516f00-0x00516f67" source-3\project-documentation\by-memory\-coverage-report.md source-3\project-documentation\auto-generated\-ag-memory-coverage.md
```
