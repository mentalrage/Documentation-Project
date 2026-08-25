<!-- REMOVED-MATERIAL-ARCHIVE -->
# Removed Material Archive

- Status: Non-authoritative archival material only.
- Source report: `E:\NTK\GhidraBridge\source-3\project-documentation\executed-b-agent-research\B002\0003X0-RankingCategoryRecordVectorInsertWithGrowth-source-quality.md`
- Safety: This file must never be executed, replayed, or used as an operational runbook.
- Credit: This archive provides no gate, score, coverage, IDA, validator, or lifecycle credit.

# Removed Executable Code Archive

- Source report: [0003X0-RankingCategoryRecordVectorInsertWithGrowth-source-quality.md](0003X0-RankingCategoryRecordVectorInsertWithGrowth-source-quality.md)
- Source report SHA256 before cleanup: `C47C64A3CECA3785F9903B23AD29E88C9FDEFAD309839F298BE66943DFBFF001`
- Cleanup generated: `2026-08-11T12:47:03Z`
- Removed executable blocks: `1`
- Scope: exact executable or command-shaped fenced blocks removed from the source report by supervisor housekeeping.
- Authority: this file is not a B-agent research report and grants no Gate 1, Gate 2, IDA, validator, score, or lifecycle credit.
- Safety: do not execute, import, evaluate, or use any block in this archive as an operational instruction.

## Removed Block R001

- Original source lines: `375-379`
- Original language: `powershell`
- Block SHA256: `D1EA1F6A41707E917822F363BA6BA6936C481C1FF7D2FDF212A98B1CB7CD8AEB`

```powershell
$p = 'E:\NTK\Resources\NexusTK\NexusTK.exe.i64'
$fs = [System.IO.File]::Open($p,[System.IO.FileMode]::Open,[System.IO.FileAccess]::Read,[System.IO.FileShare]::None)
try { $sha=[System.Security.Cryptography.SHA256]::Create(); $hash=([BitConverter]::ToString($sha.ComputeHash($fs))).Replace('-',''); $length=$fs.Length; $mtime=[System.IO.File]::GetLastWriteTimeUtc($p); $mtimeTicks=$mtime.Ticks } finally { if($sha){$sha.Dispose()}; $fs.Dispose() }
```
