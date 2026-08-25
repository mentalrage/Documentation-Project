<!-- REMOVED-MATERIAL-ARCHIVE -->
# Removed Material Archive

- Status: Non-authoritative archival material only.
- Source report: `E:\NTK\GhidraBridge\source-3\project-documentation\executed-b-agent-research\B010\0001HG-CollectionPane2RawConstructor-source-quality.md`
- Safety: This file must never be executed, replayed, or used as an operational runbook.
- Credit: This archive provides no gate, score, coverage, IDA, validator, or lifecycle credit.

# Removed Executable Code Archive

- Source report: [0001HG-CollectionPane2RawConstructor-source-quality.md](0001HG-CollectionPane2RawConstructor-source-quality.md)
- Source report SHA256 before cleanup: `AFA95BE6E6130E745D86FEDF34A213C8B97C6C5435DDF1834D9DE3FC3771E358`
- Cleanup generated: `2026-08-11T12:47:15Z`
- Removed executable blocks: `1`
- Scope: exact executable or command-shaped fenced blocks removed from the source report by supervisor housekeeping.
- Authority: this file is not a B-agent research report and grants no Gate 1, Gate 2, IDA, validator, score, or lifecycle credit.
- Safety: do not execute, import, evaluate, or use any block in this archive as an operational instruction.

## Removed Block R001

- Original source lines: `300-307`
- Original language: `powershell`
- Block SHA256: `30AADF55972037BF954352F45678A080556A1D867E7A8D997B50597E76306ED7`

```powershell
cd E:\NTK\GhidraBridge\source-3\project-documentation
python .\tools\validator.py --mode file --file by-memory\0x0056fd70-0x0056fda0.CollectionPane2RawConstructor.md --apply --queue-timeout 240 --wait-generated
python .\tools\validator.py --mode file --file by-class\CollectionPane2.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-file\CollectionPane.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-memory\0x00624668-0x006246f4.CollectionPane2VtableData.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-memory\0x0056e940-0x0056fe75.CollectionPane.md --apply --queue-timeout 240
```
