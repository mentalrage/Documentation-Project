<!-- REMOVED-MATERIAL-ARCHIVE -->
# Removed Material Archive

- Status: Non-authoritative archival material only.
- Source report: `E:\NTK\GhidraBridge\source-3\project-documentation\executed-b-agent-research\B002\000023-ClanAppearNameInputDialog-source-quality.md`
- Safety: This file must never be executed, replayed, or used as an operational runbook.
- Credit: This archive provides no gate, score, coverage, IDA, validator, or lifecycle credit.

# Removed Executable Code Archive

- Source report: [000023-ClanAppearNameInputDialog-source-quality.md](000023-ClanAppearNameInputDialog-source-quality.md)
- Source report SHA256 before cleanup: `F6A8A3947E4D6330058FC83684C7A87A8E1F4BFCEF0389CA5DEA7A5E0262463E`
- Cleanup generated: `2026-08-11T12:47:00Z`
- Removed executable blocks: `4`
- Scope: exact executable or command-shaped fenced blocks removed from the source report by supervisor housekeeping.
- Authority: this file is not a B-agent research report and grants no Gate 1, Gate 2, IDA, validator, score, or lifecycle credit.
- Safety: do not execute, import, evaluate, or use any block in this archive as an operational instruction.

## Removed Block R001

- Original source lines: `454-463`
- Original language: `powershell`
- Block SHA256: `9AA1B982CE3D383DE52BB9E1B59395C92D9B321CB57058C1F2C134382E75207D`

```powershell
python .\tools\validator.py --mode file --file .\by-class\ClanAppearNameInputDialog.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file .\by-memory\0x004893a0-0x004893d5.ClanAppearNameInputDialogRawConstructor.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file .\by-memory\0x004893e0-0x004894ce.ClanAppearNameInputDialogSubmitName.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file .\by-file\Clan.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file .\by-file\ClanDialogs.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file .\by-type\by-struct\ClanInputDialogLayouts.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file .\by-type\by-vtable\ClanModalDialogVtables.md --apply --queue-timeout 240
python .\tools\validator.py --mode autogen --apply --queue-timeout 240
```

## Removed Block R002

- Original source lines: `467-469`
- Original language: `powershell`
- Block SHA256: `49497937A868333395270230A465C551006249F617E17A57CB4B23DE12E1D5D4`

```powershell
python .\tools\validator.py --mode file --file .\by-memory\0x006158f4-0x00615fd8.ClanModalDialogVtableData.md --apply --queue-timeout 240
```

## Removed Block R003

- Original source lines: `473-478`
- Original language: `powershell`
- Block SHA256: `EBF16C6F28E21B5AD275320716CF8F1C5A7FC45628F8FBD5ECA36C3458F142DC`

```powershell
Select-String -Path .\auto-generated\NexusTK\social\Clan.cpp -Pattern "UID:000023|UID:0002NZ|UID:0002O0|ClanAppearNameInputDialog"
Select-String -Path .\auto-generated\NexusTK\social\Clan.cpp -Pattern "\[\[CHILDREN\]\]|\[\[No Children Attached\]\]"
Select-String -Path .\auto-generated\-ag-class-coverage.md -Pattern "000023|ClanAppearNameInputDialog"
Select-String -Path .\auto-generated\-ag-memory-coverage.md -Pattern "0002NZ|0002O0|ClanAppearNameInputDialog"
```

## Removed Block R004

- Original source lines: `482-485`
- Original language: `powershell`
- Block SHA256: `4B74D7F4C2B2A06CC9A867BDC6BC84F9E6FA60C775069AA53A292AC687376CE9`

```powershell
python .\tools\validator.py --mode documented --apply --queue-timeout 240
python .\tools\validator.py --mode rescore --apply --queue-timeout 240
```
