<!-- REMOVED-MATERIAL-ARCHIVE -->
# Removed Material Archive

- Status: Non-authoritative archival material only.
- Source report: `E:\NTK\GhidraBridge\source-3\project-documentation\executed-b-agent-research\B008\0001K5-ThreadManScalarDeletingDestructor-source-quality.md`
- Safety: This file must never be executed, replayed, or used as an operational runbook.
- Credit: This archive provides no gate, score, coverage, IDA, validator, or lifecycle credit.

# Removed Executable Code Archive

- Source report: [0001K5-ThreadManScalarDeletingDestructor-source-quality.md](0001K5-ThreadManScalarDeletingDestructor-source-quality.md)
- Source report SHA256 before cleanup: `B78698511FE82A6BE03A06AE3E2B2442641BF874F5EB6B9C390495C228E961DB`
- Cleanup generated: `2026-08-11T12:47:14Z`
- Removed executable blocks: `2`
- Scope: exact executable or command-shaped fenced blocks removed from the source report by supervisor housekeeping.
- Authority: this file is not a B-agent research report and grants no Gate 1, Gate 2, IDA, validator, score, or lifecycle credit.
- Safety: do not execute, import, evaluate, or use any block in this archive as an operational instruction.

## Removed Block R001

- Original source lines: `354-361`
- Original language: `powershell`
- Block SHA256: `0442132F8150315FEBAB255C3DFB203A18E9FBD636595D4E5CE1195B55D73CA7`

```powershell
python .\tools\validator.py --mode file --file .\by-memory\0x005974f0-0x0059756e.ThreadManScalarDeletingDestructor.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file .\by-class\ThreadMan.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file .\by-type\by-struct\ThreadManLayout.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file .\by-memory\0x00596d20-0x00596e0b.ThreadManRawMessageWrappers.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file .\by-global\g_pThreadMan.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file .\by-memory\0x0062e268-0x0062e334.ThreadReadOnlyData.md --apply --queue-timeout 240
```

## Removed Block R002

- Original source lines: `365-367`
- Original language: `powershell`
- Block SHA256: `97080BC52D2994BD820EB38292C855730161F907E6291D75C642B5CE0B74BE98`

```powershell
python .\tools\validator.py --mode file --file .\by-file\Thread.md --apply --queue-timeout 240
```
