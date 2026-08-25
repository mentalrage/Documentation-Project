<!-- REMOVED-MATERIAL-ARCHIVE -->
# Removed Material Archive

- Status: Non-authoritative archival material only.
- Source report: `E:\NTK\GhidraBridge\source-3\project-documentation\executed-b-agent-research\B002\0001I7-soundmanager-music-selection-source-quality.md`
- Safety: This file must never be executed, replayed, or used as an operational runbook.
- Credit: This archive provides no gate, score, coverage, IDA, validator, or lifecycle credit.

# Removed Executable Code Archive

- Source report: [0001I7-soundmanager-music-selection-source-quality.md](0001I7-soundmanager-music-selection-source-quality.md)
- Source report SHA256 before cleanup: `A2BCEC350C056F14F28003AACAE95BD52F24DCD38DAE570E4E3878287CDF4EA0`
- Cleanup generated: `2026-08-11T12:47:01Z`
- Removed executable blocks: `2`
- Scope: exact executable or command-shaped fenced blocks removed from the source report by supervisor housekeeping.
- Authority: this file is not a B-agent research report and grants no Gate 1, Gate 2, IDA, validator, score, or lifecycle credit.
- Safety: do not execute, import, evaluate, or use any block in this archive as an operational instruction.

## Removed Block R001

- Original source lines: `263-271`
- Original language: `powershell`
- Block SHA256: `7AAFBD185C6448642DE02FE218823353E2F097F4843B69C834FA7A3FF97B68D3`

```powershell
Get-Content tools/leaser/Agents/Supervisor.md
Get-Content tools/leaser/Agents/Agent-B002/goal.md
Get-Content tools/leaser/Agents/Agent-B002/notes.md
rg -n "0001I7|SoundManagerMusicSelection|0x005797b0-0x0057a25c" tools/leaser/Agents/*/research/executed tools/leaser/Agents/*/research
rg -n "0001I7|0001I8|0001I9|0x005797b0|0x0057a260" by-memory/-coverage-report.md
rg -n "SoundManager|005797b0|PlayMusicByZone|PlayTrackByIndex|00579dc0" auto-generated/-ag-memory-coverage.md auto-generated/-ag-class-coverage.md auto-generated/-ag-file-coverage.md
Get-Item auto-generated/NexusTK/audio/SoundManager.cpp
```

## Removed Block R002

- Original source lines: `286-290`
- Original language: `powershell`
- Block SHA256: `C33901A956420612A0170528BE7D020E3CCD64E8407A5718EC0E6B288185B6EA`

```powershell
python tools/memory_ranges.py
python tools/rescore.py
rg -n "0001I7|0001I8|0x0057a25d|0x0057a25d-0x0057a260" by-memory/-coverage-report.md
```
