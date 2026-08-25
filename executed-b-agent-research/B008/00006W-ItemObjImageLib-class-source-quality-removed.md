<!-- REMOVED-MATERIAL-ARCHIVE -->
# Removed Material Archive

- Status: Non-authoritative archival material only.
- Source report: `E:\NTK\GhidraBridge\source-3\project-documentation\executed-b-agent-research\B008\00006W-ItemObjImageLib-class-source-quality.md`
- Safety: This file must never be executed, replayed, or used as an operational runbook.
- Credit: This archive provides no gate, score, coverage, IDA, validator, or lifecycle credit.

# Removed Executable Code Archive

- Source report: [00006W-ItemObjImageLib-class-source-quality.md](00006W-ItemObjImageLib-class-source-quality.md)
- Source report SHA256 before cleanup: `CE6D90CF1DAA3F501D4BB8388765FC48A7E7337ECC0E9839631FF3A0DE998BCB`
- Cleanup generated: `2026-08-11T12:47:13Z`
- Removed executable blocks: `1`
- Scope: exact executable or command-shaped fenced blocks removed from the source report by supervisor housekeeping.
- Authority: this file is not a B-agent research report and grants no Gate 1, Gate 2, IDA, validator, score, or lifecycle credit.
- Safety: do not execute, import, evaluate, or use any block in this archive as an operational instruction.

## Removed Block R001

- Original source lines: `395-407`
- Original language: `powershell`
- Block SHA256: `55EC5E56A8D05AA5E6345FEAC0FB0FFCAC85BD25CD872BF282690CDEBF1E2ACC`

```powershell
python .\tools\validator.py --mode file --file by-class\ItemObjImageLib.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-file\ItemObjImageLib.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-type\by-struct\ItemObjImageLibLayout.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-type\by-struct\ItemInfo.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-type\by-vtable\ItemObjImageLibVtable.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-memory\0x0061b738-0x0061b748.ItemObjImageLibVtableData.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-memory\0x004dec30-0x004df500.ItemObjImageLibLocalMethodCluster.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-item\GetItemGlyphBounds_004DF460.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-class\-coverage-report.md --apply --queue-timeout 240
python .\tools\validator.py --mode autogen --apply --queue-timeout 240
python .\tools\validator.py --mode rescore --apply --queue-timeout 240
```
