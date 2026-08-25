<!-- REMOVED-MATERIAL-ARCHIVE -->
# Removed Material Archive

- Status: Non-authoritative archival material only.
- Source report: `E:\NTK\GhidraBridge\source-3\project-documentation\executed-b-agent-research\B003\0002IV-lightobj-get-light-bounds-source-quality.md`
- Safety: This file must never be executed, replayed, or used as an operational runbook.
- Credit: This archive provides no gate, score, coverage, IDA, validator, or lifecycle credit.

# Removed Executable Code Archive

- Source report: [0002IV-lightobj-get-light-bounds-source-quality.md](0002IV-lightobj-get-light-bounds-source-quality.md)
- Source report SHA256 before cleanup: `514D98E428F770F8C672ACE87CD14E9AA0C0CE34AC63AC9E66D2079DA7B23EF2`
- Cleanup generated: `2026-08-11T12:47:05Z`
- Removed executable blocks: `2`
- Scope: exact executable or command-shaped fenced blocks removed from the source report by supervisor housekeeping.
- Authority: this file is not a B-agent research report and grants no Gate 1, Gate 2, IDA, validator, score, or lifecycle credit.
- Safety: do not execute, import, evaluate, or use any block in this archive as an operational instruction.

## Removed Block R001

- Original source lines: `365-367`
- Original language: `powershell`
- Block SHA256: `7859A64608C17D1AACFFFA2AFFB6CDB1E1B9803D33324FF353E888F2DA252BEA`

```powershell
rg -n "0002IV|LightObjImageLibGetLightBounds|GetLightBounds|0x004dfb40|004dfb40|LightObjImageLib" tools\leaser\Agents\Agent-B001\research\executed tools\leaser\Agents\Agent-B002\research\executed tools\leaser\Agents\Agent-B003\research\executed
```

## Removed Block R002

- Original source lines: `373-380`
- Original language: `powershell`
- Block SHA256: `44732D2243BCF5B07B90C206F2E2FBC77ABC391DEE44912289880524EBAD2931`

```powershell
python source-3\project-documentation\tools\validator.py --mode file --file source-3\project-documentation\by-memory\0x004dfb40-0x004dfbb0.LightObjImageLibGetLightBounds.md --apply
python source-3\project-documentation\tools\validator.py --mode file --file source-3\project-documentation\by-memory\0x004df7e0-0x004dfd0a.LightObjImageLibLocalMethodCluster.md --apply
python source-3\project-documentation\tools\validator.py --mode file --file source-3\project-documentation\by-class\LightObjImageLib.md --apply
python source-3\project-documentation\tools\validator.py --mode file --file source-3\project-documentation\by-file\LightObjImageLib.md --apply
python source-3\project-documentation\tools\validator.py --mode file --file source-3\project-documentation\by-type\by-struct\LightObjImageLibLayout.md --apply
python source-3\project-documentation\tools\validator.py --mode autogen --apply
```
