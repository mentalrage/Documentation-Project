<!-- REMOVED-MATERIAL-ARCHIVE -->
# Removed Material Archive

- Status: Non-authoritative archival material only.
- Source report: `E:\NTK\GhidraBridge\source-3\project-documentation\executed-b-agent-research\B001\000209-00020A-00020C-00020D-00020E-softwareblend16-source-quality.md`
- Safety: This file must never be executed, replayed, or used as an operational runbook.
- Credit: This archive provides no gate, score, coverage, IDA, validator, or lifecycle credit.

# Removed Executable Code Archive

- Source report: [000209-00020A-00020C-00020D-00020E-softwareblend16-source-quality.md](000209-00020A-00020C-00020D-00020E-softwareblend16-source-quality.md)
- Source report SHA256 before cleanup: `62C2343DC9D9535AC8B8553E74048FEF5053ECFC8BD39542A1D950F6AF9957A0`
- Cleanup generated: `2026-08-11T12:46:58Z`
- Removed executable blocks: `2`
- Scope: exact executable or command-shaped fenced blocks removed from the source report by supervisor housekeeping.
- Authority: this file is not a B-agent research report and grants no Gate 1, Gate 2, IDA, validator, score, or lifecycle credit.
- Safety: do not execute, import, evaluate, or use any block in this archive as an operational instruction.

## Removed Block R001

- Original source lines: `263-275`
- Original language: `powershell`
- Block SHA256: `714B4CF5256FC6F35355A2C9CEF65DC98ACB0E5ED78322BAEE68D44A682F7589`

```powershell
cd E:\NTK\GhidraBridge\source-3\project-documentation
python .\tools\validator.py --mode file --file .\by-memory\0x004609e0-0x00460af9.Rgb565TransparentAlphaBlendMmxBlocks.md --apply --queue-timeout 240 --lock-timeout -1
python .\tools\validator.py --mode file --file .\by-memory\0x00460c90-0x00460d51.Rgb565AlphaMapMmxBlocks.md --apply --queue-timeout 240 --lock-timeout -1
python .\tools\validator.py --mode file --file .\by-memory\0x00460df0-0x00460e79.ByteSpanCopyRows.md --apply --queue-timeout 240 --lock-timeout -1
python .\tools\validator.py --mode file --file .\by-memory\0x00460e80-0x00460f09.ByteSpanAddRows.md --apply --queue-timeout 240 --lock-timeout -1
python .\tools\validator.py --mode file --file .\by-memory\0x00460f10-0x00460f99.ByteSpanSubtractRows.md --apply --queue-timeout 240 --lock-timeout -1
python .\tools\validator.py --mode file --file .\by-file\SoftwareBlend16.md --apply --queue-timeout 240 --lock-timeout -1
python .\tools\validator.py --mode file --file .\by-memory\-coverage-report.md --apply --queue-timeout 240 --lock-timeout -1
python .\tools\memory_ranges.py report
python .\tools\validator.py --mode autogen --apply --queue-timeout 240 --lock-timeout -1
python .\tools\validator.py --mode rescore --apply --queue-timeout 240 --lock-timeout -1
```

## Removed Block R002

- Original source lines: `279-282`
- Original language: `powershell`
- Block SHA256: `C0F1ADF14391E1D430C825A4DA2C14031FD7B43BE2F94D614C9080EAD697DA27`

```powershell
rg -n "000209|00020A|00020C|00020D|00020E" .\by-memory\-coverage-report.md .\auto-generated\-ag-memory-coverage.md .\project-level\-auto-completion-stats.md
Get-Item .\auto-generated\NexusTK\render\SoftwareBlend16.cpp | Select-Object FullName,Length
```
