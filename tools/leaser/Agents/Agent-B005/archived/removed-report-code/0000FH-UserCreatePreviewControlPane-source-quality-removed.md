<!-- REMOVED-MATERIAL-ARCHIVE -->
# Removed Material Archive

- Status: Non-authoritative archival material only.
- Source report: `E:\NTK\GhidraBridge\source-3\project-documentation\executed-b-agent-research\B005\0000FH-UserCreatePreviewControlPane-source-quality.md`
- Safety: This file must never be executed, replayed, or used as an operational runbook.
- Credit: This archive provides no gate, score, coverage, IDA, validator, or lifecycle credit.

# Removed Executable Code Archive

- Source report: [0000FH-UserCreatePreviewControlPane-source-quality.md](0000FH-UserCreatePreviewControlPane-source-quality.md)
- Source report SHA256 before cleanup: `B8FD22D1B782ED2EE526904D4AC0F7711C2504F86467978982ED6FCF0171F795`
- Cleanup generated: `2026-08-11T12:47:08Z`
- Removed executable blocks: `1`
- Scope: exact executable or command-shaped fenced blocks removed from the source report by supervisor housekeeping.
- Authority: this file is not a B-agent research report and grants no Gate 1, Gate 2, IDA, validator, score, or lifecycle credit.
- Safety: do not execute, import, evaluate, or use any block in this archive as an operational instruction.

## Removed Block R001

- Original source lines: `352-358`
- Original language: `powershell`
- Block SHA256: `2C314B60CE0717227933F8A40F3E2F281116309FB22A762DBF71224B16DD3998`

```powershell
python tools/validator.py --mode file --file by-class/UserCreatePreviewControlPane.md --apply --queue-timeout 240
python tools/validator.py --mode file --file by-memory/0x00501150-0x00502383.UserCreateAppearanceSelectorControls.md --apply --queue-timeout 240
python tools/validator.py --mode file --file by-file/UserCreateAppearanceControls.md --apply --queue-timeout 240
python tools/validator.py --mode file --file by-file/CreateUserDialogs.md --apply --queue-timeout 240
python tools/validator.py --mode file --file by-class/CreateUserDialogPane.md --apply --queue-timeout 240
```
