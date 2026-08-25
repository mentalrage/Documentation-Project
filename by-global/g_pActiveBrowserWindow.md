*** UID:0000Q6 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:89 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:91 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000HV | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000HV | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
// Source declaration for g_pActiveBrowserWindow is emitted by [UID:0002T5][0x0067ab94-0x0067ab98.g_pActiveBrowserWindow](by-memory/0x0067ab94-0x0067ab98.g_pActiveBrowserWindow.md).
[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# g_pActiveBrowserWindow

## Status

- Confidence: strong for active browser-window singleton role and exact storage, high for first-draft static declaration, medium-high for final Browser one-file versus split-file organization.
- Current Wave3 kind: `global-data`.
- Current generated/source owner file route: `browser/Browser.cpp` through [UID:0000HV][Browser](by-file/Browser.md).
- IDA storage: [UID:0002T5][0x0067ab94-0x0067ab98.g_pActiveBrowserWindow](by-memory/0x0067ab94-0x0067ab98.g_pActiveBrowserWindow.md) (current `unk_67AB94`; historical `dword_67AB94` / `DAT_0067ab94` in older generated variants).
- Proposed owner: [UID:0000HV][Browser](by-file/Browser.md).

## Observed Evidence

Generated and MCP-backed `BrowserWindow::BrowserWindow` evidence assigns `g_pActiveBrowserWindow = this` after entering the constructor and before installing the browser host COM vtables, with a fallback clear path. `BrowserWindow::~BrowserWindow` clears the same pointer after restoring BrowserWindow vtables and releasing the browser interface.

The active window sits in the same static browser data neighborhood as `g_pBrowserDialogOld`, `g_pBrowserThread`, and `g_pCurrentBrowserHost`.

The exact storage child [UID:0002T5][0x0067ab94-0x0067ab98.g_pActiveBrowserWindow](by-memory/0x0067ab94-0x0067ab98.g_pActiveBrowserWindow.md) records the aggregate IDA evidence for current `unk_67AB94` / historical `dword_67AB94`, the `BrowserWindow` constructor/destructor ownership trail, and the accelerator helper that reads this slot before querying the active browser object.

Historical A004 live IDA MCP on 2026-06-07 treated the storage child as an initialized four-byte `.data` slot, and prior B004 session `ddf5b602` confirmed the zero-storage interpretation before the supervisor MCP restart. B004 current MCP session `ba171fe4` supersedes stale current-session wording for this slot: `get_bytes 0x0067ab94 size 4` returns four zero bytes, `get_global_value 0x0067ab94` returns `0x0`, and `get_global_value unk_67AB94` returns `0x0`. The current exact xref inventory is five data refs across four functions: constructor publish/fallback-clear refs at `0x004696a3` and `0x004696aa`, destructor/lifetime clear at `0x00469a71`, accelerator-helper read at `0x0046a535`, and cleanup clear-thunk write at `0x00470240`.

B004 current `ba171fe4` evidence also records no interior refs to `0x0067ab95-0x0067ab97`, separate successor BrowserDialog refs at `0x0067ab98`, no recovered `g_pActiveBrowserWindow` name/global/type row, active `unk_67AB94` value access, VA operand hits only at the five modeled refs, and no RVA pointer-pattern route.

## Ownership Hypothesis

This is browser module state for the currently constructed or active embedded browser host window. It should migrate with `BrowserWindow` in `browser/Browser.cpp` or a split `browser/BrowserWindow.cpp`.

## Type / Emission Model

The accepted declaration is emitted only by the exact storage child [UID:0002T5][0x0067ab94-0x0067ab98.g_pActiveBrowserWindow](by-memory/0x0067ab94-0x0067ab98.g_pActiveBrowserWindow.md). This by-global page carries a formal coverage comment plus the `[[CHILDREN]]` insertion marker and must not duplicate the target declaration. `static` remains the best first-draft linkage because all five proven xrefs are Browser/BrowserWindow source-root refs: constructor publish/fallback-clear, destructor clear, retained BrowserWindow accelerator-helper read, and Browser clear thunk. Final Browser one-file versus split BrowserWindow source/header layout remains a confidence cap, not a blocker.

The exact storage child [UID:0002T5][0x0067ab94-0x0067ab98.g_pActiveBrowserWindow](by-memory/0x0067ab94-0x0067ab98.g_pActiveBrowserWindow.md) stays attached here rather than directly to [UID:0000HV][Browser](by-file/Browser.md). This page routes the declaration through Browser without using BrowserWindow class, mixed aggregate, retained accelerator helper, or clear thunk as the declaration owner.

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
- 2026-07-04 B004 UID0002T5 implementation callback:
  - Before: `COMPLETION:86`, `CONFIDENCE:88`, blank formal C++, provisional `static` wording, and stale/historical `dword_67AB94`/`0xffffffff` evidence.
  - Changed to: `COMPLETION:89`, `CONFIDENCE:91`, formal coverage comment plus `[[CHILDREN]]` insertion marker, current `ba171fe4` zero-byte/five-xref proof, active `unk_67AB94`/no recovered name/type caveat, exact target declaration route through [UID:0002T5][0x0067ab94-0x0067ab98.g_pActiveBrowserWindow](by-memory/0x0067ab94-0x0067ab98.g_pActiveBrowserWindow.md), and retained Browser source-root split confidence cap. Prior `ddf5b602` wording is historical only.
  - Summary/evidence: the source declaration itself emits only on exact storage UID0002T5 as `static BrowserWindow *g_pActiveBrowserWindow;`; this by-global page documents the symbol/owner route and provides the child insertion marker without duplicating the C++ definition.
