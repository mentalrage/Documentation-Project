<!-- REMOVED-MATERIAL-ARCHIVE -->
# Removed Material Archive

- Status: Non-authoritative archival material only.
- Source report: `E:\NTK\GhidraBridge\source-3\project-documentation\executed-b-agent-research\B002\0002PD-ControlFamilyStateVirtualHelpers-ownership-split-research.md`
- Safety: This file must never be executed, replayed, or used as an operational runbook.
- Credit: This archive provides no gate, score, coverage, IDA, validator, or lifecycle credit.

# Removed Executable Code Archive

- Source report: [0002PD-ControlFamilyStateVirtualHelpers-ownership-split-research.md](0002PD-ControlFamilyStateVirtualHelpers-ownership-split-research.md)
- Source report SHA256 before cleanup: `4E2484A868F534C205DE34D4E573F3E699E3048681DB9D37BB46E9DB2A748E85`
- Cleanup generated: `2026-08-11T12:47:02Z`
- Removed executable blocks: `1`
- Scope: exact executable or command-shaped fenced blocks removed from the source report by supervisor housekeeping.
- Authority: this file is not a B-agent research report and grants no Gate 1, Gate 2, IDA, validator, score, or lifecycle credit.
- Safety: do not execute, import, evaluate, or use any block in this archive as an operational instruction.

## Removed Block R001

- Original source lines: `167-188`
- Original language: `powershell`
- Block SHA256: `5C598BB716628A305B9B4EBF3630835AB9D4860975E1ECFE5B1BD182D6834A61`

```powershell
$files = @(
'by-memory/0x00494b50-0x00494c80.ControlFamilyStateVirtualHelpers.md',
'by-memory/0x00494b50-0x00494b77.ProgressBarControlPaneSetCurrentValue.md',
'by-memory/0x00494b80-0x00494bad.ControlPaneSetVisualState.md',
'by-memory/0x00494bb0-0x00494bca.ControlPaneSetVisibleFlag.md',
'by-memory/0x00494bd0-0x00494bea.ControlPaneClearVisibleFlag.md',
'by-memory/0x00494bf0-0x00494bf7.ControlPaneIgnoresHitTesting.md',
'by-memory/0x00494c00-0x00494c10.ControlPaneSetIgnoreHitTesting.md',
'by-memory/0x00494c10-0x00494c2a.ControlPaneDeactivate.md',
'by-memory/0x00494c30-0x00494c4a.ControlPaneActivate.md',
'by-memory/0x00494c50-0x00494c80.ControlPaneDrawActiveFrameHelper.md',
'by-memory/-ignored.md',
'by-file/ControlPane.md',
'by-class/ControlPane.md',
'by-file/ProgressBarControlPane.md',
'by-class/ProgressBarControlPane.md',
'by-file/ButtonControlPane.md',
'by-class/RadioGroupControlPane.md'
)
foreach ($f in $files) { python tools\validator.py --mode file --file $f --apply }
```
