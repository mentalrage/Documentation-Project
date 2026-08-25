*** UID:0000L2 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:95 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"NexusTK/map/" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:FILE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***

# MapNamePane

## Status

- Confidence: strong for class behavior, live construction sites, vtables, singleton lifecycle, map folder ownership, and preferred standalone source-file placement.
- Proposed module: `NexusTK/map/MapNamePane.cpp`. [UID:0000L3][MapPane](by-file/MapPane.md) is a related map-UI consumer of `g_pMapNamePane`, not the direct implementation owner.
- Current source-document state: exact child ownership, formal CPP/H, and shared Pane/Event/ImageLib/DATFile declaration routes are implementation-ready. The earlier blank-C++ dependency blocker is retained below as historical staging evidence rather than current state.
- Primary class doc: [UID:00007P][MapNamePane](by-class/MapNamePane.md)
- Main address docs: [UID:0001AK][0x005031f0-0x005038fe.MapNamePane](by-memory/0x005031f0-0x005038fe.MapNamePane.md) is the non-emitting MapNamePane split index under mixed island [UID:0001AL][0x005031f0-0x0050395f.MapNameAndMiniMapButtonPanes](by-memory/0x005031f0-0x0050395f.MapNameAndMiniMapButtonPanes.md).

## File Role

`MapNamePane` is the small map-name overlay pane. It initializes the current-map-name pane, manages map-name resource/font state, draws centered map-name text, and releases global/resource state during teardown.

This is map UI, not generic text-control code. `MapNamePane` remains the standalone `NexusTK/map/MapNamePane.cpp/.h` source unit; folding its implementation into `MapPane.cpp` is rejected because `MapPane` is only an external singleton consumer.

## Proposed Contents

| Entity | Address evidence | Role |
| --- | --- | --- |
| `MapNamePane` class | [UID:00007P][MapNamePane](by-class/MapNamePane.md) | Class-level declaration route for the map-name overlay pane. |
| `g_pMapNamePane` | [UID:0002XC][g_pMapNamePane](by-global/g_pMapNamePane.md), storage child [UID:0002XD][0x0069b4b4-0x0069b4b8.g_pMapNamePane](by-memory/0x0069b4b4-0x0069b4b8.g_pMapNamePane.md) | Source-level singleton definition `MapNamePane *g_pMapNamePane = NULL;`; exact storage child carries only a no-duplicate marker. |
| `MapNamePane::MapNamePane()` | [UID:0003XG][0x005031f0-0x005032c3.MapNamePaneConstructor](by-memory/0x005031f0-0x005032c3.MapNamePaneConstructor.md) | Pane lifecycle setup, map-name resources, global active pointer, and optional EPF/glyph setup. |
| `MapNamePane::~MapNamePane()` | [UID:0003XH][0x005032d0-0x0050334d.MapNamePaneNonDeletingDestructor](by-memory/0x005032d0-0x0050334d.MapNamePaneNonDeletingDestructor.md) | Ordinary source destructor; releases resources and clears global active pointer. |
| `MapNamePane::OnPaint()` | [UID:0003XI][0x00503350-0x0050349f.MapNamePaneOnPaint](by-memory/0x00503350-0x0050349f.MapNamePaneOnPaint.md) | Centered map-name rendering through resource-backed or fallback glyph paths. |
| retained wide glyph renderer helper | [UID:0002BF][0x00503110-0x005031e1.WideGlyphResourceTextRendererRaw](by-memory/0x00503110-0x005031e1.WideGlyphResourceTextRendererRaw.md) | Private `DrawNumberGlyphString` 9x11 glyph helper assigned through the class-owned `this + 0x220` table. Its exact body now emits through the class; no inbound route is proven, so confidence remains capped. |
| `MapNamePane::HandleMapNameUpdatePacket()` / `OnMapNameUpdate()` | [UID:0003XJ][0x005034a0-0x00503574.MapNamePaneHandleMapNameUpdatePacket](by-memory/0x005034a0-0x00503574.MapNamePaneHandleMapNameUpdatePacket.md) | Secondary-vtable packet/update handling for opcode `0x15`, ANSI-to-wide conversion, text clamp, and redraw. |
| singleton clear helper | [UID:0003XK][0x005037f0-0x005037fb.MapNamePaneClearSingleton](by-memory/0x005037f0-0x005037fb.MapNamePaneClearSingleton.md) | Compiler-generated constructor-unwind cleanup that clears `g_pMapNamePane`; covered by normal C++ construction semantics and intentionally non-emitting. |
| adjustor thunks / scalar deleting destructor | [UID:0003XL][0x0050380b-0x00503821.MapNamePaneDestructorAdjustorThunks](by-memory/0x0050380b-0x00503821.MapNamePaneDestructorAdjustorThunks.md), [UID:0003XM][0x00503840-0x005038fe.MapNamePaneScalarDeletingDestructor](by-memory/0x00503840-0x005038fe.MapNamePaneScalarDeletingDestructor.md) | Compiler-generated glue; evidence only, not source-authored C++. |

## Method Families

| Area | Representative anchors | Notes |
| --- | --- | --- |
| Construction/resource setup | `0x005031f0` | Initializes pane state, `g_pMapNamePane`, and map-name resource lookup state. |
| Resource cleanup | `0x005032d0`, `0x00503840` | Releases resources, clears global state, and conditionally frees the pane. |
| Rendering | `0x00503350` | Draws centered map-name text using resource-backed or fallback text rendering. |
| Map-name updates | `0x005034a0` | Handles opcode `0x15`, converts incoming byte-string map names to UTF-16, clamps/ellipsizes the display buffer, and requests a pane redraw. |

## Boundary Notes

- 2026-06-05 live IDA confirms `0x005031f0`, `0x005032d0`, `0x00503350`, `0x005034a0`, `0x005037f0`, `0x0050380b`, `0x00503816`, and `0x00503840` as exact starts.
- Live IDA confirms primary/secondary/tertiary `MapNamePane` vtables at `0x0061e5b4`, `0x0061e600`, and `0x0061e630`; render slot `0x0061e5f8` targets `0x00503350`, and update-handler slot `0x0061e610` targets `0x005034a0`.
- Constructor xrefs from the main UI setup path at `0x004f8051` and `0x004f8695` support map UI ownership and two layout placements.
- IDA also confirms [UID:00008B][MiniMapButtonPane](by-class/MiniMapButtonPane.md) starts at `0x00503580`, so the old MapName-only aggregate span crosses a separate minimap button class.
- Keep `0x0050380b` and `0x00503816` documented as thunks, but do not migrate them as source-level logic.
- 2026-06-17 B001 source-quality review resolves the source route to preferred standalone `NexusTK/map/MapNamePane.cpp`; direct `MapPane.cpp` ownership was rejected because MapPane only consumes the singleton during teardown and does not own these class methods.
- 2026-06-07 Batch 043 live IDA MCP originally recorded `0x0069b4b4-0x0069b4b8` as a `0xffffffff` singleton item, but later active-IDB byte checks supersede that historical byte wording. Current B012 MCP session `ddf5b602` reconfirms the exact storage as `NULL` / `00 00 00 00`, non-function storage with six refs: constructor publish/fallback writes, destructor clear, singleton helper clear, scalar deleting destructor clear, and an external map-side reader. The exact storage has a split page [UID:0002XD][0x0069b4b4-0x0069b4b8.g_pMapNamePane](by-memory/0x0069b4b4-0x0069b4b8.g_pMapNamePane.md) and a canonical global page [UID:0002XC][g_pMapNamePane](by-global/g_pMapNamePane.md).
- 2026-06-12 A001 Batch 271 direct IDA MCP refresh confirmed UTF-16 `MAPNAME.EPF` at `0x0061e6c0` has one code xref from `0x0050328d` in the `MapNamePane` constructor/resource setup path. The exact literal lives in [UID:0003C1][0x0061e6c0-0x0061e700.MapNameMiniMapResourceStrings](by-memory/0x0061e6c0-0x0061e700.MapNameMiniMapResourceStrings.md), which remains a mixed string child rather than a MapName-only source child.

## Source Placement Reanalysis

B001's 2026-06-17 source-quality report resolves this file as the preferred route for exact MapNamePane children. The evidence is file/module-level rather than only address-level: `MapNamePane` has its own class page, primary/secondary/tertiary vtables, singleton global, `MAPNAME.EPF` resource string, map-name display buffer, constructor/destructor/resource lifecycle, and packet/update handler. B001-0002BF extends that route to the retained raw glyph helper at `0x00503110` because it consumes the same `this + 0x220` glyph-table field loaded and freed by the class lifecycle. Those facts are narrow enough for `NexusTK/map/MapNamePane.cpp` even though this pane participates in the larger map UI graph.

2026-07-04 B012 source-quality callback resolves the singleton declaration route: [UID:0002XC][g_pMapNamePane](by-global/g_pMapNamePane.md) emits `MapNamePane *g_pMapNamePane = NULL;`, while exact storage child [UID:0002XD][0x0069b4b4-0x0069b4b8.g_pMapNamePane](by-memory/0x0069b4b4-0x0069b4b8.g_pMapNamePane.md) carries only a no-duplicate marker. The declaration is intentionally not `static` in the first draft because [UID:0000L3][MapPane](by-file/MapPane.md) reads the singleton during teardown at `0x00504a43`; a file-static definition would only be safe if later source consolidation proves the consumer and definition live in one translation unit.

Rejected source-placement alternatives are preserved here:

- Direct `MapPane.cpp` ownership is rejected. [UID:0000L3][MapPane](by-file/MapPane.md) consumes `g_pMapNamePane` during teardown, but that consumer xref does not prove MapPane owns the class implementation.
- Generic text/input/UI ownership is rejected because the class-specific vtables, singleton, resource literal, map-name storage, and update handler do not fit a shared text-control source unit.
- MiniMapButtonPane ownership is rejected for the MapNamePane starts even though its functions are interleaved in the same address island; MiniMapButtonPane has its own constructor caller, singleton, vtables, clear helper, thunks, and scalar deleting destructor.
- The retained raw glyph helper [UID:0002BF][0x00503110-0x005031e1.WideGlyphResourceTextRendererRaw](by-memory/0x00503110-0x005031e1.WideGlyphResourceTextRendererRaw.md) does not prove a live paint path and does not justify moving [UID:0002BD][0x00503060-0x005030bc.UiAssetModeRectVirtualDispatchHelper](by-memory/0x00503060-0x005030bc.UiAssetModeRectVirtualDispatchHelper.md)/[UID:0002BE][0x005030c0-0x00503104.UiAssetModeRectWriteHelper](by-memory/0x005030c0-0x00503104.UiAssetModeRectWriteHelper.md) into this file. Its accepted file route is based only on the private `MapNamePane` glyph-table field lifecycle plus the same source pattern seen in assigned UserStatusPane 9x11 glyph helpers.
- [UID:0001AK][0x005031f0-0x005038fe.MapNamePane](by-memory/0x005031f0-0x005038fe.MapNamePane.md) must not itself emit C++ through this file because it is a split/index over multiple methods, compiler glue, padding, and MiniMapButtonPane holes. Only exact source-bearing child pages should eventually emit through this file when shared Pane/event/resource/glyph helper types are source-quality.

## 2026-08-12 B003 Whole-File Reconstruction Closure

The accepted whole-file audit exhaustively reconciled the standalone source unit, every modeled start in the interleaved island, the retained raw helper, globals/storage, vtables/RTTI, resource literals, padding, callers, and support declarations. This is a complete file contract rather than a representative method sample.

### Exact source-bearing inventory and boundaries

| Range or item | Source disposition | Owner/emitter route | Exact behavior or exclusion |
| --- | --- | --- | --- |
| `0x00503110-0x005031e1` | private `MapNamePane::DrawNumberGlyphString` | UID0002BF -> UID00007P child position `10` | Initializes a local `EPFTileContext`, fixes a 9-pixel row stride and 9x11 bounds, skips wide space/slash without drawing, indexes 99-byte glyph records by `codeUnit + glyphRow * 10 - 47`, calls `g_pfnBlitSprite`, and advances the destination by 9 for every character. No inbound xref/pointer route was found; the complete retained body and `this+0x220` lifecycle justify reconstruction while capping confidence. |
| `0x005031e1-0x005031f0` | no C++ | UID0002BF boundary | Fifteen `0xcc` alignment bytes. |
| `0x005031f0-0x005032c3` | `MapNamePane::MapNamePane()` | UID0003XG -> UID00007P child position `20` | Calls `Pane(1)`, initializes `EPFTileContext`, clears the first map-name character, and conditionally resolves `MAPNAME.EPF` and loads `9X11FONT.BIN` with prefix size 99. Explicit vptr stores, Singleton publication, and EH unwind lowering are compiler output. The source intentionally does not initialize `m_mapNameGlyphs` outside the EPF branch because the binary does not. |
| `0x005032c3-0x005032d0` | no C++ | UID0001AK parent gap | Thirteen alignment bytes. |
| `0x005032d0-0x0050334d` | `MapNamePane::~MapNamePane()` | UID0003XH -> UID00007P child position `30` | Releases the optional glyph buffer through `MemoryMan`; vptr restoration, Singleton clear, and base destruction regenerate from ordinary C++. |
| `0x0050334d-0x00503350` | no C++ | UID0001AK parent gap | Three alignment bytes. |
| `0x00503350-0x0050349f` | `MapNamePane::OnPaint()` | UID0003XI -> UID00007P child position `40` | Preserves the unconditional `GetMemoryMan()` call, EPF frame rendering with `FRMPART.PAL`, centered double text draw in mode/color `1/0x80`, and fallback fill/text path in mode/colors `0/0/0x8f`. |
| `0x0050349f-0x005034a0` | no C++ | UID0001AK parent gap | One-byte boundary. |
| `0x005034a0-0x00503574` | `bool MapNamePane::HandlePacketEvent(Event *)` | UID0003XJ -> UID00007P child position `50` | Handles opcode `0x15`, reads byte count at packet `+9` and bytes at `+10`, stages a 256-byte local, converts ACP bytes into 128 wide characters, appends `L"..."` to width 173, invalidates the pane, and always returns false. The original conversion result of 128 can place the terminator at the next member boundary; no modern clamp-to-127 change is permitted. |
| `0x00503574-0x00503580` | no C++ | UID0001AK parent gap | Twelve alignment bytes before MiniMapButtonPane. |
| `0x00503580-0x005037ed` | excluded neighbor code | UID00008B MiniMapButtonPane | Constructor `503580-50361e`, cleanup `503620-503649`, paint `503650-503692`, and mouse/event body `5036a0-5037ed` belong to an independent class with its own singleton/vtables/callers. |
| `0x005037f0-0x005037fb` | compiler-covered no-code | UID0003XK, owner UID00007P, no emitter | Sole inbound edge is constructor EH cleanup at `0x006020b1`; two instructions only clear the Singleton slot. |
| `0x005037fb-0x00503800` | no C++ | UID0001AK gap | Alignment. |
| `0x00503800-0x0050380b` | excluded neighbor code | UID00008B MiniMapButtonPane | Independent MiniMap Singleton clear. |
| `0x0050380b-0x00503821` | compiler-covered no-code | UID0003XL, owner UID00007P, no emitter | EventHandler and TimerHandler deleting-destructor adjustor thunks subtract `0xa0` and `0xa4`, then jump to `0x00503840`. |
| `0x00503821-0x00503837` | excluded neighbor code | UID00008B MiniMapButtonPane | Two independent MiniMap deleting-destructor adjustor thunks. |
| `0x00503837-0x00503840` | no C++ | UID0001AK gap | Alignment. |
| `0x00503840-0x005038fe` | compiler-covered no-code | UID0003XM, owner UID00007P, no emitter | Scalar deleting destructor preserves the delete flag and `0x224` size guard; it regenerates from `virtual ~MapNamePane()`. |
| `0x005038fe-0x00503900` | no C++ | UID0001AK boundary | Alignment. |
| `0x00503900-0x0050395f` | excluded neighbor code | UID00008B MiniMapButtonPane | Independent MiniMap scalar deleting destructor. |

### Data, resources, and direct xrefs

- Three decorated MapNamePane vtable/RTTI regions at `0x0061e5b4`, `0x0061e600`, and `0x0061e630` are class-declaration-generated evidence, not standalone source tables. Slots route the scalar wrapper, `OnPaint`, both adjustor thunks, and `HandlePacketEvent`.
- `MAPNAME.EPF` occupies exact UTF-16 bytes `[0x0061e6c0,0x0061e6d8)` and has one constructor operand xref at `0x0050328d`. It remains constructor-inline source text without a separate definition.
- Shared `FRMPART.PAL` at `[0x00610fa4,0x00610fbc)` has consumers `0x00461683`, `0x00503375`, and `0x00503678`; MapName owns only its `OnPaint` source use, not the shared storage.
- Shared `9X11FONT.BIN` at `0x0061682c` is a constructor literal among broad UI consumers, not a file-static MapName object.
- Shared ellipsis bytes `[0x0061066c,0x00610674)` are exactly `2e 00 2e 00 2e 00 00 00`, one `const wchar_t[]` item with 23 xrefs to its head and no interior xrefs. MapName operand `0x00503531` feeds `GrafPort::FitTextAndAppendSuffix` at `0x00503547`; the source use is exactly `L"..."`, with no standalone definition, ownership transfer, emitter, or additional target UID.
- The process-wide singleton storage `[0x0069b4b4,0x0069b4b8)` is four zero bytes with publish/clear writes at `0x0050323b`, `0x00503242`, `0x0050332e`, `0x005037f0`, and `0x005038a5`, plus the external MapPane read at `0x00504a43`. UID0002XC owns the one non-static definition; UID0002XD is covered-by evidence only.

### Source order, header, and dependency contract

- Direct-file emitter order is compile-sensitive: UID00007P is position `10` and emits `#include "MapNamePane.h"`, remaining includes, and its child methods; UID0002XC is position `20` and emits `MapNamePane *g_pMapNamePane = NULL;` only after declaration visibility exists. Class children are positions `10/20/30/40/50` in helper/constructor/destructor/paint/packet order.
- `MapNamePane.h` is owned by UID00007P and contains the direct `Pane` base, empty `Singleton<MapNamePane>` base, exact virtual methods, `m_mapNameText[128]` at `+0xf8`, `m_mapNameImage` at `+0x1f8`, `m_mapNameGlyphs` at `+0x220`, size assertion `0x224`, and one `extern MapNamePane *g_pMapNamePane` declaration.
- Required declaration visibility is explicit: Pane H declares `explicit Pane(unsigned char mode)`; Event and ImageLib declarations belong in guarded H channels; `LoadDatFileBuffer` has a DATFile H prototype; `extern bool g_useEpfAssets` remains a source-root consumer declaration while UID0000SW remains the sole definition owner.
- No third-party import applies. This is project-owned NexusTK map UI source and no `third_party_embeds/` path corresponds to it.

### Ownership decisions and preserved historical corrections

- Standalone `NexusTK/map/MapNamePane.cpp/.h` remains the strongest source shape. Folding into MapPane is rejected because MapPane only consumes the singleton; MiniMap and generic UI/text ownership are rejected by the independent class/vtable/resource/global evidence.
- UiAssetModeRect helpers UID0002BD/UID0002BE remain outside MapNamePane: the raw glyph helper's private-field evidence does not create an ownership edge for neighboring rectangle helpers.
- UID0001AK and UID0001AL remain non-emitting indexes. Aggregate C++ is forbidden because their ranges cross methods, compiler glue, padding, and MiniMap-owned code.
- Historical blank-C++ staging, broad-range ownership, and `0xffffffff` singleton wording are preserved as superseded assumptions. Current evidence resolves formal source and confirms zero/null storage; it does not erase why earlier documentation was cautious.
- Final score `94/95` reflects complete inventory, source placement, dependency closure, and formal child routing. Confidence remains below 100 because original private spellings and runtime reachability of the retained raw helper are not symbol-proven.

## Cross-References

- [UID:00007P][MapNamePane](by-class/MapNamePane.md)
- [UID:0001AL][0x005031f0-0x0050395f.MapNameAndMiniMapButtonPanes](by-memory/0x005031f0-0x0050395f.MapNameAndMiniMapButtonPanes.md)
- [UID:0001AK][0x005031f0-0x005038fe.MapNamePane](by-memory/0x005031f0-0x005038fe.MapNamePane.md)
- [UID:0002BF][0x00503110-0x005031e1.WideGlyphResourceTextRendererRaw](by-memory/0x00503110-0x005031e1.WideGlyphResourceTextRendererRaw.md)
- [UID:0003XG][0x005031f0-0x005032c3.MapNamePaneConstructor](by-memory/0x005031f0-0x005032c3.MapNamePaneConstructor.md)
- [UID:0003XH][0x005032d0-0x0050334d.MapNamePaneNonDeletingDestructor](by-memory/0x005032d0-0x0050334d.MapNamePaneNonDeletingDestructor.md)
- [UID:0003XI][0x00503350-0x0050349f.MapNamePaneOnPaint](by-memory/0x00503350-0x0050349f.MapNamePaneOnPaint.md)
- [UID:0003XJ][0x005034a0-0x00503574.MapNamePaneHandleMapNameUpdatePacket](by-memory/0x005034a0-0x00503574.MapNamePaneHandleMapNameUpdatePacket.md)
- [UID:0003XK][0x005037f0-0x005037fb.MapNamePaneClearSingleton](by-memory/0x005037f0-0x005037fb.MapNamePaneClearSingleton.md)
- [UID:0003XL][0x0050380b-0x00503821.MapNamePaneDestructorAdjustorThunks](by-memory/0x0050380b-0x00503821.MapNamePaneDestructorAdjustorThunks.md)
- [UID:0003XM][0x00503840-0x005038fe.MapNamePaneScalarDeletingDestructor](by-memory/0x00503840-0x005038fe.MapNamePaneScalarDeletingDestructor.md)
- [UID:0003C1][0x0061e6c0-0x0061e700.MapNameMiniMapResourceStrings](by-memory/0x0061e6c0-0x0061e700.MapNameMiniMapResourceStrings.md)
- [UID:0000L3][MapPane](by-file/MapPane.md)
- [UID:0001R1][proposed-source-tree](by-project-structure/proposed-source-tree.md)

## Changes

- 2026-06-22 Rule 26 B001-0002BF closeout:
  - Score unchanged at `86/86`; added [UID:0002BF][0x00503110-0x005031e1.WideGlyphResourceTextRendererRaw](by-memory/0x00503110-0x005031e1.WideGlyphResourceTextRendererRaw.md) to the proposed contents as a retained raw `MapNamePane` helper.
  - Evidence: the helper is still live-route-unproven, but its `this + 0x220` glyph-table read matches the constructor's `9X11FONT.BIN` load and destructor cleanup, so it routes through this file as a private helper while formal C++ remains blank.

- 2026-05-28: Updated the main address document reference from `0x005031f0-0x0050395e` to `0x005031f0-0x0050395f`. Evidence: IDA MCP reports the adjacent `MiniMapButtonPane` scalar deleting destructor ending at `0x0050395f`, with `0x0050395e` as the final immediate byte.
- 2026-05-30 completion/confidence scoring:
  - What existed before: `COMPLETION:0` and `CONFIDENCE:0`.
  - Changed to: `COMPLETION:82` and `CONFIDENCE:80`.
  - Summary/evidence: map-name overlay role, constructor/render/cleanup families, boundary notes, minimap-button split, constructor xrefs, and corrected memory reference are documented; confidence is capped by whether it was standalone or file-local in `MapPane.cpp`.
- 2026-06-05 live IDA rescore and path staging:
  - Changed from: `COMPLETION:82`, `CONFIDENCE:80`, and blank `PROPOSED_RECONSTRUCTION_PATH`.
  - Changed to: `COMPLETION:86`, `CONFIDENCE:86`, and `PROPOSED_RECONSTRUCTION_PATH:"NexusTK/map/"`.
  - Reason for score increase: live IDA confirmed the missing `0x005034a0` map-name update handler, singleton-clear helper, vtable slot map, constructor callers, singleton lifecycle refs, exact function sizes, and internal padding around the interleaved MiniMapButtonPane island. The score remains below final reconstruction because the final standalone-vs-file-local split and source-level field/helper names are still unresolved.
- 2026-06-07 Batch 043 split-parent note:
  - Score unchanged at `86/86`.
  - Evidence: live IDA MCP reconfirmed the exact singleton slot and all six xrefs; this page already clears the corrected `85/85` gate for the new direct global page and exact memory split.
- 2026-06-12 A001 Batch 271:
  - Score unchanged at `86/86`.
  - Evidence: added the exact `MAPNAME.EPF` child evidence from [UID:0003C1][0x0061e6c0-0x0061e700.MapNameMiniMapResourceStrings](by-memory/0x0061e6c0-0x0061e700.MapNameMiniMapResourceStrings.md) while preserving the mixed string-child routing decision.
- 2026-06-17 B001 source-quality execution:
  - Score unchanged at `86/86`.
  - Evidence: accepted B001 report resolved preferred `NexusTK/map/MapNamePane.cpp` placement, rejected direct `MapPane.cpp` implementation ownership, converted [UID:0001AK][0x005031f0-0x005038fe.MapNamePane](by-memory/0x005031f0-0x005038fe.MapNamePane.md) into a non-emitting split index, and created exact child pages [UID:0003XG][0x005031f0-0x005032c3.MapNamePaneConstructor](by-memory/0x005031f0-0x005032c3.MapNamePaneConstructor.md)-[UID:0003XM][0x00503840-0x005038fe.MapNamePaneScalarDeletingDestructor](by-memory/0x00503840-0x005038fe.MapNamePaneScalarDeletingDestructor.md) for the constructor, ordinary destructor, paint, update handler, singleton helper, destructor adjustor thunks, and scalar deleting destructor. Formal method C++ stays blank until shared UI/event/resource/glyph helper types are source-quality.
- 2026-07-04 B012 g_pMapNamePane declaration callback:
  - Score unchanged at `86/86`; source-route support synchronized for [UID:0002XC][g_pMapNamePane](by-global/g_pMapNamePane.md) and [UID:0002XD][0x0069b4b4-0x0069b4b8.g_pMapNamePane](by-memory/0x0069b4b4-0x0069b4b8.g_pMapNamePane.md).
  - Evidence: MCP session `ddf5b602` reconfirmed current zero/null storage, exact six-ref lifecycle/consumer set, active IDA naming caveat, MapNamePane ownership route, MapPane consumer-only role, and adjacent/sibling range separation. The global page now emits the non-static first-draft definition `MapNamePane *g_pMapNamePane = NULL;`; the exact storage child carries a no-duplicate formal marker.
