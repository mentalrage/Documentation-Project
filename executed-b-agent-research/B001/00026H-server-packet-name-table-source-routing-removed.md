<!-- REMOVED-MATERIAL-ARCHIVE -->
# Removed Material Archive

- Status: Non-authoritative archival material only.
- Source report: `E:\NTK\GhidraBridge\source-3\project-documentation\executed-b-agent-research\B001\00026H-server-packet-name-table-source-routing.md`
- Safety: This file must never be executed, replayed, or used as an operational runbook.
- Credit: This archive provides no gate, score, coverage, IDA, validator, or lifecycle credit.

# Removed Executable Code Archive

- Source report: [00026H-server-packet-name-table-source-routing.md](00026H-server-packet-name-table-source-routing.md)
- Source report SHA256 before cleanup: `F6A30E5D59E03695AFAEECA8D4427F49F349C2A8BC1B5044D10CA0E58B2A29A5`
- Cleanup generated: `2026-08-11T12:46:58Z`
- Removed executable blocks: `1`
- Scope: exact executable or command-shaped fenced blocks removed from the source report by supervisor housekeeping.
- Authority: this file is not a B-agent research report and grants no Gate 1, Gate 2, IDA, validator, score, or lifecycle credit.
- Safety: do not execute, import, evaluate, or use any block in this archive as an operational instruction.

## Removed Block R001

- Original source lines: `526-532`
- Original language: `powershell`
- Block SHA256: `05D605AA03C7B3E837F57D225DB51D6DED3C4CFE9CC710510133403ED3439CAB`

```powershell
python .\tools\validator.py --mode file --file by-memory/0x00625008-0x0062ce50.ServerPacketNameTable.md --apply --lock-timeout -1
python .\tools\validator.py --mode file --file by-memory/0x0062ce50-0x0062cfd8.NetworkAndAudioReadOnlyData.md --apply --lock-timeout -1
python .\tools\validator.py --mode file --file by-memory/0x0062cfd8-0x0062d418.SpellInventoryMacroReadOnlyData.md --apply --lock-timeout -1
python .\tools\validator.py --mode file --file by-memory/-coverage-report.md --apply --lock-timeout -1
python .\tools\memory_ranges.py report
```
