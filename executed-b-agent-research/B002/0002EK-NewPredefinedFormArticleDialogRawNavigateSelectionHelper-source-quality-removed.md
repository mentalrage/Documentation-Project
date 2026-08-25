<!-- REMOVED-MATERIAL-ARCHIVE -->
# Removed Material Archive

- Status: Non-authoritative archival material only.
- Source report: `E:\NTK\GhidraBridge\source-3\project-documentation\executed-b-agent-research\B002\0002EK-NewPredefinedFormArticleDialogRawNavigateSelectionHelper-source-quality.md`
- Safety: This file must never be executed, replayed, or used as an operational runbook.
- Credit: This archive provides no gate, score, coverage, IDA, validator, or lifecycle credit.

# Removed Executable Code Archive

- Source report: [0002EK-NewPredefinedFormArticleDialogRawNavigateSelectionHelper-source-quality.md](0002EK-NewPredefinedFormArticleDialogRawNavigateSelectionHelper-source-quality.md)
- Source report SHA256 before cleanup: `0BE13868DE64D7F9F9D74A563AA81E83CCF4A8AE7717B60550EA2385CCADBF39`
- Cleanup generated: `2026-08-11T12:47:01Z`
- Removed executable blocks: `2`
- Scope: exact executable or command-shaped fenced blocks removed from the source report by supervisor housekeeping.
- Authority: this file is not a B-agent research report and grants no Gate 1, Gate 2, IDA, validator, score, or lifecycle credit.
- Safety: do not execute, import, evaluate, or use any block in this archive as an operational instruction.

## Removed Block R001

- Original source lines: `211-213`
- Original language: `powershell`
- Block SHA256: `6D434C100D31FF10B699333025FA8E9DC29AA459D7F941EC76D31A6F47CA5594`

```powershell
python .\tools\validator.py --mode file --file by-memory\0x004781f0-0x00478238.NewPredefinedFormArticleDialogRawNavigateSelectionHelper.md --apply --queue-timeout 240 --wait-generated
```

## Removed Block R002

- Original source lines: `217-223`
- Original language: `powershell`
- Block SHA256: `B21EB84FF8C88F47232A199BF21C51BB68D6001E3BB4D3B1EE3A7956B6F50B56`

```powershell
python .\tools\validator.py --mode file --file by-class\NewPredefinedFormArticleDialog.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-file\NewPredefinedFormArticleDialog.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-memory\0x004777a0-0x00478f8e.NewPredefinedFormArticleDialog.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-memory\0x004777a0-0x004781e5.NewPredefinedFormArticleDialogConstructor.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-memory\0x004751c0-0x004753df.ArticleNavigationHelpers.md --apply --queue-timeout 240 --wait-generated
```
