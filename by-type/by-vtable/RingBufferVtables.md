*** UID:0001YN | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000N8 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000N8 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
// The RingBuffer vtable inventory is covered by the RingBuffer and
// RingBufferIterator class declarations; no source table is emitted here.
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# RingBuffer Vtables

## Status

- Entity kind: MSVC vtable inventory
- Owner module: [UID:0000N8][RingBuffer](by-file/RingBuffer.md)
- Owner classes: [UID:0000C1][RingBuffer](by-class/RingBuffer.md), [UID:0000C2][RingBufferIterator](by-class/RingBufferIterator.md)
- Confidence: very strong for exact bytes/hash, addresses, RTTI hierarchies, inherited slot identities, lifecycle stores, wrapper/object sizes, boundaries, pointer uniqueness, and no-adjustor/no-raw-table disposition; capped below 95 only by original source access/header/name spelling.
- Exact by-memory child/evidence range: [UID:0002OQ][0x006230c8-0x006230e8.RingBufferVtableData](by-memory/0x006230c8-0x006230e8.RingBufferVtableData.md)
- Evidence: 2026-05-26, 2026-06-01, and 2026-06-11 IDA MCP `py_eval` over function objects, raw helper starts, vtable entries, complete-object-locator pointers, and data xrefs.

## RingBuffer

IDA names the primary table as `??_7RingBuffer@@6B@` at `0x006230cc`. The complete-object-locator pointer is immediately before the table at `0x006230c8`.

| Slot | Target | Notes |
| --- | --- | --- |
| `+0x00` | `0x005567b0` | `RingBuffer` scalar deleting destructor. |
| `+0x04` | `0x004f4b10` | Inherited `LObject::GetRuntimeClass()`; exact base implementation. |
| `+0x08` | `0x0041b6c0` | Inherited `LObject::OnChangeMessage(LObject *, Message *)`; exact base implementation. |

Observed stores/xrefs to the table base:

- `0x00556408`: constructor vptr store.
- `0x00556508`: non-deleting cleanup body reinstalls the vptr before destruction.
- `0x005567df`: scalar deleting destructor vptr store.

The RingBuffer source destructor is `0x005564e0`; slot `+0x00` instead points to compiler scalar deleting wrapper `0x005567b0`, size 0xd7 / 215, with delete-size immediate `0x28`. The dword at `0x006230d8` is adjacent RTTI data for `RingBufferIterator`, not a fourth `RingBuffer` virtual slot.

## RingBufferIterator

IDA names the companion table as `??_7RingBufferIterator@@6B@` at `0x006230dc`. The complete-object-locator pointer is immediately before the table at `0x006230d8`.

| Slot | Target | Notes |
| --- | --- | --- |
| `+0x00` | `0x00556890` | `RingBufferIterator` scalar deleting destructor. |
| `+0x04` | `0x004f4b10` | Inherited `LObject::GetRuntimeClass()`; exact base implementation. |
| `+0x08` | `0x0041b6c0` | Inherited `LObject::OnChangeMessage(LObject *, Message *)`; exact base implementation. |

Observed store/xref to the table base:

- `0x005566d7`: raw constructor-shaped body stores the iterator vptr.

Wrapper `0x00556890`, size 0x38 / 56, calls only the `LObject` destructor plus conditional delete with size `0x0c`; no ordinary iterator destructor body exists, so the source declaration intentionally relies on its implicit virtual destructor. The dword at `0x006230e8` is adjacent RTTI data for the next class (`ScreenPane`), not a fourth iterator virtual slot.

## Boundary Evidence

IDA MCP `py_eval` on 2026-06-01 confirms the exact data island boundaries:

| Address | Observed value | Interpretation |
|---|---|---|
| `0x006230c4` | `0x00000000` | Terminator after the preceding menu string data. |
| `0x006230c8` | `0x0064edb8` -> `??_R4RingBuffer@@6B@` | `RingBuffer` complete-object-locator pointer. |
| `0x006230cc` | `0x005567b0` -> `sub_5567B0` | Start of `??_7RingBuffer@@6B@`. |
| `0x006230d8` | `0x0064ee04` -> `??_R4RingBufferIterator@@6B@` | `RingBufferIterator` complete-object-locator pointer. |
| `0x006230dc` | `0x00556890` -> `sub_556890` | Start of `??_7RingBufferIterator@@6B@`. |
| `0x006230e8` | `0x0064ee50` -> `??_R4ScreenPane@@6B@` | Next class boundary; excluded from this vtable family. |

The 2026-06-07 A004 Batch 013 read-only IDA MCP refresh reconfirmed the same layout and added current xref details:

- `0x006230cc` is referenced by vptr stores at `0x00556408`, `0x00556508`, and `0x005567df`.
- `0x006230dc` is referenced by the raw `RingBufferIterator` constructor-shaped vptr store at `0x005566d7`.
- Slot targets still resolve to `0x005567b0-0x00556887`, `0x004f4b10-0x004f4b16`, `0x0041b6c0-0x0041b6c3`, and `0x00556890-0x005568c8`.
- The predecessor terminator at `0x006230c4` and successor `ScreenPane` COL pointer at `0x006230e8` keep [UID:0002OQ][0x006230c8-0x006230e8.RingBufferVtableData](by-memory/0x006230c8-0x006230e8.RingBufferVtableData.md) as the exact child range.

The 2026-06-11 A007 Batch 154 live IDA MCP refresh reconfirmed the same dword-level facts before assigning this type page upward:

- `0x006230c4` reads as `0x00000000`, and `0x006230e8` resolves to `??_R4ScreenPane@@6B@`, preserving the exact child range.
- `0x006230cc` remains `??_7RingBuffer@@6B@` with COL `??_R4RingBuffer@@6B@`, slots `0x005567b0`, `0x004f4b10`, and `0x0041b6c0`, and vptr-store xrefs at `0x00556408`, `0x00556508`, and `0x005567df`.
- `0x006230dc` remains `??_7RingBufferIterator@@6B@` with COL `??_R4RingBufferIterator@@6B@`, slots `0x00556890`, `0x004f4b10`, and `0x0041b6c0`, and the raw constructor-shaped vptr-store xref at `0x005566d7`.

## 2026-07-13 Exact ABI Inventory

Healthy database `supervisor_nexustk_20260713` at evidence-collection time returned the exact 32-byte target and bounded lifecycle/shared-slot functions. Target bytes are `B8 ED 64 00 B0 67 55 00 10 4B 4F 00 C0 B6 41 00 04 EE 64 00 90 68 55 00 10 4B 4F 00 C0 B6 41 00`; SHA256 is `BA6C579AF427527C8BC7FEDE62934B82ACBD4E7528ABA2FA1A6B4021F3433B9D`.

| Class | RTTI hierarchy | Inheritance/adjustor result |
| --- | --- | --- |
| `RingBuffer` | COL `0x0064edb8`; type `0x00678cac`; CHD `0x0064edcc`, count 2; base array `0x0064eddc` -> derived BCD `0x0064ede8`, shared LObject BCD `0x00640348` | Derived PMD `(0,-1,0)`, attributes `0x40`: public, unambiguous, non-virtual LObject at offset zero; one primary table, no adjustor. |
| `RingBufferIterator` | COL `0x0064ee04`; type `0x00678cc8`; CHD `0x0064ee18`, count 2; base array `0x0064ee28` -> derived BCD `0x0064ee34`, shared LObject BCD `0x00640348` | Same public zero-offset hierarchy and no secondary/adjusted view. |

- `0x004f4b10`, size 6, returns LObject runtime-class record `0x0061cf44` and has 489 (`0x1e9`) table references; `0x0041b6c0`, size 3, is `retn 8` and has 517 (`0x205`) table references. Shared exact addresses in both tables prove inherited implementations rather than overrides.
- Pointer-location scans found the RingBuffer vtable base only in stores `0x00556408`, `0x00556508`, and `0x005567df`; the iterator base only at `0x005566d7`; each COL only in its exact prefix cell; and each wrapper pointer only in its one table slot.
- Both wrappers use incoming `ecx` directly. Combined with PMD `(0,-1,0)` and primary offset-zero vptr stores, this excludes an adjustor thunk, secondary vtable, virtual base, or nonzero `this` effect.
- No raw table, COL struct, decorated RTTI symbol, fixed address, or deleting-wrapper body belongs in handwritten source. R1/R2 class declarations generate all eight dwords; R3 is a comment-only coverage marker and emits no object definition.

## Child Routing Gate

[UID:0002OQ][0x006230c8-0x006230e8.RingBufferVtableData](by-memory/0x006230c8-0x006230e8.RingBufferVtableData.md) uses this page as its detailed slot/layout evidence, but its autogen parent remains [UID:0000N8][RingBuffer](by-file/RingBuffer.md). Historical A003 Batch 065 validation found that using this nested by-vtable UID as a by-memory autogen parent produced `autogen_parent_unknown`; the file root directly owns the declarations that emit both vtables, so the corrected route remains durable.

This by-vtable page remains assigned upward to [UID:0000N8][RingBuffer](by-file/RingBuffer.md) at `92/94`, retaining owner/emitter UID0000N8, reconstructable true, and blank position. The direct file parent is `90/91`. This does not reroute the exact by-memory child through the type page; both remain sibling evidence/emission markers under the validator-recognized file root.

## Historical Wave3 Status And Current Source Route

Historical Wave3 metadata reported both classes/vtables from shared `util/RingBuffer.cpp`; it is retained as old provenance only and is not current evidence.

The durable current source route is [UID:0000C1][RingBuffer](by-class/RingBuffer.md) R1 at position 10, [UID:0000C2][RingBufferIterator](by-class/RingBufferIterator.md) R2 at position 20, exact method children UID0004EN-UID0004F4 at positions 100-270, compiler-only wrappers UID0004F5/UID0004F6 blank, and comment-only R0/R3 markers. Historical session `1fc4a5a7` left [UID:0004EX][0x005566c0-0x005566eb.RingBufferIteratorConstructorRaw](by-memory/0x005566c0-0x005566eb.RingBufferIteratorConstructorRaw.md) and [UID:0004F4][0x005567a0-0x005567ae.RingBufferIteratorCurrentElementRaw](by-memory/0x005567a0-0x005567ae.RingBufferIteratorCurrentElementRaw.md) as raw/no-function starts, while a later dated target-local pass modeled them as `RingBufferIterator_RingBufferIterator` and `RingBufferIterator_CurrentElement` at their unchanged exact ranges. Other raw-provenance siblings retain their own evidence. None of these method-modeling distinctions require handwritten vtable output.

## Score Rationale

Completion `92` records exact target bytes/hash, both COL/type/CHD/base-array/BCD hierarchies, both three-slot tables, inherited slot identities, lifecycle vptr stores, source-versus-wrapper destructor forms, object sizes, predecessor/successor boundaries, pointer uniqueness, no-adjustor/no-duplicate proof, exact class-declaration map, routing constraint, and R3 no-raw-table output. Confidence `94` reflects direct ABI evidence; original source access/header/name token spelling remains unavailable and prevents a 95+ score.

## Cross-References

- [UID:0000N8][RingBuffer](by-file/RingBuffer.md)
- [UID:0000C1][RingBuffer](by-class/RingBuffer.md)
- [UID:0000C2][RingBufferIterator](by-class/RingBufferIterator.md)
- [UID:0001G4][0x005563d0-0x005568c8.RingBuffer](by-memory/0x005563d0-0x005568c8.RingBuffer.md)
- [UID:0002OQ][0x006230c8-0x006230e8.RingBufferVtableData](by-memory/0x006230c8-0x006230e8.RingBufferVtableData.md)
- [Wave3 data issues](../../wave3_data_issues.md)

## Changes

- 2026-07-13 B003 UID0002OQ source-quality callback:
  - Changed `87/90 -> 92/94`; retained owner/emitter UID0000N8, reconstructable true, and blank position; inserted exact comment-only R3.
  - Added exact target bytes/SHA256, full RTTI hierarchy decode, inherited runtime/message slot identities and totals, source versus scalar-wrapper destructor distinctions, object sizes, pointer uniqueness, no-adjustor/no-secondary/no-duplicate proof, source declaration/compiler-output map, and no-raw-table policy.
  - Historicalized Wave3 and prior `autogen_parent_unknown` language without erasing routing history. UID0002OQ remains directly routed to the file owner, and UID0004EN-UID0004F6 remain unchanged.

- 2026-07-31 B006 UID0001G4 source-quality callback:
  - Corrected the current source-route prose so the historical raw/no-function observations for UID0004EX and UID0004F4 are not presented as permanent current state.
  - Preserved all vtable/RTTI/compiler-output evidence and the no-handwritten-table disposition while recording the later dated modeled constructor/current-element identities at unchanged ranges.

- 2026-06-01:
  - Before: the page was marked `0/0` despite already containing useful vtable-slot documentation, and the exact by-memory vtable-data child was missing.
  - Changed to: scored the page as `84/89`, marked it reconstructable, added exact child [UID:0002OQ][0x006230c8-0x006230e8.RingBufferVtableData](by-memory/0x006230c8-0x006230e8.RingBufferVtableData.md), and recorded the `0x006230c8-0x006230e8` boundary evidence.
  - Summary/evidence: IDA MCP `py_eval` confirms both complete-object-locator pointers, both three-slot vtables, vptr stores at `0x00556408`, `0x00556508`, `0x005567df`, and `0x005566d7`, and the next `ScreenPane` boundary at `0x006230e8`.
- 2026-06-07 A004 Batch 013 associated-parent refresh:
  - Before: the page was `84/89`, just below the corrected parent-assignment gate for exact child [UID:0002OQ][0x006230c8-0x006230e8.RingBufferVtableData](by-memory/0x006230c8-0x006230e8.RingBufferVtableData.md).
  - Changed to: raised to `86/90`, added the 2026-06-07 IDA MCP xref refresh, and recorded that the exact RingBuffer vtable-data child is now assigned here while this by-vtable page remains unassigned upward.
  - Summary/evidence: the refreshed child page and IDA MCP pass confirm the exact dword sequence, slot targets, RingBuffer and RingBufferIterator vptr-store sites, and `ScreenPane` successor boundary; local vtable-data precedent supports by-memory-to-by-vtable parent attachment.
- 2026-06-07 A003 Batch 065 coverage-error repair:
  - Before: [UID:0002OQ][0x006230c8-0x006230e8.RingBufferVtableData](by-memory/0x006230c8-0x006230e8.RingBufferVtableData.md) pointed at this by-vtable UID and generated memory coverage reported `autogen_parent_unknown`.
  - Changed to: kept this page as the `86/90` by-vtable evidence inventory, but rerouted the exact memory child to [UID:0000N8][RingBuffer](by-file/RingBuffer.md) after that file reached `86/85`.
  - Summary/evidence: the file root owns the source declarations that emit both vtables and satisfies the corrected parent gate; this page remains the canonical slot/COL/xref inventory rather than the autogen parent.
- 2026-06-11 A007 Batch 154 source-declaration routing:
  - Before: this page was `86/90` and intentionally unassigned upward after the by-memory child was rerouted to [UID:0000N8][RingBuffer](by-file/RingBuffer.md).
  - Changed to: raised completion to `87`, set `AUTOGEN_PARENT_UID:0000N8`, and kept confidence at `90`. The exact by-memory vtable-data child remains routed directly to the file root.
  - Summary/evidence: live IDA MCP reconfirmed the predecessor terminator, `ScreenPane` successor boundary, both COL pointers, both three-slot vtables, all slot targets, and all vptr-store xrefs. By-type guidance supports assigning this vtable evidence page to the source module that owns the emitting declarations, while generated memory coverage still requires the exact `.rdata` child to use the validator-recognized file parent.

## 2026-07-31 Catalog0380 Applied IDA Reconciliation

- Supervisor catalog `0380` used prestate IDB SHA256 `4B5F2EC3F83106BAC18640D079C51CD2E2FB56797577EFE7D994EF483D9A696A`, 143,192,707 bytes, preserved by byte-identical backup `E:\NTK\Resources\NexusTK\backups\NexusTK.exe.pre-B006-UID0001G4-20260731_053341.i64`. `idb_save` returned `ok:true`; saved poststate is SHA256 `1BC3C43BCEDB92B9BF8950DA6E6DE759C3FA44B50C6A2FA0458CE129B6800CFD`, 143,195,497 bytes, at `2026-07-31T05:35:32.8233834-04:00`; `4B5F...` is dated pre-catalog0380 history.
- Catalog0380 applied only accepted source-quality frame/local names after a `12/12` collision-safe dry run: enqueue physical `record +0x10/4 const void *` plus locals `memoryMan`/`writeIndex`/`nextWriteIndex`/`notEmptyCondition`; dequeue locals `memoryMan`/`readIndex`/`nextReadIndex`/`notFullCondition`; advance locals `currentIndex`/`owner`/`nextIndex`. A failed direct local-type attempt made no change; the documented stack API with frame-pointer displacement `+0x8` applied the enqueue argument type without duplication.
- Both decorated tables remain exact: `??_7RingBuffer@@6B@` and `??_7RingBufferIterator@@6B@`, their COL preheads/targets, exact comments, and `3/1` incoming vptr-store xrefs are unchanged. RingBuffer remains 40 bytes/ten members; RingBufferIterator remains 12 bytes/three members; Monitor/MonitorCondition remain 16 bytes/four members; MemoryMan/LObject remain incomplete zero-member declarations.
- The five authored method ranges, accepted types/comments/frames, body hashes `47B378...F003`, `43921F...2E38`, `6EC7AA...0A4F`, `8531BD...449B`, `FBD7D2...E480`, successor fences `5/4/6/7/2` bytes of `CC`, and incoming target xrefs `0/5/1/0/0` remain unchanged. Compiler scalar deleting wrappers and all RTTI/vtable data remain compiler output.
- Shared helper `sub_4F4A80` remains raw, unrenamed, uncommented, and typed `_DWORD *__thiscall(_DWORD *this)`; current incoming xrefs are `195`, replacing the dated `157` count without changing its protected shared-helper/source classification.
- Formal CPP/H and the no-handwritten-vtable disposition remain unchanged. Catalog0380 only synchronizes this ABI inventory with the applied IDA source-quality poststate.
- Post-catalog0380 currentness: bounded read-only session `f608d7c2` against catalog0382-era physical IDB SHA256 `B7CC899DA786D8D49AE13525B844AA85CCF3C21C73D00DB2AE337FF838058277`, 143,192,751 bytes, saved `2026-07-31T06:21:13.3464834-04:00`, reverified exact 32-byte vtable-data SHA256 `BA6C579AF427527C8BC7FEDE62934B82ACBD4E7528ABA2FA1A6B4021F3433B9D`, decorated table/COL names and comments, scalar-wrapper types, `3/1` vptr-store xrefs, exact UDT layouts, all five target hashes/fences/xrefs, applied locals/frame, and raw helper `sub_4F4A80` with `195` incoming xrefs. The prior `5F2679A7...FC79A21` checkpoint, catalog0380 save `1BC3...0CFD`, and prestate `4B5F...A696A` are dated history; final moving shared-IDB currentness remains supervisor-controlled.
