*** UID:0000PP | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:91 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000HV | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000HV | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
// Source declaration for g_activeBrowserPane is emitted by [UID:0001P9][0x0067ab84-0x0067ab88.g_activeBrowserPane](by-memory/0x0067ab84-0x0067ab88.g_activeBrowserPane.md).
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# g_activeBrowserPane

## Status

- Confidence: strong for address, browser ownership, active owner/callback role, full direct-xref set, accepted `BrowserPane *` type, and no-clear lifetime model; medium-high for exact original header/private-header/accessor spelling.
- Current Wave3 kind: `global-data`
- Current generated owner file: `class_BrowserControlPane.cpp`
- IDA storage: `0x0067ab84`, documented at [UID:0001P9][0x0067ab84-0x0067ab88.g_activeBrowserPane](by-memory/0x0067ab84-0x0067ab88.g_activeBrowserPane.md). C001 recorded a saved `g_activeBrowserPane` label in an earlier worker session; B009's 2026-06-27 active MCP worker still renders the slot as `unk_67AB84`, so `g_activeBrowserPane` is the accepted source-facing name and optional future IDA rename/type target.
- Memory doc: [UID:0001P9][0x0067ab84-0x0067ab88.g_activeBrowserPane](by-memory/0x0067ab84-0x0067ab88.g_activeBrowserPane.md)
- Owner: [UID:0000HV][Browser](by-file/Browser.md). The exact storage page now clears `90/91` and the direct parent remains score-qualified, so retaining Browser owner/emitter routing satisfies the strict child/parent gate.

## Observed Evidence

Generated `BrowserControlPane::BrowserControlPane` stores its owner tag/parent pointer into `DAT_0067ab84`. Generated `BrowserControlPane::HandleBrowserDispatchEvent` uses `g_activeBrowserPane` to notify the owning browser pane on internal-close, new-window, and document-complete events.

IDA xrefs to `0x0067ab84` include:

- `0x0046b62d` inside `BrowserControlPane` construction.
- `0x0046c9f4`, `0x0046ca77`, and `0x0046cabb` inside the browser dispatch event handler.
- Additional app/browser setup references at `0x00464e70`, `0x0046a5d4`, and `0x0046c617`.

2026-05-25 IDA MCP `py_eval` reports `dword_67AB84` as a four-byte `.data` item with 8 direct xrefs, 7 of which sit in the browser dense code neighborhood.

The exact memory page [UID:0001P9][0x0067ab84-0x0067ab88.g_activeBrowserPane](by-memory/0x0067ab84-0x0067ab88.g_activeBrowserPane.md) records a later 2026-06-02 IDA refresh: uninitialized four-byte storage at `0x0067ab84`, neighboring dword boundaries, the constructor write at `0x0046b62d`, Escape handling through `sub_49DF20(dword_67AB84)`, and browser dispatch consumers at `0x0046c9f4`, `0x0046ca77`, and `0x0046cabb`.

Live IDA MCP on 2026-06-14 rechecked the same 8 direct xrefs with no extra writers: `0x00464e70`, `0x0046a5d4`, `0x0046b62d`, `0x0046bcee`, `0x0046c617`, `0x0046c9f4`, `0x0046ca77`, and `0x0046cabb`. The constructor at `0x0046b520` remains a BrowserControlPane construction path, and the dispatch handler at `0x0046c960` remains the browser COM/event consumer with internal close, new-window, and document-complete callback behavior.

2026-06-16 C001 live IDA MCP rechecked the current worker IDB, saved the low-risk data label `g_activeBrowserPane`, and saved `BrowserControlPane_HandleBrowserDispatchEvent` for `0x0046c960`. Current bytes at `0x0067ab80-0x0067ab94` are zero-filled writable storage; `xrefs_to 0x0067ab84` still reports exactly the same 8 refs, with the constructor write in saved `BrowserControlPaneConstructor` and the dispatch callback consumers in saved `BrowserControlPane_HandleBrowserDispatchEvent`. Decompilation still shows no direct clear store to this slot, so lifetime-clear behavior remains the real blocker rather than missing xref inventory.

2026-06-21 B010 source-quality reanalysis keeps the same ownership model but makes the consumer roles explicit: `BrowserControlPane::BrowserControlPane` stores constructor argument `a4` as the active owner/callback pane; `BrowserControlPaneTranslateAcceleratorMessage` calls `sub_49df20(g_activeBrowserPane)` on Escape; `BrowserControlPane::Invoke` uses the pointer for internal-close/new-window handling and the `DocumentComplete` callback/tag `0x4243746f`. No direct clear xref was found in [UID:0000Z6][0x0046b520-0x0046cfe0.BrowserControlPaneCore](by-memory/0x0046b520-0x0046cfe0.BrowserControlPaneCore.md).

B009's 2026-06-27 accepted source-quality implementation resolves the prior caveat: live constructor caller provenance shows BrowserDialog, WebBoardDialog, and WebBoardDialogOld pass BrowserPane-derived `this` pointers into `BrowserControlPane::BrowserControlPane` after BrowserPane vtable setup, so the accepted type is `BrowserPane *`. The unchanged no-clear evidence is documented as a lifetime/guard model rather than a missing teardown blocker: the owning pane outlives the child BrowserControlPane, reachable consumers are gated by active control/window/object state or live dispatch, and teardown clears `g_activeBrowserControlPane` at `0x0067ab28` rather than this owner slot.

[UID:000015][BrowserControlPane](by-class/BrowserControlPane.md) is scored `88/90` and independently records the constructor write, dispatch-event handler at `0x0046c960`, active global dependencies, and Browser source parent. [UID:000019][BrowserPane](by-class/BrowserPane.md) is scored `88/90` and confirms the browser-pane callback family and Browser parent. [UID:0000HV][Browser](by-file/Browser.md) is scored `87/89` and lists this global as Browser-owned active owner state at the same memory page.

The dispatch-event consumers include internal-close/new-window/document-complete behavior. The document-complete path calls through vtable slot `+0x64` (decimal `100`, verified with `int_convert.py`), which supports the owner/callback interpretation but still does not prove the final static C++ type.

## Ownership Decision

This is browser-pane/control active owner state. It remains with the Browser module/source root [UID:0000HV][Browser](by-file/Browser.md), not Application, BrowserControlPane class static storage, WebBoardDialog, or generic UI state. Application and accelerator reads are consumers of Browser-owned active browser state, not declaration ownership.

## Accepted Type And Emission Model

Accepted source-facing storage definition on the exact by-memory page:

```cpp
BrowserPane *g_activeBrowserPane;
```

The exact storage page [UID:0001P9][0x0067ab84-0x0067ab88.g_activeBrowserPane](by-memory/0x0067ab84-0x0067ab88.g_activeBrowserPane.md) emits the definition. This by-global page is the symbol/evidence record and must not duplicate formal `RECONSTRUCTION_CPP CODE`, avoiding duplicate global definitions. Do not use the previously likely `static BrowserPane*` spelling as the default: `Application::RequestExit` directly reads the slot, so if Application remains a separate translation unit the Browser module needs a header/private-header declaration or accessor. Exact original header/export spelling remains a source organization caveat.

Formal output for this symbol page is therefore a source-coverage comment to [UID:0001P9][0x0067ab84-0x0067ab88.g_activeBrowserPane](by-memory/0x0067ab84-0x0067ab88.g_activeBrowserPane.md), not a duplicate `BrowserPane *g_activeBrowserPane;` declaration.

## Score Rationale

| Field | Value | Rationale |
| --- | ---: | --- |
| Completion | 85 | The page now consolidates exact storage, all known direct xref roles, BrowserControlPane constructor/dispatch evidence, BrowserPane callback context, Browser source ownership, and the remaining no-clear/type caveats. |
| Confidence | 86 | Address and Browser ownership are supported by the exact memory page plus three score-qualified Browser-family pages. Confidence stays below final reconstruction because the exact static declaration and clear/lifetime mechanism remain open. |
| Parent | [UID:0000HV][Browser](by-file/Browser.md) | Child `85/86` and direct parent `86/88` clear the strict `85/85` gate. |

Updated score after the 2026-06-14 recheck:

| Field | Value | Rationale |
| --- | ---: | --- |
| Completion | 86 | The current page includes exact storage, all 8 direct xrefs, constructor write, browser accelerator/Escape consumers, dispatch callback consumers, owner rejection for non-browser modules, parent/emitter routing, and the still-open type/clear caveats. |
| Confidence | 87 | Live IDA MCP matches the existing exact memory page and Browser-family parent evidence. Confidence remains below `g_pMapTileImageLib`/Dialog count levels because no direct clear xref has been identified and the final static C++ type/linkage remains unsettled. |
| Parent | [UID:0000HV][Browser](by-file/Browser.md) | Child `86/87` and direct parent `86/88` clear the strict `85/85` gate, and the nonblank emitter route targets `auto-generated/NexusTK/browser/Browser.cpp`. |

Updated score after the 2026-06-16 safe IDA label/evidence refresh:

| Field | Value | Rationale |
| --- | ---: | --- |
| Completion | 87 | Adds current IDB storage bytes, saved source-quality labels, unchanged complete 8-ref inventory, and explicit confirmation that the no-clear finding was rechecked rather than assumed. |
| Confidence | 89 | Current IDA names/xrefs/decompilation agree with the Browser owner/emitter route and prior support pages. Confidence remains below final-audit range because the exact static C++ type and owner-lifetime clear model are still unresolved. |
| Parent | [UID:0000HV][Browser](by-file/Browser.md) | Direct Browser source root remains the supported owner/emitter; no non-browser owner evidence appeared in the refreshed xref set. |

Updated score after the 2026-06-27 B009 source-quality implementation:

| Field | Value | Rationale |
| --- | ---: | --- |
| Completion | 90 | Adds accepted `BrowserPane *` type, constructor caller provenance, current active-IDB `unk_67AB84` caveat, rejected `static` default, rejected Application/BrowserControlPane/raw-name alternatives, no-clear lifetime model, and exact-storage-page C++ emission policy. |
| Confidence | 91 | Live MCP confirms zero storage, complete 8-ref set, constructor writer, guarded consumers, and BrowserPane-derived publishers. Confidence remains below final-audit range only because exact original header/private-header/accessor spelling and broader Browser source split remain inferred. |
| Parent | [UID:0000HV][Browser](by-file/Browser.md) | Browser remains the direct owner/emitter; by-global remains non-duplicating support while [UID:0001P9][0x0067ab84-0x0067ab88.g_activeBrowserPane](by-memory/0x0067ab84-0x0067ab88.g_activeBrowserPane.md) owns the formal storage definition. |

## Cross-References

- [UID:0000HV][Browser](by-file/Browser.md)
- [UID:000015][BrowserControlPane](by-class/BrowserControlPane.md)
- [UID:000019][BrowserPane](by-class/BrowserPane.md)
- [UID:0001SJ][BrowserDispatchEventId](by-type/by-enum/BrowserDispatchEventId.md)
- [UID:0001P9][0x0067ab84-0x0067ab88.g_activeBrowserPane](by-memory/0x0067ab84-0x0067ab88.g_activeBrowserPane.md)

## Changes

- 2026-06-29 B002 Browser empty-emitter first-batch implementation:
  - Score unchanged at `90/91`.
  - Summary/evidence: inserted formal coverage comment `// Source declaration for g_activeBrowserPane is emitted by [UID:0001P9][0x0067ab84-0x0067ab88.g_activeBrowserPane](by-memory/0x0067ab84-0x0067ab88.g_activeBrowserPane.md).` This resolves the empty emitter without duplicating the exact storage declaration `BrowserPane *g_activeBrowserPane;` already emitted by [UID:0001P9][0x0067ab84-0x0067ab88.g_activeBrowserPane](by-memory/0x0067ab84-0x0067ab88.g_activeBrowserPane.md).
- Completion/confidence scoring: existed before as ungraded `0/0`; changed to `78/72`. Summary/evidence: the page documents storage, browser construction/dispatch uses, IDA xrefs, ownership/type hypotheses, and refs, but the final type and source-facing name remain medium-confidence.
- Before: confidence stayed at `72` and autogen metadata was blank even though the exact memory page had been refreshed to `82/84` and attached to Browser.
- Changed to: score `82/84`, `RECONSTRUCTABLE:TRUE`, and `AUTOGEN_PARENT_UID:0000HV`.
- Summary/evidence: [UID:0001P9][0x0067ab84-0x0067ab88.g_activeBrowserPane](by-memory/0x0067ab84-0x0067ab88.g_activeBrowserPane.md) records the exact storage, boundary, constructor write, 8-xref set, accelerator/Escape consumers, and browser dispatch-event uses. Final C++ type/linkage remains below the 95+ reconstruction gate.
- 2026-06-10 A001 gate repair/evidence consolidation:
  - Changed to: score `85/86` while retaining `RECONSTRUCTABLE:TRUE` and `AUTOGEN_PARENT_UID:0000HV`.
  - Summary/evidence: consolidated score-qualified Browser family evidence from [UID:0000HV][Browser](by-file/Browser.md), [UID:000015][BrowserControlPane](by-class/BrowserControlPane.md), [UID:000019][BrowserPane](by-class/BrowserPane.md), and the exact storage page. The child and direct parent now clear the strict `85/85` gate; final C++ remains blank because static type/linkage and active lifetime clear behavior are still below the final reconstruction bar.
- 2026-06-14 A003 score refresh:
  - Before: `85/86`; the page already had enough evidence to clear the strict child gate but still lacked a current full-xref confirmation.
  - Changed to: `86/87`, retaining [UID:0000HV][Browser](by-file/Browser.md) as canonical owner/emitter and keeping reconstruction C++ blank.
  - Summary/evidence: live IDA MCP rechecked the 8 direct refs to `0x0067ab84`, the BrowserControlPane constructor at `0x0046b520`, and the browser dispatch handler at `0x0046c960`. The unresolved direct clear path and exact static type/linkage remain the blockers below final code entry.
- 2026-06-16 C001 safe IDA refresh:
  - Before: `86/87`, with generic IDA data/function labels still present in the current worker IDB.
  - Changed to: `87/89`; saved `g_activeBrowserPane` and `BrowserControlPane_HandleBrowserDispatchEvent` in IDA.
  - Summary/evidence: live IDA confirmed zero-filled storage, the same 8 direct refs, constructor publication, dispatch-event callback use, and no direct clear xref. No type/prototype/member/local edits or final C++ were made because exact pointer type/linkage and lifetime-clear source shape remain unresolved.
- 2026-06-21 B010 BrowserControlPane core sync:
  - Added the constructor argument publication, Escape close callback, internal-close/new-window/document-complete callback/tag behavior, and no-clear confirmation from the BrowserControlPane core source-quality pass.
- 2026-06-27 B009 accepted implementation:
  - Before: `87/89`, likely `static BrowserPane*` text, blank formal C++, and type/linkage/lifetime-clear caveat.
  - Changed to: `90/91`, accepted source-facing `BrowserPane *`, no duplicate formal C++ on this by-global support page, non-static/header-access caveat, active IDB `unk_67AB84` caveat, no-clear lifetime model, and optional future IDA rename/type note.
