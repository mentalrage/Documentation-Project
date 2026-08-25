<!-- REMOVED-MATERIAL-ARCHIVE -->
# Removed Material Archive

- Status: Non-authoritative archival material only.
- Source report: `E:\NTK\GhidraBridge\source-3\project-documentation\executed-b-agent-research\B002\00019V-SelectBoxControlPane-source-quality.md`
- Safety: This file must never be executed, replayed, or used as an operational runbook.
- Credit: This archive provides no gate, score, coverage, IDA, validator, or lifecycle credit.

# Removed Executable Code Archive

- Source report: [00019V-SelectBoxControlPane-source-quality.md](00019V-SelectBoxControlPane-source-quality.md)
- Source report SHA256 before cleanup: `947B268FBE07ED533AB3205A8ED1C675E431B892E39BE03174237D23D7580095`
- Cleanup generated: `2026-08-11T12:47:01Z`
- Removed executable blocks: `1`
- Scope: exact executable or command-shaped fenced blocks removed from the source report by supervisor housekeeping.
- Authority: this file is not a B-agent research report and grants no Gate 1, Gate 2, IDA, validator, score, or lifecycle credit.
- Safety: do not execute, import, evaluate, or use any block in this archive as an operational instruction.

## Removed Block R001

- Original source lines: `501-509`
- Original language: `powershell`
- Block SHA256: `B72B0BF6FB2C908B63C95A1F242A1C1D11B64F43F3A96A6130517924CCEDC0B7`

```powershell
Set-Location E:\NTK\GhidraBridge\source-3\project-documentation
python .\tools\validator.py --mode file --file .\by-memory\0x004fccf0-0x004fce7e.SelectBoxControlPane.md --apply --lock-timeout -1
python .\tools\validator.py --mode file --file .\by-class\SelectBoxControlPane.md --apply --lock-timeout -1
python .\tools\validator.py --mode file --file .\by-file\ButtonControlPane.md --apply --lock-timeout -1
python .\tools\validator.py --mode rescore --apply --lock-timeout -1
python .\tools\validator.py --mode autogen --apply --lock-timeout -1
python .\tools\validator.py --mode memory_ranges --apply --lock-timeout -1
```
