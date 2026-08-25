*** UID:0000MW | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:91 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:91 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"NexusTK/util/" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:FILE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***

# Queue

## Status

- Confidence: strong for the complete six-body/padding inventory, exact `0x18` class layout, class-to-file ownership route, separate `Queue.cpp`/`Queue.h` source shape, vtable/RTTI boundaries, and the five accepted source-authored method bodies; active direct caller reachability remains the explicit confidence cap.
- Proposed module: `util/Queue.cpp`
- Current generated source: validator-owned `auto-generated/NexusTK/util/Queue.cpp`
- Main address range: [UID:0001FN][0x005539e0-0x00553c07.Queue](by-memory/0x005539e0-0x00553c07.Queue.md)
- Reconstruction disposition: `TRUE`. Singular by-file pages intentionally do not carry the validator-managed `RECONSTRUCTABLE` header; this body disposition records the accepted whole-file result while retaining `CANONICAL_OWNER:FILE` and `PROPOSED_RECONSTRUCTION_PATH:"NexusTK/util/"`.

## File Role

`Queue` is a fixed-slot, fixed-element-size circular queue derived from `LObject`. It allocates `slotCount * slotSize` bytes through the client memory manager, tracks read and write indices, and exposes small write/read/empty helpers.

Historical active generated output emitted only the constructor and scalar deleting destructor. IDA disassembly shows the full compact cluster also includes the ordinary destructor, write-slot, read-slot, and empty-test helpers; [UID:0001FM][0x005539e0-0x00553a5c.QueueConstructor](by-memory/0x005539e0-0x00553a5c.QueueConstructor.md) now contributes formal first-draft `Queue::Queue(int slotSize, int slotCount)` C++, [UID:0001FO][0x00553a60-0x00553ab9.QueueDestructor](by-memory/0x00553a60-0x00553ab9.QueueDestructor.md) now contributes formal first-draft `Queue::~Queue()` C++, [UID:0001FP][0x00553ac0-0x00553b05.QueueWriteSlotRaw](by-memory/0x00553ac0-0x00553b05.QueueWriteSlotRaw.md) now contributes formal first-draft `Queue::WriteSlot(const void *slot)` C++, [UID:0001FQ][0x00553b10-0x00553b55.QueueReadSlotRaw](by-memory/0x00553b10-0x00553b55.QueueReadSlotRaw.md) now contributes formal first-draft `Queue::ReadSlot(void *slot)` C++, and [UID:0001FR][0x00553b60-0x00553b6a.QueueIsEmptyRaw](by-memory/0x00553b60-0x00553b6a.QueueIsEmptyRaw.md) now contributes formal first-draft `Queue::IsEmpty() const` C++ through the Queue class route. [UID:0001FS][0x00553b70-0x00553c07.QueueScalarDeletingDestructor](by-memory/0x00553b70-0x00553c07.QueueScalarDeletingDestructor.md) is resolved as non-emitting compiler-generated scalar-wrapper support generated from the virtual destructor. The 2026-08-11 whole-file callback below supersedes the former header/source-layout blocker: the source shape is now exact, while original symbol spelling and active-use proof remain confidence caps rather than reconstruction blockers.

2026-05-26 recheck using current `simroot_v2` and IDA MCP only: active `class_Queue.cpp` still emits only `0x005539e0` and `0x00553b70`. IDA still models `0x005539e0`, `0x00553a60`, and `0x00553b70` as functions, while `0x00553ac0`, `0x00553b10`, and `0x00553b60` remain raw not-a-function starts with no direct callers.

2026-05-31 IDA MCP recheck: `0x005539e0-0x00553a5c`, `0x00553a60-0x00553ab9`, and `0x00553b70-0x00553c07` remain modeled functions. The raw helper starts at `0x00553ac0`, `0x00553b10`, and `0x00553b60` still decode as queue-style fixed-slot write/read/empty bodies but are not IDA function starts and have no modeled direct callers. This keeps `Queue.cpp` a plausible utility source module but keeps confidence below final/original-source level.

2026-06-10 A002 live IDA gate refresh: `lookup_funcs` still reports modeled starts at `0x005539e0` size `0x7c`, `0x00553a60` size `0x59`, and `0x00553b70` size `0x97`; it still reports `0x00553ac0`, `0x00553b10`, and `0x00553b60` as not function starts. `callers`/`xrefs_to` remain empty for the constructor, ordinary destructor, and raw write/read/empty starts, while the scalar deleting destructor has the expected vtable data xref from `0x00622d24`. `xrefs_to 0x00622d24` still shows vtable stores from constructor `0x00553a15`, ordinary destructor `0x00553a88`, and scalar deleting destructor `0x00553b9f`. `get_bytes` confirms the `0xcc` alignment spans around each child, and the constructor decompile shows `this[3] = sub_5160D0(a3 * a2)`, proving the backing buffer is zero-allocated through the MemoryMan zero-allocation helper.

2026-06-16 A002 collision-review/source-quality pass: reviewed the pre-existing C001 Queue edits as shared workspace state, kept the valid direct class owner/emitter route, and corrected stale IDA-comment/final-code-gate wording in the child pages. Current IDA evidence still finds no direct xrefs or VA/RVA pointer-byte hits for the constructor, ordinary destructor, or raw helper starts; the scalar deleting destructor remains vtable-only. IDA type/struct queries do not recover a local `Queue` UDT. At that time `auto-generated/NexusTK/util/Queue.cpp` was marker-only/empty for this family, so final source output remained blocked by original method names/signatures, raw-helper reachability/source representation, and active-use proof rather than by file placement.

2026-06-27 B013 source-quality implementation resolved the write-slot child: [UID:0001FP][0x00553ac0-0x00553b05.QueueWriteSlotRaw](by-memory/0x00553ac0-0x00553b05.QueueWriteSlotRaw.md) now emits inferred `Queue::WriteSlot(const void *slot)`. Current MCP session `b001_000241_20260627` reconfirmed the raw boundary, exact bytes/padding, no xrefs, no VA/RVA pointer route, no direct `E8/E9` route, Queue layout support, and the `GetMemoryMan()->MemmoveWrapper` copy path. `WriteSlot` is inferred source-facing spelling; `Raw`, `Write`, `Push`, `Enqueue`, `Append`, and raw `sub_553AC0` remain rejected on the child page.

2026-06-27/2026-06-28 B013 source-quality implementation resolves the read-slot child: [UID:0001FQ][0x00553b10-0x00553b55.QueueReadSlotRaw](by-memory/0x00553b10-0x00553b55.QueueReadSlotRaw.md) now emits inferred `Queue::ReadSlot(void *slot)`. Current MCP session `b001_000241_20260627` reconfirmed the raw not-a-function boundary, decompile failure, exact 69-byte body, `c2 04 00` `retn 4`, eleven-byte pre/post padding, unique exact-byte signature, no xrefs/callers/callee route, no VA/RVA pointer route, no direct local PE `E8/E9` route, Queue layout support, no local Queue UDT, no recovered candidate source symbol, and the `GetMemoryMan()->MemmoveWrapper` copy-out path from `m_buffer + m_readIndex * m_slotSize` into the caller destination. `ReadSlot` is inferred source-facing spelling; `QueueReadSlotRaw`, `Read`, `Pop`, `Dequeue`, `Get`, raw `sub_553B10`, no-code, metadata fallback, and owner/emitter fallback are rejected on the child page.

2026-06-27/2026-06-28 B003 source-quality implementation resolves the empty-test child: [UID:0001FR][0x00553b60-0x00553b6a.QueueIsEmptyRaw](by-memory/0x00553b60-0x00553b6a.QueueIsEmptyRaw.md) now emits inferred `Queue::IsEmpty() const`. Current MCP session `b001_000241_20260627` reconfirmed the raw not-a-function boundary, decompile failure, exact ten-byte body `8b 41 10 3b 41 14 0f 94 c0 c3`, eleven-byte pre-padding, six-byte post-padding, unique exact-byte signature, no xrefs/callee route, no VA/RVA pointer route, no direct local PE `E8/E9` route, Queue layout support, no local Queue UDT/type record, no recovered candidate source symbol, and the equality predicate `m_readIndex == m_writeIndex`. `IsEmpty` is inferred source-facing spelling; `QueueIsEmptyRaw`, `Empty`, `empty`, `CanRead`, `HasData`, `IsFull`, raw `sub_553B60`, no-code, covered-by, metadata fallback, and owner/emitter fallback are rejected on the child page. Constructor/destructor/header factoring, active-use proof, and complete final `Queue.h`/`Queue.cpp` layout remain incomplete for the broader file.

## 2026-08-11 Whole-File Reconstruction Callback

The accepted UID0000MW whole-file investigation resolves this compilation unit without discarding the older per-child investigations. Queue is a source-authored `LObject`-derived fixed-slot circular queue whose one narrow declaration/method owner is [UID:0000BF][Queue](by-class/Queue.md); this by-file page is the source-root destination only. The complete physical cluster and every internal alignment span are:

| Exact range | Width | Source disposition |
| --- | --- | --- |
| `0x005539e0-0x00553a5c` | `0x7c` | Source-authored constructor; emits at child position `10`. |
| `0x00553a5c-0x00553a60` | `0x04` | Internal `0xcc` alignment; no source item. |
| `0x00553a60-0x00553ab9` | `0x59` | Source-authored ordinary destructor; emits at child position `20`. |
| `0x00553ab9-0x00553ac0` | `0x07` | Internal `0xcc` alignment; no source item. |
| `0x00553ac0-0x00553b05` | `0x45` | Source-authored `WriteSlot`; emits at child position `30` despite the raw IDA boundary. |
| `0x00553b05-0x00553b10` | `0x0b` | Internal `0xcc` alignment; no source item. |
| `0x00553b10-0x00553b55` | `0x45` | Source-authored `ReadSlot`; emits at child position `40` despite the raw IDA boundary. |
| `0x00553b55-0x00553b60` | `0x0b` | Internal `0xcc` alignment; no source item. |
| `0x00553b60-0x00553b6a` | `0x0a` | Source-authored `IsEmpty`; emits at child position `50` despite the raw IDA boundary. |
| `0x00553b6a-0x00553b70` | `0x06` | Internal `0xcc` alignment; no source item. |
| `0x00553b70-0x00553c07` | `0x97` | MSVC scalar deleting destructor; compiler-generated, non-emitting source support. |
| `0x00553c07-0x00553c10` | `0x09` | External successor alignment before unrelated `sub_553C10`; excluded from the Queue aggregate. |

The source-facing object is exactly `0x18` bytes: `LObject`/vptr at `+0x00`, `m_slotSize` at `+0x04`, `m_slotCount` at `+0x08`, `m_buffer` at `+0x0c`, `m_readIndex` at `+0x10`, and `m_writeIndex` at `+0x14`. Constructor stores, copy-stride arithmetic, wrap comparisons, buffer cleanup, empty comparison, and the scalar-delete size immediate independently agree with this table. Historical generated names that reversed slot size/count are rejected.

Source placement is deterministic. UID0000BF owns both formal source channels. Its CPP wrapper includes `Queue.h` first, then `MemoryMan.h`, then expands `[[CHILDREN]]` in positions `10/20/30/40/50`. Its H channel owns the one clean `Queue : public LObject` declaration, includes only `LObject.h`, declares the five source-authored methods and five fields, and asserts size `0x18`. No child H channel emits. The scalar wrapper, vtable at `0x00622d24`, Queue RTTI, and alignment bytes are compiler output and receive no hand-authored source representation.

Reachability remains evidence-backed rather than assumed. Direct caller/xref and stored-pointer searches found no direct route to the constructor, ordinary destructor, or three raw helpers. The scalar wrapper has one data xref from the Queue vtable; the vtable pointer is stored by constructor, ordinary destructor, and scalar wrapper at `0x00553a15`, `0x00553a88`, and `0x00553b9f`. The accepted probability is 90 percent dormant/legacy source and 10 percent unresolved indirect or external route. Dormancy does not convert source-authored project code into compiler/runtime code and does not remove it from preservation output.

No additional Queue-owned global, static, constant, string, resource, import, or helper was found. `g_pApplicationCleanupQueue` is expressly excluded because its type and ownership are `BlackHole *`, not this `Queue`. The adjacent `ConnectionClosedDialog` vtable head at `0x00622d34` and unrelated function at `0x00553c10` remain hard boundaries. Stale Wave2/Wave3 source material was not used; current by-* pages, current generated baseline, seven executed child reports, and fresh read-only IDA evidence supplied the accepted disposition.

## Queue Support-Only UID And Destination Inventory

These are all eleven support-only UIDs declared for the UID0000MW whole-file target. Each has one current physical documentation destination and an explicit source/no-code role; no additional support UID is implied by an aggregate label.

| Support UID | Exact physical destination and range | Queue relationship and source disposition |
| --- | --- | --- |
| `0000BF` | `by-class/Queue.md`; semantic class covering the `0x18` Queue object and the `0x005539e0-0x00553b6a` source-authored method set. | Sole class declaration/method owner. Owns the exact formal CPP wrapper and H declaration and emits through UID0000MW; it does not own a separate executable range. |
| `0001FN` | `by-memory/0x005539e0-0x00553c07.Queue.md`; executable aggregate `0x005539e0-0x00553c07`. | Complete six-body/internal-padding index. Blank formal channels by design; source bodies route through UID0000BF child order into UID0000MW. |
| `0001FM` | `by-memory/0x005539e0-0x00553a5c.QueueConstructor.md`; `0x005539e0-0x00553a5c`. | Source-authored `Queue::Queue(int slotSize, int slotCount)` body, CPP position `10`; H blank because UID0000BF owns declarations. |
| `0001FO` | `by-memory/0x00553a60-0x00553ab9.QueueDestructor.md`; `0x00553a60-0x00553ab9`. | Source-authored `Queue::~Queue()` body, CPP position `20`; H blank. Compiler vtable/base teardown is excluded from hand-authored source. |
| `0001FP` | `by-memory/0x00553ac0-0x00553b05.QueueWriteSlotRaw.md`; `0x00553ac0-0x00553b05`. | Source-authored inferred `Queue::WriteSlot(const void *slot)` body, CPP position `30`; raw IDA boundary does not change source ownership; H blank. |
| `0001FQ` | `by-memory/0x00553b10-0x00553b55.QueueReadSlotRaw.md`; `0x00553b10-0x00553b55`. | Source-authored inferred `Queue::ReadSlot(void *slot)` body, CPP position `40`; raw IDA boundary does not change source ownership; H blank. |
| `0001FR` | `by-memory/0x00553b60-0x00553b6a.QueueIsEmptyRaw.md`; `0x00553b60-0x00553b6a`. | Source-authored inferred `Queue::IsEmpty() const` body, CPP position `50`; raw IDA boundary does not change source ownership; H blank. |
| `0001FS` | `by-memory/0x00553b70-0x00553c07.QueueScalarDeletingDestructor.md`; `0x00553b70-0x00553c07`. | Compiler-generated scalar deleting destructor. Non-emitting support generated from UID0000BF's virtual destructor; no standalone CPP/H. |
| `0003CS` | `by-memory/0x00622d24-0x00622d30.QueueVtableData.md`; exact three-cell vtable `0x00622d24-0x00622d30`. | Reconstructable generated-data evidence owned/emitted by UID0000BF, but formal CPP/H remain blank because the compiler regenerates it from the class declaration. |
| `0003DH` | `by-memory/0x00622d20-0x00622d24.QueueRttiBoundary.md`; exact COL pointer boundary `0x00622d20-0x00622d24`, indexing remote Queue RTTI at `0x0064e924-0x0064e970` and `0x00678b18-0x00678b2c`. | Parentless, non-reconstructable, non-emitting compiler-data boundary/index. It owns no Queue source and protects the COL/CHD/BCA/BCD/type-descriptor/class-name graph from source emission. |
| `000269` | `by-memory/0x00622d24-0x00622f54.QueueReconnectCopyReadOnlyData.md`; mixed read-only range `0x00622d24-0x00622f54`. | Parentless, non-reconstructable, non-emitting exact-child index. Only UID0003CS within the range is Queue data; all following ConnectionClosedDialog/ReconnectDialog/CopyWindow/string children are excluded from Queue ownership. |

The per-item caller/callee/xref/read/write/lifetime authority remains physical: UID0001FM through UID0001FS carry each code-body route, UID0003CS carries every Queue vtable cell, UID0003DH carries the complete reachable RTTI graph and `.?AVQueue@@` bytes, and UID000269 records the leading/trailing mixed-range boundaries. This page consolidates those destinations without transferring byte ownership or duplicating compiler-generated source.

## Proposed Contents

| Range | Role |
| --- | --- |
| `0x005539e0-0x00553a5c` | [UID:0001FM][0x005539e0-0x00553a5c.QueueConstructor](by-memory/0x005539e0-0x00553a5c.QueueConstructor.md). Emits formal `Queue::Queue(int slotSize, int slotCount)`, using `LObject()`, `GetMemoryMan()->ZeroAllocateBufferMemory(slotSize * slotCount)`, and the accepted `m_slotSize`/`m_slotCount`/`m_buffer`/`m_readIndex`/`m_writeIndex` layout; the vtable store is compiler output. |
| `0x00553a60-0x00553ab9` | [UID:0001FO][0x00553a60-0x00553ab9.QueueDestructor](by-memory/0x00553a60-0x00553ab9.QueueDestructor.md). Emits formal `Queue::~Queue()`, freeing `m_buffer` through `GetMemoryMan()->FreeBufferMemory(m_buffer)` while excluding compiler vtable/base/scalar-delete lowering. |
| `0x00553ac0-0x00553b05` | [UID:0001FP][0x00553ac0-0x00553b05.QueueWriteSlotRaw](by-memory/0x00553ac0-0x00553b05.QueueWriteSlotRaw.md). Emits inferred `Queue::WriteSlot(const void *slot)`, writes one fixed-size element at `writeIndex` through `GetMemoryMan()->MemmoveWrapper`, and advances with wraparound. |
| `0x00553b10-0x00553b55` | [UID:0001FQ][0x00553b10-0x00553b55.QueueReadSlotRaw](by-memory/0x00553b10-0x00553b55.QueueReadSlotRaw.md). Emits inferred `Queue::ReadSlot(void *slot)`, reads one fixed-size element from `m_readIndex` into the caller destination through `GetMemoryMan()->MemmoveWrapper`, and advances with wraparound. |
| `0x00553b60-0x00553b6a` | [UID:0001FR][0x00553b60-0x00553b6a.QueueIsEmptyRaw](by-memory/0x00553b60-0x00553b6a.QueueIsEmptyRaw.md). Emits inferred `Queue::IsEmpty() const`, returning whether `m_readIndex == m_writeIndex`. |
| `0x00553b70-0x00553c07` | [UID:0001FS][0x00553b70-0x00553c07.QueueScalarDeletingDestructor](by-memory/0x00553b70-0x00553c07.QueueScalarDeletingDestructor.md). Non-emitting compiler-generated scalar deleting destructor support; source cleanup belongs to UID0001FO `Queue::~Queue()` and the exact wrapper has no source C++ emitter. |

## Source-Structure Decision

Keep `Queue` under reusable utility/container ownership. Its vtable and `LObject` base make it a project class, not an STL artifact; the strong dormant classification affects confidence and reachability prose, not source ownership.

The current `91/91` score reflects a complete six-body/padding inventory, exact class/header split, deterministic source order, resolved ownership and emitter routing, and explicit compiler-output exclusions. No direct callers are currently modeled for the constructor, ordinary destructor, or raw helper starts, and original symbol spelling is not recovered; those limitations cap the score without reopening the resolved `Queue.cpp`/`Queue.h` source shape.

## Cross-References

- [UID:0000BF][Queue](by-class/Queue.md)
- [UID:0001FN][0x005539e0-0x00553c07.Queue](by-memory/0x005539e0-0x00553c07.Queue.md)
- [UID:0001QA][client_containers](by-meta/client_containers.md)
- [UID:0000L7][MemoryMan](by-file/MemoryMan.md)

## Changes

- 2026-08-11 B010 Gate 2A incorporation repair:
  - Preserved UID0000MW metadata, complete executable census, source/formal ownership, accepted method bodies, reachability conclusion, and historical evidence.
  - Added the exact eleven-UID physical support inventory and authoritative code/vtable/RTTI/mixed-boundary disposition route required by CQM-014 and CQM-018.
- 2026-08-11 B010 accepted whole-file documentation callback:
  - What existed before: `COMPLETION:86`, `CONFIDENCE:85`, valid child source/history, and the correct `NexusTK/util/` source root, but current prose still described the complete header/source shape and aggregate reachability as unresolved.
  - Changed to: `COMPLETION:91`, `CONFIDENCE:91`; retained `PROPOSED_RECONSTRUCTION_PATH:"NexusTK/util/"` and `CANONICAL_OWNER:FILE`; recorded the accepted reconstructable disposition in body prose because singular by-file pages do not carry validator-managed `RECONSTRUCTABLE` metadata; added the exact six-body/padding census, `0x18` layout, class-owned CPP/H split, source order, dormant probability, compiler-output exclusions, negative inventory, and unrelated `BlackHole *` cleanup-global exclusion.
  - Summary/evidence: current by-* ownership, exact raw/modeled ranges and bytes, vtable/RTTI xrefs, seven executed child reports, generated baseline inspection, and the accepted UID0000MW Rule 26 report. Older dated evidence remains historical and is not pruned.
- 2026-07-07 B011 scalar-wrapper support sync:
  - Score remains `COMPLETION:86`, `CONFIDENCE:85`; source route remains `NexusTK/util/Queue.cpp` and `CANONICAL_OWNER:FILE`.
  - Summary/evidence: [UID:0001FS][0x00553b70-0x00553c07.QueueScalarDeletingDestructor](by-memory/0x00553b70-0x00553c07.QueueScalarDeletingDestructor.md) is now non-emitting compiler-generated scalar-wrapper support after B011 MCP session `43ccf853` confirmed exact wrapper range, vtable-only xref from `0x00622d24`, Queue vtable stores, cleanup/delete callees, delete-flag ABI behavior, object-size immediate `0x18`, no Queue UDT/source method symbols, pre-callback generated empty-marker state, and UID0001FO as the formal `Queue::~Queue()` source body. Scalar-wrapper handling is no longer an unresolved source-output blocker; remaining file caps are exact original header spelling, active-use proof, and complete final source layout.
- 2026-07-04 B014 constructor implementation:
  - Score remains `COMPLETION:86`, `CONFIDENCE:85`; source route remains `NexusTK/util/Queue.cpp` and `CANONICAL_OWNER:FILE`.
  - Summary/evidence: [UID:0001FM][0x005539e0-0x00553a5c.QueueConstructor](by-memory/0x005539e0-0x00553a5c.QueueConstructor.md) now emits formal `Queue::Queue(int slotSize, int slotCount)` on the child page after MCP session `eb7ce28b` confirmed exact modeled `0x7c` / 124-byte body, pre/post padding, `LObject` base construction, Queue vtable store as compiler output, `GetMemoryMan()->ZeroAllocateBufferMemory(slotSize * slotCount)`, field layout, zero direct xrefs/callers/VA-RVA route, no local Queue UDT/type/source method symbols, and rejected MemoryMan/LObject/no-owner/aggregate/class/file-emission/raw-name/plain-allocation alternatives. This page preserves broader file-level caveats for exact original `Queue.h` spelling, active use, and complete final Queue source layout; scalar-wrapper no-code handling is resolved by the 2026-07-07 B011 sync.
- 2026-07-04 B006 ordinary-destructor implementation:
  - Score remains `COMPLETION:86`, `CONFIDENCE:85`; source route remains `NexusTK/util/Queue.cpp` and `CANONICAL_OWNER:FILE`.
  - Summary/evidence: [UID:0001FO][0x00553a60-0x00553ab9.QueueDestructor](by-memory/0x00553a60-0x00553ab9.QueueDestructor.md) now emits formal `Queue::~Queue()` on the child page after MCP session `eb7ce28b` confirmed exact modeled `0x59` / 89-byte body, four-byte pre-padding, seven-byte post-padding, `m_buffer` free through `GetMemoryMan()->FreeBufferMemory`, zero direct xrefs/pointer/direct-transfer route, positive scalar-wrapper/vtable corroboration, and rejected raw/decompiler/scalar-wrapper/aggregate/no-owner alternatives. This page preserves broader file-level caveats for constructor/header factoring, active use, and complete final Queue source layout; scalar-wrapper no-code handling is resolved by the 2026-07-07 B011 sync.
- 2026-06-27/2026-06-28 B003 empty-helper implementation:
  - Score remains `COMPLETION:86`, `CONFIDENCE:85`; source route remains `NexusTK/util/Queue.cpp` and `CANONICAL_OWNER:FILE`.
  - Summary/evidence: [UID:0001FR][0x00553b60-0x00553b6a.QueueIsEmptyRaw](by-memory/0x00553b60-0x00553b6a.QueueIsEmptyRaw.md) now emits formal inferred `Queue::IsEmpty() const` C++ on the child page after current MCP session `b001_000241_20260627` reconfirmed exact raw boundary, equality-predicate behavior, layout support, negative xref/pointer/direct-route evidence, no recovered source symbol, no local Queue UDT/type record, and rejected source-name/no-code/metadata alternatives. This page preserves broader file-level caveats for constructor/destructor/header factoring, active use, and full final Queue source layout.
- 2026-07-02 B013 aggregate verification:
  - Support verification found no required file score or source-placement change. [UID:0001FN][0x005539e0-0x00553c07.Queue](by-memory/0x005539e0-0x00553c07.Queue.md) remains routed through [UID:0000BF][Queue](by-class/Queue.md) to this file and is recommended at `87/89` with blank aggregate C++. Current validator-owned `auto-generated/NexusTK/util/Queue.cpp` emits the accepted child `Queue::Queue`, `Queue::~Queue`, `Queue::WriteSlot`, `Queue::ReadSlot`, and `Queue::IsEmpty` bodies; the aggregate and class inventory remain blank route pages, and UID0001FS is non-emitting compiler support after the 2026-07-07 B011 sync.
- 2026-06-27/2026-06-28 B013 read-slot implementation:
  - Score remains `COMPLETION:86`, `CONFIDENCE:85`; source route remains `NexusTK/util/Queue.cpp` and `CANONICAL_OWNER:FILE`.
  - Summary/evidence: [UID:0001FQ][0x00553b10-0x00553b55.QueueReadSlotRaw](by-memory/0x00553b10-0x00553b55.QueueReadSlotRaw.md) now emits formal inferred `Queue::ReadSlot(void *slot)` C++ on the child page after current MCP session `b001_000241_20260627` reconfirmed exact raw boundary, copy-out/wrap behavior, MemoryMan helper vocabulary, layout support, negative xref/pointer/direct-route evidence, no recovered source symbol, no local Queue UDT, and rejected source-name/no-code/metadata alternatives. This page preserves broader file-level caveats for constructor/destructor/header factoring, active use, and the empty helper source-output decision.
- 2026-06-27 B013 write-slot implementation:
  - Score remains `COMPLETION:86`, `CONFIDENCE:85`; source route remains `NexusTK/util/Queue.cpp` and `CANONICAL_OWNER:FILE`.
  - Summary/evidence: [UID:0001FP][0x00553ac0-0x00553b05.QueueWriteSlotRaw](by-memory/0x00553ac0-0x00553b05.QueueWriteSlotRaw.md) emitted formal inferred `Queue::WriteSlot(const void *slot)` C++ on the child page after current MCP session `b001_000241_20260627` reconfirmed exact raw boundary, copy/wrap behavior, MemoryMan helper vocabulary, layout support, negative xref/pointer/direct-route evidence, and rejected source-name alternatives. At that time this page preserved broader file-level caveats for constructor/destructor/header factoring, active use, and read/empty helper source-output decisions; the read helper is now resolved by the later B013 read-slot implementation and the empty helper by the later B003 implementation above.
- 2026-06-16 A002 collision-review source-quality refresh:
  - What existed before: the file page had the 2026-06-10 gate evidence but did not record the corrected C001 collision state, current zero-byte generated root, no-UDT result, or final-C++ source-quality blocker review.
  - Changed to: added the collision-review/source-quality paragraph while keeping `COMPLETION:86`, `CONFIDENCE:85`, `PROPOSED_RECONSTRUCTION_PATH:"NexusTK/util/"`, and `CANONICAL_OWNER:FILE`.
  - Summary/evidence: A002 reviewed the pre-existing Queue edits, retained the valid direct class route through [UID:0000BF][Queue](by-class/Queue.md), verified no direct xrefs or VA/RVA pointer-byte hits for the non-vtable starts, confirmed no local `Queue` UDT evidence, and at that time recorded `auto-generated/NexusTK/util/Queue.cpp` as a zero-byte root; later child implementations and the 2026-07-02 B013 aggregate callback supersede that generated-output state.
- 2026-06-10 A002 strict-gate refresh:
  - What existed before: `COMPLETION:84`, `CONFIDENCE:80`; the page was useful but did not clear the current parent confidence gate for the Queue class/memory children already routed through it.
  - Changed to: `COMPLETION:86`, `CONFIDENCE:85`.
  - Summary/evidence: live IDA MCP reconfirmed modeled constructor/destructor/scalar-deleting destructor bounds, raw not-a-function write/read/empty helper starts, empty caller/xref sets for the non-vtable Queue starts, the scalar deleting destructor vtable xref, `Queue` vtable stores at `0x00553a15`, `0x00553a88`, and `0x00553b9f`, alignment bytes around all children, destructor/free callees, and constructor zero-allocation through `sub_5160D0`. Confidence remained capped at 85 because active direct-use evidence and exact original source names/signatures were unresolved; later B013/B003 implementations now provide inferred child C++ while preserving the active-use and full-source-layout caveats.
- Before: completion/confidence were ungraded at `0/0`.
- Changed to: completion `82`, confidence `76`.
- Summary/evidence: the page documents fixed-slot queue role, compact function cluster, raw helper starts, source-structure decision, active generated omissions, and cross-references; confidence remains capped by uncertain active runtime use and raw not-a-function helper treatment.
- What existed before: `PROPOSED_RECONSTRUCTION_PATH` was blank.
- What it was changed to: `NexusTK/util/`.
- Summary/evidence: `by-project-structure/proposed-source-tree.md` already places `Queue.cpp` under `util/`, and the 2026-05-31 IDA MCP pass confirms the queue cluster is project utility/container code rather than a feature-specific source file.
- 2026-06-01: Raised completion/confidence from `82/76` to `84/80`.
  - Evidence: IDA MCP raw byte review corrected the write/read helper endpoints to `0x00553b05` and `0x00553b55`, confirmed the internal padding spans, and reconfirmed the queue-owned slot-size/slot-count/read-index/write-index behavior. Confidence remains capped at `80` because raw helper starts still have no modeled direct callers.
