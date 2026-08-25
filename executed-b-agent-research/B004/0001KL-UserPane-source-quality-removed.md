<!-- REMOVED-MATERIAL-ARCHIVE -->
# Removed Material Archive

- Status: Non-authoritative archival material only.
- Source report: `E:\NTK\GhidraBridge\source-3\project-documentation\executed-b-agent-research\B004\0001KL-UserPane-source-quality.md`
- Safety: This file must never be executed, replayed, or used as an operational runbook.
- Credit: This archive provides no gate, score, coverage, IDA, validator, or lifecycle credit.

# Removed Executable Code Archive

- Source report: [0001KL-UserPane-source-quality.md](0001KL-UserPane-source-quality.md)
- Source report SHA256 before cleanup: `477BC1F399BA263B0C28C7E77E65F1B3D20BADE92DDCF85195FFF101E1D5952F`
- Cleanup generated: `2026-08-11T12:47:07Z`
- Removed executable blocks: `2`
- Scope: exact executable or command-shaped fenced blocks removed from the source report by supervisor housekeeping.
- Authority: this file is not a B-agent research report and grants no Gate 1, Gate 2, IDA, validator, score, or lifecycle credit.
- Safety: do not execute, import, evaluate, or use any block in this archive as an operational instruction.

## Removed Block R001

- Original source lines: `411-415`
- Original language: `powershell`
- Block SHA256: `4E0517C88E57FE0210C1356C2401796D3C563B43C764C28A9AA5D2C9264A977A`

```powershell
python .\tools\validator.py --mode file --file by-memory\0x005a2530-0x005b8395.UserPane.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-class\UserPane.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-file\UserPane.md --apply --queue-timeout 240
```

## Removed Block R002

- Original source lines: `419-425`
- Original language: `powershell`
- Block SHA256: `D5F0506F05BF8EC64C990121DECACE4785C430810CA36E715E512ECDDEDD1047`

```powershell
python .\tools\validator.py --mode file --file by-memory\0x005a5b80-0x005a5bc7.UserPaneOnBoundsChanged.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-memory\0x005a5bd0-0x005a7422.UserPaneHandleKeyEvent.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-memory\0x005a76c0-0x005a82bd.UserPaneHandleServerMessage.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-memory\0x005a83b0-0x005a87ad.UserPaneHandleAnimationStep.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-memory\0x0062ef0c-0x0062efcc.UserPaneVtableData.md --apply --queue-timeout 240
```
