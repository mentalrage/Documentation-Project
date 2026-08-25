<!-- REMOVED-MATERIAL-ARCHIVE -->
# Removed Material Archive

- Status: Non-authoritative archival material only.
- Source report: `E:\NTK\GhidraBridge\source-3\project-documentation\executed-b-agent-research\B002\0001M8-ChangeSpellSlotInputPane-source-quality.md`
- Safety: This file must never be executed, replayed, or used as an operational runbook.
- Credit: This archive provides no gate, score, coverage, IDA, validator, or lifecycle credit.

# Removed Executable Code Archive

- Source report: [0001M8-ChangeSpellSlotInputPane-source-quality.md](0001M8-ChangeSpellSlotInputPane-source-quality.md)
- Source report SHA256 before cleanup: `39D266F3FEBF934C763DCA0226FFAD61ACF45A1A09C7E9C5D51FD3E109460D51`
- Cleanup generated: `2026-08-11T12:47:01Z`
- Removed executable blocks: `2`
- Scope: exact executable or command-shaped fenced blocks removed from the source report by supervisor housekeeping.
- Authority: this file is not a B-agent research report and grants no Gate 1, Gate 2, IDA, validator, score, or lifecycle credit.
- Safety: do not execute, import, evaluate, or use any block in this archive as an operational instruction.

## Removed Block R001

- Original source lines: `648-655`
- Original language: `powershell`
- Block SHA256: `103DA5E245CD40D79D488071001ED5D30A3ADFF2AF84D6DC68E130D43B2021F8`

```powershell
python .\tools\validator.py --mode file --file by-memory\0x005b3220-0x005b340e.ChangeSpellSlotInputPane.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-memory\0x005b3220-0x005b3260.ChangeSpellSlotInputPaneRawConstructor.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-memory\0x005b3260-0x005b32cc.ChangeSpellSlotInputPaneKeyInput.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-memory\0x005b32d0-0x005b340e.ChangeSpellSlotInputPaneSubmitSlotChange.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-class\ChangeSpellSlotInputPane.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-file\SpellInputPanes.md --apply --queue-timeout 240
```

## Removed Block R002

- Original source lines: `659-665`
- Original language: `powershell`
- Block SHA256: `CF21829488D33651C03B89DAACE3890E0B8735FCB180A9131E1038DFD20A9E57`

```powershell
python .\tools\validator.py --mode file --file by-memory\0x0062fad0-0x0062fb58.ChangeSpellSlotInputPaneVtableData.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-type\by-vtable\ChangeSpellSlotInputPaneVtables.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-global\g_pCollectionData.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-memory\0x0067a748-0x0067a74c.g_pCollectionData.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-global\g_packetSender.md --apply --queue-timeout 240
```
