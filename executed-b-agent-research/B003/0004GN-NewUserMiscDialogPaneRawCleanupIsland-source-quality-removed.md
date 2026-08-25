<!-- REMOVED-MATERIAL-ARCHIVE -->
# Removed Material Archive

- Status: Non-authoritative archival material only.
- Source report: `E:\NTK\GhidraBridge\source-3\project-documentation\executed-b-agent-research\B003\0004GN-NewUserMiscDialogPaneRawCleanupIsland-source-quality.md`
- Safety: This file must never be executed, replayed, or used as an operational runbook.
- Credit: This archive provides no gate, score, coverage, IDA, validator, or lifecycle credit.

# Removed Executable Code Archive

- Source report: [0004GN-NewUserMiscDialogPaneRawCleanupIsland-source-quality.md](0004GN-NewUserMiscDialogPaneRawCleanupIsland-source-quality.md)
- Source report SHA256 before cleanup: `F81DC81BC09CC8B9CFD705A9C4FC7238D6034FBAA24489AB358BAA1E7801A922`
- Cleanup generated: `2026-08-11T12:47:06Z`
- Removed executable blocks: `2`
- Scope: exact executable or command-shaped fenced blocks removed from the source report by supervisor housekeeping.
- Authority: this file is not a B-agent research report and grants no Gate 1, Gate 2, IDA, validator, score, or lifecycle credit.
- Safety: do not execute, import, evaluate, or use any block in this archive as an operational instruction.

## Removed Block R001

- Original source lines: `262-264`
- Original language: `powershell`
- Block SHA256: `A25E4771760362D120AA63CBA45938FA75387A5465048548F54EA100999DD245`

```powershell
python .\tools\validator.py --mode file --file by-memory/0x004fbfd0-0x004fc00f.NewUserMiscDialogPaneRawCleanupIsland.md --apply --queue-timeout 240
```

## Removed Block R002

- Original source lines: `287-291`
- Original language: `powershell`
- Block SHA256: `BAAD4F62221AB807F9E0BF0C7B0676B179A4F4EFBCCE8E94CE967DA51E8275F8`

```powershell
python .\tools\validator.py --mode file --file by-class/NewUserMiscDialogPane.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-file/NewUserMiscDialogPane.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-memory/0x004fb630-0x004fccee.NewUserMiscDialogPaneCoreAndPacketHelpers.md --apply --queue-timeout 240
```
