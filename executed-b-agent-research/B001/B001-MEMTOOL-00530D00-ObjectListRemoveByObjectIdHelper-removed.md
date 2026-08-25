<!-- REMOVED-MATERIAL-ARCHIVE -->
# Removed Material Archive

- Status: Non-authoritative archival material only.
- Source report: `E:\NTK\GhidraBridge\source-3\project-documentation\executed-b-agent-research\B001\B001-MEMTOOL-00530D00-ObjectListRemoveByObjectIdHelper.md`
- Safety: This file must never be executed, replayed, or used as an operational runbook.
- Credit: This archive provides no gate, score, coverage, IDA, validator, or lifecycle credit.

# Removed Executable Code Archive

- Source report: [B001-MEMTOOL-00530D00-ObjectListRemoveByObjectIdHelper.md](B001-MEMTOOL-00530D00-ObjectListRemoveByObjectIdHelper.md)
- Source report SHA256 before cleanup: `16646A56FA43796F6372AE1CBA1B565F26679D8F69F2B0E4284DF1BC2B2E8A0C`
- Cleanup generated: `2026-08-11T12:47:00Z`
- Removed executable blocks: `2`
- Scope: exact executable or command-shaped fenced blocks removed from the source report by supervisor housekeeping.
- Authority: this file is not a B-agent research report and grants no Gate 1, Gate 2, IDA, validator, score, or lifecycle credit.
- Safety: do not execute, import, evaluate, or use any block in this archive as an operational instruction.

## Removed Block R001

- Original source lines: `348-350`
- Original language: `powershell`
- Block SHA256: `EFC9F43DD129D28D514E171325A9C616DE8DCEF15D9089EE9441B5540D398A21`

```powershell
python tools\validator.py --mode file --file "by-memory\0x00530d00-0x00530ed9.ObjectListStaticObjectLightingSyncHelper.md" --apply
```

## Removed Block R002

- Original source lines: `356-358`
- Original language: `powershell`
- Block SHA256: `7BBC54121EB03A066A0FA17EC7652EF81F81084C1CF4FBD7AA47F4A3C0F25A12`

```powershell
rg -n "ObjectListRemoveByObjectIdHelper" "E:\NTK\GhidraBridge\source-3\project-documentation"
```
