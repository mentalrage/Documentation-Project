*** UID:0000QD | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:78 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# g_pBrowserOverlayLayer

## Status

- Confidence: strong for the current non-browser ownership decision; medium-high for the final source-level name/type.
- Current Wave3 kind: `global-data`.
- Current generated owner file: `class_BrowserControlPane.cpp`.
- Current memory evidence: [UID:0001PG][0x0069b374-0x0069b378.g_layoutContext_69B374](by-memory/0x0069b374-0x0069b378.g_layoutContext_69B374.md), IDA `dword_69B374`.
- Proposed owner: shared UI layout/screen context; [UID:0000HV][Browser](by-file/Browser.md) is a consumer only.

## Observed Evidence

Generated `BrowserControlPane::SyncBrowserWindowBounds` passes `g_pBrowserOverlayLayer` to `Pane::UpdateLayout`, then uses the same layer in `Layer::MapControlPoint` before mapping browser pane coordinates into screen coordinates and moving the hosted browser window. IDA resolves this generated name to `dword_69B374`.

[UID:0001PG][0x0069b374-0x0069b378.g_layoutContext_69B374](by-memory/0x0069b374-0x0069b378.g_layoutContext_69B374.md) now records the stronger exact evidence: 13 xrefs across 8 functions, startup allocation at `0x004f62c6`, initialization at `0x004f635e`, shutdown release/clear at `0x004f64dd` / `0x004f65c8`, and representative browser/alert/layout consumers.

## Ownership Hypothesis

This is the layout/context reference used to position the embedded browser window over the normal pane/layout system. It is not browser-specific storage: IDA xrefs also include browser dialog construction, alert-pane construction, startup/main-menu UI helpers, and the startup/shutdown layer-slot lifecycle. The storage belongs with [UID:0000L1][MainUiGraph](by-file/MainUiGraph.md) / [UID:0000T6][MainUiLayerSlots](by-global/MainUiLayerSlots.md); this page records the generated browser-facing alias.

## Type Hypothesis

Keep the exact type provisional until `Layer` ownership and storage xrefs are reviewed. Do not emit this under the generated `g_pBrowserOverlayLayer` name as a browser-owned global unless a later pass proves the original declaration.

## Autogen Status

Leave reconstruction metadata blank on this alias page. The actual reconstructable source storage is documented and attached on [UID:0001PG][0x0069b374-0x0069b378.g_layoutContext_69B374](by-memory/0x0069b374-0x0069b378.g_layoutContext_69B374.md); this page should not create duplicate browser-owned C++.

## Score Rationale

| Score | Rationale |
| --- | --- |
| Completion `78` | The page now records the generated alias, browser consumer behavior, exact backing storage, stronger xref/lifecycle evidence through the memory page, non-browser ownership decision, type caveat, and no-autogen handling. Completion remains capped because the final source-level type/name for the layer/context object is unresolved. |
| Confidence `84` | Existing IDA-backed evidence strongly supports the alias-to-`dword_69B374` mapping and MainUiGraph/MainUiLayerSlots ownership. Confidence is not higher because the final original declaration name and pointed-to class type remain provisional. |

## Cross-References

- [UID:0000HV][Browser](by-file/Browser.md)
- [UID:000015][BrowserControlPane](by-class/BrowserControlPane.md)
- [UID:0001PG][0x0069b374-0x0069b378.g_layoutContext_69B374](by-memory/0x0069b374-0x0069b378.g_layoutContext_69B374.md)
- [UID:0000Z6][0x0046b520-0x0046cfe0.BrowserControlPaneCore](by-memory/0x0046b520-0x0046cfe0.BrowserControlPaneCore.md)
- [UID:0000L1][MainUiGraph](by-file/MainUiGraph.md)
- [UID:0000T6][MainUiLayerSlots](by-global/MainUiLayerSlots.md)

## Changes

- 2026-06-02:
  - Before: scored `74/68` and described the browser overlay-layer role with only medium confidence.
  - After: scored `78/84`, clarified this as a generated browser-facing alias over shared `dword_69B374` layout-context storage, and added no-autogen rationale.
  - Why: the exact memory page now records strong IDA-backed xrefs, startup/shutdown lifecycle, neighboring slot context, and representative browser/alert consumers that prove shared UI layout ownership.
- Completion/confidence scoring: existed before as ungraded `0/0`; changed to `74/68`. Summary/evidence: the page documents generated browser use, IDA resolution to `dword_69B374`, layout-context ownership hypothesis, and type caveats, but final owner/type/name still need a broader layout/global pass.
