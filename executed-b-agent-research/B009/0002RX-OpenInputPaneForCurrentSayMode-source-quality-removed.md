<!-- REMOVED-MATERIAL-ARCHIVE -->
# Removed Material Archive

- Status: Non-authoritative archival material only.
- Source report: `E:\NTK\GhidraBridge\source-3\project-documentation\executed-b-agent-research\B009\0002RX-OpenInputPaneForCurrentSayMode-source-quality.md`
- Safety: This file must never be executed, replayed, or used as an operational runbook.
- Credit: This archive provides no gate, score, coverage, IDA, validator, or lifecycle credit.

# Removed Executable Code Archive

- Source report: [0002RX-OpenInputPaneForCurrentSayMode-source-quality.md](0002RX-OpenInputPaneForCurrentSayMode-source-quality.md)
- Source report SHA256 before cleanup: `67032072C1159FBC597ED621BD20642E284C51E86B3BF03447F4C7AFD3070903`
- Cleanup generated: `2026-08-11T12:47:14Z`
- Removed executable blocks: `1`
- Scope: exact executable or command-shaped fenced blocks removed from the source report by supervisor housekeeping.
- Authority: this file is not a B-agent research report and grants no Gate 1, Gate 2, IDA, validator, score, or lifecycle credit.
- Safety: do not execute, import, evaluate, or use any block in this archive as an operational instruction.

## Removed Block R001

- Original source lines: `364-368`
- Original language: `powershell`
- Block SHA256: `A93444030573C923A21761BD79104D047DDC46091D62B8BA835F08C7AF031960`

```powershell
python .\tools\validator.py --mode file --file by-memory/0x005a5110-0x005a5337.OpenInputPaneForCurrentSayMode.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-file/SayInputPanes.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-memory/0x005a4b60-0x005a5791.SayModeHelpers.md --apply --queue-timeout 240
```
