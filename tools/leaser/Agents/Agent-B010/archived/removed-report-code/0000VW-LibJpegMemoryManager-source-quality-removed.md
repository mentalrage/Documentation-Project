<!-- REMOVED-MATERIAL-ARCHIVE -->
# Removed Material Archive

- Status: Non-authoritative archival material only.
- Source report: `E:\NTK\GhidraBridge\source-3\project-documentation\executed-b-agent-research\B010\0000VW-LibJpegMemoryManager-source-quality.md`
- Safety: This file must never be executed, replayed, or used as an operational runbook.
- Credit: This archive provides no gate, score, coverage, IDA, validator, or lifecycle credit.

# Removed Executable Code Archive

- Source report: [0000VW-LibJpegMemoryManager-source-quality.md](0000VW-LibJpegMemoryManager-source-quality.md)
- Source report SHA256 before cleanup: `68CFC680AE83D3A2B963FB190A34EE1EC5EF88911737D13331F867A0ED536035`
- Cleanup generated: `2026-08-11T12:47:15Z`
- Removed executable blocks: `1`
- Scope: exact executable or command-shaped fenced blocks removed from the source report by supervisor housekeeping.
- Authority: this file is not a B-agent research report and grants no Gate 1, Gate 2, IDA, validator, score, or lifecycle credit.
- Safety: do not execute, import, evaluate, or use any block in this archive as an operational instruction.

## Removed Block R001

- Original source lines: `376-380`
- Original language: `powershell`
- Block SHA256: `A4B9462CDF69A6A6422354E470DFD07CD5B21E9C6232A170BBB2CD631F24FB83`

```powershell
python .\tools\validator.py --mode file --file by-memory/0x00405060-0x00405c77.LibJpegMemoryManager.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-file/LibJPEG.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-memory/0x00401000-0x00414283.LibJpeg6bCore.md --apply --queue-timeout 240
```
