<!-- REMOVED-MATERIAL-ARCHIVE -->
# Removed Material Archive

- Status: Non-authoritative archival material only.
- Source report: `E:\NTK\GhidraBridge\source-3\project-documentation\executed-b-agent-research\B006\0002BT-MidiTrackBufferedByteReader-source-quality.md`
- Safety: This file must never be executed, replayed, or used as an operational runbook.
- Credit: This archive provides no gate, score, coverage, IDA, validator, or lifecycle credit.

# Removed Executable Code Archive

- Source report: [0002BT-MidiTrackBufferedByteReader-source-quality.md](0002BT-MidiTrackBufferedByteReader-source-quality.md)
- Source report SHA256 before cleanup: `90117DB901900D1D2D3F718392427BD2490F975E73A13F648F596BE0F44E0F16`
- Cleanup generated: `2026-08-11T12:47:11Z`
- Removed executable blocks: `1`
- Scope: exact executable or command-shaped fenced blocks removed from the source report by supervisor housekeeping.
- Authority: this file is not a B-agent research report and grants no Gate 1, Gate 2, IDA, validator, score, or lifecycle credit.
- Safety: do not execute, import, evaluate, or use any block in this archive as an operational instruction.

## Removed Block R001

- Original source lines: `294-298`
- Original language: `powershell`
- Block SHA256: `9A89D6AAC54D457C4A6C21BA92C62B73FB61B8FCAD79130354EC569B483F9A96`

```powershell
python .\tools\validator.py --mode file --file by-memory\0x005266b0-0x00526784.MidiTrackBufferedByteReader.md --apply --wait-generated --queue-timeout 240
python .\tools\validator.py --mode file --file by-memory\0x00526650-0x005270d5.MidiFileReaderAndSMFParserHelpers.md --apply --wait-generated --queue-timeout 240
python .\tools\validator.py --mode file --file by-file\MidiPlayer.md --apply --wait-generated --queue-timeout 240
```
