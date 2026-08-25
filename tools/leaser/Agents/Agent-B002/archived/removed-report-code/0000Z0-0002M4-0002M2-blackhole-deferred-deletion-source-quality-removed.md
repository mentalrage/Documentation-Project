<!-- REMOVED-MATERIAL-ARCHIVE -->
# Removed Material Archive

- Status: Non-authoritative archival material only.
- Source report: `E:\NTK\GhidraBridge\source-3\project-documentation\executed-b-agent-research\B002\0000Z0-0002M4-0002M2-blackhole-deferred-deletion-source-quality.md`
- Safety: This file must never be executed, replayed, or used as an operational runbook.
- Credit: This archive provides no gate, score, coverage, IDA, validator, or lifecycle credit.

# Removed Executable Code Archive

- Source report: [0000Z0-0002M4-0002M2-blackhole-deferred-deletion-source-quality.md](0000Z0-0002M4-0002M2-blackhole-deferred-deletion-source-quality.md)
- Source report SHA256 before cleanup: `4265F11452FA72441279C896662C39380DC65E7775CC71D935FAA0B3C261BBB6`
- Cleanup generated: `2026-08-11T12:47:00Z`
- Removed executable blocks: `2`
- Scope: exact executable or command-shaped fenced blocks removed from the source report by supervisor housekeeping.
- Authority: this file is not a B-agent research report and grants no Gate 1, Gate 2, IDA, validator, score, or lifecycle credit.
- Safety: do not execute, import, evaluate, or use any block in this archive as an operational instruction.

## Removed Block R001

- Original source lines: `323-338`
- Original language: `powershell`
- Block SHA256: `3D1542EB55B1BD64144D5E5FF095A23DF01DA86361A08FD84BCF46F5DC81324C`

```powershell
Set-Location E:\NTK\GhidraBridge\source-3\project-documentation

python tools\validator.py --mode file --file by-memory\0x004690b0-0x00469288.BlackHoleDeferredDeletionQueue.md --apply
python tools\validator.py --mode file --file by-memory\0x00469200-0x00469233.BlackHoleReleaseQueuedOwnedObjects.md --apply
python tools\validator.py --mode file --file by-memory\0x00469240-0x00469288.BlackHoleScalarDeletingDestructor.md --apply
python tools\validator.py --mode file --file by-class\BlackHole.md --apply
python tools\validator.py --mode file --file by-file\BlackHole.md --apply
python tools\validator.py --mode file --file by-global\g_pApplicationCleanupQueue.md --apply
python tools\validator.py --mode file --file by-type\by-struct\BlackHoleLayout.md --apply
python tools\validator.py --mode file --file by-type\by-vtable\BlackHoleVtable.md --apply
python tools\validator.py --mode file --file by-memory\-coverage-report.md --apply
python tools\memory_ranges.py report
python tools\validator.py --mode autogen --apply --lock-timeout -1
python tools\validator.py --mode rescore --apply --lock-timeout -1
```

## Removed Block R002

- Original source lines: `342-345`
- Original language: `powershell`
- Block SHA256: `AE1D597EF8421C7B64EBD8484D04010061F667AF11264FCD4BD6D7DEEC52E864`

```powershell
Get-Content auto-generated\NexusTK\ui\core\BlackHole.cpp
Select-String -Path auto-generated\-ag-memory-coverage.md -Pattern 'BlackHoleDeferredDeletionQueue|BlackHoleReleaseQueuedOwnedObjects|BlackHoleScalarDeletingDestructor'
```
