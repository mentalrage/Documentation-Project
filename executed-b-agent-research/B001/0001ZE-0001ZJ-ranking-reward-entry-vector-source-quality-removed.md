<!-- REMOVED-MATERIAL-ARCHIVE -->
# Removed Material Archive

- Status: Non-authoritative archival material only.
- Source report: `E:\NTK\GhidraBridge\source-3\project-documentation\executed-b-agent-research\B001\0001ZE-0001ZJ-ranking-reward-entry-vector-source-quality.md`
- Safety: This file must never be executed, replayed, or used as an operational runbook.
- Credit: This archive provides no gate, score, coverage, IDA, validator, or lifecycle credit.

# Removed Executable Code Archive

- Source report: [0001ZE-0001ZJ-ranking-reward-entry-vector-source-quality.md](0001ZE-0001ZJ-ranking-reward-entry-vector-source-quality.md)
- Source report SHA256 before cleanup: `38C38A6FEFE4FAA364F7861D3B12AE253DE079DD31BF149F8602A598F23DFEA2`
- Cleanup generated: `2026-08-11T12:46:58Z`
- Removed executable blocks: `1`
- Scope: exact executable or command-shaped fenced blocks removed from the source report by supervisor housekeeping.
- Authority: this file is not a B-agent research report and grants no Gate 1, Gate 2, IDA, validator, score, or lifecycle credit.
- Safety: do not execute, import, evaluate, or use any block in this archive as an operational instruction.

## Removed Block R001

- Original source lines: `528-546`
- Original language: `powershell`
- Block SHA256: `EA9CF3BD2C79B4194D2FB77FBA8F72740246A9D8A00F34408C12D74B8C9BA78E`

```powershell
Set-Location E:\NTK\GhidraBridge\source-3\project-documentation

# 1. Confirm only approved files changed.
git status --short

# 2. Confirm no unresolved `sub_` blocker wording remains in the refreshed target pages
# except explicit "current IDA label" aliases.
rg -n "sub_45D750|sub_45D790|sub_45D7E0|sub_45DB10|sub_45DB20|sub_45DB50|sub_45EAE0|sub_45EC50|sub_45EF20|sub_45EF50|sub_45F020|sub_45F130|sub_45F160|sub_45F1D0|sub_45F290|sub_45F300" by-memory by-class by-file

# 3. Confirm score/owner/emitter metadata.
rg -n "UID:0001ZE|UID:000202|UID:000203|UID:0001ZF|UID:000204|UID:0001ZI|UID:0001ZK|UID:0001ZJ|COMPLETION:|CONFIDENCE:|CANONICAL_OWNER:|EMITTER_UIDS:" by-memory/0x0045d750-0x0045d78a.RankingCategoryRecordVectorFreeHelper.md by-memory/0x0045d790-0x0045d7c2.RankingRewardEntryVectorInit.md by-memory/0x0045d7d0-0x0045d7db.RankingRewardEntryItemVectorUnwindThunk.md by-memory/0x0045d7e0-0x0045db54.RankingRewardEntryParseAndAccessors.md by-memory/0x0045db60-0x0045db9e.RankingRewardEntryItemAt.md by-memory/0x0045eae0-0x0045efd0.RankingRewardVectorStorageHelpers.md by-memory/0x0045f020-0x0045f0a7.RankingRewardEntryVectorDestroy.md by-memory/0x0045f130-0x0045f33a.RankingRewardVectorRangeAllocationHelpers.md

# 4. Confirm coverage rows and ignored rows are synchronized.
rg -n "0001ZE|000202|000203|0001ZF|000204|0001ZI|0001ZK|0001ZJ|0045ef20|WideFormatWrapper256" by-memory/-coverage-report.md by-memory/-ignored.md

# 5. Refresh generated stats using the project-standard completion tooling, then inspect deltas.
# Use the repo's existing stats/report generator command from tools/leaser once assigned by supervisor.
```
