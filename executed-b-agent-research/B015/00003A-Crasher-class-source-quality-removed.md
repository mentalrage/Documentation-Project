<!-- REMOVED-MATERIAL-ARCHIVE -->
# Removed Material Archive

- Status: Non-authoritative archival material only.
- Source report: `E:\NTK\GhidraBridge\source-3\project-documentation\executed-b-agent-research\B015\00003A-Crasher-class-source-quality.md`
- Safety: This file must never be executed, replayed, or used as an operational runbook.
- Credit: This archive provides no gate, score, coverage, IDA, validator, or lifecycle credit.

# Removed Executable Code Archive

- Source report: [00003A-Crasher-class-source-quality.md](00003A-Crasher-class-source-quality.md)
- Source report SHA256 before cleanup: `B80D7D407BC8A6118D8925FC124D02271BF0B0596E241931810F7C0C00E22F71`
- Cleanup generated: `2026-08-11T12:47:18Z`
- Removed executable blocks: `1`
- Scope: exact executable or command-shaped fenced blocks removed from the source report by supervisor housekeeping.
- Authority: this file is not a B-agent research report and grants no Gate 1, Gate 2, IDA, validator, score, or lifecycle credit.
- Safety: do not execute, import, evaluate, or use any block in this archive as an operational instruction.

## Removed Block R001

- Original source lines: `367-376`
- Original language: `powershell`
- Block SHA256: `2A1FC9E8B6EC9149EC0AA0FB30A6178B9BA22ACC06D1572275A59583BAD3CCB7`

```powershell
python .\tools\validator.py --mode file --file by-class/Crasher.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-memory/0x0049bae0-0x0049bbef.Crasher.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-file/Crasher.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-global/g_pCrasher.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-global/g_pCrashTarget.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-memory/0x00618858-0x006188e0.CrasherVtableData.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-meta/client_crash_diagnostics.md --apply --queue-timeout 240
python .\tools\validator.py --mode autogen --apply --queue-timeout 240
```
