<!-- REMOVED-MATERIAL-ARCHIVE -->
# Removed Material Archive

- Status: Non-authoritative archival material only.
- Source report: `E:\NTK\GhidraBridge\source-3\project-documentation\executed-b-agent-research\B007\0002BS-MidiExactReadHelper-source-quality.md`
- Safety: This file must never be executed, replayed, or used as an operational runbook.
- Credit: This archive provides no gate, score, coverage, IDA, validator, or lifecycle credit.

# Removed Executable Code Archive

- Source report: [0002BS-MidiExactReadHelper-source-quality.md](0002BS-MidiExactReadHelper-source-quality.md)
- Source report SHA256 before cleanup: `6C03B39CB22E96540B3AE706D49DEDD9DD6D469271DFFA80860258E63AB7E43D`
- Cleanup generated: `2026-08-11T12:47:12Z`
- Removed executable blocks: `1`
- Scope: exact executable or command-shaped fenced blocks removed from the source report by supervisor housekeeping.
- Authority: this file is not a B-agent research report and grants no Gate 1, Gate 2, IDA, validator, score, or lifecycle credit.
- Safety: do not execute, import, evaluate, or use any block in this archive as an operational instruction.

## Removed Block R001

- Original source lines: `390-396`
- Original language: `powershell`
- Block SHA256: `AA3C12E394B4B3928E26EDF650322CF8B92F8B8B684724B779EAB4F80CB932B1`

```powershell
python .\tools\validator.py --mode file --file by-memory\0x00526650-0x005266a1.MidiExactReadHelper.md --apply --queue-timeout 240 --wait-generated
python .\tools\validator.py --mode file --file by-memory\0x00526650-0x005270d5.MidiFileReaderAndSMFParserHelpers.md --apply --queue-timeout 240 --wait-generated
python .\tools\validator.py --mode file --file by-file\MidiPlayer.md --apply --queue-timeout 240 --wait-generated
python .\tools\validator.py --mode file --file by-class\MidiPlayer.md --apply --queue-timeout 240 --wait-generated
python .\tools\validator.py --mode file --file by-memory\0x005273a0-0x005277bb.MidiSMFDocumentLoadHelper.md --apply --queue-timeout 240 --wait-generated
```
