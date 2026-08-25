<!-- REMOVED-MATERIAL-ARCHIVE -->
# Removed Material Archive

- Status: Non-authoritative archival material only.
- Source report: `E:\NTK\GhidraBridge\source-3\project-documentation\executed-b-agent-research\B005\0003A5-ScrollPaneInputGeometryHelpers-source-quality.md`
- Safety: This file must never be executed, replayed, or used as an operational runbook.
- Credit: This archive provides no gate, score, coverage, IDA, validator, or lifecycle credit.

# Removed Executable Code Archive

- Source report: [0003A5-ScrollPaneInputGeometryHelpers-source-quality.md](0003A5-ScrollPaneInputGeometryHelpers-source-quality.md)
- Source report SHA256 before cleanup: `758A73720CDEAF26EB2269EF5BCF49DD203B6CFFBCC20F2022C7349A458A1183`
- Cleanup generated: `2026-08-11T12:47:10Z`
- Removed executable blocks: `2`
- Scope: exact executable or command-shaped fenced blocks removed from the source report by supervisor housekeeping.
- Authority: this file is not a B-agent research report and grants no Gate 1, Gate 2, IDA, validator, score, or lifecycle credit.
- Safety: do not execute, import, evaluate, or use any block in this archive as an operational instruction.

## Removed Block R001

- Original source lines: `1170-1185`
- Original language: `text`
- Block SHA256: `6DE8C4750780148A31CE4FAECA985EAD45D088FC6BF6695167D7B72CBEFE73DC`

```text
python .\tools\validator.py --mode file --file by-memory/0x0055d960-0x0055d9d6.ScrollPaneHitTestPart.md --apply --queue-timeout 240 --no-generated-refresh
python .\tools\validator.py --mode file --file by-memory/0x0055dea0-0x0055df10.ScrollPaneSetHighlightedPart.md --apply --queue-timeout 240 --no-generated-refresh
python .\tools\validator.py --mode file --file by-memory/0x0055df10-0x0055dfcf.ScrollPaneBeginPartPress.md --apply --queue-timeout 240 --no-generated-refresh
python .\tools\validator.py --mode file --file by-memory/0x0055dfd0-0x0055e1ed.ScrollPaneProcessActivePart.md --apply --queue-timeout 240 --no-generated-refresh
python .\tools\validator.py --mode file --file by-memory/0x0055e210-0x0055e5f6.ScrollPaneUpdatePositionFromCursor.md --apply --queue-timeout 240 --no-generated-refresh
python .\tools\validator.py --mode file --file by-memory/0x0055e600-0x0055e65c.ScrollPaneResetScrollState.md --apply --queue-timeout 240 --no-generated-refresh
python .\tools\validator.py --mode file --file by-memory/0x0055d960-0x0055e65c.ScrollPaneInputGeometryHelpers.md --apply --queue-timeout 240 --no-generated-refresh
python .\tools\validator.py --mode file --file by-memory/0x0055d9e0-0x0055de99.ScrollPaneGetScrollPartRect.md --apply --queue-timeout 240 --no-generated-refresh
python .\tools\validator.py --mode file --file by-class/ScrollPane.md --apply --queue-timeout 240 --no-generated-refresh
python .\tools\validator.py --mode file --file by-memory/0x0055c400-0x0055c5ff.ScrollPaneHandleMouseEvent.md --apply --queue-timeout 240 --no-generated-refresh
python .\tools\validator.py --mode file --file by-memory/0x0055c610-0x0055c643.ScrollPaneOnScrollTimer.md --apply --queue-timeout 240 --no-generated-refresh
python .\tools\validator.py --mode file --file by-file/ScrollBar.md --apply --queue-timeout 240 --no-generated-refresh
python .\tools\validator.py --mode file --file by-memory/0x0055d960-0x005654ec.TextEditPaneScrollbarVariants.md --apply --queue-timeout 240 --no-generated-refresh
python .\tools\validator.py --mode file --file by-memory/-ignored.md --apply --queue-timeout 240 --no-generated-refresh
```

## Removed Block R002

- Original source lines: `1191-1194`
- Original language: `text`
- Block SHA256: `92A97CD2DB670D84ECB18474E4551F4BA593945FA9552DEA1A55C9EB7E20F720`

```text
python .\tools\validator.py --mode file --file by-memory/-coverage-report.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-class/-coverage-report.md --apply --queue-timeout 240
```
