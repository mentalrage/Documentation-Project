*** UID:0000B6 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:87 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:91 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000MU | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000MU | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
// Concrete ProtectedArray<HeadInfo> template instantiation.
// Reusable source cleanup is represented by [UID:00017V][0x004e5a70-0x004e5b6f.ProtectedArrayImageInfoOrdinaryDestructors](by-memory/0x004e5a70-0x004e5b6f.ProtectedArrayImageInfoOrdinaryDestructors.md) and compiler-wrapper coverage [UID:000187][0x004e5fa0-0x004e629f.ProtectedArrayImageInfoDeletingDestructors](by-memory/0x004e5fa0-0x004e629f.ProtectedArrayImageInfoDeletingDestructors.md).
// Embedded record use remains with [UID:0000JY][HumanImageLib](by-file/HumanImageLib.md) HumanImageLib; do not emit a standalone original source class here.
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# ProtectedArray_struct_HeadInfo_

## Status

- Confidence: very strong for binary identity, destructor/vtable evidence, owner routing, and HumanImageLib embedding; medium for final original declaration spelling.
- Source-level name: `ProtectedArray<HeadInfo>`
- Source-level owner/emitter: [UID:0000MU][ProtectedArray](by-file/ProtectedArray.md) reusable template support.
- Concrete feature embedder: [UID:0000JY][HumanImageLib](by-file/HumanImageLib.md), with embedded fields recorded as `headArray` at `HumanImageLib +0x004` and `headSpecialArray` at `HumanImageLib +0x020` by [UID:0001UR][HumanImageLibLayout](by-type/by-struct/HumanImageLibLayout.md).
- Current generated metadata: `source-3/core/data/cache/wave2/classes/ProtectedArray_struct_HeadInfo_.json`; no matching `source-3/simroot_v2/class_ProtectedArray_struct_HeadInfo_.cpp` file exists in this checkout, so generated metadata is evidence only and not source-placement proof.
- Memory documentation: [UID:00017V][0x004e5a70-0x004e5b6f.ProtectedArrayImageInfoOrdinaryDestructors](by-memory/0x004e5a70-0x004e5b6f.ProtectedArrayImageInfoOrdinaryDestructors.md), [UID:000187][0x004e5fa0-0x004e629f.ProtectedArrayImageInfoDeletingDestructors](by-memory/0x004e5fa0-0x004e629f.ProtectedArrayImageInfoDeletingDestructors.md)
- Rebuild handling: source-declared/generated-binary template support; parented to [UID:0000MU][ProtectedArray](by-file/ProtectedArray.md), with concrete old-human record loading owned by [UID:0000JY][HumanImageLib](by-file/HumanImageLib.md).
- Output route: `CANONICAL_OWNER` and `EMITTER_UIDS` both route to [UID:0000MU][ProtectedArray](by-file/ProtectedArray.md). `RECONSTRUCTION_CPP` remains blank even though the current combined-score/emitter gate is satisfied, because the final template declaration, header basename, and source-facing `HeadInfo` field/member declarations are not source-quality yet.

## Methods

| Address | Method | Notes |
| --- | --- | --- |
| `0x004e5af0` | ordinary destructor | Resets `ProtectedArray<HeadInfo>` vtable and frees backing storage. |
| `0x004e6120` | scalar deleting destructor | Ordinary cleanup plus conditional `operator delete`. |

## Ownership Notes

This is old human head metadata support, not an independent original class source file. The reusable destructor/deleting-destructor source shape belongs to `ProtectedArray<T>`, while `HumanImageLib` owns the concrete `HeadInfo` records, `headArray`/`headSpecialArray` fields, and old-human head table integration.

## Evidence Notes

[UID:0001WR][ProtectedArrayTemplates](by-type/by-template/ProtectedArrayTemplates.md) records `ProtectedArray<HeadInfo>` at ordinary destructor `0x004e5af0` and deleting destructor `0x004e6120`. [UID:00017V][0x004e5a70-0x004e5b6f.ProtectedArrayImageInfoOrdinaryDestructors](by-memory/0x004e5a70-0x004e5b6f.ProtectedArrayImageInfoOrdinaryDestructors.md) identifies `0x004e5af0-0x004e5aff` as the exact ordinary destructor body, and [UID:000187][0x004e5fa0-0x004e629f.ProtectedArrayImageInfoDeletingDestructors](by-memory/0x004e5fa0-0x004e629f.ProtectedArrayImageInfoDeletingDestructors.md) identifies `0x004e6120-0x004e614f` as the exact deleting destructor body. [UID:0001XQ][HumanImageLibVtable](by-type/by-vtable/HumanImageLibVtable.md) records the `ProtectedArray<HeadInfo>` vtable at `0x0061b674` with slot target `0x004e6120`.

2026-06-16 A001 live IDA/PE refresh:

- `lookup_funcs` in IDA database `b001_mappane_0001AW_20260616` still resolves `0x004e5af0` inside broad `sub_4D2720` (`0x23aa` / 9130 bytes, Verified with int_convert), while `0x004e6120` is an exact `0x2f` / 47-byte function.
- `xrefs_to 0x004e5af0` reports two rel32 cleanup/unwind-style code references at `0x005ffb00` and `0x005ffb0e`; the read-only PE scan found the same two rel32 references and no absolute-VA or RVA pointer hits to the ordinary-destructor start.
- `xrefs_to 0x004e6120` reports the concrete vtable data reference at `0x0061b674`; the PE scan found one absolute-VA hit at the same vtable slot and no rel32 calls/jumps to the deleting destructor.
- `xrefs_to 0x0061b674` reports six references: HumanImageLib constructor embed/init at `0x004d2792` and `0x004d27ad`, HumanImageLib destructor cleanup at `0x004d4f23` and `0x004d4f35`, the ordinary destructor vtable reset at `0x004e5af3`, and the scalar deleting destructor vtable reset at `0x004e6129`.
- Decompilation of `0x004e6120` resets the `ProtectedArray<HeadInfo>` vtable, frees `Block[2]` / object `+0x08`, tests delete flag bit `1`, conditionally calls delete support, and returns `this`.
- `get_bytes` reconfirmed the Face/Hair/Head ordinary destructor bodies as consecutive `0x10` / 16-byte bodies; the HeadInfo body writes vtable `0x0061b674`, calls free, and returns.
- `search_structs ProtectedArray`, `FaceInfo`, `HairInfo`, and `HeadInfo` returned no local IDA struct/type records. The wave2 generated metadata has `has_struct:false` and `has_vtables:false`, and `rg --files` found no generated `simroot_v2` C++ file. This keeps final C++ blank: the binary proves the emitted template body, double HumanImageLib embedding, and owner route, but not the original header basename, member spelling, or full source declaration surface.

## Score Rationale

| Score | Rationale |
| --- | --- |
| Completion `87` | The page now records exact ordinary/deleting destructor ranges, current function modeling, vtable slot, two HumanImageLib embedded fields and constructor/destructor xref pairs, PE reachability cross-checks, owner/emitter routing, generated-metadata caveats, a formal no-code instantiation comment, and the reason no standalone source class should be emitted here. |
| Confidence `91` | IDA and PE evidence agree on the function boundaries, vtable slot, cleanup reachability, HumanImageLib embedding, and corrected no-code disposition. Confidence stays below final-audit range because no IDA type record or source-facing declaration evidence proves the original `ProtectedArray<T>` header/member names or `HeadInfo` field declarations. |

## Cross-References

- [UID:0001WR][ProtectedArrayTemplates](by-type/by-template/ProtectedArrayTemplates.md)
- [UID:0000JY][HumanImageLib](by-file/HumanImageLib.md)
- [UID:00017V][0x004e5a70-0x004e5b6f.ProtectedArrayImageInfoOrdinaryDestructors](by-memory/0x004e5a70-0x004e5b6f.ProtectedArrayImageInfoOrdinaryDestructors.md)
- [UID:000187][0x004e5fa0-0x004e629f.ProtectedArrayImageInfoDeletingDestructors](by-memory/0x004e5fa0-0x004e629f.ProtectedArrayImageInfoDeletingDestructors.md)
- [UID:0001XQ][HumanImageLibVtable](by-type/by-vtable/HumanImageLibVtable.md)

## Changes

- 2026-06-29 B002 direct empty-emitter implementation:
  - Raised score from `86/90` to `87/91`.
  - Added the formal no-code `ProtectedArray<HeadInfo>` instantiation comment using corrected embedder [UID:0000JY][HumanImageLib](by-file/HumanImageLib.md).
  - Summary/evidence: reusable cleanup is represented by [UID:00017V][0x004e5a70-0x004e5b6f.ProtectedArrayImageInfoOrdinaryDestructors](by-memory/0x004e5a70-0x004e5b6f.ProtectedArrayImageInfoOrdinaryDestructors.md) and compiler-wrapper coverage by [UID:000187][0x004e5fa0-0x004e629f.ProtectedArrayImageInfoDeletingDestructors](by-memory/0x004e5fa0-0x004e629f.ProtectedArrayImageInfoDeletingDestructors.md); this page remains a concrete generated template instantiation, not a standalone original source class.

- 2026-06-16 A001 Goal2 protected-array class refresh:
  - Before: score was `82/88`, current status still used stale autogen/gate wording, and the page did not record live xrefs or PE reachability for this specific instantiation.
  - Changed to: score `86/90`, current owner/emitter route wording, HumanImageLib double-embedding evidence, live IDA/PE reachability notes, score rationale, and explicit final-source blockers.
  - Evidence: live IDA `lookup_funcs`, `xrefs_to`, `decompile`, `get_bytes`, `search_structs`, current ProtectedArray/HumanImageLib support docs, `tools/int_convert.py`, wave2 metadata, generated-file search, and a read-only section-mapped PE scan.

- 2026-06-06: Raised completion/confidence and attached the instantiation to `ProtectedArray`.
  - Before: completion was `70`, confidence was `86`, and routing was blank under the older parent-field schema because parent attachment had been deferred under the 80/80 gate.
  - After: completion was `82`, confidence was `88`, and the page was attached to [UID:0000MU][ProtectedArray](by-file/ProtectedArray.md).
  - Evidence: added exact destructor memory-page evidence, the old-human vtable address, and the handling note that keeps this as shared template support rather than a standalone source file. C++ remained blank pending final template/source declaration proof.

- 2026-06-05: Marked `RECONSTRUCTABLE:TRUE` and left routing blank under the older parent-field schema.
  - Before: reconstruction autogen classification was blank for a documented custom `ProtectedArray<HeadInfo>` instantiation.
  - After: classified as reconstructable source-facing template/declaration evidence, not as a standalone original `.cpp` file.
  - Evidence: [UID:0001WR][ProtectedArrayTemplates](by-type/by-template/ProtectedArrayTemplates.md) is already `RECONSTRUCTABLE:TRUE`, and this page ties `ProtectedArray<HeadInfo>` to [UID:0000JY][HumanImageLib](by-file/HumanImageLib.md). Live IDA MCP lookup confirms deleting destructor `0x004e6120` and resolves ordinary destructor address `0x004e5af0` inside the documented old-human image-library destructor island. Parent attachment was deferred at that score and superseded by the 2026-06-06 attachment above after the page met the 80/80 gate.

- 2026-05-30: Changed completion/confidence from `0/0` to `70/86`.
  - Before: The page was unevaluated though it already identified the concrete template instance and destructor slots.
  - After: Scored as adequate completion and strong confidence for a generated `ProtectedArray<HeadInfo>` instantiation.
  - Evidence: Existing source-level owner, method table, and memory/template cross-references document the artifact identity and ownership.
