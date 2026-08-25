<!-- REMOVED-MATERIAL-ARCHIVE -->
# Removed Material Archive

- Status: Non-authoritative archival material only.
- Source report: `E:\NTK\GhidraBridge\source-3\project-documentation\executed-b-agent-research\B015\0003M9-ObjectImageButtonPaneDestructorThunks-source-routing.md`
- Safety: This file must never be executed, replayed, or used as an operational runbook.
- Credit: This archive provides no gate, score, coverage, IDA, validator, or lifecycle credit.

# Removed Executable Code Archive

- Source report: [0003M9-ObjectImageButtonPaneDestructorThunks-source-routing.md](0003M9-ObjectImageButtonPaneDestructorThunks-source-routing.md)
- Source report SHA256 before cleanup: `E42D2A21C1225C47F6B1A5FEB46310BC61F14B163F2D5D9112C7E80D954539D1`
- Cleanup generated: `2026-08-11T12:47:19Z`
- Removed executable blocks: `3`
- Scope: exact executable or command-shaped fenced blocks removed from the source report by supervisor housekeeping.
- Authority: this file is not a B-agent research report and grants no Gate 1, Gate 2, IDA, validator, score, or lifecycle credit.
- Safety: do not execute, import, evaluate, or use any block in this archive as an operational instruction.

## Removed Block R001

- Original source lines: `362-369`
- Original language: `powershell`
- Block SHA256: `0187502A39C71183A12B3DE263DD33C4C702C590036C53FBE478CB4F63A8549C`

```powershell
python .\tools\validator.py --mode file --file by-memory\0x00520ae7-0x00520afd.ObjectImageButtonPaneDestructorThunks.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-class\ObjectImageButtonPane.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-file\ObjectImageControlPane.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-memory\0x00520820-0x00520a90.ObjectImageButtonPaneCore.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-memory\0x00520c60-0x00520c9b.ObjectImageButtonPaneScalarDeletingDestructor.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-memory\0x0061ec10-0x0061fa3c.MerchantMenuDialogReadOnlyData.md --apply --queue-timeout 240
```

## Removed Block R002

- Original source lines: `373-375`
- Original language: `powershell`
- Block SHA256: `DE5227A1107DC55C84EB00517AB3282A3799A2C661B2059082F319BAFA468D95`

```powershell
python .\tools\validator.py --mode autogen --apply --queue-timeout 240
```

## Removed Block R003

- Original source lines: `379-381`
- Original language: `powershell`
- Block SHA256: `80AA9C6C3DDE137200FAC407C3C7D2314D311D995236E431A8B26BE9C56934AC`

```powershell
python .\tools\validator.py --mode file --file by-memory\-coverage-report.md --apply --queue-timeout 240
```
