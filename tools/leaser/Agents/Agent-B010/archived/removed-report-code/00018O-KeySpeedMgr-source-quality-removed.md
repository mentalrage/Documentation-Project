<!-- REMOVED-MATERIAL-ARCHIVE -->
# Removed Material Archive

- Status: Non-authoritative archival material only.
- Source report: `E:\NTK\GhidraBridge\source-3\project-documentation\executed-b-agent-research\B010\00018O-KeySpeedMgr-source-quality.md`
- Safety: This file must never be executed, replayed, or used as an operational runbook.
- Credit: This archive provides no gate, score, coverage, IDA, validator, or lifecycle credit.

# Removed Executable Code Archive

- Source report: [00018O-KeySpeedMgr-source-quality.md](00018O-KeySpeedMgr-source-quality.md)
- Source report SHA256 before cleanup: `1EBEDCFD084B22828132E139710E356CA7CFAAA678A0BBBD2612C1A779DCCEF2`
- Cleanup generated: `2026-08-11T12:47:15Z`
- Removed executable blocks: `1`
- Scope: exact executable or command-shaped fenced blocks removed from the source report by supervisor housekeeping.
- Authority: this file is not a B-agent research report and grants no Gate 1, Gate 2, IDA, validator, score, or lifecycle credit.
- Safety: do not execute, import, evaluate, or use any block in this archive as an operational instruction.

## Removed Block R001

- Original source lines: `392-406`
- Original language: `powershell`
- Block SHA256: `B481C3D99E12780052D346CD7C1D3AE7DBC6317CE8B0423C5DF9A3C280C9AA14`

```powershell
python .\tools\validator.py --mode file --file by-memory\0x004efea0-0x004f0008.KeySpeedMgr.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-memory\0x004efea0-0x004efedd.KeySpeedMgrConstructor.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-memory\0x004eff00-0x004eff25.KeySpeedMgrLoadSystemKeyboardSettings.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-memory\0x004eff30-0x004eff5d.KeySpeedMgrRestoreSystemKeyboardSettings.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-memory\0x004eff60-0x004eff91.KeySpeedMgrApplyKeyboardRepeatSettingsRaw.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-memory\0x004effa0-0x004effbd.ApplyFastKeyboardRepeatSettings.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-memory\0x004effc0-0x004f0008.KeySpeedMgrScalarDeletingDestructor.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-class\KeySpeedMgr.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-file\KeySpeedMgr.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-type\by-struct\KeySpeedMgrLayout.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-type\by-vtable\KeySpeedMgrVtable.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-global\g_pKeySpeedMgr.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-memory\0x0067ab48-0x0067ab4c.g_pKeySpeedMgr.md --apply --queue-timeout 240
```
