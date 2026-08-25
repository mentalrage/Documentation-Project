<!-- REMOVED-MATERIAL-ARCHIVE -->
# Removed Material Archive

- Status: Non-authoritative archival material only.
- Source report: `E:\NTK\GhidraBridge\source-3\project-documentation\executed-b-agent-research\B002\0002I1-0002I3-0002I4-0002I6-MapPaneEffectListHelperFamily-source-quality.md`
- Safety: This file must never be executed, replayed, or used as an operational runbook.
- Credit: This archive provides no gate, score, coverage, IDA, validator, or lifecycle credit.

# Removed Executable Code Archive

- Source report: [0002I1-0002I3-0002I4-0002I6-MapPaneEffectListHelperFamily-source-quality.md](0002I1-0002I3-0002I4-0002I6-MapPaneEffectListHelperFamily-source-quality.md)
- Source report SHA256 before cleanup: `543A21226F55962DB94569E5276D1B42F6F50DD3659420136DF71D614A01876D`
- Cleanup generated: `2026-08-11T12:47:02Z`
- Removed executable blocks: `2`
- Scope: exact executable or command-shaped fenced blocks removed from the source report by supervisor housekeeping.
- Authority: this file is not a B-agent research report and grants no Gate 1, Gate 2, IDA, validator, score, or lifecycle credit.
- Safety: do not execute, import, evaluate, or use any block in this archive as an operational instruction.

## Removed Block R001

- Original source lines: `470-479`
- Original language: `powershell`
- Block SHA256: `9A7C6E9151375D6E55BED1F24359234699477AF8F5AB7FA5DD19D631EE36CEF7`

```powershell
python .\source-3\project-documentation\tools\validator.py --mode file --file by-memory\0x00503e80-0x00503e8b.MapPaneHasEffectListEntries.md --apply --queue-timeout 240
python .\source-3\project-documentation\tools\validator.py --mode file --file by-memory\0x00503ed0-0x00503eef.MapPaneResetEffectListFields.md --apply --queue-timeout 240
python .\source-3\project-documentation\tools\validator.py --mode file --file by-memory\0x00503ef0-0x0050408d.MapPaneConfigureEffectList.md --apply --queue-timeout 240
python .\source-3\project-documentation\tools\validator.py --mode file --file by-memory\0x005040a0-0x00504102.MapPaneClearEffectList.md --apply --queue-timeout 240
python .\source-3\project-documentation\tools\validator.py --mode file --file by-class\MapPane.md --apply --queue-timeout 240
python .\source-3\project-documentation\tools\validator.py --mode file --file by-file\MapPane.md --apply --queue-timeout 240
python .\source-3\project-documentation\tools\validator.py --mode file --file by-memory\-coverage-report.md --apply --queue-timeout 240
python .\source-3\project-documentation\tools\validator.py --mode autogen --apply --queue-timeout 240
```

## Removed Block R002

- Original source lines: `483-486`
- Original language: `powershell`
- Block SHA256: `0A408AA34B65C8A3D7D789088F751168613A24A949F509054C252A80B9AC3EA6`

```powershell
rg -n "0002I1|0002I3|0002I4|0002I6|MapPaneHasScreenEffecters|MapPaneResetScreenEffecterListFields|MapPaneConfigureScreenEffecterList|MapPaneClearScreenEffecterList" .\source-3\project-documentation\by-memory\-coverage-report.md .\source-3\project-documentation\auto-generated\NexusTK\map\MapPane.cpp
rg -n "below 95|95/95|field names remain open|stored object type remains open|virtual cleanup method name.*unresolved|do not emit C\\+\\+" .\source-3\project-documentation\by-memory\0x00503e80-0x00503e8b.MapPaneHasEffectListEntries.md .\source-3\project-documentation\by-memory\0x00503ed0-0x00503eef.MapPaneResetEffectListFields.md .\source-3\project-documentation\by-memory\0x00503ef0-0x0050408d.MapPaneConfigureEffectList.md .\source-3\project-documentation\by-memory\0x005040a0-0x00504102.MapPaneClearEffectList.md
```
