<!-- REMOVED-MATERIAL-ARCHIVE -->
# Removed Material Archive

- Status: Non-authoritative archival material only.
- Source report: `E:\NTK\GhidraBridge\source-3\project-documentation\executed-b-agent-research\B005\0001CZ-NumberInputDialogAdjustorThunks-source-quality.md`
- Safety: This file must never be executed, replayed, or used as an operational runbook.
- Credit: This archive provides no gate, score, coverage, IDA, validator, or lifecycle credit.

# Removed Executable Code Archive

- Source report: [0001CZ-NumberInputDialogAdjustorThunks-source-quality.md](0001CZ-NumberInputDialogAdjustorThunks-source-quality.md)
- Source report SHA256 before cleanup: `54FB935DAAF80CF0E1CB45F0190CF56259CFC09216EF3755E70557958447969F`
- Cleanup generated: `2026-08-11T12:47:08Z`
- Removed executable blocks: `2`
- Scope: exact executable or command-shaped fenced blocks removed from the source report by supervisor housekeeping.
- Authority: this file is not a B-agent research report and grants no Gate 1, Gate 2, IDA, validator, score, or lifecycle credit.
- Safety: do not execute, import, evaluate, or use any block in this archive as an operational instruction.

## Removed Block R001

- Original source lines: `499-503`
- Original language: `powershell`
- Block SHA256: `B35B777B779BA0323EA7AD9EDA2558262358162D8CA6DE62D542C269D7A32D0E`

```powershell
python tools/validator.py --queue-timeout 240 --mode file --file by-memory/0x00530c78-0x00530c8e.NumberInputDialogAdjustorThunks.md --apply
python tools/validator.py --queue-timeout 240 --mode autogen --apply
python tools/validator.py --queue-timeout 240 --mode rescore --apply
```

## Removed Block R002

- Original source lines: `507-513`
- Original language: `powershell`
- Block SHA256: `ACFA9CD0BD42A43C4FC81A2A09241F74AD4C9B5FA445D745A008E1CA0169AF7F`

```powershell
python tools/validator.py --queue-timeout 240 --mode file --file by-class/NumberInputDialog.md --apply
python tools/validator.py --queue-timeout 240 --mode file --file by-file/NumberInputDialog.md --apply
python tools/validator.py --queue-timeout 240 --mode file --file by-memory/0x00530640-0x00530cf7.NumberInputDialog.md --apply
python tools/validator.py --queue-timeout 240 --mode file --file by-memory/0x00530c90-0x00530cf7.NumberInputDialogScalarDeletingDestructor.md --apply
python tools/validator.py --queue-timeout 240 --mode file --file by-memory/0x006201d0-0x0062026c.NumberInputDialogVtableData.md --apply
```
