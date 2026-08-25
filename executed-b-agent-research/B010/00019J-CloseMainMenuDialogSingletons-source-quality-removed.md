<!-- REMOVED-MATERIAL-ARCHIVE -->
# Removed Material Archive

- Status: Non-authoritative archival material only.
- Source report: `E:\NTK\GhidraBridge\source-3\project-documentation\executed-b-agent-research\B010\00019J-CloseMainMenuDialogSingletons-source-quality.md`
- Safety: This file must never be executed, replayed, or used as an operational runbook.
- Credit: This archive provides no gate, score, coverage, IDA, validator, or lifecycle credit.

# Removed Executable Code Archive

- Source report: [00019J-CloseMainMenuDialogSingletons-source-quality.md](00019J-CloseMainMenuDialogSingletons-source-quality.md)
- Source report SHA256 before cleanup: `1FE7890760A1D18B4564A628F5AA7B671772D5189606FFA99344B9113792A936`
- Cleanup generated: `2026-08-11T12:47:15Z`
- Removed executable blocks: `1`
- Scope: exact executable or command-shaped fenced blocks removed from the source report by supervisor housekeeping.
- Authority: this file is not a B-agent research report and grants no Gate 1, Gate 2, IDA, validator, score, or lifecycle credit.
- Safety: do not execute, import, evaluate, or use any block in this archive as an operational instruction.

## Removed Block R001

- Original source lines: `316-322`
- Original language: `powershell`
- Block SHA256: `4022363D0FF0D5211861DB8FA2D36E77E95E421A33EAC5ACB14095E2608E93CE`

```powershell
python .\tools\validator.py --mode file --file by-memory/0x004f69a0-0x004f6a31.CloseMainMenuDialogSingletons.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-global/CloseMainMenuDialogSingletons_4F69A0.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-file/MainMenuPane.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-class/MainMenuPane.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-memory/0x004f6700-0x004f7d10.MainMenuPaneCore.md --apply --queue-timeout 240
```
