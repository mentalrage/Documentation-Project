<!-- REMOVED-MATERIAL-ARCHIVE -->
# Removed Material Archive

- Status: Non-authoritative archival material only.
- Source report: `E:\NTK\GhidraBridge\source-3\project-documentation\executed-b-agent-research\B012\00022Q-IconsPaneActionDispatchRawBody-source-quality.md`
- Safety: This file must never be executed, replayed, or used as an operational runbook.
- Credit: This archive provides no gate, score, coverage, IDA, validator, or lifecycle credit.

# Removed Executable Code Archive

- Source report: [00022Q-IconsPaneActionDispatchRawBody-source-quality.md](00022Q-IconsPaneActionDispatchRawBody-source-quality.md)
- Source report SHA256 before cleanup: `2E570D017B2A4C67BE5D79662791C22CAB0D276462AA9580DF2C0F56BCEB0428`
- Cleanup generated: `2026-08-11T12:47:17Z`
- Removed executable blocks: `2`
- Scope: exact executable or command-shaped fenced blocks removed from the source report by supervisor housekeeping.
- Authority: this file is not a B-agent research report and grants no Gate 1, Gate 2, IDA, validator, score, or lifecycle credit.
- Safety: do not execute, import, evaluate, or use any block in this archive as an operational instruction.

## Removed Block R001

- Original source lines: `332-337`
- Original language: `powershell`
- Block SHA256: `6BF9329E75C05AF1F8EA2E92DD8BD9B8C1980D3BDDE2D729830FFBCA217A6D17`

```powershell
python .\tools\validator.py --mode file --file by-memory\0x004cf8e0-0x004cf974.IconsPaneActionDispatchRawBody.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-memory\0x004cf1f0-0x004cf8d5.IconsPaneCore.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-file\IconsPane.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-class\IconsPane.md --apply --queue-timeout 240
```

## Removed Block R002

- Original source lines: `341-343`
- Original language: `powershell`
- Block SHA256: `0E0D36409549E3C407069069D2A839285B7A56F1D8C7F91C3A48999A006D4DB5`

```powershell
python .\tools\validator.py --mode file --file by-file\TabPane.md --apply --queue-timeout 240
```
