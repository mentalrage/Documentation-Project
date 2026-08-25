<!-- REMOVED-MATERIAL-ARCHIVE -->
# Removed Material Archive

- Status: Non-authoritative archival material only.
- Source report: `E:\NTK\GhidraBridge\source-3\project-documentation\executed-b-agent-research\B004\0001JO-TextBoxPane-source-quality.md`
- Safety: This file must never be executed, replayed, or used as an operational runbook.
- Credit: This archive provides no gate, score, coverage, IDA, validator, or lifecycle credit.

# Removed Executable Code Archive

- Source report: [0001JO-TextBoxPane-source-quality.md](0001JO-TextBoxPane-source-quality.md)
- Source report SHA256 before cleanup: `E98CBB28F3D4C44571DC6C40F7C53E3AF015EAA26B713BF0AD076534574A0161`
- Cleanup generated: `2026-08-11T12:47:07Z`
- Removed executable blocks: `1`
- Scope: exact executable or command-shaped fenced blocks removed from the source report by supervisor housekeeping.
- Authority: this file is not a B-agent research report and grants no Gate 1, Gate 2, IDA, validator, score, or lifecycle credit.
- Safety: do not execute, import, evaluate, or use any block in this archive as an operational instruction.

## Removed Block R001

- Original source lines: `312-318`
- Original language: `powershell`
- Block SHA256: `5D02F08674F82A5AB2D63B68DC5ACC86B34CA85C2EB2D4B73F36197B255D85A6`

```powershell
python .\tools\validator.py --mode file --file by-memory\0x00591300-0x005954b3.TextBoxPaneNoncontiguousAuditMap.md --apply --queue-timeout 240 --wait-generated
python .\tools\validator.py --mode file --file by-memory\0x00591300-0x005913f9.TextBoxPaneCursorInvalidationOverrides.md --apply --queue-timeout 240 --wait-generated
python .\tools\validator.py --mode file --file by-memory\0x00595390-0x005954b3.TextBoxPaneConstructor.md --apply --queue-timeout 240 --wait-generated
python .\tools\validator.py --mode file --file by-class\TextBoxPane.md --apply --queue-timeout 240 --wait-generated
python .\tools\validator.py --mode file --file by-file\TextBoxPane.md --apply --queue-timeout 240 --wait-generated
```
