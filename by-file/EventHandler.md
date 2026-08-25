*** UID:0004ZN | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:89 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"NexusTK/ui/core/" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:FILE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***

# EventHandler

## Status

- Proposed module: `NexusTK/ui/core/EventHandler.h` and `NexusTK/ui/core/EventHandler.cpp`.
- Confidence: strong for the separate shared-header route, complete interface, class/body ownership, dispatcher dependency, Pane consumers, and source-generated vtable consequences; source-facing virtual spellings remain inferred from exact slot behavior.
- Primary class: [UID:00004N][EventHandler](by-class/EventHandler.md).
- Exact body island: [UID:00014A][0x004a8970-0x004a8a84.EventHandlerBase](by-memory/0x004a8970-0x004a8a84.EventHandlerBase.md).

## File Role

`EventHandler.h` owns the complete four-byte abstract event-handler interface shared by Pane and EventDispatcher. It includes `RectBounds.h` for the shared eight-byte `Point` output type, forward-declares `Event` and `EventDispatcher`, and declares `g_pEventDispatcher`.

`EventHandler.cpp` includes both `EventHandler.h` and the complete `EventDispatcher.h`, then receives exact constructor/destructor/default-body definitions through the EventHandler class emitter. This makes `ForwardHandlerOrder`'s dispatcher member call legal without a partial duplicate EventDispatcher declaration.

## Header Contract

- Six event-family virtuals stay abstract while their compiler-addressed pure-function definitions remain exact source bodies on UID00014A.
- The concrete defaults are `ForwardHandlerOrder`, `GetLocalOffset(Point *)`, `GetScreenOffset(Point *)`, and `ShouldAcceptEvent() const`.
- `EventHandlerSizeMustBe4` records the one-vptr, fieldless layout.
- Historical `EventPointPair`, `GetLocalEventPair`, and `GetScreenEventPair` spellings are superseded. The project-wide shared value type is `Point { int y; int x; }`, and both defaults zero that same two-int output.

## Source And Ownership Boundaries

- [UID:00004N][EventHandler](by-class/EventHandler.md) owns the declaration and routes exact bodies here.
- [UID:00014A][0x004a8970-0x004a8a84.EventHandlerBase](by-memory/0x004a8970-0x004a8a84.EventHandlerBase.md) owns exact body bytes and must not be duplicated on this by-file page.
- [UID:0000J7][EventDispatcher](by-file/EventDispatcher.md) owns dispatcher declarations and routing implementation, not this base interface.
- [UID:0000MC][Pane](by-file/Pane.md) consumes the interface through inheritance; Pane is not the declaration owner.
- EventHandler vtable/RTTI data is compiler-generated from this declaration and remains covered by its exact by-memory/vtable documentation.

## Rejected Alternatives

- A combined declaration owned only by `EventDispatcher.h` is rejected because Pane needs the abstract interface without dispatcher storage.
- A Pane-owned declaration is rejected because EventDispatcher and non-Pane handlers also consume it.
- A PCH-only declaration, partial EventDispatcher redeclaration, CPP-local `EventPointPair`, and duplicate raw vtable table are rejected as incomplete, conflicting, or non-source-authored routes.

## Implementation Contract

The class CPP formal must be:

```cpp
#include "EventHandler.h"
#include "EventDispatcher.h"

[[CHILDREN]]
```

The class H formal contains the complete interface documented above. Exact child bodies remain ordered by their physical source positions through the emitter route.

## Historical Assumptions

- Earlier documentation routed EventHandler directly through [UID:0000J7][EventDispatcher](by-file/EventDispatcher.md) and left the exact header split open. UID000090 dependency research resolves the separate `EventHandler.h/.cpp` route needed by Pane and EventDispatcher.
- Earlier formals used `EventPointPair` and pair-oriented method names. Those remain search history only after the shared Point contract and Pane override mapping resolved the source-facing offset vocabulary.

## Cross-References

- [UID:00004N][EventHandler](by-class/EventHandler.md)
- [UID:00014A][0x004a8970-0x004a8a84.EventHandlerBase](by-memory/0x004a8970-0x004a8a84.EventHandlerBase.md)
- [UID:00004M][EventDispatcher](by-class/EventDispatcher.md)
- [UID:0000J7][EventDispatcher](by-file/EventDispatcher.md)
- [UID:0000A2][Pane](by-class/Pane.md)
- [UID:0000MC][Pane](by-file/Pane.md)
