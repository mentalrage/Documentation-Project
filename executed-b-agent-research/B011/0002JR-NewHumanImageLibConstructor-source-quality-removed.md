<!-- REMOVED-MATERIAL-ARCHIVE -->
# Removed Material Archive

- Status: Non-authoritative archival material only.
- Source report: `E:\NTK\GhidraBridge\source-3\project-documentation\executed-b-agent-research\B011\0002JR-NewHumanImageLibConstructor-source-quality.md`
- Safety: This file must never be executed, replayed, or used as an operational runbook.
- Credit: This archive provides no gate, score, coverage, IDA, validator, or lifecycle credit.

# Removed Executable Code Archive

- Source report: [0002JR-NewHumanImageLibConstructor-source-quality.md](0002JR-NewHumanImageLibConstructor-source-quality.md)
- Source report SHA256 before cleanup: `58EFD1E1FAB815F985D1BE230E2B80E5C5C90BC9C9F7E10E41EEDF9BA5321FC1`
- Cleanup generated: `2026-08-11T12:47:16Z`
- Removed executable blocks: `1`
- Scope: exact executable or command-shaped fenced blocks removed from the source report by supervisor housekeeping.
- Authority: this file is not a B-agent research report and grants no Gate 1, Gate 2, IDA, validator, score, or lifecycle credit.
- Safety: do not execute, import, evaluate, or use any block in this archive as an operational instruction.

## Removed Block R001

- Original source lines: `663-684`
- Original language: `powershell`
- Block SHA256: `1724F2C106713F39D195269F1400A98BEEEF2F75EC0258557A52176B896E2B04`

```powershell
python .\tools\validator.py --mode file --file by-memory/0x004dfd10-0x004e024a.NewHumanImageLibConstructor.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-class/NewHumanImageLib.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-file/NewHumanImageLib.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-type/by-struct/NewHumanImageLibLayout.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-resource/new-human-motion-tables.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-memory/0x004dfd10-0x004e4d79.NewHumanImageLibLocalMethodCluster.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-memory/0x004e0d70-0x004e0dcf.NewHumanImageLibLoadPartFrameDrawRecord.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-memory/0x004e0dd0-0x004e0dda.NewHumanImageLibGetHeadCount.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-memory/0x004e0e20-0x004e103f.NewHumanImageLibLoadMotionTable.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-memory/0x004e1040-0x004e11af.NewHumanImageLibLoadLayerTable.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-memory/0x004e11b0-0x004e13a7.NewHumanImageLibLoadPartTable.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-memory/0x004e13b0-0x004e17f6.NewHumanImageLibLoadPartSpriteDescriptors.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-memory/0x004e1800-0x004e19c5.NewHumanImageLibLoadAcc2DrwTable.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-memory/0x004e4f10-0x004e50a0.VectorGrowAcc2Drw.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-memory/0x004e50a0-0x004e523e.VectorGrowLayer.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-memory/0x004e5240-0x004e5415.VectorGrowMotion.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-memory/0x004e5420-0x004e55f6.VectorGrowPart.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-item/ResolveSpritePartPath_004E19D0.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-memory/0x004e19d0-0x004e1f27.ResolveSpritePartPath.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-memory/0x004e5dd0-0x004e5e39.DestroyMotionVector.md --apply --queue-timeout 240
```
