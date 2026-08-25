<!-- REMOVED-MATERIAL-ARCHIVE -->
# Removed Material Archive

- Status: Non-authoritative archival material only.
- Source report: `E:\NTK\GhidraBridge\source-3\project-documentation\executed-b-agent-research\B008\0000O5-StartupWindow-empty-emitter-family-source-quality.md`
- Safety: This file must never be executed, replayed, or used as an operational runbook.
- Credit: This archive provides no gate, score, coverage, IDA, validator, or lifecycle credit.

# Removed Executable Code Archive

- Source report: [0000O5-StartupWindow-empty-emitter-family-source-quality.md](0000O5-StartupWindow-empty-emitter-family-source-quality.md)
- Source report SHA256 before cleanup: `0F71C41B76F6A83DBB3BEA9A1FA838436406960BAEF9574196DD58B7E2672448`
- Cleanup generated: `2026-08-11T12:47:13Z`
- Removed executable blocks: `1`
- Scope: exact executable or command-shaped fenced blocks removed from the source report by supervisor housekeeping.
- Authority: this file is not a B-agent research report and grants no Gate 1, Gate 2, IDA, validator, score, or lifecycle credit.
- Safety: do not execute, import, evaluate, or use any block in this archive as an operational instruction.

## Removed Block R001

- Original source lines: `872-904`
- Original language: `powershell`
- Block SHA256: `3BB0FFE3C47229F23B5E545048E3DDA42508C7FFF05F6A30FDAFFC29BC728E32`

```powershell
python .\tools\validator.py --mode file --file by-file/StartupWindow.md --apply --queue-timeout 240 --wait-generated
python .\tools\validator.py --mode file --file by-class/StartupWindow.md --apply --queue-timeout 240 --wait-generated
python .\tools\validator.py --mode file --file by-global/g_pStartupWindow.md --apply --queue-timeout 240 --wait-generated
python .\tools\validator.py --mode file --file by-memory/0x0069bac8-0x0069bacc.g_pStartupWindow.md --apply --queue-timeout 240 --wait-generated
python .\tools\validator.py --mode file --file by-global/g_startupWindowClassAtom.md --apply --queue-timeout 240 --wait-generated
python .\tools\validator.py --mode file --file by-memory/0x0069bac4-0x0069bac6.g_startupWindowClassAtom.md --apply --queue-timeout 240 --wait-generated
python .\tools\validator.py --mode file --file by-global/g_useEpfAssets.md --apply --queue-timeout 240 --wait-generated
python .\tools\validator.py --mode file --file by-memory/0x0066da97-0x0066da98.g_useEpfAssets.md --apply --queue-timeout 240 --wait-generated
python .\tools\validator.py --mode file --file by-memory/0x005807d0-0x0058080c.StartupWindowConstructor.md --apply --queue-timeout 240 --wait-generated
python .\tools\validator.py --mode file --file by-memory/0x00580810-0x00580870.StartupWindowOrdinaryDestructor.md --apply --queue-timeout 240 --wait-generated
python .\tools\validator.py --mode file --file by-memory/0x00580870-0x005810fd.StartupWindowRunUpdateCheck.md --apply --queue-timeout 240 --wait-generated
python .\tools\validator.py --mode file --file by-memory/0x00581100-0x005815aa.StartupWindowUpdateCheckWindowProc.md --apply --queue-timeout 240 --wait-generated
python .\tools\validator.py --mode file --file by-memory/0x005815b0-0x0058165a.StartupNoticePostButtonResult.md --apply --queue-timeout 240 --wait-generated
python .\tools\validator.py --mode file --file by-memory/0x00581660-0x00581664.StartupWindowGetInstanceHandle.md --apply --queue-timeout 240 --wait-generated
python .\tools\validator.py --mode file --file by-memory/0x00581670-0x00581724.StartupNoticeResetButtonStates.md --apply --queue-timeout 240 --wait-generated
python .\tools\validator.py --mode file --file by-memory/0x00581730-0x005817a0.StartupNoticeSetButtonState.md --apply --queue-timeout 240 --wait-generated
python .\tools\validator.py --mode file --file by-memory/0x005817a0-0x005817dd.StartupNoticeHitTestButton.md --apply --queue-timeout 240 --wait-generated
python .\tools\validator.py --mode file --file by-memory/0x005817e0-0x00581854.StartupNoticeInvalidateButtons.md --apply --queue-timeout 240 --wait-generated
python .\tools\validator.py --mode file --file by-memory/0x00581860-0x005818c3.StartupNoticeInvalidateButton.md --apply --queue-timeout 240 --wait-generated
python .\tools\validator.py --mode file --file by-memory/0x005818d0-0x005819cc.StartupNoticeLoadAssets.md --apply --queue-timeout 240 --wait-generated
python .\tools\validator.py --mode file --file by-memory/0x005819d0-0x00581b75.StartupNoticeCreateWindowRaw.md --apply --queue-timeout 240 --wait-generated
python .\tools\validator.py --mode file --file by-memory/0x00581cf0-0x00581d30.StartupAnsiRangeToWideString.md --apply --queue-timeout 240 --wait-generated
python .\tools\validator.py --mode file --file by-memory/0x00581d30-0x00581db2.StartupWindowScalarDeletingDestructor.md --apply --queue-timeout 240 --wait-generated
python .\tools\validator.py --mode file --file by-memory/0x00581dc0-0x00581e35.StartupNoticeDrawPcxImage.md --apply --queue-timeout 240 --wait-generated
python .\tools\validator.py --mode file --file by-memory/0x00581e40-0x00581f46.AnsiSmallStringFindFrom.md --apply --queue-timeout 240 --wait-generated
python .\tools\validator.py --mode file --file by-memory/0x00581f50-0x0058206e.AnsiSmallStringSubstring.md --apply --queue-timeout 240 --wait-generated
python .\tools\validator.py --mode file --file by-item/StartupWindowUnmodeledNoticeHelpers_5815b0_581b7f.md --apply --queue-timeout 240 --wait-generated
python .\tools\validator.py --mode file --file by-memory/0x005807d0-0x0058206e.StartupWindowUpdateCheck.md --apply --queue-timeout 240 --wait-generated
python .\tools\validator.py --mode file --file by-memory/0x0062d418-0x0062d5a8.StartupWindowReadOnlyData.md --apply --queue-timeout 240 --wait-generated
python .\tools\validator.py --mode file --file by-memory/0x00670260-0x00670268.StartupWindowNoticePointerData.md --apply --queue-timeout 240 --wait-generated
python .\tools\validator.py --mode file --file by-memory/0x0069bac4-0x0069bacc.StartupWindowUpdateStateGlobals.md --apply --queue-timeout 240 --wait-generated
```
