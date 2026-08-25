*** UID:0000C2 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:89 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:91 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000N8 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000N8 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL:20 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
class RingBufferIterator : public LObject
{
public:
    RingBufferIterator(RingBuffer *owner);

    void Reset();
    void SetToLast();
    void Advance();
    void Retreat();
    bool AtReadBoundary() const;
    bool NextAtWriteBoundary() const;
    void *CurrentElement() const;

private:
    RingBuffer *mOwner;
    int mCurrentIndex;
};
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# RingBufferIterator

## Summary

`RingBufferIterator` is a concrete 0x0c-byte companion class in the ring-buffer island. It publicly and non-virtually derives from `LObject` at offset zero, stores one [UID:0000C1][RingBuffer](by-class/RingBuffer.md) owner pointer and one signed current index, and exposes the complete retained traversal/boundary/element helper family. IDA confirms its RTTI/COL, one primary vtable, raw constructor vptr store, and compiler scalar deleting wrapper; raw/no-function starts and zero callers are retained source-quality caveats rather than reasons to omit the source declaration.

## Likely Original Placement

- Source: [UID:0000N8][RingBuffer](by-file/RingBuffer.md)
- Reconstruction paths: declaration in `NexusTK/util/RingBuffer.h` at position `20`, after the [UID:0000C1][RingBuffer](by-class/RingBuffer.md) declaration; qualified definitions remain independently positioned in `NexusTK/util/RingBuffer.cpp`.
- Confidence: strong for concrete class identity, exact layout, public zero-offset `LObject` inheritance, implicit virtual destructor lowering, and one-file ownership. Zero active callers plus unrecovered original helper/access/header spelling cap confidence without blocking R2.
- Historical evidence: the 2026-06-14 pass on database `b001_0003gy` reconfirmed the raw constructor, helper starts, vtable/COL refs, and no-direct-caller caveat. Its old conclusion that final C++ must remain blank below a generic code-entry gate is superseded by the accepted exact child bodies, current RTTI/ABI proof, and R2.

## Autogen Status

- Parent file: [UID:0000N8][RingBuffer](by-file/RingBuffer.md)
- Parent position: `20`, after [UID:0000C1][RingBuffer](by-class/RingBuffer.md)
- Reconstructable: `TRUE`
- C++ emission: the exact R2 declaration is in H, the class CPP channel is blank, and existing UID0004EX-UID0004F4 method definitions remain independent namespace-scope emitters in `RingBuffer.cpp`.

The class-page attachment now matches the RingBuffer file page and the shared vtable documentation. [UID:0001YN][RingBufferVtables](by-type/by-vtable/RingBufferVtables.md) records the same iterator COL pointer at `0x006230d8`, vtable start at `0x006230dc`, scalar deleting destructor slot, and the boundary before adjacent `ScreenPane` RTTI data.

## Inferred Layout

IDA MCP constructor/helper disassembly, RTTI, and the 0x0c delete-size immediate prove this compact 12-byte object layout:

```text
RingBufferIterator
  +0x00  public LObject base / vptr -> ??_7RingBufferIterator@@6B@
  +0x04  RingBuffer *mOwner
  +0x08  int mCurrentIndex
```

The raw constructor at `0x005566c0` calls the `LObject` constructor, stores `[ebp+0x08]` into `+0x04`, installs vtable `0x006230dc`, initializes `mCurrentIndex` to `-1`, and returns with `retn 4`. The reset/advance/retreat/boundary helpers read owner capacity `+0x14`, storage `+0x18`, read boundary `+0x20`, write boundary `+0x24`, and element size `+0x10`. The 4-byte base plus two 4-byte members closes exactly at 0x0c with no tail padding. R1's private fields and `friend class RingBufferIterator` permit these direct reads without decompiler-shaped public queue state; exact access tokens remain inferred.

## Observed Functions

- [UID:0004EX][0x005566c0-0x005566eb.RingBufferIteratorConstructorRaw](by-memory/0x005566c0-0x005566eb.RingBufferIteratorConstructorRaw.md): dated target-local IDA models this exact retained `Raw`-path range as `RingBufferIterator_RingBufferIterator`; it initializes the base, stores the `RingBuffer*`, installs vtable `0x006230dc`, sets current index to `-1`, and returns with `retn 4`.
- [UID:0004EY][0x005566f0-0x005566fa.RingBufferIteratorReset](by-memory/0x005566f0-0x005566fa.RingBufferIteratorReset.md): sets current index from the ring read index at `+0x20`.
- [UID:0004EZ][0x00556700-0x00556715.RingBufferIteratorSetToLastRaw](by-memory/0x00556700-0x00556715.RingBufferIteratorSetToLastRaw.md): computes `(writeIndex - 1 + capacity) % capacity`.
- [UID:0004F0][0x00556720-0x00556749.RingBufferIteratorAdvance](by-memory/0x00556720-0x00556749.RingBufferIteratorAdvance.md): advances current index unless the next wrapped index reaches the ring write boundary at `+0x24`.
- [UID:0004F1][0x00556750-0x00556767.RingBufferIteratorRetreatRaw](by-memory/0x00556750-0x00556767.RingBufferIteratorRetreatRaw.md): decrements current index with wrap-around unless already at the ring read boundary.
- [UID:0004F2][0x00556770-0x0055677d.RingBufferIteratorAtReadBoundaryRaw](by-memory/0x00556770-0x0055677d.RingBufferIteratorAtReadBoundaryRaw.md): emits source-ready `RingBufferIterator::AtReadBoundary() const`; fresh B003 MCP session `31debdf2` confirmed a 13-byte raw no-function predicate with unique signature `8B 51 04 8B 41 08 3B 42 20 0F 94 C0 C3`, loading owner `[ecx+4]`, current index `[ecx+8]`, comparing against the ring read index `[edx+20h]`, and returning through `setz al`.
- [UID:0004F3][0x00556780-0x00556794.RingBufferIteratorNextAtWriteBoundaryRaw](by-memory/0x00556780-0x00556794.RingBufferIteratorNextAtWriteBoundaryRaw.md): checks whether the next wrapped slot equals the ring write index.
- [UID:0004F4][0x005567a0-0x005567ae.RingBufferIteratorCurrentElementRaw](by-memory/0x005567a0-0x005567ae.RingBufferIteratorCurrentElementRaw.md): dated target-local IDA models this exact retained `Raw`-path range as `RingBufferIterator_CurrentElement`; it computes `storage + elementSize * currentIndex`.
- [UID:0004F6][0x00556890-0x005568c8.RingBufferIteratorScalarDeletingDestructor](by-memory/0x00556890-0x005568c8.RingBufferIteratorScalarDeletingDestructor.md): vtable-only compiler wrapper.
- IDA-confirmed vtable: `??_7RingBufferIterator@@6B@` at `0x006230dc`, stored by the raw constructor at `0x005566d7`.
- IDA-confirmed complete-object-locator pointer: `??_R4RingBufferIterator@@6B@` at `0x006230d8`, immediately before vtable `0x006230dc`.
- Existing [UID:0000N8][RingBuffer](by-file/RingBuffer.md) documentation records the iterator constructor, reset, next, and scalar deleting destructor as part of the same `util/RingBuffer.cpp` ownership island as `RingBuffer`.
- Existing [UID:0001YN][RingBufferVtables](by-type/by-vtable/RingBufferVtables.md) documentation records one `RingBufferIterator` vtable at `0x006230dc`, matching the class-page RTTI/COL evidence.

## Interpretation

Treat the iterator as a real retained source companion, not a separate-file split or merely a generated label. The helpers at `0x00556700-0x005567ae` walk ring storage with wrap-around behavior, use the read index for reset/start and reverse-boundary checks, use the write index for forward end checks, and compute the current element address. RTTI, constructor, complete bodies, one primary vtable, and scalar-wrapper lowering prove the declaration even though current executable use is absent. Missing IDA function objects at raw starts remain function-boundary metadata facts, not source suppression evidence.

The next dword after the three visible slots is adjacent RTTI data for `ScreenPane`, not a fourth iterator virtual slot.

IDA MCP non-flow xrefs on 2026-06-03, 2026-06-14, and the accepted 2026-07-13 pass found no direct callers for the constructor/helper starts at `0x005566c0`, `0x005566f0`, `0x00556700`, `0x00556720`, `0x00556750`, `0x00556770`, `0x00556780`, or `0x005567a0`. The only non-flow xref to the scalar deleting destructor is the vtable slot at `0x006230dc`. This rules out claims of active use, public exposure, factory ownership, or a separate iterator source file, but does not erase a fully represented retained source class.

The 2026-07-03 B003 UID0004F2 callback refreshed the read-boundary predicate under MCP session `31debdf2`: `lookup_funcs` still reports no function object at `0x00556770`, `xrefs_to 0x00556770` reports zero direct xrefs, and bytes around the helper prove `0x00556767-0x00556770` / `0x0055677d-0x00556780` are `0xcc` alignment. The accepted target evidence keeps `AtReadBoundary()` as an inferred but source-ready helper name and preserves the same class-level confidence caps for exact original helper spelling and iterator exposure.

## 2026-06-14 Live Evidence

- Historical session `b001_0003gy` reported no function object at raw starts `0x005566c0`, `0x00556700`, `0x00556750`, `0x00556770`, `0x00556780`, or `0x005567a0`; it reported modeled helpers at `0x005566f0` size `0xa`, `0x00556720` size `0x29`, and `0x00556890` size `0x38`. The constructor/current-element part of that function-object map is retained as dated history and is superseded by the later target-local model below.
- `disasm 0x005566c0` shows a complete constructor-shaped body: base call `0x004f4a80`, owner pointer store at `+0x4`, vptr store to `0x006230dc`, current index `-1` at `+0x8`, and `retn 4` at `0x005566e8`.
- Historical `disasm 0x005567a0` showed the then-raw element pointer helper computing `owner->storage + owner->elementSize * currentIndex`, followed by alignment before the RingBuffer deleting destructor at `0x005567b0`; its bytes and range remain valid despite later function modeling.
- `xrefs_to 0x006230dc` reports the constructor vptr store at `0x005566d7`; `xrefs_to 0x00556890` reports the vtable slot at `0x006230dc`; no direct code xrefs were found for the raw constructor or iterator helpers.
- `make_signature_for_range 0x005566c0-0x005566eb` returned a unique byte signature for the raw constructor.

## Dated Target-Local Modeling Reconciliation

- Dated B006 session `f608d7c2` against saved checkpoint `9F8A96C42F981A4F0AE091DCDD76CD7CC9CDEAF26C3EC8E31461E16CB881441E` modeled `[0x005566c0,0x005566eb)` as `RingBufferIterator_RingBufferIterator`, size `0x2b`, with prototype `RingBufferIterator *__thiscall(RingBufferIterator *this, RingBuffer *owner)`.
- The same pass modeled `[0x005567a0,0x005567ae)` as `RingBufferIterator_CurrentElement`, size `0x0e`, with prototype `void *__thiscall(const RingBufferIterator *this)`.
- Exact bytes, constructor vptr/field behavior, current-element calculation, alignment fences, and zero incoming caller counts were unchanged. The stable filenames retain `Raw` as historical provenance rather than asserting current no-function state.
- Other raw siblings at `0x00556700`, `0x00556750`, `0x00556770`, and `0x00556780` keep their own current evidence; this correction does not group them with the two later-modeled targets.
- The saved checkpoint is dated evidence, not durable shared-IDB authority. Supervisor Gate 2B must reread the exact function identities, types, comments, frames, bytes, and xrefs before any IDA action.

## 2026-07-13 RTTI And Destructor Evidence

- Healthy database `supervisor_nexustk_20260713` at evidence-collection time reconfirmed real target bytes/functions, the raw constructor, all helper starts, vtable xrefs, and zero incoming xrefs to the eight source starts.
- COL `0x0064ee04`, type descriptor `0x00678cc8` (`??_R0?AVRingBufferIterator@@@8`), CHD `0x0064ee18` with two bases, base array `0x0064ee28`, derived BCD `0x0064ee34`, shared LObject BCD `0x00640348`, PMD `(0,-1,0)`, and attributes `0x40` prove public, unambiguous, non-virtual `LObject` inheritance at offset zero.
- The only table-base store is raw constructor instruction `0x005566d7`; pointer scans found the COL only at target cell `0x006230d8` and deleting-wrapper pointer only at slot `0x006230dc`. No duplicate table, secondary view, adjustor, or nonzero `this` displacement exists.
- Slot `+0x04` is exact inherited `LObject::GetRuntimeClass()` at `0x004f4b10`; slot `+0x08` is exact inherited `LObject::OnChangeMessage(LObject *, Message *)` at `0x0041b6c0`. Neither is an iterator override.
- Wrapper `0x00556890`, size 0x38 / 56, calls only the `LObject` destructor and conditional delete with size `0x0c`; no ordinary iterator destructor body or derived vptr restore exists. Because the base destructor is virtual, the best source form is an implicit virtual derived destructor. R2 deliberately declares no destructor and UID0004F6 remains compiler-only/blank.
- Exact target [UID:0002OQ][0x006230c8-0x006230e8.RingBufferVtableData](by-memory/0x006230c8-0x006230e8.RingBufferVtableData.md) has SHA256 `BA6C579AF427527C8BC7FEDE62934B82ACBD4E7528ABA2FA1A6B4021F3433B9D` and ends before the `ScreenPane` COL at `0x006230e8`.

## Source Placement

Attach this class under [UID:0000N8][RingBuffer](by-file/RingBuffer.md) after [UID:0000C1][RingBuffer](by-class/RingBuffer.md). The RTTI name, vtable, constructor vptr store, owner-pointer layout, and shared source island make the `util/RingBuffer.h` / `util/RingBuffer.cpp` pair the correct current owner.

Emit R2 at position `20` in `NexusTK/util/RingBuffer.h`; keep its qualified method definitions in independently positioned children in `NexusTK/util/RingBuffer.cpp`. The class CPP channel remains blank so it cannot duplicate the header declaration. Keep it in the same source/header family as RingBuffer because the code/data islands, direct field relationship, and one file owner agree; there is no independent iterator source-file evidence. The class declaration is source-authored, while its RTTI/vtable/trivial scalar deleting wrapper are compiler output documented by UID0002OQ/UID0001YN/UID0004F6 and must not be hand-emitted.

## Score Rationale

Completion `89` records the complete R2 declaration, exact 0x0c closure, constructor and seven helper children, public zero-offset LObject RTTI, inherited slots/no overrides, implicit virtual-destructor proof, unique vptr route, one-file placement, friend/private access model, and zero-caller interpretation.

Confidence `91` reflects independent agreement among exact bytes, RTTI, constructor/helper behavior, wrapper size, child docs, and source route. It remains below RingBuffer's score because no current caller proves exposure/liveness and original helper names, header visibility, and public/private placement beyond RTTI inheritance remain inferred.

## Cross-References

- File: [UID:0000N8][RingBuffer](by-file/RingBuffer.md)
- Class: [UID:0000C1][RingBuffer](by-class/RingBuffer.md)
- Memory: [UID:0001G4][0x005563d0-0x005568c8.RingBuffer](by-memory/0x005563d0-0x005568c8.RingBuffer.md)
- Vtable: [UID:0001YN][RingBufferVtables](by-type/by-vtable/RingBufferVtables.md)
- Historical data issue only: [Wave3 data issues](../wave3_data_issues.md); Wave3 material is not current evidence or a current blocker.

## Changes

- 2026-07-31 B006 UID0001G4 source-route callback:
  - Cleared the duplicate CPP-local R2 declaration and placed the exact 0x0c `RingBufferIterator` declaration in the H channel after RingBuffer.
  - Preserved all independently positioned method children and compiler-only scalar wrapper; no score, owner, layout, RTTI, or helper-body decision changed.
  - Historicalized the older no-function observations for UID0004EX/UID0004F4 and added the later dated modeled names, ranges, prototypes, unchanged bytes, and zero-caller readback without altering still-raw siblings.
- 2026-07-13 B003 UID0002OQ source-quality callback:
  - Changed `85/86 -> 89/91`, retained owner/emitter UID0000N8 and reconstructable true, set position `20`, and inserted exact R2 with the class closed before `[[CHILDREN]]`.
  - Added exact 0x0c layout closure, public zero-offset LObject RTTI, inherited slot names/no overrides, implicit virtual-destructor/scalar-wrapper proof, unique vptr/no-adjustor/no-duplicate evidence, all helper declarations, zero-caller interpretation, friend/private access model, one-file compiler-output map, and source-name/access/header confidence caps.
  - Historicalized obsolete generic score-gate/blank-until-direct-use and Wave3 wording while preserving every raw boundary, helper behavior, no-caller negative, and prior callback fact. UID0004EX-UID0004F6 remain unchanged.

- 2026-05-30: Changed completion/confidence from `0/0` to `72/76`.
  - Before: The page was unevaluated despite documenting the iterator-like companion, raw constructor bytes, modeled helper starts, vtable, and unresolved caller/use sites.
  - After: Scored as moderate-high completion and medium-high confidence because ring-buffer file ownership and vtable identity are strong, but concrete class identity and active iterator use remain partly unresolved.
  - Evidence: Existing observed-functions list, interpretation notes, generated metadata comparison, and ring-buffer/vtable cross-references support the score.
- 2026-06-01: Expanded the observed raw helper set from IDA MCP disassembly.
  - Evidence: raw bytes show complete helper bodies at `0x00556750`, `0x00556770`, `0x00556780`, and `0x005567a0`; the raw constructor endpoint was corrected to include its epilogue and `retn 4`.
- 2026-06-03: Added RTTI/layout proof and parent attachment.
  - Before: The page was `72/76`, reconstructability and parent metadata were blank, and the class identity still leaned too heavily on generated metadata plus vtable naming.
  - After: Raised to `78/80`, marked reconstructable, attached to [UID:0000N8][RingBuffer](by-file/RingBuffer.md) at position `20`, and kept C++ blank.
  - Evidence: IDA MCP clean disassembly confirms the raw constructor stack argument, vptr store, owner pointer, and current-index field; RTTI/COL data names `??_R4RingBufferIterator@@6B@`; the vtable at `0x006230dc` points to the scalar deleting destructor and is stored by the raw constructor; non-flow xref sweeps still show no direct active callers for the iterator helper starts.
- 2026-06-07: Reconciled the class page with the existing RingBuffer file and vtable documentation.
  - Before: The page had strong identity/layout evidence but no explicit autogen-status or score-rationale section, and two observed-function bullets still cited generated output directly instead of the durable project documentation pages.
  - After: Raised to `82/82`, added autogen-status and score-rationale sections, and redirected the generated-output bullets to the existing [UID:0000N8][RingBuffer](by-file/RingBuffer.md) and [UID:0001YN][RingBufferVtables](by-type/by-vtable/RingBufferVtables.md) documentation.
  - Evidence: The file page and vtable page agree on parent attachment, `util/RingBuffer.cpp` ownership, COL pointer `0x006230d8`, vtable `0x006230dc`, and scalar deleting destructor slot; unresolved direct iterator callers and final helper names keep C++ blank.
- 2026-06-14 A001 Goal 2 refresh:
  - Before: `82/82`; the page had strong identity but older raw-byte evidence and no current no-caller confirmation.
  - Changed to: `85/86`; final C++ remains blank below `90/90+`.
  - Evidence: live IDA MCP database `b001_0003gy` reconfirmed modeled/raw helper boundaries, the exact raw constructor instructions and unique signature, the raw element pointer helper, vtable/COL refs, and no-direct-caller status for iterator helpers.
- 2026-07-03 B006 UID0001G4 implementation callback:
  - Synchronized observed functions with exact child pages [UID:0004EX][0x005566c0-0x005566eb.RingBufferIteratorConstructorRaw](by-memory/0x005566c0-0x005566eb.RingBufferIteratorConstructorRaw.md) through [UID:0004F6][0x00556890-0x005568c8.RingBufferIteratorScalarDeletingDestructor](by-memory/0x00556890-0x005568c8.RingBufferIteratorScalarDeletingDestructor.md) after [UID:0001G4][0x005563d0-0x005568c8.RingBuffer](by-memory/0x005563d0-0x005568c8.RingBuffer.md) was converted to a split/index parent.
  - Corrected helper boundary wording from the accepted MCP session `1fc4a5a7`: reset/current-start uses read index `+0x20`; advance/end checks use write index `+0x24`. No class metadata score change was required.
- 2026-07-03 B003 UID0004F2 implementation callback:
  - Added current MCP session `31debdf2` evidence for [UID:0004F2][0x00556770-0x0055677d.RingBufferIteratorAtReadBoundaryRaw](by-memory/0x00556770-0x0055677d.RingBufferIteratorAtReadBoundaryRaw.md): exact range size `0x0d` / 13 bytes, unique signature `8B 51 04 8B 41 08 3B 42 20 0F 94 C0 C3`, no IDA function object, zero direct xrefs, read-index compare at owner `+0x20`, and padding on both sides.
  - No class metadata score change was required because direct helper callers, exact original helper spelling, and public/private iterator exposure remain unresolved at class scope.

## 2026-07-31 Catalog0380 Applied IDA Reconciliation

- Supervisor catalog `0380` used prestate IDB SHA256 `4B5F2EC3F83106BAC18640D079C51CD2E2FB56797577EFE7D994EF483D9A696A`, 143,192,707 bytes, preserved by byte-identical backup `E:\NTK\Resources\NexusTK\backups\NexusTK.exe.pre-B006-UID0001G4-20260731_053341.i64`. Saved poststate is SHA256 `1BC3C43BCEDB92B9BF8950DA6E6DE759C3FA44B50C6A2FA0458CE129B6800CFD`, 143,195,497 bytes, at `2026-07-31T05:35:32.8233834-04:00`; `4B5F...` is dated pre-catalog0380 history.
- A collision-safe `12/12` dry run preceded application. Iterator-advance locals are now `currentIndex`, `owner`, and `nextIndex`. The same transaction applied enqueue physical `record +0x10/4 const void *`, enqueue locals `memoryMan`/`writeIndex`/`nextWriteIndex`/`notEmptyCondition`, and dequeue locals `memoryMan`/`readIndex`/`nextReadIndex`/`notFullCondition`. The first direct local-type attempt returned `ok:false` without applying; stack API displacement `+0x8` then produced the exact enqueue physical poststate with no duplicate member.
- `RingBufferIterator_RingBufferIterator`, `RingBufferIterator_Advance`, and `RingBufferIterator_CurrentElement` retain their exact accepted ranges, types, regular comments, frames outside the renamed locals, and absent other comment channels. Their body hashes remain `47B378923AAE1A4A4B3F45BB1470737FB6FE2EEF4F0EDD211BB0AA2C265CF003`, `8531BD461F8926EBCEFD5516CE8405CA9F06A64D4511EE9D3BC94C815BE7449B`, and `FBD7D28C9EF8AE54E2A4BCC43B66BCD0467B0E4DBE9250E7979D0D81F665E480`; successor fences remain `5/7/2` bytes of `CC`; each still has zero direct xrefs.
- RingBuffer enqueue/dequeue identities, types, comments, body hashes `43921F...2E38` and `6EC7AA...0A4F`, fences `4/6`, and xrefs `5/1` remain unchanged. Protected constructor local `var_4` remains untouched.
- Type protection retains `RingBufferIterator` size `0x0c` / 12 bytes with three members, `RingBuffer` size `0x28` / 40 bytes with ten members, `Monitor`/`MonitorCondition` size `0x10` with four members each, and incomplete zero-member `MemoryMan`/`LObject`. Iterator and RingBuffer decorated vtables/COLs/comments and `3/1` xrefs remain unchanged.
- Shared helper `sub_4F4A80` remains raw, unrenamed, uncommented, and typed `_DWORD *__thiscall(_DWORD *this)`; current incoming xrefs are `195`, replacing the dated `157` count without changing its protected shared-helper role.
- Catalog0380 does not change this class's source declaration, exact layout, formal CPP/H, score, owner/emitter route, raw-sibling evidence, or access-exposure caveat.
- Post-catalog0380 currentness: bounded read-only session `f608d7c2` against catalog0382-era physical IDB SHA256 `B7CC899DA786D8D49AE13525B844AA85CCF3C21C73D00DB2AE337FF838058277`, 143,192,751 bytes, saved `2026-07-31T06:21:13.3464834-04:00`, reverified the 12-byte/three-member iterator UDT, protected constructor/current-element identities and frames, applied advance locals `currentIndex`/`owner`/`nextIndex`, exact body hashes/fences/zero-xref state, iterator vtable/COL and one vptr-store xref, and raw helper `sub_4F4A80` with `195` incoming xrefs. The prior `5F2679A7...FC79A21` checkpoint, catalog0380 save `1BC3...0CFD`, and prestate `4B5F...A696A` are dated history; final moving shared-IDB currentness remains supervisor-controlled.
