<!-- REMOVED-MATERIAL-ARCHIVE -->
# Removed Material Archive

- Status: Non-authoritative archival material only.
- Source report: `E:\NTK\GhidraBridge\source-3\project-documentation\executed-b-agent-research\B005\0002XR-g_objectNationMap-source-quality.md`
- Safety: This file must never be executed, replayed, or used as an operational runbook.
- Credit: This archive provides no gate, score, coverage, IDA, validator, or lifecycle credit.

# Removed Executable Code Archive

- Source report: [0002XR-g_objectNationMap-source-quality.md](0002XR-g_objectNationMap-source-quality.md)
- Source report SHA256 before cleanup: `F7D1448B52AB90E4F84ED425EFC12F718C5B12574E2AF883881544F5BD0A5D09`
- Cleanup generated: `2026-08-11T12:47:09Z`
- Removed executable blocks: `1`
- Scope: exact executable or command-shaped fenced blocks removed from the source report by supervisor housekeeping.
- Authority: this file is not a B-agent research report and grants no Gate 1, Gate 2, IDA, validator, score, or lifecycle credit.
- Safety: do not execute, import, evaluate, or use any block in this archive as an operational instruction.

## Removed Block R001

- Original source lines: `280-296`
- Original language: `powershell`
- Block SHA256: `BEEE101BB9ED8B986DB222F15B79A0042C7042BECD20172B0266214B25C1F18E`

```powershell
python .\tools\validator.py --mode file --file by-memory\0x0069b4c0-0x0069b4c4.g_objectNationMap.md --apply --queue-timeout 240
# exit=0, ok: 1
python .\tools\validator.py --mode file --file by-global\g_objectNationMap.md --apply --queue-timeout 240
# exit=0, ok: 1
# final rerun after metadata-shape fix: exit=0, ok: 1, autogen_error_clear 0000Q3, autogen_cpp_update 1
python .\tools\validator.py --mode file --file by-file\MapPane.md --apply --queue-timeout 240
# exit=0, ok: 1
python .\tools\validator.py --mode file --file by-memory\0x005039f0-0x00504521.GameServerNationAndMapInit.md --apply --queue-timeout 240
# exit=0, ok: 1
python .\tools\validator.py --mode file --file by-memory\0x00504110-0x00504521.MapPaneInitialize.md --apply --queue-timeout 240
# exit=0, ok: 1
python .\tools\validator.py --mode file --file by-memory\0x00504530-0x005046c6.MapPaneCleanup.md --apply --queue-timeout 240
# exit=0, ok: 1
python .\tools\validator.py --mode file --file by-memory\0x0069b4b4-0x0069b4c8.MapNameMiniMapAndGameServerGlobals.md --apply --queue-timeout 240
# exit=0, ok: 1
```
