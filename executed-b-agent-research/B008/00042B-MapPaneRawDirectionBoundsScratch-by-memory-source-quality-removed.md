<!-- REMOVED-MATERIAL-ARCHIVE -->
# Removed Material Archive

- Status: Non-authoritative archival material only.
- Source report: `E:\NTK\GhidraBridge\source-3\project-documentation\executed-b-agent-research\B008\00042B-MapPaneRawDirectionBoundsScratch-by-memory-source-quality.md`
- Safety: This file must never be executed, replayed, or used as an operational runbook.
- Credit: This archive provides no gate, score, coverage, IDA, validator, or lifecycle credit.

# Removed Executable Code Archive

- Source report: [00042B-MapPaneRawDirectionBoundsScratch-by-memory-source-quality.md](00042B-MapPaneRawDirectionBoundsScratch-by-memory-source-quality.md)
- Source report SHA256 before cleanup: `876F690CF1410D21F215EFD551B54DA15FF6518F974C673765ECA49F2322CBE3`
- Cleanup generated: `2026-08-11T12:47:13Z`
- Removed executable blocks: `1`
- Scope: exact executable or command-shaped fenced blocks removed from the source report by supervisor housekeeping.
- Authority: this file is not a B-agent research report and grants no Gate 1, Gate 2, IDA, validator, score, or lifecycle credit.
- Safety: do not execute, import, evaluate, or use any block in this archive as an operational instruction.

## Removed Block R001

- Original source lines: `424-426`
- Original language: `powershell`
- Block SHA256: `20E86EAB6D4CE2E17CD6B96D971D88A024D65FBEB046599C89BFF2A0387F9DEB`

```powershell
python .\tools\validator.py --mode file --file by-memory/0x00505750-0x005057c8.MapPaneRawDirectionBoundsScratch.md --apply --queue-timeout 240 --wait-generated
```
