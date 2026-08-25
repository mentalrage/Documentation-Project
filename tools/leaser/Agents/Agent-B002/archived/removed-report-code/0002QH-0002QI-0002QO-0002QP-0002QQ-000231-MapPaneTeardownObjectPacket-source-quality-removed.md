<!-- REMOVED-MATERIAL-ARCHIVE -->
# Removed Material Archive

- Status: Non-authoritative archival material only.
- Source report: `E:\NTK\GhidraBridge\source-3\project-documentation\executed-b-agent-research\B002\0002QH-0002QI-0002QO-0002QP-0002QQ-000231-MapPaneTeardownObjectPacket-source-quality.md`
- Safety: This file must never be executed, replayed, or used as an operational runbook.
- Credit: This archive provides no gate, score, coverage, IDA, validator, or lifecycle credit.

# Removed Executable Code Archive

- Source report: [0002QH-0002QI-0002QO-0002QP-0002QQ-000231-MapPaneTeardownObjectPacket-source-quality.md](0002QH-0002QI-0002QO-0002QP-0002QQ-000231-MapPaneTeardownObjectPacket-source-quality.md)
- Source report SHA256 before cleanup: `EC5AEC5B867758DB79571D71159E4708D12DB82FB081018A4709BBA4605545C0`
- Cleanup generated: `2026-08-11T12:47:02Z`
- Removed executable blocks: `2`
- Scope: exact executable or command-shaped fenced blocks removed from the source report by supervisor housekeeping.
- Authority: this file is not a B-agent research report and grants no Gate 1, Gate 2, IDA, validator, score, or lifecycle credit.
- Safety: do not execute, import, evaluate, or use any block in this archive as an operational instruction.

## Removed Block R001

- Original source lines: `625-629`
- Original language: `powershell`
- Block SHA256: `4BF1EE5C0672AC1430C37672A1D3D4FECBDFB939E7F9D987933059640454C4E8`

```powershell
Set-Location 'E:\NTK\GhidraBridge\source-3\project-documentation'
rg -n '0002QH|0002QI|0002QO|0002QP|0002QQ|000231|MapPane::ExitToMenu|MapPane::OnTagDetachMessage|MapPane::RemoveObjectPaneById|MapPane::DetachObjectPane|MapPane::HasObjectIntersectingRect|SendObjectRefreshRequest' '.\by-memory' '.\by-class' '.\by-file' '.\by-type' '.\by-memory\-coverage-report.md'
rg -n '95/95|blank final C\+\+|provisional|0x00554210' '.\by-memory\0x005047f0-0x00504b6b.MapPaneExitToMenuTeardown.md' '.\by-memory\0x00504b70-0x00504b8f.MapPaneTagDetachMessage.md' '.\by-memory\0x005060f0-0x00506169.MapPaneRemoveObjectPaneById.md' '.\by-memory\0x00506170-0x005061d3.MapPaneDetachObjectPane.md' '.\by-memory\0x005062f0-0x0050637a.MapPaneFindObjectIntersectingRect.md' '.\by-memory\0x00506380-0x005063db.MapPaneOpcode0CObjectIdPacketHelper.md'
```

## Removed Block R002

- Original source lines: `633-636`
- Original language: `powershell`
- Block SHA256: `421FEB2B0443BBA3B0A30C49E12174B7F6B2279498953E71587F00A809EFA385`

```powershell
Set-Location 'E:\NTK\GhidraBridge\source-3\project-documentation'
python .\tools\leaser\validate_docs.py --uids 0002QH 0002QI 0002QO 0002QP 0002QQ 000231 00007Q 0000L3 00009R 0001SO 0003XC
```
