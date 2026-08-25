<!-- REMOVED-MATERIAL-ARCHIVE -->
# Removed Material Archive

- Status: Non-authoritative archival material only.
- Source report: `E:\NTK\GhidraBridge\source-3\project-documentation\executed-b-agent-research\B005\0002IO-ImageLibScalarDeletingDestructor-source-quality.md`
- Safety: This file must never be executed, replayed, or used as an operational runbook.
- Credit: This archive provides no gate, score, coverage, IDA, validator, or lifecycle credit.

# Removed Executable Code Archive

- Source report: [0002IO-ImageLibScalarDeletingDestructor-source-quality.md](0002IO-ImageLibScalarDeletingDestructor-source-quality.md)
- Source report SHA256 before cleanup: `EB54643CC5B9A5D4D5F991D2029C37CA4712EDC87A6ACC073A22A92D638A7A1D`
- Cleanup generated: `2026-08-11T12:47:09Z`
- Removed executable blocks: `1`
- Scope: exact executable or command-shaped fenced blocks removed from the source report by supervisor housekeeping.
- Authority: this file is not a B-agent research report and grants no Gate 1, Gate 2, IDA, validator, score, or lifecycle credit.
- Safety: do not execute, import, evaluate, or use any block in this archive as an operational instruction.

## Removed Block R001

- Original source lines: `385-396`
- Original language: `powershell`
- Block SHA256: `06DC117B8F0E50A51E7B38879D2DA326A54E599444CA410E676FFF9EA4FE235D`

```powershell
python .\tools\validator.py --mode file --file by-memory\0x004e64a0-0x004e6572.ImageLibScalarDeletingDestructor.md --apply --queue-timeout 240 --wait-generated
python .\tools\validator.py --mode file --file by-class\ImageLib.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-file\ImageLib.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-memory\0x004cffb0-0x004d011b.ImageLibLifecycleCluster.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-type\by-struct\ImageLibLayout.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-type\by-struct\ResourceLayoutNameRecord.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-type\by-vtable\ImageLibVtable.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-memory\0x0061b650-0x0061b660.ImageLibVtableData.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-global\g_pEPFLib.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-memory\0x0067a744-0x0067a748.g_pEPFLib.md --apply --queue-timeout 240
```
