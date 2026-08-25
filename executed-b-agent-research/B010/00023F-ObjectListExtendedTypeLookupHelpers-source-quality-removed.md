<!-- REMOVED-MATERIAL-ARCHIVE -->
# Removed Material Archive

- Status: Non-authoritative archival material only.
- Source report: `E:\NTK\GhidraBridge\source-3\project-documentation\executed-b-agent-research\B010\00023F-ObjectListExtendedTypeLookupHelpers-source-quality.md`
- Safety: This file must never be executed, replayed, or used as an operational runbook.
- Credit: This archive provides no gate, score, coverage, IDA, validator, or lifecycle credit.

# Removed Executable Code Archive

- Source report: [00023F-ObjectListExtendedTypeLookupHelpers-source-quality.md](00023F-ObjectListExtendedTypeLookupHelpers-source-quality.md)
- Source report SHA256 before cleanup: `13687AFAAF6F4BBDC1D660D7A3661FC840717681C7E0DB7C71F53531729A8FCE`
- Cleanup generated: `2026-08-11T12:47:15Z`
- Removed executable blocks: `1`
- Scope: exact executable or command-shaped fenced blocks removed from the source report by supervisor housekeeping.
- Authority: this file is not a B-agent research report and grants no Gate 1, Gate 2, IDA, validator, score, or lifecycle credit.
- Safety: do not execute, import, evaluate, or use any block in this archive as an operational instruction.

## Removed Block R001

- Original source lines: `552-563`
- Original language: `powershell`
- Block SHA256: `A25EE52A35AA82BBC879326AC274ACAEB98C265DDAEDD8C91CF3720C1C57DC6A`

```powershell
python .\tools\validator.py --mode file --file by-memory/0x00532f70-0x0053728e.ObjectListExtendedTypeLookupHelpers.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-memory/0x00535b10-0x00535df0.ObjectListEncodedKeyAndRectHelpers.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-memory/0x00535df0-0x00536270.ObjectListTypeSpecificEncodedKeyLookupHelpers.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-memory/0x00536270-0x0053728e.ObjectListTierInsertRemoveHelpers.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-class/ObjectList.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-file/ObjectList.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-type/by-struct/ObjectListLayout.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-memory/0x005059d0-0x00505bf8.MapPaneRecenterAndSendPosition.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-memory/0x00506970-0x00506cdd.MapPaneObjectLookupHelpers.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-memory/0x00514920-0x00514a0d.MapRefreshDimmerMethods.md --apply --queue-timeout 240
```
