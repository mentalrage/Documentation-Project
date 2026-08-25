<!-- REMOVED-MATERIAL-ARCHIVE -->
# Removed Material Archive

- Status: Non-authoritative archival material only.
- Source report: `E:\NTK\GhidraBridge\source-3\project-documentation\executed-b-agent-research\B002\0000ZZ-000100-changeman-method-source-quality.md`
- Safety: This file must never be executed, replayed, or used as an operational runbook.
- Credit: This archive provides no gate, score, coverage, IDA, validator, or lifecycle credit.

# Removed Executable Code Archive

- Source report: [0000ZZ-000100-changeman-method-source-quality.md](0000ZZ-000100-changeman-method-source-quality.md)
- Source report SHA256 before cleanup: `D06127691A11838FA047E6265FD182D05D1980BD36A08A69C62872A2B68CB23F`
- Cleanup generated: `2026-08-11T12:47:00Z`
- Removed executable blocks: `2`
- Scope: exact executable or command-shaped fenced blocks removed from the source report by supervisor housekeeping.
- Authority: this file is not a B-agent research report and grants no Gate 1, Gate 2, IDA, validator, score, or lifecycle credit.
- Safety: do not execute, import, evaluate, or use any block in this archive as an operational instruction.

## Removed Block R001

- Original source lines: `352-360`
- Original language: `powershell`
- Block SHA256: `D3086E1BB59AF907E06571E3AE8A013E9E6270D4F3445DE9851FE5E152D58892`

```powershell
python tools/validator.py --mode file --file by-memory/0x0047ee20-0x0047ee95.ChangeManDispatchMessage.md --apply
python tools/validator.py --mode file --file by-memory/0x0047eea0-0x0047eedf.ChangeManUnregisterObject.md --apply
python tools/validator.py --mode file --file by-class/ChangeMan.md --apply
python tools/validator.py --mode file --file by-type/by-struct/ChangeManEntry.md --apply
python tools/validator.py --mode file --file by-memory/-coverage-report.md --apply
python tools/memory_ranges.py report
python tools/validator.py --mode rescore --apply --lock-timeout -1
```

## Removed Block R002

- Original source lines: `364-367`
- Original language: `powershell`
- Block SHA256: `4B5B05151A7A4809B4212E059014CED243F6DE233A40E5DDFB7681D36DFDDC59`

```powershell
rg -n "0000ZZ|000100|ChangeManDispatchMessage|ChangeManUnregisterObject" by-memory/-coverage-report.md by-class/ChangeMan.md project-level/-auto-completion-stats.md
rg -n "OnChangeMessage|ChangeListener|messageScope|ChangeMessageScope|Message::m_type" by-class by-type by-memory
```
