<!-- REMOVED-MATERIAL-ARCHIVE -->
# Removed Material Archive

- Status: Non-authoritative archival material only.
- Source report: `E:\NTK\GhidraBridge\source-3\project-documentation\executed-b-agent-research\B006\00015T-RectArea-source-quality.md`
- Safety: This file must never be executed, replayed, or used as an operational runbook.
- Credit: This archive provides no gate, score, coverage, IDA, validator, or lifecycle credit.

# Removed Executable Code Archive

- Source report: [00015T-RectArea-source-quality.md](00015T-RectArea-source-quality.md)
- Source report SHA256 before cleanup: `50BA34F791D4DFB3CD158EB5887B080CEEE7CF513C00A434725667BE6830D89D`
- Cleanup generated: `2026-08-11T12:47:10Z`
- Removed executable blocks: `1`
- Scope: exact executable or command-shaped fenced blocks removed from the source report by supervisor housekeeping.
- Authority: this file is not a B-agent research report and grants no Gate 1, Gate 2, IDA, validator, score, or lifecycle credit.
- Safety: do not execute, import, evaluate, or use any block in this archive as an operational instruction.

## Removed Block R001

- Original source lines: `290-296`
- Original language: `powershell`
- Block SHA256: `95DB84F07AC373F8ED729EB597E6FF30F3EF5E694C82B8DB1E2B72BAE712D9FF`

```powershell
python source-3/project-documentation/tools/validator.py --mode file --file by-class\RectBounds.md --apply --queue-timeout 240
python source-3/project-documentation/tools/validator.py --mode file --file by-type\by-struct\RectBoundsLayout.md --apply --queue-timeout 240
python source-3/project-documentation/tools/validator.py --mode file --file by-memory\0x004b7ca0-0x004b7cb6.RectArea.md --apply --queue-timeout 240
python source-3/project-documentation/tools/validator.py --mode file --file by-file\RectBounds.md --apply --queue-timeout 240
python source-3/project-documentation/tools/validator.py --mode autogen --apply --queue-timeout 240
```
