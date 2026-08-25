<!-- REMOVED-MATERIAL-ARCHIVE -->
# Removed Material Archive

- Status: Non-authoritative archival material only.
- Source report: `E:\NTK\GhidraBridge\source-3\project-documentation\executed-b-agent-research\B003\00041R-ItemObjImageLibDrawItemImage-by-memory-source-quality.md`
- Safety: This file must never be executed, replayed, or used as an operational runbook.
- Credit: This archive provides no gate, score, coverage, IDA, validator, or lifecycle credit.

# Removed Executable Code Archive

- Source report: [00041R-ItemObjImageLibDrawItemImage-by-memory-source-quality.md](00041R-ItemObjImageLibDrawItemImage-by-memory-source-quality.md)
- Source report SHA256 before cleanup: `5EB3A26119A2AB963E764D670B7A6DF9F8294577BB59286DCC9F4381D9BF7F85`
- Cleanup generated: `2026-08-11T12:47:06Z`
- Removed executable blocks: `1`
- Scope: exact executable or command-shaped fenced blocks removed from the source report by supervisor housekeeping.
- Authority: this file is not a B-agent research report and grants no Gate 1, Gate 2, IDA, validator, score, or lifecycle credit.
- Safety: do not execute, import, evaluate, or use any block in this archive as an operational instruction.

## Removed Block R001

- Original source lines: `350-361`
- Original language: `powershell`
- Block SHA256: `331FFAA15EBEB2F8A56744A2AD3E3B2E009B0C8A8ED8309DE0166FED55B2CE8A`

```powershell
python .\tools\validator.py --mode file --file by-memory\0x004dee50-0x004defba.ItemObjImageLibDrawItemImage.md --apply --queue-timeout 240 --wait-generated
python .\tools\validator.py --mode file --file by-class\ItemObjImageLib.md --apply --queue-timeout 240 --wait-generated
python .\tools\validator.py --mode file --file by-file\ItemObjImageLib.md --apply --queue-timeout 240 --wait-generated
python .\tools\validator.py --mode file --file by-memory\0x004dec30-0x004df500.ItemObjImageLibLocalMethodCluster.md --apply --queue-timeout 240 --wait-generated
python .\tools\validator.py --mode file --file by-global\SurfaceRenderCallbackTable.md --apply --queue-timeout 240 --wait-generated
python .\tools\validator.py --mode file --file by-memory\0x0069b3e0-0x0069b410.SurfaceRenderCallbackTable.md --apply --queue-timeout 240 --wait-generated
python .\tools\validator.py --mode file --file by-memory\0x004ba250-0x004ba444.SurfaceSpriteBlitHelper.md --apply --queue-timeout 240 --wait-generated
python .\tools\validator.py --mode file --file by-memory\0x00462f20-0x00463252.DrawEncodedAlphaFrame.md --apply --queue-timeout 240 --wait-generated
python .\tools\validator.py --mode file --file by-class\AlphaMaskSurface.md --apply --queue-timeout 240 --wait-generated
python .\tools\validator.py --mode file --file by-file\AlphaMaskSurface.md --apply --queue-timeout 240 --wait-generated
```
