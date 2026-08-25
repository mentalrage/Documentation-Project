*** UID:0000A1 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:93 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000MB | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000MB | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL:10 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
#include "../util/LObject.h"
#include "../util/Singleton.h"
#include "../util/List.h"
#include "Palette.h"

struct PaletteLibLoadedEntry
{
    wchar_t *name;
    DLPalette *palette;
};

void __stdcall ApplyPaletteEntryMovesToCollection(List *palettes);

class PaletteLib : public LObject, public Singleton<PaletteLib>
{
public:
    PaletteLib();
    virtual ~PaletteLib();

    int GetScreenPaletteMode() const;
    void SetScreenPaletteMode(int mode);
    DLPalette *GetCurrentPalette();
    DLPalette *GetTextPalette();
    DLPalette *GetPaletteByName(const wchar_t *paletteName);
    DLPalette *GetSlotPalette(int slot, int paletteIndex, int superPaletteIndex);
    void ResetScreenPaletteSlots();
    bool SetPaletteFilterActive(bool active);
    float GetPaletteFilterWeight() const;
    void UpdatePaletteFilterTables(float weight);

private:
    int FindLoadedPaletteIndexByName(const wchar_t *paletteName) const;
    int LoadNamedPalette(const wchar_t *paletteName);
    List *LoadPaletteList(const wchar_t *paletteName);
    void LoadPaletteSet(int slot, const wchar_t *paletteName);

    int m_screenPaletteMode;
    List *m_loadedPalettes;
    DLPalette m_basePalette;
    DLPalette m_filteredBasePalette;
    DLPalette m_textPalette;
    List *m_sourcePaletteSets[25];
    List *m_runtimePaletteSets[25];
    bool m_useFilteredPalettes;
    float m_paletteFilterWeight;
    DLPalette m_superPalettes[7];
    DLPalette m_filteredSuperPalettes[7];
};

*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# PaletteLib

## Status

- Confidence: very strong for the complete `0x25c8` layout, RTTI inheritance, method roles, singleton lifetime, resource ownership, exact screen/filter fields, and focused source placement; unavailable original private spellings keep the score below 95.
- Source/header: [UID:0000MB][PaletteLib](by-file/PaletteLib.md), `NexusTK/render/PaletteLib.cpp` and `NexusTK/render/PaletteLib.h`, under broader [UID:0000MA][Palette](by-file/Palette.md) umbrella support.
- Address ranges: [UID:0003MT][0x00543150-0x005431b9.PaletteLibFindLoadedPaletteIndexRaw](by-memory/0x00543150-0x005431b9.PaletteLibFindLoadedPaletteIndexRaw.md), non-emitting split-inventory parent [UID:0001E6][0x005431c0-0x005443ab.PaletteLibMethodCluster](by-memory/0x005431c0-0x005443ab.PaletteLibMethodCluster.md), and [UID:0003MV][0x00544420-0x0054445b.PaletteLibScalarDeletingDestructor](by-memory/0x00544420-0x0054445b.PaletteLibScalarDeletingDestructor.md), with lower-only palette-filter helpers at [UID:0001E9][0x00543f60-0x005440f0.PaletteLibPaletteFilterHelpers](by-memory/0x00543f60-0x005440f0.PaletteLibPaletteFilterHelpers.md)
- Historical generated-source lead: older `simroot_v2` output emitted `class_PaletteLib.cpp`; current PaletteLib evidence comes from by-* docs, IDA MCP, and validator-generated output, not simroot.

## Class Purpose

`PaletteLib` is the global palette service behind `g_pPaletteLib`. Rendering callers use it to resolve a named `.PAL` file, retrieve the current base palette, or select a palette from a numbered asset-family slot.

It depends on `DATFile` for DAT-backed palette stream reads, but owns palette policy and should be reconstructed under render/palette ownership.

## Observed State

| Offset | Size | Source role |
| --- | ---: | --- |
| `+0x000` | 4 | primary `LObject` vptr/base |
| `+0x004` | 0 | empty `Singleton<PaletteLib>` base address under x86 EBO |
| `+0x004` | 4 | `m_screenPaletteMode` |
| `+0x008` | 4 | `m_loadedPalettes` |
| `+0x00c` | `0x22c` | `m_basePalette` |
| `+0x238` | `0x22c` | `m_filteredBasePalette` |
| `+0x464` | `0x22c` | `m_textPalette` |
| `+0x690` | `0x64` | `m_sourcePaletteSets[25]` |
| `+0x6f4` | `0x64` | `m_runtimePaletteSets[25]` |
| `+0x758` | 1 | `m_useFilteredPalettes` |
| `+0x759` | 3 | compiler-natural alignment before the float, not a source member |
| `+0x75c` | 4 | `m_paletteFilterWeight` |
| `+0x760` | `0xf34` | `m_superPalettes[7]` |
| `+0x1694` | `0xf34` | `m_filteredSuperPalettes[7]` |
| `+0x25c8` | 0 | exact object end/size |

The allocation, constructor/destructor field arithmetic, scalar-wrapper size guard, and all accessors close this layout exactly. `+0x758` selects source/base palettes versus filtered/runtime palettes. `+0x75c` is initialized to 1.0f, returned by the raw getter, and compared/written before derived-table rebuilds. No explicit source padding member belongs at `+0x759`.

2026-05-26 IDA MCP recheck and B001's 2026-07-20 closure show `0x00543d30` and `0x00543ee0` are `PaletteLib::SetScreenPaletteMode` and `PaletteLib::ResetScreenPaletteSlots`, invoked with `g_pPaletteLib` / `dword_67A7E0` as `this`. `PaletteLib::PaletteLib` initializes the same fields at `+0x04`, `+0x08`, and the 25-entry banks at `+0x690`/`+0x6f4`. `ScreenPanePaletteState_543D30` is retained only as a historical recovered alias, not a source class, base, facet, singleton, or `ScreenPane.cpp` owner. `ResetScreenPaletteSlots` invokes [UID:0001E5][0x00542fa0-0x00543020.DLPaletteApplyPaletteEntryMoves](by-memory/0x00542fa0-0x00543020.DLPaletteApplyPaletteEntryMoves.md) on each loaded record's `palette` pointer at `+0x04`, then applies the collection-wide free helper to the selected 25-entry bank.

[UID:0001E6][0x005431c0-0x005443ab.PaletteLibMethodCluster](by-memory/0x005431c0-0x005443ab.PaletteLibMethodCluster.md) is attached directly here as a non-emitting split-inventory parent after the class cleared `85/85`. It carries the modeled method inventory, screen-palette facet routing, filter-helper split, singleton lifecycle, `g_pPaletteLib` storage evidence, newly documented raw cleanup helper inventory at `0x005440f0-0x00544210`, and exact child/split queue. The adjacent raw finder [UID:0003MT][0x00543150-0x005431b9.PaletteLibFindLoadedPaletteIndexRaw](by-memory/0x00543150-0x005431b9.PaletteLibFindLoadedPaletteIndexRaw.md) and scalar deleting destructor [UID:0003MV][0x00544420-0x0054445b.PaletteLibScalarDeletingDestructor](by-memory/0x00544420-0x0054445b.PaletteLibScalarDeletingDestructor.md) are also direct class children.

Current generated output state for the parent is intentionally empty: validator command `000000007586`, refreshed `2026-07-06T13:33:39-04:00`, showed UID0001E6 only as an Empty Emitter Marker in generated `PaletteLib.cpp`, while exact child UID0001E9 carries the actual emitted palette-filter helper C++. That state is a parent/container signal, not a reason to synthesize one broad `PaletteLibMethodCluster` block.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| `FindLoadedPaletteIndexByName` | [UID:0003MT][0x00543150-0x005431b9.PaletteLibFindLoadedPaletteIndexRaw](by-memory/0x00543150-0x005431b9.PaletteLibFindLoadedPaletteIndexRaw.md) | Exact source-ready private const helper: captures `m_loadedPalettes` count, obtains typed `PaletteLibLoadedEntry` records through `List::GetElementAt`, compares UTF-16 names with `wcscmp` semantics, and returns the first matching index or `-1`. The active `GetPaletteByName` body contains the same inlined loop. |
| `LoadNamedPalette` | `0x005431c0` | Lazy-loads a named palette file, stores `{name, DLPalette*}` in the loaded palette list, and returns the new index. |
| `ParsePaletteDataFile` | `0x00543310` | Opens a DAT-backed palette set, reads an entry count, constructs `DLPalette` objects from the stream, and returns a list. |
| `PaletteLib::PaletteLib` | `0x00543700` | Bootstraps the singleton and preloads base, category, and optional super palettes. |
| `PaletteLib::~PaletteLib` | `0x00543af0` | Releases loaded named palettes, source/runtime slot lists, embedded palette arrays, and clears `g_pPaletteLib`. |
| `GetScreenPaletteMode` / small mode accessor caveat | `0x00543d20` | Decompiles to `return this[1]`, i.e. offset `+0x04`; do not treat it as an uncaveated filter-enabled getter because the actual filtered-palette active byte is `+0x758` in [UID:0001E9][0x00543f60-0x005440f0.PaletteLibPaletteFilterHelpers](by-memory/0x00543f60-0x005440f0.PaletteLibPaletteFilterHelpers.md). |
| `SetScreenPaletteMode` | `0x00543d30-0x00543d3d` | Stores the screen-palette mode at `+0x04`; exact SHA256 `DE8F7DA299F04A4488AFC2EB5581093BE8A8C778C1BFA0A2FF76D4F1B6FCEC1E`. |
| `GetCurrentPalette` | `0x00543d40` | Returns the source or runtime base palette depending on active palette mode. |
| `GetTextPalette` | `0x00543d60-0x00543d67` | Returns the mutable embedded text palette at `+0x464`; bytes `8d 81 64 04 00 00 c3`, SHA256 `A42845A33CD8C5F40EC3FDF356E9629BE9CC33F82D6586612EDA98A78FDAB816`, exactly two Balloon/Chatting callers. |
| `GetPaletteByName` | `0x00543d70` | Finds an already loaded named palette or lazy-loads it; falls back to current palette on failure. |
| `GetSlotPalette` | `0x00543e40` | Returns a slot palette by asset-family slot and palette index, or a super palette when `superPaletteIndex` is nonzero. |
| `ResetScreenPaletteSlots` | `0x00543ee0-0x00543f55` | Reverse-walks loaded records without null guards, calls `DLPalette::ApplyPaletteEntryMoves` on each `entry+0x04` palette, selects the source/runtime bank from `g_pConfig->m_shadowEnabled`, then applies the collection helper to exactly 25 lists; exact SHA256 `729B504AE82D630888B527FC3766A9377785C1D6DA5F34248AD9D2A6CDD711FA`. |
| `SetPaletteFilterActive` | `0x00543f60` | Stores `m_useFilteredPalettes` at `+0x758`, selecting source palettes versus filtered/runtime palettes; map render paths bracket filtered draw work with calls setting this byte to `1` then `0`. |
| `GetPaletteFilterWeight` raw | `0x00543f70` | Loads `m_paletteFilterWeight` at `+0x75c`; no observed direct xrefs in current IDA, but B014's raw-byte/pointer-route check keeps it inside [UID:0001E9][0x00543f60-0x005440f0.PaletteLibPaletteFilterHelpers](by-memory/0x00543f60-0x005440f0.PaletteLibPaletteFilterHelpers.md). |
| `UpdatePaletteFilterTables` | `0x00543f80` | Rebuilds transformed base/super/runtime slot lookup tables from a float weight and the Surface color-transform callback `dword_69B408` / `g_pfnTransformPaletteColor`; walks 25 source/runtime slot-list pairs and skips slot 11. |
| `PaletteLibClearPaletteSetBanksRaw` descriptive label | `0x005440f0-0x005441ab` | Raw executable-shaped cleanup helper with no IDA function object or live route found; iterates the 25 source/runtime palette-set list slots at `this+0x690` and `this+0x6f4`, destroys each entry/list, clears both list pointers, and is followed by `0x005441ab-0x005441b0` padding. |
| `PaletteLibClearPaletteListRaw` descriptive label | `0x005441b0-0x00544202` | Raw executable-shaped cleanup helper with no IDA function object or live route found; takes a pointer to one list pointer, destroys contained entries/list, clears the pointer, returns with `retn 4`, and is followed by `0x00544202-0x00544210` padding. |
| `LoadPaletteSet` | `0x00544210` | Loads a category `.PAL` file into the source slot list and clones it into a runtime slot list. |
| constructor-unwind global clear | `0x005443a0-0x005443ab` | Clears `g_pPaletteLib`; only referenced from constructor unwind metadata, not normal source flow. |
| `ScalarDeletingDestructor` | [UID:0003MV][0x00544420-0x0054445b.PaletteLibScalarDeletingDestructor](by-memory/0x00544420-0x0054445b.PaletteLibScalarDeletingDestructor.md) | Calls the destructor and optionally deletes `this`. |

## Render Consumers

[UID:000169][0x004ba540-0x004ba6ad.CompositePixels16](by-memory/0x004ba540-0x004ba6ad.CompositePixels16.md) is a direct render consumer of `PaletteLib::GetCurrentPalette` (`0x00543d40`). `GrafPort::CompositePixels` loads [UID:0000RW][g_pPaletteLib](by-global/g_pPaletteLib.md), obtains the current `DLPalette`, maps the GrafPort background-color field through `DLPalette::MapColor`, and uses that native 16-bit result while mutating clipped destination pixels.

Map render callers use [UID:0001E9][0x00543f60-0x005440f0.PaletteLibPaletteFilterHelpers](by-memory/0x00543f60-0x005440f0.PaletteLibPaletteFilterHelpers.md) through the singleton. `sub_5094B0` calls `UpdatePaletteFilterTables` when the graphics/shadow config byte differs from the cached MapPane scratch flag, then calls `SetPaletteFilterActive(1)` and later `SetPaletteFilterActive(0)` around filtered draw work. `sub_50A8B0` calls `UpdatePaletteFilterTables` when the day/night fade target changes and the same config byte is clear. `sub_50D8E0` brackets tile-region drawing with `SetPaletteFilterActive(1)` and `SetPaletteFilterActive(0)`.

## Slot Mapping

See [UID:0000V4][PaletteSlotTable](by-item/PaletteSlotTable.md). The constructor loads slots for `TILE.PAL`, `TILEC.PAL`, `BODY.PAL`, `ITEM.PAL`, `EFFECT.PAL`, `ALL.PAL`, `BACK.PAL`, and the other avatar/object families.

## Parent And Score Rationale

| Topic | Rationale |
| --- | --- |
| Source parent | [UID:0000MB][PaletteLib](by-file/PaletteLib.md) is the focused `NexusTK/render/PaletteLib.h/.cpp` route and owns the class declaration, singleton definition, startup role, slot-file loading, super-palette buffer, and `PaletteLib`/`DLPalette` dependency notes. |
| Umbrella source | [UID:0000MA][Palette](by-file/Palette.md) is currently `90/86` and remains the stronger umbrella page for the whole render palette family, while [UID:0000MB][PaletteLib](by-file/PaletteLib.md) is the narrower direct class parent used by the main memory aggregate and singleton. |
| Exact executable evidence | [UID:0001E6][0x005431c0-0x005443ab.PaletteLibMethodCluster](by-memory/0x005431c0-0x005443ab.PaletteLibMethodCluster.md) records exact method ranges, screen-palette facet ownership, filter-helper boundaries, raw cleanup helpers at `0x005440f0-0x005441ab` and `0x005441b0-0x00544202`, `0xcc` padding at `0x005441ab-0x005441b0` and `0x00544202-0x00544210`, generated empty-marker state, and the constructor-unwind clear boundary; [UID:0003MT][0x00543150-0x005431b9.PaletteLibFindLoadedPaletteIndexRaw](by-memory/0x00543150-0x005431b9.PaletteLibFindLoadedPaletteIndexRaw.md) and [UID:0003MV][0x00544420-0x0054445b.PaletteLibScalarDeletingDestructor](by-memory/0x00544420-0x0054445b.PaletteLibScalarDeletingDestructor.md) carry the raw finder and scalar deleting destructor. |
| Singleton evidence | [UID:0000RW][g_pPaletteLib](by-global/g_pPaletteLib.md) is attached to [UID:0000MB][PaletteLib](by-file/PaletteLib.md) and documents the `0x0067a7e0` storage, constructor publish, destructor clear, unwind clear, and broad consumer fanout. |
| Remaining blockers | All in-scope layout, inheritance, ownership, source-placement, and formal-C++ blockers are closed. Confidence remains below 95 only because original private spellings and physical header filenames are not symbol-proven. |

## UID0003MT Loaded-Name Finder Closure - 2026-08-24

- [UID:0003MT][0x00543150-0x005431b9.PaletteLibFindLoadedPaletteIndexRaw](by-memory/0x00543150-0x005431b9.PaletteLibFindLoadedPaletteIndexRaw.md) is the exact out-of-line definition for the private declaration already emitted once at line 44 of this page's H channel. The by-memory child's H channel remains blank; no second declaration is allowed.
- The receiver and record model are exact: `m_loadedPalettes` is at `+0x08`; List count is at `+0x0c`; virtual slot `+0x10` resolves to `List::GetElementAt(int)`; `PaletteLibLoadedEntry` is eight bytes with `name` at `+0x00` and `palette` at `+0x04`.
- `PaletteLib::GetPaletteByName` at `0x00543d70` contains the same count/get-element/wide-compare/index loop and has 29 incoming code xrefs. It calls `LoadNamedPalette` only after that inline search misses. This closes the retained-out-of-line/inlined-consumer source shape despite zero direct xrefs to UID0003MT.
- UID0003MT emits its exact member definition through this class at child position `15`, after the class route at 10 and before the global/screen/filter children at 20/25/30. Generated `PaletteLib.cpp` must contain one definition and no UID0003MT Empty Emitter Marker; generated `PaletteLib.h` must retain exactly one private declaration.
- The old `ResolvePaletteIndex` label for `0x005431c0` is superseded by `LoadNamedPalette`: the UID0003MT helper only finds an existing index, while the successor allocates/loads/inserts on a miss.

## B001 UID00028T Complete Class And Compiler-Boundary Closure - 2026-07-20

- RTTI class hierarchy descriptor contains exactly `PaletteLib`, `LObject`, and `Singleton<PaletteLib>`. `LObject` is primary at displacement zero; Singleton PMD is `mdisp=4,pdisp=-1,vdisp=0`, which explains the shared `+0x04` address under empty-base optimization without an explicit source field.
- Startup allocates `0x25c8` bytes before the sole constructor call. The constructor is `0x00543700-0x00543ae2` (`0x3e2` bytes), SHA256 `4D0167964629D7508741AC76C84F93F784EF1FAD6CD0419768959F0EB61D53EF`. It installs the `0x006217ac` vtable, publishes the Singleton, constructs three embedded `DLPalette` members, allocates `m_loadedPalettes` as a 20-byte `List` with element width 8 and growth 10, loads all 25 category slots, and probes `SUPER0.PAL` through `SUPER6.PAL`.
- The loaded-list record is exactly two pointers: `name` at `+0x00` and `palette` at `+0x04`. The declaration above models that width directly and keeps Reset's record access type-safe.
- The ordinary destructor is `0x00543af0-0x00543d1f`, SHA256 `78644D04D1EE355921700539862369179B3D9AD1C9FE8BC3559D2102777E73B9`. Source-authored cleanup destroys loaded names/palettes and source/runtime lists. Embedded `DLPalette` member/array destruction, Singleton clear, `LObject` teardown, vptr writes, EH cleanup, scalar delete, vtable/RTTI, and vector iterators are compiler output and are not duplicated in source.
- Constructor publication at `0x00543743`, adjusted-null fallback clear at `0x0054374a`, ordinary-destruction clear at `0x00543cfe`, and EH-only clear at `0x005443a0-0x005443ab` are compiler-lowered Singleton operations. Historical manual-global/manual-clear and standalone recovered screen-state assumptions are superseded.
- [UID:0001E9][0x00543f60-0x005440f0.PaletteLibPaletteFilterHelpers](by-memory/0x00543f60-0x005440f0.PaletteLibPaletteFilterHelpers.md) retains its three accepted bodies unchanged and emits at position 30. [UID:0001E8][0x00543d30-0x00543f54.ScreenPanePaletteState](by-memory/0x00543d30-0x00543f54.ScreenPanePaletteState.md) supplies the two PaletteLib methods at position 25. The class emits first at position 10, global at 20, physical marker at 40.
- Rejected source shapes include a standalone `ScreenPanePaletteState_543D30`, a broad parent-cluster body, an explicit three-byte reserve before the float, DAT/archive ownership, duplicate global definitions, manual Singleton publication/clear, and handwritten scalar/EH/vtable/RTTI/base-teardown bodies.

## Cross-References

- [UID:0000MB][PaletteLib](by-file/PaletteLib.md)
- [UID:0000MA][Palette](by-file/Palette.md)
- [UID:0000RW][g_pPaletteLib](by-global/g_pPaletteLib.md)
- [UID:0003MT][0x00543150-0x005431b9.PaletteLibFindLoadedPaletteIndexRaw](by-memory/0x00543150-0x005431b9.PaletteLibFindLoadedPaletteIndexRaw.md)
- [UID:0001E6][0x005431c0-0x005443ab.PaletteLibMethodCluster](by-memory/0x005431c0-0x005443ab.PaletteLibMethodCluster.md)
- [UID:0001E5][0x00542fa0-0x00543020.DLPaletteApplyPaletteEntryMoves](by-memory/0x00542fa0-0x00543020.DLPaletteApplyPaletteEntryMoves.md)
- [UID:0003MV][0x00544420-0x0054445b.PaletteLibScalarDeletingDestructor](by-memory/0x00544420-0x0054445b.PaletteLibScalarDeletingDestructor.md)
- [UID:0001E9][0x00543f60-0x005440f0.PaletteLibPaletteFilterHelpers](by-memory/0x00543f60-0x005440f0.PaletteLibPaletteFilterHelpers.md)
- [UID:00003Z][DLPalette](by-class/DLPalette.md)
- [UID:0000CC][ScreenPanePaletteState_543D30](by-class/ScreenPanePaletteState_543D30.md)
- [UID:00004G][EPFImageControlPane](by-class/EPFImageControlPane.md)
- [UID:0000J3][EPFImageResources](by-file/EPFImageResources.md)

## Changes

### 2026-08-24 UID0003MT Loaded-Name Finder Closure

- Raised `92/93 -> 93/94` while retaining UID0000MB ownership/emission, reconstructable status, position 10, `[[CHILDREN]]` CPP routing, and the complete existing H declaration/layout.
- Expanded the UID0003MT method evidence with exact List/record traversal, `wcscmp` equality semantics, the highly live inlined `GetPaletteByName` twin, retained-body reasoning, and source child position 15. Corrected stale `ResolvePaletteIndex` vocabulary at `0x005431c0` to `LoadNamedPalette`.
- Formal H still contains exactly one private `FindLoadedPaletteIndexByName` declaration; the exact definition remains owned by the UID0003MT by-memory child.

### 2026-08-16 UID0003F8 Header-Channel Relocation

- The complete `PaletteLibLoadedEntry`, `ApplyPaletteEntryMovesToCollection`, and `PaletteLib` declaration now emit once in `NexusTK/render/PaletteLib.h` at UID0000A1 position 10. The exact existing public/private methods, multiple inheritance, `0x25c8` member layout, list/palette banks, filter state, and seven-palette arrays are preserved without compression.
- Formal H includes the exact declaration dependencies `LObject.h`, `Singleton.h`, `List.h`, and `Palette.h`. The declaration is complete before Group.cpp or any other consumer calls `GetPaletteByName` through `g_pPaletteLib`.
- Formal CPP now contains only `[[CHILDREN]]`; no class, helper declaration, or extern remains in CPP. Exact method children continue to emit through UID0000MB, while [UID:0000RW][g_pPaletteLib](by-global/g_pPaletteLib.md) remains the sole CPP storage definition and emits the one H extern at position 20.
- The relocation changes no layout, inheritance, behavior, owner, score, or symbol inference. UID0000A1 remains `92/93`; only the declaration channel is corrected so generated C++ no longer contains a CPP-local class and generated H is compile-visible.
- Historical generated output with the complete declaration in `PaletteLib.cpp` and a blank `PaletteLib.h` is superseded. Duplicate class/extern blocks, a second singleton definition, manual vtables, and broad Palette ownership remain rejected.

- 2026-07-20 B001 UID00028T implementation: raised the class to `92/93`, set position 10, installed the complete `0x25c8` declaration and external global, resolved exact RTTI/EBO/layout/loaded-record/text-accessor/screen-state/source-order/compiler boundaries, and historicalized incomplete-layout, broad-source, manual-Singleton, recovered-screen-state, and reserve-field assumptions.
- 2026-07-06 B001 UID0001E6 source-quality implementation:
  - Score unchanged.
  - Updated this support page to treat [UID:0001E6][0x005431c0-0x005443ab.PaletteLibMethodCluster](by-memory/0x005431c0-0x005443ab.PaletteLibMethodCluster.md) as a non-emitting split-inventory parent instead of a parent C++ emitter; generated `PaletteLib.cpp` command `000000007586` currently showed UID0001E6 as an Empty Emitter Marker while UID0001E9 carried emitted helper code.
  - Added the raw cleanup helper inventory `0x005440f0-0x005441ab` / `PaletteLibClearPaletteSetBanksRaw`, padding `0x005441ab-0x005441b0`, `0x005441b0-0x00544202` / `PaletteLibClearPaletteListRaw`, and padding `0x00544202-0x00544210`, with no-xref/no-pointer/no-rel32 liveness caveats.
  - Replaced the uncaveated `IsPaletteFilterEnabled` method table wording for `0x00543d20` with the current `+0x04` small-mode-accessor caveat because [UID:0001E9][0x00543f60-0x005440f0.PaletteLibPaletteFilterHelpers](by-memory/0x00543f60-0x005440f0.PaletteLibPaletteFilterHelpers.md) proves the filter-active byte is `+0x758`.

- 2026-06-26 B014 palette-filter source-quality sync:
  - Score unchanged.
  - Updated the method table and field notes for [UID:0001E9][0x00543f60-0x005440f0.PaletteLibPaletteFilterHelpers](by-memory/0x00543f60-0x005440f0.PaletteLibPaletteFilterHelpers.md): `+0x758` is now `m_useFilteredPalettes`, `+0x75c` is `m_paletteFilterWeight`, `0x00543f60` is `SetPaletteFilterActive`, `0x00543f70` is the retained raw `GetPaletteFilterWeight`, and `0x00543f80` is `UpdatePaletteFilterTables`.
  - Evidence: B014 IDA MCP session `80de0a67` confirmed accessor reads choosing source/runtime palette banks, constructor/getter/updater field uses, map-render/day-night/tile-region callers through `g_pPaletteLib`, the Surface `dword_69B408` transform dependency, and target C++ readiness. The class-level C++ remains blank because broader PaletteLib layout and source-file split questions are outside this exact helper range.

- 2026-06-06 A008:
  - Before: confidence was `78` and `AUTOGEN_PARENT_UID` was blank because the class had not been reconciled with the newer focused [UID:0000MB][PaletteLib](by-file/PaletteLib.md) parent and attached memory/global pages.
  - After: changed confidence to `82`, attached the class to [UID:0000MB][PaletteLib](by-file/PaletteLib.md), and added parent/score rationale while keeping completion at `84`.
  - Evidence: [UID:0000MB][PaletteLib](by-file/PaletteLib.md) was then scored `86/80` with a focused render path; [UID:0001E6][0x005431c0-0x005443ab.PaletteLibMethodCluster](by-memory/0x005431c0-0x005443ab.PaletteLibMethodCluster.md) is attached there and documents exact method ranges, screen-palette facet routing, filter helpers, singleton lifecycle, and source split caveats; [UID:0000RW][g_pPaletteLib](by-global/g_pPaletteLib.md) documents the exact singleton storage and lifecycle.

- 2026-06-05: Marked `RECONSTRUCTABLE:TRUE` after live IDA MCP on `NexusTK.exe` confirmed named-palette, DAT parse, constructor/destructor, current/slot palette, filter, load-set, singleton-clear, and scalar-deleting starts at `0x005431c0`, `0x00543310`, `0x00543700`, `0x00543af0`, `0x00543d20`, `0x00543d30`, `0x00543d40`, `0x00543d70`, `0x00543e40`, `0x00543ee0`, `0x00543f60`, `0x00543f80`, `0x00544210`, `0x005443a0`, and `0x00544420`. Left `AUTOGEN_PARENT_UID` blank because this class confidence is below the 80 attachment gate; `0x00543f70` remains raw getter bytes rather than an IDA function start and is not used as proof.
- Before: the `PaletteLib` memory page reference ended at `0x0054445a`.
- Changed to: the page ends at `0x0054445b`.
- Summary/evidence: 2026-05-28 IDA MCP byte/function review shows `0x0054445a` is the final operand byte of the scalar deleting destructor's `retn 4`.
- Before: completion/confidence metadata were `0/0` despite detailed method roles, singleton/resource ownership, observed state, slot mapping, and palette-filter helper evidence.
- Changed to: `COMPLETION:84` and `CONFIDENCE:78`.
- Evidence: constructor/destructor, named palette loading, DAT palette parsing, current/slot palette lookup, screen-palette mode/reset helpers, filter-table helpers, singleton storage, and source-file split are documented; confidence remains medium-high because final field offsets and names still need a focused layout pass.

- 2026-06-13 C001 Goal 2 barrier repair:
  - Before: completion/confidence were `84/82`, [UID:0001E6][0x005431c0-0x005443ab.PaletteLibMethodCluster](by-memory/0x005431c0-0x005443ab.PaletteLibMethodCluster.md) was the overbroad `0x005431c0-0x0054445b` page attached to the by-file parent, and the raw `0x00543150` helper was hidden by a stale padding claim.
  - After: raised to `86/86`, updated executable children to [UID:0003MT][0x00543150-0x005431b9.PaletteLibFindLoadedPaletteIndexRaw](by-memory/0x00543150-0x005431b9.PaletteLibFindLoadedPaletteIndexRaw.md), narrowed [UID:0001E6][0x005431c0-0x005443ab.PaletteLibMethodCluster](by-memory/0x005431c0-0x005443ab.PaletteLibMethodCluster.md), and [UID:0003MV][0x00544420-0x0054445b.PaletteLibScalarDeletingDestructor](by-memory/0x00544420-0x0054445b.PaletteLibScalarDeletingDestructor.md); [UID:0001E6][0x005431c0-0x005443ab.PaletteLibMethodCluster](by-memory/0x005431c0-0x005443ab.PaletteLibMethodCluster.md), [UID:0003MT][0x00543150-0x005431b9.PaletteLibFindLoadedPaletteIndexRaw](by-memory/0x00543150-0x005431b9.PaletteLibFindLoadedPaletteIndexRaw.md), and [UID:0003MV][0x00544420-0x0054445b.PaletteLibScalarDeletingDestructor](by-memory/0x00544420-0x0054445b.PaletteLibScalarDeletingDestructor.md) can attach directly to this class.
  - Summary/evidence: live IDA proved the raw finder body, exact constructor-unwind clear end at `0x005443ab`, five-byte padding before the DLPalette destructor, exact PaletteLib scalar deleting destructor at `0x00544420-0x0054445b`, and the foreign DLPalette scalar destructor boundary.
- 2026-06-16 A001 slot-table support refresh:
  - Before: parent/score rationale still described [UID:0000MB][PaletteLib](by-file/PaletteLib.md) as `86/80`, which was stale after the PaletteLib and Palette parent-gate repairs.
  - After: refreshed the source-parent rationale to current `PaletteLib` `88/85` and `Palette` `90/86`, and kept the final source-split blocker explicit for [UID:0000V4][PaletteSlotTable](by-item/PaletteSlotTable.md).
  - Evidence: current support docs plus live IDA/PE refresh for `PaletteLib::PaletteLib`, `PaletteLib::LoadPaletteSet`, and [UID:000262][0x0062179c-0x006219e8.PaletteReadOnlyData](by-memory/0x0062179c-0x006219e8.PaletteReadOnlyData.md).
- 2026-06-18 B003 CompositePixels consumer note:
  - Score unchanged at `86/86`.
  - Added [UID:000169][0x004ba540-0x004ba6ad.CompositePixels16](by-memory/0x004ba540-0x004ba6ad.CompositePixels16.md) as a direct `PaletteLib::GetCurrentPalette` render consumer.
  - Evidence: B003 raw PE/Capstone recheck shows `GrafPort::CompositePixels` loads `g_pPaletteLib`, obtains the current `DLPalette`, maps `this+0x7c` through `DLPalette::MapColor`, and uses the result as the zero-pixel fill color.
- 2026-06-25 B014 reset-callee sync:
  - Score unchanged.
  - Updated `ResetScreenPaletteSlots` wording to call [UID:0001E5][0x00542fa0-0x00543020.DLPaletteApplyPaletteEntryMoves](by-memory/0x00542fa0-0x00543020.DLPaletteApplyPaletteEntryMoves.md) on each child `DLPalette *` instead of describing a generic child slot-state reset.
  - Evidence: accepted B014 report traced `sub_543EE0` through the list vtable accessor and the `[entry+0x04]` receiver load before the call at `0x00543efc`.
