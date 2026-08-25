*** UID:0000B5 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:87 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:91 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000MU | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000MU | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
// Concrete ProtectedArray<HairInfo> template instantiation.
// Reusable source behavior is represented by [UID:000186][0x004e5f20-0x004e5f95.ProtectedArrayImageInfoAccessors](by-memory/0x004e5f20-0x004e5f95.ProtectedArrayImageInfoAccessors.md), [UID:00017V][0x004e5a70-0x004e5b6f.ProtectedArrayImageInfoOrdinaryDestructors](by-memory/0x004e5a70-0x004e5b6f.ProtectedArrayImageInfoOrdinaryDestructors.md), and compiler-wrapper coverage [UID:000187][0x004e5fa0-0x004e629f.ProtectedArrayImageInfoDeletingDestructors](by-memory/0x004e5fa0-0x004e629f.ProtectedArrayImageInfoDeletingDestructors.md).
// Embedded record use remains with [UID:0000JY][HumanImageLib](by-file/HumanImageLib.md) HumanImageLib; do not emit a standalone original source class here.
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# ProtectedArray_struct_HairInfo_

## Status

- Confidence: very strong for binary identity, destructor/accessor/vtable evidence, owner routing, and HumanImageLib embedding; medium for final original declaration spelling.
- Source-level name: `ProtectedArray<HairInfo>`
- Source-level owner/emitter: [UID:0000MU][ProtectedArray](by-file/ProtectedArray.md) reusable template support.
- Concrete feature embedder: [UID:0000JY][HumanImageLib](by-file/HumanImageLib.md), with the embedded field recorded as `hairArray` at `HumanImageLib +0x17c` by [UID:0001UR][HumanImageLibLayout](by-type/by-struct/HumanImageLibLayout.md).
- Current generated metadata: `source-3/core/data/cache/wave2/classes/ProtectedArray_struct_HairInfo_.json`; no matching `source-3/simroot_v2/class_ProtectedArray_struct_HairInfo_.cpp` file exists in this checkout, so generated metadata is evidence only and not source-placement proof.
- Memory documentation: [UID:00017V][0x004e5a70-0x004e5b6f.ProtectedArrayImageInfoOrdinaryDestructors](by-memory/0x004e5a70-0x004e5b6f.ProtectedArrayImageInfoOrdinaryDestructors.md), [UID:000186][0x004e5f20-0x004e5f95.ProtectedArrayImageInfoAccessors](by-memory/0x004e5f20-0x004e5f95.ProtectedArrayImageInfoAccessors.md), [UID:000187][0x004e5fa0-0x004e629f.ProtectedArrayImageInfoDeletingDestructors](by-memory/0x004e5fa0-0x004e629f.ProtectedArrayImageInfoDeletingDestructors.md)
- Rebuild handling: source-declared/generated-binary template support; parented to [UID:0000MU][ProtectedArray](by-file/ProtectedArray.md), with concrete old-human record loading owned by [UID:0000JY][HumanImageLib](by-file/HumanImageLib.md).
- Output route: `CANONICAL_OWNER` and `EMITTER_UIDS` both route to [UID:0000MU][ProtectedArray](by-file/ProtectedArray.md). This class-level `RECONSTRUCTION_CPP` block remains blank for declaration/header-field caveats, but the accessor C++ blocker is resolved by [UID:000186][0x004e5f20-0x004e5f95.ProtectedArrayImageInfoAccessors](by-memory/0x004e5f20-0x004e5f95.ProtectedArrayImageInfoAccessors.md), which now emits the generic `ProtectedArray<T>::GetAtOrDefault(int index)` source body covering the concrete `HairInfo` instantiation.

## Methods

| Address | Method | Notes |
| --- | --- | --- |
| `0x004e5ae0` | ordinary destructor | Resets `ProtectedArray<HairInfo>` vtable and frees backing storage. |
| `0x004e5f20` | `GetAtOrDefault(int index)` | Bounds-checked accessor using a `0x10` byte element stride. |
| `0x004e60f0` | scalar deleting destructor | Ordinary cleanup plus conditional `operator delete`. |

## Ownership Notes

`HumanImageLib::HumanImageLib` uses this accessor while populating old hair color/variant metadata. Keep the reusable destructor/accessor/deleting-destructor source shape in `ProtectedArray<T>` support, and keep concrete records, field ownership, and data loading in `HumanImageLib`.

## Evidence Notes

[UID:0001WR][ProtectedArrayTemplates](by-type/by-template/ProtectedArrayTemplates.md) records `ProtectedArray<HairInfo>` at ordinary destructor `0x004e5ae0`, accessor `0x004e5f20`, and deleting destructor `0x004e60f0`. [UID:000186][0x004e5f20-0x004e5f95.ProtectedArrayImageInfoAccessors](by-memory/0x004e5f20-0x004e5f95.ProtectedArrayImageInfoAccessors.md) verifies the `GetAtOrDefault` bounds check, `+0x04` count, `+0x08` entries pointer, `+0x10` fallback record, and `0x10` byte element stride. [UID:00017V][0x004e5a70-0x004e5b6f.ProtectedArrayImageInfoOrdinaryDestructors](by-memory/0x004e5a70-0x004e5b6f.ProtectedArrayImageInfoOrdinaryDestructors.md) and [UID:000187][0x004e5fa0-0x004e629f.ProtectedArrayImageInfoDeletingDestructors](by-memory/0x004e5fa0-0x004e629f.ProtectedArrayImageInfoDeletingDestructors.md) cover the exact destructor bodies. [UID:0001XQ][HumanImageLibVtable](by-type/by-vtable/HumanImageLibVtable.md) records the `ProtectedArray<HairInfo>` vtable at `0x0061b6a4` with slot target `0x004e60f0`.

2026-06-16 A001 live IDA/PE refresh:

- `lookup_funcs` in IDA database `b001_mappane_0001AW_20260616` still resolves `0x004e5ae0` inside broad `sub_4D2720` (`0x23aa` / 9130 bytes, Verified with int_convert), while `0x004e5f20` is an exact `0x20` / 32-byte function and `0x004e60f0` is an exact `0x2f` / 47-byte function.
- `xrefs_to 0x004e5ae0` reports one rel32 cleanup/unwind-style code reference at `0x005ffbc3`; the read-only PE scan found the same single rel32 reference and no absolute-VA or RVA pointer hits to the ordinary-destructor start.
- Decompilation of `0x004e5f20` proves the accessor shape: reject negative indexes and indexes `>= this[1]`, return fallback storage at `this + 4` dwords / object `+0x10`, otherwise return `this[2] + 16 * index`. `int_convert` verified `0x10` / 16 and `0x20` / 32.
- `xrefs_to 0x004e5f20` reports 105 code references. The caller grouping matches the accessor support page: one HumanImageLib constructor ref at `0x004d4977`, 26 currently unmodeled old-human composition refs from `0x004d58bd-0x004d696a`, and 78 refs inside `sub_4D9180` from `0x004d9348-0x004da6e8`.
- `xrefs_to 0x004e60f0` reports the concrete vtable data reference at `0x0061b6a4`; the PE scan found one absolute-VA hit at the same vtable slot. A blind rel32 scan produced an apparent hit at `0x004f1166`, but `get_bytes 0x004f1158` shows that byte run is a `c6 85 4f ff ff ff 01` stack-byte store operand, not an instruction-start call/jump to the deleting destructor.
- `xrefs_to 0x0061b6a4` reports four references: HumanImageLib constructor embed/init at `0x004d2947`, HumanImageLib destructor cleanup at `0x004d4e4b`, the ordinary destructor vtable reset at `0x004e5ae3`, and the scalar deleting destructor vtable reset at `0x004e60f9`.
- Decompilation of `0x004e60f0` resets the `ProtectedArray<HairInfo>` vtable, frees `Block[2]` / object `+0x08`, tests delete flag bit `1`, conditionally calls delete support, and returns `this`.
- `get_bytes` reconfirmed the Face/Hair/Head ordinary destructor bodies as consecutive `0x10` / 16-byte bodies and the Hair accessor body as exactly `0x20` / 32 bytes.
- `search_structs ProtectedArray`, `FaceInfo`, `HairInfo`, and `HeadInfo` returned no local IDA struct/type records. The wave2 generated metadata has `has_struct:false` and `has_vtables:false`, and `rg --files` found no generated `simroot_v2` C++ file. This keeps final C++ blank: the binary proves the emitted template body, accessor behavior, and owner route, but not the original header basename, member spelling, full source declaration surface, or final source-facing accessor name.
- 2026-06-29 B012 implementation sync: current MCP session `3fa0535f` reconfirms the `0x004e5f20` `HairInfo` accessor as `sub_4E5F20`, size `0x20` / 32 bytes, with `0x10` / 16-byte stride, no callees, and 105 old-human constructor/composition code refs (Verified with int_convert.py where noted). The accepted source body is the generic [UID:000186][0x004e5f20-0x004e5f95.ProtectedArrayImageInfoAccessors](by-memory/0x004e5f20-0x004e5f95.ProtectedArrayImageInfoAccessors.md) `ProtectedArray<T>::GetAtOrDefault(int index)` implementation through [UID:0000MU][ProtectedArray](by-file/ProtectedArray.md); this page still keeps class-level declaration/header/member caveats and should not emit a separate handwritten `ProtectedArray<HairInfo>` wrapper.

## Score Rationale

| Score | Rationale |
| --- | --- |
| Completion `87` | The page now records exact ordinary/accessor/deleting destructor ranges, current function modeling, vtable slot, HumanImageLib embed/destructor/accessor xrefs, PE reachability cross-checks, owner/emitter routing, generated-metadata caveats, formal no-code instantiation coverage, and the reason no standalone source class should be emitted here. |
| Confidence `91` | IDA and PE evidence agree on the function boundaries, accessor stride, vtable slot, cleanup reachability, HumanImageLib embedding, and corrected no-code disposition. Confidence stays below final-audit range because no IDA type record or source-facing declaration evidence proves the original `ProtectedArray<T>` header/member names, `HairInfo` fields, or final accessor method spelling. |

## Cross-References

- [UID:000186][0x004e5f20-0x004e5f95.ProtectedArrayImageInfoAccessors](by-memory/0x004e5f20-0x004e5f95.ProtectedArrayImageInfoAccessors.md)
- [UID:0001WR][ProtectedArrayTemplates](by-type/by-template/ProtectedArrayTemplates.md)
- [UID:0000JY][HumanImageLib](by-file/HumanImageLib.md)
- [UID:0001XQ][HumanImageLibVtable](by-type/by-vtable/HumanImageLibVtable.md)

## Changes

- 2026-06-29 B002 direct empty-emitter implementation:
  - Raised score from `86/90` to `87/91`.
  - Added the formal no-code `ProtectedArray<HairInfo>` instantiation comment using corrected embedder [UID:0000JY][HumanImageLib](by-file/HumanImageLib.md).
  - Summary/evidence: reusable accessor behavior is represented by [UID:000186][0x004e5f20-0x004e5f95.ProtectedArrayImageInfoAccessors](by-memory/0x004e5f20-0x004e5f95.ProtectedArrayImageInfoAccessors.md), ordinary cleanup by [UID:00017V][0x004e5a70-0x004e5b6f.ProtectedArrayImageInfoOrdinaryDestructors](by-memory/0x004e5a70-0x004e5b6f.ProtectedArrayImageInfoOrdinaryDestructors.md), and compiler-wrapper coverage by [UID:000187][0x004e5fa0-0x004e629f.ProtectedArrayImageInfoDeletingDestructors](by-memory/0x004e5fa0-0x004e629f.ProtectedArrayImageInfoDeletingDestructors.md); this page remains a concrete generated template instantiation, not a standalone original source class.

- 2026-06-16 A001 Goal2 protected-array class refresh:
  - Before: score was `82/88`, current status still used stale autogen/gate wording, and the page did not record live xrefs or PE reachability for this specific instantiation.
  - Changed to: score `86/90`, current owner/emitter route wording, HumanImageLib embedding/accessor evidence, live IDA/PE reachability notes, score rationale, and explicit final-source blockers.
  - Evidence: live IDA `lookup_funcs`, `xrefs_to`, `decompile`, `get_bytes`, `search_structs`, current ProtectedArray/HumanImageLib support docs, `tools/int_convert.py`, wave2 metadata, generated-file search, and a read-only section-mapped PE scan.

- 2026-06-29 B012 [UID:000186][0x004e5f20-0x004e5f95.ProtectedArrayImageInfoAccessors](by-memory/0x004e5f20-0x004e5f95.ProtectedArrayImageInfoAccessors.md) implementation sync:
  - Score unchanged at `86/90`.
  - Resolved the accessor C++ blocker through the generic `ProtectedArray<T>::GetAtOrDefault(int index)` body emitted by UID000186, while keeping this concrete class declaration blank pending final source-facing `HairInfo` field/member/header proof.
  - Summary/evidence: current MCP session `3fa0535f` reconfirmed the exact `0x004e5f20` body, `0x10` / 16-byte stride, no-callee status, and 105 old-human caller refs; no local IDA type/struct record proves final original `HairInfo` declarations.

- 2026-06-06: Raised completion/confidence and attached the instantiation to `ProtectedArray`.
  - Before: completion was `72`, confidence was `86`, and routing was blank under the older parent-field schema because parent attachment had been deferred under the 80/80 gate.
  - After: completion was `82`, confidence was `88`, and the page was attached to [UID:0000MU][ProtectedArray](by-file/ProtectedArray.md).
  - Evidence: added exact accessor/destructor memory-page evidence, the old-human vtable address, and the handling note that keeps this as shared template support rather than a standalone source file. C++ remained blank pending final template/source declaration proof.

- 2026-06-05: Marked `RECONSTRUCTABLE:TRUE` and left routing blank under the older parent-field schema.
  - Before: reconstruction autogen classification was blank for a documented custom `ProtectedArray<HairInfo>` instantiation.
  - After: classified as reconstructable source-facing template/declaration evidence, not as a standalone original `.cpp` file.
  - Evidence: [UID:0001WR][ProtectedArrayTemplates](by-type/by-template/ProtectedArrayTemplates.md) is already `RECONSTRUCTABLE:TRUE`, and this page ties `ProtectedArray<HairInfo>` to [UID:0000JY][HumanImageLib](by-file/HumanImageLib.md). Live IDA MCP lookup confirms accessor `0x004e5f20` and deleting destructor `0x004e60f0`, while ordinary destructor address `0x004e5ae0` resolves inside the documented old-human image-library destructor island. Parent attachment was deferred at that score and superseded by the 2026-06-06 attachment above after the page met the 80/80 gate.

- 2026-05-30: Changed completion/confidence from `0/0` to `72/86`.
  - Before: The page was unevaluated despite identifying the concrete template instance, destructor slots, accessor, and source-level owner.
  - After: Scored as adequate completion and strong confidence for a generated `ProtectedArray<HairInfo>` instantiation.
  - Evidence: Existing method table and ownership notes tie the accessor/destructors to HumanImageLib metadata and shared template support.
