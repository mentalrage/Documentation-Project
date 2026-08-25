<!-- REMOVED-MATERIAL-ARCHIVE -->
# Removed Material Archive

- Status: Non-authoritative archival material only.
- Source report: `E:\NTK\GhidraBridge\source-3\project-documentation\executed-b-agent-research\B002\00029L-StartupClearedUnusedDwords-source-quality.md`
- Safety: This file must never be executed, replayed, or used as an operational runbook.
- Credit: This archive provides no gate, score, coverage, IDA, validator, or lifecycle credit.

# Removed Executable Code Archive

- Source report: [00029L-StartupClearedUnusedDwords-source-quality.md](00029L-StartupClearedUnusedDwords-source-quality.md)
- Source report SHA256 before cleanup: `37400CDEB8495FA48FF56E4AA7BE5EFD04D21205C2797EF618C90593DECD50A4`
- Cleanup generated: `2026-08-11T12:47:01Z`
- Removed executable blocks: `1`
- Scope: exact executable or command-shaped fenced blocks removed from the source report by supervisor housekeeping.
- Authority: this file is not a B-agent research report and grants no Gate 1, Gate 2, IDA, validator, score, or lifecycle credit.
- Safety: do not execute, import, evaluate, or use any block in this archive as an operational instruction.

## Removed Block R001

- Original source lines: `597-600`
- Original language: `powershell`
- Block SHA256: `348D175FB4BF3772AFFC33400F392A56A3077917BE4E1EA1D2EEC12BA77B2AF1`

```powershell
cd E:\NTK\GhidraBridge\source-3\project-documentation\tools
python validator.py --queue-timeout 240 --mode file --file '..\by-memory\0x0069b350-0x0069b358.StartupClearedUnusedDwords.md'
```
