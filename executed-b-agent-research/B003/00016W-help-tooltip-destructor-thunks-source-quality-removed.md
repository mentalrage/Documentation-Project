<!-- REMOVED-MATERIAL-ARCHIVE -->
# Removed Material Archive

- Status: Non-authoritative archival material only.
- Source report: `E:\NTK\GhidraBridge\source-3\project-documentation\executed-b-agent-research\B003\00016W-help-tooltip-destructor-thunks-source-quality.md`
- Safety: This file must never be executed, replayed, or used as an operational runbook.
- Credit: This archive provides no gate, score, coverage, IDA, validator, or lifecycle credit.

# Removed Executable Code Archive

- Source report: [00016W-help-tooltip-destructor-thunks-source-quality.md](00016W-help-tooltip-destructor-thunks-source-quality.md)
- Source report SHA256 before cleanup: `62F67C04A9EB28E72A1706036444C2B45F82CA2217941CB3EB2126CD9A366BE9`
- Cleanup generated: `2026-08-11T12:47:03Z`
- Removed executable blocks: `4`
- Scope: exact executable or command-shaped fenced blocks removed from the source report by supervisor housekeeping.
- Authority: this file is not a B-agent research report and grants no Gate 1, Gate 2, IDA, validator, score, or lifecycle credit.
- Safety: do not execute, import, evaluate, or use any block in this archive as an operational instruction.

## Removed Block R001

- Original source lines: `388-393`
- Original language: `powershell`
- Block SHA256: `7086B7A46E8DE37CB51327868BF87BC40D4563CCE3F9CEA0419D87F72C219352`

```powershell
Get-Content source-3/project-documentation/tools/leaser/Agents/Agent-B003/goal.md
Get-Content source-3/project-documentation/tools/leaser/Agents/Agent-B003/notes.md
Get-Content source-3/project-documentation/inference_research.md
Get-Content source-3/project-documentation/by-structure.md
```

## Removed Block R002

- Original source lines: `397-400`
- Original language: `powershell`
- Block SHA256: `FF892DA4CA8B11E0062BB14138413023D8F85520E9227FF2218A76DC06A657CC`

```powershell
Invoke-WebRequest -UseBasicParsing -Uri http://127.0.0.1:13337/mcp ...
Get-NetTCPConnection -LocalPort 13337
```

## Removed Block R003

- Original source lines: `404-408`
- Original language: `powershell`
- Block SHA256: `F6900B776C11436E4812536E8DC727684E4163EBE0B11AC8A48ADB2EC18AFD34`

```powershell
rg -n "00016W|HelpTooltip|HelpPane|SimpleHelp|ItemHelpPane|WillBeChanged|dword_69AE04|dword_67A7D4|dword_69AE00|dword_69B414" ...
Get-Content target/support docs
Get-Content auto-generated/NexusTK/ui/controls/HelpPanes.cpp
```

## Removed Block R004

- Original source lines: `414-420`
- Original language: `powershell`
- Block SHA256: `66D4982D2D7C011327E792871197737A663BDE917ABFBB21DD74BA670FB785F5`

```powershell
python .\tools\validator.py --mode file --file by-memory\0x004ce34b-0x004ce725.HelpTooltipDestructorThunks.md --apply --queue-timeout 240 --lock-timeout -1
python .\tools\validator.py --mode file --file by-memory\-ignored.md --apply --queue-timeout 240 --lock-timeout -1
python .\tools\validator.py --mode file --file by-memory\-coverage-report.md --apply --queue-timeout 240 --lock-timeout -1
python .\tools\validator.py --mode file --file by-file\HelpPanes.md --apply --queue-timeout 240 --lock-timeout -1
python .\tools\memory_ranges.py report
```
