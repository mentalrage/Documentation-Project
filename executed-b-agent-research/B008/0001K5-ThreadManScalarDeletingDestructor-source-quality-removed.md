<!-- REMOVED-MATERIAL-ARCHIVE -->
# Removed Material Archive

- Status: Non-authoritative archival material only.
- Source report: `E:\NTK\GhidraBridge\source-3\project-documentation\executed-b-agent-research\B008\0001K5-ThreadManScalarDeletingDestructor-source-quality.md`
- Safety: This file must never be executed, replayed, or used as an operational runbook.
- Credit: This archive provides no gate, score, coverage, IDA, validator, or lifecycle credit.

# Removed Executable Code Archive

- Source report: [0001K5-ThreadManScalarDeletingDestructor-source-quality.md](0001K5-ThreadManScalarDeletingDestructor-source-quality.md)
- Source report SHA256 before cleanup: `2DF6DF912EADFA8704306721DB8707E38BE039FC9A7E540EA083B5E879377D93`
- Cleanup generated: `2026-08-11T12:47:13Z`
- Removed executable blocks: `2`
- Scope: exact executable or command-shaped fenced blocks removed from the source report by supervisor housekeeping.
- Authority: this file is not a B-agent research report and grants no Gate 1, Gate 2, IDA, validator, score, or lifecycle credit.
- Safety: do not execute, import, evaluate, or use any block in this archive as an operational instruction.

## Removed Block R001

- Original source lines: `384-397`
- Original language: `powershell`
- Block SHA256: `87882B75B7492256835555F6E891DD1707731B0C2AFBECFD9148650A02730829`

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
```

## Removed Block R002

- Original source lines: `401-404`
- Original language: `powershell`
- Block SHA256: `A094D8816EC0F0EB257307E9C7B17DFA917C032062168030F9BA3F2283887D29`

```powershell
python .\tools\validator.py --mode file --file .\by-memory\0x0069be08-0x0069be0c.g_pThreadMan.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file .\by-memory\0x00596250-0x0059756e.ThreadAndThreadMan.md --apply --queue-timeout 240
```
