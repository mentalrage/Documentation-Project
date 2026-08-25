<!-- REMOVED-MATERIAL-ARCHIVE -->
# Removed Material Archive

- Status: Non-authoritative archival material only.
- Source report: `E:\NTK\GhidraBridge\source-3\project-documentation\executed-b-agent-research\B002\00015I-FpsPaneStartLogSessionRaw-source-quality.md`
- Safety: This file must never be executed, replayed, or used as an operational runbook.
- Credit: This archive provides no gate, score, coverage, IDA, validator, or lifecycle credit.

# Removed Executable Code Archive

- Source report: [00015I-FpsPaneStartLogSessionRaw-source-quality.md](00015I-FpsPaneStartLogSessionRaw-source-quality.md)
- Source report SHA256 before cleanup: `0110E922AD162B7D2199BD53F760D764F60ABBF1DA6A96AE3C539EA53398C73C`
- Cleanup generated: `2026-08-11T12:47:00Z`
- Removed executable blocks: `1`
- Scope: exact executable or command-shaped fenced blocks removed from the source report by supervisor housekeeping.
- Authority: this file is not a B-agent research report and grants no Gate 1, Gate 2, IDA, validator, score, or lifecycle credit.
- Safety: do not execute, import, evaluate, or use any block in this archive as an operational instruction.

## Removed Block R001

- Original source lines: `361-374`
- Original language: `powershell`
- Block SHA256: `BF762CBEEA76212FD772A72645B113B07145773C6C919672920A0DD4CF2BF5C8`

```powershell
python .\tools\validator.py --mode file --file by-memory\0x004b69b0-0x004b6adc.FpsPaneStartLogSession.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-class\FpsPane.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-file\FpsPane.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-memory\0x004b6410-0x004b6caf.FpsPaneDiagnostics.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-memory\0x004b64a0-0x004b67a7.FpsPaneUpdateFpsLogSessionRaw.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-memory\0x004b6ae0-0x004b6c2b.FpsPaneWriteLogSummaryRaw.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-memory\0x004b68b0-0x004b69b0.FpsPaneUpdateStatistics.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-type\by-struct\FpsPaneLayout.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-global\g_fpsDebugActive.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-global\g_fpsLogEnabled.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-memory\0x0066da90-0x0066da94.g_fpsDebugActive.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-memory\0x0069b338-0x0069b339.g_fpsLogEnabled.md --apply --queue-timeout 240
```
