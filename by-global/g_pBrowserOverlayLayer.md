*** UID:0000QD | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:FALSE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# g_pBrowserOverlayLayer

## Status

- Confidence: strong for the current non-browser ownership decision; medium-high for the final source-level name/type.
- Disposition: ignored duplicate/generated alias, not standalone reconstructable storage.
- Current memory evidence: [UID:0001PG][0x0069b374-0x0069b378.g_layoutContext_69B374](by-memory/0x0069b374-0x0069b378.g_layoutContext_69B374.md), IDA `dword_69B374`.
- Proposed owner: shared UI layout/screen context; [UID:0000HV][Browser](by-file/Browser.md) is a consumer only.
- Replacement owner: [UID:0000T6][MainUiLayerSlots](by-global/MainUiLayerSlots.md) under [UID:0000L1][MainUiGraph](by-file/MainUiGraph.md).

## Observed Evidence

`BrowserControlPane::SyncBrowserWindowBounds` passes this alias to `Pane::UpdateLayout`, then uses the same layer in `Layer::MapControlPoint` before mapping browser pane coordinates into screen coordinates and moving the hosted browser window. IDA resolves the alias to `dword_69B374`.

[UID:0001PG][0x0069b374-0x0069b378.g_layoutContext_69B374](by-memory/0x0069b374-0x0069b378.g_layoutContext_69B374.md) now records the stronger exact evidence: 13 xrefs across 8 functions, startup allocation at `0x004f62c6`, initialization at `0x004f635e`, shutdown release/clear at `0x004f64dd` / `0x004f65c8`, and representative browser/alert/layout consumers.

The exact backing storage page also records clean neighboring boundaries: the unreferenced `0x0069b370-0x0069b374` dword before this slot, the following [UID:00029O][0x0069b378-0x0069b380.MainUiLayerSlotsTail](by-memory/0x0069b378-0x0069b380.MainUiLayerSlotsTail.md) pair, and the byte-sized active-dialog counter at `0x0069b380`. That boundary evidence resolves this page as a generated alias over one member of the main UI layer slot family, not as browser-owned pointer storage.

## Ownership Hypothesis

This is the layout/context reference used to position the embedded browser window over the normal pane/layout system. It is not browser-specific storage: IDA xrefs also include browser dialog construction, alert-pane construction, startup/main-menu UI helpers, and the startup/shutdown layer-slot lifecycle. The storage belongs with [UID:0000L1][MainUiGraph](by-file/MainUiGraph.md) / [UID:0000T6][MainUiLayerSlots](by-global/MainUiLayerSlots.md); this page records the browser-facing alias and should stay in the ignored global-symbol ledger.

## Type Hypothesis

Keep the exact type provisional until `Layer` ownership and storage xrefs are reviewed. Do not emit this under the `g_pBrowserOverlayLayer` name as a browser-owned global unless a later pass proves the original declaration.

## Autogen Status

Keep `RECONSTRUCTABLE:FALSE` on this alias page. The actual reconstructable source storage is documented and attached on [UID:0001PG][0x0069b374-0x0069b378.g_layoutContext_69B374](by-memory/0x0069b374-0x0069b378.g_layoutContext_69B374.md); this page should not create duplicate browser-owned C++.

## Score Rationale

| Score | Rationale |
| --- | --- |
| Completion `86` | The page records the alias, browser consumer behavior, exact backing storage, 13-ref lifecycle evidence through the memory page, neighboring-slot separation, non-browser ownership decision, ignored-ledger disposition, replacement owner, type caveat, and no-autogen handling. Completion remains capped because the final source-level type/name for the real layer/context object is unresolved. |
| Confidence `90` | Existing IDA-backed evidence strongly supports the alias-to-`dword_69B374` mapping and MainUiGraph/MainUiLayerSlots ownership, and the duplicate-alias disposition is now consistent with the exact backing storage page, [UID:0000HV][Browser](by-file/Browser.md), and [UID:0000T6][MainUiLayerSlots](by-global/MainUiLayerSlots.md). |

## Cross-References

- [UID:0000HV][Browser](by-file/Browser.md)
- [UID:000015][BrowserControlPane](by-class/BrowserControlPane.md)
- [UID:0001PG][0x0069b374-0x0069b378.g_layoutContext_69B374](by-memory/0x0069b374-0x0069b378.g_layoutContext_69B374.md)
- [UID:0000Z6][0x0046b520-0x0046cfe0.BrowserControlPaneCore](by-memory/0x0046b520-0x0046cfe0.BrowserControlPaneCore.md)
- [UID:0000L1][MainUiGraph](by-file/MainUiGraph.md)
- [UID:0000T6][MainUiLayerSlots](by-global/MainUiLayerSlots.md)
- [UID:00029O][0x0069b378-0x0069b380.MainUiLayerSlotsTail](by-memory/0x0069b378-0x0069b380.MainUiLayerSlotsTail.md)

## Changes

- 2026-06-02:
  - Before: scored `74/68` and described the browser overlay-layer role with only medium confidence.
  - After: scored `78/84`, clarified this as a browser-facing alias over shared `dword_69B374` layout-context storage, and added no-autogen rationale.
  - Why: the exact memory page now records strong IDA-backed xrefs, startup/shutdown lifecycle, neighboring slot context, and representative browser/alert consumers that prove shared UI layout ownership.
- Completion/confidence scoring: existed before as ungraded `0/0`; changed to `74/68`. Summary/evidence: the page documents browser use, IDA resolution to `dword_69B374`, layout-context ownership hypothesis, and type caveats, but final owner/type/name still need a broader layout/global pass.
- 2026-06-05: Marked not reconstructable as a duplicate alias page. Evidence: live IDA MCP reports xrefs to `0x0069b374` from browser, alert, startup, and main-menu layout paths; the reconstructable shared storage is already documented through [UID:0001PG][0x0069b374-0x0069b378.g_layoutContext_69B374](by-memory/0x0069b374-0x0069b378.g_layoutContext_69B374.md) and [UID:0000T6][MainUiLayerSlots](by-global/MainUiLayerSlots.md).
- 2026-06-06: Raised completion/confidence from `78/84` to `86/90` and synchronized the ignored-global disposition.
  - Evidence: [UID:0001PG][0x0069b374-0x0069b378.g_layoutContext_69B374](by-memory/0x0069b374-0x0069b378.g_layoutContext_69B374.md) now documents exact 13-ref lifecycle evidence, startup/shutdown ownership, browser/alert/layout consumers, and neighboring slot boundaries; [UID:0000HV][Browser](by-file/Browser.md) explicitly treats `g_pBrowserOverlayLayer` as a Browser consumer alias; [UID:0000T6][MainUiLayerSlots](by-global/MainUiLayerSlots.md) owns the real slot family.
