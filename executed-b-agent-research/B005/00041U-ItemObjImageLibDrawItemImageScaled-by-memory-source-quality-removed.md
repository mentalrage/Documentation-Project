<!-- REMOVED-MATERIAL-ARCHIVE -->
# Removed Material Archive

- Status: Non-authoritative archival material only.
- Source report: `E:\NTK\GhidraBridge\source-3\project-documentation\executed-b-agent-research\B005\00041U-ItemObjImageLibDrawItemImageScaled-by-memory-source-quality.md`
- Safety: This file must never be executed, replayed, or used as an operational runbook.
- Credit: This archive provides no gate, score, coverage, IDA, validator, or lifecycle credit.

# Removed Executable Code Archive

- Source report: [00041U-ItemObjImageLibDrawItemImageScaled-by-memory-source-quality.md](00041U-ItemObjImageLibDrawItemImageScaled-by-memory-source-quality.md)
- Source report SHA256 before cleanup: `A4542A00AA7B05DD92BBA0CEBB465BAA086124799F21AF90F5C194744D7586C3`
- Cleanup generated: `2026-08-11T12:47:10Z`
- Removed executable blocks: `1`
- Scope: exact executable or command-shaped fenced blocks removed from the source report by supervisor housekeeping.
- Authority: this file is not a B-agent research report and grants no Gate 1, Gate 2, IDA, validator, score, or lifecycle credit.
- Safety: do not execute, import, evaluate, or use any block in this archive as an operational instruction.

## Removed Block R001

- Original source lines: `360-369`
- Original language: `powershell`
- Block SHA256: `FC58C71FDC13936A5189F4116EE956DE53D651C0BCCF4ACC306E6D24668EE4D3`

```powershell
python .\tools\validator.py --mode file --file by-memory\0x004df2c0-0x004df455.ItemObjImageLibDrawItemImageScaled.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-class\ItemObjImageLib.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-file\ItemObjImageLib.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-type\by-struct\ItemObjImageLibLayout.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-global\SurfaceRenderCallbackTable.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-memory\0x0069b3e0-0x0069b410.SurfaceRenderCallbackTable.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-memory\0x004ba250-0x004ba444.SurfaceSpriteBlitHelper.md --apply --queue-timeout 240
python .\tools\validator.py --mode autogen --apply --queue-timeout 240
```
