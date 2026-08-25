<!-- REMOVED-MATERIAL-ARCHIVE -->
# Removed Material Archive

- Status: Non-authoritative archival material only.
- Source report: `E:\NTK\GhidraBridge\source-3\project-documentation\executed-b-agent-research\B002\00017M-effectobj-render-frame-source-quality.md`
- Safety: This file must never be executed, replayed, or used as an operational runbook.
- Credit: This archive provides no gate, score, coverage, IDA, validator, or lifecycle credit.

# Removed Executable Code Archive

- Source report: [00017M-effectobj-render-frame-source-quality.md](00017M-effectobj-render-frame-source-quality.md)
- Source report SHA256 before cleanup: `177A6E62C84A49738ED8813AC1CE6FFABC34A834218B58AFA8F7C307C643A70C`
- Cleanup generated: `2026-08-11T12:47:00Z`
- Removed executable blocks: `2`
- Scope: exact executable or command-shaped fenced blocks removed from the source report by supervisor housekeeping.
- Authority: this file is not a B-agent research report and grants no Gate 1, Gate 2, IDA, validator, score, or lifecycle credit.
- Safety: do not execute, import, evaluate, or use any block in this archive as an operational instruction.

## Removed Block R001

- Original source lines: `278-286`
- Original language: `powershell`
- Block SHA256: `BFAA9FD0FB9742D82709F17054219414544AA8308EC750D930EBB7A634D79B2D`

```powershell
cd E:\NTK\GhidraBridge\source-3\project-documentation
python .\tools\validator.py --mode file --file by-memory\0x004de190-0x004de29f.EffectObjImageLibRenderEffectFrame.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-memory\0x004ddf60-0x004dec30.EffectObjImageLibLocalMethodCluster.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-class\EffectObjImageLib.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-file\EffectObjImageLib.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-memory\-coverage-report.md --apply --queue-timeout 240
python .\tools\memory_ranges.py report
```

## Removed Block R002

- Original source lines: `290-295`
- Original language: `powershell`
- Block SHA256: `12A81F978248AFAE41B6FBA193EAC6D364C7003C129A0DF5AA9A20D2E61C3C90`

```powershell
python .\tools\validator.py --mode file --file by-type\by-struct\EffectObjImageLibLayout.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-type\by-struct\EffectFrameRecord.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-type\by-struct\EffectPixMapInfo.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-memory\0x005387b0-0x00538baa.EffectObjectPaneCore.md --apply --queue-timeout 240
```
