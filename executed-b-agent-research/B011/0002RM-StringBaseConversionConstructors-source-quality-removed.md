<!-- REMOVED-MATERIAL-ARCHIVE -->
# Removed Material Archive

- Status: Non-authoritative archival material only.
- Source report: `E:\NTK\GhidraBridge\source-3\project-documentation\executed-b-agent-research\B011\0002RM-StringBaseConversionConstructors-source-quality.md`
- Safety: This file must never be executed, replayed, or used as an operational runbook.
- Credit: This archive provides no gate, score, coverage, IDA, validator, or lifecycle credit.

# Removed Executable Code Archive

- Source report: [0002RM-StringBaseConversionConstructors-source-quality.md](0002RM-StringBaseConversionConstructors-source-quality.md)
- Source report SHA256 before cleanup: `C22E411056B0F42B4622530EBEB5C35986660A15437B6FE0C0CE7DA8091F4F5D`
- Cleanup generated: `2026-08-11T12:47:16Z`
- Removed executable blocks: `2`
- Scope: exact executable or command-shaped fenced blocks removed from the source report by supervisor housekeeping.
- Authority: this file is not a B-agent research report and grants no Gate 1, Gate 2, IDA, validator, score, or lifecycle credit.
- Safety: do not execute, import, evaluate, or use any block in this archive as an operational instruction.

## Removed Block R001

- Original source lines: `451-457`
- Original language: `powershell`
- Block SHA256: `5633956D5E9AD316ECD2E1053FB010418F118AE95DD5E23E9EA91AEBD689146B`

```powershell
python .\tools\validator.py --mode file --file by-memory/0x00582500-0x005829f0.StringBaseConversionAndCrtShims.md --apply --queue-timeout 240 --wait-generated
python .\tools\validator.py --mode file --file by-file/StringBase.md --apply --queue-timeout 240 --wait-generated
python .\tools\validator.py --mode file --file by-type/by-template/StringBaseTemplate.md --apply --queue-timeout 240 --wait-generated
python .\tools\validator.py --mode file --file by-memory/0x00582500-0x00583206.StringBaseConstructionAndCow.md --apply --queue-timeout 240 --wait-generated
python .\tools\validator.py --mode file --file by-memory/0x005151b0-0x005151ef.DefaultCodepageConversionWrappers.md --apply --queue-timeout 240 --wait-generated
```

## Removed Block R002

- Original source lines: `461-463`
- Original language: `powershell`
- Block SHA256: `93F621B7A0DD225196DF0CF325FB528E3F2106827FFF09D60B43A9ED04CEDF08`

```powershell
python .\tools\validator.py --queue-status
```
