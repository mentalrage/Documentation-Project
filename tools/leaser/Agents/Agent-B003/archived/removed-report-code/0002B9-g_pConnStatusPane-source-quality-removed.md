<!-- REMOVED-MATERIAL-ARCHIVE -->
# Removed Material Archive

- Status: Non-authoritative archival material only.
- Source report: `E:\NTK\GhidraBridge\source-3\project-documentation\executed-b-agent-research\B003\0002B9-g_pConnStatusPane-source-quality.md`
- Safety: This file must never be executed, replayed, or used as an operational runbook.
- Credit: This archive provides no gate, score, coverage, IDA, validator, or lifecycle credit.

# Removed Executable Code Archive

- Source report: [0002B9-g_pConnStatusPane-source-quality.md](0002B9-g_pConnStatusPane-source-quality.md)
- Source report SHA256 before cleanup: `BB22B1BEECEA7947D45408F93430252342704F7C0086C57044D3EA144B82C47A`
- Cleanup generated: `2026-08-11T12:47:04Z`
- Removed executable blocks: `4`
- Scope: exact executable or command-shaped fenced blocks removed from the source report by supervisor housekeeping.
- Authority: this file is not a B-agent research report and grants no Gate 1, Gate 2, IDA, validator, score, or lifecycle credit.
- Safety: do not execute, import, evaluate, or use any block in this archive as an operational instruction.

## Removed Block R001

- Original source lines: `254-256`
- Original language: `powershell`
- Block SHA256: `71E0F4A8C3A06A67B0CCD6F1EA84C44D651565E908E98724E74A5B11B3B6BF92`

```powershell
python .\tools\validator.py --mode file --file by-memory/0x0069adf4-0x0069adf8.g_pConnStatusPane.md --apply --queue-timeout 240
```

## Removed Block R002

- Original source lines: `267-269`
- Original language: `powershell`
- Block SHA256: `87064E1DBD2E5A69BED99C6C009F549C3EC225234E8971960FFDB1246CD709EA`

```powershell
python .\tools\validator.py --mode file --file by-file/ConnStatusPane.md --apply --queue-timeout 240
```

## Removed Block R003

- Original source lines: `276-278`
- Original language: `powershell`
- Block SHA256: `9D4B4CF833A90FB68C12DD58A319233834B0D2E885A4E250D2A7F2CBAF2B7CB8`

```powershell
python .\tools\validator.py --mode file --file by-memory/0x00494520-0x004949df.ConnStatusPane.md --apply --queue-timeout 240
```

## Removed Block R004

- Original source lines: `383-387`
- Original language: `powershell`
- Block SHA256: `854E73B58EA5FD16364D38988D9BFA51004AAB01CBECCF815562D94B6B96758E`

```powershell
python .\tools\validator.py --mode file --file by-memory/0x0069adf4-0x0069adf8.g_pConnStatusPane.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-file/ConnStatusPane.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-memory/0x00494520-0x004949df.ConnStatusPane.md --apply --queue-timeout 240
```
