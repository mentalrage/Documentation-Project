<!-- REMOVED-MATERIAL-ARCHIVE -->
# Removed Material Archive

- Status: Non-authoritative archival material only.
- Source report: `E:\NTK\GhidraBridge\source-3\project-documentation\executed-b-agent-research\B014\0002BA-ObjectListEncodedKeyAndRectHelpers-source-quality.md`
- Safety: This file must never be executed, replayed, or used as an operational runbook.
- Credit: This archive provides no gate, score, coverage, IDA, validator, or lifecycle credit.

# Removed Executable Code Archive

- Source report: [0002BA-ObjectListEncodedKeyAndRectHelpers-source-quality.md](0002BA-ObjectListEncodedKeyAndRectHelpers-source-quality.md)
- Source report SHA256 before cleanup: `20D22FC098126297FCEFCA62809FDE3A15AF79E8DBDCD027A639A14BE97EAAFC`
- Cleanup generated: `2026-08-11T12:47:18Z`
- Removed executable blocks: `1`
- Scope: exact executable or command-shaped fenced blocks removed from the source report by supervisor housekeeping.
- Authority: this file is not a B-agent research report and grants no Gate 1, Gate 2, IDA, validator, score, or lifecycle credit.
- Safety: do not execute, import, evaluate, or use any block in this archive as an operational instruction.

## Removed Block R001

- Original source lines: `306-322`
- Original language: `powershell`
- Block SHA256: `4124080067DE3DE9ED8E517DC7EB97A7E7D8284AC49D6AD5188B572C78DC2039`

```powershell
cd E:\NTK\GhidraBridge\source-3\project-documentation
# 000000003331 at 2026-06-26T20:37:56-04:00: ok: 1
python .\tools\validator.py --mode file --file by-memory/0x00535b10-0x00535df0.ObjectListEncodedKeyAndRectHelpers.md --apply --queue-timeout 240
# 000000003461 at 2026-06-26T20:49:45-04:00: ok: 1; existing missing_ref_target 0001B1 warning.
python .\tools\validator.py --mode file --file by-memory/0x00532f70-0x0053728e.ObjectListExtendedTypeLookupHelpers.md --apply --queue-timeout 240
# 000000003462 at 2026-06-26T20:49:55-04:00: ok: 1
python .\tools\validator.py --mode file --file by-memory/0x00535df0-0x00536270.ObjectListTypeSpecificEncodedKeyLookupHelpers.md --apply --queue-timeout 240
# 000000003463 at 2026-06-26T20:50:06-04:00: ok: 1; existing missing_ref_target 00023D warning.
python .\tools\validator.py --mode file --file by-class/ObjectList.md --apply --queue-timeout 240
# 000000003464 at 2026-06-26T20:50:17-04:00: ok: 1; existing missing_ref_uid 0003IO and missing_ref_target 00023D warnings.
python .\tools\validator.py --mode file --file by-file/ObjectList.md --apply --queue-timeout 240
# 000000003475 at 2026-06-26T20:53:15-04:00: ok: 1
python .\tools\validator.py --mode file --file by-memory/0x00532180-0x005322d0.ObjectListEncodedKeyResolve.md --apply --queue-timeout 240
# 000000003476 at 2026-06-26T20:53:21-04:00: ok: 1
python .\tools\validator.py --mode file --file by-memory/0x005322d0-0x00532370.ObjectListTypeSpecificIndexDispatch.md --apply --queue-timeout 240
```
