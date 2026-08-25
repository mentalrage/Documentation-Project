<!-- REMOVED-MATERIAL-ARCHIVE -->
# Removed Material Archive

- Status: Non-authoritative archival material only.
- Source report: `E:\NTK\GhidraBridge\source-3\project-documentation\executed-b-agent-research\B006\000166-ForwardToTileFrameBlitHelper-source-quality.md`
- Safety: This file must never be executed, replayed, or used as an operational runbook.
- Credit: This archive provides no gate, score, coverage, IDA, validator, or lifecycle credit.

# Removed Executable Code Archive

- Source report: [000166-ForwardToTileFrameBlitHelper-source-quality.md](000166-ForwardToTileFrameBlitHelper-source-quality.md)
- Source report SHA256 before cleanup: `706075D04651EC51999768C490389E8F41049C3E203526C8EEF11217DEC41AD2`
- Cleanup generated: `2026-08-11T12:47:10Z`
- Removed executable blocks: `4`
- Scope: exact executable or command-shaped fenced blocks removed from the source report by supervisor housekeeping.
- Authority: this file is not a B-agent research report and grants no Gate 1, Gate 2, IDA, validator, score, or lifecycle credit.
- Safety: do not execute, import, evaluate, or use any block in this archive as an operational instruction.

## Removed Block R001

- Original source lines: `390-396`
- Original language: `text`
- Block SHA256: `2784F0739D68986C7173A16B44D6DC6AFF0641C95B796BCF65A87878D36A3612`

```text
python .\tools\validator.py --mode file --file by-memory\0x004b99f0-0x004b9a63.ForwardToTileFrameBlitHelper.md --apply --queue-timeout 240 --wait-generated
python .\tools\validator.py --mode file --file by-class\GrafPort.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-file\GrafPort.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-memory\0x004b9820-0x004ba24a.SurfacePaintHelpers.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-file\Surface.md --apply --queue-timeout 240
```

## Removed Block R002

- Original source lines: `402-428`
- Original language: `text`
- Block SHA256: `265138B7D2BE9A8036DC18E266C8798973396493F0845AAFCE69B3CD72ED00B7`

```text
python .\tools\validator.py --mode file --file by-memory\0x004b99f0-0x004b9a63.ForwardToTileFrameBlitHelper.md --apply --queue-timeout 240 --wait-generated
  command_id: 000000004586
  result: ok: 1
  generated_refresh: completed
  key updates: completion 88, confidence 91, canonical owner 0000OC -> 00005V, registry blank -> block, autogen_cpp_update 0000JR, autogen_cpp_update 0000OC, stats_row_remove UID000166 from by-memory_Reconstructable.

python .\tools\validator.py --mode file --file by-class\GrafPort.md --apply --queue-timeout 240
  command_id: 000000004587
  result: ok: 1
  generated_refresh: deferred

python .\tools\validator.py --mode file --file by-file\GrafPort.md --apply --queue-timeout 240
  command_id: 000000004588
  result: ok: 1
  generated_refresh: deferred

python .\tools\validator.py --mode file --file by-memory\0x004b9820-0x004ba24a.SurfacePaintHelpers.md --apply --queue-timeout 240
  command_id: 000000004589
  result: ok: 1
  generated_refresh: deferred

python .\tools\validator.py --mode file --file by-file\Surface.md --apply --queue-timeout 240
  command_id: 000000004590
  result: ok: 1
  generated_refresh: deferred
```


## Removed Block R003

- Source report SHA256 before this cleanup pass: `EBB145951DF177085CC89755DBA0DF8E27DD57546302B4DCAB8A7DB6C7FB48DE`
- Original source lines: `421-429`
- Original language: `text`
- Block SHA256: `B80220DD7BBECC30ADF586C10049763DDE56AE32DB8EBB17EE3A9D631AE1BE60`

```text
python .\tools\leaser\leaser.py Agent-B006 unlease <five changed by-* files> <report>
  by-memory\0x004b99f0-0x004b9a63.ForwardToTileFrameBlitHelper.md: Rejected[No active lease]
  by-class\GrafPort.md: Rejected[No active lease]
  by-file\GrafPort.md: Rejected[No active lease]
  by-memory\0x004b9820-0x004ba24a.SurfacePaintHelpers.md: Rejected[No active lease]
  by-file\Surface.md: Rejected[No active lease]
  tools\leaser\Agents\Agent-B006\research\000166-ForwardToTileFrameBlitHelper-source-quality.md: Rejected[No active lease]
```


## Removed Block R004

- Source report SHA256 before this cleanup pass: `EBB145951DF177085CC89755DBA0DF8E27DD57546302B4DCAB8A7DB6C7FB48DE`
- Original source lines: `433-436`
- Original language: `text`
- Block SHA256: `0BB9329E54459B6957C77382D278A3C017739F91BDD67BD9C899C71A263E276F`

```text
python .\tools\leaser\leaser.py Agent-B006 unlease .\tools\leaser\Agents\Agent-B006\research\000166-ForwardToTileFrameBlitHelper-source-quality.md
  tools\leaser\Agents\Agent-B006\research\000166-ForwardToTileFrameBlitHelper-source-quality.md: Success
```
