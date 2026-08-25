<!-- REMOVED-MATERIAL-ARCHIVE -->
# Removed Material Archive

- Status: Non-authoritative archival material only.
- Source report: `E:\NTK\GhidraBridge\source-3\project-documentation\executed-b-agent-research\B003\0002IA-HierListTailInsertWrapper-source-quality.md`
- Safety: This file must never be executed, replayed, or used as an operational runbook.
- Credit: This archive provides no gate, score, coverage, IDA, validator, or lifecycle credit.

# Removed Executable Code Archive

- Source report: [0002IA-HierListTailInsertWrapper-source-quality.md](0002IA-HierListTailInsertWrapper-source-quality.md)
- Source report SHA256 before cleanup: `FE03FAFDED1A8870442987A710EEBF9A1F088C96D99F30FD8A178A8B82BCB81D`
- Cleanup generated: `2026-08-11T12:47:05Z`
- Removed executable blocks: `5`
- Scope: exact executable or command-shaped fenced blocks removed from the source report by supervisor housekeeping.
- Authority: this file is not a B-agent research report and grants no Gate 1, Gate 2, IDA, validator, score, or lifecycle credit.
- Safety: do not execute, import, evaluate, or use any block in this archive as an operational instruction.

## Removed Block R001

- Original source lines: `276-283`
- Original language: `powershell`
- Block SHA256: `3B13C5327494B9F173D55F2674FE116F194CE5DA894B31E6041D70BF73E6ED72`

```powershell
python .\tools\validator.py --mode file --file by-memory\0x004ce7e0-0x004ce839.HierListTailInsertWrapper.md --apply --queue-timeout 240 --wait-generated
python .\tools\validator.py --mode file --file by-class\HierList.md --apply --queue-timeout 240 --wait-generated
python .\tools\validator.py --mode file --file by-file\HierList.md --apply --queue-timeout 240 --wait-generated
python .\tools\validator.py --mode file --file by-memory\0x004ce860-0x004ce9ad.HierListInsertBefore.md --apply --queue-timeout 240 --wait-generated
python .\tools\validator.py --mode file --file by-memory\0x004ce840-0x004ce854.HierListDefaultInsertWrapper.md --apply --queue-timeout 240 --wait-generated
python .\tools\validator.py --mode file --file by-memory\0x004ce730-0x004cee52.HierList.md --apply --queue-timeout 240 --wait-generated
```

## Removed Block R002

- Original source lines: `289-293`
- Original language: `powershell`
- Block SHA256: `B9AB28F05410F8735BDB8C7733F396D1C04BEE480AC9515297AE5A002EFF2611`

```powershell
Select-String -LiteralPath .\by-memory\0x004ce7e0-0x004ce839.HierListTailInsertWrapper.md -Pattern 'COMPLETION:90|CONFIDENCE:91|InsertLast|0x004ce7e0'
Select-String -LiteralPath .\auto-generated\NexusTK\util\HierList.cpp -Pattern '0002IA|InsertLast|Empty Emitter Marker'
Select-String -LiteralPath .\auto-generated\-ag-research-tracker.md -Pattern '0002IA'
```

## Removed Block R003

- Original source lines: `311-313`
- Original language: `powershell`
- Block SHA256: `223EE9D37A98B27F91C963E3D39E80462792F25EAD2B3D9BEDD713825B41B3DE`

```powershell
python .\tools\leaser\leaser.py Agent-B003 lease by-memory\0x004ce7e0-0x004ce839.HierListTailInsertWrapper.md by-class\HierList.md by-file\HierList.md by-memory\0x004ce860-0x004ce9ad.HierListInsertBefore.md by-memory\0x004ce840-0x004ce854.HierListDefaultInsertWrapper.md by-memory\0x004ce730-0x004cee52.HierList.md
```

## Removed Block R004

- Original source lines: `319-321`
- Original language: `powershell`
- Block SHA256: `301C9A0E5A12AE9B505C5BB301FC77641D0C64A44F73714386B0A0ECD1D06787`

```powershell
python .\tools\leaser\leaser.py Agent-B003 unlease by-memory\0x004ce7e0-0x004ce839.HierListTailInsertWrapper.md by-class\HierList.md by-file\HierList.md by-memory\0x004ce860-0x004ce9ad.HierListInsertBefore.md by-memory\0x004ce840-0x004ce854.HierListDefaultInsertWrapper.md by-memory\0x004ce730-0x004cee52.HierList.md
```

## Removed Block R005

- Original source lines: `327-329`
- Original language: `powershell`
- Block SHA256: `AC1199242E46C155A8362B70D9CADB408AA55E87113E8BB0F955E1735BF64575`

```powershell
python .\tools\validator.py --mode file --file <path> --apply --queue-timeout 240 --wait-generated
```
