<!-- REMOVED-MATERIAL-ARCHIVE -->
# Removed Material Archive

- Status: Non-authoritative archival material only.
- Source report: `E:\NTK\GhidraBridge\source-3\project-documentation\executed-b-agent-research\B001\0001FJ-textdialog-core-source-quality.md`
- Safety: This file must never be executed, replayed, or used as an operational runbook.
- Credit: This archive provides no gate, score, coverage, IDA, validator, or lifecycle credit.

# Removed Executable Code Archive

- Source report: [0001FJ-textdialog-core-source-quality.md](0001FJ-textdialog-core-source-quality.md)
- Source report SHA256 before cleanup: `B245778792BDF8BA02A96F8059F38A1670E32AA43B6D334BC719B0981F3CC719`
- Cleanup generated: `2026-08-11T12:46:57Z`
- Removed executable blocks: `1`
- Scope: exact executable or command-shaped fenced blocks removed from the source report by supervisor housekeeping.
- Authority: this file is not a B-agent research report and grants no Gate 1, Gate 2, IDA, validator, score, or lifecycle credit.
- Safety: do not execute, import, evaluate, or use any block in this archive as an operational instruction.

## Removed Block R001

- Original source lines: `272-283`
- Original language: `powershell`
- Block SHA256: `E0CF20B0A8E55A33EC764D8E2CEA2289499FD02531579BD64B1B472C01C62987`

```powershell
python .\tools\validator.py --mode file --file .\by-memory\0x00552110-0x005534a0.TextDialogCore.md --apply --lock-timeout -1
python .\tools\validator.py --mode file --file .\by-memory\0x00552110-0x0055317a.TextDialogConstructor.md --apply --lock-timeout -1
python .\tools\validator.py --mode file --file .\by-memory\0x00553180-0x00553338.TextDialogHandleDialogAction.md --apply --lock-timeout -1
python .\tools\validator.py --mode file --file .\by-memory\0x00553350-0x00553495.TextDialogUnreferencedSubmitPacketRaw.md --apply --lock-timeout -1
python .\tools\validator.py --mode file --file .\by-class\TextDialog.md --apply --lock-timeout -1
python .\tools\validator.py --mode file --file .\by-file\TextDialog.md --apply --lock-timeout -1
python .\tools\validator.py --mode file --file .\by-memory\0x0054cc30-0x0054ce0f.DialogNavigationPacketHelpers.md --apply --lock-timeout -1
python .\tools\validator.py --mode file --file .\by-memory\-ignored.md --apply --lock-timeout -1
python .\tools\validator.py --mode file --file .\by-memory\-coverage-report.md --apply --lock-timeout -1
python .\tools\memory_ranges.py report
```
