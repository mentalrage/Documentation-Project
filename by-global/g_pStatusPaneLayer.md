*** UID:0004VF | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000L1 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000L1 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL:50 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
class Layer;

Layer *g_pStatusPaneLayer = 0;
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
class Layer;

extern Layer *g_pStatusPaneLayer;
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

*** Item Summary: Sole externally linked zero-initialized Layer pointer definition for the shared status/transient system-pane layer in NexusTK/ui/MainUiGraph.cpp at position 50, backed by the exact 0x0069b378 child and 14 refs; local forward declaration plus module definition only, with shared-header extern placement documented separately. | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***

# g_pStatusPaneLayer

## Status

- Disposition: reconstructable source-level global definition.
- Type: `Layer *`.
- Linkage and initialization: external linkage, explicitly initialized to `0`.
- Source owner and route: [UID:0000L1][MainUiGraph](by-file/MainUiGraph.md), emitted at position 50 into `NexusTK/ui/MainUiGraph.cpp`.
- Physical backing: exact loader-zero cell `[0x0069b378,0x0069b37c)` documented by `by-memory/0x0069b378-0x0069b37c.g_pStatusPaneLayerStorage.md`.
- Confidence: very strong for type, independent-global shape, lifetime, source route, and complete consumer inventory; exact spelling remains inferred.

## Exact Storage And Initialization

- The physical cell is the first four-byte half of [UID:00029O][0x0069b378-0x0069b380.MainUiLayerSlotsTail](by-memory/0x0069b378-0x0069b380.MainUiLayerSlotsTail.md).
- IDA returns four zero bytes and PE section bounds prove loader-zero `.data` virtual-tail storage rather than historical `0xffffffff` initialization.
- The adjacent `0x0069b370` no-reference gap, independent layout cell at `0x0069b374`, and independently consumed IME cell at `0x0069b37c` disprove one six-field aggregate.

## Complete Reference Inventory

The cell has exactly 14 direct references:

- HelpPane construction: `0x004c6c5d`.
- Application startup store, registration operand, and registration call: `0x004f62f5`, `0x004f6365`, `0x004f636d`.
- Application shutdown detach, load/delete, and clear: `0x004f64c6`, `0x004f6550`, `0x004f6560`.
- HistoryViewingPane construction: `0x004ffe73`.
- ScreenDimmer construction: `0x00559c3d`, `0x00559c7e`, and `0x00559c9a`.
- ScreenFadeOut construction: `0x00559f2a`.
- TimerPane construction: `0x005987c4`.
- UserPane server-message InputBlocker construction: `0x005a7d90`.
- Independent InputBlocker helper path: `0x005abd49`.

No additional direct ref, pointer table, loop, or aggregate-member access was found.

## Lifetime And Consumer Semantics

- `Application::Startup` allocates a `Layer`, stores it here, and registers it with the screen pane after the layout layer and before the IME layer.
- `Application::Shutdown` detaches it, later deletes it, and clears the pointer to `NULL` while preserving the original six-layer teardown order.
- HelpPane, HistoryViewingPane, ScreenDimmer, ScreenFadeOut, TimerPane, and two InputBlocker paths attach transient/status/system panes to this layer.
- The broad consumer union rejects `modalPaneLayer`, `transientPaneLayer`, or `g_pMainUiLayer` as narrower or overbroad names. `g_pStatusPaneLayer` best matches current source vocabulary without transferring ownership to any consumer.

## Ownership And Source Placement

MainUiGraph is the common module-level source root. Application controls runtime lifetime but does not own the declaration, and no consumer class owns publication or clearing. A shared header must separately declare `extern Layer *g_pStatusPaneLayer;`; the `.cpp` managed block intentionally contains only a local forward declaration and the sole definition.

## Rejected Alternatives And Historical Assumptions

- `statusPaneLayerContext` was a useful evidence-time inferred aggregate field but is superseded by the independent-global proof.
- `g_pMainUiLayer` is a stale History-specific alias and is too broad for the status/transient consumer set.
- Modal-only and InputBlocker-owned alternatives fail because non-modal Help, History, dimmer, fade, and timer consumers use the same cell.
- Raw labels, raw offsets, fake gap fields, duplicate storage declarations, and compiler lowering are excluded from source C++.

## Reconstruction And Generated Output

The managed block is the complete sole module definition. Generated `MainUiGraph.cpp` must contain exactly one `g_pStatusPaneLayer` definition at position 50 and no parent or physical-cell empty marker. Application and all source-ready consumers use the same external symbol.

## Cross-References

- [UID:0000L1][MainUiGraph](by-file/MainUiGraph.md)
- [UID:00029O][0x0069b378-0x0069b380.MainUiLayerSlotsTail](by-memory/0x0069b378-0x0069b380.MainUiLayerSlotsTail.md)
- [UID:0002H7][0x004f5fb0-0x004f6490.BaramAppStartup](by-memory/0x004f5fb0-0x004f6490.BaramAppStartup.md)
- [UID:0002H8][0x004f6490-0x004f66a5.BaramAppShutdown](by-memory/0x004f6490-0x004f66a5.BaramAppShutdown.md)
- [UID:0001A1][0x004ffd80-0x0050008b.HistoryViewingPaneCore](by-memory/0x004ffd80-0x0050008b.HistoryViewingPaneCore.md)
- [UID:000392][0x00559b90-0x00559ce6.ScreenDimmerConstructor](by-memory/0x00559b90-0x00559ce6.ScreenDimmerConstructor.md)
- [UID:0004MG][0x005986e0-0x00598841.TimerPaneConstructor](by-memory/0x005986e0-0x00598841.TimerPaneConstructor.md)

## Score Rationale

- Completion `92`: exact bytes, split boundary, all 14 references, type, lifetime, source ownership, linkage, initializer, source route/order, no-code backing, formal definition, and rejected alternatives are recorded.
- Confidence `94`: direct binary behavior resolves every structural blocker; only original lexical spelling lacks symbol proof.

## 2026-08-16 HistoryViewingPane Header Consumer Closure

- Formal H now exposes `extern Layer *g_pStatusPaneLayer;` through the UID0000L1 `MainUiGraph.h` route. The sole definition remains this page's CPP block at position `50`; physical backing [UID:0004VH][0x0069b378-0x0069b37c.g_pStatusPaneLayerStorage](by-memory/0x0069b378-0x0069b37c.g_pStatusPaneLayerStorage.md) stays blank and non-emitting.
- HistoryViewingPane consumes this exact global at `0x004ffe1d` to attach its full-screen bounds. `g_pMainUiLayer`, modal-layer, and transient-layer aliases remain rejected; no declaration or storage moves to the consumer.
- The local `class Layer;` forward declaration makes this independent H fragment compile-visible regardless of sibling emitter order; it does not redefine or own Layer.
