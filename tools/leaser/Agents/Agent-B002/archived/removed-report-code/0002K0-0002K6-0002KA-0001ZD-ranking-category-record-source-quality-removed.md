<!-- REMOVED-MATERIAL-ARCHIVE -->
# Removed Material Archive

- Status: Non-authoritative archival material only.
- Source report: `E:\NTK\GhidraBridge\source-3\project-documentation\executed-b-agent-research\B002\0002K0-0002K6-0002KA-0001ZD-ranking-category-record-source-quality.md`
- Safety: This file must never be executed, replayed, or used as an operational runbook.
- Credit: This archive provides no gate, score, coverage, IDA, validator, or lifecycle credit.

# Removed Executable Code Archive

- Source report: [0002K0-0002K6-0002KA-0001ZD-ranking-category-record-source-quality.md](0002K0-0002K6-0002KA-0001ZD-ranking-category-record-source-quality.md)
- Source report SHA256 before cleanup: `BBA76E5004308FC1AB83F5512B6CD978F59EEFC53836D00941673B2C220AE321`
- Cleanup generated: `2026-08-11T12:47:02Z`
- Removed executable blocks: `1`
- Scope: exact executable or command-shaped fenced blocks removed from the source report by supervisor housekeeping.
- Authority: this file is not a B-agent research report and grants no Gate 1, Gate 2, IDA, validator, score, or lifecycle credit.
- Safety: do not execute, import, evaluate, or use any block in this archive as an operational instruction.

## Removed Block R001

- Original source lines: `341-347`
- Original language: `powershell`
- Block SHA256: `EEC21C417E5C951677D8428C11B6343910E38D3C919E6BF6E0BFA7DE9EF44B10`

```powershell
Set-Location E:\NTK\GhidraBridge\source-3\project-documentation
python tools\memory_ranges.py --validate
python tools\memory_ranges.py --refresh
python tools\agent_tools\validate_doc_links.py by-memory\0x0045bf60-0x0045bf63.RankingCategoryRecordGetListIndex.md by-memory\0x0045bf70-0x0045bf73.RankingCategoryRecordGetCategoryId.md by-memory\0x0045bf80-0x0045bf83.RankingCategoryRecordGetStateCode.md by-memory\0x0045bf90-0x0045bfae.RankingCategoryRecordCopyStartTimeParts.md by-memory\0x0045bfb0-0x0045bfce.RankingCategoryRecordCopyEndTimeParts.md by-memory\0x0045bfd0-0x0045bfd3.RankingCategoryRecordGetTitleText.md by-memory\0x0045bfe0-0x0045c01a.RankingCategoryRecordGetUserEntryAt.md by-memory\0x0045c240-0x0045c256.RankingCategoryRecordResetUserEntries.md by-memory\0x0045d530-0x0045d740.RankingCategoryVectorStorageHelpers.md by-class\RankingCategoryRecord.md by-type\by-struct\RankingCategoryRecordLayout.md
python tools\completion_score.py --uid 0002K0 --uid 0002K1 --uid 0002K2 --uid 0002K3 --uid 0002K4 --uid 0002K5 --uid 0002K6 --uid 0002KA --uid 0001ZD
```
