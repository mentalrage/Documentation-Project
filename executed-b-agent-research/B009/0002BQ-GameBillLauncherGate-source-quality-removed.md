<!-- REMOVED-MATERIAL-ARCHIVE -->
# Removed Material Archive

- Status: Non-authoritative archival material only.
- Source report: `E:\NTK\GhidraBridge\source-3\project-documentation\executed-b-agent-research\B009\0002BQ-GameBillLauncherGate-source-quality.md`
- Safety: This file must never be executed, replayed, or used as an operational runbook.
- Credit: This archive provides no gate, score, coverage, IDA, validator, or lifecycle credit.

# Removed Executable Code Archive

- Source report: [0002BQ-GameBillLauncherGate-source-quality.md](0002BQ-GameBillLauncherGate-source-quality.md)
- Source report SHA256 before cleanup: `B3DB79133D00E5B9B412B8FAB20C51FF907489C138A327662F93C78B07294775`
- Cleanup generated: `2026-08-11T12:47:14Z`
- Removed executable blocks: `1`
- Scope: exact executable or command-shaped fenced blocks removed from the source report by supervisor housekeeping.
- Authority: this file is not a B-agent research report and grants no Gate 1, Gate 2, IDA, validator, score, or lifecycle credit.
- Safety: do not execute, import, evaluate, or use any block in this archive as an operational instruction.

## Removed Block R001

- Original source lines: `480-487`
- Original language: `powershell`
- Block SHA256: `A1CB32DD28BE1771C940004A4ADE9B4A967DFB7AA19BFBF97184EA83959D564B`

```powershell
python .\tools\validator.py --mode file --file by-memory/0x00491790-0x004918dc.GameBillLauncherGate.md --apply --queue-timeout 240 --wait-generated
python .\tools\validator.py --mode file --file by-memory/0x0048f400-0x00491b28.RegistryCommandLineParsers.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-file/RegistryConfig.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-class/RegistryConfig.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-memory/0x006168e8-0x00617420.RegistryConfigChannelStartupStringData.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-memory/0x0067a7c8-0x0067a7cc.g_pConfig.md --apply --queue-timeout 240
```
