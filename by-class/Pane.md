*** UID:0000A2 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# Pane

## Status

- Confidence: strong.
- Likely source file: [UID:0000MC][Pane](by-file/Pane.md)
- Main address range: [UID:0001EA][0x00544460-0x00545086.PaneCore](by-memory/0x00544460-0x00545086.PaneCore.md)
- Type docs: [UID:0001VH][PaneLayout](by-type/by-struct/PaneLayout.md), [UID:0001YC][PaneCoreVtableFamily](by-type/by-vtable/PaneCoreVtableFamily.md)
- Current recovered file: `source-3/simroot_v2/class_Pane.cpp`

## Class Purpose

`Pane` is the base class for most UI elements. It inherits or embeds `GrafPort` at the front of the object, then layers on event handling, timer handling, visibility, dirty-region, clip-region, and layer-membership behavior.

## Observed State

IDA-confirmed offsets and generated-name hints are consolidated in [UID:0001VH][PaneLayout](by-type/by-struct/PaneLayout.md). Important state includes:

```text
0x000  GrafPort base
0x0a0  EventHandler secondary view
0x0a4  Timer/event tertiary view
0x0a8  attached Layer*
0x0b4  visible flag
0x0b5  pane mode byte
0x0c4  pending/alternate motion Region
0x0d8  in-paint/motion-lock byte
0x0dc  clip Region
0x0f0  input/focus registration state
0x0f4  dismissed/deletion marker
0x0f5  pane flags
0x0f8  first derived-class field

GrafPort state block:
0x08   bounds RECT
0x64   [EventHandler](EventHandler.md) subobject
0x68   TimerHandler/EventDispatcher subobject
0x6c   Layer* attached layer
0x70   origin point
0x78   visible flag
0x79   pane mode byte
0x88   dirty Region
```

## Method Families

| Family | Addresses | Role |
| --- | --- | --- |
| Construction/destruction | `0x00544460`, `0x004b8d20` | Initializes `GrafPort`, handlers, regions, mode/visibility state; releases surface/software storage and embedded objects. |
| Mode state | [UID:0002V7][0x005446b0-0x005446d4.PaneSetMode](by-memory/0x005446b0-0x005446d4.PaneSetMode.md) | Exact mode-byte setter for `+0xb5`; notifies through primary vtable slot `+0x20` when the mode changes. |
| Visibility/redraw | `0x00544730-0x005448ab` | Show, hide, repaint, and dirty-region invalidation. |
| Dirty/motion paint state | `0x00544690-0x00544b7d` | Deferred deletion marker, active/pending motion-region copy/subtract, motion comparison, begin-paint, and end-paint helpers used by layer traversal. |
| Bounds/layer membership | `0x00544b80-0x00544d70` | Screen bounds, local bounds, attached-layer test at `0x00544c50`, and add/insert/remove from `Layer`. |
| Default virtuals/thunks | `0x0041d680`, `0x00544e90`, `0x00544f2e-0x00544f43` | No-op draw/default handlers and compiler-generated adjustor thunk material. |
| Deferred deletion integration | `0x00469180` via [UID:00000W][BlackHole](by-class/BlackHole.md) | Pane close/replacement paths call a global helper that invokes `RemoveFromLayer`, `UnregisterEventHandler`, timer cleanup, and deferred deletion queueing. |

## Evidence Notes

- IDA MCP reports 95 direct constructor call sites.
- Generated source shows many feature panes calling `Pane::Pane` directly.
- `Pane::AddToLayer` calls `Layer::AddChildAfter`; `Pane::InsertInLayer` calls `Layer::AddChildBefore`; removal paths call `Layer::RemoveChild`.
- IDA maps pane vtable offsets `+0x38` and `+0x40` to `Pane::RemoveFromLayer` and `Pane::UnregisterEventHandler`; [UID:00000W][BlackHole](by-class/BlackHole.md) uses those virtuals before queueing panes for deferred deletion.
- 2026-06-03 IDA MCP confirms [UID:0002V7][0x005446b0-0x005446d4.PaneSetMode](by-memory/0x005446b0-0x005446d4.PaneSetMode.md) as the exact mode-byte setter at `0x005446b0-0x005446d4`; it writes `+0xb5` only when changed and dispatches vtable slot `+0x20` with `this + 0x44`.
- IDA maps `Pane` vtable bases at `0x006219e8`, `0x00621a34`, and `0x00621a64`; the secondary and tertiary destructor slots are the adjustor thunks `0x00544f2e` and `0x00544f39`.
- IDA caller checks tie the `0x00544690-0x00544b7d` dirty/motion helpers to `Layer` recursion and shared surface presentation. Current generated `class_MapPane.cpp` ownership for these helpers should not be treated as source-file evidence.
- The base [UID:00004N][EventHandler](by-class/EventHandler.md) methods at `0x004a8970-0x004a8a83` are shared UI event infrastructure used by pane-derived handlers and [UID:00004M][EventDispatcher](by-class/EventDispatcher.md).

## Cross-References

- [UID:0000MC][Pane](by-file/Pane.md)
- [UID:0001EA][0x00544460-0x00545086.PaneCore](by-memory/0x00544460-0x00545086.PaneCore.md)
- [UID:0001VH][PaneLayout](by-type/by-struct/PaneLayout.md)
- [UID:0001YC][PaneCoreVtableFamily](by-type/by-vtable/PaneCoreVtableFamily.md)
- [UID:0001EB][0x00544f2e-0x00544f43.PaneAdjustorThunks](by-memory/0x00544f2e-0x00544f43.PaneAdjustorThunks.md)
- [UID:0002V7][0x005446b0-0x005446d4.PaneSetMode](by-memory/0x005446b0-0x005446d4.PaneSetMode.md)
- [UID:00005V][GrafPort](by-class/GrafPort.md)
- [UID:000073][Layer](by-class/Layer.md)
- [UID:00000W][BlackHole](by-class/BlackHole.md)
- [UID:0000A3][PaneChildRegistry](by-class/PaneChildRegistry.md)
- [UID:00004N][EventHandler](by-class/EventHandler.md)
- [UID:00004M][EventDispatcher](by-class/EventDispatcher.md)

## Changes

- Before: the `PaneCore` memory page reference ended at `0x00545085`.
- Changed to: the page ends at `0x00545086`.
- Summary/evidence: 2026-05-28 IDA MCP byte/function review shows `0x00545085` is the final operand byte of `sub_544F50`'s `retn 4`.
- Before: completion/confidence metadata were `0/0` even though the page already documented the base UI class purpose, layout offsets, method families, vtables, caller evidence, and derived infrastructure relationships.
- Changed to: `COMPLETION:88` and `CONFIDENCE:86`.
- Evidence: core offsets, construction/destruction, visibility/redraw, dirty/motion paint state, bounds/layer membership, virtual thunk material, deferred deletion integration, vtable bases, and event infrastructure are documented; remaining work is mostly raw body-level C++ and exhaustive per-caller relationship coverage.
