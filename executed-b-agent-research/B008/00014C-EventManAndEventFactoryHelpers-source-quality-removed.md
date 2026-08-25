<!-- REMOVED-MATERIAL-ARCHIVE -->
# Removed Material Archive

- Status: Non-authoritative archival material only.
- Source report: `E:\NTK\GhidraBridge\source-3\project-documentation\executed-b-agent-research\B008\00014C-EventManAndEventFactoryHelpers-source-quality.md`
- Safety: This file must never be executed, replayed, or used as an operational runbook.
- Credit: This archive provides no gate, score, coverage, IDA, validator, or lifecycle credit.

# Removed Executable Code Archive

- Source report: [00014C-EventManAndEventFactoryHelpers-source-quality.md](00014C-EventManAndEventFactoryHelpers-source-quality.md)
- Source report SHA256 before cleanup: `3393B6D2A49E38C7AECA93E9BF829BEE90F239580994A2E009535CC68384C821`
- Cleanup generated: `2026-08-11T12:47:13Z`
- Removed executable blocks: `1`
- Scope: exact executable or command-shaped fenced blocks removed from the source report by supervisor housekeeping.
- Authority: this file is not a B-agent research report and grants no Gate 1, Gate 2, IDA, validator, score, or lifecycle credit.
- Safety: do not execute, import, evaluate, or use any block in this archive as an operational instruction.

## Removed Block R001

- Original source lines: `579-595`
- Original language: `powershell`
- Block SHA256: `71DCD9166C5A59F71E8BD08CE0D82C842FE4EAC0B971F659147930C014F6E8EF`

```powershell
python .\tools\validator.py --mode file --file by-memory\0x004a8ac0-0x004ab3eb.EventManAndEventFactoryHelpers.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-file\Event.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-class\EventMan.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-class\Event.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-memory\0x004a6a80-0x004a82a9.EventDispatcher.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-file\EventDispatcher.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-file\InputMan.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-memory\0x004e8af0-0x004e970d.InputMan.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-memory\0x004e7930-0x004e7b6c.IMECandidateShowCandidateList.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-memory\0x004f55d0-0x004f561d.LogoPlayerPaneInputSkipHandlers.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-memory\0x0067a754-0x0067a758.g_pEventMan.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-memory\0x006196b0-0x006196bc.EventManVtableData.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-memory\0x0066d888-0x0066da88.EventManKeyTranslationTables.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-memory\0x00574ae0-0x00574b83.SocketEventDispatchHelpers.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-memory\0x004f6490-0x004f66a5.ApplicationShutdown.md --apply --queue-timeout 240
```
