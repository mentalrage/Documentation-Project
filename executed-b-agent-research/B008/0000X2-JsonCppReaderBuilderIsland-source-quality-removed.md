<!-- REMOVED-MATERIAL-ARCHIVE -->
# Removed Material Archive

- Status: Non-authoritative archival material only.
- Source report: `E:\NTK\GhidraBridge\source-3\project-documentation\executed-b-agent-research\B008\0000X2-JsonCppReaderBuilderIsland-source-quality.md`
- Safety: This file must never be executed, replayed, or used as an operational runbook.
- Credit: This archive provides no gate, score, coverage, IDA, validator, or lifecycle credit.

# Removed Executable Code Archive

- Source report: [0000X2-JsonCppReaderBuilderIsland-source-quality.md](0000X2-JsonCppReaderBuilderIsland-source-quality.md)
- Source report SHA256 before cleanup: `8B24035E2CF12307224E63FFD76249F0F843261BB147F290E439ADB33C8BE42B`
- Cleanup generated: `2026-08-11T12:47:13Z`
- Removed executable blocks: `4`
- Scope: exact executable or command-shaped fenced blocks removed from the source report by supervisor housekeeping.
- Authority: this file is not a B-agent research report and grants no Gate 1, Gate 2, IDA, validator, score, or lifecycle credit.
- Safety: do not execute, import, evaluate, or use any block in this archive as an operational instruction.

## Removed Block R001

- Original source lines: `312-314`
- Original language: `powershell`
- Block SHA256: `27CE384A445C9D8508F4FBE4C004DD6EAF3F0A8FBB9C32AA577EAF781E2AA102`

```powershell
python .\tools\validator.py --mode file --file by-memory\0x0042ae90-0x0042e850.JsonCppReaderAndBuilderPreludeIsland.md --apply --queue-timeout 240 --wait-generated
```

## Removed Block R002

- Original source lines: `318-320`
- Original language: `powershell`
- Block SHA256: `E41F19E7C6D3A1DF84C464D35BECFDC62D7D63125854E2DA076A9B545C9FEDE9`

```powershell
python .\tools\validator.py --mode file --file by-file\JsonCpp.md --apply --queue-timeout 240 --wait-generated
```

## Removed Block R003

- Original source lines: `324-326`
- Original language: `powershell`
- Block SHA256: `93F621B7A0DD225196DF0CF325FB528E3F2106827FFF09D60B43A9ED04CEDF08`

```powershell
python .\tools\validator.py --queue-status
```

## Removed Block R004

- Original source lines: `330-332`
- Original language: `powershell`
- Block SHA256: `DB03365B6C672CF23787CEEF1E91FF0564BBAF7E7D468C461527B28DC2863DD9`

```powershell
python .\tools\validator.py execute_report B008 0000X2-JsonCppReaderBuilderIsland-source-quality.md 0000X2 --apply
```
