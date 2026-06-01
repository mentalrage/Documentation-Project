*** UID:0000RW | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:80 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
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
- Completion remains below full because the high fan-out consumer set needs a dedicated pass to group and name every palette use site.

## Ownership Decision

Keep the declaration with `render/Palette.cpp` or the narrower `PaletteLib.cpp` source if the palette family later splits. Do not assign it to DAT/archive code; palette files are DAT-backed resources, but the singleton owns render palette policy.

## Cross-References

- [UID:0000MA][Palette](by-file/Palette.md)
- [UID:0000MB][PaletteLib](by-file/PaletteLib.md)
- [UID:0000A1][PaletteLib](by-class/PaletteLib.md)
- [UID:0001E6][0x005431c0-0x0054445b.PaletteLib](by-memory/0x005431c0-0x0054445b.PaletteLib.md)
- [UID:0001E9][0x00543f60-0x005440f0.PaletteLibPaletteFilterHelpers](by-memory/0x00543f60-0x005440f0.PaletteLibPaletteFilterHelpers.md)

## Changes

- Before: completion/confidence were ungraded at `0/0`, and Status contained generated-data provenance wording.
- Changed to: completion `80`, confidence `88`; generated-data provenance wording was removed from Status.
- Summary/evidence: live IDA MCP on 2026-05-30 verified exact storage, size, segment, 83 xrefs, and broad consumer fan-out; existing IDA-backed notes identify lifecycle writes/clears and PaletteLib filter-helper ownership. Completion remains below full until all consumer clusters are semantically classified.
