<!-- REMOVED-MATERIAL-ARCHIVE -->
# Removed Material Archive

- Status: Non-authoritative archival material only.
- Source report: `E:\NTK\GhidraBridge\source-3\project-documentation\executed-b-agent-research\B004\0002QR-NewUserDialogPane2CreateUserVariant-source-quality.md`
- Safety: This file must never be executed, replayed, or used as an operational runbook.
- Credit: This archive provides no gate, score, coverage, IDA, validator, or lifecycle credit.

# Removed Executable Code Archive

- Source report: [0002QR-NewUserDialogPane2CreateUserVariant-source-quality.md](0002QR-NewUserDialogPane2CreateUserVariant-source-quality.md)
- Source report SHA256 before cleanup: `493008AE706362D9939432E255AEE7CE62FA2A3DDD2BE3A51A15E143DBAC3D42`
- Cleanup generated: `2026-08-11T12:47:07Z`
- Removed executable blocks: `1`
- Scope: exact executable or command-shaped fenced blocks removed from the source report by supervisor housekeeping.
- Authority: this file is not a B-agent research report and grants no Gate 1, Gate 2, IDA, validator, score, or lifecycle credit.
- Safety: do not execute, import, evaluate, or use any block in this archive as an operational instruction.

## Removed Block R001

- Original source lines: `718-747`
- Original language: `powershell`
- Block SHA256: `A476621FC3A026370A561BC7B9B6A6C37912A7289FB692B22AA07D2198B3CFE7`

```powershell
python .\tools\validator.py --mode file --file by-memory/0x0052a540-0x0052c325.NewUserDialogPane2CreateUserVariant.md --apply --queue-timeout 240 --wait-generated
python .\tools\validator.py --mode file --file by-memory/0x0052a540-0x0052b047.NewUserDialogPane2Constructor.md --apply --queue-timeout 240 --wait-generated
python .\tools\validator.py --mode file --file by-memory/0x0052b050-0x0052b08a.NewUserDialogPane2CompleteDestructorBody.md --apply --queue-timeout 240 --wait-generated
python .\tools\validator.py --mode file --file by-memory/0x0052b090-0x0052b1cb.NewUserDialogPane2ShiftShapesLeft.md --apply --queue-timeout 240 --wait-generated
python .\tools\validator.py --mode file --file by-memory/0x0052b1d0-0x0052b30d.NewUserDialogPane2ShiftShapesRight.md --apply --queue-timeout 240 --wait-generated
python .\tools\validator.py --mode file --file by-memory/0x0052b310-0x0052b395.NewUserDialogPane2SelectNation.md --apply --queue-timeout 240 --wait-generated
python .\tools\validator.py --mode file --file by-memory/0x0052b3a0-0x0052b462.NewUserDialogPane2SelectTotem.md --apply --queue-timeout 240 --wait-generated
python .\tools\validator.py --mode file --file by-memory/0x0052b470-0x0052b52c.NewUserDialogPane2SelectShapeSlot.md --apply --queue-timeout 240 --wait-generated
python .\tools\validator.py --mode file --file by-memory/0x0052b530-0x0052b5b8.NewUserDialogPane2SelectMaleMode.md --apply --queue-timeout 240 --wait-generated
python .\tools\validator.py --mode file --file by-memory/0x0052b5c0-0x0052b648.NewUserDialogPane2SelectFemaleMode.md --apply --queue-timeout 240 --wait-generated
python .\tools\validator.py --mode file --file by-memory/0x0052b650-0x0052b724.NewUserDialogPane2PromptCreateCharacterName.md --apply --queue-timeout 240 --wait-generated
python .\tools\validator.py --mode file --file by-memory/0x0052b730-0x0052b75c.NewUserDialogPane2ApplyCreateCharacterName.md --apply --queue-timeout 240 --wait-generated
python .\tools\validator.py --mode file --file by-memory/0x0052b760-0x0052b88c.NewUserDialogPane2OnCommand.md --apply --queue-timeout 240 --wait-generated
python .\tools\validator.py --mode file --file by-memory/0x0052b890-0x0052b910.NewUserDialogPane2HandleShapeKeyEvent.md --apply --queue-timeout 240 --wait-generated
python .\tools\validator.py --mode file --file by-memory/0x0052b910-0x0052b936.NewUserDialogPane2HandleCreateUserPacketEvent.md --apply --queue-timeout 240 --wait-generated
python .\tools\validator.py --mode file --file by-memory/0x0052b940-0x0052b949.NewUserDialogPane2ForwardDialogNotify.md --apply --queue-timeout 240 --wait-generated
python .\tools\validator.py --mode file --file by-memory/0x0052b950-0x0052b981.NewUserDialogPane2ClearGenderSelectionButtonsRaw.md --apply --queue-timeout 240 --wait-generated
python .\tools\validator.py --mode file --file by-memory/0x0052b990-0x0052b9ed.NewUserDialogPane2ClearTotemSelectionButtonsRaw.md --apply --queue-timeout 240 --wait-generated
python .\tools\validator.py --mode file --file by-memory/0x0052b9f0-0x0052bbbc.NewUserDialogPane2SubmitCreateUser.md --apply --queue-timeout 240 --wait-generated
python .\tools\validator.py --mode file --file by-memory/0x0052bbc0-0x0052bdc5.NewUserDialogPane2SendCreateAccountRequest.md --apply --queue-timeout 240 --wait-generated
python .\tools\validator.py --mode file --file by-memory/0x0052bdd0-0x0052bfc2.NewUserDialogPane2SendCreateCharacterRequest.md --apply --queue-timeout 240 --wait-generated
python .\tools\validator.py --mode file --file by-memory/0x0052bfd0-0x0052c325.NewUserDialogPane2HandleCreateUserReply.md --apply --queue-timeout 240 --wait-generated
python .\tools\validator.py --mode file --file by-memory/0x0061fd94-0x0061fd9c.NewUserDialogPane2TertiaryVtableTail.md --apply --queue-timeout 240 --wait-generated
python .\tools\validator.py --mode file --file by-memory/0x0061fd04-0x0061fd94.NewUserDialogPane2VtableData.md --apply --queue-timeout 240 --wait-generated
python .\tools\validator.py --mode file --file by-class/NewUserDialogPane2.md --apply --queue-timeout 240 --wait-generated
python .\tools\validator.py --mode file --file by-file/NewUserDialogPane2.md --apply --queue-timeout 240 --wait-generated
python .\tools\validator.py --mode file --file by-memory/0x0052a540-0x0052f94c.CreateUserDialogVariants.md --apply --queue-timeout 240 --wait-generated
python .\tools\validator.py --mode file --file by-file/CreateUserDialogs.md --apply --queue-timeout 240 --wait-generated
```
