<!-- REMOVED-MATERIAL-ARCHIVE -->
# Removed Material Archive

- Status: Non-authoritative archival material only.
- Source report: `E:\NTK\GhidraBridge\source-3\project-documentation\executed-b-agent-research\B003\00045F-IntegrateMacroDialogOnDraw-empty-emitter-source-quality.md`
- Safety: This file must never be executed, replayed, or used as an operational runbook.
- Credit: This archive provides no gate, score, coverage, IDA, validator, or lifecycle credit.

# Removed Executable Code Archive

- Source report: [00045F-IntegrateMacroDialogOnDraw-empty-emitter-source-quality.md](00045F-IntegrateMacroDialogOnDraw-empty-emitter-source-quality.md)
- Source report SHA256 before cleanup: `1AB9527A06F868E2DB1A6A71601600A25C31300FE530403CC52B56D1B0D6169A`
- Cleanup generated: `2026-08-11T12:47:06Z`
- Removed executable blocks: `2`
- Scope: exact executable or command-shaped fenced blocks removed from the source report by supervisor housekeeping.
- Authority: this file is not a B-agent research report and grants no Gate 1, Gate 2, IDA, validator, score, or lifecycle credit.
- Safety: do not execute, import, evaluate, or use any block in this archive as an operational instruction.

## Removed Block R001

- Original source lines: `259-266`
- Original language: `powershell`
- Block SHA256: `CEEF28279534A74AE50E8901B2225E03299E6EB153FF73891F26F079D78FB15C`

```powershell
python .\tools\validator.py --mode file --file by-memory\0x00541e50-0x00541f96.IntegrateMacroDialogOnDraw.md --apply --queue-timeout 240 --wait-generated
python .\tools\validator.py --mode file --file by-class\IntegrateMacroDialog.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-file\MacroDialogs.md --apply --queue-timeout 240 --wait-generated
python .\tools\validator.py --mode file --file by-memory\0x00541b30-0x00542265.IntegrateMacroDialog.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-type\by-vtable\MacroDialogFamilyVtables.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-memory\0x00620c74-0x0062179c.OptionMacroProfileReadOnlyData.md --apply --queue-timeout 240
```

## Removed Block R002

- Original source lines: `270-272`
- Original language: `powershell`
- Block SHA256: `42B0B790089E2F6D114B74F36C116734952503CE7D88E0E415C0CA44A5583EA6`

```powershell
Select-String -Path .\auto-generated\NexusTK\ui\dialogs\MacroDialogs.cpp -Pattern "UID:00045F|IntegrateMacroDialog::OnDraw|Empty Emitter Marker" -Context 0,24
```
