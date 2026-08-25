<!-- REMOVED-MATERIAL-ARCHIVE -->
# Removed Material Archive

- Status: Non-authoritative archival material only.
- Source report: `E:\NTK\GhidraBridge\source-3\project-documentation\executed-b-agent-research\B004\0001GH-ScrollPaneInputCore-source-quality.md`
- Safety: This file must never be executed, replayed, or used as an operational runbook.
- Credit: This archive provides no gate, score, coverage, IDA, validator, or lifecycle credit.

# Removed Executable Code Archive

- Source report: [0001GH-ScrollPaneInputCore-source-quality.md](0001GH-ScrollPaneInputCore-source-quality.md)
- Source report SHA256 before cleanup: `DD6E6E3E3B20318016FB5AA242E73BC88B9E422FD0F32DC675740914E019333A`
- Cleanup generated: `2026-08-11T12:47:06Z`
- Removed executable blocks: `1`
- Scope: exact executable or command-shaped fenced blocks removed from the source report by supervisor housekeeping.
- Authority: this file is not a B-agent research report and grants no Gate 1, Gate 2, IDA, validator, score, or lifecycle credit.
- Safety: do not execute, import, evaluate, or use any block in this archive as an operational instruction.

## Removed Block R001

- Original source lines: `620-637`
- Original language: `powershell`
- Block SHA256: `EC604B42C1BBC69DC66F2BDD9C56F2CAFFB316A71763040E588EA598DD8AED73`

```powershell
python .\tools\validator.py --mode file --file by-memory\0x0055c200-0x0055c643.ScrollPaneInputCore.md --apply --queue-timeout 240 --wait-generated
python .\tools\validator.py --mode file --file by-memory\0x0055c200-0x0055c2a1.ScrollPaneConstructor.md --apply --queue-timeout 240 --wait-generated
python .\tools\validator.py --mode file --file by-memory\0x0055c2b0-0x0055c2d7.ScrollPaneRangeSetterRaw.md --apply --queue-timeout 240 --wait-generated
python .\tools\validator.py --mode file --file by-memory\0x0055c2e0-0x0055c304.ScrollPaneByteStateSetterRaw.md --apply --queue-timeout 240 --wait-generated
python .\tools\validator.py --mode file --file by-memory\0x0055c310-0x0055c36b.ScrollWidgetSetScrollTargetValue.md --apply --queue-timeout 240 --wait-generated
python .\tools\validator.py --mode file --file by-memory\0x0055c370-0x0055c397.ScrollWidgetCurrentValueSetterRaw.md --apply --queue-timeout 240 --wait-generated
python .\tools\validator.py --mode file --file by-memory\0x0055c3a0-0x0055c3ba.ScrollWidgetEnable.md --apply --queue-timeout 240 --wait-generated
python .\tools\validator.py --mode file --file by-memory\0x0055c3c0-0x0055c3da.ScrollWidgetDisable.md --apply --queue-timeout 240 --wait-generated
python .\tools\validator.py --mode file --file by-memory\0x0055c3e0-0x0055c3fa.ScrollPaneIsScrollThumbVisible.md --apply --queue-timeout 240 --wait-generated
python .\tools\validator.py --mode file --file by-memory\0x0055c400-0x0055c5ff.ScrollPaneHandleMouseEvent.md --apply --queue-timeout 240 --wait-generated
python .\tools\validator.py --mode file --file by-memory\0x0055c600-0x0055c605.ScrollPaneCanScroll.md --apply --queue-timeout 240 --wait-generated
python .\tools\validator.py --mode file --file by-memory\0x0055c610-0x0055c643.ScrollPaneOnScrollTimer.md --apply --queue-timeout 240 --wait-generated
python .\tools\validator.py --mode file --file by-class\ScrollPane.md --apply --queue-timeout 240 --wait-generated
python .\tools\validator.py --mode file --file by-class\ScrollWidget.md --apply --queue-timeout 240 --wait-generated
python .\tools\validator.py --mode file --file by-file\ScrollBar.md --apply --queue-timeout 240 --wait-generated
python .\tools\validator.py --mode file --file by-memory\0x00623d58-0x00623de0.ScrollPaneVtableData.md --apply --queue-timeout 240 --wait-generated
```
