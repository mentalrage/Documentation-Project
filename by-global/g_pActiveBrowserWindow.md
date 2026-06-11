*** UID:0000Q6 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000HV | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# g_pActiveBrowserWindow

## Status

- Confidence: strong for active browser-window singleton role and exact storage, medium-high for final linkage/type spelling.
- Current Wave3 kind: `global-data`.
- Current generated owner file: `class_BrowserWindow.cpp`.
- IDA storage: [UID:0002T5][0x0067ab94-0x0067ab98.g_pActiveBrowserWindow](by-memory/0x0067ab94-0x0067ab98.g_pActiveBrowserWindow.md) (`dword_67AB94` / `DAT_0067ab94` in generated variants).
- Proposed owner: [UID:0000HV][Browser](by-file/Browser.md).

## Observed Evidence

Generated `BrowserWindow::BrowserWindow` assigns `g_pActiveBrowserWindow = this` after entering the constructor and before installing the browser host COM vtables. Generated `BrowserWindow::~BrowserWindow` clears the same pointer after releasing the browser interface.

The active window sits in the same static browser data neighborhood as `g_pBrowserDialogOld`, `g_pBrowserThread`, and `g_pCurrentBrowserHost`.

The exact storage child [UID:0002T5][0x0067ab94-0x0067ab98.g_pActiveBrowserWindow](by-memory/0x0067ab94-0x0067ab98.g_pActiveBrowserWindow.md) records the aggregate IDA evidence for `dword_67AB94`, the `BrowserWindow` constructor/destructor ownership trail, and the accelerator helper that reads this slot before querying the active browser object.

A004 live IDA MCP on 2026-06-07 reconfirmed the storage child as an initialized four-byte `.data` slot with 5 refs across 4 functions: constructor/set refs at `0x004696a3` and `0x004696aa`, lifetime ref at `0x00469a71`, accelerator-helper read at `0x0046a535`, and cleanup clear at `0x00470240`.

## Ownership Hypothesis

This is browser module state for the currently constructed or active embedded browser host window. It should migrate with `BrowserWindow` in `browser/Browser.cpp` or a split `browser/BrowserWindow.cpp`.

## Type Hypothesis

Likely declaration:

```cpp
static BrowserWindow* g_pActiveBrowserWindow;
```

Keep `static` provisional until linkage is reviewed.

The exact storage child [UID:0002T5][0x0067ab94-0x0067ab98.g_pActiveBrowserWindow](by-memory/0x0067ab94-0x0067ab98.g_pActiveBrowserWindow.md) is now attached here rather than directly to [UID:0000HV][Browser](by-file/Browser.md). This page and its Browser file parent both meet the corrected `85/85` gate after the 2026-06-07 refresh.

## Cross-References

- [UID:0000HV][Browser](by-file/Browser.md)
- [UID:00001B][BrowserWindow](by-class/BrowserWindow.md)
- [UID:0002T5][0x0067ab94-0x0067ab98.g_pActiveBrowserWindow](by-memory/0x0067ab94-0x0067ab98.g_pActiveBrowserWindow.md)
- [UID:0002AE][0x0067ab90-0x0067aba4.BrowserAndWebBoardDialogSingletons](by-memory/0x0067ab90-0x0067aba4.BrowserAndWebBoardDialogSingletons.md)
- [UID:0001OB][0x006131b4-0x006139df.BrowserVtablesAndStrings](by-memory/0x006131b4-0x006139df.BrowserVtablesAndStrings.md)

## Changes

- Completion/confidence scoring: existed before as ungraded `0/0`; changed to `76/72`. Summary/evidence: the page documents the generated active-browser-window singleton role, constructor/destructor behavior, browser data neighborhood, ownership/type hypotheses, and refs, but exact storage/type still need stronger IDA confirmation.
- Before: the page depended on generated constructor/destructor notes and a storage candidate, leaving confidence at `72` and autogen metadata blank.
- Changed to: exact storage child [UID:0002T5][0x0067ab94-0x0067ab98.g_pActiveBrowserWindow](by-memory/0x0067ab94-0x0067ab98.g_pActiveBrowserWindow.md), score `82/84`, `RECONSTRUCTABLE:TRUE`, and `AUTOGEN_PARENT_UID:0000HV`.
- Summary/evidence: the exact child records the aggregate IDA `dword_67AB94` evidence and the IDA-backed accelerator helper read, while BrowserWindow and Browser source-root docs support browser ownership. Final linkage/type spelling remains below final-source confidence.
- 2026-06-07 A004 split-rule correction:
  - Before: `COMPLETION:82`, `CONFIDENCE:84`, with exact storage child evidence but below the corrected assignment gate.
  - Changed to: `COMPLETION:86`, `CONFIDENCE:88`.
  - Summary/evidence: live IDA MCP reconfirmed exact initialized storage and five constructor/read/clear refs for [UID:0002T5][0x0067ab94-0x0067ab98.g_pActiveBrowserWindow](by-memory/0x0067ab94-0x0067ab98.g_pActiveBrowserWindow.md). The refreshed Browser parent and direct child evidence justify the exact child assignment under the corrected gate.
