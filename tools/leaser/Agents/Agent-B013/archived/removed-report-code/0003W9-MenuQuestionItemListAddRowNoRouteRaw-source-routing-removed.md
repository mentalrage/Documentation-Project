<!-- REMOVED-MATERIAL-ARCHIVE -->
# Removed Material Archive

- Status: Non-authoritative archival material only.
- Source report: `E:\NTK\GhidraBridge\source-3\project-documentation\executed-b-agent-research\B013\0003W9-MenuQuestionItemListAddRowNoRouteRaw-source-routing.md`
- Safety: This file must never be executed, replayed, or used as an operational runbook.
- Credit: This archive provides no gate, score, coverage, IDA, validator, or lifecycle credit.

# Removed Executable Code Archive

- Source report: [0003W9-MenuQuestionItemListAddRowNoRouteRaw-source-routing.md](0003W9-MenuQuestionItemListAddRowNoRouteRaw-source-routing.md)
- Source report SHA256 before cleanup: `54165F11956FB6F821FFBD0906DB81A00EB536D8620A334A6A8FC9F4E901DB72`
- Cleanup generated: `2026-08-11T12:47:18Z`
- Removed executable blocks: `2`
- Scope: exact executable or command-shaped fenced blocks removed from the source report by supervisor housekeeping.
- Authority: this file is not a B-agent research report and grants no Gate 1, Gate 2, IDA, validator, score, or lifecycle credit.
- Safety: do not execute, import, evaluate, or use any block in this archive as an operational instruction.

## Removed Block R001

- Original source lines: `385-392`
- Original language: `powershell`
- Block SHA256: `0AB217272726598BF02CCE551B7FF85A3F4C50A7690BDA9B5ACA63CBD97AC913`

```powershell
python tools\validator.py --mode file --file by-memory\0x00550dc0-0x00550e16.MenuQuestionItemListAddRowNoRouteRaw.md --apply --queue-timeout 240 --lock-timeout -1
python tools\validator.py --mode file --file by-class\MenuQuestionItemList.md --apply --queue-timeout 240 --lock-timeout -1
python tools\validator.py --mode file --file by-file\MessageDialogs.md --apply --queue-timeout 240 --lock-timeout -1
python tools\validator.py --mode file --file by-memory\0x0054ce10-0x00551021.NpcMessageAndMenuQuestionDialogs.md --apply --queue-timeout 240 --lock-timeout -1
python tools\validator.py --mode file --file by-memory\-coverage-report.md --apply --queue-timeout 240 --lock-timeout -1
python tools\validator.py --mode autogen --apply --queue-timeout 240 --lock-timeout -1
```

## Removed Block R002

- Original source lines: `396-398`
- Original language: `powershell`
- Block SHA256: `258FD24CDFEA73BCD81EEFF541E002F0B3DDD354D54E2F9A764C1725DDB1200C`

```powershell
python source-3\project-documentation\tools\validator.py --mode file --file source-3\project-documentation\by-memory\0x00550dc0-0x00550e16.MenuQuestionItemListAddRowNoRouteRaw.md --uid-only
```
