<!-- REMOVED-MATERIAL-ARCHIVE -->
# Removed Material Archive

- Status: Non-authoritative archival material only.
- Source report: `E:\NTK\GhidraBridge\source-3\project-documentation\executed-b-agent-research\B003\000114-ControlPaneAndProgressBarPrelude-source-routing.md`
- Safety: This file must never be executed, replayed, or used as an operational runbook.
- Credit: This archive provides no gate, score, coverage, IDA, validator, or lifecycle credit.

# Removed Executable Code Archive

- Source report: [000114-ControlPaneAndProgressBarPrelude-source-routing.md](000114-ControlPaneAndProgressBarPrelude-source-routing.md)
- Source report SHA256 before cleanup: `ABA8D8B7D97442164EB47CB8A37F446D042D072880670BA92E123871DD1299FD`
- Cleanup generated: `2026-08-11T12:47:03Z`
- Removed executable blocks: `2`
- Scope: exact executable or command-shaped fenced blocks removed from the source report by supervisor housekeeping.
- Authority: this file is not a B-agent research report and grants no Gate 1, Gate 2, IDA, validator, score, or lifecycle credit.
- Safety: do not execute, import, evaluate, or use any block in this archive as an operational instruction.

## Removed Block R001

- Original source lines: `276-279`
- Original language: `powershell`
- Block SHA256: `0EB955642568DCA9E22683FA6E7C4A9E10F51CAF82AD0D4F8C1A47C047340839`

```powershell
cd E:\NTK\GhidraBridge\source-3\project-documentation
python .\tools\validator.py --mode file --file by-memory\0x004949e0-0x00494b50.ControlPaneAndProgressBarPrelude.md --apply --queue-timeout 240
```

## Removed Block R002

- Original source lines: `283-291`
- Original language: `powershell`
- Block SHA256: `6DDEFDAE56BC9B4B7E62BFB9011B44CB4A1002A47EAC72B58FF39BDBC2DDA633`

```powershell
python .\tools\validator.py --mode file --file by-class\ControlPane.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-file\ControlPane.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-class\ProgressBarControlPane.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-file\ProgressBarControlPane.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-memory\0x00494a90-0x00494b4b.ProgressBarRangeSetters.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-memory\0x00494b50-0x00494c80.ControlFamilyStateVirtualHelpers.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-memory\0x00494bf0-0x00494bf7.ControlPaneIgnoresHitTesting.md --apply --queue-timeout 240
```
