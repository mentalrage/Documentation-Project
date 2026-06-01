*** UID:00004N | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:74 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:78 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000J7 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# EventHandler

## Status

- Confidence: strong for base-interface behavior; medium for final virtual slot names.
- Likely source file: [UID:0000J7][EventDispatcher](by-file/EventDispatcher.md), or a small `ui/core/EventHandler.h` declared with [UID:0000MC][Pane](by-file/Pane.md).
- Current generated file: `source-3/simroot_v2/class_EventHandler.cpp`
- Imported source hint: `EventHandler.cpp`
- Main address doc: [UID:00014A][0x004a8970-0x004a8a84.EventHandlerBase](by-memory/0x004a8970-0x004a8a84.EventHandlerBase.md)
- Autogen parent: [UID:0000J7][EventDispatcher](by-file/EventDispatcher.md) as the current shared UI event infrastructure owner.

## Class Purpose

`EventHandler` is the minimal virtual event-handler interface used by pane and dispatcher code. `Pane` embeds or inherits an event-handler subobject in its `GrafPort` state, while [UID:00004M][EventDispatcher](by-class/EventDispatcher.md) walks registered handlers and calls family-specific virtual methods based on event type.

The generated class only exposes default construction/destruction and three small default virtuals. Feature panes install derived handler vtables over this base subobject.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| `EventHandler` | `0x004a8970-0x004a8978` | Installs the base event-handler vtable. |
| `~EventHandler` | `0x004a8980-0x004a8986` | Reinstalls the base vtable. |
| `ResetHandlerPairA` | `0x004a8a10-0x004a8a26` | Default virtual that zeroes a two-dword pair. |
| `ResetHandlerPairB` | `0x004a8a30-0x004a8a46` | Same pair-zeroing default as the previous slot. |
| `AlwaysHandleEvent` | `0x004a8a50-0x004a8a52` | Returns true. |
| `ScalarDeletingDestructor` | `0x004a8a60-0x004a8a84` | Reinstalls vtable and conditionally frees heap storage. |

## Ownership Notes

- [UID:0000A2][Pane](by-class/Pane.md) should document the embedded handler subobject because panes are the common concrete event-handler owners.
- [UID:00004M][EventDispatcher](by-class/EventDispatcher.md) owns handler registration, traversal, modal ordering, and dispatch calls.
- The base `EventHandler` declaration probably lived in a shared UI event header included by both `Pane.cpp` and `EventDispatcher.cpp`.

## Open Questions

- Final names for the two pair-zeroing virtuals at `0x004a8a10` and `0x004a8a30`.
- Which vtable slots correspond to pointer, key, UI, packet, and system event families in derived pane handler vtables.
- Whether the base interface was declared inside `EventDispatcher.h`, `Pane.h`, or a small `EventHandler.h`.

## Cross-References

- [UID:0000J7][EventDispatcher](by-file/EventDispatcher.md)
- [UID:00004M][EventDispatcher](by-class/EventDispatcher.md)
- [UID:0000A2][Pane](by-class/Pane.md)
- [UID:00014A][0x004a8970-0x004a8a84.EventHandlerBase](by-memory/0x004a8970-0x004a8a84.EventHandlerBase.md)
- [UID:000146][0x004a7cd0-0x004a7df3.EventDispatcherHandlerTreeSupport](by-memory/0x004a7cd0-0x004a7df3.EventDispatcherHandlerTreeSupport.md)
- [UID:0001UF][EventDispatcherHandlerTreeLayouts](by-type/by-struct/EventDispatcherHandlerTreeLayouts.md)

## Changes

- 2026-05-30:
  - Before: completion/confidence metadata was left at unevaluated `0/0`.
  - After: scored as `74/78`.
  - Summary/evidence: base-interface role, constructor/destructor/default virtuals, deleting destructor, pane/dispatcher ownership split, and tree-layout cross-references are documented; remaining uncertainty is final virtual slot names and header placement.
- 2026-06-01:
  - Before: the class was documented but not marked reconstructable or parented for autogen.
  - After: marked `RECONSTRUCTABLE:TRUE`, parented to [UID:0000J7][EventDispatcher](by-file/EventDispatcher.md), and corrected the scalar deleting destructor range to `0x004a8a60-0x004a8a84`.
  - Summary/evidence: live IDA MCP confirms the base method island and vtable references through [UID:00014A][0x004a8970-0x004a8a84.EventHandlerBase](by-memory/0x004a8970-0x004a8a84.EventHandlerBase.md).
