*** UID:0000SO | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:82 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000P5 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# g_pVirusChecker

## Status

- Confidence: strong for address, size, initialization, local lifecycle, and file owner; medium-high for live activation.
- Address: [UID:0001Q3][0x0069bf94-0x0069bf98.g_pVirusChecker](by-memory/0x0069bf94-0x0069bf98.g_pVirusChecker.md)
- Likely owner file: [UID:0000P5][VirusChecker](by-file/VirusChecker.md)

## Purpose

`g_pVirusChecker` stores the active [UID:0000FW][VirusChecker](by-class/VirusChecker.md) singleton. The constructor writes it, and destructor/clear helpers reset it. Current IDA xrefs do not prove the singleton is constructed during the normal startup path, so treat it as real retained scanner state with uncertain live activation.

## Storage

| Range | Segment | IDA name | Proposed symbol | Type | Initial bytes | Initial value | Meaning |
| --- | --- | --- | --- | --- | --- | --- | --- |
| `0x0069bf94-0x0069bf98` | `.data` | `dword_69BF94` | `g_pVirusChecker` | `VirusChecker *` | `ff ff ff ff` | `0xffffffff` | Active retained V3 scanner singleton pointer. |

## Evidence Notes

- IDA MCP `py_eval` on 2026-06-05 reports item head `0x0069bf94`, size 4, segment `.data`, IDA name `dword_69BF94`, bytes `ff ff ff ff`, value `0xffffffff`, and five direct data references.
- `xrefs_to 0x0069bf94` reports all five data refs inside the local `VirusChecker` lifecycle: constructor publish/null-clear refs at `0x005c0496` and `0x005c049d`, ordinary destructor clear at `0x005c0582`, clear helper write at `0x005c0eb0`, and scalar deleting destructor clear at `0x005c0f63`.
- Decompilation of `0x005c0460-0x005c04e0` publishes `this` to `dword_69BF94` unless the adjusted pointer is null, installs the `VirusChecker` vtable, initializes the embedded tree header/count fields, and allocates the sentinel through `sub_5796D0`.
- Decompilation of `0x005c04e0-0x005c059d` restores the `VirusChecker` vtable, frees the V3 module handles when present, clears the V3 function pointers, destroys the embedded path tree, frees the sentinel, and clears `dword_69BF94` at `0x005c0582`.
- `0x005c0eb0-0x005c0ebb` is a tiny clear helper that stores zero to `dword_69BF94`; `xrefs_to 0x005c0eb0` reports the EH cleanup thunk edge at `0x0060bc76`.
- Decompilation of `0x005c0ec0-0x005c0f94` is the scalar deleting destructor path. It repeats the V3/tree teardown, clears `dword_69BF94` at `0x005c0f63`, and conditionally frees the object; `xrefs_to 0x005c0ec0` reports the vtable data ref at `0x006310e0`.
- `callers 0x005c0460`, `0x005c04e0`, `0x005c0eb0`, and `0x005c0ec0` report no direct static callers in the current graph, so normal runtime activation remains unproven.

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
- 2026-06-05: Raised completion/confidence from `74/82` to `82/88` and expanded the evidence around the exact singleton storage and local lifecycle refs. The score now clears the parent gate for the memory page, but remains below the higher singleton score used for globals with proven startup/consumer paths because IDA still reports no direct normal constructor caller.
