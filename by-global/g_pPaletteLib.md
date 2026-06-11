*** UID:0000RW | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000MB | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# g_pPaletteLib

## Status

- Confidence: strong for type, address, and owner family.
- Type: `PaletteLib*`.
- IDA address: `0x0067a7e0` (`dword_67A7E0`).
- Likely source file: [UID:0000MA][Palette](by-file/Palette.md) / [UID:0000MB][PaletteLib](by-file/PaletteLib.md).

## Role

`g_pPaletteLib` is the process-wide palette manager singleton. Rendering, image-library, map, UI, and text paths use it to resolve named palettes, current/base palettes, slot palettes, super palettes, and runtime palette-filter state.

## Evidence Notes

- IDA MCP recheck on 2026-05-25 identifies the storage as `0x0067a7e0` and reports 83 data references.
- `PaletteLib::PaletteLib` stores the constructed object in this global around `0x00543743-0x0054374a`.
- `PaletteLib::~PaletteLib` clears the global at `0x00543cfe`.
- The constructor-unwind cleanup stub at `0x005443a0` also clears this global and is referenced only from constructor unwind metadata at `0x00605944`.
- Map render code loads this global before calling [UID:0001E9][0x00543f60-0x005440f0.PaletteLibPaletteFilterHelpers](by-memory/0x00543f60-0x005440f0.PaletteLibPaletteFilterHelpers.md), confirming those helpers are `PaletteLib` methods.

## 2026-05-30 Review Notes

- IDA MCP `py_eval` on 2026-05-30 confirms `0x0067a7e0` is `dword_67A7E0`, size `4`, in `.data`, with 83 data xrefs.
- Live IDA xrefs include early application/render consumers at `0x004562c0`, `0x00464bef`, `0x00467f8f`, UI/image paths around `0x0048373f`, `0x004966e0`, `0x00499365`, text/draw helper neighborhoods from `0x004b9989` through `0x004c4417`, and late render/UI consumers including `0x00570fff`, `0x00588dad`, `0x00599346`, `0x005a06b1`, and the `0x005c2ac0` function family.
- Existing IDA-backed notes still identify the constructor write, destructor clear, constructor-unwind clear helper, and palette-filter helper ownership; this pass did not semantically classify all 83 xrefs.
- Live IDA decompilation on 2026-06-05 confirms `0x00543700` stores `this` into `dword_67A7E0` and installs the `PaletteLib` vtable, while `0x00543af0` and `0x005443a0` clear the singleton during cleanup/destruction.
- Completion remains below full because the high fan-out consumer set needs a dedicated pass to group and name every palette use site.

## Assignment Decision

`AUTOGEN_PARENT_UID` remains [UID:0000MB][PaletteLib](by-file/PaletteLib.md). This global now scores `86/88`, and the direct PaletteLib file parent scores `88/85`, so the corrected strict `85/85` child/direct-parent gate is satisfied. The exact storage child [UID:00028T][0x0067a7e0-0x0067a7e4.g_pPaletteLib](by-memory/0x0067a7e0-0x0067a7e4.g_pPaletteLib.md) is also above gate at `86/90` and records the zero storage, constructor publish/guard clear, destructor/unwind clears, and representative render/UI/map/tile consumers.

## Score Rationale

- Completion `86`: the page now records exact storage, type, singleton role, constructor/destructor/unwind lifecycle, representative consumer families, exact storage-child support, source-owner decision, and direct parent gate clearance.
- Confidence `88`: IDA-backed storage/xref/lifecycle evidence, the exact by-memory child, and the focused PaletteLib file parent strongly support the ownership and singleton interpretation. Confidence remains below final-audit quality because the full 83-reference consumer set is not semantically classified and final declaration/source split details remain open.

## Ownership Decision

Keep the declaration with `render/Palette.cpp` or the narrower `PaletteLib.cpp` source if the palette family later splits. Do not assign it to DAT/archive code; palette files are DAT-backed resources, but the singleton owns render palette policy.

## Cross-References

- [UID:0000MA][Palette](by-file/Palette.md)
- [UID:0000MB][PaletteLib](by-file/PaletteLib.md)
- [UID:0000A1][PaletteLib](by-class/PaletteLib.md)
- [UID:0001E6][0x005431c0-0x0054445b.PaletteLib](by-memory/0x005431c0-0x0054445b.PaletteLib.md)
- [UID:0001E9][0x00543f60-0x005440f0.PaletteLibPaletteFilterHelpers](by-memory/0x00543f60-0x005440f0.PaletteLibPaletteFilterHelpers.md)

## Changes

- Before: completion/confidence were ungraded at `0/0`, and Status contained weak provenance wording.
- Changed to: completion `80`, confidence `88`; weak provenance wording was removed from Status.
- Summary/evidence: live IDA MCP on 2026-05-30 verified exact storage, size, segment, 83 xrefs, and broad consumer fan-out; existing IDA-backed notes identify lifecycle writes/clears and PaletteLib filter-helper ownership. Completion remains below full until all consumer clusters are semantically classified.

- 2026-06-05 autogen classification:
  - What existed before: autogen metadata was blank, so the singleton was reported as unclassified.
  - Changed to: `RECONSTRUCTABLE:TRUE` with `AUTOGEN_PARENT_UID:0000MB`; `RECONSTRUCTION_CPP CODE` remains empty.
  - Summary/evidence: live IDA MCP `xrefs_to 0x0067a7e0` and decompilation of `0x00543700`, `0x00543af0`, and `0x005443a0` prove NexusTK-owned `PaletteLib` singleton storage owned by [UID:0000MB][PaletteLib](by-file/PaletteLib.md). No final C++ body was added because the page is below the 95/95 reconstruction gate.
- 2026-06-10 A001 strict gate repair:
  - Changed completion from `80` to `86`.
  - Summary/evidence: the direct PaletteLib file parent now scores `88/85`, and the exact storage child [UID:00028T][0x0067a7e0-0x0067a7e4.g_pPaletteLib](by-memory/0x0067a7e0-0x0067a7e4.g_pPaletteLib.md) scores `86/90`. The global page already carried live IDA evidence for exact `0x0067a7e0` storage, 83 xrefs, constructor publish/guard clear, destructor and constructor-unwind clears, and PaletteLib filter-helper ownership; the new rationale documents why the child/direct-parent gate clears while keeping C++ blank below the 95/95 source-code threshold.
