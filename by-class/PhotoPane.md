*** UID:0000AG | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:80 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:78 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# PhotoPane

## Status

- Confidence: strong for class behavior, medium for final field names.
- Likely source file: [UID:0000MK][PhotoPane](by-file/PhotoPane.md)
- Main address range: `0x00549620-0x00549afe`
- Current recovered file: `source-3/simroot_v2/class_PhotoPane.cpp`

## Class Purpose

`PhotoPane` is a `PictureViewPane`-derived map snapshot pane. It builds an off-screen `GrafPort` from a `C%04d.MAP` resource, renders a small terrain/static-object map region plus an avatar, and paints by copying the cached image to the visible pane.

## Method Families

| Range | Function | Role |
| --- | --- | --- |
| `0x00549620-0x00549911` | constructor | Initialize the base/viewer pane, allocate and clip the cached `GrafPort`, load the map DAT entry, render the terrain/object/avatar snapshot, and close temporary resources. |
| `0x00549920-0x00549950` | raw cleanup destructor body | Non-IDA-modeled body; writes `PhotoPane` vtables, destroys the embedded cached surface at `this + 0xf8`, then tail-jumps to the non-deleting destructor; see [UID:0002R8][0x00549920-0x00549950.PhotoPaneCleanupDestructorBodyRaw](by-memory/0x00549920-0x00549950.PhotoPaneCleanupDestructorBodyRaw.md). |
| `0x00549950-0x005499a2` | `OnPaint` | Get cached surface bounds and blit the off-screen photo surface into the pane. |
| `0x005499a2-0x005499b8` | adjustor thunks | Vtable glue for secondary class views. |
| `0x005499c0-0x00549a22` | scalar deleting destructor | Destroy the embedded `GrafPort`, chain to the non-deleting destructor, and optionally free storage. |
| `0x00549ae0-0x00549aff` | non-deleting destructor | Reset to `PictureViewPane` vtables and chain to pane teardown. |

## Layout Notes

- The generated source places the cached `GrafPort` at roughly `PhotoPane + 0xf8`.
- The constructor uses tile dimensions from the global tile-size state and draws a 17 by 15 visible tile snapshot.
- Static objects are drawn through [UID:0000E2][StaticObjImageLib](by-class/StaticObjImageLib.md), and the avatar bounds/draw path uses [UID:000092][NewHumanImageLib](by-class/NewHumanImageLib.md).

## Evidence Notes

- IDA MCP confirms the constructor, paint method, scalar deleting destructor, and non-deleting destructor as real functions in the `0x00549620-0x00549afe` cluster.
- IDA MCP 2026-06-01 also confirms raw executable cleanup code at `0x00549920-0x00549950`; IDA does not model it as a function, but its vtable writes and `this + 0xf8` cleanup identify it as `PhotoPane` destructor-family behavior.
- `MapPane::HandlePacket` calls the constructor, so this class should be documented as map-feature UI rather than a generic image control.
- The paint method is intentionally simple because the expensive snapshot composition happens in the constructor.

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

## Changes

- Before: the containing `PhotoAndPicturePanes` memory page ended at `0x00549bc4`.
- Changed to: the page ends at `0x00549bc5`.
- Summary/evidence: 2026-05-28 IDA MCP byte/function review shows the final byte at `0x00549bc4` belongs to `PictureViewPane::ScalarDeletingDestructor`.
- Before: the method table omitted the raw cleanup destructor body at `0x00549920-0x00549950`.
- Changed to: the raw body is now listed in the method family and linked to [UID:0002R8][0x00549920-0x00549950.PhotoPaneCleanupDestructorBodyRaw](by-memory/0x00549920-0x00549950.PhotoPaneCleanupDestructorBodyRaw.md).
- Evidence: 2026-06-01 IDA MCP disassembly shows this unmodeled body installs `PhotoPane` vtables, calls the cached surface destructor at `this + 0xf8`, and tail-jumps to `0x00549ae0`.
- Before: completion/confidence metadata were `0/0` despite detailed constructor, paint, destructor, map snapshot, resource, and caller documentation.
- Changed to: `COMPLETION:80` and `CONFIDENCE:78`.
- Evidence: off-screen `GrafPort`, map DAT loading, terrain/object/avatar rendering, cached blit paint path, destructor family, `MapPane` caller, and resource/library dependencies are documented; confidence remains medium-high because final field names and exact source-level layout remain open.
