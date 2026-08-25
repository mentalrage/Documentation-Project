<!-- REMOVED-MATERIAL-ARCHIVE -->
# Removed Material Archive

- Status: Non-authoritative archival material only.
- Source report: `E:\NTK\GhidraBridge\source-3\project-documentation\executed-b-agent-research\B002\0000AM-PoolAllocator-class-source-quality.md`
- Safety: This file must never be executed, replayed, or used as an operational runbook.
- Credit: This archive provides no gate, score, coverage, IDA, validator, or lifecycle credit.

# Removed Executable Code Archive

- Source report: [0000AM-PoolAllocator-class-source-quality.md](0000AM-PoolAllocator-class-source-quality.md)
- Source report SHA256 before cleanup: `376B5B30A49C19082B82F489047F737CBBF239C635CB473B6C4239CC805084D4`
- Cleanup generated: `2026-08-11T12:47:00Z`
- Removed executable blocks: `1`
- Scope: exact executable or command-shaped fenced blocks removed from the source report by supervisor housekeeping.
- Authority: this file is not a B-agent research report and grants no Gate 1, Gate 2, IDA, validator, score, or lifecycle credit.
- Safety: do not execute, import, evaluate, or use any block in this archive as an operational instruction.

## Removed Block R001

- Original source lines: `485-494`
- Original language: `powershell`
- Block SHA256: `CE72BEA9F8DE25BFE22901CA8E90E33480062A11F8CD046561BFD776F9F9BD5D`

```powershell
python .\tools\validator.py --mode file --file by-class\PoolAllocator.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-file\PoolAllocator.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-type\by-struct\PoolAllocatorLayout.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-memory\0x004b13d0-0x004b1585.PoolAllocatorCore.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-memory\0x004b14c0-0x004b14ef.ThreadSafeNodeListPushFront.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-memory\0x00549bd0-0x00549bf1.PoolAllocatorChunkHelper.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-memory\0x00549c00-0x00549c18.PoolAllocatorFreeChunkList.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-global\PoolAllocatorStaticInstances.md --apply --queue-timeout 240
```
