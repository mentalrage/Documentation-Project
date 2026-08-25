<!-- REMOVED-MATERIAL-ARCHIVE -->
# Removed Material Archive

- Status: Non-authoritative archival material only.
- Source report: `E:\NTK\GhidraBridge\source-3\project-documentation\executed-b-agent-research\B002\00011G-scrollable-control-pane-core-source-quality.md`
- Safety: This file must never be executed, replayed, or used as an operational runbook.
- Credit: This archive provides no gate, score, coverage, IDA, validator, or lifecycle credit.

# Removed Executable Code Archive

- Source report: [00011G-scrollable-control-pane-core-source-quality.md](00011G-scrollable-control-pane-core-source-quality.md)
- Source report SHA256 before cleanup: `7B9406585CE8E5F0B0397F75CEED6DC39814A792ED8BF981FCC2DFE40861C3E4`
- Cleanup generated: `2026-08-11T12:47:00Z`
- Removed executable blocks: `1`
- Scope: exact executable or command-shaped fenced blocks removed from the source report by supervisor housekeeping.
- Authority: this file is not a B-agent research report and grants no Gate 1, Gate 2, IDA, validator, score, or lifecycle credit.
- Safety: do not execute, import, evaluate, or use any block in this archive as an operational instruction.

## Removed Block R001

- Original source lines: `356-376`
- Original language: `powershell`
- Block SHA256: `43A9BDD4E3B896AE5BCBE367AC1E63697B846677250FF3A11AD4376777B30E07`

```powershell
Get-Content -Path tools/leaser/Agents/Supervisor.md
Get-Content -Path tools/leaser/Agents/Supervisor_notes.md
Get-Content -Path tools/leaser/Agents/SupervisorAssignments.md
Get-Content -Path tools/leaser/Agents/Agent-B002/goal.md
Get-Content -Path tools/leaser/Agents/Agent-B002/notes.md
Get-Content -Path by-memory/0x004985a0-0x004988cc.ScrollableControlPaneCore.md
Get-Content -Path by-class/ScrollableControlPane.md
Get-Content -Path by-file/ScrollableControlPane.md
Get-Content -Path by-class/ControlPane.md
Get-Content -Path by-memory/0x0049b4f0-0x0049b557.ScrollableControlPaneScalarDeletingDestructor.md
Get-Content -Path by-memory/0x0055e660-0x0055f44f.ScrollablePaneCore.md
Get-Content -Path by-class/ScrollablePane.md
Get-Content -Path by-file/ScrollBar.md
Get-Content -Path by-memory/-ignored.md
Get-Content -Path by-memory/-coverage-report.md
Get-Content -Path auto-generated/by-memory-tool-report.md
Get-Content -Path project-level/-auto-completion-stats.md
rg -n "00011G|004985a0|ScrollableControlPaneCore" by-memory/-coverage-report.md project-level/-auto-completion-stats.md auto-generated/by-memory-tool-report.md
rg -n "\+0x101|\+0x102|\+0x44|\+0x70|visible|active|focus|highlight|0x101|0x102" by-class/ControlPane.md by-class/ScrollableControlPane.md by-file/ScrollableControlPane.md by-memory/0x0049b4f0-0x0049b557.ScrollableControlPaneScalarDeletingDestructor.md by-memory/0x0055e660-0x0055f44f.ScrollablePaneCore.md by-class/ScrollablePane.md by-file/ScrollBar.md by-structure.md inference_research.md
```
