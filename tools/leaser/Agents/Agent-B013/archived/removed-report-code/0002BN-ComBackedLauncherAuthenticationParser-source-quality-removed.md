<!-- REMOVED-MATERIAL-ARCHIVE -->
# Removed Material Archive

- Status: Non-authoritative archival material only.
- Source report: `E:\NTK\GhidraBridge\source-3\project-documentation\executed-b-agent-research\B013\0002BN-ComBackedLauncherAuthenticationParser-source-quality.md`
- Safety: This file must never be executed, replayed, or used as an operational runbook.
- Credit: This archive provides no gate, score, coverage, IDA, validator, or lifecycle credit.

# Removed Executable Code Archive

- Source report: [0002BN-ComBackedLauncherAuthenticationParser-source-quality.md](0002BN-ComBackedLauncherAuthenticationParser-source-quality.md)
- Source report SHA256 before cleanup: `DA3E652567D00B3E38D441431EFAA07036D66612EBBEE6EAA2E20D18CF545935`
- Cleanup generated: `2026-08-11T12:47:17Z`
- Removed executable blocks: `1`
- Scope: exact executable or command-shaped fenced blocks removed from the source report by supervisor housekeeping.
- Authority: this file is not a B-agent research report and grants no Gate 1, Gate 2, IDA, validator, score, or lifecycle credit.
- Safety: do not execute, import, evaluate, or use any block in this archive as an operational instruction.

## Removed Block R001

- Original source lines: `371-377`
- Original language: `powershell`
- Block SHA256: `7311CBCE8D6F784C4F6A404605EA95835711A1FC00A128151C64A2E05E7C90EF`

```powershell
python .\tools\validator.py --mode file --file by-memory\0x00490b10-0x004910c0.ComBackedLauncherAuthenticationParser.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-memory\0x0048f400-0x00491b28.RegistryCommandLineParsers.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-file\RegistryConfig.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-class\RegistryConfig.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-memory\0x006168e8-0x00617420.RegistryConfigChannelStartupStringData.md --apply --queue-timeout 240
```
