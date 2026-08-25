*** UID:0004VG | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000L1 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000L1 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL:60 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
class Layer;

Layer *g_pIMEPaneLayer = 0;
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
class Layer;

extern Layer *g_pIMEPaneLayer;
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

*** Item Summary: Sole externally linked zero-initialized Layer pointer definition for IME status/composition/candidate panes in NexusTK/ui/MainUiGraph.cpp at position 60, backed by the exact 0x0069b37c child and 11 refs; formal MainUiGraph.h forward/extern declaration supports incidental FpsPane reuse without transferring ownership. | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***

# g_pIMEPaneLayer

## Status

- Disposition: reconstructable source-level global definition.
- Type: `Layer *`.
- Linkage and initialization: external linkage, explicitly initialized to `0`.
- Source owner and route: [UID:0000L1][MainUiGraph](by-file/MainUiGraph.md), emitted at position 60 into `NexusTK/ui/MainUiGraph.cpp`.
- Physical backing: exact loader-zero cell `[0x0069b37c,0x0069b380)` documented by `by-memory/0x0069b37c-0x0069b380.g_pIMEPaneLayerStorage.md`.
- Confidence: very strong for type, independent-global shape, lifetime, ownership, and dominant IME role; exact spelling remains inferred.

## Exact Storage And Initialization

- The physical cell is the second four-byte half of [UID:00029O][0x0069b378-0x0069b380.MainUiLayerSlotsTail](by-memory/0x0069b378-0x0069b380.MainUiLayerSlotsTail.md).
- IDA returns four zero bytes and PE section bounds prove loader-zero `.data` virtual-tail storage. Historical `0xffffffff` wording is superseded.
- Its independent startup/shutdown operands and IME-dominant consumer set separate it from the status cell at `0x0069b378`, the layout cell at `0x0069b374`, and the provisional head triplet.

## Complete Reference Inventory

The cell has exactly 11 direct references:

- IMEStatusPane construction: `0x004e724e`.
- IMECompositionPane construction: `0x004e7416`.
- IMECandidatePane construction: `0x004e7c2c`.
- Root IME dispatcher inline composition/candidate construction: `0x004e8281` and `0x004e8377`.
- Application startup store, registration operand, and registration call: `0x004f632c`, `0x004f6374`, `0x004f637c`.
- Application shutdown detach, load/delete, and clear: `0x004f6515`, `0x004f6536`, `0x004f6546`.
- FpsPane diagnostic/log-session reuse: `0x004b65ff`.

The five IME consumer refs across constructors/root dispatch dominate the one incidental FpsPane ref. No other direct reference, aggregate-member loop, or owner publication path was found.

## Lifetime And Consumer Semantics

- `Application::Startup` allocates and registers the layer after the status layer.
- `Application::Shutdown` detaches it, deletes it before the status/head/layout objects in the observed cleanup sequence, and clears it to `NULL`.
- IME status, composition, and candidate panes attach to this layer. The root handler has two inline-equivalent construction paths using the same cell.
- FpsPane reuses the IME layer as a frame parent for its diagnostic pane; that single consumer does not transfer declaration ownership or justify a Fps-specific symbol.

## Ownership And Source Placement

MainUiGraph is the common module-level source root. Application owns runtime lifetime; IME and Fps classes are consumers. A shared header must separately declare `extern Layer *g_pIMEPaneLayer;`; the `.cpp` managed block intentionally contains only a local forward declaration and the sole definition.

## Rejected Alternatives And Historical Assumptions

- `fpsOverlayLayerContext` and `g_pFpsPaneParentPane` are consumer-biased stale aliases disproved by the complete 10-to-1 lifecycle/IME-versus-Fps partition.
- Treating the slot as the sixth field of `MainUiLayerSlots` is contradicted by the no-reference gap and independent source use.
- Raw `dword_69B37C`, raw offsets, duplicate definitions, fake gap members, and compiler/decompiler scaffolding are excluded.
- The physical backing is non-emitting; this semantic page supplies the sole source definition.

## Reconstruction And Generated Output

The managed block is the complete sole module definition. Generated `MainUiGraph.cpp` must contain exactly one `g_pIMEPaneLayer` definition at position 60. IMEPanes output must contain the three source-ready constructor uses; FpsPane output contains one incidental use; the physical parent/child pages emit no marker or duplicate definition.

## Cross-References

- [UID:0000L1][MainUiGraph](by-file/MainUiGraph.md)
- [UID:00029O][0x0069b378-0x0069b380.MainUiLayerSlotsTail](by-memory/0x0069b378-0x0069b380.MainUiLayerSlotsTail.md)
- [UID:0002H7][0x004f5fb0-0x004f6490.BaramAppStartup](by-memory/0x004f5fb0-0x004f6490.BaramAppStartup.md)
- [UID:0002H8][0x004f6490-0x004f66a5.BaramAppShutdown](by-memory/0x004f6490-0x004f66a5.BaramAppShutdown.md)
- [UID:0004BX][0x004e71c0-0x004e728a.IMEStatusPaneConstructor](by-memory/0x004e71c0-0x004e728a.IMEStatusPaneConstructor.md)
- [UID:0004C1][0x004e7380-0x004e744d.IMECompositionPaneConstructor](by-memory/0x004e7380-0x004e744d.IMECompositionPaneConstructor.md)
- [UID:0004C7][0x004e7b70-0x004e7cae.IMECandidatePaneConstructor](by-memory/0x004e7b70-0x004e7cae.IMECandidatePaneConstructor.md)
- [UID:00015F][0x004b64a0-0x004b67a7.FpsPaneUpdateFpsLogSessionRaw](by-memory/0x004b64a0-0x004b67a7.FpsPaneUpdateFpsLogSessionRaw.md)

## Score Rationale

- Completion `92`: exact bytes, split boundary, all 11 references, type, lifetime, ownership, linkage, initializer, source route/order, formal definition, generated assertions, and rejected aliases are documented.
- Confidence `94`: direct binary behavior resolves the source shape and IME role; only exact original lexical spelling lacks symbol proof.

## 2026-08-24 Accepted Header Route

- The formal CPP block remains the sole `Layer *g_pIMEPaneLayer = 0;` definition at MainUiGraph source position 60.
- The formal H block now supplies exactly `class Layer;` and `extern Layer *g_pIMEPaneLayer;`, allowing FpsPane and IME consumers to include `MainUiGraph.h` without a duplicate definition.
- UID0000L1 remains the owner. FpsPane's single frame-parent use is a consumer relationship and does not move or rename the global.
