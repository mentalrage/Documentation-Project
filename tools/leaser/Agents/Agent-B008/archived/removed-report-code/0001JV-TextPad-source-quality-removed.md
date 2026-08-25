<!-- REMOVED-MATERIAL-ARCHIVE -->
# Removed Material Archive

- Status: Non-authoritative archival material only.
- Source report: `E:\NTK\GhidraBridge\source-3\project-documentation\executed-b-agent-research\B008\0001JV-TextPad-source-quality.md`
- Safety: This file must never be executed, replayed, or used as an operational runbook.
- Credit: This archive provides no gate, score, coverage, IDA, validator, or lifecycle credit.

# Removed Executable Code Archive

- Source report: [0001JV-TextPad-source-quality.md](0001JV-TextPad-source-quality.md)
- Source report SHA256 before cleanup: `CF4179DCE927A62EC802A0136EEF7BD1F53CF9A0B43B6787ADE5AC1422BCD76B`
- Cleanup generated: `2026-08-11T12:47:13Z`
- Removed executable blocks: `2`
- Scope: exact executable or command-shaped fenced blocks removed from the source report by supervisor housekeeping.
- Authority: this file is not a B-agent research report and grants no Gate 1, Gate 2, IDA, validator, score, or lifecycle credit.
- Safety: do not execute, import, evaluate, or use any block in this archive as an operational instruction.

## Removed Block R001

- Original source lines: `651-659`
- Original language: `powershell`
- Block SHA256: `D28187CEF530590094012B8D391BD2256DAF2E0F31DE26F055CF66923F0D73A0`

```powershell
python .\tools\validator.py --mode file --file by-memory\0x00595900-0x00596242.TextPad.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-file\TextPad.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-class\TextPad.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-memory\0x00595be0-0x00595f26.TextPadCommandHelper.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-memory\0x00595f30-0x00596242.TextPadStandaloneFileAndInsertHelpers.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-memory\0x0062e18c-0x0062e228.TextPadVtableData.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-memory\0x0062e228-0x0062e268.TextPadCommandStrings.md --apply --queue-timeout 240
```

## Removed Block R002

- Original source lines: `663-671`
- Original language: `powershell`
- Block SHA256: `CD155D76E4F01F57D29B50C59A84BF1ABEFCC7EA4E1E86B6EACCD35010ABF007`

```powershell
python .\tools\validator.py --mode file --file by-memory\0x00594e60-0x00595389.TextEditSupportObjectsBeforeTextBoxPane.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-class\TextEditScrap.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-memory\0x0058e490-0x0058e691.TextEditPaneSerialization.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-item\EncodeTextEditState_0058E490.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-global\WideApiDispatchTable.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-file\PlatformApi.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-memory\0x0041a280-0x0041a4a8.WideApiDispatchInit.md --apply --queue-timeout 240
```
