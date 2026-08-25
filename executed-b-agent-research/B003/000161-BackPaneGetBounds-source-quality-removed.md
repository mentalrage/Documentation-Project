<!-- REMOVED-MATERIAL-ARCHIVE -->
# Removed Material Archive

- Status: Non-authoritative archival material only.
- Source report: `E:\NTK\GhidraBridge\source-3\project-documentation\executed-b-agent-research\B003\000161-BackPaneGetBounds-source-quality.md`
- Safety: This file must never be executed, replayed, or used as an operational runbook.
- Credit: This archive provides no gate, score, coverage, IDA, validator, or lifecycle credit.

# Removed Executable Code Archive

- Source report: [000161-BackPaneGetBounds-source-quality.md](000161-BackPaneGetBounds-source-quality.md)
- Source report SHA256 before cleanup: `17F34AA4770B4607C777D9C578D94513EDC16889D52BB967DB0D589DC1BAB7A8`
- Cleanup generated: `2026-08-11T12:47:03Z`
- Removed executable blocks: `3`
- Scope: exact executable or command-shaped fenced blocks removed from the source report by supervisor housekeeping.
- Authority: this file is not a B-agent research report and grants no Gate 1, Gate 2, IDA, validator, score, or lifecycle credit.
- Safety: do not execute, import, evaluate, or use any block in this archive as an operational instruction.

## Removed Block R001

- Original source lines: `550-555`
- Original language: `powershell`
- Block SHA256: `2AEE716D65107D6C656A0640420BAE9E2989247467DA1B8E94E00DBE8E717838`

```powershell
rg "000161|0x004b8e00|BackPane::GetBounds|BackPaneGetBounds" E:\NTK\GhidraBridge\source-3\project-documentation
rg "below 95|blank formal C\+\+|deferred" E:\NTK\GhidraBridge\source-3\project-documentation\by-memory\0x004b8e00-0x004b8e11.BackPaneGetBounds.md
rg "BackPane::GetBounds" E:\NTK\GhidraBridge\source-3\project-documentation\by-class\BackPane.md E:\NTK\GhidraBridge\source-3\project-documentation\by-file\BackPane.md
rg "000161" E:\NTK\GhidraBridge\source-3\project-documentation\by-memory\-coverage-report.md E:\NTK\GhidraBridge\source-3\project-documentation\project-level\-auto-completion-stats.md
```

## Removed Block R002

- Original source lines: `559-562`
- Original language: `powershell`
- Block SHA256: `7A8D62B27BCDE5501B52A8723103D3678E3C27A38B7FD459EF79D5A09CBC6DAF`

```powershell
# Confirm bytes at file raw offset 0x000b8200 in E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe:
# expected: 55 8b ec 8b 45 08 0f 10 41 44 0f 11 00 5d c2 04 00
```


## Removed Block R003

- Source report SHA256 before this cleanup pass: `94241BDAF2DA766DFE1F374BA1C8F54BDE0985B82DE21AE4DB6A614880E17582`
- Original source lines: `72-74`
- Original language: `text`
- Block SHA256: `E57A36F2555C7708F1D48C8F44A179620AC48FF61B0A575E112C70F57F87806B`

```text
rg "000161|0x004b8e00|BackPaneGetBounds|BackPane::GetBounds|GetBounds" tools/leaser/Agents -g "*.md"
```
