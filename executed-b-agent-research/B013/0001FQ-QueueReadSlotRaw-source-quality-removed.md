<!-- REMOVED-MATERIAL-ARCHIVE -->
# Removed Material Archive

- Status: Non-authoritative archival material only.
- Source report: `E:\NTK\GhidraBridge\source-3\project-documentation\executed-b-agent-research\B013\0001FQ-QueueReadSlotRaw-source-quality.md`
- Safety: This file must never be executed, replayed, or used as an operational runbook.
- Credit: This archive provides no gate, score, coverage, IDA, validator, or lifecycle credit.

# Removed Executable Code Archive

- Source report: [0001FQ-QueueReadSlotRaw-source-quality.md](0001FQ-QueueReadSlotRaw-source-quality.md)
- Source report SHA256 before cleanup: `324AF7D5BF7BD8C9B315A0F81450BCA0A2B5B068D00E545AD683AE9BE644827A`
- Cleanup generated: `2026-08-11T12:47:17Z`
- Removed executable blocks: `1`
- Scope: exact executable or command-shaped fenced blocks removed from the source report by supervisor housekeeping.
- Authority: this file is not a B-agent research report and grants no Gate 1, Gate 2, IDA, validator, score, or lifecycle credit.
- Safety: do not execute, import, evaluate, or use any block in this archive as an operational instruction.

## Removed Block R001

- Original source lines: `394-399`
- Original language: `powershell`
- Block SHA256: `2E54588BD5CB43C0478C255B9FB456DBF0BDD8D71B7362E91285AC6BE3220BAA`

```powershell
python .\tools\validator.py --mode file --file by-memory\0x00553b10-0x00553b55.QueueReadSlotRaw.md --apply --queue-timeout 240 --wait-generated
python .\tools\validator.py --mode file --file by-memory\0x005539e0-0x00553c07.Queue.md --apply --queue-timeout 240 --wait-generated
python .\tools\validator.py --mode file --file by-class\Queue.md --apply --queue-timeout 240 --wait-generated
python .\tools\validator.py --mode file --file by-file\Queue.md --apply --queue-timeout 240 --wait-generated
```
