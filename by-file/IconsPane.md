*** UID:0000JZ | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:80 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***

# IconsPane

## Status

- Confidence: strong for class role and core range, medium for final source grouping with `TabPane`.
- Proposed module: `ui/panels/IconsPane.cpp`
- Current generated source: `class_IconsPane.cpp`
- Main class: [UID:00006B][IconsPane](by-class/IconsPane.md)
- Core address doc: [UID:00016Z][0x004cf1f0-0x004cf8d5.IconsPaneCore](by-memory/0x004cf1f0-0x004cf8d5.IconsPaneCore.md)
- Raw action-dispatch candidate: [UID:00022Q][0x004cf8e0-0x004cf975.IconsPaneActionDispatchRawBody](by-memory/0x004cf8e0-0x004cf975.IconsPaneActionDispatchRawBody.md)
- Shared tail doc: [UID:000170][0x004cf980-0x004cfe5f.TabPaneAndIconsPaneDestructorTail](by-memory/0x004cf980-0x004cfe5f.TabPaneAndIconsPaneDestructorTail.md)
- Singleton global: [UID:0000R6][g_pIconsPane](by-global/g_pIconsPane.md)
- Resource doc: [UID:0001RD][iconspane-icon-resources](by-resource/iconspane-icon-resources.md)
- Evidence basis: `simroot_v2`, Wave2 report notes, and IDA MCP decompilation/function/caller/xref checks on 2026-05-24.

## File Role

`IconsPane.cpp` owns the old-layout bottom icon strip: icon visibility mode, icon hit testing, pressed/highlight invalidation, painting `ICONS.EPD`, localized hover tooltips, and click dispatch into inventory/options/exchange/mail/community/help/quest actions.

This should stay in `ui/panels/`, likely adjacent to [UID:0000OF][TabPane](by-file/TabPane.md). `TabPane` is nearby and shares some action helpers, but it owns a different input surface with six horizontal tab regions rather than the eight-icon strip.

## Proposed Contents

| Entity | Address evidence | Role |
| --- | --- | --- |
| `IconsPane` core | `0x004cf1f0-0x004cf8d5` | Constructor, cleanup helper, show-all/reduced state methods, paint, mouse handling, hit test, pressed-state invalidation. |
| `IconsPane` raw action dispatch candidate | `0x004cf8e0-0x004cf975` | Function-shaped duplicate/candidate of the click-action switch, with local jump table and no IDA function object/direct external xrefs. |
| `IconsPane` destructor glue | `0x004cfd6c-0x004cfd81`, `0x004cfda0-0x004cfdff` | Adjustor thunks and scalar deleting destructor interleaved after `TabPane` core code. |
| `g_pIconsPane` | `0x0069b41c` | Singleton pointer registered by constructor, cleared by cleanup/destructor paths, and read during main UI shutdown plus option UI paths. |
| Vtable set | `0x0061b448`, `0x0061b494`, `0x0061b4c4` | Main and adjustor vtables installed at object offsets `0x0`, `0xa0`, and `0xa4`. |

## Behavior Notes

- The constructor at `0x004cf1f0` calls `Pane::Pane(..., 1)`, writes [UID:0000R6][g_pIconsPane](by-global/g_pIconsPane.md), installs three `IconsPane` vtables, derives `showAllIcons` from config byte `g_pConfig + 0x28de32`, initializes selected icon to `-1`, and clears the pressed flag.
- `IsShowingAllIcons`, `ShowAllIcons`, and `ShowReducedIcons` at `0x004cf290`, `0x004cf2a0`, and `0x004cf2d0` expose and persist the full/reduced icon-strip mode.
- `OnPaint` at `0x004cf300` clears the pane, starts at icon index `0` for full mode or `6` for reduced mode, and draws 20-pixel-wide frames from `ICONS.EPD` with `NPAL7.PAL`.
- `OnMouseEvent` at `0x004cf3e0` handles move/down/up/hover events, captures and releases mouse input, uses the local hit-test helper, creates `SimpleHelpPane` tooltips with localized ids `202..209`, and dispatches click actions when input is not locked.
- `HitTestIcon` at `0x004cf7d0` maps coordinates to icon indexes. Reduced mode starts at index `6`, so only icons `6` and `7` are visible.
- `SetIconHighlight` at `0x004cf870` invalidates the selected icon rectangle when pressed/highlight state changes.

## Data Caveats

Current active generated output now emits the cleanup helper at `0x004cf260`, hit-test helper at `0x004cf7d0`, highlight helper at `0x004cf870`, and scalar deleting destructor at `0x004cfda0` with the `flags & 4` no-delete guard. It still does not emit the adjacent raw action-dispatch candidate at `0x004cf8e0` as a modeled helper, and the destructor adjustor thunks at `0x004cfd6c` and `0x004cfd77` remain compiler glue documented in the shared tail page rather than normal source methods.

The `IconsPane` destructor glue is physically interleaved with [UID:0000OF][TabPane](by-file/TabPane.md) destructor glue. Use the memory docs before attempting source migration.

## Cross-References

- [UID:00006B][IconsPane](by-class/IconsPane.md)
- [UID:00016Z][0x004cf1f0-0x004cf8d5.IconsPaneCore](by-memory/0x004cf1f0-0x004cf8d5.IconsPaneCore.md)
- [UID:00022Q][0x004cf8e0-0x004cf975.IconsPaneActionDispatchRawBody](by-memory/0x004cf8e0-0x004cf975.IconsPaneActionDispatchRawBody.md)
- [UID:000170][0x004cf980-0x004cfe5f.TabPaneAndIconsPaneDestructorTail](by-memory/0x004cf980-0x004cfe5f.TabPaneAndIconsPaneDestructorTail.md)
- [UID:0000R6][g_pIconsPane](by-global/g_pIconsPane.md)
- [UID:0001RD][iconspane-icon-resources](by-resource/iconspane-icon-resources.md)
- [UID:0000OF][TabPane](by-file/TabPane.md)
- [UID:0000M7][OptionPane](by-file/OptionPane.md)

## Changes

- 2026-05-30 completion/confidence scoring:
  - What existed before: `COMPLETION:0` and `CONFIDENCE:0`.
  - Changed to: `COMPLETION:86` and `CONFIDENCE:80`.
  - Summary/evidence: old-layout icon strip behavior, singleton/vtable anchors, action dispatch candidate, destructor glue, resource docs, and `TabPane` boundary are documented; confidence is capped by the raw action-dispatch body and final source grouping with `TabPane`.
- 2026-05-30 active-output caveat correction:
  - What existed before: The data caveat said active output omitted cleanup, hit-test, highlight, destructor adjustor, and destructor guard details.
  - Changed to: The caveat now records current active emission of cleanup/hit-test/highlight/scalar deleting destructor and narrows the remaining active-output issue to the raw action-dispatch candidate plus compiler-generated adjustor thunk handling.
  - Summary/evidence: Current `simroot_v2/class_IconsPane.cpp` contains scoped installs for `0x004cf260`, `0x004cf7d0`, `0x004cf870`, and `0x004cfda0`, and the destructor body contains `(flags & 4) == 0`.
