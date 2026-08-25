<!-- REMOVED-MATERIAL-ARCHIVE -->
# Removed Material Archive

- Status: Non-authoritative archival material only.
- Source report: `E:\NTK\GhidraBridge\source-3\project-documentation\executed-b-agent-research\B014\0000VZ-LibJpegMarkerWriter-source-quality.md`
- Safety: This file must never be executed, replayed, or used as an operational runbook.
- Credit: This archive provides no gate, score, coverage, IDA, validator, or lifecycle credit.

# Removed Executable Code Archive

- Source report: [0000VZ-LibJpegMarkerWriter-source-quality.md](0000VZ-LibJpegMarkerWriter-source-quality.md)
- Source report SHA256 before cleanup: `C28C9722147BB44F1648D5E3C25B6402F72103DA4FCAF47B669E1DF400F30D35`
- Cleanup generated: `2026-08-11T12:47:18Z`
- Removed executable blocks: `2`
- Scope: exact executable or command-shaped fenced blocks removed from the source report by supervisor housekeeping.
- Authority: this file is not a B-agent research report and grants no Gate 1, Gate 2, IDA, validator, score, or lifecycle credit.
- Safety: do not execute, import, evaluate, or use any block in this archive as an operational instruction.

## Removed Block R001

- Original source lines: `349-356`
- Original language: `powershell`
- Block SHA256: `789F907DDE147F57B6A210020E45B8A5E74C98532BA1CE57CFE7DFF67CEAFEA5`

```powershell
python .\tools\validator.py --mode file --file by-memory/0x004064a0-0x00406d90.LibJpegMarkerWriter.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-file/LibJPEG.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-memory/0x00401000-0x00414283.LibJpeg6bCore.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-memory/0x004063d0-0x0040649b.LibJpegUtilityHelpers.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-memory/0x00406d90-0x00406e46.LibJpegCompressMasterInit.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-meta/client_libraries.md --apply --queue-timeout 240
```

## Removed Block R002

- Source report SHA256 before this cleanup pass: `0915806265D81A609B55A43312D3C9D49DFB99D89D3AD9AE8779E36B7BDC9F68`
- Original source lines: `415-417`
- Original language: `powershell`
- Block SHA256: `B3C1E43C2586465E31564D3D3A149A05907DD864CFEDA8E10361D14A0AC666D3`

```powershell
python .\tools\validator.py execute_report B014 0000VZ-LibJpegMarkerWriter-source-quality.md 0000VZ --apply
```
