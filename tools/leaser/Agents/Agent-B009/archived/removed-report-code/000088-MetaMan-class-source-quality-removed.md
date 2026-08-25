<!-- REMOVED-MATERIAL-ARCHIVE -->
# Removed Material Archive

- Status: Non-authoritative archival material only.
- Source report: `E:\NTK\GhidraBridge\source-3\project-documentation\executed-b-agent-research\B009\000088-MetaMan-class-source-quality.md`
- Safety: This file must never be executed, replayed, or used as an operational runbook.
- Credit: This archive provides no gate, score, coverage, IDA, validator, or lifecycle credit.

# Removed Executable Code Archive

- Source report: [000088-MetaMan-class-source-quality.md](000088-MetaMan-class-source-quality.md)
- Source report SHA256 before cleanup: `6192924E798D2D075CA6F799CA606E35FD0E98C759E0CC5C3EAEEF86090682FA`
- Cleanup generated: `2026-08-11T12:47:14Z`
- Removed executable blocks: `1`
- Scope: exact executable or command-shaped fenced blocks removed from the source report by supervisor housekeeping.
- Authority: this file is not a B-agent research report and grants no Gate 1, Gate 2, IDA, validator, score, or lifecycle credit.
- Safety: do not execute, import, evaluate, or use any block in this archive as an operational instruction.

## Removed Block R001

- Original source lines: `485-494`
- Original language: `powershell`
- Block SHA256: `35F1B803CB53E8250098193232338C108A7B5F6A9A14679D6A577C96D6E89711`

```powershell
python .\tools\validator.py --mode file --file by-class/MetaMan.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-file/MetaMan.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-memory/0x005227d0-0x00524581.MetaMan.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-memory/0x00523a00-0x00523c99.MetaManLookupHelpers.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-memory/0x00524590-0x005245b1.MetaManNodeDestroyHelper.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-global/g_pMetaMan.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-global/g_metaAliasTableName.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-resource/meta-dat-metadata-cache.md --apply --queue-timeout 240
```
