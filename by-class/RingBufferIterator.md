*** UID:0000C2 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:82 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:82 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000N8 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL:20 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# RingBufferIterator

## Summary

`RingBufferIterator` is a small companion class/helper in the ring-buffer island. Current evidence supports a real iterator-like type near [UID:0000C1][RingBuffer](by-class/RingBuffer.md): IDA confirms its RTTI/COL, vtable, scalar deleting destructor, and constructor vptr store, while the constructor body and several tiny iterator helpers remain raw code that IDA has not modeled as functions.

## Likely Original Placement

- Source: [UID:0000N8][RingBuffer](by-file/RingBuffer.md)
- Proposed path: `util/RingBuffer.cpp`
- Confidence: strong for concrete class identity and ring-buffer file ownership; active iterator caller/use sites remain unresolved.

## Autogen Status

- Parent file: [UID:0000N8][RingBuffer](by-file/RingBuffer.md)
- Parent position: `20`, after [UID:0000C1][RingBuffer](by-class/RingBuffer.md)
- Reconstructable: `TRUE`
- C++ emission: intentionally blank until direct iterator use sites and helper names are reviewed.

The class-page attachment now matches the RingBuffer file page and the shared vtable documentation. [UID:0001YN][RingBufferVtables](by-type/by-vtable/RingBufferVtables.md) records the same iterator COL pointer at `0x006230d8`, vtable start at `0x006230dc`, scalar deleting destructor slot, and the boundary before adjacent `ScreenPane` RTTI data.

## Inferred Layout

IDA MCP clean disassembly on 2026-06-03 supports a compact 12-byte object layout:

```text
RingBufferIterator
  +0x00  vptr -> ??_7RingBufferIterator@@6B@
  +0x04  RingBuffer* owner
  +0x08  int currentIndex
```

The raw constructor at `0x005566c0` stores `[ebp+0x08]` into `+0x04`, installs vtable `0x006230dc`, initializes `currentIndex` to `-1`, and returns with `retn 4`. The reset/advance/retreat/boundary helpers read `owner + 0x14` as capacity, `owner + 0x18` as storage, `owner + 0x20` as the read boundary, `owner + 0x24` as the write boundary, and `owner + 0x10` as element size.

## Observed Functions

- Raw constructor-shaped body: `0x005566c0-0x005566eb`; IDA has no function object at this start, but raw bytes initialize the base, store the `RingBuffer*`, install vtable `0x006230dc`, set the iterator index to `-1`, and return with `retn 4`.
- IDA-confirmed reset helper: `0x005566f0-0x005566fa`.
- Raw reverse/end-position helper: `0x00556700-0x00556715`; IDA has no function object at this start.
- IDA-confirmed iterator-like advance helper: `0x00556720-0x00556749`.
- Raw retreat helper: `0x00556750-0x00556767`; decrements current index with wrap-around unless already at the ring read boundary.
- Raw boundary predicates: `0x00556770-0x0055677d` and `0x00556780-0x00556794`; compare current or next wrapped index against the ring read boundary.
- Raw element pointer helper: `0x005567a0-0x005567ae`; computes `storage + elementSize * currentIndex`.
- IDA-confirmed deleting destructor-like helper: `0x00556890-0x005568c8`.
- IDA-confirmed vtable: `??_7RingBufferIterator@@6B@` at `0x006230dc`, stored by the raw constructor at `0x005566d7`.
- IDA-confirmed complete-object-locator pointer: `??_R4RingBufferIterator@@6B@` at `0x006230d8`, immediately before vtable `0x006230dc`.
- Existing [UID:0000N8][RingBuffer](by-file/RingBuffer.md) documentation records the iterator constructor, reset, next, and scalar deleting destructor as part of the same `util/RingBuffer.cpp` ownership island as `RingBuffer`.
- Existing [UID:0001YN][RingBufferVtables](by-type/by-vtable/RingBufferVtables.md) documentation records one `RingBufferIterator` vtable at `0x006230dc`, matching the class-page RTTI/COL evidence.

## Interpretation

Treat the iterator class as a useful label for the ring-buffer tail, not as final source-file split proof. The helpers at `0x00556700-0x005567ae` walk ring storage with wrap-around behavior, check boundary conditions against the ring read index, and compute the current element address. The vtable at `0x006230dc` supports a real small polymorphic companion. The missing IDA function object at `0x005566c0` and several tiny helper starts means generated function-boundary metadata still needs review, not that the bytes are arbitrary.

The next dword after the three visible slots is adjacent RTTI data for `ScreenPane`, not a fourth iterator virtual slot.

IDA MCP non-flow xrefs on 2026-06-03 found no direct callers for the constructor/helper starts at `0x005566c0`, `0x005566f0`, `0x00556700`, `0x00556720`, `0x00556750`, `0x00556770`, `0x00556780`, or `0x005567a0`. The only non-flow xref to the scalar deleting destructor is the vtable slot at `0x006230dc`. This keeps confidence at the parent-attachment threshold rather than source-quality final.

## Source Placement

Attach this class under [UID:0000N8][RingBuffer](by-file/RingBuffer.md) after [UID:0000C1][RingBuffer](by-class/RingBuffer.md). The RTTI name, vtable, constructor vptr store, owner-pointer layout, and shared source island make `util/RingBuffer.cpp` the correct current owner.

Leave `RECONSTRUCTION_CPP` blank. The class identity and layout are now strong enough for parent attachment, but unresolved direct-use evidence and final helper names keep this below the C++ emission threshold.

## Score Rationale

Completion is now `82` because the page has class identity, source ownership, parent metadata, compact layout, constructor behavior, iterator helper inventory, vtable/COL evidence, and cross-page alignment with the RingBuffer file/vtable docs. The remaining missing pieces are final helper names, direct caller/use evidence, and a source-quality C++ reconstruction.

Confidence is now `82` because independent local documentation agrees on the RTTI name, COL pointer, vtable address, constructor vptr store, scalar deleting destructor slot, and shared file ownership. Confidence remains capped by raw helper starts that still need function-boundary review and by the unresolved public/private status of the iterator companion.

## Cross-References

- File: [UID:0000N8][RingBuffer](by-file/RingBuffer.md)
- Class: [UID:0000C1][RingBuffer](by-class/RingBuffer.md)
- Memory: [UID:0001G4][0x005563d0-0x005568c8.RingBuffer](by-memory/0x005563d0-0x005568c8.RingBuffer.md)
- Vtable: [UID:0001YN][RingBufferVtables](by-type/by-vtable/RingBufferVtables.md)
- Data issue: [Wave3 data issues](../wave3_data_issues.md)

## Changes

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
