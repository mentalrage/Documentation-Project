<!-- REMOVED-MATERIAL-ARCHIVE -->
# Removed Material Archive

- Status: Non-authoritative archival material only.
- Source report: `E:\NTK\GhidraBridge\source-3\project-documentation\executed-b-agent-research\B009\00013M-DecoderAndCodecVtableGlue-source-quality.md`
- Safety: This file must never be executed, replayed, or used as an operational runbook.
- Credit: This archive provides no gate, score, coverage, IDA, validator, or lifecycle credit.

# Removed Executable Code Archive

- Source report: [00013M-DecoderAndCodecVtableGlue-source-quality.md](00013M-DecoderAndCodecVtableGlue-source-quality.md)
- Source report SHA256 before cleanup: `11CAA6640D77D3D27CF8A06D70144DD4A23B4694744BA93CA596EB6D9FB2FB06`
- Cleanup generated: `2026-08-11T12:47:14Z`
- Removed executable blocks: `2`
- Scope: exact executable or command-shaped fenced blocks removed from the source report by supervisor housekeeping.
- Authority: this file is not a B-agent research report and grants no Gate 1, Gate 2, IDA, validator, score, or lifecycle credit.
- Safety: do not execute, import, evaluate, or use any block in this archive as an operational instruction.

## Removed Block R001

- Original source lines: `294-297`
- Original language: `powershell`
- Block SHA256: `DF8272AB5B66C20E039110238B3DBAF1B2C3F2D00550D3F5563E17D23B0F0E45`

```powershell
python .\tools\validator.py --mode file --file by-memory\0x004a5630-0x004a5e54.DecoderAndCodecVtableGlue.md --apply --wait-generated
python .\tools\validator.py --mode file --file by-file\BinaryCodec.md --apply --wait-generated
```

## Removed Block R002

- Original source lines: `301-315`
- Original language: `powershell`
- Block SHA256: `76EFCD053A5DA3B7F18A2D18E35CB99FC8C7FA76F0A0BC06FC3F9A33073CB783`

```powershell
python .\tools\validator.py --mode file --file by-memory\0x004a5630-0x004a5e54.DecoderAndCodecVtableGlue.md --apply --wait-generated
# command_id: 000000004603
# command_timestamp: 2026-06-27T21:49:06-04:00
# exit code: 0
# ok: 1
# generated_refresh: completed

python .\tools\validator.py --mode file --file by-file\BinaryCodec.md --apply --wait-generated
# command_id: 000000004604
# command_timestamp: 2026-06-27T21:49:24-04:00
# exit code: 0
# ok: 1
# generated_refresh: completed
```
