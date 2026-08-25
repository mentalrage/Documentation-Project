*** UID:00007P | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:95 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000L2 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000L2 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL:10 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
#include "MapNamePane.h"

#include "../archive/DATFile.h"
#include "../render/ImageLib.h"
#include "../render/Surface.h"
#include "../ui/core/Event.h"
#include "../util/MemoryMan.h"

#include <windows.h>
#include <wchar.h>

extern bool g_useEpfAssets;

[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
#ifndef NEXUSTK_MAP_MAPNAMEPANE_H
#define NEXUSTK_MAP_MAPNAMEPANE_H

#include "../render/EPFTileContext.h"
#include "../ui/core/Pane.h"
#include "../util/Singleton.h"

class Event;

class MapNamePane : public Pane, public Singleton<MapNamePane>
{
public:
    MapNamePane();
    virtual ~MapNamePane();

protected:
    virtual void OnPaint();
    virtual bool HandlePacketEvent(Event *event);

private:
    void DrawNumberGlyphString(
        const wchar_t *text, int x, int y, signed char glyphRow);

    wchar_t m_mapNameText[128];
    EPFTileContext m_mapNameImage;
    unsigned char *m_mapNameGlyphs;
};

extern MapNamePane *g_pMapNamePane;

typedef char MapNamePaneSizeMustBe548[
    sizeof(MapNamePane) == 0x224 ? 1 : -1];

#endif
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# MapNamePane

## Status

- Confidence: strong for behavior, vtable identity, construction sites, singleton lifecycle, map-name update packet handling, map folder ownership, and the preferred standalone source route.
- Preferred source file: [UID:0000L2][MapNamePane](by-file/MapNamePane.md). [UID:0000L3][MapPane](by-file/MapPane.md) is only a related map-UI consumer of `g_pMapNamePane`, not the direct owner of this class.
- Address ranges: [UID:0001AK][0x005031f0-0x005038fe.MapNamePane](by-memory/0x005031f0-0x005038fe.MapNamePane.md) is now a non-emitting MapNamePane split index under the mixed physical island [UID:0001AL][0x005031f0-0x0050395f.MapNameAndMiniMapButtonPanes](by-memory/0x005031f0-0x0050395f.MapNameAndMiniMapButtonPanes.md). Exact source-bearing children are listed below.
- Reconstruction state: exact reconstructable children route through this class and [UID:0000L2][MapNamePane](by-file/MapNamePane.md). The former first-split blank-C++ blocker is resolved by the guarded H declaration, CPP include shell, and shared Pane/Event/ImageLib/DATFile declaration routes above.

## Class Purpose

`MapNamePane` is a small UI pane that displays the current map name. It initializes map-name archive/font resources, draws centered map-name text, and releases those resources during pane teardown.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| `MapNamePane::MapNamePane()` | [UID:0003XG][0x005031f0-0x005032c3.MapNamePaneConstructor](by-memory/0x005031f0-0x005032c3.MapNamePaneConstructor.md) | Initializes pane state, `g_pMapNamePane`, map-name resource context, display buffer, and optional EPF/glyph resources. |
| `MapNamePane::~MapNamePane()` | [UID:0003XH][0x005032d0-0x0050334d.MapNamePaneNonDeletingDestructor](by-memory/0x005032d0-0x0050334d.MapNamePaneNonDeletingDestructor.md) | Ordinary source destructor; releases resources, clears global state, and tails into base `Pane` cleanup. |
| `MapNamePane::OnPaint()` | [UID:0003XI][0x00503350-0x0050349f.MapNamePaneOnPaint](by-memory/0x00503350-0x0050349f.MapNamePaneOnPaint.md) | Virtual render/on-paint method; draws centered map-name text using resource-backed or fallback rendering. |
| `MapNamePane::DrawNumberGlyphString()` | [UID:0002BF][0x00503110-0x005031e1.WideGlyphResourceTextRendererRaw](by-memory/0x00503110-0x005031e1.WideGlyphResourceTextRendererRaw.md) | Retained private 9x11 glyph renderer assigned because it reads the class-owned `m_mapNameGlyphs` field at `this + 0x220`; its exact body emits as child position `10`, while no live caller remains a confidence cap. |
| `MapNamePane::HandleMapNameUpdatePacket()` / `OnMapNameUpdate()` | [UID:0003XJ][0x005034a0-0x00503574.MapNamePaneHandleMapNameUpdatePacket](by-memory/0x005034a0-0x00503574.MapNamePaneHandleMapNameUpdatePacket.md) | Secondary-vtable packet/update method; handles opcode `0x15`, copies incoming map-name bytes, converts ANSI to UTF-16, ellipsizes/clamps the 128-wchar display buffer, and invalidates/redraws the pane. |
| singleton clear helper | [UID:0003XK][0x005037f0-0x005037fb.MapNamePaneClearSingleton](by-memory/0x005037f0-0x005037fb.MapNamePaneClearSingleton.md) | Compiler-generated constructor-unwind cleanup that clears `g_pMapNamePane`; covered by normal construction semantics and deliberately non-emitting. |
| adjustor thunks | [UID:0003XL][0x0050380b-0x00503821.MapNamePaneDestructorAdjustorThunks](by-memory/0x0050380b-0x00503821.MapNamePaneDestructorAdjustorThunks.md) | Compiler-generated destructor adjustor thunks from the secondary/tertiary vtable slots. |
| scalar deleting destructor | [UID:0003XM][0x00503840-0x005038fe.MapNamePaneScalarDeletingDestructor](by-memory/0x00503840-0x005038fe.MapNamePaneScalarDeletingDestructor.md) | Compiler-generated deleting destructor wrapper; source destructor is the ordinary destructor child. |

## Source-Quality Names And Inferences

- `this +0xf8` is best modeled as `wchar_t m_mapNameText[128]`: the constructor clears it, the update handler writes the converted map name, and the paint method measures/draws it.
- `this +0x1f8` is best modeled as `m_mapNameEpfContext` / `m_mapNameResourceContext`: the constructor initializes it and the paint path uses it for `MAPNAME.EPF` resource-backed drawing.
- `this +0x220` is best modeled as `m_mapNameGlyphTable`: the constructor loads the `9X11FONT.BIN` / slot `0x63` table and both destructor forms release it.
- [UID:0002BF][0x00503110-0x005031e1.WideGlyphResourceTextRendererRaw](by-memory/0x00503110-0x005031e1.WideGlyphResourceTextRendererRaw.md) is the retained raw helper that consumes `m_mapNameGlyphTable`: it is a `thiscall` 9x11 wide-glyph renderer, skips wide space and slash, computes `(codeUnit + style * 10 - 47) * 99 + this->m_mapNameGlyphTable`, renders through [UID:0000TN][SurfaceRenderCallbackTable](by-global/SurfaceRenderCallbackTable.md) `dword_69B3E8`, and advances the destination by 9 pixels. B001-0002BF accepts MapNamePane source ownership from the private field lifecycle even though IDA still has no function object, start xrefs, raw pointer hits, PE absolute/RVA/relative references, or MapName/MiniMapButton-adjacent vtable slot for `0x00503110`.
- The update handler reads payload opcode `0x15`, byte length at payload byte `9`, map-name bytes at payload byte `10`, converts them with `MultiByteToWideChar(CP_ACP, 0)`, clamps/ellipsizes to `0xad` / 173 pixels with `L"..."`, and writes the wide result into `m_mapNameText[128]`. B001 rejected UTF-8 conversion, generic FittingRoom/TextEdit/InputMan ownership, and treating opcode `0x15` as an unqualified global map-packet handler because this body only updates the MapNamePane display buffer.
- Helper names remain descriptive/inferred rather than original-proof, but their roles are specific enough for documentation: `sub_4BA9A0` is the wide/glyph text measurement helper, `sub_4BAB70` is the wide/glyph text draw helper, `sub_4B9600`/`sub_4B9680` are draw-position and palette/color setup helpers, `sub_4B9980` is the inferred EPF/resource-frame selection or setup helper for map-name art, `sub_4BA820` is the inferred wide-text ellipsis/clamp helper, and `sub_516220` is the byte-copy helper used while staging packet text. These names are not treated as original symbols and still block formal C++ on the first split pass.

## B001 Report-Level Claim Map

B001's report resolved class ownership and source placement while keeping method C++ blank. The class is not a MapPane member or a generic text widget helper; it has its own vtable family, singleton global, resource literal, constructor callers, update handler, and destructor cluster. `MapPane` remains only a related teardown consumer of `g_pMapNamePane`.

The report's source-facing method decisions are:

- `MapNamePane::MapNamePane()` for `0x005031f0`; direct `InitializeMainUiGraph` callers at `0x004f8051` and `0x004f8695`, base init, singleton publish, vptr installs, `m_mapNameEpfContext` init, `m_mapNameText[128]` clear, and optional `MAPNAME.EPF` / `9X11FONT.BIN` slot-99 setup support constructor identity.
- `MapNamePane::~MapNamePane()` for `0x005032d0`; vtable restores, `m_mapNameGlyphTable` release at `+0x220`, singleton clear, and base `Pane` cleanup identify it as the ordinary source destructor.
- `0x00503840` is the scalar deleting destructor wrapper, not the hand-written destructor. Its duplicate cleanup, delete-flag test, vtable route, and thunk callers are compiler-glue evidence only.
- `0x0050380b` and `0x00503816` are adjustor thunks from secondary/tertiary vtable slots for the `+0xa0` and `+0xa4` subobjects.
- `MapNamePane::OnPaint()` is the best source-facing name for `0x00503350` because the route is the pane render vtable slot. `DrawMapName` or `RenderMapName` remain behavior descriptions, not the preferred final method name.
- `MapNamePane::HandleMapNameUpdatePacket()` / `OnMapNameUpdate()` is the best descriptive name for `0x005034a0`. The handler sees the secondary-interface adjusted object at `+0xa0`, reads an event/update object whose payload pointer is at `event+12`, accepts opcode `0x15`, uses payload byte `9` as the byte length, consumes name bytes from payload byte `10`, converts with `MultiByteToWideChar(CP_ACP, 0)`, clamps to `0xad` / 173 pixels and `0x80` / 128 wide characters using `L"..."`, invalidates the pane, and returns `0` in all cases rather than a handled-true value.
- [UID:0002BF][0x00503110-0x005031e1.WideGlyphResourceTextRendererRaw](by-memory/0x00503110-0x005031e1.WideGlyphResourceTextRendererRaw.md) is accepted as a retained private MapNamePane helper, not as a live paint-path proof. B001-0002BF rejected leaving it permanently parentless after deeper inference because the helper's object pointer is `this`, the only documented `this + 0x220` 9X11 font-table lifecycle in this address neighborhood is MapNamePane's constructor/destructor pair, and assigned UserStatusPane glyph helpers use the same class-local font-field/source-helper pattern. B001 also rejected assigning siblings [UID:0002BD][0x00503060-0x005030bc.UiAssetModeRectVirtualDispatchHelper](by-memory/0x00503060-0x005030bc.UiAssetModeRectVirtualDispatchHelper.md) and [UID:0002BE][0x005030c0-0x00503104.UiAssetModeRectWriteHelper](by-memory/0x005030c0-0x00503104.UiAssetModeRectWriteHelper.md) to MapNamePane from this evidence alone, rejected MiniMapButtonPane/MiniMap/MainMenu/Surface/RectBounds/compiler ownership, and kept formal C++ blank because no live caller/table/vtable/reference route or final helper/field names are proven.

The report explicitly rejected UTF-8 conversion, treating opcode `0x15` as an unqualified global packet-handler owner, folding the physical island into MiniMapButtonPane, retaining the legacy file-level emitter on [UID:0001AK][0x005031f0-0x005038fe.MapNamePane](by-memory/0x005031f0-0x005038fe.MapNamePane.md), and routing this class to generic UI/input/text ownership. Remaining uncertainty is limited to exact original helper names and concrete helper/interface/resource types, so it blocks final C++ but not ownership, range splitting, or the preferred standalone `NexusTK/map/MapNamePane.cpp` source route.

## Live IDA Evidence

Checked on 2026-06-05 with live IDA MCP/disassembly:

- `lookup_funcs` confirms `0x005031f0` size `0xd3`, `0x005032d0` size `0x7d`, `0x00503350` size `0x14f`, `0x005034a0` size `0xd4`, `0x005037f0` size `0xb`, adjustor thunks at `0x0050380b` and `0x00503816` size `0xb`, scalar deleting destructor `0x00503840` size `0xbe`, and [UID:00008B][MiniMapButtonPane](by-class/MiniMapButtonPane.md) beginning at `0x00503580`.
- The constructor has direct callers at `0x004f8051` and `0x004f8695` inside the main UI initialization function. Both call the constructor and then add the resulting pane with different layout rectangles.
- Decorated RTTI/vtable names exist for `MapNamePane` at primary vtable `0x0061e5b4`, secondary vtable `0x0061e600`, and tertiary vtable `0x0061e630`. Constructor, destructor, and scalar deleting destructor store all three vtable pointers.
- Vtable slots anchor the source methods: primary slot `0x0061e5b4 -> 0x00503840`, render slot `0x0061e5f8 -> 0x00503350`, secondary thunk slot `0x0061e600 -> 0x0050380b`, and update-handler slot `0x0061e610 -> 0x005034a0`.
- `xrefs_to 0x0069b4b4` confirms the constructor writes `g_pMapNamePane`, destructor and scalar deleting destructor clear it, `0x005037f0` is a singleton-clear helper, and `0x00504a43` is an external map-path reader of the live pane/global.
- Constructor decompilation shows base pane initialization, `g_pMapNamePane` assignment, three `MapNamePane` vtable stores, map-name resource setup at `this + 0x1f8`, the display buffer cleared at `this + 0xf8`, and optional resource/font setup gated by [UID:0000SW][g_useEpfAssets](by-global/g_useEpfAssets.md) / historical IDA alias `byte_66DA97`.
- Destructor and scalar deleting destructor decompilation show resource cleanup for the pointer at `+0x220`, singleton clear, base pane teardown, and conditional storage free in the deleting destructor.
- The render method draws the centered map-name buffer using the resource-backed path when [UID:0000SW][g_useEpfAssets](by-global/g_useEpfAssets.md) / historical IDA alias `byte_66DA97` is `1`; otherwise it uses the fallback text-render path and palette/color `143`.
- The `0x005034a0` update handler reads an event/packet object at `a2 + 12`, handles opcode `0x15`, copies the supplied byte string into a 256-byte temporary buffer, converts it to UTF-16 into the object buffer at `+0xf8`, clamps/ellipsizes it with width `173`, then requests a pane update through the base vtable.
- 2026-06-12 A002 Batch 325 split ties the constructor/resource setup xref at `0x0050328d` to exact UTF-16 `MAPNAME.EPF` child [UID:0003IL][0x0061e6c0-0x0061e6d8.MapNamePaneEpfResourceString](by-memory/0x0061e6c0-0x0061e6d8.MapNamePaneEpfResourceString.md), now assigned here after both child and direct class parent cleared the strict `85/85` gate. The containing [UID:0003C1][0x0061e6c0-0x0061e700.MapNameMiniMapResourceStrings](by-memory/0x0061e6c0-0x0061e700.MapNameMiniMapResourceStrings.md) page remains parentless because neighboring literals belong to MiniMapButtonPane, MapPane, LivingObjectPane, and ObjectList consumers.
- Internal padding around the newly confirmed methods is `0xcc`: `0x0050349f-0x005034a0`, `0x00503574-0x00503580`, `0x005037fb-0x00503800`, `0x005038fe-0x00503900`, and `0x0050395f-0x00503960`.
- The local address island is interleaved with [UID:00008B][MiniMapButtonPane](by-class/MiniMapButtonPane.md), so source migration must stay per-method and must not migrate the older MapName-only aggregate span as a contiguous class range.
- Do not treat the adjustor thunks as separate original methods.
- 2026-06-17 B001 source-quality review resolved the source-placement direction to preferred standalone `NexusTK/map/MapNamePane.cpp`, rejected direct `MapPane.cpp` ownership, and split the legacy [UID:0001AK][0x005031f0-0x005038fe.MapNamePane](by-memory/0x005031f0-0x005038fe.MapNamePane.md) aggregate into exact child records for constructor, ordinary destructor, render/on-paint, update handler, singleton helper, adjustor thunks, and scalar deleting destructor.

## 2026-08-12 B003 Formal Class And Source Closure

- Physical layout is `Pane` `+0x000..+0x0f7`, `wchar_t m_mapNameText[128]` `+0x0f8..+0x1f7`, `EPFTileContext m_mapNameImage` `+0x1f8..+0x21f`, and `unsigned char *m_mapNameGlyphs` at `+0x220`, for exact size `0x224`. Empty `Singleton<MapNamePane>` inheritance expresses source-level singleton publication without adding storage.
- The three decorated vtable views at `0x0061e5b4`, `0x0061e600`, and `0x0061e630` follow from direct `Pane` inheritance plus its `EventHandler`/`TimerHandler` facets. The source declaration contains only the virtual destructor, `OnPaint`, and `HandlePacketEvent`; compiler deleting destructors and adjustor thunks are not source members.
- The exact class child order is UID0002BF `10`, UID0003XG `20`, UID0003XH `30`, UID0003XI `40`, and UID0003XJ `50`. UID0003XK/UID0003XL/UID0003XM remain compiler-covered no-code; UID0003BZ vtables/RTTI and UID0003IL resource bytes regenerate or appear through ordinary declarations/literals rather than independent bodies.
- Direct-file position is `10`. This class CPP emits `#include "MapNamePane.h"`, support includes, source-root `extern bool g_useEpfAssets`, and `[[CHILDREN]]` before UID0002XC at direct-file position `20` emits the one global definition. Reversing those positions would place `MapNamePane *g_pMapNamePane = NULL;` before declaration visibility and is rejected.
- Constructor behavior preserves the original conditional initialization edge: `m_mapNameGlyphs` is assigned only when `g_useEpfAssets` is true. The destructor tests and frees that field exactly as compiled; the reconstruction intentionally does not modernize the disabled branch.
- `HandlePacketEvent` preserves packet offsets `9/10`, the 256-byte local, ACP conversion, unsigned-byte conversion length, 128-wide output, `L"..."` width 173, redraw invalidation, and false return. The potential conversion-result index `128` write at the next member boundary is historical behavior and is not silently clamped.
- Field and helper names are evidence-backed source-facing inferences, not recovered symbols. They follow the project-wide `m_`/PascalCase/lower-camel style and replace raw IDA labels while retaining exact behavior. Confidence remains capped below 100 for original private spelling and raw-helper runtime liveness.
- Third-party import is not applicable: this is project-owned NexusTK UI source, with no corresponding `third_party_embeds/` path.

### Historical corrections retained

- Earlier `m_mapNameEpfContext` / `m_mapNameGlyphTable` prose is retained as descriptive historical naming. The accepted formal spellings are `m_mapNameImage` and `m_mapNameGlyphs`, matching their concrete roles and the complete source body.
- Earlier blank formal C++ was a dependency-staging decision, not evidence that the methods lacked source bodies. Pane mode-constructor, Event H, ImageLib H, and DATFile H visibility are now explicitly routed, so blank-source wording is superseded.
- The old suggestion that `0x005037f0` could be a source helper is rejected by its sole constructor-EH xref and two-instruction Singleton clear. The ordinary source destructor is UID0003XH; UID0003XK/XL/XM are compiler lowering.
- UiAssetModeRect neighbors UID0002BD/UID0002BE remain outside the class. The private glyph field proves UID0002BF ownership only and does not transfer ownership of adjacent rectangle helpers.

## Cross-References

- [UID:0000L3][MapPane](by-file/MapPane.md)
- [UID:0000L2][MapNamePane](by-file/MapNamePane.md)
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
- [UID:0003IL][0x0061e6c0-0x0061e6d8.MapNamePaneEpfResourceString](by-memory/0x0061e6c0-0x0061e6d8.MapNamePaneEpfResourceString.md)
- [UID:0003C1][0x0061e6c0-0x0061e700.MapNameMiniMapResourceStrings](by-memory/0x0061e6c0-0x0061e700.MapNameMiniMapResourceStrings.md)
- [UID:0000SW][g_useEpfAssets](by-global/g_useEpfAssets.md)

## Changes

- 2026-06-22 Rule 26 B001-0002BF closeout:
  - Score unchanged at `86/88`; added [UID:0002BF][0x00503110-0x005031e1.WideGlyphResourceTextRendererRaw](by-memory/0x00503110-0x005031e1.WideGlyphResourceTextRendererRaw.md) as a retained private helper assigned to this class.
  - Evidence: B001-0002BF found that the raw `thiscall` helper reads `this + 0x220`, the same `m_mapNameGlyphTable` slot loaded with `9X11FONT.BIN` by the constructor and freed by the destructor; no live route is proven, so the helper remains blank-C++ and should not be used to assign the neighboring raw rectangle helpers.

- 2026-06-07 A008 alias cleanup: normalized the constructor/render `byte_66DA97` resource-mode branches to canonical [UID:0000SW][g_useEpfAssets](by-global/g_useEpfAssets.md), preserving `byte_66DA97` as the IDA lookup alias.
- 2026-06-12 A001 Batch 271: Added the exact [UID:0003C1][0x0061e6c0-0x0061e700.MapNameMiniMapResourceStrings](by-memory/0x0061e6c0-0x0061e700.MapNameMiniMapResourceStrings.md) `MAPNAME.EPF` evidence and kept the score unchanged because the page already cleared the parent gate; final source split remains the cap.
- 2026-06-12 A002 Batch 325: Updated the broad string reference to exact child [UID:0003IL][0x0061e6c0-0x0061e6d8.MapNamePaneEpfResourceString](by-memory/0x0061e6c0-0x0061e6d8.MapNamePaneEpfResourceString.md), which is assigned to this class. Score unchanged at `86/88`; the class already cleared the direct-parent gate.
- 2026-05-28: Updated the shared memory-island reference from `0x005031f0-0x0050395e` to `0x005031f0-0x0050395f`. Evidence: IDA MCP reports the interleaved `MiniMapButtonPane` destructor ending at `0x0050395f`; the previous boundary omitted the final `retn 4` immediate byte.
- Completion/confidence score update: existed before as `0/0`; changed to `76/78`. Summary: the small map-name UI pane has clear behavior, constructor/destructor/render method coverage, shared island caveat, and thunk exclusion notes, but final file split and exhaustive field/resource details remain incomplete. Evidence: linked `MapNameAndMiniMapButtonPanes` and `MapNamePane` memory pages, IDA-confirmed starts, UI setup caller, and documented interleaving with `MiniMapButtonPane`.
- 2026-06-05 live IDA rescore:
  - Changed from: `COMPLETION:76`, `CONFIDENCE:78`, reconstructable/parent unset.
  - Changed to: `COMPLETION:86`, `CONFIDENCE:88`, `RECONSTRUCTABLE:TRUE`, `AUTOGEN_PARENT_UID:0000L2`.
  - Reason for score increase: live IDA MCP confirmed exact function sizes, two constructor callers, three decorated `MapNamePane` vtables, constructor/destructor/scalar-destructor vtable stores, render and update-handler vtable slots, singleton lifecycle refs, resource pointer cleanup, map-name buffer offsets, the previously omitted `0x005034a0` opcode-`0x15` update handler, the `0x005037f0` singleton-clear helper, and internal padding around the interleaved MiniMap island. The score remains below final reconstruction because source-level field names, helper names, and standalone-vs-file-local placement are still not proven.
- 2026-06-17 B001 source-quality execution:
  - Score unchanged at `86/88`.
  - Evidence: accepted B001 report resolved the preferred standalone `NexusTK/map/MapNamePane.cpp` source route, rejected direct `MapPane.cpp` ownership, replaced the legacy aggregate emission route with exact child pages [UID:0003XG][0x005031f0-0x005032c3.MapNamePaneConstructor](by-memory/0x005031f0-0x005032c3.MapNamePaneConstructor.md)-[UID:0003XM][0x00503840-0x005038fe.MapNamePaneScalarDeletingDestructor](by-memory/0x00503840-0x005038fe.MapNamePaneScalarDeletingDestructor.md), and recorded source-facing names for constructor, ordinary destructor, paint, map-name update packet handling, singleton clear, destructor adjustor thunks, and scalar deleting destructor. Formal C++ remains blank on children until shared event/resource/glyph helper types are source-quality.
