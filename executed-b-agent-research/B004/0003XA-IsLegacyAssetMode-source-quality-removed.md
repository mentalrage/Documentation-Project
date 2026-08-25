<!-- REMOVED-MATERIAL-ARCHIVE -->
# Removed Material Archive

- Status: Non-authoritative archival material only.
- Source report: `E:\NTK\GhidraBridge\source-3\project-documentation\executed-b-agent-research\B004\0003XA-IsLegacyAssetMode-source-quality.md`
- Safety: This file must never be executed, replayed, or used as an operational runbook.
- Credit: This archive provides no gate, score, coverage, IDA, validator, or lifecycle credit.

# Removed Executable Code Archive

- Source report: [0003XA-IsLegacyAssetMode-source-quality.md](0003XA-IsLegacyAssetMode-source-quality.md)
- Source report SHA256 before cleanup: `5ECCFAD056036EB15DB1B289B7A56A3A1321D28BBDF0E17B235764174D6D8646`
- Cleanup generated: `2026-08-11T12:47:08Z`
- Removed executable blocks: `1`
- Scope: exact executable or command-shaped fenced blocks removed from the source report by supervisor housekeeping.
- Authority: this file is not a B-agent research report and grants no Gate 1, Gate 2, IDA, validator, score, or lifecycle credit.
- Safety: do not execute, import, evaluate, or use any block in this archive as an operational instruction.

## Removed Block R001

- Original source lines: `586-592`
- Original language: `powershell`
- Block SHA256: `A4B7D1D3496C7D8C948A8E5CF6760D6736AAA48E09061262AD1685B86CCCB3F6`

```powershell
python .\tools\validator.py --mode file --file by-memory/0x004b60b0-0x004b60bd.IsLegacyAssetMode.md --apply --queue-timeout 240 --no-generated-refresh
python .\tools\validator.py --mode file --file by-global/g_useEpfAssets.md --apply --queue-timeout 240 --no-generated-refresh
python .\tools\validator.py --mode file --file by-memory/0x0066da97-0x0066da98.g_useEpfAssets.md --apply --queue-timeout 240 --no-generated-refresh
python .\tools\validator.py --mode file --file by-file/StartupWindow.md --apply --queue-timeout 240 --no-generated-refresh
python .\tools\validator.py --mode file --file by-memory/0x004b5f00-0x004b6409.FontImageLib.md --apply --queue-timeout 240 --no-generated-refresh
```
