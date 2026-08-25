<!-- REMOVED-MATERIAL-ARCHIVE -->
# Removed Material Archive

- Status: Non-authoritative archival material only.
- Source report: `E:\NTK\GhidraBridge\source-3\project-documentation\executed-b-agent-research\B006\0002CE-ObjectListTypeIndexExistsSwitchHelper-source-quality.md`
- Safety: This file must never be executed, replayed, or used as an operational runbook.
- Credit: This archive provides no gate, score, coverage, IDA, validator, or lifecycle credit.

# Removed Executable Code Archive

- Source report: [0002CE-ObjectListTypeIndexExistsSwitchHelper-source-quality.md](0002CE-ObjectListTypeIndexExistsSwitchHelper-source-quality.md)
- Source report SHA256 before cleanup: `B2B0D6DFA86ECD661323435B379A988D484B21F9A7D6E42488D2E77158ACC1E3`
- Cleanup generated: `2026-08-11T12:47:11Z`
- Removed executable blocks: `3`
- Scope: exact executable or command-shaped fenced blocks removed from the source report by supervisor housekeeping.
- Authority: this file is not a B-agent research report and grants no Gate 1, Gate 2, IDA, validator, score, or lifecycle credit.
- Safety: do not execute, import, evaluate, or use any block in this archive as an operational instruction.

## Removed Block R001

- Original source lines: `263-269`
- Original language: `powershell`
- Block SHA256: `65DA509E620A03313BA254A5889FA5BD5612CC14592B507B79CB2B04929022D4`

```powershell
cd E:\NTK\GhidraBridge\source-3\project-documentation
python .\tools\validator.py --mode file --file by-memory\0x00532450-0x00532530.ObjectListTypeIndexExistsSwitchHelper.md --apply --queue-timeout 180
python .\tools\validator.py --mode file --file by-memory\0x00531480-0x00532530.ObjectListCategorizeLookupHelpers.md --apply --queue-timeout 180
python .\tools\validator.py --mode file --file by-class\ObjectList.md --apply --queue-timeout 180
python .\tools\validator.py --mode file --file by-file\ObjectList.md --apply --queue-timeout 180
```

## Removed Block R002

- Original source lines: `273-278`
- Original language: `powershell`
- Block SHA256: `8C24E11E5004C5E8498B3CEF18C2905FB96059EA1555C03F29B3B5B64DB8BD31`

```powershell
cd E:\NTK\GhidraBridge\source-3\project-documentation
python .\tools\validator.py --mode file --file by-memory\0x005322d0-0x00532370.ObjectListTypeSpecificIndexDispatch.md --apply --queue-timeout 180
python .\tools\validator.py --mode file --file by-memory\0x00535df0-0x00536270.ObjectListTypeSpecificEncodedKeyLookupHelpers.md --apply --queue-timeout 180
python .\tools\validator.py --mode file --file by-class\ObjectPane.md --apply --queue-timeout 180
```

## Removed Block R003

- Original source lines: `282-285`
- Original language: `powershell`
- Block SHA256: `EB08020632F6F10ED39FF8FF06C21010B65FBB432ACEB25609E9AD97A788234F`

```powershell
cd E:\NTK\GhidraBridge\source-3\project-documentation
Get-Content .\auto-generated\-ag-memory-coverage.md | Select-String -Pattern '0002CE|ObjectListTypeIndexExistsSwitchHelper' -Context 2,2
```
