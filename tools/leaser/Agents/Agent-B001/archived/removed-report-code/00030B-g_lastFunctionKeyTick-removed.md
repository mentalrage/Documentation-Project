<!-- REMOVED-MATERIAL-ARCHIVE -->
# Removed Material Archive

- Status: Non-authoritative archival material only.
- Source report: `E:\NTK\GhidraBridge\source-3\project-documentation\executed-b-agent-research\B001\00030B-g_lastFunctionKeyTick.md`
- Safety: This file must never be executed, replayed, or used as an operational runbook.
- Credit: This archive provides no gate, score, coverage, IDA, validator, or lifecycle credit.

# Removed Executable Code Archive

- Source report: [00030B-g_lastFunctionKeyTick.md](00030B-g_lastFunctionKeyTick.md)
- Source report SHA256 before cleanup: `A2EF80ABEB4F3984D5B3E9D2ED0C6A08B5A88A074DE309CA7912BE76129B3C47`
- Cleanup generated: `2026-08-11T12:46:59Z`
- Removed executable blocks: `2`
- Scope: exact executable or command-shaped fenced blocks removed from the source report by supervisor housekeeping.
- Authority: this file is not a B-agent research report and grants no Gate 1, Gate 2, IDA, validator, score, or lifecycle credit.
- Safety: do not execute, import, evaluate, or use any block in this archive as an operational instruction.

## Removed Block R001

- Original source lines: `344-348`
- Original language: `powershell`
- Block SHA256: `0CC62B628E8A8AB09F24775FD95E4C85B85E52B5B118A45E8B14ED927A5612E9`

```powershell
python tools\validator.py --mode file --file by-memory\0x0069bf74-0x0069bf78.g_lastFunctionKeyTick.md --apply --queue-timeout 120
python tools\validator.py --mode file --file by-memory\0x0069bf68-0x0069bf78.KeyboardInputCommandStateGlobals.md --apply --queue-timeout 120
python tools\validator.py --mode file --file by-file\LivingObjectPane.md --apply --queue-timeout 120
```

## Removed Block R002

- Original source lines: `352-356`
- Original language: `powershell`
- Block SHA256: `5E580E769528ACE45C3B596C43643F325910EE31D5FA51B5106C1464AA4341BC`

```powershell
python tools\validator.py --mode file --file by-memory\0x0069bf74-0x0069bf78.g_lastFunctionKeyTick.md --queue-timeout 120
python tools\validator.py --mode file --file by-memory\0x0069bf68-0x0069bf78.KeyboardInputCommandStateGlobals.md --queue-timeout 120
python tools\validator.py --mode file --file by-file\LivingObjectPane.md --queue-timeout 120
```
