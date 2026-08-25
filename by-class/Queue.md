*** UID:0000BF | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:91 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000MW | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000MW | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
#include "Queue.h"
#include "MemoryMan.h"

[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
#pragma once

#include "LObject.h"

class Queue : public LObject
{
public:
    Queue(int slotSize, int slotCount);
    virtual ~Queue();

    void WriteSlot(const void *slot);
    void ReadSlot(void *slot);
    bool IsEmpty() const;

private:
    int m_slotSize;
    int m_slotCount;
    void *m_buffer;
    int m_readIndex;
    int m_writeIndex;
};

typedef char QueueSizeMustBe24[sizeof(Queue) == 0x18 ? 1 : -1];
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# Queue

## Status

- Confidence: very strong for the exact `0x18` layout, five source-authored declarations, class-owned `Queue.h`, CPP include/child wrapper, method source order, direct owner/emitter route, and compiler-generated scalar-wrapper exclusion; direct active-use evidence and original symbol spelling remain the confidence caps.
- Likely source file: [UID:0000MW][Queue](by-file/Queue.md)
- Address range: [UID:0001FN][0x005539e0-0x00553c07.Queue](by-memory/0x005539e0-0x00553c07.Queue.md)
- Formal source state: this class now owns the exact CPP wrapper and H declaration. The validator-owned generated baseline remains outside this callback and is read back separately under supervisor-owned CQM-036.

## Class Purpose

`Queue` is a small `LObject`-derived circular queue for fixed-size slots. The constructor takes slot size and slot count, allocates one contiguous zeroed buffer, and initializes read/write indices.

## Layout

```text
+0x00  LObject base / vptr
+0x04  int m_slotSize
+0x08  int m_slotCount
+0x0c  void *m_buffer
+0x10  int m_readIndex
+0x14  int m_writeIndex
```

Total source-facing size is exactly `0x18` bytes on x86. The H-channel size assertion makes this layout requirement explicit without importing any IDA-only padding names.

Historical generated output once labeled +0x04 as m_slotCount and +0x08 as m_slotSize. That reversal is superseded: IDA arithmetic and the current formal/generated source establish +0x04 as m_slotSize and +0x08 as m_slotCount.

The 2026-05-26 IDA recheck confirmed that the constructor stores a2 to this[1], a3 to this[2], and allocates a3 * a2 bytes. The raw write/read helpers independently establish +0x04 as the byte stride and +0x08 as the wrap limit; this evidence established the corrected layout above and superseded the historical reversed generated names.

[UID:0001FN][0x005539e0-0x00553c07.Queue](by-memory/0x005539e0-0x00553c07.Queue.md) now records the same layout at aggregate level, including exact child ranges, internal padding, raw helper boundary caveats, generated child-output state, remaining no-code/source-shape caveats, and `Queue.cpp` parent routing.

2026-06-10 A002 live IDA refresh confirms the class-level evidence still matches the documented layout: the constructor writes the vtable at `0x00553a15`, stores `a2` at `this[1]` and `a3` at `this[2]`, zero-allocates `a3 * a2` bytes through `sub_5160D0`, and clears `this[4]`/`this[5]`; the ordinary and scalar deleting destructors restore the same `Queue` vtable and free `this[3]` through `MemoryMan`; the raw write/read helpers use `+0x04` as copy stride and `+0x08` as wrap limit; and the compact empty helper compares `+0x10` against `+0x14`.

## Methods

| Address | Method | Role |
| --- | --- | --- |
| `0x005539e0` | [UID:0001FM][0x005539e0-0x00553a5c.QueueConstructor](by-memory/0x005539e0-0x00553a5c.QueueConstructor.md) | Now emits formal `Queue::Queue(int slotSize, int slotCount)`, expressing `LObject()` construction, `GetMemoryMan()->ZeroAllocateBufferMemory(slotSize * slotCount)`, and initialization of `m_slotSize`, `m_slotCount`, `m_buffer`, `m_readIndex`, and `m_writeIndex`; compiler emits the vtable store. |
| `0x00553a60` | [UID:0001FO][0x00553a60-0x00553ab9.QueueDestructor](by-memory/0x00553a60-0x00553ab9.QueueDestructor.md) | Now emits formal `Queue::~Queue()` through [UID:0000BF]; frees `m_buffer` through `GetMemoryMan()->FreeBufferMemory(m_buffer)` while compiler vtable/base cleanup stays out of the source body. |
| `0x00553ac0` | [UID:0001FP][0x00553ac0-0x00553b05.QueueWriteSlotRaw](by-memory/0x00553ac0-0x00553b05.QueueWriteSlotRaw.md) | Raw start; now emits inferred `Queue::WriteSlot(const void *slot)`, copying one fixed-size slot into the write position through `GetMemoryMan()->MemmoveWrapper` and advancing/wrapping `writeIndex`. |
| `0x00553b10` | [UID:0001FQ][0x00553b10-0x00553b55.QueueReadSlotRaw](by-memory/0x00553b10-0x00553b55.QueueReadSlotRaw.md) | Raw start; now emits inferred `Queue::ReadSlot(void *slot)`, copying one fixed-size slot out of the read position through `GetMemoryMan()->MemmoveWrapper` and advancing/wrapping `m_readIndex`. |
| `0x00553b60` | [UID:0001FR][0x00553b60-0x00553b6a.QueueIsEmptyRaw](by-memory/0x00553b60-0x00553b6a.QueueIsEmptyRaw.md) | Raw start; now emits inferred `Queue::IsEmpty() const`, returning whether `m_readIndex == m_writeIndex`. |
| `0x00553b70` | [UID:0001FS][0x00553b70-0x00553c07.QueueScalarDeletingDestructor](by-memory/0x00553b70-0x00553c07.QueueScalarDeletingDestructor.md) | Non-emitting compiler scalar deleting wrapper; source-level cleanup is covered by UID0001FO `Queue::~Queue()`, and the exact wrapper is regenerated from the virtual destructor/class layout rather than emitted as source. |

## Cross-References

- [UID:0000MW][Queue](by-file/Queue.md)
- [UID:0001QA][client_containers](by-meta/client_containers.md)
- [UID:0000L7][MemoryMan](by-file/MemoryMan.md)
- [UID:0001FN][0x005539e0-0x00553c07.Queue](by-memory/0x005539e0-0x00553c07.Queue.md)
- [UID:000269][0x00622d24-0x00622f54.QueueReconnectCopyReadOnlyData](by-memory/0x00622d24-0x00622f54.QueueReconnectCopyReadOnlyData.md)

## Parent And Score Rationale

| Evidence group | Current assessment |
| --- | --- |
| Source module | [UID:0000MW][Queue](by-file/Queue.md) is `91/91`, has `PROPOSED_RECONSTRUCTION_PATH:"NexusTK/util/"`, and records the complete fixed-slot utility source decision. |
| Executable aggregate | [UID:0001FN][0x005539e0-0x00553c07.Queue](by-memory/0x005539e0-0x00553c07.Queue.md) is `90/91` and routes through this direct class owner/emitter; its exact children cover constructor, ordinary destructor, raw write/read/empty helpers, scalar deleting destructor, and every internal padding span. |
| Data evidence | [UID:000269][0x00622d24-0x00622f54.QueueReconnectCopyReadOnlyData](by-memory/0x00622d24-0x00622f54.QueueReconnectCopyReadOnlyData.md) confirms the compact `Queue` vtable at `0x00622d24` and keeps adjacent reconnect/copy-window data separate. |
| Remaining confidence caps | Raw helper starts are still not IDA-modeled functions and have no direct caller evidence, the ordinary destructor has no direct caller/pointer route, and original method spelling is inferred. The exact declaration, wrapper, child order, and scalar-wrapper disposition are resolved; these caps do not leave a source-shape blocker. |

The class remains attached to [UID:0000MW][Queue](by-file/Queue.md) as the sole narrow declaration/method owner. Its formal CPP supplies only `Queue.h`, `MemoryMan.h`, and `[[CHILDREN]]`; exact method bodies remain on child pages at positions `10/20/30/40/50`. Its formal H supplies the one clean class declaration and exact size assertion. UID0001FS remains non-emitting compiler-generated scalar-wrapper support. Active-use proof and original spelling remain confidence limits, but the `Queue.h`/`Queue.cpp` source shape is complete.

## 2026-06-16 Evidence Refresh

Live IDA MCP was used to recheck the active runtime-use, raw-helper, and generated-output blockers:

- `lookup_funcs` still reports modeled starts for constructor `0x005539e0` size `0x7c` and scalar deleting destructor `0x00553b70` size `0x97`, while raw write/read/empty starts `0x00553ac0`, `0x00553b10`, and `0x00553b60` remain `Not a function`.
- The same lookup pass also reports the ordinary destructor `0x00553a60` as a modeled `0x59` function; no local `Queue` UDT/struct metadata was recovered through IDA type/struct queries.
- `xrefs_to` reports zero direct refs to the constructor and all three raw helpers; the deleting destructor is referenced only by the compact vtable/data slot at `0x00622d24`.
- `xrefs_to 0x00622d24` returns the constructor, ordinary destructor, and scalar deleting destructor vtable writes at `0x00553a15`, `0x00553a88`, and `0x00553b9f`.
- `callees` keeps the class behavior stable: the constructor calls `LObject`/allocation/zero-allocation support, the ordinary destructor calls free/teardown support, and the scalar deleting destructor adds conditional delete plus guard-check paths.
- VA/RVA pointer-byte scans found no direct stored references for the constructor, ordinary destructor, or raw helper starts; the expected scalar deleting destructor VA pointer appears only as the `Queue` vtable slot. Historical `simroot_v2/class_Queue.cpp` omitted the ordinary destructor and raw helpers; current validator-generated `auto-generated/NexusTK/util/Queue.cpp` emits the accepted constructor, ordinary destructor, and write/read/empty child bodies while class/aggregate pages remain blank route pages and UID0001FS is non-emitting compiler support.

The refreshed evidence supports the fixed-slot class ownership and corrected `slotSize`/`slotCount` layout, but it does not resolve active direct use or complete final `Queue.h`/`Queue.cpp` factoring. Those blockers are real and keep the class below higher final-C++ confidence.

2026-06-27 B013 source-quality implementation resolved the write helper's formal source body. Current MCP session `b001_000241_20260627` reconfirmed [UID:0001FP][0x00553ac0-0x00553b05.QueueWriteSlotRaw](by-memory/0x00553ac0-0x00553b05.QueueWriteSlotRaw.md) as a raw not-a-function start with exact 69-byte body, no xrefs, no VA/RVA pointer route, and no direct `E8/E9` route, but also confirmed the complete source-authored write-slot behavior: `GetMemoryMan()->MemmoveWrapper` copies the caller slot into `m_buffer + m_writeIndex * m_slotSize`, then the helper wraps or increments `m_writeIndex`. `WriteSlot` is an inferred source-facing name, not a recovered original symbol; `Raw`, `Write`, `Push`, `Enqueue`, `Append`, and raw `sub_553AC0` were rejected on the child page.

2026-06-27/2026-06-28 B013 source-quality implementation resolves the read helper's formal source body. The same MCP session `b001_000241_20260627` reconfirmed [UID:0001FQ][0x00553b10-0x00553b55.QueueReadSlotRaw](by-memory/0x00553b10-0x00553b55.QueueReadSlotRaw.md) as a raw not-a-function start with decompile failure, exact 69-byte body, `c2 04 00` `retn 4`, eleven-byte pre/post padding, no xrefs/callers/callee route, no VA/RVA pointer route, no direct local PE `E8/E9` route, and no recovered Queue UDT or candidate method symbols. The body copies from `m_buffer + m_readIndex * m_slotSize` into the caller destination through `GetMemoryMan()->MemmoveWrapper`, then wraps or increments `m_readIndex`. `ReadSlot` is an inferred source-facing name, not a recovered original symbol; `QueueReadSlotRaw`, `Queue::Read`, `Queue::Pop`, `Queue::Dequeue`, `Queue::Get`, raw `sub_553B10`, no-code, metadata fallback, and owner/emitter fallback were rejected on the child page.

2026-06-27/2026-06-28 B003 source-quality implementation resolves the empty helper's formal source body. The same MCP session `b001_000241_20260627` reconfirmed [UID:0001FR][0x00553b60-0x00553b6a.QueueIsEmptyRaw](by-memory/0x00553b60-0x00553b6a.QueueIsEmptyRaw.md) as a raw not-a-function start with decompile failure, exact ten-byte body `8b 41 10 3b 41 14 0f 94 c0 c3`, eleven-byte pre-padding, six-byte post-padding, unique exact signature, no xrefs/callee route, no VA/RVA pointer route, no direct local PE `E8/E9` route, no recovered Queue UDT/type, and no candidate method symbols. The body returns the equality predicate `m_readIndex == m_writeIndex`, matching constructor/write/read field layout. `IsEmpty` is an inferred source-facing name, not a recovered original symbol; `QueueIsEmptyRaw`, `Queue::Empty`, `Queue::empty`, `Queue::CanRead`, `Queue::HasData`, `Queue::IsFull`, raw `sub_553B60`, no-code, covered-by, metadata fallback, and owner/emitter fallback were rejected on the child page.

## 2026-08-11 Whole-File Ownership And Source Reconciliation

- Ownership: UID0000BF is the only class declaration and method owner. `CANONICAL_OWNER:0000MW` links that semantic owner to the UID0000MW source root, while `EMITTER_UIDS:0000MW` routes both formal channels to `NexusTK/util/Queue.cpp` and its generated sibling `Queue.h`. The file page does not duplicate the class declaration, and aggregate UID0001FN remains a no-code range/index support page.
- Source order: CPP includes `Queue.h` then `MemoryMan.h`, followed by child positions `10` constructor, `20` ordinary destructor, `30` `WriteSlot`, `40` `ReadSlot`, and `50` `IsEmpty`. No scalar-wrapper, vtable, RTTI, or alignment source is hand-authored.
- Header contract: H includes only `LObject.h`; declares `Queue(int,int)`, virtual `~Queue()`, `WriteSlot`, `ReadSlot`, and const `IsEmpty`; records fields at `+0x04/+0x08/+0x0c/+0x10/+0x14`; and asserts total size `0x18`. Method-child H channels remain blank to prevent duplicate declarations.
- Reachability: direct xrefs/callers and stored-pointer searches remain empty for constructor, ordinary destructor, and raw helpers. The scalar wrapper is referenced only by vtable slot `0x00622d24`, and constructor/destructor/scalar lowering write that vtable. The accepted whole-file classification is 90 percent dormant and 10 percent unresolved indirect/external route.
- Historical reconciliation: generated-name reversal of slot size/count and former statements that this class must keep blank formal channels are superseded. Older dated evidence remains useful history. Stale Wave2/Wave3 material was ignored, and the unrelated `BlackHole *` cleanup global remains excluded.

## Queue Support-Only UID And Destination Inventory

The UID0000BF class owner has exactly the following eleven support-only UIDs in the accepted UID0000MW whole-file graph. The formal CPP/H above remain solely on this page; the table routes executable bodies and compiler-data evidence without creating duplicate declaration or byte ownership.

| Support UID | Exact physical destination and range | Relationship to UID0000BF and formal-source disposition |
| --- | --- | --- |
| `0000BF` | `by-class/Queue.md`; `0x18` source-facing class and semantic method set. | This page is the sole declaration/method owner. Exact CPP wrapper and H declaration remain here and emit through UID0000MW. |
| `0001FN` | `by-memory/0x005539e0-0x00553c07.Queue.md`; aggregate `0x005539e0-0x00553c07`. | Complete executable/padding index routed through this class. Blank aggregate CPP/H avoids duplicating child bodies or class declarations. |
| `0001FM` | `by-memory/0x005539e0-0x00553a5c.QueueConstructor.md`; `0x005539e0-0x00553a5c`. | Source-authored constructor body, CPP child position `10`; declaration stays in this H channel. |
| `0001FO` | `by-memory/0x00553a60-0x00553ab9.QueueDestructor.md`; `0x00553a60-0x00553ab9`. | Source-authored ordinary destructor body, CPP child position `20`; declaration stays in this H channel. |
| `0001FP` | `by-memory/0x00553ac0-0x00553b05.QueueWriteSlotRaw.md`; `0x00553ac0-0x00553b05`. | Source-authored inferred `WriteSlot` body, CPP child position `30`; raw IDA boundary is preserved and the declaration stays here. |
| `0001FQ` | `by-memory/0x00553b10-0x00553b55.QueueReadSlotRaw.md`; `0x00553b10-0x00553b55`. | Source-authored inferred `ReadSlot` body, CPP child position `40`; raw IDA boundary is preserved and the declaration stays here. |
| `0001FR` | `by-memory/0x00553b60-0x00553b6a.QueueIsEmptyRaw.md`; `0x00553b60-0x00553b6a`. | Source-authored inferred const `IsEmpty` body, CPP child position `50`; raw IDA boundary is preserved and the declaration stays here. |
| `0001FS` | `by-memory/0x00553b70-0x00553c07.QueueScalarDeletingDestructor.md`; `0x00553b70-0x00553c07`. | Non-emitting compiler scalar wrapper regenerated from this page's virtual destructor. No separate CPP/H payload. |
| `0003CS` | `by-memory/0x00622d24-0x00622d30.QueueVtableData.md`; vtable `0x00622d24-0x00622d30`. | Exact generated-data evidence owned/emitted by this class. Its blank CPP/H is mandatory because the compiler regenerates the table from this declaration. |
| `0003DH` | `by-memory/0x00622d20-0x00622d24.QueueRttiBoundary.md`; COL pointer boundary `0x00622d20-0x00622d24`, indexing remote RTTI `0x0064e924-0x0064e970` and `0x00678b18-0x00678b2c`. | Parentless, non-reconstructable compiler-data index. Queue class identity is expressed by this clean declaration, not by emitting COL/CHD/BCA/BCD/type-descriptor/class-name bytes. |
| `000269` | `by-memory/0x00622d24-0x00622f54.QueueReconnectCopyReadOnlyData.md`; mixed range `0x00622d24-0x00622f54`. | Parentless, non-reconstructable exact-child index. Only UID0003CS is Queue class data; all subsequent dialog/window/string children are excluded from this class. |

The code-page caller/callee and allocation/free evidence remains on UID0001FM through UID0001FS. UID0003CS now records each vtable cell's caller/xref/read/write/image-lifetime state, UID0003DH records each reachable Queue RTTI item and `.?AVQueue@@` overlap, and UID000269 records the mixed-range boundaries. These are evidence destinations, not additional class/source emitters.

## Changes

- 2026-08-11 B010 Gate 2A incorporation repair:
  - Preserved the exact accepted CPP/H blocks, `91/92` score, owner/emitter/reconstructability metadata, layout, source order, and reachability evidence.
  - Added the complete eleven-UID physical support inventory and exact evidence/source routing required by CQM-018, without duplicating declarations or changing formal output.
- 2026-08-11 B010 accepted whole-file documentation callback:
  - What existed before: `COMPLETION:86`, `CONFIDENCE:86`, correct owner/emitter routing and five valid child bodies, but blank class CPP/H and stale current prose treating the header/source envelope as unresolved.
  - Changed to: `COMPLETION:91`, `CONFIDENCE:92`; retained `CANONICAL_OWNER:0000MW`, `RECONSTRUCTABLE:TRUE`, and `EMITTER_UIDS:0000MW`; inserted the accepted exact CPP wrapper and clean H declaration; added the exact layout, source order, reachability, ownership, negative-evidence, and historical reconciliation.
  - Summary/evidence: the complete UID0000MW whole-file census, seven child reports, exact vtable/RTTI and padding evidence, current owner/emitter graph, and accepted Rule 26 CQM-022 through CQM-024/CQM-035 disposition.
- 2026-07-07 B011 scalar-wrapper support sync:
  - What existed before: the class page already described UID0001FS as compiler-wrapper/no-code, but status/generated-output and remaining-blocker wording still treated the wrapper as an empty marker or unresolved no-code source-output issue.
  - Changed to: UID0001FS is recorded as non-emitting compiler-generated scalar-wrapper support generated from the virtual destructor; UID0001FO remains the source-level `Queue::~Queue()` body; class metadata and blank formal C++ are unchanged.
  - Summary/evidence: accepted B011 report and MCP session `43ccf853` confirmed UID0001FS exact wrapper range, vtable-only xref, Queue vtable writes, cleanup/delete callees, delete-flag ABI behavior, object-size immediate `0x18`, no Queue UDT/source method symbols, and stale pre-callback generated empty-marker state. Remaining class caps are active-use proof, exact original `Queue.h` spelling, and broader full-source factoring.
- 2026-07-04 B014 constructor implementation:
  - What existed before: the class page treated [UID:0001FM][0x005539e0-0x00553a5c.QueueConstructor](by-memory/0x005539e0-0x00553a5c.QueueConstructor.md) as an empty constructor/source-factoring caveat while ordinary destructor/write/read/empty already emitted.
  - Changed to: UID0001FM is documented as source-ready formal `Queue::Queue(int slotSize, int slotCount)` emitted through [UID:0000BF] into [UID:0000MW][Queue](by-file/Queue.md). Class-level C++ remains blank as the inventory/route page.
  - Summary/evidence: B014 accepted report and MCP session `eb7ce28b` confirmed exact `0x7c` constructor range, `LObject` base construction, Queue vtable store as compiler output, `GetMemoryMan()->ZeroAllocateBufferMemory(slotSize * slotCount)`, field initialization, no direct constructor xrefs/callers/VA-RVA route, no recovered Queue UDT/type/source method symbols, and rejected MemoryMan/LObject/no-owner/aggregate/class/file-emission/raw-name/plain-allocation alternatives. Remaining class caps are active-use proof and exact original `Queue.h` spelling; UID0001FS compiler-wrapper handling is resolved by the 2026-07-07 B011 sync.
- 2026-07-04 B006 ordinary-destructor implementation:
  - What existed before: the class page treated [UID:0001FO][0x00553a60-0x00553ab9.QueueDestructor](by-memory/0x00553a60-0x00553ab9.QueueDestructor.md) as an empty/final-blocked child while write/read/empty already emitted.
  - Changed to: UID0001FO is documented as source-ready formal `Queue::~Queue()` emitted through [UID:0000BF] into [UID:0000MW][Queue](by-file/Queue.md). Class-level C++ remains blank as the inventory/route page.
  - Summary/evidence: B006 accepted report and MCP session `eb7ce28b` confirmed exact `0x59` destructor range, byte/padding facts, `m_buffer` free through `GetMemoryMan()->FreeBufferMemory`, zero direct ordinary-destructor xrefs/pointer/direct-transfer route, positive scalar-wrapper/vtable controls, and rejected raw/decompiler/scalar-wrapper/aggregate/no-owner alternatives. Remaining class caps are active-use proof and constructor/header factoring; UID0001FS compiler-wrapper handling is resolved by the 2026-07-07 B011 sync.
- 2026-06-27/2026-06-28 B003 empty-helper implementation:
  - What existed before: the class page treated [UID:0001FR][0x00553b60-0x00553b6a.QueueIsEmptyRaw](by-memory/0x00553b60-0x00553b6a.QueueIsEmptyRaw.md) as a raw-helper source-output blocker after write/read were already resolved.
  - Changed to: [UID:0001FR][0x00553b60-0x00553b6a.QueueIsEmptyRaw](by-memory/0x00553b60-0x00553b6a.QueueIsEmptyRaw.md) now uses inferred `Queue::IsEmpty() const` and emits formal child C++; class-level C++ remains blank, with remaining caveats limited to raw no-route/active-use/header and broader constructor/destructor/source factoring work.
  - Summary/evidence: B003 current MCP evidence confirmed exact empty-predicate body, Queue field layout, raw not-a-function/decompile-failure state, no xrefs/callee/pointer/direct-route evidence, no recovered source symbol, no local Queue UDT/type record, and rejected source-name/no-code/metadata alternatives. The class score remains `86/86`.
- 2026-07-02 B013 aggregate verification:
  - Support verification found no required class score or ownership change. Current target aggregate [UID:0001FN][0x005539e0-0x00553c07.Queue](by-memory/0x005539e0-0x00553c07.Queue.md) is `87/89` with blank aggregate C++ by explicit no-code proof; class-level C++ also remains blank because this page is the class inventory/route. The 2026-07-02 generated state was later superseded by constructor/destructor callbacks and this B011 scalar-wrapper sync: current validation is expected to emit UID0001FM/UID0001FO/UID0001FP/UID0001FQ/UID0001FR child bodies, keep class/aggregate pages blank route pages, and omit UID0001FS as non-emitting compiler support.
- 2026-06-27/2026-06-28 B013 read-slot implementation:
  - What existed before: the class page treated [UID:0001FQ][0x00553b10-0x00553b55.QueueReadSlotRaw](by-memory/0x00553b10-0x00553b55.QueueReadSlotRaw.md) and [UID:0001FR][0x00553b60-0x00553b6a.QueueIsEmptyRaw](by-memory/0x00553b60-0x00553b6a.QueueIsEmptyRaw.md) together as raw-helper source-output blockers.
  - Changed to at that time: [UID:0001FQ][0x00553b10-0x00553b55.QueueReadSlotRaw](by-memory/0x00553b10-0x00553b55.QueueReadSlotRaw.md) began using inferred `Queue::ReadSlot(void *slot)` and emitted formal child C++; class-level C++ remained blank, while [UID:0001FR][0x00553b60-0x00553b6a.QueueIsEmptyRaw](by-memory/0x00553b60-0x00553b6a.QueueIsEmptyRaw.md), constructor/destructor/header factoring, and active-use proof remained caveats. The empty helper is now resolved by the later B003 implementation above.
  - Summary/evidence: B013 current MCP evidence confirmed exact read-slot copy-out/wrap behavior, MemoryMan helper calls, Queue field layout, no raw-start xrefs/pointer/direct-route evidence, no recovered source symbol, no local Queue UDT, and rejected source-name/no-code/metadata alternatives. The class score remains `86/86`.
- 2026-06-27 B013 write-slot implementation:
  - What existed before: the class page treated all raw helper source names and source output as unresolved.
  - Changed to at that time: [UID:0001FP][0x00553ac0-0x00553b05.QueueWriteSlotRaw](by-memory/0x00553ac0-0x00553b05.QueueWriteSlotRaw.md) began using inferred `Queue::WriteSlot(const void *slot)` and emitted formal child C++; class-level C++ remained blank, while [UID:0001FQ][0x00553b10-0x00553b55.QueueReadSlotRaw](by-memory/0x00553b10-0x00553b55.QueueReadSlotRaw.md) and [UID:0001FR][0x00553b60-0x00553b6a.QueueIsEmptyRaw](by-memory/0x00553b60-0x00553b6a.QueueIsEmptyRaw.md) still needed follow-up source-output decisions.
  - Summary/evidence: B013 current MCP evidence confirmed exact write-slot copy/wrap behavior, MemoryMan helper calls, Queue field layout, no raw-start xrefs/pointer/direct-route evidence, and no recovered source symbol. The class score remained `86/86`; the read helper is now resolved by the later B013 read-slot implementation and the empty helper by the later B003 implementation above, while broader raw-helper reachability, active use, and header factoring remain unresolved.
- 2026-06-16 A002 Goal2 class-confidence refresh:
  - Before: `COMPLETION:85`, `CONFIDENCE:85`.
  - After: `COMPLETION:86`, `CONFIDENCE:86`; owner and emitter remain [UID:0000MW][Queue](by-file/Queue.md).
  - Evidence: live IDA MCP reconfirmed modeled constructor/destructor starts, raw write/read/empty non-function status, zero direct refs to constructor/raw helpers, the vtable-only deleting-destructor reference, vtable writes at `0x00553a15`, `0x00553a88`, and `0x00553b9f`, constructor/destructor memory-manager callees, no local `Queue` UDT, no non-vtable VA/RVA pointer-byte hits, and the then-current generated state that is now superseded for write/read/empty by the accepted child bodies. The score only moves modestly because active runtime callers, exact original source names, and final header/source factoring remain unresolved.
- 2026-06-10 A002 strict-gate refresh:
  - What existed before: `COMPLETION:84`, `CONFIDENCE:82`, with `AUTOGEN_PARENT_UID:0000MW` retained from the older lower gate even though the current strict child and parent gates were not met.
  - Changed to: `COMPLETION:85`, `CONFIDENCE:85`, retaining direct parent `0000MW` after raising the by-file parent to `86/85`.
  - Summary/evidence: live IDA MCP reconfirmed the Queue vtable stores, modeled constructor/destructor/scalar-deleting destructor starts and sizes, raw write/read/empty not-a-function starts, no direct caller/xref evidence for the non-vtable Queue starts, constructor zero-allocation through `sub_5160D0`, destructor free paths through `MemoryMan`, corrected slot-size/slot-count layout, and padding boundaries around the compact cluster. Class-level final C++ remained blank at that time because raw helper names/signatures and active reachability were not source-final; later child-level implementations now emit write/read/empty bodies.
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
  - Changed to: `AUTOGEN_PARENT_UID:0000MW`, added parent/score rationale, linked aggregate/read-only data evidence, and clarified that the then-active generated output was incomplete rather than authoritative.
  - Evidence: at that time, [UID:0000MW][Queue](by-file/Queue.md) documented `NexusTK/util/Queue.cpp` at `84/80`, [UID:0001FN][0x005539e0-0x00553c07.Queue](by-memory/0x005539e0-0x00553c07.Queue.md) recorded the exact executable aggregate at `82/86`, and [UID:000269][0x00622d24-0x00622f54.QueueReconnectCopyReadOnlyData](by-memory/0x00622d24-0x00622f54.QueueReconnectCopyReadOnlyData.md) anchored the compact Queue vtable while preserving neighboring UI data boundaries; current UID0001FN aggregate score is `87/89` after the 2026-07-02 callback.
