*** UID:0000C1 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000N8 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000N8 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL:10 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
#include "RingBuffer.h"

#include "MemoryMan.h"
#include "Monitor.h"
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
#pragma once

#include "LObject.h"

class Monitor;
class MonitorCondition;
class RingBufferIterator;

class RingBuffer : public LObject
{
    friend class RingBufferIterator;

public:
    RingBuffer(int elementSize, int capacity);
    virtual ~RingBuffer();

    void Enqueue(const void *record);
    void Dequeue(void *record);
    bool IsEmpty() const;
    bool IsFull() const;
    void Lock();
    void Unlock();
    bool Empty() const;
    bool Full() const;

private:
    Monitor *mMonitor;
    MonitorCondition *mNotFull;
    MonitorCondition *mNotEmpty;
    int mElementSize;
    int mCapacity;
    unsigned char *mStorage;
    int mCount;
    int mReadIndex;
    int mWriteIndex;
};
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# RingBuffer

## Class Purpose

`RingBuffer` is a 0x28-byte blocking fixed-element circular queue that publicly and non-virtually derives from `LObject` at offset zero. It owns raw storage, read/write/count fields, one [UID:00008L][Monitor](by-class/Monitor.md), and two [UID:00008M][MonitorCondition](by-class/MonitorCondition.md) objects for not-empty and not-full waits. Construction caches `GetMemoryMan()` and zero-allocates the raw element buffer through `MemoryMan::ZeroAllocateBufferMemory`; destruction guards that pointer, frees it through `MemoryMan::FreeBufferMemory`, clears it, then deletes and clears not-empty, not-full, and monitor objects in reverse acquisition order. This allocation/deallocation symmetry is part of the class ownership contract and rejects `new[]`/`delete[]` source drafts.

[UID:0000C2][RingBufferIterator](by-class/RingBufferIterator.md) is the same-file companion and receives friend access to the private queue state used by the accepted iterator bodies.

## Likely Original Placement

- Source: [UID:0000N8][RingBuffer](by-file/RingBuffer.md)
- Reconstruction paths: declaration in `NexusTK/util/RingBuffer.h`; include preamble in `NexusTK/util/RingBuffer.cpp` at position `10`, before independently positioned qualified method definitions.
- Header dependency route: `RingBuffer.h` includes complete base declaration `"LObject.h"` and forward-declares `Monitor`, `MonitorCondition`, and `RingBufferIterator`; `RingBuffer.cpp` includes `"RingBuffer.h"`, `"MemoryMan.h"`, and `"Monitor.h"` because its definitions call and construct those complete types.
- Confidence: very strong for behavior, exact 0x28 layout, public zero-offset `LObject` inheritance, virtual destructor lowering, Thread use, vtable identity, direct file ownership, and companion relationship. Exact original private/friend/header token spelling remains inferred and caps confidence below 95.

## Method Inventory

| Range | Role |
| --- | --- |
| [UID:0004EN][0x005563d0-0x005564d4.RingBufferConstructor](by-memory/0x005563d0-0x005564d4.RingBufferConstructor.md) | Constructor: caches MemoryMan, constructs monitor/not-full/not-empty, stores dimensions, zero-allocates raw storage, and clears count/read/write. |
| [UID:0004EO][0x005564e0-0x00556579.RingBufferCleanupBody](by-memory/0x005564e0-0x00556579.RingBufferCleanupBody.md) | Ordinary `RingBuffer::~RingBuffer()` definition: guarded MemoryMan storage free, explicit clear, reverse synchronization teardown, and implicit compiler base/vptr work. |
| [UID:0004EP][0x00556580-0x005565ec.RingBufferEnqueue](by-memory/0x00556580-0x005565ec.RingBufferEnqueue.md) | Enqueue: blocks while full, copies one element, signals not-empty. |
| [UID:0004EQ][0x005565f0-0x0055665a.RingBufferDequeue](by-memory/0x005565f0-0x0055665a.RingBufferDequeue.md) | Dequeue: blocks while empty, copies one element, signals not-full. |
| [UID:0004ER][0x00556660-0x00556668.RingBufferIsEmpty](by-memory/0x00556660-0x00556668.RingBufferIsEmpty.md) | Empty-test helper; returns `count <= 0`. |
| [UID:0004ES][0x00556670-0x0055667a.RingBufferIsFullRawPredicate](by-memory/0x00556670-0x0055667a.RingBufferIsFullRawPredicate.md) | Raw full predicate; no IDA function object; exact ten-byte `capacity <= count` body, no incoming route, and duplicate-only relation with UID0004EW. |
| [UID:0004ET][0x00556680-0x00556688.RingBufferLock](by-memory/0x00556680-0x00556688.RingBufferLock.md) | Lock wrapper: forwards through the owned `Monitor`. |
| [UID:0004EU][0x00556690-0x00556698.RingBufferUnlock](by-memory/0x00556690-0x00556698.RingBufferUnlock.md) | Unlock wrapper: forwards through the owned `Monitor`. |
| [UID:0004EV][0x005566a0-0x005566a8.RingBufferEmptyPredicateAlias](by-memory/0x005566a0-0x005566a8.RingBufferEmptyPredicateAlias.md) | Raw empty predicate alias; no IDA function object. |
| [UID:0004EW][0x005566b0-0x005566ba.RingBufferFullPredicateAlias](by-memory/0x005566b0-0x005566ba.RingBufferFullPredicateAlias.md) | Raw full predicate alias; no IDA function object; duplicates UID0004ES `capacity <= count` bytes and keeps inferred `Full()` naming. |
| [UID:0004F5][0x005567b0-0x00556887.RingBufferScalarDeletingDestructor](by-memory/0x005567b0-0x00556887.RingBufferScalarDeletingDestructor.md) | Scalar deleting destructor wrapper; vtable-only reachability. |

## Layout

Constructor/method offset use, the 0x28 delete-size immediate, and the accepted source children close this field map without raw-layout scaffolding or tail padding:

| Offset | Source member/type | Evidence |
| --- | --- | --- |
| `+0x00` | public `LObject` base / primary vptr | RTTI PMD `(0,-1,0)`, attributes `0x40`, and all lifecycle stores prove public, unambiguous, non-virtual inheritance at offset zero. |
| `+0x04` | `Monitor *mMonitor` | Constructor allocates it; lock/unlock wrappers call through it. |
| `+0x08` | `MonitorCondition *mNotFull` | Enqueue waits here when full; dequeue signals it after removal. |
| `+0x0c` | `MonitorCondition *mNotEmpty` | Dequeue waits here when empty; enqueue signals it after insertion. |
| `+0x10` | `int mElementSize` | Constructor stores it; storage offsets multiply by it. |
| `+0x14` | `int mCapacity` | Constructor stores it; full predicates and iterator wrap use it. |
| `+0x18` | `unsigned char *mStorage` | Constructor allocates it; enqueue/dequeue/iterator helpers index into it. |
| `+0x1c` | `int mCount` | Empty/full predicates and enqueue/dequeue update it. |
| `+0x20` | `int mReadIndex` | Dequeue and iterator reset/read-boundary helpers use it. |
| `+0x24` | `int mWriteIndex` | Enqueue and iterator advance/end helpers use it. |

The 4-byte base plus nine 4-byte members ends exactly at `+0x28`; there is no unexplained interior or tail padding. Field spellings are source-facing inferences, while order, width, signed index/count semantics, pointer categories, and behavior are binary-backed. Private fields plus `friend class RingBufferIterator` are the narrowest plausible human-written access model for direct iterator field reads; public data is behaviorally possible but lower quality and not selected.

## Destructor ABI And Vtable Evidence

IDA confirms `??_7RingBuffer@@6B@` at `0x006230cc`, with constructor/source-destructor/scalar-wrapper stores at `0x00556408`, `0x00556508`, and `0x005567df`. The COL at `0x0064edb8`, type descriptor `0x00678cac`, two-entry CHD/base array, derived PMD `(0,-1,0)`, and shared `LObject` BCD prove one primary public base and no adjustor. Slot `+0x00` is compiler scalar deleting wrapper `0x005567b0`; slot `+0x04` is inherited `LObject::GetRuntimeClass()` at `0x004f4b10`; slot `+0x08` is inherited `LObject::OnChangeMessage(LObject *, Message *)` at `0x0041b6c0`. The exact base addresses prove that neither inherited slot is overridden.

The distinct ordinary source destructor at `0x005564e0`, size 0x99 / 153, restores this vptr, releases MemoryMan-backed storage, deletes not-empty/not-full/monitor in reverse order, and calls the base destructor. Its source ABI has no deleting-flags argument. Wrapper `0x005567b0`, size 0xd7 / 215, has only its table reference, duplicates the corrected cleanup, tests unsigned delete flags, and conditionally deletes the exact `0x28`-byte object; R1 therefore declares `virtual ~RingBuffer()` but emits no deleting wrapper. The vptr restore, implicit `LObject::~LObject()` call, EH/cookie scaffolding, wrapper flags, and wrapper object-delete call are compiler lowering, not handwritten class methods. See [UID:0001YN][RingBufferVtables](by-type/by-vtable/RingBufferVtables.md). The next dword after the three slots is the iterator COL, not a fourth RingBuffer slot.

## Evidence

- `Thread::Thread` constructs two `RingBuffer` instances for message queues.
- `Thread::StopThread`, sync send, async post, and sync post helpers call enqueue.
- `Thread::ThreadProc` calls dequeue.
- Constructor calls `Monitor::Monitor` and `MonitorCondition::MonitorCondition` twice.
- 2026-05-26 IDA `py_eval` recheck confirmed modeled function starts at `0x005563d0`, `0x005564e0`, `0x00556580`, `0x005565f0`, `0x00556660`, `0x00556680`, `0x00556690`, `0x005567b0`, and the iterator helpers at `0x005566f0`, `0x00556720`, and `0x00556890`.
- Historical `source-3/simroot_v2/util/RingBuffer.meta_wave3` reported the `RingBuffer` vtable at `0x006230cc` and the `RingBufferIterator` vtable at `0x006230dc`. Current conclusions instead use live IDA and exact ordinary documentation.
- 2026-06-01 IDA MCP recheck confirmed direct Thread callers to constructor/enqueue/dequeue/empty-test, vtable stores at `0x00556408`, `0x00556508`, `0x005567df`, and additional raw iterator helper bodies between `0x00556750` and `0x005567ae`.
- 2026-06-14 live IDA MCP session `a001_goal2_class_batch` reconfirmed modeled starts at `0x005563d0`, `0x005564e0`, `0x00556580`, `0x005565f0`, `0x00556660`, `0x00556680`, `0x00556690`, and `0x005567b0`, while `0x00556670`, `0x005566a0`, and `0x005566b0` remain raw no-function predicate starts.
- The same live xref pass reconfirmed two constructor callers from `Thread::Thread` at `0x005962da` and `0x00596306`, five enqueue refs at `0x0059657f`, `0x005966b0`, `0x00596997`, `0x005969e7`, and `0x00596a86`, one dequeue ref at `0x00596872`, and empty-test refs at `0x0059684d` and `0x0059685e`.
- Live component analysis groups the constructor, enqueue, dequeue, empty test, and deleting destructor with shared `??_7RingBuffer@@6B@` access; constructor/enqueue/dequeue/empty-test are external interface functions from the thread queue path, while the deleting destructor remains internal cleanup.
- 2026-07-04 B003 UID0004ES callback refreshed the primary raw full predicate under MCP session `nexustk_supervisor_20260704`: exact range `0x00556670-0x0055667a`, size `0xa` / 10, body bytes `8B 41 14 3B 41 1C 0F 9E C0 C3`, no IDA function object, no incoming xrefs, no code/data/immediate/pointer-byte route, and duplicate full-predicate bytes only at UID0004ES/UID0004EW. This keeps `RingBuffer::IsFull() const` source-ready while preserving raw-helper confidence caps.
- During the accepted 2026-07-13 UID0002OQ evidence pass, healthy database `supervisor_nexustk_20260713` reconfirmed the constructor/source-destructor/scalar-wrapper bodies, all vptr stores, exact 0x28 delete size, RTTI hierarchy, shared inherited slots, and unique pointer locations. The two COL/table records are exact target [UID:0002OQ][0x006230c8-0x006230e8.RingBufferVtableData](by-memory/0x006230c8-0x006230e8.RingBufferVtableData.md), SHA256 `BA6C579AF427527C8BC7FEDE62934B82ACBD4E7528ABA2FA1A6B4021F3433B9D`.
- Pointer scans found the RingBuffer table base only in the three documented lifecycle stores, its COL only in the exact target cell, and its scalar-wrapper pointer only in slot `0x006230cc`. Primary offset-zero inheritance and unadjusted `ecx` use exclude a secondary view or adjustor thunk.

## Post-Gate2 IDA Reconciliation

- Supervisor catalog entry `0375` applied and verified the UID0004EO IDA handoff under MCP session `07b29e1b`. The saved poststate is IDB SHA256 `DAA597458433CFB4230D3EE96AA0BCE8683FEFB5CDD6D88E22B33D1687462C17`, 143,192,163 bytes, saved `2026-07-30T12:47:29.2294093-04:00`; the byte-identical prestate backup is `E:\NTK\Resources\NexusTK\NexusTK.exe.i64.bak-UID0004EO-prestate-20260730-124522`, SHA256 `DADC487F51F66A37C85D62C994F49C545E170AB2F18061AEEDC679828967C6A4`, 143,192,050 bytes.
- Current read-only type inspection preserves `RingBuffer` as a 0x28-byte UDT with exactly ten members: `LObject_base +0x00 unsigned __int8[4]`, `mMonitor +0x04 Monitor *`, `mNotFull +0x08 MonitorCondition *`, `mNotEmpty +0x0c MonitorCondition *`, `mElementSize +0x10 int`, `mCapacity +0x14 int`, `mStorage +0x18 unsigned __int8 *`, `mCount +0x1c int`, `mReadIndex +0x20 int`, and `mWriteIndex +0x24 int`.
- `Monitor` and `MonitorCondition` are now exact 16-byte UDTs rather than incomplete declarations. `Monitor` is `vftable +0x00 void **`, `m_mutex +0x04 HANDLE`, `m_waiterCount +0x08 int`, `m_semaphore +0x0c HANDLE`; `MonitorCondition` is `vftable +0x00 void **`, `m_monitor +0x04 Monitor *`, `m_waiterCount +0x08 int`, `m_semaphore +0x0c HANDLE`. The three RingBuffer pointer members retained their exact existing types.
- Current function readback preserves `RingBuffer_RingBuffer` and `RingBuffer_destructor` with their exact source-facing prototypes/comments, while `RingBuffer_ScalarDeletingDestructor` remains protected compiler glue with type `RingBuffer *__thiscall(RingBuffer *this, unsigned int deleteFlags)`. Vtable item `??_7RingBuffer@@6B@` at `0x006230cc`, its value `0x005567b0`, item boundary, regular comment, and three lifecycle refs remain unchanged.
- Catalog 0375 also applied `MemoryMan_ZeroAllocateBufferMemory`, `MemoryMan_FreeBufferMemory`, and `LObject_destructor` with exact source-facing types/comments while preserving every byte/range/xref. These changes improve IDA readability but do not alter the class declaration, score, formal output route, or compiler/source split.

## Source And Compiler Output

R1 is the complete source declaration and now emits through `RECONSTRUCTION_H CODE` into `RingBuffer.h`. The class CPP channel emits only the deterministic include preamble; exact UID0004EN-UID0004EW definitions remain independent namespace-scope emitters in `RingBuffer.cpp` at their file positions. Raw no-function status at UID0004ES/UID0004EV/UID0004EW is an IDA-modeling and original-name confidence caveat, not a reason to suppress their already accepted source bodies. UID0004F5 remains compiler-only and blank. The header-owned class declaration, not a raw array or CPP-local duplicate, causes the RingBuffer RTTI/COL/vtable and scalar deleting wrapper recorded by UID0002OQ and UID0001YN.

Historical only: older `simroot_v2`/Wave3 output omitted several raw helper bodies and left this class formal blank. A later reconstruction placed the complete declaration directly in the CPP channel beside `[[CHILDREN]]`; that flat-CPP shape was behaviorally useful but could not provide a compilable shared declaration to independent method definitions. Both states are superseded by the exact CPP/H split above and remain history rather than current source blockers.

## Score Rationale

Completion `90` records the complete R1 declaration, exact 0x28 layout closure, queue behavior and children, Thread callers, synchronization dependencies, public zero-offset `LObject` hierarchy, inherited slots/no overrides, explicit source destructor versus scalar-wrapper split, unique lifecycle vptr route, compiler-output map, and companion friend relationship. Confidence `92` reflects direct binary agreement on behavior, layout, inheritance, and ABI; exact original field/helper spelling, private/friend token choice, and header visibility remain inferred and prevent a 95+ score.

## Cross-References

- File: [UID:0000N8][RingBuffer](by-file/RingBuffer.md)
- Memory: [UID:0001G4][0x005563d0-0x005568c8.RingBuffer](by-memory/0x005563d0-0x005568c8.RingBuffer.md)
- Vtable: [UID:0001YN][RingBufferVtables](by-type/by-vtable/RingBufferVtables.md)
- Related: [UID:0000EV][Thread](by-class/Thread.md), [UID:00008L][Monitor](by-class/Monitor.md), [UID:00008M][MonitorCondition](by-class/MonitorCondition.md), [UID:0000C2][RingBufferIterator](by-class/RingBufferIterator.md)

## Changes

- 2026-07-31 B006 UID0001G4 source-route callback:
  - Moved the exact 0x28 `RingBuffer` declaration from the CPP channel into `RingBuffer.h`, preserving every base, friend, method, field, and access decision.
  - Replaced the CPP-local declaration and `[[CHILDREN]]` container with the exact `RingBuffer.h`/`MemoryMan.h`/`Monitor.h` include preamble; method children remain independent file-position emitters.
  - Preserved the prior blank-formal and flat-CPP stages as labeled history and changed no score, ownership, layout, ABI, or compiler-output conclusion.
- 2026-07-30 B006 UID0004EO post-Gate2 reconciliation:
  - Added exact catalog-0375 backup/save and current RingBuffer/Monitor/MonitorCondition UDT, constructor/destructor/helper/base, scalar-wrapper, and protected-vtable readbacks.
  - Preserved metadata/formals/layout/source route and historicalized Wave3 as non-authoritative lead material; no IDA mutation occurred during this documentation pass.
- 2026-07-30 B006 UID0004EO support implementation callback:
  - Preserved class metadata at `90/92`, owner/emitter UID0000N8, reconstructable true, position 10, exact formal declaration, and the complete `0x28` layout.
  - Added the MemoryMan zero-allocation/free ownership contract and reverse teardown order to class purpose.
  - Refined UID0004EN/UID0004EO method descriptions and the ordinary-source-destructor versus compiler scalar-wrapper/vptr/base/EH split without emitting compiler glue.
  - Preserved older generated/Wave3 assumptions only as labeled history; no valid caller, layout, RTTI, or raw-helper evidence was removed.

- 2026-07-13 B003 UID0002OQ source-quality callback:
  - Changed `85/87 -> 90/92`, retained owner/emitter UID0000N8 and reconstructable true, set position `10`, and inserted exact R1 with the class closed before `[[CHILDREN]]`.
  - Added the exact 0x28 public-`LObject` layout, field order/types, private/friend access rationale, complete declaration/child map, RTTI and inherited-slot identities, ordinary/source destructor versus scalar-wrapper distinction, delete-size/no-adjustor/no-duplicate evidence, compiler-output route, and source-name/access confidence caps.
  - Historicalized obsolete Wave3/blank-until-raw-helper wording without removing Thread callers, raw predicate negatives, duplicate-helper evidence, synchronization behavior, or prior change history. UID0004EN-UID0004F5 remain unchanged.

- 2026-05-30: Changed completion/confidence from `0/0` to `82/84`.
  - Before: The page was unevaluated despite documenting queue semantics, method ranges, vtable, Thread usage, synchronization dependencies, and raw helper omissions.
  - After: Scored as high completion and strong confidence for the blocking ring buffer, short of perfect due to raw tiny helper starts lacking IDA function objects.
  - Evidence: Existing method table, vtable section, Thread/Monitor evidence, Wave3 metadata comparison, and generated data caveats support the score.
- 2026-06-01: Added the expanded raw iterator-helper pocket found during the memory-page rescore.
  - Evidence: IDA MCP disassembly identifies additional unmodeled helper bodies after `0x00556720`, separated by alignment padding and operating on the iterator's owner pointer/current index fields.
- 2026-06-03: Attached class metadata to the RingBuffer source file.
  - Before: The page was already `82/84`, but reconstructability and parent metadata were blank.
  - After: Marked reconstructable and attached to [UID:0000N8][RingBuffer](by-file/RingBuffer.md) at position `10`, with C++ still blank.
  - Evidence: Existing Thread caller, synchronization dependency, vtable, and method-boundary evidence already meet the parent-attachment threshold; the fresh iterator pass reconfirmed the shared ring-buffer island and adjacent companion-class layout without resolving the remaining raw helper naming gap.
- 2026-06-14 A002 Goal 2 live class refresh:
  - Before: `82/84`.
  - After: `85/87`; owner and emitter remain [UID:0000N8][RingBuffer](by-file/RingBuffer.md).
  - Evidence: live IDA MCP session `a001_goal2_class_batch` reconfirmed the modeled queue methods, raw no-function predicate starts, Thread constructor/enqueue/dequeue/empty-test xrefs, shared `RingBuffer` vtable access, and current companion iterator support from [UID:0001G4][0x005563d0-0x005568c8.RingBuffer](by-memory/0x005563d0-0x005568c8.RingBuffer.md) and [UID:0000C2][RingBufferIterator](by-class/RingBufferIterator.md).
- 2026-07-03 B006 UID0001G4 implementation callback:
  - Synchronized method inventory with exact child pages created under [UID:0001G4][0x005563d0-0x005568c8.RingBuffer](by-memory/0x005563d0-0x005568c8.RingBuffer.md).
  - Added the accepted B006 field layout from MCP session `1fc4a5a7`; no class metadata score change was required.
- 2026-07-03 B002 UID0004EW implementation callback:
  - Preserved class metadata at `85/87`; no ownership, emitter, or C++ routing change was required.
  - Added UID0004EW caveat detail by reference: fresh MCP session `31debdf2` found no IDA function object, no direct xrefs, no code/data refs, no VA/RVA immediates, and no little-endian pointer-byte route for the raw duplicate full predicate. Folding UID0004EW into UID0004ES remains unsupported, so both exact children stay documented.
- 2026-07-04 B003 UID0004ES implementation callback:
  - Preserved class metadata at `85/87`; no ownership, emitter, or class-level C++ routing change was required.
  - Added current MCP session `nexustk_supervisor_20260704` evidence for UID0004ES: exact ten-byte `capacity <= count` predicate, no function object, no incoming route, duplicate-only relation with UID0004EW, and no-fold/no-improvement proof. Exact original helper spelling and exposure remain confidence caps.

## 2026-07-31 Catalog0380 Applied IDA Reconciliation

- Supervisor catalog `0380` used prestate IDB SHA256 `4B5F2EC3F83106BAC18640D079C51CD2E2FB56797577EFE7D994EF483D9A696A`, 143,192,707 bytes, preserved by byte-identical backup `E:\NTK\Resources\NexusTK\backups\NexusTK.exe.pre-B006-UID0001G4-20260731_053341.i64`. `idb_save` returned `ok:true`; saved poststate is SHA256 `1BC3C43BCEDB92B9BF8950DA6E6DE759C3FA44B50C6A2FA0458CE129B6800CFD`, 143,195,497 bytes, at `2026-07-31T05:35:32.8233834-04:00`. The `4B5F...` checkpoint is dated pre-catalog0380 history.
- A `12/12` collision-safe dry run preceded application. `RingBuffer_Enqueue` now has physical `record +0x10/4 const void *` and locals `memoryMan`, `writeIndex`, `nextWriteIndex`, `notEmptyCondition`; `RingBuffer_Dequeue` locals are `memoryMan`, `readIndex`, `nextReadIndex`, `notFullCondition`; `RingBufferIterator_Advance` locals are `currentIndex`, `owner`, `nextIndex`. One direct local-type attempt returned `ok:false` without applying; the documented stack API with frame-pointer displacement `+0x8` produced the exact physical enqueue poststate without duplication.
- The five authored identities/prototypes/comments/ranges remain unchanged: iterator constructor `[0x005566c0,0x005566eb)`, enqueue `[0x00556580,0x005565ec)`, dequeue `[0x005565f0,0x0055665a)`, iterator advance `[0x00556720,0x00556749)`, and current element `[0x005567a0,0x005567ae)`. Exact body hashes remain `47B378...F003`, `43921F...2E38`, `6EC7AA...0A4F`, `8531BD...449B`, and `FBD7D2...E480`; successor fences remain `5/4/6/7/2` bytes of `CC`; incoming target xrefs remain `0/5/1/0/0`.
- Class/type protection readback retains exact `RingBuffer` size `0x28` / 40 bytes with ten members and `RingBufferIterator` size `0x0c` / 12 bytes with three members. `Monitor` and `MonitorCondition` remain `0x10` / 16 bytes with four members each; `MemoryMan` and `LObject` remain incomplete zero-member declarations. No member, inheritance, friend, or source-header layout changed.
- Decorated vtables `??_7RingBuffer@@6B@` and `??_7RingBufferIterator@@6B@`, their COL preheads/targets, exact comments, and `3/1` vtable xrefs remain unchanged. Compiler scalar wrappers, padding, and protected `var_4` remain untouched.
- Shared helper `sub_4F4A80` remains raw, unrenamed, uncommented, and typed only as `_DWORD *__thiscall(_DWORD *this)`; current incoming xrefs are `195`, superseding the dated target-local count `157` without changing its shared LObject-helper/source disposition.
- Catalog0380 changes only IDA frame/local source-quality state. The class metadata, exact layout, RingBuffer.h declaration, RingBuffer.cpp include route, formal CPP/H, scores, and ownership remain unchanged.
- Post-catalog0380 currentness: bounded read-only session `f608d7c2` against catalog0382-era physical IDB SHA256 `B7CC899DA786D8D49AE13525B844AA85CCF3C21C73D00DB2AE337FF838058277`, 143,192,751 bytes, saved `2026-07-31T06:21:13.3464834-04:00`, reverified the 40-byte/ten-member RingBuffer UDT, enqueue/dequeue applied frame/local names, exact method bodies/fences/xrefs/comments, primary vtable/COL protection and three vptr-store xrefs, and incomplete MemoryMan/LObject dependencies with no drift. The prior `5F2679A7...FC79A21` checkpoint, catalog0380 save `1BC3...0CFD`, and prestate `4B5F...A696A` are dated history; final moving shared-IDB currentness remains supervisor-controlled.
