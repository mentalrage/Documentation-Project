*** UID:0004VE | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000L1 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000L1 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL:40 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
class Layer;

Layer *g_pLayoutPaneLayer = 0;
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

*** Item Summary: Sole externally linked zero-initialized Layer pointer definition for the shared Browser/alert layout layer in NexusTK/ui/MainUiGraph.cpp at position 40, backed by UID0001PG and 13 exact refs; local forward declaration plus module definition only, with shared-header extern placement documented separately and no Browser-owned duplicate. | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***

# g_pLayoutPaneLayer

## Status

- Disposition: reconstructable source-level global definition.
- Type: `Layer *`.
- Linkage and initialization: external linkage, explicitly initialized to `0`.
- Source owner and route: [UID:0000L1][MainUiGraph](by-file/MainUiGraph.md), emitted at position 40 into `NexusTK/ui/MainUiGraph.cpp`.
- Physical backing: [UID:0001PG][0x0069b374-0x0069b378.g_layoutContext_69B374](by-memory/0x0069b374-0x0069b378.g_layoutContext_69B374.md).
- Confidence: very strong for the pointer type, independent-global source shape, lifetime, source route, and consumer set; exact source spelling remains inferred because debug symbols do not survive.

## Exact Storage And Initialization

- The physical cell is `[0x0069b374,0x0069b378)`, four bytes in the `.data` virtual tail beyond the raw-backed end at VA `0x0067a800`.
- IDA returns four zero bytes and the PE mapping proves loader-zero/BSS semantics. Historical `0xffffffff` initialization claims are superseded.
- The cell is independent of the provisional head triplet at `0x0069b364/368/36c`: `0x0069b370-0x0069b374` is an unreferenced dword between them.

## Complete Reference Inventory

The physical cell has exactly 13 direct references:

- Browser/layout consumers: `0x0046abd6`, `0x0046acb0`, `0x0046c4b7`, `0x0046c4df`, `0x0046d263`, `0x0046e460`, and `0x0046e80d`.
- Alert/dialog placement: `0x004a03ff`.
- Application startup publication and registration: `0x004f62c6`, `0x004f6356` (with the registration call at `0x004f635e`).
- Application shutdown detach, delete load, and clear: `0x004f64d1`, `0x004f65b8`, and `0x004f65c8`.

The Browser and alert references prove shared layout use rather than Browser ownership. No other direct reference, pointer table, loop, or aggregate-member access was found.

## Lifetime And Behavior

- `Application::Startup` allocates one `Layer`, stores it in `g_pLayoutPaneLayer`, and registers it with `ScreenPane::SetLayerFrame` in the same six-layer runtime order as the three retained head slots and the status/IME globals.
- `Application::Shutdown` detaches this layer, later deletes it, and writes `NULL` back to the global. The ordering is behaviorally significant and is documented on the startup/shutdown memory pages.
- Browser panes use it for layout attachment, browser-window coordinate mapping, and hosted-window placement. Alert/dialog placement also uses it.

## Ownership And Source Placement

This is module-level UI graph state, not a Browser field, class static, aggregate tail member, or compiler artifact. MainUiGraph is the narrowest source root shared by all consumers and already owns the UI graph definitions. Application owns runtime creation/destruction but not the declaration. Consumer translation units require a separate shared-header `extern Layer *g_pLayoutPaneLayer;`; that declaration is documented as header placement and is intentionally not duplicated inside this `.cpp` definition block.

## Rejected Alternatives And Historical Assumptions

- `g_pBrowserOverlayLayer` is a stale Browser-facing alias. Browser is only one consumer family and does not own publication or destruction.
- `layoutPaneLayerContext` was a useful earlier inferred field name, but the no-reference gap and independent lifecycle access disprove membership in one six-field `MainUiLayerSlots` aggregate.
- Raw labels such as `dword_69B374`, opaque context names, raw-address accessors, or duplicate alias definitions are not source-quality C++.
- The physical backing page is non-emitting. This semantic page supplies the sole definition, preventing duplicate storage in generated output.

## Reconstruction And Generated Output

The managed block is the complete module definition: a local forward declaration followed by `Layer *g_pLayoutPaneLayer = 0;`. Generated `MainUiGraph.cpp` must contain exactly one definition at position 40 and no separate UID0001PG empty marker. Header `extern` placement remains a separate declaration concern and is not emitted in this source block.

## Cross-References

- [UID:0000L1][MainUiGraph](by-file/MainUiGraph.md)
- [UID:0001PG][0x0069b374-0x0069b378.g_layoutContext_69B374](by-memory/0x0069b374-0x0069b378.g_layoutContext_69B374.md)
- [UID:0002H7][0x004f5fb0-0x004f6490.BaramAppStartup](by-memory/0x004f5fb0-0x004f6490.BaramAppStartup.md)
- [UID:0002H8][0x004f6490-0x004f66a5.BaramAppShutdown](by-memory/0x004f6490-0x004f66a5.BaramAppShutdown.md)
- [UID:0000QD][g_pBrowserOverlayLayer](by-global/g_pBrowserOverlayLayer.md)

## Score Rationale

- Completion `92`: exact bytes, boundary, all 13 references, type, lifetime, ownership, linkage, initializer, source route/order, one-definition policy, formal C++, and rejected alternatives are documented.
- Confidence `94`: binary behavior and source shape are independently resolved; only the exact original lexical spelling lacks symbol proof.
