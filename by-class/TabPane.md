*** UID:0000EB | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000OF | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# TabPane

## Status

- Confidence: strong for local function boundaries, vtable identity, singleton lifecycle, input behavior, and hit-test geometry; medium for final tab labels and final source grouping with `IconsPane`.
- Likely source module: [UID:0000OF][TabPane](by-file/TabPane.md)
- Main range: [UID:000170][0x004cf980-0x004cfe5f.TabPaneAndIconsPaneDestructorTail](by-memory/0x004cf980-0x004cfe5f.TabPaneAndIconsPaneDestructorTail.md)
- Singleton global: [UID:0000SE][g_pTabPane](by-global/g_pTabPane.md)
- Evidence basis: live IDA MCP checks on 2026-06-04 against `NexusTK.exe` MD5 `4247e04e20b65d6414c7238aa8ff5515`.

## Responsibility

`TabPane` is an old-layout tab/action input pane. It maps mouse coordinates to a small set of tab action codes and dispatches those actions through the same broader UI helper family used by [UID:00006B][IconsPane](by-class/IconsPane.md), [UID:0000FQ][UserPane](by-class/UserPane.md), and related shortcuts.

## Layout Evidence

- The constructor calls `0x00544460` at `0x004cf98c`, writes [UID:0000SE][g_pTabPane](by-global/g_pTabPane.md) at `0x004cf9a4`, and writes vtables at object offsets `0x0`, `0xa0`, and `0xa4`.
- The singleton is stored from the owner pointer adjusted from `this + 0xf8`; the live constructor's null fallback only triggers for the impossible `this == -0xf8` arithmetic case.
- The input handler receives an event-like object with event mode at `+0x4`, x/y at `+0x8`/`+0xc`, and an additional argument at `+0x10c`.
- Live IDA names the vtable views as `??_7TabPane@@6B@` at `0x0061b4d0`, `??_7TabPane@@6B@_0` at `0x0061b51c`, and `??_7TabPane@@6B@_1` at `0x0061b54c`.
- Key slots are `0x0061b4d0 -> 0x004cfe00`, `0x0061b514 -> 0x004cfa00`, `0x0061b51c -> 0x004cfd82`, `0x0061b520 -> 0x004cfa10`, `0x0061b524 -> 0x004cfb10`, and `0x0061b54c -> 0x004cfd8d`.

## Important Methods

| Address | Current name | Notes |
| --- | --- | --- |
| `0x004cf980-0x004cf9ca` | constructor | Registers singleton and installs vtables. |
| `0x004cf9d0-0x004cf9f9` | cleanup helper | Reinstalls vtables, clears singleton, then jumps to shared pane cleanup at `0x00544580`. |
| `0x004cfa00-0x004cfa01` | null virtual | Empty virtual slot referenced from primary vtable slot `0x0061b514`. |
| `0x004cfa10-0x004cfb0a` | `HandleInputEvent` | Dispatches tab action codes for event modes `1` and `2`. |
| `0x004cfb10-0x004cfb15` | `CanHandleInputEvent` | Returns false. |
| `0x004cfb20-0x004cfc5c` | raw rectangle builder | No IDA function object, no entrypoint xrefs, and no pointer hits; mirrors the six tab rectangles by calling `0x004b7c50`. Keep as boundary evidence, not final source, until reachability is proved. |
| `0x004cfc60-0x004cfd4d` | `ResolveTabActionCode` | Hit-tests six fixed rectangles and returns code `0..5` or `-1`. |
| `0x004cfd82-0x004cfd8d` | adjustor thunk | Subtracts `0xa0`, forwards to `0x004cfe00`. |
| `0x004cfd8d-0x004cfd98` | adjustor thunk | Subtracts `0xa4`, forwards to `0x004cfe00`. |
| `0x004cfe00-0x004cfe5f` | scalar deleting destructor | Clears singleton, calls shared pane cleanup, optionally frees `this` unless `flags & 4` is set. |

## Live IDA Evidence

- Function boundaries in this class span are `0x004cf980-0x004cf9ca`, `0x004cf9d0-0x004cf9f9`, `0x004cfa00-0x004cfa01`, `0x004cfa10-0x004cfb0a`, `0x004cfb10-0x004cfb15`, `0x004cfc60-0x004cfd4d`, `0x004cfd82-0x004cfd8d`, `0x004cfd8d-0x004cfd98`, and `0x004cfe00-0x004cfe5f`.
- The constructor entry `0x004cf980` has a direct caller at `0x004f812d` inside `InitializeMainUiGraph`.
- [UID:0000SE][g_pTabPane](by-global/g_pTabPane.md) at `0x0069adfc` is read at `0x0049e5e6` and `0x00504936`, written by the constructor at `0x004cf9a4`, and cleared by cleanup/destructor paths at `0x004cf9ea` and `0x004cfe20`.
- The cleanup helper and scalar deleting destructor both restore all three `TabPane` vtables before clearing the singleton; the scalar deleting destructor calls `0x00544580`, frees via `0x004f4ac0` when `flags & 1` is set and `flags & 4` is clear, and returns the object pointer otherwise.
- `HandleInputEvent` calls `ResolveTabActionCode` from mode `2` at `0x004cfa4c` and mode `1` at `0x004cfaae`; mode `1` handles tab codes `0..5`, while mode `2` handles codes `0`, `1`, `2`, and `5`.
- Action helper calls are `0x005a4f70` for code `0` with event field `+0x10c`, `0x005a4db0` for code `1`, `0x005a4e40` for code `2`, `0x005a4e70` for code `3`, `0x005a4ea0` for code `4`, and `0x005a4f40` for code `5`.
- `0x004cfb20-0x004cfc5c` has a real prolog and jump table at `0x004cfc40`, but live IDA has no function object, no direct xrefs to `0x004cfb20`, and no loaded-segment pointer hits to the entry. Its cases build the same six rectangles through `0x004b7c50`; treat it as raw tab-geometry evidence until a caller or source-level purpose is found.
- `ResolveTabActionCode` builds a rectangle with `0x004b7c50`, tests point containment through `0x004b7e80`, returns the matching tab code `0..5`, and returns `-1` when no rectangle contains the point.

## Tab Regions

| Code | Rect |
| --- | --- |
| `0` | `(2, 1)-(20, 46)` |
| `1` | `(2, 47)-(20, 93)` |
| `2` | `(2, 95)-(20, 140)` |
| `3` | `(2, 142)-(20, 187)` |
| `4` | `(2, 189)-(20, 234)` |
| `5` | `(2, 236)-(20, 281)` |

## External State

- [UID:0000SE][g_pTabPane](by-global/g_pTabPane.md) at `0x0069adfc`.
- `g_pAppMan` / `dword_67A748`; the input handler checks byte `+0x13eb1d` before dispatching selected action helpers.
- Action helpers around `0x005a4db0-0x005a4f70`; names remain provisional until the shortcut/action family is reviewed.

## Open Questions

- Name the six tab regions and action codes from UI/resource evidence rather than only helper behavior.
- Decide whether final source keeps `TabPane.cpp` separate or folds it with [UID:0000JZ][IconsPane](by-file/IconsPane.md) into an old-HUD controls module.
- Determine whether the raw `0x004cfb20` rectangle builder was source-authored but unreferenced, emitted from dead code, or an artifact of an inlined/table helper pattern.

## Score Rationale

Completion and confidence are raised because the page now records the live IDA function boundaries, constructor caller, vtable slots and writes, singleton xrefs, destructor flag behavior, exact input/action dispatch, the six rectangle table, and the previously missing raw `0x004cfb20` rectangle helper. The score remains below final-source range because tab labels, action-helper names, and final source grouping with `IconsPane` are still open.

## Cross-References

- [UID:0000OF][TabPane](by-file/TabPane.md)
- [UID:000170][0x004cf980-0x004cfe5f.TabPaneAndIconsPaneDestructorTail](by-memory/0x004cf980-0x004cfe5f.TabPaneAndIconsPaneDestructorTail.md)
- [UID:0000SE][g_pTabPane](by-global/g_pTabPane.md)
- [UID:00006B][IconsPane](by-class/IconsPane.md)

## Changes

- Before: completion/confidence were unevaluated at `0/0`.
- Changed to: completion `82`, confidence `76`.
- Evidence: the page documents old-layout tab-pane responsibility, layout/vtable evidence, singleton, method map, external state, and open action-code/source-grouping questions; confidence remains capped by unresolved tab-region names and final grouping with `IconsPane`.
- 2026-06-04 live IDA pass:
  - Before: completion `82`, confidence `76`, reconstructable metadata blank.
  - Changed to: completion `86`, confidence `86`, `RECONSTRUCTABLE:TRUE`, and parent [UID:0000OF][TabPane](by-file/TabPane.md).
  - Evidence: live IDA verified exact function boundaries, constructor caller, singleton xrefs, vtable slots/writes, destructor flag behavior, action-helper dispatch, exact tab rectangles, and the raw unreferenced `0x004cfb20-0x004cfc5c` rectangle helper; remaining uncertainty is limited to final tab labels, helper names, and source grouping.
