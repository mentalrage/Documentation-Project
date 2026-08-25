<!-- REMOVED-MATERIAL-ARCHIVE -->
# Removed Material Archive

- Status: Non-authoritative archival material only.
- Source report: `E:\NTK\GhidraBridge\source-3\project-documentation\executed-b-agent-research\B003\0002EY-ChattingPaneResetScrollRangeRaw-source-quality.md`
- Safety: This file must never be executed, replayed, or used as an operational runbook.
- Credit: This archive provides no gate, score, coverage, IDA, validator, or lifecycle credit.

# Removed Executable Code Archive

- Source report: [0002EY-ChattingPaneResetScrollRangeRaw-source-quality.md](0002EY-ChattingPaneResetScrollRangeRaw-source-quality.md)
- Source report SHA256 before cleanup: `B242790F850E9282883E02752774C04F6165DF9550EC48B9D12C042A3C2531C8`
- Cleanup generated: `2026-08-11T12:47:04Z`
- Removed executable blocks: `1`
- Scope: exact executable or command-shaped fenced blocks removed from the source report by supervisor housekeeping.
- Authority: this file is not a B-agent research report and grants no Gate 1, Gate 2, IDA, validator, score, or lifecycle credit.
- Safety: do not execute, import, evaluate, or use any block in this archive as an operational instruction.

## Removed Block R001

- Original source lines: `538-546`
- Original language: `powershell`
- Block SHA256: `D57EB93443D2185427EA3380DB0ECBE50538E0ED8F0F194E124BEBE32A1E9F6A`

```powershell
python .\tools\validator.py --mode file --file by-memory\0x0047fd40-0x0047fd68.ChattingPaneScrollToBottomRaw.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-class\ChattingPane.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-file\Chatting.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-memory\0x0047efb0-0x00483ef7.ChattingUI.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-memory\0x0047fbd0-0x0047fc6b.ChattingPaneSetVisibleRowCount.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-memory\-ignored.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-memory\0x0047fc70-0x0047fd3b.ChattingPaneComputeLineCount.md --apply --queue-timeout 240
```
