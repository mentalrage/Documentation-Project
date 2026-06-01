*** UID:0000SO | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:74 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:82 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000P5 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# g_pVirusChecker

## Status

- Confidence: strong for address and singleton role.
- Address: [UID:0001Q3][0x0069bf94-0x0069bf98.g_pVirusChecker](by-memory/0x0069bf94-0x0069bf98.g_pVirusChecker.md)
- Likely owner file: [UID:0000P5][VirusChecker](by-file/VirusChecker.md)

## Purpose

`g_pVirusChecker` stores the active [UID:0000FW][VirusChecker](by-class/VirusChecker.md) singleton. The constructor writes it, and destructor/clear helpers reset it. Current IDA xrefs do not prove the singleton is constructed during the normal startup path, so treat it as real retained scanner state with uncertain live activation.

## Evidence Notes

- IDA MCP decompilation of `0x005c0460` stores the singleton.
- IDA MCP decompilation of `0x005c0eb0` clears `dword_69BF94`.
- 2026-05-24 IDA recheck found five refs, all inside the local VirusChecker lifecycle/helpers: constructor refs at `0x005c0496` and `0x005c049d`, destructor ref at `0x005c0582`, clear helper `0x005c0eb0`, and scalar deleting destructor ref at `0x005c0f63`.
- 2026-05-26 exact memory page: [UID:0001Q3][0x0069bf94-0x0069bf98.g_pVirusChecker](by-memory/0x0069bf94-0x0069bf98.g_pVirusChecker.md). Current IDA state still shows only local VirusChecker refs and no proven normal startup constructor caller.
- IDA MCP `py_eval` rechecked `0x0069bf94` on 2026-05-31 and confirmed IDA name `dword_69BF94`, initial dword `0xffffffff`, and the same 5 local lifecycle refs: constructor writes at `0x005c0496` and `0x005c049d`, destructor clear at `0x005c0582`, clear helper at `0x005c0eb0`, and scalar deleting destructor clear at `0x005c0f63`.
- Generated source names the same storage `g_pVirusChecker`.

## Cross-References

- [UID:0000P5][VirusChecker](by-file/VirusChecker.md)
- [UID:0000FW][VirusChecker](by-class/VirusChecker.md)
- [UID:0001NU][0x005c0460-0x005c0fe1.VirusChecker](by-memory/0x005c0460-0x005c0fe1.VirusChecker.md)
- [UID:0001Q3][0x0069bf94-0x0069bf98.g_pVirusChecker](by-memory/0x0069bf94-0x0069bf98.g_pVirusChecker.md)
- [UID:0001Q7][client_anticheat](by-meta/client_anticheat.md)

## Changes

- 2026-05-31: Updated reconstruction metadata and scores from live IDA evidence.
  - Before: completion/confidence were `0/0`, reconstructable state was blank, and no parent file UID was assigned.
  - After: `COMPLETION:74`, `CONFIDENCE:82`, `RECONSTRUCTABLE:TRUE`, and `AUTOGEN_PARENT_UID:0000P5` for [UID:0000P5][VirusChecker](by-file/VirusChecker.md). `RECONSTRUCTION_CPP CODE` remains blank because the page is below the 95+ final-source threshold.
  - Evidence: IDA MCP rechecked `0x0069bf94` as a 4-byte singleton pointer with 5 local VirusChecker lifecycle xrefs. Confidence remains below the other singleton pass because IDA still has no proven normal startup constructor caller.
