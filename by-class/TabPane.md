*** UID:0000EB | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:82 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:76 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# TabPane

## Status

- Confidence: strong for local behavior and range, medium for final source grouping.
- Current generated file: `class_TabPane.cpp`
- Likely source module: [UID:0000OF][TabPane](by-file/TabPane.md)
- Main range: [UID:000170][0x004cf980-0x004cfe5f.TabPaneAndIconsPaneDestructorTail](by-memory/0x004cf980-0x004cfe5f.TabPaneAndIconsPaneDestructorTail.md)
- Singleton global: [UID:0000SE][g_pTabPane](by-global/g_pTabPane.md)
- Evidence basis: `simroot_v2`, Wave2 report notes, and IDA MCP checks on 2026-05-24.

## Responsibility

`TabPane` is an old-layout tab/action input pane. It maps mouse coordinates to a small set of tab action codes and dispatches those actions through the same broader UI helper family used by [UID:00006B][IconsPane](by-class/IconsPane.md), [UID:0000FQ][UserPane](by-class/UserPane.md), and related shortcuts.

## Layout Evidence

- Constructor writes vtables at object offsets `0x0`, `0xa0`, and `0xa4`.
- The singleton is stored from an owner pointer adjusted from `this + 0xf8`, matching the surrounding pane-constructor pattern.
- The input handler receives an event-like object with event mode at `+0x4`, x/y at `+0x8`/`+0xc`, and an additional argument at `+0x10c`.
- Vtable addresses observed by IDA: `0x0061b4d0`, `0x0061b51c`, and `0x0061b54c`.

## Important Methods

| Address | Current name | Notes |
| --- | --- | --- |
| `0x004cf980-0x004cf9ca` | constructor | Registers singleton and installs vtables. |
| `0x004cf9d0-0x004cf9f9` | cleanup helper | Reinstalls vtables, clears singleton, calls shared pane cleanup. Omitted from active generated output. |
| `0x004cfa00-0x004cfa01` | null virtual | Empty virtual slot. Disabled output emits it. |
| `0x004cfa10-0x004cfb0a` | `HandleInputEvent` | Dispatches tab action codes for event modes `1` and `2`. |
| `0x004cfb10-0x004cfb15` | `CanHandleInputEvent` | Returns false. |
| `0x004cfc60-0x004cfd4d` | `ResolveTabActionCode` | Hit-tests six fixed rectangles. Omitted from active generated output. |
| `0x004cfd82-0x004cfd8d` | adjustor thunk | Subtracts `0xa0`, forwards to `0x004cfe00`. |
| `0x004cfd8d-0x004cfd98` | adjustor thunk | Subtracts `0xa4`, forwards to `0x004cfe00`. Disabled output says missing code. |
| `0x004cfe00-0x004cfe5f` | scalar deleting destructor | Clears singleton, calls shared pane cleanup, optionally frees `this` unless `flags & 4` is set. |

## External State

- [UID:0000SE][g_pTabPane](by-global/g_pTabPane.md) at `0x0069adfc`.
- `g_pAppMan` / `dword_67A748`; used by input suppression and selected action helpers.
- Action helpers around `0x005a4db0-0x005a4f70`; names remain provisional until the shortcut/action family is reviewed.

## Open Questions

- Name the six tab regions and action codes from UI/resource evidence rather than only helper behavior.
- Decide whether final source keeps `TabPane.cpp` separate or folds it with [UID:0000JZ][IconsPane](by-file/IconsPane.md) into an old-HUD controls module.

## Cross-References

- [UID:0000OF][TabPane](by-file/TabPane.md)
- [UID:000170][0x004cf980-0x004cfe5f.TabPaneAndIconsPaneDestructorTail](by-memory/0x004cf980-0x004cfe5f.TabPaneAndIconsPaneDestructorTail.md)
- [UID:0000SE][g_pTabPane](by-global/g_pTabPane.md)
- [UID:00006B][IconsPane](by-class/IconsPane.md)

## Changes

- Before: completion/confidence were unevaluated at `0/0`.
- Changed to: completion `82`, confidence `76`.
- Evidence: the page documents old-layout tab-pane responsibility, layout/vtable evidence, singleton, method map, external state, and open action-code/source-grouping questions; confidence remains capped by unresolved tab-region names and final grouping with `IconsPane`.
