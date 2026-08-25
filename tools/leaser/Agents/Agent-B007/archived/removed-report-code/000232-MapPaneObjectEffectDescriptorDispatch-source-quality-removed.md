<!-- REMOVED-MATERIAL-ARCHIVE -->
# Removed Material Archive

- Status: Non-authoritative archival material only.
- Source report: `E:\NTK\GhidraBridge\source-3\project-documentation\executed-b-agent-research\B007\000232-MapPaneObjectEffectDescriptorDispatch-source-quality.md`
- Safety: This file must never be executed, replayed, or used as an operational runbook.
- Credit: This archive provides no gate, score, coverage, IDA, validator, or lifecycle credit.

# Removed Executable Code Archive

- Source report: [000232-MapPaneObjectEffectDescriptorDispatch-source-quality.md](000232-MapPaneObjectEffectDescriptorDispatch-source-quality.md)
- Source report SHA256 before cleanup: `C4E6FDB3199A9C0F06057395223BA5C03DEECE33E4F4709FDB3AC349A1403B38`
- Cleanup generated: `2026-08-11T12:47:12Z`
- Removed executable blocks: `1`
- Scope: exact executable or command-shaped fenced blocks removed from the source report by supervisor housekeeping.
- Authority: this file is not a B-agent research report and grants no Gate 1, Gate 2, IDA, validator, score, or lifecycle credit.
- Safety: do not execute, import, evaluate, or use any block in this archive as an operational instruction.

## Removed Block R001

- Original source lines: `870-885`
- Original language: `powershell`
- Block SHA256: `4163211F3525B9CB77E28E5D188A67350913370093FCB4A0ECE7526588F6150B`

```powershell
python tools/leaser/validate_docs.py --mode file --path "by-memory/0x0050e320-0x0050e4b6.MapPaneObjectEffectDescriptorDispatch.md" --apply --queue-timeout 240
python tools/leaser/validate_docs.py --mode file --path "by-class/MapPane.md" --apply --queue-timeout 240
python tools/leaser/validate_docs.py --mode file --path "by-file/MapPane.md" --apply --queue-timeout 240
python tools/leaser/validate_docs.py --mode file --path "by-memory/0x0050ea30-0x0050eb8a.MapPaneCreateEffectObjectPane.md" --apply --queue-timeout 240
python tools/leaser/validate_docs.py --mode file --path "by-memory/0x0050eb90-0x0050ec2e.MapPaneApplyEffectObjectPaneTimerAction.md" --apply --queue-timeout 240
python tools/leaser/validate_docs.py --mode file --path "by-memory/0x0050e850-0x0050ea30.MapPaneCoordinateEffectDescriptorDispatch.md" --apply --queue-timeout 240
python tools/leaser/validate_docs.py --mode file --path "by-type/by-struct/EffectInfo.md" --apply --queue-timeout 240
python tools/leaser/validate_docs.py --mode file --path "by-type/by-struct/AttachedObjectRegistryLayout.md" --apply --queue-timeout 240
python tools/leaser/validate_docs.py --mode file --path "by-class/EffectObjectPane.md" --apply --queue-timeout 240
python tools/leaser/validate_docs.py --mode file --path "by-memory/0x005387b0-0x00538baa.EffectObjectPaneCore.md" --apply --queue-timeout 240
python tools/leaser/validate_docs.py --mode file --path "by-memory/0x00511440-0x00511703.MapPaneHandleDrawObjectsPacket.md" --apply --queue-timeout 240
python tools/leaser/validate_docs.py --mode file --path "by-memory/0x00511c90-0x00511dae.MapPaneHandleObjectMoveEffectPacket.md" --apply --queue-timeout 240
python tools/leaser/validate_docs.py --mode file --path "by-memory/0x0053bab0-0x0053bb1d.LivingObjectPaneNameplateSpecialEffectHelpers.md" --apply --queue-timeout 240
python tools/leaser/validate_docs.py --mode file --path "by-memory/0x005a2e00-0x005a36de.LivingObjectPaneProcessMovement.md" --apply --queue-timeout 240
```
