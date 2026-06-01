*** UID:0000QD | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:74 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:68 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# g_pBrowserOverlayLayer

## Status

- Confidence: medium for browser overlay layer role.
- Current Wave3 kind: `global-data`.
- Current generated owner file: `class_BrowserControlPane.cpp`.
- Current memory evidence: [UID:0001PG][0x0069b374-0x0069b378.g_layoutContext_69B374](by-memory/0x0069b374-0x0069b378.g_layoutContext_69B374.md), IDA `dword_69B374`.
- Proposed owner: shared UI layout/screen context; [UID:0000HV][Browser](by-file/Browser.md) is a consumer only.

## Observed Evidence

Generated `BrowserControlPane::SyncBrowserWindowBounds` passes `g_pBrowserOverlayLayer` to `Pane::UpdateLayout`, then uses the same layer in `Layer::MapControlPoint` before mapping browser pane coordinates into screen coordinates and moving the hosted browser window. IDA resolves this generated name to `dword_69B374`.

## Ownership Hypothesis

This is the layout/context reference used to position the embedded browser window over the normal pane/layout system. It is not browser-specific storage: IDA xrefs also include browser dialog construction, alert-pane construction, and startup/main-menu UI helpers.

## Type Hypothesis

Provisional declaration:

```cpp
extern void* g_layoutContext_69B374;
```

Keep the exact type provisional until `Layer` ownership and storage xrefs are reviewed. Do not emit this under the generated `g_pBrowserOverlayLayer` name as a browser-owned global unless a later pass proves the original declaration.

## Cross-References

- [UID:0000HV][Browser](by-file/Browser.md)
- [UID:000015][BrowserControlPane](by-class/BrowserControlPane.md)
- [UID:0001PG][0x0069b374-0x0069b378.g_layoutContext_69B374](by-memory/0x0069b374-0x0069b378.g_layoutContext_69B374.md)
- [UID:0000Z6][0x0046b520-0x0046cfe0.BrowserControlPaneCore](by-memory/0x0046b520-0x0046cfe0.BrowserControlPaneCore.md)

## Changes

- Completion/confidence scoring: existed before as ungraded `0/0`; changed to `74/68`. Summary/evidence: the page documents generated browser use, IDA resolution to `dword_69B374`, layout-context ownership hypothesis, and type caveats, but final owner/type/name still need a broader layout/global pass.
