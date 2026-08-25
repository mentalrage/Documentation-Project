<!-- REMOVED-MATERIAL-ARCHIVE -->
# Removed Material Archive

- Status: Non-authoritative archival material only.
- Source report: `E:\NTK\GhidraBridge\source-3\project-documentation\executed-b-agent-research\B007\0002ID-HierListInsertAfter-source-quality.md`
- Safety: This file must never be executed, replayed, or used as an operational runbook.
- Credit: This archive provides no gate, score, coverage, IDA, validator, or lifecycle credit.

# Removed Executable Code Archive

- Source report: [0002ID-HierListInsertAfter-source-quality.md](0002ID-HierListInsertAfter-source-quality.md)
- Source report SHA256 before cleanup: `E9852D7B548F625750CCB97228476E1FF9F360C95E00E167AB8405F3528F6B90`
- Cleanup generated: `2026-08-11T12:47:12Z`
- Removed executable blocks: `2`
- Scope: exact executable or command-shaped fenced blocks removed from the source report by supervisor housekeeping.
- Authority: this file is not a B-agent research report and grants no Gate 1, Gate 2, IDA, validator, score, or lifecycle credit.
- Safety: do not execute, import, evaluate, or use any block in this archive as an operational instruction.

## Removed Block R001

- Original source lines: `257-263`
- Original language: `powershell`
- Block SHA256: `631E0E971EB07BFDAFC7C8D0155C0C98AA640DAB0AEF1F8229471778650605DA`

```powershell
python .\tools\validator.py --mode file --file by-memory\0x004ce9b0-0x004ceafc.HierListInsertAfter.md --apply --queue-timeout 240 --wait-generated
python .\tools\validator.py --mode file --file by-class\HierList.md --apply --queue-timeout 240 --wait-generated
python .\tools\validator.py --mode file --file by-file\HierList.md --apply --queue-timeout 240 --wait-generated
python .\tools\validator.py --mode file --file by-memory\0x004ce730-0x004cee52.HierList.md --apply --queue-timeout 240 --wait-generated
python .\tools\validator.py --mode file --file by-memory\0x004ce860-0x004ce9ad.HierListInsertBefore.md --apply --queue-timeout 240 --wait-generated
```

## Removed Block R002

- Original source lines: `267-270`
- Original language: `powershell`
- Block SHA256: `ADA7B11A621AC5CA55A81A6A5F7F1580D475643BE876DCCC81A3ED214C171F46`

```powershell
Select-String -LiteralPath .\by-memory\0x004ce9b0-0x004ceafc.HierListInsertAfter.md -Pattern 'COMPLETION:90|CONFIDENCE:92|InsertAfter|referenceOwnerList|0x004ce9b0'
Select-String -LiteralPath .\auto-generated\NexusTK\util\HierList.cpp -Pattern '0002ID|InsertAfter|Empty Emitter Marker'
```
