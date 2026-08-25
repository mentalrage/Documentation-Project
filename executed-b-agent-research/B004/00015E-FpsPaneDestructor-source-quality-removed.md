<!-- REMOVED-MATERIAL-ARCHIVE -->
# Removed Material Archive

- Status: Non-authoritative archival material only.
- Source report: `E:\NTK\GhidraBridge\source-3\project-documentation\executed-b-agent-research\B004\00015E-FpsPaneDestructor-source-quality.md`
- Safety: This file must never be executed, replayed, or used as an operational runbook.
- Credit: This archive provides no gate, score, coverage, IDA, validator, or lifecycle credit.

# Removed Executable Code Archive

- Source report: [00015E-FpsPaneDestructor-source-quality.md](00015E-FpsPaneDestructor-source-quality.md)
- Source report SHA256 before cleanup: `66319D5F662B1C936F23D1AFF4B8EF4C10F1D4558A58755F5E4226F420F33353`
- Cleanup generated: `2026-08-11T12:47:06Z`
- Removed executable blocks: `2`
- Scope: exact executable or command-shaped fenced blocks removed from the source report by supervisor housekeeping.
- Authority: this file is not a B-agent research report and grants no Gate 1, Gate 2, IDA, validator, score, or lifecycle credit.
- Safety: do not execute, import, evaluate, or use any block in this archive as an operational instruction.

## Removed Block R001

- Original source lines: `326-328`
- Original language: `powershell`
- Block SHA256: `97B9101DBA3AF4983A2BF6A65B218D9513B12BD18DDB238F800A3F2F74B253DA`

```powershell
python .\tools\validator.py --mode file --file by-memory\0x004b6470-0x004b6499.FpsPaneDestructor.md --apply --queue-timeout 240
```

## Removed Block R002

- Original source lines: `332-340`
- Original language: `powershell`
- Block SHA256: `BD544419D074014E277632D700AB701B4B9A96ED91C067F479387E1153F2406F`

```powershell
python .\tools\validator.py --mode file --file by-class\FpsPane.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-file\FpsPane.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-memory\0x004b6c50-0x004b6caf.FpsPaneScalarDeletingDestructor.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-memory\0x004b6410-0x004b6caf.FpsPaneDiagnostics.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-global\g_pFpsPane.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-type\by-vtable\FpsPane_vtables.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-memory\0x0061a61c-0x0061a6a4.FpsPaneVtableData.md --apply --queue-timeout 240
```
