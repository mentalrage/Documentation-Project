<!-- REMOVED-MATERIAL-ARCHIVE -->
# Removed Material Archive

- Status: Non-authoritative archival material only.
- Source report: `E:\NTK\GhidraBridge\source-3\project-documentation\executed-b-agent-research\B012\0001K5-ThreadManScalarDeletingDestructor-source-quality.md`
- Safety: This file must never be executed, replayed, or used as an operational runbook.
- Credit: This archive provides no gate, score, coverage, IDA, validator, or lifecycle credit.

# Removed Executable Code Archive

- Source report: [0001K5-ThreadManScalarDeletingDestructor-source-quality.md](0001K5-ThreadManScalarDeletingDestructor-source-quality.md)
- Source report SHA256 before cleanup: `09118BA120D91F7E9B62940C7250A0B56BE8C5FD0A78292BEB8FF4D95E61DB6B`
- Cleanup generated: `2026-08-11T12:47:17Z`
- Removed executable blocks: `2`
- Scope: exact executable or command-shaped fenced blocks removed from the source report by supervisor housekeeping.
- Authority: this file is not a B-agent research report and grants no Gate 1, Gate 2, IDA, validator, score, or lifecycle credit.
- Safety: do not execute, import, evaluate, or use any block in this archive as an operational instruction.

## Removed Block R001

- Original source lines: `572-586`
- Original language: `powershell`
- Block SHA256: `25A3F96712D47CCD68F8D94971F1A48215ED701609C23FF71817A9538FD6D342`

```powershell
python .\tools\validator.py --mode file --file .\by-memory\0x005974f0-0x0059756e.ThreadManScalarDeletingDestructor.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file .\by-class\ThreadMan.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file .\by-file\Thread.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file .\by-type\by-struct\ThreadManLayout.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file .\by-type\by-struct\ThreadManWatchRecord.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file .\by-memory\0x00596d20-0x00596e0b.ThreadManRawMessageWrappers.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file .\by-memory\0x00596bf0-0x00596d13.ThreadManConstructor.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file .\by-memory\0x00596e10-0x005970df.ThreadManWorkerLoop.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file .\by-memory\0x005971b0-0x005974da.ThreadManWatchListRawHelpers.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file .\by-memory\0x005974e0-0x005974eb.ClearThreadManSingleton.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file .\by-global\g_pThreadMan.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file .\by-memory\0x0062e268-0x0062e334.ThreadReadOnlyData.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file .\by-memory\0x00596250-0x0059756e.ThreadAndThreadMan.md --apply --queue-timeout 240
```

## Removed Block R002

- Original source lines: `596-598`
- Original language: `powershell`
- Block SHA256: `71E8FD6DC5FF9696938E52D3A6F41701994A1A0FA0643D8A1C890204F7A8A035`

```powershell
python .\tools\validator.py --mode file --file .\by-memory\0x005974f0-0x0059756e.ThreadManScalarDeletingDestructor.md --queue-timeout 240
```
