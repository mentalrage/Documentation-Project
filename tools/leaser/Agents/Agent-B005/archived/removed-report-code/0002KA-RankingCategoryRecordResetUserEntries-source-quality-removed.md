<!-- REMOVED-MATERIAL-ARCHIVE -->
# Removed Material Archive

- Status: Non-authoritative archival material only.
- Source report: `E:\NTK\GhidraBridge\source-3\project-documentation\executed-b-agent-research\B005\0002KA-RankingCategoryRecordResetUserEntries-source-quality.md`
- Safety: This file must never be executed, replayed, or used as an operational runbook.
- Credit: This archive provides no gate, score, coverage, IDA, validator, or lifecycle credit.

# Removed Executable Code Archive

- Source report: [0002KA-RankingCategoryRecordResetUserEntries-source-quality.md](0002KA-RankingCategoryRecordResetUserEntries-source-quality.md)
- Cleanup reason: executable PowerShell is prohibited in B-agent research reports; valid research and reconstructed C++ remain in the original report.
- Preservation: every removed block below is copied verbatim, with its original language and start line recorded.
- Authority: this file is not a B-agent research report, claims no target coverage, and grants no Gate 1, Gate 2, IDA, validator, score, or lifecycle credit.
- Safety: do not execute, import, evaluate, or use any block in this archive as an operational instruction.

## Removed Block R001

- Original start line: `422`
- Language: `powershell`
- Preserved body SHA256: `50D989B2F6573D8C8444D28DB588C4A2AECD326111E168CC14F552901149916C`
- Original fenced-block characters: `853`

~~~~powershell
$idb = 'E:\NTK\Resources\NexusTK\NexusTK.exe.i64'
$expectedSha = '74720635DA2BED8F69DFFDBE8E7ED345C6F6ECB44F38FF03A8E8FACC9539FC46'
$expectedSize = 143196412
$item = Get-Item -LiteralPath $idb
$actualSha = (Get-FileHash -LiteralPath $idb -Algorithm SHA256).Hash
if ($item.Length -ne $expectedSize -or $actualSha -ne $expectedSha) { throw 'UID0002KA canonical IDB prestate mismatch; stop before mutation and reconcile the report.' }
$stamp = Get-Date -Format 'yyyyMMdd-HHmmss'
$backup = "$idb.bak-UID0002KA-prestate-$stamp"
Copy-Item -LiteralPath $idb -Destination $backup
$backupItem = Get-Item -LiteralPath $backup
$backupSha = (Get-FileHash -LiteralPath $backup -Algorithm SHA256).Hash
if ($backupItem.Length -ne $expectedSize -or $backupSha -ne $expectedSha) { throw 'UID0002KA backup is not byte-identical; stop before mutation.' }
~~~~

## Removed Block R002

- Original start line: `521`
- Language: `powershell`
- Preserved body SHA256: `0DABC0EE5A2DA9BE11EB9F4F5E1E4AF6F0AD244466A17D09CB69B50C349C12DD`
- Original fenced-block characters: `539`

~~~~powershell
# Before-save failure: do not call idb_save. Stop the unsaved worker, verify
# the canonical disk remains at the prestate SHA/size, reopen it fresh, and
# rerun the raw-prestate RB0 bundle.

# Save/persistence failure:
Copy-Item -LiteralPath $backup -Destination $idb -Force
$restoredItem = Get-Item -LiteralPath $idb
$restoredSha = (Get-FileHash -LiteralPath $idb -Algorithm SHA256).Hash
if ($restoredItem.Length -ne $expectedSize -or $restoredSha -ne $expectedSha) { throw 'UID0002KA rollback restore mismatch; halt.' }
~~~~
