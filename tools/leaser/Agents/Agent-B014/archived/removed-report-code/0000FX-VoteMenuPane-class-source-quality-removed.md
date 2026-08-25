<!-- REMOVED-MATERIAL-ARCHIVE -->
# Removed Material Archive

- Status: Non-authoritative archival material only.
- Source report: `E:\NTK\GhidraBridge\source-3\project-documentation\executed-b-agent-research\B014\0000FX-VoteMenuPane-class-source-quality.md`
- Safety: This file must never be executed, replayed, or used as an operational runbook.
- Credit: This archive provides no gate, score, coverage, IDA, validator, or lifecycle credit.

# Removed Executable Code Archive

- Source report: [0000FX-VoteMenuPane-class-source-quality.md](0000FX-VoteMenuPane-class-source-quality.md)
- Source report SHA256 before cleanup: `983ABC57326E19F098B74B40EFBE1FC3B6F1BAEDBBFD39725FF69414A595CE13`
- Cleanup generated: `2026-08-11T12:47:18Z`
- Removed executable blocks: `1`
- Scope: exact executable or command-shaped fenced blocks removed from the source report by supervisor housekeeping.
- Authority: this file is not a B-agent research report and grants no Gate 1, Gate 2, IDA, validator, score, or lifecycle credit.
- Safety: do not execute, import, evaluate, or use any block in this archive as an operational instruction.

## Removed Block R001

- Original source lines: `370-383`
- Original language: `powershell`
- Block SHA256: `357AB6B9E738AA9CC559B66EE6C778793DE864F7132A5E9672395FEFF79E2425`

```powershell
python .\tools\validator.py --mode file --file .\by-class\VoteMenuPane.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file .\by-file\VoteMenuPane.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file .\by-type\by-struct\VoteMenuPaneLayout.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file .\by-type\by-vtable\VoteMenuPaneVtables.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file .\by-memory\0x00622ff4-0x00623084.VoteMenuPaneVtableData.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file .\by-global\g_pVoteMenuPane.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file .\by-memory\0x0069ba38-0x0069ba3c.g_pVoteMenuPane.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file .\by-memory\0x005558d0-0x00555945.VoteMenuPaneRawConstructor.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file .\by-memory\0x005558d0-0x0055606d.VoteMenuPaneCore.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file .\by-memory\0x00556070-0x00556211.VoteMenuPaneHitTestAndSubmit.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file .\by-memory\0x00556320-0x005563cd.VoteMenuPaneScalarDeletingDestructor.md --apply --queue-timeout 240
python .\tools\validator.py --mode autogen --apply --queue-timeout 240
```
