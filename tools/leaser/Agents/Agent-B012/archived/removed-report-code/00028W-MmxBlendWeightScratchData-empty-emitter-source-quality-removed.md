<!-- REMOVED-MATERIAL-ARCHIVE -->
# Removed Material Archive

- Status: Non-authoritative archival material only.
- Source report: `E:\NTK\GhidraBridge\source-3\project-documentation\executed-b-agent-research\B012\00028W-MmxBlendWeightScratchData-empty-emitter-source-quality.md`
- Safety: This file must never be executed, replayed, or used as an operational runbook.
- Credit: This archive provides no gate, score, coverage, IDA, validator, or lifecycle credit.

# Removed Executable Code Archive

- Source report: [00028W-MmxBlendWeightScratchData-empty-emitter-source-quality.md](00028W-MmxBlendWeightScratchData-empty-emitter-source-quality.md)
- Source report SHA256 before cleanup: `EB32AAF9AE5FCEB3ACA14CDF10C6FABE6090B1C0FF9CEECCC9DB8C514A8ED45C`
- Cleanup generated: `2026-08-11T12:47:17Z`
- Removed executable blocks: `3`
- Scope: exact executable or command-shaped fenced blocks removed from the source report by supervisor housekeeping.
- Authority: this file is not a B-agent research report and grants no Gate 1, Gate 2, IDA, validator, score, or lifecycle credit.
- Safety: do not execute, import, evaluate, or use any block in this archive as an operational instruction.

## Removed Block R001

- Original source lines: `370-374`
- Original language: `powershell`
- Block SHA256: `27CB8AD57EB10ED8A0C8C07D54AC5CEA4F3C264CF64D2DC8D71351F42087AC0C`

```powershell
python .\tools\validator.py --mode file --file by-memory\0x0067a7f0-0x0067a830.MmxBlendWeightScratchData.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-file\SoftwareBlend16.md --apply --queue-timeout 240
python .\tools\validator.py --mode autogen --apply --queue-timeout 240
```

## Removed Block R002

- Original source lines: `378-383`
- Original language: `powershell`
- Block SHA256: `88BF4DCCABCD6E89BAE26BE316E8584FDE805738600E6EF4B576E178D9A00271`

```powershell
python .\tools\validator.py --mode file --file by-memory\0x0045fa00-0x004604f4.Rgb555565BlitHelpers.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-memory\0x004609e0-0x00460af9.Rgb565TransparentAlphaBlendMmxBlocks.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-memory\0x00460b00-0x00460c0a.AlphaBlendSpan16Blocks.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-memory\0x00610e38-0x00610ed8.SoftwareBlend16ReadOnlyConstants.md --apply --queue-timeout 240
```

## Removed Block R003

- Original source lines: `387-391`
- Original language: `powershell`
- Block SHA256: `6E910829BC619D6299E4A8B0E4F8969E35DC64CE84FB95E3D2473F7538FB9498`

```powershell
rg -n "UID:00028W|qword_67A7F0|qword_67A828|MmxBlendWeightScratchData|Empty Emitter Marker" auto-generated\NexusTK\render\SoftwareBlend16.cpp
rg -n "00028W|0x0067a7f0|0x0067a830|MmxBlendWeightScratchData" by-memory\0x0067a7f0-0x0067a830.MmxBlendWeightScratchData.md project-level\-auto-completion-stats.md auto-generated\-ag-memory-coverage.md
Select-String -Path auto-generated\NexusTK\render\SoftwareBlend16.cpp -Pattern "validator-command-id","validator-refreshed-at","UID:00028W","qword_67A7F0","qword_67A828"
```
