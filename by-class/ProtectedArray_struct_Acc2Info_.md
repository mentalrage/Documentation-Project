*** UID:0000AY | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:87 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:91 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000MU | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000MU | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
// Concrete ProtectedArray<Acc2Info> template instantiation.
// Reusable source behavior is represented by [UID:000186][0x004e5f20-0x004e5f95.ProtectedArrayImageInfoAccessors](by-memory/0x004e5f20-0x004e5f95.ProtectedArrayImageInfoAccessors.md), [UID:00017V][0x004e5a70-0x004e5b6f.ProtectedArrayImageInfoOrdinaryDestructors](by-memory/0x004e5a70-0x004e5b6f.ProtectedArrayImageInfoOrdinaryDestructors.md), and compiler-wrapper coverage [UID:000187][0x004e5fa0-0x004e629f.ProtectedArrayImageInfoDeletingDestructors](by-memory/0x004e5fa0-0x004e629f.ProtectedArrayImageInfoDeletingDestructors.md).
// Embedded record use remains with [UID:0000JY][HumanImageLib](by-file/HumanImageLib.md) HumanImageLib; do not emit a standalone original source class here.
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# ProtectedArray_struct_Acc2Info_

## Status

- Confidence: very strong for binary identity, accessor/destructor/vtable evidence, owner routing, and HumanImageLib embedding; medium for final original declaration spelling.
- Source-level name: `ProtectedArray<Acc2Info>`
- Source-level owner/emitter: [UID:0000MU][ProtectedArray](by-file/ProtectedArray.md) reusable template support.
- Concrete feature embedder: [UID:0000JY][HumanImageLib](by-file/HumanImageLib.md), with the embedded field recorded as `acc2Array` at `HumanImageLib +0x19c` by [UID:0001UR][HumanImageLibLayout](by-type/by-struct/HumanImageLibLayout.md).
- Current generated file: `source-3/simroot_v2/class_ProtectedArray_struct_Acc2Info_.cpp`
- Rebuild handling: source-declared/generated-binary template support; parented to [UID:0000MU][ProtectedArray](by-file/ProtectedArray.md), with concrete old-human record loading owned by [UID:0000JY][HumanImageLib](by-file/HumanImageLib.md).
- Output route: `CANONICAL_OWNER` and `EMITTER_UIDS` both route to [UID:0000MU][ProtectedArray](by-file/ProtectedArray.md). This class-level `RECONSTRUCTION_CPP` block remains blank for declaration/header-field caveats, but the accessor C++ blocker is resolved by [UID:000186][0x004e5f20-0x004e5f95.ProtectedArrayImageInfoAccessors](by-memory/0x004e5f20-0x004e5f95.ProtectedArrayImageInfoAccessors.md), which now emits the generic `ProtectedArray<T>::GetAtOrDefault(int index)` source body covering the concrete `Acc2Info` instantiation.

## Methods

| Address | Method | Notes |
| --- | --- | --- |
| `0x004e5a80` | ordinary destructor | Resets `ProtectedArray<Acc2Info>` vtable and frees backing storage. |
| `0x004e5f40` | `GetAtOrDefault(int index)` | Bounds-checked accessor using a `0x14` byte element stride. |
| `0x004e5fd0` | scalar deleting destructor | Ordinary cleanup plus conditional `operator delete`. |

## Ownership Notes

`HumanImageLib::HumanImageLib` uses this accessor while populating old accessory draw metadata. Keep the reusable template body in shared `ProtectedArray` support and the concrete record loading, field ownership, and draw/composition semantics in `HumanImageLib`.

## Evidence Notes

[UID:0001WR][ProtectedArrayTemplates](by-type/by-template/ProtectedArrayTemplates.md) records `ProtectedArray<Acc2Info>` at ordinary destructor `0x004e5a80`, accessor `0x004e5f40`, and deleting destructor `0x004e5fd0`. [UID:000186][0x004e5f20-0x004e5f95.ProtectedArrayImageInfoAccessors](by-memory/0x004e5f20-0x004e5f95.ProtectedArrayImageInfoAccessors.md) verifies the `GetAtOrDefault` bounds check, `+0x04` count, `+0x08` entries pointer, `+0x10` fallback record, and `0x14` byte element stride. [UID:00017V][0x004e5a70-0x004e5b6f.ProtectedArrayImageInfoOrdinaryDestructors](by-memory/0x004e5a70-0x004e5b6f.ProtectedArrayImageInfoOrdinaryDestructors.md) and [UID:000187][0x004e5fa0-0x004e629f.ProtectedArrayImageInfoDeletingDestructors](by-memory/0x004e5fa0-0x004e629f.ProtectedArrayImageInfoDeletingDestructors.md) cover the exact destructor bodies. [UID:0001XQ][HumanImageLibVtable](by-type/by-vtable/HumanImageLibVtable.md) records the `ProtectedArray<Acc2Info>` vtable at `0x0061b6ac` with slot target `0x004e5fd0`.

2026-06-16 A001 live IDA/PE refresh:

- `lookup_funcs` in IDA database `b001_mappane_0001AW_20260616` still resolves `0x004e5a80` inside broad `sub_4D2720` (`0x23aa` bytes), while `0x004e5f40` is an exact `0x25` / 37-byte accessor and `0x004e5fd0` is an exact `0x2f` / 47-byte scalar deleting destructor (Verified with int_convert.py).
- `decompile 0x004e5f40` rejects negative indexes and indexes `>= this[1]`, returns fallback storage at `this + 4` dwords / object `+0x10`, and otherwise returns `this[2] + 20 * index`; `0x14` is 20 bytes (Verified with int_convert.py).
- `xrefs_to 0x004e5f40` reports 27 code references: three in the HumanImageLib constructor (`0x004d4860`, `0x004d48aa`, `0x004d48e4`), three currently unmodeled old-human composition callsites (`0x004d5947`, `0x004d5b18`, `0x004d66aa`), and 21 in `sub_4D9180`. The read-only PE scan matched all 27 rel32 calls and found no absolute-VA/RVA pointer hits.
- `xrefs_to 0x004e5a80` reports one rel32 cleanup/unwind-style reference at `0x005ffbd4`; the PE scan found the same single rel32 reference and no pointer hits to the ordinary-destructor start.
- `xrefs_to 0x004e5fd0` reports the concrete vtable data reference at `0x0061b6ac`; the PE scan found one absolute-VA hit at that slot and no rel32 calls/jumps to the deleting destructor.
- `xrefs_to 0x0061b6ac` reports four references: HumanImageLib constructor embed/init at `0x004d296e`, HumanImageLib destructor cleanup at `0x004d4e36`, the ordinary destructor vtable reset at `0x004e5a83`, and the scalar deleting destructor vtable reset at `0x004e5fd9`.
- Decompilation of `0x004e5fd0` resets the `ProtectedArray<Acc2Info>` vtable, frees `Block[2]` / object `+0x08`, tests delete flag bit `1`, conditionally calls delete support, and returns `this`.
- `get_bytes` reconfirmed the Acc2 accessor body plus `0xcc` alignment through `0x004e5f70`, and the ordinary/deleting destructor byte patterns match the documented template shapes.
- `search_structs ProtectedArray` returned no local IDA struct/type record. This keeps final C++ blank: the binary proves the emitted template body, accessor behavior, and owner route, but not the original header basename, member spelling, or final `Acc2Info` declaration.
- 2026-06-29 B012 implementation sync: current MCP session `3fa0535f` reconfirms the `0x004e5f40` `Acc2Info` accessor as `sub_4E5F40`, size `0x25` / 37 bytes, with `0x14` / 20-byte stride, no callees, and 27 old-human constructor/composition code refs (Verified with int_convert.py where noted). The accepted source body is the generic [UID:000186][0x004e5f20-0x004e5f95.ProtectedArrayImageInfoAccessors](by-memory/0x004e5f20-0x004e5f95.ProtectedArrayImageInfoAccessors.md) `ProtectedArray<T>::GetAtOrDefault(int index)` implementation through [UID:0000MU][ProtectedArray](by-file/ProtectedArray.md); this page still keeps class-level declaration/header/member caveats and should not emit a separate handwritten `ProtectedArray<Acc2Info>` wrapper.

## Score Rationale

| Score | Rationale |
| --- | --- |
| Completion `87` | The page now records exact ordinary/accessor/deleting ranges, current function sizes, accessor behavior and stride, 27-call reachability, concrete vtable xrefs, HumanImageLib embedding, owner/emitter routing, PE cross-checks, formal no-code instantiation coverage, and the final-source blockers. |
| Confidence `91` | IDA and PE evidence agree on the modeled accessor, deleting destructor, cleanup-table ordinary destructor reference, vtable slot, HumanImageLib constructor/destructor integration, and corrected no-code disposition. Confidence stays below final-audit range because final source-facing names and the original template/record declarations are still unproven. |

## Cross-References

- [UID:000186][0x004e5f20-0x004e5f95.ProtectedArrayImageInfoAccessors](by-memory/0x004e5f20-0x004e5f95.ProtectedArrayImageInfoAccessors.md)
- [UID:0001WR][ProtectedArrayTemplates](by-type/by-template/ProtectedArrayTemplates.md)
- [UID:0000JY][HumanImageLib](by-file/HumanImageLib.md)
- [UID:0001XQ][HumanImageLibVtable](by-type/by-vtable/HumanImageLibVtable.md)

## Changes

- 2026-06-29 B002 direct empty-emitter implementation:
  - Raised score from `86/90` to `87/91`.
  - Added the formal no-code `ProtectedArray<Acc2Info>` instantiation comment using corrected embedder [UID:0000JY][HumanImageLib](by-file/HumanImageLib.md).
  - Summary/evidence: reusable accessor behavior is represented by [UID:000186][0x004e5f20-0x004e5f95.ProtectedArrayImageInfoAccessors](by-memory/0x004e5f20-0x004e5f95.ProtectedArrayImageInfoAccessors.md), ordinary cleanup by [UID:00017V][0x004e5a70-0x004e5b6f.ProtectedArrayImageInfoOrdinaryDestructors](by-memory/0x004e5a70-0x004e5b6f.ProtectedArrayImageInfoOrdinaryDestructors.md), and compiler-wrapper coverage by [UID:000187][0x004e5fa0-0x004e629f.ProtectedArrayImageInfoDeletingDestructors](by-memory/0x004e5fa0-0x004e629f.ProtectedArrayImageInfoDeletingDestructors.md); this page remains a concrete generated template instantiation, not a standalone original source class.

- 2026-06-16 A001 Goal2 protected-array class refresh:
  - Before: score was `82/88`, current status still used stale autogen/gate wording, and the page did not record live xrefs or PE reachability for this specific instantiation.
  - Changed to: score `86/90`, current owner/emitter route wording, HumanImageLib embedding evidence, live accessor/destructor/vtable reachability notes, score rationale, and explicit final-source blockers.
  - Evidence: live IDA `lookup_funcs`, `xrefs_to`, `decompile`, `get_bytes`, `search_structs`, current ProtectedArray/HumanImageLib support docs, `tools/int_convert.py`, and a read-only section-mapped PE scan.

- 2026-06-29 B012 [UID:000186][0x004e5f20-0x004e5f95.ProtectedArrayImageInfoAccessors](by-memory/0x004e5f20-0x004e5f95.ProtectedArrayImageInfoAccessors.md) implementation sync:
  - Score unchanged at `86/90`.
  - Resolved the accessor C++ blocker through the generic `ProtectedArray<T>::GetAtOrDefault(int index)` body emitted by UID000186, while keeping this concrete class declaration blank pending final source-facing `Acc2Info` field/member/header proof.
  - Summary/evidence: current MCP session `3fa0535f` reconfirmed the exact `0x004e5f40` body, `0x14` / 20-byte stride, no-callee status, and 27 old-human caller refs; no local IDA type/struct record proves final original `Acc2Info` declarations.

- 2026-06-06: Raised completion/confidence and attached the instantiation to `ProtectedArray`.
  - Before: completion was `72`, confidence was `86`, and routing was blank under the older parent-field schema because parent attachment had been deferred under the 80/80 gate.
  - After: completion was `82`, confidence was `88`, and the page was attached to [UID:0000MU][ProtectedArray](by-file/ProtectedArray.md).
  - Evidence: added exact accessor/destructor memory-page evidence, the old-human vtable address, and the handling note that keeps this as shared template support rather than a standalone source file. C++ remained blank pending final template/source declaration proof.

- 2026-06-05: Marked `RECONSTRUCTABLE:TRUE` and left routing blank under the older parent-field schema.
  - Before: reconstruction autogen classification was blank for a documented custom `ProtectedArray<Acc2Info>` instantiation.
  - After: classified as reconstructable source-facing template/declaration evidence, not as a standalone original `.cpp` file.
  - Evidence: [UID:0001WR][ProtectedArrayTemplates](by-type/by-template/ProtectedArrayTemplates.md) is already `RECONSTRUCTABLE:TRUE`, and this page ties `ProtectedArray<Acc2Info>` to [UID:0000JY][HumanImageLib](by-file/HumanImageLib.md). Live IDA MCP lookup confirms accessor `0x004e5f40` and deleting destructor `0x004e5fd0`, while ordinary destructor address `0x004e5a80` resolves inside the documented old-human image-library destructor island. Parent attachment was deferred at that score and superseded by the 2026-06-06 attachment above after the page met the 80/80 gate.

- 2026-05-30: Changed completion/confidence from `0/0` to `72/86`.
  - Before: The page was unevaluated despite identifying the concrete template instance, destructor slots, accessor, and source-level owner.
  - After: Scored as adequate completion and strong confidence for a generated `ProtectedArray<Acc2Info>` instantiation.
  - Evidence: Existing method table and ownership notes tie the accessor/destructors to HumanImageLib accessory metadata and shared template support.
