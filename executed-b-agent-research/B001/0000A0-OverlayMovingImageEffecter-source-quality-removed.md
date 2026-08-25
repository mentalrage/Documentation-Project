<!-- REMOVED-MATERIAL-ARCHIVE -->
# Removed Material Archive

- Status: Non-authoritative archival material only.
- Source report: `E:\NTK\GhidraBridge\source-3\project-documentation\executed-b-agent-research\B001\0000A0-OverlayMovingImageEffecter-source-quality.md`
- Safety: This file must never be executed, replayed, or used as an operational runbook.
- Credit: This archive provides no gate, score, coverage, IDA, validator, or lifecycle credit.

# Removed Executable Code Archive

- Source report: [0000A0-OverlayMovingImageEffecter-source-quality.md](0000A0-OverlayMovingImageEffecter-source-quality.md)
- Source report SHA256 before cleanup: `956F4B125F4ECE9263A526277148283FD2F998B31FE79A96BC808824504A16E7`
- Cleanup generated: `2026-08-11T12:46:56Z`
- Removed executable blocks: `2`
- Scope: exact executable or command-shaped fenced blocks removed from the source report by supervisor housekeeping.
- Authority: this file is not a B-agent research report and grants no Gate 1, Gate 2, IDA, validator, score, or lifecycle credit.
- Safety: do not execute, import, evaluate, or use any block in this archive as an operational instruction.

## Removed Block R001

- Original source lines: `446-448`
- Original language: `powershell`
- Block SHA256: `B98B5F8FC0FFD4D4F5C053649FDB3F557FA56F0DA6395CB011784640F1276AA5`

```powershell
python .\source-3\project-documentation\tools\validator.py --mode file --file .\source-3\project-documentation\by-class\OverlayMovingImageEffecter.md --apply
```

## Removed Block R002

- Original source lines: `452-455`
- Original language: `powershell`
- Block SHA256: `8EAD58F77DC3A3214AEC0AA7B9D0B6E4336D2D200B915D83EA068398048A993C`

```powershell
rg -n "sub_|dword_67A744|word_66DA9C|word_66DAA0|ScalarDeletingDestructor|95/95|below-95|FittingRoomDownloadControlPane" .\source-3\project-documentation\by-class\OverlayMovingImageEffecter.md
rg -n "OverlayMovingImageEffecter|0x0055a990|0x00623900|0x0055bef0" .\source-3\project-documentation\by-file\Effects.md .\source-3\project-documentation\by-memory\0x0055a260-0x0055c1ff.ScreenEffecterRuntimeCluster.md .\source-3\project-documentation\by-type\by-vtable\ScreenEffecterVtableFamily.md .\source-3\project-documentation\by-memory\0x006235a0-0x00623d18.ScreenEffecterVtableData.md
```
