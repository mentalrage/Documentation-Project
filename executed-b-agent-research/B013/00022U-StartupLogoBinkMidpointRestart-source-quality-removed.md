<!-- REMOVED-MATERIAL-ARCHIVE -->
# Removed Material Archive

- Status: Non-authoritative archival material only.
- Source report: `E:\NTK\GhidraBridge\source-3\project-documentation\executed-b-agent-research\B013\00022U-StartupLogoBinkMidpointRestart-source-quality.md`
- Safety: This file must never be executed, replayed, or used as an operational runbook.
- Credit: This archive provides no gate, score, coverage, IDA, validator, or lifecycle credit.

# Removed Executable Code Archive

- Source report: [00022U-StartupLogoBinkMidpointRestart-source-quality.md](00022U-StartupLogoBinkMidpointRestart-source-quality.md)
- Source report SHA256 before cleanup: `AA796A853FB67CEFD0B6259BE1BDA325A210AF1A040F3473C9D50305CFA33268`
- Cleanup generated: `2026-08-11T12:47:17Z`
- Removed executable blocks: `3`
- Scope: exact executable or command-shaped fenced blocks removed from the source report by supervisor housekeeping.
- Authority: this file is not a B-agent research report and grants no Gate 1, Gate 2, IDA, validator, score, or lifecycle credit.
- Safety: do not execute, import, evaluate, or use any block in this archive as an operational instruction.

## Removed Block R001

- Original source lines: `383-393`
- Original language: `powershell`
- Block SHA256: `8C12F2C96DFED57BC27590A6C7D1251CD6820CD4AAFA2B7FE46D77E0E571CE0A`

```powershell
python .\tools\validator.py --mode file --file by-memory\0x004f5ae0-0x004f5b1e.TryAdvanceStartupLogoBinkSegment.md --apply --queue-timeout 240 --wait-generated
python .\tools\validator.py --mode file --file by-file\StartupLogoPanes.md --apply --queue-timeout 240 --wait-generated
python .\tools\validator.py --mode file --file by-memory\0x004f59d0-0x004f5ac7.StartupLogoBinkWndProc.md --apply --queue-timeout 240 --wait-generated
python .\tools\validator.py --mode file --file by-memory\0x004f5710-0x004f59c6.PlayStartupLogoBinkFile.md --apply --queue-timeout 240 --wait-generated
python .\tools\validator.py --mode file --file by-memory\0x004f5710-0x004f5ac7.StartupLogoBinkPlaybackLoop.md --apply --queue-timeout 240 --wait-generated
python .\tools\validator.py --mode file --file by-memory\0x0069b45c-0x0069b480.StartupLogoBinkPlaybackGlobals.md --apply --queue-timeout 240 --wait-generated
python .\tools\validator.py --mode file --file by-global\StartupLogoBinkRestartFlag.md --apply --queue-timeout 240 --wait-generated
python .\tools\validator.py --mode file --file by-memory\0x0066db42-0x0066db44.StartupLogoBinkRestartFlag.md --apply --queue-timeout 240 --wait-generated
python .\tools\validator.py --mode file --file by-resource\startup-logo-media.md --apply --queue-timeout 240 --wait-generated
```

## Removed Block R002

- Original source lines: `397-399`
- Original language: `powershell`
- Block SHA256: `E929E218EF962F69A6C47E93AC1F3377DFCC7F04B07CB50D7964DD560C6199E2`

```powershell
python .\tools\validator.py --mode autogen --apply --queue-timeout 240 --wait-generated
```

## Removed Block R003

- Original source lines: `403-405`
- Original language: `powershell`
- Block SHA256: `5DDBB512296E38317E3F695CDD41E90036DF6B549122E1E3C4E933A967FDF9CC`

```powershell
python .\tools\validator.py execute_report B013 00022U-StartupLogoBinkMidpointRestart-source-quality.md 00022U --apply
```
