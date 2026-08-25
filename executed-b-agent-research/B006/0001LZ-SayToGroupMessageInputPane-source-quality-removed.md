<!-- REMOVED-MATERIAL-ARCHIVE -->
# Removed Material Archive

- Status: Non-authoritative archival material only.
- Source report: `E:\NTK\GhidraBridge\source-3\project-documentation\executed-b-agent-research\B006\0001LZ-SayToGroupMessageInputPane-source-quality.md`
- Safety: This file must never be executed, replayed, or used as an operational runbook.
- Credit: This archive provides no gate, score, coverage, IDA, validator, or lifecycle credit.

# Removed Executable Code Archive

- Source report: [0001LZ-SayToGroupMessageInputPane-source-quality.md](0001LZ-SayToGroupMessageInputPane-source-quality.md)
- Source report SHA256 before cleanup: `75D67C819279D096790D46127387ED7C908F14ECCAF99385243979E1BDA6FD9A`
- Cleanup generated: `2026-08-11T12:47:11Z`
- Removed executable blocks: `1`
- Scope: exact executable or command-shaped fenced blocks removed from the source report by supervisor housekeeping.
- Authority: this file is not a B-agent research report and grants no Gate 1, Gate 2, IDA, validator, score, or lifecycle credit.
- Safety: do not execute, import, evaluate, or use any block in this archive as an operational instruction.

## Removed Block R001

- Original source lines: `141-161`
- Original language: `powershell`
- Block SHA256: `4751C35FFFEC8A508BD19EF460E96738211E6894DBB48BE8991093E1CA339C74`

```powershell
@'
[
  {"text":"0xbe", "size":2},
  {"text":"0x1d2", "size":2},
  {"text":"0x292", "size":2},
  {"text":"0x80", "size":2},
  {"text":"0x108", "size":2},
  {"text":"0xa0", "size":2},
  {"text":"0xa4", "size":2},
  {"text":"0x19", "size":1},
  {"text":"0x100", "size":2},
  {"text":"0x12c", "size":2},
  {"text":"0x230", "size":2},
  {"text":"0x0062f85c", "size":4},
  {"text":"0x00630a44", "size":4},
  {"text":"0x005b2152", "size":4},
  {"text":"0x005b1ec0", "size":4}
]
'@ | python .\tools\int_convert.py --pretty
```
