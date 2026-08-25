** TARGET-REPORT-UID:0000ZF **
** AUTHOR-AGENT-ID:B001 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# 0000ZF Browser OLE Legacy And Helpers Ownership / Split Research

Revision: B001-024 final write phase, 2026-06-10

## Finalized Report / Current Recommendation

- Current recommendation: keep [UID:0000ZF] `by-memory/0x0046f010-0x004710b8.BrowserOleLegacyAndHelpers.md` as a parent-blank, non-emitting split inventory. Do not attach the aggregate to `Browser`, `BrowserThread`, or any other single owner.
- Final disposition: the in-range source-bearing Browser/OLE functions/helpers/destructors/stubs now have exact child pages. Reconstructable children are scored at least `85/85` and assigned only to direct parents that also clear `85/85`. Non-source compiler/ABI/library thunk islands have exact non-reconstructable pages and remain parent-blank by evidence.
- Required action: supervisor review and execute/archive this report. Do not move this report to `executed` before supervisor review.
- Confidence: high for the split/container recommendation (`92/100`), high for exact in-range child coverage (`91/100`), medium-high for final historical source names where IDA only proves behavior and ownership class/file (`87-90/100` depending on child).

## Supporting Research

## Target

- Target UID: `0000ZF`
- Target path: `E:\NTK\GhidraBridge\source-3\project-documentation\by-memory\0x0046f010-0x004710b8.BrowserOleLegacyAndHelpers.md`
- Source queue/report row: B001-024, UID `0000ZF`, supervisor issue that the existing research report was stale and the master page still listed unresolved in-range Browser/OLE children.
- Current supervisor classification: active B001-only split repair; do not spawn agents, do not edit `Supervisor_notes.md`, do not create leases for this current B001-only workflow unless explicitly told, and do not move this report to `executed`.
- Current scores and parent state: target page is now `COMPLETION:91`, `CONFIDENCE:92`, `RECONSTRUCTABLE:FALSE`, `AUTOGEN_PARENT_UID:` blank.

## Executive Recommendation

The aggregate is correctly parent-blank because it is not one source item. The best direct-owner model is a split map:

- Browser-class methods: [UID:000013] `Browser`
- Browser file-level helpers: [UID:0000HV] `Browser`
- BrowserThread methods: [UID:00001A] `BrowserThread`
- BrowserControlPaneOld methods: [UID:000016] `BrowserControlPaneOld`
- BrowserControlPane scalar destructor: [UID:000015] `BrowserControlPane`
- BrowserWindow navigation: [UID:00001B] `BrowserWindow`
- BrowserPane destructor: [UID:000019] `BrowserPane`
- `browser::Notification` destructor/post helper: [UID:000014] `browser__Notification`
- BrowserDialog/BrowserDialogOld/WebBoardDialog/WebBoardDialogOld destructors: their exact class pages
- AutoInit scalar destructor: [UID:0000HN] `AutoInit`
- Compiler/ABI/library helper thunks: exact non-emitting parent-blank pages

No in-range source-bearing Browser/OLE item remains as a vague follow-up. The only parent-blank children left in the range are explicitly non-emitting thunk/helper islands, not reconstructable source functions.

## Supervisor Active Recheck

- The active supervisor concern was correct: before this write phase the master page still had a stale unresolved-child list covering Browser/BrowserControlPane/BrowserPane/browser::Notification destructors, `AdviseConnectionPoint`, `UnadviseConnectionPoint`, `BrowserWindow::Navigate`, `PostBrowserNotification`, and in-range adjustor/delegation thunks.
- The assigned item required split repair before a final master report. The broad range includes multiple direct owners and non-source ABI/compiler islands.
- [UID:000015] `BrowserControlPane` was raised from `82/86` to `85/87` before assigning [UID:000339] `0x00470410-0x004704ec.BrowserControlPaneScalarDeletingDestructor`.
- [UID:000014] `browser__Notification` was raised from `84/88` to `85/88` before assigning [UID:00033D] `0x00470740-0x00470782.BrowserNotificationScalarDeletingDestructor` and [UID:00033L] `0x00470f20-0x00470fb9.PostBrowserNotification`.
- [UID:00032R] `0x0046f1d0-0x0046f1db.BrowserThreadDeleteIfPresentWrapper` intentionally remains parent-blank: it is an exact null-check/delete wrapper referenced from BrowserThread vtable data, but it is not a source-emitting method body. `BrowserThread` remains the semantic owner, not the autogen parent.
- I did not edit `Supervisor_notes.md`, did not create leases, did not spawn other agents, and did not move the report to `executed`.

## Inference Research Guidance Check

`by-structure.md` and `inference_research.md` affected three decisions:

- Assignment is allowed only when both the child and direct parent clear the current `85/85` gate. This drove the BrowserControlPane, browser::Notification, BrowserDialog, BrowserDialogOld, WebBoardDialog, AutoInit parent repairs.
- Existing documentation was treated as a hypothesis, not proof. The master page already stated that the aggregate was mixed, but it still listed unresolved exact children. IDA MCP and current by-* pages were used to replace that stale state.
- Mixed aggregates should be split rather than assigned to a convenient broad file. The aggregate contains Browser module code, AutoInit process-wide OLE lifetime code, WebBoardDialogOld cleanup, switch tables, padding, and ABI thunks, so one parent would be misleading.

Evidence categories are separated below as IDA fact, documentation evidence, and ownership inference.

## Evidence Standards Used

- IDA MCP function/range inventory: function starts/ends, final in-range function, padding gaps, raw code-shaped destructor, switch/table islands.
- IDA behavior evidence: destructor vtable resets, COM `QueryInterface`/`Invoke`, BSTR/VARIANT/SafeArray handling, connection point advise/unadvise, notification allocation/posting, AutoInit `OleUninitialize`.
- IDA data evidence: vtable/data refs such as `0x00613760 -> 0x0046f010`, AutoInit vtable `0x0061373c -> 0x00470300`, BrowserControlPane vtable refs, and singleton-clear globals.
- Documentation evidence: current by-class/by-file/by-memory pages, existing B001-024 child pages, and validator metadata.
- Negative evidence: no single class/file owns the whole range; several exact child pages are compiler/ABI/library helpers and should not emit source even though they have precise address coverage.

## IDA MCP Facts

- Function/range facts: IDA reports 125 modeled function starts inside `0x0046f010-0x004710b8`; 130 modeled functions when adjacent tail helpers through `0x00471142` are included.
- Boundary facts: first in-range function is `sub_46F010` at `0x0046f010-0x0046f1c8`; final in-range function is `sub_4710AE` at `0x004710ae-0x004710b8`. The half-open end is therefore `0x004710b8`.
- Data/table/padding facts: IDA confirms padding at `0x0046f1c8-0x0046f1d0`, `0x0046f1db-0x0046f1e0`, `0x0046f216-0x0046f220`, and `0x0046f30f-0x0046f310`; switch/table bytes after `0x0046f378`; Browser `Invoke` table bytes after `0x0046fab6`; and `0xcc` padding after AutoInit at `0x0047032a-0x00470330`.
- Xref facts: `0x00613760 -> 0x0046f010` anchors BrowserThread; `0x00613764 -> 0x0046f1d0` anchors the delete-if-present wrapper; `0x0061373c -> 0x00470300` anchors AutoInit.
- Behavior facts: `0x0046f480` is the Browser ordinary destructor; `0x0046f540` is Browser `QueryInterface`; `0x0046f810` handles dispatch IDs `104`, `106`, `250`, `251`, `263`, and `270`; `0x00470170` builds a `VARIANT` from a string; `0x004708d0`/`0x00470980` advise/unadvise connection points; `0x00470dd0` performs WebBrowser navigation; `0x00470f20` posts `browser::Notification` using message `0x42726f73`.
- Negative IDA facts: AutoInit and WebBoardDialogOld interior code are not Browser instance methods; final adjustor/delegation clusters are ABI support rather than handwritten source bodies.

## Function / Child Inventory

| Range / Item | UID / Path | Role | Reconstructable | Direct Parent | Score | Status |
| --- | --- | --- | --- | --- | --- | --- |
| `0x0046f010-0x0046f1c8` | [UID:00032Q] `by-memory/0x0046f010-0x0046f1c8.BrowserThreadRunMessageLoop.md` | BrowserThread message loop | true | [UID:00001A] `BrowserThread` | `85/89` | exact child, assigned |
| `0x0046f1d0-0x0046f1db` | [UID:00032R] `by-memory/0x0046f1d0-0x0046f1db.BrowserThreadDeleteIfPresentWrapper.md` | delete-if-present wrapper | false | parent blank, semantic BrowserThread | `86/90` | exact non-emitting wrapper |
| `0x0046f1e0-0x0046f216` | [UID:00032S] `by-memory/0x0046f1e0-0x0046f216.BrowserControlPaneOldNonDeletingDestructor.md` | old-pane destructor body | true | [UID:000016] `BrowserControlPaneOld` | `85/86` | exact child, assigned |
| `0x0046f220-0x0046f30f` | [UID:00032T] `by-memory/0x0046f220-0x0046f30f.BrowserControlPaneOldDrawStatusOverlay.md` | old-pane overlay drawing | true | [UID:000016] `BrowserControlPaneOld` | `85/88` | exact child, assigned |
| `0x0046f310-0x0046f47b` | [UID:00032U] `by-memory/0x0046f310-0x0046f47b.BrowserControlPaneOldHandleBrowserMessage.md` | old-pane message handler/table | true | [UID:000016] `BrowserControlPaneOld` | `85/88` | exact child, assigned |
| `0x0046f480-0x0046f53e` | [UID:00032Y] `by-memory/0x0046f480-0x0046f53e.BrowserNonDeletingDestructor.md` | Browser ordinary destructor | true | [UID:000013] `Browser` | `85/88` | created, assigned |
| `0x0046f540-0x0046f66f` | [UID:00032Z] `by-memory/0x0046f540-0x0046f66f.BrowserQueryInterface.md` | Browser COM QI | true | [UID:000013] `Browser` | `85/88` | created, assigned |
| `0x0046f670-0x0046f808` | [UID:000330] `by-memory/0x0046f670-0x0046f808.BrowserComStubMethods.md` | Browser COM stubs | true | [UID:000013] `Browser` | `85/87` | created, assigned |
| `0x0046f810-0x0046fb80` | [UID:000331] `by-memory/0x0046f810-0x0046fb80.BrowserInvokeAndSwitchTable.md` | Browser Invoke/table | true | [UID:000013] `Browser` | `85/88` | created, assigned |
| `0x0046fb80-0x0046fca5` | [UID:000332] `by-memory/0x0046fb80-0x0046fca5.BrowserDocHostShowUiStubs.md` | doc-host/UI stubs | true | [UID:000013] `Browser` | `85/87` | created, assigned |
| `0x0046fcb0-0x0046ff50` | [UID:000333] `by-memory/0x0046fcb0-0x0046ff50.BrowserLegacyHostWndProc.md` | browser host WndProc | true | [UID:0000HV] `Browser` file | `85/87` | created, assigned |
| `0x0046ff50-0x00470159` | [UID:0002P3] `by-memory/0x0046ff50-0x00470159.BrowserControlPaneOldConstructor.md` | old-pane constructor | true | [UID:000016] `BrowserControlPaneOld` | `85/89` | exact child, assigned |
| `0x00470160-0x0047016e` | [UID:000334] `by-memory/0x00470160-0x0047016e.CAtlExceptionConstructorThunk.md` | ATL exception helper | false | parent blank | `86/88` | created, non-emitting |
| `0x00470170-0x004701c9` | [UID:000335] `by-memory/0x00470170-0x004701c9.BrowserVariantFromString.md` | Browser variant helper | true | [UID:0000HV] `Browser` file | `85/89` | created, assigned |
| `0x004701d0-0x00470278` | [UID:000336] `by-memory/0x004701d0-0x00470278.BrowserDialogCleanupAndVariantThunks.md` | mixed cleanup/thunk island | false | parent blank | `86/88` | created, non-emitting |
| `0x00470278-0x004702fc` | [UID:000337] `by-memory/0x00470278-0x004702fc.BrowserDialogDestructorAdjustorThunks.md` | destructor adjustors | false | parent blank | `86/90` | created, non-emitting |
| `0x00470300-0x0047032a` | [UID:0000ZG] `by-memory/0x00470300-0x0047032a.AutoInit.md` | AutoInit scalar destructor | true | [UID:0000HN] `AutoInit` | `85/90` | repaired, assigned |
| `0x00470330-0x00470406` | [UID:000338] `by-memory/0x00470330-0x00470406.BrowserScalarDeletingDestructor.md` | Browser scalar destructor | true | [UID:000013] `Browser` | `85/88` | created, assigned |
| `0x00470410-0x004704ec` | [UID:000339] `by-memory/0x00470410-0x004704ec.BrowserControlPaneScalarDeletingDestructor.md` | BrowserControlPane scalar destructor | true | [UID:000015] `BrowserControlPane` | `85/88` | created, assigned after parent repair |
| `0x004704f0-0x00470579` | [UID:00032X] `by-memory/0x004704f0-0x00470579.BrowserControlPaneOldScalarDeletingDestructorAndAdjustors.md` | old-pane scalar destructor/adjustors | true | [UID:000016] `BrowserControlPaneOld` | `85/88` | exact child, assigned |
| `0x00470580-0x004705df` | [UID:00033A] `by-memory/0x00470580-0x004705df.BrowserDialogScalarDeletingDestructor.md` | BrowserDialog scalar destructor | true | [UID:000017] `BrowserDialog` | `85/88` | created, assigned after parent repair |
| `0x004705e0-0x0047068d` | [UID:00033B] `by-memory/0x004705e0-0x0047068d.BrowserDialogOldScalarDeletingDestructor.md` | BrowserDialogOld scalar destructor | true | [UID:000018] `BrowserDialogOld` | `85/88` | created, assigned after parent repair |
| `0x00470690-0x004706e5` | [UID:00033C] `by-memory/0x00470690-0x004706e5.BrowserPaneScalarDeletingDestructor.md` | BrowserPane scalar destructor | true | [UID:000019] `BrowserPane` | `85/88` | created, assigned |
| `0x004706f0-0x0047073b` | [UID:00032V] `by-memory/0x004706f0-0x0047073b.BrowserThreadScalarDeletingDestructor.md` | BrowserThread scalar destructor | true | [UID:00001A] `BrowserThread` | `85/90` | exact child, assigned |
| `0x00470740-0x00470782` | [UID:00033D] `by-memory/0x00470740-0x00470782.BrowserNotificationScalarDeletingDestructor.md` | Notification scalar destructor | true | [UID:000014] `browser__Notification` | `85/88` | created, assigned after parent repair |
| `0x00470790-0x004707ef` | [UID:00033E] `by-memory/0x00470790-0x004707ef.WebBoardDialogScalarDeletingDestructor.md` | WebBoardDialog scalar destructor | true | [UID:0000G2] `WebBoardDialog` | `85/87` | created, assigned after parent repair |
| `0x004707f0-0x0047084f` | [UID:00033F] `by-memory/0x004707f0-0x0047084f.WebBoardDialogOldScalarDeletingDestructor.md` | WebBoardDialogOld scalar destructor | true | [UID:0000G3] `WebBoardDialogOld` | `85/88` | created, assigned |
| `0x0047084f-0x004708c7` | [UID:00033G] `by-memory/0x0047084f-0x004708c7.BrowserComAdjustorThunks.md` | COM adjustor thunks | false | parent blank | `86/90` | created, non-emitting |
| `0x004708d0-0x00470953` | [UID:00033H] `by-memory/0x004708d0-0x00470953.AdviseConnectionPoint.md` | connection-point advise helper | true | [UID:0000HV] `Browser` file | `85/89` | created, assigned |
| `0x00470960-0x0047097c` | [UID:00033I] `by-memory/0x00470960-0x0047097c.CAtlExceptionThrowHelper.md` | ATL throw helper | false | parent blank | `86/89` | created, non-emitting |
| `0x00470980-0x00470a00` | [UID:00033J] `by-memory/0x00470980-0x00470a00.UnadviseConnectionPoint.md` | connection-point unadvise helper | true | [UID:0000HV] `Browser` file | `85/89` | created, assigned |
| `0x00470a00-0x00470dc9` | [UID:00032W] `by-memory/0x00470a00-0x00470dc9.BrowserThreadInitializeBrowserHost.md` | BrowserThread host init | true | [UID:00001A] `BrowserThread` | `85/89` | exact child, assigned |
| `0x00470dd0-0x00470f10` | [UID:00033K] `by-memory/0x00470dd0-0x00470f10.BrowserWindowNavigate.md` | BrowserWindow Navigate | true | [UID:00001B] `BrowserWindow` | `85/88` | created, assigned |
| `0x00470f20-0x00470fb9` | [UID:00033L] `by-memory/0x00470f20-0x00470fb9.PostBrowserNotification.md` | notification allocator/post helper | true | [UID:000014] `browser__Notification` | `85/89` | created, assigned after parent repair |
| `0x00470fc0-0x004710b8` | [UID:00033M] `by-memory/0x00470fc0-0x004710b8.BrowserOleAdjustorAndDelegationThunks.md` | final adjustor/delegation thunk cluster | false | parent blank | `86/90` | created, non-emitting |

## Direct Xref / Caller Inventory

| Address / Item | Xref / Caller / Callee | Meaning |
| --- | --- | --- |
| `0x0046f010` | data ref `0x00613760 -> 0x0046f010` | BrowserThread vtable entry anchors `RunMessageLoop`. |
| `0x0046f1d0` | data ref `0x00613764 -> 0x0046f1d0` | BrowserThread vtable-adjacent delete-if-present wrapper; semantic BrowserThread, non-emitting. |
| `0x0046f1e0` | unmodeled code-shaped body between modeled functions | BrowserControlPaneOld non-deleting destructor body despite missing IDA function object. |
| `0x0046f810` | dispatch IDs `104`, `106`, `250`, `251`, `263`, `270` | Browser `Invoke` event/dispatch handler; source-bearing Browser method. |
| `0x0046fcb0` | `GetWindowLongA(hwnd, -21)` / `dword_67AB8C` Browser object lookup | Browser legacy host window procedure, file-level helper. |
| `0x00470170` | `VariantClear`, `SysAllocString`, `VT_BSTR`, `VT_ERROR` | Browser free helper that builds OLE variants from strings. |
| `0x00470260` | writes `dword_67ABA0 = 0` | WebBoardDialogOld singleton clear inside mixed thunk island, not Browser ownership. |
| `0x00470300` | vtable slot `0x0061373c -> 0x00470300`; calls `OleUninitialize` | AutoInit scalar deleting destructor, non-Browser OLE lifetime child. |
| `0x00470410` | vtable `0x0061344c`; adjustor callers `0x0047027e`/`0x00470289` | BrowserControlPane scalar deleting destructor; parent gate repaired before assignment. |
| `0x004708d0` | `QueryInterface`, `FindConnectionPoint`, `Advise`, release | Browser connection-point advise helper. |
| `0x00470980` | connection-point release/unadvise flow | Browser connection-point unadvise helper. |
| `0x00470dd0` | BSTR/VARIANT/SafeArray setup, WebBrowser navigate vtable call | BrowserWindow navigation method. |
| `0x00470f20` | allocates notification, installs vtable `0x006131f0`, posts `0x42726f73` | `browser::Notification` source helper. |
| `0x00470fc0-0x004710b8` | tail jumps/adjustors to Browser, BrowserControlPane, BrowserWindow COM methods | ABI/delegation thunk cluster; exact but non-emitting. |

## Documentation Evidence And IDA Status

- Existing docs that support the conclusion: [UID:0000HV] `Browser` already says process-wide OLE lifetime is separate from Browser ownership; BrowserThread, BrowserControlPaneOld, Browser, BrowserWindow, BrowserPane, BrowserControlPane, and browser::Notification pages provide the parent surfaces used by exact children.
- Existing docs that were stale or incomplete: the master page still listed missing interior follow-ups after exact children had been created; [UID:000015] `BrowserControlPane` was `82/86`; [UID:000014] `browser__Notification` was `84/88`; [UID:0000HN] `AutoInit` and [UID:0000ZG] AutoInit scalar destructor were below the current 85/85 gate.
- Documentation repaired in this pass: the master page now has a final exact split map; BrowserControlPane/browser::Notification and other parent gates were raised where evidence supported assignment; AutoInit parent/child were raised to clear the in-range OLE child gate.
- Generated/coverage state: targeted validator scans with `--apply` updated validator-owned generated memory coverage/report state. Generated files were not manually edited.

## Ranked Ownership Analysis

### 1. Exact split inventory under multiple direct owners

- Evidence for: IDA proves multiple class vtables, free helpers, process-wide AutoInit OLE lifetime code, WebBoardDialogOld cleanup, switch tables, padding, and ABI thunks in one contiguous address island.
- Evidence against: none for the split disposition; uncertainty remains only in final source spelling for some helpers.
- Decision: accepted. This is the only defensible ownership model for `0000ZF`.

### 2. Single Browser file owner for the whole aggregate

- Evidence for: most of the range is browser-module COM/UI code, and `Browser.md` is the source root for multiple free helpers.
- Evidence against: AutoInit `0x00470300`, WebBoardDialogOld singleton clear at `0x00470260`, WebBoardDialog/WebBoardDialogOld destructors, and compiler/ABI thunk islands are not Browser source methods. A single Browser parent would mis-own non-Browser code.
- Decision: rejected for the aggregate; accepted only for exact Browser free-helper children such as `BrowserVariantFromString`, `AdviseConnectionPoint`, `UnadviseConnectionPoint`, and host WndProc.

### 3. Single class owner for the whole aggregate

- Evidence for: several subranges are class methods/destructors.
- Evidence against: no class spans BrowserThread, BrowserControlPaneOld, Browser, BrowserControlPane, BrowserPane, BrowserWindow, browser::Notification, BrowserDialog, WebBoardDialog, WebBoardDialogOld, and AutoInit.
- Decision: rejected.

### Proposed new file/grouping, if applicable

- Proposed owner/name/path: no new source owner is needed for this assignment.
- Likely full contents: existing `Browser`, class, WebBoard, and AutoInit parent pages cover the relevant contents.
- Candidate related items that belong: adjacent outside-range helpers `0x004710b8-0x004710cc`, `0x004710d0-0x004710df`, and `0x004710e0-0x0047110e` remain separate adjacent Browser items and are not part of this half-open range.
- Candidate related items rejected: the broad `0000ZF` aggregate is not a new source file; it is a documentation inventory page.
- Standalone, narrow, or broad source-file inference: mixed non-emitting container.

## Negative Evidence Summary

- Consumer/read xrefs do not make the aggregate a Browser file item because AutoInit and WebBoardDialogOld write/teardown evidence is inside the same address range.
- Vtable adjacency does not make small wrappers source-emitting. The delete-if-present wrapper and COM adjustor/delegation clusters are exact documented artifacts but should remain parent-blank because the source reconstructs the underlying class methods, not the ABI wrappers.
- Adjacent tail helpers beginning at `0x004710b8` are outside the half-open target and were not used to inflate in-range completion.
- Existing docs were not assumed correct where they were below gate or stale; parent pages were raised only where direct IDA-backed child evidence supported it.

## Final Recommendation

- Exact changes applied: the master page was rewritten as a final split map and raised to `91/92`; 25 missing exact child pages were created and scored; AutoInit parent/child were repaired; needed direct parents were raised to clear assignment gates.
- Exact parent assignments applied: Browser class/file, BrowserThread, BrowserControlPaneOld, BrowserControlPane, BrowserDialog, BrowserDialogOld, BrowserPane, browser::Notification, WebBoardDialog, WebBoardDialogOld, BrowserWindow, and AutoInit assignments are applied only to exact reconstructable children that clear `85/85`.
- Exact items left unassigned and why: [UID:00032R], [UID:000334], [UID:000336], [UID:000337], [UID:00033G], [UID:00033I], and [UID:00033M] are exact non-reconstructable wrapper/helper/thunk islands and remain parent-blank intentionally.
- Exact future work outside assignment scope: supervisor may separately review adjacent out-of-range Browser tail items such as [UID:000218] `BrowserGuidCompareHelper`, but those start at or after `0x004710b8` and are not blockers for B001-024.

## Follow-Up Actions

- Supervisor actions: review this report and the changed by-* files; execute/archive the report if accepted.
- A-agent actions: none required for in-range source-bearing Browser/OLE coverage. All in-range reconstructable children now have exact pages and gate-cleared direct parents.
- B001 future research actions: none pending for `0000ZF` unless the supervisor requests adjacent tail follow-up.

## Confidence

- Recommendation confidence: `92/100` for parent-blank mixed-container disposition.
- Score confidence: `91/100` for aggregate completion and `87-90/100` for the newly created exact children, depending on how much original source naming remains inferred.
- Remaining uncertainty: final historical source-file spelling and exact source names for some free helpers and ABI-visible methods remain inferred, but this does not block the split/parent disposition.

## Validator Results

Commands run from `E:\NTK\GhidraBridge\source-3\project-documentation`:

> Executable block R001 was removed from this report and preserved verbatim in [0000ZF-BrowserOleLegacyAndHelpers-removed.md](0000ZF-BrowserOleLegacyAndHelpers-removed.md). The archived block is non-authoritative and must not be executed.

The validator was run in two sequential batches. Batch 1 timed out at the shell level after 25 successful scans and no failures; batch 2 continued from the next unscanned file and completed 24 additional scans with no failures. After a wording cleanup touched the aggregate page, `by-memory/0x0046f010-0x004710b8.BrowserOleLegacyAndHelpers.md` was scanned once more and passed. No validator scans remain pending.

| File | Result |
| --- | --- |
| `by-memory/0x0046f010-0x004710b8.BrowserOleLegacyAndHelpers.md` | OK |
| `by-memory/0x0046f010-0x0046f1c8.BrowserThreadRunMessageLoop.md` | OK |
| `by-memory/0x0046f1d0-0x0046f1db.BrowserThreadDeleteIfPresentWrapper.md` | OK |
| `by-memory/0x0046f1e0-0x0046f216.BrowserControlPaneOldNonDeletingDestructor.md` | OK |
| `by-memory/0x0046f220-0x0046f30f.BrowserControlPaneOldDrawStatusOverlay.md` | OK |
| `by-memory/0x0046f310-0x0046f47b.BrowserControlPaneOldHandleBrowserMessage.md` | OK |
| `by-memory/0x0046f480-0x0046f53e.BrowserNonDeletingDestructor.md` | OK |
| `by-memory/0x0046f540-0x0046f66f.BrowserQueryInterface.md` | OK |
| `by-memory/0x0046f670-0x0046f808.BrowserComStubMethods.md` | OK |
| `by-memory/0x0046f810-0x0046fb80.BrowserInvokeAndSwitchTable.md` | OK |
| `by-memory/0x0046fb80-0x0046fca5.BrowserDocHostShowUiStubs.md` | OK |
| `by-memory/0x0046fcb0-0x0046ff50.BrowserLegacyHostWndProc.md` | OK |
| `by-memory/0x0046ff50-0x00470159.BrowserControlPaneOldConstructor.md` | OK |
| `by-memory/0x00470160-0x0047016e.CAtlExceptionConstructorThunk.md` | OK |
| `by-memory/0x00470170-0x004701c9.BrowserVariantFromString.md` | OK |
| `by-memory/0x004701d0-0x00470278.BrowserDialogCleanupAndVariantThunks.md` | OK |
| `by-memory/0x00470278-0x004702fc.BrowserDialogDestructorAdjustorThunks.md` | OK |
| `by-memory/0x00470300-0x0047032a.AutoInit.md` | OK |
| `by-memory/0x00470330-0x00470406.BrowserScalarDeletingDestructor.md` | OK |
| `by-memory/0x00470410-0x004704ec.BrowserControlPaneScalarDeletingDestructor.md` | OK |
| `by-memory/0x004704f0-0x00470579.BrowserControlPaneOldScalarDeletingDestructorAndAdjustors.md` | OK |
| `by-memory/0x00470580-0x004705df.BrowserDialogScalarDeletingDestructor.md` | OK |
| `by-memory/0x004705e0-0x0047068d.BrowserDialogOldScalarDeletingDestructor.md` | OK |
| `by-memory/0x00470690-0x004706e5.BrowserPaneScalarDeletingDestructor.md` | OK |
| `by-memory/0x004706f0-0x0047073b.BrowserThreadScalarDeletingDestructor.md` | OK |
| `by-memory/0x00470740-0x00470782.BrowserNotificationScalarDeletingDestructor.md` | OK |
| `by-memory/0x00470790-0x004707ef.WebBoardDialogScalarDeletingDestructor.md` | OK |
| `by-memory/0x004707f0-0x0047084f.WebBoardDialogOldScalarDeletingDestructor.md` | OK |
| `by-memory/0x0047084f-0x004708c7.BrowserComAdjustorThunks.md` | OK |
| `by-memory/0x004708d0-0x00470953.AdviseConnectionPoint.md` | OK |
| `by-memory/0x00470960-0x0047097c.CAtlExceptionThrowHelper.md` | OK |
| `by-memory/0x00470980-0x00470a00.UnadviseConnectionPoint.md` | OK |
| `by-memory/0x00470a00-0x00470dc9.BrowserThreadInitializeBrowserHost.md` | OK |
| `by-memory/0x00470dd0-0x00470f10.BrowserWindowNavigate.md` | OK |
| `by-memory/0x00470f20-0x00470fb9.PostBrowserNotification.md` | OK |
| `by-memory/0x00470fc0-0x004710b8.BrowserOleAdjustorAndDelegationThunks.md` | OK |
| `by-class/Browser.md` | OK |
| `by-file/Browser.md` | OK |
| `by-class/BrowserThread.md` | OK |
| `by-class/BrowserControlPaneOld.md` | OK |
| `by-class/BrowserControlPane.md` | OK |
| `by-class/BrowserDialog.md` | OK |
| `by-class/BrowserDialogOld.md` | OK |
| `by-class/BrowserPane.md` | OK |
| `by-class/browser__Notification.md` | OK |
| `by-class/WebBoardDialog.md` | OK |
| `by-class/WebBoardDialogOld.md` | OK |
| `by-class/BrowserWindow.md` | OK |
| `by-file/AutoInit.md` | OK |

Validator-owned generated state:

- `auto-generated/-ag-memory-coverage.md` was updated by validator during `--apply` scans.
- `tools/validator_autogen_backup/20260610-*` backup snapshots were created by validator.
- Tool lock/state mtimes changed as validator side effects. I did not manually edit tool internals.

## Changed Files

Created:

- `by-memory/0x0046f480-0x0046f53e.BrowserNonDeletingDestructor.md`
- `by-memory/0x0046f540-0x0046f66f.BrowserQueryInterface.md`
- `by-memory/0x0046f670-0x0046f808.BrowserComStubMethods.md`
- `by-memory/0x0046f810-0x0046fb80.BrowserInvokeAndSwitchTable.md`
- `by-memory/0x0046fb80-0x0046fca5.BrowserDocHostShowUiStubs.md`
- `by-memory/0x0046fcb0-0x0046ff50.BrowserLegacyHostWndProc.md`
- `by-memory/0x00470160-0x0047016e.CAtlExceptionConstructorThunk.md`
- `by-memory/0x00470170-0x004701c9.BrowserVariantFromString.md`
- `by-memory/0x004701d0-0x00470278.BrowserDialogCleanupAndVariantThunks.md`
- `by-memory/0x00470278-0x004702fc.BrowserDialogDestructorAdjustorThunks.md`
- `by-memory/0x00470330-0x00470406.BrowserScalarDeletingDestructor.md`
- `by-memory/0x00470410-0x004704ec.BrowserControlPaneScalarDeletingDestructor.md`
- `by-memory/0x00470580-0x004705df.BrowserDialogScalarDeletingDestructor.md`
- `by-memory/0x004705e0-0x0047068d.BrowserDialogOldScalarDeletingDestructor.md`
- `by-memory/0x00470690-0x004706e5.BrowserPaneScalarDeletingDestructor.md`
- `by-memory/0x00470740-0x00470782.BrowserNotificationScalarDeletingDestructor.md`
- `by-memory/0x00470790-0x004707ef.WebBoardDialogScalarDeletingDestructor.md`
- `by-memory/0x004707f0-0x0047084f.WebBoardDialogOldScalarDeletingDestructor.md`
- `by-memory/0x0047084f-0x004708c7.BrowserComAdjustorThunks.md`
- `by-memory/0x004708d0-0x00470953.AdviseConnectionPoint.md`
- `by-memory/0x00470960-0x0047097c.CAtlExceptionThrowHelper.md`
- `by-memory/0x00470980-0x00470a00.UnadviseConnectionPoint.md`
- `by-memory/0x00470dd0-0x00470f10.BrowserWindowNavigate.md`
- `by-memory/0x00470f20-0x00470fb9.PostBrowserNotification.md`
- `by-memory/0x00470fc0-0x004710b8.BrowserOleAdjustorAndDelegationThunks.md`

Modified:

- `by-memory/0x0046f010-0x004710b8.BrowserOleLegacyAndHelpers.md`
- `by-class/BrowserControlPane.md`
- `by-class/browser__Notification.md`
- `by-class/BrowserDialog.md`
- `by-class/BrowserDialogOld.md`
- `by-class/WebBoardDialog.md`
- `by-file/AutoInit.md`
- `by-memory/0x00470300-0x0047032a.AutoInit.md`
- `auto-generated/-ag-memory-coverage.md` by validator `--apply`
- `tools/leaser/Agents/Agent-B001/research/0000ZF-BrowserOleLegacyAndHelpers.md`

Validated existing/pre-existing B001-024 split pages:

- `by-memory/0x0046f010-0x0046f1c8.BrowserThreadRunMessageLoop.md`
- `by-memory/0x0046f1d0-0x0046f1db.BrowserThreadDeleteIfPresentWrapper.md`
- `by-memory/0x0046f1e0-0x0046f216.BrowserControlPaneOldNonDeletingDestructor.md`
- `by-memory/0x0046f220-0x0046f30f.BrowserControlPaneOldDrawStatusOverlay.md`
- `by-memory/0x0046f310-0x0046f47b.BrowserControlPaneOldHandleBrowserMessage.md`
- `by-memory/0x0046ff50-0x00470159.BrowserControlPaneOldConstructor.md`
- `by-memory/0x004704f0-0x00470579.BrowserControlPaneOldScalarDeletingDestructorAndAdjustors.md`
- `by-memory/0x004706f0-0x0047073b.BrowserThreadScalarDeletingDestructor.md`
- `by-memory/0x00470a00-0x00470dc9.BrowserThreadInitializeBrowserHost.md`

Renamed:

- None in this replacement write phase. The aggregate page already used the corrected half-open `0x004710b8` filename at the start of this write phase; the page history records the earlier rename from the legacy inclusive-end `0x004710b7` path.

Moved to executed:

- None.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B001","command_id":"000000004165","destination_path":"executed-b-agent-research/B001/0000ZF-BrowserOleLegacyAndHelpers.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:18","uid":"0000ZF"} -->
<!-- {"agent":"B001","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 0000ZF-BrowserOleLegacyAndHelpers-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B001/0000ZF-BrowserOleLegacyAndHelpers.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"0000ZF"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
