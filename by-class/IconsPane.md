*** UID:00006B | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:82 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:80 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# IconsPane

## Status

- Confidence: strong for behavior and core range, medium for final grouping with `TabPane`.
- Current generated file: `class_IconsPane.cpp`
- Likely source module: [UID:0000JZ][IconsPane](by-file/IconsPane.md)
- Core range: [UID:00016Z][0x004cf1f0-0x004cf8d5.IconsPaneCore](by-memory/0x004cf1f0-0x004cf8d5.IconsPaneCore.md)
- Raw action-dispatch candidate: [UID:00022Q][0x004cf8e0-0x004cf975.IconsPaneActionDispatchRawBody](by-memory/0x004cf8e0-0x004cf975.IconsPaneActionDispatchRawBody.md)
- Shared destructor tail: [UID:000170][0x004cf980-0x004cfe5f.TabPaneAndIconsPaneDestructorTail](by-memory/0x004cf980-0x004cfe5f.TabPaneAndIconsPaneDestructorTail.md)
- Singleton global: [UID:0000R6][g_pIconsPane](by-global/g_pIconsPane.md)
- Resource doc: [UID:0001RD][iconspane-icon-resources](by-resource/iconspane-icon-resources.md)
- Evidence basis: `simroot_v2`, Wave2 report notes, and IDA MCP checks on 2026-05-24.

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

| Address | Current name | Notes |
| --- | --- | --- |
| `0x004cf1f0-0x004cf25d` | constructor | Registers singleton, reads config byte `+0x28de32`, initializes show/selected/pressed state. |
| `0x004cf260-0x004cf289` | cleanup helper | Reinstalls vtables, clears singleton, calls shared pane cleanup. Current active output emits it as `IconsPane::Cleanup`. |
| `0x004cf290-0x004cf297` | `IsShowingAllIcons` | Returns `showAllIcons`. |
| `0x004cf2a0-0x004cf2c6` | `ShowAllIcons` | Sets config byte `+0x28de32` to `0`, flips `showAllIcons`, invalidates bounds. |
| `0x004cf2d0-0x004cf2f6` | `ShowReducedIcons` | Sets config byte `+0x28de32` to `1`, clears `showAllIcons`, invalidates bounds. |
| `0x004cf300-0x004cf3d3` | `OnPaint` | Draws `ICONS.EPD` frames through `NPAL7.PAL`; pressed icon uses frame `index + 8`. |
| `0x004cf3e0-0x004cf74b` | `OnMouseEvent` | Handles capture, pressed state, click actions, and tooltips. |
| `0x004cf7d0-0x004cf862` | `HitTestIcon` | Converts coordinates to icon index; reduced mode starts at icon `6`. |
| `0x004cf870-0x004cf8d5` | `SetIconHighlight` | Invalidates the selected icon rectangle when highlight state changes. |
| `0x004cf8e0-0x004cf975` | raw action dispatch candidate | Function-shaped duplicate/candidate of the click-action switch, with local jump table and no IDA function object/direct external xrefs. |
| `0x004cfd6c-0x004cfd81` | adjustor thunks | Subtract `0xa0`/`0xa4` and forward to scalar deleting destructor. |
| `0x004cfda0-0x004cfdff` | scalar deleting destructor | Clears singleton, calls shared pane cleanup, optionally frees `this` unless `flags & 4` is set. |

## External State

- [UID:0000R6][g_pIconsPane](by-global/g_pIconsPane.md) at `0x0069b41c`.
- `g_pConfig` / `dword_67A7C8`; persisted icon visibility byte at offset `0x28de32`.
- `g_pEPFLib` / `dword_67A744`; resource manager for `ICONS.EPD`.
- `g_pLanguageMan` / `dword_67A750`; localized tooltip ids `202..209`.
- `g_isInputLocked` at `dword_67A764 + 1008`; click dispatch is skipped while input is locked.
- `g_pAppMan` / `dword_67A748`; passed to selected action helpers.

## Open Questions

- Name each of the eight click actions from the helper callees at `0x005a4db0`, `0x005a4e40`, `0x005a4f70`, `0x005a5010`, `0x005a50a0`, `0x005a5110`, `0x005a5340`, and `0x005a5a80`.
- Decide whether [UID:00022Q][0x004cf8e0-0x004cf975.IconsPaneActionDispatchRawBody](by-memory/0x004cf8e0-0x004cf975.IconsPaneActionDispatchRawBody.md) is live unmodeled code or an unreferenced duplicate emitted near the icon-pane class block.
- Decide whether original source kept `IconsPane` and [UID:0000EB][TabPane](by-class/TabPane.md) in separate `.cpp` files or a single old-HUD controls file. Current evidence supports separate class docs but adjacent file placement.

## Cross-References

- [UID:0000JZ][IconsPane](by-file/IconsPane.md)
- [UID:00016Z][0x004cf1f0-0x004cf8d5.IconsPaneCore](by-memory/0x004cf1f0-0x004cf8d5.IconsPaneCore.md)
- [UID:00022Q][0x004cf8e0-0x004cf975.IconsPaneActionDispatchRawBody](by-memory/0x004cf8e0-0x004cf975.IconsPaneActionDispatchRawBody.md)
- [UID:000170][0x004cf980-0x004cfe5f.TabPaneAndIconsPaneDestructorTail](by-memory/0x004cf980-0x004cfe5f.TabPaneAndIconsPaneDestructorTail.md)
- [UID:0000R6][g_pIconsPane](by-global/g_pIconsPane.md)
- [UID:0001RD][iconspane-icon-resources](by-resource/iconspane-icon-resources.md)
- [UID:0000EB][TabPane](by-class/TabPane.md)

## Changes

- Completion/confidence score update: existed before as `0/0`; changed to `82/80`. Summary: old-layout icon-strip behavior, layout offsets, vtables, methods, singleton, resource use, persisted config byte, click action state, raw dispatch caveat, and TabPane grouping question are documented; confidence is capped by unresolved live status of the raw action-dispatch body and final source grouping. Evidence: `IconsPaneCore`, `IconsPaneActionDispatchRawBody`, `TabPaneAndIconsPaneDestructorTail`, `g_pIconsPane`, and `iconspane-icon-resources`.
- 2026-05-30: Corrected active-output status for the cleanup helper.
  - Before: The method table described the `0x004cf260-0x004cf289` cleanup helper as omitted from active generated output.
  - After: The method table records that current active `class_IconsPane.cpp` emits the helper as `IconsPane::Cleanup`.
  - Evidence: Current `simroot_v2/class_IconsPane.cpp` contains `NTK_ScopedInstall(Cleanup, 0x004cf260)` and `void IconsPane::Cleanup()`.
