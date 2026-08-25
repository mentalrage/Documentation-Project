<!-- REMOVED-MATERIAL-ARCHIVE -->
# Removed Material Archive

- Status: Non-authoritative archival material only.
- Source report: `E:\NTK\GhidraBridge\source-3\project-documentation\executed-b-agent-research\B012\00014W-MixItemDialogDoubleParamCallback-empty-emitter-source-quality.md`
- Safety: This file must never be executed, replayed, or used as an operational runbook.
- Credit: This archive provides no gate, score, coverage, IDA, validator, or lifecycle credit.

# Removed Executable Code Archive

- Source report: [00014W-MixItemDialogDoubleParamCallback-empty-emitter-source-quality.md](00014W-MixItemDialogDoubleParamCallback-empty-emitter-source-quality.md)
- Source report SHA256 before cleanup: `E01BD427F54A0410C562A7ECA576A8E3BC86BC1B77D38F1C47761D05F6CD3E4A`
- Cleanup generated: `2026-08-11T12:47:17Z`
- Removed executable blocks: `4`
- Scope: exact executable or command-shaped fenced blocks removed from the source report by supervisor housekeeping.
- Authority: this file is not a B-agent research report and grants no Gate 1, Gate 2, IDA, validator, score, or lifecycle credit.
- Safety: do not execute, import, evaluate, or use any block in this archive as an operational instruction.

## Removed Block R001

- Original source lines: `521-523`
- Original language: `powershell`
- Block SHA256: `19F628C6BFC93AB5B2DD11BC5C6B4DCC23C78DF9658A983C534ED3C7E5060E37`

```powershell
Set-Location E:\NTK\GhidraBridge\source-3\project-documentation
```

## Removed Block R002

- Original source lines: `527-532`
- Original language: `powershell`
- Block SHA256: `6BC82F5EEBBE78D46426F11BEEE371FE1030EEF90C62871C5161DA65BCF36D7B`

```powershell
python .\tools\validator.py --mode file --file "by-class\DoubleParamMemberFunctionObject_void____thiscall_MixItemDialog_____unsigne__h9ece1f1df45d.md" --apply --queue-timeout 240
python .\tools\validator.py --mode file --file "by-file\FunctionObjects.md" --apply --queue-timeout 240
python .\tools\validator.py --mode file --file "by-type\by-template\FunctionObjectTemplates.md" --apply --queue-timeout 240
python .\tools\validator.py --mode file --file "by-memory\0x004b0880-0x004b08a1.MixItemDialogDoubleParamCallback.md" --apply --queue-timeout 240 --wait-generated
```

## Removed Block R003

- Original source lines: `536-538`
- Original language: `powershell`
- Block SHA256: `0AC68CA95C81BBF833DEC63E083D276B7E42543AC554D8540D14EA0712FD9307`

```powershell
python .\tools\validator.py --mode file --file "by-type\by-vtable\MixItemDialogDoubleParamCallbackVtable.md" --apply --queue-timeout 240
```

## Removed Block R004

- Original source lines: `542-546`
- Original language: `powershell`
- Block SHA256: `4C2BCAF6AB16AFA3CA081A53E1D231E337D034774624662BF05AD4C664BE33C2`

```powershell
Get-Content -LiteralPath ".\auto-generated\NexusTK\util\FunctionObjects.cpp" -TotalCount 20
Select-String -LiteralPath ".\auto-generated\NexusTK\util\FunctionObjects.cpp" -Pattern "UID:00014W" -Context 0,4
Select-String -LiteralPath ".\auto-generated\NexusTK\util\FunctionObjects.cpp" -Pattern "UID:00014W.*Empty Emitter Marker"
```
