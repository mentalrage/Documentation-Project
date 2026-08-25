<!-- REMOVED-MATERIAL-ARCHIVE -->
# Removed Material Archive

- Status: Non-authoritative archival material only.
- Source report: `E:\NTK\GhidraBridge\source-3\project-documentation\executed-b-agent-research\B004\00013R-DecoderStringAndBlobReaders-source-quality.md`
- Safety: This file must never be executed, replayed, or used as an operational runbook.
- Credit: This archive provides no gate, score, coverage, IDA, validator, or lifecycle credit.

# Removed Executable Code Archive

- Source report: [00013R-DecoderStringAndBlobReaders-source-quality.md](00013R-DecoderStringAndBlobReaders-source-quality.md)
- Source report SHA256 before cleanup: `F6E5F00A1C2C928853F8AB3E9427BF5F4AD991A65CE0731CB3B4122F7AA416C5`
- Cleanup generated: `2026-08-11T12:47:06Z`
- Removed executable blocks: `1`
- Scope: exact executable or command-shaped fenced blocks removed from the source report by supervisor housekeeping.
- Authority: this file is not a B-agent research report and grants no Gate 1, Gate 2, IDA, validator, score, or lifecycle credit.
- Safety: do not execute, import, evaluate, or use any block in this archive as an operational instruction.

## Removed Block R001

- Original source lines: `490-493`
- Original language: `powershell`
- Block SHA256: `C2D745C30ADC151A650A2FC1B9105B8C1D5C7AF9592E389C6028582E429C69F7`

```powershell
cd E:\NTK\GhidraBridge\source-3\project-documentation
python .\tools\validator.py --mode file --file by-memory\0x004a57e0-0x004a5dce.DecoderStringAndBlobReaders.md --apply --wait-generated
```
