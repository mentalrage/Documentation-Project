<!-- REMOVED-MATERIAL-ARCHIVE -->
# Removed Material Archive

- Status: Non-authoritative archival material only.
- Source report: `E:\NTK\GhidraBridge\source-3\project-documentation\executed-b-agent-research\B010\0001BG-ReallocateOrThrow-source-quality.md`
- Safety: This file must never be executed, replayed, or used as an operational runbook.
- Credit: This archive provides no gate, score, coverage, IDA, validator, or lifecycle credit.

# Removed Executable Code Archive

- Source report: [0001BG-ReallocateOrThrow-source-quality.md](0001BG-ReallocateOrThrow-source-quality.md)
- Source report SHA256 before cleanup: `480D6A0BC83716C1D669EA80132CA312B7BE72E084F3BD27EB767B8B860B877F`
- Cleanup generated: `2026-08-11T12:47:15Z`
- Removed executable blocks: `1`
- Scope: exact executable or command-shaped fenced blocks removed from the source report by supervisor housekeeping.
- Authority: this file is not a B-agent research report and grants no Gate 1, Gate 2, IDA, validator, score, or lifecycle credit.
- Safety: do not execute, import, evaluate, or use any block in this archive as an operational instruction.

## Removed Block R001

- Original source lines: `423-430`
- Original language: `powershell`
- Block SHA256: `991D467BA5E359713E36F4806BB78A50DE413EAF8184998C9D400015DAF65E95`

```powershell
python .\tools\validator.py --mode file --file .\by-memory\0x00516190-0x00516210.ReallocateOrThrow.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file .\by-class\MemoryMan.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file .\by-file\MemoryMan.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file .\by-global\MemoryAllocationHelpers.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file .\by-memory\0x00516000-0x0051628e.MemoryManAndAllocationHelpers.md --apply --queue-timeout 240
python .\tools\validator.py --queue-status
```
