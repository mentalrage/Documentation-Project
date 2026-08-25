<!-- REMOVED-MATERIAL-ARCHIVE -->
# Removed Material Archive

- Status: Non-authoritative archival material only.
- Source report: `E:\NTK\GhidraBridge\source-3\project-documentation\executed-b-agent-research\B014\0001A2-BackStoryDialogPaneCore-source-quality.md`
- Safety: This file must never be executed, replayed, or used as an operational runbook.
- Credit: This archive provides no gate, score, coverage, IDA, validator, or lifecycle credit.

# Removed Executable Code Archive

- Source report: [0001A2-BackStoryDialogPaneCore-source-quality.md](0001A2-BackStoryDialogPaneCore-source-quality.md)
- Source report SHA256 before cleanup: `C70077A28344B5A178372A720ED3A19B73CD971CC7260718E1A26D7D86578CDD`
- Cleanup generated: `2026-08-11T12:47:18Z`
- Removed executable blocks: `2`
- Scope: exact executable or command-shaped fenced blocks removed from the source report by supervisor housekeeping.
- Authority: this file is not a B-agent research report and grants no Gate 1, Gate 2, IDA, validator, score, or lifecycle credit.
- Safety: do not execute, import, evaluate, or use any block in this archive as an operational instruction.

## Removed Block R001

- Original source lines: `369-373`
- Original language: `powershell`
- Block SHA256: `163020DBEBE95FBFE6F580A927C1FFF9F713B9C4671C3DE96B53528CF66A44BE`

```powershell
rg -n "UID:0001A2|BackStoryDialogPaneCore|0x00500090|0x005003f0|g_pBackStoryDialogPane|BACKTALE|STORY\.EPF|STORY\.EPD" source-3/project-documentation
rg -n "g_pMainMenuPane|dword_69B36C|g_pMainUiGraph" source-3/project-documentation/by-class/BackStoryDialogPane.md source-3/project-documentation/by-file/BackStoryDialogPane.md source-3/project-documentation/by-memory/0x00500090-0x0050040d.BackStoryDialogPaneCore.md
rg -n "0001A2" source-3/project-documentation/by-memory/-coverage-report.md source-3/project-documentation/project-level/-auto-completion-stats.md source-3/project-documentation/auto-generated/-ag-memory-coverage.md
```

## Removed Block R002

- Original source lines: `388-392`
- Original language: `powershell`
- Block SHA256: `F4AC441AA0BB59E6EB90C379DA5FCD44EFB6D8A4DCEFA426C7373B0FC1CA1CAD`

```powershell
python source-3/project-documentation/tools/validators/validate_memory_doc.py source-3/project-documentation/by-memory/0x00500090-0x0050040d.BackStoryDialogPaneCore.md
python source-3/project-documentation/tools/validators/validate_emitters.py --uid 0001A2
python source-3/project-documentation/tools/validators/validate_coverage.py --uid 0001A2
```
