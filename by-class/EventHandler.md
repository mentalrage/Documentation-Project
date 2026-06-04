*** UID:00004N | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:82 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000J7 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# EventHandler

## Status

- Confidence: strong for base-interface behavior and vtable shape; medium for final virtual slot names and header placement.
- Likely source file: [UID:0000J7][EventDispatcher](by-file/EventDispatcher.md), or a small `ui/core/EventHandler.h` declared with [UID:0000MC][Pane](by-file/Pane.md).
- Imported source hint: `EventHandler.cpp`
- Main address doc: [UID:00014A][0x004a8970-0x004a8a84.EventHandlerBase](by-memory/0x004a8970-0x004a8a84.EventHandlerBase.md)
- Autogen parent: [UID:0000J7][EventDispatcher](by-file/EventDispatcher.md) as the current shared UI event infrastructure owner.

## Class Purpose

`EventHandler` is the minimal virtual event-handler interface used by pane and dispatcher code. `Pane` embeds or inherits an event-handler subobject in its `GrafPort` state, while [UID:00004M][EventDispatcher](by-class/EventDispatcher.md) walks registered handlers and calls family-specific virtual methods based on event type.

The recovered base class exposes default construction/destruction, a dispatcher-forwarding default slot, two pair-reset default slots, and an always-true default predicate. Feature panes install derived handler vtables over this base subobject.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| `EventHandler` | `0x004a8970-0x004a8978` | Installs the base event-handler vtable. |
| `~EventHandler` | `0x004a8980-0x004a8986` | Reinstalls the base vtable. |
| `ForwardToDispatcherDefault` | `0x004a89f0-0x004a8a09` | Vtable default that forwards two arguments through the global dispatcher helper with a zero flag. |
| `ResetHandlerPairA` | `0x004a8a10-0x004a8a26` | Default virtual that zeroes a two-dword pair. |
| `ResetHandlerPairB` | `0x004a8a30-0x004a8a46` | Same pair-zeroing default as the previous slot. |
| `AlwaysHandleEvent` | `0x004a8a50-0x004a8a52` | Returns true. |
| `ScalarDeletingDestructor` | `0x004a8a60-0x004a8a84` | Reinstalls vtable and conditionally frees heap storage. |

## Evidence Notes

- 2026-06-04 live IDA MCP identity: `NexusTK.exe` at base `0x400000`, MD5 `4247e04e20b65d6414c7238aa8ff5515`, SHA256 `9aec210bbc5ce592176a21dd8e9d9fd8f250b8d9ea78237915a99ba8cfa9a632`.
- Function lookup confirms the base island: `0x004a8970` size `0x9`, `0x004a8980` size `0x7`, `0x004a89f0` size `0x1a`, `0x004a8a10` size `0x17`, `0x004a8a30` size `0x17`, `0x004a8a50` size `0x3`, and `0x004a8a60` size `0x24`; `0x004a8a84` is padding before the next event-object function at `0x004a8a90`.
- Decompilation confirms the constructor, ordinary destructor, and scalar deleting destructor all write `EventHandler::vftable`; the deleting destructor frees the block only when its low flag bit is set.
- Direct code references are narrow: the constructor is called from `0x0054449d` in `sub_544460`, the ordinary destructor from `0x00544669` in `sub_544580` and `0x00545040` in `sub_544F50`, plus the `0x00605a51` cleanup reference associated with `sub_544460`.
- Vtable data is named `??_7EventHandler@@6B@` at `0x00619674`, with RTTI pointer `0x00647068`; slots map to the scalar deleting destructor at `0x00619674`, six `__purecall` entries at `0x00619678-0x0061968c`, the dispatcher-forwarding default at `0x00619690`, pair-reset defaults at `0x00619694` and `0x00619698`, and the always-true predicate at `0x0061969c`.
- The source parent remains [UID:0000J7][EventDispatcher](by-file/EventDispatcher.md): the class is a shared UI event-interface type and the parent file is already scored high enough for attachment, but final C++ remains below the `95/95` reconstruction bar.

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
- 2026-06-04:
  - Before: scored as `74/78`, with stale source-output wording and incomplete vtable-slot evidence.
  - After: scored as `82/88`.
  - Summary/evidence: live IDA MCP rechecked the NexusTK executable identity, exact function starts/sizes, decompiled constructor/destructor/default-slot bodies, constructor/destructor callers, vtable RTTI, purecall/default slot mapping, and the padding boundary before `0x004a8a90`; remaining uncertainty is limited to final virtual names and header placement, so no final reconstruction C++ is emitted.
