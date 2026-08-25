*** UID:0000MK | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:95 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"NexusTK/map/" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:FILE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***

# PhotoPane

## Status

- Confidence: very strong for the complete source graph, exact six human definitions, map-feature placement, constructor callers, typed map records, destructor-family source causes, EventHandler identities, and generated split; combined `PhotoPane.cpp` remains the selected route while an adjacent viewer file is retained only as a bounded historical alternative.
- Proposed module: `map/PhotoPane.cpp`
- Proposed header: `map/PhotoPane.h`
- Generated-output context: `source-3/simroot_v2/class_PhotoPane.cpp` and `source-3/simroot_v2/class_PictureViewPane.cpp` are useful generated references but are not original-source evidence.
- Main address cluster: `0x00549620-0x00549bc5`

## File Role

This module owns the map-photo/viewer pane used to show a generated snapshot of a map area and avatar. `PhotoPane` builds an off-screen `GrafPort`/`m_snapshotPort` from a map DAT entry, renders a 17 by 15 terrain/object tile preview, draws a `NewHumanImageLib` avatar over it, and later blits that cached `GrafPort` during paint.

`PictureViewPane` is the immediate viewer/base pane that attaches itself to the active view pane, uses the same full-screen image-view lifecycle, and calls `Pane::MarkForDeletion()` on selected close/dismiss message codes. The current reconstruction should keep `PhotoPane` and `PictureViewPane` together in `NexusTK/map/PhotoPane.cpp`; a separate adjacent `PictureViewPane.cpp` remains possible, but should not be created until another derived viewer or source filename evidence appears.

## Proposed Contents

| Entity | Address | Role |
| --- | --- | --- |
| `PhotoPane` | `0x00549620-0x00549a22` plus compiler support | Map-photo pane with embedded `GrafPort`/`m_snapshotPort`, map DAT load, typed tile/object/avatar render, paint blit, and implicit-destructor compiler cleanup. |
| `PictureViewPane` | `0x00549a30-0x00549bc5` plus thunks | Full-screen picture/viewer pane base used by `PhotoPane`; creates against the active view pane and handles close/delete messages. |

## Function Map

| Range | Function | Notes |
| --- | --- | --- |
| `0x00549620-0x00549911` | [UID:0004RJ][0x00549620-0x00549911.PhotoPaneConstructor](by-memory/0x00549620-0x00549911.PhotoPaneConstructor.md) | Exact source constructor; opens `C%04d.MAP`, initializes `m_snapshotPort`, traverses an opaque eight-byte header plus 15x17 six-byte map records, renders terrain/static objects and one partially seeded avatar descriptor, and excludes vptr/EH lowering. |
| `0x00549920-0x00549950` | `PhotoPane` raw cleanup destructor body | Non-IDA-modeled generated-binary cleanup/unwind body; writes `PhotoPane` vtables, destroys embedded `GrafPort`/`m_snapshotPort` at `this + 0xf8`, then tail-jumps to `PictureViewPane` teardown; see [UID:0002R8][0x00549920-0x00549950.PhotoPaneCleanupDestructorBodyRaw](by-memory/0x00549920-0x00549950.PhotoPaneCleanupDestructorBodyRaw.md). |
| `0x00549950-0x005499a2` | [UID:0004RK][0x00549950-0x005499a2.PhotoPaneOnPaint](by-memory/0x00549950-0x005499a2.PhotoPaneOnPaint.md) | Exact source virtual; obtains cached bounds, ends visible drawing, blits `m_snapshotPort`, and refreshes visible surface access in binary order. |
| `0x005499a2-0x005499b8` | `PhotoPane` adjustor thunks | Vtable glue for the paint/delete views. |
| `0x005499c0-0x00549a22` | `PhotoPane::ScalarDeletingDestructor` | Resets `PhotoPane` vtables, destroys the embedded `GrafPort`, chains to the non-deleting destructor, and optionally deletes. |
| `0x00549a30-0x00549ad6` | [UID:0004RL][0x00549a30-0x00549ad6.PictureViewPaneConstructor](by-memory/0x00549a30-0x00549ad6.PictureViewPaneConstructor.md) | Exact source constructor; initializes `Pane(0)`, copies `g_activeMapPane` bounds, calls `SetPaneOrder(NULL, g_activeMapPane)`, and attaches through the main layer head. |
| `0x00549ae0-0x00549aff` | [UID:0004RM][0x00549ae0-0x00549aff.PictureViewPaneDestructor](by-memory/0x00549ae0-0x00549aff.PictureViewPaneDestructor.md) | Exact empty out-of-line virtual source destructor; compiler vptr resets and Pane teardown are excluded. |
| `0x00549b00-0x00549b22` | [UID:0004RN][0x00549b00-0x00549b22.PictureViewPaneHandlePointerOrMouseEvent](by-memory/0x00549b00-0x00549b22.PictureViewPaneHandlePointerOrMouseEvent.md) | Exact EventHandler `+0x04` override; handles left/right button-up through inherited `Pane::MarkForDeletion()` and always returns true. |
| `0x00549b30-0x00549b4d` | [UID:0004RO][0x00549b30-0x00549b4d.PictureViewPaneHandleKeyOrTextEvent](by-memory/0x00549b30-0x00549b4d.PictureViewPaneHandleKeyOrTextEvent.md) | Exact EventHandler `+0x08` override; handles key-down through inherited `Pane::MarkForDeletion()` and always returns true without reading key payload. |
| `0x00549b4d-0x00549b63` | [UID:0004RP][0x00549b4d-0x00549b63.PictureViewPaneDestructorAdjustorThunks](by-memory/0x00549b4d-0x00549b63.PictureViewPaneDestructorAdjustorThunks.md) | Compiler-generated `-0xa0`/`-0xa4` vtable glue to the scalar deleting wrapper; false/non-emitting/blank. |
| `0x00549b70-0x00549bc5` | `PictureViewPane::ScalarDeletingDestructor` | Resets `PictureViewPane` vtables, tears down `Pane`, and optionally deletes. |

## Ownership Decision

Place this under `map/` rather than generic `ui/controls`. The constructor consumes map resource files (`C%04d.MAP`), terrain tile rendering, static-object rendering, and human/avatar rendering. `MapPane::HandlePacket` is a confirmed constructor caller, which makes the pane a map feature consumer rather than a reusable dialog control.

Do not group this with [UID:0000HX][BulletinSession](by-file/BulletinSession.md) based only on current generated `PictureViewPane` handler text. B014's source-quality pass resolves `0x00544690` as [UID:0001EA][0x00544460-0x00545086.PaneCore](by-memory/0x00544460-0x00545086.PaneCore.md)'s broad `Pane::MarkForDeletion` helper; the generated `BulletinSession::MarkForDeletion` name is owner pollution.

## Complete Source Graph

- [UID:0000AH][PictureViewPane](by-class/PictureViewPane.md) emits first at file position 10 and closes before its children; [UID:0000AG][PhotoPane](by-class/PhotoPane.md) follows at position 20 and also closes before its children.
- Exactly six human definitions emit from UID0004RL, UID0004RM, UID0004RN, UID0004RO, UID0004RJ, and UID0004RK. The base class declaration precedes the derived class declaration.
- UID0001F2 and UID0001F3 are non-emitting mixed indexes; UID0003OW is generated vtable data; UID0004RP is compiler adjustor glue; UID0002R8 is a comment-only compiler cleanup marker; scalar deleting wrappers and padding do not emit handwritten methods.
- The source intentionally contains no explicit PhotoPane destructor definition. Implicit destruction of `m_snapshotPort` plus the virtual PictureViewPane destructor accounts for raw cleanup, scalar-wrapper, adjustor, and constructor-EH paths.
- Generated output must contain no `BulletinSession` owner text, raw addresses, `this-0xa0`, explicit vptr writes, scalar-delete flags, adjustor arithmetic, or duplicate parent/child source.

## Compiler-Data And Authored-Source Split

- The selected authored module remains `NexusTK/map/PhotoPane.cpp` with `PictureViewPane` at position 10 and `PhotoPane` at position 20. Their six human definitions are UID0004RL, UID0004RM, UID0004RN, UID0004RO, UID0004RJ, and UID0004RK in the documented source order.
- Corrected aggregate [UID:000265][0x00622030-0x00622154.PhotoPictureReadOnlyData](by-memory/0x00622030-0x00622154.PhotoPictureReadOnlyData.md) begins with the PhotoPane primary COL pointer rather than the first callable cell. Its exact children are [UID:0003OU][0x00622030-0x006220b8.PhotoPaneVtableData](by-memory/0x00622030-0x006220b8.PhotoPaneVtableData.md), [UID:0003OV][0x006220b8-0x006220cc.PhotoPaneMapFilenameFormatString](by-memory/0x006220b8-0x006220cc.PhotoPaneMapFilenameFormatString.md) `C%04d.MAP` at `[0x006220b8,0x006220cc)`, and [UID:0003OW][0x006220cc-0x00622154.PictureViewPaneVtableData](by-memory/0x006220cc-0x00622154.PictureViewPaneVtableData.md) PictureViewPane vtable data at `[0x006220cc,0x00622154)`.
- UID0003OU is 136 bytes with exact SHA256 `2E6C241E1EBD8FC18807C7D9D08A9251AE5B25A9C05B7CA0870F6DAE2C8A83A4`. It contains three COL pointers, 18 primary slots, 11 EventHandler-facet slots, two TimerHandler-facet slots, and no padding.
- The hierarchy encoded by those tables is `PhotoPane -> PictureViewPane -> Pane -> GrafPort -> LObject`, with EventHandler and TimerHandler inherited facets at object `+0xa0/+0xa4`. Only PictureViewPane is a direct PhotoPane source base.
- The primary view ends at `+0x44 PhotoPane::OnPaint`. The following dword is a secondary COL pointer, not a Pane-owned `+0x48 OnActivate`; that activation contract is introduced by PanelPane and does not belong in this module's PhotoPane declaration.
- Constructor, raw cleanup, and scalar-wrapper stores reach all three PhotoPane vtable views at `0x00622034`, `0x00622080`, and `0x006220b0`. UID0002R8's raw body, `0x005499a2/0x005499ad` adjustors, and `0x005499c0` scalar wrapper are compiler consequences of the implicit virtual PhotoPane destructor, owned `m_snapshotPort`, and virtual PictureViewPane base teardown.
- The source must not contain literal vtable arrays, RTTI objects, direct vptr writes, explicit facet adjustors, scalar deleting destructors, explicit direct EventHandler/TimerHandler bases, or an empty hand-authored PhotoPane destructor. These alternatives duplicate MSVC lowering and contradict the source-clean class graph.
- UID0003OU is therefore `RECONSTRUCTABLE:FALSE`, class-owned, non-emitting, and blank in both formal code channels. This is not lost source: the class declaration, constructor, OnPaint, inherited contracts, and implicit destructor regenerate the table island.
- The previous generated Empty Emitter Marker was caused solely by UID0003OU's stale reconstructable/emitter metadata. Clearing that physical-data emitter must remove only the marker while preserving the complete PhotoPane/PictureViewPane source graph.

## Evidence Notes

- 2026-06-12 live IDA MCP reports `PhotoPane::PhotoPane` at `0x00549620-0x00549911` and exactly two constructor call sites: [UID:0000L3][MapPane](by-file/MapPane.md) packet dispatch at `0x00508bc1` inside `0x00507c90-0x00508e06`, and `0x00514461` inside `sub_5143C0`.
- `sub_5143C0` reads a compact photo/map payload using `sub_575730` and `sub_575710`, allocates `0x198` bytes (408 bytes; Verified with `int_convert.py`), and calls `PhotoPane::PhotoPane`. B014 PE/Capstone recheck supports naming it `PhotoPaneFactoryHelper` / a no-direct-caller opcode `0x5a` companion body: it strengthens `PhotoPane` source placement but does not move implementation ownership to MapPane.
- The accepted constructor parameter direction is `PhotoPane::PhotoPane(unsigned short mapId, unsigned char avatarShape, int avatarTileX, int avatarTileY, unsigned char avatarDirection)`. Packet order is `uint16 mapId`, `uint16`/low-byte avatar shape or body byte, `uint8 avatarDirection`, `uint8 avatarTileX`, and `uint8 avatarTileY`.
- `PhotoPane::PhotoPane` calls shared render helpers from [UID:0000L5][MapTileImageLib](by-file/MapTileImageLib.md), [UID:0000O7][StaticObjImageLib](by-file/StaticObjImageLib.md), and [UID:0000LR][NewHumanImageLib](by-file/NewHumanImageLib.md).
- IDA MCP 2026-06-12 identifies `0x00549920-0x00549950` as a unique `0x30`-byte raw executable destructor-shaped cleanup body (48 bytes; Verified with `int_convert.py`) not modeled as a function start; it belongs with `PhotoPane` because it writes `PhotoPane` vtables at `0x00622034`, `0x00622080`, and `0x006220b0`, destroys the embedded `GrafPort`/`m_snapshotPort` at `this + 0xf8`, and tail-jumps to `0x00549ae0`.
- B005 current MCP session `80de0a67` supersedes the older blank-C++ handling for [UID:0002R8][0x00549920-0x00549950.PhotoPaneCleanupDestructorBodyRaw](by-memory/0x00549920-0x00549950.PhotoPaneCleanupDestructorBodyRaw.md): the raw start still has no function object or incoming xref, but the child now carries a formal comment-only generated-binary marker because constructor/scalar-destructor parity, `PhotoPane` vtable xrefs, `sub_4B8D20` as `GrafPort` cleanup, and `sub_549AE0` as `PictureViewPane` teardown are resolved.
- `PhotoPane::OnPaint` only blits the cached `GrafPort`, supporting the constructor-rendered snapshot interpretation.
- The binary PhotoPane cleanup families reset vtables and destroy `m_snapshotPort`, but those actions are compiler lowering of implicit source destruction; adjacent `0x00549ae0` is the explicit PictureViewPane ordinary destructor.
- `PictureViewPane` constructor reads [UID:0000PR][g_activeMapPane](by-global/g_activeMapPane.md), copies bounds, and attaches itself through `MainUiLayerSlotsHead` / `g_mainUiLayerSlotsHead`; its close handlers do not access bulletin-specific article or board state.

## 2026-06-16 A001 File-Confidence Refresh

Live IDA MCP on `b001_mappane_0001AW_20260616` rechecked the current source-root blockers:

- `lookup_funcs` confirms `PhotoPane` constructor `0x00549620`, `OnPaint` `0x00549950`, scalar deleting destructor `0x005499c0`, non-deleting destructor `0x00549ae0`, `PictureViewPane` constructor `0x00549a30`, close handlers `0x00549b00`/`0x00549b30`, and scalar deleting destructor `0x00549b70`.
- `xrefs_to 0x00549620` still reports exactly two constructor call sites: [UID:0000L3][MapPane](by-file/MapPane.md) packet dispatch at `0x00508bc1` and the packet/UI payload helper at `0x00514461` inside `sub_5143C0`.
- `analyze_function 0x005143c0` reconfirms the second caller reads two 16-bit fields and three byte fields, allocates `0x198` bytes, and calls `PhotoPane::PhotoPane`; this remains a map-photo construction path even though the exact opcode/helper name is unresolved.
- Raw disassembly at `0x00549920-0x00549950` still shows a real cleanup body: it writes all three `PhotoPane` vtables, destroys the embedded `GrafPort`/`m_snapshotPort` at `this + 0xf8`, and tail-jumps to `0x00549ae0`. `lookup_funcs` and `xrefs_to` still show no function object or independent refs for that raw start.
- `xrefs_to` reconfirmed `PhotoPane` vtable stores from constructor, raw cleanup, and scalar deleting destructor at `0x00622034`, `0x00622080`, and `0x006220b0`; the close-handler vtable refs for `PictureViewPane` remain at `0x00622084`, `0x00622088`, `0x00622120`, and `0x00622124`.
- IDA string search finds RTTI class names for `PhotoPane` and `PictureViewPane`, but no embedded `PhotoPane.cpp` or `PictureViewPane.cpp` filename string. `search_structs` for both names returns no local IDA struct/type records.
- The then-current generated-output review found `class_PhotoPane.cpp` emitted constructor, `OnPaint`, scalar deleting destructor, and non-deleting destructor, but still had no `0x00549920` raw cleanup body in the C++ file or source map. B005 later resolves that omission by giving [UID:0002R8][0x00549920-0x00549950.PhotoPaneCleanupDestructorBodyRaw](by-memory/0x00549920-0x00549950.PhotoPaneCleanupDestructorBodyRaw.md) a formal comment-only marker rather than an independent method body.

That historical pass raised the file root to `88/88`. The current source-graph closure resolves the public virtual names, exact child bodies, and compiler/source disposition; only the original combined-file versus adjacent-file choice lacks direct filename evidence, with combined `NexusTK/map/PhotoPane.cpp` selected by contiguity, inheritance, caller, and feature cohesion.

## Current Caveats

- The exact original source split remains open. Current reconstruction should keep `PictureViewPane` in `NexusTK/map/PhotoPane.cpp`; a separate adjacent `PictureViewPane.cpp` remains possible only if another derived viewer or source filename evidence appears.
- Historical generated handler names implied `BulletinSession` ownership. That text is rejected owner pollution: the helper at `0x00544690` is `Pane::MarkForDeletion`, and source calls it normally from PictureViewPane overrides while the compiler supplies complete-object adjustment.
- The 2026-05-25 generated state that emitted `BulletinSession::MarkForDeletion` is historical. Exact children now use the current EventHandler names and keep `0x00549b4d`/`0x00549b58` as non-emitting adjustor thunks.
- The second direct caller at `sub_5143C0` is now behaviorally characterized as a payload reader/allocation path for `PhotoPane`; B014 identifies it as a no-direct-caller packet/factory helper tied to opcode `0x5a` and the same `PhotoPane` constructor payload shape.

## Cross-References

- [UID:0000AG][PhotoPane](by-class/PhotoPane.md)
- [UID:0000AH][PictureViewPane](by-class/PictureViewPane.md)
- [UID:0001F2][0x00549620-0x00549bc5.PhotoAndPicturePanes](by-memory/0x00549620-0x00549bc5.PhotoAndPicturePanes.md)
- [UID:0002R8][0x00549920-0x00549950.PhotoPaneCleanupDestructorBodyRaw](by-memory/0x00549920-0x00549950.PhotoPaneCleanupDestructorBodyRaw.md)
- [UID:0001F3][0x00549b00-0x00549b63.PictureViewPaneCloseHandlersAndThunks](by-memory/0x00549b00-0x00549b63.PictureViewPaneCloseHandlersAndThunks.md)
- [UID:0000L3][MapPane](by-file/MapPane.md)
- [UID:0001AT][0x00506970-0x0050e320.MapPaneInputPacketRenderCore](by-memory/0x00506970-0x0050e320.MapPaneInputPacketRenderCore.md)
- [UID:0000L5][MapTileImageLib](by-file/MapTileImageLib.md)
- [UID:0000O7][StaticObjImageLib](by-file/StaticObjImageLib.md)
- [UID:0000LR][NewHumanImageLib](by-file/NewHumanImageLib.md)
- [UID:0000IM][DATArchive](by-file/DATArchive.md)
- [UID:0004RJ][0x00549620-0x00549911.PhotoPaneConstructor](by-memory/0x00549620-0x00549911.PhotoPaneConstructor.md)
- [UID:0004RK][0x00549950-0x005499a2.PhotoPaneOnPaint](by-memory/0x00549950-0x005499a2.PhotoPaneOnPaint.md)
- [UID:0004RL][0x00549a30-0x00549ad6.PictureViewPaneConstructor](by-memory/0x00549a30-0x00549ad6.PictureViewPaneConstructor.md)
- [UID:0004RM][0x00549ae0-0x00549aff.PictureViewPaneDestructor](by-memory/0x00549ae0-0x00549aff.PictureViewPaneDestructor.md)
- [UID:0004RN][0x00549b00-0x00549b22.PictureViewPaneHandlePointerOrMouseEvent](by-memory/0x00549b00-0x00549b22.PictureViewPaneHandlePointerOrMouseEvent.md)
- [UID:0004RO][0x00549b30-0x00549b4d.PictureViewPaneHandleKeyOrTextEvent](by-memory/0x00549b30-0x00549b4d.PictureViewPaneHandleKeyOrTextEvent.md)
- [UID:0004RP][0x00549b4d-0x00549b63.PictureViewPaneDestructorAdjustorThunks](by-memory/0x00549b4d-0x00549b63.PictureViewPaneDestructorAdjustorThunks.md)
- [UID:0003OU][0x00622030-0x006220b8.PhotoPaneVtableData](by-memory/0x00622030-0x006220b8.PhotoPaneVtableData.md)
- [UID:000265][0x00622030-0x00622154.PhotoPictureReadOnlyData](by-memory/0x00622030-0x00622154.PhotoPictureReadOnlyData.md)
- [UID:000264][0x00621db8-0x00622030.PatchPaneReadOnlyData](by-memory/0x00621db8-0x00622030.PatchPaneReadOnlyData.md)

## Changes

- Before: `PictureViewPane` destructor coverage ended at `0x00549bc4`.
- Changed to: the destructor and containing photo/picture pane memory range end at `0x00549bc5`.
- Summary/evidence: 2026-05-28 IDA MCP byte/function review shows `0x00549bc4` is the final operand byte of the `retn 4` in `sub_549B70`; the following bytes through `0x00549bd0` are alignment padding.

- Before: the function map skipped `0x00549920-0x00549950`.
- Changed to: the raw cleanup destructor body is now listed as part of `PhotoPane` and linked to [UID:0002R8][0x00549920-0x00549950.PhotoPaneCleanupDestructorBodyRaw](by-memory/0x00549920-0x00549950.PhotoPaneCleanupDestructorBodyRaw.md).
- Summary/evidence: 2026-06-01 IDA MCP disassembly shows the raw body writes `PhotoPane` vtables, destroys `this + 0xf8`, and tail-jumps to `0x00549ae0`.

- Before: completion/confidence were ungraded at `0/0`.
- Changed to: completion `86`, confidence `80`.
- Summary/evidence: the page documents the photo/viewer module role, proposed contents, function map, ownership decision, IDA evidence, generated-handler caveats, range correction, and cross-references; confidence remains capped by final split from `PictureViewPane` and one unresolved constructor caller.

- 2026-06-12 A004 Goal 2 confidence refresh:
  - Before: `CONFIDENCE:80`; the page still had an unresolved secondary constructor caller and old raw-body evidence.
  - Changed to: `CONFIDENCE:85`.
  - Summary/evidence: live read-only IDA MCP on database `a002_batch346` reconfirmed the constructor range and both constructor xrefs. The `sub_5143C0` caller reads payload fields, allocates `0x198` bytes, and calls the constructor, so it strengthens the map-photo module placement even though its exact feature/opcode name remains open. The same pass reconfirmed [UID:0002R8][0x00549920-0x00549950.PhotoPaneCleanupDestructorBodyRaw](by-memory/0x00549920-0x00549950.PhotoPaneCleanupDestructorBodyRaw.md) as a unique raw `PhotoPane` destructor-family body and supports routing that child to [UID:0000AG][PhotoPane](by-class/PhotoPane.md). Exact `PhotoPane.cpp` versus split `PictureViewPane.cpp` source layout remains below final-audit certainty.
- 2026-06-16 A001 file-confidence refresh:
  - Before: `COMPLETION:86`, `CONFIDENCE:85`.
  - After: `COMPLETION:87`, `CONFIDENCE:86`.
  - Summary/evidence: live IDA MCP reconfirmed all `PhotoPane`/`PictureViewPane` modeled function starts, the exact two constructor xrefs, `sub_5143C0` payload-reader/allocation behavior, raw cleanup disassembly at `0x00549920-0x00549950`, vtable refs from constructor/raw/scalar destructor paths, and close-handler vtable slots. IDA has RTTI class names but no source filename strings or local structs; at that time generated output still omitted the raw cleanup body, an omission B005 later resolved with a formal comment-only marker rather than a standalone method body.
- 2026-06-22 B014 Rule 26 source-quality incorporation:
  - Before: `COMPLETION:87`, `CONFIDENCE:86`, with `Pane::MarkForDeletion`, constructor parameter roles, cached member naming, and opcode `0x5a` helper context still treated as passive blockers.
  - After: `COMPLETION:88`, `CONFIDENCE:88`.
  - Summary/evidence: B014 direct PE/Capstone reanalysis confirms the two constructor routes, `PhotoPaneFactoryHelper`/opcode `0x5a` companion shape, the constructor signature roles, `m_snapshotPort` at `this+0xf8`, resolved service globals, `g_activeMapPane`, `MainUiLayerSlotsHead`, and `Pane::MarkForDeletion` at `0x00544690`; the only residual file-level caveat is whether `PictureViewPane` was compiled in the same `PhotoPane.cpp` or adjacent viewer source file.
- 2026-06-25 B005 implementation of accepted [UID:0002R8][0x00549920-0x00549950.PhotoPaneCleanupDestructorBodyRaw](by-memory/0x00549920-0x00549950.PhotoPaneCleanupDestructorBodyRaw.md) report:
  - Updated the function inventory and source-placement notes so [UID:0002R8][0x00549920-0x00549950.PhotoPaneCleanupDestructorBodyRaw](by-memory/0x00549920-0x00549950.PhotoPaneCleanupDestructorBodyRaw.md) is generated-binary destructor cleanup/unwind evidence with a formal comment-only marker and no independent method body.
  - Replaced generic cleanup wording with embedded `GrafPort`/`m_snapshotPort` at `this+0xf8`.
  - Preserved `NexusTK/map/PhotoPane.cpp` as the current source route and preserved the remaining `PhotoPane.cpp` versus adjacent `PictureViewPane.cpp` split caveat.
- 2026-07-15 B004 UID0001F3 source-graph closure:
  - Before: `88/88`, exact six source definitions absent, public handler names unresolved, and adjacent `0x00549ae0` mislabeled as `PhotoPane::~PhotoPane`.
  - After: `92/94`, complete two-class/six-definition graph with real UIDs, exact compiler-only exclusions, typed map source, partial ObjectStatusBlob seed preservation, and corrected `PictureViewPane::~PictureViewPane` identity.
  - The combined `NexusTK/map/PhotoPane.cpp` route remains selected; separate adjacent `PictureViewPane.cpp` remains a rejected lower-ranked alternative absent direct filename evidence.
- 2026-07-26 Agent-B001 UID0003OU source-quality callback:
  - Before: `92/94`; the module had the complete human function graph but retained stale read-only-data boundaries and lacked the full compiler-data/source-regeneration closure behind UID0003OU's Empty Emitter Marker.
  - Changed to: `94/95`, corrected UID000264/UID000265/UID0003OU links, complete three-view RTTI/vtable and destructor-family disposition, exact authored-versus-generated exclusions, and deterministic marker-removal reasoning.
  - Evidence: live IDA MCP session `f085b224`, exact PhotoPane table bytes/hash, three COLs, 18/11/2 slots, seven-base hierarchy, lifecycle stores, current class UDT, existing six-definition source graph, and the generated command `000000017870` pre-callback marker checkpoint.
