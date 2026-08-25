<!-- REMOVED-MATERIAL-ARCHIVE -->
# Removed Material Archive

- Status: Non-authoritative archival material only.
- Source report: `E:\NTK\GhidraBridge\source-3\project-documentation\executed-b-agent-research\B003\0001D6-staticobjectpane-core-source-quality.md`
- Safety: This file must never be executed, replayed, or used as an operational runbook.
- Credit: This archive provides no gate, score, coverage, IDA, validator, or lifecycle credit.

# Removed Executable Code Archive

- Source report: [0001D6-staticobjectpane-core-source-quality.md](0001D6-staticobjectpane-core-source-quality.md)
- Source report SHA256 before cleanup: `13FE226345F36D5A5B0B2A76FB8A1BF82CF525945967F60D6A1F45EFC5D540E4`
- Cleanup generated: `2026-08-11T12:47:04Z`
- Removed executable blocks: `1`
- Scope: exact executable or command-shaped fenced blocks removed from the source report by supervisor housekeeping.
- Authority: this file is not a B-agent research report and grants no Gate 1, Gate 2, IDA, validator, score, or lifecycle credit.
- Safety: do not execute, import, evaluate, or use any block in this archive as an operational instruction.

## Removed Block R001

- Original source lines: `316-324`
- Original language: `powershell`
- Block SHA256: `EFDE1F80C41969F623CD44E528CD00911BFAFCB2E87218753D486556B665331A`

```powershell
python tools/validate_doc.py by-memory/0x00537900-0x00537abf.StaticObjectPaneCore.md
python tools/validate_doc.py by-memory/0x00537ac0-0x00537b39.StaticObjectPaneSendInteractionPacket.md
python tools/validate_doc.py by-file/StaticObjectPane.md
python tools/validate_doc.py by-class/StaticObjectPane.md
python tools/validate_doc.py by-memory/0x0050bce0-0x0050e320.MapPaneTileObjectGridRenderCore.md
rg -n "g_pStaticObjectManager|m_objectTypeId|m_objectInstanceId|0x0050c691|0x00537ac0|0001D6|00023G" project-documentation/by-memory project-documentation/by-file project-documentation/by-class
rg -n "0001D6|00023G|00037Y" project-documentation/by-memory/-coverage-report.md
```
