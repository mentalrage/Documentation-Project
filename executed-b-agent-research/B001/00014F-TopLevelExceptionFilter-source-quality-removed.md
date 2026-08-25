<!-- REMOVED-MATERIAL-ARCHIVE -->
# Removed Material Archive

- Status: Non-authoritative archival material only.
- Source report: `E:\NTK\GhidraBridge\source-3\project-documentation\executed-b-agent-research\B001\00014F-TopLevelExceptionFilter-source-quality.md`
- Safety: This file must never be executed, replayed, or used as an operational runbook.
- Credit: This archive provides no gate, score, coverage, IDA, validator, or lifecycle credit.

# Removed Executable Code Archive

- Source report: [00014F-TopLevelExceptionFilter-source-quality.md](00014F-TopLevelExceptionFilter-source-quality.md)
- Source report SHA256 before cleanup: `1D99AC9D8F80DB4A3998842634A4F7CC34B91FB390B0E550189449797EC1ED72`
- Cleanup generated: `2026-08-11T12:46:56Z`
- Removed executable blocks: `4`
- Scope: exact executable or command-shaped fenced blocks removed from the source report by supervisor housekeeping.
- Authority: this file is not a B-agent research report and grants no Gate 1, Gate 2, IDA, validator, score, or lifecycle credit.
- Safety: do not execute, import, evaluate, or use any block in this archive as an operational instruction.

## Removed Block R001

- Original source lines: `584-586`
- Original language: `powershell`
- Block SHA256: `F8C8C8299F7823D95091F06555603FFB175B59C1065A8D97EA8D10D5501AF4FA`

```powershell
python .\tools\validator.py --mode file --file .\by-memory\0x004ab830-0x004ab86f.TopLevelExceptionFilter.md --queue-timeout 240
```

## Removed Block R002

- Original source lines: `600-603`
- Original language: `powershell`
- Block SHA256: `F1DEA6BA669C821C1650ABC1F9EA036DAC83F18C4D2B738316F3AF60FB7E90E3`

```powershell
python .\tools\validator.py --mode file --file .\by-memory\0x004ab830-0x004ab86f.TopLevelExceptionFilter.md --apply --queue-timeout 240
python .\tools\validator.py --mode autogen --apply --queue-timeout 240
```

## Removed Block R003

- Original source lines: `607-617`
- Original language: `powershell`
- Block SHA256: `4F746E8A7E5A03115742B5CBF92CDDF98EB3026EE42C5D80798726760948D92C`

```powershell
python .\tools\validator.py --mode file --file .\by-memory\0x004ab480-0x004ac89a.ExceptionHandler.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file .\by-class\ExceptionHandler.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file .\by-file\ExceptionHandler.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file .\by-global\g_pCrashTarget.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file .\by-memory\0x0067ab34-0x0067ab38.g_pCrashTarget.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file .\by-global\g_pKeySpeedMgr.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file .\by-memory\0x004eff30-0x004eff5d.KeySpeedMgrRestoreSystemKeyboardSettings.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file .\by-meta\client_crash_diagnostics.md --apply --queue-timeout 240
python .\tools\validator.py --mode autogen --apply --queue-timeout 240
```

## Removed Block R004

- Original source lines: `621-624`
- Original language: `powershell`
- Block SHA256: `EB0BAADFA08D6EA02E995A8ED80149E5E1660261C5991C5CEBEBEACF16A10195`

```powershell
Get-Content .\auto-generated\NexusTK\platform\ExceptionHandler.cpp |
  Select-String -Pattern "UID:00014F|TopLevelExceptionFilter|Empty Emitter Marker|RestoreSystemKeyboardSettings|WriteCrashReport" -Context 2,8
```
