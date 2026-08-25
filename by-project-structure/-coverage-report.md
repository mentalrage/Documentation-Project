*** UID:0001QZ | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:-1 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:-1 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***

# by-project-structure Coverage Report

## Summary

- Last generated: 2026-05-26
- Folder: `by-project-structure`
- Coverage summary: 1 covered reconstructable rows, 0 covered ignored rows, 1 uncovered inventory placeholder row.
- Confidence summary: baseline report generated from existing documentation pages and `-ignored.md`; ignored rows are driven by the local ignored ledger, while reconstructable row confidence is heuristic until IDA/MCP or manual verification raises it.
- Ordering: alphabetic by item name, except `by-memory`, which is sorted by the first address in the row.

## Covered Items To Replicate

- [UID:0001R1][proposed-source-tree](by-project-structure/proposed-source-tree.md) : reconstructable : 50% : medium : Confidence remains medium for the initial source-layout hypothesis, indexed by-file coverage, and final migration readiness; the established `NexusTK/security/CheatDetector.cpp` entry now explicitly contains the sole g_pCheatDetector definition, direct Singleton<CheatDetector>/TimerHandler class, constructor/CaptureTimeSnapshot/OnTimer source, inline empty destructor carrier, and compiler-only clear/scalar/vtable exclusions with no duplicate backing-storage emission.

## Covered Items To Ignore

- None recorded yet.

## Uncovered Items

- by-project-structure inventory baseline : uncovered : 0% : open : Full authoritative inventory for by-project-structure is not yet proven complete; compare this report against Wave3 when OPERATIONAL, simroot_v2, and IDA/MCP evidence.
