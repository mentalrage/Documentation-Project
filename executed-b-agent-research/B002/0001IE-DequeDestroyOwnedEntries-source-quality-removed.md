<!-- REMOVED-MATERIAL-ARCHIVE -->
# Removed Material Archive

- Status: Non-authoritative archival material only.
- Source report: `E:\NTK\GhidraBridge\source-3\project-documentation\executed-b-agent-research\B002\0001IE-DequeDestroyOwnedEntries-source-quality.md`
- Safety: This file must never be executed, replayed, or used as an operational runbook.
- Credit: This archive provides no gate, score, coverage, IDA, validator, or lifecycle credit.

# Removed Executable Code Archive

- Source report: [0001IE-DequeDestroyOwnedEntries-source-quality.md](0001IE-DequeDestroyOwnedEntries-source-quality.md)
- Source report SHA256 before cleanup: `A13D8038057EF0EC8AFAB250EEF68C0505B0494B3DD521EA265A5441F077AD63`
- Cleanup generated: `2026-08-11T12:47:01Z`
- Removed executable blocks: `7`
- Scope: exact executable or command-shaped fenced blocks removed from the source report by supervisor housekeeping.
- Authority: this file is not a B-agent research report and grants no Gate 1, Gate 2, IDA, validator, score, or lifecycle credit.
- Safety: do not execute, import, evaluate, or use any block in this archive as an operational instruction.

## Removed Block R001

- Original source lines: `420-422`
- Original language: `powershell`
- Block SHA256: `90D4522BEFAB8E30CBB29722249CB1ED74760653F4BE4EF81D1BDC693821E6EA`

```powershell
python .\tools\validator.py --mode file --file by-memory/0x0057b9e0-0x0057baa3.DequeDestroyOwnedEntries.md --apply --queue-timeout 240
```

## Removed Block R002

- Original source lines: `437-439`
- Original language: `powershell`
- Block SHA256: `F78D510123F884E69889B7631265BB0B9D89F2C8F221BA1FB5D6B4F926C72D9A`

```powershell
python .\tools\validator.py --mode file --file by-class/Deque.md --apply --queue-timeout 240
```

## Removed Block R003

- Original source lines: `453-455`
- Original language: `powershell`
- Block SHA256: `8A4F63B6D027CFEFE308C179899542557D4235DFFBEAA9467A57AF60FAD62371`

```powershell
python .\tools\validator.py --mode file --file by-file/Deque.md --apply --queue-timeout 240
```

## Removed Block R004

- Original source lines: `468-470`
- Original language: `powershell`
- Block SHA256: `2F5AC5800FAC25943745A94DBCD63CAE56E455A36F7A5EC81371819B8A7B6A56`

```powershell
python .\tools\validator.py --mode file --file by-type/by-struct/DequeLayout.md --apply --queue-timeout 240
```

## Removed Block R005

- Original source lines: `482-484`
- Original language: `powershell`
- Block SHA256: `22A42AE4FDEDCBAB17E64C72245C27A41179BA95CFF92FF85DCFF01A230FCBF9`

```powershell
python .\tools\validator.py --mode file --file by-memory/0x0057a890-0x0057afcd.SoundManagerMusicDirectoryScan.md --apply --queue-timeout 240
```

## Removed Block R006

- Original source lines: `496-498`
- Original language: `powershell`
- Block SHA256: `56074E5C488B6F460B7EE9FE322FDE56643CA5EAC44B02CDEB861A199FEE1FAF`

```powershell
python .\tools\validator.py --mode file --file by-memory/0x0057b860-0x0057bf6e.SoundPathVector.md --apply --queue-timeout 240
```

## Removed Block R007

- Original source lines: `508-510`
- Original language: `powershell`
- Block SHA256: `DE57201B15832A1E689CF74F873D9A18A78B0A5FE171F30DC6F916191B5FED39`

```powershell
python .\tools\validator.py --mode file --file by-memory/0x005797b0-0x0057bf6e.SoundManagerAudioHelperCluster.md --apply --queue-timeout 240
```
