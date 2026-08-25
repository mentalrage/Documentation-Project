*** UID:0000AG | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:95 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000MK | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000MK | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL:20 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
class PhotoPane : public PictureViewPane
{
public:
    PhotoPane(unsigned short mapId,
              unsigned char avatarShape,
              int avatarTileX,
              int avatarTileY,
              unsigned char avatarDirection);

    virtual void OnPaint();

private:
    GrafPort m_snapshotPort;
};

[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# PhotoPane

## Status

- Confidence: very strong for class behavior, map-photo ownership, constructor and OnPaint source, destructor-family cause, caller set, cached `GrafPort` member, typed map records, and source placement.
- Likely source file: [UID:0000MK][PhotoPane](by-file/PhotoPane.md)
- Main address range: `0x00549620-0x00549a22` for direct PhotoPane code within aggregate `0x00549620-0x00549bc5`; adjacent `0x00549ae0` is PictureViewPane teardown, not a PhotoPane method.
- Current recovered file: `source-3/simroot_v2/class_PhotoPane.cpp`
- Emission order: position 20 after base [UID:0000AH][PictureViewPane](by-class/PictureViewPane.md) at position 10; the class closes before `[[CHILDREN]]`.

## Class Purpose

`PhotoPane` is a `PictureViewPane`-derived map snapshot pane. It builds an off-screen `GrafPort`/`m_snapshotPort` from a `C%04d.MAP` resource, renders a small terrain/static-object map region plus an avatar, and paints by copying the cached image to the visible pane.

## Method Families

| Range | Function | Role |
| --- | --- | --- |
| `0x00549620-0x00549911` | [UID:0004RJ][0x00549620-0x00549911.PhotoPaneConstructor](by-memory/0x00549620-0x00549911.PhotoPaneConstructor.md) | Initialize the base/viewer pane, allocate and clip `m_snapshotPort`, load `C%04d.MAP`, render 15x17 typed terrain/static-object cells and one avatar, and close temporary resources while preserving the observed partial ObjectStatusBlob seed. |
| `0x00549920-0x00549950` | raw cleanup destructor body | Direct class child [UID:0002R8][0x00549920-0x00549950.PhotoPaneCleanupDestructorBodyRaw](by-memory/0x00549920-0x00549950.PhotoPaneCleanupDestructorBodyRaw.md); non-IDA-modeled generated-binary cleanup/unwind body writes `PhotoPane` vtables, destroys the embedded `GrafPort`/`m_snapshotPort` at `this + 0xf8`, then tail-jumps to `PictureViewPane` teardown. |
| `0x00549950-0x005499a2` | [UID:0004RK][0x00549950-0x005499a2.PhotoPaneOnPaint](by-memory/0x00549950-0x005499a2.PhotoPaneOnPaint.md) | Cache bounds, end visible drawing, blit `m_snapshotPort` to the same bounds, then refresh visible surface access in exact order. |
| `0x005499a2-0x005499b8` | adjustor thunks | Vtable glue for secondary class views. |
| `0x005499c0-0x00549a22` | scalar deleting destructor | Destroy the embedded `GrafPort`, chain to the non-deleting destructor, and optionally free storage. |
| `0x00549ae0-0x00549aff` | [UID:0004RM][0x00549ae0-0x00549aff.PictureViewPaneDestructor](by-memory/0x00549ae0-0x00549aff.PictureViewPaneDestructor.md) | Adjacent base-class teardown reached from PhotoPane cleanup; not a PhotoPane source method. |

## Layout Notes

- The cached `GrafPort` member at `PhotoPane + 0xf8` (248; Verified with `int_convert.py`) should be named `m_snapshotPort` or `m_cachedPhotoPort`; `m_snapshotPort` is the preferred first-draft name because the constructor builds an off-screen map/avatar snapshot and `OnPaint` only blits it.
- The constructor uses tile dimensions from the global tile-size state and draws a 17 by 15 visible tile snapshot (`0x11` -> 17 and `0xf` -> 15; Verified with `int_convert.py`).
- Static objects are drawn through [UID:0000E2][StaticObjImageLib](by-class/StaticObjImageLib.md), and the avatar bounds/draw path uses [UID:000092][NewHumanImageLib](by-class/NewHumanImageLib.md).
- Constructor callsites parse `uint16 mapId`, low-byte avatar shape, signed-width call arguments for tile coordinates, and low-byte direction. The source signature is `PhotoPane(unsigned short mapId, unsigned char avatarShape, int avatarTileX, int avatarTileY, unsigned char avatarDirection)`.
- The map payload is an opaque eight-byte header followed by 15x17 six-byte records containing `{terrainTileId, reserved, staticObjectId}`. This typed view replaces raw-byte source while preserving the exact pointer start, bounds, stride, and field reads.
- The constructor intentionally initializes only the ObjectStatusBlob fields observed in the binary before the avatar render call; it must not zero- or value-initialize unseeded bytes.

## Evidence Notes

- IDA MCP confirms the constructor, paint method, scalar deleting destructor, and non-deleting destructor as real functions in the `0x00549620-0x00549afe` cluster.
- IDA MCP 2026-06-01 also confirms raw executable cleanup code at `0x00549920-0x00549950`; IDA does not model it as a function, but its vtable writes and `this + 0xf8` cleanup identify it as `PhotoPane` destructor-family behavior.
- 2026-06-12 live IDA MCP on database `a002_batch346` reconfirmed the raw cleanup child as a unique `0x30`-byte body (48 bytes; Verified with `int_convert.py`) with no IDA function start, no xrefs to `0x00549920`, `PhotoPane` vtable stores at `0x00622034`, `0x00622080`, and `0x006220b0`, a `sub_4B8D20` `GrafPort`/`m_snapshotPort` cleanup call, and a tail jump to `0x00549ae0`.
- 2026-06-25 B005 current MCP session `80de0a67` keeps [UID:0002R8][0x00549920-0x00549950.PhotoPaneCleanupDestructorBodyRaw](by-memory/0x00549920-0x00549950.PhotoPaneCleanupDestructorBodyRaw.md) as a retained direct class child but changes its source-output policy: no function exists at `0x00549920` or `0x0054994b`, no xref reaches the raw start, and those facts cap confidence; constructor/scalar-destructor parity, `PhotoPane` vtable-store xrefs, `sub_4B8D20` as `GrafPort` cleanup, and `sub_549AE0` as `PictureViewPane` base teardown justify a formal comment-only generated-binary marker rather than a blank block or standalone method body.
- `xrefs_to 0x00549620` reports exactly two constructor call sites: [UID:0000L3][MapPane](by-file/MapPane.md) packet dispatch at `0x00508bc1` inside `0x00507c90-0x00508e06`, and `0x00514461` inside `sub_5143C0`.
- The `sub_5143C0` caller reads two 16-bit and three byte payload fields through `sub_575730`/`sub_575710`, allocates `0x198` bytes (408 bytes; Verified with `int_convert.py`), and calls `PhotoPane::PhotoPane`, confirming it is another packet/UI construction path for the same map-photo pane rather than unrelated ownership.
- B014 direct PE/Capstone reanalysis identifies that second route as a no-direct-caller `PhotoPaneFactoryHelper` / opcode `0x5a` companion body with the same payload shape. It is caller/factory evidence for `PhotoPane`; it is not implementation ownership for [UID:0000L3][MapPane](by-file/MapPane.md).
- `MapPane::HandlePacket` calls the constructor, so this class should be documented as map-feature UI rather than a generic image control.
- The paint method is intentionally simple because the expensive snapshot composition happens in the constructor.
- [UID:0000MK][PhotoPane](by-file/PhotoPane.md) is scored `86/85`, has valid `NexusTK/map/` placement, and documents the paired `PhotoPane`/`PictureViewPane` source-module decision, function map, ownership caveats, and current split uncertainty.
- [UID:0001F2][0x00549620-0x00549bc5.PhotoAndPicturePanes](by-memory/0x00549620-0x00549bc5.PhotoAndPicturePanes.md) is attached to the same file and records exact constructor, paint, destructor, padding, callee, touched-state, and resource-rendering evidence for this class.
- [UID:0000AH][PictureViewPane](by-class/PictureViewPane.md) is already attached to [UID:0000MK][PhotoPane](by-file/PhotoPane.md), which supports keeping this derived map-photo pane and the viewer base under the same source module.

## RTTI, Vtable, And Destructor Source Cause

- [UID:0003OU][0x00622030-0x006220b8.PhotoPaneVtableData](by-memory/0x00622030-0x006220b8.PhotoPaneVtableData.md) is the exact 136-byte non-emitting compiler-data island for this class. It contains three complete-object-locator pointers plus 31 callable cells and no padding. Its exact SHA256 is `2E6C241E1EBD8FC18807C7D9D08A9251AE5B25A9C05B7CA0870F6DAE2C8A83A4`.
- The primary complete-object locator is `??_R4PhotoPane@@6B@` through `0x00622030`, with complete-object offset `+0x00`. The secondary and tertiary locators are `??_R4PhotoPane@@6B@_0` at `0x0064e088` for object offset `+0xa0` and `??_R4PhotoPane@@6B@_1` at `0x0064e09c` for object offset `+0xa4`.
- The common hierarchy descriptor has multiple-inheritance attributes `1` and seven bases in exact order: `PhotoPane`, direct source base `PictureViewPane`, inherited `Pane`, inherited `GrafPort`, inherited `LObject`, inherited `EventHandler` facet at `+0xa0`, and inherited `TimerHandler` facet at `+0xa4`. The only direct source base remains `PictureViewPane`; adding EventHandler or TimerHandler as direct PhotoPane bases is rejected.
- The recovered `PhotoPane` type is `0x198` bytes. Its `PictureViewPane` base occupies `[+0x00,+0xf8)`, and owned `GrafPort m_snapshotPort` occupies `[+0xf8,+0x198)`. The `+0xa0/+0xa4` facet offsets are therefore inherited Pane subobjects, not new PhotoPane members.

Primary view `0x00622034-0x0062207c` has exactly 18 slots:

| Offset | Target | Source cause |
| --- | --- | --- |
| `+0x00` | `0x005499c0` | compiler scalar deleting wrapper for implicit virtual `PhotoPane::~PhotoPane()` |
| `+0x04` | `0x004f4b10` | inherited `LObject::GetRuntimeClass()` |
| `+0x08` | `0x0041b6c0` | inherited `LObject::OnChangeMessage` default |
| `+0x0c` | `0x004b8e20` | inherited `Pane::UpdateRenderRegion(const RectBounds *)` |
| `+0x10` | `0x0041d680` | inherited `Pane::DrawOnTarget(...)` no-op |
| `+0x14` | `0x00544730` | inherited `Pane::Show()` |
| `+0x18` | `0x00544750` | inherited `Pane::Hide()` |
| `+0x1c` | `0x005447a0` | inherited `Pane::GetParentPane()` |
| `+0x20` | `0x00544800` | inherited `Pane::InvalidateRect` |
| `+0x24` | `0x00544a20` | inherited `Pane::GetDescription` |
| `+0x28` | `0x00544b80` | inherited `Pane::GetScreenBounds` |
| `+0x2c` | `0x00544bd0` | inherited `Pane::SetBounds` |
| `+0x30` | `0x00544c70` | inherited `Pane::AddToLayer` |
| `+0x34` | `0x00544cb0` | inherited `Pane::InsertInLayer` |
| `+0x38` | `0x00544ce0` | inherited `Pane::RemoveFromLayer` |
| `+0x3c` | `0x00544d30` | inherited `Pane::SetPaneOrder` |
| `+0x40` | `0x00544d70` | inherited `Pane::UnregisterEventHandler` |
| `+0x44` | `0x00549950` | exact `PhotoPane::OnPaint()` override |

The EventHandler facet at object `+0xa0` has exactly 11 slots: destructor adjustor `0x005499a2`, PictureViewPane pointer/mouse handler `0x00549b00`, PictureViewPane key/text handler `0x00549b30`, inherited IME/packet/system/type-19 bridges `0x00544dd0/0x00544de0/0x00544df0/0x00544e00`, `ForwardHandlerOrder` at `0x004a89f0`, local/screen event-pair accessors `0x00544e10/0x00544e30`, and `ShouldAcceptEvent` at `0x00544e70`.

The TimerHandler facet at object `+0xa4` has exactly two slots: destructor adjustor `0x005499ad` and inherited `Pane::OnTimer(int,int,int)` at `0x00544e90`.

| Vtable view | Constructor store | Raw cleanup store | Scalar-wrapper store |
| --- | --- | --- | --- |
| primary `0x00622034` | `0x0054966f` | `0x00549929` | `0x005499cc` |
| EventHandler `0x00622080` | `0x00549675` | `0x0054992f` | `0x005499d2` |
| TimerHandler `0x006220b0` | `0x0054967f` | `0x00549939` | `0x005499dc` |

- The implicit virtual destructor is the source-faithful cause of the primary scalar wrapper, two facet adjustors, raw cleanup body, `m_snapshotPort` destruction, and PictureViewPane base teardown. An explicit empty destructor, literal vtable arrays, RTTI objects, vptr fields/stores, adjustor methods, or scalar-delete source would expose compiler lowering and is rejected.
- Pane's primary virtual contract ends at `+0x44 OnPaint`. The dword after it is the secondary COL pointer, not a Pane-owned `+0x48 OnActivate` slot. `OnActivate(const unsigned char *)` is introduced by PanelPane; PhotoPane is not a PanelPane and has no activation slot.
- The physical target is correctly `RECONSTRUCTABLE:FALSE`, semantically owned by this class, and non-emitting with blank CPP/H. This class declaration and its constructor/OnPaint children regenerate the binary data without a separate authored statement.

## Autogen Handling

Attach this class to [UID:0000MK][PhotoPane](by-file/PhotoPane.md). The class page emits the complete source-clean declaration only; exact constructor and OnPaint definitions belong to UID0004RJ and UID0004RK. Source omits an explicit PhotoPane destructor declaration because implicit virtual destruction of `m_snapshotPort` and the PictureViewPane base explains UID0002R8, adjustor/scalar support, and constructor-EH cleanup. No vptr, cookie, adjustor, scalar-delete, or raw cleanup pseudo-source belongs in this class block.

## Cross-References

- [UID:0000MK][PhotoPane](by-file/PhotoPane.md)
- [UID:0000AH][PictureViewPane](by-class/PictureViewPane.md)
- [UID:0001F2][0x00549620-0x00549bc5.PhotoAndPicturePanes](by-memory/0x00549620-0x00549bc5.PhotoAndPicturePanes.md)
- [UID:0002R8][0x00549920-0x00549950.PhotoPaneCleanupDestructorBodyRaw](by-memory/0x00549920-0x00549950.PhotoPaneCleanupDestructorBodyRaw.md)
- [UID:0001F3][0x00549b00-0x00549b63.PictureViewPaneCloseHandlersAndThunks](by-memory/0x00549b00-0x00549b63.PictureViewPaneCloseHandlersAndThunks.md)
- [UID:00007Q][MapPane](by-class/MapPane.md)
- [UID:0000L5][MapTileImageLib](by-file/MapTileImageLib.md)
- [UID:0000O7][StaticObjImageLib](by-file/StaticObjImageLib.md)
- [UID:0000LR][NewHumanImageLib](by-file/NewHumanImageLib.md)
- [UID:0004RJ][0x00549620-0x00549911.PhotoPaneConstructor](by-memory/0x00549620-0x00549911.PhotoPaneConstructor.md)
- [UID:0004RK][0x00549950-0x005499a2.PhotoPaneOnPaint](by-memory/0x00549950-0x005499a2.PhotoPaneOnPaint.md)
- [UID:0004RM][0x00549ae0-0x00549aff.PictureViewPaneDestructor](by-memory/0x00549ae0-0x00549aff.PictureViewPaneDestructor.md)
- [UID:0003OU][0x00622030-0x006220b8.PhotoPaneVtableData](by-memory/0x00622030-0x006220b8.PhotoPaneVtableData.md)
- [UID:000265][0x00622030-0x00622154.PhotoPictureReadOnlyData](by-memory/0x00622030-0x00622154.PhotoPictureReadOnlyData.md)

## Changes

- 2026-06-05: Marked `RECONSTRUCTABLE:TRUE` and left `AUTOGEN_PARENT_UID` blank.
  - Before: reconstruction autogen classification was blank despite map-photo pane documentation covering constructor, paint, destructor-family behavior, cached `GrafPort`, and render dependencies.
  - After: classified as reconstructable source but intentionally unassigned.
  - Evidence: live IDA MCP `lookup_funcs` confirms modeled starts at `0x00549620`, `0x00549950`, `0x005499a2`, `0x005499ad`, `0x005499c0`, and `0x00549ae0`; `0x00549920` remains raw executable cleanup code not modeled as an IDA function, matching the existing raw-body note. Parent attachment to [UID:0000MK][PhotoPane](by-file/PhotoPane.md) is deferred because the class has `CONFIDENCE:78`, below the 80/80 attach gate.

- Before: the containing `PhotoAndPicturePanes` memory page ended at `0x00549bc4`.
- Changed to: the page ends at `0x00549bc5`.
- Summary/evidence: 2026-05-28 IDA MCP byte/function review shows the final byte at `0x00549bc4` belongs to `PictureViewPane::ScalarDeletingDestructor`.
- Before: the method table omitted the raw cleanup destructor body at `0x00549920-0x00549950`.
- Changed to: the raw body is now listed in the method family and linked to [UID:0002R8][0x00549920-0x00549950.PhotoPaneCleanupDestructorBodyRaw](by-memory/0x00549920-0x00549950.PhotoPaneCleanupDestructorBodyRaw.md).
- Evidence: 2026-06-01 IDA MCP disassembly shows this unmodeled body installs `PhotoPane` vtables, calls the embedded `GrafPort`/`m_snapshotPort` cleanup at `this + 0xf8`, and tail-jumps to `0x00549ae0`.
- Before: completion/confidence metadata were `0/0` despite detailed constructor, paint, destructor, map snapshot, resource, and caller documentation.
- Changed to: `COMPLETION:80` and `CONFIDENCE:78`.
- Evidence: off-screen `GrafPort`, map DAT loading, terrain/object/avatar rendering, cached blit paint path, destructor family, `MapPane` caller, and resource/library dependencies are documented; confidence remains medium-high because final field names and exact source-level layout remain open.
- 2026-06-06: Raised confidence to `84` and attached `AUTOGEN_PARENT_UID:0000MK`.
  - Evidence: [UID:0000MK][PhotoPane](by-file/PhotoPane.md) is `86/80` with `NexusTK/map/` placement; [UID:0001F2][0x00549620-0x00549bc5.PhotoAndPicturePanes](by-memory/0x00549620-0x00549bc5.PhotoAndPicturePanes.md) is attached to the same parent and records exact constructor/callee/touched-state/destructor evidence; [UID:0002R8][0x00549920-0x00549950.PhotoPaneCleanupDestructorBodyRaw](by-memory/0x00549920-0x00549950.PhotoPaneCleanupDestructorBodyRaw.md) resolves the raw cleanup body; and [UID:0000AH][PictureViewPane](by-class/PictureViewPane.md) is already attached as the adjacent viewer base. At that point C++ remained blank because field/helper names and one secondary constructor caller were not source-quality yet; the 2026-06-22 B014 entry supersedes that blocker with current code-entry policy.

- 2026-06-12 A004 Goal 2 parent-gate refresh:
  - Before: `COMPLETION:80`, `CONFIDENCE:84`; the class referenced the old 80/80 gate and left the second constructor caller as an unresolved blocker.
  - Changed to: `COMPLETION:85`, `CONFIDENCE:86`; retained [UID:0000MK][PhotoPane](by-file/PhotoPane.md) as direct file parent after that file reached `86/85`.
  - Evidence: live read-only IDA MCP reconfirmed the raw cleanup child [UID:0002R8][0x00549920-0x00549950.PhotoPaneCleanupDestructorBodyRaw](by-memory/0x00549920-0x00549950.PhotoPaneCleanupDestructorBodyRaw.md), scalar destructor parity, and the exact constructor caller set. The former `0x005143c0` caveat now has behavior: it reads photo payload fields, allocates `0x198` bytes, and calls the constructor at `0x00514461`. Final C++ stayed blank under the then-current final-code caveat; B014 now narrows the blocker to exact child-page emission and final avatar-descriptor spelling.
- 2026-06-22 B014 Rule 26 source-quality incorporation:
  - Before: `COMPLETION:85`, `CONFIDENCE:86`, with constructor names, cached member name, and helper roles still described as provisional blockers.
  - After: `COMPLETION:86`, `CONFIDENCE:88`.
  - Summary/evidence: B014 reanalysis resolves the first-draft constructor signature, `m_snapshotPort` role, opcode `0x5a`/`PhotoPaneFactoryHelper` construction route, service dependencies, and aggregate/method-body emission policy. Residual uncertainty is limited to exact shared avatar-descriptor field spelling and final source-file split.
- 2026-06-25 B005 implementation of accepted [UID:0002R8][0x00549920-0x00549950.PhotoPaneCleanupDestructorBodyRaw](by-memory/0x00549920-0x00549950.PhotoPaneCleanupDestructorBodyRaw.md) report:
  - [UID:0002R8][0x00549920-0x00549950.PhotoPaneCleanupDestructorBodyRaw](by-memory/0x00549920-0x00549950.PhotoPaneCleanupDestructorBodyRaw.md) is now documented as retained destructor cleanup/unwind generated-binary evidence with a formal comment-only marker.
  - Replaced the old generic cleanup shorthand for `sub_4B8D20` with embedded `GrafPort`/`m_snapshotPort` cleanup at `this+0xf8`.
  - Preserved the class-page C++ block as blank; class declarations and exact method bodies remain separate future work, while [UID:0002R8][0x00549920-0x00549950.PhotoPaneCleanupDestructorBodyRaw](by-memory/0x00549920-0x00549950.PhotoPaneCleanupDestructorBodyRaw.md) owns only the comment marker for its raw non-function range.
- 2026-07-15 B004 UID0001F3 source-graph closure:
  - Before: `86/88`, blank class block, and exact constructor/paint emission deferred.
  - After: `92/93`, emitter position 20, complete class declaration closed before `[[CHILDREN]]`, UID0004RJ constructor and UID0004RK OnPaint definitions, and source-clean `GrafPort m_snapshotPort` layout.
  - The class intentionally declares no explicit destructor. UID0002R8 remains a comment-only compiler cleanup marker caused by implicit PhotoPane destruction, `m_snapshotPort`, and the PictureViewPane base; adjacent UID0004RM is the PictureViewPane ordinary destructor.
- 2026-07-26 Agent-B001 UID0003OU source-quality callback:
  - Before: `92/93`; the class had source-clean declaration/method ownership but did not carry the exact corrected RTTI boundary, complete 18/11/2 slot source causes, seven-base hierarchy, lifecycle-store triads, no-OnActivate proof, or full rejected compiler-lowering alternatives.
  - Changed to: `94/95` with the complete vtable/RTTI/destructor source-cause record and links to corrected UID0003OU/UID000265. The formal class declaration remains unchanged because it already expresses the strongest source-faithful cause.
  - Evidence: live IDA MCP session `f085b224`, exact target bytes/hash, three COLs and PMDs, 31 callable cells, class UDT size/layout, constructor/raw-cleanup/scalar-wrapper stores, and the source module's existing constructor/OnPaint children.
