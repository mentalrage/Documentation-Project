<!-- REMOVED-MATERIAL-ARCHIVE -->
# Removed Material Archive

- Status: Non-authoritative archival material only.
- Source report: `E:\NTK\GhidraBridge\source-3\project-documentation\executed-b-agent-research\B002\0002S5-ItemWhoTargetNavigationRawHelpers-source-quality.md`
- Safety: This file must never be executed, replayed, or used as an operational runbook.
- Credit: This archive provides no gate, score, coverage, IDA, validator, or lifecycle credit.

# Removed Executable Code Archive

- Source report: [0002S5-ItemWhoTargetNavigationRawHelpers-source-quality.md](0002S5-ItemWhoTargetNavigationRawHelpers-source-quality.md)
- Source report SHA256 before cleanup: `B9FD165EBCCF2E63BEE218923250927B5F68D0CEB8A54F0A81FDC7F1A480A2B8`
- Cleanup generated: `2026-08-11T12:47:02Z`
- Removed executable blocks: `1`
- Scope: exact executable or command-shaped fenced blocks removed from the source report by supervisor housekeeping.
- Authority: this file is not a B-agent research report and grants no Gate 1, Gate 2, IDA, validator, score, or lifecycle credit.
- Safety: do not execute, import, evaluate, or use any block in this archive as an operational instruction.

## Removed Block R001

- Original source lines: `404-409`
- Original language: `powershell`
- Block SHA256: `9A1A60DF2A4F8D0395A4396E2FA6C7868A2EAFABCADEE767BF071BA52179AA57`

```powershell
python .\tools\validator.py --mode file --file by-memory\0x005af3b0-0x005af4ef.ItemWhoTargetNavigationRawHelpers.md --apply --queue-timeout 240 --wait-generated
python .\tools\validator.py --mode file --file by-class\ItemWhoInputPane.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-file\TargetSelectionInputPanes.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-memory\0x005aedd0-0x005aefaf.ItemWhoInputPaneKeyInput.md --apply --queue-timeout 240
```
