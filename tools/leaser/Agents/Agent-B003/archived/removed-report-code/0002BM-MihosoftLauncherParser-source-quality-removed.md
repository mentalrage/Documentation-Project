<!-- REMOVED-MATERIAL-ARCHIVE -->
# Removed Material Archive

- Status: Non-authoritative archival material only.
- Source report: `E:\NTK\GhidraBridge\source-3\project-documentation\executed-b-agent-research\B003\0002BM-MihosoftLauncherParser-source-quality.md`
- Safety: This file must never be executed, replayed, or used as an operational runbook.
- Credit: This archive provides no gate, score, coverage, IDA, validator, or lifecycle credit.

# Removed Executable Code Archive

- Source report: [0002BM-MihosoftLauncherParser-source-quality.md](0002BM-MihosoftLauncherParser-source-quality.md)
- Source report SHA256 before cleanup: `1732544F84AE7F6DEFB3FD40DB6127AB94452D412210E3ACDD8924A963A19D44`
- Cleanup generated: `2026-08-11T12:47:04Z`
- Removed executable blocks: `1`
- Scope: exact executable or command-shaped fenced blocks removed from the source report by supervisor housekeeping.
- Authority: this file is not a B-agent research report and grants no Gate 1, Gate 2, IDA, validator, score, or lifecycle credit.
- Safety: do not execute, import, evaluate, or use any block in this archive as an operational instruction.

## Removed Block R001

- Original source lines: `371-378`
- Original language: `powershell`
- Block SHA256: `4E72E1D040F36A5B4755500146BEF8740E6C9BF5ADC44F4ED10EC542F93C0B0C`

```powershell
python .\tools\validator.py --mode file --file by-memory/0x00490810-0x00490b01.MihosoftLauncherParser.md --apply --queue-timeout 240 --wait-generated
python .\tools\validator.py --mode file --file by-memory/0x0048f400-0x00491b28.RegistryCommandLineParsers.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-file/RegistryConfig.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-class/RegistryConfig.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-memory/0x006168e8-0x00617420.RegistryConfigChannelStartupStringData.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-memory/0x0067a7c8-0x0067a7cc.g_pConfig.md --apply --queue-timeout 240
```
