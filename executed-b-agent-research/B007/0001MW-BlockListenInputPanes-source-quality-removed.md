<!-- REMOVED-MATERIAL-ARCHIVE -->
# Removed Material Archive

- Status: Non-authoritative archival material only.
- Source report: `E:\NTK\GhidraBridge\source-3\project-documentation\executed-b-agent-research\B007\0001MW-BlockListenInputPanes-source-quality.md`
- Safety: This file must never be executed, replayed, or used as an operational runbook.
- Credit: This archive provides no gate, score, coverage, IDA, validator, or lifecycle credit.

# Removed Executable Code Archive

- Source report: [0001MW-BlockListenInputPanes-source-quality.md](0001MW-BlockListenInputPanes-source-quality.md)
- Source report SHA256 before cleanup: `4C6D8C841D40DCC8C6BFBC9FA40C0201B3727B8B93E79D4FC98FC03A09EE4F0A`
- Cleanup generated: `2026-08-11T12:47:12Z`
- Removed executable blocks: `3`
- Scope: exact executable or command-shaped fenced blocks removed from the source report by supervisor housekeeping.
- Authority: this file is not a B-agent research report and grants no Gate 1, Gate 2, IDA, validator, score, or lifecycle credit.
- Safety: do not execute, import, evaluate, or use any block in this archive as an operational instruction.

## Removed Block R001

- Original source lines: `498-500`
- Original language: `powershell`
- Block SHA256: `6A56EE35CFEAFCEE5D57E8205C27F64074B4D718D2848F34DADEC7AF30D59A89`

```powershell
python .\tools\validator.py --mode file --file by-memory\0x005b68c0-0x005b7354.BlockListenInputPanes.md --apply --queue-timeout 240
```

## Removed Block R002

- Original source lines: `510-512`
- Original language: `powershell`
- Block SHA256: `ED33D19C9C6782B0A171F88AD773AF2D9EEF622EAE5210BEE3BCC235E952BD7B`

```powershell
python .\tools\validator.py --mode file --file by-file\BlockListenInputPanes.md --apply --queue-timeout 240
```

## Removed Block R003

- Original source lines: `525-527`
- Original language: `powershell`
- Block SHA256: `93F621B7A0DD225196DF0CF325FB528E3F2106827FFF09D60B43A9ED04CEDF08`

```powershell
python .\tools\validator.py --queue-status
```
