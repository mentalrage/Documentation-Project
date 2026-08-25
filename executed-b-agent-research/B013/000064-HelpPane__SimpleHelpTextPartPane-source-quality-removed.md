<!-- REMOVED-MATERIAL-ARCHIVE -->
# Removed Material Archive

- Status: Non-authoritative archival material only.
- Source report: `E:\NTK\GhidraBridge\source-3\project-documentation\executed-b-agent-research\B013\000064-HelpPane__SimpleHelpTextPartPane-source-quality.md`
- Safety: This file must never be executed, replayed, or used as an operational runbook.
- Credit: This archive provides no gate, score, coverage, IDA, validator, or lifecycle credit.

# Removed Executable Code Archive

- Source report: [000064-HelpPane__SimpleHelpTextPartPane-source-quality.md](000064-HelpPane__SimpleHelpTextPartPane-source-quality.md)
- Source report SHA256 before cleanup: `B5A7EDC0EBB7C77364A268A1D11CB72B0D3865F66C7FFA9B3ACAE642688AB7CA`
- Cleanup generated: `2026-08-11T12:47:17Z`
- Removed executable blocks: `1`
- Scope: exact executable or command-shaped fenced blocks removed from the source report by supervisor housekeeping.
- Authority: this file is not a B-agent research report and grants no Gate 1, Gate 2, IDA, validator, score, or lifecycle credit.
- Safety: do not execute, import, evaluate, or use any block in this archive as an operational instruction.

## Removed Block R001

- Original source lines: `369-376`
- Original language: `powershell`
- Block SHA256: `9F6AF193457D7CC2693ECD5B63D16DE6B135A0985D8E8E1C1599D77525D83EBA`

```powershell
python tools/validator.py --mode file --file by-class/HelpPane__SimpleHelpTextPartPane.md --uid-only
python tools/validator.py --mode file --file by-memory/0x004c65a0-0x004c6ea9.HelpPaneCore.md --uid-only
python tools/validator.py --mode file --file by-memory/0x004ce620-0x004ce668.HelpPaneSimpleHelpTextPartPaneScalarDeletingDestructor.md --uid-only
python tools/validator.py --mode file --file by-class/HelpPane.md --uid-only
python tools/validator.py --mode file --file by-file/HelpPanes.md --uid-only
python tools/validator.py --mode autogen --apply
```
