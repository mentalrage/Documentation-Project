<!-- REMOVED-MATERIAL-ARCHIVE -->
# Removed Material Archive

- Status: Non-authoritative archival material only.
- Source report: `E:\NTK\GhidraBridge\source-3\project-documentation\executed-b-agent-research\B005\0002CB-ObjectListEncodedKeyResolve-source-quality.md`
- Safety: This file must never be executed, replayed, or used as an operational runbook.
- Credit: This archive provides no gate, score, coverage, IDA, validator, or lifecycle credit.

# Removed Executable Code Archive

- Source report: [0002CB-ObjectListEncodedKeyResolve-source-quality.md](0002CB-ObjectListEncodedKeyResolve-source-quality.md)
- Source report SHA256 before cleanup: `9E6684E60739AEA3F2C5748EE73964D0251FE78544A69FCDC827E3BFD44C5375`
- Cleanup generated: `2026-08-11T12:47:09Z`
- Removed executable blocks: `1`
- Scope: exact executable or command-shaped fenced blocks removed from the source report by supervisor housekeeping.
- Authority: this file is not a B-agent research report and grants no Gate 1, Gate 2, IDA, validator, score, or lifecycle credit.
- Safety: do not execute, import, evaluate, or use any block in this archive as an operational instruction.

## Removed Block R001

- Original source lines: `336-346`
- Original language: `powershell`
- Block SHA256: `1366D2EEE4FCC88561D5F680442419C8BE56DE606EDDE34A6F1417E2A68FC5BE`

```powershell
python .\tools\validator.py --mode file --file by-memory/0x00532180-0x005322d0.ObjectListEncodedKeyResolve.md --apply --queue-timeout 240 --wait-generated
python .\tools\validator.py --mode file --file by-memory/0x00531480-0x00532530.ObjectListCategorizeLookupHelpers.md --apply --queue-timeout 240 --wait-generated
python .\tools\validator.py --mode file --file by-memory/0x005322d0-0x00532370.ObjectListTypeSpecificIndexDispatch.md --apply --queue-timeout 240 --wait-generated
python .\tools\validator.py --mode file --file by-memory/0x00535b10-0x00535df0.ObjectListEncodedKeyAndRectHelpers.md --apply --queue-timeout 240 --wait-generated
python .\tools\validator.py --mode file --file by-memory/0x00532f70-0x0053728e.ObjectListExtendedTypeLookupHelpers.md --apply --queue-timeout 240 --wait-generated
python .\tools\validator.py --mode file --file by-memory/0x00506970-0x00506cdd.MapPaneObjectLookupHelpers.md --apply --queue-timeout 240 --wait-generated
python .\tools\validator.py --mode file --file by-class/ObjectList.md --apply --queue-timeout 240 --wait-generated
python .\tools\validator.py --mode file --file by-file/ObjectList.md --apply --queue-timeout 240 --wait-generated
python .\tools\validator.py --mode file --file by-type/by-struct/ObjectListLayout.md --apply --queue-timeout 240 --wait-generated
```
