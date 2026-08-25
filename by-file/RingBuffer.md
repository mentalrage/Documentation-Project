*** UID:0000N8 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:91 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"NexusTK/util/" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:FILE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***

# RingBuffer

## Status

- Reconstruction source: `NexusTK/util/RingBuffer.cpp`
- Reconstruction header: `NexusTK/util/RingBuffer.h`
- Deterministic dependency route: `RingBuffer.h` includes `"LObject.h"` and forward-declares pointer-only synchronization/iterator types; `RingBuffer.cpp` includes `"RingBuffer.h"`, `"MemoryMan.h"`, and `"Monitor.h"`.
- Confidence: strong for utility ownership, one-file RingBuffer/RingBufferIterator grouping, complete source/compiler inventory, and ownership of the compiler-emitted vtable data; original iterator exposure, access tokens, and exact member/helper spelling remain inferred.
- Historical generated lead only: `source-3/simroot_v2/util/RingBuffer.cpp` and associated Wave3 metadata helped identify the island but are stale provenance, not current source authority or blockers.

## File Role

The `RingBuffer.cpp` / `RingBuffer.h` pair owns the blocking fixed-size ring buffer used by [UID:0000OR][Thread](by-file/Thread.md) for message queues. It combines raw element storage with [UID:0000LI][Monitor](by-file/Monitor.md) and [UID:00008M][MonitorCondition](by-class/MonitorCondition.md) to provide producer/consumer enqueue and dequeue operations. Its source constructor caches `GetMemoryMan()` and obtains zeroed raw storage through `MemoryMan::ZeroAllocateBufferMemory`; enqueue/dequeue obtain `MemoryMan` before locking and copy through the retained receiver's `MemoryMan::MemmoveWrapper`; its ordinary destructor returns storage through `MemoryMan::FreeBufferMemory`, explicitly clears it, then deletes/clears not-empty, not-full, and monitor in reverse acquisition order.

It is a synchronization-aware container and is tracked with the other reusable storage helpers in [UID:0001QA][client_containers](by-meta/client_containers.md).

## Vtable-Data Parent And Source Gate

This `90/91` file is the direct owner/emitter for both header-owned class declarations, all exact source method children, and both comment-only compiler-data audit markers. [UID:0000C1][RingBuffer](by-class/RingBuffer.md) emits the `RingBuffer.cpp` include preamble and first `RingBuffer.h` declaration block at position `10`; [UID:0000C2][RingBufferIterator](by-class/RingBufferIterator.md) has a blank CPP channel and emits the second header declaration block at position `20`; exact source children UID0004EN-UID0004F4 retain independent CPP positions `100-270`. [UID:0002OQ][0x006230c8-0x006230e8.RingBufferVtableData](by-memory/0x006230c8-0x006230e8.RingBufferVtableData.md) and [UID:0001YN][RingBufferVtables](by-type/by-vtable/RingBufferVtables.md) emit R0/R3 comments with blank positions. Method-child H channels remain blank because declarations belong to the class pages. Compiler wrappers UID0004F5/UID0004F6 remain non-reconstructable with blank formals. Raw-helper names and iterator exposure are explicit confidence caps, not blockers to the complete CPP/H source route.

## Likely Contents

- [UID:0000C1][RingBuffer](by-class/RingBuffer.md): public zero-offset `LObject` base, explicit virtual destructor, exact 0x28 private queue layout, and friend iterator access.
- [UID:0000C2][RingBufferIterator](by-class/RingBufferIterator.md): public zero-offset `LObject` base, implicit virtual destructor, exact 0x0c owner/index layout, and complete retained helper declarations.
- UID0004EN: source constructor that caches MemoryMan, creates monitor/not-full/not-empty, stores dimensions, zero-allocates raw storage, and clears count/read/write.
- UID0004EO: ordinary source destructor that guards/frees storage through MemoryMan, clears it, deletes/clears not-empty/not-full/monitor in reverse order, and relies on compiler-generated vptr/base teardown.
- UID0004EP/UID0004EQ: blocking queue definitions that retain `GetMemoryMan()` across waits and call `MemoryMan::MemmoveWrapper`, not CRT `memcpy`.
- UID0004ER-UID0004F4: predicate/lock and iterator definitions, including raw-provenance paths retained as source.
- UID0004F5/UID0004F6: exact compiler scalar deleting-wrapper coverage with no handwritten source; UID0004F5 duplicates corrected RingBuffer cleanup and adds only compiler delete-flags/object-delete behavior.
- [UID:0002OQ][0x006230c8-0x006230e8.RingBufferVtableData](by-memory/0x006230c8-0x006230e8.RingBufferVtableData.md) and [UID:0001YN][RingBufferVtables](by-type/by-vtable/RingBufferVtables.md): exact COL/vtable/RTTI inventory and covered-by markers, never raw arrays.

## Evidence

- IDA MCP confirms a ring-buffer island at `0x005563d0-0x005568c8`.
- `RingBuffer::RingBuffer` constructs one `Monitor` and two `MonitorCondition` objects, stores element size/capacity, allocates zeroed storage, and initializes read/write/count fields.
- `Thread::Thread` constructs two ring buffers with `elementSize = 24`, matching the thread message record.
- Exact source children at `0x00556580`, `0x005565f0`, and `0x00556660` implement blocking enqueue, blocking dequeue, and empty-test behavior; all remaining exact children are inventoried below.
- `RingBuffer::Enqueue` is called by `Thread::StopThread` and thread message-post helpers.
- `RingBuffer::Dequeue` is called by `Thread::ThreadProc`.
- IDA confirms two short MSVC vtables in `.rdata`: `??_7RingBuffer@@6B@` at `0x006230cc` and `??_7RingBufferIterator@@6B@` at `0x006230dc`.
- Historical 2026-05-26 `simroot_v2/util/RingBuffer.meta_wave3` reported one vtable for each class at `0x006230cc` and `0x006230dc`; current conclusions use live IDA and exact documentation children instead.
- 2026-05-26 IDA `py_eval` recheck found direct code xrefs from `Thread` methods to the constructor (`0x005962da`, `0x00596306`), enqueue (`0x0059657f`, `0x005966b0`, `0x00596997`, `0x005969e7`, `0x00596a86`), dequeue (`0x00596872`), and empty test (`0x0059684d`, `0x0059685e`).
- 2026-06-01 IDA MCP recheck confirmed additional raw iterator helpers at `0x00556750`, `0x00556770`, `0x00556780`, and `0x005567a0`, plus `RingBuffer` vtable stores at `0x00556408`, `0x00556508`, and `0x005567df` and the `RingBufferIterator` vtable store at `0x005566d7`.
- 2026-06-03 IDA MCP recheck confirmed `RingBufferIterator` RTTI/COL `??_R4RingBufferIterator@@6B@` at `0x006230d8`, vtable `??_7RingBufferIterator@@6B@` at `0x006230dc`, constructor vptr store at `0x005566d7`, and the compact iterator layout `(vptr, RingBuffer* owner, int currentIndex)`.
- 2026-06-03 and accepted 2026-07-13 IDA MCP non-flow xref sweeps found no direct callers for the iterator constructor/helper starts. This rejects invented active/public use but no longer blocks the RTTI/constructor/body-backed class declaration.
- Dated B006 target-local session `f608d7c2` later modeled exact UID0004EX range `[0x005566c0,0x005566eb)` as `RingBufferIterator_RingBufferIterator` and exact UID0004F4 range `[0x005567a0,0x005567ae)` as `RingBufferIterator_CurrentElement`, while preserving their bytes, behavior, alignment fences, and zero-caller counts. Their stable `Raw` filenames and earlier no-function observations remain historical provenance; still-raw iterator siblings retain their own evidence.
- 2026-07-03 B003 UID0004F2 callback refreshed the `RingBufferIterator::AtReadBoundary() const` child under MCP session `31debdf2`: exact range `0x00556770-0x0055677d`, size `0x0d` / 13 bytes, unique signature `8B 51 04 8B 41 08 3B 42 20 0F 94 C0 C3`, no IDA function object, zero direct xrefs, loads owner `[ecx+4]`, loads current index `[ecx+8]`, compares to owner read index `[edx+20h]`, and returns through `setz al`.
- The accepted UID0002OQ evidence pass used healthy database `supervisor_nexustk_20260713` at collection time and proved exact target SHA256 `BA6C579AF427527C8BC7FEDE62934B82ACBD4E7528ABA2FA1A6B4021F3433B9D`, public zero-offset LObject RTTI for both classes, inherited runtime/message slots, source RingBuffer destructor versus both scalar wrappers, object sizes 0x28/0x0c, unique vptr stores, no adjustors/secondary views/duplicate tables, and clean menu/ScreenPane boundaries.

## Post-Gate2 IDA And Generated Reconciliation

- Supervisor catalog entry `0375` applied and verified the UID0004EO IDA handoff under MCP session `07b29e1b`. The saved poststate is IDB SHA256 `DAA597458433CFB4230D3EE96AA0BCE8683FEFB5CDD6D88E22B33D1687462C17`, 143,192,163 bytes, saved `2026-07-30T12:47:29.2294093-04:00`; the byte-identical prestate backup is `E:\NTK\Resources\NexusTK\NexusTK.exe.i64.bak-UID0004EO-prestate-20260730-124522`, SHA256 `DADC487F51F66A37C85D62C994F49C545E170AB2F18061AEEDC679828967C6A4`, 143,192,050 bytes.
- Current read-only IDA resolves `RingBuffer_RingBuffer`, `RingBuffer_destructor`, `MemoryMan_ZeroAllocateBufferMemory`, `MemoryMan_FreeBufferMemory`, and `LObject_destructor` with the exact source-facing types/comments documented on their by-memory pages. `RingBuffer_ScalarDeletingDestructor` and decorated data `??_7RingBuffer@@6B@` remain protected compiler output with unchanged ranges/types/value/comments/xrefs.
- Current type readback preserves the exact 0x28 `RingBuffer` UDT and completes both synchronization dependencies as 16-byte/four-member UDTs. `Monitor` contains `vftable`, `m_mutex`, `m_waiterCount`, and `m_semaphore` at offsets `0x00/0x04/0x08/0x0c`; `MonitorCondition` contains `vftable`, `m_monitor`, `m_waiterCount`, and `m_semaphore` at the same offsets. RingBuffer's `Monitor *` and `MonitorCondition *` fields remain unchanged.
- Supervisor generated refresh command `000000020024` completed `2026-07-30T12:50:19-04:00`, exit `0`. Its readback observed `auto-generated/NexusTK/util/RingBuffer.cpp` SHA256 `D35175F455A60039C3827E6D4B8C678D5F034ADC19A057D59BF30612BB0FAB0B`, 7,002 bytes / 240 lines, with exact UID0004EN constructor and UID0004EO destructor bodies present and neither an empty emitter. `RingBuffer.h` was absent under that root, consistent with the class-before-child flat CPP route rather than evidence that a historical header could not have existed.
- The same command-20024 checkpoint observed generated memory coverage SHA256 `3B54DA2FED76D4EDA0853E154DCBA94DF56697D73D00E8A16985FC9CD15B3EDA`, 1,420,185 bytes / 4,950 lines, with UID0004EN/UID0004EO coded at positions 100/110, and research tracker SHA256 `6349AD9B2B2EE6282BEB28C7E80263431A5248FCF7996FA70BE5A36790D384A8`, 1,679,848 bytes / 6,634 lines, with both rows at `92/93` and `93/94` and pre-execution direct/additional/total counts `0/0/0`. These generated identities are moving validator-owned observations, not durable lifecycle assertions; a later supervisor closure must reread current files.

## Generated Source And Compiler Inventory

UID0001G4 is not a source-emitting memory aggregate. The 2026-07-03 B006 split converted [UID:0001G4][0x005563d0-0x005568c8.RingBuffer](by-memory/0x005563d0-0x005568c8.RingBuffer.md) into a reviewed non-emitting split/index parent and created exact children for every method/helper. Source output comes from R1/R2 plus those exact children; R0/R3 document compiler-generated data; the mixed executable aggregate and compiler wrappers remain blank.

Exact executable children now routed to this file for source output:

- [UID:0004EN][0x005563d0-0x005564d4.RingBufferConstructor](by-memory/0x005563d0-0x005564d4.RingBufferConstructor.md): constructor; cached MemoryMan acquisition, monitor/conditions, dimensions, zero-allocated storage, and field initialization.
- [UID:0004EO][0x005564e0-0x00556579.RingBufferCleanupBody](by-memory/0x005564e0-0x00556579.RingBufferCleanupBody.md): ordinary `RingBuffer::~RingBuffer()` definition; MemoryMan storage free, explicit clear, reverse synchronization teardown, and compiler-managed base/vptr work.
- [UID:0004EP][0x00556580-0x005565ec.RingBufferEnqueue](by-memory/0x00556580-0x005565ec.RingBufferEnqueue.md): blocking enqueue.
- [UID:0004EQ][0x005565f0-0x0055665a.RingBufferDequeue](by-memory/0x005565f0-0x0055665a.RingBufferDequeue.md): blocking dequeue.
- [UID:0004ER][0x00556660-0x00556668.RingBufferIsEmpty](by-memory/0x00556660-0x00556668.RingBufferIsEmpty.md): modeled empty predicate.
- [UID:0004ES][0x00556670-0x0055667a.RingBufferIsFullRawPredicate](by-memory/0x00556670-0x0055667a.RingBufferIsFullRawPredicate.md), [UID:0004EV][0x005566a0-0x005566a8.RingBufferEmptyPredicateAlias](by-memory/0x005566a0-0x005566a8.RingBufferEmptyPredicateAlias.md), and [UID:0004EW][0x005566b0-0x005566ba.RingBufferFullPredicateAlias](by-memory/0x005566b0-0x005566ba.RingBufferFullPredicateAlias.md): raw predicate helpers/aliases with no IDA function objects.
- [UID:0004ET][0x00556680-0x00556688.RingBufferLock](by-memory/0x00556680-0x00556688.RingBufferLock.md) and [UID:0004EU][0x00556690-0x00556698.RingBufferUnlock](by-memory/0x00556690-0x00556698.RingBufferUnlock.md): monitor wrappers.
- [UID:0004EX][0x005566c0-0x005566eb.RingBufferIteratorConstructorRaw](by-memory/0x005566c0-0x005566eb.RingBufferIteratorConstructorRaw.md), [UID:0004EY][0x005566f0-0x005566fa.RingBufferIteratorReset](by-memory/0x005566f0-0x005566fa.RingBufferIteratorReset.md), [UID:0004EZ][0x00556700-0x00556715.RingBufferIteratorSetToLastRaw](by-memory/0x00556700-0x00556715.RingBufferIteratorSetToLastRaw.md), [UID:0004F0][0x00556720-0x00556749.RingBufferIteratorAdvance](by-memory/0x00556720-0x00556749.RingBufferIteratorAdvance.md), [UID:0004F1][0x00556750-0x00556767.RingBufferIteratorRetreatRaw](by-memory/0x00556750-0x00556767.RingBufferIteratorRetreatRaw.md), [UID:0004F2][0x00556770-0x0055677d.RingBufferIteratorAtReadBoundaryRaw](by-memory/0x00556770-0x0055677d.RingBufferIteratorAtReadBoundaryRaw.md), [UID:0004F3][0x00556780-0x00556794.RingBufferIteratorNextAtWriteBoundaryRaw](by-memory/0x00556780-0x00556794.RingBufferIteratorNextAtWriteBoundaryRaw.md), and [UID:0004F4][0x005567a0-0x005567ae.RingBufferIteratorCurrentElementRaw](by-memory/0x005567a0-0x005567ae.RingBufferIteratorCurrentElementRaw.md): companion iterator helpers in the same file.
- [UID:0004F5][0x005567b0-0x00556887.RingBufferScalarDeletingDestructor](by-memory/0x005567b0-0x00556887.RingBufferScalarDeletingDestructor.md) and [UID:0004F6][0x00556890-0x005568c8.RingBufferIteratorScalarDeletingDestructor](by-memory/0x00556890-0x005568c8.RingBufferIteratorScalarDeletingDestructor.md): documented as non-reconstructable, non-emitting MSVC scalar deleting destructor glue. They remain exact coverage children but should be regenerated by the compiler from source destructor declarations rather than emitted as handwritten source snippets.

Historical MCP session `1fc4a5a7` refreshed the original source-output split evidence: modeled starts were `0x005563d0`, `0x005564e0`, `0x00556580`, `0x005565f0`, `0x00556660`, `0x00556680`, `0x00556690`, `0x005566f0`, `0x00556720`, `0x005567b0`, and `0x00556890`; raw/no-function starts included `0x00556670`, `0x005566a0`, `0x005566b0`, `0x005566c0`, `0x00556700`, `0x00556750`, `0x00556770`, `0x00556780`, and `0x005567a0`. Dated later target-local evidence supersedes only the function-object state for UID0004EX/UID0004F4. The forward iterator end predicate at `0x00556780` compares the next wrapped index to the write boundary at `+0x24`; reset/current-start uses the read index at `+0x20`.

The later B003 UID0004F2 evidence under MCP session `31debdf2` narrows the source-output note for [UID:0004F2][0x00556770-0x0055677d.RingBufferIteratorAtReadBoundaryRaw](by-memory/0x00556770-0x0055677d.RingBufferIteratorAtReadBoundaryRaw.md): this child emits `RingBufferIterator::AtReadBoundary() const` through this file, compares current index to read boundary `+0x20`, is bracketed by `0xcc` alignment at `0x00556767-0x00556770` and `0x0055677d-0x00556780`, and is distinct from [UID:0004F3][0x00556780-0x00556794.RingBufferIteratorNextAtWriteBoundaryRaw](by-memory/0x00556780-0x00556794.RingBufferIteratorNextAtWriteBoundaryRaw.md), which checks the next wrapped index against write boundary `+0x24`.

Raw helper caveats remain: direct callers were not found for the raw iterator/helper starts, and exact original helper names plus `RingBufferIterator` public/private exposure remain inferred. These caveats now belong on the exact child pages instead of blocking the parent aggregate structure. For [UID:0004EW][0x005566b0-0x005566ba.RingBufferFullPredicateAlias](by-memory/0x005566b0-0x005566ba.RingBufferFullPredicateAlias.md), fresh MCP session `31debdf2` found no direct xrefs, code refs, data refs, VA/RVA immediate refs, or little-endian pointer-byte route to either duplicate full-predicate start (`0x00556670`/`0x005566b0`); therefore UID0004EW remains emitted at position `190` as an exact inferred `Full()` alias, and folding it into UID0004ES is unsupported by current route evidence.

B003 UID0004ES current-session evidence under MCP session `nexustk_supervisor_20260704` narrows the same caveat for [UID:0004ES][0x00556670-0x0055667a.RingBufferIsFullRawPredicate](by-memory/0x00556670-0x0055667a.RingBufferIsFullRawPredicate.md): exact range `0x00556670-0x0055667a`, size `0xa` / 10, bytes `8B 41 14 3B 41 1C 0F 9E C0 C3`, disassembly `mov eax, [ecx+14h]; cmp eax, [ecx+1Ch]; setle al; retn`, no IDA function object, no incoming xrefs, no code/data/immediate/pointer-byte route, and duplicate full-predicate bytes only at UID0004ES/UID0004EW. UID0004ES remains emitted through this file at position `150` as `RingBuffer::IsFull() const`; no fold, metadata change, or generated-file manual edit is supported.

Historical Wave3 output emitted `RingBufferIterator::RingBufferIterator` at `0x005566c0`. Exact child UID0004EX retains that source body: base initialization, owning `RingBuffer *` store, vptr store to `0x006230dc`, `mCurrentIndex = -1`, and return. The older no-function observation is dated history; later target-local IDA models the exact range and constructor prototype. Neither state changes the one-file CPP/H source route.

The 2026-06-01 IDA pass corrected the raw constructor-shaped endpoint to include the epilogue and `retn 4` at `0x005566e8`, so the body is tracked as `0x005566c0-0x005566eb` before alignment padding.

## Source-Structure Decision

Use `util/RingBuffer.cpp` with `util/RingBuffer.h`. Keep the module separate from [UID:0000OR][Thread](by-file/Thread.md) because it is a reusable blocking container with its own monitor/condition implementation and a compact code island. Keep it separate from [UID:0000KS][List](by-file/List.md) because it is synchronization-aware and not the same fixed-width dynamic array container.

Declarations live in `RingBuffer.h` because independent child definitions need one shared complete class declaration, while `RingBuffer.cpp` owns definitions and includes complete MemoryMan/Monitor dependencies. This deterministic compilable route supersedes the flat CPP-local declaration without claiming recovered debug-symbol proof of the original header token. `RingBufferIterator` remains in this module because its RTTI/data/code are contiguous with RingBuffer and it directly accesses RingBuffer state; no caller or independent island supports `RingBufferIterator.cpp`. Thread is a consumer, Monitor/MonitorCondition are dependencies, and adjacent menu/ScreenPane data only prove boundaries.

## Score Rationale

Completion `90` reflects a complete source/compiler inventory, exact class positions and declarations, every source child and compiler exclusion, one source path, exact data markers, Thread consumers, Monitor dependencies, raw-helper negative evidence, duplicate-predicate retention, and generated ordering/no-raw-table policy. Confidence `91` is strong for module ownership and behavior; exact original header exposure, private/friend tokens, and helper/member spellings remain unavailable and cap the score.

## Cross-References

- [UID:0000C1][RingBuffer](by-class/RingBuffer.md)
- [UID:0000C2][RingBufferIterator](by-class/RingBufferIterator.md)
- [UID:0001G4][0x005563d0-0x005568c8.RingBuffer](by-memory/0x005563d0-0x005568c8.RingBuffer.md)
- [UID:0001YN][RingBufferVtables](by-type/by-vtable/RingBufferVtables.md)
- [UID:0000OR][Thread](by-file/Thread.md)
- [UID:0000LI][Monitor](by-file/Monitor.md)
- [UID:0001QT][client_threading](by-meta/client_threading.md)
- [UID:0001QA][client_containers](by-meta/client_containers.md)

## Changes

- 2026-07-31 B006 UID0001G4 source-route callback:
  - Replaced the flat CPP-only declaration route with exact `NexusTK/util/RingBuffer.cpp` and `NexusTK/util/RingBuffer.h` ownership, including same-folder `LObject.h`, `MemoryMan.h`, and `Monitor.h` dependencies.
  - Recorded header-owned declarations, independently positioned CPP definitions, blank method-child H channels, and `MemoryMan::MemmoveWrapper` enqueue/dequeue semantics without changing scores or ownership.
  - Historicalized the old UID0004EX/UID0004F4 no-function map and added their later dated modeled names/prototypes while preserving every still-raw sibling and zero-caller confidence cap.
- 2026-07-30 B006 UID0004EO post-Gate2 reconciliation:
  - Added catalog-0375 backup/save, exact current RingBuffer/helper/base/UDT/protected compiler state, and bounded command-20024 generated CPP/H/memory/tracker observations.
  - Preserved the one-file source route, all exact child/compiler exclusions, scores, and historical evidence. Generated identities are explicitly moving checkpoints and no generated file was edited.
- 2026-07-30 B006 UID0004EO support implementation callback:
  - Preserved file metadata `90/91`, `PROPOSED_RECONSTRUCTION_PATH:"NexusTK/util/"`, `CANONICAL_OWNER:FILE`, one-file RingBuffer/RingBufferIterator ownership, and every exact child/compiler-data route.
  - Reconciled file role and method inventory to cached-MemoryMan construction and paired MemoryMan destruction, including exact reverse ownership teardown and compiler scalar-wrapper exclusion.
  - Recorded that UID0004EN/UID0004EO own corrected CPP definitions, their H channels remain blank because UID0000C1 owns declarations, generated RingBuffer H remains absent, and generated output must be refreshed only by supervisor-controlled validation.
  - Preserved all valid Thread callers, Monitor dependencies, raw-helper caveats, RTTI/vtable evidence, and labeled historical Wave3 assumptions.

- 2026-07-13 B003 UID0002OQ source-quality callback:
  - Changed `86/85 -> 90/91`; retained `PROPOSED_RECONSTRUCTION_PATH:"NexusTK/util/"` and `CANONICAL_OWNER:FILE`.
  - Added R1/R2 positions 10/20, exact source children UID0004EN-UID0004F4, compiler exclusions UID0004F5/UID0004F6, R0/R3 marker routes, complete RTTI/layout/destructor/object-size/no-adjustor/no-duplicate evidence, one-file source rationale, and generated structure/no-raw-table policy.
  - Historicalized stale Wave3/final-source-blocked wording while preserving all Thread caller, Monitor dependency, raw-helper no-caller/name, duplicate predicate, and prior split/history detail. No verify-only child was edited.

- 2026-05-30: Scored documentation completeness/confidence.
  - Before: completion/confidence metadata was ungraded at `0/0`.
  - After: set completion to `86` and confidence to `82`.
  - Evidence: document captures utility ownership, class contents, IDA function island, Thread call evidence, vtable evidence, generated-output caveats, raw helper gaps, and source-structure decision; confidence is capped by unresolved raw helper names and the exact public/private status of `RingBufferIterator`.
- 2026-06-01: Filled validator-managed projected reconstruction path.
  - Before: `PROPOSED_RECONSTRUCTION_PATH` was blank despite the page and project tree already identifying `util/RingBuffer.cpp`.
  - After: set the projected folder to `NexusTK/util/` so validator-owned autogen can stage `RingBuffer.cpp` under the reconstructed root.
  - Evidence: this page's source-structure decision, [UID:0001YN][RingBufferVtables](by-type/by-vtable/RingBufferVtables.md), and `by-project-structure/proposed-source-tree.md` all place the utility ring-buffer module in the util/threading container group.
- 2026-06-01: Added the expanded raw iterator-helper pocket from the memory-page rescore.
  - Evidence: IDA MCP disassembly found additional complete helper bodies at `0x00556750`, `0x00556770`, `0x00556780`, and `0x005567a0`, and corrected the raw iterator constructor endpoint to `0x005566eb`.
- 2026-06-03: Attached RingBuffer class pages.
  - Before: the file listed [UID:0000C1][RingBuffer](by-class/RingBuffer.md) and [UID:0000C2][RingBufferIterator](by-class/RingBufferIterator.md), but both class pages were still unassigned in autogen metadata.
  - After: attached `RingBuffer` at position `10` and `RingBufferIterator` at position `20`; C++ remains blank for both.
  - Evidence: IDA MCP reconfirmed the shared code island, `RingBufferIterator` RTTI/COL and vtable, the raw constructor vptr store, and the unresolved direct-caller gap for iterator helper starts.
- 2026-06-07 A003 Batch 065: Raised confidence from `82` to `85` with a focused vtable-data parent-gate audit. Evidence is the already documented Thread caller set, shared ring-buffer code island, attached RingBuffer/RingBufferIterator classes, [UID:0001YN][RingBufferVtables](by-type/by-vtable/RingBufferVtables.md), and exact [UID:0002OQ][0x006230c8-0x006230e8.RingBufferVtableData](by-memory/0x006230c8-0x006230e8.RingBufferVtableData.md) child. Completion remains `86`, and C++ remains blank because raw helper names and iterator source exposure are not final-code quality.
- 2026-07-03 B006 UID0001G4 implementation callback: synchronized the file page after converting [UID:0001G4][0x005563d0-0x005568c8.RingBuffer](by-memory/0x005563d0-0x005568c8.RingBuffer.md) into a non-emitting split/index parent. Exact method/helper child pages [UID:0004EN][0x005563d0-0x005564d4.RingBufferConstructor](by-memory/0x005563d0-0x005564d4.RingBufferConstructor.md) through [UID:0004F4][0x005567a0-0x005567ae.RingBufferIteratorCurrentElementRaw](by-memory/0x005567a0-0x005567ae.RingBufferIteratorCurrentElementRaw.md) now carry source-output routing for the RingBuffer/RingBufferIterator methods and helpers through this file; scalar wrapper children [UID:0004F5][0x005567b0-0x00556887.RingBufferScalarDeletingDestructor](by-memory/0x005567b0-0x00556887.RingBufferScalarDeletingDestructor.md) and [UID:0004F6][0x00556890-0x005568c8.RingBufferIteratorScalarDeletingDestructor](by-memory/0x00556890-0x005568c8.RingBufferIteratorScalarDeletingDestructor.md) are non-emitting compiler glue. No file metadata score change was required.
- 2026-07-03 B003 UID0004F2 implementation callback: added current `31debdf2` MCP evidence for the emitting `RingBufferIterator::AtReadBoundary() const` child. No file metadata score change was required because file-level confidence remains capped by exact original iterator helper spelling and public/private exposure.
- 2026-07-03 B002 UID0004EW implementation callback: preserved file metadata and source route. UID0004EW still emits through this file at position `190`; the accepted no-improvement proof records duplicate full-predicate bytes only at UID0004ES/UID0004EW and no incoming code/data/ref/immediate/pointer-byte route, so no fold, score change, or emitter change was applied.
- 2026-07-04 B003 UID0004ES implementation callback: preserved file metadata and source route. UID0004ES still emits through this file at position `150`; current MCP session `nexustk_supervisor_20260704` records exact ten-byte `capacity <= count` bytes, no IDA function object, no incoming route, duplicate-only relation with UID0004EW, and no score or fold improvement.

## UID0000LI Dependency Closure - 2026-08-15

The existing `Monitor.h` consumer route is reconfirmed against exact Monitor/MonitorCondition source children. RingBuffer constructs one Monitor and two MonitorCondition instances and calls only Lock/Unlock/Wait/Signal; no RequestSyncGate or CriticalSection ownership is introduced. No RingBuffer formal body changed.

## 2026-07-31 Catalog0380 Applied IDA Reconciliation

- Supervisor catalog `0380` used prestate IDB SHA256 `4B5F2EC3F83106BAC18640D079C51CD2E2FB56797577EFE7D994EF483D9A696A`, 143,192,707 bytes, preserved by byte-identical backup `E:\NTK\Resources\NexusTK\backups\NexusTK.exe.pre-B006-UID0001G4-20260731_053341.i64`. `idb_save` returned `ok:true`; current saved poststate is SHA256 `1BC3C43BCEDB92B9BF8950DA6E6DE759C3FA44B50C6A2FA0458CE129B6800CFD`, 143,195,497 bytes, at `2026-07-31T05:35:32.8233834-04:00`. The `4B5F...` checkpoint is dated pre-catalog0380 history.
- A collision-safe dry run passed `12/12`. Applied source-quality state is enqueue frame `record +0x10/4 const void *`; enqueue locals `memoryMan`, `writeIndex`, `nextWriteIndex`, `notEmptyCondition`; dequeue locals `memoryMan`, `readIndex`, `nextReadIndex`, `notFullCondition`; advance locals `currentIndex`, `owner`, `nextIndex`. The first direct local-type edit returned `ok:false` and made no change; the stack API with frame-pointer displacement `+0x8` then applied the exact frame type without duplication.
- All five source-authored function identities, exact prototypes, regular comments, frames outside targeted items, ranges, and other absent comment channels remain unchanged. Their exact body hashes remain constructor `47B378...F003`, enqueue `43921F...2E38`, dequeue `6EC7AA...0A4F`, advance `8531BD...449B`, current element `FBD7D2...E480`; successor `CC` fences remain `5/4/6/7/2` bytes; incoming target xrefs remain `0/5/1/0/0`.
- Type and ABI protection remains exact: `RingBuffer` 40 bytes/ten members, `RingBufferIterator` 12 bytes/three members, `Monitor`/`MonitorCondition` 16 bytes/four members each, incomplete zero-member `MemoryMan`/`LObject`, both decorated vtables and COLs unchanged with `3/1` xrefs, and compiler-only wrappers/padding untouched.
- Shared helper `sub_4F4A80` remains raw, unrenamed, uncommented, and typed `_DWORD *__thiscall(_DWORD *this)`. Its current incoming-xref count is `195`, superseding the dated `157` count without changing its broad shared LObject-helper/source disposition.
- Catalog0380 does not change the `NexusTK/util/RingBuffer.cpp` plus `RingBuffer.h` route, include/declaration ownership, emitter ordering, formal CPP/H, scores, or source split. It only reconciles the applied IDA frame/local names with this file-family documentation.
- Post-catalog0380 currentness: bounded read-only session `f608d7c2` against catalog0382-era physical IDB SHA256 `B7CC899DA786D8D49AE13525B844AA85CCF3C21C73D00DB2AE337FF838058277`, 143,192,751 bytes, saved `2026-07-31T06:21:13.3464834-04:00`, reverified all five target ranges/names/types/comments/frames/applied locals, exact hashes/fences/xrefs `0/5/1/0/0`, RingBuffer/iterator/Monitor UDTs, decorated vtables/COLs, and protected `sub_4F4A80` with `195` incoming xrefs. No source-family drift occurred; the prior `5F2679A7...FC79A21` checkpoint, catalog0380 save `1BC3...0CFD`, and prestate `4B5F...A696A` are dated history. Final moving shared-IDB currentness remains supervisor-controlled.
