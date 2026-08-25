<!-- REMOVED-MATERIAL-ARCHIVE -->
# Removed Material Archive

- Status: Non-authoritative archival material only.
- Source report: `E:\NTK\GhidraBridge\source-3\project-documentation\executed-b-agent-research\B007\00041G-VectorGrowPart-by-memory-source-quality.md`
- Safety: This file must never be executed, replayed, or used as an operational runbook.
- Credit: This archive provides no gate, score, coverage, IDA, validator, or lifecycle credit.

# Removed Executable Code Archive

- Source report: [00041G-VectorGrowPart-by-memory-source-quality.md](00041G-VectorGrowPart-by-memory-source-quality.md)
- Source report SHA256 before cleanup: `ED5A76634CEB1E5900C70A2DD712491E83ADB7A808BC35FC86CA20C6518F2D45`
- Cleanup generated: `2026-08-11T12:47:12Z`
- Removed executable blocks: `2`
- Scope: exact executable or command-shaped fenced blocks removed from the source report by supervisor housekeeping.
- Authority: this file is not a B-agent research report and grants no Gate 1, Gate 2, IDA, validator, score, or lifecycle credit.
- Safety: do not execute, import, evaluate, or use any block in this archive as an operational instruction.

## Removed Block R001

- Original source lines: `319-324`
- Original language: `powershell`
- Block SHA256: `C0EB1F29EF9DA601B25AF53D23BE8768DB796356A4C556EE65ED4B645773AD43`

```powershell
python .\tools\validator.py --mode file --file by-memory/0x004e5420-0x004e55f6.VectorGrowPart.md --apply --queue-timeout 240 --wait-generated
python .\tools\validator.py --mode file --file by-file/NewHumanImageLib.md --apply --queue-timeout 240 --wait-generated
python .\tools\validator.py --mode file --file by-class/NewHumanImageLib.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-memory/0x004dfd10-0x004e4d79.NewHumanImageLibLocalMethodCluster.md --apply --queue-timeout 240
```

## Removed Block R002

- Original source lines: `328-333`
- Original language: `powershell`
- Block SHA256: `1D9AE75D16719F850AC02500A01CDF8CE9A51EA375F9E510FB799E2BF0E7480F`

```powershell
python .\tools\validator.py --mode file --file by-memory/0x004dfd10-0x004e024a.NewHumanImageLibConstructor.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-memory/0x004e11b0-0x004e13a7.NewHumanImageLibLoadPartTable.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-type/by-struct/NewHumanImageLibLayout.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-file/VectorHelpers.md --apply --queue-timeout 240
```
