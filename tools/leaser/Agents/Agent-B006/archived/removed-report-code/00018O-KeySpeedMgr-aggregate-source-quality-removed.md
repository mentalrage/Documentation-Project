<!-- REMOVED-MATERIAL-ARCHIVE -->
# Removed Material Archive

- Status: Non-authoritative archival material only.
- Source report: `E:\NTK\GhidraBridge\source-3\project-documentation\executed-b-agent-research\B006\00018O-KeySpeedMgr-aggregate-source-quality.md`
- Safety: This file must never be executed, replayed, or used as an operational runbook.
- Credit: This archive provides no gate, score, coverage, IDA, validator, or lifecycle credit.

# Removed Executable Code Archive

- Source report: [00018O-KeySpeedMgr-aggregate-source-quality.md](00018O-KeySpeedMgr-aggregate-source-quality.md)
- Source report SHA256 before cleanup: `3091C643BE956D8C807A1E815E8FCA6972D0E55177584FE0DA127170A1D81C6B`
- Cleanup generated: `2026-08-11T12:47:10Z`
- Removed executable blocks: `2`
- Scope: exact executable or command-shaped fenced blocks removed from the source report by supervisor housekeeping.
- Authority: this file is not a B-agent research report and grants no Gate 1, Gate 2, IDA, validator, score, or lifecycle credit.
- Safety: do not execute, import, evaluate, or use any block in this archive as an operational instruction.

## Removed Block R001

- Original source lines: `585-598`
- Original language: `powershell`
- Block SHA256: `B200D8550DC82D66B3D2C2BF951614BFC6ABF21DAE30D801F910DB59F70E8117`

```powershell
python .\tools\validator.py --mode file --file .\by-class\KeySpeedMgr.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file .\by-file\KeySpeedMgr.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file .\by-type\by-struct\KeySpeedMgrLayout.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file .\by-global\g_pKeySpeedMgr.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file .\by-memory\0x004efea0-0x004f0008.KeySpeedMgr.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file .\by-memory\0x004efea0-0x004efedd.KeySpeedMgrConstructor.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file .\by-memory\0x004eff00-0x004eff25.KeySpeedMgrLoadSystemKeyboardSettings.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file .\by-memory\0x004eff30-0x004eff5d.KeySpeedMgrRestoreSystemKeyboardSettings.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file .\by-memory\0x004eff60-0x004eff91.KeySpeedMgrApplyKeyboardRepeatSettingsRaw.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file .\by-memory\0x004effa0-0x004effbd.ApplyFastKeyboardRepeatSettings.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file .\by-memory\0x004effc0-0x004f0008.KeySpeedMgrScalarDeletingDestructor.md --apply --queue-timeout 240
python .\tools\validator.py --mode autogen --apply --queue-timeout 240
```

## Removed Block R002

- Original source lines: `614-616`
- Original language: `powershell`
- Block SHA256: `1665F24E058F39ED52F80A7FBE9698CF2CA47A7D04CAE67D64D7D1BE74A434C9`

```powershell
python .\tools\validator.py --mode file --file .\by-memory\0x004efea0-0x004f0008.KeySpeedMgr.md --queue-timeout 240
```
