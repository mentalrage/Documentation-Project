<!-- REMOVED-MATERIAL-ARCHIVE -->
# Removed Material Archive

- Status: Non-authoritative archival material only.
- Source report: `E:\NTK\GhidraBridge\source-3\project-documentation\executed-b-agent-research\B011\0002F9-ChattingModifyHeightPaneOnPaint-source-quality.md`
- Safety: This file must never be executed, replayed, or used as an operational runbook.
- Credit: This archive provides no gate, score, coverage, IDA, validator, or lifecycle credit.

# Removed Executable Code Archive

- Source report: [0002F9-ChattingModifyHeightPaneOnPaint-source-quality.md](0002F9-ChattingModifyHeightPaneOnPaint-source-quality.md)
- Source report SHA256 before cleanup: `89505F380AA61EF2E3BE6128D385B1C281CEFC0BCE5A1C06E5EF64806BD6847B`
- Cleanup generated: `2026-08-11T12:47:16Z`
- Removed executable blocks: `3`
- Scope: exact executable or command-shaped fenced blocks removed from the source report by supervisor housekeeping.
- Authority: this file is not a B-agent research report and grants no Gate 1, Gate 2, IDA, validator, score, or lifecycle credit.
- Safety: do not execute, import, evaluate, or use any block in this archive as an operational instruction.

## Removed Block R001

- Original source lines: `435-440`
- Original language: `powershell`
- Block SHA256: `F1614ACC6BF2CB6853CB7BF21A743E525991E8E292668D1F73F18F4184B73584`

```powershell
python .\tools\validator.py --mode file --file by-memory\0x00480bb0-0x00480c45.ChattingModifyHeightPaneOnPaint.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-class\ChattingModifyHeightPane.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-file\Chatting.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-memory\0x0047efb0-0x00483ef7.ChattingUI.md --apply --queue-timeout 240
```

## Removed Block R002

- Original source lines: `444-447`
- Original language: `powershell`
- Block SHA256: `BEB85F696ECB488DB7E668E3A38C07CCF186AE68B127568F5692201C99D4E74F`

```powershell
python .\tools\validator.py --mode file --file by-memory\0x00615284-0x00615460.ChattingStringResourceData.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-memory\0x00614cdc-0x00615284.ChattingVtableData.md --apply --queue-timeout 240
```

## Removed Block R003

- Original source lines: `451-453`
- Original language: `powershell`
- Block SHA256: `DE5227A1107DC55C84EB00517AB3282A3799A2C661B2059082F319BAFA468D95`

```powershell
python .\tools\validator.py --mode autogen --apply --queue-timeout 240
```
