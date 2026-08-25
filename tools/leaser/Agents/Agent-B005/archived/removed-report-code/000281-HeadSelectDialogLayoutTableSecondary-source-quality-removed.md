<!-- REMOVED-MATERIAL-ARCHIVE -->
# Removed Material Archive

- Status: Non-authoritative archival material only.
- Source report: `E:\NTK\GhidraBridge\source-3\project-documentation\executed-b-agent-research\B005\000281-HeadSelectDialogLayoutTableSecondary-source-quality.md`
- Safety: This file must never be executed, replayed, or used as an operational runbook.
- Credit: This archive provides no gate, score, coverage, IDA, validator, or lifecycle credit.

# Removed Executable Code Archive

- Source report: [000281-HeadSelectDialogLayoutTableSecondary-source-quality.md](000281-HeadSelectDialogLayoutTableSecondary-source-quality.md)
- Source report SHA256 before cleanup: `ED92EFA44BAD86E42F34A21F8DD6E0408B944A18C200BA1AE3270B70FF971685`
- Cleanup generated: `2026-08-11T12:47:09Z`
- Removed executable blocks: `3`
- Scope: exact executable or command-shaped fenced blocks removed from the source report by supervisor housekeeping.
- Authority: this file is not a B-agent research report and grants no Gate 1, Gate 2, IDA, validator, score, or lifecycle credit.
- Safety: do not execute, import, evaluate, or use any block in this archive as an operational instruction.

## Removed Block R001

- Original source lines: `259-261`
- Original language: `powershell`
- Block SHA256: `5133FD08CB44E407800245881DBEBDA5D63F38C81C94FB4BD0CA1E5F940F9706`

```powershell
python .\tools\validator.py --mode file --file by-memory\0x0066eea0-0x0066fce4.HeadSelectDialogLayoutTableSecondary.md --apply --queue-timeout 240 --wait-generated
```

## Removed Block R002

- Original source lines: `265-269`
- Original language: `powershell`
- Block SHA256: `A6B51FAFF2480E0CC9D7FDCFB0FEE6284CAB3286685EDD77E613127A86B26346`

```powershell
python .\tools\validator.py --mode file --file by-memory\0x00551030-0x005520e5.HeadSelectDialogCore.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-class\HeadSelectDialog.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-file\HeadSelectDialog.md --apply --queue-timeout 240 --wait-generated
```

## Removed Block R003

- Original source lines: `273-275`
- Original language: `powershell`
- Block SHA256: `C58C0094932EE0FB2BB0584C288F0B98A9F3FC92210477486AEC97BBFDC2BEC3`

```powershell
rg -n "UID:000281|s_highResHeadVerticalOffsets|Empty Emitter Marker" auto-generated\NexusTK\ui\dialogs\HeadSelectDialog.cpp auto-generated\-ag-coverage-report-by-memory.md auto-generated\-ag-memory-coverage.md
```
