<!-- REMOVED-MATERIAL-ARCHIVE -->
# Removed Material Archive

- Status: Non-authoritative archival material only.
- Source report: `E:\NTK\GhidraBridge\source-3\project-documentation\executed-b-agent-research\B008\0002BI-NetsgoStartupAuthenticationParser-source-quality.md`
- Safety: This file must never be executed, replayed, or used as an operational runbook.
- Credit: This archive provides no gate, score, coverage, IDA, validator, or lifecycle credit.

# Removed Executable Code Archive

- Source report: [0002BI-NetsgoStartupAuthenticationParser-source-quality.md](0002BI-NetsgoStartupAuthenticationParser-source-quality.md)
- Source report SHA256 before cleanup: `CAED572F7CB5B78DB76126D2E0AF0A8BD400E81A5A116BAD2AD7A919DF52D636`
- Cleanup generated: `2026-08-11T12:47:13Z`
- Removed executable blocks: `2`
- Scope: exact executable or command-shaped fenced blocks removed from the source report by supervisor housekeeping.
- Authority: this file is not a B-agent research report and grants no Gate 1, Gate 2, IDA, validator, score, or lifecycle credit.
- Safety: do not execute, import, evaluate, or use any block in this archive as an operational instruction.

## Removed Block R001

- Original source lines: `419-430`
- Original language: `powershell`
- Block SHA256: `894B7519547EB21E7975DDBBF3FA5E3DDFCFB805E7B0C869D1A307BB5BFEFBB7`

```powershell
python .\tools\validator.py --mode file --file by-memory/0x0048f6d0-0x0048fc96.NetsgoStartupAuthenticationParser.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-memory/0x0048f400-0x00491b28.RegistryCommandLineParsers.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-file/RegistryConfig.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-class/RegistryConfig.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-memory/0x006168e8-0x00617420.RegistryConfigChannelStartupStringData.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-memory/0x0041a280-0x0041a4a8.WideApiDispatchInit.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-memory/0x0069be14-0x0069bec4.WideApiDispatchPointerTable.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-global/WideApiDispatchTable.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-file/PlatformApi.md --apply --queue-timeout 240
python .\tools\validator.py --mode autogen --apply --queue-timeout 240
```

## Removed Block R002

- Original source lines: `434-436`
- Original language: `powershell`
- Block SHA256: `E1E0EABBDCBC70DF5931C9EDBBB4103CDCBFD6EC80121A6F0C88F7F1591A6119`

```powershell
python .\tools\validator.py --mode file --file by-memory/-coverage-report.md --apply --queue-timeout 240
```
