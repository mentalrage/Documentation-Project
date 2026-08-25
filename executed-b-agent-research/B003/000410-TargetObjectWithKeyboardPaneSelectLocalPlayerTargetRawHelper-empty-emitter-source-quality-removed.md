<!-- REMOVED-MATERIAL-ARCHIVE -->
# Removed Material Archive

- Status: Non-authoritative archival material only.
- Source report: `E:\NTK\GhidraBridge\source-3\project-documentation\executed-b-agent-research\B003\000410-TargetObjectWithKeyboardPaneSelectLocalPlayerTargetRawHelper-empty-emitter-source-quality.md`
- Safety: This file must never be executed, replayed, or used as an operational runbook.
- Credit: This archive provides no gate, score, coverage, IDA, validator, or lifecycle credit.

# Removed Executable Code Archive

- Source report: [000410-TargetObjectWithKeyboardPaneSelectLocalPlayerTargetRawHelper-empty-emitter-source-quality.md](000410-TargetObjectWithKeyboardPaneSelectLocalPlayerTargetRawHelper-empty-emitter-source-quality.md)
- Source report SHA256 before cleanup: `62CA28DC180FB15FB1AB5B3F7E7F260385CA0CB423010CFBC02DAB5E6FDBE22E`
- Cleanup generated: `2026-08-11T12:47:06Z`
- Removed executable blocks: `1`
- Scope: exact executable or command-shaped fenced blocks removed from the source report by supervisor housekeeping.
- Authority: this file is not a B-agent research report and grants no Gate 1, Gate 2, IDA, validator, score, or lifecycle credit.
- Safety: do not execute, import, evaluate, or use any block in this archive as an operational instruction.

## Removed Block R001

- Original source lines: `532-538`
- Original language: `powershell`
- Block SHA256: `DD69D5778BA2DB40704AD6513746E5CCF131B6B1ED1F8D83CEA3400FF35074B1`

```powershell
python .\tools\validator.py --mode file --file by-memory\0x005b06b0-0x005b06ef.TargetObjectWithKeyboardPaneSelectLocalPlayerTargetRawHelper.md --apply --queue-timeout 240 --wait-generated
python .\tools\validator.py --mode file --file by-memory\0x005b05d0-0x005b06ef.TargetObjectWithKeyboardPaneNavigationRawHelpers.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-class\TargetObjectWithKeyboardPane.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-file\TargetSelectionInputPanes.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-memory\0x005b0010-0x005b01da.TargetObjectWithKeyboardPaneKeyboardEvent.md --apply --queue-timeout 240
```
