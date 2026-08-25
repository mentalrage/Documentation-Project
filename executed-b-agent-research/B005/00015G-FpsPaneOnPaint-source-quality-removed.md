<!-- REMOVED-MATERIAL-ARCHIVE -->
# Removed Material Archive

- Status: Non-authoritative archival material only.
- Source report: `E:\NTK\GhidraBridge\source-3\project-documentation\executed-b-agent-research\B005\00015G-FpsPaneOnPaint-source-quality.md`
- Safety: This file must never be executed, replayed, or used as an operational runbook.
- Credit: This archive provides no gate, score, coverage, IDA, validator, or lifecycle credit.

# Removed Executable Code Archive

- Source report: [00015G-FpsPaneOnPaint-source-quality.md](00015G-FpsPaneOnPaint-source-quality.md)
- Source report SHA256 before cleanup: `9C63398555E7471A8DAE314F5F01AC9D1D468E4F06C5FCEAADD79FAD1913DFF2`
- Cleanup generated: `2026-08-11T12:47:08Z`
- Removed executable blocks: `2`
- Scope: exact executable or command-shaped fenced blocks removed from the source report by supervisor housekeeping.
- Authority: this file is not a B-agent research report and grants no Gate 1, Gate 2, IDA, validator, score, or lifecycle credit.
- Safety: do not execute, import, evaluate, or use any block in this archive as an operational instruction.

## Removed Block R001

- Original source lines: `370-374`
- Original language: `powershell`
- Block SHA256: `EE7DDD29DE551927F4BBD6199F7564CD27BC9192D27248D7EE9ABDC86C17808E`

```powershell
python tools\validator.py --mode file --file by-memory\0x004b67b0-0x004b68ab.FpsPaneOnPaint.md --apply --queue-timeout 240
python tools\validator.py --mode file --file by-class\FpsPane.md --apply --queue-timeout 240
python tools\validator.py --mode file --file by-file\FpsPane.md --apply --queue-timeout 240
```

## Removed Block R002

- Original source lines: `378-386`
- Original language: `powershell`
- Block SHA256: `CFE41814EAC47465D74131C1398BD3258F84294C9E7B487ED903C17A9FCF666B`

```powershell
python tools\validator.py --mode file --file by-type\by-struct\FpsPaneLayout.md --apply --queue-timeout 240
python tools\validator.py --mode file --file by-type\by-vtable\FpsPane_vtables.md --apply --queue-timeout 240
python tools\validator.py --mode file --file by-memory\0x0061a61c-0x0061a6a4.FpsPaneVtableData.md --apply --queue-timeout 240
python tools\validator.py --mode file --file by-memory\0x0061a6a4-0x0061a7dc.FpsPaneDiagnosticStringData.md --apply --queue-timeout 240
python tools\validator.py --mode file --file by-memory\0x004b95e0-0x004b969f.GrafPortDrawStateAccessors.md --apply --queue-timeout 240
python tools\validator.py --mode file --file by-memory\0x004ba9a0-0x004bad66.GrafPortTextRunHelpers.md --apply --queue-timeout 240
python tools\validator.py --mode file --file by-global\SurfaceRenderCallbackTable.md --apply --queue-timeout 240
```
