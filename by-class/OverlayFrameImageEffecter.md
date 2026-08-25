*** UID:00009X | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:91 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000IZ | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000IZ | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
class OverlayFrameImageEffecter : public OverlayEffecter
{
public:
    OverlayFrameImageEffecter(const wchar_t *frameResourceName,
                              const wchar_t *paletteName,
                              int overlayX,
                              int overlayY,
                              int frameIndex);
    virtual ~OverlayFrameImageEffecter();

    virtual void RenderOverlayFrame();

private:
    wchar_t m_frameResourceName[16];
    wchar_t m_paletteName[16];
    ArchiveMetadataTable *m_frameTable;
    FrameDrawRecord m_frameDrawRecord;
    short m_frameIndex;
};
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# OverlayFrameImageEffecter

## Status

- Confidence: very strong for class identity, Effects ownership, four-view vtable identity, adjusted `+0x04` pane/GrafPort render receiver mapping, frame-table lifetime, helper route, and first-draft source shape for exact future method children.
- Likely source module: [UID:0000IZ][Effects](by-file/Effects.md), emitted under `NexusTK/render/Effects.cpp`.
- Current memory range: [UID:0001GE][0x0055a260-0x0055c1ff.ScreenEffecterRuntimeCluster](by-memory/0x0055a260-0x0055c1ff.ScreenEffecterRuntimeCluster.md).
- Vtable/layout anchor: [UID:0001YO][ScreenEffecterVtableFamily](by-type/by-vtable/ScreenEffecterVtableFamily.md).
- Base class: [UID:00009W][OverlayEffecter](by-class/OverlayEffecter.md).
- C++ status: formal class-page C++ now emits the declaration and field split. The source-owned render, constructor, and ordinary destructor bodies are first-draft ready once exact by-memory child pages exist. The scalar deleting destructor is compiler-generated and must not be emitted as handwritten source.

## Responsibility

`OverlayFrameImageEffecter` is the frame-indexed overlay subclass of [UID:00009W][OverlayEffecter](by-class/OverlayEffecter.md). It copies a frame resource name and a palette name, stores an owned image-frame table block loaded through [UID:0000QU][g_pEPFLib](by-global/g_pEPFLib.md), initializes an embedded EPFTileContext-compatible frame draw record, stores a current frame index, and renders that selected frame through [UID:00016A][0x004ba6b0-0x004ba81d.GrafPortDrawTiledBackground](by-memory/0x004ba6b0-0x004ba81d.GrafPortDrawTiledBackground.md).

The important source-quality correction is that the render body at `0x0055a5e0` is installed in the embedded `+0x04` pane/GrafPort vtable view. It receives `ecx = complete this + 4`, not the complete object pointer. Raw render offsets such as adjusted `this+0xfc`, `this+0x11c`, `this+0x140`, and `this+0x168` must therefore be normalized to complete-object offsets before naming fields.

## Method Notes

| Address | Size | Source-facing role | Notes |
| --- | ---: | --- | --- |
| `0x0055a5e0-0x0055a61b` | `0x3b` / 59 bytes | `RenderOverlayFrame` / pane draw virtual; `OnPaint` or `Draw` remains possible final family name | Installed at pane/GrafPort view slot `0x006237a8`; resolves a frame record from `g_pEPFLib` and calls `GrafPort::DrawTiledBackground`. It renders an already stored frame index and does not advance animation state, so old `UpdateFrameAndRender` wording is only historical behavior prose. |
| `0x0055a620-0x0055a6ea` | `0xca` / 202 bytes | complete-object constructor | Calls `OverlayEffecter(1, overlayX, overlayY)`, installs four subclass vtable views, initializes the frame draw record, loads the owned frame table, copies two 16-wide-character names, stores the frame index, sets the active/visible byte, and returns with `ret 0x14`, proving five explicit arguments. |
| `0x0055a6f0-0x0055a797` | `0xa7` / 167 bytes | ordinary destructor | Releases the owned frame-table block at complete `+0x140`, then performs compiler/base vtable and pane teardown. Source body should only model `DestroyOwnedImageBlock(m_frameTable)`. |
| `0x0055bc90-0x0055bd63` | `0xd3` / 211 bytes | compiler-generated scalar deleting destructor | Repeats derived/base teardown and conditionally deletes storage based on MSVC flags. Keep as vtable/compiler evidence only; do not emit as source C++. |

## Adjusted Renderer Receiver

`0x0055a5e0` is in the embedded pane/GrafPort view table that starts at `0x00623764`; the render slot is `0x006237a8 -> 0x0055a5e0`. The incoming `ecx` is therefore the complete object plus four. B015's raw PE/capstone audit resolves the stale field conflict by normalizing render offsets back to the complete object:

| Render-body offset | Complete-object offset | Best source-facing role | Evidence |
| --- | --- | --- | --- |
| adjusted `+0xfc` | complete `+0x100` | `m_frameResourceName` / possible `m_imageName` | Constructor copies the first 16-wide-character argument to complete `+0x100`; render passes adjusted `this+0xfc` to `ResourceLayoutTable::LookupLayoutEntry`. |
| adjusted `+0x11c` | complete `+0x120` | `m_paletteName` | Constructor copies the second 16-wide-character argument to complete `+0x120`; render passes adjusted `this+0x11c` as the palette/name argument to `GrafPort::DrawTiledBackground`. |
| adjusted `+0x140` | complete `+0x144` | `m_frameDrawRecord` / EPFTileContext-compatible draw record | Constructor calls `InitTileContext` at complete `+0x144`; render uses adjusted `this+0x140` as layout-lookup output and tiled-background source record. |
| adjusted `+0x168` | complete `+0x16c` | `m_frameIndex` | Constructor stores the final word argument at complete `+0x16c`; render reads adjusted `word [this+0x168]`. |
| adjusted `+0x44` | complete `+0x48` | inherited pane/GrafPort clip or visible bounds argument | Passed to `GrafPort::DrawTiledBackground` as the clip/bounds argument. The exact inherited field name is still a base-layout issue. |

Do not copy adjusted `this+0x11c` or `this+0x140` into complete-object field docs. Complete `+0x140` is the owned image-frame table pointer. Complete `+0x144` is the draw record passed to layout lookup and tiled rendering.

## Field And Subobject Direction

| Complete offset | Best name/type direction | Evidence and caveat |
| --- | --- | --- |
| `+0xf9` | inherited active/visible byte | Constructor writes `1`, matching sibling overlay effecters. Final inherited field spelling may be `m_active`, `m_visible`, or similar. |
| `+0x100` | `wchar_t m_frameResourceName[16]` / `m_imageName[16]` | First constructor argument copied with bounded wide-copy helper `0x005cd657`; used as the resource-layout lookup key. |
| `+0x120` | `wchar_t m_paletteName[16]` | Second constructor argument copied with the same 16-wide-character helper; used by `GrafPort::DrawTiledBackground` for palette lookup through `g_pPaletteLib`. |
| `+0x140` | `m_frameTable` / owned `ImageFrameTable` block pointer | Constructor stores `LoadImageFrameTable(frameResourceName, 0)` here; B010 2026-07-03 caller-disassembly evidence shows nearby `g_pEPFLib` / `ecx` setup is not a target parameter for this loader. Ordinary and scalar destructors free the same field through `DestroyOwnedImageBlock`. |
| `+0x144` | `m_frameDrawRecord` / `EPFTileContext`-compatible draw record | Initialized through `InitTileContext`, filled by `ResourceLayoutTable::LookupLayoutEntry`, and consumed by `GrafPort::DrawTiledBackground`. Exact final type spelling may be `FrameDrawRecord`, `EPFTileContext`, or a small wrapper around the context. |
| `+0x16c` | `short m_frameIndex` / current frame index | Final constructor argument; render body uses it as the layout-entry index. |
| `+0xfc/+0xfe` | inherited overlay placement words | Written by `OverlayEffecter(1, overlayX, overlayY)`. `overlayX`/`overlayY` are high-probability descriptive parameter names; `originX/originY` remains possible if a future Effects-family factory pass standardizes them. |

## Constructor Details

`0x0055a620` has a five-argument `ret 0x14` shape. Best current source-facing signature:

```cpp
OverlayFrameImageEffecter::OverlayFrameImageEffecter(
    const wchar_t *frameResourceName,
    const wchar_t *paletteName,
    int overlayX,
    int overlayY,
    int frameIndex);
```

Observed constructor behavior:

- Calls [UID:00009W][OverlayEffecter](by-class/OverlayEffecter.md) at `0x0055a651` with fixed first argument `1` and the two placement word arguments.
- Installs four `OverlayFrameImageEffecter` vtable views: primary `0x00623740`, embedded pane/GrafPort view `0x00623764`, secondary view `0x006237b0`, and secondary view `0x006237e0`.
- Calls [UID:00004I][EPFTileContext](by-class/EPFTileContext.md) initializer `0x00457a60` on complete `this+0x144`.
- Calls [UID:0002P4][0x004d0f50-0x004d15c5.LoadImageFrameTable](by-memory/0x004d0f50-0x004d15c5.LoadImageFrameTable.md) with the frame resource name and merge/direct flag `0`; stores the returned owned block at complete `+0x140`. B010 2026-07-03 clarifies that [UID:0000QU][g_pEPFLib](by-global/g_pEPFLib.md) / `ecx` setup at callers is not a target parameter.
- Copies `frameResourceName` to complete `+0x100` and `paletteName` to complete `+0x120` through secure 16-wide-character helper `0x005cd657`. Source prose should use `wcsncpy_s`, `wcscpy_s`, or `CopyWideString16` style wording rather than the raw helper name.
- Stores `frameIndex` as a word at complete `+0x16c` and writes active/visible byte complete `+0xf9 = 1`.
- Uses SEH/security-cookie and vtable-store mechanics generated by the compiler; those are not source statements.

## Render Method

`0x0055a5e0` saves `esi`/`edi`, resolves the selected frame, and tiles it:

- Loads [UID:0000QU][g_pEPFLib](by-global/g_pEPFLib.md) and calls [UID:0002KP][0x004d02f0-0x004d039e.ResourceLayoutTableLookupLayoutEntry](by-memory/0x004d02f0-0x004d039e.ResourceLayoutTableLookupLayoutEntry.md) with complete `m_frameResourceName`, `m_frameIndex`, and `&m_frameDrawRecord`.
- Calls [UID:00016A][0x004ba6b0-0x004ba81d.GrafPortDrawTiledBackground](by-memory/0x004ba6b0-0x004ba81d.GrafPortDrawTiledBackground.md) on the adjusted pane/GrafPort receiver, passing the inherited clip/bounds pointer, the complete `m_frameDrawRecord`, and complete `m_paletteName`.
- Has only a vtable pointer route at `0x006237a8` in the local PE scan. No direct rel32 callers or separate pointer routes were found.

`RenderOverlayFrame` is the best current descriptive source name. `OnPaint` / `Draw` remains possible final family spelling because the method is installed in the pane/GrafPort draw virtual view. Avoid `UpdateFrameAndRender` as the primary source-facing name because the body does not update animation state; it renders the current stored frame index.

## Destructor And Compiler Artifacts

The ordinary destructor `0x0055a6f0-0x0055a797`:

- Reinstalls all four most-derived `OverlayFrameImageEffecter` vtable views during the derived destructor phase.
- Calls [UID:0002P5][0x004d15d0-0x004d15fc.DestroyOwnedImageBlock](by-memory/0x004d15d0-0x004d15fc.DestroyOwnedImageBlock.md) on complete `this+0x140`.
- Resets the four [UID:00009W][OverlayEffecter](by-class/OverlayEffecter.md) base vtable views `0x006235e8`, `0x0062360c`, `0x00623658`, and `0x00623688`.
- Runs inherited pane teardown helpers `0x00544ce0` and `0x00544580` on complete `this+0x04`.
- Resets the primary base to [UID:0000C9][ScreenEffecter](by-class/ScreenEffecter.md) vtable `0x006235a4`.

The scalar deleting destructor `0x0055bc90-0x0055bd63` is compiler-generated wrapper code. It is reached from destructor jump-strip branches at `0x0055ba61`, `0x0055ba6c`, and `0x0055ba77`, and from primary vtable slot `0x00623758`. It returns `this`, performs no storage delete when `(flags & 1) == 0`, calls project delete helper `0x004f4ac0` when `(flags & 1) != 0 && (flags & 4) == 0`, and calls guarded sized/vector-delete helper `0x0041b6a0(this, 0x170)` when `(flags & 4) != 0`. Keep this wrapper, its flag behavior, and vtable route in evidence prose only.

## Vtable And Reachability

Raw `.rdata` around `0x0062373c-0x00623800` confirms:

- RTTI/COL pointer at `0x0062373c`.
- Primary table `0x00623740`; scalar deleting destructor slot `0x00623758 -> 0x0055bc90`.
- Embedded pane/GrafPort view table `0x00623764`; render slot `0x006237a8 -> 0x0055a5e0`.
- Secondary table `0x006237b0`.
- Secondary table `0x006237e0`.
- Next sibling [UID:00009Z][OverlayImageOnPointEffecter](by-class/OverlayImageOnPointEffecter.md) begins at `0x006237ec`.

B015's local raw PE scan found:

- `0x0055a5e0` has one VA pointer hit at `0x006237a8`.
- `0x0055bc90` has one VA pointer hit at `0x00623758`.
- Constructor `0x0055a620` and ordinary destructor `0x0055a6f0` have zero VA/RVA/raw-offset pointer hits.
- No direct rel32 calls/jumps reach `0x0055a5e0`, `0x0055a620`, or `0x0055a6f0`.
- The only direct branches to `0x0055bc90` are the destructor jump-strip branches noted above.

The missing direct constructor and ordinary-destructor routes cap final audit confidence but do not block Effects ownership or first-draft source shape. The constructor/destructor byte bodies, sibling overlay patterns, vtable installation, and frame-table load/free pairing are coherent source-authored class evidence.

## Helper Name Resolution

| Address/raw label | Recommended documentation name | Evidence |
| --- | --- | --- |
| `0x004d02f0` / `sub_4D02F0` | `ResourceLayoutTable::LookupLayoutEntry` | Central EPF/EPD layout lookup; render body fills the complete `+0x144` draw record. |
| `0x004d0f50` / `sub_4D0F50` | `LoadImageFrameTable` | Shared ImageFrameTable loader; constructor stores the owned return block at complete `+0x140`. |
| `0x004d15d0` / `sub_4D15D0` | `DestroyOwnedImageBlock` | Shared ImageFrameTable cleanup companion; destructor/scalar wrapper release complete `+0x140`. |
| `0x00457a60` / `sub_457A60` | `EPFTileContext::InitTileContext` / `InitTileContext` | Initializes the complete `+0x144` frame draw record. |
| `0x004ba6b0` / `sub_4BA6B0` | `GrafPort::DrawTiledBackground` | Tiled renderer that uses a `FrameDrawRecord`, source rectangle, palette name, and GrafPort draw state. |
| `0x005cd657` | secure 16-wide-character copy helper | Use source-level bounded wide-string copy wording; exact helper/import spelling remains below final-source quality. |
| `0x0067a744` | `g_pEPFLib` | Current IDA/global canonical ImageLib/ResourceLayout singleton. |
| `0x0067a7e0` | `g_pPaletteLib` | Palette singleton consumed indirectly by `GrafPort::DrawTiledBackground`. |

Rejected raw/generated names and owner routes:

- Do not leave `sub_55A5E0`, `sub_55A620`, `sub_55A6F0`, or `sub_55BC90` as passive blockers. Use descriptive class-method names and keep the scalar wrapper as compiler-generated.
- Fitting-room/download helper provenance names are caller-biased render-helper pollution and do not change ownership.
- Do not move this class to direct `Surface`, `GrafPort`, `ImageFrameTable`, `ResourceLayoutTable`, or `EPFTileContext` ownership. Those pages own dependencies.
- Do not route to a standalone `OverlayFrameImageEffecter.cpp` split in this pass; current file owner remains [UID:0000IZ][Effects](by-file/Effects.md).
- Do not handwrite SEH, security cookies, vtable stores/restores, destructor adjustors, scalar-delete wrappers, or base destructor mechanics as source C++.

## First-Draft Source Shape For Future Exact Children

When exact by-memory method children are created, the source-owned bodies can use this draft shape:

```cpp
OverlayFrameImageEffecter::OverlayFrameImageEffecter(
    const wchar_t *frameResourceName,
    const wchar_t *paletteName,
    int overlayX,
    int overlayY,
    int frameIndex)
    : OverlayEffecter(1, overlayX, overlayY),
      m_frameTable(nullptr),
      m_frameIndex(static_cast<short>(frameIndex))
{
    InitTileContext(&m_frameDrawRecord);
    m_frameTable = LoadImageFrameTable(frameResourceName, 0);
    wcsncpy_s(m_frameResourceName, 16, frameResourceName, _TRUNCATE);
    wcsncpy_s(m_paletteName, 16, paletteName, _TRUNCATE);
    m_active = true;
}

void OverlayFrameImageEffecter::RenderOverlayFrame()
{
    g_pEPFLib->LookupLayoutEntry(m_frameResourceName,
                                 m_frameIndex,
                                 &m_frameDrawRecord);
    DrawTiledBackground(&m_visibleBounds, &m_frameDrawRecord, m_paletteName);
}

OverlayFrameImageEffecter::~OverlayFrameImageEffecter()
{
    DestroyOwnedImageBlock(m_frameTable);
}
```

This is source-shape documentation, not formal class-page emitted C++. `RenderOverlayFrame` may become `OnPaint`/`Draw` after a whole effecter-family pane-vtable naming pass. `m_active`, `m_visibleBounds`, and `overlayX`/`overlayY` remain high-confidence descriptive names rather than recovered symbols.

## Autogen Status

Attach this class to [UID:0000IZ][Effects](by-file/Effects.md) as reconstructable runtime-effecter metadata. The class clears the active `85/85` documentation gate, and formal C++ now emits the class declaration and field split supported by the B015 pass. Method bodies remain non-contiguous inside [UID:0001GE][0x0055a260-0x0055c1ff.ScreenEffecterRuntimeCluster](by-memory/0x0055a260-0x0055c1ff.ScreenEffecterRuntimeCluster.md), exact method child pages do not yet exist, the scalar deleting destructor is compiler-generated, and constructor/ordinary-destructor reachability remains vtable/family-pattern evidence rather than direct caller evidence.

Preferred future split children are `0x0055a5e0-0x0055a61b`, `0x0055a620-0x0055a6ea`, `0x0055a6f0-0x0055a797`, and `0x0055bc90-0x0055bd63` with the scalar wrapper marked no-formal-C++.

## Cross-References

- [UID:0000IZ][Effects](by-file/Effects.md)
- [UID:0001YO][ScreenEffecterVtableFamily](by-type/by-vtable/ScreenEffecterVtableFamily.md)
- [UID:00009W][OverlayEffecter](by-class/OverlayEffecter.md)
- [UID:0001GE][0x0055a260-0x0055c1ff.ScreenEffecterRuntimeCluster](by-memory/0x0055a260-0x0055c1ff.ScreenEffecterRuntimeCluster.md)
- [UID:0000QU][g_pEPFLib](by-global/g_pEPFLib.md)
- [UID:0000RW][g_pPaletteLib](by-global/g_pPaletteLib.md)
- [UID:0002KP][0x004d02f0-0x004d039e.ResourceLayoutTableLookupLayoutEntry](by-memory/0x004d02f0-0x004d039e.ResourceLayoutTableLookupLayoutEntry.md)
- [UID:0002P4][0x004d0f50-0x004d15c5.LoadImageFrameTable](by-memory/0x004d0f50-0x004d15c5.LoadImageFrameTable.md)
- [UID:0002P5][0x004d15d0-0x004d15fc.DestroyOwnedImageBlock](by-memory/0x004d15d0-0x004d15fc.DestroyOwnedImageBlock.md)
- [UID:00016A][0x004ba6b0-0x004ba81d.GrafPortDrawTiledBackground](by-memory/0x004ba6b0-0x004ba81d.GrafPortDrawTiledBackground.md)

## 2026-06-30 B006 Empty-Emitter Callback

Formal C++ now emits the class declaration and field split supported by the B015 pass: copied `m_frameResourceName[16]`, copied `m_paletteName[16]`, owned `ArchiveMetadataTable *m_frameTable` at complete `+0x140`, embedded `FrameDrawRecord m_frameDrawRecord` at complete `+0x144`, and `m_frameIndex` at complete `+0x16c`. Method bodies remain deferred to future exact children for render `0x0055a5e0-0x0055a61b`, constructor `0x0055a620-0x0055a6ea`, and ordinary destructor `0x0055a6f0-0x0055a797`; scalar deleting destructor `0x0055bc90-0x0055bd63` remains compiler-generated. The no-direct constructor/destructor caveat remains a confidence cap, not a no-code reason for the declaration.

## Changes

- 2026-06-22 B015 Rule 26 source-quality incorporation:
  - Before: `84/88`, empty formal output, and render-body offsets were recorded as if the receiver were the complete object.
  - After: `88/91`, owner/emitter remain [UID:0000IZ][Effects](by-file/Effects.md), reconstructable remains true, and class-level formal output was withheld by exact-child split policy. B006 2026-06-30 supersedes that with declaration-only output.
  - Summary/evidence: incorporated B015 report-level details without a detail cap. The page now records the adjusted `+0x04` pane/GrafPort receiver, normalized complete-object fields `+0x100/+0x120/+0x140/+0x144/+0x16c`, exact render/constructor/ordinary-destructor/scalar-wrapper ranges and sizes, four-view vtable evidence, frame-table load/free pairing, `ResourceLayoutTable::LookupLayoutEntry`, `LoadImageFrameTable`, `DestroyOwnedImageBlock`, `InitTileContext`, `GrafPort::DrawTiledBackground`, secure wide-copy helper, `g_pEPFLib` and `g_pPaletteLib` roles, no-direct constructor/destructor route caveat, rejected owner/name alternatives, and first-draft source shape for future exact method children.
- 2026-06-07 A005 resolved-name cleanup:
  - Before: frame metadata/resource evidence used only historical `dword_67A744`.
  - After: the page records canonical `g_pEPFLib` beside the historical label and cross-links the global page.
  - Evidence: generated resolved-name report maps `dword_67A744` to `g_pEPFLib`; existing IDA-backed evidence already ties the references to EPF frame metadata/resource loading.
- 2026-06-05:
  - Before: scored `72/82`, reconstructability and parent metadata were blank, and the page only had high-level method-range notes.
  - After: scored `84/88`, marked reconstructable, attached to [UID:0000IZ][Effects](by-file/Effects.md), and withheld formal output at that time.
  - Why: live IDA evidence now confirms exact modeled function ranges, constructor base call and four-view vtable stores, frame-table load/free helpers, two copied 16-wide-character names, update/render flow through `sub_4D02F0` and `sub_4BA6B0`, scalar-delete jump-strip refs, exact vtable slot targets, and the remaining lack of direct constructor/non-scalar-destructor callers. Completion remains below final-source quality because field names, creator inventory, and final method names are incomplete.
- Before: completion/confidence metadata were `0/0` while the page already contained role, owner, method ranges, and overlay-base relationships.
- Changed to: `COMPLETION:72` and `CONFIDENCE:82`.
- Evidence: frame update/render, constructor, destructor, scalar deleting destructor, source-family, vtable family, and base class relationships are documented; completion remains below high because field names, callers, and reconstructed C++ are not fully covered.
