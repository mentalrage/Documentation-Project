<!-- REMOVED-MATERIAL-ARCHIVE -->
# Removed Material Archive

- Status: Non-authoritative archival material only.
- Source report: `E:\NTK\GhidraBridge\source-3\project-documentation\executed-b-agent-research\B006\00011T-FontStyleCore-source-quality.md`
- Safety: This file must never be executed, replayed, or used as an operational runbook.
- Credit: This archive provides no gate, score, coverage, IDA, validator, or lifecycle credit.

# Removed Executable Code Archive

- Source report: [00011T-FontStyleCore-source-quality.md](00011T-FontStyleCore-source-quality.md)
- Source report SHA256 before cleanup: `B1A3F6B6395EB2F7D0C18E557BADB00FCF960A6659A11C6644D17F7CB060FA0E`
- Cleanup generated: `2026-08-11T12:47:10Z`
- Removed executable blocks: `1`
- Scope: exact executable or command-shaped fenced blocks removed from the source report by supervisor housekeeping.
- Authority: this file is not a B-agent research report and grants no Gate 1, Gate 2, IDA, validator, score, or lifecycle credit.
- Safety: do not execute, import, evaluate, or use any block in this archive as an operational instruction.

## Removed Block R001

- Original source lines: `600-608`
- Original language: `powershell`
- Block SHA256: `1EC62EE937377B75A420F2C8AA2500C671F2CE90F071D746066D0503BEA91EDC`

```powershell
python tools/validator.py --mode file --file by-class\FontStyle.md --apply --queue-timeout 240
python tools/validator.py --mode file --file by-file\FontStyle.md --apply --queue-timeout 240
python tools/validator.py --mode file --file by-type\by-struct\FontStyleLayout.md --apply --queue-timeout 240
python tools/validator.py --mode file --file by-memory\0x00499f10-0x00499fda.FontStyleCore.md --apply --queue-timeout 240
python tools/validator.py --mode file --file by-memory\0x004536e0-0x00453732.FontStyleClearRules.md --apply --queue-timeout 240
python tools/validator.py --mode file --file by-memory\0x0049ac60-0x0049ad74.FontStyleRuleVectorGrowth.md --apply --queue-timeout 240
python tools/validator.py --mode autogen --apply --queue-timeout 240
```
