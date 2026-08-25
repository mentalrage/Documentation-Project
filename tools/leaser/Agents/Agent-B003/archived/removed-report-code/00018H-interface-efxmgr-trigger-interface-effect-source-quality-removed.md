<!-- REMOVED-MATERIAL-ARCHIVE -->
# Removed Material Archive

- Status: Non-authoritative archival material only.
- Source report: `E:\NTK\GhidraBridge\source-3\project-documentation\executed-b-agent-research\B003\00018H-interface-efxmgr-trigger-interface-effect-source-quality.md`
- Safety: This file must never be executed, replayed, or used as an operational runbook.
- Credit: This archive provides no gate, score, coverage, IDA, validator, or lifecycle credit.

# Removed Executable Code Archive

- Source report: [00018H-interface-efxmgr-trigger-interface-effect-source-quality.md](00018H-interface-efxmgr-trigger-interface-effect-source-quality.md)
- Source report SHA256 before cleanup: `A6AAFB0BEEDD07C4C2151E4B542ED6069388CF0B77BA7FFC2E0D796F5D95E8E4`
- Cleanup generated: `2026-08-11T12:47:03Z`
- Removed executable blocks: `1`
- Scope: exact executable or command-shaped fenced blocks removed from the source report by supervisor housekeeping.
- Authority: this file is not a B-agent research report and grants no Gate 1, Gate 2, IDA, validator, score, or lifecycle credit.
- Safety: do not execute, import, evaluate, or use any block in this archive as an operational instruction.

## Removed Block R001

- Original source lines: `273-285`
- Original language: `powershell`
- Block SHA256: `6CF0C98DCE4C939D300B3086A3DEC07B5F6719D5D9720225DF96224A866E9C74`

```powershell
cd E:\NTK\GhidraBridge\source-3\project-documentation
python tools\validator.py --mode file --file by-memory\0x004e9ee0-0x004e9f2d.InterfaceEfxMgrTriggerInterfaceEffect.md --apply
python tools\validator.py --mode file --file by-class\InterfaceEfxMgr.md --apply
python tools\validator.py --mode file --file by-file\InterfaceEfx.md --apply
python tools\validator.py --mode file --file by-memory\0x004e97b0-0x004ea121.InterfaceEfxAndMgr.md --apply
python tools\validator.py --mode file --file by-memory\0x0067a7c8-0x0067a7cc.g_pConfig.md --apply
python tools\validator.py --mode file --file by-memory\0x00541040-0x00541114.SendLowHighDisplayModeOption.md --apply
python tools\validator.py --mode file --file by-resource\interface-efx-resources.md --apply
python tools\validator.py --mode file --file by-memory\-coverage-report.md --apply
python tools\validator.py --mode autogen --apply
python tools\validator.py --mode rescore --apply
```
