<!-- REMOVED-MATERIAL-ARCHIVE -->
# Removed Material Archive

- Status: Non-authoritative archival material only.
- Source report: `E:\NTK\GhidraBridge\source-3\project-documentation\executed-b-agent-research\B009\000164-GrafPortClipRectHelper-source-quality.md`
- Safety: This file must never be executed, replayed, or used as an operational runbook.
- Credit: This archive provides no gate, score, coverage, IDA, validator, or lifecycle credit.

# Removed Executable Code Archive

- Source report: [000164-GrafPortClipRectHelper-source-quality.md](000164-GrafPortClipRectHelper-source-quality.md)
- Source report SHA256 before cleanup: `26F6F720CBCA8D9BF8E276654807E50D026265AD5C49E4B690BA319DF8DB194B`
- Cleanup generated: `2026-08-11T12:47:14Z`
- Removed executable blocks: `1`
- Scope: exact executable or command-shaped fenced blocks removed from the source report by supervisor housekeeping.
- Authority: this file is not a B-agent research report and grants no Gate 1, Gate 2, IDA, validator, score, or lifecycle credit.
- Safety: do not execute, import, evaluate, or use any block in this archive as an operational instruction.

## Removed Block R001

- Original source lines: `172-179`
- Original language: `powershell`
- Block SHA256: `E1CFBF09BB54180D221C1D23C57424286AFC5B06C88D75D4DBB547A174BD4A69`

```powershell
python .\tools\validator.py --mode file --file by-memory\0x004b96c0-0x004b9768.GrafPortGetClipRect.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-class\GrafPort.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-file\GrafPort.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-memory\0x004ba450-0x004ba53b.GrafPortDrawRectFrame.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-memory\0x004ba540-0x004ba6ad.CompositePixels16.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-memory\0x004b9770-0x004b981e.GrafPortEffectiveClipAndBackingRelease.md --apply --queue-timeout 240
```
