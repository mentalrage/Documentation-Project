<!-- REMOVED-MATERIAL-ARCHIVE -->
# Removed Material Archive

- Status: Non-authoritative archival material only.
- Source report: `E:\NTK\GhidraBridge\source-3\project-documentation\executed-b-agent-research\B005\0000X7-JsonCppOurReaderParse-source-quality.md`
- Safety: This file must never be executed, replayed, or used as an operational runbook.
- Credit: This archive provides no gate, score, coverage, IDA, validator, or lifecycle credit.

# Removed Executable Code Archive

- Source report: [0000X7-JsonCppOurReaderParse-source-quality.md](0000X7-JsonCppOurReaderParse-source-quality.md)
- Source report SHA256 before cleanup: `50D95B0423E159ABB92DE77B90A48D3566ADACB4C3EEF4742ED991B2856404FE`
- Cleanup generated: `2026-08-11T12:47:08Z`
- Removed executable blocks: `1`
- Scope: exact executable or command-shaped fenced blocks removed from the source report by supervisor housekeeping.
- Authority: this file is not a B-agent research report and grants no Gate 1, Gate 2, IDA, validator, score, or lifecycle credit.
- Safety: do not execute, import, evaluate, or use any block in this archive as an operational instruction.

## Removed Block R001

- Original source lines: `289-297`
- Original language: `powershell`
- Block SHA256: `78280FA5BA2B446F08AF3FC988358A8B35EC0219A135E62A068F5986E39AE4F3`

```powershell
python .\tools\validator.py --mode file --file by-memory\0x00431d50-0x00431f1c.JsonCppOurReaderParse.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-file\JsonCpp.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-memory\0x00430092-0x00431d50.JsonCppWriterTailAndOurReaderPrelude.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-memory\0x00431f20-0x00432e10.JsonCppOurReaderErrorTokenHelpers.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-memory\0x00432e10-0x004345ee.JsonCppSecondParserIsland.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-memory\0x0060e2b0-0x0060f038.JsonCppReadOnlyData.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-meta\client_libraries.md --apply --queue-timeout 240
```
