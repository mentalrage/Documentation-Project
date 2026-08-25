<!-- REMOVED-MATERIAL-ARCHIVE -->
# Removed Material Archive

- Status: Non-authoritative archival material only.
- Source report: `E:\NTK\GhidraBridge\source-3\project-documentation\executed-b-agent-research\B003\0000YH-AboveFrame-source-quality.md`
- Safety: This file must never be executed, replayed, or used as an operational runbook.
- Credit: This archive provides no gate, score, coverage, IDA, validator, or lifecycle credit.

# Removed Executable Code Archive

- Source report: [0000YH-AboveFrame-source-quality.md](0000YH-AboveFrame-source-quality.md)
- Source report SHA256 before cleanup: `5AAEF36E19D092077734FD72B9767E1F910FBD2CCBB1EB778948A9DF891F6DFA`
- Cleanup generated: `2026-08-11T12:47:13Z`
- Removed executable blocks: `2`
- Scope: exact executable or command-shaped fenced blocks removed from the source report by supervisor housekeeping.
- Authority: this file is not a B-agent research report and grants no Gate 1, Gate 2, IDA, validator, score, or lifecycle credit.
- Safety: do not execute, import, evaluate, or use any block in this archive as an operational instruction.

## Removed Block R001

- Original source lines: `593-604`
- Original language: `powershell`
- Block SHA256: `76075A1470DA7D7D2728D46075ADE52729DC144C0434E3DD78697F017A6C08ED`

```powershell
python .\tools\validator.py --mode file --file by-memory\0x004610f0-0x0046178a.AboveFrame.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-class\AboveFrame.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-file\FrameChrome.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-item\BuildAboveFrameBorder_00461310.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-memory\0x004615b0-0x00461657.AboveFrameRefreshHelpers.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-memory\0x004616c8-0x004616de.AboveFrameAdjustorThunks.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-global\FrameChromeSlots.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-memory\0x0067a834-0x0067a874.AboveFrameSlots.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-memory\0x00610f60-0x00610fe8.FrameChromeResourceStrings.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-type\by-vtable\AboveFrameVtables.md --apply --queue-timeout 240
```

## Removed Block R002

- Original source lines: `608-611`
- Original language: `powershell`
- Block SHA256: `EE416CA4B5CE6DC3E8ADA91195922B60B4ABD827AA57B0FBC0783A947B905FF3`

```powershell
python .\tools\validator.py --mode file --file by-memory\0x0067a874-0x0067a878.g_pGeneralPurposePanel.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-memory\0x004b9820-0x004ba24a.SurfacePaintHelpers.md --apply --queue-timeout 240
```
