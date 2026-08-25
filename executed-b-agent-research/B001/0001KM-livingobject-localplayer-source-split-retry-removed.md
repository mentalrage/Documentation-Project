<!-- REMOVED-MATERIAL-ARCHIVE -->
# Removed Material Archive

- Status: Non-authoritative archival material only.
- Source report: `E:\NTK\GhidraBridge\source-3\project-documentation\executed-b-agent-research\B001\0001KM-livingobject-localplayer-source-split-retry.md`
- Safety: This file must never be executed, replayed, or used as an operational runbook.
- Credit: This archive provides no gate, score, coverage, IDA, validator, or lifecycle credit.

# Removed Executable Code Archive

- Source report: [0001KM-livingobject-localplayer-source-split-retry.md](0001KM-livingobject-localplayer-source-split-retry.md)
- Source report SHA256 before cleanup: `015A9612DF9011F22889E88F1F5231C66C9DE9BE27B2A6D51EE39079783C8EA1`
- Cleanup generated: `2026-08-11T12:46:57Z`
- Removed executable blocks: `1`
- Scope: exact executable or command-shaped fenced blocks removed from the source report by supervisor housekeeping.
- Authority: this file is not a B-agent research report and grants no Gate 1, Gate 2, IDA, validator, score, or lifecycle credit.
- Safety: do not execute, import, evaluate, or use any block in this archive as an operational instruction.

## Removed Block R001

- Original source lines: `887-904`
- Original language: `powershell`
- Block SHA256: `B3D92EAC53D2708979326726ED57CB6EA07BD058A9FC83F3FD779CFA6B1CF07E`

```powershell
python tools/validator.py --mode file --file by-memory/0x005a5b80-0x005a5bc7.UserPaneOnBoundsChanged.md --apply
python tools/validator.py --mode file --file by-memory/0x005a5bd0-0x005a7422.UserPaneHandleKeyEvent.md --apply
python tools/validator.py --mode file --file by-memory/0x005a7422-0x005a76c0.UserPaneHandleKeyEventSwitchTables.md --apply
python tools/validator.py --mode file --file by-memory/0x005a76c0-0x005a82bd.UserPaneHandleServerMessage.md --apply
python tools/validator.py --mode file --file by-memory/0x005a82bd-0x005a83b0.UserPaneHandleServerMessageSwitchTables.md --apply
python tools/validator.py --mode file --file by-memory/0x005a83b0-0x005a87ad.UserPaneHandleAnimationStep.md --apply
python tools/validator.py --mode file --file by-memory/0x005a87b0-0x005a87d5.LivingObjectPaneGetActiveLinkedRecordByIndexRaw.md --apply
python tools/validator.py --mode file --file by-memory/-ignored.md --apply
python tools/validator.py --mode file --file by-memory/0x005a2de0-0x005ad441.LivingObjectPaneLocalPlayerExtensions.md --apply
python tools/validator.py --mode file --file by-memory/0x005a2530-0x005b8395.UserPane.md --apply
python tools/validator.py --mode file --file by-class/UserPane.md --apply
python tools/validator.py --mode file --file by-file/UserPane.md --apply
python tools/validator.py --mode file --file by-class/LivingObjectPane.md --apply
python tools/validator.py --mode file --file by-file/LivingObjectPane.md --apply
python tools/validator.py --mode file --file by-memory/-coverage-report.md --apply
python tools/memory_ranges.py report
```
