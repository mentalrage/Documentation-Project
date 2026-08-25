<!-- REMOVED-MATERIAL-ARCHIVE -->
# Removed Material Archive

- Status: Non-authoritative archival material only.
- Source report: `E:\NTK\GhidraBridge\source-3\project-documentation\executed-b-agent-research\B001\005971ad-threadman-watch-list-raw-cluster.md`
- Safety: This file must never be executed, replayed, or used as an operational runbook.
- Credit: This archive provides no gate, score, coverage, IDA, validator, or lifecycle credit.

# Removed Executable Code Archive

- Source report: [005971ad-threadman-watch-list-raw-cluster.md](005971ad-threadman-watch-list-raw-cluster.md)
- Source report SHA256 before cleanup: `6250C7E52CD085F14D19AD4B9775B0293648F56AE2EC6EF873AA4EE3FA913B78`
- Cleanup generated: `2026-08-11T12:47:00Z`
- Removed executable blocks: `2`
- Scope: exact executable or command-shaped fenced blocks removed from the source report by supervisor housekeeping.
- Authority: this file is not a B-agent research report and grants no Gate 1, Gate 2, IDA, validator, score, or lifecycle credit.
- Safety: do not execute, import, evaluate, or use any block in this archive as an operational instruction.

## Removed Block R001

- Original source lines: `229-235`
- Original language: `powershell`
- Block SHA256: `AB0A783017AE64B1E5275E68E38F6F48CBCBBD4DA8E9C88C2F16D0C6BB7E328C`

```powershell
python .\tools\validator.py --mode file --file by-memory\0x005971b0-0x005974da.ThreadManWatchListRawHelpers.md --apply --lock-timeout -1
python .\tools\validator.py --mode file --file by-memory\-ignored.md --apply --lock-timeout -1
python .\tools\validator.py --mode file --file by-memory\-coverage-report.md --apply --lock-timeout -1
python .\tools\memory_ranges.py report
rg -n "005971ad|005971b0|005974da|005974e0|ThreadManWatchListRawHelpers" by-memory
```

## Removed Block R002

- Original source lines: `239-243`
- Original language: `powershell`
- Block SHA256: `B7693AB71671FF0567D24FAD47E8250D57AB2F9741A2337E12BCCF5CAF955F87`

```powershell
python .\tools\validator.py --mode file --file by-memory\0x00596250-0x0059756e.ThreadAndThreadMan.md --apply --lock-timeout -1
python .\tools\validator.py --mode file --file by-class\ThreadMan.md --apply --lock-timeout -1
python .\tools\validator.py --mode file --file by-file\Thread.md --apply --lock-timeout -1
```
