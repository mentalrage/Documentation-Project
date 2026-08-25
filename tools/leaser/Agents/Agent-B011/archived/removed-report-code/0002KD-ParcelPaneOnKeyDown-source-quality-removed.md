<!-- REMOVED-MATERIAL-ARCHIVE -->
# Removed Material Archive

- Status: Non-authoritative archival material only.
- Source report: `E:\NTK\GhidraBridge\source-3\project-documentation\executed-b-agent-research\B011\0002KD-ParcelPaneOnKeyDown-source-quality.md`
- Safety: This file must never be executed, replayed, or used as an operational runbook.
- Credit: This archive provides no gate, score, coverage, IDA, validator, or lifecycle credit.

# Removed Executable Code Archive

- Source report: [0002KD-ParcelPaneOnKeyDown-source-quality.md](0002KD-ParcelPaneOnKeyDown-source-quality.md)
- Source report SHA256 before cleanup: `000CB26B4AD65D4C7AF43610A059F7A8402882562422F830128432B0F6500B49`
- Cleanup generated: `2026-08-11T12:47:16Z`
- Removed executable blocks: `1`
- Scope: exact executable or command-shaped fenced blocks removed from the source report by supervisor housekeeping.
- Authority: this file is not a B-agent research report and grants no Gate 1, Gate 2, IDA, validator, score, or lifecycle credit.
- Safety: do not execute, import, evaluate, or use any block in this archive as an operational instruction.

## Removed Block R001

- Original source lines: `187-194`
- Original language: `powershell`
- Block SHA256: `092A46DC95112EFC316184FC401D54D3BB236E607394E120AB66BF707DBA434D`

```powershell
python .\tools\validator.py --mode file --file by-memory/0x005465e0-0x0054660a.ParcelPaneOnKeyDown.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-class/ParcelPane.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-file/ParcelPane.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-memory/0x00621bb0-0x00621d50.ParcelNotificationVtableData.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-type/by-vtable/ParcelNotificationVtableFamily.md --apply --queue-timeout 240
python .\tools\validator.py --queue-status
```
