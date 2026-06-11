*** UID:0000MW | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:85 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"NexusTK/util/" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***

# Queue

## Status

- Confidence: strong for class behavior, compact source ownership, vtable/data boundary, and `Queue.cpp` routing; medium-high for active direct caller reachability.
- Proposed module: `util/Queue.cpp`
- Current generated source: `source-3/simroot_v2/class_Queue.cpp`
- Main address range: [UID:0001FN][0x005539e0-0x00553c07.Queue](by-memory/0x005539e0-0x00553c07.Queue.md)

## File Role

`Queue` is a fixed-slot, fixed-element-size circular queue derived from `LObject`. It allocates `slotCount * slotSize` bytes through the client memory manager, tracks read and write indices, and exposes small push/pop/empty helpers.

Active generated output emits only the constructor and scalar deleting destructor. IDA disassembly shows the full compact cluster also includes the ordinary destructor, enqueue, dequeue, and empty-test helpers.

2026-05-26 recheck using current `simroot_v2` and IDA MCP only: active `class_Queue.cpp` still emits only `0x005539e0` and `0x00553b70`. IDA still models `0x005539e0`, `0x00553a60`, and `0x00553b70` as functions, while `0x00553ac0`, `0x00553b10`, and `0x00553b60` remain raw not-a-function starts with no direct callers.

2026-05-31 IDA MCP recheck: `0x005539e0-0x00553a5c`, `0x00553a60-0x00553ab9`, and `0x00553b70-0x00553c07` remain modeled functions. The raw helper starts at `0x00553ac0`, `0x00553b10`, and `0x00553b60` still decode as queue-style fixed-slot write/read/empty bodies but are not IDA function starts and have no modeled direct callers. This keeps `Queue.cpp` a plausible utility source module but keeps confidence below final/original-source level.

2026-06-10 A002 live IDA gate refresh: `lookup_funcs` still reports modeled starts at `0x005539e0` size `0x7c`, `0x00553a60` size `0x59`, and `0x00553b70` size `0x97`; it still reports `0x00553ac0`, `0x00553b10`, and `0x00553b60` as not function starts. `callers`/`xrefs_to` remain empty for the constructor, ordinary destructor, and raw write/read/empty starts, while the scalar deleting destructor has the expected vtable data xref from `0x00622d24`. `xrefs_to 0x00622d24` still shows vtable stores from constructor `0x00553a15`, ordinary destructor `0x00553a88`, and scalar deleting destructor `0x00553b9f`. `get_bytes` confirms the `0xcc` alignment spans around each child, and the constructor decompile shows `this[3] = sub_5160D0(a3 * a2)`, proving the backing buffer is zero-allocated through the MemoryMan zero-allocation helper.

## Proposed Contents

| Range | Role |
| --- | --- |
| `0x005539e0-0x00553a5c` | [UID:0001FM][0x005539e0-0x00553a5c.QueueConstructor](by-memory/0x005539e0-0x00553a5c.QueueConstructor.md). IDA arithmetic shows first argument is slot size and second argument is slot count. |
| `0x00553a60-0x00553ab9` | [UID:0001FO][0x00553a60-0x00553ab9.QueueDestructor](by-memory/0x00553a60-0x00553ab9.QueueDestructor.md). |
| `0x00553ac0-0x00553b05` | [UID:0001FP][0x00553ac0-0x00553b05.QueueWriteSlotRaw](by-memory/0x00553ac0-0x00553b05.QueueWriteSlotRaw.md). Writes one fixed-size element at `writeIndex` and advances with wraparound. |
| `0x00553b10-0x00553b55` | [UID:0001FQ][0x00553b10-0x00553b55.QueueReadSlotRaw](by-memory/0x00553b10-0x00553b55.QueueReadSlotRaw.md). Reads one fixed-size element from `readIndex` and advances with wraparound. |
| `0x00553b60-0x00553b6a` | [UID:0001FR][0x00553b60-0x00553b6a.QueueIsEmptyRaw](by-memory/0x00553b60-0x00553b6a.QueueIsEmptyRaw.md). Returns whether read and write indices match. |
| `0x00553b70-0x00553c07` | [UID:0001FS][0x00553b70-0x00553c07.QueueScalarDeletingDestructor](by-memory/0x00553b70-0x00553c07.QueueScalarDeletingDestructor.md). |

## Source-Structure Decision

Keep `Queue` under reusable utility/container ownership unless later caller evidence proves it is dead legacy code or private to one subsystem. Its vtable and `LObject` base make it a project class, not an STL artifact.

The 2026-06-10 strict-gate refresh raises this source-root page to `86/85`, which is enough for the existing [UID:0000BF][Queue](by-class/Queue.md) class child and the exact Queue memory children to remain attached under the current `85/85` rule. The score is not higher because no direct callers are currently modeled for the constructor, ordinary destructor, or raw helper starts, and the final `Queue.h` method names/signatures remain source-quality TODOs.

## Cross-References

- [UID:0000BF][Queue](by-class/Queue.md)
- [UID:0001FN][0x005539e0-0x00553c07.Queue](by-memory/0x005539e0-0x00553c07.Queue.md)
- [UID:0001QA][client_containers](by-meta/client_containers.md)
- [UID:0000L7][MemoryMan](by-file/MemoryMan.md)

## Changes

- 2026-06-10 A002 strict-gate refresh:
  - What existed before: `COMPLETION:84`, `CONFIDENCE:80`; the page was useful but did not clear the current parent confidence gate for the Queue class/memory children already routed through it.
  - Changed to: `COMPLETION:86`, `CONFIDENCE:85`.
  - Summary/evidence: live IDA MCP reconfirmed modeled constructor/destructor/scalar-deleting destructor bounds, raw not-a-function write/read/empty helper starts, empty caller/xref sets for the non-vtable Queue starts, the scalar deleting destructor vtable xref, `Queue` vtable stores at `0x00553a15`, `0x00553a88`, and `0x00553b9f`, alignment bytes around all children, destructor/free callees, and constructor zero-allocation through `sub_5160D0`. Confidence remains capped at 85 because active direct-use evidence and final source names/signatures are still unresolved.
- Before: completion/confidence were ungraded at `0/0`.
- Changed to: completion `82`, confidence `76`.
- Summary/evidence: the page documents fixed-slot queue role, compact function cluster, raw helper starts, source-structure decision, active generated omissions, and cross-references; confidence remains capped by uncertain active runtime use and raw not-a-function helper treatment.
- What existed before: `PROPOSED_RECONSTRUCTION_PATH` was blank.
- What it was changed to: `NexusTK/util/`.
- Summary/evidence: `by-project-structure/proposed-source-tree.md` already places `Queue.cpp` under `util/`, and the 2026-05-31 IDA MCP pass confirms the queue cluster is project utility/container code rather than a feature-specific source file.
- 2026-06-01: Raised completion/confidence from `82/76` to `84/80`.
  - Evidence: IDA MCP raw byte review corrected the write/read helper endpoints to `0x00553b05` and `0x00553b55`, confirmed the internal padding spans, and reconfirmed the queue-owned slot-size/slot-count/read-index/write-index behavior. Confidence remains capped at `80` because raw helper starts still have no modeled direct callers.
