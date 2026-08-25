<!-- REMOVED-MATERIAL-ARCHIVE -->
# Removed Material Archive

- Status: Non-authoritative archival material only.
- Source report: `E:\NTK\GhidraBridge\source-3\project-documentation\executed-b-agent-research\B009\00013V-EncoderScalarDeletingDestructor-source-quality.md`
- Safety: This file must never be executed, replayed, or used as an operational runbook.
- Credit: This archive provides no gate, score, coverage, IDA, validator, or lifecycle credit.

# Removed Executable Code Archive

- Source report: [00013V-EncoderScalarDeletingDestructor-source-quality.md](00013V-EncoderScalarDeletingDestructor-source-quality.md)
- Source report SHA256 before cleanup: `907EEA51FA5293B9D149723A12F818A02CC689D90C5724A0612DC0D95B87B6BD`
- Cleanup generated: `2026-08-11T12:47:14Z`
- Removed executable blocks: `2`
- Scope: exact executable or command-shaped fenced blocks removed from the source report by supervisor housekeeping.
- Authority: this file is not a B-agent research report and grants no Gate 1, Gate 2, IDA, validator, score, or lifecycle credit.
- Safety: do not execute, import, evaluate, or use any block in this archive as an operational instruction.

## Removed Block R001

- Original source lines: `230-234`
- Original language: `powershell`
- Block SHA256: `E8DCA6257970453D55CA8E0E54FE4670E83CFE5C5E8700E72A320627A5A89450`

```powershell
python .\tools\validator.py --mode file --file by-memory\0x004a5e30-0x004a5e54.EncoderScalarDeletingDestructor.md --apply --wait-generated
python .\tools\validator.py --mode file --file by-class\Encoder.md --apply --wait-generated
python .\tools\validator.py --mode file --file by-file\Encoder.md --apply --wait-generated
```

## Removed Block R002

- Original source lines: `238-240`
- Original language: `powershell`
- Block SHA256: `F0C4901A9AFDE64A1D9C8B08EB8FF063A3CB827BC8FBC3A23D09770B781690CF`

```powershell
python .\tools\validator.py --mode file --file by-file\BinaryCodec.md --apply --wait-generated
```
