<!-- REMOVED-MATERIAL-ARCHIVE -->
# Removed Material Archive

- Status: Non-authoritative archival material only.
- Source report: `E:\NTK\GhidraBridge\source-3\project-documentation\executed-b-agent-research\B001\0002BD-UiAssetModeRectVirtualDispatchHelper-post-migration.md`
- Safety: This file must never be executed, replayed, or used as an operational runbook.
- Credit: This archive provides no gate, score, coverage, IDA, validator, or lifecycle credit.

# Removed Executable Code Archive

- Source report: [0002BD-UiAssetModeRectVirtualDispatchHelper-post-migration.md](0002BD-UiAssetModeRectVirtualDispatchHelper-post-migration.md)
- Source report SHA256 before cleanup: `728EC4D2F35A4E068564A91115235F45F0E809532D9CDAFBF899EBBD0AC516EB`
- Cleanup generated: `2026-08-11T12:46:58Z`
- Removed executable blocks: `1`
- Scope: exact executable or command-shaped fenced blocks removed from the source report by supervisor housekeeping.
- Authority: this file is not a B-agent research report and grants no Gate 1, Gate 2, IDA, validator, score, or lifecycle credit.
- Safety: do not execute, import, evaluate, or use any block in this archive as an operational instruction.

## Removed Block R001

- Original source lines: `562-579`
- Original language: `powershell`
- Block SHA256: `8F74024DE9D5ACB60D8C6545A0F9028DDAC038BD3BAB253DABD92AD47BEC297D`

```powershell
# IDA MCP health/session
server_health database=b001_0003lq
lookup_funcs 0x00503060 0x005030bc 0x005030c0 0x00503104 0x00503110 0x005031e1 ...
xrefs_to 0x00503060 0x005030c0 0x00503110 ...
disasm 0x00503060
disasm 0x00503110
decompile 0x005031f0
decompile 0x005032d0
decompile 0x00503350
decompile 0x005034a0
decompile 0x00503650
find_bytes VA/RVA forms for 0x00503060, 0x005030c0, 0x00503110
make_signature 0x00503060 0x005030c0 0x00503110
make_signature_for_range 0x00503060-0x005030bc
search_text byte_66DA97 over 0x00503000-0x00503200
int_convert 0xa6 0xad 0x10 0x20 0x220
```
