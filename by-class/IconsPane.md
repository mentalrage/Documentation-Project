*** UID:00006B | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:85 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:85 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000JZ | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# IconsPane

## Status

- Confidence: strong for behavior, core range, exact destructor ownership, and file ownership; medium-high for final grouping with `TabPane`.
- Current generated file: `class_IconsPane.cpp`
- Likely source module: [UID:0000JZ][IconsPane](by-file/IconsPane.md)
- Core range: [UID:00016Z][0x004cf1f0-0x004cf8d5.IconsPaneCore](by-memory/0x004cf1f0-0x004cf8d5.IconsPaneCore.md)
- Raw action-dispatch candidate: [UID:00022Q][0x004cf8e0-0x004cf974.IconsPaneActionDispatchRawBody](by-memory/0x004cf8e0-0x004cf974.IconsPaneActionDispatchRawBody.md)
- Split destructor tail inventory: [UID:000170][0x004cf980-0x004cfe5f.TabPaneAndIconsPaneDestructorTail](by-memory/0x004cf980-0x004cfe5f.TabPaneAndIconsPaneDestructorTail.md)
- Singleton global: [UID:0000R6][g_pIconsPane](by-global/g_pIconsPane.md)
- Resource doc: [UID:0001RD][iconspane-icon-resources](by-resource/iconspane-icon-resources.md)
- Evidence basis: IDA MCP checks, current generated source, and linked exact memory pages.

## Responsibility

`IconsPane` is the old-layout icon-strip HUD pane. It paints a row of icon buttons, switches between full and reduced visibility, tracks click/pressed state, shows localized tooltips, and dispatches the corresponding game UI actions.

## Layout Evidence

- Constructor writes vtables at object offsets `0x0`, `0xa0`, and `0xa4`.
- `showAllIcons` lives at object offset `0xf8`.
- `selectedIconIndex` lives at object offset `0xfc`.
- `isPressed` / highlight state lives at object offset `0x100`.
- Icon rectangles are fixed at 20-pixel horizontal slots, `0..19`, `20..39`, and so on up to `159`, with height `14`.
- Vtable addresses observed by IDA: `0x0061b448`, `0x0061b494`, and `0x0061b4c4`.

## Important Methods

| Range doc | Current name | Notes |
| --- | --- | --- |
| [UID:0002SW][0x004cf1f0-0x004cf25d.IconsPaneConstructor](by-memory/0x004cf1f0-0x004cf25d.IconsPaneConstructor.md) | constructor | Registers singleton, reads config byte `+0x28de32`, initializes show/selected/pressed state. |
| [UID:0002SX][0x004cf260-0x004cf289.IconsPaneCleanupHelper](by-memory/0x004cf260-0x004cf289.IconsPaneCleanupHelper.md) | cleanup helper | Reinstalls vtables, clears singleton, calls shared pane cleanup. Current active output emits it as `IconsPane::Cleanup`. |
| [UID:0002SY][0x004cf290-0x004cf297.IconsPaneIsShowingAllIcons](by-memory/0x004cf290-0x004cf297.IconsPaneIsShowingAllIcons.md) | `IsShowingAllIcons` | Returns `showAllIcons`. |
| [UID:0002SZ][0x004cf2a0-0x004cf2c6.IconsPaneShowAllIcons](by-memory/0x004cf2a0-0x004cf2c6.IconsPaneShowAllIcons.md) | `ShowAllIcons` | Sets config byte `+0x28de32` to `0`, flips `showAllIcons`, invalidates bounds. |
| [UID:0002T0][0x004cf2d0-0x004cf2f6.IconsPaneShowReducedIcons](by-memory/0x004cf2d0-0x004cf2f6.IconsPaneShowReducedIcons.md) | `ShowReducedIcons` | Sets config byte `+0x28de32` to `1`, clears `showAllIcons`, invalidates bounds. |
| [UID:0002T1][0x004cf300-0x004cf3d3.IconsPaneOnPaint](by-memory/0x004cf300-0x004cf3d3.IconsPaneOnPaint.md) | `OnPaint` | Draws `ICONS.EPD` frames through `NPAL7.PAL`; pressed icon uses frame `index + 8`. |
| [UID:0002T2][0x004cf3e0-0x004cf74b.IconsPaneOnMouseEvent](by-memory/0x004cf3e0-0x004cf74b.IconsPaneOnMouseEvent.md) | `OnMouseEvent` | Handles capture, pressed state, click actions, and tooltips. |
| [UID:0002T3][0x004cf7d0-0x004cf862.IconsPaneHitTestIcon](by-memory/0x004cf7d0-0x004cf862.IconsPaneHitTestIcon.md) | `HitTestIcon` | Converts coordinates to icon index; reduced mode starts at icon `6`. |
| [UID:0002T4][0x004cf870-0x004cf8d5.IconsPaneSetIconHighlight](by-memory/0x004cf870-0x004cf8d5.IconsPaneSetIconHighlight.md) | `SetIconHighlight` | Invalidates the selected icon rectangle when highlight state changes. |
| `0x004cf8e0-0x004cf974` | raw action dispatch candidate | Function-shaped duplicate/candidate of the click-action switch, with local jump table and no IDA function object/direct external xrefs. |
| [UID:00034T][0x004cfd6c-0x004cfd82.IconsPaneDestructorAdjustorThunks](by-memory/0x004cfd6c-0x004cfd82.IconsPaneDestructorAdjustorThunks.md) | adjustor thunks | Compiler-generated `this - 0xa0`/`this - 0xa4` forwards to the scalar deleting destructor; non-reconstructable and parent-blank. |
| [UID:00034V][0x004cfda0-0x004cfdff.IconsPaneScalarDeletingDestructor](by-memory/0x004cfda0-0x004cfdff.IconsPaneScalarDeletingDestructor.md) | scalar deleting destructor | Clears singleton, calls shared pane cleanup, optionally frees `this` unless `flags & 4` is set. |

## External State

- [UID:0000R6][g_pIconsPane](by-global/g_pIconsPane.md) at `0x0069b41c`.
- `g_pConfig` / `dword_67A7C8`; persisted icon visibility byte at offset `0x28de32`.
- `g_pEPFLib` / `dword_67A744`; resource manager for `ICONS.EPD`.
- `g_pLanguageMan` / `dword_67A750`; localized tooltip ids `202..209`.
- `g_isInputLocked` at `dword_67A764 + 1008`; click dispatch is skipped while input is locked.
- [UID:0000QK][g_pCollectionData](by-global/g_pCollectionData.md) / historical `dword_67A748` (older generated `g_pAppMan` label); passed to selected action helpers.

## Open Questions

- Name each of the eight click actions from the helper callees at `0x005a4db0`, `0x005a4e40`, `0x005a4f70`, `0x005a5010`, `0x005a50a0`, `0x005a5110`, `0x005a5340`, and `0x005a5a80`.
- Decide whether [UID:00022Q][0x004cf8e0-0x004cf974.IconsPaneActionDispatchRawBody](by-memory/0x004cf8e0-0x004cf974.IconsPaneActionDispatchRawBody.md) is live unmodeled code or an unreferenced duplicate emitted near the icon-pane class block.
- Decide whether original source kept `IconsPane` and [UID:0000EB][TabPane](by-class/TabPane.md) in separate `.cpp` files or a single old-HUD controls file. The 2026-06-10 split resolved the destructor-tail ownership; source grouping remains open.

## Autogen Status

- Reconstructable: true, as an old-layout HUD panel class with IDA-backed constructor, methods, singleton, resources, and exact destructor evidence.
- Parent: [UID:0000JZ][IconsPane](by-file/IconsPane.md).
- C++: intentionally blank because helper naming, the raw dispatch body, and final grouping with `TabPane` are not final-audit quality.

## Cross-References

- [UID:0000JZ][IconsPane](by-file/IconsPane.md)
- [UID:00016Z][0x004cf1f0-0x004cf8d5.IconsPaneCore](by-memory/0x004cf1f0-0x004cf8d5.IconsPaneCore.md)
- [UID:00022Q][0x004cf8e0-0x004cf974.IconsPaneActionDispatchRawBody](by-memory/0x004cf8e0-0x004cf974.IconsPaneActionDispatchRawBody.md)
- [UID:000170][0x004cf980-0x004cfe5f.TabPaneAndIconsPaneDestructorTail](by-memory/0x004cf980-0x004cfe5f.TabPaneAndIconsPaneDestructorTail.md)
- [UID:00034T][0x004cfd6c-0x004cfd82.IconsPaneDestructorAdjustorThunks](by-memory/0x004cfd6c-0x004cfd82.IconsPaneDestructorAdjustorThunks.md)
- [UID:00034V][0x004cfda0-0x004cfdff.IconsPaneScalarDeletingDestructor](by-memory/0x004cfda0-0x004cfdff.IconsPaneScalarDeletingDestructor.md)
- [UID:0000R6][g_pIconsPane](by-global/g_pIconsPane.md)
- [UID:0001RD][iconspane-icon-resources](by-resource/iconspane-icon-resources.md)
- [UID:0000EB][TabPane](by-class/TabPane.md)
- [UID:0002SW][0x004cf1f0-0x004cf25d.IconsPaneConstructor](by-memory/0x004cf1f0-0x004cf25d.IconsPaneConstructor.md)
- [UID:0002SX][0x004cf260-0x004cf289.IconsPaneCleanupHelper](by-memory/0x004cf260-0x004cf289.IconsPaneCleanupHelper.md)
- [UID:0002SY][0x004cf290-0x004cf297.IconsPaneIsShowingAllIcons](by-memory/0x004cf290-0x004cf297.IconsPaneIsShowingAllIcons.md)
- [UID:0002SZ][0x004cf2a0-0x004cf2c6.IconsPaneShowAllIcons](by-memory/0x004cf2a0-0x004cf2c6.IconsPaneShowAllIcons.md)
- [UID:0002T0][0x004cf2d0-0x004cf2f6.IconsPaneShowReducedIcons](by-memory/0x004cf2d0-0x004cf2f6.IconsPaneShowReducedIcons.md)
- [UID:0002T1][0x004cf300-0x004cf3d3.IconsPaneOnPaint](by-memory/0x004cf300-0x004cf3d3.IconsPaneOnPaint.md)
- [UID:0002T2][0x004cf3e0-0x004cf74b.IconsPaneOnMouseEvent](by-memory/0x004cf3e0-0x004cf74b.IconsPaneOnMouseEvent.md)
- [UID:0002T3][0x004cf7d0-0x004cf862.IconsPaneHitTestIcon](by-memory/0x004cf7d0-0x004cf862.IconsPaneHitTestIcon.md)
- [UID:0002T4][0x004cf870-0x004cf8d5.IconsPaneSetIconHighlight](by-memory/0x004cf870-0x004cf8d5.IconsPaneSetIconHighlight.md)
- [UID:0000QK][g_pCollectionData](by-global/g_pCollectionData.md)

## Changes

- 2026-06-10 B001-034 split repair:
  - Before: class confidence remained `82/82`, and destructor glue was only listed as bare ranges inside the mixed [UID:000170][0x004cf980-0x004cfe5f.TabPaneAndIconsPaneDestructorTail](by-memory/0x004cf980-0x004cfe5f.TabPaneAndIconsPaneDestructorTail.md) page.
  - Changed to: completion/confidence `85/85`; the method inventory now links exact destructor thunk and scalar deleting destructor children [UID:00034T][0x004cfd6c-0x004cfd82.IconsPaneDestructorAdjustorThunks](by-memory/0x004cfd6c-0x004cfd82.IconsPaneDestructorAdjustorThunks.md) and [UID:00034V][0x004cfda0-0x004cfdff.IconsPaneScalarDeletingDestructor](by-memory/0x004cfda0-0x004cfdff.IconsPaneScalarDeletingDestructor.md).
  - Evidence: IDA MCP confirmed `IconsPane` vtables at `0x0061b448`, `0x0061b494`, and `0x0061b4c4`; `g_pIconsPane` writes/clears at `0x004cf215`, `0x004cf27a`, and `0x004cfdc0`; adjustor thunks at `0x004cfd6c` and `0x004cfd77`; and scalar deleting destructor body `0x004cfda0-0x004cfdff`.
- 2026-06-07 A005 resolved-name cleanup:
  - Before: click-action state evidence used historical `dword_67A748` and the older generated `g_pAppMan` label.
  - After: the page records canonical `g_pCollectionData` beside the historical label and cross-links the global page.
  - Evidence: generated resolved-name report maps `dword_67A748` to `g_pCollectionData`; existing IconsPane action-dispatch evidence already ties the reference to selected client/player action helpers.
- Completion/confidence score update: existed before as `0/0`; changed to `82/80`. Summary: old-layout icon-strip behavior, layout offsets, vtables, methods, singleton, resource use, persisted config byte, click action state, raw dispatch caveat, and TabPane grouping question are documented; confidence is capped by unresolved live status of the raw action-dispatch body and final source grouping. Evidence: `IconsPaneCore`, `IconsPaneActionDispatchRawBody`, `TabPaneAndIconsPaneDestructorTail`, `g_pIconsPane`, and `iconspane-icon-resources`.
- 2026-05-30: Corrected active-output status for the cleanup helper.
  - Before: The method table described the `0x004cf260-0x004cf289` cleanup helper as omitted from active generated output.
  - After: The method table records that current active `class_IconsPane.cpp` emits the helper as `IconsPane::Cleanup`.
  - Evidence: Current `simroot_v2/class_IconsPane.cpp` contains `NTK_ScopedInstall(Cleanup, 0x004cf260)` and `void IconsPane::Cleanup()`.
- 2026-06-02 autogen attachment:
  - What existed before: the class was scored `82/80` with no reconstructable flag or parent attachment.
  - Changed to: confidence `82`, `RECONSTRUCTABLE:TRUE`, and `AUTOGEN_PARENT_UID:0000JZ`.
  - Summary/evidence: the file parent now has a validated `NexusTK/ui/panels/` projected path; reconstructed C++ remains blank under the 95+ gate.
- 2026-06-03 exact memory split:
  - What existed before: the important-method table listed bare addresses under the broad [UID:00016Z][0x004cf1f0-0x004cf8d5.IconsPaneCore](by-memory/0x004cf1f0-0x004cf8d5.IconsPaneCore.md) aggregate.
  - Changed to: the table now links exact child pages [UID:0002SW][0x004cf1f0-0x004cf25d.IconsPaneConstructor](by-memory/0x004cf1f0-0x004cf25d.IconsPaneConstructor.md) through [UID:0002T4][0x004cf870-0x004cf8d5.IconsPaneSetIconHighlight](by-memory/0x004cf870-0x004cf8d5.IconsPaneSetIconHighlight.md) for constructor, cleanup, state, paint, mouse, hit-test, and highlight helpers.
  - Summary/evidence: the child pages are reconstructable source-owned `IconsPane` methods/helpers with blank C++ under the 95+ gate.
