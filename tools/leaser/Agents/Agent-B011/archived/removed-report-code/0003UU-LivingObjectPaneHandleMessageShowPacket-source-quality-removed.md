<!-- REMOVED-MATERIAL-ARCHIVE -->
# Removed Material Archive

- Status: Non-authoritative archival material only.
- Source report: `E:\NTK\GhidraBridge\source-3\project-documentation\executed-b-agent-research\B011\0003UU-LivingObjectPaneHandleMessageShowPacket-source-quality.md`
- Safety: This file must never be executed, replayed, or used as an operational runbook.
- Credit: This archive provides no gate, score, coverage, IDA, validator, or lifecycle credit.

# Removed Executable Code Archive

- Source report: [0003UU-LivingObjectPaneHandleMessageShowPacket-source-quality.md](0003UU-LivingObjectPaneHandleMessageShowPacket-source-quality.md)
- Source report SHA256 before cleanup: `0D7FB21FBC953539E87BD2EC01554F445F95A77CE0FC29540F1A229F051AB395`
- Cleanup generated: `2026-08-11T12:47:16Z`
- Removed executable blocks: `2`
- Scope: exact executable or command-shaped fenced blocks removed from the source report by supervisor housekeeping.
- Authority: this file is not a B-agent research report and grants no Gate 1, Gate 2, IDA, validator, score, or lifecycle credit.
- Safety: do not execute, import, evaluate, or use any block in this archive as an operational instruction.

## Removed Block R001

- Original source lines: `547-567`
- Original language: `powershell`
- Block SHA256: `1FF189510991150EE78A53A45F975159933BAA072C2892231F975F604A291030`

```powershell
$files = @(
  "by-memory/0x005ac070-0x005ac1a8.LivingObjectPaneHandleMessageShowPacket.md",
  "by-file/LivingObjectPane.md",
  "by-class/LivingObjectPane.md",
  "by-memory/0x005a2de0-0x005ad441.LivingObjectPaneLocalPlayerExtensions.md",
  "by-memory/0x005a76c0-0x005a82bd.UserPaneHandleServerMessage.md",
  "by-file/UserPane.md",
  "by-class/UserPane.md",
  "by-file/MessageShowPane.md",
  "by-class/MessageShowPane.md",
  "by-global/g_pMessageShowPane.md",
  "by-memory/0x0069b4f4-0x0069b4f8.g_pMessageShowPane.md",
  "by-memory/0x00522530-0x005226ea.MessageShowPaneSetWrappedText.md",
  "by-memory/0x00625008-0x0062ce50.ServerPacketNameTable.md"
)

foreach ($file in $files) {
  python tools/validator.py --mode file --file $file --apply --lock-timeout 240
}
```

## Removed Block R002

- Original source lines: `571-573`
- Original language: `powershell`
- Block SHA256: `6BCCE920DE3770F23B54BD5F51242DED7B95FA3D89A8C3D89DEF9944FE7D7296`

```powershell
python tools/validator.py --mode autogen --apply --lock-timeout 240
```
