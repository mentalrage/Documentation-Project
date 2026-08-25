<!-- REMOVED-MATERIAL-ARCHIVE -->
# Removed Material Archive

- Status: Non-authoritative archival material only.
- Source report: `E:\NTK\GhidraBridge\source-3\project-documentation\executed-b-agent-research\B005\0003O5-SelfSaveInputPaneConstructorRaw-source-quality.md`
- Safety: This file must never be executed, replayed, or used as an operational runbook.
- Credit: This archive provides no gate, score, coverage, IDA, validator, or lifecycle credit.

# Removed Executable Code Archive

- Source report: [0003O5-SelfSaveInputPaneConstructorRaw-source-quality.md](0003O5-SelfSaveInputPaneConstructorRaw-source-quality.md)
- Source report SHA256 before cleanup: `4890ADF5415AA8FB313458822DC0F5BA808861BB19B53C456D1195B8A0F362BF`
- Cleanup generated: `2026-08-11T12:47:10Z`
- Removed executable blocks: `2`
- Scope: exact executable or command-shaped fenced blocks removed from the source report by supervisor housekeeping.
- Authority: this file is not a B-agent research report and grants no Gate 1, Gate 2, IDA, validator, score, or lifecycle credit.
- Safety: do not execute, import, evaluate, or use any block in this archive as an operational instruction.

## Removed Block R001

- Original source lines: `496-501`
- Original language: `powershell`
- Block SHA256: `0DA5F968AEBCB5E8F0174BA8221236FB2BEDBB0851AB6F0269AF5E0A833DBCFD`

```powershell
python tools\validator.py --mode file --file by-memory\0x005b67c0-0x005b6800.SelfSaveInputPaneConstructorRaw.md --apply --queue-timeout 240
python tools\validator.py --mode file --file by-class\SelfSaveInputPane.md --apply --queue-timeout 240
python tools\validator.py --mode file --file by-file\SelfSaveInputPane.md --apply --queue-timeout 240
python tools\validator.py --mode file --file by-memory\0x005b67c0-0x005b68b0.SelfSaveInputPane.md --apply --queue-timeout 240
```

## Removed Block R002

- Original source lines: `505-516`
- Original language: `powershell`
- Block SHA256: `FF39295B0764E9C5EBE5B3DD159059308C718D64FEEE760A95F1541C89B35EA3`

```powershell
python tools\validator.py --mode file --file by-memory\0x005aa140-0x005aa1bf.SelfSaveInputPaneFactory.md --apply --queue-timeout 240
python tools\validator.py --mode file --file by-memory\0x005b6800-0x005b686c.SelfSaveInputPaneConfirmInput.md --apply --queue-timeout 240
python tools\validator.py --mode file --file by-memory\0x005b6870-0x005b68b0.SelfSaveInputPaneSendSelfSavePacketRaw.md --apply --queue-timeout 240
python tools\validator.py --mode file --file by-memory\0x006305c0-0x00630648.SelfSaveInputPaneVtableData.md --apply --queue-timeout 240
python tools\validator.py --mode file --file by-type\by-vtable\SelfSaveInputPaneVtables.md --apply --queue-timeout 240
python tools\validator.py --mode file --file by-resource\str-res-localized-strings.md --apply --queue-timeout 240
python tools\validator.py --mode file --file by-global\g_pLanguageMan.md --apply --queue-timeout 240
python tools\validator.py --mode file --file by-memory\0x0067a750-0x0067a754.g_pLanguageMan.md --apply --queue-timeout 240
python tools\validator.py --mode file --file by-class\CharInputPane.md --apply --queue-timeout 240
python tools\validator.py --mode file --file by-memory\0x004f28a0-0x004f2913.CharInputPaneConstructor.md --apply --queue-timeout 240
```
