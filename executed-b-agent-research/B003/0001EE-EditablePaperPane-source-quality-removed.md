<!-- REMOVED-MATERIAL-ARCHIVE -->
# Removed Material Archive

- Status: Non-authoritative archival material only.
- Source report: `E:\NTK\GhidraBridge\source-3\project-documentation\executed-b-agent-research\B003\0001EE-EditablePaperPane-source-quality.md`
- Safety: This file must never be executed, replayed, or used as an operational runbook.
- Credit: This archive provides no gate, score, coverage, IDA, validator, or lifecycle credit.

# Removed Executable Code Archive

- Source report: [0001EE-EditablePaperPane-source-quality.md](0001EE-EditablePaperPane-source-quality.md)
- Source report SHA256 before cleanup: `2BC83AD1AF0A72CAD7A79E36A77CC85466685468336F8B7941365F7881BE5A90`
- Cleanup generated: `2026-08-11T12:47:04Z`
- Removed executable blocks: `2`
- Scope: exact executable or command-shaped fenced blocks removed from the source report by supervisor housekeeping.
- Authority: this file is not a B-agent research report and grants no Gate 1, Gate 2, IDA, validator, score, or lifecycle credit.
- Safety: do not execute, import, evaluate, or use any block in this archive as an operational instruction.

## Removed Block R001

- Original source lines: `642-651`
- Original language: `powershell`
- Block SHA256: `0EE000C8B20A6C923BFF77217D5C3310DCA478DE949B7945D92724C111540C22`

```powershell
cd E:\NTK\GhidraBridge\source-3\project-documentation\tools
python validator.py --mode file --file ..\by-memory\0x00545170-0x00545e3b.EditablePaperPane.md --apply
python validator.py --mode file --file ..\by-file\EditablePaperPane.md --apply
python validator.py --mode file --file ..\by-class\EditablePaperPane.md --apply
python validator.py --mode file --file ..\by-type\by-vtable\EditablePaperPaneVtables.md --apply
python validator.py --mode file --file ..\by-memory\0x00545ddd-0x00545df3.EditablePaperPaneAdjustorThunks.md --apply
python validator.py --mode file --file ..\by-memory\-coverage-report.md --apply
python validator.py --mode autogen --apply
```

## Removed Block R002

- Original source lines: `655-659`
- Original language: `powershell`
- Block SHA256: `74F639703CE4A927FEDFCFF2FC6EB3F03E63E44F7988A65BA2F2A87E31195E2A`

```powershell
Select-String -Path E:\NTK\GhidraBridge\source-3\project-documentation\by-memory\0x00545170-0x00545e3b.EditablePaperPane.md -Pattern '\+0x26d|0x005128a0|0x00512900|LINE001\.EPD|0x23|0x1b|0x35'
Select-String -Path E:\NTK\GhidraBridge\source-3\project-documentation\by-memory\-coverage-report.md -Pattern '0001EE|0001EF'
Select-String -Path E:\NTK\GhidraBridge\source-3\project-documentation\by-file\EditablePaperPane.md,E:\NTK\GhidraBridge\source-3\project-documentation\by-class\EditablePaperPane.md -Pattern '\+0x26d|wrapper|LINE001\.EPD|95/95'
```
