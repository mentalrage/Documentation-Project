<!-- REMOVED-MATERIAL-ARCHIVE -->
# Removed Material Archive

- Status: Non-authoritative archival material only.
- Source report: `E:\NTK\GhidraBridge\source-3\project-documentation\executed-b-agent-research\B001\00016X-hierlist-source-quality.md`
- Safety: This file must never be executed, replayed, or used as an operational runbook.
- Credit: This archive provides no gate, score, coverage, IDA, validator, or lifecycle credit.

# Removed Executable Code Archive

- Source report: [00016X-hierlist-source-quality.md](00016X-hierlist-source-quality.md)
- Source report SHA256 before cleanup: `396B438B02DBDF9A98E91A99E67C493813BE74E13F31A5BADAD0365C36FDEAC0`
- Cleanup generated: `2026-08-11T12:46:56Z`
- Removed executable blocks: `2`
- Scope: exact executable or command-shaped fenced blocks removed from the source report by supervisor housekeeping.
- Authority: this file is not a B-agent research report and grants no Gate 1, Gate 2, IDA, validator, score, or lifecycle credit.
- Safety: do not execute, import, evaluate, or use any block in this archive as an operational instruction.

## Removed Block R001

- Original source lines: `281-288`
- Original language: `powershell`
- Block SHA256: `BD27B3E98660FF0D67C5C469E94B8A3C86733E2A9BD92652342481E3EF04B34C`

```powershell
python .\tools\validator.py --mode file --file .\by-memory\0x004ce730-0x004cee52.HierList.md --apply --queue-timeout 240 --lock-timeout -1
python .\tools\validator.py --mode file --file .\by-class\HierList.md --apply --queue-timeout 240 --lock-timeout -1
python .\tools\validator.py --mode file --file .\by-file\HierList.md --apply --queue-timeout 240 --lock-timeout -1
python .\tools\validator.py --mode file --file .\by-type\by-struct\HierListNode.md --apply --queue-timeout 240 --lock-timeout -1
python .\tools\validator.py --mode file --file .\by-memory\-coverage-report.md --apply --queue-timeout 240 --lock-timeout -1
python .\tools\validator.py --mode autogen --apply --queue-timeout 240 --lock-timeout -1
```

## Removed Block R002

- Original source lines: `294-297`
- Original language: `powershell`
- Block SHA256: `6E1E6CE9C431ABB0A3B3F8D1A3F7A5F2BDE0505513AF535581BB5F3AC98F85DA`

```powershell
Select-String -LiteralPath .\auto-generated\-ag-memory-coverage.md -Pattern '00016X|0002I8|0002IM|HierList.cpp'
Select-String -LiteralPath .\by-memory\-coverage-report.md -Pattern '00016X|0002IA|0002IM|0x004cee52-0x004cee60'
```
