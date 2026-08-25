<!-- REMOVED-MATERIAL-ARCHIVE -->
# Removed Material Archive

- Status: Non-authoritative archival material only.
- Source report: `E:\NTK\GhidraBridge\source-3\project-documentation\executed-b-agent-research\B010\0002RQ-StringBaseSplitTrimAndLocks-source-quality.md`
- Safety: This file must never be executed, replayed, or used as an operational runbook.
- Credit: This archive provides no gate, score, coverage, IDA, validator, or lifecycle credit.

# Removed Executable Code Archive

- Source report: [0002RQ-StringBaseSplitTrimAndLocks-source-quality.md](0002RQ-StringBaseSplitTrimAndLocks-source-quality.md)
- Source report SHA256 before cleanup: `651F1E496C46B1C9E7AFEC9C40679F3A682573215195D23C84377DA9E062DE5C`
- Cleanup generated: `2026-08-11T12:47:15Z`
- Removed executable blocks: `1`
- Scope: exact executable or command-shaped fenced blocks removed from the source report by supervisor housekeeping.
- Authority: this file is not a B-agent research report and grants no Gate 1, Gate 2, IDA, validator, score, or lifecycle credit.
- Safety: do not execute, import, evaluate, or use any block in this archive as an operational instruction.

## Removed Block R001

- Original source lines: `658-668`
- Original language: `powershell`
- Block SHA256: `B5E45DD0F3F4ACC07B9B2DF3B58FBB9533075BC8EA702C34A7A9243DE56692F7`

```powershell
python .\tools\validator.py --mode file --file by-memory\0x00583970-0x00584052.StringBaseReplaceTrimAndLocks.md --apply --queue-timeout 240 --wait-generated
python .\tools\validator.py --mode file --file by-memory\0x005832f0-0x00584d7e.StringBaseReleaseFormatAndMutation.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-memory\0x005845f0-0x0058490f.StringBaseWideSearchHelpers.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-file\StringBase.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-type\by-template\StringBaseTemplate.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-type\by-struct\RefCountedStringBufferHeader.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-global\StringBufferSentinelsAndPools.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-memory\0x00584910-0x0058498b.SimpleUStringVectorPushBack.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-class\SimpleUStringVector.md --apply --queue-timeout 240
```
