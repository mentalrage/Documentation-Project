<!-- REMOVED-MATERIAL-ARCHIVE -->
# Removed Material Archive

- Status: Non-authoritative archival material only.
- Source report: `E:\NTK\GhidraBridge\source-3\project-documentation\executed-b-agent-research\B005\00017N-ItemObjImageLibLocalMethodCluster-source-quality.md`
- Safety: This file must never be executed, replayed, or used as an operational runbook.
- Credit: This archive provides no gate, score, coverage, IDA, validator, or lifecycle credit.

# Removed Executable Code Archive

- Source report: [00017N-ItemObjImageLibLocalMethodCluster-source-quality.md](00017N-ItemObjImageLibLocalMethodCluster-source-quality.md)
- Source report SHA256 before cleanup: `7D59926E4D62FC5462F8BBE6C6EA289BE62AB00B36912861CD3C7D0A232D72AD`
- Cleanup generated: `2026-08-11T12:47:08Z`
- Removed executable blocks: `1`
- Scope: exact executable or command-shaped fenced blocks removed from the source report by supervisor housekeeping.
- Authority: this file is not a B-agent research report and grants no Gate 1, Gate 2, IDA, validator, score, or lifecycle credit.
- Safety: do not execute, import, evaluate, or use any block in this archive as an operational instruction.

## Removed Block R001

- Original source lines: `307-316`
- Original language: `powershell`
- Block SHA256: `543D95E025804CB2083EEDC55E6D1059BA6866F96120FD3B3B5A3D35C2DBB118`

```powershell
python .\tools\validator.py --mode file --file by-memory\0x004dec30-0x004df500.ItemObjImageLibLocalMethodCluster.md --apply --queue-timeout 240 --wait-generated
python .\tools\validator.py --mode file --file by-memory\0x004dee50-0x004defba.ItemObjImageLibDrawItemImage.md --apply --queue-timeout 240 --wait-generated
python .\tools\validator.py --mode file --file by-memory\0x004defc0-0x004df1d4.ItemObjImageLibDrawItemImageIn43x43Slot.md --apply --queue-timeout 240 --wait-generated
python .\tools\validator.py --mode file --file by-memory\0x004df1e0-0x004df2b7.ItemObjImageLibDrawItemImageUnscaled.md --apply --queue-timeout 240 --wait-generated
python .\tools\validator.py --mode file --file by-memory\0x004df2c0-0x004df455.ItemObjImageLibDrawItemImageScaled.md --apply --queue-timeout 240 --wait-generated
python .\tools\validator.py --mode file --file by-memory\0x004df460-0x004df4f9.GetItemGlyphBounds.md --apply --queue-timeout 240 --wait-generated
python .\tools\validator.py --mode file --file by-file\ItemObjImageLib.md --apply --queue-timeout 240 --wait-generated
python .\tools\validator.py --mode file --file by-class\ItemObjImageLib.md --apply --queue-timeout 240 --wait-generated
```
