<!-- REMOVED-MATERIAL-ARCHIVE -->
# Removed Material Archive

- Status: Non-authoritative archival material only.
- Source report: `E:\NTK\GhidraBridge\source-3\project-documentation\executed-b-agent-research\B007\0002TM-Decode8BitBmpToTileContext-source-quality.md`
- Safety: This file must never be executed, replayed, or used as an operational runbook.
- Credit: This archive provides no gate, score, coverage, IDA, validator, or lifecycle credit.

# Removed Executable Code Archive

- Source report: [0002TM-Decode8BitBmpToTileContext-source-quality.md](0002TM-Decode8BitBmpToTileContext-source-quality.md)
- Source report SHA256 before cleanup: `6AE7EE2FBCA0B54E796F98B367801EF24D58F22B2D695B1A78E2C4D61B7D34CB`
- Cleanup generated: `2026-08-11T12:47:12Z`
- Removed executable blocks: `4`
- Scope: exact executable or command-shaped fenced blocks removed from the source report by supervisor housekeeping.
- Authority: this file is not a B-agent research report and grants no Gate 1, Gate 2, IDA, validator, score, or lifecycle credit.
- Safety: do not execute, import, evaluate, or use any block in this archive as an operational instruction.

## Removed Block R001

- Original source lines: `372-374`
- Original language: `powershell`
- Block SHA256: `1C3E504A82264E530EBF59E5415E5742584820EE8F13F0EE277D703E75F74D14`

```powershell
rg -n "sub_4D09B0|call    sub_4D09B0|sub_4583D0|sub_458500|sub_542CD0|sub_543020|aLevelBmp|LEVEL\.BMP" "C:\Users\admin\Desktop\CTools\CPlusPlusSim\core\extra-sources\IDA-EXPORTS\NexusTK.exe.lst" "C:\Users\admin\Desktop\CTools\CPlusPlusSim\core\extra-sources\IDA-EXPORTS\NexusTK.exe.c"
```

## Removed Block R002

- Original source lines: `376-380`
- Original language: `powershell`
- Block SHA256: `BAC34823C00F581FDFE9F5527F93A3495A920F31E87BD9663D0BFABAB7C7FB1B`

```powershell
Get-Content -Path "C:\Users\admin\Desktop\CTools\CPlusPlusSim\core\extra-sources\IDA-EXPORTS\NexusTK.exe.c" | Select-Object -Skip 172960 -First 90
Get-Content -Path "C:\Users\admin\Desktop\CTools\CPlusPlusSim\core\extra-sources\IDA-EXPORTS\NexusTK.exe.lst" | Select-Object -Skip 346576 -First 125
Get-Content -Path "C:\Users\admin\Desktop\CTools\CPlusPlusSim\core\extra-sources\IDA-EXPORTS\NexusTK.exe.lst" | Select-Object -Skip 406748 -First 70
```

## Removed Block R003

- Original source lines: `382-386`
- Original language: `powershell`
- Block SHA256: `22C868E40BC2DF83E744D45B8E19E5DFB075E505CC92DF5B8A25B903481D47D7`

```powershell
@'
["0xda","0x1fc","0x224","0x28","0x0a","0x0e","0x12","0x16","0x1c","0x400","0x100","0x36"]
'@ | python source-3/project-documentation/tools/int_convert.py --pretty
```

## Removed Block R004

- Original source lines: `390-392`
- Original language: `powershell`
- Block SHA256: `DB771EFB8FF84D9DE4D40D46AEF946DA27CB44AC800EC35992659BD0ACB633E2`

```powershell
rg -n "0002TM|Decode8BitBmpToTileContext|0x004d09b0|0x004d0a8a|0x004f68bd|LoadFromRawRGBA|FreePaletteData" source-3/project-documentation
```
