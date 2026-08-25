<!-- REMOVED-MATERIAL-ARCHIVE -->
# Removed Material Archive

- Status: Non-authoritative archival material only.
- Source report: `E:\NTK\GhidraBridge\source-3\project-documentation\executed-b-agent-research\B006\00018I-InterfaceEfxMgrSingletonAndThunks-source-quality.md`
- Safety: This file must never be executed, replayed, or used as an operational runbook.
- Credit: This archive provides no gate, score, coverage, IDA, validator, or lifecycle credit.

# Removed Executable Code Archive

- Source report: [00018I-InterfaceEfxMgrSingletonAndThunks-source-quality.md](00018I-InterfaceEfxMgrSingletonAndThunks-source-quality.md)
- Source report SHA256 before cleanup: `38A535B75856BE3338DD1B76E042750D26AB49E70184AA0DBE961CC154FC80AC`
- Cleanup generated: `2026-08-11T12:47:10Z`
- Removed executable blocks: `1`
- Scope: exact executable or command-shaped fenced blocks removed from the source report by supervisor housekeeping.
- Authority: this file is not a B-agent research report and grants no Gate 1, Gate 2, IDA, validator, score, or lifecycle credit.
- Safety: do not execute, import, evaluate, or use any block in this archive as an operational instruction.

## Removed Block R001

- Original source lines: `284-292`
- Original language: `powershell`
- Block SHA256: `090BDA831BEC4E2CBC6E2CEE2CEC92A34233D9AF6B5A8EFA9B7BBC6DC7F2F935`

```powershell
python source-3/project-documentation/tools/validator.py --mode file --file by-memory\0x004ea060-0x004ea081.InterfaceEfxMgrSingletonAndThunks.md --apply --queue-timeout 240
python source-3/project-documentation/tools/validator.py --mode file --file by-class\InterfaceEfxMgr.md --apply --queue-timeout 240
python source-3/project-documentation/tools/validator.py --mode file --file by-file\InterfaceEfx.md --apply --queue-timeout 240
python source-3/project-documentation/tools/validator.py --mode file --file by-memory\0x004e97b0-0x004ea121.InterfaceEfxAndMgr.md --apply --queue-timeout 240
python source-3/project-documentation/tools/validator.py --mode file --file by-global\g_pInterfaceEfxMgr.md --apply --queue-timeout 240
python source-3/project-documentation/tools/validator.py --mode file --file by-memory\0x0069b360-0x0069b364.g_pInterfaceEfxMgrStorage.md --apply --queue-timeout 240
python source-3/project-documentation/tools/validator.py --mode autogen --apply --queue-timeout 240
```
