<!-- REMOVED-MATERIAL-ARCHIVE -->
# Removed Material Archive

- Status: Non-authoritative archival material only.
- Source report: `E:\NTK\GhidraBridge\source-3\project-documentation\executed-b-agent-research\B001\0002IE-HierListRemoveNode-source-quality.md`
- Safety: This file must never be executed, replayed, or used as an operational runbook.
- Credit: This archive provides no gate, score, coverage, IDA, validator, or lifecycle credit.

# Removed Executable Code Archive

- Source report: [0002IE-HierListRemoveNode-source-quality.md](0002IE-HierListRemoveNode-source-quality.md)
- Source report SHA256 before cleanup: `F48DF8B58A2CB99B94C14CDF9636825C688E7ADCCF14AD38661E25F3B8A54CC5`
- Cleanup generated: `2026-08-11T12:46:58Z`
- Removed executable blocks: `2`
- Scope: exact executable or command-shaped fenced blocks removed from the source report by supervisor housekeeping.
- Authority: this file is not a B-agent research report and grants no Gate 1, Gate 2, IDA, validator, score, or lifecycle credit.
- Safety: do not execute, import, evaluate, or use any block in this archive as an operational instruction.

## Removed Block R001

- Original source lines: `284-289`
- Original language: `powershell`
- Block SHA256: `1278C43C0073114F62A24B713041F8602E7D624D4C8FCA6F1970B763323EAD2E`

```powershell
python .\tools\validator.py --mode file --file by-memory\0x004ceb00-0x004ceb45.HierListRemoveNode.md --apply --queue-timeout 240 --wait-generated
python .\tools\validator.py --mode file --file by-class\HierList.md --apply --queue-timeout 240 --wait-generated
python .\tools\validator.py --mode file --file by-file\HierList.md --apply --queue-timeout 240 --wait-generated
python .\tools\validator.py --mode file --file by-memory\0x004ce730-0x004cee52.HierList.md --apply --queue-timeout 240 --wait-generated
```

## Removed Block R002

- Original source lines: `293-297`
- Original language: `powershell`
- Block SHA256: `C3FE7D1BA964BAEDF0302BFDBE160D57EE7D76F4324A0925E1214F16983FEA6F`

```powershell
python .\tools\validator.py --mode file --file by-memory\0x004cec30-0x004ced0f.HierListFindNodeByData.md --apply --queue-timeout 240 --wait-generated
python .\tools\validator.py --mode file --file by-memory\0x004cebc0-0x004cebec.HierListRemoveAt.md --apply --queue-timeout 240 --wait-generated
python .\tools\validator.py --mode file --file by-memory\0x004f0480-0x004f1bf6.Layer.md --apply --queue-timeout 240 --wait-generated
```
