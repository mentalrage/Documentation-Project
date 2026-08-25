<!-- REMOVED-MATERIAL-ARCHIVE -->
# Removed Material Archive

- Status: Non-authoritative archival material only.
- Source report: `E:\NTK\GhidraBridge\source-3\project-documentation\executed-b-agent-research\B001\0001AK-mapnamepane-source-quality.md`
- Safety: This file must never be executed, replayed, or used as an operational runbook.
- Credit: This archive provides no gate, score, coverage, IDA, validator, or lifecycle credit.

# Removed Executable Code Archive

- Source report: [0001AK-mapnamepane-source-quality.md](0001AK-mapnamepane-source-quality.md)
- Source report SHA256 before cleanup: `3D17AC0C8CEF7C151C985185166E2FD85981C7CEFBF918BD9E4A426593D7DF24`
- Cleanup generated: `2026-08-11T12:46:57Z`
- Removed executable blocks: `1`
- Scope: exact executable or command-shaped fenced blocks removed from the source report by supervisor housekeeping.
- Authority: this file is not a B-agent research report and grants no Gate 1, Gate 2, IDA, validator, score, or lifecycle credit.
- Safety: do not execute, import, evaluate, or use any block in this archive as an operational instruction.

## Removed Block R001

- Original source lines: `409-416`
- Original language: `powershell`
- Block SHA256: `94D040383FC3BE5346DE733092FA81B28FA942B56EE3CBF38CC9C3C960B1BC70`

```powershell
python E:\NTK\GhidraBridge\source-3\project-documentation\tools\validator.py --mode file --file E:\NTK\GhidraBridge\source-3\project-documentation\by-memory\0x005031f0-0x005038fd.MapNamePane.md --apply --queue-timeout 240 --lock-timeout -1
python E:\NTK\GhidraBridge\source-3\project-documentation\tools\validator.py --mode file --file E:\NTK\GhidraBridge\source-3\project-documentation\by-class\MapNamePane.md --apply --queue-timeout 240 --lock-timeout -1
python E:\NTK\GhidraBridge\source-3\project-documentation\tools\validator.py --mode file --file E:\NTK\GhidraBridge\source-3\project-documentation\by-file\MapNamePane.md --apply --queue-timeout 240 --lock-timeout -1
python E:\NTK\GhidraBridge\source-3\project-documentation\tools\validator.py --mode file --file E:\NTK\GhidraBridge\source-3\project-documentation\by-memory\-coverage-report.md --apply --queue-timeout 240 --lock-timeout -1
python E:\NTK\GhidraBridge\source-3\project-documentation\tools\memory_ranges.py report
python E:\NTK\GhidraBridge\source-3\project-documentation\tools\validator.py --mode rescore --apply --queue-timeout 240 --lock-timeout -1
```
