<!-- REMOVED-MATERIAL-ARCHIVE -->
# Removed Material Archive

- Status: Non-authoritative archival material only.
- Source report: `E:\NTK\GhidraBridge\source-3\project-documentation\executed-b-agent-research\B011\00003T-DialogPane-class-source-quality.md`
- Safety: This file must never be executed, replayed, or used as an operational runbook.
- Credit: This archive provides no gate, score, coverage, IDA, validator, or lifecycle credit.

# Removed Executable Code Archive

- Source report: [00003T-DialogPane-class-source-quality.md](00003T-DialogPane-class-source-quality.md)
- Source report SHA256 before cleanup: `3E6C1DB8F465AC590B7D1EAE51A109CF6E3A8634EC42744C61926CA096DC20EA`
- Cleanup generated: `2026-08-11T12:47:16Z`
- Removed executable blocks: `4`
- Scope: exact executable or command-shaped fenced blocks removed from the source report by supervisor housekeeping.
- Authority: this file is not a B-agent research report and grants no Gate 1, Gate 2, IDA, validator, score, or lifecycle credit.
- Safety: do not execute, import, evaluate, or use any block in this archive as an operational instruction.

## Removed Block R001

- Original source lines: `478-488`
- Original language: `powershell`
- Block SHA256: `818898270950B3C0D681F2A6C237AFF6B01CE686F9DBCBBEBDFCC35BECCF9526`

```powershell
python .\tools\validator.py --mode file --file by-class\DialogPane.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-file\DialogPane.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-memory\0x0049d8a0-0x0049feae.DialogPane.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-memory\0x0049dae0-0x0049dfc4.DialogControlPaneHelpers.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-memory\0x0049eac0-0x0049f07e.DialogPaneSlideAnimation.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-type\by-struct\DialogPaneLayout.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-type\by-vtable\DialogPaneVtables.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-memory\0x00618a60-0x00618afc.DialogPaneVtableData.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-memory\0x0048c27b-0x0048c290.DialogPaneAdjustorThunks.md --apply --queue-timeout 240
```

## Removed Block R002

- Original source lines: `492-507`
- Original language: `powershell`
- Block SHA256: `1827AB197083EB27DEDA049A167CFD6A7640B5982933D27A5D43E87F7B7C2CAC`

```powershell
python .\tools\validator.py --mode file --file by-memory\0x0049dae0-0x0049db14.DialogPaneStoreClampRect.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-memory\0x0049db20-0x0049db28.DialogPaneClearClampRectDirtyFlag.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-memory\0x0049db30-0x0049db5d.DialogPaneSetTitleText.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-memory\0x0049db60-0x0049dc05.DialogPaneSetBackgroundResource.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-memory\0x0049dc10-0x0049dc93.DialogPaneEnsureControlManagerAndAdd.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-memory\0x0049dca0-0x0049dcf8.DialogPaneSelectControlById.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-memory\0x0049dd00-0x0049dd17.DialogCategorySwitch.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-memory\0x0049dd20-0x0049dd6b.DialogPaneFindControlIndexById.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-memory\0x0049dd70-0x0049dd7f.DialogPaneGetControlCountRaw.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-memory\0x0049dd80-0x0049ddd0.DialogPaneSetFocusedControl.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-memory\0x0049ddd0-0x0049ddf7.DialogPaneSetPendingControl.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-memory\0x0049de00-0x0049de67.DialogPaneSetSelectionVisualState.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-memory\0x0049de70-0x0049df14.DialogPaneActivateFocusedControlRaw.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-memory\0x0049df20-0x0049dfc4.DialogPaneActivatePendingControl.md --apply --queue-timeout 240
```

## Removed Block R003

- Original source lines: `511-516`
- Original language: `powershell`
- Block SHA256: `9DF45BB024409B0CDFD02E4724937F85304795ABF17E14E233638D3474B4E03A`

```powershell
python .\tools\validator.py --mode file --file by-class\-coverage-report.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-file\-coverage-report.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-memory\-coverage-report.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-type\by-struct\-coverage-report.md --apply --queue-timeout 240
```

## Removed Block R004

- Original source lines: `520-522`
- Original language: `powershell`
- Block SHA256: `DE5227A1107DC55C84EB00517AB3282A3799A2C661B2059082F319BAFA468D95`

```powershell
python .\tools\validator.py --mode autogen --apply --queue-timeout 240
```
