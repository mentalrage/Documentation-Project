<!-- REMOVED-MATERIAL-ARCHIVE -->
# Removed Material Archive

- Status: Non-authoritative archival material only.
- Source report: `E:\NTK\GhidraBridge\source-3\project-documentation\executed-b-agent-research\B015\0002K7-RankingCategoryRecordSetStartTimeFromPackedDateTime-source-quality.md`
- Safety: This file must never be executed, replayed, or used as an operational runbook.
- Credit: This archive provides no gate, score, coverage, IDA, validator, or lifecycle credit.

# Removed Executable Code Archive

- Source report: [0002K7-RankingCategoryRecordSetStartTimeFromPackedDateTime-source-quality.md](0002K7-RankingCategoryRecordSetStartTimeFromPackedDateTime-source-quality.md)
- Source report SHA256 before cleanup: `24D478D6690F964AECB23FB7F4A39C299FC3FDD85284F961A52116E6F83D7E96`
- Cleanup generated: `2026-08-11T12:47:19Z`
- Removed executable blocks: `1`
- Scope: exact executable or command-shaped fenced blocks removed from the source report by supervisor housekeeping.
- Authority: this file is not a B-agent research report and grants no Gate 1, Gate 2, IDA, validator, score, or lifecycle credit.
- Safety: do not execute, import, evaluate, or use any block in this archive as an operational instruction.

## Removed Block R001

- Original source lines: `378-387`
- Original language: `powershell`
- Block SHA256: `F46E60B684B898BE37791E27E81D5D3D80B6E1BF1C05651BA4C6D671C3000B8B`

```powershell
python .\tools\validator.py --mode file --file .\by-memory\0x0045c050-0x0045c0f9.RankingCategoryRecordSetStartTimeFromPackedDateTime.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file .\by-class\RankingCategoryRecord.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file .\by-type\by-struct\RankingCategoryRecordLayout.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file .\by-memory\0x0045bf60-0x0045c257.RankingCategoryRecord.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file .\by-memory\0x0045c2a0-0x0045c556.RankingCategoryCollectionParseCategoryListResponse.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file .\by-memory\0x0045c560-0x0045cb0a.RankingCategoryCollectionParseInitialCategoryPageResponse.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file .\by-file\RankingDialog.md --apply --queue-timeout 240
python .\tools\validator.py --mode autogen --apply --queue-timeout 240
```
