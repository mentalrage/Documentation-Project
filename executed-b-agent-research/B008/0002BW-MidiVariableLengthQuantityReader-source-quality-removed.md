<!-- REMOVED-MATERIAL-ARCHIVE -->
# Removed Material Archive

- Status: Non-authoritative archival material only.
- Source report: `E:\NTK\GhidraBridge\source-3\project-documentation\executed-b-agent-research\B008\0002BW-MidiVariableLengthQuantityReader-source-quality.md`
- Safety: This file must never be executed, replayed, or used as an operational runbook.
- Credit: This archive provides no gate, score, coverage, IDA, validator, or lifecycle credit.

# Removed Executable Code Archive

- Source report: [0002BW-MidiVariableLengthQuantityReader-source-quality.md](0002BW-MidiVariableLengthQuantityReader-source-quality.md)
- Source report SHA256 before cleanup: `9221954A84A61665EE0ADA4732B7E631D579E1FEDFE5BC6AAEDBBBA1607C90F9`
- Cleanup generated: `2026-08-11T12:47:13Z`
- Removed executable blocks: `2`
- Scope: exact executable or command-shaped fenced blocks removed from the source report by supervisor housekeeping.
- Authority: this file is not a B-agent research report and grants no Gate 1, Gate 2, IDA, validator, score, or lifecycle credit.
- Safety: do not execute, import, evaluate, or use any block in this archive as an operational instruction.

## Removed Block R001

- Original source lines: `245-250`
- Original language: `powershell`
- Block SHA256: `8FEE3DA9971E3DB65299589E42C539C3A77FD6D9B30C66AC4E5849A0326E21B5`

```powershell
python .\tools\validator.py --mode file --file by-memory\0x00526bb0-0x00526cd9.MidiVariableLengthQuantityReader.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-memory\0x00526650-0x005270d5.MidiFileReaderAndSMFParserHelpers.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-file\MidiPlayer.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-class\MidiPlayer.md --apply --queue-timeout 240
```

## Removed Block R002

- Original source lines: `256-259`
- Original language: `powershell`
- Block SHA256: `798EE012BB60AFC2B61A97DC981DADFA1180CF3593F66FA09C2E21BE78BE9BE7`

```powershell
rg -n "UID:0002BW|MidiReadVariableLength|Empty Emitter Marker" .\auto-generated\NexusTK\audio\MidiPlayer.cpp
rg -n "0002BW|0x00526bb0|MidiVariableLengthQuantityReader" .\auto-generated\-ag-memory-coverage.md .\auto-generated\-ag-research-tracker.md .\auto-generated\-ag-coverage-report-by-memory.md
```
