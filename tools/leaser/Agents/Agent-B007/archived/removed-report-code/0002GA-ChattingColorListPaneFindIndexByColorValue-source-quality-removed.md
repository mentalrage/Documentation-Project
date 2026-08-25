<!-- REMOVED-MATERIAL-ARCHIVE -->
# Removed Material Archive

- Status: Non-authoritative archival material only.
- Source report: `E:\NTK\GhidraBridge\source-3\project-documentation\executed-b-agent-research\B007\0002GA-ChattingColorListPaneFindIndexByColorValue-source-quality.md`
- Safety: This file must never be executed, replayed, or used as an operational runbook.
- Credit: This archive provides no gate, score, coverage, IDA, validator, or lifecycle credit.

# Removed Executable Code Archive

- Source report: [0002GA-ChattingColorListPaneFindIndexByColorValue-source-quality.md](0002GA-ChattingColorListPaneFindIndexByColorValue-source-quality.md)
- Source report SHA256 before cleanup: `8A900DB6E2BFD3F12C54E28468BC553B42231EF714FC095F2BE57FFBDEC8581E`
- Cleanup generated: `2026-08-11T12:47:12Z`
- Removed executable blocks: `2`
- Scope: exact executable or command-shaped fenced blocks removed from the source report by supervisor housekeeping.
- Authority: this file is not a B-agent research report and grants no Gate 1, Gate 2, IDA, validator, score, or lifecycle credit.
- Safety: do not execute, import, evaluate, or use any block in this archive as an operational instruction.

## Removed Block R001

- Original source lines: `424-434`
- Original language: `powershell`
- Block SHA256: `21D460EBA02857342EAEE3BCBA586CCB378292666D1FA659F638E9173DBDAAFF`

```powershell
python tools\validator.py --mode file --file by-memory\0x00483270-0x004832b9.ChattingColorListPaneFindIndexByColorValue.md --apply --queue-timeout 240
python tools\validator.py --mode file --file by-class\ChattingColorListPane.md --apply --queue-timeout 240
python tools\validator.py --mode file --file by-memory\0x00483210-0x0048325b.ChattingColorListPaneSelectCurrentColor.md --apply --queue-timeout 240
python tools\validator.py --mode file --file by-memory\0x00483260-0x0048326f.ChattingColorListPaneGetSelectedColorValueRaw.md --apply --queue-timeout 240
python tools\validator.py --mode file --file by-class\ListPane.md --apply --queue-timeout 240
python tools\validator.py --mode file --file by-file\ListPane.md --apply --queue-timeout 240
python tools\validator.py --mode file --file by-memory\0x004f3a50-0x004f4a77.ListPane.md --apply --queue-timeout 240
python tools\validator.py --mode file --file by-memory\0x004f3bb0-0x004f3f20.ListPaneItemSelectionStorageHelpers.md --apply --queue-timeout 240
python tools\validator.py --mode file --file by-file\Chatting.md --apply --queue-timeout 240
```

## Removed Block R002

- Original source lines: `438-440`
- Original language: `powershell`
- Block SHA256: `12A9833B683207800F47C8D060D7A3B96B0E94B7B7BFD7B811CD7FD1A6A60893`

```powershell
python tools\validator.py --mode file --file by-memory\-coverage-report.md --apply --queue-timeout 240
```
