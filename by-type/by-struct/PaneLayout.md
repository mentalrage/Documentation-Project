*** UID:0001VH | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:82 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000A2 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# Pane Layout

## Status

- Entity kind: class layout / UI base object state.
- Covered class: [UID:0000A2][Pane](by-class/Pane.md).
- Likely owner header/source: [UID:0000MC][Pane](by-file/Pane.md).
- Confidence: strong for listed offsets and derived boundary; medium for final names of several flags/region roles.
- Autogen parent: attached to [UID:0000A2][Pane](by-class/Pane.md); the class scores `88/86` and this layout scores `82/86`, so both sides satisfy the 80/80 parent gate.
- Verification basis: IDA MCP `lookup_funcs` and decompilation rechecked representative constructor, destructor, visibility, deletion, layer, and motion-region methods on 2026-05-31. Generated Wave3/simroot data is not used as authority for this score.

## Observed Layout

`Pane` is the common UI base over [UID:00005V][GrafPort](by-class/GrafPort.md). It keeps the primary `GrafPort`/pane view at object start, installs event/timer handler views at `+0xa0` and `+0xa4`, and adds layer, visibility, motion/clip, deletion, and focus state. Derived classes such as [UID:0001U4][DialogPaneLayout](by-type/by-struct/DialogPaneLayout.md) and [UID:0001U5][DialogSessionLayouts](by-type/by-struct/DialogSessionLayouts.md) begin their own fields at `+0xf8`.

| Offset | Field hypothesis | Evidence |
| --- | --- | --- |
| `+0x00` | primary `GrafPort`/`Pane` vptr, `0x006219e8` | `GrafPort` constructor writes the base table, then `Pane::Pane` installs the `Pane` primary vtable. |
| `+0x04` | inherited `GrafPort` active/current region state | `GrafPort` constructs a region here; motion helpers copy from or into this region. |
| `+0x18` | inherited `GrafPort` primary surface pointer | `GrafPort` constructor/destructor initialize and release this field. |
| `+0x1c` | inherited `GrafPort` tile/context state | `GrafPort` constructor initializes this context and destructor tears it down. |
| `+0x2c` | inherited `GrafPort` rectangle/state block | `GrafPort` initializes this rectangle; final role belongs to [UID:00005V][GrafPort](by-class/GrafPort.md). |
| `+0x44` | local/bounds rectangle | `Show`, `InvalidateRect`, and `SetBounds` use this as the local draw/bounds rectangle. |
| `+0x54` | inherited `GrafPort` exposed/dirty region | `GrafPort` constructs a region here; GrafPort update/draw paths use it. |
| `+0x68` | inherited `GrafPort` point/draw-state area | `GrafPort` initializes a point here; draw-state fields continue through this block. |
| `+0xa0` | event-handler secondary vptr, `0x00621a34` | Constructor calls `EventHandler` constructor here, then stores the `Pane` secondary table. Dispatcher helpers pass `this + 0xa0`. |
| `+0xa4` | timer/event tertiary vptr, `0x00621a64` | Constructor calls timer handler constructor here, then stores the `Pane` tertiary table. |
| `+0xa8` | attached `Layer*` | Constructor initializes zero; add/insert/remove helpers read and write the cached layer pointer. |
| `+0xac` | pane origin point | Constructor initializes to `(0,0)`; `SetBounds` stores the top-left origin here. |
| `+0xb4` | visible byte | Constructor initializes `1`; `Show` sets `1`, `Hide` sets `0`. |
| `+0xb5` | pane mode byte | Constructor stores the incoming mode; `Show` skips redraw when mode is `4`; [UID:0002V7][0x005446b0-0x005446d4.PaneSetMode](by-memory/0x005446b0-0x005446d4.PaneSetMode.md) updates it only on change and dispatches the pane vtable slot `+0x20`. |
| `+0xb8` | auxiliary pane pointer/state | Constructor initializes zero; exact role remains open. |
| `+0xc0` | auxiliary state byte | Constructor initializes zero; exact role remains open. |
| `+0xc4` | pending/alternate motion region | Constructor initializes and empties this region; motion helpers compare/copy/subtract it. |
| `+0xd8` | in-paint/motion-lock byte | `BeginMotionPaint` sets it to `1`; `EndMotionPaint` clears it. |
| `+0xdc` | pane clip/committed motion region | Constructor initializes and empties this region; `BeginMotionPaint` copies it into active region state. |
| `+0xf0` | input/focus registration state dword | Destructor paths test this against `1` before focus cleanup through the global manager. |
| `+0xf4` | dismissed/deferred-delete marker | Constructor initializes zero; `MarkForDeletion` sets it before queueing through the pane manager/deferred deletion path. |
| `+0xf5` | pane motion/dirty flag byte | `GetCurrentMotionRegion` and `HasPendingMotion` choose current versus pending region behavior from this byte. |
| `+0xf6` | adjacent pane flag byte | Constructor clears it as part of a word store at `+0xf5`; exact role remains open. |
| `+0xf8` | first derived-class field | `DialogPane` title starts here; `DialogSession` tracked-list pointer starts here. |

## IDA Evidence

Checked on 2026-05-26 and representative methods rechecked through IDA MCP on 2026-05-31:

- `Pane::Pane` at `0x00544460` calls `GrafPort::GrafPort`, constructs handler subobjects at `+0xa0` and `+0xa4`, installs the three `Pane` vtables, constructs regions at `+0xc4` and `+0xdc`, initializes layer/origin/visible/mode state, clears delete/input flags, and returns `this`.
- `Pane` non-deleting destructor at `0x00544580` and scalar deleting destructor at `0x00544f50` reinstall the three `Pane` vtables, clear active dispatcher/layer state through `+0xa0` and `+0xa8`, destroy the regions at `+0xdc` and `+0xc4`, tear down the handler subobjects, and call `GrafPort` teardown.
- `MarkForDeletion` at `0x00544690` reads/writes byte `+0xf4`.
- `Show` and `Hide` at `0x00544730` and `0x00544750` write visible byte `+0xb4`; `Show` also checks mode byte `+0xb5`.
- `PaneSetMode` at `0x005446b0-0x005446d4` compares and writes mode byte `+0xb5`, then calls the primary vtable slot `+0x20` with `this + 0x44` when the mode changed; this was rechecked through IDA MCP on 2026-06-03.
- `GetCurrentMotionRegion`, `HasPendingMotion`, `BeginMotionPaint`, and `EndMotionPaint` at `0x005446e0`, `0x00544a40`, `0x00544ae0`, and `0x00544b50` use `+0xc4`, `+0xd8`, `+0xdc`, and `+0xf5` for motion/dirty state.
- `AddToLayer`, `InsertInLayer`, and `RemoveFromLayer` at `0x00544c70`, `0x00544cb0`, and `0x00544ce0` read and write the cached layer pointer at `+0xa8`.
- `IsAttachedToLayer` / layer-membership test at `0x00544c50` reads the cached layer pointer at `+0xa8` and asks whether that layer contains the current pane.
- `SetPaneOrder` and `UnregisterEventHandler` at `0x00544d30` and `0x00544d70` pass `this + 0xa0` to `EventDispatcher`.

## Reconstruction Notes

- Model `Pane` as a concrete base class of size `0xf8` before derived state starts. This matches `DialogPane +0xf8` title storage and `DialogSession +0xf8` session-stack storage.
- Keep `GrafPort` declaration details in [UID:0000JR][GrafPort](by-file/GrafPort.md). This page records the direct object offsets visible through pane behavior, not the full rendering-port declaration.
- Keep the `+0xa0` and `+0xa4` handler views as real embedded subobjects/interfaces. Their destructor adjustor thunks are compiler ABI glue and should not become handwritten methods.
- Current generated `class_Pane.cpp` still has source-quality issues such as synthetic overlays and `ConnStatusPane` names on generic pane state wrappers; use IDA layout evidence for final source declarations.

## Cross-References

- [UID:0000MC][Pane](by-file/Pane.md)
- [UID:0000A2][Pane](by-class/Pane.md)
- [UID:0001EA][0x00544460-0x00545086.PaneCore](by-memory/0x00544460-0x00545086.PaneCore.md)
- [UID:0001YC][PaneCoreVtableFamily](by-type/by-vtable/PaneCoreVtableFamily.md)
- [UID:0001EB][0x00544f2e-0x00544f43.PaneAdjustorThunks](by-memory/0x00544f2e-0x00544f43.PaneAdjustorThunks.md)
- [UID:0002V7][0x005446b0-0x005446d4.PaneSetMode](by-memory/0x005446b0-0x005446d4.PaneSetMode.md)
- [UID:0000JR][GrafPort](by-file/GrafPort.md)
- [UID:0001U4][DialogPaneLayout](by-type/by-struct/DialogPaneLayout.md)
- [UID:0001V9][ModelessDialogPaneLayout](by-type/by-struct/ModelessDialogPaneLayout.md)
- [UID:0001U5][DialogSessionLayouts](by-type/by-struct/DialogSessionLayouts.md)
- [Wave3 data issues](../../wave3_data_issues.md)

## Changes

- 2026-06-06: Attached the base pane layout to [UID:0000A2][Pane](by-class/Pane.md). Scores remain `82/86`; this is a parent metadata sync for the already documented base layout.
- Before: validator metadata was unevaluated at completion `0`, confidence `0`, and reconstructable blank despite existing detailed offset documentation.
- Changed to: `RECONSTRUCTABLE:TRUE`, completion `82`, confidence `86`.
- Evidence: IDA MCP verified `Pane::Pane` at `0x00544460`, non-deleting destructor `0x00544580`, scalar deleting destructor `0x00544f50`, deletion marker `0x00544690`, visibility methods `0x00544730`/`0x00544750`, motion-region helpers `0x00544a40`/`0x00544ae0`/`0x00544b50`, and layer membership helpers `0x00544c70`/`0x00544cb0`/`0x00544ce0`. Scores stay below `95+` because final source names for several flags/regions and complete downstream use-site audits remain unresolved.
