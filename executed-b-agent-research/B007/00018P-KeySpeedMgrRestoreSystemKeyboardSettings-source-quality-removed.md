<!-- REMOVED-MATERIAL-ARCHIVE -->
# Removed Material Archive

- Status: Non-authoritative archival material only.
- Source report: `E:\NTK\GhidraBridge\source-3\project-documentation\executed-b-agent-research\B007\00018P-KeySpeedMgrRestoreSystemKeyboardSettings-source-quality.md`
- Safety: This file must never be executed, replayed, or used as an operational runbook.
- Credit: This archive provides no gate, score, coverage, IDA, validator, or lifecycle credit.

# Removed Executable Code Archive

- Source report: [00018P-KeySpeedMgrRestoreSystemKeyboardSettings-source-quality.md](00018P-KeySpeedMgrRestoreSystemKeyboardSettings-source-quality.md)
- Source report SHA256 before cleanup: `A051AB7F0AB4E29806923148FB693161DDCFBF9B4C38535FA4845B3822B6CB6B`
- Cleanup generated: `2026-08-11T12:47:12Z`
- Removed executable blocks: `1`
- Scope: exact executable or command-shaped fenced blocks removed from the source report by supervisor housekeeping.
- Authority: this file is not a B-agent research report and grants no Gate 1, Gate 2, IDA, validator, score, or lifecycle credit.
- Safety: do not execute, import, evaluate, or use any block in this archive as an operational instruction.

## Removed Block R001

- Original source lines: `253-259`
- Original language: `powershell`
- Block SHA256: `D3FDCF4421CD31F839665EC5D6D927E75C5A8FB8EF746598FE2567C3B8F3C255`

```powershell
python source-3/project-documentation/tools/validator.py --mode file --file source-3/project-documentation/by-memory/0x004eff30-0x004eff5d.KeySpeedMgrRestoreSystemKeyboardSettings.md --apply
python source-3/project-documentation/tools/validator.py --mode file --file source-3/project-documentation/by-class/KeySpeedMgr.md --apply
python source-3/project-documentation/tools/validator.py --mode file --file source-3/project-documentation/by-file/KeySpeedMgr.md --apply
python source-3/project-documentation/tools/validator.py --mode file --file source-3/project-documentation/by-memory/0x004efea0-0x004f0008.KeySpeedMgr.md --apply
python source-3/project-documentation/tools/validator.py --mode autogen --apply
```
