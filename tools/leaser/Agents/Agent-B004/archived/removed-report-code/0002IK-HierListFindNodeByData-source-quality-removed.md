<!-- REMOVED-MATERIAL-ARCHIVE -->
# Removed Material Archive

- Status: Non-authoritative archival material only.
- Source report: `E:\NTK\GhidraBridge\source-3\project-documentation\executed-b-agent-research\B004\0002IK-HierListFindNodeByData-source-quality.md`
- Safety: This file must never be executed, replayed, or used as an operational runbook.
- Credit: This archive provides no gate, score, coverage, IDA, validator, or lifecycle credit.

# Removed Executable Code Archive

- Source report: [0002IK-HierListFindNodeByData-source-quality.md](0002IK-HierListFindNodeByData-source-quality.md)
- Source report SHA256 before cleanup: `A6CD929F040BA126A085E163C09C213754461693E194EF075E34214B52C2AA10`
- Cleanup generated: `2026-08-11T12:47:07Z`
- Removed executable blocks: `1`
- Scope: exact executable or command-shaped fenced blocks removed from the source report by supervisor housekeeping.
- Authority: this file is not a B-agent research report and grants no Gate 1, Gate 2, IDA, validator, score, or lifecycle credit.
- Safety: do not execute, import, evaluate, or use any block in this archive as an operational instruction.

## Removed Block R001

- Original source lines: `269-274`
- Original language: `powershell`
- Block SHA256: `DD3FE54A0EA440CBE920B2B6E0FF5D0D69660F04F354D9F05FDF1E8DCAC8F306`

```powershell
python .\tools\validator.py --mode file --file by-memory\0x004cec30-0x004ced0f.HierListFindNodeByData.md --apply --queue-timeout 240 --wait-generated
python .\tools\validator.py --mode file --file by-class\HierList.md --apply --queue-timeout 240 --wait-generated
python .\tools\validator.py --mode file --file by-file\HierList.md --apply --queue-timeout 240 --wait-generated
python .\tools\validator.py --mode file --file by-type\by-struct\HierListNode.md --apply --queue-timeout 240 --wait-generated
```
