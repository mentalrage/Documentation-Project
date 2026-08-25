<!-- REMOVED-MATERIAL-ARCHIVE -->
# Removed Material Archive

- Status: Non-authoritative archival material only.
- Source report: `E:\NTK\GhidraBridge\source-3\project-documentation\executed-b-agent-research\B007\0000NF-ScrollBar-empty-emitter-family-source-quality.md`
- Safety: This file must never be executed, replayed, or used as an operational runbook.
- Credit: This archive provides no gate, score, coverage, IDA, validator, or lifecycle credit.

# Removed Executable Code Archive

- Source report: [0000NF-ScrollBar-empty-emitter-family-source-quality.md](0000NF-ScrollBar-empty-emitter-family-source-quality.md)
- Source report SHA256 before cleanup: `A98C878A97DBF215BC88B61D2C95566F6B6E2D819FBE02290C3B40E2DCC2BFB0`
- Cleanup generated: `2026-08-11T12:47:11Z`
- Removed executable blocks: `1`
- Scope: exact executable or command-shaped fenced blocks removed from the source report by supervisor housekeeping.
- Authority: this file is not a B-agent research report and grants no Gate 1, Gate 2, IDA, validator, score, or lifecycle credit.
- Safety: do not execute, import, evaluate, or use any block in this archive as an operational instruction.

## Removed Block R001

- Original source lines: `580-596`
- Original language: `powershell`
- Block SHA256: `00BF362C2392836F665D73EAC9E053348AC8E14A7E50E0C25811BD928813AF35`

```powershell
cd E:\NTK\GhidraBridge\source-3\project-documentation
python .\tools\validator.py --mode file --file by-file/ScrollBar.md --apply --queue-timeout 240 --wait-generated
python .\tools\validator.py --mode file --file by-class/CScrollBarBackPane.md --apply --queue-timeout 240 --wait-generated
python .\tools\validator.py --mode file --file by-memory/0x0053fea0-0x0053ff8d.CScrollBarBackPaneCore.md --apply --queue-timeout 240 --wait-generated
python .\tools\validator.py --mode file --file by-memory/0x00621018-0x006210a0.CScrollBarBackPaneVtableData.md --apply --queue-timeout 240 --wait-generated
python .\tools\validator.py --mode file --file by-class/ScrollPane.md --apply --queue-timeout 240 --wait-generated
python .\tools\validator.py --mode file --file by-memory/0x0055c400-0x0055c5ff.ScrollPaneHandleMouseEvent.md --apply --queue-timeout 240 --wait-generated
python .\tools\validator.py --mode file --file by-memory/0x0055d960-0x0055e65c.ScrollPaneInputGeometryHelpers.md --apply --queue-timeout 240 --wait-generated
python .\tools\validator.py --mode file --file by-memory/0x00623d58-0x00623de0.ScrollPaneVtableData.md --apply --queue-timeout 240 --wait-generated
python .\tools\validator.py --mode file --file by-class/ScrollWidget.md --apply --queue-timeout 240 --wait-generated
python .\tools\validator.py --mode file --file by-class/ScrollablePane.md --apply --queue-timeout 240 --wait-generated
python .\tools\validator.py --mode file --file by-memory/0x0055e660-0x0055f44f.ScrollablePaneCore.md --apply --queue-timeout 240 --wait-generated
python .\tools\validator.py --mode file --file by-memory/0x005654ec-0x00565608.ScrollablePaneVirtualDefaults.md --apply --queue-timeout 240 --wait-generated
python .\tools\validator.py --mode file --file by-memory/0x00623de0-0x00623e90.ScrollablePaneVtableData.md --apply --queue-timeout 240 --wait-generated
python .\tools\validator.py --mode file --file by-memory/0x00624138-0x00624168.ScrollPaneScrollbarConstantData.md --apply --queue-timeout 240 --wait-generated
```
