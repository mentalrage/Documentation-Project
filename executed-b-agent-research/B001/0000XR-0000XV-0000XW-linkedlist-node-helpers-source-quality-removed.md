<!-- REMOVED-MATERIAL-ARCHIVE -->
# Removed Material Archive

- Status: Non-authoritative archival material only.
- Source report: `E:\NTK\GhidraBridge\source-3\project-documentation\executed-b-agent-research\B001\0000XR-0000XV-0000XW-linkedlist-node-helpers-source-quality.md`
- Safety: This file must never be executed, replayed, or used as an operational runbook.
- Credit: This archive provides no gate, score, coverage, IDA, validator, or lifecycle credit.

# Removed Executable Code Archive

- Source report: [0000XR-0000XV-0000XW-linkedlist-node-helpers-source-quality.md](0000XR-0000XV-0000XW-linkedlist-node-helpers-source-quality.md)
- Source report SHA256 before cleanup: `F5C3A1702983DFB86FD32FA7092DE63ACDBEBB168128B51796C9DC12CD7E313F`
- Cleanup generated: `2026-08-11T12:46:56Z`
- Removed executable blocks: `1`
- Scope: exact executable or command-shaped fenced blocks removed from the source report by supervisor housekeeping.
- Authority: this file is not a B-agent research report and grants no Gate 1, Gate 2, IDA, validator, score, or lifecycle credit.
- Safety: do not execute, import, evaluate, or use any block in this archive as an operational instruction.

## Removed Block R001

- Original source lines: `212-224`
- Original language: `powershell`
- Block SHA256: `F80B5E1A8B5176BF7CBCEF9350F2337B1F1585A04280B1C2DF007134E65EA3EF`

```powershell
cd E:\NTK\GhidraBridge\source-3\project-documentation
python .\tools\validator.py --mode file --file .\by-memory\0x004570e0-0x00457100.StdListBuyNodeWithPayload8.md --apply --queue-timeout 240 --lock-timeout -1
python .\tools\validator.py --mode file --file .\by-memory\0x00457430-0x00457473.StdListTidy8ByteList.md --apply --queue-timeout 240 --lock-timeout -1
python .\tools\validator.py --mode file --file .\by-memory\0x00457550-0x0045757d.StdListBuyNode8.md --apply --queue-timeout 240 --lock-timeout -1
python .\tools\validator.py --mode file --file .\by-file\LinkedList.md --apply --queue-timeout 240 --lock-timeout -1
python .\tools\validator.py --mode file --file .\by-type\by-struct\ListNode.md --apply --queue-timeout 240 --lock-timeout -1
python .\tools\validator.py --mode file --file .\by-type\by-struct\LinkedListState.md --apply --queue-timeout 240 --lock-timeout -1
python .\tools\validator.py --mode documented --remove-missing --apply --queue-timeout 240 --lock-timeout -1
python .\tools\memory_ranges.py report
python .\tools\validator.py --mode autogen --apply --queue-timeout 240 --lock-timeout -1
python .\tools\validator.py --mode rescore --apply --queue-timeout 240 --lock-timeout -1
```
