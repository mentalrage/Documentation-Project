<!-- REMOVED-MATERIAL-ARCHIVE -->
# Removed Material Archive

- Status: Non-authoritative archival material only.
- Source report: `E:\NTK\GhidraBridge\source-3\project-documentation\executed-b-agent-research\B003\0001I6-ClearPacketSenderGlobal-source-quality.md`
- Safety: This file must never be executed, replayed, or used as an operational runbook.
- Credit: This archive provides no gate, score, coverage, IDA, validator, or lifecycle credit.

# Removed Executable Code Archive

- Source report: [0001I6-ClearPacketSenderGlobal-source-quality.md](0001I6-ClearPacketSenderGlobal-source-quality.md)
- Source report SHA256 before cleanup: `7B67E50CCB52E655E14F1D40E17A4F7E7ADBCACB1B6A15DBB03E4A8DBFF3FE4E`
- Cleanup generated: `2026-08-11T12:47:04Z`
- Removed executable blocks: `2`
- Scope: exact executable or command-shaped fenced blocks removed from the source report by supervisor housekeeping.
- Authority: this file is not a B-agent research report and grants no Gate 1, Gate 2, IDA, validator, score, or lifecycle credit.
- Safety: do not execute, import, evaluate, or use any block in this archive as an operational instruction.

## Removed Block R001

- Original source lines: `730-739`
- Original language: `powershell`
- Block SHA256: `4BF57DDA6D4865EEC228D37473E2F777B84166CF4B36210A88386F317184B25D`

```powershell
python tools\validator.py --mode file --file by-memory\0x005794c0-0x005794cb.ClearPacketSenderGlobal.md --apply --queue-timeout 180
python tools\validator.py --mode file --file by-file\Socket.md --apply --queue-timeout 180
python tools\validator.py --mode file --file by-class\Socket.md --apply --queue-timeout 180
python tools\validator.py --mode file --file by-global\g_packetSender.md --apply --queue-timeout 180
python tools\validator.py --mode file --file by-memory\0x0067a7ec-0x0067a7f0.g_packetSender.md --apply --queue-timeout 180
python tools\validator.py --mode file --file by-memory\-coverage-report.md --apply --queue-timeout 180
python tools\validator.py --mode autogen --apply --queue-timeout 180
python tools\validator.py --mode rescore --apply --queue-timeout 180
```


## Removed Block R002

- Source report SHA256 before this cleanup pass: `93158D46D94A94D7B41B91B4204F7C2D2CE566BDA0558BFB72E6D9380D32EB04`
- Original source lines: `113-115`
- Original language: `text`
- Block SHA256: `013B65AD17FC19A38F5065C452D067D4B0F7B17B63484AF6F0C4BFE342D0D434`

```text
rg "0001I6|0x005794c0|ClearPacketSenderGlobal|sub_5794C0|dword_67A7EC|g_packetSender" tools/leaser/Agents/*/research/executed
```
