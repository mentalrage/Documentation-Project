*** UID:0000BF | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:85 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:85 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000MW | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# Queue

## Status

- Confidence: strong for layout, method roles, fixed-slot queue source ownership, vtable identity, and `Queue.cpp` routing; medium-high for active caller reachability because the raw helper starts still lack modeled direct callers.
- Likely source file: [UID:0000MW][Queue](by-file/Queue.md)
- Address range: [UID:0001FN][0x005539e0-0x00553c07.Queue](by-memory/0x005539e0-0x00553c07.Queue.md)
- Current generated file: `source-3/simroot_v2/class_Queue.cpp`, which emits only the constructor and scalar deleting destructor and should not be treated as complete source coverage.

## Class Purpose

`Queue` is a small `LObject`-derived circular queue for fixed-size slots. The constructor takes slot size and slot count, allocates one contiguous zeroed buffer, and initializes read/write indices.

## Layout

```text
+0x00  vtable
+0x04  slotSize
+0x08  slotCount
+0x0c  buffer
+0x10  readIndex
+0x14  writeIndex
```

The current generated field names call `+0x04` `m_slotCount` and `+0x08` `m_slotSize`, but IDA push/pop arithmetic shows `+0x04` is multiplied by the read/write index as the byte stride, while `+0x08` is used as the wrap limit.

2026-05-26 IDA recheck confirms the constructor stores `a2` to `this[1]`, `a3` to `this[2]`, and allocates `a3 * a2` bytes. The raw write/read helpers still use `+0x04` as the copy byte count and `+0x08` as the wrap limit, so keep the corrected layout names above despite the current generated parameter names.

[UID:0001FN][0x005539e0-0x00553c07.Queue](by-memory/0x005539e0-0x00553c07.Queue.md) now records the same layout at aggregate level, including exact child ranges, internal padding, raw helper boundary caveats, generated-output omissions, and `Queue.cpp` parent routing.

2026-06-10 A002 live IDA refresh confirms the class-level evidence still matches the documented layout: the constructor writes the vtable at `0x00553a15`, stores `a2` at `this[1]` and `a3` at `this[2]`, zero-allocates `a3 * a2` bytes through `sub_5160D0`, and clears `this[4]`/`this[5]`; the ordinary and scalar deleting destructors restore the same `Queue` vtable and free `this[3]` through `MemoryMan`; the raw write/read helpers use `+0x04` as copy stride and `+0x08` as wrap limit; and the compact empty helper compares `+0x10` against `+0x14`.

## Methods

| Address | Method | Role |
| --- | --- | --- |
| `0x005539e0` | [UID:0001FM][0x005539e0-0x00553a5c.QueueConstructor](by-memory/0x005539e0-0x00553a5c.QueueConstructor.md) | Calls `LObject`, installs vtable, allocates `slotSize * slotCount` zeroed bytes. |
| `0x00553a60` | [UID:0001FO][0x00553a60-0x00553ab9.QueueDestructor](by-memory/0x00553a60-0x00553ab9.QueueDestructor.md) | Frees buffer and runs `LObject` teardown. |
| `0x00553ac0` | [UID:0001FP][0x00553ac0-0x00553b05.QueueWriteSlotRaw](by-memory/0x00553ac0-0x00553b05.QueueWriteSlotRaw.md) | Raw start; copies one fixed-size slot into the write position and advances write index. |
| `0x00553b10` | [UID:0001FQ][0x00553b10-0x00553b55.QueueReadSlotRaw](by-memory/0x00553b10-0x00553b55.QueueReadSlotRaw.md) | Raw start; copies one fixed-size slot out of the read position and advances read index. |
| `0x00553b60` | [UID:0001FR][0x00553b60-0x00553b6a.QueueIsEmptyRaw](by-memory/0x00553b60-0x00553b6a.QueueIsEmptyRaw.md) | Raw start; compares read and write indices. |
| `0x00553b70` | [UID:0001FS][0x00553b70-0x00553c07.QueueScalarDeletingDestructor](by-memory/0x00553b70-0x00553c07.QueueScalarDeletingDestructor.md) | Destructor plus conditional delete. |

## Cross-References

- [UID:0000MW][Queue](by-file/Queue.md)
- [UID:0001QA][client_containers](by-meta/client_containers.md)
- [UID:0000L7][MemoryMan](by-file/MemoryMan.md)
- [UID:0001FN][0x005539e0-0x00553c07.Queue](by-memory/0x005539e0-0x00553c07.Queue.md)
- [UID:000269][0x00622d24-0x00622f54.QueueReconnectCopyReadOnlyData](by-memory/0x00622d24-0x00622f54.QueueReconnectCopyReadOnlyData.md)

## Parent And Score Rationale

| Evidence group | Current assessment |
| --- | --- |
| Source module | [UID:0000MW][Queue](by-file/Queue.md) is `86/85`, has `PROPOSED_RECONSTRUCTION_PATH:"NexusTK/util/"`, and documents the compact fixed-slot utility source decision. |
| Executable aggregate | [UID:0001FN][0x005539e0-0x00553c07.Queue](by-memory/0x005539e0-0x00553c07.Queue.md) is `82/86` and already attached to `Queue.cpp`; its exact children cover constructor, ordinary destructor, raw write/read/empty helpers, and scalar deleting destructor. |
| Data evidence | [UID:000269][0x00622d24-0x00622f54.QueueReconnectCopyReadOnlyData](by-memory/0x00622d24-0x00622f54.QueueReconnectCopyReadOnlyData.md) confirms the compact `Queue` vtable at `0x00622d24` and keeps adjacent reconnect/copy-window data separate. |
| Remaining blockers | Raw write/read/empty helper starts are still not IDA-modeled functions and have no direct caller evidence; active generated output is incomplete; final names and header/source shape are below the final C++ gate. |

The class now meets the strict child and parent `85/85` gate and remains attached to [UID:0000MW][Queue](by-file/Queue.md). Reconstruction C++ remains blank because the raw-helper reachability and final declaration names are not near-final.

## Changes

- 2026-06-10 A002 strict-gate refresh:
  - What existed before: `COMPLETION:84`, `CONFIDENCE:82`, with `AUTOGEN_PARENT_UID:0000MW` retained from the older lower gate even though the current strict child and parent gates were not met.
  - Changed to: `COMPLETION:85`, `CONFIDENCE:85`, retaining direct parent `0000MW` after raising the by-file parent to `86/85`.
  - Summary/evidence: live IDA MCP reconfirmed the Queue vtable stores, modeled constructor/destructor/scalar-deleting destructor starts and sizes, raw write/read/empty not-a-function starts, no direct caller/xref evidence for the non-vtable Queue starts, constructor zero-allocation through `sub_5160D0`, destructor free paths through `MemoryMan`, corrected slot-size/slot-count layout, and padding boundaries around the compact cluster. Final C++ remains blank because raw helper names/signatures and active reachability are still not source-final.
- 2026-06-05: Changed `RECONSTRUCTABLE` from blank to `TRUE` and left `AUTOGEN_PARENT_UID` blank.
  - Before: The utility queue class remained unclassified in autogen coverage despite documented project-owned `LObject` inheritance, layout, and queue method cluster.
  - After: The page is reconstructable but unassigned because the class confidence score is below the 80/80 parent-attach gate.
  - Evidence: Live IDA MCP lookup confirms modeled functions at `0x005539e0`, `0x00553a60`, and `0x00553b70`; raw helper starts at `0x00553ac0`, `0x00553b10`, and `0x00553b60` remain not modeled as functions, matching the existing source-ownership caveat.

- 2026-05-30: Changed completion/confidence from `0/0` to `82/78`.
  - Before: The page was unevaluated though it already documented layout, method roles, corrected field naming, and memory cross-references.
  - After: Scored as high completion with medium-high confidence because active feature ownership remains less certain than the container implementation.
  - Evidence: Existing layout notes, 2026-05-26 IDA recheck, and method table cover the queue behavior while preserving generated-name caveats.
- 2026-06-06: Raised completion/confidence from `82/78` to `84/82` and attached the class to [UID:0000MW][Queue](by-file/Queue.md).
  - Before: The class stayed unassigned even though the file page and aggregate Queue memory page had since crossed the 80/80 gate.
  - Changed to: `AUTOGEN_PARENT_UID:0000MW`, added parent/score rationale, linked aggregate/read-only data evidence, and clarified that active generated output is incomplete rather than authoritative.
  - Evidence: [UID:0000MW][Queue](by-file/Queue.md) documents `NexusTK/util/Queue.cpp` at `84/80`, [UID:0001FN][0x005539e0-0x00553c07.Queue](by-memory/0x005539e0-0x00553c07.Queue.md) records the exact executable aggregate at `82/86`, and [UID:000269][0x00622d24-0x00622f54.QueueReconnectCopyReadOnlyData](by-memory/0x00622d24-0x00622f54.QueueReconnectCopyReadOnlyData.md) anchors the compact Queue vtable while preserving neighboring UI data boundaries.
