<!-- REMOVED-MATERIAL-ARCHIVE -->
# Removed Material Archive

- Status: Non-authoritative archival material only.
- Source report: `E:\NTK\GhidraBridge\source-3\project-documentation\executed-b-agent-research\B001\00015Q-RectBoundsMethods-source-quality.md`
- Safety: This file must never be executed, replayed, or used as an operational runbook.
- Credit: This archive provides no gate, score, coverage, IDA, validator, or lifecycle credit.

# Removed Executable Code Archive

- Source report: [00015Q-RectBoundsMethods-source-quality.md](00015Q-RectBoundsMethods-source-quality.md)
- Source report SHA256 before cleanup: `2EC101508F93552140D9E192B3584D0F3281C475A3966AF4667E310FE9D0A404`
- Cleanup generated: `2026-08-11T12:46:56Z`
- Removed executable blocks: `3`
- Scope: exact executable or command-shaped fenced blocks removed from the source report by supervisor housekeeping.
- Authority: this file is not a B-agent research report and grants no Gate 1, Gate 2, IDA, validator, score, or lifecycle credit.
- Safety: do not execute, import, evaluate, or use any block in this archive as an operational instruction.

## Removed Block R001

- Original source lines: `390-395`
- Original language: `powershell`
- Block SHA256: `DD756C353FEFAE473AA9C50214137E488617F62340269870B7A847FA7134A248`

```powershell
python .\tools\validator.py --mode file --file by-memory/0x004b78d0-0x004b7ae8.RectBoundsMethods.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-class/RectBounds.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-file/RectBounds.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-type/by-struct/RectBoundsLayout.md --apply --queue-timeout 240
```

## Removed Block R002

- Original source lines: `399-401`
- Original language: `powershell`
- Block SHA256: `30A989B3ABC71C74A9664E16D6174E188261AC466140A043D6997BDDBEED5855`

```powershell
python .\tools\validator.py --mode file --file by-memory/0x004b7910-0x004b795e.RectBoundsInset.md --apply --queue-timeout 240
```

## Removed Block R003

- Original source lines: `405-407`
- Original language: `powershell`
- Block SHA256: `CA2DC0DBA238EF6495901B0E2D99EBA9F933F841968D3BB6BA6B477DC9CC17D0`

```powershell
python .\tools\validator.py execute_report B001 00015Q-RectBoundsMethods-source-quality.md 00015Q --apply
```
