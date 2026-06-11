*** UID:00004M | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:85 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000J7 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# EventDispatcher

## Summary

`EventDispatcher` is the UI event-routing singleton. It owns a timer-handler base, pane-entry tree/list structures, active/previous pane tracking, dispatch traversal order, modal list insertion, and recursive event dispatch into child handlers.

## Likely Original Placement

- Source: [UID:0000J7][EventDispatcher](by-file/EventDispatcher.md)
- Proposed path: `ui/core/EventDispatcher.cpp`
- Confidence: strong

## Methods

- `0x004a6a80` constructor - initializes `TimerHandler`, embedded `LObject` tree, sentinel entries, `FrameMgr`, keyboard state, and `g_pEventDispatcher`.
- `0x004a6ce0` `SetPaneOrder`.
- `0x004a6dd0` `RemovePaneEntry`.
- `0x004a6ef0` `DispatchEvent`.
- `0x004a6f40` `SetActivePaneEntry`.
- `0x004a6f80` `ContainsPaneEntry`.
- `0x004a6fc0` `AddToModalList`.
- `0x004a7110` `OnTimerTick`.
- `0x004a7130` `RouteEventToHandlers`.
- `0x004a7570` `DispatchToChildren`.
- `0x004a7690` `DispatchToTranslatedChildren`.
- `0x004a77d0` `CallHandler`.
- `0x004a78f0` internal helper to find an enabled matching handler record and update a tree iterator.
- `0x004a7b10` internal helper to grow/insert a 28-byte handler-record vector entry.
- `0x004a7cd0-0x004a7df3` handler tree support island: [UID:0000F8][Tree_near_class_EventHandler___](by-class/Tree_near_class_EventHandler___.md), [UID:0000FA][TreeItor_near_class_EventHandler___](by-class/TreeItor_near_class_EventHandler___.md), and [UID:000060][HandlerFindFunc](by-class/HandlerFindFunc.md).
- `0x004a7e00` scalar deleting destructor.
- `0x004a7e70` `RebuildHandlerTraversalOrder`.
- `0x004a87a0` internal helper to free and clear the handler-record vector.
- `0x00597580` was formerly projected as an `EventDispatcher` destructor, but current docs resolve it as [UID:0001K7][0x00597580-0x005975c3.TimerHandlerDestructor](by-memory/0x00597580-0x005975c3.TimerHandlerDestructor.md).

## Evidence

- IDA MCP confirms the constructor is called from `Application::Initialize` at `0x00464613`.
- IDA MCP confirms `DispatchEvent` has many direct callers, including application event adapter paths.
- IDA MCP confirms `RouteEventToHandlers` calls child dispatch, translated-child dispatch, `CallHandler`, and keyboard-state helper paths.
- IDA MCP recheck on 2026-05-25 confirms the unresolved helper starts under `0x004a78f0-0x004a87a0` are dispatcher handler-tree/list/vector support, not independent feature files.
- IDA MCP confirms `0x00597580` is a function and still names it as a Boost exception destructor, but decompilation writes `TimerHandler::vftable` and calls the timer-manager remove-all helper. Treat `EventDispatcher` as a caller/derived timer owner, not the owner of that range.
- 2026-05-26 recheck against current `simroot_v2` and IDA MCP: the generated source still externs `sub_4A78F0`, still splits the concrete tree/iterator/predicate helper files, and still mis-attaches `0x00597580` to `~EventDispatcher`. IDA callers continue to keep `0x004a78f0`, `0x004a7b10`, `0x004a7d00`, and `0x004a87a0` inside the dispatcher handler-tree/list/vector cleanup paths.
- 2026-06-07 A010 live IDA refresh reconfirmed constructor `0x004a6a80` with caller `0x00464613`, central dispatch `0x004a6ef0` with broad UI/event caller coverage, and `RouteEventToHandlers` at `0x004a7130` as the immediate callee from dispatch. The same refresh keeps `0x004a78f0`, `0x004a7b10`, `0x004a7d00`, and `0x004a87a0` in dispatcher-owned handler search/vector/list cleanup paths through their callers.
- 2026-06-07 callee refresh shows `0x004a7130` calls keyboard-state helpers plus the child-dispatch/helper fanout, including `0x004a78f0`, `0x004a7570`, `0x004a7690`, and `0x004a77d0`; screenshot helper calls from this route are event-action side effects, not evidence for moving the dispatcher to image-writer ownership. `0x00597580` remains a modeled function with a stale public name and is still treated as TimerHandler base cleanup rather than an EventDispatcher method.

## Assignment Gate

`AUTOGEN_PARENT_UID` is set to [UID:0000J7][EventDispatcher](by-file/EventDispatcher.md). The child is now `85/86`, the direct source-file parent is already `89/85`, and the relationship is direct by-structure ownership because this class is the principal class implemented by the EventDispatcher file.

## Score Rationale

- Completion is `85` because singleton role, source placement, constructor/dispatch/routing methods, handler tree/vector support islands, memory cross-references, timer-base exclusion, and direct parent routing are documented.
- Confidence is `86` because live IDA confirms constructor, central dispatch, route helper, and internal handler-support xrefs while the by-file parent already clears the corrected 85/85 gate.
- The score stays below final-code range because final helper names, header placement for adjacent event types, and generated ownership refresh still need cleanup before C++ emission.

## Open Questions

- Final names for the internal handler-tree/list/vector helper functions under `0x004a78f0-0x004a87a0`.
- Confirm generated ownership after the next refresh; current `simroot_v2` is still stale for both helper materialization and `0x00597580`.
- Confirm whether `Event` should remain in the same source file or become a small `Event.cpp`.
- Confirm whether [UID:00004N][EventHandler](by-class/EventHandler.md) was declared in `EventDispatcher.h`, `Pane.h`, or an adjacent `EventHandler.h`.
- Keep timer-base cleanup ranges under [UID:0000OT][TimerMgr](by-file/TimerMgr.md) while retaining `EventDispatcher` as a timer consumer.

## Cross-References

- File: [UID:0000J7][EventDispatcher](by-file/EventDispatcher.md)
- Related classes: [UID:00004N][EventHandler](by-class/EventHandler.md), [UID:000060][HandlerFindFunc](by-class/HandlerFindFunc.md), [UID:0000F8][Tree_near_class_EventHandler___](by-class/Tree_near_class_EventHandler___.md), [UID:0000FA][TreeItor_near_class_EventHandler___](by-class/TreeItor_near_class_EventHandler___.md), [UID:00004L][Event](by-class/Event.md), [UID:00000E][ApplicationHelper_4A6C40](by-class/ApplicationHelper_4A6C40.md), [UID:00000D][Application](by-class/Application.md), [UID:0000A2][Pane](by-class/Pane.md)
- Memory: [UID:000141][0x004a6a80-0x004a82a9.EventDispatcher](by-memory/0x004a6a80-0x004a82a9.EventDispatcher.md), [UID:000144][0x004a78f0-0x004a7979.EventDispatcherFindHandlerIterator](by-memory/0x004a78f0-0x004a7979.EventDispatcherFindHandlerIterator.md), [UID:000145][0x004a7b10-0x004a7c2a.EventDispatcherHandlerRecordVectorInsert](by-memory/0x004a7b10-0x004a7c2a.EventDispatcherHandlerRecordVectorInsert.md), [UID:000146][0x004a7cd0-0x004a7df3.EventDispatcherHandlerTreeSupport](by-memory/0x004a7cd0-0x004a7df3.EventDispatcherHandlerTreeSupport.md), [UID:000147][0x004a7d00-0x004a7d43.EventDispatcherHandlerListDestructor](by-memory/0x004a7d00-0x004a7d43.EventDispatcherHandlerListDestructor.md), [UID:00022A][0x004a82b0-0x004a8795.EventDispatcherHandlerRecordRelinkHelpers](by-memory/0x004a82b0-0x004a8795.EventDispatcherHandlerRecordRelinkHelpers.md), [UID:000148][0x004a87a0-0x004a8810.EventDispatcherHandlerRecordVectorFree](by-memory/0x004a87a0-0x004a8810.EventDispatcherHandlerRecordVectorFree.md), [UID:00022B][0x004a8820-0x004a88d2.EventDispatcherHandlerRecordVectorAllocationHelpers](by-memory/0x004a8820-0x004a88d2.EventDispatcherHandlerRecordVectorAllocationHelpers.md), [UID:00014A][0x004a8970-0x004a8a84.EventHandlerBase](by-memory/0x004a8970-0x004a8a84.EventHandlerBase.md), [UID:0001K7][0x00597580-0x005975c3.TimerHandlerDestructor](by-memory/0x00597580-0x005975c3.TimerHandlerDestructor.md)

## Changes

- 2026-06-07 A010 Batch086 class coverage toss-up:
  - Before: score `82/82`, `AUTOGEN_PARENT_UID` blank.
  - After: score `85/86`, `AUTOGEN_PARENT_UID:0000J7`.
  - Evidence: live IDA reconfirmed constructor caller, broad `DispatchEvent` caller coverage, `RouteEventToHandlers` fanout, handler search/vector/list helper ownership, and the TimerHandler destructor exclusion; [UID:0000J7][EventDispatcher](by-file/EventDispatcher.md) was already `89/85`, so both child and direct parent meet the corrected 85/85 gate.
- 2026-05-30:
  - Before: completion/confidence metadata was left at unevaluated `0/0`.
  - After: scored as `82/82`.
  - Summary/evidence: dispatcher singleton role, major routing/tree/vector/modal/timer methods, helper islands, Application construction evidence, stale timer destructor ownership correction, open questions, and detailed memory cross-references are documented; remaining uncertainty is final helper names and refreshed generated ownership.
- 2026-05-31:
  - Before: `RECONSTRUCTABLE` metadata was blank.
  - After: marked `RECONSTRUCTABLE:TRUE`.
  - Summary/evidence: IDA MCP rechecks keep the constructor, event-routing methods, handler tree/list/vector helpers, and dispatcher cleanup paths under project-owned `EventDispatcher` UI infrastructure. Parent attachment and C++ reconstruction code remain blank because final helper declarations/source shape are not at the 95+ gate.
