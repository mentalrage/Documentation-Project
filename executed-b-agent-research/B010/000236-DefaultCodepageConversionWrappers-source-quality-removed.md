<!-- REMOVED-MATERIAL-ARCHIVE -->
# Removed Material Archive

- Status: Non-authoritative archival material only.
- Source report: `E:\NTK\GhidraBridge\source-3\project-documentation\executed-b-agent-research\B010\000236-DefaultCodepageConversionWrappers-source-quality.md`
- Safety: This file must never be executed, replayed, or used as an operational runbook.
- Credit: This archive provides no gate, score, coverage, IDA, validator, or lifecycle credit.

# Removed Executable Code Archive

- Source report: [000236-DefaultCodepageConversionWrappers-source-quality.md](000236-DefaultCodepageConversionWrappers-source-quality.md)
- Source report SHA256 before cleanup: `82D32E855B8FEC1128A91DBD3EA41D9D69FB394E3081F9E6388F2F5930859533`
- Cleanup generated: `2026-08-11T12:47:15Z`
- Removed executable blocks: `1`
- Scope: exact executable or command-shaped fenced blocks removed from the source report by supervisor housekeeping.
- Authority: this file is not a B-agent research report and grants no Gate 1, Gate 2, IDA, validator, score, or lifecycle credit.
- Safety: do not execute, import, evaluate, or use any block in this archive as an operational instruction.

## Removed Block R001

- Original source lines: `250-256`
- Original language: `powershell`
- Block SHA256: `0DC432432F8323F20F5E3B81E6AEB798A39573469D65BA62489F89ED73ACC492`

```powershell
python .\tools\validator.py --mode file --file by-memory/0x005151b0-0x005151ef.DefaultCodepageConversionWrappers.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-file/StringBase.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-file/StringUtil.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-memory/0x00582500-0x005829f0.StringBaseConversionAndCrtShims.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-memory/-ignored.md --apply --queue-timeout 240
```
