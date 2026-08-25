*** UID:00004N | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:89 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0004ZN | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0004ZN | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
#include "EventHandler.h"
#include "EventDispatcher.h"

[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
#ifndef NEXUSTK_UI_CORE_EVENTHANDLER_H
#define NEXUSTK_UI_CORE_EVENTHANDLER_H

#include "RectBounds.h"

class Event;
class EventDispatcher;

extern EventDispatcher *g_pEventDispatcher;

class EventHandler
{
public:
    EventHandler();
    virtual ~EventHandler();

    virtual bool HandlePointerOrMouseEvent(Event *event) = 0;
    virtual bool HandleKeyOrTextEvent(Event *event) = 0;
    virtual bool HandleImeEvent(Event *event) = 0;
    virtual bool HandlePacketEvent(Event *event) = 0;
    virtual bool HandleSystemOrControlEvent(Event *event) = 0;
    virtual bool HandleType19Event(Event *event) = 0;

    virtual bool ForwardHandlerOrder(EventHandler *first, EventHandler *second);
    virtual void GetLocalOffset(Point *offset);
    virtual void GetScreenOffset(Point *offset);
    virtual bool ShouldAcceptEvent() const;
};

typedef char EventHandlerSizeMustBe4[sizeof(EventHandler) == 4 ? 1 : -1];

#endif
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# EventHandler

## C134 Header Assembly Closure

`EventHandler.h` now has one complete declaration under `NEXUSTK_UI_CORE_EVENTHANDLER_H`. The RectBounds include supplies the project `Point` value type; exact method bodies remain CPP children, so the declaration channel omits an empty child token. This resolves command20473's repeated-include and invalid-attribute failures without changing interface order or the exact four-byte vptr-only layout.

## Status

- Confidence: strong for base-interface behavior, vtable shape, and direct packet/system/type-19 declaration order; medium for final virtual slot names and header placement.
- Likely source file: [UID:0000J7][EventDispatcher](by-file/EventDispatcher.md), with a high-probability shared `ui/core/EventHandler.h` or EventDispatcher-adjacent event header included by both dispatcher and pane code.
- Imported source hint: `EventHandler.cpp`
- Main address doc: [UID:00014A][0x004a8970-0x004a8a84.EventHandlerBase](by-memory/0x004a8970-0x004a8a84.EventHandlerBase.md)
- Read-only data: [UID:0003I6][0x00619670-0x006196a0.EventHandlerVtableData](by-memory/0x00619670-0x006196a0.EventHandlerVtableData.md)
- Autogen parent: [UID:0000J7][EventDispatcher](by-file/EventDispatcher.md) as the current shared UI event infrastructure owner.

## UID0003ZT EventHandler Header Contract - 2026-07-23

- `NexusTK/ui/core/EventHandler.h` owns `EventPointPair`, the complete `EventHandler` interface, `class Event;`, `class EventDispatcher;`, and `extern EventDispatcher *g_pEventDispatcher`.
- The header does not redeclare a partial `EventDispatcher` class merely to expose `SetPaneOrder`. `EventHandler.cpp` includes the canonical `EventDispatcher.h` before defining `ForwardHandlerOrder`, so the member call sees the complete router declaration.
- EventHandler virtual signatures use only `Event *`; member-access consumers such as [UID:0003ZT][0x00508f60-0x0050902b.MapPaneNotifyMessageCore](by-memory/0x00508f60-0x0050902b.MapPaneNotifyMessageCore.md) separately include self-contained `Event.h`.
- `EventDispatcher.h` includes `TimerHandler.h` and EventHandler.h before its dispatcher-local records/storage and complete router shell. `Pane.h` includes GrafPort.h, EventHandler.h, and TimerHandler.h before defining Pane.
- This removes the incomplete duplicate-class defect without changing the handler's `89/92` score, owner/emitter [UID:0000J7][EventDispatcher](by-file/EventDispatcher.md), vtable order, pure virtual slots, default method bodies, or prior evidence.

## Class Purpose

`EventHandler` is the minimal virtual event-handler interface used by pane and dispatcher code. `Pane` embeds or inherits an event-handler subobject in its `GrafPort` state, while [UID:00004M][EventDispatcher](by-class/EventDispatcher.md) walks registered handlers and calls family-specific virtual methods based on event type.

## UID000090 Separate Header And Shared Point Closure - 2026-07-31

- Direct owner/emitter is now [UID:0004ZN][EventHandler](by-file/EventHandler.md), the separate `NexusTK/ui/core/EventHandler.h/.cpp` source owner. Historical direct routing through UID0000J7 remains below as superseded provenance.
- The H formal includes shared `RectBounds.h`, uses `Point` for offset outputs, declares the complete eleven-slot abstract/default interface, and guards the exact four-byte vptr-only layout with `EventHandlerSizeMustBe4`.
- The CPP formal includes `EventHandler.h` and complete `EventDispatcher.h` before the child marker, making the forwarding default's dispatcher member call source-legal without a partial duplicate router declaration.
- Historical `EventPointPair`, `GetLocalEventPair`, and `GetScreenEventPair` are superseded aliases. Exact source-facing defaults are `GetLocalOffset(Point *)` and `GetScreenOffset(Point *)`; the six event-family declarations and their exact bodies are otherwise unchanged.

The recovered base class exposes default construction/destruction, six source-defined false-return default bodies for pure event-family slots, a dispatcher-forwarding default slot, two pair-output default slots, and an always-true default predicate. Feature panes install derived handler vtables over this base subobject.

B008's EventMan/factory helper pass gives the current family vocabulary for those virtual slots: pointer/mouse events `0..7`, key/text events `8..10`, IME events `11..17`, packet events `18`, a dispatcher special slot for type `19`, and system/control events `20..22`. B002's accepted UID00014B synchronization adds global producer resolution: type `19` is `kEventApplicationNotification`, built by Main_WndProc message `0x406` with channel and `LObject *` payload after `EventMan::PostNotification`; type `22` is `kEventWorkNotification`, built by Main_WndProc custom message `0x400` with low-word subtype `32`. Types `17`, `20`, and `21` still have no producer after checking all Event-vtable construction sites and all five out-of-line constructor callers; type `20` is directly suppressed before normal dispatch. Exact original virtual method names remain inferred, but docs should use these families instead of generic pointer/key/UI placeholders.

## UID00014B Event Record Synchronization

- [UID:00004L][Event](by-class/Event.md) now emits the accepted Event enum and exact `0x110` declaration: unsigned type byte at `+0x04` and a `0x108` variant payload union beginning at `+0x08`.
- Handler-facing pointer records use x/y `+0x08/+0x0c`, modifier `+0x10`, detail `+0x14`, and message time `+0x18`; key/text/IME records use embedded text state and message time `+0x10c`. The historical common-tick interpretation is not applied to pointer records.
- Packet handlers receive kind/data/size at `+0x08/+0x0c/+0x10`; EventDispatcher frees type-18 data after handler routing. The type19 slot receives channel/payload at `+0x08/+0x0c` and Main_WndProc releases the `LObject *` after dispatch.
- [UID:00014B][0x004a8a90-0x004a8abf.EventBaseConstructorDestructor](by-memory/0x004a8a90-0x004a8abf.EventBaseConstructorDestructor.md) now emits source lifecycle. Its five constructor calls and 49 destructor refs plus 79 Event-vtable refs prove the record is live across Main_WndProc, MapPane, retained mouse/key helpers, and inlined Event.cpp factories.
- The scalar deleting destructor and Event vtable pages carry compiler-coverage markers; EventHandler declarations must not duplicate scalar-delete ABI or raw vtable data.
- Current RTTI/name inventory has one Event record class and no Event-derived class. EventHandler is a consumer interface and remains owned by EventDispatcher infrastructure, not Event.cpp lifecycle.

## Packet, System, And Type-19 Slot Order

- Live IDA MCP session `160045b9` reconfirmed `EventDispatcher` dispatch at `0x004a77d0`: packet-family events call the secondary virtual at `+0x10`, system/control events call `+0x14`, and exact type-19 events call `+0x18`. The managed declaration now follows those offsets as `HandlePacketEvent`, `HandleSystemOrControlEvent`, then `HandleType19Event`.
- The accepted `Event` record supplies type at `+0x04` and payload at `+0x08`. Packet events are type 18 with kind/data/size at `+0x08/+0x0c/+0x10`; the concrete [UID:0002EU][0x0047f890-0x0047f8c9.ChattingPaneChatPacketRouter](by-memory/0x0047f890-0x0047f8c9.ChattingPaneChatPacketRouter.md) override reads packet data from `+0x0c`. Type 19 instead carries its channel/payload pair at `+0x08/+0x0c`, while system/control covers the distinct dispatch family at types 20 through 22.
- [UID:0003AT][0x00614cdc-0x00615284.ChattingVtableData](by-memory/0x00614cdc-0x00615284.ChattingVtableData.md) independently fixes the concrete `ChattingPane` secondary table: UID0002EU is at `+0x10`, inherited system/control is at `+0x14`, and inherited type 19 is at `+0x18`. Its scalar deleting destructor adjustor and the remaining inherited/default slots preserve the same eleven-entry interface shape.
- The order correction does not rename or synthesize bodies, change ownership, alter the six source-defined pure-default false bodies, or weaken the existing producer/cleanup evidence. Exact original method spellings remain descriptive; direct slot order is no longer open.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| `EventHandler` | `0x004a8970-0x004a8978` | Installs the base event-handler vtable. |
| `~EventHandler` | `0x004a8980-0x004a8986` | Reinstalls the base vtable. |
| `PureDefaultFalseBodies` | `0x004a8990-0x004a89e4` | Six source-defined default false bodies reached by Pane thunks; the base vtable still points the six abstract event-family slots to `__purecall`. |
| `ForwardToDispatcherDefault` | `0x004a89f0-0x004a8a09` | Vtable default that forwards two arguments through the global dispatcher helper with a zero flag. |
| `ResetHandlerPairA` | `0x004a8a10-0x004a8a26` | Provisional generated name for a default virtual that zeroes a two-dword position/pair output. |
| `ResetHandlerPairB` | `0x004a8a30-0x004a8a46` | Provisional generated name for the second two-dword position/pair output default. |
| `AlwaysHandleEvent` | `0x004a8a50-0x004a8a52` | Provisional generated name for the always-true predispatch acceptance predicate. |
| `ScalarDeletingDestructor` | `0x004a8a60-0x004a8a84` | Reinstalls vtable and conditionally frees heap storage. |

## Evidence Notes

- 2026-06-04 live IDA MCP identity: `NexusTK.exe` at base `0x400000`, MD5 `4247e04e20b65d6414c7238aa8ff5515`, SHA256 `9aec210bbc5ce592176a21dd8e9d9fd8f250b8d9ea78237915a99ba8cfa9a632`.
- Function lookup confirms the base island: `0x004a8970` size `0x9`, `0x004a8980` size `0x7`, `0x004a89f0` size `0x1a`, `0x004a8a10` size `0x17`, `0x004a8a30` size `0x17`, `0x004a8a50` size `0x3`, and `0x004a8a60` size `0x24`; `0x004a8a84` is padding before the next event-object function at `0x004a8a90`.
- Decompilation confirms the constructor, ordinary destructor, and scalar deleting destructor all write `EventHandler::vftable`; the deleting destructor frees the block only when its low flag bit is set.
- Direct code references are narrow: the constructor is called from `0x0054449d` in `sub_544460`, the ordinary destructor from `0x00544669` in `sub_544580` and `0x00545040` in `sub_544F50`, plus the `0x00605a51` cleanup reference associated with `sub_544460`.
- Vtable data is named `??_7EventHandler@@6B@` at `0x00619674`, with RTTI pointer `0x00647068`; slots map to the scalar deleting destructor at `0x00619674`, six `__purecall` entries at `0x00619678-0x0061968c`, the dispatcher-forwarding default at `0x00619690`, pair-reset defaults at `0x00619694` and `0x00619698`, and the always-true predicate at `0x0061969c`.
- 2026-06-12 A003 Batch322 read-only-data split confirmed [UID:0003I6][0x00619670-0x006196a0.EventHandlerVtableData](by-memory/0x00619670-0x006196a0.EventHandlerVtableData.md) as the exact `EventHandler` COL/vtable child: PE dwords map `0x00619670 -> 0x00647068`, `0x00619674 -> 0x004a8a60`, six `__purecall` slots, defaults at `0x004a89f0`, `0x004a8a10`, `0x004a8a30`, and `0x004a8a50`; MCP xrefs to `0x00619674` are the constructor, ordinary destructor, and scalar deleting destructor paths.
- The source parent remains [UID:0000J7][EventDispatcher](by-file/EventDispatcher.md): the class is a shared UI event-interface type and the parent file is already scored high enough for attachment. B010 now emits the accepted formal interface/declaration route with `[[CHILDREN]]`; exact original virtual names and header factoring remain final-audit caveats.
- 2026-06-17 B001 recheck adds the missing source-defined pure-default false bodies at `0x004a8990-0x004a89e4`. Pane thunks at `0x00544db0-0x00544e00` jump to these bodies, while the abstract base vtable still uses six `__purecall` slots. This supports source-defined default bodies for pure virtual event-family methods rather than padding or Pane-owned code.
- 2026-06-17 B001 LogoPlayerPane input-handler reanalysis validates a derived use of this interface pattern: [UID:0002PV][0x004f55d0-0x004f561d.LogoPlayerPaneInputSkipHandlers](by-memory/0x004f55d0-0x004f561d.LogoPlayerPaneInputSkipHandlers.md) is reached only through secondary vtable slots at `0x0061d074` and `0x0061d078`, receives the EventHandler secondary `this` pointer, subtracts `0xa0` to recover `LogoPlayerPane`, and implements source-authored key and mouse event-family overrides rather than an independent input-handler class.

## Ownership Notes

- [UID:0000A2][Pane](by-class/Pane.md) should document the embedded handler subobject because panes are the common concrete event-handler owners.
- [UID:00004M][EventDispatcher](by-class/EventDispatcher.md) owns handler registration, traversal, modal ordering, and dispatch calls.
- The base `EventHandler` declaration probably lived in a shared UI event header included by both `Pane.cpp` and `EventDispatcher.cpp`. B012 narrows the best header inference to a small `ui/core/EventHandler.h` or EventDispatcher-adjacent event header; `Pane.h` is a weaker placement and should not be treated as the sole owner.

## Open Questions

- Final names for the two pair-zeroing virtuals at `0x004a8a10` and `0x004a8a30`.
- Exact original names for the family virtual slots. The current high-probability families are pointer/mouse, key/text, IME, packet, exact special type `19`, and system/control, based on [UID:00014C][0x004a8ac0-0x004ab3eb.EventManAndEventFactoryHelpers](by-memory/0x004a8ac0-0x004ab3eb.EventManAndEventFactoryHelpers.md) and EventDispatcher routing.
- Exact header factoring remains open, but the current best direction is a shared `EventHandler.h` or EventDispatcher-adjacent event header. `EventDispatcher.h` as a combined event-router header remains possible; `Pane.h` alone is unlikely.
- Formal C++ for [UID:00014A][0x004a8970-0x004a8a84.EventHandlerBase](by-memory/0x004a8970-0x004a8a84.EventHandlerBase.md) now emits the accepted first-draft default bodies. The remaining open items are exact original event-family names, dispatcher-forwarding slot spelling, pair-output type/name spelling, and final header factoring with Pane vtables.

## Score Rationale

- `89/92` reflects the accepted complete interface, owner/emitter route, source-defined defaults, vtable data, Event payload synchronization, producer/cleanup evidence, and now direct dispatcher proof for packet `+0x10`, system/control `+0x14`, and type 19 `+0x18` ordering.
- Original symbols for the descriptive family names, the two pair-output methods, dispatcher-forwarding method, and exact header factoring remain unavailable. Those bounded naming questions cap the score but do not block the formal declaration or source generation.

## Cross-References

- [UID:0000J7][EventDispatcher](by-file/EventDispatcher.md)
- [UID:00004M][EventDispatcher](by-class/EventDispatcher.md)
- [UID:0000A2][Pane](by-class/Pane.md)
- [UID:00014A][0x004a8970-0x004a8a84.EventHandlerBase](by-memory/0x004a8970-0x004a8a84.EventHandlerBase.md)
- [UID:0003I6][0x00619670-0x006196a0.EventHandlerVtableData](by-memory/0x00619670-0x006196a0.EventHandlerVtableData.md)
- [UID:000146][0x004a7cd0-0x004a7df3.EventDispatcherHandlerTreeSupport](by-memory/0x004a7cd0-0x004a7df3.EventDispatcherHandlerTreeSupport.md)
- [UID:0001UF][EventDispatcherHandlerTreeLayouts](by-type/by-struct/EventDispatcherHandlerTreeLayouts.md)

## Changes

- 2026-07-12 B002 accepted UID00014B handler synchronization:
  - Score, owner/emitter metadata, and formal EventHandler interface remained unchanged.
  - Added exact Event layout/variant context, type19/type22 producers, types17/20/21 no-producer caveats, lifecycle/caller/xref relation, packet/notification cleanup semantics, compiler-marker policy, and no-subclass/consumer-owner distinction.

- 2026-06-30 B010 accepted EventDispatcher implementation callback:
  - Before: `COMPLETION:85`, `CONFIDENCE:89`, with EventHandler declaration/body shape still described as coordinated future work.
  - Changed to: `COMPLETION:88`, `CONFIDENCE:91`; owner/emitter unchanged as [UID:0000J7][EventDispatcher](by-file/EventDispatcher.md), and formal `RECONSTRUCTION_CPP` now emits the accepted `EventHandler` interface route, `EventPointPair`, dispatcher forward declarations, and `[[CHILDREN]]`.
  - Evidence: accepted B010 report used IDA MCP session `supervisor_resume_20260629`, EventHandler vtable bytes at `0x00619670`, constructor/destructor/default body ranges at `0x004a8970-0x004a8a84`, and Pane thunk/default-body evidence to promote the previous review draft into formal source.
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
- 2026-06-12 A003 Batch322:
  - Before: scored `82/88`, below the corrected parent gate for exact class vtable-data children.
  - After: scored `85/89`; retained [UID:0000J7][EventDispatcher](by-file/EventDispatcher.md) as source-file parent.
  - Summary/evidence: exact [UID:0003I6][0x00619670-0x006196a0.EventHandlerVtableData](by-memory/0x00619670-0x006196a0.EventHandlerVtableData.md) split now records the COL pointer, full slot map, constructor/destructor/scalar-deleting-destructor xrefs, and boundaries between the EventDispatcher handler-tree support tables and the following Event vtable.
- 2026-06-17 B001 EventHandlerBase source-quality sync:
  - Summary/evidence: added the six source-defined pure-default false bodies and refined generated slot names as provisional. The class score was unchanged in that historical pass; [UID:00014A][0x004a8970-0x004a8a84.EventHandlerBase](by-memory/0x004a8970-0x004a8a84.EventHandlerBase.md) carried the score increase and then-review-only source shape, now superseded by the 2026-06-30 B010 formal implementation callback.
- 2026-06-17 B001 LogoPlayerPane input support sync:
  - Summary/evidence: [UID:0002PV][0x004f55d0-0x004f561d.LogoPlayerPaneInputSkipHandlers](by-memory/0x004f55d0-0x004f561d.LogoPlayerPaneInputSkipHandlers.md) validates another concrete Pane/EventHandler `+0xa0` override family. The class score is unchanged because broad final virtual slot names and header placement remain coordinated UI-core work.
- 2026-06-21 Rule 26 incorporation of B008 EventMan/factory helper report:
  - Score unchanged at `85/89`.
  - Summary/evidence: [UID:00014C][0x004a8ac0-0x004ab3eb.EventManAndEventFactoryHelpers](by-memory/0x004a8ac0-0x004ab3eb.EventManAndEventFactoryHelpers.md) now provides the Event family map that the EventDispatcher/EventHandler interface consumes. The class page now uses pointer/mouse, key/text, IME, packet, special type `19`, and system/control family wording; only exact original method names/header placement remain open.
- 2026-06-21 B012 EventDispatcher class source-quality sync:
  - Score unchanged at `85/89`.
  - Summary/evidence: B012's EventDispatcher reanalysis narrows EventHandler source placement to shared UI event infrastructure routed through [UID:0000J7][EventDispatcher](by-file/EventDispatcher.md), with a high-probability `EventHandler.h` or EventDispatcher-adjacent event header. `Pane.h` remains an include/consumer context for concrete pane handlers, not the sole owner of the base interface.
- 2026-07-13 B001 UID0002EU callback:
  - Raised `88/91` to `89/92` and applied the complete managed interface with packet, system/control, then type-19 declarations in exact `EventDispatcher` `+0x10/+0x14/+0x18` order.
  - Added direct dispatcher, Event layout, concrete ChattingPane secondary-table, and score evidence. Preserved UID0000J7 owner/emitter, all constructor/destructor/default-body and payload synchronization facts, source placement, unrelated declarations, and the bounded exact-name/header caveats.
## FolderSelectDialog Shared RTTI Dependencies R12/R18

These existing EventHandler-owned compiler RTTI records are reached through FolderSelectDialog's inherited DialogPane facet. The records remain external and cause no formal-source change.

| ID | Exact record and fields | Exact xrefs | Ownership boundary |
| --- | --- | --- | --- |
| R12 | `0x6405bc-0x6405d8` BCD: TD `0x6739cc`, contained `0`, PMD `0xa0/-1/0`, attrs `0x40`, CHD `0x6405d8` | `xref_query.total=373`; FolderSelectDialog graph edge `0x647844`; outgoing TD `0x6739cc` and CHD `0x6405d8` | EventHandler-owned compiler RTTI; FolderSelectDialog only references the inherited facet. |
| R18 | `0x6739cc-0x6739e8` TypeDescriptor `??_R0?AVEventHandler@@@8`: vfptr `0x635078`, spare `0`, decorated `.?AVEventHandler@@` | `xref_query.total=4`, including BCD edge `0x6405bc`; outgoing vfptr `0x635078` | EventHandler-owned shared TypeDescriptor; no FolderSelectDialog CPP/H storage. |
