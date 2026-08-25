*** UID:0000MB | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:93 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"NexusTK/render/" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:FILE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***

# PaletteLib

## Status

- Confidence: very strong for the internal super-palette filename declaration, class/global/screen-state/filter/storage ownership, exact source order, singleton lifetime, palette-slot loading, and the focused source/header route.
- Direct module: `NexusTK/render/PaletteLib.cpp` with declaration in `NexusTK/render/PaletteLib.h`; [UID:0000MA][Palette](by-file/Palette.md) remains broader DLPalette/palette-family umbrella support.
- Main ranges: [UID:0003MT][0x00543150-0x005431b9.PaletteLibFindLoadedPaletteIndexRaw](by-memory/0x00543150-0x005431b9.PaletteLibFindLoadedPaletteIndexRaw.md), non-emitting split-inventory parent [UID:0001E6][0x005431c0-0x005443ab.PaletteLibMethodCluster](by-memory/0x005431c0-0x005443ab.PaletteLibMethodCluster.md), and [UID:0003MV][0x00544420-0x0054445b.PaletteLibScalarDeletingDestructor](by-memory/0x00544420-0x0054445b.PaletteLibScalarDeletingDestructor.md) for `PaletteLib`; [UID:0001E4][0x00542ac0-0x00543149.DLPaletteMethodCluster](by-memory/0x00542ac0-0x00543149.DLPaletteMethodCluster.md) plus [UID:0003MU][0x005443b0-0x00544411.DLPaletteScalarDeletingDestructor](by-memory/0x005443b0-0x00544411.DLPaletteScalarDeletingDestructor.md) for `DLPalette`.
- Primary global instance: `g_pPaletteLib` at `0x0067a7e0`.

## File Role

`PaletteLib` is the process-wide palette manager used by sprite, tile, UI, and image-control rendering. It owns named palette loading, per-asset-family palette slots, source/runtime palette lists, base palettes, and optional `SUPER0.PAL` through `SUPER6.PAL` palettes.

`DLPalette` is the data object used by `PaletteLib`: it reads DAT-backed palette streams, stores optional remap entries, converts RGB palette data to the client native 16-bit color lookup table, and exposes simple color lookup/set helpers.

`PaletteLib` directly depends on the `DLPalette` declaration and implementation supplied by the broader Palette family: it constructs and destroys embedded `DLPalette` objects, calls `DLPalette::LoadFromStream` during bootstrap, and clones instances when building runtime palette sets. This focused page owns `PaletteLib.h/.cpp`; broad Palette retains the DLPalette/free-helper umbrella. Neither route is raw DAT archive ownership.

Adjacent code also contains historical alias [UID:0000NC][ScreenPanePaletteState](by-file/ScreenPanePaletteState.md). A 2026-05-26 IDA recheck and B001's 2026-07-20 receiver/layout closure show its two imported methods are called with `g_pPaletteLib` as `this`, and `PaletteLib::PaletteLib` initializes the fields they use. The alias remains documentation-only with no standalone file; the two bodies are `PaletteLib` methods in this focused source.

## Startup And Ownership

IDA xrefs show `PaletteLib::PaletteLib` has one executable caller, `Application::Startup` / `sub_4F5FB0`, with the IDA call at `0x004f61bb`. The startup path allocates a large `PaletteLib` object, constructs it after the major image libraries and `MetaMan`, and later shutdown paths destroy `g_pPaletteLib` through its vtable.

The constructor:

- chains to `LObject`;
- sets `g_pPaletteLib = this`;
- installs the `PaletteLib` vtable;
- resets three embedded base palettes from `baram.pal`;
- constructs super/reserved palette arrays;
- allocates a `List(8, 10)` for loaded named palettes;
- loads 25 category palette files into indexed slots;
- probes `SUPER0.PAL` through `SUPER6.PAL` and loads present super palettes.

The optional super-palette probe owns the mutable source-declared filename buffer [UID:0002ZD][0x0066dee8-0x0066df00.SuperPaletteFilenameBuffer](by-memory/0x0066dee8-0x0066df00.SuperPaletteFilenameBuffer.md). It is an internal PaletteLib.cpp wide array initialized from `SUPER0.PAL` at source position 5, before the class declaration. The physical source object is 22 bytes (ten characters plus NUL); the final two bytes before `0x0066df00` are compiler/linker alignment. The former adjacent aggregate was split because the preceding `0x0066dee4-0x0066dee8` `DLGOPT.EPD` pointer is `OptionPane`-owned.

The destructor clears `g_pPaletteLib`. The tiny helper at `0x005443a0` also clears the global, but IDA only references it from constructor unwind metadata, so treat it as cleanup support rather than a normal source method.

## Likely Original Source Group

```text
NexusTK/render/PaletteLib.h
  struct PaletteLibLoadedEntry
  class PaletteLib
  extern PaletteLib *g_pPaletteLib

NexusTK/render/PaletteLib.cpp
  UID0002ZD internal mutable super-palette filename declaration
  UID0003MT PaletteLib::FindLoadedPaletteIndexByName definition
  PaletteLib class methods and lifecycle
  PaletteLib *g_pPaletteLib = 0
  PaletteLib::SetScreenPaletteMode / ResetScreenPaletteSlots
  PaletteLib filter helpers
  exact physical-storage marker
```

The palette manager's file cross-references EPF/image rendering modules because consumers frequently combine `g_pEPFLib` frame lookup with `g_pPaletteLib` palette selection. See [UID:0000MA][Palette](by-file/Palette.md) for DLPalette/free-helper umbrella support, [UID:0001E5][0x00542fa0-0x00543020.DLPaletteApplyPaletteEntryMoves](by-memory/0x00542fa0-0x00543020.DLPaletteApplyPaletteEntryMoves.md) for the DLPalette entry-move method invoked by `ResetScreenPaletteSlots`, and the lower-only helper caveats around `0x00543450` and `0x005443a0`.

## B001 UID00028T Focused Source And Emission Order - 2026-07-20

- [UID:0002ZD][0x0066dee8-0x0066df00.SuperPaletteFilenameBuffer](by-memory/0x0066dee8-0x0066df00.SuperPaletteFilenameBuffer.md) emits the internal mutable filename declaration at position 5. [UID:0000A1][PaletteLib](by-class/PaletteLib.md) emits the complete class/header declaration at position 10. [UID:0003MT][0x00543150-0x005431b9.PaletteLibFindLoadedPaletteIndexRaw](by-memory/0x00543150-0x005431b9.PaletteLibFindLoadedPaletteIndexRaw.md) emits `PaletteLib::FindLoadedPaletteIndexByName` at position 15. [UID:0000RW][g_pPaletteLib](by-global/g_pPaletteLib.md) emits the sole zero-initialized definition at position 20. [UID:0001E8][0x00543d30-0x00543f54.ScreenPanePaletteState](by-memory/0x00543d30-0x00543f54.ScreenPanePaletteState.md) emits `PaletteLib::SetScreenPaletteMode` and `PaletteLib::ResetScreenPaletteSlots` at position 25. [UID:0001E9][0x00543f60-0x005440f0.PaletteLibPaletteFilterHelpers](by-memory/0x00543f60-0x005440f0.PaletteLibPaletteFilterHelpers.md) retains its three exact methods at position 30. [UID:00028T][0x0067a7e0-0x0067a7e4.g_pPaletteLib](by-memory/0x0067a7e0-0x0067a7e4.g_pPaletteLib.md) emits only the no-duplicate marker at position 40.
- The exact ordering provides one internal filename declaration, one class/header declaration, one loaded-name finder definition, one `extern` declaration, one global definition, the two screen-state methods, the three filter methods, and one physical marker. It must not emit a second filename declaration in broad `Palette.cpp`, constructor-local output, or a header, nor a duplicate loaded-name finder/declaration, broad recovered class, duplicate global, parent-cluster body, scalar/EH/vtable/RTTI/vector/base/vptr body, or manual Singleton publication/clear.
- Complete class size is `0x25c8`. RTTI proves primary `LObject` and empty `Singleton<PaletteLib>` bases. Constructor `0x00543700-0x00543ae2` SHA256 `4D0167964629D7508741AC76C84F93F784EF1FAD6CD0419768959F0EB61D53EF` and ordinary destructor `0x00543af0-0x00543d1f` SHA256 `78644D04D1EE355921700539862369179B3D9AD1C9FE8BC3559D2102777E73B9` separate source-authored resource work from compiler-lowered embedded/base/Singleton cleanup.
- The exact layout is owned by the class page: embedded palettes at `+0x00c/+0x238/+0x464`, source/runtime list banks at `+0x690/+0x6f4`, filter selector at `+0x758`, natural float alignment and weight at `+0x75c`, and seven source/filtered super palettes at `+0x760/+0x1694`.
- The executable `GetTextPalette` candidate `0x00543d60-0x00543d67`, bytes `8d 81 64 04 00 00 c3`, SHA256 `A42845A33CD8C5F40EC3FDF356E9629BE9CC33F82D6586612EDA98A78FDAB816`, belongs in the UID0001E6 exact-child queue and remains outside ignored coverage. It is bracketed by two nine-byte internal alignment spans.
- Historical `render/Palette.cpp`-only, independent `ScreenPanePaletteState`, manual Singleton write/clear, ambiguous class layout, and DAT-owned source suggestions are superseded. Broad Palette still preserves unrelated DLPalette, free helper, literal, and shared resource content.

## UID0002ZD Internal Super-Palette Filename Declaration

- The source-facing role is one file-static mutable wide filename array initialized from `SUPER0.PAL`. The constructor's only direct storage operations are two base-address uses and one word write to digit index 5 before the DAT existence/open/load path; it cycles exactly seven names and advances the source palette receiver by `0x22c`.
- Exact source storage is `[0x0066dee8,0x0066defe)`, an effective 11-element array consisting of ten visible characters plus NUL. `[0x0066defe,0x0066df00)` is two-byte compiler/linker alignment before the unrelated HeadSelect dword table, not a twelfth source element.
- Internal linkage and position 5 are the no-duplicate route. No header declaration, class-static member, broad-Palette definition, separate Palette globals source, or constructor-local duplicate is emitted. The target formal owns the declaration; this by-file page records route and order only.
- The best inferred name is `s_superPaletteFilename`. Raw `off_66DEE8` and `word_66DEF2` labels remain evidence-time analysis names and do not appear in human source. The original private token and exact file-scope-versus-constant-initialized-local spelling remain lexical confidence caps, not source blockers.
- The physical predecessor is OptionPane-owned UID0002ZC; the physical successor is HeadSelect-owned UID00027Z. Their adjacency does not change focused PaletteLib ownership.

## Palette Filter Helpers

[UID:0001E9][0x00543f60-0x005440f0.PaletteLibPaletteFilterHelpers](by-memory/0x00543f60-0x005440f0.PaletteLibPaletteFilterHelpers.md) is now source-quality enough for its exact by-memory C++ block. The helper group stays in this `PaletteLib` source family:

| Range | Source-facing role | File-level meaning |
| --- | --- | --- |
| `0x00543f60-0x00543f70` | `PaletteLib::SetPaletteFilterActive(bool active)` | Writes `m_useFilteredPalettes` at `+0x758`, the accessors' source-vs-filtered palette-bank selector. |
| `0x00543f70-0x00543f77` | `PaletteLib::GetPaletteFilterWeight() const` raw getter | Returns `m_paletteFilterWeight` at `+0x75c`; retained in the exact helper page despite no direct xrefs because it is a complete source-shaped accessor for the same state family. |
| `0x00543f80-0x005440f0` | `PaletteLib::UpdatePaletteFilterTables(float weight)` | Rebuilds filtered base, super, and runtime slot palettes through the Surface color-transform callback slot `dword_69B408` / `g_pfnTransformPaletteColor`. |

The file-level ownership remains a consumer/provider split. `PaletteLib` owns the palette state, filtered/runtime bank selector, cached weight, source/runtime list banks, and update loops. [UID:0000TN][SurfaceRenderCallbackTable](by-global/SurfaceRenderCallbackTable.md) owns the callback slot at `0x0069b408`, whose final typedef spelling remains open but is usable here as `SurfacePaletteTransformProc` / `g_pfnTransformPaletteColor`. B001's earlier no-standalone-`PaletteTransformHelpers.cpp` decision still applies: the live `0x00543f80` member, raw `0x00543670` collection transform, and raw `0x00542d90` sibling share a transform kernel but belong under the render palette source family rather than an independent source file.

## UID0001E6 Split Inventory And Raw Cleanup Helpers

[UID:0001E6][0x005431c0-0x005443ab.PaletteLibMethodCluster](by-memory/0x005431c0-0x005443ab.PaletteLibMethodCluster.md) is now a non-emitting split-inventory parent for the PaletteLib method island. It remains useful file-level evidence for `PaletteLib` ownership, but the parent should not emit a broad `PaletteLibMethodCluster` C++ block. Current generated `auto-generated/NexusTK/render/PaletteLib.cpp` command `000000007586`, refreshed `2026-07-06T13:33:39-04:00`, showed UID0001E6 only as an Empty Emitter Marker; the actual emitted code currently present for this island is the child UID0001E9 palette-filter helper block.

The missing raw cleanup interval between the UID0001E9 helper child and `LoadPaletteSet` is part of this file-family inventory:

| Range | Source-facing documentation label | File-level disposition |
| --- | --- | --- |
| `0x005440f0-0x005441ab` | `PaletteLibClearPaletteSetBanksRaw` | Raw executable-shaped cleanup helper. It walks the 25 source/runtime palette-set list slots at `this+0x690` and `this+0x6f4`, destroys entries/lists, clears both list pointers, and currently has no direct xrefs, no VA/RVA pointer-byte hits, and no local PE `E8`/`E9` rel32 calls/jumps to its start. |
| `0x005441ab-0x005441b0` | padding | `0xcc` alignment padding between raw cleanup helpers. |
| `0x005441b0-0x00544202` | `PaletteLibClearPaletteListRaw` | Raw executable-shaped cleanup helper. It takes a pointer to one list pointer, destroys contained entries/list, clears the pointer, returns with `retn 4`, and currently has no direct xrefs, no VA/RVA pointer-byte hits, and no local PE `E8`/`E9` rel32 calls/jumps to its start. |
| `0x00544202-0x00544210` | padding | `0xcc` alignment padding before `PaletteLib::LoadPaletteSet`. |

These labels are descriptive documentation labels only; original helper names are not recovered. The no-live-route evidence keeps them as retained/dormant or compiler-adjacent PaletteLib cleanup helpers until a caller/source-order route is found. They are not padding, and they should be split into exact child pages only after a child-page pass can supply complete metadata, owner/emitter decisions, and C++/no-code dispositions.

## UID0003MT Loaded-Name Finder Source Role - 2026-08-24

- UID0003MT is a separate exact 105-byte source method immediately before UID0001E6. It captures `m_loadedPalettes` count, fetches typed `PaletteLibLoadedEntry` records through `List::GetElementAt`, compares each `wchar_t *name`, and returns the first matching index or `-1`.
- The active `PaletteLib::GetPaletteByName` method contains an instruction-equivalent inline copy and calls `LoadNamedPalette` only on a miss. The source-quality disposition is therefore a retained out-of-line private member definition plus an inlined consumer, not dead code, a List helper, or compiler-only output.
- The focused route is one definition in `NexusTK/render/PaletteLib.cpp` at position 15 and one existing private declaration in `PaletteLib.h` through UID0000A1. Generated output must replace UID0003MT's historical Empty Emitter Marker with the exact definition and must not duplicate the declaration or body.
- UID0001E6 remains a non-emitting successor inventory beginning at `0x005431c0`; the seven-byte `0xcc` fence at `0x005431b9-0x005431c0` prevents any range/body absorption.

## Cross-References

- [UID:0000A1][PaletteLib](by-class/PaletteLib.md)
- [UID:0000MA][Palette](by-file/Palette.md)
- [UID:0000RW][g_pPaletteLib](by-global/g_pPaletteLib.md)
- [UID:00003Z][DLPalette](by-class/DLPalette.md)
- [UID:0003MT][0x00543150-0x005431b9.PaletteLibFindLoadedPaletteIndexRaw](by-memory/0x00543150-0x005431b9.PaletteLibFindLoadedPaletteIndexRaw.md)
- [UID:0001E6][0x005431c0-0x005443ab.PaletteLibMethodCluster](by-memory/0x005431c0-0x005443ab.PaletteLibMethodCluster.md)
- [UID:0003MV][0x00544420-0x0054445b.PaletteLibScalarDeletingDestructor](by-memory/0x00544420-0x0054445b.PaletteLibScalarDeletingDestructor.md)
- [UID:0002ZD][0x0066dee8-0x0066df00.SuperPaletteFilenameBuffer](by-memory/0x0066dee8-0x0066df00.SuperPaletteFilenameBuffer.md)
- [UID:0001E4][0x00542ac0-0x00543149.DLPaletteMethodCluster](by-memory/0x00542ac0-0x00543149.DLPaletteMethodCluster.md)
- [UID:0003MU][0x005443b0-0x00544411.DLPaletteScalarDeletingDestructor](by-memory/0x005443b0-0x00544411.DLPaletteScalarDeletingDestructor.md)
- [UID:0001E9][0x00543f60-0x005440f0.PaletteLibPaletteFilterHelpers](by-memory/0x00543f60-0x005440f0.PaletteLibPaletteFilterHelpers.md)
- [UID:0001E7][0x00543450-0x00543665.PaletteListAndEntryMoveHelpers](by-memory/0x00543450-0x00543665.PaletteListAndEntryMoveHelpers.md)
- [UID:0002R4][0x00543670-0x005436f4.PaletteCollectionColorTransformRaw](by-memory/0x00543670-0x005436f4.PaletteCollectionColorTransformRaw.md)
- [UID:0000V4][PaletteSlotTable](by-item/PaletteSlotTable.md)
- [UID:0000NC][ScreenPanePaletteState](by-file/ScreenPanePaletteState.md)
- [UID:0000J3][EPFImageResources](by-file/EPFImageResources.md)
- [UID:0001QC][client_dat_specifications](by-meta/client_dat_specifications.md)

## Changes

- 2026-08-24 B009 UID0003MT implementation: raised `91/92 -> 92/93`; added the source-ready loaded-name finder to the focused source role and exact `5/10/15/20/25/30/40` order; documented typed List/entry behavior, retained-body/inlined-consumer evidence, the separate UID0001E6 boundary, and the generated no-empty-marker/no-duplicate expectation.

- 2026-07-22 B005 UID0002ZD implementation: score/path unchanged at `91/92` and `NexusTK/render/`; added the position-5 internal mutable super-palette filename declaration to the focused source order, exact 22-byte source-object/two-byte alignment distinction, sole-constructor behavior, and no-header/no-broad-Palette/no-constructor-local-duplicate rule while preserving the complete B001/B014/C001 source union and history.
- 2026-07-20 B001 UID00028T implementation: raised to `91/92`; fixed the direct route at `NexusTK/render/PaletteLib.h/.cpp`; recorded exact 10/20/25/30/40 ordering, one-definition and uniqueness rules, complete layout/lifetime/accessor context, and historicalized broad-only/recovered-screen-state/manual-Singleton ambiguity without removing existing method/split/raw-helper evidence.
- 2026-07-06 B001 UID0001E6 source-quality implementation:
  - Score unchanged.
  - Recorded [UID:0001E6][0x005431c0-0x005443ab.PaletteLibMethodCluster](by-memory/0x005431c0-0x005443ab.PaletteLibMethodCluster.md) as a non-emitting split-inventory parent for this file family. Current generated `PaletteLib.cpp` command `000000007586` shows UID0001E6 only as an Empty Emitter Marker while exact child [UID:0001E9][0x00543f60-0x005440f0.PaletteLibPaletteFilterHelpers](by-memory/0x00543f60-0x005440f0.PaletteLibPaletteFilterHelpers.md) carries emitted helper code.
  - Added file-level inventory for raw cleanup helper ranges `0x005440f0-0x005441ab` and `0x005441b0-0x00544202`, their `0xcc` padding at `0x005441ab-0x005441b0` and `0x00544202-0x00544210`, descriptive labels, and no-xref/no-pointer/no-rel32 liveness caveats.

- 2026-06-26 B014 palette-filter source-quality sync:
  - Score unchanged.
  - Added the resolved [UID:0001E9][0x00543f60-0x005440f0.PaletteLibPaletteFilterHelpers](by-memory/0x00543f60-0x005440f0.PaletteLibPaletteFilterHelpers.md) method names, `m_useFilteredPalettes` filtered-bank selector semantics, `m_paletteFilterWeight` cache semantics, and the Surface callback dependency `dword_69B408` / `g_pfnTransformPaletteColor`.
  - Evidence: B014 IDA MCP session `80de0a67` confirmed map-render callers through `g_pPaletteLib`, raw getter no-split/no-route status, table rebuild loops over base/super/runtime palettes, runtime list banks `+0x690/+0x6f4`, 25-slot loop with slot 11 skipped, and first-draft C++ readiness in the exact by-memory target.

- Before: the `PaletteLib` memory page ended at `0x0054445a`.
- Changed to: the page ends at `0x0054445b`.
- Summary/evidence: 2026-05-28 IDA MCP byte/function review shows `0x0054445a` is the final operand byte of the `retn 4` in `PaletteLib::ScalarDeletingDestructor`; `0x0054445b-0x00544460` is alignment padding.

- Before: the related DLPalette range summary ended the primary DLPalette cluster at `0x00543148`.
- Changed to: the related DLPalette range summary now ends the primary cluster at `0x00543149`.
- Summary/evidence: 2026-06-01 IDA MCP `idautils.Functions` reports `DLPalette::LoadFromBitmapPalette` as `0x005430a0-0x00543149`; C001's 2026-06-13 live IDA pass later corrected the successor map to `0x00543149-0x00543150` padding, [UID:0003MT][0x00543150-0x005431b9.PaletteLibFindLoadedPaletteIndexRaw](by-memory/0x00543150-0x005431b9.PaletteLibFindLoadedPaletteIndexRaw.md), and `0x005431b9-0x005431c0` padding.

- Before: the filter-helper cross-reference used the old inclusive-style `0x00543f60-0x005440ef` range.
- Changed to: the range is now `0x00543f60-0x005440f0` and includes the unxrefed raw cached-weight getter at `0x00543f70-0x00543f77`.
- Summary/evidence: 2026-06-01 IDA MCP boundary and byte checks confirm `sub_543F60`, raw getter bytes, `sub_543F80`, and the intervening `0xcc` padding.

- Before: completion/confidence were ungraded at `0/0`.
- Changed to: completion `86`, confidence `80`.
- Summary/evidence: the page documents class roles, startup ownership, likely source group, singleton behavior, Palette umbrella relationship, range correction, and cross-references; confidence remains capped by exact original split between `Palette.cpp`, `PaletteLib.cpp`, and `DLPalette.cpp`.

- 2026-06-05 projected path assignment:
  - What existed before: `PROPOSED_RECONSTRUCTION_PATH` was blank, so the by-file root remained an autogen file-path error.
  - Changed to: `PROPOSED_RECONSTRUCTION_PATH:"NexusTK/render/"`.
  - Summary/evidence: `by-project-structure/proposed-source-tree.md` places palette manager work under the render subsystem, and live IDA MCP xrefs/decompilation on `0x0067a7e0` confirm `PaletteLib` singleton ownership for this render palette source family.
- 2026-06-07 A008 Batch 053 parent-gate refresh:
  - What existed before: `86/80`; the page documented `SUPER0.PAL` through `SUPER6.PAL` probing but did not carry the exact mutable `.data` buffer split needed for a child assignment under the corrected `85/85` gate.
  - Changed to: `88/85`; added [UID:0002ZD][0x0066dee8-0x0066df00.SuperPaletteFilenameBuffer](by-memory/0x0066dee8-0x0066df00.SuperPaletteFilenameBuffer.md), recorded that the preceding `DLGOPT.EPD` pointer is not PaletteLib-owned, and made the super-palette buffer part of the focused `PaletteLib` source inventory.
  - Assignment effect: [UID:0002ZD][0x0066dee8-0x0066df00.SuperPaletteFilenameBuffer](by-memory/0x0066dee8-0x0066df00.SuperPaletteFilenameBuffer.md) now has a direct by-file parent that clears the corrected `85/85` gate. Confidence remains at `85` because the final source split between `Palette.cpp`, `PaletteLib.cpp`, and `DLPalette.cpp` is still not fully proven.

- 2026-06-13 C001 Goal 2 DLPalette/PaletteLib barrier repair:
  - Before: the main range still treated `PaletteLib` as broad `0x005431c0-0x0054445b`, which crossed the `DLPalette` scalar deleting destructor island.
  - Changed to: split the executable range into [UID:0003MT][0x00543150-0x005431b9.PaletteLibFindLoadedPaletteIndexRaw](by-memory/0x00543150-0x005431b9.PaletteLibFindLoadedPaletteIndexRaw.md), narrowed [UID:0001E6][0x005431c0-0x005443ab.PaletteLibMethodCluster](by-memory/0x005431c0-0x005443ab.PaletteLibMethodCluster.md), and exact scalar deleting destructor [UID:0003MV][0x00544420-0x0054445b.PaletteLibScalarDeletingDestructor](by-memory/0x00544420-0x0054445b.PaletteLibScalarDeletingDestructor.md); the foreign [UID:0003MU][0x005443b0-0x00544411.DLPaletteScalarDeletingDestructor](by-memory/0x005443b0-0x00544411.DLPaletteScalarDeletingDestructor.md) DLPalette scalar deleting destructor is now separate.
  - Summary/evidence: live IDA confirmed `0x00543150-0x005431b9` raw finder code, `0x005443a0-0x005443ab` constructor-unwind clear, padding at `0x005443ab-0x005443b0`, and exact scalar deleting destructor wrappers for both classes.
- 2026-06-25 B014 DLPalette entry-move sync:
  - Score unchanged.
  - Added [UID:0001E5][0x00542fa0-0x00543020.DLPaletteApplyPaletteEntryMoves](by-memory/0x00542fa0-0x00543020.DLPaletteApplyPaletteEntryMoves.md) as the `DLPalette` method invoked by the PaletteLib screen-palette reset path, replacing the older generic lower-only caveat around `0x00542fa0`.
  - Evidence: B014 accepted report ties the `+0x04` entry-move pointer, `+0x08` count, and `+0x2c` mapped-color table to the DLPalette loader/copy/raw-RGBA object layout.
