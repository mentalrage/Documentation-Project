<!-- REMOVED-MATERIAL-ARCHIVE -->
# Removed Material Archive

- Status: Non-authoritative archival material only.
- Source report: `E:\NTK\GhidraBridge\source-3\project-documentation\executed-b-agent-research\B011\0000L0-MainMenuPane-empty-emitter-family-source-quality.md`
- Safety: This file must never be executed, replayed, or used as an operational runbook.
- Credit: This archive provides no gate, score, coverage, IDA, validator, or lifecycle credit.

# Removed Executable Code Archive

- Source report: [0000L0-MainMenuPane-empty-emitter-family-source-quality.md](0000L0-MainMenuPane-empty-emitter-family-source-quality.md)
- Source report SHA256 before cleanup: `9E4F94B860A6339ABA0CEC2321DA5A36C443E62969F6E59746A0AAA0D951D35C`
- Cleanup generated: `2026-08-11T12:47:16Z`
- Removed executable blocks: `1`
- Scope: exact executable or command-shaped fenced blocks removed from the source report by supervisor housekeeping.
- Authority: this file is not a B-agent research report and grants no Gate 1, Gate 2, IDA, validator, score, or lifecycle credit.
- Safety: do not execute, import, evaluate, or use any block in this archive as an operational instruction.

## Removed Block R001

- Original source lines: `212-227`
- Original language: `powershell`
- Block SHA256: `09DC3EF0A127BC20243EC4C7E5E87D8BCE166298A7D6DB0A25FB1C82D35C7E1A`

```powershell
python .\tools\validator.py --mode file --file by-memory\0x004f8fa0-0x004f9055.OpenCreateUserDialog.md --apply --queue-timeout 240 --wait-generated
python .\tools\validator.py --mode file --file by-memory\0x004f91c0-0x004f927d.OpenTerminalPane.md --apply --queue-timeout 240 --wait-generated
python .\tools\validator.py --mode file --file by-class\MainMenuPane.md --apply --queue-timeout 240 --wait-generated
python .\tools\validator.py --mode file --file by-global\CloseMainMenuDialogSingletons_4F69A0.md --apply --queue-timeout 240 --wait-generated
python .\tools\validator.py --mode file --file by-global\ComputeMenuItemRect_4F8B90.md --apply --queue-timeout 240 --wait-generated
python .\tools\validator.py --mode file --file by-global\HandleLegacyMainMenuPacket_4F8D00.md --apply --queue-timeout 240 --wait-generated
python .\tools\validator.py --mode file --file by-global\HitTestMenuItem_4F8C10.md --apply --queue-timeout 240 --wait-generated
python .\tools\validator.py --mode file --file by-global\OpenChangePasswordDialog_4F9060.md --apply --queue-timeout 240 --wait-generated
python .\tools\validator.py --mode file --file by-global\OpenCreateUserDialog_4F8FA0.md --apply --queue-timeout 240 --wait-generated
python .\tools\validator.py --mode file --file by-global\OpenHistoryViewingPane_4F9140.md --apply --queue-timeout 240 --wait-generated
python .\tools\validator.py --mode file --file by-global\OpenStoryViewingPane_4F90C0.md --apply --queue-timeout 240 --wait-generated
python .\tools\validator.py --mode file --file by-global\OpenTerminalPane_4F91C0.md --apply --queue-timeout 240 --wait-generated
python .\tools\validator.py --mode file --file by-file\MainMenuPane.md --apply --queue-timeout 240 --wait-generated
python .\tools\validator.py --mode file --file by-memory\0x004f6700-0x004fb62a.MainMenuLoginAndAccountDialogs.md --apply --queue-timeout 240 --wait-generated
```
