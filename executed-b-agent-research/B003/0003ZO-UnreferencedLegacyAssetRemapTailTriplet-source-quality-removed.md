<!-- REMOVED-MATERIAL-ARCHIVE -->
# Removed Material Archive

- Status: Non-authoritative archival material only.
- Source report: `E:\NTK\GhidraBridge\source-3\project-documentation\executed-b-agent-research\B003\0003ZO-UnreferencedLegacyAssetRemapTailTriplet-source-quality.md`
- Safety: This file must never be executed, replayed, or used as an operational runbook.
- Credit: This archive provides no gate, score, coverage, IDA, validator, or lifecycle credit.

# Removed Executable Code Archive

- Source report: [0003ZO-UnreferencedLegacyAssetRemapTailTriplet-source-quality.md](0003ZO-UnreferencedLegacyAssetRemapTailTriplet-source-quality.md)
- Source report SHA256 before cleanup: `481656AF4D9081ECF417FFC4CD166511FB26E704063561D9605F02646759144A`
- Cleanup generated: `2026-08-11T12:47:06Z`
- Removed executable blocks: `2`
- Scope: exact executable or command-shaped fenced blocks removed from the source report by supervisor housekeeping.
- Authority: this file is not a B-agent research report and grants no Gate 1, Gate 2, IDA, validator, score, or lifecycle credit.
- Safety: do not execute, import, evaluate, or use any block in this archive as an operational instruction.

## Removed Block R001

- Original source lines: `349-364`
- Original language: `powershell`
- Block SHA256: `A019FD6027517B8DB65854E6FCA403EDE164CD86E9DA68A4BC44D03BD846FC6D`

```powershell
Get-Content -LiteralPath "...\Agent-B003\goal.md"
Get-Content -LiteralPath "...\Agent-B003\notes.md"
Get-Content -LiteralPath "...\Supervisor.md"
Get-Content -LiteralPath "...\by-structure.md"
Get-Content -LiteralPath "...\inference_research.md"
Get-Content -LiteralPath "...\by-project-structure\proposed-source-tree.md"
rg --files "...\project-documentation" | rg "(0066da|UnreferencedLegacyAssetRemap|LegacyAssetRemap|g_useEpfAssets|MapPane|ItemObjImageLib|MapTileImageLib|ImageLib|00027I|0003ZO|0003ZL|0003ZM|0003ZN|00027J)"
rg -n "0003ZO|0066dae0|UnreferencedLegacyAssetRemapTailTriplet" "...\by-memory\-coverage-report.md" "...\project-level\-auto-completion-stats.md"
rg -n "0066dae0|0066daec|0066daa4|0066dabc|0066dad4|LegacyAssetRemap|legacy.*remap|remap|g_useEpfAssets|EPF|EPD|0x0093|0x00a9|0x00aa|UnknownTail" support docs
Invoke-WebRequest http://127.0.0.1:13337/mcp ...
python inline PE parser/scanner against E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe
python tools\int_convert.py 0x93 / 0xa9 / 0xaa / 0xc / 0x6 / 0x0066dae0 / 0x0066daec
rg -n "66DAE0|0066dae0|0x0093|0x00a9|0x00aa|UnknownTail|LegacyAssetRemap|g_legacyAssetRemapUnknownTail|g_currentAssetRemapUnknownTail" auto-generated and Agents folders
python tools\validator.py --mode file --file by-memory\0x0066dae0-0x0066daec.UnreferencedLegacyAssetRemapTailTriplet.md
```

## Removed Block R002

- Original source lines: `378-385`
- Original language: `powershell`
- Block SHA256: `986D3780BCF8F11D3EF09E11430E6F034EFD5CA034E55730C7E1DAE28A69B440`

```powershell
Set-Location E:\NTK\GhidraBridge\source-3\project-documentation
python .\tools\validator.py --mode file --file .\by-memory\0x0066dae0-0x0066daec.UnreferencedLegacyAssetRemapTailTriplet.md --apply --lock-timeout -1
python .\tools\validator.py --mode autogen --apply --lock-timeout -1
python .\tools\validator.py --mode rescore --apply --lock-timeout -1
python .\tools\memory_ranges.py report --apply
python .\tools\unresolved.py scan --apply
```
