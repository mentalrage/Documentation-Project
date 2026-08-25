<!-- REMOVED-MATERIAL-ARCHIVE -->
# Removed Material Archive

- Status: Non-authoritative archival material only.
- Source report: `E:\NTK\GhidraBridge\source-3\project-documentation\executed-b-agent-research\B005\00030K-NewArticleDialogCore-source-quality.md`
- Safety: This file must never be executed, replayed, or used as an operational runbook.
- Credit: This archive provides no gate, score, coverage, IDA, validator, or lifecycle credit.

# Removed Executable Code Archive

- Source report: [00030K-NewArticleDialogCore-source-quality.md](00030K-NewArticleDialogCore-source-quality.md)
- Source report SHA256 before cleanup: `8D715C77F62F3AC332D23B66B7714306E4B3695290888D7CF7C6D42D9129D107`
- Cleanup generated: `2026-08-11T12:47:09Z`
- Removed executable blocks: `1`
- Scope: exact executable or command-shaped fenced blocks removed from the source report by supervisor housekeeping.
- Authority: this file is not a B-agent research report and grants no Gate 1, Gate 2, IDA, validator, score, or lifecycle credit.
- Safety: do not execute, import, evaluate, or use any block in this archive as an operational instruction.

## Removed Block R001

- Original source lines: `703-707`
- Original language: `powershell`
- Block SHA256: `12D9C2D5218DCE463CF44579C76413FA6AF81BFC5527A487164747E27A0EDA08`

```powershell
python tools\validator.py --mode file --file "by-memory\0x00476c10-0x00477790.NewArticleDialogCore.md" --apply --queue-timeout 240 --lock-timeout -1
python tools\validator.py --mode file --file "by-class\NewArticleDialog.md" --apply --queue-timeout 240 --lock-timeout -1
python tools\validator.py --mode file --file "by-file\BoardDialogs.md" --apply --queue-timeout 240 --lock-timeout -1
```
