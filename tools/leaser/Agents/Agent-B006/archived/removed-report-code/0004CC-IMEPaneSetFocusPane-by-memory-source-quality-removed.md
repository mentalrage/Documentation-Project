<!-- REMOVED-MATERIAL-ARCHIVE -->
# Removed Material Archive

- Status: Non-authoritative archival material only.
- Source report: `E:\NTK\GhidraBridge\source-3\project-documentation\executed-b-agent-research\B006\0004CC-IMEPaneSetFocusPane-by-memory-source-quality.md`
- Safety: This file must never be executed, replayed, or used as an operational runbook.
- Credit: This archive provides no gate, score, coverage, IDA, validator, or lifecycle credit.

# Removed Executable Code Archive

- Source report: [0004CC-IMEPaneSetFocusPane-by-memory-source-quality.md](0004CC-IMEPaneSetFocusPane-by-memory-source-quality.md)
- Source report SHA256 before cleanup: `44D9D79ACD9C7143F55465428B653C13623DF4DBBB4ED128C14169CD19B143EC`
- Cleanup generated: `2026-08-11T12:47:11Z`
- Removed executable blocks: `5`
- Scope: exact executable or command-shaped fenced blocks removed from the source report by supervisor housekeeping.
- Authority: this file is not a B-agent research report and grants no Gate 1, Gate 2, IDA, validator, score, or lifecycle credit.
- Safety: do not execute, import, evaluate, or use any block in this archive as an operational instruction.

## Removed Block R001

- Original source lines: `191-193`
- Original language: `powershell`
- Block SHA256: `BA70CB98FE3FD1C9E8816C995B2B1263CC79A508FFF1163C2E782BF0875D329A`

```powershell
python .\tools\validator.py --mode file --file by-memory/0x004e80a0-0x004e810b.IMEPaneSetFocusPane.md --apply --queue-timeout 240 --wait-generated
```

## Removed Block R002

- Original source lines: `198-200`
- Original language: `powershell`
- Block SHA256: `5852690E5F8E3B7D21320079E5E9397B4C8D37EAEE700420BDA698A16505EFBB`

```powershell
python .\tools\validator.py --mode file --file by-class/IMEPane.md --apply --queue-timeout 240
```

## Removed Block R003

- Original source lines: `204-206`
- Original language: `powershell`
- Block SHA256: `7F16D2747D839E05E346F7F037E895F6AB0C7F05BAC0283B4066AD7416AD7419`

```powershell
python .\tools\validator.py --mode file --file by-file/IMEPanes.md --apply --queue-timeout 240
```

## Removed Block R004

- Original source lines: `210-212`
- Original language: `powershell`
- Block SHA256: `5786C71AFE9CD7EDA75545F88BCFA6A314A8230DDA6716586C78426A81E8C9A1`

```powershell
python .\tools\validator.py --mode file --file by-memory/0x004e70f0-0x004e8433.IMEPaneFamily.md --apply --queue-timeout 240
```

## Removed Block R005

- Original source lines: `216-218`
- Original language: `powershell`
- Block SHA256: `43CB059F6233E538E7D92000013097F781ADEEED6A400A458D43DBDFD020795E`

```powershell
python .\tools\validator.py --mode file --file by-file/IMEPanes.md --apply --queue-timeout 240 --wait-generated
```
