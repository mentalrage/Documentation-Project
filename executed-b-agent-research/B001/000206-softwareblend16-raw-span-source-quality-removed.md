<!-- REMOVED-MATERIAL-ARCHIVE -->
# Removed Material Archive

- Status: Non-authoritative archival material only.
- Source report: `E:\NTK\GhidraBridge\source-3\project-documentation\executed-b-agent-research\B001\000206-softwareblend16-raw-span-source-quality.md`
- Safety: This file must never be executed, replayed, or used as an operational runbook.
- Credit: This archive provides no gate, score, coverage, IDA, validator, or lifecycle credit.

# Removed Executable Code Archive

- Source report: [000206-softwareblend16-raw-span-source-quality.md](000206-softwareblend16-raw-span-source-quality.md)
- Source report SHA256 before cleanup: `40E71FEAA641D347D1F7488276E42E264E57D19E598CBE26C9F6C3DBF97AD584`
- Cleanup generated: `2026-08-11T12:46:58Z`
- Removed executable blocks: `4`
- Scope: exact executable or command-shaped fenced blocks removed from the source report by supervisor housekeeping.
- Authority: this file is not a B-agent research report and grants no Gate 1, Gate 2, IDA, validator, score, or lifecycle credit.
- Safety: do not execute, import, evaluate, or use any block in this archive as an operational instruction.

## Removed Block R001

- Original source lines: `442-446`
- Original language: `powershell`
- Block SHA256: `5320999C94C652CF16FFA7FEA803268784F43454910F938547ED862485710F93`

```powershell
python E:\NTK\GhidraBridge\source-3\project-documentation\tools\validator.py --mode file --file E:\NTK\GhidraBridge\source-3\project-documentation\by-memory\0x00460710-0x004607e0.Rgb565HalfBlendSpanRaw.md --apply
python E:\NTK\GhidraBridge\source-3\project-documentation\tools\validator.py --mode file --file E:\NTK\GhidraBridge\source-3\project-documentation\by-memory\-coverage-report.md --apply
python E:\NTK\GhidraBridge\source-3\project-documentation\tools\validator.py --mode autogen
```

## Removed Block R002

- Original source lines: `450-455`
- Original language: `powershell`
- Block SHA256: `B6EC8A9FB3FC06AD8CEBAAD5DF37D0750D9BCE58EBACA1566B759E172FAB4A38`

```powershell
python E:\NTK\GhidraBridge\source-3\project-documentation\tools\validator.py --mode file --file E:\NTK\GhidraBridge\source-3\project-documentation\by-memory\0x004607e0-0x0046093c.Rgb565TransparentAlphaBlendSpanRaw.md --apply
python E:\NTK\GhidraBridge\source-3\project-documentation\tools\validator.py --mode file --file E:\NTK\GhidraBridge\source-3\project-documentation\by-memory\0x00460d60-0x00460dee.ByteSpanFillRows.md --apply
python E:\NTK\GhidraBridge\source-3\project-documentation\tools\validator.py --mode file --file E:\NTK\GhidraBridge\source-3\project-documentation\by-memory\-coverage-report.md --apply
python E:\NTK\GhidraBridge\source-3\project-documentation\tools\validator.py --mode autogen
```

## Removed Block R003

- Original source lines: `459-462`
- Original language: `powershell`
- Block SHA256: `A60CCAD0179D7505FB8EB91BA83F72365FB638DE386A6EF2BDC423923AF84C00`

```powershell
python E:\NTK\GhidraBridge\source-3\project-documentation\tools\validator.py --mode file --file E:\NTK\GhidraBridge\source-3\project-documentation\by-file\SoftwareBlend16.md --apply
python E:\NTK\GhidraBridge\source-3\project-documentation\tools\validator.py --mode autogen
```

## Removed Block R004

- Original source lines: `466-469`
- Original language: `powershell`
- Block SHA256: `A3F6EFAB399C5C47721B69F6DDAFB6B50A66FC0263868D52815F72832875C598`

```powershell
rg -n "000206|000207|00020B|Rgb565HalfBlendSpanRaw|Rgb565TransparentAlphaBlendSpanRaw|ByteSpanFillRows" E:\NTK\GhidraBridge\source-3\project-documentation\project-level\-auto-completion-stats.md E:\NTK\GhidraBridge\source-3\project-documentation\auto-generated\-ag-memory-coverage.md
rg -n "0x00460710-0x004607e0|0x004607e0-0x0046093c|0x00460d60-0x00460dee" E:\NTK\GhidraBridge\source-3\project-documentation\by-memory\-coverage-report.md
```
