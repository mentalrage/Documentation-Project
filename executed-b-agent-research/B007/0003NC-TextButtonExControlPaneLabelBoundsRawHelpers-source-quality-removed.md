<!-- REMOVED-MATERIAL-ARCHIVE -->
# Removed Material Archive

- Status: Non-authoritative archival material only.
- Source report: `E:\NTK\GhidraBridge\source-3\project-documentation\executed-b-agent-research\B007\0003NC-TextButtonExControlPaneLabelBoundsRawHelpers-source-quality.md`
- Safety: This file must never be executed, replayed, or used as an operational runbook.
- Credit: This archive provides no gate, score, coverage, IDA, validator, or lifecycle credit.

# Removed Executable Code Archive

- Source report: [0003NC-TextButtonExControlPaneLabelBoundsRawHelpers-source-quality.md](0003NC-TextButtonExControlPaneLabelBoundsRawHelpers-source-quality.md)
- Source report SHA256 before cleanup: `5FE47C146AFE16C979E9CD92C138EE0414A973758BCCB2763A9D6DD93C86EC8C`
- Cleanup generated: `2026-08-11T12:47:12Z`
- Removed executable blocks: `1`
- Scope: exact executable or command-shaped fenced blocks removed from the source report by supervisor housekeeping.
- Authority: this file is not a B-agent research report and grants no Gate 1, Gate 2, IDA, validator, score, or lifecycle credit.
- Safety: do not execute, import, evaluate, or use any block in this archive as an operational instruction.

## Removed Block R001

- Original source lines: `609-613`
- Original language: `text`
- Block SHA256: `A93F3490529A14E8A26E959941041F58633F67FA1D213D8091BB30979F82629E`

```text
python .\tools\validator.py --mode file --file by-memory\0x00495aa0-0x00495be3.TextButtonExControlPaneLabelBoundsRawHelpers.md --apply --queue-timeout 180
python .\tools\validator.py --mode file --file by-class\TextButtonExControlPane.md --apply --queue-timeout 180
python .\tools\validator.py --mode file --file by-memory\0x00494eb0-0x0049803a.ButtonChoiceControlCore.md --apply --queue-timeout 180
```
