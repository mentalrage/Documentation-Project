<!-- REMOVED-MATERIAL-ARCHIVE -->
# Removed Material Archive

- Status: Non-authoritative archival material only.
- Source report: `E:\NTK\GhidraBridge\source-3\project-documentation\executed-b-agent-research\B001\00015A-0002HP-fontimagelib-source-quality.md`
- Safety: This file must never be executed, replayed, or used as an operational runbook.
- Credit: This archive provides no gate, score, coverage, IDA, validator, or lifecycle credit.

# Removed Executable Code Archive

- Source report: [00015A-0002HP-fontimagelib-source-quality.md](00015A-0002HP-fontimagelib-source-quality.md)
- Source report SHA256 before cleanup: `AE9D45FC132B37A1642CAD34B86D04330E6F853F27D7198B2CFDAFCEE011F972`
- Cleanup generated: `2026-08-11T12:46:56Z`
- Removed executable blocks: `1`
- Scope: exact executable or command-shaped fenced blocks removed from the source report by supervisor housekeeping.
- Authority: this file is not a B-agent research report and grants no Gate 1, Gate 2, IDA, validator, score, or lifecycle credit.
- Safety: do not execute, import, evaluate, or use any block in this archive as an operational instruction.

## Removed Block R001

- Original source lines: `304-309`
- Original language: `powershell`
- Block SHA256: `41A93A33006799697605C08E9170D54D08A100518D4DEE97D0948C82B83B8F22`

```powershell
python project-documentation/tools/validator.py --mode file --file project-documentation/by-memory/0x004b5f00-0x004b6409.FontImageLib.md --queue-timeout 180
python project-documentation/tools/validator.py --mode file --file project-documentation/by-memory/0x004b5f00-0x004b5f54.FontImageLibConstructor.md --queue-timeout 180
python project-documentation/tools/validator.py --mode file --file project-documentation/by-memory/0x004b60b0-0x004b60bd.IsLegacyAssetMode.md --queue-timeout 180
python project-documentation/tools/validator.py --mode autogen --queue-timeout 180
```
